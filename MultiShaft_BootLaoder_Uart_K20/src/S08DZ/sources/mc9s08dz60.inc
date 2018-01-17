; Based on CPU DB MC9S08DZ60_64, version 2.87.006 (RegistersPrg V2.03)

; ###################################################################
;     Filename  : MC9S08DZ60.inc
;     Processor : MC9S08DZ60FEE
;     FileFormat: V2.03
;     DataSheet : MC9S08DZ60 Rev. 0.05 8/5/2005
;     Compiler  : CodeWarrior compiler
;     Date/Time : 13.02.2006, 16:03
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     (c) Copyright UNIS, spol. s r.o. 1997-2006
;     UNIS, spol. s r.o.
;     Jundrovska 33
;     624 00 Brno
;     Czech Republic
;     http      : www.processorexpert.com
;     mail      : info@processorexpert.com
;
;     File-Format-Revisions:
;      - 14.11.2005, V2.00 :
;               - Deprecated symbols added for backward compatibility (section at the end of this file)
;      - 15.11.2005, V2.01 :
;               - Fixed invalid instruction in macro __RESET_WATCHDOG for HCS12 family.
;      - 17.12.2005, V2.02 :
;               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
;      - 16.01.2006, V2.03 :
;               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
;               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
;
;     CPU Registers Revisions:
;      - none
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROMStart:           equ   $00001900
ROMEnd:             equ   $0000FFAF
Z_RAMStart:         equ   $00000080
Z_RAMEnd:           equ   $000000FF
RAMStart:           equ   $00000100
RAMEnd:             equ   $0000107F
ROM1Start:          equ   $00001080
ROM1End:            equ   $000013FF
EEPROMStart:        equ   $00001400
EEPROMEnd:          equ   $000017FF
;
Vacmp2:             equ   $0000FFC0
Vacmp1:             equ   $0000FFC2
Vcantx:             equ   $0000FFC4
Vcanrx:             equ   $0000FFC6
Vcanerr:            equ   $0000FFC8
Vcanwu:             equ   $0000FFCA
Vrtc:               equ   $0000FFCC
Viic:               equ   $0000FFCE
Vadc:               equ   $0000FFD0
Vport:              equ   $0000FFD2
Vsci2tx:            equ   $0000FFD4
Vsci2rx:            equ   $0000FFD6
Vsci2err:           equ   $0000FFD8
Vsci1tx:            equ   $0000FFDA
Vsci1rx:            equ   $0000FFDC
Vsci1err:           equ   $0000FFDE
Vspi1:              equ   $0000FFE0
Vtpm2ovf:           equ   $0000FFE2
Vtpm2ch1:           equ   $0000FFE4
Vtpm2ch0:           equ   $0000FFE6
Vtpm1ovf:           equ   $0000FFE8
Vtpm1ch5:           equ   $0000FFEA
Vtpm1ch4:           equ   $0000FFEC
Vtpm1ch3:           equ   $0000FFEE
Vtpm1ch2:           equ   $0000FFF0
Vtpm1ch1:           equ   $0000FFF2
Vtpm1ch0:           equ   $0000FFF4
Vlol:               equ   $0000FFF6
Vlvd:               equ   $0000FFF8
Virq:               equ   $0000FFFA
Vswi:               equ   $0000FFFC
Vreset:             equ   $0000FFFE
;


;*** PTAD - Port A Data Register; 0x00000000 ***
PTAD:               equ    $00000000                                ;*** PTAD - Port A Data Register; 0x00000000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAD_PTAD0:         equ    0                                         ; Port A Data Register Bit 0
PTAD_PTAD1:         equ    1                                         ; Port A Data Register Bit 1
PTAD_PTAD2:         equ    2                                         ; Port A Data Register Bit 2
PTAD_PTAD3:         equ    3                                         ; Port A Data Register Bit 3
PTAD_PTAD4:         equ    4                                         ; Port A Data Register Bit 4
PTAD_PTAD5:         equ    5                                         ; Port A Data Register Bit 5
PTAD_PTAD6:         equ    6                                         ; Port A Data Register Bit 6
PTAD_PTAD7:         equ    7                                         ; Port A Data Register Bit 7
; bit position masks
mPTAD_PTAD0:        equ    %00000001
mPTAD_PTAD1:        equ    %00000010
mPTAD_PTAD2:        equ    %00000100
mPTAD_PTAD3:        equ    %00001000
mPTAD_PTAD4:        equ    %00010000
mPTAD_PTAD5:        equ    %00100000
mPTAD_PTAD6:        equ    %01000000
mPTAD_PTAD7:        equ    %10000000


;*** PTADD - Data Direction Register A; 0x00000001 ***
PTADD:              equ    $00000001                                ;*** PTADD - Data Direction Register A; 0x00000001 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0:       equ    0                                         ; Data Direction for Port A Bit 0
PTADD_PTADD1:       equ    1                                         ; Data Direction for Port A Bit 1
PTADD_PTADD2:       equ    2                                         ; Data Direction for Port A Bit 2
PTADD_PTADD3:       equ    3                                         ; Data Direction for Port A Bit 3
PTADD_PTADD4:       equ    4                                         ; Data Direction for Port A Bit 4
PTADD_PTADD5:       equ    5                                         ; Data Direction for Port A Bit 5
PTADD_PTADD6:       equ    6                                         ; Data Direction for Port A Bit 6
PTADD_PTADD7:       equ    7                                         ; Data Direction for Port A Bit 7
; bit position masks
mPTADD_PTADD0:      equ    %00000001
mPTADD_PTADD1:      equ    %00000010
mPTADD_PTADD2:      equ    %00000100
mPTADD_PTADD3:      equ    %00001000
mPTADD_PTADD4:      equ    %00010000
mPTADD_PTADD5:      equ    %00100000
mPTADD_PTADD6:      equ    %01000000
mPTADD_PTADD7:      equ    %10000000


;*** PTBD - Port B Data Register; 0x00000002 ***
PTBD:               equ    $00000002                                ;*** PTBD - Port B Data Register; 0x00000002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBD_PTBD0:         equ    0                                         ; Port B Data Register Bit 0
PTBD_PTBD1:         equ    1                                         ; Port B Data Register Bit 1
PTBD_PTBD2:         equ    2                                         ; Port B Data Register Bit 2
PTBD_PTBD3:         equ    3                                         ; Port B Data Register Bit 3
PTBD_PTBD4:         equ    4                                         ; Port B Data Register Bit 4
PTBD_PTBD5:         equ    5                                         ; Port B Data Register Bit 5
PTBD_PTBD6:         equ    6                                         ; Port B Data Register Bit 6
PTBD_PTBD7:         equ    7                                         ; Port B Data Register Bit 7
; bit position masks
mPTBD_PTBD0:        equ    %00000001
mPTBD_PTBD1:        equ    %00000010
mPTBD_PTBD2:        equ    %00000100
mPTBD_PTBD3:        equ    %00001000
mPTBD_PTBD4:        equ    %00010000
mPTBD_PTBD5:        equ    %00100000
mPTBD_PTBD6:        equ    %01000000
mPTBD_PTBD7:        equ    %10000000


;*** PTBDD - Data Direction Register B; 0x00000003 ***
PTBDD:              equ    $00000003                                ;*** PTBDD - Data Direction Register B; 0x00000003 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0:       equ    0                                         ; Data Direction for Port B Bit 0
PTBDD_PTBDD1:       equ    1                                         ; Data Direction for Port B Bit 1
PTBDD_PTBDD2:       equ    2                                         ; Data Direction for Port B Bit 2
PTBDD_PTBDD3:       equ    3                                         ; Data Direction for Port B Bit 3
PTBDD_PTBDD4:       equ    4                                         ; Data Direction for Port B Bit 4
PTBDD_PTBDD5:       equ    5                                         ; Data Direction for Port B Bit 5
PTBDD_PTBDD6:       equ    6                                         ; Data Direction for Port B Bit 6
PTBDD_PTBDD7:       equ    7                                         ; Data Direction for Port B Bit 7
; bit position masks
mPTBDD_PTBDD0:      equ    %00000001
mPTBDD_PTBDD1:      equ    %00000010
mPTBDD_PTBDD2:      equ    %00000100
mPTBDD_PTBDD3:      equ    %00001000
mPTBDD_PTBDD4:      equ    %00010000
mPTBDD_PTBDD5:      equ    %00100000
mPTBDD_PTBDD6:      equ    %01000000
mPTBDD_PTBDD7:      equ    %10000000


;*** PTCD - Port C Data Register; 0x00000004 ***
PTCD:               equ    $00000004                                ;*** PTCD - Port C Data Register; 0x00000004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCD_PTCD0:         equ    0                                         ; Port C Data Register Bit 0
PTCD_PTCD1:         equ    1                                         ; Port C Data Register Bit 1
PTCD_PTCD2:         equ    2                                         ; Port C Data Register Bit 2
PTCD_PTCD3:         equ    3                                         ; Port C Data Register Bit 3
PTCD_PTCD4:         equ    4                                         ; Port C Data Register Bit 4
PTCD_PTCD5:         equ    5                                         ; Port C Data Register Bit 5
PTCD_PTCD6:         equ    6                                         ; Port C Data Register Bit 6
PTCD_PTCD7:         equ    7                                         ; Port C Data Register Bit 7
; bit position masks
mPTCD_PTCD0:        equ    %00000001
mPTCD_PTCD1:        equ    %00000010
mPTCD_PTCD2:        equ    %00000100
mPTCD_PTCD3:        equ    %00001000
mPTCD_PTCD4:        equ    %00010000
mPTCD_PTCD5:        equ    %00100000
mPTCD_PTCD6:        equ    %01000000
mPTCD_PTCD7:        equ    %10000000


;*** PTCDD - Data Direction Register C; 0x00000005 ***
PTCDD:              equ    $00000005                                ;*** PTCDD - Data Direction Register C; 0x00000005 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0:       equ    0                                         ; Data Direction for Port C Bit 0
PTCDD_PTCDD1:       equ    1                                         ; Data Direction for Port C Bit 1
PTCDD_PTCDD2:       equ    2                                         ; Data Direction for Port C Bit 2
PTCDD_PTCDD3:       equ    3                                         ; Data Direction for Port C Bit 3
PTCDD_PTCDD4:       equ    4                                         ; Data Direction for Port C Bit 4
PTCDD_PTCDD5:       equ    5                                         ; Data Direction for Port C Bit 5
PTCDD_PTCDD6:       equ    6                                         ; Data Direction for Port C Bit 6
PTCDD_PTCDD7:       equ    7                                         ; Data Direction for Port C Bit 7
; bit position masks
mPTCDD_PTCDD0:      equ    %00000001
mPTCDD_PTCDD1:      equ    %00000010
mPTCDD_PTCDD2:      equ    %00000100
mPTCDD_PTCDD3:      equ    %00001000
mPTCDD_PTCDD4:      equ    %00010000
mPTCDD_PTCDD5:      equ    %00100000
mPTCDD_PTCDD6:      equ    %01000000
mPTCDD_PTCDD7:      equ    %10000000


;*** PTDD - Port D Data Register; 0x00000006 ***
PTDD:               equ    $00000006                                ;*** PTDD - Port D Data Register; 0x00000006 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDD_PTDD0:         equ    0                                         ; Port D Data Register Bit 0
PTDD_PTDD1:         equ    1                                         ; Port D Data Register Bit 1
PTDD_PTDD2:         equ    2                                         ; Port D Data Register Bit 2
PTDD_PTDD3:         equ    3                                         ; Port D Data Register Bit 3
PTDD_PTDD4:         equ    4                                         ; Port D Data Register Bit 4
PTDD_PTDD5:         equ    5                                         ; Port D Data Register Bit 5
PTDD_PTDD6:         equ    6                                         ; Port D Data Register Bit 6
PTDD_PTDD7:         equ    7                                         ; Port D Data Register Bit 7
; bit position masks
mPTDD_PTDD0:        equ    %00000001
mPTDD_PTDD1:        equ    %00000010
mPTDD_PTDD2:        equ    %00000100
mPTDD_PTDD3:        equ    %00001000
mPTDD_PTDD4:        equ    %00010000
mPTDD_PTDD5:        equ    %00100000
mPTDD_PTDD6:        equ    %01000000
mPTDD_PTDD7:        equ    %10000000


;*** PTDDD - Data Direction Register D; 0x00000007 ***
PTDDD:              equ    $00000007                                ;*** PTDDD - Data Direction Register D; 0x00000007 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0:       equ    0                                         ; Data Direction for Port D Bit 0
PTDDD_PTDDD1:       equ    1                                         ; Data Direction for Port D Bit 1
PTDDD_PTDDD2:       equ    2                                         ; Data Direction for Port D Bit 2
PTDDD_PTDDD3:       equ    3                                         ; Data Direction for Port D Bit 3
PTDDD_PTDDD4:       equ    4                                         ; Data Direction for Port D Bit 4
PTDDD_PTDDD5:       equ    5                                         ; Data Direction for Port D Bit 5
PTDDD_PTDDD6:       equ    6                                         ; Data Direction for Port D Bit 6
PTDDD_PTDDD7:       equ    7                                         ; Data Direction for Port D Bit 7
; bit position masks
mPTDDD_PTDDD0:      equ    %00000001
mPTDDD_PTDDD1:      equ    %00000010
mPTDDD_PTDDD2:      equ    %00000100
mPTDDD_PTDDD3:      equ    %00001000
mPTDDD_PTDDD4:      equ    %00010000
mPTDDD_PTDDD5:      equ    %00100000
mPTDDD_PTDDD6:      equ    %01000000
mPTDDD_PTDDD7:      equ    %10000000


;*** PTED - Port E Data Register; 0x00000008 ***
PTED:               equ    $00000008                                ;*** PTED - Port E Data Register; 0x00000008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTED_PTED0:         equ    0                                         ; Port E Data Register Bit 0
PTED_PTED1:         equ    1                                         ; Port E Data Register Bit 1
PTED_PTED2:         equ    2                                         ; Port E Data Register Bit 2
PTED_PTED3:         equ    3                                         ; Port E Data Register Bit 3
PTED_PTED4:         equ    4                                         ; Port E Data Register Bit 4
PTED_PTED5:         equ    5                                         ; Port E Data Register Bit 5
PTED_PTED6:         equ    6                                         ; Port E Data Register Bit 6
PTED_PTED7:         equ    7                                         ; Port E Data Register Bit 7
; bit position masks
mPTED_PTED0:        equ    %00000001
mPTED_PTED1:        equ    %00000010
mPTED_PTED2:        equ    %00000100
mPTED_PTED3:        equ    %00001000
mPTED_PTED4:        equ    %00010000
mPTED_PTED5:        equ    %00100000
mPTED_PTED6:        equ    %01000000
mPTED_PTED7:        equ    %10000000


;*** PTEDD - Data Direction Register E; 0x00000009 ***
PTEDD:              equ    $00000009                                ;*** PTEDD - Data Direction Register E; 0x00000009 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDD_PTEDD0:       equ    0                                         ; Data Direction for Port E Bit 0
PTEDD_PTEDD1:       equ    1                                         ; Data Direction for Port E Bit 1
PTEDD_PTEDD2:       equ    2                                         ; Data Direction for Port E Bit 2
PTEDD_PTEDD3:       equ    3                                         ; Data Direction for Port E Bit 3
PTEDD_PTEDD4:       equ    4                                         ; Data Direction for Port E Bit 4
PTEDD_PTEDD5:       equ    5                                         ; Data Direction for Port E Bit 5
PTEDD_PTEDD6:       equ    6                                         ; Data Direction for Port E Bit 6
PTEDD_PTEDD7:       equ    7                                         ; Data Direction for Port E Bit 7
; bit position masks
mPTEDD_PTEDD0:      equ    %00000001
mPTEDD_PTEDD1:      equ    %00000010
mPTEDD_PTEDD2:      equ    %00000100
mPTEDD_PTEDD3:      equ    %00001000
mPTEDD_PTEDD4:      equ    %00010000
mPTEDD_PTEDD5:      equ    %00100000
mPTEDD_PTEDD6:      equ    %01000000
mPTEDD_PTEDD7:      equ    %10000000


;*** PTFD - Port F Data Register; 0x0000000A ***
PTFD:               equ    $0000000A                                ;*** PTFD - Port F Data Register; 0x0000000A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFD_PTFD0:         equ    0                                         ; Port F Data Register Bit 0
PTFD_PTFD1:         equ    1                                         ; Port F Data Register Bit 1
PTFD_PTFD2:         equ    2                                         ; Port F Data Register Bit 2
PTFD_PTFD3:         equ    3                                         ; Port F Data Register Bit 3
PTFD_PTFD4:         equ    4                                         ; Port F Data Register Bit 4
PTFD_PTFD5:         equ    5                                         ; Port F Data Register Bit 5
PTFD_PTFD6:         equ    6                                         ; Port F Data Register Bit 6
PTFD_PTFD7:         equ    7                                         ; Port F Data Register Bit 7
; bit position masks
mPTFD_PTFD0:        equ    %00000001
mPTFD_PTFD1:        equ    %00000010
mPTFD_PTFD2:        equ    %00000100
mPTFD_PTFD3:        equ    %00001000
mPTFD_PTFD4:        equ    %00010000
mPTFD_PTFD5:        equ    %00100000
mPTFD_PTFD6:        equ    %01000000
mPTFD_PTFD7:        equ    %10000000


;*** PTFDD - Data Direction Register F; 0x0000000B ***
PTFDD:              equ    $0000000B                                ;*** PTFDD - Data Direction Register F; 0x0000000B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDD_PTFDD0:       equ    0                                         ; Data Direction for Port F Bit 0
PTFDD_PTFDD1:       equ    1                                         ; Data Direction for Port F Bit 1
PTFDD_PTFDD2:       equ    2                                         ; Data Direction for Port F Bit 2
PTFDD_PTFDD3:       equ    3                                         ; Data Direction for Port F Bit 3
PTFDD_PTFDD4:       equ    4                                         ; Data Direction for Port F Bit 4
PTFDD_PTFDD5:       equ    5                                         ; Data Direction for Port F Bit 5
PTFDD_PTFDD6:       equ    6                                         ; Data Direction for Port F Bit 6
PTFDD_PTFDD7:       equ    7                                         ; Data Direction for Port F Bit 7
; bit position masks
mPTFDD_PTFDD0:      equ    %00000001
mPTFDD_PTFDD1:      equ    %00000010
mPTFDD_PTFDD2:      equ    %00000100
mPTFDD_PTFDD3:      equ    %00001000
mPTFDD_PTFDD4:      equ    %00010000
mPTFDD_PTFDD5:      equ    %00100000
mPTFDD_PTFDD6:      equ    %01000000
mPTFDD_PTFDD7:      equ    %10000000


;*** PTGD - Port G Data Register; 0x0000000C ***
PTGD:               equ    $0000000C                                ;*** PTGD - Port G Data Register; 0x0000000C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGD_PTGD0:         equ    0                                         ; Port G Data Register Bit 0
PTGD_PTGD1:         equ    1                                         ; Port G Data Register Bit 1
PTGD_PTGD2:         equ    2                                         ; Port G Data Register Bit 2
PTGD_PTGD3:         equ    3                                         ; Port G Data Register Bit 3
PTGD_PTGD4:         equ    4                                         ; Port G Data Register Bit 4
PTGD_PTGD5:         equ    5                                         ; Port G Data Register Bit 5
; bit position masks
mPTGD_PTGD0:        equ    %00000001
mPTGD_PTGD1:        equ    %00000010
mPTGD_PTGD2:        equ    %00000100
mPTGD_PTGD3:        equ    %00001000
mPTGD_PTGD4:        equ    %00010000
mPTGD_PTGD5:        equ    %00100000


;*** PTGDD - Data Direction Register G; 0x0000000D ***
PTGDD:              equ    $0000000D                                ;*** PTGDD - Data Direction Register G; 0x0000000D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDD_PTGDD0:       equ    0                                         ; Data Direction for Port G Bit 0
PTGDD_PTGDD1:       equ    1                                         ; Data Direction for Port G Bit 1
PTGDD_PTGDD2:       equ    2                                         ; Data Direction for Port G Bit 2
PTGDD_PTGDD3:       equ    3                                         ; Data Direction for Port G Bit 3
PTGDD_PTGDD4:       equ    4                                         ; Data Direction for Port G Bit 4
PTGDD_PTGDD5:       equ    5                                         ; Data Direction for Port G Bit 5
; bit position masks
mPTGDD_PTGDD0:      equ    %00000001
mPTGDD_PTGDD1:      equ    %00000010
mPTGDD_PTGDD2:      equ    %00000100
mPTGDD_PTGDD3:      equ    %00001000
mPTGDD_PTGDD4:      equ    %00010000
mPTGDD_PTGDD5:      equ    %00100000


;*** ACMP1SC - Analog Comparator 1 Status and Control Register; 0x0000000E ***
ACMP1SC:            equ    $0000000E                                ;*** ACMP1SC - Analog Comparator 1 Status and Control Register; 0x0000000E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ACMP1SC_ACMOD0:     equ    0                                         ; Analog Comparator Mode Bit 0
ACMP1SC_ACMOD1:     equ    1                                         ; Analog Comparator Mode Bit 1
ACMP1SC_ACOPE:      equ    2                                         ; Analog Comparator Output Pin Enable
ACMP1SC_ACO:        equ    3                                         ; Analog Comparator Output
ACMP1SC_ACIE:       equ    4                                         ; Analog Comparator Interrupt Enable
ACMP1SC_ACF:        equ    5                                         ; Analog Comparator Flag
ACMP1SC_ACBGS:      equ    6                                         ; Analog Comparator Bandgap Select
ACMP1SC_ACME:       equ    7                                         ; Analog Comparator Module Enable
; bit position masks
mACMP1SC_ACMOD0:    equ    %00000001
mACMP1SC_ACMOD1:    equ    %00000010
mACMP1SC_ACOPE:     equ    %00000100
mACMP1SC_ACO:       equ    %00001000
mACMP1SC_ACIE:      equ    %00010000
mACMP1SC_ACF:       equ    %00100000
mACMP1SC_ACBGS:     equ    %01000000
mACMP1SC_ACME:      equ    %10000000


;*** ACMP2SC - Analog Comparator 2 Status and Control Register; 0x0000000F ***
ACMP2SC:            equ    $0000000F                                ;*** ACMP2SC - Analog Comparator 2 Status and Control Register; 0x0000000F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ACMP2SC_ACMOD0:     equ    0                                         ; Analog Comparator Mode Bit 0
ACMP2SC_ACMOD1:     equ    1                                         ; Analog Comparator Mode Bit 1
ACMP2SC_ACOPE:      equ    2                                         ; Analog Comparator Output Pin Enable
ACMP2SC_ACO:        equ    3                                         ; Analog Comparator Output
ACMP2SC_ACIE:       equ    4                                         ; Analog Comparator Interrupt Enable
ACMP2SC_ACF:        equ    5                                         ; Analog Comparator Flag
ACMP2SC_ACBGS:      equ    6                                         ; Analog Comparator Bandgap Select
ACMP2SC_ACME:       equ    7                                         ; Analog Comparator Module Enable
; bit position masks
mACMP2SC_ACMOD0:    equ    %00000001
mACMP2SC_ACMOD1:    equ    %00000010
mACMP2SC_ACOPE:     equ    %00000100
mACMP2SC_ACO:       equ    %00001000
mACMP2SC_ACIE:      equ    %00010000
mACMP2SC_ACF:       equ    %00100000
mACMP2SC_ACBGS:     equ    %01000000
mACMP2SC_ACME:      equ    %10000000


;*** ADSC1 - Status and Control Register; 0x00000010 ***
ADSC1:              equ    $00000010                                ;*** ADSC1 - Status and Control Register; 0x00000010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSC1_ADCH0:        equ    0                                         ; Input Channel Select Bit 0
ADSC1_ADCH1:        equ    1                                         ; Input Channel Select Bit 1
ADSC1_ADCH2:        equ    2                                         ; Input Channel Select Bit 2
ADSC1_ADCH3:        equ    3                                         ; Input Channel Select Bit 3
ADSC1_ADCH4:        equ    4                                         ; Input Channel Select Bit 4
ADSC1_ADCO:         equ    5                                         ; Continuous Conversion Enable
ADSC1_AIEN:         equ    6                                         ; Interrupt Enable
ADSC1_COCO:         equ    7                                         ; Conversion Complete Flag
; bit position masks
mADSC1_ADCH0:       equ    %00000001
mADSC1_ADCH1:       equ    %00000010
mADSC1_ADCH2:       equ    %00000100
mADSC1_ADCH3:       equ    %00001000
mADSC1_ADCH4:       equ    %00010000
mADSC1_ADCO:        equ    %00100000
mADSC1_AIEN:        equ    %01000000
mADSC1_COCO:        equ    %10000000


;*** ADSC2 - Status and Control Register 2; 0x00000011 ***
ADSC2:              equ    $00000011                                ;*** ADSC2 - Status and Control Register 2; 0x00000011 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSC2_ACFGT:        equ    4                                         ; Compare Function Greater Than Enable
ADSC2_ACFE:         equ    5                                         ; Compare Function Enable
ADSC2_ADTRG:        equ    6                                         ; Conversion Trigger Select
ADSC2_ADACT:        equ    7                                         ; Conversion Active
; bit position masks
mADSC2_ACFGT:       equ    %00010000
mADSC2_ACFE:        equ    %00100000
mADSC2_ADTRG:       equ    %01000000
mADSC2_ADACT:       equ    %10000000


;*** ADR - ADC Result Data Right Justified; 0x00000012 ***
ADR:                equ    $00000012                                ;*** ADR - ADC Result Data Right Justified; 0x00000012 ***


;*** ADRH - ADC Result Data Right Justified High; 0x00000012 ***
ADRH:               equ    $00000012                                ;*** ADRH - ADC Result Data Right Justified High; 0x00000012 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRH_ADR8:          equ    0                                         ; ADC Result Data Bit 8
ADRH_ADR9:          equ    1                                         ; ADC Result Data Bit 9
; bit position masks
mADRH_ADR8:         equ    %00000001
mADRH_ADR9:         equ    %00000010


;*** ADRL - ADC Result Data Right Justified Low; 0x00000013 ***
ADRL:               equ    $00000013                                ;*** ADRL - ADC Result Data Right Justified Low; 0x00000013 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRL_ADR0:          equ    0                                         ; ADC Result Data Bit 0
ADRL_ADR1:          equ    1                                         ; ADC Result Data Bit 1
ADRL_ADR2:          equ    2                                         ; ADC Result Data Bit 2
ADRL_ADR3:          equ    3                                         ; ADC Result Data Bit 3
ADRL_ADR4:          equ    4                                         ; ADC Result Data Bit 4
ADRL_ADR5:          equ    5                                         ; ADC Result Data Bit 5
ADRL_ADR6:          equ    6                                         ; ADC Result Data Bit 6
ADRL_ADR7:          equ    7                                         ; ADC Result Data Bit 7
; bit position masks
mADRL_ADR0:         equ    %00000001
mADRL_ADR1:         equ    %00000010
mADRL_ADR2:         equ    %00000100
mADRL_ADR3:         equ    %00001000
mADRL_ADR4:         equ    %00010000
mADRL_ADR5:         equ    %00100000
mADRL_ADR6:         equ    %01000000
mADRL_ADR7:         equ    %10000000


;*** ADCV - Compare Value Register; 0x00000014 ***
ADCV:               equ    $00000014                                ;*** ADCV - Compare Value Register; 0x00000014 ***


;*** ADCVH - Compare Value Register High; 0x00000014 ***
ADCVH:              equ    $00000014                                ;*** ADCVH - Compare Value Register High; 0x00000014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCVH_ADCV8:        equ    0                                         ; Compare Function Value 8
ADCVH_ADCV9:        equ    1                                         ; Compare Function Value 9
; bit position masks
mADCVH_ADCV8:       equ    %00000001
mADCVH_ADCV9:       equ    %00000010


;*** ADCVL - Compare Value Register Low; 0x00000015 ***
ADCVL:              equ    $00000015                                ;*** ADCVL - Compare Value Register Low; 0x00000015 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCVL_ADCV0:        equ    0                                         ; Compare Function Value 0
ADCVL_ADCV1:        equ    1                                         ; Compare Function Value 1
ADCVL_ADCV2:        equ    2                                         ; Compare Function Value 2
ADCVL_ADCV3:        equ    3                                         ; Compare Function Value 3
ADCVL_ADCV4:        equ    4                                         ; Compare Function Value 4
ADCVL_ADCV5:        equ    5                                         ; Compare Function Value 5
ADCVL_ADCV6:        equ    6                                         ; Compare Function Value 6
ADCVL_ADCV7:        equ    7                                         ; Compare Function Value 7
; bit position masks
mADCVL_ADCV0:       equ    %00000001
mADCVL_ADCV1:       equ    %00000010
mADCVL_ADCV2:       equ    %00000100
mADCVL_ADCV3:       equ    %00001000
mADCVL_ADCV4:       equ    %00010000
mADCVL_ADCV5:       equ    %00100000
mADCVL_ADCV6:       equ    %01000000
mADCVL_ADCV7:       equ    %10000000


