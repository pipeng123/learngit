; Based on CPU DB MC9S08RG60, version 2.87.009 (RegistersPrg V1.061)

; ###################################################################
;     Filename  : MC9S08RG60.h
;     Processor : MC9S08RG60
;     FileFormat: V1.061
;     DataSheet : MC9S08RG60/D Rev. 1.07, 2/2004
;     Compiler  : Metrowerks C compiler
;     Date/Time : 08.04.2004, 09:14
;     Abstract  :
;         This implements an IO devices mapping.
;
;     (c) Copyright UNIS, spol. s r.o. 1997-2003
;     UNIS, spol. s r.o.
;     Jundrovska 33
;     624 00 Brno
;     Czech Republic
;     http      : www.processorexpert.com
;     mail      : info@processorexpert.com
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
; Commented out for V3.0 SP; Creates conflicts with asm source file stub: ROMStart:           equ   $0000182C
ROMEnd:             equ   $0000FFBF
Z_RAMStart:         equ   $00000046
Z_RAMEnd:           equ   $000000FF
; Commented out for V3.0 SP; Creates conflicts with asm source file stub: RAMStart:           equ   $00000100
RAMEnd:             equ   $00000845
ROM1Start:          equ   $00000846
ROM1End:            equ   $000017FF
;
Vspi1:              equ   $0000FFE0
Vrti:               equ   $0000FFE2
Vkeyboard2:         equ   $0000FFE4
Vkeyboard1:         equ   $0000FFE6
Vacmp1:             equ   $0000FFE8
Vcmt:               equ   $0000FFEA
Vsci1tx:            equ   $0000FFEC
Vsci1rx:            equ   $0000FFEE
Vsci1err:           equ   $0000FFF0
Vtpm1ovf:           equ   $0000FFF2
Vtpm1ch1:           equ   $0000FFF4
Vtpm1ch0:           equ   $0000FFF6
Virq:               equ   $0000FFF8
Vlvd:               equ   $0000FFFA
Vswi:               equ   $0000FFFC
Vreset:             equ   $0000FFFE
;
;*** PTAD - Port A Data Register; 0x00000000 ***
PTAD:               equ    $00000000                                ;*** PTAD - Port A Data Register; 0x00000000 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTAPE - Pullup Enable for Port; 0x00000001 ***
PTAPE:              equ    $00000001                                ;*** PTAPE - Pullup Enable for Port; 0x00000001 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTADD - Data Direction Register A; 0x00000003 ***
PTADD:              equ    $00000003                                ;*** PTADD - Data Direction Register A; 0x00000003 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTBD - Port B Data Register; 0x00000004 ***
PTBD:               equ    $00000004                                ;*** PTBD - Port B Data Register; 0x00000004 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTBPE - Pullup Enable for Port B; 0x00000005 ***
PTBPE:              equ    $00000005                                ;*** PTBPE - Pullup Enable for Port B; 0x00000005 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTBDD - Data Direction Register B; 0x00000007 ***
PTBDD:              equ    $00000007                                ;*** PTBDD - Data Direction Register B; 0x00000007 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTCD - Port C Data Register; 0x00000008 ***
PTCD:               equ    $00000008                                ;*** PTCD - Port C Data Register; 0x00000008 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTCPE - Pullup Enable for Port C; 0x00000009 ***
PTCPE:              equ    $00000009                                ;*** PTCPE - Pullup Enable for Port C; 0x00000009 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTCDD - Data Direction Register C; 0x0000000B ***
PTCDD:              equ    $0000000B                                ;*** PTCDD - Data Direction Register C; 0x0000000B ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTDD - Port D Data Register; 0x0000000C ***
PTDD:               equ    $0000000C                                ;*** PTDD - Port D Data Register; 0x0000000C ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
PTDD_PTDD0:         equ    0                                         ; Port D Data Register Bit 0
PTDD_PTDD1:         equ    1                                         ; Port D Data Register Bit 1
PTDD_PTDD2:         equ    2                                         ; Port D Data Register Bit 2
PTDD_PTDD3:         equ    3                                         ; Port D Data Register Bit 3
PTDD_PTDD4:         equ    4                                         ; Port D Data Register Bit 4
PTDD_PTDD5:         equ    5                                         ; Port D Data Register Bit 5
PTDD_PTDD6:         equ    6                                         ; Port D Data Register Bit 6
; bit position masks
mPTDD_PTDD0:        equ    %00000001
mPTDD_PTDD1:        equ    %00000010
mPTDD_PTDD2:        equ    %00000100
mPTDD_PTDD3:        equ    %00001000
mPTDD_PTDD4:        equ    %00010000
mPTDD_PTDD5:        equ    %00100000
mPTDD_PTDD6:        equ    %01000000


;*** PTDPE - Pullup Enable for Port D; 0x0000000D ***
PTDPE:              equ    $0000000D                                ;*** PTDPE - Pullup Enable for Port D; 0x0000000D ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0:       equ    0                                         ; Pullup Enable for Port D Bit 0
PTDPE_PTDPE1:       equ    1                                         ; Pullup Enable for Port D Bit 1
PTDPE_PTDPE2:       equ    2                                         ; Pullup Enable for Port D Bit 2
PTDPE_PTDPE3:       equ    3                                         ; Pullup Enable for Port D Bit 3
PTDPE_PTDPE4:       equ    4                                         ; Pullup Enable for Port D Bit 4
PTDPE_PTDPE5:       equ    5                                         ; Pullup Enable for Port D Bit 5
PTDPE_PTDPE6:       equ    6                                         ; Pullup Enable for Port D Bit 6
; bit position masks
mPTDPE_PTDPE0:      equ    %00000001
mPTDPE_PTDPE1:      equ    %00000010
mPTDPE_PTDPE2:      equ    %00000100
mPTDPE_PTDPE3:      equ    %00001000
mPTDPE_PTDPE4:      equ    %00010000
mPTDPE_PTDPE5:      equ    %00100000
mPTDPE_PTDPE6:      equ    %01000000


;*** PTDDD - Data Direction Register D; 0x0000000F ***
PTDDD:              equ    $0000000F                                ;*** PTDDD - Data Direction Register D; 0x0000000F ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0:       equ    0                                         ; Data Direction for Port D Bit 0
PTDDD_PTDDD1:       equ    1                                         ; Data Direction for Port D Bit 1
PTDDD_PTDDD2:       equ    2                                         ; Data Direction for Port D Bit 2
PTDDD_PTDDD3:       equ    3                                         ; Data Direction for Port D Bit 3
PTDDD_PTDDD4:       equ    4                                         ; Data Direction for Port D Bit 4
PTDDD_PTDDD5:       equ    5                                         ; Data Direction for Port D Bit 5
PTDDD_PTDDD6:       equ    6                                         ; Data Direction for Port D Bit 6
; bit position masks
mPTDDD_PTDDD0:      equ    %00000001
mPTDDD_PTDDD1:      equ    %00000010
mPTDDD_PTDDD2:      equ    %00000100
mPTDDD_PTDDD3:      equ    %00001000
mPTDDD_PTDDD4:      equ    %00010000
mPTDDD_PTDDD5:      equ    %00100000
mPTDDD_PTDDD6:      equ    %01000000


;*** PTED - Port E Data Register; 0x00000010 ***
PTED:               equ    $00000010                                ;*** PTED - Port E Data Register; 0x00000010 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTEPE - Pullup Enable for Port E; 0x00000011 ***
PTEPE:              equ    $00000011                                ;*** PTEPE - Pullup Enable for Port E; 0x00000011 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** PTEDD - Data Direction Register E; 0x00000013 ***
PTEDD:              equ    $00000013                                ;*** PTEDD - Data Direction Register E; 0x00000013 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** KBI1SC - KBI1 Status and Control; 0x00000014 ***
KBI1SC:             equ    $00000014                                ;*** KBI1SC - KBI1 Status and Control; 0x00000014 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
KBI1SC_KBIMOD:      equ    0                                         ; Keyboard Detection Mode
KBI1SC_KBIE:        equ    1                                         ; Keyboard Interrupt Enable
KBI1SC_KBACK:       equ    2                                         ; Keyboard Interrupt Acknowledge
KBI1SC_KBF:         equ    3                                         ; Keyboard Interrupt Flag
KBI1SC_KBEDG4:      equ    4                                         ; Keyboard Edge Select for Port A Bit 4
KBI1SC_KBEDG5:      equ    5                                         ; Keyboard Edge Select for Port A Bit 5
KBI1SC_KBEDG6:      equ    6                                         ; Keyboard Edge Select for Port A Bit 6
KBI1SC_KBEDG7:      equ    7                                         ; Keyboard Edge Select for Port A Bit 7
; bit position masks
mKBI1SC_KBIMOD:     equ    %00000001
mKBI1SC_KBIE:       equ    %00000010
mKBI1SC_KBACK:      equ    %00000100
mKBI1SC_KBF:        equ    %00001000
mKBI1SC_KBEDG4:     equ    %00010000
mKBI1SC_KBEDG5:     equ    %00100000
mKBI1SC_KBEDG6:     equ    %01000000
mKBI1SC_KBEDG7:     equ    %10000000


