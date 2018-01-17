/**********************************************************************
* HEADER_START                                                        *
*                                                                     *
*      Name:           main.c                                         *
*      Project:        Developper's HC08 Bootloader Slave             *
*      Description:    S08JM main bootloader file                     *
*      Platform:       Linux/Win32                                    *
*      Date:           Jan 27 2009                                    *
*      Author:         B20253                                         *
*      Company:        Freescale                                      *
*      Security:       General Business                               *
*                                                                     *
* =================================================================== *
* Copyright (c):       FREESCALE Inc., 2009, All rights reserved.     *
*                                                                     *
* =================================================================== *
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY              *
* EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  *
* PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL FREESCALE OR             *
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    *
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT        *
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;        *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)            *
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, *
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       *
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED *
* OF THE POSSIBILITY OF SUCH DAMAGE.                                  *
* =================================================================== */

#include <hidef.h>        /* for EnableInterrupts macro */
#include "derivative.h"   /* include peripheral declarations */
#include "hc08sprg.h"
#include "usb.h"          /* usb module */
#include "usb_cdc.h"      /* usb cdc class module */
#include "target.h"
#include "cfm.h"

/* SELECT VERSION */

    /* TWO VERSION bootloaders with JMP instruction in relocated vector table & without JMP instruction*/


#define DEBUGLED FALSE   /* LED SETTINGS, DEFAULT LED SETTINGS IS FOR EVB JM60 */      

                        
#if VERSION==0
 #include "vector.h"
#else
 #include "vector2.h"
#endif

FILE_PTR_STR file_ptr;

#if VERSION==0
 const byte MY_NVPROT  @0x0000040D = 0xF3;           // NVPROT protected to boundary 2FFF
#else
// const byte MY_NVPROT  @0x0000040D = 0xFF;           // NVPROT no protected 
#endif


unsigned char quit;
unsigned int* ptr_app;
byte i;

/* PIN DETECT USER SETTING */
#define  PULL_UP_ENABLE  PTGPE_PTGPE3                   // Port G Pull Enable Register
#define  PORT_DATA_DIR   PTGDD_PTGDD3                   // Port G Data Direction Register
#define  BUTTON          PTGD_PTGD3  

//--------------------------------------------------------------------   
#if VERSION==0
 #ifdef JM128 
  const IDENT_STR idents = 
   {
    1,                         // number of reprogrammable memory areas
    (int *) (RELINTVECT+(6*NUMBER_OF_VECTOR)),
                               // start of flash memory area
    (int *) 0x0001FFFF,        // flash end
    (int *) RELINTVECT,        // start of new relocated vector table
    (int *) (4*NUMBER_OF_VECTOR),        // end of interrupt vector table
    FLASH_ERASE_PAGE,          // size of erase page
    FLASH_WRITE_PAGE           // size of write page
   };                     

  #else
   const IDENT_STR idents = 
   {
    1,                         // number of reprogrammable memory areas
    (int *) (RELINTVECT+(6*NUMBER_OF_VECTOR)),
                               // start of flash memory area
    (int *) 0x0000FFFF,        // flash end
    (int *) RELINTVECT,        // start of new relocated vector table
    (int *) (4*NUMBER_OF_VECTOR),        // end of interrupt vector table
    FLASH_ERASE_PAGE,          // size of erase page
    FLASH_WRITE_PAGE           // size of write page
   };                     
  #endif
//---------------------------------------------------------------------   
#else
  const IDENT_STR idents =
   {
    2,                         // number of reprogrammable memory areas
    (int *) 0x00000000,        // start of flash memory area1
    (int *) 0x000003FF,        // flash end1
    (int *) 0x00000410,        // start of flash memory area2
    (int *) FLASH_END,        // flash end2
    (int *) 0x00000000,        // start of new relocated vector table
    NULL,                      // end of interrupt vector table (NULL means no relocation on CFV1)
    FLASH_ERASE_PAGE,          // size of erase page
    FLASH_WRITE_PAGE           // size of write page
   };                     
