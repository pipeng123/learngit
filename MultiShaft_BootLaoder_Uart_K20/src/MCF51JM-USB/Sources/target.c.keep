/***************************************************************************
 *
 *            Copyright (c) 2006-2007 by CMX Systems, Inc.
 *
 * This software is copyrighted by and is the sole property of
 * CMX.  All rights, title, ownership, or other interests
 * in the software remain the property of CMX.  This
 * software may only be used in accordance with the corresponding
 * license agreement.  Any unauthorized use, duplication, transmission,
 * distribution, or disclosure of this software is expressly forbidden.
 *
 * This Copyright notice may not be removed or modified without prior
 * written consent of CMX.
 *
 * CMX reserves the right to modify this software without notice.
 *
 * CMX Systems, Inc.
 * 12276 San Jose Blvd. #511
 * Jacksonville, FL 32223
 * USA
 *
 * Tel:  (904) 880-1840
 * Fax:  (904) 880-1632
 * http: www.cmx.com
 * email: cmx@cmx.com
 *
 ***************************************************************************/
#include "target.h"
#include "hcc_types.h"
#include <hidef.h>
#include "mcf51xx_reg.h"



static void init_clock(void)
{
 /* Assume 12MHz external clock source connected. */
  
  /* In order to use the USB we need to enter PEE mode and MCGOUT set to 48 MHz. 
     Out of reset MCG is in FEI mode. */
     
  /**** Moving from FEI (FLL engaged internal) to PEE (PLL engaged external) mode. */ 
  /* switch from FEI to FBE (FLL bypassed external) */ 
    /* enable external clock source */
    
  MCGC2 = MCGC2_HGO_MASK          /* oscillator in high gain mode */
          | MCGC2_EREFS_MASK      /* because crystal is being used */
          | MCGC2_RANGE_MASK      /* 12 MHz is in high freq range */
          | MCGC2_ERCLKEN_MASK;   /* activate external reference clock */
  while (MCGSC_OSCINIT == 0)
    ;
    /* select clock mode */
  MCGC1 = (2<<6)         /* CLKS = 10 -> external reference clock. */
          | (3<<3);      /* RDIV = 3 -> 12MHz/8=1.5 MHz */
  
    /* wait for mode change to be done */
  while (MCGSC_IREFST != 0)
    ;
  while (MCGSC_CLKST != 2)
    ;
    
  /* switch from FBE to PBE (PLL bypassed internal) mode */
  MCGC3=MCGC3_PLLS_MASK
        | (8<<0);     /* VDIV=6 -> multiply by 32 -> 1.5MHz * 32 = 48MHz */
  while(MCGSC_PLLST != 1)
    ;
  while(MCGSC_LOCK != 1)
    ;
  /* finally switch from PBE to PEE (PLL enabled external mode) */
  MCGC1 = (0<<6)         /* CLKS = 0 -> PLL or FLL output clock. */
          | (3<<3);      /* RDIV = 3 -> 12MHz/8=1.5 MHz */
  while(MCGSC_CLKST!=3)
    ;
    
  /* Now MCGOUT=48MHz, BUS_CLOCK=24MHz */  
}


void init_board(void)
{
  /* Configure LED io pins to be outputs. 
   * EVB51JM128: LED to port mapping: 
   *  LED1  LED2 LED3 LED4 LED5 LED6 LED7 LED8
   *   |     |    |    |    |    |    |    |
   *   ^     ^    ^    ^    ^    ^    ^    ^
   *  PTE2  PTE3 PTF0 PTF1 PTF5 PTD2 PTC4 PTC6
   * DEMO51JM128: LED to port mapping: 
   *  LED1  LED2 LED3 LED4 LED5 LED6 LED7 LED8
   *   |     |    |    |    |    |    |    |
   *   ^     ^    ^    ^    ^    ^    ^    ^
   *  PTE2  PTE3 PTF0 PTF1 PTC2 PTC4 PTF5 PTD2
   */
  PTEDD= PTED_PTED2_MASK | PTED_PTED3_MASK;
  PTFDD= PTFD_PTFD0_MASK | PTFD_PTFD1_MASK | PTFD_PTFD5_MASK;
  PTCDD= PTCD_PTCD4_MASK 
 #ifdef EVB
          | PTCD_PTCD6_MASK
 #else
          | PTCD_PTCD2_MASK          
 #endif          
          ;
          
  PTDDD= PTDD_PTDD2_MASK;
  
  /* Enable internal pull-ups on port E pins to get switches working.
   * EVB51JM128: Button-to-port mapping:
   *  SW1   SW2   SW3   SW4
   *   |     |     |     |
   *   ^     ^     ^     ^
   *  PTG1  PTG2  PTG3  PTD5
   * DEMO51JM128: Button-to-port mapping:
   *  SW1   SW2   SW3   SW4
   *   |     |     |     |
   *   ^     ^     ^     ^
   *  PTG0  PTG1  PTG2  PTG3
   */
  PTGPE= PTGPE_PTGPE1_MASK | PTGPE_PTGPE2_MASK | PTGPE_PTGPE3_MASK
  #ifndef EVB
    | PTGPE_PTGPE0_MASK  
  #endif
   ;
  PTDPE= PTDPE_PTDPE5_MASK ;
}

void _irq_restore (hcc_imask ip)
{
    asm_set_ipl(ip);
}

hcc_imask _irq_disable (void)
{
    return((hcc_imask)asm_set_ipl(7));
}



/********************************************************************/
void hw_init(void)
{  
  /* Disable watchdog. */
  SOPT1_COPT=0;
#ifdef LITTLE_ENDIAN_MODE  
  SOPT2  &= ~(1<<5); /* MUST clear bit 5 to use little endian for memory access */
#endif 


  init_clock();
 //init_board();
 //EnableInterrupts;  
}


void Usb_Vbus_On(void)
{
  PTHD_PTHD4 = 0;   /* turn AMD (Vbus) switch on */
}

void Usb_Vbus_Off(void)
{
  PTHD_PTHD4 = 1;  /* turn AMD (Vbus) switch onff */
}

int Usb_Vbus_Stat(void)
{
  return((PTGD_PTGD0 & 0x4)>>2);
}


void stack_init(byte pattern) 
{
   extern unsigned long far __SP_END;
   byte far * stackEnd  = (byte far*)&__SP_END;
   byte far * stackPointer;
   asm{
    move.l A7,stackPointer
   }
   stackPointer -= 4; 
   for (;stackPointer >= stackEnd;) 
   {
      *stackPointer-- = pattern;
   }
}


long stack_size(byte pattern) 
{
   extern unsigned long far __SP_END;
   extern unsigned long far __SP_INIT;
   byte far * stackEnd  = (byte far*)&__SP_END;
   byte far * stackBegin = (byte far*)&__SP_INIT;
   byte far * stackPointer;
   byte far *tempStackPointer = stackEnd;
   long stackSize = 0;
   
   asm{
    move.l A7,stackPointer
   }

   // Search the stack for pattern
   for(;tempStackPointer <= (stackPointer);tempStackPointer++) 
   {
      if(*tempStackPointer != pattern) 
      {
        break;
      }
      stackSize++;
   }
   
   return (stackBegin-stackEnd+1-stackSize);
}/****************************** END OF FILE **********************************/