;*** KBI1PE - KBI1 Pin Enable Register; 0x00000015 ***
KBI1PE:             equ    $00000015                                ;*** KBI1PE - KBI1 Pin Enable Register; 0x00000015 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
KBI1PE_KBIPE0:      equ    0                                         ; Keyboard Pin Enable for Port A Bit 0
KBI1PE_KBIPE1:      equ    1                                         ; Keyboard Pin Enable for Port A Bit 1
KBI1PE_KBIPE2:      equ    2                                         ; Keyboard Pin Enable for Port A Bit 2
KBI1PE_KBIPE3:      equ    3                                         ; Keyboard Pin Enable for Port A Bit 3
KBI1PE_KBIPE4:      equ    4                                         ; Keyboard Pin Enable for Port A Bit 4
KBI1PE_KBIPE5:      equ    5                                         ; Keyboard Pin Enable for Port A Bit 5
KBI1PE_KBIPE6:      equ    6                                         ; Keyboard Pin Enable for Port A Bit 6
KBI1PE_KBIPE7:      equ    7                                         ; Keyboard Pin Enable for Port A Bit 7
; bit position masks
mKBI1PE_KBIPE0:     equ    %00000001
mKBI1PE_KBIPE1:     equ    %00000010
mKBI1PE_KBIPE2:     equ    %00000100
mKBI1PE_KBIPE3:     equ    %00001000
mKBI1PE_KBIPE4:     equ    %00010000
mKBI1PE_KBIPE5:     equ    %00100000
mKBI1PE_KBIPE6:     equ    %01000000
mKBI1PE_KBIPE7:     equ    %10000000


;*** KBI2SC - KBI2 Status and Control; 0x00000016 ***
KBI2SC:             equ    $00000016                                ;*** KBI2SC - KBI2 Status and Control; 0x00000016 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
KBI2SC_KBIMOD:      equ    0                                         ; Keyboard Detection Mode
KBI2SC_KBIE:        equ    1                                         ; Keyboard Interrupt Enable
KBI2SC_KBACK:       equ    2                                         ; Keyboard Interrupt Acknowledge
KBI2SC_KBF:         equ    3                                         ; Keyboard Interrupt Flag
; bit position masks
mKBI2SC_KBIMOD:     equ    %00000001
mKBI2SC_KBIE:       equ    %00000010
mKBI2SC_KBACK:      equ    %00000100
mKBI2SC_KBF:        equ    %00001000


;*** KBI2PE - KBI2 Pin Enable Register; 0x00000017 ***
KBI2PE:             equ    $00000017                                ;*** KBI2PE - KBI2 Pin Enable Register; 0x00000017 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
KBI2PE_KBIPE0:      equ    0                                         ; Keyboard Pin Enable for Port C Bit 0
KBI2PE_KBIPE1:      equ    1                                         ; Keyboard Pin Enable for Port C Bit 1
KBI2PE_KBIPE2:      equ    2                                         ; Keyboard Pin Enable for Port C Bit 2
KBI2PE_KBIPE3:      equ    3                                         ; Keyboard Pin Enable for Port C Bit 3
; bit position masks
mKBI2PE_KBIPE0:     equ    %00000001
mKBI2PE_KBIPE1:     equ    %00000010
mKBI2PE_KBIPE2:     equ    %00000100
mKBI2PE_KBIPE3:     equ    %00001000


;*** SCI1BD - SCI1 Baud Rate Register; 0x00000018 ***
SCI1BD:             equ    $00000018                                ;*** SCI1BD - SCI1 Baud Rate Register; 0x00000018 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SCI1BD_SBR0:        equ    0                                         ; Baud Rate Modulo Divisor Bit 0
SCI1BD_SBR1:        equ    1                                         ; Baud Rate Modulo Divisor Bit 1
SCI1BD_SBR2:        equ    2                                         ; Baud Rate Modulo Divisor Bit 2
SCI1BD_SBR3:        equ    3                                         ; Baud Rate Modulo Divisor Bit 3
SCI1BD_SBR4:        equ    4                                         ; Baud Rate Modulo Divisor Bit 4
SCI1BD_SBR5:        equ    5                                         ; Baud Rate Modulo Divisor Bit 5
SCI1BD_SBR6:        equ    6                                         ; Baud Rate Modulo Divisor Bit 6
SCI1BD_SBR7:        equ    7                                         ; Baud Rate Modulo Divisor Bit 7
SCI1BD_SBR8:        equ    8                                         ; Baud Rate Modulo Divisor Bit 8
SCI1BD_SBR9:        equ    9                                         ; Baud Rate Modulo Divisor Bit 9
SCI1BD_SBR10:       equ    10                                        ; Baud Rate Modulo Divisor Bit 10
SCI1BD_SBR11:       equ    11                                        ; Baud Rate Modulo Divisor Bit 11
SCI1BD_SBR12:       equ    12                                        ; Baud Rate Modulo Divisor Bit 12
; bit position masks
mSCI1BD_SBR0:       equ    %00000001
mSCI1BD_SBR1:       equ    %00000010
mSCI1BD_SBR2:       equ    %00000100
mSCI1BD_SBR3:       equ    %00001000
mSCI1BD_SBR4:       equ    %00010000
mSCI1BD_SBR5:       equ    %00100000
mSCI1BD_SBR6:       equ    %01000000
mSCI1BD_SBR7:       equ    %10000000
mSCI1BD_SBR8:       equ    %100000000
mSCI1BD_SBR9:       equ    %1000000000
mSCI1BD_SBR10:      equ    %10000000000
mSCI1BD_SBR11:      equ    %100000000000
mSCI1BD_SBR12:      equ    %1000000000000


;*** SCI1BDH - SCI1 Baud Rate Register High; 0x00000018 ***
SCI1BDH:            equ    $00000018                                ;*** SCI1BDH - SCI1 Baud Rate Register High; 0x00000018 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8:       equ    0                                         ; Baud Rate Modulo Divisor Bit 8
SCI1BDH_SBR9:       equ    1                                         ; Baud Rate Modulo Divisor Bit 9
SCI1BDH_SBR10:      equ    2                                         ; Baud Rate Modulo Divisor Bit 10
SCI1BDH_SBR11:      equ    3                                         ; Baud Rate Modulo Divisor Bit 11
SCI1BDH_SBR12:      equ    4                                         ; Baud Rate Modulo Divisor Bit 12
; bit position masks
mSCI1BDH_SBR8:      equ    %00000001
mSCI1BDH_SBR9:      equ    %00000010
mSCI1BDH_SBR10:     equ    %00000100
mSCI1BDH_SBR11:     equ    %00001000
mSCI1BDH_SBR12:     equ    %00010000


;*** SCI1BDL - SCI1 Baud Rate Register Low; 0x00000019 ***
SCI1BDL:            equ    $00000019                                ;*** SCI1BDL - SCI1 Baud Rate Register Low; 0x00000019 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** SCI1C1 - SCI1 Control Register 1; 0x0000001A ***
SCI1C1:             equ    $0000001A                                ;*** SCI1C1 - SCI1 Control Register 1; 0x0000001A ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SCI1C1_PT:          equ    0                                         ; Parity Type
SCI1C1_PE:          equ    1                                         ; Parity Enable
SCI1C1_ILT:         equ    2                                         ; Idle Line Type Select
SCI1C1_WAKE:        equ    3                                         ; Receiver Wakeup Method Select
SCI1C1_M:           equ    4                                         ; 9-Bit or 8-Bit Mode Select
SCI1C1_RSRC:        equ    5                                         ; Receiver Source Select
SCI1C1_SCI1SWAI:    equ    6                                         ; SCI1 Stops in Wait Mode
SCI1C1_LOOPS:       equ    7                                         ; Loop Mode Select
; bit position masks
mSCI1C1_PT:         equ    %00000001
mSCI1C1_PE:         equ    %00000010
mSCI1C1_ILT:        equ    %00000100
mSCI1C1_WAKE:       equ    %00001000
mSCI1C1_M:          equ    %00010000
mSCI1C1_RSRC:       equ    %00100000
mSCI1C1_SCI1SWAI:   equ    %01000000
mSCI1C1_LOOPS:      equ    %10000000


