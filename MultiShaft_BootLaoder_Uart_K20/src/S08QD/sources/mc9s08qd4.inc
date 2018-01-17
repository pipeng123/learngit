; Based on CPU DB MC9S08QD4_8, version 2.87.007 (RegistersPrg V2.08)

; ###################################################################
;     Filename  : mc9s08qd4.inc
;     Processor : MC9S08QD4VEDE
;     FileFormat: V2.08
;     DataSheet : MC9S08QD4 Rev. 0.8 26/6/2006
;     Compiler  : CodeWarrior compiler
;     Date/Time : 11.07.2006, 14:48
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
;               - Revision is not related to this file (CPU family)
;      - 17.12.2005, V2.02 :
;               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
;      - 16.01.2006, V2.03 :
;               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
;               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
;      - 08.03.2006, V2.04 :
;               - Support for bit(s) names duplicated with any register name in .h header files
;      - 24.03.2006, V2.05 :
;               - Revision is not related to this file (CPU family)
;      - 26.04.2006, V2.06 :
;               - Absolute assembly supported (depreciated symbols are not defined)
;      - 27.04.2006, V2.07 :
;               - Fixed macro __RESET_WATCHDOG for HCS12, HCS12X ,HCS08 DZ and HCS08 EN derivatives (write 0x55,0xAA).
;      - 07.06.2006, V2.08 :
;               - For .inc files added constants "RAMStart" and "RAMEnd" even there is only Z_RAM.
;
;     CPU Registers Revisions:
;               - none
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROMStart:           equ   $0000F000
ROMEnd:             equ   $0000FFAD
Z_RAMStart:         equ   $00000060
Z_RAMEnd:           equ   $000000FF
RAMStart:           equ   $00000100
RAMEnd:             equ   $0000015F
ROM1Start:          equ   $0000FFC0
ROM1End:            equ   $0000FFCF
;
Vrti:               equ   $0000FFD0
Reserved1:          equ   $0000FFD2
Reserved2:          equ   $0000FFD4
Reserved3:          equ   $0000FFD6
Vadc1:              equ   $0000FFD8
Vkeyboard1:         equ   $0000FFDA
Reserved6:          equ   $0000FFDC
Reserved7:          equ   $0000FFDE
Reserved8:          equ   $0000FFE0
Reserved9:          equ   $0000FFE2
Reserved10:         equ   $0000FFE4
Reserved11:         equ   $0000FFE6
Reserved12:         equ   $0000FFE8
Vtpm2ovf:           equ   $0000FFEA
Reserved14:         equ   $0000FFEC
Vtpm2ch0:           equ   $0000FFEE
Vtpm1ovf:           equ   $0000FFF0
Vtpm1ch1:           equ   $0000FFF2
Vtpm1ch0:           equ   $0000FFF4
Reserved19:         equ   $0000FFF6
Virq:               equ   $0000FFF8
Vlvd:               equ   $0000FFFA
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
; bit position masks
mPTAD_PTAD0:        equ    %00000001
mPTAD_PTAD1:        equ    %00000010
mPTAD_PTAD2:        equ    %00000100
mPTAD_PTAD3:        equ    %00001000
mPTAD_PTAD4:        equ    %00010000
mPTAD_PTAD5:        equ    %00100000


;*** PTADD - Data Direction Register A; 0x00000001 ***
PTADD:              equ    $00000001                                ;*** PTADD - Data Direction Register A; 0x00000001 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0:       equ    0                                         ; Data Direction for Port A Bit 0
PTADD_PTADD1:       equ    1                                         ; Data Direction for Port A Bit 1
PTADD_PTADD2:       equ    2                                         ; Data Direction for Port A Bit 2
PTADD_PTADD3:       equ    3                                         ; Data Direction for Port A Bit 3
PTADD_PTADD4:       equ    4                                         ; Data Direction for Port A Bit 4
PTADD_PTADD5:       equ    5                                         ; Data Direction for Port A Bit 5
; bit position masks
mPTADD_PTADD0:      equ    %00000001
mPTADD_PTADD1:      equ    %00000010
mPTADD_PTADD2:      equ    %00000100
mPTADD_PTADD3:      equ    %00001000
mPTADD_PTADD4:      equ    %00010000
mPTADD_PTADD5:      equ    %00100000


;*** KBISC - KBI Status and Control; 0x0000000C ***
KBISC:              equ    $0000000C                                ;*** KBISC - KBI Status and Control; 0x0000000C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBISC_KBIMOD:       equ    0                                         ; Keyboard Detection Mode
KBISC_KBIE:         equ    1                                         ; Keyboard Interrupt Enable
KBISC_KBACK:        equ    2                                         ; Keyboard Interrupt Acknowledge
KBISC_KBF:          equ    3                                         ; Keyboard Interrupt Flag
; bit position masks
mKBISC_KBIMOD:      equ    %00000001
mKBISC_KBIE:        equ    %00000010
mKBISC_KBACK:       equ    %00000100
mKBISC_KBF:         equ    %00001000


;*** KBIPE - KBI Pin Enable Register; 0x0000000D ***
KBIPE:              equ    $0000000D                                ;*** KBIPE - KBI Pin Enable Register; 0x0000000D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPE_KBIPE0:       equ    0                                         ; Keyboard Pin Enable for Port A Bit 0
KBIPE_KBIPE1:       equ    1                                         ; Keyboard Pin Enable for Port A Bit 1
KBIPE_KBIPE2:       equ    2                                         ; Keyboard Pin Enable for Port A Bit 2
KBIPE_KBIPE3:       equ    3                                         ; Keyboard Pin Enable for Port A Bit 3
KBIPE_KBIPE4:       equ    4                                         ; Keyboard Pin Enable for Port A Bit 4
KBIPE_KBIPE5:       equ    5                                         ; Keyboard Pin Enable for Port A Bit 5
KBIPE_KBIPE6:       equ    6                                         ; Keyboard Pin Enable for Port A Bit 6
KBIPE_KBIPE7:       equ    7                                         ; Keyboard Pin Enable for Port A Bit 7
; bit position masks
mKBIPE_KBIPE0:      equ    %00000001
mKBIPE_KBIPE1:      equ    %00000010
mKBIPE_KBIPE2:      equ    %00000100
mKBIPE_KBIPE3:      equ    %00001000
mKBIPE_KBIPE4:      equ    %00010000
mKBIPE_KBIPE5:      equ    %00100000
mKBIPE_KBIPE6:      equ    %01000000
mKBIPE_KBIPE7:      equ    %10000000