;*** ADCFG - Configuration Register; 0x00000016 ***
ADCFG:              equ    $00000016                                ;*** ADCFG - Configuration Register; 0x00000016 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCFG_ADICLK0:      equ    0                                         ; Input Clock Select Bit 0
ADCFG_ADICLK1:      equ    1                                         ; Input Clock Select Bit 1
ADCFG_MODE0:        equ    2                                         ; Conversion Mode Selection Bit 0
ADCFG_MODE1:        equ    3                                         ; Conversion Mode Selection Bit 1
ADCFG_ADLSMP:       equ    4                                         ; Long Sample Time Configuration
ADCFG_ADIV0:        equ    5                                         ; Clock Divide Select Bit 0
ADCFG_ADIV1:        equ    6                                         ; Clock Divide Select Bit 1
ADCFG_ADLPC:        equ    7                                         ; Low Power Configuration
; bit position masks
mADCFG_ADICLK0:     equ    %00000001
mADCFG_ADICLK1:     equ    %00000010
mADCFG_MODE0:       equ    %00000100
mADCFG_MODE1:       equ    %00001000
mADCFG_ADLSMP:      equ    %00010000
mADCFG_ADIV0:       equ    %00100000
mADCFG_ADIV1:       equ    %01000000
mADCFG_ADLPC:       equ    %10000000


;*** APCTL1 - ADC Pin Control 1 Register; 0x00000017 ***
APCTL1:             equ    $00000017                                ;*** APCTL1 - ADC Pin Control 1 Register; 0x00000017 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL1_ADPC0:       equ    0                                         ; ADC Pin Control 0
APCTL1_ADPC1:       equ    1                                         ; ADC Pin Control 1
APCTL1_ADPC2:       equ    2                                         ; ADC Pin Control 2
APCTL1_ADPC3:       equ    3                                         ; ADC Pin Control 3
APCTL1_ADPC4:       equ    4                                         ; ADC Pin Control 4
APCTL1_ADPC5:       equ    5                                         ; ADC Pin Control 5
APCTL1_ADPC6:       equ    6                                         ; ADC Pin Control 6
APCTL1_ADPC7:       equ    7                                         ; ADC Pin Control 7
; bit position masks
mAPCTL1_ADPC0:      equ    %00000001
mAPCTL1_ADPC1:      equ    %00000010
mAPCTL1_ADPC2:      equ    %00000100
mAPCTL1_ADPC3:      equ    %00001000
mAPCTL1_ADPC4:      equ    %00010000
mAPCTL1_ADPC5:      equ    %00100000
mAPCTL1_ADPC6:      equ    %01000000
mAPCTL1_ADPC7:      equ    %10000000


;*** APCTL2 - ADC Pin Control 2 Register; 0x00000018 ***
APCTL2:             equ    $00000018                                ;*** APCTL2 - ADC Pin Control 2 Register; 0x00000018 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL2_ADPC8:       equ    0                                         ; ADC Pin Control 8
APCTL2_ADPC9:       equ    1                                         ; ADC Pin Control 9
APCTL2_ADPC10:      equ    2                                         ; ADC Pin Control 10
APCTL2_ADPC11:      equ    3                                         ; ADC Pin Control 11
APCTL2_ADPC12:      equ    4                                         ; ADC Pin Control 12
APCTL2_ADPC13:      equ    5                                         ; ADC Pin Control 13
APCTL2_ADPC14:      equ    6                                         ; ADC Pin Control 14
APCTL2_ADPC15:      equ    7                                         ; ADC Pin Control 15
; bit position masks
mAPCTL2_ADPC8:      equ    %00000001
mAPCTL2_ADPC9:      equ    %00000010
mAPCTL2_ADPC10:     equ    %00000100
mAPCTL2_ADPC11:     equ    %00001000
mAPCTL2_ADPC12:     equ    %00010000
mAPCTL2_ADPC13:     equ    %00100000
mAPCTL2_ADPC14:     equ    %01000000
mAPCTL2_ADPC15:     equ    %10000000


;*** APCTL3 - ADC Pin Control 3 Register; 0x00000019 ***
APCTL3:             equ    $00000019                                ;*** APCTL3 - ADC Pin Control 3 Register; 0x00000019 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL3_ADPC16:      equ    0                                         ; ADC Pin Control 16
APCTL3_ADPC17:      equ    1                                         ; ADC Pin Control 17
APCTL3_ADPC18:      equ    2                                         ; ADC Pin Control 18
APCTL3_ADPC19:      equ    3                                         ; ADC Pin Control 19
APCTL3_ADPC20:      equ    4                                         ; ADC Pin Control 20
APCTL3_ADPC21:      equ    5                                         ; ADC Pin Control 21
APCTL3_ADPC22:      equ    6                                         ; ADC Pin Control 22
APCTL3_ADPC23:      equ    7                                         ; ADC Pin Control 23
; bit position masks
mAPCTL3_ADPC16:     equ    %00000001
mAPCTL3_ADPC17:     equ    %00000010
mAPCTL3_ADPC18:     equ    %00000100
mAPCTL3_ADPC19:     equ    %00001000
mAPCTL3_ADPC20:     equ    %00010000
mAPCTL3_ADPC21:     equ    %00100000
mAPCTL3_ADPC22:     equ    %01000000
mAPCTL3_ADPC23:     equ    %10000000


;*** IRQSC - Interrupt Request Status and Control Register; 0x0000001C ***
IRQSC:              equ    $0000001C                                ;*** IRQSC - Interrupt Request Status and Control Register; 0x0000001C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD:       equ    0                                         ; IRQ Detection Mode
IRQSC_IRQIE:        equ    1                                         ; IRQ Interrupt Enable
IRQSC_IRQACK:       equ    2                                         ; IRQ Acknowledge
IRQSC_IRQF:         equ    3                                         ; IRQ Flag
IRQSC_IRQPE:        equ    4                                         ; IRQ Pin Enable
IRQSC_IRQEDG:       equ    5                                         ; Interrupt Request (IRQ) Edge Select
IRQSC_IRQPDD:       equ    6                                         ; Interrupt Request (IRQ) Pull Device Disable
; bit position masks
mIRQSC_IRQMOD:      equ    %00000001
mIRQSC_IRQIE:       equ    %00000010
mIRQSC_IRQACK:      equ    %00000100
mIRQSC_IRQF:        equ    %00001000
mIRQSC_IRQPE:       equ    %00010000
mIRQSC_IRQEDG:      equ    %00100000
mIRQSC_IRQPDD:      equ    %01000000


;*** TPM1SC - TPM 1 Status and Control Register; 0x00000020 ***
TPM1SC:             equ    $00000020                                ;*** TPM1SC - TPM 1 Status and Control Register; 0x00000020 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1SC_PS0:         equ    0                                         ; Prescale Divisor Select Bit 0
TPM1SC_PS1:         equ    1                                         ; Prescale Divisor Select Bit 1
TPM1SC_PS2:         equ    2                                         ; Prescale Divisor Select Bit 2
TPM1SC_CLKSA:       equ    3                                         ; Clock Source Select A
TPM1SC_CLKSB:       equ    4                                         ; Clock Source Select B
TPM1SC_CPWMS:       equ    5                                         ; Center-Aligned PWM Select
TPM1SC_TOIE:        equ    6                                         ; Timer Overflow Interrupt Enable
TPM1SC_TOF:         equ    7                                         ; Timer Overflow Flag
; bit position masks
mTPM1SC_PS0:        equ    %00000001
mTPM1SC_PS1:        equ    %00000010
mTPM1SC_PS2:        equ    %00000100
mTPM1SC_CLKSA:      equ    %00001000
mTPM1SC_CLKSB:      equ    %00010000
mTPM1SC_CPWMS:      equ    %00100000
mTPM1SC_TOIE:       equ    %01000000
mTPM1SC_TOF:        equ    %10000000


;*** TPM1CNT - TPM 1 Counter Register; 0x00000021 ***
TPM1CNT:            equ    $00000021                                ;*** TPM1CNT - TPM 1 Counter Register; 0x00000021 ***


;*** TPM1CNTH - TPM 1 Counter Register High; 0x00000021 ***
TPM1CNTH:           equ    $00000021                                ;*** TPM1CNTH - TPM 1 Counter Register High; 0x00000021 ***


;*** TPM1CNTL - TPM 1 Counter Register Low; 0x00000022 ***
TPM1CNTL:           equ    $00000022                                ;*** TPM1CNTL - TPM 1 Counter Register Low; 0x00000022 ***


;*** TPM1MOD - TPM 1 Timer Counter Modulo Register; 0x00000023 ***
TPM1MOD:            equ    $00000023                                ;*** TPM1MOD - TPM 1 Timer Counter Modulo Register; 0x00000023 ***


;*** TPM1MODH - TPM 1 Timer Counter Modulo Register High; 0x00000023 ***
TPM1MODH:           equ    $00000023                                ;*** TPM1MODH - TPM 1 Timer Counter Modulo Register High; 0x00000023 ***


;*** TPM1MODL - TPM 1 Timer Counter Modulo Register Low; 0x00000024 ***
TPM1MODL:           equ    $00000024                                ;*** TPM1MODL - TPM 1 Timer Counter Modulo Register Low; 0x00000024 ***


;*** TPM1C0SC - TPM 1 Timer Channel 0 Status and Control Register; 0x00000025 ***
TPM1C0SC:           equ    $00000025                                ;*** TPM1C0SC - TPM 1 Timer Channel 0 Status and Control Register; 0x00000025 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C0SC_ELS0A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C0SC_ELS0B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C0SC_MS0A:      equ    4                                         ; Mode Select A for TPM Channel 0
TPM1C0SC_MS0B:      equ    5                                         ; Mode Select B for TPM Channel 0
TPM1C0SC_CH0IE:     equ    6                                         ; Channel 0 Interrupt Enable
TPM1C0SC_CH0F:      equ    7                                         ; Channel 0 Flag
; bit position masks
mTPM1C0SC_ELS0A:    equ    %00000100
mTPM1C0SC_ELS0B:    equ    %00001000
mTPM1C0SC_MS0A:     equ    %00010000
mTPM1C0SC_MS0B:     equ    %00100000
mTPM1C0SC_CH0IE:    equ    %01000000
mTPM1C0SC_CH0F:     equ    %10000000


;*** TPM1C0V - TPM 1 Timer Channel 0 Value Register; 0x00000026 ***
TPM1C0V:            equ    $00000026                                ;*** TPM1C0V - TPM 1 Timer Channel 0 Value Register; 0x00000026 ***


;*** TPM1C0VH - TPM 1 Timer Channel 0 Value Register High; 0x00000026 ***
TPM1C0VH:           equ    $00000026                                ;*** TPM1C0VH - TPM 1 Timer Channel 0 Value Register High; 0x00000026 ***


;*** TPM1C0VL - TPM 1 Timer Channel 0 Value Register Low; 0x00000027 ***
TPM1C0VL:           equ    $00000027                                ;*** TPM1C0VL - TPM 1 Timer Channel 0 Value Register Low; 0x00000027 ***


;*** TPM1C1SC - TPM 1 Timer Channel 1 Status and Control Register; 0x00000028 ***
TPM1C1SC:           equ    $00000028                                ;*** TPM1C1SC - TPM 1 Timer Channel 1 Status and Control Register; 0x00000028 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C1SC_ELS1A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C1SC_ELS1B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C1SC_MS1A:      equ    4                                         ; Mode Select A for TPM Channel 1
TPM1C1SC_MS1B:      equ    5                                         ; Mode Select B for TPM Channel 1
TPM1C1SC_CH1IE:     equ    6                                         ; Channel 1 Interrupt Enable
TPM1C1SC_CH1F:      equ    7                                         ; Channel 1 Flag
; bit position masks
mTPM1C1SC_ELS1A:    equ    %00000100
mTPM1C1SC_ELS1B:    equ    %00001000
mTPM1C1SC_MS1A:     equ    %00010000
mTPM1C1SC_MS1B:     equ    %00100000
mTPM1C1SC_CH1IE:    equ    %01000000
mTPM1C1SC_CH1F:     equ    %10000000


;*** TPM1C1V - TPM 1 Timer Channel 1 Value Register; 0x00000029 ***
TPM1C1V:            equ    $00000029                                ;*** TPM1C1V - TPM 1 Timer Channel 1 Value Register; 0x00000029 ***


;*** TPM1C1VH - TPM 1 Timer Channel 1 Value Register High; 0x00000029 ***
TPM1C1VH:           equ    $00000029                                ;*** TPM1C1VH - TPM 1 Timer Channel 1 Value Register High; 0x00000029 ***


;*** TPM1C1VL - TPM 1 Timer Channel 1 Value Register Low; 0x0000002A ***
TPM1C1VL:           equ    $0000002A                                ;*** TPM1C1VL - TPM 1 Timer Channel 1 Value Register Low; 0x0000002A ***


;*** TPM1C2SC - TPM 1 Timer Channel 2 Status and Control Register; 0x0000002B ***
TPM1C2SC:           equ    $0000002B                                ;*** TPM1C2SC - TPM 1 Timer Channel 2 Status and Control Register; 0x0000002B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C2SC_ELS2A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C2SC_ELS2B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C2SC_MS2A:      equ    4                                         ; Mode Select A for TPM Channel 2
TPM1C2SC_MS2B:      equ    5                                         ; Mode Select B for TPM Channel 2
TPM1C2SC_CH2IE:     equ    6                                         ; Channel 2 Interrupt Enable
TPM1C2SC_CH2F:      equ    7                                         ; Channel 2 Flag
; bit position masks
mTPM1C2SC_ELS2A:    equ    %00000100
mTPM1C2SC_ELS2B:    equ    %00001000
mTPM1C2SC_MS2A:     equ    %00010000
mTPM1C2SC_MS2B:     equ    %00100000
mTPM1C2SC_CH2IE:    equ    %01000000
mTPM1C2SC_CH2F:     equ    %10000000


;*** TPM1C2V - TPM 1 Timer Channel 2 Value Register; 0x0000002C ***
TPM1C2V:            equ    $0000002C                                ;*** TPM1C2V - TPM 1 Timer Channel 2 Value Register; 0x0000002C ***


;*** TPM1C2VH - TPM 1 Timer Channel 2 Value Register High; 0x0000002C ***
TPM1C2VH:           equ    $0000002C                                ;*** TPM1C2VH - TPM 1 Timer Channel 2 Value Register High; 0x0000002C ***


;*** TPM1C2VL - TPM 1 Timer Channel 2 Value Register Low; 0x0000002D ***
TPM1C2VL:           equ    $0000002D                                ;*** TPM1C2VL - TPM 1 Timer Channel 2 Value Register Low; 0x0000002D ***


;*** TPM1C3SC - TPM 1 Timer Channel 3 Status and Control Register; 0x0000002E ***
TPM1C3SC:           equ    $0000002E                                ;*** TPM1C3SC - TPM 1 Timer Channel 3 Status and Control Register; 0x0000002E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C3SC_ELS3A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C3SC_ELS3B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C3SC_MS3A:      equ    4                                         ; Mode Select A for TPM Channel 3
TPM1C3SC_MS3B:      equ    5                                         ; Mode Select B for TPM Channel 3
TPM1C3SC_CH3IE:     equ    6                                         ; Channel 3 Interrupt Enable
TPM1C3SC_CH3F:      equ    7                                         ; Channel 3 Flag
; bit position masks
mTPM1C3SC_ELS3A:    equ    %00000100
mTPM1C3SC_ELS3B:    equ    %00001000
mTPM1C3SC_MS3A:     equ    %00010000
mTPM1C3SC_MS3B:     equ    %00100000
mTPM1C3SC_CH3IE:    equ    %01000000
mTPM1C3SC_CH3F:     equ    %10000000


;*** TPM1C3V - TPM 1 Timer Channel 3 Value Register; 0x0000002F ***
TPM1C3V:            equ    $0000002F                                ;*** TPM1C3V - TPM 1 Timer Channel 3 Value Register; 0x0000002F ***


;*** TPM1C3VH - TPM 1 Timer Channel 3 Value Register High; 0x0000002F ***
TPM1C3VH:           equ    $0000002F                                ;*** TPM1C3VH - TPM 1 Timer Channel 3 Value Register High; 0x0000002F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C3VH_BIT8:      equ    0                                         ; Timer Channel 3 Value Bit 8
TPM1C3VH_BIT9:      equ    1                                         ; Timer Channel 3 Value Bit 9
TPM1C3VH_BIT10:     equ    2                                         ; Timer Channel 3 Value Bit 10
TPM1C3VH_BIT11:     equ    3                                         ; Timer Channel 3 Value Bit 11
TPM1C3VH_BIT12:     equ    4                                         ; Timer Channel 3 Value Bit 12
TPM1C3VH_BIT13:     equ    5                                         ; Timer Channel 3 Value Bit 13
TPM1C3VH_BIT14:     equ    6                                         ; Timer Channel 3 Value Bit 14
TPM1C3VH_BIT15:     equ    7                                         ; Timer Channel 3 Value Bit 15
; bit position masks
mTPM1C3VH_BIT8:     equ    %00000001
mTPM1C3VH_BIT9:     equ    %00000010
mTPM1C3VH_BIT10:    equ    %00000100
mTPM1C3VH_BIT11:    equ    %00001000
mTPM1C3VH_BIT12:    equ    %00010000
mTPM1C3VH_BIT13:    equ    %00100000
mTPM1C3VH_BIT14:    equ    %01000000
mTPM1C3VH_BIT15:    equ    %10000000


;*** TPM1C3VL - TPM 1 Timer Channel 3 Value Register Low; 0x00000030 ***
TPM1C3VL:           equ    $00000030                                ;*** TPM1C3VL - TPM 1 Timer Channel 3 Value Register Low; 0x00000030 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C3VL_BIT0:      equ    0                                         ; Timer Channel 3 Value Bit 0
TPM1C3VL_BIT1:      equ    1                                         ; Timer Channel 3 Value Bit 1
TPM1C3VL_BIT2:      equ    2                                         ; Timer Channel 3 Value Bit 2
TPM1C3VL_BIT3:      equ    3                                         ; Timer Channel 3 Value Bit 3
TPM1C3VL_BIT4:      equ    4                                         ; Timer Channel 3 Value Bit 4
TPM1C3VL_BIT5:      equ    5                                         ; Timer Channel 3 Value Bit 5
TPM1C3VL_BIT6:      equ    6                                         ; Timer Channel 3 Value Bit 6
TPM1C3VL_BIT7:      equ    7                                         ; Timer Channel 3 Value Bit 7
; bit position masks
mTPM1C3VL_BIT0:     equ    %00000001
mTPM1C3VL_BIT1:     equ    %00000010
mTPM1C3VL_BIT2:     equ    %00000100
mTPM1C3VL_BIT3:     equ    %00001000
mTPM1C3VL_BIT4:     equ    %00010000
mTPM1C3VL_BIT5:     equ    %00100000
mTPM1C3VL_BIT6:     equ    %01000000
mTPM1C3VL_BIT7:     equ    %10000000


;*** TPM1C4SC - TPM 1 Timer Channel 4 Status and Control Register; 0x00000031 ***
TPM1C4SC:           equ    $00000031                                ;*** TPM1C4SC - TPM 1 Timer Channel 4 Status and Control Register; 0x00000031 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C4SC_ELS4A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C4SC_ELS4B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C4SC_MS4A:      equ    4                                         ; Mode Select A for TPM Channel 4
TPM1C4SC_MS4B:      equ    5                                         ; Mode Select B for TPM Channel 4
TPM1C4SC_CH4IE:     equ    6                                         ; Channel 4 Interrupt Enable
TPM1C4SC_CH4F:      equ    7                                         ; Channel 4 Flag
; bit position masks
mTPM1C4SC_ELS4A:    equ    %00000100
mTPM1C4SC_ELS4B:    equ    %00001000
mTPM1C4SC_MS4A:     equ    %00010000
mTPM1C4SC_MS4B:     equ    %00100000
mTPM1C4SC_CH4IE:    equ    %01000000
mTPM1C4SC_CH4F:     equ    %10000000


;*** TPM1C4V - TPM 1 Timer Channel 4 Value Register; 0x00000032 ***
TPM1C4V:            equ    $00000032                                ;*** TPM1C4V - TPM 1 Timer Channel 4 Value Register; 0x00000032 ***


;*** TPM1C4VH - TPM 1 Timer Channel 4 Value Register High; 0x00000032 ***
TPM1C4VH:           equ    $00000032                                ;*** TPM1C4VH - TPM 1 Timer Channel 4 Value Register High; 0x00000032 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C4VH_BIT8:      equ    0                                         ; Timer Channel 4 Value Bit 8
TPM1C4VH_BIT9:      equ    1                                         ; Timer Channel 4 Value Bit 9
TPM1C4VH_BIT10:     equ    2                                         ; Timer Channel 4 Value Bit 10
TPM1C4VH_BIT11:     equ    3                                         ; Timer Channel 4 Value Bit 11
TPM1C4VH_BIT12:     equ    4                                         ; Timer Channel 4 Value Bit 12
TPM1C4VH_BIT13:     equ    5                                         ; Timer Channel 4 Value Bit 13
TPM1C4VH_BIT14:     equ    6                                         ; Timer Channel 4 Value Bit 14
TPM1C4VH_BIT15:     equ    7                                         ; Timer Channel 4 Value Bit 15
; bit position masks
mTPM1C4VH_BIT8:     equ    %00000001
mTPM1C4VH_BIT9:     equ    %00000010
mTPM1C4VH_BIT10:    equ    %00000100
mTPM1C4VH_BIT11:    equ    %00001000
mTPM1C4VH_BIT12:    equ    %00010000
mTPM1C4VH_BIT13:    equ    %00100000
mTPM1C4VH_BIT14:    equ    %01000000
mTPM1C4VH_BIT15:    equ    %10000000


;*** TPM1C4VL - TPM 1 Timer Channel 4 Value Register Low; 0x00000033 ***
TPM1C4VL:           equ    $00000033                                ;*** TPM1C4VL - TPM 1 Timer Channel 4 Value Register Low; 0x00000033 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C4VL_BIT0:      equ    0                                         ; Timer Channel 4 Value Bit 0
TPM1C4VL_BIT1:      equ    1                                         ; Timer Channel 4 Value Bit 1
TPM1C4VL_BIT2:      equ    2                                         ; Timer Channel 4 Value Bit 2
TPM1C4VL_BIT3:      equ    3                                         ; Timer Channel 4 Value Bit 3
TPM1C4VL_BIT4:      equ    4                                         ; Timer Channel 4 Value Bit 4
TPM1C4VL_BIT5:      equ    5                                         ; Timer Channel 4 Value Bit 5
TPM1C4VL_BIT6:      equ    6                                         ; Timer Channel 4 Value Bit 6
TPM1C4VL_BIT7:      equ    7                                         ; Timer Channel 4 Value Bit 7
; bit position masks
mTPM1C4VL_BIT0:     equ    %00000001
mTPM1C4VL_BIT1:     equ    %00000010
mTPM1C4VL_BIT2:     equ    %00000100
mTPM1C4VL_BIT3:     equ    %00001000
mTPM1C4VL_BIT4:     equ    %00010000
mTPM1C4VL_BIT5:     equ    %00100000
mTPM1C4VL_BIT6:     equ    %01000000
mTPM1C4VL_BIT7:     equ    %10000000


;*** TPM1C5SC - TPM 1 Timer Channel 5 Status and Control Register; 0x00000034 ***
TPM1C5SC:           equ    $00000034                                ;*** TPM1C5SC - TPM 1 Timer Channel 5 Status and Control Register; 0x00000034 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C5SC_ELS5A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C5SC_ELS5B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C5SC_MS5A:      equ    4                                         ; Mode Select A for TPM Channel 5
TPM1C5SC_MS5B:      equ    5                                         ; Mode Select B for TPM Channel 5
TPM1C5SC_CH5IE:     equ    6                                         ; Channel 5 Interrupt Enable
TPM1C5SC_CH5F:      equ    7                                         ; Channel 5 Flag
; bit position masks
mTPM1C5SC_ELS5A:    equ    %00000100
mTPM1C5SC_ELS5B:    equ    %00001000
mTPM1C5SC_MS5A:     equ    %00010000
mTPM1C5SC_MS5B:     equ    %00100000
mTPM1C5SC_CH5IE:    equ    %01000000
mTPM1C5SC_CH5F:     equ    %10000000


;*** TPM1C5V - TPM 1 Timer Channel 5 Value Register; 0x00000035 ***
TPM1C5V:            equ    $00000035                                ;*** TPM1C5V - TPM 1 Timer Channel 5 Value Register; 0x00000035 ***


;*** TPM1C5VH - TPM 1 Timer Channel 5 Value Register High; 0x00000035 ***
TPM1C5VH:           equ    $00000035                                ;*** TPM1C5VH - TPM 1 Timer Channel 5 Value Register High; 0x00000035 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C5VH_BIT8:      equ    0                                         ; Timer Channel 5 Value Bit 8
TPM1C5VH_BIT9:      equ    1                                         ; Timer Channel 5 Value Bit 9
TPM1C5VH_BIT10:     equ    2                                         ; Timer Channel 5 Value Bit 10
TPM1C5VH_BIT11:     equ    3                                         ; Timer Channel 5 Value Bit 11
TPM1C5VH_BIT12:     equ    4                                         ; Timer Channel 5 Value Bit 12
TPM1C5VH_BIT13:     equ    5                                         ; Timer Channel 5 Value Bit 13
TPM1C5VH_BIT14:     equ    6                                         ; Timer Channel 5 Value Bit 14
TPM1C5VH_BIT15:     equ    7                                         ; Timer Channel 5 Value Bit 15
; bit position masks
mTPM1C5VH_BIT8:     equ    %00000001
mTPM1C5VH_BIT9:     equ    %00000010
mTPM1C5VH_BIT10:    equ    %00000100
mTPM1C5VH_BIT11:    equ    %00001000
mTPM1C5VH_BIT12:    equ    %00010000
mTPM1C5VH_BIT13:    equ    %00100000
mTPM1C5VH_BIT14:    equ    %01000000
mTPM1C5VH_BIT15:    equ    %10000000


;*** TPM1C5VL - TPM 1 Timer Channel 5 Value Register Low; 0x00000036 ***
TPM1C5VL:           equ    $00000036                                ;*** TPM1C5VL - TPM 1 Timer Channel 5 Value Register Low; 0x00000036 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C5VL_BIT0:      equ    0                                         ; Timer Channel 5 Value Bit 0
TPM1C5VL_BIT1:      equ    1                                         ; Timer Channel 5 Value Bit 1
TPM1C5VL_BIT2:      equ    2                                         ; Timer Channel 5 Value Bit 2
TPM1C5VL_BIT3:      equ    3                                         ; Timer Channel 5 Value Bit 3
TPM1C5VL_BIT4:      equ    4                                         ; Timer Channel 5 Value Bit 4
TPM1C5VL_BIT5:      equ    5                                         ; Timer Channel 5 Value Bit 5
TPM1C5VL_BIT6:      equ    6                                         ; Timer Channel 5 Value Bit 6
TPM1C5VL_BIT7:      equ    7                                         ; Timer Channel 5 Value Bit 7
; bit position masks
mTPM1C5VL_BIT0:     equ    %00000001
mTPM1C5VL_BIT1:     equ    %00000010
mTPM1C5VL_BIT2:     equ    %00000100
mTPM1C5VL_BIT3:     equ    %00001000
mTPM1C5VL_BIT4:     equ    %00010000
mTPM1C5VL_BIT5:     equ    %00100000
mTPM1C5VL_BIT6:     equ    %01000000
mTPM1C5VL_BIT7:     equ    %10000000


;*** SCI1BD - SCI1 Baud Rate Register; 0x00000038 ***
SCI1BD:             equ    $00000038                                ;*** SCI1BD - SCI1 Baud Rate Register; 0x00000038 ***


;*** SCI1BDH - SCI1 Baud Rate Register High; 0x00000038 ***
SCI1BDH:            equ    $00000038                                ;*** SCI1BDH - SCI1 Baud Rate Register High; 0x00000038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8:       equ    0                                         ; Baud Rate Modulo Divisor Bit 8
SCI1BDH_SBR9:       equ    1                                         ; Baud Rate Modulo Divisor Bit 9
SCI1BDH_SBR10:      equ    2                                         ; Baud Rate Modulo Divisor Bit 10
SCI1BDH_SBR11:      equ    3                                         ; Baud Rate Modulo Divisor Bit 11
SCI1BDH_SBR12:      equ    4                                         ; Baud Rate Modulo Divisor Bit 12
SCI1BDH_RXEDGIE:    equ    6                                         ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI1BDH_LBKDIE:     equ    7                                         ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI1BDH_SBR8:      equ    %00000001
mSCI1BDH_SBR9:      equ    %00000010
mSCI1BDH_SBR10:     equ    %00000100
mSCI1BDH_SBR11:     equ    %00001000
mSCI1BDH_SBR12:     equ    %00010000
mSCI1BDH_RXEDGIE:   equ    %01000000
mSCI1BDH_LBKDIE:    equ    %10000000


;*** SCI1BDL - SCI1 Baud Rate Register Low; 0x00000039 ***
SCI1BDL:            equ    $00000039                                ;*** SCI1BDL - SCI1 Baud Rate Register Low; 0x00000039 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDL_SBR0:       equ    0                                         ; Baud Rate Modulo Divisor Bit 0
SCI1BDL_SBR1:       equ    1                                         ; Baud Rate Modulo Divisor Bit 1
SCI1BDL_SBR2:       equ    2                                         ; Baud Rate Modulo Divisor Bit 2
SCI1BDL_SBR3:       equ    3                                         ; Baud Rate Modulo Divisor Bit 3
SCI1BDL_SBR4:       equ    4                                         ; Baud Rate Modulo Divisor Bit 4
SCI1BDL_SBR5:       equ    5                                         ; Baud Rate Modulo Divisor Bit 5
SCI1BDL_SBR6:       equ    6                                         ; Baud Rate Modulo Divisor Bit 6
SCI1BDL_SBR7:       equ    7                                         ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI1BDL_SBR0:      equ    %00000001
mSCI1BDL_SBR1:      equ    %00000010
mSCI1BDL_SBR2:      equ    %00000100
mSCI1BDL_SBR3:      equ    %00001000
mSCI1BDL_SBR4:      equ    %00010000
mSCI1BDL_SBR5:      equ    %00100000
mSCI1BDL_SBR6:      equ    %01000000
mSCI1BDL_SBR7:      equ    %10000000


