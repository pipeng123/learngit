/*******************************************************************************
 *
 * (c) Freescale Semiconductor, 2009, All rights reserved 
 * 
 ******************************************************************************* 
 * 
 * $File Name        : flashapi.h$
 * $Date             : Feb-6-2009$
 * $Version          : 10.0.2.0$ 
 * $Last Modified By : r30323$
 * 
 * Description       : Flash Erase/Write API wrapper
 * 
 ******************************************************************************/ 



/*

FLASHPROGAPI pointers are stored at following addreses:

MC9S08QD2/4           0xFFFA:0xFFFD


Reserved RAM locations are:

MC9S08QD2/4           0x0063:0x006A - total 7 bytes


thus your application MUST NOT use these memory locations. These will be overwritten
during FLASHPROGAPI calls.

You have to modify your application PRM file as following:

original (QD4 example):
  Z_RAM  = READ_WRITE 0x0060 TO xxx; 

modified (QD4 example):
  Z_RAM  = READ_WRITE 0x006B TO xxx; 



API usage - is simple :)
------------------------

#include "flashapi.h"            // just include *THIS* file ;)

char source[] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

#pragma CONST_SEG MYEEPROMFLASHPAGE  
// MYEEPROMFLASHPAGE must be of 512B size {erase page}

const char target[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

#pragma CONST_SEG DEFAULT

void main(void)
{
    /-* MCU INIT HERE *-/

    // flash clock MUST be initialized properly
    
    /-* MCU INIT ENDS HERE *-/
    

    FlashErase(target);                 // erase where target buffer is stored
    FlashWrite(target, source, 0x10);   // "copy" 0x10 bytes from source (in RAM!) to target (in FLASH)

}

*/

#ifndef _FLASHPROGAPI_
#define _FLASHPROGAPI_ 1

#define FLASHERASEADDR 0xfffa /* S08QD families */
#define FLASHWRITEADDR 0xfffc /* S08QD families */

//                            ADRS (to)             ADRR (from)     LEN (len)
#define FlashWrite ((void (*)(const unsigned char*, unsigned char*, unsigned char)) (*((unsigned int *)FLASHWRITEADDR)))
#define FlashErase ((void (*)(const unsigned char*)) (*((unsigned int *)FLASHERASEADDR)))

// provide macros for backward compatibilty with DoOnStack package
#define  FlashProgBurst     FlashWrite
#define  FlashErase1        FlashErase

#endif
