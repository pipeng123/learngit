/*****************************************************************************
*
* (c) 2005 Freescale Inc.
* ALL RIGHTS RESERVED.
*
**************************************************************************//*!
*
* @file      main.c
* @version   1.0.19.0
* @date      Oct-11-2011
* @author    r30323
*
* @brief     JW32 USB bootloader main {}
*  
*****************************************************************************/

#include "map.h"
#include "hc08sprg.h"

#include "usb.h"         /* USB module */
#include "pll.h"         /* PLL module */
#include "global.h"
#include "usb_cdc.h"
#include "usb_driver.h"

#define LED1 PTB_PTB0
#define LED2 PTB_PTB1
#define LED3 PTB_PTB5

#define LEDON  0
#define LEDOFF 1

#define LED1DDR DDRB_DDRB0
#define LED2DDR DDRB_DDRB1
#define LED3DDR DDRB_DDRB5

extern void PllStart(void);
extern char bl_boot_table[];
extern char boot_table[];
extern char usr_boot_table[];

const IDENT_STR idents = 
{
    0x83,      // version number
    0xFFFF, // SDID unused
    1,      // number of flash pages
    (char *) 0x7000, // Flash start
    usr_boot_table, // Flash end  (same as apl vector)
    usr_boot_table, // Apl vector
    (char *) 0xFFFE - 2*16, // Int vector start
    FLASH_ERASE_PAGE,
    FLASH_WRITE_PAGE
};

// control signal
extern word cdcControlLineState;

#pragma DATA_SEG SHORT _DATA_ZEROPAGE

unsigned char i;
FILE_PTR_STR file_ptr;
unsigned char quit;

#pragma DATA_SEG DEFAULT


/*
 * IRQPinLow: Checks IRQ Pin to see if is low.
 *
 * Parameters: None
 *
 * Return : 1 if IRQ is Low.
 */
unsigned char IRQPin(void){

    asm  BIL irq    
    return 1;    
    asm irq:    
    return 0;
}

void flash_boot_table(char * table, char signature) 
{
    DisableInterrupts;
    
    Protect((char *)&boot_table+512);
    
    file_ptr.bus_spd = BUS_SPD;
    file_ptr.addr.w = boot_table;
    Erarnge(file_ptr);      // erase actual vector page

    file_ptr.addr.w = table;
    file_ptr.datasize = 8+3*NUM_OF_VECTS+1;
    Ldrnge(file_ptr);      // load values from Flash to RAM buffer

    file_ptr.data[FLASH_WRITE_PAGE-1] = signature; // write signature to RAM

    file_ptr.addr.w = boot_table;
    file_ptr.datasize = FLASH_WRITE_PAGE;
    Prgrnge(file_ptr);      // program new vector page

    Protect((char *)&boot_table);
};


#define getchar USB_RxChar2
#define putchar (void)USB_TxChar3
#define flush (void)USB_TxFlush3

void putstr(char * str) 
{
    do 
    {        
        (void)putchar(*str);
    } while(*str++);

    (void)flush();
}


void main(void) 
{

    if ((boot_table[FLASH_WRITE_PAGE-1] != SIG_USR) || (IRQPin() == 0))
    {
        if ((boot_table[FLASH_WRITE_PAGE-1] == SIG_EMPTY) || (IRQPin() == 0))
        {
            LED1DDR = 1;
            LED2DDR = 1;
            LED3DDR = 1;

            LED1 = LEDOFF;
            LED2 = LEDOFF;
            LED3 = LEDOFF;
        
            cdcControlLineState = 0;

            CONFIG1 = CONFIG1_COPD_MASK;

            ISCR_IMASK = 1;     // mask out IRQ interrupts!
            ISCR_ACK = 1;       // clear IRQ flag
           
            USB_Init();             // initialize

            PllStart();
            flash_boot_table ((char *)&bl_boot_table, SIG_BOOT);

            USB_Enable();

            EnableInterrupts;       // Enable USB only

            /* wait for USB ready, COM port opened by hc08sprg.exe */
            while (cdcControlLineState != 2) 
            {
              LED2 ^= 1;
            };

            LED2 = LEDOFF;
            
            do
            {
                LED1 = LEDON;
            
                /* send ACK to USB */
                putchar(FCACK); 
                flush();

                /* wait for ACK from USB */
            } while(getchar() != FCACK);

             quit = 0;
           
            /* send ACK to USB */
            putchar(FCACK); 
            flush();

            while(!quit) 
            {
                switch(getchar())
                {
                    case READ:
                        LED2 = LEDON;
                        file_ptr.addr.b.hi = getchar();  // addr hi
                        file_ptr.addr.b.lo = getchar();  // addr lo
                        file_ptr.datasize = getchar();   // length

                        while (file_ptr.datasize--)
                            putchar(*file_ptr.addr.w++);

                        flush();
                        LED2 = LEDOFF;
                        break;
                    case ERASE:
                        LED1 = LEDON;
                        file_ptr.bus_spd = BUS_SPD;
                        file_ptr.addr.b.hi = getchar();  // addr hi
                        file_ptr.addr.b.lo = getchar();  // addr lo

                        DisableInterrupts;
                        
                        Erarnge(file_ptr);      // Erase! it

                        EnableInterrupts;
                        /* send ACK to USB */
                        putchar(FCACK); 
                        flush();
                        LED1 = LEDOFF;
                        break;
                            
                    case WRITE:
                        LED3 = LEDON;
                        file_ptr.bus_spd = BUS_SPD;
                        file_ptr.addr.b.hi = getchar();  // addr hi
                        file_ptr.addr.b.lo = getchar();  // addr lo

                        file_ptr.datasize = getchar();  // length
                        
                        for (i=0; i < file_ptr.datasize; i++)
                            file_ptr.data[i] = getchar();

                        DisableInterrupts;

                        Prgrnge(file_ptr);      // Flash! it
                            
                        EnableInterrupts;
                        /* send ACK to USB */
                        putchar(FCACK); 
                        flush();
                        LED3 = LEDOFF;
                        break;
                    case IDENT:
                        for (i=0; i < sizeof(idents); i++) 
                            putchar(idents.str[i]);    
                        putstr("JW32/USB $Version: 1.0.19.0$");

                        LED1 = LEDON;
                        LED2 = LEDOFF;
                        LED3 = LEDON;
                        
                        break;
                    case QUIT:
                        quit = 1;
                        break;
                }
            }

          USBCR = 0;      /* disable USB */

        } /* if ((boot_table[FLASH_WRITE_PAGE-1] == SIG_EMPTY) || (IRQPin() == 0)) */

        flash_boot_table ((char *)&usr_boot_table, SIG_USR);
            
        ILOP;

    } 
    else  /* if ((boot_table[FLASH_WRITE_PAGE-1] != SIG_USR) || (IRQPin() == 0))  */
    {
        Protect((char *)&boot_table);

        asm JMP boot_table:8;
        
    }; /* if ((boot_table[FLASH_WRITE_PAGE-1] != SIG_USR) || (IRQPin() == 0)) */
}