;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-abasaz.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    ABAZAS32/60 main bootloader file
;      Platform:       HC08
;      $Version: 6.0.24.0$
;      $Date: Oct-10-2011$ 
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

; label IRQOPTION defined externally, if required:
; IRQOPTION *NOT* defined >> regular version using 4.9152MHz xtal (AS/AZ/AB) or 8MHz (GZ)
; IRQOPTION defined >> regular version using 4.9152MHz xtal (AS/AZ/AB) or 8MHz (GZ) and IRQ option
;  (bootloading won't start if IRQ high)

; FAMILY = 1, SIZE 32 - AS32A
; FAMILY = 1, SIZE 60 - AS60A

; FAMILY = 2, SIZE 32 - AZ32A
; FAMILY = 2, SIZE 60 - AZ60A

; FAMILY = 3, SIZE 32 - AB32A

      IF ((FAMILY = 1) || (FAMILY = 2))
   include "reg-azas60.h"
      ELSEIF (FAMILY = 3)
   include "reg-ab32.h"
      ENDIF

RCS_ENA    EQU      1        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS        EQU      $80      ; READ COMMAND SUPPORTED
  ELSE
RCS        EQU      0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM    EQU      3        ; FC protocol version number - number 3!


      IF SIZE = 60
          IF FAMILY = 1    ; (AS60A)
FLS_BEG    EQU      $0E00   ; FLASH #2 block start
FLS_END    EQU      $FB80   ; FLASH #2 block end
FLS_BEG1   EQU      $0450   ; FLASH #0 block start
FLS_END1   EQU      $0A00   ; EEPROM 1+2 block end

INT_VECT   EQU      $FFD2
        ELSEIF FAMILY = 2   ; (AZ60A)
FLS_BEG    EQU      $0E00   ; FLASH #2 block start
FLS_END    EQU      $FB80   ; FLASH #2 block end
FLS_BEG1   EQU      $0450   ; FLASH #0 block start
FLS_END1   EQU      $0500   ; FLASH #0 block end
FLS_BEG2   EQU      $0580   ; FLASH #1 through EEPROM 1+2 block start
FLS_END2   EQU      $0A00   ; EEPROM 1+2 block end

        IF FAMILY = 1     ; (AS60A)
INT_VECT   EQU      $FFDA
          ELSEIF FAMILY = 2   ; (AZ60A)
INT_VECT   EQU      $FFCC
          ENDIF
        ENDIF
      ELSEIF SIZE = 32
FLS_BEG    EQU      $8000   ; FLASH #1 block start
FLS_END    EQU      $FB80   ; FLASH #1 block end
FLS_BEG1   EQU      $0800   ; EEPROM #1 block start
FLS_END1   EQU      $0A00   ; EEPROM #1 block end
          IF FAMILY = 1   ; (AS32A)
INT_VECT   EQU      $FFDA
        ELSEIF FAMILY = 2   ; (AZ32A)
INT_VECT   EQU      $FFCC
        ELSEIF FAMILY = 3   ; (AB32A)
INT_VECT   EQU      $FFD0
        ENDIF
      ENDIF

IDENTS MACRO
        IF SIZE = 60
            IF FAMILY = 1
                DC.B     'AS60A'
            ELSEIF FAMILY = 2
                DC.B     'AZ60A'
            ENDIF
        ELSEIF SIZE = 32
            IF FAMILY = 1
                DC.B     'AS32A'
            ELSEIF FAMILY = 2
                DC.B     'AZ32A'
            ELSEIF FAMILY = 3
                DC.B     'AB32'
            ENDIF
        ENDIF
          IFDEF IRQOPTION
            DC.B     '-irq'
          ENDIF
            DC.B     0
            ENDM


ERBLK_LEN   EQU      128
WRBLK_LEN   EQU      64       

FLBPRMASK   EQU     $8000     ; this is CPU specific FLBPR mask 
                            ; (i.e. bits that are always in the address)
                               
;*******************************************************************************************

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

   XDEF   FLBPR
   XDEF   EE1DIV
  IF SIZE = 60
   XDEF   EE2DIV
  ENDIF
   
T1US      EQU      1    ; 4us @ 1.2288MHz
T5US      EQU      2    ; 7.3us
T10US     EQU      3    ; 11.3us
T30US     EQU      10   ; 34.1us
T100US    EQU      30   ; 3*34.1us
T1MS      EQU      1    ; 2.50ms
T10MS     EQU      4    ; 10ms
T100MS    EQU      40   ; 100.1ms
   
WR_DATA   EQU      'W'
RD_DATA   EQU      'R'
ENDPRG    EQU      'Q'
ERASE     EQU      'E'
ACK       EQU      $FC
IDENT     EQU      'I'

ILOP    MACRO
          DC.B    $32             ; this is illegal operation code
        ENDM

;*******************************************************************************************
D_MS:   MACRO
        LDA   \1        ; [2] ||  arg > 0, arg=0 <=> arg=256
\@L2:   CLRX            ; [1] ||
\@L1:
        PSHA            ; [2] |
        PSHX            ; [2] |
        NOP             ; [1] |
        PULX            ; [2] |
        PULA            ; [2] |
        DBNZX   \@L1    ; [3] |    256*12 = 3072T
        DBNZA   \@L2    ; [3] ||  (3072+4)*arg + 2 T
      ENDM

D_US:   MACRO
        LDA   \1         ; [2]       arg > 0, arg=0 <=> arg=256
\@L1:   NOP              ; [1]
        DBNZA   \@L1     ; [3]      4*arg + 2 T
      ENDM              
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

STSRSR:    DS.B   1               ; storage for SRSR reg.
ADRS:      DS.W   1
POM:       DS.B   1
LEN:       DS.B   1
STAT:      DS.B   1
STACK      DS.W   1               ; storage for stack
STACKCPY   DS.W   1               ; storage for stack
SOURCE     DS.W   1               ; storage for source address
RFLBPR:    DS.W   1
RFLCR:     DS.W   1
REECR:     DS.W   1

DEFAULT_RAM:    SECTION

PRG:       DS.B   150
DAT:       DS.B   WRBLK_LEN

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRI:    DC.B    0,0,0,0,0,0,0,0 ; 8 bytes reserved for bootloader's private use, not used in ver 3
                        ; kept for compatibility
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
  
FLB_PROT_ROM:   SECTION
FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection starts MUST CHANGE ACCORDING TO MEMORY MAPPING

EETBASE  equ      28571      ; 1/35us
EETCLOCK equ      4915200      ; Hz

EE1DIV_ROM:   SECTION
EE1DIV:  DC.W    EETCLOCK/EETBASE    ; EEPROM NVReg for timing with security enabled

   IF SIZE = 60
EE2DIV_ROM:   SECTION
EE2DIV:  DC.W    EETCLOCK/EETBASE    ; EEPROM NVReg for timing with security enabled
    ENDIF    
        
DEFAULT_ROM:  SECTION
     
ID_STRING1:
        DC.B  VER_NUM | RCS ; version number & "Read command supported" flag
        DC.W   $FFFF         ; SDID (undefined, for HC08s)
      IF SIZE = 60
          IF FAMILY = 1      ; AS60A
        DC.B   2             ; number of Flash blocks
        DC.W   FLS_BEG       ; START ADDRESS OF FLASH   
        DC.W   FLS_END       ; END ADDRESS OF FLASH   
        DC.W   FLS_BEG1      ; START ADDRESS OF FLASH #1
        DC.W   FLS_END1      ; END ADDRESS OF FLASH    #1 plus EEPROM
        ELSEIF FAMILY = 2    ; AZ60A
        DC.B   3             ; number of Flash blocks
        DC.W   FLS_BEG        ; START ADDRESS OF FLASH   
        DC.W   FLS_END        ; END ADDRESS OF FLASH   
        DC.W   FLS_BEG1       ; START ADDRESS OF FLASH #1
        DC.W   FLS_END1       ; END ADDRESS OF FLASH    #1
        DC.W   FLS_BEG2       ; START ADDRESS OF FLASH #2
        DC.W   FLS_END2       ; END ADDRESS OF FLASH    #2 plus EEPROM
        ENDIF      
      ELSEIF SIZE = 32
        DC.B   2                  ; number of Flash blocks
        DC.W   FLS_BEG        ; START ADDRESS OF FLASH   
        DC.W   FLS_END        ; END ADDRESS OF FLASH   
        DC.W   FLS_BEG1       ; START ADDRESS OF EEPROM #1
        DC.W   FLS_END1       ; END ADDRESS OF EEPROM #1
      ENDIF  
        DC.W   APL_VECT         ; POINTER TO APPLICATION VECTOR TABLE
        DC.W   INT_VECT         ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W   ERBLK_LEN        ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W   WRBLK_LEN        ; WRITE BLCK LENGTH OF FLASH ALG.

   IDENTS
ID_STRING1_END:

;*******************************************************************************************
main:   
        IFDEF IRQOPTION
          BIH     PVEC0                   ; [for special case - if IRQ high, jump directly to real app.]
        ENDIF
          LDA     SRSR                    ; fetch RESET status reg.
          STA     STSRSR                  ; store for later re-use
          TSTA                            ; check is zero (this happens if RESET pulse is too short)
          BEQ     slfprg                  ; if so, jump to self programming                
          AND     #%10000000              ; mask only POR RESET source      
          BNE     slfprg                  ; any of these sources, go to self programming
PVEC0:    JMP     VEC0                    ; any of other sources, jump to real application

slfprg:
          CLRA
          STA     CONFIG2            ; CAN, EEPROMclk = CGMXCLK
          MOV     #%10010001,CONFIG1   ; COP disable

; PLL not initialized, Xtal (4.1952MHz)/4 used for BUSCLK (1.2288MHz)

          BSET    6,SCC1          ; SCI enable
          MOV     #%00001100,SCC2 ; transmit & receive enable
          CLR     SCC3
          MOV     #%00000011,SCBR ; 9600Bd @ 4.9152MHz (CGMXCLK), /4, /16, /8
       
          LDA     SCS1
          MOV     #ACK,SCDR

          LDX     #T100MS
L2:       CLRA
L1:       BRSET   5,SCS1,CAUGHT
          DBNZA   L1
          DBNZX   L2

;       timeout
ENDPRG_COM:
          ILOP                   ; generate RESET by doing illegal operation

;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
          BSR     READ
          CMPA    #ACK
          BNE     ENDPRG_COM

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
           
          CBEQA   #IDENT, IDENT_COM       ; Ident command
          CBEQA   #ERASE, ERASE_COM       ; Erase command
          CBEQA   #WR_DATA, WR_DATA_COM   ; Write (program) command
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

          BRA     BCKGND          ; finish without ACK
      
;*******************************************************************************************
WRITE_LOOP:                   ; start address in HX, length in LEN
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
READ:
          BRCLR   5,SCS1,READ
          LDA     SCDR
          RTS

WRITE:   
          BRCLR   6,SCS1,WRITE
          STA     SCDR
          RTS
;*******************************************************************************************
GETADDR:
          BSR     READ
          STA     ADRS
          BSR     READ
          STA     ADRS+1
          RTS

;*******************************************************************************************
;*******************************************************************************************
      IF SIZE = 60
;*******************************************************************************************
ERASE_COM:

          BSR     GETADDR

          JSR     EETEST         ; go'n'check EEPROM address area
          BCS     EEERASE
          
          LDHX    #ERASE_ALG      ; LOAD ERASE ALGORITHM TO RAM
          STHX    SOURCE
          MOV     #ERASE_ALG_END-ERASE_ALG,STAT

          BRA     CPYPRNGORAM      ; prepare FLCR & FLBPR address in RAM and JUMP to PRG then!
      
EEERASE:      
          LDA     #%00010110   ; block erase, EELAT & AUTO bit
          LDHX    REECR
          STA     ,X         ; EEPROM block erase
          
          LDHX    ADRS
          STA     ,X         ; latch address

          LDA     #%00010111   ; EEPGM on now
          LDHX    REECR
          STA     ,X         ; EEPROM block erase

WAUTOE:
          LDA     ,X         ; fetch EECR
          AND     #%00000001   ; mask EEPGM bit
          BNE     WAUTOE
                         ; A zeroed
          STA     ,X         ; EECTL off completely

          JMP     SUCC
;*******************************************************************************************
WR_DATA_COM:
          BSR     GETADDR

          BSR     READ
          STA     LEN
          STA     STAT
          LDHX    #DAT
WR_DATA_L1:
          BSR     READ
          STA     ,X
          AIX     #1
          DBNZ    STAT,WR_DATA_L1
                            ; START OF SELF-PROGRAMMING

          JSR     EETEST         ; go'n'check EEPROM address area
          BCS     WREEP

          TSX
          STHX    STACK           ; copy stack for later re-call

WR_BUF:
          LDHX    #WR_ALG         ; LOAD WRITE ALGORITHM TO RAM
          STHX    SOURCE
          MOV     #WR_ALG_END-WR_ALG,STAT

          BRA     CPYPRNGORAM      ; copyprepare FLCR & FLBPR address in RAM and JUMP to PRG then!, or do EEPROM pgming!

WREEP:
          LDHX    #DAT            ; prepare addrs'
          MOV     LEN,POM
EWR_ALG_L1:
          LDA     ,X
          BSR     EEWRITE
          AIX     #1
          DBNZ    POM,EWR_ALG_L1   ; copy desired block of data

          JMP     SUCC


RETWR:    LDHX    STACK
          TXS                     ; restore stack
        
          JMP     SUCC      

;*******************************************************************************************
CPYPRNGORAM:
          TSX
          STHX    STACKCPY          ; copy stack for later re-call
        
          LDHX    SOURCE         ; LOAD WRITE ALGORITHM TO RAM
          TXS
          LDHX    #PRG
CPY_PRG_L1:
          PULA
          STA     ,X
          AIX     #1
          DBNZ    STAT,CPY_PRG_L1
        
          LDHX    STACKCPY
          TXS                     ; restore stack

          LDHX    #$8000
          CPHX    ADRS         ; FLASH1/FLASH2 boundary at $8000
          
          BHI     FL2SEL         ; if 8000 < ADRS (ie. FLASH1, hi)
          
          LDHX    #FL1CR         ; ADRS >= $8000
          STHX    RFLCR
          LDHX    #FL1BPR
          BRA     GORAM
FL2SEL:         
          LDHX    #FL2CR         ; ADRS < $8000
          STHX    RFLCR
          LDHX    #FL2BPR
GORAM:    STHX    RFLBPR
          JMP     PRG            ; jump to RAM program

;*******************************************************************************************
EETEST:   
          LDHX    ADRS
          CPHX    #$0600
          BLO     FLASH         ; not eeprom
                            ; ADRS >= $600
          CPHX    #$0A00                     
          BHS     FLASH         ; right in the middle
                            ; ADRS < $A00
          CPHX    #$0800
          BLO     EE2SEL

          LDHX    #EE1CR         ; ADRS < $800
          BRA     GORAM2
      
EE2SEL:   LDHX    #EE2CR      
GORAM2:   STHX    REECR         ; prepare EECR addr into RAM

          SEC
          RTS                  ; set carry to indicate EEPROM

FLASH:    CLC
          RTS                  ; carry clear for Flash
            
;*******************************************************************************************
EEWRITE:
          PSHH
          PSHX
          PSHA
          
          LDA     #%00000110   ; byte write, EELAT
          LDHX    REECR
          STA     ,X         ; EEPROM block erase
          
          LDHX    ADRS
          PULA
          STA     ,X         ; latch address & store data into EEPROM

          AIX     #1
          STHX    ADRS

          LDA     #%00000111   ; EEPGM on now
          LDHX    REECR
          STA     ,X         ; EEPROM block erase

WAUTOW:
          LDA     ,X         ; fetch EECR
          AND     #%00000001   ; mask EEPGM bit
          BNE     WAUTOW
                         ; A zeroed
          STA     ,X         ; EECTL off completely
          
          PULX
          PULH
          RTS
;*******************************************************************************************
ERASE_ALG:

          LDA     #%00000010   
          LDHX    RFLCR
          STA     ,X              ; PGM bit on
          LDHX    RFLBPR
          LDA     ,X              ; dummy read FLBPR

          LDHX    ADRS            ; write anything
          STA     ,X              ; to desired range
          D_US    #T10US         ; wait 10us (tNVS)

          LDA     #%00001010
          LDHX    RFLCR
          STA     ,X              ; PGM bit on
          D_MS    #T1MS         ; wait 1ms (tERASE), modifies X!

          LDA     #%00001000
          LDHX    RFLCR
          STA     ,X              ; PGM bit on
          D_US    #T5US         ; wait 5us (tNVH)

          CLRA
          STA     ,X              ; PGM bit on
          D_US    #T1US         ; wait 1us (tRCV)
       
          JMP     SUCC            ; finish with ACK
ERASE_ALG_END:
;*******************************************************************************************
WR_ALG:
          LDA     #%00000001
          LDHX    RFLCR
          STA     ,X              ; PGM bit on
          LDHX    RFLBPR
          LDA     ,X              ; dummy read FLBPR

          LDHX    ADRS            ; prepare addrs'
          STA     ,X              ; and write to desired range
          D_US    #T10US         ; wait 10us (tNVS)

          LDA     #%00001001
          LDHX    RFLCR
          STA     ,X              ; PGM bit on
          D_US    #T5US         ; wait 5us (tPGS)

          LDHX    #DAT            ; prepare addrs'
          TXS
          LDHX    ADRS
          MOV     LEN,POM
WR_ALG_L1:
          PULA
          STA     ,X
          AIX     #1
          D_US    #T30US         ; wait 30us (tPROG)
          DBNZ    POM,WR_ALG_L1   ; copy desired block of data

          LDA     #%00001000
          LDHX    RFLCR
          STA     ,X              ; PGM bit on
          D_US    #T5US         ; wait 5us (tNVH)

          CLRA
          STA     ,X              ; PGM bit on
          D_US    #T1US         ; wait 1us (tRCV)
       
          JMP     RETWR           ; finish with ACK (& restore STACK before)
WR_ALG_END:
;*******************************************************************************************
; SIZE = 60 END /all FLBPR, FLCR and EECR registers are stored in RAM (according to memory bank used)/
;*******************************************************************************************
   ELSE IF SIZE = 32
;*******************************************************************************************
ERASE_COM:

          BSR     GETADDR

          LDHX    ADRS
          CPHX    #$0A00                     

          BLO     EEERASE
          
          LDHX    #ERASE_ALG      ; LOAD ERASE ALGORITHM TO RAM
          STHX    SOURCE
          MOV     #ERASE_ALG_END-ERASE_ALG,STAT

          BRA     CPYPRNGORAM      ; prepare FLCR & FLBPR address in RAM and JUMP to PRG then!
          
EEERASE:      
          LDA     #%00010110   ; block erase, EELAT & AUTO!
          STA     EE1CR      ; EEPROM block erase
          
          LDHX    ADRS
          STA     ,X         ; latch address

          LDA     #%00010111   ; EEPGM on now
          STA     EE1CR      ; EEPROM block erase

WAUTOE:   LDA     EE1CR
          AND     #%00000001   ; mask EEPGM bit
          BNE     WAUTOE
                         ; A is zero   now      
          STA     EE1CR      ; EECTL off completely

          JMP     SUCC
;*******************************************************************************************
WR_DATA_COM:
          BSR     GETADDR
          BSR     READ
          STA     LEN
          STA     STAT
          LDHX    #DAT
WR_DATA_L1:
          BSR     READ
          STA     ,X
          AIX     #1
          DBNZ    STAT,WR_DATA_L1
                            ; START OF SELF-PROGRAMMING
          LDHX    ADRS
          CPHX    #$0A00                     
          BLO     WREEP
          TSX
          STHX    STACK           ; copy stack for later re-call

WR_BUF:
          LDHX    #WR_ALG         ; LOAD WRITE ALGORITHM TO RAM
          STHX    SOURCE
          MOV     #WR_ALG_END-WR_ALG,STAT
          BRA     CPYPRNGORAM      ; prepare FLCR & FLBPR address in RAM and JUMP to PRG then!

WREEP:
          LDHX    #DAT            ; prepare addrs'
          MOV     LEN,POM
EWR_ALG_L1:
          LDA     ,X
          BSR     EEWRITE
          AIX     #1
          DBNZ    POM,EWR_ALG_L1   ; copy desired block of data
          JMP     SUCC


RETWR:    LDHX    STACK
          TXS                     ; restore stack
          JMP     SUCC      

;*******************************************************************************************
CPYPRNGORAM:
          TSX
          STHX    STACKCPY          ; copy stack for later re-call
        
          LDHX    SOURCE         ; LOAD WRITE ALGORITHM TO RAM
          TXS
          LDHX    #PRG
CPY_PRG_L1:
          PULA
          STA     ,X
          AIX     #1
          DBNZ    STAT,CPY_PRG_L1
        
          LDHX    STACKCPY
          TXS                     ; restore stack

          JMP     PRG            ; jump to RAM program

;*******************************************************************************************
EEWRITE:
          PSHH
          PSHX
          PSHA
          
          LDA     #%00000110   ; byte write, EELAT & AUTO
          STA     EE1CR      ; EEPROM block erase
          
          LDHX    ADRS
          PULA
          STA     ,X         ; latch address & store data into EEPROM

          AIX     #1
          STHX    ADRS

          LDA     #%00000111   ; EEPGM on now
          STA     EE1CR      ; EEPROM block erase

WAUTOW:   LDA     EE1CR
          AND     #%00000001   ; mask EEPGM bit
          BNE     WAUTOW
                         ; A is zero   now
          STA     EE1CR      ; EECTL off completely
          
          PULX
          PULH
          RTS
;*******************************************************************************************
ERASE_ALG:

          LDA     #%00000010   
          STA     FL1CR           ; ERASE bit on
          LDA     FL1BPR          ; dummy read FLBPR

          LDHX    ADRS            ; write anything
          STA     ,X              ; to desired range
          D_US    #T10US         ; wait 10us (tNVS)

          LDA     #%00001010
          STA     FL1CR           ; ERASE bit on, HVEN bit on
          D_MS    #T1MS         ; wait 1ms (tERASE), modifies X!

          LDA     #%00001000
          STA     FL1CR           ; ERASE bit on, HVEN bit off
          D_US    #T5US         ; wait 5us (tNVH), A zero on exit

          STA     FL1CR           ; ERASE bit off
          D_US    #T1US         ; wait 1us (tRCV)
   
          JMP     SUCC            ; finish with ACK
ERASE_ALG_END:
;*******************************************************************************************
WR_ALG:
          LDA     #%00000001
          STA     FL1CR           ; PGM bit on
          LDA     FL1BPR          ; dummy read FLBPR

          LDHX    ADRS            ; prepare addrs'
          STA     ,X              ; and write to desired range
          D_US    #T10US         ; wait 10us (tNVS)

          LDA     #%00001001
          STA     FL1CR           ; PGM bit on, HVEN bit on
          D_US    #T5US         ; wait 5us (tPGS)

          LDHX    #DAT            ; prepare addrs'
          TXS
          LDHX    ADRS
          MOV     LEN,POM
WR_ALG_L1:
          PULA
          STA     ,X
          AIX     #1
          D_US    #T30US         ; wait 30us (tPROG)
          DBNZ    POM,WR_ALG_L1   ; copy desired block of data

          LDA     #%00001000
          STA     FL1CR           ; PGM bit on, HVEN bit off
          D_US    #T5US         ; wait 5us (tNVH), A zero on exit

          STA     FL1CR           ; PGM bit off
          D_US    #T1US         ; wait 1us (tRCV)
   
          JMP     RETWR           ; finish with ACK (& restore STACK before)
WR_ALG_END:
;*******************************************************************************************
; SIZE = 32 END /all FLBPR, FLCR and EECR registers are fixed to FLASH-1 or EEPROM-1/
;*******************************************************************************************
   ENDIF
END            
