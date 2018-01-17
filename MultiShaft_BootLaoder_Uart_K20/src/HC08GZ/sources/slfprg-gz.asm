;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-gz.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    GZ main bootloader file
;      Platform:       HC08
;      $Version: 6.0.8.0$
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

; labels SIZE and IRQOPTION defined externally:
;
; SIZE = 8, 16 depending whether GZ8 or GZ16 is required
; IRQOPTION *NOT* defined >> regular version using 8MHz xtal
; IRQOPTION defined >> regular version using 8MHz xtal and IRQ option (bootloading won't start if IRQ high)


    include "reg-gz.h"

RCS_ENA     EQU     0        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS         EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU     1        ; FC protocol version number


IDENTS      MACRO
          IF SIZE = 8
            DC.B     'GZ8'      ; GZ8 string
          ELSEIF SIZE = 16
            DC.B     'GZ16'     ; GZ16 string
          ENDIF

          IFDEF IRQOPTION
            DC.B     '-irq'     ; IRQ option used
          ENDIF

            DC.B    0
            ENDM

ERBLK_LEN   EQU     64
WRBLK_LEN   EQU     32       

          IF SIZE = 8
FLS_BEG     EQU     $E000   ; 8kB FLASH
          ELSEIF SIZE = 16
FLS_BEG     EQU     $C000   ; 16kB FLASH
          ENDIF

FLS_END     EQU     $FC80   ; this is APL_VECT address (also from PRM file)
INT_VECT    EQU     $FFD4

FLBPRMASK   EQU     $C000   ; this is CPU specific FLBPR mask    
                     ;(i.e. bits that are always in the address)

; 1. Bus Speed Limitation
; The GR/GZ16 Flash routines embedded in ROM support a bus speed higher or equal to 2MHz
 
GETBYTE     EQU     $1C00
RDVRRNG     EQU     $1C03
ERARNGE     EQU     $1C06
PRGRNGE     EQU     $1C09
DELNUS      EQU     $1C0C

RAMSTART    EQU     $40
CTRLBYT     EQU     RAMSTART+$08
CPUSPD      EQU     RAMSTART+$09
LADDR       EQU     RAMSTART+$0A
DATA        EQU     RAMSTART+$0C

SPEED       EQU     16           ; 2 x f(op) [MHz] / for GZ!

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
            XDEF   VEC18
            XDEF   VEC19
            XDEF   VEC20
            XDEF   VEC21

            XDEF    FLBPR

WR_DATA EQU       'W'
RD_DATA EQU       'R'
ENDPRG  EQU       'Q'
ERASE   EQU       'E'
ACK     EQU       $FC
IDENT   EQU       'I'

T100MS  EQU       128

ILOP    MACRO
        DC.B    $32             ; this is illegal operation code
        ENDM
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

STSRSR: DS.B   1               ; storage for SRSR reg.
ADRS:   DS.W   1
LEN:    DS.B   1
STAT:   DS.B   1

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
VEC18:  JMP     main            ; vector 18
VEC19:  JMP     main            ; vector 19
VEC20:  JMP     main            ; vector 20
VEC21:  JMP     main            ; vector 21

APL_LEN         EQU      (8+3*($10000-INT_VECT)/2)            ; all int. vectors + JMPs + 8 private files
APLVECT_LEN     EQU      (((APL_LEN-1)/ERBLK_LEN)+1)*ERBLK_LEN   ; newly defined length of new (relocated) application vector page

FLB_PROT_ROM:   SECTION
FLBPR:  DC.B    (FLS_END+APLVECT_LEN-FLBPRMASK)/ERBLK_LEN   ; FLASH protection starts MUST CHANGE ACCORING TO MEMORY MAPPING
DEFAULT_ROM:    SECTION
        
ID_STRING1:
        DC.B    VER_NUM | RCS ; version number & "Read command supported" flag
        DC.W    FLS_BEG       ; START ADDRESS OF FLASH   
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
      IFDEF IRQOPTION
        BIH     PVEC0                   ; [for special case - if IRQ high, jump directly to real app.]
      ENDIF
        LDA     SRSR                    ; fetch RESET status reg.
        STA     STSRSR                  ; store for later re-use
        TSTA                            ; check is zero (this happens if RESET pulse is too short)
        BEQ     slfprg                  ; if so, jump to self programming                
        AND     #%10000000              ; mask only POR RESET source      
        BNE     slfprg                  ; any of these sources, go to self programming
PVEC0:  JMP     VEC0

slfprg: MOV     #%00000001,CONFIG2
        MOV     #%10010001,CONFIG1

        CLR     PCTL
        MOV     #$02,PCTL       ; P = 0, E = 2
        MOV     #$00,PMSH
        MOV     #$04,PMSL       ; VCO = Xtal * 4 MHz
        MOV     #$70,PMRS
        BSET    5,PCTL          ; TURN ON PLL
        BSET    7,PBWC          ; PUT IN AUTO BANDWIDTH MODE
LOOP:   BRCLR   6,PBWC,LOOP     ; WAIT FOR PLL TO LOCK
        BSET    4,PCTL          ; SELECT CGMVCLK TO DRIVE CGMOUT

        BSET    6,SCC1          ; SCI enable
        MOV     #%00001100,SCC2 ; transmit & receive enable
        CLR     SCC3
        MOV     #%00110000,SCBR ; 9600Bd @ 8MHz (BUS clk = SCI clk)

        LDA     SCS1
        MOV     #ACK,SCDR

        LDX     #T100MS
L2:     CLRA
L1:     BRSET   5,SCS1,CAUGHT
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

        LDHX    #PRI           ; next 8 are from private area
        MOV     #8,LEN
        BSR     WRITE_LOOP
              
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
        BRCLR   5,SCS1,READ
        LDA     SCDR
        RTS

WRITE:   
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
