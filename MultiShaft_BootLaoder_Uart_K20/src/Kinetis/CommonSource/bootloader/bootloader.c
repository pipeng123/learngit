 /******************************************************************************
* 
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved                       
*
*******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file      bootloader.c
*
* @author    b01119
* 
* @version   0.0.37.0
* 
* @date      Mar-11-2014
* 
* @brief     Bootloader state machine file
*
******************************************************************************/

#include "bootloader.h"
#include "rs232.h" 
#include "flash_kinetis.h"
#include "wdg.h"
#include "crc.h"



static void SendResult(unsigned long res);
static void SendResultCRC(unsigned long res);
extern void JumpToUserApplication(LWord userSP, LWord userStartup);

extern int __main(void);
extern unsigned long __BOOT_STACK_ADDRESS[];

#if defined(__IAR_SYSTEMS_ICC__)
	// Suppress the warning message in IAR with non - alligned member in structure.
	#pragma diag_suppress=Pa039

	#pragma section = "IntVectTable"
    #pragma location = "IntVectTable"

    __root const vector_entry __vector_table[16] = 
#elif defined(__ARMCC_VERSION)
#pragma diag_suppress=61
    __attribute__((section(".IntVectTable"))) const vector_entry __vector_table[16] __attribute__((used)) =   
#elif defined(__CWCC__)
#pragma  define_section vectors_rom ".vectors_rom" far_abs R
	__declspec(vectors_rom) vector_entry __vector_table[16] =     		
#endif    
{
   (pointer*)__BOOT_STACK_ADDRESS,  /* Initial SP           */
   (vector_entry)__main,            /* Initial PC           */
   Boot_ResetMCU,                   /* Non-maskable Interrupt (NMI) */
   Boot_ResetMCU,                   /* Hard Fault */
   Boot_ResetMCU,                   /* MemManage Fault */
   Boot_ResetMCU,                   /* Bus Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU,                   /* Usage Fault */
   Boot_ResetMCU                    /* Usage Fault */   
};

#if defined(__IAR_SYSTEMS_ICC__)
    #pragma section = "FlashConfig"
    #pragma location = "FlashConfig"
    
    __root const FlashConfig_t Config = 
#elif defined(__ARMCC_VERSION)
    __attribute__((section(".FlashConfig"))) const FlashConfig_t Config __attribute__((used)) =   
#elif defined(__GNUC__)
	__attribute__((section(".FlashConfig"))) const FlashConfig_t Config __attribute__((used)) =
#elif defined(__CWCC__)
	#pragma define_section cfmconfig ".cfmconfig" far_abs R
	__declspec(cfmconfig) FlashConfig_t Config  =  
#endif
{
    0xFFFFFFFF, 0xFFFFFFFF, FLASH_BOOT_PROTECTION, FLASH_BOOT_CONFIGURATION
};



AddressType   address;
AddressType   tmp_transpone;
AddressType   crc_res;

unsigned char write_buffer[256];
unsigned long length;
unsigned long i;
unsigned long enableBootMode;
unsigned long timeout_cnt;

const BootloaderIdentOptimType bootloaderIdent = 
{
   /** count of flash blocks */
   LITTLE2BIG(FLASH_BLOCK_CNT),
   /** flash blocks descritor */
   {{LITTLE2BIG(USER_FLASH_START), LITTLE2BIG(USER_FLASH_END), LITTLE2BIG(FLASH_ERASE_PAGE), LITTLE2BIG(FLASH_WRITE_PAGE)}
#if FLASH_BLOCK_CNT == 2
   ,
   {LITTLE2BIG(USER_FLASH_START_2), LITTLE2BIG(USER_FLASH_END_2), LITTLE2BIG(FLASH_ERASE_PAGE_2), LITTLE2BIG(FLASH_WRITE_PAGE_2)}
#endif
   },   
   /** Relocated interrupts vestor table */
   LITTLE2BIG(RELOCATED_VECTORS),
   /** Interrupts vestor table */
   LITTLE2BIG(INTERRUPT_VECTORS),
   /** Id string */
   KINETIS_MODEL_STR      
};

//-----------------------------------------------------------------------------
// FUNCTION:    Boot_ResetMCU
// SCOPE:       Bootloader application system function
// DESCRIPTION: The function resets the MCU and support CONNECTED mode
//              
// PARAMETERS:  enableBootloader - TRUE/FALSE
//              
// RETURNS:     none
//-----------------------------------------------------------------------------  
void Boot_ResetMCU(void)
{ 
  SCB_AIRCR = SCB_AIRCR_VECTKEY(0x5FA) | SCB_AIRCR_SYSRESETREQ_MASK;
  while(1)
  {};   
}