;*** SCI1C1 - SCI1 Control Register 1; 0x0000003A ***
SCI1C1:             equ    $0000003A                                ;*** SCI1C1 - SCI1 Control Register 1; 0x0000003A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C1_PT:          equ    0                                         ; Parity Type
SCI1C1_PE:          equ    1                                         ; Parity Enable
SCI1C1_ILT:         equ    2                                         ; Idle Line Type Select
SCI1C1_WAKE:        equ    3                                         ; Receiver Wakeup Method Select
SCI1C1_M:           equ    4                                         ; 9-Bit or 8-Bit Mode Select
SCI1C1_RSRC:        equ    5                                         ; Receiver Source Select
SCI1C1_SCISWAI:     equ    6                                         ; SCI Stops in Wait Mode
SCI1C1_LOOPS:       equ    7                                         ; Loop Mode Select
; bit position masks
mSCI1C1_PT:         equ    %00000001
mSCI1C1_PE:         equ    %00000010
mSCI1C1_ILT:        equ    %00000100
mSCI1C1_WAKE:       equ    %00001000
mSCI1C1_M:          equ    %00010000
mSCI1C1_RSRC:       equ    %00100000
mSCI1C1_SCISWAI:    equ    %01000000
mSCI1C1_LOOPS:      equ    %10000000


;*** SCI1C2 - SCI1 Control Register 2; 0x0000003B ***
SCI1C2:             equ    $0000003B                                ;*** SCI1C2 - SCI1 Control Register 2; 0x0000003B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C2_SBK:         equ    0                                         ; Send Break
SCI1C2_RWU:         equ    1                                         ; Receiver Wakeup Control
SCI1C2_RE:          equ    2                                         ; Receiver Enable
SCI1C2_TE:          equ    3                                         ; Transmitter Enable
SCI1C2_ILIE:        equ    4                                         ; Idle Line Interrupt Enable (for IDLE)
SCI1C2_RIE:         equ    5                                         ; Receiver Interrupt Enable (for RDRF)
SCI1C2_TCIE:        equ    6                                         ; Transmission Complete Interrupt Enable (for TC)
SCI1C2_TIE:         equ    7                                         ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI1C2_SBK:        equ    %00000001
mSCI1C2_RWU:        equ    %00000010
mSCI1C2_RE:         equ    %00000100
mSCI1C2_TE:         equ    %00001000
mSCI1C2_ILIE:       equ    %00010000
mSCI1C2_RIE:        equ    %00100000
mSCI1C2_TCIE:       equ    %01000000
mSCI1C2_TIE:        equ    %10000000


;*** SCI1S1 - SCI1 Status Register 1; 0x0000003C ***
SCI1S1:             equ    $0000003C                                ;*** SCI1S1 - SCI1 Status Register 1; 0x0000003C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S1_PF:          equ    0                                         ; Parity Error Flag
SCI1S1_FE:          equ    1                                         ; Framing Error Flag
SCI1S1_NF:          equ    2                                         ; Noise Flag
SCI1S1_OR:          equ    3                                         ; Receiver Overrun Flag
SCI1S1_IDLE:        equ    4                                         ; Idle Line Flag
SCI1S1_RDRF:        equ    5                                         ; Receive Data Register Full Flag
SCI1S1_TC:          equ    6                                         ; Transmission Complete Flag
SCI1S1_TDRE:        equ    7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI1S1_PF:         equ    %00000001
mSCI1S1_FE:         equ    %00000010
mSCI1S1_NF:         equ    %00000100
mSCI1S1_OR:         equ    %00001000
mSCI1S1_IDLE:       equ    %00010000
mSCI1S1_RDRF:       equ    %00100000
mSCI1S1_TC:         equ    %01000000
mSCI1S1_TDRE:       equ    %10000000


;*** SCI1S2 - SCI1 Status Register 2; 0x0000003D ***
SCI1S2:             equ    $0000003D                                ;*** SCI1S2 - SCI1 Status Register 2; 0x0000003D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S2_RAF:         equ    0                                         ; Receiver Active Flag
SCI1S2_LBKDE:       equ    1                                         ; LIN Break Detection Enable
SCI1S2_BRK13:       equ    2                                         ; Break Character Generation Length
SCI1S2_RWUID:       equ    3                                         ; ReceiveWake Up Idle Detect
SCI1S2_RXINV:       equ    4                                         ; Receive Data Inversion
SCI1S2_RXEDGIF:     equ    6                                         ; RxD Pin Active Edge Interrupt Flag
SCI1S2_LBKDIF:      equ    7                                         ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI1S2_RAF:        equ    %00000001
mSCI1S2_LBKDE:      equ    %00000010
mSCI1S2_BRK13:      equ    %00000100
mSCI1S2_RWUID:      equ    %00001000
mSCI1S2_RXINV:      equ    %00010000
mSCI1S2_RXEDGIF:    equ    %01000000
mSCI1S2_LBKDIF:     equ    %10000000


;*** SCI1C3 - SCI1 Control Register 3; 0x0000003E ***
SCI1C3:             equ    $0000003E                                ;*** SCI1C3 - SCI1 Control Register 3; 0x0000003E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C3_PEIE:        equ    0                                         ; Parity Error Interrupt Enable
SCI1C3_FEIE:        equ    1                                         ; Framing Error Interrupt Enable
SCI1C3_NEIE:        equ    2                                         ; Noise Error Interrupt Enable
SCI1C3_ORIE:        equ    3                                         ; Overrun Interrupt Enable
SCI1C3_TXINV:       equ    4                                         ; Transmit Data Inversion
SCI1C3_TXDIR:       equ    5                                         ; TxD Pin Direction in Single-Wire Mode
SCI1C3_T8:          equ    6                                         ; Ninth Data Bit for Transmitter
SCI1C3_R8:          equ    7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI1C3_PEIE:       equ    %00000001
mSCI1C3_FEIE:       equ    %00000010
mSCI1C3_NEIE:       equ    %00000100
mSCI1C3_ORIE:       equ    %00001000
mSCI1C3_TXINV:      equ    %00010000
mSCI1C3_TXDIR:      equ    %00100000
mSCI1C3_T8:         equ    %01000000
mSCI1C3_R8:         equ    %10000000


;*** SCI1D - SCI1 Data Register; 0x0000003F ***
SCI1D:              equ    $0000003F                                ;*** SCI1D - SCI1 Data Register; 0x0000003F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1D_R0_T0:        equ    0                                         ; Receive/Transmit Data Bit 0
SCI1D_R1_T1:        equ    1                                         ; Receive/Transmit Data Bit 1
SCI1D_R2_T2:        equ    2                                         ; Receive/Transmit Data Bit 2
SCI1D_R3_T3:        equ    3                                         ; Receive/Transmit Data Bit 3
SCI1D_R4_T4:        equ    4                                         ; Receive/Transmit Data Bit 4
SCI1D_R5_T5:        equ    5                                         ; Receive/Transmit Data Bit 5
SCI1D_R6_T6:        equ    6                                         ; Receive/Transmit Data Bit 6
SCI1D_R7_T7:        equ    7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI1D_R0_T0:       equ    %00000001
mSCI1D_R1_T1:       equ    %00000010
mSCI1D_R2_T2:       equ    %00000100
mSCI1D_R3_T3:       equ    %00001000
mSCI1D_R4_T4:       equ    %00010000
mSCI1D_R5_T5:       equ    %00100000
mSCI1D_R6_T6:       equ    %01000000
mSCI1D_R7_T7:       equ    %10000000


;*** SCI2BD - SCI2 Baud Rate Register; 0x00000040 ***
SCI2BD:             equ    $00000040                                ;*** SCI2BD - SCI2 Baud Rate Register; 0x00000040 ***


;*** SCI2BDH - SCI2 Baud Rate Register High; 0x00000040 ***
SCI2BDH:            equ    $00000040                                ;*** SCI2BDH - SCI2 Baud Rate Register High; 0x00000040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDH_SBR8:       equ    0                                         ; Baud Rate Modulo Divisor Bit 8
SCI2BDH_SBR9:       equ    1                                         ; Baud Rate Modulo Divisor Bit 9
SCI2BDH_SBR10:      equ    2                                         ; Baud Rate Modulo Divisor Bit 10
SCI2BDH_SBR11:      equ    3                                         ; Baud Rate Modulo Divisor Bit 11
SCI2BDH_SBR12:      equ    4                                         ; Baud Rate Modulo Divisor Bit 12
SCI2BDH_RXEDGIE:    equ    6                                         ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI2BDH_LBKDIE:     equ    7                                         ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI2BDH_SBR8:      equ    %00000001
mSCI2BDH_SBR9:      equ    %00000010
mSCI2BDH_SBR10:     equ    %00000100
mSCI2BDH_SBR11:     equ    %00001000
mSCI2BDH_SBR12:     equ    %00010000
mSCI2BDH_RXEDGIE:   equ    %01000000
mSCI2BDH_LBKDIE:    equ    %10000000


;*** SCI2BDL - SCI2 Baud Rate Register Low; 0x00000041 ***
SCI2BDL:            equ    $00000041                                ;*** SCI2BDL - SCI2 Baud Rate Register Low; 0x00000041 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDL_SBR0:       equ    0                                         ; Baud Rate Modulo Divisor Bit 0
SCI2BDL_SBR1:       equ    1                                         ; Baud Rate Modulo Divisor Bit 1
SCI2BDL_SBR2:       equ    2                                         ; Baud Rate Modulo Divisor Bit 2
SCI2BDL_SBR3:       equ    3                                         ; Baud Rate Modulo Divisor Bit 3
SCI2BDL_SBR4:       equ    4                                         ; Baud Rate Modulo Divisor Bit 4
SCI2BDL_SBR5:       equ    5                                         ; Baud Rate Modulo Divisor Bit 5
SCI2BDL_SBR6:       equ    6                                         ; Baud Rate Modulo Divisor Bit 6
SCI2BDL_SBR7:       equ    7                                         ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI2BDL_SBR0:      equ    %00000001
mSCI2BDL_SBR1:      equ    %00000010
mSCI2BDL_SBR2:      equ    %00000100
mSCI2BDL_SBR3:      equ    %00001000
mSCI2BDL_SBR4:      equ    %00010000
mSCI2BDL_SBR5:      equ    %00100000
mSCI2BDL_SBR6:      equ    %01000000
mSCI2BDL_SBR7:      equ    %10000000


;*** SCI2C1 - SCI1 Control Register 1; 0x00000042 ***
SCI2C1:             equ    $00000042                                ;*** SCI2C1 - SCI1 Control Register 1; 0x00000042 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C1_PT:          equ    0                                         ; Parity Type
SCI2C1_PE:          equ    1                                         ; Parity Enable
SCI2C1_ILT:         equ    2                                         ; Idle Line Type Select
SCI2C1_WAKE:        equ    3                                         ; Receiver Wakeup Method Select
SCI2C1_M:           equ    4                                         ; 9-Bit or 8-Bit Mode Select
SCI2C1_RSRC:        equ    5                                         ; Receiver Source Select
SCI2C1_SCISWAI:     equ    6                                         ; SCI Stops in Wait Mode
SCI2C1_LOOPS:       equ    7                                         ; Loop Mode Select
; bit position masks
mSCI2C1_PT:         equ    %00000001
mSCI2C1_PE:         equ    %00000010
mSCI2C1_ILT:        equ    %00000100
mSCI2C1_WAKE:       equ    %00001000
mSCI2C1_M:          equ    %00010000
mSCI2C1_RSRC:       equ    %00100000
mSCI2C1_SCISWAI:    equ    %01000000
mSCI2C1_LOOPS:      equ    %10000000


;*** SCI2C2 - SCI2 Control Register 2; 0x00000043 ***
SCI2C2:             equ    $00000043                                ;*** SCI2C2 - SCI2 Control Register 2; 0x00000043 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C2_SBK:         equ    0                                         ; Send Break
SCI2C2_RWU:         equ    1                                         ; Receiver Wakeup Control
SCI2C2_RE:          equ    2                                         ; Receiver Enable
SCI2C2_TE:          equ    3                                         ; Transmitter Enable
SCI2C2_ILIE:        equ    4                                         ; Idle Line Interrupt Enable (for IDLE)
SCI2C2_RIE:         equ    5                                         ; Receiver Interrupt Enable (for RDRF)
SCI2C2_TCIE:        equ    6                                         ; Transmission Complete Interrupt Enable (for TC)
SCI2C2_TIE:         equ    7                                         ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI2C2_SBK:        equ    %00000001
mSCI2C2_RWU:        equ    %00000010
mSCI2C2_RE:         equ    %00000100
mSCI2C2_TE:         equ    %00001000
mSCI2C2_ILIE:       equ    %00010000
mSCI2C2_RIE:        equ    %00100000
mSCI2C2_TCIE:       equ    %01000000
mSCI2C2_TIE:        equ    %10000000


;*** SCI2S1 - SCI2 Status Register 1; 0x00000044 ***
SCI2S1:             equ    $00000044                                ;*** SCI2S1 - SCI2 Status Register 1; 0x00000044 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S1_PF:          equ    0                                         ; Parity Error Flag
SCI2S1_FE:          equ    1                                         ; Framing Error Flag
SCI2S1_NF:          equ    2                                         ; Noise Flag
SCI2S1_OR:          equ    3                                         ; Receiver Overrun Flag
SCI2S1_IDLE:        equ    4                                         ; Idle Line Flag
SCI2S1_RDRF:        equ    5                                         ; Receive Data Register Full Flag
SCI2S1_TC:          equ    6                                         ; Transmission Complete Flag
SCI2S1_TDRE:        equ    7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI2S1_PF:         equ    %00000001
mSCI2S1_FE:         equ    %00000010
mSCI2S1_NF:         equ    %00000100
mSCI2S1_OR:         equ    %00001000
mSCI2S1_IDLE:       equ    %00010000
mSCI2S1_RDRF:       equ    %00100000
mSCI2S1_TC:         equ    %01000000
mSCI2S1_TDRE:       equ    %10000000


;*** SCI2S2 - SCI2 Status Register 2; 0x00000045 ***
SCI2S2:             equ    $00000045                                ;*** SCI2S2 - SCI2 Status Register 2; 0x00000045 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S2_RAF:         equ    0                                         ; Receiver Active Flag
SCI2S2_LBKDE:       equ    1                                         ; LIN Break Detection Enable
SCI2S2_BRK13:       equ    2                                         ; Break Character Generation Length
SCI2S2_RWUID:       equ    3                                         ; ReceiveWake Up Idle Detect
SCI2S2_RXINV:       equ    4                                         ; Receive Data Inversion
SCI2S2_RXEDGIF:     equ    6                                         ; RxD Pin Active Edge Interrupt Flag
SCI2S2_LBKDIF:      equ    7                                         ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI2S2_RAF:        equ    %00000001
mSCI2S2_LBKDE:      equ    %00000010
mSCI2S2_BRK13:      equ    %00000100
mSCI2S2_RWUID:      equ    %00001000
mSCI2S2_RXINV:      equ    %00010000
mSCI2S2_RXEDGIF:    equ    %01000000
mSCI2S2_LBKDIF:     equ    %10000000


;*** SCI2C3 - SCI2 Control Register 3; 0x00000046 ***
SCI2C3:             equ    $00000046                                ;*** SCI2C3 - SCI2 Control Register 3; 0x00000046 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C3_PEIE:        equ    0                                         ; Parity Error Interrupt Enable
SCI2C3_FEIE:        equ    1                                         ; Framing Error Interrupt Enable
SCI2C3_NEIE:        equ    2                                         ; Noise Error Interrupt Enable
SCI2C3_ORIE:        equ    3                                         ; Overrun Interrupt Enable
SCI2C3_TXINV:       equ    4                                         ; Transmit Data Inversion
SCI2C3_TXDIR:       equ    5                                         ; TxD Pin Direction in Single-Wire Mode
SCI2C3_T8:          equ    6                                         ; Ninth Data Bit for Transmitter
SCI2C3_R8:          equ    7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI2C3_PEIE:       equ    %00000001
mSCI2C3_FEIE:       equ    %00000010
mSCI2C3_NEIE:       equ    %00000100
mSCI2C3_ORIE:       equ    %00001000
mSCI2C3_TXINV:      equ    %00010000
mSCI2C3_TXDIR:      equ    %00100000
mSCI2C3_T8:         equ    %01000000
mSCI2C3_R8:         equ    %10000000


;*** SCI2D - SCI2 Data Register; 0x00000047 ***
SCI2D:              equ    $00000047                                ;*** SCI2D - SCI2 Data Register; 0x00000047 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2D_R0_T0:        equ    0                                         ; Receive/Transmit Data Bit 0
SCI2D_R1_T1:        equ    1                                         ; Receive/Transmit Data Bit 1
SCI2D_R2_T2:        equ    2                                         ; Receive/Transmit Data Bit 2
SCI2D_R3_T3:        equ    3                                         ; Receive/Transmit Data Bit 3
SCI2D_R4_T4:        equ    4                                         ; Receive/Transmit Data Bit 4
SCI2D_R5_T5:        equ    5                                         ; Receive/Transmit Data Bit 5
SCI2D_R6_T6:        equ    6                                         ; Receive/Transmit Data Bit 6
SCI2D_R7_T7:        equ    7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI2D_R0_T0:       equ    %00000001
mSCI2D_R1_T1:       equ    %00000010
mSCI2D_R2_T2:       equ    %00000100
mSCI2D_R3_T3:       equ    %00001000
mSCI2D_R4_T4:       equ    %00010000
mSCI2D_R5_T5:       equ    %00100000
mSCI2D_R6_T6:       equ    %01000000
mSCI2D_R7_T7:       equ    %10000000


;*** MCGC1 - ICS Control Register 1; 0x00000048 ***
MCGC1:              equ    $00000048                                ;*** MCGC1 - ICS Control Register 1; 0x00000048 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC1_IREFSTEN:     equ    0                                         ; Internal Reference Stop Enable
MCGC1_IRCLKEN:      equ    1                                         ; Internal Reference Clock Enable
MCGC1_IREFS:        equ    2                                         ; Internal Reference Select
MCGC1_RDIV0:        equ    3                                         ; Reference Divider, bit 0
MCGC1_RDIV1:        equ    4                                         ; Reference Divider, bit 1
MCGC1_RDIV2:        equ    5                                         ; Reference Divider, bit 2
MCGC1_CLKS0:        equ    6                                         ; Clock Source Select, bit 0
MCGC1_CLKS1:        equ    7                                         ; Clock Source Select, bit 1
; bit position masks
mMCGC1_IREFSTEN:    equ    %00000001
mMCGC1_IRCLKEN:     equ    %00000010
mMCGC1_IREFS:       equ    %00000100
mMCGC1_RDIV0:       equ    %00001000
mMCGC1_RDIV1:       equ    %00010000
mMCGC1_RDIV2:       equ    %00100000
mMCGC1_CLKS0:       equ    %01000000
mMCGC1_CLKS1:       equ    %10000000


;*** MCGC2 - ICS Control Register 2; 0x00000049 ***
MCGC2:              equ    $00000049                                ;*** MCGC2 - ICS Control Register 2; 0x00000049 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC2_EREFSTEN:     equ    0                                         ; External Reference Stop Enable
MCGC2_ERCLKEN:      equ    1                                         ; External Reference Enable
MCGC2_EREFS:        equ    2                                         ; External Reference Select
MCGC2_LP:           equ    3                                         ; Low Power Select
MCGC2_HGO:          equ    4                                         ; High Gain Oscillator Select
MCGC2_RANGE:        equ    5                                         ; Frequency Range Select
MCGC2_BDIV0:        equ    6                                         ; Bus Frequency Divider, bit 0
MCGC2_BDIV1:        equ    7                                         ; Bus Frequency Divider, bit 1
; bit position masks
mMCGC2_EREFSTEN:    equ    %00000001
mMCGC2_ERCLKEN:     equ    %00000010
mMCGC2_EREFS:       equ    %00000100
mMCGC2_LP:          equ    %00001000
mMCGC2_HGO:         equ    %00010000
mMCGC2_RANGE:       equ    %00100000
mMCGC2_BDIV0:       equ    %01000000
mMCGC2_BDIV1:       equ    %10000000


;*** MCGTRM - ICS Trim Register; 0x0000004A ***
MCGTRM:             equ    $0000004A                                ;*** MCGTRM - ICS Trim Register; 0x0000004A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGTRM_TRIM0:       equ    0                                         ; ICS Trim Setting, bit 0
MCGTRM_TRIM1:       equ    1                                         ; ICS Trim Setting, bit 1
MCGTRM_TRIM2:       equ    2                                         ; ICS Trim Setting, bit 2
MCGTRM_TRIM3:       equ    3                                         ; ICS Trim Setting, bit 3
MCGTRM_TRIM4:       equ    4                                         ; ICS Trim Setting, bit 4
MCGTRM_TRIM5:       equ    5                                         ; ICS Trim Setting, bit 5
MCGTRM_TRIM6:       equ    6                                         ; ICS Trim Setting, bit 6
MCGTRM_TRIM7:       equ    7                                         ; ICS Trim Setting, bit 7
; bit position masks
mMCGTRM_TRIM0:      equ    %00000001
mMCGTRM_TRIM1:      equ    %00000010
mMCGTRM_TRIM2:      equ    %00000100
mMCGTRM_TRIM3:      equ    %00001000
mMCGTRM_TRIM4:      equ    %00010000
mMCGTRM_TRIM5:      equ    %00100000
mMCGTRM_TRIM6:      equ    %01000000
mMCGTRM_TRIM7:      equ    %10000000


;*** MCGSC - MCG Status and Control Register; 0x0000004B ***
MCGSC:              equ    $0000004B                                ;*** MCGSC - MCG Status and Control Register; 0x0000004B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGSC_FTRIM:        equ    0                                         ; ICS Fine Trim
MCGSC_OSCINIT:      equ    1                                         ; OSC Initialization
MCGSC_CLKST0:       equ    2                                         ; Clock Mode Status, bit 0
MCGSC_CLKST1:       equ    3                                         ; Clock Mode Status, bit 1
MCGSC_LOCK:         equ    6                                         ; Lock Status
MCGSC_LOLS:         equ    7                                         ; Loss of Lock Status
; bit position masks
mMCGSC_FTRIM:       equ    %00000001
mMCGSC_OSCINIT:     equ    %00000010
mMCGSC_CLKST0:      equ    %00000100
mMCGSC_CLKST1:      equ    %00001000
mMCGSC_LOCK:        equ    %01000000
mMCGSC_LOLS:        equ    %10000000


;*** MCGC3 - MCG Control Register 3; 0x0000004C ***
MCGC3:              equ    $0000004C                                ;*** MCGC3 - MCG Control Register 3; 0x0000004C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC3_VDIV0:        equ    0                                         ; ICS Trim Setting, bit 0
MCGC3_VDIV1:        equ    1                                         ; ICS Trim Setting, bit 1
MCGC3_VDIV2:        equ    2                                         ; ICS Trim Setting, bit 2
MCGC3_VDIV3:        equ    3                                         ; ICS Trim Setting, bit 3
MCGC3_CME:          equ    5                                         ; Clock Monitor Enable
MCGC3_PLLS:         equ    6                                         ; ICS Trim Setting
MCGC3_LOLIE:        equ    7                                         ; Loss of Lock Interrupt Enable
; bit position masks
mMCGC3_VDIV0:       equ    %00000001
mMCGC3_VDIV1:       equ    %00000010
mMCGC3_VDIV2:       equ    %00000100
mMCGC3_VDIV3:       equ    %00001000
mMCGC3_CME:         equ    %00100000
mMCGC3_PLLS:        equ    %01000000
mMCGC3_LOLIE:       equ    %10000000


;*** SPIC1 - SPI Control Register 1; 0x00000050 ***
SPIC1:              equ    $00000050                                ;*** SPIC1 - SPI Control Register 1; 0x00000050 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC1_LSBFE:        equ    0                                         ; LSB First (shifter direction)
SPIC1_SSOE:         equ    1                                         ; Slave Select Output Enable
SPIC1_CPHA:         equ    2                                         ; Clock Phase
SPIC1_CPOL:         equ    3                                         ; Clock Polarity
SPIC1_MSTR:         equ    4                                         ; Master/Slave Mode Select
SPIC1_SPTIE:        equ    5                                         ; SPI Transmit Interrupt Enable
SPIC1_SPE:          equ    6                                         ; SPI System Enable
SPIC1_SPIE:         equ    7                                         ; SPI Interrupt Enable
; bit position masks
mSPIC1_LSBFE:       equ    %00000001
mSPIC1_SSOE:        equ    %00000010
mSPIC1_CPHA:        equ    %00000100
mSPIC1_CPOL:        equ    %00001000
mSPIC1_MSTR:        equ    %00010000
mSPIC1_SPTIE:       equ    %00100000
mSPIC1_SPE:         equ    %01000000
mSPIC1_SPIE:        equ    %10000000


;*** SPIC2 - SPI Control Register 2; 0x00000051 ***
SPIC2:              equ    $00000051                                ;*** SPIC2 - SPI Control Register 2; 0x00000051 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC2_SPC0:         equ    0                                         ; SPI Pin Control 0
SPIC2_SPISWAI:      equ    1                                         ; SPI Stop in Wait Mode
SPIC2_BIDIROE:      equ    3                                         ; Bidirectional Mode Output Enable
SPIC2_MODFEN:       equ    4                                         ; Master Mode-Fault Function Enable
; bit position masks
mSPIC2_SPC0:        equ    %00000001
mSPIC2_SPISWAI:     equ    %00000010
mSPIC2_BIDIROE:     equ    %00001000
mSPIC2_MODFEN:      equ    %00010000


;*** SPIBR - SPI Baud Rate Register; 0x00000052 ***
SPIBR:              equ    $00000052                                ;*** SPIBR - SPI Baud Rate Register; 0x00000052 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIBR_SPR0:         equ    0                                         ; SPI Baud Rate Divisor Bit 0
SPIBR_SPR1:         equ    1                                         ; SPI Baud Rate Divisor Bit 1
SPIBR_SPR2:         equ    2                                         ; SPI Baud Rate Divisor Bit 2
SPIBR_SPPR0:        equ    4                                         ; SPI Baud Rate Prescale Divisor Bit 0
SPIBR_SPPR1:        equ    5                                         ; SPI Baud Rate Prescale Divisor Bit 1
SPIBR_SPPR2:        equ    6                                         ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPIBR_SPR0:        equ    %00000001
mSPIBR_SPR1:        equ    %00000010
mSPIBR_SPR2:        equ    %00000100
mSPIBR_SPPR0:       equ    %00010000
mSPIBR_SPPR1:       equ    %00100000
mSPIBR_SPPR2:       equ    %01000000


;*** SPIS - SPI Status Register; 0x00000053 ***
SPIS:               equ    $00000053                                ;*** SPIS - SPI Status Register; 0x00000053 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIS_MODF:          equ    4                                         ; Master Mode Fault Flag
SPIS_SPTEF:         equ    5                                         ; SPI Transmit Buffer Empty Flag
SPIS_SPRF:          equ    7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPIS_MODF:         equ    %00010000
mSPIS_SPTEF:        equ    %00100000
mSPIS_SPRF:         equ    %10000000


;*** SPID - SPI Data Register; 0x00000055 ***
SPID:               equ    $00000055                                ;*** SPID - SPI Data Register; 0x00000055 ***


;*** IICA - IIC Address Register; 0x00000058 ***
IICA:               equ    $00000058                                ;*** IICA - IIC Address Register; 0x00000058 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA_AD1:           equ    1                                         ; IIC Address Bit 1
IICA_AD2:           equ    2                                         ; IIC Address Bit 2
IICA_AD3:           equ    3                                         ; IIC Address Bit 3
IICA_AD4:           equ    4                                         ; IIC Address Bit 4
IICA_AD5:           equ    5                                         ; IIC Address Bit 5
IICA_AD6:           equ    6                                         ; IIC Address Bit 6
IICA_AD7:           equ    7                                         ; IIC Address Bit 7
; bit position masks
mIICA_AD1:          equ    %00000010
mIICA_AD2:          equ    %00000100
mIICA_AD3:          equ    %00001000
mIICA_AD4:          equ    %00010000
mIICA_AD5:          equ    %00100000
mIICA_AD6:          equ    %01000000
mIICA_AD7:          equ    %10000000


;*** IICF - IIC Frequency Divider Register; 0x00000059 ***
IICF:               equ    $00000059                                ;*** IICF - IIC Frequency Divider Register; 0x00000059 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICF_ICR0:          equ    0                                         ; IIC Clock Rate Bit 0
IICF_ICR1:          equ    1                                         ; IIC Clock Rate Bit 1
IICF_ICR2:          equ    2                                         ; IIC Clock Rate Bit 2
IICF_ICR3:          equ    3                                         ; IIC Clock Rate Bit 3
IICF_ICR4:          equ    4                                         ; IIC Clock Rate Bit 4
IICF_ICR5:          equ    5                                         ; IIC Clock Rate Bit 5
IICF_MULT0:         equ    6                                         ; Multiplier Factor Bit 0
IICF_MULT1:         equ    7                                         ; Multiplier Factor Bit 1
; bit position masks
mIICF_ICR0:         equ    %00000001
mIICF_ICR1:         equ    %00000010
mIICF_ICR2:         equ    %00000100
mIICF_ICR3:         equ    %00001000
mIICF_ICR4:         equ    %00010000
mIICF_ICR5:         equ    %00100000
mIICF_MULT0:        equ    %01000000
mIICF_MULT1:        equ    %10000000


