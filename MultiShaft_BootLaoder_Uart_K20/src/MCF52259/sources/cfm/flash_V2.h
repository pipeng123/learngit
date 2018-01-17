/*************************************************************
 * File:          cfm.h
 * Purpose:     Provide common ColdFire Flash routines.
 *************************************************************/

#ifndef __CFM_H__
#define __CFM_H__

/***********************************************************************/
 /* The basic data types */

 typedef unsigned char       uint8;  
 typedef unsigned short int  uint16; 
 typedef unsigned long int   uint32; 

 typedef char                int8;  
 typedef short int           int16; 
 typedef int                 int32;  

 typedef volatile int8       vint8;  
 typedef volatile int16      vint16; 
 typedef volatile int32      vint32; 

 typedef volatile uint8      vuint8;  
 typedef volatile uint16     vuint16; 
 typedef volatile uint32     vuint32;
 
  
/***********************************************************************/

#define CFM_IPS_FLASH_ADDR   0x44000000

/* Last Address of execution code is where data begins */

#define FLASH_DATA_ADDR ((vuint32)0x800)

/* address in memory map to write in FLASH */
#define FLASH_START_ADDRESS CFM_IPS_FLASH_ADDR

/* End address for region of flash */
#define FLASH_END_ADDRESS  (vuint32)&__FLASH_SIZE+0x44000000

/* Flash erase page size */
#define FLASH_PAGE_SIZE    0x0800

/********************************************************************/

volatile int Burst_Prog (uint32 *destination, uint32 *source, uint32 lenght);
volatile int Page_erase (unsigned int);

void SpSub(void); 
void SpSubEnd(void);
void SpSubBurst(uint32 *destination, uint32 *source, uint32 lenght); 
void SpSubBurstEnd(void);


/********************************************************************/
#endif /* __CFM_H__ */