#if defined(__IAR_SYSTEMS_ICC__)
//-----------------------------------------------------------------------------
// FUNCTION:    JumpToUserApplication
// SCOPE:       Bootloader application system function
// DESCRIPTION: The function startup user application
//              
// PARAMETERS:  pointer on user vector table
//              
// RETURNS:     function never go back
//-----------------------------------------------------------------------------  

void JumpToUserApplication(LWord userSP, LWord userStartup)
{
  // set up stack pointer
  __asm("msr msp, r0");
  __asm("msr psp, r0");

  // Jump to PC (r1)
  __asm("mov pc, r1"); 
}
#elif defined(__CWCC__)

asm void JumpToUserApplication(LWord userSP, LWord userStartup)
{
	// set up stack pointer
	msr msp, r0;
	msr psp, r0;
	// Jump to PC (r1)		
	mov pc, r1;
}

#endif
//-----------------------------------------------------------------------------
// FUNCTION:    SendResult
// SCOPE:       Bootloader application system function
// DESCRIPTION: The function send the ACk or NACK
//              
// PARAMETERS:  res - TRUE/FALSE to send ACK or NACK
//              
// RETURNS:     none
//----------------------------------------------------------------------------- 
static void SendResult(unsigned long res)
{ 
    if(!res)
    {
        UART_PutChar(BOOT_CMD_ACK);
    }
    else
    {
        UART_PutChar(BOOT_CMD_NACK);
    }
}

//-----------------------------------------------------------------------------
// FUNCTION:    SendResultCRC
// SCOPE:       Bootloader application system function
// DESCRIPTION: The function send the ACk or NACK with CRC (if enabled)
//              
// PARAMETERS:  res - TRUE/FALSE to send ACK or NACK
//              
// RETURNS:     none
//----------------------------------------------------------------------------- 
static void SendResultCRC(unsigned long res)
{ 
  SendResult(res);
  #if BOOTLOADER_CRC_ENABLE == 1
  if(!res)
  {
    UART_PutChar(0xcf);
    UART_PutChar(0x63);
  }else
  {
    UART_PutChar(0xd1);
    UART_PutChar(0x93);
  }
  #endif
}

//-----------------------------------------------------------------------------
// FUNCTION:    ReadAddress
// SCOPE:       Bootloader application system function  
// DESCRIPTION: The functin reads the 4 bytes from IIC and store it to global address variable

//              
// PARAMETERS:  none
//              
// RETURNS:     none
//----------------------------------------------------------------------------- 
static void ReadAddress(void)
{
  address.Bytes.hh = UART_GetChar();
  address.Bytes.hl = UART_GetChar();
  address.Bytes.lh = UART_GetChar();
  address.Bytes.ll = UART_GetChar();
}

//-----------------------------------------------------------------------------
// FUNCTION:    ReadCrc
// SCOPE:       Bootloader application system function  
// DESCRIPTION: The functin reads the 2 bytes from IIC and store it to global crc variable

//              
// PARAMETERS:  none
//              
// RETURNS:     none
//----------------------------------------------------------------------------- 
#if BOOTLOADER_CRC_ENABLE == 1
  static void ReadCrc(void)
  {
    crc_res.Bytes.lh = UART_GetChar();
    crc_res.Bytes.ll = UART_GetChar();
  }
#endif


//-----------------------------------------------------------------------------
// FUNCTION:    TrimmSettings
// SCOPE:       Trimming of Internal Oscilator 
// DESCRIPTION: This function measures break impulse from PC and sets correct trim value

