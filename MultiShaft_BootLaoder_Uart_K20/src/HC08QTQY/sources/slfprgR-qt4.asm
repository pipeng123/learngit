;*********************************************************************
; HEADER_START
;
;        $File Name: slfprgR-qt4.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    QT/QY main bootloader file
;      Platform:       HC08
;      $Version: 6.0.45.0$
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

    include "reg-qt4.h"

RCS_ENA         EQU     0           ; READ COMMAND SUPPORTED?

  IFNE RCS_ENA
RCS             EQU     $80         ; READ COMMAND SUPPORTED
  ELSE
RCS             EQU     0           ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM         EQU     1           ; FC protocol version number

BUSCLOCK        EQU     3200000     ; QTQY's BUS clock
SCISPEED        EQU     9600

SPEED           EQU     10


ERBLK_LEN       EQU     64
WRBLK_LEN       EQU     32       

FLS_END         EQU     $FCC0       ; this is APL_VECT address (also from PRM file)
INT_VECT        EQU     $FFDE

FLBPRMASK       EQU     $C000       ; this is CPU specific FLBPR mask (i.e. bits that are always in the address)


ROMSTART        EQU     $2800

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

INV             EQU      1   ; symbolic defines
NOINV           EQU      0   ; for inversion selection

MEMSTART_QT1    EQU     $F800           ; 1.5kB memory size
MEMSTART_QT2    EQU     $F800           ; 1.5kB memory size too ;)
MEMSTART_QT4    EQU     $EE00           ; 4kB memory size
MEMSTART_QT5    EQU     $EE00           ; 4kB memory size too ;)
MEMSTART_QT8    EQU     $DE00           ; 8kB memory size

;**************************************************************************

            IF PLATFORM = 1      ; TA5RA5

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     4             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     5             ; <<<

RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 2      ; TA1RA0

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     1             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     0             ; <<<
RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF
            ENDIF
;**************************************************************************

            IF PLATFORM = 3      ; TA4RA3

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     4             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     3             ; <<<

RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 4      ; TB5RB4

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTB           ; <<<
TXDPIN          EQU     5             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTB           ; <<<
RXDPIN          EQU     4             ; <<<

RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 5      ; TA3RA2

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     3             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     2             ; <<<

RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 6      ; TB5RB3

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTB           ; <<<
TXDPIN          EQU     5             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTB           ; <<<
RXDPIN          EQU     3             ; <<<
    
RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************

            IF PLATFORM = 7      ; TA2RA2

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     1             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     2             ; <<<

RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************
            IF PLATFORM = 10   ; TRiA4 (single wire)

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     4             ; <<<
SCITXINV        EQU     INV           ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     TXDPORT       ; <<<SINGLE WIRE
RXDPIN          EQU     TXDPIN        ; <<<SINGLE WIRE
    
RXDPUEN         EQU     0             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************
            IF PLATFORM = 11   ; TRA0 (single wire)

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     0             ; <<<
SCITXINV        EQU     NOINV         ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     TXDPORT       ; <<<SINGLE WIRE
RXDPIN          EQU     TXDPIN        ; <<<SINGLE WIRE
    
RXDPUEN         EQU     1             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************
            IF PLATFORM = 12   ; TRiA1 (single wire)

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     1             ; <<<
SCITXINV        EQU     INV           ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     TXDPORT       ; <<<SINGLE WIRE
RXDPIN          EQU     TXDPIN        ; <<<SINGLE WIRE
    
RXDPUEN         EQU     0             ; use pull-up feature

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************
            IF PLATFORM = 13   ; QT5/8 test  - TEST ONLY, NOT VERIFIED YET!!

FLS_BEG         EQU     MEMSTART_QT8    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     0             ; <<<
SCITXINV        EQU     NOINV           ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     TXDPORT       ; <<<SINGLE WIRE
RXDPIN          EQU     TXDPIN        ; <<<SINGLE WIRE
    
RXDPUEN         EQU     0             ; use pull-up feature (will be done different way)

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************
            IF PLATFORM = 14   ; TRiA3 (single wire)

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     3             ; <<<
SCITXINV        EQU     INV           ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     TXDPORT       ; <<<SINGLE WIRE
RXDPIN          EQU     TXDPIN        ; <<<SINGLE WIRE
    
