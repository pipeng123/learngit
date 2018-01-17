; Based on CPU DB MCF51JM128_80, version 3.00.031 (RegistersPrg V2.23)

; ###################################################################
;     Filename  : mcf51jm128.inc
;     Processor : MCF51JM128VLK
;     FileFormat: V2.23
;     DataSheet : MCF51JM128RM Rev. 1 Draft A 1/2008
;     Compiler  : CodeWarrior compiler
;     Date/Time : 6.5.2008, 13:48
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     (c) Copyright UNIS, spol. s r.o. 1997-2008
;     UNIS, spol. s r.o.
;     Jundrovska 33
;     624 00 Brno
;     Czech Republic
;     http      : www.processorexpert.com
;     mail      : info@processorexpert.com
;
;     CPU Registers Revisions:
;      - 05.02.2008, V3.00.0:
;              - Removed bit SPI2C3[INTCLR], removed register SPI2CI, removed bits OTG_CTRL[VBUS_DSCHG, VBUS_CHG, VBUS_ON].
;              -   REASON: Bug-fix (issue #5763 from the Unis Issue Manager).
;
;     File-Format-Revisions:
;      - 06.08.2007, V2.19 :
;               - CPUDB revisions generated ahead of the file-format revisions.
;      - 11.09.2007, V2.20 :
;               - Added comment about initialization of unbonded pins.
;      - 02.01.2008, V2.21 :
;               - pragma push/pack replaced by pragma options align, issue #5608
;      - 13.02.2008, V2.22 :
;               - ASM header files: fixed too long lines and pseudo-instructions format (leading dot)
;      - 20.02.2008, V2.23 :
;               -  Changes have not affected this file (because they are related to another family)
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Interrupt Vectors
;******************************************
INITSP:             .equ  $00000000
INITPC:             .equ  $00000004
Vaccerr:            .equ  $00000008
Vadderr:            .equ  $0000000C
Viinstr:            .equ  $00000010
VReserved5:         .equ  $00000014
VReserved6:         .equ  $00000018
VReserved7:         .equ  $0000001C
Vprviol:            .equ  $00000020
Vtrace:             .equ  $00000024
Vunilaop:           .equ  $00000028
Vunilfop:           .equ  $0000002C
Vdbgi:              .equ  $00000030
VReserved13:        .equ  $00000034
Vferror:            .equ  $00000038
VReserved15:        .equ  $0000003C
VReserved16:        .equ  $00000040
VReserved17:        .equ  $00000044
VReserved18:        .equ  $00000048
VReserved19:        .equ  $0000004C
VReserved20:        .equ  $00000050
VReserved21:        .equ  $00000054
VReserved22:        .equ  $00000058
VReserved23:        .equ  $0000005C
Vspuri:             .equ  $00000060
VReserved25:        .equ  $00000064
VReserved26:        .equ  $00000068
VReserved27:        .equ  $0000006C
VReserved28:        .equ  $00000070
VReserved29:        .equ  $00000074
VReserved30:        .equ  $00000078
VReserved31:        .equ  $0000007C
Vtrap0:             .equ  $00000080
Vtrap1:             .equ  $00000084
Vtrap2:             .equ  $00000088
Vtrap3:             .equ  $0000008C
Vtrap4:             .equ  $00000090
Vtrap5:             .equ  $00000094
Vtrap6:             .equ  $00000098
Vtrap7:             .equ  $0000009C
Vtrap8:             .equ  $000000A0
Vtrap9:             .equ  $000000A4
Vtrap10:            .equ  $000000A8
Vtrap11:            .equ  $000000AC
Vtrap12:            .equ  $000000B0
Vtrap13:            .equ  $000000B4
Vtrap14:            .equ  $000000B8
Vtrap15:            .equ  $000000BC
VReserved48:        .equ  $000000C0
VReserved49:        .equ  $000000C4
VReserved50:        .equ  $000000C8
VReserved51:        .equ  $000000CC
VReserved52:        .equ  $000000D0
VReserved53:        .equ  $000000D4
VReserved54:        .equ  $000000D8
VReserved55:        .equ  $000000DC
VReserved56:        .equ  $000000E0
VReserved57:        .equ  $000000E4
VReserved58:        .equ  $000000E8
VReserved59:        .equ  $000000EC
VReserved60:        .equ  $000000F0
Vunsinstr:          .equ  $000000F4
VReserved62:        .equ  $000000F8
VReserved63:        .equ  $000000FC
Virq:               .equ  $00000100
Vlvd:               .equ  $00000104
Vlol:               .equ  $00000108
Vspi1:              .equ  $0000010C
Vspi2:              .equ  $00000110
Vusb:               .equ  $00000114
VReserved70:        .equ  $00000118
Vtpm1ch0:           .equ  $0000011C
Vtpm1ch1:           .equ  $00000120
Vtpm1ch2:           .equ  $00000124
Vtpm1ch3:           .equ  $00000128
Vtpm1ch4:           .equ  $0000012C
Vtpm1ch5:           .equ  $00000130
Vtpm1ovf:           .equ  $00000134
Vtpm2ch0:           .equ  $00000138
Vtpm2ch1:           .equ  $0000013C
Vtpm2ovf:           .equ  $00000140
Vsci1err:           .equ  $00000144
Vsci1rx:            .equ  $00000148
Vsci1tx:            .equ  $0000014C
Vsci2err:           .equ  $00000150
Vsci2rx:            .equ  $00000154
Vsci2tx:            .equ  $00000158
Vkeyboard:          .equ  $0000015C
Vadc:               .equ  $00000160
Vacmpx:             .equ  $00000164
Viic1x:             .equ  $00000168
Vrtc:               .equ  $0000016C
Viic2x:             .equ  $00000170
Vcmt:               .equ  $00000174
Vcanwu:             .equ  $00000178
Vcanerr:            .equ  $0000017C
Vcanrx:             .equ  $00000180
Vcantx:             .equ  $00000184
Vrnga:              .equ  $00000188
VReserved99:        .equ  $0000018C
VReserved100:       .equ  $00000190
VReserved101:       .equ  $00000194
VReserved102:       .equ  $00000198
VReserved103:       .equ  $0000019C
VL7swi:             .equ  $000001A0
VL6swi:             .equ  $000001A4
VL5swi:             .equ  $000001A8
VL4swi:             .equ  $000001AC
VL3swi:             .equ  $000001B0
VL2swi:             .equ  $000001B4
VL1swi:             .equ  $000001B8
;


;*** NVFTRIM - Nonvolatile MCG Fine Trim; 0x000003FE ***
NVFTRIM:            .equ   $000003FE                                ;*** NVFTRIM - Nonvolatile MCG Fine Trim; 0x000003FE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFTRIM_FTRIM:      .equ   0                                         ; MCG Fine Trim
; bit position masks
mNVFTRIM_FTRIM:     .equ   %00000001


;*** NVMCGTRM - Nonvolatile MCG Trim Register; 0x000003FF ***
NVMCGTRM:           .equ   $000003FF                                ;*** NVMCGTRM - Nonvolatile MCG Trim Register; 0x000003FF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVMCGTRM_TRIM0:     .equ   0                                         ; MCG Trim Setting, bit 0
NVMCGTRM_TRIM1:     .equ   1                                         ; MCG Trim Setting, bit 1
NVMCGTRM_TRIM2:     .equ   2                                         ; MCG Trim Setting, bit 2
NVMCGTRM_TRIM3:     .equ   3                                         ; MCG Trim Setting, bit 3
NVMCGTRM_TRIM4:     .equ   4                                         ; MCG Trim Setting, bit 4
NVMCGTRM_TRIM5:     .equ   5                                         ; MCG Trim Setting, bit 5
NVMCGTRM_TRIM6:     .equ   6                                         ; MCG Trim Setting, bit 6
NVMCGTRM_TRIM7:     .equ   7                                         ; MCG Trim Setting, bit 7
; bit position masks
mNVMCGTRM_TRIM0:    .equ   %00000001
mNVMCGTRM_TRIM1:    .equ   %00000010
mNVMCGTRM_TRIM2:    .equ   %00000100
mNVMCGTRM_TRIM3:    .equ   %00001000
mNVMCGTRM_TRIM4:    .equ   %00010000
mNVMCGTRM_TRIM5:    .equ   %00100000
mNVMCGTRM_TRIM6:    .equ   %01000000
mNVMCGTRM_TRIM7:    .equ   %10000000


;*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x00000400 ***
NVBACKKEY0:         .equ   $00000400                                ;*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x00000400 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY0_KEY0:    .equ   0                                         ; Backdoor Comparison Key 0 Bits, bit 0
NVBACKKEY0_KEY1:    .equ   1                                         ; Backdoor Comparison Key 0 Bits, bit 1
NVBACKKEY0_KEY2:    .equ   2                                         ; Backdoor Comparison Key 0 Bits, bit 2
NVBACKKEY0_KEY3:    .equ   3                                         ; Backdoor Comparison Key 0 Bits, bit 3
NVBACKKEY0_KEY4:    .equ   4                                         ; Backdoor Comparison Key 0 Bits, bit 4
NVBACKKEY0_KEY5:    .equ   5                                         ; Backdoor Comparison Key 0 Bits, bit 5
NVBACKKEY0_KEY6:    .equ   6                                         ; Backdoor Comparison Key 0 Bits, bit 6
NVBACKKEY0_KEY7:    .equ   7                                         ; Backdoor Comparison Key 0 Bits, bit 7
; bit position masks
mNVBACKKEY0_KEY0:   .equ   %00000001
mNVBACKKEY0_KEY1:   .equ   %00000010
mNVBACKKEY0_KEY2:   .equ   %00000100
mNVBACKKEY0_KEY3:   .equ   %00001000
mNVBACKKEY0_KEY4:   .equ   %00010000
mNVBACKKEY0_KEY5:   .equ   %00100000
mNVBACKKEY0_KEY6:   .equ   %01000000
mNVBACKKEY0_KEY7:   .equ   %10000000


;*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x00000401 ***
NVBACKKEY1:         .equ   $00000401                                ;*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x00000401 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY1_KEY0:    .equ   0                                         ; Backdoor Comparison Key 1 Bits, bit 0
NVBACKKEY1_KEY1:    .equ   1                                         ; Backdoor Comparison Key 1 Bits, bit 1
NVBACKKEY1_KEY2:    .equ   2                                         ; Backdoor Comparison Key 1 Bits, bit 2
NVBACKKEY1_KEY3:    .equ   3                                         ; Backdoor Comparison Key 1 Bits, bit 3
NVBACKKEY1_KEY4:    .equ   4                                         ; Backdoor Comparison Key 1 Bits, bit 4
NVBACKKEY1_KEY5:    .equ   5                                         ; Backdoor Comparison Key 1 Bits, bit 5
NVBACKKEY1_KEY6:    .equ   6                                         ; Backdoor Comparison Key 1 Bits, bit 6
NVBACKKEY1_KEY7:    .equ   7                                         ; Backdoor Comparison Key 1 Bits, bit 7
; bit position masks
mNVBACKKEY1_KEY0:   .equ   %00000001
mNVBACKKEY1_KEY1:   .equ   %00000010
mNVBACKKEY1_KEY2:   .equ   %00000100
mNVBACKKEY1_KEY3:   .equ   %00001000
mNVBACKKEY1_KEY4:   .equ   %00010000
mNVBACKKEY1_KEY5:   .equ   %00100000
mNVBACKKEY1_KEY6:   .equ   %01000000
mNVBACKKEY1_KEY7:   .equ   %10000000


;*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x00000402 ***
NVBACKKEY2:         .equ   $00000402                                ;*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x00000402 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY2_KEY0:    .equ   0                                         ; Backdoor Comparison Key 2 Bits, bit 0
NVBACKKEY2_KEY1:    .equ   1                                         ; Backdoor Comparison Key 2 Bits, bit 1
NVBACKKEY2_KEY2:    .equ   2                                         ; Backdoor Comparison Key 2 Bits, bit 2
NVBACKKEY2_KEY3:    .equ   3                                         ; Backdoor Comparison Key 2 Bits, bit 3
NVBACKKEY2_KEY4:    .equ   4                                         ; Backdoor Comparison Key 2 Bits, bit 4
NVBACKKEY2_KEY5:    .equ   5                                         ; Backdoor Comparison Key 2 Bits, bit 5
NVBACKKEY2_KEY6:    .equ   6                                         ; Backdoor Comparison Key 2 Bits, bit 6
NVBACKKEY2_KEY7:    .equ   7                                         ; Backdoor Comparison Key 2 Bits, bit 7
; bit position masks
mNVBACKKEY2_KEY0:   .equ   %00000001
mNVBACKKEY2_KEY1:   .equ   %00000010
mNVBACKKEY2_KEY2:   .equ   %00000100
mNVBACKKEY2_KEY3:   .equ   %00001000
mNVBACKKEY2_KEY4:   .equ   %00010000
mNVBACKKEY2_KEY5:   .equ   %00100000
mNVBACKKEY2_KEY6:   .equ   %01000000
mNVBACKKEY2_KEY7:   .equ   %10000000


;*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x00000403 ***
NVBACKKEY3:         .equ   $00000403                                ;*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x00000403 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY3_KEY0:    .equ   0                                         ; Backdoor Comparison Key 3 Bits, bit 0
NVBACKKEY3_KEY1:    .equ   1                                         ; Backdoor Comparison Key 3 Bits, bit 1
NVBACKKEY3_KEY2:    .equ   2                                         ; Backdoor Comparison Key 3 Bits, bit 2
NVBACKKEY3_KEY3:    .equ   3                                         ; Backdoor Comparison Key 3 Bits, bit 3
NVBACKKEY3_KEY4:    .equ   4                                         ; Backdoor Comparison Key 3 Bits, bit 4
NVBACKKEY3_KEY5:    .equ   5                                         ; Backdoor Comparison Key 3 Bits, bit 5
NVBACKKEY3_KEY6:    .equ   6                                         ; Backdoor Comparison Key 3 Bits, bit 6
NVBACKKEY3_KEY7:    .equ   7                                         ; Backdoor Comparison Key 3 Bits, bit 7
; bit position masks
mNVBACKKEY3_KEY0:   .equ   %00000001
mNVBACKKEY3_KEY1:   .equ   %00000010
mNVBACKKEY3_KEY2:   .equ   %00000100
mNVBACKKEY3_KEY3:   .equ   %00001000
mNVBACKKEY3_KEY4:   .equ   %00010000
mNVBACKKEY3_KEY5:   .equ   %00100000
mNVBACKKEY3_KEY6:   .equ   %01000000
mNVBACKKEY3_KEY7:   .equ   %10000000


;*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x00000404 ***
NVBACKKEY4:         .equ   $00000404                                ;*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x00000404 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY4_KEY0:    .equ   0                                         ; Backdoor Comparison Key 4 Bits, bit 0
NVBACKKEY4_KEY1:    .equ   1                                         ; Backdoor Comparison Key 4 Bits, bit 1
NVBACKKEY4_KEY2:    .equ   2                                         ; Backdoor Comparison Key 4 Bits, bit 2
NVBACKKEY4_KEY3:    .equ   3                                         ; Backdoor Comparison Key 4 Bits, bit 3
NVBACKKEY4_KEY4:    .equ   4                                         ; Backdoor Comparison Key 4 Bits, bit 4
NVBACKKEY4_KEY5:    .equ   5                                         ; Backdoor Comparison Key 4 Bits, bit 5
NVBACKKEY4_KEY6:    .equ   6                                         ; Backdoor Comparison Key 4 Bits, bit 6
NVBACKKEY4_KEY7:    .equ   7                                         ; Backdoor Comparison Key 4 Bits, bit 7
; bit position masks
mNVBACKKEY4_KEY0:   .equ   %00000001
mNVBACKKEY4_KEY1:   .equ   %00000010
mNVBACKKEY4_KEY2:   .equ   %00000100
mNVBACKKEY4_KEY3:   .equ   %00001000
mNVBACKKEY4_KEY4:   .equ   %00010000
mNVBACKKEY4_KEY5:   .equ   %00100000
mNVBACKKEY4_KEY6:   .equ   %01000000
mNVBACKKEY4_KEY7:   .equ   %10000000


;*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x00000405 ***
NVBACKKEY5:         .equ   $00000405                                ;*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x00000405 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY5_KEY0:    .equ   0                                         ; Backdoor Comparison Key 5 Bits, bit 0
NVBACKKEY5_KEY1:    .equ   1                                         ; Backdoor Comparison Key 5 Bits, bit 1
NVBACKKEY5_KEY2:    .equ   2                                         ; Backdoor Comparison Key 5 Bits, bit 2
NVBACKKEY5_KEY3:    .equ   3                                         ; Backdoor Comparison Key 5 Bits, bit 3
NVBACKKEY5_KEY4:    .equ   4                                         ; Backdoor Comparison Key 5 Bits, bit 4
NVBACKKEY5_KEY5:    .equ   5                                         ; Backdoor Comparison Key 5 Bits, bit 5
NVBACKKEY5_KEY6:    .equ   6                                         ; Backdoor Comparison Key 5 Bits, bit 6
NVBACKKEY5_KEY7:    .equ   7                                         ; Backdoor Comparison Key 5 Bits, bit 7
; bit position masks
mNVBACKKEY5_KEY0:   .equ   %00000001
mNVBACKKEY5_KEY1:   .equ   %00000010
mNVBACKKEY5_KEY2:   .equ   %00000100
mNVBACKKEY5_KEY3:   .equ   %00001000
mNVBACKKEY5_KEY4:   .equ   %00010000
mNVBACKKEY5_KEY5:   .equ   %00100000
mNVBACKKEY5_KEY6:   .equ   %01000000
mNVBACKKEY5_KEY7:   .equ   %10000000


;*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x00000406 ***
NVBACKKEY6:         .equ   $00000406                                ;*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x00000406 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY6_KEY0:    .equ   0                                         ; Backdoor Comparison Key 6 Bits, bit 0
NVBACKKEY6_KEY1:    .equ   1                                         ; Backdoor Comparison Key 6 Bits, bit 1
NVBACKKEY6_KEY2:    .equ   2                                         ; Backdoor Comparison Key 6 Bits, bit 2
NVBACKKEY6_KEY3:    .equ   3                                         ; Backdoor Comparison Key 6 Bits, bit 3
NVBACKKEY6_KEY4:    .equ   4                                         ; Backdoor Comparison Key 6 Bits, bit 4
NVBACKKEY6_KEY5:    .equ   5                                         ; Backdoor Comparison Key 6 Bits, bit 5
NVBACKKEY6_KEY6:    .equ   6                                         ; Backdoor Comparison Key 6 Bits, bit 6
NVBACKKEY6_KEY7:    .equ   7                                         ; Backdoor Comparison Key 6 Bits, bit 7
; bit position masks
mNVBACKKEY6_KEY0:   .equ   %00000001
mNVBACKKEY6_KEY1:   .equ   %00000010
mNVBACKKEY6_KEY2:   .equ   %00000100
mNVBACKKEY6_KEY3:   .equ   %00001000
mNVBACKKEY6_KEY4:   .equ   %00010000
mNVBACKKEY6_KEY5:   .equ   %00100000
mNVBACKKEY6_KEY6:   .equ   %01000000
mNVBACKKEY6_KEY7:   .equ   %10000000


;*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x00000407 ***
NVBACKKEY7:         .equ   $00000407                                ;*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x00000407 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY7_KEY0:    .equ   0                                         ; Backdoor Comparison Key 7 Bits, bit 0
NVBACKKEY7_KEY1:    .equ   1                                         ; Backdoor Comparison Key 7 Bits, bit 1
NVBACKKEY7_KEY2:    .equ   2                                         ; Backdoor Comparison Key 7 Bits, bit 2
NVBACKKEY7_KEY3:    .equ   3                                         ; Backdoor Comparison Key 7 Bits, bit 3
NVBACKKEY7_KEY4:    .equ   4                                         ; Backdoor Comparison Key 7 Bits, bit 4
NVBACKKEY7_KEY5:    .equ   5                                         ; Backdoor Comparison Key 7 Bits, bit 5
NVBACKKEY7_KEY6:    .equ   6                                         ; Backdoor Comparison Key 7 Bits, bit 6
NVBACKKEY7_KEY7:    .equ   7                                         ; Backdoor Comparison Key 7 Bits, bit 7
; bit position masks
mNVBACKKEY7_KEY0:   .equ   %00000001
mNVBACKKEY7_KEY1:   .equ   %00000010
mNVBACKKEY7_KEY2:   .equ   %00000100
mNVBACKKEY7_KEY3:   .equ   %00001000
mNVBACKKEY7_KEY4:   .equ   %00010000
mNVBACKKEY7_KEY5:   .equ   %00100000
mNVBACKKEY7_KEY6:   .equ   %01000000
mNVBACKKEY7_KEY7:   .equ   %10000000


;*** NVPROT - Nonvolatile Flash Protection Register; 0x0000040D ***
NVPROT:             .equ   $0000040D                                ;*** NVPROT - Nonvolatile Flash Protection Register; 0x0000040D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVPROT_FPOPEN:      .equ   0                                         ; Flash Protection Open
NVPROT_FPS0:        .equ   1                                         ; Flash Protection Size, bit 0
NVPROT_FPS1:        .equ   2                                         ; Flash Protection Size, bit 1
NVPROT_FPS2:        .equ   3                                         ; Flash Protection Size, bit 2
NVPROT_FPS3:        .equ   4                                         ; Flash Protection Size, bit 3
NVPROT_FPS4:        .equ   5                                         ; Flash Protection Size, bit 4
NVPROT_FPS5:        .equ   6                                         ; Flash Protection Size, bit 5
NVPROT_FPS6:        .equ   7                                         ; Flash Protection Size, bit 6
; bit position masks
mNVPROT_FPOPEN:     .equ   %00000001
mNVPROT_FPS0:       .equ   %00000010
mNVPROT_FPS1:       .equ   %00000100
mNVPROT_FPS2:       .equ   %00001000
mNVPROT_FPS3:       .equ   %00010000
mNVPROT_FPS4:       .equ   %00100000
mNVPROT_FPS5:       .equ   %01000000
mNVPROT_FPS6:       .equ   %10000000


;*** NVOPT - Nonvolatile Flash Options Register; 0x0000040F ***
NVOPT:              .equ   $0000040F                                ;*** NVOPT - Nonvolatile Flash Options Register; 0x0000040F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC0:         .equ   0                                         ; Flash Security Bit 0
NVOPT_SEC1:         .equ   1                                         ; Flash Security Bit 1
NVOPT_KEYEN0:       .equ   6                                         ; Backdoor Key Security Enable Bit 0
NVOPT_KEYEN1:       .equ   7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mNVOPT_SEC0:        .equ   %00000001
mNVOPT_SEC1:        .equ   %00000010
mNVOPT_KEYEN0:      .equ   %01000000
mNVOPT_KEYEN1:      .equ   %10000000


;*** RGPIO_DIR - RGPIO Data Direction Register; 0x00C00000 ***
RGPIO_DIR:          .equ   $00C00000                                ;*** RGPIO_DIR - RGPIO Data Direction Register; 0x00C00000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RGPIO_DIR_DIR0:     .equ   0                                         ; RGPIO data direction bit 0
RGPIO_DIR_DIR1:     .equ   1                                         ; RGPIO data direction bit 1
RGPIO_DIR_DIR2:     .equ   2                                         ; RGPIO data direction bit 2
RGPIO_DIR_DIR3:     .equ   3                                         ; RGPIO data direction bit 3
RGPIO_DIR_DIR4:     .equ   4                                         ; RGPIO data direction bit 4
RGPIO_DIR_DIR5:     .equ   5                                         ; RGPIO data direction bit 5
RGPIO_DIR_DIR6:     .equ   6                                         ; RGPIO data direction bit 6
RGPIO_DIR_DIR7:     .equ   7                                         ; RGPIO data direction bit 7
RGPIO_DIR_DIR8:     .equ   8                                         ; RGPIO data direction bit 8
RGPIO_DIR_DIR9:     .equ   9                                         ; RGPIO data direction bit 9
RGPIO_DIR_DIR10:    .equ   10                                        ; RGPIO data direction bit 10
RGPIO_DIR_DIR11:    .equ   11                                        ; RGPIO data direction bit 11
RGPIO_DIR_DIR12:    .equ   12                                        ; RGPIO data direction bit 12
RGPIO_DIR_DIR13:    .equ   13                                        ; RGPIO data direction bit 13
RGPIO_DIR_DIR14:    .equ   14                                        ; RGPIO data direction bit 14
RGPIO_DIR_DIR15:    .equ   15                                        ; RGPIO data direction bit 15
; bit position masks
mRGPIO_DIR_DIR0:    .equ   %00000001
mRGPIO_DIR_DIR1:    .equ   %00000010
mRGPIO_DIR_DIR2:    .equ   %00000100
mRGPIO_DIR_DIR3:    .equ   %00001000
mRGPIO_DIR_DIR4:    .equ   %00010000
mRGPIO_DIR_DIR5:    .equ   %00100000
mRGPIO_DIR_DIR6:    .equ   %01000000
mRGPIO_DIR_DIR7:    .equ   %10000000
mRGPIO_DIR_DIR8:    .equ   %100000000
mRGPIO_DIR_DIR9:    .equ   %1000000000
mRGPIO_DIR_DIR10:   .equ   %10000000000
mRGPIO_DIR_DIR11:   .equ   %100000000000
mRGPIO_DIR_DIR12:   .equ   %1000000000000
mRGPIO_DIR_DIR13:   .equ   %10000000000000
mRGPIO_DIR_DIR14:   .equ   %100000000000000
mRGPIO_DIR_DIR15:   .equ   %1000000000000000


;*** RGPIO_DATA - RGPIO Data Register; 0x00C00002 ***
RGPIO_DATA:         .equ   $00C00002                                ;*** RGPIO_DATA - RGPIO Data Register; 0x00C00002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RGPIO_DATA_DATA0:   .equ   0                                         ; RGPIO data bit 0
RGPIO_DATA_DATA1:   .equ   1                                         ; RGPIO data bit 1
RGPIO_DATA_DATA2:   .equ   2                                         ; RGPIO data bit 2
RGPIO_DATA_DATA3:   .equ   3                                         ; RGPIO data bit 3
RGPIO_DATA_DATA4:   .equ   4                                         ; RGPIO data bit 4
RGPIO_DATA_DATA5:   .equ   5                                         ; RGPIO data bit 5
RGPIO_DATA_DATA6:   .equ   6                                         ; RGPIO data bit 6
RGPIO_DATA_DATA7:   .equ   7                                         ; RGPIO data bit 7
RGPIO_DATA_DATA8:   .equ   8                                         ; RGPIO data bit 8
RGPIO_DATA_DATA9:   .equ   9                                         ; RGPIO data bit 9
RGPIO_DATA_DATA10:  .equ   10                                        ; RGPIO data bit 10
RGPIO_DATA_DATA11:  .equ   11                                        ; RGPIO data bit 11
RGPIO_DATA_DATA12:  .equ   12                                        ; RGPIO data bit 12
RGPIO_DATA_DATA13:  .equ   13                                        ; RGPIO data bit 13
RGPIO_DATA_DATA14:  .equ   14                                        ; RGPIO data bit 14
RGPIO_DATA_DATA15:  .equ   15                                        ; RGPIO data bit 15
; bit position masks
mRGPIO_DATA_DATA0:  .equ   %00000001
mRGPIO_DATA_DATA1:  .equ   %00000010
mRGPIO_DATA_DATA2:  .equ   %00000100
mRGPIO_DATA_DATA3:  .equ   %00001000
mRGPIO_DATA_DATA4:  .equ   %00010000
mRGPIO_DATA_DATA5:  .equ   %00100000
mRGPIO_DATA_DATA6:  .equ   %01000000
mRGPIO_DATA_DATA7:  .equ   %10000000
mRGPIO_DATA_DATA8:  .equ   %100000000
mRGPIO_DATA_DATA9:  .equ   %1000000000
mRGPIO_DATA_DATA10: .equ   %10000000000
mRGPIO_DATA_DATA11: .equ   %100000000000
mRGPIO_DATA_DATA12: .equ   %1000000000000
mRGPIO_DATA_DATA13: .equ   %10000000000000
mRGPIO_DATA_DATA14: .equ   %100000000000000
mRGPIO_DATA_DATA15: .equ   %1000000000000000


;*** RGPIO_ENB - RGPIO Pin Enable Register; 0x00C00004 ***
RGPIO_ENB:          .equ   $00C00004                                ;*** RGPIO_ENB - RGPIO Pin Enable Register; 0x00C00004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RGPIO_ENB_ENB0:     .equ   0                                         ; RGPIO enable bit 0
RGPIO_ENB_ENB1:     .equ   1                                         ; RGPIO enable bit 1
RGPIO_ENB_ENB2:     .equ   2                                         ; RGPIO enable bit 2
RGPIO_ENB_ENB3:     .equ   3                                         ; RGPIO enable bit 3
RGPIO_ENB_ENB4:     .equ   4                                         ; RGPIO enable bit 4
RGPIO_ENB_ENB5:     .equ   5                                         ; RGPIO enable bit 5
RGPIO_ENB_ENB6:     .equ   6                                         ; RGPIO enable bit 6
RGPIO_ENB_ENB7:     .equ   7                                         ; RGPIO enable bit 7
RGPIO_ENB_ENB8:     .equ   8                                         ; RGPIO enable bit 8
RGPIO_ENB_ENB9:     .equ   9                                         ; RGPIO enable bit 9
RGPIO_ENB_ENB10:    .equ   10                                        ; RGPIO enable bit 10
RGPIO_ENB_ENB11:    .equ   11                                        ; RGPIO enable bit 11
RGPIO_ENB_ENB12:    .equ   12                                        ; RGPIO enable bit 12
RGPIO_ENB_ENB13:    .equ   13                                        ; RGPIO enable bit 13
RGPIO_ENB_ENB14:    .equ   14                                        ; RGPIO enable bit 14
RGPIO_ENB_ENB15:    .equ   15                                        ; RGPIO enable bit 15
; bit position masks
mRGPIO_ENB_ENB0:    .equ   %00000001
mRGPIO_ENB_ENB1:    .equ   %00000010
mRGPIO_ENB_ENB2:    .equ   %00000100
mRGPIO_ENB_ENB3:    .equ   %00001000
mRGPIO_ENB_ENB4:    .equ   %00010000
mRGPIO_ENB_ENB5:    .equ   %00100000
mRGPIO_ENB_ENB6:    .equ   %01000000
mRGPIO_ENB_ENB7:    .equ   %10000000
mRGPIO_ENB_ENB8:    .equ   %100000000
mRGPIO_ENB_ENB9:    .equ   %1000000000
mRGPIO_ENB_ENB10:   .equ   %10000000000
mRGPIO_ENB_ENB11:   .equ   %100000000000
mRGPIO_ENB_ENB12:   .equ   %1000000000000
mRGPIO_ENB_ENB13:   .equ   %10000000000000
mRGPIO_ENB_ENB14:   .equ   %100000000000000
mRGPIO_ENB_ENB15:   .equ   %1000000000000000


;*** RGPIO_CLR - RGPIO Clear Data Register; 0x00C00006 ***
RGPIO_CLR:          .equ   $00C00006                                ;*** RGPIO_CLR - RGPIO Clear Data Register; 0x00C00006 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RGPIO_CLR_CLR0:     .equ   0                                         ; RGPIO clear data bit 0
RGPIO_CLR_CLR1:     .equ   1                                         ; RGPIO clear data bit 1
RGPIO_CLR_CLR2:     .equ   2                                         ; RGPIO clear data bit 2
RGPIO_CLR_CLR3:     .equ   3                                         ; RGPIO clear data bit 3
RGPIO_CLR_CLR4:     .equ   4                                         ; RGPIO clear data bit 4
RGPIO_CLR_CLR5:     .equ   5                                         ; RGPIO clear data bit 5
RGPIO_CLR_CLR6:     .equ   6                                         ; RGPIO clear data bit 6
RGPIO_CLR_CLR7:     .equ   7                                         ; RGPIO clear data bit 7
RGPIO_CLR_CLR8:     .equ   8                                         ; RGPIO clear data bit 8
RGPIO_CLR_CLR9:     .equ   9                                         ; RGPIO clear data bit 9
RGPIO_CLR_CLR10:    .equ   10                                        ; RGPIO clear data bit 10
RGPIO_CLR_CLR11:    .equ   11                                        ; RGPIO clear data bit 11
RGPIO_CLR_CLR12:    .equ   12                                        ; RGPIO clear data bit 12
RGPIO_CLR_CLR13:    .equ   13                                        ; RGPIO clear data bit 13
RGPIO_CLR_CLR14:    .equ   14                                        ; RGPIO clear data bit 14
RGPIO_CLR_CLR15:    .equ   15                                        ; RGPIO clear data bit 15
; bit position masks
mRGPIO_CLR_CLR0:    .equ   %00000001
mRGPIO_CLR_CLR1:    .equ   %00000010
mRGPIO_CLR_CLR2:    .equ   %00000100
mRGPIO_CLR_CLR3:    .equ   %00001000
mRGPIO_CLR_CLR4:    .equ   %00010000
mRGPIO_CLR_CLR5:    .equ   %00100000
mRGPIO_CLR_CLR6:    .equ   %01000000
mRGPIO_CLR_CLR7:    .equ   %10000000
mRGPIO_CLR_CLR8:    .equ   %100000000
mRGPIO_CLR_CLR9:    .equ   %1000000000
mRGPIO_CLR_CLR10:   .equ   %10000000000
mRGPIO_CLR_CLR11:   .equ   %100000000000
mRGPIO_CLR_CLR12:   .equ   %1000000000000
mRGPIO_CLR_CLR13:   .equ   %10000000000000
mRGPIO_CLR_CLR14:   .equ   %100000000000000
mRGPIO_CLR_CLR15:   .equ   %1000000000000000


;*** RGPIO_SET - RGPIO Set Data Register; 0x00C0000A ***
RGPIO_SET:          .equ   $00C0000A                                ;*** RGPIO_SET - RGPIO Set Data Register; 0x00C0000A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RGPIO_SET_SET0:     .equ   0                                         ; RGPIO set data bit 0
RGPIO_SET_SET1:     .equ   1                                         ; RGPIO set data bit 1
RGPIO_SET_SET2:     .equ   2                                         ; RGPIO set data bit 2
RGPIO_SET_SET3:     .equ   3                                         ; RGPIO set data bit 3
RGPIO_SET_SET4:     .equ   4                                         ; RGPIO set data bit 4
RGPIO_SET_SET5:     .equ   5                                         ; RGPIO set data bit 5
RGPIO_SET_SET6:     .equ   6                                         ; RGPIO set data bit 6
RGPIO_SET_SET7:     .equ   7                                         ; RGPIO set data bit 7
RGPIO_SET_SET8:     .equ   8                                         ; RGPIO set data bit 8
RGPIO_SET_SET9:     .equ   9                                         ; RGPIO set data bit 9
RGPIO_SET_SET10:    .equ   10                                        ; RGPIO set data bit 10
RGPIO_SET_SET11:    .equ   11                                        ; RGPIO set data bit 11
RGPIO_SET_SET12:    .equ   12                                        ; RGPIO set data bit 12
RGPIO_SET_SET13:    .equ   13                                        ; RGPIO set data bit 13
RGPIO_SET_SET14:    .equ   14                                        ; RGPIO set data bit 14
RGPIO_SET_SET15:    .equ   15                                        ; RGPIO set data bit 15
; bit position masks
mRGPIO_SET_SET0:    .equ   %00000001
mRGPIO_SET_SET1:    .equ   %00000010
mRGPIO_SET_SET2:    .equ   %00000100
mRGPIO_SET_SET3:    .equ   %00001000
mRGPIO_SET_SET4:    .equ   %00010000
mRGPIO_SET_SET5:    .equ   %00100000
mRGPIO_SET_SET6:    .equ   %01000000
mRGPIO_SET_SET7:    .equ   %10000000
mRGPIO_SET_SET8:    .equ   %100000000
mRGPIO_SET_SET9:    .equ   %1000000000
mRGPIO_SET_SET10:   .equ   %10000000000
mRGPIO_SET_SET11:   .equ   %100000000000
mRGPIO_SET_SET12:   .equ   %1000000000000
mRGPIO_SET_SET13:   .equ   %10000000000000
mRGPIO_SET_SET14:   .equ   %100000000000000
mRGPIO_SET_SET15:   .equ   %1000000000000000


;*** RGPIO_TOG - RGPIO Toggle Data Register; 0x00C0000E ***
RGPIO_TOG:          .equ   $00C0000E                                ;*** RGPIO_TOG - RGPIO Toggle Data Register; 0x00C0000E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RGPIO_TOG_TOG0:     .equ   0                                         ; RGPIO toggle data bit 0
RGPIO_TOG_TOG1:     .equ   1                                         ; RGPIO toggle data bit 1
RGPIO_TOG_TOG2:     .equ   2                                         ; RGPIO toggle data bit 2
RGPIO_TOG_TOG3:     .equ   3                                         ; RGPIO toggle data bit 3
RGPIO_TOG_TOG4:     .equ   4                                         ; RGPIO toggle data bit 4
RGPIO_TOG_TOG5:     .equ   5                                         ; RGPIO toggle data bit 5
RGPIO_TOG_TOG6:     .equ   6                                         ; RGPIO toggle data bit 6
RGPIO_TOG_TOG7:     .equ   7                                         ; RGPIO toggle data bit 7
RGPIO_TOG_TOG8:     .equ   8                                         ; RGPIO toggle data bit 8
RGPIO_TOG_TOG9:     .equ   9                                         ; RGPIO toggle data bit 9
RGPIO_TOG_TOG10:    .equ   10                                        ; RGPIO toggle data bit 10
RGPIO_TOG_TOG11:    .equ   11                                        ; RGPIO toggle data bit 11
RGPIO_TOG_TOG12:    .equ   12                                        ; RGPIO toggle data bit 12
RGPIO_TOG_TOG13:    .equ   13                                        ; RGPIO toggle data bit 13
RGPIO_TOG_TOG14:    .equ   14                                        ; RGPIO toggle data bit 14
RGPIO_TOG_TOG15:    .equ   15                                        ; RGPIO toggle data bit 15
; bit position masks
mRGPIO_TOG_TOG0:    .equ   %00000001
mRGPIO_TOG_TOG1:    .equ   %00000010
mRGPIO_TOG_TOG2:    .equ   %00000100
mRGPIO_TOG_TOG3:    .equ   %00001000
mRGPIO_TOG_TOG4:    .equ   %00010000
mRGPIO_TOG_TOG5:    .equ   %00100000
mRGPIO_TOG_TOG6:    .equ   %01000000
mRGPIO_TOG_TOG7:    .equ   %10000000
mRGPIO_TOG_TOG8:    .equ   %100000000
mRGPIO_TOG_TOG9:    .equ   %1000000000
mRGPIO_TOG_TOG10:   .equ   %10000000000
mRGPIO_TOG_TOG11:   .equ   %100000000000
mRGPIO_TOG_TOG12:   .equ   %1000000000000
mRGPIO_TOG_TOG13:   .equ   %10000000000000
mRGPIO_TOG_TOG14:   .equ   %100000000000000
mRGPIO_TOG_TOG15:   .equ   %1000000000000000


;*** PTAD - Port A Data Register; 0xFFFF8000 ***
PTAD:               .equ   $FFFF8000                                ;*** PTAD - Port A Data Register; 0xFFFF8000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAD_PTAD0:         .equ   0                                         ; Port A Data Register Bit 0
PTAD_PTAD1:         .equ   1                                         ; Port A Data Register Bit 1
PTAD_PTAD2:         .equ   2                                         ; Port A Data Register Bit 2
PTAD_PTAD3:         .equ   3                                         ; Port A Data Register Bit 3
PTAD_PTAD4:         .equ   4                                         ; Port A Data Register Bit 4
PTAD_PTAD5:         .equ   5                                         ; Port A Data Register Bit 5
PTAD_PTAD6:         .equ   6                                         ; Port A Data Register Bit 6
PTAD_PTAD7:         .equ   7                                         ; Port A Data Register Bit 7
; bit position masks
mPTAD_PTAD0:        .equ   %00000001
mPTAD_PTAD1:        .equ   %00000010
mPTAD_PTAD2:        .equ   %00000100
mPTAD_PTAD3:        .equ   %00001000
mPTAD_PTAD4:        .equ   %00010000
mPTAD_PTAD5:        .equ   %00100000
mPTAD_PTAD6:        .equ   %01000000
mPTAD_PTAD7:        .equ   %10000000


;*** PTADD - Port A Data Direction Register; 0xFFFF8001 ***
PTADD:              .equ   $FFFF8001                                ;*** PTADD - Port A Data Direction Register; 0xFFFF8001 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0:       .equ   0                                         ; Data Direction for Port A Bit 0
PTADD_PTADD1:       .equ   1                                         ; Data Direction for Port A Bit 1
PTADD_PTADD2:       .equ   2                                         ; Data Direction for Port A Bit 2
PTADD_PTADD3:       .equ   3                                         ; Data Direction for Port A Bit 3
PTADD_PTADD4:       .equ   4                                         ; Data Direction for Port A Bit 4
PTADD_PTADD5:       .equ   5                                         ; Data Direction for Port A Bit 5
PTADD_PTADD6:       .equ   6                                         ; Data Direction for Port A Bit 6
PTADD_PTADD7:       .equ   7                                         ; Data Direction for Port A Bit 7
; bit position masks
mPTADD_PTADD0:      .equ   %00000001
mPTADD_PTADD1:      .equ   %00000010
mPTADD_PTADD2:      .equ   %00000100
mPTADD_PTADD3:      .equ   %00001000
mPTADD_PTADD4:      .equ   %00010000
mPTADD_PTADD5:      .equ   %00100000
mPTADD_PTADD6:      .equ   %01000000
mPTADD_PTADD7:      .equ   %10000000


;*** PTBD - Port B Data Register; 0xFFFF8002 ***
PTBD:               .equ   $FFFF8002                                ;*** PTBD - Port B Data Register; 0xFFFF8002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBD_PTBD0:         .equ   0                                         ; Port B Data Register Bit 0
PTBD_PTBD1:         .equ   1                                         ; Port B Data Register Bit 1
PTBD_PTBD2:         .equ   2                                         ; Port B Data Register Bit 2
PTBD_PTBD3:         .equ   3                                         ; Port B Data Register Bit 3
PTBD_PTBD4:         .equ   4                                         ; Port B Data Register Bit 4
PTBD_PTBD5:         .equ   5                                         ; Port B Data Register Bit 5
PTBD_PTBD6:         .equ   6                                         ; Port B Data Register Bit 6
PTBD_PTBD7:         .equ   7                                         ; Port B Data Register Bit 7
; bit position masks
mPTBD_PTBD0:        .equ   %00000001
mPTBD_PTBD1:        .equ   %00000010
mPTBD_PTBD2:        .equ   %00000100
mPTBD_PTBD3:        .equ   %00001000
mPTBD_PTBD4:        .equ   %00010000
mPTBD_PTBD5:        .equ   %00100000
mPTBD_PTBD6:        .equ   %01000000
mPTBD_PTBD7:        .equ   %10000000


;*** PTBDD - Port B Data Direction Register; 0xFFFF8003 ***
PTBDD:              .equ   $FFFF8003                                ;*** PTBDD - Port B Data Direction Register; 0xFFFF8003 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0:       .equ   0                                         ; Data Direction for Port B Bit 0
PTBDD_PTBDD1:       .equ   1                                         ; Data Direction for Port B Bit 1
PTBDD_PTBDD2:       .equ   2                                         ; Data Direction for Port B Bit 2
PTBDD_PTBDD3:       .equ   3                                         ; Data Direction for Port B Bit 3
PTBDD_PTBDD4:       .equ   4                                         ; Data Direction for Port B Bit 4
PTBDD_PTBDD5:       .equ   5                                         ; Data Direction for Port B Bit 5
PTBDD_PTBDD6:       .equ   6                                         ; Data Direction for Port B Bit 6
PTBDD_PTBDD7:       .equ   7                                         ; Data Direction for Port B Bit 7
; bit position masks
mPTBDD_PTBDD0:      .equ   %00000001
mPTBDD_PTBDD1:      .equ   %00000010
mPTBDD_PTBDD2:      .equ   %00000100
mPTBDD_PTBDD3:      .equ   %00001000
mPTBDD_PTBDD4:      .equ   %00010000
mPTBDD_PTBDD5:      .equ   %00100000
mPTBDD_PTBDD6:      .equ   %01000000
mPTBDD_PTBDD7:      .equ   %10000000


;*** PTCD - Port C Data Register; 0xFFFF8004 ***
PTCD:               .equ   $FFFF8004                                ;*** PTCD - Port C Data Register; 0xFFFF8004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCD_PTCD0:         .equ   0                                         ; Port C Data Register Bit 0
PTCD_PTCD1:         .equ   1                                         ; Port C Data Register Bit 1
PTCD_PTCD2:         .equ   2                                         ; Port C Data Register Bit 2
PTCD_PTCD3:         .equ   3                                         ; Port C Data Register Bit 3
PTCD_PTCD4:         .equ   4                                         ; Port C Data Register Bit 4
PTCD_PTCD5:         .equ   5                                         ; Port C Data Register Bit 5
PTCD_PTCD6:         .equ   6                                         ; Port C Data Register Bit 6
PTCD_PTCD7:         .equ   7                                         ; Port C Data Register Bit 7
; bit position masks
mPTCD_PTCD0:        .equ   %00000001
mPTCD_PTCD1:        .equ   %00000010
mPTCD_PTCD2:        .equ   %00000100
mPTCD_PTCD3:        .equ   %00001000
mPTCD_PTCD4:        .equ   %00010000
mPTCD_PTCD5:        .equ   %00100000
mPTCD_PTCD6:        .equ   %01000000
mPTCD_PTCD7:        .equ   %10000000


;*** PTCDD - Port C Data Direction Register; 0xFFFF8005 ***
PTCDD:              .equ   $FFFF8005                                ;*** PTCDD - Port C Data Direction Register; 0xFFFF8005 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0:       .equ   0                                         ; Data Direction for Port C Bit 0
PTCDD_PTCDD1:       .equ   1                                         ; Data Direction for Port C Bit 1
PTCDD_PTCDD2:       .equ   2                                         ; Data Direction for Port C Bit 2
PTCDD_PTCDD3:       .equ   3                                         ; Data Direction for Port C Bit 3
PTCDD_PTCDD4:       .equ   4                                         ; Data Direction for Port C Bit 4
PTCDD_PTCDD5:       .equ   5                                         ; Data Direction for Port C Bit 5
PTCDD_PTCDD6:       .equ   6                                         ; Data Direction for Port C Bit 6
PTCDD_PTCDD7:       .equ   7                                         ; Data Direction for Port C Bit 7
; bit position masks
mPTCDD_PTCDD0:      .equ   %00000001
mPTCDD_PTCDD1:      .equ   %00000010
mPTCDD_PTCDD2:      .equ   %00000100
mPTCDD_PTCDD3:      .equ   %00001000
mPTCDD_PTCDD4:      .equ   %00010000
mPTCDD_PTCDD5:      .equ   %00100000
mPTCDD_PTCDD6:      .equ   %01000000
mPTCDD_PTCDD7:      .equ   %10000000


;*** PTDD - Port D Data Register; 0xFFFF8006 ***
PTDD:               .equ   $FFFF8006                                ;*** PTDD - Port D Data Register; 0xFFFF8006 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDD_PTDD0:         .equ   0                                         ; Port D Data Register Bit 0
PTDD_PTDD1:         .equ   1                                         ; Port D Data Register Bit 1
PTDD_PTDD2:         .equ   2                                         ; Port D Data Register Bit 2
PTDD_PTDD3:         .equ   3                                         ; Port D Data Register Bit 3
PTDD_PTDD4:         .equ   4                                         ; Port D Data Register Bit 4
PTDD_PTDD5:         .equ   5                                         ; Port D Data Register Bit 5
PTDD_PTDD6:         .equ   6                                         ; Port D Data Register Bit 6
PTDD_PTDD7:         .equ   7                                         ; Port D Data Register Bit 7
; bit position masks
mPTDD_PTDD0:        .equ   %00000001
mPTDD_PTDD1:        .equ   %00000010
mPTDD_PTDD2:        .equ   %00000100
mPTDD_PTDD3:        .equ   %00001000
mPTDD_PTDD4:        .equ   %00010000
mPTDD_PTDD5:        .equ   %00100000
mPTDD_PTDD6:        .equ   %01000000
mPTDD_PTDD7:        .equ   %10000000


;*** PTDDD - Port D Data Direction Register; 0xFFFF8007 ***
PTDDD:              .equ   $FFFF8007                                ;*** PTDDD - Port D Data Direction Register; 0xFFFF8007 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0:       .equ   0                                         ; Data Direction for Port D Bit 0
PTDDD_PTDDD1:       .equ   1                                         ; Data Direction for Port D Bit 1
PTDDD_PTDDD2:       .equ   2                                         ; Data Direction for Port D Bit 2
PTDDD_PTDDD3:       .equ   3                                         ; Data Direction for Port D Bit 3
PTDDD_PTDDD4:       .equ   4                                         ; Data Direction for Port D Bit 4
PTDDD_PTDDD5:       .equ   5                                         ; Data Direction for Port D Bit 5
PTDDD_PTDDD6:       .equ   6                                         ; Data Direction for Port D Bit 6
PTDDD_PTDDD7:       .equ   7                                         ; Data Direction for Port D Bit 7
; bit position masks
mPTDDD_PTDDD0:      .equ   %00000001
mPTDDD_PTDDD1:      .equ   %00000010
mPTDDD_PTDDD2:      .equ   %00000100
mPTDDD_PTDDD3:      .equ   %00001000
mPTDDD_PTDDD4:      .equ   %00010000
mPTDDD_PTDDD5:      .equ   %00100000
mPTDDD_PTDDD6:      .equ   %01000000
mPTDDD_PTDDD7:      .equ   %10000000


;*** PTED - Port E Data Register; 0xFFFF8008 ***
PTED:               .equ   $FFFF8008                                ;*** PTED - Port E Data Register; 0xFFFF8008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTED_PTED0:         .equ   0                                         ; Port E Data Register Bit 0
PTED_PTED1:         .equ   1                                         ; Port E Data Register Bit 1
PTED_PTED2:         .equ   2                                         ; Port E Data Register Bit 2
PTED_PTED3:         .equ   3                                         ; Port E Data Register Bit 3
PTED_PTED4:         .equ   4                                         ; Port E Data Register Bit 4
PTED_PTED5:         .equ   5                                         ; Port E Data Register Bit 5
PTED_PTED6:         .equ   6                                         ; Port E Data Register Bit 6
PTED_PTED7:         .equ   7                                         ; Port E Data Register Bit 7
; bit position masks
mPTED_PTED0:        .equ   %00000001
mPTED_PTED1:        .equ   %00000010
mPTED_PTED2:        .equ   %00000100
mPTED_PTED3:        .equ   %00001000
mPTED_PTED4:        .equ   %00010000
mPTED_PTED5:        .equ   %00100000
mPTED_PTED6:        .equ   %01000000
mPTED_PTED7:        .equ   %10000000


;*** PTEDD - Port E Data Direction Register; 0xFFFF8009 ***
PTEDD:              .equ   $FFFF8009                                ;*** PTEDD - Port E Data Direction Register; 0xFFFF8009 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDD_PTEDD0:       .equ   0                                         ; Data Direction for Port E Bit 0
PTEDD_PTEDD1:       .equ   1                                         ; Data Direction for Port E Bit 1
PTEDD_PTEDD2:       .equ   2                                         ; Data Direction for Port E Bit 2
PTEDD_PTEDD3:       .equ   3                                         ; Data Direction for Port E Bit 3
PTEDD_PTEDD4:       .equ   4                                         ; Data Direction for Port E Bit 4
PTEDD_PTEDD5:       .equ   5                                         ; Data Direction for Port E Bit 5
PTEDD_PTEDD6:       .equ   6                                         ; Data Direction for Port E Bit 6
PTEDD_PTEDD7:       .equ   7                                         ; Data Direction for Port E Bit 7
; bit position masks
mPTEDD_PTEDD0:      .equ   %00000001
mPTEDD_PTEDD1:      .equ   %00000010
mPTEDD_PTEDD2:      .equ   %00000100
mPTEDD_PTEDD3:      .equ   %00001000
mPTEDD_PTEDD4:      .equ   %00010000
mPTEDD_PTEDD5:      .equ   %00100000
mPTEDD_PTEDD6:      .equ   %01000000
mPTEDD_PTEDD7:      .equ   %10000000


;*** PTFD - Port F Data Register; 0xFFFF800A ***
PTFD:               .equ   $FFFF800A                                ;*** PTFD - Port F Data Register; 0xFFFF800A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFD_PTFD0:         .equ   0                                         ; Port F Data Register Bit 0
PTFD_PTFD1:         .equ   1                                         ; Port F Data Register Bit 1
PTFD_PTFD2:         .equ   2                                         ; Port F Data Register Bit 2
PTFD_PTFD3:         .equ   3                                         ; Port F Data Register Bit 3
PTFD_PTFD4:         .equ   4                                         ; Port F Data Register Bit 4
PTFD_PTFD5:         .equ   5                                         ; Port F Data Register Bit 5
PTFD_PTFD6:         .equ   6                                         ; Port F Data Register Bit 6
PTFD_PTFD7:         .equ   7                                         ; Port F Data Register Bit 7
; bit position masks
mPTFD_PTFD0:        .equ   %00000001
mPTFD_PTFD1:        .equ   %00000010
mPTFD_PTFD2:        .equ   %00000100
mPTFD_PTFD3:        .equ   %00001000
mPTFD_PTFD4:        .equ   %00010000
mPTFD_PTFD5:        .equ   %00100000
mPTFD_PTFD6:        .equ   %01000000
mPTFD_PTFD7:        .equ   %10000000


;*** PTFDD - Port F Data Direction Register; 0xFFFF800B ***
PTFDD:              .equ   $FFFF800B                                ;*** PTFDD - Port F Data Direction Register; 0xFFFF800B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDD_PTFDD0:       .equ   0                                         ; Data Direction for Port F Bit 0
PTFDD_PTFDD1:       .equ   1                                         ; Data Direction for Port F Bit 1
PTFDD_PTFDD2:       .equ   2                                         ; Data Direction for Port F Bit 2
PTFDD_PTFDD3:       .equ   3                                         ; Data Direction for Port F Bit 3
PTFDD_PTFDD4:       .equ   4                                         ; Data Direction for Port F Bit 4
PTFDD_PTFDD5:       .equ   5                                         ; Data Direction for Port F Bit 5
PTFDD_PTFDD6:       .equ   6                                         ; Data Direction for Port F Bit 6
PTFDD_PTFDD7:       .equ   7                                         ; Data Direction for Port F Bit 7
; bit position masks
mPTFDD_PTFDD0:      .equ   %00000001
mPTFDD_PTFDD1:      .equ   %00000010
mPTFDD_PTFDD2:      .equ   %00000100
mPTFDD_PTFDD3:      .equ   %00001000
mPTFDD_PTFDD4:      .equ   %00010000
mPTFDD_PTFDD5:      .equ   %00100000
mPTFDD_PTFDD6:      .equ   %01000000
mPTFDD_PTFDD7:      .equ   %10000000


;*** PTGD - Port G Data Register; 0xFFFF800C ***
PTGD:               .equ   $FFFF800C                                ;*** PTGD - Port G Data Register; 0xFFFF800C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGD_PTGD0:         .equ   0                                         ; Port G Data Register Bit 0
PTGD_PTGD1:         .equ   1                                         ; Port G Data Register Bit 1
PTGD_PTGD2:         .equ   2                                         ; Port G Data Register Bit 2
PTGD_PTGD3:         .equ   3                                         ; Port G Data Register Bit 3
PTGD_PTGD4:         .equ   4                                         ; Port G Data Register Bit 4
PTGD_PTGD5:         .equ   5                                         ; Port G Data Register Bit 5
PTGD_PTGD6:         .equ   6                                         ; Port G Data Register Bit 6
PTGD_PTGD7:         .equ   7                                         ; Port G Data Register Bit 7
; bit position masks
mPTGD_PTGD0:        .equ   %00000001
mPTGD_PTGD1:        .equ   %00000010
mPTGD_PTGD2:        .equ   %00000100
mPTGD_PTGD3:        .equ   %00001000
mPTGD_PTGD4:        .equ   %00010000
mPTGD_PTGD5:        .equ   %00100000
mPTGD_PTGD6:        .equ   %01000000
mPTGD_PTGD7:        .equ   %10000000


;*** PTGDD - Port G Data Direction Register; 0xFFFF800D ***
PTGDD:              .equ   $FFFF800D                                ;*** PTGDD - Port G Data Direction Register; 0xFFFF800D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDD_PTGDD0:       .equ   0                                         ; Data Direction for Port G Bit 0
PTGDD_PTGDD1:       .equ   1                                         ; Data Direction for Port G Bit 1
PTGDD_PTGDD2:       .equ   2                                         ; Data Direction for Port G Bit 2
PTGDD_PTGDD3:       .equ   3                                         ; Data Direction for Port G Bit 3
PTGDD_PTGDD4:       .equ   4                                         ; Data Direction for Port G Bit 4
PTGDD_PTGDD5:       .equ   5                                         ; Data Direction for Port G Bit 5
PTGDD_PTGDD6:       .equ   6                                         ; Data Direction for Port G Bit 6
PTGDD_PTGDD7:       .equ   7                                         ; Data Direction for Port G Bit 7
; bit position masks
mPTGDD_PTGDD0:      .equ   %00000001
mPTGDD_PTGDD1:      .equ   %00000010
mPTGDD_PTGDD2:      .equ   %00000100
mPTGDD_PTGDD3:      .equ   %00001000
mPTGDD_PTGDD4:      .equ   %00010000
mPTGDD_PTGDD5:      .equ   %00100000
mPTGDD_PTGDD6:      .equ   %01000000
mPTGDD_PTGDD7:      .equ   %10000000


;*** ACMPSC - ACMP Status and Control Register; 0xFFFF800E ***
ACMPSC:             .equ   $FFFF800E                                ;*** ACMPSC - ACMP Status and Control Register; 0xFFFF800E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ACMPSC_ACMOD0:      .equ   0                                         ; Analog Comparator Mode Bit 0
ACMPSC_ACMOD1:      .equ   1                                         ; Analog Comparator Mode Bit 1
ACMPSC_ACOPE:       .equ   2                                         ; Analog Comparator Output Pin Enable
ACMPSC_ACO:         .equ   3                                         ; Analog Comparator Output
ACMPSC_ACIE:        .equ   4                                         ; Analog Comparator Interrupt Enable
ACMPSC_ACF:         .equ   5                                         ; Analog Comparator Flag
ACMPSC_ACBGS:       .equ   6                                         ; Analog Comparator Bandgap Select
ACMPSC_ACME:        .equ   7                                         ; Analog Comparator Module Enable
; bit position masks
mACMPSC_ACMOD0:     .equ   %00000001
mACMPSC_ACMOD1:     .equ   %00000010
mACMPSC_ACOPE:      .equ   %00000100
mACMPSC_ACO:        .equ   %00001000
mACMPSC_ACIE:       .equ   %00010000
mACMPSC_ACF:        .equ   %00100000
mACMPSC_ACBGS:      .equ   %01000000
mACMPSC_ACME:       .equ   %10000000


;*** ADCSC1 - Status and Control Register 1; 0xFFFF8010 ***
ADCSC1:             .equ   $FFFF8010                                ;*** ADCSC1 - Status and Control Register 1; 0xFFFF8010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1_ADCH0:       .equ   0                                         ; Input Channel Select Bit 0
ADCSC1_ADCH1:       .equ   1                                         ; Input Channel Select Bit 1
ADCSC1_ADCH2:       .equ   2                                         ; Input Channel Select Bit 2
ADCSC1_ADCH3:       .equ   3                                         ; Input Channel Select Bit 3
ADCSC1_ADCH4:       .equ   4                                         ; Input Channel Select Bit 4
ADCSC1_ADCO:        .equ   5                                         ; Continuous Conversion Enable - ADCO is used to enable continuous conversions
ADCSC1_AIEN:        .equ   6                                         ; Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while AIEN is high, an interrupt is asserted
ADCSC1_COCO:        .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADCSC1_ADCH0:      .equ   %00000001
mADCSC1_ADCH1:      .equ   %00000010
mADCSC1_ADCH2:      .equ   %00000100
mADCSC1_ADCH3:      .equ   %00001000
mADCSC1_ADCH4:      .equ   %00010000
mADCSC1_ADCO:       .equ   %00100000
mADCSC1_AIEN:       .equ   %01000000
mADCSC1_COCO:       .equ   %10000000


;*** ADCSC2 - Status and Control Register 2; 0xFFFF8011 ***
ADCSC2:             .equ   $FFFF8011                                ;*** ADCSC2 - Status and Control Register 2; 0xFFFF8011 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC2_ACFGT:       .equ   4                                         ; Compare Function Greater Than Enable
ADCSC2_ACFE:        .equ   5                                         ; Compare Function Enable - ACFE is used to enable the compare function
ADCSC2_ADTRG:       .equ   6                                         ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion
ADCSC2_ADACT:       .equ   7                                         ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted
; bit position masks
mADCSC2_ACFGT:      .equ   %00010000
mADCSC2_ACFE:       .equ   %00100000
mADCSC2_ADTRG:      .equ   %01000000
mADCSC2_ADACT:      .equ   %10000000


;*** ADCR - Data Result Register; 0xFFFF8012 ***
ADCR:               .equ   $FFFF8012                                ;*** ADCR - Data Result Register; 0xFFFF8012 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCR_ADR0:          .equ   0                                         ; ADC Result Data Bit 0
ADCR_ADR1:          .equ   1                                         ; ADC Result Data Bit 1
ADCR_ADR2:          .equ   2                                         ; ADC Result Data Bit 2
ADCR_ADR3:          .equ   3                                         ; ADC Result Data Bit 3
ADCR_ADR4:          .equ   4                                         ; ADC Result Data Bit 4
ADCR_ADR5:          .equ   5                                         ; ADC Result Data Bit 5
ADCR_ADR6:          .equ   6                                         ; ADC Result Data Bit 6
ADCR_ADR7:          .equ   7                                         ; ADC Result Data Bit 7
ADCR_ADR8:          .equ   8                                         ; ADC Result Data Bit 8
ADCR_ADR9:          .equ   9                                         ; ADC Result Data Bit 9
ADCR_ADR10:         .equ   10                                        ; ADC Result Data Bit 10
ADCR_ADR11:         .equ   11                                        ; ADC Result Data Bit 11
; bit position masks
mADCR_ADR0:         .equ   %00000001
mADCR_ADR1:         .equ   %00000010
mADCR_ADR2:         .equ   %00000100
mADCR_ADR3:         .equ   %00001000
mADCR_ADR4:         .equ   %00010000
mADCR_ADR5:         .equ   %00100000
mADCR_ADR6:         .equ   %01000000
mADCR_ADR7:         .equ   %10000000
mADCR_ADR8:         .equ   %100000000
mADCR_ADR9:         .equ   %1000000000
mADCR_ADR10:        .equ   %10000000000
mADCR_ADR11:        .equ   %100000000000


;*** ADCRH - Data Result High Register; 0xFFFF8012 ***
ADCRH:              .equ   $FFFF8012                                ;*** ADCRH - Data Result High Register; 0xFFFF8012 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRH_ADR8:         .equ   0                                         ; ADC Result Data Bit 8
ADCRH_ADR9:         .equ   1                                         ; ADC Result Data Bit 9
ADCRH_ADR10:        .equ   2                                         ; ADC Result Data Bit 10
ADCRH_ADR11:        .equ   3                                         ; ADC Result Data Bit 11
; bit position masks
mADCRH_ADR8:        .equ   %00000001
mADCRH_ADR9:        .equ   %00000010
mADCRH_ADR10:       .equ   %00000100
mADCRH_ADR11:       .equ   %00001000


;*** ADCRL - Data Result Low Register; 0xFFFF8013 ***
ADCRL:              .equ   $FFFF8013                                ;*** ADCRL - Data Result Low Register; 0xFFFF8013 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRL_ADR0:         .equ   0                                         ; ADC Result Data Bit 0
ADCRL_ADR1:         .equ   1                                         ; ADC Result Data Bit 1
ADCRL_ADR2:         .equ   2                                         ; ADC Result Data Bit 2
ADCRL_ADR3:         .equ   3                                         ; ADC Result Data Bit 3
ADCRL_ADR4:         .equ   4                                         ; ADC Result Data Bit 4
ADCRL_ADR5:         .equ   5                                         ; ADC Result Data Bit 5
ADCRL_ADR6:         .equ   6                                         ; ADC Result Data Bit 6
ADCRL_ADR7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADCRL_ADR0:        .equ   %00000001
mADCRL_ADR1:        .equ   %00000010
mADCRL_ADR2:        .equ   %00000100
mADCRL_ADR3:        .equ   %00001000
mADCRL_ADR4:        .equ   %00010000
mADCRL_ADR5:        .equ   %00100000
mADCRL_ADR6:        .equ   %01000000
mADCRL_ADR7:        .equ   %10000000


;*** ADCCV - Compare Value Register; 0xFFFF8014 ***
ADCCV:              .equ   $FFFF8014                                ;*** ADCCV - Compare Value Register; 0xFFFF8014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV_ADCV0:        .equ   0                                         ; Compare Function Value 0
ADCCV_ADCV1:        .equ   1                                         ; Compare Function Value 1
ADCCV_ADCV2:        .equ   2                                         ; Compare Function Value 2
ADCCV_ADCV3:        .equ   3                                         ; Compare Function Value 3
ADCCV_ADCV4:        .equ   4                                         ; Compare Function Value 4
ADCCV_ADCV5:        .equ   5                                         ; Compare Function Value 5
ADCCV_ADCV6:        .equ   6                                         ; Compare Function Value 6
ADCCV_ADCV7:        .equ   7                                         ; Compare Function Value 7
ADCCV_ADCV8:        .equ   8                                         ; Compare Function Value 8
ADCCV_ADCV9:        .equ   9                                         ; Compare Function Value 9
ADCCV_ADCV10:       .equ   10                                        ; Compare Function Value 10
ADCCV_ADCV11:       .equ   11                                        ; Compare Function Value 11
; bit position masks
mADCCV_ADCV0:       .equ   %00000001
mADCCV_ADCV1:       .equ   %00000010
mADCCV_ADCV2:       .equ   %00000100
mADCCV_ADCV3:       .equ   %00001000
mADCCV_ADCV4:       .equ   %00010000
mADCCV_ADCV5:       .equ   %00100000
mADCCV_ADCV6:       .equ   %01000000
mADCCV_ADCV7:       .equ   %10000000
mADCCV_ADCV8:       .equ   %100000000
mADCCV_ADCV9:       .equ   %1000000000
mADCCV_ADCV10:      .equ   %10000000000
mADCCV_ADCV11:      .equ   %100000000000


;*** ADCCVH - Compare Value High Register; 0xFFFF8014 ***
ADCCVH:             .equ   $FFFF8014                                ;*** ADCCVH - Compare Value High Register; 0xFFFF8014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCVH_ADCV8:       .equ   0                                         ; Compare Function Value 8
ADCCVH_ADCV9:       .equ   1                                         ; Compare Function Value 9
ADCCVH_ADCV10:      .equ   2                                         ; Compare Function Value 10
ADCCVH_ADCV11:      .equ   3                                         ; Compare Function Value 11
; bit position masks
mADCCVH_ADCV8:      .equ   %00000001
mADCCVH_ADCV9:      .equ   %00000010
mADCCVH_ADCV10:     .equ   %00000100
mADCCVH_ADCV11:     .equ   %00001000


;*** ADCCVL - Compare Value Low Register; 0xFFFF8015 ***
ADCCVL:             .equ   $FFFF8015                                ;*** ADCCVL - Compare Value Low Register; 0xFFFF8015 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCVL_ADCV0:       .equ   0                                         ; Compare Function Value 0
ADCCVL_ADCV1:       .equ   1                                         ; Compare Function Value 1
ADCCVL_ADCV2:       .equ   2                                         ; Compare Function Value 2
ADCCVL_ADCV3:       .equ   3                                         ; Compare Function Value 3
ADCCVL_ADCV4:       .equ   4                                         ; Compare Function Value 4
ADCCVL_ADCV5:       .equ   5                                         ; Compare Function Value 5
ADCCVL_ADCV6:       .equ   6                                         ; Compare Function Value 6
ADCCVL_ADCV7:       .equ   7                                         ; Compare Function Value 7
; bit position masks
mADCCVL_ADCV0:      .equ   %00000001
mADCCVL_ADCV1:      .equ   %00000010
mADCCVL_ADCV2:      .equ   %00000100
mADCCVL_ADCV3:      .equ   %00001000
mADCCVL_ADCV4:      .equ   %00010000
mADCCVL_ADCV5:      .equ   %00100000
mADCCVL_ADCV6:      .equ   %01000000
mADCCVL_ADCV7:      .equ   %10000000


;*** ADCCFG - Configuration Register; 0xFFFF8016 ***
ADCCFG:             .equ   $FFFF8016                                ;*** ADCCFG - Configuration Register; 0xFFFF8016 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCFG_ADICLK0:     .equ   0                                         ; Input Clock Select Bit 0
ADCCFG_ADICLK1:     .equ   1                                         ; Input Clock Select Bit 1
ADCCFG_MODE0:       .equ   2                                         ; Conversion Mode Selection Bit 0
ADCCFG_MODE1:       .equ   3                                         ; Conversion Mode Selection Bit 1
ADCCFG_ADLSMP:      .equ   4                                         ; Long Sample Time Configuration
ADCCFG_ADIV0:       .equ   5                                         ; Clock Divide Select Bit 0
ADCCFG_ADIV1:       .equ   6                                         ; Clock Divide Select Bit 1
ADCCFG_ADLPC:       .equ   7                                         ; Low Power Configuration
; bit position masks
mADCCFG_ADICLK0:    .equ   %00000001
mADCCFG_ADICLK1:    .equ   %00000010
mADCCFG_MODE0:      .equ   %00000100
mADCCFG_MODE1:      .equ   %00001000
mADCCFG_ADLSMP:     .equ   %00010000
mADCCFG_ADIV0:      .equ   %00100000
mADCCFG_ADIV1:      .equ   %01000000
mADCCFG_ADLPC:      .equ   %10000000


;*** APCTL1 - Pin Control 1 Register; 0xFFFF8017 ***
APCTL1:             .equ   $FFFF8017                                ;*** APCTL1 - Pin Control 1 Register; 0xFFFF8017 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL1_ADPC0:       .equ   0                                         ; ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0
APCTL1_ADPC1:       .equ   1                                         ; ADC Pin Control 1 - ADPC1 is used to control the pin associated with channel AD1
APCTL1_ADPC2:       .equ   2                                         ; ADC Pin Control 2 - ADPC2 is used to control the pin associated with channel AD2
APCTL1_ADPC3:       .equ   3                                         ; ADC Pin Control 3 - ADPC3 is used to control the pin associated with channel AD3
APCTL1_ADPC4:       .equ   4                                         ; ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4
APCTL1_ADPC5:       .equ   5                                         ; ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5
APCTL1_ADPC6:       .equ   6                                         ; ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6
APCTL1_ADPC7:       .equ   7                                         ; ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7
; bit position masks
mAPCTL1_ADPC0:      .equ   %00000001
mAPCTL1_ADPC1:      .equ   %00000010
mAPCTL1_ADPC2:      .equ   %00000100
mAPCTL1_ADPC3:      .equ   %00001000
mAPCTL1_ADPC4:      .equ   %00010000
mAPCTL1_ADPC5:      .equ   %00100000
mAPCTL1_ADPC6:      .equ   %01000000
mAPCTL1_ADPC7:      .equ   %10000000


;*** APCTL2 - Pin Control 2 Register; 0xFFFF8018 ***
APCTL2:             .equ   $FFFF8018                                ;*** APCTL2 - Pin Control 2 Register; 0xFFFF8018 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL2_ADPC8:       .equ   0                                         ; ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8
APCTL2_ADPC9:       .equ   1                                         ; ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9
APCTL2_ADPC10:      .equ   2                                         ; ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10
APCTL2_ADPC11:      .equ   3                                         ; ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11
; bit position masks
mAPCTL2_ADPC8:      .equ   %00000001
mAPCTL2_ADPC9:      .equ   %00000010
mAPCTL2_ADPC10:     .equ   %00000100
mAPCTL2_ADPC11:     .equ   %00001000


;*** IRQSC - Interrupt request status and control register; 0xFFFF801B ***
IRQSC:              .equ   $FFFF801B                                ;*** IRQSC - Interrupt request status and control register; 0xFFFF801B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD:       .equ   0                                         ; IRQ Detection Mode
IRQSC_IRQIE:        .equ   1                                         ; IRQ Interrupt Enable
IRQSC_IRQACK:       .equ   2                                         ; IRQ Acknowledge
IRQSC_IRQF:         .equ   3                                         ; IRQ Flag
IRQSC_IRQPE:        .equ   4                                         ; IRQ Pin Enable
IRQSC_IRQEDG:       .equ   5                                         ; IRQ Edge Select
IRQSC_IRQPDD:       .equ   6                                         ; IRQ Pull Device Disable
; bit position masks
mIRQSC_IRQMOD:      .equ   %00000001
mIRQSC_IRQIE:       .equ   %00000010
mIRQSC_IRQACK:      .equ   %00000100
mIRQSC_IRQF:        .equ   %00001000
mIRQSC_IRQPE:       .equ   %00010000
mIRQSC_IRQEDG:      .equ   %00100000
mIRQSC_IRQPDD:      .equ   %01000000


;*** KBI1SC - KBI1 Status and Control Register; 0xFFFF801C ***
KBI1SC:             .equ   $FFFF801C                                ;*** KBI1SC - KBI1 Status and Control Register; 0xFFFF801C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1SC_KBIMOD:      .equ   0                                         ; Keyboard Detection Mode
KBI1SC_KBIE:        .equ   1                                         ; Keyboard Interrupt Enable
KBI1SC_KBACK:       .equ   2                                         ; Keyboard Interrupt Acknowledge
KBI1SC_KBF:         .equ   3                                         ; Keyboard Interrupt Flag
; bit position masks
mKBI1SC_KBIMOD:     .equ   %00000001
mKBI1SC_KBIE:       .equ   %00000010
mKBI1SC_KBACK:      .equ   %00000100
mKBI1SC_KBF:        .equ   %00001000


;*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF801D ***
KBI1PE:             .equ   $FFFF801D                                ;*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF801D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1PE_KBIPE0:      .equ   0                                         ; Keyboard Pin Enable for KBI Port Bit 0
KBI1PE_KBIPE1:      .equ   1                                         ; Keyboard Pin Enable for KBI Port Bit 1
KBI1PE_KBIPE2:      .equ   2                                         ; Keyboard Pin Enable for KBI Port Bit 2
KBI1PE_KBIPE3:      .equ   3                                         ; Keyboard Pin Enable for KBI Port Bit 3
KBI1PE_KBIPE4:      .equ   4                                         ; Keyboard Pin Enable for KBI Port Bit 4
KBI1PE_KBIPE5:      .equ   5                                         ; Keyboard Pin Enable for KBI Port Bit 5
KBI1PE_KBIPE6:      .equ   6                                         ; Keyboard Pin Enable for KBI Port Bit 6
KBI1PE_KBIPE7:      .equ   7                                         ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI1PE_KBIPE0:     .equ   %00000001
mKBI1PE_KBIPE1:     .equ   %00000010
mKBI1PE_KBIPE2:     .equ   %00000100
mKBI1PE_KBIPE3:     .equ   %00001000
mKBI1PE_KBIPE4:     .equ   %00010000
mKBI1PE_KBIPE5:     .equ   %00100000
mKBI1PE_KBIPE6:     .equ   %01000000
mKBI1PE_KBIPE7:     .equ   %10000000


;*** KBI1ES - KBI1 Edge Select Register; 0xFFFF801E ***
KBI1ES:             .equ   $FFFF801E                                ;*** KBI1ES - KBI1 Edge Select Register; 0xFFFF801E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1ES_KBEDG0:      .equ   0                                         ; Keyboard Edge Select Bit 0
KBI1ES_KBEDG1:      .equ   1                                         ; Keyboard Edge Select Bit 1
KBI1ES_KBEDG2:      .equ   2                                         ; Keyboard Edge Select Bit 2
KBI1ES_KBEDG3:      .equ   3                                         ; Keyboard Edge Select Bit 3
KBI1ES_KBEDG4:      .equ   4                                         ; Keyboard Edge Select Bit 4
KBI1ES_KBEDG5:      .equ   5                                         ; Keyboard Edge Select Bit 5
KBI1ES_KBEDG6:      .equ   6                                         ; Keyboard Edge Select Bit 6
KBI1ES_KBEDG7:      .equ   7                                         ; Keyboard Edge Select Bit 7
; bit position masks
mKBI1ES_KBEDG0:     .equ   %00000001
mKBI1ES_KBEDG1:     .equ   %00000010
mKBI1ES_KBEDG2:     .equ   %00000100
mKBI1ES_KBEDG3:     .equ   %00001000
mKBI1ES_KBEDG4:     .equ   %00010000
mKBI1ES_KBEDG5:     .equ   %00100000
mKBI1ES_KBEDG6:     .equ   %01000000
mKBI1ES_KBEDG7:     .equ   %10000000


;*** TPM1SC - TPM1 Status and Control Register; 0xFFFF8020 ***
TPM1SC:             .equ   $FFFF8020                                ;*** TPM1SC - TPM1 Status and Control Register; 0xFFFF8020 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1SC_PS0:         .equ   0                                         ; Prescale Divisor Select Bit 0
TPM1SC_PS1:         .equ   1                                         ; Prescale Divisor Select Bit 1
TPM1SC_PS2:         .equ   2                                         ; Prescale Divisor Select Bit 2
TPM1SC_CLKSA:       .equ   3                                         ; Clock Source Select A
TPM1SC_CLKSB:       .equ   4                                         ; Clock Source Select B
TPM1SC_CPWMS:       .equ   5                                         ; Center-Aligned PWM Select
TPM1SC_TOIE:        .equ   6                                         ; Timer Overflow Interrupt Enable
TPM1SC_TOF:         .equ   7                                         ; Timer Overflow Flag
; bit position masks
mTPM1SC_PS0:        .equ   %00000001
mTPM1SC_PS1:        .equ   %00000010
mTPM1SC_PS2:        .equ   %00000100
mTPM1SC_CLKSA:      .equ   %00001000
mTPM1SC_CLKSB:      .equ   %00010000
mTPM1SC_CPWMS:      .equ   %00100000
mTPM1SC_TOIE:       .equ   %01000000
mTPM1SC_TOF:        .equ   %10000000


;*** TPM1CNT - TPM1 Timer Counter Register; 0xFFFF8021 ***
TPM1CNT:            .equ   $FFFF8021                                ;*** TPM1CNT - TPM1 Timer Counter Register; 0xFFFF8021 ***


;*** TPM1CNTH - TPM1 Timer Counter Register High; 0xFFFF8021 ***
TPM1CNTH:           .equ   $FFFF8021                                ;*** TPM1CNTH - TPM1 Timer Counter Register High; 0xFFFF8021 ***


;*** TPM1CNTL - TPM1 Timer Counter Register Low; 0xFFFF8022 ***
TPM1CNTL:           .equ   $FFFF8022                                ;*** TPM1CNTL - TPM1 Timer Counter Register Low; 0xFFFF8022 ***


;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0xFFFF8023 ***
TPM1MOD:            .equ   $FFFF8023                                ;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0xFFFF8023 ***


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0xFFFF8023 ***
TPM1MODH:           .equ   $FFFF8023                                ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0xFFFF8023 ***


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0xFFFF8024 ***
TPM1MODL:           .equ   $FFFF8024                                ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0xFFFF8024 ***


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0xFFFF8025 ***
TPM1C0SC:           .equ   $FFFF8025                                ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0xFFFF8025 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C0SC_ELS0A:     .equ   2                                         ; Edge/Level Select Bit A
TPM1C0SC_ELS0B:     .equ   3                                         ; Edge/Level Select Bit B
TPM1C0SC_MS0A:      .equ   4                                         ; Mode Select A for TPM Channel 0
TPM1C0SC_MS0B:      .equ   5                                         ; Mode Select B for TPM Channel 0
TPM1C0SC_CH0IE:     .equ   6                                         ; Channel 0 Interrupt Enable
TPM1C0SC_CH0F:      .equ   7                                         ; Channel 0 Flag
; bit position masks
mTPM1C0SC_ELS0A:    .equ   %00000100
mTPM1C0SC_ELS0B:    .equ   %00001000
mTPM1C0SC_MS0A:     .equ   %00010000
mTPM1C0SC_MS0B:     .equ   %00100000
mTPM1C0SC_CH0IE:    .equ   %01000000
mTPM1C0SC_CH0F:     .equ   %10000000


;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0xFFFF8026 ***
TPM1C0V:            .equ   $FFFF8026                                ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0xFFFF8026 ***


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0xFFFF8026 ***
TPM1C0VH:           .equ   $FFFF8026                                ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0xFFFF8026 ***


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0xFFFF8027 ***
TPM1C0VL:           .equ   $FFFF8027                                ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0xFFFF8027 ***


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0xFFFF8028 ***
TPM1C1SC:           .equ   $FFFF8028                                ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0xFFFF8028 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C1SC_ELS1A:     .equ   2                                         ; Edge/Level Select Bit A
TPM1C1SC_ELS1B:     .equ   3                                         ; Edge/Level Select Bit B
TPM1C1SC_MS1A:      .equ   4                                         ; Mode Select A for TPM Channel 1
TPM1C1SC_MS1B:      .equ   5                                         ; Mode Select B for TPM Channel 1
TPM1C1SC_CH1IE:     .equ   6                                         ; Channel 1 Interrupt Enable
TPM1C1SC_CH1F:      .equ   7                                         ; Channel 1 Flag
; bit position masks
mTPM1C1SC_ELS1A:    .equ   %00000100
mTPM1C1SC_ELS1B:    .equ   %00001000
mTPM1C1SC_MS1A:     .equ   %00010000
mTPM1C1SC_MS1B:     .equ   %00100000
mTPM1C1SC_CH1IE:    .equ   %01000000
mTPM1C1SC_CH1F:     .equ   %10000000


;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0xFFFF8029 ***
TPM1C1V:            .equ   $FFFF8029                                ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0xFFFF8029 ***


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0xFFFF8029 ***
TPM1C1VH:           .equ   $FFFF8029                                ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0xFFFF8029 ***


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0xFFFF802A ***
TPM1C1VL:           .equ   $FFFF802A                                ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0xFFFF802A ***


;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register; 0xFFFF802B ***
TPM1C2SC:           .equ   $FFFF802B                                ;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register; 0xFFFF802B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C2SC_ELS2A:     .equ   2                                         ; Edge/Level Select Bit A
TPM1C2SC_ELS2B:     .equ   3                                         ; Edge/Level Select Bit B
TPM1C2SC_MS2A:      .equ   4                                         ; Mode Select A for TPM Channel 2
TPM1C2SC_MS2B:      .equ   5                                         ; Mode Select B for TPM Channel 2
TPM1C2SC_CH2IE:     .equ   6                                         ; Channel 2 Interrupt Enable
TPM1C2SC_CH2F:      .equ   7                                         ; Channel 2 Flag
; bit position masks
mTPM1C2SC_ELS2A:    .equ   %00000100
mTPM1C2SC_ELS2B:    .equ   %00001000
mTPM1C2SC_MS2A:     .equ   %00010000
mTPM1C2SC_MS2B:     .equ   %00100000
mTPM1C2SC_CH2IE:    .equ   %01000000
mTPM1C2SC_CH2F:     .equ   %10000000


;*** TPM1C2V - TPM1 Timer Channel 2 Value Register; 0xFFFF802C ***
TPM1C2V:            .equ   $FFFF802C                                ;*** TPM1C2V - TPM1 Timer Channel 2 Value Register; 0xFFFF802C ***


;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High; 0xFFFF802C ***
TPM1C2VH:           .equ   $FFFF802C                                ;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High; 0xFFFF802C ***


;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low; 0xFFFF802D ***
TPM1C2VL:           .equ   $FFFF802D                                ;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low; 0xFFFF802D ***


;*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register; 0xFFFF802E ***
TPM1C3SC:           .equ   $FFFF802E                                ;*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register; 0xFFFF802E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C3SC_ELS3A:     .equ   2                                         ; Edge/Level Select Bit A
TPM1C3SC_ELS3B:     .equ   3                                         ; Edge/Level Select Bit B
TPM1C3SC_MS3A:      .equ   4                                         ; Mode Select A for TPM Channel 3
TPM1C3SC_MS3B:      .equ   5                                         ; Mode Select B for TPM Channel 3
TPM1C3SC_CH3IE:     .equ   6                                         ; Channel 3 Interrupt Enable
TPM1C3SC_CH3F:      .equ   7                                         ; Channel 3 Flag
; bit position masks
mTPM1C3SC_ELS3A:    .equ   %00000100
mTPM1C3SC_ELS3B:    .equ   %00001000
mTPM1C3SC_MS3A:     .equ   %00010000
mTPM1C3SC_MS3B:     .equ   %00100000
mTPM1C3SC_CH3IE:    .equ   %01000000
mTPM1C3SC_CH3F:     .equ   %10000000


;*** TPM1C3V - TPM1 Timer Channel 3 Value Register; 0xFFFF802F ***
TPM1C3V:            .equ   $FFFF802F                                ;*** TPM1C3V - TPM1 Timer Channel 3 Value Register; 0xFFFF802F ***


;*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High; 0xFFFF802F ***
TPM1C3VH:           .equ   $FFFF802F                                ;*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High; 0xFFFF802F ***


;*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low; 0xFFFF8030 ***
TPM1C3VL:           .equ   $FFFF8030                                ;*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low; 0xFFFF8030 ***


;*** TPM1C4SC - TPM1 Timer Channel 4 Status and Control Register; 0xFFFF8031 ***
TPM1C4SC:           .equ   $FFFF8031                                ;*** TPM1C4SC - TPM1 Timer Channel 4 Status and Control Register; 0xFFFF8031 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C4SC_ELS4A:     .equ   2                                         ; Edge/Level Select Bit A
TPM1C4SC_ELS4B:     .equ   3                                         ; Edge/Level Select Bit B
TPM1C4SC_MS4A:      .equ   4                                         ; Mode Select A for TPM Channel 4
TPM1C4SC_MS4B:      .equ   5                                         ; Mode Select B for TPM Channel 4
TPM1C4SC_CH4IE:     .equ   6                                         ; Channel 4 Interrupt Enable
TPM1C4SC_CH4F:      .equ   7                                         ; Channel 4 Flag
; bit position masks
mTPM1C4SC_ELS4A:    .equ   %00000100
mTPM1C4SC_ELS4B:    .equ   %00001000
mTPM1C4SC_MS4A:     .equ   %00010000
mTPM1C4SC_MS4B:     .equ   %00100000
mTPM1C4SC_CH4IE:    .equ   %01000000
mTPM1C4SC_CH4F:     .equ   %10000000


;*** TPM1C4V - TPM1 Timer Channel 4 Value Register; 0xFFFF8032 ***
TPM1C4V:            .equ   $FFFF8032                                ;*** TPM1C4V - TPM1 Timer Channel 4 Value Register; 0xFFFF8032 ***


;*** TPM1C4VH - TPM1 Timer Channel 4 Value Register High; 0xFFFF8032 ***
TPM1C4VH:           .equ   $FFFF8032                                ;*** TPM1C4VH - TPM1 Timer Channel 4 Value Register High; 0xFFFF8032 ***


;*** TPM1C4VL - TPM1 Timer Channel 4 Value Register Low; 0xFFFF8033 ***
TPM1C4VL:           .equ   $FFFF8033                                ;*** TPM1C4VL - TPM1 Timer Channel 4 Value Register Low; 0xFFFF8033 ***


;*** TPM1C5SC - TPM1 Timer Channel 5 Status and Control Register; 0xFFFF8034 ***
TPM1C5SC:           .equ   $FFFF8034                                ;*** TPM1C5SC - TPM1 Timer Channel 5 Status and Control Register; 0xFFFF8034 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C5SC_ELS5A:     .equ   2                                         ; Edge/Level Select Bit A
TPM1C5SC_ELS5B:     .equ   3                                         ; Edge/Level Select Bit B
TPM1C5SC_MS5A:      .equ   4                                         ; Mode Select A for TPM Channel 5
TPM1C5SC_MS5B:      .equ   5                                         ; Mode Select B for TPM Channel 5
TPM1C5SC_CH5IE:     .equ   6                                         ; Channel 5 Interrupt Enable
TPM1C5SC_CH5F:      .equ   7                                         ; Channel 5 Flag
; bit position masks
mTPM1C5SC_ELS5A:    .equ   %00000100
mTPM1C5SC_ELS5B:    .equ   %00001000
mTPM1C5SC_MS5A:     .equ   %00010000
mTPM1C5SC_MS5B:     .equ   %00100000
mTPM1C5SC_CH5IE:    .equ   %01000000
mTPM1C5SC_CH5F:     .equ   %10000000


;*** TPM1C5V - TPM1 Timer Channel 5 Value Register; 0xFFFF8035 ***
TPM1C5V:            .equ   $FFFF8035                                ;*** TPM1C5V - TPM1 Timer Channel 5 Value Register; 0xFFFF8035 ***


;*** TPM1C5VH - TPM1 Timer Channel 5 Value Register High; 0xFFFF8035 ***
TPM1C5VH:           .equ   $FFFF8035                                ;*** TPM1C5VH - TPM1 Timer Channel 5 Value Register High; 0xFFFF8035 ***


;*** TPM1C5VL - TPM1 Timer Channel 5 Value Register Low; 0xFFFF8036 ***
TPM1C5VL:           .equ   $FFFF8036                                ;*** TPM1C5VL - TPM1 Timer Channel 5 Value Register Low; 0xFFFF8036 ***


;*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF8038 ***
SCI1BD:             .equ   $FFFF8038                                ;*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF8038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BD_SBR0:        .equ   0                                         ; Baud Rate Modulo Divisor Bit 0
SCI1BD_SBR1:        .equ   1                                         ; Baud Rate Modulo Divisor Bit 1
SCI1BD_SBR2:        .equ   2                                         ; Baud Rate Modulo Divisor Bit 2
SCI1BD_SBR3:        .equ   3                                         ; Baud Rate Modulo Divisor Bit 3
SCI1BD_SBR4:        .equ   4                                         ; Baud Rate Modulo Divisor Bit 4
SCI1BD_SBR5:        .equ   5                                         ; Baud Rate Modulo Divisor Bit 5
SCI1BD_SBR6:        .equ   6                                         ; Baud Rate Modulo Divisor Bit 6
SCI1BD_SBR7:        .equ   7                                         ; Baud Rate Modulo Divisor Bit 7
SCI1BD_SBR8:        .equ   8                                         ; Baud Rate Modulo Divisor Bit 8
SCI1BD_SBR9:        .equ   9                                         ; Baud Rate Modulo Divisor Bit 9
SCI1BD_SBR10:       .equ   10                                        ; Baud Rate Modulo Divisor Bit 10
SCI1BD_SBR11:       .equ   11                                        ; Baud Rate Modulo Divisor Bit 11
SCI1BD_SBR12:       .equ   12                                        ; Baud Rate Modulo Divisor Bit 12
SCI1BD_RXEDGIE:     .equ   14                                        ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI1BD_LBKDIE:      .equ   15                                        ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI1BD_SBR0:       .equ   %00000001
mSCI1BD_SBR1:       .equ   %00000010
mSCI1BD_SBR2:       .equ   %00000100
mSCI1BD_SBR3:       .equ   %00001000
mSCI1BD_SBR4:       .equ   %00010000
mSCI1BD_SBR5:       .equ   %00100000
mSCI1BD_SBR6:       .equ   %01000000
mSCI1BD_SBR7:       .equ   %10000000
mSCI1BD_SBR8:       .equ   %100000000
mSCI1BD_SBR9:       .equ   %1000000000
mSCI1BD_SBR10:      .equ   %10000000000
mSCI1BD_SBR11:      .equ   %100000000000
mSCI1BD_SBR12:      .equ   %1000000000000
mSCI1BD_RXEDGIE:    .equ   %100000000000000
mSCI1BD_LBKDIE:     .equ   %1000000000000000


;*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF8038 ***
SCI1BDH:            .equ   $FFFF8038                                ;*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF8038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8:       .equ   0                                         ; Baud Rate Modulo Divisor Bit 8
SCI1BDH_SBR9:       .equ   1                                         ; Baud Rate Modulo Divisor Bit 9
SCI1BDH_SBR10:      .equ   2                                         ; Baud Rate Modulo Divisor Bit 10
SCI1BDH_SBR11:      .equ   3                                         ; Baud Rate Modulo Divisor Bit 11
SCI1BDH_SBR12:      .equ   4                                         ; Baud Rate Modulo Divisor Bit 12
SCI1BDH_RXEDGIE:    .equ   6                                         ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI1BDH_LBKDIE:     .equ   7                                         ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI1BDH_SBR8:      .equ   %00000001
mSCI1BDH_SBR9:      .equ   %00000010
mSCI1BDH_SBR10:     .equ   %00000100
mSCI1BDH_SBR11:     .equ   %00001000
mSCI1BDH_SBR12:     .equ   %00010000
mSCI1BDH_RXEDGIE:   .equ   %01000000
mSCI1BDH_LBKDIE:    .equ   %10000000


;*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF8039 ***
SCI1BDL:            .equ   $FFFF8039                                ;*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF8039 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDL_SBR0:       .equ   0                                         ; Baud Rate Modulo Divisor Bit 0
SCI1BDL_SBR1:       .equ   1                                         ; Baud Rate Modulo Divisor Bit 1
SCI1BDL_SBR2:       .equ   2                                         ; Baud Rate Modulo Divisor Bit 2
SCI1BDL_SBR3:       .equ   3                                         ; Baud Rate Modulo Divisor Bit 3
SCI1BDL_SBR4:       .equ   4                                         ; Baud Rate Modulo Divisor Bit 4
SCI1BDL_SBR5:       .equ   5                                         ; Baud Rate Modulo Divisor Bit 5
SCI1BDL_SBR6:       .equ   6                                         ; Baud Rate Modulo Divisor Bit 6
SCI1BDL_SBR7:       .equ   7                                         ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI1BDL_SBR0:      .equ   %00000001
mSCI1BDL_SBR1:      .equ   %00000010
mSCI1BDL_SBR2:      .equ   %00000100
mSCI1BDL_SBR3:      .equ   %00001000
mSCI1BDL_SBR4:      .equ   %00010000
mSCI1BDL_SBR5:      .equ   %00100000
mSCI1BDL_SBR6:      .equ   %01000000
mSCI1BDL_SBR7:      .equ   %10000000


;*** SCI1C1 - SCI1 Control Register 1; 0xFFFF803A ***
SCI1C1:             .equ   $FFFF803A                                ;*** SCI1C1 - SCI1 Control Register 1; 0xFFFF803A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C1_PT:          .equ   0                                         ; Parity Type
SCI1C1_PE:          .equ   1                                         ; Parity Enable
SCI1C1_ILT:         .equ   2                                         ; Idle Line Type Select
SCI1C1_WAKE:        .equ   3                                         ; Receiver Wakeup Method Select
SCI1C1_M:           .equ   4                                         ; 9-Bit or 8-Bit Mode Select
SCI1C1_RSRC:        .equ   5                                         ; Receiver Source Select
SCI1C1_SCISWAI:     .equ   6                                         ; SCI Stops in Wait Mode
SCI1C1_LOOPS:       .equ   7                                         ; Loop Mode Select
; bit position masks
mSCI1C1_PT:         .equ   %00000001
mSCI1C1_PE:         .equ   %00000010
mSCI1C1_ILT:        .equ   %00000100
mSCI1C1_WAKE:       .equ   %00001000
mSCI1C1_M:          .equ   %00010000
mSCI1C1_RSRC:       .equ   %00100000
mSCI1C1_SCISWAI:    .equ   %01000000
mSCI1C1_LOOPS:      .equ   %10000000


;*** SCI1C2 - SCI1 Control Register 2; 0xFFFF803B ***
SCI1C2:             .equ   $FFFF803B                                ;*** SCI1C2 - SCI1 Control Register 2; 0xFFFF803B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C2_SBK:         .equ   0                                         ; Send Break
SCI1C2_RWU:         .equ   1                                         ; Receiver Wakeup Control
SCI1C2_RE:          .equ   2                                         ; Receiver Enable
SCI1C2_TE:          .equ   3                                         ; Transmitter Enable
SCI1C2_ILIE:        .equ   4                                         ; Idle Line Interrupt Enable (for IDLE)
SCI1C2_RIE:         .equ   5                                         ; Receiver Interrupt Enable (for RDRF)
SCI1C2_TCIE:        .equ   6                                         ; Transmission Complete Interrupt Enable (for TC)
SCI1C2_TIE:         .equ   7                                         ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI1C2_SBK:        .equ   %00000001
mSCI1C2_RWU:        .equ   %00000010
mSCI1C2_RE:         .equ   %00000100
mSCI1C2_TE:         .equ   %00001000
mSCI1C2_ILIE:       .equ   %00010000
mSCI1C2_RIE:        .equ   %00100000
mSCI1C2_TCIE:       .equ   %01000000
mSCI1C2_TIE:        .equ   %10000000


;*** SCI1S1 - SCI1 Status Register 1; 0xFFFF803C ***
SCI1S1:             .equ   $FFFF803C                                ;*** SCI1S1 - SCI1 Status Register 1; 0xFFFF803C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S1_PF:          .equ   0                                         ; Parity Error Flag
SCI1S1_FE:          .equ   1                                         ; Framing Error Flag
SCI1S1_NF:          .equ   2                                         ; Noise Flag
SCI1S1_OR:          .equ   3                                         ; Receiver Overrun Flag
SCI1S1_IDLE:        .equ   4                                         ; Idle Line Flag
SCI1S1_RDRF:        .equ   5                                         ; Receive Data Register Full Flag
SCI1S1_TC:          .equ   6                                         ; Transmission Complete Flag
SCI1S1_TDRE:        .equ   7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI1S1_PF:         .equ   %00000001
mSCI1S1_FE:         .equ   %00000010
mSCI1S1_NF:         .equ   %00000100
mSCI1S1_OR:         .equ   %00001000
mSCI1S1_IDLE:       .equ   %00010000
mSCI1S1_RDRF:       .equ   %00100000
mSCI1S1_TC:         .equ   %01000000
mSCI1S1_TDRE:       .equ   %10000000


;*** SCI1S2 - SCI1 Status Register 2; 0xFFFF803D ***
SCI1S2:             .equ   $FFFF803D                                ;*** SCI1S2 - SCI1 Status Register 2; 0xFFFF803D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S2_RAF:         .equ   0                                         ; Receiver Active Flag
SCI1S2_LBKDE:       .equ   1                                         ; LIN Break Detection Enable
SCI1S2_BRK13:       .equ   2                                         ; Break Character Generation Length
SCI1S2_RWUID:       .equ   3                                         ; Receive Wake Up Idle Detect
SCI1S2_RXINV:       .equ   4                                         ; Receive Data Inversion
SCI1S2_RXEDGIF:     .equ   6                                         ; RxD Pin Active Edge Interrupt Flag
SCI1S2_LBKDIF:      .equ   7                                         ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI1S2_RAF:        .equ   %00000001
mSCI1S2_LBKDE:      .equ   %00000010
mSCI1S2_BRK13:      .equ   %00000100
mSCI1S2_RWUID:      .equ   %00001000
mSCI1S2_RXINV:      .equ   %00010000
mSCI1S2_RXEDGIF:    .equ   %01000000
mSCI1S2_LBKDIF:     .equ   %10000000


;*** SCI1C3 - SCI1 Control Register 3; 0xFFFF803E ***
SCI1C3:             .equ   $FFFF803E                                ;*** SCI1C3 - SCI1 Control Register 3; 0xFFFF803E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C3_PEIE:        .equ   0                                         ; Parity Error Interrupt Enable
SCI1C3_FEIE:        .equ   1                                         ; Framing Error Interrupt Enable
SCI1C3_NEIE:        .equ   2                                         ; Noise Error Interrupt Enable
SCI1C3_ORIE:        .equ   3                                         ; Overrun Interrupt Enable
SCI1C3_TXINV:       .equ   4                                         ; Transmit Data Inversion
SCI1C3_TXDIR:       .equ   5                                         ; TxD Pin Direction in Single-Wire Mode
SCI1C3_T8:          .equ   6                                         ; Ninth Data Bit for Transmitter
SCI1C3_R8:          .equ   7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI1C3_PEIE:       .equ   %00000001
mSCI1C3_FEIE:       .equ   %00000010
mSCI1C3_NEIE:       .equ   %00000100
mSCI1C3_ORIE:       .equ   %00001000
mSCI1C3_TXINV:      .equ   %00010000
mSCI1C3_TXDIR:      .equ   %00100000
mSCI1C3_T8:         .equ   %01000000
mSCI1C3_R8:         .equ   %10000000


;*** SCI1D - SCI1 Data Register; 0xFFFF803F ***
SCI1D:              .equ   $FFFF803F                                ;*** SCI1D - SCI1 Data Register; 0xFFFF803F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1D_R0_T0:        .equ   0                                         ; Receive/Transmit Data Bit 0
SCI1D_R1_T1:        .equ   1                                         ; Receive/Transmit Data Bit 1
SCI1D_R2_T2:        .equ   2                                         ; Receive/Transmit Data Bit 2
SCI1D_R3_T3:        .equ   3                                         ; Receive/Transmit Data Bit 3
SCI1D_R4_T4:        .equ   4                                         ; Receive/Transmit Data Bit 4
SCI1D_R5_T5:        .equ   5                                         ; Receive/Transmit Data Bit 5
SCI1D_R6_T6:        .equ   6                                         ; Receive/Transmit Data Bit 6
SCI1D_R7_T7:        .equ   7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI1D_R0_T0:       .equ   %00000001
mSCI1D_R1_T1:       .equ   %00000010
mSCI1D_R2_T2:       .equ   %00000100
mSCI1D_R3_T3:       .equ   %00001000
mSCI1D_R4_T4:       .equ   %00010000
mSCI1D_R5_T5:       .equ   %00100000
mSCI1D_R6_T6:       .equ   %01000000
mSCI1D_R7_T7:       .equ   %10000000


;*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF8040 ***
SCI2BD:             .equ   $FFFF8040                                ;*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF8040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BD_SBR0:        .equ   0                                         ; Baud Rate Modulo Divisor Bit 0
SCI2BD_SBR1:        .equ   1                                         ; Baud Rate Modulo Divisor Bit 1
SCI2BD_SBR2:        .equ   2                                         ; Baud Rate Modulo Divisor Bit 2
SCI2BD_SBR3:        .equ   3                                         ; Baud Rate Modulo Divisor Bit 3
SCI2BD_SBR4:        .equ   4                                         ; Baud Rate Modulo Divisor Bit 4
SCI2BD_SBR5:        .equ   5                                         ; Baud Rate Modulo Divisor Bit 5
SCI2BD_SBR6:        .equ   6                                         ; Baud Rate Modulo Divisor Bit 6
SCI2BD_SBR7:        .equ   7                                         ; Baud Rate Modulo Divisor Bit 7
SCI2BD_SBR8:        .equ   8                                         ; Baud Rate Modulo Divisor Bit 8
SCI2BD_SBR9:        .equ   9                                         ; Baud Rate Modulo Divisor Bit 9
SCI2BD_SBR10:       .equ   10                                        ; Baud Rate Modulo Divisor Bit 10
SCI2BD_SBR11:       .equ   11                                        ; Baud Rate Modulo Divisor Bit 11
SCI2BD_SBR12:       .equ   12                                        ; Baud Rate Modulo Divisor Bit 12
SCI2BD_RXEDGIE:     .equ   14                                        ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI2BD_LBKDIE:      .equ   15                                        ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI2BD_SBR0:       .equ   %00000001
mSCI2BD_SBR1:       .equ   %00000010
mSCI2BD_SBR2:       .equ   %00000100
mSCI2BD_SBR3:       .equ   %00001000
mSCI2BD_SBR4:       .equ   %00010000
mSCI2BD_SBR5:       .equ   %00100000
mSCI2BD_SBR6:       .equ   %01000000
mSCI2BD_SBR7:       .equ   %10000000
mSCI2BD_SBR8:       .equ   %100000000
mSCI2BD_SBR9:       .equ   %1000000000
mSCI2BD_SBR10:      .equ   %10000000000
mSCI2BD_SBR11:      .equ   %100000000000
mSCI2BD_SBR12:      .equ   %1000000000000
mSCI2BD_RXEDGIE:    .equ   %100000000000000
mSCI2BD_LBKDIE:     .equ   %1000000000000000


;*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF8040 ***
SCI2BDH:            .equ   $FFFF8040                                ;*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF8040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDH_SBR8:       .equ   0                                         ; Baud Rate Modulo Divisor Bit 8
SCI2BDH_SBR9:       .equ   1                                         ; Baud Rate Modulo Divisor Bit 9
SCI2BDH_SBR10:      .equ   2                                         ; Baud Rate Modulo Divisor Bit 10
SCI2BDH_SBR11:      .equ   3                                         ; Baud Rate Modulo Divisor Bit 11
SCI2BDH_SBR12:      .equ   4                                         ; Baud Rate Modulo Divisor Bit 12
SCI2BDH_RXEDGIE:    .equ   6                                         ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI2BDH_LBKDIE:     .equ   7                                         ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI2BDH_SBR8:      .equ   %00000001
mSCI2BDH_SBR9:      .equ   %00000010
mSCI2BDH_SBR10:     .equ   %00000100
mSCI2BDH_SBR11:     .equ   %00001000
mSCI2BDH_SBR12:     .equ   %00010000
mSCI2BDH_RXEDGIE:   .equ   %01000000
mSCI2BDH_LBKDIE:    .equ   %10000000


;*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF8041 ***
SCI2BDL:            .equ   $FFFF8041                                ;*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF8041 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDL_SBR0:       .equ   0                                         ; Baud Rate Modulo Divisor Bit 0
SCI2BDL_SBR1:       .equ   1                                         ; Baud Rate Modulo Divisor Bit 1
SCI2BDL_SBR2:       .equ   2                                         ; Baud Rate Modulo Divisor Bit 2
SCI2BDL_SBR3:       .equ   3                                         ; Baud Rate Modulo Divisor Bit 3
SCI2BDL_SBR4:       .equ   4                                         ; Baud Rate Modulo Divisor Bit 4
SCI2BDL_SBR5:       .equ   5                                         ; Baud Rate Modulo Divisor Bit 5
SCI2BDL_SBR6:       .equ   6                                         ; Baud Rate Modulo Divisor Bit 6
SCI2BDL_SBR7:       .equ   7                                         ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI2BDL_SBR0:      .equ   %00000001
mSCI2BDL_SBR1:      .equ   %00000010
mSCI2BDL_SBR2:      .equ   %00000100
mSCI2BDL_SBR3:      .equ   %00001000
mSCI2BDL_SBR4:      .equ   %00010000
mSCI2BDL_SBR5:      .equ   %00100000
mSCI2BDL_SBR6:      .equ   %01000000
mSCI2BDL_SBR7:      .equ   %10000000


;*** SCI2C1 - SCI2 Control Register 1; 0xFFFF8042 ***
SCI2C1:             .equ   $FFFF8042                                ;*** SCI2C1 - SCI2 Control Register 1; 0xFFFF8042 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C1_PT:          .equ   0                                         ; Parity Type
SCI2C1_PE:          .equ   1                                         ; Parity Enable
SCI2C1_ILT:         .equ   2                                         ; Idle Line Type Select
SCI2C1_WAKE:        .equ   3                                         ; Receiver Wakeup Method Select
SCI2C1_M:           .equ   4                                         ; 9-Bit or 8-Bit Mode Select
SCI2C1_RSRC:        .equ   5                                         ; Receiver Source Select
SCI2C1_SCISWAI:     .equ   6                                         ; SCI Stops in Wait Mode
SCI2C1_LOOPS:       .equ   7                                         ; Loop Mode Select
; bit position masks
mSCI2C1_PT:         .equ   %00000001
mSCI2C1_PE:         .equ   %00000010
mSCI2C1_ILT:        .equ   %00000100
mSCI2C1_WAKE:       .equ   %00001000
mSCI2C1_M:          .equ   %00010000
mSCI2C1_RSRC:       .equ   %00100000
mSCI2C1_SCISWAI:    .equ   %01000000
mSCI2C1_LOOPS:      .equ   %10000000


;*** SCI2C2 - SCI2 Control Register 2; 0xFFFF8043 ***
SCI2C2:             .equ   $FFFF8043                                ;*** SCI2C2 - SCI2 Control Register 2; 0xFFFF8043 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C2_SBK:         .equ   0                                         ; Send Break
SCI2C2_RWU:         .equ   1                                         ; Receiver Wakeup Control
SCI2C2_RE:          .equ   2                                         ; Receiver Enable
SCI2C2_TE:          .equ   3                                         ; Transmitter Enable
SCI2C2_ILIE:        .equ   4                                         ; Idle Line Interrupt Enable (for IDLE)
SCI2C2_RIE:         .equ   5                                         ; Receiver Interrupt Enable (for RDRF)
SCI2C2_TCIE:        .equ   6                                         ; Transmission Complete Interrupt Enable (for TC)
SCI2C2_TIE:         .equ   7                                         ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI2C2_SBK:        .equ   %00000001
mSCI2C2_RWU:        .equ   %00000010
mSCI2C2_RE:         .equ   %00000100
mSCI2C2_TE:         .equ   %00001000
mSCI2C2_ILIE:       .equ   %00010000
mSCI2C2_RIE:        .equ   %00100000
mSCI2C2_TCIE:       .equ   %01000000
mSCI2C2_TIE:        .equ   %10000000


;*** SCI2S1 - SCI2 Status Register 1; 0xFFFF8044 ***
SCI2S1:             .equ   $FFFF8044                                ;*** SCI2S1 - SCI2 Status Register 1; 0xFFFF8044 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S1_PF:          .equ   0                                         ; Parity Error Flag
SCI2S1_FE:          .equ   1                                         ; Framing Error Flag
SCI2S1_NF:          .equ   2                                         ; Noise Flag
SCI2S1_OR:          .equ   3                                         ; Receiver Overrun Flag
SCI2S1_IDLE:        .equ   4                                         ; Idle Line Flag
SCI2S1_RDRF:        .equ   5                                         ; Receive Data Register Full Flag
SCI2S1_TC:          .equ   6                                         ; Transmission Complete Flag
SCI2S1_TDRE:        .equ   7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI2S1_PF:         .equ   %00000001
mSCI2S1_FE:         .equ   %00000010
mSCI2S1_NF:         .equ   %00000100
mSCI2S1_OR:         .equ   %00001000
mSCI2S1_IDLE:       .equ   %00010000
mSCI2S1_RDRF:       .equ   %00100000
mSCI2S1_TC:         .equ   %01000000
mSCI2S1_TDRE:       .equ   %10000000


;*** SCI2S2 - SCI2 Status Register 2; 0xFFFF8045 ***
SCI2S2:             .equ   $FFFF8045                                ;*** SCI2S2 - SCI2 Status Register 2; 0xFFFF8045 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S2_RAF:         .equ   0                                         ; Receiver Active Flag
SCI2S2_LBKDE:       .equ   1                                         ; LIN Break Detection Enable
SCI2S2_BRK13:       .equ   2                                         ; Break Character Generation Length
SCI2S2_RWUID:       .equ   3                                         ; Receive Wake Up Idle Detect
SCI2S2_RXINV:       .equ   4                                         ; Receive Data Inversion
SCI2S2_RXEDGIF:     .equ   6                                         ; RxD Pin Active Edge Interrupt Flag
SCI2S2_LBKDIF:      .equ   7                                         ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI2S2_RAF:        .equ   %00000001
mSCI2S2_LBKDE:      .equ   %00000010
mSCI2S2_BRK13:      .equ   %00000100
mSCI2S2_RWUID:      .equ   %00001000
mSCI2S2_RXINV:      .equ   %00010000
mSCI2S2_RXEDGIF:    .equ   %01000000
mSCI2S2_LBKDIF:     .equ   %10000000


;*** SCI2C3 - SCI2 Control Register 3; 0xFFFF8046 ***
SCI2C3:             .equ   $FFFF8046                                ;*** SCI2C3 - SCI2 Control Register 3; 0xFFFF8046 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C3_PEIE:        .equ   0                                         ; Parity Error Interrupt Enable
SCI2C3_FEIE:        .equ   1                                         ; Framing Error Interrupt Enable
SCI2C3_NEIE:        .equ   2                                         ; Noise Error Interrupt Enable
SCI2C3_ORIE:        .equ   3                                         ; Overrun Interrupt Enable
SCI2C3_TXINV:       .equ   4                                         ; Transmit Data Inversion
SCI2C3_TXDIR:       .equ   5                                         ; TxD Pin Direction in Single-Wire Mode
SCI2C3_T8:          .equ   6                                         ; Ninth Data Bit for Transmitter
SCI2C3_R8:          .equ   7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI2C3_PEIE:       .equ   %00000001
mSCI2C3_FEIE:       .equ   %00000010
mSCI2C3_NEIE:       .equ   %00000100
mSCI2C3_ORIE:       .equ   %00001000
mSCI2C3_TXINV:      .equ   %00010000
mSCI2C3_TXDIR:      .equ   %00100000
mSCI2C3_T8:         .equ   %01000000
mSCI2C3_R8:         .equ   %10000000


;*** SCI2D - SCI2 Data Register; 0xFFFF8047 ***
SCI2D:              .equ   $FFFF8047                                ;*** SCI2D - SCI2 Data Register; 0xFFFF8047 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2D_R0_T0:        .equ   0                                         ; Receive/Transmit Data Bit 0
SCI2D_R1_T1:        .equ   1                                         ; Receive/Transmit Data Bit 1
SCI2D_R2_T2:        .equ   2                                         ; Receive/Transmit Data Bit 2
SCI2D_R3_T3:        .equ   3                                         ; Receive/Transmit Data Bit 3
SCI2D_R4_T4:        .equ   4                                         ; Receive/Transmit Data Bit 4
SCI2D_R5_T5:        .equ   5                                         ; Receive/Transmit Data Bit 5
SCI2D_R6_T6:        .equ   6                                         ; Receive/Transmit Data Bit 6
SCI2D_R7_T7:        .equ   7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI2D_R0_T0:       .equ   %00000001
mSCI2D_R1_T1:       .equ   %00000010
mSCI2D_R2_T2:       .equ   %00000100
mSCI2D_R3_T3:       .equ   %00001000
mSCI2D_R4_T4:       .equ   %00010000
mSCI2D_R5_T5:       .equ   %00100000
mSCI2D_R6_T6:       .equ   %01000000
mSCI2D_R7_T7:       .equ   %10000000


;*** MCGC1 - MCG Control Register 1; 0xFFFF8048 ***
MCGC1:              .equ   $FFFF8048                                ;*** MCGC1 - MCG Control Register 1; 0xFFFF8048 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC1_IREFSTEN:     .equ   0                                         ; Internal Reference Stop Enable
MCGC1_IRCLKEN:      .equ   1                                         ; Internal Reference Clock Enable
MCGC1_IREFS:        .equ   2                                         ; Internal Reference Select
MCGC1_RDIV0:        .equ   3                                         ; Reference Divider, bit 0
MCGC1_RDIV1:        .equ   4                                         ; Reference Divider, bit 1
MCGC1_RDIV2:        .equ   5                                         ; Reference Divider, bit 2
MCGC1_CLKS0:        .equ   6                                         ; Clock Source Select, bit 0
MCGC1_CLKS1:        .equ   7                                         ; Clock Source Select, bit 1
; bit position masks
mMCGC1_IREFSTEN:    .equ   %00000001
mMCGC1_IRCLKEN:     .equ   %00000010
mMCGC1_IREFS:       .equ   %00000100
mMCGC1_RDIV0:       .equ   %00001000
mMCGC1_RDIV1:       .equ   %00010000
mMCGC1_RDIV2:       .equ   %00100000
mMCGC1_CLKS0:       .equ   %01000000
mMCGC1_CLKS1:       .equ   %10000000


;*** MCGC2 - MCG Control Register 2; 0xFFFF8049 ***
MCGC2:              .equ   $FFFF8049                                ;*** MCGC2 - MCG Control Register 2; 0xFFFF8049 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC2_EREFSTEN:     .equ   0                                         ; External Reference Stop Enable
MCGC2_ERCLKEN:      .equ   1                                         ; External Reference Enable
MCGC2_EREFS:        .equ   2                                         ; External Reference Select
MCGC2_LP:           .equ   3                                         ; Low Power Select
MCGC2_HGO:          .equ   4                                         ; High Gain Oscillator Select
MCGC2_RANGE:        .equ   5                                         ; Frequency Range Select
MCGC2_BDIV0:        .equ   6                                         ; Bus Frequency Divider, bit 0
MCGC2_BDIV1:        .equ   7                                         ; Bus Frequency Divider, bit 1
; bit position masks
mMCGC2_EREFSTEN:    .equ   %00000001
mMCGC2_ERCLKEN:     .equ   %00000010
mMCGC2_EREFS:       .equ   %00000100
mMCGC2_LP:          .equ   %00001000
mMCGC2_HGO:         .equ   %00010000
mMCGC2_RANGE:       .equ   %00100000
mMCGC2_BDIV0:       .equ   %01000000
mMCGC2_BDIV1:       .equ   %10000000


;*** MCGTRM - MCG Trim Register; 0xFFFF804A ***
MCGTRM:             .equ   $FFFF804A                                ;*** MCGTRM - MCG Trim Register; 0xFFFF804A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGTRM_TRIM0:       .equ   0                                         ; MCG Trim Setting, bit 0
MCGTRM_TRIM1:       .equ   1                                         ; MCG Trim Setting, bit 1
MCGTRM_TRIM2:       .equ   2                                         ; MCG Trim Setting, bit 2
MCGTRM_TRIM3:       .equ   3                                         ; MCG Trim Setting, bit 3
MCGTRM_TRIM4:       .equ   4                                         ; MCG Trim Setting, bit 4
MCGTRM_TRIM5:       .equ   5                                         ; MCG Trim Setting, bit 5
MCGTRM_TRIM6:       .equ   6                                         ; MCG Trim Setting, bit 6
MCGTRM_TRIM7:       .equ   7                                         ; MCG Trim Setting, bit 7
; bit position masks
mMCGTRM_TRIM0:      .equ   %00000001
mMCGTRM_TRIM1:      .equ   %00000010
mMCGTRM_TRIM2:      .equ   %00000100
mMCGTRM_TRIM3:      .equ   %00001000
mMCGTRM_TRIM4:      .equ   %00010000
mMCGTRM_TRIM5:      .equ   %00100000
mMCGTRM_TRIM6:      .equ   %01000000
mMCGTRM_TRIM7:      .equ   %10000000


;*** MCGSC - MCG Status and Control Register; 0xFFFF804B ***
MCGSC:              .equ   $FFFF804B                                ;*** MCGSC - MCG Status and Control Register; 0xFFFF804B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGSC_FTRIM:        .equ   0                                         ; MCG Fine Trim
MCGSC_OSCINIT:      .equ   1                                         ; OSC Initialization
MCGSC_CLKST0:       .equ   2                                         ; Clock Mode Status, bit 0
MCGSC_CLKST1:       .equ   3                                         ; Clock Mode Status, bit 1
MCGSC_IREFST:       .equ   4                                         ; Internal Reference Status
MCGSC_PLLST:        .equ   5                                         ; PLL Select Status
MCGSC_LOCK:         .equ   6                                         ; Lock Status
MCGSC_LOLS:         .equ   7                                         ; Loss of Lock Status
; bit position masks
mMCGSC_FTRIM:       .equ   %00000001
mMCGSC_OSCINIT:     .equ   %00000010
mMCGSC_CLKST0:      .equ   %00000100
mMCGSC_CLKST1:      .equ   %00001000
mMCGSC_IREFST:      .equ   %00010000
mMCGSC_PLLST:       .equ   %00100000
mMCGSC_LOCK:        .equ   %01000000
mMCGSC_LOLS:        .equ   %10000000


;*** MCGC3 - MCG Control Register 3; 0xFFFF804C ***
MCGC3:              .equ   $FFFF804C                                ;*** MCGC3 - MCG Control Register 3; 0xFFFF804C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC3_VDIV0:        .equ   0                                         ; VCO Divider, bit 0
MCGC3_VDIV1:        .equ   1                                         ; VCO Divider, bit 1
MCGC3_VDIV2:        .equ   2                                         ; VCO Divider, bit 2
MCGC3_VDIV3:        .equ   3                                         ; VCO Divider, bit 3
MCGC3_DIV32:        .equ   4                                         ; Divide-by-32 Enable
MCGC3_CME:          .equ   5                                         ; Clock Monitor Enable
MCGC3_PLLS:         .equ   6                                         ; PLL Select
MCGC3_LOLIE:        .equ   7                                         ; Loss of Lock Interrupt Enable
; bit position masks
mMCGC3_VDIV0:       .equ   %00000001
mMCGC3_VDIV1:       .equ   %00000010
mMCGC3_VDIV2:       .equ   %00000100
mMCGC3_VDIV3:       .equ   %00001000
mMCGC3_DIV32:       .equ   %00010000
mMCGC3_CME:         .equ   %00100000
mMCGC3_PLLS:        .equ   %01000000
mMCGC3_LOLIE:       .equ   %10000000


;*** MCGC4 - MCG Control Register 4; 0xFFFF804D ***
MCGC4:              .equ   $FFFF804D                                ;*** MCGC4 - MCG Control Register 4; 0xFFFF804D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC4_DRST_DRS0:    .equ   0                                         ; DCO Range Status / DCO Range Select, bit 0
MCGC4_DRST_DRS1:    .equ   1                                         ; DCO Range Status / DCO Range Select, bit 1
MCGC4_DMX32:        .equ   5                                         ; DCO Maximum frequency with 32.768 kHz reference
; bit position masks
mMCGC4_DRST_DRS0:   .equ   %00000001
mMCGC4_DRST_DRS1:   .equ   %00000010
mMCGC4_DMX32:       .equ   %00100000


;*** SPI1C1 - SPI1 Control Register 1; 0xFFFF8050 ***
SPI1C1:             .equ   $FFFF8050                                ;*** SPI1C1 - SPI1 Control Register 1; 0xFFFF8050 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C1_LSBFE:       .equ   0                                         ; LSB First (Shifter Direction)
SPI1C1_SSOE:        .equ   1                                         ; Slave Select Output Enable
SPI1C1_CPHA:        .equ   2                                         ; Clock Phase
SPI1C1_CPOL:        .equ   3                                         ; Clock Polarity
SPI1C1_MSTR:        .equ   4                                         ; Master/Slave Mode Select
SPI1C1_SPTIE:       .equ   5                                         ; SPI Transmit Interrupt Enable
SPI1C1_SPE:         .equ   6                                         ; SPI System Enable
SPI1C1_SPIE:        .equ   7                                         ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI1C1_LSBFE:      .equ   %00000001
mSPI1C1_SSOE:       .equ   %00000010
mSPI1C1_CPHA:       .equ   %00000100
mSPI1C1_CPOL:       .equ   %00001000
mSPI1C1_MSTR:       .equ   %00010000
mSPI1C1_SPTIE:      .equ   %00100000
mSPI1C1_SPE:        .equ   %01000000
mSPI1C1_SPIE:       .equ   %10000000


;*** SPI1C2 - SPI1 Control Register 2; 0xFFFF8051 ***
SPI1C2:             .equ   $FFFF8051                                ;*** SPI1C2 - SPI1 Control Register 2; 0xFFFF8051 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0:        .equ   0                                         ; SPI Pin Control 0
SPI1C2_SPISWAI:     .equ   1                                         ; SPI Stop in Wait Mode
SPI1C2_BIDIROE:     .equ   3                                         ; Bidirectional Mode Output Enable
SPI1C2_MODFEN:      .equ   4                                         ; Master Mode-Fault Function Enable
SPI1C2_SPIMODE:     .equ   6                                         ; SPI 8- or 16-bit Mode Select
SPI1C2_SPMIE:       .equ   7                                         ; SPI Match Interrupt Enable
; bit position masks
mSPI1C2_SPC0:       .equ   %00000001
mSPI1C2_SPISWAI:    .equ   %00000010
mSPI1C2_BIDIROE:    .equ   %00001000
mSPI1C2_MODFEN:     .equ   %00010000
mSPI1C2_SPIMODE:    .equ   %01000000
mSPI1C2_SPMIE:      .equ   %10000000


;*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF8052 ***
SPI1BR:             .equ   $FFFF8052                                ;*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF8052 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0:        .equ   0                                         ; SPI Baud Rate Divisor Bit 0
SPI1BR_SPR1:        .equ   1                                         ; SPI Baud Rate Divisor Bit 1
SPI1BR_SPR2:        .equ   2                                         ; SPI Baud Rate Divisor Bit 2
SPI1BR_SPPR0:       .equ   4                                         ; SPI Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1:       .equ   5                                         ; SPI Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2:       .equ   6                                         ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0:       .equ   %00000001
mSPI1BR_SPR1:       .equ   %00000010
mSPI1BR_SPR2:       .equ   %00000100
mSPI1BR_SPPR0:      .equ   %00010000
mSPI1BR_SPPR1:      .equ   %00100000
mSPI1BR_SPPR2:      .equ   %01000000


;*** SPI1S - SPI1 Status Register; 0xFFFF8053 ***
SPI1S:              .equ   $FFFF8053                                ;*** SPI1S - SPI1 Status Register; 0xFFFF8053 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF:         .equ   4                                         ; Master Mode Fault Flag
SPI1S_SPTEF:        .equ   5                                         ; SPI Transmit Buffer Empty Flag
SPI1S_SPMF:         .equ   6                                         ; SPI Match Flag
SPI1S_SPRF:         .equ   7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPI1S_MODF:        .equ   %00010000
mSPI1S_SPTEF:       .equ   %00100000
mSPI1S_SPMF:        .equ   %01000000
mSPI1S_SPRF:        .equ   %10000000


;*** SPI1D16 - SPI1 Data Register; 0xFFFF8054 ***
SPI1D16:            .equ   $FFFF8054                                ;*** SPI1D16 - SPI1 Data Register; 0xFFFF8054 ***


;*** SPI1DH - SPI1 Data Register High; 0xFFFF8054 ***
SPI1DH:             .equ   $FFFF8054                                ;*** SPI1DH - SPI1 Data Register High; 0xFFFF8054 ***


;*** SPI1DL - SPI1 Data Register Low; 0xFFFF8055 ***
SPI1DL:             .equ   $FFFF8055                                ;*** SPI1DL - SPI1 Data Register Low; 0xFFFF8055 ***


;*** SPI1D - SPI1 Data Register Low; 0xFFFF8055 ***
SPI1D:              .equ   $FFFF8055                                ;*** SPI1D - SPI1 Data Register Low; 0xFFFF8055 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1D_Bit0:         .equ   0                                         ; SPI Data Bit 0
SPI1D_Bit1:         .equ   1                                         ; SPI Data Bit 1
SPI1D_Bit2:         .equ   2                                         ; SPI Data Bit 2
SPI1D_Bit3:         .equ   3                                         ; SPI Data Bit 3
SPI1D_Bit4:         .equ   4                                         ; SPI Data Bit 4
SPI1D_Bit5:         .equ   5                                         ; SPI Data Bit 5
SPI1D_Bit6:         .equ   6                                         ; SPI Data Bit 6
SPI1D_Bit7:         .equ   7                                         ; SPI Data Bit 7
; bit position masks
mSPI1D_Bit0:        .equ   %00000001
mSPI1D_Bit1:        .equ   %00000010
mSPI1D_Bit2:        .equ   %00000100
mSPI1D_Bit3:        .equ   %00001000
mSPI1D_Bit4:        .equ   %00010000
mSPI1D_Bit5:        .equ   %00100000
mSPI1D_Bit6:        .equ   %01000000
mSPI1D_Bit7:        .equ   %10000000


;*** SPI1M - SPI1 Match Register; 0xFFFF8056 ***
SPI1M:              .equ   $FFFF8056                                ;*** SPI1M - SPI1 Match Register; 0xFFFF8056 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1M_Bit0:         .equ   0                                         ; SPI Match Value Bit 0
SPI1M_Bit1:         .equ   1                                         ; SPI Match Value Bit 1
SPI1M_Bit2:         .equ   2                                         ; SPI Match Value Bit 2
SPI1M_Bit3:         .equ   3                                         ; SPI Match Value Bit 3
SPI1M_Bit4:         .equ   4                                         ; SPI Match Value Bit 4
SPI1M_Bit5:         .equ   5                                         ; SPI Match Value Bit 5
SPI1M_Bit6:         .equ   6                                         ; SPI Match Value Bit 6
SPI1M_Bit7:         .equ   7                                         ; SPI Match Value Bit 7
SPI1M_Bit8:         .equ   8                                         ; SPI Match Value Bit 8
SPI1M_Bit9:         .equ   9                                         ; SPI Match Value Bit 9
SPI1M_Bit10:        .equ   10                                        ; SPI Match Value Bit 10
SPI1M_Bit11:        .equ   11                                        ; SPI Match Value Bit 11
SPI1M_Bit12:        .equ   12                                        ; SPI Match Value Bit 12
SPI1M_Bit13:        .equ   13                                        ; SPI Match Value Bit 13
SPI1M_Bit14:        .equ   14                                        ; SPI Match Value Bit 14
SPI1M_Bit15:        .equ   15                                        ; SPI Match Value Bit 15
; bit position masks
mSPI1M_Bit0:        .equ   %00000001
mSPI1M_Bit1:        .equ   %00000010
mSPI1M_Bit2:        .equ   %00000100
mSPI1M_Bit3:        .equ   %00001000
mSPI1M_Bit4:        .equ   %00010000
mSPI1M_Bit5:        .equ   %00100000
mSPI1M_Bit6:        .equ   %01000000
mSPI1M_Bit7:        .equ   %10000000
mSPI1M_Bit8:        .equ   %100000000
mSPI1M_Bit9:        .equ   %1000000000
mSPI1M_Bit10:       .equ   %10000000000
mSPI1M_Bit11:       .equ   %100000000000
mSPI1M_Bit12:       .equ   %1000000000000
mSPI1M_Bit13:       .equ   %10000000000000
mSPI1M_Bit14:       .equ   %100000000000000
mSPI1M_Bit15:       .equ   %1000000000000000


;*** SPI1MH - SPI1 Match Register High; 0xFFFF8056 ***
SPI1MH:             .equ   $FFFF8056                                ;*** SPI1MH - SPI1 Match Register High; 0xFFFF8056 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1MH_Bit8:        .equ   0                                         ; SPI Match Value Bit 8
SPI1MH_Bit9:        .equ   1                                         ; SPI Match Value Bit 9
SPI1MH_Bit10:       .equ   2                                         ; SPI Match Value Bit 10
SPI1MH_Bit11:       .equ   3                                         ; SPI Match Value Bit 11
SPI1MH_Bit12:       .equ   4                                         ; SPI Match Value Bit 12
SPI1MH_Bit13:       .equ   5                                         ; SPI Match Value Bit 13
SPI1MH_Bit14:       .equ   6                                         ; SPI Match Value Bit 14
SPI1MH_Bit15:       .equ   7                                         ; SPI Match Value Bit 15
; bit position masks
mSPI1MH_Bit8:       .equ   %00000001
mSPI1MH_Bit9:       .equ   %00000010
mSPI1MH_Bit10:      .equ   %00000100
mSPI1MH_Bit11:      .equ   %00001000
mSPI1MH_Bit12:      .equ   %00010000
mSPI1MH_Bit13:      .equ   %00100000
mSPI1MH_Bit14:      .equ   %01000000
mSPI1MH_Bit15:      .equ   %10000000


;*** SPI1ML - SPI1 Match Register Low; 0xFFFF8057 ***
SPI1ML:             .equ   $FFFF8057                                ;*** SPI1ML - SPI1 Match Register Low; 0xFFFF8057 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1ML_Bit0:        .equ   0                                         ; SPI Match Value Bit 0
SPI1ML_Bit1:        .equ   1                                         ; SPI Match Value Bit 1
SPI1ML_Bit2:        .equ   2                                         ; SPI Match Value Bit 2
SPI1ML_Bit3:        .equ   3                                         ; SPI Match Value Bit 3
SPI1ML_Bit4:        .equ   4                                         ; SPI Match Value Bit 4
SPI1ML_Bit5:        .equ   5                                         ; SPI Match Value Bit 5
SPI1ML_Bit6:        .equ   6                                         ; SPI Match Value Bit 6
SPI1ML_Bit7:        .equ   7                                         ; SPI Match Value Bit 7
; bit position masks
mSPI1ML_Bit0:       .equ   %00000001
mSPI1ML_Bit1:       .equ   %00000010
mSPI1ML_Bit2:       .equ   %00000100
mSPI1ML_Bit3:       .equ   %00001000
mSPI1ML_Bit4:       .equ   %00010000
mSPI1ML_Bit5:       .equ   %00100000
mSPI1ML_Bit6:       .equ   %01000000
mSPI1ML_Bit7:       .equ   %10000000


;*** IIC1A - IIC Address Register; 0xFFFF8058 ***
IIC1A:              .equ   $FFFF8058                                ;*** IIC1A - IIC Address Register; 0xFFFF8058 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1A_AD1:          .equ   1                                         ; Slave Address Bit 1
IIC1A_AD2:          .equ   2                                         ; Slave Address Bit 2
IIC1A_AD3:          .equ   3                                         ; Slave Address Bit 3
IIC1A_AD4:          .equ   4                                         ; Slave Address Bit 4
IIC1A_AD5:          .equ   5                                         ; Slave Address Bit 5
IIC1A_AD6:          .equ   6                                         ; Slave Address Bit 6
IIC1A_AD7:          .equ   7                                         ; Slave Address Bit 7
; bit position masks
mIIC1A_AD1:         .equ   %00000010
mIIC1A_AD2:         .equ   %00000100
mIIC1A_AD3:         .equ   %00001000
mIIC1A_AD4:         .equ   %00010000
mIIC1A_AD5:         .equ   %00100000
mIIC1A_AD6:         .equ   %01000000
mIIC1A_AD7:         .equ   %10000000


;*** IIC1F - IIC Frequency Divider Register; 0xFFFF8059 ***
IIC1F:              .equ   $FFFF8059                                ;*** IIC1F - IIC Frequency Divider Register; 0xFFFF8059 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1F_ICR0:         .equ   0                                         ; IIC Clock Rate Bit 0
IIC1F_ICR1:         .equ   1                                         ; IIC Clock Rate Bit 1
IIC1F_ICR2:         .equ   2                                         ; IIC Clock Rate Bit 2
IIC1F_ICR3:         .equ   3                                         ; IIC Clock Rate Bit 3
IIC1F_ICR4:         .equ   4                                         ; IIC Clock Rate Bit 4
IIC1F_ICR5:         .equ   5                                         ; IIC Clock Rate Bit 5
IIC1F_MULT0:        .equ   6                                         ; Multiplier Factor Bit 0
IIC1F_MULT1:        .equ   7                                         ; Multiplier Factor Bit 1
; bit position masks
mIIC1F_ICR0:        .equ   %00000001
mIIC1F_ICR1:        .equ   %00000010
mIIC1F_ICR2:        .equ   %00000100
mIIC1F_ICR3:        .equ   %00001000
mIIC1F_ICR4:        .equ   %00010000
mIIC1F_ICR5:        .equ   %00100000
mIIC1F_MULT0:       .equ   %01000000
mIIC1F_MULT1:       .equ   %10000000


;*** IIC1C1 - IIC Control Register 1; 0xFFFF805A ***
IIC1C1:             .equ   $FFFF805A                                ;*** IIC1C1 - IIC Control Register 1; 0xFFFF805A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1C1_RSTA:        .equ   2                                         ; Repeat START
IIC1C1_TXAK:        .equ   3                                         ; Transmit Acknowledge Enable
IIC1C1_TX:          .equ   4                                         ; Transmit Mode Select
IIC1C1_MST:         .equ   5                                         ; Master Mode Select
IIC1C1_IICIE:       .equ   6                                         ; IIC Interrupt Enable
IIC1C1_IICEN:       .equ   7                                         ; IIC Enable
; bit position masks
mIIC1C1_RSTA:       .equ   %00000100
mIIC1C1_TXAK:       .equ   %00001000
mIIC1C1_TX:         .equ   %00010000
mIIC1C1_MST:        .equ   %00100000
mIIC1C1_IICIE:      .equ   %01000000
mIIC1C1_IICEN:      .equ   %10000000


;*** IIC1C - IIC Control Register; 0xFFFF805A ***
IIC1C:              .equ   $FFFF805A                                ;*** IIC1C - IIC Control Register; 0xFFFF805A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1C_RSTA:         .equ   2                                         ; Repeat START
IIC1C_TXAK:         .equ   3                                         ; Transmit Acknowledge Enable
IIC1C_TX:           .equ   4                                         ; Transmit Mode Select
IIC1C_MST:          .equ   5                                         ; Master Mode Select
IIC1C_IICIE:        .equ   6                                         ; IIC Interrupt Enable
IIC1C_IICEN:        .equ   7                                         ; IIC Enable
; bit position masks
mIIC1C_RSTA:        .equ   %00000100
mIIC1C_TXAK:        .equ   %00001000
mIIC1C_TX:          .equ   %00010000
mIIC1C_MST:         .equ   %00100000
mIIC1C_IICIE:       .equ   %01000000
mIIC1C_IICEN:       .equ   %10000000


;*** IIC1S - IIC Status Register; 0xFFFF805B ***
IIC1S:              .equ   $FFFF805B                                ;*** IIC1S - IIC Status Register; 0xFFFF805B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1S_RXAK:         .equ   0                                         ; Receive Acknowledge
IIC1S_IICIF:        .equ   1                                         ; IIC Interrupt Flag
IIC1S_SRW:          .equ   2                                         ; Slave Read/Write
IIC1S_ARBL:         .equ   4                                         ; Arbitration Lost
IIC1S_BUSY:         .equ   5                                         ; Bus Busy
IIC1S_IAAS:         .equ   6                                         ; Addressed as a Slave
IIC1S_TCF:          .equ   7                                         ; Transfer Complete Flag
; bit position masks
mIIC1S_RXAK:        .equ   %00000001
mIIC1S_IICIF:       .equ   %00000010
mIIC1S_SRW:         .equ   %00000100
mIIC1S_ARBL:        .equ   %00010000
mIIC1S_BUSY:        .equ   %00100000
mIIC1S_IAAS:        .equ   %01000000
mIIC1S_TCF:         .equ   %10000000


;*** IIC1D - IIC Data I/O Register; 0xFFFF805C ***
IIC1D:              .equ   $FFFF805C                                ;*** IIC1D - IIC Data I/O Register; 0xFFFF805C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1D_DATA0:        .equ   0                                         ; IIC Data Bit 0
IIC1D_DATA1:        .equ   1                                         ; IIC Data Bit 1
IIC1D_DATA2:        .equ   2                                         ; IIC Data Bit 2
IIC1D_DATA3:        .equ   3                                         ; IIC Data Bit 3
IIC1D_DATA4:        .equ   4                                         ; IIC Data Bit 4
IIC1D_DATA5:        .equ   5                                         ; IIC Data Bit 5
IIC1D_DATA6:        .equ   6                                         ; IIC Data Bit 6
IIC1D_DATA7:        .equ   7                                         ; IIC Data Bit 7
; bit position masks
mIIC1D_DATA0:       .equ   %00000001
mIIC1D_DATA1:       .equ   %00000010
mIIC1D_DATA2:       .equ   %00000100
mIIC1D_DATA3:       .equ   %00001000
mIIC1D_DATA4:       .equ   %00010000
mIIC1D_DATA5:       .equ   %00100000
mIIC1D_DATA6:       .equ   %01000000
mIIC1D_DATA7:       .equ   %10000000


;*** IIC1C2 - IIC Control Register 2; 0xFFFF805D ***
IIC1C2:             .equ   $FFFF805D                                ;*** IIC1C2 - IIC Control Register 2; 0xFFFF805D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1C2_AD8:         .equ   0                                         ; Slave Address Bit 8
IIC1C2_AD9:         .equ   1                                         ; Slave Address Bit 9
IIC1C2_AD10:        .equ   2                                         ; Slave Address Bit 10
IIC1C2_ADEXT:       .equ   6                                         ; Address Extension
IIC1C2_GCAEN:       .equ   7                                         ; General Call Address Enable
; bit position masks
mIIC1C2_AD8:        .equ   %00000001
mIIC1C2_AD9:        .equ   %00000010
mIIC1C2_AD10:       .equ   %00000100
mIIC1C2_ADEXT:      .equ   %01000000
mIIC1C2_GCAEN:      .equ   %10000000


;*** TPM2SC - TPM2 Status and Control Register; 0xFFFF8060 ***
TPM2SC:             .equ   $FFFF8060                                ;*** TPM2SC - TPM2 Status and Control Register; 0xFFFF8060 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2SC_PS0:         .equ   0                                         ; Prescale Divisor Select Bit 0
TPM2SC_PS1:         .equ   1                                         ; Prescale Divisor Select Bit 1
TPM2SC_PS2:         .equ   2                                         ; Prescale Divisor Select Bit 2
TPM2SC_CLKSA:       .equ   3                                         ; Clock Source Select A
TPM2SC_CLKSB:       .equ   4                                         ; Clock Source Select B
TPM2SC_CPWMS:       .equ   5                                         ; Center-Aligned PWM Select
TPM2SC_TOIE:        .equ   6                                         ; Timer Overflow Interrupt Enable
TPM2SC_TOF:         .equ   7                                         ; Timer Overflow Flag
; bit position masks
mTPM2SC_PS0:        .equ   %00000001
mTPM2SC_PS1:        .equ   %00000010
mTPM2SC_PS2:        .equ   %00000100
mTPM2SC_CLKSA:      .equ   %00001000
mTPM2SC_CLKSB:      .equ   %00010000
mTPM2SC_CPWMS:      .equ   %00100000
mTPM2SC_TOIE:       .equ   %01000000
mTPM2SC_TOF:        .equ   %10000000


;*** TPM2CNT - TPM2 Timer Counter Register; 0xFFFF8061 ***
TPM2CNT:            .equ   $FFFF8061                                ;*** TPM2CNT - TPM2 Timer Counter Register; 0xFFFF8061 ***


;*** TPM2CNTH - TPM2 Timer Counter Register High; 0xFFFF8061 ***
TPM2CNTH:           .equ   $FFFF8061                                ;*** TPM2CNTH - TPM2 Timer Counter Register High; 0xFFFF8061 ***


;*** TPM2CNTL - TPM2 Timer Counter Register Low; 0xFFFF8062 ***
TPM2CNTL:           .equ   $FFFF8062                                ;*** TPM2CNTL - TPM2 Timer Counter Register Low; 0xFFFF8062 ***


;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0xFFFF8063 ***
TPM2MOD:            .equ   $FFFF8063                                ;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0xFFFF8063 ***


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0xFFFF8063 ***
TPM2MODH:           .equ   $FFFF8063                                ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0xFFFF8063 ***


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0xFFFF8064 ***
TPM2MODL:           .equ   $FFFF8064                                ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0xFFFF8064 ***


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0xFFFF8065 ***
TPM2C0SC:           .equ   $FFFF8065                                ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0xFFFF8065 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C0SC_ELS0A:     .equ   2                                         ; Edge/Level Select Bit A
TPM2C0SC_ELS0B:     .equ   3                                         ; Edge/Level Select Bit B
TPM2C0SC_MS0A:      .equ   4                                         ; Mode Select A for TPM Channel 0
TPM2C0SC_MS0B:      .equ   5                                         ; Mode Select B for TPM Channel 0
TPM2C0SC_CH0IE:     .equ   6                                         ; Channel 0 Interrupt Enable
TPM2C0SC_CH0F:      .equ   7                                         ; Channel 0 Flag
; bit position masks
mTPM2C0SC_ELS0A:    .equ   %00000100
mTPM2C0SC_ELS0B:    .equ   %00001000
mTPM2C0SC_MS0A:     .equ   %00010000
mTPM2C0SC_MS0B:     .equ   %00100000
mTPM2C0SC_CH0IE:    .equ   %01000000
mTPM2C0SC_CH0F:     .equ   %10000000


;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0xFFFF8066 ***
TPM2C0V:            .equ   $FFFF8066                                ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0xFFFF8066 ***


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0xFFFF8066 ***
TPM2C0VH:           .equ   $FFFF8066                                ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0xFFFF8066 ***


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0xFFFF8067 ***
TPM2C0VL:           .equ   $FFFF8067                                ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0xFFFF8067 ***


;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0xFFFF8068 ***
TPM2C1SC:           .equ   $FFFF8068                                ;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0xFFFF8068 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C1SC_ELS1A:     .equ   2                                         ; Edge/Level Select Bit A
TPM2C1SC_ELS1B:     .equ   3                                         ; Edge/Level Select Bit B
TPM2C1SC_MS1A:      .equ   4                                         ; Mode Select A for TPM Channel 1
TPM2C1SC_MS1B:      .equ   5                                         ; Mode Select B for TPM Channel 1
TPM2C1SC_CH1IE:     .equ   6                                         ; Channel 1 Interrupt Enable
TPM2C1SC_CH1F:      .equ   7                                         ; Channel 1 Flag
; bit position masks
mTPM2C1SC_ELS1A:    .equ   %00000100
mTPM2C1SC_ELS1B:    .equ   %00001000
mTPM2C1SC_MS1A:     .equ   %00010000
mTPM2C1SC_MS1B:     .equ   %00100000
mTPM2C1SC_CH1IE:    .equ   %01000000
mTPM2C1SC_CH1F:     .equ   %10000000


;*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0xFFFF8069 ***
TPM2C1V:            .equ   $FFFF8069                                ;*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0xFFFF8069 ***


;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0xFFFF8069 ***
TPM2C1VH:           .equ   $FFFF8069                                ;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0xFFFF8069 ***


;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0xFFFF806A ***
TPM2C1VL:           .equ   $FFFF806A                                ;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0xFFFF806A ***


;*** RTCSC - RTC Status and Control Register; 0xFFFF806C ***
RTCSC:              .equ   $FFFF806C                                ;*** RTCSC - RTC Status and Control Register; 0xFFFF806C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCSC_RTCPS0:       .equ   0                                         ; Real-Time Clock Prescaler Select, bit 0
RTCSC_RTCPS1:       .equ   1                                         ; Real-Time Clock Prescaler Select, bit 1
RTCSC_RTCPS2:       .equ   2                                         ; Real-Time Clock Prescaler Select, bit 2
RTCSC_RTCPS3:       .equ   3                                         ; Real-Time Clock Prescaler Select, bit 3
RTCSC_RTIE:         .equ   4                                         ; Real-Time Interrupt Enable
RTCSC_RTCLKS0:      .equ   5                                         ; Real-Time Clock Source Select, bit 0
RTCSC_RTCLKS1:      .equ   6                                         ; Real-Time Clock Source Select, bit 1
RTCSC_RTIF:         .equ   7                                         ; Real-Time Interrupt Flag
; bit position masks
mRTCSC_RTCPS0:      .equ   %00000001
mRTCSC_RTCPS1:      .equ   %00000010
mRTCSC_RTCPS2:      .equ   %00000100
mRTCSC_RTCPS3:      .equ   %00001000
mRTCSC_RTIE:        .equ   %00010000
mRTCSC_RTCLKS0:     .equ   %00100000
mRTCSC_RTCLKS1:     .equ   %01000000
mRTCSC_RTIF:        .equ   %10000000


;*** RTCCNT - RTC Counter Register; 0xFFFF806D ***
RTCCNT:             .equ   $FFFF806D                                ;*** RTCCNT - RTC Counter Register; 0xFFFF806D ***


;*** RTCMOD - RTC Modulo Register; 0xFFFF806E ***
RTCMOD:             .equ   $FFFF806E                                ;*** RTCMOD - RTC Modulo Register; 0xFFFF806E ***


;*** SPI2C1 - SPI2 Control Register 1; 0xFFFF8070 ***
SPI2C1:             .equ   $FFFF8070                                ;*** SPI2C1 - SPI2 Control Register 1; 0xFFFF8070 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C1_LSBFE:       .equ   0                                         ; LSB First (Shifter Direction)
SPI2C1_SSOE:        .equ   1                                         ; Slave Select Output Enable
SPI2C1_CPHA:        .equ   2                                         ; Clock Phase
SPI2C1_CPOL:        .equ   3                                         ; Clock Polarity
SPI2C1_MSTR:        .equ   4                                         ; Master/Slave Mode Select
SPI2C1_SPTIE:       .equ   5                                         ; SPI Transmit Interrupt Enable
SPI2C1_SPE:         .equ   6                                         ; SPI System Enable
SPI2C1_SPIE:        .equ   7                                         ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI2C1_LSBFE:      .equ   %00000001
mSPI2C1_SSOE:       .equ   %00000010
mSPI2C1_CPHA:       .equ   %00000100
mSPI2C1_CPOL:       .equ   %00001000
mSPI2C1_MSTR:       .equ   %00010000
mSPI2C1_SPTIE:      .equ   %00100000
mSPI2C1_SPE:        .equ   %01000000
mSPI2C1_SPIE:       .equ   %10000000


;*** SPI2C2 - SPI2 Control Register 2; 0xFFFF8071 ***
SPI2C2:             .equ   $FFFF8071                                ;*** SPI2C2 - SPI2 Control Register 2; 0xFFFF8071 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C2_SPC0:        .equ   0                                         ; SPI Pin Control 0
SPI2C2_SPISWAI:     .equ   1                                         ; SPI Stop in Wait Mode
SPI2C2_BIDIROE:     .equ   3                                         ; Bidirectional Mode Output Enable
SPI2C2_MODFEN:      .equ   4                                         ; Master Mode-Fault Function Enable
SPI2C2_SPIMODE:     .equ   6                                         ; SPI 8- or 16-bit Mode Select
SPI2C2_SPMIE:       .equ   7                                         ; SPI Match Interrupt Enable
; bit position masks
mSPI2C2_SPC0:       .equ   %00000001
mSPI2C2_SPISWAI:    .equ   %00000010
mSPI2C2_BIDIROE:    .equ   %00001000
mSPI2C2_MODFEN:     .equ   %00010000
mSPI2C2_SPIMODE:    .equ   %01000000
mSPI2C2_SPMIE:      .equ   %10000000


;*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF8072 ***
SPI2BR:             .equ   $FFFF8072                                ;*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF8072 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2BR_SPR0:        .equ   0                                         ; SPI Baud Rate Divisor Bit 0
SPI2BR_SPR1:        .equ   1                                         ; SPI Baud Rate Divisor Bit 1
SPI2BR_SPR2:        .equ   2                                         ; SPI Baud Rate Divisor Bit 2
SPI2BR_SPPR0:       .equ   4                                         ; SPI Baud Rate Prescale Divisor Bit 0
SPI2BR_SPPR1:       .equ   5                                         ; SPI Baud Rate Prescale Divisor Bit 1
SPI2BR_SPPR2:       .equ   6                                         ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI2BR_SPR0:       .equ   %00000001
mSPI2BR_SPR1:       .equ   %00000010
mSPI2BR_SPR2:       .equ   %00000100
mSPI2BR_SPPR0:      .equ   %00010000
mSPI2BR_SPPR1:      .equ   %00100000
mSPI2BR_SPPR2:      .equ   %01000000


;*** SPI2S - SPI2 Status Register; 0xFFFF8073 ***
SPI2S:              .equ   $FFFF8073                                ;*** SPI2S - SPI2 Status Register; 0xFFFF8073 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2S_RFIFOEF:      .equ   0                                         ; SPI Read FIFO Empty Flag
SPI2S_TXFULLF:      .equ   1                                         ; SPI Transmit FIFO Full Flag
SPI2S_TNEAREF:      .equ   2                                         ; SPI Transmit FIFO Nearly Empty Flag
SPI2S_RNFULLF:      .equ   3                                         ; SPI Receive FIFO Nearly Full Flag
SPI2S_MODF:         .equ   4                                         ; Master Mode Fault Flag
SPI2S_SPTEF:        .equ   5                                         ; SPI Transmit Buffer Empty Flag
SPI2S_SPMF:         .equ   6                                         ; SPI Match Flag
SPI2S_SPRF:         .equ   7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPI2S_RFIFOEF:     .equ   %00000001
mSPI2S_TXFULLF:     .equ   %00000010
mSPI2S_TNEAREF:     .equ   %00000100
mSPI2S_RNFULLF:     .equ   %00001000
mSPI2S_MODF:        .equ   %00010000
mSPI2S_SPTEF:       .equ   %00100000
mSPI2S_SPMF:        .equ   %01000000
mSPI2S_SPRF:        .equ   %10000000


;*** SPI2D16 - SPI2 Data Register; 0xFFFF8074 ***
SPI2D16:            .equ   $FFFF8074                                ;*** SPI2D16 - SPI2 Data Register; 0xFFFF8074 ***


;*** SPI2DH - SPI2 Data Register High; 0xFFFF8074 ***
SPI2DH:             .equ   $FFFF8074                                ;*** SPI2DH - SPI2 Data Register High; 0xFFFF8074 ***


;*** SPI2DL - SPI2 Data Register Low; 0xFFFF8075 ***
SPI2DL:             .equ   $FFFF8075                                ;*** SPI2DL - SPI2 Data Register Low; 0xFFFF8075 ***


;*** SPI2D - SPI2 Data Register Low; 0xFFFF8075 ***
SPI2D:              .equ   $FFFF8075                                ;*** SPI2D - SPI2 Data Register Low; 0xFFFF8075 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2D_Bit0:         .equ   0                                         ; SPI Data Bit 0
SPI2D_Bit1:         .equ   1                                         ; SPI Data Bit 1
SPI2D_Bit2:         .equ   2                                         ; SPI Data Bit 2
SPI2D_Bit3:         .equ   3                                         ; SPI Data Bit 3
SPI2D_Bit4:         .equ   4                                         ; SPI Data Bit 4
SPI2D_Bit5:         .equ   5                                         ; SPI Data Bit 5
SPI2D_Bit6:         .equ   6                                         ; SPI Data Bit 6
SPI2D_Bit7:         .equ   7                                         ; SPI Data Bit 7
; bit position masks
mSPI2D_Bit0:        .equ   %00000001
mSPI2D_Bit1:        .equ   %00000010
mSPI2D_Bit2:        .equ   %00000100
mSPI2D_Bit3:        .equ   %00001000
mSPI2D_Bit4:        .equ   %00010000
mSPI2D_Bit5:        .equ   %00100000
mSPI2D_Bit6:        .equ   %01000000
mSPI2D_Bit7:        .equ   %10000000


;*** SPI2M - SPI2 Match Register; 0xFFFF8076 ***
SPI2M:              .equ   $FFFF8076                                ;*** SPI2M - SPI2 Match Register; 0xFFFF8076 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2M_Bit0:         .equ   0                                         ; SPI Match Value Bit 0
SPI2M_Bit1:         .equ   1                                         ; SPI Match Value Bit 1
SPI2M_Bit2:         .equ   2                                         ; SPI Match Value Bit 2
SPI2M_Bit3:         .equ   3                                         ; SPI Match Value Bit 3
SPI2M_Bit4:         .equ   4                                         ; SPI Match Value Bit 4
SPI2M_Bit5:         .equ   5                                         ; SPI Match Value Bit 5
SPI2M_Bit6:         .equ   6                                         ; SPI Match Value Bit 6
SPI2M_Bit7:         .equ   7                                         ; SPI Match Value Bit 7
SPI2M_Bit8:         .equ   8                                         ; SPI Match Value Bit 8
SPI2M_Bit9:         .equ   9                                         ; SPI Match Value Bit 9
SPI2M_Bit10:        .equ   10                                        ; SPI Match Value Bit 10
SPI2M_Bit11:        .equ   11                                        ; SPI Match Value Bit 11
SPI2M_Bit12:        .equ   12                                        ; SPI Match Value Bit 12
SPI2M_Bit13:        .equ   13                                        ; SPI Match Value Bit 13
SPI2M_Bit14:        .equ   14                                        ; SPI Match Value Bit 14
SPI2M_Bit15:        .equ   15                                        ; SPI Match Value Bit 15
; bit position masks
mSPI2M_Bit0:        .equ   %00000001
mSPI2M_Bit1:        .equ   %00000010
mSPI2M_Bit2:        .equ   %00000100
mSPI2M_Bit3:        .equ   %00001000
mSPI2M_Bit4:        .equ   %00010000
mSPI2M_Bit5:        .equ   %00100000
mSPI2M_Bit6:        .equ   %01000000
mSPI2M_Bit7:        .equ   %10000000
mSPI2M_Bit8:        .equ   %100000000
mSPI2M_Bit9:        .equ   %1000000000
mSPI2M_Bit10:       .equ   %10000000000
mSPI2M_Bit11:       .equ   %100000000000
mSPI2M_Bit12:       .equ   %1000000000000
mSPI2M_Bit13:       .equ   %10000000000000
mSPI2M_Bit14:       .equ   %100000000000000
mSPI2M_Bit15:       .equ   %1000000000000000


;*** SPI2MH - SPI2 Match Register High; 0xFFFF8076 ***
SPI2MH:             .equ   $FFFF8076                                ;*** SPI2MH - SPI2 Match Register High; 0xFFFF8076 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2MH_Bit8:        .equ   0                                         ; SPI Match Value Bit 8
SPI2MH_Bit9:        .equ   1                                         ; SPI Match Value Bit 9
SPI2MH_Bit10:       .equ   2                                         ; SPI Match Value Bit 10
SPI2MH_Bit11:       .equ   3                                         ; SPI Match Value Bit 11
SPI2MH_Bit12:       .equ   4                                         ; SPI Match Value Bit 12
SPI2MH_Bit13:       .equ   5                                         ; SPI Match Value Bit 13
SPI2MH_Bit14:       .equ   6                                         ; SPI Match Value Bit 14
SPI2MH_Bit15:       .equ   7                                         ; SPI Match Value Bit 15
; bit position masks
mSPI2MH_Bit8:       .equ   %00000001
mSPI2MH_Bit9:       .equ   %00000010
mSPI2MH_Bit10:      .equ   %00000100
mSPI2MH_Bit11:      .equ   %00001000
mSPI2MH_Bit12:      .equ   %00010000
mSPI2MH_Bit13:      .equ   %00100000
mSPI2MH_Bit14:      .equ   %01000000
mSPI2MH_Bit15:      .equ   %10000000


;*** SPI2ML - SPI2 Match Register Low; 0xFFFF8077 ***
SPI2ML:             .equ   $FFFF8077                                ;*** SPI2ML - SPI2 Match Register Low; 0xFFFF8077 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2ML_Bit0:        .equ   0                                         ; SPI Match Value Bit 0
SPI2ML_Bit1:        .equ   1                                         ; SPI Match Value Bit 1
SPI2ML_Bit2:        .equ   2                                         ; SPI Match Value Bit 2
SPI2ML_Bit3:        .equ   3                                         ; SPI Match Value Bit 3
SPI2ML_Bit4:        .equ   4                                         ; SPI Match Value Bit 4
SPI2ML_Bit5:        .equ   5                                         ; SPI Match Value Bit 5
SPI2ML_Bit6:        .equ   6                                         ; SPI Match Value Bit 6
SPI2ML_Bit7:        .equ   7                                         ; SPI Match Value Bit 7
; bit position masks
mSPI2ML_Bit0:       .equ   %00000001
mSPI2ML_Bit1:       .equ   %00000010
mSPI2ML_Bit2:       .equ   %00000100
mSPI2ML_Bit3:       .equ   %00001000
mSPI2ML_Bit4:       .equ   %00010000
mSPI2ML_Bit5:       .equ   %00100000
mSPI2ML_Bit6:       .equ   %01000000
mSPI2ML_Bit7:       .equ   %10000000


;*** SPI2C3 - SPI2 Control Register 3; 0xFFFF8078 ***
SPI2C3:             .equ   $FFFF8078                                ;*** SPI2C3 - SPI2 Control Register 3; 0xFFFF8078 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C3_FIFOMODE:    .equ   0                                         ; SPI FIFO Mode Enable
SPI2C3_RNFULLIEN:   .equ   1                                         ; Receive FIFO Nearly Full Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPIE in the SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0
SPI2C3_TNEARIEN:    .equ   2                                         ; Transmit FIFO Nearly Empty Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPTIE in the <br/>SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0
SPI2C3_RNFULLF_MARK: .equ   4                                        ; Receive FIFO Nearly Full Water Mark - This bit selects the mark for which RNFULLF flag is asserted
SPI2C3_TNEAREF_MARK: .equ   5                                        ; Transmit FIFO Nearly Empty Water Mark - This bit selects the mark after which TNEAREF flag is asserted
; bit position masks
mSPI2C3_FIFOMODE:   .equ   %00000001
mSPI2C3_RNFULLIEN:  .equ   %00000010
mSPI2C3_TNEARIEN:   .equ   %00000100
mSPI2C3_RNFULLF_MARK: .equ   %00010000
mSPI2C3_TNEAREF_MARK: .equ   %00100000


;*** SRS - System Reset Status Register; 0xFFFF9800 ***
SRS:                .equ   $FFFF9800                                ;*** SRS - System Reset Status Register; 0xFFFF9800 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD:            .equ   1                                         ; Low Voltage Detect
SRS_LOC:            .equ   2                                         ; Loss-of-Clock Reset
SRS_ILAD:           .equ   3                                         ; Illegal Address
SRS_ILOP:           .equ   4                                         ; Illegal Opcode
SRS_COP:            .equ   5                                         ; Computer Operating Properly (COP) Watchdog
SRS_PIN:            .equ   6                                         ; External Reset Pin
SRS_POR:            .equ   7                                         ; Power-On Reset
; bit position masks
mSRS_LVD:           .equ   %00000010
mSRS_LOC:           .equ   %00000100
mSRS_ILAD:          .equ   %00001000
mSRS_ILOP:          .equ   %00010000
mSRS_COP:           .equ   %00100000
mSRS_PIN:           .equ   %01000000
mSRS_POR:           .equ   %10000000


;*** SOPT1 - System Options Register 1; 0xFFFF9802 ***
SOPT1:              .equ   $FFFF9802                                ;*** SOPT1 - System Options Register 1; 0xFFFF9802 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_WAITE:        .equ   4                                         ; WAIT Mode Enable
SOPT1_STOPE:        .equ   5                                         ; Stop Mode Enable
SOPT1_COPT0:        .equ   6                                         ; COP Watchdog Timeout, bit 0
SOPT1_COPT1:        .equ   7                                         ; COP Watchdog Timeout, bit 1
; bit position masks
mSOPT1_WAITE:       .equ   %00010000
mSOPT1_STOPE:       .equ   %00100000
mSOPT1_COPT0:       .equ   %01000000
mSOPT1_COPT1:       .equ   %10000000


;*** SOPT2 - System Options Register 2; 0xFFFF9803 ***
SOPT2:              .equ   $FFFF9803                                ;*** SOPT2 - System Options Register 2; 0xFFFF9803 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_ACIC:         .equ   0                                         ; Analog Comparator to Input Capture Enable
SOPT2_SPI2FE:       .equ   1                                         ; SPI2 Ports Input Filter Enable
SOPT2_SPI1FE:       .equ   2                                         ; SPI1 Ports Input Filter Enable
SOPT2_CMT_CLK_SEL:  .equ   3                                         ; CMT Clock Select
SOPT2_CLKOUT_EN:    .equ   4                                         ; Clock Output Enable
SOPT2_USB_BIGEND:   .equ   5                                         ; USB Big Endian
SOPT2_COPW:         .equ   6                                         ; COP Window
SOPT2_COPCLKS:      .equ   7                                         ; COP Watchdog Clock Select
; bit position masks
mSOPT2_ACIC:        .equ   %00000001
mSOPT2_SPI2FE:      .equ   %00000010
mSOPT2_SPI1FE:      .equ   %00000100
mSOPT2_CMT_CLK_SEL: .equ   %00001000
mSOPT2_CLKOUT_EN:   .equ   %00010000
mSOPT2_USB_BIGEND:  .equ   %00100000
mSOPT2_COPW:        .equ   %01000000
mSOPT2_COPCLKS:     .equ   %10000000


;*** SDID - System Device Identification Register; 0xFFFF9806 ***
SDID:               .equ   $FFFF9806                                ;*** SDID - System Device Identification Register; 0xFFFF9806 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDID_ID0:           .equ   0                                         ; Part Identification Number, bit 0
SDID_ID1:           .equ   1                                         ; Part Identification Number, bit 1
SDID_ID2:           .equ   2                                         ; Part Identification Number, bit 2
SDID_ID3:           .equ   3                                         ; Part Identification Number, bit 3
SDID_ID4:           .equ   4                                         ; Part Identification Number, bit 4
SDID_ID5:           .equ   5                                         ; Part Identification Number, bit 5
SDID_ID6:           .equ   6                                         ; Part Identification Number, bit 6
SDID_ID7:           .equ   7                                         ; Part Identification Number, bit 7
SDID_ID8:           .equ   8                                         ; Part Identification Number, bit 8
SDID_ID9:           .equ   9                                         ; Part Identification Number, bit 9
SDID_ID10:          .equ   10                                        ; Part Identification Number, bit 10
SDID_ID11:          .equ   11                                        ; Part Identification Number, bit 11
SDID_REV0:          .equ   12                                        ; Revision number bit 0
SDID_REV1:          .equ   13                                        ; Revision number bit 1
SDID_REV2:          .equ   14                                        ; Revision number bit 2
SDID_REV3:          .equ   15                                        ; Revision number bit 3
; bit position masks
mSDID_ID0:          .equ   %00000001
mSDID_ID1:          .equ   %00000010
mSDID_ID2:          .equ   %00000100
mSDID_ID3:          .equ   %00001000
mSDID_ID4:          .equ   %00010000
mSDID_ID5:          .equ   %00100000
mSDID_ID6:          .equ   %01000000
mSDID_ID7:          .equ   %10000000
mSDID_ID8:          .equ   %100000000
mSDID_ID9:          .equ   %1000000000
mSDID_ID10:         .equ   %10000000000
mSDID_ID11:         .equ   %100000000000
mSDID_REV0:         .equ   %1000000000000
mSDID_REV1:         .equ   %10000000000000
mSDID_REV2:         .equ   %100000000000000
mSDID_REV3:         .equ   %1000000000000000


;*** SDIDH - System Device Identification Register High; 0xFFFF9806 ***
SDIDH:              .equ   $FFFF9806                                ;*** SDIDH - System Device Identification Register High; 0xFFFF9806 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8:          .equ   0                                         ; Part Identification Number, bit 8
SDIDH_ID9:          .equ   1                                         ; Part Identification Number, bit 9
SDIDH_ID10:         .equ   2                                         ; Part Identification Number, bit 10
SDIDH_ID11:         .equ   3                                         ; Part Identification Number, bit 11
SDIDH_REV8:         .equ   4                                         ; Revision number bit 0
SDIDH_REV9:         .equ   5                                         ; Revision number bit 1
SDIDH_REV10:        .equ   6                                         ; Revision number bit 2
SDIDH_REV11:        .equ   7                                         ; Revision number bit 3
; bit position masks
mSDIDH_ID8:         .equ   %00000001
mSDIDH_ID9:         .equ   %00000010
mSDIDH_ID10:        .equ   %00000100
mSDIDH_ID11:        .equ   %00001000
mSDIDH_REV8:        .equ   %00010000
mSDIDH_REV9:        .equ   %00100000
mSDIDH_REV10:       .equ   %01000000
mSDIDH_REV11:       .equ   %10000000


;*** SDIDL - System Device Identification Register Low; 0xFFFF9807 ***
SDIDL:              .equ   $FFFF9807                                ;*** SDIDL - System Device Identification Register Low; 0xFFFF9807 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDL_ID0:          .equ   0                                         ; Part Identification Number, bit 0
SDIDL_ID1:          .equ   1                                         ; Part Identification Number, bit 1
SDIDL_ID2:          .equ   2                                         ; Part Identification Number, bit 2
SDIDL_ID3:          .equ   3                                         ; Part Identification Number, bit 3
SDIDL_ID4:          .equ   4                                         ; Part Identification Number, bit 4
SDIDL_ID5:          .equ   5                                         ; Part Identification Number, bit 5
SDIDL_ID6:          .equ   6                                         ; Part Identification Number, bit 6
SDIDL_ID7:          .equ   7                                         ; Part Identification Number, bit 7
; bit position masks
mSDIDL_ID0:         .equ   %00000001
mSDIDL_ID1:         .equ   %00000010
mSDIDL_ID2:         .equ   %00000100
mSDIDL_ID3:         .equ   %00001000
mSDIDL_ID4:         .equ   %00010000
mSDIDL_ID5:         .equ   %00100000
mSDIDL_ID6:         .equ   %01000000
mSDIDL_ID7:         .equ   %10000000


;*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF9809 ***
SPMSC1:             .equ   $FFFF9809                                ;*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF9809 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE:        .equ   0                                         ; Bandgap Buffer Enable
SPMSC1_LVDE:        .equ   2                                         ; Low-Voltage Detect Enable
SPMSC1_LVDSE:       .equ   3                                         ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE:       .equ   4                                         ; Low-Voltage Detect Reset Enable
SPMSC1_LVWIE:       .equ   5                                         ; Low-Voltage Warning Interrupt Enable
SPMSC1_LVWACK:      .equ   6                                         ; Low-Voltage Warning Acknowledge
SPMSC1_LVWF:        .equ   7                                         ; Low-Voltage Warning status
; bit position masks
mSPMSC1_BGBE:       .equ   %00000001
mSPMSC1_LVDE:       .equ   %00000100
mSPMSC1_LVDSE:      .equ   %00001000
mSPMSC1_LVDRE:      .equ   %00010000
mSPMSC1_LVWIE:      .equ   %00100000
mSPMSC1_LVWACK:     .equ   %01000000
mSPMSC1_LVWF:       .equ   %10000000


;*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF980A ***
SPMSC2:             .equ   $FFFF980A                                ;*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF980A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC:        .equ   0                                         ; Partial Power Down Control
SPMSC2_PPDACK:      .equ   2                                         ; Partial Power Down Acknowledge
SPMSC2_PPDF:        .equ   3                                         ; Partial Power Down Flag
SPMSC2_LVWV:        .equ   4                                         ; Low-Voltage Warning Voltage Select
SPMSC2_LVDV:        .equ   5                                         ; Low-Voltage Detect Voltage Select
; bit position masks
mSPMSC2_PPDC:       .equ   %00000001
mSPMSC2_PPDACK:     .equ   %00000100
mSPMSC2_PPDF:       .equ   %00001000
mSPMSC2_LVWV:       .equ   %00010000
mSPMSC2_LVDV:       .equ   %00100000


;*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF980B ***
SCGC1:              .equ   $FFFF980B                                ;*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF980B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI1:         .equ   0                                         ; SCI1 Clock Gate Control
SCGC1_SCI2:         .equ   1                                         ; SCI2 Clock Gate Control
SCGC1_IIC1:         .equ   2                                         ; IIC1 Clock Gate Control
SCGC1_IIC2:         .equ   3                                         ; IIC2 Clock Gate Control
SCGC1_ADC:          .equ   4                                         ; ADC Clock Gate Control
SCGC1_TPM1:         .equ   5                                         ; TPM1 Clock Gate Control
SCGC1_TPM2:         .equ   6                                         ; TPM2 Clock Gate Control
SCGC1_CMT:          .equ   7                                         ; CMT Clock Gate Control
; bit position masks
mSCGC1_SCI1:        .equ   %00000001
mSCGC1_SCI2:        .equ   %00000010
mSCGC1_IIC1:        .equ   %00000100
mSCGC1_IIC2:        .equ   %00001000
mSCGC1_ADC:         .equ   %00010000
mSCGC1_TPM1:        .equ   %00100000
mSCGC1_TPM2:        .equ   %01000000
mSCGC1_CMT:         .equ   %10000000


;*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF980C ***
SCGC2:              .equ   $FFFF980C                                ;*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF980C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI1:         .equ   0                                         ; SPI1 Clock Gate Control
SCGC2_SPI2:         .equ   1                                         ; SPI2 Clock Gate Control
SCGC2_RTC:          .equ   2                                         ; RTC Clock Gate Control
SCGC2_ACMP:         .equ   3                                         ; ACMP Clock Gate Control
SCGC2_KBI:          .equ   4                                         ; KBI Clock Gate Control
SCGC2_IRQ:          .equ   5                                         ; IRQ Clock Gate Control
SCGC2_FLS:          .equ   6                                         ; FLASH Register Clock Gate Control
SCGC2_USB:          .equ   7                                         ; USB Clock Gate Control
; bit position masks
mSCGC2_SPI1:        .equ   %00000001
mSCGC2_SPI2:        .equ   %00000010
mSCGC2_RTC:         .equ   %00000100
mSCGC2_ACMP:        .equ   %00001000
mSCGC2_KBI:         .equ   %00010000
mSCGC2_IRQ:         .equ   %00100000
mSCGC2_FLS:         .equ   %01000000
mSCGC2_USB:         .equ   %10000000


;*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF980D ***
SCGC3:              .equ   $FFFF980D                                ;*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF980D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC3_RNGA:         .equ   0                                         ; RNGA Clock Gate Control
; bit position masks
mSCGC3_RNGA:        .equ   %00000001


;*** SOPT3 - System Options 3 Register; 0xFFFF980E ***
SOPT3:              .equ   $FFFF980E                                ;*** SOPT3 - System Options 3 Register; 0xFFFF980E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT3_CMT_PAD:      .equ   0                                         ; CMT pad drive strength
; bit position masks
mSOPT3_CMT_PAD:     .equ   %00000001


;*** SOPT4 - System Options 4 Register; 0xFFFF980F ***
SOPT4:              .equ   $FFFF980F                                ;*** SOPT4 - System Options 4 Register; 0xFFFF980F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT4_PMC_LVD_TRIM0: .equ   0                                        ; PMC LVD TRIM, bit 0
SOPT4_PMC_LVD_TRIM1: .equ   1                                        ; PMC LVD TRIM, bit 1
SOPT4_PMC_LVD_TRIM2: .equ   2                                        ; PMC LVD TRIM, bit 2
SOPT4_PMC_LVD_TRIM3: .equ   3                                        ; PMC LVD TRIM, bit 3
; bit position masks
mSOPT4_PMC_LVD_TRIM0: .equ   %00000001
mSOPT4_PMC_LVD_TRIM1: .equ   %00000010
mSOPT4_PMC_LVD_TRIM2: .equ   %00000100
mSOPT4_PMC_LVD_TRIM3: .equ   %00001000


;*** FCDIV - FLASH Clock Divider Register; 0xFFFF9820 ***
FCDIV:              .equ   $FFFF9820                                ;*** FCDIV - FLASH Clock Divider Register; 0xFFFF9820 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCDIV_FDIV0:        .equ   0                                         ; Divisor for FLASH Clock Divider, bit 0
FCDIV_FDIV1:        .equ   1                                         ; Divisor for FLASH Clock Divider, bit 1
FCDIV_FDIV2:        .equ   2                                         ; Divisor for FLASH Clock Divider, bit 2
FCDIV_FDIV3:        .equ   3                                         ; Divisor for FLASH Clock Divider, bit 3
FCDIV_FDIV4:        .equ   4                                         ; Divisor for FLASH Clock Divider, bit 4
FCDIV_FDIV5:        .equ   5                                         ; Divisor for FLASH Clock Divider, bit 5
FCDIV_PRDIV8:       .equ   6                                         ; Prescale (Divide) FLASH Clock by 8
FCDIV_FDIVLD:       .equ   7                                         ; Divisor Loaded Status Flag
; bit position masks
mFCDIV_FDIV0:       .equ   %00000001
mFCDIV_FDIV1:       .equ   %00000010
mFCDIV_FDIV2:       .equ   %00000100
mFCDIV_FDIV3:       .equ   %00001000
mFCDIV_FDIV4:       .equ   %00010000
mFCDIV_FDIV5:       .equ   %00100000
mFCDIV_PRDIV8:      .equ   %01000000
mFCDIV_FDIVLD:      .equ   %10000000


;*** FOPT - Flash Options Register; 0xFFFF9821 ***
FOPT:               .equ   $FFFF9821                                ;*** FOPT - Flash Options Register; 0xFFFF9821 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SEC0:          .equ   0                                         ; Flash Security Bit 0
FOPT_SEC1:          .equ   1                                         ; Flash Security Bit 1
FOPT_KEYEN0:        .equ   6                                         ; Backdoor Key Security Enable Bit 0
FOPT_KEYEN1:        .equ   7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mFOPT_SEC0:         .equ   %00000001
mFOPT_SEC1:         .equ   %00000010
mFOPT_KEYEN0:       .equ   %01000000
mFOPT_KEYEN1:       .equ   %10000000


;*** FCNFG - Flash Configuration Register; 0xFFFF9823 ***
FCNFG:              .equ   $FFFF9823                                ;*** FCNFG - Flash Configuration Register; 0xFFFF9823 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC:       .equ   5                                         ; Enable Security Key Writing
; bit position masks
mFCNFG_KEYACC:      .equ   %00100000


;*** FPROT - Flash Protection Register; 0xFFFF9824 ***
FPROT:              .equ   $FFFF9824                                ;*** FPROT - Flash Protection Register; 0xFFFF9824 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPOPEN:       .equ   0                                         ; Flash Protection Open
FPROT_FPS0:         .equ   1                                         ; Flash Protection Size, bit 0
FPROT_FPS1:         .equ   2                                         ; Flash Protection Size, bit 1
FPROT_FPS2:         .equ   3                                         ; Flash Protection Size, bit 2
FPROT_FPS3:         .equ   4                                         ; Flash Protection Size, bit 3
FPROT_FPS4:         .equ   5                                         ; Flash Protection Size, bit 4
FPROT_FPS5:         .equ   6                                         ; Flash Protection Size, bit 5
FPROT_FPS6:         .equ   7                                         ; Flash Protection Size, bit 6
; bit position masks
mFPROT_FPOPEN:      .equ   %00000001
mFPROT_FPS0:        .equ   %00000010
mFPROT_FPS1:        .equ   %00000100
mFPROT_FPS2:        .equ   %00001000
mFPROT_FPS3:        .equ   %00010000
mFPROT_FPS4:        .equ   %00100000
mFPROT_FPS5:        .equ   %01000000
mFPROT_FPS6:        .equ   %10000000


;*** FSTAT - Flash Status Register; 0xFFFF9825 ***
FSTAT:              .equ   $FFFF9825                                ;*** FSTAT - Flash Status Register; 0xFFFF9825 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSTAT_FBLANK:       .equ   2                                         ; FLASH Flag Indicating the Erase Verify Operation Status
FSTAT_FACCERR:      .equ   4                                         ; FLASH Access Error Flag
FSTAT_FPVIOL:       .equ   5                                         ; FLASH Protection Violation Flag
FSTAT_FCCF:         .equ   6                                         ; FLASH Command Complete Interrupt Flag
FSTAT_FCBEF:        .equ   7                                         ; FLASH Command Buffer Empty Flag
; bit position masks
mFSTAT_FBLANK:      .equ   %00000100
mFSTAT_FACCERR:     .equ   %00010000
mFSTAT_FPVIOL:      .equ   %00100000
mFSTAT_FCCF:        .equ   %01000000
mFSTAT_FCBEF:       .equ   %10000000


;*** FCMD - Flash Command Register; 0xFFFF9826 ***
FCMD:               .equ   $FFFF9826                                ;*** FCMD - Flash Command Register; 0xFFFF9826 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCMD_FCMD0:         .equ   0                                         ; Flash Command, bit 0
FCMD_FCMD1:         .equ   1                                         ; Flash Command, bit 1
FCMD_FCMD2:         .equ   2                                         ; Flash Command, bit 2
FCMD_FCMD3:         .equ   3                                         ; Flash Command, bit 3
FCMD_FCMD4:         .equ   4                                         ; Flash Command, bit 4
FCMD_FCMD5:         .equ   5                                         ; Flash Command, bit 5
FCMD_FCMD6:         .equ   6                                         ; Flash Command, bit 6
; bit position masks
mFCMD_FCMD0:        .equ   %00000001
mFCMD_FCMD1:        .equ   %00000010
mFCMD_FCMD2:        .equ   %00000100
mFCMD_FCMD3:        .equ   %00001000
mFCMD_FCMD4:        .equ   %00010000
mFCMD_FCMD5:        .equ   %00100000
mFCMD_FCMD6:        .equ   %01000000


;*** IIC2A - IIC Address Register; 0xFFFF9838 ***
IIC2A:              .equ   $FFFF9838                                ;*** IIC2A - IIC Address Register; 0xFFFF9838 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2A_AD1:          .equ   1                                         ; Slave Address Bit 1
IIC2A_AD2:          .equ   2                                         ; Slave Address Bit 2
IIC2A_AD3:          .equ   3                                         ; Slave Address Bit 3
IIC2A_AD4:          .equ   4                                         ; Slave Address Bit 4
IIC2A_AD5:          .equ   5                                         ; Slave Address Bit 5
IIC2A_AD6:          .equ   6                                         ; Slave Address Bit 6
IIC2A_AD7:          .equ   7                                         ; Slave Address Bit 7
; bit position masks
mIIC2A_AD1:         .equ   %00000010
mIIC2A_AD2:         .equ   %00000100
mIIC2A_AD3:         .equ   %00001000
mIIC2A_AD4:         .equ   %00010000
mIIC2A_AD5:         .equ   %00100000
mIIC2A_AD6:         .equ   %01000000
mIIC2A_AD7:         .equ   %10000000


;*** IIC2F - IIC Frequency Divider Register; 0xFFFF9839 ***
IIC2F:              .equ   $FFFF9839                                ;*** IIC2F - IIC Frequency Divider Register; 0xFFFF9839 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2F_ICR0:         .equ   0                                         ; IIC Clock Rate Bit 0
IIC2F_ICR1:         .equ   1                                         ; IIC Clock Rate Bit 1
IIC2F_ICR2:         .equ   2                                         ; IIC Clock Rate Bit 2
IIC2F_ICR3:         .equ   3                                         ; IIC Clock Rate Bit 3
IIC2F_ICR4:         .equ   4                                         ; IIC Clock Rate Bit 4
IIC2F_ICR5:         .equ   5                                         ; IIC Clock Rate Bit 5
IIC2F_MULT0:        .equ   6                                         ; Multiplier Factor Bit 0
IIC2F_MULT1:        .equ   7                                         ; Multiplier Factor Bit 1
; bit position masks
mIIC2F_ICR0:        .equ   %00000001
mIIC2F_ICR1:        .equ   %00000010
mIIC2F_ICR2:        .equ   %00000100
mIIC2F_ICR3:        .equ   %00001000
mIIC2F_ICR4:        .equ   %00010000
mIIC2F_ICR5:        .equ   %00100000
mIIC2F_MULT0:       .equ   %01000000
mIIC2F_MULT1:       .equ   %10000000


;*** IIC2C1 - IIC Control Register 1; 0xFFFF983A ***
IIC2C1:             .equ   $FFFF983A                                ;*** IIC2C1 - IIC Control Register 1; 0xFFFF983A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2C1_RSTA:        .equ   2                                         ; Repeat START
IIC2C1_TXAK:        .equ   3                                         ; Transmit Acknowledge Enable
IIC2C1_TX:          .equ   4                                         ; Transmit Mode Select
IIC2C1_MST:         .equ   5                                         ; Master Mode Select
IIC2C1_IICIE:       .equ   6                                         ; IIC Interrupt Enable
IIC2C1_IICEN:       .equ   7                                         ; IIC Enable
; bit position masks
mIIC2C1_RSTA:       .equ   %00000100
mIIC2C1_TXAK:       .equ   %00001000
mIIC2C1_TX:         .equ   %00010000
mIIC2C1_MST:        .equ   %00100000
mIIC2C1_IICIE:      .equ   %01000000
mIIC2C1_IICEN:      .equ   %10000000


;*** IIC2C - IIC Control Register; 0xFFFF983A ***
IIC2C:              .equ   $FFFF983A                                ;*** IIC2C - IIC Control Register; 0xFFFF983A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2C_RSTA:         .equ   2                                         ; Repeat START
IIC2C_TXAK:         .equ   3                                         ; Transmit Acknowledge Enable
IIC2C_TX:           .equ   4                                         ; Transmit Mode Select
IIC2C_MST:          .equ   5                                         ; Master Mode Select
IIC2C_IICIE:        .equ   6                                         ; IIC Interrupt Enable
IIC2C_IICEN:        .equ   7                                         ; IIC Enable
; bit position masks
mIIC2C_RSTA:        .equ   %00000100
mIIC2C_TXAK:        .equ   %00001000
mIIC2C_TX:          .equ   %00010000
mIIC2C_MST:         .equ   %00100000
mIIC2C_IICIE:       .equ   %01000000
mIIC2C_IICEN:       .equ   %10000000


;*** IIC2S - IIC Status Register; 0xFFFF983B ***
IIC2S:              .equ   $FFFF983B                                ;*** IIC2S - IIC Status Register; 0xFFFF983B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2S_RXAK:         .equ   0                                         ; Receive Acknowledge
IIC2S_IICIF:        .equ   1                                         ; IIC Interrupt Flag
IIC2S_SRW:          .equ   2                                         ; Slave Read/Write
IIC2S_ARBL:         .equ   4                                         ; Arbitration Lost
IIC2S_BUSY:         .equ   5                                         ; Bus Busy
IIC2S_IAAS:         .equ   6                                         ; Addressed as a Slave
IIC2S_TCF:          .equ   7                                         ; Transfer Complete Flag
; bit position masks
mIIC2S_RXAK:        .equ   %00000001
mIIC2S_IICIF:       .equ   %00000010
mIIC2S_SRW:         .equ   %00000100
mIIC2S_ARBL:        .equ   %00010000
mIIC2S_BUSY:        .equ   %00100000
mIIC2S_IAAS:        .equ   %01000000
mIIC2S_TCF:         .equ   %10000000


;*** IIC2D - IIC Data I/O Register; 0xFFFF983C ***
IIC2D:              .equ   $FFFF983C                                ;*** IIC2D - IIC Data I/O Register; 0xFFFF983C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2D_DATA0:        .equ   0                                         ; IIC Data Bit 0
IIC2D_DATA1:        .equ   1                                         ; IIC Data Bit 1
IIC2D_DATA2:        .equ   2                                         ; IIC Data Bit 2
IIC2D_DATA3:        .equ   3                                         ; IIC Data Bit 3
IIC2D_DATA4:        .equ   4                                         ; IIC Data Bit 4
IIC2D_DATA5:        .equ   5                                         ; IIC Data Bit 5
IIC2D_DATA6:        .equ   6                                         ; IIC Data Bit 6
IIC2D_DATA7:        .equ   7                                         ; IIC Data Bit 7
; bit position masks
mIIC2D_DATA0:       .equ   %00000001
mIIC2D_DATA1:       .equ   %00000010
mIIC2D_DATA2:       .equ   %00000100
mIIC2D_DATA3:       .equ   %00001000
mIIC2D_DATA4:       .equ   %00010000
mIIC2D_DATA5:       .equ   %00100000
mIIC2D_DATA6:       .equ   %01000000
mIIC2D_DATA7:       .equ   %10000000


;*** IIC2C2 - IIC Control Register 2; 0xFFFF983D ***
IIC2C2:             .equ   $FFFF983D                                ;*** IIC2C2 - IIC Control Register 2; 0xFFFF983D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2C2_AD8:         .equ   0                                         ; Slave Address Bit 8
IIC2C2_AD9:         .equ   1                                         ; Slave Address Bit 9
IIC2C2_AD10:        .equ   2                                         ; Slave Address Bit 10
IIC2C2_ADEXT:       .equ   6                                         ; Address Extension
IIC2C2_GCAEN:       .equ   7                                         ; General Call Address Enable
; bit position masks
mIIC2C2_AD8:        .equ   %00000001
mIIC2C2_AD9:        .equ   %00000010
mIIC2C2_AD10:       .equ   %00000100
mIIC2C2_ADEXT:      .equ   %01000000
mIIC2C2_GCAEN:      .equ   %10000000


;*** PTAPE - Port A Pull Enable Register; 0xFFFF9840 ***
PTAPE:              .equ   $FFFF9840                                ;*** PTAPE - Port A Pull Enable Register; 0xFFFF9840 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0:       .equ   0                                         ; Internal Pull Enable for Port A Bit 0
PTAPE_PTAPE1:       .equ   1                                         ; Internal Pull Enable for Port A Bit 1
PTAPE_PTAPE2:       .equ   2                                         ; Internal Pull Enable for Port A Bit 2
PTAPE_PTAPE3:       .equ   3                                         ; Internal Pull Enable for Port A Bit 3
PTAPE_PTAPE4:       .equ   4                                         ; Internal Pull Enable for Port A Bit 4
PTAPE_PTAPE5:       .equ   5                                         ; Internal Pull Enable for Port A Bit 5
PTAPE_PTAPE6:       .equ   6                                         ; Internal Pull Enable for Port A Bit 6
PTAPE_PTAPE7:       .equ   7                                         ; Internal Pull Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0:      .equ   %00000001
mPTAPE_PTAPE1:      .equ   %00000010
mPTAPE_PTAPE2:      .equ   %00000100
mPTAPE_PTAPE3:      .equ   %00001000
mPTAPE_PTAPE4:      .equ   %00010000
mPTAPE_PTAPE5:      .equ   %00100000
mPTAPE_PTAPE6:      .equ   %01000000
mPTAPE_PTAPE7:      .equ   %10000000


;*** PTASE - Port A Slew Rate Enable Register; 0xFFFF9841 ***
PTASE:              .equ   $FFFF9841                                ;*** PTASE - Port A Slew Rate Enable Register; 0xFFFF9841 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0:       .equ   0                                         ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1:       .equ   1                                         ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE2:       .equ   2                                         ; Output Slew Rate Enable for Port A Bit 2
PTASE_PTASE3:       .equ   3                                         ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4:       .equ   4                                         ; Output Slew Rate Enable for Port A Bit 4
PTASE_PTASE5:       .equ   5                                         ; Output Slew Rate Enable for Port A Bit 5
PTASE_PTASE6:       .equ   6                                         ; Output Slew Rate Enable for Port A Bit 6
PTASE_PTASE7:       .equ   7                                         ; Output Slew Rate Enable for Port A Bit 7
; bit position masks
mPTASE_PTASE0:      .equ   %00000001
mPTASE_PTASE1:      .equ   %00000010
mPTASE_PTASE2:      .equ   %00000100
mPTASE_PTASE3:      .equ   %00001000
mPTASE_PTASE4:      .equ   %00010000
mPTASE_PTASE5:      .equ   %00100000
mPTASE_PTASE6:      .equ   %01000000
mPTASE_PTASE7:      .equ   %10000000


;*** PTADS - Port A Drive Strength Selection Register; 0xFFFF9842 ***
PTADS:              .equ   $FFFF9842                                ;*** PTADS - Port A Drive Strength Selection Register; 0xFFFF9842 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0:       .equ   0                                         ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS1:       .equ   1                                         ; Output Drive Strength Selection for Port A Bit 1
PTADS_PTADS2:       .equ   2                                         ; Output Drive Strength Selection for Port A Bit 2
PTADS_PTADS3:       .equ   3                                         ; Output Drive Strength Selection for Port A Bit 3
PTADS_PTADS4:       .equ   4                                         ; Output Drive Strength Selection for Port A Bit 4
PTADS_PTADS5:       .equ   5                                         ; Output Drive Strength Selection for Port A Bit 5
PTADS_PTADS6:       .equ   6                                         ; Output Drive Strength Selection for Port A Bit 6
PTADS_PTADS7:       .equ   7                                         ; Output Drive Strength Selection for Port A Bit 7
; bit position masks
mPTADS_PTADS0:      .equ   %00000001
mPTADS_PTADS1:      .equ   %00000010
mPTADS_PTADS2:      .equ   %00000100
mPTADS_PTADS3:      .equ   %00001000
mPTADS_PTADS4:      .equ   %00010000
mPTADS_PTADS5:      .equ   %00100000
mPTADS_PTADS6:      .equ   %01000000
mPTADS_PTADS7:      .equ   %10000000


;*** PTAIFE - Port A Input Filter Enable Register; 0xFFFF9843 ***
PTAIFE:             .equ   $FFFF9843                                ;*** PTAIFE - Port A Input Filter Enable Register; 0xFFFF9843 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAIFE_PTAIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTAIFE_PTAIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTAIFE_PTAIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTAIFE_PTAIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTAIFE_PTAIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTAIFE_PTAIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTAIFE_PTAIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTAIFE_PTAIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTAIFE_PTAIFE0:    .equ   %00000001
mPTAIFE_PTAIFE1:    .equ   %00000010
mPTAIFE_PTAIFE2:    .equ   %00000100
mPTAIFE_PTAIFE3:    .equ   %00001000
mPTAIFE_PTAIFE4:    .equ   %00010000
mPTAIFE_PTAIFE5:    .equ   %00100000
mPTAIFE_PTAIFE6:    .equ   %01000000
mPTAIFE_PTAIFE7:    .equ   %10000000


;*** PTBPE - Port B Pull Enable Register; 0xFFFF9844 ***
PTBPE:              .equ   $FFFF9844                                ;*** PTBPE - Port B Pull Enable Register; 0xFFFF9844 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0:       .equ   0                                         ; Internal Pull Enable for Port B Bit 0
PTBPE_PTBPE1:       .equ   1                                         ; Internal Pull Enable for Port B Bit 1
PTBPE_PTBPE2:       .equ   2                                         ; Internal Pull Enable for Port B Bit 2
PTBPE_PTBPE3:       .equ   3                                         ; Internal Pull Enable for Port B Bit 3
PTBPE_PTBPE4:       .equ   4                                         ; Internal Pull Enable for Port B Bit 4
PTBPE_PTBPE5:       .equ   5                                         ; Internal Pull Enable for Port B Bit 5
PTBPE_PTBPE6:       .equ   6                                         ; Internal Pull Enable for Port B Bit 6
PTBPE_PTBPE7:       .equ   7                                         ; Internal Pull Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0:      .equ   %00000001
mPTBPE_PTBPE1:      .equ   %00000010
mPTBPE_PTBPE2:      .equ   %00000100
mPTBPE_PTBPE3:      .equ   %00001000
mPTBPE_PTBPE4:      .equ   %00010000
mPTBPE_PTBPE5:      .equ   %00100000
mPTBPE_PTBPE6:      .equ   %01000000
mPTBPE_PTBPE7:      .equ   %10000000


;*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF9845 ***
PTBSE:              .equ   $FFFF9845                                ;*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF9845 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE0:       .equ   0                                         ; Output Slew Rate Enable for Port B Bit 0
PTBSE_PTBSE1:       .equ   1                                         ; Output Slew Rate Enable for Port B Bit 1
PTBSE_PTBSE2:       .equ   2                                         ; Output Slew Rate Enable for Port B Bit 2
PTBSE_PTBSE3:       .equ   3                                         ; Output Slew Rate Enable for Port B Bit 3
PTBSE_PTBSE4:       .equ   4                                         ; Output Slew Rate Enable for Port B Bit 4
PTBSE_PTBSE5:       .equ   5                                         ; Output Slew Rate Enable for Port B Bit 5
PTBSE_PTBSE6:       .equ   6                                         ; Output Slew Rate Enable for Port B Bit 6
PTBSE_PTBSE7:       .equ   7                                         ; Output Slew Rate Enable for Port B Bit 7
; bit position masks
mPTBSE_PTBSE0:      .equ   %00000001
mPTBSE_PTBSE1:      .equ   %00000010
mPTBSE_PTBSE2:      .equ   %00000100
mPTBSE_PTBSE3:      .equ   %00001000
mPTBSE_PTBSE4:      .equ   %00010000
mPTBSE_PTBSE5:      .equ   %00100000
mPTBSE_PTBSE6:      .equ   %01000000
mPTBSE_PTBSE7:      .equ   %10000000


;*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF9846 ***
PTBDS:              .equ   $FFFF9846                                ;*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF9846 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS0:       .equ   0                                         ; Output Drive Strength Selection for Port B Bit 0
PTBDS_PTBDS1:       .equ   1                                         ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2:       .equ   2                                         ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS3:       .equ   3                                         ; Output Drive Strength Selection for Port B Bit 3
PTBDS_PTBDS4:       .equ   4                                         ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5:       .equ   5                                         ; Output Drive Strength Selection for Port B Bit 5
PTBDS_PTBDS6:       .equ   6                                         ; Output Drive Strength Selection for Port B Bit 6
PTBDS_PTBDS7:       .equ   7                                         ; Output Drive Strength Selection for Port B Bit 7
; bit position masks
mPTBDS_PTBDS0:      .equ   %00000001
mPTBDS_PTBDS1:      .equ   %00000010
mPTBDS_PTBDS2:      .equ   %00000100
mPTBDS_PTBDS3:      .equ   %00001000
mPTBDS_PTBDS4:      .equ   %00010000
mPTBDS_PTBDS5:      .equ   %00100000
mPTBDS_PTBDS6:      .equ   %01000000
mPTBDS_PTBDS7:      .equ   %10000000


;*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF9847 ***
PTBIFE:             .equ   $FFFF9847                                ;*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF9847 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBIFE_PTBIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTBIFE_PTBIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTBIFE_PTBIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTBIFE_PTBIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTBIFE_PTBIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTBIFE_PTBIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTBIFE_PTBIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTBIFE_PTBIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTBIFE_PTBIFE0:    .equ   %00000001
mPTBIFE_PTBIFE1:    .equ   %00000010
mPTBIFE_PTBIFE2:    .equ   %00000100
mPTBIFE_PTBIFE3:    .equ   %00001000
mPTBIFE_PTBIFE4:    .equ   %00010000
mPTBIFE_PTBIFE5:    .equ   %00100000
mPTBIFE_PTBIFE6:    .equ   %01000000
mPTBIFE_PTBIFE7:    .equ   %10000000


;*** PTCPE - Port C Pull Enable Register; 0xFFFF9848 ***
PTCPE:              .equ   $FFFF9848                                ;*** PTCPE - Port C Pull Enable Register; 0xFFFF9848 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0:       .equ   0                                         ; Internal Pull Enable for Port C Bit 0
PTCPE_PTCPE1:       .equ   1                                         ; Internal Pull Enable for Port C Bit 1
PTCPE_PTCPE2:       .equ   2                                         ; Internal Pull Enable for Port C Bit 2
PTCPE_PTCPE3:       .equ   3                                         ; Internal Pull Enable for Port C Bit 3
PTCPE_PTCPE4:       .equ   4                                         ; Internal Pull Enable for Port C Bit 4
PTCPE_PTCPE5:       .equ   5                                         ; Internal Pull Enable for Port C Bit 5
PTCPE_PTCPE6:       .equ   6                                         ; Internal Pull Enable for Port C Bit 6
PTCPE_PTCPE7:       .equ   7                                         ; Internal Pull Enable for Port C Bit 7
; bit position masks
mPTCPE_PTCPE0:      .equ   %00000001
mPTCPE_PTCPE1:      .equ   %00000010
mPTCPE_PTCPE2:      .equ   %00000100
mPTCPE_PTCPE3:      .equ   %00001000
mPTCPE_PTCPE4:      .equ   %00010000
mPTCPE_PTCPE5:      .equ   %00100000
mPTCPE_PTCPE6:      .equ   %01000000
mPTCPE_PTCPE7:      .equ   %10000000


;*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF9849 ***
PTCSE:              .equ   $FFFF9849                                ;*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF9849 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0:       .equ   0                                         ; Output Slew Rate Enable for Port C Bit 0
PTCSE_PTCSE1:       .equ   1                                         ; Output Slew Rate Enable for Port C Bit 1
PTCSE_PTCSE2:       .equ   2                                         ; Output Slew Rate Enable for Port C Bit 2
PTCSE_PTCSE3:       .equ   3                                         ; Output Slew Rate Enable for Port C Bit 3
PTCSE_PTCSE4:       .equ   4                                         ; Output Slew Rate Enable for Port C Bit 4
PTCSE_PTCSE5:       .equ   5                                         ; Output Slew Rate Enable for Port C Bit 5
PTCSE_PTCSE6:       .equ   6                                         ; Output Slew Rate Enable for Port C Bit 6
PTCSE_PTCSE7:       .equ   7                                         ; Output Slew Rate Enable for Port C Bit 7
; bit position masks
mPTCSE_PTCSE0:      .equ   %00000001
mPTCSE_PTCSE1:      .equ   %00000010
mPTCSE_PTCSE2:      .equ   %00000100
mPTCSE_PTCSE3:      .equ   %00001000
mPTCSE_PTCSE4:      .equ   %00010000
mPTCSE_PTCSE5:      .equ   %00100000
mPTCSE_PTCSE6:      .equ   %01000000
mPTCSE_PTCSE7:      .equ   %10000000


;*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF984A ***
PTCDS:              .equ   $FFFF984A                                ;*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF984A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0:       .equ   0                                         ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1:       .equ   1                                         ; Output Drive Strength Selection for Port C Bit 1
PTCDS_PTCDS2:       .equ   2                                         ; Output Drive Strength Selection for Port C Bit 2
PTCDS_PTCDS3:       .equ   3                                         ; Output Drive Strength Selection for Port C Bit 3
PTCDS_PTCDS4:       .equ   4                                         ; Output Drive Strength Selection for Port C Bit 4
PTCDS_PTCDS5:       .equ   5                                         ; Output Drive Strength Selection for Port C Bit 5
PTCDS_PTCDS6:       .equ   6                                         ; Output Drive Strength Selection for Port C Bit 6
PTCDS_PTCDS7:       .equ   7                                         ; Output Drive Strength Selection for Port C Bit 7
; bit position masks
mPTCDS_PTCDS0:      .equ   %00000001
mPTCDS_PTCDS1:      .equ   %00000010
mPTCDS_PTCDS2:      .equ   %00000100
mPTCDS_PTCDS3:      .equ   %00001000
mPTCDS_PTCDS4:      .equ   %00010000
mPTCDS_PTCDS5:      .equ   %00100000
mPTCDS_PTCDS6:      .equ   %01000000
mPTCDS_PTCDS7:      .equ   %10000000


;*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF984B ***
PTCIFE:             .equ   $FFFF984B                                ;*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF984B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCIFE_PTCIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTCIFE_PTCIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTCIFE_PTCIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTCIFE_PTCIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTCIFE_PTCIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTCIFE_PTCIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTCIFE_PTCIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTCIFE_PTCIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTCIFE_PTCIFE0:    .equ   %00000001
mPTCIFE_PTCIFE1:    .equ   %00000010
mPTCIFE_PTCIFE2:    .equ   %00000100
mPTCIFE_PTCIFE3:    .equ   %00001000
mPTCIFE_PTCIFE4:    .equ   %00010000
mPTCIFE_PTCIFE5:    .equ   %00100000
mPTCIFE_PTCIFE6:    .equ   %01000000
mPTCIFE_PTCIFE7:    .equ   %10000000


;*** PTDPE - Port D Pull Enable Register; 0xFFFF984C ***
PTDPE:              .equ   $FFFF984C                                ;*** PTDPE - Port D Pull Enable Register; 0xFFFF984C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0:       .equ   0                                         ; Internal Pull Enable for Port D Bit 0
PTDPE_PTDPE1:       .equ   1                                         ; Internal Pull Enable for Port D Bit 1
PTDPE_PTDPE2:       .equ   2                                         ; Internal Pull Enable for Port D Bit 2
PTDPE_PTDPE3:       .equ   3                                         ; Internal Pull Enable for Port D Bit 3
PTDPE_PTDPE4:       .equ   4                                         ; Internal Pull Enable for Port D Bit 4
PTDPE_PTDPE5:       .equ   5                                         ; Internal Pull Enable for Port D Bit 5
PTDPE_PTDPE6:       .equ   6                                         ; Internal Pull Enable for Port D Bit 6
PTDPE_PTDPE7:       .equ   7                                         ; Internal Pull Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0:      .equ   %00000001
mPTDPE_PTDPE1:      .equ   %00000010
mPTDPE_PTDPE2:      .equ   %00000100
mPTDPE_PTDPE3:      .equ   %00001000
mPTDPE_PTDPE4:      .equ   %00010000
mPTDPE_PTDPE5:      .equ   %00100000
mPTDPE_PTDPE6:      .equ   %01000000
mPTDPE_PTDPE7:      .equ   %10000000


;*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF984D ***
PTDSE:              .equ   $FFFF984D                                ;*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF984D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSE_PTDSE0:       .equ   0                                         ; Output Slew Rate Enable for Port D Bit 0
PTDSE_PTDSE1:       .equ   1                                         ; Output Slew Rate Enable for Port D Bit 1
PTDSE_PTDSE2:       .equ   2                                         ; Output Slew Rate Enable for Port D Bit 2
PTDSE_PTDSE3:       .equ   3                                         ; Output Slew Rate Enable for Port D Bit 3
PTDSE_PTDSE4:       .equ   4                                         ; Output Slew Rate Enable for Port D Bit 4
PTDSE_PTDSE5:       .equ   5                                         ; Output Slew Rate Enable for Port D Bit 5
PTDSE_PTDSE6:       .equ   6                                         ; Output Slew Rate Enable for Port D Bit 6
PTDSE_PTDSE7:       .equ   7                                         ; Output Slew Rate Enable for Port D Bit 7
; bit position masks
mPTDSE_PTDSE0:      .equ   %00000001
mPTDSE_PTDSE1:      .equ   %00000010
mPTDSE_PTDSE2:      .equ   %00000100
mPTDSE_PTDSE3:      .equ   %00001000
mPTDSE_PTDSE4:      .equ   %00010000
mPTDSE_PTDSE5:      .equ   %00100000
mPTDSE_PTDSE6:      .equ   %01000000
mPTDSE_PTDSE7:      .equ   %10000000


;*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF984E ***
PTDDS:              .equ   $FFFF984E                                ;*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF984E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDS_PTDDS0:       .equ   0                                         ; Output Drive Strength Selection for Port D Bit 0
PTDDS_PTDDS1:       .equ   1                                         ; Output Drive Strength Selection for Port D Bit 1
PTDDS_PTDDS2:       .equ   2                                         ; Output Drive Strength Selection for Port D Bit 2
PTDDS_PTDDS3:       .equ   3                                         ; Output Drive Strength Selection for Port D Bit 3
PTDDS_PTDDS4:       .equ   4                                         ; Output Drive Strength Selection for Port D Bit 4
PTDDS_PTDDS5:       .equ   5                                         ; Output Drive Strength Selection for Port D Bit 5
PTDDS_PTDDS6:       .equ   6                                         ; Output Drive Strength Selection for Port D Bit 6
PTDDS_PTDDS7:       .equ   7                                         ; Output Drive Strength Selection for Port D Bit 7
; bit position masks
mPTDDS_PTDDS0:      .equ   %00000001
mPTDDS_PTDDS1:      .equ   %00000010
mPTDDS_PTDDS2:      .equ   %00000100
mPTDDS_PTDDS3:      .equ   %00001000
mPTDDS_PTDDS4:      .equ   %00010000
mPTDDS_PTDDS5:      .equ   %00100000
mPTDDS_PTDDS6:      .equ   %01000000
mPTDDS_PTDDS7:      .equ   %10000000


;*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF984F ***
PTDIFE:             .equ   $FFFF984F                                ;*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF984F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDIFE_PTDIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTDIFE_PTDIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTDIFE_PTDIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTDIFE_PTDIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTDIFE_PTDIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTDIFE_PTDIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTDIFE_PTDIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTDIFE_PTDIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTDIFE_PTDIFE0:    .equ   %00000001
mPTDIFE_PTDIFE1:    .equ   %00000010
mPTDIFE_PTDIFE2:    .equ   %00000100
mPTDIFE_PTDIFE3:    .equ   %00001000
mPTDIFE_PTDIFE4:    .equ   %00010000
mPTDIFE_PTDIFE5:    .equ   %00100000
mPTDIFE_PTDIFE6:    .equ   %01000000
mPTDIFE_PTDIFE7:    .equ   %10000000


;*** PTEPE - Port E Pull Enable Register; 0xFFFF9850 ***
PTEPE:              .equ   $FFFF9850                                ;*** PTEPE - Port E Pull Enable Register; 0xFFFF9850 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPE_PTEPE0:       .equ   0                                         ; Internal Pull Enable for Port E Bit 0
PTEPE_PTEPE1:       .equ   1                                         ; Internal Pull Enable for Port E Bit 1
PTEPE_PTEPE2:       .equ   2                                         ; Internal Pull Enable for Port E Bit 2
PTEPE_PTEPE3:       .equ   3                                         ; Internal Pull Enable for Port E Bit 3
PTEPE_PTEPE4:       .equ   4                                         ; Internal Pull Enable for Port E Bit 4
PTEPE_PTEPE5:       .equ   5                                         ; Internal Pull Enable for Port E Bit 5
PTEPE_PTEPE6:       .equ   6                                         ; Internal Pull Enable for Port E Bit 6
PTEPE_PTEPE7:       .equ   7                                         ; Internal Pull Enable for Port E Bit 7
; bit position masks
mPTEPE_PTEPE0:      .equ   %00000001
mPTEPE_PTEPE1:      .equ   %00000010
mPTEPE_PTEPE2:      .equ   %00000100
mPTEPE_PTEPE3:      .equ   %00001000
mPTEPE_PTEPE4:      .equ   %00010000
mPTEPE_PTEPE5:      .equ   %00100000
mPTEPE_PTEPE6:      .equ   %01000000
mPTEPE_PTEPE7:      .equ   %10000000


;*** PTESE - Port E Slew Rate Enable Register; 0xFFFF9851 ***
PTESE:              .equ   $FFFF9851                                ;*** PTESE - Port E Slew Rate Enable Register; 0xFFFF9851 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTESE_PTESE0:       .equ   0                                         ; Output Slew Rate Enable for Port E Bit 0
PTESE_PTESE1:       .equ   1                                         ; Output Slew Rate Enable for Port E Bit 1
PTESE_PTESE2:       .equ   2                                         ; Output Slew Rate Enable for Port E Bit 2
PTESE_PTESE3:       .equ   3                                         ; Output Slew Rate Enable for Port E Bit 3
PTESE_PTESE4:       .equ   4                                         ; Output Slew Rate Enable for Port E Bit 4
PTESE_PTESE5:       .equ   5                                         ; Output Slew Rate Enable for Port E Bit 5
PTESE_PTESE6:       .equ   6                                         ; Output Slew Rate Enable for Port E Bit 6
PTESE_PTESE7:       .equ   7                                         ; Output Slew Rate Enable for Port E Bit 7
; bit position masks
mPTESE_PTESE0:      .equ   %00000001
mPTESE_PTESE1:      .equ   %00000010
mPTESE_PTESE2:      .equ   %00000100
mPTESE_PTESE3:      .equ   %00001000
mPTESE_PTESE4:      .equ   %00010000
mPTESE_PTESE5:      .equ   %00100000
mPTESE_PTESE6:      .equ   %01000000
mPTESE_PTESE7:      .equ   %10000000


;*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF9852 ***
PTEDS:              .equ   $FFFF9852                                ;*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF9852 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDS_PTEDS0:       .equ   0                                         ; Output Drive Strength Selection for Port E Bit 0
PTEDS_PTEDS1:       .equ   1                                         ; Output Drive Strength Selection for Port E Bit 1
PTEDS_PTEDS2:       .equ   2                                         ; Output Drive Strength Selection for Port E Bit 2
PTEDS_PTEDS3:       .equ   3                                         ; Output Drive Strength Selection for Port E Bit 3
PTEDS_PTEDS4:       .equ   4                                         ; Output Drive Strength Selection for Port E Bit 4
PTEDS_PTEDS5:       .equ   5                                         ; Output Drive Strength Selection for Port E Bit 5
PTEDS_PTEDS6:       .equ   6                                         ; Output Drive Strength Selection for Port E Bit 6
PTEDS_PTEDS7:       .equ   7                                         ; Output Drive Strength Selection for Port E Bit 7
; bit position masks
mPTEDS_PTEDS0:      .equ   %00000001
mPTEDS_PTEDS1:      .equ   %00000010
mPTEDS_PTEDS2:      .equ   %00000100
mPTEDS_PTEDS3:      .equ   %00001000
mPTEDS_PTEDS4:      .equ   %00010000
mPTEDS_PTEDS5:      .equ   %00100000
mPTEDS_PTEDS6:      .equ   %01000000
mPTEDS_PTEDS7:      .equ   %10000000


;*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF9853 ***
PTEIFE:             .equ   $FFFF9853                                ;*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF9853 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEIFE_PTEIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTEIFE_PTEIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTEIFE_PTEIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTEIFE_PTEIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTEIFE_PTEIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTEIFE_PTEIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTEIFE_PTEIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTEIFE_PTEIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTEIFE_PTEIFE0:    .equ   %00000001
mPTEIFE_PTEIFE1:    .equ   %00000010
mPTEIFE_PTEIFE2:    .equ   %00000100
mPTEIFE_PTEIFE3:    .equ   %00001000
mPTEIFE_PTEIFE4:    .equ   %00010000
mPTEIFE_PTEIFE5:    .equ   %00100000
mPTEIFE_PTEIFE6:    .equ   %01000000
mPTEIFE_PTEIFE7:    .equ   %10000000


;*** PTFPE - Port F Pull Enable Register; 0xFFFF9854 ***
PTFPE:              .equ   $FFFF9854                                ;*** PTFPE - Port F Pull Enable Register; 0xFFFF9854 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPE_PTFPE0:       .equ   0                                         ; Internal Pull Enable for Port F Bit 0
PTFPE_PTFPE1:       .equ   1                                         ; Internal Pull Enable for Port F Bit 1
PTFPE_PTFPE2:       .equ   2                                         ; Internal Pull Enable for Port F Bit 2
PTFPE_PTFPE3:       .equ   3                                         ; Internal Pull Enable for Port F Bit 3
PTFPE_PTFPE4:       .equ   4                                         ; Internal Pull Enable for Port F Bit 4
PTFPE_PTFPE5:       .equ   5                                         ; Internal Pull Enable for Port F Bit 5
PTFPE_PTFPE6:       .equ   6                                         ; Internal Pull Enable for Port F Bit 6
PTFPE_PTFPE7:       .equ   7                                         ; Internal Pull Enable for Port F Bit 7
; bit position masks
mPTFPE_PTFPE0:      .equ   %00000001
mPTFPE_PTFPE1:      .equ   %00000010
mPTFPE_PTFPE2:      .equ   %00000100
mPTFPE_PTFPE3:      .equ   %00001000
mPTFPE_PTFPE4:      .equ   %00010000
mPTFPE_PTFPE5:      .equ   %00100000
mPTFPE_PTFPE6:      .equ   %01000000
mPTFPE_PTFPE7:      .equ   %10000000


;*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF9855 ***
PTFSE:              .equ   $FFFF9855                                ;*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF9855 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSE_PTFSE0:       .equ   0                                         ; Output Slew Rate Enable for Port F Bit 0
PTFSE_PTFSE1:       .equ   1                                         ; Output Slew Rate Enable for Port F Bit 1
PTFSE_PTFSE2:       .equ   2                                         ; Output Slew Rate Enable for Port F Bit 2
PTFSE_PTFSE3:       .equ   3                                         ; Output Slew Rate Enable for Port F Bit 3
PTFSE_PTFSE4:       .equ   4                                         ; Output Slew Rate Enable for Port F Bit 4
PTFSE_PTFSE5:       .equ   5                                         ; Output Slew Rate Enable for Port F Bit 5
PTFSE_PTFSE6:       .equ   6                                         ; Output Slew Rate Enable for Port F Bit 6
PTFSE_PTFSE7:       .equ   7                                         ; Output Slew Rate Enable for Port F Bit 7
; bit position masks
mPTFSE_PTFSE0:      .equ   %00000001
mPTFSE_PTFSE1:      .equ   %00000010
mPTFSE_PTFSE2:      .equ   %00000100
mPTFSE_PTFSE3:      .equ   %00001000
mPTFSE_PTFSE4:      .equ   %00010000
mPTFSE_PTFSE5:      .equ   %00100000
mPTFSE_PTFSE6:      .equ   %01000000
mPTFSE_PTFSE7:      .equ   %10000000


;*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF9856 ***
PTFDS:              .equ   $FFFF9856                                ;*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF9856 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDS_PTFDS0:       .equ   0                                         ; Output Drive Strength Selection for Port F Bit 0
PTFDS_PTFDS1:       .equ   1                                         ; Output Drive Strength Selection for Port F Bit 1
PTFDS_PTFDS2:       .equ   2                                         ; Output Drive Strength Selection for Port F Bit 2
PTFDS_PTFDS3:       .equ   3                                         ; Output Drive Strength Selection for Port F Bit 3
PTFDS_PTFDS4:       .equ   4                                         ; Output Drive Strength Selection for Port F Bit 4
PTFDS_PTFDS5:       .equ   5                                         ; Output Drive Strength Selection for Port F Bit 5
PTFDS_PTFDS6:       .equ   6                                         ; Output Drive Strength Selection for Port F Bit 6
PTFDS_PTFDS7:       .equ   7                                         ; Output Drive Strength Selection for Port F Bit 7
; bit position masks
mPTFDS_PTFDS0:      .equ   %00000001
mPTFDS_PTFDS1:      .equ   %00000010
mPTFDS_PTFDS2:      .equ   %00000100
mPTFDS_PTFDS3:      .equ   %00001000
mPTFDS_PTFDS4:      .equ   %00010000
mPTFDS_PTFDS5:      .equ   %00100000
mPTFDS_PTFDS6:      .equ   %01000000
mPTFDS_PTFDS7:      .equ   %10000000


;*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF9857 ***
PTFIFE:             .equ   $FFFF9857                                ;*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF9857 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFIFE_PTFIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTFIFE_PTFIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTFIFE_PTFIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTFIFE_PTFIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTFIFE_PTFIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTFIFE_PTFIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTFIFE_PTFIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTFIFE_PTFIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTFIFE_PTFIFE0:    .equ   %00000001
mPTFIFE_PTFIFE1:    .equ   %00000010
mPTFIFE_PTFIFE2:    .equ   %00000100
mPTFIFE_PTFIFE3:    .equ   %00001000
mPTFIFE_PTFIFE4:    .equ   %00010000
mPTFIFE_PTFIFE5:    .equ   %00100000
mPTFIFE_PTFIFE6:    .equ   %01000000
mPTFIFE_PTFIFE7:    .equ   %10000000


;*** PTGPE - Port G Pull Enable Register; 0xFFFF9858 ***
PTGPE:              .equ   $FFFF9858                                ;*** PTGPE - Port G Pull Enable Register; 0xFFFF9858 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPE_PTGPE0:       .equ   0                                         ; Internal Pull Enable for Port G Bit 0
PTGPE_PTGPE1:       .equ   1                                         ; Internal Pull Enable for Port G Bit 1
PTGPE_PTGPE2:       .equ   2                                         ; Internal Pull Enable for Port G Bit 2
PTGPE_PTGPE3:       .equ   3                                         ; Internal Pull Enable for Port G Bit 3
PTGPE_PTGPE4:       .equ   4                                         ; Internal Pull Enable for Port G Bit 4
PTGPE_PTGPE5:       .equ   5                                         ; Internal Pull Enable for Port G Bit 5
PTGPE_PTGPE6:       .equ   6                                         ; Internal Pull Enable for Port G Bit 6
PTGPE_PTGPE7:       .equ   7                                         ; Internal Pull Enable for Port G Bit 7
; bit position masks
mPTGPE_PTGPE0:      .equ   %00000001
mPTGPE_PTGPE1:      .equ   %00000010
mPTGPE_PTGPE2:      .equ   %00000100
mPTGPE_PTGPE3:      .equ   %00001000
mPTGPE_PTGPE4:      .equ   %00010000
mPTGPE_PTGPE5:      .equ   %00100000
mPTGPE_PTGPE6:      .equ   %01000000
mPTGPE_PTGPE7:      .equ   %10000000


;*** PTGSE - Port G Slew Rate Enable Register; 0xFFFF9859 ***
PTGSE:              .equ   $FFFF9859                                ;*** PTGSE - Port G Slew Rate Enable Register; 0xFFFF9859 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGSE_PTGSE0:       .equ   0                                         ; Output Slew Rate Enable for Port G Bit 0
PTGSE_PTGSE1:       .equ   1                                         ; Output Slew Rate Enable for Port G Bit 1
PTGSE_PTGSE2:       .equ   2                                         ; Output Slew Rate Enable for Port G Bit 2
PTGSE_PTGSE3:       .equ   3                                         ; Output Slew Rate Enable for Port G Bit 3
PTGSE_PTGSE4:       .equ   4                                         ; Output Slew Rate Enable for Port G Bit 4
PTGSE_PTGSE5:       .equ   5                                         ; Output Slew Rate Enable for Port G Bit 5
PTGSE_PTGSE6:       .equ   6                                         ; Output Slew Rate Enable for Port G Bit 6
PTGSE_PTGSE7:       .equ   7                                         ; Output Slew Rate Enable for Port G Bit 7
; bit position masks
mPTGSE_PTGSE0:      .equ   %00000001
mPTGSE_PTGSE1:      .equ   %00000010
mPTGSE_PTGSE2:      .equ   %00000100
mPTGSE_PTGSE3:      .equ   %00001000
mPTGSE_PTGSE4:      .equ   %00010000
mPTGSE_PTGSE5:      .equ   %00100000
mPTGSE_PTGSE6:      .equ   %01000000
mPTGSE_PTGSE7:      .equ   %10000000


;*** PTGDS - Port G Drive Strength Selection Register; 0xFFFF985A ***
PTGDS:              .equ   $FFFF985A                                ;*** PTGDS - Port G Drive Strength Selection Register; 0xFFFF985A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDS_PTGDS0:       .equ   0                                         ; Output Drive Strength Selection for Port G Bit 0
PTGDS_PTGDS1:       .equ   1                                         ; Output Drive Strength Selection for Port G Bit 1
PTGDS_PTGDS2:       .equ   2                                         ; Output Drive Strength Selection for Port G Bit 2
PTGDS_PTGDS3:       .equ   3                                         ; Output Drive Strength Selection for Port G Bit 3
PTGDS_PTGDS4:       .equ   4                                         ; Output Drive Strength Selection for Port G Bit 4
PTGDS_PTGDS5:       .equ   5                                         ; Output Drive Strength Selection for Port G Bit 5
PTGDS_PTGDS6:       .equ   6                                         ; Output Drive Strength Selection for Port G Bit 6
PTGDS_PTGDS7:       .equ   7                                         ; Output Drive Strength Selection for Port G Bit 7
; bit position masks
mPTGDS_PTGDS0:      .equ   %00000001
mPTGDS_PTGDS1:      .equ   %00000010
mPTGDS_PTGDS2:      .equ   %00000100
mPTGDS_PTGDS3:      .equ   %00001000
mPTGDS_PTGDS4:      .equ   %00010000
mPTGDS_PTGDS5:      .equ   %00100000
mPTGDS_PTGDS6:      .equ   %01000000
mPTGDS_PTGDS7:      .equ   %10000000


;*** PTGIFE - Port G Input Filter Enable Register; 0xFFFF985B ***
PTGIFE:             .equ   $FFFF985B                                ;*** PTGIFE - Port G Input Filter Enable Register; 0xFFFF985B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGIFE_PTGIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTGIFE_PTGIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTGIFE_PTGIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTGIFE_PTGIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTGIFE_PTGIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTGIFE_PTGIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTGIFE_PTGIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTGIFE_PTGIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTGIFE_PTGIFE0:    .equ   %00000001
mPTGIFE_PTGIFE1:    .equ   %00000010
mPTGIFE_PTGIFE2:    .equ   %00000100
mPTGIFE_PTGIFE3:    .equ   %00001000
mPTGIFE_PTGIFE4:    .equ   %00010000
mPTGIFE_PTGIFE5:    .equ   %00100000
mPTGIFE_PTGIFE6:    .equ   %01000000
mPTGIFE_PTGIFE7:    .equ   %10000000


;*** PTHPE - Port H Pull Enable Register; 0xFFFF985C ***
PTHPE:              .equ   $FFFF985C                                ;*** PTHPE - Port H Pull Enable Register; 0xFFFF985C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHPE_PTHPE0:       .equ   0                                         ; Internal Pull Enable for Port H Bit 0
PTHPE_PTHPE1:       .equ   1                                         ; Internal Pull Enable for Port H Bit 1
PTHPE_PTHPE2:       .equ   2                                         ; Internal Pull Enable for Port H Bit 2
PTHPE_PTHPE3:       .equ   3                                         ; Internal Pull Enable for Port H Bit 3
PTHPE_PTHPE4:       .equ   4                                         ; Internal Pull Enable for Port H Bit 4
; bit position masks
mPTHPE_PTHPE0:      .equ   %00000001
mPTHPE_PTHPE1:      .equ   %00000010
mPTHPE_PTHPE2:      .equ   %00000100
mPTHPE_PTHPE3:      .equ   %00001000
mPTHPE_PTHPE4:      .equ   %00010000


;*** PTHSE - Port H Slew Rate Enable Register; 0xFFFF985D ***
PTHSE:              .equ   $FFFF985D                                ;*** PTHSE - Port H Slew Rate Enable Register; 0xFFFF985D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHSE_PTHSE0:       .equ   0                                         ; Output Slew Rate Enable for Port H Bit 0
PTHSE_PTHSE1:       .equ   1                                         ; Output Slew Rate Enable for Port H Bit 1
PTHSE_PTHSE2:       .equ   2                                         ; Output Slew Rate Enable for Port H Bit 2
PTHSE_PTHSE3:       .equ   3                                         ; Output Slew Rate Enable for Port H Bit 3
PTHSE_PTHSE4:       .equ   4                                         ; Output Slew Rate Enable for Port H Bit 4
; bit position masks
mPTHSE_PTHSE0:      .equ   %00000001
mPTHSE_PTHSE1:      .equ   %00000010
mPTHSE_PTHSE2:      .equ   %00000100
mPTHSE_PTHSE3:      .equ   %00001000
mPTHSE_PTHSE4:      .equ   %00010000


;*** PTHDS - Port H Drive Strength Selection Register; 0xFFFF985E ***
PTHDS:              .equ   $FFFF985E                                ;*** PTHDS - Port H Drive Strength Selection Register; 0xFFFF985E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDS_PTHDS0:       .equ   0                                         ; Output Drive Strength Selection for Port H Bit 0
PTHDS_PTHDS1:       .equ   1                                         ; Output Drive Strength Selection for Port H Bit 1
PTHDS_PTHDS2:       .equ   2                                         ; Output Drive Strength Selection for Port H Bit 2
PTHDS_PTHDS3:       .equ   3                                         ; Output Drive Strength Selection for Port H Bit 3
PTHDS_PTHDS4:       .equ   4                                         ; Output Drive Strength Selection for Port H Bit 4
; bit position masks
mPTHDS_PTHDS0:      .equ   %00000001
mPTHDS_PTHDS1:      .equ   %00000010
mPTHDS_PTHDS2:      .equ   %00000100
mPTHDS_PTHDS3:      .equ   %00001000
mPTHDS_PTHDS4:      .equ   %00010000


;*** PTHIFE - Port H Input Filter Enable Register; 0xFFFF985F ***
PTHIFE:             .equ   $FFFF985F                                ;*** PTHIFE - Port H Input Filter Enable Register; 0xFFFF985F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHIFE_PTHIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTHIFE_PTHIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTHIFE_PTHIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTHIFE_PTHIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTHIFE_PTHIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
; bit position masks
mPTHIFE_PTHIFE0:    .equ   %00000001
mPTHIFE_PTHIFE1:    .equ   %00000010
mPTHIFE_PTHIFE2:    .equ   %00000100
mPTHIFE_PTHIFE3:    .equ   %00001000
mPTHIFE_PTHIFE4:    .equ   %00010000


;*** PTJPE - Port J Pull Enable Register; 0xFFFF9860 ***
PTJPE:              .equ   $FFFF9860                                ;*** PTJPE - Port J Pull Enable Register; 0xFFFF9860 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJPE_PTJPE0:       .equ   0                                         ; Internal Pull Enable for Port J Bit 0
PTJPE_PTJPE1:       .equ   1                                         ; Internal Pull Enable for Port J Bit 1
PTJPE_PTJPE2:       .equ   2                                         ; Internal Pull Enable for Port J Bit 2
PTJPE_PTJPE3:       .equ   3                                         ; Internal Pull Enable for Port J Bit 3
PTJPE_PTJPE4:       .equ   4                                         ; Internal Pull Enable for Port J Bit 4
; bit position masks
mPTJPE_PTJPE0:      .equ   %00000001
mPTJPE_PTJPE1:      .equ   %00000010
mPTJPE_PTJPE2:      .equ   %00000100
mPTJPE_PTJPE3:      .equ   %00001000
mPTJPE_PTJPE4:      .equ   %00010000


;*** PTJSE - Port J Slew Rate Enable Register; 0xFFFF9861 ***
PTJSE:              .equ   $FFFF9861                                ;*** PTJSE - Port J Slew Rate Enable Register; 0xFFFF9861 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJSE_PTJSE0:       .equ   0                                         ; Output Slew Rate Enable for Port J Bit 0
PTJSE_PTJSE1:       .equ   1                                         ; Output Slew Rate Enable for Port J Bit 1
PTJSE_PTJSE2:       .equ   2                                         ; Output Slew Rate Enable for Port J Bit 2
PTJSE_PTJSE3:       .equ   3                                         ; Output Slew Rate Enable for Port J Bit 3
PTJSE_PTJSE4:       .equ   4                                         ; Output Slew Rate Enable for Port J Bit 4
; bit position masks
mPTJSE_PTJSE0:      .equ   %00000001
mPTJSE_PTJSE1:      .equ   %00000010
mPTJSE_PTJSE2:      .equ   %00000100
mPTJSE_PTJSE3:      .equ   %00001000
mPTJSE_PTJSE4:      .equ   %00010000


;*** PTJDS - Port J Drive Strength Selection Register; 0xFFFF9862 ***
PTJDS:              .equ   $FFFF9862                                ;*** PTJDS - Port J Drive Strength Selection Register; 0xFFFF9862 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJDS_PTJDS0:       .equ   0                                         ; Output Drive Strength Selection for Port J Bit 0
PTJDS_PTJDS1:       .equ   1                                         ; Output Drive Strength Selection for Port J Bit 1
PTJDS_PTJDS2:       .equ   2                                         ; Output Drive Strength Selection for Port J Bit 2
PTJDS_PTJDS3:       .equ   3                                         ; Output Drive Strength Selection for Port J Bit 3
PTJDS_PTJDS4:       .equ   4                                         ; Output Drive Strength Selection for Port J Bit 4
; bit position masks
mPTJDS_PTJDS0:      .equ   %00000001
mPTJDS_PTJDS1:      .equ   %00000010
mPTJDS_PTJDS2:      .equ   %00000100
mPTJDS_PTJDS3:      .equ   %00001000
mPTJDS_PTJDS4:      .equ   %00010000


;*** PTJIFE - Port J Input Filter Enable Register; 0xFFFF9863 ***
PTJIFE:             .equ   $FFFF9863                                ;*** PTJIFE - Port J Input Filter Enable Register; 0xFFFF9863 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJIFE_PTJIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTJIFE_PTJIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTJIFE_PTJIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTJIFE_PTJIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTJIFE_PTJIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
; bit position masks
mPTJIFE_PTJIFE0:    .equ   %00000001
mPTJIFE_PTJIFE1:    .equ   %00000010
mPTJIFE_PTJIFE2:    .equ   %00000100
mPTJIFE_PTJIFE3:    .equ   %00001000
mPTJIFE_PTJIFE4:    .equ   %00010000


;*** CMTCG1 - Carrier Generator Data Register 1; 0xFFFF9868 ***
CMTCG1:             .equ   $FFFF9868                                ;*** CMTCG1 - Carrier Generator Data Register 1; 0xFFFF9868 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCG1_PL0:         .equ   0                                         ; Primary Carrier Low Time Data Value Bit 0
CMTCG1_PL1:         .equ   1                                         ; Primary Carrier Low Time Data Value Bit 1
CMTCG1_PL2:         .equ   2                                         ; Primary Carrier Low Time Data Value Bit 2
CMTCG1_PL3:         .equ   3                                         ; Primary Carrier Low Time Data Value Bit 3
CMTCG1_PL4:         .equ   4                                         ; Primary Carrier Low Time Data Value Bit 4
CMTCG1_PL5:         .equ   5                                         ; Primary Carrier Low Time Data Value Bit 5
CMTCG1_PL6:         .equ   6                                         ; Primary Carrier Low Time Data Value Bit 6
CMTCG1_PL7:         .equ   7                                         ; Primary Carrier Low Time Data Value Bit 0
CMTCG1_PH0:         .equ   8                                         ; Primary Carrier High Time Data Value Bit 0
CMTCG1_PH1:         .equ   9                                         ; Primary Carrier High Time Data Value Bit 1
CMTCG1_PH2:         .equ   10                                        ; Primary Carrier High Time Data Value Bit 2
CMTCG1_PH3:         .equ   11                                        ; Primary Carrier High Time Data Value Bit 3
CMTCG1_PH4:         .equ   12                                        ; Primary Carrier High Time Data Value Bit 4
CMTCG1_PH5:         .equ   13                                        ; Primary Carrier High Time Data Value Bit 5
CMTCG1_PH6:         .equ   14                                        ; Primary Carrier High Time Data Value Bit 6
CMTCG1_PH7:         .equ   15                                        ; Primary Carrier High Time Data Value Bit 7
; bit position masks
mCMTCG1_PL0:        .equ   %00000001
mCMTCG1_PL1:        .equ   %00000010
mCMTCG1_PL2:        .equ   %00000100
mCMTCG1_PL3:        .equ   %00001000
mCMTCG1_PL4:        .equ   %00010000
mCMTCG1_PL5:        .equ   %00100000
mCMTCG1_PL6:        .equ   %01000000
mCMTCG1_PL7:        .equ   %10000000
mCMTCG1_PH0:        .equ   %100000000
mCMTCG1_PH1:        .equ   %1000000000
mCMTCG1_PH2:        .equ   %10000000000
mCMTCG1_PH3:        .equ   %100000000000
mCMTCG1_PH4:        .equ   %1000000000000
mCMTCG1_PH5:        .equ   %10000000000000
mCMTCG1_PH6:        .equ   %100000000000000
mCMTCG1_PH7:        .equ   %1000000000000000


;*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte; 0xFFFF9868 ***
CMTCGH1:            .equ   $FFFF9868                                ;*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte; 0xFFFF9868 ***


;*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte; 0xFFFF9869 ***
CMTCGL1:            .equ   $FFFF9869                                ;*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte; 0xFFFF9869 ***


;*** CMTCG2 - Carrier Generator Data Register 2; 0xFFFF986A ***
CMTCG2:             .equ   $FFFF986A                                ;*** CMTCG2 - Carrier Generator Data Register 2; 0xFFFF986A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCG2_SL0:         .equ   0                                         ; Secondary Carrier Low Time Data Value Bit 0
CMTCG2_SL1:         .equ   1                                         ; Secondary Carrier Low Time Data Value Bit 1
CMTCG2_SL2:         .equ   2                                         ; Secondary Carrier Low Time Data Value Bit 2
CMTCG2_SL3:         .equ   3                                         ; Secondary Carrier Low Time Data Value Bit 3
CMTCG2_SL4:         .equ   4                                         ; Secondary Carrier Low Time Data Value Bit 4
CMTCG2_SL5:         .equ   5                                         ; Secondary Carrier Low Time Data Value Bit 5
CMTCG2_SL6:         .equ   6                                         ; Secondary Carrier Low Time Data Value Bit 6
CMTCG2_SL7:         .equ   7                                         ; Secondary Carrier Low Time Data Value Bit 7
CMTCG2_SH0:         .equ   8                                         ; Secondary Carrier High Time Data Value Bit 0
CMTCG2_SH1:         .equ   9                                         ; Secondary Carrier High Time Data Value Bit 1
CMTCG2_SH2:         .equ   10                                        ; Secondary Carrier High Time Data Value Bit 2
CMTCG2_SH3:         .equ   11                                        ; Secondary Carrier High Time Data Value Bit 3
CMTCG2_SH4:         .equ   12                                        ; Secondary Carrier High Time Data Value Bit 4
CMTCG2_SH5:         .equ   13                                        ; Secondary Carrier High Time Data Value Bit 5
CMTCG2_SH6:         .equ   14                                        ; Secondary Carrier High Time Data Value Bit 6
CMTCG2_SH7:         .equ   15                                        ; Secondary Carrier High Time Data Value Bit 7
; bit position masks
mCMTCG2_SL0:        .equ   %00000001
mCMTCG2_SL1:        .equ   %00000010
mCMTCG2_SL2:        .equ   %00000100
mCMTCG2_SL3:        .equ   %00001000
mCMTCG2_SL4:        .equ   %00010000
mCMTCG2_SL5:        .equ   %00100000
mCMTCG2_SL6:        .equ   %01000000
mCMTCG2_SL7:        .equ   %10000000
mCMTCG2_SH0:        .equ   %100000000
mCMTCG2_SH1:        .equ   %1000000000
mCMTCG2_SH2:        .equ   %10000000000
mCMTCG2_SH3:        .equ   %100000000000
mCMTCG2_SH4:        .equ   %1000000000000
mCMTCG2_SH5:        .equ   %10000000000000
mCMTCG2_SH6:        .equ   %100000000000000
mCMTCG2_SH7:        .equ   %1000000000000000


;*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte; 0xFFFF986A ***
CMTCGH2:            .equ   $FFFF986A                                ;*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte; 0xFFFF986A ***


;*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte; 0xFFFF986B ***
CMTCGL2:            .equ   $FFFF986B                                ;*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte; 0xFFFF986B ***


;*** CMTOC - CMT Output Control Register; 0xFFFF986C ***
CMTOC:              .equ   $FFFF986C                                ;*** CMTOC - CMT Output Control Register; 0xFFFF986C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTOC_IROPEN:       .equ   5                                         ; IRO pin enable
CMTOC_CMTPOL:       .equ   6                                         ; CMT output polarity
CMTOC_IROL:         .equ   7                                         ; IRO latch control
; bit position masks
mCMTOC_IROPEN:      .equ   %00100000
mCMTOC_CMTPOL:      .equ   %01000000
mCMTOC_IROL:        .equ   %10000000


;*** CMTMSC - CMT Modulator Status and Control Register; 0xFFFF986D ***
CMTMSC:             .equ   $FFFF986D                                ;*** CMTMSC - CMT Modulator Status and Control Register; 0xFFFF986D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTMSC_MCGEN:       .equ   0                                         ; Modulator and Carrier Generator Enable
CMTMSC_EOCIE:       .equ   1                                         ; End of Cycle Interrupt Enable
CMTMSC_FSK:         .equ   2                                         ; FSK Mode Select
CMTMSC_BASE:        .equ   3                                         ; Baseband Mode Enable
CMTMSC_EXSPC:       .equ   4                                         ; Extended Space Enable
CMTMSC_CMTDIV0:     .equ   5                                         ; CMT Clock Divide Prescaler Bit 0
CMTMSC_CMTDIV1:     .equ   6                                         ; CMT Clock Divide Prescaler Bit 1
CMTMSC_EOCF:        .equ   7                                         ; End of Cycle Status Flag
; bit position masks
mCMTMSC_MCGEN:      .equ   %00000001
mCMTMSC_EOCIE:      .equ   %00000010
mCMTMSC_FSK:        .equ   %00000100
mCMTMSC_BASE:       .equ   %00001000
mCMTMSC_EXSPC:      .equ   %00010000
mCMTMSC_CMTDIV0:    .equ   %00100000
mCMTMSC_CMTDIV1:    .equ   %01000000
mCMTMSC_EOCF:       .equ   %10000000


;*** CMTCMD12 - CMT Modulator Data Register 12; 0xFFFF986E ***
CMTCMD12:           .equ   $FFFF986E                                ;*** CMTCMD12 - CMT Modulator Data Register 12; 0xFFFF986E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCMD12_MB0:       .equ   0                                         ; Data Value Bit 0
CMTCMD12_MB1:       .equ   1                                         ; Data Value Bit 1
CMTCMD12_MB2:       .equ   2                                         ; Data Value Bit 2
CMTCMD12_MB3:       .equ   3                                         ; Data Value Bit 3
CMTCMD12_MB4:       .equ   4                                         ; Data Value Bit 4
CMTCMD12_MB5:       .equ   5                                         ; Data Value Bit 5
CMTCMD12_MB6:       .equ   6                                         ; Data Value Bit 6
CMTCMD12_MB7:       .equ   7                                         ; Data Value Bit 7
CMTCMD12_MB8:       .equ   8                                         ; Data Value Bit 8
CMTCMD12_MB9:       .equ   9                                         ; Data Value Bit 9
CMTCMD12_MB10:      .equ   10                                        ; Data Value Bit 10
CMTCMD12_MB11:      .equ   11                                        ; Data Value Bit 11
CMTCMD12_MB12:      .equ   12                                        ; Data Value Bit 12
CMTCMD12_MB13:      .equ   13                                        ; Data Value Bit 13
CMTCMD12_MB14:      .equ   14                                        ; Data Value Bit 14
CMTCMD12_MB15:      .equ   15                                        ; Data Value Bit 15
; bit position masks
mCMTCMD12_MB0:      .equ   %00000001
mCMTCMD12_MB1:      .equ   %00000010
mCMTCMD12_MB2:      .equ   %00000100
mCMTCMD12_MB3:      .equ   %00001000
mCMTCMD12_MB4:      .equ   %00010000
mCMTCMD12_MB5:      .equ   %00100000
mCMTCMD12_MB6:      .equ   %01000000
mCMTCMD12_MB7:      .equ   %10000000
mCMTCMD12_MB8:      .equ   %100000000
mCMTCMD12_MB9:      .equ   %1000000000
mCMTCMD12_MB10:     .equ   %10000000000
mCMTCMD12_MB11:     .equ   %100000000000
mCMTCMD12_MB12:     .equ   %1000000000000
mCMTCMD12_MB13:     .equ   %10000000000000
mCMTCMD12_MB14:     .equ   %100000000000000
mCMTCMD12_MB15:     .equ   %1000000000000000


;*** CMTCMD1 - CMT Modulator Data Register 1; 0xFFFF986E ***
CMTCMD1:            .equ   $FFFF986E                                ;*** CMTCMD1 - CMT Modulator Data Register 1; 0xFFFF986E ***


;*** CMTCMD2 - CMT Modulator Data Register 2; 0xFFFF986F ***
CMTCMD2:            .equ   $FFFF986F                                ;*** CMTCMD2 - CMT Modulator Data Register 2; 0xFFFF986F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCMD2_MB0:        .equ   0                                         ; Data Value Bit 0
CMTCMD2_MB1:        .equ   1                                         ; Data Value Bit 1
CMTCMD2_MB2:        .equ   2                                         ; Data Value Bit 2
CMTCMD2_MB3:        .equ   3                                         ; Data Value Bit 3
CMTCMD2_MB4:        .equ   4                                         ; Data Value Bit 4
CMTCMD2_MB5:        .equ   5                                         ; Data Value Bit 5
CMTCMD2_MB6:        .equ   6                                         ; Data Value Bit 6
CMTCMD2_MB7:        .equ   7                                         ; Data Value Bit 7
; bit position masks
mCMTCMD2_MB0:       .equ   %00000001
mCMTCMD2_MB1:       .equ   %00000010
mCMTCMD2_MB2:       .equ   %00000100
mCMTCMD2_MB3:       .equ   %00001000
mCMTCMD2_MB4:       .equ   %00010000
mCMTCMD2_MB5:       .equ   %00100000
mCMTCMD2_MB6:       .equ   %01000000
mCMTCMD2_MB7:       .equ   %10000000


;*** CMTCMD34 - CMT Modulator Data Register 34; 0xFFFF9870 ***
CMTCMD34:           .equ   $FFFF9870                                ;*** CMTCMD34 - CMT Modulator Data Register 34; 0xFFFF9870 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCMD34_SB0:       .equ   0                                         ; Data Value Bit 0
CMTCMD34_SB1:       .equ   1                                         ; Data Value Bit 1
CMTCMD34_SB2:       .equ   2                                         ; Data Value Bit 2
CMTCMD34_SB3:       .equ   3                                         ; Data Value Bit 3
CMTCMD34_SB4:       .equ   4                                         ; Data Value Bit 4
CMTCMD34_SB5:       .equ   5                                         ; Data Value Bit 5
CMTCMD34_SB6:       .equ   6                                         ; Data Value Bit 6
CMTCMD34_SB7:       .equ   7                                         ; Data Value Bit 7
CMTCMD34_SB8:       .equ   8                                         ; Data Value Bit 8
CMTCMD34_SB9:       .equ   9                                         ; Data Value Bit 9
CMTCMD34_SB10:      .equ   10                                        ; Data Value Bit 10
CMTCMD34_SB11:      .equ   11                                        ; Data Value Bit 11
CMTCMD34_SB12:      .equ   12                                        ; Data Value Bit 12
CMTCMD34_SB13:      .equ   13                                        ; Data Value Bit 13
CMTCMD34_SB14:      .equ   14                                        ; Data Value Bit 14
CMTCMD34_SB15:      .equ   15                                        ; Data Value Bit 15
; bit position masks
mCMTCMD34_SB0:      .equ   %00000001
mCMTCMD34_SB1:      .equ   %00000010
mCMTCMD34_SB2:      .equ   %00000100
mCMTCMD34_SB3:      .equ   %00001000
mCMTCMD34_SB4:      .equ   %00010000
mCMTCMD34_SB5:      .equ   %00100000
mCMTCMD34_SB6:      .equ   %01000000
mCMTCMD34_SB7:      .equ   %10000000
mCMTCMD34_SB8:      .equ   %100000000
mCMTCMD34_SB9:      .equ   %1000000000
mCMTCMD34_SB10:     .equ   %10000000000
mCMTCMD34_SB11:     .equ   %100000000000
mCMTCMD34_SB12:     .equ   %1000000000000
mCMTCMD34_SB13:     .equ   %10000000000000
mCMTCMD34_SB14:     .equ   %100000000000000
mCMTCMD34_SB15:     .equ   %1000000000000000


;*** CMTCMD3 - CMT Modulator Data Register 3; 0xFFFF9870 ***
CMTCMD3:            .equ   $FFFF9870                                ;*** CMTCMD3 - CMT Modulator Data Register 3; 0xFFFF9870 ***


;*** CMTCMD4 - CMT Modulator Data Register 4; 0xFFFF9871 ***
CMTCMD4:            .equ   $FFFF9871                                ;*** CMTCMD4 - CMT Modulator Data Register 4; 0xFFFF9871 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCMD4_SB0:        .equ   0                                         ; Data Value Bit 0
CMTCMD4_SB1:        .equ   1                                         ; Data Value Bit 1
CMTCMD4_SB2:        .equ   2                                         ; Data Value Bit 2
CMTCMD4_SB3:        .equ   3                                         ; Data Value Bit 3
CMTCMD4_SB4:        .equ   4                                         ; Data Value Bit 4
CMTCMD4_SB5:        .equ   5                                         ; Data Value Bit 5
CMTCMD4_SB6:        .equ   6                                         ; Data Value Bit 6
CMTCMD4_SB7:        .equ   7                                         ; Data Value Bit 7
; bit position masks
mCMTCMD4_SB0:       .equ   %00000001
mCMTCMD4_SB1:       .equ   %00000010
mCMTCMD4_SB2:       .equ   %00000100
mCMTCMD4_SB3:       .equ   %00001000
mCMTCMD4_SB4:       .equ   %00010000
mCMTCMD4_SB5:       .equ   %00100000
mCMTCMD4_SB6:       .equ   %01000000
mCMTCMD4_SB7:       .equ   %10000000


;*** PTHD - Port H Data Register; 0xFFFF9874 ***
PTHD:               .equ   $FFFF9874                                ;*** PTHD - Port H Data Register; 0xFFFF9874 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHD_PTHD0:         .equ   0                                         ; Port H Data Register Bit 0
PTHD_PTHD1:         .equ   1                                         ; Port H Data Register Bit 1
PTHD_PTHD2:         .equ   2                                         ; Port H Data Register Bit 2
PTHD_PTHD3:         .equ   3                                         ; Port H Data Register Bit 3
PTHD_PTHD4:         .equ   4                                         ; Port H Data Register Bit 4
; bit position masks
mPTHD_PTHD0:        .equ   %00000001
mPTHD_PTHD1:        .equ   %00000010
mPTHD_PTHD2:        .equ   %00000100
mPTHD_PTHD3:        .equ   %00001000
mPTHD_PTHD4:        .equ   %00010000


;*** PTHDD - Port H Data Direction Register; 0xFFFF9875 ***
PTHDD:              .equ   $FFFF9875                                ;*** PTHDD - Port H Data Direction Register; 0xFFFF9875 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDD_PTHDD0:       .equ   0                                         ; Data Direction for Port H Bit 0
PTHDD_PTHDD1:       .equ   1                                         ; Data Direction for Port H Bit 1
PTHDD_PTHDD2:       .equ   2                                         ; Data Direction for Port H Bit 2
PTHDD_PTHDD3:       .equ   3                                         ; Data Direction for Port H Bit 3
PTHDD_PTHDD4:       .equ   4                                         ; Data Direction for Port H Bit 4
; bit position masks
mPTHDD_PTHDD0:      .equ   %00000001
mPTHDD_PTHDD1:      .equ   %00000010
mPTHDD_PTHDD2:      .equ   %00000100
mPTHDD_PTHDD3:      .equ   %00001000
mPTHDD_PTHDD4:      .equ   %00010000


;*** PTJD - Port J Data Register; 0xFFFF9876 ***
PTJD:               .equ   $FFFF9876                                ;*** PTJD - Port J Data Register; 0xFFFF9876 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJD_PTJD0:         .equ   0                                         ; Port J Data Register Bit 0
PTJD_PTJD1:         .equ   1                                         ; Port J Data Register Bit 1
PTJD_PTJD2:         .equ   2                                         ; Port J Data Register Bit 2
PTJD_PTJD3:         .equ   3                                         ; Port J Data Register Bit 3
PTJD_PTJD4:         .equ   4                                         ; Port J Data Register Bit 4
; bit position masks
mPTJD_PTJD0:        .equ   %00000001
mPTJD_PTJD1:        .equ   %00000010
mPTJD_PTJD2:        .equ   %00000100
mPTJD_PTJD3:        .equ   %00001000
mPTJD_PTJD4:        .equ   %00010000


;*** PTJDD - Port J Data Direction Register; 0xFFFF9877 ***
PTJDD:              .equ   $FFFF9877                                ;*** PTJDD - Port J Data Direction Register; 0xFFFF9877 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJDD_PTJDD0:       .equ   0                                         ; Data Direction for Port J Bit 0
PTJDD_PTJDD1:       .equ   1                                         ; Data Direction for Port J Bit 1
PTJDD_PTJDD2:       .equ   2                                         ; Data Direction for Port J Bit 2
PTJDD_PTJDD3:       .equ   3                                         ; Data Direction for Port J Bit 3
PTJDD_PTJDD4:       .equ   4                                         ; Data Direction for Port J Bit 4
; bit position masks
mPTJDD_PTJDD0:      .equ   %00000001
mPTJDD_PTJDD1:      .equ   %00000010
mPTJDD_PTJDD2:      .equ   %00000100
mPTJDD_PTJDD3:      .equ   %00001000
mPTJDD_PTJDD4:      .equ   %00010000


;*** CANCTL0 - MSCAN Control 0 Register; 0xFFFF9880 ***
CANCTL0:            .equ   $FFFF9880                                ;*** CANCTL0 - MSCAN Control 0 Register; 0xFFFF9880 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANCTL0_INITRQ:     .equ   0                                         ; Initialization Mode Request
CANCTL0_SLPRQ:      .equ   1                                         ; Sleep Mode Request
CANCTL0_WUPE:       .equ   2                                         ; Wake-Up Enable
CANCTL0_TIME:       .equ   3                                         ; Timer Enable
CANCTL0_SYNCH:      .equ   4                                         ; Synchronized Status
CANCTL0_CSWAI:      .equ   5                                         ; CAN Stops in Wait Mode
CANCTL0_RXACT:      .equ   6                                         ; Receiver Active Status
CANCTL0_RXFRM:      .equ   7                                         ; Received Frame Flag
; bit position masks
mCANCTL0_INITRQ:    .equ   %00000001
mCANCTL0_SLPRQ:     .equ   %00000010
mCANCTL0_WUPE:      .equ   %00000100
mCANCTL0_TIME:      .equ   %00001000
mCANCTL0_SYNCH:     .equ   %00010000
mCANCTL0_CSWAI:     .equ   %00100000
mCANCTL0_RXACT:     .equ   %01000000
mCANCTL0_RXFRM:     .equ   %10000000


;*** CANCTL1 - MSCAN Control 1 Register; 0xFFFF9881 ***
CANCTL1:            .equ   $FFFF9881                                ;*** CANCTL1 - MSCAN Control 1 Register; 0xFFFF9881 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANCTL1_INITAK:     .equ   0                                         ; Initialization Mode Acknowledge
CANCTL1_SLPAK:      .equ   1                                         ; Sleep Mode Acknowledge
CANCTL1_WUPM:       .equ   2                                         ; Wake-Up Mode
CANCTL1_BORM:       .equ   3                                         ; Bus-Off Recovery Mode
CANCTL1_LISTEN:     .equ   4                                         ; Listen Only Mode
CANCTL1_LOOPB:      .equ   5                                         ; Loop Back Self Test Mode
CANCTL1_CLKSRC:     .equ   6                                         ; MSCAN Clock Source
CANCTL1_CANE:       .equ   7                                         ; MSCAN Enable
; bit position masks
mCANCTL1_INITAK:    .equ   %00000001
mCANCTL1_SLPAK:     .equ   %00000010
mCANCTL1_WUPM:      .equ   %00000100
mCANCTL1_BORM:      .equ   %00001000
mCANCTL1_LISTEN:    .equ   %00010000
mCANCTL1_LOOPB:     .equ   %00100000
mCANCTL1_CLKSRC:    .equ   %01000000
mCANCTL1_CANE:      .equ   %10000000


;*** CANBTR0 - MSCAN Bus Timing Register 0; 0xFFFF9882 ***
CANBTR0:            .equ   $FFFF9882                                ;*** CANBTR0 - MSCAN Bus Timing Register 0; 0xFFFF9882 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANBTR0_BRP0:       .equ   0                                         ; Baud Rate Prescaler 0
CANBTR0_BRP1:       .equ   1                                         ; Baud Rate Prescaler 1
CANBTR0_BRP2:       .equ   2                                         ; Baud Rate Prescaler 2
CANBTR0_BRP3:       .equ   3                                         ; Baud Rate Prescaler 3
CANBTR0_BRP4:       .equ   4                                         ; Baud Rate Prescaler 4
CANBTR0_BRP5:       .equ   5                                         ; Baud Rate Prescaler 5
CANBTR0_SJW0:       .equ   6                                         ; Synchronization Jump Width 0
CANBTR0_SJW1:       .equ   7                                         ; Synchronization Jump Width 1
; bit position masks
mCANBTR0_BRP0:      .equ   %00000001
mCANBTR0_BRP1:      .equ   %00000010
mCANBTR0_BRP2:      .equ   %00000100
mCANBTR0_BRP3:      .equ   %00001000
mCANBTR0_BRP4:      .equ   %00010000
mCANBTR0_BRP5:      .equ   %00100000
mCANBTR0_SJW0:      .equ   %01000000
mCANBTR0_SJW1:      .equ   %10000000


;*** CANBTR1 - MSCAN Bus Timing Register 1; 0xFFFF9883 ***
CANBTR1:            .equ   $FFFF9883                                ;*** CANBTR1 - MSCAN Bus Timing Register 1; 0xFFFF9883 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANBTR1_TSEG10:     .equ   0                                         ; Time Segment 10
CANBTR1_TSEG11:     .equ   1                                         ; Time Segment 11
CANBTR1_TSEG12:     .equ   2                                         ; Time Segment 12
CANBTR1_TSEG13:     .equ   3                                         ; Time Segment 13
CANBTR1_TSEG20:     .equ   4                                         ; Time Segment 20
CANBTR1_TSEG21:     .equ   5                                         ; Time Segment 21
CANBTR1_TSEG22:     .equ   6                                         ; Time Segment 22
CANBTR1_SAMP:       .equ   7                                         ; Sampling
; bit position masks
mCANBTR1_TSEG10:    .equ   %00000001
mCANBTR1_TSEG11:    .equ   %00000010
mCANBTR1_TSEG12:    .equ   %00000100
mCANBTR1_TSEG13:    .equ   %00001000
mCANBTR1_TSEG20:    .equ   %00010000
mCANBTR1_TSEG21:    .equ   %00100000
mCANBTR1_TSEG22:    .equ   %01000000
mCANBTR1_SAMP:      .equ   %10000000


;*** CANRFLG - MSCAN Receiver Flag Register; 0xFFFF9884 ***
CANRFLG:            .equ   $FFFF9884                                ;*** CANRFLG - MSCAN Receiver Flag Register; 0xFFFF9884 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRFLG_RXF:        .equ   0                                         ; Receive Buffer Full
CANRFLG_OVRIF:      .equ   1                                         ; Overrun Interrupt Flag
CANRFLG_TSTAT0:     .equ   2                                         ; Transmitter Status Bit 0
CANRFLG_TSTAT1:     .equ   3                                         ; Transmitter Status Bit 1
CANRFLG_RSTAT0:     .equ   4                                         ; Receiver Status Bit 0
CANRFLG_RSTAT1:     .equ   5                                         ; Receiver Status Bit 1
CANRFLG_CSCIF:      .equ   6                                         ; CAN Status Change Interrupt Flag
CANRFLG_WUPIF:      .equ   7                                         ; Wake-up Interrupt Flag
; bit position masks
mCANRFLG_RXF:       .equ   %00000001
mCANRFLG_OVRIF:     .equ   %00000010
mCANRFLG_TSTAT0:    .equ   %00000100
mCANRFLG_TSTAT1:    .equ   %00001000
mCANRFLG_RSTAT0:    .equ   %00010000
mCANRFLG_RSTAT1:    .equ   %00100000
mCANRFLG_CSCIF:     .equ   %01000000
mCANRFLG_WUPIF:     .equ   %10000000


;*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0xFFFF9885 ***
CANRIER:            .equ   $FFFF9885                                ;*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0xFFFF9885 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIER_RXFIE:      .equ   0                                         ; Receiver Full Interrupt Enable
CANRIER_OVRIE:      .equ   1                                         ; Overrun Interrupt Enable
CANRIER_TSTATE0:    .equ   2                                         ; Transmitter Status Change Enable 0
CANRIER_TSTATE1:    .equ   3                                         ; Transmitter Status Change Enable 1
CANRIER_RSTATE0:    .equ   4                                         ; Receiver Status Change Enable 0
CANRIER_RSTATE1:    .equ   5                                         ; Receiver Status Change Enable 1
CANRIER_CSCIE:      .equ   6                                         ; CAN Status Change Interrupt Enable
CANRIER_WUPIE:      .equ   7                                         ; Wake-up Interrupt Enable
; bit position masks
mCANRIER_RXFIE:     .equ   %00000001
mCANRIER_OVRIE:     .equ   %00000010
mCANRIER_TSTATE0:   .equ   %00000100
mCANRIER_TSTATE1:   .equ   %00001000
mCANRIER_RSTATE0:   .equ   %00010000
mCANRIER_RSTATE1:   .equ   %00100000
mCANRIER_CSCIE:     .equ   %01000000
mCANRIER_WUPIE:     .equ   %10000000


;*** CANTFLG - MSCAN Transmitter Flag Register; 0xFFFF9886 ***
CANTFLG:            .equ   $FFFF9886                                ;*** CANTFLG - MSCAN Transmitter Flag Register; 0xFFFF9886 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTFLG_TXE0:       .equ   0                                         ; Transmitter Buffer Empty 0
CANTFLG_TXE1:       .equ   1                                         ; Transmitter Buffer Empty 1
CANTFLG_TXE2:       .equ   2                                         ; Transmitter Buffer Empty 2
; bit position masks
mCANTFLG_TXE0:      .equ   %00000001
mCANTFLG_TXE1:      .equ   %00000010
mCANTFLG_TXE2:      .equ   %00000100


;*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0xFFFF9887 ***
CANTIER:            .equ   $FFFF9887                                ;*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0xFFFF9887 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIER_TXEIE0:     .equ   0                                         ; Transmitter Empty Interrupt Enable 0
CANTIER_TXEIE1:     .equ   1                                         ; Transmitter Empty Interrupt Enable 1
CANTIER_TXEIE2:     .equ   2                                         ; Transmitter Empty Interrupt Enable 2
; bit position masks
mCANTIER_TXEIE0:    .equ   %00000001
mCANTIER_TXEIE1:    .equ   %00000010
mCANTIER_TXEIE2:    .equ   %00000100


;*** CANTARQ - MSCAN Transmitter Message Abort Request; 0xFFFF9888 ***
CANTARQ:            .equ   $FFFF9888                                ;*** CANTARQ - MSCAN Transmitter Message Abort Request; 0xFFFF9888 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTARQ_ABTRQ0:     .equ   0                                         ; Abort Request 0
CANTARQ_ABTRQ1:     .equ   1                                         ; Abort Request 1
CANTARQ_ABTRQ2:     .equ   2                                         ; Abort Request 2
; bit position masks
mCANTARQ_ABTRQ0:    .equ   %00000001
mCANTARQ_ABTRQ1:    .equ   %00000010
mCANTARQ_ABTRQ2:    .equ   %00000100


;*** CANTAAK - MSCAN Transmitter Message Abort Acknowledge; 0xFFFF9889 ***
CANTAAK:            .equ   $FFFF9889                                ;*** CANTAAK - MSCAN Transmitter Message Abort Acknowledge; 0xFFFF9889 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTAAK_ABTAK0:     .equ   0                                         ; Abort Acknowledge 0
CANTAAK_ABTAK1:     .equ   1                                         ; Abort Acknowledge 1
CANTAAK_ABTAK2:     .equ   2                                         ; Abort Acknowledge 2
; bit position masks
mCANTAAK_ABTAK0:    .equ   %00000001
mCANTAAK_ABTAK1:    .equ   %00000010
mCANTAAK_ABTAK2:    .equ   %00000100


;*** CANTBSEL - MSCAN Transmit Buffer Selection; 0xFFFF988A ***
CANTBSEL:           .equ   $FFFF988A                                ;*** CANTBSEL - MSCAN Transmit Buffer Selection; 0xFFFF988A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTBSEL_TX0:       .equ   0                                         ; Transmit Buffer Select 0
CANTBSEL_TX1:       .equ   1                                         ; Transmit Buffer Select 1
CANTBSEL_TX2:       .equ   2                                         ; Transmit Buffer Select 2
; bit position masks
mCANTBSEL_TX0:      .equ   %00000001
mCANTBSEL_TX1:      .equ   %00000010
mCANTBSEL_TX2:      .equ   %00000100


;*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0xFFFF988B ***
CANIDAC:            .equ   $FFFF988B                                ;*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0xFFFF988B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAC_IDHIT0:     .equ   0                                         ; Identifier Acceptance Hit Indicator 0
CANIDAC_IDHIT1:     .equ   1                                         ; Identifier Acceptance Hit Indicator 1
CANIDAC_IDHIT2:     .equ   2                                         ; Identifier Acceptance Hit Indicator 2
CANIDAC_IDAM0:      .equ   4                                         ; Identifier Acceptance Mode 0
CANIDAC_IDAM1:      .equ   5                                         ; Identifier Acceptance Mode 1
; bit position masks
mCANIDAC_IDHIT0:    .equ   %00000001
mCANIDAC_IDHIT1:    .equ   %00000010
mCANIDAC_IDHIT2:    .equ   %00000100
mCANIDAC_IDAM0:     .equ   %00010000
mCANIDAC_IDAM1:     .equ   %00100000


;*** CANMISC - MSCAN Miscellaneous Register; 0xFFFF988D ***
CANMISC:            .equ   $FFFF988D                                ;*** CANMISC - MSCAN Miscellaneous Register; 0xFFFF988D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANMISC_BOHOLD:     .equ   0                                         ; Bus-off State Hold Until User Request - If BORM is set
; bit position masks
mCANMISC_BOHOLD:    .equ   %00000001


;*** CANRXERR - MSCAN Receive Error Counter Register; 0xFFFF988E ***
CANRXERR:           .equ   $FFFF988E                                ;*** CANRXERR - MSCAN Receive Error Counter Register; 0xFFFF988E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRXERR_RXERR0:    .equ   0                                         ; Bit 0
CANRXERR_RXERR1:    .equ   1                                         ; Bit 1
CANRXERR_RXERR2:    .equ   2                                         ; Bit 2
CANRXERR_RXERR3:    .equ   3                                         ; Bit 3
CANRXERR_RXERR4:    .equ   4                                         ; Bit 4
CANRXERR_RXERR5:    .equ   5                                         ; Bit 5
CANRXERR_RXERR6:    .equ   6                                         ; Bit 6
CANRXERR_RXERR7:    .equ   7                                         ; Bit 7
; bit position masks
mCANRXERR_RXERR0:   .equ   %00000001
mCANRXERR_RXERR1:   .equ   %00000010
mCANRXERR_RXERR2:   .equ   %00000100
mCANRXERR_RXERR3:   .equ   %00001000
mCANRXERR_RXERR4:   .equ   %00010000
mCANRXERR_RXERR5:   .equ   %00100000
mCANRXERR_RXERR6:   .equ   %01000000
mCANRXERR_RXERR7:   .equ   %10000000


;*** CANTXERR - MSCAN Transmit Error Counter Register; 0xFFFF988F ***
CANTXERR:           .equ   $FFFF988F                                ;*** CANTXERR - MSCAN Transmit Error Counter Register; 0xFFFF988F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTXERR_TXERR0:    .equ   0                                         ; Bit 0
CANTXERR_TXERR1:    .equ   1                                         ; Bit 1
CANTXERR_TXERR2:    .equ   2                                         ; Bit 2
CANTXERR_TXERR3:    .equ   3                                         ; Bit 3
CANTXERR_TXERR4:    .equ   4                                         ; Bit 4
CANTXERR_TXERR5:    .equ   5                                         ; Bit 5
CANTXERR_TXERR6:    .equ   6                                         ; Bit 6
CANTXERR_TXERR7:    .equ   7                                         ; Bit 7
; bit position masks
mCANTXERR_TXERR0:   .equ   %00000001
mCANTXERR_TXERR1:   .equ   %00000010
mCANTXERR_TXERR2:   .equ   %00000100
mCANTXERR_TXERR3:   .equ   %00001000
mCANTXERR_TXERR4:   .equ   %00010000
mCANTXERR_TXERR5:   .equ   %00100000
mCANTXERR_TXERR6:   .equ   %01000000
mCANTXERR_TXERR7:   .equ   %10000000


;*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0xFFFF9890 ***
CANIDAR0:           .equ   $FFFF9890                                ;*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0xFFFF9890 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR0_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR0_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR0_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR0_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR0_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR0_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR0_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR0_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR0_AC0:      .equ   %00000001
mCANIDAR0_AC1:      .equ   %00000010
mCANIDAR0_AC2:      .equ   %00000100
mCANIDAR0_AC3:      .equ   %00001000
mCANIDAR0_AC4:      .equ   %00010000
mCANIDAR0_AC5:      .equ   %00100000
mCANIDAR0_AC6:      .equ   %01000000
mCANIDAR0_AC7:      .equ   %10000000


;*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0xFFFF9891 ***
CANIDAR1:           .equ   $FFFF9891                                ;*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0xFFFF9891 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR1_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR1_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR1_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR1_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR1_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR1_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR1_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR1_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR1_AC0:      .equ   %00000001
mCANIDAR1_AC1:      .equ   %00000010
mCANIDAR1_AC2:      .equ   %00000100
mCANIDAR1_AC3:      .equ   %00001000
mCANIDAR1_AC4:      .equ   %00010000
mCANIDAR1_AC5:      .equ   %00100000
mCANIDAR1_AC6:      .equ   %01000000
mCANIDAR1_AC7:      .equ   %10000000


;*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0xFFFF9892 ***
CANIDAR2:           .equ   $FFFF9892                                ;*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0xFFFF9892 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR2_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR2_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR2_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR2_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR2_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR2_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR2_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR2_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR2_AC0:      .equ   %00000001
mCANIDAR2_AC1:      .equ   %00000010
mCANIDAR2_AC2:      .equ   %00000100
mCANIDAR2_AC3:      .equ   %00001000
mCANIDAR2_AC4:      .equ   %00010000
mCANIDAR2_AC5:      .equ   %00100000
mCANIDAR2_AC6:      .equ   %01000000
mCANIDAR2_AC7:      .equ   %10000000


;*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0xFFFF9893 ***
CANIDAR3:           .equ   $FFFF9893                                ;*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0xFFFF9893 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR3_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR3_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR3_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR3_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR3_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR3_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR3_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR3_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR3_AC0:      .equ   %00000001
mCANIDAR3_AC1:      .equ   %00000010
mCANIDAR3_AC2:      .equ   %00000100
mCANIDAR3_AC3:      .equ   %00001000
mCANIDAR3_AC4:      .equ   %00010000
mCANIDAR3_AC5:      .equ   %00100000
mCANIDAR3_AC6:      .equ   %01000000
mCANIDAR3_AC7:      .equ   %10000000


;*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0xFFFF9894 ***
CANIDMR0:           .equ   $FFFF9894                                ;*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0xFFFF9894 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR0_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR0_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR0_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR0_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR0_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR0_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR0_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR0_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR0_AM0:      .equ   %00000001
mCANIDMR0_AM1:      .equ   %00000010
mCANIDMR0_AM2:      .equ   %00000100
mCANIDMR0_AM3:      .equ   %00001000
mCANIDMR0_AM4:      .equ   %00010000
mCANIDMR0_AM5:      .equ   %00100000
mCANIDMR0_AM6:      .equ   %01000000
mCANIDMR0_AM7:      .equ   %10000000


;*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0xFFFF9895 ***
CANIDMR1:           .equ   $FFFF9895                                ;*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0xFFFF9895 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR1_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR1_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR1_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR1_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR1_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR1_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR1_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR1_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR1_AM0:      .equ   %00000001
mCANIDMR1_AM1:      .equ   %00000010
mCANIDMR1_AM2:      .equ   %00000100
mCANIDMR1_AM3:      .equ   %00001000
mCANIDMR1_AM4:      .equ   %00010000
mCANIDMR1_AM5:      .equ   %00100000
mCANIDMR1_AM6:      .equ   %01000000
mCANIDMR1_AM7:      .equ   %10000000


;*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0xFFFF9896 ***
CANIDMR2:           .equ   $FFFF9896                                ;*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0xFFFF9896 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR2_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR2_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR2_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR2_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR2_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR2_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR2_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR2_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR2_AM0:      .equ   %00000001
mCANIDMR2_AM1:      .equ   %00000010
mCANIDMR2_AM2:      .equ   %00000100
mCANIDMR2_AM3:      .equ   %00001000
mCANIDMR2_AM4:      .equ   %00010000
mCANIDMR2_AM5:      .equ   %00100000
mCANIDMR2_AM6:      .equ   %01000000
mCANIDMR2_AM7:      .equ   %10000000


;*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0xFFFF9897 ***
CANIDMR3:           .equ   $FFFF9897                                ;*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0xFFFF9897 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR3_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR3_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR3_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR3_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR3_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR3_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR3_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR3_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR3_AM0:      .equ   %00000001
mCANIDMR3_AM1:      .equ   %00000010
mCANIDMR3_AM2:      .equ   %00000100
mCANIDMR3_AM3:      .equ   %00001000
mCANIDMR3_AM4:      .equ   %00010000
mCANIDMR3_AM5:      .equ   %00100000
mCANIDMR3_AM6:      .equ   %01000000
mCANIDMR3_AM7:      .equ   %10000000


;*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0xFFFF9898 ***
CANIDAR4:           .equ   $FFFF9898                                ;*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0xFFFF9898 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR4_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR4_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR4_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR4_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR4_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR4_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR4_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR4_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR4_AC0:      .equ   %00000001
mCANIDAR4_AC1:      .equ   %00000010
mCANIDAR4_AC2:      .equ   %00000100
mCANIDAR4_AC3:      .equ   %00001000
mCANIDAR4_AC4:      .equ   %00010000
mCANIDAR4_AC5:      .equ   %00100000
mCANIDAR4_AC6:      .equ   %01000000
mCANIDAR4_AC7:      .equ   %10000000


;*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0xFFFF9899 ***
CANIDAR5:           .equ   $FFFF9899                                ;*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0xFFFF9899 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR5_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR5_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR5_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR5_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR5_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR5_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR5_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR5_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR5_AC0:      .equ   %00000001
mCANIDAR5_AC1:      .equ   %00000010
mCANIDAR5_AC2:      .equ   %00000100
mCANIDAR5_AC3:      .equ   %00001000
mCANIDAR5_AC4:      .equ   %00010000
mCANIDAR5_AC5:      .equ   %00100000
mCANIDAR5_AC6:      .equ   %01000000
mCANIDAR5_AC7:      .equ   %10000000


;*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0xFFFF989A ***
CANIDAR6:           .equ   $FFFF989A                                ;*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0xFFFF989A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR6_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR6_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR6_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR6_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR6_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR6_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR6_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR6_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR6_AC0:      .equ   %00000001
mCANIDAR6_AC1:      .equ   %00000010
mCANIDAR6_AC2:      .equ   %00000100
mCANIDAR6_AC3:      .equ   %00001000
mCANIDAR6_AC4:      .equ   %00010000
mCANIDAR6_AC5:      .equ   %00100000
mCANIDAR6_AC6:      .equ   %01000000
mCANIDAR6_AC7:      .equ   %10000000


;*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0xFFFF989B ***
CANIDAR7:           .equ   $FFFF989B                                ;*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0xFFFF989B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDAR7_AC0:       .equ   0                                         ; Acceptance Code Bit 0
CANIDAR7_AC1:       .equ   1                                         ; Acceptance Code Bit 1
CANIDAR7_AC2:       .equ   2                                         ; Acceptance Code Bit 2
CANIDAR7_AC3:       .equ   3                                         ; Acceptance Code Bit 3
CANIDAR7_AC4:       .equ   4                                         ; Acceptance Code Bit 4
CANIDAR7_AC5:       .equ   5                                         ; Acceptance Code Bit 5
CANIDAR7_AC6:       .equ   6                                         ; Acceptance Code Bit 6
CANIDAR7_AC7:       .equ   7                                         ; Acceptance Code Bit 7
; bit position masks
mCANIDAR7_AC0:      .equ   %00000001
mCANIDAR7_AC1:      .equ   %00000010
mCANIDAR7_AC2:      .equ   %00000100
mCANIDAR7_AC3:      .equ   %00001000
mCANIDAR7_AC4:      .equ   %00010000
mCANIDAR7_AC5:      .equ   %00100000
mCANIDAR7_AC6:      .equ   %01000000
mCANIDAR7_AC7:      .equ   %10000000


;*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0xFFFF989C ***
CANIDMR4:           .equ   $FFFF989C                                ;*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0xFFFF989C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR4_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR4_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR4_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR4_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR4_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR4_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR4_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR4_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR4_AM0:      .equ   %00000001
mCANIDMR4_AM1:      .equ   %00000010
mCANIDMR4_AM2:      .equ   %00000100
mCANIDMR4_AM3:      .equ   %00001000
mCANIDMR4_AM4:      .equ   %00010000
mCANIDMR4_AM5:      .equ   %00100000
mCANIDMR4_AM6:      .equ   %01000000
mCANIDMR4_AM7:      .equ   %10000000


;*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0xFFFF989D ***
CANIDMR5:           .equ   $FFFF989D                                ;*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0xFFFF989D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR5_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR5_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR5_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR5_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR5_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR5_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR5_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR5_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR5_AM0:      .equ   %00000001
mCANIDMR5_AM1:      .equ   %00000010
mCANIDMR5_AM2:      .equ   %00000100
mCANIDMR5_AM3:      .equ   %00001000
mCANIDMR5_AM4:      .equ   %00010000
mCANIDMR5_AM5:      .equ   %00100000
mCANIDMR5_AM6:      .equ   %01000000
mCANIDMR5_AM7:      .equ   %10000000


;*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0xFFFF989E ***
CANIDMR6:           .equ   $FFFF989E                                ;*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0xFFFF989E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR6_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR6_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR6_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR6_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR6_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR6_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR6_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR6_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR6_AM0:      .equ   %00000001
mCANIDMR6_AM1:      .equ   %00000010
mCANIDMR6_AM2:      .equ   %00000100
mCANIDMR6_AM3:      .equ   %00001000
mCANIDMR6_AM4:      .equ   %00010000
mCANIDMR6_AM5:      .equ   %00100000
mCANIDMR6_AM6:      .equ   %01000000
mCANIDMR6_AM7:      .equ   %10000000


;*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0xFFFF989F ***
CANIDMR7:           .equ   $FFFF989F                                ;*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0xFFFF989F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANIDMR7_AM0:       .equ   0                                         ; Acceptance Mask Bit 0
CANIDMR7_AM1:       .equ   1                                         ; Acceptance Mask Bit 1
CANIDMR7_AM2:       .equ   2                                         ; Acceptance Mask Bit 2
CANIDMR7_AM3:       .equ   3                                         ; Acceptance Mask Bit 3
CANIDMR7_AM4:       .equ   4                                         ; Acceptance Mask Bit 4
CANIDMR7_AM5:       .equ   5                                         ; Acceptance Mask Bit 5
CANIDMR7_AM6:       .equ   6                                         ; Acceptance Mask Bit 6
CANIDMR7_AM7:       .equ   7                                         ; Acceptance Mask Bit 7
; bit position masks
mCANIDMR7_AM0:      .equ   %00000001
mCANIDMR7_AM1:      .equ   %00000010
mCANIDMR7_AM2:      .equ   %00000100
mCANIDMR7_AM3:      .equ   %00001000
mCANIDMR7_AM4:      .equ   %00010000
mCANIDMR7_AM5:      .equ   %00100000
mCANIDMR7_AM6:      .equ   %01000000
mCANIDMR7_AM7:      .equ   %10000000


;*** CANRIDR0 - MSCAN 0 Receive Identifier Register 0; 0xFFFF98A0 ***
CANRIDR0:           .equ   $FFFF98A0                                ;*** CANRIDR0 - MSCAN 0 Receive Identifier Register 0; 0xFFFF98A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIDR0_ID21:      .equ   0                                         ; Extended format identifier Bit 21
CANRIDR0_ID22:      .equ   1                                         ; Extended format identifier Bit 22
CANRIDR0_ID23:      .equ   2                                         ; Extended format identifier Bit 23
CANRIDR0_ID24:      .equ   3                                         ; Extended format identifier Bit 24
CANRIDR0_ID25:      .equ   4                                         ; Extended format identifier Bit 25
CANRIDR0_ID26:      .equ   5                                         ; Extended format identifier Bit 26
CANRIDR0_ID27:      .equ   6                                         ; Extended format identifier Bit 27
CANRIDR0_ID28:      .equ   7                                         ; Extended format identifier Bit 28
; bit position masks
mCANRIDR0_ID21:     .equ   %00000001
mCANRIDR0_ID22:     .equ   %00000010
mCANRIDR0_ID23:     .equ   %00000100
mCANRIDR0_ID24:     .equ   %00001000
mCANRIDR0_ID25:     .equ   %00010000
mCANRIDR0_ID26:     .equ   %00100000
mCANRIDR0_ID27:     .equ   %01000000
mCANRIDR0_ID28:     .equ   %10000000


;*** CANRIDR1 - MSCAN 0 Receive Identifier Register 1; 0xFFFF98A1 ***
CANRIDR1:           .equ   $FFFF98A1                                ;*** CANRIDR1 - MSCAN 0 Receive Identifier Register 1; 0xFFFF98A1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIDR1_ID15:      .equ   0                                         ; Extended format identifier Bit 15
CANRIDR1_ID16:      .equ   1                                         ; Extended format identifier Bit 16
CANRIDR1_ID17:      .equ   2                                         ; Extended format identifier Bit 17
CANRIDR1_IDE:       .equ   3                                         ; ID Extended
CANRIDR1_SRR:       .equ   4                                         ; Substitute Remote Request
CANRIDR1_ID18:      .equ   5                                         ; Extended format identifier Bit 18
CANRIDR1_ID19:      .equ   6                                         ; Extended format identifier Bit 19
CANRIDR1_ID20:      .equ   7                                         ; Extended format identifier Bit 20
; bit position masks
mCANRIDR1_ID15:     .equ   %00000001
mCANRIDR1_ID16:     .equ   %00000010
mCANRIDR1_ID17:     .equ   %00000100
mCANRIDR1_IDE:      .equ   %00001000
mCANRIDR1_SRR:      .equ   %00010000
mCANRIDR1_ID18:     .equ   %00100000
mCANRIDR1_ID19:     .equ   %01000000
mCANRIDR1_ID20:     .equ   %10000000


;*** CANRIDR2 - MSCAN 0 Receive Identifier Register 2; 0xFFFF98A2 ***
CANRIDR2:           .equ   $FFFF98A2                                ;*** CANRIDR2 - MSCAN 0 Receive Identifier Register 2; 0xFFFF98A2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIDR2_ID7:       .equ   0                                         ; Extended format identifier Bit 7
CANRIDR2_ID8:       .equ   1                                         ; Extended format identifier Bit 8
CANRIDR2_ID9:       .equ   2                                         ; Extended format identifier Bit 9
CANRIDR2_ID10:      .equ   3                                         ; Extended format identifier Bit 10
CANRIDR2_ID11:      .equ   4                                         ; Extended format identifier Bit 11
CANRIDR2_ID12:      .equ   5                                         ; Extended format identifier Bit 12
CANRIDR2_ID13:      .equ   6                                         ; Extended format identifier Bit 13
CANRIDR2_ID14:      .equ   7                                         ; Extended format identifier Bit 14
; bit position masks
mCANRIDR2_ID7:      .equ   %00000001
mCANRIDR2_ID8:      .equ   %00000010
mCANRIDR2_ID9:      .equ   %00000100
mCANRIDR2_ID10:     .equ   %00001000
mCANRIDR2_ID11:     .equ   %00010000
mCANRIDR2_ID12:     .equ   %00100000
mCANRIDR2_ID13:     .equ   %01000000
mCANRIDR2_ID14:     .equ   %10000000


;*** CANRIDR3 - MSCAN 0 Receive Identifier Register 3; 0xFFFF98A3 ***
CANRIDR3:           .equ   $FFFF98A3                                ;*** CANRIDR3 - MSCAN 0 Receive Identifier Register 3; 0xFFFF98A3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRIDR3_RTR:       .equ   0                                         ; Remote Transmission Request
CANRIDR3_ID0:       .equ   1                                         ; Extended format identifier Bit 0
CANRIDR3_ID1:       .equ   2                                         ; Extended format identifier Bit 1
CANRIDR3_ID2:       .equ   3                                         ; Extended format identifier Bit 2
CANRIDR3_ID3:       .equ   4                                         ; Extended format identifier Bit 3
CANRIDR3_ID4:       .equ   5                                         ; Extended format identifier Bit 4
CANRIDR3_ID5:       .equ   6                                         ; Extended format identifier Bit 5
CANRIDR3_ID6:       .equ   7                                         ; Extended format identifier Bit 6
; bit position masks
mCANRIDR3_RTR:      .equ   %00000001
mCANRIDR3_ID0:      .equ   %00000010
mCANRIDR3_ID1:      .equ   %00000100
mCANRIDR3_ID2:      .equ   %00001000
mCANRIDR3_ID3:      .equ   %00010000
mCANRIDR3_ID4:      .equ   %00100000
mCANRIDR3_ID5:      .equ   %01000000
mCANRIDR3_ID6:      .equ   %10000000


;*** CANRDSR0 - MSCAN Receive Data Segment Register 0; 0xFFFF98A4 ***
CANRDSR0:           .equ   $FFFF98A4                                ;*** CANRDSR0 - MSCAN Receive Data Segment Register 0; 0xFFFF98A4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR0_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR0_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR0_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR0_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR0_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR0_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR0_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR0_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR0_DB0:      .equ   %00000001
mCANRDSR0_DB1:      .equ   %00000010
mCANRDSR0_DB2:      .equ   %00000100
mCANRDSR0_DB3:      .equ   %00001000
mCANRDSR0_DB4:      .equ   %00010000
mCANRDSR0_DB5:      .equ   %00100000
mCANRDSR0_DB6:      .equ   %01000000
mCANRDSR0_DB7:      .equ   %10000000


;*** CANRDSR1 - MSCAN Receive Data Segment Register 1; 0xFFFF98A5 ***
CANRDSR1:           .equ   $FFFF98A5                                ;*** CANRDSR1 - MSCAN Receive Data Segment Register 1; 0xFFFF98A5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR1_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR1_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR1_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR1_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR1_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR1_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR1_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR1_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR1_DB0:      .equ   %00000001
mCANRDSR1_DB1:      .equ   %00000010
mCANRDSR1_DB2:      .equ   %00000100
mCANRDSR1_DB3:      .equ   %00001000
mCANRDSR1_DB4:      .equ   %00010000
mCANRDSR1_DB5:      .equ   %00100000
mCANRDSR1_DB6:      .equ   %01000000
mCANRDSR1_DB7:      .equ   %10000000


;*** CANRDSR2 - MSCAN Receive Data Segment Register 2; 0xFFFF98A6 ***
CANRDSR2:           .equ   $FFFF98A6                                ;*** CANRDSR2 - MSCAN Receive Data Segment Register 2; 0xFFFF98A6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR2_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR2_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR2_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR2_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR2_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR2_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR2_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR2_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR2_DB0:      .equ   %00000001
mCANRDSR2_DB1:      .equ   %00000010
mCANRDSR2_DB2:      .equ   %00000100
mCANRDSR2_DB3:      .equ   %00001000
mCANRDSR2_DB4:      .equ   %00010000
mCANRDSR2_DB5:      .equ   %00100000
mCANRDSR2_DB6:      .equ   %01000000
mCANRDSR2_DB7:      .equ   %10000000


;*** CANRDSR3 - MSCAN Receive Data Segment Register 3; 0xFFFF98A7 ***
CANRDSR3:           .equ   $FFFF98A7                                ;*** CANRDSR3 - MSCAN Receive Data Segment Register 3; 0xFFFF98A7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR3_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR3_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR3_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR3_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR3_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR3_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR3_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR3_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR3_DB0:      .equ   %00000001
mCANRDSR3_DB1:      .equ   %00000010
mCANRDSR3_DB2:      .equ   %00000100
mCANRDSR3_DB3:      .equ   %00001000
mCANRDSR3_DB4:      .equ   %00010000
mCANRDSR3_DB5:      .equ   %00100000
mCANRDSR3_DB6:      .equ   %01000000
mCANRDSR3_DB7:      .equ   %10000000


;*** CANRDSR4 - MSCAN Receive Data Segment Register 4; 0xFFFF98A8 ***
CANRDSR4:           .equ   $FFFF98A8                                ;*** CANRDSR4 - MSCAN Receive Data Segment Register 4; 0xFFFF98A8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR4_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR4_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR4_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR4_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR4_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR4_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR4_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR4_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR4_DB0:      .equ   %00000001
mCANRDSR4_DB1:      .equ   %00000010
mCANRDSR4_DB2:      .equ   %00000100
mCANRDSR4_DB3:      .equ   %00001000
mCANRDSR4_DB4:      .equ   %00010000
mCANRDSR4_DB5:      .equ   %00100000
mCANRDSR4_DB6:      .equ   %01000000
mCANRDSR4_DB7:      .equ   %10000000


;*** CANRDSR5 - MSCAN Receive Data Segment Register 5; 0xFFFF98A9 ***
CANRDSR5:           .equ   $FFFF98A9                                ;*** CANRDSR5 - MSCAN Receive Data Segment Register 5; 0xFFFF98A9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR5_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR5_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR5_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR5_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR5_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR5_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR5_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR5_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR5_DB0:      .equ   %00000001
mCANRDSR5_DB1:      .equ   %00000010
mCANRDSR5_DB2:      .equ   %00000100
mCANRDSR5_DB3:      .equ   %00001000
mCANRDSR5_DB4:      .equ   %00010000
mCANRDSR5_DB5:      .equ   %00100000
mCANRDSR5_DB6:      .equ   %01000000
mCANRDSR5_DB7:      .equ   %10000000


;*** CANRDSR6 - MSCAN Receive Data Segment Register 6; 0xFFFF98AA ***
CANRDSR6:           .equ   $FFFF98AA                                ;*** CANRDSR6 - MSCAN Receive Data Segment Register 6; 0xFFFF98AA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR6_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR6_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR6_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR6_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR6_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR6_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR6_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR6_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR6_DB0:      .equ   %00000001
mCANRDSR6_DB1:      .equ   %00000010
mCANRDSR6_DB2:      .equ   %00000100
mCANRDSR6_DB3:      .equ   %00001000
mCANRDSR6_DB4:      .equ   %00010000
mCANRDSR6_DB5:      .equ   %00100000
mCANRDSR6_DB6:      .equ   %01000000
mCANRDSR6_DB7:      .equ   %10000000


;*** CANRDSR7 - MSCAN Receive Data Segment Register 7; 0xFFFF98AB ***
CANRDSR7:           .equ   $FFFF98AB                                ;*** CANRDSR7 - MSCAN Receive Data Segment Register 7; 0xFFFF98AB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDSR7_DB0:       .equ   0                                         ; Data Bit 0
CANRDSR7_DB1:       .equ   1                                         ; Data Bit 1
CANRDSR7_DB2:       .equ   2                                         ; Data Bit 2
CANRDSR7_DB3:       .equ   3                                         ; Data Bit 3
CANRDSR7_DB4:       .equ   4                                         ; Data Bit 4
CANRDSR7_DB5:       .equ   5                                         ; Data Bit 5
CANRDSR7_DB6:       .equ   6                                         ; Data Bit 6
CANRDSR7_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANRDSR7_DB0:      .equ   %00000001
mCANRDSR7_DB1:      .equ   %00000010
mCANRDSR7_DB2:      .equ   %00000100
mCANRDSR7_DB3:      .equ   %00001000
mCANRDSR7_DB4:      .equ   %00010000
mCANRDSR7_DB5:      .equ   %00100000
mCANRDSR7_DB6:      .equ   %01000000
mCANRDSR7_DB7:      .equ   %10000000


;*** CANRDLR - MSCAN Receive Data Length Register; 0xFFFF98AC ***
CANRDLR:            .equ   $FFFF98AC                                ;*** CANRDLR - MSCAN Receive Data Length Register; 0xFFFF98AC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRDLR_DLC0:       .equ   0                                         ; Data Length Code Bit 0
CANRDLR_DLC1:       .equ   1                                         ; Data Length Code Bit 1
CANRDLR_DLC2:       .equ   2                                         ; Data Length Code Bit 2
CANRDLR_DLC3:       .equ   3                                         ; Data Length Code Bit 3
; bit position masks
mCANRDLR_DLC0:      .equ   %00000001
mCANRDLR_DLC1:      .equ   %00000010
mCANRDLR_DLC2:      .equ   %00000100
mCANRDLR_DLC3:      .equ   %00001000


;*** CANRTSR - MSCAN Receive Time Stamp Register; 0xFFFF98AE ***
CANRTSR:            .equ   $FFFF98AE                                ;*** CANRTSR - MSCAN Receive Time Stamp Register; 0xFFFF98AE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRTSR_TSR0:       .equ   0                                         ; Time Stamp Bit 0
CANRTSR_TSR1:       .equ   1                                         ; Time Stamp Bit 1
CANRTSR_TSR2:       .equ   2                                         ; Time Stamp Bit 2
CANRTSR_TSR3:       .equ   3                                         ; Time Stamp Bit 3
CANRTSR_TSR4:       .equ   4                                         ; Time Stamp Bit 4
CANRTSR_TSR5:       .equ   5                                         ; Time Stamp Bit 5
CANRTSR_TSR6:       .equ   6                                         ; Time Stamp Bit 6
CANRTSR_TSR7:       .equ   7                                         ; Time Stamp Bit 7
CANRTSR_TSR8:       .equ   8                                         ; Time Stamp Bit 8
CANRTSR_TSR9:       .equ   9                                         ; Time Stamp Bit 9
CANRTSR_TSR10:      .equ   10                                        ; Time Stamp Bit 10
CANRTSR_TSR11:      .equ   11                                        ; Time Stamp Bit 11
CANRTSR_TSR12:      .equ   12                                        ; Time Stamp Bit 12
CANRTSR_TSR13:      .equ   13                                        ; Time Stamp Bit 13
CANRTSR_TSR14:      .equ   14                                        ; Time Stamp Bit 14
CANRTSR_TSR15:      .equ   15                                        ; Time Stamp Bit 15
; bit position masks
mCANRTSR_TSR0:      .equ   %00000001
mCANRTSR_TSR1:      .equ   %00000010
mCANRTSR_TSR2:      .equ   %00000100
mCANRTSR_TSR3:      .equ   %00001000
mCANRTSR_TSR4:      .equ   %00010000
mCANRTSR_TSR5:      .equ   %00100000
mCANRTSR_TSR6:      .equ   %01000000
mCANRTSR_TSR7:      .equ   %10000000
mCANRTSR_TSR8:      .equ   %100000000
mCANRTSR_TSR9:      .equ   %1000000000
mCANRTSR_TSR10:     .equ   %10000000000
mCANRTSR_TSR11:     .equ   %100000000000
mCANRTSR_TSR12:     .equ   %1000000000000
mCANRTSR_TSR13:     .equ   %10000000000000
mCANRTSR_TSR14:     .equ   %100000000000000
mCANRTSR_TSR15:     .equ   %1000000000000000


;*** CANRTSRH - MSCAN Receive Time Stamp Register High; 0xFFFF98AE ***
CANRTSRH:           .equ   $FFFF98AE                                ;*** CANRTSRH - MSCAN Receive Time Stamp Register High; 0xFFFF98AE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRTSRH_TSR8:      .equ   0                                         ; Time Stamp Bit 8
CANRTSRH_TSR9:      .equ   1                                         ; Time Stamp Bit 9
CANRTSRH_TSR10:     .equ   2                                         ; Time Stamp Bit 10
CANRTSRH_TSR11:     .equ   3                                         ; Time Stamp Bit 11
CANRTSRH_TSR12:     .equ   4                                         ; Time Stamp Bit 12
CANRTSRH_TSR13:     .equ   5                                         ; Time Stamp Bit 13
CANRTSRH_TSR14:     .equ   6                                         ; Time Stamp Bit 14
CANRTSRH_TSR15:     .equ   7                                         ; Time Stamp Bit 15
; bit position masks
mCANRTSRH_TSR8:     .equ   %00000001
mCANRTSRH_TSR9:     .equ   %00000010
mCANRTSRH_TSR10:    .equ   %00000100
mCANRTSRH_TSR11:    .equ   %00001000
mCANRTSRH_TSR12:    .equ   %00010000
mCANRTSRH_TSR13:    .equ   %00100000
mCANRTSRH_TSR14:    .equ   %01000000
mCANRTSRH_TSR15:    .equ   %10000000


;*** CANRTSRL - MSCAN Receive Time Stamp Register Low; 0xFFFF98AF ***
CANRTSRL:           .equ   $FFFF98AF                                ;*** CANRTSRL - MSCAN Receive Time Stamp Register Low; 0xFFFF98AF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANRTSRL_TSR0:      .equ   0                                         ; Time Stamp Bit 0
CANRTSRL_TSR1:      .equ   1                                         ; Time Stamp Bit 1
CANRTSRL_TSR2:      .equ   2                                         ; Time Stamp Bit 2
CANRTSRL_TSR3:      .equ   3                                         ; Time Stamp Bit 3
CANRTSRL_TSR4:      .equ   4                                         ; Time Stamp Bit 4
CANRTSRL_TSR5:      .equ   5                                         ; Time Stamp Bit 5
CANRTSRL_TSR6:      .equ   6                                         ; Time Stamp Bit 6
CANRTSRL_TSR7:      .equ   7                                         ; Time Stamp Bit 7
; bit position masks
mCANRTSRL_TSR0:     .equ   %00000001
mCANRTSRL_TSR1:     .equ   %00000010
mCANRTSRL_TSR2:     .equ   %00000100
mCANRTSRL_TSR3:     .equ   %00001000
mCANRTSRL_TSR4:     .equ   %00010000
mCANRTSRL_TSR5:     .equ   %00100000
mCANRTSRL_TSR6:     .equ   %01000000
mCANRTSRL_TSR7:     .equ   %10000000


;*** CANTIDR0 - MSCAN 0 Transmit Identifier Register 0; 0xFFFF98B0 ***
CANTIDR0:           .equ   $FFFF98B0                                ;*** CANTIDR0 - MSCAN 0 Transmit Identifier Register 0; 0xFFFF98B0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIDR0_ID21:      .equ   0                                         ; Extended format identifier Bit 21
CANTIDR0_ID22:      .equ   1                                         ; Extended format identifier Bit 22
CANTIDR0_ID23:      .equ   2                                         ; Extended format identifier Bit 23
CANTIDR0_ID24:      .equ   3                                         ; Extended format identifier Bit 24
CANTIDR0_ID25:      .equ   4                                         ; Extended format identifier Bit 25
CANTIDR0_ID26:      .equ   5                                         ; Extended format identifier Bit 26
CANTIDR0_ID27:      .equ   6                                         ; Extended format identifier Bit 27
CANTIDR0_ID28:      .equ   7                                         ; Extended format identifier Bit 28
; bit position masks
mCANTIDR0_ID21:     .equ   %00000001
mCANTIDR0_ID22:     .equ   %00000010
mCANTIDR0_ID23:     .equ   %00000100
mCANTIDR0_ID24:     .equ   %00001000
mCANTIDR0_ID25:     .equ   %00010000
mCANTIDR0_ID26:     .equ   %00100000
mCANTIDR0_ID27:     .equ   %01000000
mCANTIDR0_ID28:     .equ   %10000000


;*** CANTIDR1 - MSCAN 0 Transmit Identifier Register 1; 0xFFFF98B1 ***
CANTIDR1:           .equ   $FFFF98B1                                ;*** CANTIDR1 - MSCAN 0 Transmit Identifier Register 1; 0xFFFF98B1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIDR1_ID15:      .equ   0                                         ; Extended format identifier Bit 15
CANTIDR1_ID16:      .equ   1                                         ; Extended format identifier Bit 16
CANTIDR1_ID17:      .equ   2                                         ; Extended format identifier Bit 17
CANTIDR1_IDE:       .equ   3                                         ; ID Extended
CANTIDR1_SRR:       .equ   4                                         ; Substitute Remote Request
CANTIDR1_ID18:      .equ   5                                         ; Extended format identifier Bit 18
CANTIDR1_ID19:      .equ   6                                         ; Extended format identifier Bit 19
CANTIDR1_ID20:      .equ   7                                         ; Extended format identifier Bit 20
; bit position masks
mCANTIDR1_ID15:     .equ   %00000001
mCANTIDR1_ID16:     .equ   %00000010
mCANTIDR1_ID17:     .equ   %00000100
mCANTIDR1_IDE:      .equ   %00001000
mCANTIDR1_SRR:      .equ   %00010000
mCANTIDR1_ID18:     .equ   %00100000
mCANTIDR1_ID19:     .equ   %01000000
mCANTIDR1_ID20:     .equ   %10000000


;*** CANTIDR2 - MSCAN 0 Transmit Identifier Register 2; 0xFFFF98B2 ***
CANTIDR2:           .equ   $FFFF98B2                                ;*** CANTIDR2 - MSCAN 0 Transmit Identifier Register 2; 0xFFFF98B2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIDR2_ID7:       .equ   0                                         ; Extended format identifier Bit 7
CANTIDR2_ID8:       .equ   1                                         ; Extended format identifier Bit 8
CANTIDR2_ID9:       .equ   2                                         ; Extended format identifier Bit 9
CANTIDR2_ID10:      .equ   3                                         ; Extended format identifier Bit 10
CANTIDR2_ID11:      .equ   4                                         ; Extended format identifier Bit 11
CANTIDR2_ID12:      .equ   5                                         ; Extended format identifier Bit 12
CANTIDR2_ID13:      .equ   6                                         ; Extended format identifier Bit 13
CANTIDR2_ID14:      .equ   7                                         ; Extended format identifier Bit 14
; bit position masks
mCANTIDR2_ID7:      .equ   %00000001
mCANTIDR2_ID8:      .equ   %00000010
mCANTIDR2_ID9:      .equ   %00000100
mCANTIDR2_ID10:     .equ   %00001000
mCANTIDR2_ID11:     .equ   %00010000
mCANTIDR2_ID12:     .equ   %00100000
mCANTIDR2_ID13:     .equ   %01000000
mCANTIDR2_ID14:     .equ   %10000000


;*** CANTIDR3 - MSCAN 0 Transmit Identifier Register 3; 0xFFFF98B3 ***
CANTIDR3:           .equ   $FFFF98B3                                ;*** CANTIDR3 - MSCAN 0 Transmit Identifier Register 3; 0xFFFF98B3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTIDR3_RTR:       .equ   0                                         ; Remote Transmission Request
CANTIDR3_ID0:       .equ   1                                         ; Extended format identifier Bit 0
CANTIDR3_ID1:       .equ   2                                         ; Extended format identifier Bit 1
CANTIDR3_ID2:       .equ   3                                         ; Extended format identifier Bit 2
CANTIDR3_ID3:       .equ   4                                         ; Extended format identifier Bit 3
CANTIDR3_ID4:       .equ   5                                         ; Extended format identifier Bit 4
CANTIDR3_ID5:       .equ   6                                         ; Extended format identifier Bit 5
CANTIDR3_ID6:       .equ   7                                         ; Extended format identifier Bit 6
; bit position masks
mCANTIDR3_RTR:      .equ   %00000001
mCANTIDR3_ID0:      .equ   %00000010
mCANTIDR3_ID1:      .equ   %00000100
mCANTIDR3_ID2:      .equ   %00001000
mCANTIDR3_ID3:      .equ   %00010000
mCANTIDR3_ID4:      .equ   %00100000
mCANTIDR3_ID5:      .equ   %01000000
mCANTIDR3_ID6:      .equ   %10000000


;*** CANTDSR0 - MSCAN Transmit Data Segment Register 0; 0xFFFF98B4 ***
CANTDSR0:           .equ   $FFFF98B4                                ;*** CANTDSR0 - MSCAN Transmit Data Segment Register 0; 0xFFFF98B4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR0_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR0_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR0_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR0_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR0_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR0_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR0_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR0_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR0_DB0:      .equ   %00000001
mCANTDSR0_DB1:      .equ   %00000010
mCANTDSR0_DB2:      .equ   %00000100
mCANTDSR0_DB3:      .equ   %00001000
mCANTDSR0_DB4:      .equ   %00010000
mCANTDSR0_DB5:      .equ   %00100000
mCANTDSR0_DB6:      .equ   %01000000
mCANTDSR0_DB7:      .equ   %10000000


;*** CANTDSR1 - MSCAN Transmit Data Segment Register 1; 0xFFFF98B5 ***
CANTDSR1:           .equ   $FFFF98B5                                ;*** CANTDSR1 - MSCAN Transmit Data Segment Register 1; 0xFFFF98B5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR1_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR1_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR1_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR1_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR1_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR1_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR1_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR1_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR1_DB0:      .equ   %00000001
mCANTDSR1_DB1:      .equ   %00000010
mCANTDSR1_DB2:      .equ   %00000100
mCANTDSR1_DB3:      .equ   %00001000
mCANTDSR1_DB4:      .equ   %00010000
mCANTDSR1_DB5:      .equ   %00100000
mCANTDSR1_DB6:      .equ   %01000000
mCANTDSR1_DB7:      .equ   %10000000


;*** CANTDSR2 - MSCAN Transmit Data Segment Register 2; 0xFFFF98B6 ***
CANTDSR2:           .equ   $FFFF98B6                                ;*** CANTDSR2 - MSCAN Transmit Data Segment Register 2; 0xFFFF98B6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR2_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR2_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR2_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR2_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR2_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR2_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR2_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR2_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR2_DB0:      .equ   %00000001
mCANTDSR2_DB1:      .equ   %00000010
mCANTDSR2_DB2:      .equ   %00000100
mCANTDSR2_DB3:      .equ   %00001000
mCANTDSR2_DB4:      .equ   %00010000
mCANTDSR2_DB5:      .equ   %00100000
mCANTDSR2_DB6:      .equ   %01000000
mCANTDSR2_DB7:      .equ   %10000000


;*** CANTDSR3 - MSCAN Transmit Data Segment Register 3; 0xFFFF98B7 ***
CANTDSR3:           .equ   $FFFF98B7                                ;*** CANTDSR3 - MSCAN Transmit Data Segment Register 3; 0xFFFF98B7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR3_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR3_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR3_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR3_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR3_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR3_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR3_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR3_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR3_DB0:      .equ   %00000001
mCANTDSR3_DB1:      .equ   %00000010
mCANTDSR3_DB2:      .equ   %00000100
mCANTDSR3_DB3:      .equ   %00001000
mCANTDSR3_DB4:      .equ   %00010000
mCANTDSR3_DB5:      .equ   %00100000
mCANTDSR3_DB6:      .equ   %01000000
mCANTDSR3_DB7:      .equ   %10000000


;*** CANTDSR4 - MSCAN Transmit Data Segment Register 4; 0xFFFF98B8 ***
CANTDSR4:           .equ   $FFFF98B8                                ;*** CANTDSR4 - MSCAN Transmit Data Segment Register 4; 0xFFFF98B8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR4_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR4_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR4_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR4_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR4_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR4_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR4_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR4_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR4_DB0:      .equ   %00000001
mCANTDSR4_DB1:      .equ   %00000010
mCANTDSR4_DB2:      .equ   %00000100
mCANTDSR4_DB3:      .equ   %00001000
mCANTDSR4_DB4:      .equ   %00010000
mCANTDSR4_DB5:      .equ   %00100000
mCANTDSR4_DB6:      .equ   %01000000
mCANTDSR4_DB7:      .equ   %10000000


;*** CANTDSR5 - MSCAN Transmit Data Segment Register 5; 0xFFFF98B9 ***
CANTDSR5:           .equ   $FFFF98B9                                ;*** CANTDSR5 - MSCAN Transmit Data Segment Register 5; 0xFFFF98B9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR5_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR5_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR5_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR5_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR5_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR5_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR5_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR5_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR5_DB0:      .equ   %00000001
mCANTDSR5_DB1:      .equ   %00000010
mCANTDSR5_DB2:      .equ   %00000100
mCANTDSR5_DB3:      .equ   %00001000
mCANTDSR5_DB4:      .equ   %00010000
mCANTDSR5_DB5:      .equ   %00100000
mCANTDSR5_DB6:      .equ   %01000000
mCANTDSR5_DB7:      .equ   %10000000


;*** CANTDSR6 - MSCAN Transmit Data Segment Register 6; 0xFFFF98BA ***
CANTDSR6:           .equ   $FFFF98BA                                ;*** CANTDSR6 - MSCAN Transmit Data Segment Register 6; 0xFFFF98BA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR6_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR6_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR6_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR6_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR6_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR6_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR6_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR6_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR6_DB0:      .equ   %00000001
mCANTDSR6_DB1:      .equ   %00000010
mCANTDSR6_DB2:      .equ   %00000100
mCANTDSR6_DB3:      .equ   %00001000
mCANTDSR6_DB4:      .equ   %00010000
mCANTDSR6_DB5:      .equ   %00100000
mCANTDSR6_DB6:      .equ   %01000000
mCANTDSR6_DB7:      .equ   %10000000


;*** CANTDSR7 - MSCAN Transmit Data Segment Register 7; 0xFFFF98BB ***
CANTDSR7:           .equ   $FFFF98BB                                ;*** CANTDSR7 - MSCAN Transmit Data Segment Register 7; 0xFFFF98BB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDSR7_DB0:       .equ   0                                         ; Data Bit 0
CANTDSR7_DB1:       .equ   1                                         ; Data Bit 1
CANTDSR7_DB2:       .equ   2                                         ; Data Bit 2
CANTDSR7_DB3:       .equ   3                                         ; Data Bit 3
CANTDSR7_DB4:       .equ   4                                         ; Data Bit 4
CANTDSR7_DB5:       .equ   5                                         ; Data Bit 5
CANTDSR7_DB6:       .equ   6                                         ; Data Bit 6
CANTDSR7_DB7:       .equ   7                                         ; Data Bit 7
; bit position masks
mCANTDSR7_DB0:      .equ   %00000001
mCANTDSR7_DB1:      .equ   %00000010
mCANTDSR7_DB2:      .equ   %00000100
mCANTDSR7_DB3:      .equ   %00001000
mCANTDSR7_DB4:      .equ   %00010000
mCANTDSR7_DB5:      .equ   %00100000
mCANTDSR7_DB6:      .equ   %01000000
mCANTDSR7_DB7:      .equ   %10000000


;*** CANTDLR - MSCAN Transmit Data Length Register; 0xFFFF98BC ***
CANTDLR:            .equ   $FFFF98BC                                ;*** CANTDLR - MSCAN Transmit Data Length Register; 0xFFFF98BC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTDLR_DLC0:       .equ   0                                         ; Data Length Code Bit 0
CANTDLR_DLC1:       .equ   1                                         ; Data Length Code Bit 1
CANTDLR_DLC2:       .equ   2                                         ; Data Length Code Bit 2
CANTDLR_DLC3:       .equ   3                                         ; Data Length Code Bit 3
; bit position masks
mCANTDLR_DLC0:      .equ   %00000001
mCANTDLR_DLC1:      .equ   %00000010
mCANTDLR_DLC2:      .equ   %00000100
mCANTDLR_DLC3:      .equ   %00001000


;*** CANTTBPR - MSCAN Transmit Buffer Priority; 0xFFFF98BD ***
CANTTBPR:           .equ   $FFFF98BD                                ;*** CANTTBPR - MSCAN Transmit Buffer Priority; 0xFFFF98BD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTTBPR_PRIO0:     .equ   0                                         ; Transmit Buffer Priority Bit 0
CANTTBPR_PRIO1:     .equ   1                                         ; Transmit Buffer Priority Bit 1
CANTTBPR_PRIO2:     .equ   2                                         ; Transmit Buffer Priority Bit 2
CANTTBPR_PRIO3:     .equ   3                                         ; Transmit Buffer Priority Bit 3
CANTTBPR_PRIO4:     .equ   4                                         ; Transmit Buffer Priority Bit 4
CANTTBPR_PRIO5:     .equ   5                                         ; Transmit Buffer Priority Bit 5
CANTTBPR_PRIO6:     .equ   6                                         ; Transmit Buffer Priority Bit 6
CANTTBPR_PRIO7:     .equ   7                                         ; Transmit Buffer Priority Bit 7
; bit position masks
mCANTTBPR_PRIO0:    .equ   %00000001
mCANTTBPR_PRIO1:    .equ   %00000010
mCANTTBPR_PRIO2:    .equ   %00000100
mCANTTBPR_PRIO3:    .equ   %00001000
mCANTTBPR_PRIO4:    .equ   %00010000
mCANTTBPR_PRIO5:    .equ   %00100000
mCANTTBPR_PRIO6:    .equ   %01000000
mCANTTBPR_PRIO7:    .equ   %10000000


;*** CANTTSR - MSCAN Transmit Time Stamp Register; 0xFFFF98BE ***
CANTTSR:            .equ   $FFFF98BE                                ;*** CANTTSR - MSCAN Transmit Time Stamp Register; 0xFFFF98BE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTTSR_TSR0:       .equ   0                                         ; Time Stamp Bit 0
CANTTSR_TSR1:       .equ   1                                         ; Time Stamp Bit 1
CANTTSR_TSR2:       .equ   2                                         ; Time Stamp Bit 2
CANTTSR_TSR3:       .equ   3                                         ; Time Stamp Bit 3
CANTTSR_TSR4:       .equ   4                                         ; Time Stamp Bit 4
CANTTSR_TSR5:       .equ   5                                         ; Time Stamp Bit 5
CANTTSR_TSR6:       .equ   6                                         ; Time Stamp Bit 6
CANTTSR_TSR7:       .equ   7                                         ; Time Stamp Bit 7
CANTTSR_TSR8:       .equ   8                                         ; Time Stamp Bit 8
CANTTSR_TSR9:       .equ   9                                         ; Time Stamp Bit 9
CANTTSR_TSR10:      .equ   10                                        ; Time Stamp Bit 10
CANTTSR_TSR11:      .equ   11                                        ; Time Stamp Bit 11
CANTTSR_TSR12:      .equ   12                                        ; Time Stamp Bit 12
CANTTSR_TSR13:      .equ   13                                        ; Time Stamp Bit 13
CANTTSR_TSR14:      .equ   14                                        ; Time Stamp Bit 14
CANTTSR_TSR15:      .equ   15                                        ; Time Stamp Bit 15
; bit position masks
mCANTTSR_TSR0:      .equ   %00000001
mCANTTSR_TSR1:      .equ   %00000010
mCANTTSR_TSR2:      .equ   %00000100
mCANTTSR_TSR3:      .equ   %00001000
mCANTTSR_TSR4:      .equ   %00010000
mCANTTSR_TSR5:      .equ   %00100000
mCANTTSR_TSR6:      .equ   %01000000
mCANTTSR_TSR7:      .equ   %10000000
mCANTTSR_TSR8:      .equ   %100000000
mCANTTSR_TSR9:      .equ   %1000000000
mCANTTSR_TSR10:     .equ   %10000000000
mCANTTSR_TSR11:     .equ   %100000000000
mCANTTSR_TSR12:     .equ   %1000000000000
mCANTTSR_TSR13:     .equ   %10000000000000
mCANTTSR_TSR14:     .equ   %100000000000000
mCANTTSR_TSR15:     .equ   %1000000000000000


;*** CANTTSRH - MSCAN Transmit Time Stamp Register High; 0xFFFF98BE ***
CANTTSRH:           .equ   $FFFF98BE                                ;*** CANTTSRH - MSCAN Transmit Time Stamp Register High; 0xFFFF98BE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTTSRH_TSR8:      .equ   0                                         ; Time Stamp Bit 8
CANTTSRH_TSR9:      .equ   1                                         ; Time Stamp Bit 9
CANTTSRH_TSR10:     .equ   2                                         ; Time Stamp Bit 10
CANTTSRH_TSR11:     .equ   3                                         ; Time Stamp Bit 11
CANTTSRH_TSR12:     .equ   4                                         ; Time Stamp Bit 12
CANTTSRH_TSR13:     .equ   5                                         ; Time Stamp Bit 13
CANTTSRH_TSR14:     .equ   6                                         ; Time Stamp Bit 14
CANTTSRH_TSR15:     .equ   7                                         ; Time Stamp Bit 15
; bit position masks
mCANTTSRH_TSR8:     .equ   %00000001
mCANTTSRH_TSR9:     .equ   %00000010
mCANTTSRH_TSR10:    .equ   %00000100
mCANTTSRH_TSR11:    .equ   %00001000
mCANTTSRH_TSR12:    .equ   %00010000
mCANTTSRH_TSR13:    .equ   %00100000
mCANTTSRH_TSR14:    .equ   %01000000
mCANTTSRH_TSR15:    .equ   %10000000


;*** CANTTSRL - MSCAN Transmit Time Stamp Register Low; 0xFFFF98BF ***
CANTTSRL:           .equ   $FFFF98BF                                ;*** CANTTSRL - MSCAN Transmit Time Stamp Register Low; 0xFFFF98BF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CANTTSRL_TSR0:      .equ   0                                         ; Time Stamp Bit 0
CANTTSRL_TSR1:      .equ   1                                         ; Time Stamp Bit 1
CANTTSRL_TSR2:      .equ   2                                         ; Time Stamp Bit 2
CANTTSRL_TSR3:      .equ   3                                         ; Time Stamp Bit 3
CANTTSRL_TSR4:      .equ   4                                         ; Time Stamp Bit 4
CANTTSRL_TSR5:      .equ   5                                         ; Time Stamp Bit 5
CANTTSRL_TSR6:      .equ   6                                         ; Time Stamp Bit 6
CANTTSRL_TSR7:      .equ   7                                         ; Time Stamp Bit 7
; bit position masks
mCANTTSRL_TSR0:     .equ   %00000001
mCANTTSRL_TSR1:     .equ   %00000010
mCANTTSRL_TSR2:     .equ   %00000100
mCANTTSRL_TSR3:     .equ   %00001000
mCANTTSRL_TSR4:     .equ   %00010000
mCANTTSRL_TSR5:     .equ   %00100000
mCANTTSRL_TSR6:     .equ   %01000000
mCANTTSRL_TSR7:     .equ   %10000000


;*** RNGCR - Control Register; 0xFFFF98C0 ***
RNGCR:              .equ   $FFFF98C0                                ;*** RNGCR - Control Register; 0xFFFF98C0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RNGCR_GO:           .equ   0                                         ; Output register random data loading control
RNGCR_HA:           .equ   1                                         ; High Assurance
RNGCR_IM:           .equ   2                                         ; Interrupt Mask
RNGCR_CI:           .equ   3                                         ; Clear interrupt
RNGCR_SLM:          .equ   4                                         ; Sleep mode control bit
; bit position masks
mRNGCR_GO:          .equ   %00000001
mRNGCR_HA:          .equ   %00000010
mRNGCR_IM:          .equ   %00000100
mRNGCR_CI:          .equ   %00001000
mRNGCR_SLM:         .equ   %00010000


;*** RNGSR - Status Register; 0xFFFF98C4 ***
RNGSR:              .equ   $FFFF98C4                                ;*** RNGSR - Status Register; 0xFFFF98C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RNGSR_SV:           .equ   0                                         ; Security Violation
RNGSR_LRS:          .equ   1                                         ; Last Read Status
RNGSR_OUF:          .equ   2                                         ; Output Register Underflow
RNGSR_EI:           .equ   3                                         ; Error Interrupt
RNGSR_SLP:          .equ   4                                         ; Sleep
RNGSR_ORL0:         .equ   8                                         ; Output Register Level, bit 0
RNGSR_ORL1:         .equ   9                                         ; Output Register Level, bit 1
RNGSR_ORL2:         .equ   10                                        ; Output Register Level, bit 2
RNGSR_ORL3:         .equ   11                                        ; Output Register Level, bit 3
RNGSR_ORL4:         .equ   12                                        ; Output Register Level, bit 4
RNGSR_ORL5:         .equ   13                                        ; Output Register Level, bit 5
RNGSR_ORL6:         .equ   14                                        ; Output Register Level, bit 6
RNGSR_ORL7:         .equ   15                                        ; Output Register Level, bit 7
RNGSR_ORS0:         .equ   16                                        ; Output Register Size, bit 0
RNGSR_ORS1:         .equ   17                                        ; Output Register Size, bit 1
RNGSR_ORS2:         .equ   18                                        ; Output Register Size, bit 2
RNGSR_ORS3:         .equ   19                                        ; Output Register Size, bit 3
RNGSR_ORS4:         .equ   20                                        ; Output Register Size, bit 4
RNGSR_ORS5:         .equ   21                                        ; Output Register Size, bit 5
RNGSR_ORS6:         .equ   22                                        ; Output Register Size, bit 6
RNGSR_ORS7:         .equ   23                                        ; Output Register Size, bit 7
RNGSR_OD:           .equ   31                                        ; Oscillator clocks verification
; bit position masks
mRNGSR_SV:          .equ   %00000001
mRNGSR_LRS:         .equ   %00000010
mRNGSR_OUF:         .equ   %00000100
mRNGSR_EI:          .equ   %00001000
mRNGSR_SLP:         .equ   %00010000
mRNGSR_ORL0:        .equ   %100000000
mRNGSR_ORL1:        .equ   %1000000000
mRNGSR_ORL2:        .equ   %10000000000
mRNGSR_ORL3:        .equ   %100000000000
mRNGSR_ORL4:        .equ   %1000000000000
mRNGSR_ORL5:        .equ   %10000000000000
mRNGSR_ORL6:        .equ   %100000000000000
mRNGSR_ORL7:        .equ   %1000000000000000
mRNGSR_ORS0:        .equ   %10000000000000000
mRNGSR_ORS1:        .equ   %100000000000000000
mRNGSR_ORS2:        .equ   %1000000000000000000
mRNGSR_ORS3:        .equ   %10000000000000000000
mRNGSR_ORS4:        .equ   %100000000000000000000
mRNGSR_ORS5:        .equ   %1000000000000000000000
mRNGSR_ORS6:        .equ   %10000000000000000000000
mRNGSR_ORS7:        .equ   %100000000000000000000000
mRNGSR_OD:          .equ   %10000000000000000000000000000000


;*** RNGER - Entropy Register; 0xFFFF98C8 ***
RNGER:              .equ   $FFFF98C8                                ;*** RNGER - Entropy Register; 0xFFFF98C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RNGER_ENT0:         .equ   0                                         ; External Entropy, bit 0
RNGER_ENT1:         .equ   1                                         ; External Entropy, bit 1
RNGER_ENT2:         .equ   2                                         ; External Entropy, bit 2
RNGER_ENT3:         .equ   3                                         ; External Entropy, bit 3
RNGER_ENT4:         .equ   4                                         ; External Entropy, bit 4
RNGER_ENT5:         .equ   5                                         ; External Entropy, bit 5
RNGER_ENT6:         .equ   6                                         ; External Entropy, bit 6
RNGER_ENT7:         .equ   7                                         ; External Entropy, bit 7
RNGER_ENT8:         .equ   8                                         ; External Entropy, bit 8
RNGER_ENT9:         .equ   9                                         ; External Entropy, bit 9
RNGER_ENT10:        .equ   10                                        ; External Entropy, bit 10
RNGER_ENT11:        .equ   11                                        ; External Entropy, bit 11
RNGER_ENT12:        .equ   12                                        ; External Entropy, bit 12
RNGER_ENT13:        .equ   13                                        ; External Entropy, bit 13
RNGER_ENT14:        .equ   14                                        ; External Entropy, bit 14
RNGER_ENT15:        .equ   15                                        ; External Entropy, bit 15
RNGER_ENT16:        .equ   16                                        ; External Entropy, bit 16
RNGER_ENT17:        .equ   17                                        ; External Entropy, bit 17
RNGER_ENT18:        .equ   18                                        ; External Entropy, bit 18
RNGER_ENT19:        .equ   19                                        ; External Entropy, bit 19
RNGER_ENT20:        .equ   20                                        ; External Entropy, bit 20
RNGER_ENT21:        .equ   21                                        ; External Entropy, bit 21
RNGER_ENT22:        .equ   22                                        ; External Entropy, bit 22
RNGER_ENT23:        .equ   23                                        ; External Entropy, bit 23
RNGER_ENT24:        .equ   24                                        ; External Entropy, bit 24
RNGER_ENT25:        .equ   25                                        ; External Entropy, bit 25
RNGER_ENT26:        .equ   26                                        ; External Entropy, bit 26
RNGER_ENT27:        .equ   27                                        ; External Entropy, bit 27
RNGER_ENT28:        .equ   28                                        ; External Entropy, bit 28
RNGER_ENT29:        .equ   29                                        ; External Entropy, bit 29
RNGER_ENT30:        .equ   30                                        ; External Entropy, bit 30
RNGER_ENT31:        .equ   31                                        ; External Entropy, bit 31
; bit position masks
mRNGER_ENT0:        .equ   %00000001
mRNGER_ENT1:        .equ   %00000010
mRNGER_ENT2:        .equ   %00000100
mRNGER_ENT3:        .equ   %00001000
mRNGER_ENT4:        .equ   %00010000
mRNGER_ENT5:        .equ   %00100000
mRNGER_ENT6:        .equ   %01000000
mRNGER_ENT7:        .equ   %10000000
mRNGER_ENT8:        .equ   %100000000
mRNGER_ENT9:        .equ   %1000000000
mRNGER_ENT10:       .equ   %10000000000
mRNGER_ENT11:       .equ   %100000000000
mRNGER_ENT12:       .equ   %1000000000000
mRNGER_ENT13:       .equ   %10000000000000
mRNGER_ENT14:       .equ   %100000000000000
mRNGER_ENT15:       .equ   %1000000000000000
mRNGER_ENT16:       .equ   %10000000000000000
mRNGER_ENT17:       .equ   %100000000000000000
mRNGER_ENT18:       .equ   %1000000000000000000
mRNGER_ENT19:       .equ   %10000000000000000000
mRNGER_ENT20:       .equ   %100000000000000000000
mRNGER_ENT21:       .equ   %1000000000000000000000
mRNGER_ENT22:       .equ   %10000000000000000000000
mRNGER_ENT23:       .equ   %100000000000000000000000
mRNGER_ENT24:       .equ   %1000000000000000000000000
mRNGER_ENT25:       .equ   %10000000000000000000000000
mRNGER_ENT26:       .equ   %100000000000000000000000000
mRNGER_ENT27:       .equ   %1000000000000000000000000000
mRNGER_ENT28:       .equ   %10000000000000000000000000000
mRNGER_ENT29:       .equ   %100000000000000000000000000000
mRNGER_ENT30:       .equ   %1000000000000000000000000000000
mRNGER_ENT31:       .equ   %10000000000000000000000000000000


;*** RNGOUT - Output Register; 0xFFFF98CC ***
RNGOUT:             .equ   $FFFF98CC                                ;*** RNGOUT - Output Register; 0xFFFF98CC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RNGOUT_RANDOM_OUTPUT0: .equ   0                                      ; Random Output, bit 0
RNGOUT_RANDOM_OUTPUT1: .equ   1                                      ; Random Output, bit 1
RNGOUT_RANDOM_OUTPUT2: .equ   2                                      ; Random Output, bit 2
RNGOUT_RANDOM_OUTPUT3: .equ   3                                      ; Random Output, bit 3
RNGOUT_RANDOM_OUTPUT4: .equ   4                                      ; Random Output, bit 4
RNGOUT_RANDOM_OUTPUT5: .equ   5                                      ; Random Output, bit 5
RNGOUT_RANDOM_OUTPUT6: .equ   6                                      ; Random Output, bit 6
RNGOUT_RANDOM_OUTPUT7: .equ   7                                      ; Random Output, bit 7
RNGOUT_RANDOM_OUTPUT8: .equ   8                                      ; Random Output, bit 8
RNGOUT_RANDOM_OUTPUT9: .equ   9                                      ; Random Output, bit 9
RNGOUT_RANDOM_OUTPUT10: .equ   10                                    ; Random Output, bit 10
RNGOUT_RANDOM_OUTPUT11: .equ   11                                    ; Random Output, bit 11
RNGOUT_RANDOM_OUTPUT12: .equ   12                                    ; Random Output, bit 12
RNGOUT_RANDOM_OUTPUT13: .equ   13                                    ; Random Output, bit 13
RNGOUT_RANDOM_OUTPUT14: .equ   14                                    ; Random Output, bit 14
RNGOUT_RANDOM_OUTPUT15: .equ   15                                    ; Random Output, bit 15
RNGOUT_RANDOM_OUTPUT16: .equ   16                                    ; Random Output, bit 16
RNGOUT_RANDOM_OUTPUT17: .equ   17                                    ; Random Output, bit 17
RNGOUT_RANDOM_OUTPUT18: .equ   18                                    ; Random Output, bit 18
RNGOUT_RANDOM_OUTPUT19: .equ   19                                    ; Random Output, bit 19
RNGOUT_RANDOM_OUTPUT20: .equ   20                                    ; Random Output, bit 20
RNGOUT_RANDOM_OUTPUT21: .equ   21                                    ; Random Output, bit 21
RNGOUT_RANDOM_OUTPUT22: .equ   22                                    ; Random Output, bit 22
RNGOUT_RANDOM_OUTPUT23: .equ   23                                    ; Random Output, bit 23
RNGOUT_RANDOM_OUTPUT24: .equ   24                                    ; Random Output, bit 24
RNGOUT_RANDOM_OUTPUT25: .equ   25                                    ; Random Output, bit 25
RNGOUT_RANDOM_OUTPUT26: .equ   26                                    ; Random Output, bit 26
RNGOUT_RANDOM_OUTPUT27: .equ   27                                    ; Random Output, bit 27
RNGOUT_RANDOM_OUTPUT28: .equ   28                                    ; Random Output, bit 28
RNGOUT_RANDOM_OUTPUT29: .equ   29                                    ; Random Output, bit 29
RNGOUT_RANDOM_OUTPUT30: .equ   30                                    ; Random Output, bit 30
RNGOUT_RANDOM_OUTPUT31: .equ   31                                    ; Random Output, bit 31
; bit position masks
mRNGOUT_RANDOM_OUTPUT0: .equ   %00000001
mRNGOUT_RANDOM_OUTPUT1: .equ   %00000010
mRNGOUT_RANDOM_OUTPUT2: .equ   %00000100
mRNGOUT_RANDOM_OUTPUT3: .equ   %00001000
mRNGOUT_RANDOM_OUTPUT4: .equ   %00010000
mRNGOUT_RANDOM_OUTPUT5: .equ   %00100000
mRNGOUT_RANDOM_OUTPUT6: .equ   %01000000
mRNGOUT_RANDOM_OUTPUT7: .equ   %10000000
mRNGOUT_RANDOM_OUTPUT8: .equ   %100000000
mRNGOUT_RANDOM_OUTPUT9: .equ   %1000000000
mRNGOUT_RANDOM_OUTPUT10: .equ   %10000000000
mRNGOUT_RANDOM_OUTPUT11: .equ   %100000000000
mRNGOUT_RANDOM_OUTPUT12: .equ   %1000000000000
mRNGOUT_RANDOM_OUTPUT13: .equ   %10000000000000
mRNGOUT_RANDOM_OUTPUT14: .equ   %100000000000000
mRNGOUT_RANDOM_OUTPUT15: .equ   %1000000000000000
mRNGOUT_RANDOM_OUTPUT16: .equ   %10000000000000000
mRNGOUT_RANDOM_OUTPUT17: .equ   %100000000000000000
mRNGOUT_RANDOM_OUTPUT18: .equ   %1000000000000000000
mRNGOUT_RANDOM_OUTPUT19: .equ   %10000000000000000000
mRNGOUT_RANDOM_OUTPUT20: .equ   %100000000000000000000
mRNGOUT_RANDOM_OUTPUT21: .equ   %1000000000000000000000
mRNGOUT_RANDOM_OUTPUT22: .equ   %10000000000000000000000
mRNGOUT_RANDOM_OUTPUT23: .equ   %100000000000000000000000
mRNGOUT_RANDOM_OUTPUT24: .equ   %1000000000000000000000000
mRNGOUT_RANDOM_OUTPUT25: .equ   %10000000000000000000000000
mRNGOUT_RANDOM_OUTPUT26: .equ   %100000000000000000000000000
mRNGOUT_RANDOM_OUTPUT27: .equ   %1000000000000000000000000000
mRNGOUT_RANDOM_OUTPUT28: .equ   %10000000000000000000000000000
mRNGOUT_RANDOM_OUTPUT29: .equ   %100000000000000000000000000000
mRNGOUT_RANDOM_OUTPUT30: .equ   %1000000000000000000000000000000
mRNGOUT_RANDOM_OUTPUT31: .equ   %10000000000000000000000000000000


;*** PER_ID - Peripherial ID Register; 0xFFFF9A00 ***
PER_ID:             .equ   $FFFF9A00                                ;*** PER_ID - Peripherial ID Register; 0xFFFF9A00 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PER_ID_ID0:         .equ   0                                         ; Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 0
PER_ID_ID1:         .equ   1                                         ; Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 1
PER_ID_ID2:         .equ   2                                         ; Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 2
PER_ID_ID3:         .equ   3                                         ; Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 3
PER_ID_ID4:         .equ   4                                         ; Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 4
PER_ID_ID5:         .equ   5                                         ; Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 5
; bit position masks
mPER_ID_ID0:        .equ   %00000001
mPER_ID_ID1:        .equ   %00000010
mPER_ID_ID2:        .equ   %00000100
mPER_ID_ID3:        .equ   %00001000
mPER_ID_ID4:        .equ   %00010000
mPER_ID_ID5:        .equ   %00100000


;*** ID_COMP - Peripheral ID Complement Register; 0xFFFF9A04 ***
ID_COMP:            .equ   $FFFF9A04                                ;*** ID_COMP - Peripheral ID Complement Register; 0xFFFF9A04 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ID_COMP_NID0:       .equ   0                                         ; Ones complement of peripheral identification bits, bit 0
ID_COMP_NID1:       .equ   1                                         ; Ones complement of peripheral identification bits, bit 1
ID_COMP_NID2:       .equ   2                                         ; Ones complement of peripheral identification bits, bit 2
ID_COMP_NID3:       .equ   3                                         ; Ones complement of peripheral identification bits, bit 3
ID_COMP_NID4:       .equ   4                                         ; Ones complement of peripheral identification bits, bit 4
ID_COMP_NID5:       .equ   5                                         ; Ones complement of peripheral identification bits, bit 5
; bit position masks
mID_COMP_NID0:      .equ   %00000001
mID_COMP_NID1:      .equ   %00000010
mID_COMP_NID2:      .equ   %00000100
mID_COMP_NID3:      .equ   %00001000
mID_COMP_NID4:      .equ   %00010000
mID_COMP_NID5:      .equ   %00100000


;*** REV - Peripheral Revision Register; 0xFFFF9A08 ***
REV:                .equ   $FFFF9A08                                ;*** REV - Peripheral Revision Register; 0xFFFF9A08 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REV_REV0:           .equ   0                                         ; Revision number indicate the revision number of the USB Core, bit 0
REV_REV1:           .equ   1                                         ; Revision number indicate the revision number of the USB Core, bit 1
REV_REV2:           .equ   2                                         ; Revision number indicate the revision number of the USB Core, bit 2
REV_REV3:           .equ   3                                         ; Revision number indicate the revision number of the USB Core, bit 3
REV_REV4:           .equ   4                                         ; Revision number indicate the revision number of the USB Core, bit 4
REV_REV5:           .equ   5                                         ; Revision number indicate the revision number of the USB Core, bit 5
REV_REV6:           .equ   6                                         ; Revision number indicate the revision number of the USB Core, bit 6
REV_REV7:           .equ   7                                         ; Revision number indicate the revision number of the USB Core, bit 7
; bit position masks
mREV_REV0:          .equ   %00000001
mREV_REV1:          .equ   %00000010
mREV_REV2:          .equ   %00000100
mREV_REV3:          .equ   %00001000
mREV_REV4:          .equ   %00010000
mREV_REV5:          .equ   %00100000
mREV_REV6:          .equ   %01000000
mREV_REV7:          .equ   %10000000


;*** ADD_INFO - Peripheral Additional Info Register; 0xFFFF9A0C ***
ADD_INFO:           .equ   $FFFF9A0C                                ;*** ADD_INFO - Peripheral Additional Info Register; 0xFFFF9A0C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADD_INFO_IEHOST:    .equ   0                                         ; This bit will be set if host mode is enabled
ADD_INFO_IRQ_NUM0:  .equ   3                                         ; Assigned Interrupt Request Number, bit 0
ADD_INFO_IRQ_NUM1:  .equ   4                                         ; Assigned Interrupt Request Number, bit 1
ADD_INFO_IRQ_NUM2:  .equ   5                                         ; Assigned Interrupt Request Number, bit 2
ADD_INFO_IRQ_NUM3:  .equ   6                                         ; Assigned Interrupt Request Number, bit 3
ADD_INFO_IRQ_NUM4:  .equ   7                                         ; Assigned Interrupt Request Number, bit 4
; bit position masks
mADD_INFO_IEHOST:   .equ   %00000001
mADD_INFO_IRQ_NUM0: .equ   %00001000
mADD_INFO_IRQ_NUM1: .equ   %00010000
mADD_INFO_IRQ_NUM2: .equ   %00100000
mADD_INFO_IRQ_NUM3: .equ   %01000000
mADD_INFO_IRQ_NUM4: .equ   %10000000


;*** OTG_INT_STAT - OTG Interrupt Status Register; 0xFFFF9A10 ***
OTG_INT_STAT:       .equ   $FFFF9A10                                ;*** OTG_INT_STAT - OTG Interrupt Status Register; 0xFFFF9A10 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OTG_INT_STAT_A_VBUS_CHG: .equ   0                                    ; This bit is set when a change in VBUS is detected on an &quot;A&quot; device
OTG_INT_STAT_B_SESS_CHG: .equ   2                                    ; This bit is set when a change in VBUS is detected on a &quot;B&quot; device
OTG_INT_STAT_SESS_VLD_CHG: .equ   3                                  ; This bit is set when a change in VBUS is detected indicating a session valid or a session no longer valid
OTG_INT_STAT_LINE_STATE_CHG: .equ   5                                ; This bit is set when the USB line state changes. The interrupt associated with this bit can be used to detect Reset, Resume, Connect, and Data Line Pulse signals
OTG_INT_STAT_ONE_MSEC: .equ   6                                      ; This bit is set when the 1 millisecond timer expires. This bit stays asserted until clered by software. The interrupt must be serviced every millisecond to avoid losing 1msec counts
OTG_INT_STAT_ID_CHG: .equ   7                                        ; This bit is set when a change in the ID Signal from the USB connector is sensed
; bit position masks
mOTG_INT_STAT_A_VBUS_CHG: .equ   %00000001
mOTG_INT_STAT_B_SESS_CHG: .equ   %00000100
mOTG_INT_STAT_SESS_VLD_CHG: .equ   %00001000
mOTG_INT_STAT_LINE_STATE_CHG: .equ   %00100000
mOTG_INT_STAT_ONE_MSEC: .equ   %01000000
mOTG_INT_STAT_ID_CHG: .equ   %10000000


;*** OTG_INT_EN - OTG Interrupt Control Register; 0xFFFF9A14 ***
OTG_INT_EN:         .equ   $FFFF9A14                                ;*** OTG_INT_EN - OTG Interrupt Control Register; 0xFFFF9A14 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OTG_INT_EN_A_VBUS_EN: .equ   0                                       ; &quot;A&quot; VBUS Valid interrupt enable
OTG_INT_EN_B_SESS_EN: .equ   2                                       ; &quot;B&quot; Session END interrupt enable
OTG_INT_EN_SESS_VLD_EN: .equ   3                                     ; Session valid interrupt enable
OTG_INT_EN_LINE_STATE_EN: .equ   5                                   ; Line State change interrupt enable
OTG_INT_EN_ONE_MSEC_EN: .equ   6                                     ; 1 millisecond interrupt enable
OTG_INT_EN_ID_EN:   .equ   7                                         ; ID interrupt enable
; bit position masks
mOTG_INT_EN_A_VBUS_EN: .equ   %00000001
mOTG_INT_EN_B_SESS_EN: .equ   %00000100
mOTG_INT_EN_SESS_VLD_EN: .equ   %00001000
mOTG_INT_EN_LINE_STATE_EN: .equ   %00100000
mOTG_INT_EN_ONE_MSEC_EN: .equ   %01000000
mOTG_INT_EN_ID_EN:  .equ   %10000000


;*** OTG_STAT - Interrupt Status Register; 0xFFFF9A18 ***
OTG_STAT:           .equ   $FFFF9A18                                ;*** OTG_STAT - Interrupt Status Register; 0xFFFF9A18 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OTG_STAT_A_VBUS_VLD: .equ   0                                        ; &quot;A&quot; VBUS Valid
OTG_STAT_B_SESS_END: .equ   2                                        ; &quot;B&quot; Session END
OTG_STAT_SESS_VLD:  .equ   3                                         ; Session Valid
OTG_STAT_LINE_STATE_STABLE: .equ   5                                 ; This bit indicates that the internal signals which control the LINE_STATE_CHG bit (bit 5) of the OTG_INT_STAT register have been stable for at least 1 millisecond
OTG_STAT_ONE_MSEC_EN: .equ   6                                       ; This bit is reserved for the 1msec count, but it is not useful to software
OTG_STAT_ID:        .equ   7                                         ; Indicates the current state of the ID pin on the USB connector
; bit position masks
mOTG_STAT_A_VBUS_VLD: .equ   %00000001
mOTG_STAT_B_SESS_END: .equ   %00000100
mOTG_STAT_SESS_VLD: .equ   %00001000
mOTG_STAT_LINE_STATE_STABLE: .equ   %00100000
mOTG_STAT_ONE_MSEC_EN: .equ   %01000000
mOTG_STAT_ID:       .equ   %10000000


;*** OTG_CTRL - OTG Control Register; 0xFFFF9A1C ***
OTG_CTRL:           .equ   $FFFF9A1C                                ;*** OTG_CTRL - OTG Control Register; 0xFFFF9A1C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OTG_CTRL_OTG_EN:    .equ   2                                         ; On-The-Go pull-up/pull-down resistor enable
OTG_CTRL_DM_LOW:    .equ   4                                         ; D- Data Line pull-down resistor enable. This bit should always be enabled together with bit 5 (DP_LOW)
OTG_CTRL_DP_LOW:    .equ   5                                         ; D+ Data Line pull-down resistor enable. This bit should always be enabled together with bit 4 (DM_LOW)
OTG_CTRL_DP_HIGH:   .equ   7                                         ; D+ Data Line pull-up resistor enable
; bit position masks
mOTG_CTRL_OTG_EN:   .equ   %00000100
mOTG_CTRL_DM_LOW:   .equ   %00010000
mOTG_CTRL_DP_LOW:   .equ   %00100000
mOTG_CTRL_DP_HIGH:  .equ   %10000000


;*** INT_STAT - Interrupt Status Register; 0xFFFF9A80 ***
INT_STAT:           .equ   $FFFF9A80                                ;*** INT_STAT - Interrupt Status Register; 0xFFFF9A80 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_STAT_USB_RST:   .equ   0                                         ; This bit is set when the USB Module has decoded a valid USB reset
INT_STAT_ERROR:     .equ   1                                         ; This bit is set when any of the error conditions within the ERR_STAT register occur. The ColdFire core must then read the ERR_STAT register to determine the source of the error
INT_STAT_SOF_TOK:   .equ   2                                         ; This bit is set when the USB Module receives a Start Of Frame (SOF) token. In Host mode this bit is set when the SOF threshold is reached, so that software can prepare for the next SOF
INT_STAT_TOK_DNE:   .equ   3                                         ; This bit is set when the current token being processed has completed
INT_STAT_SLEEP:     .equ   4                                         ; This bit is set when the USB Module detects a constant idle on the USB bus for 3 milliseconds. The sleep timer is reset by activity on the USB bus
INT_STAT_RESUME:    .equ   5                                         ; This bit is set depending upon the DP/DM signals, and can be used to signal remote wake-up signaling on the USB bus. When not in suspend mode this interrupt should be disabled
INT_STAT_ATTACH:    .equ   6                                         ; Attach Interrupt. This bit is set when the USB Module detects an attach of a USB device. This signal is only valid if HOST_MODE_EN is true. This interrupt signifies that a peripheral is now present and must be configured
INT_STAT_STALL:     .equ   7                                         ; Stall Interrupt. In Target mode this bit is asserted when a STALL handshake is sent by the SIE. In Host mode this bit is set when the USB Module detects a STALL acknowledge during the handshake phase of a USB transaction
; bit position masks
mINT_STAT_USB_RST:  .equ   %00000001
mINT_STAT_ERROR:    .equ   %00000010
mINT_STAT_SOF_TOK:  .equ   %00000100
mINT_STAT_TOK_DNE:  .equ   %00001000
mINT_STAT_SLEEP:    .equ   %00010000
mINT_STAT_RESUME:   .equ   %00100000
mINT_STAT_ATTACH:   .equ   %01000000
mINT_STAT_STALL:    .equ   %10000000


;*** INT_ENB - Interrupt Enable Register; 0xFFFF9A84 ***
INT_ENB:            .equ   $FFFF9A84                                ;*** INT_ENB - Interrupt Enable Register; 0xFFFF9A84 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_ENB_USB_RST_EN: .equ   0                                         ; USB_RST Interrupt Enable
INT_ENB_ERROR_EN:   .equ   1                                         ; ERROR Interrupt Enable
INT_ENB_SOF_TOK_EN: .equ   2                                         ; SOF_TOK Interrupt Enable
INT_ENB_TOK_DNE_EN: .equ   3                                         ; TOK_DNE Interrupt Enable
INT_ENB_SLEEP_EN:   .equ   4                                         ; SLEEP Interrupt Enable
INT_ENB_RESUME_EN:  .equ   5                                         ; RESUME Interrupt Enable
INT_ENB_ATTACH_EN:  .equ   6                                         ; ATTACH Interrupt Enable
INT_ENB_STALL_EN:   .equ   7                                         ; STALL Interrupt Enable
; bit position masks
mINT_ENB_USB_RST_EN: .equ   %00000001
mINT_ENB_ERROR_EN:  .equ   %00000010
mINT_ENB_SOF_TOK_EN: .equ   %00000100
mINT_ENB_TOK_DNE_EN: .equ   %00001000
mINT_ENB_SLEEP_EN:  .equ   %00010000
mINT_ENB_RESUME_EN: .equ   %00100000
mINT_ENB_ATTACH_EN: .equ   %01000000
mINT_ENB_STALL_EN:  .equ   %10000000


;*** ERR_STAT - Error Interrupt Status Register; 0xFFFF9A88 ***
ERR_STAT:           .equ   $FFFF9A88                                ;*** ERR_STAT - Error Interrupt Status Register; 0xFFFF9A88 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ERR_STAT_PID_ERR:   .equ   0                                         ; This bit is set when the PID check field fails
ERR_STAT_CRC5_EOF:  .equ   1                                         ; When the USB Module is operating in Peripheral mode (HOST_MODE_EN=0) this interrupt will detect CRC5 errors in the token packets generated by the host. When the USB Module is operating in Host mode (HOST_MODE_EN=1) this interupt will detect End Of Frame...
ERR_STAT_CRC16:     .equ   2                                         ; This bit is set when a data packet is rejected due to a CRC16 error
ERR_STAT_DFN8:      .equ   3                                         ; This bit is set if the dta field received was not 8 bits in length. USB Specification 1.0 requires that data fields be an integral number of bytes. If the data field was not an integral number of bytes this bit will be set
ERR_STAT_BTO_ERR:   .equ   4                                         ; This bit is set when a bus turnaround timeout error occurs
ERR_STAT_DMA_ERR:   .equ   5                                         ; This bit is set if the USB Module has requested a DMA access to read a new BDT but has not been given the bus before it needs to receive or transmit data
ERR_STAT_BTS_ERR:   .equ   7                                         ; This bit is set when a bit stuff error is detected. If set the corresponding packet will be rejected due to the error
; bit position masks
mERR_STAT_PID_ERR:  .equ   %00000001
mERR_STAT_CRC5_EOF: .equ   %00000010
mERR_STAT_CRC16:    .equ   %00000100
mERR_STAT_DFN8:     .equ   %00001000
mERR_STAT_BTO_ERR:  .equ   %00010000
mERR_STAT_DMA_ERR:  .equ   %00100000
mERR_STAT_BTS_ERR:  .equ   %10000000


;*** ERR_ENB - Error Interrupt Enable Register; 0xFFFF9A8C ***
ERR_ENB:            .equ   $FFFF9A8C                                ;*** ERR_ENB - Error Interrupt Enable Register; 0xFFFF9A8C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ERR_ENB_PID_ERR_EN: .equ   0                                         ; PID_ERR Interrupt Enable
ERR_ENB_CRC5_EOF_EN: .equ   1                                        ; CRC5/EOF Interrupt Enable
ERR_ENB_CRC16_EN:   .equ   2                                         ; CRC16 Interrupt Enable
ERR_ENB_DFN8_EN:    .equ   3                                         ; DFN8 Interrupt Enable
ERR_ENB_BTO_ERR_EN: .equ   4                                         ; BTO_ERR Interrupt Enable
ERR_ENB_DMA_ERR_EN: .equ   5                                         ; DMA_ERR Interrupt Enable
ERR_ENB_BTS_ERR_EN: .equ   7                                         ; BTS_ERR Interrupt Enable
; bit position masks
mERR_ENB_PID_ERR_EN: .equ   %00000001
mERR_ENB_CRC5_EOF_EN: .equ   %00000010
mERR_ENB_CRC16_EN:  .equ   %00000100
mERR_ENB_DFN8_EN:   .equ   %00001000
mERR_ENB_BTO_ERR_EN: .equ   %00010000
mERR_ENB_DMA_ERR_EN: .equ   %00100000
mERR_ENB_BTS_ERR_EN: .equ   %10000000


;*** STAT - Status Register; 0xFFFF9A90 ***
STAT:               .equ   $FFFF9A90                                ;*** STAT - Status Register; 0xFFFF9A90 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
STAT_ODD:           .equ   2                                         ; This bit is set if the last Buffer Descriptor updated was in the odd bank of the BDT
STAT_TX:            .equ   3                                         ; Transmit Indicator
STAT_ENDP0:         .equ   4                                         ; ENDP field, bit 0
STAT_ENDP1:         .equ   5                                         ; ENDP field, bit 1
STAT_ENDP2:         .equ   6                                         ; ENDP field, bit 2
STAT_ENDP3:         .equ   7                                         ; ENDP field, bit 3
; bit position masks
mSTAT_ODD:          .equ   %00000100
mSTAT_TX:           .equ   %00001000
mSTAT_ENDP0:        .equ   %00010000
mSTAT_ENDP1:        .equ   %00100000
mSTAT_ENDP2:        .equ   %01000000
mSTAT_ENDP3:        .equ   %10000000


;*** CTL - Control Register; 0xFFFF9A94 ***
CTL:                .equ   $FFFF9A94                                ;*** CTL - Control Register; 0xFFFF9A94 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CTL_USB_EN_SOF_EN:  .equ   0                                         ; USB Enable. Setting this bit causes the SIE to reset all of its ODD bits to the BDTs. Thus, setting this bit will reset much of the logic in the SIE. when host mode is enabled clearing this bit will cause the SIE to stop sending SOF tokens
CTL_ODD_RST:        .equ   1                                         ; Setting this bit to 1 will reset all the BDT ODD ping/pong bits to 0, which then specifies the EVEN BDT bank
CTL_RESUME:         .equ   2                                         ; When set to 1 this bit enables the USB Module to execute resume signaling
CTL_HOST_MODE_EN:   .equ   3                                         ; When set to 1, this bit enables the USB Module to operate in Host mode. In Host mode the USB Module will perform USB transactions under the programmed control of the host processor
CTL_RESET:          .equ   4                                         ; Setting this bit enables the USB Module to generate USB reset signaling
CTL_TXSUSPEND_TOKENBUSY: .equ   5                                    ; When the USB Module is in Host mode TOKEN_BUSY is set when the USB Module is busy executing a USB token and no more token commands should be written to the Token Register. In Target mode TXD_SUSPEND is set when the SIE has disabled packet transmission a...
CTL_SE0:            .equ   6                                         ; Live USB Single Ended Zero signal
CTL_JSTATE:         .equ   7                                         ; Live USB differential receiver JSTATE signal. The polarity of this signal is affected bythe current state of LS_EN
; bit position masks
mCTL_USB_EN_SOF_EN: .equ   %00000001
mCTL_ODD_RST:       .equ   %00000010
mCTL_RESUME:        .equ   %00000100
mCTL_HOST_MODE_EN:  .equ   %00001000
mCTL_RESET:         .equ   %00010000
mCTL_TXSUSPEND_TOKENBUSY: .equ   %00100000
mCTL_SE0:           .equ   %01000000
mCTL_JSTATE:        .equ   %10000000


;*** ADDR - Address Register; 0xFFFF9A98 ***
ADDR:               .equ   $FFFF9A98                                ;*** ADDR - Address Register; 0xFFFF9A98 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADDR_ADDR0:         .equ   0                                         ; USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 0
ADDR_ADDR1:         .equ   1                                         ; USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 1
ADDR_ADDR2:         .equ   2                                         ; USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 2
ADDR_ADDR3:         .equ   3                                         ; USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 3
ADDR_ADDR4:         .equ   4                                         ; USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 4
ADDR_ADDR5:         .equ   5                                         ; USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 5
ADDR_ADDR6:         .equ   6                                         ; USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 6
ADDR_LS_EN:         .equ   7                                         ; Low Speed Enable bit. This bit uniforms the USB Module that the next token command written to the token register must be performed at low speed. This will enable the USB Module to perform the necessary preamble required for low-speed data transmissions
; bit position masks
mADDR_ADDR0:        .equ   %00000001
mADDR_ADDR1:        .equ   %00000010
mADDR_ADDR2:        .equ   %00000100
mADDR_ADDR3:        .equ   %00001000
mADDR_ADDR4:        .equ   %00010000
mADDR_ADDR5:        .equ   %00100000
mADDR_ADDR6:        .equ   %01000000
mADDR_LS_EN:        .equ   %10000000


;*** BDT_PAGE_01 - BDT Page Register 1; 0xFFFF9A9C ***
BDT_PAGE_01:        .equ   $FFFF9A9C                                ;*** BDT_PAGE_01 - BDT Page Register 1; 0xFFFF9A9C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BDT_PAGE_01_BDT_BA9: .equ   1                                        ; BDT base address bit 9
BDT_PAGE_01_BDT_BA10: .equ   2                                       ; BDT base address bit 10
BDT_PAGE_01_BDT_BA11: .equ   3                                       ; BDT base address bit 11
BDT_PAGE_01_BDT_BA12: .equ   4                                       ; BDT base address bit 12
BDT_PAGE_01_BDT_BA13: .equ   5                                       ; BDT base address bit 13
BDT_PAGE_01_BDT_BA14: .equ   6                                       ; BDT base address bit 14
BDT_PAGE_01_BDT_BA15: .equ   7                                       ; BDT base address bit 15
; bit position masks
mBDT_PAGE_01_BDT_BA9: .equ   %00000010
mBDT_PAGE_01_BDT_BA10: .equ   %00000100
mBDT_PAGE_01_BDT_BA11: .equ   %00001000
mBDT_PAGE_01_BDT_BA12: .equ   %00010000
mBDT_PAGE_01_BDT_BA13: .equ   %00100000
mBDT_PAGE_01_BDT_BA14: .equ   %01000000
mBDT_PAGE_01_BDT_BA15: .equ   %10000000


;*** FRM_NUML - Frame Number Register Low; 0xFFFF9AA0 ***
FRM_NUML:           .equ   $FFFF9AA0                                ;*** FRM_NUML - Frame Number Register Low; 0xFFFF9AA0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRM_NUML_FRM0:      .equ   0                                         ; Frame number bit 0
FRM_NUML_FRM1:      .equ   1                                         ; Frame number bit 1
FRM_NUML_FRM2:      .equ   2                                         ; Frame number bit 2
FRM_NUML_FRM3:      .equ   3                                         ; Frame number bit 3
FRM_NUML_FRM4:      .equ   4                                         ; Frame number bit 4
FRM_NUML_FRM5:      .equ   5                                         ; Frame number bit 5
FRM_NUML_FRM6:      .equ   6                                         ; Frame number bit 6
FRM_NUML_FRM7:      .equ   7                                         ; Frame number bit 7
; bit position masks
mFRM_NUML_FRM0:     .equ   %00000001
mFRM_NUML_FRM1:     .equ   %00000010
mFRM_NUML_FRM2:     .equ   %00000100
mFRM_NUML_FRM3:     .equ   %00001000
mFRM_NUML_FRM4:     .equ   %00010000
mFRM_NUML_FRM5:     .equ   %00100000
mFRM_NUML_FRM6:     .equ   %01000000
mFRM_NUML_FRM7:     .equ   %10000000


;*** FRM_NUMH - Frame Number Register High; 0xFFFF9AA4 ***
FRM_NUMH:           .equ   $FFFF9AA4                                ;*** FRM_NUMH - Frame Number Register High; 0xFFFF9AA4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRM_NUMH_FRM8:      .equ   0                                         ; Frame number bit 8
FRM_NUMH_FRM9:      .equ   1                                         ; Frame number bit 9
FRM_NUMH_FRM10:     .equ   2                                         ; Frame number bit 10
; bit position masks
mFRM_NUMH_FRM8:     .equ   %00000001
mFRM_NUMH_FRM9:     .equ   %00000010
mFRM_NUMH_FRM10:    .equ   %00000100


;*** TOKEN - Token Register; 0xFFFF9AA8 ***
TOKEN:              .equ   $FFFF9AA8                                ;*** TOKEN - Token Register; 0xFFFF9AA8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TOKEN_TOKEN_ENDPT0: .equ   0                                         ; Endpoint address for the token command, bit 0
TOKEN_TOKEN_ENDPT1: .equ   1                                         ; Endpoint address for the token command, bit 1
TOKEN_TOKEN_ENDPT2: .equ   2                                         ; Endpoint address for the token command, bit 2
TOKEN_TOKEN_ENDPT3: .equ   3                                         ; Endpoint address for the token command, bit 3
TOKEN_TOKEN_PID0:   .equ   4                                         ; Token type, bit 0
TOKEN_TOKEN_PID1:   .equ   5                                         ; Token type, bit 1
TOKEN_TOKEN_PID2:   .equ   6                                         ; Token type, bit 2
TOKEN_TOKEN_PID3:   .equ   7                                         ; Token type, bit 3
; bit position masks
mTOKEN_TOKEN_ENDPT0: .equ   %00000001
mTOKEN_TOKEN_ENDPT1: .equ   %00000010
mTOKEN_TOKEN_ENDPT2: .equ   %00000100
mTOKEN_TOKEN_ENDPT3: .equ   %00001000
mTOKEN_TOKEN_PID0:  .equ   %00010000
mTOKEN_TOKEN_PID1:  .equ   %00100000
mTOKEN_TOKEN_PID2:  .equ   %01000000
mTOKEN_TOKEN_PID3:  .equ   %10000000


;*** SOF_THLD - SOF Threshold Register; 0xFFFF9AAC ***
SOF_THLD:           .equ   $FFFF9AAC                                ;*** SOF_THLD - SOF Threshold Register; 0xFFFF9AAC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOF_THLD_CNT0:      .equ   0                                         ; SOF count threshold, bit 0
SOF_THLD_CNT1:      .equ   1                                         ; SOF count threshold, bit 1
SOF_THLD_CNT2:      .equ   2                                         ; SOF count threshold, bit 2
SOF_THLD_CNT3:      .equ   3                                         ; SOF count threshold, bit 3
SOF_THLD_CNT4:      .equ   4                                         ; SOF count threshold, bit 4
SOF_THLD_CNT5:      .equ   5                                         ; SOF count threshold, bit 5
SOF_THLD_CNT6:      .equ   6                                         ; SOF count threshold, bit 6
SOF_THLD_CNT7:      .equ   7                                         ; SOF count threshold, bit 7
; bit position masks
mSOF_THLD_CNT0:     .equ   %00000001
mSOF_THLD_CNT1:     .equ   %00000010
mSOF_THLD_CNT2:     .equ   %00000100
mSOF_THLD_CNT3:     .equ   %00001000
mSOF_THLD_CNT4:     .equ   %00010000
mSOF_THLD_CNT5:     .equ   %00100000
mSOF_THLD_CNT6:     .equ   %01000000
mSOF_THLD_CNT7:     .equ   %10000000


;*** BDT_PAGE_02 - BDT Page Register 2; 0xFFFF9AB0 ***
BDT_PAGE_02:        .equ   $FFFF9AB0                                ;*** BDT_PAGE_02 - BDT Page Register 2; 0xFFFF9AB0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BDT_PAGE_02_BDT_BA16: .equ   0                                       ; BDT base address bit 16
BDT_PAGE_02_BDT_BA17: .equ   1                                       ; BDT base address bit 17
BDT_PAGE_02_BDT_BA18: .equ   2                                       ; BDT base address bit 18
BDT_PAGE_02_BDT_BA19: .equ   3                                       ; BDT base address bit 19
BDT_PAGE_02_BDT_BA20: .equ   4                                       ; BDT base address bit 20
BDT_PAGE_02_BDT_BA21: .equ   5                                       ; BDT base address bit 21
BDT_PAGE_02_BDT_BA22: .equ   6                                       ; BDT base address bit 22
BDT_PAGE_02_BDT_BA23: .equ   7                                       ; BDT base address bit 23
; bit position masks
mBDT_PAGE_02_BDT_BA16: .equ   %00000001
mBDT_PAGE_02_BDT_BA17: .equ   %00000010
mBDT_PAGE_02_BDT_BA18: .equ   %00000100
mBDT_PAGE_02_BDT_BA19: .equ   %00001000
mBDT_PAGE_02_BDT_BA20: .equ   %00010000
mBDT_PAGE_02_BDT_BA21: .equ   %00100000
mBDT_PAGE_02_BDT_BA22: .equ   %01000000
mBDT_PAGE_02_BDT_BA23: .equ   %10000000


;*** BDT_PAGE_03 - BDT Page Register 3; 0xFFFF9AB4 ***
BDT_PAGE_03:        .equ   $FFFF9AB4                                ;*** BDT_PAGE_03 - BDT Page Register 3; 0xFFFF9AB4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BDT_PAGE_03_BDT_BA24: .equ   0                                       ; BDT base address bit 24
BDT_PAGE_03_BDT_BA25: .equ   1                                       ; BDT base address bit 25
BDT_PAGE_03_BDT_BA26: .equ   2                                       ; BDT base address bit 26
BDT_PAGE_03_BDT_BA27: .equ   3                                       ; BDT base address bit 27
BDT_PAGE_03_BDT_BA28: .equ   4                                       ; BDT base address bit 28
BDT_PAGE_03_BDT_BA29: .equ   5                                       ; BDT base address bit 29
BDT_PAGE_03_BDT_BA30: .equ   6                                       ; BDT base address bit 30
BDT_PAGE_03_BDT_BA31: .equ   7                                       ; BDT base address bit 31
; bit position masks
mBDT_PAGE_03_BDT_BA24: .equ   %00000001
mBDT_PAGE_03_BDT_BA25: .equ   %00000010
mBDT_PAGE_03_BDT_BA26: .equ   %00000100
mBDT_PAGE_03_BDT_BA27: .equ   %00001000
mBDT_PAGE_03_BDT_BA28: .equ   %00010000
mBDT_PAGE_03_BDT_BA29: .equ   %00100000
mBDT_PAGE_03_BDT_BA30: .equ   %01000000
mBDT_PAGE_03_BDT_BA31: .equ   %10000000


;*** ENDPT0 - Endpoint Control Register 0; 0xFFFF9AC0 ***
ENDPT0:             .equ   $FFFF9AC0                                ;*** ENDPT0 - Endpoint Control Register 0; 0xFFFF9AC0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT0_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT0_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT0_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT0_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT0_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT0_RETRY_DIS:   .equ   6                                         ; This is a Host mode only bit and is only present in the control register for endpoint 0 (ENDPT0)
ENDPT0_HOST_WO_HUB: .equ   7                                         ; This is a Host mode only bit and is only present in the control register for endpoint 0 (ENDPT0)
; bit position masks
mENDPT0_EP_HSHK:    .equ   %00000001
mENDPT0_EP_STALL:   .equ   %00000010
mENDPT0_EP_TX_EN:   .equ   %00000100
mENDPT0_EP_RX_EN:   .equ   %00001000
mENDPT0_EP_CTL_DIS: .equ   %00010000
mENDPT0_RETRY_DIS:  .equ   %01000000
mENDPT0_HOST_WO_HUB: .equ   %10000000


;*** ENDPT1 - Endpoint Control Register 1; 0xFFFF9AC4 ***
ENDPT1:             .equ   $FFFF9AC4                                ;*** ENDPT1 - Endpoint Control Register 1; 0xFFFF9AC4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT1_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT1_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT1_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT1_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT1_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT1_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT1_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT1_EP_HSHK:    .equ   %00000001
mENDPT1_EP_STALL:   .equ   %00000010
mENDPT1_EP_TX_EN:   .equ   %00000100
mENDPT1_EP_RX_EN:   .equ   %00001000
mENDPT1_EP_CTL_DIS: .equ   %00010000
mENDPT1_RETRY_DIS:  .equ   %01000000
mENDPT1_HOST_WO_HUB: .equ   %10000000


;*** ENDPT2 - Endpoint Control Register 2; 0xFFFF9AC8 ***
ENDPT2:             .equ   $FFFF9AC8                                ;*** ENDPT2 - Endpoint Control Register 2; 0xFFFF9AC8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT2_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT2_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT2_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT2_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT2_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT2_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT2_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT2_EP_HSHK:    .equ   %00000001
mENDPT2_EP_STALL:   .equ   %00000010
mENDPT2_EP_TX_EN:   .equ   %00000100
mENDPT2_EP_RX_EN:   .equ   %00001000
mENDPT2_EP_CTL_DIS: .equ   %00010000
mENDPT2_RETRY_DIS:  .equ   %01000000
mENDPT2_HOST_WO_HUB: .equ   %10000000


;*** ENDPT3 - Endpoint Control Register 3; 0xFFFF9ACC ***
ENDPT3:             .equ   $FFFF9ACC                                ;*** ENDPT3 - Endpoint Control Register 3; 0xFFFF9ACC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT3_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT3_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT3_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT3_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT3_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT3_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT3_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT3_EP_HSHK:    .equ   %00000001
mENDPT3_EP_STALL:   .equ   %00000010
mENDPT3_EP_TX_EN:   .equ   %00000100
mENDPT3_EP_RX_EN:   .equ   %00001000
mENDPT3_EP_CTL_DIS: .equ   %00010000
mENDPT3_RETRY_DIS:  .equ   %01000000
mENDPT3_HOST_WO_HUB: .equ   %10000000


;*** ENDPT4 - Endpoint Control Register 4; 0xFFFF9AD0 ***
ENDPT4:             .equ   $FFFF9AD0                                ;*** ENDPT4 - Endpoint Control Register 4; 0xFFFF9AD0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT4_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT4_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT4_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT4_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT4_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT4_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT4_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT4_EP_HSHK:    .equ   %00000001
mENDPT4_EP_STALL:   .equ   %00000010
mENDPT4_EP_TX_EN:   .equ   %00000100
mENDPT4_EP_RX_EN:   .equ   %00001000
mENDPT4_EP_CTL_DIS: .equ   %00010000
mENDPT4_RETRY_DIS:  .equ   %01000000
mENDPT4_HOST_WO_HUB: .equ   %10000000


;*** ENDPT5 - Endpoint Control Register 5; 0xFFFF9AD4 ***
ENDPT5:             .equ   $FFFF9AD4                                ;*** ENDPT5 - Endpoint Control Register 5; 0xFFFF9AD4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT5_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT5_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT5_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT5_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT5_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT5_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT5_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT5_EP_HSHK:    .equ   %00000001
mENDPT5_EP_STALL:   .equ   %00000010
mENDPT5_EP_TX_EN:   .equ   %00000100
mENDPT5_EP_RX_EN:   .equ   %00001000
mENDPT5_EP_CTL_DIS: .equ   %00010000
mENDPT5_RETRY_DIS:  .equ   %01000000
mENDPT5_HOST_WO_HUB: .equ   %10000000


;*** ENDPT6 - Endpoint Control Register 6; 0xFFFF9AD8 ***
ENDPT6:             .equ   $FFFF9AD8                                ;*** ENDPT6 - Endpoint Control Register 6; 0xFFFF9AD8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT6_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT6_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT6_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT6_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT6_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT6_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT6_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT6_EP_HSHK:    .equ   %00000001
mENDPT6_EP_STALL:   .equ   %00000010
mENDPT6_EP_TX_EN:   .equ   %00000100
mENDPT6_EP_RX_EN:   .equ   %00001000
mENDPT6_EP_CTL_DIS: .equ   %00010000
mENDPT6_RETRY_DIS:  .equ   %01000000
mENDPT6_HOST_WO_HUB: .equ   %10000000


;*** ENDPT7 - Endpoint Control Register 7; 0xFFFF9ADC ***
ENDPT7:             .equ   $FFFF9ADC                                ;*** ENDPT7 - Endpoint Control Register 7; 0xFFFF9ADC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT7_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT7_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT7_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT7_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT7_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT7_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT7_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT7_EP_HSHK:    .equ   %00000001
mENDPT7_EP_STALL:   .equ   %00000010
mENDPT7_EP_TX_EN:   .equ   %00000100
mENDPT7_EP_RX_EN:   .equ   %00001000
mENDPT7_EP_CTL_DIS: .equ   %00010000
mENDPT7_RETRY_DIS:  .equ   %01000000
mENDPT7_HOST_WO_HUB: .equ   %10000000


;*** ENDPT8 - Endpoint Control Register 8; 0xFFFF9AE0 ***
ENDPT8:             .equ   $FFFF9AE0                                ;*** ENDPT8 - Endpoint Control Register 8; 0xFFFF9AE0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT8_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT8_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT8_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT8_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT8_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT8_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT8_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT8_EP_HSHK:    .equ   %00000001
mENDPT8_EP_STALL:   .equ   %00000010
mENDPT8_EP_TX_EN:   .equ   %00000100
mENDPT8_EP_RX_EN:   .equ   %00001000
mENDPT8_EP_CTL_DIS: .equ   %00010000
mENDPT8_RETRY_DIS:  .equ   %01000000
mENDPT8_HOST_WO_HUB: .equ   %10000000


;*** ENDPT9 - Endpoint Control Register 9; 0xFFFF9AE4 ***
ENDPT9:             .equ   $FFFF9AE4                                ;*** ENDPT9 - Endpoint Control Register 9; 0xFFFF9AE4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT9_EP_HSHK:     .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT9_EP_STALL:    .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT9_EP_TX_EN:    .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT9_EP_RX_EN:    .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT9_EP_CTL_DIS:  .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT9_RETRY_DIS:   .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT9_HOST_WO_HUB: .equ   7                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT9_EP_HSHK:    .equ   %00000001
mENDPT9_EP_STALL:   .equ   %00000010
mENDPT9_EP_TX_EN:   .equ   %00000100
mENDPT9_EP_RX_EN:   .equ   %00001000
mENDPT9_EP_CTL_DIS: .equ   %00010000
mENDPT9_RETRY_DIS:  .equ   %01000000
mENDPT9_HOST_WO_HUB: .equ   %10000000


;*** ENDPT10 - Endpoint Control Register 10; 0xFFFF9AE8 ***
ENDPT10:            .equ   $FFFF9AE8                                ;*** ENDPT10 - Endpoint Control Register 10; 0xFFFF9AE8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT10_EP_HSHK:    .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT10_EP_STALL:   .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT10_EP_TX_EN:   .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT10_EP_RX_EN:   .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT10_EP_CTL_DIS: .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT10_RETRY_DIS:  .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT10_HOST_WO_HUB: .equ   7                                        ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT10_EP_HSHK:   .equ   %00000001
mENDPT10_EP_STALL:  .equ   %00000010
mENDPT10_EP_TX_EN:  .equ   %00000100
mENDPT10_EP_RX_EN:  .equ   %00001000
mENDPT10_EP_CTL_DIS: .equ   %00010000
mENDPT10_RETRY_DIS: .equ   %01000000
mENDPT10_HOST_WO_HUB: .equ   %10000000


;*** ENDPT11 - Endpoint Control Register 11; 0xFFFF9AEC ***
ENDPT11:            .equ   $FFFF9AEC                                ;*** ENDPT11 - Endpoint Control Register 11; 0xFFFF9AEC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT11_EP_HSHK:    .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT11_EP_STALL:   .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT11_EP_TX_EN:   .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT11_EP_RX_EN:   .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT11_EP_CTL_DIS: .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT11_RETRY_DIS:  .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT11_HOST_WO_HUB: .equ   7                                        ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT11_EP_HSHK:   .equ   %00000001
mENDPT11_EP_STALL:  .equ   %00000010
mENDPT11_EP_TX_EN:  .equ   %00000100
mENDPT11_EP_RX_EN:  .equ   %00001000
mENDPT11_EP_CTL_DIS: .equ   %00010000
mENDPT11_RETRY_DIS: .equ   %01000000
mENDPT11_HOST_WO_HUB: .equ   %10000000


;*** ENDPT12 - Endpoint Control Register 12; 0xFFFF9AF0 ***
ENDPT12:            .equ   $FFFF9AF0                                ;*** ENDPT12 - Endpoint Control Register 12; 0xFFFF9AF0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT12_EP_HSHK:    .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT12_EP_STALL:   .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT12_EP_TX_EN:   .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT12_EP_RX_EN:   .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT12_EP_CTL_DIS: .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT12_RETRY_DIS:  .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT12_HOST_WO_HUB: .equ   7                                        ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT12_EP_HSHK:   .equ   %00000001
mENDPT12_EP_STALL:  .equ   %00000010
mENDPT12_EP_TX_EN:  .equ   %00000100
mENDPT12_EP_RX_EN:  .equ   %00001000
mENDPT12_EP_CTL_DIS: .equ   %00010000
mENDPT12_RETRY_DIS: .equ   %01000000
mENDPT12_HOST_WO_HUB: .equ   %10000000


;*** ENDPT13 - Endpoint Control Register 13; 0xFFFF9AF4 ***
ENDPT13:            .equ   $FFFF9AF4                                ;*** ENDPT13 - Endpoint Control Register 13; 0xFFFF9AF4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT13_EP_HSHK:    .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT13_EP_STALL:   .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT13_EP_TX_EN:   .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT13_EP_RX_EN:   .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT13_EP_CTL_DIS: .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT13_RETRY_DIS:  .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT13_HOST_WO_HUB: .equ   7                                        ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT13_EP_HSHK:   .equ   %00000001
mENDPT13_EP_STALL:  .equ   %00000010
mENDPT13_EP_TX_EN:  .equ   %00000100
mENDPT13_EP_RX_EN:  .equ   %00001000
mENDPT13_EP_CTL_DIS: .equ   %00010000
mENDPT13_RETRY_DIS: .equ   %01000000
mENDPT13_HOST_WO_HUB: .equ   %10000000


;*** ENDPT14 - Endpoint Control Register 14; 0xFFFF9AF8 ***
ENDPT14:            .equ   $FFFF9AF8                                ;*** ENDPT14 - Endpoint Control Register 14; 0xFFFF9AF8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT14_EP_HSHK:    .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT14_EP_STALL:   .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT14_EP_TX_EN:   .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT14_EP_RX_EN:   .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT14_EP_CTL_DIS: .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT14_RETRY_DIS:  .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT14_HOST_WO_HUB: .equ   7                                        ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT14_EP_HSHK:   .equ   %00000001
mENDPT14_EP_STALL:  .equ   %00000010
mENDPT14_EP_TX_EN:  .equ   %00000100
mENDPT14_EP_RX_EN:  .equ   %00001000
mENDPT14_EP_CTL_DIS: .equ   %00010000
mENDPT14_RETRY_DIS: .equ   %01000000
mENDPT14_HOST_WO_HUB: .equ   %10000000


;*** ENDPT15 - Endpoint Control Register 15; 0xFFFF9AFC ***
ENDPT15:            .equ   $FFFF9AFC                                ;*** ENDPT15 - Endpoint Control Register 15; 0xFFFF9AFC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ENDPT15_EP_HSHK:    .equ   0                                         ; When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous
ENDPT15_EP_STALL:   .equ   1                                         ; When set this bit indicates that the endpoint is stalled
ENDPT15_EP_TX_EN:   .equ   2                                         ; This bit, when set, enables the endpoint for TX transfers
ENDPT15_EP_RX_EN:   .equ   3                                         ; This bit, when set, enables the endpoint for RX transfers
ENDPT15_EP_CTL_DIS: .equ   4                                         ; This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set
ENDPT15_RETRY_DIS:  .equ   6                                         ; Not available. Present only in endpoint 0 control register (ENDPT0)
ENDPT15_HOST_WO_HUB: .equ   7                                        ; Not available. Present only in endpoint 0 control register (ENDPT0)
; bit position masks
mENDPT15_EP_HSHK:   .equ   %00000001
mENDPT15_EP_STALL:  .equ   %00000010
mENDPT15_EP_TX_EN:  .equ   %00000100
mENDPT15_EP_RX_EN:  .equ   %00001000
mENDPT15_EP_CTL_DIS: .equ   %00010000
mENDPT15_RETRY_DIS: .equ   %01000000
mENDPT15_HOST_WO_HUB: .equ   %10000000


;*** USB_CTRL - USB Control Register; 0xFFFF9B00 ***
USB_CTRL:           .equ   $FFFF9B00                                ;*** USB_CTRL - USB Control Register; 0xFFFF9B00 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USB_CTRL_CLK_SRC0:  .equ   0                                         ; Determines the clock source for the USB 48 MHZ clock, bit 0
USB_CTRL_CLK_SRC1:  .equ   1                                         ; Determines the clock source for the USB 48 MHZ clock, bit 1
USB_CTRL_PDE:       .equ   6                                         ; Enables the non-functional weak pulldowns on the USB transceiver
USB_CTRL_SUSP:      .equ   7                                         ; Places the USB transceiver into the suspend state
; bit position masks
mUSB_CTRL_CLK_SRC0: .equ   %00000001
mUSB_CTRL_CLK_SRC1: .equ   %00000010
mUSB_CTRL_PDE:      .equ   %01000000
mUSB_CTRL_SUSP:     .equ   %10000000


;*** USB_OTG_OBSERVE - USB OTG Observe Register; 0xFFFF9B04 ***
USB_OTG_OBSERVE:    .equ   $FFFF9B04                                ;*** USB_OTG_OBSERVE - USB OTG Observe Register; 0xFFFF9B04 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USB_OTG_OBSERVE_DM_PD: .equ   4                                      ; Provides observability of the D- Pull Down signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface
USB_OTG_OBSERVE_DP_PD: .equ   6                                      ; Provides observability of the D+ Pull Down signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface
USB_OTG_OBSERVE_DP_PU: .equ   7                                      ; Provides observability of the D+ Pull Up signal output from the USB OTG module. This bit is useful when interfacing to anexternal OTG control module via a serial interface. Useful when interfacing to an external OTG control module via a serial interface
; bit position masks
mUSB_OTG_OBSERVE_DM_PD: .equ   %00010000
mUSB_OTG_OBSERVE_DP_PD: .equ   %01000000
mUSB_OTG_OBSERVE_DP_PU: .equ   %10000000


;*** USB_OTG_CONTROL - USB OTG Control Register; 0xFFFF9B08 ***
USB_OTG_CONTROL:    .equ   $FFFF9B08                                ;*** USB_OTG_CONTROL - USB OTG Control Register; 0xFFFF9B08 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USB_OTG_CONTROL_SESSEND: .equ   0                                    ; Provides observability of the Session End signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface
USB_OTG_CONTROL_SESSVLD: .equ   1                                    ; Provides observability of the Session Valid signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface
USB_OTG_CONTROL_VBUSVLD: .equ   2                                    ; Provides control of the VBUS Valid signal into the USB OTG module if a pin has not been configured for this function. Useful when interfacing to an external OTG control module via a serial interface
USB_OTG_CONTROL_ID: .equ   3                                         ; Provides control of the USB ID signal into the USB OTG module if a pin has not been configured for this function. Useful when interfacing to an external OTG control module via a serial interface
USB_OTG_CONTROL_DPPULLUP_NONOTG: .equ   4                            ; Provides control of the DP PULLUP in the USB OTG module, if USB is configured in non-OTG device mode
; bit position masks
mUSB_OTG_CONTROL_SESSEND: .equ   %00000001
mUSB_OTG_CONTROL_SESSVLD: .equ   %00000010
mUSB_OTG_CONTROL_VBUSVLD: .equ   %00000100
mUSB_OTG_CONTROL_ID: .equ   %00001000
mUSB_OTG_CONTROL_DPPULLUP_NONOTG: .equ   %00010000


;*** USBTRC0 - USB Transceiver and Regulator Control Register 0; 0xFFFF9B0C ***
USBTRC0:            .equ   $FFFF9B0C                                ;*** USBTRC0 - USB Transceiver and Regulator Control Register 0; 0xFFFF9B0C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USBTRC0_USB_RESUME_INT: .equ   0                                     ; USB Asynchronous Interrupt
USBTRC0_USBVREN:    .equ   2                                         ; USB voltage regulator enable
USBTRC0_USBRESMEN:  .equ   5                                         ; Allows the USB module to send an asynchronous wakeup event upon detection of resume signaling on the USB bus
USBTRC0_USBPU:      .equ   6                                         ; Pull-up resistor on the USBDP line
USBTRC0_USBRESET:   .equ   7                                         ; Generates a hard reset to the USB module
; bit position masks
mUSBTRC0_USB_RESUME_INT: .equ   %00000001
mUSBTRC0_USBVREN:   .equ   %00000100
mUSBTRC0_USBRESMEN: .equ   %00100000
mUSBTRC0_USBPU:     .equ   %01000000
mUSBTRC0_USBRESET:  .equ   %10000000


;*** OTGPIN - USB OTG Pin Control Register; 0xFFFF9B10 ***
OTGPIN:             .equ   $FFFF9B10                                ;*** OTGPIN - USB OTG Pin Control Register; 0xFFFF9B10 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OTGPIN_SESSVLD:     .equ   0                                         ; Session Valid Pin Enable
OTGPIN_SESSEND:     .equ   1                                         ; Session End Pin Enable
OTGPIN_VBUSVLD:     .equ   2                                         ; Valid Pin Enable
OTGPIN_PULLUP:      .equ   3                                         ; Pull-up Pin Enable
OTGPIN_DPDOWN:      .equ   4                                         ; DPDOWN Pin Enable
OTGPIN_DMDOWN:      .equ   5                                         ; DMDOWN Pin Enable
OTGPIN_USBID:       .equ   6                                         ; USB_ID Pin Enable
; bit position masks
mOTGPIN_SESSVLD:    .equ   %00000001
mOTGPIN_SESSEND:    .equ   %00000010
mOTGPIN_VBUSVLD:    .equ   %00000100
mOTGPIN_PULLUP:     .equ   %00001000
mOTGPIN_DPDOWN:     .equ   %00010000
mOTGPIN_DMDOWN:     .equ   %00100000
mOTGPIN_USBID:      .equ   %01000000


;*** INTC_FRC - INTC Force Interrupt Register; 0xFFFFFFD0 ***
INTC_FRC:           .equ   $FFFFFFD0                                ;*** INTC_FRC - INTC Force Interrupt Register; 0xFFFFFFD0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_FRC_LVL7:      .equ   0                                         ; Force Level 7 interrupt
INTC_FRC_LVL6:      .equ   1                                         ; Force Level 6 interrupt
INTC_FRC_LVL5:      .equ   2                                         ; Force Level 5 interrupt
INTC_FRC_LVL4:      .equ   3                                         ; Force Level 4 interrupt
INTC_FRC_LVL3:      .equ   4                                         ; Force Level 3 interrupt
INTC_FRC_LVL2:      .equ   5                                         ; Force Level 2 interrupt
INTC_FRC_LVL1:      .equ   6                                         ; Force Level 1 interrupt
; bit position masks
mINTC_FRC_LVL7:     .equ   %00000001
mINTC_FRC_LVL6:     .equ   %00000010
mINTC_FRC_LVL5:     .equ   %00000100
mINTC_FRC_LVL4:     .equ   %00001000
mINTC_FRC_LVL3:     .equ   %00010000
mINTC_FRC_LVL2:     .equ   %00100000
mINTC_FRC_LVL1:     .equ   %01000000


;*** INTC_PL6P7 - INTC Programmable Level 6, Priority 7 Register; 0xFFFFFFD8 ***
INTC_PL6P7:         .equ   $FFFFFFD8                                ;*** INTC_PL6P7 - INTC Programmable Level 6, Priority 7 Register; 0xFFFFFFD8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_PL6P7_REQN0:   .equ   0                                         ; Request number, bit 0
INTC_PL6P7_REQN1:   .equ   1                                         ; Request number, bit 1
INTC_PL6P7_REQN2:   .equ   2                                         ; Request number, bit 2
INTC_PL6P7_REQN3:   .equ   3                                         ; Request number, bit 3
INTC_PL6P7_REQN4:   .equ   4                                         ; Request number, bit 4
; bit position masks
mINTC_PL6P7_REQN0:  .equ   %00000001
mINTC_PL6P7_REQN1:  .equ   %00000010
mINTC_PL6P7_REQN2:  .equ   %00000100
mINTC_PL6P7_REQN3:  .equ   %00001000
mINTC_PL6P7_REQN4:  .equ   %00010000


;*** INTC_PL6P6 - INTC Programmable Level 6, Priority 6 Register; 0xFFFFFFD9 ***
INTC_PL6P6:         .equ   $FFFFFFD9                                ;*** INTC_PL6P6 - INTC Programmable Level 6, Priority 6 Register; 0xFFFFFFD9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_PL6P6_REQN0:   .equ   0                                         ; Request number, bit 0
INTC_PL6P6_REQN1:   .equ   1                                         ; Request number, bit 1
INTC_PL6P6_REQN2:   .equ   2                                         ; Request number, bit 2
INTC_PL6P6_REQN3:   .equ   3                                         ; Request number, bit 3
INTC_PL6P6_REQN4:   .equ   4                                         ; Request number, bit 4
; bit position masks
mINTC_PL6P6_REQN0:  .equ   %00000001
mINTC_PL6P6_REQN1:  .equ   %00000010
mINTC_PL6P6_REQN2:  .equ   %00000100
mINTC_PL6P6_REQN3:  .equ   %00001000
mINTC_PL6P6_REQN4:  .equ   %00010000


;*** INTC_WCR - INTC Wake-up Control Register; 0xFFFFFFDB ***
INTC_WCR:           .equ   $FFFFFFDB                                ;*** INTC_WCR - INTC Wake-up Control Register; 0xFFFFFFDB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_WCR_MASK0:     .equ   0                                         ; Interrupt mask level, bit 0
INTC_WCR_MASK1:     .equ   1                                         ; Interrupt mask level, bit 1
INTC_WCR_MASK2:     .equ   2                                         ; Interrupt mask level, bit 2
INTC_WCR_ENB:       .equ   7                                         ; Enable
; bit position masks
mINTC_WCR_MASK0:    .equ   %00000001
mINTC_WCR_MASK1:    .equ   %00000010
mINTC_WCR_MASK2:    .equ   %00000100
mINTC_WCR_ENB:      .equ   %10000000


;*** INTC_SFRC - INTC Set Interrupt Force Register; 0xFFFFFFDE ***
INTC_SFRC:          .equ   $FFFFFFDE                                ;*** INTC_SFRC - INTC Set Interrupt Force Register; 0xFFFFFFDE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_SFRC_SET0:     .equ   0                                         ; Sets corresponding bits in the INTC_FRC register, bit 0
INTC_SFRC_SET1:     .equ   1                                         ; Sets corresponding bits in the INTC_FRC register, bit 1
INTC_SFRC_SET2:     .equ   2                                         ; Sets corresponding bits in the INTC_FRC register, bit 2
INTC_SFRC_SET3:     .equ   3                                         ; Sets corresponding bits in the INTC_FRC register, bit 3
INTC_SFRC_SET4:     .equ   4                                         ; Sets corresponding bits in the INTC_FRC register, bit 4
INTC_SFRC_SET5:     .equ   5                                         ; Sets corresponding bits in the INTC_FRC register, bit 5
; bit position masks
mINTC_SFRC_SET0:    .equ   %00000001
mINTC_SFRC_SET1:    .equ   %00000010
mINTC_SFRC_SET2:    .equ   %00000100
mINTC_SFRC_SET3:    .equ   %00001000
mINTC_SFRC_SET4:    .equ   %00010000
mINTC_SFRC_SET5:    .equ   %00100000


;*** INTC_CFRC - INTC Clear Interrupt Force Register; 0xFFFFFFDF ***
INTC_CFRC:          .equ   $FFFFFFDF                                ;*** INTC_CFRC - INTC Clear Interrupt Force Register; 0xFFFFFFDF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_CFRC_CLR0:     .equ   0                                         ; Clears corresponding bits in the INTC_FRC register, bit 0
INTC_CFRC_CLR1:     .equ   1                                         ; Clears corresponding bits in the INTC_FRC register, bit 1
INTC_CFRC_CLR2:     .equ   2                                         ; Clears corresponding bits in the INTC_FRC register, bit 2
INTC_CFRC_CLR3:     .equ   3                                         ; Clears corresponding bits in the INTC_FRC register, bit 3
INTC_CFRC_CLR4:     .equ   4                                         ; Clears corresponding bits in the INTC_FRC register, bit 4
INTC_CFRC_CLR5:     .equ   5                                         ; Clears corresponding bits in the INTC_FRC register, bit 5
; bit position masks
mINTC_CFRC_CLR0:    .equ   %00000001
mINTC_CFRC_CLR1:    .equ   %00000010
mINTC_CFRC_CLR2:    .equ   %00000100
mINTC_CFRC_CLR3:    .equ   %00001000
mINTC_CFRC_CLR4:    .equ   %00010000
mINTC_CFRC_CLR5:    .equ   %00100000


;*** INTC_SWIACK - INTC Software IACK Register; 0xFFFFFFE0 ***
INTC_SWIACK:        .equ   $FFFFFFE0                                ;*** INTC_SWIACK - INTC Software IACK Register; 0xFFFFFFE0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_SWIACK_VECN0:  .equ   0                                         ; Vector number, bit 0
INTC_SWIACK_VECN1:  .equ   1                                         ; Vector number, bit 1
INTC_SWIACK_VECN2:  .equ   2                                         ; Vector number, bit 2
INTC_SWIACK_VECN3:  .equ   3                                         ; Vector number, bit 3
INTC_SWIACK_VECN4:  .equ   4                                         ; Vector number, bit 4
INTC_SWIACK_VECN5:  .equ   5                                         ; Vector number, bit 5
INTC_SWIACK_VECN6:  .equ   6                                         ; Vector number, bit 6
; bit position masks
mINTC_SWIACK_VECN0: .equ   %00000001
mINTC_SWIACK_VECN1: .equ   %00000010
mINTC_SWIACK_VECN2: .equ   %00000100
mINTC_SWIACK_VECN3: .equ   %00001000
mINTC_SWIACK_VECN4: .equ   %00010000
mINTC_SWIACK_VECN5: .equ   %00100000
mINTC_SWIACK_VECN6: .equ   %01000000


;*** INTC_LVL1IACK - INTC Level 1 IACK Register; 0xFFFFFFE4 ***
INTC_LVL1IACK:      .equ   $FFFFFFE4                                ;*** INTC_LVL1IACK - INTC Level 1 IACK Register; 0xFFFFFFE4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_LVL1IACK_VECN0: .equ   0                                        ; Vector number, bit 0
INTC_LVL1IACK_VECN1: .equ   1                                        ; Vector number, bit 1
INTC_LVL1IACK_VECN2: .equ   2                                        ; Vector number, bit 2
INTC_LVL1IACK_VECN3: .equ   3                                        ; Vector number, bit 3
INTC_LVL1IACK_VECN4: .equ   4                                        ; Vector number, bit 4
INTC_LVL1IACK_VECN5: .equ   5                                        ; Vector number, bit 5
INTC_LVL1IACK_VECN6: .equ   6                                        ; Vector number, bit 6
; bit position masks
mINTC_LVL1IACK_VECN0: .equ   %00000001
mINTC_LVL1IACK_VECN1: .equ   %00000010
mINTC_LVL1IACK_VECN2: .equ   %00000100
mINTC_LVL1IACK_VECN3: .equ   %00001000
mINTC_LVL1IACK_VECN4: .equ   %00010000
mINTC_LVL1IACK_VECN5: .equ   %00100000
mINTC_LVL1IACK_VECN6: .equ   %01000000


;*** INTC_LVL2IACK - INTC Level 2 IACK Register; 0xFFFFFFE8 ***
INTC_LVL2IACK:      .equ   $FFFFFFE8                                ;*** INTC_LVL2IACK - INTC Level 2 IACK Register; 0xFFFFFFE8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_LVL2IACK_VECN0: .equ   0                                        ; Vector number, bit 0
INTC_LVL2IACK_VECN1: .equ   1                                        ; Vector number, bit 1
INTC_LVL2IACK_VECN2: .equ   2                                        ; Vector number, bit 2
INTC_LVL2IACK_VECN3: .equ   3                                        ; Vector number, bit 3
INTC_LVL2IACK_VECN4: .equ   4                                        ; Vector number, bit 4
INTC_LVL2IACK_VECN5: .equ   5                                        ; Vector number, bit 5
INTC_LVL2IACK_VECN6: .equ   6                                        ; Vector number, bit 6
; bit position masks
mINTC_LVL2IACK_VECN0: .equ   %00000001
mINTC_LVL2IACK_VECN1: .equ   %00000010
mINTC_LVL2IACK_VECN2: .equ   %00000100
mINTC_LVL2IACK_VECN3: .equ   %00001000
mINTC_LVL2IACK_VECN4: .equ   %00010000
mINTC_LVL2IACK_VECN5: .equ   %00100000
mINTC_LVL2IACK_VECN6: .equ   %01000000


;*** INTC_LVL3IACK - INTC Level 3 IACK Register; 0xFFFFFFEC ***
INTC_LVL3IACK:      .equ   $FFFFFFEC                                ;*** INTC_LVL3IACK - INTC Level 3 IACK Register; 0xFFFFFFEC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_LVL3IACK_VECN0: .equ   0                                        ; Vector number, bit 0
INTC_LVL3IACK_VECN1: .equ   1                                        ; Vector number, bit 1
INTC_LVL3IACK_VECN2: .equ   2                                        ; Vector number, bit 2
INTC_LVL3IACK_VECN3: .equ   3                                        ; Vector number, bit 3
INTC_LVL3IACK_VECN4: .equ   4                                        ; Vector number, bit 4
INTC_LVL3IACK_VECN5: .equ   5                                        ; Vector number, bit 5
INTC_LVL3IACK_VECN6: .equ   6                                        ; Vector number, bit 6
; bit position masks
mINTC_LVL3IACK_VECN0: .equ   %00000001
mINTC_LVL3IACK_VECN1: .equ   %00000010
mINTC_LVL3IACK_VECN2: .equ   %00000100
mINTC_LVL3IACK_VECN3: .equ   %00001000
mINTC_LVL3IACK_VECN4: .equ   %00010000
mINTC_LVL3IACK_VECN5: .equ   %00100000
mINTC_LVL3IACK_VECN6: .equ   %01000000


;*** INTC_LVL4IACK - INTC Level 4 IACK Register; 0xFFFFFFF0 ***
INTC_LVL4IACK:      .equ   $FFFFFFF0                                ;*** INTC_LVL4IACK - INTC Level 4 IACK Register; 0xFFFFFFF0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_LVL4IACK_VECN0: .equ   0                                        ; Vector number, bit 0
INTC_LVL4IACK_VECN1: .equ   1                                        ; Vector number, bit 1
INTC_LVL4IACK_VECN2: .equ   2                                        ; Vector number, bit 2
INTC_LVL4IACK_VECN3: .equ   3                                        ; Vector number, bit 3
INTC_LVL4IACK_VECN4: .equ   4                                        ; Vector number, bit 4
INTC_LVL4IACK_VECN5: .equ   5                                        ; Vector number, bit 5
INTC_LVL4IACK_VECN6: .equ   6                                        ; Vector number, bit 6
; bit position masks
mINTC_LVL4IACK_VECN0: .equ   %00000001
mINTC_LVL4IACK_VECN1: .equ   %00000010
mINTC_LVL4IACK_VECN2: .equ   %00000100
mINTC_LVL4IACK_VECN3: .equ   %00001000
mINTC_LVL4IACK_VECN4: .equ   %00010000
mINTC_LVL4IACK_VECN5: .equ   %00100000
mINTC_LVL4IACK_VECN6: .equ   %01000000


;*** INTC_LVL5IACK - INTC Level 5 IACK Register; 0xFFFFFFF4 ***
INTC_LVL5IACK:      .equ   $FFFFFFF4                                ;*** INTC_LVL5IACK - INTC Level 5 IACK Register; 0xFFFFFFF4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_LVL5IACK_VECN0: .equ   0                                        ; Vector number, bit 0
INTC_LVL5IACK_VECN1: .equ   1                                        ; Vector number, bit 1
INTC_LVL5IACK_VECN2: .equ   2                                        ; Vector number, bit 2
INTC_LVL5IACK_VECN3: .equ   3                                        ; Vector number, bit 3
INTC_LVL5IACK_VECN4: .equ   4                                        ; Vector number, bit 4
INTC_LVL5IACK_VECN5: .equ   5                                        ; Vector number, bit 5
INTC_LVL5IACK_VECN6: .equ   6                                        ; Vector number, bit 6
; bit position masks
mINTC_LVL5IACK_VECN0: .equ   %00000001
mINTC_LVL5IACK_VECN1: .equ   %00000010
mINTC_LVL5IACK_VECN2: .equ   %00000100
mINTC_LVL5IACK_VECN3: .equ   %00001000
mINTC_LVL5IACK_VECN4: .equ   %00010000
mINTC_LVL5IACK_VECN5: .equ   %00100000
mINTC_LVL5IACK_VECN6: .equ   %01000000


;*** INTC_LVL6IACK - INTC Level 6 IACK Register; 0xFFFFFFF8 ***
INTC_LVL6IACK:      .equ   $FFFFFFF8                                ;*** INTC_LVL6IACK - INTC Level 6 IACK Register; 0xFFFFFFF8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_LVL6IACK_VECN0: .equ   0                                        ; Vector number, bit 0
INTC_LVL6IACK_VECN1: .equ   1                                        ; Vector number, bit 1
INTC_LVL6IACK_VECN2: .equ   2                                        ; Vector number, bit 2
INTC_LVL6IACK_VECN3: .equ   3                                        ; Vector number, bit 3
INTC_LVL6IACK_VECN4: .equ   4                                        ; Vector number, bit 4
INTC_LVL6IACK_VECN5: .equ   5                                        ; Vector number, bit 5
INTC_LVL6IACK_VECN6: .equ   6                                        ; Vector number, bit 6
; bit position masks
mINTC_LVL6IACK_VECN0: .equ   %00000001
mINTC_LVL6IACK_VECN1: .equ   %00000010
mINTC_LVL6IACK_VECN2: .equ   %00000100
mINTC_LVL6IACK_VECN3: .equ   %00001000
mINTC_LVL6IACK_VECN4: .equ   %00010000
mINTC_LVL6IACK_VECN5: .equ   %00100000
mINTC_LVL6IACK_VECN6: .equ   %01000000


;*** INTC_LVL7IACK - INTC Level 7 IACK Register; 0xFFFFFFFC ***
INTC_LVL7IACK:      .equ   $FFFFFFFC                                ;*** INTC_LVL7IACK - INTC Level 7 IACK Register; 0xFFFFFFFC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_LVL7IACK_VECN0: .equ   0                                        ; Vector number, bit 0
INTC_LVL7IACK_VECN1: .equ   1                                        ; Vector number, bit 1
INTC_LVL7IACK_VECN2: .equ   2                                        ; Vector number, bit 2
INTC_LVL7IACK_VECN3: .equ   3                                        ; Vector number, bit 3
INTC_LVL7IACK_VECN4: .equ   4                                        ; Vector number, bit 4
INTC_LVL7IACK_VECN5: .equ   5                                        ; Vector number, bit 5
INTC_LVL7IACK_VECN6: .equ   6                                        ; Vector number, bit 6
; bit position masks
mINTC_LVL7IACK_VECN0: .equ   %00000001
mINTC_LVL7IACK_VECN1: .equ   %00000010
mINTC_LVL7IACK_VECN2: .equ   %00000100
mINTC_LVL7IACK_VECN3: .equ   %00001000
mINTC_LVL7IACK_VECN4: .equ   %00010000
mINTC_LVL7IACK_VECN5: .equ   %00100000
mINTC_LVL7IACK_VECN6: .equ   %01000000



; Flash commands
mBlank:             .equ    $05
mBurstProg:         .equ    $25
mByteProg:          .equ    $20
mMassErase:         .equ    $41
mPageErase:         .equ    $40


;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
        .IFNDEF __GENERATE_APPLICATION__                            ; not supported for absolute assembler
                    .XREF   This_symb_has_been_depreciated
        .ENDIF
; ---------------------------------------------------------------------------
; The following symbols were removed, because they were invalid or irrelevant
; ---------------------------------------------------------------------------



; **** 5.2.2008 15:05:11

        .IFNDEF __GENERATE_APPLICATION__
#define SPI2C3_INTCLR                           This_symb_has_been_depreciated
#define mSPI2C3_INTCLR                          This_symb_has_been_depreciated
#define SPI2CI                                  This_symb_has_been_depreciated
#define SPI2CI_SPRFCI                           This_symb_has_been_depreciated
#define SPI2CI_SPTEFCI                          This_symb_has_been_depreciated
#define SPI2CI_RNFULLFCI                        This_symb_has_been_depreciated
#define SPI2CI_TNEAREFCI                        This_symb_has_been_depreciated
#define SPI2CI_RXFOF                            This_symb_has_been_depreciated
#define SPI2CI_TXFOF                            This_symb_has_been_depreciated
#define SPI2CI_RXFERR                           This_symb_has_been_depreciated
#define SPI2CI_TXFERR                           This_symb_has_been_depreciated
#define mSPI2CI_SPRFCI                          This_symb_has_been_depreciated
#define mSPI2CI_SPTEFCI                         This_symb_has_been_depreciated
#define mSPI2CI_RNFULLFCI                       This_symb_has_been_depreciated
#define mSPI2CI_TNEAREFCI                       This_symb_has_been_depreciated
#define mSPI2CI_RXFOF                           This_symb_has_been_depreciated
#define mSPI2CI_TXFOF                           This_symb_has_been_depreciated
#define mSPI2CI_RXFERR                          This_symb_has_been_depreciated
#define mSPI2CI_TXFERR                          This_symb_has_been_depreciated
#define OTG_CTRL_VBUS_DSCHG                     This_symb_has_been_depreciated
#define OTG_CTRL_VBUS_CHG                       This_symb_has_been_depreciated
#define OTG_CTRL_VBUS_ON                        This_symb_has_been_depreciated
#define mOTG_CTRL_VBUS_DSCHG                    This_symb_has_been_depreciated
#define mOTG_CTRL_VBUS_CHG                      This_symb_has_been_depreciated
#define mOTG_CTRL_VBUS_ON                       This_symb_has_been_depreciated
        .ENDIF

; EOF