;*** IICC1 - IIC Control Register 1; 0x0000005A ***
IICC1:              equ    $0000005A                                ;*** IICC1 - IIC Control Register 1; 0x0000005A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC1_RSTA:         equ    2                                         ; Repeat START Bit
IICC1_TXAK:         equ    3                                         ; Transmit Acknowledge Enable Bit
IICC1_TX:           equ    4                                         ; Transmit Mode Select Bit
IICC1_MST:          equ    5                                         ; Master Mode Select Bit
IICC1_IICIE:        equ    6                                         ; IIC Interrupt Enable Bit
IICC1_IICEN:        equ    7                                         ; IIC Enable Bit
; bit position masks
mIICC1_RSTA:        equ    %00000100
mIICC1_TXAK:        equ    %00001000
mIICC1_TX:          equ    %00010000
mIICC1_MST:         equ    %00100000
mIICC1_IICIE:       equ    %01000000
mIICC1_IICEN:       equ    %10000000


;*** IICS - IIC Status Register; 0x0000005B ***
IICS:               equ    $0000005B                                ;*** IICS - IIC Status Register; 0x0000005B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICS_RXAK:          equ    0                                         ; Receive Acknowledge
IICS_IICIF:         equ    1                                         ; IIC Interrupt Flag
IICS_SRW:           equ    2                                         ; Slave Read/Write
IICS_ARBL:          equ    4                                         ; Arbitration Lost
IICS_BUSY:          equ    5                                         ; Bus Busy bit
IICS_IAAS:          equ    6                                         ; Addressed as a Slave Bit
IICS_TCF:           equ    7                                         ; Transfer Complete Flag
; bit position masks
mIICS_RXAK:         equ    %00000001
mIICS_IICIF:        equ    %00000010
mIICS_SRW:          equ    %00000100
mIICS_ARBL:         equ    %00010000
mIICS_BUSY:         equ    %00100000
mIICS_IAAS:         equ    %01000000
mIICS_TCF:          equ    %10000000


;*** IICD - IIC Data I/O Register; 0x0000005C ***
IICD:               equ    $0000005C                                ;*** IICD - IIC Data I/O Register; 0x0000005C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICD_DATA0:         equ    0                                         ; IIC Data Bit 0
IICD_DATA1:         equ    1                                         ; IIC Data Bit 1
IICD_DATA2:         equ    2                                         ; IIC Data Bit 2
IICD_DATA3:         equ    3                                         ; IIC Data Bit 3
IICD_DATA4:         equ    4                                         ; IIC Data Bit 4
IICD_DATA5:         equ    5                                         ; IIC Data Bit 5
IICD_DATA6:         equ    6                                         ; IIC Data Bit 6
IICD_DATA7:         equ    7                                         ; IIC Data Bit 7
; bit position masks
mIICD_DATA0:        equ    %00000001
mIICD_DATA1:        equ    %00000010
mIICD_DATA2:        equ    %00000100
mIICD_DATA3:        equ    %00001000
mIICD_DATA4:        equ    %00010000
mIICD_DATA5:        equ    %00100000
mIICD_DATA6:        equ    %01000000
mIICD_DATA7:        equ    %10000000


;*** IICC2 - IIC Control Register 2; 0x0000005D ***
IICC2:              equ    $0000005D                                ;*** IICC2 - IIC Control Register 2; 0x0000005D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC2_AD8:          equ    0                                         ; IIC Address Bit 8
IICC2_AD9:          equ    1                                         ; IIC Address Bit 9
IICC2_AD10:         equ    2                                         ; IIC Address Bit 10
IICC2_ADEXT:        equ    6                                         ; Address Extension
IICC2_GCAEN:        equ    7                                         ; General Call Address Enable
; bit position masks
mIICC2_AD8:         equ    %00000001
mIICC2_AD9:         equ    %00000010
mIICC2_AD10:        equ    %00000100
mIICC2_ADEXT:       equ    %01000000
mIICC2_GCAEN:       equ    %10000000


;*** TPM2SC - TPM 2 Status and Control Register; 0x00000060 ***
TPM2SC:             equ    $00000060                                ;*** TPM2SC - TPM 2 Status and Control Register; 0x00000060 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2SC_PS0:         equ    0                                         ; Prescale Divisor Select Bit 0
TPM2SC_PS1:         equ    1                                         ; Prescale Divisor Select Bit 1
TPM2SC_PS2:         equ    2                                         ; Prescale Divisor Select Bit 2
TPM2SC_CLKSA:       equ    3                                         ; Clock Source Select A
TPM2SC_CLKSB:       equ    4                                         ; Clock Source Select B
TPM2SC_CPWMS:       equ    5                                         ; Center-Aligned PWM Select
TPM2SC_TOIE:        equ    6                                         ; Timer Overflow Interrupt Enable
TPM2SC_TOF:         equ    7                                         ; Timer Overflow Flag
; bit position masks
mTPM2SC_PS0:        equ    %00000001
mTPM2SC_PS1:        equ    %00000010
mTPM2SC_PS2:        equ    %00000100
mTPM2SC_CLKSA:      equ    %00001000
mTPM2SC_CLKSB:      equ    %00010000
mTPM2SC_CPWMS:      equ    %00100000
mTPM2SC_TOIE:       equ    %01000000
mTPM2SC_TOF:        equ    %10000000


;*** TPM2CNT - TPM 2 Counter Register; 0x00000061 ***
TPM2CNT:            equ    $00000061                                ;*** TPM2CNT - TPM 2 Counter Register; 0x00000061 ***


;*** TPM2CNTH - TPM 2 Counter Register High; 0x00000061 ***
TPM2CNTH:           equ    $00000061                                ;*** TPM2CNTH - TPM 2 Counter Register High; 0x00000061 ***


;*** TPM2CNTL - TPM 2 Counter Register Low; 0x00000062 ***
TPM2CNTL:           equ    $00000062                                ;*** TPM2CNTL - TPM 2 Counter Register Low; 0x00000062 ***


;*** TPM2MOD - TPM 2 Timer Counter Modulo Register; 0x00000063 ***
TPM2MOD:            equ    $00000063                                ;*** TPM2MOD - TPM 2 Timer Counter Modulo Register; 0x00000063 ***


;*** TPM2MODH - TPM 2 Timer Counter Modulo Register High; 0x00000063 ***
TPM2MODH:           equ    $00000063                                ;*** TPM2MODH - TPM 2 Timer Counter Modulo Register High; 0x00000063 ***


;*** TPM2MODL - TPM 2 Timer Counter Modulo Register Low; 0x00000064 ***
TPM2MODL:           equ    $00000064                                ;*** TPM2MODL - TPM 2 Timer Counter Modulo Register Low; 0x00000064 ***


;*** TPM2C0SC - TPM 2 Timer Channel 0 Status and Control Register; 0x00000065 ***
TPM2C0SC:           equ    $00000065                                ;*** TPM2C0SC - TPM 2 Timer Channel 0 Status and Control Register; 0x00000065 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C0SC_ELS0A:     equ    2                                         ; Edge/Level Select Bit A
TPM2C0SC_ELS0B:     equ    3                                         ; Edge/Level Select Bit B
TPM2C0SC_MS0A:      equ    4                                         ; Mode Select A for TPM Channel 0
TPM2C0SC_MS0B:      equ    5                                         ; Mode Select B for TPM Channel 0
TPM2C0SC_CH0IE:     equ    6                                         ; Channel 0 Interrupt Enable
TPM2C0SC_CH0F:      equ    7                                         ; Channel 0 Flag
; bit position masks
mTPM2C0SC_ELS0A:    equ    %00000100
mTPM2C0SC_ELS0B:    equ    %00001000
mTPM2C0SC_MS0A:     equ    %00010000
mTPM2C0SC_MS0B:     equ    %00100000
mTPM2C0SC_CH0IE:    equ    %01000000
mTPM2C0SC_CH0F:     equ    %10000000


;*** TPM2C0V - TPM 2 Timer Channel 0 Value Register; 0x00000066 ***
TPM2C0V:            equ    $00000066                                ;*** TPM2C0V - TPM 2 Timer Channel 0 Value Register; 0x00000066 ***


;*** TPM2C0VH - TPM 2 Timer Channel 0 Value Register High; 0x00000066 ***
TPM2C0VH:           equ    $00000066                                ;*** TPM2C0VH - TPM 2 Timer Channel 0 Value Register High; 0x00000066 ***


;*** TPM2C0VL - TPM 2 Timer Channel 0 Value Register Low; 0x00000067 ***
TPM2C0VL:           equ    $00000067                                ;*** TPM2C0VL - TPM 2 Timer Channel 0 Value Register Low; 0x00000067 ***


;*** TPM2C1SC - TPM 2 Timer Channel 1 Status and Control Register; 0x00000068 ***
TPM2C1SC:           equ    $00000068                                ;*** TPM2C1SC - TPM 2 Timer Channel 1 Status and Control Register; 0x00000068 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C1SC_ELS1A:     equ    2                                         ; Edge/Level Select Bit A
TPM2C1SC_ELS1B:     equ    3                                         ; Edge/Level Select Bit B
TPM2C1SC_MS1A:      equ    4                                         ; Mode Select A for TPM Channel 1
TPM2C1SC_MS1B:      equ    5                                         ; Mode Select B for TPM Channel 1
TPM2C1SC_CH1IE:     equ    6                                         ; Channel 1 Interrupt Enable
TPM2C1SC_CH1F:      equ    7                                         ; Channel 1 Flag
; bit position masks
mTPM2C1SC_ELS1A:    equ    %00000100
mTPM2C1SC_ELS1B:    equ    %00001000
mTPM2C1SC_MS1A:     equ    %00010000
mTPM2C1SC_MS1B:     equ    %00100000
mTPM2C1SC_CH1IE:    equ    %01000000
mTPM2C1SC_CH1F:     equ    %10000000


;*** TPM2C1V - TPM 2 Timer Channel 1 Value Register; 0x00000069 ***
TPM2C1V:            equ    $00000069                                ;*** TPM2C1V - TPM 2 Timer Channel 1 Value Register; 0x00000069 ***


;*** TPM2C1VH - TPM 2 Timer Channel 1 Value Register High; 0x00000069 ***
TPM2C1VH:           equ    $00000069                                ;*** TPM2C1VH - TPM 2 Timer Channel 1 Value Register High; 0x00000069 ***


;*** TPM2C1VL - TPM 2 Timer Channel 1 Value Register Low; 0x0000006A ***
TPM2C1VL:           equ    $0000006A                                ;*** TPM2C1VL - TPM 2 Timer Channel 1 Value Register Low; 0x0000006A ***


;*** RTCSC - RTC Status and Control Register; 0x0000006C ***
RTCSC:              equ    $0000006C                                ;*** RTCSC - RTC Status and Control Register; 0x0000006C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCSC_RTCPS0:       equ    0                                         ; Real-Time Clock Prescaler Select, bit 0
RTCSC_RTCPS1:       equ    1                                         ; Real-Time Clock Prescaler Select, bit 1
RTCSC_RTCPS2:       equ    2                                         ; Real-Time Clock Prescaler Select, bit 2
RTCSC_RTCPS3:       equ    3                                         ; Real-Time Clock Prescaler Select, bit 3
RTCSC_RTIE:         equ    4                                         ; Real-Time Interrupt Enable
RTCSC_RTCLKS0:      equ    5                                         ; Real-Time Clock Source Select, bit 0
RTCSC_RTCLKS1:      equ    6                                         ; Real-Time Clock Source Select, bit 1
RTCSC_RTIF:         equ    7                                         ; Real-Time Interrupt Flag
; bit position masks
mRTCSC_RTCPS0:      equ    %00000001
mRTCSC_RTCPS1:      equ    %00000010
mRTCSC_RTCPS2:      equ    %00000100
mRTCSC_RTCPS3:      equ    %00001000
mRTCSC_RTIE:        equ    %00010000
mRTCSC_RTCLKS0:     equ    %00100000
mRTCSC_RTCLKS1:     equ    %01000000
mRTCSC_RTIF:        equ    %10000000


;*** RTCCNT - RTC Counter Register; 0x0000006D ***
RTCCNT:             equ    $0000006D                                ;*** RTCCNT - RTC Counter Register; 0x0000006D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCCNT_RTCCNT0:     equ    0                                         ; RTC Count, bit 0
RTCCNT_RTCCNT1:     equ    1                                         ; RTC Count, bit 1
RTCCNT_RTCCNT2:     equ    2                                         ; RTC Count, bit 2
RTCCNT_RTCCNT3:     equ    3                                         ; RTC Count, bit 3
RTCCNT_RTCCNT4:     equ    4                                         ; RTC Count, bit 4
RTCCNT_RTCCNT5:     equ    5                                         ; RTC Count, bit 5
RTCCNT_RTCCNT6:     equ    6                                         ; RTC Count, bit 6
RTCCNT_RTCCNT7:     equ    7                                         ; RTC Count, bit 7
; bit position masks
mRTCCNT_RTCCNT0:    equ    %00000001
mRTCCNT_RTCCNT1:    equ    %00000010
mRTCCNT_RTCCNT2:    equ    %00000100
mRTCCNT_RTCCNT3:    equ    %00001000
mRTCCNT_RTCCNT4:    equ    %00010000
mRTCCNT_RTCCNT5:    equ    %00100000
mRTCCNT_RTCCNT6:    equ    %01000000
mRTCCNT_RTCCNT7:    equ    %10000000


;*** RTCMOD - RTC Modulo Register; 0x0000006E ***
RTCMOD:             equ    $0000006E                                ;*** RTCMOD - RTC Modulo Register; 0x0000006E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCMOD_RTCMOD0:     equ    0                                         ; RTC Modulo, bit 0
RTCMOD_RTCMOD1:     equ    1                                         ; RTC Modulo, bit 1
RTCMOD_RTCMOD2:     equ    2                                         ; RTC Modulo, bit 2
RTCMOD_RTCMOD3:     equ    3                                         ; RTC Modulo, bit 3
RTCMOD_RTCMOD4:     equ    4                                         ; RTC Modulo, bit 4
RTCMOD_RTCMOD5:     equ    5                                         ; RTC Modulo, bit 5
RTCMOD_RTCMOD6:     equ    6                                         ; RTC Modulo, bit 6
RTCMOD_RTCMOD7:     equ    7                                         ; RTC Modulo, bit 7
; bit position masks
mRTCMOD_RTCMOD0:    equ    %00000001
mRTCMOD_RTCMOD1:    equ    %00000010
mRTCMOD_RTCMOD2:    equ    %00000100
mRTCMOD_RTCMOD3:    equ    %00001000
mRTCMOD_RTCMOD4:    equ    %00010000
mRTCMOD_RTCMOD5:    equ    %00100000
mRTCMOD_RTCMOD6:    equ    %01000000
mRTCMOD_RTCMOD7:    equ    %10000000


;*** SRS - System Reset Status; 0x00001800 ***
SRS:                equ    $00001800                                ;*** SRS - System Reset Status; 0x00001800 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD:            equ    1                                         ; Low Voltage Detect
SRS_LOC:            equ    2                                         ; Loss of Clock
SRS_ILAD:           equ    3                                         ; Illegal Address
SRS_ILOP:           equ    4                                         ; Illegal Opcode
SRS_COP:            equ    5                                         ; Computer Operating Properly (COP) Watchdog
SRS_PIN:            equ    6                                         ; External Reset Pin
SRS_POR:            equ    7                                         ; Power-On Reset
; bit position masks
mSRS_LVD:           equ    %00000010
mSRS_LOC:           equ    %00000100
mSRS_ILAD:          equ    %00001000
mSRS_ILOP:          equ    %00010000
mSRS_COP:           equ    %00100000
mSRS_PIN:           equ    %01000000
mSRS_POR:           equ    %10000000


;*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***
SBDFR:              equ    $00001801                                ;*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBDFR_BDFR:         equ    0                                         ; Background Debug Force Reset
; bit position masks
mSBDFR_BDFR:        equ    %00000001


;*** SOPT1 - System Options Register 1; 0x00001802 ***
SOPT1:              equ    $00001802                                ;*** SOPT1 - System Options Register 1; 0x00001802 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_IICPS:        equ    3                                         ; IIC Pin Select
SOPT1_SCI2PS:       equ    4                                         ; SCI2 Pin Select
SOPT1_STOPE:        equ    5                                         ; Stop Mode Enable
SOPT1_COPT0:        equ    6                                         ; COP Watchdog Timeout, bit 0
SOPT1_COPT1:        equ    7                                         ; COP Watchdog Timeout, bit 1
; bit position masks
mSOPT1_IICPS:       equ    %00001000
mSOPT1_SCI2PS:      equ    %00010000
mSOPT1_STOPE:       equ    %00100000
mSOPT1_COPT0:       equ    %01000000
mSOPT1_COPT1:       equ    %10000000


;*** SOPT2 - System Options Register 2; 0x00001803 ***
SOPT2:              equ    $00001803                                ;*** SOPT2 - System Options Register 2; 0x00001803 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_MCSEL0:       equ    0                                         ; MCLK Divide Select, bit 0
SOPT2_MCSEL1:       equ    1                                         ; MCLK Divide Select, bit 1
SOPT2_MCSEL2:       equ    2                                         ; MCLK Divide Select, bit 2
SOPT2_ADHTS:        equ    4                                         ; ADC Hardware Trigger Select
SOPT2_COPW:         equ    6                                         ; COP Window
SOPT2_COPCLKS:      equ    7                                         ; COP Watchdog Clock Select
; bit position masks
mSOPT2_MCSEL0:      equ    %00000001
mSOPT2_MCSEL1:      equ    %00000010
mSOPT2_MCSEL2:      equ    %00000100
mSOPT2_ADHTS:       equ    %00010000
mSOPT2_COPW:        equ    %01000000
mSOPT2_COPCLKS:     equ    %10000000


;*** SDID - System Integration Module Part ID Register; 0x00001806 ***
SDID:               equ    $00001806                                ;*** SDID - System Integration Module Part ID Register; 0x00001806 ***


;*** SDIDH - System Integration Module Part ID Register High; 0x00001806 ***
SDIDH:              equ    $00001806                                ;*** SDIDH - System Integration Module Part ID Register High; 0x00001806 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8:          equ    0                                         ; Part Identification Number 8
SDIDH_ID9:          equ    1                                         ; Part Identification Number 9
SDIDH_ID10:         equ    2                                         ; Part Identification Number 10
SDIDH_ID11:         equ    3                                         ; Part Identification Number 11
SDIDH_REV0:         equ    4                                         ; Revision Number 0
SDIDH_REV1:         equ    5                                         ; Revision Number 1
SDIDH_REV2:         equ    6                                         ; Revision Number 2
SDIDH_REV3:         equ    7                                         ; Revision Number 3
; bit position masks
mSDIDH_ID8:         equ    %00000001
mSDIDH_ID9:         equ    %00000010
mSDIDH_ID10:        equ    %00000100
mSDIDH_ID11:        equ    %00001000
mSDIDH_REV0:        equ    %00010000
mSDIDH_REV1:        equ    %00100000
mSDIDH_REV2:        equ    %01000000
mSDIDH_REV3:        equ    %10000000


;*** SDIDL - System Integration Module Part ID Register Low; 0x00001807 ***
SDIDL:              equ    $00001807                                ;*** SDIDL - System Integration Module Part ID Register Low; 0x00001807 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDL_ID0:          equ    0                                         ; Part Identification Number 0
SDIDL_ID1:          equ    1                                         ; Part Identification Number 1
SDIDL_ID2:          equ    2                                         ; Part Identification Number 2
SDIDL_ID3:          equ    3                                         ; Part Identification Number 3
SDIDL_ID4:          equ    4                                         ; Part Identification Number 4
SDIDL_ID5:          equ    5                                         ; Part Identification Number 5
SDIDL_ID6:          equ    6                                         ; Part Identification Number 6
SDIDL_ID7:          equ    7                                         ; Part Identification Number 7
; bit position masks
mSDIDL_ID0:         equ    %00000001
mSDIDL_ID1:         equ    %00000010
mSDIDL_ID2:         equ    %00000100
mSDIDL_ID3:         equ    %00001000
mSDIDL_ID4:         equ    %00010000
mSDIDL_ID5:         equ    %00100000
mSDIDL_ID6:         equ    %01000000
mSDIDL_ID7:         equ    %10000000


;*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***
SPMSC1:             equ    $00001809                                ;*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE:        equ    0                                         ; Bandgap Buffer Enable
SPMSC1_LVDE:        equ    2                                         ; Low-Voltage Detect Enable
SPMSC1_LVDSE:       equ    3                                         ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE:       equ    4                                         ; Low-Voltage Detect Reset Enable
SPMSC1_LVWIE:       equ    5                                         ; Low-Voltage Warning Interrupt Enable
SPMSC1_LVWACK:      equ    6                                         ; Low-Voltage Warning Acknowledge
SPMSC1_LVWF:        equ    7                                         ; Low-Voltage Warning Flag
; bit position masks
mSPMSC1_BGBE:       equ    %00000001
mSPMSC1_LVDE:       equ    %00000100
mSPMSC1_LVDSE:      equ    %00001000
mSPMSC1_LVDRE:      equ    %00010000
mSPMSC1_LVWIE:      equ    %00100000
mSPMSC1_LVWACK:     equ    %01000000
mSPMSC1_LVWF:       equ    %10000000


;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***
SPMSC2:             equ    $0000180A                                ;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC:        equ    0                                         ; Partial Power Down Control
SPMSC2_PPDACK:      equ    2                                         ; Partial Power Down Acknowlege
SPMSC2_PPDF:        equ    3                                         ; Partial Power Down Flag
SPMSC2_LVWV:        equ    4                                         ; Low-Voltage Warning Voltage Select
SPMSC2_LVDV:        equ    5                                         ; Low-Voltage Detect Voltage Select
; bit position masks
mSPMSC2_PPDC:       equ    %00000001
mSPMSC2_PPDACK:     equ    %00000100
mSPMSC2_PPDF:       equ    %00001000
mSPMSC2_LVWV:       equ    %00010000
mSPMSC2_LVDV:       equ    %00100000


;*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***
DBGCAH:             equ    $00001810                                ;*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAH_Bit8:        equ    0                                         ; Debug Comparator A Bit 8
DBGCAH_Bit9:        equ    1                                         ; Debug Comparator A Bit 9
DBGCAH_Bit10:       equ    2                                         ; Debug Comparator A Bit 10
DBGCAH_Bit11:       equ    3                                         ; Debug Comparator A Bit 11
DBGCAH_Bit12:       equ    4                                         ; Debug Comparator A Bit 12
DBGCAH_Bit13:       equ    5                                         ; Debug Comparator A Bit 13
DBGCAH_Bit14:       equ    6                                         ; Debug Comparator A Bit 14
DBGCAH_Bit15:       equ    7                                         ; Debug Comparator A Bit 15
; bit position masks
mDBGCAH_Bit8:       equ    %00000001
mDBGCAH_Bit9:       equ    %00000010
mDBGCAH_Bit10:      equ    %00000100
mDBGCAH_Bit11:      equ    %00001000
mDBGCAH_Bit12:      equ    %00010000
mDBGCAH_Bit13:      equ    %00100000
mDBGCAH_Bit14:      equ    %01000000
mDBGCAH_Bit15:      equ    %10000000


;*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***
DBGCAL:             equ    $00001811                                ;*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAL_Bit0:        equ    0                                         ; Debug Comparator A Bit 0
DBGCAL_Bit1:        equ    1                                         ; Debug Comparator A Bit 1
DBGCAL_Bit2:        equ    2                                         ; Debug Comparator A Bit 2
DBGCAL_Bit3:        equ    3                                         ; Debug Comparator A Bit 3
DBGCAL_Bit4:        equ    4                                         ; Debug Comparator A Bit 4
DBGCAL_Bit5:        equ    5                                         ; Debug Comparator A Bit 5
DBGCAL_Bit6:        equ    6                                         ; Debug Comparator A Bit 6
DBGCAL_Bit7:        equ    7                                         ; Debug Comparator A Bit 7
; bit position masks
mDBGCAL_Bit0:       equ    %00000001
mDBGCAL_Bit1:       equ    %00000010
mDBGCAL_Bit2:       equ    %00000100
mDBGCAL_Bit3:       equ    %00001000
mDBGCAL_Bit4:       equ    %00010000
mDBGCAL_Bit5:       equ    %00100000
mDBGCAL_Bit6:       equ    %01000000
mDBGCAL_Bit7:       equ    %10000000


;*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***
DBGCBH:             equ    $00001812                                ;*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBH_Bit8:        equ    0                                         ; Debug Comparator B Bit 8
DBGCBH_Bit9:        equ    1                                         ; Debug Comparator B Bit 9
DBGCBH_Bit10:       equ    2                                         ; Debug Comparator B Bit 10
DBGCBH_Bit11:       equ    3                                         ; Debug Comparator B Bit 11
DBGCBH_Bit12:       equ    4                                         ; Debug Comparator B Bit 12
DBGCBH_Bit13:       equ    5                                         ; Debug Comparator B Bit 13
DBGCBH_Bit14:       equ    6                                         ; Debug Comparator B Bit 14
DBGCBH_Bit15:       equ    7                                         ; Debug Comparator B Bit 15
; bit position masks
mDBGCBH_Bit8:       equ    %00000001
mDBGCBH_Bit9:       equ    %00000010
mDBGCBH_Bit10:      equ    %00000100
mDBGCBH_Bit11:      equ    %00001000
mDBGCBH_Bit12:      equ    %00010000
mDBGCBH_Bit13:      equ    %00100000
mDBGCBH_Bit14:      equ    %01000000
mDBGCBH_Bit15:      equ    %10000000


;*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***
DBGCBL:             equ    $00001813                                ;*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBL_Bit0:        equ    0                                         ; Debug Comparator B Bit 0
DBGCBL_Bit1:        equ    1                                         ; Debug Comparator B Bit 1
DBGCBL_Bit2:        equ    2                                         ; Debug Comparator B Bit 2
DBGCBL_Bit3:        equ    3                                         ; Debug Comparator B Bit 3
DBGCBL_Bit4:        equ    4                                         ; Debug Comparator B Bit 4
DBGCBL_Bit5:        equ    5                                         ; Debug Comparator B Bit 5
DBGCBL_Bit6:        equ    6                                         ; Debug Comparator B Bit 6
DBGCBL_Bit7:        equ    7                                         ; Debug Comparator B Bit 7
; bit position masks
mDBGCBL_Bit0:       equ    %00000001
mDBGCBL_Bit1:       equ    %00000010
mDBGCBL_Bit2:       equ    %00000100
mDBGCBL_Bit3:       equ    %00001000
mDBGCBL_Bit4:       equ    %00010000
mDBGCBL_Bit5:       equ    %00100000
mDBGCBL_Bit6:       equ    %01000000
mDBGCBL_Bit7:       equ    %10000000


;*** DBGF - Debug FIFO Register; 0x00001814 ***
DBGF:               equ    $00001814                                ;*** DBGF - Debug FIFO Register; 0x00001814 ***


;*** DBGFH - Debug FIFO High Register; 0x00001814 ***
DBGFH:              equ    $00001814                                ;*** DBGFH - Debug FIFO High Register; 0x00001814 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFH_Bit8:         equ    0                                         ; Debug FIFO Bit 8
DBGFH_Bit9:         equ    1                                         ; Debug FIFO Bit 9
DBGFH_Bit10:        equ    2                                         ; Debug FIFO Bit 10
DBGFH_Bit11:        equ    3                                         ; Debug FIFO Bit 11
DBGFH_Bit12:        equ    4                                         ; Debug FIFO Bit 12
DBGFH_Bit13:        equ    5                                         ; Debug FIFO Bit 13
DBGFH_Bit14:        equ    6                                         ; Debug FIFO Bit 14
DBGFH_Bit15:        equ    7                                         ; Debug FIFO Bit 15
; bit position masks
mDBGFH_Bit8:        equ    %00000001
mDBGFH_Bit9:        equ    %00000010
mDBGFH_Bit10:       equ    %00000100
mDBGFH_Bit11:       equ    %00001000
mDBGFH_Bit12:       equ    %00010000
mDBGFH_Bit13:       equ    %00100000
mDBGFH_Bit14:       equ    %01000000
mDBGFH_Bit15:       equ    %10000000


;*** DBGFL - Debug FIFO Low Register; 0x00001815 ***
DBGFL:              equ    $00001815                                ;*** DBGFL - Debug FIFO Low Register; 0x00001815 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFL_Bit0:         equ    0                                         ; Debug FIFO Bit 0
DBGFL_Bit1:         equ    1                                         ; Debug FIFO Bit 1
DBGFL_Bit2:         equ    2                                         ; Debug FIFO Bit 2
DBGFL_Bit3:         equ    3                                         ; Debug FIFO Bit 3
DBGFL_Bit4:         equ    4                                         ; Debug FIFO Bit 4
DBGFL_Bit5:         equ    5                                         ; Debug FIFO Bit 5
DBGFL_Bit6:         equ    6                                         ; Debug FIFO Bit 6
DBGFL_Bit7:         equ    7                                         ; Debug FIFO Bit 7
; bit position masks
mDBGFL_Bit0:        equ    %00000001
mDBGFL_Bit1:        equ    %00000010
mDBGFL_Bit2:        equ    %00000100
mDBGFL_Bit3:        equ    %00001000
mDBGFL_Bit4:        equ    %00010000
mDBGFL_Bit5:        equ    %00100000
mDBGFL_Bit6:        equ    %01000000
mDBGFL_Bit7:        equ    %10000000


