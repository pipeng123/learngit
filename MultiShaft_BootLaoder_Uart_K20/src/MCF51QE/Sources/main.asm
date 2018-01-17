/*****************************************************************//*!
* HEADER_START
*
* @file      main.asm
* @version   1.0.20.0
* @date      Oct-10-2011
* @author    B20253
*
* @brief     MCF51QE main bootloader file
*
* =================================================================== 
* Copyright (c):       FREESCALE Inc., 2009, All rights reserved.     
* =================================================================== 
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY              
* EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  
* PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL FREESCALE OR             
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT        
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;        
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)            
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
* OF THE POSSIBILITY OF SUCH DAMAGE.                                  
* =================================================================== */

/* label SCI = 1, 2 selects what SCI channel is used              */
/* label HISPEED => if defined, 115200Bd is used instead of 9600Bd */


         
  .extern   __SP_INIT
  .extern   __SP_AFTER_RESET
  .global _asm_function
  .global _main
  .global _asm_startmeup
  .include "derivative.inc"  

/*******************************************************************************/

.function "_asm_startmeup",_asm_startmeup,_asm_startmeup_end-_asm_startmeup
.data

/**********************************************************************/

  .IF(SCI == 1)      /*  definition SCI_1  */
   
SCIBDH     .equ SCI1BDH
SCIBDL     .equ SCI1BDL
SCIC1      .equ SCI1C1
SCIC2      .equ SCI1C2
SCIC3      .equ SCI1C3
SCIS1      .equ SCI1S1
SCIDR      .equ SCI1D

  .ELSE IF(SCI == 2) /* definition SCI_2 */
  
SCIBDH     .equ SCI2BDH
SCIBDL     .equ SCI2BDL
SCIC1      .equ SCI2C1
SCIC2      .equ SCI2C2
SCIC3      .equ SCI2C3
SCIS1      .equ SCI2S1
SCIDR      .equ SCI2D

  .ENDIF

  
DATA:      .DS.B    128
TMPSTOR:   .DS.B    12

REDIR:     .EQU     0x3F4           /* INIT_PC, INIT_SP and NVTRIM values stored here */

PROT_VER   .EQU     0x84            /* PROTOCOL VERSION - READ COMMAND IMPLEMENTED */

WR_DATA:   .equ     "W"           /* WRITE COMMAND */
RD_DATA:   .equ     "R"           /* READ  COMMAND */
ERASE:     .equ     "E"           /* ERASE COMMAND */
IDENT1:    .equ     "I"           /* IDENT COMMAND */
QUIT_DATA: .equ     "Q"
 
ACK:       .equ     0xFC          /* ACKNOWLEDGE */


.section  code
.text


  IDENT:              /* IDENT STRING BEGIN */

   NFLBLKS:       .DC.L   0x2        /* NUMBER OF FLASH BLOCKS */
   FLS_BEG1:      .DC.L   0x0        /* FLASH START ADDRESS */
   FLS_END1:      .DC.L   0x3F3      /* FLASH END ADDRESS */

   FLS_BEG2:      .DC.L   0x400      /* FLASH START ADDRESS */

  .IF(SIZE==128) 
   FLS_END2:      .DC.L   0x1FBFF    /* FLASH END ADDRESS */
  .ELSEIF(SIZE==64)
   FLS_END2:      .DC.L   0x0FBFF    /* FLASH END ADDRESS */
  .ELSEIF(SIZE==32)
   FLS_END2:      .DC.L   0x07BFF    /* FLASH END ADDRESS */
  .ENDIF

   REL_VECT:      .DC.L   0x0        /* RELOCATED VECTOR TABLE  */
   INT_VECT:      .DC.L   0x0        /* INTERRUPTS VECTOR TABLE */
   ERBLK_LEN:     .DC.L   1024       /* ERASE BLOCK LENGTH */
   WRBLK_LEN:     .DC.L   128        /* WRITE BLOCK LENGTH */
   IDENTSTR:      .DC.B   "MCF51QE"
  .IF(SIZE==128) 
                  .DC.B   "128"
  .ELSEIF(SIZE==64) 
                  .DC.B   "64"
  .ELSEIF(SIZE==32) 
                  .DC.B   "32"
  .ENDIF
   ZERO:          .DC.W   0
  IDENT_END:          /* IDENT STRING END */




/********************************************************************************/
 _asm_startmeup:
  
             move.w  #0x2700,SR  
             lea     __SP_INIT,A7
             
