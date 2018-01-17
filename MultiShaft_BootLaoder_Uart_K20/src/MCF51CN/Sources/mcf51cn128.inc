; Based on CPU DB MCF51CN128_80, version 3.00.000 (RegistersPrg V2.24)

; ###################################################################
;     Filename  : mcf51cn128.inc
;     Processor : MCF51CN128_LQFP80
;     FileFormat: V2.24
;     DataSheet : MCF51CN128RM Rev. 2.0 20 August 2008
;     Compiler  : CodeWarrior compiler
;     Date/Time : 30.9.2008, 10:43
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     (c) Copyright UNIS, a.s. 1997-2008
;     UNIS, a.s.
;     Jundrovska 33
;     624 00 Brno
;     Czech Republic
;     http      : www.processorexpert.com
;     mail      : info@processorexpert.com
;
;     CPU Registers Revisions:
;               - none
;
;     File-Format-Revisions:
;      - 03.07.2008, V2.24 :
;               - Added support for bits with name starting with number (like "1HZ")
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
Vtpm1ch0:           .equ  $0000010C
Vtpm1ch1:           .equ  $00000110
Vtpm1ch2:           .equ  $00000114
Vtpm1ovf:           .equ  $00000118
Vmtim1:             .equ  $0000011C
Vtpm2ch0:           .equ  $00000120
Vtpm2ch1:           .equ  $00000124
Vtpm2ch2:           .equ  $00000128
Vtpm2ovf:           .equ  $0000012C
Vspi1:              .equ  $00000130
Vspi2:              .equ  $00000134
Vmtim2:             .equ  $00000138
Vsci1err:           .equ  $0000013C
Vsci1rx:            .equ  $00000140
Vsci1tx:            .equ  $00000144
Vsci2err:           .equ  $00000148
Vsci2rx:            .equ  $0000014C
Vsci2tx:            .equ  $00000150
Vsci3or:            .equ  $00000154
Vfectxf:            .equ  $00000158
Vfecrxf:            .equ  $0000015C
Vfecother:          .equ  $00000160
Vfechberr:          .equ  $00000164
Vfecbabr:           .equ  $00000168
Vfecbabt:           .equ  $0000016C
Vfecgra:            .equ  $00000170
Vfectxb:            .equ  $00000174
Vfecrxb:            .equ  $00000178
Vfecmii:            .equ  $0000017C
Vfeceberr:          .equ  $00000180
Vfeclc:             .equ  $00000184
Vfecrl:             .equ  $00000188
Vfecun:             .equ  $0000018C
Vsci3err:           .equ  $00000190
Vsci3rx:            .equ  $00000194
Vsci3tx:            .equ  $00000198
VL7swi:             .equ  $0000019C
VL6swi:             .equ  $000001A0
VL5swi:             .equ  $000001A4
VL4swi:             .equ  $000001A8
VL3swi:             .equ  $000001AC
VL2swi:             .equ  $000001B0
VL1swi:             .equ  $000001B4
Viic1:              .equ  $000001B8
Viic2:              .equ  $000001BC
Vadc:               .equ  $000001C0
Vkeyboard:          .equ  $000001C4
Vrtc:               .equ  $000001C8
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


;*** PTAPE - Port A Pull Enable Register; 0xFFFF8008 ***
PTAPE:              .equ   $FFFF8008                                ;*** PTAPE - Port A Pull Enable Register; 0xFFFF8008 ***
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


;*** PTASE - Port A Slew Rate Enable Register; 0xFFFF8009 ***
PTASE:              .equ   $FFFF8009                                ;*** PTASE - Port A Slew Rate Enable Register; 0xFFFF8009 ***
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


;*** PTADS - Port A Drive Strength Selection Register; 0xFFFF800A ***
PTADS:              .equ   $FFFF800A                                ;*** PTADS - Port A Drive Strength Selection Register; 0xFFFF800A ***
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


;*** PTAIFE - Port A Input Filter Enable Register; 0xFFFF800B ***
PTAIFE:             .equ   $FFFF800B                                ;*** PTAIFE - Port A Input Filter Enable Register; 0xFFFF800B ***
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


;*** PTBD - Port B Data Register; 0xFFFF8010 ***
PTBD:               .equ   $FFFF8010                                ;*** PTBD - Port B Data Register; 0xFFFF8010 ***
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


;*** PTBDD - Port B Data Direction Register; 0xFFFF8011 ***
PTBDD:              .equ   $FFFF8011                                ;*** PTBDD - Port B Data Direction Register; 0xFFFF8011 ***
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


;*** PTBPE - Port B Pull Enable Register; 0xFFFF8018 ***
PTBPE:              .equ   $FFFF8018                                ;*** PTBPE - Port B Pull Enable Register; 0xFFFF8018 ***
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


;*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF8019 ***
PTBSE:              .equ   $FFFF8019                                ;*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF8019 ***
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


;*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF801A ***
PTBDS:              .equ   $FFFF801A                                ;*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF801A ***
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


;*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF801B ***
PTBIFE:             .equ   $FFFF801B                                ;*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF801B ***
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


;*** PTCD - Port C Data Register; 0xFFFF8020 ***
PTCD:               .equ   $FFFF8020                                ;*** PTCD - Port C Data Register; 0xFFFF8020 ***
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


;*** PTCDD - Port C Data Direction Register; 0xFFFF8021 ***
PTCDD:              .equ   $FFFF8021                                ;*** PTCDD - Port C Data Direction Register; 0xFFFF8021 ***
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


;*** PTCPE - Port C Pull Enable Register; 0xFFFF8028 ***
PTCPE:              .equ   $FFFF8028                                ;*** PTCPE - Port C Pull Enable Register; 0xFFFF8028 ***
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


;*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF8029 ***
PTCSE:              .equ   $FFFF8029                                ;*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF8029 ***
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


;*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF802A ***
PTCDS:              .equ   $FFFF802A                                ;*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF802A ***
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


;*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF802B ***
PTCIFE:             .equ   $FFFF802B                                ;*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF802B ***
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


;*** PTDD - Port D Data Register; 0xFFFF8030 ***
PTDD:               .equ   $FFFF8030                                ;*** PTDD - Port D Data Register; 0xFFFF8030 ***
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


;*** PTDDD - Port D Data Direction Register; 0xFFFF8031 ***
PTDDD:              .equ   $FFFF8031                                ;*** PTDDD - Port D Data Direction Register; 0xFFFF8031 ***
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


;*** PTDPE - Port D Pull Enable Register; 0xFFFF8038 ***
PTDPE:              .equ   $FFFF8038                                ;*** PTDPE - Port D Pull Enable Register; 0xFFFF8038 ***
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


;*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF8039 ***
PTDSE:              .equ   $FFFF8039                                ;*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF8039 ***
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


;*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF803A ***
PTDDS:              .equ   $FFFF803A                                ;*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF803A ***
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


;*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF803B ***
PTDIFE:             .equ   $FFFF803B                                ;*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF803B ***
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


;*** PTED - Port E Data Register; 0xFFFF8040 ***
PTED:               .equ   $FFFF8040                                ;*** PTED - Port E Data Register; 0xFFFF8040 ***
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


;*** PTEDD - Port E Data Direction Register; 0xFFFF8041 ***
PTEDD:              .equ   $FFFF8041                                ;*** PTEDD - Port E Data Direction Register; 0xFFFF8041 ***
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


;*** PTEPE - Port E Pull Enable Register; 0xFFFF8048 ***
PTEPE:              .equ   $FFFF8048                                ;*** PTEPE - Port E Pull Enable Register; 0xFFFF8048 ***
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


;*** PTESE - Port E Slew Rate Enable Register; 0xFFFF8049 ***
PTESE:              .equ   $FFFF8049                                ;*** PTESE - Port E Slew Rate Enable Register; 0xFFFF8049 ***
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


;*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF804A ***
PTEDS:              .equ   $FFFF804A                                ;*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF804A ***
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


;*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF804B ***
PTEIFE:             .equ   $FFFF804B                                ;*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF804B ***
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


;*** KBI2SC - KBI2 Status and Control Register; 0xFFFF804C ***
KBI2SC:             .equ   $FFFF804C                                ;*** KBI2SC - KBI2 Status and Control Register; 0xFFFF804C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2SC_KBIMOD:      .equ   0                                         ; Keyboard Detection Mode
KBI2SC_KBIE:        .equ   1                                         ; Keyboard Interrupt Enable
KBI2SC_KBACK:       .equ   2                                         ; Keyboard Interrupt Acknowledge
KBI2SC_KBF:         .equ   3                                         ; Keyboard Interrupt Flag
; bit position masks
mKBI2SC_KBIMOD:     .equ   %00000001
mKBI2SC_KBIE:       .equ   %00000010
mKBI2SC_KBACK:      .equ   %00000100
mKBI2SC_KBF:        .equ   %00001000


;*** KBI2PE - KBI2 Pin Enable Register; 0xFFFF804D ***
KBI2PE:             .equ   $FFFF804D                                ;*** KBI2PE - KBI2 Pin Enable Register; 0xFFFF804D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2PE_KBIPE0:      .equ   0                                         ; Keyboard Pin Enable for KBI Port Bit 0
KBI2PE_KBIPE1:      .equ   1                                         ; Keyboard Pin Enable for KBI Port Bit 1
KBI2PE_KBIPE2:      .equ   2                                         ; Keyboard Pin Enable for KBI Port Bit 2
KBI2PE_KBIPE3:      .equ   3                                         ; Keyboard Pin Enable for KBI Port Bit 3
KBI2PE_KBIPE4:      .equ   4                                         ; Keyboard Pin Enable for KBI Port Bit 4
KBI2PE_KBIPE5:      .equ   5                                         ; Keyboard Pin Enable for KBI Port Bit 5
KBI2PE_KBIPE6:      .equ   6                                         ; Keyboard Pin Enable for KBI Port Bit 6
KBI2PE_KBIPE7:      .equ   7                                         ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI2PE_KBIPE0:     .equ   %00000001
mKBI2PE_KBIPE1:     .equ   %00000010
mKBI2PE_KBIPE2:     .equ   %00000100
mKBI2PE_KBIPE3:     .equ   %00001000
mKBI2PE_KBIPE4:     .equ   %00010000
mKBI2PE_KBIPE5:     .equ   %00100000
mKBI2PE_KBIPE6:     .equ   %01000000
mKBI2PE_KBIPE7:     .equ   %10000000


;*** KBI2ES - KBI2 Edge Select Register; 0xFFFF804E ***
KBI2ES:             .equ   $FFFF804E                                ;*** KBI2ES - KBI2 Edge Select Register; 0xFFFF804E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2ES_KBEDG0:      .equ   0                                         ; Keyboard Edge Select Bit 0
KBI2ES_KBEDG1:      .equ   1                                         ; Keyboard Edge Select Bit 1
KBI2ES_KBEDG2:      .equ   2                                         ; Keyboard Edge Select Bit 2
KBI2ES_KBEDG3:      .equ   3                                         ; Keyboard Edge Select Bit 3
KBI2ES_KBEDG4:      .equ   4                                         ; Keyboard Edge Select Bit 4
KBI2ES_KBEDG5:      .equ   5                                         ; Keyboard Edge Select Bit 5
KBI2ES_KBEDG6:      .equ   6                                         ; Keyboard Edge Select Bit 6
KBI2ES_KBEDG7:      .equ   7                                         ; Keyboard Edge Select Bit 7
; bit position masks
mKBI2ES_KBEDG0:     .equ   %00000001
mKBI2ES_KBEDG1:     .equ   %00000010
mKBI2ES_KBEDG2:     .equ   %00000100
mKBI2ES_KBEDG3:     .equ   %00001000
mKBI2ES_KBEDG4:     .equ   %00010000
mKBI2ES_KBEDG5:     .equ   %00100000
mKBI2ES_KBEDG6:     .equ   %01000000
mKBI2ES_KBEDG7:     .equ   %10000000


;*** PTFD - Port F Data Register; 0xFFFF8050 ***
PTFD:               .equ   $FFFF8050                                ;*** PTFD - Port F Data Register; 0xFFFF8050 ***
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


;*** PTFDD - Port F Data Direction Register; 0xFFFF8051 ***
PTFDD:              .equ   $FFFF8051                                ;*** PTFDD - Port F Data Direction Register; 0xFFFF8051 ***
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


;*** PTFPE - Port F Pull Enable Register; 0xFFFF8058 ***
PTFPE:              .equ   $FFFF8058                                ;*** PTFPE - Port F Pull Enable Register; 0xFFFF8058 ***
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


;*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF8059 ***
PTFSE:              .equ   $FFFF8059                                ;*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF8059 ***
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


;*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF805A ***
PTFDS:              .equ   $FFFF805A                                ;*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF805A ***
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


;*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF805B ***
PTFIFE:             .equ   $FFFF805B                                ;*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF805B ***
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


;*** PTGD - Port G Data Register; 0xFFFF8060 ***
PTGD:               .equ   $FFFF8060                                ;*** PTGD - Port G Data Register; 0xFFFF8060 ***
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


;*** PTGDD - Port G Data Direction Register; 0xFFFF8061 ***
PTGDD:              .equ   $FFFF8061                                ;*** PTGDD - Port G Data Direction Register; 0xFFFF8061 ***
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


;*** PTGPE - Port G Pull Enable Register; 0xFFFF8068 ***
PTGPE:              .equ   $FFFF8068                                ;*** PTGPE - Port G Pull Enable Register; 0xFFFF8068 ***
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


;*** PTGSE - Port G Slew Rate Enable Register; 0xFFFF8069 ***
PTGSE:              .equ   $FFFF8069                                ;*** PTGSE - Port G Slew Rate Enable Register; 0xFFFF8069 ***
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


;*** PTGDS - Port G Drive Strength Selection Register; 0xFFFF806A ***
PTGDS:              .equ   $FFFF806A                                ;*** PTGDS - Port G Drive Strength Selection Register; 0xFFFF806A ***
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


;*** PTGIFE - Port G Input Filter Enable Register; 0xFFFF806B ***
PTGIFE:             .equ   $FFFF806B                                ;*** PTGIFE - Port G Input Filter Enable Register; 0xFFFF806B ***
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


;*** KBI1SC - KBI1 Status and Control Register; 0xFFFF806C ***
KBI1SC:             .equ   $FFFF806C                                ;*** KBI1SC - KBI1 Status and Control Register; 0xFFFF806C ***
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


;*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF806D ***
KBI1PE:             .equ   $FFFF806D                                ;*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF806D ***
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


;*** KBI1ES - KBI1 Edge Select Register; 0xFFFF806E ***
KBI1ES:             .equ   $FFFF806E                                ;*** KBI1ES - KBI1 Edge Select Register; 0xFFFF806E ***
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


;*** PTHD - Port H Data Register; 0xFFFF8070 ***
PTHD:               .equ   $FFFF8070                                ;*** PTHD - Port H Data Register; 0xFFFF8070 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHD_PTHD0:         .equ   0                                         ; Port H Data Register Bit 0
PTHD_PTHD1:         .equ   1                                         ; Port H Data Register Bit 1
PTHD_PTHD2:         .equ   2                                         ; Port H Data Register Bit 2
PTHD_PTHD3:         .equ   3                                         ; Port H Data Register Bit 3
PTHD_PTHD4:         .equ   4                                         ; Port H Data Register Bit 4
PTHD_PTHD5:         .equ   5                                         ; Port H Data Register Bit 5
PTHD_PTHD6:         .equ   6                                         ; Port H Data Register Bit 6
PTHD_PTHD7:         .equ   7                                         ; Port H Data Register Bit 7
; bit position masks
mPTHD_PTHD0:        .equ   %00000001
mPTHD_PTHD1:        .equ   %00000010
mPTHD_PTHD2:        .equ   %00000100
mPTHD_PTHD3:        .equ   %00001000
mPTHD_PTHD4:        .equ   %00010000
mPTHD_PTHD5:        .equ   %00100000
mPTHD_PTHD6:        .equ   %01000000
mPTHD_PTHD7:        .equ   %10000000


;*** PTHDD - Port H Data Direction Register; 0xFFFF8071 ***
PTHDD:              .equ   $FFFF8071                                ;*** PTHDD - Port H Data Direction Register; 0xFFFF8071 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDD_PTHDD0:       .equ   0                                         ; Data Direction for Port H Bit 0
PTHDD_PTHDD1:       .equ   1                                         ; Data Direction for Port H Bit 1
PTHDD_PTHDD2:       .equ   2                                         ; Data Direction for Port H Bit 2
PTHDD_PTHDD3:       .equ   3                                         ; Data Direction for Port H Bit 3
PTHDD_PTHDD4:       .equ   4                                         ; Data Direction for Port H Bit 4
PTHDD_PTHDD5:       .equ   5                                         ; Data Direction for Port H Bit 5
PTHDD_PTHDD6:       .equ   6                                         ; Data Direction for Port H Bit 6
PTHDD_PTHDD7:       .equ   7                                         ; Data Direction for Port H Bit 7
; bit position masks
mPTHDD_PTHDD0:      .equ   %00000001
mPTHDD_PTHDD1:      .equ   %00000010
mPTHDD_PTHDD2:      .equ   %00000100
mPTHDD_PTHDD3:      .equ   %00001000
mPTHDD_PTHDD4:      .equ   %00010000
mPTHDD_PTHDD5:      .equ   %00100000
mPTHDD_PTHDD6:      .equ   %01000000
mPTHDD_PTHDD7:      .equ   %10000000


;*** PTHPE - Port H Pull Enable Register; 0xFFFF8078 ***
PTHPE:              .equ   $FFFF8078                                ;*** PTHPE - Port H Pull Enable Register; 0xFFFF8078 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHPE_PTHPE0:       .equ   0                                         ; Internal Pull Enable for Port H Bit 0
PTHPE_PTHPE1:       .equ   1                                         ; Internal Pull Enable for Port H Bit 1
PTHPE_PTHPE2:       .equ   2                                         ; Internal Pull Enable for Port H Bit 2
PTHPE_PTHPE3:       .equ   3                                         ; Internal Pull Enable for Port H Bit 3
PTHPE_PTHPE4:       .equ   4                                         ; Internal Pull Enable for Port H Bit 4
PTHPE_PTHPE5:       .equ   5                                         ; Internal Pull Enable for Port H Bit 5
PTHPE_PTHPE6:       .equ   6                                         ; Internal Pull Enable for Port H Bit 6
PTHPE_PTHPE7:       .equ   7                                         ; Internal Pull Enable for Port H Bit 7
; bit position masks
mPTHPE_PTHPE0:      .equ   %00000001
mPTHPE_PTHPE1:      .equ   %00000010
mPTHPE_PTHPE2:      .equ   %00000100
mPTHPE_PTHPE3:      .equ   %00001000
mPTHPE_PTHPE4:      .equ   %00010000
mPTHPE_PTHPE5:      .equ   %00100000
mPTHPE_PTHPE6:      .equ   %01000000
mPTHPE_PTHPE7:      .equ   %10000000


;*** PTHSE - Port H Slew Rate Enable Register; 0xFFFF8079 ***
PTHSE:              .equ   $FFFF8079                                ;*** PTHSE - Port H Slew Rate Enable Register; 0xFFFF8079 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHSE_PTHSE0:       .equ   0                                         ; Output Slew Rate Enable for Port H Bit 0
PTHSE_PTHSE1:       .equ   1                                         ; Output Slew Rate Enable for Port H Bit 1
PTHSE_PTHSE2:       .equ   2                                         ; Output Slew Rate Enable for Port H Bit 2
PTHSE_PTHSE3:       .equ   3                                         ; Output Slew Rate Enable for Port H Bit 3
PTHSE_PTHSE4:       .equ   4                                         ; Output Slew Rate Enable for Port H Bit 4
PTHSE_PTHSE5:       .equ   5                                         ; Output Slew Rate Enable for Port H Bit 5
PTHSE_PTHSE6:       .equ   6                                         ; Output Slew Rate Enable for Port H Bit 6
PTHSE_PTHSE7:       .equ   7                                         ; Output Slew Rate Enable for Port H Bit 7
; bit position masks
mPTHSE_PTHSE0:      .equ   %00000001
mPTHSE_PTHSE1:      .equ   %00000010
mPTHSE_PTHSE2:      .equ   %00000100
mPTHSE_PTHSE3:      .equ   %00001000
mPTHSE_PTHSE4:      .equ   %00010000
mPTHSE_PTHSE5:      .equ   %00100000
mPTHSE_PTHSE6:      .equ   %01000000
mPTHSE_PTHSE7:      .equ   %10000000


;*** PTHDS - Port H Drive Strength Selection Register; 0xFFFF807A ***
PTHDS:              .equ   $FFFF807A                                ;*** PTHDS - Port H Drive Strength Selection Register; 0xFFFF807A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDS_PTHDS0:       .equ   0                                         ; Output Drive Strength Selection for Port H Bit 0
PTHDS_PTHDS1:       .equ   1                                         ; Output Drive Strength Selection for Port H Bit 1
PTHDS_PTHDS2:       .equ   2                                         ; Output Drive Strength Selection for Port H Bit 2
PTHDS_PTHDS3:       .equ   3                                         ; Output Drive Strength Selection for Port H Bit 3
PTHDS_PTHDS4:       .equ   4                                         ; Output Drive Strength Selection for Port H Bit 4
PTHDS_PTHDS5:       .equ   5                                         ; Output Drive Strength Selection for Port H Bit 5
PTHDS_PTHDS6:       .equ   6                                         ; Output Drive Strength Selection for Port H Bit 6
PTHDS_PTHDS7:       .equ   7                                         ; Output Drive Strength Selection for Port H Bit 7
; bit position masks
mPTHDS_PTHDS0:      .equ   %00000001
mPTHDS_PTHDS1:      .equ   %00000010
mPTHDS_PTHDS2:      .equ   %00000100
mPTHDS_PTHDS3:      .equ   %00001000
mPTHDS_PTHDS4:      .equ   %00010000
mPTHDS_PTHDS5:      .equ   %00100000
mPTHDS_PTHDS6:      .equ   %01000000
mPTHDS_PTHDS7:      .equ   %10000000


;*** PTHIFE - Port H Input Filter Enable Register; 0xFFFF807B ***
PTHIFE:             .equ   $FFFF807B                                ;*** PTHIFE - Port H Input Filter Enable Register; 0xFFFF807B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHIFE_PTHIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTHIFE_PTHIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTHIFE_PTHIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTHIFE_PTHIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTHIFE_PTHIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTHIFE_PTHIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
PTHIFE_PTHIFE6:     .equ   6                                         ; Port A Input Filter Enable Bit 6
PTHIFE_PTHIFE7:     .equ   7                                         ; Port A Input Filter Enable Bit 7
; bit position masks
mPTHIFE_PTHIFE0:    .equ   %00000001
mPTHIFE_PTHIFE1:    .equ   %00000010
mPTHIFE_PTHIFE2:    .equ   %00000100
mPTHIFE_PTHIFE3:    .equ   %00001000
mPTHIFE_PTHIFE4:    .equ   %00010000
mPTHIFE_PTHIFE5:    .equ   %00100000
mPTHIFE_PTHIFE6:    .equ   %01000000
mPTHIFE_PTHIFE7:    .equ   %10000000


;*** PTJD - Port J Data Register; 0xFFFF8080 ***
PTJD:               .equ   $FFFF8080                                ;*** PTJD - Port J Data Register; 0xFFFF8080 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJD_PTJD0:         .equ   0                                         ; Port J Data Register Bit 0
PTJD_PTJD1:         .equ   1                                         ; Port J Data Register Bit 1
PTJD_PTJD2:         .equ   2                                         ; Port J Data Register Bit 2
PTJD_PTJD3:         .equ   3                                         ; Port J Data Register Bit 3
PTJD_PTJD4:         .equ   4                                         ; Port J Data Register Bit 4
PTJD_PTJD5:         .equ   5                                         ; Port J Data Register Bit 5
; bit position masks
mPTJD_PTJD0:        .equ   %00000001
mPTJD_PTJD1:        .equ   %00000010
mPTJD_PTJD2:        .equ   %00000100
mPTJD_PTJD3:        .equ   %00001000
mPTJD_PTJD4:        .equ   %00010000
mPTJD_PTJD5:        .equ   %00100000


;*** PTJDD - Port J Data Direction Register; 0xFFFF8081 ***
PTJDD:              .equ   $FFFF8081                                ;*** PTJDD - Port J Data Direction Register; 0xFFFF8081 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJDD_PTJDD0:       .equ   0                                         ; Data Direction for Port J Bit 0
PTJDD_PTJDD1:       .equ   1                                         ; Data Direction for Port J Bit 1
PTJDD_PTJDD2:       .equ   2                                         ; Data Direction for Port J Bit 2
PTJDD_PTJDD3:       .equ   3                                         ; Data Direction for Port J Bit 3
PTJDD_PTJDD4:       .equ   4                                         ; Data Direction for Port J Bit 4
PTJDD_PTJDD5:       .equ   5                                         ; Data Direction for Port J Bit 5
; bit position masks
mPTJDD_PTJDD0:      .equ   %00000001
mPTJDD_PTJDD1:      .equ   %00000010
mPTJDD_PTJDD2:      .equ   %00000100
mPTJDD_PTJDD3:      .equ   %00001000
mPTJDD_PTJDD4:      .equ   %00010000
mPTJDD_PTJDD5:      .equ   %00100000


;*** PTJPE - Port J Pull Enable Register; 0xFFFF8088 ***
PTJPE:              .equ   $FFFF8088                                ;*** PTJPE - Port J Pull Enable Register; 0xFFFF8088 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJPE_PTJPE0:       .equ   0                                         ; Internal Pull Enable for Port J Bit 0
PTJPE_PTJPE1:       .equ   1                                         ; Internal Pull Enable for Port J Bit 1
PTJPE_PTJPE2:       .equ   2                                         ; Internal Pull Enable for Port J Bit 2
PTJPE_PTJPE3:       .equ   3                                         ; Internal Pull Enable for Port J Bit 3
PTJPE_PTJPE4:       .equ   4                                         ; Internal Pull Enable for Port J Bit 4
PTJPE_PTJPE5:       .equ   5                                         ; Internal Pull Enable for Port J Bit 5
; bit position masks
mPTJPE_PTJPE0:      .equ   %00000001
mPTJPE_PTJPE1:      .equ   %00000010
mPTJPE_PTJPE2:      .equ   %00000100
mPTJPE_PTJPE3:      .equ   %00001000
mPTJPE_PTJPE4:      .equ   %00010000
mPTJPE_PTJPE5:      .equ   %00100000


