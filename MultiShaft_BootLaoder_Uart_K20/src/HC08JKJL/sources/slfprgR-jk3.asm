;*********************************************************************
; HEADER_START
;
;        $File Name: slfprgR-jk3.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    JK/JL main bootloader file
;      Platform:       HC08
;      $Version: 6.0.23.0$
;      $Date: Oct-10-2011$ 
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

    include "reg-jk3.h"

RCS_ENA         EQU     0           ; READ COMMAND SUPPORTED?

  IFNE RCS_ENA
RCS             EQU     $80         ; READ COMMAND SUPPORTED
  ELSE
RCS             EQU     0           ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM         EQU     1           ; FC protocol version number


ERBLK_LEN       EQU     64
WRBLK_LEN       EQU     32       

FLS_END         EQU     $FA80       ; this is APL_VECT address (also from PRM file)
INT_VECT        EQU     $FFDC

FLBPRMASK       EQU     $E000       ; this is CPU specific FLBPR mask (i.e. bits that are always in the address)

ROMSTART        EQU     $FC00

GETBYTE         EQU     ROMSTART+0
RDVRRNG         EQU     ROMSTART+3
ERARNGE         EQU     ROMSTART+6
PRGRNGE         EQU     ROMSTART+9
DELNUS          EQU     ROMSTART+12

RAMSTART        EQU     $80
CTRLBYT         EQU     RAMSTART+$08
CPUSPD          EQU     RAMSTART+$09
LADDR           EQU     RAMSTART+$0A
DATA            EQU     RAMSTART+$0C

Jx1_FLS_BEG     EQU     $F600       ; flash start for Jx1
Jx3_FLS_BEG     EQU     $EC00       ; flash start for Jx3


;**************************************************************************

            IF PLATFORM = 1
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK3 used

IDENTS          MACRO
                DC.B    'J3',0       ; soft SCI
                ENDM

TXDPORT         EQU     PTD           ; <<<
TXDPIN          EQU     4             ; <<<
SCITXINV        EQU     0             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     0             ; (if RXD uses IRQ pin instead)

RXDPORT         EQU     PTD           ; <<<
RXDPIN          EQU     5             ; <<<

RXDPUEN         EQU     1             ; use pull-up feature

BUSCLOCK        EQU     1228800       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     9600

CALENABLED      EQU     1             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     6            ; specify Xtal clk in MHz if no calibration (known freq.)
              ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 2
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK3 used

IDENTS          MACRO
                DC.B     'J3',0       ; soft SCI
                ENDM

TXDPORT         EQU     PTD           ; <<<
TXDPIN          EQU     5             ; <<<
SCITXINV        EQU     1             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     1             ; (if RXD uses IRQ pin instead)

RXDPUEN         EQU     0             ; undefine pull-up enabling port             

BUSCLOCK        EQU     1228800       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     9600

CALENABLED      EQU     1             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     6             ; specify Xtal clk in MHz if no calibration (known freq.)
              ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 3
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK3 used

IDENTS          MACRO
                DC.B     'J3',0       ; soft SCI
                ENDM

TXDPORT         EQU     PTD           ; <<<
TXDPIN          EQU     5             ; <<<
SCITXINV        EQU     1             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     1             ; (if RXD uses IRQ pin instead)

RXDPUEN         EQU     0             ; don't use pull-up feature

BUSCLOCK        EQU     4000000       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     19200

CALENABLED      EQU     0             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     16            ; specify BUS*4 clk in MHz if no calibration (known freq.)
              ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 4
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK3 used

IDENTS          MACRO
                DC.B    'J3',0       ; soft SCI
                ENDM

TXDPORT         EQU     PTD           ; <<<
TXDPIN          EQU     6             ; <<<
SCITXINV        EQU     1             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     1             ; (if RXD uses IRQ pin instead)

RXDPUEN         EQU     0             ; undefine pull-up enabling port             

BUSCLOCK        EQU     4000000       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     19200

CALENABLED      EQU     0             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     16            ; specify BUS*4 clk in MHz if no calibration (known freq.)
              ENDIF

            ENDIF
            
