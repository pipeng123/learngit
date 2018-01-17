;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-s08gw.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    S08GW main bootloader file
;      Platform:       HCS08
;      $Version: 10.0.4.0$
;      $Date: Sep-10-2012$ 
;      $Last Modified By: r30323$
;      Company:        Freescale Semiconductor
;      Security:       General Business
;
; =================================================================== 
; Copyright (c):      Freescale Semiconductor, 2012, All rights reserved.
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

; labels SIZE and IRQOPTION defined externally:
; SIZE = 32, 64 depending whether what memory size of GW family is required
; 
; IRQOPTION *NOT* defined >> regular version
; IRQOPTION defined >> regular version using IRQ option (bootloading won't start if IRQ high)
;
; label SPEED => if defined, baudrate is specified, otherwise default 9600Bd

    include "mc9s08gw64.inc"


RCS_ENA  EQU     1        ; READ COMMAND SUPPORTED?


   IFNDEF SCI
SCI      EQU      1
   ENDIF   

   IF SCI = 1
SCIBDH      equ SCI1BDH
SCIBDL      equ SCI1BDL
SCC1        equ SCI1C1
SCC2        equ SCI1C2
SCC3        equ SCI1C3
SCS1        equ SCI1S1
SCS2        equ SCI1S2
SCDR        equ SCI1D

TXDDDR      EQU     PTBDD
TXDPORT     EQU     PTBD
TXDBIT      EQU     0
RXDPORT     EQU     PTBD
RXDBIT      EQU     1
   ENDIF

   IF SCI = 2
SCIBDH      equ SCI2BDH
SCIBDL      equ SCI2BDL
SCC1        equ SCI2C1
SCC2        equ SCI2C2
SCC3        equ SCI2C3
SCS1        equ SCI2S1
SCS2        equ SCI2S2
SCDR        equ SCI2D

TXDDDR      EQU     PTBDD
TXDPORT     EQU     PTBD
TXDBIT      EQU     7
RXDPORT     EQU     PTBD
RXDBIT      EQU     6
   ENDIF

   IF SCI = 3
SCIBDH      equ SCI3BDH
SCIBDL      equ SCI3BDL
SCC1        equ SCI3C1
SCC2        equ SCI3C2
SCC3        equ SCI3C3
SCS1        equ SCI3S1
SCS2        equ SCI3S2
SCDR        equ SCI3D

TXDDDR      EQU     PTGDD
TXDPORT     EQU     PTGD
TXDBIT      EQU     5
RXDPORT     EQU     PTGD
RXDBIT      EQU     4
   ENDIF

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET
TDRE:       equ   7           ;(bit #7) Tx data register empty
TC:         equ   6           ;(bit #6) transmit complete
RDRF:       equ   5           ;(bit #5) Rx data register full
IDLE:       equ   4           ;(bit #4) idle line detected
OR:         equ   3           ;(bit #3) Rx over run
NF:         equ   2           ;(bit #2) Rx noise flag
FE:         equ   1           ;(bit #1) Rx framing error
PF:         equ   0           ;(bit #0) Rx parity failed

mTDRE:      equ    %10000000  ;(bit #7) Tx data register empty
mTC:        equ    %01000000  ;(bit #6) transmit complete
mRDRF:      equ    %00100000  ;(bit #5) Rx data register full
mIDLE:      equ    %00010000  ;(bit #4) idle line detected
mOR:        equ    %00001000  ;(bit #3) Rx over run
mNF:        equ    %00000100  ;(bit #2) Rx noise flag
mFE:        equ    %00000010  ;(bit #1) Rx framing error
mPF:        equ    %00000001  ;(bit #0) Rx parity failed

  IF RCS_ENA = 1
RCS         EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU     $06     ; FC protocol version number (S08 long)
                            ; same as protocol version 2
                            ; except that Erase block is not
                            ; sized as power of two, just for compatibility
                            ; reasons ie. this bootloader will abort if used
                            ; with old version of hc08sprg.exe (that does not yet
                            ; support this 'non-binary' page sizes)
                            ; plus it has 24 bits addressing

IDENTS      MACRO

            DC.B   'GW'

          IF SIZE = 64
            DC.B     '64'    ; 64kB string
          ENDIF
          IF SIZE = 32
            DC.B     '32'    ; 32kB string
          ENDIF

          IFDEF IRQOPTION
            DC.B     '-irq'     ; IRQ option used
          ENDIF

            DC.B    0
            ENDM

ERBLK_LEN   EQU      512
WRBLK_LEN   EQU      128      

ADDR24  MACRO
          DC.B  (\1) / $10000
          DC.W  (\1) & $0FFFF
        ENDM

   
REL_VECT   EQU    $FD96   ; newly relocated int. vectors
INT_VECT   EQU    $FF96   ; start of table of original vectors

         XDEF   main
;*******************************************************************************************
  
WR_DATA      EQU       'W'
RD_DATA      EQU       'R'
ENDPRG       EQU       'Q'
ERASE        EQU       'E'
ACK          EQU       $FC
IDENT        EQU       'I'

T100MS       EQU       255

ILOP      MACRO
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

DATA:     DS.B    WRBLK_LEN

;*******************************************************************************************
DEFAULT_ROM:   SECTION
     
ID_STRING:

    IF SIZE = 32
         DC.B   3        ; number of Flash blocks
         ADDR24  $004000   ; START ADDRESS OF FLASH   
         ADDR24  REL_VECT  ; END ADDRESS OF FLASH                                                                      
         ADDR24  $028000   ; page 2                      ; $8000
         ADDR24  $02C000   ; end of page 2               ; $C000
         ADDR24  $038000   ; page 3                      ; $C000
         ADDR24  $030000 | (REL_VECT & $BFFF)            ; REL_VECT
    ENDIF
 
    IF SIZE = 64
         DC.B   4        ; number of Flash blocks
         ADDR24  $000000   ; START ADDRESS OF FLASH   
         ADDR24  REL_VECT  ; END ADDRESS OF FLASH                                                                      
         ADDR24  $018000   ; page 1                      ; $4000
         ADDR24  $01C000   ; end of page 1               ; $8000
         ADDR24  $028000   ; page 2                      ; $8000
         ADDR24  $02C000   ; end of page 2               ; $C000
         ADDR24  $038000   ; page 3                      ; $C000
         ADDR24  $030000 | (REL_VECT & $BFFF)            ; REL_VECT
    ENDIF


         DC.W    REL_VECT      ; POINTER TO APPLICATION VECTOR TABLE
         DC.W    INT_VECT      ; POINTER TO BEGINING OF FLASH INT. VECTORS
         DC.W    ERBLK_LEN      ; ERASE BLOCK LENGTH OF FLASH ALG.
         DC.W    WRBLK_LEN      ; WRITE BLOCK LENGTH OF FLASH ALG.

         IDENTS
ID_STRING_END:

         XDEF    MY_NVPROT   
         XDEF    MY_NVOPT    
  
;*******************************************************************************************
NVPROT_ROM:      SECTION
MY_NVPROT    DC.B   %11111110   ; flash protected (from 0xFE00), this is a smallest block on GW

NVOPT_ROM:      SECTION
MY_NVOPT     DC.B   %00000010   ; redirection enabled, (un)secured flash [last 10]

DEFAULT_ROM:   SECTION
;*******************************************************************************************
main:
    IFDEF IRQOPTION
         BIH     PVEC0                   ; if IRQ high, jump directly to real app.
    ENDIF
         LDA     SRS                     ; fetch RESET status reg.
         TSTA                            ; check if zero (this happens if RESET pulse is too short)
         BEQ     slfprg                  ; if so, jump to self programming                
         AND     #%11000000              ; mask only POR RESET AND PIN RESET source      
         BNE     slfprg                  ; any of these sources, go to self programming
PVEC0:        
         LDHX    #(REL_VECT|$00FF)&$FFFE ; there should be relocated reset vector of the new app.
         LDA     ,X
         PSHA
         AND     1,X
         LDX     1,X
         PULH
         INCA
         BEQ     slfprg                  ; don't jump if empty vector!
         JMP     ,X                      ; jump to relocated application!

slfprg:        
         LDA     #$80
         STA     ICSTRM

         LDA     #%00000011
         STA     SOPT1                   ; COP disable, BDM enable (for now)
         LDA     #%00000100              ; FEI mode, IREFS = 1
         STA     ICSC1        

         CLRA
         STA     ICSSC                   ; DRS=0 (16-20MHz DCO range)
         STA     ICSC2                   ; BDIV=00 (/1), 16-20MHz, reqd' 16MHz, bus = ICS/2
        
         LDA     FSTAT
         ORA     #mFSTAT_FACCERR
         STA     FSTAT                   ; clear any FACCERR flag

         LDA     #39                     ; div by 40 to fit into 150-200kHz Flash clock!
         STA     FCDIV
        
         BSET    TXDBIT,TXDPORT
         BSET    TXDBIT,TXDDDR           ; TxD high when SCI disabled        

         LDA     #%00001100
         STA     SCC2                    ; transmit & receive enable
         CLRA
         STA     SCC3
         STA     SCIBDH

     IFNDEF SPEED
         LDA     #52
         STA     SCIBDL                  ; BUS (8M)/(16 * 52) = 9600Bd
     ELSE

    IF SPEED==38400
         LDA     #13
         STA     SCIBDL                  ; BUS (8M)/(16 * 13) = 38400Bd
    ELSE IF SPEED==19200
         LDA     #26
         STA     SCIBDL                  ; BUS (8M)/(16 * 26) = 19200Bd
     ENDIF
     ENDIF

         LDA     SCS1
         LDA     #ACK
         STA     SCDR

         LDX     #T100MS
L2:      CLRA
L1:      PSHA
         LDA     SCS1
         AND     #mRDRF
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
         CLRA
         STA     SCC2               ; disable SCI
         JSR     ICSTRIM            ; go & trim
         LDA     #%00001100         ; transmit & receive enable
         STA     SCC2 

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
IDENT_COM:                        ; TRANSFER OF IDENTIFICATION STRING
         LDA     #(VER_NUM | RCS)  ; version number & "Read command supported" flag
         BSR     WRITE
         LDA     SDIDH                 ; system device identification 1 register (high)
         BSR     WRITE
         LDA     SDIDL                 ; system device identification 1 register (low)
         BSR     WRITE

         MOV     #ID_STRING_END-ID_STRING, LEN
         LDHX    #ID_STRING
         BSR     WRITE_LOOP
                 
         BRA     BCKGND            ; finish without ACK
;*******************************************************************************************
WRITE_LOOP:                       ; start address in HX, length in LEN
         LDA     ,X
         BSR     WRITE
         AIX     #1
         DBNZ    LEN, WRITE_LOOP
         RTS
;*******************************************************************************************
      IF RCS_ENA = 1
RD_DATA_COM:
         BSR     READ
         STA     PPAGE
         BSR     READ
         STA     ADRS
         BSR     READ
         STA     ADRS+1

         JSR     MODPPAGE          ; modify addressing

         BSR     READ
         STA     LEN
         LDHX    ADRS
        
         BSR     WRITE_LOOP

         BRA     BCKGND            ; finish without ACK
      ENDIF

;*******************************************************************************************
WRITE:   
         PSHA
WRITE1:
         LDA     SCS1
         AND     #mTC
         BEQ     WRITE1
         PULA
         STA     SCDR
         RTS

READ:
         LDA     SCS1
         AND     #mRDRF
         BEQ     READ

         LDA     SCDR
         RTS

;*******************************************************************************************
ERASE_COM:
         BSR     READ
         STA     PPAGE
         BSR     READ
         STA     ADRS
         BSR     READ
         STA     ADRS+1

         JSR     MODPPAGE            ; modify addressing

         lda     #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
         sta     FSTAT                   ;abort any command and clear errors

         mov     #LOW(EraseSubSize), STAT   ;length of flash erase routine to STAT
         tsx
         sthx    STACK
         ldhx    #EraseSubEnd-1         ;point at last byte to move to stack

         bra     DoOnStack              ;execute prog code from stack RAM
;*******************************************************************************************
WR_DATA_COM:
         BSR     READ
         STA     PPAGE
         BSR     READ
         STA     ADRS
         BSR     READ
         STA     ADRS+1

         BSR     MODPPAGE            ; modify addressing

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
         sta     FSTAT                   ;abort any command and clear errors

         mov     #LOW(ProgSubSize), STAT   ;length of flash prog routine to STAT
         tsx
         sthx    STACK
         ldhx    #ProgSubEnd-1          ;point at last byte to move to stack

;      bra    DoOnStack          ;execute prog code from stack RAM
      ; fallthru to DoOnStack
;*******************************************************************************************
DoOnStack: 
         lda     ,x               ;read from flash
         psha                      ;move onto stack
         aix     #-1            ;next byte to move
         dbnz    STAT, DoOnStack
         tsx                      ;point to sub on stack
         jmp     ,x               ;execute the sub on the stack (will return on it's own)      
;*******************************************************************************************
EraseSub:    
         ldhx    ADRS            ;get flash address
         sta     0,x            ;write to flash; latch addr and data
         lda     #mPageErase ;get flash command
         sta     FCMD            ;write the flash command
         lda     #mFSTAT_FCBEF       ;mask to initiate command
         sta     FSTAT          ;[pwpp] register command
         nop                     ;[p] want min 4~ from w cycle to r
ChkDoneErase: 
         lda     FSTAT          ;[prpp] so FCCF is valid
         lsla                      ;FCCF now in MSB
         bpl     ChkDoneErase    ;loop if FCCF = 0

         ldhx    STACK
         txs
         jmp     SUCC          ;refer status back to PC
EraseSubEnd: 
EraseSubSize: equ (*-EraseSub)
;*******************************************************************************************
ProgSub:    
         lda     FSTAT          ;check FCBEF
         and     #mFSTAT_FCBEF       ;mask it
         beq     ProgSub         ;loop if not empty
         
         ldhx    ADRR
         lda     0,x
         aix     #1
         sthx    ADRR
         
         ldhx    ADRS            ;get flash address
         sta     0,x            ;write to flash; latch addr and data
         aix     #1
         sthx    ADRS
         
         lda     #mBurstProg ;get flash command
         sta     FCMD            ;write the flash command
         lda     #mFSTAT_FCBEF       ;mask to initiate command
         sta     FSTAT          ;[pwpp] register command
         dbnz    LEN,ProgSub   ;all bytes in a row?
ChkDoneProg: 
         lda     FSTAT          ;[prpp] so FCCF is valid
         lsla                     ;FCCF now in MSB
         bpl     ChkDoneProg    ;loop if FCCF = 0
         
         ldhx    STACK
         txs
         jmp     SUCC          ;refer status back to PC
ProgSubEnd: 
ProgSubSize: equ (*-ProgSub)
;*******************************************************************************************
MODPPAGE:   ; modify ADRS and PPAGE, let's do all flashing between 0x8000 and 0xBFFF with PPAGE set
         LDA     PPAGE
         TSTA    
         BEQ     MODPPAGE2
         RTS
MODPPAGE2:

         JMP     MODPPAGE3
HI_ROM:  SECTION
MODPPAGE3:

         LDA     ADRS        ; two highest bits of the high address byte
         ROLA
         ROLA
         ROLA
         AND     #$3
         STA     PPAGE       ; are used for PPAGE

         LDA     ADRS        ; and masked to fit 0x8000-0xBFFF area
         AND     #$3F
         ORA     #$80
         STA     ADRS
                
         RTS        
;*******************************************************************************************
ICSTRIM:
         CLRX
         CLRH
MONRXD:
         BRSET   RXDBIT,RXDPORT,MONRXD    ; WAIT FOR BREAK SIGNAL TO START
CHKRXD:
         BRSET   RXDBIT,RXDPORT,BRKDONE   ; (5) GET OUT OF LOOP IF BREAK IS OVER
         AIX     #1              ; (2) INCREMENT THE COUNTER
         NOP
         NOP
         NOP                     ; loop count 14 total
         NOP
         BRA     CHKRXD          ; (3) GO BACK AND CHECK SIGNAL AGAIN
BRKDONE:

     IFNDEF SPEED
         PSHH
         PULA                    ; PUT HIGH BYTE IN ACC AND WORK WITH A:X
         LSRA
         RORX                    ; low speed (9600) div 2
         PSHA
         PULH
    ELSE
    IF SPEED==38400
         PSHH
         PULA                    ; PUT HIGH BYTE IN ACC AND WORK WITH A:X
         LSLX
         ROLA                    ; hi speed (38400) mul 2
         PSHA
         PULH
    ENDIF
     ENDIF                       ; mid speeed (19200) do nothing


; data in H:X & A:X (non standard)
; 1.04ms (break char @ 9600Bd) = 8320T @ 8MHz = 594 loops (@ 14T) =
; divided by 2 => 297 time 28T loops optimal, limits are 169..424 for $00..$FF icstrim
ICSOFFSET  equ  169

         CPHX    #(ICSOFFSET+256)
         BHS     OOR
         CPHX    #ICSOFFSET
         BLO     OOR

         TXA                     ; low byte into A
         SUB     #ICSOFFSET      ; - offset

         BRA     LDTRM
OOR:
         LDA     NVICSTRM        ; if out of range, try factory trim (may not be in flash)
LDTRM:
         STA     ICSTRM
         RTS
;*******************************************************************************************
END            