RXDPUEN         EQU     0             ; use pull-up feature (will be done different way)

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF
;**************************************************************************
            IF PLATFORM = 15   ; TRiA5 (single wire)

FLS_BEG         EQU     MEMSTART_QT4    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     5             ; <<<
SCITXINV        EQU     INV           ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     TXDPORT       ; <<<SINGLE WIRE
RXDPIN          EQU     TXDPIN        ; <<<SINGLE WIRE
    
RXDPUEN         EQU     0             ; use pull-up feature (will be done different way)

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF

;**************************************************************************
            IF PLATFORM = 16   ; TRiA3 (single wire)

FLS_BEG         EQU     MEMSTART_QT8    ; specify YOUR memory limit!

TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     3             ; <<<
SCITXINV        EQU     INV           ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     TXDPORT       ; <<<SINGLE WIRE
RXDPIN          EQU     TXDPIN        ; <<<SINGLE WIRE
    
RXDPUEN         EQU     0             ; use pull-up feature (will be done different way)

            IF RXDPUEN = 1
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port
            ENDIF

            ENDIF
;**************************************************************************
    IF (RXDPORT = TXDPORT) & (RXDPIN = TXDPIN)
SINGLEWIRE      EQU     1             ; do use single-wire feature
    ELSE
SINGLEWIRE      EQU     0             ; do NOT use single-wire feature
    ENDIF    
;**************************************************************************


TXDDDR          EQU     TXDPORT+4
RXDDDR          EQU     RXDPORT+4
   
SCITXTICK       EQU     (BUSCLOCK/SCISPEED)

;*******************************************************************************************

                    XDEF    main
                    XDEF    VEC1
                    XDEF    VEC2

                    XDEF    VEC4
                    XDEF    VEC5
                    XDEF    VEC6

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

BRRXDLO     MACRO

      IF SCIRXINV = 1
        BRSET   RXDPIN,RXDPORT,\1    ; branch if RXD low
      ELSE
        BRCLR   RXDPIN,RXDPORT,\1    ; branch if RXD low
      ENDIF

    ENDM

BRRXDHI         MACRO

      IF SCIRXINV = 1
        BRCLR   RXDPIN,RXDPORT,\1    ; branch if RXD hi
      ELSE
        BRSET   RXDPIN,RXDPORT,\1    ; branch if RXD hi
      ENDIF

    ENDM

TXDCLR         MACRO

      IF SCITXINV = 1
        BSET    TXDPIN,TXDPORT  ; clr bit
      ELSE
        BCLR    TXDPIN,TXDPORT  ; clr bit
      ENDIF

        ENDM

TXDSET         MACRO

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
        DC.B    $ff,$ff,$ff     ; unused vector 3
VEC4:   JMP     main            ; vector 4
VEC5:   JMP     main            ; vector 5
VEC6:   JMP     main            ; vector 6
        DC.B    $ff,$ff,$ff     ; unused vector 7
        DC.B    $ff,$ff,$ff     ; unused vector 8
        DC.B    $ff,$ff,$ff     ; unused vector 9
        DC.B    $ff,$ff,$ff     ; unused vector 10
        DC.B    $ff,$ff,$ff     ; unused vector 11
        DC.B    $ff,$ff,$ff     ; unused vector 12
        DC.B    $ff,$ff,$ff     ; unused vector 13
        DC.B    $ff,$ff,$ff     ; unused vector 14
VEC15:  JMP     main            ; vector 15
VEC16:  JMP     main            ; vector 16

CODE_ROM:       SECTION

SCIAPI:
        DC.W    SCIINIT         ; address of WRITE call
        DC.W    READ            ; address of READ call
        DC.W    WRITE           ; address of WRITE call
        DC.W    ONEBIT          ; address of ONEBIT variable
        
ID_STRING1:
        DC.B    VER_NUM | RCS   ; version number & "Read command supported" flag
        DC.W    FLS_BEG         ; START ADDRESS OF FLASH    
        DC.W    FLS_END         ; END ADDRESS OF FLASH    
        DC.W    APL_VECT        ; POINTER TO APPLICATION VECTOR TABLE
        DC.W    INT_VECT        ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W    ERBLK_LEN       ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W    WRBLK_LEN       ; WRITE BLCK LENGTH OF FLASH ALG.