;*** DBGC - Debug Control Register; 0x00001816 ***
DBGC:               equ    $00001816                                ;*** DBGC - Debug Control Register; 0x00001816 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC_RWBEN:         equ    0                                         ; Enable R/W for Comparator B
DBGC_RWB:           equ    1                                         ; R/W Comparison Value for Comparator B
DBGC_RWAEN:         equ    2                                         ; Enable R/W for Comparator A
DBGC_RWA:           equ    3                                         ; R/W Comparison Value for Comparator A
DBGC_BRKEN:         equ    4                                         ;  Break Enable
DBGC_TAG:           equ    5                                         ; Tag/Force Select
DBGC_ARM:           equ    6                                         ; Arm Control
DBGC_DBGEN:         equ    7                                         ; Debug Module Enable
; bit position masks
mDBGC_RWBEN:        equ    %00000001
mDBGC_RWB:          equ    %00000010
mDBGC_RWAEN:        equ    %00000100
mDBGC_RWA:          equ    %00001000
mDBGC_BRKEN:        equ    %00010000
mDBGC_TAG:          equ    %00100000
mDBGC_ARM:          equ    %01000000
mDBGC_DBGEN:        equ    %10000000


;*** DBGT - Debug Trigger Register; 0x00001817 ***
DBGT:               equ    $00001817                                ;*** DBGT - Debug Trigger Register; 0x00001817 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGT_TRG0:          equ    0                                         ; Select Trigger Mode Bit 0
DBGT_TRG1:          equ    1                                         ; Select Trigger Mode Bit 1
DBGT_TRG2:          equ    2                                         ; Select Trigger Mode Bit 2
DBGT_TRG3:          equ    3                                         ; Select Trigger Mode Bit 3
DBGT_BEGIN:         equ    6                                         ; Begin/End Trigger Select
DBGT_TRGSEL:        equ    7                                         ; Trigger Type
; bit position masks
mDBGT_TRG0:         equ    %00000001
mDBGT_TRG1:         equ    %00000010
mDBGT_TRG2:         equ    %00000100
mDBGT_TRG3:         equ    %00001000
mDBGT_BEGIN:        equ    %01000000
mDBGT_TRGSEL:       equ    %10000000


;*** DBGS - Debug Status Register; 0x00001818 ***
DBGS:               equ    $00001818                                ;*** DBGS - Debug Status Register; 0x00001818 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGS_CNT0:          equ    0                                         ; FIFO Valid Count Bit 0
DBGS_CNT1:          equ    1                                         ; FIFO Valid Count Bit 1
DBGS_CNT2:          equ    2                                         ; FIFO Valid Count Bit 2
DBGS_CNT3:          equ    3                                         ; FIFO Valid Count Bit 3
DBGS_ARMF:          equ    5                                         ; Arm Flag
DBGS_BF:            equ    6                                         ; Trigger Match B Flag
DBGS_AF:            equ    7                                         ; Trigger Match A Flag
; bit position masks
mDBGS_CNT0:         equ    %00000001
mDBGS_CNT1:         equ    %00000010
mDBGS_CNT2:         equ    %00000100
mDBGS_CNT3:         equ    %00001000
mDBGS_ARMF:         equ    %00100000
mDBGS_BF:           equ    %01000000
mDBGS_AF:           equ    %10000000


;*** FCDIV - FLASH and EEPROM Clock Divider Register; 0x00001820 ***
FCDIV:              equ    $00001820                                ;*** FCDIV - FLASH and EEPROM Clock Divider Register; 0x00001820 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCDIV_DIV0:         equ    0                                         ; Divisor for FLASH Clock Divider Bit 0
FCDIV_DIV1:         equ    1                                         ; Divisor for FLASH Clock Divider Bit 1
FCDIV_DIV2:         equ    2                                         ; Divisor for FLASH Clock Divider Bit 2
FCDIV_DIV3:         equ    3                                         ; Divisor for FLASH Clock Divider Bit 3
FCDIV_DIV4:         equ    4                                         ; Divisor for FLASH Clock Divider Bit 4
FCDIV_DIV5:         equ    5                                         ; Divisor for FLASH Clock Divider Bit 5
FCDIV_PRDIV8:       equ    6                                         ; Prescale (Divide) FLASH Clock by 8
FCDIV_DIVLD:        equ    7                                         ; Divisor Loaded Status Flag
; bit position masks
mFCDIV_DIV0:        equ    %00000001
mFCDIV_DIV1:        equ    %00000010
mFCDIV_DIV2:        equ    %00000100
mFCDIV_DIV3:        equ    %00001000
mFCDIV_DIV4:        equ    %00010000
mFCDIV_DIV5:        equ    %00100000
mFCDIV_PRDIV8:      equ    %01000000
mFCDIV_DIVLD:       equ    %10000000


;*** FOPT - FLASH and EEPROM Options Register; 0x00001821 ***
FOPT:               equ    $00001821                                ;*** FOPT - FLASH and EEPROM Options Register; 0x00001821 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SEC0:          equ    0                                         ; Security State Code Bit 0
FOPT_SEC1:          equ    1                                         ; Security State Code Bit 1
FOPT_EPGMOD:        equ    5                                         ; EEPROM Sector Mode
FOPT_FNORED:        equ    6                                         ; Vector Redirection Disable
FOPT_KEYEN:         equ    7                                         ; Backdoor Key Mechanism Enable
; bit position masks
mFOPT_SEC0:         equ    %00000001
mFOPT_SEC1:         equ    %00000010
mFOPT_EPGMOD:       equ    %00100000
mFOPT_FNORED:       equ    %01000000
mFOPT_KEYEN:        equ    %10000000


;*** FTSTMOD - FLASH and EEPROM Test Mode Register; 0x00001822 ***
FTSTMOD:            equ    $00001822                                ;*** FTSTMOD - FLASH and EEPROM Test Mode Register; 0x00001822 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTSTMOD_MRDS0:      equ    5                                         ; Margin Read Settings, bit 0
FTSTMOD_MRDS1:      equ    6                                         ; Margin Read Settings, bit 1
; bit position masks
mFTSTMOD_MRDS0:     equ    %00100000
mFTSTMOD_MRDS1:     equ    %01000000


;*** FCNFG - FLASH and EEPROM Configuration Register; 0x00001823 ***
FCNFG:              equ    $00001823                                ;*** FCNFG - FLASH and EEPROM Configuration Register; 0x00001823 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_ECCDIS:       equ    4                                         ; Error Correction Code Disable
FCNFG_KEYACC:       equ    5                                         ; Enable Writing of Access Key
FCNFG_EPGSEL:       equ    6                                         ; EEPROM Page Select
; bit position masks
mFCNFG_ECCDIS:      equ    %00010000
mFCNFG_KEYACC:      equ    %00100000
mFCNFG_EPGSEL:      equ    %01000000


;*** FPROT - FLASH and EEPROM Protection Register; 0x00001824 ***
FPROT:              equ    $00001824                                ;*** FPROT - FLASH and EEPROM Protection Register; 0x00001824 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPS0:         equ    0                                         ; FLASH Protect Select Bits, bit 0
FPROT_FPS1:         equ    1                                         ; FLASH Protect Select Bits, bit 1
FPROT_FPS2:         equ    2                                         ; FLASH Protect Select Bits, bit 2
FPROT_FPS3:         equ    3                                         ; FLASH Protect Select Bits, bit 3
FPROT_FPS4:         equ    4                                         ; FLASH Protect Select Bits, bit 4
FPROT_FPS5:         equ    5                                         ; FLASH Protect Select Bits, bit 5
FPROT_EPS0:         equ    6                                         ; EEPROM Protect Select Bits, bit 0
FPROT_EPS1:         equ    7                                         ; EEPROM Protect Select Bits, bit 1
; bit position masks
mFPROT_FPS0:        equ    %00000001
mFPROT_FPS1:        equ    %00000010
mFPROT_FPS2:        equ    %00000100
mFPROT_FPS3:        equ    %00001000
mFPROT_FPS4:        equ    %00010000
mFPROT_FPS5:        equ    %00100000
mFPROT_EPS0:        equ    %01000000
mFPROT_EPS1:        equ    %10000000


;*** FSTAT - FLASH and EEPROM Status Register; 0x00001825 ***
FSTAT:              equ    $00001825                                ;*** FSTAT - FLASH and EEPROM Status Register; 0x00001825 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSTAT_FBLANK:       equ    2                                         ; FLASH Verified as All Blank (erased) Flag
FSTAT_FACCERR:      equ    4                                         ; Access Error Flag
FSTAT_FPVIOL:       equ    5                                         ; Protection Violation Flag
FSTAT_FCCF:         equ    6                                         ; FLASH Command Complete Flag
FSTAT_FCBEF:        equ    7                                         ; FLASH Command Buffer Empty Flag
; bit position masks
mFSTAT_FBLANK:      equ    %00000100
mFSTAT_FACCERR:     equ    %00010000
mFSTAT_FPVIOL:      equ    %00100000
mFSTAT_FCCF:        equ    %01000000
mFSTAT_FCBEF:       equ    %10000000


;*** FCMD - FLASH and EEPROM Command Register; 0x00001826 ***
FCMD:               equ    $00001826                                ;*** FCMD - FLASH and EEPROM Command Register; 0x00001826 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCMD_FCMD0:         equ    0                                         ; FLASH Command Bit 0
FCMD_FCMD1:         equ    1                                         ; FLASH Command Bit 1
FCMD_FCMD2:         equ    2                                         ; FLASH Command Bit 2
FCMD_FCMD3:         equ    3                                         ; FLASH Command Bit 3
FCMD_FCMD4:         equ    4                                         ; FLASH Command Bit 4
FCMD_FCMD5:         equ    5                                         ; FLASH Command Bit 5
FCMD_FCMD6:         equ    6                                         ; FLASH Command Bit 6
FCMD_FCMD7:         equ    7                                         ; FLASH Command Bit 7
; bit position masks
mFCMD_FCMD0:        equ    %00000001
mFCMD_FCMD1:        equ    %00000010
mFCMD_FCMD2:        equ    %00000100
mFCMD_FCMD3:        equ    %00001000
mFCMD_FCMD4:        equ    %00010000
mFCMD_FCMD5:        equ    %00100000
mFCMD_FCMD6:        equ    %01000000
mFCMD_FCMD7:        equ    %10000000


;*** PTAPE - Pullup Enable for Port A; 0x00001840 ***
PTAPE:              equ    $00001840                                ;*** PTAPE - Pullup Enable for Port A; 0x00001840 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0:       equ    0                                         ; Pullup Enable for Port A Bit 0
PTAPE_PTAPE1:       equ    1                                         ; Pullup Enable for Port A Bit 1
PTAPE_PTAPE2:       equ    2                                         ; Pullup Enable for Port A Bit 2
PTAPE_PTAPE3:       equ    3                                         ; Pullup Enable for Port A Bit 3
PTAPE_PTAPE4:       equ    4                                         ; Pullup Enable for Port A Bit 4
PTAPE_PTAPE5:       equ    5                                         ; Pullup Enable for Port A Bit 5
PTAPE_PTAPE6:       equ    6                                         ; Pullup Enable for Port A Bit 6
PTAPE_PTAPE7:       equ    7                                         ; Pullup Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0:      equ    %00000001
mPTAPE_PTAPE1:      equ    %00000010
mPTAPE_PTAPE2:      equ    %00000100
mPTAPE_PTAPE3:      equ    %00001000
mPTAPE_PTAPE4:      equ    %00010000
mPTAPE_PTAPE5:      equ    %00100000
mPTAPE_PTAPE6:      equ    %01000000
mPTAPE_PTAPE7:      equ    %10000000


;*** PTASE - Slew Rate Control Enable for Port A; 0x00001841 ***
PTASE:              equ    $00001841                                ;*** PTASE - Slew Rate Control Enable for Port A; 0x00001841 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0:       equ    0                                         ; Slew Rate Control Enable for Port A Bit 0
PTASE_PTASE1:       equ    1                                         ; Slew Rate Control Enable for Port A Bit 1
PTASE_PTASE2:       equ    2                                         ; Slew Rate Control Enable for Port A Bit 2
PTASE_PTASE3:       equ    3                                         ; Slew Rate Control Enable for Port A Bit 3
PTASE_PTASE4:       equ    4                                         ; Slew Rate Control Enable for Port A Bit 4
PTASE_PTASE5:       equ    5                                         ; Slew Rate Control Enable for Port A Bit 5
PTASE_PTASE6:       equ    6                                         ; Slew Rate Control Enable for Port A Bit 6
PTASE_PTASE7:       equ    7                                         ; Slew Rate Control Enable for Port A Bit 7
; bit position masks
mPTASE_PTASE0:      equ    %00000001
mPTASE_PTASE1:      equ    %00000010
mPTASE_PTASE2:      equ    %00000100
mPTASE_PTASE3:      equ    %00001000
mPTASE_PTASE4:      equ    %00010000
mPTASE_PTASE5:      equ    %00100000
mPTASE_PTASE6:      equ    %01000000
mPTASE_PTASE7:      equ    %10000000


;*** PTADS - Output Drive Strength Selection for Port A; 0x00001842 ***
PTADS:              equ    $00001842                                ;*** PTADS - Output Drive Strength Selection for Port A; 0x00001842 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0:       equ    0                                         ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS1:       equ    1                                         ; Output Drive Strength Selection for Port A Bit 1
PTADS_PTADS2:       equ    2                                         ; Output Drive Strength Selection for Port A Bit 2
PTADS_PTADS3:       equ    3                                         ; Output Drive Strength Selection for Port A Bit 3
PTADS_PTADS4:       equ    4                                         ; Output Drive Strength Selection for Port A Bit 4
PTADS_PTADS5:       equ    5                                         ; Output Drive Strength Selection for Port A Bit 5
PTADS_PTADS6:       equ    6                                         ; Output Drive Strength Selection for Port A Bit 6
PTADS_PTADS7:       equ    7                                         ; Output Drive Strength Selection for Port A Bit 7
; bit position masks
mPTADS_PTADS0:      equ    %00000001
mPTADS_PTADS1:      equ    %00000010
mPTADS_PTADS2:      equ    %00000100
mPTADS_PTADS3:      equ    %00001000
mPTADS_PTADS4:      equ    %00010000
mPTADS_PTADS5:      equ    %00100000
mPTADS_PTADS6:      equ    %01000000
mPTADS_PTADS7:      equ    %10000000


;*** PTASC - Port A Interrupt Status and Control Register; 0x00001844 ***
PTASC:              equ    $00001844                                ;*** PTASC - Port A Interrupt Status and Control Register; 0x00001844 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASC_PTAMOD:       equ    0                                         ; Port A Detection Mode
PTASC_PTAIE:        equ    1                                         ; Port A Interrupt Enable
PTASC_PTAACK:       equ    2                                         ; Port A Interrupt Acknowledge
PTASC_PTAIF:        equ    3                                         ; Port A Interrupt Flag
; bit position masks
mPTASC_PTAMOD:      equ    %00000001
mPTASC_PTAIE:       equ    %00000010
mPTASC_PTAACK:      equ    %00000100
mPTASC_PTAIF:       equ    %00001000


;*** PTAPS - Port A Interrupt Pin Select Register; 0x00001845 ***
PTAPS:              equ    $00001845                                ;*** PTAPS - Port A Interrupt Pin Select Register; 0x00001845 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPS_PTAPS0:       equ    0                                         ; Port A Interrupt Pin Select Bit 0
PTAPS_PTAPS1:       equ    1                                         ; Port A Interrupt Pin Select Bit 1
PTAPS_PTAPS2:       equ    2                                         ; Port A Interrupt Pin Select Bit 2
PTAPS_PTAPS3:       equ    3                                         ; Port A Interrupt Pin Select Bit 3
PTAPS_PTAPS4:       equ    4                                         ; Port A Interrupt Pin Select Bit 4
PTAPS_PTAPS5:       equ    5                                         ; Port A Interrupt Pin Select Bit 5
PTAPS_PTAPS6:       equ    6                                         ; Port A Interrupt Pin Select Bit 6
PTAPS_PTAPS7:       equ    7                                         ; Port A Interrupt Pin Select Bit 7
; bit position masks
mPTAPS_PTAPS0:      equ    %00000001
mPTAPS_PTAPS1:      equ    %00000010
mPTAPS_PTAPS2:      equ    %00000100
mPTAPS_PTAPS3:      equ    %00001000
mPTAPS_PTAPS4:      equ    %00010000
mPTAPS_PTAPS5:      equ    %00100000
mPTAPS_PTAPS6:      equ    %01000000
mPTAPS_PTAPS7:      equ    %10000000


;*** PTAES - Port A Interrupt Edge Select Register; 0x00001846 ***
PTAES:              equ    $00001846                                ;*** PTAES - Port A Interrupt Edge Select Register; 0x00001846 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAES_PTAES0:       equ    0                                         ; Port A Edge Select Bit 0
PTAES_PTAES1:       equ    1                                         ; Port A Edge Select Bit 1
PTAES_PTAES2:       equ    2                                         ; Port A Edge Select Bit 2
PTAES_PTAES3:       equ    3                                         ; Port A Edge Select Bit 3
PTAES_PTAES4:       equ    4                                         ; Port A Edge Select Bit 4
PTAES_PTAES5:       equ    5                                         ; Port A Edge Select Bit 5
PTAES_PTAES6:       equ    6                                         ; Port A Edge Select Bit 6
PTAES_PTAES7:       equ    7                                         ; Port A Edge Select Bit 7
; bit position masks
mPTAES_PTAES0:      equ    %00000001
mPTAES_PTAES1:      equ    %00000010
mPTAES_PTAES2:      equ    %00000100
mPTAES_PTAES3:      equ    %00001000
mPTAES_PTAES4:      equ    %00010000
mPTAES_PTAES5:      equ    %00100000
mPTAES_PTAES6:      equ    %01000000
mPTAES_PTAES7:      equ    %10000000


;*** PTBPE - Pullup Enable for Port B; 0x00001848 ***
PTBPE:              equ    $00001848                                ;*** PTBPE - Pullup Enable for Port B; 0x00001848 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0:       equ    0                                         ; Pullup Enable for Port B Bit 0
PTBPE_PTBPE1:       equ    1                                         ; Pullup Enable for Port B Bit 1
PTBPE_PTBPE2:       equ    2                                         ; Pullup Enable for Port B Bit 2
PTBPE_PTBPE3:       equ    3                                         ; Pullup Enable for Port B Bit 3
PTBPE_PTBPE4:       equ    4                                         ; Pullup Enable for Port B Bit 4
PTBPE_PTBPE5:       equ    5                                         ; Pullup Enable for Port B Bit 5
PTBPE_PTBPE6:       equ    6                                         ; Pullup Enable for Port B Bit 6
PTBPE_PTBPE7:       equ    7                                         ; Pullup Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0:      equ    %00000001
mPTBPE_PTBPE1:      equ    %00000010
mPTBPE_PTBPE2:      equ    %00000100
mPTBPE_PTBPE3:      equ    %00001000
mPTBPE_PTBPE4:      equ    %00010000
mPTBPE_PTBPE5:      equ    %00100000
mPTBPE_PTBPE6:      equ    %01000000
mPTBPE_PTBPE7:      equ    %10000000


;*** PTBSE - Slew Rate Control Enable for Port B; 0x00001849 ***
PTBSE:              equ    $00001849                                ;*** PTBSE - Slew Rate Control Enable for Port B; 0x00001849 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE0:       equ    0                                         ; Slew Rate Control Enable for Port B Bit 0
PTBSE_PTBSE1:       equ    1                                         ; Slew Rate Control Enable for Port B Bit 1
PTBSE_PTBSE2:       equ    2                                         ; Slew Rate Control Enable for Port B Bit 2
PTBSE_PTBSE3:       equ    3                                         ; Slew Rate Control Enable for Port B Bit 3
PTBSE_PTBSE4:       equ    4                                         ; Slew Rate Control Enable for Port B Bit 4
PTBSE_PTBSE5:       equ    5                                         ; Slew Rate Control Enable for Port B Bit 5
PTBSE_PTBSE6:       equ    6                                         ; Slew Rate Control Enable for Port B Bit 6
PTBSE_PTBSE7:       equ    7                                         ; Slew Rate Control Enable for Port B Bit 7
; bit position masks
mPTBSE_PTBSE0:      equ    %00000001
mPTBSE_PTBSE1:      equ    %00000010
mPTBSE_PTBSE2:      equ    %00000100
mPTBSE_PTBSE3:      equ    %00001000
mPTBSE_PTBSE4:      equ    %00010000
mPTBSE_PTBSE5:      equ    %00100000
mPTBSE_PTBSE6:      equ    %01000000
mPTBSE_PTBSE7:      equ    %10000000


;*** PTBDS - Output Drive Strength Selection for Port B; 0x0000184A ***
PTBDS:              equ    $0000184A                                ;*** PTBDS - Output Drive Strength Selection for Port B; 0x0000184A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS0:       equ    0                                         ; Output Drive Strength Selection for Port B Bit 0
PTBDS_PTBDS1:       equ    1                                         ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2:       equ    2                                         ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS3:       equ    3                                         ; Output Drive Strength Selection for Port B Bit 3
PTBDS_PTBDS4:       equ    4                                         ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5:       equ    5                                         ; Output Drive Strength Selection for Port B Bit 5
PTBDS_PTBDS6:       equ    6                                         ; Output Drive Strength Selection for Port B Bit 6
PTBDS_PTBDS7:       equ    7                                         ; Output Drive Strength Selection for Port B Bit 7
; bit position masks
mPTBDS_PTBDS0:      equ    %00000001
mPTBDS_PTBDS1:      equ    %00000010
mPTBDS_PTBDS2:      equ    %00000100
mPTBDS_PTBDS3:      equ    %00001000
mPTBDS_PTBDS4:      equ    %00010000
mPTBDS_PTBDS5:      equ    %00100000
mPTBDS_PTBDS6:      equ    %01000000
mPTBDS_PTBDS7:      equ    %10000000


;*** PTBSC - Port B Interrupt Status and Control Register; 0x0000184C ***
PTBSC:              equ    $0000184C                                ;*** PTBSC - Port B Interrupt Status and Control Register; 0x0000184C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSC_PTBMOD:       equ    0                                         ; Port B Detection Mode
PTBSC_PTBIE:        equ    1                                         ; Port B Interrupt Enable
PTBSC_PTBACK:       equ    2                                         ; Port B Interrupt Acknowledge
PTBSC_PTBIF:        equ    3                                         ; Port B Interrupt Flag
; bit position masks
mPTBSC_PTBMOD:      equ    %00000001
mPTBSC_PTBIE:       equ    %00000010
mPTBSC_PTBACK:      equ    %00000100
mPTBSC_PTBIF:       equ    %00001000


;*** PTBPS - Port B Interrupt Pin Select Register; 0x0000184D ***
PTBPS:              equ    $0000184D                                ;*** PTBPS - Port B Interrupt Pin Select Register; 0x0000184D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPS_PTBPS0:       equ    0                                         ; Port B Interrupt Pin Select Bit 0
PTBPS_PTBPS1:       equ    1                                         ; Port B Interrupt Pin Select Bit 1
PTBPS_PTBPS2:       equ    2                                         ; Port B Interrupt Pin Select Bit 2
PTBPS_PTBPS3:       equ    3                                         ; Port B Interrupt Pin Select Bit 3
PTBPS_PTBPS4:       equ    4                                         ; Port B Interrupt Pin Select Bit 4
PTBPS_PTBPS5:       equ    5                                         ; Port B Interrupt Pin Select Bit 5
PTBPS_PTBPS6:       equ    6                                         ; Port B Interrupt Pin Select Bit 6
PTBPS_PTBPS7:       equ    7                                         ; Port B Interrupt Pin Select Bit 7
; bit position masks
mPTBPS_PTBPS0:      equ    %00000001
mPTBPS_PTBPS1:      equ    %00000010
mPTBPS_PTBPS2:      equ    %00000100
mPTBPS_PTBPS3:      equ    %00001000
mPTBPS_PTBPS4:      equ    %00010000
mPTBPS_PTBPS5:      equ    %00100000
mPTBPS_PTBPS6:      equ    %01000000
mPTBPS_PTBPS7:      equ    %10000000


;*** PTBES - Port B Interrupt Edge Select Register; 0x0000184E ***
PTBES:              equ    $0000184E                                ;*** PTBES - Port B Interrupt Edge Select Register; 0x0000184E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBES_PTBES0:       equ    0                                         ; Port B Edge Select Bit 0
PTBES_PTBES1:       equ    1                                         ; Port B Edge Select Bit 1
PTBES_PTBES2:       equ    2                                         ; Port B Edge Select Bit 2
PTBES_PTBES3:       equ    3                                         ; Port B Edge Select Bit 3
PTBES_PTBES4:       equ    4                                         ; Port B Edge Select Bit 4
PTBES_PTBES5:       equ    5                                         ; Port B Edge Select Bit 5
PTBES_PTBES6:       equ    6                                         ; Port B Edge Select Bit 6
PTBES_PTBES7:       equ    7                                         ; Port B Edge Select Bit 7
; bit position masks
mPTBES_PTBES0:      equ    %00000001
mPTBES_PTBES1:      equ    %00000010
mPTBES_PTBES2:      equ    %00000100
mPTBES_PTBES3:      equ    %00001000
mPTBES_PTBES4:      equ    %00010000
mPTBES_PTBES5:      equ    %00100000
mPTBES_PTBES6:      equ    %01000000
mPTBES_PTBES7:      equ    %10000000


;*** PTCPE - Pullup Enable for Port C; 0x00001850 ***
PTCPE:              equ    $00001850                                ;*** PTCPE - Pullup Enable for Port C; 0x00001850 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0:       equ    0                                         ; Pullup Enable for Port C Bit 0
PTCPE_PTCPE1:       equ    1                                         ; Pullup Enable for Port C Bit 1
PTCPE_PTCPE2:       equ    2                                         ; Pullup Enable for Port C Bit 2
PTCPE_PTCPE3:       equ    3                                         ; Pullup Enable for Port C Bit 3
PTCPE_PTCPE4:       equ    4                                         ; Pullup Enable for Port C Bit 4
PTCPE_PTCPE5:       equ    5                                         ; Pullup Enable for Port C Bit 5
PTCPE_PTCPE6:       equ    6                                         ; Pullup Enable for Port C Bit 6
PTCPE_PTCPE7:       equ    7                                         ; Pullup Enable for Port C Bit 7
; bit position masks
mPTCPE_PTCPE0:      equ    %00000001
mPTCPE_PTCPE1:      equ    %00000010
mPTCPE_PTCPE2:      equ    %00000100
mPTCPE_PTCPE3:      equ    %00001000
mPTCPE_PTCPE4:      equ    %00010000
mPTCPE_PTCPE5:      equ    %00100000
mPTCPE_PTCPE6:      equ    %01000000
mPTCPE_PTCPE7:      equ    %10000000


;*** PTCSE - Slew Rate Control Enable for Port C; 0x00001851 ***
PTCSE:              equ    $00001851                                ;*** PTCSE - Slew Rate Control Enable for Port C; 0x00001851 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0:       equ    0                                         ; Slew Rate Control Enable for Port C Bit 0
PTCSE_PTCSE1:       equ    1                                         ; Slew Rate Control Enable for Port C Bit 1
PTCSE_PTCSE2:       equ    2                                         ; Slew Rate Control Enable for Port C Bit 2
PTCSE_PTCSE3:       equ    3                                         ; Slew Rate Control Enable for Port C Bit 3
PTCSE_PTCSE4:       equ    4                                         ; Slew Rate Control Enable for Port C Bit 4
PTCSE_PTCSE5:       equ    5                                         ; Slew Rate Control Enable for Port C Bit 5
PTCSE_PTCSE6:       equ    6                                         ; Slew Rate Control Enable for Port C Bit 6
PTCSE_PTCSE7:       equ    7                                         ; Slew Rate Control Enable for Port C Bit 7
; bit position masks
mPTCSE_PTCSE0:      equ    %00000001
mPTCSE_PTCSE1:      equ    %00000010
mPTCSE_PTCSE2:      equ    %00000100
mPTCSE_PTCSE3:      equ    %00001000
mPTCSE_PTCSE4:      equ    %00010000
mPTCSE_PTCSE5:      equ    %00100000
mPTCSE_PTCSE6:      equ    %01000000
mPTCSE_PTCSE7:      equ    %10000000


;*** PTCDS - Output Drive Strength Selection for Port C; 0x00001852 ***
PTCDS:              equ    $00001852                                ;*** PTCDS - Output Drive Strength Selection for Port C; 0x00001852 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0:       equ    0                                         ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1:       equ    1                                         ; Output Drive Strength Selection for Port C Bit 1
PTCDS_PTCDS2:       equ    2                                         ; Output Drive Strength Selection for Port C Bit 2
PTCDS_PTCDS3:       equ    3                                         ; Output Drive Strength Selection for Port C Bit 3
PTCDS_PTCDS4:       equ    4                                         ; Output Drive Strength Selection for Port C Bit 4
PTCDS_PTCDS5:       equ    5                                         ; Output Drive Strength Selection for Port C Bit 5
PTCDS_PTCDS6:       equ    6                                         ; Output Drive Strength Selection for Port C Bit 6
PTCDS_PTCDS7:       equ    7                                         ; Output Drive Strength Selection for Port C Bit 7
; bit position masks
mPTCDS_PTCDS0:      equ    %00000001
mPTCDS_PTCDS1:      equ    %00000010
mPTCDS_PTCDS2:      equ    %00000100
mPTCDS_PTCDS3:      equ    %00001000
mPTCDS_PTCDS4:      equ    %00010000
mPTCDS_PTCDS5:      equ    %00100000
mPTCDS_PTCDS6:      equ    %01000000
mPTCDS_PTCDS7:      equ    %10000000


