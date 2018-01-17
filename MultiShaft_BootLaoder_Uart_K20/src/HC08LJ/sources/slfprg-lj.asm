;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-lj.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    LJ main bootloader file
;      Platform:       HC08
;      $Version: 6.0.12.0$
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

; labels VERSION, SIZE and IRQOPTION defined externally:
; VERSION = 1 >> regular version using 32768Hz xtal
; VERSION = 2 >> version using external clock (here 4.9152MHz, for example)
;                for other clk freq. SCI settings & BUS_SPD must be modified too!
;
; SIZE = 12, 24 depending whether LJ/LK24 or LJ12 is required
; IRQOPTION *NOT* defined >> regular version using 32768Hz xtal
; IRQOPTION defined >> regular version using IRQ option (bootloading won't start if IRQ high)

; NOTE: there's difference between LJ/LK24 and LJ12. 
; LJ/LK24 has FLBPR @ FFCF and in FLASH
; LJ12 has    FLBPR @ FE09 and in RAM


    include "reg-lj.h"

RCS_ENA     EQU     0        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS         EQU     $80      ; READ COMMAND SUPPORTED
  ELSE
RCS         EQU     0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM     EQU     1        ; FC protocol version number

IDENTS      MACRO
          IF SIZE = 12
            DC.B     'LJ12'      ; LJ12 string
          ENDIF
          IF SIZE = 24
            DC.B     'LJ24'      ; LJ24 string
          ENDIF

          IF VERSION = 1
            DC.B     '-XR'      ; Xtal 32768 reqd., ROM used 
          ENDIF

          IF VERSION = 2
            DC.B     '-R-ext'   ; external clock, ROM used
          ENDIF

          IFDEF IRQOPTION                                        
            DC.B     '-irq'     ; IRQ option used
          ENDIF
                     
            DC.B     0
          ENDM

ERBLK_LEN  EQU     128
WRBLK_LEN  EQU     64      
 
          IF SIZE = 12
FLS_BEG    EQU     $C000   ; 12kB FLASH
FLBPRMASK  EQU     $9100   ; this is CPU specific FLBPR mask    
                     ;(this one is rather tricky - FLBPR uses only 7:1 bits in LJ12,
                     ; so it's mangled in order to get right FLBPR value)
INT_VECT   EQU     $FFDA
FLS_END    EQU     $EEBF   ; this is APL_VECT address (from PRM file)
          ENDIF
          IF SIZE = 24
FLS_BEG    EQU     $9000   ; 24kB FLASH
FLBPRMASK  EQU     $8000   ; this is CPU specific FLBPR mask    
                     ;(i.e. bits that are always in the address)
INT_VECT   EQU     $FFD8
FLS_END    EQU     $EEBC   ; this is APL_VECT address (from PRM file)
          ENDIF


ERARNGE    EQU     $FCBE
PRGRNGE    EQU     $FC06

             IF VERSION = 1
SPEED           EQU     15          ; 4 x f(op) [MHz]
             ENDIF

             IF VERSION = 2 
SPEED           EQU     5          ; 4 x f(op) [MHz]
             ENDIF

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
  IF SIZE = 24
           XDEF   VEC19
           XDEF  FLBPR
  ENDIF
  
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

FILE_PTR:

BUS_SPD      DS.B 1          ; Indicates 4x bus frequency
DATASIZE     DS.B 1          ; Data size to be programmed
START_ADDR   DS.W 1          ; FLASH start address
DATAARRAY    DS.B WRBLK_LEN  ; Reserved data array

ADRS:        DS.W   1
LEN:         DS.B   1
STSRSR:      DS.B   1        ; storage for SRSR reg.

DEFAULT_RAM:    SECTION

;*******************************************************************************************
  IF SIZE = 24
FLB_PROT_ROM:   SECTION

FLBPR:  DC.B    (FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN ; FLASH protection block start - MUST CHANGE ACCORDING TO MEMORY MAPPING

  ENDIF
;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRI:    DC.B    0,$80,0,0,0,0,0,0 ; 8 bytes reserved for bootloader's private use
        
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
  IF SIZE = 24
VEC19:  JMP     main            ; vector 19
  ENDIF

DEFAULT_ROM:   SECTION
        
ID_STRING1:
          DC.B   VER_NUM | RCS   ; version number & "Read command supported" flag
          DC.W   FLS_BEG         ; START ADDRESS OF FLASH   
          DC.W   FLS_END            ; END ADDRESS OF FLASH   
          DC.W   APL_VECT          ; POINTER TO APPLICATION VECTOR TABLE
          DC.W   INT_VECT          ; POINTER TO BEGINING OF FLASH INT. VECTORS
          DC.W   ERBLK_LEN          ; ERASE BLCK LENGTH OF FLASH ALG.
          DC.W   WRBLK_LEN          ; WRITE BLCK LENGTH OF FLASH ALG.
ID_STRING1_END:

ID_STRING2:
   IDENTS
ID_STRING2_END:

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

PVEC0:    JMP     VEC0

    IF VERSION = 1
slfprg:                           ; CONFIG2 not touched, so user will define e.g. his own LVi voltage
          MOV     #%10010001,CONFIG1

      IF SIZE = 12
          LDA     #(FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN
          STA     FLBPR                   ; is in RAM!!
      ENDIF
          CLR     PCTL
          BSET    0,PCTL          ; P = 0, E = 1
          MOV     #$01,PMSH
          MOV     #$C0,PMSL       ; 3.6864 MHz
          MOV     #$C0,PMRS
          MOV     #$01,PMDS
          BSET    5,PCTL          ; TURN ON PLL
          BSET    7,PBWC          ; PUT IN AUTO BANDWIDTH MODE
LOOP:     BRCLR   6,PBWC,LOOP     ; WAIT FOR PLL TO LOCK
          BSET    4,PCTL          ; SELECT CGMVCLK TO DRIVE CGMOUT

          BSET    6,SCC1          ; SCI enable
          MOV     #%00001100,SCC2 ; transmit & receive enable
          CLR     SCC3
          MOV     #%10010011,SCBR ; 9600Bd @ 3.68MHz, div by (3 x 8 x 16!), other HC08s div by 64, not 16!
                        ; CKS set here! (BUS clock used)
    ENDIF

    IF VERSION = 2            ; external clock settings
slfprg:                           ; CONFIG2 not touched
          MOV     #%00010001,CONFIG1      ; LVIPWRDisable, COPDisable

      IF SIZE = 12
          LDA     #(FLS_END+ERBLK_LEN-FLBPRMASK)/ERBLK_LEN
          STA     FLBPR                   ; is in RAM!!
      ENDIF
          BSET    6,SCC1                  ; SCI enable
          MOV     #%00001100,SCC2         ; transmit & receive enable
          CLR     SCC3
          MOV        #%10000011,SCBR ; 9600Bd @ 1.2288MHz, div by (1 x 8 x 16!), other HC08s div by 64, not 16!
                        ; CKS set here! (BUS clock used)
    ENDIF

          LDA     SCS1
          MOV     #ACK,SCDR

          LDX     #T100MS
L2:       CLRA
L1:       BRSET   5,SCS1,CAUGHT
          DBNZA   L1
          DBNZX   L2

;       timeout
ENDPRG_COM:
          ILOP          ; generate RESET by doing illegal operation
;*******************************************************************************************
CAUGHT:         ; CAUGHT IN SELF-PROGRAMMING?
          BSR     READ
          CMPA    #ACK
          BNE     ENDPRG_COM
          MOV     #SPEED,BUS_SPD   ; feed the speed

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
          
          LDHX    #PRI+1           ; next 6 are from private area
          MOV     #6,LEN
          BSR     WRITE_LOOP

          LDA     FLBPR
          BSR     WRITE           ; last byte would be FLBPR, just for info
              
          MOV     #ID_STRING2_END-ID_STRING2, LEN
          LDHX    #ID_STRING2
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
ERASE_COM:
          BSR     READ
          STA     START_ADDR     ; store hi byte
          BSR     READ
          STA     START_ADDR+1   ; store lo byte
          LDHX    #FILE_PTR      ; show where's the buffer
          JSR     ERARNGE        ; call ROM erase routine
          BRA     SUCC           ; refer status back to PC

;*******************************************************************************************
WR_DATA_COM:
          BSR     READ
          STA     ADRS
          STA     START_ADDR    ; store hi byte
          BSR     READ
          STA     ADRS+1
          STA     START_ADDR+1  ; store lo byte
          BSR     READ
          STA     LEN
          STA     DATASIZE      ; store # of bytes to be programmed
          LDHX    #DATAARRAY
WR_DATA_L1:
          BSR     READ
          STA     ,X
          AIX     #1
          DBNZ    LEN,WR_DATA_L1
                                  ; START OF SELF-PROGRAMMING
          LDHX    #FILE_PTR       ; show where's the buffer
          JSR     PRGRNGE         ; call ROM erase routine
        
          JMP     SUCC            ; refer status back to PC
;*******************************************************************************************
END            