;*** KBIES - KBI Edge Select Register; 0x0000000E ***
KBIES:              equ    $0000000E                                ;*** KBIES - KBI Edge Select Register; 0x0000000E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIES_KBEDG0:       equ    0                                         ; Keyboard Edge Select Bit 0
KBIES_KBEDG1:       equ    1                                         ; Keyboard Edge Select Bit 1
KBIES_KBEDG2:       equ    2                                         ; Keyboard Edge Select Bit 2
KBIES_KBEDG3:       equ    3                                         ; Keyboard Edge Select Bit 3
KBIES_KBEDG4:       equ    4                                         ; Keyboard Edge Select Bit 4
KBIES_KBEDG5:       equ    5                                         ; Keyboard Edge Select Bit 5
KBIES_KBEDG6:       equ    6                                         ; Keyboard Edge Select Bit 6
KBIES_KBEDG7:       equ    7                                         ; Keyboard Edge Select Bit 7
; bit position masks
mKBIES_KBEDG0:      equ    %00000001
mKBIES_KBEDG1:      equ    %00000010
mKBIES_KBEDG2:      equ    %00000100
mKBIES_KBEDG3:      equ    %00001000
mKBIES_KBEDG4:      equ    %00010000
mKBIES_KBEDG5:      equ    %00100000
mKBIES_KBEDG6:      equ    %01000000
mKBIES_KBEDG7:      equ    %10000000


;*** IRQSC - Interrupt Request Status and Control Register; 0x0000000F ***
IRQSC:              equ    $0000000F                                ;*** IRQSC - Interrupt Request Status and Control Register; 0x0000000F ***
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


;*** ADC1SC1 - Status and Control Register; 0x00000010 ***
ADC1SC1:            equ    $00000010                                ;*** ADC1SC1 - Status and Control Register; 0x00000010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC1_ADCH0:      equ    0                                         ; Input Channel Select Bit 0
ADC1SC1_ADCH1:      equ    1                                         ; Input Channel Select Bit 1
ADC1SC1_ADCH2:      equ    2                                         ; Input Channel Select Bit 2
ADC1SC1_ADCH3:      equ    3                                         ; Input Channel Select Bit 3
ADC1SC1_ADCH4:      equ    4                                         ; Input Channel Select Bit 4
ADC1SC1_ADCO:       equ    5                                         ; Continuous Conversion Enable
ADC1SC1_AIEN:       equ    6                                         ; Interrupt Enable
ADC1SC1_COCO:       equ    7                                         ; Conversion Complete Flag
; bit position masks
mADC1SC1_ADCH0:     equ    %00000001
mADC1SC1_ADCH1:     equ    %00000010
mADC1SC1_ADCH2:     equ    %00000100
mADC1SC1_ADCH3:     equ    %00001000
mADC1SC1_ADCH4:     equ    %00010000
mADC1SC1_ADCO:      equ    %00100000
mADC1SC1_AIEN:      equ    %01000000
mADC1SC1_COCO:      equ    %10000000


;*** ADC1SC2 - Status and Control Register 2; 0x00000011 ***
ADC1SC2:            equ    $00000011                                ;*** ADC1SC2 - Status and Control Register 2; 0x00000011 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC2_ACFGT:      equ    4                                         ; Compare Function Greater Than Enable
ADC1SC2_ACFE:       equ    5                                         ; Compare Function Enable
ADC1SC2_ADTRG:      equ    6                                         ; Conversion Trigger Select
ADC1SC2_ADACT:      equ    7                                         ; Conversion Active
; bit position masks
mADC1SC2_ACFGT:     equ    %00010000
mADC1SC2_ACFE:      equ    %00100000
mADC1SC2_ADTRG:     equ    %01000000
mADC1SC2_ADACT:     equ    %10000000


;*** ADC1R - ADC10 Result Data Right Justified; 0x00000012 ***
ADC1R:              equ    $00000012                                ;*** ADC1R - ADC10 Result Data Right Justified; 0x00000012 ***


;*** ADC1RH - ADC10 Result Data Right Justified High; 0x00000012 ***
ADC1RH:             equ    $00000012                                ;*** ADC1RH - ADC10 Result Data Right Justified High; 0x00000012 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RH_ADR8:        equ    0                                         ; ADC10 Result Data Bit 8
ADC1RH_ADR9:        equ    1                                         ; ADC10 Result Data Bit 9
; bit position masks
mADC1RH_ADR8:       equ    %00000001
mADC1RH_ADR9:       equ    %00000010