;*** PTDPE - Pullup Enable for Port D; 0x00001858 ***
PTDPE:              equ    $00001858                                ;*** PTDPE - Pullup Enable for Port D; 0x00001858 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0:       equ    0                                         ; Pullup Enable for Port D Bit 0
PTDPE_PTDPE1:       equ    1                                         ; Pullup Enable for Port D Bit 1
PTDPE_PTDPE2:       equ    2                                         ; Pullup Enable for Port D Bit 2
PTDPE_PTDPE3:       equ    3                                         ; Pullup Enable for Port D Bit 3
PTDPE_PTDPE4:       equ    4                                         ; Pullup Enable for Port D Bit 4
PTDPE_PTDPE5:       equ    5                                         ; Pullup Enable for Port D Bit 5
PTDPE_PTDPE6:       equ    6                                         ; Pullup Enable for Port D Bit 6
PTDPE_PTDPE7:       equ    7                                         ; Pullup Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0:      equ    %00000001
mPTDPE_PTDPE1:      equ    %00000010
mPTDPE_PTDPE2:      equ    %00000100
mPTDPE_PTDPE3:      equ    %00001000
mPTDPE_PTDPE4:      equ    %00010000
mPTDPE_PTDPE5:      equ    %00100000
mPTDPE_PTDPE6:      equ    %01000000
mPTDPE_PTDPE7:      equ    %10000000


;*** PTDSE - Slew Rate Control Enable for Port D; 0x00001859 ***
PTDSE:              equ    $00001859                                ;*** PTDSE - Slew Rate Control Enable for Port D; 0x00001859 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSE_PTDSE0:       equ    0                                         ; Slew Rate Control Enable for Port D Bit 0
PTDSE_PTDSE1:       equ    1                                         ; Slew Rate Control Enable for Port D Bit 1
PTDSE_PTDSE2:       equ    2                                         ; Slew Rate Control Enable for Port D Bit 2
PTDSE_PTDSE3:       equ    3                                         ; Slew Rate Control Enable for Port D Bit 3
PTDSE_PTDSE4:       equ    4                                         ; Slew Rate Control Enable for Port D Bit 4
PTDSE_PTDSE5:       equ    5                                         ; Slew Rate Control Enable for Port D Bit 5
PTDSE_PTDSE6:       equ    6                                         ; Slew Rate Control Enable for Port D Bit 6
PTDSE_PTDSE7:       equ    7                                         ; Slew Rate Control Enable for Port D Bit 7
; bit position masks
mPTDSE_PTDSE0:      equ    %00000001
mPTDSE_PTDSE1:      equ    %00000010
mPTDSE_PTDSE2:      equ    %00000100
mPTDSE_PTDSE3:      equ    %00001000
mPTDSE_PTDSE4:      equ    %00010000
mPTDSE_PTDSE5:      equ    %00100000
mPTDSE_PTDSE6:      equ    %01000000
mPTDSE_PTDSE7:      equ    %10000000


;*** PTDDS - Output Drive Strength Selection for Port D; 0x0000185A ***
PTDDS:              equ    $0000185A                                ;*** PTDDS - Output Drive Strength Selection for Port D; 0x0000185A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDS_PTDDS0:       equ    0                                         ; Output Drive Strength Selection for Port D Bit 0
PTDDS_PTDDS1:       equ    1                                         ; Output Drive Strength Selection for Port D Bit 1
PTDDS_PTDDS2:       equ    2                                         ; Output Drive Strength Selection for Port D Bit 2
PTDDS_PTDDS3:       equ    3                                         ; Output Drive Strength Selection for Port D Bit 3
PTDDS_PTDDS4:       equ    4                                         ; Output Drive Strength Selection for Port D Bit 4
PTDDS_PTDDS5:       equ    5                                         ; Output Drive Strength Selection for Port D Bit 5
PTDDS_PTDDS6:       equ    6                                         ; Output Drive Strength Selection for Port D Bit 6
PTDDS_PTDDS7:       equ    7                                         ; Output Drive Strength Selection for Port D Bit 7
; bit position masks
mPTDDS_PTDDS0:      equ    %00000001
mPTDDS_PTDDS1:      equ    %00000010
mPTDDS_PTDDS2:      equ    %00000100
mPTDDS_PTDDS3:      equ    %00001000
mPTDDS_PTDDS4:      equ    %00010000
mPTDDS_PTDDS5:      equ    %00100000
mPTDDS_PTDDS6:      equ    %01000000
mPTDDS_PTDDS7:      equ    %10000000


;*** PTDSC - Port D Interrupt Status and Control Register; 0x0000185C ***
PTDSC:              equ    $0000185C                                ;*** PTDSC - Port D Interrupt Status and Control Register; 0x0000185C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSC_PTDMOD:       equ    0                                         ; Port D Detection Mode
PTDSC_PTDIE:        equ    1                                         ; Port D Interrupt Enable
PTDSC_PTDACK:       equ    2                                         ; Port D Interrupt Acknowledge
PTDSC_PTDIF:        equ    3                                         ; Port D Interrupt Flag
; bit position masks
mPTDSC_PTDMOD:      equ    %00000001
mPTDSC_PTDIE:       equ    %00000010
mPTDSC_PTDACK:      equ    %00000100
mPTDSC_PTDIF:       equ    %00001000


;*** PTDPS - Port D Interrupt Pin Select Register; 0x0000185D ***
PTDPS:              equ    $0000185D                                ;*** PTDPS - Port D Interrupt Pin Select Register; 0x0000185D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPS_PTDPS0:       equ    0                                         ; Port D Interrupt Pin Select Bit 0
PTDPS_PTDPS1:       equ    1                                         ; Port D Interrupt Pin Select Bit 1
PTDPS_PTDPS2:       equ    2                                         ; Port D Interrupt Pin Select Bit 2
PTDPS_PTDPS3:       equ    3                                         ; Port D Interrupt Pin Select Bit 3
PTDPS_PTDPS4:       equ    4                                         ; Port D Interrupt Pin Select Bit 4
PTDPS_PTDPS5:       equ    5                                         ; Port D Interrupt Pin Select Bit 5
PTDPS_PTDPS6:       equ    6                                         ; Port D Interrupt Pin Select Bit 6
PTDPS_PTDPS7:       equ    7                                         ; Port D Interrupt Pin Select Bit 7
; bit position masks
mPTDPS_PTDPS0:      equ    %00000001
mPTDPS_PTDPS1:      equ    %00000010
mPTDPS_PTDPS2:      equ    %00000100
mPTDPS_PTDPS3:      equ    %00001000
mPTDPS_PTDPS4:      equ    %00010000
mPTDPS_PTDPS5:      equ    %00100000
mPTDPS_PTDPS6:      equ    %01000000
mPTDPS_PTDPS7:      equ    %10000000


;*** PTDES - Port D Interrupt Edge Select Register; 0x0000185E ***
PTDES:              equ    $0000185E                                ;*** PTDES - Port D Interrupt Edge Select Register; 0x0000185E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDES_PTDES0:       equ    0                                         ; Port D Edge Select Bit 0
PTDES_PTDES1:       equ    1                                         ; Port D Edge Select Bit 1
PTDES_PTDES2:       equ    2                                         ; Port D Edge Select Bit 2
PTDES_PTDES3:       equ    3                                         ; Port D Edge Select Bit 3
PTDES_PTDES4:       equ    4                                         ; Port D Edge Select Bit 4
PTDES_PTDES5:       equ    5                                         ; Port D Edge Select Bit 5
PTDES_PTDES6:       equ    6                                         ; Port D Edge Select Bit 6
PTDES_PTDES7:       equ    7                                         ; Port D Edge Select Bit 7
; bit position masks
mPTDES_PTDES0:      equ    %00000001
mPTDES_PTDES1:      equ    %00000010
mPTDES_PTDES2:      equ    %00000100
mPTDES_PTDES3:      equ    %00001000
mPTDES_PTDES4:      equ    %00010000
mPTDES_PTDES5:      equ    %00100000
mPTDES_PTDES6:      equ    %01000000
mPTDES_PTDES7:      equ    %10000000


;*** PTEPE - Pullup Enable for Port E; 0x00001860 ***
PTEPE:              equ    $00001860                                ;*** PTEPE - Pullup Enable for Port E; 0x00001860 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPE_PTEPE0:       equ    0                                         ; Pullup Enable for Port E Bit 0
PTEPE_PTEPE1:       equ    1                                         ; Pullup Enable for Port E Bit 1
PTEPE_PTEPE2:       equ    2                                         ; Pullup Enable for Port E Bit 2
PTEPE_PTEPE3:       equ    3                                         ; Pullup Enable for Port E Bit 3
PTEPE_PTEPE4:       equ    4                                         ; Pullup Enable for Port E Bit 4
PTEPE_PTEPE5:       equ    5                                         ; Pullup Enable for Port E Bit 5
PTEPE_PTEPE6:       equ    6                                         ; Pullup Enable for Port E Bit 6
PTEPE_PTEPE7:       equ    7                                         ; Pullup Enable for Port E Bit 7
; bit position masks
mPTEPE_PTEPE0:      equ    %00000001
mPTEPE_PTEPE1:      equ    %00000010
mPTEPE_PTEPE2:      equ    %00000100
mPTEPE_PTEPE3:      equ    %00001000
mPTEPE_PTEPE4:      equ    %00010000
mPTEPE_PTEPE5:      equ    %00100000
mPTEPE_PTEPE6:      equ    %01000000
mPTEPE_PTEPE7:      equ    %10000000


;*** PTESE - Slew Rate Control Enable for Port E; 0x00001861 ***
PTESE:              equ    $00001861                                ;*** PTESE - Slew Rate Control Enable for Port E; 0x00001861 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTESE_PTESE0:       equ    0                                         ; Slew Rate Control Enable for Port E Bit 0
PTESE_PTESE1:       equ    1                                         ; Slew Rate Control Enable for Port E Bit 1
PTESE_PTESE2:       equ    2                                         ; Slew Rate Control Enable for Port E Bit 2
PTESE_PTESE3:       equ    3                                         ; Slew Rate Control Enable for Port E Bit 3
PTESE_PTESE4:       equ    4                                         ; Slew Rate Control Enable for Port E Bit 4
PTESE_PTESE5:       equ    5                                         ; Slew Rate Control Enable for Port E Bit 5
PTESE_PTESE6:       equ    6                                         ; Slew Rate Control Enable for Port E Bit 6
PTESE_PTESE7:       equ    7                                         ; Slew Rate Control Enable for Port E Bit 7
; bit position masks
mPTESE_PTESE0:      equ    %00000001
mPTESE_PTESE1:      equ    %00000010
mPTESE_PTESE2:      equ    %00000100
mPTESE_PTESE3:      equ    %00001000
mPTESE_PTESE4:      equ    %00010000
mPTESE_PTESE5:      equ    %00100000
mPTESE_PTESE6:      equ    %01000000
mPTESE_PTESE7:      equ    %10000000


;*** PTEDS - Output Drive Strength Selection for Port E; 0x00001862 ***
PTEDS:              equ    $00001862                                ;*** PTEDS - Output Drive Strength Selection for Port E; 0x00001862 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDS_PTEDS0:       equ    0                                         ; Output Drive Strength Selection for Port E Bit 0
PTEDS_PTEDS1:       equ    1                                         ; Output Drive Strength Selection for Port E Bit 1
PTEDS_PTEDS2:       equ    2                                         ; Output Drive Strength Selection for Port E Bit 2
PTEDS_PTEDS3:       equ    3                                         ; Output Drive Strength Selection for Port E Bit 3
PTEDS_PTEDS4:       equ    4                                         ; Output Drive Strength Selection for Port E Bit 4
PTEDS_PTEDS5:       equ    5                                         ; Output Drive Strength Selection for Port E Bit 5
PTEDS_PTEDS6:       equ    6                                         ; Output Drive Strength Selection for Port E Bit 6
PTEDS_PTEDS7:       equ    7                                         ; Output Drive Strength Selection for Port E Bit 7
; bit position masks
mPTEDS_PTEDS0:      equ    %00000001
mPTEDS_PTEDS1:      equ    %00000010
mPTEDS_PTEDS2:      equ    %00000100
mPTEDS_PTEDS3:      equ    %00001000
mPTEDS_PTEDS4:      equ    %00010000
mPTEDS_PTEDS5:      equ    %00100000
mPTEDS_PTEDS6:      equ    %01000000
mPTEDS_PTEDS7:      equ    %10000000


;*** PTFPE - Pullup Enable for Port F; 0x00001868 ***
PTFPE:              equ    $00001868                                ;*** PTFPE - Pullup Enable for Port F; 0x00001868 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPE_PTFPE0:       equ    0                                         ; Pullup Enable for Port F Bit 0
PTFPE_PTFPE1:       equ    1                                         ; Pullup Enable for Port F Bit 1
PTFPE_PTFPE2:       equ    2                                         ; Pullup Enable for Port F Bit 2
PTFPE_PTFPE3:       equ    3                                         ; Pullup Enable for Port F Bit 3
PTFPE_PTFPE4:       equ    4                                         ; Pullup Enable for Port F Bit 4
PTFPE_PTFPE5:       equ    5                                         ; Pullup Enable for Port F Bit 5
PTFPE_PTFPE6:       equ    6                                         ; Pullup Enable for Port F Bit 6
PTFPE_PTFPE7:       equ    7                                         ; Pullup Enable for Port F Bit 7
; bit position masks
mPTFPE_PTFPE0:      equ    %00000001
mPTFPE_PTFPE1:      equ    %00000010
mPTFPE_PTFPE2:      equ    %00000100
mPTFPE_PTFPE3:      equ    %00001000
mPTFPE_PTFPE4:      equ    %00010000
mPTFPE_PTFPE5:      equ    %00100000
mPTFPE_PTFPE6:      equ    %01000000
mPTFPE_PTFPE7:      equ    %10000000


;*** PTFSE - Slew Rate Control Enable for Port F; 0x00001869 ***
PTFSE:              equ    $00001869                                ;*** PTFSE - Slew Rate Control Enable for Port F; 0x00001869 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSE_PTFSE0:       equ    0                                         ; Slew Rate Control Enable for Port F Bit 0
PTFSE_PTFSE1:       equ    1                                         ; Slew Rate Control Enable for Port F Bit 1
PTFSE_PTFSE2:       equ    2                                         ; Slew Rate Control Enable for Port F Bit 2
PTFSE_PTFSE3:       equ    3                                         ; Slew Rate Control Enable for Port F Bit 3
PTFSE_PTFSE4:       equ    4                                         ; Slew Rate Control Enable for Port F Bit 4
PTFSE_PTFSE5:       equ    5                                         ; Slew Rate Control Enable for Port F Bit 5
PTFSE_PTFSE6:       equ    6                                         ; Slew Rate Control Enable for Port F Bit 6
PTFSE_PTFSE7:       equ    7                                         ; Slew Rate Control Enable for Port F Bit 7
; bit position masks
mPTFSE_PTFSE0:      equ    %00000001
mPTFSE_PTFSE1:      equ    %00000010
mPTFSE_PTFSE2:      equ    %00000100
mPTFSE_PTFSE3:      equ    %00001000
mPTFSE_PTFSE4:      equ    %00010000
mPTFSE_PTFSE5:      equ    %00100000
mPTFSE_PTFSE6:      equ    %01000000
mPTFSE_PTFSE7:      equ    %10000000


;*** PTFDS - Output Drive Strength Selection for Port F; 0x0000186A ***
PTFDS:              equ    $0000186A                                ;*** PTFDS - Output Drive Strength Selection for Port F; 0x0000186A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDS_PTFDS0:       equ    0                                         ; Output Drive Strength Selection for Port F Bit 0
PTFDS_PTFDS1:       equ    1                                         ; Output Drive Strength Selection for Port F Bit 1
PTFDS_PTFDS2:       equ    2                                         ; Output Drive Strength Selection for Port F Bit 2
PTFDS_PTFDS3:       equ    3                                         ; Output Drive Strength Selection for Port F Bit 3
PTFDS_PTFDS4:       equ    4                                         ; Output Drive Strength Selection for Port F Bit 4
PTFDS_PTFDS5:       equ    5                                         ; Output Drive Strength Selection for Port F Bit 5
PTFDS_PTFDS6:       equ    6                                         ; Output Drive Strength Selection for Port F Bit 6
PTFDS_PTFDS7:       equ    7                                         ; Output Drive Strength Selection for Port F Bit 7
; bit position masks
mPTFDS_PTFDS0:      equ    %00000001
mPTFDS_PTFDS1:      equ    %00000010
mPTFDS_PTFDS2:      equ    %00000100
mPTFDS_PTFDS3:      equ    %00001000
mPTFDS_PTFDS4:      equ    %00010000
mPTFDS_PTFDS5:      equ    %00100000
mPTFDS_PTFDS6:      equ    %01000000
mPTFDS_PTFDS7:      equ    %10000000


;*** PTGPE - Pullup Enable for Port G; 0x00001870 ***
PTGPE:              equ    $00001870                                ;*** PTGPE - Pullup Enable for Port G; 0x00001870 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPE_PTGPE0:       equ    0                                         ; Pullup Enable for Port G Bit 0
PTGPE_PTGPE1:       equ    1                                         ; Pullup Enable for Port G Bit 1
PTGPE_PTGPE2:       equ    2                                         ; Pullup Enable for Port G Bit 2
PTGPE_PTGPE3:       equ    3                                         ; Pullup Enable for Port G Bit 3
PTGPE_PTGPE4:       equ    4                                         ; Pullup Enable for Port G Bit 4
PTGPE_PTGPE5:       equ    5                                         ; Pullup Enable for Port G Bit 5
; bit position masks
mPTGPE_PTGPE0:      equ    %00000001
mPTGPE_PTGPE1:      equ    %00000010
mPTGPE_PTGPE2:      equ    %00000100
mPTGPE_PTGPE3:      equ    %00001000
mPTGPE_PTGPE4:      equ    %00010000
mPTGPE_PTGPE5:      equ    %00100000


;*** PTGSE - Slew Rate Control Enable for Port G; 0x00001871 ***
PTGSE:              equ    $00001871                                ;*** PTGSE - Slew Rate Control Enable for Port G; 0x00001871 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGSE_PTGSE0:       equ    0                                         ; Slew Rate Control Enable for Port G Bit 0
PTGSE_PTGSE1:       equ    1                                         ; Slew Rate Control Enable for Port G Bit 1
PTGSE_PTGSE2:       equ    2                                         ; Slew Rate Control Enable for Port G Bit 2
PTGSE_PTGSE3:       equ    3                                         ; Slew Rate Control Enable for Port G Bit 3
PTGSE_PTGSE4:       equ    4                                         ; Slew Rate Control Enable for Port G Bit 4
PTGSE_PTGSE5:       equ    5                                         ; Slew Rate Control Enable for Port G Bit 5
; bit position masks
mPTGSE_PTGSE0:      equ    %00000001
mPTGSE_PTGSE1:      equ    %00000010
mPTGSE_PTGSE2:      equ    %00000100
mPTGSE_PTGSE3:      equ    %00001000
mPTGSE_PTGSE4:      equ    %00010000
mPTGSE_PTGSE5:      equ    %00100000


;*** PTGDS - Output Drive Strength Selection for Port G; 0x00001872 ***
PTGDS:              equ    $00001872                                ;*** PTGDS - Output Drive Strength Selection for Port G; 0x00001872 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDS_PTGDS0:       equ    0                                         ; Output Drive Strength Selection for Port G Bit 0
PTGDS_PTGDS1:       equ    1                                         ; Output Drive Strength Selection for Port G Bit 1
PTGDS_PTGDS2:       equ    2                                         ; Output Drive Strength Selection for Port G Bit 2
PTGDS_PTGDS3:       equ    3                                         ; Output Drive Strength Selection for Port G Bit 3
PTGDS_PTGDS4:       equ    4                                         ; Output Drive Strength Selection for Port G Bit 4
PTGDS_PTGDS5:       equ    5                                         ; Output Drive Strength Selection for Port G Bit 5
; bit position masks
mPTGDS_PTGDS0:      equ    %00000001
mPTGDS_PTGDS1:      equ    %00000010
mPTGDS_PTGDS2:      equ    %00000100
mPTGDS_PTGDS3:      equ    %00001000
mPTGDS_PTGDS4:      equ    %00010000
mPTGDS_PTGDS5:      equ    %00100000


;*** CANCTL0 - MSCAN Control 0 Register; 0x00001880 ***
CANCTL0:            equ    $00001880                                ;*** CANCTL0 - MSCAN Control 0 Register; 0x00001880 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANCTL0_INITRQ:     equ    0                                         ; Initialization Mode Request
CANCTL0_SLPRQ:      equ    1                                         ; Sleep Mode Request
CANCTL0_WUPE:       equ    2                                         ; Wake-Up Enable
CANCTL0_TIME:       equ    3                                         ; Timer Enable
CANCTL0_SYNCH:      equ    4                                         ; Synchronized Status
CANCTL0_CSWAI:      equ    5                                         ; CAN Stops in Wait Mode
CANCTL0_RXACT:      equ    6                                         ; Receiver Active Status
CANCTL0_RXFRM:      equ    7                                         ; Received Frame Flag
; bit position masks
mCANCTL0_INITRQ:    equ    %00000001
mCANCTL0_SLPRQ:     equ    %00000010
mCANCTL0_WUPE:      equ    %00000100
mCANCTL0_TIME:      equ    %00001000
mCANCTL0_SYNCH:     equ    %00010000
mCANCTL0_CSWAI:     equ    %00100000
mCANCTL0_RXACT:     equ    %01000000
mCANCTL0_RXFRM:     equ    %10000000


;*** CANCTL1 - MSCAN Control 1 Register; 0x00001881 ***
CANCTL1:            equ    $00001881                                ;*** CANCTL1 - MSCAN Control 1 Register; 0x00001881 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANCTL1_INITAK:     equ    0                                         ; Initialization Mode Acknowledge
CANCTL1_SLPAK:      equ    1                                         ; Sleep Mode Acknowledge
CANCTL1_WUPM:       equ    2                                         ; Wake-Up Mode
CANCTL1_LISTEN:     equ    4                                         ; Listen Only Mode
CANCTL1_LOOPB:      equ    5                                         ; Loop Back Self Test Mode
CANCTL1_CLKSRC:     equ    6                                         ; MSCAN Clock Source
CANCTL1_CANE:       equ    7                                         ; MSCAN Enable
; bit position masks
mCANCTL1_INITAK:    equ    %00000001
mCANCTL1_SLPAK:     equ    %00000010
mCANCTL1_WUPM:      equ    %00000100
mCANCTL1_LISTEN:    equ    %00010000
mCANCTL1_LOOPB:     equ    %00100000
mCANCTL1_CLKSRC:    equ    %01000000
mCANCTL1_CANE:      equ    %10000000


;*** CANBTR0 - MSCAN Bus Timing Register 0; 0x00001882 ***
CANBTR0:            equ    $00001882                                ;*** CANBTR0 - MSCAN Bus Timing Register 0; 0x00001882 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANBTR0_BRP0:       equ    0                                         ; Baud Rate Prescaler 0
CANBTR0_BRP1:       equ    1                                         ; Baud Rate Prescaler 1
CANBTR0_BRP2:       equ    2                                         ; Baud Rate Prescaler 2
CANBTR0_BRP3:       equ    3                                         ; Baud Rate Prescaler 3
CANBTR0_BRP4:       equ    4                                         ; Baud Rate Prescaler 4
CANBTR0_BRP5:       equ    5                                         ; Baud Rate Prescaler 5
CANBTR0_SJW0:       equ    6                                         ; Synchronization Jump Width 0
CANBTR0_SJW1:       equ    7                                         ; Synchronization Jump Width 1
; bit position masks
mCANBTR0_BRP0:      equ    %00000001
mCANBTR0_BRP1:      equ    %00000010
mCANBTR0_BRP2:      equ    %00000100
mCANBTR0_BRP3:      equ    %00001000
mCANBTR0_BRP4:      equ    %00010000
mCANBTR0_BRP5:      equ    %00100000
mCANBTR0_SJW0:      equ    %01000000
mCANBTR0_SJW1:      equ    %10000000


;*** CANBTR1 - MSCAN Bus Timing Register 1; 0x00001883 ***
CANBTR1:            equ    $00001883                                ;*** CANBTR1 - MSCAN Bus Timing Register 1; 0x00001883 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANBTR1_TSEG10:     equ    0                                         ; Time Segment 10
CANBTR1_TSEG11:     equ    1                                         ; Time Segment 11
CANBTR1_TSEG12:     equ    2                                         ; Time Segment 12
CANBTR1_TSEG13:     equ    3                                         ; Time Segment 13
CANBTR1_TSEG20:     equ    4                                         ; Time Segment 20
CANBTR1_TSEG21:     equ    5                                         ; Time Segment 21
CANBTR1_TSEG22:     equ    6                                         ; Time Segment 22
CANBTR1_SAMP:       equ    7                                         ; Sampling
; bit position masks
mCANBTR1_TSEG10:    equ    %00000001
mCANBTR1_TSEG11:    equ    %00000010
mCANBTR1_TSEG12:    equ    %00000100
mCANBTR1_TSEG13:    equ    %00001000
mCANBTR1_TSEG20:    equ    %00010000
mCANBTR1_TSEG21:    equ    %00100000
mCANBTR1_TSEG22:    equ    %01000000
mCANBTR1_SAMP:      equ    %10000000


;*** CANRFLG - MSCAN Receiver Flag Register; 0x00001884 ***
CANRFLG:            equ    $00001884                                ;*** CANRFLG - MSCAN Receiver Flag Register; 0x00001884 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRFLG_RXF:        equ    0                                         ; Receive Buffer Full
CANRFLG_OVRIF:      equ    1                                         ; Overrun Interrupt Flag
CANRFLG_TSTAT0:     equ    2                                         ; Transmitter Status Bit 0
CANRFLG_TSTAT1:     equ    3                                         ; Transmitter Status Bit 1
CANRFLG_RSTAT0:     equ    4                                         ; Receiver Status Bit 0
CANRFLG_RSTAT1:     equ    5                                         ; Receiver Status Bit 1
CANRFLG_CSCIF:      equ    6                                         ; CAN Status Change Interrupt Flag
CANRFLG_WUPIF:      equ    7                                         ; Wake-up Interrupt Flag
; bit position masks
mCANRFLG_RXF:       equ    %00000001
mCANRFLG_OVRIF:     equ    %00000010
mCANRFLG_TSTAT0:    equ    %00000100
mCANRFLG_TSTAT1:    equ    %00001000
mCANRFLG_RSTAT0:    equ    %00010000
mCANRFLG_RSTAT1:    equ    %00100000
mCANRFLG_CSCIF:     equ    %01000000
mCANRFLG_WUPIF:     equ    %10000000


;*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0x00001885 ***
CANRIER:            equ    $00001885                                ;*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0x00001885 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIER_RXFIE:      equ    0                                         ; Receiver Full Interrupt Enable
CANRIER_OVRIE:      equ    1                                         ; Overrun Interrupt Enable
CANRIER_TSTATE0:    equ    2                                         ; Transmitter Status Change Enable 0
CANRIER_TSTATE1:    equ    3                                         ; Transmitter Status Change Enable 1
CANRIER_RSTATE0:    equ    4                                         ; Receiver Status Change Enable 0
CANRIER_RSTATE1:    equ    5                                         ; Receiver Status Change Enable 1
CANRIER_CSCIE:      equ    6                                         ; CAN Status Change Interrupt Enable
CANRIER_WUPIE:      equ    7                                         ; Wake-up Interrupt Enable
; bit position masks
mCANRIER_RXFIE:     equ    %00000001
mCANRIER_OVRIE:     equ    %00000010
mCANRIER_TSTATE0:   equ    %00000100
mCANRIER_TSTATE1:   equ    %00001000
mCANRIER_RSTATE0:   equ    %00010000
mCANRIER_RSTATE1:   equ    %00100000
mCANRIER_CSCIE:     equ    %01000000
mCANRIER_WUPIE:     equ    %10000000


;*** CANTFLG - MSCAN Transmitter Flag Register; 0x00001886 ***
CANTFLG:            equ    $00001886                                ;*** CANTFLG - MSCAN Transmitter Flag Register; 0x00001886 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTFLG_TXE0:       equ    0                                         ; Transmitter Buffer Empty 0
CANTFLG_TXE1:       equ    1                                         ; Transmitter Buffer Empty 1
CANTFLG_TXE2:       equ    2                                         ; Transmitter Buffer Empty 2
; bit position masks
mCANTFLG_TXE0:      equ    %00000001
mCANTFLG_TXE1:      equ    %00000010
mCANTFLG_TXE2:      equ    %00000100


;*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0x00001887 ***
CANTIER:            equ    $00001887                                ;*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0x00001887 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIER_TXEIE0:     equ    0                                         ; Transmitter Empty Interrupt Enable 0
CANTIER_TXEIE1:     equ    1                                         ; Transmitter Empty Interrupt Enable 1
CANTIER_TXEIE2:     equ    2                                         ; Transmitter Empty Interrupt Enable 2
; bit position masks
mCANTIER_TXEIE0:    equ    %00000001
mCANTIER_TXEIE1:    equ    %00000010
mCANTIER_TXEIE2:    equ    %00000100


;*** CANTARQ - MSCAN Transmitter Message Abort Request; 0x00001888 ***
CANTARQ:            equ    $00001888                                ;*** CANTARQ - MSCAN Transmitter Message Abort Request; 0x00001888 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTARQ_ABTRQ0:     equ    0                                         ; Abort Request 0
CANTARQ_ABTRQ1:     equ    1                                         ; Abort Request 1
CANTARQ_ABTRQ2:     equ    2                                         ; Abort Request 2
; bit position masks
mCANTARQ_ABTRQ0:    equ    %00000001
mCANTARQ_ABTRQ1:    equ    %00000010
mCANTARQ_ABTRQ2:    equ    %00000100


