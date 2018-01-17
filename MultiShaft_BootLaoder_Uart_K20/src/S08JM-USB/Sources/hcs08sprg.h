/*****************************************************************************
*
* (c) 2009 Freescale Inc.
* ALL RIGHTS RESERVED.
*
**************************************************************************//*!
*
* @file      hcs08sprg.h
* @version   1.0.10.0
* @date      Jun-22-2009
* @author    r30323
*
* @brief     hc08sprg S08JM main header file
*  
*****************************************************************************/

#ifndef _HCS08SPRG_H
#define _HC0S8SPRG_H


#define put_char (void)cdc_putch

#define ILOP    asm DCB $8d 

#define PROTOCOL_VERSION 0x82
#define FLASH_WRITE_PAGE 64
#define FLASH_ERASE_PAGE 512


#define FCACK   0xFC

#define READ    0x52
#define WRITE   0x57
#define ERASE   0x45
#define IDENT   0x49
#define QUIT    0x51

#define SIG_EMPTY 0xFF
#define SIG_USR   0xFE
#define SIG_BOOT  0xFC

#define TABLE_VECT_SIZE 65


typedef union
{
    struct{
        unsigned char hi;
        unsigned char lo;
    } b;
    unsigned char * w;
} HILOWORD;

typedef struct{
    unsigned char datasize;
    HILOWORD addr;
    unsigned char data[TABLE_VECT_SIZE];
} FILE_PTR_STR;

  
typedef union{
    struct {
        unsigned char numflash;  // number of flash blocks 
        char * flsbeg;           // start of flash1
        char * flsend;           // end of flash1
      #if SIZE == 60
        char * flsbeg2;          // start of flash2
        char * flsend2;          // end of flash2
      #endif    
        char * aplvect;          // application vector table (boot table)
        char * intvect;          // start of interrupt vectors
        unsigned int erblklen;   // erase page length
        unsigned int wrblklen;   // write page length
    } idx;
    char str[20];
} IDENT_STR;  


#endif