;**************************************************************************

            IF PLATFORM = 5
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK3 used

IDENTS          MACRO
                DC.B    'J3',0       ; soft SCI
                ENDM

TXDPORT         EQU     PTD           ; <<<
TXDPIN          EQU     1             ; <<<
SCITXINV        EQU     0             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     0             ; (if RXD uses IRQ pin instead)
              IF RXDISIRQ = 0         ; RXDPORT & RXDPIN is defined
RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     4             ; <<<
RXDPUEN         EQU     1             ; use pull-up feature
              ENDIF

BUSCLOCK        EQU     2000000       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     9600

CALENABLED      EQU     1             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     10            ; specify Xtal clk in MHz if no calibration (known freq.)
              ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 6
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK1 used

IDENTS          MACRO
                DC.B    'J3',0       ; soft SCI
                ENDM

TXDPORT         EQU     PTB           ; <<<
TXDPIN          EQU     4             ; <<<
SCITXINV        EQU     0             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     0             ; (if RXD uses IRQ pin instead)
              IF RXDISIRQ = 0         ; RXDPORT & RXDPIN is defined
RXDPORT         EQU     PTB           ; <<<
RXDPIN          EQU     3             ; <<<
RXDPUEN         EQU     0             ; use pull-up feature
              ENDIF
              
BUSCLOCK        EQU     2000000       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     9600

CALENABLED      EQU     1             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     10            ; specify Xtal clk in MHz if no calibration (known freq.)
              ENDIF
            ENDIF

;**************************************************************************

            IF PLATFORM = 7
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK1 used

IDENTS          MACRO
                DC.B    'J3',0       ; soft SCI
                ENDM

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     1             ; <<<
SCITXINV        EQU     0             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     0             ; (if RXD uses IRQ pin instead)
              IF RXDISIRQ = 0         ; RXDPORT & RXDPIN is defined
RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     0             ; <<<
RXDPUEN         EQU     1             ; use pull-up feature
              ENDIF
              
BUSCLOCK        EQU     2000000       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     9600

CALENABLED      EQU     1             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     10            ; specify Xtal clk in MHz if no calibration (known freq.)
              ENDIF
            ENDIF

;**************************************************************************

            IF PLATFORM = 8
FLS_BEG         EQU     Jx3_FLS_BEG     ; JK1 used

IDENTS          MACRO
                DC.B    'J3',0        ; soft SCI
                ENDM

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     1             ; <<<
SCITXINV        EQU     0             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))
RXDISIRQ        EQU     0             ; (if RXD uses IRQ pin instead)
              IF RXDISIRQ = 0         ; RXDPORT & RXDPIN is defined
RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     1             ; <<<
RXDPUEN         EQU     1             ; use pull-up feature
              ENDIF
              
BUSCLOCK        EQU     2000000       ; <<< MODIFY SO IT IS NEAR YOUR BUS CLOCK!
SCISPEED        EQU     9600

CALENABLED      EQU     1             ; calibration enabled 

              IF CALENABLED = 0
SPEED           EQU     10            ; specify Xtal clk in MHz if no calibration (known freq.)
              ENDIF
            ENDIF

;**************************************************************************
;**************************************************************************

          IF RXDISIRQ = 1           ; RXDPORT & RXDPIN is *not* defined
            IF SCIRXINV = 1            
CONFIG2DEF      EQU     %10000000     ; pullup on IRQ disabled!   you need hardwired pull-down in fact!
            ELSE
CONFIG2DEF      EQU     %00000000     ; pullup on IRQ enabled!              
            ENDIF
          ELSE
CONFIG2DEF      EQU     %00000000     ; pullup on IRQ *not* disabled!              
RXDDDR          EQU     RXDPORT+4
            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF
          ENDIF

TXDDDR          EQU     TXDPORT+4
   
SCITXTICK       EQU     (BUSCLOCK/SCISPEED)

;**************************************************************************
   IF RXDISIRQ = 0         ; RXDPORT & RXDPIN is defined
    IF (RXDPORT = TXDPORT) & (RXDPIN = TXDPIN)