;*** CANTAAK - MSCAN Transmitter Message Abort Control; 0x00001889 ***
CANTAAK:            equ    $00001889                                ;*** CANTAAK - MSCAN Transmitter Message Abort Control; 0x00001889 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTAAK_ABTAK0:     equ    0                                         ; Abort Acknowledge 0
CANTAAK_ABTAK1:     equ    1                                         ; Abort Acknowledge 1
CANTAAK_ABTAK2:     equ    2                                         ; Abort Acknowledge 2
; bit position masks
mCANTAAK_ABTAK0:    equ    %00000001
mCANTAAK_ABTAK1:    equ    %00000010
mCANTAAK_ABTAK2:    equ    %00000100


;*** CANTBSEL - MSCAN Transmit Buffer Selection; 0x0000188A ***
CANTBSEL:           equ    $0000188A                                ;*** CANTBSEL - MSCAN Transmit Buffer Selection; 0x0000188A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTBSEL_TX0:       equ    0                                         ; Transmit Buffer Select 0
CANTBSEL_TX1:       equ    1                                         ; Transmit Buffer Select 1
CANTBSEL_TX2:       equ    2                                         ; Transmit Buffer Select 2
; bit position masks
mCANTBSEL_TX0:      equ    %00000001
mCANTBSEL_TX1:      equ    %00000010
mCANTBSEL_TX2:      equ    %00000100


;*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0x0000188B ***
CANIDAC:            equ    $0000188B                                ;*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0x0000188B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAC_IDHIT0:     equ    0                                         ; Identifier Acceptance Hit Indicator 0
CANIDAC_IDHIT1:     equ    1                                         ; Identifier Acceptance Hit Indicator 1
CANIDAC_IDHIT2:     equ    2                                         ; Identifier Acceptance Hit Indicator 2
CANIDAC_IDAM0:      equ    4                                         ; Identifier Acceptance Mode 0
CANIDAC_IDAM1:      equ    5                                         ; Identifier Acceptance Mode 1
; bit position masks
mCANIDAC_IDHIT0:    equ    %00000001
mCANIDAC_IDHIT1:    equ    %00000010
mCANIDAC_IDHIT2:    equ    %00000100
mCANIDAC_IDAM0:     equ    %00010000
mCANIDAC_IDAM1:     equ    %00100000


;*** CANRXERR - MSCAN Receive Error Counter Register; 0x0000188E ***
CANRXERR:           equ    $0000188E                                ;*** CANRXERR - MSCAN Receive Error Counter Register; 0x0000188E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRXERR_RXERR0:    equ    0                                         ; Bit 0
CANRXERR_RXERR1:    equ    1                                         ; Bit 1
CANRXERR_RXERR2:    equ    2                                         ; Bit 2
CANRXERR_RXERR3:    equ    3                                         ; Bit 3
CANRXERR_RXERR4:    equ    4                                         ; Bit 4
CANRXERR_RXERR5:    equ    5                                         ; Bit 5
CANRXERR_RXERR6:    equ    6                                         ; Bit 6
CANRXERR_RXERR7:    equ    7                                         ; Bit 7
; bit position masks
mCANRXERR_RXERR0:   equ    %00000001
mCANRXERR_RXERR1:   equ    %00000010
mCANRXERR_RXERR2:   equ    %00000100
mCANRXERR_RXERR3:   equ    %00001000
mCANRXERR_RXERR4:   equ    %00010000
mCANRXERR_RXERR5:   equ    %00100000
mCANRXERR_RXERR6:   equ    %01000000
mCANRXERR_RXERR7:   equ    %10000000


;*** CANTXERR - MSCAN Transmit Error Counter Register; 0x0000188F ***
CANTXERR:           equ    $0000188F                                ;*** CANTXERR - MSCAN Transmit Error Counter Register; 0x0000188F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTXERR_TXERR0:    equ    0                                         ; Bit 0
CANTXERR_TXERR1:    equ    1                                         ; Bit 1
CANTXERR_TXERR2:    equ    2                                         ; Bit 2
CANTXERR_TXERR3:    equ    3                                         ; Bit 3
CANTXERR_TXERR4:    equ    4                                         ; Bit 4
CANTXERR_TXERR5:    equ    5                                         ; Bit 5
CANTXERR_TXERR6:    equ    6                                         ; Bit 6
CANTXERR_TXERR7:    equ    7                                         ; Bit 7
; bit position masks
mCANTXERR_TXERR0:   equ    %00000001
mCANTXERR_TXERR1:   equ    %00000010
mCANTXERR_TXERR2:   equ    %00000100
mCANTXERR_TXERR3:   equ    %00001000
mCANTXERR_TXERR4:   equ    %00010000
mCANTXERR_TXERR5:   equ    %00100000
mCANTXERR_TXERR6:   equ    %01000000
mCANTXERR_TXERR7:   equ    %10000000


;*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0x00001890 ***
CANIDAR0:           equ    $00001890                                ;*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0x00001890 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR0_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR0_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR0_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR0_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR0_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR0_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR0_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR0_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR0_AC0:      equ    %00000001
mCANIDAR0_AC1:      equ    %00000010
mCANIDAR0_AC2:      equ    %00000100
mCANIDAR0_AC3:      equ    %00001000
mCANIDAR0_AC4:      equ    %00010000
mCANIDAR0_AC5:      equ    %00100000
mCANIDAR0_AC6:      equ    %01000000
mCANIDAR0_AC7:      equ    %10000000


;*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0x00001891 ***
CANIDAR1:           equ    $00001891                                ;*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0x00001891 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR1_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR1_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR1_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR1_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR1_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR1_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR1_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR1_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR1_AC0:      equ    %00000001
mCANIDAR1_AC1:      equ    %00000010
mCANIDAR1_AC2:      equ    %00000100
mCANIDAR1_AC3:      equ    %00001000
mCANIDAR1_AC4:      equ    %00010000
mCANIDAR1_AC5:      equ    %00100000
mCANIDAR1_AC6:      equ    %01000000
mCANIDAR1_AC7:      equ    %10000000


;*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0x00001892 ***
CANIDAR2:           equ    $00001892                                ;*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0x00001892 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR2_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR2_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR2_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR2_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR2_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR2_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR2_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR2_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR2_AC0:      equ    %00000001
mCANIDAR2_AC1:      equ    %00000010
mCANIDAR2_AC2:      equ    %00000100
mCANIDAR2_AC3:      equ    %00001000
mCANIDAR2_AC4:      equ    %00010000
mCANIDAR2_AC5:      equ    %00100000
mCANIDAR2_AC6:      equ    %01000000
mCANIDAR2_AC7:      equ    %10000000


;*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0x00001893 ***
CANIDAR3:           equ    $00001893                                ;*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0x00001893 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR3_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR3_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR3_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR3_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR3_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR3_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR3_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR3_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR3_AC0:      equ    %00000001
mCANIDAR3_AC1:      equ    %00000010
mCANIDAR3_AC2:      equ    %00000100
mCANIDAR3_AC3:      equ    %00001000
mCANIDAR3_AC4:      equ    %00010000
mCANIDAR3_AC5:      equ    %00100000
mCANIDAR3_AC6:      equ    %01000000
mCANIDAR3_AC7:      equ    %10000000


;*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0x00001894 ***
CANIDMR0:           equ    $00001894                                ;*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0x00001894 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR0_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR0_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR0_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR0_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR0_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR0_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR0_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR0_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR0_AM0:      equ    %00000001
mCANIDMR0_AM1:      equ    %00000010
mCANIDMR0_AM2:      equ    %00000100
mCANIDMR0_AM3:      equ    %00001000
mCANIDMR0_AM4:      equ    %00010000
mCANIDMR0_AM5:      equ    %00100000
mCANIDMR0_AM6:      equ    %01000000
mCANIDMR0_AM7:      equ    %10000000


;*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0x00001895 ***
CANIDMR1:           equ    $00001895                                ;*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0x00001895 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR1_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR1_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR1_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR1_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR1_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR1_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR1_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR1_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR1_AM0:      equ    %00000001
mCANIDMR1_AM1:      equ    %00000010
mCANIDMR1_AM2:      equ    %00000100
mCANIDMR1_AM3:      equ    %00001000
mCANIDMR1_AM4:      equ    %00010000
mCANIDMR1_AM5:      equ    %00100000
mCANIDMR1_AM6:      equ    %01000000
mCANIDMR1_AM7:      equ    %10000000


;*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0x00001896 ***
CANIDMR2:           equ    $00001896                                ;*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0x00001896 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR2_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR2_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR2_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR2_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR2_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR2_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR2_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR2_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR2_AM0:      equ    %00000001
mCANIDMR2_AM1:      equ    %00000010
mCANIDMR2_AM2:      equ    %00000100
mCANIDMR2_AM3:      equ    %00001000
mCANIDMR2_AM4:      equ    %00010000
mCANIDMR2_AM5:      equ    %00100000
mCANIDMR2_AM6:      equ    %01000000
mCANIDMR2_AM7:      equ    %10000000


;*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0x00001897 ***
CANIDMR3:           equ    $00001897                                ;*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0x00001897 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR3_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR3_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR3_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR3_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR3_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR3_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR3_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR3_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR3_AM0:      equ    %00000001
mCANIDMR3_AM1:      equ    %00000010
mCANIDMR3_AM2:      equ    %00000100
mCANIDMR3_AM3:      equ    %00001000
mCANIDMR3_AM4:      equ    %00010000
mCANIDMR3_AM5:      equ    %00100000
mCANIDMR3_AM6:      equ    %01000000
mCANIDMR3_AM7:      equ    %10000000


;*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0x00001898 ***
CANIDAR4:           equ    $00001898                                ;*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0x00001898 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR4_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR4_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR4_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR4_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR4_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR4_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR4_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR4_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR4_AC0:      equ    %00000001
mCANIDAR4_AC1:      equ    %00000010
mCANIDAR4_AC2:      equ    %00000100
mCANIDAR4_AC3:      equ    %00001000
mCANIDAR4_AC4:      equ    %00010000
mCANIDAR4_AC5:      equ    %00100000
mCANIDAR4_AC6:      equ    %01000000
mCANIDAR4_AC7:      equ    %10000000


;*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0x00001899 ***
CANIDAR5:           equ    $00001899                                ;*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0x00001899 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR5_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR5_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR5_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR5_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR5_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR5_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR5_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR5_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR5_AC0:      equ    %00000001
mCANIDAR5_AC1:      equ    %00000010
mCANIDAR5_AC2:      equ    %00000100
mCANIDAR5_AC3:      equ    %00001000
mCANIDAR5_AC4:      equ    %00010000
mCANIDAR5_AC5:      equ    %00100000
mCANIDAR5_AC6:      equ    %01000000
mCANIDAR5_AC7:      equ    %10000000


;*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0x0000189A ***
CANIDAR6:           equ    $0000189A                                ;*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0x0000189A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR6_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR6_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR6_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR6_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR6_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR6_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR6_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR6_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR6_AC0:      equ    %00000001
mCANIDAR6_AC1:      equ    %00000010
mCANIDAR6_AC2:      equ    %00000100
mCANIDAR6_AC3:      equ    %00001000
mCANIDAR6_AC4:      equ    %00010000
mCANIDAR6_AC5:      equ    %00100000
mCANIDAR6_AC6:      equ    %01000000
mCANIDAR6_AC7:      equ    %10000000


;*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0x0000189B ***
CANIDAR7:           equ    $0000189B                                ;*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0x0000189B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR7_AC0:       equ    0                                         ; Acceptance Code Bit 0
CANIDAR7_AC1:       equ    1                                         ; Acceptance Code Bit 1
CANIDAR7_AC2:       equ    2                                         ; Acceptance Code Bit 2
CANIDAR7_AC3:       equ    3                                         ; Acceptance Code Bit 3
CANIDAR7_AC4:       equ    4                                         ; Acceptance Code Bit 4
CANIDAR7_AC5:       equ    5                                         ; Acceptance Code Bit 5
CANIDAR7_AC6:       equ    6                                         ; Acceptance Code Bit 6
CANIDAR7_AC7:       equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR7_AC0:      equ    %00000001
mCANIDAR7_AC1:      equ    %00000010
mCANIDAR7_AC2:      equ    %00000100
mCANIDAR7_AC3:      equ    %00001000
mCANIDAR7_AC4:      equ    %00010000
mCANIDAR7_AC5:      equ    %00100000
mCANIDAR7_AC6:      equ    %01000000
mCANIDAR7_AC7:      equ    %10000000


;*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0x0000189C ***
CANIDMR4:           equ    $0000189C                                ;*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0x0000189C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR4_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR4_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR4_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR4_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR4_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR4_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR4_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR4_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR4_AM0:      equ    %00000001
mCANIDMR4_AM1:      equ    %00000010
mCANIDMR4_AM2:      equ    %00000100
mCANIDMR4_AM3:      equ    %00001000
mCANIDMR4_AM4:      equ    %00010000
mCANIDMR4_AM5:      equ    %00100000
mCANIDMR4_AM6:      equ    %01000000
mCANIDMR4_AM7:      equ    %10000000


;*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0x0000189D ***
CANIDMR5:           equ    $0000189D                                ;*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0x0000189D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR5_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR5_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR5_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR5_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR5_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR5_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR5_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR5_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR5_AM0:      equ    %00000001
mCANIDMR5_AM1:      equ    %00000010
mCANIDMR5_AM2:      equ    %00000100
mCANIDMR5_AM3:      equ    %00001000
mCANIDMR5_AM4:      equ    %00010000
mCANIDMR5_AM5:      equ    %00100000
mCANIDMR5_AM6:      equ    %01000000
mCANIDMR5_AM7:      equ    %10000000


;*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0x0000189E ***
CANIDMR6:           equ    $0000189E                                ;*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0x0000189E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR6_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR6_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR6_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR6_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR6_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR6_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR6_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR6_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR6_AM0:      equ    %00000001
mCANIDMR6_AM1:      equ    %00000010
mCANIDMR6_AM2:      equ    %00000100
mCANIDMR6_AM3:      equ    %00001000
mCANIDMR6_AM4:      equ    %00010000
mCANIDMR6_AM5:      equ    %00100000
mCANIDMR6_AM6:      equ    %01000000
mCANIDMR6_AM7:      equ    %10000000


;*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0x0000189F ***
CANIDMR7:           equ    $0000189F                                ;*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0x0000189F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR7_AM0:       equ    0                                         ; Acceptance Mask Bit 0
CANIDMR7_AM1:       equ    1                                         ; Acceptance Mask Bit 1
CANIDMR7_AM2:       equ    2                                         ; Acceptance Mask Bit 2
CANIDMR7_AM3:       equ    3                                         ; Acceptance Mask Bit 3
CANIDMR7_AM4:       equ    4                                         ; Acceptance Mask Bit 4
CANIDMR7_AM5:       equ    5                                         ; Acceptance Mask Bit 5
CANIDMR7_AM6:       equ    6                                         ; Acceptance Mask Bit 6
CANIDMR7_AM7:       equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR7_AM0:      equ    %00000001
mCANIDMR7_AM1:      equ    %00000010
mCANIDMR7_AM2:      equ    %00000100
mCANIDMR7_AM3:      equ    %00001000
mCANIDMR7_AM4:      equ    %00010000
mCANIDMR7_AM5:      equ    %00100000
mCANIDMR7_AM6:      equ    %01000000
mCANIDMR7_AM7:      equ    %10000000


;*** CANRIDR0 - MSCAN Receive Identifier Register 0; 0x000018A0 ***
CANRIDR0:           equ    $000018A0                                ;*** CANRIDR0 - MSCAN Receive Identifier Register 0; 0x000018A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIDR0_ID3:       equ    0                                         ; Extended format identifier Bit 3
CANRIDR0_ID4:       equ    1                                         ; Extended format identifier Bit 4
CANRIDR0_ID5:       equ    2                                         ; Extended format identifier Bit 5
CANRIDR0_ID6:       equ    3                                         ; Extended format identifier Bit 6
CANRIDR0_ID7:       equ    4                                         ; Extended format identifier Bit 7
CANRIDR0_ID8:       equ    5                                         ; Extended format identifier Bit 8
CANRIDR0_ID9:       equ    6                                         ; Extended format identifier Bit 9
CANRIDR0_ID10:      equ    7                                         ; Extended format identifier Bit 10
; bit position masks
mCANRIDR0_ID3:      equ    %00000001
mCANRIDR0_ID4:      equ    %00000010
mCANRIDR0_ID5:      equ    %00000100
mCANRIDR0_ID6:      equ    %00001000
mCANRIDR0_ID7:      equ    %00010000
mCANRIDR0_ID8:      equ    %00100000
mCANRIDR0_ID9:      equ    %01000000
mCANRIDR0_ID10:     equ    %10000000


;*** CANRIDR1 - MSCAN Receive Identifier Register 1; 0x000018A1 ***
CANRIDR1:           equ    $000018A1                                ;*** CANRIDR1 - MSCAN Receive Identifier Register 1; 0x000018A1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIDR1_IDE:       equ    3                                         ; ID Extended
CANRIDR1_RTR:       equ    4                                         ; Remote Transmission Request
CANRIDR1_ID0:       equ    5                                         ; Extended format identifier Bit 0
CANRIDR1_ID1:       equ    6                                         ; Extended format identifier Bit 1
CANRIDR1_ID2:       equ    7                                         ; Extended format identifier Bit 2
; bit position masks
mCANRIDR1_IDE:      equ    %00001000
mCANRIDR1_RTR:      equ    %00010000
mCANRIDR1_ID0:      equ    %00100000
mCANRIDR1_ID1:      equ    %01000000
mCANRIDR1_ID2:      equ    %10000000


;*** CANRDSR0 - MSCAN Receive Data Segment Register 0; 0x000018A4 ***
CANRDSR0:           equ    $000018A4                                ;*** CANRDSR0 - MSCAN Receive Data Segment Register 0; 0x000018A4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR0_DB0:       equ    0                                         ; Data Bit 0
CANRDSR0_DB1:       equ    1                                         ; Data Bit 1
CANRDSR0_DB2:       equ    2                                         ; Data Bit 2
CANRDSR0_DB3:       equ    3                                         ; Data Bit 3
CANRDSR0_DB4:       equ    4                                         ; Data Bit 4
CANRDSR0_DB5:       equ    5                                         ; Data Bit 5
CANRDSR0_DB6:       equ    6                                         ; Data Bit 6
CANRDSR0_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR0_DB0:      equ    %00000001
mCANRDSR0_DB1:      equ    %00000010
mCANRDSR0_DB2:      equ    %00000100
mCANRDSR0_DB3:      equ    %00001000
mCANRDSR0_DB4:      equ    %00010000
mCANRDSR0_DB5:      equ    %00100000
mCANRDSR0_DB6:      equ    %01000000
mCANRDSR0_DB7:      equ    %10000000


;*** CANRDSR1 - MSCAN Receive Data Segment Register 1; 0x000018A5 ***
CANRDSR1:           equ    $000018A5                                ;*** CANRDSR1 - MSCAN Receive Data Segment Register 1; 0x000018A5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR1_DB0:       equ    0                                         ; Data Bit 0
CANRDSR1_DB1:       equ    1                                         ; Data Bit 1
CANRDSR1_DB2:       equ    2                                         ; Data Bit 2
CANRDSR1_DB3:       equ    3                                         ; Data Bit 3
CANRDSR1_DB4:       equ    4                                         ; Data Bit 4
CANRDSR1_DB5:       equ    5                                         ; Data Bit 5
CANRDSR1_DB6:       equ    6                                         ; Data Bit 6
CANRDSR1_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR1_DB0:      equ    %00000001
mCANRDSR1_DB1:      equ    %00000010
mCANRDSR1_DB2:      equ    %00000100
mCANRDSR1_DB3:      equ    %00001000
mCANRDSR1_DB4:      equ    %00010000
mCANRDSR1_DB5:      equ    %00100000
mCANRDSR1_DB6:      equ    %01000000
mCANRDSR1_DB7:      equ    %10000000


;*** CANRDSR2 - MSCAN Receive Data Segment Register 2; 0x000018A6 ***
CANRDSR2:           equ    $000018A6                                ;*** CANRDSR2 - MSCAN Receive Data Segment Register 2; 0x000018A6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR2_DB0:       equ    0                                         ; Data Bit 0
CANRDSR2_DB1:       equ    1                                         ; Data Bit 1
CANRDSR2_DB2:       equ    2                                         ; Data Bit 2
CANRDSR2_DB3:       equ    3                                         ; Data Bit 3
CANRDSR2_DB4:       equ    4                                         ; Data Bit 4
CANRDSR2_DB5:       equ    5                                         ; Data Bit 5
CANRDSR2_DB6:       equ    6                                         ; Data Bit 6
CANRDSR2_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR2_DB0:      equ    %00000001
mCANRDSR2_DB1:      equ    %00000010
mCANRDSR2_DB2:      equ    %00000100
mCANRDSR2_DB3:      equ    %00001000
mCANRDSR2_DB4:      equ    %00010000
mCANRDSR2_DB5:      equ    %00100000
mCANRDSR2_DB6:      equ    %01000000
mCANRDSR2_DB7:      equ    %10000000


;*** CANRDSR3 - MSCAN Receive Data Segment Register 3; 0x000018A7 ***
CANRDSR3:           equ    $000018A7                                ;*** CANRDSR3 - MSCAN Receive Data Segment Register 3; 0x000018A7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR3_DB0:       equ    0                                         ; Data Bit 0
CANRDSR3_DB1:       equ    1                                         ; Data Bit 1
CANRDSR3_DB2:       equ    2                                         ; Data Bit 2
CANRDSR3_DB3:       equ    3                                         ; Data Bit 3
CANRDSR3_DB4:       equ    4                                         ; Data Bit 4
CANRDSR3_DB5:       equ    5                                         ; Data Bit 5
CANRDSR3_DB6:       equ    6                                         ; Data Bit 6
CANRDSR3_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR3_DB0:      equ    %00000001
mCANRDSR3_DB1:      equ    %00000010
mCANRDSR3_DB2:      equ    %00000100
mCANRDSR3_DB3:      equ    %00001000
mCANRDSR3_DB4:      equ    %00010000
mCANRDSR3_DB5:      equ    %00100000
mCANRDSR3_DB6:      equ    %01000000
mCANRDSR3_DB7:      equ    %10000000


;*** CANRDSR4 - MSCAN Receive Data Segment Register 4; 0x000018A8 ***
CANRDSR4:           equ    $000018A8                                ;*** CANRDSR4 - MSCAN Receive Data Segment Register 4; 0x000018A8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR4_DB0:       equ    0                                         ; Data Bit 0
CANRDSR4_DB1:       equ    1                                         ; Data Bit 1
CANRDSR4_DB2:       equ    2                                         ; Data Bit 2
CANRDSR4_DB3:       equ    3                                         ; Data Bit 3
CANRDSR4_DB4:       equ    4                                         ; Data Bit 4
CANRDSR4_DB5:       equ    5                                         ; Data Bit 5
CANRDSR4_DB6:       equ    6                                         ; Data Bit 6
CANRDSR4_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR4_DB0:      equ    %00000001
mCANRDSR4_DB1:      equ    %00000010
mCANRDSR4_DB2:      equ    %00000100
mCANRDSR4_DB3:      equ    %00001000
mCANRDSR4_DB4:      equ    %00010000
mCANRDSR4_DB5:      equ    %00100000
mCANRDSR4_DB6:      equ    %01000000
mCANRDSR4_DB7:      equ    %10000000


;*** CANRDSR5 - MSCAN Receive Data Segment Register 5; 0x000018A9 ***
CANRDSR5:           equ    $000018A9                                ;*** CANRDSR5 - MSCAN Receive Data Segment Register 5; 0x000018A9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR5_DB0:       equ    0                                         ; Data Bit 0
CANRDSR5_DB1:       equ    1                                         ; Data Bit 1
CANRDSR5_DB2:       equ    2                                         ; Data Bit 2
CANRDSR5_DB3:       equ    3                                         ; Data Bit 3
CANRDSR5_DB4:       equ    4                                         ; Data Bit 4
CANRDSR5_DB5:       equ    5                                         ; Data Bit 5
CANRDSR5_DB6:       equ    6                                         ; Data Bit 6
CANRDSR5_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR5_DB0:      equ    %00000001
mCANRDSR5_DB1:      equ    %00000010
mCANRDSR5_DB2:      equ    %00000100
mCANRDSR5_DB3:      equ    %00001000
mCANRDSR5_DB4:      equ    %00010000
mCANRDSR5_DB5:      equ    %00100000
mCANRDSR5_DB6:      equ    %01000000
mCANRDSR5_DB7:      equ    %10000000


;*** CANRDSR6 - MSCAN Receive Data Segment Register 6; 0x000018AA ***
CANRDSR6:           equ    $000018AA                                ;*** CANRDSR6 - MSCAN Receive Data Segment Register 6; 0x000018AA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR6_DB0:       equ    0                                         ; Data Bit 0
CANRDSR6_DB1:       equ    1                                         ; Data Bit 1
CANRDSR6_DB2:       equ    2                                         ; Data Bit 2
CANRDSR6_DB3:       equ    3                                         ; Data Bit 3
CANRDSR6_DB4:       equ    4                                         ; Data Bit 4
CANRDSR6_DB5:       equ    5                                         ; Data Bit 5
CANRDSR6_DB6:       equ    6                                         ; Data Bit 6
CANRDSR6_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR6_DB0:      equ    %00000001
mCANRDSR6_DB1:      equ    %00000010
mCANRDSR6_DB2:      equ    %00000100
mCANRDSR6_DB3:      equ    %00001000
mCANRDSR6_DB4:      equ    %00010000
mCANRDSR6_DB5:      equ    %00100000
mCANRDSR6_DB6:      equ    %01000000
mCANRDSR6_DB7:      equ    %10000000


;*** CANRDSR7 - MSCAN Receive Data Segment Register 7; 0x000018AB ***
CANRDSR7:           equ    $000018AB                                ;*** CANRDSR7 - MSCAN Receive Data Segment Register 7; 0x000018AB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR7_DB0:       equ    0                                         ; Data Bit 0
CANRDSR7_DB1:       equ    1                                         ; Data Bit 1
CANRDSR7_DB2:       equ    2                                         ; Data Bit 2
CANRDSR7_DB3:       equ    3                                         ; Data Bit 3
CANRDSR7_DB4:       equ    4                                         ; Data Bit 4
CANRDSR7_DB5:       equ    5                                         ; Data Bit 5
CANRDSR7_DB6:       equ    6                                         ; Data Bit 6
CANRDSR7_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANRDSR7_DB0:      equ    %00000001
mCANRDSR7_DB1:      equ    %00000010
mCANRDSR7_DB2:      equ    %00000100
mCANRDSR7_DB3:      equ    %00001000
mCANRDSR7_DB4:      equ    %00010000
mCANRDSR7_DB5:      equ    %00100000
mCANRDSR7_DB6:      equ    %01000000
mCANRDSR7_DB7:      equ    %10000000


;*** CANRDLR - MSCAN Receive Data Length Register; 0x000018AC ***
CANRDLR:            equ    $000018AC                                ;*** CANRDLR - MSCAN Receive Data Length Register; 0x000018AC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDLR_DLC0:       equ    0                                         ; Data Length Code Bit 0
CANRDLR_DLC1:       equ    1                                         ; Data Length Code Bit 1
CANRDLR_DLC2:       equ    2                                         ; Data Length Code Bit 2
CANRDLR_DLC3:       equ    3                                         ; Data Length Code Bit 3
; bit position masks
mCANRDLR_DLC0:      equ    %00000001
mCANRDLR_DLC1:      equ    %00000010
mCANRDLR_DLC2:      equ    %00000100
mCANRDLR_DLC3:      equ    %00001000


;*** CANRTSR - MSCAN Receive Time Stamp Register; 0x000018AE ***
CANRTSR:            equ    $000018AE                                ;*** CANRTSR - MSCAN Receive Time Stamp Register; 0x000018AE ***


;*** CANRTSRH - MSCAN Receive Time Stamp Register High; 0x000018AE ***
CANRTSRH:           equ    $000018AE                                ;*** CANRTSRH - MSCAN Receive Time Stamp Register High; 0x000018AE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRTSRH_TSR8:      equ    0                                         ; Time Stamp Bit 8
CANRTSRH_TSR9:      equ    1                                         ; Time Stamp Bit 9
CANRTSRH_TSR10:     equ    2                                         ; Time Stamp Bit 10
CANRTSRH_TSR11:     equ    3                                         ; Time Stamp Bit 11
CANRTSRH_TSR12:     equ    4                                         ; Time Stamp Bit 12
CANRTSRH_TSR13:     equ    5                                         ; Time Stamp Bit 13
CANRTSRH_TSR14:     equ    6                                         ; Time Stamp Bit 14
CANRTSRH_TSR15:     equ    7                                         ; Time Stamp Bit 15
; bit position masks
mCANRTSRH_TSR8:     equ    %00000001
mCANRTSRH_TSR9:     equ    %00000010
mCANRTSRH_TSR10:    equ    %00000100
mCANRTSRH_TSR11:    equ    %00001000
mCANRTSRH_TSR12:    equ    %00010000
mCANRTSRH_TSR13:    equ    %00100000
mCANRTSRH_TSR14:    equ    %01000000
mCANRTSRH_TSR15:    equ    %10000000


