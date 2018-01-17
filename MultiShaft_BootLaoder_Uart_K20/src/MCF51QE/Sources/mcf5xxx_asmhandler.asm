/*
 * File:   mcf5xxx_asmhandler.asm
 * Purpose:   asm exception handler for all ColdFire processors.
 *
 * Notes: This file contains the interrupt hanlder for timer 1 channel 1 interrupt   
 *
 */
 
.include "derivative.inc"

.global asm_exception_handler
.global asm_tpm1_ch0_handler

.text
.function "asm_exception_handler",asm_exception_handler,asm_exception_handler_end-asm_exception_handler

/********************************************************************/
/* This routine is the lowest-level exception handler.
/********************************************************************/
asm_exception_handler:
       link    A6,#0 
       lea     -20(sp), SP
       movem.l D0-D2/A0-A1, (SP)
       lea     24(SP),A0   /* A0 point to exception stack frame on the stack */
       movem.l (SP), D0-D2/A0-A1
       lea     20(SP), SP
       unlk    A6
       rte
asm_exception_handler_end:
 
 /********************************************************************/
.function "asm_tpm1_ch0_handler",asm_tpm1_ch0_handler,asm_tpm1_ch0_handler_end-asm_tpm1_ch0_handler

 /********************************************************************/
 /* This routine is the execution handler for Timer 1 Channel 0 interrupt
 /********************************************************************/
asm_tpm1_ch0_handler:
       link    A6,#0 
       lea     -20(SP), SP
       movem.l D0-D2/A0-A1, (SP)
       lea     24(SP),A0       /* A0 point to exception stack frame on the stack */

       move.b  TPM1C0SC,D0
       andi.l  #$7F,D0
       move.b  D0,TPM1C0SC     /* Clear O.C. Flag */

       move.b  TPM1C0VL,D0     /* Setup interrupt in 10ms more */
       addi.l  #$6E,D0
       move.b  D0,TPM1C0VL   
   
       move.b  TPM1C0VH,D0
       addi.l  #$02,D0       
       move.b  D0,TPM1C0VH

check_t1:
       tst     D4
       beq     check_t2             ; Is Timeout 1 currently active?
       subi.l  #$1,D4               ; yes
       bne     check_t2             ; Did it just finish counting down?
       bsr     t1_handler           ; Yes - Execute Timeout 1 handler

check_t2:
       tst     D5
       beq     Check_t3             ; Is Timeout 2 currently active?
       subi.l  #$1,D5               ; yes
       bne     Check_t3             ; Did it just finish counting down?
       jsr     t2_handler           ; Yes - Execute Timeout 2 handler

Check_t3:
       tst     D6
       beq     done_tisr            ; Is Timeout 3 currently active?
       subi.l  #$1,D6               ; yes
       bne     done_tisr            ; Did it just finish counting down?
       jsr     t3_handler           ; Yes - Execute Timeout 3 handler

done_tisr:
       movem.l (SP), D0-D2/A0-A1
       lea     20(sp), SP
       unlk    A6
       rte


/***************************************************************
* Timeout Handlers - All the user has to do is set one of the  *
*                    timeout variables in D4,D5,D6 registers   *
*                    to any number n (1-255)                   *
*                    and the timeout handler will be executed  *
*                    in 10*n milliseconds. Setting the timeout *
*                    variable from within the handler will     *
*                    cause a periodic timeout as shown in      *
*                    timeout 1.                                *
****************************************************************/
t1_handler: 
       
       move.b  PTBD,D0
       eor.l   #$20,D0
       move.b  D0,PTBD
       
       move.b  PTCD,D0
       eor.l   #$3F,D0
       move.b  D0,PTCD
       
       move.b  PTED,D0
       eor.l   #$C0,D0
       move.b  D0,PTED
       
       move.b  #$F,D4     ; Setup next t1_handler event, ~160ms 
       rts

t2_handler:
       rts

t3_handler:
       rts

asm_tpm1_ch0_handler_end:
/********************************************************************/
.end
   
/* This source is (C)opyright 2003, P&E Microcomputer Systems, Inc.
   Visit us at http://www.pemicro.com */   
