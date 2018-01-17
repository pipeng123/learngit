;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-gr.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    GR4/8/8A/16 main bootloader file
;      Platform:       HC08
;      $Version: 6.0.28.0$
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

; labels VERSION, SIZE and IRQOPTION defined externally:
; VERSION = 1 >> regular version using 32768Hz Xtal
; VERSION = 2 >> version using external clock (this actual version uses 11.052 MHz)
;                for other clk freq. SCI settings must be modified too!
; !!! THIS VERSION USES 57600Bd since 9600 Bd can't be derived out of 11.052 MHz clock
; VERSION = 3 >> GR8A/GR4A regular version using 8MHz Xtal
; VERSION = 4 >> GR8A/GR4A regular version using 7.37MHz Xtal
; VERSION = 5 >> GR8A/GR4A regular version using 7.2MHz Xtal
;
; SIZE = 4, 8, 16 depending whether GR4 or GR8 (or 16) is required
; IRQOPTION *NOT* defined >> regular version using Xtal
; IRQOPTION defined >> regular version using Xtal and IRQ option (bootloading won't start if IRQ high)
;
; HIGHSPEED defined >> highest possible baudrate, now version 4 and 5 only, 38400Bd
; LVICOP defined >> (currently only for VERSION = 3, 4 and 5), COP servicing is done, LVI enabled for 3.3V


    include "reg-gp32.h"

RCS_ENA     EQU     0        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS         EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU     1        ; FC protocol version number

IDENTS      MACRO
          IF SIZE = 4
            DC.B     'GR4'      ; GR4 string
          ENDIF
          IF SIZE = 8
            DC.B     'GR8'      ; GR8 string
          ENDIF
          IF SIZE = 16
            DC.B     'GR16'     ; GR16 string
          ENDIF

          IF VERSION = 1
            DC.B     '-XR'      ; Xtal 32768 reqd., ROM used 
          ENDIF

          IF VERSION = 2
            DC.B     '-R-ext'   ; external clock, ROM used
          ENDIF

          IF (VERSION = 3) || (VERSION = 4) || (VERSION = 5)
            DC.B     'A-XR'      ; external clock, ROM used
          ENDIF

          IFDEF IRQOPTION
            DC.B     '-irq'     ; IRQ option used
          ENDIF

            DC.B    0
            ENDM

ERBLK_LEN   EQU      64
WRBLK_LEN   EQU      32       

          IF SIZE = 4
FLS_BEG      EQU      $EE00   ; 4kB FLASH
          ENDIF
          IF SIZE = 8
FLS_BEG      EQU      $E000   ; 8kB FLASH
          ENDIF
          IF SIZE = 16
FLS_BEG      EQU      $C000   ; 16kB FLASH
          ENDIF

FLS_END      EQU      $FCC0   ; this is APL_VECT address (also from PRM file)
INT_VECT     EQU      $FFDC

FLBPRMASK    EQU      $C000   ; this is CPU specific FLBPR mask    
                     ;(i.e. bits that are always in the address)

   IF (SIZE = 4) || (SIZE = 8)
GETBYTE      EQU      $1C99
RDVRRNG      EQU      $1CAD
ERARNGE      EQU      $1DA0
PRGRNGE      EQU      $1CEC
DELNUS       EQU      $1D96
   ELSEIF (SIZE = 16)
GETBYTE      EQU      $1C00
RDVRRNG      EQU      $1C03
ERARNGE      EQU      $1C06
PRGRNGE      EQU      $1C09
DELNUS       EQU      $1C0C
   ENDIF   

RAMSTART     EQU      $40
CTRLBYT      EQU      RAMSTART+$08
CPUSPD       EQU      RAMSTART+$09
LADDR        EQU      RAMSTART+$0A
DATA         EQU      RAMSTART+$0C

   IF (SIZE = 4) || (SIZE = 8)
              IF VERSION = 1            ; Xtal 32768Hz + PLL (to 3.6864MHz)
SPEED           EQU     15          ; 4 x f(op) [MHz]
              ENDIF
   
              IF VERSION = 2             ; external 11.052MHz CAN
SPEED           EQU     11          ; 4 x f(op) [MHz]
              ENDIF

          IF (VERSION = 3)          ; Xtal 8MHz + PLL (4MHz BUS)
SPEED           EQU     16          ; 4 x f(op) [MHz]
              ENDIF

          IF (VERSION = 4) || (VERSION = 5)  ; Xtal 7.2(7.37)MHz + PLL (3.6MHz BUS)
SPEED           EQU     15          ; 4 x f(op) [MHz]
              ENDIF

   ELSEIF SIZE = 16
              IF (VERSION = 1) || (VERSION = 2) 
SPEED           EQU     8           ; 2 x f(op) [MHz] / for GR16 only!
              ENDIF
   ENDIF

;*******************************************************************************************

   XDEF   main
   XDEF   VEC1
   XDEF   VEC2
   XDEF   VEC3
   XDEF   VEC4
   XDEF   VEC5
   XDEF   VEC6
   XDEF   VEC7
   XDEF   VEC8
   XDEF   VEC9
   XDEF   VEC10
   XDEF   VEC11
   XDEF   VEC12
   XDEF   VEC13
   XDEF   VEC14
   XDEF   VEC15
   XDEF   VEC16
   XDEF   VEC17

WR_DATA     EQU       'W'
RD_DATA     EQU       'R'
ENDPRG      EQU       'Q'
ERASE       EQU       'E'
ACK         EQU       $FC
IDENT       EQU       'I'

T100MS      EQU       128

ILOP        MACRO
            DC.B    $32             ; this is illegal operation code
            ENDM
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

ADRS:   DS.W     1
LEN:    DS.B     1
STAT:   DS.B     1
STSRSR: DS.B     1               ; storage for SRSR reg.

DEFAULT_RAM:    SECTION

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRI:    DC.B    0,$80,0,0,0,0,0,0 ; 8 bytes reserved for bootloader's private use
        
VEC0:   JMP     main            ; vector 0
VEC1:   JMP     main            ; vector 1
VEC2:   JMP     main            ; vector 2
VEC3:   JMP     main            ; vector 3
VEC4:   JMP     main            ; vector 4
VEC5:   JMP     main            ; vector 5
VEC6:   JMP     main            ; vector 6
VEC7:   JMP     main            ; vector 7
VEC8:   JMP     main            ; vector 8
VEC9:   JMP     main            ; vector 9
VEC10:  JMP     main            ; vector 10
VEC11:  JMP     main            ; vector 11
VEC12:  JMP     main            ; vector 12
VEC13:  JMP     main            ; vector 13
VEC14:  JMP     main            ; vector 14
VEC15:  JMP     main            ; vector 15
VEC16:  JMP     main            ; vector 16
VEC17:  JMP     main            ; vector 17

FLB_PROT_ROM:   SECTION
FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection starts MUST CHANGE ACCORING TO MEMORY MAPPING
        
DEFAULT_ROM:    SECTION
        
ID_STRING1:
        DC.B    VER_NUM | RCS    ; version number & "Read command supported" flag
        DC.W    FLS_BEG          ; START ADDRESS OF FLASH   
        DC.W    FLS_END          ; END ADDRESS OF FLASH   
        DC.W    APL_VECT         ; POINTER TO APPLICATION VECTOR TABLE
        DC.W    INT_VECT         ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W    ERBLK_LEN        ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W    WRBLK_LEN        ; WRITE BLCK LENGTH OF FLASH ALG.
ID_STRING1_END:

ID_STRING2:
   IDENTS
ID_STRING2_END:

;*******************************************************************************************
main:   
      IF (VERSION = 1) || (VERSION = 2) ; non-A GR version
        MOV     #$1C, $0033             ; set up unused timer channel, right after reset
      ENDIF
        
      IFDEF IRQOPTION
        BIH     VEC0                    ; [for special case - if IRQ high, jump directly to real app.]
      ENDIF
        LDA     SRSR                    ; fetch RESET status reg.
        STA     STSRSR                  ; store for later re-use
        TSTA                            ; check is zero (this happens if RESET pulse is too short)
        BEQ     slfprg                  ; if so, jump to self programming                
        AND     #%10000000              ; mask only POR RESET source      
        BEQ     VEC0                    ; any of these sources, go to self programming

      IF VERSION = 1
slfprg: MOV     #%00000001,CONFIG2
        MOV     #%10010001,CONFIG1
        CLR     PCTL
        BSET    0,PCTL          ; P = 0, E = 1
        MOV     #$01,PMSH
        MOV     #$C0,PMSL       ; 3.6864 MHz
        MOV     #$C0,PMRS
        MOV     #$01,PMDS
        BSET    5,PCTL          ; TURN ON PLL
        BSET    7,PBWC          ; PUT IN AUTO BANDWIDTH MODE
LOOP:   BRCLR   6,PBWC,LOOP     ; WAIT FOR PLL TO LOCK
        BSET    4,PCTL          ; SELECT CGMVCLK TO DRIVE CGMOUT

        BSET    6,SCC1          ; SCI enable
        MOV     #%00001100,SCC2 ; transmit & receive enable
        CLR     SCC3
        MOV     #%00010001,SCBR ; 9600Bd @ 3.68MHz
      ENDIF

      IF VERSION = 2            ; external clock settings
slfprg: MOV     #%00000000,CONFIG2      ; external clk used as a SCI clock source
        MOV     #%00010001,CONFIG1      ; LVIPWRDisable, COPDisable

        BSET    6,SCC1                  ; SCI enable
        MOV     #%00001100,SCC2         ; transmit & receive enable
        CLR     SCC3
        MOV     #%00010000,SCBR          ; 57600Bd @ 11.05927 MHz
      ENDIF

    IF (VERSION = 3) || (VERSION = 4) || (VERSION = 5)
slfprg: CLR     CONFIG2              ; SCI clk = Xtal clk

      IFDEF LVICOP
        MOV     #%10000000, CONFIG1  ; LVI enabled for 3.3V, COP enabled & short timeout
      ELSE
        MOV     #%10010001, CONFIG1  ; COP disabled & LVI disabled
      ENDIF

        CLR     PCTL                 ; clear PCTL first
        MOV     #%00000001, PCTL     ; P = 0, E = 1

        CLR     PMSH
        MOV     #2,PMSL         ; 16MHz fVCLK (N = 2), 2*8MHz (2*7.2MHz), BUS 4MHz (3.6MHz), suitable also for 3V systems
        MOV     #1,PMDS            ; R = 1

      IF (VERSION = 3)          ; 8MHz
        MOV     #208,PMRS          ; L = 208 (for E=1) = 16MHz (fVclk) = (208 * 2^1) * 38400 (fNOM)
       ENDIF

      IF (VERSION = 4)          ; 7.2MHz
        MOV     #188,PMRS          ; L = 188 (for E=1) = 14.4000MHz (fVclk) = (188 * 2^1) * 38400 (fNOM)
       ENDIF
     
      IF (VERSION = 5)          ; 7.37MHz
        MOV     #192,PMRS          ; L = 192 (for E=1) = 14.7456MHz (fVclk) = (192 * 2^1) * 38400 (fNOM)
       ENDIF
     
        BSET    7,PBWC          ; PUT IN AUTO BANDWIDTH MODE first
        BSET    5,PCTL          ; TURN ON PLL
LOOP:   BRCLR   6,PBWC,LOOP     ; WAIT FOR PLL TO LOCK
        BSET    4,PCTL          ; SELECT CGMVCLK TO DRIVE CGMOUT

        BSET    6,SCC1          ; SCI enable
        MOV     #%00001100,SCC2 ; transmit & receive enable
        CLR     SCC3

      IF (VERSION = 3)
       IFDEF HIGHSPEED
        'ERROR -- not possible to have 38400Bd with 8MHz Xtal clock driving SCI module
      ELSE
        MOV     #%00110000,SCBR ; 9600Bd @ 8MHz (PD=13 BD=1)
       ENDIF
       ENDIF

      IF (VERSION = 4) || (VERSION = 5)
       IFDEF HIGHSPEED
        MOV     #%00010000,SCBR ; 38400Bd @ 7.2(7.37)MHz (PD=3 BD=1) 37500Hz (2.3% off 38400) for 7.2MHz, 7.37MHz is sharp
      ELSE
        MOV     #%00010010,SCBR ; 9600Bd @ 7.2(7.37)MHz (PD=3 BD=4)   9375Hz (2.3% off  9600) for 7.2MHz, 7.37MHz is sharp
       ENDIF
       ENDIF

    ENDIF

        LDA     SCS1
        MOV     #ACK,SCDR

        LDX     #T100MS
L2:     CLRA
L1:     BRSET   5,SCS1,CAUGHT
    IFDEF LVICOP
        STA     COPCTL
    ENDIF
        DBNZA   L1
        DBNZX   L2

;       timeout
ENDPRG_COM:
        ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
        BSR     READ
        CMPA    #ACK
        BNE     ENDPRG_COM
      
        MOV     #SPEED,CPUSPD   ; feed the speed
        BCLR    6,CTRLBYT       ; no mass erase      

;*******************************************************************************************
; successful return from all write routines
SUCC:
        LDA     #ACK
        BSR     WRITE

;fall thru to background
;*******************************************************************************************
; BEGIN OF BACKGROUND COMMAND LOOP
BCKGND:
        BSR     READ
           
        CBEQA   #ERASE, ERASE_COM       ; Erase command
        CBEQA   #WR_DATA, WR_DATA_COM   ; Write (program) command
        CBEQA   #IDENT, IDENT_COM       ; Ident command
      IF RCS_ENA = 1
        CBEQA   #RD_DATA, RD_DATA_COM   ; Read command
      ENDIF

        ; if no valid command found (including Quit)
        ; generate reset too!
        ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************
IDENT_COM:                      ; TRANSFER OF IDENTIFICATION STRING
        MOV     #ID_STRING1_END-ID_STRING1, LEN
        LDHX    #ID_STRING1
        BSR     WRITE_LOOP

        LDA     STSRSR          ; first byte will be SRSR reg.
        BSR     WRITE
        
        LDHX    #PRI+1           ; next 6 are from private area
        MOV     #6,LEN
        BSR     WRITE_LOOP

        LDA     FLBPR
        BSR     WRITE           ; last byte would be FLBPR, just for info
              
        MOV     #ID_STRING2_END-ID_STRING2, LEN
        LDHX    #ID_STRING2
        BSR     WRITE_LOOP

        BRA     BCKGND          ; finish without ACK
;*******************************************************************************************
WRITE_LOOP:                   ; start address in HX, length in LEN
        LDA     ,X
        BSR     WRITE
        AIX     #1
        DBNZ    LEN, WRITE_LOOP
        RTS
;*******************************************************************************************
      IF RCS_ENA = 1
RD_DATA_COM:

        BSR     READ
        STA     ADRS
        BSR     READ
        STA     ADRS+1
        BSR     READ
        STA     LEN
        LDHX    ADRS
        
        BSR     WRITE_LOOP

        BRA     BCKGND          ; finish without ACK
      ENDIF
;*******************************************************************************************
READ:
    IFDEF LVICOP
        STA     COPCTL
    ENDIF
        BRCLR   5,SCS1,READ
        LDA     SCDR
        RTS

WRITE:   
    IFDEF LVICOP
        STA     COPCTL
    ENDIF
        BRCLR   6,SCS1,WRITE
        STA     SCDR
        RTS
;*******************************************************************************************
ERASE_COM:
        BSR     READ
        PSHA
        PULH                    ; store to H:x
        BSR     READ
        TAX                     ; store to h:X
        JSR     ERARNGE         ; call ROM erase routine

        BRA     SUCC            ; refer status back to PC
;*******************************************************************************************
WR_DATA_COM:
        BSR     READ
        STA     ADRS
        BSR     READ
        STA     ADRS+1
        BSR     READ
        STA     STAT
        DECA
        STA     LEN
        LDHX    #DATA
WR_DATA_L1:
        BSR     READ
        STA     ,X
        AIX     #1
        DBNZ    STAT,WR_DATA_L1
                        ; START OF SELF-PROGRAMMING
        LDA     ADRS+1
        ADD     LEN
        STA     LADDR+1
        LDA     ADRS
        ADC     #0
        STA     LADDR
        LDHX    ADRS
                                
        JSR     PRGRNGE         ; call ROM erase routine
        
        JMP     SUCC          ; refer status back to PC
;*******************************************************************************************
END            