;*** SCI1C2 - SCI1 Control Register 2; 0x0000001B ***
SCI1C2:             equ    $0000001B                                ;*** SCI1C2 - SCI1 Control Register 2; 0x0000001B ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** SCI1S1 - SCI1 Status Register 1; 0x0000001C ***
SCI1S1:             equ    $0000001C                                ;*** SCI1S1 - SCI1 Status Register 1; 0x0000001C ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** SCI1S2 - SCI1 Status Register 2; 0x0000001D ***
SCI1S2:             equ    $0000001D                                ;*** SCI1S2 - SCI1 Status Register 2; 0x0000001D ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SCI1S2_RAF:         equ    0                                         ; Receiver Active Flag
; bit position masks
mSCI1S2_RAF:        equ    %00000001


;*** SCI1C3 - SCI1 Control Register 3; 0x0000001E ***
SCI1C3:             equ    $0000001E                                ;*** SCI1C3 - SCI1 Control Register 3; 0x0000001E ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SCI1C3_PEIE:        equ    0                                         ; Parity Error Interrupt Enable
SCI1C3_FEIE:        equ    1                                         ; Framing Error Interrupt Enable
SCI1C3_NEIE:        equ    2                                         ; Noise Error Interrupt Enable
SCI1C3_ORIE:        equ    3                                         ; Overrun Interrupt Enable
SCI1C3_TXDIR:       equ    5                                         ; TxD Pin Direction in Single-Wire Mode
SCI1C3_T8:          equ    6                                         ; Ninth Data Bit for Transmitter
SCI1C3_R8:          equ    7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI1C3_PEIE:       equ    %00000001
mSCI1C3_FEIE:       equ    %00000010
mSCI1C3_NEIE:       equ    %00000100
mSCI1C3_ORIE:       equ    %00001000
mSCI1C3_TXDIR:      equ    %00100000
mSCI1C3_T8:         equ    %01000000
mSCI1C3_R8:         equ    %10000000


;*** SCI1DRL - SCI1 Data Register; 0x0000001F ***
SCI1DRL:            equ    $0000001F                                ;*** SCI1DRL - SCI1 Data Register; 0x0000001F ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SCI1DRL_R0_T0:      equ    0                                         ; Receive/Transmit Data Bit 0
SCI1DRL_R1_T1:      equ    1                                         ; Receive/Transmit Data Bit 1
SCI1DRL_R2_T2:      equ    2                                         ; Receive/Transmit Data Bit 2
SCI1DRL_R3_T3:      equ    3                                         ; Receive/Transmit Data Bit 3
SCI1DRL_R4_T4:      equ    4                                         ; Receive/Transmit Data Bit 4
SCI1DRL_R5_T5:      equ    5                                         ; Receive/Transmit Data Bit 5
SCI1DRL_R6_T6:      equ    6                                         ; Receive/Transmit Data Bit 6
SCI1DRL_R7_T7:      equ    7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI1DRL_R0_T0:     equ    %00000001
mSCI1DRL_R1_T1:     equ    %00000010
mSCI1DRL_R2_T2:     equ    %00000100
mSCI1DRL_R3_T3:     equ    %00001000
mSCI1DRL_R4_T4:     equ    %00010000
mSCI1DRL_R5_T5:     equ    %00100000
mSCI1DRL_R6_T6:     equ    %01000000
mSCI1DRL_R7_T7:     equ    %10000000


;*** CMTCG1 - Carrier Generator Data Register 1; 0x00000020 ***
CMTCG1:             equ    $00000020                                ;*** CMTCG1 - Carrier Generator Data Register 1; 0x00000020 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTCG1_PL0:         equ    0                                         ; Primary Carrier Low Time Data Value Bit 0
CMTCG1_PL1:         equ    1                                         ; Primary Carrier Low Time Data Value Bit 1
CMTCG1_PL2:         equ    2                                         ; Primary Carrier Low Time Data Value Bit 2
CMTCG1_PL3:         equ    3                                         ; Primary Carrier Low Time Data Value Bit 3
CMTCG1_PL4:         equ    4                                         ; Primary Carrier Low Time Data Value Bit 4
CMTCG1_PL5:         equ    5                                         ; Primary Carrier Low Time Data Value Bit 5
CMTCG1_PL6:         equ    6                                         ; Primary Carrier Low Time Data Value Bit 6
CMTCG1_PL7:         equ    7                                         ; Primary Carrier Low Time Data Value Bit 7
CMTCG1_PH0:         equ    8                                         ; Primary Carrier High Time Data Value Bit 0
CMTCG1_PH1:         equ    9                                         ; Primary Carrier High Time Data Value Bit 1
CMTCG1_PH2:         equ    10                                        ; Primary Carrier High Time Data Value Bit 2
CMTCG1_PH3:         equ    11                                        ; Primary Carrier High Time Data Value Bit 3
CMTCG1_PH4:         equ    12                                        ; Primary Carrier High Time Data Value Bit 4
CMTCG1_PH5:         equ    13                                        ; Primary Carrier High Time Data Value Bit 5
CMTCG1_PH6:         equ    14                                        ; Primary Carrier High Time Data Value Bit 6
CMTCG1_PH7:         equ    15                                        ; Primary Carrier High Time Data Value Bit 7
; bit position masks
mCMTCG1_PL0:        equ    %00000001
mCMTCG1_PL1:        equ    %00000010
mCMTCG1_PL2:        equ    %00000100
mCMTCG1_PL3:        equ    %00001000
mCMTCG1_PL4:        equ    %00010000
mCMTCG1_PL5:        equ    %00100000
mCMTCG1_PL6:        equ    %01000000
mCMTCG1_PL7:        equ    %10000000
mCMTCG1_PH0:        equ    %100000000
mCMTCG1_PH1:        equ    %1000000000
mCMTCG1_PH2:        equ    %10000000000
mCMTCG1_PH3:        equ    %100000000000
mCMTCG1_PH4:        equ    %1000000000000
mCMTCG1_PH5:        equ    %10000000000000
mCMTCG1_PH6:        equ    %100000000000000
mCMTCG1_PH7:        equ    %1000000000000000


;*** CMTCGH1 - Carrier Generator Data Register High 1; 0x00000020 ***
CMTCGH1:            equ    $00000020                                ;*** CMTCGH1 - Carrier Generator Data Register High 1; 0x00000020 ***


;*** CMTCGL1 - Carrier Generator Data Register Low 1; 0x00000021 ***
CMTCGL1:            equ    $00000021                                ;*** CMTCGL1 - Carrier Generator Data Register Low 1; 0x00000021 ***


;*** CMTCG2 - Carrier Generator Data Register 2; 0x00000022 ***
CMTCG2:             equ    $00000022                                ;*** CMTCG2 - Carrier Generator Data Register 2; 0x00000022 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTCG2_SL0:         equ    0                                         ; Secondary Carrier Low Time Data Value Bit 0
CMTCG2_SL1:         equ    1                                         ; Secondary Carrier Low Time Data Value Bit 1
CMTCG2_SL2:         equ    2                                         ; Secondary Carrier Low Time Data Value Bit 2
CMTCG2_SL3:         equ    3                                         ; Secondary Carrier Low Time Data Value Bit 3
CMTCG2_SL4:         equ    4                                         ; Secondary Carrier Low Time Data Value Bit 4
CMTCG2_SL5:         equ    5                                         ; Secondary Carrier Low Time Data Value Bit 5
CMTCG2_SL6:         equ    6                                         ; Secondary Carrier Low Time Data Value Bit 6
CMTCG2_SL7:         equ    7                                         ; Secondary Carrier Low Time Data Value Bit 7
CMTCG2_SH0:         equ    8                                         ; Secondary Carrier High Time Data Value Bit 0
CMTCG2_SH1:         equ    9                                         ; Secondary Carrier High Time Data Value Bit 1
CMTCG2_SH2:         equ    10                                        ; Secondary Carrier High Time Data Value Bit 2
CMTCG2_SH3:         equ    11                                        ; Secondary Carrier High Time Data Value Bit 3
CMTCG2_SH4:         equ    12                                        ; Secondary Carrier High Time Data Value Bit 4
CMTCG2_SH5:         equ    13                                        ; Secondary Carrier High Time Data Value Bit 5
CMTCG2_SH6:         equ    14                                        ; Secondary Carrier High Time Data Value Bit 6
CMTCG2_SH7:         equ    15                                        ; Secondary Carrier High Time Data Value Bit 7
; bit position masks
mCMTCG2_SL0:        equ    %00000001
mCMTCG2_SL1:        equ    %00000010
mCMTCG2_SL2:        equ    %00000100
mCMTCG2_SL3:        equ    %00001000
mCMTCG2_SL4:        equ    %00010000
mCMTCG2_SL5:        equ    %00100000
mCMTCG2_SL6:        equ    %01000000
mCMTCG2_SL7:        equ    %10000000
mCMTCG2_SH0:        equ    %100000000
mCMTCG2_SH1:        equ    %1000000000
mCMTCG2_SH2:        equ    %10000000000
mCMTCG2_SH3:        equ    %100000000000
mCMTCG2_SH4:        equ    %1000000000000
mCMTCG2_SH5:        equ    %10000000000000
mCMTCG2_SH6:        equ    %100000000000000
mCMTCG2_SH7:        equ    %1000000000000000


