;*********************************************************************
; HEADER_START
;
;        $File Name: slfprgR-trim-qb.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    QB main bootloader file
;      Platform:       HC08
;      $Version: 6.0.5.0$
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

    include "reg-qb.h"

RCS_ENA       EQU     0           ; READ COMMAND SUPPORTED?

  IFNE RCS_ENA
RCS           EQU     $80         ; READ COMMAND SUPPORTED
  ELSE
RCS           EQU     0           ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM       EQU     1           ; FC protocol version number


ERBLK_LEN     EQU     64
WRBLK_LEN     EQU     32       

            IF SIZE = 4      ; QB4
FLS_BEG       EQU     $EE00    ; specify memory limit!
IDENTS        MACRO
              DC.B    'QB4-t',0  ; QB4 string
              ENDM
            ENDIF

            IF SIZE = 8      ; QB8
FLS_BEG       EQU     $DE00    ; specify memory limit!
IDENTS        MACRO
              DC.B    'QB8-t',0  ; QB8 string
              ENDM
            ENDIF
            
FLS_END       EQU     $FCC0       ; this is APL_VECT address (also from PRM file)
INT_VECT      EQU     $FFDE


FLBPRMASK     EQU     $C000       ; this is CPU specific FLBPR mask (i.e. bits that are always in the address)

SPEED         EQU     8         ; 4 x f(BUS)

ROMSTART      EQU     $2800

GETBYTE       EQU     ROMSTART
RDVRRNG       EQU     ROMSTART+3
ERARNGE       EQU     ROMSTART+6 
PRGRNGE       EQU     ROMSTART+9
DELNUS        EQU     ROMSTART+12

RAMSTART      EQU     $80
CTRLBYT       EQU     RAMSTART+$08
CPUSPD        EQU     RAMSTART+$09
LADDR         EQU     RAMSTART+$0A
DATA          EQU     RAMSTART+$0C

TXDDDR        EQU     DDRB
TXDPORT       EQU     PTB
TXDBIT        EQU     5
RXDPORT       EQU     PTB
RXDBIT        EQU     4

;*******************************************************************************************

            XDEF    FLBPR   ; external define for FLBPR

            XDEF    main
            XDEF    VEC1
            XDEF    VEC2
            XDEF    APL_VECT
            XDEF    VEC4
            XDEF    VEC5
            XDEF    VEC6
            XDEF    VEC7
            XDEF    VEC8
            XDEF    VEC9
            XDEF    VEC10
            XDEF    VEC11
            XDEF    VEC12
            XDEF    VEC13
            XDEF    VEC14
            XDEF    VEC15
            XDEF    VEC16


WR_DATA     EQU     'W'
RD_DATA     EQU     'R'
ENDPRG      EQU     'Q'
ERASE       EQU     'E'
ACK         EQU     $FC
IDENT       EQU     'I'

T100MS      EQU     255

ILOP      MACRO
            DC.B    $32             ; this is illegal operation code
          ENDM
;*******************************************************************************************
MY_ZEROPAGE:    SECTION  SHORT

ADRS:   DS.W     1
LEN:    DS.B     1
STAT:   DS.B     1
STSRSR: DS.B     1               ; storage for SRSR reg.

DEFAULT_RAM:    SECTION

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRIV:   DC.B    $80,0,0,0,0,0,0,0 ; 8 bytes reserved for bootloader's private use
        
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
VEC14   JMP     main            ; vector 14
VEC15:  JMP     main            ; vector 15
VEC16:  JMP     main            ; vector 16

;*******************************************************************************************
FLB_PROT_ROM:   SECTION
FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection block start - MUST CHANGE ACCORDING TO MEMORY MAPPING

CODE_ROM:       SECTION 

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

****************************************************************************************
FL1_PROT_ROM:   SECTION
; 29 bytes
main:   
        LDA     SRSR            ;[3] fetch RESET status reg.
        STA     STSRSR          ;[2] store for later re-use
        TSTA                    ;[1] check if zero (this happens if RESET pulse is too short)

        BEQ     slfprg          ;[2] if so, jump to self programming                
        AND     #%10000000      ;[2] mask only POR RESET source      
        BNE     slfprg          ;[2] any of these sources, go to self programming

        LDA     PRIV                ;[3] fetch private OSCTRIM
        STA     OSCTRIM             ;[2] trim ICG now
        
        JMP     VEC0                 ;[3] jump to real application

slfprg: 
        MOV     #%10000001,CONFIG1   ;[3] COP disable, 
                                     ;ESCI clock = CGMXCLK by default (via CONFIG2)
        MOV     #%00100000,OSCSC     ;[3] 12.8MHz Internal clock select
      
        BRA     page1                 ;[2]
FL0_PROT_ROM:   SECTION
; 14 bytes
page1:
        BSET    6,SCC1           ;[2] SCI enable
        MOV     #%00001100,SCC2  ;[3] transmit & receive enable
        MOV     #%00010000,SCBR  ;[3] 9600Bd @ 12.8MHz CGMXCLK (:3)
        MOV     #%10111110,SCPSC ;[3] 9600Bd @ 12.8MHz CGMXCLK (:(6+30/32))

        JMP     page0                 ;[3]

CODE_ROM:       SECTION 
page0:
        CLR     SCC3                  ;[2] ctrl. reg
        LDA     SCS1                 ;[2]
        MOV     #ACK,SCDR            ;[2] present ACK (we're here)

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

        JSR     ICGTRIM            ; go & trim

        BSET    6,SCC1          ; SCI enable
        MOV     #%00001100,SCC2 ; transmit & receive enable
      
        MOV     #SPEED,CPUSPD   ; feed the speed
        CLR     CTRLBYT         ; no mass erase   (QB will probably neeed this byte cleared
                                ; competely as well as QC family)
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
 
        LDA     OSCTRIM
        BSR     WRITE           ; next byte would be ICGTR, needed when no boot done!
  
        LDHX    #PRIV+1         ; next 7 are from private area
        MOV     #7,LEN
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
        RTS                                 ; low in A as well
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
        BSR     GETADDR         ; read adr. and return in H:X
        
        ADD     ERBLK_LEN-1        ; low address in A, add erase block length
        STA     LADDR+1         ; store in LastAddress

        PSHH                    ; get high address
        PULA                    ; transfer to A
        STA     LADDR           ; and store to LastAddress
        
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
        NOP                     ; (1)
        NOP                     ; (1)
        NOP                     ; (1)
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
        STA     OSCTRIM
OOR:
        RTS
;*******************************************************************************************
END  