SINGLEWIRE      EQU     1             ; do use single-wire feature
    ELSE
SINGLEWIRE      EQU     0             ; do NOT use single-wire feature
    ENDIF    
   ELSE
SINGLEWIRE      EQU     0             ; do NOT use single-wire feature
   ENDIF
;*******************************************************************************************

    XDEF    main
    XDEF    VEC1
    XDEF    VEC2
    XDEF    VEC3
    XDEF    VEC4
    XDEF    VEC5
    XDEF    VEC6
    XDEF    VEC7
    XDEF    VEC8
    XDEF    VEC9
    XDEF    VEC10
    XDEF    VEC11
    XDEF    VEC12
    XDEF    VEC13
    XDEF    VEC14
    XDEF    VEC15
    XDEF    VEC16

    XDEF    SCIAPIREF       
    XDEF    FLBPR           

WR_DATA     EQU     'W'
RD_DATA     EQU     'R'
ENDPRG      EQU     'Q'
ERASE       EQU     'E'
ACK         EQU     $FC
IDENT       EQU     'I'

T100MS      EQU     255

ILOP        MACRO
            DC.B    $32             ; this is illegal operation code
            ENDM

SKIP1       MACRO
            DC.B    $21             ; BRANCH NEVER (saves memory)
            ENDM

SKIP2       MACRO
            DC.B    $65             ; CPHX (saves memory)
            ENDM

BRRXDLO         MACRO

    IF RXDISIRQ = 1
      IF SCIRXINV = 1
    BIH     \1       ; branch if RXD low
      ELSE
    BIL     \1       ; branch if RXD low
      ENDIF
    ELSE    ; RXD uses normal I/O pin
      IF SCIRXINV = 1
    BRSET   RXDPIN,RXDPORT,\1    ; branch if RXD low
      ELSE
    BRCLR   RXDPIN,RXDPORT,\1    ; branch if RXD low
      ENDIF
    ENDIF

    ENDM

BRRXDHI         MACRO

    IF RXDISIRQ = 1
      IF SCIRXINV = 1
    BIL     \1       ; branch if RXD hi 
      ELSE
    BIH     \1       ; branch if RXD hi
      ENDIF
    ELSE    ; RXD uses normal I/O pin
      IF SCIRXINV = 1
    BRCLR   RXDPIN,RXDPORT,\1    ; branch if RXD hi
      ELSE
    BRSET   RXDPIN,RXDPORT,\1    ; branch if RXD hi
      ENDIF
    ENDIF

    ENDM

TXDCLR          MACRO

      IF SCITXINV = 1
        BSET    TXDPIN,TXDPORT  ; clr bit
      ELSE
        BCLR    TXDPIN,TXDPORT  ; clr bit
      ENDIF

        ENDM

TXDSET          MACRO

      IF SCITXINV = 1
        BCLR    TXDPIN,TXDPORT  ; set bit
      ELSE
        BSET    TXDPIN,TXDPORT  ; set bit
      ENDIF

        ENDM
        
TMOD    EQU     TMODH           ; we use high address for storing all 16 bits at once

;*******************************************************************************************
MY_ZEROPAGE:    SECTION  SHORT

ONEBIT: DS.W    1
BITS:   DS.B    1
ADRS:   DS.W    1
LEN:    DS.B    1
STAT:   DS.B    1
STSRSR: DS.B    1               ; storage for SRSR reg.

;*******************************************************************************************
APL_VECT_ROM:    SECTION

APL_VECT:
PRI:    DC.W    SCITXTICK
        DC.W    0
        DC.W    0
        DC.W    0
        
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

CODE_ROM:       SECTION

SCIAPI:
        DC.W    SCIINIT         ; address of WRITE call
        DC.W    READ            ; address of READ call
        DC.W    WRITE           ; address of WRITE call
        DC.W    ONEBIT          ; address of ONEBIT variable
       
        
