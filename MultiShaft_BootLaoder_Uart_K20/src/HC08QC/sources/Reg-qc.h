;*********************************************************************
; HEADER_START
;
;        $File Name: Reg-qc.h$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    QB/QC header file (not complete!)
;      Platform:       HC08
;      $Version: 6.0.3.0$
;      $Date: Oct-11-2011$ 
;      $Last Modified By: B20253$
;      Company:        Freescale Semiconductor
;      Security:       General Business
;
; =================================================================== 
; Copyright (c):      Freescale Semiconductor, 2004, All rights reserved.
;
; =================================================================== 
; THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY
; EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
; PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL FREESCALE OR
; ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
; NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
; STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
; ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
; OF THE POSSIBILITY OF SUCH DAMAGE.
; ===================================================================
;
; HEADER_END

   ifndef   _REG_H
_REG_H   equ   1

;***********************
; PORTS SECTION
;***********************

PTA      equ   $0000      ;port A
PTB      equ   $0001      ;port B

DDRA     equ   $0004      ;port A data direction reg.
DDRB     equ   $0005      ;port B data direction reg.

PTAPUE   equ   $000B      ;port A pull-up enable
PTBPUE   equ   $000C      ;port B pull-up enable


;***********************
; SCI SECTION
;***********************

SCC1     equ   $0010      ;SCI ctrl reg 1
SCC2     equ   $0011      ;SCI ctrl reg 2
SCC3     equ   $0012      ;SCI ctrl reg 3
SCS1     equ   $0013      ;SCI stat reg 1
SCS2     equ   $0014      ;SCI stat reg 2
SCDR     equ   $0015      ;SCI data reg
SCBR     equ   $0016      ;SCI baudrate reg
SCPSC    equ   $0017      ;ESCI baudrate prescaler reg
SCIACTL  equ   $0018      ;ESCI arbiter ctl
SCIADAT  equ   $0019      ;ESCI arbiter data


;***********************
; KEYBOARD SECTION
;***********************

KBSR     equ   $001a      ;KBD stat & ctrl reg
KBIER    equ   $001b      ;KBD int. enable



;***********************
; INTERRUPT SECTION
;***********************

INTSCR   equ   $001d      ;IRQ stat & ctrl reg


;***********************
; CONFIG SECTION
;***********************

CONFIG2  equ   $001e      ;config reg 2
CONFIG1  equ   $001f      ;config reg 1


;***********************
; TIMER SECTION
;***********************

TSC      equ   $0020      ;TMR stat & ctrl reg
TCNTH    equ   $0021      ;TMR hi
TCNTL    equ   $0022      ;TMR lo
TMODH    equ   $0023      ;TMR modulo hi
TMODL    equ   $0024      ;TMR modulo lo
TSC0     equ   $0025      ;TMR ch0 stat & ctrl reg
TCH0H    equ   $0026      ;TMC ch0 reg hi
TCH0L    equ   $0027      ;TMC ch0 reg lo
TSC1     equ   $0028      ;TMR ch1 stat & ctrl reg
TCH1H    equ   $0029      ;TMC ch1 reg hi
TCH1L    equ   $002a      ;TMC ch1 reg lo


;***********************
; A/D SECTION
;***********************

ADSCR    equ   $003c      ;AD ctrl & stat reg
ADR      equ   $003e      ;AD data reg
ADCLK    equ   $003f      ;AD clk reg


;***********************
; CLOCK SECTION
;***********************

OSCSC    equ   $0036      ;ICG stat & ctrl reg
OSCTRIM  equ   $0038      ;ICG trim reg

;***********************
; TEST, SIM SECTION
;***********************

SRSR   equ   $fe01      ;SIM RESET STAT REG

INT1   equ   $fe04      ;Interrupt stat reg 1
INT2   equ   $fe05      ;Interrupt stat reg 2
INT3   equ   $fe06      ;Interrupt stat reg 3

FLCR   equ   $fe08      ;FLASH ctrl reg

LVISR  equ   $fe0c      ;LVI stat reg

OSCTRIMF equ   $FFC0       ; this is where manufacturer value is stored

;FLBPR   equ   $ffbe      ;FLASH blk protection reg
COPCTL   equ   $ffff      ;COP ctrl reg

   ENDIF
   END
