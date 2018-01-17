;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-s08jm.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    S08JM main bootloader file
;      Platform:       HCS08
;      $Version: 9.0.7.0$
;      $Date: Sep-10-2012$ 
;      $Last Modified By: r30323$
;      Company:        Freescale Semiconductor
;      Security:       General Business
;
; =================================================================== 
; Copyright (c):      Freescale Semiconductor, 2008, All rights reserved.
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

; labels SCI, SIZE and IRQOPTION defined externally:
; SIZE = 16, 32, 60 depending whether what memory size of JM family is required
; 
; IRQOPTION *NOT* defined >> regular version (bootloader starts always after POR)
; IRQOPTION defined >> using IRQ option (bootloading won't start if IRQ high)
;
; label SCI = 1, 2 selects what SCI channel is used
; label HISPEED => if defined, 38400Bd is used instead of 9600Bd


;!!!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;!!!
;!!!   This S08JM bootloader requires hc08sprg.exe of version 9.0.37.0 or higher
;!!!
;!!!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


    include "mc9s08jm60.inc"

   IFNDEF SCI
SCI      EQU      1
   ENDIF   

PF       equ    0
FE       equ    1
NF       equ    2
OR       equ    3
IDLE     equ    4
RDRF     equ    5
TC       equ    6
TDRE     equ    7

   IF SCI = 1
SCIBDH   equ    SCI1BDH
SCIBDL   equ    SCI1BDL
SCC1     equ    SCI1C1
SCC2     equ    SCI1C2
SCC3     equ    SCI1C3
SCS1     equ    SCI1S1
SCS2     equ    SCI1S2
SCDR     equ    SCI1D

   ENDIF

   IF SCI = 2
SCIBDH   equ    SCI2BDH
SCIBDL   equ    SCI2BDL
SCC1     equ    SCI2C1
SCC2     equ    SCI2C2
SCC3     equ    SCI2C3
SCS1     equ    SCI2S1
SCS2     equ    SCI2S2
SCDR     equ    SCI2D

   ENDIF


RCS_ENA     EQU     1        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS         EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU     2        ; FC protocol version number

IDENTS      MACRO

            DC.B   'JM'

          IF SIZE = 16
            DC.B     '16'    ; 16kB string
          ENDIF
          IF SIZE = 32
            DC.B     '32'    ; 32kB string
          ENDIF
          IF SIZE = 60
            DC.B     '60'    ; 60kB string
          ENDIF

          IFDEF IRQOPTION
            DC.B     '-irq'     ; IRQ option used
          ENDIF

            DC.B    0
            ENDM

ERBLK_LEN   EQU      512
WRBLK_LEN   EQU      64      

ADDR24  MACRO
          DC.B  (\1) / $10000
          DC.W  (\1) & $0FFFF
        ENDM

          IF SIZE = 16
FLS_BEG      EQU      $C000   ; FLASH #0 block start
FLS_END      EQU      $FDC0   ; FLASH #0 block end
NFLBLKS      EQU      1       ; one continuous block
        ENDIF

          IF SIZE = 32
FLS_BEG      EQU      $8000   ; FLASH #0 block start
FLS_END      EQU      $FDC0   ; FLASH #0 block end
NFLBLKS      EQU      1       ; one continuous block
        ENDIF

          IF SIZE = 60
FLS_BEG      EQU      $10B0   ; FLASH #0 block start
FLS_END      EQU      $1800   ; FLASH #0 block end
FLS_BEG1     EQU      $1960   ; FLASH #1 block start
FLS_END1     EQU      $FDC0   ; FLASH #1 block end
NFLBLKS      EQU      2       ; two continuous blocks
        ENDIF
         
REL_VECT     EQU      $FDC0   ; newly relocated int. vectors
INT_VECT     EQU      $FFC0   ; start of table of original vectros!


         XDEF   main
;*******************************************************************************************
  
WR_DATA      EQU       'W'
RD_DATA      EQU       'R'
ENDPRG       EQU       'Q'
ERASE        EQU       'E'
ACK          EQU       $FC
IDENT        EQU       'I'

T100MS       EQU       255

ILOP        MACRO
             DC.B    $8d             ; this is illegal operation code
            ENDM
;*******************************************************************************************
MY_ZEROPAGE:  SECTION  SHORT

ADRS:    DS.W   1
ADRR:    DS.W   1
ADRH:    DS.B   1
LEN:     DS.B   1
BSTAT:   DS.B   1
STACK:   DS.W   1

DEFAULT_RAM:  SECTION

DATA:  DS.B   WRBLK_LEN

;*******************************************************************************************
DEFAULT_ROM:  SECTION
     
ID_STRING:
       DC.B   NFLBLKS         ; number of Flash blocks
       DC.W   FLS_BEG         ; START ADDRESS OF FLASH   
       DC.W   FLS_END         ; END ADDRESS OF FLASH   
      IF NFLBLKS >= 2
       DC.W   FLS_BEG1        ; START ADDRESS OF FLASH #2
       DC.W   FLS_END1        ; END ADDRESS OF FLASH    #2
      ENDIF        
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
MY_NVPROT   DC.B   %11111100     ; flash protected (from 0xFE00) 

NVOPT_ROM:       SECTION
MY_NVOPT    DC.B   %00000010   ; redirection enable, (un)secured flash [last 10]

DEFAULT_ROM:     SECTION
;*******************************************************************************************
main:
    IFDEF IRQOPTION
      BIH     PVEC0                   ; if IRQ high, jump directly to real app.
    ENDIF
      LDA     SRS                     ; fetch RESET status reg.
      TSTA                            ; check if zero (this happens if RESET pulse is too short)
      BEQ     slfprg                  ; if so, jump to self programming                
      AND     #%11000000              ; mask only POR and PIN RESET source      
      BNE     slfprg                  ; any of these sources, go to self programming
PVEC0:        
      LDHX    #(REL_VECT|$00FF)&$FFFE   ; there should be relocated reset vector of the new app.
      LDA     ,X
      PSHA
      AND     1,X
      LDX     1,X
      PULH
      INCA
      BEQ     slfprg               ; don't jump if empty vector!
      JMP     ,X                  ; jump to relocated application!

slfprg:        
      LDA     NVMCGTRM
      STA     MCGTRM

      LDA     NVFTRIM
      ORA     MCGSC
      STA     MCGSC

      LDA      #%00000000
      STA      SOPT1               ; COP disable, SCI2PS as needed
      
         ; f(BUS) defaults to 8MHz
    
      LDA      FSTAT
      ORA      #mFSTAT_FACCERR                            
      STA      FSTAT               ; clear any FACCERR flag

      LDA      #40                  ; div by 36+1 to fit into 150-200kHz Flash clock!
      STA      FCDIV
        
      MOV      #%00001100,SCC2        ; transmit & receive enable
      CLR      SCIBDH

     IFNDEF HISPEED
      MOV      #52, SCIBDL            ; BUS (8M)/(16 * 52) = 9600Bd
     ELSE
      MOV      #13, SCIBDL            ; BUS (8M)/(16 * 13) = 38400Bd
     ENDIF
      CLR      SCC3

; OPTIONAL DELAY - if your RS232 hardware is lazy, uncomment following delay

;        CLRX
;DLY2:   CLRA
;DLY1:   NOP
;        
;        DBNZA   DLY1
;        DBNZX   DLY2
;

      LDA      SCS1
      MOV      #ACK,SCDR

      LDX      #T100MS
L2:   CLRA
L1:   BRSET    RDRF,SCS1,CAUGHT
      DBNZA    L1
      DBNZX    L2
ILOP:
;       timeout
      ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
      BSR      READ
      CBEQA    #ACK, SUCC       ; Got ACK!

      ILOP          ; generate RESET by doing illegal operation
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
      LDA      #(VER_NUM | RCS)  ; version number & "Read command supported" flag
      BSR      WRITE
      LDA      SDIDH         ; system device identification 1 register (high)
      BSR      WRITE
      LDA      SDIDL         ; system device identification 1 register (low)
      BSR      WRITE

      MOV      #ID_STRING_END-ID_STRING, LEN
      LDHX     #ID_STRING
      BSR      WRITE_LOOP
                 
      BRA      BCKGND          ; finish without ACK
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

      BSR      READ
      STA      ADRS
      BSR      READ
      STA      ADRS+1
      BSR      READ
      STA      LEN
      LDHX     ADRS
        
      BSR      WRITE_LOOP

      BRA      BCKGND          ; finish without ACK
    ENDIF

;*******************************************************************************************
WRITE:   
      BRCLR    TC,SCS1,WRITE
      STA      SCDR
      RTS
READ:
      BRCLR    RDRF,SCS1,READ
      LDA      SCDR
      RTS
;*******************************************************************************************
ERASE_COM:
      BSR      READ
      STA      ADRS
      BSR      READ
      STA      ADRS+1

      lda      #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
      sta      FSTAT                   ;abort any command and clear errors

      mov      #LOW(EraseSubSize), BSTAT   ;length of flash erase routine to BSTAT
      tsx
      sthx     STACK
      ldhx     #EraseSubEnd-1        ;point at last byte to move to stack

      bra      DoOnStack              ;execute prog code from stack RAM
;*******************************************************************************************
WR_DATA_COM:
      BSR      READ
      STA      ADRS
      BSR      READ
      STA      ADRS+1
      BSR      READ
      STA      BSTAT
      STA      LEN
      LDHX     #DATA
      STHX     ADRR
WR_DATA_L1:
      BSR      READ
      STA      ,X
      AIX      #1
      DBNZ     BSTAT,WR_DATA_L1
      
      lda      #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
      sta      FSTAT             ;abort any command and clear errors

      mov      #LOW(ProgSubSize), BSTAT   ;length of flash prog routine to BSTAT
      tsx
      sthx     STACK
      ldhx     #ProgSubEnd-1      ;point at last byte to move to stack

;      bra     DoOnStack          ;execute prog code from stack RAM
      ; fallthru to this routine
;*******************************************************************************************
DoOnStack: 
      lda      ,x           ;read from flash
      psha                  ;move onto stack
      aix      #-1          ;next byte to move
      dbnz     BSTAT, DoOnStack
      tsx                   ;point to sub on stack
      jmp      ,x           ;execute the sub on the stack (will return on it's own)      
;*******************************************************************************************
EraseSub:    
      ldhx     ADRS           ;get flash address
      sta      0,x            ;write to flash; latch addr and data
      lda      #mPageErase    ;get flash command
      sta      FCMD           ;write the flash command
      lda      #mFSTAT_FCBEF       ;mask to initiate command
      sta      FSTAT          ;[pwpp] register command
      nop                     ;[p] want min 4~ from w cycle to r
ChkDoneErase: 
      lda      FSTAT          ;[prpp] so FCCF is valid
      lsla                    ;FCCF now in MSB
      bpl      ChkDoneErase   ;loop if FCCF = 0

      ldhx     STACK
      txs
      jmp      SUCC          ;refer status back to PC
EraseSubEnd: 
EraseSubSize:  equ (*-EraseSub)
;*******************************************************************************************
ProgSub:    
      lda      FSTAT           ;check FCBEF
      and      #mFSTAT_FCBEF   ;mask it
      beq      ProgSub         ;loop if not empty
      
      ldhx     ADRR
      lda      0,x
      aix      #1
      sthx     ADRR
      
      ldhx     ADRS          ;get flash address
      sta      0,x           ;write to flash; latch addr and data
      aix      #1
      sthx     ADRS
      
      lda      #mBurstProg    ;get flash command
      sta      FCMD           ;write the flash command
      lda      #mFSTAT_FCBEF  ;mask to initiate command
      sta      FSTAT          ;[pwpp] register command
      dbnz     LEN,ProgSub    ;all bytes in a row?
ChkDoneProg: 
      lda      FSTAT          ;[prpp] so FCCF is valid
      lsla                    ;FCCF now in MSB
      bpl      ChkDoneProg    ;loop if FCCF = 0
      
      ldhx     STACK
      txs
      jmp      SUCC          ;refer status back to PC
ProgSubEnd: 
ProgSubSize: equ (*-ProgSub)
;*******************************************************************************************
END            