;*** CMTCGH2 - Carrier Generator Data Register High 2; 0x00000022 ***
CMTCGH2:            equ    $00000022                                ;*** CMTCGH2 - Carrier Generator Data Register High 2; 0x00000022 ***


;*** CMTCGL2 - Carrier Generator Data Register Low 2; 0x00000023 ***
CMTCGL2:            equ    $00000023                                ;*** CMTCGL2 - Carrier Generator Data Register Low 2; 0x00000023 ***


;*** CMTOC - CMT Output Control Register; 0x00000024 ***
CMTOC:              equ    $00000024                                ;*** CMTOC - CMT Output Control Register; 0x00000024 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTOC_IROPEN:       equ    5                                         ; IRO Pin Enable
CMTOC_CMTPOL:       equ    6                                         ; CMT Output Polarity
CMTOC_IROL:         equ    7                                         ; IRO Latch Control
; bit position masks
mCMTOC_IROPEN:      equ    %00100000
mCMTOC_CMTPOL:      equ    %01000000
mCMTOC_IROL:        equ    %10000000


;*** CMTMSC - CMT Modulator Status and Control Register; 0x00000025 ***
CMTMSC:             equ    $00000025                                ;*** CMTMSC - CMT Modulator Status and Control Register; 0x00000025 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTMSC_MCGEN:       equ    0                                         ; Modulator and Carrier Generator Enable
CMTMSC_EOCIE:       equ    1                                         ; End of Cycle Interrupt Enable
CMTMSC_FSK:         equ    2                                         ; FSK Mode Select
CMTMSC_BASE:        equ    3                                         ; Baseband Enable
CMTMSC_EXSPC:       equ    4                                         ; Extended Space Enable
CMTMSC_CMTDIV0:     equ    5                                         ; CMT Clock Divide Prescaler Bit 0
CMTMSC_CMTDIV1:     equ    6                                         ; CMT Clock Divide Prescaler Bit 1
CMTMSC_EOCF:        equ    7                                         ; End Of Cycle Status Flag
; bit position masks
mCMTMSC_MCGEN:      equ    %00000001
mCMTMSC_EOCIE:      equ    %00000010
mCMTMSC_FSK:        equ    %00000100
mCMTMSC_BASE:       equ    %00001000
mCMTMSC_EXSPC:      equ    %00010000
mCMTMSC_CMTDIV0:    equ    %00100000
mCMTMSC_CMTDIV1:    equ    %01000000
mCMTMSC_EOCF:       equ    %10000000


;*** CMTCMD12 - CMT Modulator Data Register 12; 0x00000026 ***
CMTCMD12:           equ    $00000026                                ;*** CMTCMD12 - CMT Modulator Data Register 12; 0x00000026 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTCMD12_MB0:       equ    0                                         ; CMT Modulator Data Bit 0
CMTCMD12_MB1:       equ    1                                         ; CMT Modulator Data Bit 1
CMTCMD12_MB2:       equ    2                                         ; CMT Modulator Data Bit 2
CMTCMD12_MB3:       equ    3                                         ; CMT Modulator Data Bit 3
CMTCMD12_MB4:       equ    4                                         ; CMT Modulator Data Bit 4
CMTCMD12_MB5:       equ    5                                         ; CMT Modulator Data Bit 5
CMTCMD12_MB6:       equ    6                                         ; CMT Modulator Data Bit 6
CMTCMD12_MB7:       equ    7                                         ; CMT Modulator Data Bit 7
CMTCMD12_MB8:       equ    8                                         ; CMT Modulator Data Bit 8
CMTCMD12_MB9:       equ    9                                         ; CMT Modulator Data Bit 9
CMTCMD12_MB10:      equ    10                                        ; CMT Modulator Data Bit 10
CMTCMD12_MB11:      equ    11                                        ; CMT Modulator Data Bit 11
CMTCMD12_MB12:      equ    12                                        ; CMT Modulator Data Bit 12
CMTCMD12_MB13:      equ    13                                        ; CMT Modulator Data Bit 13
CMTCMD12_MB14:      equ    14                                        ; CMT Modulator Data Bit 14
CMTCMD12_MB15:      equ    15                                        ; CMT Modulator Data Bit 15
; bit position masks
mCMTCMD12_MB0:      equ    %00000001
mCMTCMD12_MB1:      equ    %00000010
mCMTCMD12_MB2:      equ    %00000100
mCMTCMD12_MB3:      equ    %00001000
mCMTCMD12_MB4:      equ    %00010000
mCMTCMD12_MB5:      equ    %00100000
mCMTCMD12_MB6:      equ    %01000000
mCMTCMD12_MB7:      equ    %10000000
mCMTCMD12_MB8:      equ    %100000000
mCMTCMD12_MB9:      equ    %1000000000
mCMTCMD12_MB10:     equ    %10000000000
mCMTCMD12_MB11:     equ    %100000000000
mCMTCMD12_MB12:     equ    %1000000000000
mCMTCMD12_MB13:     equ    %10000000000000
mCMTCMD12_MB14:     equ    %100000000000000
mCMTCMD12_MB15:     equ    %1000000000000000


;*** CMTCMD1 - CMT Modulator Data Register 1; 0x00000026 ***
CMTCMD1:            equ    $00000026                                ;*** CMTCMD1 - CMT Modulator Data Register 1; 0x00000026 ***


;*** CMTCMD2 - CMT Modulator Data Register 2; 0x00000027 ***
CMTCMD2:            equ    $00000027                                ;*** CMTCMD2 - CMT Modulator Data Register 2; 0x00000027 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTCMD2_MB0:        equ    0                                         ; CMT Modulator Data Bit 0
CMTCMD2_MB1:        equ    1                                         ; CMT Modulator Data Bit 1
CMTCMD2_MB2:        equ    2                                         ; CMT Modulator Data Bit 2
CMTCMD2_MB3:        equ    3                                         ; CMT Modulator Data Bit 3
CMTCMD2_MB4:        equ    4                                         ; CMT Modulator Data Bit 4
CMTCMD2_MB5:        equ    5                                         ; CMT Modulator Data Bit 5
CMTCMD2_MB6:        equ    6                                         ; CMT Modulator Data Bit 6
CMTCMD2_MB7:        equ    7                                         ; CMT Modulator Data Bit 7
; bit position masks
mCMTCMD2_MB0:       equ    %00000001
mCMTCMD2_MB1:       equ    %00000010
mCMTCMD2_MB2:       equ    %00000100
mCMTCMD2_MB3:       equ    %00001000
mCMTCMD2_MB4:       equ    %00010000
mCMTCMD2_MB5:       equ    %00100000
mCMTCMD2_MB6:       equ    %01000000
mCMTCMD2_MB7:       equ    %10000000


;*** CMTCMD34 - CMT Modulator Data Register 34; 0x00000028 ***
CMTCMD34:           equ    $00000028                                ;*** CMTCMD34 - CMT Modulator Data Register 34; 0x00000028 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTCMD34_SB0:       equ    0                                         ; CMT Modulator Data Bit 0
CMTCMD34_SB1:       equ    1                                         ; CMT Modulator Data Bit 1
CMTCMD34_SB2:       equ    2                                         ; CMT Modulator Data Bit 2
CMTCMD34_SB3:       equ    3                                         ; CMT Modulator Data Bit 3
CMTCMD34_SB4:       equ    4                                         ; CMT Modulator Data Bit 4
CMTCMD34_SB5:       equ    5                                         ; CMT Modulator Data Bit 5
CMTCMD34_SB6:       equ    6                                         ; CMT Modulator Data Bit 6
CMTCMD34_SB7:       equ    7                                         ; CMT Modulator Data Bit 7
CMTCMD34_SB8:       equ    8                                         ; CMT Modulator Data Bit 8
CMTCMD34_SB9:       equ    9                                         ; CMT Modulator Data Bit 9
CMTCMD34_SB10:      equ    10                                        ; CMT Modulator Data Bit 10
CMTCMD34_SB11:      equ    11                                        ; CMT Modulator Data Bit 11
CMTCMD34_SB12:      equ    12                                        ; CMT Modulator Data Bit 12
CMTCMD34_SB13:      equ    13                                        ; CMT Modulator Data Bit 13
CMTCMD34_SB14:      equ    14                                        ; CMT Modulator Data Bit 14
CMTCMD34_SB15:      equ    15                                        ; CMT Modulator Data Bit 15
; bit position masks
mCMTCMD34_SB0:      equ    %00000001
mCMTCMD34_SB1:      equ    %00000010
mCMTCMD34_SB2:      equ    %00000100
mCMTCMD34_SB3:      equ    %00001000
mCMTCMD34_SB4:      equ    %00010000
mCMTCMD34_SB5:      equ    %00100000
mCMTCMD34_SB6:      equ    %01000000
mCMTCMD34_SB7:      equ    %10000000
mCMTCMD34_SB8:      equ    %100000000
mCMTCMD34_SB9:      equ    %1000000000
mCMTCMD34_SB10:     equ    %10000000000
mCMTCMD34_SB11:     equ    %100000000000
mCMTCMD34_SB12:     equ    %1000000000000
mCMTCMD34_SB13:     equ    %10000000000000
mCMTCMD34_SB14:     equ    %100000000000000
mCMTCMD34_SB15:     equ    %1000000000000000


