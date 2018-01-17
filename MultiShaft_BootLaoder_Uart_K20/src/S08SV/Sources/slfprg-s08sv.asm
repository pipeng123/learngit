;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-s08sv.asm$
;      Project:        AN2295 Developper's HC08 Bootloader Slave
;      Description:    S08SV main bootloader file
;      Platform:       HCS08
;      $Version: 10.0.6.0$
;      $Date: Sep-10-2012$ 
;      $Last Modified By: r30323$
;      Company:        Freescale Semiconductor
;      Security:       General Business
;
; =================================================================== 
; Copyright (c):      Freescale Semiconductor, 2011, All rights reserved.
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

; label HISPEED defined externally:
; label HISPEED => if defined, 38400Bd is used instead of 9600Bd

    include "mc9s08sv8.inc"


RCS_ENA     EQU     1        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS         EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU     2        ; FC protocol version number

IDENTS      MACRO

            DC.B   'SV'

          IF SIZE = 16
            DC.B     '16'   ; 16kB string
          ENDIF
          
          IF SIZE = 8
            DC.B     '8'    ; 8kB string
          ENDIF
          
          IFDEF IRQOPTION
            DC.B     '-irq' ; IRQ option used
          ENDIF

            DC.B    0
            ENDM

ERBLK_LEN   EQU      512
WRBLK_LEN   EQU      64      

  IF SIZE = 16
FLS_BEG     EQU      $C000   ; FLASH #0 block start
FLS_END     EQU      $FDC0   ; FLASH #0 block end
  ENDIF

  IF SIZE = 8
FLS_BEG     EQU      $E000   ; FLASH #0 block start
FLS_END     EQU      $FDC0   ; FLASH #0 block end
  ENDIF

REL_VECT    EQU    $FDC0     ; newly relocated int. vectors
INT_VECT    EQU      $FFC0   ; start of table of original vectros!


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
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

ADRS:    DS.W   1
ADRR:    DS.W   1
LEN:     DS.B   1
STAT:    DS.B   1
STACK:   DS.W   1

DEFAULT_RAM:    SECTION

DATA:     DS.B   WRBLK_LEN

;*******************************************************************************************
DEFAULT_ROM:   SECTION
     
ID_STRING:
      DC.B   1              ; number of Flash blocks
      DC.W   FLS_BEG        ; START ADDRESS OF FLASH   
      DC.W   FLS_END        ; END ADDRESS OF FLASH                                                                      
      DC.W   REL_VECT       ; POINTER TO APPLICATION VECTOR TABLE
      DC.W   INT_VECT       ; POINTER TO BEGINING OF FLASH INT. VECTORS
      DC.W   ERBLK_LEN      ; ERASE BLCK LENGTH OF FLASH ALG.
      DC.W   WRBLK_LEN      ; WRITE BLCK LENGTH OF FLASH ALG.

      IDENTS
    
ID_STRING_END:

      XDEF   MY_NVPROT   
      XDEF   MY_NVOPT    

;*******************************************************************************************
NVPROT_ROM:      SECTION
MY_NVPROT   DC.B   %11111100   ; flash protected (from 0xFE00) 

NVOPT_ROM:      SECTION
MY_NVOPT    DC.B   %10000010   ; backdoor enable, redirection enable, (un)secured flash [last 10]

DEFAULT_ROM:   SECTION
;*******************************************************************************************
main:
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
      BEQ     slfprg                ; don't jump if empty vector!
      JMP     ,X                     ; jump to relocated application!

slfprg:        
      LDA     #%00000010
      STA     SOPT1                ; COP disable, BDM enable (for now)
      MOV     #%00000100,ICSC1       ; FEI mode, IREFS = 1

      MOV     #%00000000,ICSSC       ; DRS=0 (16-20MHz DCO range)
      MOV     #%00000000,ICSC2       ; BDIV=00 (/1), 16-20MHz, reqd' 16MHz, bus = ICS/2

      LDA     NVICSTRM
      STA     ICSTRM                  ; load ICS trim value from Flash
      LDA     NVFTRIM
      ORA     ICSSC
      STA     ICSSC                   ; load ICS fine trim value from Flash

      LDA     FSTAT
      ORA     #mFSTAT_FACCERR
      STA     FSTAT                 ; clear any FACCERR flag

      LDA     #39                     ; div by 40 to fit into 150-200kHz Flash clock!
      STA     FCDIV

      LDA     #%00001100
      STA     SCIC2                   ; transmit & receive enable
      CLRA
      STA     SCIBDH

    IFNDEF HISPEED
      LDA     #52
      STA     SCIBDL                ; BUS (8M)/(16 * 52) = 9600Bd
      ELSE
      LDA     #13
      STA     SCIBDL                ; BUS (8M)/(16 * 13) = 38400Bd
    ENDIF
      CLRA
      STA     SCIC3

; OPTIONAL DELAY - if your RS232 hardware is lazy, uncomment following delay

;        CLRX
;DLY2:   CLRA
;DLY1:   NOP
;        
;        DBNZA   DLY1
;        DBNZX   DLY2
;

      LDA     SCIS1
      LDA     #ACK
      STA     SCID

      LDX     #T100MS