/********************************************************************************/        
_main:
             move.b  SRS,d0           /* fetch RESET status reg. */
             btst    #4,d0
             beq.s   INIT_CLOCK
             
             move.l  REDIR,a7        /* restore user code SP */

             move.l  REDIR+4,a0      /* jump to user code */
             jmp     (a0)
             
INIT_CLOCK:
             move.b  #0x0F,d0
             move.b  d0,SOPT1
             
             moveq   #0,d6            /* zero page flag */
   
             move.b  #0xFF, d1
             move.b  d1,TMPSTOR+8     /* dummy */
             move.b  d1,TMPSTOR+9

             move.b  NVFTRIM,d1
             move.b  d1,TMPSTOR+10
             
             move.b  NVICSTRM,d1
             move.b  d1,TMPSTOR+11      
             move.b  d1,ICSTRM

             moveq   #%00000110,d0     
             move.b  d0,ICSC1         
                                     
             move.b  #%00000000,d0    
             move.b  d0,ICSC2         
                                     
ICS_SET:     mvz.b   ICSSC,d1        /* ICG clock = 48MHz */
             moveq   #27,d0          /* BUSCLOCK = ICG clock/2 = 24MHz*/
             lsl.l   d0,d1           /* SCICLOCK = BUSCLOCK */ 
             moveq   #31,d0
             lsr.l   d0,d1
             tst.b   d1
             beq.s   ICS_SET            
            
             mvz.b   ICSSC,d1
             moveq   #-97,d0
             and.l   d0,d1
             mvz.b   d1,d0
             bset    #7,d0
             move.b  d0,ICSSC
          
  
INIT_SCI:    clr.b   SCIBDH            /* initialize SCI    */
             
           .IFNDEF HIGHSPEED
             move.b  #156,d0           /* 9600  Baud rate   */
           .ELSE
             move.b  #13,d0            /* 115200 Baud rate   */
           .ENDIF 
       
             move.b  d0,SCI1BDL
             clr.b   SCIC1
             
             moveq   #0x0C,d0          /* transmit & receive enable */
             move.b  d0,SCIC2
                                    
             clr.b   SCIC3             /* clear byte SCIC3 */

             moveq   #%01001110,d0     /* set up flash clock */
             move.b  d0,FCDIV          /* 24MHz/200kHz = 120; PRDIV8=1, FDIV=14 */

/********************************************************************************/
             move.b  #ACK,d0
             bsr     WRITE            /* send acknowledge to master */
             move.l  #0x0,d3
             move.w  #0xFFFF,d3

L1:          move.b  SCIS1,d1
             btst    #5,d1
             bne.s   CAUGHT

             subi.l  #1,d3
             cmpi    #0,d3
             
             bne.s   L1

             bra     ILOP               /* generate RESET by doing illegal operation */
/*********************************************************************************/
CAUGHT:   
             BSR     READ
             cmpi    #ACK,d0
             bne.s   CAUGHT
             bra.s   SUCC

/*********************************************************************************/
IDENT_COM:      
             move.b  #PROT_VER,d0
             bsr     WRITE
             move.b  SDIDH,d0               /* system device identification 1 register (high) */
             bsr     WRITE
             move.b  SDIDL,d0               /* system device identification 1 register (low)  */
             bsr     WRITE
             lea     IDENT,a0
             move.b  #(IDENT_END-IDENT),d3  /* length */
             bsr     WRITE_LOOP
             bra     BCKGND
       
/********************************************************************************/
SUCC:
             move.b  #ACK,d0
             bsr     WRITE
/*********************************************************************************/
BCKGND:
             bsr     READ

             cmpi.b  #ERASE,d0
             beq.s   ERASE_COM 
             
             cmpi.b  #WR_DATA,d0
             beq     WR_DATA_COM 
             
             cmpi.b  #IDENT1,d0
             beq.s   IDENT_COM
             
             cmpi.b  #RD_DATA,d0
             beq     RD_DATA_COM
             
             cmpi.b  #QUIT_DATA,d0
             beq.s   BURST_RESET

ILOP:
             stop    #0                   ;ILOP
/********************************************************************************/        
BURST_RESET: 
             tst     d6                 /* test D6 zero page flag */
             beq.s   ILOP               /* if zero page not modified, jump to ILOP */
             
             moveq   #2,d6              /* make sure BURST will go to ILOP instead */

             move.l  #REDIR,d2          /* destination address minus two dummy */
             move.l  #TMPSTOR,a3        /* source address */
             moveq   #12,d4             /* length */
            
             bra     BURST
                        