;*** ADC1RL - ADC10 Result Data Right Justified Low; 0x00000013 ***
ADC1RL:             equ    $00000013                                ;*** ADC1RL - ADC10 Result Data Right Justified Low; 0x00000013 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RL_ADR0:        equ    0                                         ; ADC10 Result Data Bit 0
ADC1RL_ADR1:        equ    1                                         ; ADC10 Result Data Bit 1
ADC1RL_ADR2:        equ    2                                         ; ADC10 Result Data Bit 2
ADC1RL_ADR3:        equ    3                                         ; ADC10 Result Data Bit 3
ADC1RL_ADR4:        equ    4                                         ; ADC10 Result Data Bit 4
ADC1RL_ADR5:        equ    5                                         ; ADC10 Result Data Bit 5
ADC1RL_ADR6:        equ    6                                         ; ADC10 Result Data Bit 6
ADC1RL_ADR7:        equ    7                                         ; ADC10 Result Data Bit 7
; bit position masks
mADC1RL_ADR0:       equ    %00000001
mADC1RL_ADR1:       equ    %00000010
mADC1RL_ADR2:       equ    %00000100
mADC1RL_ADR3:       equ    %00001000
mADC1RL_ADR4:       equ    %00010000
mADC1RL_ADR5:       equ    %00100000
mADC1RL_ADR6:       equ    %01000000
mADC1RL_ADR7:       equ    %10000000


;*** ADC1CV - Compare Value Register; 0x00000014 ***
ADC1CV:             equ    $00000014                                ;*** ADC1CV - Compare Value Register; 0x00000014 ***


;*** ADC1CVH - Compare Value Register High; 0x00000014 ***
ADC1CVH:            equ    $00000014                                ;*** ADC1CVH - Compare Value Register High; 0x00000014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CVH_ADCV8:      equ    0                                         ; Compare Function Value 8
ADC1CVH_ADCV9:      equ    1                                         ; Compare Function Value 9
; bit position masks
mADC1CVH_ADCV8:     equ    %00000001
mADC1CVH_ADCV9:     equ    %00000010


;*** ADC1CVL - Compare Value Register Low; 0x00000015 ***
ADC1CVL:            equ    $00000015                                ;*** ADC1CVL - Compare Value Register Low; 0x00000015 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CVL_ADCV0:      equ    0                                         ; Compare Function Value 0
ADC1CVL_ADCV1:      equ    1                                         ; Compare Function Value 1
ADC1CVL_ADCV2:      equ    2                                         ; Compare Function Value 2
ADC1CVL_ADCV3:      equ    3                                         ; Compare Function Value 3
ADC1CVL_ADCV4:      equ    4                                         ; Compare Function Value 4
ADC1CVL_ADCV5:      equ    5                                         ; Compare Function Value 5
ADC1CVL_ADCV6:      equ    6                                         ; Compare Function Value 6
ADC1CVL_ADCV7:      equ    7                                         ; Compare Function Value 7
; bit position masks
mADC1CVL_ADCV0:     equ    %00000001
mADC1CVL_ADCV1:     equ    %00000010
mADC1CVL_ADCV2:     equ    %00000100
mADC1CVL_ADCV3:     equ    %00001000
mADC1CVL_ADCV4:     equ    %00010000
mADC1CVL_ADCV5:     equ    %00100000
mADC1CVL_ADCV6:     equ    %01000000
mADC1CVL_ADCV7:     equ    %10000000


;*** ADC1CFG - Configuration Register; 0x00000016 ***
ADC1CFG:            equ    $00000016                                ;*** ADC1CFG - Configuration Register; 0x00000016 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CFG_ADICLK0:    equ    0                                         ; Input Clock Select Bit 0
ADC1CFG_ADICLK1:    equ    1                                         ; Input Clock Select Bit 1
ADC1CFG_MODE0:      equ    2                                         ; Conversion Mode Selection Bit 0
ADC1CFG_MODE1:      equ    3                                         ; Conversion Mode Selection Bit 1
ADC1CFG_ADLSMP:     equ    4                                         ; Long Sample Time Configuration
ADC1CFG_ADIV0:      equ    5                                         ; Clock Divide Select Bit 0
ADC1CFG_ADIV1:      equ    6                                         ; Clock Divide Select Bit 1
ADC1CFG_ADLPC:      equ    7                                         ; Low Power Configuration
; bit position masks
mADC1CFG_ADICLK0:   equ    %00000001
mADC1CFG_ADICLK1:   equ    %00000010
mADC1CFG_MODE0:     equ    %00000100
mADC1CFG_MODE1:     equ    %00001000
mADC1CFG_ADLSMP:    equ    %00010000
mADC1CFG_ADIV0:     equ    %00100000
mADC1CFG_ADIV1:     equ    %01000000
mADC1CFG_ADLPC:     equ    %10000000


;*** APCTL1 - ADC10 Pin Control 1 Register; 0x00000017 ***
APCTL1:             equ    $00000017                                ;*** APCTL1 - ADC10 Pin Control 1 Register; 0x00000017 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL1_ADPC0:       equ    0                                         ; ADC10 Pin Control 0
APCTL1_ADPC1:       equ    1                                         ; ADC10 Pin Control 1
APCTL1_ADPC2:       equ    2                                         ; ADC10 Pin Control 2
APCTL1_ADPC3:       equ    3                                         ; ADC10 Pin Control 3
; bit position masks
mAPCTL1_ADPC0:      equ    %00000001
mAPCTL1_ADPC1:      equ    %00000010
mAPCTL1_ADPC2:      equ    %00000100
mAPCTL1_ADPC3:      equ    %00001000


;*** TPM2SC - TPM2 Timer Status and Control Register; 0x00000020 ***
TPM2SC:             equ    $00000020                                ;*** TPM2SC - TPM2 Timer Status and Control Register; 0x00000020 ***
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


;*** TPM2CNT - TPM2 Counter Register; 0x00000021 ***
TPM2CNT:            equ    $00000021                                ;*** TPM2CNT - TPM2 Counter Register; 0x00000021 ***