;*** PTJSE - Port J Slew Rate Enable Register; 0xFFFF8089 ***
PTJSE:              .equ   $FFFF8089                                ;*** PTJSE - Port J Slew Rate Enable Register; 0xFFFF8089 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJSE_PTJSE0:       .equ   0                                         ; Output Slew Rate Enable for Port J Bit 0
PTJSE_PTJSE1:       .equ   1                                         ; Output Slew Rate Enable for Port J Bit 1
PTJSE_PTJSE2:       .equ   2                                         ; Output Slew Rate Enable for Port J Bit 2
PTJSE_PTJSE3:       .equ   3                                         ; Output Slew Rate Enable for Port J Bit 3
PTJSE_PTJSE4:       .equ   4                                         ; Output Slew Rate Enable for Port J Bit 4
PTJSE_PTJSE5:       .equ   5                                         ; Output Slew Rate Enable for Port J Bit 5
; bit position masks
mPTJSE_PTJSE0:      .equ   %00000001
mPTJSE_PTJSE1:      .equ   %00000010
mPTJSE_PTJSE2:      .equ   %00000100
mPTJSE_PTJSE3:      .equ   %00001000
mPTJSE_PTJSE4:      .equ   %00010000
mPTJSE_PTJSE5:      .equ   %00100000


;*** PTJDS - Port J Drive Strength Selection Register; 0xFFFF808A ***
PTJDS:              .equ   $FFFF808A                                ;*** PTJDS - Port J Drive Strength Selection Register; 0xFFFF808A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJDS_PTJDS0:       .equ   0                                         ; Output Drive Strength Selection for Port J Bit 0
PTJDS_PTJDS1:       .equ   1                                         ; Output Drive Strength Selection for Port J Bit 1
PTJDS_PTJDS2:       .equ   2                                         ; Output Drive Strength Selection for Port J Bit 2
PTJDS_PTJDS3:       .equ   3                                         ; Output Drive Strength Selection for Port J Bit 3
PTJDS_PTJDS4:       .equ   4                                         ; Output Drive Strength Selection for Port J Bit 4
PTJDS_PTJDS5:       .equ   5                                         ; Output Drive Strength Selection for Port J Bit 5
; bit position masks
mPTJDS_PTJDS0:      .equ   %00000001
mPTJDS_PTJDS1:      .equ   %00000010
mPTJDS_PTJDS2:      .equ   %00000100
mPTJDS_PTJDS3:      .equ   %00001000
mPTJDS_PTJDS4:      .equ   %00010000
mPTJDS_PTJDS5:      .equ   %00100000


;*** PTJIFE - Port J Input Filter Enable Register; 0xFFFF808B ***
PTJIFE:             .equ   $FFFF808B                                ;*** PTJIFE - Port J Input Filter Enable Register; 0xFFFF808B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJIFE_PTJIFE0:     .equ   0                                         ; Port A Input Filter Enable Bit 0
PTJIFE_PTJIFE1:     .equ   1                                         ; Port A Input Filter Enable Bit 1
PTJIFE_PTJIFE2:     .equ   2                                         ; Port A Input Filter Enable Bit 2
PTJIFE_PTJIFE3:     .equ   3                                         ; Port A Input Filter Enable Bit 3
PTJIFE_PTJIFE4:     .equ   4                                         ; Port A Input Filter Enable Bit 4
PTJIFE_PTJIFE5:     .equ   5                                         ; Port A Input Filter Enable Bit 5
; bit position masks
mPTJIFE_PTJIFE0:    .equ   %00000001
mPTJIFE_PTJIFE1:    .equ   %00000010
mPTJIFE_PTJIFE2:    .equ   %00000100
mPTJIFE_PTJIFE3:    .equ   %00001000
mPTJIFE_PTJIFE4:    .equ   %00010000
mPTJIFE_PTJIFE5:    .equ   %00100000


;*** PTAPF1 - Port A Routing Register 1; 0xFFFF80C0 ***
PTAPF1:             .equ   $FFFF80C0                                ;*** PTAPF1 - Port A Routing Register 1; 0xFFFF80C0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPF1_A40:         .equ   0                                         ; Port PTA4 Pin Mux Controls, bit 0
PTAPF1_A41:         .equ   1                                         ; Port PTA4 Pin Mux Controls, bit 1
PTAPF1_A50:         .equ   2                                         ; Port PTA5 Pin Mux Controls, bit 0
PTAPF1_A51:         .equ   3                                         ; Port PTA5 Pin Mux Controls, bit 1
PTAPF1_A60:         .equ   4                                         ; Port PTA6 Pin Mux Controls, bit 0
PTAPF1_A61:         .equ   5                                         ; Port PTA6 Pin Mux Controls, bit 1
PTAPF1_A70:         .equ   6                                         ; Port PTA7 Pin Mux Controls, bit 0
PTAPF1_A71:         .equ   7                                         ; Port PTA7 Pin Mux Controls, bit 1
; bit position masks
mPTAPF1_A40:        .equ   %00000001
mPTAPF1_A41:        .equ   %00000010
mPTAPF1_A50:        .equ   %00000100
mPTAPF1_A51:        .equ   %00001000
mPTAPF1_A60:        .equ   %00010000
mPTAPF1_A61:        .equ   %00100000
mPTAPF1_A70:        .equ   %01000000
mPTAPF1_A71:        .equ   %10000000


;*** PTAPF2 - Port A Routing Register 2; 0xFFFF80C1 ***
PTAPF2:             .equ   $FFFF80C1                                ;*** PTAPF2 - Port A Routing Register 2; 0xFFFF80C1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPF2_A00:         .equ   0                                         ; Port PTA0 Pin Mux Controls, bit 0
PTAPF2_A01:         .equ   1                                         ; Port PTA0 Pin Mux Controls, bit 1
PTAPF2_A10:         .equ   2                                         ; Port PTA1 Pin Mux Controls, bit 0
PTAPF2_A11:         .equ   3                                         ; Port PTA1 Pin Mux Controls, bit 1
PTAPF2_A20:         .equ   4                                         ; Port PTA2 Pin Mux Controls, bit 0
PTAPF2_A21:         .equ   5                                         ; Port PTA2 Pin Mux Controls, bit 1
PTAPF2_A30:         .equ   6                                         ; Port PTA3 Pin Mux Controls, bit 0
PTAPF2_A31:         .equ   7                                         ; Port PTA3 Pin Mux Controls, bit 1
; bit position masks
mPTAPF2_A00:        .equ   %00000001
mPTAPF2_A01:        .equ   %00000010
mPTAPF2_A10:        .equ   %00000100
mPTAPF2_A11:        .equ   %00001000
mPTAPF2_A20:        .equ   %00010000
mPTAPF2_A21:        .equ   %00100000
mPTAPF2_A30:        .equ   %01000000
mPTAPF2_A31:        .equ   %10000000


;*** PTBPF1 - Port B Routing Register 1; 0xFFFF80C2 ***
PTBPF1:             .equ   $FFFF80C2                                ;*** PTBPF1 - Port B Routing Register 1; 0xFFFF80C2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPF1_B40:         .equ   0                                         ; Port PTB4 Pin Mux Controls, bit 0
PTBPF1_B41:         .equ   1                                         ; Port PTB4 Pin Mux Controls, bit 1
PTBPF1_B50:         .equ   2                                         ; Port PTB5 Pin Mux Controls, bit 0
PTBPF1_B51:         .equ   3                                         ; Port PTB5 Pin Mux Controls, bit 1
PTBPF1_B60:         .equ   4                                         ; Port PTB6 Pin Mux Controls, bit 0
PTBPF1_B61:         .equ   5                                         ; Port PTB6 Pin Mux Controls, bit 1
PTBPF1_B70:         .equ   6                                         ; Port PTB7 Pin Mux Controls, bit 0
PTBPF1_B71:         .equ   7                                         ; Port PTB7 Pin Mux Controls, bit 1
; bit position masks
mPTBPF1_B40:        .equ   %00000001
mPTBPF1_B41:        .equ   %00000010
mPTBPF1_B50:        .equ   %00000100
mPTBPF1_B51:        .equ   %00001000
mPTBPF1_B60:        .equ   %00010000
mPTBPF1_B61:        .equ   %00100000
mPTBPF1_B70:        .equ   %01000000
mPTBPF1_B71:        .equ   %10000000


;*** PTBPF2 - Port B Routing Register 2; 0xFFFF80C3 ***
PTBPF2:             .equ   $FFFF80C3                                ;*** PTBPF2 - Port B Routing Register 2; 0xFFFF80C3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPF2_B00:         .equ   0                                         ; Port PTB0 Pin Mux Controls, bit 0
PTBPF2_B01:         .equ   1                                         ; Port PTB0 Pin Mux Controls, bit 1
PTBPF2_B10:         .equ   2                                         ; Port PTB1 Pin Mux Controls, bit 0
PTBPF2_B11:         .equ   3                                         ; Port PTB1 Pin Mux Controls, bit 1
PTBPF2_B20:         .equ   4                                         ; Port PTB2 Pin Mux Controls, bit 0
PTBPF2_B21:         .equ   5                                         ; Port PTB2 Pin Mux Controls, bit 1
PTBPF2_B30:         .equ   6                                         ; Port PTB3 Pin Mux Controls, bit 0
PTBPF2_B31:         .equ   7                                         ; Port PTB3 Pin Mux Controls, bit 1
; bit position masks
mPTBPF2_B00:        .equ   %00000001
mPTBPF2_B01:        .equ   %00000010
mPTBPF2_B10:        .equ   %00000100
mPTBPF2_B11:        .equ   %00001000
mPTBPF2_B20:        .equ   %00010000
mPTBPF2_B21:        .equ   %00100000
mPTBPF2_B30:        .equ   %01000000
mPTBPF2_B31:        .equ   %10000000


;*** PTCPF1 - Port C Routing Register 1; 0xFFFF80C4 ***
PTCPF1:             .equ   $FFFF80C4                                ;*** PTCPF1 - Port C Routing Register 1; 0xFFFF80C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPF1_C40:         .equ   0                                         ; Port PTC4 Pin Mux Controls, bit 0
PTCPF1_C41:         .equ   1                                         ; Port PTC4 Pin Mux Controls, bit 1
PTCPF1_C50:         .equ   2                                         ; Port PTC5 Pin Mux Controls, bit 0
PTCPF1_C51:         .equ   3                                         ; Port PTC5 Pin Mux Controls, bit 1
PTCPF1_C60:         .equ   4                                         ; Port PTC6 Pin Mux Controls, bit 0
PTCPF1_C61:         .equ   5                                         ; Port PTC6 Pin Mux Controls, bit 1
PTCPF1_C70:         .equ   6                                         ; Port PTC7 Pin Mux Controls, bit 0
PTCPF1_C71:         .equ   7                                         ; Port PTC7 Pin Mux Controls, bit 1
; bit position masks
mPTCPF1_C40:        .equ   %00000001
mPTCPF1_C41:        .equ   %00000010
mPTCPF1_C50:        .equ   %00000100
mPTCPF1_C51:        .equ   %00001000
mPTCPF1_C60:        .equ   %00010000
mPTCPF1_C61:        .equ   %00100000
mPTCPF1_C70:        .equ   %01000000
mPTCPF1_C71:        .equ   %10000000


;*** PTCPF2 - Port C Routing Register 2; 0xFFFF80C5 ***
PTCPF2:             .equ   $FFFF80C5                                ;*** PTCPF2 - Port C Routing Register 2; 0xFFFF80C5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPF2_C00:         .equ   0                                         ; Port PTC0 Pin Mux Controls, bit 0
PTCPF2_C01:         .equ   1                                         ; Port PTC0 Pin Mux Controls, bit 1
PTCPF2_C10:         .equ   2                                         ; Port PTC1 Pin Mux Controls, bit 0
PTCPF2_C11:         .equ   3                                         ; Port PTC1 Pin Mux Controls, bit 1
PTCPF2_C20:         .equ   4                                         ; Port PTC2 Pin Mux Controls, bit 0
PTCPF2_C21:         .equ   5                                         ; Port PTC2 Pin Mux Controls, bit 1
PTCPF2_C30:         .equ   6                                         ; Port PTC3 Pin Mux Controls, bit 0
PTCPF2_C31:         .equ   7                                         ; Port PTC3 Pin Mux Controls, bit 1
; bit position masks
mPTCPF2_C00:        .equ   %00000001
mPTCPF2_C01:        .equ   %00000010
mPTCPF2_C10:        .equ   %00000100
mPTCPF2_C11:        .equ   %00001000
mPTCPF2_C20:        .equ   %00010000
mPTCPF2_C21:        .equ   %00100000
mPTCPF2_C30:        .equ   %01000000
mPTCPF2_C31:        .equ   %10000000


;*** PTDPF1 - Port D Routing Register 1; 0xFFFF80C6 ***
PTDPF1:             .equ   $FFFF80C6                                ;*** PTDPF1 - Port D Routing Register 1; 0xFFFF80C6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPF1_D40:         .equ   0                                         ; Port PTD4 Pin Mux Controls, bit 0
PTDPF1_D41:         .equ   1                                         ; Port PTD4 Pin Mux Controls, bit 1
PTDPF1_D50:         .equ   2                                         ; Port PTD5 Pin Mux Controls, bit 0
PTDPF1_D51:         .equ   3                                         ; Port PTD5 Pin Mux Controls, bit 1
PTDPF1_D60:         .equ   4                                         ; Port PTD6 Pin Mux Controls, bit 0
PTDPF1_D61:         .equ   5                                         ; Port PTD6 Pin Mux Controls, bit 1
PTDPF1_D70:         .equ   6                                         ; Port PTD7 Pin Mux Controls, bit 0
PTDPF1_D71:         .equ   7                                         ; Port PTD7 Pin Mux Controls, bit 1
; bit position masks
mPTDPF1_D40:        .equ   %00000001
mPTDPF1_D41:        .equ   %00000010
mPTDPF1_D50:        .equ   %00000100
mPTDPF1_D51:        .equ   %00001000
mPTDPF1_D60:        .equ   %00010000
mPTDPF1_D61:        .equ   %00100000
mPTDPF1_D70:        .equ   %01000000
mPTDPF1_D71:        .equ   %10000000


;*** PTDPF2 - Port D Routing Register 2; 0xFFFF80C7 ***
PTDPF2:             .equ   $FFFF80C7                                ;*** PTDPF2 - Port D Routing Register 2; 0xFFFF80C7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPF2_D00:         .equ   0                                         ; Port PTD0 Pin Mux Controls, bit 0
PTDPF2_D01:         .equ   1                                         ; Port PTD0 Pin Mux Controls, bit 1
PTDPF2_D10:         .equ   2                                         ; Port PTD1 Pin Mux Controls, bit 0
PTDPF2_D11:         .equ   3                                         ; Port PTD1 Pin Mux Controls, bit 1
PTDPF2_D20:         .equ   4                                         ; Port PTD2 Pin Mux Controls, bit 0
PTDPF2_D21:         .equ   5                                         ; Port PTD2 Pin Mux Controls, bit 1
PTDPF2_D30:         .equ   6                                         ; Port PTD3 Pin Mux Controls, bit 0
PTDPF2_D31:         .equ   7                                         ; Port PTD3 Pin Mux Controls, bit 1
; bit position masks
mPTDPF2_D00:        .equ   %00000001
mPTDPF2_D01:        .equ   %00000010
mPTDPF2_D10:        .equ   %00000100
mPTDPF2_D11:        .equ   %00001000
mPTDPF2_D20:        .equ   %00010000
mPTDPF2_D21:        .equ   %00100000
mPTDPF2_D30:        .equ   %01000000
mPTDPF2_D31:        .equ   %10000000


;*** PTEPF1 - Port E Routing Register 1; 0xFFFF80C8 ***
PTEPF1:             .equ   $FFFF80C8                                ;*** PTEPF1 - Port E Routing Register 1; 0xFFFF80C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPF1_E40:         .equ   0                                         ; Port PTE4 Pin Mux Controls, bit 0
PTEPF1_E41:         .equ   1                                         ; Port PTE4 Pin Mux Controls, bit 1
PTEPF1_E50:         .equ   2                                         ; Port PTE5 Pin Mux Controls, bit 0
PTEPF1_E51:         .equ   3                                         ; Port PTE5 Pin Mux Controls, bit 1
PTEPF1_E60:         .equ   4                                         ; Port PTE6 Pin Mux Controls, bit 0
PTEPF1_E61:         .equ   5                                         ; Port PTE6 Pin Mux Controls, bit 1
PTEPF1_E70:         .equ   6                                         ; Port PTE7 Pin Mux Controls, bit 0
PTEPF1_E71:         .equ   7                                         ; Port PTE7 Pin Mux Controls, bit 1
; bit position masks
mPTEPF1_E40:        .equ   %00000001
mPTEPF1_E41:        .equ   %00000010
mPTEPF1_E50:        .equ   %00000100
mPTEPF1_E51:        .equ   %00001000
mPTEPF1_E60:        .equ   %00010000
mPTEPF1_E61:        .equ   %00100000
mPTEPF1_E70:        .equ   %01000000
mPTEPF1_E71:        .equ   %10000000


;*** PTEPF2 - Port E Routing Register 2; 0xFFFF80C9 ***
PTEPF2:             .equ   $FFFF80C9                                ;*** PTEPF2 - Port E Routing Register 2; 0xFFFF80C9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPF2_E00:         .equ   0                                         ; Port PTE0 Pin Mux Controls, bit 0
PTEPF2_E01:         .equ   1                                         ; Port PTE0 Pin Mux Controls, bit 1
PTEPF2_E10:         .equ   2                                         ; Port PTE1 Pin Mux Controls, bit 0
PTEPF2_E11:         .equ   3                                         ; Port PTE1 Pin Mux Controls, bit 1
PTEPF2_E20:         .equ   4                                         ; Port PTE2 Pin Mux Controls, bit 0
PTEPF2_E21:         .equ   5                                         ; Port PTE2 Pin Mux Controls, bit 1
PTEPF2_E30:         .equ   6                                         ; Port PTE3 Pin Mux Controls, bit 0
PTEPF2_E31:         .equ   7                                         ; Port PTE3 Pin Mux Controls, bit 1
; bit position masks
mPTEPF2_E00:        .equ   %00000001
mPTEPF2_E01:        .equ   %00000010
mPTEPF2_E10:        .equ   %00000100
mPTEPF2_E11:        .equ   %00001000
mPTEPF2_E20:        .equ   %00010000
mPTEPF2_E21:        .equ   %00100000
mPTEPF2_E30:        .equ   %01000000
mPTEPF2_E31:        .equ   %10000000


;*** PTFPF1 - Port F Routing Register 1; 0xFFFF80CA ***
PTFPF1:             .equ   $FFFF80CA                                ;*** PTFPF1 - Port F Routing Register 1; 0xFFFF80CA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPF1_F40:         .equ   0                                         ; Port PTF4 Pin Mux Controls, bit 0
PTFPF1_F41:         .equ   1                                         ; Port PTF4 Pin Mux Controls, bit 1
PTFPF1_F50:         .equ   2                                         ; Port PTF5 Pin Mux Controls, bit 0
PTFPF1_F51:         .equ   3                                         ; Port PTF5 Pin Mux Controls, bit 1
PTFPF1_F60:         .equ   4                                         ; Port PTF6 Pin Mux Controls, bit 0
PTFPF1_F61:         .equ   5                                         ; Port PTF6 Pin Mux Controls, bit 1
PTFPF1_F70:         .equ   6                                         ; Port PTF7 Pin Mux Controls, bit 0
PTFPF1_F71:         .equ   7                                         ; Port PTF7 Pin Mux Controls, bit 1
; bit position masks
mPTFPF1_F40:        .equ   %00000001
mPTFPF1_F41:        .equ   %00000010
mPTFPF1_F50:        .equ   %00000100
mPTFPF1_F51:        .equ   %00001000
mPTFPF1_F60:        .equ   %00010000
mPTFPF1_F61:        .equ   %00100000
mPTFPF1_F70:        .equ   %01000000
mPTFPF1_F71:        .equ   %10000000


;*** PTFPF2 - Port F Routing Register 2; 0xFFFF80CB ***
PTFPF2:             .equ   $FFFF80CB                                ;*** PTFPF2 - Port F Routing Register 2; 0xFFFF80CB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPF2_F00:         .equ   0                                         ; Port PTF0 Pin Mux Controls, bit 0
PTFPF2_F01:         .equ   1                                         ; Port PTF0 Pin Mux Controls, bit 1
PTFPF2_F10:         .equ   2                                         ; Port PTF1 Pin Mux Controls, bit 0
PTFPF2_F11:         .equ   3                                         ; Port PTF1 Pin Mux Controls, bit 1
PTFPF2_F20:         .equ   4                                         ; Port PTF2 Pin Mux Controls, bit 0
PTFPF2_F21:         .equ   5                                         ; Port PTF2 Pin Mux Controls, bit 1
PTFPF2_F30:         .equ   6                                         ; Port PTF3 Pin Mux Controls, bit 0
PTFPF2_F31:         .equ   7                                         ; Port PTF3 Pin Mux Controls, bit 1
; bit position masks
mPTFPF2_F00:        .equ   %00000001
mPTFPF2_F01:        .equ   %00000010
mPTFPF2_F10:        .equ   %00000100
mPTFPF2_F11:        .equ   %00001000
mPTFPF2_F20:        .equ   %00010000
mPTFPF2_F21:        .equ   %00100000
mPTFPF2_F30:        .equ   %01000000
mPTFPF2_F31:        .equ   %10000000


;*** PTGPF1 - Port G Routing Register 1; 0xFFFF80CC ***
PTGPF1:             .equ   $FFFF80CC                                ;*** PTGPF1 - Port G Routing Register 1; 0xFFFF80CC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPF1_G40:         .equ   0                                         ; Port PTG4 Pin Mux Controls, bit 0
PTGPF1_G41:         .equ   1                                         ; Port PTG4 Pin Mux Controls, bit 1
PTGPF1_G50:         .equ   2                                         ; Port PTG5 Pin Mux Controls, bit 0
PTGPF1_G51:         .equ   3                                         ; Port PTG5 Pin Mux Controls, bit 1
PTGPF1_G60:         .equ   4                                         ; Port PTG6 Pin Mux Controls, bit 0
PTGPF1_G61:         .equ   5                                         ; Port PTG6 Pin Mux Controls, bit 1
PTGPF1_G70:         .equ   6                                         ; Port PTG7 Pin Mux Controls, bit 0
PTGPF1_G71:         .equ   7                                         ; Port PTG7 Pin Mux Controls, bit 1
; bit position masks
mPTGPF1_G40:        .equ   %00000001
mPTGPF1_G41:        .equ   %00000010
mPTGPF1_G50:        .equ   %00000100
mPTGPF1_G51:        .equ   %00001000
mPTGPF1_G60:        .equ   %00010000
mPTGPF1_G61:        .equ   %00100000
mPTGPF1_G70:        .equ   %01000000
mPTGPF1_G71:        .equ   %10000000


;*** PTGPF2 - Port G Routing Register 2; 0xFFFF80CD ***
PTGPF2:             .equ   $FFFF80CD                                ;*** PTGPF2 - Port G Routing Register 2; 0xFFFF80CD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPF2_G00:         .equ   0                                         ; Port PTG0 Pin Mux Controls, bit 0
PTGPF2_G01:         .equ   1                                         ; Port PTG0 Pin Mux Controls, bit 1
PTGPF2_G10:         .equ   2                                         ; Port PTG1 Pin Mux Controls, bit 0
PTGPF2_G11:         .equ   3                                         ; Port PTG1 Pin Mux Controls, bit 1
PTGPF2_G20:         .equ   4                                         ; Port PTG2 Pin Mux Controls, bit 0
PTGPF2_G21:         .equ   5                                         ; Port PTG2 Pin Mux Controls, bit 1
PTGPF2_G30:         .equ   6                                         ; Port PTG3 Pin Mux Controls, bit 0
PTGPF2_G31:         .equ   7                                         ; Port PTG3 Pin Mux Controls, bit 1
; bit position masks
mPTGPF2_G00:        .equ   %00000001
mPTGPF2_G01:        .equ   %00000010
mPTGPF2_G10:        .equ   %00000100
mPTGPF2_G11:        .equ   %00001000
mPTGPF2_G20:        .equ   %00010000
mPTGPF2_G21:        .equ   %00100000
mPTGPF2_G30:        .equ   %01000000
mPTGPF2_G31:        .equ   %10000000


;*** PTHPF1 - Port H Routing Register 1; 0xFFFF80CE ***
PTHPF1:             .equ   $FFFF80CE                                ;*** PTHPF1 - Port H Routing Register 1; 0xFFFF80CE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHPF1_H40:         .equ   0                                         ; Port PTH4 Pin Mux Controls, bit 0
PTHPF1_H41:         .equ   1                                         ; Port PTH4 Pin Mux Controls, bit 1
PTHPF1_H50:         .equ   2                                         ; Port PTH5 Pin Mux Controls, bit 0
PTHPF1_H51:         .equ   3                                         ; Port PTH5 Pin Mux Controls, bit 1
PTHPF1_H60:         .equ   4                                         ; Port PTH6 Pin Mux Controls, bit 0
PTHPF1_H61:         .equ   5                                         ; Port PTH6 Pin Mux Controls, bit 1
PTHPF1_H70:         .equ   6                                         ; Port PTH7 Pin Mux Controls, bit 0
PTHPF1_H71:         .equ   7                                         ; Port PTH7 Pin Mux Controls, bit 1
; bit position masks
mPTHPF1_H40:        .equ   %00000001
mPTHPF1_H41:        .equ   %00000010
mPTHPF1_H50:        .equ   %00000100
mPTHPF1_H51:        .equ   %00001000
mPTHPF1_H60:        .equ   %00010000
mPTHPF1_H61:        .equ   %00100000
mPTHPF1_H70:        .equ   %01000000
mPTHPF1_H71:        .equ   %10000000


