#ifndef _HC08SPRG_H
#define _HC08SPRG_H

// types
typedef union
{
    struct{
        unsigned char hi;
        unsigned char lo;
    } b;
    unsigned char * w;
} HILOWORD;

typedef struct{
    unsigned char bus_spd;
    unsigned char datasize;
    HILOWORD addr;
    unsigned char data[64];
} FILE_PTR_STR;

#define Protect(x) FLBPR = ((unsigned int)(x)>>8)&0xFE

/*
typedef void (*PTR2FILE_PTR)(FILE_PTR_STR * file_ptr); 

#define Prgrnge ((PTR2FILE_PTR) 0xFE10)

#define Erarnge ((PTR2FILE_PTR) 0xFE13)

*/

typedef void (*PTR2FUN)(void); 

#define Prgrnge(x) {asm LDHX @x;((PTR2FUN) 0xFE10)();}
#define Erarnge(x) {asm LDHX @x;((PTR2FUN) 0xFE13)();}
#define Ldrnge(x) {asm LDHX @x;((PTR2FUN) 0xFA31)();}


typedef union{
    struct {
        unsigned char caps;      // bootloader capability table, version
        unsigned int sdid;       // SDID (unused)
        unsigned char numflash;  // number of flash blocks
        char * flsbeg;           // start of flash
        char * flsend;           // end of flash
        char * aplvect;          // application vector table (boot table)
        char * intvect;          // start of interrupt vectors
        unsigned int erblklen;  // erase page length
        unsigned int wrblklen;  // write page length
    } idx;
    char str[16];
} IDENT_STR;

#define ILOP    asm DCB $32

#define FLASH_WRITE_PAGE 64
#define FLASH_ERASE_PAGE 512

#define BUS_SPD 32

#define FCACK   0xFC
#define READ    'R'
#define ERASE   'E'
#define WRITE   'W'
#define IDENT   'I'
#define QUIT    'Q'

#define SIG_EMPTY 0xFF
#define SIG_USR   0xFE
#define SIG_BOOT  0xFC

#define NUM_OF_VECTS 17

#endif
