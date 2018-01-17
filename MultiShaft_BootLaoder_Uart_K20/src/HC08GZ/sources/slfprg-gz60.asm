;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-gz60.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    GZ60 main bootloader file
;      Platform:       HC08
;      $Version: 6.0.12.0$
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

; label IRQOPTION defined externally, if required:
; IRQOPTION *NOT* defined >> regular version using 8MHz 
; IRQOPTION defined >> regular version using 8MHz and IRQ option
;  (bootloading won't start if IRQ high)
; SIZE = 32, 48 or 60

    include "reg-gz.h"

RCS_ENA    EQU      0        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS        EQU     $80       ; READ COMMAND SUPPORTED
  ELSE
RCS        EQU      0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM    EQU      3        ; FC protocol version number - number 3!


          IF SIZE = 32
FLS_BEG    EQU      $8000   ; FLASH #0 block start
FLS_END    EQU      $FC00   ; FLASH #0 block end
          ELSEIF SIZE = 48
FLS_BEG    EQU      $4000   ; FLASH #0 block start
FLS_END    EQU      $FC00   ; FLASH #0 block end
          ELSEIF SIZE = 60
FLS_BEG    EQU      $1E20   ; FLASH #2 block start
FLS_END    EQU      $FC00   ; FLASH #2 block end
FLS_BEG1   EQU      $0462   ; FLASH #0 block start
FLS_END1   EQU      $0500   ; FLASH #0 block end
FLS_BEG2   EQU      $0980   ; FLASH #1 block start
FLS_END2   EQU      $1B80   ; FLASH #1 block end
          ENDIF

INT_VECT   EQU      $FFCC

IDENTS        MACRO
          IF SIZE = 32
            DC.B     'GZ32'     ; GZ32 string
          ELSEIF SIZE = 48
            DC.B     'GZ48'     ; GZ48 string
          ELSEIF SIZE = 60
            DC.B     'GZ60'     ; GZ60 string
          ENDIF

          IFDEF IRQOPTION
;;            DC.B     '-irq'       ;; text saved in order to fit flash memory
          ENDIF
            DC.B     0
            ENDM


ERBLK_LEN  EQU      128
WRBLK_LEN  EQU      64       

FLBPRMASK  EQU      $8000     ; this is CPU specific FLBPR mask 
                        ; (i.e. bits that are always in the address)
                               
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
            XDEF   VEC23
            XDEF   VEC24
            XDEF   VEC25

            XDEF   FLBPR

T1US        EQU      2    ; 1.25us @ 8MHz
T5US        EQU      10   ; 5.25us
T10US       EQU      20   ; 10.25us
T30US       EQU      60   ; 30.25us
T1MS        EQU      3    ; 1.15ms
T100MS      EQU      0    ; 0 = 256 98ms
   
WR_DATA     EQU      'W'
RD_DATA     EQU      'R'
ENDPRG      EQU      'Q'
ERASE       EQU      'E'
ACK         EQU      $FC
IDENT       EQU      'I'

ILOP      MACRO
          DC.B    $32             ; this is illegal operation code
          ENDM

;*******************************************************************************************
D_MS:   MACRO
        LDA   \1       ; [2] ||  arg > 0, arg=0 <=> arg=256
\@L2:   CLRX           ; [1] ||
\@L1:   PSHA           ; [2] |
        PSHX           ; [2] |
        NOP            ; [1] |
        PULX           ; [2] |
        PULA           ; [2] |
        DBNZX   \@L1   ; [3] |    256*12 = 3072T
        DBNZA   \@L2   ; [3] ||  (3072+4)*arg + 2 T
     ENDM

D_US:   MACRO
        LDA   \1         ; [2]       arg > 0, arg=0 <=> arg=256
\@L1:   NOP              ; [1]
        DBNZA   \@L1   ; [3]      4*arg + 2 T
      ENDM
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

STSRSR:  DS.B   1               ; storage for SRSR reg.
ADRS:    DS.W   1
POM:     DS.B   1
LEN:     DS.B   1
STAT:    DS.B   1
STACK    DS.W   1               ; storage for stack
SOURCE   DS.W   1               ; storage for source address
RFLBPR:  DS.W   1
RFLCR:   DS.W   1

DEFAULT_RAM:    SECTION

PRG:     DS.B   150
DAT:     DS.B   WRBLK_LEN

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRI:    DC.B    0,0,0,0,0,0,0,0 ; 8 bytes reserved for bootloader's private use, not used in ver 3
                        ; kept for compatibility
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
VEC22:  JMP     main            ; vector 22
VEC23:  JMP     main            ; vector 23
VEC24:  JMP     main            ; vector 24
VEC25:  JMP     main            ; vector 25
  
FLB_PROT_ROM:   SECTION
FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection starts MUST CHANGE ACCORING TO MEMORY MAPPING
        
DEFAULT_ROM:   SECTION
     
ID_STRING1:
        DC.B  VER_NUM | RCS   ; version number & "Read command supported" flag
        DC.W   $FFFF                ; SDID (undefined, for HC08s)

      IF (SIZE = 32) || (SIZE = 48)
        DC.B   1                  ; number of Flash blocks
        DC.W   FLS_BEG            ; START ADDRESS OF FLASH   
        DC.W   FLS_END            ; END ADDRESS OF FLASH   

        DC.W   APL_VECT           ; POINTER TO APPLICATION VECTOR TABLE
        DC.W   INT_VECT           ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W   ERBLK_LEN          ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W   WRBLK_LEN          ; WRITE BLCK LENGTH OF FLASH ALG.
      ELSEIF SIZE = 60
        DC.B   3                ; number of Flash blocks
        DC.W   FLS_BEG          ; START ADDRESS OF FLASH   
        DC.W   FLS_END          ; END ADDRESS OF FLASH   
        DC.W   FLS_BEG1         ; START ADDRESS OF FLASH #1
        DC.W   FLS_END1         ; END ADDRESS OF FLASH    #1
        DC.W   FLS_BEG2         ; START ADDRESS OF FLASH #2
        DC.W   FLS_END2         ; END ADDRESS OF FLASH    #2

        DC.W   APL_VECT           ; POINTER TO APPLICATION VECTOR TABLE
        DC.W   INT_VECT           ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W   ERBLK_LEN          ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W   WRBLK_LEN          ; WRITE BLCK LENGTH OF FLASH ALG.
      ENDIF

   IDENTS
ID_STRING1_END:

;*******************************************************************************************
main:   
  IFDEF IRQOPTION
        BIH     PVEC0           ; [for special case - if IRQ high, jump directly to real app.]
  ENDIF
        LDA     SRSR            ; fetch RESET status reg.
        STA     STSRSR          ; store for later re-use
        TSTA                    ; check is zero (this happens if RESET pulse is too short)
        BEQ     slfprg          ; if so, jump to self programming                
        AND     #%10000000      ; mask only POR RESET source      
        BNE     slfprg          ; any of these sources, go to self programming
PVEC0:
        JMP     VEC0            ; any of other sources, jump to real application

slfprg:
      ; CONFIG2 not configured - reset selects SCIBDSRC - SCI clk = BUS clock
        MOV     #%10010001,CONFIG1   ; COP disable
        CLR     PCTL
        MOV     #$02,PCTL       ; P = 0, E = 2
        MOV     #$00,PMSH
        MOV     #$04,PMSL       ; VCO = Xtal * 4 , 32MHz VCO for 8MHz Xtal
        MOV     #$70,PMRS
        BSET    5,PCTL          ; TURN ON PLL
        BSET    7,PBWC          ; PUT IN AUTO BANDWIDTH MODE
LOOP:   
        BRCLR   6,PBWC,LOOP     ; WAIT FOR PLL TO LOCK
        BSET    4,PCTL          ; SELECT CGMVCLK TO DRIVE CGMOUT
    
        BSET    6,SCC1          ; SCI enable
        MOV     #%00001100,SCC2 ; transmit & receive enable
        MOV     #%00110000,SCBR ; 9600Bd @ 8MHz (BUSCLK), /4 /16 /13

        LDA     SCS1
        MOV     #ACK,SCDR

        LDX     #T100MS
L2:     CLRA
L1:     BRSET   5,SCS1,CAUGHT
        DBNZA   L1
        DBNZX   L2

;       timeout
ENDPRG_COM:
        ILOP                   ; generate RESET by doing illegal operation

;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
        BSR     READ
        CMPA    #ACK
        BNE     ENDPRG_COM

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
        STA     ADRS
        BSR     READ
        STA     ADRS+1

        LDHX    #ERASE_ALG      ; LOAD ERASE ALGORITHM TO RAM
        STHX    SOURCE
        MOV     #ERASE_ALG_END-ERASE_ALG,STAT

        BSR     CPY_PRG
        
        BRA     PR_N_GO_RAM      ; prepare FLCR & FLBPR address in RAM and JUMP to PRG then!
;*******************************************************************************************
WR_DATA_COM:

        BSR     READ
        STA     ADRS
        BSR     READ
        STA     ADRS+1
        BSR     READ
        STA     LEN
        STA     STAT
        LDHX    #DAT

WR_DATA_L1:
        BSR     READ
        STA     ,X
        AIX     #1
        DBNZ    STAT,WR_DATA_L1
                              ; START OF SELF-PROGRAMMING
WR_BUF:
        LDHX    #WR_ALG           ; LOAD WRITE ALGORITHM TO RAM
        STHX    SOURCE
        MOV     #WR_ALG_END-WR_ALG,STAT

        BSR     CPY_PRG
   
        TSX
        STHX    STACK         ; copy stack for later re-call

        BRA     PR_N_GO_RAM      ; prepare FLCR & FLBPR address in RAM and JUMP to PRG then!
        
RETWR:
        LDHX    STACK
        TXS                 ; restore stack
        
        JMP     SUCC      
;*******************************************************************************************
PR_N_GO_RAM:
        LDHX    #$8000
        CPHX    ADRS           ; FLASH1/FLASH2 boundary at $8000
            
        BHI     FL2SEL         ; carry set, if 8000 < ADRS (ie. FLASH1, hi)
            
        LDHX    #FL1CR
        STHX    RFLCR
        LDHX    #FL1BPR
        BRA     GORAM
FL2SEL:         
        LDHX    #FL2CR
        STHX    RFLCR
        LDHX    #FL2BPR
GORAM:   
        STHX    RFLBPR
        JMP     PRG              ; jump to RAM program
;*******************************************************************************************
CPY_PRG:
        TSX
        STHX    STACK             ; copy stack for later re-call
            
        LDHX    SOURCE         ; LOAD WRITE ALGORITHM TO RAM
        TXS
        LDHX    #PRG
CPY_PRG_L1:
        PULA
        STA     ,X
        AIX     #1
        DBNZ    STAT,CPY_PRG_L1
        
        LDHX    STACK
        TXS                     ; restore stack
        RTS
;*******************************************************************************************
ERASE_ALG:

        LDA     #%00000010   
        LDHX    RFLCR
        STA     ,X            ; ERASE bit on
        LDHX    RFLBPR
        LDA     ,X            ; dummy read FLBPR

        LDHX    ADRS          ; write anything
        STA     ,X            ; to desired range
        D_US    #T10US        ; wait 10us (tNVS)

        LDA     #%00001010
        LDHX    RFLCR
        STA     ,X             ; ERASE bit on, HVEN bit on
        D_MS    #T1MS          ; wait 1ms (tERASE), modifies X!

        LDA     #%00001000
        LDHX    RFLCR
        STA     ,X             ; ERASE bit off, HVEN bit still on
        D_US    #T5US          ; wait 5us (tNVH)

        STA     ,X             ; all bits off
        D_US    #T1US          ; wait 1us (tRCV)
   
        JMP     SUCC           ; finish with ACK
ERASE_ALG_END:
;*******************************************************************************************
WR_ALG:
        LDA     #%00000001
        LDHX    RFLCR
        STA     ,X              ; PGM bit on
        LDHX    RFLBPR
        LDA     ,X              ; dummy read FLBPR

        LDHX    ADRS          ; prepare address
        STA     ,X              ; and write to desired range
        D_US    #T10US        ; wait 10us (tNVS)

        LDA     #%00001001
        LDHX    RFLCR
        STA     ,X              ; PGM bit on, HVEN bit on
        D_US    #T5US        ; wait 5us (tPGS)

        LDHX    #DAT          ; prepare data
        TXS
        LDHX    ADRS
        MOV     LEN,POM
WR_ALG_L1:
        PULA
        STA     ,X
        AIX     #1
        D_US    #T30US        ; wait 30us (tPROG)
        DBNZ    POM,WR_ALG_L1 ; copy desired block of data

        LDA     #%00001000
        LDHX    RFLCR
        STA     ,X              ; PGM bit off, HVEN bit still on
        D_US    #T5US        ; wait 5us (tNVH)

        STA     ,X              ; HVEN bit off
        D_US    #T1US        ; wait 1us (tRCV)
   
        JMP     RETWR         ; finish with ACK (& restore STACK before)
WR_ALG_END:
;*******************************************************************************************
END            
