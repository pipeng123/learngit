/**********************************************************************
* HEADER_START
*
* @file      main.c
* @version   1.0.18.0
* @date      Jun-24-2009
* @author    B20253
*
* @brief     MCF51EM main bootloader file
*
* =================================================================== 
* Copyright (c):       FREESCALE Inc., 2010, All rights reserved.     
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
/* label HISPEED => if defined, 19200Bd is used instead of 9600Bd */

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

  .IF(SCI == 1)                      /*  definition SCI_1 */
SCIBDH       .EQU SCI1BDH
SCIBDL       .EQU SCI1BDL
SCIC1        .EQU SCI1C1
SCIC2        .EQU SCI1C2
SCIC3        .EQU SCI1C3
SCIS1        .EQU SCI1S1
SCIDR        .EQU SCI1D
 
RXDPORT      .EQU PTBD
RXDBIT       .EQU PTBD_PTBD2

.ENDIF
 
  .IF(SCI == 2)                      /* definition SCI_2 */
SCIBDH       .EQU SCI2BDH
SCIBDL       .EQU SCI2BDL
SCIC1        .EQU SCI2C1
SCIC2        .EQU SCI2C2
SCIC3        .EQU SCI2C3
SCIS1        .EQU SCI2S1
SCIDR        .EQU SCI2D

RXDPORT      .EQU PTBD
RXDBIT       .EQU PTBD_PTBD0

 .ENDIF
 
  .IF(SCI == 3)                      /* definition SCI_3 */
SCIBDH       .EQU SCI3BDH
SCIBDL       .EQU SCI3BDL
SCIC1        .EQU SCI3C1
SCIC2        .EQU SCI3C2
SCIC3        .EQU SCI3C3
SCIS1        .EQU SCI3S1
SCIDR        .EQU SCI3D

RXDPORT      .EQU PTCD
RXDBIT       .EQU PTCD_PTCD0

 .ENDIF

/********************************************************************************/
  
DATA:        .DS.B   256
TMPSTOR:     .DS.B   12

REDIR:       .EQU    0x3F4         /* INIT_PC, INIT_SP and NVTRIM values stored here */

PROT_VER     .EQU    0x84          /* PROTOCOL VERSION - READ COMMAND IMPLEMENTED */

WR_DATA:     .EQU    "W"           /* WRITE COMMAND */
RD_DATA:     .EQU    "R"           /* READ  COMMAND */
ERASE:       .EQU    "E"           /* ERASE COMMAND */
IDENT1:      .EQU    "I"           /* IDENT COMMAND */
QUIT_DATA:   .EQU    "Q"
 
ACK:         .EQU    0xFC          /* ACKNOWLEDGE */


.section  code
.text

/********************************************************************************/
  IDENT:                                 /* IDENT STRING BEGIN */

   NFLBLKS:           .DC.L   0x2        /* NUMBER OF FLASH BLOCKS */
   FLS_BEG1:          .DC.L   0x0        /* FLASH START ADDRESS */
   FLS_END1:          .DC.L   0x3F3      /* FLASH END ADDRESS */
  .IF(SIZE==128) 
   FLS_BEG2:          .DC.L   0x400      /* FLASH START ADDRESS */
   FLS_END2:          .DC.L   0x1FBFF    /* FLASH END ADDRESS */
  .ELSEIF(SIZE==256) 
   FLS_BEG2:          .DC.L   0x400      /* FLASH START ADDRESS */
   FLS_END2:          .DC.L   0x3F7FF    /* FLASH END ADDRESS */
  .ENDIF
   REL_VECT:          .DC.L   0x0        /* RELOCATED VECTOR TABLE  */
   INT_VECT:          .DC.L   0x0        /* INTERRUPTS VECTOR TABLE */
   ERBLK_LEN:         .DC.L   1024       /* ERASE BLOCK LENGTH */
   WRBLK_LEN:         .DC.L   128        /* WRITE BLOCK LENGTH */

   IDENTSTR:          .DC.B   "MCF51EM"
     .IF(SIZE==128)
                      .DC.B   "128"
FLASHARRAYEND:      .EQU    0xFFFF
     .ELSEIF(SIZE==256) 
                      .DC.B   "256"
