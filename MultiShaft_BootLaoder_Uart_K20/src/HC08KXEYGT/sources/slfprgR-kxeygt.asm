;*********************************************************************
; HEADER_START
;
;        $File Name: slfprgR-kxeygt.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    KX/EY/GT main bootloader file
;      Platform:       HC08
;      $Version: 6.0.14.0$
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

; labels FAMILY and SIZE defined externally:
; FAMILY = 1 >>> KX8 family (SIZE = 2 or 8)
; FAMILY = 2 >>> GT8/16 family (SIZE = 8 or 16)
; FAMILY = 3 >>> EY16 family
; label IRQOPTION is defined only when IRQ option is required

RCS_ENA         EQU     0     ; READ COMMAND SUPPORTED?

  IFNE RCS_ENA
RCS             EQU     $80   ; READ COMMAND SUPPORTED
  ELSE
RCS             EQU     0     ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM         EQU     1     ; FC protocol version number


ERBLK_LEN       EQU     64
WRBLK_LEN       EQU     32       

    IF FAMILY = 1                   ; KX2/8
      IF SIZE = 2
FLS_BEG         EQU     $F600
      ENDIF    
      IF SIZE = 8
FLS_BEG         EQU     $E000
      ENDIF    
    ENDIF
    
    IF FAMILY = 2                   ; GT8/16
      IF SIZE = 16
FLS_BEG         EQU     $C000
      ENDIF    
      IF SIZE = 8
FLS_BEG         EQU     $E000
      ENDIF    
    ENDIF    

    IF FAMILY = 3                   ; EY16 only
FLS_BEG         EQU     $E000
    ENDIF    
    
IDENTS          MACRO
    IF FAMILY = 1
      IF SIZE = 2
                DC.B    'KX2'       ; KX2 string
      ENDIF
      IF SIZE = 8
                DC.B    'KX8'       ; KX8 string
      ENDIF
    ENDIF

    IF FAMILY = 2
      IF SIZE = 16
                DC.B    'GT16'      ; GT16 string
      ENDIF
      IF SIZE = 8
                DC.B    'GT8'       ; GT8 string
      ENDIF
    ENDIF

    IF FAMILY = 3
                DC.B    'EY16'      ; EY16 string
    ENDIF

    IFDEF IRQOPTION
                DC.B    '-IR-irq',0 ; internal oscillator & ROM usage + IRQ option active
    ELSE
                DC.B    '-IR',0     ; internal oscillator & ROM usage
    ENDIF
                ENDM

    
FLS_END         EQU     $FC80         ; this is APL_VECT address (copy start of VAR_ROM from PRM file)
INT_VECT        EQU     $FFDC

FLBPRMASK       EQU     $C000         ; this is CPU specific FLBPR mask (i.e. bits that are always in the address)

ICGMRINIT       EQU     $20           ; 32 times internal oscillator

    IF (FAMILY = 1) || (FAMILY = 3)
ROMSTART        EQU     $1000
    ENDIF
    
    IF FAMILY = 2
ROMSTART        EQU     $1B50
    ENDIF

GETBYTE         EQU     ROMSTART+0
RDVRRNG         EQU     ROMSTART+3
ERARNGE         EQU     ROMSTART+6
PRGRNGE         EQU     ROMSTART+9
DELNUS          EQU     ROMSTART+12

RAMSTART        EQU     $40
CTRLBYT         EQU     RAMSTART+$08
CPUSPD          EQU     RAMSTART+$09
LADDR           EQU     RAMSTART+$0A
DATA            EQU     RAMSTART+$0C

SPEED           EQU     10

    IF FAMILY = 1
       include "reg-kx8.h"

TXDDDR          EQU     DDRB
TXDPORT         EQU     PTB
TXDBIT          EQU     5
RXDPORT         EQU     PTB
RXDBIT          EQU     4
    ENDIF
    
    IF (FAMILY = 2) || (FAMILY = 3)
       include "reg-eygt.h"

TXDDDR          EQU     DDRE
TXDPORT         EQU     PTE
TXDBIT          EQU     0
RXDPORT         EQU     PTE
RXDBIT          EQU     1
    ENDIF

;*******************************************************************************************

           XDEF      main
           XDEF      VEC1
           XDEF      VEC2
           XDEF      VEC3
           XDEF      VEC4
           XDEF      VEC5
           XDEF      VEC6
           XDEF      VEC7
           XDEF      VEC8
           XDEF      VEC9
           XDEF      VEC10
           XDEF      VEC11
           XDEF      VEC12
           XDEF      VEC13
           XDEF      VEC14
           XDEF      VEC15
           XDEF      VEC16
           XDEF      VEC17

WR_DATA      EQU       'W'
RD_DATA      EQU       'R'
ENDPRG       EQU       'Q'
ERASE        EQU       'E'
ACK          EQU       $FC
IDENT        EQU       'I'

T100MS       EQU       128

ILOP         MACRO
             DC.B    $32             ; this is illegal operation code
             ENDM
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

