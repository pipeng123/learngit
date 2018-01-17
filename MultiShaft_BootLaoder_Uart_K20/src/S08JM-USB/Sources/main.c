/*****************************************************************************
*
* (c) 2009 Freescale Inc.
* ALL RIGHTS RESERVED.
*
**************************************************************************//*!
*
* @file      main.c
* @version   1.0.24.0
* @date      Jun-25-2009
* @author    r30323
*
* @brief     S08JM USB bootloader main
*  
*****************************************************************************/

#include <hidef.h> 
#include "derivative.h" 
#include "doonstack.h"
#include "hcs08sprg.h"
#include "target.h"
#include "usb_cdc.h"
#include "usb.h"

extern char boot_table[];
extern char bl_boot_table[];
extern char usr_boot_table[];

FILE_PTR_STR file_ptr;
unsigned char quit;
byte i;


#define DEBUGLED TRUE   /* LED SETTINGS, DEFAULT LED SETTINGS IS FOR EVB JM60 */      


/* USER LED SETTING */
/* THIS LED'S DEFINITION  IS COMPATIBLE WITH EVB JM60 */

#if DEBUGLED == TRUE

 #define LED1 PTEDD_PTEDD2   
 #define LED2 PTEDD_PTEDD3   
 #define LED3 PTFDD_PTFDD0   
 #define LED4 PTFDD_PTFDD1
 #define LED5 PTCDD_PTCDD2
 #define LED6 PTCDD_PTCDD4
 #define LED7 PTDDD_PTDDD2
 #define LEDON  1
 #define LEDOFF 0
 
#endif

/* PIN DETECT USER SETTING */
/* THIS PIN'S DEFINITION  IS COMPATIBLE WITH EVB FOR JM60 */


 #define  PULL_UP_ENABLE  PTGPE_PTGPE3                   // Port G Pull Enable Register
 #define  PORT_DATA_DIR   PTGDD_PTGDD3                   // Port G Data Direction Register
 #define  KBI_PIN_EN      KBIPE                          // KBI Pin Enable Register
 #define  PORT_DATA       PTGD                           // Port G Data Register
 #define  BUTTON          PTGD_PTGD3                     



const byte MY_NVOPT  @0x0000FFBF = 0x02;  // vector redirect, flash unsecure
const byte MY_NVPROT @0x0000FFBD = 0xE6;  // 0xE800-0xFFFF are protected


/* Specification memory area for MCU HCS08JM32 */

#if SIZE == 32
const IDENT_STR idents = 
{
    1,                       // Number of reprogrammable memory areas
    (char *) 0x8000,         // Start address of reprogrammable memory area #2
    usr_boot_table,          // Flash end  (same as apl vector)
    usr_boot_table,          // Apl vector
    (char *) 0xFFC0,         // Start address of MCU interrupt vector table
    FLASH_ERASE_PAGE,        // Length of MCU erase block
    FLASH_WRITE_PAGE         // Length of MCU write block
};

#endif


/*Specification memory area for MCU HCS08JM60 */

#if SIZE == 60
const IDENT_STR idents = 
{
    2,                       // Number of reprogrammable memory areas
    (char *) 0x10B0,         // Start address of reprogrammable memory area #1
    (char *) 0x17FF,         // End address of reprogrammable memory area #1 + 1
    (char *) 0x1960,         // Start address of reprogrammable memory area #2
    usr_boot_table,          // Flash end  (same as apl vector)
    usr_boot_table,          // Apl vector
    (char *) 0xFFC0,         // Start address of MCU interrupt vector table
    FLASH_ERASE_PAGE,        // Length of MCU erase block
    FLASH_WRITE_PAGE         // Length of MCU write block
};

#endif

                       
unsigned char PinDetect()    // If button PTG3 active after POR, bootloader starts.
    {           
  
    PULL_UP_ENABLE = 1;
    PORT_DATA_DIR  = 0;
    KBI_PIN_EN     = 0;
    PORT_DATA      = 0;
  
    for(i=0;i<100;i++){asm nop;}    
    
    return (!BUTTON ? 0 : 1);
    
    }


 void flash_boot_table(char * table, char signature) 

   {
   
    (void)FlashErase1((unsigned char *)boot_table);  // erase new boot vector table

    file_ptr.datasize = TABLE_VECT_SIZE;

    file_ptr.data[0] = signature;
    
    for(i=1;i<TABLE_VECT_SIZE;i++)
     
      file_ptr.data[i] = *table++; 
          
    (void)FlashProgBurst((byte*) boot_table,(byte*) &file_ptr.data,file_ptr.datasize);
    
    }


 void putstr(char * str) 
  {
    do 
    {        
        (void)cdc_putch(*str);
    } while(*str++);

    (void)cdc_process();
  }
  
  