FLASHARRAYEND:      .EQU    0x1FFFF
     .ELSE
                      .DC.B   "ERROR"
   .ENDIF

   ZERO:              .DC.W   0
  IDENT_END:                         /* IDENT STRING END */

/********************************************************************************/
 _asm_startmeup:
  
             move.w  #0x2700,SR  
             lea     __SP_INIT,A7
             
/********************************************************************************/        
_main:
             move.b  SRS,d0           /* fetch RESET status reg. */
             btst    #4,d0
             beq.s   INIT_CLOCK

USERRUN:             
             move.l  REDIR,a7        /* restore user code SP */

             move.l  REDIR+4,a0      /* jump to user code */
             jmp     (a0)
INIT_CLOCK:
             clr.b   SOPT1             /* watchdog disabled */

             moveq   #0,d6            /* zero page flag */

             move.b  #0xFF, d1
             move.b  d1,TMPSTOR+8     /* dummy */
             move.b  d1,TMPSTOR+9

             move.b  NV1FTRIM,d1
             move.b  d1,TMPSTOR+10
             
             move.b  NV1ICSTRM,d1
             move.b  d1,TMPSTOR+11      

             move.b  #0x80,d1
             move.b  d1,ICSTRM
             
/****************************************************************************************/             
             move.b  #%00000100,d0         /*CLKS=00;RDIV=000;IREFS=1;IRCLKLEN=0;IREFSTEN=0*/
             move.b  d0,ICSC1         
             move.b  #%00000000,d0         /*BDIV=00;RANGE=0;HGO=0,LP=0;EREFS=0;ERCLKLEN=0;EREFSTEN=0*/
             move.b  d0,ICSC2         
             move.b  #%10010000,d0         /*DRS=10;DMX32=0;IREFST=1;CLKST=0;OSCINIT=0;FTRIM1=0*/ 
             move.b  d0,ICSSC
                                         
/****************************************************************************************/
INIT_SCI:    
            .IF(SCI==1)                     // initialize SCI1 (RX1&TX1)
             move.b  PTBPF2,d0
             ori.l   #0xF0,d0         
             move.b  d0,PTBPF2
            
            .ELSEIF(SCI==2)                 // initialize SCI2 (RX2&TX2)
             move.b  PTBPF2,d0
             ori.l   #0x0F,d0
             move.b  d0,PTBPF2
            
            .ELSEIF(SCI==3)                 // initialize SCI3 (RX3&TX3)
             move.b  PTCPF2,d0
             ori.l   #0x0F,d0
             move.b  d0,PTCPF2
            .ENDIF
           
             clr.b   SCIBDH           
             
           .IFNDEF HIGHSPEED
             move.b  #156,d0           /* 9600  Baud rate   */
             move.b  d0,SCIBDL
           .ELSE
             
             move.b  #78,d0            /* 19200 Baud rate   */
             move.b  d0,SCIBDL
           .ENDIF 
       
             clr.b   SCIC1
             
             moveq   #0x0C,d0         /* transmit & receive enable */
             move.b  d0,SCIC2
                                    
             clr.b   SCIC3            /* clear byte SCIC3 */
                                  
             moveq   #%01001110,d0    /* set up flash clock */
             move.b  d0,F1CDIV        /* 24MHz/200kHz = 120; PRDIV8=1, FDIV=14 */
             move.b  d0,F2CDIV        /* 24MHz/200kHz = 120; PRDIV8=1, FDIV=14 */
/****************************************************************************************/
 loop:       move.b  #ACK,d0
             bsr     WRITE            /* send acknowledge to master */
            
             move.l  #0x0,d3
             move.l  #0x1FFFFFF,d3

L1:          move.b  SCIS1,d1
             btst    #5,d1
             bne.s   CAUGHT

             subi.l  #1,d3
             cmpi    #0,d3
             
             bne.s   L1
             move.b  d0,SCIC2
             bra     ILOP               /* generate RESET by doing illegal operation */
/*********************************************************************************/
CAUGHT:   
             BSR     READ
             jsr     TRIMING
             bra     SUCC
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

             bra     BCKGND
ILOP:
             stop    #0                   ;ILOP
