;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-s08qg-softsci.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    S08QG main bootloader file, software SCI
;      Platform:       HCS08
;      $Version: 8.0.11.0$
;      $Date: Sep-10-2012$ 
;      $Last Modified By: r30323$
;      Company:        Freescale Semiconductor
;      Security:       General Business
;
; =================================================================== 
; Copyright (c):      Freescale Semiconductor, 2006, All rights reserved.
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

; only labels PLATFORM and IRQOPTION defined externally:
;
; PLATFORM = 1,2,3... once you create your own platform (combination or RXD and TXD
; pins, together with polarity, memory size, etc.), add a new target with new platform
; number and add a new section woth defines for this platform.
; 
; IRQOPTION *NOT* defined >> regular version
; IRQOPTION defined >> regular version using IRQ option (bootloading won't start if IRQ high)
;
; The bootloader starts communicating at 9600Bd but with calibration feature, 
; the communication speeds up to 57600Bd were briefly tested (the embedded side
; will automatically calibrate to such speed without any code change). 


    include "mc9s08qg8.inc"

;##########################################################################
;##########################################################################

            IF PLATFORM = 1      ; TRA0

RCS_ENA         EQU     1              ; READ COMMAND SUPPORTED?

SIZE            EQU     8             ; specify YOUR memory size

TXDPORT         EQU     PTAD          ; <<< TxD pin port
TXDPIN          EQU     PTAD_PTAD0    ; <<< TxD pin number

SCITXINV        EQU     0             ; 0 with level shifters, 1 without
SCIRXINV        EQU     SCITXINV      ; 0 with level shifters, 1 without

RXDPORT         EQU     PTAD          ; <<< RxD pin port
RXDPIN          EQU     PTAD_PTAD0    ; <<< RxD pin number

RXDPUEN         EQU     1             ; use pull-up feature
RXDPUE          EQU     PTAPE         ; define pull-up enable port, if used

            ENDIF

;**************************************************************************

            IF PLATFORM = 2      ; TB1RB0

RCS_ENA         EQU     1              ; READ COMMAND SUPPORTED?

SIZE            EQU     8             ; specify YOUR memory size

TXDPORT         EQU     PTBD          ; <<< TxD pin port
TXDPIN          EQU     PTBD_PTBD1    ; <<< TxD pin number

SCITXINV        EQU     0             ; 0 with level shifters, 1 without
SCIRXINV        EQU     SCITXINV      ; 0 with level shifters, 1 without

RXDPORT         EQU     PTBD          ; <<< RxD pin port
RXDPIN          EQU     PTBD_PTBD0    ; <<< RxD pin number

RXDPUEN         EQU     1             ; use pull-up feature
RXDPUE          EQU     PTBPE         ; define pull-up enable port, if used

            ENDIF

;**************************************************************************

            IF PLATFORM = 3      ; TRiB6

RCS_ENA         EQU     1              ; READ COMMAND SUPPORTED?

SIZE            EQU     8             ; specify YOUR memory size

TXDPORT         EQU     PTBD          ; <<< TxD pin port
TXDPIN          EQU     PTBD_PTBD6    ; <<< TxD pin number

SCITXINV        EQU     1             ; 0 with level shifters, 1 without
SCIRXINV        EQU     SCITXINV      ; 0 with level shifters, 1 without

RXDPORT         EQU     PTBD          ; <<< RxD pin port
RXDPIN          EQU     PTBD_PTBD6    ; <<< RxD pin number

RXDPUEN         EQU     0             ; use pull-up feature
RXDPUE          EQU     PTBPE         ; define pull-up enable port, if used

            ENDIF

;##########################################################################
;##########################################################################
; the code below should not be modified (too much)
;**************************************************************************
    IF (RXDPORT = TXDPORT) & (RXDPIN = TXDPIN)
SINGLEWIRE      EQU     1             ; do use single-wire feature
    ELSE
SINGLEWIRE      EQU     0             ; do NOT use single-wire feature
    ENDIF    
;**************************************************************************

TXDDDR          EQU     TXDPORT+1
RXDDDR          EQU     RXDPORT+1
   
BUSCLOCK        EQU     8000000     ; QG's BUS clock
SCISPEED        EQU     9600

SCITXTICK       EQU     (BUSCLOCK/SCISPEED)

;*******************************************************************************************

  IF RCS_ENA = 1
RCS         EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU     2        ; FC protocol version number

IDENTS      MACRO

            DC.B   'QG'

          IF SIZE = 8
            DC.B     '8'    ; 8kb string
          ENDIF
          IF SIZE = 4
            DC.B     '4'    ; 4kb string
          ENDIF

            DC.B   '-softSCI'

          IFDEF IRQOPTION
            DC.B     '-irq'     ; IRQ option used
          ENDIF

            DC.B    0
            ENDM

ERBLK_LEN   EQU      512
WRBLK_LEN   EQU      64      

          IF SIZE = 8
FLS_BEG      EQU      $E000   ; FLASH #0 block start
FLS_END      EQU      $FDC0   ; FLASH #0 block end
        ENDIF

          IF SIZE = 4
FLS_BEG      EQU      $F000   ; FLASH #0 block start
FLS_END      EQU      $FDC0   ; FLASH #0 block end
        ENDIF

   
REL_VECT     EQU      $FDC0   ; newly relocated int. vectors
INT_VECT     EQU      $FFC0   ; start of table of original vectros!

; command codes
mBlank:     equ   $05         ;Blank Check command
mByteProg:  equ   $20         ;Byte Program command
mBurstProg: equ   $25         ;Burst Program command
mPageErase: equ   $40         ;Page Erase command
mMassErase: equ   $41         ;Mass Erase command


F_ICSTRM    equ   $FFAF
F_ICSFTRM   equ   $FFAE

         XDEF   main
;*******************************************************************************************
  
WR_DATA     EQU       'W'
RD_DATA     EQU       'R'
ENDPRG      EQU       'Q'
ERASE       EQU       'E'
ACK         EQU       $FC
IDENT       EQU       'I'

T100MS      EQU       255

ILOP        MACRO
            DC.B    $8d             ; this is illegal operation code
            ENDM

SKIP1       MACRO
            DC.B    $21             ; BRANCH NEVER (saves memory)
            ENDM

SKIP2       MACRO
            DC.B    $65             ; CPHX (saves memory)
            ENDM

BRRXDLO MACRO

        IF SCIRXINV = 1
            BRSET   RXDPIN,RXDPORT,\1    ; branch if RXD low
        ELSE
            BRCLR   RXDPIN,RXDPORT,\1    ; branch if RXD low
        ENDIF

        ENDM

BRRXDHI MACRO

        IF SCIRXINV = 1
            BRCLR   RXDPIN,RXDPORT,\1    ; branch if RXD hi
        ELSE
            BRSET   RXDPIN,RXDPORT,\1    ; branch if RXD hi
        ENDIF

        ENDM

TXDCLR  MACRO

        IF SCITXINV = 1
            BSET    TXDPIN,TXDPORT  ; clr bit
        ELSE
            BCLR    TXDPIN,TXDPORT  ; clr bit
        ENDIF

        ENDM

TXDSET  MACRO

        IF SCITXINV = 1
            BCLR    TXDPIN,TXDPORT  ; set bit
        ELSE
            BSET    TXDPIN,TXDPORT  ; set bit
        ENDIF

        ENDM
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

ONEBIT:   DS.W  1           ; length of 1 bit (in BUS clock cycles)
BITS:     DS.B  1                  ; bit counter in RX/TX softSCI routines
ADRS:     DS.W  1                  ; target flash address
ADRR:     DS.W  1                  ; pointer to source data in RAM
LEN:      DS.B  1                  ; lenght counter
STAT:     DS.B  1                  ; temporary length counter
STACK:    DS.W  1               ; temporary storage for SP

DEFAULT_RAM:    SECTION

DATA:     DS.B    WRBLK_LEN   ; buffer for Write data

;*******************************************************************************************
DEFAULT_ROM:   SECTION
     
ID_STRING:
          DC.B    1              ; number of Flash blocks
          DC.W    FLS_BEG        ; START ADDRESS OF FLASH   
          DC.W    FLS_END        ; END ADDRESS OF FLASH                                                                      
          DC.W    REL_VECT       ; POINTER TO APPLICATION VECTOR TABLE
          DC.W    INT_VECT       ; POINTER TO BEGINING OF FLASH INT. VECTORS
          DC.W    ERBLK_LEN      ; ERASE BLCK LENGTH OF FLASH ALG.
          DC.W    WRBLK_LEN      ; WRITE BLCK LENGTH OF FLASH ALG.

      IDENTS
ID_STRING_END:

          XDEF    MY_NVPROT   
          XDEF    MY_NVOPT    

;*******************************************************************************************
NVPROT_ROM:      SECTION
MY_NVPROT     DC.B   %11111100   ; flash protected (from 0xFE00) 

NVOPT_ROM:      SECTION
MY_NVOPT      DC.B   %10000010   ; backdoor enable, redirection enable, (un)secured flash [last 10]

DEFAULT_ROM:   SECTION
;*******************************************************************************************
main:
      IFDEF IRQOPTION
          BIH     PVEC0                   ; if IRQ high, jump directly to real app.
      ENDIF
          LDA     SRS                     ; fetch RESET status reg.
          TSTA                            ; check if zero (this happens if RESET pulse is too short)
          BEQ     slfprg                  ; if so, jump to self programming                
          AND     #%10000000              ; mask only POR RESET source      
          BNE     slfprg                  ; any of these sources, go to self programming
PVEC0:        
          LDHX    #(REL_VECT|$00FF)&$FFFE   ; there should be relocated reset vector of the new app.
          LDA     ,X
          PSHA
          AND     1,X
          LDX     1,X
          PULH
          INCA
          BEQ     slfprg                 ; don't jump if empty vector!
          JMP     ,X                      ; jump to relocated application!

slfprg:        
          LDA     F_ICSTRM
          STA     ICSTRM

          LDA     F_ICSFTRM
          ORA     ICSSC
          STA     ICSSC

          LDA     #%00000010
          STA     SOPT1                  ; COP disable, BDM enable (for now)

          MOV     #%00000000,ICSC2   ; bus divide :1, ie bus = 8MHz

           ; f(BUS)=f(ICGOUT)/2
     
          LDA     FSTAT
          ORA     #mFSTAT_FACCERR                            
          STA     FSTAT                      ; clear any FACCERR flag

          LDA     #(mFCDIV_PRDIV8 + 4) ; div by 8*(4+1) to fit into 150-200kHz Flash clock!
          STA     FCDIV
        
          LDHX    #SCITXTICK               ; ONEBIT default value
          STHX    ONEBIT

      IF RXDPUEN=1
          LDA     RXDPUE
          ORA     #(1<<RXDPIN)
          STA     RXDPUE                  ; pull-up RXD pin (if enabled)
      ENDIF

          TXDSET                          ; TxD pin idle
      IF SINGLEWIRE=0
          BSET    TXDPIN,TXDDDR           ; output for TXD
      ENDIF
          BCLR    RXDPIN,RXDDDR           ; input for RXD

; OPTIONAL DELAY - if your RS232 hardware is lazy, uncomment following delay

;         CLRX
;DLY2:    CLRA
;DLY1:    NOP
;        
;         DBNZA   DLY1
;         DBNZX   DLY2
;

          LDA     #ACK 
          JSR     WRITE

          LDX     #T100MS
LL2:      CLRA
LL1:      BRRXDHI L1
        
          DBNZA   LL1
          DBNZX   LL2
                      ; timeout - no data
          ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************

L2:       CLRA
L1:       BRRXDLO CAUGHT  ; hi-lo edge required (start bit)
        
          DBNZA   L1
          DBNZX   L2
                      ; timeout - no data
          ILOP        ; generate RESET by doing illegal operation
;*******************************************************************************************
CAUGHT:               ; CAUGHT IN SELF-PROGRAMMING?
          JSR     SCIRXNOEDGE

          CLRH
          CLRX               ; calibrate now

MONRXD2:
          BRRXDHI MONRXD2
CHKRXD:
          BRRXDHI BRKDONE ; (5) together 10 BUS clocks per loop
                                ;     we measure 10 bits time so at the
                                ;     and H:X will contain a correct BUS 
                                ;     clock ticks for 1 bit time

          AIX     #1              ; (2) INCREMENT THE COUNTER
          BRA     CHKRXD          ; (3) GO BACK AND CHECK SIGNAL AGAIN

BRKDONE:
          STHX    ONEBIT          ; store it
;*******************************************************************************************
; successful return from all write routines
SUCC:
          LDA     #ACK                  ; send ACK
          JSR     WRITE

;fall thru to background
;*******************************************************************************************
; BEGIN OF BACKGROUND COMMAND LOOP
BCKGND:
          JSR      READ                              ; read command from PC
            
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
IDENT_COM:                       ; TRANSFER OF IDENTIFICATION STRING
          LDA      #(VER_NUM | RCS) ; version number & "Read command supported" flag
          BSR      WRITE
          LDA      SDIDH                ; system device identification 1 register (high)
          BSR      WRITE
          LDA      SDIDL                ; system device identification 1 register (low)
          BSR      WRITE

          MOV      #ID_STRING_END-ID_STRING, LEN
          LDHX     #ID_STRING
          BSR      WRITE_LOOP
                 
          BRA      BCKGND           ; finish without ACK
;*******************************************************************************************
WRITE_LOOP:             ; start address in HX, length in LEN
          LDA      ,X
          BSR      WRITE
          AIX      #1
          DBNZ     LEN, WRITE_LOOP
          RTS
;*******************************************************************************************
      IF RCS_ENA = 1
RD_DATA_COM:

          JSR      READ
          STA      ADRS
          BSR      READ
          STA      ADRS+1
          BSR      READ
          STA      LEN
          LDHX     ADRS
        
          BSR      WRITE_LOOP

          BRA      BCKGND              ; finish without ACK
      ENDIF

;*******************************************************************************************
ERASE_COM:
          BSR      READ
          STA      ADRS
          BSR      READ
          STA      ADRS+1

          lda      #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
          sta      FSTAT                   ;abort any command and clear errors

          mov      #LOW(EraseSubSize), STAT   ;length of flash erase routine to STAT
          tsx
          sthx     STACK
          ldhx     #EraseSubEnd-1        ;point at last byte to move to stack

          jmp      DoOnStack              ;execute prog code from stack RAM
;*******************************************************************************************
WR_DATA_COM:
          BSR      READ
          STA      ADRS
          BSR      READ
          STA      ADRS+1
          BSR      READ
          STA      STAT
          STA      LEN
          LDHX     #DATA
          STHX     ADRR
WR_DATA_L1:
          BSR      READ
          STA      ,X
          AIX      #1
          DBNZ     STAT,WR_DATA_L1
      
          lda      #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
          sta      FSTAT                   ;abort any command and clear errors

          mov      #LOW(ProgSubSize), STAT   ;length of flash prog routine to STAT
          tsx
          sthx     STACK
          ldhx     #ProgSubEnd-1          ;point at last byte to move to stack

          jmp      DoOnStack          ; execute prog code from stack RAM
;*******************************************************************************************
;*******************************************************************************************
WRITE:
          PSHH                    ; (1B)
          PSHX                    ; (1B)

          LDHX     ONEBIT          ; (2B)
          STHX     TPMMOD          ; (2B)

    IF SINGLEWIRE=1
          BSET     TXDPIN,TXDDDR   ; (2B) output for TXD
    ENDIF

          MOV      #%00001000,TPMSC ; initialize prescalers, run the timer, select clock
          STA      TPMCNTH               ; clear counter

SCITX0:   BRCLR    TPMSC_TOF,TPMSC,SCITX0    ; wait for TOF
          MOV      #10,BITS        ; number of bits + 1 stop bit
          BRA      DATALOW         ; jump to loop

SCITX2:        
          SEC                     ; set carry so stop bit is '1'
          RORA                    ; rotate lowest bit
          BCC      DATALOW

          TXDSET
          SKIP2                   ; skip next two bytes
DATALOW:
          TXDCLR
          BCLR     TPMSC_TOF,TPMSC           ; and clear TOF
SCITX1:   BRCLR    TPMSC_TOF,TPMSC,SCITX1    ; wait for TOF

          DBNZ     BITS,SCITX2     ; and loop for next bit

EPILOG:
          CLR      TPMSC           ; stop timer

    IF SINGLEWIRE=1
          BCLR     TXDPIN,TXDDDR   ; (2B) input for TXD (shared with RXD)
    ENDIF
          PULX
          PULH
          RTS
;*******************************************************************************************
READ:
          BRRXDLO  READ             ; (3B) loop until RXD high (idle)

SCIRXNOEDGE:
          PSHH                     ; (1B)
          PSHX                     ; (1B)

          LDX      ONEBIT          ; (2B)
          LDA      ONEBIT+1        ; (2B)
          LSRX                     ; (1B)
          RORA                     ; (1B)
          STX      TPMMODH         ; first TOF should occur just half bit
          STA      TPMMODL         ; after the hi-lo edge (right in the middle of start bit)

SCIRX1:
          BRRXDHI  SCIRX1          ; loop until RXD low (wait for start bit)

          MOV      #%00001000,TPMSC  ; initialize prescalers, run the timer, select clock
          STA      TPMCNTH               ; clear counter
          MOV      #9,BITS         ; number of bits + 1
        
SCIRX2:   BRCLR    TPMSC_TOF,TPMSC,SCIRX2    ; wait for TOF
                                
          LSRA                     ; shift data right (highest bit cleared)
          BRRXDLO  RXDLOW          ; skip if RXD low
          ORA      #$80            ; set highest bit if RXD high

RXDLOW:   LDHX     ONEBIT
          STHX     TPMMODH

          BCLR     TPMSC_TOF,TPMSC ; and clear TOF
          DBNZ     BITS,SCIRX2     ; and loop for next bit

          BRA      EPILOG        

;*******************************************************************************************
;*******************************************************************************************
ROM_2:   SECTION
; 62 bytes
DoOnStack: 
          lda      ,x             ;read from flash
          psha                    ;move onto stack
          aix      #-1          ;next byte to move
          dbnz     STAT, DoOnStack
          tsx                    ;point to sub on stack
          jmp      ,x             ;execute the sub on the stack (will return on it's own)      
DEFAULT_ROM:   SECTION 
;*******************************************************************************************
EraseSub:    
          ldhx     ADRS             ;get flash address
          sta      0,x              ;write to flash; latch addr and data
          lda      #mPageErase      ;get flash command
          sta      FCMD             ;write the flash command
          lda      #mFSTAT_FCBEF    ;mask to initiate command
          sta      FSTAT            ;[pwpp] register command
          nop                       ;[p] want min 4~ from w cycle to r
ChkDoneErase: 
          lda      FSTAT            ;[prpp] so FCCF is valid
          lsla                      ;FCCF now in MSB
          bpl      ChkDoneErase     ;loop if FCCF = 0

          ldhx     STACK
          txs
          jmp      SUCC           ;refer status back to PC
EraseSubEnd: 
EraseSubSize: equ (*-EraseSub)
;*******************************************************************************************
ROM_2:   SECTION
; 62 bytes
ProgSub:    
          lda      FSTAT            ;check FCBEF
          and      #mFSTAT_FCBEF    ;mask it
          beq      ProgSub          ;loop if not empty
          
          ldhx     ADRR
          lda      0,x
          aix      #1
          sthx     ADRR
          
          ldhx     ADRS             ;get flash address
          sta      0,x              ;write to flash; latch addr and data
          aix      #1
          sthx     ADRS
          
          lda      #mBurstProg      ;get flash command
          sta      FCMD             ;write the flash command
          lda      #mFSTAT_FCBEF    ;mask to initiate command
          sta      FSTAT            ;[pwpp] register command
          dbnz     LEN,ProgSub      ;all bytes in a row?
ChkDoneProg: 
          lda      FSTAT            ;[prpp] so FCCF is valid
          lsla                      ;FCCF now in MSB
          bpl      ChkDoneProg      ;loop if FCCF = 0
          
          ldhx     STACK
          txs
          jmp      SUCC             ;refer status back to PC
ProgSubEnd: 
ProgSubSize: equ (*-ProgSub)
DEFAULT_ROM:   SECTION 
;*******************************************************************************************

END            