;*** CMTCMD3 - CMT Modulator Data Register 3; 0x00000028 ***
CMTCMD3:            equ    $00000028                                ;*** CMTCMD3 - CMT Modulator Data Register 3; 0x00000028 ***


;*** CMTCMD4 - CMT Modulator Data Register 4; 0x00000029 ***
CMTCMD4:            equ    $00000029                                ;*** CMTCMD4 - CMT Modulator Data Register 4; 0x00000029 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
CMTCMD4_SB0:        equ    0                                         ; CMT Modulator Data Bit 0
CMTCMD4_SB1:        equ    1                                         ; CMT Modulator Data Bit 1
CMTCMD4_SB2:        equ    2                                         ; CMT Modulator Data Bit 2
CMTCMD4_SB3:        equ    3                                         ; CMT Modulator Data Bit 3
CMTCMD4_SB4:        equ    4                                         ; CMT Modulator Data Bit 4
CMTCMD4_SB5:        equ    5                                         ; CMT Modulator Data Bit 5
CMTCMD4_SB6:        equ    6                                         ; CMT Modulator Data Bit 6
CMTCMD4_SB7:        equ    7                                         ; CMT Modulator Data Bit 7
; bit position masks
mCMTCMD4_SB0:       equ    %00000001
mCMTCMD4_SB1:       equ    %00000010
mCMTCMD4_SB2:       equ    %00000100
mCMTCMD4_SB3:       equ    %00001000
mCMTCMD4_SB4:       equ    %00010000
mCMTCMD4_SB5:       equ    %00100000
mCMTCMD4_SB6:       equ    %01000000
mCMTCMD4_SB7:       equ    %10000000


;*** IRQSC - Interrupt Request Status and Control Register; 0x0000002A ***
IRQSC:              equ    $0000002A                                ;*** IRQSC - Interrupt Request Status and Control Register; 0x0000002A ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD:       equ    0                                         ; IRQ Detection Mode
IRQSC_IRQIE:        equ    1                                         ; IRQ Interrupt Enable
IRQSC_IRQACK:       equ    2                                         ; IRQ Acknowledge
IRQSC_IRQF:         equ    3                                         ; IRQ Flag
IRQSC_IRQPE:        equ    4                                         ; IRQ Pin Enable
IRQSC_IRQEDG:       equ    5                                         ; Interrupt Request (IRQ) Edge Select
; bit position masks
mIRQSC_IRQMOD:      equ    %00000001
mIRQSC_IRQIE:       equ    %00000010
mIRQSC_IRQACK:      equ    %00000100
mIRQSC_IRQF:        equ    %00001000
mIRQSC_IRQPE:       equ    %00010000
mIRQSC_IRQEDG:      equ    %00100000


;*** ACMP1SC - Analog Comparator Status and Control Register; 0x0000002B ***
ACMP1SC:            equ    $0000002B                                ;*** ACMP1SC - Analog Comparator Status and Control Register; 0x0000002B ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
ACMP1SC_ACMOD0:     equ    0                                         ; Analog Comparator Mode Bit 0
ACMP1SC_ACMOD1:     equ    1                                         ; Analog Comparator Mode Bit 1
ACMP1SC_ACO:        equ    3                                         ; Analog Comparator Output
ACMP1SC_ACIE:       equ    4                                         ; Analog Comparator Interrupt Enable
ACMP1SC_ACF:        equ    5                                         ; Analog Comparator Flag
ACMP1SC_ACBGS:      equ    6                                         ; Analog Comparator Bandgap Select
ACMP1SC_ACME:       equ    7                                         ; Analog Comparator Module Enable
; bit position masks
mACMP1SC_ACMOD0:    equ    %00000001
mACMP1SC_ACMOD1:    equ    %00000010
mACMP1SC_ACO:       equ    %00001000
mACMP1SC_ACIE:      equ    %00010000
mACMP1SC_ACF:       equ    %00100000
mACMP1SC_ACBGS:     equ    %01000000
mACMP1SC_ACME:      equ    %10000000


;*** TPM1SC - TPM1 Timer Status and Control Register; 0x00000030 ***
TPM1SC:             equ    $00000030                                ;*** TPM1SC - TPM1 Timer Status and Control Register; 0x00000030 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** TPM1CNT - TPM1 Counter Register; 0x00000031 ***
TPM1CNT:            equ    $00000031                                ;*** TPM1CNT - TPM1 Counter Register; 0x00000031 ***


;*** TPM1CNTH - TPM1 Counter Register High; 0x00000031 ***
TPM1CNTH:           equ    $00000031                                ;*** TPM1CNTH - TPM1 Counter Register High; 0x00000031 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1CNTH_BIT8:      equ    0                                         ; TPM1 Counter Bit 8
TPM1CNTH_BIT9:      equ    1                                         ; TPM1 Counter Bit 9
TPM1CNTH_BIT10:     equ    2                                         ; TPM1 Counter Bit 10
TPM1CNTH_BIT11:     equ    3                                         ; TPM1 Counter Bit 11
TPM1CNTH_BIT12:     equ    4                                         ; TPM1 Counter Bit 12
TPM1CNTH_BIT13:     equ    5                                         ; TPM1 Counter Bit 13
TPM1CNTH_BIT14:     equ    6                                         ; TPM1 Counter Bit 14
TPM1CNTH_BIT15:     equ    7                                         ; TPM1 Counter Bit 15
; bit position masks
mTPM1CNTH_BIT8:     equ    %00000001
mTPM1CNTH_BIT9:     equ    %00000010
mTPM1CNTH_BIT10:    equ    %00000100
mTPM1CNTH_BIT11:    equ    %00001000
mTPM1CNTH_BIT12:    equ    %00010000
mTPM1CNTH_BIT13:    equ    %00100000
mTPM1CNTH_BIT14:    equ    %01000000
mTPM1CNTH_BIT15:    equ    %10000000


;*** TPM1CNTL - TPM1 Counter Register Low; 0x00000032 ***
TPM1CNTL:           equ    $00000032                                ;*** TPM1CNTL - TPM1 Counter Register Low; 0x00000032 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1CNTL_BIT0:      equ    0                                         ; TPM1 Counter Bit 0
TPM1CNTL_BIT1:      equ    1                                         ; TPM1 Counter Bit 1
TPM1CNTL_BIT2:      equ    2                                         ; TPM1 Counter Bit 2
TPM1CNTL_BIT3:      equ    3                                         ; TPM1 Counter Bit 3
TPM1CNTL_BIT4:      equ    4                                         ; TPM1 Counter Bit 4
TPM1CNTL_BIT5:      equ    5                                         ; TPM1 Counter Bit 5
TPM1CNTL_BIT6:      equ    6                                         ; TPM1 Counter Bit 6
TPM1CNTL_BIT7:      equ    7                                         ; TPM1 Counter Bit 7
; bit position masks
mTPM1CNTL_BIT0:     equ    %00000001
mTPM1CNTL_BIT1:     equ    %00000010
mTPM1CNTL_BIT2:     equ    %00000100
mTPM1CNTL_BIT3:     equ    %00001000
mTPM1CNTL_BIT4:     equ    %00010000
mTPM1CNTL_BIT5:     equ    %00100000
mTPM1CNTL_BIT6:     equ    %01000000
mTPM1CNTL_BIT7:     equ    %10000000


