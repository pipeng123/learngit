;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-mr32.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    MR main bootloader file
;      Platform:       HC08
;      $Version: 6.0.16.0$
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

; label SIZE defined externally:
; SIZE = 4, 8 or 32 for MR4, MR8 and MR32 respectively

    include "reg-mr32.h"

RCS_ENA       EQU     1           ; READ COMMAND SUPPORTED?

  IFNE RCS_ENA
RCS           EQU     $80         ; READ COMMAND SUPPORTED
  ELSE
RCS           EQU     0           ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM       EQU     1           ; FC protocol version number

APLVECT_LEN   EQU     128         ; newly defined length of new (relocated) application vector page

            IF SIZE = 8
IDENTS        MACRO
              DC.B    'MR8',0
            ENDM

ERBLK_LEN     EQU     64
WRBLK_LEN     EQU     32       
FLS_BEG       EQU     $E000      ; this is start of FLASH memory
FLS_END       EQU     $FC33      ; this is APL_VECT address (also from PRM file)
INT_VECT      EQU     $FFD2      ; this is start of real int. vector table

FLBPRMASK     EQU     $C000      ; this is CPU specific FLBPR mask 
                                 ; (i.e. bits that are always in the address)
            ENDIF
                               
            IF SIZE = 16
IDENTS        MACRO
              DC.B    'MR16',0
            ENDM

ERBLK_LEN     EQU     128
WRBLK_LEN     EQU     64       
FLS_BEG       EQU     $8000       ; this is start of FLASH memory
FLS_END       EQU     $BD33       ; this is APL_VECT address (also from PRM file)
INT_VECT      EQU     $FFD2       ; this is start of real int. vector table

FLBPRMASK     EQU     $8000       ; this is CPU specific FLBPR mask 
                                  ; (i.e. bits that are always in the address)
                                    
              ENDIF

            IF SIZE = 32
IDENTS        MACRO
              DC.B    'MR32',0
            ENDM

ERBLK_LEN     EQU     128
WRBLK_LEN     EQU     64       
FLS_BEG       EQU     $8000       ; this is start of FLASH memory
FLS_END       EQU     $FC33       ; this is APL_VECT address (also from PRM file)
INT_VECT      EQU     $FFD2       ; this is start of real int. vector table

FLBPRMASK     EQU     $8000       ; this is CPU specific FLBPR mask 
                                  ; (i.e. bits that are always in the address)
                                    
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
           XDEF   VEC18
           XDEF   VEC19
           XDEF   VEC20
           XDEF   VEC21
           XDEF   VEC22

T1US        EQU       2
T5US        EQU       10
T10US       EQU       20
T30US       EQU       60
T1MS        EQU       8

T100MS      EQU       255

WR_DATA     EQU       'W'
RD_DATA     EQU       'R'
ENDPRG      EQU       'Q'
ERASE       EQU       'E'
ACK         EQU       $FC
IDENT       EQU       'I'

ILOP        MACRO
            DC.B    $32             ; this is illegal operation code
            ENDM

;*******************************************************************************************
D_MS:   MACRO
        LDA   \1         ; [2] ||
\@L2:   CLRX             ; [1] ||
\@L1:   NOP              ; [1] |
        DBNZX   \@L1     ; [3] |    256*4 = 1024T
        DBNZA   \@L2     ; [3] || (1024+4)*(arg-1) + 2 T
        ENDM

D_US:   MACRO
        LDA   \1         ; [2]
\@L1:   NOP              ; [1]
        DBNZA   \@L1     ; [3] 4*(arg-1) + 2 T
        ENDM
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

ADRS:    DS.W   1
POM:     DS.B   1
LEN:     DS.B   1
STAT:    DS.B   1
STSRSR:  DS.B   1               ; storage for SRSR reg.
STACK    DS.W   1               ; storage for stack
SOURCE   DS.W   1               ; storage for source address

PRG:     DS.B   $50             ; area for running prg. in zero page

DEFAULT_RAM:    SECTION
DAT:     DS.B   WRBLK_LEN       ; prg. data buffer in high RAM now.

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRI:    DC.B    0,$80,0,0,0,0,0,0 ; 8 bytes reserved for bootloader's private use
        
VEC0:   JMP     VEC0            ; vector 0
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
VEC22:  JMP     main            ; vector 22