//              
// PARAMETERS:  none
//              
// RETURNS:     none
//----------------------------------------------------------------------------- 
void SlaveFrequencyCalibration(void)
{
  signed long diff;
#if IS_KMx_FAMILY
  unsigned long lastDiff;
    signed long update;
  lastDiff = 0;
#endif
  BOOT_PIN_INIT_AS_GPIO; 
  //  systick initialization
  SYST_RVR = 0xFFFFFF; // full range 0.8s for standard bus clock  = 32768Hz * 640 FLL / 2^24
  
  while(((GPIO_PDIR_REG(BOOT_CALIBRATION_GPIO_BASE) & GPIO_RX_MASK)))
  {};
  
  while(1)
  {
    //  waiting for falling edge of calibration impuls
    diff = 10000000;
    while(((GPIO_PDIR_REG(BOOT_CALIBRATION_GPIO_BASE) & GPIO_RX_MASK) == GPIO_RX_MASK))    
    {
      if(!diff--)
        Boot_ResetMCU(); // OutOfLimit
    };
    
    // Clear the Count Flag 
    (void)SYST_CSR;
    SYST_CVR = 0;
    
    //  waiting for raising edge of calibration impuls, if timer overflow is performed the baudrated is not relevant 
    while((GPIO_PDIR_REG(BOOT_CALIBRATION_GPIO_BASE) & GPIO_RX_MASK) == 0)
    {
      if(SYST_CSR & SysTick_CSR_COUNTFLAG_MASK)
        Boot_ResetMCU(); // OutOfLimit
    }
    timeout_cnt = SYST_CVR;
    
   
     

#if IS_KMx_FAMILY    
    // 20 plus 
    diff = 0xFFFFFF - timeout_cnt - CALIB_PULSE_LENGTH + 20;
    
    if(diff >= 0)
      update = 2;
    else
    {
      update = -2;
      diff *= -1;
    }
    
    MCG_C4 += update;
    
    if(lastDiff > diff || !diff)
      break;
    
    lastDiff = diff;
      
#else 
     // compute difference to expected value
    diff = 0xFFFFFF - timeout_cnt - CALIB_PULSE_LENGTH;
    
    //  if calculate value is in this range frequency of internal oscilator is correct set  
    if((diff <= BAUDRATE_ONE_PERCENT_ERROR) && (diff >= -BAUDRATE_ONE_PERCENT_ERROR))
      break;    

    // Why 6 ?
    // We expect the the trimm could tune clocks +-25%. For example for short trim
    // the right time of the calibration pulse is 1638 ticks. The 25% of this is 409.
    // And for the worst case of deviation we want to add just 1/4 of of trim scale.
    // what could be done by constatnt 6 (409 / 6 = 68 what is roughly 64 (256/4)).
    
    // And why 4? - Just for optimization :-)
    TRIM_REG += diff >> 2; //6
#endif
  }
  
  BOOT_PIN_INIT_AS_UART;
}

//-----------------------------------------------------------------------------
// FUNCTION:    Bootloader
// SCOPE:       Bootloader application system function 
// DESCRIPTION: This is main function of the project it substitute normal main function

//              
// PARAMETERS:  none
//              
// RETURNS:     none
//----------------------------------------------------------------------------- 
/* Entry point of bootloader */
/* Entry point of bootloader */


