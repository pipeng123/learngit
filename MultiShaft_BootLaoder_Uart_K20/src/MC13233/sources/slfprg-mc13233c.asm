;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-mc13233c.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    MC13233x main bootloader file
;      Platform:       HCS08
;      $Version: 10.0.4.0$
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

; label HISPEED => if defined, 38400Bd is used instead of 9600Bd

    include "mc13233c.inc"


RCS_ENA     EQU    1        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS         EQU    $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU    0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU    10      ; FC protocol version number

IDENTS      MACRO
 
            DC.B   'MC13233C'    ; MC13233 string

          IFDEF IRQOPTION
            DC.B   '-irq'        ; IRQ option used
          ENDIF

            DC.B   0
            ENDM

ERBLK_LEN   EQU    1024
WRBLK_LEN   EQU    128      

ADDR24    MACRO
            DC.B   (\1) / $10000
            DC.W   (\1) & $0FFFF
          ENDM

   
REL_VECT    EQU    $FBA0   ; newly relocated int. vectors
INT_VECT    EQU    $FFC0   ; start of table of original vectors

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
         XDEF   VEC26
         XDEF   VEC27
         XDEF   VEC28
         XDEF   VEC29
         XDEF   VEC30
         XDEF   VEC31

         XDEF   main
;*******************************************************************************************
  
WR_DATA  EQU    'W'
RD_DATA  EQU    'R'
ENDPRG   EQU    'Q'
ERASE    EQU    'E'
ACK      EQU    $FC
IDENT    EQU    'I'

T100MS   EQU    255

ILOP     MACRO
         STOP      ; illegal as of this config
            ;DC.W    $9E9E   ; this is illegal operation code for CPUV4
         ENDM
;*******************************************************************************************
MY_ZEROPAGE:    SECTION  SHORT

ADRS:    DS.W   1
ADRR:    DS.W   1
LEN:     DS.B   1
STAT:    DS.B   1
STACK:   DS.W   1

DEFAULT_RAM:    SECTION

DATA:    DS.B   WRBLK_LEN

;*******************************************************************************************
DEFAULT_ROM:    SECTION
     
ID_STRING:
        DC.B    3               ; number of Flash blocks
        ADDR24  ROMStart        ; START ADDRESS OF FLASH   
        ADDR24  REL_VECT        ; END ADDRESS OF FLASH                                                                      
        ADDR24  PPAGE_2Start
        ADDR24  PPAGE_2End+1
        ADDR24  PPAGE_4Start
        ADDR24  PPAGE_4End+1

        DC.W    REL_VECT       ; POINTER TO APPLICATION VECTOR TABLE
        DC.W    INT_VECT       ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W    ERBLK_LEN      ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W    WRBLK_LEN      ; WRITE BLCK LENGTH OF FLASH ALG.

      IDENTS
ID_STRING_END:

        XDEF   MY_NVPROT   
        XDEF   MY_NVOPT    

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
VEC0:   JMP    main            ; vector 0
VEC1:   JMP    main            ; vector 1
VEC2:   JMP    main            ; vector 2
VEC3:   JMP    main            ; vector 3
VEC4:   JMP    main            ; vector 4
VEC5:   JMP    main            ; vector 5
VEC6:   JMP    main            ; vector 6
VEC7:   JMP    main            ; vector 7
VEC8:   JMP    main            ; vector 8
VEC9:   JMP    main            ; vector 9
VEC10:  JMP    main            ; vector 10
VEC11:  JMP    main            ; vector 11
VEC12:  JMP    main            ; vector 12
VEC13:  JMP    main            ; vector 13
VEC14:  JMP    main            ; vector 14
VEC15:  JMP    main            ; vector 15
VEC16:  JMP    main            ; vector 16
VEC17:  JMP    main            ; vector 17
VEC18:  JMP    main            ; vector 18
VEC19:  JMP    main            ; vector 19
VEC20:  JMP    main            ; vector 20
VEC21:  JMP    main            ; vector 21
VEC22:  JMP    main            ; vector 22
VEC23:  JMP    main            ; vector 23
VEC24:  JMP    main            ; vector 24
VEC25:  JMP    main            ; vector 25
VEC26:  JMP    main            ; vector 26
VEC27:  JMP    main            ; vector 27
VEC28:  JMP    main            ; vector 28
VEC29:  JMP    main            ; vector 29
VEC30:  JMP    main            ; vector 30
VEC31:  JMP    main            ; vector 31
  
;*******************************************************************************************
NVPROT_ROM:    SECTION
MY_NVPROT      DC.B   %11111101 ; flash protected (from 0xFC00), this is a smallest block on QE

NVOPT_ROM:      SECTION
MY_NVOPT       DC.B   %10000010   ; backdoor enable, (un)secured flash [last 10]

DEFAULT_ROM:   SECTION
;*******************************************************************************************
main:
    IFDEF IRQOPTION
      BIH      PVEC0                   ; if IRQ high, jump directly to real app.
    ENDIF
      LDA      SRS                     ; fetch RESET status reg.
      TSTA                             ; check if zero (this happens if RESET pulse is too short)
      BEQ      slfprg                  ; if so, jump to self programming                
      AND      #%11000000              ; mask only POR and PIN RESET source      
      BNE      slfprg                  ; any of these sources, go to self programming
