;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-s08ac128.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    S08AC128 main bootloader file
;      Platform:       HCS08
;      $Version: 10.0.5.0$
;      $Date: Oct-11-2011$ 
;      $Last Modified By: B20253$
;      Company:        Freescale Semiconductor
;      Security:       General Business
;
; =================================================================== 
; Copyright (c):      Freescale Semiconductor, 2009, All rights reserved.
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
; SIZE = 64, 96, 128 depending whether what memory size of AC family is required
; 
; IRQOPTION *NOT* defined >> regular version
; IRQOPTION defined >> regular version using IRQ option (bootloading won't start if IRQ high)
;
; label HISPEED => if defined, 38400Bd is used instead of 9600Bd

    include "mc9s08ac128.inc"


HISPEED_115200   EQU      1
HISPEED_38400    EQU      2
HISPEED_57600    EQU      3
HISPEED_76800    EQU      4      


   IFNDEF SCI
SCI      EQU      1
   ENDIF   

   IF SCI = 1
SCIBDH     equ     SCI1BDH
SCIBDL     equ     SCI1BDL
SCC1       equ     SCI1C1
SCC2       equ     SCI1C2
SCC3       equ     SCI1C3
SCS1       equ     SCI1S1
SCS2       equ     SCI1S2
SCDR       equ     SCI1D
TC         equ     SCI1S1_TC
RDRF       equ     SCI1S1_RDRF

mTDRE:     equ     mSCI1S1_TDRE   ;(bit #7) Tx data register empty
mTC:       equ     mSCI1S1_TC     ;(bit #6) transmit complete
mRDRF:     equ     mSCI1S1_RDRF   ;(bit #5) Rx data register full
mIDLE:     equ     mSCI1S1_IDLE   ;(bit #4) idle line detected
mOR:       equ     mSCI1S1_OR     ;(bit #3) Rx over run
mNF:       equ     mSCI1S1_NF     ;(bit #2) Rx noise flag
mFE:       equ     mSCI1S1_FE     ;(bit #1) Rx framing error
mPF:       equ     mSCI1S1_PF     ;(bit #0) Rx parity failed
                   
TXDDDR     EQU     PTEDD
TXDPORT    EQU     PTED
TXDDS      EQU     PTEDS
TXDBIT     EQU     0
RXDPORT    EQU     PTED
RXDBIT     EQU     1
   ENDIF

   IF SCI = 2
SCIBDH     equ     SCI2BDH
SCIBDL     equ     SCI2BDL
SCC1       equ     SCI2C1
SCC2       equ     SCI2C2
SCC3       equ     SCI2C3
SCS1       equ     SCI2S1
SCS2       equ     SCI2S2
SCDR       equ     SCI2D
TC         equ     SCI2S1_TC
RDRF       equ     SCI2S1_RDRF

mTDRE:     equ     mSCI2S1_TDRE   ;(bit #7) Tx data register empty
mTC:       equ     mSCI2S1_TC     ;(bit #6) transmit complete
mRDRF:     equ     mSCI2S1_RDRF   ;(bit #5) Rx data register full
mIDLE:     equ     mSCI2S1_IDLE   ;(bit #4) idle line detected
mOR:       equ     mSCI2S1_OR     ;(bit #3) Rx over run
mNF:       equ     mSCI2S1_NF     ;(bit #2) Rx noise flag
mFE:       equ     mSCI2S1_FE     ;(bit #1) Rx framing error
mPF:       equ     mSCI2S1_PF     ;(bit #0) Rx parity failed

TXDDDR     EQU     PTCDD
TXDPORT    EQU     PTCD
TXDDS      EQU     PTCDS
TXDBIT     EQU     3
RXDPORT    EQU     PTCD
RXDBIT     EQU     5
   ENDIF


BOOT_SIG_ENA EQU     1        ; ENABLE BOOTLOADER ON PIN SIGNAL

  IF BOOT_SIG_ENA = 1 

BOOTDDR    EQU     PTGDD
BOOTPORT   EQU     PTGD
BOOTPE     EQU     PTGPE
BOOTBIT    EQU     3

BOOTPIN_CHECKCNT EQU 100
BOOTPIN_CHECKCNT_MIN EQU 90

  ENDIF
  
RCS_ENA    EQU     1        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS        EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS        EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM    EQU     10       ; FC protocol version number

IDENTS     MACRO

           DC.B   'AC'

          IF SIZE = 96
           DC.B     '96'    ; 96kB string
          ENDIF
          IF SIZE = 128
           DC.B     '128'   ; 128kB string
          ENDIF

          IFDEF IRQOPTION
           DC.B     '-irq'  ; IRQ option used
          ENDIF

           DC.B    0
           ENDM

ERBLK_LEN  EQU      512
WRBLK_LEN  EQU      128      

ADDR24  MACRO
           DC.B  (\1) / $10000
           DC.W  (\1) & $0FFFF
        ENDM

   
REL_VECT   EQU    $FB6A   ; newly relocated int. vectors
INT_VECT   EQU    $FF9C   ; start of table of original vectors

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

           XDEF   VEC48
           XDEF   VEC49

           XDEF   main
;*******************************************************************************************
  
WR_DATA    EQU       'W'
RD_DATA    EQU       'R'
ENDPRG     EQU       'Q'
ERASE      EQU       'E'
ACK        EQU       $FC
IDENT      EQU       'I'

T100MS     EQU       255

ILOP      MACRO
            STOP      ; illegal as of this config
            ;DC.W    $9E9E   ; this is illegal operation code for CPUV4
          ENDM
;*******************************************************************************************
MY_ZEROPAGE:    SECTION  SHORT

ADRS:   DS.W   1
ADRR:   DS.W   1
LEN:    DS.B   1
STAT:   DS.B   1
STACK:  DS.W   1

DEFAULT_RAM:    SECTION

DATA:   DS.B    WRBLK_LEN

;*******************************************************************************************
DEFAULT_ROM:    SECTION

ID_STRING:
          IF SIZE = 96
          DC.B   4                ; number of Flash blocks
        ADDR24  ROMStart          ; START ADDRESS OF FLASH   
        ADDR24  REL_VECT          ; END ADDRESS OF FLASH                                                                      
        ADDR24  PPAGE_2Start
        ADDR24  PPAGE_2End+1
        ADDR24  PPAGE_4Start
        ADDR24  PPAGE_4End+1 
        ADDR24  PPAGE_5Start
        ADDR24  PPAGE_5End+1 
          ENDIF

          IF SIZE = 128
          DC.B   6                ; number of Flash blocks
        ADDR24  ROMStart          ; START ADDRESS OF FLASH   
        ADDR24  REL_VECT          ; END ADDRESS OF FLASH                                                                      
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


        DC.W    REL_VECT       ; POINTER TO APPLICATION VECTOR TABLE
        DC.W    INT_VECT       ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W    ERBLK_LEN      ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W    WRBLK_LEN      ; WRITE BLCK LENGTH OF FLASH ALG.

      IDENTS
ID_STRING_END:

        XDEF    MY_NVPROT   
        XDEF    MY_NVOPT    

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
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
VEC26:  JMP     main            ; vector 26
VEC27:  JMP     main            ; vector 27
VEC28:  JMP     main            ; vector 28
VEC29:  JMP     main            ; vector 29
VEC30:  JMP     main            ; vector 30
VEC31:  JMP     main            ; vector 31

VEC32:  JMP     main            ; unused vector 32
VEC33:  JMP     main            ; unused vector 33
VEC34:  JMP     main            ; unused vector 34
VEC35:  JMP     main            ; unused vector 35
VEC36:  JMP     main            ; unused vector 36
VEC37:  JMP     main            ; unused vector 37
VEC38:  JMP     main            ; unused vector 38
VEC39:  JMP     main            ; unused vector 39
VEC40:  JMP     main            ; unused vector 40
VEC41:  JMP     main            ; unused vector 41
VEC42:  JMP     main            ; unused vector 42
VEC43:  JMP     main            ; unused vector 43
VEC44:  JMP     main            ; unused vector 44
VEC45:  JMP     main            ; unused vector 45
VEC46:  JMP     main            ; unused vector 46
VEC47:  JMP     main            ; unused vector 47

VEC48:  JMP     main            ; vector 48
VEC49:  JMP     main            ; vector 49

;*******************************************************************************************
NVPROT_ROM:     SECTION
MY_NVPROT     DC.B   %11111101 ; flash protected (from 0xFC00), this is a smallest block on QE

NVOPT_ROM:      SECTION
MY_NVOPT      DC.B   %10000010   ; backdoor enable, (un)secured flash [last 10]

DEFAULT_ROM:    SECTION
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
PVEC0:  JMP     VEC0                    ; jump to relocated application!

slfprg:        
        LDA     #%00000010
        STA     SOPT                  ; COP disable, BDM enable (for now)
        MOV     #%00001000,ICGC1      ; FEI mode

     IFNDEF HISPEED
        MOV     #%00000001,ICGC2      ; N=4,R=2, f(ICGOUT)=f(IRG)/7*64*4/2=4.4434MHz (10% off reqd' 4.9152MHz)
     ELSE
        MOV     #%00010000,ICGC2      ; N=6,R=2, f(ICGOUT)=f(IRG)/7*64*6/1=13.330MHz (10% off reqd' 14.7456MHz)
     ENDIF
                                ; f(BUS)=f(ICGOUT)/2
     
LOOP:   BRCLR   ICGS1_LOCK,ICGS1,LOOP         ; wait until ICG stable       
    
        LDA     FSTAT
        ORA     #mFSTAT_FACCERR                            
        STA     FSTAT                  ; clear any FACCERR flag

     IFNDEF HISPEED
        LDA     #13                    ; div by 13 to fit into 150-200kHz Flash clock!
     ELSE
        LDA     #36                    ; div by 36+1 to fit into 150-200kHz Flash clock!
     ENDIF
        STA     FCDIV
        
        BSET    TXDBIT,TXDPORT
        BSET    TXDBIT,TXDDDR           ; TxD high when SCI disabled        
        LDA     TXDDS
        ORA     #(1<<TXDBIT)
        STA     TXDDS                   ; TxD drive strength high        
    
   LDA     #%00001100
        STA     SCC2                    ; transmit & receive enable
        CLRA
        STA     SCIBDH

     IFNDEF HISPEED
        MOV     #16, SCIBDL            ; BUS (2.4576M)/(16 * 16) = 9600Bd
     ELSE
       IF HISPEED == HISPEED_38400
        MOV     #12, SCIBDL            ; BUS (7.3728M)/(16 * 12) = 38400Bd
       ELSEIF HISPEED == HISPEED_57600
        MOV     #8, SCIBDL             ; BUS (7.3728M)/(16 * 8) = 57600Bd
       ELSEIF HISPEED == HISPEED_76800
        MOV     #6, SCIBDL             ; BUS (7.3728M)/(16 * 6) = 76800Bd
       ELSE
        MOV     #4, SCIBDL             ; BUS (7.3728M)/(16 * 4) = 115200Bd
       ENDIF
     ENDIF
        CLR     SCC3

    IF BOOT_SIG_ENA = 1           ; PIN SIGNAL MODE OF BOOTLOADER STARTUP
    
        BCLR    BOOTBIT,BOOTDDR   ; SET THE BOOT ENABLE PIN TO INPUT    
        LDA     BOOTPE
        ORA     #(1<<BOOTBIT)
        STA     BOOTPE             ; SET PULL UP ON THE BOOT ENABLE PIN        
        CLRA                       ; CLEAR CHECK COUNTER
        LDX     #BOOTPIN_CHECKCNT

BOOT_L1:
        BRCLR   BOOTBIT,BOOTPORT,BOOT_NOSIG 
        INCA

BOOT_NOSIG:    
        DBNZX   BOOT_L1    
        CMPA    #BOOTPIN_CHECKCNT_MIN
    
        BHI     BOOT_L2           ; test pin high (enough)

        ILOP          ; generate RESET by doing illegal operation

BOOT_L2:
        LDA     #ACK
        BSR     WRITE

        CLRX                             ; 1 Cycle

BOOT_L3:
        CLRA                             ; 1 Cycle
BOOT_L4:
        BRSET   RDRF,SCS1,CAUGHT         ; 5 Cycles

        DBNZA   BOOT_L4                  ; 4 Cycles
        DBNZX   BOOT_L3                  ; 4 Cycles
    
        BRA     BOOT_L2                  ; 4 Cycles
                                  
    ELSE
                              ; STANDARD MODE OF BOOTLOADER STARTUP
        LDA     SCS1
        MOV     #ACK,SCDR

        LDX     #T100MS
L2:     CLRA
L1:     BRSET   RDRF,SCS1,CAUGHT
        DBNZA   L1
        DBNZX   L2

ILOP:
;       timeout
        ILOP          ; generate RESET by doing illegal operation

    ENDIF
;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
        BSR     READ
        CLR     SCC2               ; disable SCI
        JSR     ICGTRIM            ; go & trim
        MOV     #%00001100,SCC2    ; transmit & receive enable

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
WRITE_LOOP:             ; start address in HX, length in LEN
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
        BSR     READ
        STA     LEN
        LDHX    ADRS
        
        BSR     WRITE_LOOP

        BRA     BCKGND            ; finish without ACK
      ENDIF

;*******************************************************************************************
WRITE:   
        BRCLR   TC,SCS1,WRITE
        STA     SCDR
        RTS
READ:
        BRCLR   RDRF,SCS1,READ
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
        lda     #(mFSTAT_FPVIOL+mFSTAT_FACCERR) ;mask
        sta     FSTAT                          ;abort any command and clear errors

        mov     #LOW(EraseSubSize), STAT       ;length of flash erase routine to STAT
        tsx
        sthx    STACK
        ldhx    #EraseSubEnd-1                 ;point at last byte to move to stack

        bra     DoOnStack                      ;execute prog code from stack RAM
;*******************************************************************************************
WR_DATA_COM:
        BSR     READ
        STA     PPAGE
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
        ldhx    #ProgSubEnd-1        ;point at last byte to move to stack

;      bra      DoOnStack            ;execute prog code from stack RAM
; fallthru to DoOnStack
;*******************************************************************************************
DoOnStack: 
        lda     ,x             ;read from flash
        psha                   ;move onto stack
        aix     #-1            ;next byte to move
        dbnz    STAT, DoOnStack
        tsx                    ;point to sub on stack
        jmp     ,x             ;execute the sub on the stack (will return on it's own)      
;*******************************************************************************************
EraseSub:    
        ldhx    ADRS            ;get flash address
        sta     0,x             ;write to flash; latch addr and data
        lda     #mPageErase     ;get flash command
        sta     FCMD            ;write the flash command
        lda     #mFSTAT_FCBEF   ;mask to initiate command
        sta     FSTAT           ;[pwpp] register command
        nop                     ;[p] want min 4~ from w cycle to r
ChkDoneErase: 
        lda     FSTAT          ;[prpp] so FCCF is valid
        lsla                   ;FCCF now in MSB
        bpl     ChkDoneErase   ;loop if FCCF = 0

        ldhx    STACK
        txs
        jmp     SUCC           ;refer status back to PC
EraseSubEnd: 
EraseSubSize:   equ.b (*-EraseSub)
;*******************************************************************************************
ProgSub:    
        lda     FSTAT           ;check FCBEF
        and     #mFSTAT_FCBEF   ;mask it
        beq     ProgSub         ;loop if not empty
        
        ldhx    ADRR
        lda     0,x
        aix     #1
        sthx    ADRR
        
        ldhx    ADRS            ;get flash address
        sta     0,x             ;write to flash; latch addr and data
        aix     #1
        sthx    ADRS
        
        lda     #mBurstProg     ;get flash command
        sta     FCMD            ;write the flash command
        lda     #mFSTAT_FCBEF   ;mask to initiate command
        sta     FSTAT           ;[pwpp] register command
        dbnz    LEN,ProgSub     ;all bytes in a row?
ChkDoneProg: 
        lda     FSTAT           ;[prpp] so FCCF is valid
        lsla                    ;FCCF now in MSB
        bpl     ChkDoneProg     ;loop if FCCF = 0
      
        ldhx    STACK
        txs
        jmp     SUCC            ;refer status back to PC
ProgSubEnd: 
ProgSubSize: equ.b (*-ProgSub)
;*******************************************************************************************
ICGTRIM:
        CLRX
        CLRH
MONRXD:
        BRSET   RXDBIT,RXDPORT,MONRXD    ; WAIT FOR BREAK SIGNAL TO START
CHKRXD:
        BRSET   RXDBIT,RXDPORT,BRKDONE   ; (5) GET OUT OF LOOP IF BREAK IS OVER
        AIX     #1              ; (2) INCREMENT THE COUNTER
        BRA     CHKRXD          ; (3) GO BACK AND CHECK SIGNAL AGAIN
BRKDONE:
        PSHH
        PULA                    ; PUT HIGH BYTE IN ACC AND WORK WITH A:X

     IFDEF HISPEED
    
      IF HISPEED == HISPEED_38400
      ; mul by 1.3  ~ keep 1
      ; mul by 2  
        LSLA
          ROLX
      ELSEIF HISPEED == HISPEED_57600
        ; mul by 2  
        LSLA
        ROLX
          
      ELSEIF HISPEED == HISPEED_76800
        ; mul by 2.66 ~ keep 2
        LSLA
        ROLX          
      ELSE
        LSLA
        ROLX
        LSLA
        ROLX   ; mul by 4 since we're 4 times slower
       ENDIF   
     ENDIF

        TSTA                    ; IF MSB OF LOOP CYCLES = 0, THEN BREAK TAKES TOO
        TXA                     ; FEW CYCLES THAN EXPECTED, SO TRIM BY SPEEDING
        BEQ     SLOW            ; UP f OP .
FAST:   CMP     #$40            ; SEE IF BREAK IS WITHIN TOLERANCE
        BGE     OOR             ; DON'T TRIM IF OUT OF RANGE
        ASLA                    ; multiply by two to get right range
        ADD     #$80            ; BREAK LONGER THAN EXPECTED, SO SLOW DOWN f OP
        BRA     ICGDONE
SLOW:   CMP     #$C0            ; SEE IF BREAK IS WITHIN TOLERANCE
        BLT     OOR             ; DON'T TRIM IF OUT OF RANGE
        ASLA                    ; multiply by two to get right range
        SUB     #$80
ICGDONE:
        STA     ICGTRM
OOR:
        RTS
;*******************************************************************************************
END            