int __main(void)
{
    /* initialize any hardware specific issues */
#if BOOTLOADER_INT_WATCHDOG == 1
    WDG_Enable(); 
#else
    WDG_Disable();
#endif
    // this setup all clock
    INIT_CLOCKS_TO_MODULES
    
    // initialize bootloader pin reset
#if BOOTLOADER_PIN_ENABLE == 1
    BOOTLOADER_PIN_ENABLE_INIT;
#endif
    
    // initialize variables
    timeout_cnt = 0;
    enableBootMode = 1;
     
    // read the srs register
    if(SRS_REG & SRS_POR_MASK)
        enableBootMode = 1;
    
    // Application is present ?
    if((*(unsigned long*)(RELOCATED_VECTORS + 8)) == 0xffffffff)
        enableBootMode = 1;
    
    
    // Check external pin if = 0 go to bootloader mode 
#if BOOTLOADER_PIN_ENABLE == 1
    if((GPIO_PDIR_REG(BOOT_PIN_ENABLE_GPIO_BASE) & (1 << BOOT_PIN_ENABLE_NUM)) == 0) 
        enableBootMode = 1;
#endif
  
  
    if(enableBootMode)
    {
        unsigned long i;    
        
    #if BOOTLOADER_CRC_ENABLE == 1
        CRC_Init();    
    #endif
        
        //  multiplexer setting  to UART alternative
        BOOT_PIN_INIT_AS_UART;
        
        // init UART module
        UART_Initialization(); 
        
        // run the timer on 10ms
        SYST_RVR = (unsigned long)(0.01 * BOOT_BUS_CLOCK); // to do add macro to define the initial timeout
        SYST_CSR = (SysTick_CSR_CLKSOURCE_MASK | SysTick_CSR_ENABLE_MASK);
        
        while(1)
        {
        #if BOOTLOADER_INT_WATCHDOG == 1
            WDG_Refresh(); /* feeds the dog */
        #endif  
            
            if(SYST_CSR & SysTick_CSR_COUNTFLAG_MASK)
            {
                SYST_CVR = 0; // Finish the clear of the SysTick CountFlag
              
                // increment timeout value
            #if defined(__IAR_SYSTEMS_ICC__) || defined(__ARMCC_VERSION)
                timeout_cnt++;		
            #elif defined(__CWCC__)
                timeout_cnt += 8;	  
            #endif
                
                if((timeout_cnt & 0x1F) == 0x10)
              	    SendResult(0);    	  
                if((timeout_cnt > BOOT_WAITING_TIMEOUT) && ((*(unsigned long*)(RELOCATED_VECTORS + 8)) != 0xffffffff))
              	    break;
            }
            
            // check the UART activity
            if(UART_IsChar())
            {
                // measuring of brake signal due to using of Internal oscilator..
            #if BOOTLOADER_AUTO_TRIMMING == 1           
                SlaveFrequencyCalibration();
            #endif        
                
                // init the flash module
                FLASH_Initialization(); 
                enableBootMode++;
                SendResult(0);
                break;
            }  
        }
        
        //  Bootloader protocol runs !
        while(enableBootMode > 1)
        {
            // never ending loop - except quit commnad that disable  enableBootMode
        #if BOOTLOADER_INT_WATCHDOG == 1
            WDG_Refresh(); /* feeds the dog */
        #endif
            
        #if BOOTLOADER_CRC_ENABLE == 1
            CRC_Reset();
        #endif
        
            switch(UART_GetChar())
            {
                case BOOT_CMD_QUIT:                                 // QUIT command
                #if BOOTLOADER_CRC_ENABLE == 1
                    CRC_AddByte(BOOT_CMD_QUIT);  
                    ReadCrc();
                    if(crc_res.Words.low != CRC_GetResult())
                    {            
                        SendResultCRC(1);
                        break;
                    }
                #endif
                    // send the ack
                    SendResultCRC(0);
                    // reset MCU
                    Boot_ResetMCU();
                
                case BOOT_CMD_ACK:
                    SendResult(0);                                   // ACK command
                    break;
                
                case BOOT_CMD_IDENT:                               // IDENT command
                    //and send the all data with/without CRC 
                #if BOOTLOADER_CRC_ENABLE == 1
                    CRC_AddByte(BOOT_CMD_IDENT);  
                    CRC_AddByte((BootloaderProtocolType)_BOOTLOADER_PROTOCOL_VERSION);
                #endif
                    UART_PutChar((BootloaderProtocolType)_BOOTLOADER_PROTOCOL_VERSION);

        #if 0
			#if 0
			    /*Ver0.037*/
                #if BOOTLOADER_CRC_ENABLE == 1
                    CRC_AddLong(SIM_SDID);
                #endif
                    UART_PutChar(SIM_SDID >> 24);
                    UART_PutChar(SIM_SDID >> 16);      
                    UART_PutChar(SIM_SDID >> 8);
                    UART_PutChar(SIM_SDID);  
			#else
			    /*Ver0.032*/
				#if BOOTLOADER_CRC_ENABLE == 1
					//CRC_AddLong(SIM_SDID);
					CRC_AddByte(SIM_SDID>>8);
					CRC_AddByte(SIM_SDID);
				#endif
					//UART_PutChar(SIM_SDID >> 24);
					//UART_PutChar(SIM_SDID >> 16);      
					UART_PutChar(SIM_SDID >> 8);
					UART_PutChar(SIM_SDID);  
			#endif
        #else   /*10.18 ok*/	    
                #if BOOTLOADER_CRC_ENABLE == 1
                    CRC_AddLong(0x000001de);
                #endif
                    UART_PutChar(0x00);
                    UART_PutChar(0x00);      
                    UART_PutChar(0x01);
                    UART_PutChar(0xde);     
        #endif  	    
                  
                    for(i=0; i < sizeof(bootloaderIdent); i++)
                    {
                    #if BOOTLOADER_CRC_ENABLE == 1
                        CRC_AddByte(((unsigned char*)&bootloaderIdent)[i]);
                    #endif              
                        UART_PutChar(((unsigned char*)&bootloaderIdent)[i]);
                    }
                
                #if BOOTLOADER_CRC_ENABLE == 1
                    UART_PutChar(CRC_GetResultHigh());         
                    UART_PutChar(CRC_GetResultLow());
                #endif
                    break;
                  
                case BOOT_CMD_ERASE:                                // ERASE command
                    // Read Address
                    ReadAddress();
                    // Check the CRC
                #if BOOTLOADER_CRC_ENABLE == 1
                    CRC_AddByte(BOOT_CMD_ERASE);
                    CRC_AddLong(address.complete);
                    ReadCrc();
                    if(crc_res.Words.low != CRC_GetResult())
                    {            
                        SendResultCRC(1);
                        break;
                    }
                #endif
                    // Erase the flash and send result
                    SendResultCRC(FLASH_EraseSector(address.complete));
                    break;
                  
                case BOOT_CMD_WRITE:
                    // Read Address                                                   // WRITE command
                    ReadAddress();
                    // Read length
                    length = UART_GetChar();
                  
                #if BOOTLOADER_CRC_ENABLE == 1
                    CRC_AddByte(BOOT_CMD_WRITE);
                    CRC_AddLong(address.complete);
                    CRC_AddByte((unsigned char)length);
                #endif
                  
                    // Load the data to write
                    for(i = 0;i<length; i++)
                    {
                        write_buffer[i] =  UART_GetChar(); 
                      #if BOOTLOADER_CRC_ENABLE == 1
                        CRC_AddByte(write_buffer[i]);
                      #endif  
                    }
                  
                    if(length%4)
                    {
                        for(i = length;i<(length+4-length%4); i++) 
                            write_buffer[length]=0xFF;
                        length+=(4-length%4);
                    }
                  
                    length >>= 2;    // divide by four
                  
                    // check the CRC of input data
                  
                #if BOOTLOADER_CRC_ENABLE == 1
                    ReadCrc();
                    if(crc_res.Words.low != CRC_GetResult())
                    {            
                        SendResultCRC(1);
                        break;
                    }
                #endif
                        
                    if(FLASH_PROGRAM(address.complete, (LWord*)write_buffer, length))
                    {            
                        SendResultCRC(1);
                        break;
                    }
                  
                // Verify flashed data (if enabled)
                #if BOOTLOADER_ENABLE_VERIFY == 1                 
                    for(i = 0;i<length; i++)
                    {              
                        if(((unsigned long*)write_buffer)[i] != ((unsigned long*)address.complete)[i])
                        {
                            SendResultCRC(1);
                            break;
                        }
                    }
                #endif    
                    SendResultCRC(0);
                    break;
                
            #if BOOTLOADER_ENABLE_READ_CMD == 1       
                case BOOT_CMD_READ:                                   // READ comamnd    
                    ReadAddress();
                    length = UART_GetChar();
                  
                #if BOOTLOADER_CRC_ENABLE == 1
                    ReadCrc();
                    
                    CRC_AddByte(BOOT_CMD_READ);
                    CRC_AddLong(address.complete);
                    CRC_AddByte((unsigned char)length);
                    
                    if(crc_res.Words.low != CRC_GetResult())
                    {            
                        SendResultCRC(1);
                        break;
                    }
                #endif
                  
                #if BOOTLOADER_CRC_ENABLE == 1
                    CRC_Reset();
                #endif
                  
                    for(i = 0;i<length; i++)
                    {
                    #if BOOTLOADER_CRC_ENABLE == 1
                        CRC_AddByte(((unsigned char*)(address.complete))[i]);
                    #endif              
                        UART_PutChar(((unsigned char*)(address.complete))[i]); 
                      
                    #if BOOTLOADER_INT_WATCHDOG == 1
                        WDG_Refresh(); /* feeds the dog */
                    #endif
                    }
                #if BOOTLOADER_CRC_ENABLE == 1
                    UART_PutChar(CRC_GetResultHigh());         
                    UART_PutChar(CRC_GetResultLow());
                #endif
                    break;
             #endif    
                
            }      
        } 
    }
    // deinitialization of SysTick
    SYST_CSR = 0;
  
    //  deinitialization of UART
    UART_Deinitialization();
  
    // relocate vector table
    SCB_VTOR = RELOCATED_VECTORS;
    
    // Jump to user application
    JumpToUserApplication(*((unsigned long*)RELOCATED_VECTORS), *((unsigned long*)(RELOCATED_VECTORS+4)));   
    
	return 0;
}