FL1_PROT_ROM:   SECTION
; 14 bytes
ID_STRING1:
        DC.B    VER_NUM | RCS   ; version number & "Read command supported" flag
        DC.W    FLS_BEG         ; START ADDRESS OF FLASH    
        DC.W    FLS_END         ; END ADDRESS OF FLASH    
        DC.W    APL_VECT        ; POINTER TO APPLICATION VECTOR TABLE
        DC.W    INT_VECT        ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W    ERBLK_LEN       ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W    WRBLK_LEN       ; WRITE BLCK LENGTH OF FLASH ALG.
ID_STRING1_END:
CODE_ROM:   SECTION 

ID_STRING2:
        IDENTS
ID_STRING2_END:

;*******************************************************************************************
main:    
        LDA     SRSR                    ; fetch RESET status reg.
        STA     STSRSR                  ; store for later re-use
        TSTA                            ; check is zero (this happens if RESET pulse is too short)
        BEQ     slfprg                  ; if so, jump to self programming                
        AND     #%10000000              ; mask only POR RESET source      
        BEQ     VEC0                    ; any of these sources, go to self programming
slfprg: 
      IF CONFIG2DEF = 0
        CLR     CONFIG2
      ELSE
        MOV     #CONFIG2DEF,CONFIG2     ; from definition
      ENDIF
        MOV     #%10000001,CONFIG1      ; COP disable

        LDA     #(FLS_END+ERBLK_LEN-FLBPRMASK)/32 
        STA     FLBPR                   ; is in RAM!!
           
        BSR     SCIINIT                 ; call SCI init now :)                     
        
        LDHX    #SCITXTICK            ; ONEBIT is rewritten to default value
        STHX    ONEBIT                ; just for case the private area is erased
      
        LDA     #ACK
        JSR     WRITE
        
        LDX     #T100MS

LL2:    CLRA
LL1:    BRRXDHI L1
        
        DBNZA   LL1
        DBNZX   LL2

;       timeout
        ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************

L2:     CLRA
L1:     BRRXDLO CAUGHT
        
        DBNZA   L1
        DBNZX   L2

;       timeout
        ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************

SCIINIT:
        LDX     PRI+1                   ; [3B]
        LDA     PRI                     ; [3B]

        PSHA                            ; [1B]
        PULH                            ; [1B]
        STHX    ONEBIT                  ; (2B)

    IF RXDISIRQ = 0         ; RXDPORT & RXDPIN is defined (not IRQ)
        BCLR    RXDPIN,RXDDDR           ; input for RXD
      IF RXDPUEN = 1
        BSET    RXDPIN,RXDPUE
      ENDIF
    ENDIF        

        TXDSET
    IF SINGLEWIRE=0
        BSET    TXDPIN,TXDDDR           ; (2B) output for TXD
    ENDIF
        RTS

;*******************************************************************************************

CAUGHT:            ; CAUGHT IN SELF-PROGRAMMING?
        JSR     SCIRXNOEDGE

      IF CALENABLED = 1
        CLRH
        CLRX

MONRXD2:
        BRRXDHI MONRXD2

CHKRXD:
        BRRXDHI BRKDONE

      IF RXDISIRQ = 1
        NOP                     ; (1)
        NOP                     ; (1)
      ENDIF
        AIX     #1              ; (2) INCREMENT THE COUNTER
        BRA     CHKRXD          ; (3) GO BACK AND CHECK SIGNAL AGAIN

BRKDONE:
        STHX    ONEBIT          ; store it

        TXA
        LDX     #$1a            ; calculate speed
        DIV
      ELSE
        LDA     #16             ; <<< modify this if no calibration is required (BUS freq in MHz * 4)
      ENDIF
             
        STA     CPUSPD
        CLR     CTRLBYT         ; no mass erase    
;*******************************************************************************************
; successful return from all write routines
SUCC:
        LDA     #ACK
        JSR     WRITE

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

        LDHX    #ONEBIT         ; next 8 are from RAM area (!)
        MOV     #8,LEN          ; 8 is future priv area
        BSR     WRITE_LOOP

        MOV     #ID_STRING2_END-ID_STRING2, LEN
        LDHX    #ID_STRING2
        BSR     WRITE_LOOP

        BRA     BCKGND          ; finish without ACK
      
