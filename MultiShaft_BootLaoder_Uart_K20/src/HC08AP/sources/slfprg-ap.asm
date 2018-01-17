;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-ap.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    AP main bootloader file
;      Platform:       HC08
;      $Version: 6.0.11.0$
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

; labels SCI, SIZE and IRQOPTION defined externally:
; SIZE = 8, 16, 32, 64 depending whether what memory size of AP family is required
; 
; IRQOPTION *NOT* defined >> regular version using 32768Hz xtal
; IRQOPTION defined >> regular version using IRQ option (bootloading won't start if IRQ high)
;
; label SCI = 0, 1 selects what SCI channel is used (0 regular SCI, 1 IRSCI)

   IFNDEF SCI
SCI      EQU      0
   ENDIF   

    include "reg-ap.h"


RCS_ENA      EQU      0        ; READ COMMAND SUPPORTED?

  IF RCS_ENA = 1
RCS          EQU      $80      ; READ COMMAND SUPPORTED
  ELSE
RCS          EQU      0        ; READ COMMAND unSUPPORTED
  ENDIF

VER_NUM      EQU      1        ; FC protocol version number

IDENTS      MACRO
          IF SIZE = 8
            DC.B      'AP8'      ; AP8 string
          ENDIF
          IF SIZE = 16
            DC.B      'AP16'     ; AP16 string
          ENDIF
          IF SIZE = 32
            DC.B      'AP32'     ; AP32 string
          ENDIF
          IF SIZE = 64
            DC.B      'AP64'     ; AP64 string
          ENDIF

            DC.B      '-XR'      ; Xtal 32768 reqd., ROM used 

          IFDEF IRQOPTION
            DC.B      '-irq'     ; IRQ option used
          ENDIF

            DC.B      0
            ENDM

ERBLK_LEN    EQU      512
WRBLK_LEN    EQU      64      

FLS_BEG      EQU      $0860   ; ALL FLASH START AT THIS ADDRESS
 
          IF SIZE = 8
FLS_END      EQU      $25B0   ; this is APL_VECT address (from SLFPRG-AP8.PRM file)
          ENDIF
          
          IF SIZE = 16
FLS_END      EQU      $45B0   ; this is APL_VECT address (from SLFPRG-AP16.PRM file)
          ENDIF
          
          IF SIZE = 32
FLS_END      EQU      $85B0   ; this is APL_VECT address (from SLFPRG-AP32.PRM file)
          ENDIF

          IF SIZE = 64
FLS_END      EQU      $F9B0   ; this is APL_VECT address (from SLFPRG-AP64.PRM file)
          ENDIF

INT_VECT     EQU      $FFD0

ERARNGE      EQU      $FCE4
PRGRNGE      EQU      $FC34

SPEED        EQU      15          ; 4 x f(op) [MHz]

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
   
   XDEF    MORDEF
  
WR_DATA      EQU       'W'
RD_DATA      EQU       'R'
ENDPRG       EQU       'Q'
ERASE        EQU       'E'
ACK          EQU       $FC
IDENT        EQU       'I'

T100MS       EQU       128

ILOP         MACRO
             DC.B      $32             ; this is illegal operation code
             ENDM
;*******************************************************************************************
MY_ZEROPAGE:   SECTION  SHORT

FILE_PTR:

BUS_SPD      DS.B  1              ; Indicates 4x bus frequency
DATASIZE     DS.B  1              ; Data size to be programmed
START_ADDR   DS.W  1              ; FLASH start address
DATAARRAY    DS.B WRBLK_LEN       ; Reserved data array

ADRS:        DS.W  1
LEN:         DS.B  1
STSRSR:      DS.B  1         ; storage for SRSR reg.

DEFAULT_RAM:    SECTION

;*******************************************************************************************

MOR_PROT_ROM:   SECTION
MORDEF:  DC.B   $FF            ; MOR reg. must be defined here and is valid for the application
; Xtal oscillator as CGMXCLK source defined here (rather strong hardware limitation!)
DEFAULT_ROM:   SECTION

;*******************************************************************************************
APL_VECT_ROM:   SECTION

APL_VECT:
PRI:    DC.B    0,0,$80,0,0,0,0,0    ; 8 bytes reserved for bootloader's private use
        
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

DEFAULT_ROM:   SECTION
        
ID_STRING1:
        DC.B   VER_NUM | RCS ; version number & "Read command supported" flag
        DC.W   FLS_BEG       ; START ADDRESS OF FLASH   
        DC.W   FLS_END          ; END ADDRESS OF FLASH   
        DC.W   APL_VECT        ; POINTER TO APPLICATION VECTOR TABLE
        DC.W   INT_VECT        ; POINTER TO BEGINING OF FLASH INT. VECTORS
        DC.W   ERBLK_LEN        ; ERASE BLCK LENGTH OF FLASH ALG.
        DC.W   WRBLK_LEN        ; WRITE BLCK LENGTH OF FLASH ALG.
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

PVEC0:  JMP     VEC0

slfprg:                        
        MOV     #%00000001,CONFIG2      ; SCI0 clock source = BUS clock
        MOV     #%00000001,CONFIG1      ; COP disabled

        LDA     #(FLS_END+ERBLK_LEN)/256 ; AP family specific calculation
        STA     FLBPR                   ; is in RAM!!

        CLR     PCTL
        BSET    0,PCTL          ; P = 0, E = 1
        MOV     #$01,PMSH
        MOV     #$C0,PMSL       ; 3.6864 MHz BUS clock
        MOV     #$C0,PMRS
        MOV     #$01,PMDS
        BSET    5,PCTL          ; TURN ON PLL
        BSET    7,PBWC          ; PUT IN AUTO BANDWIDTH MODE
LOOP:   BRCLR   6,PBWC,LOOP     ; WAIT FOR PLL TO LOCK
        BSET    4,PCTL          ; SELECT CGMVCLK TO DRIVE CGMOUT

        BSET    6,SCC1          ; SCI enable
        MOV     #%00001100,SCC2 ; transmit & receive enable
        CLR     SCC3

   IF SCI = 0
        MOV     #%00010001,SCBR ; SCI0: 9600Bd @ 3.68MHz = BUS, BUS/(3 x 2 x 64)
   ENDIF

   IF SCI = 1
        MOV     #%10010011,SCBR ; SCI1: 9600Bd @ 3.68MHz = BUS, BUS/(3 x 8 x !16!)
   ENDIF                  ; SCI1: CKS set here! (BUS clock used)
   
        LDA     SCS1
        MOV     #ACK,SCDR

        LDX     #T100MS
L2:     CLRA
L1:     BRSET   5,SCS1,CAUGHT
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
        
        LDHX    #PRI+2           ; next 6 are from private area
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
        STA     START_ADDR      ; store hi byte
        BSR     READ
        STA     START_ADDR+1   ; store lo byte
        LDHX    #FILE_PTR      ; show where's the buffer
        JSR     ERARNGE         ; call ROM erase routine

        BRA     SUCC            ; refer status back to PC

;*******************************************************************************************
WR_DATA_COM:
        BSR     READ
        STA     ADRS
        STA     START_ADDR     ; store hi byte
        BSR     READ
        STA     ADRS+1
        STA     START_ADDR+1   ; store lo byte
        BSR     READ
        STA     LEN
        STA     DATASIZE       ; store # of bytes to be programmed
        LDHX    #DATAARRAY
WR_DATA_L1:
        BSR     READ
        STA     ,X
        AIX     #1
        DBNZ    LEN,WR_DATA_L1
                               ; START OF SELF-PROGRAMMING
        LDHX    #FILE_PTR      ; show where's the buffer
        JSR     PRGRNGE        ; call ROM erase routine
        
        JMP     SUCC           ; refer status back to PC
;*******************************************************************************************
END            
