#include "cfm.h"
#include "mcf51JM128_cfm.h"
#include "hidef.h"

/********************************************************************/
/*
 * Performs a page erase of the flash memory. 
 * Note: assumes that the flash clock dividor and block protection 
 *       has been preset.
 *
 * Parameters:
 *  address     An address within the page to be erased
 *
 ********************************************************************/
 
volatile int Page_erase (unsigned int address)
{   
    /* Allocate space on stack to run flash command out of SRAM */
   char buf[100];
   int (*RunOnStack)(void) = (int(*)(void))buf;   
   memcpy(buf, (void*)SpSub, (char*)SpSubEnd - (char*)SpSub);
   

   MCF_CFM_CFMUSTAT = (MCF_CFM_CFMUSTAT_PVIOL  | MCF_CFM_CFMUSTAT_ACCERR);
    
    
   while (!(MCF_CFM_CFMUSTAT & MCF_CFM_CFMUSTAT_CBEIF)){};
   
   (*(volatile vuint32 *)(/*FLASH_START_ADDRESS + */address)) = (vuint32)-1;
  
  
   FCMD = mPageErase;
   
   RunOnStack();

   
   if (MCF_CFM_CFMUSTAT & MCF_CFM_CFMUSTAT_ACCERR) {return 0;}
   if (MCF_CFM_CFMUSTAT & MCF_CFM_CFMUSTAT_PVIOL)  {return 0;}
   return(1);
   
}

/********************************************************************/
/*
 *   Code required to run in SRAM to perform flash commands. 
 *  All else can be run in flash.
 *
 ********************************************************************/ 
void SpSub(void) 
{
   asm(
   
      move.w  SR,D7             /* current sr            */
      move.l  D7,D5            /* save return value     */
      move.w  #0x0700,D6      /* set level to 7        */
      andi.l  #0x0000F8FF,D7  /* zero out current IPL  */
      or.l    D6,D7           /*   */
      move.w  D7,SR           /* place new IPL in sr   */

      // MCF_CFM_CFMUSTAT = CBEIF;
      
      move.l   #MCF_CFM_CFMUSTAT,a4  
      move.b   #0x80,d1     
      move.b   d1,(a4)

      // while (!(MCF_CFM_CFMUSTAT & CCIF)){};//wait until execution complete
      loop:
      move.l   #MCF_CFM_CFMUSTAT,a4  
      move.b   (a4),d2
      moveq    #0,d1
      move.b   d2,d1
      andi.l   #0x40,d1     
      beq.s    loop

      move.w  D5,SR
   );
}

void SpSubEnd(void){} 

/********************************************************************/
/*
 * Performs a write of the flash memory. 
 * Note: assumes that the flash clock dividor and block protection 
 *       has been preset.
 *
 * Parameters:
 *  address     The location of memory to be programed
 *  data        The data to be programed to memory
 *
 ********************************************************************/
 
volatile int Burst_Prog(uint32 *destination, uint32 *source, uint32 lenght)
{
   /* Allocate space on stack to run flash command out of SRAM */
   char localbuf[100];
   int (*RunOnStack)(uint32 *destination, uint32 *source, uint32 lenght) = (int(*)(uint32 *destination, uint32 *source, uint32 lenght))localbuf;
   memcpy(localbuf, (void*)SpSubBurst, (char*)SpSubBurstEnd - (char*)SpSubBurst);

   /* Check to make sure long word is aligned */
   if((uint32)destination & 0x00000001) {return 0;} 

   /* Clear any errors */
   
   MCF_CFM_CFMUSTAT = (MCF_CFM_CFMUSTAT_PVIOL | MCF_CFM_CFMUSTAT_ACCERR);
   
   RunOnStack(destination,source,lenght);
   
   
  if (MCF_CFM_CFMUSTAT & MCF_CFM_CFMUSTAT_ACCERR) {return 0;}
   if (MCF_CFM_CFMUSTAT & MCF_CFM_CFMUSTAT_PVIOL)  {return 0;}
   return 1;

}
/********************************************************************/
/*
 *   Code required to run in SRAM to perform flash commands. 
 *  All else can be run in flash.
 *
 ********************************************************************/ 
void SpSubBurst(uint32 *destination, uint32 *source, uint32 lenght) 
{
   DisableInterrupts;

   while(lenght--) {
     
     while (!(MCF_CFM_CFMUSTAT & MCF_CFM_CFMUSTAT_CBEIF)){};
       
     (*( vuint32 *)(FLASH_START_ADDRESS+(uint32)(destination++))) =  *(source++);
      
     FCMD = mBurstProg;
     
     MCF_CFM_CFMUSTAT = MCF_CFM_CFMUSTAT_CBEIF;
   
     while (!(MCF_CFM_CFMUSTAT & MCF_CFM_CFMUSTAT_CCIF)){};        //wait until execution complete
   }
   
   EnableInterrupts;
}

void SpSubBurstEnd(void){} 