/********************************************************************************/        
BURST_RESET: 
             tst     d6                 /* test D6 zero page flag */
             beq.s   ILOP               /* if zero page not modified, jump to ILOP */
                         
             moveq   #2,d6              /* make sure BURST will go to ILOP instead */

             moveq   #0,d3              /*  DUE TO FIRST PAGE OF APP RESET VALUE */
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
             move.l  d1,d6
             
             cmpi.l  #FLASHARRAYEND,d6
             bgt.s   SEC_ROUT
                              
             move.l  #(SpSubEnd),a1
             move.l  #(SpSub),a6
             bra     RUNONSTACK
             
SEC_ROUT:    move.l  #(SpSubEnd2),a1
             move.l  #(SpSub2),a6
          
RUNONSTACK:  bsr     RunOnStack

             move.l  a0,a1                  /* SET UP FACCER A FPVIOL FLAG TO 1 */
           
             cmpi.l  #FLASHARRAYEND,d6

             bgt.s   SECOND_BLOCK

FIRST_BLOCK: /*THIS IS FIRST BLOCK OF FLASH MEMORY for EM128 (0x410-0xFFFF) and for EM256 (0x410-0x1FFFF)*/          
             move.b  #(mF1STAT_FACCERR+mF1STAT_FPVIOL),d0
             move.b  d0,F1STAT
             
             move.l  d1,a0                 
             move.l  #0xFF,(a0)            
             
             moveq   #mPageErase,d0        
             move.b  d0,F1CMD              
             bra     JMP_STACK
      
SECOND_BLOCK: /*THIS IS SECOND BLOCK OF FLASH MEMORY for EM128 (0xFFFF-1FFFF) and for EM256 (0x1FFFF-0x3FFFF)*/ 
             moveq   #(mF2STAT_FACCERR+mF2STAT_FPVIOL),d0
             move.b  d0,F2STAT
 
             move.l  d1,a0                 
             move.l  #0xFF,(a0)            
            
             moveq   #mPageErase,d0        
             move.b  d0,F2CMD              
JMP_STACK:
             jsr     (A1)                   /*JUMP TO STACK ON DOONSTACK ROUTINE */
             bra     SUCC                   /* SEND ACKNOWLEDGE */
                     
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
             move.l  d0,d3
             bsr     READ
             
             move.b  d0,d4                /* TBD */
             move.b  d0,d3
             
             move.l  #DATA,a3

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
           
             move.l  #DATA,a3            /* source address */

BURST:       
             cmpi.l  #FLASHARRAYEND,d3
             bgt.s   SEC_ROUT2
                              
TMP:         move.l  #(SpSubBurstEnd),a1
             move.l  #(SpSubBurst),a6
             bra     DOONSTACK2
             
SEC_ROUT2:   
             move.l  #(SpSubBurstEnd2),a1
             move.l  #(SpSubBurst2),a6


DOONSTACK2:  bsr     RunOnStack
         
             cmpi.l  #FLASHARRAYEND,d3
             bgt.s   SECOND_BLOCK2

FIRST_BLOCK2:
             move.l  a0,a1
             move.b  #(mF1STAT_FCCF + mF1STAT_FCBEF),d0
             move.b  d0,F1STAT
             bra     JMP_STACK2
SECOND_BLOCK2:
             move.l  a0,a1
             move.b  #(mF2STAT_FCCF + mF2STAT_FCBEF),d0
             move.b  d0,F2STAT
JMP_STACK2:
             jsr     (A1)
             cmpi.b  #2,d3               /* compare zero page flag */
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
/*********** THIS PART OF SOURCE CODE MUST RUN IN RAM **************************/
SpSub:
             move.b  #mF1STAT_FCBEF,d1          /*   Clear  FCBEF 0x80             */
             move.b  d1,(F1STAT)                /*   Write: FSTAT register         */
loop_1:
             move.l  #F1STAT,a4                 /* Read: FSTAT register            */
             move.b  (a4),d2
             moveq   #0,d1          
             move.b  d2,d1                      /* FCCF Set? */
             andi.l  #0x40,d1       
             beq.s   loop_1
SpSubEnd:
             rts
/*********************************/ 
SpSub2:
             move.b  #mF2STAT_FCBEF,d1          /*   Clear  FCBEF 0x80             */
             move.b  d1,(F2STAT)                /*   Write: FSTAT register         */