;*** TPM2CNTH - TPM2 Counter Register High; 0x00000021 ***
TPM2CNTH:           equ    $00000021                                ;*** TPM2CNTH - TPM2 Counter Register High; 0x00000021 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2CNTH_BIT8:      equ    0                                         ; TPM2 Counter Bit 8
TPM2CNTH_BIT9:      equ    1                                         ; TPM2 Counter Bit 9
TPM2CNTH_BIT10:     equ    2                                         ; TPM2 Counter Bit 10
TPM2CNTH_BIT11:     equ    3                                         ; TPM2 Counter Bit 11
TPM2CNTH_BIT12:     equ    4                                         ; TPM2 Counter Bit 12
TPM2CNTH_BIT13:     equ    5                                         ; TPM2 Counter Bit 13
TPM2CNTH_BIT14:     equ    6                                         ; TPM2 Counter Bit 14
TPM2CNTH_BIT15:     equ    7                                         ; TPM2 Counter Bit 15
; bit position masks
mTPM2CNTH_BIT8:     equ    %00000001
mTPM2CNTH_BIT9:     equ    %00000010
mTPM2CNTH_BIT10:    equ    %00000100
mTPM2CNTH_BIT11:    equ    %00001000
mTPM2CNTH_BIT12:    equ    %00010000
mTPM2CNTH_BIT13:    equ    %00100000
mTPM2CNTH_BIT14:    equ    %01000000
mTPM2CNTH_BIT15:    equ    %10000000


;*** TPM2CNTL - TPM2 Counter Register Low; 0x00000022 ***
TPM2CNTL:           equ    $00000022                                ;*** TPM2CNTL - TPM2 Counter Register Low; 0x00000022 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2CNTL_BIT0:      equ    0                                         ; TPM2 Counter Bit 0
TPM2CNTL_BIT1:      equ    1                                         ; TPM2 Counter Bit 1
TPM2CNTL_BIT2:      equ    2                                         ; TPM2 Counter Bit 2
TPM2CNTL_BIT3:      equ    3                                         ; TPM2 Counter Bit 3
TPM2CNTL_BIT4:      equ    4                                         ; TPM2 Counter Bit 4
TPM2CNTL_BIT5:      equ    5                                         ; TPM2 Counter Bit 5
TPM2CNTL_BIT6:      equ    6                                         ; TPM2 Counter Bit 6
TPM2CNTL_BIT7:      equ    7                                         ; TPM2 Counter Bit 7
; bit position masks
mTPM2CNTL_BIT0:     equ    %00000001
mTPM2CNTL_BIT1:     equ    %00000010
mTPM2CNTL_BIT2:     equ    %00000100
mTPM2CNTL_BIT3:     equ    %00001000
mTPM2CNTL_BIT4:     equ    %00010000
mTPM2CNTL_BIT5:     equ    %00100000
mTPM2CNTL_BIT6:     equ    %01000000
mTPM2CNTL_BIT7:     equ    %10000000


;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x00000023 ***
TPM2MOD:            equ    $00000023                                ;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x00000023 ***


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x00000023 ***
TPM2MODH:           equ    $00000023                                ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x00000023 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2MODH_BIT8:      equ    0                                         ; Timer Counter Modulo Bit 8
TPM2MODH_BIT9:      equ    1                                         ; Timer Counter Modulo Bit 9
TPM2MODH_BIT10:     equ    2                                         ; Timer Counter Modulo Bit 10
TPM2MODH_BIT11:     equ    3                                         ; Timer Counter Modulo Bit 11
TPM2MODH_BIT12:     equ    4                                         ; Timer Counter Modulo Bit 12
TPM2MODH_BIT13:     equ    5                                         ; Timer Counter Modulo Bit 13
TPM2MODH_BIT14:     equ    6                                         ; Timer Counter Modulo Bit 14
TPM2MODH_BIT15:     equ    7                                         ; Timer Counter Modulo Bit 15
; bit position masks
mTPM2MODH_BIT8:     equ    %00000001
mTPM2MODH_BIT9:     equ    %00000010
mTPM2MODH_BIT10:    equ    %00000100
mTPM2MODH_BIT11:    equ    %00001000
mTPM2MODH_BIT12:    equ    %00010000
mTPM2MODH_BIT13:    equ    %00100000
mTPM2MODH_BIT14:    equ    %01000000
mTPM2MODH_BIT15:    equ    %10000000


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x00000024 ***
TPM2MODL:           equ    $00000024                                ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x00000024 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2MODL_BIT0:      equ    0                                         ; Timer Counter Modulo Bit 0
TPM2MODL_BIT1:      equ    1                                         ; Timer Counter Modulo Bit 1
TPM2MODL_BIT2:      equ    2                                         ; Timer Counter Modulo Bit 2
TPM2MODL_BIT3:      equ    3                                         ; Timer Counter Modulo Bit 3
TPM2MODL_BIT4:      equ    4                                         ; Timer Counter Modulo Bit 4
TPM2MODL_BIT5:      equ    5                                         ; Timer Counter Modulo Bit 5
TPM2MODL_BIT6:      equ    6                                         ; Timer Counter Modulo Bit 6
TPM2MODL_BIT7:      equ    7                                         ; Timer Counter Modulo Bit 7
; bit position masks
mTPM2MODL_BIT0:     equ    %00000001
mTPM2MODL_BIT1:     equ    %00000010
mTPM2MODL_BIT2:     equ    %00000100
mTPM2MODL_BIT3:     equ    %00001000
mTPM2MODL_BIT4:     equ    %00010000
mTPM2MODL_BIT5:     equ    %00100000
mTPM2MODL_BIT6:     equ    %01000000
mTPM2MODL_BIT7:     equ    %10000000


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x00000025 ***
TPM2C0SC:           equ    $00000025                                ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x00000025 ***
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