/********************************************************************************/
ERASE_COM:
             bsr     READ
             lsl.l   #8,D0                  
             bsr     READ                                           
             lsl.l   #8,D0
             bsr     READ                                           
             lsl.l   #8,D0
             bsr     READ
           
             move.l  d0,d1
             move.l  #(SpSubEnd),a1
             move.l  #(SpSub),a6
             
             bsr     RunOnStack

             move.l  a0,a1                  /* SET UP FACCER A FPVIOL FLAG TO 1 */
             moveq   #(mFSTAT_FACCERR | mFSTAT_FPVIOL),d0
             move.b  d0,FSTAT
loop:      
             move.b  FSTAT,d0               /* TESTING bit FCBEF */
             btst    #FSTAT_FCBEF,d0
             beq.s   loop          
            
             move.l  d1,a0                  /* ADDRESS OF ERASE BLOCK MOVE TO A0 */
             move.l  #0xFF,(a0)             /* DUMMY DATA */
            
             moveq   #mPageErase,d0         /* FLASH COMMAND 0x40 - SECTOR ERASE */
             move.b  d0,FCMD                /* MOVE TO REGISTER FCMD */
             
             jsr     (A1)                    /* JUMP TO FLASH ROUTINE ON THE STACK */
             bra     SUCC                    /* ACKNOWLEDGE */
       
/*******************************************************************************/

WR_DATA_COM:
             bsr     READ
             lsl.l   #8,D0                /* ROTATE LEFT 8 BITS */
             bsr     READ
             lsl.l   #8,D0                /* ROTATE LEFT 8 BITS */                       
             bsr     READ
             lsl.l   #8,D0                /* ROTATE LEFT 8 BITS */
             bsr     READ
             
             move.l  d0,d2                /* FINALY ADDRESS OF FLASH MEMORY AREA */
             bsr     READ
             
             move.b  d0,d4                /* TBD */
             move.b  d0,d3
             
             move.l  #DATA,a3             /* source address */

             cmpi.l  #0x0,d2              /* TESTING THE FIRST BYTE "INIT_SP"*/
             beq.s   WRITE_RESET
             
             cmpi.l  #0x4,d2              /* TESTING THE SECOND BYTE "RESET" */
             bne.s   WR_DATA_L1
             
WRITE_RESET:
             moveq   #0x01,d6               /* indicate that zero page has been modified */

             move.l  #(__SP_INIT),(a3)         /* INIT SP */
             addq.l  #4,a3
             
             move.l  #(_asm_startmeup),(a3)    /* RESET VECTOR */
             addq.l  #4,a3
             
             moveq   #8,d5
             move.l  #(TMPSTOR),a4
            
LOAD_RESET:          
             bsr     READ
             
             move.b  d0,(a4)

             subi.l  #1,d5
             addq.l  #1,a4
              
             cmpi.b  #0,d5  
              
             bne.s   LOAD_RESET
               
             subi.l  #8,d3
             
WR_DATA_L1:
             bsr     READ
             move.b  d0,(a3)
             
             addq.l  #1,a3               /* INCREMENT ADDRESS AND DATA */
             subi.l  #1,d3     
            
             cmpi.b  #0,d3               /* COMPARE SIZE OF DATA WITH ZERO */
                  
             bne.s   WR_DATA_L1     
           
             move.l  #DATA,a3             /* source address */
BURST:       
             move.l  #(SpSubBurstEnd),a1
             move.l  #(SpSubBurst),a6

             bsr     RunOnStack
FCBEF1:       
             move.l  a0,a1
             moveq   #(mFSTAT_FACCERR | mFSTAT_FPVIOL),d0
             move.b  d0,FSTAT           /* clear FACCERR & FPVIOL flags */
loop1:      
             move.b  FSTAT,d0
             btst    #FSTAT_FCBEF,d0
             beq.s   loop1 
           
             jsr     (A1)
             
             cmpi.b  #2,d6               /* compare zero page flag */
             beq.l   ILOP
             
             bra     SUCC
         
