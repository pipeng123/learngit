;*********************************************************************
; HEADER_START
;
;        $File Name: REG-MR32.H$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    MR header file (may not be complete)
;      Platform:       HC08
;      $Version: 6.0.4.0$
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

PTA    equ   $0000      ;port A
PTB    equ   $0001      ;port B
PTC    equ   $0002      ;port C
PTD    equ   $0003      ;port D
PTE    equ   $0008      ;port E
PTF    equ   $0009      ;port F

DDRA   equ   $0004      ;port A data direction reg.
DDRB   equ   $0005      ;port B data direction reg.
DDRC   equ   $0006      ;port C data direction reg.
DDRD   equ   $0007      ;port D data direction reg.
DDRE   equ   $000C      ;port E data direction reg.
DDRF   equ   $000D      ;port F data direction reg.

;PTAPUE   equ   $000D      ;port A pull-up enable
;PTCPUE   equ   $000E      ;port C pull-up enable
;PTDPUE   equ   $000F      ;port D pull-up enable

;***********************
; SPI SECTION
;***********************

SPCR   equ   $0044      ;SPI ctrl reg
SPSCR  equ   $0045      ;SPI stat reg
SPDR   equ   $0046      ;SPI data reg

;***********************
; SCI SECTION
;***********************

SCC1   equ   $0038      ;SCI ctrl reg 1
SCC2   equ   $0039      ;SCI ctrl reg 2
SCC3   equ   $003A      ;SCI ctrl reg 3
SCS1   equ   $003B      ;SCI stat reg 1
SCS2   equ   $003C      ;SCI stat reg 2
SCDR   equ   $003D      ;SCI data reg
SCBR   equ   $003E      ;SCI baudrate reg


;***********************
; KEYBOARD SECTION
;***********************

INTKBSCR equ   $001a      ;KBD stat & ctrl reg
INTKBIER equ   $001b      ;KBD int. enable


;***********************
; TIME BASE SECTION
;***********************

TBCR     equ   $001c      ;TB ctrl reg


;***********************
; INTERRUPT SECTION
;***********************

INTSCR   equ   $003f      ;IRQ stat & ctrl reg


;***********************
; CONFIG SECTION
;***********************

CONFIG   equ   $001f      ;config reg


;***********************
; TIMER #1 SECTION
;***********************

T1SC     equ   $0020      ;TMR stat & ctrl reg
T1CNTH   equ   $0021      ;TMR hi
T1CNTL   equ   $0022      ;TMR lo
T1MODH   equ   $0023      ;TMR modulo hi
T1MODL   equ   $0024      ;TMR modulo lo
T1SC0    equ   $0025      ;TMR ch0 stat & ctrl reg
T1CH0H   equ   $0026      ;TMC ch0 reg hi
T1CH0L   equ   $0027      ;TMC ch0 reg lo
T1SC1    equ   $0028      ;TMR ch1 stat & ctrl reg
T1CH1H   equ   $0029      ;TMC ch1 reg hi
T1CH1L   equ   $002a      ;TMC ch1 reg lo

;***********************
; TIMER #2 SECTION
;***********************

T2SC     equ   $0051      ;TMR stat & ctrl reg
T2CNTH   equ   $0052      ;TMR hi
T2CNTL   equ   $0053      ;TMR lo
T2MODH   equ   $0054      ;TMR modulo hi
T2MODL   equ   $0055      ;TMR modulo lo
T2SC0    equ   $0056      ;TMR ch0 stat & ctrl reg
T2CH0H   equ   $0057      ;TMC ch0 reg hi
T2CH0L   equ   $0058      ;TMC ch0 reg lo
T2SC1    equ   $0059      ;TMR ch1 stat & ctrl reg
T2CH1H   equ   $005A      ;TMC ch1 reg hi
T2CH1L   equ   $005B      ;TMC ch1 reg lo


;***********************
; CLOCK SECTION
;***********************

PCTL   equ   $005C      ;PLL ctrl reg
PBWC   equ   $005D      ;PLL B/W reg
PPG    equ   $005E      ;PLL programming reg


;***********************
; A/D SECTION
;***********************

ADSCR  equ   $0040      ;AD ctrl & stat reg
ADRH   equ   $0041      ;AD data reg
ADRL   equ   $0042      ;AD data reg
ADCLK  equ   $0043      ;AD clk reg


;***********************
; TEST, SIM SECTION
;***********************

SBSR   equ   $fe00      ;BREAK STATUS REG
SRSR   equ   $fe01      ;SIM RESET STAT REG
SBFCR  equ   $fe03      ;Break Flag Control Register

BRKH   equ   $fe0c      ;Break Address Registers
BRKL   equ   $fe0d      ;Break Address Registers
BRKSCR equ   $fe0e      ;Break Status & Control Register

;INT1  equ   $fe04      ;Interrupt stat reg 1
;INT2  equ   $fe05      ;Interrupt stat reg 2
;INT3  equ   $fe06      ;Interrupt stat reg 3

;***********************
; FLASH SECTION
;***********************

FLCR   equ   $fe08      ;FLASH ctrl reg
;FLBPR equ   $ff7e      ;FLASH blk protection reg

LVISR  equ   $fe0f      ;LVI stat reg

COPCTL equ   $ffff      ;COP ctrl reg

   ENDIF
   END