;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x00000026 ***
TPM2C0V:            equ    $00000026                                ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x00000026 ***


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x00000026 ***
TPM2C0VH:           equ    $00000026                                ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x00000026 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C0VH_BIT8:      equ    0                                         ; Timer Channel 0 Value Bit 8
TPM2C0VH_BIT9:      equ    1                                         ; Timer Channel 0 Value Bit 9
TPM2C0VH_BIT10:     equ    2                                         ; Timer Channel 0 Value Bit 10
TPM2C0VH_BIT11:     equ    3                                         ; Timer Channel 0 Value Bit 11
TPM2C0VH_BIT12:     equ    4                                         ; Timer Channel 0 Value Bit 12
TPM2C0VH_BIT13:     equ    5                                         ; Timer Channel 0 Value Bit 13
TPM2C0VH_BIT14:     equ    6                                         ; Timer Channel 0 Value Bit 14
TPM2C0VH_BIT15:     equ    7                                         ; Timer Channel 0 Value Bit 15
; bit position masks
mTPM2C0VH_BIT8:     equ    %00000001
mTPM2C0VH_BIT9:     equ    %00000010
mTPM2C0VH_BIT10:    equ    %00000100
mTPM2C0VH_BIT11:    equ    %00001000
mTPM2C0VH_BIT12:    equ    %00010000
mTPM2C0VH_BIT13:    equ    %00100000
mTPM2C0VH_BIT14:    equ    %01000000
mTPM2C0VH_BIT15:    equ    %10000000


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x00000027 ***
TPM2C0VL:           equ    $00000027                                ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x00000027 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C0VL_BIT0:      equ    0                                         ; Timer Channel 0 Value Bit 0
TPM2C0VL_BIT1:      equ    1                                         ; Timer Channel 0 Value Bit 1
TPM2C0VL_BIT2:      equ    2                                         ; Timer Channel 0 Value Bit 2
TPM2C0VL_BIT3:      equ    3                                         ; Timer Channel 0 Value Bit 3
TPM2C0VL_BIT4:      equ    4                                         ; Timer Channel 0 Value Bit 4
TPM2C0VL_BIT5:      equ    5                                         ; Timer Channel 0 Value Bit 5
TPM2C0VL_BIT6:      equ    6                                         ; Timer Channel 0 Value Bit 6
TPM2C0VL_BIT7:      equ    7                                         ; Timer Channel 0 Value Bit 7
; bit position masks
mTPM2C0VL_BIT0:     equ    %00000001
mTPM2C0VL_BIT1:     equ    %00000010
mTPM2C0VL_BIT2:     equ    %00000100
mTPM2C0VL_BIT3:     equ    %00001000
mTPM2C0VL_BIT4:     equ    %00010000
mTPM2C0VL_BIT5:     equ    %00100000
mTPM2C0VL_BIT6:     equ    %01000000
mTPM2C0VL_BIT7:     equ    %10000000


;*** ICSC1 - ICS Control Register 1; 0x00000038 ***
ICSC1:              equ    $00000038                                ;*** ICSC1 - ICS Control Register 1; 0x00000038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC1_IREFSTEN:     equ    0                                         ; Internal Reference Stop Enable
ICSC1_CLKS:         equ    6                                         ; Clock Source Select
; bit position masks
mICSC1_IREFSTEN:    equ    %00000001
mICSC1_CLKS:        equ    %01000000


;*** ICSC2 - ICS Control Register 2; 0x00000039 ***
ICSC2:              equ    $00000039                                ;*** ICSC2 - ICS Control Register 2; 0x00000039 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC2_LP:           equ    3                                         ; Low Power Select
ICSC2_BDIV0:        equ    6                                         ; Bus Frequency Divider, bit 0
ICSC2_BDIV1:        equ    7                                         ; Bus Frequency Divider, bit 1
; bit position masks
mICSC2_LP:          equ    %00001000
mICSC2_BDIV0:       equ    %01000000
mICSC2_BDIV1:       equ    %10000000


;*** ICSTRM - ICS Trim Register; 0x0000003A ***
ICSTRM:             equ    $0000003A                                ;*** ICSTRM - ICS Trim Register; 0x0000003A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM0:       equ    0                                         ; ICS Trim Setting, bit 0
ICSTRM_TRIM1:       equ    1                                         ; ICS Trim Setting, bit 1
ICSTRM_TRIM2:       equ    2                                         ; ICS Trim Setting, bit 2
ICSTRM_TRIM3:       equ    3                                         ; ICS Trim Setting, bit 3
ICSTRM_TRIM4:       equ    4                                         ; ICS Trim Setting, bit 4
ICSTRM_TRIM5:       equ    5                                         ; ICS Trim Setting, bit 5
ICSTRM_TRIM6:       equ    6                                         ; ICS Trim Setting, bit 6
ICSTRM_TRIM7:       equ    7                                         ; ICS Trim Setting, bit 7
; bit position masks
mICSTRM_TRIM0:      equ    %00000001
mICSTRM_TRIM1:      equ    %00000010
mICSTRM_TRIM2:      equ    %00000100
mICSTRM_TRIM3:      equ    %00001000
mICSTRM_TRIM4:      equ    %00010000
mICSTRM_TRIM5:      equ    %00100000
mICSTRM_TRIM6:      equ    %01000000
mICSTRM_TRIM7:      equ    %10000000


;*** ICSSC - ICS Status and Control; 0x0000003B ***
ICSSC:              equ    $0000003B                                ;*** ICSSC - ICS Status and Control; 0x0000003B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM:        equ    0                                         ; ICS Fine Trim
ICSSC_CLKST:        equ    2                                         ; Clock Mode Status
; bit position masks
mICSSC_FTRIM:       equ    %00000001
mICSSC_CLKST:       equ    %00000100