;*** PTHPF2 - Port H Routing Register 2; 0xFFFF80CF ***
PTHPF2:             .equ   $FFFF80CF                                ;*** PTHPF2 - Port H Routing Register 2; 0xFFFF80CF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHPF2_H00:         .equ   0                                         ; Port PTH0 Pin Mux Controls, bit 0
PTHPF2_H01:         .equ   1                                         ; Port PTH0 Pin Mux Controls, bit 1
PTHPF2_H10:         .equ   2                                         ; Port PTH1 Pin Mux Controls, bit 0
PTHPF2_H11:         .equ   3                                         ; Port PTH1 Pin Mux Controls, bit 1
PTHPF2_H20:         .equ   4                                         ; Port PTH2 Pin Mux Controls, bit 0
PTHPF2_H21:         .equ   5                                         ; Port PTH2 Pin Mux Controls, bit 1
PTHPF2_H30:         .equ   6                                         ; Port PTH3 Pin Mux Controls, bit 0
PTHPF2_H31:         .equ   7                                         ; Port PTH3 Pin Mux Controls, bit 1
; bit position masks
mPTHPF2_H00:        .equ   %00000001
mPTHPF2_H01:        .equ   %00000010
mPTHPF2_H10:        .equ   %00000100
mPTHPF2_H11:        .equ   %00001000
mPTHPF2_H20:        .equ   %00010000
mPTHPF2_H21:        .equ   %00100000
mPTHPF2_H30:        .equ   %01000000
mPTHPF2_H31:        .equ   %10000000


;*** PTJPF1 - Port J Routing Register 1; 0xFFFF80D0 ***
PTJPF1:             .equ   $FFFF80D0                                ;*** PTJPF1 - Port J Routing Register 1; 0xFFFF80D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJPF1_J40:         .equ   0                                         ; Port PTJ4 Pin Mux Controls, bit 0
PTJPF1_J41:         .equ   1                                         ; Port PTJ4 Pin Mux Controls, bit 1
PTJPF1_J50:         .equ   2                                         ; Port PTJ5 Pin Mux Controls, bit 0
PTJPF1_J51:         .equ   3                                         ; Port PTJ5 Pin Mux Controls, bit 1
; bit position masks
mPTJPF1_J40:        .equ   %00000001
mPTJPF1_J41:        .equ   %00000010
mPTJPF1_J50:        .equ   %00000100
mPTJPF1_J51:        .equ   %00001000


;*** PTJPF2 - Port J Routing Register 2; 0xFFFF80D1 ***
PTJPF2:             .equ   $FFFF80D1                                ;*** PTJPF2 - Port J Routing Register 2; 0xFFFF80D1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJPF2_J00:         .equ   0                                         ; Port PTJ0 Pin Mux Controls, bit 0
PTJPF2_J01:         .equ   1                                         ; Port PTJ0 Pin Mux Controls, bit 1
PTJPF2_J10:         .equ   2                                         ; Port PTJ1 Pin Mux Controls, bit 0
PTJPF2_J11:         .equ   3                                         ; Port PTJ1 Pin Mux Controls, bit 1
PTJPF2_J20:         .equ   4                                         ; Port PTJ2 Pin Mux Controls, bit 0
PTJPF2_J21:         .equ   5                                         ; Port PTJ2 Pin Mux Controls, bit 1
PTJPF2_J30:         .equ   6                                         ; Port PTJ3 Pin Mux Controls, bit 0
PTJPF2_J31:         .equ   7                                         ; Port PTJ3 Pin Mux Controls, bit 1
; bit position masks
mPTJPF2_J00:        .equ   %00000001
mPTJPF2_J01:        .equ   %00000010
mPTJPF2_J10:        .equ   %00000100
mPTJPF2_J11:        .equ   %00001000
mPTJPF2_J20:        .equ   %00010000
mPTJPF2_J21:        .equ   %00100000
mPTJPF2_J30:        .equ   %01000000
mPTJPF2_J31:        .equ   %10000000


;*** IRQSC - Interrupt request status and control register; 0xFFFF80E0 ***
IRQSC:              .equ   $FFFF80E0                                ;*** IRQSC - Interrupt request status and control register; 0xFFFF80E0 ***
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


;*** SRS - System Reset Status Register; 0xFFFF8100 ***
SRS:                .equ   $FFFF8100                                ;*** SRS - System Reset Status Register; 0xFFFF8100 ***
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


;*** SOPT1 - System Options Register 1; 0xFFFF8101 ***
SOPT1:              .equ   $FFFF8101                                ;*** SOPT1 - System Options Register 1; 0xFFFF8101 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_COPW:         .equ   0                                         ; COP Window Mode
SOPT1_COPCLKS:      .equ   1                                         ; COP Watchdog Clock Select
SOPT1_COPT0:        .equ   2                                         ; COP Watchdog Timeout, bit 0
SOPT1_COPT1:        .equ   3                                         ; COP Watchdog Timeout, bit 1
SOPT1_WAITE:        .equ   4                                         ; WAIT Mode Enable
SOPT1_STOPE:        .equ   5                                         ; Stop Mode Enable
SOPT1_SL:           .equ   6                                         ; Security Level
; bit position masks
mSOPT1_COPW:        .equ   %00000001
mSOPT1_COPCLKS:     .equ   %00000010
mSOPT1_COPT0:       .equ   %00000100
mSOPT1_COPT1:       .equ   %00001000
mSOPT1_WAITE:       .equ   %00010000
mSOPT1_STOPE:       .equ   %00100000
mSOPT1_SL:          .equ   %01000000


;*** SOPT3 - SIM Options Register 3; 0xFFFF8103 ***
SOPT3:              .equ   $FFFF8103                                ;*** SOPT3 - SIM Options Register 3; 0xFFFF8103 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT3_PCS0:         .equ   0                                         ; Phy Clock Select, bit 0
SOPT3_PCS1:         .equ   1                                         ; Phy Clock Select, bit 1
SOPT3_CS0:          .equ   2                                         ; CLKOUT Select, bit 0
SOPT3_CS1:          .equ   3                                         ; CLKOUT Select, bit 1
SOPT3_CS2:          .equ   4                                         ; CLKOUT Select, bit 2
; bit position masks
mSOPT3_PCS0:        .equ   %00000001
mSOPT3_PCS1:        .equ   %00000010
mSOPT3_CS0:         .equ   %00000100
mSOPT3_CS1:         .equ   %00001000
mSOPT3_CS2:         .equ   %00010000


;*** SDID - System Device Identification Register; 0xFFFF8106 ***
SDID:               .equ   $FFFF8106                                ;*** SDID - System Device Identification Register; 0xFFFF8106 ***
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
SDID_REV0:          .equ   12                                        ; Revision Number
SDID_REV1:          .equ   13                                        ; Revision Number, bit 1
SDID_REV2:          .equ   14                                        ; Revision Number, bit 2
SDID_REV3:          .equ   15                                        ; Revision Number, bit 3
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


;*** SDIDH - System Device Identification Register High; 0xFFFF8106 ***
SDIDH:              .equ   $FFFF8106                                ;*** SDIDH - System Device Identification Register High; 0xFFFF8106 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8:          .equ   0                                         ; Part Identification Number, bit 8
SDIDH_ID9:          .equ   1                                         ; Part Identification Number, bit 9
SDIDH_ID10:         .equ   2                                         ; Part Identification Number, bit 10
SDIDH_ID11:         .equ   3                                         ; Part Identification Number, bit 11
SDIDH_REV0:         .equ   4                                         ; Revision Number, bit 0
SDIDH_REV1:         .equ   5                                         ; Revision Number, bit 1
SDIDH_REV2:         .equ   6                                         ; Revision Number, bit 2
SDIDH_REV3:         .equ   7                                         ; Revision Number, bit 3
; bit position masks
mSDIDH_ID8:         .equ   %00000001
mSDIDH_ID9:         .equ   %00000010
mSDIDH_ID10:        .equ   %00000100
mSDIDH_ID11:        .equ   %00001000
mSDIDH_REV0:        .equ   %00010000
mSDIDH_REV1:        .equ   %00100000
mSDIDH_REV2:        .equ   %01000000
mSDIDH_REV3:        .equ   %10000000


;*** SDIDL - System Device Identification Register Low; 0xFFFF8107 ***
SDIDL:              .equ   $FFFF8107                                ;*** SDIDL - System Device Identification Register Low; 0xFFFF8107 ***
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


;*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF8108 ***
SCGC1:              .equ   $FFFF8108                                ;*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF8108 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI1:         .equ   0                                         ; SCI1 Clock Gate Control
SCGC1_SCI2:         .equ   1                                         ; SCI2 Clock Gate Control
SCGC1_IIC1:         .equ   2                                         ; IIC1 Clock Gate Control
SCGC1_IIC2:         .equ   3                                         ; IIC2 Clock Gate Control
SCGC1_ADC:          .equ   4                                         ; ADC Clock Gate Control
SCGC1_TPM1:         .equ   5                                         ; TPM1 Clock Gate Control
SCGC1_TPM2:         .equ   6                                         ; TPM2 Clock Gate Control
SCGC1_MTIM1:        .equ   7                                         ; MTIM1 Clock Gate Control
; bit position masks
mSCGC1_SCI1:        .equ   %00000001
mSCGC1_SCI2:        .equ   %00000010
mSCGC1_IIC1:        .equ   %00000100
mSCGC1_IIC2:        .equ   %00001000
mSCGC1_ADC:         .equ   %00010000
mSCGC1_TPM1:        .equ   %00100000
mSCGC1_TPM2:        .equ   %01000000
mSCGC1_MTIM1:       .equ   %10000000


;*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF8109 ***
SCGC2:              .equ   $FFFF8109                                ;*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF8109 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI1:         .equ   0                                         ; SPI1 Clock Gate Control
SCGC2_SPI2:         .equ   1                                         ; SPI2 Clock Gate Control
SCGC2_RTC:          .equ   2                                         ; RTC Clock Gate Control
SCGC2_KBI1:         .equ   3                                         ; KBI1 Clock Gate Control
SCGC2_KBI2:         .equ   4                                         ; KBI2 Clock Gate Control
SCGC2_IRQ:          .equ   5                                         ; IRQ Clock Gate Control
SCGC2_FTSR:         .equ   6                                         ; FTSR Clock Gate Control
SCGC2_SCI3:         .equ   7                                         ; SCI3 Clock Gate Control
; bit position masks
mSCGC2_SPI1:        .equ   %00000001
mSCGC2_SPI2:        .equ   %00000010
mSCGC2_RTC:         .equ   %00000100
mSCGC2_KBI1:        .equ   %00001000
mSCGC2_KBI2:        .equ   %00010000
mSCGC2_IRQ:         .equ   %00100000
mSCGC2_FTSR:        .equ   %01000000
mSCGC2_SCI3:        .equ   %10000000


;*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF810A ***
SCGC3:              .equ   $FFFF810A                                ;*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF810A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC3_PTA:          .equ   0                                         ; PTA Clock Gate Control
SCGC3_PTB:          .equ   1                                         ; PTB Clock Gate Control
SCGC3_PTC:          .equ   2                                         ; PTC Clock Gate Control
SCGC3_PTD:          .equ   3                                         ; PTD Clock Gate Control
SCGC3_PTE:          .equ   4                                         ; PTE Clock Gate Control
SCGC3_PTF:          .equ   5                                         ; PTF Clock Gate Control
SCGC3_PTG:          .equ   6                                         ; PTG Clock Gate Control
SCGC3_PTH:          .equ   7                                         ; PTH Clock Gate Control
; bit position masks
mSCGC3_PTA:         .equ   %00000001
mSCGC3_PTB:         .equ   %00000010
mSCGC3_PTC:         .equ   %00000100
mSCGC3_PTD:         .equ   %00001000
mSCGC3_PTE:         .equ   %00010000
mSCGC3_PTF:         .equ   %00100000
mSCGC3_PTG:         .equ   %01000000
mSCGC3_PTH:         .equ   %10000000


;*** SCGC4 - System Clock Gating Control 4 Register; 0xFFFF810B ***
SCGC4:              .equ   $FFFF810B                                ;*** SCGC4 - System Clock Gating Control 4 Register; 0xFFFF810B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC4_PTJ:          .equ   0                                         ; PTJ Clock Gate Control
SCGC4_FEC:          .equ   1                                         ; FEC Clock Gate Control
SCGC4_MB:           .equ   2                                         ; MiniBus Clock Gate Control
SCGC4_MC:           .equ   3                                         ; Port Mux Control
SCGC4_MTIM2:        .equ   4                                         ; MTIM2 Clock Gate Control
; bit position masks
mSCGC4_PTJ:         .equ   %00000001
mSCGC4_FEC:         .equ   %00000010
mSCGC4_MB:          .equ   %00000100
mSCGC4_MC:          .equ   %00001000
mSCGC4_MTIM2:       .equ   %00010000


;*** SIMIPS - SIM Internal Peripheral Select Register; 0xFFFF810C ***
SIMIPS:             .equ   $FFFF810C                                ;*** SIMIPS - SIM Internal Peripheral Select Register; 0xFFFF810C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMIPS_MTIM1:       .equ   0                                         ; MTIM1 External Clock Select
SIMIPS_MTIM2:       .equ   1                                         ; MTIM2 External Clock Selec
SIMIPS_TPM1:        .equ   2                                         ; TPM1 External Clock Select
SIMIPS_TPM2:        .equ   3                                         ; TPM2 External Clock Select
; bit position masks
mSIMIPS_MTIM1:      .equ   %00000001
mSIMIPS_MTIM2:      .equ   %00000010
mSIMIPS_TPM1:       .equ   %00000100
mSIMIPS_TPM2:       .equ   %00001000


;*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF8120 ***
SPMSC1:             .equ   $FFFF8120                                ;*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF8120 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE:        .equ   0                                         ; Bandgap Buffer Enable
SPMSC1_LVDE:        .equ   2                                         ; Low-Voltage Detect Enable
SPMSC1_LVDSE:       .equ   3                                         ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE:       .equ   4                                         ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE:       .equ   5                                         ; Low-Voltage Detect Interrupt Enable
SPMSC1_LVDACK:      .equ   6                                         ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF:        .equ   7                                         ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_BGBE:       .equ   %00000001
mSPMSC1_LVDE:       .equ   %00000100
mSPMSC1_LVDSE:      .equ   %00001000
mSPMSC1_LVDRE:      .equ   %00010000
mSPMSC1_LVDIE:      .equ   %00100000
mSPMSC1_LVDACK:     .equ   %01000000
mSPMSC1_LVDF:       .equ   %10000000


;*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF8121 ***
SPMSC2:             .equ   $FFFF8121                                ;*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF8121 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC:        .equ   0                                         ; Partial Power Down Control
SPMSC2_PPDE:        .equ   1                                         ; Partial Power-Down Enable
SPMSC2_PPDACK:      .equ   2                                         ; Partial Power Down Acknowledge
SPMSC2_PPDF:        .equ   3                                         ; Partial Power Down Flag
SPMSC2_LPWUI:       .equ   5                                         ; Low Power Wake Up on Interrupt
SPMSC2_LPRS:        .equ   6                                         ; Low Power Regulator Status
SPMSC2_LPR:         .equ   7                                         ; Low Power Regulator Control
; bit position masks
mSPMSC2_PPDC:       .equ   %00000001
mSPMSC2_PPDE:       .equ   %00000010
mSPMSC2_PPDACK:     .equ   %00000100
mSPMSC2_PPDF:       .equ   %00001000
mSPMSC2_LPWUI:      .equ   %00100000
mSPMSC2_LPRS:       .equ   %01000000
mSPMSC2_LPR:        .equ   %10000000


;*** SPMSC3 - System Power Management Status and Control 3 Register; 0xFFFF8123 ***
SPMSC3:             .equ   $FFFF8123                                ;*** SPMSC3 - System Power Management Status and Control 3 Register; 0xFFFF8123 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC3_LVWIE:       .equ   3                                         ; Low-Voltage Warning Interrupt Enable
SPMSC3_LVWV:        .equ   4                                         ; Low-Voltage Warning Voltage Select
SPMSC3_LVDV:        .equ   5                                         ; Low-Voltage Detect Voltage Select
SPMSC3_LVWACK:      .equ   6                                         ; Low-Voltage Warning Acknowledge
SPMSC3_LVWF:        .equ   7                                         ; Low-Voltage Warning Flag
; bit position masks
mSPMSC3_LVWIE:      .equ   %00001000
mSPMSC3_LVWV:       .equ   %00010000
mSPMSC3_LVDV:       .equ   %00100000
mSPMSC3_LVWACK:     .equ   %01000000
mSPMSC3_LVWF:       .equ   %10000000


;*** ADCSC1 - Status and Control Register 1; 0xFFFF8140 ***
ADCSC1:             .equ   $FFFF8140                                ;*** ADCSC1 - Status and Control Register 1; 0xFFFF8140 ***
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


;*** ADCSC2 - Status and Control Register 2; 0xFFFF8141 ***
ADCSC2:             .equ   $FFFF8141                                ;*** ADCSC2 - Status and Control Register 2; 0xFFFF8141 ***
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


;*** ADCR - Data Result Register; 0xFFFF8142 ***
ADCR:               .equ   $FFFF8142                                ;*** ADCR - Data Result Register; 0xFFFF8142 ***
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


;*** ADCRH - Data Result High Register; 0xFFFF8142 ***
ADCRH:              .equ   $FFFF8142                                ;*** ADCRH - Data Result High Register; 0xFFFF8142 ***
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


;*** ADCRL - Data Result Low Register; 0xFFFF8143 ***
ADCRL:              .equ   $FFFF8143                                ;*** ADCRL - Data Result Low Register; 0xFFFF8143 ***
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


;*** ADCCV - Compare Value Register; 0xFFFF8144 ***
ADCCV:              .equ   $FFFF8144                                ;*** ADCCV - Compare Value Register; 0xFFFF8144 ***
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


;*** ADCCVH - Compare Value High Register; 0xFFFF8144 ***
ADCCVH:             .equ   $FFFF8144                                ;*** ADCCVH - Compare Value High Register; 0xFFFF8144 ***
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


;*** ADCCVL - Compare Value Low Register; 0xFFFF8145 ***
ADCCVL:             .equ   $FFFF8145                                ;*** ADCCVL - Compare Value Low Register; 0xFFFF8145 ***
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


;*** ADCCFG - Configuration Register; 0xFFFF8146 ***
ADCCFG:             .equ   $FFFF8146                                ;*** ADCCFG - Configuration Register; 0xFFFF8146 ***
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


;*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF8160 ***
SCI1BD:             .equ   $FFFF8160                                ;*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF8160 ***
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


;*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF8160 ***
SCI1BDH:            .equ   $FFFF8160                                ;*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF8160 ***
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


;*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF8161 ***
SCI1BDL:            .equ   $FFFF8161                                ;*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF8161 ***
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


;*** SCI1C1 - SCI1 Control Register 1; 0xFFFF8162 ***
SCI1C1:             .equ   $FFFF8162                                ;*** SCI1C1 - SCI1 Control Register 1; 0xFFFF8162 ***
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


;*** SCI1C2 - SCI1 Control Register 2; 0xFFFF8163 ***
SCI1C2:             .equ   $FFFF8163                                ;*** SCI1C2 - SCI1 Control Register 2; 0xFFFF8163 ***
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


;*** SCI1S1 - SCI1 Status Register 1; 0xFFFF8164 ***
SCI1S1:             .equ   $FFFF8164                                ;*** SCI1S1 - SCI1 Status Register 1; 0xFFFF8164 ***
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


;*** SCI1S2 - SCI1 Status Register 2; 0xFFFF8165 ***
SCI1S2:             .equ   $FFFF8165                                ;*** SCI1S2 - SCI1 Status Register 2; 0xFFFF8165 ***
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


;*** SCI1C3 - SCI1 Control Register 3; 0xFFFF8166 ***
SCI1C3:             .equ   $FFFF8166                                ;*** SCI1C3 - SCI1 Control Register 3; 0xFFFF8166 ***
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


;*** SCI1D - SCI1 Data Register; 0xFFFF8167 ***
SCI1D:              .equ   $FFFF8167                                ;*** SCI1D - SCI1 Data Register; 0xFFFF8167 ***
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


;*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF8180 ***
SCI2BD:             .equ   $FFFF8180                                ;*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF8180 ***
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


;*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF8180 ***
SCI2BDH:            .equ   $FFFF8180                                ;*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF8180 ***
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


;*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF8181 ***
SCI2BDL:            .equ   $FFFF8181                                ;*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF8181 ***
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


;*** SCI2C1 - SCI2 Control Register 1; 0xFFFF8182 ***
SCI2C1:             .equ   $FFFF8182                                ;*** SCI2C1 - SCI2 Control Register 1; 0xFFFF8182 ***
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


;*** SCI2C2 - SCI2 Control Register 2; 0xFFFF8183 ***
SCI2C2:             .equ   $FFFF8183                                ;*** SCI2C2 - SCI2 Control Register 2; 0xFFFF8183 ***
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


;*** SCI2S1 - SCI2 Status Register 1; 0xFFFF8184 ***
SCI2S1:             .equ   $FFFF8184                                ;*** SCI2S1 - SCI2 Status Register 1; 0xFFFF8184 ***
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


;*** SCI2S2 - SCI2 Status Register 2; 0xFFFF8185 ***
SCI2S2:             .equ   $FFFF8185                                ;*** SCI2S2 - SCI2 Status Register 2; 0xFFFF8185 ***
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


;*** SCI2C3 - SCI2 Control Register 3; 0xFFFF8186 ***
SCI2C3:             .equ   $FFFF8186                                ;*** SCI2C3 - SCI2 Control Register 3; 0xFFFF8186 ***
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


;*** SCI2D - SCI2 Data Register; 0xFFFF8187 ***
SCI2D:              .equ   $FFFF8187                                ;*** SCI2D - SCI2 Data Register; 0xFFFF8187 ***
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


;*** SCI3BD - SCI3 Baud Rate Register; 0xFFFF81A0 ***
SCI3BD:             .equ   $FFFF81A0                                ;*** SCI3BD - SCI3 Baud Rate Register; 0xFFFF81A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3BD_SBR0:        .equ   0                                         ; Baud Rate Modulo Divisor Bit 0
SCI3BD_SBR1:        .equ   1                                         ; Baud Rate Modulo Divisor Bit 1
SCI3BD_SBR2:        .equ   2                                         ; Baud Rate Modulo Divisor Bit 2
SCI3BD_SBR3:        .equ   3                                         ; Baud Rate Modulo Divisor Bit 3
SCI3BD_SBR4:        .equ   4                                         ; Baud Rate Modulo Divisor Bit 4
SCI3BD_SBR5:        .equ   5                                         ; Baud Rate Modulo Divisor Bit 5
SCI3BD_SBR6:        .equ   6                                         ; Baud Rate Modulo Divisor Bit 6
SCI3BD_SBR7:        .equ   7                                         ; Baud Rate Modulo Divisor Bit 7
SCI3BD_SBR8:        .equ   8                                         ; Baud Rate Modulo Divisor Bit 8
SCI3BD_SBR9:        .equ   9                                         ; Baud Rate Modulo Divisor Bit 9
SCI3BD_SBR10:       .equ   10                                        ; Baud Rate Modulo Divisor Bit 10
SCI3BD_SBR11:       .equ   11                                        ; Baud Rate Modulo Divisor Bit 11
SCI3BD_SBR12:       .equ   12                                        ; Baud Rate Modulo Divisor Bit 12
SCI3BD_RXEDGIE:     .equ   14                                        ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI3BD_LBKDIE:      .equ   15                                        ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI3BD_SBR0:       .equ   %00000001
mSCI3BD_SBR1:       .equ   %00000010
mSCI3BD_SBR2:       .equ   %00000100
mSCI3BD_SBR3:       .equ   %00001000
mSCI3BD_SBR4:       .equ   %00010000
mSCI3BD_SBR5:       .equ   %00100000
mSCI3BD_SBR6:       .equ   %01000000
mSCI3BD_SBR7:       .equ   %10000000
mSCI3BD_SBR8:       .equ   %100000000
mSCI3BD_SBR9:       .equ   %1000000000
mSCI3BD_SBR10:      .equ   %10000000000
mSCI3BD_SBR11:      .equ   %100000000000
mSCI3BD_SBR12:      .equ   %1000000000000
mSCI3BD_RXEDGIE:    .equ   %100000000000000
mSCI3BD_LBKDIE:     .equ   %1000000000000000


;*** SCI3BDH - SCI3 Baud Rate Register High; 0xFFFF81A0 ***
SCI3BDH:            .equ   $FFFF81A0                                ;*** SCI3BDH - SCI3 Baud Rate Register High; 0xFFFF81A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3BDH_SBR8:       .equ   0                                         ; Baud Rate Modulo Divisor Bit 8
SCI3BDH_SBR9:       .equ   1                                         ; Baud Rate Modulo Divisor Bit 9
SCI3BDH_SBR10:      .equ   2                                         ; Baud Rate Modulo Divisor Bit 10
SCI3BDH_SBR11:      .equ   3                                         ; Baud Rate Modulo Divisor Bit 11
SCI3BDH_SBR12:      .equ   4                                         ; Baud Rate Modulo Divisor Bit 12
SCI3BDH_RXEDGIE:    .equ   6                                         ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI3BDH_LBKDIE:     .equ   7                                         ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI3BDH_SBR8:      .equ   %00000001
mSCI3BDH_SBR9:      .equ   %00000010
mSCI3BDH_SBR10:     .equ   %00000100
mSCI3BDH_SBR11:     .equ   %00001000
mSCI3BDH_SBR12:     .equ   %00010000
mSCI3BDH_RXEDGIE:   .equ   %01000000
mSCI3BDH_LBKDIE:    .equ   %10000000