/*******************************************************************************/
RD_DATA_COM:

             bsr     READ           /* BYTE 01 */
             lsl.l   #8,D0
             bsr     READ           /* BYTE 02 */
             lsl.l   #8,D0
             bsr     READ           /* BYTE 03 */
             lsl.l   #8,D0
             bsr     READ           /* BYTE 04 */
             move.l  d0,a0
             bsr     READ           /* LENGTH */
             move.b  d0,d3          /* move length from D0 to D3 */
             
             cmpa.l  #0x0,a0
             bne.s   NEXT_DATA
             
             move.b  d3,d4
             move.l  a0,a1
             
             moveq   #0x0,d0
             move.b  d0,TMPSTOR
             
             move.l  #TMPSTOR,a0
             move.b  #8,d3
             bsr.s   WRITE_LOOP
             
             move.b  d4,d3
             subi.l  #8,d3
             
             move.l  a1,a0
             adda.l  #8,a0  
        
NEXT_DATA:   bsr.s   WRITE_LOOP
             
             bra     BCKGND
             
/*******************************************************************************/        
WRITE_LOOP:

             move.b  (a0),d0                 
             bsr.s   WRITE                  
             addq.l  #1,a0                   
             subi.l  #1,d3                  // decrement LEN
             cmpi.b  #0,d3                  // compare length with zero
             bne.s   WRITE_LOOP             // branch if no equal to WRITE_LOOP
            
             rts   
/*******************************************************************************/ 
RunOnStack:
             move.l  A7,A2       /* save actual address SP */
RunOnStack1:
             suba.l  #2,a7       
             
             move.w  (a1),d0
             move.w  d0,(A7)
             
             cmpa.l  a6,a1       /* SELECTED #(SpSubBurst) or #(SpSub) */           
             suba.l  #2,a1
             bne.s   RunOnStack1

             move.l  A7,A0
             move.l  A2,A7
             rts
/*******************************************************************************/ 
WRITE:
             move.b  SCIS1,d1
             btst    #6,d1
             beq.s   WRITE
             move.b  d0,SCIDR                 

             rts
/*******************************************************************************/        
READ:
             move.b  SCIS1,d1
             btst    #5,d1
             beq.s   READ
             move.b  SCIDR,d0
        
             rts
/*******************************************************************************/ 
/***************************** ERASE SUBROUTINE ********************************/
/*********** THIS PART OF SOURCE CODE MUST RUNNING IN RAM ***********************/
SpSub:
             move.l  #FSTAT,a4      
             move.b  #mFSTAT_FCBEF,d1 /*   Clear  FCBEF 0x80                 */
             move.b  d1,(a4)          /*   Write: FSTAT register             */
             
loop_1:
             move.l  #FSTAT,a4        /* Read: FSTAT register */
             move.b  (a4),d2
             moveq   #0,d1          
             move.b  d2,d1            /* FCCF Set? */
             andi.l  #mFSTAT_FCCF,d1       
             beq.s   loop_1
               
SpSubEnd:
             rts
/*******************************************************************************/ 
/*********************** FLASH BURST SUBROUTINE ********************************/
/*********** THIS PART OF SOURCE CODE MUST RUNNING IN RAM ***********************/
 
SpSubBurst:
             move.l  d2,a1              /* SOURCE ADDRESS IN D2 */
SpSubBurst1:                            /* LENGTH IN D4, MUST BE MULTIPLE OF 4 */
            
             move.l  (a3),(a1)          /* POINTER TO DATA IN A3 */
       
             moveq   #mBurstProg,d0     /* BURST COMMAND */                               
             move.b  d0,FCMD

             move.l  #FSTAT,a4  
             move.b  #mFSTAT_FCBEF,d1   /* CLEAR FACCER AND FPVIOL */
             move.b  d1,(a4)
loop3:      
             move.b  FSTAT,d0           /* IF COMMAND BUUFER EMPTY FLAG == 0 WAIT */
             btst    #FSTAT_FCBEF,d0
             beq.s   loop3 

             addq.l  #4,a1              /* POINTER TO DESTINATION ADDRESS PLUS FOUR BYTES */
             addq.l  #4,a3              /* POINTER TO SOURCE ADDRESS PLUS FOUR BYTES */
            
             subi.l  #4,d4              /* CHECK LENGTH */
             cmpi.b  #0,d4
             bne.s   SpSubBurst1
            
loop4:       
             move.b  FSTAT,d0                                          
             btst    #FSTAT_FCCF,d0                                          
             beq.s   loop4 


SpSubBurstEnd:

             rts
/*********************************************************************************/
_asm_startmeup_end:       

    .end
    
