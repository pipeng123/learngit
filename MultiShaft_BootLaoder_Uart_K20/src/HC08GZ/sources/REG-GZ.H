;*********************************************************************
; HEADER_START
;
;        $File Name: REG-GZ.H$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    GZ header file
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

PTA      equ   $0000      ;port A
PTB      equ   $0001      ;port B
PTC      equ   $0002      ;port C
PTD      equ   $0003      ;port D
PTE      equ   $0008      ;port E

DDRA     equ   $0004      ;port A data direction reg.
DDRB     equ   $0005      ;port B data direction reg.
DDRC     equ   $0006      ;port C data direction reg.
DDRD     equ   $0007      ;port D data direction reg.
DDRE     equ   $000C      ;port E data direction reg.

PTAPUE   equ   $000D      ;port A pull-up enable
PTCPUE   equ   $000E      ;port C pull-up enable
PTDPUE   equ   $000F      ;port D pull-up enable

;***********************
; SPI SECTION
;***********************

SPCR    equ   $0010      ;SPI ctrl reg
SPSCR   equ   $0011      ;SPI stat reg
SPDR    equ   $0012      ;SPI data reg

;***********************
; ESCI SECTION
;***********************

SCPSC    equ   $0009      ;ESCI prescaler
SCIACTL  equ   $000a      ;ESCI arbiter ctrl
SCIADAT  equ   $000b      ;ESCI arbiter data
SCC1     equ   $0013      ;SCI ctrl reg 1
SCC2     equ   $0014      ;SCI ctrl reg 2
SCC3     equ   $0015      ;SCI ctrl reg 3
SCS1     equ   $0016      ;SCI stat reg 1
SCS2     equ   $0017      ;SCI stat reg 2
SCDR     equ   $0018      ;SCI data reg
SCBR     equ   $0019      ;SCI baudrate reg


;***********************
; KEYBOARD SECTION
;***********************

INTKBSCR   equ   $001a      ;KBD stat & ctrl reg
INTKBIER   equ   $001b      ;KBD int. enable


;***********************
; TIME BASE SECTION
;***********************

TBCR     equ   $001c      ;TB ctrl reg


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
; TIMER #1 SECTION
;***********************

T1SC    equ   $0020      ;TMR stat & ctrl reg
T1CNTH  equ   $0021      ;TMR hi
T1CNTL  equ   $0022      ;TMR lo
T1MODH  equ   $0023      ;TMR modulo hi
T1MODL  equ   $0024      ;TMR modulo lo
T1SC0   equ   $0025      ;TMR ch0 stat & ctrl reg
T1CH0H  equ   $0026      ;TMC ch0 reg hi
T1CH0L  equ   $0027      ;TMC ch0 reg lo
T1SC1   equ   $0028      ;TMR ch1 stat & ctrl reg
T1CH1H  equ   $0029      ;TMC ch1 reg hi
T1CH1L  equ   $002a      ;TMC ch1 reg lo

;***********************
; TIMER #2 SECTION
;***********************

T2SC    equ   $002b      ;TMR stat & ctrl reg
T2CNTH  equ   $002c      ;TMR hi
T2CNTL  equ   $002d      ;TMR lo
T2MODH  equ   $002e      ;TMR modulo hi
T2MODL  equ   $002f      ;TMR modulo lo
T2SC0   equ   $0030      ;TMR ch0 stat & ctrl reg
T2CH0H  equ   $0031      ;TMC ch0 reg hi
T2CH0L  equ   $0032      ;TMC ch0 reg lo
T2SC1   equ   $0033      ;TMR ch1 stat & ctrl reg
T2CH1H  equ   $0034      ;TMC ch1 reg hi
T2CH1L  equ   $0035      ;TMC ch1 reg lo


;***********************
; CLOCK SECTION
;***********************

PCTL   equ   $0036      ;PLL ctrl reg
PBWC   equ   $0037      ;PLL B/W reg
PMSH   equ   $0038      ;PLL mult hi reg
PMSL   equ   $0039      ;PLL mult lo reg
PMRS   equ   $003a      ;PLL VCO sel. range reg


;***********************
; A/D SECTION
;***********************

ADSCR  equ   $003c      ;AD ctrl & stat reg
ADRH   equ   $003d      ;AD data reg hi
ADRL   equ   $003e      ;AD data reg lo
ADCLK  equ   $003f      ;AD clk reg


;***********************
; TEST, SIM SECTION
;***********************

SBSR   equ   $fe00      ;BREAK STATUS REG
SRSR   equ   $fe01      ;SIM RESET STAT REG
SUBAR  equ   $fe02      ;SIM Upper Byte Address Register
SBFCR  equ   $fe03      ;Break Flag Control Register

BRKH   equ   $fe09      ;Break Address Registers
BRKL   equ   $fe0a      ;Break Address Registers
BRKSCR equ   $fe0b      ;Break Status & Control Register

INT1   equ   $fe04      ;Interrupt stat reg 1
INT2   equ   $fe05      ;Interrupt stat reg 2
INT3   equ   $fe06      ;Interrupt stat reg 3

;***********************
; FLASH SECTION
;***********************

;GZ8/16 defs
FLCR     equ   $fe08      ;FLASH ctrl reg
;FLBPR   equ   $ff7e      ;FLASH blk protection reg

;GZ60 defs
FL1CR    equ   $ff88      ;FLASH1 ctrl reg
FL2CR    equ   $fe08      ;FLASH2 ctrl reg
FL1BPR   equ   $ff80      ;FLASH1 blk protection reg
FL2BPR   equ   $ff81      ;FLASH2 blk protection reg


LVISR    equ   $fe0c      ;LVI stat reg

COPCTL   equ   $ffff      ;COP ctrl reg

   ENDIF
   END