;*** TPMSC - TPM Timer Status and Control Register; 0x00000040 ***
TPMSC:              equ    $00000040                                ;*** TPMSC - TPM Timer Status and Control Register; 0x00000040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMSC_PS0:          equ    0                                         ; Prescale Divisor Select Bit 0
TPMSC_PS1:          equ    1                                         ; Prescale Divisor Select Bit 1
TPMSC_PS2:          equ    2                                         ; Prescale Divisor Select Bit 2
TPMSC_CLKSA:        equ    3                                         ; Clock Source Select A
TPMSC_CLKSB:        equ    4                                         ; Clock Source Select B
TPMSC_CPWMS:        equ    5                                         ; Center-Aligned PWM Select
TPMSC_TOIE:         equ    6                                         ; Timer Overflow Interrupt Enable
TPMSC_TOF:          equ    7                                         ; Timer Overflow Flag
; bit position masks
mTPMSC_PS0:         equ    %00000001
mTPMSC_PS1:         equ    %00000010
mTPMSC_PS2:         equ    %00000100
mTPMSC_CLKSA:       equ    %00001000
mTPMSC_CLKSB:       equ    %00010000
mTPMSC_CPWMS:       equ    %00100000
mTPMSC_TOIE:        equ    %01000000
mTPMSC_TOF:         equ    %10000000


;*** TPMCNT - TPM Counter Register; 0x00000041 ***
TPMCNT:             equ    $00000041                                ;*** TPMCNT - TPM Counter Register; 0x00000041 ***


;*** TPMCNTH - TPM Counter Register High; 0x00000041 ***
TPMCNTH:            equ    $00000041                                ;*** TPMCNTH - TPM Counter Register High; 0x00000041 ***


;*** TPMCNTL - TPM Counter Register Low; 0x00000042 ***
TPMCNTL:            equ    $00000042                                ;*** TPMCNTL - TPM Counter Register Low; 0x00000042 ***


;*** TPMMOD - TPM Timer Counter Modulo Register; 0x00000043 ***
TPMMOD:             equ    $00000043                                ;*** TPMMOD - TPM Timer Counter Modulo Register; 0x00000043 ***


;*** TPMMODH - TPM Timer Counter Modulo Register High; 0x00000043 ***
TPMMODH:            equ    $00000043                                ;*** TPMMODH - TPM Timer Counter Modulo Register High; 0x00000043 ***


;*** TPMMODL - TPM Timer Counter Modulo Register Low; 0x00000044 ***
TPMMODL:            equ    $00000044                                ;*** TPMMODL - TPM Timer Counter Modulo Register Low; 0x00000044 ***


;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register; 0x00000045 ***
TPMC0SC:            equ    $00000045                                ;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register; 0x00000045 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMC0SC_ELS0A:      equ    2                                         ; Edge/Level Select Bit A
TPMC0SC_ELS0B:      equ    3                                         ; Edge/Level Select Bit B
TPMC0SC_MS0A:       equ    4                                         ; Mode Select A for TPM Channel 0
TPMC0SC_MS0B:       equ    5                                         ; Mode Select B for TPM Channel 0
TPMC0SC_CH0IE:      equ    6                                         ; Channel 0 Interrupt Enable
TPMC0SC_CH0F:       equ    7                                         ; Channel 0 Flag
; bit position masks
mTPMC0SC_ELS0A:     equ    %00000100
mTPMC0SC_ELS0B:     equ    %00001000
mTPMC0SC_MS0A:      equ    %00010000
mTPMC0SC_MS0B:      equ    %00100000
mTPMC0SC_CH0IE:     equ    %01000000
mTPMC0SC_CH0F:      equ    %10000000


;*** TPMC0V - TPM Timer Channel 0 Value Register; 0x00000046 ***
TPMC0V:             equ    $00000046                                ;*** TPMC0V - TPM Timer Channel 0 Value Register; 0x00000046 ***


;*** TPMC0VH - TPM Timer Channel 0 Value Register High; 0x00000046 ***
TPMC0VH:            equ    $00000046                                ;*** TPMC0VH - TPM Timer Channel 0 Value Register High; 0x00000046 ***


;*** TPMC0VL - TPM Timer Channel 0 Value Register Low; 0x00000047 ***
TPMC0VL:            equ    $00000047                                ;*** TPMC0VL - TPM Timer Channel 0 Value Register Low; 0x00000047 ***


;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register; 0x00000048 ***
TPMC1SC:            equ    $00000048                                ;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register; 0x00000048 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMC1SC_ELS1A:      equ    2                                         ; Edge/Level Select Bit A
TPMC1SC_ELS1B:      equ    3                                         ; Edge/Level Select Bit B
TPMC1SC_MS1A:       equ    4                                         ; Mode Select A for TPM Channel 1
TPMC1SC_MS1B:       equ    5                                         ; Mode Select B for TPM Channel 1
TPMC1SC_CH1IE:      equ    6                                         ; Channel 1 Interrupt Enable
TPMC1SC_CH1F:       equ    7                                         ; Channel 1 Flag
; bit position masks
mTPMC1SC_ELS1A:     equ    %00000100
mTPMC1SC_ELS1B:     equ    %00001000
mTPMC1SC_MS1A:      equ    %00010000
mTPMC1SC_MS1B:      equ    %00100000
mTPMC1SC_CH1IE:     equ    %01000000
mTPMC1SC_CH1F:      equ    %10000000


;*** TPMC1V - TPM Timer Channel 1 Value Register; 0x00000049 ***
TPMC1V:             equ    $00000049                                ;*** TPMC1V - TPM Timer Channel 1 Value Register; 0x00000049 ***


;*** TPMC1VH - TPM Timer Channel 1 Value Register High; 0x00000049 ***
TPMC1VH:            equ    $00000049                                ;*** TPMC1VH - TPM Timer Channel 1 Value Register High; 0x00000049 ***


;*** TPMC1VL - TPM Timer Channel 1 Value Register Low; 0x0000004A ***
TPMC1VL:            equ    $0000004A                                ;*** TPMC1VL - TPM Timer Channel 1 Value Register Low; 0x0000004A ***