;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x00000033 ***
TPM1MOD:            equ    $00000033                                ;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x00000033 ***


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x00000033 ***
TPM1MODH:           equ    $00000033                                ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x00000033 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1MODH_BIT8:      equ    0                                         ; Timer Counter Modulo Bit 8
TPM1MODH_BIT9:      equ    1                                         ; Timer Counter Modulo Bit 9
TPM1MODH_BIT10:     equ    2                                         ; Timer Counter Modulo Bit 10
TPM1MODH_BIT11:     equ    3                                         ; Timer Counter Modulo Bit 11
TPM1MODH_BIT12:     equ    4                                         ; Timer Counter Modulo Bit 12
TPM1MODH_BIT13:     equ    5                                         ; Timer Counter Modulo Bit 13
TPM1MODH_BIT14:     equ    6                                         ; Timer Counter Modulo Bit 14
TPM1MODH_BIT15:     equ    7                                         ; Timer Counter Modulo Bit 15
; bit position masks
mTPM1MODH_BIT8:     equ    %00000001
mTPM1MODH_BIT9:     equ    %00000010
mTPM1MODH_BIT10:    equ    %00000100
mTPM1MODH_BIT11:    equ    %00001000
mTPM1MODH_BIT12:    equ    %00010000
mTPM1MODH_BIT13:    equ    %00100000
mTPM1MODH_BIT14:    equ    %01000000
mTPM1MODH_BIT15:    equ    %10000000


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x00000034 ***
TPM1MODL:           equ    $00000034                                ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x00000034 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1MODL_BIT0:      equ    0                                         ; Timer Counter Modulo Bit 0
TPM1MODL_BIT1:      equ    1                                         ; Timer Counter Modulo Bit 1
TPM1MODL_BIT2:      equ    2                                         ; Timer Counter Modulo Bit 2
TPM1MODL_BIT3:      equ    3                                         ; Timer Counter Modulo Bit 3
TPM1MODL_BIT4:      equ    4                                         ; Timer Counter Modulo Bit 4
TPM1MODL_BIT5:      equ    5                                         ; Timer Counter Modulo Bit 5
TPM1MODL_BIT6:      equ    6                                         ; Timer Counter Modulo Bit 6
TPM1MODL_BIT7:      equ    7                                         ; Timer Counter Modulo Bit 7
; bit position masks
mTPM1MODL_BIT0:     equ    %00000001
mTPM1MODL_BIT1:     equ    %00000010
mTPM1MODL_BIT2:     equ    %00000100
mTPM1MODL_BIT3:     equ    %00001000
mTPM1MODL_BIT4:     equ    %00010000
mTPM1MODL_BIT5:     equ    %00100000
mTPM1MODL_BIT6:     equ    %01000000
mTPM1MODL_BIT7:     equ    %10000000


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x00000035 ***
TPM1C0SC:           equ    $00000035                                ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x00000035 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1C0SC_ELS0A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C0SC_ELS0B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C0SC_MS0A:      equ    4                                         ; Mode Select A for TPM1 Channel 0
TPM1C0SC_MS0B:      equ    5                                         ; Mode Select B for TPM1 Channel 0
TPM1C0SC_CH0IE:     equ    6                                         ; Channel 0 Interrupt Enable
TPM1C0SC_CH0F:      equ    7                                         ; Channel 0 Flag
; bit position masks
mTPM1C0SC_ELS0A:    equ    %00000100
mTPM1C0SC_ELS0B:    equ    %00001000
mTPM1C0SC_MS0A:     equ    %00010000
mTPM1C0SC_MS0B:     equ    %00100000
mTPM1C0SC_CH0IE:    equ    %01000000
mTPM1C0SC_CH0F:     equ    %10000000


;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x00000036 ***
TPM1C0V:            equ    $00000036                                ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x00000036 ***


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x00000036 ***
TPM1C0VH:           equ    $00000036                                ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x00000036 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1C0VH_BIT8:      equ    0                                         ; Timer Channel 0 Value Bit 8
TPM1C0VH_BIT9:      equ    1                                         ; Timer Channel 0 Value Bit 9
TPM1C0VH_BIT10:     equ    2                                         ; Timer Channel 0 Value Bit 10
TPM1C0VH_BIT11:     equ    3                                         ; Timer Channel 0 Value Bit 11
TPM1C0VH_BIT12:     equ    4                                         ; Timer Channel 0 Value Bit 12
TPM1C0VH_BIT13:     equ    5                                         ; Timer Channel 0 Value Bit 13
TPM1C0VH_BIT14:     equ    6                                         ; Timer Channel 0 Value Bit 14
TPM1C0VH_BIT15:     equ    7                                         ; Timer Channel 0 Value Bit 15
; bit position masks
mTPM1C0VH_BIT8:     equ    %00000001
mTPM1C0VH_BIT9:     equ    %00000010
mTPM1C0VH_BIT10:    equ    %00000100
mTPM1C0VH_BIT11:    equ    %00001000
mTPM1C0VH_BIT12:    equ    %00010000
mTPM1C0VH_BIT13:    equ    %00100000
mTPM1C0VH_BIT14:    equ    %01000000
mTPM1C0VH_BIT15:    equ    %10000000


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x00000037 ***
TPM1C0VL:           equ    $00000037                                ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x00000037 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1C0VL_BIT0:      equ    0                                         ; Timer Channel 0 Value Bit 0
TPM1C0VL_BIT1:      equ    1                                         ; Timer Channel 0 Value Bit 1
TPM1C0VL_BIT2:      equ    2                                         ; Timer Channel 0 Value Bit 2
TPM1C0VL_BIT3:      equ    3                                         ; Timer Channel 0 Value Bit 3
TPM1C0VL_BIT4:      equ    4                                         ; Timer Channel 0 Value Bit 4
TPM1C0VL_BIT5:      equ    5                                         ; Timer Channel 0 Value Bit 5
TPM1C0VL_BIT6:      equ    6                                         ; Timer Channel 0 Value Bit 6
TPM1C0VL_BIT7:      equ    7                                         ; Timer Channel 0 Value Bit 7
; bit position masks
mTPM1C0VL_BIT0:     equ    %00000001
mTPM1C0VL_BIT1:     equ    %00000010
mTPM1C0VL_BIT2:     equ    %00000100
mTPM1C0VL_BIT3:     equ    %00001000
mTPM1C0VL_BIT4:     equ    %00010000
mTPM1C0VL_BIT5:     equ    %00100000
mTPM1C0VL_BIT6:     equ    %01000000
mTPM1C0VL_BIT7:     equ    %10000000


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x00000038 ***
TPM1C1SC:           equ    $00000038                                ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x00000038 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1C1SC_ELS1A:     equ    2                                         ; Edge/Level Select Bit A
TPM1C1SC_ELS1B:     equ    3                                         ; Edge/Level Select Bit B
TPM1C1SC_MS1A:      equ    4                                         ; Mode Select A for TPM1 Channel 1
TPM1C1SC_MS1B:      equ    5                                         ; Mode Select B for TPM1 Channel 1
TPM1C1SC_CH1IE:     equ    6                                         ; Channel 1 Interrupt Enable
TPM1C1SC_CH1F:      equ    7                                         ; Channel 1 Flag
; bit position masks
mTPM1C1SC_ELS1A:    equ    %00000100
mTPM1C1SC_ELS1B:    equ    %00001000
mTPM1C1SC_MS1A:     equ    %00010000
mTPM1C1SC_MS1B:     equ    %00100000
mTPM1C1SC_CH1IE:    equ    %01000000
mTPM1C1SC_CH1F:     equ    %10000000


;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x00000039 ***
TPM1C1V:            equ    $00000039                                ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x00000039 ***


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x00000039 ***
TPM1C1VH:           equ    $00000039                                ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x00000039 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1C1VH_BIT8:      equ    0                                         ; Timer Channel 1 Value Bit 8
TPM1C1VH_BIT9:      equ    1                                         ; Timer Channel 1 Value Bit 9
TPM1C1VH_BIT10:     equ    2                                         ; Timer Channel 1 Value Bit 10
TPM1C1VH_BIT11:     equ    3                                         ; Timer Channel 1 Value Bit 11
TPM1C1VH_BIT12:     equ    4                                         ; Timer Channel 1 Value Bit 12
TPM1C1VH_BIT13:     equ    5                                         ; Timer Channel 1 Value Bit 13
TPM1C1VH_BIT14:     equ    6                                         ; Timer Channel 1 Value Bit 14
TPM1C1VH_BIT15:     equ    7                                         ; Timer Channel 1 Value Bit 15
; bit position masks
mTPM1C1VH_BIT8:     equ    %00000001
mTPM1C1VH_BIT9:     equ    %00000010
mTPM1C1VH_BIT10:    equ    %00000100
mTPM1C1VH_BIT11:    equ    %00001000
mTPM1C1VH_BIT12:    equ    %00010000
mTPM1C1VH_BIT13:    equ    %00100000
mTPM1C1VH_BIT14:    equ    %01000000
mTPM1C1VH_BIT15:    equ    %10000000


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x0000003A ***
TPM1C1VL:           equ    $0000003A                                ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x0000003A ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
TPM1C1VL_BIT0:      equ    0                                         ; Timer Channel 1 Value Bit 0
TPM1C1VL_BIT1:      equ    1                                         ; Timer Channel 1 Value Bit 1
TPM1C1VL_BIT2:      equ    2                                         ; Timer Channel 1 Value Bit 2
TPM1C1VL_BIT3:      equ    3                                         ; Timer Channel 1 Value Bit 3
TPM1C1VL_BIT4:      equ    4                                         ; Timer Channel 1 Value Bit 4
TPM1C1VL_BIT5:      equ    5                                         ; Timer Channel 1 Value Bit 5
TPM1C1VL_BIT6:      equ    6                                         ; Timer Channel 1 Value Bit 6
TPM1C1VL_BIT7:      equ    7                                         ; Timer Channel 1 Value Bit 7
; bit position masks
mTPM1C1VL_BIT0:     equ    %00000001
mTPM1C1VL_BIT1:     equ    %00000010
mTPM1C1VL_BIT2:     equ    %00000100
mTPM1C1VL_BIT3:     equ    %00001000
mTPM1C1VL_BIT4:     equ    %00010000
mTPM1C1VL_BIT5:     equ    %00100000
mTPM1C1VL_BIT6:     equ    %01000000
mTPM1C1VL_BIT7:     equ    %10000000