ADRS:   DS.W   1
LEN:    DS.B   1
STAT:   DS.B   1
STSRSR: DS.B  1                 ; storage for SRSR reg.

DEFAULT_RAM:    SECTION

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRIV:   DC.B    0,$80,0,0,0,$80,0,0 ; 8 bytes reserved for bootloader's private use
        
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

FLB_PROT_ROM:   SECTION
FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection block start - MUST CHANGE ACCORDING TO MEMORY MAPPING
        
DEFAULT_ROM:    SECTION
        
ID_STRING1:
        DC.B    VER_NUM | RCS    ; version number & "Read command supported" flag
        DC.W    FLS_BEG          ; START ADDRESS OF FLASH   
        DC.W    FLS_END          ; END ADDRESS OF FLASH   
        DC.W    APL_VECT         ; POINTER TO APPLICATION VECTOR TABLE
        DC.W    INT_VECT         ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W    ERBLK_LEN        ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W    WRBLK_LEN        ; WRITE BLCK LENGTH OF FLASH ALG.
ID_STRING1_END:

ID_STRING2:
       IDENTS
ID_STRING2_END:

;*******************************************************************************************
main:   
    IFDEF IRQOPTION
        BIH     PVEC0                   ; if IRQ high, jump directly to real app.
    ENDIF
        LDA     SRSR                    ; fetch RESET status reg.
        STA     STSRSR                  ; store for later re-use
        TSTA                            ; check is zero (this happens if RESET pulse is too short)
        BEQ     slfprg                  ; if so, jump to self programming                
        AND     #%10000000              ; mask only POR RESET source      
        BNE     slfprg                  ; any of these sources, go to self programming

PVEC0:  LDA     PRIV+5
        STA     ICGTR                   ; trim ICG for future use!
        BRA     VEC0

slfprg: 
        MOV     #%10000001,CONFIG1

        MOV     #ICGMRINIT,ICGMR        ; set 9.8304MHz CLOCK
LOOP:   BRCLR   2,ICGCR,LOOP            ; wait until ICG stable       
        
        BSET    TXDBIT,TXDPORT
        BSET    TXDBIT,TXDDDR           ; TxD high when SCI disabled        

        BSET    6,SCC1           ; SCI enable
        MOV     #%00001100,SCC2  ; transmit & receive enable
        CLR     SCC3

      IF FAMILY = 2              ; GT family can't use CGMXCLK as SCI source
        MOV     #%00000010,SCBR  ; 9600Bd @ 2.4576MHz (:4)
      ELSE
        MOV     #%00000100,SCBR  ; 9600Bd @ 9.8304MHz (:16)
      ENDIF

        LDA     SCS1
        MOV     #ACK,SCDR

        LDX     #T100MS
L2:     CLRA
L1:     BRSET   5,SCS1,CAUGHT
        DBNZA   L1
        DBNZX   L2

;       timeout
        ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
        BSR     READ

        BCLR    6,SCC1          ; disable SCI

        JSR     ICGTRIM         ; go & trim

        BSET    6,SCC1          ; SCI enable
        MOV     #%00001100,SCC2 ; transmit & receive enable
        
        MOV     #SPEED,CPUSPD   ; feed the speed
        BCLR    6,CTRLBYT       ; no mass erase
        
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
IDENT_COM:                      ; TRANSFER OF IDENTIFICATION STRING
        MOV     #ID_STRING1_END-ID_STRING1, LEN
        LDHX    #ID_STRING1
        BSR     WRITE_LOOP

        LDA     STSRSR          ; first byte will be SRSR reg.
        BSR     WRITE
        
        LDHX    #PRIV+1         ; next 4 are from private area
        MOV     #4,LEN
        BSR     WRITE_LOOP

        LDA     ICGTR
        BSR     WRITE           ; next byte would be ICGTR, needed when no boot done!
        
        LDA     ICGMR
        BSR     WRITE           ; next byte would be ICGMR, just for info
        
        LDA     FLBPR
        BSR     WRITE           ; last byte would be FLBPR, so it     includes in S19
        
        MOV     #ID_STRING2_END-ID_STRING2, LEN
        LDHX    #ID_STRING2
        BSR     WRITE_LOOP

        BRA     BCKGND          ; finish without ACK
      
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
WRITE:   
        BRCLR   6,SCS1,WRITE
        STA     SCDR
        RTS
READ:
        BRCLR   5,SCS1,READ
        LDA     SCDR
        RTS

;*******************************************************************************************
ERASE_COM:
        BSR     READ
        PSHA
        PULH                    ; store to H:x
        BSR     READ
        TAX                     ; store to h:X
        JSR     ERARNGE         ; call ROM erase routine

        BRA     SUCC            ; refer status back to PC

;*******************************************************************************************
WR_DATA_COM:
        BSR     READ
        STA     ADRS
        BSR     READ
        STA     ADRS+1
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
        
        JMP     SUCC            ; refer status back to PC
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
        STA     ICGTR
OOR:
        RTS
;*******************************************************************************************
END            