;*** SCI3BDL - SCI3 Baud Rate Register Low; 0xFFFF81A1 ***
SCI3BDL:            .equ   $FFFF81A1                                ;*** SCI3BDL - SCI3 Baud Rate Register Low; 0xFFFF81A1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3BDL_SBR0:       .equ   0                                         ; Baud Rate Modulo Divisor Bit 0
SCI3BDL_SBR1:       .equ   1                                         ; Baud Rate Modulo Divisor Bit 1
SCI3BDL_SBR2:       .equ   2                                         ; Baud Rate Modulo Divisor Bit 2
SCI3BDL_SBR3:       .equ   3                                         ; Baud Rate Modulo Divisor Bit 3
SCI3BDL_SBR4:       .equ   4                                         ; Baud Rate Modulo Divisor Bit 4
SCI3BDL_SBR5:       .equ   5                                         ; Baud Rate Modulo Divisor Bit 5
SCI3BDL_SBR6:       .equ   6                                         ; Baud Rate Modulo Divisor Bit 6
SCI3BDL_SBR7:       .equ   7                                         ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI3BDL_SBR0:      .equ   %00000001
mSCI3BDL_SBR1:      .equ   %00000010
mSCI3BDL_SBR2:      .equ   %00000100
mSCI3BDL_SBR3:      .equ   %00001000
mSCI3BDL_SBR4:      .equ   %00010000
mSCI3BDL_SBR5:      .equ   %00100000
mSCI3BDL_SBR6:      .equ   %01000000
mSCI3BDL_SBR7:      .equ   %10000000


;*** SCI3C1 - SCI3 Control Register 1; 0xFFFF81A2 ***
SCI3C1:             .equ   $FFFF81A2                                ;*** SCI3C1 - SCI3 Control Register 1; 0xFFFF81A2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3C1_PT:          .equ   0                                         ; Parity Type
SCI3C1_PE:          .equ   1                                         ; Parity Enable
SCI3C1_ILT:         .equ   2                                         ; Idle Line Type Select
SCI3C1_WAKE:        .equ   3                                         ; Receiver Wakeup Method Select
SCI3C1_M:           .equ   4                                         ; 9-Bit or 8-Bit Mode Select
SCI3C1_RSRC:        .equ   5                                         ; Receiver Source Select
SCI3C1_SCISWAI:     .equ   6                                         ; SCI Stops in Wait Mode
SCI3C1_LOOPS:       .equ   7                                         ; Loop Mode Select
; bit position masks
mSCI3C1_PT:         .equ   %00000001
mSCI3C1_PE:         .equ   %00000010
mSCI3C1_ILT:        .equ   %00000100
mSCI3C1_WAKE:       .equ   %00001000
mSCI3C1_M:          .equ   %00010000
mSCI3C1_RSRC:       .equ   %00100000
mSCI3C1_SCISWAI:    .equ   %01000000
mSCI3C1_LOOPS:      .equ   %10000000


;*** SCI3C2 - SCI3 Control Register 2; 0xFFFF81A3 ***
SCI3C2:             .equ   $FFFF81A3                                ;*** SCI3C2 - SCI3 Control Register 2; 0xFFFF81A3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3C2_SBK:         .equ   0                                         ; Send Break
SCI3C2_RWU:         .equ   1                                         ; Receiver Wakeup Control
SCI3C2_RE:          .equ   2                                         ; Receiver Enable
SCI3C2_TE:          .equ   3                                         ; Transmitter Enable
SCI3C2_ILIE:        .equ   4                                         ; Idle Line Interrupt Enable (for IDLE)
SCI3C2_RIE:         .equ   5                                         ; Receiver Interrupt Enable (for RDRF)
SCI3C2_TCIE:        .equ   6                                         ; Transmission Complete Interrupt Enable (for TC)
SCI3C2_TIE:         .equ   7                                         ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI3C2_SBK:        .equ   %00000001
mSCI3C2_RWU:        .equ   %00000010
mSCI3C2_RE:         .equ   %00000100
mSCI3C2_TE:         .equ   %00001000
mSCI3C2_ILIE:       .equ   %00010000
mSCI3C2_RIE:        .equ   %00100000
mSCI3C2_TCIE:       .equ   %01000000
mSCI3C2_TIE:        .equ   %10000000


;*** SCI3S1 - SCI3 Status Register 1; 0xFFFF81A4 ***
SCI3S1:             .equ   $FFFF81A4                                ;*** SCI3S1 - SCI3 Status Register 1; 0xFFFF81A4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3S1_PF:          .equ   0                                         ; Parity Error Flag
SCI3S1_FE:          .equ   1                                         ; Framing Error Flag
SCI3S1_NF:          .equ   2                                         ; Noise Flag
SCI3S1_OR:          .equ   3                                         ; Receiver Overrun Flag
SCI3S1_IDLE:        .equ   4                                         ; Idle Line Flag
SCI3S1_RDRF:        .equ   5                                         ; Receive Data Register Full Flag
SCI3S1_TC:          .equ   6                                         ; Transmission Complete Flag
SCI3S1_TDRE:        .equ   7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI3S1_PF:         .equ   %00000001
mSCI3S1_FE:         .equ   %00000010
mSCI3S1_NF:         .equ   %00000100
mSCI3S1_OR:         .equ   %00001000
mSCI3S1_IDLE:       .equ   %00010000
mSCI3S1_RDRF:       .equ   %00100000
mSCI3S1_TC:         .equ   %01000000
mSCI3S1_TDRE:       .equ   %10000000


;*** SCI3S2 - SCI3 Status Register 2; 0xFFFF81A5 ***
SCI3S2:             .equ   $FFFF81A5                                ;*** SCI3S2 - SCI3 Status Register 2; 0xFFFF81A5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3S2_RAF:         .equ   0                                         ; Receiver Active Flag
SCI3S2_LBKDE:       .equ   1                                         ; LIN Break Detection Enable
SCI3S2_BRK13:       .equ   2                                         ; Break Character Generation Length
SCI3S2_RWUID:       .equ   3                                         ; Receive Wake Up Idle Detect
SCI3S2_RXINV:       .equ   4                                         ; Receive Data Inversion
SCI3S2_RXEDGIF:     .equ   6                                         ; RxD Pin Active Edge Interrupt Flag
SCI3S2_LBKDIF:      .equ   7                                         ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI3S2_RAF:        .equ   %00000001
mSCI3S2_LBKDE:      .equ   %00000010
mSCI3S2_BRK13:      .equ   %00000100
mSCI3S2_RWUID:      .equ   %00001000
mSCI3S2_RXINV:      .equ   %00010000
mSCI3S2_RXEDGIF:    .equ   %01000000
mSCI3S2_LBKDIF:     .equ   %10000000


;*** SCI3C3 - SCI3 Control Register 3; 0xFFFF81A6 ***
SCI3C3:             .equ   $FFFF81A6                                ;*** SCI3C3 - SCI3 Control Register 3; 0xFFFF81A6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3C3_PEIE:        .equ   0                                         ; Parity Error Interrupt Enable
SCI3C3_FEIE:        .equ   1                                         ; Framing Error Interrupt Enable
SCI3C3_NEIE:        .equ   2                                         ; Noise Error Interrupt Enable
SCI3C3_ORIE:        .equ   3                                         ; Overrun Interrupt Enable
SCI3C3_TXINV:       .equ   4                                         ; Transmit Data Inversion
SCI3C3_TXDIR:       .equ   5                                         ; TxD Pin Direction in Single-Wire Mode
SCI3C3_T8:          .equ   6                                         ; Ninth Data Bit for Transmitter
SCI3C3_R8:          .equ   7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI3C3_PEIE:       .equ   %00000001
mSCI3C3_FEIE:       .equ   %00000010
mSCI3C3_NEIE:       .equ   %00000100
mSCI3C3_ORIE:       .equ   %00001000
mSCI3C3_TXINV:      .equ   %00010000
mSCI3C3_TXDIR:      .equ   %00100000
mSCI3C3_T8:         .equ   %01000000
mSCI3C3_R8:         .equ   %10000000


;*** SCI3D - SCI3 Data Register; 0xFFFF81A7 ***
SCI3D:              .equ   $FFFF81A7                                ;*** SCI3D - SCI3 Data Register; 0xFFFF81A7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3D_R0_T0:        .equ   0                                         ; Receive/Transmit Data Bit 0
SCI3D_R1_T1:        .equ   1                                         ; Receive/Transmit Data Bit 1
SCI3D_R2_T2:        .equ   2                                         ; Receive/Transmit Data Bit 2
SCI3D_R3_T3:        .equ   3                                         ; Receive/Transmit Data Bit 3
SCI3D_R4_T4:        .equ   4                                         ; Receive/Transmit Data Bit 4
SCI3D_R5_T5:        .equ   5                                         ; Receive/Transmit Data Bit 5
SCI3D_R6_T6:        .equ   6                                         ; Receive/Transmit Data Bit 6
SCI3D_R7_T7:        .equ   7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI3D_R0_T0:       .equ   %00000001
mSCI3D_R1_T1:       .equ   %00000010
mSCI3D_R2_T2:       .equ   %00000100
mSCI3D_R3_T3:       .equ   %00001000
mSCI3D_R4_T4:       .equ   %00010000
mSCI3D_R5_T5:       .equ   %00100000
mSCI3D_R6_T6:       .equ   %01000000
mSCI3D_R7_T7:       .equ   %10000000


;*** SPI1C1 - SPI1 Control Register 1; 0xFFFF81C0 ***
SPI1C1:             .equ   $FFFF81C0                                ;*** SPI1C1 - SPI1 Control Register 1; 0xFFFF81C0 ***
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


;*** SPI1C2 - SPI1 Control Register 2; 0xFFFF81C1 ***
SPI1C2:             .equ   $FFFF81C1                                ;*** SPI1C2 - SPI1 Control Register 2; 0xFFFF81C1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0:        .equ   0                                         ; SPI Pin Control 0
SPI1C2_SPISWAI:     .equ   1                                         ; SPI Stop in Wait Mode
SPI1C2_BIDIROE:     .equ   3                                         ; Bidirectional Mode Output Enable
SPI1C2_MODFEN:      .equ   4                                         ; Master Mode-Fault Function Enable
; bit position masks
mSPI1C2_SPC0:       .equ   %00000001
mSPI1C2_SPISWAI:    .equ   %00000010
mSPI1C2_BIDIROE:    .equ   %00001000
mSPI1C2_MODFEN:     .equ   %00010000


;*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF81C2 ***
SPI1BR:             .equ   $FFFF81C2                                ;*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF81C2 ***
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


;*** SPI1S - SPI1 Status Register; 0xFFFF81C3 ***
SPI1S:              .equ   $FFFF81C3                                ;*** SPI1S - SPI1 Status Register; 0xFFFF81C3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF:         .equ   4                                         ; Master Mode Fault Flag
SPI1S_SPTEF:        .equ   5                                         ; SPI Transmit Buffer Empty Flag
SPI1S_SPRF:         .equ   7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPI1S_MODF:        .equ   %00010000
mSPI1S_SPTEF:       .equ   %00100000
mSPI1S_SPRF:        .equ   %10000000


;*** SPI1D - SPI1 Data Register; 0xFFFF81C5 ***
SPI1D:              .equ   $FFFF81C5                                ;*** SPI1D - SPI1 Data Register; 0xFFFF81C5 ***


;*** SPI2C1 - SPI2 Control Register 1; 0xFFFF81E0 ***
SPI2C1:             .equ   $FFFF81E0                                ;*** SPI2C1 - SPI2 Control Register 1; 0xFFFF81E0 ***
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


;*** SPI2C2 - SPI2 Control Register 2; 0xFFFF81E1 ***
SPI2C2:             .equ   $FFFF81E1                                ;*** SPI2C2 - SPI2 Control Register 2; 0xFFFF81E1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C2_SPC0:        .equ   0                                         ; SPI Pin Control 0
SPI2C2_SPISWAI:     .equ   1                                         ; SPI Stop in Wait Mode
SPI2C2_BIDIROE:     .equ   3                                         ; Bidirectional Mode Output Enable
SPI2C2_MODFEN:      .equ   4                                         ; Master Mode-Fault Function Enable
; bit position masks
mSPI2C2_SPC0:       .equ   %00000001
mSPI2C2_SPISWAI:    .equ   %00000010
mSPI2C2_BIDIROE:    .equ   %00001000
mSPI2C2_MODFEN:     .equ   %00010000


;*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF81E2 ***
SPI2BR:             .equ   $FFFF81E2                                ;*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF81E2 ***
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


;*** SPI2S - SPI2 Status Register; 0xFFFF81E3 ***
SPI2S:              .equ   $FFFF81E3                                ;*** SPI2S - SPI2 Status Register; 0xFFFF81E3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2S_MODF:         .equ   4                                         ; Master Mode Fault Flag
SPI2S_SPTEF:        .equ   5                                         ; SPI Transmit Buffer Empty Flag
SPI2S_SPRF:         .equ   7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPI2S_MODF:        .equ   %00010000
mSPI2S_SPTEF:       .equ   %00100000
mSPI2S_SPRF:        .equ   %10000000


;*** SPI2D - SPI2 Data Register; 0xFFFF81E5 ***
SPI2D:              .equ   $FFFF81E5                                ;*** SPI2D - SPI2 Data Register; 0xFFFF81E5 ***


;*** IIC1A1 - IIC Address Register; 0xFFFF8200 ***
IIC1A1:             .equ   $FFFF8200                                ;*** IIC1A1 - IIC Address Register; 0xFFFF8200 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1A1_AD1:         .equ   1                                         ; Slave Address Bit 1
IIC1A1_AD2:         .equ   2                                         ; Slave Address Bit 2
IIC1A1_AD3:         .equ   3                                         ; Slave Address Bit 3
IIC1A1_AD4:         .equ   4                                         ; Slave Address Bit 4
IIC1A1_AD5:         .equ   5                                         ; Slave Address Bit 5
IIC1A1_AD6:         .equ   6                                         ; Slave Address Bit 6
IIC1A1_AD7:         .equ   7                                         ; Slave Address Bit 7
; bit position masks
mIIC1A1_AD1:        .equ   %00000010
mIIC1A1_AD2:        .equ   %00000100
mIIC1A1_AD3:        .equ   %00001000
mIIC1A1_AD4:        .equ   %00010000
mIIC1A1_AD5:        .equ   %00100000
mIIC1A1_AD6:        .equ   %01000000
mIIC1A1_AD7:        .equ   %10000000


;*** IIC1A - IIC Address Register; 0xFFFF8200 ***
IIC1A:              .equ   $FFFF8200                                ;*** IIC1A - IIC Address Register; 0xFFFF8200 ***
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


;*** IIC1F - IIC Frequency Divider Register; 0xFFFF8201 ***
IIC1F:              .equ   $FFFF8201                                ;*** IIC1F - IIC Frequency Divider Register; 0xFFFF8201 ***
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


;*** IIC1C1 - IIC Control Register 1; 0xFFFF8202 ***
IIC1C1:             .equ   $FFFF8202                                ;*** IIC1C1 - IIC Control Register 1; 0xFFFF8202 ***
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


;*** IIC1C - IIC Control Register; 0xFFFF8202 ***
IIC1C:              .equ   $FFFF8202                                ;*** IIC1C - IIC Control Register; 0xFFFF8202 ***
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


;*** IIC1S - IIC Status Register; 0xFFFF8203 ***
IIC1S:              .equ   $FFFF8203                                ;*** IIC1S - IIC Status Register; 0xFFFF8203 ***
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


;*** IIC1D - IIC Data I/O Register; 0xFFFF8204 ***
IIC1D:              .equ   $FFFF8204                                ;*** IIC1D - IIC Data I/O Register; 0xFFFF8204 ***
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


;*** IIC1C2 - IIC Control Register 2; 0xFFFF8205 ***
IIC1C2:             .equ   $FFFF8205                                ;*** IIC1C2 - IIC Control Register 2; 0xFFFF8205 ***
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


;*** IIC1SMB - SMBus Control and Status Register; 0xFFFF8206 ***
IIC1SMB:            .equ   $FFFF8206                                ;*** IIC1SMB - SMBus Control and Status Register; 0xFFFF8206 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1SMB_SHTF:       .equ   2                                         ; SCL High Timeout Flag
IIC1SMB_SLTF:       .equ   3                                         ; SCL Low Timeout Flag
IIC1SMB_TCKSEL:     .equ   4                                         ; Time Out Counter Clock Select
IIC1SMB_SIICAEN:    .equ   5                                         ; Second IIC Address Enable
IIC1SMB_ALERTEN:    .equ   6                                         ; SMBus Alert Response Address Enable
IIC1SMB_FACK:       .equ   7                                         ; Fast NACK/ACK enable
; bit position masks
mIIC1SMB_SHTF:      .equ   %00000100
mIIC1SMB_SLTF:      .equ   %00001000
mIIC1SMB_TCKSEL:    .equ   %00010000
mIIC1SMB_SIICAEN:   .equ   %00100000
mIIC1SMB_ALERTEN:   .equ   %01000000
mIIC1SMB_FACK:      .equ   %10000000


;*** IIC1A2 - IIC Address Register 2; 0xFFFF8207 ***
IIC1A2:             .equ   $FFFF8207                                ;*** IIC1A2 - IIC Address Register 2; 0xFFFF8207 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1A2_SAD1:        .equ   1                                         ; SMBus Address Bit 1
IIC1A2_SAD2:        .equ   2                                         ; SMBus Address Bit 2
IIC1A2_SAD3:        .equ   3                                         ; SMBus Address Bit 3
IIC1A2_SAD4:        .equ   4                                         ; SMBus Address Bit 4
IIC1A2_SAD5:        .equ   5                                         ; SMBus Address Bit 5
IIC1A2_SAD6:        .equ   6                                         ; SMBus Address Bit 6
IIC1A2_SAD7:        .equ   7                                         ; SMBus Address Bit 7
; bit position masks
mIIC1A2_SAD1:       .equ   %00000010
mIIC1A2_SAD2:       .equ   %00000100
mIIC1A2_SAD3:       .equ   %00001000
mIIC1A2_SAD4:       .equ   %00010000
mIIC1A2_SAD5:       .equ   %00100000
mIIC1A2_SAD6:       .equ   %01000000
mIIC1A2_SAD7:       .equ   %10000000


;*** IIC1SLT - IIC SCL Low Time Out register; 0xFFFF8208 ***
IIC1SLT:            .equ   $FFFF8208                                ;*** IIC1SLT - IIC SCL Low Time Out register; 0xFFFF8208 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1SLT_SSLT0:      .equ   0                                         ; SCL Low Time Out Bits, bit 0
IIC1SLT_SSLT1:      .equ   1                                         ; SCL Low Time Out Bits, bit 1
IIC1SLT_SSLT2:      .equ   2                                         ; SCL Low Time Out Bits, bit 2
IIC1SLT_SSLT3:      .equ   3                                         ; SCL Low Time Out Bits, bit 3
IIC1SLT_SSLT4:      .equ   4                                         ; SCL Low Time Out Bits, bit 4
IIC1SLT_SSLT5:      .equ   5                                         ; SCL Low Time Out Bits, bit 5
IIC1SLT_SSLT6:      .equ   6                                         ; SCL Low Time Out Bits, bit 6
IIC1SLT_SSLT7:      .equ   7                                         ; SCL Low Time Out Bits, bit 7
IIC1SLT_SSLT8:      .equ   8                                         ; SCL Low Time Out Bits, bit 8
IIC1SLT_SSLT9:      .equ   9                                         ; SCL Low Time Out Bits, bit 9
IIC1SLT_SSLT10:     .equ   10                                        ; SCL Low Time Out Bits, bit 10
IIC1SLT_SSLT11:     .equ   11                                        ; SCL Low Time Out Bits, bit 11
IIC1SLT_SSLT12:     .equ   12                                        ; SCL Low Time Out Bits, bit 12
IIC1SLT_SSLT13:     .equ   13                                        ; SCL Low Time Out Bits, bit 13
IIC1SLT_SSLT14:     .equ   14                                        ; SCL Low Time Out Bits, bit 14
IIC1SLT_SSLT15:     .equ   15                                        ; SCL Low Time Out Bits, bit 15
; bit position masks
mIIC1SLT_SSLT0:     .equ   %00000001
mIIC1SLT_SSLT1:     .equ   %00000010
mIIC1SLT_SSLT2:     .equ   %00000100
mIIC1SLT_SSLT3:     .equ   %00001000
mIIC1SLT_SSLT4:     .equ   %00010000
mIIC1SLT_SSLT5:     .equ   %00100000
mIIC1SLT_SSLT6:     .equ   %01000000
mIIC1SLT_SSLT7:     .equ   %10000000
mIIC1SLT_SSLT8:     .equ   %100000000
mIIC1SLT_SSLT9:     .equ   %1000000000
mIIC1SLT_SSLT10:    .equ   %10000000000
mIIC1SLT_SSLT11:    .equ   %100000000000
mIIC1SLT_SSLT12:    .equ   %1000000000000
mIIC1SLT_SSLT13:    .equ   %10000000000000
mIIC1SLT_SSLT14:    .equ   %100000000000000
mIIC1SLT_SSLT15:    .equ   %1000000000000000


;*** IIC1SLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8208 ***
IIC1SLTH:           .equ   $FFFF8208                                ;*** IIC1SLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8208 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1SLTH_SSLT8:     .equ   0                                         ; SCL Low Time Out Bit 8
IIC1SLTH_SSLT9:     .equ   1                                         ; SCL Low Time Out Bit 9
IIC1SLTH_SSLT10:    .equ   2                                         ; SCL Low Time Out Bit 10
IIC1SLTH_SSLT11:    .equ   3                                         ; SCL Low Time Out Bit 11
IIC1SLTH_SSLT12:    .equ   4                                         ; SCL Low Time Out Bit 12
IIC1SLTH_SSLT13:    .equ   5                                         ; SCL Low Time Out Bit 13
IIC1SLTH_SSLT14:    .equ   6                                         ; SCL Low Time Out Bit 14
IIC1SLTH_SSLT15:    .equ   7                                         ; SCL Low Time Out Bit 15
; bit position masks
mIIC1SLTH_SSLT8:    .equ   %00000001
mIIC1SLTH_SSLT9:    .equ   %00000010
mIIC1SLTH_SSLT10:   .equ   %00000100
mIIC1SLTH_SSLT11:   .equ   %00001000
mIIC1SLTH_SSLT12:   .equ   %00010000
mIIC1SLTH_SSLT13:   .equ   %00100000
mIIC1SLTH_SSLT14:   .equ   %01000000
mIIC1SLTH_SSLT15:   .equ   %10000000


;*** IIC1SLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8209 ***
IIC1SLTL:           .equ   $FFFF8209                                ;*** IIC1SLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8209 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1SLTL_SSLT0:     .equ   0                                         ; SCL Low Time Out Bits, bit 0
IIC1SLTL_SSLT1:     .equ   1                                         ; SCL Low Time Out Bits, bit 1
IIC1SLTL_SSLT2:     .equ   2                                         ; SCL Low Time Out Bits, bit 2
IIC1SLTL_SSLT3:     .equ   3                                         ; SCL Low Time Out Bits, bit 3
IIC1SLTL_SSLT4:     .equ   4                                         ; SCL Low Time Out Bits, bit 4
IIC1SLTL_SSLT5:     .equ   5                                         ; SCL Low Time Out Bits, bit 5
IIC1SLTL_SSLT6:     .equ   6                                         ; SCL Low Time Out Bits, bit 6
IIC1SLTL_SSLT7:     .equ   7                                         ; SCL Low Time Out Bits, bit 7
; bit position masks
mIIC1SLTL_SSLT0:    .equ   %00000001
mIIC1SLTL_SSLT1:    .equ   %00000010
mIIC1SLTL_SSLT2:    .equ   %00000100
mIIC1SLTL_SSLT3:    .equ   %00001000
mIIC1SLTL_SSLT4:    .equ   %00010000
mIIC1SLTL_SSLT5:    .equ   %00100000
mIIC1SLTL_SSLT6:    .equ   %01000000
mIIC1SLTL_SSLT7:    .equ   %10000000


;*** IIC1FLT - IIC Filter register; 0xFFFF820A ***
IIC1FLT:            .equ   $FFFF820A                                ;*** IIC1FLT - IIC Filter register; 0xFFFF820A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1FLT_FLT0:       .equ   0                                         ; Filter value bit 0
IIC1FLT_FLT1:       .equ   1                                         ; Filter value bit 1
IIC1FLT_FLT2:       .equ   2                                         ; Filter value bit 2
; bit position masks
mIIC1FLT_FLT0:      .equ   %00000001
mIIC1FLT_FLT1:      .equ   %00000010
mIIC1FLT_FLT2:      .equ   %00000100


;*** IIC2A1 - IIC Address Register; 0xFFFF8220 ***
IIC2A1:             .equ   $FFFF8220                                ;*** IIC2A1 - IIC Address Register; 0xFFFF8220 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2A1_AD1:         .equ   1                                         ; Slave Address Bit 1
IIC2A1_AD2:         .equ   2                                         ; Slave Address Bit 2
IIC2A1_AD3:         .equ   3                                         ; Slave Address Bit 3
IIC2A1_AD4:         .equ   4                                         ; Slave Address Bit 4
IIC2A1_AD5:         .equ   5                                         ; Slave Address Bit 5
IIC2A1_AD6:         .equ   6                                         ; Slave Address Bit 6
IIC2A1_AD7:         .equ   7                                         ; Slave Address Bit 7
; bit position masks
mIIC2A1_AD1:        .equ   %00000010
mIIC2A1_AD2:        .equ   %00000100
mIIC2A1_AD3:        .equ   %00001000
mIIC2A1_AD4:        .equ   %00010000
mIIC2A1_AD5:        .equ   %00100000
mIIC2A1_AD6:        .equ   %01000000
mIIC2A1_AD7:        .equ   %10000000


;*** IIC2A - IIC Address Register; 0xFFFF8220 ***
IIC2A:              .equ   $FFFF8220                                ;*** IIC2A - IIC Address Register; 0xFFFF8220 ***
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


;*** IIC2F - IIC Frequency Divider Register; 0xFFFF8221 ***
IIC2F:              .equ   $FFFF8221                                ;*** IIC2F - IIC Frequency Divider Register; 0xFFFF8221 ***
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


;*** IIC2C1 - IIC Control Register 1; 0xFFFF8222 ***
IIC2C1:             .equ   $FFFF8222                                ;*** IIC2C1 - IIC Control Register 1; 0xFFFF8222 ***
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


;*** IIC2C - IIC Control Register; 0xFFFF8222 ***
IIC2C:              .equ   $FFFF8222                                ;*** IIC2C - IIC Control Register; 0xFFFF8222 ***
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