;*** SPI1C1 - SPI1 Control Register 1; 0x00000040 ***
SPI1C1:             equ    $00000040                                ;*** SPI1C1 - SPI1 Control Register 1; 0x00000040 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SPI1C1_LSBFE:       equ    0                                         ; LSB First (shifter direction)
SPI1C1_SSOE:        equ    1                                         ; Slave Select Output Enable
SPI1C1_CPHA:        equ    2                                         ; Clock Phase
SPI1C1_CPOL:        equ    3                                         ; Clock Polarity
SPI1C1_MSTR:        equ    4                                         ; Master/Slave Mode Select
SPI1C1_SPTIE:       equ    5                                         ; SPI1 Transmit Interrupt Enable
SPI1C1_SPE:         equ    6                                         ; SPI1 System Enable
SPI1C1_SPI1E:       equ    7                                         ; SPI1 Interrupt Enable
; bit position masks
mSPI1C1_LSBFE:      equ    %00000001
mSPI1C1_SSOE:       equ    %00000010
mSPI1C1_CPHA:       equ    %00000100
mSPI1C1_CPOL:       equ    %00001000
mSPI1C1_MSTR:       equ    %00010000
mSPI1C1_SPTIE:      equ    %00100000
mSPI1C1_SPE:        equ    %01000000
mSPI1C1_SPI1E:      equ    %10000000


;*** SPI1C2 - SPI1 Control Register 2; 0x00000041 ***
SPI1C2:             equ    $00000041                                ;*** SPI1C2 - SPI1 Control Register 2; 0x00000041 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0:        equ    0                                         ; SPI1 Pin Control 0
SPI1C2_SPISWAI:     equ    1                                         ; SPI1 Stop in Wait Mode
SPI1C2_BIDIROE:     equ    3                                         ; Bidirectional Mode Output Enable
SPI1C2_MODFEN:      equ    4                                         ; Master Mode-Fault Function Enable
; bit position masks
mSPI1C2_SPC0:       equ    %00000001
mSPI1C2_SPISWAI:    equ    %00000010
mSPI1C2_BIDIROE:    equ    %00001000
mSPI1C2_MODFEN:     equ    %00010000


;*** SPI1BR - SPI1 Baud Rate Register; 0x00000042 ***
SPI1BR:             equ    $00000042                                ;*** SPI1BR - SPI1 Baud Rate Register; 0x00000042 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0:        equ    0                                         ; SPI1 Baud Rate Divisor Bit 0
SPI1BR_SPR1:        equ    1                                         ; SPI1 Baud Rate Divisor Bit 1
SPI1BR_SPR2:        equ    2                                         ; SPI1 Baud Rate Divisor Bit 2
SPI1BR_SPPR0:       equ    4                                         ; SPI1 Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1:       equ    5                                         ; SPI1 Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2:       equ    6                                         ; SPI1 Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0:       equ    %00000001
mSPI1BR_SPR1:       equ    %00000010
mSPI1BR_SPR2:       equ    %00000100
mSPI1BR_SPPR0:      equ    %00010000
mSPI1BR_SPPR1:      equ    %00100000
mSPI1BR_SPPR2:      equ    %01000000


;*** SPI1S - SPI1 Status Register; 0x00000043 ***
SPI1S:              equ    $00000043                                ;*** SPI1S - SPI1 Status Register; 0x00000043 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF:         equ    4                                         ; Master Mode Fault Flag
SPI1S_SPTEF:        equ    5                                         ; SPI1 Transmit Buffer Empty Flag
SPI1S_SPRF:         equ    7                                         ; SPI1 Read Buffer Full Flag
; bit position masks
mSPI1S_MODF:        equ    %00010000
mSPI1S_SPTEF:       equ    %00100000
mSPI1S_SPRF:        equ    %10000000


;*** SPI1D - SPI1 Data Register; 0x00000045 ***
SPI1D:              equ    $00000045                                ;*** SPI1D - SPI1 Data Register; 0x00000045 ***


;*** SRS - System Reset Status Register; 0x00001800 ***
SRS:                equ    $00001800                                ;*** SRS - System Reset Status Register; 0x00001800 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SRS_LVD:            equ    1                                         ; Low Voltage Detect
SRS_ILOP:           equ    4                                         ; Illegal Opcode
SRS_COP:            equ    5                                         ; Computer Operating Properly (COP) Watchdog
SRS_PIN:            equ    6                                         ; External Reset Pin
SRS_POR:            equ    7                                         ; Power-On Reset
; bit position masks
mSRS_LVD:           equ    %00000010
mSRS_ILOP:          equ    %00010000
mSRS_COP:           equ    %00100000
mSRS_PIN:           equ    %01000000
mSRS_POR:           equ    %10000000


;*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***
SBDFR:              equ    $00001801                                ;*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SBDFR_BDFR:         equ    0                                         ; Background Debug Force Reset
; bit position masks
mSBDFR_BDFR:        equ    %00000001


;*** SOPT - System Integration Module Options Register; 0x00001802 ***
SOPT:               equ    $00001802                                ;*** SOPT - System Integration Module Options Register; 0x00001802 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SOPT_RSTPE:         equ    0                                         ; RESET Pin Enable
SOPT_BKGDPE:        equ    1                                         ; Background Debug Mode Pin Enable
SOPT_STOPE:         equ    5                                         ; Stop Mode Enable
SOPT_COPT:          equ    6                                         ; COP Watchdog Timeout
SOPT_COPE:          equ    7                                         ; COP Watchdog Enable
; bit position masks
mSOPT_RSTPE:        equ    %00000001
mSOPT_BKGDPE:       equ    %00000010
mSOPT_STOPE:        equ    %00100000
mSOPT_COPT:         equ    %01000000
mSOPT_COPE:         equ    %10000000


;*** SDID - System Device Identification Register; 0x00001806 ***
SDID:               equ    $00001806                                ;*** SDID - System Device Identification Register; 0x00001806 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SDID_ID0:           equ    0                                         ; Part Identification Number 0
SDID_ID1:           equ    1                                         ; Part Identification Number 1
SDID_ID2:           equ    2                                         ; Part Identification Number 2
SDID_ID3:           equ    3                                         ; Part Identification Number 3
SDID_ID4:           equ    4                                         ; Part Identification Number 4
SDID_ID5:           equ    5                                         ; Part Identification Number 5
SDID_ID6:           equ    6                                         ; Part Identification Number 6
SDID_ID7:           equ    7                                         ; Part Identification Number 7
SDID_ID8:           equ    8                                         ; Part Identification Number 8
SDID_ID9:           equ    9                                         ; Part Identification Number 9
SDID_ID10:          equ    10                                        ; Part Identification Number 10
SDID_ID11:          equ    11                                        ; Part Identification Number 11
SDID_REV0:          equ    12                                        ; Revision Number 0
SDID_REV1:          equ    13                                        ; Revision Number 1
SDID_REV2:          equ    14                                        ; Revision Number 2
SDID_REV3:          equ    15                                        ; Revision Number 3
; bit position masks
mSDID_ID0:          equ    %00000001
mSDID_ID1:          equ    %00000010
mSDID_ID2:          equ    %00000100
mSDID_ID3:          equ    %00001000
mSDID_ID4:          equ    %00010000
mSDID_ID5:          equ    %00100000
mSDID_ID6:          equ    %01000000
mSDID_ID7:          equ    %10000000
mSDID_ID8:          equ    %100000000
mSDID_ID9:          equ    %1000000000
mSDID_ID10:         equ    %10000000000
mSDID_ID11:         equ    %100000000000
mSDID_REV0:         equ    %1000000000000
mSDID_REV1:         equ    %10000000000000
mSDID_REV2:         equ    %100000000000000
mSDID_REV3:         equ    %1000000000000000


