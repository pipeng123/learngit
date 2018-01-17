;*********************************************************************
; HEADER_START
;
;      $File Name: slfprg-s08dz128.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    S08DZ128 main bootloader file
;      Platform:       HCS08
;      $Version: 11.0.13.0$
;      $Date: Sep-17-2012$ 
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
; SIZE = 96, 128 depending whether what memory size of DZ/DV family is required
; if EEPROM is defined -> DZ family used (EEPROM support)
; if EEPROM is *NOT* defined, it defaults to DV family (no EEPROM support)
; 
; IRQOPTION *NOT* defined >> regular version (bootloader starts always after POR)
; IRQOPTION defined >> using IRQ option (bootloading won't start if IRQ high)
;
; label SCI = 1, 2 selects what SCI channel is used
; label HISPEED => if defined, 38400Bd is used instead of 9600Bd


;!!!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;!!!
;!!!   This S08DZ128 bootloader requires hc08sprg.exe of version 9.0.41.0 or higher
;!!!
;!!!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


    include "mc9s08dz128.inc"

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
SCIBDH   equ SCI1BDH
SCIBDL   equ SCI1BDL
SCC1     equ SCI1C1
SCC2     equ SCI1C2
SCC3     equ SCI1C3
SCS1     equ SCI1S1
SCS2     equ SCI1S2
SCDR     equ SCI1D

   ENDIF

   IF SCI = 2
SCIBDH   equ SCI2BDH
SCIBDL   equ SCI2BDL
SCC1     equ SCI2C1
SCC2     equ SCI2C2
SCC3     equ SCI2C3
SCS1     equ SCI2S1
SCS2     equ SCI2S2
SCDR     equ SCI2D

   ENDIF


RCS_ENA    EQU     1        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS        EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS        EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM    EQU     $06      ; FC protocol version number (S08 long)
                            ; same as protocol version 2
                            ; except that Erase block is not
                            ; sized as power of two, just for compatibility
                            ; reasons ie. this bootloader will abort if used
                            ; with old version of hc08sprg.exe (that does not yet
                            ; support this 'non-binary' page sizes)
                            ; plus it has 24 bits addressing

IDENTS   MACRO

          IFDEF EEPROM
           DC.B   'DZ'
          ELSE
           DC.B   'DV'
          ENDIF

          IF SIZE = 96
           DC.B     '96'    ; 96kB string
          ENDIF
          IF SIZE = 128
           DC.B     '128'   ; 128kB string
          ENDIF

          IFDEF IRQOPTION
           DC.B     '-irq'     ; IRQ option used
          ENDIF

           DC.B    0
         ENDM

ERBLK_LEN  EQU      512
WRBLK_LEN  EQU      128      
EEBLK_LEN  EQU      8

ADDR24  MACRO
           DC.B  (\1) / $10000
           DC.W  (\1) & $0FFFF
        ENDM

         IFDEF EEPROM
EEP_BEG    EQU   $3C00   ; EEPROM #0 block start
EEP_END    EQU   $4000   ; EEPROM page 0 end
                        ; EEPROM page 1 is $10000 higher
         ENDIF
   
REL_VECT   EQU   $DF90   ; newly relocated int. vectors


INT_VECT   EQU   $FF90   ; start of table of original vectros!


         XDEF   main
;*******************************************************************************************
  
WR_DATA    EQU       'W'
RD_DATA    EQU       'R'
ENDPRG     EQU       'Q'
ERASE      EQU       'E'
ACK        EQU       $FC
IDENT      EQU       'I'

T100MS     EQU       255

ILOP        MACRO
            STOP      ; illegal as of this config
            ;DC.W    $9E9E   ; this is illegal operation code for CPUV4
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
          IF SIZE = 96
      IFDEF EEPROM                ; DZ96
          DC.B   5                ; number of Flash blocks
        ADDR24  $1900            
        ADDR24  REL_VECT                                                                  
        ADDR24  EEP_BEG + $10000  ; second half of EEPROM 
        ADDR24  EEP_END + $10000                                                         
      ELSE                        ; DV96
          DC.B   5                ; number of Flash blocks
        ADDR24  $1080       
        ADDR24  $1800                                                                    
        ADDR24  $1900       
        ADDR24  REL_VECT                                                                 
      ENDIF
        ADDR24  PPAGE_2Start
        ADDR24  PPAGE_2End+1
        ADDR24  PPAGE_4Start
        ADDR24  PPAGE_4End+1 
        ADDR24  PPAGE_5Start
        ADDR24  PPAGE_5End+1 
          ENDIF

          IF SIZE = 128
      IFDEF EEPROM                ; DZ128
          DC.B   7                ; number of Flash blocks
        ADDR24  $2180            
        ADDR24  REL_VECT                                                           
        ADDR24  EEP_BEG + $10000  ; second half of EEPROM
        ADDR24  EEP_END + $10000                                                  
      ELSE                        ; DV128
          DC.B   6                ; number of Flash blocks
        ADDR24  $1900           
        ADDR24  REL_VECT                                                      
      ENDIF
        ADDR24  PPAGE_2Start
        ADDR24  PPAGE_2End+1
        ADDR24  PPAGE_4Start
        ADDR24  PPAGE_4End+1 
        ADDR24  PPAGE_5Start
        ADDR24  PPAGE_5End+1 
        ADDR24  PPAGE_6Start
        ADDR24  PPAGE_6End+1 
        ADDR24  PPAGE_7Start
        ADDR24  PPAGE_7End+1 
          ENDIF

        DC.W   REL_VECT           ; POINTER TO APPLICATION VECTOR TABLE
        DC.W   INT_VECT           ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W   ERBLK_LEN          ; ERASE BLOCK LENGTH OF FLASH ALG.
        DC.W   WRBLK_LEN          ; WRITE BLOCK LENGTH OF FLASH ALG.

      IDENTS
ID_STRING_END:


;*******************************************************************************************
  XDEF    MY_NVPROT
NVPROT_ROM:     SECTION
MY_NVPROT     DC.B   %11111101   ; flash protected & redirected (from 0xE000), this is a smallest block on DZ128 :(
                                 ; EEPROM unprotected

  XDEF    MY_NVOPT
NVOPT_ROM:      SECTION
MY_NVOPT      DC.B   %00100010   ; backdoor enable, redirection enable, (un)secured flash [last 10], 8 byte EEPROM

DEFAULT_ROM:      SECTION
;*******************************************************************************************
main:
    IFDEF IRQOPTION
         BIH       PVEC0                   ; if IRQ high, jump directly to real app.
    ENDIF
         LDA       SRS                     ; fetch RESET status reg.
    IFDEF RESETPINOPTION
         TSTA                              ; check if zero (this happens if RESET pulse is too short)
         BEQ       slfprg                  ; if so, jump to self programming                
         AND       #%11000000              ; mask only POR and PIN RESET source      
    ELSE
         AND       #%10000000              ; mask only POR RESET source      
    ENDIF     
         BNE       slfprg                  ; any of these sources, go to self programming
PVEC0:        
         LDHX      #(REL_VECT|$00FF)&$FFFE ; there should be relocated reset vector of the new app.
         LDA       ,X
         PSHA
         AND       1,X
         LDX       1,X
         PULH
         INCA
         BEQ       slfprg                  ; don't jump if empty vector
         JMP       ,X                      ; jump to relocated application

slfprg:        
         LDA       NVMCGTRM
         STA       MCGTRM

         LDA       NVFTRIM
         ORA       MCGSC
         STA       MCGSC

         LDA       #%00000000
         STA       SOPT1                   ; COP disable, SCI2PS as needed, STOP disabled
          
            ; f(BUS) defaults to 16MHz
            
         LDA       FSTAT
         ORA       #mFSTAT_FACCERR                            
         STA       FSTAT                   ; clear any FACCERR flag

         LDA       #39                     ; div by 39+1 to fit into 150-200kHz Flash clock
         STA       FCDIV                
        
         MOV       #%00001100,SCC2         ; transmit & receive enable
         CLR       SCIBDH

     IFNDEF HISPEED
         MOV       #52, SCIBDL             ; BUS (8M)/(16 * 52) = 9600Bd
     ELSE
         MOV       #13, SCIBDL             ; BUS (8M)/(16 * 13) = 38400Bd
     ENDIF
         CLR       SCC3

; OPTIONAL DELAY - if your RS232 hardware is lazy, uncomment following delay

;        CLRX
;DLY2:   CLRA
;DLY1:   NOP
;        
;        DBNZA     DLY1
;        DBNZX     DLY2
;

          LDA      SCS1
          MOV      #ACK,SCDR

          LDX      #T100MS
L2:       CLRA
L1:       BRSET    RDRF,SCS1,CAUGHT
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
       IFDEF EEPROM
EECHECK:
          DBNZA    EPAGE0
          LDA      #mFCNFG_EPGSEL        
          BRA      ECFG
EPAGE0:   CLRA     
ECFG:     STA      FCNFG        
          RTS
       ENDIF
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
          STA      PPAGE   
       IFDEF EEPROM
          BSR      EECHECK   
       ENDIF
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
          STA      PPAGE
       IFDEF EEPROM
          BSR      EECHECK   
       ENDIF
          BSR      READ
          STA      ADRS
          BSR      READ
          STA      ADRS+1

       IFDEF EEPROM
          LDHX     ADRS             ; any EEPROM page?
          CPHX     #EEP_END
          BHS      E_FLASH          ; if EEP_END <= ADRS (ie. FLASH)

          CPHX     #EEP_BEG
          BHS      E_EEPROM          ; if EEP_BEG <= ADRS (ie. EEPROM)
       ENDIF

E_FLASH:
          lda      #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
          sta      FSTAT                   ;abort any command and clear errors

          mov      #LOW(EraseSubSize), STAT   ;length of flash erase routine to STAT
          tsx
          sthx     STACK
          ldhx     #EraseSubEnd-1        ;point at last byte to move to stack

          bra      DoOnStack              ;execute prog code from stack RAM
;*******************************************************************************************
WR_DATA_COM:
          BSR      READ
          STA      PPAGE   
       IFDEF EEPROM
          JSR      EECHECK   
       ENDIF
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
          sta      FSTAT             ;abort any command and clear errors

          mov      #LOW(ProgSubSize), STAT   ;length of flash prog routine to STAT
          tsx
          sthx     STACK
          ldhx     #ProgSubEnd-1      ;point at last byte to move to stack

;      bra    DoOnStack          ;execute prog code from stack RAM
      ; fallthru to this routine
;*******************************************************************************************
DoOnStack: 
          lda      ,x           ;read from flash
          psha                  ;move onto stack
          aix      #-1          ;next byte to move
          dbnz     STAT, DoOnStack
          tsx                   ;point to sub on stack
          jmp      ,x           ;execute the sub on the stack (will return on it's own)      
;*******************************************************************************************
;*******************************************************************************************
       IFDEF EEPROM
E_EEPROM:         
          clra

E_EEPROM2:         
          psha        
        
          STA      ,X      ;latch the unprotected address from H:X
          NOP             ;brief delay to allow the command state machine to start
          STA      ,X      ;intentionally cause an access error to abort this command          
        ; see errata
          
          lda      #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
          sta      FSTAT                   ;abort any command and clear errors

          sta      0,x             ;write to flash; latch addr and data
          lda      #mPageErase     ;get flash command
          sta      FCMD            ;write the flash command
          lda      #mFSTAT_FCBEF   ;mask to initiate command
          sta      FSTAT           ;[pwpp] register command
          nop                      ;[p] want min 4~ from w cycle to r
ChkDoneEErase: 
          lda      FSTAT           ;[prpp] so FCCF is valid
          lsla                     ;FCCF now in MSB
          bpl      ChkDoneEErase   ;loop if FCCF = 0

          aix      #EEBLK_LEN               ; increment EEprom address
          pula
          inca
          
          cmp      #(ERBLK_LEN/EEBLK_LEN)   ; Flash erase page / EEprom erase page
          blo      E_EEPROM2
        
          jmp      SUCC           ;refer status back to PC
       ENDIF
;*******************************************************************************************
;*******************************************************************************************
EraseSub:    
          ldhx     ADRS          ;get flash address
          sta      0,x          ;write to flash; latch addr and data
          lda      #mPageErase    ;get flash command
          sta      FCMD          ;write the flash command
          lda      #mFSTAT_FCBEF       ;mask to initiate command
          sta      FSTAT          ;[pwpp] register command
          nop                ;[p] want min 4~ from w cycle to r
ChkDoneErase: 
          lda      FSTAT          ;[prpp] so FCCF is valid
          lsla                ;FCCF now in MSB
          bpl      ChkDoneErase    ;loop if FCCF = 0

          ldhx     STACK
          txs
          jmp      SUCC          ;refer status back to PC
EraseSubEnd: 
EraseSubSize: equ (*-EraseSub)
;*******************************************************************************************
ProgSub:    
          lda      FSTAT          ;check FCBEF
          and      #mFSTAT_FCBEF       ;mask it
          beq      ProgSub         ;loop if not empty
          
          ldhx     ADRR
          lda      0,x
          aix      #1
          sthx     ADRR
          
          ldhx     ADRS          ;get flash address
          sta      0,x          ;write to flash; latch addr and data
          aix      #1
          sthx     ADRS
          
          lda      #mBurstProg    ;get flash command
          sta      FCMD          ;write the flash command
          lda      #mFSTAT_FCBEF       ;mask to initiate command
          sta      FSTAT          ;[pwpp] register command
          dbnz     LEN,ProgSub      ;all bytes in a row?
ChkDoneProg: 
          lda      FSTAT          ;[prpp] so FCCF is valid
          lsla                ;FCCF now in MSB
          bpl      ChkDoneProg    ;loop if FCCF = 0
          
          ldhx     STACK
          txs
          jmp      SUCC          ;refer status back to PC
ProgSubEnd: 
ProgSubSize: equ (*-ProgSub)
;*******************************************************************************************
END            

