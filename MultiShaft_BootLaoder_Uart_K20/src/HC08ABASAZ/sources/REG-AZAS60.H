;*********************************************************************
; HEADER_START
;
;        $File Name: REG-AZAS60.H$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    AZ/AS60 header file (incomplete!)
;      Platform:       HC08
;      $Version: 6.0.6.0$
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
; SCI SECTION
;***********************

SCC1   equ   $0013      ;SCI ctrl reg 1
SCC2   equ   $0014      ;SCI ctrl reg 2
SCC3   equ   $0015      ;SCI ctrl reg 3
SCS1   equ   $0016      ;SCI stat reg 1
SCS2   equ   $0017      ;SCI stat reg 2
SCDR   equ   $0018      ;SCI data reg
SCBR   equ   $0019      ;SCI baudrate reg


;***********************
; CONFIG SECTION
;***********************

CONFIG2   equ   $fe09      ;config reg 2
CONFIG1   equ   $001f      ;config reg 1


;***********************
; CLOCK SECTION
;***********************

PCTL    equ   $001c      ;PLL ctrl reg
PBWC    equ   $001d      ;PLL B/W reg
PPG     equ   $001e      ;PLL mult reg


;***********************
; TEST, SIM SECTION
;***********************

SBSR    equ   $fe00      ;BREAK STATUS REG
SRSR    equ   $fe01      ;SIM RESET STAT REG
SBFCR   equ   $fe03      ;Break Flag Control Register

BRKH    equ   $fe0c      ;Break Address Registers
BRKL    equ   $fe0d      ;Break Address Registers
BRKSCR  equ   $fe0e      ;Break Status & Control Register

;***********************
; EEPROM SECTION
;***********************

EE1DIVHNVR   equ   $fe10   ;NonVolatile
EE1DIVLNVR   equ   $fe11   ;NonVolatile
EE1DIVH      equ   $fe1a
EE1DIVL      equ   $fe1b
EE1NVR       equ   $fe1c   ;NonVolatile
EE1CR        equ   $fe1d
EE1ACR       equ   $fe1f

EE2DIVHNVR   equ   $ff70   ;NonVolatile
EE2DIVLNVR   equ   $ff71   ;NonVolatile
EE2DIVH      equ   $ff7a
EE2DIVL      equ   $ff7b
EE2NVR       equ   $ff7c   ;NonVolatile
EE2CR        equ   $ff7d
EE2ACR       equ   $fff7

;***********************
; FLASH SECTION
;***********************

FL1CR    equ   $ff88      ;FLASH1 ctrl reg
FL2CR    equ   $fe08      ;FLASH2 ctrl reg
FL1BPR   equ   $ff80      ;FLASH1 blk protection reg
FL2BPR   equ   $ff81      ;FLASH2 blk protection reg

LVISR    equ   $fe0f      ;LVI stat reg

COPCTL   equ   $ffff      ;COP ctrl reg

   ENDIF
   END