;*** IIC2S - IIC Status Register; 0xFFFF8223 ***
IIC2S:              .equ   $FFFF8223                                ;*** IIC2S - IIC Status Register; 0xFFFF8223 ***
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


;*** IIC2D - IIC Data I/O Register; 0xFFFF8224 ***
IIC2D:              .equ   $FFFF8224                                ;*** IIC2D - IIC Data I/O Register; 0xFFFF8224 ***
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


;*** IIC2C2 - IIC Control Register 2; 0xFFFF8225 ***
IIC2C2:             .equ   $FFFF8225                                ;*** IIC2C2 - IIC Control Register 2; 0xFFFF8225 ***
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


;*** IIC2SMB - SMBus Control and Status Register; 0xFFFF8226 ***
IIC2SMB:            .equ   $FFFF8226                                ;*** IIC2SMB - SMBus Control and Status Register; 0xFFFF8226 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2SMB_SHTF:       .equ   2                                         ; SCL High Timeout Flag
IIC2SMB_SLTF:       .equ   3                                         ; SCL Low Timeout Flag
IIC2SMB_TCKSEL:     .equ   4                                         ; Time Out Counter Clock Select
IIC2SMB_SIICAEN:    .equ   5                                         ; Second IIC Address Enable
IIC2SMB_ALERTEN:    .equ   6                                         ; SMBus Alert Response Address Enable
IIC2SMB_FACK:       .equ   7                                         ; Fast NACK/ACK enable
; bit position masks
mIIC2SMB_SHTF:      .equ   %00000100
mIIC2SMB_SLTF:      .equ   %00001000
mIIC2SMB_TCKSEL:    .equ   %00010000
mIIC2SMB_SIICAEN:   .equ   %00100000
mIIC2SMB_ALERTEN:   .equ   %01000000
mIIC2SMB_FACK:      .equ   %10000000


;*** IIC2A2 - IIC Address Register 2; 0xFFFF8227 ***
IIC2A2:             .equ   $FFFF8227                                ;*** IIC2A2 - IIC Address Register 2; 0xFFFF8227 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2A2_SAD1:        .equ   1                                         ; SMBus Address Bit 1
IIC2A2_SAD2:        .equ   2                                         ; SMBus Address Bit 2
IIC2A2_SAD3:        .equ   3                                         ; SMBus Address Bit 3
IIC2A2_SAD4:        .equ   4                                         ; SMBus Address Bit 4
IIC2A2_SAD5:        .equ   5                                         ; SMBus Address Bit 5
IIC2A2_SAD6:        .equ   6                                         ; SMBus Address Bit 6
IIC2A2_SAD7:        .equ   7                                         ; SMBus Address Bit 7
; bit position masks
mIIC2A2_SAD1:       .equ   %00000010
mIIC2A2_SAD2:       .equ   %00000100
mIIC2A2_SAD3:       .equ   %00001000
mIIC2A2_SAD4:       .equ   %00010000
mIIC2A2_SAD5:       .equ   %00100000
mIIC2A2_SAD6:       .equ   %01000000
mIIC2A2_SAD7:       .equ   %10000000


;*** IIC2SLT - IIC SCL Low Time Out register; 0xFFFF8228 ***
IIC2SLT:            .equ   $FFFF8228                                ;*** IIC2SLT - IIC SCL Low Time Out register; 0xFFFF8228 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2SLT_SSLT0:      .equ   0                                         ; SCL Low Time Out Bits, bit 0
IIC2SLT_SSLT1:      .equ   1                                         ; SCL Low Time Out Bits, bit 1
IIC2SLT_SSLT2:      .equ   2                                         ; SCL Low Time Out Bits, bit 2
IIC2SLT_SSLT3:      .equ   3                                         ; SCL Low Time Out Bits, bit 3
IIC2SLT_SSLT4:      .equ   4                                         ; SCL Low Time Out Bits, bit 4
IIC2SLT_SSLT5:      .equ   5                                         ; SCL Low Time Out Bits, bit 5
IIC2SLT_SSLT6:      .equ   6                                         ; SCL Low Time Out Bits, bit 6
IIC2SLT_SSLT7:      .equ   7                                         ; SCL Low Time Out Bits, bit 7
IIC2SLT_SSLT8:      .equ   8                                         ; SCL Low Time Out Bits, bit 8
IIC2SLT_SSLT9:      .equ   9                                         ; SCL Low Time Out Bits, bit 9
IIC2SLT_SSLT10:     .equ   10                                        ; SCL Low Time Out Bits, bit 10
IIC2SLT_SSLT11:     .equ   11                                        ; SCL Low Time Out Bits, bit 11
IIC2SLT_SSLT12:     .equ   12                                        ; SCL Low Time Out Bits, bit 12
IIC2SLT_SSLT13:     .equ   13                                        ; SCL Low Time Out Bits, bit 13
IIC2SLT_SSLT14:     .equ   14                                        ; SCL Low Time Out Bits, bit 14
IIC2SLT_SSLT15:     .equ   15                                        ; SCL Low Time Out Bits, bit 15
; bit position masks
mIIC2SLT_SSLT0:     .equ   %00000001
mIIC2SLT_SSLT1:     .equ   %00000010
mIIC2SLT_SSLT2:     .equ   %00000100
mIIC2SLT_SSLT3:     .equ   %00001000
mIIC2SLT_SSLT4:     .equ   %00010000
mIIC2SLT_SSLT5:     .equ   %00100000
mIIC2SLT_SSLT6:     .equ   %01000000
mIIC2SLT_SSLT7:     .equ   %10000000
mIIC2SLT_SSLT8:     .equ   %100000000
mIIC2SLT_SSLT9:     .equ   %1000000000
mIIC2SLT_SSLT10:    .equ   %10000000000
mIIC2SLT_SSLT11:    .equ   %100000000000
mIIC2SLT_SSLT12:    .equ   %1000000000000
mIIC2SLT_SSLT13:    .equ   %10000000000000
mIIC2SLT_SSLT14:    .equ   %100000000000000
mIIC2SLT_SSLT15:    .equ   %1000000000000000


;*** IIC2SLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8228 ***
IIC2SLTH:           .equ   $FFFF8228                                ;*** IIC2SLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8228 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2SLTH_SSLT8:     .equ   0                                         ; SCL Low Time Out Bit 8
IIC2SLTH_SSLT9:     .equ   1                                         ; SCL Low Time Out Bit 9
IIC2SLTH_SSLT10:    .equ   2                                         ; SCL Low Time Out Bit 10
IIC2SLTH_SSLT11:    .equ   3                                         ; SCL Low Time Out Bit 11
IIC2SLTH_SSLT12:    .equ   4                                         ; SCL Low Time Out Bit 12
IIC2SLTH_SSLT13:    .equ   5                                         ; SCL Low Time Out Bit 13
IIC2SLTH_SSLT14:    .equ   6                                         ; SCL Low Time Out Bit 14
IIC2SLTH_SSLT15:    .equ   7                                         ; SCL Low Time Out Bit 15
; bit position masks
mIIC2SLTH_SSLT8:    .equ   %00000001
mIIC2SLTH_SSLT9:    .equ   %00000010
mIIC2SLTH_SSLT10:   .equ   %00000100
mIIC2SLTH_SSLT11:   .equ   %00001000
mIIC2SLTH_SSLT12:   .equ   %00010000
mIIC2SLTH_SSLT13:   .equ   %00100000
mIIC2SLTH_SSLT14:   .equ   %01000000
mIIC2SLTH_SSLT15:   .equ   %10000000


;*** IIC2SLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8229 ***
IIC2SLTL:           .equ   $FFFF8229                                ;*** IIC2SLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8229 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2SLTL_SSLT0:     .equ   0                                         ; SCL Low Time Out Bits, bit 0
IIC2SLTL_SSLT1:     .equ   1                                         ; SCL Low Time Out Bits, bit 1
IIC2SLTL_SSLT2:     .equ   2                                         ; SCL Low Time Out Bits, bit 2
IIC2SLTL_SSLT3:     .equ   3                                         ; SCL Low Time Out Bits, bit 3
IIC2SLTL_SSLT4:     .equ   4                                         ; SCL Low Time Out Bits, bit 4
IIC2SLTL_SSLT5:     .equ   5                                         ; SCL Low Time Out Bits, bit 5
IIC2SLTL_SSLT6:     .equ   6                                         ; SCL Low Time Out Bits, bit 6
IIC2SLTL_SSLT7:     .equ   7                                         ; SCL Low Time Out Bits, bit 7
; bit position masks
mIIC2SLTL_SSLT0:    .equ   %00000001
mIIC2SLTL_SSLT1:    .equ   %00000010
mIIC2SLTL_SSLT2:    .equ   %00000100
mIIC2SLTL_SSLT3:    .equ   %00001000
mIIC2SLTL_SSLT4:    .equ   %00010000
mIIC2SLTL_SSLT5:    .equ   %00100000
mIIC2SLTL_SSLT6:    .equ   %01000000
mIIC2SLTL_SSLT7:    .equ   %10000000


;*** IIC2FLT - IIC Filter register; 0xFFFF822A ***
IIC2FLT:            .equ   $FFFF822A                                ;*** IIC2FLT - IIC Filter register; 0xFFFF822A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC2FLT_FLT0:       .equ   0                                         ; Filter value bit 0
IIC2FLT_FLT1:       .equ   1                                         ; Filter value bit 1
IIC2FLT_FLT2:       .equ   2                                         ; Filter value bit 2
; bit position masks
mIIC2FLT_FLT0:      .equ   %00000001
mIIC2FLT_FLT1:      .equ   %00000010
mIIC2FLT_FLT2:      .equ   %00000100


;*** MCGC1 - MCG Control Register 1; 0xFFFF8240 ***
MCGC1:              .equ   $FFFF8240                                ;*** MCGC1 - MCG Control Register 1; 0xFFFF8240 ***
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


;*** MCGC2 - MCG Control Register 2; 0xFFFF8241 ***
MCGC2:              .equ   $FFFF8241                                ;*** MCGC2 - MCG Control Register 2; 0xFFFF8241 ***
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


;*** MCGTRM - MCG Trim Register; 0xFFFF8242 ***
MCGTRM:             .equ   $FFFF8242                                ;*** MCGTRM - MCG Trim Register; 0xFFFF8242 ***
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


;*** MCGSC - MCG Status and Control Register; 0xFFFF8243 ***
MCGSC:              .equ   $FFFF8243                                ;*** MCGSC - MCG Status and Control Register; 0xFFFF8243 ***
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


;*** MCGC3 - MCG Control Register 3; 0xFFFF8244 ***
MCGC3:              .equ   $FFFF8244                                ;*** MCGC3 - MCG Control Register 3; 0xFFFF8244 ***
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


;*** MCGC4 - MCG Control Register 4; 0xFFFF8245 ***
MCGC4:              .equ   $FFFF8245                                ;*** MCGC4 - MCG Control Register 4; 0xFFFF8245 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC4_DRST_DRS0:    .equ   0                                         ; DCO Range Status / DCO Range Select, bit 0
MCGC4_DRST_DRS1:    .equ   1                                         ; DCO Range Status / DCO Range Select, bit 1
MCGC4_DMX32:        .equ   5                                         ; DCO Maximum frequency with 32.768 kHz reference
; bit position masks
mMCGC4_DRST_DRS0:   .equ   %00000001
mMCGC4_DRST_DRS1:   .equ   %00000010
mMCGC4_DMX32:       .equ   %00100000


;*** TPM1SC - TPM1 Status and Control Register; 0xFFFF8260 ***
TPM1SC:             .equ   $FFFF8260                                ;*** TPM1SC - TPM1 Status and Control Register; 0xFFFF8260 ***
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


;*** TPM1CNT - TPM1 Timer Counter Register; 0xFFFF8261 ***
TPM1CNT:            .equ   $FFFF8261                                ;*** TPM1CNT - TPM1 Timer Counter Register; 0xFFFF8261 ***


;*** TPM1CNTH - TPM1 Timer Counter Register High; 0xFFFF8261 ***
TPM1CNTH:           .equ   $FFFF8261                                ;*** TPM1CNTH - TPM1 Timer Counter Register High; 0xFFFF8261 ***


;*** TPM1CNTL - TPM1 Timer Counter Register Low; 0xFFFF8262 ***
TPM1CNTL:           .equ   $FFFF8262                                ;*** TPM1CNTL - TPM1 Timer Counter Register Low; 0xFFFF8262 ***


;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0xFFFF8263 ***
TPM1MOD:            .equ   $FFFF8263                                ;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0xFFFF8263 ***


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0xFFFF8263 ***
TPM1MODH:           .equ   $FFFF8263                                ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0xFFFF8263 ***


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0xFFFF8264 ***
TPM1MODL:           .equ   $FFFF8264                                ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0xFFFF8264 ***


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0xFFFF8265 ***
TPM1C0SC:           .equ   $FFFF8265                                ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0xFFFF8265 ***
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


;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0xFFFF8266 ***
TPM1C0V:            .equ   $FFFF8266                                ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0xFFFF8266 ***


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0xFFFF8266 ***
TPM1C0VH:           .equ   $FFFF8266                                ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0xFFFF8266 ***


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0xFFFF8267 ***
TPM1C0VL:           .equ   $FFFF8267                                ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0xFFFF8267 ***


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0xFFFF8268 ***
TPM1C1SC:           .equ   $FFFF8268                                ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0xFFFF8268 ***
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


;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0xFFFF8269 ***
TPM1C1V:            .equ   $FFFF8269                                ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0xFFFF8269 ***


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0xFFFF8269 ***
TPM1C1VH:           .equ   $FFFF8269                                ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0xFFFF8269 ***


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0xFFFF826A ***
TPM1C1VL:           .equ   $FFFF826A                                ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0xFFFF826A ***


;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register; 0xFFFF826B ***
TPM1C2SC:           .equ   $FFFF826B                                ;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register; 0xFFFF826B ***
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


;*** TPM1C2V - TPM1 Timer Channel 2 Value Register; 0xFFFF826C ***
TPM1C2V:            .equ   $FFFF826C                                ;*** TPM1C2V - TPM1 Timer Channel 2 Value Register; 0xFFFF826C ***


;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High; 0xFFFF826C ***
TPM1C2VH:           .equ   $FFFF826C                                ;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High; 0xFFFF826C ***


;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low; 0xFFFF826D ***
TPM1C2VL:           .equ   $FFFF826D                                ;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low; 0xFFFF826D ***


;*** TPM2SC - TPM2 Status and Control Register; 0xFFFF8280 ***
TPM2SC:             .equ   $FFFF8280                                ;*** TPM2SC - TPM2 Status and Control Register; 0xFFFF8280 ***
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


;*** TPM2CNT - TPM2 Timer Counter Register; 0xFFFF8281 ***
TPM2CNT:            .equ   $FFFF8281                                ;*** TPM2CNT - TPM2 Timer Counter Register; 0xFFFF8281 ***


;*** TPM2CNTH - TPM2 Timer Counter Register High; 0xFFFF8281 ***
TPM2CNTH:           .equ   $FFFF8281                                ;*** TPM2CNTH - TPM2 Timer Counter Register High; 0xFFFF8281 ***


;*** TPM2CNTL - TPM2 Timer Counter Register Low; 0xFFFF8282 ***
TPM2CNTL:           .equ   $FFFF8282                                ;*** TPM2CNTL - TPM2 Timer Counter Register Low; 0xFFFF8282 ***


;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0xFFFF8283 ***
TPM2MOD:            .equ   $FFFF8283                                ;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0xFFFF8283 ***


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0xFFFF8283 ***
TPM2MODH:           .equ   $FFFF8283                                ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0xFFFF8283 ***


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0xFFFF8284 ***
TPM2MODL:           .equ   $FFFF8284                                ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0xFFFF8284 ***


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0xFFFF8285 ***
TPM2C0SC:           .equ   $FFFF8285                                ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0xFFFF8285 ***
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


;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0xFFFF8286 ***
TPM2C0V:            .equ   $FFFF8286                                ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0xFFFF8286 ***


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0xFFFF8286 ***
TPM2C0VH:           .equ   $FFFF8286                                ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0xFFFF8286 ***


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0xFFFF8287 ***
TPM2C0VL:           .equ   $FFFF8287                                ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0xFFFF8287 ***


;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0xFFFF8288 ***
TPM2C1SC:           .equ   $FFFF8288                                ;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0xFFFF8288 ***
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


;*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0xFFFF8289 ***
TPM2C1V:            .equ   $FFFF8289                                ;*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0xFFFF8289 ***


;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0xFFFF8289 ***
TPM2C1VH:           .equ   $FFFF8289                                ;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0xFFFF8289 ***


;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0xFFFF828A ***
TPM2C1VL:           .equ   $FFFF828A                                ;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0xFFFF828A ***


;*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register; 0xFFFF828B ***
TPM2C2SC:           .equ   $FFFF828B                                ;*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register; 0xFFFF828B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C2SC_ELS2A:     .equ   2                                         ; Edge/Level Select Bit A
TPM2C2SC_ELS2B:     .equ   3                                         ; Edge/Level Select Bit B
TPM2C2SC_MS2A:      .equ   4                                         ; Mode Select A for TPM Channel 2
TPM2C2SC_MS2B:      .equ   5                                         ; Mode Select B for TPM Channel 2
TPM2C2SC_CH2IE:     .equ   6                                         ; Channel 2 Interrupt Enable
TPM2C2SC_CH2F:      .equ   7                                         ; Channel 2 Flag
; bit position masks
mTPM2C2SC_ELS2A:    .equ   %00000100
mTPM2C2SC_ELS2B:    .equ   %00001000
mTPM2C2SC_MS2A:     .equ   %00010000
mTPM2C2SC_MS2B:     .equ   %00100000
mTPM2C2SC_CH2IE:    .equ   %01000000
mTPM2C2SC_CH2F:     .equ   %10000000


;*** TPM2C2V - TPM2 Timer Channel 2 Value Register; 0xFFFF828C ***
TPM2C2V:            .equ   $FFFF828C                                ;*** TPM2C2V - TPM2 Timer Channel 2 Value Register; 0xFFFF828C ***


;*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High; 0xFFFF828C ***
TPM2C2VH:           .equ   $FFFF828C                                ;*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High; 0xFFFF828C ***


;*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low; 0xFFFF828D ***
TPM2C2VL:           .equ   $FFFF828D                                ;*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low; 0xFFFF828D ***


;*** MTIM1SC - MTIM Clock Configuration Register; 0xFFFF82A0 ***
MTIM1SC:            .equ   $FFFF82A0                                ;*** MTIM1SC - MTIM Clock Configuration Register; 0xFFFF82A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM1SC_TSTP:       .equ   4                                         ; MTIM Counter Stop
MTIM1SC_TRST:       .equ   5                                         ; MTIM Counter Reset
MTIM1SC_TOIE:       .equ   6                                         ; MTIM Overflow Interrupt Enable
MTIM1SC_TOF:        .equ   7                                         ; MTIM Overflow Flag
; bit position masks
mMTIM1SC_TSTP:      .equ   %00010000
mMTIM1SC_TRST:      .equ   %00100000
mMTIM1SC_TOIE:      .equ   %01000000
mMTIM1SC_TOF:       .equ   %10000000


;*** MTIM1CLK - MTIM Clock Configuration Register; 0xFFFF82A1 ***
MTIM1CLK:           .equ   $FFFF82A1                                ;*** MTIM1CLK - MTIM Clock Configuration Register; 0xFFFF82A1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM1CLK_PS0:       .equ   0                                         ; Clock source Prescaler Bit 0
MTIM1CLK_PS1:       .equ   1                                         ; Clock source Prescaler Bit 1
MTIM1CLK_PS2:       .equ   2                                         ; Clock source Prescaler Bit 2
MTIM1CLK_PS3:       .equ   3                                         ; Clock source Prescaler Bit 3
MTIM1CLK_CLKS0:     .equ   4                                         ; Clock source Select Bit 0
MTIM1CLK_CLKS1:     .equ   5                                         ; Clock source Select Bit 1
; bit position masks
mMTIM1CLK_PS0:      .equ   %00000001
mMTIM1CLK_PS1:      .equ   %00000010
mMTIM1CLK_PS2:      .equ   %00000100
mMTIM1CLK_PS3:      .equ   %00001000
mMTIM1CLK_CLKS0:    .equ   %00010000
mMTIM1CLK_CLKS1:    .equ   %00100000


;*** MTIM1CNT - MTIM Counter Register; 0xFFFF82A2 ***
MTIM1CNT:           .equ   $FFFF82A2                                ;*** MTIM1CNT - MTIM Counter Register; 0xFFFF82A2 ***


;*** MTIM1MOD - MTIM Modulo Register; 0xFFFF82A3 ***
MTIM1MOD:           .equ   $FFFF82A3                                ;*** MTIM1MOD - MTIM Modulo Register; 0xFFFF82A3 ***


;*** RTCSC - RTC Status and Control Register; 0xFFFF82C0 ***
RTCSC:              .equ   $FFFF82C0                                ;*** RTCSC - RTC Status and Control Register; 0xFFFF82C0 ***
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


;*** RTCCNT - RTC Counter Register; 0xFFFF82C1 ***
RTCCNT:             .equ   $FFFF82C1                                ;*** RTCCNT - RTC Counter Register; 0xFFFF82C1 ***


;*** RTCMOD - RTC Modulo Register; 0xFFFF82C2 ***
RTCMOD:             .equ   $FFFF82C2                                ;*** RTCMOD - RTC Modulo Register; 0xFFFF82C2 ***


;*** FCDIV - FLASH Clock Divider Register; 0xFFFF82E0 ***
FCDIV:              .equ   $FFFF82E0                                ;*** FCDIV - FLASH Clock Divider Register; 0xFFFF82E0 ***
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


;*** FOPT - Flash Options Register; 0xFFFF82E1 ***
FOPT:               .equ   $FFFF82E1                                ;*** FOPT - Flash Options Register; 0xFFFF82E1 ***
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


;*** FCNFG - Flash Configuration Register; 0xFFFF82E3 ***
FCNFG:              .equ   $FFFF82E3                                ;*** FCNFG - Flash Configuration Register; 0xFFFF82E3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC:       .equ   5                                         ; Enable Security Key Writing
; bit position masks
mFCNFG_KEYACC:      .equ   %00100000


;*** FPROT - Flash Protection Register; 0xFFFF82E4 ***
FPROT:              .equ   $FFFF82E4                                ;*** FPROT - Flash Protection Register; 0xFFFF82E4 ***
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


;*** FSTAT - Flash Status Register; 0xFFFF82E5 ***
FSTAT:              .equ   $FFFF82E5                                ;*** FSTAT - Flash Status Register; 0xFFFF82E5 ***
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


;*** FCMD - Flash Command Register; 0xFFFF82E6 ***
FCMD:               .equ   $FFFF82E6                                ;*** FCMD - Flash Command Register; 0xFFFF82E6 ***
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


;*** MTIM2SC - MTIM Clock Configuration Register; 0xFFFF8300 ***
MTIM2SC:            .equ   $FFFF8300                                ;*** MTIM2SC - MTIM Clock Configuration Register; 0xFFFF8300 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM2SC_TSTP:       .equ   4                                         ; MTIM Counter Stop
MTIM2SC_TRST:       .equ   5                                         ; MTIM Counter Reset
MTIM2SC_TOIE:       .equ   6                                         ; MTIM Overflow Interrupt Enable
MTIM2SC_TOF:        .equ   7                                         ; MTIM Overflow Flag
; bit position masks
mMTIM2SC_TSTP:      .equ   %00010000
mMTIM2SC_TRST:      .equ   %00100000
mMTIM2SC_TOIE:      .equ   %01000000
mMTIM2SC_TOF:       .equ   %10000000


;*** MTIM2CLK - MTIM Clock Configuration Register; 0xFFFF8301 ***
MTIM2CLK:           .equ   $FFFF8301                                ;*** MTIM2CLK - MTIM Clock Configuration Register; 0xFFFF8301 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM2CLK_PS0:       .equ   0                                         ; Clock source Prescaler Bit 0
MTIM2CLK_PS1:       .equ   1                                         ; Clock source Prescaler Bit 1
MTIM2CLK_PS2:       .equ   2                                         ; Clock source Prescaler Bit 2
MTIM2CLK_PS3:       .equ   3                                         ; Clock source Prescaler Bit 3
MTIM2CLK_CLKS0:     .equ   4                                         ; Clock source Select Bit 0
MTIM2CLK_CLKS1:     .equ   5                                         ; Clock source Select Bit 1
; bit position masks
mMTIM2CLK_PS0:      .equ   %00000001
mMTIM2CLK_PS1:      .equ   %00000010
mMTIM2CLK_PS2:      .equ   %00000100
mMTIM2CLK_PS3:      .equ   %00001000
mMTIM2CLK_CLKS0:    .equ   %00010000
mMTIM2CLK_CLKS1:    .equ   %00100000


;*** MTIM2CNT - MTIM Counter Register; 0xFFFF8302 ***
MTIM2CNT:           .equ   $FFFF8302                                ;*** MTIM2CNT - MTIM Counter Register; 0xFFFF8302 ***


;*** MTIM2MOD - MTIM Modulo Register; 0xFFFF8303 ***
MTIM2MOD:           .equ   $FFFF8303                                ;*** MTIM2MOD - MTIM Modulo Register; 0xFFFF8303 ***


