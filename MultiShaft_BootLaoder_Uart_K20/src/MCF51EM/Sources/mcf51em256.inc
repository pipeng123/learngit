; Based on CPU DB MCF51EM256_100, version 3.00.000 (RegistersPrg V2.24)

; ###################################################################
;     Filename  : mcf51em256.inc
;     Processor : MCF51EM256CLL
;     FileFormat: V2.24
;     DataSheet : MCF51EM256RM Revision 3 10 Oct. 2008
;     Compiler  : CodeWarrior compiler
;     Date/Time : 27.11.2008, 19:01
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
VReserved66:        .equ  $00000108
VReserved67:        .equ  $0000010C
Vpdb:               .equ  $00000110
Vtpmch0:            .equ  $00000114
Vtpmch1:            .equ  $00000118
Vtpmovf:            .equ  $0000011C
VReserved72:        .equ  $00000120
Vmtim2:             .equ  $00000124
Vmtim3:             .equ  $00000128
Vmtim1:             .equ  $0000012C
Vadc4:              .equ  $00000130
Vadc3:              .equ  $00000134
Vadc2:              .equ  $00000138
Vadc1:              .equ  $0000013C
Vspi1:              .equ  $00000140
Vspi2:              .equ  $00000144
Vspi3:              .equ  $00000148
Vsci1err:           .equ  $0000014C
Vsci1rx:            .equ  $00000150
Vsci1tx:            .equ  $00000154
VReserved86:        .equ  $00000158
Vsci2err:           .equ  $0000015C
Vsci2rx:            .equ  $00000160
Vsci2tx:            .equ  $00000164
Vsci3err:           .equ  $00000168
Vsci3rx:            .equ  $0000016C
Vsci3tx:            .equ  $00000170
VReserved93:        .equ  $00000174
VReserved94:        .equ  $00000178
Viic:               .equ  $0000017C
Vcmp1:              .equ  $00000180
Vcmp2:              .equ  $00000184
VReserved98:        .equ  $00000188
Vkbi1:              .equ  $0000018C
Vkbi2:              .equ  $00000190
VReserved101:       .equ  $00000194
Vrtc:               .equ  $00000198
VL7swi:             .equ  $0000019C
VL6swi:             .equ  $000001A0
VL5swi:             .equ  $000001A4
VL4swi:             .equ  $000001A8
VL3swi:             .equ  $000001AC
VL2swi:             .equ  $000001B0
VL1swi:             .equ  $000001B4
Vlcd:               .equ  $000001B8
VReserved111:       .equ  $000001BC
Vftsr1:             .equ  $000001C0
Vftsr2:             .equ  $000001C4
VReserved114:       .equ  $000001C8
;


;*** NV1FTRIM - Nonvolatile ICS Fine Trim 1; 0x000003FE ***
NV1FTRIM:           .equ   $000003FE                                ;*** NV1FTRIM - Nonvolatile ICS Fine Trim 1; 0x000003FE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1FTRIM_FTRIM:     .equ   0                                         ; ICS Fine Trim
; bit position masks
mNV1FTRIM_FTRIM:    .equ   %00000001


;*** NV1ICSTRM - Nonvolatile ICS Trim Register 1; 0x000003FF ***
NV1ICSTRM:          .equ   $000003FF                                ;*** NV1ICSTRM - Nonvolatile ICS Trim Register 1; 0x000003FF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1ICSTRM_TRIM0:    .equ   0                                         ; ICS Trim Setting, bit 0
NV1ICSTRM_TRIM1:    .equ   1                                         ; ICS Trim Setting, bit 1
NV1ICSTRM_TRIM2:    .equ   2                                         ; ICS Trim Setting, bit 2
NV1ICSTRM_TRIM3:    .equ   3                                         ; ICS Trim Setting, bit 3
NV1ICSTRM_TRIM4:    .equ   4                                         ; ICS Trim Setting, bit 4
NV1ICSTRM_TRIM5:    .equ   5                                         ; ICS Trim Setting, bit 5
NV1ICSTRM_TRIM6:    .equ   6                                         ; ICS Trim Setting, bit 6
NV1ICSTRM_TRIM7:    .equ   7                                         ; ICS Trim Setting, bit 7
; bit position masks
mNV1ICSTRM_TRIM0:   .equ   %00000001
mNV1ICSTRM_TRIM1:   .equ   %00000010
mNV1ICSTRM_TRIM2:   .equ   %00000100
mNV1ICSTRM_TRIM3:   .equ   %00001000
mNV1ICSTRM_TRIM4:   .equ   %00010000
mNV1ICSTRM_TRIM5:   .equ   %00100000
mNV1ICSTRM_TRIM6:   .equ   %01000000
mNV1ICSTRM_TRIM7:   .equ   %10000000


;*** NV1BACKKEY0 - Backdoor Comparison Key 0; 0x00000400 ***
NV1BACKKEY0:        .equ   $00000400                                ;*** NV1BACKKEY0 - Backdoor Comparison Key 0; 0x00000400 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY0_KEY0:   .equ   0                                         ; Backdoor Comparison Key 0 Bits, bit 0
NV1BACKKEY0_KEY1:   .equ   1                                         ; Backdoor Comparison Key 0 Bits, bit 1
NV1BACKKEY0_KEY2:   .equ   2                                         ; Backdoor Comparison Key 0 Bits, bit 2
NV1BACKKEY0_KEY3:   .equ   3                                         ; Backdoor Comparison Key 0 Bits, bit 3
NV1BACKKEY0_KEY4:   .equ   4                                         ; Backdoor Comparison Key 0 Bits, bit 4
NV1BACKKEY0_KEY5:   .equ   5                                         ; Backdoor Comparison Key 0 Bits, bit 5
NV1BACKKEY0_KEY6:   .equ   6                                         ; Backdoor Comparison Key 0 Bits, bit 6
NV1BACKKEY0_KEY7:   .equ   7                                         ; Backdoor Comparison Key 0 Bits, bit 7
; bit position masks
mNV1BACKKEY0_KEY0:  .equ   %00000001
mNV1BACKKEY0_KEY1:  .equ   %00000010
mNV1BACKKEY0_KEY2:  .equ   %00000100
mNV1BACKKEY0_KEY3:  .equ   %00001000
mNV1BACKKEY0_KEY4:  .equ   %00010000
mNV1BACKKEY0_KEY5:  .equ   %00100000
mNV1BACKKEY0_KEY6:  .equ   %01000000
mNV1BACKKEY0_KEY7:  .equ   %10000000


;*** NV1BACKKEY1 - Backdoor Comparison Key 1; 0x00000401 ***
NV1BACKKEY1:        .equ   $00000401                                ;*** NV1BACKKEY1 - Backdoor Comparison Key 1; 0x00000401 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY1_KEY0:   .equ   0                                         ; Backdoor Comparison Key 1 Bits, bit 0
NV1BACKKEY1_KEY1:   .equ   1                                         ; Backdoor Comparison Key 1 Bits, bit 1
NV1BACKKEY1_KEY2:   .equ   2                                         ; Backdoor Comparison Key 1 Bits, bit 2
NV1BACKKEY1_KEY3:   .equ   3                                         ; Backdoor Comparison Key 1 Bits, bit 3
NV1BACKKEY1_KEY4:   .equ   4                                         ; Backdoor Comparison Key 1 Bits, bit 4
NV1BACKKEY1_KEY5:   .equ   5                                         ; Backdoor Comparison Key 1 Bits, bit 5
NV1BACKKEY1_KEY6:   .equ   6                                         ; Backdoor Comparison Key 1 Bits, bit 6
NV1BACKKEY1_KEY7:   .equ   7                                         ; Backdoor Comparison Key 1 Bits, bit 7
; bit position masks
mNV1BACKKEY1_KEY0:  .equ   %00000001
mNV1BACKKEY1_KEY1:  .equ   %00000010
mNV1BACKKEY1_KEY2:  .equ   %00000100
mNV1BACKKEY1_KEY3:  .equ   %00001000
mNV1BACKKEY1_KEY4:  .equ   %00010000
mNV1BACKKEY1_KEY5:  .equ   %00100000
mNV1BACKKEY1_KEY6:  .equ   %01000000
mNV1BACKKEY1_KEY7:  .equ   %10000000


;*** NV1BACKKEY2 - Backdoor Comparison Key 2; 0x00000402 ***
NV1BACKKEY2:        .equ   $00000402                                ;*** NV1BACKKEY2 - Backdoor Comparison Key 2; 0x00000402 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY2_KEY0:   .equ   0                                         ; Backdoor Comparison Key 2 Bits, bit 0
NV1BACKKEY2_KEY1:   .equ   1                                         ; Backdoor Comparison Key 2 Bits, bit 1
NV1BACKKEY2_KEY2:   .equ   2                                         ; Backdoor Comparison Key 2 Bits, bit 2
NV1BACKKEY2_KEY3:   .equ   3                                         ; Backdoor Comparison Key 2 Bits, bit 3
NV1BACKKEY2_KEY4:   .equ   4                                         ; Backdoor Comparison Key 2 Bits, bit 4
NV1BACKKEY2_KEY5:   .equ   5                                         ; Backdoor Comparison Key 2 Bits, bit 5
NV1BACKKEY2_KEY6:   .equ   6                                         ; Backdoor Comparison Key 2 Bits, bit 6
NV1BACKKEY2_KEY7:   .equ   7                                         ; Backdoor Comparison Key 2 Bits, bit 7
; bit position masks
mNV1BACKKEY2_KEY0:  .equ   %00000001
mNV1BACKKEY2_KEY1:  .equ   %00000010
mNV1BACKKEY2_KEY2:  .equ   %00000100
mNV1BACKKEY2_KEY3:  .equ   %00001000
mNV1BACKKEY2_KEY4:  .equ   %00010000
mNV1BACKKEY2_KEY5:  .equ   %00100000
mNV1BACKKEY2_KEY6:  .equ   %01000000
mNV1BACKKEY2_KEY7:  .equ   %10000000


;*** NV1BACKKEY3 - Backdoor Comparison Key 3; 0x00000403 ***
NV1BACKKEY3:        .equ   $00000403                                ;*** NV1BACKKEY3 - Backdoor Comparison Key 3; 0x00000403 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY3_KEY0:   .equ   0                                         ; Backdoor Comparison Key 3 Bits, bit 0
NV1BACKKEY3_KEY1:   .equ   1                                         ; Backdoor Comparison Key 3 Bits, bit 1
NV1BACKKEY3_KEY2:   .equ   2                                         ; Backdoor Comparison Key 3 Bits, bit 2
NV1BACKKEY3_KEY3:   .equ   3                                         ; Backdoor Comparison Key 3 Bits, bit 3
NV1BACKKEY3_KEY4:   .equ   4                                         ; Backdoor Comparison Key 3 Bits, bit 4
NV1BACKKEY3_KEY5:   .equ   5                                         ; Backdoor Comparison Key 3 Bits, bit 5
NV1BACKKEY3_KEY6:   .equ   6                                         ; Backdoor Comparison Key 3 Bits, bit 6
NV1BACKKEY3_KEY7:   .equ   7                                         ; Backdoor Comparison Key 3 Bits, bit 7
; bit position masks
mNV1BACKKEY3_KEY0:  .equ   %00000001
mNV1BACKKEY3_KEY1:  .equ   %00000010
mNV1BACKKEY3_KEY2:  .equ   %00000100
mNV1BACKKEY3_KEY3:  .equ   %00001000
mNV1BACKKEY3_KEY4:  .equ   %00010000
mNV1BACKKEY3_KEY5:  .equ   %00100000
mNV1BACKKEY3_KEY6:  .equ   %01000000
mNV1BACKKEY3_KEY7:  .equ   %10000000


;*** NV1BACKKEY4 - Backdoor Comparison Key 4; 0x00000404 ***
NV1BACKKEY4:        .equ   $00000404                                ;*** NV1BACKKEY4 - Backdoor Comparison Key 4; 0x00000404 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY4_KEY0:   .equ   0                                         ; Backdoor Comparison Key 4 Bits, bit 0
NV1BACKKEY4_KEY1:   .equ   1                                         ; Backdoor Comparison Key 4 Bits, bit 1
NV1BACKKEY4_KEY2:   .equ   2                                         ; Backdoor Comparison Key 4 Bits, bit 2
NV1BACKKEY4_KEY3:   .equ   3                                         ; Backdoor Comparison Key 4 Bits, bit 3
NV1BACKKEY4_KEY4:   .equ   4                                         ; Backdoor Comparison Key 4 Bits, bit 4
NV1BACKKEY4_KEY5:   .equ   5                                         ; Backdoor Comparison Key 4 Bits, bit 5
NV1BACKKEY4_KEY6:   .equ   6                                         ; Backdoor Comparison Key 4 Bits, bit 6
NV1BACKKEY4_KEY7:   .equ   7                                         ; Backdoor Comparison Key 4 Bits, bit 7
; bit position masks
mNV1BACKKEY4_KEY0:  .equ   %00000001
mNV1BACKKEY4_KEY1:  .equ   %00000010
mNV1BACKKEY4_KEY2:  .equ   %00000100
mNV1BACKKEY4_KEY3:  .equ   %00001000
mNV1BACKKEY4_KEY4:  .equ   %00010000
mNV1BACKKEY4_KEY5:  .equ   %00100000
mNV1BACKKEY4_KEY6:  .equ   %01000000
mNV1BACKKEY4_KEY7:  .equ   %10000000


;*** NV1BACKKEY5 - Backdoor Comparison Key 5; 0x00000405 ***
NV1BACKKEY5:        .equ   $00000405                                ;*** NV1BACKKEY5 - Backdoor Comparison Key 5; 0x00000405 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY5_KEY0:   .equ   0                                         ; Backdoor Comparison Key 5 Bits, bit 0
NV1BACKKEY5_KEY1:   .equ   1                                         ; Backdoor Comparison Key 5 Bits, bit 1
NV1BACKKEY5_KEY2:   .equ   2                                         ; Backdoor Comparison Key 5 Bits, bit 2
NV1BACKKEY5_KEY3:   .equ   3                                         ; Backdoor Comparison Key 5 Bits, bit 3
NV1BACKKEY5_KEY4:   .equ   4                                         ; Backdoor Comparison Key 5 Bits, bit 4
NV1BACKKEY5_KEY5:   .equ   5                                         ; Backdoor Comparison Key 5 Bits, bit 5
NV1BACKKEY5_KEY6:   .equ   6                                         ; Backdoor Comparison Key 5 Bits, bit 6
NV1BACKKEY5_KEY7:   .equ   7                                         ; Backdoor Comparison Key 5 Bits, bit 7
; bit position masks
mNV1BACKKEY5_KEY0:  .equ   %00000001
mNV1BACKKEY5_KEY1:  .equ   %00000010
mNV1BACKKEY5_KEY2:  .equ   %00000100
mNV1BACKKEY5_KEY3:  .equ   %00001000
mNV1BACKKEY5_KEY4:  .equ   %00010000
mNV1BACKKEY5_KEY5:  .equ   %00100000
mNV1BACKKEY5_KEY6:  .equ   %01000000
mNV1BACKKEY5_KEY7:  .equ   %10000000


;*** NV1BACKKEY6 - Backdoor Comparison Key 6; 0x00000406 ***
NV1BACKKEY6:        .equ   $00000406                                ;*** NV1BACKKEY6 - Backdoor Comparison Key 6; 0x00000406 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY6_KEY0:   .equ   0                                         ; Backdoor Comparison Key 6 Bits, bit 0
NV1BACKKEY6_KEY1:   .equ   1                                         ; Backdoor Comparison Key 6 Bits, bit 1
NV1BACKKEY6_KEY2:   .equ   2                                         ; Backdoor Comparison Key 6 Bits, bit 2
NV1BACKKEY6_KEY3:   .equ   3                                         ; Backdoor Comparison Key 6 Bits, bit 3
NV1BACKKEY6_KEY4:   .equ   4                                         ; Backdoor Comparison Key 6 Bits, bit 4
NV1BACKKEY6_KEY5:   .equ   5                                         ; Backdoor Comparison Key 6 Bits, bit 5
NV1BACKKEY6_KEY6:   .equ   6                                         ; Backdoor Comparison Key 6 Bits, bit 6
NV1BACKKEY6_KEY7:   .equ   7                                         ; Backdoor Comparison Key 6 Bits, bit 7
; bit position masks
mNV1BACKKEY6_KEY0:  .equ   %00000001
mNV1BACKKEY6_KEY1:  .equ   %00000010
mNV1BACKKEY6_KEY2:  .equ   %00000100
mNV1BACKKEY6_KEY3:  .equ   %00001000
mNV1BACKKEY6_KEY4:  .equ   %00010000
mNV1BACKKEY6_KEY5:  .equ   %00100000
mNV1BACKKEY6_KEY6:  .equ   %01000000
mNV1BACKKEY6_KEY7:  .equ   %10000000


;*** NV1BACKKEY7 - Backdoor Comparison Key 7; 0x00000407 ***
NV1BACKKEY7:        .equ   $00000407                                ;*** NV1BACKKEY7 - Backdoor Comparison Key 7; 0x00000407 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1BACKKEY7_KEY0:   .equ   0                                         ; Backdoor Comparison Key 7 Bits, bit 0
NV1BACKKEY7_KEY1:   .equ   1                                         ; Backdoor Comparison Key 7 Bits, bit 1
NV1BACKKEY7_KEY2:   .equ   2                                         ; Backdoor Comparison Key 7 Bits, bit 2
NV1BACKKEY7_KEY3:   .equ   3                                         ; Backdoor Comparison Key 7 Bits, bit 3
NV1BACKKEY7_KEY4:   .equ   4                                         ; Backdoor Comparison Key 7 Bits, bit 4
NV1BACKKEY7_KEY5:   .equ   5                                         ; Backdoor Comparison Key 7 Bits, bit 5
NV1BACKKEY7_KEY6:   .equ   6                                         ; Backdoor Comparison Key 7 Bits, bit 6
NV1BACKKEY7_KEY7:   .equ   7                                         ; Backdoor Comparison Key 7 Bits, bit 7
; bit position masks
mNV1BACKKEY7_KEY0:  .equ   %00000001
mNV1BACKKEY7_KEY1:  .equ   %00000010
mNV1BACKKEY7_KEY2:  .equ   %00000100
mNV1BACKKEY7_KEY3:  .equ   %00001000
mNV1BACKKEY7_KEY4:  .equ   %00010000
mNV1BACKKEY7_KEY5:  .equ   %00100000
mNV1BACKKEY7_KEY6:  .equ   %01000000
mNV1BACKKEY7_KEY7:  .equ   %10000000


;*** NV1PROT - Nonvolatile Flash Protection Register; 0x0000040D ***
NV1PROT:            .equ   $0000040D                                ;*** NV1PROT - Nonvolatile Flash Protection Register; 0x0000040D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1PROT_FPOPEN:     .equ   0                                         ; Flash Protection Open
NV1PROT_FPS0:       .equ   1                                         ; Flash Protection Size, bit 0
NV1PROT_FPS1:       .equ   2                                         ; Flash Protection Size, bit 1
NV1PROT_FPS2:       .equ   3                                         ; Flash Protection Size, bit 2
NV1PROT_FPS3:       .equ   4                                         ; Flash Protection Size, bit 3
NV1PROT_FPS4:       .equ   5                                         ; Flash Protection Size, bit 4
NV1PROT_FPS5:       .equ   6                                         ; Flash Protection Size, bit 5
NV1PROT_FPS6:       .equ   7                                         ; Flash Protection Size, bit 6
; bit position masks
mNV1PROT_FPOPEN:    .equ   %00000001
mNV1PROT_FPS0:      .equ   %00000010
mNV1PROT_FPS1:      .equ   %00000100
mNV1PROT_FPS2:      .equ   %00001000
mNV1PROT_FPS3:      .equ   %00010000
mNV1PROT_FPS4:      .equ   %00100000
mNV1PROT_FPS5:      .equ   %01000000
mNV1PROT_FPS6:      .equ   %10000000


;*** NV1OPT - Nonvolatile Flash Options Register; 0x0000040F ***
NV1OPT:             .equ   $0000040F                                ;*** NV1OPT - Nonvolatile Flash Options Register; 0x0000040F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV1OPT_SEC0:        .equ   0                                         ; Flash Security Bit 0
NV1OPT_SEC1:        .equ   1                                         ; Flash Security Bit 1
NV1OPT_KEYEN0:      .equ   6                                         ; Backdoor Key Security Enable Bit 0
NV1OPT_KEYEN1:      .equ   7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mNV1OPT_SEC0:       .equ   %00000001
mNV1OPT_SEC1:       .equ   %00000010
mNV1OPT_KEYEN0:     .equ   %01000000
mNV1OPT_KEYEN1:     .equ   %10000000


;*** NV2FTRIM - Nonvolatile ICS Fine Trim 2; 0x000203FE ***
NV2FTRIM:           .equ   $000203FE                                ;*** NV2FTRIM - Nonvolatile ICS Fine Trim 2; 0x000203FE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2FTRIM_FTRIM:     .equ   0                                         ; ICS Fine Trim
; bit position masks
mNV2FTRIM_FTRIM:    .equ   %00000001


;*** NV2ICSTRM - Nonvolatile ICS Trim Register 2; 0x000203FF ***
NV2ICSTRM:          .equ   $000203FF                                ;*** NV2ICSTRM - Nonvolatile ICS Trim Register 2; 0x000203FF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2ICSTRM_TRIM0:    .equ   0                                         ; ICS Trim Setting, bit 0
NV2ICSTRM_TRIM1:    .equ   1                                         ; ICS Trim Setting, bit 1
NV2ICSTRM_TRIM2:    .equ   2                                         ; ICS Trim Setting, bit 2
NV2ICSTRM_TRIM3:    .equ   3                                         ; ICS Trim Setting, bit 3
NV2ICSTRM_TRIM4:    .equ   4                                         ; ICS Trim Setting, bit 4
NV2ICSTRM_TRIM5:    .equ   5                                         ; ICS Trim Setting, bit 5
NV2ICSTRM_TRIM6:    .equ   6                                         ; ICS Trim Setting, bit 6
NV2ICSTRM_TRIM7:    .equ   7                                         ; ICS Trim Setting, bit 7
; bit position masks
mNV2ICSTRM_TRIM0:   .equ   %00000001
mNV2ICSTRM_TRIM1:   .equ   %00000010
mNV2ICSTRM_TRIM2:   .equ   %00000100
mNV2ICSTRM_TRIM3:   .equ   %00001000
mNV2ICSTRM_TRIM4:   .equ   %00010000
mNV2ICSTRM_TRIM5:   .equ   %00100000
mNV2ICSTRM_TRIM6:   .equ   %01000000
mNV2ICSTRM_TRIM7:   .equ   %10000000


;*** NV2BACKKEY0 - Backdoor Comparison Key 0; 0x00020400 ***
NV2BACKKEY0:        .equ   $00020400                                ;*** NV2BACKKEY0 - Backdoor Comparison Key 0; 0x00020400 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY0_KEY0:   .equ   0                                         ; Backdoor Comparison Key 0 Bits, bit 0
NV2BACKKEY0_KEY1:   .equ   1                                         ; Backdoor Comparison Key 0 Bits, bit 1
NV2BACKKEY0_KEY2:   .equ   2                                         ; Backdoor Comparison Key 0 Bits, bit 2
NV2BACKKEY0_KEY3:   .equ   3                                         ; Backdoor Comparison Key 0 Bits, bit 3
NV2BACKKEY0_KEY4:   .equ   4                                         ; Backdoor Comparison Key 0 Bits, bit 4
NV2BACKKEY0_KEY5:   .equ   5                                         ; Backdoor Comparison Key 0 Bits, bit 5
NV2BACKKEY0_KEY6:   .equ   6                                         ; Backdoor Comparison Key 0 Bits, bit 6
NV2BACKKEY0_KEY7:   .equ   7                                         ; Backdoor Comparison Key 0 Bits, bit 7
; bit position masks
mNV2BACKKEY0_KEY0:  .equ   %00000001
mNV2BACKKEY0_KEY1:  .equ   %00000010
mNV2BACKKEY0_KEY2:  .equ   %00000100
mNV2BACKKEY0_KEY3:  .equ   %00001000
mNV2BACKKEY0_KEY4:  .equ   %00010000
mNV2BACKKEY0_KEY5:  .equ   %00100000
mNV2BACKKEY0_KEY6:  .equ   %01000000
mNV2BACKKEY0_KEY7:  .equ   %10000000


;*** NV2BACKKEY1 - Backdoor Comparison Key 1; 0x00020401 ***
NV2BACKKEY1:        .equ   $00020401                                ;*** NV2BACKKEY1 - Backdoor Comparison Key 1; 0x00020401 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY1_KEY0:   .equ   0                                         ; Backdoor Comparison Key 1 Bits, bit 0
NV2BACKKEY1_KEY1:   .equ   1                                         ; Backdoor Comparison Key 1 Bits, bit 1
NV2BACKKEY1_KEY2:   .equ   2                                         ; Backdoor Comparison Key 1 Bits, bit 2
NV2BACKKEY1_KEY3:   .equ   3                                         ; Backdoor Comparison Key 1 Bits, bit 3
NV2BACKKEY1_KEY4:   .equ   4                                         ; Backdoor Comparison Key 1 Bits, bit 4
NV2BACKKEY1_KEY5:   .equ   5                                         ; Backdoor Comparison Key 1 Bits, bit 5
NV2BACKKEY1_KEY6:   .equ   6                                         ; Backdoor Comparison Key 1 Bits, bit 6
NV2BACKKEY1_KEY7:   .equ   7                                         ; Backdoor Comparison Key 1 Bits, bit 7
; bit position masks
mNV2BACKKEY1_KEY0:  .equ   %00000001
mNV2BACKKEY1_KEY1:  .equ   %00000010
mNV2BACKKEY1_KEY2:  .equ   %00000100
mNV2BACKKEY1_KEY3:  .equ   %00001000
mNV2BACKKEY1_KEY4:  .equ   %00010000
mNV2BACKKEY1_KEY5:  .equ   %00100000
mNV2BACKKEY1_KEY6:  .equ   %01000000
mNV2BACKKEY1_KEY7:  .equ   %10000000


;*** NV2BACKKEY2 - Backdoor Comparison Key 2; 0x00020402 ***
NV2BACKKEY2:        .equ   $00020402                                ;*** NV2BACKKEY2 - Backdoor Comparison Key 2; 0x00020402 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY2_KEY0:   .equ   0                                         ; Backdoor Comparison Key 2 Bits, bit 0
NV2BACKKEY2_KEY1:   .equ   1                                         ; Backdoor Comparison Key 2 Bits, bit 1
NV2BACKKEY2_KEY2:   .equ   2                                         ; Backdoor Comparison Key 2 Bits, bit 2
NV2BACKKEY2_KEY3:   .equ   3                                         ; Backdoor Comparison Key 2 Bits, bit 3
NV2BACKKEY2_KEY4:   .equ   4                                         ; Backdoor Comparison Key 2 Bits, bit 4
NV2BACKKEY2_KEY5:   .equ   5                                         ; Backdoor Comparison Key 2 Bits, bit 5
NV2BACKKEY2_KEY6:   .equ   6                                         ; Backdoor Comparison Key 2 Bits, bit 6
NV2BACKKEY2_KEY7:   .equ   7                                         ; Backdoor Comparison Key 2 Bits, bit 7
; bit position masks
mNV2BACKKEY2_KEY0:  .equ   %00000001
mNV2BACKKEY2_KEY1:  .equ   %00000010
mNV2BACKKEY2_KEY2:  .equ   %00000100
mNV2BACKKEY2_KEY3:  .equ   %00001000
mNV2BACKKEY2_KEY4:  .equ   %00010000
mNV2BACKKEY2_KEY5:  .equ   %00100000
mNV2BACKKEY2_KEY6:  .equ   %01000000
mNV2BACKKEY2_KEY7:  .equ   %10000000


;*** NV2BACKKEY3 - Backdoor Comparison Key 3; 0x00020403 ***
NV2BACKKEY3:        .equ   $00020403                                ;*** NV2BACKKEY3 - Backdoor Comparison Key 3; 0x00020403 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY3_KEY0:   .equ   0                                         ; Backdoor Comparison Key 3 Bits, bit 0
NV2BACKKEY3_KEY1:   .equ   1                                         ; Backdoor Comparison Key 3 Bits, bit 1
NV2BACKKEY3_KEY2:   .equ   2                                         ; Backdoor Comparison Key 3 Bits, bit 2
NV2BACKKEY3_KEY3:   .equ   3                                         ; Backdoor Comparison Key 3 Bits, bit 3
NV2BACKKEY3_KEY4:   .equ   4                                         ; Backdoor Comparison Key 3 Bits, bit 4
NV2BACKKEY3_KEY5:   .equ   5                                         ; Backdoor Comparison Key 3 Bits, bit 5
NV2BACKKEY3_KEY6:   .equ   6                                         ; Backdoor Comparison Key 3 Bits, bit 6
NV2BACKKEY3_KEY7:   .equ   7                                         ; Backdoor Comparison Key 3 Bits, bit 7
; bit position masks
mNV2BACKKEY3_KEY0:  .equ   %00000001
mNV2BACKKEY3_KEY1:  .equ   %00000010
mNV2BACKKEY3_KEY2:  .equ   %00000100
mNV2BACKKEY3_KEY3:  .equ   %00001000
mNV2BACKKEY3_KEY4:  .equ   %00010000
mNV2BACKKEY3_KEY5:  .equ   %00100000
mNV2BACKKEY3_KEY6:  .equ   %01000000
mNV2BACKKEY3_KEY7:  .equ   %10000000


;*** NV2BACKKEY4 - Backdoor Comparison Key 4; 0x00020404 ***
NV2BACKKEY4:        .equ   $00020404                                ;*** NV2BACKKEY4 - Backdoor Comparison Key 4; 0x00020404 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY4_KEY0:   .equ   0                                         ; Backdoor Comparison Key 4 Bits, bit 0
NV2BACKKEY4_KEY1:   .equ   1                                         ; Backdoor Comparison Key 4 Bits, bit 1
NV2BACKKEY4_KEY2:   .equ   2                                         ; Backdoor Comparison Key 4 Bits, bit 2
NV2BACKKEY4_KEY3:   .equ   3                                         ; Backdoor Comparison Key 4 Bits, bit 3
NV2BACKKEY4_KEY4:   .equ   4                                         ; Backdoor Comparison Key 4 Bits, bit 4
NV2BACKKEY4_KEY5:   .equ   5                                         ; Backdoor Comparison Key 4 Bits, bit 5
NV2BACKKEY4_KEY6:   .equ   6                                         ; Backdoor Comparison Key 4 Bits, bit 6
NV2BACKKEY4_KEY7:   .equ   7                                         ; Backdoor Comparison Key 4 Bits, bit 7
; bit position masks
mNV2BACKKEY4_KEY0:  .equ   %00000001
mNV2BACKKEY4_KEY1:  .equ   %00000010
mNV2BACKKEY4_KEY2:  .equ   %00000100
mNV2BACKKEY4_KEY3:  .equ   %00001000
mNV2BACKKEY4_KEY4:  .equ   %00010000
mNV2BACKKEY4_KEY5:  .equ   %00100000
mNV2BACKKEY4_KEY6:  .equ   %01000000
mNV2BACKKEY4_KEY7:  .equ   %10000000


;*** NV2BACKKEY5 - Backdoor Comparison Key 5; 0x00020405 ***
NV2BACKKEY5:        .equ   $00020405                                ;*** NV2BACKKEY5 - Backdoor Comparison Key 5; 0x00020405 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY5_KEY0:   .equ   0                                         ; Backdoor Comparison Key 5 Bits, bit 0
NV2BACKKEY5_KEY1:   .equ   1                                         ; Backdoor Comparison Key 5 Bits, bit 1
NV2BACKKEY5_KEY2:   .equ   2                                         ; Backdoor Comparison Key 5 Bits, bit 2
NV2BACKKEY5_KEY3:   .equ   3                                         ; Backdoor Comparison Key 5 Bits, bit 3
NV2BACKKEY5_KEY4:   .equ   4                                         ; Backdoor Comparison Key 5 Bits, bit 4
NV2BACKKEY5_KEY5:   .equ   5                                         ; Backdoor Comparison Key 5 Bits, bit 5
NV2BACKKEY5_KEY6:   .equ   6                                         ; Backdoor Comparison Key 5 Bits, bit 6
NV2BACKKEY5_KEY7:   .equ   7                                         ; Backdoor Comparison Key 5 Bits, bit 7
; bit position masks
mNV2BACKKEY5_KEY0:  .equ   %00000001
mNV2BACKKEY5_KEY1:  .equ   %00000010
mNV2BACKKEY5_KEY2:  .equ   %00000100
mNV2BACKKEY5_KEY3:  .equ   %00001000
mNV2BACKKEY5_KEY4:  .equ   %00010000
mNV2BACKKEY5_KEY5:  .equ   %00100000
mNV2BACKKEY5_KEY6:  .equ   %01000000
mNV2BACKKEY5_KEY7:  .equ   %10000000


;*** NV2BACKKEY6 - Backdoor Comparison Key 6; 0x00020406 ***
NV2BACKKEY6:        .equ   $00020406                                ;*** NV2BACKKEY6 - Backdoor Comparison Key 6; 0x00020406 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY6_KEY0:   .equ   0                                         ; Backdoor Comparison Key 6 Bits, bit 0
NV2BACKKEY6_KEY1:   .equ   1                                         ; Backdoor Comparison Key 6 Bits, bit 1
NV2BACKKEY6_KEY2:   .equ   2                                         ; Backdoor Comparison Key 6 Bits, bit 2
NV2BACKKEY6_KEY3:   .equ   3                                         ; Backdoor Comparison Key 6 Bits, bit 3
NV2BACKKEY6_KEY4:   .equ   4                                         ; Backdoor Comparison Key 6 Bits, bit 4
NV2BACKKEY6_KEY5:   .equ   5                                         ; Backdoor Comparison Key 6 Bits, bit 5
NV2BACKKEY6_KEY6:   .equ   6                                         ; Backdoor Comparison Key 6 Bits, bit 6
NV2BACKKEY6_KEY7:   .equ   7                                         ; Backdoor Comparison Key 6 Bits, bit 7
; bit position masks
mNV2BACKKEY6_KEY0:  .equ   %00000001
mNV2BACKKEY6_KEY1:  .equ   %00000010
mNV2BACKKEY6_KEY2:  .equ   %00000100
mNV2BACKKEY6_KEY3:  .equ   %00001000
mNV2BACKKEY6_KEY4:  .equ   %00010000
mNV2BACKKEY6_KEY5:  .equ   %00100000
mNV2BACKKEY6_KEY6:  .equ   %01000000
mNV2BACKKEY6_KEY7:  .equ   %10000000


;*** NV2BACKKEY7 - Backdoor Comparison Key 7; 0x00020407 ***
NV2BACKKEY7:        .equ   $00020407                                ;*** NV2BACKKEY7 - Backdoor Comparison Key 7; 0x00020407 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2BACKKEY7_KEY0:   .equ   0                                         ; Backdoor Comparison Key 7 Bits, bit 0
NV2BACKKEY7_KEY1:   .equ   1                                         ; Backdoor Comparison Key 7 Bits, bit 1
NV2BACKKEY7_KEY2:   .equ   2                                         ; Backdoor Comparison Key 7 Bits, bit 2
NV2BACKKEY7_KEY3:   .equ   3                                         ; Backdoor Comparison Key 7 Bits, bit 3
NV2BACKKEY7_KEY4:   .equ   4                                         ; Backdoor Comparison Key 7 Bits, bit 4
NV2BACKKEY7_KEY5:   .equ   5                                         ; Backdoor Comparison Key 7 Bits, bit 5
NV2BACKKEY7_KEY6:   .equ   6                                         ; Backdoor Comparison Key 7 Bits, bit 6
NV2BACKKEY7_KEY7:   .equ   7                                         ; Backdoor Comparison Key 7 Bits, bit 7
; bit position masks
mNV2BACKKEY7_KEY0:  .equ   %00000001
mNV2BACKKEY7_KEY1:  .equ   %00000010
mNV2BACKKEY7_KEY2:  .equ   %00000100
mNV2BACKKEY7_KEY3:  .equ   %00001000
mNV2BACKKEY7_KEY4:  .equ   %00010000
mNV2BACKKEY7_KEY5:  .equ   %00100000
mNV2BACKKEY7_KEY6:  .equ   %01000000
mNV2BACKKEY7_KEY7:  .equ   %10000000


;*** NV2PROT - Nonvolatile Flash Protection Register; 0x0002040D ***
NV2PROT:            .equ   $0002040D                                ;*** NV2PROT - Nonvolatile Flash Protection Register; 0x0002040D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2PROT_FPOPEN:     .equ   0                                         ; Flash Protection Open
NV2PROT_FPS0:       .equ   1                                         ; Flash Protection Size, bit 0
NV2PROT_FPS1:       .equ   2                                         ; Flash Protection Size, bit 1
NV2PROT_FPS2:       .equ   3                                         ; Flash Protection Size, bit 2
NV2PROT_FPS3:       .equ   4                                         ; Flash Protection Size, bit 3
NV2PROT_FPS4:       .equ   5                                         ; Flash Protection Size, bit 4
NV2PROT_FPS5:       .equ   6                                         ; Flash Protection Size, bit 5
NV2PROT_FPS6:       .equ   7                                         ; Flash Protection Size, bit 6
; bit position masks
mNV2PROT_FPOPEN:    .equ   %00000001
mNV2PROT_FPS0:      .equ   %00000010
mNV2PROT_FPS1:      .equ   %00000100
mNV2PROT_FPS2:      .equ   %00001000
mNV2PROT_FPS3:      .equ   %00010000
mNV2PROT_FPS4:      .equ   %00100000
mNV2PROT_FPS5:      .equ   %01000000
mNV2PROT_FPS6:      .equ   %10000000


;*** NV2OPT - Nonvolatile Flash Options Register; 0x0002040F ***
NV2OPT:             .equ   $0002040F                                ;*** NV2OPT - Nonvolatile Flash Options Register; 0x0002040F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV2OPT_SEC0:        .equ   0                                         ; Flash Security Bit 0
NV2OPT_SEC1:        .equ   1                                         ; Flash Security Bit 1
NV2OPT_KEYEN0:      .equ   6                                         ; Backdoor Key Security Enable Bit 0
NV2OPT_KEYEN1:      .equ   7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mNV2OPT_SEC0:       .equ   %00000001
mNV2OPT_SEC1:       .equ   %00000010
mNV2OPT_KEYEN0:     .equ   %01000000
mNV2OPT_KEYEN1:     .equ   %10000000


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


;*** PTASET - Port A Data Set Register; 0xFFFF8002 ***
PTASET:             .equ   $FFFF8002                                ;*** PTASET - Port A Data Set Register; 0xFFFF8002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASET_PTASET0:     .equ   0                                         ; Data Set for Port A Bit 0
PTASET_PTASET1:     .equ   1                                         ; Data Set for Port A Bit 1
PTASET_PTASET2:     .equ   2                                         ; Data Set for Port A Bit 2
PTASET_PTASET3:     .equ   3                                         ; Data Set for Port A Bit 3
PTASET_PTASET4:     .equ   4                                         ; Data Set for Port A Bit 4
PTASET_PTASET5:     .equ   5                                         ; Data Set for Port A Bit 5
PTASET_PTASET6:     .equ   6                                         ; Data Set for Port A Bit 6
PTASET_PTASET7:     .equ   7                                         ; Data Set for Port A Bit 7
; bit position masks
mPTASET_PTASET0:    .equ   %00000001
mPTASET_PTASET1:    .equ   %00000010
mPTASET_PTASET2:    .equ   %00000100
mPTASET_PTASET3:    .equ   %00001000
mPTASET_PTASET4:    .equ   %00010000
mPTASET_PTASET5:    .equ   %00100000
mPTASET_PTASET6:    .equ   %01000000
mPTASET_PTASET7:    .equ   %10000000


;*** PTACLR - Port A Data Clear Register; 0xFFFF8003 ***
PTACLR:             .equ   $FFFF8003                                ;*** PTACLR - Port A Data Clear Register; 0xFFFF8003 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTACLR_PTACLR0:     .equ   0                                         ; Data Clear for Port A Bit 0
PTACLR_PTACLR1:     .equ   1                                         ; Data Clear for Port A Bit 1
PTACLR_PTACLR2:     .equ   2                                         ; Data Clear for Port A Bit 2
PTACLR_PTACLR3:     .equ   3                                         ; Data Clear for Port A Bit 3
PTACLR_PTACLR4:     .equ   4                                         ; Data Clear for Port A Bit 4
PTACLR_PTACLR5:     .equ   5                                         ; Data Clear for Port A Bit 5
PTACLR_PTACLR6:     .equ   6                                         ; Data Clear for Port A Bit 6
PTACLR_PTACLR7:     .equ   7                                         ; Data Clear for Port A Bit 7
; bit position masks
mPTACLR_PTACLR0:    .equ   %00000001
mPTACLR_PTACLR1:    .equ   %00000010
mPTACLR_PTACLR2:    .equ   %00000100
mPTACLR_PTACLR3:    .equ   %00001000
mPTACLR_PTACLR4:    .equ   %00010000
mPTACLR_PTACLR5:    .equ   %00100000
mPTACLR_PTACLR6:    .equ   %01000000
mPTACLR_PTACLR7:    .equ   %10000000


;*** PTATOG - Port A Toggle Register; 0xFFFF8004 ***
PTATOG:             .equ   $FFFF8004                                ;*** PTATOG - Port A Toggle Register; 0xFFFF8004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTATOG_PTATOG0:     .equ   0                                         ; Toggle Enable for Port A Bit 0
PTATOG_PTATOG1:     .equ   1                                         ; Toggle Enable for Port A Bit 1
PTATOG_PTATOG2:     .equ   2                                         ; Toggle Enable for Port A Bit 2
PTATOG_PTATOG3:     .equ   3                                         ; Toggle Enable for Port A Bit 3
PTATOG_PTATOG4:     .equ   4                                         ; Toggle Enable for Port A Bit 4
PTATOG_PTATOG5:     .equ   5                                         ; Toggle Enable for Port A Bit 5
PTATOG_PTATOG6:     .equ   6                                         ; Toggle Enable for Port A Bit 6
PTATOG_PTATOG7:     .equ   7                                         ; Toggle Enable for Port A Bit 7
; bit position masks
mPTATOG_PTATOG0:    .equ   %00000001
mPTATOG_PTATOG1:    .equ   %00000010
mPTATOG_PTATOG2:    .equ   %00000100
mPTATOG_PTATOG3:    .equ   %00001000
mPTATOG_PTATOG4:    .equ   %00010000
mPTATOG_PTATOG5:    .equ   %00100000
mPTATOG_PTATOG6:    .equ   %01000000
mPTATOG_PTATOG7:    .equ   %10000000


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


;*** PTBD - Port B Data Register; 0xFFFF8040 ***
PTBD:               .equ   $FFFF8040                                ;*** PTBD - Port B Data Register; 0xFFFF8040 ***
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


;*** PTBDD - Port B Data Direction Register; 0xFFFF8041 ***
PTBDD:              .equ   $FFFF8041                                ;*** PTBDD - Port B Data Direction Register; 0xFFFF8041 ***
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


;*** PTBSET - Port B Data Set Register; 0xFFFF8042 ***
PTBSET:             .equ   $FFFF8042                                ;*** PTBSET - Port B Data Set Register; 0xFFFF8042 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSET_PTBSET0:     .equ   0                                         ; Data Set for Port B Bit 0
PTBSET_PTBSET1:     .equ   1                                         ; Data Set for Port B Bit 1
PTBSET_PTBSET2:     .equ   2                                         ; Data Set for Port B Bit 2
PTBSET_PTBSET3:     .equ   3                                         ; Data Set for Port B Bit 3
PTBSET_PTBSET4:     .equ   4                                         ; Data Set for Port B Bit 4
PTBSET_PTBSET5:     .equ   5                                         ; Data Set for Port B Bit 5
PTBSET_PTBSET6:     .equ   6                                         ; Data Set for Port B Bit 6
PTBSET_PTBSET7:     .equ   7                                         ; Data Set for Port B Bit 7
; bit position masks
mPTBSET_PTBSET0:    .equ   %00000001
mPTBSET_PTBSET1:    .equ   %00000010
mPTBSET_PTBSET2:    .equ   %00000100
mPTBSET_PTBSET3:    .equ   %00001000
mPTBSET_PTBSET4:    .equ   %00010000
mPTBSET_PTBSET5:    .equ   %00100000
mPTBSET_PTBSET6:    .equ   %01000000
mPTBSET_PTBSET7:    .equ   %10000000


;*** PTBCLR - Port B Data Clear Register; 0xFFFF8043 ***
PTBCLR:             .equ   $FFFF8043                                ;*** PTBCLR - Port B Data Clear Register; 0xFFFF8043 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBCLR_PTBCLR0:     .equ   0                                         ; Data Clear for Port B Bit 0
PTBCLR_PTBCLR1:     .equ   1                                         ; Data Clear for Port B Bit 1
PTBCLR_PTBCLR2:     .equ   2                                         ; Data Clear for Port B Bit 2
PTBCLR_PTBCLR3:     .equ   3                                         ; Data Clear for Port B Bit 3
PTBCLR_PTBCLR4:     .equ   4                                         ; Data Clear for Port B Bit 4
PTBCLR_PTBCLR5:     .equ   5                                         ; Data Clear for Port B Bit 5
PTBCLR_PTBCLR6:     .equ   6                                         ; Data Clear for Port B Bit 6
PTBCLR_PTBCLR7:     .equ   7                                         ; Data Clear for Port B Bit 7
; bit position masks
mPTBCLR_PTBCLR0:    .equ   %00000001
mPTBCLR_PTBCLR1:    .equ   %00000010
mPTBCLR_PTBCLR2:    .equ   %00000100
mPTBCLR_PTBCLR3:    .equ   %00001000
mPTBCLR_PTBCLR4:    .equ   %00010000
mPTBCLR_PTBCLR5:    .equ   %00100000
mPTBCLR_PTBCLR6:    .equ   %01000000
mPTBCLR_PTBCLR7:    .equ   %10000000


;*** PTBTOG - Port B Toggle Register; 0xFFFF8044 ***
PTBTOG:             .equ   $FFFF8044                                ;*** PTBTOG - Port B Toggle Register; 0xFFFF8044 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBTOG_PTBTOG0:     .equ   0                                         ; Toggle Enable for Port B Bit 0
PTBTOG_PTBTOG1:     .equ   1                                         ; Toggle Enable for Port B Bit 1
PTBTOG_PTBTOG2:     .equ   2                                         ; Toggle Enable for Port B Bit 2
PTBTOG_PTBTOG3:     .equ   3                                         ; Toggle Enable for Port B Bit 3
PTBTOG_PTBTOG4:     .equ   4                                         ; Toggle Enable for Port B Bit 4
PTBTOG_PTBTOG5:     .equ   5                                         ; Toggle Enable for Port B Bit 5
PTBTOG_PTBTOG6:     .equ   6                                         ; Toggle Enable for Port B Bit 6
PTBTOG_PTBTOG7:     .equ   7                                         ; Toggle Enable for Port B Bit 7
; bit position masks
mPTBTOG_PTBTOG0:    .equ   %00000001
mPTBTOG_PTBTOG1:    .equ   %00000010
mPTBTOG_PTBTOG2:    .equ   %00000100
mPTBTOG_PTBTOG3:    .equ   %00001000
mPTBTOG_PTBTOG4:    .equ   %00010000
mPTBTOG_PTBTOG5:    .equ   %00100000
mPTBTOG_PTBTOG6:    .equ   %01000000
mPTBTOG_PTBTOG7:    .equ   %10000000


;*** PTBPE - Port B Pull Enable Register; 0xFFFF8048 ***
PTBPE:              .equ   $FFFF8048                                ;*** PTBPE - Port B Pull Enable Register; 0xFFFF8048 ***
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


;*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF8049 ***
PTBSE:              .equ   $FFFF8049                                ;*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF8049 ***
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


;*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF804A ***
PTBDS:              .equ   $FFFF804A                                ;*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF804A ***
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


;*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF804B ***
PTBIFE:             .equ   $FFFF804B                                ;*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF804B ***
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


;*** PTCD - Port C Data Register; 0xFFFF8080 ***
PTCD:               .equ   $FFFF8080                                ;*** PTCD - Port C Data Register; 0xFFFF8080 ***
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


;*** PTCDD - Port C Data Direction Register; 0xFFFF8081 ***
PTCDD:              .equ   $FFFF8081                                ;*** PTCDD - Port C Data Direction Register; 0xFFFF8081 ***
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


;*** PTCSET - Port C Data Set Register; 0xFFFF8082 ***
PTCSET:             .equ   $FFFF8082                                ;*** PTCSET - Port C Data Set Register; 0xFFFF8082 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSET_PTCSET0:     .equ   0                                         ; Data Set for Port C Bit 0
PTCSET_PTCSET1:     .equ   1                                         ; Data Set for Port C Bit 1
PTCSET_PTCSET2:     .equ   2                                         ; Data Set for Port C Bit 2
PTCSET_PTCSET3:     .equ   3                                         ; Data Set for Port C Bit 3
PTCSET_PTCSET4:     .equ   4                                         ; Data Set for Port C Bit 4
PTCSET_PTCSET5:     .equ   5                                         ; Data Set for Port C Bit 5
PTCSET_PTCSET6:     .equ   6                                         ; Data Set for Port C Bit 6
PTCSET_PTCSET7:     .equ   7                                         ; Data Set for Port C Bit 7
; bit position masks
mPTCSET_PTCSET0:    .equ   %00000001
mPTCSET_PTCSET1:    .equ   %00000010
mPTCSET_PTCSET2:    .equ   %00000100
mPTCSET_PTCSET3:    .equ   %00001000
mPTCSET_PTCSET4:    .equ   %00010000
mPTCSET_PTCSET5:    .equ   %00100000
mPTCSET_PTCSET6:    .equ   %01000000
mPTCSET_PTCSET7:    .equ   %10000000


;*** PTCCLR - Port C Data Clear Register; 0xFFFF8083 ***
PTCCLR:             .equ   $FFFF8083                                ;*** PTCCLR - Port C Data Clear Register; 0xFFFF8083 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCCLR_PTCCLR0:     .equ   0                                         ; Data Clear for Port C Bit 0
PTCCLR_PTCCLR1:     .equ   1                                         ; Data Clear for Port C Bit 1
PTCCLR_PTCCLR2:     .equ   2                                         ; Data Clear for Port C Bit 2
PTCCLR_PTCCLR3:     .equ   3                                         ; Data Clear for Port C Bit 3
PTCCLR_PTCCLR4:     .equ   4                                         ; Data Clear for Port C Bit 4
PTCCLR_PTCCLR5:     .equ   5                                         ; Data Clear for Port C Bit 5
PTCCLR_PTCCLR6:     .equ   6                                         ; Data Clear for Port C Bit 6
PTCCLR_PTCCLR7:     .equ   7                                         ; Data Clear for Port C Bit 7
; bit position masks
mPTCCLR_PTCCLR0:    .equ   %00000001
mPTCCLR_PTCCLR1:    .equ   %00000010
mPTCCLR_PTCCLR2:    .equ   %00000100
mPTCCLR_PTCCLR3:    .equ   %00001000
mPTCCLR_PTCCLR4:    .equ   %00010000
mPTCCLR_PTCCLR5:    .equ   %00100000
mPTCCLR_PTCCLR6:    .equ   %01000000
mPTCCLR_PTCCLR7:    .equ   %10000000


;*** PTCTOG - Port C Toggle Register; 0xFFFF8084 ***
PTCTOG:             .equ   $FFFF8084                                ;*** PTCTOG - Port C Toggle Register; 0xFFFF8084 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCTOG_PTCTOG0:     .equ   0                                         ; Toggle Enable for Port C Bit 0
PTCTOG_PTCTOG1:     .equ   1                                         ; Toggle Enable for Port C Bit 1
PTCTOG_PTCTOG2:     .equ   2                                         ; Toggle Enable for Port C Bit 2
PTCTOG_PTCTOG3:     .equ   3                                         ; Toggle Enable for Port C Bit 3
PTCTOG_PTCTOG4:     .equ   4                                         ; Toggle Enable for Port C Bit 4
PTCTOG_PTCTOG5:     .equ   5                                         ; Toggle Enable for Port C Bit 5
PTCTOG_PTCTOG6:     .equ   6                                         ; Toggle Enable for Port C Bit 6
PTCTOG_PTCTOG7:     .equ   7                                         ; Toggle Enable for Port C Bit 7
; bit position masks
mPTCTOG_PTCTOG0:    .equ   %00000001
mPTCTOG_PTCTOG1:    .equ   %00000010
mPTCTOG_PTCTOG2:    .equ   %00000100
mPTCTOG_PTCTOG3:    .equ   %00001000
mPTCTOG_PTCTOG4:    .equ   %00010000
mPTCTOG_PTCTOG5:    .equ   %00100000
mPTCTOG_PTCTOG6:    .equ   %01000000
mPTCTOG_PTCTOG7:    .equ   %10000000


;*** PTCPE - Port C Pull Enable Register; 0xFFFF8088 ***
PTCPE:              .equ   $FFFF8088                                ;*** PTCPE - Port C Pull Enable Register; 0xFFFF8088 ***
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


;*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF8089 ***
PTCSE:              .equ   $FFFF8089                                ;*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF8089 ***
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


;*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF808A ***
PTCDS:              .equ   $FFFF808A                                ;*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF808A ***
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


;*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF808B ***
PTCIFE:             .equ   $FFFF808B                                ;*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF808B ***
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


;*** PTDD - Port D Data Register; 0xFFFF80C0 ***
PTDD:               .equ   $FFFF80C0                                ;*** PTDD - Port D Data Register; 0xFFFF80C0 ***
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


;*** PTDDD - Port D Data Direction Register; 0xFFFF80C1 ***
PTDDD:              .equ   $FFFF80C1                                ;*** PTDDD - Port D Data Direction Register; 0xFFFF80C1 ***
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


;*** PTDSET - Port D Data Set Register; 0xFFFF80C2 ***
PTDSET:             .equ   $FFFF80C2                                ;*** PTDSET - Port D Data Set Register; 0xFFFF80C2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSET_PTDSET0:     .equ   0                                         ; Data Set for Port D Bit 0
PTDSET_PTDSET1:     .equ   1                                         ; Data Set for Port D Bit 1
PTDSET_PTDSET2:     .equ   2                                         ; Data Set for Port D Bit 2
PTDSET_PTDSET3:     .equ   3                                         ; Data Set for Port D Bit 3
PTDSET_PTDSET4:     .equ   4                                         ; Data Set for Port D Bit 4
PTDSET_PTDSET5:     .equ   5                                         ; Data Set for Port D Bit 5
PTDSET_PTDSET6:     .equ   6                                         ; Data Set for Port D Bit 6
PTDSET_PTDSET7:     .equ   7                                         ; Data Set for Port D Bit 7
; bit position masks
mPTDSET_PTDSET0:    .equ   %00000001
mPTDSET_PTDSET1:    .equ   %00000010
mPTDSET_PTDSET2:    .equ   %00000100
mPTDSET_PTDSET3:    .equ   %00001000
mPTDSET_PTDSET4:    .equ   %00010000
mPTDSET_PTDSET5:    .equ   %00100000
mPTDSET_PTDSET6:    .equ   %01000000
mPTDSET_PTDSET7:    .equ   %10000000


;*** PTDCLR - Port D Data Clear Register; 0xFFFF80C3 ***
PTDCLR:             .equ   $FFFF80C3                                ;*** PTDCLR - Port D Data Clear Register; 0xFFFF80C3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDCLR_PTDCLR0:     .equ   0                                         ; Data Clear for Port D Bit 0
PTDCLR_PTDCLR1:     .equ   1                                         ; Data Clear for Port D Bit 1
PTDCLR_PTDCLR2:     .equ   2                                         ; Data Clear for Port D Bit 2
PTDCLR_PTDCLR3:     .equ   3                                         ; Data Clear for Port D Bit 3
PTDCLR_PTDCLR4:     .equ   4                                         ; Data Clear for Port D Bit 4
PTDCLR_PTDCLR5:     .equ   5                                         ; Data Clear for Port D Bit 5
PTDCLR_PTDCLR6:     .equ   6                                         ; Data Clear for Port D Bit 6
PTDCLR_PTDCLR7:     .equ   7                                         ; Data Clear for Port D Bit 7
; bit position masks
mPTDCLR_PTDCLR0:    .equ   %00000001
mPTDCLR_PTDCLR1:    .equ   %00000010
mPTDCLR_PTDCLR2:    .equ   %00000100
mPTDCLR_PTDCLR3:    .equ   %00001000
mPTDCLR_PTDCLR4:    .equ   %00010000
mPTDCLR_PTDCLR5:    .equ   %00100000
mPTDCLR_PTDCLR6:    .equ   %01000000
mPTDCLR_PTDCLR7:    .equ   %10000000


;*** PTDTOG - Port D Toggle Register; 0xFFFF80C4 ***
PTDTOG:             .equ   $FFFF80C4                                ;*** PTDTOG - Port D Toggle Register; 0xFFFF80C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDTOG_PTDTOG0:     .equ   0                                         ; Toggle Enable for Port D Bit 0
PTDTOG_PTDTOG1:     .equ   1                                         ; Toggle Enable for Port D Bit 1
PTDTOG_PTDTOG2:     .equ   2                                         ; Toggle Enable for Port D Bit 2
PTDTOG_PTDTOG3:     .equ   3                                         ; Toggle Enable for Port D Bit 3
PTDTOG_PTDTOG4:     .equ   4                                         ; Toggle Enable for Port D Bit 4
PTDTOG_PTDTOG5:     .equ   5                                         ; Toggle Enable for Port D Bit 5
PTDTOG_PTDTOG6:     .equ   6                                         ; Toggle Enable for Port D Bit 6
PTDTOG_PTDTOG7:     .equ   7                                         ; Toggle Enable for Port D Bit 7
; bit position masks
mPTDTOG_PTDTOG0:    .equ   %00000001
mPTDTOG_PTDTOG1:    .equ   %00000010
mPTDTOG_PTDTOG2:    .equ   %00000100
mPTDTOG_PTDTOG3:    .equ   %00001000
mPTDTOG_PTDTOG4:    .equ   %00010000
mPTDTOG_PTDTOG5:    .equ   %00100000
mPTDTOG_PTDTOG6:    .equ   %01000000
mPTDTOG_PTDTOG7:    .equ   %10000000


;*** PTDPE - Port D Pull Enable Register; 0xFFFF80C8 ***
PTDPE:              .equ   $FFFF80C8                                ;*** PTDPE - Port D Pull Enable Register; 0xFFFF80C8 ***
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


;*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF80C9 ***
PTDSE:              .equ   $FFFF80C9                                ;*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF80C9 ***
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


;*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF80CA ***
PTDDS:              .equ   $FFFF80CA                                ;*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF80CA ***
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


;*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF80CB ***
PTDIFE:             .equ   $FFFF80CB                                ;*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF80CB ***
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


;*** PTED - Port E Data Register; 0xFFFF8100 ***
PTED:               .equ   $FFFF8100                                ;*** PTED - Port E Data Register; 0xFFFF8100 ***
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


;*** PTEDD - Port E Data Direction Register; 0xFFFF8101 ***
PTEDD:              .equ   $FFFF8101                                ;*** PTEDD - Port E Data Direction Register; 0xFFFF8101 ***
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


;*** PTESET - Port E Data Set Register; 0xFFFF8102 ***
PTESET:             .equ   $FFFF8102                                ;*** PTESET - Port E Data Set Register; 0xFFFF8102 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTESET_PTESET0:     .equ   0                                         ; Data Set for Port E Bit 0
PTESET_PTESET1:     .equ   1                                         ; Data Set for Port E Bit 1
PTESET_PTESET2:     .equ   2                                         ; Data Set for Port E Bit 2
PTESET_PTESET3:     .equ   3                                         ; Data Set for Port E Bit 3
PTESET_PTESET4:     .equ   4                                         ; Data Set for Port E Bit 4
PTESET_PTESET5:     .equ   5                                         ; Data Set for Port E Bit 5
PTESET_PTESET6:     .equ   6                                         ; Data Set for Port E Bit 6
PTESET_PTESET7:     .equ   7                                         ; Data Set for Port E Bit 7
; bit position masks
mPTESET_PTESET0:    .equ   %00000001
mPTESET_PTESET1:    .equ   %00000010
mPTESET_PTESET2:    .equ   %00000100
mPTESET_PTESET3:    .equ   %00001000
mPTESET_PTESET4:    .equ   %00010000
mPTESET_PTESET5:    .equ   %00100000
mPTESET_PTESET6:    .equ   %01000000
mPTESET_PTESET7:    .equ   %10000000


;*** PTECLR - Port E Data Clear Register; 0xFFFF8103 ***
PTECLR:             .equ   $FFFF8103                                ;*** PTECLR - Port E Data Clear Register; 0xFFFF8103 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTECLR_PTECLR0:     .equ   0                                         ; Data Clear for Port E Bit 0
PTECLR_PTECLR1:     .equ   1                                         ; Data Clear for Port E Bit 1
PTECLR_PTECLR2:     .equ   2                                         ; Data Clear for Port E Bit 2
PTECLR_PTECLR3:     .equ   3                                         ; Data Clear for Port E Bit 3
PTECLR_PTECLR4:     .equ   4                                         ; Data Clear for Port E Bit 4
PTECLR_PTECLR5:     .equ   5                                         ; Data Clear for Port E Bit 5
PTECLR_PTECLR6:     .equ   6                                         ; Data Clear for Port E Bit 6
PTECLR_PTECLR7:     .equ   7                                         ; Data Clear for Port E Bit 7
; bit position masks
mPTECLR_PTECLR0:    .equ   %00000001
mPTECLR_PTECLR1:    .equ   %00000010
mPTECLR_PTECLR2:    .equ   %00000100
mPTECLR_PTECLR3:    .equ   %00001000
mPTECLR_PTECLR4:    .equ   %00010000
mPTECLR_PTECLR5:    .equ   %00100000
mPTECLR_PTECLR6:    .equ   %01000000
mPTECLR_PTECLR7:    .equ   %10000000


;*** PTETOG - Port E Toggle Register; 0xFFFF8104 ***
PTETOG:             .equ   $FFFF8104                                ;*** PTETOG - Port E Toggle Register; 0xFFFF8104 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTETOG_PTETOG0:     .equ   0                                         ; Toggle Enable for Port E Bit 0
PTETOG_PTETOG1:     .equ   1                                         ; Toggle Enable for Port E Bit 1
PTETOG_PTETOG2:     .equ   2                                         ; Toggle Enable for Port E Bit 2
PTETOG_PTETOG3:     .equ   3                                         ; Toggle Enable for Port E Bit 3
PTETOG_PTETOG4:     .equ   4                                         ; Toggle Enable for Port E Bit 4
PTETOG_PTETOG5:     .equ   5                                         ; Toggle Enable for Port E Bit 5
PTETOG_PTETOG6:     .equ   6                                         ; Toggle Enable for Port E Bit 6
PTETOG_PTETOG7:     .equ   7                                         ; Toggle Enable for Port E Bit 7
; bit position masks
mPTETOG_PTETOG0:    .equ   %00000001
mPTETOG_PTETOG1:    .equ   %00000010
mPTETOG_PTETOG2:    .equ   %00000100
mPTETOG_PTETOG3:    .equ   %00001000
mPTETOG_PTETOG4:    .equ   %00010000
mPTETOG_PTETOG5:    .equ   %00100000
mPTETOG_PTETOG6:    .equ   %01000000
mPTETOG_PTETOG7:    .equ   %10000000


;*** PTEPE - Port E Pull Enable Register; 0xFFFF8108 ***
PTEPE:              .equ   $FFFF8108                                ;*** PTEPE - Port E Pull Enable Register; 0xFFFF8108 ***
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


;*** PTESE - Port E Slew Rate Enable Register; 0xFFFF8109 ***
PTESE:              .equ   $FFFF8109                                ;*** PTESE - Port E Slew Rate Enable Register; 0xFFFF8109 ***
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


;*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF810A ***
PTEDS:              .equ   $FFFF810A                                ;*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF810A ***
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


;*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF810B ***
PTEIFE:             .equ   $FFFF810B                                ;*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF810B ***
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


;*** PTFD - Port F Data Register; 0xFFFF8140 ***
PTFD:               .equ   $FFFF8140                                ;*** PTFD - Port F Data Register; 0xFFFF8140 ***
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


;*** PTFDD - Port F Data Direction Register; 0xFFFF8141 ***
PTFDD:              .equ   $FFFF8141                                ;*** PTFDD - Port F Data Direction Register; 0xFFFF8141 ***
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


;*** PTFSET - Port F Data Set Register; 0xFFFF8142 ***
PTFSET:             .equ   $FFFF8142                                ;*** PTFSET - Port F Data Set Register; 0xFFFF8142 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSET_PTFSET0:     .equ   0                                         ; Data Set for Port F Bit 0
PTFSET_PTFSET1:     .equ   1                                         ; Data Set for Port F Bit 1
PTFSET_PTFSET2:     .equ   2                                         ; Data Set for Port F Bit 2
PTFSET_PTFSET3:     .equ   3                                         ; Data Set for Port F Bit 3
PTFSET_PTFSET4:     .equ   4                                         ; Data Set for Port F Bit 4
PTFSET_PTFSET5:     .equ   5                                         ; Data Set for Port F Bit 5
PTFSET_PTFSET6:     .equ   6                                         ; Data Set for Port F Bit 6
PTFSET_PTFSET7:     .equ   7                                         ; Data Set for Port F Bit 7
; bit position masks
mPTFSET_PTFSET0:    .equ   %00000001
mPTFSET_PTFSET1:    .equ   %00000010
mPTFSET_PTFSET2:    .equ   %00000100
mPTFSET_PTFSET3:    .equ   %00001000
mPTFSET_PTFSET4:    .equ   %00010000
mPTFSET_PTFSET5:    .equ   %00100000
mPTFSET_PTFSET6:    .equ   %01000000
mPTFSET_PTFSET7:    .equ   %10000000


;*** PTFCLR - Port F Data Clear Register; 0xFFFF8143 ***
PTFCLR:             .equ   $FFFF8143                                ;*** PTFCLR - Port F Data Clear Register; 0xFFFF8143 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFCLR_PTFCLR0:     .equ   0                                         ; Data Clear for Port F Bit 0
PTFCLR_PTFCLR1:     .equ   1                                         ; Data Clear for Port F Bit 1
PTFCLR_PTFCLR2:     .equ   2                                         ; Data Clear for Port F Bit 2
PTFCLR_PTFCLR3:     .equ   3                                         ; Data Clear for Port F Bit 3
PTFCLR_PTFCLR4:     .equ   4                                         ; Data Clear for Port F Bit 4
PTFCLR_PTFCLR5:     .equ   5                                         ; Data Clear for Port F Bit 5
PTFCLR_PTFCLR6:     .equ   6                                         ; Data Clear for Port F Bit 6
PTFCLR_PTFCLR7:     .equ   7                                         ; Data Clear for Port F Bit 7
; bit position masks
mPTFCLR_PTFCLR0:    .equ   %00000001
mPTFCLR_PTFCLR1:    .equ   %00000010
mPTFCLR_PTFCLR2:    .equ   %00000100
mPTFCLR_PTFCLR3:    .equ   %00001000
mPTFCLR_PTFCLR4:    .equ   %00010000
mPTFCLR_PTFCLR5:    .equ   %00100000
mPTFCLR_PTFCLR6:    .equ   %01000000
mPTFCLR_PTFCLR7:    .equ   %10000000


;*** PTFTOG - Port F Toggle Register; 0xFFFF8144 ***
PTFTOG:             .equ   $FFFF8144                                ;*** PTFTOG - Port F Toggle Register; 0xFFFF8144 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFTOG_PTFTOG0:     .equ   0                                         ; Toggle Enable for Port F Bit 0
PTFTOG_PTFTOG1:     .equ   1                                         ; Toggle Enable for Port F Bit 1
PTFTOG_PTFTOG2:     .equ   2                                         ; Toggle Enable for Port F Bit 2
PTFTOG_PTFTOG3:     .equ   3                                         ; Toggle Enable for Port F Bit 3
PTFTOG_PTFTOG4:     .equ   4                                         ; Toggle Enable for Port F Bit 4
PTFTOG_PTFTOG5:     .equ   5                                         ; Toggle Enable for Port F Bit 5
PTFTOG_PTFTOG6:     .equ   6                                         ; Toggle Enable for Port F Bit 6
PTFTOG_PTFTOG7:     .equ   7                                         ; Toggle Enable for Port F Bit 7
; bit position masks
mPTFTOG_PTFTOG0:    .equ   %00000001
mPTFTOG_PTFTOG1:    .equ   %00000010
mPTFTOG_PTFTOG2:    .equ   %00000100
mPTFTOG_PTFTOG3:    .equ   %00001000
mPTFTOG_PTFTOG4:    .equ   %00010000
mPTFTOG_PTFTOG5:    .equ   %00100000
mPTFTOG_PTFTOG6:    .equ   %01000000
mPTFTOG_PTFTOG7:    .equ   %10000000


;*** PTFPE - Port F Pull Enable Register; 0xFFFF8148 ***
PTFPE:              .equ   $FFFF8148                                ;*** PTFPE - Port F Pull Enable Register; 0xFFFF8148 ***
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


;*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF8149 ***
PTFSE:              .equ   $FFFF8149                                ;*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF8149 ***
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


;*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF814A ***
PTFDS:              .equ   $FFFF814A                                ;*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF814A ***
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


;*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF814B ***
PTFIFE:             .equ   $FFFF814B                                ;*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF814B ***
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


;*** KBI1SC - KBI1 Status and Control Register; 0xFFFF8180 ***
KBI1SC:             .equ   $FFFF8180                                ;*** KBI1SC - KBI1 Status and Control Register; 0xFFFF8180 ***
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


;*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF8181 ***
KBI1PE:             .equ   $FFFF8181                                ;*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF8181 ***
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


;*** KBI1ES - KBI1 Edge Select Register; 0xFFFF8182 ***
KBI1ES:             .equ   $FFFF8182                                ;*** KBI1ES - KBI1 Edge Select Register; 0xFFFF8182 ***
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


;*** KBI2SC - KBI2 Status and Control Register; 0xFFFF81A0 ***
KBI2SC:             .equ   $FFFF81A0                                ;*** KBI2SC - KBI2 Status and Control Register; 0xFFFF81A0 ***
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


;*** KBI2PE - KBI2 Pin Enable Register; 0xFFFF81A1 ***
KBI2PE:             .equ   $FFFF81A1                                ;*** KBI2PE - KBI2 Pin Enable Register; 0xFFFF81A1 ***
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


;*** KBI2ES - KBI2 Edge Select Register; 0xFFFF81A2 ***
KBI2ES:             .equ   $FFFF81A2                                ;*** KBI2ES - KBI2 Edge Select Register; 0xFFFF81A2 ***
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


;*** IRQSC - Interrupt request status and control register; 0xFFFF81C0 ***
IRQSC:              .equ   $FFFF81C0                                ;*** IRQSC - Interrupt request status and control register; 0xFFFF81C0 ***
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


;*** PTAPF1 - Port A Routing Register 1; 0xFFFF8200 ***
PTAPF1:             .equ   $FFFF8200                                ;*** PTAPF1 - Port A Routing Register 1; 0xFFFF8200 ***
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


;*** PTAPF2 - Port A Routing Register 2; 0xFFFF8201 ***
PTAPF2:             .equ   $FFFF8201                                ;*** PTAPF2 - Port A Routing Register 2; 0xFFFF8201 ***
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


;*** PTBPF1 - Port B Routing Register 1; 0xFFFF8202 ***
PTBPF1:             .equ   $FFFF8202                                ;*** PTBPF1 - Port B Routing Register 1; 0xFFFF8202 ***
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


;*** PTBPF2 - Port B Routing Register 2; 0xFFFF8203 ***
PTBPF2:             .equ   $FFFF8203                                ;*** PTBPF2 - Port B Routing Register 2; 0xFFFF8203 ***
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


;*** PTCPF1 - Port C Routing Register 1; 0xFFFF8204 ***
PTCPF1:             .equ   $FFFF8204                                ;*** PTCPF1 - Port C Routing Register 1; 0xFFFF8204 ***
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


;*** PTCPF2 - Port C Routing Register 2; 0xFFFF8205 ***
PTCPF2:             .equ   $FFFF8205                                ;*** PTCPF2 - Port C Routing Register 2; 0xFFFF8205 ***
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


;*** PTDPF1 - Port D Routing Register 1; 0xFFFF8206 ***
PTDPF1:             .equ   $FFFF8206                                ;*** PTDPF1 - Port D Routing Register 1; 0xFFFF8206 ***
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


;*** PTDPF2 - Port D Routing Register 2; 0xFFFF8207 ***
PTDPF2:             .equ   $FFFF8207                                ;*** PTDPF2 - Port D Routing Register 2; 0xFFFF8207 ***
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


;*** PTEPF1 - Port E Routing Register 1; 0xFFFF8208 ***
PTEPF1:             .equ   $FFFF8208                                ;*** PTEPF1 - Port E Routing Register 1; 0xFFFF8208 ***
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


;*** PTEPF2 - Port E Routing Register 2; 0xFFFF8209 ***
PTEPF2:             .equ   $FFFF8209                                ;*** PTEPF2 - Port E Routing Register 2; 0xFFFF8209 ***
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


;*** PTFPF1 - Port F Routing Register 1; 0xFFFF820A ***
PTFPF1:             .equ   $FFFF820A                                ;*** PTFPF1 - Port F Routing Register 1; 0xFFFF820A ***
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


;*** PTFPF2 - Port F Routing Register 2; 0xFFFF820B ***
PTFPF2:             .equ   $FFFF820B                                ;*** PTFPF2 - Port F Routing Register 2; 0xFFFF820B ***
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


;*** LCDPF1 - LCD Pin Mux Control Register 1; 0xFFFF820C ***
LCDPF1:             .equ   $FFFF820C                                ;*** LCDPF1 - LCD Pin Mux Control Register 1; 0xFFFF820C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPF1_LCD60:       .equ   0                                         ; LCD6 mux control bit 0
LCDPF1_LCD61:       .equ   1                                         ; LCD6 mux control bit 1
LCDPF1_LCD70:       .equ   2                                         ; LCD7 mux control bit 0
LCDPF1_LCD71:       .equ   3                                         ; LCD7 mux control bit 1
LCDPF1_LCD80:       .equ   4                                         ; LCD8 mux control bit 0
LCDPF1_LCD81:       .equ   5                                         ; LCD8 mux control bit 1
LCDPF1_LCD90:       .equ   6                                         ; LCD9 mux control bit 0
LCDPF1_LCD91:       .equ   7                                         ; LCD9 mux control bit 1
; bit position masks
mLCDPF1_LCD60:      .equ   %00000001
mLCDPF1_LCD61:      .equ   %00000010
mLCDPF1_LCD70:      .equ   %00000100
mLCDPF1_LCD71:      .equ   %00001000
mLCDPF1_LCD80:      .equ   %00010000
mLCDPF1_LCD81:      .equ   %00100000
mLCDPF1_LCD90:      .equ   %01000000
mLCDPF1_LCD91:      .equ   %10000000


;*** LCDPF2 - LCD Pin Mux Control Register 1; 0xFFFF820D ***
LCDPF2:             .equ   $FFFF820D                                ;*** LCDPF2 - LCD Pin Mux Control Register 1; 0xFFFF820D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPF2_LCD350:      .equ   0                                         ; LCD35 mux control bit 0
LCDPF2_LCD351:      .equ   1                                         ; LCD35 mux control bit 1
; bit position masks
mLCDPF2_LCD350:     .equ   %00000001
mLCDPF2_LCD351:     .equ   %00000010


;*** ICSC1 - ICS Control Register 1; 0xFFFF8220 ***
ICSC1:              .equ   $FFFF8220                                ;*** ICSC1 - ICS Control Register 1; 0xFFFF8220 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC1_IREFSTEN:     .equ   0                                         ; Internal Reference Stop Enable
ICSC1_IRCLKEN:      .equ   1                                         ; Internal Reference Clock Enable
ICSC1_IREFS:        .equ   2                                         ; Internal Reference Select
ICSC1_RDIV0:        .equ   3                                         ; Reference Divider, bit 0
ICSC1_RDIV1:        .equ   4                                         ; Reference Divider, bit 1
ICSC1_RDIV2:        .equ   5                                         ; Reference Divider, bit 2
ICSC1_CLKS0:        .equ   6                                         ; Clock Source Select, bit 0
ICSC1_CLKS1:        .equ   7                                         ; Clock Source Select, bit 1
; bit position masks
mICSC1_IREFSTEN:    .equ   %00000001
mICSC1_IRCLKEN:     .equ   %00000010
mICSC1_IREFS:       .equ   %00000100
mICSC1_RDIV0:       .equ   %00001000
mICSC1_RDIV1:       .equ   %00010000
mICSC1_RDIV2:       .equ   %00100000
mICSC1_CLKS0:       .equ   %01000000
mICSC1_CLKS1:       .equ   %10000000


;*** ICSC2 - ICS Control Register 2; 0xFFFF8221 ***
ICSC2:              .equ   $FFFF8221                                ;*** ICSC2 - ICS Control Register 2; 0xFFFF8221 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC2_EREFSTEN:     .equ   0                                         ; External Reference Stop Enable
ICSC2_ERCLKEN:      .equ   1                                         ; External Reference Enable
ICSC2_EREFS:        .equ   2                                         ; External Reference Select
ICSC2_LP:           .equ   3                                         ; Low Power Select
ICSC2_HGO:          .equ   4                                         ; High Gain Oscillator Select
ICSC2_RANGE:        .equ   5                                         ; Frequency Range Select
ICSC2_BDIV0:        .equ   6                                         ; Bus Frequency Divider, bit 0
ICSC2_BDIV1:        .equ   7                                         ; Bus Frequency Divider, bit 1
; bit position masks
mICSC2_EREFSTEN:    .equ   %00000001
mICSC2_ERCLKEN:     .equ   %00000010
mICSC2_EREFS:       .equ   %00000100
mICSC2_LP:          .equ   %00001000
mICSC2_HGO:         .equ   %00010000
mICSC2_RANGE:       .equ   %00100000
mICSC2_BDIV0:       .equ   %01000000
mICSC2_BDIV1:       .equ   %10000000


;*** ICSTRM - ICS Trim Register; 0xFFFF8222 ***
ICSTRM:             .equ   $FFFF8222                                ;*** ICSTRM - ICS Trim Register; 0xFFFF8222 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM0:       .equ   0                                         ; ICS Trim Setting, bit 0
ICSTRM_TRIM1:       .equ   1                                         ; ICS Trim Setting, bit 1
ICSTRM_TRIM2:       .equ   2                                         ; ICS Trim Setting, bit 2
ICSTRM_TRIM3:       .equ   3                                         ; ICS Trim Setting, bit 3
ICSTRM_TRIM4:       .equ   4                                         ; ICS Trim Setting, bit 4
ICSTRM_TRIM5:       .equ   5                                         ; ICS Trim Setting, bit 5
ICSTRM_TRIM6:       .equ   6                                         ; ICS Trim Setting, bit 6
ICSTRM_TRIM7:       .equ   7                                         ; ICS Trim Setting, bit 7
; bit position masks
mICSTRM_TRIM0:      .equ   %00000001
mICSTRM_TRIM1:      .equ   %00000010
mICSTRM_TRIM2:      .equ   %00000100
mICSTRM_TRIM3:      .equ   %00001000
mICSTRM_TRIM4:      .equ   %00010000
mICSTRM_TRIM5:      .equ   %00100000
mICSTRM_TRIM6:      .equ   %01000000
mICSTRM_TRIM7:      .equ   %10000000


;*** ICSSC - ICS Status and Control Register; 0xFFFF8223 ***
ICSSC:              .equ   $FFFF8223                                ;*** ICSSC - ICS Status and Control Register; 0xFFFF8223 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM:        .equ   0                                         ; ICS Fine Trim
ICSSC_OSCINIT:      .equ   1                                         ; OSC Initialization
ICSSC_CLKST0:       .equ   2                                         ; Clock Mode Status, bit 0
ICSSC_CLKST1:       .equ   3                                         ; Clock Mode Status, bit 1
ICSSC_IREFST:       .equ   4                                         ; Internal Reference Status
ICSSC_DMX32:        .equ   5                                         ; DCO Maximum frequency with 32.768 kHz reference
ICSSC_DRST_DRS0:    .equ   6                                         ; DCO Range Status/Range Select, bit 0
ICSSC_DRST_DRS1:    .equ   7                                         ; DCO Range Status/Range Select, bit 1
; bit position masks
mICSSC_FTRIM:       .equ   %00000001
mICSSC_OSCINIT:     .equ   %00000010
mICSSC_CLKST0:      .equ   %00000100
mICSSC_CLKST1:      .equ   %00001000
mICSSC_IREFST:      .equ   %00010000
mICSSC_DMX32:       .equ   %00100000
mICSSC_DRST_DRS0:   .equ   %01000000
mICSSC_DRST_DRS1:   .equ   %10000000


;*** CCSCTRL - Clock Check & Select Control; 0xFFFF8240 ***
CCSCTRL:            .equ   $FFFF8240                                ;*** CCSCTRL - Clock Check & Select Control; 0xFFFF8240 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSCTRL_SEL:        .equ   0                                         ; External Clock Select
CCSCTRL_TEST:       .equ   1                                         ; TEST
CCSCTRL_EN:         .equ   2                                         ; Enable clock for CCS
; bit position masks
mCCSCTRL_SEL:       .equ   %00000001
mCCSCTRL_TEST:      .equ   %00000010
mCCSCTRL_EN:        .equ   %00000100


;*** CCSTMR1 - CCS XOSC1 Timer Register; 0xFFFF8241 ***
CCSTMR1:            .equ   $FFFF8241                                ;*** CCSTMR1 - CCS XOSC1 Timer Register; 0xFFFF8241 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSTMR1_CNT10:      .equ   0                                         ; CNT1, bit 0
CCSTMR1_CNT11:      .equ   1                                         ; CNT1, bit 1
CCSTMR1_CNT12:      .equ   2                                         ; CNT1, bit 2
CCSTMR1_CNT13:      .equ   3                                         ; CNT1, bit 3
CCSTMR1_CNT14:      .equ   4                                         ; CNT1, bit 4
CCSTMR1_CNT15:      .equ   5                                         ; CNT1, bit 5
CCSTMR1_CNT16:      .equ   6                                         ; CNT1, bit 6
CCSTMR1_CNT17:      .equ   7                                         ; CNT1, bit 7
; bit position masks
mCCSTMR1_CNT10:     .equ   %00000001
mCCSTMR1_CNT11:     .equ   %00000010
mCCSTMR1_CNT12:     .equ   %00000100
mCCSTMR1_CNT13:     .equ   %00001000
mCCSTMR1_CNT14:     .equ   %00010000
mCCSTMR1_CNT15:     .equ   %00100000
mCCSTMR1_CNT16:     .equ   %01000000
mCCSTMR1_CNT17:     .equ   %10000000


;*** CCSTMR2 - CCS XOSC2 Timer Register; 0xFFFF8242 ***
CCSTMR2:            .equ   $FFFF8242                                ;*** CCSTMR2 - CCS XOSC2 Timer Register; 0xFFFF8242 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSTMR2_CNT20:      .equ   0                                         ; CNT2, bit 0
CCSTMR2_CNT21:      .equ   1                                         ; CNT2, bit 1
CCSTMR2_CNT22:      .equ   2                                         ; CNT2, bit 2
CCSTMR2_CNT23:      .equ   3                                         ; CNT2, bit 3
CCSTMR2_CNT24:      .equ   4                                         ; CNT2, bit 4
CCSTMR2_CNT25:      .equ   5                                         ; CNT2, bit 5
CCSTMR2_CNT26:      .equ   6                                         ; CNT2, bit 6
CCSTMR2_CNT27:      .equ   7                                         ; CNT2, bit 7
; bit position masks
mCCSTMR2_CNT20:     .equ   %00000001
mCCSTMR2_CNT21:     .equ   %00000010
mCCSTMR2_CNT22:     .equ   %00000100
mCCSTMR2_CNT23:     .equ   %00001000
mCCSTMR2_CNT24:     .equ   %00010000
mCCSTMR2_CNT25:     .equ   %00100000
mCCSTMR2_CNT26:     .equ   %01000000
mCCSTMR2_CNT27:     .equ   %10000000


;*** CCSTMRIR - CCS Internal Reference Clock Timer Register; 0xFFFF8243 ***
CCSTMRIR:           .equ   $FFFF8243                                ;*** CCSTMRIR - CCS Internal Reference Clock Timer Register; 0xFFFF8243 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSTMRIR_CNTIR0:    .equ   0                                         ; CNTIR, bit 0
CCSTMRIR_CNTIR1:    .equ   1                                         ; CNTIR, bit 1
CCSTMRIR_CNTIR2:    .equ   2                                         ; CNTIR, bit 2
CCSTMRIR_CNTIR3:    .equ   3                                         ; CNTIR, bit 3
CCSTMRIR_CNTIR4:    .equ   4                                         ; CNTIR, bit 4
CCSTMRIR_CNTIR5:    .equ   5                                         ; CNTIR, bit 5
CCSTMRIR_CNTIR6:    .equ   6                                         ; CNTIR, bit 6
CCSTMRIR_CNTIR7:    .equ   7                                         ; CNTIR, bit 7
; bit position masks
mCCSTMRIR_CNTIR0:   .equ   %00000001
mCCSTMRIR_CNTIR1:   .equ   %00000010
mCCSTMRIR_CNTIR2:   .equ   %00000100
mCCSTMRIR_CNTIR3:   .equ   %00001000
mCCSTMRIR_CNTIR4:   .equ   %00010000
mCCSTMRIR_CNTIR5:   .equ   %00100000
mCCSTMRIR_CNTIR6:   .equ   %01000000
mCCSTMRIR_CNTIR7:   .equ   %10000000


;*** SRS - System Reset Status Register; 0xFFFF8280 ***
SRS:                .equ   $FFFF8280                                ;*** SRS - System Reset Status Register; 0xFFFF8280 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD:            .equ   1                                         ; Low Voltage Detect
SRS_ILAD:           .equ   3                                         ; Illegal Address
SRS_ILOP:           .equ   4                                         ; Illegal Opcode
SRS_COP:            .equ   5                                         ; Computer Operating Properly (COP) Watchdog
SRS_PIN:            .equ   6                                         ; External Reset Pin
SRS_POR:            .equ   7                                         ; Power-On Reset
; bit position masks
mSRS_LVD:           .equ   %00000010
mSRS_ILAD:          .equ   %00001000
mSRS_ILOP:          .equ   %00010000
mSRS_COP:           .equ   %00100000
mSRS_PIN:           .equ   %01000000
mSRS_POR:           .equ   %10000000


;*** SOPT1 - System Options Register 1; 0xFFFF8281 ***
SOPT1:              .equ   $FFFF8281                                ;*** SOPT1 - System Options Register 1; 0xFFFF8281 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_COPW:         .equ   0                                         ; COP Window Mode
SOPT1_COPCLKS:      .equ   1                                         ; COP Watchdog Clock Select
SOPT1_COPT0:        .equ   2                                         ; COP Watchdog Timeout, bit 0
SOPT1_COPT1:        .equ   3                                         ; COP Watchdog Timeout, bit 1
SOPT1_WAITE:        .equ   4                                         ; WAIT Mode Enable
SOPT1_STOPE:        .equ   5                                         ; Stop Mode Enable
; bit position masks
mSOPT1_COPW:        .equ   %00000001
mSOPT1_COPCLKS:     .equ   %00000010
mSOPT1_COPT0:       .equ   %00000100
mSOPT1_COPT1:       .equ   %00001000
mSOPT1_WAITE:       .equ   %00010000
mSOPT1_STOPE:       .equ   %00100000


;*** SDID - System Device Identification Register; 0xFFFF8284 ***
SDID:               .equ   $FFFF8284                                ;*** SDID - System Device Identification Register; 0xFFFF8284 ***
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


;*** SDIDH - System Device Identification Register High; 0xFFFF8284 ***
SDIDH:              .equ   $FFFF8284                                ;*** SDIDH - System Device Identification Register High; 0xFFFF8284 ***
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


;*** SDIDL - System Device Identification Register Low; 0xFFFF8285 ***
SDIDL:              .equ   $FFFF8285                                ;*** SDIDL - System Device Identification Register Low; 0xFFFF8285 ***
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


;*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF8286 ***
SCGC1:              .equ   $FFFF8286                                ;*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF8286 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI1:         .equ   0                                         ; SCI1 Clock Gate Control
SCGC1_SCI2:         .equ   1                                         ; SCI2 Clock Gate Control
SCGC1_SCI3:         .equ   2                                         ; SCI3 Clock Gate Control
SCGC1_IIC:          .equ   3                                         ; IIC Clock Gate Control
SCGC1_ADC1:         .equ   4                                         ; ADC 1 Clock Gate Control
SCGC1_ADC2:         .equ   5                                         ; ADC 2 Clock Gate Control
SCGC1_ADC3:         .equ   6                                         ; ADC 3 Clock Gate Control
SCGC1_ADC4:         .equ   7                                         ; ADC 4 Clock Gate Control
; bit position masks
mSCGC1_SCI1:        .equ   %00000001
mSCGC1_SCI2:        .equ   %00000010
mSCGC1_SCI3:        .equ   %00000100
mSCGC1_IIC:         .equ   %00001000
mSCGC1_ADC1:        .equ   %00010000
mSCGC1_ADC2:        .equ   %00100000
mSCGC1_ADC3:        .equ   %01000000
mSCGC1_ADC4:        .equ   %10000000


;*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF8287 ***
SCGC2:              .equ   $FFFF8287                                ;*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF8287 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI1:         .equ   0                                         ; SPI1 Clock Gate Control
SCGC2_SPI2:         .equ   1                                         ; SPI2 Clock Gate Control
SCGC2_SPI3:         .equ   2                                         ; SPI3 Clock Gate Control
SCGC2_LCD:          .equ   3                                         ; LCD Clock Gate Control
SCGC2_IRQ:          .equ   4                                         ; IRQ Clock Gate Control
SCGC2_VREF:         .equ   5                                         ; VREF Clock Gate Control
SCGC2_CMP1:         .equ   6                                         ; CMP1 Clock Gate Control
SCGC2_CMP2:         .equ   7                                         ; CMP2 Clock Gate Control
; bit position masks
mSCGC2_SPI1:        .equ   %00000001
mSCGC2_SPI2:        .equ   %00000010
mSCGC2_SPI3:        .equ   %00000100
mSCGC2_LCD:         .equ   %00001000
mSCGC2_IRQ:         .equ   %00010000
mSCGC2_VREF:        .equ   %00100000
mSCGC2_CMP1:        .equ   %01000000
mSCGC2_CMP2:        .equ   %10000000


;*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF8288 ***
SCGC3:              .equ   $FFFF8288                                ;*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF8288 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC3_PTA:          .equ   0                                         ; PTA Clock Gate Control
SCGC3_PTB:          .equ   1                                         ; PTB Clock Gate Control
SCGC3_PTC:          .equ   2                                         ; PTC Clock Gate Control
SCGC3_PTD:          .equ   3                                         ; PTD Clock Gate Control
SCGC3_PTE:          .equ   4                                         ; PTE Clock Gate Control
SCGC3_PTF:          .equ   5                                         ; PTF Clock Gate Control
SCGC3_KBI1:         .equ   6                                         ; KBI1 Clock Gate Control
SCGC3_KBI2:         .equ   7                                         ; KBI2 Clock Gate Control
; bit position masks
mSCGC3_PTA:         .equ   %00000001
mSCGC3_PTB:         .equ   %00000010
mSCGC3_PTC:         .equ   %00000100
mSCGC3_PTD:         .equ   %00001000
mSCGC3_PTE:         .equ   %00010000
mSCGC3_PTF:         .equ   %00100000
mSCGC3_KBI1:        .equ   %01000000
mSCGC3_KBI2:        .equ   %10000000


;*** SCGC4 - System Clock Gating Control 4 Register; 0xFFFF8289 ***
SCGC4:              .equ   $FFFF8289                                ;*** SCGC4 - System Clock Gating Control 4 Register; 0xFFFF8289 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC4_MTIM1:        .equ   0                                         ; MTIM1 Clock Gate Control
SCGC4_MTIM2:        .equ   1                                         ; MTIM2 Clock Gate Control
SCGC4_MTIM3:        .equ   2                                         ; MTIM3 Clock Gate Control
SCGC4_PDB:          .equ   3                                         ; PDB Clock Gate Control
SCGC4_TPM:          .equ   4                                         ; TPM Clock Gate Control
SCGC4_CRC:          .equ   5                                         ; CRC Clock Gate Control
SCGC4_PM:           .equ   6                                         ; Port Mux Control
; bit position masks
mSCGC4_MTIM1:       .equ   %00000001
mSCGC4_MTIM2:       .equ   %00000010
mSCGC4_MTIM3:       .equ   %00000100
mSCGC4_PDB:         .equ   %00001000
mSCGC4_TPM:         .equ   %00010000
mSCGC4_CRC:         .equ   %00100000
mSCGC4_PM:          .equ   %01000000


;*** SCGC5 - System Clock Gating Control 5 Register; 0xFFFF828A ***
SCGC5:              .equ   $FFFF828A                                ;*** SCGC5 - System Clock Gating Control 5 Register; 0xFFFF828A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC5_FTSR1:        .equ   0                                         ; FTSR1 Clock Gate Control
SCGC5_FTSR2:        .equ   1                                         ; FTSR2 Clock Gate Control
; bit position masks
mSCGC5_FTSR1:       .equ   %00000001
mSCGC5_FTSR2:       .equ   %00000010


;*** SIMCO - SIM Clock Options Register; 0xFFFF828B ***
SIMCO:              .equ   $FFFF828B                                ;*** SIMCO - SIM Clock Options Register; 0xFFFF828B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMCO_CS0:          .equ   0                                         ; CLKOUT Select, bit 0
SIMCO_CS1:          .equ   1                                         ; CLKOUT Select, bit 1
SIMCO_CS2:          .equ   2                                         ; CLKOUT Select, bit 2
SIMCO_CS3:          .equ   3                                         ; CLKOUT Select, bit 3
; bit position masks
mSIMCO_CS0:         .equ   %00000001
mSIMCO_CS1:         .equ   %00000010
mSIMCO_CS2:         .equ   %00000100
mSIMCO_CS3:         .equ   %00001000


;*** SIMIPS1 - Internal Peripheral Select Register 1; 0xFFFF828D ***
SIMIPS1:            .equ   $FFFF828D                                ;*** SIMIPS1 - Internal Peripheral Select Register 1; 0xFFFF828D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMIPS1_MTIM1:      .equ   0                                         ; MTIM1 External Clock Pin Selec
SIMIPS1_MTIM20:     .equ   1                                         ; MTIM2 External Clock Pin Select, bit 0
SIMIPS1_MTIM21:     .equ   2                                         ; MTIM2 External Clock Pin Select, bit 1
SIMIPS1_MTIM30:     .equ   4                                         ; MTIM3 External Clock Pin Selec, bit 0
SIMIPS1_MTIM31:     .equ   5                                         ; MTIM3 External Clock Pin Selec, bit 1
SIMIPS1_TPM:        .equ   7                                         ; TPM External Clock Select Pin
; bit position masks
mSIMIPS1_MTIM1:     .equ   %00000001
mSIMIPS1_MTIM20:    .equ   %00000010
mSIMIPS1_MTIM21:    .equ   %00000100
mSIMIPS1_MTIM30:    .equ   %00010000
mSIMIPS1_MTIM31:    .equ   %00100000
mSIMIPS1_TPM:       .equ   %10000000


;*** SIMIPS2 - Internal Peripheral Select Register 1; 0xFFFF828E ***
SIMIPS2:            .equ   $FFFF828E                                ;*** SIMIPS2 - Internal Peripheral Select Register 1; 0xFFFF828E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMIPS2_MODTX1:     .equ   0                                         ; Modulate TX1
SIMIPS2_MODTX2:     .equ   1                                         ; Modulate TX2
SIMIPS2_MTBASE10:   .equ   2                                         ; SCI1 TX Modulation Time Base Select, bit 0
SIMIPS2_MTBASE11:   .equ   3                                         ; SCI1 TX Modulation Time Base Select, bit 1
SIMIPS2_MTBASE20:   .equ   4                                         ; SCI2 TX Modulation Time Base Select, bit 0
SIMIPS2_MTBASE21:   .equ   5                                         ; SCI2 TX Modulation Time Base Select, bit 1
SIMIPS2_RX1IN:      .equ   6                                         ; SCI1 RX Input Pin Select
SIMIPS2_RX2IN:      .equ   7                                         ; SCI2 RX Input Pin Select
; bit position masks
mSIMIPS2_MODTX1:    .equ   %00000001
mSIMIPS2_MODTX2:    .equ   %00000010
mSIMIPS2_MTBASE10:  .equ   %00000100
mSIMIPS2_MTBASE11:  .equ   %00001000
mSIMIPS2_MTBASE20:  .equ   %00010000
mSIMIPS2_MTBASE21:  .equ   %00100000
mSIMIPS2_RX1IN:     .equ   %01000000
mSIMIPS2_RX2IN:     .equ   %10000000


;*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF82A0 ***
SPMSC1:             .equ   $FFFF82A0                                ;*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF82A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE:        .equ   0                                         ; Bandgap Buffer Enable
SPMSC1_BGBDS:       .equ   1                                         ; Bandgap Buffer Drive Select
SPMSC1_LVDE:        .equ   2                                         ; Low-Voltage Detect Enable
SPMSC1_LVDSE:       .equ   3                                         ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE:       .equ   4                                         ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE:       .equ   5                                         ; Low-Voltage Detect Interrupt Enable
SPMSC1_LVDACK:      .equ   6                                         ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF:        .equ   7                                         ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_BGBE:       .equ   %00000001
mSPMSC1_BGBDS:      .equ   %00000010
mSPMSC1_LVDE:       .equ   %00000100
mSPMSC1_LVDSE:      .equ   %00001000
mSPMSC1_LVDRE:      .equ   %00010000
mSPMSC1_LVDIE:      .equ   %00100000
mSPMSC1_LVDACK:     .equ   %01000000
mSPMSC1_LVDF:       .equ   %10000000


;*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF82A1 ***
SPMSC2:             .equ   $FFFF82A1                                ;*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF82A1 ***
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


;*** SPMSC3 - System Power Management Status and Control 3 Register; 0xFFFF82A3 ***
SPMSC3:             .equ   $FFFF82A3                                ;*** SPMSC3 - System Power Management Status and Control 3 Register; 0xFFFF82A3 ***
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


;*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF82C0 ***
SCI1BD:             .equ   $FFFF82C0                                ;*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF82C0 ***
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


;*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF82C0 ***
SCI1BDH:            .equ   $FFFF82C0                                ;*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF82C0 ***
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


;*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF82C1 ***
SCI1BDL:            .equ   $FFFF82C1                                ;*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF82C1 ***
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


;*** SCI1C1 - SCI1 Control Register 1; 0xFFFF82C2 ***
SCI1C1:             .equ   $FFFF82C2                                ;*** SCI1C1 - SCI1 Control Register 1; 0xFFFF82C2 ***
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


;*** SCI1C2 - SCI1 Control Register 2; 0xFFFF82C3 ***
SCI1C2:             .equ   $FFFF82C3                                ;*** SCI1C2 - SCI1 Control Register 2; 0xFFFF82C3 ***
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


;*** SCI1S1 - SCI1 Status Register 1; 0xFFFF82C4 ***
SCI1S1:             .equ   $FFFF82C4                                ;*** SCI1S1 - SCI1 Status Register 1; 0xFFFF82C4 ***
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


;*** SCI1S2 - SCI1 Status Register 2; 0xFFFF82C5 ***
SCI1S2:             .equ   $FFFF82C5                                ;*** SCI1S2 - SCI1 Status Register 2; 0xFFFF82C5 ***
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


;*** SCI1C3 - SCI1 Control Register 3; 0xFFFF82C6 ***
SCI1C3:             .equ   $FFFF82C6                                ;*** SCI1C3 - SCI1 Control Register 3; 0xFFFF82C6 ***
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


;*** SCI1D - SCI1 Data Register; 0xFFFF82C7 ***
SCI1D:              .equ   $FFFF82C7                                ;*** SCI1D - SCI1 Data Register; 0xFFFF82C7 ***
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


;*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF82E0 ***
SCI2BD:             .equ   $FFFF82E0                                ;*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF82E0 ***
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


;*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF82E0 ***
SCI2BDH:            .equ   $FFFF82E0                                ;*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF82E0 ***
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


;*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF82E1 ***
SCI2BDL:            .equ   $FFFF82E1                                ;*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF82E1 ***
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


;*** SCI2C1 - SCI2 Control Register 1; 0xFFFF82E2 ***
SCI2C1:             .equ   $FFFF82E2                                ;*** SCI2C1 - SCI2 Control Register 1; 0xFFFF82E2 ***
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


;*** SCI2C2 - SCI2 Control Register 2; 0xFFFF82E3 ***
SCI2C2:             .equ   $FFFF82E3                                ;*** SCI2C2 - SCI2 Control Register 2; 0xFFFF82E3 ***
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


;*** SCI2S1 - SCI2 Status Register 1; 0xFFFF82E4 ***
SCI2S1:             .equ   $FFFF82E4                                ;*** SCI2S1 - SCI2 Status Register 1; 0xFFFF82E4 ***
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


;*** SCI2S2 - SCI2 Status Register 2; 0xFFFF82E5 ***
SCI2S2:             .equ   $FFFF82E5                                ;*** SCI2S2 - SCI2 Status Register 2; 0xFFFF82E5 ***
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


;*** SCI2C3 - SCI2 Control Register 3; 0xFFFF82E6 ***
SCI2C3:             .equ   $FFFF82E6                                ;*** SCI2C3 - SCI2 Control Register 3; 0xFFFF82E6 ***
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


;*** SCI2D - SCI2 Data Register; 0xFFFF82E7 ***
SCI2D:              .equ   $FFFF82E7                                ;*** SCI2D - SCI2 Data Register; 0xFFFF82E7 ***
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


;*** SCI3BD - SCI3 Baud Rate Register; 0xFFFF8300 ***
SCI3BD:             .equ   $FFFF8300                                ;*** SCI3BD - SCI3 Baud Rate Register; 0xFFFF8300 ***
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


;*** SCI3BDH - SCI3 Baud Rate Register High; 0xFFFF8300 ***
SCI3BDH:            .equ   $FFFF8300                                ;*** SCI3BDH - SCI3 Baud Rate Register High; 0xFFFF8300 ***
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


;*** SCI3BDL - SCI3 Baud Rate Register Low; 0xFFFF8301 ***
SCI3BDL:            .equ   $FFFF8301                                ;*** SCI3BDL - SCI3 Baud Rate Register Low; 0xFFFF8301 ***
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


;*** SCI3C1 - SCI3 Control Register 1; 0xFFFF8302 ***
SCI3C1:             .equ   $FFFF8302                                ;*** SCI3C1 - SCI3 Control Register 1; 0xFFFF8302 ***
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


;*** SCI3C2 - SCI3 Control Register 2; 0xFFFF8303 ***
SCI3C2:             .equ   $FFFF8303                                ;*** SCI3C2 - SCI3 Control Register 2; 0xFFFF8303 ***
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


;*** SCI3S1 - SCI3 Status Register 1; 0xFFFF8304 ***
SCI3S1:             .equ   $FFFF8304                                ;*** SCI3S1 - SCI3 Status Register 1; 0xFFFF8304 ***
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


;*** SCI3S2 - SCI3 Status Register 2; 0xFFFF8305 ***
SCI3S2:             .equ   $FFFF8305                                ;*** SCI3S2 - SCI3 Status Register 2; 0xFFFF8305 ***
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


;*** SCI3C3 - SCI3 Control Register 3; 0xFFFF8306 ***
SCI3C3:             .equ   $FFFF8306                                ;*** SCI3C3 - SCI3 Control Register 3; 0xFFFF8306 ***
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


;*** SCI3D - SCI3 Data Register; 0xFFFF8307 ***
SCI3D:              .equ   $FFFF8307                                ;*** SCI3D - SCI3 Data Register; 0xFFFF8307 ***
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


;*** SPI1C1 - SPI1 Control Register 1; 0xFFFF8320 ***
SPI1C1:             .equ   $FFFF8320                                ;*** SPI1C1 - SPI1 Control Register 1; 0xFFFF8320 ***
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


;*** SPI1C2 - SPI1 Control Register 2; 0xFFFF8321 ***
SPI1C2:             .equ   $FFFF8321                                ;*** SPI1C2 - SPI1 Control Register 2; 0xFFFF8321 ***
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


;*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF8322 ***
SPI1BR:             .equ   $FFFF8322                                ;*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF8322 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0:        .equ   0                                         ; SPI Baud Rate Divisor Bit 0
SPI1BR_SPR1:        .equ   1                                         ; SPI Baud Rate Divisor Bit 1
SPI1BR_SPR2:        .equ   2                                         ; SPI Baud Rate Divisor Bit 2
SPI1BR_SPR3:        .equ   3                                         ; SPI Baud Rate Divisor Bit 3
SPI1BR_SPPR0:       .equ   4                                         ; SPI Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1:       .equ   5                                         ; SPI Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2:       .equ   6                                         ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0:       .equ   %00000001
mSPI1BR_SPR1:       .equ   %00000010
mSPI1BR_SPR2:       .equ   %00000100
mSPI1BR_SPR3:       .equ   %00001000
mSPI1BR_SPPR0:      .equ   %00010000
mSPI1BR_SPPR1:      .equ   %00100000
mSPI1BR_SPPR2:      .equ   %01000000


;*** SPI1S - SPI1 Status Register; 0xFFFF8323 ***
SPI1S:              .equ   $FFFF8323                                ;*** SPI1S - SPI1 Status Register; 0xFFFF8323 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_RFIFOEF:      .equ   0                                         ; SPI Read FIFO Empty Flag
SPI1S_TXFULLF:      .equ   1                                         ; SPI Transmit FIFO Full Flag
SPI1S_TNEAREF:      .equ   2                                         ; SPI Transmit FIFO Nearly Empty Flag
SPI1S_RNFULLF:      .equ   3                                         ; SPI Receive FIFO Nearly Full Flag
SPI1S_MODF:         .equ   4                                         ; Master Mode Fault Flag
SPI1S_SPTEF:        .equ   5                                         ; SPI Transmit Buffer Empty Flag
SPI1S_SPMF:         .equ   6                                         ; SPI Match Flag
SPI1S_SPRF:         .equ   7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPI1S_RFIFOEF:     .equ   %00000001
mSPI1S_TXFULLF:     .equ   %00000010
mSPI1S_TNEAREF:     .equ   %00000100
mSPI1S_RNFULLF:     .equ   %00001000
mSPI1S_MODF:        .equ   %00010000
mSPI1S_SPTEF:       .equ   %00100000
mSPI1S_SPMF:        .equ   %01000000
mSPI1S_SPRF:        .equ   %10000000


;*** SPI1D16 - SPI1 Data Register; 0xFFFF8324 ***
SPI1D16:            .equ   $FFFF8324                                ;*** SPI1D16 - SPI1 Data Register; 0xFFFF8324 ***


;*** SPI1DH - SPI1 Data Register High; 0xFFFF8324 ***
SPI1DH:             .equ   $FFFF8324                                ;*** SPI1DH - SPI1 Data Register High; 0xFFFF8324 ***


;*** SPI1DL - SPI1 Data Register Low; 0xFFFF8325 ***
SPI1DL:             .equ   $FFFF8325                                ;*** SPI1DL - SPI1 Data Register Low; 0xFFFF8325 ***


;*** SPI1D - SPI1 Data Register Low; 0xFFFF8325 ***
SPI1D:              .equ   $FFFF8325                                ;*** SPI1D - SPI1 Data Register Low; 0xFFFF8325 ***
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


;*** SPI1M - SPI1 Match Register; 0xFFFF8326 ***
SPI1M:              .equ   $FFFF8326                                ;*** SPI1M - SPI1 Match Register; 0xFFFF8326 ***
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


;*** SPI1MH - SPI1 Match Register High; 0xFFFF8326 ***
SPI1MH:             .equ   $FFFF8326                                ;*** SPI1MH - SPI1 Match Register High; 0xFFFF8326 ***
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


;*** SPI1ML - SPI1 Match Register Low; 0xFFFF8327 ***
SPI1ML:             .equ   $FFFF8327                                ;*** SPI1ML - SPI1 Match Register Low; 0xFFFF8327 ***
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


;*** SPI1C3 - SPI1 Control Register 3; 0xFFFF8328 ***
SPI1C3:             .equ   $FFFF8328                                ;*** SPI1C3 - SPI1 Control Register 3; 0xFFFF8328 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C3_FIFOMODE:    .equ   0                                         ; SPI FIFO Mode Enable
SPI1C3_RNFULLIEN:   .equ   1                                         ; Receive FIFO Nearly Full Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPIE in the SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0
SPI1C3_TNEARIEN:    .equ   2                                         ; Transmit FIFO Nearly Empty Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPTIE in the <br/>SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0
SPI1C3_RNFULLF_MARK: .equ   4                                        ; Receive FIFO Nearly Full Water Mark - This bit selects the mark for which RNFULLF flag is asserted
SPI1C3_TNEAREF_MARK: .equ   5                                        ; Transmit FIFO Nearly Empty Water Mark - This bit selects the mark after which TNEAREF flag is asserted
; bit position masks
mSPI1C3_FIFOMODE:   .equ   %00000001
mSPI1C3_RNFULLIEN:  .equ   %00000010
mSPI1C3_TNEARIEN:   .equ   %00000100
mSPI1C3_RNFULLF_MARK: .equ   %00010000
mSPI1C3_TNEAREF_MARK: .equ   %00100000


;*** SPI2C1 - SPI2 Control Register 1; 0xFFFF8340 ***
SPI2C1:             .equ   $FFFF8340                                ;*** SPI2C1 - SPI2 Control Register 1; 0xFFFF8340 ***
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


;*** SPI2C2 - SPI2 Control Register 2; 0xFFFF8341 ***
SPI2C2:             .equ   $FFFF8341                                ;*** SPI2C2 - SPI2 Control Register 2; 0xFFFF8341 ***
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


;*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF8342 ***
SPI2BR:             .equ   $FFFF8342                                ;*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF8342 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2BR_SPR0:        .equ   0                                         ; SPI Baud Rate Divisor Bit 0
SPI2BR_SPR1:        .equ   1                                         ; SPI Baud Rate Divisor Bit 1
SPI2BR_SPR2:        .equ   2                                         ; SPI Baud Rate Divisor Bit 2
SPI2BR_SPR3:        .equ   3                                         ; SPI Baud Rate Divisor Bit 3
SPI2BR_SPPR0:       .equ   4                                         ; SPI Baud Rate Prescale Divisor Bit 0
SPI2BR_SPPR1:       .equ   5                                         ; SPI Baud Rate Prescale Divisor Bit 1
SPI2BR_SPPR2:       .equ   6                                         ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI2BR_SPR0:       .equ   %00000001
mSPI2BR_SPR1:       .equ   %00000010
mSPI2BR_SPR2:       .equ   %00000100
mSPI2BR_SPR3:       .equ   %00001000
mSPI2BR_SPPR0:      .equ   %00010000
mSPI2BR_SPPR1:      .equ   %00100000
mSPI2BR_SPPR2:      .equ   %01000000


;*** SPI2S - SPI2 Status Register; 0xFFFF8343 ***
SPI2S:              .equ   $FFFF8343                                ;*** SPI2S - SPI2 Status Register; 0xFFFF8343 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2S_MODF:         .equ   4                                         ; Master Mode Fault Flag
SPI2S_SPTEF:        .equ   5                                         ; SPI Transmit Buffer Empty Flag
SPI2S_SPRF:         .equ   7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPI2S_MODF:        .equ   %00010000
mSPI2S_SPTEF:       .equ   %00100000
mSPI2S_SPRF:        .equ   %10000000


;*** SPI2D - SPI2 Data Register; 0xFFFF8345 ***
SPI2D:              .equ   $FFFF8345                                ;*** SPI2D - SPI2 Data Register; 0xFFFF8345 ***


;*** SPI3C1 - SPI3 Control Register 1; 0xFFFF8360 ***
SPI3C1:             .equ   $FFFF8360                                ;*** SPI3C1 - SPI3 Control Register 1; 0xFFFF8360 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI3C1_LSBFE:       .equ   0                                         ; LSB First (Shifter Direction)
SPI3C1_SSOE:        .equ   1                                         ; Slave Select Output Enable
SPI3C1_CPHA:        .equ   2                                         ; Clock Phase
SPI3C1_CPOL:        .equ   3                                         ; Clock Polarity
SPI3C1_MSTR:        .equ   4                                         ; Master/Slave Mode Select
SPI3C1_SPTIE:       .equ   5                                         ; SPI Transmit Interrupt Enable
SPI3C1_SPE:         .equ   6                                         ; SPI System Enable
SPI3C1_SPIE:        .equ   7                                         ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI3C1_LSBFE:      .equ   %00000001
mSPI3C1_SSOE:       .equ   %00000010
mSPI3C1_CPHA:       .equ   %00000100
mSPI3C1_CPOL:       .equ   %00001000
mSPI3C1_MSTR:       .equ   %00010000
mSPI3C1_SPTIE:      .equ   %00100000
mSPI3C1_SPE:        .equ   %01000000
mSPI3C1_SPIE:       .equ   %10000000


;*** SPI3C2 - SPI3 Control Register 2; 0xFFFF8361 ***
SPI3C2:             .equ   $FFFF8361                                ;*** SPI3C2 - SPI3 Control Register 2; 0xFFFF8361 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI3C2_SPC0:        .equ   0                                         ; SPI Pin Control 0
SPI3C2_SPISWAI:     .equ   1                                         ; SPI Stop in Wait Mode
SPI3C2_BIDIROE:     .equ   3                                         ; Bidirectional Mode Output Enable
SPI3C2_MODFEN:      .equ   4                                         ; Master Mode-Fault Function Enable
; bit position masks
mSPI3C2_SPC0:       .equ   %00000001
mSPI3C2_SPISWAI:    .equ   %00000010
mSPI3C2_BIDIROE:    .equ   %00001000
mSPI3C2_MODFEN:     .equ   %00010000


;*** SPI3BR - SPI3 Baud Rate Register; 0xFFFF8362 ***
SPI3BR:             .equ   $FFFF8362                                ;*** SPI3BR - SPI3 Baud Rate Register; 0xFFFF8362 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI3BR_SPR0:        .equ   0                                         ; SPI Baud Rate Divisor Bit 0
SPI3BR_SPR1:        .equ   1                                         ; SPI Baud Rate Divisor Bit 1
SPI3BR_SPR2:        .equ   2                                         ; SPI Baud Rate Divisor Bit 2
SPI3BR_SPR3:        .equ   3                                         ; SPI Baud Rate Divisor Bit 3
SPI3BR_SPPR0:       .equ   4                                         ; SPI Baud Rate Prescale Divisor Bit 0
SPI3BR_SPPR1:       .equ   5                                         ; SPI Baud Rate Prescale Divisor Bit 1
SPI3BR_SPPR2:       .equ   6                                         ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI3BR_SPR0:       .equ   %00000001
mSPI3BR_SPR1:       .equ   %00000010
mSPI3BR_SPR2:       .equ   %00000100
mSPI3BR_SPR3:       .equ   %00001000
mSPI3BR_SPPR0:      .equ   %00010000
mSPI3BR_SPPR1:      .equ   %00100000
mSPI3BR_SPPR2:      .equ   %01000000


;*** SPI3S - SPI3 Status Register; 0xFFFF8363 ***
SPI3S:              .equ   $FFFF8363                                ;*** SPI3S - SPI3 Status Register; 0xFFFF8363 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI3S_MODF:         .equ   4                                         ; Master Mode Fault Flag
SPI3S_SPTEF:        .equ   5                                         ; SPI Transmit Buffer Empty Flag
SPI3S_SPRF:         .equ   7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPI3S_MODF:        .equ   %00010000
mSPI3S_SPTEF:       .equ   %00100000
mSPI3S_SPRF:        .equ   %10000000


;*** SPI3D - SPI3 Data Register; 0xFFFF8365 ***
SPI3D:              .equ   $FFFF8365                                ;*** SPI3D - SPI3 Data Register; 0xFFFF8365 ***


;*** IICA1 - IIC Address Register; 0xFFFF8380 ***
IICA1:              .equ   $FFFF8380                                ;*** IICA1 - IIC Address Register; 0xFFFF8380 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA1_AD1:          .equ   1                                         ; Slave Address Bit 1
IICA1_AD2:          .equ   2                                         ; Slave Address Bit 2
IICA1_AD3:          .equ   3                                         ; Slave Address Bit 3
IICA1_AD4:          .equ   4                                         ; Slave Address Bit 4
IICA1_AD5:          .equ   5                                         ; Slave Address Bit 5
IICA1_AD6:          .equ   6                                         ; Slave Address Bit 6
IICA1_AD7:          .equ   7                                         ; Slave Address Bit 7
; bit position masks
mIICA1_AD1:         .equ   %00000010
mIICA1_AD2:         .equ   %00000100
mIICA1_AD3:         .equ   %00001000
mIICA1_AD4:         .equ   %00010000
mIICA1_AD5:         .equ   %00100000
mIICA1_AD6:         .equ   %01000000
mIICA1_AD7:         .equ   %10000000


;*** IICA - IIC Address Register; 0xFFFF8380 ***
IICA:               .equ   $FFFF8380                                ;*** IICA - IIC Address Register; 0xFFFF8380 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA_AD1:           .equ   1                                         ; Slave Address Bit 1
IICA_AD2:           .equ   2                                         ; Slave Address Bit 2
IICA_AD3:           .equ   3                                         ; Slave Address Bit 3
IICA_AD4:           .equ   4                                         ; Slave Address Bit 4
IICA_AD5:           .equ   5                                         ; Slave Address Bit 5
IICA_AD6:           .equ   6                                         ; Slave Address Bit 6
IICA_AD7:           .equ   7                                         ; Slave Address Bit 7
; bit position masks
mIICA_AD1:          .equ   %00000010
mIICA_AD2:          .equ   %00000100
mIICA_AD3:          .equ   %00001000
mIICA_AD4:          .equ   %00010000
mIICA_AD5:          .equ   %00100000
mIICA_AD6:          .equ   %01000000
mIICA_AD7:          .equ   %10000000


;*** IICF - IIC Frequency Divider Register; 0xFFFF8381 ***
IICF:               .equ   $FFFF8381                                ;*** IICF - IIC Frequency Divider Register; 0xFFFF8381 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICF_ICR0:          .equ   0                                         ; IIC Clock Rate Bit 0
IICF_ICR1:          .equ   1                                         ; IIC Clock Rate Bit 1
IICF_ICR2:          .equ   2                                         ; IIC Clock Rate Bit 2
IICF_ICR3:          .equ   3                                         ; IIC Clock Rate Bit 3
IICF_ICR4:          .equ   4                                         ; IIC Clock Rate Bit 4
IICF_ICR5:          .equ   5                                         ; IIC Clock Rate Bit 5
IICF_MULT0:         .equ   6                                         ; Multiplier Factor Bit 0
IICF_MULT1:         .equ   7                                         ; Multiplier Factor Bit 1
; bit position masks
mIICF_ICR0:         .equ   %00000001
mIICF_ICR1:         .equ   %00000010
mIICF_ICR2:         .equ   %00000100
mIICF_ICR3:         .equ   %00001000
mIICF_ICR4:         .equ   %00010000
mIICF_ICR5:         .equ   %00100000
mIICF_MULT0:        .equ   %01000000
mIICF_MULT1:        .equ   %10000000


;*** IICC1 - IIC Control Register 1; 0xFFFF8382 ***
IICC1:              .equ   $FFFF8382                                ;*** IICC1 - IIC Control Register 1; 0xFFFF8382 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC1_RSTA:         .equ   2                                         ; Repeat START
IICC1_TXAK:         .equ   3                                         ; Transmit Acknowledge Enable
IICC1_TX:           .equ   4                                         ; Transmit Mode Select
IICC1_MST:          .equ   5                                         ; Master Mode Select
IICC1_IICIE:        .equ   6                                         ; IIC Interrupt Enable
IICC1_IICEN:        .equ   7                                         ; IIC Enable
; bit position masks
mIICC1_RSTA:        .equ   %00000100
mIICC1_TXAK:        .equ   %00001000
mIICC1_TX:          .equ   %00010000
mIICC1_MST:         .equ   %00100000
mIICC1_IICIE:       .equ   %01000000
mIICC1_IICEN:       .equ   %10000000


;*** IICC - IIC Control Register; 0xFFFF8382 ***
IICC:               .equ   $FFFF8382                                ;*** IICC - IIC Control Register; 0xFFFF8382 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC_RSTA:          .equ   2                                         ; Repeat START
IICC_TXAK:          .equ   3                                         ; Transmit Acknowledge Enable
IICC_TX:            .equ   4                                         ; Transmit Mode Select
IICC_MST:           .equ   5                                         ; Master Mode Select
IICC_IICIE:         .equ   6                                         ; IIC Interrupt Enable
IICC_IICEN:         .equ   7                                         ; IIC Enable
; bit position masks
mIICC_RSTA:         .equ   %00000100
mIICC_TXAK:         .equ   %00001000
mIICC_TX:           .equ   %00010000
mIICC_MST:          .equ   %00100000
mIICC_IICIE:        .equ   %01000000
mIICC_IICEN:        .equ   %10000000


;*** IICS - IIC Status Register; 0xFFFF8383 ***
IICS:               .equ   $FFFF8383                                ;*** IICS - IIC Status Register; 0xFFFF8383 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICS_RXAK:          .equ   0                                         ; Receive Acknowledge
IICS_IICIF:         .equ   1                                         ; IIC Interrupt Flag
IICS_SRW:           .equ   2                                         ; Slave Read/Write
IICS_ARBL:          .equ   4                                         ; Arbitration Lost
IICS_BUSY:          .equ   5                                         ; Bus Busy
IICS_IAAS:          .equ   6                                         ; Addressed as a Slave
IICS_TCF:           .equ   7                                         ; Transfer Complete Flag
; bit position masks
mIICS_RXAK:         .equ   %00000001
mIICS_IICIF:        .equ   %00000010
mIICS_SRW:          .equ   %00000100
mIICS_ARBL:         .equ   %00010000
mIICS_BUSY:         .equ   %00100000
mIICS_IAAS:         .equ   %01000000
mIICS_TCF:          .equ   %10000000


;*** IICD - IIC Data I/O Register; 0xFFFF8384 ***
IICD:               .equ   $FFFF8384                                ;*** IICD - IIC Data I/O Register; 0xFFFF8384 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICD_DATA0:         .equ   0                                         ; IIC Data Bit 0
IICD_DATA1:         .equ   1                                         ; IIC Data Bit 1
IICD_DATA2:         .equ   2                                         ; IIC Data Bit 2
IICD_DATA3:         .equ   3                                         ; IIC Data Bit 3
IICD_DATA4:         .equ   4                                         ; IIC Data Bit 4
IICD_DATA5:         .equ   5                                         ; IIC Data Bit 5
IICD_DATA6:         .equ   6                                         ; IIC Data Bit 6
IICD_DATA7:         .equ   7                                         ; IIC Data Bit 7
; bit position masks
mIICD_DATA0:        .equ   %00000001
mIICD_DATA1:        .equ   %00000010
mIICD_DATA2:        .equ   %00000100
mIICD_DATA3:        .equ   %00001000
mIICD_DATA4:        .equ   %00010000
mIICD_DATA5:        .equ   %00100000
mIICD_DATA6:        .equ   %01000000
mIICD_DATA7:        .equ   %10000000


;*** IICC2 - IIC Control Register 2; 0xFFFF8385 ***
IICC2:              .equ   $FFFF8385                                ;*** IICC2 - IIC Control Register 2; 0xFFFF8385 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC2_AD8:          .equ   0                                         ; Slave Address Bit 8
IICC2_AD9:          .equ   1                                         ; Slave Address Bit 9
IICC2_AD10:         .equ   2                                         ; Slave Address Bit 10
IICC2_ADEXT:        .equ   6                                         ; Address Extension
IICC2_GCAEN:        .equ   7                                         ; General Call Address Enable
; bit position masks
mIICC2_AD8:         .equ   %00000001
mIICC2_AD9:         .equ   %00000010
mIICC2_AD10:        .equ   %00000100
mIICC2_ADEXT:       .equ   %01000000
mIICC2_GCAEN:       .equ   %10000000


;*** IICSMB - SMBus Control and Status Register; 0xFFFF8386 ***
IICSMB:             .equ   $FFFF8386                                ;*** IICSMB - SMBus Control and Status Register; 0xFFFF8386 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSMB_SHTF:        .equ   2                                         ; SCL High Timeout Flag
IICSMB_SLTF:        .equ   3                                         ; SCL Low Timeout Flag
IICSMB_TCKSEL:      .equ   4                                         ; Time Out Counter Clock Select
IICSMB_SIICAEN:     .equ   5                                         ; Second IIC Address Enable
IICSMB_ALERTEN:     .equ   6                                         ; SMBus Alert Response Address Enable
IICSMB_FACK:        .equ   7                                         ; Fast NACK/ACK enable
; bit position masks
mIICSMB_SHTF:       .equ   %00000100
mIICSMB_SLTF:       .equ   %00001000
mIICSMB_TCKSEL:     .equ   %00010000
mIICSMB_SIICAEN:    .equ   %00100000
mIICSMB_ALERTEN:    .equ   %01000000
mIICSMB_FACK:       .equ   %10000000


;*** IICA2 - IIC Address Register 2; 0xFFFF8387 ***
IICA2:              .equ   $FFFF8387                                ;*** IICA2 - IIC Address Register 2; 0xFFFF8387 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA2_SAD1:         .equ   1                                         ; SMBus Address Bit 1
IICA2_SAD2:         .equ   2                                         ; SMBus Address Bit 2
IICA2_SAD3:         .equ   3                                         ; SMBus Address Bit 3
IICA2_SAD4:         .equ   4                                         ; SMBus Address Bit 4
IICA2_SAD5:         .equ   5                                         ; SMBus Address Bit 5
IICA2_SAD6:         .equ   6                                         ; SMBus Address Bit 6
IICA2_SAD7:         .equ   7                                         ; SMBus Address Bit 7
; bit position masks
mIICA2_SAD1:        .equ   %00000010
mIICA2_SAD2:        .equ   %00000100
mIICA2_SAD3:        .equ   %00001000
mIICA2_SAD4:        .equ   %00010000
mIICA2_SAD5:        .equ   %00100000
mIICA2_SAD6:        .equ   %01000000
mIICA2_SAD7:        .equ   %10000000


;*** IICSLT - IIC SCL Low Time Out register; 0xFFFF8388 ***
IICSLT:             .equ   $FFFF8388                                ;*** IICSLT - IIC SCL Low Time Out register; 0xFFFF8388 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSLT_SSLT0:       .equ   0                                         ; SCL Low Time Out Bits, bit 0
IICSLT_SSLT1:       .equ   1                                         ; SCL Low Time Out Bits, bit 1
IICSLT_SSLT2:       .equ   2                                         ; SCL Low Time Out Bits, bit 2
IICSLT_SSLT3:       .equ   3                                         ; SCL Low Time Out Bits, bit 3
IICSLT_SSLT4:       .equ   4                                         ; SCL Low Time Out Bits, bit 4
IICSLT_SSLT5:       .equ   5                                         ; SCL Low Time Out Bits, bit 5
IICSLT_SSLT6:       .equ   6                                         ; SCL Low Time Out Bits, bit 6
IICSLT_SSLT7:       .equ   7                                         ; SCL Low Time Out Bits, bit 7
IICSLT_SSLT8:       .equ   8                                         ; SCL Low Time Out Bits, bit 8
IICSLT_SSLT9:       .equ   9                                         ; SCL Low Time Out Bits, bit 9
IICSLT_SSLT10:      .equ   10                                        ; SCL Low Time Out Bits, bit 10
IICSLT_SSLT11:      .equ   11                                        ; SCL Low Time Out Bits, bit 11
IICSLT_SSLT12:      .equ   12                                        ; SCL Low Time Out Bits, bit 12
IICSLT_SSLT13:      .equ   13                                        ; SCL Low Time Out Bits, bit 13
IICSLT_SSLT14:      .equ   14                                        ; SCL Low Time Out Bits, bit 14
IICSLT_SSLT15:      .equ   15                                        ; SCL Low Time Out Bits, bit 15
; bit position masks
mIICSLT_SSLT0:      .equ   %00000001
mIICSLT_SSLT1:      .equ   %00000010
mIICSLT_SSLT2:      .equ   %00000100
mIICSLT_SSLT3:      .equ   %00001000
mIICSLT_SSLT4:      .equ   %00010000
mIICSLT_SSLT5:      .equ   %00100000
mIICSLT_SSLT6:      .equ   %01000000
mIICSLT_SSLT7:      .equ   %10000000
mIICSLT_SSLT8:      .equ   %100000000
mIICSLT_SSLT9:      .equ   %1000000000
mIICSLT_SSLT10:     .equ   %10000000000
mIICSLT_SSLT11:     .equ   %100000000000
mIICSLT_SSLT12:     .equ   %1000000000000
mIICSLT_SSLT13:     .equ   %10000000000000
mIICSLT_SSLT14:     .equ   %100000000000000
mIICSLT_SSLT15:     .equ   %1000000000000000


;*** IICSLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8388 ***
IICSLTH:            .equ   $FFFF8388                                ;*** IICSLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8388 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSLTH_SSLT8:      .equ   0                                         ; SCL Low Time Out Bit 8
IICSLTH_SSLT9:      .equ   1                                         ; SCL Low Time Out Bit 9
IICSLTH_SSLT10:     .equ   2                                         ; SCL Low Time Out Bit 10
IICSLTH_SSLT11:     .equ   3                                         ; SCL Low Time Out Bit 11
IICSLTH_SSLT12:     .equ   4                                         ; SCL Low Time Out Bit 12
IICSLTH_SSLT13:     .equ   5                                         ; SCL Low Time Out Bit 13
IICSLTH_SSLT14:     .equ   6                                         ; SCL Low Time Out Bit 14
IICSLTH_SSLT15:     .equ   7                                         ; SCL Low Time Out Bit 15
; bit position masks
mIICSLTH_SSLT8:     .equ   %00000001
mIICSLTH_SSLT9:     .equ   %00000010
mIICSLTH_SSLT10:    .equ   %00000100
mIICSLTH_SSLT11:    .equ   %00001000
mIICSLTH_SSLT12:    .equ   %00010000
mIICSLTH_SSLT13:    .equ   %00100000
mIICSLTH_SSLT14:    .equ   %01000000
mIICSLTH_SSLT15:    .equ   %10000000


;*** IICSLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8389 ***
IICSLTL:            .equ   $FFFF8389                                ;*** IICSLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8389 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSLTL_SSLT0:      .equ   0                                         ; SCL Low Time Out Bits, bit 0
IICSLTL_SSLT1:      .equ   1                                         ; SCL Low Time Out Bits, bit 1
IICSLTL_SSLT2:      .equ   2                                         ; SCL Low Time Out Bits, bit 2
IICSLTL_SSLT3:      .equ   3                                         ; SCL Low Time Out Bits, bit 3
IICSLTL_SSLT4:      .equ   4                                         ; SCL Low Time Out Bits, bit 4
IICSLTL_SSLT5:      .equ   5                                         ; SCL Low Time Out Bits, bit 5
IICSLTL_SSLT6:      .equ   6                                         ; SCL Low Time Out Bits, bit 6
IICSLTL_SSLT7:      .equ   7                                         ; SCL Low Time Out Bits, bit 7
; bit position masks
mIICSLTL_SSLT0:     .equ   %00000001
mIICSLTL_SSLT1:     .equ   %00000010
mIICSLTL_SSLT2:     .equ   %00000100
mIICSLTL_SSLT3:     .equ   %00001000
mIICSLTL_SSLT4:     .equ   %00010000
mIICSLTL_SSLT5:     .equ   %00100000
mIICSLTL_SSLT6:     .equ   %01000000
mIICSLTL_SSLT7:     .equ   %10000000


;*** IICFLT - IIC Filter register; 0xFFFF838A ***
IICFLT:             .equ   $FFFF838A                                ;*** IICFLT - IIC Filter register; 0xFFFF838A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICFLT_FLT0:        .equ   0                                         ; Filter value bit 0
IICFLT_FLT1:        .equ   1                                         ; Filter value bit 1
IICFLT_FLT2:        .equ   2                                         ; Filter value bit 2
IICFLT_FLT3:        .equ   3                                         ; Filter value bit 3
; bit position masks
mIICFLT_FLT0:       .equ   %00000001
mIICFLT_FLT1:       .equ   %00000010
mIICFLT_FLT2:       .equ   %00000100
mIICFLT_FLT3:       .equ   %00001000


;*** VREFTRM - VREF Trim Register; 0xFFFF83C0 ***
VREFTRM:            .equ   $FFFF83C0                                ;*** VREFTRM - VREF Trim Register; 0xFFFF83C0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREFTRM_TRM0:       .equ   0                                         ; Trim Bits, bit 0
VREFTRM_TRM1:       .equ   1                                         ; Trim Bits, bit 1
VREFTRM_TRM2:       .equ   2                                         ; Trim Bits, bit 2
VREFTRM_TRM3:       .equ   3                                         ; Trim Bits, bit 3
VREFTRM_TRM4:       .equ   4                                         ; Trim Bits, bit 4
VREFTRM_TRM5:       .equ   5                                         ; Trim Bits, bit 5
VREFTRM_TRM6:       .equ   6                                         ; Trim Bits, bit 6
VREFTRM_TRM7:       .equ   7                                         ; Trim Bits, bit 7
; bit position masks
mVREFTRM_TRM0:      .equ   %00000001
mVREFTRM_TRM1:      .equ   %00000010
mVREFTRM_TRM2:      .equ   %00000100
mVREFTRM_TRM3:      .equ   %00001000
mVREFTRM_TRM4:      .equ   %00010000
mVREFTRM_TRM5:      .equ   %00100000
mVREFTRM_TRM6:      .equ   %01000000
mVREFTRM_TRM7:      .equ   %10000000


;*** VREFSC - VREF Control Register; 0xFFFF83C1 ***
VREFSC:             .equ   $FFFF83C1                                ;*** VREFSC - VREF Control Register; 0xFFFF83C1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREFSC_MODE0:       .equ   0                                         ; Mode selection, bit 0
VREFSC_MODE1:       .equ   1                                         ; Mode selection, bit 1
VREFSC_VREFST:      .equ   2                                         ; Internal Voltage Reference Stable
VREFSC_VREFEN:      .equ   7                                         ; Internal Voltage Reference Enable
; bit position masks
mVREFSC_MODE0:      .equ   %00000001
mVREFSC_MODE1:      .equ   %00000010
mVREFSC_VREFST:     .equ   %00000100
mVREFSC_VREFEN:     .equ   %10000000


;*** ADC1SC1A - Status and Control Register 1A; 0xFFFF8400 ***
ADC1SC1A:           .equ   $FFFF8400                                ;*** ADC1SC1A - Status and Control Register 1A; 0xFFFF8400 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC1A_ADCHA0:    .equ   0                                         ; Input Channel Select Bit 0
ADC1SC1A_ADCHA1:    .equ   1                                         ; Input Channel Select Bit 1
ADC1SC1A_ADCHA2:    .equ   2                                         ; Input Channel Select Bit 2
ADC1SC1A_ADCHA3:    .equ   3                                         ; Input Channel Select Bit 3
ADC1SC1A_ADCHA4:    .equ   4                                         ; Input Channel Select Bit 4
ADC1SC1A_DIFFA:     .equ   5                                         ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADC1SC1A_AIENA:     .equ   6                                         ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA is high, an interrupt is asserted
ADC1SC1A_COCOA:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC1SC1A_ADCHA0:   .equ   %00000001
mADC1SC1A_ADCHA1:   .equ   %00000010
mADC1SC1A_ADCHA2:   .equ   %00000100
mADC1SC1A_ADCHA3:   .equ   %00001000
mADC1SC1A_ADCHA4:   .equ   %00010000
mADC1SC1A_DIFFA:    .equ   %00100000
mADC1SC1A_AIENA:    .equ   %01000000
mADC1SC1A_COCOA:    .equ   %10000000


;*** ADC1SC1B - Status and Control Register 1B; 0xFFFF8401 ***
ADC1SC1B:           .equ   $FFFF8401                                ;*** ADC1SC1B - Status and Control Register 1B; 0xFFFF8401 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC1B_ADCHB0:    .equ   0                                         ; Input Channel Select Bit 0
ADC1SC1B_ADCHB1:    .equ   1                                         ; Input Channel Select Bit 1
ADC1SC1B_ADCHB2:    .equ   2                                         ; Input Channel Select Bit 2
ADC1SC1B_ADCHB3:    .equ   3                                         ; Input Channel Select Bit 3
ADC1SC1B_ADCHB4:    .equ   4                                         ; Input Channel Select Bit 4
ADC1SC1B_DIFFB:     .equ   5                                         ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADC1SC1B_AIENB:     .equ   6                                         ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB is high, an interrupt is asserted
ADC1SC1B_COCOB:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC1SC1B_ADCHB0:   .equ   %00000001
mADC1SC1B_ADCHB1:   .equ   %00000010
mADC1SC1B_ADCHB2:   .equ   %00000100
mADC1SC1B_ADCHB3:   .equ   %00001000
mADC1SC1B_ADCHB4:   .equ   %00010000
mADC1SC1B_DIFFB:    .equ   %00100000
mADC1SC1B_AIENB:    .equ   %01000000
mADC1SC1B_COCOB:    .equ   %10000000


;*** ADC1CFG1 - Configuration Register 1; 0xFFFF8402 ***
ADC1CFG1:           .equ   $FFFF8402                                ;*** ADC1CFG1 - Configuration Register 1; 0xFFFF8402 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CFG1_ADICLK0:   .equ   0                                         ; Input Clock Select Bit 0
ADC1CFG1_ADICLK1:   .equ   1                                         ; Input Clock Select Bit 1
ADC1CFG1_MODE0:     .equ   2                                         ; Conversion Mode Selection Bit 0
ADC1CFG1_MODE1:     .equ   3                                         ; Conversion Mode Selection Bit 1
ADC1CFG1_ADLSMP:    .equ   4                                         ; Long Sample Time Configuration
ADC1CFG1_ADIV0:     .equ   5                                         ; Clock Divide Select Bit 0
ADC1CFG1_ADIV1:     .equ   6                                         ; Clock Divide Select Bit 1
ADC1CFG1_ADLPC:     .equ   7                                         ; Low Power Configuration
; bit position masks
mADC1CFG1_ADICLK0:  .equ   %00000001
mADC1CFG1_ADICLK1:  .equ   %00000010
mADC1CFG1_MODE0:    .equ   %00000100
mADC1CFG1_MODE1:    .equ   %00001000
mADC1CFG1_ADLSMP:   .equ   %00010000
mADC1CFG1_ADIV0:    .equ   %00100000
mADC1CFG1_ADIV1:    .equ   %01000000
mADC1CFG1_ADLPC:    .equ   %10000000


;*** ADC1CFG2 - Configuration Register 2; 0xFFFF8403 ***
ADC1CFG2:           .equ   $FFFF8403                                ;*** ADC1CFG2 - Configuration Register 2; 0xFFFF8403 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CFG2_ADLSTS0:   .equ   0                                         ; Long Sample Time Select Bit 0
ADC1CFG2_ADLSTS1:   .equ   1                                         ; Long Sample Time Select Bit 1
ADC1CFG2_ADHSC:     .equ   2                                         ; High Speed Configuration
ADC1CFG2_ADACKEN:   .equ   3                                         ; Asynchronous Clock Output Enable
; bit position masks
mADC1CFG2_ADLSTS0:  .equ   %00000001
mADC1CFG2_ADLSTS1:  .equ   %00000010
mADC1CFG2_ADHSC:    .equ   %00000100
mADC1CFG2_ADACKEN:  .equ   %00001000


;*** ADC1RA - Data Result Register A; 0xFFFF8404 ***
ADC1RA:             .equ   $FFFF8404                                ;*** ADC1RA - Data Result Register A; 0xFFFF8404 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RA_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC1RA_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC1RA_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC1RA_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC1RA_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC1RA_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC1RA_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC1RA_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC1RA_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC1RA_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC1RA_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC1RA_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC1RA_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC1RA_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC1RA_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC1RA_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC1RA_D0:         .equ   %00000001
mADC1RA_D1:         .equ   %00000010
mADC1RA_D2:         .equ   %00000100
mADC1RA_D3:         .equ   %00001000
mADC1RA_D4:         .equ   %00010000
mADC1RA_D5:         .equ   %00100000
mADC1RA_D6:         .equ   %01000000
mADC1RA_D7:         .equ   %10000000
mADC1RA_D8:         .equ   %100000000
mADC1RA_D9:         .equ   %1000000000
mADC1RA_D10:        .equ   %10000000000
mADC1RA_D11:        .equ   %100000000000
mADC1RA_D12:        .equ   %1000000000000
mADC1RA_D13:        .equ   %10000000000000
mADC1RA_D14:        .equ   %100000000000000
mADC1RA_D15:        .equ   %1000000000000000


;*** ADC1RHA - Data Result High Register A; 0xFFFF8404 ***
ADC1RHA:            .equ   $FFFF8404                                ;*** ADC1RHA - Data Result High Register A; 0xFFFF8404 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RHA_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC1RHA_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC1RHA_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC1RHA_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC1RHA_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC1RHA_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC1RHA_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC1RHA_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC1RHA_D8:        .equ   %00000001
mADC1RHA_D9:        .equ   %00000010
mADC1RHA_D10:       .equ   %00000100
mADC1RHA_D11:       .equ   %00001000
mADC1RHA_D12:       .equ   %00010000
mADC1RHA_D13:       .equ   %00100000
mADC1RHA_D14:       .equ   %01000000
mADC1RHA_D15:       .equ   %10000000


;*** ADC1RLA - Data Result Low Register A; 0xFFFF8405 ***
ADC1RLA:            .equ   $FFFF8405                                ;*** ADC1RLA - Data Result Low Register A; 0xFFFF8405 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RLA_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC1RLA_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC1RLA_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC1RLA_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC1RLA_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC1RLA_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC1RLA_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC1RLA_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC1RLA_D0:        .equ   %00000001
mADC1RLA_D1:        .equ   %00000010
mADC1RLA_D2:        .equ   %00000100
mADC1RLA_D3:        .equ   %00001000
mADC1RLA_D4:        .equ   %00010000
mADC1RLA_D5:        .equ   %00100000
mADC1RLA_D6:        .equ   %01000000
mADC1RLA_D7:        .equ   %10000000


;*** ADC1RB - Data Result Register B; 0xFFFF8406 ***
ADC1RB:             .equ   $FFFF8406                                ;*** ADC1RB - Data Result Register B; 0xFFFF8406 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RB_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC1RB_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC1RB_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC1RB_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC1RB_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC1RB_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC1RB_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC1RB_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC1RB_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC1RB_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC1RB_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC1RB_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC1RB_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC1RB_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC1RB_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC1RB_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC1RB_D0:         .equ   %00000001
mADC1RB_D1:         .equ   %00000010
mADC1RB_D2:         .equ   %00000100
mADC1RB_D3:         .equ   %00001000
mADC1RB_D4:         .equ   %00010000
mADC1RB_D5:         .equ   %00100000
mADC1RB_D6:         .equ   %01000000
mADC1RB_D7:         .equ   %10000000
mADC1RB_D8:         .equ   %100000000
mADC1RB_D9:         .equ   %1000000000
mADC1RB_D10:        .equ   %10000000000
mADC1RB_D11:        .equ   %100000000000
mADC1RB_D12:        .equ   %1000000000000
mADC1RB_D13:        .equ   %10000000000000
mADC1RB_D14:        .equ   %100000000000000
mADC1RB_D15:        .equ   %1000000000000000


;*** ADC1RHB - Data Result High Register B; 0xFFFF8406 ***
ADC1RHB:            .equ   $FFFF8406                                ;*** ADC1RHB - Data Result High Register B; 0xFFFF8406 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RHB_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC1RHB_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC1RHB_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC1RHB_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC1RHB_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC1RHB_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC1RHB_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC1RHB_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC1RHB_D8:        .equ   %00000001
mADC1RHB_D9:        .equ   %00000010
mADC1RHB_D10:       .equ   %00000100
mADC1RHB_D11:       .equ   %00001000
mADC1RHB_D12:       .equ   %00010000
mADC1RHB_D13:       .equ   %00100000
mADC1RHB_D14:       .equ   %01000000
mADC1RHB_D15:       .equ   %10000000


;*** ADC1RLB - Data Result Low Register B; 0xFFFF8407 ***
ADC1RLB:            .equ   $FFFF8407                                ;*** ADC1RLB - Data Result Low Register B; 0xFFFF8407 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RLB_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC1RLB_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC1RLB_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC1RLB_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC1RLB_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC1RLB_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC1RLB_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC1RLB_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC1RLB_D0:        .equ   %00000001
mADC1RLB_D1:        .equ   %00000010
mADC1RLB_D2:        .equ   %00000100
mADC1RLB_D3:        .equ   %00001000
mADC1RLB_D4:        .equ   %00010000
mADC1RLB_D5:        .equ   %00100000
mADC1RLB_D6:        .equ   %01000000
mADC1RLB_D7:        .equ   %10000000


;*** ADC1CV1 - Compare Value 1 Register; 0xFFFF8408 ***
ADC1CV1:            .equ   $FFFF8408                                ;*** ADC1CV1 - Compare Value 1 Register; 0xFFFF8408 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV1_CV10:       .equ   0                                         ; Compare Function Value 0
ADC1CV1_CV11:       .equ   1                                         ; Compare Function Value 1
ADC1CV1_CV12:       .equ   2                                         ; Compare Function Value 2
ADC1CV1_CV13:       .equ   3                                         ; Compare Function Value 3
ADC1CV1_CV14:       .equ   4                                         ; Compare Function Value 4
ADC1CV1_CV15:       .equ   5                                         ; Compare Function Value 5
ADC1CV1_CV16:       .equ   6                                         ; Compare Function Value 6
ADC1CV1_CV17:       .equ   7                                         ; Compare Function Value 7
ADC1CV1_CV18:       .equ   8                                         ; Compare Function Value 8
ADC1CV1_CV19:       .equ   9                                         ; Compare Function Value 9
ADC1CV1_CV110:      .equ   10                                        ; Compare Function Value 10
ADC1CV1_CV111:      .equ   11                                        ; Compare Function Value 11
ADC1CV1_CV112:      .equ   12                                        ; Compare Function Value 12
ADC1CV1_CV113:      .equ   13                                        ; Compare Function Value 13
ADC1CV1_CV114:      .equ   14                                        ; Compare Function Value 14
ADC1CV1_CV115:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC1CV1_CV10:      .equ   %00000001
mADC1CV1_CV11:      .equ   %00000010
mADC1CV1_CV12:      .equ   %00000100
mADC1CV1_CV13:      .equ   %00001000
mADC1CV1_CV14:      .equ   %00010000
mADC1CV1_CV15:      .equ   %00100000
mADC1CV1_CV16:      .equ   %01000000
mADC1CV1_CV17:      .equ   %10000000
mADC1CV1_CV18:      .equ   %100000000
mADC1CV1_CV19:      .equ   %1000000000
mADC1CV1_CV110:     .equ   %10000000000
mADC1CV1_CV111:     .equ   %100000000000
mADC1CV1_CV112:     .equ   %1000000000000
mADC1CV1_CV113:     .equ   %10000000000000
mADC1CV1_CV114:     .equ   %100000000000000
mADC1CV1_CV115:     .equ   %1000000000000000


;*** ADC1CV1H - Compare Value 1 High Register; 0xFFFF8408 ***
ADC1CV1H:           .equ   $FFFF8408                                ;*** ADC1CV1H - Compare Value 1 High Register; 0xFFFF8408 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV1H_CV18:      .equ   0                                         ; Compare Function Value 8
ADC1CV1H_CV19:      .equ   1                                         ; Compare Function Value 9
ADC1CV1H_CV110:     .equ   2                                         ; Compare Function Value 10
ADC1CV1H_CV111:     .equ   3                                         ; Compare Function Value 11
ADC1CV1H_CV112:     .equ   4                                         ; Compare Function Value 12
ADC1CV1H_CV113:     .equ   5                                         ; Compare Function Value 13
ADC1CV1H_CV114:     .equ   6                                         ; Compare Function Value 14
ADC1CV1H_CV115:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC1CV1H_CV18:     .equ   %00000001
mADC1CV1H_CV19:     .equ   %00000010
mADC1CV1H_CV110:    .equ   %00000100
mADC1CV1H_CV111:    .equ   %00001000
mADC1CV1H_CV112:    .equ   %00010000
mADC1CV1H_CV113:    .equ   %00100000
mADC1CV1H_CV114:    .equ   %01000000
mADC1CV1H_CV115:    .equ   %10000000


;*** ADC1CV1L - Compare Value 1 Low Register; 0xFFFF8409 ***
ADC1CV1L:           .equ   $FFFF8409                                ;*** ADC1CV1L - Compare Value 1 Low Register; 0xFFFF8409 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV1L_CV10:      .equ   0                                         ; Compare Function Value 0
ADC1CV1L_CV11:      .equ   1                                         ; Compare Function Value 1
ADC1CV1L_CV12:      .equ   2                                         ; Compare Function Value 2
ADC1CV1L_CV13:      .equ   3                                         ; Compare Function Value 3
ADC1CV1L_CV14:      .equ   4                                         ; Compare Function Value 4
ADC1CV1L_CV15:      .equ   5                                         ; Compare Function Value 5
ADC1CV1L_CV16:      .equ   6                                         ; Compare Function Value 6
ADC1CV1L_CV17:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC1CV1L_CV10:     .equ   %00000001
mADC1CV1L_CV11:     .equ   %00000010
mADC1CV1L_CV12:     .equ   %00000100
mADC1CV1L_CV13:     .equ   %00001000
mADC1CV1L_CV14:     .equ   %00010000
mADC1CV1L_CV15:     .equ   %00100000
mADC1CV1L_CV16:     .equ   %01000000
mADC1CV1L_CV17:     .equ   %10000000


;*** ADC1CV2 - Compare Value 2 Register; 0xFFFF840A ***
ADC1CV2:            .equ   $FFFF840A                                ;*** ADC1CV2 - Compare Value 2 Register; 0xFFFF840A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV2_CV20:       .equ   0                                         ; Compare Function Value 0
ADC1CV2_CV21:       .equ   1                                         ; Compare Function Value 1
ADC1CV2_CV22:       .equ   2                                         ; Compare Function Value 2
ADC1CV2_CV23:       .equ   3                                         ; Compare Function Value 3
ADC1CV2_CV24:       .equ   4                                         ; Compare Function Value 4
ADC1CV2_CV25:       .equ   5                                         ; Compare Function Value 5
ADC1CV2_CV26:       .equ   6                                         ; Compare Function Value 6
ADC1CV2_CV27:       .equ   7                                         ; Compare Function Value 7
ADC1CV2_CV28:       .equ   8                                         ; Compare Function Value 8
ADC1CV2_CV29:       .equ   9                                         ; Compare Function Value 9
ADC1CV2_CV210:      .equ   10                                        ; Compare Function Value 10
ADC1CV2_CV211:      .equ   11                                        ; Compare Function Value 11
ADC1CV2_CV212:      .equ   12                                        ; Compare Function Value 12
ADC1CV2_CV213:      .equ   13                                        ; Compare Function Value 13
ADC1CV2_CV214:      .equ   14                                        ; Compare Function Value 14
ADC1CV2_CV215:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC1CV2_CV20:      .equ   %00000001
mADC1CV2_CV21:      .equ   %00000010
mADC1CV2_CV22:      .equ   %00000100
mADC1CV2_CV23:      .equ   %00001000
mADC1CV2_CV24:      .equ   %00010000
mADC1CV2_CV25:      .equ   %00100000
mADC1CV2_CV26:      .equ   %01000000
mADC1CV2_CV27:      .equ   %10000000
mADC1CV2_CV28:      .equ   %100000000
mADC1CV2_CV29:      .equ   %1000000000
mADC1CV2_CV210:     .equ   %10000000000
mADC1CV2_CV211:     .equ   %100000000000
mADC1CV2_CV212:     .equ   %1000000000000
mADC1CV2_CV213:     .equ   %10000000000000
mADC1CV2_CV214:     .equ   %100000000000000
mADC1CV2_CV215:     .equ   %1000000000000000


;*** ADC1CV2H - Compare Value 2 High Register; 0xFFFF840A ***
ADC1CV2H:           .equ   $FFFF840A                                ;*** ADC1CV2H - Compare Value 2 High Register; 0xFFFF840A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV2H_CV28:      .equ   0                                         ; Compare Function Value 8
ADC1CV2H_CV29:      .equ   1                                         ; Compare Function Value 9
ADC1CV2H_CV210:     .equ   2                                         ; Compare Function Value 10
ADC1CV2H_CV211:     .equ   3                                         ; Compare Function Value 11
ADC1CV2H_CV212:     .equ   4                                         ; Compare Function Value 12
ADC1CV2H_CV213:     .equ   5                                         ; Compare Function Value 13
ADC1CV2H_CV214:     .equ   6                                         ; Compare Function Value 14
ADC1CV2H_CV215:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC1CV2H_CV28:     .equ   %00000001
mADC1CV2H_CV29:     .equ   %00000010
mADC1CV2H_CV210:    .equ   %00000100
mADC1CV2H_CV211:    .equ   %00001000
mADC1CV2H_CV212:    .equ   %00010000
mADC1CV2H_CV213:    .equ   %00100000
mADC1CV2H_CV214:    .equ   %01000000
mADC1CV2H_CV215:    .equ   %10000000


;*** ADC1CV2L - Compare Value 2 Low Register; 0xFFFF840B ***
ADC1CV2L:           .equ   $FFFF840B                                ;*** ADC1CV2L - Compare Value 2 Low Register; 0xFFFF840B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV2L_CV20:      .equ   0                                         ; Compare Function Value 0
ADC1CV2L_CV21:      .equ   1                                         ; Compare Function Value 1
ADC1CV2L_CV22:      .equ   2                                         ; Compare Function Value 2
ADC1CV2L_CV23:      .equ   3                                         ; Compare Function Value 3
ADC1CV2L_CV24:      .equ   4                                         ; Compare Function Value 4
ADC1CV2L_CV25:      .equ   5                                         ; Compare Function Value 5
ADC1CV2L_CV26:      .equ   6                                         ; Compare Function Value 6
ADC1CV2L_CV27:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC1CV2L_CV20:     .equ   %00000001
mADC1CV2L_CV21:     .equ   %00000010
mADC1CV2L_CV22:     .equ   %00000100
mADC1CV2L_CV23:     .equ   %00001000
mADC1CV2L_CV24:     .equ   %00010000
mADC1CV2L_CV25:     .equ   %00100000
mADC1CV2L_CV26:     .equ   %01000000
mADC1CV2L_CV27:     .equ   %10000000


;*** ADC1SC2 - Status and Control Register 2; 0xFFFF840C ***
ADC1SC2:            .equ   $FFFF840C                                ;*** ADC1SC2 - Status and Control Register 2; 0xFFFF840C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC2_REFSEL0:    .equ   0                                         ; Voltage Reference Selection, bit 0
ADC1SC2_REFSEL1:    .equ   1                                         ; Voltage Reference Selection, bit 1
ADC1SC2_ACREN:      .equ   3                                         ; Unused
ADC1SC2_ACFGT:      .equ   4                                         ; Compare Function Greater Than Enable
ADC1SC2_ACFE:       .equ   5                                         ; Compare Function Enable - ACFE is used to enable the compare function
ADC1SC2_ADTRG:      .equ   6                                         ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion
ADC1SC2_ADACT:      .equ   7                                         ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted
; bit position masks
mADC1SC2_REFSEL0:   .equ   %00000001
mADC1SC2_REFSEL1:   .equ   %00000010
mADC1SC2_ACREN:     .equ   %00001000
mADC1SC2_ACFGT:     .equ   %00010000
mADC1SC2_ACFE:      .equ   %00100000
mADC1SC2_ADTRG:     .equ   %01000000
mADC1SC2_ADACT:     .equ   %10000000


;*** ADC1SC3 - Status and Control Register 3; 0xFFFF840D ***
ADC1SC3:            .equ   $FFFF840D                                ;*** ADC1SC3 - Status and Control Register 3; 0xFFFF840D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC3_AVGS0:      .equ   0                                         ; Hardware Average select, bit 0
ADC1SC3_AVGS1:      .equ   1                                         ; Hardware Average select, bit 1
ADC1SC3_AVGE:       .equ   2                                         ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADC1SC3_ADCO:       .equ   3                                         ; Continuous Conversion Enable - ADCO enables continuous conversions
ADC1SC3_CALF:       .equ   6                                         ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC1SC3_CAL:        .equ   7                                         ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADC1SC3_AVGS0:     .equ   %00000001
mADC1SC3_AVGS1:     .equ   %00000010
mADC1SC3_AVGE:      .equ   %00000100
mADC1SC3_ADCO:      .equ   %00001000
mADC1SC3_CALF:      .equ   %01000000
mADC1SC3_CAL:       .equ   %10000000


;*** ADC1OFS - Offset Correction Register; 0xFFFF840E ***
ADC1OFS:            .equ   $FFFF840E                                ;*** ADC1OFS - Offset Correction Register; 0xFFFF840E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1OFS_OFS0:       .equ   0                                         ; Offset error correction value bit 0
ADC1OFS_OFS1:       .equ   1                                         ; Offset error correction value bit 1
ADC1OFS_OFS2:       .equ   2                                         ; Offset error correction value bit 2
ADC1OFS_OFS3:       .equ   3                                         ; Offset error correction value bit 3
ADC1OFS_OFS4:       .equ   4                                         ; Offset error correction value bit 4
ADC1OFS_OFS5:       .equ   5                                         ; Offset error correction value bit 5
ADC1OFS_OFS6:       .equ   6                                         ; Offset error correction value bit 6
ADC1OFS_OFS7:       .equ   7                                         ; Offset error correction value bit 7
ADC1OFS_OFS8:       .equ   8                                         ; Offset error correction value bit 8
ADC1OFS_OFS9:       .equ   9                                         ; Offset error correction value bit 9
ADC1OFS_OFS10:      .equ   10                                        ; Offset error correction value bit 10
ADC1OFS_OFS11:      .equ   11                                        ; Offset error correction value bit 11
ADC1OFS_OFS12:      .equ   12                                        ; Offset error correction value bit 12
ADC1OFS_OFS13:      .equ   13                                        ; Offset error correction value bit 13
ADC1OFS_OFS14:      .equ   14                                        ; Offset error correction value bit 14
ADC1OFS_OFS15:      .equ   15                                        ; Offset error correction value bit 15
; bit position masks
mADC1OFS_OFS0:      .equ   %00000001
mADC1OFS_OFS1:      .equ   %00000010
mADC1OFS_OFS2:      .equ   %00000100
mADC1OFS_OFS3:      .equ   %00001000
mADC1OFS_OFS4:      .equ   %00010000
mADC1OFS_OFS5:      .equ   %00100000
mADC1OFS_OFS6:      .equ   %01000000
mADC1OFS_OFS7:      .equ   %10000000
mADC1OFS_OFS8:      .equ   %100000000
mADC1OFS_OFS9:      .equ   %1000000000
mADC1OFS_OFS10:     .equ   %10000000000
mADC1OFS_OFS11:     .equ   %100000000000
mADC1OFS_OFS12:     .equ   %1000000000000
mADC1OFS_OFS13:     .equ   %10000000000000
mADC1OFS_OFS14:     .equ   %100000000000000
mADC1OFS_OFS15:     .equ   %1000000000000000


;*** ADC1OFSH - Offset Correction High Register; 0xFFFF840E ***
ADC1OFSH:           .equ   $FFFF840E                                ;*** ADC1OFSH - Offset Correction High Register; 0xFFFF840E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1OFSH_OFS8:      .equ   0                                         ; Offset error correction value bit 8
ADC1OFSH_OFS9:      .equ   1                                         ; Offset error correction value bit 9
ADC1OFSH_OFS10:     .equ   2                                         ; Offset error correction value bit 10
ADC1OFSH_OFS11:     .equ   3                                         ; Offset error correction value bit 11
ADC1OFSH_OFS12:     .equ   4                                         ; Offset error correction value bit 12
ADC1OFSH_OFS13:     .equ   5                                         ; Offset error correction value bit 13
ADC1OFSH_OFS14:     .equ   6                                         ; Offset error correction value bit 14
ADC1OFSH_OFS15:     .equ   7                                         ; Offset error correction value bit 15
; bit position masks
mADC1OFSH_OFS8:     .equ   %00000001
mADC1OFSH_OFS9:     .equ   %00000010
mADC1OFSH_OFS10:    .equ   %00000100
mADC1OFSH_OFS11:    .equ   %00001000
mADC1OFSH_OFS12:    .equ   %00010000
mADC1OFSH_OFS13:    .equ   %00100000
mADC1OFSH_OFS14:    .equ   %01000000
mADC1OFSH_OFS15:    .equ   %10000000


;*** ADC1OFSL - Offset Correction Low Register; 0xFFFF840F ***
ADC1OFSL:           .equ   $FFFF840F                                ;*** ADC1OFSL - Offset Correction Low Register; 0xFFFF840F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1OFSL_OFS0:      .equ   0                                         ; Offset error correction value bit 0
ADC1OFSL_OFS1:      .equ   1                                         ; Offset error correction value bit 1
ADC1OFSL_OFS2:      .equ   2                                         ; Offset error correction value bit 2
ADC1OFSL_OFS3:      .equ   3                                         ; Offset error correction value bit 3
ADC1OFSL_OFS4:      .equ   4                                         ; Offset error correction value bit 4
ADC1OFSL_OFS5:      .equ   5                                         ; Offset error correction value bit 5
ADC1OFSL_OFS6:      .equ   6                                         ; Offset error correction value bit 6
ADC1OFSL_OFS7:      .equ   7                                         ; Offset error correction value bit 7
; bit position masks
mADC1OFSL_OFS0:     .equ   %00000001
mADC1OFSL_OFS1:     .equ   %00000010
mADC1OFSL_OFS2:     .equ   %00000100
mADC1OFSL_OFS3:     .equ   %00001000
mADC1OFSL_OFS4:     .equ   %00010000
mADC1OFSL_OFS5:     .equ   %00100000
mADC1OFSL_OFS6:     .equ   %01000000
mADC1OFSL_OFS7:     .equ   %10000000


;*** ADC1PG - Plus-Side Gain Register; 0xFFFF8410 ***
ADC1PG:             .equ   $FFFF8410                                ;*** ADC1PG - Plus-Side Gain Register; 0xFFFF8410 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1PG_PG0:         .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC1PG_PG1:         .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC1PG_PG2:         .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC1PG_PG3:         .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC1PG_PG4:         .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC1PG_PG5:         .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC1PG_PG6:         .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC1PG_PG7:         .equ   7                                         ; Gain error correction for the plus-side input value bit 7
ADC1PG_PG8:         .equ   8                                         ; Gain error correction for the plus-side input value bit 8
ADC1PG_PG9:         .equ   9                                         ; Gain error correction for the plus-side input value bit 9
ADC1PG_PG10:        .equ   10                                        ; Gain error correction for the plus-side input value bit 10
ADC1PG_PG11:        .equ   11                                        ; Gain error correction for the plus-side input value bit 11
ADC1PG_PG12:        .equ   12                                        ; Gain error correction for the plus-side input value bit 12
ADC1PG_PG13:        .equ   13                                        ; Gain error correction for the plus-side input value bit 13
ADC1PG_PG14:        .equ   14                                        ; Gain error correction for the plus-side input value bit 14
ADC1PG_PG15:        .equ   15                                        ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC1PG_PG0:        .equ   %00000001
mADC1PG_PG1:        .equ   %00000010
mADC1PG_PG2:        .equ   %00000100
mADC1PG_PG3:        .equ   %00001000
mADC1PG_PG4:        .equ   %00010000
mADC1PG_PG5:        .equ   %00100000
mADC1PG_PG6:        .equ   %01000000
mADC1PG_PG7:        .equ   %10000000
mADC1PG_PG8:        .equ   %100000000
mADC1PG_PG9:        .equ   %1000000000
mADC1PG_PG10:       .equ   %10000000000
mADC1PG_PG11:       .equ   %100000000000
mADC1PG_PG12:       .equ   %1000000000000
mADC1PG_PG13:       .equ   %10000000000000
mADC1PG_PG14:       .equ   %100000000000000
mADC1PG_PG15:       .equ   %1000000000000000


;*** ADC1PGH - Plus-Side Gain High Register; 0xFFFF8410 ***
ADC1PGH:            .equ   $FFFF8410                                ;*** ADC1PGH - Plus-Side Gain High Register; 0xFFFF8410 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1PGH_PG8:        .equ   0                                         ; Gain error correction for the plus-side input value bit 8
ADC1PGH_PG9:        .equ   1                                         ; Gain error correction for the plus-side input value bit 9
ADC1PGH_PG10:       .equ   2                                         ; Gain error correction for the plus-side input value bit 10
ADC1PGH_PG11:       .equ   3                                         ; Gain error correction for the plus-side input value bit 11
ADC1PGH_PG12:       .equ   4                                         ; Gain error correction for the plus-side input value bit 12
ADC1PGH_PG13:       .equ   5                                         ; Gain error correction for the plus-side input value bit 13
ADC1PGH_PG14:       .equ   6                                         ; Gain error correction for the plus-side input value bit 14
ADC1PGH_PG15:       .equ   7                                         ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC1PGH_PG8:       .equ   %00000001
mADC1PGH_PG9:       .equ   %00000010
mADC1PGH_PG10:      .equ   %00000100
mADC1PGH_PG11:      .equ   %00001000
mADC1PGH_PG12:      .equ   %00010000
mADC1PGH_PG13:      .equ   %00100000
mADC1PGH_PG14:      .equ   %01000000
mADC1PGH_PG15:      .equ   %10000000


;*** ADC1PGL - Plus-Side Gain Low Register; 0xFFFF8411 ***
ADC1PGL:            .equ   $FFFF8411                                ;*** ADC1PGL - Plus-Side Gain Low Register; 0xFFFF8411 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1PGL_PG0:        .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC1PGL_PG1:        .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC1PGL_PG2:        .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC1PGL_PG3:        .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC1PGL_PG4:        .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC1PGL_PG5:        .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC1PGL_PG6:        .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC1PGL_PG7:        .equ   7                                         ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADC1PGL_PG0:       .equ   %00000001
mADC1PGL_PG1:       .equ   %00000010
mADC1PGL_PG2:       .equ   %00000100
mADC1PGL_PG3:       .equ   %00001000
mADC1PGL_PG4:       .equ   %00010000
mADC1PGL_PG5:       .equ   %00100000
mADC1PGL_PG6:       .equ   %01000000
mADC1PGL_PG7:       .equ   %10000000


;*** ADC1MG - Minus-Side Gain Register; 0xFFFF8412 ***
ADC1MG:             .equ   $FFFF8412                                ;*** ADC1MG - Minus-Side Gain Register; 0xFFFF8412 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1MG_MG0:         .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC1MG_MG1:         .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC1MG_MG2:         .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC1MG_MG3:         .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC1MG_MG4:         .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC1MG_MG5:         .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC1MG_MG6:         .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC1MG_MG7:         .equ   7                                         ; Gain error correction for the minus-side input value bit 7
ADC1MG_MG8:         .equ   8                                         ; Gain error correction for the minus-side input value bit 8
ADC1MG_MG9:         .equ   9                                         ; Gain error correction for the minus-side input value bit 9
ADC1MG_MG10:        .equ   10                                        ; Gain error correction for the minus-side input value bit 10
ADC1MG_MG11:        .equ   11                                        ; Gain error correction for the minus-side input value bit 11
ADC1MG_MG12:        .equ   12                                        ; Gain error correction for the minus-side input value bit 12
ADC1MG_MG13:        .equ   13                                        ; Gain error correction for the minus-side input value bit 13
ADC1MG_MG14:        .equ   14                                        ; Gain error correction for the minus-side input value bit 14
ADC1MG_MG15:        .equ   15                                        ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC1MG_MG0:        .equ   %00000001
mADC1MG_MG1:        .equ   %00000010
mADC1MG_MG2:        .equ   %00000100
mADC1MG_MG3:        .equ   %00001000
mADC1MG_MG4:        .equ   %00010000
mADC1MG_MG5:        .equ   %00100000
mADC1MG_MG6:        .equ   %01000000
mADC1MG_MG7:        .equ   %10000000
mADC1MG_MG8:        .equ   %100000000
mADC1MG_MG9:        .equ   %1000000000
mADC1MG_MG10:       .equ   %10000000000
mADC1MG_MG11:       .equ   %100000000000
mADC1MG_MG12:       .equ   %1000000000000
mADC1MG_MG13:       .equ   %10000000000000
mADC1MG_MG14:       .equ   %100000000000000
mADC1MG_MG15:       .equ   %1000000000000000


;*** ADC1MGH - Minus-Side Gain High Register; 0xFFFF8412 ***
ADC1MGH:            .equ   $FFFF8412                                ;*** ADC1MGH - Minus-Side Gain High Register; 0xFFFF8412 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1MGH_MG8:        .equ   0                                         ; Gain error correction for the minus-side input value bit 8
ADC1MGH_MG9:        .equ   1                                         ; Gain error correction for the minus-side input value bit 9
ADC1MGH_MG10:       .equ   2                                         ; Gain error correction for the minus-side input value bit 10
ADC1MGH_MG11:       .equ   3                                         ; Gain error correction for the minus-side input value bit 11
ADC1MGH_MG12:       .equ   4                                         ; Gain error correction for the minus-side input value bit 12
ADC1MGH_MG13:       .equ   5                                         ; Gain error correction for the minus-side input value bit 13
ADC1MGH_MG14:       .equ   6                                         ; Gain error correction for the minus-side input value bit 14
ADC1MGH_MG15:       .equ   7                                         ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC1MGH_MG8:       .equ   %00000001
mADC1MGH_MG9:       .equ   %00000010
mADC1MGH_MG10:      .equ   %00000100
mADC1MGH_MG11:      .equ   %00001000
mADC1MGH_MG12:      .equ   %00010000
mADC1MGH_MG13:      .equ   %00100000
mADC1MGH_MG14:      .equ   %01000000
mADC1MGH_MG15:      .equ   %10000000


;*** ADC1MGL - Minus-Side Gain Low Register; 0xFFFF8413 ***
ADC1MGL:            .equ   $FFFF8413                                ;*** ADC1MGL - Minus-Side Gain Low Register; 0xFFFF8413 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1MGL_MG0:        .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC1MGL_MG1:        .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC1MGL_MG2:        .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC1MGL_MG3:        .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC1MGL_MG4:        .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC1MGL_MG5:        .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC1MGL_MG6:        .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC1MGL_MG7:        .equ   7                                         ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADC1MGL_MG0:       .equ   %00000001
mADC1MGL_MG1:       .equ   %00000010
mADC1MGL_MG2:       .equ   %00000100
mADC1MGL_MG3:       .equ   %00001000
mADC1MGL_MG4:       .equ   %00010000
mADC1MGL_MG5:       .equ   %00100000
mADC1MGL_MG6:       .equ   %01000000
mADC1MGL_MG7:       .equ   %10000000


;*** ADC1CLPD - Plus-Side General Calibration Value D Register; 0xFFFF8414 ***
ADC1CLPD:           .equ   $FFFF8414                                ;*** ADC1CLPD - Plus-Side General Calibration Value D Register; 0xFFFF8414 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLPD_CLPD0:     .equ   0                                         ; Plus-Side General Calibration Value D bit 0
ADC1CLPD_CLPD1:     .equ   1                                         ; Plus-Side General Calibration Value D bit 1
ADC1CLPD_CLPD2:     .equ   2                                         ; Plus-Side General Calibration Value D bit 2
ADC1CLPD_CLPD3:     .equ   3                                         ; Plus-Side General Calibration Value D bit 3
ADC1CLPD_CLPD4:     .equ   4                                         ; Plus-Side General Calibration Value D bit 4
ADC1CLPD_CLPD5:     .equ   5                                         ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADC1CLPD_CLPD0:    .equ   %00000001
mADC1CLPD_CLPD1:    .equ   %00000010
mADC1CLPD_CLPD2:    .equ   %00000100
mADC1CLPD_CLPD3:    .equ   %00001000
mADC1CLPD_CLPD4:    .equ   %00010000
mADC1CLPD_CLPD5:    .equ   %00100000


;*** ADC1CLPS - Plus-Side General Calibration Value S Register; 0xFFFF8415 ***
ADC1CLPS:           .equ   $FFFF8415                                ;*** ADC1CLPS - Plus-Side General Calibration Value S Register; 0xFFFF8415 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLPS_CLPS0:     .equ   0                                         ; Plus-Side General Calibration Value S bit 0
ADC1CLPS_CLPS1:     .equ   1                                         ; Plus-Side General Calibration Value S bit 1
ADC1CLPS_CLPS2:     .equ   2                                         ; Plus-Side General Calibration Value S bit 2
ADC1CLPS_CLPS3:     .equ   3                                         ; Plus-Side General Calibration Value S bit 3
ADC1CLPS_CLPS4:     .equ   4                                         ; Plus-Side General Calibration Value S bit 4
ADC1CLPS_CLPS5:     .equ   5                                         ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADC1CLPS_CLPS0:    .equ   %00000001
mADC1CLPS_CLPS1:    .equ   %00000010
mADC1CLPS_CLPS2:    .equ   %00000100
mADC1CLPS_CLPS3:    .equ   %00001000
mADC1CLPS_CLPS4:    .equ   %00010000
mADC1CLPS_CLPS5:    .equ   %00100000


;*** ADC1CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF8416 ***
ADC1CLP4:           .equ   $FFFF8416                                ;*** ADC1CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF8416 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP4_CLP40:     .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC1CLP4_CLP41:     .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC1CLP4_CLP42:     .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC1CLP4_CLP43:     .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC1CLP4_CLP44:     .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC1CLP4_CLP45:     .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC1CLP4_CLP46:     .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC1CLP4_CLP47:     .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
ADC1CLP4_CLP48:     .equ   8                                         ; Plus-Side General Calibration Value 4 bit 8
ADC1CLP4_CLP49:     .equ   9                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC1CLP4_CLP40:    .equ   %00000001
mADC1CLP4_CLP41:    .equ   %00000010
mADC1CLP4_CLP42:    .equ   %00000100
mADC1CLP4_CLP43:    .equ   %00001000
mADC1CLP4_CLP44:    .equ   %00010000
mADC1CLP4_CLP45:    .equ   %00100000
mADC1CLP4_CLP46:    .equ   %01000000
mADC1CLP4_CLP47:    .equ   %10000000
mADC1CLP4_CLP48:    .equ   %100000000
mADC1CLP4_CLP49:    .equ   %1000000000


;*** ADC1CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF8416 ***
ADC1CLP4H:          .equ   $FFFF8416                                ;*** ADC1CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF8416 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP4H_CLP48:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 8
ADC1CLP4H_CLP49:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC1CLP4H_CLP48:   .equ   %00000001
mADC1CLP4H_CLP49:   .equ   %00000010


;*** ADC1CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF8417 ***
ADC1CLP4L:          .equ   $FFFF8417                                ;*** ADC1CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF8417 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP4L_CLP40:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC1CLP4L_CLP41:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC1CLP4L_CLP42:    .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC1CLP4L_CLP43:    .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC1CLP4L_CLP44:    .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC1CLP4L_CLP45:    .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC1CLP4L_CLP46:    .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC1CLP4L_CLP47:    .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADC1CLP4L_CLP40:   .equ   %00000001
mADC1CLP4L_CLP41:   .equ   %00000010
mADC1CLP4L_CLP42:   .equ   %00000100
mADC1CLP4L_CLP43:   .equ   %00001000
mADC1CLP4L_CLP44:   .equ   %00010000
mADC1CLP4L_CLP45:   .equ   %00100000
mADC1CLP4L_CLP46:   .equ   %01000000
mADC1CLP4L_CLP47:   .equ   %10000000


;*** ADC1CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF8418 ***
ADC1CLP3:           .equ   $FFFF8418                                ;*** ADC1CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF8418 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP3_CLP30:     .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC1CLP3_CLP31:     .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC1CLP3_CLP32:     .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC1CLP3_CLP33:     .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC1CLP3_CLP34:     .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC1CLP3_CLP35:     .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC1CLP3_CLP36:     .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC1CLP3_CLP37:     .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
ADC1CLP3_CLP38:     .equ   8                                         ; Plus-Side General Calibration Value 3 bit 8
; bit position masks
mADC1CLP3_CLP30:    .equ   %00000001
mADC1CLP3_CLP31:    .equ   %00000010
mADC1CLP3_CLP32:    .equ   %00000100
mADC1CLP3_CLP33:    .equ   %00001000
mADC1CLP3_CLP34:    .equ   %00010000
mADC1CLP3_CLP35:    .equ   %00100000
mADC1CLP3_CLP36:    .equ   %01000000
mADC1CLP3_CLP37:    .equ   %10000000
mADC1CLP3_CLP38:    .equ   %100000000


;*** ADC1CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF8418 ***
ADC1CLP3H:          .equ   $FFFF8418                                ;*** ADC1CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF8418 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP3H_CLP38:    .equ   0                                         ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADC1CLP3H_CLP38:   .equ   %00000001


;*** ADC1CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF8419 ***
ADC1CLP3L:          .equ   $FFFF8419                                ;*** ADC1CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF8419 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP3L_CLP30:    .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC1CLP3L_CLP31:    .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC1CLP3L_CLP32:    .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC1CLP3L_CLP33:    .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC1CLP3L_CLP34:    .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC1CLP3L_CLP35:    .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC1CLP3L_CLP36:    .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC1CLP3L_CLP37:    .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADC1CLP3L_CLP30:   .equ   %00000001
mADC1CLP3L_CLP31:   .equ   %00000010
mADC1CLP3L_CLP32:   .equ   %00000100
mADC1CLP3L_CLP33:   .equ   %00001000
mADC1CLP3L_CLP34:   .equ   %00010000
mADC1CLP3L_CLP35:   .equ   %00100000
mADC1CLP3L_CLP36:   .equ   %01000000
mADC1CLP3L_CLP37:   .equ   %10000000


;*** ADC1CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF841A ***
ADC1CLP2:           .equ   $FFFF841A                                ;*** ADC1CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF841A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP2_CLP20:     .equ   0                                         ; Plus-Side General Calibration Value 2 bit 0
ADC1CLP2_CLP21:     .equ   1                                         ; Plus-Side General Calibration Value 2 bit 1
ADC1CLP2_CLP22:     .equ   2                                         ; Plus-Side General Calibration Value 2 bit 2
ADC1CLP2_CLP23:     .equ   3                                         ; Plus-Side General Calibration Value 2 bit 3
ADC1CLP2_CLP24:     .equ   4                                         ; Plus-Side General Calibration Value 2 bit 4
ADC1CLP2_CLP25:     .equ   5                                         ; Plus-Side General Calibration Value 2 bit 5
ADC1CLP2_CLP26:     .equ   6                                         ; Plus-Side General Calibration Value 2 bit 6
ADC1CLP2_CLP27:     .equ   7                                         ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADC1CLP2_CLP20:    .equ   %00000001
mADC1CLP2_CLP21:    .equ   %00000010
mADC1CLP2_CLP22:    .equ   %00000100
mADC1CLP2_CLP23:    .equ   %00001000
mADC1CLP2_CLP24:    .equ   %00010000
mADC1CLP2_CLP25:    .equ   %00100000
mADC1CLP2_CLP26:    .equ   %01000000
mADC1CLP2_CLP27:    .equ   %10000000


;*** ADC1CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF841B ***
ADC1CLP1:           .equ   $FFFF841B                                ;*** ADC1CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF841B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP1_CLP10:     .equ   0                                         ; Plus-Side General Calibration Value 1 bit 0
ADC1CLP1_CLP11:     .equ   1                                         ; Plus-Side General Calibration Value 1 bit 1
ADC1CLP1_CLP12:     .equ   2                                         ; Plus-Side General Calibration Value 1 bit 2
ADC1CLP1_CLP13:     .equ   3                                         ; Plus-Side General Calibration Value 1 bit 3
ADC1CLP1_CLP14:     .equ   4                                         ; Plus-Side General Calibration Value 1 bit 4
ADC1CLP1_CLP15:     .equ   5                                         ; Plus-Side General Calibration Value 1 bit 5
ADC1CLP1_CLP16:     .equ   6                                         ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADC1CLP1_CLP10:    .equ   %00000001
mADC1CLP1_CLP11:    .equ   %00000010
mADC1CLP1_CLP12:    .equ   %00000100
mADC1CLP1_CLP13:    .equ   %00001000
mADC1CLP1_CLP14:    .equ   %00010000
mADC1CLP1_CLP15:    .equ   %00100000
mADC1CLP1_CLP16:    .equ   %01000000


;*** ADC1CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF841C ***
ADC1CLP0:           .equ   $FFFF841C                                ;*** ADC1CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF841C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP0_CLP00:     .equ   0                                         ; Plus-Side General Calibration Value 0 bit 0
ADC1CLP0_CLP01:     .equ   1                                         ; Plus-Side General Calibration Value 0 bit 1
ADC1CLP0_CLP02:     .equ   2                                         ; Plus-Side General Calibration Value 0 bit 2
ADC1CLP0_CLP03:     .equ   3                                         ; Plus-Side General Calibration Value 0 bit 3
ADC1CLP0_CLP04:     .equ   4                                         ; Plus-Side General Calibration Value 0 bit 4
ADC1CLP0_CLP05:     .equ   5                                         ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADC1CLP0_CLP00:    .equ   %00000001
mADC1CLP0_CLP01:    .equ   %00000010
mADC1CLP0_CLP02:    .equ   %00000100
mADC1CLP0_CLP03:    .equ   %00001000
mADC1CLP0_CLP04:    .equ   %00010000
mADC1CLP0_CLP05:    .equ   %00100000


;*** ADC1CLMD - Minus-Side General Calibration Value D Register; 0xFFFF841E ***
ADC1CLMD:           .equ   $FFFF841E                                ;*** ADC1CLMD - Minus-Side General Calibration Value D Register; 0xFFFF841E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLMD_CLMD0:     .equ   0                                         ; Minus-Side General Calibration Value D bit 0
ADC1CLMD_CLMD1:     .equ   1                                         ; Minus-Side General Calibration Value D bit 1
ADC1CLMD_CLMD2:     .equ   2                                         ; Minus-Side General Calibration Value D bit 2
ADC1CLMD_CLMD3:     .equ   3                                         ; Minus-Side General Calibration Value D bit 3
ADC1CLMD_CLMD4:     .equ   4                                         ; Minus-Side General Calibration Value D bit 4
ADC1CLMD_CLMD5:     .equ   5                                         ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADC1CLMD_CLMD0:    .equ   %00000001
mADC1CLMD_CLMD1:    .equ   %00000010
mADC1CLMD_CLMD2:    .equ   %00000100
mADC1CLMD_CLMD3:    .equ   %00001000
mADC1CLMD_CLMD4:    .equ   %00010000
mADC1CLMD_CLMD5:    .equ   %00100000


;*** ADC1CLMS - Minus-Side General Calibration Value S Register; 0xFFFF841F ***
ADC1CLMS:           .equ   $FFFF841F                                ;*** ADC1CLMS - Minus-Side General Calibration Value S Register; 0xFFFF841F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLMS_CLMS0:     .equ   0                                         ; Minus-Side General Calibration Value S bit 0
ADC1CLMS_CLMS1:     .equ   1                                         ; Minus-Side General Calibration Value S bit 1
ADC1CLMS_CLMS2:     .equ   2                                         ; Minus-Side General Calibration Value S bit 2
ADC1CLMS_CLMS3:     .equ   3                                         ; Minus-Side General Calibration Value S bit 3
ADC1CLMS_CLMS4:     .equ   4                                         ; Minus-Side General Calibration Value S bit 4
ADC1CLMS_CLMS5:     .equ   5                                         ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADC1CLMS_CLMS0:    .equ   %00000001
mADC1CLMS_CLMS1:    .equ   %00000010
mADC1CLMS_CLMS2:    .equ   %00000100
mADC1CLMS_CLMS3:    .equ   %00001000
mADC1CLMS_CLMS4:    .equ   %00010000
mADC1CLMS_CLMS5:    .equ   %00100000


;*** ADC1CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF8420 ***
ADC1CLM4:           .equ   $FFFF8420                                ;*** ADC1CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF8420 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM4_CLM40:     .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC1CLM4_CLM41:     .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC1CLM4_CLM42:     .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC1CLM4_CLM43:     .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC1CLM4_CLM44:     .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC1CLM4_CLM45:     .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC1CLM4_CLM46:     .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC1CLM4_CLM47:     .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
ADC1CLM4_CLM48:     .equ   8                                         ; Minus-Side General Calibration Value 4 bit 8
ADC1CLM4_CLM49:     .equ   9                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC1CLM4_CLM40:    .equ   %00000001
mADC1CLM4_CLM41:    .equ   %00000010
mADC1CLM4_CLM42:    .equ   %00000100
mADC1CLM4_CLM43:    .equ   %00001000
mADC1CLM4_CLM44:    .equ   %00010000
mADC1CLM4_CLM45:    .equ   %00100000
mADC1CLM4_CLM46:    .equ   %01000000
mADC1CLM4_CLM47:    .equ   %10000000
mADC1CLM4_CLM48:    .equ   %100000000
mADC1CLM4_CLM49:    .equ   %1000000000


;*** ADC1CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF8420 ***
ADC1CLM4H:          .equ   $FFFF8420                                ;*** ADC1CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF8420 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM4H_CLM48:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 8
ADC1CLM4H_CLM49:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC1CLM4H_CLM48:   .equ   %00000001
mADC1CLM4H_CLM49:   .equ   %00000010


;*** ADC1CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF8421 ***
ADC1CLM4L:          .equ   $FFFF8421                                ;*** ADC1CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF8421 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM4L_CLM40:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC1CLM4L_CLM41:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC1CLM4L_CLM42:    .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC1CLM4L_CLM43:    .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC1CLM4L_CLM44:    .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC1CLM4L_CLM45:    .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC1CLM4L_CLM46:    .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC1CLM4L_CLM47:    .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADC1CLM4L_CLM40:   .equ   %00000001
mADC1CLM4L_CLM41:   .equ   %00000010
mADC1CLM4L_CLM42:   .equ   %00000100
mADC1CLM4L_CLM43:   .equ   %00001000
mADC1CLM4L_CLM44:   .equ   %00010000
mADC1CLM4L_CLM45:   .equ   %00100000
mADC1CLM4L_CLM46:   .equ   %01000000
mADC1CLM4L_CLM47:   .equ   %10000000


;*** ADC1CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF8422 ***
ADC1CLM3:           .equ   $FFFF8422                                ;*** ADC1CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF8422 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM3_CLM30:     .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC1CLM3_CLM31:     .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC1CLM3_CLM32:     .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC1CLM3_CLM33:     .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC1CLM3_CLM34:     .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC1CLM3_CLM35:     .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC1CLM3_CLM36:     .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC1CLM3_CLM37:     .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
ADC1CLM3_CLM38:     .equ   8                                         ; Minus-Side General Calibration Value 3 bit 8
; bit position masks
mADC1CLM3_CLM30:    .equ   %00000001
mADC1CLM3_CLM31:    .equ   %00000010
mADC1CLM3_CLM32:    .equ   %00000100
mADC1CLM3_CLM33:    .equ   %00001000
mADC1CLM3_CLM34:    .equ   %00010000
mADC1CLM3_CLM35:    .equ   %00100000
mADC1CLM3_CLM36:    .equ   %01000000
mADC1CLM3_CLM37:    .equ   %10000000
mADC1CLM3_CLM38:    .equ   %100000000


;*** ADC1CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF8422 ***
ADC1CLM3H:          .equ   $FFFF8422                                ;*** ADC1CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF8422 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM3H_CLM38:    .equ   0                                         ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADC1CLM3H_CLM38:   .equ   %00000001


;*** ADC1CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF8423 ***
ADC1CLM3L:          .equ   $FFFF8423                                ;*** ADC1CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF8423 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM3L_CLM30:    .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC1CLM3L_CLM31:    .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC1CLM3L_CLM32:    .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC1CLM3L_CLM33:    .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC1CLM3L_CLM34:    .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC1CLM3L_CLM35:    .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC1CLM3L_CLM36:    .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC1CLM3L_CLM37:    .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADC1CLM3L_CLM30:   .equ   %00000001
mADC1CLM3L_CLM31:   .equ   %00000010
mADC1CLM3L_CLM32:   .equ   %00000100
mADC1CLM3L_CLM33:   .equ   %00001000
mADC1CLM3L_CLM34:   .equ   %00010000
mADC1CLM3L_CLM35:   .equ   %00100000
mADC1CLM3L_CLM36:   .equ   %01000000
mADC1CLM3L_CLM37:   .equ   %10000000


;*** ADC1CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF8424 ***
ADC1CLM2:           .equ   $FFFF8424                                ;*** ADC1CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF8424 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM2_CLM20:     .equ   0                                         ; Minus-Side General Calibration Value 2 bit 0
ADC1CLM2_CLM21:     .equ   1                                         ; Minus-Side General Calibration Value 2 bit 1
ADC1CLM2_CLM22:     .equ   2                                         ; Minus-Side General Calibration Value 2 bit 2
ADC1CLM2_CLM23:     .equ   3                                         ; Minus-Side General Calibration Value 2 bit 3
ADC1CLM2_CLM24:     .equ   4                                         ; Minus-Side General Calibration Value 2 bit 4
ADC1CLM2_CLM25:     .equ   5                                         ; Minus-Side General Calibration Value 2 bit 5
ADC1CLM2_CLM26:     .equ   6                                         ; Minus-Side General Calibration Value 2 bit 6
ADC1CLM2_CLM27:     .equ   7                                         ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADC1CLM2_CLM20:    .equ   %00000001
mADC1CLM2_CLM21:    .equ   %00000010
mADC1CLM2_CLM22:    .equ   %00000100
mADC1CLM2_CLM23:    .equ   %00001000
mADC1CLM2_CLM24:    .equ   %00010000
mADC1CLM2_CLM25:    .equ   %00100000
mADC1CLM2_CLM26:    .equ   %01000000
mADC1CLM2_CLM27:    .equ   %10000000


;*** ADC1CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF8425 ***
ADC1CLM1:           .equ   $FFFF8425                                ;*** ADC1CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF8425 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM1_CLM10:     .equ   0                                         ; Minus-Side General Calibration Value 1 bit 0
ADC1CLM1_CLM11:     .equ   1                                         ; Minus-Side General Calibration Value 1 bit 1
ADC1CLM1_CLM12:     .equ   2                                         ; Minus-Side General Calibration Value 1 bit 2
ADC1CLM1_CLM13:     .equ   3                                         ; Minus-Side General Calibration Value 1 bit 3
ADC1CLM1_CLM14:     .equ   4                                         ; Minus-Side General Calibration Value 1 bit 4
ADC1CLM1_CLM15:     .equ   5                                         ; Minus-Side General Calibration Value 1 bit 5
ADC1CLM1_CLM16:     .equ   6                                         ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADC1CLM1_CLM10:    .equ   %00000001
mADC1CLM1_CLM11:    .equ   %00000010
mADC1CLM1_CLM12:    .equ   %00000100
mADC1CLM1_CLM13:    .equ   %00001000
mADC1CLM1_CLM14:    .equ   %00010000
mADC1CLM1_CLM15:    .equ   %00100000
mADC1CLM1_CLM16:    .equ   %01000000


;*** ADC1CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF8426 ***
ADC1CLM0:           .equ   $FFFF8426                                ;*** ADC1CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF8426 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM0_CLM00:     .equ   0                                         ; Minus-Side General Calibration Value 0 bit 0
ADC1CLM0_CLM01:     .equ   1                                         ; Minus-Side General Calibration Value 0 bit 1
ADC1CLM0_CLM02:     .equ   2                                         ; Minus-Side General Calibration Value 0 bit 2
ADC1CLM0_CLM03:     .equ   3                                         ; Minus-Side General Calibration Value 0 bit 3
ADC1CLM0_CLM04:     .equ   4                                         ; Minus-Side General Calibration Value 0 bit 4
ADC1CLM0_CLM05:     .equ   5                                         ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADC1CLM0_CLM00:    .equ   %00000001
mADC1CLM0_CLM01:    .equ   %00000010
mADC1CLM0_CLM02:    .equ   %00000100
mADC1CLM0_CLM03:    .equ   %00001000
mADC1CLM0_CLM04:    .equ   %00010000
mADC1CLM0_CLM05:    .equ   %00100000


;*** ADC2SC1A - Status and Control Register 1A; 0xFFFF8440 ***
ADC2SC1A:           .equ   $FFFF8440                                ;*** ADC2SC1A - Status and Control Register 1A; 0xFFFF8440 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2SC1A_ADCHA0:    .equ   0                                         ; Input Channel Select Bit 0
ADC2SC1A_ADCHA1:    .equ   1                                         ; Input Channel Select Bit 1
ADC2SC1A_ADCHA2:    .equ   2                                         ; Input Channel Select Bit 2
ADC2SC1A_ADCHA3:    .equ   3                                         ; Input Channel Select Bit 3
ADC2SC1A_ADCHA4:    .equ   4                                         ; Input Channel Select Bit 4
ADC2SC1A_DIFFA:     .equ   5                                         ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADC2SC1A_AIENA:     .equ   6                                         ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA is high, an interrupt is asserted
ADC2SC1A_COCOA:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC2SC1A_ADCHA0:   .equ   %00000001
mADC2SC1A_ADCHA1:   .equ   %00000010
mADC2SC1A_ADCHA2:   .equ   %00000100
mADC2SC1A_ADCHA3:   .equ   %00001000
mADC2SC1A_ADCHA4:   .equ   %00010000
mADC2SC1A_DIFFA:    .equ   %00100000
mADC2SC1A_AIENA:    .equ   %01000000
mADC2SC1A_COCOA:    .equ   %10000000


;*** ADC2SC1B - Status and Control Register 1B; 0xFFFF8441 ***
ADC2SC1B:           .equ   $FFFF8441                                ;*** ADC2SC1B - Status and Control Register 1B; 0xFFFF8441 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2SC1B_ADCHB0:    .equ   0                                         ; Input Channel Select Bit 0
ADC2SC1B_ADCHB1:    .equ   1                                         ; Input Channel Select Bit 1
ADC2SC1B_ADCHB2:    .equ   2                                         ; Input Channel Select Bit 2
ADC2SC1B_ADCHB3:    .equ   3                                         ; Input Channel Select Bit 3
ADC2SC1B_ADCHB4:    .equ   4                                         ; Input Channel Select Bit 4
ADC2SC1B_DIFFB:     .equ   5                                         ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADC2SC1B_AIENB:     .equ   6                                         ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB is high, an interrupt is asserted
ADC2SC1B_COCOB:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC2SC1B_ADCHB0:   .equ   %00000001
mADC2SC1B_ADCHB1:   .equ   %00000010
mADC2SC1B_ADCHB2:   .equ   %00000100
mADC2SC1B_ADCHB3:   .equ   %00001000
mADC2SC1B_ADCHB4:   .equ   %00010000
mADC2SC1B_DIFFB:    .equ   %00100000
mADC2SC1B_AIENB:    .equ   %01000000
mADC2SC1B_COCOB:    .equ   %10000000


;*** ADC2CFG1 - Configuration Register 1; 0xFFFF8442 ***
ADC2CFG1:           .equ   $FFFF8442                                ;*** ADC2CFG1 - Configuration Register 1; 0xFFFF8442 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CFG1_ADICLK0:   .equ   0                                         ; Input Clock Select Bit 0
ADC2CFG1_ADICLK1:   .equ   1                                         ; Input Clock Select Bit 1
ADC2CFG1_MODE0:     .equ   2                                         ; Conversion Mode Selection Bit 0
ADC2CFG1_MODE1:     .equ   3                                         ; Conversion Mode Selection Bit 1
ADC2CFG1_ADLSMP:    .equ   4                                         ; Long Sample Time Configuration
ADC2CFG1_ADIV0:     .equ   5                                         ; Clock Divide Select Bit 0
ADC2CFG1_ADIV1:     .equ   6                                         ; Clock Divide Select Bit 1
ADC2CFG1_ADLPC:     .equ   7                                         ; Low Power Configuration
; bit position masks
mADC2CFG1_ADICLK0:  .equ   %00000001
mADC2CFG1_ADICLK1:  .equ   %00000010
mADC2CFG1_MODE0:    .equ   %00000100
mADC2CFG1_MODE1:    .equ   %00001000
mADC2CFG1_ADLSMP:   .equ   %00010000
mADC2CFG1_ADIV0:    .equ   %00100000
mADC2CFG1_ADIV1:    .equ   %01000000
mADC2CFG1_ADLPC:    .equ   %10000000


;*** ADC2CFG2 - Configuration Register 2; 0xFFFF8443 ***
ADC2CFG2:           .equ   $FFFF8443                                ;*** ADC2CFG2 - Configuration Register 2; 0xFFFF8443 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CFG2_ADLSTS0:   .equ   0                                         ; Long Sample Time Select Bit 0
ADC2CFG2_ADLSTS1:   .equ   1                                         ; Long Sample Time Select Bit 1
ADC2CFG2_ADHSC:     .equ   2                                         ; High Speed Configuration
ADC2CFG2_ADACKEN:   .equ   3                                         ; Asynchronous Clock Output Enable
; bit position masks
mADC2CFG2_ADLSTS0:  .equ   %00000001
mADC2CFG2_ADLSTS1:  .equ   %00000010
mADC2CFG2_ADHSC:    .equ   %00000100
mADC2CFG2_ADACKEN:  .equ   %00001000


;*** ADC2RA - Data Result Register A; 0xFFFF8444 ***
ADC2RA:             .equ   $FFFF8444                                ;*** ADC2RA - Data Result Register A; 0xFFFF8444 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2RA_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC2RA_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC2RA_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC2RA_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC2RA_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC2RA_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC2RA_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC2RA_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC2RA_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC2RA_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC2RA_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC2RA_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC2RA_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC2RA_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC2RA_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC2RA_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC2RA_D0:         .equ   %00000001
mADC2RA_D1:         .equ   %00000010
mADC2RA_D2:         .equ   %00000100
mADC2RA_D3:         .equ   %00001000
mADC2RA_D4:         .equ   %00010000
mADC2RA_D5:         .equ   %00100000
mADC2RA_D6:         .equ   %01000000
mADC2RA_D7:         .equ   %10000000
mADC2RA_D8:         .equ   %100000000
mADC2RA_D9:         .equ   %1000000000
mADC2RA_D10:        .equ   %10000000000
mADC2RA_D11:        .equ   %100000000000
mADC2RA_D12:        .equ   %1000000000000
mADC2RA_D13:        .equ   %10000000000000
mADC2RA_D14:        .equ   %100000000000000
mADC2RA_D15:        .equ   %1000000000000000


;*** ADC2RHA - Data Result High Register A; 0xFFFF8444 ***
ADC2RHA:            .equ   $FFFF8444                                ;*** ADC2RHA - Data Result High Register A; 0xFFFF8444 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2RHA_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC2RHA_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC2RHA_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC2RHA_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC2RHA_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC2RHA_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC2RHA_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC2RHA_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC2RHA_D8:        .equ   %00000001
mADC2RHA_D9:        .equ   %00000010
mADC2RHA_D10:       .equ   %00000100
mADC2RHA_D11:       .equ   %00001000
mADC2RHA_D12:       .equ   %00010000
mADC2RHA_D13:       .equ   %00100000
mADC2RHA_D14:       .equ   %01000000
mADC2RHA_D15:       .equ   %10000000


;*** ADC2RLA - Data Result Low Register A; 0xFFFF8445 ***
ADC2RLA:            .equ   $FFFF8445                                ;*** ADC2RLA - Data Result Low Register A; 0xFFFF8445 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2RLA_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC2RLA_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC2RLA_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC2RLA_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC2RLA_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC2RLA_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC2RLA_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC2RLA_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC2RLA_D0:        .equ   %00000001
mADC2RLA_D1:        .equ   %00000010
mADC2RLA_D2:        .equ   %00000100
mADC2RLA_D3:        .equ   %00001000
mADC2RLA_D4:        .equ   %00010000
mADC2RLA_D5:        .equ   %00100000
mADC2RLA_D6:        .equ   %01000000
mADC2RLA_D7:        .equ   %10000000


;*** ADC2RB - Data Result Register B; 0xFFFF8446 ***
ADC2RB:             .equ   $FFFF8446                                ;*** ADC2RB - Data Result Register B; 0xFFFF8446 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2RB_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC2RB_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC2RB_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC2RB_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC2RB_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC2RB_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC2RB_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC2RB_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC2RB_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC2RB_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC2RB_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC2RB_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC2RB_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC2RB_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC2RB_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC2RB_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC2RB_D0:         .equ   %00000001
mADC2RB_D1:         .equ   %00000010
mADC2RB_D2:         .equ   %00000100
mADC2RB_D3:         .equ   %00001000
mADC2RB_D4:         .equ   %00010000
mADC2RB_D5:         .equ   %00100000
mADC2RB_D6:         .equ   %01000000
mADC2RB_D7:         .equ   %10000000
mADC2RB_D8:         .equ   %100000000
mADC2RB_D9:         .equ   %1000000000
mADC2RB_D10:        .equ   %10000000000
mADC2RB_D11:        .equ   %100000000000
mADC2RB_D12:        .equ   %1000000000000
mADC2RB_D13:        .equ   %10000000000000
mADC2RB_D14:        .equ   %100000000000000
mADC2RB_D15:        .equ   %1000000000000000


;*** ADC2RHB - Data Result High Register B; 0xFFFF8446 ***
ADC2RHB:            .equ   $FFFF8446                                ;*** ADC2RHB - Data Result High Register B; 0xFFFF8446 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2RHB_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC2RHB_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC2RHB_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC2RHB_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC2RHB_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC2RHB_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC2RHB_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC2RHB_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC2RHB_D8:        .equ   %00000001
mADC2RHB_D9:        .equ   %00000010
mADC2RHB_D10:       .equ   %00000100
mADC2RHB_D11:       .equ   %00001000
mADC2RHB_D12:       .equ   %00010000
mADC2RHB_D13:       .equ   %00100000
mADC2RHB_D14:       .equ   %01000000
mADC2RHB_D15:       .equ   %10000000


;*** ADC2RLB - Data Result Low Register B; 0xFFFF8447 ***
ADC2RLB:            .equ   $FFFF8447                                ;*** ADC2RLB - Data Result Low Register B; 0xFFFF8447 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2RLB_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC2RLB_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC2RLB_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC2RLB_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC2RLB_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC2RLB_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC2RLB_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC2RLB_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC2RLB_D0:        .equ   %00000001
mADC2RLB_D1:        .equ   %00000010
mADC2RLB_D2:        .equ   %00000100
mADC2RLB_D3:        .equ   %00001000
mADC2RLB_D4:        .equ   %00010000
mADC2RLB_D5:        .equ   %00100000
mADC2RLB_D6:        .equ   %01000000
mADC2RLB_D7:        .equ   %10000000


;*** ADC2CV1 - Compare Value 1 Register; 0xFFFF8448 ***
ADC2CV1:            .equ   $FFFF8448                                ;*** ADC2CV1 - Compare Value 1 Register; 0xFFFF8448 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CV1_CV10:       .equ   0                                         ; Compare Function Value 0
ADC2CV1_CV11:       .equ   1                                         ; Compare Function Value 1
ADC2CV1_CV12:       .equ   2                                         ; Compare Function Value 2
ADC2CV1_CV13:       .equ   3                                         ; Compare Function Value 3
ADC2CV1_CV14:       .equ   4                                         ; Compare Function Value 4
ADC2CV1_CV15:       .equ   5                                         ; Compare Function Value 5
ADC2CV1_CV16:       .equ   6                                         ; Compare Function Value 6
ADC2CV1_CV17:       .equ   7                                         ; Compare Function Value 7
ADC2CV1_CV18:       .equ   8                                         ; Compare Function Value 8
ADC2CV1_CV19:       .equ   9                                         ; Compare Function Value 9
ADC2CV1_CV110:      .equ   10                                        ; Compare Function Value 10
ADC2CV1_CV111:      .equ   11                                        ; Compare Function Value 11
ADC2CV1_CV112:      .equ   12                                        ; Compare Function Value 12
ADC2CV1_CV113:      .equ   13                                        ; Compare Function Value 13
ADC2CV1_CV114:      .equ   14                                        ; Compare Function Value 14
ADC2CV1_CV115:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC2CV1_CV10:      .equ   %00000001
mADC2CV1_CV11:      .equ   %00000010
mADC2CV1_CV12:      .equ   %00000100
mADC2CV1_CV13:      .equ   %00001000
mADC2CV1_CV14:      .equ   %00010000
mADC2CV1_CV15:      .equ   %00100000
mADC2CV1_CV16:      .equ   %01000000
mADC2CV1_CV17:      .equ   %10000000
mADC2CV1_CV18:      .equ   %100000000
mADC2CV1_CV19:      .equ   %1000000000
mADC2CV1_CV110:     .equ   %10000000000
mADC2CV1_CV111:     .equ   %100000000000
mADC2CV1_CV112:     .equ   %1000000000000
mADC2CV1_CV113:     .equ   %10000000000000
mADC2CV1_CV114:     .equ   %100000000000000
mADC2CV1_CV115:     .equ   %1000000000000000


;*** ADC2CV1H - Compare Value 1 High Register; 0xFFFF8448 ***
ADC2CV1H:           .equ   $FFFF8448                                ;*** ADC2CV1H - Compare Value 1 High Register; 0xFFFF8448 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CV1H_CV18:      .equ   0                                         ; Compare Function Value 8
ADC2CV1H_CV19:      .equ   1                                         ; Compare Function Value 9
ADC2CV1H_CV110:     .equ   2                                         ; Compare Function Value 10
ADC2CV1H_CV111:     .equ   3                                         ; Compare Function Value 11
ADC2CV1H_CV112:     .equ   4                                         ; Compare Function Value 12
ADC2CV1H_CV113:     .equ   5                                         ; Compare Function Value 13
ADC2CV1H_CV114:     .equ   6                                         ; Compare Function Value 14
ADC2CV1H_CV115:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC2CV1H_CV18:     .equ   %00000001
mADC2CV1H_CV19:     .equ   %00000010
mADC2CV1H_CV110:    .equ   %00000100
mADC2CV1H_CV111:    .equ   %00001000
mADC2CV1H_CV112:    .equ   %00010000
mADC2CV1H_CV113:    .equ   %00100000
mADC2CV1H_CV114:    .equ   %01000000
mADC2CV1H_CV115:    .equ   %10000000


;*** ADC2CV1L - Compare Value 1 Low Register; 0xFFFF8449 ***
ADC2CV1L:           .equ   $FFFF8449                                ;*** ADC2CV1L - Compare Value 1 Low Register; 0xFFFF8449 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CV1L_CV10:      .equ   0                                         ; Compare Function Value 0
ADC2CV1L_CV11:      .equ   1                                         ; Compare Function Value 1
ADC2CV1L_CV12:      .equ   2                                         ; Compare Function Value 2
ADC2CV1L_CV13:      .equ   3                                         ; Compare Function Value 3
ADC2CV1L_CV14:      .equ   4                                         ; Compare Function Value 4
ADC2CV1L_CV15:      .equ   5                                         ; Compare Function Value 5
ADC2CV1L_CV16:      .equ   6                                         ; Compare Function Value 6
ADC2CV1L_CV17:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC2CV1L_CV10:     .equ   %00000001
mADC2CV1L_CV11:     .equ   %00000010
mADC2CV1L_CV12:     .equ   %00000100
mADC2CV1L_CV13:     .equ   %00001000
mADC2CV1L_CV14:     .equ   %00010000
mADC2CV1L_CV15:     .equ   %00100000
mADC2CV1L_CV16:     .equ   %01000000
mADC2CV1L_CV17:     .equ   %10000000


;*** ADC2CV2 - Compare Value 2 Register; 0xFFFF844A ***
ADC2CV2:            .equ   $FFFF844A                                ;*** ADC2CV2 - Compare Value 2 Register; 0xFFFF844A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CV2_CV20:       .equ   0                                         ; Compare Function Value 0
ADC2CV2_CV21:       .equ   1                                         ; Compare Function Value 1
ADC2CV2_CV22:       .equ   2                                         ; Compare Function Value 2
ADC2CV2_CV23:       .equ   3                                         ; Compare Function Value 3
ADC2CV2_CV24:       .equ   4                                         ; Compare Function Value 4
ADC2CV2_CV25:       .equ   5                                         ; Compare Function Value 5
ADC2CV2_CV26:       .equ   6                                         ; Compare Function Value 6
ADC2CV2_CV27:       .equ   7                                         ; Compare Function Value 7
ADC2CV2_CV28:       .equ   8                                         ; Compare Function Value 8
ADC2CV2_CV29:       .equ   9                                         ; Compare Function Value 9
ADC2CV2_CV210:      .equ   10                                        ; Compare Function Value 10
ADC2CV2_CV211:      .equ   11                                        ; Compare Function Value 11
ADC2CV2_CV212:      .equ   12                                        ; Compare Function Value 12
ADC2CV2_CV213:      .equ   13                                        ; Compare Function Value 13
ADC2CV2_CV214:      .equ   14                                        ; Compare Function Value 14
ADC2CV2_CV215:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC2CV2_CV20:      .equ   %00000001
mADC2CV2_CV21:      .equ   %00000010
mADC2CV2_CV22:      .equ   %00000100
mADC2CV2_CV23:      .equ   %00001000
mADC2CV2_CV24:      .equ   %00010000
mADC2CV2_CV25:      .equ   %00100000
mADC2CV2_CV26:      .equ   %01000000
mADC2CV2_CV27:      .equ   %10000000
mADC2CV2_CV28:      .equ   %100000000
mADC2CV2_CV29:      .equ   %1000000000
mADC2CV2_CV210:     .equ   %10000000000
mADC2CV2_CV211:     .equ   %100000000000
mADC2CV2_CV212:     .equ   %1000000000000
mADC2CV2_CV213:     .equ   %10000000000000
mADC2CV2_CV214:     .equ   %100000000000000
mADC2CV2_CV215:     .equ   %1000000000000000


;*** ADC2CV2H - Compare Value 2 High Register; 0xFFFF844A ***
ADC2CV2H:           .equ   $FFFF844A                                ;*** ADC2CV2H - Compare Value 2 High Register; 0xFFFF844A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CV2H_CV28:      .equ   0                                         ; Compare Function Value 8
ADC2CV2H_CV29:      .equ   1                                         ; Compare Function Value 9
ADC2CV2H_CV210:     .equ   2                                         ; Compare Function Value 10
ADC2CV2H_CV211:     .equ   3                                         ; Compare Function Value 11
ADC2CV2H_CV212:     .equ   4                                         ; Compare Function Value 12
ADC2CV2H_CV213:     .equ   5                                         ; Compare Function Value 13
ADC2CV2H_CV214:     .equ   6                                         ; Compare Function Value 14
ADC2CV2H_CV215:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC2CV2H_CV28:     .equ   %00000001
mADC2CV2H_CV29:     .equ   %00000010
mADC2CV2H_CV210:    .equ   %00000100
mADC2CV2H_CV211:    .equ   %00001000
mADC2CV2H_CV212:    .equ   %00010000
mADC2CV2H_CV213:    .equ   %00100000
mADC2CV2H_CV214:    .equ   %01000000
mADC2CV2H_CV215:    .equ   %10000000


;*** ADC2CV2L - Compare Value 2 Low Register; 0xFFFF844B ***
ADC2CV2L:           .equ   $FFFF844B                                ;*** ADC2CV2L - Compare Value 2 Low Register; 0xFFFF844B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CV2L_CV20:      .equ   0                                         ; Compare Function Value 0
ADC2CV2L_CV21:      .equ   1                                         ; Compare Function Value 1
ADC2CV2L_CV22:      .equ   2                                         ; Compare Function Value 2
ADC2CV2L_CV23:      .equ   3                                         ; Compare Function Value 3
ADC2CV2L_CV24:      .equ   4                                         ; Compare Function Value 4
ADC2CV2L_CV25:      .equ   5                                         ; Compare Function Value 5
ADC2CV2L_CV26:      .equ   6                                         ; Compare Function Value 6
ADC2CV2L_CV27:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC2CV2L_CV20:     .equ   %00000001
mADC2CV2L_CV21:     .equ   %00000010
mADC2CV2L_CV22:     .equ   %00000100
mADC2CV2L_CV23:     .equ   %00001000
mADC2CV2L_CV24:     .equ   %00010000
mADC2CV2L_CV25:     .equ   %00100000
mADC2CV2L_CV26:     .equ   %01000000
mADC2CV2L_CV27:     .equ   %10000000


;*** ADC2SC2 - Status and Control Register 2; 0xFFFF844C ***
ADC2SC2:            .equ   $FFFF844C                                ;*** ADC2SC2 - Status and Control Register 2; 0xFFFF844C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2SC2_REFSEL0:    .equ   0                                         ; Voltage Reference Selection, bit 0
ADC2SC2_REFSEL1:    .equ   1                                         ; Voltage Reference Selection, bit 1
ADC2SC2_ACREN:      .equ   3                                         ; Unused
ADC2SC2_ACFGT:      .equ   4                                         ; Compare Function Greater Than Enable
ADC2SC2_ACFE:       .equ   5                                         ; Compare Function Enable - ACFE is used to enable the compare function
ADC2SC2_ADTRG:      .equ   6                                         ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion
ADC2SC2_ADACT:      .equ   7                                         ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted
; bit position masks
mADC2SC2_REFSEL0:   .equ   %00000001
mADC2SC2_REFSEL1:   .equ   %00000010
mADC2SC2_ACREN:     .equ   %00001000
mADC2SC2_ACFGT:     .equ   %00010000
mADC2SC2_ACFE:      .equ   %00100000
mADC2SC2_ADTRG:     .equ   %01000000
mADC2SC2_ADACT:     .equ   %10000000


;*** ADC2SC3 - Status and Control Register 3; 0xFFFF844D ***
ADC2SC3:            .equ   $FFFF844D                                ;*** ADC2SC3 - Status and Control Register 3; 0xFFFF844D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2SC3_AVGS0:      .equ   0                                         ; Hardware Average select, bit 0
ADC2SC3_AVGS1:      .equ   1                                         ; Hardware Average select, bit 1
ADC2SC3_AVGE:       .equ   2                                         ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADC2SC3_ADCO:       .equ   3                                         ; Continuous Conversion Enable - ADCO enables continuous conversions
ADC2SC3_CALF:       .equ   6                                         ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC2SC3_CAL:        .equ   7                                         ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADC2SC3_AVGS0:     .equ   %00000001
mADC2SC3_AVGS1:     .equ   %00000010
mADC2SC3_AVGE:      .equ   %00000100
mADC2SC3_ADCO:      .equ   %00001000
mADC2SC3_CALF:      .equ   %01000000
mADC2SC3_CAL:       .equ   %10000000


;*** ADC2OFS - Offset Correction Register; 0xFFFF844E ***
ADC2OFS:            .equ   $FFFF844E                                ;*** ADC2OFS - Offset Correction Register; 0xFFFF844E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2OFS_OFS0:       .equ   0                                         ; Offset error correction value bit 0
ADC2OFS_OFS1:       .equ   1                                         ; Offset error correction value bit 1
ADC2OFS_OFS2:       .equ   2                                         ; Offset error correction value bit 2
ADC2OFS_OFS3:       .equ   3                                         ; Offset error correction value bit 3
ADC2OFS_OFS4:       .equ   4                                         ; Offset error correction value bit 4
ADC2OFS_OFS5:       .equ   5                                         ; Offset error correction value bit 5
ADC2OFS_OFS6:       .equ   6                                         ; Offset error correction value bit 6
ADC2OFS_OFS7:       .equ   7                                         ; Offset error correction value bit 7
ADC2OFS_OFS8:       .equ   8                                         ; Offset error correction value bit 8
ADC2OFS_OFS9:       .equ   9                                         ; Offset error correction value bit 9
ADC2OFS_OFS10:      .equ   10                                        ; Offset error correction value bit 10
ADC2OFS_OFS11:      .equ   11                                        ; Offset error correction value bit 11
ADC2OFS_OFS12:      .equ   12                                        ; Offset error correction value bit 12
ADC2OFS_OFS13:      .equ   13                                        ; Offset error correction value bit 13
ADC2OFS_OFS14:      .equ   14                                        ; Offset error correction value bit 14
ADC2OFS_OFS15:      .equ   15                                        ; Offset error correction value bit 15
; bit position masks
mADC2OFS_OFS0:      .equ   %00000001
mADC2OFS_OFS1:      .equ   %00000010
mADC2OFS_OFS2:      .equ   %00000100
mADC2OFS_OFS3:      .equ   %00001000
mADC2OFS_OFS4:      .equ   %00010000
mADC2OFS_OFS5:      .equ   %00100000
mADC2OFS_OFS6:      .equ   %01000000
mADC2OFS_OFS7:      .equ   %10000000
mADC2OFS_OFS8:      .equ   %100000000
mADC2OFS_OFS9:      .equ   %1000000000
mADC2OFS_OFS10:     .equ   %10000000000
mADC2OFS_OFS11:     .equ   %100000000000
mADC2OFS_OFS12:     .equ   %1000000000000
mADC2OFS_OFS13:     .equ   %10000000000000
mADC2OFS_OFS14:     .equ   %100000000000000
mADC2OFS_OFS15:     .equ   %1000000000000000


;*** ADC2OFSH - Offset Correction High Register; 0xFFFF844E ***
ADC2OFSH:           .equ   $FFFF844E                                ;*** ADC2OFSH - Offset Correction High Register; 0xFFFF844E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2OFSH_OFS8:      .equ   0                                         ; Offset error correction value bit 8
ADC2OFSH_OFS9:      .equ   1                                         ; Offset error correction value bit 9
ADC2OFSH_OFS10:     .equ   2                                         ; Offset error correction value bit 10
ADC2OFSH_OFS11:     .equ   3                                         ; Offset error correction value bit 11
ADC2OFSH_OFS12:     .equ   4                                         ; Offset error correction value bit 12
ADC2OFSH_OFS13:     .equ   5                                         ; Offset error correction value bit 13
ADC2OFSH_OFS14:     .equ   6                                         ; Offset error correction value bit 14
ADC2OFSH_OFS15:     .equ   7                                         ; Offset error correction value bit 15
; bit position masks
mADC2OFSH_OFS8:     .equ   %00000001
mADC2OFSH_OFS9:     .equ   %00000010
mADC2OFSH_OFS10:    .equ   %00000100
mADC2OFSH_OFS11:    .equ   %00001000
mADC2OFSH_OFS12:    .equ   %00010000
mADC2OFSH_OFS13:    .equ   %00100000
mADC2OFSH_OFS14:    .equ   %01000000
mADC2OFSH_OFS15:    .equ   %10000000


;*** ADC2OFSL - Offset Correction Low Register; 0xFFFF844F ***
ADC2OFSL:           .equ   $FFFF844F                                ;*** ADC2OFSL - Offset Correction Low Register; 0xFFFF844F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2OFSL_OFS0:      .equ   0                                         ; Offset error correction value bit 0
ADC2OFSL_OFS1:      .equ   1                                         ; Offset error correction value bit 1
ADC2OFSL_OFS2:      .equ   2                                         ; Offset error correction value bit 2
ADC2OFSL_OFS3:      .equ   3                                         ; Offset error correction value bit 3
ADC2OFSL_OFS4:      .equ   4                                         ; Offset error correction value bit 4
ADC2OFSL_OFS5:      .equ   5                                         ; Offset error correction value bit 5
ADC2OFSL_OFS6:      .equ   6                                         ; Offset error correction value bit 6
ADC2OFSL_OFS7:      .equ   7                                         ; Offset error correction value bit 7
; bit position masks
mADC2OFSL_OFS0:     .equ   %00000001
mADC2OFSL_OFS1:     .equ   %00000010
mADC2OFSL_OFS2:     .equ   %00000100
mADC2OFSL_OFS3:     .equ   %00001000
mADC2OFSL_OFS4:     .equ   %00010000
mADC2OFSL_OFS5:     .equ   %00100000
mADC2OFSL_OFS6:     .equ   %01000000
mADC2OFSL_OFS7:     .equ   %10000000


;*** ADC2PG - Plus-Side Gain Register; 0xFFFF8450 ***
ADC2PG:             .equ   $FFFF8450                                ;*** ADC2PG - Plus-Side Gain Register; 0xFFFF8450 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2PG_PG0:         .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC2PG_PG1:         .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC2PG_PG2:         .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC2PG_PG3:         .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC2PG_PG4:         .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC2PG_PG5:         .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC2PG_PG6:         .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC2PG_PG7:         .equ   7                                         ; Gain error correction for the plus-side input value bit 7
ADC2PG_PG8:         .equ   8                                         ; Gain error correction for the plus-side input value bit 8
ADC2PG_PG9:         .equ   9                                         ; Gain error correction for the plus-side input value bit 9
ADC2PG_PG10:        .equ   10                                        ; Gain error correction for the plus-side input value bit 10
ADC2PG_PG11:        .equ   11                                        ; Gain error correction for the plus-side input value bit 11
ADC2PG_PG12:        .equ   12                                        ; Gain error correction for the plus-side input value bit 12
ADC2PG_PG13:        .equ   13                                        ; Gain error correction for the plus-side input value bit 13
ADC2PG_PG14:        .equ   14                                        ; Gain error correction for the plus-side input value bit 14
ADC2PG_PG15:        .equ   15                                        ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC2PG_PG0:        .equ   %00000001
mADC2PG_PG1:        .equ   %00000010
mADC2PG_PG2:        .equ   %00000100
mADC2PG_PG3:        .equ   %00001000
mADC2PG_PG4:        .equ   %00010000
mADC2PG_PG5:        .equ   %00100000
mADC2PG_PG6:        .equ   %01000000
mADC2PG_PG7:        .equ   %10000000
mADC2PG_PG8:        .equ   %100000000
mADC2PG_PG9:        .equ   %1000000000
mADC2PG_PG10:       .equ   %10000000000
mADC2PG_PG11:       .equ   %100000000000
mADC2PG_PG12:       .equ   %1000000000000
mADC2PG_PG13:       .equ   %10000000000000
mADC2PG_PG14:       .equ   %100000000000000
mADC2PG_PG15:       .equ   %1000000000000000


;*** ADC2PGH - Plus-Side Gain High Register; 0xFFFF8450 ***
ADC2PGH:            .equ   $FFFF8450                                ;*** ADC2PGH - Plus-Side Gain High Register; 0xFFFF8450 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2PGH_PG8:        .equ   0                                         ; Gain error correction for the plus-side input value bit 8
ADC2PGH_PG9:        .equ   1                                         ; Gain error correction for the plus-side input value bit 9
ADC2PGH_PG10:       .equ   2                                         ; Gain error correction for the plus-side input value bit 10
ADC2PGH_PG11:       .equ   3                                         ; Gain error correction for the plus-side input value bit 11
ADC2PGH_PG12:       .equ   4                                         ; Gain error correction for the plus-side input value bit 12
ADC2PGH_PG13:       .equ   5                                         ; Gain error correction for the plus-side input value bit 13
ADC2PGH_PG14:       .equ   6                                         ; Gain error correction for the plus-side input value bit 14
ADC2PGH_PG15:       .equ   7                                         ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC2PGH_PG8:       .equ   %00000001
mADC2PGH_PG9:       .equ   %00000010
mADC2PGH_PG10:      .equ   %00000100
mADC2PGH_PG11:      .equ   %00001000
mADC2PGH_PG12:      .equ   %00010000
mADC2PGH_PG13:      .equ   %00100000
mADC2PGH_PG14:      .equ   %01000000
mADC2PGH_PG15:      .equ   %10000000


;*** ADC2PGL - Plus-Side Gain Low Register; 0xFFFF8451 ***
ADC2PGL:            .equ   $FFFF8451                                ;*** ADC2PGL - Plus-Side Gain Low Register; 0xFFFF8451 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2PGL_PG0:        .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC2PGL_PG1:        .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC2PGL_PG2:        .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC2PGL_PG3:        .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC2PGL_PG4:        .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC2PGL_PG5:        .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC2PGL_PG6:        .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC2PGL_PG7:        .equ   7                                         ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADC2PGL_PG0:       .equ   %00000001
mADC2PGL_PG1:       .equ   %00000010
mADC2PGL_PG2:       .equ   %00000100
mADC2PGL_PG3:       .equ   %00001000
mADC2PGL_PG4:       .equ   %00010000
mADC2PGL_PG5:       .equ   %00100000
mADC2PGL_PG6:       .equ   %01000000
mADC2PGL_PG7:       .equ   %10000000


;*** ADC2MG - Minus-Side Gain Register; 0xFFFF8452 ***
ADC2MG:             .equ   $FFFF8452                                ;*** ADC2MG - Minus-Side Gain Register; 0xFFFF8452 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2MG_MG0:         .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC2MG_MG1:         .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC2MG_MG2:         .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC2MG_MG3:         .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC2MG_MG4:         .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC2MG_MG5:         .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC2MG_MG6:         .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC2MG_MG7:         .equ   7                                         ; Gain error correction for the minus-side input value bit 7
ADC2MG_MG8:         .equ   8                                         ; Gain error correction for the minus-side input value bit 8
ADC2MG_MG9:         .equ   9                                         ; Gain error correction for the minus-side input value bit 9
ADC2MG_MG10:        .equ   10                                        ; Gain error correction for the minus-side input value bit 10
ADC2MG_MG11:        .equ   11                                        ; Gain error correction for the minus-side input value bit 11
ADC2MG_MG12:        .equ   12                                        ; Gain error correction for the minus-side input value bit 12
ADC2MG_MG13:        .equ   13                                        ; Gain error correction for the minus-side input value bit 13
ADC2MG_MG14:        .equ   14                                        ; Gain error correction for the minus-side input value bit 14
ADC2MG_MG15:        .equ   15                                        ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC2MG_MG0:        .equ   %00000001
mADC2MG_MG1:        .equ   %00000010
mADC2MG_MG2:        .equ   %00000100
mADC2MG_MG3:        .equ   %00001000
mADC2MG_MG4:        .equ   %00010000
mADC2MG_MG5:        .equ   %00100000
mADC2MG_MG6:        .equ   %01000000
mADC2MG_MG7:        .equ   %10000000
mADC2MG_MG8:        .equ   %100000000
mADC2MG_MG9:        .equ   %1000000000
mADC2MG_MG10:       .equ   %10000000000
mADC2MG_MG11:       .equ   %100000000000
mADC2MG_MG12:       .equ   %1000000000000
mADC2MG_MG13:       .equ   %10000000000000
mADC2MG_MG14:       .equ   %100000000000000
mADC2MG_MG15:       .equ   %1000000000000000


;*** ADC2MGH - Minus-Side Gain High Register; 0xFFFF8452 ***
ADC2MGH:            .equ   $FFFF8452                                ;*** ADC2MGH - Minus-Side Gain High Register; 0xFFFF8452 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2MGH_MG8:        .equ   0                                         ; Gain error correction for the minus-side input value bit 8
ADC2MGH_MG9:        .equ   1                                         ; Gain error correction for the minus-side input value bit 9
ADC2MGH_MG10:       .equ   2                                         ; Gain error correction for the minus-side input value bit 10
ADC2MGH_MG11:       .equ   3                                         ; Gain error correction for the minus-side input value bit 11
ADC2MGH_MG12:       .equ   4                                         ; Gain error correction for the minus-side input value bit 12
ADC2MGH_MG13:       .equ   5                                         ; Gain error correction for the minus-side input value bit 13
ADC2MGH_MG14:       .equ   6                                         ; Gain error correction for the minus-side input value bit 14
ADC2MGH_MG15:       .equ   7                                         ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC2MGH_MG8:       .equ   %00000001
mADC2MGH_MG9:       .equ   %00000010
mADC2MGH_MG10:      .equ   %00000100
mADC2MGH_MG11:      .equ   %00001000
mADC2MGH_MG12:      .equ   %00010000
mADC2MGH_MG13:      .equ   %00100000
mADC2MGH_MG14:      .equ   %01000000
mADC2MGH_MG15:      .equ   %10000000


;*** ADC2MGL - Minus-Side Gain Low Register; 0xFFFF8453 ***
ADC2MGL:            .equ   $FFFF8453                                ;*** ADC2MGL - Minus-Side Gain Low Register; 0xFFFF8453 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2MGL_MG0:        .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC2MGL_MG1:        .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC2MGL_MG2:        .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC2MGL_MG3:        .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC2MGL_MG4:        .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC2MGL_MG5:        .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC2MGL_MG6:        .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC2MGL_MG7:        .equ   7                                         ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADC2MGL_MG0:       .equ   %00000001
mADC2MGL_MG1:       .equ   %00000010
mADC2MGL_MG2:       .equ   %00000100
mADC2MGL_MG3:       .equ   %00001000
mADC2MGL_MG4:       .equ   %00010000
mADC2MGL_MG5:       .equ   %00100000
mADC2MGL_MG6:       .equ   %01000000
mADC2MGL_MG7:       .equ   %10000000


;*** ADC2CLPD - Plus-Side General Calibration Value D Register; 0xFFFF8454 ***
ADC2CLPD:           .equ   $FFFF8454                                ;*** ADC2CLPD - Plus-Side General Calibration Value D Register; 0xFFFF8454 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLPD_CLPD0:     .equ   0                                         ; Plus-Side General Calibration Value D bit 0
ADC2CLPD_CLPD1:     .equ   1                                         ; Plus-Side General Calibration Value D bit 1
ADC2CLPD_CLPD2:     .equ   2                                         ; Plus-Side General Calibration Value D bit 2
ADC2CLPD_CLPD3:     .equ   3                                         ; Plus-Side General Calibration Value D bit 3
ADC2CLPD_CLPD4:     .equ   4                                         ; Plus-Side General Calibration Value D bit 4
ADC2CLPD_CLPD5:     .equ   5                                         ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADC2CLPD_CLPD0:    .equ   %00000001
mADC2CLPD_CLPD1:    .equ   %00000010
mADC2CLPD_CLPD2:    .equ   %00000100
mADC2CLPD_CLPD3:    .equ   %00001000
mADC2CLPD_CLPD4:    .equ   %00010000
mADC2CLPD_CLPD5:    .equ   %00100000


;*** ADC2CLPS - Plus-Side General Calibration Value S Register; 0xFFFF8455 ***
ADC2CLPS:           .equ   $FFFF8455                                ;*** ADC2CLPS - Plus-Side General Calibration Value S Register; 0xFFFF8455 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLPS_CLPS0:     .equ   0                                         ; Plus-Side General Calibration Value S bit 0
ADC2CLPS_CLPS1:     .equ   1                                         ; Plus-Side General Calibration Value S bit 1
ADC2CLPS_CLPS2:     .equ   2                                         ; Plus-Side General Calibration Value S bit 2
ADC2CLPS_CLPS3:     .equ   3                                         ; Plus-Side General Calibration Value S bit 3
ADC2CLPS_CLPS4:     .equ   4                                         ; Plus-Side General Calibration Value S bit 4
ADC2CLPS_CLPS5:     .equ   5                                         ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADC2CLPS_CLPS0:    .equ   %00000001
mADC2CLPS_CLPS1:    .equ   %00000010
mADC2CLPS_CLPS2:    .equ   %00000100
mADC2CLPS_CLPS3:    .equ   %00001000
mADC2CLPS_CLPS4:    .equ   %00010000
mADC2CLPS_CLPS5:    .equ   %00100000


;*** ADC2CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF8456 ***
ADC2CLP4:           .equ   $FFFF8456                                ;*** ADC2CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF8456 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP4_CLP40:     .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC2CLP4_CLP41:     .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC2CLP4_CLP42:     .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC2CLP4_CLP43:     .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC2CLP4_CLP44:     .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC2CLP4_CLP45:     .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC2CLP4_CLP46:     .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC2CLP4_CLP47:     .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
ADC2CLP4_CLP48:     .equ   8                                         ; Plus-Side General Calibration Value 4 bit 8
ADC2CLP4_CLP49:     .equ   9                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC2CLP4_CLP40:    .equ   %00000001
mADC2CLP4_CLP41:    .equ   %00000010
mADC2CLP4_CLP42:    .equ   %00000100
mADC2CLP4_CLP43:    .equ   %00001000
mADC2CLP4_CLP44:    .equ   %00010000
mADC2CLP4_CLP45:    .equ   %00100000
mADC2CLP4_CLP46:    .equ   %01000000
mADC2CLP4_CLP47:    .equ   %10000000
mADC2CLP4_CLP48:    .equ   %100000000
mADC2CLP4_CLP49:    .equ   %1000000000


;*** ADC2CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF8456 ***
ADC2CLP4H:          .equ   $FFFF8456                                ;*** ADC2CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF8456 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP4H_CLP48:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 8
ADC2CLP4H_CLP49:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC2CLP4H_CLP48:   .equ   %00000001
mADC2CLP4H_CLP49:   .equ   %00000010


;*** ADC2CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF8457 ***
ADC2CLP4L:          .equ   $FFFF8457                                ;*** ADC2CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF8457 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP4L_CLP40:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC2CLP4L_CLP41:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC2CLP4L_CLP42:    .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC2CLP4L_CLP43:    .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC2CLP4L_CLP44:    .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC2CLP4L_CLP45:    .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC2CLP4L_CLP46:    .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC2CLP4L_CLP47:    .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADC2CLP4L_CLP40:   .equ   %00000001
mADC2CLP4L_CLP41:   .equ   %00000010
mADC2CLP4L_CLP42:   .equ   %00000100
mADC2CLP4L_CLP43:   .equ   %00001000
mADC2CLP4L_CLP44:   .equ   %00010000
mADC2CLP4L_CLP45:   .equ   %00100000
mADC2CLP4L_CLP46:   .equ   %01000000
mADC2CLP4L_CLP47:   .equ   %10000000


;*** ADC2CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF8458 ***
ADC2CLP3:           .equ   $FFFF8458                                ;*** ADC2CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF8458 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP3_CLP30:     .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC2CLP3_CLP31:     .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC2CLP3_CLP32:     .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC2CLP3_CLP33:     .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC2CLP3_CLP34:     .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC2CLP3_CLP35:     .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC2CLP3_CLP36:     .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC2CLP3_CLP37:     .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
ADC2CLP3_CLP38:     .equ   8                                         ; Plus-Side General Calibration Value 3 bit 8
; bit position masks
mADC2CLP3_CLP30:    .equ   %00000001
mADC2CLP3_CLP31:    .equ   %00000010
mADC2CLP3_CLP32:    .equ   %00000100
mADC2CLP3_CLP33:    .equ   %00001000
mADC2CLP3_CLP34:    .equ   %00010000
mADC2CLP3_CLP35:    .equ   %00100000
mADC2CLP3_CLP36:    .equ   %01000000
mADC2CLP3_CLP37:    .equ   %10000000
mADC2CLP3_CLP38:    .equ   %100000000


;*** ADC2CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF8458 ***
ADC2CLP3H:          .equ   $FFFF8458                                ;*** ADC2CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF8458 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP3H_CLP38:    .equ   0                                         ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADC2CLP3H_CLP38:   .equ   %00000001


;*** ADC2CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF8459 ***
ADC2CLP3L:          .equ   $FFFF8459                                ;*** ADC2CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF8459 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP3L_CLP30:    .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC2CLP3L_CLP31:    .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC2CLP3L_CLP32:    .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC2CLP3L_CLP33:    .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC2CLP3L_CLP34:    .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC2CLP3L_CLP35:    .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC2CLP3L_CLP36:    .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC2CLP3L_CLP37:    .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADC2CLP3L_CLP30:   .equ   %00000001
mADC2CLP3L_CLP31:   .equ   %00000010
mADC2CLP3L_CLP32:   .equ   %00000100
mADC2CLP3L_CLP33:   .equ   %00001000
mADC2CLP3L_CLP34:   .equ   %00010000
mADC2CLP3L_CLP35:   .equ   %00100000
mADC2CLP3L_CLP36:   .equ   %01000000
mADC2CLP3L_CLP37:   .equ   %10000000


;*** ADC2CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF845A ***
ADC2CLP2:           .equ   $FFFF845A                                ;*** ADC2CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF845A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP2_CLP20:     .equ   0                                         ; Plus-Side General Calibration Value 2 bit 0
ADC2CLP2_CLP21:     .equ   1                                         ; Plus-Side General Calibration Value 2 bit 1
ADC2CLP2_CLP22:     .equ   2                                         ; Plus-Side General Calibration Value 2 bit 2
ADC2CLP2_CLP23:     .equ   3                                         ; Plus-Side General Calibration Value 2 bit 3
ADC2CLP2_CLP24:     .equ   4                                         ; Plus-Side General Calibration Value 2 bit 4
ADC2CLP2_CLP25:     .equ   5                                         ; Plus-Side General Calibration Value 2 bit 5
ADC2CLP2_CLP26:     .equ   6                                         ; Plus-Side General Calibration Value 2 bit 6
ADC2CLP2_CLP27:     .equ   7                                         ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADC2CLP2_CLP20:    .equ   %00000001
mADC2CLP2_CLP21:    .equ   %00000010
mADC2CLP2_CLP22:    .equ   %00000100
mADC2CLP2_CLP23:    .equ   %00001000
mADC2CLP2_CLP24:    .equ   %00010000
mADC2CLP2_CLP25:    .equ   %00100000
mADC2CLP2_CLP26:    .equ   %01000000
mADC2CLP2_CLP27:    .equ   %10000000


;*** ADC2CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF845B ***
ADC2CLP1:           .equ   $FFFF845B                                ;*** ADC2CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF845B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP1_CLP10:     .equ   0                                         ; Plus-Side General Calibration Value 1 bit 0
ADC2CLP1_CLP11:     .equ   1                                         ; Plus-Side General Calibration Value 1 bit 1
ADC2CLP1_CLP12:     .equ   2                                         ; Plus-Side General Calibration Value 1 bit 2
ADC2CLP1_CLP13:     .equ   3                                         ; Plus-Side General Calibration Value 1 bit 3
ADC2CLP1_CLP14:     .equ   4                                         ; Plus-Side General Calibration Value 1 bit 4
ADC2CLP1_CLP15:     .equ   5                                         ; Plus-Side General Calibration Value 1 bit 5
ADC2CLP1_CLP16:     .equ   6                                         ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADC2CLP1_CLP10:    .equ   %00000001
mADC2CLP1_CLP11:    .equ   %00000010
mADC2CLP1_CLP12:    .equ   %00000100
mADC2CLP1_CLP13:    .equ   %00001000
mADC2CLP1_CLP14:    .equ   %00010000
mADC2CLP1_CLP15:    .equ   %00100000
mADC2CLP1_CLP16:    .equ   %01000000


;*** ADC2CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF845C ***
ADC2CLP0:           .equ   $FFFF845C                                ;*** ADC2CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF845C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLP0_CLP00:     .equ   0                                         ; Plus-Side General Calibration Value 0 bit 0
ADC2CLP0_CLP01:     .equ   1                                         ; Plus-Side General Calibration Value 0 bit 1
ADC2CLP0_CLP02:     .equ   2                                         ; Plus-Side General Calibration Value 0 bit 2
ADC2CLP0_CLP03:     .equ   3                                         ; Plus-Side General Calibration Value 0 bit 3
ADC2CLP0_CLP04:     .equ   4                                         ; Plus-Side General Calibration Value 0 bit 4
ADC2CLP0_CLP05:     .equ   5                                         ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADC2CLP0_CLP00:    .equ   %00000001
mADC2CLP0_CLP01:    .equ   %00000010
mADC2CLP0_CLP02:    .equ   %00000100
mADC2CLP0_CLP03:    .equ   %00001000
mADC2CLP0_CLP04:    .equ   %00010000
mADC2CLP0_CLP05:    .equ   %00100000


;*** ADC2CLMD - Minus-Side General Calibration Value D Register; 0xFFFF845E ***
ADC2CLMD:           .equ   $FFFF845E                                ;*** ADC2CLMD - Minus-Side General Calibration Value D Register; 0xFFFF845E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLMD_CLMD0:     .equ   0                                         ; Minus-Side General Calibration Value D bit 0
ADC2CLMD_CLMD1:     .equ   1                                         ; Minus-Side General Calibration Value D bit 1
ADC2CLMD_CLMD2:     .equ   2                                         ; Minus-Side General Calibration Value D bit 2
ADC2CLMD_CLMD3:     .equ   3                                         ; Minus-Side General Calibration Value D bit 3
ADC2CLMD_CLMD4:     .equ   4                                         ; Minus-Side General Calibration Value D bit 4
ADC2CLMD_CLMD5:     .equ   5                                         ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADC2CLMD_CLMD0:    .equ   %00000001
mADC2CLMD_CLMD1:    .equ   %00000010
mADC2CLMD_CLMD2:    .equ   %00000100
mADC2CLMD_CLMD3:    .equ   %00001000
mADC2CLMD_CLMD4:    .equ   %00010000
mADC2CLMD_CLMD5:    .equ   %00100000


;*** ADC2CLMS - Minus-Side General Calibration Value S Register; 0xFFFF845F ***
ADC2CLMS:           .equ   $FFFF845F                                ;*** ADC2CLMS - Minus-Side General Calibration Value S Register; 0xFFFF845F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLMS_CLMS0:     .equ   0                                         ; Minus-Side General Calibration Value S bit 0
ADC2CLMS_CLMS1:     .equ   1                                         ; Minus-Side General Calibration Value S bit 1
ADC2CLMS_CLMS2:     .equ   2                                         ; Minus-Side General Calibration Value S bit 2
ADC2CLMS_CLMS3:     .equ   3                                         ; Minus-Side General Calibration Value S bit 3
ADC2CLMS_CLMS4:     .equ   4                                         ; Minus-Side General Calibration Value S bit 4
ADC2CLMS_CLMS5:     .equ   5                                         ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADC2CLMS_CLMS0:    .equ   %00000001
mADC2CLMS_CLMS1:    .equ   %00000010
mADC2CLMS_CLMS2:    .equ   %00000100
mADC2CLMS_CLMS3:    .equ   %00001000
mADC2CLMS_CLMS4:    .equ   %00010000
mADC2CLMS_CLMS5:    .equ   %00100000


;*** ADC2CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF8460 ***
ADC2CLM4:           .equ   $FFFF8460                                ;*** ADC2CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF8460 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM4_CLM40:     .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC2CLM4_CLM41:     .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC2CLM4_CLM42:     .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC2CLM4_CLM43:     .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC2CLM4_CLM44:     .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC2CLM4_CLM45:     .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC2CLM4_CLM46:     .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC2CLM4_CLM47:     .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
ADC2CLM4_CLM48:     .equ   8                                         ; Minus-Side General Calibration Value 4 bit 8
ADC2CLM4_CLM49:     .equ   9                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC2CLM4_CLM40:    .equ   %00000001
mADC2CLM4_CLM41:    .equ   %00000010
mADC2CLM4_CLM42:    .equ   %00000100
mADC2CLM4_CLM43:    .equ   %00001000
mADC2CLM4_CLM44:    .equ   %00010000
mADC2CLM4_CLM45:    .equ   %00100000
mADC2CLM4_CLM46:    .equ   %01000000
mADC2CLM4_CLM47:    .equ   %10000000
mADC2CLM4_CLM48:    .equ   %100000000
mADC2CLM4_CLM49:    .equ   %1000000000


;*** ADC2CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF8460 ***
ADC2CLM4H:          .equ   $FFFF8460                                ;*** ADC2CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF8460 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM4H_CLM48:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 8
ADC2CLM4H_CLM49:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC2CLM4H_CLM48:   .equ   %00000001
mADC2CLM4H_CLM49:   .equ   %00000010


;*** ADC2CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF8461 ***
ADC2CLM4L:          .equ   $FFFF8461                                ;*** ADC2CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF8461 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM4L_CLM40:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC2CLM4L_CLM41:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC2CLM4L_CLM42:    .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC2CLM4L_CLM43:    .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC2CLM4L_CLM44:    .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC2CLM4L_CLM45:    .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC2CLM4L_CLM46:    .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC2CLM4L_CLM47:    .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADC2CLM4L_CLM40:   .equ   %00000001
mADC2CLM4L_CLM41:   .equ   %00000010
mADC2CLM4L_CLM42:   .equ   %00000100
mADC2CLM4L_CLM43:   .equ   %00001000
mADC2CLM4L_CLM44:   .equ   %00010000
mADC2CLM4L_CLM45:   .equ   %00100000
mADC2CLM4L_CLM46:   .equ   %01000000
mADC2CLM4L_CLM47:   .equ   %10000000


;*** ADC2CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF8462 ***
ADC2CLM3:           .equ   $FFFF8462                                ;*** ADC2CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF8462 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM3_CLM30:     .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC2CLM3_CLM31:     .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC2CLM3_CLM32:     .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC2CLM3_CLM33:     .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC2CLM3_CLM34:     .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC2CLM3_CLM35:     .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC2CLM3_CLM36:     .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC2CLM3_CLM37:     .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
ADC2CLM3_CLM38:     .equ   8                                         ; Minus-Side General Calibration Value 3 bit 8
; bit position masks
mADC2CLM3_CLM30:    .equ   %00000001
mADC2CLM3_CLM31:    .equ   %00000010
mADC2CLM3_CLM32:    .equ   %00000100
mADC2CLM3_CLM33:    .equ   %00001000
mADC2CLM3_CLM34:    .equ   %00010000
mADC2CLM3_CLM35:    .equ   %00100000
mADC2CLM3_CLM36:    .equ   %01000000
mADC2CLM3_CLM37:    .equ   %10000000
mADC2CLM3_CLM38:    .equ   %100000000


;*** ADC2CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF8462 ***
ADC2CLM3H:          .equ   $FFFF8462                                ;*** ADC2CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF8462 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM3H_CLM38:    .equ   0                                         ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADC2CLM3H_CLM38:   .equ   %00000001


;*** ADC2CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF8463 ***
ADC2CLM3L:          .equ   $FFFF8463                                ;*** ADC2CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF8463 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM3L_CLM30:    .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC2CLM3L_CLM31:    .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC2CLM3L_CLM32:    .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC2CLM3L_CLM33:    .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC2CLM3L_CLM34:    .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC2CLM3L_CLM35:    .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC2CLM3L_CLM36:    .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC2CLM3L_CLM37:    .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADC2CLM3L_CLM30:   .equ   %00000001
mADC2CLM3L_CLM31:   .equ   %00000010
mADC2CLM3L_CLM32:   .equ   %00000100
mADC2CLM3L_CLM33:   .equ   %00001000
mADC2CLM3L_CLM34:   .equ   %00010000
mADC2CLM3L_CLM35:   .equ   %00100000
mADC2CLM3L_CLM36:   .equ   %01000000
mADC2CLM3L_CLM37:   .equ   %10000000


;*** ADC2CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF8464 ***
ADC2CLM2:           .equ   $FFFF8464                                ;*** ADC2CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF8464 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM2_CLM20:     .equ   0                                         ; Minus-Side General Calibration Value 2 bit 0
ADC2CLM2_CLM21:     .equ   1                                         ; Minus-Side General Calibration Value 2 bit 1
ADC2CLM2_CLM22:     .equ   2                                         ; Minus-Side General Calibration Value 2 bit 2
ADC2CLM2_CLM23:     .equ   3                                         ; Minus-Side General Calibration Value 2 bit 3
ADC2CLM2_CLM24:     .equ   4                                         ; Minus-Side General Calibration Value 2 bit 4
ADC2CLM2_CLM25:     .equ   5                                         ; Minus-Side General Calibration Value 2 bit 5
ADC2CLM2_CLM26:     .equ   6                                         ; Minus-Side General Calibration Value 2 bit 6
ADC2CLM2_CLM27:     .equ   7                                         ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADC2CLM2_CLM20:    .equ   %00000001
mADC2CLM2_CLM21:    .equ   %00000010
mADC2CLM2_CLM22:    .equ   %00000100
mADC2CLM2_CLM23:    .equ   %00001000
mADC2CLM2_CLM24:    .equ   %00010000
mADC2CLM2_CLM25:    .equ   %00100000
mADC2CLM2_CLM26:    .equ   %01000000
mADC2CLM2_CLM27:    .equ   %10000000


;*** ADC2CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF8465 ***
ADC2CLM1:           .equ   $FFFF8465                                ;*** ADC2CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF8465 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM1_CLM10:     .equ   0                                         ; Minus-Side General Calibration Value 1 bit 0
ADC2CLM1_CLM11:     .equ   1                                         ; Minus-Side General Calibration Value 1 bit 1
ADC2CLM1_CLM12:     .equ   2                                         ; Minus-Side General Calibration Value 1 bit 2
ADC2CLM1_CLM13:     .equ   3                                         ; Minus-Side General Calibration Value 1 bit 3
ADC2CLM1_CLM14:     .equ   4                                         ; Minus-Side General Calibration Value 1 bit 4
ADC2CLM1_CLM15:     .equ   5                                         ; Minus-Side General Calibration Value 1 bit 5
ADC2CLM1_CLM16:     .equ   6                                         ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADC2CLM1_CLM10:    .equ   %00000001
mADC2CLM1_CLM11:    .equ   %00000010
mADC2CLM1_CLM12:    .equ   %00000100
mADC2CLM1_CLM13:    .equ   %00001000
mADC2CLM1_CLM14:    .equ   %00010000
mADC2CLM1_CLM15:    .equ   %00100000
mADC2CLM1_CLM16:    .equ   %01000000


;*** ADC2CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF8466 ***
ADC2CLM0:           .equ   $FFFF8466                                ;*** ADC2CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF8466 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC2CLM0_CLM00:     .equ   0                                         ; Minus-Side General Calibration Value 0 bit 0
ADC2CLM0_CLM01:     .equ   1                                         ; Minus-Side General Calibration Value 0 bit 1
ADC2CLM0_CLM02:     .equ   2                                         ; Minus-Side General Calibration Value 0 bit 2
ADC2CLM0_CLM03:     .equ   3                                         ; Minus-Side General Calibration Value 0 bit 3
ADC2CLM0_CLM04:     .equ   4                                         ; Minus-Side General Calibration Value 0 bit 4
ADC2CLM0_CLM05:     .equ   5                                         ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADC2CLM0_CLM00:    .equ   %00000001
mADC2CLM0_CLM01:    .equ   %00000010
mADC2CLM0_CLM02:    .equ   %00000100
mADC2CLM0_CLM03:    .equ   %00001000
mADC2CLM0_CLM04:    .equ   %00010000
mADC2CLM0_CLM05:    .equ   %00100000


;*** ADC3SC1A - Status and Control Register 1A; 0xFFFF8480 ***
ADC3SC1A:           .equ   $FFFF8480                                ;*** ADC3SC1A - Status and Control Register 1A; 0xFFFF8480 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3SC1A_ADCHA0:    .equ   0                                         ; Input Channel Select Bit 0
ADC3SC1A_ADCHA1:    .equ   1                                         ; Input Channel Select Bit 1
ADC3SC1A_ADCHA2:    .equ   2                                         ; Input Channel Select Bit 2
ADC3SC1A_ADCHA3:    .equ   3                                         ; Input Channel Select Bit 3
ADC3SC1A_ADCHA4:    .equ   4                                         ; Input Channel Select Bit 4
ADC3SC1A_DIFFA:     .equ   5                                         ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADC3SC1A_AIENA:     .equ   6                                         ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA is high, an interrupt is asserted
ADC3SC1A_COCOA:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC3SC1A_ADCHA0:   .equ   %00000001
mADC3SC1A_ADCHA1:   .equ   %00000010
mADC3SC1A_ADCHA2:   .equ   %00000100
mADC3SC1A_ADCHA3:   .equ   %00001000
mADC3SC1A_ADCHA4:   .equ   %00010000
mADC3SC1A_DIFFA:    .equ   %00100000
mADC3SC1A_AIENA:    .equ   %01000000
mADC3SC1A_COCOA:    .equ   %10000000


;*** ADC3SC1B - Status and Control Register 1B; 0xFFFF8481 ***
ADC3SC1B:           .equ   $FFFF8481                                ;*** ADC3SC1B - Status and Control Register 1B; 0xFFFF8481 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3SC1B_ADCHB0:    .equ   0                                         ; Input Channel Select Bit 0
ADC3SC1B_ADCHB1:    .equ   1                                         ; Input Channel Select Bit 1
ADC3SC1B_ADCHB2:    .equ   2                                         ; Input Channel Select Bit 2
ADC3SC1B_ADCHB3:    .equ   3                                         ; Input Channel Select Bit 3
ADC3SC1B_ADCHB4:    .equ   4                                         ; Input Channel Select Bit 4
ADC3SC1B_DIFFB:     .equ   5                                         ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADC3SC1B_AIENB:     .equ   6                                         ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB is high, an interrupt is asserted
ADC3SC1B_COCOB:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC3SC1B_ADCHB0:   .equ   %00000001
mADC3SC1B_ADCHB1:   .equ   %00000010
mADC3SC1B_ADCHB2:   .equ   %00000100
mADC3SC1B_ADCHB3:   .equ   %00001000
mADC3SC1B_ADCHB4:   .equ   %00010000
mADC3SC1B_DIFFB:    .equ   %00100000
mADC3SC1B_AIENB:    .equ   %01000000
mADC3SC1B_COCOB:    .equ   %10000000


;*** ADC3CFG1 - Configuration Register 1; 0xFFFF8482 ***
ADC3CFG1:           .equ   $FFFF8482                                ;*** ADC3CFG1 - Configuration Register 1; 0xFFFF8482 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CFG1_ADICLK0:   .equ   0                                         ; Input Clock Select Bit 0
ADC3CFG1_ADICLK1:   .equ   1                                         ; Input Clock Select Bit 1
ADC3CFG1_MODE0:     .equ   2                                         ; Conversion Mode Selection Bit 0
ADC3CFG1_MODE1:     .equ   3                                         ; Conversion Mode Selection Bit 1
ADC3CFG1_ADLSMP:    .equ   4                                         ; Long Sample Time Configuration
ADC3CFG1_ADIV0:     .equ   5                                         ; Clock Divide Select Bit 0
ADC3CFG1_ADIV1:     .equ   6                                         ; Clock Divide Select Bit 1
ADC3CFG1_ADLPC:     .equ   7                                         ; Low Power Configuration
; bit position masks
mADC3CFG1_ADICLK0:  .equ   %00000001
mADC3CFG1_ADICLK1:  .equ   %00000010
mADC3CFG1_MODE0:    .equ   %00000100
mADC3CFG1_MODE1:    .equ   %00001000
mADC3CFG1_ADLSMP:   .equ   %00010000
mADC3CFG1_ADIV0:    .equ   %00100000
mADC3CFG1_ADIV1:    .equ   %01000000
mADC3CFG1_ADLPC:    .equ   %10000000


;*** ADC3CFG2 - Configuration Register 2; 0xFFFF8483 ***
ADC3CFG2:           .equ   $FFFF8483                                ;*** ADC3CFG2 - Configuration Register 2; 0xFFFF8483 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CFG2_ADLSTS0:   .equ   0                                         ; Long Sample Time Select Bit 0
ADC3CFG2_ADLSTS1:   .equ   1                                         ; Long Sample Time Select Bit 1
ADC3CFG2_ADHSC:     .equ   2                                         ; High Speed Configuration
ADC3CFG2_ADACKEN:   .equ   3                                         ; Asynchronous Clock Output Enable
; bit position masks
mADC3CFG2_ADLSTS0:  .equ   %00000001
mADC3CFG2_ADLSTS1:  .equ   %00000010
mADC3CFG2_ADHSC:    .equ   %00000100
mADC3CFG2_ADACKEN:  .equ   %00001000


;*** ADC3RA - Data Result Register A; 0xFFFF8484 ***
ADC3RA:             .equ   $FFFF8484                                ;*** ADC3RA - Data Result Register A; 0xFFFF8484 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3RA_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC3RA_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC3RA_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC3RA_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC3RA_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC3RA_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC3RA_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC3RA_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC3RA_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC3RA_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC3RA_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC3RA_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC3RA_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC3RA_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC3RA_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC3RA_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC3RA_D0:         .equ   %00000001
mADC3RA_D1:         .equ   %00000010
mADC3RA_D2:         .equ   %00000100
mADC3RA_D3:         .equ   %00001000
mADC3RA_D4:         .equ   %00010000
mADC3RA_D5:         .equ   %00100000
mADC3RA_D6:         .equ   %01000000
mADC3RA_D7:         .equ   %10000000
mADC3RA_D8:         .equ   %100000000
mADC3RA_D9:         .equ   %1000000000
mADC3RA_D10:        .equ   %10000000000
mADC3RA_D11:        .equ   %100000000000
mADC3RA_D12:        .equ   %1000000000000
mADC3RA_D13:        .equ   %10000000000000
mADC3RA_D14:        .equ   %100000000000000
mADC3RA_D15:        .equ   %1000000000000000


;*** ADC3RHA - Data Result High Register A; 0xFFFF8484 ***
ADC3RHA:            .equ   $FFFF8484                                ;*** ADC3RHA - Data Result High Register A; 0xFFFF8484 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3RHA_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC3RHA_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC3RHA_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC3RHA_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC3RHA_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC3RHA_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC3RHA_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC3RHA_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC3RHA_D8:        .equ   %00000001
mADC3RHA_D9:        .equ   %00000010
mADC3RHA_D10:       .equ   %00000100
mADC3RHA_D11:       .equ   %00001000
mADC3RHA_D12:       .equ   %00010000
mADC3RHA_D13:       .equ   %00100000
mADC3RHA_D14:       .equ   %01000000
mADC3RHA_D15:       .equ   %10000000


;*** ADC3RLA - Data Result Low Register A; 0xFFFF8485 ***
ADC3RLA:            .equ   $FFFF8485                                ;*** ADC3RLA - Data Result Low Register A; 0xFFFF8485 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3RLA_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC3RLA_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC3RLA_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC3RLA_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC3RLA_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC3RLA_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC3RLA_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC3RLA_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC3RLA_D0:        .equ   %00000001
mADC3RLA_D1:        .equ   %00000010
mADC3RLA_D2:        .equ   %00000100
mADC3RLA_D3:        .equ   %00001000
mADC3RLA_D4:        .equ   %00010000
mADC3RLA_D5:        .equ   %00100000
mADC3RLA_D6:        .equ   %01000000
mADC3RLA_D7:        .equ   %10000000


;*** ADC3RB - Data Result Register B; 0xFFFF8486 ***
ADC3RB:             .equ   $FFFF8486                                ;*** ADC3RB - Data Result Register B; 0xFFFF8486 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3RB_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC3RB_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC3RB_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC3RB_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC3RB_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC3RB_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC3RB_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC3RB_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC3RB_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC3RB_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC3RB_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC3RB_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC3RB_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC3RB_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC3RB_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC3RB_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC3RB_D0:         .equ   %00000001
mADC3RB_D1:         .equ   %00000010
mADC3RB_D2:         .equ   %00000100
mADC3RB_D3:         .equ   %00001000
mADC3RB_D4:         .equ   %00010000
mADC3RB_D5:         .equ   %00100000
mADC3RB_D6:         .equ   %01000000
mADC3RB_D7:         .equ   %10000000
mADC3RB_D8:         .equ   %100000000
mADC3RB_D9:         .equ   %1000000000
mADC3RB_D10:        .equ   %10000000000
mADC3RB_D11:        .equ   %100000000000
mADC3RB_D12:        .equ   %1000000000000
mADC3RB_D13:        .equ   %10000000000000
mADC3RB_D14:        .equ   %100000000000000
mADC3RB_D15:        .equ   %1000000000000000


;*** ADC3RHB - Data Result High Register B; 0xFFFF8486 ***
ADC3RHB:            .equ   $FFFF8486                                ;*** ADC3RHB - Data Result High Register B; 0xFFFF8486 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3RHB_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC3RHB_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC3RHB_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC3RHB_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC3RHB_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC3RHB_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC3RHB_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC3RHB_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC3RHB_D8:        .equ   %00000001
mADC3RHB_D9:        .equ   %00000010
mADC3RHB_D10:       .equ   %00000100
mADC3RHB_D11:       .equ   %00001000
mADC3RHB_D12:       .equ   %00010000
mADC3RHB_D13:       .equ   %00100000
mADC3RHB_D14:       .equ   %01000000
mADC3RHB_D15:       .equ   %10000000


;*** ADC3RLB - Data Result Low Register B; 0xFFFF8487 ***
ADC3RLB:            .equ   $FFFF8487                                ;*** ADC3RLB - Data Result Low Register B; 0xFFFF8487 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3RLB_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC3RLB_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC3RLB_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC3RLB_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC3RLB_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC3RLB_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC3RLB_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC3RLB_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC3RLB_D0:        .equ   %00000001
mADC3RLB_D1:        .equ   %00000010
mADC3RLB_D2:        .equ   %00000100
mADC3RLB_D3:        .equ   %00001000
mADC3RLB_D4:        .equ   %00010000
mADC3RLB_D5:        .equ   %00100000
mADC3RLB_D6:        .equ   %01000000
mADC3RLB_D7:        .equ   %10000000


;*** ADC3CV1 - Compare Value 1 Register; 0xFFFF8488 ***
ADC3CV1:            .equ   $FFFF8488                                ;*** ADC3CV1 - Compare Value 1 Register; 0xFFFF8488 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CV1_CV10:       .equ   0                                         ; Compare Function Value 0
ADC3CV1_CV11:       .equ   1                                         ; Compare Function Value 1
ADC3CV1_CV12:       .equ   2                                         ; Compare Function Value 2
ADC3CV1_CV13:       .equ   3                                         ; Compare Function Value 3
ADC3CV1_CV14:       .equ   4                                         ; Compare Function Value 4
ADC3CV1_CV15:       .equ   5                                         ; Compare Function Value 5
ADC3CV1_CV16:       .equ   6                                         ; Compare Function Value 6
ADC3CV1_CV17:       .equ   7                                         ; Compare Function Value 7
ADC3CV1_CV18:       .equ   8                                         ; Compare Function Value 8
ADC3CV1_CV19:       .equ   9                                         ; Compare Function Value 9
ADC3CV1_CV110:      .equ   10                                        ; Compare Function Value 10
ADC3CV1_CV111:      .equ   11                                        ; Compare Function Value 11
ADC3CV1_CV112:      .equ   12                                        ; Compare Function Value 12
ADC3CV1_CV113:      .equ   13                                        ; Compare Function Value 13
ADC3CV1_CV114:      .equ   14                                        ; Compare Function Value 14
ADC3CV1_CV115:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC3CV1_CV10:      .equ   %00000001
mADC3CV1_CV11:      .equ   %00000010
mADC3CV1_CV12:      .equ   %00000100
mADC3CV1_CV13:      .equ   %00001000
mADC3CV1_CV14:      .equ   %00010000
mADC3CV1_CV15:      .equ   %00100000
mADC3CV1_CV16:      .equ   %01000000
mADC3CV1_CV17:      .equ   %10000000
mADC3CV1_CV18:      .equ   %100000000
mADC3CV1_CV19:      .equ   %1000000000
mADC3CV1_CV110:     .equ   %10000000000
mADC3CV1_CV111:     .equ   %100000000000
mADC3CV1_CV112:     .equ   %1000000000000
mADC3CV1_CV113:     .equ   %10000000000000
mADC3CV1_CV114:     .equ   %100000000000000
mADC3CV1_CV115:     .equ   %1000000000000000


;*** ADC3CV1H - Compare Value 1 High Register; 0xFFFF8488 ***
ADC3CV1H:           .equ   $FFFF8488                                ;*** ADC3CV1H - Compare Value 1 High Register; 0xFFFF8488 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CV1H_CV18:      .equ   0                                         ; Compare Function Value 8
ADC3CV1H_CV19:      .equ   1                                         ; Compare Function Value 9
ADC3CV1H_CV110:     .equ   2                                         ; Compare Function Value 10
ADC3CV1H_CV111:     .equ   3                                         ; Compare Function Value 11
ADC3CV1H_CV112:     .equ   4                                         ; Compare Function Value 12
ADC3CV1H_CV113:     .equ   5                                         ; Compare Function Value 13
ADC3CV1H_CV114:     .equ   6                                         ; Compare Function Value 14
ADC3CV1H_CV115:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC3CV1H_CV18:     .equ   %00000001
mADC3CV1H_CV19:     .equ   %00000010
mADC3CV1H_CV110:    .equ   %00000100
mADC3CV1H_CV111:    .equ   %00001000
mADC3CV1H_CV112:    .equ   %00010000
mADC3CV1H_CV113:    .equ   %00100000
mADC3CV1H_CV114:    .equ   %01000000
mADC3CV1H_CV115:    .equ   %10000000


;*** ADC3CV1L - Compare Value 1 Low Register; 0xFFFF8489 ***
ADC3CV1L:           .equ   $FFFF8489                                ;*** ADC3CV1L - Compare Value 1 Low Register; 0xFFFF8489 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CV1L_CV10:      .equ   0                                         ; Compare Function Value 0
ADC3CV1L_CV11:      .equ   1                                         ; Compare Function Value 1
ADC3CV1L_CV12:      .equ   2                                         ; Compare Function Value 2
ADC3CV1L_CV13:      .equ   3                                         ; Compare Function Value 3
ADC3CV1L_CV14:      .equ   4                                         ; Compare Function Value 4
ADC3CV1L_CV15:      .equ   5                                         ; Compare Function Value 5
ADC3CV1L_CV16:      .equ   6                                         ; Compare Function Value 6
ADC3CV1L_CV17:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC3CV1L_CV10:     .equ   %00000001
mADC3CV1L_CV11:     .equ   %00000010
mADC3CV1L_CV12:     .equ   %00000100
mADC3CV1L_CV13:     .equ   %00001000
mADC3CV1L_CV14:     .equ   %00010000
mADC3CV1L_CV15:     .equ   %00100000
mADC3CV1L_CV16:     .equ   %01000000
mADC3CV1L_CV17:     .equ   %10000000


;*** ADC3CV2 - Compare Value 2 Register; 0xFFFF848A ***
ADC3CV2:            .equ   $FFFF848A                                ;*** ADC3CV2 - Compare Value 2 Register; 0xFFFF848A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CV2_CV20:       .equ   0                                         ; Compare Function Value 0
ADC3CV2_CV21:       .equ   1                                         ; Compare Function Value 1
ADC3CV2_CV22:       .equ   2                                         ; Compare Function Value 2
ADC3CV2_CV23:       .equ   3                                         ; Compare Function Value 3
ADC3CV2_CV24:       .equ   4                                         ; Compare Function Value 4
ADC3CV2_CV25:       .equ   5                                         ; Compare Function Value 5
ADC3CV2_CV26:       .equ   6                                         ; Compare Function Value 6
ADC3CV2_CV27:       .equ   7                                         ; Compare Function Value 7
ADC3CV2_CV28:       .equ   8                                         ; Compare Function Value 8
ADC3CV2_CV29:       .equ   9                                         ; Compare Function Value 9
ADC3CV2_CV210:      .equ   10                                        ; Compare Function Value 10
ADC3CV2_CV211:      .equ   11                                        ; Compare Function Value 11
ADC3CV2_CV212:      .equ   12                                        ; Compare Function Value 12
ADC3CV2_CV213:      .equ   13                                        ; Compare Function Value 13
ADC3CV2_CV214:      .equ   14                                        ; Compare Function Value 14
ADC3CV2_CV215:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC3CV2_CV20:      .equ   %00000001
mADC3CV2_CV21:      .equ   %00000010
mADC3CV2_CV22:      .equ   %00000100
mADC3CV2_CV23:      .equ   %00001000
mADC3CV2_CV24:      .equ   %00010000
mADC3CV2_CV25:      .equ   %00100000
mADC3CV2_CV26:      .equ   %01000000
mADC3CV2_CV27:      .equ   %10000000
mADC3CV2_CV28:      .equ   %100000000
mADC3CV2_CV29:      .equ   %1000000000
mADC3CV2_CV210:     .equ   %10000000000
mADC3CV2_CV211:     .equ   %100000000000
mADC3CV2_CV212:     .equ   %1000000000000
mADC3CV2_CV213:     .equ   %10000000000000
mADC3CV2_CV214:     .equ   %100000000000000
mADC3CV2_CV215:     .equ   %1000000000000000


;*** ADC3CV2H - Compare Value 2 High Register; 0xFFFF848A ***
ADC3CV2H:           .equ   $FFFF848A                                ;*** ADC3CV2H - Compare Value 2 High Register; 0xFFFF848A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CV2H_CV28:      .equ   0                                         ; Compare Function Value 8
ADC3CV2H_CV29:      .equ   1                                         ; Compare Function Value 9
ADC3CV2H_CV210:     .equ   2                                         ; Compare Function Value 10
ADC3CV2H_CV211:     .equ   3                                         ; Compare Function Value 11
ADC3CV2H_CV212:     .equ   4                                         ; Compare Function Value 12
ADC3CV2H_CV213:     .equ   5                                         ; Compare Function Value 13
ADC3CV2H_CV214:     .equ   6                                         ; Compare Function Value 14
ADC3CV2H_CV215:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC3CV2H_CV28:     .equ   %00000001
mADC3CV2H_CV29:     .equ   %00000010
mADC3CV2H_CV210:    .equ   %00000100
mADC3CV2H_CV211:    .equ   %00001000
mADC3CV2H_CV212:    .equ   %00010000
mADC3CV2H_CV213:    .equ   %00100000
mADC3CV2H_CV214:    .equ   %01000000
mADC3CV2H_CV215:    .equ   %10000000


;*** ADC3CV2L - Compare Value 2 Low Register; 0xFFFF848B ***
ADC3CV2L:           .equ   $FFFF848B                                ;*** ADC3CV2L - Compare Value 2 Low Register; 0xFFFF848B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CV2L_CV20:      .equ   0                                         ; Compare Function Value 0
ADC3CV2L_CV21:      .equ   1                                         ; Compare Function Value 1
ADC3CV2L_CV22:      .equ   2                                         ; Compare Function Value 2
ADC3CV2L_CV23:      .equ   3                                         ; Compare Function Value 3
ADC3CV2L_CV24:      .equ   4                                         ; Compare Function Value 4
ADC3CV2L_CV25:      .equ   5                                         ; Compare Function Value 5
ADC3CV2L_CV26:      .equ   6                                         ; Compare Function Value 6
ADC3CV2L_CV27:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC3CV2L_CV20:     .equ   %00000001
mADC3CV2L_CV21:     .equ   %00000010
mADC3CV2L_CV22:     .equ   %00000100
mADC3CV2L_CV23:     .equ   %00001000
mADC3CV2L_CV24:     .equ   %00010000
mADC3CV2L_CV25:     .equ   %00100000
mADC3CV2L_CV26:     .equ   %01000000
mADC3CV2L_CV27:     .equ   %10000000


;*** ADC3SC2 - Status and Control Register 2; 0xFFFF848C ***
ADC3SC2:            .equ   $FFFF848C                                ;*** ADC3SC2 - Status and Control Register 2; 0xFFFF848C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3SC2_REFSEL0:    .equ   0                                         ; Voltage Reference Selection, bit 0
ADC3SC2_REFSEL1:    .equ   1                                         ; Voltage Reference Selection, bit 1
ADC3SC2_ACREN:      .equ   3                                         ; Unused
ADC3SC2_ACFGT:      .equ   4                                         ; Compare Function Greater Than Enable
ADC3SC2_ACFE:       .equ   5                                         ; Compare Function Enable - ACFE is used to enable the compare function
ADC3SC2_ADTRG:      .equ   6                                         ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion
ADC3SC2_ADACT:      .equ   7                                         ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted
; bit position masks
mADC3SC2_REFSEL0:   .equ   %00000001
mADC3SC2_REFSEL1:   .equ   %00000010
mADC3SC2_ACREN:     .equ   %00001000
mADC3SC2_ACFGT:     .equ   %00010000
mADC3SC2_ACFE:      .equ   %00100000
mADC3SC2_ADTRG:     .equ   %01000000
mADC3SC2_ADACT:     .equ   %10000000


;*** ADC3SC3 - Status and Control Register 3; 0xFFFF848D ***
ADC3SC3:            .equ   $FFFF848D                                ;*** ADC3SC3 - Status and Control Register 3; 0xFFFF848D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3SC3_AVGS0:      .equ   0                                         ; Hardware Average select, bit 0
ADC3SC3_AVGS1:      .equ   1                                         ; Hardware Average select, bit 1
ADC3SC3_AVGE:       .equ   2                                         ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADC3SC3_ADCO:       .equ   3                                         ; Continuous Conversion Enable - ADCO enables continuous conversions
ADC3SC3_CALF:       .equ   6                                         ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC3SC3_CAL:        .equ   7                                         ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADC3SC3_AVGS0:     .equ   %00000001
mADC3SC3_AVGS1:     .equ   %00000010
mADC3SC3_AVGE:      .equ   %00000100
mADC3SC3_ADCO:      .equ   %00001000
mADC3SC3_CALF:      .equ   %01000000
mADC3SC3_CAL:       .equ   %10000000


;*** ADC3OFS - Offset Correction Register; 0xFFFF848E ***
ADC3OFS:            .equ   $FFFF848E                                ;*** ADC3OFS - Offset Correction Register; 0xFFFF848E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3OFS_OFS0:       .equ   0                                         ; Offset error correction value bit 0
ADC3OFS_OFS1:       .equ   1                                         ; Offset error correction value bit 1
ADC3OFS_OFS2:       .equ   2                                         ; Offset error correction value bit 2
ADC3OFS_OFS3:       .equ   3                                         ; Offset error correction value bit 3
ADC3OFS_OFS4:       .equ   4                                         ; Offset error correction value bit 4
ADC3OFS_OFS5:       .equ   5                                         ; Offset error correction value bit 5
ADC3OFS_OFS6:       .equ   6                                         ; Offset error correction value bit 6
ADC3OFS_OFS7:       .equ   7                                         ; Offset error correction value bit 7
ADC3OFS_OFS8:       .equ   8                                         ; Offset error correction value bit 8
ADC3OFS_OFS9:       .equ   9                                         ; Offset error correction value bit 9
ADC3OFS_OFS10:      .equ   10                                        ; Offset error correction value bit 10
ADC3OFS_OFS11:      .equ   11                                        ; Offset error correction value bit 11
ADC3OFS_OFS12:      .equ   12                                        ; Offset error correction value bit 12
ADC3OFS_OFS13:      .equ   13                                        ; Offset error correction value bit 13
ADC3OFS_OFS14:      .equ   14                                        ; Offset error correction value bit 14
ADC3OFS_OFS15:      .equ   15                                        ; Offset error correction value bit 15
; bit position masks
mADC3OFS_OFS0:      .equ   %00000001
mADC3OFS_OFS1:      .equ   %00000010
mADC3OFS_OFS2:      .equ   %00000100
mADC3OFS_OFS3:      .equ   %00001000
mADC3OFS_OFS4:      .equ   %00010000
mADC3OFS_OFS5:      .equ   %00100000
mADC3OFS_OFS6:      .equ   %01000000
mADC3OFS_OFS7:      .equ   %10000000
mADC3OFS_OFS8:      .equ   %100000000
mADC3OFS_OFS9:      .equ   %1000000000
mADC3OFS_OFS10:     .equ   %10000000000
mADC3OFS_OFS11:     .equ   %100000000000
mADC3OFS_OFS12:     .equ   %1000000000000
mADC3OFS_OFS13:     .equ   %10000000000000
mADC3OFS_OFS14:     .equ   %100000000000000
mADC3OFS_OFS15:     .equ   %1000000000000000


;*** ADC3OFSH - Offset Correction High Register; 0xFFFF848E ***
ADC3OFSH:           .equ   $FFFF848E                                ;*** ADC3OFSH - Offset Correction High Register; 0xFFFF848E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3OFSH_OFS8:      .equ   0                                         ; Offset error correction value bit 8
ADC3OFSH_OFS9:      .equ   1                                         ; Offset error correction value bit 9
ADC3OFSH_OFS10:     .equ   2                                         ; Offset error correction value bit 10
ADC3OFSH_OFS11:     .equ   3                                         ; Offset error correction value bit 11
ADC3OFSH_OFS12:     .equ   4                                         ; Offset error correction value bit 12
ADC3OFSH_OFS13:     .equ   5                                         ; Offset error correction value bit 13
ADC3OFSH_OFS14:     .equ   6                                         ; Offset error correction value bit 14
ADC3OFSH_OFS15:     .equ   7                                         ; Offset error correction value bit 15
; bit position masks
mADC3OFSH_OFS8:     .equ   %00000001
mADC3OFSH_OFS9:     .equ   %00000010
mADC3OFSH_OFS10:    .equ   %00000100
mADC3OFSH_OFS11:    .equ   %00001000
mADC3OFSH_OFS12:    .equ   %00010000
mADC3OFSH_OFS13:    .equ   %00100000
mADC3OFSH_OFS14:    .equ   %01000000
mADC3OFSH_OFS15:    .equ   %10000000


;*** ADC3OFSL - Offset Correction Low Register; 0xFFFF848F ***
ADC3OFSL:           .equ   $FFFF848F                                ;*** ADC3OFSL - Offset Correction Low Register; 0xFFFF848F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3OFSL_OFS0:      .equ   0                                         ; Offset error correction value bit 0
ADC3OFSL_OFS1:      .equ   1                                         ; Offset error correction value bit 1
ADC3OFSL_OFS2:      .equ   2                                         ; Offset error correction value bit 2
ADC3OFSL_OFS3:      .equ   3                                         ; Offset error correction value bit 3
ADC3OFSL_OFS4:      .equ   4                                         ; Offset error correction value bit 4
ADC3OFSL_OFS5:      .equ   5                                         ; Offset error correction value bit 5
ADC3OFSL_OFS6:      .equ   6                                         ; Offset error correction value bit 6
ADC3OFSL_OFS7:      .equ   7                                         ; Offset error correction value bit 7
; bit position masks
mADC3OFSL_OFS0:     .equ   %00000001
mADC3OFSL_OFS1:     .equ   %00000010
mADC3OFSL_OFS2:     .equ   %00000100
mADC3OFSL_OFS3:     .equ   %00001000
mADC3OFSL_OFS4:     .equ   %00010000
mADC3OFSL_OFS5:     .equ   %00100000
mADC3OFSL_OFS6:     .equ   %01000000
mADC3OFSL_OFS7:     .equ   %10000000


;*** ADC3PG - Plus-Side Gain Register; 0xFFFF8490 ***
ADC3PG:             .equ   $FFFF8490                                ;*** ADC3PG - Plus-Side Gain Register; 0xFFFF8490 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3PG_PG0:         .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC3PG_PG1:         .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC3PG_PG2:         .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC3PG_PG3:         .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC3PG_PG4:         .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC3PG_PG5:         .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC3PG_PG6:         .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC3PG_PG7:         .equ   7                                         ; Gain error correction for the plus-side input value bit 7
ADC3PG_PG8:         .equ   8                                         ; Gain error correction for the plus-side input value bit 8
ADC3PG_PG9:         .equ   9                                         ; Gain error correction for the plus-side input value bit 9
ADC3PG_PG10:        .equ   10                                        ; Gain error correction for the plus-side input value bit 10
ADC3PG_PG11:        .equ   11                                        ; Gain error correction for the plus-side input value bit 11
ADC3PG_PG12:        .equ   12                                        ; Gain error correction for the plus-side input value bit 12
ADC3PG_PG13:        .equ   13                                        ; Gain error correction for the plus-side input value bit 13
ADC3PG_PG14:        .equ   14                                        ; Gain error correction for the plus-side input value bit 14
ADC3PG_PG15:        .equ   15                                        ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC3PG_PG0:        .equ   %00000001
mADC3PG_PG1:        .equ   %00000010
mADC3PG_PG2:        .equ   %00000100
mADC3PG_PG3:        .equ   %00001000
mADC3PG_PG4:        .equ   %00010000
mADC3PG_PG5:        .equ   %00100000
mADC3PG_PG6:        .equ   %01000000
mADC3PG_PG7:        .equ   %10000000
mADC3PG_PG8:        .equ   %100000000
mADC3PG_PG9:        .equ   %1000000000
mADC3PG_PG10:       .equ   %10000000000
mADC3PG_PG11:       .equ   %100000000000
mADC3PG_PG12:       .equ   %1000000000000
mADC3PG_PG13:       .equ   %10000000000000
mADC3PG_PG14:       .equ   %100000000000000
mADC3PG_PG15:       .equ   %1000000000000000


;*** ADC3PGH - Plus-Side Gain High Register; 0xFFFF8490 ***
ADC3PGH:            .equ   $FFFF8490                                ;*** ADC3PGH - Plus-Side Gain High Register; 0xFFFF8490 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3PGH_PG8:        .equ   0                                         ; Gain error correction for the plus-side input value bit 8
ADC3PGH_PG9:        .equ   1                                         ; Gain error correction for the plus-side input value bit 9
ADC3PGH_PG10:       .equ   2                                         ; Gain error correction for the plus-side input value bit 10
ADC3PGH_PG11:       .equ   3                                         ; Gain error correction for the plus-side input value bit 11
ADC3PGH_PG12:       .equ   4                                         ; Gain error correction for the plus-side input value bit 12
ADC3PGH_PG13:       .equ   5                                         ; Gain error correction for the plus-side input value bit 13
ADC3PGH_PG14:       .equ   6                                         ; Gain error correction for the plus-side input value bit 14
ADC3PGH_PG15:       .equ   7                                         ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC3PGH_PG8:       .equ   %00000001
mADC3PGH_PG9:       .equ   %00000010
mADC3PGH_PG10:      .equ   %00000100
mADC3PGH_PG11:      .equ   %00001000
mADC3PGH_PG12:      .equ   %00010000
mADC3PGH_PG13:      .equ   %00100000
mADC3PGH_PG14:      .equ   %01000000
mADC3PGH_PG15:      .equ   %10000000


;*** ADC3PGL - Plus-Side Gain Low Register; 0xFFFF8491 ***
ADC3PGL:            .equ   $FFFF8491                                ;*** ADC3PGL - Plus-Side Gain Low Register; 0xFFFF8491 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3PGL_PG0:        .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC3PGL_PG1:        .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC3PGL_PG2:        .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC3PGL_PG3:        .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC3PGL_PG4:        .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC3PGL_PG5:        .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC3PGL_PG6:        .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC3PGL_PG7:        .equ   7                                         ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADC3PGL_PG0:       .equ   %00000001
mADC3PGL_PG1:       .equ   %00000010
mADC3PGL_PG2:       .equ   %00000100
mADC3PGL_PG3:       .equ   %00001000
mADC3PGL_PG4:       .equ   %00010000
mADC3PGL_PG5:       .equ   %00100000
mADC3PGL_PG6:       .equ   %01000000
mADC3PGL_PG7:       .equ   %10000000


;*** ADC3MG - Minus-Side Gain Register; 0xFFFF8492 ***
ADC3MG:             .equ   $FFFF8492                                ;*** ADC3MG - Minus-Side Gain Register; 0xFFFF8492 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3MG_MG0:         .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC3MG_MG1:         .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC3MG_MG2:         .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC3MG_MG3:         .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC3MG_MG4:         .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC3MG_MG5:         .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC3MG_MG6:         .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC3MG_MG7:         .equ   7                                         ; Gain error correction for the minus-side input value bit 7
ADC3MG_MG8:         .equ   8                                         ; Gain error correction for the minus-side input value bit 8
ADC3MG_MG9:         .equ   9                                         ; Gain error correction for the minus-side input value bit 9
ADC3MG_MG10:        .equ   10                                        ; Gain error correction for the minus-side input value bit 10
ADC3MG_MG11:        .equ   11                                        ; Gain error correction for the minus-side input value bit 11
ADC3MG_MG12:        .equ   12                                        ; Gain error correction for the minus-side input value bit 12
ADC3MG_MG13:        .equ   13                                        ; Gain error correction for the minus-side input value bit 13
ADC3MG_MG14:        .equ   14                                        ; Gain error correction for the minus-side input value bit 14
ADC3MG_MG15:        .equ   15                                        ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC3MG_MG0:        .equ   %00000001
mADC3MG_MG1:        .equ   %00000010
mADC3MG_MG2:        .equ   %00000100
mADC3MG_MG3:        .equ   %00001000
mADC3MG_MG4:        .equ   %00010000
mADC3MG_MG5:        .equ   %00100000
mADC3MG_MG6:        .equ   %01000000
mADC3MG_MG7:        .equ   %10000000
mADC3MG_MG8:        .equ   %100000000
mADC3MG_MG9:        .equ   %1000000000
mADC3MG_MG10:       .equ   %10000000000
mADC3MG_MG11:       .equ   %100000000000
mADC3MG_MG12:       .equ   %1000000000000
mADC3MG_MG13:       .equ   %10000000000000
mADC3MG_MG14:       .equ   %100000000000000
mADC3MG_MG15:       .equ   %1000000000000000


;*** ADC3MGH - Minus-Side Gain High Register; 0xFFFF8492 ***
ADC3MGH:            .equ   $FFFF8492                                ;*** ADC3MGH - Minus-Side Gain High Register; 0xFFFF8492 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3MGH_MG8:        .equ   0                                         ; Gain error correction for the minus-side input value bit 8
ADC3MGH_MG9:        .equ   1                                         ; Gain error correction for the minus-side input value bit 9
ADC3MGH_MG10:       .equ   2                                         ; Gain error correction for the minus-side input value bit 10
ADC3MGH_MG11:       .equ   3                                         ; Gain error correction for the minus-side input value bit 11
ADC3MGH_MG12:       .equ   4                                         ; Gain error correction for the minus-side input value bit 12
ADC3MGH_MG13:       .equ   5                                         ; Gain error correction for the minus-side input value bit 13
ADC3MGH_MG14:       .equ   6                                         ; Gain error correction for the minus-side input value bit 14
ADC3MGH_MG15:       .equ   7                                         ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC3MGH_MG8:       .equ   %00000001
mADC3MGH_MG9:       .equ   %00000010
mADC3MGH_MG10:      .equ   %00000100
mADC3MGH_MG11:      .equ   %00001000
mADC3MGH_MG12:      .equ   %00010000
mADC3MGH_MG13:      .equ   %00100000
mADC3MGH_MG14:      .equ   %01000000
mADC3MGH_MG15:      .equ   %10000000


;*** ADC3MGL - Minus-Side Gain Low Register; 0xFFFF8493 ***
ADC3MGL:            .equ   $FFFF8493                                ;*** ADC3MGL - Minus-Side Gain Low Register; 0xFFFF8493 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3MGL_MG0:        .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC3MGL_MG1:        .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC3MGL_MG2:        .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC3MGL_MG3:        .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC3MGL_MG4:        .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC3MGL_MG5:        .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC3MGL_MG6:        .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC3MGL_MG7:        .equ   7                                         ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADC3MGL_MG0:       .equ   %00000001
mADC3MGL_MG1:       .equ   %00000010
mADC3MGL_MG2:       .equ   %00000100
mADC3MGL_MG3:       .equ   %00001000
mADC3MGL_MG4:       .equ   %00010000
mADC3MGL_MG5:       .equ   %00100000
mADC3MGL_MG6:       .equ   %01000000
mADC3MGL_MG7:       .equ   %10000000


;*** ADC3CLPD - Plus-Side General Calibration Value D Register; 0xFFFF8494 ***
ADC3CLPD:           .equ   $FFFF8494                                ;*** ADC3CLPD - Plus-Side General Calibration Value D Register; 0xFFFF8494 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLPD_CLPD0:     .equ   0                                         ; Plus-Side General Calibration Value D bit 0
ADC3CLPD_CLPD1:     .equ   1                                         ; Plus-Side General Calibration Value D bit 1
ADC3CLPD_CLPD2:     .equ   2                                         ; Plus-Side General Calibration Value D bit 2
ADC3CLPD_CLPD3:     .equ   3                                         ; Plus-Side General Calibration Value D bit 3
ADC3CLPD_CLPD4:     .equ   4                                         ; Plus-Side General Calibration Value D bit 4
ADC3CLPD_CLPD5:     .equ   5                                         ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADC3CLPD_CLPD0:    .equ   %00000001
mADC3CLPD_CLPD1:    .equ   %00000010
mADC3CLPD_CLPD2:    .equ   %00000100
mADC3CLPD_CLPD3:    .equ   %00001000
mADC3CLPD_CLPD4:    .equ   %00010000
mADC3CLPD_CLPD5:    .equ   %00100000


;*** ADC3CLPS - Plus-Side General Calibration Value S Register; 0xFFFF8495 ***
ADC3CLPS:           .equ   $FFFF8495                                ;*** ADC3CLPS - Plus-Side General Calibration Value S Register; 0xFFFF8495 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLPS_CLPS0:     .equ   0                                         ; Plus-Side General Calibration Value S bit 0
ADC3CLPS_CLPS1:     .equ   1                                         ; Plus-Side General Calibration Value S bit 1
ADC3CLPS_CLPS2:     .equ   2                                         ; Plus-Side General Calibration Value S bit 2
ADC3CLPS_CLPS3:     .equ   3                                         ; Plus-Side General Calibration Value S bit 3
ADC3CLPS_CLPS4:     .equ   4                                         ; Plus-Side General Calibration Value S bit 4
ADC3CLPS_CLPS5:     .equ   5                                         ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADC3CLPS_CLPS0:    .equ   %00000001
mADC3CLPS_CLPS1:    .equ   %00000010
mADC3CLPS_CLPS2:    .equ   %00000100
mADC3CLPS_CLPS3:    .equ   %00001000
mADC3CLPS_CLPS4:    .equ   %00010000
mADC3CLPS_CLPS5:    .equ   %00100000


;*** ADC3CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF8496 ***
ADC3CLP4:           .equ   $FFFF8496                                ;*** ADC3CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF8496 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP4_CLP40:     .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC3CLP4_CLP41:     .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC3CLP4_CLP42:     .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC3CLP4_CLP43:     .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC3CLP4_CLP44:     .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC3CLP4_CLP45:     .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC3CLP4_CLP46:     .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC3CLP4_CLP47:     .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
ADC3CLP4_CLP48:     .equ   8                                         ; Plus-Side General Calibration Value 4 bit 8
ADC3CLP4_CLP49:     .equ   9                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC3CLP4_CLP40:    .equ   %00000001
mADC3CLP4_CLP41:    .equ   %00000010
mADC3CLP4_CLP42:    .equ   %00000100
mADC3CLP4_CLP43:    .equ   %00001000
mADC3CLP4_CLP44:    .equ   %00010000
mADC3CLP4_CLP45:    .equ   %00100000
mADC3CLP4_CLP46:    .equ   %01000000
mADC3CLP4_CLP47:    .equ   %10000000
mADC3CLP4_CLP48:    .equ   %100000000
mADC3CLP4_CLP49:    .equ   %1000000000


;*** ADC3CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF8496 ***
ADC3CLP4H:          .equ   $FFFF8496                                ;*** ADC3CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF8496 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP4H_CLP48:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 8
ADC3CLP4H_CLP49:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC3CLP4H_CLP48:   .equ   %00000001
mADC3CLP4H_CLP49:   .equ   %00000010


;*** ADC3CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF8497 ***
ADC3CLP4L:          .equ   $FFFF8497                                ;*** ADC3CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF8497 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP4L_CLP40:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC3CLP4L_CLP41:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC3CLP4L_CLP42:    .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC3CLP4L_CLP43:    .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC3CLP4L_CLP44:    .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC3CLP4L_CLP45:    .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC3CLP4L_CLP46:    .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC3CLP4L_CLP47:    .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADC3CLP4L_CLP40:   .equ   %00000001
mADC3CLP4L_CLP41:   .equ   %00000010
mADC3CLP4L_CLP42:   .equ   %00000100
mADC3CLP4L_CLP43:   .equ   %00001000
mADC3CLP4L_CLP44:   .equ   %00010000
mADC3CLP4L_CLP45:   .equ   %00100000
mADC3CLP4L_CLP46:   .equ   %01000000
mADC3CLP4L_CLP47:   .equ   %10000000


;*** ADC3CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF8498 ***
ADC3CLP3:           .equ   $FFFF8498                                ;*** ADC3CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF8498 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP3_CLP30:     .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC3CLP3_CLP31:     .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC3CLP3_CLP32:     .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC3CLP3_CLP33:     .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC3CLP3_CLP34:     .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC3CLP3_CLP35:     .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC3CLP3_CLP36:     .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC3CLP3_CLP37:     .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
ADC3CLP3_CLP38:     .equ   8                                         ; Plus-Side General Calibration Value 3 bit 8
; bit position masks
mADC3CLP3_CLP30:    .equ   %00000001
mADC3CLP3_CLP31:    .equ   %00000010
mADC3CLP3_CLP32:    .equ   %00000100
mADC3CLP3_CLP33:    .equ   %00001000
mADC3CLP3_CLP34:    .equ   %00010000
mADC3CLP3_CLP35:    .equ   %00100000
mADC3CLP3_CLP36:    .equ   %01000000
mADC3CLP3_CLP37:    .equ   %10000000
mADC3CLP3_CLP38:    .equ   %100000000


;*** ADC3CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF8498 ***
ADC3CLP3H:          .equ   $FFFF8498                                ;*** ADC3CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF8498 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP3H_CLP38:    .equ   0                                         ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADC3CLP3H_CLP38:   .equ   %00000001


;*** ADC3CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF8499 ***
ADC3CLP3L:          .equ   $FFFF8499                                ;*** ADC3CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF8499 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP3L_CLP30:    .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC3CLP3L_CLP31:    .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC3CLP3L_CLP32:    .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC3CLP3L_CLP33:    .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC3CLP3L_CLP34:    .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC3CLP3L_CLP35:    .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC3CLP3L_CLP36:    .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC3CLP3L_CLP37:    .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADC3CLP3L_CLP30:   .equ   %00000001
mADC3CLP3L_CLP31:   .equ   %00000010
mADC3CLP3L_CLP32:   .equ   %00000100
mADC3CLP3L_CLP33:   .equ   %00001000
mADC3CLP3L_CLP34:   .equ   %00010000
mADC3CLP3L_CLP35:   .equ   %00100000
mADC3CLP3L_CLP36:   .equ   %01000000
mADC3CLP3L_CLP37:   .equ   %10000000


;*** ADC3CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF849A ***
ADC3CLP2:           .equ   $FFFF849A                                ;*** ADC3CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF849A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP2_CLP20:     .equ   0                                         ; Plus-Side General Calibration Value 2 bit 0
ADC3CLP2_CLP21:     .equ   1                                         ; Plus-Side General Calibration Value 2 bit 1
ADC3CLP2_CLP22:     .equ   2                                         ; Plus-Side General Calibration Value 2 bit 2
ADC3CLP2_CLP23:     .equ   3                                         ; Plus-Side General Calibration Value 2 bit 3
ADC3CLP2_CLP24:     .equ   4                                         ; Plus-Side General Calibration Value 2 bit 4
ADC3CLP2_CLP25:     .equ   5                                         ; Plus-Side General Calibration Value 2 bit 5
ADC3CLP2_CLP26:     .equ   6                                         ; Plus-Side General Calibration Value 2 bit 6
ADC3CLP2_CLP27:     .equ   7                                         ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADC3CLP2_CLP20:    .equ   %00000001
mADC3CLP2_CLP21:    .equ   %00000010
mADC3CLP2_CLP22:    .equ   %00000100
mADC3CLP2_CLP23:    .equ   %00001000
mADC3CLP2_CLP24:    .equ   %00010000
mADC3CLP2_CLP25:    .equ   %00100000
mADC3CLP2_CLP26:    .equ   %01000000
mADC3CLP2_CLP27:    .equ   %10000000


;*** ADC3CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF849B ***
ADC3CLP1:           .equ   $FFFF849B                                ;*** ADC3CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF849B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP1_CLP10:     .equ   0                                         ; Plus-Side General Calibration Value 1 bit 0
ADC3CLP1_CLP11:     .equ   1                                         ; Plus-Side General Calibration Value 1 bit 1
ADC3CLP1_CLP12:     .equ   2                                         ; Plus-Side General Calibration Value 1 bit 2
ADC3CLP1_CLP13:     .equ   3                                         ; Plus-Side General Calibration Value 1 bit 3
ADC3CLP1_CLP14:     .equ   4                                         ; Plus-Side General Calibration Value 1 bit 4
ADC3CLP1_CLP15:     .equ   5                                         ; Plus-Side General Calibration Value 1 bit 5
ADC3CLP1_CLP16:     .equ   6                                         ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADC3CLP1_CLP10:    .equ   %00000001
mADC3CLP1_CLP11:    .equ   %00000010
mADC3CLP1_CLP12:    .equ   %00000100
mADC3CLP1_CLP13:    .equ   %00001000
mADC3CLP1_CLP14:    .equ   %00010000
mADC3CLP1_CLP15:    .equ   %00100000
mADC3CLP1_CLP16:    .equ   %01000000


;*** ADC3CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF849C ***
ADC3CLP0:           .equ   $FFFF849C                                ;*** ADC3CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF849C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLP0_CLP00:     .equ   0                                         ; Plus-Side General Calibration Value 0 bit 0
ADC3CLP0_CLP01:     .equ   1                                         ; Plus-Side General Calibration Value 0 bit 1
ADC3CLP0_CLP02:     .equ   2                                         ; Plus-Side General Calibration Value 0 bit 2
ADC3CLP0_CLP03:     .equ   3                                         ; Plus-Side General Calibration Value 0 bit 3
ADC3CLP0_CLP04:     .equ   4                                         ; Plus-Side General Calibration Value 0 bit 4
ADC3CLP0_CLP05:     .equ   5                                         ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADC3CLP0_CLP00:    .equ   %00000001
mADC3CLP0_CLP01:    .equ   %00000010
mADC3CLP0_CLP02:    .equ   %00000100
mADC3CLP0_CLP03:    .equ   %00001000
mADC3CLP0_CLP04:    .equ   %00010000
mADC3CLP0_CLP05:    .equ   %00100000


;*** ADC3CLMD - Minus-Side General Calibration Value D Register; 0xFFFF849E ***
ADC3CLMD:           .equ   $FFFF849E                                ;*** ADC3CLMD - Minus-Side General Calibration Value D Register; 0xFFFF849E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLMD_CLMD0:     .equ   0                                         ; Minus-Side General Calibration Value D bit 0
ADC3CLMD_CLMD1:     .equ   1                                         ; Minus-Side General Calibration Value D bit 1
ADC3CLMD_CLMD2:     .equ   2                                         ; Minus-Side General Calibration Value D bit 2
ADC3CLMD_CLMD3:     .equ   3                                         ; Minus-Side General Calibration Value D bit 3
ADC3CLMD_CLMD4:     .equ   4                                         ; Minus-Side General Calibration Value D bit 4
ADC3CLMD_CLMD5:     .equ   5                                         ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADC3CLMD_CLMD0:    .equ   %00000001
mADC3CLMD_CLMD1:    .equ   %00000010
mADC3CLMD_CLMD2:    .equ   %00000100
mADC3CLMD_CLMD3:    .equ   %00001000
mADC3CLMD_CLMD4:    .equ   %00010000
mADC3CLMD_CLMD5:    .equ   %00100000


;*** ADC3CLMS - Minus-Side General Calibration Value S Register; 0xFFFF849F ***
ADC3CLMS:           .equ   $FFFF849F                                ;*** ADC3CLMS - Minus-Side General Calibration Value S Register; 0xFFFF849F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLMS_CLMS0:     .equ   0                                         ; Minus-Side General Calibration Value S bit 0
ADC3CLMS_CLMS1:     .equ   1                                         ; Minus-Side General Calibration Value S bit 1
ADC3CLMS_CLMS2:     .equ   2                                         ; Minus-Side General Calibration Value S bit 2
ADC3CLMS_CLMS3:     .equ   3                                         ; Minus-Side General Calibration Value S bit 3
ADC3CLMS_CLMS4:     .equ   4                                         ; Minus-Side General Calibration Value S bit 4
ADC3CLMS_CLMS5:     .equ   5                                         ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADC3CLMS_CLMS0:    .equ   %00000001
mADC3CLMS_CLMS1:    .equ   %00000010
mADC3CLMS_CLMS2:    .equ   %00000100
mADC3CLMS_CLMS3:    .equ   %00001000
mADC3CLMS_CLMS4:    .equ   %00010000
mADC3CLMS_CLMS5:    .equ   %00100000


;*** ADC3CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF84A0 ***
ADC3CLM4:           .equ   $FFFF84A0                                ;*** ADC3CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF84A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM4_CLM40:     .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC3CLM4_CLM41:     .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC3CLM4_CLM42:     .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC3CLM4_CLM43:     .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC3CLM4_CLM44:     .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC3CLM4_CLM45:     .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC3CLM4_CLM46:     .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC3CLM4_CLM47:     .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
ADC3CLM4_CLM48:     .equ   8                                         ; Minus-Side General Calibration Value 4 bit 8
ADC3CLM4_CLM49:     .equ   9                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC3CLM4_CLM40:    .equ   %00000001
mADC3CLM4_CLM41:    .equ   %00000010
mADC3CLM4_CLM42:    .equ   %00000100
mADC3CLM4_CLM43:    .equ   %00001000
mADC3CLM4_CLM44:    .equ   %00010000
mADC3CLM4_CLM45:    .equ   %00100000
mADC3CLM4_CLM46:    .equ   %01000000
mADC3CLM4_CLM47:    .equ   %10000000
mADC3CLM4_CLM48:    .equ   %100000000
mADC3CLM4_CLM49:    .equ   %1000000000


;*** ADC3CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF84A0 ***
ADC3CLM4H:          .equ   $FFFF84A0                                ;*** ADC3CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF84A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM4H_CLM48:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 8
ADC3CLM4H_CLM49:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC3CLM4H_CLM48:   .equ   %00000001
mADC3CLM4H_CLM49:   .equ   %00000010


;*** ADC3CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF84A1 ***
ADC3CLM4L:          .equ   $FFFF84A1                                ;*** ADC3CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF84A1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM4L_CLM40:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC3CLM4L_CLM41:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC3CLM4L_CLM42:    .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC3CLM4L_CLM43:    .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC3CLM4L_CLM44:    .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC3CLM4L_CLM45:    .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC3CLM4L_CLM46:    .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC3CLM4L_CLM47:    .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADC3CLM4L_CLM40:   .equ   %00000001
mADC3CLM4L_CLM41:   .equ   %00000010
mADC3CLM4L_CLM42:   .equ   %00000100
mADC3CLM4L_CLM43:   .equ   %00001000
mADC3CLM4L_CLM44:   .equ   %00010000
mADC3CLM4L_CLM45:   .equ   %00100000
mADC3CLM4L_CLM46:   .equ   %01000000
mADC3CLM4L_CLM47:   .equ   %10000000


;*** ADC3CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF84A2 ***
ADC3CLM3:           .equ   $FFFF84A2                                ;*** ADC3CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF84A2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM3_CLM30:     .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC3CLM3_CLM31:     .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC3CLM3_CLM32:     .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC3CLM3_CLM33:     .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC3CLM3_CLM34:     .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC3CLM3_CLM35:     .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC3CLM3_CLM36:     .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC3CLM3_CLM37:     .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
ADC3CLM3_CLM38:     .equ   8                                         ; Minus-Side General Calibration Value 3 bit 8
; bit position masks
mADC3CLM3_CLM30:    .equ   %00000001
mADC3CLM3_CLM31:    .equ   %00000010
mADC3CLM3_CLM32:    .equ   %00000100
mADC3CLM3_CLM33:    .equ   %00001000
mADC3CLM3_CLM34:    .equ   %00010000
mADC3CLM3_CLM35:    .equ   %00100000
mADC3CLM3_CLM36:    .equ   %01000000
mADC3CLM3_CLM37:    .equ   %10000000
mADC3CLM3_CLM38:    .equ   %100000000


;*** ADC3CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF84A2 ***
ADC3CLM3H:          .equ   $FFFF84A2                                ;*** ADC3CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF84A2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM3H_CLM38:    .equ   0                                         ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADC3CLM3H_CLM38:   .equ   %00000001


;*** ADC3CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF84A3 ***
ADC3CLM3L:          .equ   $FFFF84A3                                ;*** ADC3CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF84A3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM3L_CLM30:    .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC3CLM3L_CLM31:    .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC3CLM3L_CLM32:    .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC3CLM3L_CLM33:    .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC3CLM3L_CLM34:    .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC3CLM3L_CLM35:    .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC3CLM3L_CLM36:    .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC3CLM3L_CLM37:    .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADC3CLM3L_CLM30:   .equ   %00000001
mADC3CLM3L_CLM31:   .equ   %00000010
mADC3CLM3L_CLM32:   .equ   %00000100
mADC3CLM3L_CLM33:   .equ   %00001000
mADC3CLM3L_CLM34:   .equ   %00010000
mADC3CLM3L_CLM35:   .equ   %00100000
mADC3CLM3L_CLM36:   .equ   %01000000
mADC3CLM3L_CLM37:   .equ   %10000000


;*** ADC3CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF84A4 ***
ADC3CLM2:           .equ   $FFFF84A4                                ;*** ADC3CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF84A4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM2_CLM20:     .equ   0                                         ; Minus-Side General Calibration Value 2 bit 0
ADC3CLM2_CLM21:     .equ   1                                         ; Minus-Side General Calibration Value 2 bit 1
ADC3CLM2_CLM22:     .equ   2                                         ; Minus-Side General Calibration Value 2 bit 2
ADC3CLM2_CLM23:     .equ   3                                         ; Minus-Side General Calibration Value 2 bit 3
ADC3CLM2_CLM24:     .equ   4                                         ; Minus-Side General Calibration Value 2 bit 4
ADC3CLM2_CLM25:     .equ   5                                         ; Minus-Side General Calibration Value 2 bit 5
ADC3CLM2_CLM26:     .equ   6                                         ; Minus-Side General Calibration Value 2 bit 6
ADC3CLM2_CLM27:     .equ   7                                         ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADC3CLM2_CLM20:    .equ   %00000001
mADC3CLM2_CLM21:    .equ   %00000010
mADC3CLM2_CLM22:    .equ   %00000100
mADC3CLM2_CLM23:    .equ   %00001000
mADC3CLM2_CLM24:    .equ   %00010000
mADC3CLM2_CLM25:    .equ   %00100000
mADC3CLM2_CLM26:    .equ   %01000000
mADC3CLM2_CLM27:    .equ   %10000000


;*** ADC3CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF84A5 ***
ADC3CLM1:           .equ   $FFFF84A5                                ;*** ADC3CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF84A5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM1_CLM10:     .equ   0                                         ; Minus-Side General Calibration Value 1 bit 0
ADC3CLM1_CLM11:     .equ   1                                         ; Minus-Side General Calibration Value 1 bit 1
ADC3CLM1_CLM12:     .equ   2                                         ; Minus-Side General Calibration Value 1 bit 2
ADC3CLM1_CLM13:     .equ   3                                         ; Minus-Side General Calibration Value 1 bit 3
ADC3CLM1_CLM14:     .equ   4                                         ; Minus-Side General Calibration Value 1 bit 4
ADC3CLM1_CLM15:     .equ   5                                         ; Minus-Side General Calibration Value 1 bit 5
ADC3CLM1_CLM16:     .equ   6                                         ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADC3CLM1_CLM10:    .equ   %00000001
mADC3CLM1_CLM11:    .equ   %00000010
mADC3CLM1_CLM12:    .equ   %00000100
mADC3CLM1_CLM13:    .equ   %00001000
mADC3CLM1_CLM14:    .equ   %00010000
mADC3CLM1_CLM15:    .equ   %00100000
mADC3CLM1_CLM16:    .equ   %01000000


;*** ADC3CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF84A6 ***
ADC3CLM0:           .equ   $FFFF84A6                                ;*** ADC3CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF84A6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC3CLM0_CLM00:     .equ   0                                         ; Minus-Side General Calibration Value 0 bit 0
ADC3CLM0_CLM01:     .equ   1                                         ; Minus-Side General Calibration Value 0 bit 1
ADC3CLM0_CLM02:     .equ   2                                         ; Minus-Side General Calibration Value 0 bit 2
ADC3CLM0_CLM03:     .equ   3                                         ; Minus-Side General Calibration Value 0 bit 3
ADC3CLM0_CLM04:     .equ   4                                         ; Minus-Side General Calibration Value 0 bit 4
ADC3CLM0_CLM05:     .equ   5                                         ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADC3CLM0_CLM00:    .equ   %00000001
mADC3CLM0_CLM01:    .equ   %00000010
mADC3CLM0_CLM02:    .equ   %00000100
mADC3CLM0_CLM03:    .equ   %00001000
mADC3CLM0_CLM04:    .equ   %00010000
mADC3CLM0_CLM05:    .equ   %00100000


;*** ADC4SC1A - Status and Control Register 1A; 0xFFFF84C0 ***
ADC4SC1A:           .equ   $FFFF84C0                                ;*** ADC4SC1A - Status and Control Register 1A; 0xFFFF84C0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4SC1A_ADCHA0:    .equ   0                                         ; Input Channel Select Bit 0
ADC4SC1A_ADCHA1:    .equ   1                                         ; Input Channel Select Bit 1
ADC4SC1A_ADCHA2:    .equ   2                                         ; Input Channel Select Bit 2
ADC4SC1A_ADCHA3:    .equ   3                                         ; Input Channel Select Bit 3
ADC4SC1A_ADCHA4:    .equ   4                                         ; Input Channel Select Bit 4
ADC4SC1A_DIFFA:     .equ   5                                         ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADC4SC1A_AIENA:     .equ   6                                         ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA is high, an interrupt is asserted
ADC4SC1A_COCOA:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC4SC1A_ADCHA0:   .equ   %00000001
mADC4SC1A_ADCHA1:   .equ   %00000010
mADC4SC1A_ADCHA2:   .equ   %00000100
mADC4SC1A_ADCHA3:   .equ   %00001000
mADC4SC1A_ADCHA4:   .equ   %00010000
mADC4SC1A_DIFFA:    .equ   %00100000
mADC4SC1A_AIENA:    .equ   %01000000
mADC4SC1A_COCOA:    .equ   %10000000


;*** ADC4SC1B - Status and Control Register 1B; 0xFFFF84C1 ***
ADC4SC1B:           .equ   $FFFF84C1                                ;*** ADC4SC1B - Status and Control Register 1B; 0xFFFF84C1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4SC1B_ADCHB0:    .equ   0                                         ; Input Channel Select Bit 0
ADC4SC1B_ADCHB1:    .equ   1                                         ; Input Channel Select Bit 1
ADC4SC1B_ADCHB2:    .equ   2                                         ; Input Channel Select Bit 2
ADC4SC1B_ADCHB3:    .equ   3                                         ; Input Channel Select Bit 3
ADC4SC1B_ADCHB4:    .equ   4                                         ; Input Channel Select Bit 4
ADC4SC1B_DIFFB:     .equ   5                                         ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADC4SC1B_AIENB:     .equ   6                                         ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB is high, an interrupt is asserted
ADC4SC1B_COCOB:     .equ   7                                         ; Conversion Complete Flag
; bit position masks
mADC4SC1B_ADCHB0:   .equ   %00000001
mADC4SC1B_ADCHB1:   .equ   %00000010
mADC4SC1B_ADCHB2:   .equ   %00000100
mADC4SC1B_ADCHB3:   .equ   %00001000
mADC4SC1B_ADCHB4:   .equ   %00010000
mADC4SC1B_DIFFB:    .equ   %00100000
mADC4SC1B_AIENB:    .equ   %01000000
mADC4SC1B_COCOB:    .equ   %10000000


;*** ADC4CFG1 - Configuration Register 1; 0xFFFF84C2 ***
ADC4CFG1:           .equ   $FFFF84C2                                ;*** ADC4CFG1 - Configuration Register 1; 0xFFFF84C2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CFG1_ADICLK0:   .equ   0                                         ; Input Clock Select Bit 0
ADC4CFG1_ADICLK1:   .equ   1                                         ; Input Clock Select Bit 1
ADC4CFG1_MODE0:     .equ   2                                         ; Conversion Mode Selection Bit 0
ADC4CFG1_MODE1:     .equ   3                                         ; Conversion Mode Selection Bit 1
ADC4CFG1_ADLSMP:    .equ   4                                         ; Long Sample Time Configuration
ADC4CFG1_ADIV0:     .equ   5                                         ; Clock Divide Select Bit 0
ADC4CFG1_ADIV1:     .equ   6                                         ; Clock Divide Select Bit 1
ADC4CFG1_ADLPC:     .equ   7                                         ; Low Power Configuration
; bit position masks
mADC4CFG1_ADICLK0:  .equ   %00000001
mADC4CFG1_ADICLK1:  .equ   %00000010
mADC4CFG1_MODE0:    .equ   %00000100
mADC4CFG1_MODE1:    .equ   %00001000
mADC4CFG1_ADLSMP:   .equ   %00010000
mADC4CFG1_ADIV0:    .equ   %00100000
mADC4CFG1_ADIV1:    .equ   %01000000
mADC4CFG1_ADLPC:    .equ   %10000000


;*** ADC4CFG2 - Configuration Register 2; 0xFFFF84C3 ***
ADC4CFG2:           .equ   $FFFF84C3                                ;*** ADC4CFG2 - Configuration Register 2; 0xFFFF84C3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CFG2_ADLSTS0:   .equ   0                                         ; Long Sample Time Select Bit 0
ADC4CFG2_ADLSTS1:   .equ   1                                         ; Long Sample Time Select Bit 1
ADC4CFG2_ADHSC:     .equ   2                                         ; High Speed Configuration
ADC4CFG2_ADACKEN:   .equ   3                                         ; Asynchronous Clock Output Enable
; bit position masks
mADC4CFG2_ADLSTS0:  .equ   %00000001
mADC4CFG2_ADLSTS1:  .equ   %00000010
mADC4CFG2_ADHSC:    .equ   %00000100
mADC4CFG2_ADACKEN:  .equ   %00001000


;*** ADC4RA - Data Result Register A; 0xFFFF84C4 ***
ADC4RA:             .equ   $FFFF84C4                                ;*** ADC4RA - Data Result Register A; 0xFFFF84C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4RA_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC4RA_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC4RA_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC4RA_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC4RA_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC4RA_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC4RA_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC4RA_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC4RA_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC4RA_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC4RA_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC4RA_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC4RA_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC4RA_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC4RA_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC4RA_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC4RA_D0:         .equ   %00000001
mADC4RA_D1:         .equ   %00000010
mADC4RA_D2:         .equ   %00000100
mADC4RA_D3:         .equ   %00001000
mADC4RA_D4:         .equ   %00010000
mADC4RA_D5:         .equ   %00100000
mADC4RA_D6:         .equ   %01000000
mADC4RA_D7:         .equ   %10000000
mADC4RA_D8:         .equ   %100000000
mADC4RA_D9:         .equ   %1000000000
mADC4RA_D10:        .equ   %10000000000
mADC4RA_D11:        .equ   %100000000000
mADC4RA_D12:        .equ   %1000000000000
mADC4RA_D13:        .equ   %10000000000000
mADC4RA_D14:        .equ   %100000000000000
mADC4RA_D15:        .equ   %1000000000000000


;*** ADC4RHA - Data Result High Register A; 0xFFFF84C4 ***
ADC4RHA:            .equ   $FFFF84C4                                ;*** ADC4RHA - Data Result High Register A; 0xFFFF84C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4RHA_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC4RHA_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC4RHA_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC4RHA_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC4RHA_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC4RHA_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC4RHA_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC4RHA_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC4RHA_D8:        .equ   %00000001
mADC4RHA_D9:        .equ   %00000010
mADC4RHA_D10:       .equ   %00000100
mADC4RHA_D11:       .equ   %00001000
mADC4RHA_D12:       .equ   %00010000
mADC4RHA_D13:       .equ   %00100000
mADC4RHA_D14:       .equ   %01000000
mADC4RHA_D15:       .equ   %10000000


;*** ADC4RLA - Data Result Low Register A; 0xFFFF84C5 ***
ADC4RLA:            .equ   $FFFF84C5                                ;*** ADC4RLA - Data Result Low Register A; 0xFFFF84C5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4RLA_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC4RLA_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC4RLA_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC4RLA_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC4RLA_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC4RLA_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC4RLA_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC4RLA_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC4RLA_D0:        .equ   %00000001
mADC4RLA_D1:        .equ   %00000010
mADC4RLA_D2:        .equ   %00000100
mADC4RLA_D3:        .equ   %00001000
mADC4RLA_D4:        .equ   %00010000
mADC4RLA_D5:        .equ   %00100000
mADC4RLA_D6:        .equ   %01000000
mADC4RLA_D7:        .equ   %10000000


;*** ADC4RB - Data Result Register B; 0xFFFF84C6 ***
ADC4RB:             .equ   $FFFF84C6                                ;*** ADC4RB - Data Result Register B; 0xFFFF84C6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4RB_D0:          .equ   0                                         ; ADC Result Data Bit 0
ADC4RB_D1:          .equ   1                                         ; ADC Result Data Bit 1
ADC4RB_D2:          .equ   2                                         ; ADC Result Data Bit 2
ADC4RB_D3:          .equ   3                                         ; ADC Result Data Bit 3
ADC4RB_D4:          .equ   4                                         ; ADC Result Data Bit 4
ADC4RB_D5:          .equ   5                                         ; ADC Result Data Bit 5
ADC4RB_D6:          .equ   6                                         ; ADC Result Data Bit 6
ADC4RB_D7:          .equ   7                                         ; ADC Result Data Bit 7
ADC4RB_D8:          .equ   8                                         ; ADC Result Data Bit 8
ADC4RB_D9:          .equ   9                                         ; ADC Result Data Bit 9
ADC4RB_D10:         .equ   10                                        ; ADC Result Data Bit 10
ADC4RB_D11:         .equ   11                                        ; ADC Result Data Bit 11
ADC4RB_D12:         .equ   12                                        ; ADC Result Data Bit 12
ADC4RB_D13:         .equ   13                                        ; ADC Result Data Bit 13
ADC4RB_D14:         .equ   14                                        ; ADC Result Data Bit 14
ADC4RB_D15:         .equ   15                                        ; ADC Result Data Bit 15
; bit position masks
mADC4RB_D0:         .equ   %00000001
mADC4RB_D1:         .equ   %00000010
mADC4RB_D2:         .equ   %00000100
mADC4RB_D3:         .equ   %00001000
mADC4RB_D4:         .equ   %00010000
mADC4RB_D5:         .equ   %00100000
mADC4RB_D6:         .equ   %01000000
mADC4RB_D7:         .equ   %10000000
mADC4RB_D8:         .equ   %100000000
mADC4RB_D9:         .equ   %1000000000
mADC4RB_D10:        .equ   %10000000000
mADC4RB_D11:        .equ   %100000000000
mADC4RB_D12:        .equ   %1000000000000
mADC4RB_D13:        .equ   %10000000000000
mADC4RB_D14:        .equ   %100000000000000
mADC4RB_D15:        .equ   %1000000000000000


;*** ADC4RHB - Data Result High Register B; 0xFFFF84C6 ***
ADC4RHB:            .equ   $FFFF84C6                                ;*** ADC4RHB - Data Result High Register B; 0xFFFF84C6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4RHB_D8:         .equ   0                                         ; ADC Result Data Bit 8
ADC4RHB_D9:         .equ   1                                         ; ADC Result Data Bit 9
ADC4RHB_D10:        .equ   2                                         ; ADC Result Data Bit 10
ADC4RHB_D11:        .equ   3                                         ; ADC Result Data Bit 11
ADC4RHB_D12:        .equ   4                                         ; ADC Result Data Bit 12
ADC4RHB_D13:        .equ   5                                         ; ADC Result Data Bit 13
ADC4RHB_D14:        .equ   6                                         ; ADC Result Data Bit 14
ADC4RHB_D15:        .equ   7                                         ; ADC Result Data Bit 15
; bit position masks
mADC4RHB_D8:        .equ   %00000001
mADC4RHB_D9:        .equ   %00000010
mADC4RHB_D10:       .equ   %00000100
mADC4RHB_D11:       .equ   %00001000
mADC4RHB_D12:       .equ   %00010000
mADC4RHB_D13:       .equ   %00100000
mADC4RHB_D14:       .equ   %01000000
mADC4RHB_D15:       .equ   %10000000


;*** ADC4RLB - Data Result Low Register B; 0xFFFF84C7 ***
ADC4RLB:            .equ   $FFFF84C7                                ;*** ADC4RLB - Data Result Low Register B; 0xFFFF84C7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4RLB_D0:         .equ   0                                         ; ADC Result Data Bit 0
ADC4RLB_D1:         .equ   1                                         ; ADC Result Data Bit 1
ADC4RLB_D2:         .equ   2                                         ; ADC Result Data Bit 2
ADC4RLB_D3:         .equ   3                                         ; ADC Result Data Bit 3
ADC4RLB_D4:         .equ   4                                         ; ADC Result Data Bit 4
ADC4RLB_D5:         .equ   5                                         ; ADC Result Data Bit 5
ADC4RLB_D6:         .equ   6                                         ; ADC Result Data Bit 6
ADC4RLB_D7:         .equ   7                                         ; ADC Result Data Bit 7
; bit position masks
mADC4RLB_D0:        .equ   %00000001
mADC4RLB_D1:        .equ   %00000010
mADC4RLB_D2:        .equ   %00000100
mADC4RLB_D3:        .equ   %00001000
mADC4RLB_D4:        .equ   %00010000
mADC4RLB_D5:        .equ   %00100000
mADC4RLB_D6:        .equ   %01000000
mADC4RLB_D7:        .equ   %10000000


;*** ADC4CV1 - Compare Value 1 Register; 0xFFFF84C8 ***
ADC4CV1:            .equ   $FFFF84C8                                ;*** ADC4CV1 - Compare Value 1 Register; 0xFFFF84C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CV1_CV10:       .equ   0                                         ; Compare Function Value 0
ADC4CV1_CV11:       .equ   1                                         ; Compare Function Value 1
ADC4CV1_CV12:       .equ   2                                         ; Compare Function Value 2
ADC4CV1_CV13:       .equ   3                                         ; Compare Function Value 3
ADC4CV1_CV14:       .equ   4                                         ; Compare Function Value 4
ADC4CV1_CV15:       .equ   5                                         ; Compare Function Value 5
ADC4CV1_CV16:       .equ   6                                         ; Compare Function Value 6
ADC4CV1_CV17:       .equ   7                                         ; Compare Function Value 7
ADC4CV1_CV18:       .equ   8                                         ; Compare Function Value 8
ADC4CV1_CV19:       .equ   9                                         ; Compare Function Value 9
ADC4CV1_CV110:      .equ   10                                        ; Compare Function Value 10
ADC4CV1_CV111:      .equ   11                                        ; Compare Function Value 11
ADC4CV1_CV112:      .equ   12                                        ; Compare Function Value 12
ADC4CV1_CV113:      .equ   13                                        ; Compare Function Value 13
ADC4CV1_CV114:      .equ   14                                        ; Compare Function Value 14
ADC4CV1_CV115:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC4CV1_CV10:      .equ   %00000001
mADC4CV1_CV11:      .equ   %00000010
mADC4CV1_CV12:      .equ   %00000100
mADC4CV1_CV13:      .equ   %00001000
mADC4CV1_CV14:      .equ   %00010000
mADC4CV1_CV15:      .equ   %00100000
mADC4CV1_CV16:      .equ   %01000000
mADC4CV1_CV17:      .equ   %10000000
mADC4CV1_CV18:      .equ   %100000000
mADC4CV1_CV19:      .equ   %1000000000
mADC4CV1_CV110:     .equ   %10000000000
mADC4CV1_CV111:     .equ   %100000000000
mADC4CV1_CV112:     .equ   %1000000000000
mADC4CV1_CV113:     .equ   %10000000000000
mADC4CV1_CV114:     .equ   %100000000000000
mADC4CV1_CV115:     .equ   %1000000000000000


;*** ADC4CV1H - Compare Value 1 High Register; 0xFFFF84C8 ***
ADC4CV1H:           .equ   $FFFF84C8                                ;*** ADC4CV1H - Compare Value 1 High Register; 0xFFFF84C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CV1H_CV18:      .equ   0                                         ; Compare Function Value 8
ADC4CV1H_CV19:      .equ   1                                         ; Compare Function Value 9
ADC4CV1H_CV110:     .equ   2                                         ; Compare Function Value 10
ADC4CV1H_CV111:     .equ   3                                         ; Compare Function Value 11
ADC4CV1H_CV112:     .equ   4                                         ; Compare Function Value 12
ADC4CV1H_CV113:     .equ   5                                         ; Compare Function Value 13
ADC4CV1H_CV114:     .equ   6                                         ; Compare Function Value 14
ADC4CV1H_CV115:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC4CV1H_CV18:     .equ   %00000001
mADC4CV1H_CV19:     .equ   %00000010
mADC4CV1H_CV110:    .equ   %00000100
mADC4CV1H_CV111:    .equ   %00001000
mADC4CV1H_CV112:    .equ   %00010000
mADC4CV1H_CV113:    .equ   %00100000
mADC4CV1H_CV114:    .equ   %01000000
mADC4CV1H_CV115:    .equ   %10000000


;*** ADC4CV1L - Compare Value 1 Low Register; 0xFFFF84C9 ***
ADC4CV1L:           .equ   $FFFF84C9                                ;*** ADC4CV1L - Compare Value 1 Low Register; 0xFFFF84C9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CV1L_CV10:      .equ   0                                         ; Compare Function Value 0
ADC4CV1L_CV11:      .equ   1                                         ; Compare Function Value 1
ADC4CV1L_CV12:      .equ   2                                         ; Compare Function Value 2
ADC4CV1L_CV13:      .equ   3                                         ; Compare Function Value 3
ADC4CV1L_CV14:      .equ   4                                         ; Compare Function Value 4
ADC4CV1L_CV15:      .equ   5                                         ; Compare Function Value 5
ADC4CV1L_CV16:      .equ   6                                         ; Compare Function Value 6
ADC4CV1L_CV17:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC4CV1L_CV10:     .equ   %00000001
mADC4CV1L_CV11:     .equ   %00000010
mADC4CV1L_CV12:     .equ   %00000100
mADC4CV1L_CV13:     .equ   %00001000
mADC4CV1L_CV14:     .equ   %00010000
mADC4CV1L_CV15:     .equ   %00100000
mADC4CV1L_CV16:     .equ   %01000000
mADC4CV1L_CV17:     .equ   %10000000


;*** ADC4CV2 - Compare Value 2 Register; 0xFFFF84CA ***
ADC4CV2:            .equ   $FFFF84CA                                ;*** ADC4CV2 - Compare Value 2 Register; 0xFFFF84CA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CV2_CV20:       .equ   0                                         ; Compare Function Value 0
ADC4CV2_CV21:       .equ   1                                         ; Compare Function Value 1
ADC4CV2_CV22:       .equ   2                                         ; Compare Function Value 2
ADC4CV2_CV23:       .equ   3                                         ; Compare Function Value 3
ADC4CV2_CV24:       .equ   4                                         ; Compare Function Value 4
ADC4CV2_CV25:       .equ   5                                         ; Compare Function Value 5
ADC4CV2_CV26:       .equ   6                                         ; Compare Function Value 6
ADC4CV2_CV27:       .equ   7                                         ; Compare Function Value 7
ADC4CV2_CV28:       .equ   8                                         ; Compare Function Value 8
ADC4CV2_CV29:       .equ   9                                         ; Compare Function Value 9
ADC4CV2_CV210:      .equ   10                                        ; Compare Function Value 10
ADC4CV2_CV211:      .equ   11                                        ; Compare Function Value 11
ADC4CV2_CV212:      .equ   12                                        ; Compare Function Value 12
ADC4CV2_CV213:      .equ   13                                        ; Compare Function Value 13
ADC4CV2_CV214:      .equ   14                                        ; Compare Function Value 14
ADC4CV2_CV215:      .equ   15                                        ; Compare Function Value 15
; bit position masks
mADC4CV2_CV20:      .equ   %00000001
mADC4CV2_CV21:      .equ   %00000010
mADC4CV2_CV22:      .equ   %00000100
mADC4CV2_CV23:      .equ   %00001000
mADC4CV2_CV24:      .equ   %00010000
mADC4CV2_CV25:      .equ   %00100000
mADC4CV2_CV26:      .equ   %01000000
mADC4CV2_CV27:      .equ   %10000000
mADC4CV2_CV28:      .equ   %100000000
mADC4CV2_CV29:      .equ   %1000000000
mADC4CV2_CV210:     .equ   %10000000000
mADC4CV2_CV211:     .equ   %100000000000
mADC4CV2_CV212:     .equ   %1000000000000
mADC4CV2_CV213:     .equ   %10000000000000
mADC4CV2_CV214:     .equ   %100000000000000
mADC4CV2_CV215:     .equ   %1000000000000000


;*** ADC4CV2H - Compare Value 2 High Register; 0xFFFF84CA ***
ADC4CV2H:           .equ   $FFFF84CA                                ;*** ADC4CV2H - Compare Value 2 High Register; 0xFFFF84CA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CV2H_CV28:      .equ   0                                         ; Compare Function Value 8
ADC4CV2H_CV29:      .equ   1                                         ; Compare Function Value 9
ADC4CV2H_CV210:     .equ   2                                         ; Compare Function Value 10
ADC4CV2H_CV211:     .equ   3                                         ; Compare Function Value 11
ADC4CV2H_CV212:     .equ   4                                         ; Compare Function Value 12
ADC4CV2H_CV213:     .equ   5                                         ; Compare Function Value 13
ADC4CV2H_CV214:     .equ   6                                         ; Compare Function Value 14
ADC4CV2H_CV215:     .equ   7                                         ; Compare Function Value 15
; bit position masks
mADC4CV2H_CV28:     .equ   %00000001
mADC4CV2H_CV29:     .equ   %00000010
mADC4CV2H_CV210:    .equ   %00000100
mADC4CV2H_CV211:    .equ   %00001000
mADC4CV2H_CV212:    .equ   %00010000
mADC4CV2H_CV213:    .equ   %00100000
mADC4CV2H_CV214:    .equ   %01000000
mADC4CV2H_CV215:    .equ   %10000000


;*** ADC4CV2L - Compare Value 2 Low Register; 0xFFFF84CB ***
ADC4CV2L:           .equ   $FFFF84CB                                ;*** ADC4CV2L - Compare Value 2 Low Register; 0xFFFF84CB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CV2L_CV20:      .equ   0                                         ; Compare Function Value 0
ADC4CV2L_CV21:      .equ   1                                         ; Compare Function Value 1
ADC4CV2L_CV22:      .equ   2                                         ; Compare Function Value 2
ADC4CV2L_CV23:      .equ   3                                         ; Compare Function Value 3
ADC4CV2L_CV24:      .equ   4                                         ; Compare Function Value 4
ADC4CV2L_CV25:      .equ   5                                         ; Compare Function Value 5
ADC4CV2L_CV26:      .equ   6                                         ; Compare Function Value 6
ADC4CV2L_CV27:      .equ   7                                         ; Compare Function Value 7
; bit position masks
mADC4CV2L_CV20:     .equ   %00000001
mADC4CV2L_CV21:     .equ   %00000010
mADC4CV2L_CV22:     .equ   %00000100
mADC4CV2L_CV23:     .equ   %00001000
mADC4CV2L_CV24:     .equ   %00010000
mADC4CV2L_CV25:     .equ   %00100000
mADC4CV2L_CV26:     .equ   %01000000
mADC4CV2L_CV27:     .equ   %10000000


;*** ADC4SC2 - Status and Control Register 2; 0xFFFF84CC ***
ADC4SC2:            .equ   $FFFF84CC                                ;*** ADC4SC2 - Status and Control Register 2; 0xFFFF84CC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4SC2_REFSEL0:    .equ   0                                         ; Voltage Reference Selection, bit 0
ADC4SC2_REFSEL1:    .equ   1                                         ; Voltage Reference Selection, bit 1
ADC4SC2_ACREN:      .equ   3                                         ; Unused
ADC4SC2_ACFGT:      .equ   4                                         ; Compare Function Greater Than Enable
ADC4SC2_ACFE:       .equ   5                                         ; Compare Function Enable - ACFE is used to enable the compare function
ADC4SC2_ADTRG:      .equ   6                                         ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion
ADC4SC2_ADACT:      .equ   7                                         ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted
; bit position masks
mADC4SC2_REFSEL0:   .equ   %00000001
mADC4SC2_REFSEL1:   .equ   %00000010
mADC4SC2_ACREN:     .equ   %00001000
mADC4SC2_ACFGT:     .equ   %00010000
mADC4SC2_ACFE:      .equ   %00100000
mADC4SC2_ADTRG:     .equ   %01000000
mADC4SC2_ADACT:     .equ   %10000000


;*** ADC4SC3 - Status and Control Register 3; 0xFFFF84CD ***
ADC4SC3:            .equ   $FFFF84CD                                ;*** ADC4SC3 - Status and Control Register 3; 0xFFFF84CD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4SC3_AVGS0:      .equ   0                                         ; Hardware Average select, bit 0
ADC4SC3_AVGS1:      .equ   1                                         ; Hardware Average select, bit 1
ADC4SC3_AVGE:       .equ   2                                         ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADC4SC3_ADCO:       .equ   3                                         ; Continuous Conversion Enable - ADCO enables continuous conversions
ADC4SC3_CALF:       .equ   6                                         ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC4SC3_CAL:        .equ   7                                         ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADC4SC3_AVGS0:     .equ   %00000001
mADC4SC3_AVGS1:     .equ   %00000010
mADC4SC3_AVGE:      .equ   %00000100
mADC4SC3_ADCO:      .equ   %00001000
mADC4SC3_CALF:      .equ   %01000000
mADC4SC3_CAL:       .equ   %10000000


;*** ADC4OFS - Offset Correction Register; 0xFFFF84CE ***
ADC4OFS:            .equ   $FFFF84CE                                ;*** ADC4OFS - Offset Correction Register; 0xFFFF84CE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4OFS_OFS0:       .equ   0                                         ; Offset error correction value bit 0
ADC4OFS_OFS1:       .equ   1                                         ; Offset error correction value bit 1
ADC4OFS_OFS2:       .equ   2                                         ; Offset error correction value bit 2
ADC4OFS_OFS3:       .equ   3                                         ; Offset error correction value bit 3
ADC4OFS_OFS4:       .equ   4                                         ; Offset error correction value bit 4
ADC4OFS_OFS5:       .equ   5                                         ; Offset error correction value bit 5
ADC4OFS_OFS6:       .equ   6                                         ; Offset error correction value bit 6
ADC4OFS_OFS7:       .equ   7                                         ; Offset error correction value bit 7
ADC4OFS_OFS8:       .equ   8                                         ; Offset error correction value bit 8
ADC4OFS_OFS9:       .equ   9                                         ; Offset error correction value bit 9
ADC4OFS_OFS10:      .equ   10                                        ; Offset error correction value bit 10
ADC4OFS_OFS11:      .equ   11                                        ; Offset error correction value bit 11
ADC4OFS_OFS12:      .equ   12                                        ; Offset error correction value bit 12
ADC4OFS_OFS13:      .equ   13                                        ; Offset error correction value bit 13
ADC4OFS_OFS14:      .equ   14                                        ; Offset error correction value bit 14
ADC4OFS_OFS15:      .equ   15                                        ; Offset error correction value bit 15
; bit position masks
mADC4OFS_OFS0:      .equ   %00000001
mADC4OFS_OFS1:      .equ   %00000010
mADC4OFS_OFS2:      .equ   %00000100
mADC4OFS_OFS3:      .equ   %00001000
mADC4OFS_OFS4:      .equ   %00010000
mADC4OFS_OFS5:      .equ   %00100000
mADC4OFS_OFS6:      .equ   %01000000
mADC4OFS_OFS7:      .equ   %10000000
mADC4OFS_OFS8:      .equ   %100000000
mADC4OFS_OFS9:      .equ   %1000000000
mADC4OFS_OFS10:     .equ   %10000000000
mADC4OFS_OFS11:     .equ   %100000000000
mADC4OFS_OFS12:     .equ   %1000000000000
mADC4OFS_OFS13:     .equ   %10000000000000
mADC4OFS_OFS14:     .equ   %100000000000000
mADC4OFS_OFS15:     .equ   %1000000000000000


;*** ADC4OFSH - Offset Correction High Register; 0xFFFF84CE ***
ADC4OFSH:           .equ   $FFFF84CE                                ;*** ADC4OFSH - Offset Correction High Register; 0xFFFF84CE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4OFSH_OFS8:      .equ   0                                         ; Offset error correction value bit 8
ADC4OFSH_OFS9:      .equ   1                                         ; Offset error correction value bit 9
ADC4OFSH_OFS10:     .equ   2                                         ; Offset error correction value bit 10
ADC4OFSH_OFS11:     .equ   3                                         ; Offset error correction value bit 11
ADC4OFSH_OFS12:     .equ   4                                         ; Offset error correction value bit 12
ADC4OFSH_OFS13:     .equ   5                                         ; Offset error correction value bit 13
ADC4OFSH_OFS14:     .equ   6                                         ; Offset error correction value bit 14
ADC4OFSH_OFS15:     .equ   7                                         ; Offset error correction value bit 15
; bit position masks
mADC4OFSH_OFS8:     .equ   %00000001
mADC4OFSH_OFS9:     .equ   %00000010
mADC4OFSH_OFS10:    .equ   %00000100
mADC4OFSH_OFS11:    .equ   %00001000
mADC4OFSH_OFS12:    .equ   %00010000
mADC4OFSH_OFS13:    .equ   %00100000
mADC4OFSH_OFS14:    .equ   %01000000
mADC4OFSH_OFS15:    .equ   %10000000


;*** ADC4OFSL - Offset Correction Low Register; 0xFFFF84CF ***
ADC4OFSL:           .equ   $FFFF84CF                                ;*** ADC4OFSL - Offset Correction Low Register; 0xFFFF84CF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4OFSL_OFS0:      .equ   0                                         ; Offset error correction value bit 0
ADC4OFSL_OFS1:      .equ   1                                         ; Offset error correction value bit 1
ADC4OFSL_OFS2:      .equ   2                                         ; Offset error correction value bit 2
ADC4OFSL_OFS3:      .equ   3                                         ; Offset error correction value bit 3
ADC4OFSL_OFS4:      .equ   4                                         ; Offset error correction value bit 4
ADC4OFSL_OFS5:      .equ   5                                         ; Offset error correction value bit 5
ADC4OFSL_OFS6:      .equ   6                                         ; Offset error correction value bit 6
ADC4OFSL_OFS7:      .equ   7                                         ; Offset error correction value bit 7
; bit position masks
mADC4OFSL_OFS0:     .equ   %00000001
mADC4OFSL_OFS1:     .equ   %00000010
mADC4OFSL_OFS2:     .equ   %00000100
mADC4OFSL_OFS3:     .equ   %00001000
mADC4OFSL_OFS4:     .equ   %00010000
mADC4OFSL_OFS5:     .equ   %00100000
mADC4OFSL_OFS6:     .equ   %01000000
mADC4OFSL_OFS7:     .equ   %10000000


;*** ADC4PG - Plus-Side Gain Register; 0xFFFF84D0 ***
ADC4PG:             .equ   $FFFF84D0                                ;*** ADC4PG - Plus-Side Gain Register; 0xFFFF84D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4PG_PG0:         .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC4PG_PG1:         .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC4PG_PG2:         .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC4PG_PG3:         .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC4PG_PG4:         .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC4PG_PG5:         .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC4PG_PG6:         .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC4PG_PG7:         .equ   7                                         ; Gain error correction for the plus-side input value bit 7
ADC4PG_PG8:         .equ   8                                         ; Gain error correction for the plus-side input value bit 8
ADC4PG_PG9:         .equ   9                                         ; Gain error correction for the plus-side input value bit 9
ADC4PG_PG10:        .equ   10                                        ; Gain error correction for the plus-side input value bit 10
ADC4PG_PG11:        .equ   11                                        ; Gain error correction for the plus-side input value bit 11
ADC4PG_PG12:        .equ   12                                        ; Gain error correction for the plus-side input value bit 12
ADC4PG_PG13:        .equ   13                                        ; Gain error correction for the plus-side input value bit 13
ADC4PG_PG14:        .equ   14                                        ; Gain error correction for the plus-side input value bit 14
ADC4PG_PG15:        .equ   15                                        ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC4PG_PG0:        .equ   %00000001
mADC4PG_PG1:        .equ   %00000010
mADC4PG_PG2:        .equ   %00000100
mADC4PG_PG3:        .equ   %00001000
mADC4PG_PG4:        .equ   %00010000
mADC4PG_PG5:        .equ   %00100000
mADC4PG_PG6:        .equ   %01000000
mADC4PG_PG7:        .equ   %10000000
mADC4PG_PG8:        .equ   %100000000
mADC4PG_PG9:        .equ   %1000000000
mADC4PG_PG10:       .equ   %10000000000
mADC4PG_PG11:       .equ   %100000000000
mADC4PG_PG12:       .equ   %1000000000000
mADC4PG_PG13:       .equ   %10000000000000
mADC4PG_PG14:       .equ   %100000000000000
mADC4PG_PG15:       .equ   %1000000000000000


;*** ADC4PGH - Plus-Side Gain High Register; 0xFFFF84D0 ***
ADC4PGH:            .equ   $FFFF84D0                                ;*** ADC4PGH - Plus-Side Gain High Register; 0xFFFF84D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4PGH_PG8:        .equ   0                                         ; Gain error correction for the plus-side input value bit 8
ADC4PGH_PG9:        .equ   1                                         ; Gain error correction for the plus-side input value bit 9
ADC4PGH_PG10:       .equ   2                                         ; Gain error correction for the plus-side input value bit 10
ADC4PGH_PG11:       .equ   3                                         ; Gain error correction for the plus-side input value bit 11
ADC4PGH_PG12:       .equ   4                                         ; Gain error correction for the plus-side input value bit 12
ADC4PGH_PG13:       .equ   5                                         ; Gain error correction for the plus-side input value bit 13
ADC4PGH_PG14:       .equ   6                                         ; Gain error correction for the plus-side input value bit 14
ADC4PGH_PG15:       .equ   7                                         ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC4PGH_PG8:       .equ   %00000001
mADC4PGH_PG9:       .equ   %00000010
mADC4PGH_PG10:      .equ   %00000100
mADC4PGH_PG11:      .equ   %00001000
mADC4PGH_PG12:      .equ   %00010000
mADC4PGH_PG13:      .equ   %00100000
mADC4PGH_PG14:      .equ   %01000000
mADC4PGH_PG15:      .equ   %10000000


;*** ADC4PGL - Plus-Side Gain Low Register; 0xFFFF84D1 ***
ADC4PGL:            .equ   $FFFF84D1                                ;*** ADC4PGL - Plus-Side Gain Low Register; 0xFFFF84D1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4PGL_PG0:        .equ   0                                         ; Gain error correction for the plus-side input value bit 0
ADC4PGL_PG1:        .equ   1                                         ; Gain error correction for the plus-side input value bit 1
ADC4PGL_PG2:        .equ   2                                         ; Gain error correction for the plus-side input value bit 2
ADC4PGL_PG3:        .equ   3                                         ; Gain error correction for the plus-side input value bit 3
ADC4PGL_PG4:        .equ   4                                         ; Gain error correction for the plus-side input value bit 4
ADC4PGL_PG5:        .equ   5                                         ; Gain error correction for the plus-side input value bit 5
ADC4PGL_PG6:        .equ   6                                         ; Gain error correction for the plus-side input value bit 6
ADC4PGL_PG7:        .equ   7                                         ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADC4PGL_PG0:       .equ   %00000001
mADC4PGL_PG1:       .equ   %00000010
mADC4PGL_PG2:       .equ   %00000100
mADC4PGL_PG3:       .equ   %00001000
mADC4PGL_PG4:       .equ   %00010000
mADC4PGL_PG5:       .equ   %00100000
mADC4PGL_PG6:       .equ   %01000000
mADC4PGL_PG7:       .equ   %10000000


;*** ADC4MG - Minus-Side Gain Register; 0xFFFF84D2 ***
ADC4MG:             .equ   $FFFF84D2                                ;*** ADC4MG - Minus-Side Gain Register; 0xFFFF84D2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4MG_MG0:         .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC4MG_MG1:         .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC4MG_MG2:         .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC4MG_MG3:         .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC4MG_MG4:         .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC4MG_MG5:         .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC4MG_MG6:         .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC4MG_MG7:         .equ   7                                         ; Gain error correction for the minus-side input value bit 7
ADC4MG_MG8:         .equ   8                                         ; Gain error correction for the minus-side input value bit 8
ADC4MG_MG9:         .equ   9                                         ; Gain error correction for the minus-side input value bit 9
ADC4MG_MG10:        .equ   10                                        ; Gain error correction for the minus-side input value bit 10
ADC4MG_MG11:        .equ   11                                        ; Gain error correction for the minus-side input value bit 11
ADC4MG_MG12:        .equ   12                                        ; Gain error correction for the minus-side input value bit 12
ADC4MG_MG13:        .equ   13                                        ; Gain error correction for the minus-side input value bit 13
ADC4MG_MG14:        .equ   14                                        ; Gain error correction for the minus-side input value bit 14
ADC4MG_MG15:        .equ   15                                        ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC4MG_MG0:        .equ   %00000001
mADC4MG_MG1:        .equ   %00000010
mADC4MG_MG2:        .equ   %00000100
mADC4MG_MG3:        .equ   %00001000
mADC4MG_MG4:        .equ   %00010000
mADC4MG_MG5:        .equ   %00100000
mADC4MG_MG6:        .equ   %01000000
mADC4MG_MG7:        .equ   %10000000
mADC4MG_MG8:        .equ   %100000000
mADC4MG_MG9:        .equ   %1000000000
mADC4MG_MG10:       .equ   %10000000000
mADC4MG_MG11:       .equ   %100000000000
mADC4MG_MG12:       .equ   %1000000000000
mADC4MG_MG13:       .equ   %10000000000000
mADC4MG_MG14:       .equ   %100000000000000
mADC4MG_MG15:       .equ   %1000000000000000


;*** ADC4MGH - Minus-Side Gain High Register; 0xFFFF84D2 ***
ADC4MGH:            .equ   $FFFF84D2                                ;*** ADC4MGH - Minus-Side Gain High Register; 0xFFFF84D2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4MGH_MG8:        .equ   0                                         ; Gain error correction for the minus-side input value bit 8
ADC4MGH_MG9:        .equ   1                                         ; Gain error correction for the minus-side input value bit 9
ADC4MGH_MG10:       .equ   2                                         ; Gain error correction for the minus-side input value bit 10
ADC4MGH_MG11:       .equ   3                                         ; Gain error correction for the minus-side input value bit 11
ADC4MGH_MG12:       .equ   4                                         ; Gain error correction for the minus-side input value bit 12
ADC4MGH_MG13:       .equ   5                                         ; Gain error correction for the minus-side input value bit 13
ADC4MGH_MG14:       .equ   6                                         ; Gain error correction for the minus-side input value bit 14
ADC4MGH_MG15:       .equ   7                                         ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC4MGH_MG8:       .equ   %00000001
mADC4MGH_MG9:       .equ   %00000010
mADC4MGH_MG10:      .equ   %00000100
mADC4MGH_MG11:      .equ   %00001000
mADC4MGH_MG12:      .equ   %00010000
mADC4MGH_MG13:      .equ   %00100000
mADC4MGH_MG14:      .equ   %01000000
mADC4MGH_MG15:      .equ   %10000000


;*** ADC4MGL - Minus-Side Gain Low Register; 0xFFFF84D3 ***
ADC4MGL:            .equ   $FFFF84D3                                ;*** ADC4MGL - Minus-Side Gain Low Register; 0xFFFF84D3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4MGL_MG0:        .equ   0                                         ; Gain error correction for the minus-side input value bit 0
ADC4MGL_MG1:        .equ   1                                         ; Gain error correction for the minus-side input value bit 1
ADC4MGL_MG2:        .equ   2                                         ; Gain error correction for the minus-side input value bit 2
ADC4MGL_MG3:        .equ   3                                         ; Gain error correction for the minus-side input value bit 3
ADC4MGL_MG4:        .equ   4                                         ; Gain error correction for the minus-side input value bit 4
ADC4MGL_MG5:        .equ   5                                         ; Gain error correction for the minus-side input value bit 5
ADC4MGL_MG6:        .equ   6                                         ; Gain error correction for the minus-side input value bit 6
ADC4MGL_MG7:        .equ   7                                         ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADC4MGL_MG0:       .equ   %00000001
mADC4MGL_MG1:       .equ   %00000010
mADC4MGL_MG2:       .equ   %00000100
mADC4MGL_MG3:       .equ   %00001000
mADC4MGL_MG4:       .equ   %00010000
mADC4MGL_MG5:       .equ   %00100000
mADC4MGL_MG6:       .equ   %01000000
mADC4MGL_MG7:       .equ   %10000000


;*** ADC4CLPD - Plus-Side General Calibration Value D Register; 0xFFFF84D4 ***
ADC4CLPD:           .equ   $FFFF84D4                                ;*** ADC4CLPD - Plus-Side General Calibration Value D Register; 0xFFFF84D4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLPD_CLPD0:     .equ   0                                         ; Plus-Side General Calibration Value D bit 0
ADC4CLPD_CLPD1:     .equ   1                                         ; Plus-Side General Calibration Value D bit 1
ADC4CLPD_CLPD2:     .equ   2                                         ; Plus-Side General Calibration Value D bit 2
ADC4CLPD_CLPD3:     .equ   3                                         ; Plus-Side General Calibration Value D bit 3
ADC4CLPD_CLPD4:     .equ   4                                         ; Plus-Side General Calibration Value D bit 4
ADC4CLPD_CLPD5:     .equ   5                                         ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADC4CLPD_CLPD0:    .equ   %00000001
mADC4CLPD_CLPD1:    .equ   %00000010
mADC4CLPD_CLPD2:    .equ   %00000100
mADC4CLPD_CLPD3:    .equ   %00001000
mADC4CLPD_CLPD4:    .equ   %00010000
mADC4CLPD_CLPD5:    .equ   %00100000


;*** ADC4CLPS - Plus-Side General Calibration Value S Register; 0xFFFF84D5 ***
ADC4CLPS:           .equ   $FFFF84D5                                ;*** ADC4CLPS - Plus-Side General Calibration Value S Register; 0xFFFF84D5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLPS_CLPS0:     .equ   0                                         ; Plus-Side General Calibration Value S bit 0
ADC4CLPS_CLPS1:     .equ   1                                         ; Plus-Side General Calibration Value S bit 1
ADC4CLPS_CLPS2:     .equ   2                                         ; Plus-Side General Calibration Value S bit 2
ADC4CLPS_CLPS3:     .equ   3                                         ; Plus-Side General Calibration Value S bit 3
ADC4CLPS_CLPS4:     .equ   4                                         ; Plus-Side General Calibration Value S bit 4
ADC4CLPS_CLPS5:     .equ   5                                         ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADC4CLPS_CLPS0:    .equ   %00000001
mADC4CLPS_CLPS1:    .equ   %00000010
mADC4CLPS_CLPS2:    .equ   %00000100
mADC4CLPS_CLPS3:    .equ   %00001000
mADC4CLPS_CLPS4:    .equ   %00010000
mADC4CLPS_CLPS5:    .equ   %00100000


;*** ADC4CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF84D6 ***
ADC4CLP4:           .equ   $FFFF84D6                                ;*** ADC4CLP4 - Plus-Side General Calibration Value 4 Register; 0xFFFF84D6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP4_CLP40:     .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC4CLP4_CLP41:     .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC4CLP4_CLP42:     .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC4CLP4_CLP43:     .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC4CLP4_CLP44:     .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC4CLP4_CLP45:     .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC4CLP4_CLP46:     .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC4CLP4_CLP47:     .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
ADC4CLP4_CLP48:     .equ   8                                         ; Plus-Side General Calibration Value 4 bit 8
ADC4CLP4_CLP49:     .equ   9                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC4CLP4_CLP40:    .equ   %00000001
mADC4CLP4_CLP41:    .equ   %00000010
mADC4CLP4_CLP42:    .equ   %00000100
mADC4CLP4_CLP43:    .equ   %00001000
mADC4CLP4_CLP44:    .equ   %00010000
mADC4CLP4_CLP45:    .equ   %00100000
mADC4CLP4_CLP46:    .equ   %01000000
mADC4CLP4_CLP47:    .equ   %10000000
mADC4CLP4_CLP48:    .equ   %100000000
mADC4CLP4_CLP49:    .equ   %1000000000


;*** ADC4CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF84D6 ***
ADC4CLP4H:          .equ   $FFFF84D6                                ;*** ADC4CLP4H - Plus-Side General Calibration Value 4 High Register; 0xFFFF84D6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP4H_CLP48:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 8
ADC4CLP4H_CLP49:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC4CLP4H_CLP48:   .equ   %00000001
mADC4CLP4H_CLP49:   .equ   %00000010


;*** ADC4CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF84D7 ***
ADC4CLP4L:          .equ   $FFFF84D7                                ;*** ADC4CLP4L - Plus-Side General Calibration Value 4 Low Register; 0xFFFF84D7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP4L_CLP40:    .equ   0                                         ; Plus-Side General Calibration Value 4 bit 0
ADC4CLP4L_CLP41:    .equ   1                                         ; Plus-Side General Calibration Value 4 bit 1
ADC4CLP4L_CLP42:    .equ   2                                         ; Plus-Side General Calibration Value 4 bit 2
ADC4CLP4L_CLP43:    .equ   3                                         ; Plus-Side General Calibration Value 4 bit 3
ADC4CLP4L_CLP44:    .equ   4                                         ; Plus-Side General Calibration Value 4 bit 4
ADC4CLP4L_CLP45:    .equ   5                                         ; Plus-Side General Calibration Value 4 bit 5
ADC4CLP4L_CLP46:    .equ   6                                         ; Plus-Side General Calibration Value 4 bit 6
ADC4CLP4L_CLP47:    .equ   7                                         ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADC4CLP4L_CLP40:   .equ   %00000001
mADC4CLP4L_CLP41:   .equ   %00000010
mADC4CLP4L_CLP42:   .equ   %00000100
mADC4CLP4L_CLP43:   .equ   %00001000
mADC4CLP4L_CLP44:   .equ   %00010000
mADC4CLP4L_CLP45:   .equ   %00100000
mADC4CLP4L_CLP46:   .equ   %01000000
mADC4CLP4L_CLP47:   .equ   %10000000


;*** ADC4CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF84D8 ***
ADC4CLP3:           .equ   $FFFF84D8                                ;*** ADC4CLP3 - Plus-Side General Calibration Value 3 Register; 0xFFFF84D8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP3_CLP30:     .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC4CLP3_CLP31:     .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC4CLP3_CLP32:     .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC4CLP3_CLP33:     .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC4CLP3_CLP34:     .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC4CLP3_CLP35:     .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC4CLP3_CLP36:     .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC4CLP3_CLP37:     .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
ADC4CLP3_CLP38:     .equ   8                                         ; Plus-Side General Calibration Value 3 bit 8
; bit position masks
mADC4CLP3_CLP30:    .equ   %00000001
mADC4CLP3_CLP31:    .equ   %00000010
mADC4CLP3_CLP32:    .equ   %00000100
mADC4CLP3_CLP33:    .equ   %00001000
mADC4CLP3_CLP34:    .equ   %00010000
mADC4CLP3_CLP35:    .equ   %00100000
mADC4CLP3_CLP36:    .equ   %01000000
mADC4CLP3_CLP37:    .equ   %10000000
mADC4CLP3_CLP38:    .equ   %100000000


;*** ADC4CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF84D8 ***
ADC4CLP3H:          .equ   $FFFF84D8                                ;*** ADC4CLP3H - Plus-Side General Calibration Value 3 High Register; 0xFFFF84D8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP3H_CLP38:    .equ   0                                         ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADC4CLP3H_CLP38:   .equ   %00000001


;*** ADC4CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF84D9 ***
ADC4CLP3L:          .equ   $FFFF84D9                                ;*** ADC4CLP3L - Plus-Side General Calibration Value 3 Low Register; 0xFFFF84D9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP3L_CLP30:    .equ   0                                         ; Plus-Side General Calibration Value 3 bit 0
ADC4CLP3L_CLP31:    .equ   1                                         ; Plus-Side General Calibration Value 3 bit 1
ADC4CLP3L_CLP32:    .equ   2                                         ; Plus-Side General Calibration Value 3 bit 2
ADC4CLP3L_CLP33:    .equ   3                                         ; Plus-Side General Calibration Value 3 bit 3
ADC4CLP3L_CLP34:    .equ   4                                         ; Plus-Side General Calibration Value 3 bit 4
ADC4CLP3L_CLP35:    .equ   5                                         ; Plus-Side General Calibration Value 3 bit 5
ADC4CLP3L_CLP36:    .equ   6                                         ; Plus-Side General Calibration Value 3 bit 6
ADC4CLP3L_CLP37:    .equ   7                                         ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADC4CLP3L_CLP30:   .equ   %00000001
mADC4CLP3L_CLP31:   .equ   %00000010
mADC4CLP3L_CLP32:   .equ   %00000100
mADC4CLP3L_CLP33:   .equ   %00001000
mADC4CLP3L_CLP34:   .equ   %00010000
mADC4CLP3L_CLP35:   .equ   %00100000
mADC4CLP3L_CLP36:   .equ   %01000000
mADC4CLP3L_CLP37:   .equ   %10000000


;*** ADC4CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF84DA ***
ADC4CLP2:           .equ   $FFFF84DA                                ;*** ADC4CLP2 - Plus-Side General Calibration Value 2 Register; 0xFFFF84DA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP2_CLP20:     .equ   0                                         ; Plus-Side General Calibration Value 2 bit 0
ADC4CLP2_CLP21:     .equ   1                                         ; Plus-Side General Calibration Value 2 bit 1
ADC4CLP2_CLP22:     .equ   2                                         ; Plus-Side General Calibration Value 2 bit 2
ADC4CLP2_CLP23:     .equ   3                                         ; Plus-Side General Calibration Value 2 bit 3
ADC4CLP2_CLP24:     .equ   4                                         ; Plus-Side General Calibration Value 2 bit 4
ADC4CLP2_CLP25:     .equ   5                                         ; Plus-Side General Calibration Value 2 bit 5
ADC4CLP2_CLP26:     .equ   6                                         ; Plus-Side General Calibration Value 2 bit 6
ADC4CLP2_CLP27:     .equ   7                                         ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADC4CLP2_CLP20:    .equ   %00000001
mADC4CLP2_CLP21:    .equ   %00000010
mADC4CLP2_CLP22:    .equ   %00000100
mADC4CLP2_CLP23:    .equ   %00001000
mADC4CLP2_CLP24:    .equ   %00010000
mADC4CLP2_CLP25:    .equ   %00100000
mADC4CLP2_CLP26:    .equ   %01000000
mADC4CLP2_CLP27:    .equ   %10000000


;*** ADC4CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF84DB ***
ADC4CLP1:           .equ   $FFFF84DB                                ;*** ADC4CLP1 - Plus-Side General Calibration Value 1 Register; 0xFFFF84DB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP1_CLP10:     .equ   0                                         ; Plus-Side General Calibration Value 1 bit 0
ADC4CLP1_CLP11:     .equ   1                                         ; Plus-Side General Calibration Value 1 bit 1
ADC4CLP1_CLP12:     .equ   2                                         ; Plus-Side General Calibration Value 1 bit 2
ADC4CLP1_CLP13:     .equ   3                                         ; Plus-Side General Calibration Value 1 bit 3
ADC4CLP1_CLP14:     .equ   4                                         ; Plus-Side General Calibration Value 1 bit 4
ADC4CLP1_CLP15:     .equ   5                                         ; Plus-Side General Calibration Value 1 bit 5
ADC4CLP1_CLP16:     .equ   6                                         ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADC4CLP1_CLP10:    .equ   %00000001
mADC4CLP1_CLP11:    .equ   %00000010
mADC4CLP1_CLP12:    .equ   %00000100
mADC4CLP1_CLP13:    .equ   %00001000
mADC4CLP1_CLP14:    .equ   %00010000
mADC4CLP1_CLP15:    .equ   %00100000
mADC4CLP1_CLP16:    .equ   %01000000


;*** ADC4CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF84DC ***
ADC4CLP0:           .equ   $FFFF84DC                                ;*** ADC4CLP0 - Plus-Side General Calibration Value 0 Register; 0xFFFF84DC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLP0_CLP00:     .equ   0                                         ; Plus-Side General Calibration Value 0 bit 0
ADC4CLP0_CLP01:     .equ   1                                         ; Plus-Side General Calibration Value 0 bit 1
ADC4CLP0_CLP02:     .equ   2                                         ; Plus-Side General Calibration Value 0 bit 2
ADC4CLP0_CLP03:     .equ   3                                         ; Plus-Side General Calibration Value 0 bit 3
ADC4CLP0_CLP04:     .equ   4                                         ; Plus-Side General Calibration Value 0 bit 4
ADC4CLP0_CLP05:     .equ   5                                         ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADC4CLP0_CLP00:    .equ   %00000001
mADC4CLP0_CLP01:    .equ   %00000010
mADC4CLP0_CLP02:    .equ   %00000100
mADC4CLP0_CLP03:    .equ   %00001000
mADC4CLP0_CLP04:    .equ   %00010000
mADC4CLP0_CLP05:    .equ   %00100000


;*** ADC4CLMD - Minus-Side General Calibration Value D Register; 0xFFFF84DE ***
ADC4CLMD:           .equ   $FFFF84DE                                ;*** ADC4CLMD - Minus-Side General Calibration Value D Register; 0xFFFF84DE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLMD_CLMD0:     .equ   0                                         ; Minus-Side General Calibration Value D bit 0
ADC4CLMD_CLMD1:     .equ   1                                         ; Minus-Side General Calibration Value D bit 1
ADC4CLMD_CLMD2:     .equ   2                                         ; Minus-Side General Calibration Value D bit 2
ADC4CLMD_CLMD3:     .equ   3                                         ; Minus-Side General Calibration Value D bit 3
ADC4CLMD_CLMD4:     .equ   4                                         ; Minus-Side General Calibration Value D bit 4
ADC4CLMD_CLMD5:     .equ   5                                         ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADC4CLMD_CLMD0:    .equ   %00000001
mADC4CLMD_CLMD1:    .equ   %00000010
mADC4CLMD_CLMD2:    .equ   %00000100
mADC4CLMD_CLMD3:    .equ   %00001000
mADC4CLMD_CLMD4:    .equ   %00010000
mADC4CLMD_CLMD5:    .equ   %00100000


;*** ADC4CLMS - Minus-Side General Calibration Value S Register; 0xFFFF84DF ***
ADC4CLMS:           .equ   $FFFF84DF                                ;*** ADC4CLMS - Minus-Side General Calibration Value S Register; 0xFFFF84DF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLMS_CLMS0:     .equ   0                                         ; Minus-Side General Calibration Value S bit 0
ADC4CLMS_CLMS1:     .equ   1                                         ; Minus-Side General Calibration Value S bit 1
ADC4CLMS_CLMS2:     .equ   2                                         ; Minus-Side General Calibration Value S bit 2
ADC4CLMS_CLMS3:     .equ   3                                         ; Minus-Side General Calibration Value S bit 3
ADC4CLMS_CLMS4:     .equ   4                                         ; Minus-Side General Calibration Value S bit 4
ADC4CLMS_CLMS5:     .equ   5                                         ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADC4CLMS_CLMS0:    .equ   %00000001
mADC4CLMS_CLMS1:    .equ   %00000010
mADC4CLMS_CLMS2:    .equ   %00000100
mADC4CLMS_CLMS3:    .equ   %00001000
mADC4CLMS_CLMS4:    .equ   %00010000
mADC4CLMS_CLMS5:    .equ   %00100000


;*** ADC4CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF84E0 ***
ADC4CLM4:           .equ   $FFFF84E0                                ;*** ADC4CLM4 - Minus-Side General Calibration Value 4 Register; 0xFFFF84E0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM4_CLM40:     .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC4CLM4_CLM41:     .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC4CLM4_CLM42:     .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC4CLM4_CLM43:     .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC4CLM4_CLM44:     .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC4CLM4_CLM45:     .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC4CLM4_CLM46:     .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC4CLM4_CLM47:     .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
ADC4CLM4_CLM48:     .equ   8                                         ; Minus-Side General Calibration Value 4 bit 8
ADC4CLM4_CLM49:     .equ   9                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC4CLM4_CLM40:    .equ   %00000001
mADC4CLM4_CLM41:    .equ   %00000010
mADC4CLM4_CLM42:    .equ   %00000100
mADC4CLM4_CLM43:    .equ   %00001000
mADC4CLM4_CLM44:    .equ   %00010000
mADC4CLM4_CLM45:    .equ   %00100000
mADC4CLM4_CLM46:    .equ   %01000000
mADC4CLM4_CLM47:    .equ   %10000000
mADC4CLM4_CLM48:    .equ   %100000000
mADC4CLM4_CLM49:    .equ   %1000000000


;*** ADC4CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF84E0 ***
ADC4CLM4H:          .equ   $FFFF84E0                                ;*** ADC4CLM4H - Minus-Side General Calibration Value 4 High Register; 0xFFFF84E0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM4H_CLM48:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 8
ADC4CLM4H_CLM49:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC4CLM4H_CLM48:   .equ   %00000001
mADC4CLM4H_CLM49:   .equ   %00000010


;*** ADC4CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF84E1 ***
ADC4CLM4L:          .equ   $FFFF84E1                                ;*** ADC4CLM4L - Minus-Side General Calibration Value 4 Low Register; 0xFFFF84E1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM4L_CLM40:    .equ   0                                         ; Minus-Side General Calibration Value 4 bit 0
ADC4CLM4L_CLM41:    .equ   1                                         ; Minus-Side General Calibration Value 4 bit 1
ADC4CLM4L_CLM42:    .equ   2                                         ; Minus-Side General Calibration Value 4 bit 2
ADC4CLM4L_CLM43:    .equ   3                                         ; Minus-Side General Calibration Value 4 bit 3
ADC4CLM4L_CLM44:    .equ   4                                         ; Minus-Side General Calibration Value 4 bit 4
ADC4CLM4L_CLM45:    .equ   5                                         ; Minus-Side General Calibration Value 4 bit 5
ADC4CLM4L_CLM46:    .equ   6                                         ; Minus-Side General Calibration Value 4 bit 6
ADC4CLM4L_CLM47:    .equ   7                                         ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADC4CLM4L_CLM40:   .equ   %00000001
mADC4CLM4L_CLM41:   .equ   %00000010
mADC4CLM4L_CLM42:   .equ   %00000100
mADC4CLM4L_CLM43:   .equ   %00001000
mADC4CLM4L_CLM44:   .equ   %00010000
mADC4CLM4L_CLM45:   .equ   %00100000
mADC4CLM4L_CLM46:   .equ   %01000000
mADC4CLM4L_CLM47:   .equ   %10000000


;*** ADC4CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF84E2 ***
ADC4CLM3:           .equ   $FFFF84E2                                ;*** ADC4CLM3 - Minus-Side General Calibration Value 3 Register; 0xFFFF84E2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM3_CLM30:     .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC4CLM3_CLM31:     .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC4CLM3_CLM32:     .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC4CLM3_CLM33:     .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC4CLM3_CLM34:     .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC4CLM3_CLM35:     .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC4CLM3_CLM36:     .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC4CLM3_CLM37:     .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
ADC4CLM3_CLM38:     .equ   8                                         ; Minus-Side General Calibration Value 3 bit 8
; bit position masks
mADC4CLM3_CLM30:    .equ   %00000001
mADC4CLM3_CLM31:    .equ   %00000010
mADC4CLM3_CLM32:    .equ   %00000100
mADC4CLM3_CLM33:    .equ   %00001000
mADC4CLM3_CLM34:    .equ   %00010000
mADC4CLM3_CLM35:    .equ   %00100000
mADC4CLM3_CLM36:    .equ   %01000000
mADC4CLM3_CLM37:    .equ   %10000000
mADC4CLM3_CLM38:    .equ   %100000000


;*** ADC4CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF84E2 ***
ADC4CLM3H:          .equ   $FFFF84E2                                ;*** ADC4CLM3H - Minus-Side General Calibration Value 3 High Register; 0xFFFF84E2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM3H_CLM38:    .equ   0                                         ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADC4CLM3H_CLM38:   .equ   %00000001


;*** ADC4CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF84E3 ***
ADC4CLM3L:          .equ   $FFFF84E3                                ;*** ADC4CLM3L - Minus-Side General Calibration Value 3 Low Register; 0xFFFF84E3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM3L_CLM30:    .equ   0                                         ; Minus-Side General Calibration Value 3 bit 0
ADC4CLM3L_CLM31:    .equ   1                                         ; Minus-Side General Calibration Value 3 bit 1
ADC4CLM3L_CLM32:    .equ   2                                         ; Minus-Side General Calibration Value 3 bit 2
ADC4CLM3L_CLM33:    .equ   3                                         ; Minus-Side General Calibration Value 3 bit 3
ADC4CLM3L_CLM34:    .equ   4                                         ; Minus-Side General Calibration Value 3 bit 4
ADC4CLM3L_CLM35:    .equ   5                                         ; Minus-Side General Calibration Value 3 bit 5
ADC4CLM3L_CLM36:    .equ   6                                         ; Minus-Side General Calibration Value 3 bit 6
ADC4CLM3L_CLM37:    .equ   7                                         ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADC4CLM3L_CLM30:   .equ   %00000001
mADC4CLM3L_CLM31:   .equ   %00000010
mADC4CLM3L_CLM32:   .equ   %00000100
mADC4CLM3L_CLM33:   .equ   %00001000
mADC4CLM3L_CLM34:   .equ   %00010000
mADC4CLM3L_CLM35:   .equ   %00100000
mADC4CLM3L_CLM36:   .equ   %01000000
mADC4CLM3L_CLM37:   .equ   %10000000


;*** ADC4CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF84E4 ***
ADC4CLM2:           .equ   $FFFF84E4                                ;*** ADC4CLM2 - Minus-Side General Calibration Value 2 Register; 0xFFFF84E4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM2_CLM20:     .equ   0                                         ; Minus-Side General Calibration Value 2 bit 0
ADC4CLM2_CLM21:     .equ   1                                         ; Minus-Side General Calibration Value 2 bit 1
ADC4CLM2_CLM22:     .equ   2                                         ; Minus-Side General Calibration Value 2 bit 2
ADC4CLM2_CLM23:     .equ   3                                         ; Minus-Side General Calibration Value 2 bit 3
ADC4CLM2_CLM24:     .equ   4                                         ; Minus-Side General Calibration Value 2 bit 4
ADC4CLM2_CLM25:     .equ   5                                         ; Minus-Side General Calibration Value 2 bit 5
ADC4CLM2_CLM26:     .equ   6                                         ; Minus-Side General Calibration Value 2 bit 6
ADC4CLM2_CLM27:     .equ   7                                         ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADC4CLM2_CLM20:    .equ   %00000001
mADC4CLM2_CLM21:    .equ   %00000010
mADC4CLM2_CLM22:    .equ   %00000100
mADC4CLM2_CLM23:    .equ   %00001000
mADC4CLM2_CLM24:    .equ   %00010000
mADC4CLM2_CLM25:    .equ   %00100000
mADC4CLM2_CLM26:    .equ   %01000000
mADC4CLM2_CLM27:    .equ   %10000000


;*** ADC4CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF84E5 ***
ADC4CLM1:           .equ   $FFFF84E5                                ;*** ADC4CLM1 - Minus-Side General Calibration Value 1 Register; 0xFFFF84E5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM1_CLM10:     .equ   0                                         ; Minus-Side General Calibration Value 1 bit 0
ADC4CLM1_CLM11:     .equ   1                                         ; Minus-Side General Calibration Value 1 bit 1
ADC4CLM1_CLM12:     .equ   2                                         ; Minus-Side General Calibration Value 1 bit 2
ADC4CLM1_CLM13:     .equ   3                                         ; Minus-Side General Calibration Value 1 bit 3
ADC4CLM1_CLM14:     .equ   4                                         ; Minus-Side General Calibration Value 1 bit 4
ADC4CLM1_CLM15:     .equ   5                                         ; Minus-Side General Calibration Value 1 bit 5
ADC4CLM1_CLM16:     .equ   6                                         ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADC4CLM1_CLM10:    .equ   %00000001
mADC4CLM1_CLM11:    .equ   %00000010
mADC4CLM1_CLM12:    .equ   %00000100
mADC4CLM1_CLM13:    .equ   %00001000
mADC4CLM1_CLM14:    .equ   %00010000
mADC4CLM1_CLM15:    .equ   %00100000
mADC4CLM1_CLM16:    .equ   %01000000


;*** ADC4CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF84E6 ***
ADC4CLM0:           .equ   $FFFF84E6                                ;*** ADC4CLM0 - Minus-Side General Calibration Value 0 Register; 0xFFFF84E6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC4CLM0_CLM00:     .equ   0                                         ; Minus-Side General Calibration Value 0 bit 0
ADC4CLM0_CLM01:     .equ   1                                         ; Minus-Side General Calibration Value 0 bit 1
ADC4CLM0_CLM02:     .equ   2                                         ; Minus-Side General Calibration Value 0 bit 2
ADC4CLM0_CLM03:     .equ   3                                         ; Minus-Side General Calibration Value 0 bit 3
ADC4CLM0_CLM04:     .equ   4                                         ; Minus-Side General Calibration Value 0 bit 4
ADC4CLM0_CLM05:     .equ   5                                         ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADC4CLM0_CLM00:    .equ   %00000001
mADC4CLM0_CLM01:    .equ   %00000010
mADC4CLM0_CLM02:    .equ   %00000100
mADC4CLM0_CLM03:    .equ   %00001000
mADC4CLM0_CLM04:    .equ   %00010000
mADC4CLM0_CLM05:    .equ   %00100000


;*** PRACMP1CS - PRACMP1 Control and Status Register; 0xFFFF8520 ***
PRACMP1CS:          .equ   $FFFF8520                                ;*** PRACMP1CS - PRACMP1 Control and Status Register; 0xFFFF8520 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1CS_ACIEN:    .equ   0                                         ; ACMP Interrupt Enable
PRACMP1CS_ACINTS0:  .equ   1                                         ; ACMP Interrupt Select, bit 0
PRACMP1CS_ACINTS1:  .equ   2                                         ; ACMP Interrupt Select, bit 1
PRACMP1CS_ACMPO:    .equ   3                                         ; ACMP Output Bit
PRACMP1CS_ACOPE:    .equ   4                                         ; ACMP Output Pin Enable
PRACMP1CS_ACMPF:    .equ   6                                         ; ACMP Interrupt Flag
PRACMP1CS_ACEN:     .equ   7                                         ; ACMP Module Enable
; bit position masks
mPRACMP1CS_ACIEN:   .equ   %00000001
mPRACMP1CS_ACINTS0: .equ   %00000010
mPRACMP1CS_ACINTS1: .equ   %00000100
mPRACMP1CS_ACMPO:   .equ   %00001000
mPRACMP1CS_ACOPE:   .equ   %00010000
mPRACMP1CS_ACMPF:   .equ   %01000000
mPRACMP1CS_ACEN:    .equ   %10000000


;*** PRACMP1C0 - PRACMP1 Control 0 Register; 0xFFFF8521 ***
PRACMP1C0:          .equ   $FFFF8521                                ;*** PRACMP1C0 - PRACMP1 Control 0 Register; 0xFFFF8521 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1C0_ACNSEL0:  .equ   0                                         ; ACMP Negative Input Select, bit 0
PRACMP1C0_ACNSEL1:  .equ   1                                         ; ACMP Negative Input Select, bit 1
PRACMP1C0_ACNSEL2:  .equ   2                                         ; ACMP Negative Input Select, bit 2
PRACMP1C0_ACPSEL0:  .equ   4                                         ; ACMP Positive Input Select, bit 0
PRACMP1C0_ACPSEL1:  .equ   5                                         ; ACMP Positive Input Select, bit 1
PRACMP1C0_ACPSEL2:  .equ   6                                         ; ACMP Positive Input Select, bit 2
; bit position masks
mPRACMP1C0_ACNSEL0: .equ   %00000001
mPRACMP1C0_ACNSEL1: .equ   %00000010
mPRACMP1C0_ACNSEL2: .equ   %00000100
mPRACMP1C0_ACPSEL0: .equ   %00010000
mPRACMP1C0_ACPSEL1: .equ   %00100000
mPRACMP1C0_ACPSEL2: .equ   %01000000


;*** PRACMP1C1 - PRACMP1 Control 1 Register; 0xFFFF8522 ***
PRACMP1C1:          .equ   $FFFF8522                                ;*** PRACMP1C1 - PRACMP1 Control 1 Register; 0xFFFF8522 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1C1_PRGOS0:   .equ   0                                         ; Programmable Reference Generator Output Selection, bit 0
PRACMP1C1_PRGOS1:   .equ   1                                         ; Programmable Reference Generator Output Selection, bit 1
PRACMP1C1_PRGOS2:   .equ   2                                         ; Programmable Reference Generator Output Selection, bit 2
PRACMP1C1_PRGOS3:   .equ   3                                         ; Programmable Reference Generator Output Selection, bit 3
PRACMP1C1_PRGOS4:   .equ   4                                         ; Programmable Reference Generator Output Selection, bit 4
PRACMP1C1_PRGINS:   .equ   6                                         ; Programmable Reference Generator Input Selection
PRACMP1C1_PRGEN:    .equ   7                                         ; Programmable Reference Generator Enable
; bit position masks
mPRACMP1C1_PRGOS0:  .equ   %00000001
mPRACMP1C1_PRGOS1:  .equ   %00000010
mPRACMP1C1_PRGOS2:  .equ   %00000100
mPRACMP1C1_PRGOS3:  .equ   %00001000
mPRACMP1C1_PRGOS4:  .equ   %00010000
mPRACMP1C1_PRGINS:  .equ   %01000000
mPRACMP1C1_PRGEN:   .equ   %10000000


;*** PRACMP1C2 - PRACMP1 Control 2 Register; 0xFFFF8523 ***
PRACMP1C2:          .equ   $FFFF8523                                ;*** PRACMP1C2 - PRACMP1 Control 2 Register; 0xFFFF8523 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1C2_ACIPE0:   .equ   0                                         ; ACMP Input Pin 0 Enable - ACIPE0 is used to control the PRACMP external pin 0 as analog input
PRACMP1C2_ACIPE1:   .equ   1                                         ; ACMP Input Pin 1 Enable - ACIPE1 is used to control the PRACMP external pin 1 as analog input
PRACMP1C2_ACIPE2:   .equ   2                                         ; ACMP Input Pin 2 Enable - ACIPE2 is used to control the PRACMP external pin 2 as analog input
PRACMP1C2_ACIPE3:   .equ   3                                         ; ACMP Input Pin 3 Enable - ACIPE3 is used to control the PRACMP external pin 3 as analog input
PRACMP1C2_ACIPE4:   .equ   4                                         ; ACMP Input Pin 4 Enable - ACIPE4 is used to control the PRACMP external pin 4 as analog input
PRACMP1C2_ACIPE5:   .equ   5                                         ; ACMP Input Pin 5 Enable - ACIPE5 is used to control the PRACMP external pin 5 as analog input
PRACMP1C2_ACIPE6:   .equ   6                                         ; ACMP Input Pin 6 Enable - ACIPE6 is used to control the PRACMP external pin 6 as analog input
; bit position masks
mPRACMP1C2_ACIPE0:  .equ   %00000001
mPRACMP1C2_ACIPE1:  .equ   %00000010
mPRACMP1C2_ACIPE2:  .equ   %00000100
mPRACMP1C2_ACIPE3:  .equ   %00001000
mPRACMP1C2_ACIPE4:  .equ   %00010000
mPRACMP1C2_ACIPE5:  .equ   %00100000
mPRACMP1C2_ACIPE6:  .equ   %01000000


;*** PRACMP2CS - PRACMP2 Control and Status Register; 0xFFFF8540 ***
PRACMP2CS:          .equ   $FFFF8540                                ;*** PRACMP2CS - PRACMP2 Control and Status Register; 0xFFFF8540 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2CS_ACIEN:    .equ   0                                         ; ACMP Interrupt Enable
PRACMP2CS_ACINTS0:  .equ   1                                         ; ACMP Interrupt Select, bit 0
PRACMP2CS_ACINTS1:  .equ   2                                         ; ACMP Interrupt Select, bit 1
PRACMP2CS_ACMPO:    .equ   3                                         ; ACMP Output Bit
PRACMP2CS_ACOPE:    .equ   4                                         ; ACMP Output Pin Enable
PRACMP2CS_ACMPF:    .equ   6                                         ; ACMP Interrupt Flag
PRACMP2CS_ACEN:     .equ   7                                         ; ACMP Module Enable
; bit position masks
mPRACMP2CS_ACIEN:   .equ   %00000001
mPRACMP2CS_ACINTS0: .equ   %00000010
mPRACMP2CS_ACINTS1: .equ   %00000100
mPRACMP2CS_ACMPO:   .equ   %00001000
mPRACMP2CS_ACOPE:   .equ   %00010000
mPRACMP2CS_ACMPF:   .equ   %01000000
mPRACMP2CS_ACEN:    .equ   %10000000


;*** PRACMP2C0 - PRACMP2 Control 0 Register; 0xFFFF8541 ***
PRACMP2C0:          .equ   $FFFF8541                                ;*** PRACMP2C0 - PRACMP2 Control 0 Register; 0xFFFF8541 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2C0_ACNSEL0:  .equ   0                                         ; ACMP Negative Input Select, bit 0
PRACMP2C0_ACNSEL1:  .equ   1                                         ; ACMP Negative Input Select, bit 1
PRACMP2C0_ACNSEL2:  .equ   2                                         ; ACMP Negative Input Select, bit 2
PRACMP2C0_ACPSEL0:  .equ   4                                         ; ACMP Positive Input Select, bit 0
PRACMP2C0_ACPSEL1:  .equ   5                                         ; ACMP Positive Input Select, bit 1
PRACMP2C0_ACPSEL2:  .equ   6                                         ; ACMP Positive Input Select, bit 2
; bit position masks
mPRACMP2C0_ACNSEL0: .equ   %00000001
mPRACMP2C0_ACNSEL1: .equ   %00000010
mPRACMP2C0_ACNSEL2: .equ   %00000100
mPRACMP2C0_ACPSEL0: .equ   %00010000
mPRACMP2C0_ACPSEL1: .equ   %00100000
mPRACMP2C0_ACPSEL2: .equ   %01000000


;*** PRACMP2C1 - PRACMP2 Control 1 Register; 0xFFFF8542 ***
PRACMP2C1:          .equ   $FFFF8542                                ;*** PRACMP2C1 - PRACMP2 Control 1 Register; 0xFFFF8542 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2C1_PRGOS0:   .equ   0                                         ; Programmable Reference Generator Output Selection, bit 0
PRACMP2C1_PRGOS1:   .equ   1                                         ; Programmable Reference Generator Output Selection, bit 1
PRACMP2C1_PRGOS2:   .equ   2                                         ; Programmable Reference Generator Output Selection, bit 2
PRACMP2C1_PRGOS3:   .equ   3                                         ; Programmable Reference Generator Output Selection, bit 3
PRACMP2C1_PRGOS4:   .equ   4                                         ; Programmable Reference Generator Output Selection, bit 4
PRACMP2C1_PRGINS:   .equ   6                                         ; Programmable Reference Generator Input Selection
PRACMP2C1_PRGEN:    .equ   7                                         ; Programmable Reference Generator Enable
; bit position masks
mPRACMP2C1_PRGOS0:  .equ   %00000001
mPRACMP2C1_PRGOS1:  .equ   %00000010
mPRACMP2C1_PRGOS2:  .equ   %00000100
mPRACMP2C1_PRGOS3:  .equ   %00001000
mPRACMP2C1_PRGOS4:  .equ   %00010000
mPRACMP2C1_PRGINS:  .equ   %01000000
mPRACMP2C1_PRGEN:   .equ   %10000000


;*** PRACMP2C2 - PRACMP2 Control 2 Register; 0xFFFF8543 ***
PRACMP2C2:          .equ   $FFFF8543                                ;*** PRACMP2C2 - PRACMP2 Control 2 Register; 0xFFFF8543 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2C2_ACIPE0:   .equ   0                                         ; ACMP Input Pin 0 Enable - ACIPE0 is used to control the PRACMP external pin 0 as analog input
PRACMP2C2_ACIPE1:   .equ   1                                         ; ACMP Input Pin 1 Enable - ACIPE1 is used to control the PRACMP external pin 1 as analog input
PRACMP2C2_ACIPE2:   .equ   2                                         ; ACMP Input Pin 2 Enable - ACIPE2 is used to control the PRACMP external pin 2 as analog input
PRACMP2C2_ACIPE3:   .equ   3                                         ; ACMP Input Pin 3 Enable - ACIPE3 is used to control the PRACMP external pin 3 as analog input
PRACMP2C2_ACIPE4:   .equ   4                                         ; ACMP Input Pin 4 Enable - ACIPE4 is used to control the PRACMP external pin 4 as analog input
PRACMP2C2_ACIPE5:   .equ   5                                         ; ACMP Input Pin 5 Enable - ACIPE5 is used to control the PRACMP external pin 5 as analog input
PRACMP2C2_ACIPE6:   .equ   6                                         ; ACMP Input Pin 6 Enable - ACIPE6 is used to control the PRACMP external pin 6 as analog input
; bit position masks
mPRACMP2C2_ACIPE0:  .equ   %00000001
mPRACMP2C2_ACIPE1:  .equ   %00000010
mPRACMP2C2_ACIPE2:  .equ   %00000100
mPRACMP2C2_ACIPE3:  .equ   %00001000
mPRACMP2C2_ACIPE4:  .equ   %00010000
mPRACMP2C2_ACIPE5:  .equ   %00100000
mPRACMP2C2_ACIPE6:  .equ   %01000000


;*** MTIM1SC - MTIM Clock Configuration Register; 0xFFFF8560 ***
MTIM1SC:            .equ   $FFFF8560                                ;*** MTIM1SC - MTIM Clock Configuration Register; 0xFFFF8560 ***
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


;*** MTIM1CLK - MTIM Clock Configuration Register; 0xFFFF8561 ***
MTIM1CLK:           .equ   $FFFF8561                                ;*** MTIM1CLK - MTIM Clock Configuration Register; 0xFFFF8561 ***
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


;*** MTIM1CNT - MTIM Counter Register; 0xFFFF8562 ***
MTIM1CNT:           .equ   $FFFF8562                                ;*** MTIM1CNT - MTIM Counter Register; 0xFFFF8562 ***


;*** MTIM1MOD - MTIM Modulo Register; 0xFFFF8563 ***
MTIM1MOD:           .equ   $FFFF8563                                ;*** MTIM1MOD - MTIM Modulo Register; 0xFFFF8563 ***


;*** MTIM2SC - MTIM Clock Configuration Register; 0xFFFF8580 ***
MTIM2SC:            .equ   $FFFF8580                                ;*** MTIM2SC - MTIM Clock Configuration Register; 0xFFFF8580 ***
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


;*** MTIM2CLK - MTIM Clock Configuration Register; 0xFFFF8581 ***
MTIM2CLK:           .equ   $FFFF8581                                ;*** MTIM2CLK - MTIM Clock Configuration Register; 0xFFFF8581 ***
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


;*** MTIM2CNT - MTIM Counter Register; 0xFFFF8582 ***
MTIM2CNT:           .equ   $FFFF8582                                ;*** MTIM2CNT - MTIM Counter Register; 0xFFFF8582 ***


;*** MTIM2MOD - MTIM Modulo Register; 0xFFFF8583 ***
MTIM2MOD:           .equ   $FFFF8583                                ;*** MTIM2MOD - MTIM Modulo Register; 0xFFFF8583 ***


;*** MTIM3SC - MTIM16 Status and Control Register; 0xFFFF85A0 ***
MTIM3SC:            .equ   $FFFF85A0                                ;*** MTIM3SC - MTIM16 Status and Control Register; 0xFFFF85A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM3SC_TSTP:       .equ   4                                         ; MTIM16 Counter Stop
MTIM3SC_TRST:       .equ   5                                         ; MTIM16 Counter Reset
MTIM3SC_TOIE:       .equ   6                                         ; MTIM16 Overflow Interrupt Enable
MTIM3SC_TOF:        .equ   7                                         ; MTIM16 Overflow Flag
; bit position masks
mMTIM3SC_TSTP:      .equ   %00010000
mMTIM3SC_TRST:      .equ   %00100000
mMTIM3SC_TOIE:      .equ   %01000000
mMTIM3SC_TOF:       .equ   %10000000


;*** MTIM3CLK - MTIM16 Clock Configuration Register; 0xFFFF85A1 ***
MTIM3CLK:           .equ   $FFFF85A1                                ;*** MTIM3CLK - MTIM16 Clock Configuration Register; 0xFFFF85A1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM3CLK_PS0:       .equ   0                                         ; Clock source Prescaler Bit 0
MTIM3CLK_PS1:       .equ   1                                         ; Clock source Prescaler Bit 1
MTIM3CLK_PS2:       .equ   2                                         ; Clock source Prescaler Bit 2
MTIM3CLK_PS3:       .equ   3                                         ; Clock source Prescaler Bit 3
MTIM3CLK_CLKS0:     .equ   4                                         ; Clock source Select Bit 0
MTIM3CLK_CLKS1:     .equ   5                                         ; Clock source Select Bit 1
; bit position masks
mMTIM3CLK_PS0:      .equ   %00000001
mMTIM3CLK_PS1:      .equ   %00000010
mMTIM3CLK_PS2:      .equ   %00000100
mMTIM3CLK_PS3:      .equ   %00001000
mMTIM3CLK_CLKS0:    .equ   %00010000
mMTIM3CLK_CLKS1:    .equ   %00100000


;*** MTIM3CNT - MTIM16 Counter Register; 0xFFFF85A2 ***
MTIM3CNT:           .equ   $FFFF85A2                                ;*** MTIM3CNT - MTIM16 Counter Register; 0xFFFF85A2 ***


;*** MTIM3CNTH - MTIM16 Counter Register High; 0xFFFF85A2 ***
MTIM3CNTH:          .equ   $FFFF85A2                                ;*** MTIM3CNTH - MTIM16 Counter Register High; 0xFFFF85A2 ***


;*** MTIM3CNTL - MTIM16 Counter Register Low; 0xFFFF85A3 ***
MTIM3CNTL:          .equ   $FFFF85A3                                ;*** MTIM3CNTL - MTIM16 Counter Register Low; 0xFFFF85A3 ***


;*** MTIM3MOD - MTIM16 Modulo Register; 0xFFFF85A4 ***
MTIM3MOD:           .equ   $FFFF85A4                                ;*** MTIM3MOD - MTIM16 Modulo Register; 0xFFFF85A4 ***


;*** MTIM3MODH - MTIM16 Modulo Register High; 0xFFFF85A4 ***
MTIM3MODH:          .equ   $FFFF85A4                                ;*** MTIM3MODH - MTIM16 Modulo Register High; 0xFFFF85A4 ***


;*** MTIM3MODL - MTIM16 Modulo Register Low; 0xFFFF85A5 ***
MTIM3MODL:          .equ   $FFFF85A5                                ;*** MTIM3MODL - MTIM16 Modulo Register Low; 0xFFFF85A5 ***


;*** CRCH - CRC High Register; 0xFFFF85C0 ***
CRCH:               .equ   $FFFF85C0                                ;*** CRCH - CRC High Register; 0xFFFF85C0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRCH_BIT8:          .equ   0                                         ; High byte of CRC register ,bit 8
CRCH_BIT9:          .equ   1                                         ; High byte of CRC register ,bit 9
CRCH_BIT10:         .equ   2                                         ; High byte of CRC register ,bit 10
CRCH_BIT11:         .equ   3                                         ; High byte of CRC register ,bit 11
CRCH_BIT12:         .equ   4                                         ; High byte of CRC register ,bit 12
CRCH_BIT13:         .equ   5                                         ; High byte of CRC register ,bit 13
CRCH_BIT14:         .equ   6                                         ; High byte of CRC register ,bit 14
CRCH_BIT15:         .equ   7                                         ; High byte of CRC register ,bit 15
; bit position masks
mCRCH_BIT8:         .equ   %00000001
mCRCH_BIT9:         .equ   %00000010
mCRCH_BIT10:        .equ   %00000100
mCRCH_BIT11:        .equ   %00001000
mCRCH_BIT12:        .equ   %00010000
mCRCH_BIT13:        .equ   %00100000
mCRCH_BIT14:        .equ   %01000000
mCRCH_BIT15:        .equ   %10000000


;*** CRCL - CRC Low Register; 0xFFFF85C1 ***
CRCL:               .equ   $FFFF85C1                                ;*** CRCL - CRC Low Register; 0xFFFF85C1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRCL_BIT0:          .equ   0                                         ; Low byte of CRC register, bit 0
CRCL_BIT1:          .equ   1                                         ; Low byte of CRC register, bit 1
CRCL_BIT2:          .equ   2                                         ; Low byte of CRC register, bit 2
CRCL_BIT3:          .equ   3                                         ; Low byte of CRC register, bit 3
CRCL_BIT4:          .equ   4                                         ; Low byte of CRC register, bit 4
CRCL_BIT5:          .equ   5                                         ; Low byte of CRC register, bit 5
CRCL_BIT6:          .equ   6                                         ; Low byte of CRC register, bit 6
CRCL_BIT7:          .equ   7                                         ; Low byte of CRC register, bit 7
; bit position masks
mCRCL_BIT0:         .equ   %00000001
mCRCL_BIT1:         .equ   %00000010
mCRCL_BIT2:         .equ   %00000100
mCRCL_BIT3:         .equ   %00001000
mCRCL_BIT4:         .equ   %00010000
mCRCL_BIT5:         .equ   %00100000
mCRCL_BIT6:         .equ   %01000000
mCRCL_BIT7:         .equ   %10000000


;*** TRANSPOSE - CRC Transpose Register; 0xFFFF85C2 ***
TRANSPOSE:          .equ   $FFFF85C2                                ;*** TRANSPOSE - CRC Transpose Register; 0xFFFF85C2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TRANSPOSE_BIT0:     .equ   0                                         ; CRC transpose register, bit 0
TRANSPOSE_BIT1:     .equ   1                                         ; CRC transpose register, bit 1
TRANSPOSE_BIT2:     .equ   2                                         ; CRC transpose register, bit 2
TRANSPOSE_BIT3:     .equ   3                                         ; CRC transpose register, bit 3
TRANSPOSE_BIT4:     .equ   4                                         ; CRC transpose register, bit 4
TRANSPOSE_BIT5:     .equ   5                                         ; CRC transpose register, bit 5
TRANSPOSE_BIT6:     .equ   6                                         ; CRC transpose register, bit 6
TRANSPOSE_BIT7:     .equ   7                                         ; CRC transpose register, bit 7
; bit position masks
mTRANSPOSE_BIT0:    .equ   %00000001
mTRANSPOSE_BIT1:    .equ   %00000010
mTRANSPOSE_BIT2:    .equ   %00000100
mTRANSPOSE_BIT3:    .equ   %00001000
mTRANSPOSE_BIT4:    .equ   %00010000
mTRANSPOSE_BIT5:    .equ   %00100000
mTRANSPOSE_BIT6:    .equ   %01000000
mTRANSPOSE_BIT7:    .equ   %10000000


;*** TPMSC - TPM Status and Control Register; 0xFFFF8600 ***
TPMSC:              .equ   $FFFF8600                                ;*** TPMSC - TPM Status and Control Register; 0xFFFF8600 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMSC_PS0:          .equ   0                                         ; Prescale Divisor Select Bit 0
TPMSC_PS1:          .equ   1                                         ; Prescale Divisor Select Bit 1
TPMSC_PS2:          .equ   2                                         ; Prescale Divisor Select Bit 2
TPMSC_CLKSA:        .equ   3                                         ; Clock Source Select A
TPMSC_CLKSB:        .equ   4                                         ; Clock Source Select B
TPMSC_CPWMS:        .equ   5                                         ; Center-Aligned PWM Select
TPMSC_TOIE:         .equ   6                                         ; Timer Overflow Interrupt Enable
TPMSC_TOF:          .equ   7                                         ; Timer Overflow Flag
; bit position masks
mTPMSC_PS0:         .equ   %00000001
mTPMSC_PS1:         .equ   %00000010
mTPMSC_PS2:         .equ   %00000100
mTPMSC_CLKSA:       .equ   %00001000
mTPMSC_CLKSB:       .equ   %00010000
mTPMSC_CPWMS:       .equ   %00100000
mTPMSC_TOIE:        .equ   %01000000
mTPMSC_TOF:         .equ   %10000000


;*** TPMCNT - TPM Timer Counter Register; 0xFFFF8601 ***
TPMCNT:             .equ   $FFFF8601                                ;*** TPMCNT - TPM Timer Counter Register; 0xFFFF8601 ***


;*** TPMCNTH - TPM Timer Counter Register High; 0xFFFF8601 ***
TPMCNTH:            .equ   $FFFF8601                                ;*** TPMCNTH - TPM Timer Counter Register High; 0xFFFF8601 ***


;*** TPMCNTL - TPM Timer Counter Register Low; 0xFFFF8602 ***
TPMCNTL:            .equ   $FFFF8602                                ;*** TPMCNTL - TPM Timer Counter Register Low; 0xFFFF8602 ***


;*** TPMMOD - TPM Timer Counter Modulo Register; 0xFFFF8603 ***
TPMMOD:             .equ   $FFFF8603                                ;*** TPMMOD - TPM Timer Counter Modulo Register; 0xFFFF8603 ***


;*** TPMMODH - TPM Timer Counter Modulo Register High; 0xFFFF8603 ***
TPMMODH:            .equ   $FFFF8603                                ;*** TPMMODH - TPM Timer Counter Modulo Register High; 0xFFFF8603 ***


;*** TPMMODL - TPM Timer Counter Modulo Register Low; 0xFFFF8604 ***
TPMMODL:            .equ   $FFFF8604                                ;*** TPMMODL - TPM Timer Counter Modulo Register Low; 0xFFFF8604 ***


;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register; 0xFFFF8605 ***
TPMC0SC:            .equ   $FFFF8605                                ;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register; 0xFFFF8605 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMC0SC_ELS0A:      .equ   2                                         ; Edge/Level Select Bit A
TPMC0SC_ELS0B:      .equ   3                                         ; Edge/Level Select Bit B
TPMC0SC_MS0A:       .equ   4                                         ; Mode Select A for TPM Channel 0
TPMC0SC_MS0B:       .equ   5                                         ; Mode Select B for TPM Channel 0
TPMC0SC_CH0IE:      .equ   6                                         ; Channel 0 Interrupt Enable
TPMC0SC_CH0F:       .equ   7                                         ; Channel 0 Flag
; bit position masks
mTPMC0SC_ELS0A:     .equ   %00000100
mTPMC0SC_ELS0B:     .equ   %00001000
mTPMC0SC_MS0A:      .equ   %00010000
mTPMC0SC_MS0B:      .equ   %00100000
mTPMC0SC_CH0IE:     .equ   %01000000
mTPMC0SC_CH0F:      .equ   %10000000


;*** TPMC0V - TPM Timer Channel 0 Value Register; 0xFFFF8606 ***
TPMC0V:             .equ   $FFFF8606                                ;*** TPMC0V - TPM Timer Channel 0 Value Register; 0xFFFF8606 ***


;*** TPMC0VH - TPM Timer Channel 0 Value Register High; 0xFFFF8606 ***
TPMC0VH:            .equ   $FFFF8606                                ;*** TPMC0VH - TPM Timer Channel 0 Value Register High; 0xFFFF8606 ***


;*** TPMC0VL - TPM Timer Channel 0 Value Register Low; 0xFFFF8607 ***
TPMC0VL:            .equ   $FFFF8607                                ;*** TPMC0VL - TPM Timer Channel 0 Value Register Low; 0xFFFF8607 ***


;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register; 0xFFFF8608 ***
TPMC1SC:            .equ   $FFFF8608                                ;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register; 0xFFFF8608 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMC1SC_ELS1A:      .equ   2                                         ; Edge/Level Select Bit A
TPMC1SC_ELS1B:      .equ   3                                         ; Edge/Level Select Bit B
TPMC1SC_MS1A:       .equ   4                                         ; Mode Select A for TPM Channel 1
TPMC1SC_MS1B:       .equ   5                                         ; Mode Select B for TPM Channel 1
TPMC1SC_CH1IE:      .equ   6                                         ; Channel 1 Interrupt Enable
TPMC1SC_CH1F:       .equ   7                                         ; Channel 1 Flag
; bit position masks
mTPMC1SC_ELS1A:     .equ   %00000100
mTPMC1SC_ELS1B:     .equ   %00001000
mTPMC1SC_MS1A:      .equ   %00010000
mTPMC1SC_MS1B:      .equ   %00100000
mTPMC1SC_CH1IE:     .equ   %01000000
mTPMC1SC_CH1F:      .equ   %10000000


;*** TPMC1V - TPM Timer Channel 1 Value Register; 0xFFFF8609 ***
TPMC1V:             .equ   $FFFF8609                                ;*** TPMC1V - TPM Timer Channel 1 Value Register; 0xFFFF8609 ***


;*** TPMC1VH - TPM Timer Channel 1 Value Register High; 0xFFFF8609 ***
TPMC1VH:            .equ   $FFFF8609                                ;*** TPMC1VH - TPM Timer Channel 1 Value Register High; 0xFFFF8609 ***


;*** TPMC1VL - TPM Timer Channel 1 Value Register Low; 0xFFFF860A ***
TPMC1VL:            .equ   $FFFF860A                                ;*** TPMC1VL - TPM Timer Channel 1 Value Register Low; 0xFFFF860A ***


;*** IRTC_YEARMON_bcd - RTC Year and Month Counters Register (BCD format); 0xFFFF8640 ***
IRTC_YEARMON_bcd:   .equ   $FFFF8640                                ;*** IRTC_YEARMON_bcd - RTC Year and Month Counters Register (BCD format); 0xFFFF8640 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_YEARMON_bcd_MONTH_units0: .equ   0                              ; Month count value units bits, bit 0
IRTC_YEARMON_bcd_MONTH_units1: .equ   1                              ; Month count value units bits, bit 1
IRTC_YEARMON_bcd_MONTH_units2: .equ   2                              ; Month count value units bits, bit 2
IRTC_YEARMON_bcd_MONTH_units3: .equ   3                              ; Month count value units bits, bit 3
IRTC_YEARMON_bcd_MONTH_tens0: .equ   4                               ; Month count value tens bits, bit 0
IRTC_YEARMON_bcd_MONTH_tens1: .equ   5                               ; Month count value tens bits, bit 1
IRTC_YEARMON_bcd_MONTH_tens2: .equ   6                               ; Month count value tens bits, bit 2
IRTC_YEARMON_bcd_MONTH_tens3: .equ   7                               ; Month count value tens bits, bit 3
IRTC_YEARMON_bcd_YEAR0: .equ   8                                     ; Year count value bits, bit 0
IRTC_YEARMON_bcd_YEAR1: .equ   9                                     ; Year count value bits, bit 1
IRTC_YEARMON_bcd_YEAR2: .equ   10                                    ; Year count value bits, bit 2
IRTC_YEARMON_bcd_YEAR3: .equ   11                                    ; Year count value bits, bit 3
IRTC_YEARMON_bcd_YEAR4: .equ   12                                    ; Year count value bits, bit 4
IRTC_YEARMON_bcd_YEAR5: .equ   13                                    ; Year count value bits, bit 5
IRTC_YEARMON_bcd_YEAR6: .equ   14                                    ; Year count value bits, bit 6
IRTC_YEARMON_bcd_YEAR7: .equ   15                                    ; Year count value bits, bit 7
; bit position masks
mIRTC_YEARMON_bcd_MONTH_units0: .equ   %00000001
mIRTC_YEARMON_bcd_MONTH_units1: .equ   %00000010
mIRTC_YEARMON_bcd_MONTH_units2: .equ   %00000100
mIRTC_YEARMON_bcd_MONTH_units3: .equ   %00001000
mIRTC_YEARMON_bcd_MONTH_tens0: .equ   %00010000
mIRTC_YEARMON_bcd_MONTH_tens1: .equ   %00100000
mIRTC_YEARMON_bcd_MONTH_tens2: .equ   %01000000
mIRTC_YEARMON_bcd_MONTH_tens3: .equ   %10000000
mIRTC_YEARMON_bcd_YEAR0: .equ   %100000000
mIRTC_YEARMON_bcd_YEAR1: .equ   %1000000000
mIRTC_YEARMON_bcd_YEAR2: .equ   %10000000000
mIRTC_YEARMON_bcd_YEAR3: .equ   %100000000000
mIRTC_YEARMON_bcd_YEAR4: .equ   %1000000000000
mIRTC_YEARMON_bcd_YEAR5: .equ   %10000000000000
mIRTC_YEARMON_bcd_YEAR6: .equ   %100000000000000
mIRTC_YEARMON_bcd_YEAR7: .equ   %1000000000000000


;*** IRTC_YEARMON_bin - RTC Year and Month Counters Register (binary format); 0xFFFF8640 ***
IRTC_YEARMON_bin:   .equ   $FFFF8640                                ;*** IRTC_YEARMON_bin - RTC Year and Month Counters Register (binary format); 0xFFFF8640 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_YEARMON_bin_MONTH0: .equ   0                                    ; Month count value bits, bit 0
IRTC_YEARMON_bin_MONTH1: .equ   1                                    ; Month count value bits, bit 1
IRTC_YEARMON_bin_MONTH2: .equ   2                                    ; Month count value bits, bit 2
IRTC_YEARMON_bin_MONTH3: .equ   3                                    ; Month count value bits, bit 3
IRTC_YEARMON_bin_YEAR0: .equ   8                                     ; Year count value bits, bit 0
IRTC_YEARMON_bin_YEAR1: .equ   9                                     ; Year count value bits, bit 1
IRTC_YEARMON_bin_YEAR2: .equ   10                                    ; Year count value bits, bit 2
IRTC_YEARMON_bin_YEAR3: .equ   11                                    ; Year count value bits, bit 3
IRTC_YEARMON_bin_YEAR4: .equ   12                                    ; Year count value bits, bit 4
IRTC_YEARMON_bin_YEAR5: .equ   13                                    ; Year count value bits, bit 5
IRTC_YEARMON_bin_YEAR6: .equ   14                                    ; Year count value bits, bit 6
IRTC_YEARMON_bin_YEAR7: .equ   15                                    ; Year count value bits, bit 7
; bit position masks
mIRTC_YEARMON_bin_MONTH0: .equ   %00000001
mIRTC_YEARMON_bin_MONTH1: .equ   %00000010
mIRTC_YEARMON_bin_MONTH2: .equ   %00000100
mIRTC_YEARMON_bin_MONTH3: .equ   %00001000
mIRTC_YEARMON_bin_YEAR0: .equ   %100000000
mIRTC_YEARMON_bin_YEAR1: .equ   %1000000000
mIRTC_YEARMON_bin_YEAR2: .equ   %10000000000
mIRTC_YEARMON_bin_YEAR3: .equ   %100000000000
mIRTC_YEARMON_bin_YEAR4: .equ   %1000000000000
mIRTC_YEARMON_bin_YEAR5: .equ   %10000000000000
mIRTC_YEARMON_bin_YEAR6: .equ   %100000000000000
mIRTC_YEARMON_bin_YEAR7: .equ   %1000000000000000


;*** IRTC_DAYS_bcd - RTC Days Counter Register (BCD format); 0xFFFF8642 ***
IRTC_DAYS_bcd:      .equ   $FFFF8642                                ;*** IRTC_DAYS_bcd - RTC Days Counter Register (BCD format); 0xFFFF8642 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DAYS_bcd_DAYS_units0: .equ   0                                  ; Day Setting - units. Indicates the current day count, bit 0
IRTC_DAYS_bcd_DAYS_units1: .equ   1                                  ; Day Setting - units. Indicates the current day count, bit 1
IRTC_DAYS_bcd_DAYS_units2: .equ   2                                  ; Day Setting - units. Indicates the current day count, bit 2
IRTC_DAYS_bcd_DAYS_units3: .equ   3                                  ; Day Setting - units. Indicates the current day count, bit 3
IRTC_DAYS_bcd_DAYS_tens0: .equ   4                                   ; Day Setting - tens. Indicates the current day count, bit 0
IRTC_DAYS_bcd_DAYS_tens1: .equ   5                                   ; Day Setting - tens. Indicates the current day count, bit 1
IRTC_DAYS_bcd_DAYS_tens2: .equ   6                                   ; Day Setting - tens. Indicates the current day count, bit 2
IRTC_DAYS_bcd_DAYS_tens3: .equ   7                                   ; Day Setting - tens. Indicates the current day count, bit 3
IRTC_DAYS_bcd_DAY_OF_WEEK0: .equ   8                                 ; Indicates the current day count, bit 0, bit 0
IRTC_DAYS_bcd_DAY_OF_WEEK1: .equ   9                                 ; Indicates the current day count, bit 0, bit 1
IRTC_DAYS_bcd_DAY_OF_WEEK2: .equ   10                                ; Indicates the current day count, bit 0, bit 2
; bit position masks
mIRTC_DAYS_bcd_DAYS_units0: .equ   %00000001
mIRTC_DAYS_bcd_DAYS_units1: .equ   %00000010
mIRTC_DAYS_bcd_DAYS_units2: .equ   %00000100
mIRTC_DAYS_bcd_DAYS_units3: .equ   %00001000
mIRTC_DAYS_bcd_DAYS_tens0: .equ   %00010000
mIRTC_DAYS_bcd_DAYS_tens1: .equ   %00100000
mIRTC_DAYS_bcd_DAYS_tens2: .equ   %01000000
mIRTC_DAYS_bcd_DAYS_tens3: .equ   %10000000
mIRTC_DAYS_bcd_DAY_OF_WEEK0: .equ   %100000000
mIRTC_DAYS_bcd_DAY_OF_WEEK1: .equ   %1000000000
mIRTC_DAYS_bcd_DAY_OF_WEEK2: .equ   %10000000000


;*** IRTC_DAYS_bin - RTC Days Counter Register (binary format); 0xFFFF8642 ***
IRTC_DAYS_bin:      .equ   $FFFF8642                                ;*** IRTC_DAYS_bin - RTC Days Counter Register (binary format); 0xFFFF8642 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DAYS_bin_DAYS0: .equ   0                                        ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 0
IRTC_DAYS_bin_DAYS1: .equ   1                                        ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 1
IRTC_DAYS_bin_DAYS2: .equ   2                                        ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 2
IRTC_DAYS_bin_DAYS3: .equ   3                                        ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 3
IRTC_DAYS_bin_DAYS4: .equ   4                                        ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 4
IRTC_DAYS_bin_DAY_OF_WEEK0: .equ   8                                 ; Indicates the current day count, bit 0, bit 0
IRTC_DAYS_bin_DAY_OF_WEEK1: .equ   9                                 ; Indicates the current day count, bit 0, bit 1
IRTC_DAYS_bin_DAY_OF_WEEK2: .equ   10                                ; Indicates the current day count, bit 0, bit 2
; bit position masks
mIRTC_DAYS_bin_DAYS0: .equ   %00000001
mIRTC_DAYS_bin_DAYS1: .equ   %00000010
mIRTC_DAYS_bin_DAYS2: .equ   %00000100
mIRTC_DAYS_bin_DAYS3: .equ   %00001000
mIRTC_DAYS_bin_DAYS4: .equ   %00010000
mIRTC_DAYS_bin_DAY_OF_WEEK0: .equ   %100000000
mIRTC_DAYS_bin_DAY_OF_WEEK1: .equ   %1000000000
mIRTC_DAYS_bin_DAY_OF_WEEK2: .equ   %10000000000


;*** IRTC_HOURMIN_bcd - RTC Hours and Minutes Counter Register (BCD format); 0xFFFF8644 ***
IRTC_HOURMIN_bcd:   .equ   $FFFF8644                                ;*** IRTC_HOURMIN_bcd - RTC Hours and Minutes Counter Register (BCD format); 0xFFFF8644 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_HOURMIN_bcd_MINUTES_ones0: .equ   0                             ; Indicates the current minutes - ones, bit 0
IRTC_HOURMIN_bcd_MINUTES_ones1: .equ   1                             ; Indicates the current minutes - ones, bit 1
IRTC_HOURMIN_bcd_MINUTES_ones2: .equ   2                             ; Indicates the current minutes - ones, bit 2
IRTC_HOURMIN_bcd_MINUTES_ones3: .equ   3                             ; Indicates the current minutes - ones, bit 3
IRTC_HOURMIN_bcd_MINUTES_tens0: .equ   4                             ; Indicates the current minutes - tens, bit 0
IRTC_HOURMIN_bcd_MINUTES_tens1: .equ   5                             ; Indicates the current minutes - tens, bit 1
IRTC_HOURMIN_bcd_MINUTES_tens2: .equ   6                             ; Indicates the current minutes - tens, bit 2
IRTC_HOURMIN_bcd_MINUTES_tens3: .equ   7                             ; Indicates the current minutes - tens, bit 3
IRTC_HOURMIN_bcd_HOURS_units0: .equ   8                              ; Indicates the current hour - units, bit 0
IRTC_HOURMIN_bcd_HOURS_units1: .equ   9                              ; Indicates the current hour - units, bit 1
IRTC_HOURMIN_bcd_HOURS_units2: .equ   10                             ; Indicates the current hour - units, bit 2
IRTC_HOURMIN_bcd_HOURS_units3: .equ   11                             ; Indicates the current hour - units, bit 3
IRTC_HOURMIN_bcd_HOURS_tens0: .equ   12                              ; Indicates the current hour - tens, bit 0
IRTC_HOURMIN_bcd_HOURS_tens1: .equ   13                              ; Indicates the current hour - tens, bit 1
IRTC_HOURMIN_bcd_HOURS_tens2: .equ   14                              ; Indicates the current hour - tens, bit 2
IRTC_HOURMIN_bcd_HOURS_tens3: .equ   15                              ; Indicates the current hour - tens, bit 3
; bit position masks
mIRTC_HOURMIN_bcd_MINUTES_ones0: .equ   %00000001
mIRTC_HOURMIN_bcd_MINUTES_ones1: .equ   %00000010
mIRTC_HOURMIN_bcd_MINUTES_ones2: .equ   %00000100
mIRTC_HOURMIN_bcd_MINUTES_ones3: .equ   %00001000
mIRTC_HOURMIN_bcd_MINUTES_tens0: .equ   %00010000
mIRTC_HOURMIN_bcd_MINUTES_tens1: .equ   %00100000
mIRTC_HOURMIN_bcd_MINUTES_tens2: .equ   %01000000
mIRTC_HOURMIN_bcd_MINUTES_tens3: .equ   %10000000
mIRTC_HOURMIN_bcd_HOURS_units0: .equ   %100000000
mIRTC_HOURMIN_bcd_HOURS_units1: .equ   %1000000000
mIRTC_HOURMIN_bcd_HOURS_units2: .equ   %10000000000
mIRTC_HOURMIN_bcd_HOURS_units3: .equ   %100000000000
mIRTC_HOURMIN_bcd_HOURS_tens0: .equ   %1000000000000
mIRTC_HOURMIN_bcd_HOURS_tens1: .equ   %10000000000000
mIRTC_HOURMIN_bcd_HOURS_tens2: .equ   %100000000000000
mIRTC_HOURMIN_bcd_HOURS_tens3: .equ   %1000000000000000


;*** IRTC_HOURMIN_bin - RTC Hours and Minutes Counter Register (binary format); 0xFFFF8644 ***
IRTC_HOURMIN_bin:   .equ   $FFFF8644                                ;*** IRTC_HOURMIN_bin - RTC Hours and Minutes Counter Register (binary format); 0xFFFF8644 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_HOURMIN_bin_MINUTES0: .equ   0                                  ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B), bit 0
IRTC_HOURMIN_bin_MINUTES1: .equ   1                                  ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B), bit 1
IRTC_HOURMIN_bin_MINUTES2: .equ   2                                  ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B), bit 2
IRTC_HOURMIN_bin_MINUTES3: .equ   3                                  ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B), bit 3
IRTC_HOURMIN_bin_MINUTES4: .equ   4                                  ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B), bit 4
IRTC_HOURMIN_bin_MINUTES5: .equ   5                                  ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B), bit 5
IRTC_HOURMIN_bin_HOURS0: .equ   8                                    ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17), bit 0
IRTC_HOURMIN_bin_HOURS1: .equ   9                                    ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17), bit 1
IRTC_HOURMIN_bin_HOURS2: .equ   10                                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17), bit 2
IRTC_HOURMIN_bin_HOURS3: .equ   11                                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17), bit 3
IRTC_HOURMIN_bin_HOURS4: .equ   12                                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17), bit 4
; bit position masks
mIRTC_HOURMIN_bin_MINUTES0: .equ   %00000001
mIRTC_HOURMIN_bin_MINUTES1: .equ   %00000010
mIRTC_HOURMIN_bin_MINUTES2: .equ   %00000100
mIRTC_HOURMIN_bin_MINUTES3: .equ   %00001000
mIRTC_HOURMIN_bin_MINUTES4: .equ   %00010000
mIRTC_HOURMIN_bin_MINUTES5: .equ   %00100000
mIRTC_HOURMIN_bin_HOURS0: .equ   %100000000
mIRTC_HOURMIN_bin_HOURS1: .equ   %1000000000
mIRTC_HOURMIN_bin_HOURS2: .equ   %10000000000
mIRTC_HOURMIN_bin_HOURS3: .equ   %100000000000
mIRTC_HOURMIN_bin_HOURS4: .equ   %1000000000000


;*** IRTC_SECONDS_bcd - RTC Seconds Counter Register (BCD format); 0xFFFF8646 ***
IRTC_SECONDS_bcd:   .equ   $FFFF8646                                ;*** IRTC_SECONDS_bcd - RTC Seconds Counter Register (BCD format); 0xFFFF8646 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_SECONDS_bcd_SECONDS_units0: .equ   0                            ; Indicates the current seconds - units, bit 0
IRTC_SECONDS_bcd_SECONDS_units1: .equ   1                            ; Indicates the current seconds - units, bit 1
IRTC_SECONDS_bcd_SECONDS_units2: .equ   2                            ; Indicates the current seconds - units, bit 2
IRTC_SECONDS_bcd_SECONDS_units3: .equ   3                            ; Indicates the current seconds - units, bit 3
IRTC_SECONDS_bcd_SECONDS_tens0: .equ   4                             ; Indicates the current seconds - tens, bit 0
IRTC_SECONDS_bcd_SECONDS_tens1: .equ   5                             ; Indicates the current seconds - tens, bit 1
IRTC_SECONDS_bcd_SECONDS_tens2: .equ   6                             ; Indicates the current seconds - tens, bit 2
IRTC_SECONDS_bcd_SECONDS_tens3: .equ   7                             ; Indicates the current seconds - tens, bit 3
; bit position masks
mIRTC_SECONDS_bcd_SECONDS_units0: .equ   %00000001
mIRTC_SECONDS_bcd_SECONDS_units1: .equ   %00000010
mIRTC_SECONDS_bcd_SECONDS_units2: .equ   %00000100
mIRTC_SECONDS_bcd_SECONDS_units3: .equ   %00001000
mIRTC_SECONDS_bcd_SECONDS_tens0: .equ   %00010000
mIRTC_SECONDS_bcd_SECONDS_tens1: .equ   %00100000
mIRTC_SECONDS_bcd_SECONDS_tens2: .equ   %01000000
mIRTC_SECONDS_bcd_SECONDS_tens3: .equ   %10000000


;*** IRTC_SECONDS_bin - RTC Seconds Counter Register  (binary format); 0xFFFF8646 ***
IRTC_SECONDS_bin:   .equ   $FFFF8646                                ;*** IRTC_SECONDS_bin - RTC Seconds Counter Register  (binary format); 0xFFFF8646 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_SECONDS_bin_SECONDS0: .equ   0                                  ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B), bit 0
IRTC_SECONDS_bin_SECONDS1: .equ   1                                  ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B), bit 1
IRTC_SECONDS_bin_SECONDS2: .equ   2                                  ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B), bit 2
IRTC_SECONDS_bin_SECONDS3: .equ   3                                  ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B), bit 3
IRTC_SECONDS_bin_SECONDS4: .equ   4                                  ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B), bit 4
IRTC_SECONDS_bin_SECONDS5: .equ   5                                  ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B), bit 5
; bit position masks
mIRTC_SECONDS_bin_SECONDS0: .equ   %00000001
mIRTC_SECONDS_bin_SECONDS1: .equ   %00000010
mIRTC_SECONDS_bin_SECONDS2: .equ   %00000100
mIRTC_SECONDS_bin_SECONDS3: .equ   %00001000
mIRTC_SECONDS_bin_SECONDS4: .equ   %00010000
mIRTC_SECONDS_bin_SECONDS5: .equ   %00100000


;*** IRTC_ALM_YRMON_bcd - RTC Year and Month Alarm Register (BCD format); 0xFFFF8648 ***
IRTC_ALM_YRMON_bcd: .equ   $FFFF8648                                ;*** IRTC_ALM_YRMON_bcd - RTC Year and Month Alarm Register (BCD format); 0xFFFF8648 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_YRMON_bcd_AML_MONTH_units0: .equ   0                        ; Month alarm value bits - units, bit 0
IRTC_ALM_YRMON_bcd_AML_MONTH_units1: .equ   1                        ; Month alarm value bits - units, bit 1
IRTC_ALM_YRMON_bcd_AML_MONTH_units2: .equ   2                        ; Month alarm value bits - units, bit 2
IRTC_ALM_YRMON_bcd_AML_MONTH_units3: .equ   3                        ; Month alarm value bits - units, bit 3
IRTC_ALM_YRMON_bcd_AML_MONTH_tens0: .equ   4                         ; Month alarm value bits - tens, bit 0
IRTC_ALM_YRMON_bcd_AML_MONTH_tens1: .equ   5                         ; Month alarm value bits - tens, bit 1
IRTC_ALM_YRMON_bcd_AML_MONTH_tens2: .equ   6                         ; Month alarm value bits - tens, bit 2
IRTC_ALM_YRMON_bcd_AML_MONTH_tens3: .equ   7                         ; Month alarm value bits - tens, bit 3
IRTC_ALM_YRMON_bcd_ALM_YEAR0: .equ   8                               ; Year count value bits, bit 0
IRTC_ALM_YRMON_bcd_ALM_YEAR1: .equ   9                               ; Year count value bits, bit 1
IRTC_ALM_YRMON_bcd_ALM_YEAR2: .equ   10                              ; Year count value bits, bit 2
IRTC_ALM_YRMON_bcd_ALM_YEAR3: .equ   11                              ; Year count value bits, bit 3
IRTC_ALM_YRMON_bcd_ALM_YEAR4: .equ   12                              ; Year count value bits, bit 4
IRTC_ALM_YRMON_bcd_ALM_YEAR5: .equ   13                              ; Year count value bits, bit 5
IRTC_ALM_YRMON_bcd_ALM_YEAR6: .equ   14                              ; Year count value bits, bit 6
IRTC_ALM_YRMON_bcd_ALM_YEAR7: .equ   15                              ; Year count value bits, bit 7
; bit position masks
mIRTC_ALM_YRMON_bcd_AML_MONTH_units0: .equ   %00000001
mIRTC_ALM_YRMON_bcd_AML_MONTH_units1: .equ   %00000010
mIRTC_ALM_YRMON_bcd_AML_MONTH_units2: .equ   %00000100
mIRTC_ALM_YRMON_bcd_AML_MONTH_units3: .equ   %00001000
mIRTC_ALM_YRMON_bcd_AML_MONTH_tens0: .equ   %00010000
mIRTC_ALM_YRMON_bcd_AML_MONTH_tens1: .equ   %00100000
mIRTC_ALM_YRMON_bcd_AML_MONTH_tens2: .equ   %01000000
mIRTC_ALM_YRMON_bcd_AML_MONTH_tens3: .equ   %10000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR0: .equ   %100000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR1: .equ   %1000000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR2: .equ   %10000000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR3: .equ   %100000000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR4: .equ   %1000000000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR5: .equ   %10000000000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR6: .equ   %100000000000000
mIRTC_ALM_YRMON_bcd_ALM_YEAR7: .equ   %1000000000000000


;*** IRTC_ALM_YRMON_bin - RTC Year and Month Alarm Register (binary format); 0xFFFF8648 ***
IRTC_ALM_YRMON_bin: .equ   $FFFF8648                                ;*** IRTC_ALM_YRMON_bin - RTC Year and Month Alarm Register (binary format); 0xFFFF8648 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_YRMON_bin_AML_MONTH0: .equ   0                              ; Month alarm value bits, bit 0
IRTC_ALM_YRMON_bin_AML_MONTH1: .equ   1                              ; Month alarm value bits, bit 1
IRTC_ALM_YRMON_bin_AML_MONTH2: .equ   2                              ; Month alarm value bits, bit 2
IRTC_ALM_YRMON_bin_AML_MONTH3: .equ   3                              ; Month alarm value bits, bit 3
IRTC_ALM_YRMON_bin_ALM_YEAR0: .equ   8                               ; Year count value bits, bit 0
IRTC_ALM_YRMON_bin_ALM_YEAR1: .equ   9                               ; Year count value bits, bit 1
IRTC_ALM_YRMON_bin_ALM_YEAR2: .equ   10                              ; Year count value bits, bit 2
IRTC_ALM_YRMON_bin_ALM_YEAR3: .equ   11                              ; Year count value bits, bit 3
IRTC_ALM_YRMON_bin_ALM_YEAR4: .equ   12                              ; Year count value bits, bit 4
IRTC_ALM_YRMON_bin_ALM_YEAR5: .equ   13                              ; Year count value bits, bit 5
IRTC_ALM_YRMON_bin_ALM_YEAR6: .equ   14                              ; Year count value bits, bit 6
IRTC_ALM_YRMON_bin_ALM_YEAR7: .equ   15                              ; Year count value bits, bit 7
; bit position masks
mIRTC_ALM_YRMON_bin_AML_MONTH0: .equ   %00000001
mIRTC_ALM_YRMON_bin_AML_MONTH1: .equ   %00000010
mIRTC_ALM_YRMON_bin_AML_MONTH2: .equ   %00000100
mIRTC_ALM_YRMON_bin_AML_MONTH3: .equ   %00001000
mIRTC_ALM_YRMON_bin_ALM_YEAR0: .equ   %100000000
mIRTC_ALM_YRMON_bin_ALM_YEAR1: .equ   %1000000000
mIRTC_ALM_YRMON_bin_ALM_YEAR2: .equ   %10000000000
mIRTC_ALM_YRMON_bin_ALM_YEAR3: .equ   %100000000000
mIRTC_ALM_YRMON_bin_ALM_YEAR4: .equ   %1000000000000
mIRTC_ALM_YRMON_bin_ALM_YEAR5: .equ   %10000000000000
mIRTC_ALM_YRMON_bin_ALM_YEAR6: .equ   %100000000000000
mIRTC_ALM_YRMON_bin_ALM_YEAR7: .equ   %1000000000000000


;*** IRTC_ALM_DAYS_bcd - RTC Day Alarm Register (BCD format); 0xFFFF864A ***
IRTC_ALM_DAYS_bcd:  .equ   $FFFF864A                                ;*** IRTC_ALM_DAYS_bcd - RTC Day Alarm Register (BCD format); 0xFFFF864A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_DAYS_bcd_ALM_DAYS_units0: .equ   0                          ; Indicates the current day setting of the alarm - units, bit 0
IRTC_ALM_DAYS_bcd_ALM_DAYS_units1: .equ   1                          ; Indicates the current day setting of the alarm - units, bit 1
IRTC_ALM_DAYS_bcd_ALM_DAYS_units2: .equ   2                          ; Indicates the current day setting of the alarm - units, bit 2
IRTC_ALM_DAYS_bcd_ALM_DAYS_units3: .equ   3                          ; Indicates the current day setting of the alarm - units, bit 3
IRTC_ALM_DAYS_bcd_ALM_DAYS_tens0: .equ   4                           ; Indicates the current day setting of the alarm - tens, bit 0
IRTC_ALM_DAYS_bcd_ALM_DAYS_tens1: .equ   5                           ; Indicates the current day setting of the alarm - tens, bit 1
IRTC_ALM_DAYS_bcd_ALM_DAYS_tens2: .equ   6                           ; Indicates the current day setting of the alarm - tens, bit 2
IRTC_ALM_DAYS_bcd_ALM_DAYS_tens3: .equ   7                           ; Indicates the current day setting of the alarm - tens, bit 3
; bit position masks
mIRTC_ALM_DAYS_bcd_ALM_DAYS_units0: .equ   %00000001
mIRTC_ALM_DAYS_bcd_ALM_DAYS_units1: .equ   %00000010
mIRTC_ALM_DAYS_bcd_ALM_DAYS_units2: .equ   %00000100
mIRTC_ALM_DAYS_bcd_ALM_DAYS_units3: .equ   %00001000
mIRTC_ALM_DAYS_bcd_ALM_DAYS_tens0: .equ   %00010000
mIRTC_ALM_DAYS_bcd_ALM_DAYS_tens1: .equ   %00100000
mIRTC_ALM_DAYS_bcd_ALM_DAYS_tens2: .equ   %01000000
mIRTC_ALM_DAYS_bcd_ALM_DAYS_tens3: .equ   %10000000


;*** IRTC_ALM_DAYS_bin - RTC Day Alarm Register (binary format); 0xFFFF864A ***
IRTC_ALM_DAYS_bin:  .equ   $FFFF864A                                ;*** IRTC_ALM_DAYS_bin - RTC Day Alarm Register (binary format); 0xFFFF864A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_DAYS_bin_ALM_DAYS0: .equ   0                                ; Indicates the current day setting of the alarm, bit 0
IRTC_ALM_DAYS_bin_ALM_DAYS1: .equ   1                                ; Indicates the current day setting of the alarm, bit 1
IRTC_ALM_DAYS_bin_ALM_DAYS2: .equ   2                                ; Indicates the current day setting of the alarm, bit 2
IRTC_ALM_DAYS_bin_ALM_DAYS3: .equ   3                                ; Indicates the current day setting of the alarm, bit 3
IRTC_ALM_DAYS_bin_ALM_DAYS4: .equ   4                                ; Indicates the current day setting of the alarm, bit 4
; bit position masks
mIRTC_ALM_DAYS_bin_ALM_DAYS0: .equ   %00000001
mIRTC_ALM_DAYS_bin_ALM_DAYS1: .equ   %00000010
mIRTC_ALM_DAYS_bin_ALM_DAYS2: .equ   %00000100
mIRTC_ALM_DAYS_bin_ALM_DAYS3: .equ   %00001000
mIRTC_ALM_DAYS_bin_ALM_DAYS4: .equ   %00010000


;*** IRTC_ALM_HM_bcd - RTC Hours and Minutes Alarm Register (BCD format); 0xFFFF864C ***
IRTC_ALM_HM_bcd:    .equ   $FFFF864C                                ;*** IRTC_ALM_HM_bcd - RTC Hours and Minutes Alarm Register (BCD format); 0xFFFF864C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_HM_bcd_ALM_MINUTES_units0: .equ   0                         ; Minutes setting of the alarm - units, bit 0
IRTC_ALM_HM_bcd_ALM_MINUTES_units1: .equ   1                         ; Minutes setting of the alarm - units, bit 1
IRTC_ALM_HM_bcd_ALM_MINUTES_units2: .equ   2                         ; Minutes setting of the alarm - units, bit 2
IRTC_ALM_HM_bcd_ALM_MINUTES_units3: .equ   3                         ; Minutes setting of the alarm - units, bit 3
IRTC_ALM_HM_bcd_ALM_MINUTES_tens0: .equ   4                          ; Minutes setting of the alarm - tens, bit 0
IRTC_ALM_HM_bcd_ALM_MINUTES_tens1: .equ   5                          ; Minutes setting of the alarm - tens, bit 1
IRTC_ALM_HM_bcd_ALM_MINUTES_tens2: .equ   6                          ; Minutes setting of the alarm - tens, bit 2
IRTC_ALM_HM_bcd_ALM_MINUTES_tens3: .equ   7                          ; Minutes setting of the alarm - tens, bit 3
IRTC_ALM_HM_bcd_ALM_HOURS_units0: .equ   8                           ; Hours setting of the alarm - units, bit 0
IRTC_ALM_HM_bcd_ALM_HOURS_units1: .equ   9                           ; Hours setting of the alarm - units, bit 1
IRTC_ALM_HM_bcd_ALM_HOURS_units2: .equ   10                          ; Hours setting of the alarm - units, bit 2
IRTC_ALM_HM_bcd_ALM_HOURS_units3: .equ   11                          ; Hours setting of the alarm - units, bit 3
IRTC_ALM_HM_bcd_ALM_HOURS_tens0: .equ   12                           ; Hours setting of the alarm - tens, bit 0
IRTC_ALM_HM_bcd_ALM_HOURS_tens1: .equ   13                           ; Hours setting of the alarm - tens, bit 1
IRTC_ALM_HM_bcd_ALM_HOURS_tens2: .equ   14                           ; Hours setting of the alarm - tens, bit 2
IRTC_ALM_HM_bcd_ALM_HOURS_tens3: .equ   15                           ; Hours setting of the alarm - tens, bit 3
; bit position masks
mIRTC_ALM_HM_bcd_ALM_MINUTES_units0: .equ   %00000001
mIRTC_ALM_HM_bcd_ALM_MINUTES_units1: .equ   %00000010
mIRTC_ALM_HM_bcd_ALM_MINUTES_units2: .equ   %00000100
mIRTC_ALM_HM_bcd_ALM_MINUTES_units3: .equ   %00001000
mIRTC_ALM_HM_bcd_ALM_MINUTES_tens0: .equ   %00010000
mIRTC_ALM_HM_bcd_ALM_MINUTES_tens1: .equ   %00100000
mIRTC_ALM_HM_bcd_ALM_MINUTES_tens2: .equ   %01000000
mIRTC_ALM_HM_bcd_ALM_MINUTES_tens3: .equ   %10000000
mIRTC_ALM_HM_bcd_ALM_HOURS_units0: .equ   %100000000
mIRTC_ALM_HM_bcd_ALM_HOURS_units1: .equ   %1000000000
mIRTC_ALM_HM_bcd_ALM_HOURS_units2: .equ   %10000000000
mIRTC_ALM_HM_bcd_ALM_HOURS_units3: .equ   %100000000000
mIRTC_ALM_HM_bcd_ALM_HOURS_tens0: .equ   %1000000000000
mIRTC_ALM_HM_bcd_ALM_HOURS_tens1: .equ   %10000000000000
mIRTC_ALM_HM_bcd_ALM_HOURS_tens2: .equ   %100000000000000
mIRTC_ALM_HM_bcd_ALM_HOURS_tens3: .equ   %1000000000000000


;*** IRTC_ALM_HM_bin - RTC Hours and Minutes Alarm Register (binary format); 0xFFFF864C ***
IRTC_ALM_HM_bin:    .equ   $FFFF864C                                ;*** IRTC_ALM_HM_bin - RTC Hours and Minutes Alarm Register (binary format); 0xFFFF864C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_HM_bin_ALM_MINUTES0: .equ   0                               ; Minutes setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 0
IRTC_ALM_HM_bin_ALM_MINUTES1: .equ   1                               ; Minutes setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 1
IRTC_ALM_HM_bin_ALM_MINUTES2: .equ   2                               ; Minutes setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 2
IRTC_ALM_HM_bin_ALM_MINUTES3: .equ   3                               ; Minutes setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 3
IRTC_ALM_HM_bin_ALM_MINUTES4: .equ   4                               ; Minutes setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 4
IRTC_ALM_HM_bin_ALM_MINUTES5: .equ   5                               ; Minutes setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 5
IRTC_ALM_HM_bin_ALM_HOURS0: .equ   8                                 ; Hours setting of the alarm. It can be set to any value between 0 and 23 (0x17), bit 0
IRTC_ALM_HM_bin_ALM_HOURS1: .equ   9                                 ; Hours setting of the alarm. It can be set to any value between 0 and 23 (0x17), bit 1
IRTC_ALM_HM_bin_ALM_HOURS2: .equ   10                                ; Hours setting of the alarm. It can be set to any value between 0 and 23 (0x17), bit 2
IRTC_ALM_HM_bin_ALM_HOURS3: .equ   11                                ; Hours setting of the alarm. It can be set to any value between 0 and 23 (0x17), bit 3
IRTC_ALM_HM_bin_ALM_HOURS4: .equ   12                                ; Hours setting of the alarm. It can be set to any value between 0 and 23 (0x17), bit 4
; bit position masks
mIRTC_ALM_HM_bin_ALM_MINUTES0: .equ   %00000001
mIRTC_ALM_HM_bin_ALM_MINUTES1: .equ   %00000010
mIRTC_ALM_HM_bin_ALM_MINUTES2: .equ   %00000100
mIRTC_ALM_HM_bin_ALM_MINUTES3: .equ   %00001000
mIRTC_ALM_HM_bin_ALM_MINUTES4: .equ   %00010000
mIRTC_ALM_HM_bin_ALM_MINUTES5: .equ   %00100000
mIRTC_ALM_HM_bin_ALM_HOURS0: .equ   %100000000
mIRTC_ALM_HM_bin_ALM_HOURS1: .equ   %1000000000
mIRTC_ALM_HM_bin_ALM_HOURS2: .equ   %10000000000
mIRTC_ALM_HM_bin_ALM_HOURS3: .equ   %100000000000
mIRTC_ALM_HM_bin_ALM_HOURS4: .equ   %1000000000000


;*** IRTC_ALM_SEC_bcd - RTC Seconds Alarm Register (BCD format); 0xFFFF864E ***
IRTC_ALM_SEC_bcd:   .equ   $FFFF864E                                ;*** IRTC_ALM_SEC_bcd - RTC Seconds Alarm Register (BCD format); 0xFFFF864E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_SEC_bcd_ALM_SECONDS_units0: .equ   0                        ; Seconds setting of the alarm - units, bit 0
IRTC_ALM_SEC_bcd_ALM_SECONDS_units1: .equ   1                        ; Seconds setting of the alarm - units, bit 1
IRTC_ALM_SEC_bcd_ALM_SECONDS_units2: .equ   2                        ; Seconds setting of the alarm - units, bit 2
IRTC_ALM_SEC_bcd_ALM_SECONDS_units3: .equ   3                        ; Seconds setting of the alarm - units, bit 3
IRTC_ALM_SEC_bcd_ALM_SECONDS_tens0: .equ   4                         ; Seconds setting of the alarm - tens, bit 0
IRTC_ALM_SEC_bcd_ALM_SECONDS_tens1: .equ   5                         ; Seconds setting of the alarm - tens, bit 1
IRTC_ALM_SEC_bcd_ALM_SECONDS_tens2: .equ   6                         ; Seconds setting of the alarm - tens, bit 2
IRTC_ALM_SEC_bcd_ALM_SECONDS_tens3: .equ   7                         ; Seconds setting of the alarm - tens, bit 3
IRTC_ALM_SEC_bcd_DEC_S: .equ   8                                     ; Controls the decrement of seconds counter
IRTC_ALM_SEC_bcd_INC_S: .equ   9                                     ; Controls the increment of seconds counter
; bit position masks
mIRTC_ALM_SEC_bcd_ALM_SECONDS_units0: .equ   %00000001
mIRTC_ALM_SEC_bcd_ALM_SECONDS_units1: .equ   %00000010
mIRTC_ALM_SEC_bcd_ALM_SECONDS_units2: .equ   %00000100
mIRTC_ALM_SEC_bcd_ALM_SECONDS_units3: .equ   %00001000
mIRTC_ALM_SEC_bcd_ALM_SECONDS_tens0: .equ   %00010000
mIRTC_ALM_SEC_bcd_ALM_SECONDS_tens1: .equ   %00100000
mIRTC_ALM_SEC_bcd_ALM_SECONDS_tens2: .equ   %01000000
mIRTC_ALM_SEC_bcd_ALM_SECONDS_tens3: .equ   %10000000
mIRTC_ALM_SEC_bcd_DEC_S: .equ   %100000000
mIRTC_ALM_SEC_bcd_INC_S: .equ   %1000000000


;*** IRTC_ALM_SEC_bin - RTC Seconds Alarm Register (binary format); 0xFFFF864E ***
IRTC_ALM_SEC_bin:   .equ   $FFFF864E                                ;*** IRTC_ALM_SEC_bin - RTC Seconds Alarm Register (binary format); 0xFFFF864E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_SEC_bin_ALM_SECONDS0: .equ   0                              ; Seconds setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 0
IRTC_ALM_SEC_bin_ALM_SECONDS1: .equ   1                              ; Seconds setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 1
IRTC_ALM_SEC_bin_ALM_SECONDS2: .equ   2                              ; Seconds setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 2
IRTC_ALM_SEC_bin_ALM_SECONDS3: .equ   3                              ; Seconds setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 3
IRTC_ALM_SEC_bin_ALM_SECONDS4: .equ   4                              ; Seconds setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 4
IRTC_ALM_SEC_bin_ALM_SECONDS5: .equ   5                              ; Seconds setting of the alarm. It can be set to any value between 0 and 59 (0x3B), bit 5
IRTC_ALM_SEC_bin_DEC_S: .equ   8                                     ; Controls the decrement of seconds counter
IRTC_ALM_SEC_bin_INC_S: .equ   9                                     ; Controls the increment of seconds counter
; bit position masks
mIRTC_ALM_SEC_bin_ALM_SECONDS0: .equ   %00000001
mIRTC_ALM_SEC_bin_ALM_SECONDS1: .equ   %00000010
mIRTC_ALM_SEC_bin_ALM_SECONDS2: .equ   %00000100
mIRTC_ALM_SEC_bin_ALM_SECONDS3: .equ   %00001000
mIRTC_ALM_SEC_bin_ALM_SECONDS4: .equ   %00010000
mIRTC_ALM_SEC_bin_ALM_SECONDS5: .equ   %00100000
mIRTC_ALM_SEC_bin_DEC_S: .equ   %100000000
mIRTC_ALM_SEC_bin_INC_S: .equ   %1000000000


;*** IRTC_CTRL - RTC Control Register; 0xFFFF8650 ***
IRTC_CTRL:          .equ   $FFFF8650                                ;*** IRTC_CTRL - RTC Control Register; 0xFFFF8650 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_CTRL_WE0:      .equ   0                                         ; Write enable bits, bit 0
IRTC_CTRL_WE1:      .equ   1                                         ; Write enable bits, bit 1
IRTC_CTRL_ALARM_MATCH0: .equ   2                                     ; Alarm match bits, bit 0
IRTC_CTRL_ALARM_MATCH1: .equ   3                                     ; Alarm match bits, bit 1
IRTC_CTRL_DSTEN:    .equ   6                                         ; Daylight saving enable
IRTC_CTRL_BCDEN:    .equ   7                                         ; BCD format enable
IRTC_CTRL_SWR:      .equ   8                                         ; Software reset
IRTC_CTRL_TAMPER_DETECT_DURATION0: .equ   9                          ; Tamper detect duration bits, bit 0
IRTC_CTRL_TAMPER_DETECT_DURATION1: .equ   10                         ; Tamper detect duration bits, bit 1
IRTC_CTRL_TAMPER_DETECT_DURATION2: .equ   11                         ; Tamper detect duration bits, bit 2
IRTC_CTRL_TAMPER_DETECT_DURATION3: .equ   12                         ; Tamper detect duration bits, bit 3
IRTC_CTRL_OFF_CHIP_CLK0: .equ   13                                   ; Off-chip clock output enable bits, bit 0
IRTC_CTRL_OFF_CHIP_CLK1: .equ   14                                   ; Off-chip clock output enable bits, bit 1
IRTC_CTRL_OCLK:     .equ   15                                        ; Oscillator clock output enable
; bit position masks
mIRTC_CTRL_WE0:     .equ   %00000001
mIRTC_CTRL_WE1:     .equ   %00000010
mIRTC_CTRL_ALARM_MATCH0: .equ   %00000100
mIRTC_CTRL_ALARM_MATCH1: .equ   %00001000
mIRTC_CTRL_DSTEN:   .equ   %01000000
mIRTC_CTRL_BCDEN:   .equ   %10000000
mIRTC_CTRL_SWR:     .equ   %100000000
mIRTC_CTRL_TAMPER_DETECT_DURATION0: .equ   %1000000000
mIRTC_CTRL_TAMPER_DETECT_DURATION1: .equ   %10000000000
mIRTC_CTRL_TAMPER_DETECT_DURATION2: .equ   %100000000000
mIRTC_CTRL_TAMPER_DETECT_DURATION3: .equ   %1000000000000
mIRTC_CTRL_OFF_CHIP_CLK0: .equ   %10000000000000
mIRTC_CTRL_OFF_CHIP_CLK1: .equ   %100000000000000
mIRTC_CTRL_OCLK:    .equ   %1000000000000000


;*** IRTC_STATUS - RTC Status Register; 0xFFFF8652 ***
IRTC_STATUS:        .equ   $FFFF8652                                ;*** IRTC_STATUS - RTC Status Register; 0xFFFF8652 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_STATUS_INVAL:  .equ   0                                         ; Invalid time bit
IRTC_STATUS_C_DON:  .equ   1                                         ; Compensation one bit
IRTC_STATUS_BERR:   .equ   2                                         ; Bus error bit
IRTC_STATUS_OCAL:   .equ   3                                         ; Calibration output bit or compensation interval bit
IRTC_STATUS_WPE:    .equ   4                                         ; Write protect enable
IRTC_STATUS_CLV:    .equ   5                                         ; CPU low voltage
; bit position masks
mIRTC_STATUS_INVAL: .equ   %00000001
mIRTC_STATUS_C_DON: .equ   %00000010
mIRTC_STATUS_BERR:  .equ   %00000100
mIRTC_STATUS_OCAL:  .equ   %00001000
mIRTC_STATUS_WPE:   .equ   %00010000
mIRTC_STATUS_CLV:   .equ   %00100000


;*** IRTC_ISR - RTC Interrupt Status Register; 0xFFFF8654 ***
IRTC_ISR:           .equ   $FFFF8654                                ;*** IRTC_ISR - RTC Interrupt Status Register; 0xFFFF8654 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ISR_TMPR:      .equ   0                                         ; Tamper detect interrupt
IRTC_ISR_STW:       .equ   1                                         ; Countdown timer expiry flag
IRTC_ISR_ALM:       .equ   2                                         ; Alarm flag
IRTC_ISR_DAY:       .equ   3                                         ; Day flag
IRTC_ISR_HR:        .equ   4                                         ; Hour flag
IRTC_ISR_MIN:       .equ   5                                         ; Minutes flag
IRTC_ISR_1HZ:       .equ   6                                         ; Interrupt flag 1 Hz. Indicates an interrupt has occurred. If enabled, this bit is set every half a second
IRTC_ISR_2HZ:       .equ   7                                         ; Interrupt flag 2 Hz. Indicates an interrupt has occurred. If enabled, this bit is set every half a second
IRTC_ISR_SAM0:      .equ   8                                         ; Sampling timer 0 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_SAM1:      .equ   9                                         ; Sampling timer 1 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_SAM2:      .equ   10                                        ; Sampling timer 2 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_SAM3:      .equ   11                                        ; Sampling timer 3 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_SAM4:      .equ   12                                        ; Sampling timer 4 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_SAM5:      .equ   13                                        ; Sampling timer 5 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_SAM6:      .equ   14                                        ; Sampling timer 6 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_SAM7:      .equ   15                                        ; Sampling timer 7 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
; bit position masks
mIRTC_ISR_TMPR:     .equ   %00000001
mIRTC_ISR_STW:      .equ   %00000010
mIRTC_ISR_ALM:      .equ   %00000100
mIRTC_ISR_DAY:      .equ   %00001000
mIRTC_ISR_HR:       .equ   %00010000
mIRTC_ISR_MIN:      .equ   %00100000
mIRTC_ISR_1HZ:      .equ   %01000000
mIRTC_ISR_2HZ:      .equ   %10000000
mIRTC_ISR_SAM0:     .equ   %100000000
mIRTC_ISR_SAM1:     .equ   %1000000000
mIRTC_ISR_SAM2:     .equ   %10000000000
mIRTC_ISR_SAM3:     .equ   %100000000000
mIRTC_ISR_SAM4:     .equ   %1000000000000
mIRTC_ISR_SAM5:     .equ   %10000000000000
mIRTC_ISR_SAM6:     .equ   %100000000000000
mIRTC_ISR_SAM7:     .equ   %1000000000000000


;*** IRTC_IER - RTC Interrupt Enable Register; 0xFFFF8656 ***
IRTC_IER:           .equ   $FFFF8656                                ;*** IRTC_IER - RTC Interrupt Enable Register; 0xFFFF8656 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_IER_TMPR:      .equ   0                                         ; Tamper detect interrupt
IRTC_IER_STW:       .equ   1                                         ; Countdown timer expiry flag
IRTC_IER_ALM:       .equ   2                                         ; Alarm flag
IRTC_IER_DAY:       .equ   3                                         ; Day flag
IRTC_IER_HR:        .equ   4                                         ; Hour flag
IRTC_IER_MIN:       .equ   5                                         ; Minutes flag
IRTC_IER_1HZ:       .equ   6                                         ; Sampling timer interrupt at 1 Hz frequency
IRTC_IER_2HZ:       .equ   7                                         ; Sampling timer interrupt at 2 Hz frequency
IRTC_IER_SAM0:      .equ   8                                         ; Sampling timer 0 interrupt enable
IRTC_IER_SAM1:      .equ   9                                         ; Sampling timer 1 interrupt enable
IRTC_IER_SAM2:      .equ   10                                        ; Sampling timer 2 interrupt enable
IRTC_IER_SAM3:      .equ   11                                        ; Sampling timer 3 interrupt enable
IRTC_IER_SAM4:      .equ   12                                        ; Sampling timer 4 interrupt enable
IRTC_IER_SAM5:      .equ   13                                        ; Sampling timer 5 interrupt enable
IRTC_IER_SAM6:      .equ   14                                        ; Sampling timer 6 interrupt enable
IRTC_IER_SAM7:      .equ   15                                        ; Sampling timer 7 interrupt enable
; bit position masks
mIRTC_IER_TMPR:     .equ   %00000001
mIRTC_IER_STW:      .equ   %00000010
mIRTC_IER_ALM:      .equ   %00000100
mIRTC_IER_DAY:      .equ   %00001000
mIRTC_IER_HR:       .equ   %00010000
mIRTC_IER_MIN:      .equ   %00100000
mIRTC_IER_1HZ:      .equ   %01000000
mIRTC_IER_2HZ:      .equ   %10000000
mIRTC_IER_SAM0:     .equ   %100000000
mIRTC_IER_SAM1:     .equ   %1000000000
mIRTC_IER_SAM2:     .equ   %10000000000
mIRTC_IER_SAM3:     .equ   %100000000000
mIRTC_IER_SAM4:     .equ   %1000000000000
mIRTC_IER_SAM5:     .equ   %10000000000000
mIRTC_IER_SAM6:     .equ   %100000000000000
mIRTC_IER_SAM7:     .equ   %1000000000000000


;*** IRTC_COUNT_DN_bcd - RTC Countdown (Minutes) Timer Register (BCD format); 0xFFFF8658 ***
IRTC_COUNT_DN_bcd:  .equ   $FFFF8658                                ;*** IRTC_COUNT_DN_bcd - RTC Countdown (Minutes) Timer Register (BCD format); 0xFFFF8658 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units0: .equ   0                   ; Countdown counter value bits - units, bit 0
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units1: .equ   1                   ; Countdown counter value bits - units, bit 1
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units2: .equ   2                   ; Countdown counter value bits - units, bit 2
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units3: .equ   3                   ; Countdown counter value bits - units, bit 3
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens0: .equ   4                    ; Countdown counter value bits - tens, bit 0
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens1: .equ   5                    ; Countdown counter value bits - tens, bit 1
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens2: .equ   6                    ; Countdown counter value bits - tens, bit 2
IRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens3: .equ   7                    ; Countdown counter value bits - tens, bit 3
; bit position masks
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units0: .equ   %00000001
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units1: .equ   %00000010
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units2: .equ   %00000100
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_units3: .equ   %00001000
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens0: .equ   %00010000
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens1: .equ   %00100000
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens2: .equ   %01000000
mIRTC_COUNT_DN_bcd_COUNTDOWN_COUNT_tens3: .equ   %10000000


;*** IRTC_COUNT_DN_bin - RTC Countdown (Minutes) Timer Register (binary format); 0xFFFF8658 ***
IRTC_COUNT_DN_bin:  .equ   $FFFF8658                                ;*** IRTC_COUNT_DN_bin - RTC Countdown (Minutes) Timer Register (binary format); 0xFFFF8658 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT0: .equ   0                         ; Countdown counter value bits, bit 0
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT1: .equ   1                         ; Countdown counter value bits, bit 1
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT2: .equ   2                         ; Countdown counter value bits, bit 2
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT3: .equ   3                         ; Countdown counter value bits, bit 3
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT4: .equ   4                         ; Countdown counter value bits, bit 4
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT5: .equ   5                         ; Countdown counter value bits, bit 5
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT6: .equ   6                         ; Countdown counter value bits, bit 6
IRTC_COUNT_DN_bin_COUNTDOWN_COUNT7: .equ   7                         ; Countdown counter value bits, bit 7
; bit position masks
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT0: .equ   %00000001
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT1: .equ   %00000010
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT2: .equ   %00000100
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT3: .equ   %00001000
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT4: .equ   %00010000
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT5: .equ   %00100000
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT6: .equ   %01000000
mIRTC_COUNT_DN_bin_COUNTDOWN_COUNT7: .equ   %10000000


;*** IRTC_CFG_DATA - RTC Configuration Data Register; 0xFFFF8660 ***
IRTC_CFG_DATA:      .equ   $FFFF8660                                ;*** IRTC_CFG_DATA - RTC Configuration Data Register; 0xFFFF8660 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_CFG_DATA_CFG0: .equ   0                                         ; Directly output from RTC bit 0
; bit position masks
mIRTC_CFG_DATA_CFG0: .equ   %00000001


;*** IRTC_DST_HOUR_bcd - RTC Daylight Saving Hour Register; 0xFFFF8662 ***
IRTC_DST_HOUR_bcd:  .equ   $FFFF8662                                ;*** IRTC_DST_HOUR_bcd - RTC Daylight Saving Hour Register; 0xFFFF8662 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_HOUR_bcd_DST_END_HOUR_units0: .equ   0                      ; Hour unis value when daylight saving has to end bits, bit 0
IRTC_DST_HOUR_bcd_DST_END_HOUR_units1: .equ   1                      ; Hour unis value when daylight saving has to end bits, bit 1
IRTC_DST_HOUR_bcd_DST_END_HOUR_units2: .equ   2                      ; Hour unis value when daylight saving has to end bits, bit 2
IRTC_DST_HOUR_bcd_DST_END_HOUR_units3: .equ   3                      ; Hour unis value when daylight saving has to end bits, bit 3
IRTC_DST_HOUR_bcd_DST_END_HOUR_tens0: .equ   4                       ; Hour tens value when daylight saving has to end bits, bit 0
IRTC_DST_HOUR_bcd_DST_END_HOUR_tens1: .equ   5                       ; Hour tens value when daylight saving has to end bits, bit 1
IRTC_DST_HOUR_bcd_DST_END_HOUR_tens2: .equ   6                       ; Hour tens value when daylight saving has to end bits, bit 2
IRTC_DST_HOUR_bcd_DST_END_HOUR_tens3: .equ   7                       ; Hour tens value when daylight saving has to end bits, bit 3
IRTC_DST_HOUR_bcd_DST_START_HOUR_units0: .equ   8                    ; Hour units value when daylight saving has to start bits, bit 0
IRTC_DST_HOUR_bcd_DST_START_HOUR_units1: .equ   9                    ; Hour units value when daylight saving has to start bits, bit 1
IRTC_DST_HOUR_bcd_DST_START_HOUR_units2: .equ   10                   ; Hour units value when daylight saving has to start bits, bit 2
IRTC_DST_HOUR_bcd_DST_START_HOUR_units3: .equ   11                   ; Hour units value when daylight saving has to start bits, bit 3
IRTC_DST_HOUR_bcd_DST_START_HOUR_tens0: .equ   12                    ; Hour tens value when daylight saving has to start bits, bit 0
IRTC_DST_HOUR_bcd_DST_START_HOUR_tens1: .equ   13                    ; Hour tens value when daylight saving has to start bits, bit 1
IRTC_DST_HOUR_bcd_DST_START_HOUR_tens2: .equ   14                    ; Hour tens value when daylight saving has to start bits, bit 2
IRTC_DST_HOUR_bcd_DST_START_HOUR_tens3: .equ   15                    ; Hour tens value when daylight saving has to start bits, bit 3
; bit position masks
mIRTC_DST_HOUR_bcd_DST_END_HOUR_units0: .equ   %00000001
mIRTC_DST_HOUR_bcd_DST_END_HOUR_units1: .equ   %00000010
mIRTC_DST_HOUR_bcd_DST_END_HOUR_units2: .equ   %00000100
mIRTC_DST_HOUR_bcd_DST_END_HOUR_units3: .equ   %00001000
mIRTC_DST_HOUR_bcd_DST_END_HOUR_tens0: .equ   %00010000
mIRTC_DST_HOUR_bcd_DST_END_HOUR_tens1: .equ   %00100000
mIRTC_DST_HOUR_bcd_DST_END_HOUR_tens2: .equ   %01000000
mIRTC_DST_HOUR_bcd_DST_END_HOUR_tens3: .equ   %10000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_units0: .equ   %100000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_units1: .equ   %1000000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_units2: .equ   %10000000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_units3: .equ   %100000000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_tens0: .equ   %1000000000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_tens1: .equ   %10000000000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_tens2: .equ   %100000000000000
mIRTC_DST_HOUR_bcd_DST_START_HOUR_tens3: .equ   %1000000000000000


;*** IRTC_DST_HOUR_bin - RTC Daylight Saving Hour Register; 0xFFFF8662 ***
IRTC_DST_HOUR_bin:  .equ   $FFFF8662                                ;*** IRTC_DST_HOUR_bin - RTC Daylight Saving Hour Register; 0xFFFF8662 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_HOUR_bin_DST_END_HOUR0: .equ   0                            ; Hour value when daylight saving has to end bits, bit 0
IRTC_DST_HOUR_bin_DST_END_HOUR1: .equ   1                            ; Hour value when daylight saving has to end bits, bit 1
IRTC_DST_HOUR_bin_DST_END_HOUR2: .equ   2                            ; Hour value when daylight saving has to end bits, bit 2
IRTC_DST_HOUR_bin_DST_END_HOUR3: .equ   3                            ; Hour value when daylight saving has to end bits, bit 3
IRTC_DST_HOUR_bin_DST_END_HOUR4: .equ   4                            ; Hour value when daylight saving has to end bits, bit 4
IRTC_DST_HOUR_bin_DST_START_HOUR0: .equ   8                          ; Hour value when daylight saving has to start bits, bit 0
IRTC_DST_HOUR_bin_DST_START_HOUR1: .equ   9                          ; Hour value when daylight saving has to start bits, bit 1
IRTC_DST_HOUR_bin_DST_START_HOUR2: .equ   10                         ; Hour value when daylight saving has to start bits, bit 2
IRTC_DST_HOUR_bin_DST_START_HOUR3: .equ   11                         ; Hour value when daylight saving has to start bits, bit 3
IRTC_DST_HOUR_bin_DST_START_HOUR4: .equ   12                         ; Hour value when daylight saving has to start bits, bit 4
; bit position masks
mIRTC_DST_HOUR_bin_DST_END_HOUR0: .equ   %00000001
mIRTC_DST_HOUR_bin_DST_END_HOUR1: .equ   %00000010
mIRTC_DST_HOUR_bin_DST_END_HOUR2: .equ   %00000100
mIRTC_DST_HOUR_bin_DST_END_HOUR3: .equ   %00001000
mIRTC_DST_HOUR_bin_DST_END_HOUR4: .equ   %00010000
mIRTC_DST_HOUR_bin_DST_START_HOUR0: .equ   %100000000
mIRTC_DST_HOUR_bin_DST_START_HOUR1: .equ   %1000000000
mIRTC_DST_HOUR_bin_DST_START_HOUR2: .equ   %10000000000
mIRTC_DST_HOUR_bin_DST_START_HOUR3: .equ   %100000000000
mIRTC_DST_HOUR_bin_DST_START_HOUR4: .equ   %1000000000000


;*** IRTC_DST_MNTH_bcd - RTC Daylight Saving Month Register; 0xFFFF8664 ***
IRTC_DST_MNTH_bcd:  .equ   $FFFF8664                                ;*** IRTC_DST_MNTH_bcd - RTC Daylight Saving Month Register; 0xFFFF8664 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_MNTH_bcd_DST_END_MONTH_units0: .equ   0                     ; Month units value when daylight saving has to end bits, bit 0
IRTC_DST_MNTH_bcd_DST_END_MONTH_units1: .equ   1                     ; Month units value when daylight saving has to end bits, bit 1
IRTC_DST_MNTH_bcd_DST_END_MONTH_units2: .equ   2                     ; Month units value when daylight saving has to end bits, bit 2
IRTC_DST_MNTH_bcd_DST_END_MONTH_units3: .equ   3                     ; Month units value when daylight saving has to end bits, bit 3
IRTC_DST_MNTH_bcd_DST_END_MONTH_tens0: .equ   4                      ; Month tens value when daylight saving has to end bits, bit 0
IRTC_DST_MNTH_bcd_DST_END_MONTH_tens1: .equ   5                      ; Month tens value when daylight saving has to end bits, bit 1
IRTC_DST_MNTH_bcd_DST_END_MONTH_tens2: .equ   6                      ; Month tens value when daylight saving has to end bits, bit 2
IRTC_DST_MNTH_bcd_DST_END_MONTH_tens3: .equ   7                      ; Month tens value when daylight saving has to end bits, bit 3
IRTC_DST_MNTH_bcd_DST_START_MONTH_units0: .equ   8                   ; Month units value when daylight saving has to start bits, bit 0
IRTC_DST_MNTH_bcd_DST_START_MONTH_units1: .equ   9                   ; Month units value when daylight saving has to start bits, bit 1
IRTC_DST_MNTH_bcd_DST_START_MONTH_units2: .equ   10                  ; Month units value when daylight saving has to start bits, bit 2
IRTC_DST_MNTH_bcd_DST_START_MONTH_units3: .equ   11                  ; Month units value when daylight saving has to start bits, bit 3
IRTC_DST_MNTH_bcd_DST_START_MONTH_tens0: .equ   12                   ; Month tens value when daylight saving has to start bits, bit 0
IRTC_DST_MNTH_bcd_DST_START_MONTH_tens1: .equ   13                   ; Month tens value when daylight saving has to start bits, bit 1
IRTC_DST_MNTH_bcd_DST_START_MONTH_tens2: .equ   14                   ; Month tens value when daylight saving has to start bits, bit 2
IRTC_DST_MNTH_bcd_DST_START_MONTH_tens3: .equ   15                   ; Month tens value when daylight saving has to start bits, bit 3
; bit position masks
mIRTC_DST_MNTH_bcd_DST_END_MONTH_units0: .equ   %00000001
mIRTC_DST_MNTH_bcd_DST_END_MONTH_units1: .equ   %00000010
mIRTC_DST_MNTH_bcd_DST_END_MONTH_units2: .equ   %00000100
mIRTC_DST_MNTH_bcd_DST_END_MONTH_units3: .equ   %00001000
mIRTC_DST_MNTH_bcd_DST_END_MONTH_tens0: .equ   %00010000
mIRTC_DST_MNTH_bcd_DST_END_MONTH_tens1: .equ   %00100000
mIRTC_DST_MNTH_bcd_DST_END_MONTH_tens2: .equ   %01000000
mIRTC_DST_MNTH_bcd_DST_END_MONTH_tens3: .equ   %10000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_units0: .equ   %100000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_units1: .equ   %1000000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_units2: .equ   %10000000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_units3: .equ   %100000000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_tens0: .equ   %1000000000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_tens1: .equ   %10000000000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_tens2: .equ   %100000000000000
mIRTC_DST_MNTH_bcd_DST_START_MONTH_tens3: .equ   %1000000000000000


;*** IRTC_DST_MNTH_bin - RTC Daylight Saving Month Register; 0xFFFF8664 ***
IRTC_DST_MNTH_bin:  .equ   $FFFF8664                                ;*** IRTC_DST_MNTH_bin - RTC Daylight Saving Month Register; 0xFFFF8664 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_MNTH_bin_DST_END_MONTH0: .equ   0                           ; Month value when daylight saving has to end bits, bit 0
IRTC_DST_MNTH_bin_DST_END_MONTH1: .equ   1                           ; Month value when daylight saving has to end bits, bit 1
IRTC_DST_MNTH_bin_DST_END_MONTH2: .equ   2                           ; Month value when daylight saving has to end bits, bit 2
IRTC_DST_MNTH_bin_DST_END_MONTH3: .equ   3                           ; Month value when daylight saving has to end bits, bit 3
IRTC_DST_MNTH_bin_DST_START_MONTH0: .equ   8                         ; Month value when daylight saving has to start bits, bit 0
IRTC_DST_MNTH_bin_DST_START_MONTH1: .equ   9                         ; Month value when daylight saving has to start bits, bit 1
IRTC_DST_MNTH_bin_DST_START_MONTH2: .equ   10                        ; Month value when daylight saving has to start bits, bit 2
IRTC_DST_MNTH_bin_DST_START_MONTH3: .equ   11                        ; Month value when daylight saving has to start bits, bit 3
; bit position masks
mIRTC_DST_MNTH_bin_DST_END_MONTH0: .equ   %00000001
mIRTC_DST_MNTH_bin_DST_END_MONTH1: .equ   %00000010
mIRTC_DST_MNTH_bin_DST_END_MONTH2: .equ   %00000100
mIRTC_DST_MNTH_bin_DST_END_MONTH3: .equ   %00001000
mIRTC_DST_MNTH_bin_DST_START_MONTH0: .equ   %100000000
mIRTC_DST_MNTH_bin_DST_START_MONTH1: .equ   %1000000000
mIRTC_DST_MNTH_bin_DST_START_MONTH2: .equ   %10000000000
mIRTC_DST_MNTH_bin_DST_START_MONTH3: .equ   %100000000000


;*** IRTC_DST_DAY_bcd - RTC Daylight Saving Day Register; 0xFFFF8666 ***
IRTC_DST_DAY_bcd:   .equ   $FFFF8666                                ;*** IRTC_DST_DAY_bcd - RTC Daylight Saving Day Register; 0xFFFF8666 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_DAY_bcd_DST_END_DAY_units0: .equ   0                        ; Day units value when daylight saving has to end bits, bit 0
IRTC_DST_DAY_bcd_DST_END_DAY_units1: .equ   1                        ; Day units value when daylight saving has to end bits, bit 1
IRTC_DST_DAY_bcd_DST_END_DAY_units2: .equ   2                        ; Day units value when daylight saving has to end bits, bit 2
IRTC_DST_DAY_bcd_DST_END_DAY_units3: .equ   3                        ; Day units value when daylight saving has to end bits, bit 3
IRTC_DST_DAY_bcd_DST_END_DAY_tens0: .equ   4                         ; Day tens value when daylight saving has to end bits, bit 0
IRTC_DST_DAY_bcd_DST_END_DAY_tens1: .equ   5                         ; Day tens value when daylight saving has to end bits, bit 1
IRTC_DST_DAY_bcd_DST_END_DAY_tens2: .equ   6                         ; Day tens value when daylight saving has to end bits, bit 2
IRTC_DST_DAY_bcd_DST_END_DAY_tens3: .equ   7                         ; Day tens value when daylight saving has to end bits, bit 3
IRTC_DST_DAY_bcd_DST_START_DAY_units0: .equ   8                      ; Day units value when daylight saving has to start bits, bit 0
IRTC_DST_DAY_bcd_DST_START_DAY_units1: .equ   9                      ; Day units value when daylight saving has to start bits, bit 1
IRTC_DST_DAY_bcd_DST_START_DAY_units2: .equ   10                     ; Day units value when daylight saving has to start bits, bit 2
IRTC_DST_DAY_bcd_DST_START_DAY_units3: .equ   11                     ; Day units value when daylight saving has to start bits, bit 3
IRTC_DST_DAY_bcd_DST_START_DAY_tens0: .equ   12                      ; Day tens value when daylight saving has to start bits, bit 0
IRTC_DST_DAY_bcd_DST_START_DAY_tens1: .equ   13                      ; Day tens value when daylight saving has to start bits, bit 1
IRTC_DST_DAY_bcd_DST_START_DAY_tens2: .equ   14                      ; Day tens value when daylight saving has to start bits, bit 2
IRTC_DST_DAY_bcd_DST_START_DAY_tens3: .equ   15                      ; Day tens value when daylight saving has to start bits, bit 3
; bit position masks
mIRTC_DST_DAY_bcd_DST_END_DAY_units0: .equ   %00000001
mIRTC_DST_DAY_bcd_DST_END_DAY_units1: .equ   %00000010
mIRTC_DST_DAY_bcd_DST_END_DAY_units2: .equ   %00000100
mIRTC_DST_DAY_bcd_DST_END_DAY_units3: .equ   %00001000
mIRTC_DST_DAY_bcd_DST_END_DAY_tens0: .equ   %00010000
mIRTC_DST_DAY_bcd_DST_END_DAY_tens1: .equ   %00100000
mIRTC_DST_DAY_bcd_DST_END_DAY_tens2: .equ   %01000000
mIRTC_DST_DAY_bcd_DST_END_DAY_tens3: .equ   %10000000
mIRTC_DST_DAY_bcd_DST_START_DAY_units0: .equ   %100000000
mIRTC_DST_DAY_bcd_DST_START_DAY_units1: .equ   %1000000000
mIRTC_DST_DAY_bcd_DST_START_DAY_units2: .equ   %10000000000
mIRTC_DST_DAY_bcd_DST_START_DAY_units3: .equ   %100000000000
mIRTC_DST_DAY_bcd_DST_START_DAY_tens0: .equ   %1000000000000
mIRTC_DST_DAY_bcd_DST_START_DAY_tens1: .equ   %10000000000000
mIRTC_DST_DAY_bcd_DST_START_DAY_tens2: .equ   %100000000000000
mIRTC_DST_DAY_bcd_DST_START_DAY_tens3: .equ   %1000000000000000


;*** IRTC_DST_DAY_bin - RTC Daylight Saving Day Register; 0xFFFF8666 ***
IRTC_DST_DAY_bin:   .equ   $FFFF8666                                ;*** IRTC_DST_DAY_bin - RTC Daylight Saving Day Register; 0xFFFF8666 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_DAY_bin_DST_END_DAY0: .equ   0                              ; Day value when daylight saving has to end bits, bit 0
IRTC_DST_DAY_bin_DST_END_DAY1: .equ   1                              ; Day value when daylight saving has to end bits, bit 1
IRTC_DST_DAY_bin_DST_END_DAY2: .equ   2                              ; Day value when daylight saving has to end bits, bit 2
IRTC_DST_DAY_bin_DST_END_DAY3: .equ   3                              ; Day value when daylight saving has to end bits, bit 3
IRTC_DST_DAY_bin_DST_END_DAY4: .equ   4                              ; Day value when daylight saving has to end bits, bit 4
IRTC_DST_DAY_bin_DST_START_DAY0: .equ   8                            ; Day value when daylight saving has to start bits, bit 0
IRTC_DST_DAY_bin_DST_START_DAY1: .equ   9                            ; Day value when daylight saving has to start bits, bit 1
IRTC_DST_DAY_bin_DST_START_DAY2: .equ   10                           ; Day value when daylight saving has to start bits, bit 2
IRTC_DST_DAY_bin_DST_START_DAY3: .equ   11                           ; Day value when daylight saving has to start bits, bit 3
IRTC_DST_DAY_bin_DST_START_DAY4: .equ   12                           ; Day value when daylight saving has to start bits, bit 4
; bit position masks
mIRTC_DST_DAY_bin_DST_END_DAY0: .equ   %00000001
mIRTC_DST_DAY_bin_DST_END_DAY1: .equ   %00000010
mIRTC_DST_DAY_bin_DST_END_DAY2: .equ   %00000100
mIRTC_DST_DAY_bin_DST_END_DAY3: .equ   %00001000
mIRTC_DST_DAY_bin_DST_END_DAY4: .equ   %00010000
mIRTC_DST_DAY_bin_DST_START_DAY0: .equ   %100000000
mIRTC_DST_DAY_bin_DST_START_DAY1: .equ   %1000000000
mIRTC_DST_DAY_bin_DST_START_DAY2: .equ   %10000000000
mIRTC_DST_DAY_bin_DST_START_DAY3: .equ   %100000000000
mIRTC_DST_DAY_bin_DST_START_DAY4: .equ   %1000000000000


;*** IRTC_COMPEN - RTC Compensation Register; 0xFFFF8668 ***
IRTC_COMPEN:        .equ   $FFFF8668                                ;*** IRTC_COMPEN - RTC Compensation Register; 0xFFFF8668 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_COMPEN_COMPENSATION_VALUE0: .equ   0                            ; Compensation value bits, bit 0
IRTC_COMPEN_COMPENSATION_VALUE1: .equ   1                            ; Compensation value bits, bit 1
IRTC_COMPEN_COMPENSATION_VALUE2: .equ   2                            ; Compensation value bits, bit 2
IRTC_COMPEN_COMPENSATION_VALUE3: .equ   3                            ; Compensation value bits, bit 3
IRTC_COMPEN_COMPENSATION_VALUE4: .equ   4                            ; Compensation value bits, bit 4
IRTC_COMPEN_COMPENSATION_VALUE5: .equ   5                            ; Compensation value bits, bit 5
IRTC_COMPEN_COMPENSATION_VALUE6: .equ   6                            ; Compensation value bits, bit 6
IRTC_COMPEN_COMPENSATION_VALUE7: .equ   7                            ; Compensation value bits, bit 7
IRTC_COMPEN_COMPENSTAION_INTERVAL0: .equ   8                         ; Compensation interval value bits, bit 0
IRTC_COMPEN_COMPENSTAION_INTERVAL1: .equ   9                         ; Compensation interval value bits, bit 1
IRTC_COMPEN_COMPENSTAION_INTERVAL2: .equ   10                        ; Compensation interval value bits, bit 2
IRTC_COMPEN_COMPENSTAION_INTERVAL3: .equ   11                        ; Compensation interval value bits, bit 3
IRTC_COMPEN_COMPENSTAION_INTERVAL4: .equ   12                        ; Compensation interval value bits, bit 4
IRTC_COMPEN_COMPENSTAION_INTERVAL5: .equ   13                        ; Compensation interval value bits, bit 5
IRTC_COMPEN_COMPENSTAION_INTERVAL6: .equ   14                        ; Compensation interval value bits, bit 6
IRTC_COMPEN_COMPENSTAION_INTERVAL7: .equ   15                        ; Compensation interval value bits, bit 7
; bit position masks
mIRTC_COMPEN_COMPENSATION_VALUE0: .equ   %00000001
mIRTC_COMPEN_COMPENSATION_VALUE1: .equ   %00000010
mIRTC_COMPEN_COMPENSATION_VALUE2: .equ   %00000100
mIRTC_COMPEN_COMPENSATION_VALUE3: .equ   %00001000
mIRTC_COMPEN_COMPENSATION_VALUE4: .equ   %00010000
mIRTC_COMPEN_COMPENSATION_VALUE5: .equ   %00100000
mIRTC_COMPEN_COMPENSATION_VALUE6: .equ   %01000000
mIRTC_COMPEN_COMPENSATION_VALUE7: .equ   %10000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL0: .equ   %100000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL1: .equ   %1000000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL2: .equ   %10000000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL3: .equ   %100000000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL4: .equ   %1000000000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL5: .equ   %10000000000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL6: .equ   %100000000000000
mIRTC_COMPEN_COMPENSTAION_INTERVAL7: .equ   %1000000000000000


;*** IRTC_TTSR_MY_bcd - RTC Tamper Time Stamp Month & Year Register; 0xFFFF866A ***
IRTC_TTSR_MY_bcd:   .equ   $FFFF866A                                ;*** IRTC_TTSR_MY_bcd - RTC Tamper Time Stamp Month & Year Register; 0xFFFF866A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units0: .equ   0                  ; Tamper detect month units value bits, bit 0
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units1: .equ   1                  ; Tamper detect month units value bits, bit 1
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units2: .equ   2                  ; Tamper detect month units value bits, bit 2
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units3: .equ   3                  ; Tamper detect month units value bits, bit 3
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens0: .equ   4                   ; Tamper detect month tens value bits, bit 0
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens1: .equ   5                   ; Tamper detect month tens value bits, bit 1
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens2: .equ   6                   ; Tamper detect month tens value bits, bit 2
IRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens3: .equ   7                   ; Tamper detect month tens value bits, bit 3
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR0: .equ   8                          ; Tamper detect year value bits, bit 0
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR1: .equ   9                          ; Tamper detect year value bits, bit 1
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR2: .equ   10                         ; Tamper detect year value bits, bit 2
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR3: .equ   11                         ; Tamper detect year value bits, bit 3
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR4: .equ   12                         ; Tamper detect year value bits, bit 4
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR5: .equ   13                         ; Tamper detect year value bits, bit 5
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR6: .equ   14                         ; Tamper detect year value bits, bit 6
IRTC_TTSR_MY_bcd_TIME_STAMP_YEAR7: .equ   15                         ; Tamper detect year value bits, bit 7
; bit position masks
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units0: .equ   %00000001
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units1: .equ   %00000010
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units2: .equ   %00000100
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_units3: .equ   %00001000
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens0: .equ   %00010000
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens1: .equ   %00100000
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens2: .equ   %01000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_MONTHS_tens3: .equ   %10000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR0: .equ   %100000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR1: .equ   %1000000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR2: .equ   %10000000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR3: .equ   %100000000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR4: .equ   %1000000000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR5: .equ   %10000000000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR6: .equ   %100000000000000
mIRTC_TTSR_MY_bcd_TIME_STAMP_YEAR7: .equ   %1000000000000000


;*** IRTC_TTSR_MY_bin - RTC Tamper Time Stamp Month & Year Register; 0xFFFF866A ***
IRTC_TTSR_MY_bin:   .equ   $FFFF866A                                ;*** IRTC_TTSR_MY_bin - RTC Tamper Time Stamp Month & Year Register; 0xFFFF866A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_MY_bin_TIME_STAMP_MONTHS0: .equ   0                        ; Tamper detect month value bits, bit 0
IRTC_TTSR_MY_bin_TIME_STAMP_MONTHS1: .equ   1                        ; Tamper detect month value bits, bit 1
IRTC_TTSR_MY_bin_TIME_STAMP_MONTHS2: .equ   2                        ; Tamper detect month value bits, bit 2
IRTC_TTSR_MY_bin_TIME_STAMP_MONTHS3: .equ   3                        ; Tamper detect month value bits, bit 3
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR0: .equ   8                          ; Tamper detect year value bits, bit 0
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR1: .equ   9                          ; Tamper detect year value bits, bit 1
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR2: .equ   10                         ; Tamper detect year value bits, bit 2
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR3: .equ   11                         ; Tamper detect year value bits, bit 3
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR4: .equ   12                         ; Tamper detect year value bits, bit 4
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR5: .equ   13                         ; Tamper detect year value bits, bit 5
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR6: .equ   14                         ; Tamper detect year value bits, bit 6
IRTC_TTSR_MY_bin_TIME_STAMP_YEAR7: .equ   15                         ; Tamper detect year value bits, bit 7
; bit position masks
mIRTC_TTSR_MY_bin_TIME_STAMP_MONTHS0: .equ   %00000001
mIRTC_TTSR_MY_bin_TIME_STAMP_MONTHS1: .equ   %00000010
mIRTC_TTSR_MY_bin_TIME_STAMP_MONTHS2: .equ   %00000100
mIRTC_TTSR_MY_bin_TIME_STAMP_MONTHS3: .equ   %00001000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR0: .equ   %100000000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR1: .equ   %1000000000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR2: .equ   %10000000000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR3: .equ   %100000000000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR4: .equ   %1000000000000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR5: .equ   %10000000000000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR6: .equ   %100000000000000
mIRTC_TTSR_MY_bin_TIME_STAMP_YEAR7: .equ   %1000000000000000


;*** IRTC_TTSR_DAY_bcd - RTC Tamper Time Stamp Day Register; 0xFFFF866C ***
IRTC_TTSR_DAY_bcd:  .equ   $FFFF866C                                ;*** IRTC_TTSR_DAY_bcd - RTC Tamper Time Stamp Day Register; 0xFFFF866C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units0: .equ   0                    ; Tamper detect days units value bits, bit 0
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units1: .equ   1                    ; Tamper detect days units value bits, bit 1
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units2: .equ   2                    ; Tamper detect days units value bits, bit 2
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units3: .equ   3                    ; Tamper detect days units value bits, bit 3
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens0: .equ   4                     ; Tamper detect days tens value bits, bit 0
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens1: .equ   5                     ; Tamper detect days tens value bits, bit 1
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens2: .equ   6                     ; Tamper detect days tens value bits, bit 2
IRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens3: .equ   7                     ; Tamper detect days tens value bits, bit 3
; bit position masks
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units0: .equ   %00000001
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units1: .equ   %00000010
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units2: .equ   %00000100
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_units3: .equ   %00001000
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens0: .equ   %00010000
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens1: .equ   %00100000
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens2: .equ   %01000000
mIRTC_TTSR_DAY_bcd_TIME_STAMP_DAY_tens3: .equ   %10000000


;*** IRTC_TTSR_DAY_bin - RTC Tamper Time Stamp Day Register; 0xFFFF866C ***
IRTC_TTSR_DAY_bin:  .equ   $FFFF866C                                ;*** IRTC_TTSR_DAY_bin - RTC Tamper Time Stamp Day Register; 0xFFFF866C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_DAY_bin_TIME_STAMP_DAY0: .equ   0                          ; Tamper detect days value bits, bit 0
IRTC_TTSR_DAY_bin_TIME_STAMP_DAY1: .equ   1                          ; Tamper detect days value bits, bit 1
IRTC_TTSR_DAY_bin_TIME_STAMP_DAY2: .equ   2                          ; Tamper detect days value bits, bit 2
IRTC_TTSR_DAY_bin_TIME_STAMP_DAY3: .equ   3                          ; Tamper detect days value bits, bit 3
IRTC_TTSR_DAY_bin_TIME_STAMP_DAY4: .equ   4                          ; Tamper detect days value bits, bit 4
; bit position masks
mIRTC_TTSR_DAY_bin_TIME_STAMP_DAY0: .equ   %00000001
mIRTC_TTSR_DAY_bin_TIME_STAMP_DAY1: .equ   %00000010
mIRTC_TTSR_DAY_bin_TIME_STAMP_DAY2: .equ   %00000100
mIRTC_TTSR_DAY_bin_TIME_STAMP_DAY3: .equ   %00001000
mIRTC_TTSR_DAY_bin_TIME_STAMP_DAY4: .equ   %00010000


;*** IRTC_TTSR_HM_bcd - RTC Tamper Time Stamp Hours & Minutes Register; 0xFFFF866E ***
IRTC_TTSR_HM_bcd:   .equ   $FFFF866E                                ;*** IRTC_TTSR_HM_bcd - RTC Tamper Time Stamp Hours & Minutes Register; 0xFFFF866E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units0: .equ   0                 ; Tamper detect minutes units value bits, bit 0
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units1: .equ   1                 ; Tamper detect minutes units value bits, bit 1
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units2: .equ   2                 ; Tamper detect minutes units value bits, bit 2
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units3: .equ   3                 ; Tamper detect minutes units value bits, bit 3
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens0: .equ   4                  ; Tamper detect minutes tens value bits, bit 0
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens1: .equ   5                  ; Tamper detect minutes tens value bits, bit 1
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens2: .equ   6                  ; Tamper detect minutes tens value bits, bit 2
IRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens3: .equ   7                  ; Tamper detect minutes tens value bits, bit 3
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units0: .equ   8                   ; Tamper detect hours units value bits, bit 0
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units1: .equ   9                   ; Tamper detect hours units value bits, bit 1
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units2: .equ   10                  ; Tamper detect hours units value bits, bit 2
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units3: .equ   11                  ; Tamper detect hours units value bits, bit 3
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens0: .equ   12                   ; Tamper detect hours tens value bits, bit 0
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens1: .equ   13                   ; Tamper detect hours tens value bits, bit 1
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens2: .equ   14                   ; Tamper detect hours tens value bits, bit 2
IRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens3: .equ   15                   ; Tamper detect hours tens value bits, bit 3
; bit position masks
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units0: .equ   %00000001
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units1: .equ   %00000010
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units2: .equ   %00000100
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_units3: .equ   %00001000
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens0: .equ   %00010000
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens1: .equ   %00100000
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens2: .equ   %01000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_MINUTES_tens3: .equ   %10000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units0: .equ   %100000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units1: .equ   %1000000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units2: .equ   %10000000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_units3: .equ   %100000000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens0: .equ   %1000000000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens1: .equ   %10000000000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens2: .equ   %100000000000000
mIRTC_TTSR_HM_bcd_TIME_STAMP_HOURS_tens3: .equ   %1000000000000000


;*** IRTC_TTSR_HM_bin - RTC Tamper Time Stamp Hours & Minutes Register; 0xFFFF866E ***
IRTC_TTSR_HM_bin:   .equ   $FFFF866E                                ;*** IRTC_TTSR_HM_bin - RTC Tamper Time Stamp Hours & Minutes Register; 0xFFFF866E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_HM_bin_TIME_STAMP_MINUTES0: .equ   0                       ; Tamper detect minutes value bits, bit 0
IRTC_TTSR_HM_bin_TIME_STAMP_MINUTES1: .equ   1                       ; Tamper detect minutes value bits, bit 1
IRTC_TTSR_HM_bin_TIME_STAMP_MINUTES2: .equ   2                       ; Tamper detect minutes value bits, bit 2
IRTC_TTSR_HM_bin_TIME_STAMP_MINUTES3: .equ   3                       ; Tamper detect minutes value bits, bit 3
IRTC_TTSR_HM_bin_TIME_STAMP_MINUTES4: .equ   4                       ; Tamper detect minutes value bits, bit 4
IRTC_TTSR_HM_bin_TIME_STAMP_MINUTES5: .equ   5                       ; Tamper detect minutes value bits, bit 5
IRTC_TTSR_HM_bin_TIME_STAMP_HOURS0: .equ   8                         ; Tamper detect hours value bits, bit 0
IRTC_TTSR_HM_bin_TIME_STAMP_HOURS1: .equ   9                         ; Tamper detect hours value bits, bit 1
IRTC_TTSR_HM_bin_TIME_STAMP_HOURS2: .equ   10                        ; Tamper detect hours value bits, bit 2
IRTC_TTSR_HM_bin_TIME_STAMP_HOURS3: .equ   11                        ; Tamper detect hours value bits, bit 3
IRTC_TTSR_HM_bin_TIME_STAMP_HOURS4: .equ   12                        ; Tamper detect hours value bits, bit 4
; bit position masks
mIRTC_TTSR_HM_bin_TIME_STAMP_MINUTES0: .equ   %00000001
mIRTC_TTSR_HM_bin_TIME_STAMP_MINUTES1: .equ   %00000010
mIRTC_TTSR_HM_bin_TIME_STAMP_MINUTES2: .equ   %00000100
mIRTC_TTSR_HM_bin_TIME_STAMP_MINUTES3: .equ   %00001000
mIRTC_TTSR_HM_bin_TIME_STAMP_MINUTES4: .equ   %00010000
mIRTC_TTSR_HM_bin_TIME_STAMP_MINUTES5: .equ   %00100000
mIRTC_TTSR_HM_bin_TIME_STAMP_HOURS0: .equ   %100000000
mIRTC_TTSR_HM_bin_TIME_STAMP_HOURS1: .equ   %1000000000
mIRTC_TTSR_HM_bin_TIME_STAMP_HOURS2: .equ   %10000000000
mIRTC_TTSR_HM_bin_TIME_STAMP_HOURS3: .equ   %100000000000
mIRTC_TTSR_HM_bin_TIME_STAMP_HOURS4: .equ   %1000000000000


;*** IRTC_TTSR_SEC_bcd - RTC Tamper Time Stamp Seconds Register; 0xFFFF8670 ***
IRTC_TTSR_SEC_bcd:  .equ   $FFFF8670                                ;*** IRTC_TTSR_SEC_bcd - RTC Tamper Time Stamp Seconds Register; 0xFFFF8670 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units0: .equ   0                ; Tamper detect seconds units value bits, bit 0
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units1: .equ   1                ; Tamper detect seconds units value bits, bit 1
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units2: .equ   2                ; Tamper detect seconds units value bits, bit 2
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units3: .equ   3                ; Tamper detect seconds units value bits, bit 3
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens0: .equ   4                 ; Tamper detect seconds tens value bits, bit 0
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens1: .equ   5                 ; Tamper detect seconds tens value bits, bit 1
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens2: .equ   6                 ; Tamper detect seconds tens value bits, bit 2
IRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens3: .equ   7                 ; Tamper detect seconds tens value bits, bit 3
IRTC_TTSR_SEC_bcd_STATUS0: .equ   8                                  ; Tamper detect status bits, bit 0
IRTC_TTSR_SEC_bcd_STATUS1: .equ   9                                  ; Tamper detect status bits, bit 1
; bit position masks
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units0: .equ   %00000001
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units1: .equ   %00000010
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units2: .equ   %00000100
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_units3: .equ   %00001000
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens0: .equ   %00010000
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens1: .equ   %00100000
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens2: .equ   %01000000
mIRTC_TTSR_SEC_bcd_TIME_STAMP_SECONDS_tens3: .equ   %10000000
mIRTC_TTSR_SEC_bcd_STATUS0: .equ   %100000000
mIRTC_TTSR_SEC_bcd_STATUS1: .equ   %1000000000


;*** IRTC_TTSR_SEC_bin - RTC Tamper Time Stamp Seconds Register; 0xFFFF8670 ***
IRTC_TTSR_SEC_bin:  .equ   $FFFF8670                                ;*** IRTC_TTSR_SEC_bin - RTC Tamper Time Stamp Seconds Register; 0xFFFF8670 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS0: .equ   0                      ; Tamper detect seconds value bits, bit 0
IRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS1: .equ   1                      ; Tamper detect seconds value bits, bit 1
IRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS2: .equ   2                      ; Tamper detect seconds value bits, bit 2
IRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS3: .equ   3                      ; Tamper detect seconds value bits, bit 3
IRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS4: .equ   4                      ; Tamper detect seconds value bits, bit 4
IRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS5: .equ   5                      ; Tamper detect seconds value bits, bit 5
IRTC_TTSR_SEC_bin_STATUS0: .equ   8                                  ; Tamper detect status bits, bit 0
IRTC_TTSR_SEC_bin_STATUS1: .equ   9                                  ; Tamper detect status bits, bit 1
; bit position masks
mIRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS0: .equ   %00000001
mIRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS1: .equ   %00000010
mIRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS2: .equ   %00000100
mIRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS3: .equ   %00001000
mIRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS4: .equ   %00010000
mIRTC_TTSR_SEC_bin_TIME_STAMP_SECONDS5: .equ   %00100000
mIRTC_TTSR_SEC_bin_STATUS0: .equ   %100000000
mIRTC_TTSR_SEC_bin_STATUS1: .equ   %1000000000


;*** IRTC_UP_CNTR_H - RTC Up-Counter Higher Register; 0xFFFF8672 ***
IRTC_UP_CNTR_H:     .equ   $FFFF8672                                ;*** IRTC_UP_CNTR_H - RTC Up-Counter Higher Register; 0xFFFF8672 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_UP_CNTR_H_BYTE20: .equ   0                                      ; Up counter upper word byte 2, bit 0
IRTC_UP_CNTR_H_BYTE21: .equ   1                                      ; Up counter upper word byte 2, bit 1
IRTC_UP_CNTR_H_BYTE22: .equ   2                                      ; Up counter upper word byte 2, bit 2
IRTC_UP_CNTR_H_BYTE23: .equ   3                                      ; Up counter upper word byte 2, bit 3
IRTC_UP_CNTR_H_BYTE24: .equ   4                                      ; Up counter upper word byte 2, bit 4
IRTC_UP_CNTR_H_BYTE25: .equ   5                                      ; Up counter upper word byte 2, bit 5
IRTC_UP_CNTR_H_BYTE26: .equ   6                                      ; Up counter upper word byte 2, bit 6
IRTC_UP_CNTR_H_BYTE27: .equ   7                                      ; Up counter upper word byte 2, bit 7
IRTC_UP_CNTR_H_BYTE30: .equ   8                                      ; Up counter upper word byte 3, bit 0
IRTC_UP_CNTR_H_BYTE31: .equ   9                                      ; Up counter upper word byte 3, bit 1
IRTC_UP_CNTR_H_BYTE32: .equ   10                                     ; Up counter upper word byte 3, bit 2
IRTC_UP_CNTR_H_BYTE33: .equ   11                                     ; Up counter upper word byte 3, bit 3
IRTC_UP_CNTR_H_BYTE34: .equ   12                                     ; Up counter upper word byte 3, bit 4
IRTC_UP_CNTR_H_BYTE35: .equ   13                                     ; Up counter upper word byte 3, bit 5
IRTC_UP_CNTR_H_BYTE36: .equ   14                                     ; Up counter upper word byte 3, bit 6
IRTC_UP_CNTR_H_BYTE37: .equ   15                                     ; Up counter upper word byte 3, bit 7
; bit position masks
mIRTC_UP_CNTR_H_BYTE20: .equ   %00000001
mIRTC_UP_CNTR_H_BYTE21: .equ   %00000010
mIRTC_UP_CNTR_H_BYTE22: .equ   %00000100
mIRTC_UP_CNTR_H_BYTE23: .equ   %00001000
mIRTC_UP_CNTR_H_BYTE24: .equ   %00010000
mIRTC_UP_CNTR_H_BYTE25: .equ   %00100000
mIRTC_UP_CNTR_H_BYTE26: .equ   %01000000
mIRTC_UP_CNTR_H_BYTE27: .equ   %10000000
mIRTC_UP_CNTR_H_BYTE30: .equ   %100000000
mIRTC_UP_CNTR_H_BYTE31: .equ   %1000000000
mIRTC_UP_CNTR_H_BYTE32: .equ   %10000000000
mIRTC_UP_CNTR_H_BYTE33: .equ   %100000000000
mIRTC_UP_CNTR_H_BYTE34: .equ   %1000000000000
mIRTC_UP_CNTR_H_BYTE35: .equ   %10000000000000
mIRTC_UP_CNTR_H_BYTE36: .equ   %100000000000000
mIRTC_UP_CNTR_H_BYTE37: .equ   %1000000000000000


;*** IRTC_UP_CNTR_L - RTC Up-Counter Lower Register; 0xFFFF8674 ***
IRTC_UP_CNTR_L:     .equ   $FFFF8674                                ;*** IRTC_UP_CNTR_L - RTC Up-Counter Lower Register; 0xFFFF8674 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_UP_CNTR_L_BYTE00: .equ   0                                      ; Up counter upper word byte 0, bit 0
IRTC_UP_CNTR_L_BYTE01: .equ   1                                      ; Up counter upper word byte 0, bit 1
IRTC_UP_CNTR_L_BYTE02: .equ   2                                      ; Up counter upper word byte 0, bit 2
IRTC_UP_CNTR_L_BYTE03: .equ   3                                      ; Up counter upper word byte 0, bit 3
IRTC_UP_CNTR_L_BYTE04: .equ   4                                      ; Up counter upper word byte 0, bit 4
IRTC_UP_CNTR_L_BYTE05: .equ   5                                      ; Up counter upper word byte 0, bit 5
IRTC_UP_CNTR_L_BYTE06: .equ   6                                      ; Up counter upper word byte 0, bit 6
IRTC_UP_CNTR_L_BYTE07: .equ   7                                      ; Up counter upper word byte 0, bit 7
IRTC_UP_CNTR_L_BYTE10: .equ   8                                      ; Up counter upper word byte 1, bit 0
IRTC_UP_CNTR_L_BYTE11: .equ   9                                      ; Up counter upper word byte 1, bit 1
IRTC_UP_CNTR_L_BYTE12: .equ   10                                     ; Up counter upper word byte 1, bit 2
IRTC_UP_CNTR_L_BYTE13: .equ   11                                     ; Up counter upper word byte 1, bit 3
IRTC_UP_CNTR_L_BYTE14: .equ   12                                     ; Up counter upper word byte 1, bit 4
IRTC_UP_CNTR_L_BYTE15: .equ   13                                     ; Up counter upper word byte 1, bit 5
IRTC_UP_CNTR_L_BYTE16: .equ   14                                     ; Up counter upper word byte 1, bit 6
IRTC_UP_CNTR_L_BYTE17: .equ   15                                     ; Up counter upper word byte 1, bit 7
; bit position masks
mIRTC_UP_CNTR_L_BYTE00: .equ   %00000001
mIRTC_UP_CNTR_L_BYTE01: .equ   %00000010
mIRTC_UP_CNTR_L_BYTE02: .equ   %00000100
mIRTC_UP_CNTR_L_BYTE03: .equ   %00001000
mIRTC_UP_CNTR_L_BYTE04: .equ   %00010000
mIRTC_UP_CNTR_L_BYTE05: .equ   %00100000
mIRTC_UP_CNTR_L_BYTE06: .equ   %01000000
mIRTC_UP_CNTR_L_BYTE07: .equ   %10000000
mIRTC_UP_CNTR_L_BYTE10: .equ   %100000000
mIRTC_UP_CNTR_L_BYTE11: .equ   %1000000000
mIRTC_UP_CNTR_L_BYTE12: .equ   %10000000000
mIRTC_UP_CNTR_L_BYTE13: .equ   %100000000000
mIRTC_UP_CNTR_L_BYTE14: .equ   %1000000000000
mIRTC_UP_CNTR_L_BYTE15: .equ   %10000000000000
mIRTC_UP_CNTR_L_BYTE16: .equ   %100000000000000
mIRTC_UP_CNTR_L_BYTE17: .equ   %1000000000000000


;*** LCDC0 - LCD Control Register 0; 0xFFFF8700 ***
LCDC0:              .equ   $FFFF8700                                ;*** LCDC0 - LCD Control Register 0; 0xFFFF8700 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDC0_DUTY0:        .equ   0                                         ; LCD Duty Select Bit 0
LCDC0_DUTY1:        .equ   1                                         ; LCD Duty Select Bit 1
LCDC0_DUTY2:        .equ   2                                         ; LCD Duty Select Bit 2
LCDC0_LCLK0:        .equ   3                                         ; LCD Clock Prescaler Bit 0
LCDC0_LCLK1:        .equ   4                                         ; LCD Clock Prescaler Bit 1
LCDC0_LCLK2:        .equ   5                                         ; LCD Clock Prescaler Bit 2
LCDC0_SOURCE:       .equ   6                                         ; LCD Clock Source Select
LCDC0_LCDEN:        .equ   7                                         ; LCD Driver Enable
; bit position masks
mLCDC0_DUTY0:       .equ   %00000001
mLCDC0_DUTY1:       .equ   %00000010
mLCDC0_DUTY2:       .equ   %00000100
mLCDC0_LCLK0:       .equ   %00001000
mLCDC0_LCLK1:       .equ   %00010000
mLCDC0_LCLK2:       .equ   %00100000
mLCDC0_SOURCE:      .equ   %01000000
mLCDC0_LCDEN:       .equ   %10000000


;*** LCDC1 - LCD Control Register 1; 0xFFFF8701 ***
LCDC1:              .equ   $FFFF8701                                ;*** LCDC1 - LCD Control Register 1; 0xFFFF8701 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDC1_LCDSTP:       .equ   0                                         ; LCD Module Driver and Charge Pump Stop While in Stop2 or Stop3 Mode
LCDC1_LCDWAI:       .equ   1                                         ; LCD Module Driver and Charge Pump Stop While in Wait Mode
LCDC1_FCDEN:        .equ   2                                         ; Full Complementary Drive Enable
LCDC1_LCDIEN:       .equ   7                                         ; LCD Module Frame Frequency Interrupt Enable
; bit position masks
mLCDC1_LCDSTP:      .equ   %00000001
mLCDC1_LCDWAI:      .equ   %00000010
mLCDC1_FCDEN:       .equ   %00000100
mLCDC1_LCDIEN:      .equ   %10000000


;*** LCDSUPPLY - LCD Voltage Supply Register; 0xFFFF8702 ***
LCDSUPPLY:          .equ   $FFFF8702                                ;*** LCDSUPPLY - LCD Voltage Supply Register; 0xFFFF8702 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDSUPPLY_VSUPPLY0: .equ   0                                         ; Voltage Supply Control Bit 0
LCDSUPPLY_VSUPPLY1: .equ   1                                         ; Voltage Supply Control Bit 1
LCDSUPPLY_BBYPASS:  .equ   2                                         ; Op Amp Control
LCDSUPPLY_LADJ0:    .equ   4                                         ; LCD Module Load Adjust Bit 0
LCDSUPPLY_LADJ1:    .equ   5                                         ; LCD Module Load Adjust Bit 1
LCDSUPPLY_HREFSEL:  .equ   6                                         ; High Reference Select
LCDSUPPLY_CPSEL:    .equ   7                                         ; Charge Pump or Resistor Bias Select
; bit position masks
mLCDSUPPLY_VSUPPLY0: .equ   %00000001
mLCDSUPPLY_VSUPPLY1: .equ   %00000010
mLCDSUPPLY_BBYPASS: .equ   %00000100
mLCDSUPPLY_LADJ0:   .equ   %00010000
mLCDSUPPLY_LADJ1:   .equ   %00100000
mLCDSUPPLY_HREFSEL: .equ   %01000000
mLCDSUPPLY_CPSEL:   .equ   %10000000


;*** LCDRVC - LCD Regulated Voltage Control Register; 0xFFFF8703 ***
LCDRVC:             .equ   $FFFF8703                                ;*** LCDRVC - LCD Regulated Voltage Control Register; 0xFFFF8703 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRVC_RVTRIM0:     .equ   0                                         ; Regulated Voltage Trim Bit 0
LCDRVC_RVTRIM1:     .equ   1                                         ; Regulated Voltage Trim Bit 1
LCDRVC_RVTRIM2:     .equ   2                                         ; Regulated Voltage Trim Bit 2
LCDRVC_RVTRIM3:     .equ   3                                         ; Regulated Voltage Trim Bit 3
LCDRVC_RVEN:        .equ   7                                         ; Regulated Voltage Enable
; bit position masks
mLCDRVC_RVTRIM0:    .equ   %00000001
mLCDRVC_RVTRIM1:    .equ   %00000010
mLCDRVC_RVTRIM2:    .equ   %00000100
mLCDRVC_RVTRIM3:    .equ   %00001000
mLCDRVC_RVEN:       .equ   %10000000


;*** LCDBCTL - LCD Blink Control Register; 0xFFFF8704 ***
LCDBCTL:            .equ   $FFFF8704                                ;*** LCDBCTL - LCD Blink Control Register; 0xFFFF8704 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBCTL_BRATE0:     .equ   0                                         ; Blink-Rate Configuration Bit 0
LCDBCTL_BRATE1:     .equ   1                                         ; Blink-Rate Configuration Bit 1
LCDBCTL_BRATE2:     .equ   2                                         ; Blink-Rate Configuration Bit 2
LCDBCTL_BMODE:      .equ   3                                         ; Blink Mode
LCDBCTL_BLANK:      .equ   5                                         ; Blank Display Mode
LCDBCTL_ALT:        .equ   6                                         ; Alternate Display Mode
LCDBCTL_BLINK:      .equ   7                                         ; Blink Command
; bit position masks
mLCDBCTL_BRATE0:    .equ   %00000001
mLCDBCTL_BRATE1:    .equ   %00000010
mLCDBCTL_BRATE2:    .equ   %00000100
mLCDBCTL_BMODE:     .equ   %00001000
mLCDBCTL_BLANK:     .equ   %00100000
mLCDBCTL_ALT:       .equ   %01000000
mLCDBCTL_BLINK:     .equ   %10000000


;*** LCDS - LCD Status Register; 0xFFFF8705 ***
LCDS:               .equ   $FFFF8705                                ;*** LCDS - LCD Status Register; 0xFFFF8705 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDS_LCDIF:         .equ   7                                         ; LCD Interrupt Flag
; bit position masks
mLCDS_LCDIF:        .equ   %10000000


;*** LCDPEN0 - LCD Pin Enable Register 0; 0xFFFF8706 ***
LCDPEN0:            .equ   $FFFF8706                                ;*** LCDPEN0 - LCD Pin Enable Register 0; 0xFFFF8706 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN0_PEN0:       .equ   0                                         ; Enable LCD pin 0 for LCD operation
LCDPEN0_PEN1:       .equ   1                                         ; Enable LCD pin 1 for LCD operation
LCDPEN0_PEN2:       .equ   2                                         ; Enable LCD pin 2 for LCD operation
LCDPEN0_PEN3:       .equ   3                                         ; Enable LCD pin 3 for LCD operation
LCDPEN0_PEN4:       .equ   4                                         ; Enable LCD pin 4 for LCD operation
LCDPEN0_PEN5:       .equ   5                                         ; Enable LCD pin 5 for LCD operation
LCDPEN0_PEN6:       .equ   6                                         ; Enable LCD pin 6 for LCD operation
LCDPEN0_PEN7:       .equ   7                                         ; Enable LCD pin 7 for LCD operation
; bit position masks
mLCDPEN0_PEN0:      .equ   %00000001
mLCDPEN0_PEN1:      .equ   %00000010
mLCDPEN0_PEN2:      .equ   %00000100
mLCDPEN0_PEN3:      .equ   %00001000
mLCDPEN0_PEN4:      .equ   %00010000
mLCDPEN0_PEN5:      .equ   %00100000
mLCDPEN0_PEN6:      .equ   %01000000
mLCDPEN0_PEN7:      .equ   %10000000


;*** LCDPEN1 - LCD Pin Enable Register 1; 0xFFFF8707 ***
LCDPEN1:            .equ   $FFFF8707                                ;*** LCDPEN1 - LCD Pin Enable Register 1; 0xFFFF8707 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN1_PEN8:       .equ   0                                         ; Enable LCD pin 8 for LCD operation
LCDPEN1_PEN9:       .equ   1                                         ; Enable LCD pin 9 for LCD operation
LCDPEN1_PEN10:      .equ   2                                         ; Enable LCD pin 10 for LCD operation
LCDPEN1_PEN11:      .equ   3                                         ; Enable LCD pin 11 for LCD operation
LCDPEN1_PEN12:      .equ   4                                         ; Enable LCD pin 12 for LCD operation
LCDPEN1_PEN13:      .equ   5                                         ; Enable LCD pin 13 for LCD operation
LCDPEN1_PEN14:      .equ   6                                         ; Enable LCD pin 14 for LCD operation
LCDPEN1_PEN15:      .equ   7                                         ; Enable LCD pin 15 for LCD operation
; bit position masks
mLCDPEN1_PEN8:      .equ   %00000001
mLCDPEN1_PEN9:      .equ   %00000010
mLCDPEN1_PEN10:     .equ   %00000100
mLCDPEN1_PEN11:     .equ   %00001000
mLCDPEN1_PEN12:     .equ   %00010000
mLCDPEN1_PEN13:     .equ   %00100000
mLCDPEN1_PEN14:     .equ   %01000000
mLCDPEN1_PEN15:     .equ   %10000000


;*** LCDPEN2 - LCD Pin Enable Register 2; 0xFFFF8708 ***
LCDPEN2:            .equ   $FFFF8708                                ;*** LCDPEN2 - LCD Pin Enable Register 2; 0xFFFF8708 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN2_PEN16:      .equ   0                                         ; Enable LCD pin 16 for LCD operation
LCDPEN2_PEN17:      .equ   1                                         ; Enable LCD pin 17 for LCD operation
LCDPEN2_PEN18:      .equ   2                                         ; Enable LCD pin 18 for LCD operation
LCDPEN2_PEN19:      .equ   3                                         ; Enable LCD pin 19 for LCD operation
LCDPEN2_PEN20:      .equ   4                                         ; Enable LCD pin 20 for LCD operation
LCDPEN2_PEN21:      .equ   5                                         ; Enable LCD pin 21 for LCD operation
LCDPEN2_PEN22:      .equ   6                                         ; Enable LCD pin 22 for LCD operation
LCDPEN2_PEN23:      .equ   7                                         ; Enable LCD pin 23 for LCD operation
; bit position masks
mLCDPEN2_PEN16:     .equ   %00000001
mLCDPEN2_PEN17:     .equ   %00000010
mLCDPEN2_PEN18:     .equ   %00000100
mLCDPEN2_PEN19:     .equ   %00001000
mLCDPEN2_PEN20:     .equ   %00010000
mLCDPEN2_PEN21:     .equ   %00100000
mLCDPEN2_PEN22:     .equ   %01000000
mLCDPEN2_PEN23:     .equ   %10000000


;*** LCDPEN3 - LCD Pin Enable Register 3; 0xFFFF8709 ***
LCDPEN3:            .equ   $FFFF8709                                ;*** LCDPEN3 - LCD Pin Enable Register 3; 0xFFFF8709 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN3_PEN24:      .equ   0                                         ; Enable LCD pin 24 for LCD operation
LCDPEN3_PEN25:      .equ   1                                         ; Enable LCD pin 25 for LCD operation
LCDPEN3_PEN26:      .equ   2                                         ; Enable LCD pin 26 for LCD operation
LCDPEN3_PEN27:      .equ   3                                         ; Enable LCD pin 27 for LCD operation
LCDPEN3_PEN28:      .equ   4                                         ; Enable LCD pin 28 for LCD operation
LCDPEN3_PEN29:      .equ   5                                         ; Enable LCD pin 29 for LCD operation
LCDPEN3_PEN30:      .equ   6                                         ; Enable LCD pin 30 for LCD operation
LCDPEN3_PEN31:      .equ   7                                         ; Enable LCD pin 31 for LCD operation
; bit position masks
mLCDPEN3_PEN24:     .equ   %00000001
mLCDPEN3_PEN25:     .equ   %00000010
mLCDPEN3_PEN26:     .equ   %00000100
mLCDPEN3_PEN27:     .equ   %00001000
mLCDPEN3_PEN28:     .equ   %00010000
mLCDPEN3_PEN29:     .equ   %00100000
mLCDPEN3_PEN30:     .equ   %01000000
mLCDPEN3_PEN31:     .equ   %10000000


;*** LCDPEN4 - LCD Pin Enable Register 4; 0xFFFF870A ***
LCDPEN4:            .equ   $FFFF870A                                ;*** LCDPEN4 - LCD Pin Enable Register 4; 0xFFFF870A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN4_PEN32:      .equ   0                                         ; Enable LCD pin 32 for LCD operation
LCDPEN4_PEN33:      .equ   1                                         ; Enable LCD pin 33 for LCD operation
LCDPEN4_PEN34:      .equ   2                                         ; Enable LCD pin 34 for LCD operation
LCDPEN4_PEN35:      .equ   3                                         ; Enable LCD pin 35 for LCD operation
LCDPEN4_PEN36:      .equ   4                                         ; Enable LCD pin 36 for LCD operation
LCDPEN4_PEN37:      .equ   5                                         ; Enable LCD pin 37 for LCD operation
LCDPEN4_PEN38:      .equ   6                                         ; Enable LCD pin 38 for LCD operation
LCDPEN4_PEN39:      .equ   7                                         ; Enable LCD pin 39 for LCD operation
; bit position masks
mLCDPEN4_PEN32:     .equ   %00000001
mLCDPEN4_PEN33:     .equ   %00000010
mLCDPEN4_PEN34:     .equ   %00000100
mLCDPEN4_PEN35:     .equ   %00001000
mLCDPEN4_PEN36:     .equ   %00010000
mLCDPEN4_PEN37:     .equ   %00100000
mLCDPEN4_PEN38:     .equ   %01000000
mLCDPEN4_PEN39:     .equ   %10000000


;*** LCDPEN5 - LCD Pin Enable Register 5; 0xFFFF870B ***
LCDPEN5:            .equ   $FFFF870B                                ;*** LCDPEN5 - LCD Pin Enable Register 5; 0xFFFF870B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN5_PEN40:      .equ   0                                         ; Enable LCD pin 40 for LCD operation
LCDPEN5_PEN41:      .equ   1                                         ; Enable LCD pin 41 for LCD operation
LCDPEN5_PEN42:      .equ   2                                         ; Enable LCD pin 42 for LCD operation
LCDPEN5_PEN43:      .equ   3                                         ; Enable LCD pin 43 for LCD operation
; bit position masks
mLCDPEN5_PEN40:     .equ   %00000001
mLCDPEN5_PEN41:     .equ   %00000010
mLCDPEN5_PEN42:     .equ   %00000100
mLCDPEN5_PEN43:     .equ   %00001000


;*** LCDBPEN0 - LCD Backplane Enable Register 0; 0xFFFF870E ***
LCDBPEN0:           .equ   $FFFF870E                                ;*** LCDBPEN0 - LCD Backplane Enable Register 0; 0xFFFF870E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN0_BPEN0:     .equ   0                                         ; Enable LCD pin 0 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN1:     .equ   1                                         ; Enable LCD pin 1 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN2:     .equ   2                                         ; Enable LCD pin 2 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN3:     .equ   3                                         ; Enable LCD pin 3 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN4:     .equ   4                                         ; Enable LCD pin 4 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN5:     .equ   5                                         ; Enable LCD pin 5 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN6:     .equ   6                                         ; Enable LCD pin 6 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN7:     .equ   7                                         ; Enable LCD pin 7 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN0_BPEN0:    .equ   %00000001
mLCDBPEN0_BPEN1:    .equ   %00000010
mLCDBPEN0_BPEN2:    .equ   %00000100
mLCDBPEN0_BPEN3:    .equ   %00001000
mLCDBPEN0_BPEN4:    .equ   %00010000
mLCDBPEN0_BPEN5:    .equ   %00100000
mLCDBPEN0_BPEN6:    .equ   %01000000
mLCDBPEN0_BPEN7:    .equ   %10000000


;*** LCDBPEN1 - LCD Backplane Enable Register 1; 0xFFFF870F ***
LCDBPEN1:           .equ   $FFFF870F                                ;*** LCDBPEN1 - LCD Backplane Enable Register 1; 0xFFFF870F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN1_BPEN8:     .equ   0                                         ; Enable LCD pin 8 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN9:     .equ   1                                         ; Enable LCD pin 9 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN10:    .equ   2                                         ; Enable LCD pin 10 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN11:    .equ   3                                         ; Enable LCD pin 11 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN12:    .equ   4                                         ; Enable LCD pin 12 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN13:    .equ   5                                         ; Enable LCD pin 13 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN14:    .equ   6                                         ; Enable LCD pin 14 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN15:    .equ   7                                         ; Enable LCD pin 15 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN1_BPEN8:    .equ   %00000001
mLCDBPEN1_BPEN9:    .equ   %00000010
mLCDBPEN1_BPEN10:   .equ   %00000100
mLCDBPEN1_BPEN11:   .equ   %00001000
mLCDBPEN1_BPEN12:   .equ   %00010000
mLCDBPEN1_BPEN13:   .equ   %00100000
mLCDBPEN1_BPEN14:   .equ   %01000000
mLCDBPEN1_BPEN15:   .equ   %10000000


;*** LCDBPEN2 - LCD Backplane Enable Register 2; 0xFFFF8710 ***
LCDBPEN2:           .equ   $FFFF8710                                ;*** LCDBPEN2 - LCD Backplane Enable Register 2; 0xFFFF8710 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN2_BPEN16:    .equ   0                                         ; Enable LCD pin 16 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN17:    .equ   1                                         ; Enable LCD pin 17 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN18:    .equ   2                                         ; Enable LCD pin 18 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN19:    .equ   3                                         ; Enable LCD pin 19 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN20:    .equ   4                                         ; Enable LCD pin 20 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN21:    .equ   5                                         ; Enable LCD pin 21 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN22:    .equ   6                                         ; Enable LCD pin 22 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN23:    .equ   7                                         ; Enable LCD pin 23 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN2_BPEN16:   .equ   %00000001
mLCDBPEN2_BPEN17:   .equ   %00000010
mLCDBPEN2_BPEN18:   .equ   %00000100
mLCDBPEN2_BPEN19:   .equ   %00001000
mLCDBPEN2_BPEN20:   .equ   %00010000
mLCDBPEN2_BPEN21:   .equ   %00100000
mLCDBPEN2_BPEN22:   .equ   %01000000
mLCDBPEN2_BPEN23:   .equ   %10000000


;*** LCDBPEN3 - LCD Backplane Enable Register 3; 0xFFFF8711 ***
LCDBPEN3:           .equ   $FFFF8711                                ;*** LCDBPEN3 - LCD Backplane Enable Register 3; 0xFFFF8711 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN3_BPEN24:    .equ   0                                         ; Enable LCD pin 24 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN25:    .equ   1                                         ; Enable LCD pin 25 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN26:    .equ   2                                         ; Enable LCD pin 26 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN27:    .equ   3                                         ; Enable LCD pin 27 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN28:    .equ   4                                         ; Enable LCD pin 28 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN29:    .equ   5                                         ; Enable LCD pin 29 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN30:    .equ   6                                         ; Enable LCD pin 30 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN31:    .equ   7                                         ; Enable LCD pin 31 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN3_BPEN24:   .equ   %00000001
mLCDBPEN3_BPEN25:   .equ   %00000010
mLCDBPEN3_BPEN26:   .equ   %00000100
mLCDBPEN3_BPEN27:   .equ   %00001000
mLCDBPEN3_BPEN28:   .equ   %00010000
mLCDBPEN3_BPEN29:   .equ   %00100000
mLCDBPEN3_BPEN30:   .equ   %01000000
mLCDBPEN3_BPEN31:   .equ   %10000000


;*** LCDBPEN4 - LCD Backplane Enable Register 4; 0xFFFF8712 ***
LCDBPEN4:           .equ   $FFFF8712                                ;*** LCDBPEN4 - LCD Backplane Enable Register 4; 0xFFFF8712 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN4_BPEN32:    .equ   0                                         ; Enable LCD pin 32 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN33:    .equ   1                                         ; Enable LCD pin 33 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN34:    .equ   2                                         ; Enable LCD pin 34 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN35:    .equ   3                                         ; Enable LCD pin 35 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN36:    .equ   4                                         ; Enable LCD pin 36 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN37:    .equ   5                                         ; Enable LCD pin 37 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN38:    .equ   6                                         ; Enable LCD pin 38 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN39:    .equ   7                                         ; Enable LCD pin 39 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN4_BPEN32:   .equ   %00000001
mLCDBPEN4_BPEN33:   .equ   %00000010
mLCDBPEN4_BPEN34:   .equ   %00000100
mLCDBPEN4_BPEN35:   .equ   %00001000
mLCDBPEN4_BPEN36:   .equ   %00010000
mLCDBPEN4_BPEN37:   .equ   %00100000
mLCDBPEN4_BPEN38:   .equ   %01000000
mLCDBPEN4_BPEN39:   .equ   %10000000


;*** LCDBPEN5 - LCD Backplane Enable Register 5; 0xFFFF8713 ***
LCDBPEN5:           .equ   $FFFF8713                                ;*** LCDBPEN5 - LCD Backplane Enable Register 5; 0xFFFF8713 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN5_BPEN40:    .equ   0                                         ; Enable LCD pin 40 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN41:    .equ   1                                         ; Enable LCD pin 41 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN42:    .equ   2                                         ; Enable LCD pin 42 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN43:    .equ   3                                         ; Enable LCD pin 43 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN5_BPEN40:   .equ   %00000001
mLCDBPEN5_BPEN41:   .equ   %00000010
mLCDBPEN5_BPEN42:   .equ   %00000100
mLCDBPEN5_BPEN43:   .equ   %00001000


;*** LCDWF0 - LCD Waveform Register 0; 0xFFFF8716 ***
LCDWF0:             .equ   $FFFF8716                                ;*** LCDWF0 - LCD Waveform Register 0; 0xFFFF8716 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF0_BPALCD0:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPBLCD0:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPCLCD0:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPDLCD0:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPELCD0:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPFLCD0:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPGLCD0:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPHLCD0:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF0_BPALCD0:    .equ   %00000001
mLCDWF0_BPBLCD0:    .equ   %00000010
mLCDWF0_BPCLCD0:    .equ   %00000100
mLCDWF0_BPDLCD0:    .equ   %00001000
mLCDWF0_BPELCD0:    .equ   %00010000
mLCDWF0_BPFLCD0:    .equ   %00100000
mLCDWF0_BPGLCD0:    .equ   %01000000
mLCDWF0_BPHLCD0:    .equ   %10000000


;*** LCDWF1 - LCD Waveform Register 1; 0xFFFF8717 ***
LCDWF1:             .equ   $FFFF8717                                ;*** LCDWF1 - LCD Waveform Register 1; 0xFFFF8717 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF1_BPALCD1:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPBLCD1:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPCLCD1:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPDLCD1:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPELCD1:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPFLCD1:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPGLCD1:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPHLCD1:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF1_BPALCD1:    .equ   %00000001
mLCDWF1_BPBLCD1:    .equ   %00000010
mLCDWF1_BPCLCD1:    .equ   %00000100
mLCDWF1_BPDLCD1:    .equ   %00001000
mLCDWF1_BPELCD1:    .equ   %00010000
mLCDWF1_BPFLCD1:    .equ   %00100000
mLCDWF1_BPGLCD1:    .equ   %01000000
mLCDWF1_BPHLCD1:    .equ   %10000000


;*** LCDWF2 - LCD Waveform Register 2; 0xFFFF8718 ***
LCDWF2:             .equ   $FFFF8718                                ;*** LCDWF2 - LCD Waveform Register 2; 0xFFFF8718 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF2_BPALCD2:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPBLCD2:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPCLCD2:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPDLCD2:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPELCD2:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPFLCD2:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPGLCD2:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPHLCD2:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF2_BPALCD2:    .equ   %00000001
mLCDWF2_BPBLCD2:    .equ   %00000010
mLCDWF2_BPCLCD2:    .equ   %00000100
mLCDWF2_BPDLCD2:    .equ   %00001000
mLCDWF2_BPELCD2:    .equ   %00010000
mLCDWF2_BPFLCD2:    .equ   %00100000
mLCDWF2_BPGLCD2:    .equ   %01000000
mLCDWF2_BPHLCD2:    .equ   %10000000


;*** LCDWF3 - LCD Waveform Register 3; 0xFFFF8719 ***
LCDWF3:             .equ   $FFFF8719                                ;*** LCDWF3 - LCD Waveform Register 3; 0xFFFF8719 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF3_BPALCD3:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPBLCD3:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPCLCD3:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPDLCD3:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPELCD3:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPFLCD3:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPGLCD3:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPHLCD3:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF3_BPALCD3:    .equ   %00000001
mLCDWF3_BPBLCD3:    .equ   %00000010
mLCDWF3_BPCLCD3:    .equ   %00000100
mLCDWF3_BPDLCD3:    .equ   %00001000
mLCDWF3_BPELCD3:    .equ   %00010000
mLCDWF3_BPFLCD3:    .equ   %00100000
mLCDWF3_BPGLCD3:    .equ   %01000000
mLCDWF3_BPHLCD3:    .equ   %10000000


;*** LCDWF4 - LCD Waveform Register 4; 0xFFFF871A ***
LCDWF4:             .equ   $FFFF871A                                ;*** LCDWF4 - LCD Waveform Register 4; 0xFFFF871A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF4_BPALCD4:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPBLCD4:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPCLCD4:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPDLCD4:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPELCD4:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPFLCD4:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPGLCD4:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPHLCD4:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF4_BPALCD4:    .equ   %00000001
mLCDWF4_BPBLCD4:    .equ   %00000010
mLCDWF4_BPCLCD4:    .equ   %00000100
mLCDWF4_BPDLCD4:    .equ   %00001000
mLCDWF4_BPELCD4:    .equ   %00010000
mLCDWF4_BPFLCD4:    .equ   %00100000
mLCDWF4_BPGLCD4:    .equ   %01000000
mLCDWF4_BPHLCD4:    .equ   %10000000


;*** LCDWF5 - LCD Waveform Register 5; 0xFFFF871B ***
LCDWF5:             .equ   $FFFF871B                                ;*** LCDWF5 - LCD Waveform Register 5; 0xFFFF871B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF5_BPALCD5:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPBLCD5:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPCLCD5:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPDLCD5:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPELCD5:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPFLCD5:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPGLCD5:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPHLCD5:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF5_BPALCD5:    .equ   %00000001
mLCDWF5_BPBLCD5:    .equ   %00000010
mLCDWF5_BPCLCD5:    .equ   %00000100
mLCDWF5_BPDLCD5:    .equ   %00001000
mLCDWF5_BPELCD5:    .equ   %00010000
mLCDWF5_BPFLCD5:    .equ   %00100000
mLCDWF5_BPGLCD5:    .equ   %01000000
mLCDWF5_BPHLCD5:    .equ   %10000000


;*** LCDWF6 - LCD Waveform Register 6; 0xFFFF871C ***
LCDWF6:             .equ   $FFFF871C                                ;*** LCDWF6 - LCD Waveform Register 6; 0xFFFF871C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF6_BPALCD6:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPBLCD6:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPCLCD6:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPDLCD6:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPELCD6:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPFLCD6:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPGLCD6:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPHLCD6:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF6_BPALCD6:    .equ   %00000001
mLCDWF6_BPBLCD6:    .equ   %00000010
mLCDWF6_BPCLCD6:    .equ   %00000100
mLCDWF6_BPDLCD6:    .equ   %00001000
mLCDWF6_BPELCD6:    .equ   %00010000
mLCDWF6_BPFLCD6:    .equ   %00100000
mLCDWF6_BPGLCD6:    .equ   %01000000
mLCDWF6_BPHLCD6:    .equ   %10000000


;*** LCDWF7 - LCD Waveform Register 7; 0xFFFF871D ***
LCDWF7:             .equ   $FFFF871D                                ;*** LCDWF7 - LCD Waveform Register 7; 0xFFFF871D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF7_BPALCD7:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPBLCD7:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPCLCD7:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPDLCD7:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPELCD7:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPFLCD7:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPGLCD7:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPHLCD7:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF7_BPALCD7:    .equ   %00000001
mLCDWF7_BPBLCD7:    .equ   %00000010
mLCDWF7_BPCLCD7:    .equ   %00000100
mLCDWF7_BPDLCD7:    .equ   %00001000
mLCDWF7_BPELCD7:    .equ   %00010000
mLCDWF7_BPFLCD7:    .equ   %00100000
mLCDWF7_BPGLCD7:    .equ   %01000000
mLCDWF7_BPHLCD7:    .equ   %10000000


;*** LCDWF8 - LCD Waveform Register 8; 0xFFFF871E ***
LCDWF8:             .equ   $FFFF871E                                ;*** LCDWF8 - LCD Waveform Register 8; 0xFFFF871E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF8_BPALCD8:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPBLCD8:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPCLCD8:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPDLCD8:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPELCD8:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPFLCD8:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPGLCD8:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPHLCD8:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF8_BPALCD8:    .equ   %00000001
mLCDWF8_BPBLCD8:    .equ   %00000010
mLCDWF8_BPCLCD8:    .equ   %00000100
mLCDWF8_BPDLCD8:    .equ   %00001000
mLCDWF8_BPELCD8:    .equ   %00010000
mLCDWF8_BPFLCD8:    .equ   %00100000
mLCDWF8_BPGLCD8:    .equ   %01000000
mLCDWF8_BPHLCD8:    .equ   %10000000


;*** LCDWF9 - LCD Waveform Register 9; 0xFFFF871F ***
LCDWF9:             .equ   $FFFF871F                                ;*** LCDWF9 - LCD Waveform Register 9; 0xFFFF871F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF9_BPALCD9:     .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPBLCD9:     .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPCLCD9:     .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPDLCD9:     .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPELCD9:     .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPFLCD9:     .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPGLCD9:     .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPHLCD9:     .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF9_BPALCD9:    .equ   %00000001
mLCDWF9_BPBLCD9:    .equ   %00000010
mLCDWF9_BPCLCD9:    .equ   %00000100
mLCDWF9_BPDLCD9:    .equ   %00001000
mLCDWF9_BPELCD9:    .equ   %00010000
mLCDWF9_BPFLCD9:    .equ   %00100000
mLCDWF9_BPGLCD9:    .equ   %01000000
mLCDWF9_BPHLCD9:    .equ   %10000000


;*** LCDWF10 - LCD Waveform Register 10; 0xFFFF8720 ***
LCDWF10:            .equ   $FFFF8720                                ;*** LCDWF10 - LCD Waveform Register 10; 0xFFFF8720 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF10_BPALCD10:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPBLCD10:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPCLCD10:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPDLCD10:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPELCD10:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPFLCD10:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPGLCD10:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPHLCD10:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF10_BPALCD10:  .equ   %00000001
mLCDWF10_BPBLCD10:  .equ   %00000010
mLCDWF10_BPCLCD10:  .equ   %00000100
mLCDWF10_BPDLCD10:  .equ   %00001000
mLCDWF10_BPELCD10:  .equ   %00010000
mLCDWF10_BPFLCD10:  .equ   %00100000
mLCDWF10_BPGLCD10:  .equ   %01000000
mLCDWF10_BPHLCD10:  .equ   %10000000


;*** LCDWF11 - LCD Waveform Register 11; 0xFFFF8721 ***
LCDWF11:            .equ   $FFFF8721                                ;*** LCDWF11 - LCD Waveform Register 11; 0xFFFF8721 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF11_BPALCD11:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPBLCD11:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPCLCD11:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPDLCD11:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPELCD11:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPFLCD11:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPGLCD11:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPHLCD11:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF11_BPALCD11:  .equ   %00000001
mLCDWF11_BPBLCD11:  .equ   %00000010
mLCDWF11_BPCLCD11:  .equ   %00000100
mLCDWF11_BPDLCD11:  .equ   %00001000
mLCDWF11_BPELCD11:  .equ   %00010000
mLCDWF11_BPFLCD11:  .equ   %00100000
mLCDWF11_BPGLCD11:  .equ   %01000000
mLCDWF11_BPHLCD11:  .equ   %10000000


;*** LCDWF12 - LCD Waveform Register 12; 0xFFFF8722 ***
LCDWF12:            .equ   $FFFF8722                                ;*** LCDWF12 - LCD Waveform Register 12; 0xFFFF8722 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF12_BPALCD12:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPBLCD12:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPCLCD12:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPDLCD12:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPELCD12:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPFLCD12:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPGLCD12:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPHLCD12:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF12_BPALCD12:  .equ   %00000001
mLCDWF12_BPBLCD12:  .equ   %00000010
mLCDWF12_BPCLCD12:  .equ   %00000100
mLCDWF12_BPDLCD12:  .equ   %00001000
mLCDWF12_BPELCD12:  .equ   %00010000
mLCDWF12_BPFLCD12:  .equ   %00100000
mLCDWF12_BPGLCD12:  .equ   %01000000
mLCDWF12_BPHLCD12:  .equ   %10000000


;*** LCDWF13 - LCD Waveform Register 13; 0xFFFF8723 ***
LCDWF13:            .equ   $FFFF8723                                ;*** LCDWF13 - LCD Waveform Register 13; 0xFFFF8723 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF13_BPALCD13:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPBLCD13:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPCLCD13:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPDLCD13:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPELCD13:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPFLCD13:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPGLCD13:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPHLCD13:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF13_BPALCD13:  .equ   %00000001
mLCDWF13_BPBLCD13:  .equ   %00000010
mLCDWF13_BPCLCD13:  .equ   %00000100
mLCDWF13_BPDLCD13:  .equ   %00001000
mLCDWF13_BPELCD13:  .equ   %00010000
mLCDWF13_BPFLCD13:  .equ   %00100000
mLCDWF13_BPGLCD13:  .equ   %01000000
mLCDWF13_BPHLCD13:  .equ   %10000000


;*** LCDWF14 - LCD Waveform Register 14; 0xFFFF8724 ***
LCDWF14:            .equ   $FFFF8724                                ;*** LCDWF14 - LCD Waveform Register 14; 0xFFFF8724 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF14_BPALCD14:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPBLCD14:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPCLCD14:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPDLCD14:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPELCD14:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPFLCD14:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPGLCD14:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPHLCD14:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF14_BPALCD14:  .equ   %00000001
mLCDWF14_BPBLCD14:  .equ   %00000010
mLCDWF14_BPCLCD14:  .equ   %00000100
mLCDWF14_BPDLCD14:  .equ   %00001000
mLCDWF14_BPELCD14:  .equ   %00010000
mLCDWF14_BPFLCD14:  .equ   %00100000
mLCDWF14_BPGLCD14:  .equ   %01000000
mLCDWF14_BPHLCD14:  .equ   %10000000


;*** LCDWF15 - LCD Waveform Register 15; 0xFFFF8725 ***
LCDWF15:            .equ   $FFFF8725                                ;*** LCDWF15 - LCD Waveform Register 15; 0xFFFF8725 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF15_BPALCD15:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPBLCD15:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPCLCD15:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPDLCD15:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPELCD15:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPFLCD15:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPGLCD15:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPHLCD15:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF15_BPALCD15:  .equ   %00000001
mLCDWF15_BPBLCD15:  .equ   %00000010
mLCDWF15_BPCLCD15:  .equ   %00000100
mLCDWF15_BPDLCD15:  .equ   %00001000
mLCDWF15_BPELCD15:  .equ   %00010000
mLCDWF15_BPFLCD15:  .equ   %00100000
mLCDWF15_BPGLCD15:  .equ   %01000000
mLCDWF15_BPHLCD15:  .equ   %10000000


;*** LCDWF16 - LCD Waveform Register 16; 0xFFFF8726 ***
LCDWF16:            .equ   $FFFF8726                                ;*** LCDWF16 - LCD Waveform Register 16; 0xFFFF8726 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF16_BPALCD16:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPBLCD16:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPCLCD16:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPDLCD16:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPELCD16:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPFLCD16:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPGLCD16:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPHLCD16:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF16_BPALCD16:  .equ   %00000001
mLCDWF16_BPBLCD16:  .equ   %00000010
mLCDWF16_BPCLCD16:  .equ   %00000100
mLCDWF16_BPDLCD16:  .equ   %00001000
mLCDWF16_BPELCD16:  .equ   %00010000
mLCDWF16_BPFLCD16:  .equ   %00100000
mLCDWF16_BPGLCD16:  .equ   %01000000
mLCDWF16_BPHLCD16:  .equ   %10000000


;*** LCDWF17 - LCD Waveform Register 17; 0xFFFF8727 ***
LCDWF17:            .equ   $FFFF8727                                ;*** LCDWF17 - LCD Waveform Register 17; 0xFFFF8727 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF17_BPALCD17:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPBLCD17:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPCLCD17:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPDLCD17:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPELCD17:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPFLCD17:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPGLCD17:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPHLCD17:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF17_BPALCD17:  .equ   %00000001
mLCDWF17_BPBLCD17:  .equ   %00000010
mLCDWF17_BPCLCD17:  .equ   %00000100
mLCDWF17_BPDLCD17:  .equ   %00001000
mLCDWF17_BPELCD17:  .equ   %00010000
mLCDWF17_BPFLCD17:  .equ   %00100000
mLCDWF17_BPGLCD17:  .equ   %01000000
mLCDWF17_BPHLCD17:  .equ   %10000000


;*** LCDWF18 - LCD Waveform Register 18; 0xFFFF8728 ***
LCDWF18:            .equ   $FFFF8728                                ;*** LCDWF18 - LCD Waveform Register 18; 0xFFFF8728 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF18_BPALCD18:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPBLCD18:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPCLCD18:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPDLCD18:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPELCD18:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPFLCD18:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPGLCD18:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPHLCD18:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF18_BPALCD18:  .equ   %00000001
mLCDWF18_BPBLCD18:  .equ   %00000010
mLCDWF18_BPCLCD18:  .equ   %00000100
mLCDWF18_BPDLCD18:  .equ   %00001000
mLCDWF18_BPELCD18:  .equ   %00010000
mLCDWF18_BPFLCD18:  .equ   %00100000
mLCDWF18_BPGLCD18:  .equ   %01000000
mLCDWF18_BPHLCD18:  .equ   %10000000


;*** LCDWF19 - LCD Waveform Register 19; 0xFFFF8729 ***
LCDWF19:            .equ   $FFFF8729                                ;*** LCDWF19 - LCD Waveform Register 19; 0xFFFF8729 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF19_BPALCD19:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPBLCD19:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPCLCD19:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPDLCD19:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPELCD19:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPFLCD19:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPGLCD19:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPHLCD19:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF19_BPALCD19:  .equ   %00000001
mLCDWF19_BPBLCD19:  .equ   %00000010
mLCDWF19_BPCLCD19:  .equ   %00000100
mLCDWF19_BPDLCD19:  .equ   %00001000
mLCDWF19_BPELCD19:  .equ   %00010000
mLCDWF19_BPFLCD19:  .equ   %00100000
mLCDWF19_BPGLCD19:  .equ   %01000000
mLCDWF19_BPHLCD19:  .equ   %10000000


;*** LCDWF20 - LCD Waveform Register 20; 0xFFFF872A ***
LCDWF20:            .equ   $FFFF872A                                ;*** LCDWF20 - LCD Waveform Register 20; 0xFFFF872A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF20_BPALCD20:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPBLCD20:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPCLCD20:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPDLCD20:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPELCD20:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPFLCD20:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPGLCD20:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPHLCD20:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF20_BPALCD20:  .equ   %00000001
mLCDWF20_BPBLCD20:  .equ   %00000010
mLCDWF20_BPCLCD20:  .equ   %00000100
mLCDWF20_BPDLCD20:  .equ   %00001000
mLCDWF20_BPELCD20:  .equ   %00010000
mLCDWF20_BPFLCD20:  .equ   %00100000
mLCDWF20_BPGLCD20:  .equ   %01000000
mLCDWF20_BPHLCD20:  .equ   %10000000


;*** LCDWF21 - LCD Waveform Register 21; 0xFFFF872B ***
LCDWF21:            .equ   $FFFF872B                                ;*** LCDWF21 - LCD Waveform Register 21; 0xFFFF872B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF21_BPALCD21:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPBLCD21:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPCLCD21:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPDLCD21:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPELCD21:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPFLCD21:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPGLCD21:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPHLCD21:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF21_BPALCD21:  .equ   %00000001
mLCDWF21_BPBLCD21:  .equ   %00000010
mLCDWF21_BPCLCD21:  .equ   %00000100
mLCDWF21_BPDLCD21:  .equ   %00001000
mLCDWF21_BPELCD21:  .equ   %00010000
mLCDWF21_BPFLCD21:  .equ   %00100000
mLCDWF21_BPGLCD21:  .equ   %01000000
mLCDWF21_BPHLCD21:  .equ   %10000000


;*** LCDWF22 - LCD Waveform Register 22; 0xFFFF872C ***
LCDWF22:            .equ   $FFFF872C                                ;*** LCDWF22 - LCD Waveform Register 22; 0xFFFF872C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF22_BPALCD22:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPBLCD22:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPCLCD22:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPDLCD22:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPELCD22:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPFLCD22:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPGLCD22:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPHLCD22:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF22_BPALCD22:  .equ   %00000001
mLCDWF22_BPBLCD22:  .equ   %00000010
mLCDWF22_BPCLCD22:  .equ   %00000100
mLCDWF22_BPDLCD22:  .equ   %00001000
mLCDWF22_BPELCD22:  .equ   %00010000
mLCDWF22_BPFLCD22:  .equ   %00100000
mLCDWF22_BPGLCD22:  .equ   %01000000
mLCDWF22_BPHLCD22:  .equ   %10000000


;*** LCDWF23 - LCD Waveform Register 23; 0xFFFF872D ***
LCDWF23:            .equ   $FFFF872D                                ;*** LCDWF23 - LCD Waveform Register 23; 0xFFFF872D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF23_BPALCD23:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPBLCD23:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPCLCD23:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPDLCD23:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPELCD23:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPFLCD23:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPGLCD23:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPHLCD23:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF23_BPALCD23:  .equ   %00000001
mLCDWF23_BPBLCD23:  .equ   %00000010
mLCDWF23_BPCLCD23:  .equ   %00000100
mLCDWF23_BPDLCD23:  .equ   %00001000
mLCDWF23_BPELCD23:  .equ   %00010000
mLCDWF23_BPFLCD23:  .equ   %00100000
mLCDWF23_BPGLCD23:  .equ   %01000000
mLCDWF23_BPHLCD23:  .equ   %10000000


;*** LCDWF24 - LCD Waveform Register 24; 0xFFFF872E ***
LCDWF24:            .equ   $FFFF872E                                ;*** LCDWF24 - LCD Waveform Register 24; 0xFFFF872E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF24_BPALCD24:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPBLCD24:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPCLCD24:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPDLCD24:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPELCD24:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPFLCD24:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPGLCD24:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPHLCD24:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF24_BPALCD24:  .equ   %00000001
mLCDWF24_BPBLCD24:  .equ   %00000010
mLCDWF24_BPCLCD24:  .equ   %00000100
mLCDWF24_BPDLCD24:  .equ   %00001000
mLCDWF24_BPELCD24:  .equ   %00010000
mLCDWF24_BPFLCD24:  .equ   %00100000
mLCDWF24_BPGLCD24:  .equ   %01000000
mLCDWF24_BPHLCD24:  .equ   %10000000


;*** LCDWF25 - LCD Waveform Register 25; 0xFFFF872F ***
LCDWF25:            .equ   $FFFF872F                                ;*** LCDWF25 - LCD Waveform Register 25; 0xFFFF872F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF25_BPALCD25:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPBLCD25:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPCLCD25:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPDLCD25:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPELCD25:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPFLCD25:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPGLCD25:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPHLCD25:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF25_BPALCD25:  .equ   %00000001
mLCDWF25_BPBLCD25:  .equ   %00000010
mLCDWF25_BPCLCD25:  .equ   %00000100
mLCDWF25_BPDLCD25:  .equ   %00001000
mLCDWF25_BPELCD25:  .equ   %00010000
mLCDWF25_BPFLCD25:  .equ   %00100000
mLCDWF25_BPGLCD25:  .equ   %01000000
mLCDWF25_BPHLCD25:  .equ   %10000000


;*** LCDWF26 - LCD Waveform Register 26; 0xFFFF8730 ***
LCDWF26:            .equ   $FFFF8730                                ;*** LCDWF26 - LCD Waveform Register 26; 0xFFFF8730 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF26_BPALCD26:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPBLCD26:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPCLCD26:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPDLCD26:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPELCD26:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPFLCD26:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPGLCD26:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPHLCD26:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF26_BPALCD26:  .equ   %00000001
mLCDWF26_BPBLCD26:  .equ   %00000010
mLCDWF26_BPCLCD26:  .equ   %00000100
mLCDWF26_BPDLCD26:  .equ   %00001000
mLCDWF26_BPELCD26:  .equ   %00010000
mLCDWF26_BPFLCD26:  .equ   %00100000
mLCDWF26_BPGLCD26:  .equ   %01000000
mLCDWF26_BPHLCD26:  .equ   %10000000


;*** LCDWF27 - LCD Waveform Register 27; 0xFFFF8731 ***
LCDWF27:            .equ   $FFFF8731                                ;*** LCDWF27 - LCD Waveform Register 27; 0xFFFF8731 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF27_BPALCD27:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPBLCD27:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPCLCD27:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPDLCD27:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPELCD27:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPFLCD27:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPGLCD27:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPHLCD27:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF27_BPALCD27:  .equ   %00000001
mLCDWF27_BPBLCD27:  .equ   %00000010
mLCDWF27_BPCLCD27:  .equ   %00000100
mLCDWF27_BPDLCD27:  .equ   %00001000
mLCDWF27_BPELCD27:  .equ   %00010000
mLCDWF27_BPFLCD27:  .equ   %00100000
mLCDWF27_BPGLCD27:  .equ   %01000000
mLCDWF27_BPHLCD27:  .equ   %10000000


;*** LCDWF28 - LCD Waveform Register 28; 0xFFFF8732 ***
LCDWF28:            .equ   $FFFF8732                                ;*** LCDWF28 - LCD Waveform Register 28; 0xFFFF8732 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF28_BPALCD28:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPBLCD28:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPCLCD28:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPDLCD28:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPELCD28:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPFLCD28:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPGLCD28:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPHLCD28:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF28_BPALCD28:  .equ   %00000001
mLCDWF28_BPBLCD28:  .equ   %00000010
mLCDWF28_BPCLCD28:  .equ   %00000100
mLCDWF28_BPDLCD28:  .equ   %00001000
mLCDWF28_BPELCD28:  .equ   %00010000
mLCDWF28_BPFLCD28:  .equ   %00100000
mLCDWF28_BPGLCD28:  .equ   %01000000
mLCDWF28_BPHLCD28:  .equ   %10000000


;*** LCDWF29 - LCD Waveform Register 29; 0xFFFF8733 ***
LCDWF29:            .equ   $FFFF8733                                ;*** LCDWF29 - LCD Waveform Register 29; 0xFFFF8733 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF29_BPALCD29:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPBLCD29:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPCLCD29:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPDLCD29:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPELCD29:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPFLCD29:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPGLCD29:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPHLCD29:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF29_BPALCD29:  .equ   %00000001
mLCDWF29_BPBLCD29:  .equ   %00000010
mLCDWF29_BPCLCD29:  .equ   %00000100
mLCDWF29_BPDLCD29:  .equ   %00001000
mLCDWF29_BPELCD29:  .equ   %00010000
mLCDWF29_BPFLCD29:  .equ   %00100000
mLCDWF29_BPGLCD29:  .equ   %01000000
mLCDWF29_BPHLCD29:  .equ   %10000000


;*** LCDWF30 - LCD Waveform Register 30; 0xFFFF8734 ***
LCDWF30:            .equ   $FFFF8734                                ;*** LCDWF30 - LCD Waveform Register 30; 0xFFFF8734 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF30_BPALCD30:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPBLCD30:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPCLCD30:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPDLCD30:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPELCD30:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPFLCD30:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPGLCD30:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPHLCD30:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF30_BPALCD30:  .equ   %00000001
mLCDWF30_BPBLCD30:  .equ   %00000010
mLCDWF30_BPCLCD30:  .equ   %00000100
mLCDWF30_BPDLCD30:  .equ   %00001000
mLCDWF30_BPELCD30:  .equ   %00010000
mLCDWF30_BPFLCD30:  .equ   %00100000
mLCDWF30_BPGLCD30:  .equ   %01000000
mLCDWF30_BPHLCD30:  .equ   %10000000


;*** LCDWF31 - LCD Waveform Register 31; 0xFFFF8735 ***
LCDWF31:            .equ   $FFFF8735                                ;*** LCDWF31 - LCD Waveform Register 31; 0xFFFF8735 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF31_BPALCD31:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPBLCD31:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPCLCD31:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPDLCD31:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPELCD31:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPFLCD31:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPGLCD31:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPHLCD31:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF31_BPALCD31:  .equ   %00000001
mLCDWF31_BPBLCD31:  .equ   %00000010
mLCDWF31_BPCLCD31:  .equ   %00000100
mLCDWF31_BPDLCD31:  .equ   %00001000
mLCDWF31_BPELCD31:  .equ   %00010000
mLCDWF31_BPFLCD31:  .equ   %00100000
mLCDWF31_BPGLCD31:  .equ   %01000000
mLCDWF31_BPHLCD31:  .equ   %10000000


;*** LCDWF32 - LCD Waveform Register 32; 0xFFFF8736 ***
LCDWF32:            .equ   $FFFF8736                                ;*** LCDWF32 - LCD Waveform Register 32; 0xFFFF8736 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF32_BPALCD32:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPBLCD32:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPCLCD32:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPDLCD32:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPELCD32:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPFLCD32:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPGLCD32:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPHLCD32:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF32_BPALCD32:  .equ   %00000001
mLCDWF32_BPBLCD32:  .equ   %00000010
mLCDWF32_BPCLCD32:  .equ   %00000100
mLCDWF32_BPDLCD32:  .equ   %00001000
mLCDWF32_BPELCD32:  .equ   %00010000
mLCDWF32_BPFLCD32:  .equ   %00100000
mLCDWF32_BPGLCD32:  .equ   %01000000
mLCDWF32_BPHLCD32:  .equ   %10000000


;*** LCDWF33 - LCD Waveform Register 33; 0xFFFF8737 ***
LCDWF33:            .equ   $FFFF8737                                ;*** LCDWF33 - LCD Waveform Register 33; 0xFFFF8737 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF33_BPALCD33:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPBLCD33:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPCLCD33:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPDLCD33:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPELCD33:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPFLCD33:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPGLCD33:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPHLCD33:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF33_BPALCD33:  .equ   %00000001
mLCDWF33_BPBLCD33:  .equ   %00000010
mLCDWF33_BPCLCD33:  .equ   %00000100
mLCDWF33_BPDLCD33:  .equ   %00001000
mLCDWF33_BPELCD33:  .equ   %00010000
mLCDWF33_BPFLCD33:  .equ   %00100000
mLCDWF33_BPGLCD33:  .equ   %01000000
mLCDWF33_BPHLCD33:  .equ   %10000000


;*** LCDWF34 - LCD Waveform Register 34; 0xFFFF8738 ***
LCDWF34:            .equ   $FFFF8738                                ;*** LCDWF34 - LCD Waveform Register 34; 0xFFFF8738 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF34_BPALCD34:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPBLCD34:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPCLCD34:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPDLCD34:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPELCD34:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPFLCD34:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPGLCD34:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPHLCD34:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF34_BPALCD34:  .equ   %00000001
mLCDWF34_BPBLCD34:  .equ   %00000010
mLCDWF34_BPCLCD34:  .equ   %00000100
mLCDWF34_BPDLCD34:  .equ   %00001000
mLCDWF34_BPELCD34:  .equ   %00010000
mLCDWF34_BPFLCD34:  .equ   %00100000
mLCDWF34_BPGLCD34:  .equ   %01000000
mLCDWF34_BPHLCD34:  .equ   %10000000


;*** LCDWF35 - LCD Waveform Register 35; 0xFFFF8739 ***
LCDWF35:            .equ   $FFFF8739                                ;*** LCDWF35 - LCD Waveform Register 35; 0xFFFF8739 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF35_BPALCD35:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPBLCD35:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPCLCD35:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPDLCD35:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPELCD35:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPFLCD35:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPGLCD35:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPHLCD35:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF35_BPALCD35:  .equ   %00000001
mLCDWF35_BPBLCD35:  .equ   %00000010
mLCDWF35_BPCLCD35:  .equ   %00000100
mLCDWF35_BPDLCD35:  .equ   %00001000
mLCDWF35_BPELCD35:  .equ   %00010000
mLCDWF35_BPFLCD35:  .equ   %00100000
mLCDWF35_BPGLCD35:  .equ   %01000000
mLCDWF35_BPHLCD35:  .equ   %10000000


;*** LCDWF36 - LCD Waveform Register 36; 0xFFFF873A ***
LCDWF36:            .equ   $FFFF873A                                ;*** LCDWF36 - LCD Waveform Register 36; 0xFFFF873A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF36_BPALCD36:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPBLCD36:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPCLCD36:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPDLCD36:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPELCD36:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPFLCD36:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPGLCD36:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPHLCD36:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF36_BPALCD36:  .equ   %00000001
mLCDWF36_BPBLCD36:  .equ   %00000010
mLCDWF36_BPCLCD36:  .equ   %00000100
mLCDWF36_BPDLCD36:  .equ   %00001000
mLCDWF36_BPELCD36:  .equ   %00010000
mLCDWF36_BPFLCD36:  .equ   %00100000
mLCDWF36_BPGLCD36:  .equ   %01000000
mLCDWF36_BPHLCD36:  .equ   %10000000


;*** LCDWF37 - LCD Waveform Register 37; 0xFFFF873B ***
LCDWF37:            .equ   $FFFF873B                                ;*** LCDWF37 - LCD Waveform Register 37; 0xFFFF873B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF37_BPALCD37:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPBLCD37:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPCLCD37:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPDLCD37:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPELCD37:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPFLCD37:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPGLCD37:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPHLCD37:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF37_BPALCD37:  .equ   %00000001
mLCDWF37_BPBLCD37:  .equ   %00000010
mLCDWF37_BPCLCD37:  .equ   %00000100
mLCDWF37_BPDLCD37:  .equ   %00001000
mLCDWF37_BPELCD37:  .equ   %00010000
mLCDWF37_BPFLCD37:  .equ   %00100000
mLCDWF37_BPGLCD37:  .equ   %01000000
mLCDWF37_BPHLCD37:  .equ   %10000000


;*** LCDWF38 - LCD Waveform Register 38; 0xFFFF873C ***
LCDWF38:            .equ   $FFFF873C                                ;*** LCDWF38 - LCD Waveform Register 38; 0xFFFF873C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF38_BPALCD38:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPBLCD38:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPCLCD38:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPDLCD38:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPELCD38:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPFLCD38:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPGLCD38:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPHLCD38:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF38_BPALCD38:  .equ   %00000001
mLCDWF38_BPBLCD38:  .equ   %00000010
mLCDWF38_BPCLCD38:  .equ   %00000100
mLCDWF38_BPDLCD38:  .equ   %00001000
mLCDWF38_BPELCD38:  .equ   %00010000
mLCDWF38_BPFLCD38:  .equ   %00100000
mLCDWF38_BPGLCD38:  .equ   %01000000
mLCDWF38_BPHLCD38:  .equ   %10000000


;*** LCDWF39 - LCD Waveform Register 39; 0xFFFF873D ***
LCDWF39:            .equ   $FFFF873D                                ;*** LCDWF39 - LCD Waveform Register 39; 0xFFFF873D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF39_BPALCD39:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPBLCD39:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPCLCD39:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPDLCD39:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPELCD39:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPFLCD39:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPGLCD39:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPHLCD39:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF39_BPALCD39:  .equ   %00000001
mLCDWF39_BPBLCD39:  .equ   %00000010
mLCDWF39_BPCLCD39:  .equ   %00000100
mLCDWF39_BPDLCD39:  .equ   %00001000
mLCDWF39_BPELCD39:  .equ   %00010000
mLCDWF39_BPFLCD39:  .equ   %00100000
mLCDWF39_BPGLCD39:  .equ   %01000000
mLCDWF39_BPHLCD39:  .equ   %10000000


;*** LCDWF40 - LCD Waveform Register 40; 0xFFFF873E ***
LCDWF40:            .equ   $FFFF873E                                ;*** LCDWF40 - LCD Waveform Register 40; 0xFFFF873E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF40_BPALCD40:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPBLCD40:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPCLCD40:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPDLCD40:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPELCD40:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPFLCD40:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPGLCD40:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPHLCD40:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF40_BPALCD40:  .equ   %00000001
mLCDWF40_BPBLCD40:  .equ   %00000010
mLCDWF40_BPCLCD40:  .equ   %00000100
mLCDWF40_BPDLCD40:  .equ   %00001000
mLCDWF40_BPELCD40:  .equ   %00010000
mLCDWF40_BPFLCD40:  .equ   %00100000
mLCDWF40_BPGLCD40:  .equ   %01000000
mLCDWF40_BPHLCD40:  .equ   %10000000


;*** LCDWF41 - LCD Waveform Register 41; 0xFFFF873F ***
LCDWF41:            .equ   $FFFF873F                                ;*** LCDWF41 - LCD Waveform Register 41; 0xFFFF873F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF41_BPALCD41:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPBLCD41:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPCLCD41:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPDLCD41:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPELCD41:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPFLCD41:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPGLCD41:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPHLCD41:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF41_BPALCD41:  .equ   %00000001
mLCDWF41_BPBLCD41:  .equ   %00000010
mLCDWF41_BPCLCD41:  .equ   %00000100
mLCDWF41_BPDLCD41:  .equ   %00001000
mLCDWF41_BPELCD41:  .equ   %00010000
mLCDWF41_BPFLCD41:  .equ   %00100000
mLCDWF41_BPGLCD41:  .equ   %01000000
mLCDWF41_BPHLCD41:  .equ   %10000000


;*** LCDWF42 - LCD Waveform Register 42; 0xFFFF8740 ***
LCDWF42:            .equ   $FFFF8740                                ;*** LCDWF42 - LCD Waveform Register 42; 0xFFFF8740 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF42_BPALCD42:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPBLCD42:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPCLCD42:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPDLCD42:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPELCD42:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPFLCD42:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPGLCD42:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPHLCD42:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF42_BPALCD42:  .equ   %00000001
mLCDWF42_BPBLCD42:  .equ   %00000010
mLCDWF42_BPCLCD42:  .equ   %00000100
mLCDWF42_BPDLCD42:  .equ   %00001000
mLCDWF42_BPELCD42:  .equ   %00010000
mLCDWF42_BPFLCD42:  .equ   %00100000
mLCDWF42_BPGLCD42:  .equ   %01000000
mLCDWF42_BPHLCD42:  .equ   %10000000


;*** LCDWF43 - LCD Waveform Register 43; 0xFFFF8741 ***
LCDWF43:            .equ   $FFFF8741                                ;*** LCDWF43 - LCD Waveform Register 43; 0xFFFF8741 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF43_BPALCD43:   .equ   0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPBLCD43:   .equ   1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPCLCD43:   .equ   2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPDLCD43:   .equ   3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPELCD43:   .equ   4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPFLCD43:   .equ   5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPGLCD43:   .equ   6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPHLCD43:   .equ   7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF43_BPALCD43:  .equ   %00000001
mLCDWF43_BPBLCD43:  .equ   %00000010
mLCDWF43_BPCLCD43:  .equ   %00000100
mLCDWF43_BPDLCD43:  .equ   %00001000
mLCDWF43_BPELCD43:  .equ   %00010000
mLCDWF43_BPFLCD43:  .equ   %00100000
mLCDWF43_BPGLCD43:  .equ   %01000000
mLCDWF43_BPHLCD43:  .equ   %10000000


;*** F1CDIV - FLASH Clock Divider Register; 0xFFFF8780 ***
F1CDIV:             .equ   $FFFF8780                                ;*** F1CDIV - FLASH Clock Divider Register; 0xFFFF8780 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F1CDIV_FDIV0:       .equ   0                                         ; Divisor for FLASH Clock Divider, bit 0
F1CDIV_FDIV1:       .equ   1                                         ; Divisor for FLASH Clock Divider, bit 1
F1CDIV_FDIV2:       .equ   2                                         ; Divisor for FLASH Clock Divider, bit 2
F1CDIV_FDIV3:       .equ   3                                         ; Divisor for FLASH Clock Divider, bit 3
F1CDIV_FDIV4:       .equ   4                                         ; Divisor for FLASH Clock Divider, bit 4
F1CDIV_FDIV5:       .equ   5                                         ; Divisor for FLASH Clock Divider, bit 5
F1CDIV_PRDIV8:      .equ   6                                         ; Prescale (Divide) FLASH Clock by 8
F1CDIV_FDIVLD:      .equ   7                                         ; Divisor Loaded Status Flag
; bit position masks
mF1CDIV_FDIV0:      .equ   %00000001
mF1CDIV_FDIV1:      .equ   %00000010
mF1CDIV_FDIV2:      .equ   %00000100
mF1CDIV_FDIV3:      .equ   %00001000
mF1CDIV_FDIV4:      .equ   %00010000
mF1CDIV_FDIV5:      .equ   %00100000
mF1CDIV_PRDIV8:     .equ   %01000000
mF1CDIV_FDIVLD:     .equ   %10000000


;*** F1OPT - Flash Options Register; 0xFFFF8781 ***
F1OPT:              .equ   $FFFF8781                                ;*** F1OPT - Flash Options Register; 0xFFFF8781 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F1OPT_SEC0:         .equ   0                                         ; Flash Security Bit 0
F1OPT_SEC1:         .equ   1                                         ; Flash Security Bit 1
F1OPT_KEYEN0:       .equ   6                                         ; Backdoor Key Security Enable Bit 0
F1OPT_KEYEN1:       .equ   7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mF1OPT_SEC0:        .equ   %00000001
mF1OPT_SEC1:        .equ   %00000010
mF1OPT_KEYEN0:      .equ   %01000000
mF1OPT_KEYEN1:      .equ   %10000000


;*** F1CNFG - Flash Configuration Register; 0xFFFF8783 ***
F1CNFG:             .equ   $FFFF8783                                ;*** F1CNFG - Flash Configuration Register; 0xFFFF8783 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F1CNFG_KEYACC:      .equ   5                                         ; Enable Security Key Writing
F1CNFG_CCIE:        .equ   6                                         ; Command Complete Interrupt Enable
F1CNFG_CBEIE:       .equ   7                                         ; Command Buffer Empty Interrupt Enable
; bit position masks
mF1CNFG_KEYACC:     .equ   %00100000
mF1CNFG_CCIE:       .equ   %01000000
mF1CNFG_CBEIE:      .equ   %10000000


;*** F1PROT - Flash Protection Register; 0xFFFF8784 ***
F1PROT:             .equ   $FFFF8784                                ;*** F1PROT - Flash Protection Register; 0xFFFF8784 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F1PROT_FPOPEN:      .equ   0                                         ; Flash Protection Open
F1PROT_FPS0:        .equ   1                                         ; Flash Protection Size, bit 0
F1PROT_FPS1:        .equ   2                                         ; Flash Protection Size, bit 1
F1PROT_FPS2:        .equ   3                                         ; Flash Protection Size, bit 2
F1PROT_FPS3:        .equ   4                                         ; Flash Protection Size, bit 3
F1PROT_FPS4:        .equ   5                                         ; Flash Protection Size, bit 4
F1PROT_FPS5:        .equ   6                                         ; Flash Protection Size, bit 5
F1PROT_FPS6:        .equ   7                                         ; Flash Protection Size, bit 6
; bit position masks
mF1PROT_FPOPEN:     .equ   %00000001
mF1PROT_FPS0:       .equ   %00000010
mF1PROT_FPS1:       .equ   %00000100
mF1PROT_FPS2:       .equ   %00001000
mF1PROT_FPS3:       .equ   %00010000
mF1PROT_FPS4:       .equ   %00100000
mF1PROT_FPS5:       .equ   %01000000
mF1PROT_FPS6:       .equ   %10000000


;*** F1STAT - Flash Status Register; 0xFFFF8785 ***
F1STAT:             .equ   $FFFF8785                                ;*** F1STAT - Flash Status Register; 0xFFFF8785 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F1STAT_FBLANK:      .equ   2                                         ; FLASH Flag Indicating the Erase Verify Operation Status
F1STAT_FACCERR:     .equ   4                                         ; FLASH Access Error Flag
F1STAT_FPVIOL:      .equ   5                                         ; FLASH Protection Violation Flag
F1STAT_FCCF:        .equ   6                                         ; FLASH Command Complete Interrupt Flag
F1STAT_FCBEF:       .equ   7                                         ; FLASH Command Buffer Empty Flag
; bit position masks
mF1STAT_FBLANK:     .equ   %00000100
mF1STAT_FACCERR:    .equ   %00010000
mF1STAT_FPVIOL:     .equ   %00100000
mF1STAT_FCCF:       .equ   %01000000
mF1STAT_FCBEF:      .equ   %10000000


;*** F1CMD - Flash Command Register; 0xFFFF8786 ***
F1CMD:              .equ   $FFFF8786                                ;*** F1CMD - Flash Command Register; 0xFFFF8786 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F1CMD_FCMD0:        .equ   0                                         ; Flash Command, bit 0
F1CMD_FCMD1:        .equ   1                                         ; Flash Command, bit 1
F1CMD_FCMD2:        .equ   2                                         ; Flash Command, bit 2
F1CMD_FCMD3:        .equ   3                                         ; Flash Command, bit 3
F1CMD_FCMD4:        .equ   4                                         ; Flash Command, bit 4
F1CMD_FCMD5:        .equ   5                                         ; Flash Command, bit 5
F1CMD_FCMD6:        .equ   6                                         ; Flash Command, bit 6
; bit position masks
mF1CMD_FCMD0:       .equ   %00000001
mF1CMD_FCMD1:       .equ   %00000010
mF1CMD_FCMD2:       .equ   %00000100
mF1CMD_FCMD3:       .equ   %00001000
mF1CMD_FCMD4:       .equ   %00010000
mF1CMD_FCMD5:       .equ   %00100000
mF1CMD_FCMD6:       .equ   %01000000


;*** F2CDIV - FLASH Clock Divider Register; 0xFFFF87A0 ***
F2CDIV:             .equ   $FFFF87A0                                ;*** F2CDIV - FLASH Clock Divider Register; 0xFFFF87A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F2CDIV_FDIV0:       .equ   0                                         ; Divisor for FLASH Clock Divider, bit 0
F2CDIV_FDIV1:       .equ   1                                         ; Divisor for FLASH Clock Divider, bit 1
F2CDIV_FDIV2:       .equ   2                                         ; Divisor for FLASH Clock Divider, bit 2
F2CDIV_FDIV3:       .equ   3                                         ; Divisor for FLASH Clock Divider, bit 3
F2CDIV_FDIV4:       .equ   4                                         ; Divisor for FLASH Clock Divider, bit 4
F2CDIV_FDIV5:       .equ   5                                         ; Divisor for FLASH Clock Divider, bit 5
F2CDIV_PRDIV8:      .equ   6                                         ; Prescale (Divide) FLASH Clock by 8
F2CDIV_FDIVLD:      .equ   7                                         ; Divisor Loaded Status Flag
; bit position masks
mF2CDIV_FDIV0:      .equ   %00000001
mF2CDIV_FDIV1:      .equ   %00000010
mF2CDIV_FDIV2:      .equ   %00000100
mF2CDIV_FDIV3:      .equ   %00001000
mF2CDIV_FDIV4:      .equ   %00010000
mF2CDIV_FDIV5:      .equ   %00100000
mF2CDIV_PRDIV8:     .equ   %01000000
mF2CDIV_FDIVLD:     .equ   %10000000


;*** F2OPT - Flash Options Register; 0xFFFF87A1 ***
F2OPT:              .equ   $FFFF87A1                                ;*** F2OPT - Flash Options Register; 0xFFFF87A1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F2OPT_SEC0:         .equ   0                                         ; Flash Security Bit 0
F2OPT_SEC1:         .equ   1                                         ; Flash Security Bit 1
F2OPT_KEYEN0:       .equ   6                                         ; Backdoor Key Security Enable Bit 0
F2OPT_KEYEN1:       .equ   7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mF2OPT_SEC0:        .equ   %00000001
mF2OPT_SEC1:        .equ   %00000010
mF2OPT_KEYEN0:      .equ   %01000000
mF2OPT_KEYEN1:      .equ   %10000000


;*** F2CNFG - Flash Configuration Register; 0xFFFF87A3 ***
F2CNFG:             .equ   $FFFF87A3                                ;*** F2CNFG - Flash Configuration Register; 0xFFFF87A3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F2CNFG_KEYACC:      .equ   5                                         ; Enable Security Key Writing
F2CNFG_CCIE:        .equ   6                                         ; Command Complete Interrupt Enable
F2CNFG_CBEIE:       .equ   7                                         ; Command Buffer Empty Interrupt Enable
; bit position masks
mF2CNFG_KEYACC:     .equ   %00100000
mF2CNFG_CCIE:       .equ   %01000000
mF2CNFG_CBEIE:      .equ   %10000000


;*** F2PROT - Flash Protection Register; 0xFFFF87A4 ***
F2PROT:             .equ   $FFFF87A4                                ;*** F2PROT - Flash Protection Register; 0xFFFF87A4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F2PROT_FPOPEN:      .equ   0                                         ; Flash Protection Open
F2PROT_FPS0:        .equ   1                                         ; Flash Protection Size, bit 0
F2PROT_FPS1:        .equ   2                                         ; Flash Protection Size, bit 1
F2PROT_FPS2:        .equ   3                                         ; Flash Protection Size, bit 2
F2PROT_FPS3:        .equ   4                                         ; Flash Protection Size, bit 3
F2PROT_FPS4:        .equ   5                                         ; Flash Protection Size, bit 4
F2PROT_FPS5:        .equ   6                                         ; Flash Protection Size, bit 5
F2PROT_FPS6:        .equ   7                                         ; Flash Protection Size, bit 6
; bit position masks
mF2PROT_FPOPEN:     .equ   %00000001
mF2PROT_FPS0:       .equ   %00000010
mF2PROT_FPS1:       .equ   %00000100
mF2PROT_FPS2:       .equ   %00001000
mF2PROT_FPS3:       .equ   %00010000
mF2PROT_FPS4:       .equ   %00100000
mF2PROT_FPS5:       .equ   %01000000
mF2PROT_FPS6:       .equ   %10000000


;*** F2STAT - Flash Status Register; 0xFFFF87A5 ***
F2STAT:             .equ   $FFFF87A5                                ;*** F2STAT - Flash Status Register; 0xFFFF87A5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F2STAT_FBLANK:      .equ   2                                         ; FLASH Flag Indicating the Erase Verify Operation Status
F2STAT_FACCERR:     .equ   4                                         ; FLASH Access Error Flag
F2STAT_FPVIOL:      .equ   5                                         ; FLASH Protection Violation Flag
F2STAT_FCCF:        .equ   6                                         ; FLASH Command Complete Interrupt Flag
F2STAT_FCBEF:       .equ   7                                         ; FLASH Command Buffer Empty Flag
; bit position masks
mF2STAT_FBLANK:     .equ   %00000100
mF2STAT_FACCERR:    .equ   %00010000
mF2STAT_FPVIOL:     .equ   %00100000
mF2STAT_FCCF:       .equ   %01000000
mF2STAT_FCBEF:      .equ   %10000000


;*** F2CMD - Flash Command Register; 0xFFFF87A6 ***
F2CMD:              .equ   $FFFF87A6                                ;*** F2CMD - Flash Command Register; 0xFFFF87A6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F2CMD_FCMD0:        .equ   0                                         ; Flash Command, bit 0
F2CMD_FCMD1:        .equ   1                                         ; Flash Command, bit 1
F2CMD_FCMD2:        .equ   2                                         ; Flash Command, bit 2
F2CMD_FCMD3:        .equ   3                                         ; Flash Command, bit 3
F2CMD_FCMD4:        .equ   4                                         ; Flash Command, bit 4
F2CMD_FCMD5:        .equ   5                                         ; Flash Command, bit 5
F2CMD_FCMD6:        .equ   6                                         ; Flash Command, bit 6
; bit position masks
mF2CMD_FCMD0:       .equ   %00000001
mF2CMD_FCMD1:       .equ   %00000010
mF2CMD_FCMD2:       .equ   %00000100
mF2CMD_FCMD3:       .equ   %00001000
mF2CMD_FCMD4:       .equ   %00010000
mF2CMD_FCMD5:       .equ   %00100000
mF2CMD_FCMD6:       .equ   %01000000


;*** PDBSCR - PDB Status and Control Register; 0xFFFFE000 ***
PDBSCR:             .equ   $FFFFE000                                ;*** PDBSCR - PDB Status and Control Register; 0xFFFFE000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBSCR_EN:          .equ   0                                         ; Module Enable
PDBSCR_IE:          .equ   1                                         ; Interrupt Enable
PDBSCR_TRIGSEL0:    .equ   2                                         ; Input Trigger Select, bit 0
PDBSCR_TRIGSEL1:    .equ   3                                         ; Input Trigger Select, bit 1
PDBSCR_TRIGSEL2:    .equ   4                                         ; Input Trigger Select, bit 2
PDBSCR_SWTRIG:      .equ   5                                         ; Software Trigger
PDBSCR_CONT:        .equ   6                                         ; Continuous Mode Enable
PDBSCR_IF:          .equ   7                                         ; Interrupt Flag
PDBSCR_PRESCALER0:  .equ   13                                        ; Clock Prescaler Select, bit 0
PDBSCR_PRESCALER1:  .equ   14                                        ; Clock Prescaler Select, bit 1
PDBSCR_PRESCALER2:  .equ   15                                        ; Clock Prescaler Select, bit 2
; bit position masks
mPDBSCR_EN:         .equ   %00000001
mPDBSCR_IE:         .equ   %00000010
mPDBSCR_TRIGSEL0:   .equ   %00000100
mPDBSCR_TRIGSEL1:   .equ   %00001000
mPDBSCR_TRIGSEL2:   .equ   %00010000
mPDBSCR_SWTRIG:     .equ   %00100000
mPDBSCR_CONT:       .equ   %01000000
mPDBSCR_IF:         .equ   %10000000
mPDBSCR_PRESCALER0: .equ   %10000000000000
mPDBSCR_PRESCALER1: .equ   %100000000000000
mPDBSCR_PRESCALER2: .equ   %1000000000000000


;*** PDBMOD - PDB Counter Modulus Register; 0xFFFFE002 ***
PDBMOD:             .equ   $FFFFE002                                ;*** PDBMOD - PDB Counter Modulus Register; 0xFFFFE002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBMOD_MOD0:        .equ   0                                         ; Counter Modulus, bit 0
PDBMOD_MOD1:        .equ   1                                         ; Counter Modulus, bit 1
PDBMOD_MOD2:        .equ   2                                         ; Counter Modulus, bit 2
PDBMOD_MOD3:        .equ   3                                         ; Counter Modulus, bit 3
PDBMOD_MOD4:        .equ   4                                         ; Counter Modulus, bit 4
PDBMOD_MOD5:        .equ   5                                         ; Counter Modulus, bit 5
PDBMOD_MOD6:        .equ   6                                         ; Counter Modulus, bit 6
PDBMOD_MOD7:        .equ   7                                         ; Counter Modulus, bit 7
PDBMOD_MOD8:        .equ   8                                         ; Counter Modulus, bit 8
PDBMOD_MOD9:        .equ   9                                         ; Counter Modulus, bit 9
PDBMOD_MOD10:       .equ   10                                        ; Counter Modulus, bit 10
PDBMOD_MOD11:       .equ   11                                        ; Counter Modulus, bit 11
PDBMOD_MOD12:       .equ   12                                        ; Counter Modulus, bit 12
PDBMOD_MOD13:       .equ   13                                        ; Counter Modulus, bit 13
PDBMOD_MOD14:       .equ   14                                        ; Counter Modulus, bit 14
PDBMOD_MOD15:       .equ   15                                        ; Counter Modulus, bit 15
; bit position masks
mPDBMOD_MOD0:       .equ   %00000001
mPDBMOD_MOD1:       .equ   %00000010
mPDBMOD_MOD2:       .equ   %00000100
mPDBMOD_MOD3:       .equ   %00001000
mPDBMOD_MOD4:       .equ   %00010000
mPDBMOD_MOD5:       .equ   %00100000
mPDBMOD_MOD6:       .equ   %01000000
mPDBMOD_MOD7:       .equ   %10000000
mPDBMOD_MOD8:       .equ   %100000000
mPDBMOD_MOD9:       .equ   %1000000000
mPDBMOD_MOD10:      .equ   %10000000000
mPDBMOD_MOD11:      .equ   %100000000000
mPDBMOD_MOD12:      .equ   %1000000000000
mPDBMOD_MOD13:      .equ   %10000000000000
mPDBMOD_MOD14:      .equ   %100000000000000
mPDBMOD_MOD15:      .equ   %1000000000000000


;*** PDBCOUNT - PDB Counter Value Register; 0xFFFFE004 ***
PDBCOUNT:           .equ   $FFFFE004                                ;*** PDBCOUNT - PDB Counter Value Register; 0xFFFFE004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCOUNT_COUNT0:    .equ   0                                         ; Counter Value, bit 0
PDBCOUNT_COUNT1:    .equ   1                                         ; Counter Value, bit 1
PDBCOUNT_COUNT2:    .equ   2                                         ; Counter Value, bit 2
PDBCOUNT_COUNT3:    .equ   3                                         ; Counter Value, bit 3
PDBCOUNT_COUNT4:    .equ   4                                         ; Counter Value, bit 4
PDBCOUNT_COUNT5:    .equ   5                                         ; Counter Value, bit 5
PDBCOUNT_COUNT6:    .equ   6                                         ; Counter Value, bit 6
PDBCOUNT_COUNT7:    .equ   7                                         ; Counter Value, bit 7
PDBCOUNT_COUNT8:    .equ   8                                         ; Counter Value, bit 8
PDBCOUNT_COUNT9:    .equ   9                                         ; Counter Value, bit 9
PDBCOUNT_COUNT10:   .equ   10                                        ; Counter Value, bit 10
PDBCOUNT_COUNT11:   .equ   11                                        ; Counter Value, bit 11
PDBCOUNT_COUNT12:   .equ   12                                        ; Counter Value, bit 12
PDBCOUNT_COUNT13:   .equ   13                                        ; Counter Value, bit 13
PDBCOUNT_COUNT14:   .equ   14                                        ; Counter Value, bit 14
PDBCOUNT_COUNT15:   .equ   15                                        ; Counter Value, bit 15
; bit position masks
mPDBCOUNT_COUNT0:   .equ   %00000001
mPDBCOUNT_COUNT1:   .equ   %00000010
mPDBCOUNT_COUNT2:   .equ   %00000100
mPDBCOUNT_COUNT3:   .equ   %00001000
mPDBCOUNT_COUNT4:   .equ   %00010000
mPDBCOUNT_COUNT5:   .equ   %00100000
mPDBCOUNT_COUNT6:   .equ   %01000000
mPDBCOUNT_COUNT7:   .equ   %10000000
mPDBCOUNT_COUNT8:   .equ   %100000000
mPDBCOUNT_COUNT9:   .equ   %1000000000
mPDBCOUNT_COUNT10:  .equ   %10000000000
mPDBCOUNT_COUNT11:  .equ   %100000000000
mPDBCOUNT_COUNT12:  .equ   %1000000000000
mPDBCOUNT_COUNT13:  .equ   %10000000000000
mPDBCOUNT_COUNT14:  .equ   %100000000000000
mPDBCOUNT_COUNT15:  .equ   %1000000000000000


;*** PDBIDELAY - PDB Interrupt Delay Register; 0xFFFFE006 ***
PDBIDELAY:          .equ   $FFFFE006                                ;*** PDBIDELAY - PDB Interrupt Delay Register; 0xFFFFE006 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBIDELAY_IDELAY0:  .equ   0                                         ; Interrupt Delay, bit 0
PDBIDELAY_IDELAY1:  .equ   1                                         ; Interrupt Delay, bit 1
PDBIDELAY_IDELAY2:  .equ   2                                         ; Interrupt Delay, bit 2
PDBIDELAY_IDELAY3:  .equ   3                                         ; Interrupt Delay, bit 3
PDBIDELAY_IDELAY4:  .equ   4                                         ; Interrupt Delay, bit 4
PDBIDELAY_IDELAY5:  .equ   5                                         ; Interrupt Delay, bit 5
PDBIDELAY_IDELAY6:  .equ   6                                         ; Interrupt Delay, bit 6
PDBIDELAY_IDELAY7:  .equ   7                                         ; Interrupt Delay, bit 7
PDBIDELAY_IDELAY8:  .equ   8                                         ; Interrupt Delay, bit 8
PDBIDELAY_IDELAY9:  .equ   9                                         ; Interrupt Delay, bit 9
PDBIDELAY_IDELAY10: .equ   10                                        ; Interrupt Delay, bit 10
PDBIDELAY_IDELAY11: .equ   11                                        ; Interrupt Delay, bit 11
PDBIDELAY_IDELAY12: .equ   12                                        ; Interrupt Delay, bit 12
PDBIDELAY_IDELAY13: .equ   13                                        ; Interrupt Delay, bit 13
PDBIDELAY_IDELAY14: .equ   14                                        ; Interrupt Delay, bit 14
PDBIDELAY_IDELAY15: .equ   15                                        ; Interrupt Delay, bit 15
; bit position masks
mPDBIDELAY_IDELAY0: .equ   %00000001
mPDBIDELAY_IDELAY1: .equ   %00000010
mPDBIDELAY_IDELAY2: .equ   %00000100
mPDBIDELAY_IDELAY3: .equ   %00001000
mPDBIDELAY_IDELAY4: .equ   %00010000
mPDBIDELAY_IDELAY5: .equ   %00100000
mPDBIDELAY_IDELAY6: .equ   %01000000
mPDBIDELAY_IDELAY7: .equ   %10000000
mPDBIDELAY_IDELAY8: .equ   %100000000
mPDBIDELAY_IDELAY9: .equ   %1000000000
mPDBIDELAY_IDELAY10: .equ   %10000000000
mPDBIDELAY_IDELAY11: .equ   %100000000000
mPDBIDELAY_IDELAY12: .equ   %1000000000000
mPDBIDELAY_IDELAY13: .equ   %10000000000000
mPDBIDELAY_IDELAY14: .equ   %100000000000000
mPDBIDELAY_IDELAY15: .equ   %1000000000000000


;*** PDBCH1CR - PDB Channel 1 Control Register; 0xFFFFE008 ***
PDBCH1CR:           .equ   $FFFFE008                                ;*** PDBCH1CR - PDB Channel 1 Control Register; 0xFFFFE008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1CR_ENB:       .equ   0                                         ; Trigger B Enable
PDBCH1CR_ENA:       .equ   1                                         ; Trigger A Enable
PDBCH1CR_BOS0:      .equ   2                                         ; Channel 1 Trigger B Output Select, bit 0
PDBCH1CR_BOS1:      .equ   3                                         ; Channel 1 Trigger B Output Select, bit 1
PDBCH1CR_AOS0:      .equ   4                                         ; Channel 1 Trigger A Output Select, bit 0
PDBCH1CR_AOS1:      .equ   5                                         ; Channel 1 Trigger A Output Select, bit 1
; bit position masks
mPDBCH1CR_ENB:      .equ   %00000001
mPDBCH1CR_ENA:      .equ   %00000010
mPDBCH1CR_BOS0:     .equ   %00000100
mPDBCH1CR_BOS1:     .equ   %00001000
mPDBCH1CR_AOS0:     .equ   %00010000
mPDBCH1CR_AOS1:     .equ   %00100000


;*** PDBCH1DELA - PDB Channel 1 Delay A Register; 0xFFFFE00A ***
PDBCH1DELA:         .equ   $FFFFE00A                                ;*** PDBCH1DELA - PDB Channel 1 Delay A Register; 0xFFFFE00A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1DELA_DELAY0:  .equ   0                                         ; Delay A, bit 0
PDBCH1DELA_DELAY1:  .equ   1                                         ; Delay A, bit 1
PDBCH1DELA_DELAY2:  .equ   2                                         ; Delay A, bit 2
PDBCH1DELA_DELAY3:  .equ   3                                         ; Delay A, bit 3
PDBCH1DELA_DELAY4:  .equ   4                                         ; Delay A, bit 4
PDBCH1DELA_DELAY5:  .equ   5                                         ; Delay A, bit 5
PDBCH1DELA_DELAY6:  .equ   6                                         ; Delay A, bit 6
PDBCH1DELA_DELAY7:  .equ   7                                         ; Delay A, bit 7
PDBCH1DELA_DELAY8:  .equ   8                                         ; Delay A, bit 8
PDBCH1DELA_DELAY9:  .equ   9                                         ; Delay A, bit 9
PDBCH1DELA_DELAY10: .equ   10                                        ; Delay A, bit 10
PDBCH1DELA_DELAY11: .equ   11                                        ; Delay A, bit 11
PDBCH1DELA_DELAY12: .equ   12                                        ; Delay A, bit 12
PDBCH1DELA_DELAY13: .equ   13                                        ; Delay A, bit 13
PDBCH1DELA_DELAY14: .equ   14                                        ; Delay A, bit 14
PDBCH1DELA_DELAY15: .equ   15                                        ; Delay A, bit 15
; bit position masks
mPDBCH1DELA_DELAY0: .equ   %00000001
mPDBCH1DELA_DELAY1: .equ   %00000010
mPDBCH1DELA_DELAY2: .equ   %00000100
mPDBCH1DELA_DELAY3: .equ   %00001000
mPDBCH1DELA_DELAY4: .equ   %00010000
mPDBCH1DELA_DELAY5: .equ   %00100000
mPDBCH1DELA_DELAY6: .equ   %01000000
mPDBCH1DELA_DELAY7: .equ   %10000000
mPDBCH1DELA_DELAY8: .equ   %100000000
mPDBCH1DELA_DELAY9: .equ   %1000000000
mPDBCH1DELA_DELAY10: .equ   %10000000000
mPDBCH1DELA_DELAY11: .equ   %100000000000
mPDBCH1DELA_DELAY12: .equ   %1000000000000
mPDBCH1DELA_DELAY13: .equ   %10000000000000
mPDBCH1DELA_DELAY14: .equ   %100000000000000
mPDBCH1DELA_DELAY15: .equ   %1000000000000000


;*** PDBCH1DELB - PDB Channel 1 Delay B Register; 0xFFFFE00C ***
PDBCH1DELB:         .equ   $FFFFE00C                                ;*** PDBCH1DELB - PDB Channel 1 Delay B Register; 0xFFFFE00C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1DELB_DELAY0:  .equ   0                                         ; Delay B, bit 0
PDBCH1DELB_DELAY1:  .equ   1                                         ; Delay B, bit 1
PDBCH1DELB_DELAY2:  .equ   2                                         ; Delay B, bit 2
PDBCH1DELB_DELAY3:  .equ   3                                         ; Delay B, bit 3
PDBCH1DELB_DELAY4:  .equ   4                                         ; Delay B, bit 4
PDBCH1DELB_DELAY5:  .equ   5                                         ; Delay B, bit 5
PDBCH1DELB_DELAY6:  .equ   6                                         ; Delay B, bit 6
PDBCH1DELB_DELAY7:  .equ   7                                         ; Delay B, bit 7
PDBCH1DELB_DELAY8:  .equ   8                                         ; Delay B, bit 8
PDBCH1DELB_DELAY9:  .equ   9                                         ; Delay B, bit 9
PDBCH1DELB_DELAY10: .equ   10                                        ; Delay B, bit 10
PDBCH1DELB_DELAY11: .equ   11                                        ; Delay B, bit 11
PDBCH1DELB_DELAY12: .equ   12                                        ; Delay B, bit 12
PDBCH1DELB_DELAY13: .equ   13                                        ; Delay B, bit 13
PDBCH1DELB_DELAY14: .equ   14                                        ; Delay B, bit 14
PDBCH1DELB_DELAY15: .equ   15                                        ; Delay B, bit 15
; bit position masks
mPDBCH1DELB_DELAY0: .equ   %00000001
mPDBCH1DELB_DELAY1: .equ   %00000010
mPDBCH1DELB_DELAY2: .equ   %00000100
mPDBCH1DELB_DELAY3: .equ   %00001000
mPDBCH1DELB_DELAY4: .equ   %00010000
mPDBCH1DELB_DELAY5: .equ   %00100000
mPDBCH1DELB_DELAY6: .equ   %01000000
mPDBCH1DELB_DELAY7: .equ   %10000000
mPDBCH1DELB_DELAY8: .equ   %100000000
mPDBCH1DELB_DELAY9: .equ   %1000000000
mPDBCH1DELB_DELAY10: .equ   %10000000000
mPDBCH1DELB_DELAY11: .equ   %100000000000
mPDBCH1DELB_DELAY12: .equ   %1000000000000
mPDBCH1DELB_DELAY13: .equ   %10000000000000
mPDBCH1DELB_DELAY14: .equ   %100000000000000
mPDBCH1DELB_DELAY15: .equ   %1000000000000000


;*** PDBCH2CR - PDB Channel 2 Control Register; 0xFFFFE010 ***
PDBCH2CR:           .equ   $FFFFE010                                ;*** PDBCH2CR - PDB Channel 2 Control Register; 0xFFFFE010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2CR_ENB:       .equ   0                                         ; Trigger B Enable
PDBCH2CR_ENA:       .equ   1                                         ; Trigger A Enable
PDBCH2CR_BOS0:      .equ   2                                         ; Channel 2 Trigger B Output Select, bit 0
PDBCH2CR_BOS1:      .equ   3                                         ; Channel 2 Trigger B Output Select, bit 1
PDBCH2CR_AOS0:      .equ   4                                         ; Channel 2 Trigger A Output Select, bit 0
PDBCH2CR_AOS1:      .equ   5                                         ; Channel 2 Trigger A Output Select, bit 1
; bit position masks
mPDBCH2CR_ENB:      .equ   %00000001
mPDBCH2CR_ENA:      .equ   %00000010
mPDBCH2CR_BOS0:     .equ   %00000100
mPDBCH2CR_BOS1:     .equ   %00001000
mPDBCH2CR_AOS0:     .equ   %00010000
mPDBCH2CR_AOS1:     .equ   %00100000


;*** PDBCH2DELA - PDB Channel 2 Delay A Register; 0xFFFFE012 ***
PDBCH2DELA:         .equ   $FFFFE012                                ;*** PDBCH2DELA - PDB Channel 2 Delay A Register; 0xFFFFE012 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2DELA_DELAY0:  .equ   0                                         ; Delay A, bit 0
PDBCH2DELA_DELAY1:  .equ   1                                         ; Delay A, bit 1
PDBCH2DELA_DELAY2:  .equ   2                                         ; Delay A, bit 2
PDBCH2DELA_DELAY3:  .equ   3                                         ; Delay A, bit 3
PDBCH2DELA_DELAY4:  .equ   4                                         ; Delay A, bit 4
PDBCH2DELA_DELAY5:  .equ   5                                         ; Delay A, bit 5
PDBCH2DELA_DELAY6:  .equ   6                                         ; Delay A, bit 6
PDBCH2DELA_DELAY7:  .equ   7                                         ; Delay A, bit 7
PDBCH2DELA_DELAY8:  .equ   8                                         ; Delay A, bit 8
PDBCH2DELA_DELAY9:  .equ   9                                         ; Delay A, bit 9
PDBCH2DELA_DELAY10: .equ   10                                        ; Delay A, bit 10
PDBCH2DELA_DELAY11: .equ   11                                        ; Delay A, bit 11
PDBCH2DELA_DELAY12: .equ   12                                        ; Delay A, bit 12
PDBCH2DELA_DELAY13: .equ   13                                        ; Delay A, bit 13
PDBCH2DELA_DELAY14: .equ   14                                        ; Delay A, bit 14
PDBCH2DELA_DELAY15: .equ   15                                        ; Delay A, bit 15
; bit position masks
mPDBCH2DELA_DELAY0: .equ   %00000001
mPDBCH2DELA_DELAY1: .equ   %00000010
mPDBCH2DELA_DELAY2: .equ   %00000100
mPDBCH2DELA_DELAY3: .equ   %00001000
mPDBCH2DELA_DELAY4: .equ   %00010000
mPDBCH2DELA_DELAY5: .equ   %00100000
mPDBCH2DELA_DELAY6: .equ   %01000000
mPDBCH2DELA_DELAY7: .equ   %10000000
mPDBCH2DELA_DELAY8: .equ   %100000000
mPDBCH2DELA_DELAY9: .equ   %1000000000
mPDBCH2DELA_DELAY10: .equ   %10000000000
mPDBCH2DELA_DELAY11: .equ   %100000000000
mPDBCH2DELA_DELAY12: .equ   %1000000000000
mPDBCH2DELA_DELAY13: .equ   %10000000000000
mPDBCH2DELA_DELAY14: .equ   %100000000000000
mPDBCH2DELA_DELAY15: .equ   %1000000000000000


;*** PDBCH2DELB - PDB Channel 2 Delay B Register; 0xFFFFE014 ***
PDBCH2DELB:         .equ   $FFFFE014                                ;*** PDBCH2DELB - PDB Channel 2 Delay B Register; 0xFFFFE014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2DELB_DELAY0:  .equ   0                                         ; Delay B, bit 0
PDBCH2DELB_DELAY1:  .equ   1                                         ; Delay B, bit 1
PDBCH2DELB_DELAY2:  .equ   2                                         ; Delay B, bit 2
PDBCH2DELB_DELAY3:  .equ   3                                         ; Delay B, bit 3
PDBCH2DELB_DELAY4:  .equ   4                                         ; Delay B, bit 4
PDBCH2DELB_DELAY5:  .equ   5                                         ; Delay B, bit 5
PDBCH2DELB_DELAY6:  .equ   6                                         ; Delay B, bit 6
PDBCH2DELB_DELAY7:  .equ   7                                         ; Delay B, bit 7
PDBCH2DELB_DELAY8:  .equ   8                                         ; Delay B, bit 8
PDBCH2DELB_DELAY9:  .equ   9                                         ; Delay B, bit 9
PDBCH2DELB_DELAY10: .equ   10                                        ; Delay B, bit 10
PDBCH2DELB_DELAY11: .equ   11                                        ; Delay B, bit 11
PDBCH2DELB_DELAY12: .equ   12                                        ; Delay B, bit 12
PDBCH2DELB_DELAY13: .equ   13                                        ; Delay B, bit 13
PDBCH2DELB_DELAY14: .equ   14                                        ; Delay B, bit 14
PDBCH2DELB_DELAY15: .equ   15                                        ; Delay B, bit 15
; bit position masks
mPDBCH2DELB_DELAY0: .equ   %00000001
mPDBCH2DELB_DELAY1: .equ   %00000010
mPDBCH2DELB_DELAY2: .equ   %00000100
mPDBCH2DELB_DELAY3: .equ   %00001000
mPDBCH2DELB_DELAY4: .equ   %00010000
mPDBCH2DELB_DELAY5: .equ   %00100000
mPDBCH2DELB_DELAY6: .equ   %01000000
mPDBCH2DELB_DELAY7: .equ   %10000000
mPDBCH2DELB_DELAY8: .equ   %100000000
mPDBCH2DELB_DELAY9: .equ   %1000000000
mPDBCH2DELB_DELAY10: .equ   %10000000000
mPDBCH2DELB_DELAY11: .equ   %100000000000
mPDBCH2DELB_DELAY12: .equ   %1000000000000
mPDBCH2DELB_DELAY13: .equ   %10000000000000
mPDBCH2DELB_DELAY14: .equ   %100000000000000
mPDBCH2DELB_DELAY15: .equ   %1000000000000000


;*** PDBCH3CR - PDB Channel 3 Control Register; 0xFFFFE018 ***
PDBCH3CR:           .equ   $FFFFE018                                ;*** PDBCH3CR - PDB Channel 3 Control Register; 0xFFFFE018 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH3CR_ENB:       .equ   0                                         ; Trigger B Enable
PDBCH3CR_ENA:       .equ   1                                         ; Trigger A Enable
PDBCH3CR_BOS0:      .equ   2                                         ; Channel 3 Trigger B Output Select, bit 0
PDBCH3CR_BOS1:      .equ   3                                         ; Channel 3 Trigger B Output Select, bit 1
PDBCH3CR_AOS0:      .equ   4                                         ; Channel 3 Trigger A Output Select, bit 0
PDBCH3CR_AOS1:      .equ   5                                         ; Channel 3 Trigger A Output Select, bit 1
; bit position masks
mPDBCH3CR_ENB:      .equ   %00000001
mPDBCH3CR_ENA:      .equ   %00000010
mPDBCH3CR_BOS0:     .equ   %00000100
mPDBCH3CR_BOS1:     .equ   %00001000
mPDBCH3CR_AOS0:     .equ   %00010000
mPDBCH3CR_AOS1:     .equ   %00100000


;*** PDBCH3DELA - PDB Channel 3 Delay A Register; 0xFFFFE01A ***
PDBCH3DELA:         .equ   $FFFFE01A                                ;*** PDBCH3DELA - PDB Channel 3 Delay A Register; 0xFFFFE01A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH3DELA_DELAY0:  .equ   0                                         ; Delay A, bit 0
PDBCH3DELA_DELAY1:  .equ   1                                         ; Delay A, bit 1
PDBCH3DELA_DELAY2:  .equ   2                                         ; Delay A, bit 2
PDBCH3DELA_DELAY3:  .equ   3                                         ; Delay A, bit 3
PDBCH3DELA_DELAY4:  .equ   4                                         ; Delay A, bit 4
PDBCH3DELA_DELAY5:  .equ   5                                         ; Delay A, bit 5
PDBCH3DELA_DELAY6:  .equ   6                                         ; Delay A, bit 6
PDBCH3DELA_DELAY7:  .equ   7                                         ; Delay A, bit 7
PDBCH3DELA_DELAY8:  .equ   8                                         ; Delay A, bit 8
PDBCH3DELA_DELAY9:  .equ   9                                         ; Delay A, bit 9
PDBCH3DELA_DELAY10: .equ   10                                        ; Delay A, bit 10
PDBCH3DELA_DELAY11: .equ   11                                        ; Delay A, bit 11
PDBCH3DELA_DELAY12: .equ   12                                        ; Delay A, bit 12
PDBCH3DELA_DELAY13: .equ   13                                        ; Delay A, bit 13
PDBCH3DELA_DELAY14: .equ   14                                        ; Delay A, bit 14
PDBCH3DELA_DELAY15: .equ   15                                        ; Delay A, bit 15
; bit position masks
mPDBCH3DELA_DELAY0: .equ   %00000001
mPDBCH3DELA_DELAY1: .equ   %00000010
mPDBCH3DELA_DELAY2: .equ   %00000100
mPDBCH3DELA_DELAY3: .equ   %00001000
mPDBCH3DELA_DELAY4: .equ   %00010000
mPDBCH3DELA_DELAY5: .equ   %00100000
mPDBCH3DELA_DELAY6: .equ   %01000000
mPDBCH3DELA_DELAY7: .equ   %10000000
mPDBCH3DELA_DELAY8: .equ   %100000000
mPDBCH3DELA_DELAY9: .equ   %1000000000
mPDBCH3DELA_DELAY10: .equ   %10000000000
mPDBCH3DELA_DELAY11: .equ   %100000000000
mPDBCH3DELA_DELAY12: .equ   %1000000000000
mPDBCH3DELA_DELAY13: .equ   %10000000000000
mPDBCH3DELA_DELAY14: .equ   %100000000000000
mPDBCH3DELA_DELAY15: .equ   %1000000000000000


;*** PDBCH3DELB - PDB Channel 3 Delay B Register; 0xFFFFE01C ***
PDBCH3DELB:         .equ   $FFFFE01C                                ;*** PDBCH3DELB - PDB Channel 3 Delay B Register; 0xFFFFE01C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH3DELB_DELAY0:  .equ   0                                         ; Delay B, bit 0
PDBCH3DELB_DELAY1:  .equ   1                                         ; Delay B, bit 1
PDBCH3DELB_DELAY2:  .equ   2                                         ; Delay B, bit 2
PDBCH3DELB_DELAY3:  .equ   3                                         ; Delay B, bit 3
PDBCH3DELB_DELAY4:  .equ   4                                         ; Delay B, bit 4
PDBCH3DELB_DELAY5:  .equ   5                                         ; Delay B, bit 5
PDBCH3DELB_DELAY6:  .equ   6                                         ; Delay B, bit 6
PDBCH3DELB_DELAY7:  .equ   7                                         ; Delay B, bit 7
PDBCH3DELB_DELAY8:  .equ   8                                         ; Delay B, bit 8
PDBCH3DELB_DELAY9:  .equ   9                                         ; Delay B, bit 9
PDBCH3DELB_DELAY10: .equ   10                                        ; Delay B, bit 10
PDBCH3DELB_DELAY11: .equ   11                                        ; Delay B, bit 11
PDBCH3DELB_DELAY12: .equ   12                                        ; Delay B, bit 12
PDBCH3DELB_DELAY13: .equ   13                                        ; Delay B, bit 13
PDBCH3DELB_DELAY14: .equ   14                                        ; Delay B, bit 14
PDBCH3DELB_DELAY15: .equ   15                                        ; Delay B, bit 15
; bit position masks
mPDBCH3DELB_DELAY0: .equ   %00000001
mPDBCH3DELB_DELAY1: .equ   %00000010
mPDBCH3DELB_DELAY2: .equ   %00000100
mPDBCH3DELB_DELAY3: .equ   %00001000
mPDBCH3DELB_DELAY4: .equ   %00010000
mPDBCH3DELB_DELAY5: .equ   %00100000
mPDBCH3DELB_DELAY6: .equ   %01000000
mPDBCH3DELB_DELAY7: .equ   %10000000
mPDBCH3DELB_DELAY8: .equ   %100000000
mPDBCH3DELB_DELAY9: .equ   %1000000000
mPDBCH3DELB_DELAY10: .equ   %10000000000
mPDBCH3DELB_DELAY11: .equ   %100000000000
mPDBCH3DELB_DELAY12: .equ   %1000000000000
mPDBCH3DELB_DELAY13: .equ   %10000000000000
mPDBCH3DELB_DELAY14: .equ   %100000000000000
mPDBCH3DELB_DELAY15: .equ   %1000000000000000


;*** PDBCH4CR - PDB Channel 4 Control Register; 0xFFFFE020 ***
PDBCH4CR:           .equ   $FFFFE020                                ;*** PDBCH4CR - PDB Channel 4 Control Register; 0xFFFFE020 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH4CR_ENB:       .equ   0                                         ; Trigger B Enable
PDBCH4CR_ENA:       .equ   1                                         ; Trigger A Enable
PDBCH4CR_BOS0:      .equ   2                                         ; Channel 4 Trigger B Output Select, bit 0
PDBCH4CR_BOS1:      .equ   3                                         ; Channel 4 Trigger B Output Select, bit 1
PDBCH4CR_AOS0:      .equ   4                                         ; Channel 4 Trigger A Output Select, bit 0
PDBCH4CR_AOS1:      .equ   5                                         ; Channel 4 Trigger A Output Select, bit 1
; bit position masks
mPDBCH4CR_ENB:      .equ   %00000001
mPDBCH4CR_ENA:      .equ   %00000010
mPDBCH4CR_BOS0:     .equ   %00000100
mPDBCH4CR_BOS1:     .equ   %00001000
mPDBCH4CR_AOS0:     .equ   %00010000
mPDBCH4CR_AOS1:     .equ   %00100000


;*** PDBCH4DELA - PDB Channel 4 Delay A Register; 0xFFFFE022 ***
PDBCH4DELA:         .equ   $FFFFE022                                ;*** PDBCH4DELA - PDB Channel 4 Delay A Register; 0xFFFFE022 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH4DELA_DELAY0:  .equ   0                                         ; Delay A, bit 0
PDBCH4DELA_DELAY1:  .equ   1                                         ; Delay A, bit 1
PDBCH4DELA_DELAY2:  .equ   2                                         ; Delay A, bit 2
PDBCH4DELA_DELAY3:  .equ   3                                         ; Delay A, bit 3
PDBCH4DELA_DELAY4:  .equ   4                                         ; Delay A, bit 4
PDBCH4DELA_DELAY5:  .equ   5                                         ; Delay A, bit 5
PDBCH4DELA_DELAY6:  .equ   6                                         ; Delay A, bit 6
PDBCH4DELA_DELAY7:  .equ   7                                         ; Delay A, bit 7
PDBCH4DELA_DELAY8:  .equ   8                                         ; Delay A, bit 8
PDBCH4DELA_DELAY9:  .equ   9                                         ; Delay A, bit 9
PDBCH4DELA_DELAY10: .equ   10                                        ; Delay A, bit 10
PDBCH4DELA_DELAY11: .equ   11                                        ; Delay A, bit 11
PDBCH4DELA_DELAY12: .equ   12                                        ; Delay A, bit 12
PDBCH4DELA_DELAY13: .equ   13                                        ; Delay A, bit 13
PDBCH4DELA_DELAY14: .equ   14                                        ; Delay A, bit 14
PDBCH4DELA_DELAY15: .equ   15                                        ; Delay A, bit 15
; bit position masks
mPDBCH4DELA_DELAY0: .equ   %00000001
mPDBCH4DELA_DELAY1: .equ   %00000010
mPDBCH4DELA_DELAY2: .equ   %00000100
mPDBCH4DELA_DELAY3: .equ   %00001000
mPDBCH4DELA_DELAY4: .equ   %00010000
mPDBCH4DELA_DELAY5: .equ   %00100000
mPDBCH4DELA_DELAY6: .equ   %01000000
mPDBCH4DELA_DELAY7: .equ   %10000000
mPDBCH4DELA_DELAY8: .equ   %100000000
mPDBCH4DELA_DELAY9: .equ   %1000000000
mPDBCH4DELA_DELAY10: .equ   %10000000000
mPDBCH4DELA_DELAY11: .equ   %100000000000
mPDBCH4DELA_DELAY12: .equ   %1000000000000
mPDBCH4DELA_DELAY13: .equ   %10000000000000
mPDBCH4DELA_DELAY14: .equ   %100000000000000
mPDBCH4DELA_DELAY15: .equ   %1000000000000000


;*** PDBCH4DELB - PDB Channel 4 Delay B Register; 0xFFFFE024 ***
PDBCH4DELB:         .equ   $FFFFE024                                ;*** PDBCH4DELB - PDB Channel 4 Delay B Register; 0xFFFFE024 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH4DELB_DELAY0:  .equ   0                                         ; Delay B, bit 0
PDBCH4DELB_DELAY1:  .equ   1                                         ; Delay B, bit 1
PDBCH4DELB_DELAY2:  .equ   2                                         ; Delay B, bit 2
PDBCH4DELB_DELAY3:  .equ   3                                         ; Delay B, bit 3
PDBCH4DELB_DELAY4:  .equ   4                                         ; Delay B, bit 4
PDBCH4DELB_DELAY5:  .equ   5                                         ; Delay B, bit 5
PDBCH4DELB_DELAY6:  .equ   6                                         ; Delay B, bit 6
PDBCH4DELB_DELAY7:  .equ   7                                         ; Delay B, bit 7
PDBCH4DELB_DELAY8:  .equ   8                                         ; Delay B, bit 8
PDBCH4DELB_DELAY9:  .equ   9                                         ; Delay B, bit 9
PDBCH4DELB_DELAY10: .equ   10                                        ; Delay B, bit 10
PDBCH4DELB_DELAY11: .equ   11                                        ; Delay B, bit 11
PDBCH4DELB_DELAY12: .equ   12                                        ; Delay B, bit 12
PDBCH4DELB_DELAY13: .equ   13                                        ; Delay B, bit 13
PDBCH4DELB_DELAY14: .equ   14                                        ; Delay B, bit 14
PDBCH4DELB_DELAY15: .equ   15                                        ; Delay B, bit 15
; bit position masks
mPDBCH4DELB_DELAY0: .equ   %00000001
mPDBCH4DELB_DELAY1: .equ   %00000010
mPDBCH4DELB_DELAY2: .equ   %00000100
mPDBCH4DELB_DELAY3: .equ   %00001000
mPDBCH4DELB_DELAY4: .equ   %00010000
mPDBCH4DELB_DELAY5: .equ   %00100000
mPDBCH4DELB_DELAY6: .equ   %01000000
mPDBCH4DELB_DELAY7: .equ   %10000000
mPDBCH4DELB_DELAY8: .equ   %100000000
mPDBCH4DELB_DELAY9: .equ   %1000000000
mPDBCH4DELB_DELAY10: .equ   %10000000000
mPDBCH4DELB_DELAY11: .equ   %100000000000
mPDBCH4DELB_DELAY12: .equ   %1000000000000
mPDBCH4DELB_DELAY13: .equ   %10000000000000
mPDBCH4DELB_DELAY14: .equ   %100000000000000
mPDBCH4DELB_DELAY15: .equ   %1000000000000000


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

; EOF
