 #ifndef _HC08SPRG_H
 #define _HC08SPRG_H


#define NUMBER_OF_VECTOR 111
#define START_RAM_VEC    0x000800000

#define FLASH_WRITE_PAGE 128
#define FLASH_ERASE_PAGE 1024
#define FLASH_END (RAM_vector - (4*NUMBER_OF_VECTOR))

#if VERSION==0
#define RELINTVECT      0x3000
#define USER_APP        (RELINTVECT+6)                  
#endif



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


#if VERSION==0
typedef union{
    struct {
        int numflash;          // number of flash blocs
        int * flsbeg1;           // start of flash memory
        int * flsend1;           // end of flash memory
        int * intvect;          // start of interrupt vectors table
        int * relintvect;       // start of interrupt vectors table
        int erblklen;           // erase page length
        int wrblklen;           // write page length 
    } idx;
    char str[7];
} IDENT_STR;  
#else
typedef union{
    struct {
        int numflash;          // number of flash blocs
        int * flsbeg1;           // start of flash memory
        int * flsend1;           // end of flash memory
        int * flsbeg2;           // start of flash memory
        int * flsend2;           // end of flash memory
        int * intvect;          // start of interrupt vectors table
        int * relintvect;       // start of interrupt vectors table
        int erblklen;           // erase page length
        int wrblklen;           // write page length 
    } idx;
    char str[7];
} IDENT_STR;  
#endif


#define RESET_ADDRESS    0x1C2
#define RESET_APP        0x1C0  
#define ASM_JUMP         0x4EF9 << 16

#define BYTE 4
#define PROTOCOL_VERSION 0x84
#define FCACK   0xFC
#define READ    0x52
#define WRITE   0x57
#define ERASE   0x45
#define IDENT   0x49
#define QUIT    0x51

#define LED1 PTEDD_PTEDD2
#define LED2 PTEDD_PTEDD3
#define LED3 PTFDD_PTFDD0
#define LED4 PTFDD_PTFDD1
#define LED5 PTCDD_PTCDD2
#define LED6 PTCDD_PTCDD4
#define LED7 PTFDD_PTFDD5

#define LEDON  1
#define LEDOFF 0

#define TRUE   1
#define FALSE  0

#endif