PVEC0:
      JMP      VEC0                          ; jump to relocated application!

slfprg:        
      LDA      #%00000010
      STA      SOPT1                         ; COP disable, BDM enable (for now)
   
      LDA      #%00001100
      STA      SOMC1
        
      LDA      #%10011110
      STA      SOMC2
        
      LDA      FSTAT
      ORA      #mFSTAT_FACCERR
      STA      FSTAT                      ; clear any FACCERR flag

      LDA      #80                        ; div by 40 to fit into 150-200kHz Flash clock!
      STA      FCDIV
        
      LDA      #(mSCIC2_RE|mSCIC2_TE)
      STA      SCIC2                      ; transmit & receive enable
      CLRA
      STA      SCIBDH

     IFNDEF HISPEED
      LDA      #104
      STA      SCIBDL                       ; BUS (8M)/(16 * 52) = 9600Bd
     ELSE
      LDA      #26
      STA      SCIBDL                       ; BUS (8M)/(16 * 13) = 38400Bd
     ENDIF
      CLRA
      STA      SCIC3

      LDA      SCIS1
      LDA      #ACK
      STA      SCID

      LDX      #T100MS
L2:   CLRA
L1:   PSHA
      LDA      SCIS1
      AND      #mSCIS1_RDRF
      BNE      CAUGHT
      PULA
      DBNZA    L1
      DBNZX    L2

ILOP:
;       timeout
      ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
      BSR      READ

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
IDENT_COM:                        ; TRANSFER OF IDENTIFICATION STRING
      LDA      #(VER_NUM | RCS)  ; version number & "Read command supported" flag
      BSR      WRITE
      LDA      SDIDH                 ; system device identification 1 register (high)
      BSR      WRITE
      LDA      SDIDL                 ; system device identification 1 register (low)
      BSR      WRITE

      MOV      #ID_STRING_END-ID_STRING, LEN
      LDHX     #ID_STRING
      BSR      WRITE_LOOP
                 
      BRA      BCKGND            ; finish without ACK
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
      STA      PPAGE
      BSR      READ
      STA      ADRS
      BSR      READ
      STA      ADRS+1
      BSR      READ
      STA      LEN
      LDHX     ADRS
      
      BSR      WRITE_LOOP
               
      BRA      BCKGND            ; finish without ACK
    ENDIF

;*******************************************************************************************
WRITE:   
      PSHA
WRITE1:
      LDA      SCIS1
      AND      #mSCIS1_TC
      BEQ      WRITE1
      PULA
      STA      SCID
      RTS

READ:
      LDA      SCIS1
      AND      #mSCIS1_RDRF
      BEQ      READ

      LDA      SCID
      RTS

;*******************************************************************************************
ERASE_COM:
      BSR      READ
      STA      PPAGE
      BSR      READ
      STA      ADRS
      BSR      READ
      STA      ADRS+1

      lda      #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
      sta      FSTAT                   ;abort any command and clear errors

      mov      #LOW(EraseSubSize), STAT   ;length of flash erase routine to STAT
      tsx
      sthx     STACK
      ldhx     #EraseSubEnd-1         ;point at last byte to move to stack

      bra      DoOnStack              ;execute prog code from stack RAM
;*******************************************************************************************
WR_DATA_COM:
      BSR      READ
      STA      PPAGE
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

      mov      #LOW(ProgSubSize), STAT      ;length of flash prog routine to STAT
      tsx
      sthx     STACK
      ldhx     #ProgSubEnd-1           ;point at last byte to move to stack

;      bra    DoOnStack                ;execute prog code from stack RAM
      ; fallthru to DoOnStack
;*******************************************************************************************
DoOnStack: 
      lda      ,x               ;read from flash
      psha                      ;move onto stack
      aix      #-1              ;next byte to move
      dbnz     STAT, DoOnStack
      tsx                       ;point to sub on stack
      jmp      ,x               ;execute the sub on the stack (will return on it's own)      
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
      jmp      SUCC             ;refer status back to PC
EraseSubEnd: 
EraseSubSize:  equ (*-EraseSub)
;*******************************************************************************************
ProgSub:    
      lda      FSTAT          ;check FCBEF
      and      #mFSTAT_FCBEF  ;mask it
      beq      ProgSub        ;loop if not empty
      
      ldhx     ADRR
      lda      0,x
      aix      #1
      sthx     ADRR
      
      ldhx     ADRS           ;get flash address
      sta      0,x            ;write to flash; latch addr and data
      aix      #1
      sthx     ADRS
      
      lda      #mBurstProg    ;get flash command
      sta      FCMD           ;write the flash command
      lda      #mFSTAT_FCBEF       ;mask to initiate command
      sta      FSTAT          ;[pwpp] register command
      dbnz     LEN,ProgSub    ;all bytes in a row?
ChkDoneProg: 
      lda      FSTAT          ;[prpp] so FCCF is valid
      lsla                    ;FCCF now in MSB
      bpl      ChkDoneProg    ;loop if FCCF = 0
      
      ldhx     STACK
      txs
      jmp      SUCC           ;refer status back to PC
ProgSubEnd: 
ProgSubSize: equ (*-ProgSub)
;*******************************************************************************************
END            