//*********************************************************************************************//

void main (void)
{

    if ((boot_table[0] != SIG_USR) || (PinDetect() == 0))
    {
        if ((boot_table[0] == SIG_EMPTY) || (PinDetect() == 0))
        {
            DisableInterrupts;

            #if DEBUGLED == TRUE
            LED1=LEDON;
            #endif
            
            hw_init();      /* CLOCK INITIALIZATION 24 MHz */
            
            FCDIV= 0x4F;    /* FCLK=(PRDCLK)/1+FCDIV[5:0]=3000kHz/(1k+15k)=187,5 kHz (6,25%) */

            usb_cfg_init();
            
            cdc_init(); 
           
            flash_boot_table ((char *)&bl_boot_table, SIG_BOOT);

            EnableInterrupts;

            while (!cdc_line_coding_changed())    
          
            {
                #if DEBUGLED == TRUE
                LED2=LEDON;
                #endif
            };
             
            #if DEBUGLED == TRUE
            LED2=LEDOFF;
            #endif

            put_char(FCACK);
            
            while(get_char()!=FCACK){};
             
            quit=0;

            put_char(FCACK);
             
            while(!quit) 

            {
                switch(get_char())
                { 
                                  
                case READ:

                    #if DEBUGLED == TRUE
                    LED3=LEDON;
                    #endif
                                    
                    file_ptr.addr.b.hi = get_char();  // addr hi
                    file_ptr.addr.b.lo = get_char();  // addr lo
                    file_ptr.datasize  = get_char();  // length

                    while (file_ptr.datasize--)
                    put_char(*file_ptr.addr.w++);

                    #if DEBUGLED == TRUE
                    LED3=LEDOFF;
                    #endif

                    break;

                case ERASE:

                    #if DEBUGLED == TRUE
                    LED4=LEDON;
                    #endif

                    file_ptr.addr.b.hi = get_char();  // addr hi
                    file_ptr.addr.b.lo = get_char();  // addr lo 

                    DisableInterrupts;
                    (void)FlashErase1(file_ptr.addr.w);
                    EnableInterrupts;                 

                    put_char(FCACK);

                    #if DEBUGLED == TRUE
                    LED4=LEDOFF;
                    #endif

                    break;
      
                case WRITE:

                    #if DEBUGLED == TRUE
                    LED5=LEDON;
                    #endif

                    file_ptr.addr.b.hi = get_char();  // addr hi
                    file_ptr.addr.b.lo = get_char();  // addr lo
                    file_ptr.datasize  = get_char();  // length

                    for (i=0; i < file_ptr.datasize; i++)
                    file_ptr.data[i] = get_char();

                    DisableInterrupts;
                    (void)FlashProgBurst(file_ptr.addr.w,(byte*)&file_ptr.data,file_ptr.datasize);
                    EnableInterrupts;        

                    put_char(FCACK);   

                    #if DEBUGLED == TRUE
                    LED5=LEDOFF;
                    #endif

                    break;
                      
                case IDENT:

                    #if DEBUGLED == TRUE
                    LED6=LEDON;
                    #endif

                    put_char(PROTOCOL_VERSION);
                    put_char(SDIDH);
                    put_char(SDIDL);

                    for (i=0; i < sizeof(idents); i++) 
                    put_char(idents.str[i]);

                    #if SIZE==32   
                    putstr("JM60/USB ");
                    #endif

                    #if SIZE==60
                    putstr("JM32/USB ");
                    #endif 

                    putstr("$Version: 1.0.24.0$");

                    #if DEBUGLED == TRUE
                    LED6=LEDOFF; 
                    #endif

                    break;

                case QUIT:

                    #if DEBUGLED == TRUE
                    LED7=LEDON;
                    #endif

                    quit=1;

                    #if DEBUGLED == TRUE
                    LED7=LEDOFF;
                    #endif

                    break;
                }
            }


        (void)usb_stop();
      
        } 

        #if DEBUGLED == TRUE
        LED4=LEDON;
        #endif
        
        flash_boot_table ((char *)&usr_boot_table, SIG_USR);
        ILOP;

    } 
    else  
    {
        asm ldhx  boot_table:63;
        asm jmp  ,x
    }; 
}