;*** SRS - System Reset Status Register; 0x00001800 ***
SRS:                equ    $00001800                                ;*** SRS - System Reset Status Register; 0x00001800 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD:            equ    1                                         ; Low Voltage Detect
SRS_ILAD:           equ    3                                         ; Illegal Address
SRS_ILOP:           equ    4                                         ; Illegal Opcode
SRS_COP:            equ    5                                         ; Computer Operating Properly (COP) Watchdog
SRS_PIN:            equ    6                                         ; External Reset Pin
SRS_POR:            equ    7                                         ; Power-On Reset
; bit position masks
mSRS_LVD:           equ    %00000010
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
SOPT1_RSTPE:        equ    0                                         ; RESET Pin Enable
SOPT1_BKGDPE:       equ    1                                         ; Background Debug Mode Pin Enable
SOPT1_STOPE:        equ    5                                         ; Stop Mode Enable
SOPT1_COPT:         equ    6                                         ; COP Watchdog Timeout
SOPT1_COPE:         equ    7                                         ; COP Watchdog Enable
; bit position masks
mSOPT1_RSTPE:       equ    %00000001
mSOPT1_BKGDPE:      equ    %00000010
mSOPT1_STOPE:       equ    %00100000
mSOPT1_COPT:        equ    %01000000
mSOPT1_COPE:        equ    %10000000


;*** SOPT2 - System Options Register 2; 0x00001803 ***
SOPT2:              equ    $00001803                                ;*** SOPT2 - System Options Register 2; 0x00001803 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_COPCLKS:      equ    7                                         ; COP Watchdog Clock Select
; bit position masks
mSOPT2_COPCLKS:     equ    %10000000


;*** SDID - System Device Identification Register; 0x00001806 ***
SDID:               equ    $00001806                                ;*** SDID - System Device Identification Register; 0x00001806 ***


;*** SDIDH - System Device Identification Register High; 0x00001806 ***
SDIDH:              equ    $00001806                                ;*** SDIDH - System Device Identification Register High; 0x00001806 ***
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


;*** SDIDL - System Device Identification Register Low; 0x00001807 ***
SDIDL:              equ    $00001807                                ;*** SDIDL - System Device Identification Register Low; 0x00001807 ***
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


;*** SRTISC - System RTI Status and Control Register; 0x00001808 ***
SRTISC:             equ    $00001808                                ;*** SRTISC - System RTI Status and Control Register; 0x00001808 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE:        equ    0                                         ; Bandgap Buffer Enable
SPMSC1_LVDE:        equ    2                                         ; Low-Voltage Detect Enable
SPMSC1_LVDSE:       equ    3                                         ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE:       equ    4                                         ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE:       equ    5                                         ; Low-Voltage Detect Interrrupt Enable
SPMSC1_LVDACK:      equ    6                                         ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF:        equ    7                                         ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_BGBE:       equ    %00000001
mSPMSC1_LVDE:       equ    %00000100
mSPMSC1_LVDSE:      equ    %00001000
mSPMSC1_LVDRE:      equ    %00010000
mSPMSC1_LVDIE:      equ    %00100000
mSPMSC1_LVDACK:     equ    %01000000
mSPMSC1_LVDF:       equ    %10000000


;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***
SPMSC2:             equ    $0000180A                                ;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC:        equ    0                                         ; Partial Power Down Control
SPMSC2_PPDACK:      equ    2                                         ; Partial Power Down Acknowledge
SPMSC2_PPDF:        equ    3                                         ; Partial Power Down Flag
SPMSC2_LVWV:        equ    4                                         ; Low-Voltage Warning Voltage Select
SPMSC2_LVDV:        equ    5                                         ; Low-Voltage Detect Voltage Select
SPMSC2_LVWACK:      equ    6                                         ; Low-Voltage Warning Acknowledge
SPMSC2_LVWF:        equ    7                                         ; Low-Voltage Warning Flag
; bit position masks
mSPMSC2_PPDC:       equ    %00000001
mSPMSC2_PPDACK:     equ    %00000100
mSPMSC2_PPDF:       equ    %00001000
mSPMSC2_LVWV:       equ    %00010000
mSPMSC2_LVDV:       equ    %00100000
mSPMSC2_LVWACK:     equ    %01000000
mSPMSC2_LVWF:       equ    %10000000


;*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***
FCDIV:              equ    $00001820                                ;*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***
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


;*** FOPT - FLASH Options Register; 0x00001821 ***
FOPT:               equ    $00001821                                ;*** FOPT - FLASH Options Register; 0x00001821 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
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
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC:       equ    5                                         ; Enable Writing of Access Key
; bit position masks
mFCNFG_KEYACC:      equ    %00100000


;*** FPROT - FLASH Protection Register; 0x00001824 ***
FPROT:              equ    $00001824                                ;*** FPROT - FLASH Protection Register; 0x00001824 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPDIS:        equ    0                                         ; FLASH Protection Disable
FPROT_FPS0:         equ    1                                         ; FLASH Protect Select Bits, bit 0
FPROT_FPS1:         equ    2                                         ; FLASH Protect Select Bits, bit 1
FPROT_FPS2:         equ    3                                         ; FLASH Protect Select Bits, bit 2
FPROT_FPS3:         equ    4                                         ; FLASH Protect Select Bits, bit 3
FPROT_FPS4:         equ    5                                         ; FLASH Protect Select Bits, bit 4
FPROT_FPS5:         equ    6                                         ; FLASH Protect Select Bits, bit 5
FPROT_FPS6:         equ    7                                         ; FLASH Protect Select Bits, bit 6
; bit position masks
mFPROT_FPDIS:       equ    %00000001
mFPROT_FPS0:        equ    %00000010
mFPROT_FPS1:        equ    %00000100
mFPROT_FPS2:        equ    %00001000
mFPROT_FPS3:        equ    %00010000
mFPROT_FPS4:        equ    %00100000
mFPROT_FPS5:        equ    %01000000
mFPROT_FPS6:        equ    %10000000