ID_STRING1_END:

;*******************************************************************************************
FLB_PROT_ROM:   SECTION

FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection block start - MUST CHANGE ACCORDING TO MEMORY MAPPING

FL2_PROT_ROM:   SECTION
; 16 bytes
main:   
        LDA     OSCTRIMF                ; (3B) fetch manufacturer preloaded TRIM value
        STA     OSCTRIM                 ; (2B) and trim OSC now!

        LDA     SRSR                    ; (3B) fetch RESET status reg.
      ; warning! SRSR is NOT stored in RAM for later re-use! (lack of space)
        AND     #%10000000              ; (2B) unmask only POR and PIN RESET source      
        BNE     slfprg                  ; (2B) if any of these, jump to slfprg
        JMP     VEC0                    ; (3B) otherwise run real app.
FL1_PROT_ROM:   SECTION
; 28 bytes
slfprg:       
  IF (FLS_BEG = MEMSTART_QT5) || (FLS_BEG = MEMSTART_QT8)    ; if Qx5 or Qx8 defined,
        MOV      #%00100000,OSCSTAT      ; [3B] specify 12.8MHz internal clock select! (for QT/QY1-4 compatibility)
  ENDIF
        LDHX    #page2                  ; (3B)
        PSHX                            ; (1B)
        PSHH                            ; (1B) put to stack, RTS will jump to page2
        
SCIINIT:
        LDX     PRI+1                   ; [3B]
        LDA     PRI                     ; [3B]

        PSHA                            ; [1B]
        PULH                            ; [1B]
        STHX    ONEBIT                  ; (2B)

      IF RXDPUEN=1
        BSET    RXDPIN,RXDPUE           ; (2B) pull-up RXD pin (if enabled)
      ENDIF

        TXDSET                          ; (2B)
    IF SINGLEWIRE=0
        BSET    TXDPIN,TXDDDR           ; (2B) output for TXD
    ENDIF
        BCLR    RXDPIN,RXDDDR           ; (2B) input for RXD
        RTS                             ; (1B) 27 out of 28

CODE_ROM:   SECTION 

page2: 
        LDHX    #SCITXTICK            ; ONEBIT is rewritten to default value
        STHX    ONEBIT                ; just for case the private area is erased
      
        MOV     #%10000001,CONFIG1      ; (3B) COP disable

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
CAUGHT:            ; CAUGHT IN SELF-PROGRAMMING?
        JSR     SCIRXNOEDGE

        CLRH
        CLRX

MONRXD2:
        BRRXDHI MONRXD2

CHKRXD:
        BRRXDHI BRKDONE

        AIX     #1              ; (2) INCREMENT THE COUNTER
        BRA     CHKRXD          ; (3) GO BACK AND CHECK SIGNAL AGAIN

BRKDONE:
        STHX    ONEBIT          ; store it

        MOV     #SPEED,CPUSPD
        CLR     CTRLBYT         ; no mass erase    
;*******************************************************************************************
; successful return from all write routines
SUCC:
        LDA     #ACK
SUCCWR:
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

        CLRA
        BRA     SUCCWR          ; call WRITE & finish without ACK
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

        ADD     ADRS+1
        STA     LADDR+1
        LDA     ADRS
        ADC     #0
        STA     LADDR

        LDHX    #DATA
WR_DATA_L1:
        BSR     READ
        STA     ,X
        AIX     #1
        DBNZ    STAT,WR_DATA_L1
                                ; START OF SELF-PROGRAMMING
        LDHX    ADRS
        JSR     PRGRNGE         ; call ROM erase routine
        
        BRA     SUCC            ; refer status back to PC

;*******************************************************************************************
READ:
        STA     COPCTL               ; bump COP
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
FL0_PROT_ROM:   SECTION
; 14 bytes
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
        DC.W    SCIAPI          ; this address holds the start of SCI API table, see sci.h
  
;*******************************************************************************************
END  