;*** SDIDH - System Device Identification Register High; 0x00001806 ***
SDIDH:              equ    $00001806                                ;*** SDIDH - System Device Identification Register High; 0x00001806 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** SDIDL - System Device Identification Register Low; 0x00001807 ***
SDIDL:              equ    $00001807                                ;*** SDIDL - System Device Identification Register Low; 0x00001807 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** SRTISC - System RTI Status and Control Register; 0x00001808 ***
SRTISC:             equ    $00001808                                ;*** SRTISC - System RTI Status and Control Register; 0x00001808 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SRTISC_RTIS0:       equ    0                                         ; Real-Time Interrupt Delay Select Bit 0
SRTISC_RTIS1:       equ    1                                         ; Real-Time Interrupt Delay Select Bit 1
SRTISC_RTIS2:       equ    2                                         ; Real-Time Interrupt Delay Select Bit 2
SRTISC_RTIE:        equ    4                                         ; Real-Time Interrupt Enable
SRTISC_RTICLKS:     equ    5                                         ; Real-Time Interrupt Clock Select
SRTISC_RTIACK:      equ    6                                         ; Real-Time Interrupt Acknowledge
SRTISC_RTIF:        equ    7                                         ; Real-Time Interrupt Flag
; bit position masks
mSRTISC_RTIS0:      equ    %00000001
mSRTISC_RTIS1:      equ    %00000010
mSRTISC_RTIS2:      equ    %00000100
mSRTISC_RTIE:       equ    %00010000
mSRTISC_RTICLKS:    equ    %00100000
mSRTISC_RTIACK:     equ    %01000000
mSRTISC_RTIF:       equ    %10000000


;*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***
SPMSC1:             equ    $00001809                                ;*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SPMSC1_LVDRE:       equ    3                                         ; Low-Voltage Detect Reset Enable
SPMSC1_SAFE:        equ    4                                         ; SAFE System from interrupts
SPMSC1_LVDIE:       equ    5                                         ; Low-Voltage Detect Interrrupt Enable
SPMSC1_LVDACK:      equ    6                                         ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF:        equ    7                                         ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_LVDRE:      equ    %00001000
mSPMSC1_SAFE:       equ    %00010000
mSPMSC1_LVDIE:      equ    %00100000
mSPMSC1_LVDACK:     equ    %01000000
mSPMSC1_LVDF:       equ    %10000000


;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***
SPMSC2:             equ    $0000180A                                ;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC:        equ    0                                         ; Partial Power Down Control
SPMSC2_PDC:         equ    1                                         ; Power Down Control
SPMSC2_PPDACK:      equ    2                                         ; Partial Power Down Acknowlege
SPMSC2_PPDF:        equ    3                                         ; Partial Power Down Flag
SPMSC2_LVWACK:      equ    6                                         ; Low-Voltage Warning Acknowlege
SPMSC2_LVWF:        equ    7                                         ; Low-Voltage Warning Flag
; bit position masks
mSPMSC2_PPDC:       equ    %00000001
mSPMSC2_PDC:        equ    %00000010
mSPMSC2_PPDACK:     equ    %00000100
mSPMSC2_PPDF:       equ    %00001000
mSPMSC2_LVWACK:     equ    %01000000
mSPMSC2_LVWF:       equ    %10000000


;*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***
DBGCAH:             equ    $00001810                                ;*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
DBGF_Bit0:          equ    0                                         ; Debug FIFO Bit 0
DBGF_Bit1:          equ    1                                         ; Debug FIFO Bit 1
DBGF_Bit2:          equ    2                                         ; Debug FIFO Bit 2
DBGF_Bit3:          equ    3                                         ; Debug FIFO Bit 3
DBGF_Bit4:          equ    4                                         ; Debug FIFO Bit 4
DBGF_Bit5:          equ    5                                         ; Debug FIFO Bit 5
DBGF_Bit6:          equ    6                                         ; Debug FIFO Bit 6
DBGF_Bit7:          equ    7                                         ; Debug FIFO Bit 7
DBGF_Bit8:          equ    8                                         ; Debug FIFO Bit 8
DBGF_Bit9:          equ    9                                         ; Debug FIFO Bit 9
DBGF_Bit10:         equ    10                                        ; Debug FIFO Bit 10
DBGF_Bit11:         equ    11                                        ; Debug FIFO Bit 11
DBGF_Bit12:         equ    12                                        ; Debug FIFO Bit 12
DBGF_Bit13:         equ    13                                        ; Debug FIFO Bit 13
DBGF_Bit14:         equ    14                                        ; Debug FIFO Bit 14
DBGF_Bit15:         equ    15                                        ; Debug FIFO Bit 15
; bit position masks
mDBGF_Bit0:         equ    %00000001
mDBGF_Bit1:         equ    %00000010
mDBGF_Bit2:         equ    %00000100
mDBGF_Bit3:         equ    %00001000
mDBGF_Bit4:         equ    %00010000
mDBGF_Bit5:         equ    %00100000
mDBGF_Bit6:         equ    %01000000
mDBGF_Bit7:         equ    %10000000
mDBGF_Bit8:         equ    %100000000
mDBGF_Bit9:         equ    %1000000000
mDBGF_Bit10:        equ    %10000000000
mDBGF_Bit11:        equ    %100000000000
mDBGF_Bit12:        equ    %1000000000000
mDBGF_Bit13:        equ    %10000000000000
mDBGF_Bit14:        equ    %100000000000000
mDBGF_Bit15:        equ    %1000000000000000


;*** DBGFH - Debug FIFO High Register; 0x00001814 ***
DBGFH:              equ    $00001814                                ;*** DBGFH - Debug FIFO High Register; 0x00001814 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***
FCDIV:              equ    $00001820                                ;*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** FOPT - FLASH Options Register; 0x00001821 ***
FOPT:               equ    $00001821                                ;*** FOPT - FLASH Options Register; 0x00001821 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
FOPT_SEC00:         equ    0                                         ; Security State Code Bit 0
FOPT_SEC01:         equ    1                                         ; Security State Code Bit 1
FOPT_FNORED:        equ    6                                         ; Vector Redirection Disable
FOPT_KEYEN:         equ    7                                         ; Backdoor Key Mechanism Enable
; bit position masks
mFOPT_SEC00:        equ    %00000001
mFOPT_SEC01:        equ    %00000010
mFOPT_FNORED:       equ    %01000000
mFOPT_KEYEN:        equ    %10000000


;*** FCNFG - FLASH Configuration Register; 0x00001823 ***
FCNFG:              equ    $00001823                                ;*** FCNFG - FLASH Configuration Register; 0x00001823 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC:       equ    5                                         ; Enable Writing of Access Key
; bit position masks
mFCNFG_KEYACC:      equ    %00100000


;*** FPROT - FLASH Protection Register; 0x00001824 ***
FPROT:              equ    $00001824                                ;*** FPROT - FLASH Protection Register; 0x00001824 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
FPROT_FPS0:         equ    3                                         ; FLASH Protect Size Select Bit 0
FPROT_FPS1:         equ    4                                         ; FLASH Protect Size Select Bit 1
FPROT_FPS2:         equ    5                                         ; FLASH Protect Size Select Bit 2
FPROT_FPDIS:        equ    6                                         ; FLASH Protection Disable
FPROT_FPOPEN:       equ    7                                         ; Open Unprotected FLASH for Program/Erase
; bit position masks
mFPROT_FPS0:        equ    %00001000
mFPROT_FPS1:        equ    %00010000
mFPROT_FPS2:        equ    %00100000
mFPROT_FPDIS:       equ    %01000000
mFPROT_FPOPEN:      equ    %10000000


;*** FSTAT - FLASH Status Register; 0x00001825 ***
FSTAT:              equ    $00001825                                ;*** FSTAT - FLASH Status Register; 0x00001825 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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


;*** FCMD - FLASH Command Register; 0x00001826 ***
FCMD:               equ    $00001826                                ;*** FCMD - FLASH Command Register; 0x00001826 ***
; bit numbers for user in BCLR, BSET, BRCLR and BRSET
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







; command codes
mBlank:     equ   $05         ;Blank Check command
mByteProg:  equ   $20         ;Byte Program command
mBurstProg: equ   $25         ;Burst Program command
mPageErase: equ   $40         ;Page Erase command
mMassErase: equ   $41         ;Mass Erase command



; bit position masks
mFCBEF:     equ   %10000000   ;flash command buffer empty flag
mFCCF:      equ   %01000000   ;flash command complete flag
mFPVIOL:    equ   %00100000   ;flash protection violation
mFACCERR:   equ   %00010000   ;flash access error
mFBLANK:    equ   %00000100   ;flash verified as all blank (erased =$ff) flag
