 #ifndef _HC08SPRG_H
 #define _HC08SPRG_H

#define FLASH_WRITE_PAGE      128
#define FLASH_ERASE_PAGE      4096

#define EnableInterrupts asm { move.w SR,D0; andi.l #0xF8FF,D0; move.w D0,SR;  }
  /*!< Macro to enable all interrupts. */
#define DisableInterrupts asm { move.w SR,D0; ori.l #0x0700,D0; move.w D0,SR;  }
  /*!< Macro to disable all interrupts. */

typedef union
{
    struct{
        unsigned char byte03;         //  first byte of address
        unsigned char byte02;         //  second byte of address
        unsigned char byte01;         //  third byte of address
        unsigned char byte00;         //  fourth byte of address
    } b;
    unsigned char * w;
    unsigned int * i;
} HILOWORD;

typedef union{
  unsigned char data8[FLASH_WRITE_PAGE];
  unsigned int data32[FLASH_WRITE_PAGE / 4];
}FILE_PTR_DATA;

typedef struct{
    unsigned char datasize;
    HILOWORD addr;
    FILE_PTR_DATA data;
} FILE_PTR_STR;

typedef union{
    struct {
        int numflash;      // number of flash blocs
        int * flsbeg1;   // start of flash memory
        int * flsend1;   // end of flash memory
        int * flsbeg2;   // start of flash memory
        int * flsend2;   // end of flash memory
        int * intvect;   // start of interrupt vectors table
        int * relintvect;   // start of interrupt vectors table
        int erblklen;      // erase page length
        int wrblklen;      // write page length 
    } idx;
    char str[7];
} IDENT_STR;  

#define RESET_APP   0x4E0
#define MAX_VALUE   0x1FFFF  
#define MCF_CCM_CIR_REG  0x40110008

#define BYTE 4
#define PROTOCOL_VERSION   0x84
#define FCACK   0xFC
#define READ    0x52
#define WRITE   0x57
#define ERASE   0x45
#define IDENT   0x49
#define QUIT    0x51

#define LEDON  1
#define LEDOFF 0

#define TRUE   1
#define FALSE  0

#endif