;*** EIR - Ethernet Interrupt Event Register; 0xFFFFE004 ***
EIR:                .equ   $FFFFE004                                ;*** EIR - Ethernet Interrupt Event Register; 0xFFFFE004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EIR_UN:             .equ   19                                        ; Transmit FIFO underrun. This bit indicates that the transmit FIFO became empty before the complete frame was transmitted. A bad CRC is appended to the frame fragment and the remainder of the frame is discarded
EIR_RL:             .equ   20                                        ; Collision retry limit. This bit indicates that a collision occurred on each of 16 successive attempts to transmit the frame. The frame is discarded without being transmitted and transmission of the next frame will commence. Can only occur in half duplex...
EIR_LC:             .equ   21                                        ; Late collison. This bit indicates that a collision occurred beyond the collision window (slot time) in half duplex mode. The frame is truncated with a bad CRC and the remainder of the frame is discarded
EIR_EBERR:          .equ   22                                        ; Ethernet bus error. This bit indicates that a system bus error occurred when a DMA transaction was underway. When the EBERR bit is set, ECR[ETHER_EN] will be cleared, halting frame processing by the FEC. When this occurs software will need to insure tha...
EIR_MII:            .equ   23                                        ; MII interrupt. This bit indicates that the MII has completed the data transfer requested
EIR_RXB:            .equ   24                                        ; Receive buffer interrupt. This bit indicates that a receive buffer descriptor has been updated that was not the last in the frame
EIR_RXF:            .equ   25                                        ; Receive frame interrupt. This bit indicates that a frame has been received and that the last corresponding buffer descriptor has been updated
EIR_TXB:            .equ   26                                        ; Transmit buffer interrupt. This bit indicates that a transmit buffer descriptor has been updated
EIR_TXF:            .equ   27                                        ; Transmit frame interrupt. This bit indicates that a frame has been transmitted and that the last corresponding buffer descriptor has been updated
EIR_GRA:            .equ   28                                        ; Graceful stop complete. This interrupt will be asserted for one of three reasons. Graceful stop means that the transmitter is put into a pause state after completion of the frame currently being transmitted. <br/>1) A graceful stop, which was initiated ...
EIR_BABT:           .equ   29                                        ; Babbling transmit error. This bit indicates that the transmitted frame length has exceeded RCR[MAX_FL] bytes. This condition is usually caused by a frame that is too long being placed into the transmit data buffer(s). Truncation does not occur
EIR_BABR:           .equ   30                                        ; Babbling receive error. This bit indicates a frame was received with length in excess of RCR[MAX_FL] bytes
EIR_HBERR:          .equ   31                                        ; Heartbeat error. This interrupt indicates that HBC is set in the TCR register and that the COL input was not asserted within the Heartbeat window following a transmission
; bit position masks
mEIR_UN:            .equ   %10000000000000000000
mEIR_RL:            .equ   %100000000000000000000
mEIR_LC:            .equ   %1000000000000000000000
mEIR_EBERR:         .equ   %10000000000000000000000
mEIR_MII:           .equ   %100000000000000000000000
mEIR_RXB:           .equ   %1000000000000000000000000
mEIR_RXF:           .equ   %10000000000000000000000000
mEIR_TXB:           .equ   %100000000000000000000000000
mEIR_TXF:           .equ   %1000000000000000000000000000
mEIR_GRA:           .equ   %10000000000000000000000000000
mEIR_BABT:          .equ   %100000000000000000000000000000
mEIR_BABR:          .equ   %1000000000000000000000000000000
mEIR_HBERR:         .equ   %10000000000000000000000000000000


;*** EIMR - Interrupt Mask Register; 0xFFFFE008 ***
EIMR:               .equ   $FFFFE008                                ;*** EIMR - Interrupt Mask Register; 0xFFFFE008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EIMR_UN:            .equ   19                                        ; Transmit FIFO underrun interrupt mask
EIMR_RL:            .equ   20                                        ; Collision retry limit interrupt mask
EIMR_LC:            .equ   21                                        ; Late collison interrupt mask
EIMR_EBERR:         .equ   22                                        ; Ethernet bus error interrupt mask
EIMR_MII:           .equ   23                                        ; MII interrupt interrupt mask
EIMR_RXB:           .equ   24                                        ; Receive buffer interrupt mask
EIMR_RXF:           .equ   25                                        ; Receive frame interrupt mask
EIMR_TXB:           .equ   26                                        ; Transmit buffer interrupt mask
EIMR_TXF:           .equ   27                                        ; Transmit frame interrupt mask
EIMR_GRA:           .equ   28                                        ; Graceful stop complete interrupt mask
EIMR_BABT:          .equ   29                                        ; Babbling transmit error interrupt mask
EIMR_BABR:          .equ   30                                        ; Babbling receive error interrupt mask
EIMR_HBERR:         .equ   31                                        ; Heartbeat error interrupt mask
; bit position masks
mEIMR_UN:           .equ   %10000000000000000000
mEIMR_RL:           .equ   %100000000000000000000
mEIMR_LC:           .equ   %1000000000000000000000
mEIMR_EBERR:        .equ   %10000000000000000000000
mEIMR_MII:          .equ   %100000000000000000000000
mEIMR_RXB:          .equ   %1000000000000000000000000
mEIMR_RXF:          .equ   %10000000000000000000000000
mEIMR_TXB:          .equ   %100000000000000000000000000
mEIMR_TXF:          .equ   %1000000000000000000000000000
mEIMR_GRA:          .equ   %10000000000000000000000000000
mEIMR_BABT:         .equ   %100000000000000000000000000000
mEIMR_BABR:         .equ   %1000000000000000000000000000000
mEIMR_HBERR:        .equ   %10000000000000000000000000000000


;*** RDAR - Receive Descriptor Active Register; 0xFFFFE010 ***
RDAR:               .equ   $FFFFE010                                ;*** RDAR - Receive Descriptor Active Register; 0xFFFFE010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDAR_RDAR:          .equ   24                                        ; Set to one when this register is written, regardless of the value written. Cleared by the FEC device whenever no additional &quot;empty&quot; descriptors remain in the receive ring. Also cleared when ECR[ETHER_EN] is cleared
; bit position masks
mRDAR_RDAR:         .equ   %1000000000000000000000000


;*** TDAR - Transmit Descriptor Active Register; 0xFFFFE014 ***
TDAR:               .equ   $FFFFE014                                ;*** TDAR - Transmit Descriptor Active Register; 0xFFFFE014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TDAR_TDAR:          .equ   24                                        ; Set to one when this register is written, regardless of the value written. Cleared by the FEC device whenever no additional ready descriptors remain in the transmit ring. Also cleared when ECR[ETHER_EN] is cleared
; bit position masks
mTDAR_TDAR:         .equ   %1000000000000000000000000


;*** ECR -  Ethernet Control Register; 0xFFFFE024 ***
ECR:                .equ   $FFFFE024                                ;*** ECR -  Ethernet Control Register; 0xFFFFE024 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ECR_RESET:          .equ   0                                         ; When this bit is set, the equivalent of a hardware reset is performed but it is local to the FEC. ETHER_EN is cleared and all other FEC registers take their reset values. Also, any transmission/reception currently in progress is abruptly aborted. This b...
ECR_ETHER_EN:       .equ   1                                         ; When this bit is set, the FEC is enabled, and reception and transmission are possible. When this bit is cleared, reception is immediately stopped and transmission is stopped after a bad CRC is appended to any currently transmitted frame. The buffer desc...
; bit position masks
mECR_RESET:         .equ   %00000001
mECR_ETHER_EN:      .equ   %00000010


;*** MMFR - MII Management Frame Register; 0xFFFFE040 ***
MMFR:               .equ   $FFFFE040                                ;*** MMFR - MII Management Frame Register; 0xFFFFE040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMFR_DATA0:         .equ   0                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 0
MMFR_DATA1:         .equ   1                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 1
MMFR_DATA2:         .equ   2                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 2
MMFR_DATA3:         .equ   3                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 3
MMFR_DATA4:         .equ   4                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 4
MMFR_DATA5:         .equ   5                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 5
MMFR_DATA6:         .equ   6                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 6
MMFR_DATA7:         .equ   7                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 7
MMFR_DATA8:         .equ   8                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 8
MMFR_DATA9:         .equ   9                                         ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 9
MMFR_DATA10:        .equ   10                                        ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 10
MMFR_DATA11:        .equ   11                                        ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 11
MMFR_DATA12:        .equ   12                                        ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 12
MMFR_DATA13:        .equ   13                                        ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 13
MMFR_DATA14:        .equ   14                                        ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 14
MMFR_DATA15:        .equ   15                                        ; Management frame data. This is the field for data to be written to or read from the PHY register, bit 15
MMFR_TA0:           .equ   16                                        ; Turn around. This field must be programmed to 0b10 to generate a valid MII management frame, bit 0
MMFR_TA1:           .equ   17                                        ; Turn around. This field must be programmed to 0b10 to generate a valid MII management frame, bit 1
MMFR_RA0:           .equ   18                                        ; Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 0
MMFR_RA1:           .equ   19                                        ; Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 1
MMFR_RA2:           .equ   20                                        ; Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 2
MMFR_RA3:           .equ   21                                        ; Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 3
MMFR_RA4:           .equ   22                                        ; Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 4
MMFR_PA0:           .equ   23                                        ; PHY address. This field specifies one of up to 32 attached PHY devices, bit 0
MMFR_PA1:           .equ   24                                        ; PHY address. This field specifies one of up to 32 attached PHY devices, bit 1
MMFR_PA2:           .equ   25                                        ; PHY address. This field specifies one of up to 32 attached PHY devices, bit 2
MMFR_PA3:           .equ   26                                        ; PHY address. This field specifies one of up to 32 attached PHY devices, bit 3
MMFR_PA4:           .equ   27                                        ; PHY address. This field specifies one of up to 32 attached PHY devices, bit 4
MMFR_OP0:           .equ   28                                        ; Operation code. This field must be programmed to 0b10 (read) or 0b01 (write) to generate a valid MII management frame. A value of 0b11 will produce &quot;read&quot; frame operation while a value of 0b00 will produce &quot;write&quot; frame operation, bu...
MMFR_OP1:           .equ   29                                        ; Operation code. This field must be programmed to 0b10 (read) or 0b01 (write) to generate a valid MII management frame. A value of 0b11 will produce &quot;read&quot; frame operation while a value of 0b00 will produce &quot;write&quot; frame operation, bu...
MMFR_ST0:           .equ   30                                        ; Start of frame delimiter. These bits must be programmed to 0b01 for a valid MII management frame, bit 0
MMFR_ST1:           .equ   31                                        ; Start of frame delimiter. These bits must be programmed to 0b01 for a valid MII management frame, bit 1
; bit position masks
mMMFR_DATA0:        .equ   %00000001
mMMFR_DATA1:        .equ   %00000010
mMMFR_DATA2:        .equ   %00000100
mMMFR_DATA3:        .equ   %00001000
mMMFR_DATA4:        .equ   %00010000
mMMFR_DATA5:        .equ   %00100000
mMMFR_DATA6:        .equ   %01000000
mMMFR_DATA7:        .equ   %10000000
mMMFR_DATA8:        .equ   %100000000
mMMFR_DATA9:        .equ   %1000000000
mMMFR_DATA10:       .equ   %10000000000
mMMFR_DATA11:       .equ   %100000000000
mMMFR_DATA12:       .equ   %1000000000000
mMMFR_DATA13:       .equ   %10000000000000
mMMFR_DATA14:       .equ   %100000000000000
mMMFR_DATA15:       .equ   %1000000000000000
mMMFR_TA0:          .equ   %10000000000000000
mMMFR_TA1:          .equ   %100000000000000000
mMMFR_RA0:          .equ   %1000000000000000000
mMMFR_RA1:          .equ   %10000000000000000000
mMMFR_RA2:          .equ   %100000000000000000000
mMMFR_RA3:          .equ   %1000000000000000000000
mMMFR_RA4:          .equ   %10000000000000000000000
mMMFR_PA0:          .equ   %100000000000000000000000
mMMFR_PA1:          .equ   %1000000000000000000000000
mMMFR_PA2:          .equ   %10000000000000000000000000
mMMFR_PA3:          .equ   %100000000000000000000000000
mMMFR_PA4:          .equ   %1000000000000000000000000000
mMMFR_OP0:          .equ   %10000000000000000000000000000
mMMFR_OP1:          .equ   %100000000000000000000000000000
mMMFR_ST0:          .equ   %1000000000000000000000000000000
mMMFR_ST1:          .equ   %10000000000000000000000000000000