;*******************************************************************************************
WRITE_LOOP:                     ; start address in HX, length in LEN
        LDA     ,X
        JSR     WRITE
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
GETADDR:
        BSR     READ
        PSHA
        PULH                    ; store to H:x
        BSR     READ
        TAX                     ; store to h:X
        RTS
;*******************************************************************************************
ERASE_COM:
        BSR     GETADDR         ; read adr. and return in H:X
        JSR     ERARNGE         ; call ROM erase routine

        BRA     SUCC            ; refer status back to PC

;*******************************************************************************************
WR_DATA_COM:
        BSR     GETADDR         ; read adr. and return in H:X
        STHX    ADRS
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
        
        BRA     SUCC            ; refer status back to PC

;*******************************************************************************************
READ:
        BRRXDLO READ            ; (3B) loop until RXD high (idle)

SCIRXNOEDGE:
        PSHH                    ; (1B)
        PSHX                    ; (1B)

        LDX     ONEBIT          ; (2B)
        LDA     ONEBIT+1        ; (2B)
        LSRX                    ; (1B)
        RORA                    ; (1B)
        STX     TMODH           ; first TOF should occur just half bit
        STA     TMODL           ; after the hi-lo edge (right in the middle of start bit)

SCIRX1:
        BRRXDHI SCIRX1          ; loop until RXD low (wait for start bit)

        MOV     #%00010000,TSC  ; initialize prescalers, reset & run the timer
        MOV     #9,BITS         ; number of bits + 1
        
SCIRX2: BRCLR   7,TSC,SCIRX2    ; wait for TOF
                                
        LSRA                    ; shift data right (highest bit cleared)
        BRRXDLO RXDLOW          ; skip if RXD low
        ORA     #$80            ; set highest bit if RXD high

RXDLOW: LDHX    ONEBIT
        STHX    TMOD

        BCLR    7,TSC           ; and clear TOF
        DBNZ    BITS,SCIRX2     ; and loop for next bit

        BRA     EPILOG        

;*******************************************************************************************
FL2_PROT_ROM:   SECTION
; 16 bytes
WRITE:
        PSHH                    ; (1B)
        PSHX                    ; (1B)

        LDHX    ONEBIT          ; (2B)
        STHX    TMOD            ; (2B)

    IF SINGLEWIRE=1
        BSET    TXDPIN,TXDDDR   ; (2B) output for TXD
    ENDIF

        MOV     #%00010000,TSC  ; (3B) initialize prescalers, reset & run the timer
        JMP     page3           ; (3B) total 14 (of 14)

CODE_ROM:   SECTION 

page3:         
        
SCITX0: BRCLR   7,TSC,SCITX0    ; wait for TOF
        MOV     #10,BITS        ; number of bits + 1 stop bit
        BRA     DATALOW         ; jump to loop

SCITX2:        
        SEC                     ; set carry so stop bit is '1'
        RORA                    ; rotate lowest bit
        BCC     DATALOW

        TXDSET
        SKIP2                   ; skip next two bytes
DATALOW:
        TXDCLR
        BCLR    7,TSC           ; and clear TOF
SCITX1: BRCLR   7,TSC,SCITX1    ; wait for TOF

        DBNZ    BITS,SCITX2     ; and loop for next bit

EPILOG:
        MOV     #%00110000,TSC  ; stop & reset timer

    IF SINGLEWIRE=1
        BCLR    TXDPIN,TXDDDR           ; (2B) input for TXD (shared with RXD)
    ENDIF
        PULX
        PULH
        RTS

;*******************************************************************************************
SCI_PROT_ROM:   SECTION
; 2 bytes
SCIAPIREF:
        DC.W    SCIAPI          ; this address holds the start of SCI API table
                                ; this is an address of READ call,
                                ; WRITE call is 2 bytes higher
  
;*******************************************************************************************
END  