#endif
//-----------------------------------------------------------------------   
void vector_redirection(void)
{
    int  *original_vectors, *ram_vectors;

    /* vector redirection - flash to RAM */
    asm (move.l  #START_RAM_VEC,d0);
    asm (movec   d0,vbr);

    /* set up starting address of pointers */
    original_vectors = (int*)RAM_vector;
    ram_vectors      = (int*)START_RAM_VEC;

    /* copy all interrupt vectors to ram */         
    for(i=0;i<=NUMBER_OF_VECTOR;i++)
    {
        *ram_vectors++=*original_vectors++;
    } 
}                                                         
 
//-------------------------------------------------------------   
unsigned char PinDetect(void)
{
    PULL_UP_ENABLE = 1;      
    PORT_DATA_DIR  = 0;      

    for(i=0;i<100;i++){asm(nop);}    

    return((unsigned char)(!BUTTON ? 1 : 0));
}
//-------------------------------------------------------------   
void putchar(char ch) 
{
    while (!cdc_putch(ch)) 
    {};
}
//-------------------------------------------------------------   
void putstr(char * str) 
{
    while(*str)    
        putchar(*str++);
    
    putchar(NULL);
}

//-------------------------------------------------------------   
#if VERSION==1
 
void putint(unsigned char * p) 
{
    putchar((char)*p++);
    putchar((char)*p++);
    putchar((char)*p++);
    putchar((char)*p++);
}
  
#endif

/****************************************************************************************************/
void main(void){
 
    if(SRS_ILOP == FALSE)
    {
        if(PinDetect() == TRUE)   /* if button PTG3 push, booer's starting */
        {
            DisableInterrupts               
#if DEBUGLED == TRUE
            LED1=LEDON;
#endif
                         
            hw_init();       

            FCDIV = 0x4F;    /* FCLK=(PRDCLK)/1+FCDIV[5:0]=3000kHz/(1k+15k)=187,5 kHz (6,25%) */

            vector_redirection();
                        
            usb_init();     /* initialization usb low level */
            cdc_init();     /* initialization cdc class */

            EnableInterrupts;
               
            /* wait for USB ready, COM port opened by hc08sprg.exe */
            while (!cdc_line_coding_changed())   
            {
#if DEBUGLED == TRUE
                LED2=LEDON;
#endif
            };
#if DEBUGLED == TRUE
            LED2=LEDOFF;
#endif

            /* send ACK to USB */
            putchar((char)FCACK);            
       
            /* wait for ACK from USB */    
            while(getchar()!=FCACK)
                {};         
              
            /* send ACK to USB */
            putchar((char)FCACK);    

            quit=0;

            while(!quit) 
            {
                switch(getchar()) { 
                
                case READ:
              
#if DEBUGLED == TRUE
                    LED3=LEDON;
#endif

                    file_ptr.addr.b.byte03 = getchar();    // addr hi
                    file_ptr.addr.b.byte02 = getchar();    
                    file_ptr.addr.b.byte01 = getchar();    
                    file_ptr.addr.b.byte00 = getchar();    // addr lo
                    file_ptr.datasize      = getchar();    // length

                    #if VERSION==1

                    if(file_ptr.addr.i == NULL)
                    {
                       putint((unsigned char*)RESET_APP);
                       putint((unsigned char*)(RESET_APP+4));
                       file_ptr.addr.w   += 8;
                       file_ptr.datasize -= 8;
                    }
                                                                    
                    #endif

                    while (file_ptr.datasize)
                    {
                        putchar((char)*file_ptr.addr.w);
                        file_ptr.addr.w++;
                        file_ptr.datasize--;  
                    }
                                        
#if DEBUGLED == TRUE
                    LED3 = LEDOFF;                                        
#endif
                    break;
                            
                case ERASE:
              
#if DEBUGLED == TRUE
                    LED4=LEDON;
#endif
                     
                    file_ptr.addr.b.byte03 = getchar();    // addr hi
                    file_ptr.addr.b.byte02 = getchar();
                    file_ptr.addr.b.byte01 = getchar();
                    file_ptr.addr.b.byte00 = getchar();    // addr lo    
                                                             
                    DisableInterrupts;
                    Page_erase(file_ptr.addr.w);           // Erase! it
                    EnableInterrupts;           
                     
                     /* send ACK to USB */
                    putchar((char)FCACK);
#if DEBUGLED == TRUE
                    LED4=LEDOFF;
#endif
                    break;
                      
                      
                case WRITE:
              
#if DEBUGLED == TRUE
                    LED5=LEDON;
#endif

                    file_ptr.addr.b.byte03 = getchar();    // addr hi
                    file_ptr.addr.b.byte02 = getchar();  
                    file_ptr.addr.b.byte01 = getchar();
                    file_ptr.addr.b.byte00 = getchar();    // addr lo  
                     
                    file_ptr.datasize = getchar();  
                     
                    for (i=0; i <file_ptr.datasize; i++)
                        file_ptr.data.data8[i] = getchar();
                     
                #if VERSION==1

                    if(file_ptr.addr.i == NULL)
                    {                                          
                        
                        ptr_app =(unsigned int*)RESET_APP;
                        DisableInterrupts;
                        Burst_Prog(ptr_app, file_ptr.data.data32, 2);  // copy SP & PC to RESET_APP
                        EnableInterrupts;
                        file_ptr.data.data32[0] = (unsigned int)&_SP_INIT;
                        file_ptr.data.data32[1] = (unsigned int)&_startup;  
                    }
                #endif

                    if (file_ptr.datasize & 0x3) // length non long word aligned
                    {
                        file_ptr.datasize &= 0xFFFFFFFC;
                        file_ptr.datasize += 4;
                    }
                    
                    DisableInterrupts;
                    Burst_Prog(file_ptr.addr.w, file_ptr.data.data32, file_ptr.datasize / 4);
                    EnableInterrupts;
                    /* send ACK to USB */
                    putchar((char)FCACK);
#if DEBUGLED == TRUE
                    LED5=LEDOFF;
#endif
                    break;
                      
                case IDENT:
              
#if DEBUGLED == TRUE
                    LED6=LEDON;
#endif
                     
                    putchar((char)PROTOCOL_VERSION);
                    putchar((char)SDIDH);
                    putchar((char)SDIDL);      
                   
                    i=0;
                    while(i < sizeof(idents))
                    {
                        putchar(idents.str[i++]);
                    }  
                    putstr("MCF51JM128/USB $Version: 1.0.23.0$");    
                     
                    /* send ACK to USB */
                    putchar((char)FCACK);                     
#if DEBUGLED == TRUE
                    LED6=LEDOFF;
#endif
                    break;
                      
                case QUIT:
                    
#if DEBUGLED == TRUE
                    LED7=LEDON;
#endif
                    quit=1;
                    
                    break;

                }
            }
                                 
            (void)usb_stop();    /* disable USB */
            DisableInterrupts;
            SOPT1=0x0;
            asm(stop #0);        /* ILOP */
             
        } 
        
        else  /* if((SRS_ILOP == FALSE) and (PinDetect() == FALSE)) */
        {
#if DEBUGLED == TRUE
            LED4=LEDON;
#endif
       
        #if VERSION==0
            asm (move.l #R_INITSP+2,a0);    /* set up stack pointer */
            asm (move.l (a0),a7);
            asm (JMP R_INITPC);             /* jump to application reset vector */
        #else
            asm (move.l RESET_APP,a0);      /* set up stack pointer */
            asm (move.l (a0),a7);
            asm (move.l RESET_APP+4,a0);    /* set up stack pointer */
            asm (jmp (a0));
        #endif 
        }          
    } 
      
    else  /* if(SRS_ILOP == TRUE) */               
    {
  
    #if VERSION==0
        asm (move.l #R_INITSP+2,a0);      /* set up stack pointer */
        asm (move.l (a0),a7);
        asm (JMP R_INITPC);               /* jump to application reset vector */
    #else
        asm (move.l RESET_APP,a0);      /* set up stack pointer */
        asm (move.l (a0),a7);
        asm (move.l RESET_APP+4,a0);    /* set up stack pointer */
        asm (jmp (a0));
    #endif
    }
}