;*** MSCR - MII Speed Control Register; 0xFFFFE044 ***
MSCR:               .equ   $FFFFE044                                ;*** MSCR - MII Speed Control Register; 0xFFFFE044 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MSCR_MII_SPEED0:    .equ   1                                         ; MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency...
MSCR_MII_SPEED1:    .equ   2                                         ; MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency...
MSCR_MII_SPEED2:    .equ   3                                         ; MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency...
MSCR_MII_SPEED3:    .equ   4                                         ; MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency...
MSCR_MII_SPEED4:    .equ   5                                         ; MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency...
MSCR_MII_SPEED5:    .equ   6                                         ; MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency...
MSCR_DIS_PRE:       .equ   7                                         ; Asserting this bit will cause preamble (32 1's) not to be prepended to the MII management frame. The MII standard allows the preamble to be dropped if the attached PHY device(s) does not require it
; bit position masks
mMSCR_MII_SPEED0:   .equ   %00000010
mMSCR_MII_SPEED1:   .equ   %00000100
mMSCR_MII_SPEED2:   .equ   %00001000
mMSCR_MII_SPEED3:   .equ   %00010000
mMSCR_MII_SPEED4:   .equ   %00100000
mMSCR_MII_SPEED5:   .equ   %01000000
mMSCR_DIS_PRE:      .equ   %10000000


;*** RCR - Receive Control Register; 0xFFFFE084 ***
RCR:                .equ   $FFFFE084                                ;*** RCR - Receive Control Register; 0xFFFFE084 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RCR_LOOP:           .equ   0                                         ; Internal loopback. If set, transmitted frames are looped back internal to the device and the transmit output signals are not asserted. The system clock is substituted for the ETXCLK when LOOP is asserted. DRT must be set to zero when asserting LOOP
RCR_DRT:            .equ   1                                         ; Disable receive on transmit
RCR_MII_MODE:       .equ   2                                         ; Media independent interface mode. Selects the external interface mode for both transmit and receive blocks
RCR_PROM:           .equ   3                                         ; Promiscuous mode. All frames are accepted regardless of address matching
RCR_BC_REJ:         .equ   4                                         ; Broadcast frame reject. If asserted, frames with DA (destination address) = FF_FF_FF_FF_FF_FF will be rejected unless the PROM bit is set. If both BC_REJ and PROM = 1, then frames with broadcast DA will be accepted and the M (MISS) bit will be set in th...
RCR_FCE:            .equ   5                                         ; Flow control enable. If asserted, the receiver will detect PAUSE frames. Upon PAUSE frame detection, the transmitter will stop transmitting data frames for a given duration
RCR_MAX_FL0:        .equ   16                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL1:        .equ   17                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL2:        .equ   18                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL3:        .equ   19                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL4:        .equ   20                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL5:        .equ   21                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL6:        .equ   22                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL7:        .equ   23                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL8:        .equ   24                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL9:        .equ   25                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
RCR_MAX_FL10:       .equ   26                                        ; Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BAB...
; bit position masks
mRCR_LOOP:          .equ   %00000001
mRCR_DRT:           .equ   %00000010
mRCR_MII_MODE:      .equ   %00000100
mRCR_PROM:          .equ   %00001000
mRCR_BC_REJ:        .equ   %00010000
mRCR_FCE:           .equ   %00100000
mRCR_MAX_FL0:       .equ   %10000000000000000
mRCR_MAX_FL1:       .equ   %100000000000000000
mRCR_MAX_FL2:       .equ   %1000000000000000000
mRCR_MAX_FL3:       .equ   %10000000000000000000
mRCR_MAX_FL4:       .equ   %100000000000000000000
mRCR_MAX_FL5:       .equ   %1000000000000000000000
mRCR_MAX_FL6:       .equ   %10000000000000000000000
mRCR_MAX_FL7:       .equ   %100000000000000000000000
mRCR_MAX_FL8:       .equ   %1000000000000000000000000
mRCR_MAX_FL9:       .equ   %10000000000000000000000000
mRCR_MAX_FL10:      .equ   %100000000000000000000000000


;*** TCR - Transmit Control Register; 0xFFFFE0C4 ***
TCR:                .equ   $FFFFE0C4                                ;*** TCR - Transmit Control Register; 0xFFFFE0C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TCR_GTS:            .equ   0                                         ; Graceful transmit stop. When this bit is set, the MAC will stop transmission after any frame that is currently being transmitted is complete and the GRA interrupt in the EIR register will be asserted. If frame transmission is not currently underway, the...
TCR_HBC:            .equ   1                                         ; Heartbeat control. If set, the heartbeat check is performed following end of transmission and the HB bit in the status register will be set if the collision input does not assert within the heartbeat window. This bit should only be modified when ETHER_E...
TCR_FDEN:           .equ   2                                         ; Full duplex enable. If set, frames are transmitted independent of carrier sense and collision inputs. This bit should only be modified when ETHER_EN is deasserted
TCR_TFC_PAUSE:      .equ   3                                         ; Transmit frame control pause. Transmits a PAUSE frame when asserted. When this bit is set, the MAC will stop transmission of data frames after the current transmission is complete. At this time, the GRA interrupt in the EIR register will be asserted. Wi...
TCR_RFC_PAUSE:      .equ   4                                         ; Receive frame control pause. This read-only status bit will be asserted when a full duplex flow control pause frame has been received and the transmitter is paused for the duration defined in this pause frame. This bit will automatically clear when the ...
; bit position masks
mTCR_GTS:           .equ   %00000001
mTCR_HBC:           .equ   %00000010
mTCR_FDEN:          .equ   %00000100
mTCR_TFC_PAUSE:     .equ   %00001000
mTCR_RFC_PAUSE:     .equ   %00010000


;*** PALR - Physical Address Low Register; 0xFFFFE0E4 ***
PALR:               .equ   $FFFFE0E4                                ;*** PALR - Physical Address Low Register; 0xFFFFE0E4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PALR_PADDR10:       .equ   0                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 0
PALR_PADDR11:       .equ   1                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 1
PALR_PADDR12:       .equ   2                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 2
PALR_PADDR13:       .equ   3                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 3
PALR_PADDR14:       .equ   4                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 4
PALR_PADDR15:       .equ   5                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 5
PALR_PADDR16:       .equ   6                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 6
PALR_PADDR17:       .equ   7                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 7
PALR_PADDR18:       .equ   8                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 8
PALR_PADDR19:       .equ   9                                         ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 9
PALR_PADDR110:      .equ   10                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 10
PALR_PADDR111:      .equ   11                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 11
PALR_PADDR112:      .equ   12                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 12
PALR_PADDR113:      .equ   13                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 13
PALR_PADDR114:      .equ   14                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 14
PALR_PADDR115:      .equ   15                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 15
PALR_PADDR116:      .equ   16                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 16
PALR_PADDR117:      .equ   17                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 17
PALR_PADDR118:      .equ   18                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 18
PALR_PADDR119:      .equ   19                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 19
PALR_PADDR120:      .equ   20                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 20
PALR_PADDR121:      .equ   21                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 21
PALR_PADDR122:      .equ   22                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 22
PALR_PADDR123:      .equ   23                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 23
PALR_PADDR124:      .equ   24                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 24
PALR_PADDR125:      .equ   25                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 25
PALR_PADDR126:      .equ   26                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 26
PALR_PADDR127:      .equ   27                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 27
PALR_PADDR128:      .equ   28                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 28
PALR_PADDR129:      .equ   29                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 29
PALR_PADDR130:      .equ   30                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 30
PALR_PADDR131:      .equ   31                                        ; Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 31
; bit position masks
mPALR_PADDR10:      .equ   %00000001
mPALR_PADDR11:      .equ   %00000010
mPALR_PADDR12:      .equ   %00000100
mPALR_PADDR13:      .equ   %00001000
mPALR_PADDR14:      .equ   %00010000
mPALR_PADDR15:      .equ   %00100000
mPALR_PADDR16:      .equ   %01000000
mPALR_PADDR17:      .equ   %10000000
mPALR_PADDR18:      .equ   %100000000
mPALR_PADDR19:      .equ   %1000000000
mPALR_PADDR110:     .equ   %10000000000
mPALR_PADDR111:     .equ   %100000000000
mPALR_PADDR112:     .equ   %1000000000000
mPALR_PADDR113:     .equ   %10000000000000
mPALR_PADDR114:     .equ   %100000000000000
mPALR_PADDR115:     .equ   %1000000000000000
mPALR_PADDR116:     .equ   %10000000000000000
mPALR_PADDR117:     .equ   %100000000000000000
mPALR_PADDR118:     .equ   %1000000000000000000
mPALR_PADDR119:     .equ   %10000000000000000000
mPALR_PADDR120:     .equ   %100000000000000000000
mPALR_PADDR121:     .equ   %1000000000000000000000
mPALR_PADDR122:     .equ   %10000000000000000000000
mPALR_PADDR123:     .equ   %100000000000000000000000
mPALR_PADDR124:     .equ   %1000000000000000000000000
mPALR_PADDR125:     .equ   %10000000000000000000000000
mPALR_PADDR126:     .equ   %100000000000000000000000000
mPALR_PADDR127:     .equ   %1000000000000000000000000000
mPALR_PADDR128:     .equ   %10000000000000000000000000000
mPALR_PADDR129:     .equ   %100000000000000000000000000000
mPALR_PADDR130:     .equ   %1000000000000000000000000000000
mPALR_PADDR131:     .equ   %10000000000000000000000000000000


;*** PAUR - Physical Address High Register; 0xFFFFE0E8 ***
PAUR:               .equ   $FFFFE0E8                                ;*** PAUR - Physical Address High Register; 0xFFFFE0E8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PAUR_TYPE0:         .equ   0                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 0
PAUR_TYPE1:         .equ   1                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 1
PAUR_TYPE2:         .equ   2                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 2
PAUR_TYPE3:         .equ   3                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 3
PAUR_TYPE4:         .equ   4                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 4
PAUR_TYPE5:         .equ   5                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 5
PAUR_TYPE6:         .equ   6                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 6
PAUR_TYPE7:         .equ   7                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 7
PAUR_TYPE8:         .equ   8                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 8
PAUR_TYPE9:         .equ   9                                         ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 9
PAUR_TYPE10:        .equ   10                                        ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 10
PAUR_TYPE11:        .equ   11                                        ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 11
PAUR_TYPE12:        .equ   12                                        ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 12
PAUR_TYPE13:        .equ   13                                        ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 13
PAUR_TYPE14:        .equ   14                                        ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 14
PAUR_TYPE15:        .equ   15                                        ; Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 15
PAUR_PADDR20:       .equ   16                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 0
PAUR_PADDR21:       .equ   17                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 1
PAUR_PADDR22:       .equ   18                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 2
PAUR_PADDR23:       .equ   19                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 3
PAUR_PADDR24:       .equ   20                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 4
PAUR_PADDR25:       .equ   21                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 5
PAUR_PADDR26:       .equ   22                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 6
PAUR_PADDR27:       .equ   23                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 7
PAUR_PADDR28:       .equ   24                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 8
PAUR_PADDR29:       .equ   25                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 9
PAUR_PADDR210:      .equ   26                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 10
PAUR_PADDR211:      .equ   27                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 11
PAUR_PADDR212:      .equ   28                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 12
PAUR_PADDR213:      .equ   29                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 13
PAUR_PADDR214:      .equ   30                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 14
PAUR_PADDR215:      .equ   31                                        ; Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 15
; bit position masks
mPAUR_TYPE0:        .equ   %00000001
mPAUR_TYPE1:        .equ   %00000010
mPAUR_TYPE2:        .equ   %00000100
mPAUR_TYPE3:        .equ   %00001000
mPAUR_TYPE4:        .equ   %00010000
mPAUR_TYPE5:        .equ   %00100000
mPAUR_TYPE6:        .equ   %01000000
mPAUR_TYPE7:        .equ   %10000000
mPAUR_TYPE8:        .equ   %100000000
mPAUR_TYPE9:        .equ   %1000000000
mPAUR_TYPE10:       .equ   %10000000000
mPAUR_TYPE11:       .equ   %100000000000
mPAUR_TYPE12:       .equ   %1000000000000
mPAUR_TYPE13:       .equ   %10000000000000
mPAUR_TYPE14:       .equ   %100000000000000
mPAUR_TYPE15:       .equ   %1000000000000000
mPAUR_PADDR20:      .equ   %10000000000000000
mPAUR_PADDR21:      .equ   %100000000000000000
mPAUR_PADDR22:      .equ   %1000000000000000000
mPAUR_PADDR23:      .equ   %10000000000000000000
mPAUR_PADDR24:      .equ   %100000000000000000000
mPAUR_PADDR25:      .equ   %1000000000000000000000
mPAUR_PADDR26:      .equ   %10000000000000000000000
mPAUR_PADDR27:      .equ   %100000000000000000000000
mPAUR_PADDR28:      .equ   %1000000000000000000000000
mPAUR_PADDR29:      .equ   %10000000000000000000000000
mPAUR_PADDR210:     .equ   %100000000000000000000000000
mPAUR_PADDR211:     .equ   %1000000000000000000000000000
mPAUR_PADDR212:     .equ   %10000000000000000000000000000
mPAUR_PADDR213:     .equ   %100000000000000000000000000000
mPAUR_PADDR214:     .equ   %1000000000000000000000000000000
mPAUR_PADDR215:     .equ   %10000000000000000000000000000000


;*** OPD - Opcode/Pause Duration Register; 0xFFFFE0EC ***
OPD:                .equ   $FFFFE0EC                                ;*** OPD - Opcode/Pause Duration Register; 0xFFFFE0EC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OPD_PAUSE_DUR0:     .equ   0                                         ; Pause Duration field used in PAUSE frames, bit 0
OPD_PAUSE_DUR1:     .equ   1                                         ; Pause Duration field used in PAUSE frames, bit 1
OPD_PAUSE_DUR2:     .equ   2                                         ; Pause Duration field used in PAUSE frames, bit 2
OPD_PAUSE_DUR3:     .equ   3                                         ; Pause Duration field used in PAUSE frames, bit 3
OPD_PAUSE_DUR4:     .equ   4                                         ; Pause Duration field used in PAUSE frames, bit 4
OPD_PAUSE_DUR5:     .equ   5                                         ; Pause Duration field used in PAUSE frames, bit 5
OPD_PAUSE_DUR6:     .equ   6                                         ; Pause Duration field used in PAUSE frames, bit 6
OPD_PAUSE_DUR7:     .equ   7                                         ; Pause Duration field used in PAUSE frames, bit 7
OPD_PAUSE_DUR8:     .equ   8                                         ; Pause Duration field used in PAUSE frames, bit 8
OPD_PAUSE_DUR9:     .equ   9                                         ; Pause Duration field used in PAUSE frames, bit 9
OPD_PAUSE_DUR10:    .equ   10                                        ; Pause Duration field used in PAUSE frames, bit 10
OPD_PAUSE_DUR11:    .equ   11                                        ; Pause Duration field used in PAUSE frames, bit 11
OPD_PAUSE_DUR12:    .equ   12                                        ; Pause Duration field used in PAUSE frames, bit 12
OPD_PAUSE_DUR13:    .equ   13                                        ; Pause Duration field used in PAUSE frames, bit 13
OPD_PAUSE_DUR14:    .equ   14                                        ; Pause Duration field used in PAUSE frames, bit 14
OPD_PAUSE_DUR15:    .equ   15                                        ; Pause Duration field used in PAUSE frames, bit 15
OPD_OPCODE0:        .equ   16                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 0
OPD_OPCODE1:        .equ   17                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 1
OPD_OPCODE2:        .equ   18                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 2
OPD_OPCODE3:        .equ   19                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 3
OPD_OPCODE4:        .equ   20                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 4
OPD_OPCODE5:        .equ   21                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 5
OPD_OPCODE6:        .equ   22                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 6
OPD_OPCODE7:        .equ   23                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 7
OPD_OPCODE8:        .equ   24                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 8
OPD_OPCODE9:        .equ   25                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 9
OPD_OPCODE10:       .equ   26                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 10
OPD_OPCODE11:       .equ   27                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 11
OPD_OPCODE12:       .equ   28                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 12
OPD_OPCODE13:       .equ   29                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 13
OPD_OPCODE14:       .equ   30                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 14
OPD_OPCODE15:       .equ   31                                        ; Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 15
; bit position masks
mOPD_PAUSE_DUR0:    .equ   %00000001
mOPD_PAUSE_DUR1:    .equ   %00000010
mOPD_PAUSE_DUR2:    .equ   %00000100
mOPD_PAUSE_DUR3:    .equ   %00001000
mOPD_PAUSE_DUR4:    .equ   %00010000
mOPD_PAUSE_DUR5:    .equ   %00100000
mOPD_PAUSE_DUR6:    .equ   %01000000
mOPD_PAUSE_DUR7:    .equ   %10000000
mOPD_PAUSE_DUR8:    .equ   %100000000
mOPD_PAUSE_DUR9:    .equ   %1000000000
mOPD_PAUSE_DUR10:   .equ   %10000000000
mOPD_PAUSE_DUR11:   .equ   %100000000000
mOPD_PAUSE_DUR12:   .equ   %1000000000000
mOPD_PAUSE_DUR13:   .equ   %10000000000000
mOPD_PAUSE_DUR14:   .equ   %100000000000000
mOPD_PAUSE_DUR15:   .equ   %1000000000000000
mOPD_OPCODE0:       .equ   %10000000000000000
mOPD_OPCODE1:       .equ   %100000000000000000
mOPD_OPCODE2:       .equ   %1000000000000000000
mOPD_OPCODE3:       .equ   %10000000000000000000
mOPD_OPCODE4:       .equ   %100000000000000000000
mOPD_OPCODE5:       .equ   %1000000000000000000000
mOPD_OPCODE6:       .equ   %10000000000000000000000
mOPD_OPCODE7:       .equ   %100000000000000000000000
mOPD_OPCODE8:       .equ   %1000000000000000000000000
mOPD_OPCODE9:       .equ   %10000000000000000000000000
mOPD_OPCODE10:      .equ   %100000000000000000000000000
mOPD_OPCODE11:      .equ   %1000000000000000000000000000
mOPD_OPCODE12:      .equ   %10000000000000000000000000000
mOPD_OPCODE13:      .equ   %100000000000000000000000000000
mOPD_OPCODE14:      .equ   %1000000000000000000000000000000
mOPD_OPCODE15:      .equ   %10000000000000000000000000000000


;*** IAUR - Descriptor Individual Upper Address Register; 0xFFFFE118 ***
IAUR:               .equ   $FFFFE118                                ;*** IAUR - Descriptor Individual Upper Address Register; 0xFFFFE118 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IAUR_IADDR10:       .equ   0                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 0
IAUR_IADDR11:       .equ   1                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 1
IAUR_IADDR12:       .equ   2                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 2
IAUR_IADDR13:       .equ   3                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 3
IAUR_IADDR14:       .equ   4                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 4
IAUR_IADDR15:       .equ   5                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 5
IAUR_IADDR16:       .equ   6                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 6
IAUR_IADDR17:       .equ   7                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 7
IAUR_IADDR18:       .equ   8                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 8
IAUR_IADDR19:       .equ   9                                         ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 9
IAUR_IADDR110:      .equ   10                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 10
IAUR_IADDR111:      .equ   11                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 11
IAUR_IADDR112:      .equ   12                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 12
IAUR_IADDR113:      .equ   13                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 13
IAUR_IADDR114:      .equ   14                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 14
IAUR_IADDR115:      .equ   15                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 15
IAUR_IADDR116:      .equ   16                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 16
IAUR_IADDR117:      .equ   17                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 17
IAUR_IADDR118:      .equ   18                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 18
IAUR_IADDR119:      .equ   19                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 19
IAUR_IADDR120:      .equ   20                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 20
IAUR_IADDR121:      .equ   21                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 21
IAUR_IADDR122:      .equ   22                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 22
IAUR_IADDR123:      .equ   23                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 23
IAUR_IADDR124:      .equ   24                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 24
IAUR_IADDR125:      .equ   25                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 25
IAUR_IADDR126:      .equ   26                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 26
IAUR_IADDR127:      .equ   27                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 27
IAUR_IADDR128:      .equ   28                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 28
IAUR_IADDR129:      .equ   29                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 29
IAUR_IADDR130:      .equ   30                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 30
IAUR_IADDR131:      .equ   31                                        ; The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 31
; bit position masks
mIAUR_IADDR10:      .equ   %00000001
mIAUR_IADDR11:      .equ   %00000010
mIAUR_IADDR12:      .equ   %00000100
mIAUR_IADDR13:      .equ   %00001000
mIAUR_IADDR14:      .equ   %00010000
mIAUR_IADDR15:      .equ   %00100000
mIAUR_IADDR16:      .equ   %01000000
mIAUR_IADDR17:      .equ   %10000000
mIAUR_IADDR18:      .equ   %100000000
mIAUR_IADDR19:      .equ   %1000000000
mIAUR_IADDR110:     .equ   %10000000000
mIAUR_IADDR111:     .equ   %100000000000
mIAUR_IADDR112:     .equ   %1000000000000
mIAUR_IADDR113:     .equ   %10000000000000
mIAUR_IADDR114:     .equ   %100000000000000
mIAUR_IADDR115:     .equ   %1000000000000000
mIAUR_IADDR116:     .equ   %10000000000000000
mIAUR_IADDR117:     .equ   %100000000000000000
mIAUR_IADDR118:     .equ   %1000000000000000000
mIAUR_IADDR119:     .equ   %10000000000000000000
mIAUR_IADDR120:     .equ   %100000000000000000000
mIAUR_IADDR121:     .equ   %1000000000000000000000
mIAUR_IADDR122:     .equ   %10000000000000000000000
mIAUR_IADDR123:     .equ   %100000000000000000000000
mIAUR_IADDR124:     .equ   %1000000000000000000000000
mIAUR_IADDR125:     .equ   %10000000000000000000000000
mIAUR_IADDR126:     .equ   %100000000000000000000000000
mIAUR_IADDR127:     .equ   %1000000000000000000000000000
mIAUR_IADDR128:     .equ   %10000000000000000000000000000
mIAUR_IADDR129:     .equ   %100000000000000000000000000000
mIAUR_IADDR130:     .equ   %1000000000000000000000000000000
mIAUR_IADDR131:     .equ   %10000000000000000000000000000000


;*** IALR - Descriptor Individual Lower Address Register; 0xFFFFE11C ***
IALR:               .equ   $FFFFE11C                                ;*** IALR - Descriptor Individual Lower Address Register; 0xFFFFE11C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IALR_IADDR20:       .equ   0                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 0
IALR_IADDR21:       .equ   1                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 1
IALR_IADDR22:       .equ   2                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 2
IALR_IADDR23:       .equ   3                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 3
IALR_IADDR24:       .equ   4                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 4
IALR_IADDR25:       .equ   5                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 5
IALR_IADDR26:       .equ   6                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 6
IALR_IADDR27:       .equ   7                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 7
IALR_IADDR28:       .equ   8                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 8
IALR_IADDR29:       .equ   9                                         ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 9
IALR_IADDR210:      .equ   10                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 10
IALR_IADDR211:      .equ   11                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 11
IALR_IADDR212:      .equ   12                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 12
IALR_IADDR213:      .equ   13                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 13
IALR_IADDR214:      .equ   14                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 14
IALR_IADDR215:      .equ   15                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 15
IALR_IADDR216:      .equ   16                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 16
IALR_IADDR217:      .equ   17                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 17
IALR_IADDR218:      .equ   18                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 18
IALR_IADDR219:      .equ   19                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 19
IALR_IADDR220:      .equ   20                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 20
IALR_IADDR221:      .equ   21                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 21
IALR_IADDR222:      .equ   22                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 22
IALR_IADDR223:      .equ   23                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 23
IALR_IADDR224:      .equ   24                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 24
IALR_IADDR225:      .equ   25                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 25
IALR_IADDR226:      .equ   26                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 26
IALR_IADDR227:      .equ   27                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 27
IALR_IADDR228:      .equ   28                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 28
IALR_IADDR229:      .equ   29                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 29
IALR_IADDR230:      .equ   30                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 30
IALR_IADDR231:      .equ   31                                        ; The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 31
; bit position masks
mIALR_IADDR20:      .equ   %00000001
mIALR_IADDR21:      .equ   %00000010
mIALR_IADDR22:      .equ   %00000100
mIALR_IADDR23:      .equ   %00001000
mIALR_IADDR24:      .equ   %00010000
mIALR_IADDR25:      .equ   %00100000
mIALR_IADDR26:      .equ   %01000000
mIALR_IADDR27:      .equ   %10000000
mIALR_IADDR28:      .equ   %100000000
mIALR_IADDR29:      .equ   %1000000000
mIALR_IADDR210:     .equ   %10000000000
mIALR_IADDR211:     .equ   %100000000000
mIALR_IADDR212:     .equ   %1000000000000
mIALR_IADDR213:     .equ   %10000000000000
mIALR_IADDR214:     .equ   %100000000000000
mIALR_IADDR215:     .equ   %1000000000000000
mIALR_IADDR216:     .equ   %10000000000000000
mIALR_IADDR217:     .equ   %100000000000000000
mIALR_IADDR218:     .equ   %1000000000000000000
mIALR_IADDR219:     .equ   %10000000000000000000
mIALR_IADDR220:     .equ   %100000000000000000000
mIALR_IADDR221:     .equ   %1000000000000000000000
mIALR_IADDR222:     .equ   %10000000000000000000000
mIALR_IADDR223:     .equ   %100000000000000000000000
mIALR_IADDR224:     .equ   %1000000000000000000000000
mIALR_IADDR225:     .equ   %10000000000000000000000000
mIALR_IADDR226:     .equ   %100000000000000000000000000
mIALR_IADDR227:     .equ   %1000000000000000000000000000
mIALR_IADDR228:     .equ   %10000000000000000000000000000
mIALR_IADDR229:     .equ   %100000000000000000000000000000
mIALR_IADDR230:     .equ   %1000000000000000000000000000000
mIALR_IADDR231:     .equ   %10000000000000000000000000000000


;*** GAUR - Descriptor Group Upper Address Register; 0xFFFFE120 ***
GAUR:               .equ   $FFFFE120                                ;*** GAUR - Descriptor Group Upper Address Register; 0xFFFFE120 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GAUR_GADDR10:       .equ   0                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 0
GAUR_GADDR11:       .equ   1                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 1
GAUR_GADDR12:       .equ   2                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 2
GAUR_GADDR13:       .equ   3                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 3
GAUR_GADDR14:       .equ   4                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 4
GAUR_GADDR15:       .equ   5                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 5
GAUR_GADDR16:       .equ   6                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 6
GAUR_GADDR17:       .equ   7                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 7
GAUR_GADDR18:       .equ   8                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 8
GAUR_GADDR19:       .equ   9                                         ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 9
GAUR_GADDR110:      .equ   10                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 10
GAUR_GADDR111:      .equ   11                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 11
GAUR_GADDR112:      .equ   12                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 12
GAUR_GADDR113:      .equ   13                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 13
GAUR_GADDR114:      .equ   14                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 14
GAUR_GADDR115:      .equ   15                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 15
GAUR_GADDR116:      .equ   16                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 16
GAUR_GADDR117:      .equ   17                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 17
GAUR_GADDR118:      .equ   18                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 18
GAUR_GADDR119:      .equ   19                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 19
GAUR_GADDR120:      .equ   20                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 20
GAUR_GADDR121:      .equ   21                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 21
GAUR_GADDR122:      .equ   22                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 22
GAUR_GADDR123:      .equ   23                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 23
GAUR_GADDR124:      .equ   24                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 24
GAUR_GADDR125:      .equ   25                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 25
GAUR_GADDR126:      .equ   26                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 26
GAUR_GADDR127:      .equ   27                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 27
GAUR_GADDR128:      .equ   28                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 28
GAUR_GADDR129:      .equ   29                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 29
GAUR_GADDR130:      .equ   30                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 30
GAUR_GADDR131:      .equ   31                                        ; The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 31
; bit position masks
mGAUR_GADDR10:      .equ   %00000001
mGAUR_GADDR11:      .equ   %00000010
mGAUR_GADDR12:      .equ   %00000100
mGAUR_GADDR13:      .equ   %00001000
mGAUR_GADDR14:      .equ   %00010000
mGAUR_GADDR15:      .equ   %00100000
mGAUR_GADDR16:      .equ   %01000000
mGAUR_GADDR17:      .equ   %10000000
mGAUR_GADDR18:      .equ   %100000000
mGAUR_GADDR19:      .equ   %1000000000
mGAUR_GADDR110:     .equ   %10000000000
mGAUR_GADDR111:     .equ   %100000000000
mGAUR_GADDR112:     .equ   %1000000000000
mGAUR_GADDR113:     .equ   %10000000000000
mGAUR_GADDR114:     .equ   %100000000000000
mGAUR_GADDR115:     .equ   %1000000000000000
mGAUR_GADDR116:     .equ   %10000000000000000
mGAUR_GADDR117:     .equ   %100000000000000000
mGAUR_GADDR118:     .equ   %1000000000000000000
mGAUR_GADDR119:     .equ   %10000000000000000000
mGAUR_GADDR120:     .equ   %100000000000000000000
mGAUR_GADDR121:     .equ   %1000000000000000000000
mGAUR_GADDR122:     .equ   %10000000000000000000000
mGAUR_GADDR123:     .equ   %100000000000000000000000
mGAUR_GADDR124:     .equ   %1000000000000000000000000
mGAUR_GADDR125:     .equ   %10000000000000000000000000
mGAUR_GADDR126:     .equ   %100000000000000000000000000
mGAUR_GADDR127:     .equ   %1000000000000000000000000000
mGAUR_GADDR128:     .equ   %10000000000000000000000000000
mGAUR_GADDR129:     .equ   %100000000000000000000000000000
mGAUR_GADDR130:     .equ   %1000000000000000000000000000000
mGAUR_GADDR131:     .equ   %10000000000000000000000000000000


;*** GALR - Descriptor Group Lower Address Register; 0xFFFFE124 ***
GALR:               .equ   $FFFFE124                                ;*** GALR - Descriptor Group Lower Address Register; 0xFFFFE124 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GALR_GADDR20:       .equ   0                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 0
GALR_GADDR21:       .equ   1                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 1
GALR_GADDR22:       .equ   2                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 2
GALR_GADDR23:       .equ   3                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 3
GALR_GADDR24:       .equ   4                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 4
GALR_GADDR25:       .equ   5                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 5
GALR_GADDR26:       .equ   6                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 6
GALR_GADDR27:       .equ   7                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 7
GALR_GADDR28:       .equ   8                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 8
GALR_GADDR29:       .equ   9                                         ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 9
GALR_GADDR210:      .equ   10                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 10
GALR_GADDR211:      .equ   11                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 11
GALR_GADDR212:      .equ   12                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 12
GALR_GADDR213:      .equ   13                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 13
GALR_GADDR214:      .equ   14                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 14
GALR_GADDR215:      .equ   15                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 15
GALR_GADDR216:      .equ   16                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 16
GALR_GADDR217:      .equ   17                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 17
GALR_GADDR218:      .equ   18                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 18
GALR_GADDR219:      .equ   19                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 19
GALR_GADDR220:      .equ   20                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 20
GALR_GADDR221:      .equ   21                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 21
GALR_GADDR222:      .equ   22                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 22
GALR_GADDR223:      .equ   23                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 23
GALR_GADDR224:      .equ   24                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 24
GALR_GADDR225:      .equ   25                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 25
GALR_GADDR226:      .equ   26                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 26
GALR_GADDR227:      .equ   27                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 27
GALR_GADDR228:      .equ   28                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 28
GALR_GADDR229:      .equ   29                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 29
GALR_GADDR230:      .equ   30                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 30
GALR_GADDR231:      .equ   31                                        ; The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 31
; bit position masks
mGALR_GADDR20:      .equ   %00000001
mGALR_GADDR21:      .equ   %00000010
mGALR_GADDR22:      .equ   %00000100
mGALR_GADDR23:      .equ   %00001000
mGALR_GADDR24:      .equ   %00010000
mGALR_GADDR25:      .equ   %00100000
mGALR_GADDR26:      .equ   %01000000
mGALR_GADDR27:      .equ   %10000000
mGALR_GADDR28:      .equ   %100000000
mGALR_GADDR29:      .equ   %1000000000
mGALR_GADDR210:     .equ   %10000000000
mGALR_GADDR211:     .equ   %100000000000
mGALR_GADDR212:     .equ   %1000000000000
mGALR_GADDR213:     .equ   %10000000000000
mGALR_GADDR214:     .equ   %100000000000000
mGALR_GADDR215:     .equ   %1000000000000000
mGALR_GADDR216:     .equ   %10000000000000000
mGALR_GADDR217:     .equ   %100000000000000000
mGALR_GADDR218:     .equ   %1000000000000000000
mGALR_GADDR219:     .equ   %10000000000000000000
mGALR_GADDR220:     .equ   %100000000000000000000
mGALR_GADDR221:     .equ   %1000000000000000000000
mGALR_GADDR222:     .equ   %10000000000000000000000
mGALR_GADDR223:     .equ   %100000000000000000000000
mGALR_GADDR224:     .equ   %1000000000000000000000000
mGALR_GADDR225:     .equ   %10000000000000000000000000
mGALR_GADDR226:     .equ   %100000000000000000000000000
mGALR_GADDR227:     .equ   %1000000000000000000000000000
mGALR_GADDR228:     .equ   %10000000000000000000000000000
mGALR_GADDR229:     .equ   %100000000000000000000000000000
mGALR_GADDR230:     .equ   %1000000000000000000000000000000
mGALR_GADDR231:     .equ   %10000000000000000000000000000000


;*** TFWR - FIFO Transmit FIFO Watermark Register; 0xFFFFE144 ***
TFWR:               .equ   $FFFFE144                                ;*** TFWR - FIFO Transmit FIFO Watermark Register; 0xFFFFE144 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TFWR_TFWR0:         .equ   0                                         ; Number of bytes written to transmit FIFO before transmission of a frame begins, bit 0
TFWR_TFWR1:         .equ   1                                         ; Number of bytes written to transmit FIFO before transmission of a frame begins, bit 1
; bit position masks
mTFWR_TFWR0:        .equ   %00000001
mTFWR_TFWR1:        .equ   %00000010


;*** FRBR - FIFO Receive Bound Register; 0xFFFFE14C ***
FRBR:               .equ   $FFFFE14C                                ;*** FRBR - FIFO Receive Bound Register; 0xFFFFE14C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRBR_R_BOUND0:      .equ   2                                         ; Read-only. Highest valid FIFO RAM address, bit 0
FRBR_R_BOUND1:      .equ   3                                         ; Read-only. Highest valid FIFO RAM address, bit 1
FRBR_R_BOUND2:      .equ   4                                         ; Read-only. Highest valid FIFO RAM address, bit 2
FRBR_R_BOUND3:      .equ   5                                         ; Read-only. Highest valid FIFO RAM address, bit 3
FRBR_R_BOUND4:      .equ   6                                         ; Read-only. Highest valid FIFO RAM address, bit 4
FRBR_R_BOUND5:      .equ   7                                         ; Read-only. Highest valid FIFO RAM address, bit 5
FRBR_R_BOUND6:      .equ   8                                         ; Read-only. Highest valid FIFO RAM address, bit 6
FRBR_R_BOUND7:      .equ   9                                         ; Read-only. Highest valid FIFO RAM address, bit 7
; bit position masks
mFRBR_R_BOUND0:     .equ   %00000100
mFRBR_R_BOUND1:     .equ   %00001000
mFRBR_R_BOUND2:     .equ   %00010000
mFRBR_R_BOUND3:     .equ   %00100000
mFRBR_R_BOUND4:     .equ   %01000000
mFRBR_R_BOUND5:     .equ   %10000000
mFRBR_R_BOUND6:     .equ   %100000000
mFRBR_R_BOUND7:     .equ   %1000000000


;*** FRSR - FIFO Receive Start Register; 0xFFFFE150 ***
FRSR:               .equ   $FFFFE150                                ;*** FRSR - FIFO Receive Start Register; 0xFFFFE150 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRSR_R_FSTART0:     .equ   2                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 0
FRSR_R_FSTART1:     .equ   3                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 1
FRSR_R_FSTART2:     .equ   4                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 2
FRSR_R_FSTART3:     .equ   5                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 3
FRSR_R_FSTART4:     .equ   6                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 4
FRSR_R_FSTART5:     .equ   7                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 5
FRSR_R_FSTART6:     .equ   8                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 6
FRSR_R_FSTART7:     .equ   9                                         ; Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 7
; bit position masks
mFRSR_R_FSTART0:    .equ   %00000100
mFRSR_R_FSTART1:    .equ   %00001000
mFRSR_R_FSTART2:    .equ   %00010000
mFRSR_R_FSTART3:    .equ   %00100000
mFRSR_R_FSTART4:    .equ   %01000000
mFRSR_R_FSTART5:    .equ   %10000000
mFRSR_R_FSTART6:    .equ   %100000000
mFRSR_R_FSTART7:    .equ   %1000000000


;*** ERDSR - Receive Descriptor Ring Start Register; 0xFFFFE180 ***
ERDSR:              .equ   $FFFFE180                                ;*** ERDSR - Receive Descriptor Ring Start Register; 0xFFFFE180 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ERDSR_R_DES_START0: .equ   2                                         ; Pointer to start of receive buffer descriptor queue, bit 0
ERDSR_R_DES_START1: .equ   3                                         ; Pointer to start of receive buffer descriptor queue, bit 1
ERDSR_R_DES_START2: .equ   4                                         ; Pointer to start of receive buffer descriptor queue, bit 2
ERDSR_R_DES_START3: .equ   5                                         ; Pointer to start of receive buffer descriptor queue, bit 3
ERDSR_R_DES_START4: .equ   6                                         ; Pointer to start of receive buffer descriptor queue, bit 4
ERDSR_R_DES_START5: .equ   7                                         ; Pointer to start of receive buffer descriptor queue, bit 5
ERDSR_R_DES_START6: .equ   8                                         ; Pointer to start of receive buffer descriptor queue, bit 6
ERDSR_R_DES_START7: .equ   9                                         ; Pointer to start of receive buffer descriptor queue, bit 7
ERDSR_R_DES_START8: .equ   10                                        ; Pointer to start of receive buffer descriptor queue, bit 8
ERDSR_R_DES_START9: .equ   11                                        ; Pointer to start of receive buffer descriptor queue, bit 9
ERDSR_R_DES_START10: .equ   12                                       ; Pointer to start of receive buffer descriptor queue, bit 10
ERDSR_R_DES_START11: .equ   13                                       ; Pointer to start of receive buffer descriptor queue, bit 11
ERDSR_R_DES_START12: .equ   14                                       ; Pointer to start of receive buffer descriptor queue, bit 12
ERDSR_R_DES_START13: .equ   15                                       ; Pointer to start of receive buffer descriptor queue, bit 13
ERDSR_R_DES_START14: .equ   16                                       ; Pointer to start of receive buffer descriptor queue, bit 14
ERDSR_R_DES_START15: .equ   17                                       ; Pointer to start of receive buffer descriptor queue, bit 15
ERDSR_R_DES_START16: .equ   18                                       ; Pointer to start of receive buffer descriptor queue, bit 16
ERDSR_R_DES_START17: .equ   19                                       ; Pointer to start of receive buffer descriptor queue, bit 17
ERDSR_R_DES_START18: .equ   20                                       ; Pointer to start of receive buffer descriptor queue, bit 18
ERDSR_R_DES_START19: .equ   21                                       ; Pointer to start of receive buffer descriptor queue, bit 19
ERDSR_R_DES_START20: .equ   22                                       ; Pointer to start of receive buffer descriptor queue, bit 20
ERDSR_R_DES_START21: .equ   23                                       ; Pointer to start of receive buffer descriptor queue, bit 21
ERDSR_R_DES_START22: .equ   24                                       ; Pointer to start of receive buffer descriptor queue, bit 22
ERDSR_R_DES_START23: .equ   25                                       ; Pointer to start of receive buffer descriptor queue, bit 23
ERDSR_R_DES_START24: .equ   26                                       ; Pointer to start of receive buffer descriptor queue, bit 24
ERDSR_R_DES_START25: .equ   27                                       ; Pointer to start of receive buffer descriptor queue, bit 25
ERDSR_R_DES_START26: .equ   28                                       ; Pointer to start of receive buffer descriptor queue, bit 26
ERDSR_R_DES_START27: .equ   29                                       ; Pointer to start of receive buffer descriptor queue, bit 27
ERDSR_R_DES_START28: .equ   30                                       ; Pointer to start of receive buffer descriptor queue, bit 28
ERDSR_R_DES_START29: .equ   31                                       ; Pointer to start of receive buffer descriptor queue, bit 29
; bit position masks
mERDSR_R_DES_START0: .equ   %00000100
mERDSR_R_DES_START1: .equ   %00001000
mERDSR_R_DES_START2: .equ   %00010000
mERDSR_R_DES_START3: .equ   %00100000
mERDSR_R_DES_START4: .equ   %01000000
mERDSR_R_DES_START5: .equ   %10000000
mERDSR_R_DES_START6: .equ   %100000000
mERDSR_R_DES_START7: .equ   %1000000000
mERDSR_R_DES_START8: .equ   %10000000000
mERDSR_R_DES_START9: .equ   %100000000000
mERDSR_R_DES_START10: .equ   %1000000000000
mERDSR_R_DES_START11: .equ   %10000000000000
mERDSR_R_DES_START12: .equ   %100000000000000
mERDSR_R_DES_START13: .equ   %1000000000000000
mERDSR_R_DES_START14: .equ   %10000000000000000
mERDSR_R_DES_START15: .equ   %100000000000000000
mERDSR_R_DES_START16: .equ   %1000000000000000000
mERDSR_R_DES_START17: .equ   %10000000000000000000
mERDSR_R_DES_START18: .equ   %100000000000000000000
mERDSR_R_DES_START19: .equ   %1000000000000000000000
mERDSR_R_DES_START20: .equ   %10000000000000000000000
mERDSR_R_DES_START21: .equ   %100000000000000000000000
mERDSR_R_DES_START22: .equ   %1000000000000000000000000
mERDSR_R_DES_START23: .equ   %10000000000000000000000000
mERDSR_R_DES_START24: .equ   %100000000000000000000000000
mERDSR_R_DES_START25: .equ   %1000000000000000000000000000
mERDSR_R_DES_START26: .equ   %10000000000000000000000000000
mERDSR_R_DES_START27: .equ   %100000000000000000000000000000
mERDSR_R_DES_START28: .equ   %1000000000000000000000000000000
mERDSR_R_DES_START29: .equ   %10000000000000000000000000000000


;*** ETSDR - Transmit Buffer Descriptor Ring Start Register; 0xFFFFE184 ***
ETSDR:              .equ   $FFFFE184                                ;*** ETSDR - Transmit Buffer Descriptor Ring Start Register; 0xFFFFE184 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ETSDR_X_DES_START0: .equ   2                                         ; Pointer to start of transmit buffer descriptor queue, bit 0
ETSDR_X_DES_START1: .equ   3                                         ; Pointer to start of transmit buffer descriptor queue, bit 1
ETSDR_X_DES_START2: .equ   4                                         ; Pointer to start of transmit buffer descriptor queue, bit 2
ETSDR_X_DES_START3: .equ   5                                         ; Pointer to start of transmit buffer descriptor queue, bit 3
ETSDR_X_DES_START4: .equ   6                                         ; Pointer to start of transmit buffer descriptor queue, bit 4
ETSDR_X_DES_START5: .equ   7                                         ; Pointer to start of transmit buffer descriptor queue, bit 5
ETSDR_X_DES_START6: .equ   8                                         ; Pointer to start of transmit buffer descriptor queue, bit 6
ETSDR_X_DES_START7: .equ   9                                         ; Pointer to start of transmit buffer descriptor queue, bit 7
ETSDR_X_DES_START8: .equ   10                                        ; Pointer to start of transmit buffer descriptor queue, bit 8
ETSDR_X_DES_START9: .equ   11                                        ; Pointer to start of transmit buffer descriptor queue, bit 9
ETSDR_X_DES_START10: .equ   12                                       ; Pointer to start of transmit buffer descriptor queue, bit 10
ETSDR_X_DES_START11: .equ   13                                       ; Pointer to start of transmit buffer descriptor queue, bit 11
ETSDR_X_DES_START12: .equ   14                                       ; Pointer to start of transmit buffer descriptor queue, bit 12
ETSDR_X_DES_START13: .equ   15                                       ; Pointer to start of transmit buffer descriptor queue, bit 13
ETSDR_X_DES_START14: .equ   16                                       ; Pointer to start of transmit buffer descriptor queue, bit 14
ETSDR_X_DES_START15: .equ   17                                       ; Pointer to start of transmit buffer descriptor queue, bit 15
ETSDR_X_DES_START16: .equ   18                                       ; Pointer to start of transmit buffer descriptor queue, bit 16
ETSDR_X_DES_START17: .equ   19                                       ; Pointer to start of transmit buffer descriptor queue, bit 17
ETSDR_X_DES_START18: .equ   20                                       ; Pointer to start of transmit buffer descriptor queue, bit 18
ETSDR_X_DES_START19: .equ   21                                       ; Pointer to start of transmit buffer descriptor queue, bit 19
ETSDR_X_DES_START20: .equ   22                                       ; Pointer to start of transmit buffer descriptor queue, bit 20
ETSDR_X_DES_START21: .equ   23                                       ; Pointer to start of transmit buffer descriptor queue, bit 21
ETSDR_X_DES_START22: .equ   24                                       ; Pointer to start of transmit buffer descriptor queue, bit 22
ETSDR_X_DES_START23: .equ   25                                       ; Pointer to start of transmit buffer descriptor queue, bit 23
ETSDR_X_DES_START24: .equ   26                                       ; Pointer to start of transmit buffer descriptor queue, bit 24
ETSDR_X_DES_START25: .equ   27                                       ; Pointer to start of transmit buffer descriptor queue, bit 25
ETSDR_X_DES_START26: .equ   28                                       ; Pointer to start of transmit buffer descriptor queue, bit 26
ETSDR_X_DES_START27: .equ   29                                       ; Pointer to start of transmit buffer descriptor queue, bit 27
ETSDR_X_DES_START28: .equ   30                                       ; Pointer to start of transmit buffer descriptor queue, bit 28
ETSDR_X_DES_START29: .equ   31                                       ; Pointer to start of transmit buffer descriptor queue, bit 29
; bit position masks
mETSDR_X_DES_START0: .equ   %00000100
mETSDR_X_DES_START1: .equ   %00001000
mETSDR_X_DES_START2: .equ   %00010000
mETSDR_X_DES_START3: .equ   %00100000
mETSDR_X_DES_START4: .equ   %01000000
mETSDR_X_DES_START5: .equ   %10000000
mETSDR_X_DES_START6: .equ   %100000000
mETSDR_X_DES_START7: .equ   %1000000000
mETSDR_X_DES_START8: .equ   %10000000000
mETSDR_X_DES_START9: .equ   %100000000000
mETSDR_X_DES_START10: .equ   %1000000000000
mETSDR_X_DES_START11: .equ   %10000000000000
mETSDR_X_DES_START12: .equ   %100000000000000
mETSDR_X_DES_START13: .equ   %1000000000000000
mETSDR_X_DES_START14: .equ   %10000000000000000
mETSDR_X_DES_START15: .equ   %100000000000000000
mETSDR_X_DES_START16: .equ   %1000000000000000000
mETSDR_X_DES_START17: .equ   %10000000000000000000
mETSDR_X_DES_START18: .equ   %100000000000000000000
mETSDR_X_DES_START19: .equ   %1000000000000000000000
mETSDR_X_DES_START20: .equ   %10000000000000000000000
mETSDR_X_DES_START21: .equ   %100000000000000000000000
mETSDR_X_DES_START22: .equ   %1000000000000000000000000
mETSDR_X_DES_START23: .equ   %10000000000000000000000000
mETSDR_X_DES_START24: .equ   %100000000000000000000000000
mETSDR_X_DES_START25: .equ   %1000000000000000000000000000
mETSDR_X_DES_START26: .equ   %10000000000000000000000000000
mETSDR_X_DES_START27: .equ   %100000000000000000000000000000
mETSDR_X_DES_START28: .equ   %1000000000000000000000000000000
mETSDR_X_DES_START29: .equ   %10000000000000000000000000000000


;*** EMRBR - Receive Buffer Size Register; 0xFFFFE188 ***
EMRBR:              .equ   $FFFFE188                                ;*** EMRBR - Receive Buffer Size Register; 0xFFFFE188 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EMRBR_R_BUF_SIZE0:  .equ   4                                         ; Receive buffer size, bit 0
EMRBR_R_BUF_SIZE1:  .equ   5                                         ; Receive buffer size, bit 1
EMRBR_R_BUF_SIZE2:  .equ   6                                         ; Receive buffer size, bit 2
EMRBR_R_BUF_SIZE3:  .equ   7                                         ; Receive buffer size, bit 3
EMRBR_R_BUF_SIZE4:  .equ   8                                         ; Receive buffer size, bit 4
EMRBR_R_BUF_SIZE5:  .equ   9                                         ; Receive buffer size, bit 5
EMRBR_R_BUF_SIZE6:  .equ   10                                        ; Receive buffer size, bit 6
; bit position masks
mEMRBR_R_BUF_SIZE0: .equ   %00010000
mEMRBR_R_BUF_SIZE1: .equ   %00100000
mEMRBR_R_BUF_SIZE2: .equ   %01000000
mEMRBR_R_BUF_SIZE3: .equ   %10000000
mEMRBR_R_BUF_SIZE4: .equ   %100000000
mEMRBR_R_BUF_SIZE5: .equ   %1000000000
mEMRBR_R_BUF_SIZE6: .equ   %10000000000


;*** CSAR0 - Chip Select Address Register 0; 0xFFFFE800 ***
CSAR0:              .equ   $FFFFE800                                ;*** CSAR0 - Chip Select Address Register 0; 0xFFFFE800 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CSAR0_BA0:          .equ   16                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 0
CSAR0_BA1:          .equ   17                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 1
CSAR0_BA2:          .equ   18                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 2
CSAR0_BA3:          .equ   19                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 3
CSAR0_BA4:          .equ   20                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 4
CSAR0_BA5:          .equ   21                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 5
CSAR0_BA6:          .equ   22                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 6
CSAR0_BA7:          .equ   23                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 7
CSAR0_BA8:          .equ   24                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 8
CSAR0_BA9:          .equ   25                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 9
CSAR0_BA10:         .equ   26                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 10
CSAR0_BA11:         .equ   27                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 11
CSAR0_BA12:         .equ   28                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 12
CSAR0_BA13:         .equ   29                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 13
CSAR0_BA14:         .equ   30                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 14
CSAR0_BA15:         .equ   31                                        ; Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 15
; bit position masks
mCSAR0_BA0:         .equ   %10000000000000000
mCSAR0_BA1:         .equ   %100000000000000000
mCSAR0_BA2:         .equ   %1000000000000000000
mCSAR0_BA3:         .equ   %10000000000000000000
mCSAR0_BA4:         .equ   %100000000000000000000
mCSAR0_BA5:         .equ   %1000000000000000000000
mCSAR0_BA6:         .equ   %10000000000000000000000
mCSAR0_BA7:         .equ   %100000000000000000000000
mCSAR0_BA8:         .equ   %1000000000000000000000000
mCSAR0_BA9:         .equ   %10000000000000000000000000
mCSAR0_BA10:        .equ   %100000000000000000000000000
mCSAR0_BA11:        .equ   %1000000000000000000000000000
mCSAR0_BA12:        .equ   %10000000000000000000000000000
mCSAR0_BA13:        .equ   %100000000000000000000000000000
mCSAR0_BA14:        .equ   %1000000000000000000000000000000
mCSAR0_BA15:        .equ   %10000000000000000000000000000000


;*** CSMR0 - Chip Select Mask Register 0; 0xFFFFE804 ***
CSMR0:              .equ   $FFFFE804                                ;*** CSMR0 - Chip Select Mask Register 0; 0xFFFFE804 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CSMR0_V:            .equ   0                                         ; Valid bit. Indicates whether the corresponding CSAR, CSMR, and CSCR contents are valid. Programmed chip selects do not assert until V is set (except for CS0, which acts as the global chip select). Reset clears each CSMRn[V]
CSMR0_WP:           .equ   8                                         ; Write protect. Controls write accesses to the address range in the corresponding CSAR. Attempting to write to the range of addresses for which CSAR0[WP] = 1 results in the appropriate chip select not being selected. No exception occurs
CSMR0_BAM0:         .equ   16                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 0
CSMR0_BAM1:         .equ   17                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 1
CSMR0_BAM2:         .equ   18                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 2
CSMR0_BAM3:         .equ   19                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 3
CSMR0_BAM4:         .equ   20                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 4
CSMR0_BAM5:         .equ   21                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 5
CSMR0_BAM6:         .equ   22                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 6
CSMR0_BAM7:         .equ   23                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 7
CSMR0_BAM8:         .equ   24                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 8
CSMR0_BAM9:         .equ   25                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 9
CSMR0_BAM10:        .equ   26                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 10
CSMR0_BAM11:        .equ   27                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 11
CSMR0_BAM12:        .equ   28                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 12
CSMR0_BAM13:        .equ   29                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 13
CSMR0_BAM14:        .equ   30                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 14
CSMR0_BAM15:        .equ   31                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 15
; bit position masks
mCSMR0_V:           .equ   %00000001
mCSMR0_WP:          .equ   %100000000
mCSMR0_BAM0:        .equ   %10000000000000000
mCSMR0_BAM1:        .equ   %100000000000000000
mCSMR0_BAM2:        .equ   %1000000000000000000
mCSMR0_BAM3:        .equ   %10000000000000000000
mCSMR0_BAM4:        .equ   %100000000000000000000
mCSMR0_BAM5:        .equ   %1000000000000000000000
mCSMR0_BAM6:        .equ   %10000000000000000000000
mCSMR0_BAM7:        .equ   %100000000000000000000000
mCSMR0_BAM8:        .equ   %1000000000000000000000000
mCSMR0_BAM9:        .equ   %10000000000000000000000000
mCSMR0_BAM10:       .equ   %100000000000000000000000000
mCSMR0_BAM11:       .equ   %1000000000000000000000000000
mCSMR0_BAM12:       .equ   %10000000000000000000000000000
mCSMR0_BAM13:       .equ   %100000000000000000000000000000
mCSMR0_BAM14:       .equ   %1000000000000000000000000000000
mCSMR0_BAM15:       .equ   %10000000000000000000000000000000


;*** CSCR0 - Chip Select Control Register 0; 0xFFFFE808 ***
CSCR0:              .equ   $FFFFE808                                ;*** CSCR0 - Chip Select Control Register 0; 0xFFFFE808 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CSCR0_PS0:          .equ   6                                         ; Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 0
CSCR0_PS1:          .equ   7                                         ; Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 1
CSCR0_AA:           .equ   8                                         ; Auto-acknowledge enable. Determines the assertion of the internal transfer acknowledge for accesses specified by the chip select address. Note that if AA = 1 for a corresponding CSn and the external system asserts an external TA before the wait-state co...
CSCR0_MUX:          .equ   9                                         ; Multiplexed mode
CSCR0_WS0:          .equ   10                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR0_WS1:          .equ   11                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR0_WS2:          .equ   12                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR0_WS3:          .equ   13                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR0_WS4:          .equ   14                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR0_WS5:          .equ   15                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR0_WRAH0:        .equ   16                                        ; Write address hold or deselect, bit 0
CSCR0_WRAH1:        .equ   17                                        ; Write address hold or deselect, bit 1
CSCR0_RDAH0:        .equ   18                                        ; Read address hold or deselect, bit 0
CSCR0_RDAH1:        .equ   19                                        ; Read address hold or deselect, bit 1
CSCR0_ASET0:        .equ   20                                        ; Address setup, bit 0
CSCR0_ASET1:        .equ   21                                        ; Address setup, bit 1
; bit position masks
mCSCR0_PS0:         .equ   %01000000
mCSCR0_PS1:         .equ   %10000000
mCSCR0_AA:          .equ   %100000000
mCSCR0_MUX:         .equ   %1000000000
mCSCR0_WS0:         .equ   %10000000000
mCSCR0_WS1:         .equ   %100000000000
mCSCR0_WS2:         .equ   %1000000000000
mCSCR0_WS3:         .equ   %10000000000000
mCSCR0_WS4:         .equ   %100000000000000
mCSCR0_WS5:         .equ   %1000000000000000
mCSCR0_WRAH0:       .equ   %10000000000000000
mCSCR0_WRAH1:       .equ   %100000000000000000
mCSCR0_RDAH0:       .equ   %1000000000000000000
mCSCR0_RDAH1:       .equ   %10000000000000000000
mCSCR0_ASET0:       .equ   %100000000000000000000
mCSCR0_ASET1:       .equ   %1000000000000000000000


;*** CSAR1 - Chip Select Address Register 1; 0xFFFFE80C ***
CSAR1:              .equ   $FFFFE80C                                ;*** CSAR1 - Chip Select Address Register 1; 0xFFFFE80C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CSAR1_BA0:          .equ   16                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 0
CSAR1_BA1:          .equ   17                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 1
CSAR1_BA2:          .equ   18                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 2
CSAR1_BA3:          .equ   19                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 3
CSAR1_BA4:          .equ   20                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 4
CSAR1_BA5:          .equ   21                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 5
CSAR1_BA6:          .equ   22                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 6
CSAR1_BA7:          .equ   23                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 7
CSAR1_BA8:          .equ   24                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 8
CSAR1_BA9:          .equ   25                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 9
CSAR1_BA10:         .equ   26                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 10
CSAR1_BA11:         .equ   27                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 11
CSAR1_BA12:         .equ   28                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 12
CSAR1_BA13:         .equ   29                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 13
CSAR1_BA14:         .equ   30                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 14
CSAR1_BA15:         .equ   31                                        ; Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 15
; bit position masks
mCSAR1_BA0:         .equ   %10000000000000000
mCSAR1_BA1:         .equ   %100000000000000000
mCSAR1_BA2:         .equ   %1000000000000000000
mCSAR1_BA3:         .equ   %10000000000000000000
mCSAR1_BA4:         .equ   %100000000000000000000
mCSAR1_BA5:         .equ   %1000000000000000000000
mCSAR1_BA6:         .equ   %10000000000000000000000
mCSAR1_BA7:         .equ   %100000000000000000000000
mCSAR1_BA8:         .equ   %1000000000000000000000000
mCSAR1_BA9:         .equ   %10000000000000000000000000
mCSAR1_BA10:        .equ   %100000000000000000000000000
mCSAR1_BA11:        .equ   %1000000000000000000000000000
mCSAR1_BA12:        .equ   %10000000000000000000000000000
mCSAR1_BA13:        .equ   %100000000000000000000000000000
mCSAR1_BA14:        .equ   %1000000000000000000000000000000
mCSAR1_BA15:        .equ   %10000000000000000000000000000000


;*** CSMR1 - Chip Select Mask Register 1; 0xFFFFE810 ***
CSMR1:              .equ   $FFFFE810                                ;*** CSMR1 - Chip Select Mask Register 1; 0xFFFFE810 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CSMR1_V:            .equ   0                                         ; Valid bit. Indicates whether the corresponding CSAR, CSMR, and CSCR contents are valid. Programmed chip selects do not assert until V is set (except for CS0, which acts as the global chip select). Reset clears each CSMRn[V]
CSMR1_WP:           .equ   8                                         ; Write protect. Controls write accesses to the address range in the corresponding CSAR. Attempting to write to the range of addresses for which CSAR0[WP] = 1 results in the appropriate chip select not being selected. No exception occurs
CSMR1_BAM0:         .equ   16                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 0
CSMR1_BAM1:         .equ   17                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 1
CSMR1_BAM2:         .equ   18                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 2
CSMR1_BAM3:         .equ   19                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 3
CSMR1_BAM4:         .equ   20                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 4
CSMR1_BAM5:         .equ   21                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 5
CSMR1_BAM6:         .equ   22                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 6
CSMR1_BAM7:         .equ   23                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 7
CSMR1_BAM8:         .equ   24                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 8
CSMR1_BAM9:         .equ   25                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 9
CSMR1_BAM10:        .equ   26                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 10
CSMR1_BAM11:        .equ   27                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 11
CSMR1_BAM12:        .equ   28                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 12
CSMR1_BAM13:        .equ   29                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 13
CSMR1_BAM14:        .equ   30                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 14
CSMR1_BAM15:        .equ   31                                        ; Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 15
; bit position masks
mCSMR1_V:           .equ   %00000001
mCSMR1_WP:          .equ   %100000000
mCSMR1_BAM0:        .equ   %10000000000000000
mCSMR1_BAM1:        .equ   %100000000000000000
mCSMR1_BAM2:        .equ   %1000000000000000000
mCSMR1_BAM3:        .equ   %10000000000000000000
mCSMR1_BAM4:        .equ   %100000000000000000000
mCSMR1_BAM5:        .equ   %1000000000000000000000
mCSMR1_BAM6:        .equ   %10000000000000000000000
mCSMR1_BAM7:        .equ   %100000000000000000000000
mCSMR1_BAM8:        .equ   %1000000000000000000000000
mCSMR1_BAM9:        .equ   %10000000000000000000000000
mCSMR1_BAM10:       .equ   %100000000000000000000000000
mCSMR1_BAM11:       .equ   %1000000000000000000000000000
mCSMR1_BAM12:       .equ   %10000000000000000000000000000
mCSMR1_BAM13:       .equ   %100000000000000000000000000000
mCSMR1_BAM14:       .equ   %1000000000000000000000000000000
mCSMR1_BAM15:       .equ   %10000000000000000000000000000000


;*** CSCR1 - Chip Select Control Register 1; 0xFFFFE814 ***
CSCR1:              .equ   $FFFFE814                                ;*** CSCR1 - Chip Select Control Register 1; 0xFFFFE814 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CSCR1_PS0:          .equ   6                                         ; Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 0
CSCR1_PS1:          .equ   7                                         ; Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 1
CSCR1_AA:           .equ   8                                         ; Auto-acknowledge enable. Determines the assertion of the internal transfer acknowledge for accesses specified by the chip select address. Note that if AA = 1 for a corresponding CSn and the external system asserts an external TA before the wait-state co...
CSCR1_MUX:          .equ   9                                         ; Multiplexed mode
CSCR1_WS0:          .equ   10                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR1_WS1:          .equ   11                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR1_WS2:          .equ   12                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR1_WS3:          .equ   13                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR1_WS4:          .equ   14                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR1_WS5:          .equ   15                                        ; Wait states. The number of wait states inserted before an internal transfer acknowledge is generated (WS = 0 inserts zero wait states, WS = 0xF inserts 15 wait states). If AA = 0, TA must be asserted by the external system regardless of the number of wa...
CSCR1_WRAH0:        .equ   16                                        ; Write address hold or deselect, bit 0
CSCR1_WRAH1:        .equ   17                                        ; Write address hold or deselect, bit 1
CSCR1_RDAH0:        .equ   18                                        ; Read address hold or deselect, bit 0
CSCR1_RDAH1:        .equ   19                                        ; Read address hold or deselect, bit 1
CSCR1_ASET0:        .equ   20                                        ; Address setup, bit 0
CSCR1_ASET1:        .equ   21                                        ; Address setup, bit 1
; bit position masks
mCSCR1_PS0:         .equ   %01000000
mCSCR1_PS1:         .equ   %10000000
mCSCR1_AA:          .equ   %100000000
mCSCR1_MUX:         .equ   %1000000000
mCSCR1_WS0:         .equ   %10000000000
mCSCR1_WS1:         .equ   %100000000000
mCSCR1_WS2:         .equ   %1000000000000
mCSCR1_WS3:         .equ   %10000000000000
mCSCR1_WS4:         .equ   %100000000000000
mCSCR1_WS5:         .equ   %1000000000000000
mCSCR1_WRAH0:       .equ   %10000000000000000
mCSCR1_WRAH1:       .equ   %100000000000000000
mCSCR1_RDAH0:       .equ   %1000000000000000000
mCSCR1_RDAH1:       .equ   %10000000000000000000
mCSCR1_ASET0:       .equ   %100000000000000000000
mCSCR1_ASET1:       .equ   %1000000000000000000000


;*** INTC_ORMR - INTC OR Mask Register; 0xFFFFFFCD ***
INTC_ORMR:          .equ   $FFFFFFCD                                ;*** INTC_ORMR - INTC OR Mask Register; 0xFFFFFFCD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_ORMR_SCI3DO:   .equ   5                                         ; Disable (mask) SCI3_OR interrupt request
INTC_ORMR_FECDO:    .equ   7                                         ; Disable (mask) FEC_Other interrupt request
; bit position masks
mINTC_ORMR_SCI3DO:  .equ   %00100000
mINTC_ORMR_FECDO:   .equ   %10000000


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
INTC_PL6P7_REQN5:   .equ   5                                         ; Request number, bit 5
; bit position masks
mINTC_PL6P7_REQN0:  .equ   %00000001
mINTC_PL6P7_REQN1:  .equ   %00000010
mINTC_PL6P7_REQN2:  .equ   %00000100
mINTC_PL6P7_REQN3:  .equ   %00001000
mINTC_PL6P7_REQN4:  .equ   %00010000
mINTC_PL6P7_REQN5:  .equ   %00100000


;*** INTC_PL6P6 - INTC Programmable Level 6, Priority 6 Register; 0xFFFFFFD9 ***
INTC_PL6P6:         .equ   $FFFFFFD9                                ;*** INTC_PL6P6 - INTC Programmable Level 6, Priority 6 Register; 0xFFFFFFD9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTC_PL6P6_REQN0:   .equ   0                                         ; Request number, bit 0
INTC_PL6P6_REQN1:   .equ   1                                         ; Request number, bit 1
INTC_PL6P6_REQN2:   .equ   2                                         ; Request number, bit 2
INTC_PL6P6_REQN3:   .equ   3                                         ; Request number, bit 3
INTC_PL6P6_REQN4:   .equ   4                                         ; Request number, bit 4
INTC_PL6P6_REQN5:   .equ   5                                         ; Request number, bit 5
; bit position masks
mINTC_PL6P6_REQN0:  .equ   %00000001
mINTC_PL6P6_REQN1:  .equ   %00000010
mINTC_PL6P6_REQN2:  .equ   %00000100
mINTC_PL6P6_REQN3:  .equ   %00001000
mINTC_PL6P6_REQN4:  .equ   %00010000
mINTC_PL6P6_REQN5:  .equ   %00100000


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

; EOF