;*** CANRTSRL - MSCAN Receive Time Stamp Register Low; 0x000018AF ***
CANRTSRL:           equ    $000018AF                                ;*** CANRTSRL - MSCAN Receive Time Stamp Register Low; 0x000018AF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRTSRL_TSR0:      equ    0                                         ; Time Stamp Bit 0
CANRTSRL_TSR1:      equ    1                                         ; Time Stamp Bit 1
CANRTSRL_TSR2:      equ    2                                         ; Time Stamp Bit 2
CANRTSRL_TSR3:      equ    3                                         ; Time Stamp Bit 3
CANRTSRL_TSR4:      equ    4                                         ; Time Stamp Bit 4
CANRTSRL_TSR5:      equ    5                                         ; Time Stamp Bit 5
CANRTSRL_TSR6:      equ    6                                         ; Time Stamp Bit 6
CANRTSRL_TSR7:      equ    7                                         ; Time Stamp Bit 7
; bit position masks
mCANRTSRL_TSR0:     equ    %00000001
mCANRTSRL_TSR1:     equ    %00000010
mCANRTSRL_TSR2:     equ    %00000100
mCANRTSRL_TSR3:     equ    %00001000
mCANRTSRL_TSR4:     equ    %00010000
mCANRTSRL_TSR5:     equ    %00100000
mCANRTSRL_TSR6:     equ    %01000000
mCANRTSRL_TSR7:     equ    %10000000


;*** CANTIDR0 - MSCAN Transmit Identifier Register 0; 0x000018B0 ***
CANTIDR0:           equ    $000018B0                                ;*** CANTIDR0 - MSCAN Transmit Identifier Register 0; 0x000018B0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIDR0_ID3:       equ    0                                         ; Extended format identifier Bit 3
CANTIDR0_ID4:       equ    1                                         ; Extended format identifier Bit 4
CANTIDR0_ID5:       equ    2                                         ; Extended format identifier Bit 5
CANTIDR0_ID6:       equ    3                                         ; Extended format identifier Bit 6
CANTIDR0_ID7:       equ    4                                         ; Extended format identifier Bit 7
CANTIDR0_ID8:       equ    5                                         ; Extended format identifier Bit 8
CANTIDR0_ID9:       equ    6                                         ; Extended format identifier Bit 9
CANTIDR0_ID10:      equ    7                                         ; Extended format identifier Bit 10
; bit position masks
mCANTIDR0_ID3:      equ    %00000001
mCANTIDR0_ID4:      equ    %00000010
mCANTIDR0_ID5:      equ    %00000100
mCANTIDR0_ID6:      equ    %00001000
mCANTIDR0_ID7:      equ    %00010000
mCANTIDR0_ID8:      equ    %00100000
mCANTIDR0_ID9:      equ    %01000000
mCANTIDR0_ID10:     equ    %10000000


;*** CANTIDR1 - MSCAN Transmit Identifier Register 1; 0x000018B1 ***
CANTIDR1:           equ    $000018B1                                ;*** CANTIDR1 - MSCAN Transmit Identifier Register 1; 0x000018B1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIDR1_IDE:       equ    3                                         ; ID Extended
CANTIDR1_RTR:       equ    4                                         ; Remote Transmission Request
CANTIDR1_ID0:       equ    5                                         ; Extended format identifier Bit 0
CANTIDR1_ID1:       equ    6                                         ; Extended format identifier Bit 1
CANTIDR1_ID2:       equ    7                                         ; Extended format identifier Bit 2
; bit position masks
mCANTIDR1_IDE:      equ    %00001000
mCANTIDR1_RTR:      equ    %00010000
mCANTIDR1_ID0:      equ    %00100000
mCANTIDR1_ID1:      equ    %01000000
mCANTIDR1_ID2:      equ    %10000000


;*** CANTDSR0 - MSCAN Transmit Data Segment Register 0; 0x000018B4 ***
CANTDSR0:           equ    $000018B4                                ;*** CANTDSR0 - MSCAN Transmit Data Segment Register 0; 0x000018B4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR0_DB0:       equ    0                                         ; Data Bit 0
CANTDSR0_DB1:       equ    1                                         ; Data Bit 1
CANTDSR0_DB2:       equ    2                                         ; Data Bit 2
CANTDSR0_DB3:       equ    3                                         ; Data Bit 3
CANTDSR0_DB4:       equ    4                                         ; Data Bit 4
CANTDSR0_DB5:       equ    5                                         ; Data Bit 5
CANTDSR0_DB6:       equ    6                                         ; Data Bit 6
CANTDSR0_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR0_DB0:      equ    %00000001
mCANTDSR0_DB1:      equ    %00000010
mCANTDSR0_DB2:      equ    %00000100
mCANTDSR0_DB3:      equ    %00001000
mCANTDSR0_DB4:      equ    %00010000
mCANTDSR0_DB5:      equ    %00100000
mCANTDSR0_DB6:      equ    %01000000
mCANTDSR0_DB7:      equ    %10000000


;*** CANTDSR1 - MSCAN Transmit Data Segment Register 1; 0x000018B5 ***
CANTDSR1:           equ    $000018B5                                ;*** CANTDSR1 - MSCAN Transmit Data Segment Register 1; 0x000018B5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR1_DB0:       equ    0                                         ; Data Bit 0
CANTDSR1_DB1:       equ    1                                         ; Data Bit 1
CANTDSR1_DB2:       equ    2                                         ; Data Bit 2
CANTDSR1_DB3:       equ    3                                         ; Data Bit 3
CANTDSR1_DB4:       equ    4                                         ; Data Bit 4
CANTDSR1_DB5:       equ    5                                         ; Data Bit 5
CANTDSR1_DB6:       equ    6                                         ; Data Bit 6
CANTDSR1_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR1_DB0:      equ    %00000001
mCANTDSR1_DB1:      equ    %00000010
mCANTDSR1_DB2:      equ    %00000100
mCANTDSR1_DB3:      equ    %00001000
mCANTDSR1_DB4:      equ    %00010000
mCANTDSR1_DB5:      equ    %00100000
mCANTDSR1_DB6:      equ    %01000000
mCANTDSR1_DB7:      equ    %10000000


;*** CANTDSR2 - MSCAN Transmit Data Segment Register 2; 0x000018B6 ***
CANTDSR2:           equ    $000018B6                                ;*** CANTDSR2 - MSCAN Transmit Data Segment Register 2; 0x000018B6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR2_DB0:       equ    0                                         ; Data Bit 0
CANTDSR2_DB1:       equ    1                                         ; Data Bit 1
CANTDSR2_DB2:       equ    2                                         ; Data Bit 2
CANTDSR2_DB3:       equ    3                                         ; Data Bit 3
CANTDSR2_DB4:       equ    4                                         ; Data Bit 4
CANTDSR2_DB5:       equ    5                                         ; Data Bit 5
CANTDSR2_DB6:       equ    6                                         ; Data Bit 6
CANTDSR2_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR2_DB0:      equ    %00000001
mCANTDSR2_DB1:      equ    %00000010
mCANTDSR2_DB2:      equ    %00000100
mCANTDSR2_DB3:      equ    %00001000
mCANTDSR2_DB4:      equ    %00010000
mCANTDSR2_DB5:      equ    %00100000
mCANTDSR2_DB6:      equ    %01000000
mCANTDSR2_DB7:      equ    %10000000


;*** CANTDSR3 - MSCAN Transmit Data Segment Register 3; 0x000018B7 ***
CANTDSR3:           equ    $000018B7                                ;*** CANTDSR3 - MSCAN Transmit Data Segment Register 3; 0x000018B7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR3_DB0:       equ    0                                         ; Data Bit 0
CANTDSR3_DB1:       equ    1                                         ; Data Bit 1
CANTDSR3_DB2:       equ    2                                         ; Data Bit 2
CANTDSR3_DB3:       equ    3                                         ; Data Bit 3
CANTDSR3_DB4:       equ    4                                         ; Data Bit 4
CANTDSR3_DB5:       equ    5                                         ; Data Bit 5
CANTDSR3_DB6:       equ    6                                         ; Data Bit 6
CANTDSR3_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR3_DB0:      equ    %00000001
mCANTDSR3_DB1:      equ    %00000010
mCANTDSR3_DB2:      equ    %00000100
mCANTDSR3_DB3:      equ    %00001000
mCANTDSR3_DB4:      equ    %00010000
mCANTDSR3_DB5:      equ    %00100000
mCANTDSR3_DB6:      equ    %01000000
mCANTDSR3_DB7:      equ    %10000000


;*** CANTDSR4 - MSCAN Transmit Data Segment Register 4; 0x000018B8 ***
CANTDSR4:           equ    $000018B8                                ;*** CANTDSR4 - MSCAN Transmit Data Segment Register 4; 0x000018B8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR4_DB0:       equ    0                                         ; Data Bit 0
CANTDSR4_DB1:       equ    1                                         ; Data Bit 1
CANTDSR4_DB2:       equ    2                                         ; Data Bit 2
CANTDSR4_DB3:       equ    3                                         ; Data Bit 3
CANTDSR4_DB4:       equ    4                                         ; Data Bit 4
CANTDSR4_DB5:       equ    5                                         ; Data Bit 5
CANTDSR4_DB6:       equ    6                                         ; Data Bit 6
CANTDSR4_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR4_DB0:      equ    %00000001
mCANTDSR4_DB1:      equ    %00000010
mCANTDSR4_DB2:      equ    %00000100
mCANTDSR4_DB3:      equ    %00001000
mCANTDSR4_DB4:      equ    %00010000
mCANTDSR4_DB5:      equ    %00100000
mCANTDSR4_DB6:      equ    %01000000
mCANTDSR4_DB7:      equ    %10000000


;*** CANTDSR5 - MSCAN Transmit Data Segment Register 5; 0x000018B9 ***
CANTDSR5:           equ    $000018B9                                ;*** CANTDSR5 - MSCAN Transmit Data Segment Register 5; 0x000018B9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR5_DB0:       equ    0                                         ; Data Bit 0
CANTDSR5_DB1:       equ    1                                         ; Data Bit 1
CANTDSR5_DB2:       equ    2                                         ; Data Bit 2
CANTDSR5_DB3:       equ    3                                         ; Data Bit 3
CANTDSR5_DB4:       equ    4                                         ; Data Bit 4
CANTDSR5_DB5:       equ    5                                         ; Data Bit 5
CANTDSR5_DB6:       equ    6                                         ; Data Bit 6
CANTDSR5_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR5_DB0:      equ    %00000001
mCANTDSR5_DB1:      equ    %00000010
mCANTDSR5_DB2:      equ    %00000100
mCANTDSR5_DB3:      equ    %00001000
mCANTDSR5_DB4:      equ    %00010000
mCANTDSR5_DB5:      equ    %00100000
mCANTDSR5_DB6:      equ    %01000000
mCANTDSR5_DB7:      equ    %10000000


;*** CANTDSR6 - MSCAN Transmit Data Segment Register 6; 0x000018BA ***
CANTDSR6:           equ    $000018BA                                ;*** CANTDSR6 - MSCAN Transmit Data Segment Register 6; 0x000018BA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR6_DB0:       equ    0                                         ; Data Bit 0
CANTDSR6_DB1:       equ    1                                         ; Data Bit 1
CANTDSR6_DB2:       equ    2                                         ; Data Bit 2
CANTDSR6_DB3:       equ    3                                         ; Data Bit 3
CANTDSR6_DB4:       equ    4                                         ; Data Bit 4
CANTDSR6_DB5:       equ    5                                         ; Data Bit 5
CANTDSR6_DB6:       equ    6                                         ; Data Bit 6
CANTDSR6_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR6_DB0:      equ    %00000001
mCANTDSR6_DB1:      equ    %00000010
mCANTDSR6_DB2:      equ    %00000100
mCANTDSR6_DB3:      equ    %00001000
mCANTDSR6_DB4:      equ    %00010000
mCANTDSR6_DB5:      equ    %00100000
mCANTDSR6_DB6:      equ    %01000000
mCANTDSR6_DB7:      equ    %10000000


;*** CANTDSR7 - MSCAN Transmit Data Segment Register 7; 0x000018BB ***
CANTDSR7:           equ    $000018BB                                ;*** CANTDSR7 - MSCAN Transmit Data Segment Register 7; 0x000018BB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR7_DB0:       equ    0                                         ; Data Bit 0
CANTDSR7_DB1:       equ    1                                         ; Data Bit 1
CANTDSR7_DB2:       equ    2                                         ; Data Bit 2
CANTDSR7_DB3:       equ    3                                         ; Data Bit 3
CANTDSR7_DB4:       equ    4                                         ; Data Bit 4
CANTDSR7_DB5:       equ    5                                         ; Data Bit 5
CANTDSR7_DB6:       equ    6                                         ; Data Bit 6
CANTDSR7_DB7:       equ    7                                         ; Data Bit 7
; bit position masks
mCANTDSR7_DB0:      equ    %00000001
mCANTDSR7_DB1:      equ    %00000010
mCANTDSR7_DB2:      equ    %00000100
mCANTDSR7_DB3:      equ    %00001000
mCANTDSR7_DB4:      equ    %00010000
mCANTDSR7_DB5:      equ    %00100000
mCANTDSR7_DB6:      equ    %01000000
mCANTDSR7_DB7:      equ    %10000000


;*** CANTDLR - MSCAN Transmit Data Length Register; 0x000018BC ***
CANTDLR:            equ    $000018BC                                ;*** CANTDLR - MSCAN Transmit Data Length Register; 0x000018BC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDLR_DLC0:       equ    0                                         ; Data Length Code Bit 0
CANTDLR_DLC1:       equ    1                                         ; Data Length Code Bit 1
CANTDLR_DLC2:       equ    2                                         ; Data Length Code Bit 2
CANTDLR_DLC3:       equ    3                                         ; Data Length Code Bit 3
; bit position masks
mCANTDLR_DLC0:      equ    %00000001
mCANTDLR_DLC1:      equ    %00000010
mCANTDLR_DLC2:      equ    %00000100
mCANTDLR_DLC3:      equ    %00001000


;*** CANTTBPR - MSCAN Transmit Buffer Priority; 0x000018BD ***
CANTTBPR:           equ    $000018BD                                ;*** CANTTBPR - MSCAN Transmit Buffer Priority; 0x000018BD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTTBPR_PRIO0:     equ    0                                         ; Transmit Buffer Priority Bit 0
CANTTBPR_PRIO1:     equ    1                                         ; Transmit Buffer Priority Bit 1
CANTTBPR_PRIO2:     equ    2                                         ; Transmit Buffer Priority Bit 2
CANTTBPR_PRIO3:     equ    3                                         ; Transmit Buffer Priority Bit 3
CANTTBPR_PRIO4:     equ    4                                         ; Transmit Buffer Priority Bit 4
CANTTBPR_PRIO5:     equ    5                                         ; Transmit Buffer Priority Bit 5
CANTTBPR_PRIO6:     equ    6                                         ; Transmit Buffer Priority Bit 6
CANTTBPR_PRIO7:     equ    7                                         ; Transmit Buffer Priority Bit 7
; bit position masks
mCANTTBPR_PRIO0:    equ    %00000001
mCANTTBPR_PRIO1:    equ    %00000010
mCANTTBPR_PRIO2:    equ    %00000100
mCANTTBPR_PRIO3:    equ    %00001000
mCANTTBPR_PRIO4:    equ    %00010000
mCANTTBPR_PRIO5:    equ    %00100000
mCANTTBPR_PRIO6:    equ    %01000000
mCANTTBPR_PRIO7:    equ    %10000000


;*** CANTTSR - MSCAN Transmit Time Stamp Register; 0x000018BE ***
CANTTSR:            equ    $000018BE                                ;*** CANTTSR - MSCAN Transmit Time Stamp Register; 0x000018BE ***


;*** CANTTSRH - MSCAN Transmit Time Stamp Register High; 0x000018BE ***
CANTTSRH:           equ    $000018BE                                ;*** CANTTSRH - MSCAN Transmit Time Stamp Register High; 0x000018BE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTTSRH_TSR8:      equ    0                                         ; Time Stamp Bit 8
CANTTSRH_TSR9:      equ    1                                         ; Time Stamp Bit 9
CANTTSRH_TSR10:     equ    2                                         ; Time Stamp Bit 10
CANTTSRH_TSR11:     equ    3                                         ; Time Stamp Bit 11
CANTTSRH_TSR12:     equ    4                                         ; Time Stamp Bit 12
CANTTSRH_TSR13:     equ    5                                         ; Time Stamp Bit 13
CANTTSRH_TSR14:     equ    6                                         ; Time Stamp Bit 14
CANTTSRH_TSR15:     equ    7                                         ; Time Stamp Bit 15
; bit position masks
mCANTTSRH_TSR8:     equ    %00000001
mCANTTSRH_TSR9:     equ    %00000010
mCANTTSRH_TSR10:    equ    %00000100
mCANTTSRH_TSR11:    equ    %00001000
mCANTTSRH_TSR12:    equ    %00010000
mCANTTSRH_TSR13:    equ    %00100000
mCANTTSRH_TSR14:    equ    %01000000
mCANTTSRH_TSR15:    equ    %10000000


;*** CANTTSRL - MSCAN Transmit Time Stamp Register Low; 0x000018BF ***
CANTTSRL:           equ    $000018BF                                ;*** CANTTSRL - MSCAN Transmit Time Stamp Register Low; 0x000018BF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTTSRL_TSR0:      equ    0                                         ; Time Stamp Bit 0
CANTTSRL_TSR1:      equ    1                                         ; Time Stamp Bit 1
CANTTSRL_TSR2:      equ    2                                         ; Time Stamp Bit 2
CANTTSRL_TSR3:      equ    3                                         ; Time Stamp Bit 3
CANTTSRL_TSR4:      equ    4                                         ; Time Stamp Bit 4
CANTTSRL_TSR5:      equ    5                                         ; Time Stamp Bit 5
CANTTSRL_TSR6:      equ    6                                         ; Time Stamp Bit 6
CANTTSRL_TSR7:      equ    7                                         ; Time Stamp Bit 7
; bit position masks
mCANTTSRL_TSR0:     equ    %00000001
mCANTTSRL_TSR1:     equ    %00000010
mCANTTSRL_TSR2:     equ    %00000100
mCANTTSRL_TSR3:     equ    %00001000
mCANTTSRL_TSR4:     equ    %00010000
mCANTTSRL_TSR5:     equ    %00100000
mCANTTSRL_TSR6:     equ    %01000000
mCANTTSRL_TSR7:     equ    %10000000


;*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***
NVBACKKEY0:         equ    $0000FFB0                                ;*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY0_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY0_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY0_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY0_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY0_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY0_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY0_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY0_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY0_KEY0:   equ    %00000001
mNVBACKKEY0_KEY1:   equ    %00000010
mNVBACKKEY0_KEY2:   equ    %00000100
mNVBACKKEY0_KEY3:   equ    %00001000
mNVBACKKEY0_KEY4:   equ    %00010000
mNVBACKKEY0_KEY5:   equ    %00100000
mNVBACKKEY0_KEY6:   equ    %01000000
mNVBACKKEY0_KEY7:   equ    %10000000


;*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***
NVBACKKEY1:         equ    $0000FFB1                                ;*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY1_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY1_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY1_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY1_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY1_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY1_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY1_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY1_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY1_KEY0:   equ    %00000001
mNVBACKKEY1_KEY1:   equ    %00000010
mNVBACKKEY1_KEY2:   equ    %00000100
mNVBACKKEY1_KEY3:   equ    %00001000
mNVBACKKEY1_KEY4:   equ    %00010000
mNVBACKKEY1_KEY5:   equ    %00100000
mNVBACKKEY1_KEY6:   equ    %01000000
mNVBACKKEY1_KEY7:   equ    %10000000


;*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***
NVBACKKEY2:         equ    $0000FFB2                                ;*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY2_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY2_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY2_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY2_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY2_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY2_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY2_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY2_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY2_KEY0:   equ    %00000001
mNVBACKKEY2_KEY1:   equ    %00000010
mNVBACKKEY2_KEY2:   equ    %00000100
mNVBACKKEY2_KEY3:   equ    %00001000
mNVBACKKEY2_KEY4:   equ    %00010000
mNVBACKKEY2_KEY5:   equ    %00100000
mNVBACKKEY2_KEY6:   equ    %01000000
mNVBACKKEY2_KEY7:   equ    %10000000


;*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***
NVBACKKEY3:         equ    $0000FFB3                                ;*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY3_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY3_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY3_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY3_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY3_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY3_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY3_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY3_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY3_KEY0:   equ    %00000001
mNVBACKKEY3_KEY1:   equ    %00000010
mNVBACKKEY3_KEY2:   equ    %00000100
mNVBACKKEY3_KEY3:   equ    %00001000
mNVBACKKEY3_KEY4:   equ    %00010000
mNVBACKKEY3_KEY5:   equ    %00100000
mNVBACKKEY3_KEY6:   equ    %01000000
mNVBACKKEY3_KEY7:   equ    %10000000


;*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***
NVBACKKEY4:         equ    $0000FFB4                                ;*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY4_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY4_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY4_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY4_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY4_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY4_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY4_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY4_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY4_KEY0:   equ    %00000001
mNVBACKKEY4_KEY1:   equ    %00000010
mNVBACKKEY4_KEY2:   equ    %00000100
mNVBACKKEY4_KEY3:   equ    %00001000
mNVBACKKEY4_KEY4:   equ    %00010000
mNVBACKKEY4_KEY5:   equ    %00100000
mNVBACKKEY4_KEY6:   equ    %01000000
mNVBACKKEY4_KEY7:   equ    %10000000


;*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***
NVBACKKEY5:         equ    $0000FFB5                                ;*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY5_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY5_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY5_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY5_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY5_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY5_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY5_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY5_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY5_KEY0:   equ    %00000001
mNVBACKKEY5_KEY1:   equ    %00000010
mNVBACKKEY5_KEY2:   equ    %00000100
mNVBACKKEY5_KEY3:   equ    %00001000
mNVBACKKEY5_KEY4:   equ    %00010000
mNVBACKKEY5_KEY5:   equ    %00100000
mNVBACKKEY5_KEY6:   equ    %01000000
mNVBACKKEY5_KEY7:   equ    %10000000


;*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***
NVBACKKEY6:         equ    $0000FFB6                                ;*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY6_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY6_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY6_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY6_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY6_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY6_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY6_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY6_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY6_KEY0:   equ    %00000001
mNVBACKKEY6_KEY1:   equ    %00000010
mNVBACKKEY6_KEY2:   equ    %00000100
mNVBACKKEY6_KEY3:   equ    %00001000
mNVBACKKEY6_KEY4:   equ    %00010000
mNVBACKKEY6_KEY5:   equ    %00100000
mNVBACKKEY6_KEY6:   equ    %01000000
mNVBACKKEY6_KEY7:   equ    %10000000


;*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***
NVBACKKEY7:         equ    $0000FFB7                                ;*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY7_KEY0:    equ    0                                         ; Backdoor Comparison Key bits, bit 0
NVBACKKEY7_KEY1:    equ    1                                         ; Backdoor Comparison Key bits, bit 1
NVBACKKEY7_KEY2:    equ    2                                         ; Backdoor Comparison Key bits, bit 2
NVBACKKEY7_KEY3:    equ    3                                         ; Backdoor Comparison Key bits, bit 3
NVBACKKEY7_KEY4:    equ    4                                         ; Backdoor Comparison Key bits, bit 4
NVBACKKEY7_KEY5:    equ    5                                         ; Backdoor Comparison Key bits, bit 5
NVBACKKEY7_KEY6:    equ    6                                         ; Backdoor Comparison Key bits, bit 6
NVBACKKEY7_KEY7:    equ    7                                         ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY7_KEY0:   equ    %00000001
mNVBACKKEY7_KEY1:   equ    %00000010
mNVBACKKEY7_KEY2:   equ    %00000100
mNVBACKKEY7_KEY3:   equ    %00001000
mNVBACKKEY7_KEY4:   equ    %00010000
mNVBACKKEY7_KEY5:   equ    %00100000
mNVBACKKEY7_KEY6:   equ    %01000000
mNVBACKKEY7_KEY7:   equ    %10000000


;*** NVECC - Nonvolatile Error Correction Code Enable Register; 0x0000FFB8 ***
NVECC:              equ    $0000FFB8                                ;*** NVECC - Nonvolatile Error Correction Code Enable Register; 0x0000FFB8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVECC_ECC0:         equ    0                                         ; Error Correction Code Enable Bit 0
NVECC_ECC1:         equ    1                                         ; Error Correction Code Enable Bit 1
NVECC_ECC2:         equ    2                                         ; Error Correction Code Enable Bit 2
NVECC_ECC3:         equ    3                                         ; Error Correction Code Enable Bit 3
NVECC_ECC4:         equ    4                                         ; Error Correction Code Enable Bit 4
NVECC_ECC5:         equ    5                                         ; Error Correction Code Enable Bit 5
NVECC_ECC6:         equ    6                                         ; Error Correction Code Enable Bit 6
NVECC_ECC7:         equ    7                                         ; Error Correction Code Enable Bit 7
; bit position masks
mNVECC_ECC0:        equ    %00000001
mNVECC_ECC1:        equ    %00000010
mNVECC_ECC2:        equ    %00000100
mNVECC_ECC3:        equ    %00001000
mNVECC_ECC4:        equ    %00010000
mNVECC_ECC5:        equ    %00100000
mNVECC_ECC6:        equ    %01000000
mNVECC_ECC7:        equ    %10000000

  IF 0	    ; undefined for purpose of bootloader

;*** NVPROT - Nonvolatile FLASH and EEPROM Protection Register; 0x0000FFBD ***
NVPROT:             equ    $0000FFBD                                ;*** NVPROT - Nonvolatile FLASH and EEPROM Protection Register; 0x0000FFBD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVPROT_FPS0:        equ    0                                         ; FLASH Protect Select Bits, bit 0
NVPROT_FPS1:        equ    1                                         ; FLASH Protect Select Bits, bit 1
NVPROT_FPS2:        equ    2                                         ; FLASH Protect Select Bits, bit 2
NVPROT_FPS3:        equ    3                                         ; FLASH Protect Select Bits, bit 3
NVPROT_FPS4:        equ    4                                         ; FLASH Protect Select Bits, bit 4
NVPROT_FPS5:        equ    5                                         ; FLASH Protect Select Bits, bit 5
NVPROT_EPS0:        equ    6                                         ; EEPROM Protect Select Bits, bit 0
NVPROT_EPS1:        equ    7                                         ; EEPROM Protect Select Bits, bit 1
; bit position masks
mNVPROT_FPS0:       equ    %00000001
mNVPROT_FPS1:       equ    %00000010
mNVPROT_FPS2:       equ    %00000100
mNVPROT_FPS3:       equ    %00001000
mNVPROT_FPS4:       equ    %00010000
mNVPROT_FPS5:       equ    %00100000
mNVPROT_EPS0:       equ    %01000000
mNVPROT_EPS1:       equ    %10000000


;*** NVOPT - Nonvolatile FLASH and EEPROM Options Register; 0x0000FFBF ***
NVOPT:              equ    $0000FFBF                                ;*** NVOPT - Nonvolatile FLASH and EEPROM Options Register; 0x0000FFBF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC0:         equ    0                                         ; Security State Code Bit 0
NVOPT_SEC1:         equ    1                                         ; Security State Code Bit 1
NVOPT_EPGMOD:       equ    5                                         ; EEPROM Sector Mode
NVOPT_FNORED:       equ    6                                         ; Vector Redirection Disable
NVOPT_KEYEN:        equ    7                                         ; Backdoor Key Mechanism Enable
; bit position masks
mNVOPT_SEC0:        equ    %00000001
mNVOPT_SEC1:        equ    %00000010
mNVOPT_EPGMOD:      equ    %00100000
mNVOPT_FNORED:      equ    %01000000
mNVOPT_KEYEN:       equ    %10000000

  ENDIF
  
  ; command codes
mBlank:     equ   $05         ;Blank Check command
mByteProg:  equ   $20         ;Byte Program command
mBurstProg: equ   $25         ;Burst Program command
mPageErase: equ   $40         ;Page Erase command
mMassErase: equ   $41         ;Mass Erase command

;*** NV_FTRIM - Nonvolatile ICS Fine Trim Register; 0x0000FFAE ***
NV_FTRIM:           equ    $0000FFAE                                ;*** NV_FTRIM - Nonvolatile ICS Fine Trim Register; 0x0000FFAE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FTRIM_FTRIM:     equ    0                                         ; ICS Fine Trim
; bit position masks
mNV_FTRIM_FTRIM:    equ    %00000001

;*** NV_ICSTRM - Nonvolatile ICS Trim Register; 0x0000FFAF ***
NV_ICSTRM:          equ    $0000FFAF                                ;*** NV_ICSTRM - Nonvolatile ICS Trim Register; 0x0000FFAF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_ICSTRM_TRIM0:    equ    0                                         ; ICS Trim Setting, bit 0
NV_ICSTRM_TRIM1:    equ    1                                         ; ICS Trim Setting, bit 1
NV_ICSTRM_TRIM2:    equ    2                                         ; ICS Trim Setting, bit 2
NV_ICSTRM_TRIM3:    equ    3                                         ; ICS Trim Setting, bit 3
NV_ICSTRM_TRIM4:    equ    4                                         ; ICS Trim Setting, bit 4
NV_ICSTRM_TRIM5:    equ    5                                         ; ICS Trim Setting, bit 5
NV_ICSTRM_TRIM6:    equ    6                                         ; ICS Trim Setting, bit 6
NV_ICSTRM_TRIM7:    equ    7                                         ; ICS Trim Setting, bit 7
; bit position masks
mNV_ICSTRM_TRIM0:   equ    %00000001
mNV_ICSTRM_TRIM1:   equ    %00000010
mNV_ICSTRM_TRIM2:   equ    %00000100
mNV_ICSTRM_TRIM3:   equ    %00001000
mNV_ICSTRM_TRIM4:   equ    %00010000
mNV_ICSTRM_TRIM5:   equ    %00100000
mNV_ICSTRM_TRIM6:   equ    %01000000
mNV_ICSTRM_TRIM7:   equ    %10000000


; EOF
