;*********************************************************************
; HEADER_START
;
;        $File Name: slfprgR-lb.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    LB main bootloader file
;      Platform:       HC08
;      $Version: 6.0.7.0$
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

    include "reg-lb.h"

RCS_ENA         EQU     0           ; READ COMMAND SUPPORTED?

  IFNE RCS_ENA
RCS             EQU     $80         ; READ COMMAND SUPPORTED
  ELSE
RCS             EQU     0           ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM         EQU     1           ; FC protocol version number


ERBLK_LEN       EQU     64
WRBLK_LEN       EQU     32       

FLS_END         EQU     $FC80       ; this is APL_VECT address (also from PRM file)
INT_VECT        EQU     $FFDE

FLBPRMASK       EQU     $C000       ; this is CPU specific FLBPR mask (i.e. bits that are always in the address)

ROMSTART        EQU     $037E

ERARNGE         EQU     ROMSTART+9   ;???? different ROM routines allocation ????
PRGRNGE         EQU     ROMSTART+12   ;???? different ROM routines allocation ????

RAMSTART        EQU     $80
CTRLBYT         EQU     RAMSTART+$08
CPUSPD          EQU     RAMSTART+$09
LADDR           EQU     RAMSTART+$0A
DATA            EQU     RAMSTART+$0C
INV             EQU     1   ; symbolic defines
NOINV           EQU     0   ; for inversion selection

FLS_BEG         EQU     $DE00       ; flash start for LB8

IDENTS          MACRO
                DC.B    'LB8',0       ; soft SCI
                ENDM

BUSCLOCK        EQU     4000000       ; int. osc. default clock
SCISPEED        EQU     9600
SPEED           EQU     16            ; specify fBUS*4 clk in MHz 

;**************************************************************************

            IF PLATFORM = 1
TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     0             ; <<<
SCITXINV        EQU     0             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     0             ; <<<
            ENDIF

;**************************************************************************

            IF PLATFORM = 2
TXDPORT         EQU     PTA           ; <<<
TXDPIN          EQU     0             ; <<<
SCITXINV        EQU     0             ; (1 if SCI TX is inverted (no drivers))
SCIRXINV        EQU     SCITXINV      ; (1 if SCI RX is inverted (no drivers))

RXDPORT         EQU     PTA           ; <<<
RXDPIN          EQU     0             ; <<<
            ENDIF

;**************************************************************************
    IF (RXDPORT = TXDPORT) & (RXDPIN = TXDPIN)
SINGLEWIRE      EQU     1             ; do use single-wire feature
    ELSE
SINGLEWIRE      EQU     0             ; do NOT use single-wire feature
    ENDIF    
;**************************************************************************

RXDDDR          EQU     RXDPORT+4
RXDPUE          EQU     RXDPORT+$0B   ; define pull-up enable port

TXDDDR          EQU     TXDPORT+4
   
SCITXTICK       EQU     (BUSCLOCK/SCISPEED)
;*******************************************************************************************

            XDEF    main
            XDEF    VEC1
            XDEF    VEC2

            XDEF    VEC4
            XDEF    VEC5
            XDEF    VEC6
            XDEF    VEC7
            XDEF    VEC8
            XDEF    VEC9

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
        DC.B    $ff, $ff, $ff   ; vector 3
VEC4:   JMP     main            ; vector 4
VEC5:   JMP     main            ; vector 5
VEC6:   JMP     main            ; vector 6
VEC7:   JMP     main            ; vector 7
VEC8:   JMP     main            ; vector 8
VEC9:   JMP     main            ; vector 9
        DC.B    $ff, $ff, $ff   ; vector 10
        DC.B    $ff, $ff, $ff   ; vector 11
        DC.B    $ff, $ff, $ff   ; vector 12
        DC.B    $ff, $ff, $ff   ; vector 13
        DC.B    $ff, $ff, $ff   ; vector 14
VEC15:  JMP     main            ; vector 15
VEC16:  JMP     main            ; vector 16

FL1_PROT_ROM:   SECTION
; 10 bytes
SCIAPI:
        DC.W    SCIINIT         ; address of WRITE call
        DC.W    READ            ; address of READ call
        DC.W    WRITE           ; address of WRITE call
        DC.W    ONEBIT          ; address of ONEBIT variable

CODE_ROM:   SECTION       
ID_STRING1:
        DC.B    VER_NUM | RCS   ; version number & "Read command supported" flag
        DC.W    FLS_BEG         ; START ADDRESS OF FLASH    
        DC.W    FLS_END         ; END ADDRESS OF FLASH    
        DC.W    APL_VECT        ; POINTER TO APPLICATION VECTOR TABLE
        DC.W    INT_VECT        ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W    ERBLK_LEN       ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W    WRBLK_LEN       ; WRITE BLCK LENGTH OF FLASH ALG.
ID_STRING1_END:

ID_STRING2:
        IDENTS
ID_STRING2_END:
;*******************************************************************************************
FLB_PROT_ROM:   SECTION

FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection block start - MUST CHANGE ACCORDING TO MEMORY MAPPING

;*******************************************************************************************
CODE_ROM:       SECTION 
main:    
        LDA     OSCTRIMF                ; (3B) fetch manufacturer preloaded TRIM value
        STA     OSCTRIM                 ; (2B) and trim OSC now!

        LDA     SRSR                    ; fetch RESET status reg.
        STA     STSRSR                  ; store for later re-use
        TSTA                            ; check is zero (this happens if RESET pulse is too short)
        BEQ     slfprg                  ; if so, jump to self programming                
        AND     #%10000000              ; mask only POR RESET source      
        BEQ     VEC0                    ; any of these sources, go to self programming
slfprg: 
        CLR     CONFIG2               ; int. oscillator enable
        MOV     #%10000001,CONFIG1      ; COP disable

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

        BCLR    RXDPIN,RXDDDR           ; input for RXD
        BSET    RXDPIN,RXDPUE

        TXDSET
    IF SINGLEWIRE=0
        BSET    TXDPIN,TXDDDR           ; (2B) output for TXD
    ENDIF
        RTS

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

        MOV     #SPEED, CPUSPD
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
WRITE:
        PSHH                    ; (1B)
        PSHX                    ; (1B)

        LDHX    ONEBIT          ; (2B)
        STHX    TMOD            ; (2B)

    IF SINGLEWIRE=1
        BSET    TXDPIN,TXDDDR   ; (2B) output for TXD
    ENDIF

        MOV     #%00010000,TSC  ; (3B) initialize prescalers, reset & run the timer
        
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