L2:   CLRA
L1:   PSHA
      LDA     SCIS1
      AND     #mSCIS1_RDRF
      BNE     CAUGHT
      PULA
      DBNZA   L1
      DBNZX   L2

ILOP:
;       timeout
      ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
      BSR     READ
      CBEQA   #ACK, SUCC       ; Got ACK!

      ILOP          ; generate RESET by doing illegal operation
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
IDENT_COM:                   ; TRANSFER OF IDENTIFICATION STRING
      LDA     #(VER_NUM | RCS) ; version number & "Read command supported" flag
      BSR     WRITE
      LDA     SDIDH          ; system device identification 1 register (high)
      BSR     WRITE
      LDA     SDIDL          ; system device identification 1 register (low)
      BSR     WRITE

      MOV     #ID_STRING_END-ID_STRING, LEN
      LDHX    #ID_STRING
      BSR     WRITE_LOOP
                 
      BRA     BCKGND           ; finish without ACK
;*******************************************************************************************
WRITE_LOOP:                      ; start address in HX, length in LEN
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

      BRA     BCKGND              ; finish without ACK
    ENDIF

;*******************************************************************************************
WRITE:   
      PSHA
WRITE1
      LDA     SCIS1
      AND     #mSCIS1_TC
      BEQ     WRITE1
      PULA
      STA     SCID
      RTS

READ:
      LDA     SCIS1
      AND     #mSCIS1_RDRF
      BEQ     READ

      LDA     SCID
      RTS

;*******************************************************************************************
ERASE_COM:
      BSR     READ
      STA     ADRS
      BSR     READ
      STA     ADRS+1

      lda     #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
      sta     FSTAT                 ;abort any command and clear errors

      mov     #LOW(EraseSubSize), STAT   ;length of flash erase routine to STAT
      tsx
      sthx    STACK
      ldhx    #EraseSubEnd-1        ;point at last byte to move to stack

      bra     DoOnStack             ;execute prog code from stack RAM
;*******************************************************************************************
WR_DATA_COM:
      BSR     READ
      STA     ADRS
      BSR     READ
      STA     ADRS+1
      BSR     READ
      STA     STAT
      STA     LEN
      LDHX    #DATA
      STHX    ADRR

WR_DATA_L1:
      BSR     READ
      STA     ,X
      AIX     #1
      DBNZ    STAT,WR_DATA_L1
      
      lda     #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
      sta     FSTAT             ;abort any command and clear errors

      mov     #LOW(ProgSubSize), STAT   ;length of flash prog routine to STAT
      tsx
      sthx    STACK
      ldhx    #ProgSubEnd-1      ;point at last byte to move to stack

; bra    DoOnStack          ;execute prog code from stack RAM
; fallthru to DoOnStack
;*******************************************************************************************
DoOnStack: 
      lda     ,x               ;read from flash
      psha                     ;move onto stack
      aix     #-1              ;next byte to move
      dbnz    STAT, DoOnStack
      tsx                      ;point to sub on stack
      jmp    ,x                ;execute the sub on the stack (will return on it's own)      
;*******************************************************************************************
EraseSub:    
      ldhx     ADRS            ;get flash address
      sta      0,x             ;write to flash; latch addr and data
      lda      #mPageErase     ;get flash command
      sta      FCMD            ;write the flash command
      lda      #mFSTAT_FCBEF   ;mask to initiate command
      sta      FSTAT           ;[pwpp] register command
      nop                      ;[p] want min 4~ from w cycle to r
ChkDoneErase: 
      lda      FSTAT           ;[prpp] so FCCF is valid
      lsla                     ;FCCF now in MSB
      bpl      ChkDoneErase    ;loop if FCCF = 0

      ldhx     STACK
      txs
      jmp      SUCC            ;refer status back to PC
EraseSubEnd: 
EraseSubSize: equ (*-EraseSub)
;*******************************************************************************************
ProgSub:    
      lda      FSTAT           ;check FCBEF
      and      #mFSTAT_FCBEF   ;mask it
      beq      ProgSub         ;loop if not empty
      
      ldhx     ADRR
      lda      0,x
      aix      #1
      sthx     ADRR
      
      ldhx     ADRS            ;get flash address
      sta      0,x             ;write to flash; latch addr and data
      aix      #1
      sthx     ADRS
      
      lda      #mBurstProg     ;get flash command
      sta      FCMD            ;write the flash command
      lda      #mFSTAT_FCBEF   ;mask to initiate command
      sta      FSTAT           ;[pwpp] register command
      dbnz     LEN,ProgSub     ;all bytes in a row?
ChkDoneProg: 
      lda      FSTAT           ;[prpp] so FCCF is valid
      lsla                     ;FCCF now in MSB
      bpl      ChkDoneProg     ;loop if FCCF = 0
      
      ldhx     STACK
      txs
      jmp      SUCC            ;refer status back to PC
ProgSubEnd: 
ProgSubSize: equ (*-ProgSub)
;*******************************************************************************************
END            