loop_2:
             move.l  #F2STAT,a4                 /* Read: FSTAT register            */
             move.b  (a4),d2
             moveq   #0,d1          
             move.b  d2,d1                      /* FCCF Set? */
             andi.l  #0x40,d1       
             beq.s   loop_2
SpSubEnd2:
             rts
/*********************************************TRIM********************************************/
TRIMING:
             clr     d0 
             clr     d1
             move.l  #0x00000000,d2
MONRXD:
             move.b  RXDPORT,d0           //IF COMMAND == 0 WAIT 
             btst    #RXDBIT,d0
             bne.s   MONRXD 
CHKRXD:
             addi.l  #1,d2

             move.l  #25,d3
CHKRXD2:     subi.l  #1,d3
             bne.s   CHKRXD2

             move.b  RXDPORT,d0            // 2100 / 21 = 100
             btst    #RXDBIT,d0
             beq     CHKRXD
           
           .IFDEF HIGHSPEED
             lsl.l   #1,d2
           .ENDIF
           
BRKDONE:
             move.l  #183,d3
             subx.l  d3,d2

             move.b d2,ICSTRM

OOR:         
             rts         
                          
/*********************************************************************************/

_asm_startmeup_end:       
/*******************************************************************************/ 
/*********************** FLASH BURST SUBROUTINE ********************************/
/*********** THIS PART OF SOURCE CODE MUST RUNNING IN RAM ***********************/
SpSubBurst:
             move.l  d2,a1               /* SOURCE ADDRESS IN D2 */
SpSubBurst1:                             /* LENGTH IN D4, MUST BE MULTIPLE OF 4 */
loop3:      
             move.b  F1STAT,d0           /* IF COMMAND BUUFER EMPTY FLAG == 0 WAIT */
             btst    #F1STAT_FCBEF,d0
             beq.s   loop3 
            
             move.l  (a3),(a1)          /* POINTER TO DATA IN A3 */
       
             moveq   #mBurstProg,d0     /* BURST COMMAND */                               
             move.b  d0,F1CMD

             move.b  #mF1STAT_FCBEF,d1   /* CLEAR FACCER AND FPVIOL */
             move.b  d1,(F1STAT)

             addq.l  #4,a1               /* POINTER TO DESTINATION ADDRESS PLUS FOUR BYTES */
             addq.l  #4,a3               /* POINTER TO SOURCE ADDRESS PLUS FOUR BYTES */
            
             subi.l  #4,d4               /* CHECK LENGTH */
             cmpi.b  #0,d4
             bne.s   SpSubBurst1
loop4:       
             move.b  F1STAT,d0                                          
             btst    #F1STAT_FCCF,d0                                          
             beq.s   loop4 
SpSubBurstEnd:
             rts
/********************************************************************************/             
SpSubBurst2:
             move.l  d2,a1               /* SOURCE ADDRESS IN D2 */
SpSubBurst0:                             /* LENGTH IN D4, MUST BE MULTIPLE OF 4 */
loop5:      
             move.b  F2STAT,d0           /* IF COMMAND BUUFER EMPTY FLAG == 0 WAIT */
             btst    #F2STAT_FCBEF,d0
             beq.s   loop5 
            
             move.l  (a3),(a1)           /* POINTER TO DATA IN A3 */
       
             moveq   #mBurstProg,d0      /* BURST COMMAND */                               
             move.b  d0,F2CMD

             move.b  #mF2STAT_FCBEF,d1   /* CLEAR FACCER AND FPVIOL */
             move.b  d1,(F2STAT)

             addq.l  #4,a1               /* POINTER TO DESTINATION ADDRESS PLUS FOUR BYTES */
             addq.l  #4,a3               /* POINTER TO SOURCE ADDRESS PLUS FOUR BYTES */
            
             subi.l  #4,d4               /* CHECK LENGTH */
             cmpi.b  #0,d4
             bne.s   SpSubBurst0
loop6:       
             move.b  F2STAT,d0                                          
             btst    #F2STAT_FCCF,d0                                          
             beq.s   loop6 
SpSubBurstEnd2:
             rts
    .end