FLB_PROT_ROM:   SECTION
FLBPR:  DC.B    (FLS_END+APLVECT_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection starts MUST CHANGE ACCORING TO MEMORY MAPPING
DEFAULT_ROM:    SECTION
        
ID_STRING1:
        DC.B   VER_NUM | RCS     ; version number & "Read command supported" flag
        DC.W   FLS_BEG           ; START ADDRESS OF FLASH   
        DC.W   FLS_END           ; END ADDRESS OF FLASH   
        DC.W   APL_VECT          ; POINTER TO APPLICATION VECTOR TABLE
        DC.W   INT_VECT          ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W   ERBLK_LEN         ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W   WRBLK_LEN         ; WRITE BLCK LENGTH OF FLASH ALG.
ID_STRING1_END:

ID_STRING2:
   IDENTS
ID_STRING2_END:

;*******************************************************************************************
main:   
        LDA      SRSR                    ; fetch RESET status reg.
        STA      STSRSR                  ; store for later re-use
        TSTA                             ; check is zero (this happens if RESET pulse is too short)
        BEQ      slfprg                  ; if so, jump to self programming                
        AND      #%10000000              ; mask only POR RESET source      
        BNE      slfprg
        JMP      VEC0                    ; any of other sources, jump to real application

slfprg: MOV      #%00000001,CONFIG       ; COP disable, LVI disable

        MOV      #$80,PBWC            ; set Auto Bandwidth Control
        BCLR     5,PCTL               ; turn PLL off to be able to program multiplier
        MOV      #$87,PPG             ; multiply X-tal frequency by 8 => X-tal=4MHz *8 = 32MHz 
        BSET     5,PCTL               ; turn PLL on
                                      ; bus frequency 32MHz/4 = 8MHz, VCO range = 7
LOOP:   BRCLR    6,PBWC,LOOP           ; wait for PLL lock
        BSET     4,PCTL                  ; use PLL clock
                              
        BSET     6,SCC1                 ; SCI enable
        MOV      #%00001100,SCC2        ; transmit & receive enable
        CLR      SCC3
        MOV      #%00110000,SCBR        ; 9600Bd @ 8MHz BUS

        LDA      SCS1
        MOV      #ACK,SCDR

        LDX      #T100MS
L2:     CLRA
L1:     BRSET    5,SCS1,CAUGHT
        DBNZA    L1
        DBNZX    L2

;       timeout
ENDPRG_COM:
        ILOP          ; generate RESET by doing illegal operation

;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
        BSR      READ
        CMPA     #ACK
        BNE      ENDPRG_COM

;*******************************************************************************************
; successful return from all write routines
SUCC:
        LDA      #ACK
        BSR      WRITE

;fall thru to background
;*******************************************************************************************
; BEGIN OF BACKGROUND COMMAND LOOP
BCKGND:
        BSR      READ
        
        CBEQA    #ERASE, ERASE_COM       ; Erase command
        CBEQA    #WR_DATA, WR_DATA_COM   ; Write (program) command
        CBEQA    #IDENT, IDENT_COM       ; Ident command
      IF RCS_ENA = 1
        CBEQA    #RD_DATA, RD_DATA_COM   ; Read command
      ENDIF

        ; if no valid command found (including Quit)
        ; generate reset too!
        ILOP          ; generate RESET by doing illegal operation
        
;*******************************************************************************************
IDENT_COM:                      ; TRANSFER OF IDENTIFICATION STRING
        MOV      #ID_STRING1_END-ID_STRING1, LEN
        LDHX     #ID_STRING1
        BSR      WRITE_LOOP

        LDA      STSRSR          ; first byte will be SRSR reg.
        BSR      WRITE
        
        LDHX     #PRI+1           ; next 7 are from private area
        MOV      #7,LEN
        BSR      WRITE_LOOP
        
        MOV      #ID_STRING2_END-ID_STRING2, LEN
        LDHX     #ID_STRING2
        BSR      WRITE_LOOP

        BRA      BCKGND          ; finish without ACK
      
;*******************************************************************************************
WRITE_LOOP:                   ; start address in HX, length in LEN
        LDA      ,X
        BSR      WRITE
        AIX      #1
        DBNZ     LEN, WRITE_LOOP
        RTS
;*******************************************************************************************
      IF RCS_ENA = 1
RD_DATA_COM:

        BSR      READ
        STA      ADRS
        BSR      READ
        STA      ADRS+1
        BSR      READ
        STA      LEN
        LDHX     ADRS
        
        BSR      WRITE_LOOP

        BRA      BCKGND             ; finish without ACK
      ENDIF
;*******************************************************************************************
READ:
        BRCLR    5,SCS1,READ
        LDA      SCDR
        RTS

WRITE:   
        BRCLR    6,SCS1,WRITE
        STA      SCDR
        RTS
;*******************************************************************************************
ERASE_COM:

        BSR      READ
        STA      ADRS
        BSR      READ
        STA      ADRS+1

        LDHX     #ERASE_ALG      ; LOAD ERASE ALGORITHM TO RAM
        STHX     SOURCE
        MOV      #ERASE_ALG_END-ERASE_ALG,STAT

        BSR      CPY_PRG
        
        JMP      PRG            ; ERASE BLOCK 
;*******************************************************************************************
WR_DATA_COM:
        BSR      READ
        STA      ADRS
        BSR      READ
        STA      ADRS+1
        BSR      READ
        STA      LEN
        STA      STAT
        LDHX     #DAT

WR_DATA_L1:
        BSR      READ
        STA      ,X
        AIX      #1
        DBNZ     STAT,WR_DATA_L1
                        ; START OF SELF-PROGRAMMING
WR_BUF:
        LDHX     #WR_ALG         ; LOAD WRITE ALGORITHM TO RAM
        STHX     SOURCE
        MOV      #WR_ALG_END-WR_ALG,STAT

        BSR      CPY_PRG
        TSX
        STHX     STACK           ; copy stack for later re-call
        JMP      PRG   
        
RETWR:  LDHX     STACK
        TXS                     ; restore stack
        
        JMP      SUCC      
;*******************************************************************************************
CPY_PRG:
        TSX
        STHX     STACK           ; copy stack for later re-call
        
        LDHX     SOURCE          ; LOAD WRITE ALGORITHM TO RAM
        TXS
        LDHX     #PRG
CPY_PRG_L1:
        PULA
        STA      ,X
        AIX      #1
        DBNZ     STAT,CPY_PRG_L1
        
        LDHX     STACK
        TXS                     ; restore stack
        RTS
;*******************************************************************************************
ERASE_ALG:

        LDA      #%00000010   
        STA      FLCR           ; ERASE bit on
        LDA      FLBPR          ; dummy read FLBPR

        LDHX     ADRS           ; write anything
        STA      ,X             ; to desired range
        D_US     #T10US         ; wait 10us

        LDA      #%00001010
        STA      FLCR           ; set HVEN, keep ERASE
        D_MS     #T1MS          ; wait 1ms

        LDA      #%00001000
        STA      FLCR           ; keep HVEN, ERASE off
        D_US     #T5US          ; wait 5us

        CLRA
        STA      FLCR           ; HVEN off
        D_US     #T1US          ; wait 1us
       
        JMP      SUCC           ; finish with ACK
ERASE_ALG_END:
;*******************************************************************************************
WR_ALG:
        LDA      #%00000001
        STA      FLCR            ; PGM bit on
        LDA      FLBPR           ; dummy read FLBPR

        LDHX     ADRS            ; prepare addrs'
        STA      ,X              ; and write to desired range
        D_US     #T10US          ; wait 10us

        LDA      #%00001001
        STA      FLCR            ; set HVEN, keep PGM
        D_US     #T5US           ; wait 5us

        LDHX     #DAT            ; prepare addrs'
        TXS
        LDHX     ADRS
        MOV      LEN,POM
WR_ALG_L1:
        PULA
        STA      ,X
        AIX      #1
        D_US     #T30US          ; wait 30us
        DBNZ     POM,WR_ALG_L1   ; copy desired block of data
       
        LDA      #%00001000
        STA      FLCR            ; keep HVEN, PGM off
        D_US     #T5US           ; wait 5us

        CLRA
        STA      FLCR            ; HVEN off
        D_US     #T1US           ; wait 1us
       
        JMP      RETWR           ; finish with ACK (& restore STACK before)
WR_ALG_END:
;*******************************************************************************************
END            