;*** FSTAT - FLASH Status Register; 0x00001825 ***
FSTAT:              equ    $00001825                                ;*** FSTAT - FLASH Status Register; 0x00001825 ***
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


;*** FCMD - FLASH Command Register; 0x00001826 ***
FCMD:               equ    $00001826                                ;*** FCMD - FLASH Command Register; 0x00001826 ***
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


;*** PTAPE - Port A Internal Pullup Enable; 0x00001840 ***
PTAPE:              equ    $00001840                                ;*** PTAPE - Port A Internal Pullup Enable; 0x00001840 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0:       equ    0                                         ; Internal Pullup Enable for Port A Bit 0
PTAPE_PTAPE1:       equ    1                                         ; Internal Pullup Enable for Port A Bit 1
PTAPE_PTAPE2:       equ    2                                         ; Internal Pullup Enable for Port A Bit 2
PTAPE_PTAPE3:       equ    3                                         ; Internal Pullup Enable for Port A Bit 3
PTAPE_PTAPE4:       equ    4                                         ; Internal Pullup Enable for Port A Bit 4
PTAPE_PTAPE5:       equ    5                                         ; Internal Pullup Enable for Port A Bit 5
; bit position masks
mPTAPE_PTAPE0:      equ    %00000001
mPTAPE_PTAPE1:      equ    %00000010
mPTAPE_PTAPE2:      equ    %00000100
mPTAPE_PTAPE3:      equ    %00001000
mPTAPE_PTAPE4:      equ    %00010000
mPTAPE_PTAPE5:      equ    %00100000


;*** PTASE - Port A Slew Rate Enable; 0x00001841 ***
PTASE:              equ    $00001841                                ;*** PTASE - Port A Slew Rate Enable; 0x00001841 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0:       equ    0                                         ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1:       equ    1                                         ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE2:       equ    2                                         ; Output Slew Rate Enable for Port A Bit 2
PTASE_PTASE3:       equ    3                                         ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4:       equ    4                                         ; Output Slew Rate Enable for Port A Bit 4
PTASE_PTASE5:       equ    5                                         ; Output Slew Rate Enable for Port A Bit 5
; bit position masks
mPTASE_PTASE0:      equ    %00000001
mPTASE_PTASE1:      equ    %00000010
mPTASE_PTASE2:      equ    %00000100
mPTASE_PTASE3:      equ    %00001000
mPTASE_PTASE4:      equ    %00010000
mPTASE_PTASE5:      equ    %00100000


;*** PTADS - Port A Drive Strength Select; 0x00001842 ***
PTADS:              equ    $00001842                                ;*** PTADS - Port A Drive Strength Select; 0x00001842 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0:       equ    0                                         ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS1:       equ    1                                         ; Output Drive Strength Selection for Port A Bit 1
PTADS_PTADS2:       equ    2                                         ; Output Drive Strength Selection for Port A Bit 2
PTADS_PTADS3:       equ    3                                         ; Output Drive Strength Selection for Port A Bit 3
PTADS_PTADS4:       equ    4                                         ; Output Drive Strength Selection for Port A Bit 4
PTADS_PTADS5:       equ    5                                         ; Output Drive Strength Selection for Port A Bit 5
; bit position masks
mPTADS_PTADS0:      equ    %00000001
mPTADS_PTADS1:      equ    %00000010
mPTADS_PTADS2:      equ    %00000100
mPTADS_PTADS3:      equ    %00001000
mPTADS_PTADS4:      equ    %00010000
mPTADS_PTADS5:      equ    %00100000


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


;*** NVPROT - Nonvolatile FLASH Protection Register; 0x0000FFBD ***
NVPROT:             equ    $0000FFBD                                ;*** NVPROT - Nonvolatile FLASH Protection Register; 0x0000FFBD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVPROT_FPDIS:       equ    0                                         ; FLASH Protection Disable
NVPROT_FPS0:        equ    1                                         ; FLASH Protect Select Bits, bit 0
NVPROT_FPS1:        equ    2                                         ; FLASH Protect Select Bits, bit 1
NVPROT_FPS2:        equ    3                                         ; FLASH Protect Select Bits, bit 2
NVPROT_FPS3:        equ    4                                         ; FLASH Protect Select Bits, bit 3
NVPROT_FPS4:        equ    5                                         ; FLASH Protect Select Bits, bit 4
NVPROT_FPS5:        equ    6                                         ; FLASH Protect Select Bits, bit 5
NVPROT_FPS6:        equ    7                                         ; FLASH Protect Select Bits, bit 6
; bit position masks
mNVPROT_FPDIS:      equ    %00000001
mNVPROT_FPS0:       equ    %00000010
mNVPROT_FPS1:       equ    %00000100
mNVPROT_FPS2:       equ    %00001000
mNVPROT_FPS3:       equ    %00010000
mNVPROT_FPS4:       equ    %00100000
mNVPROT_FPS5:       equ    %01000000
mNVPROT_FPS6:       equ    %10000000


;*** NVOPT - Nonvolatile FLASH Options Register; 0x0000FFBF ***
NVOPT:              equ    $0000FFBF                                ;*** NVOPT - Nonvolatile FLASH Options Register; 0x0000FFBF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC00:        equ    0                                         ; Security State Code Bit 0
NVOPT_SEC01:        equ    1                                         ; Security State Code Bit 1
NVOPT_FNORED:       equ    6                                         ; Vector Redirection Disable
NVOPT_KEYEN:        equ    7                                         ; Backdoor Key Mechanism Enable
; bit position masks
mNVOPT_SEC00:       equ    %00000001
mNVOPT_SEC01:       equ    %00000010
mNVOPT_FNORED:      equ    %01000000
mNVOPT_KEYEN:       equ    %10000000


;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
        IFNDEF  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
                    XREF    This_symb_has_been_depreciated
        ENDIF

; EOF
