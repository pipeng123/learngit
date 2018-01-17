        XDEF bl_boot_table
        XDEF boot_table

        XDEF usr_boot_table

        XDEF VEC0 
        XDEF VEC1 
        XDEF VEC2 
        XDEF VEC3 
        XDEF VEC4 
        XDEF VEC5 
        XDEF VEC6 
        XDEF VEC7 
        XDEF VEC8 
        XDEF VEC9 
        XDEF VEC10
        XDEF VEC11
        XDEF VEC12
        XDEF VEC13
        XDEF VEC14
        XDEF VEC15
        XDEF VEC16

        XREF USB_SYS_ISR
        XREF USB_EP_ISR

SIG_BOOT EQU    $FC
    

;    XREF TIM_CH0_ISR
;    XREF TIM_CH1_ISR

TIM_CH0_ISR  equ $fffe
TIM_CH1_ISR  equ $fffe
TIM_OVF_ISR  equ $fffe

BLVECTROM: SECTION    
bl_boot_table:   

        DC.B    0,0,0,0,0,0,0,0
        jmp     $fffe        ; 0
        jmp     $fffe        ; 1
        jmp     USB_SYS_ISR  ; 2
        jmp     USB_EP_ISR   ; 3
        jmp     $fffe        ; 4
        jmp     $fffe        ; 5
        jmp     TIM_CH0_ISR  ; 6
        jmp     TIM_CH1_ISR  ; 7
        jmp     TIM_OVF_ISR  ; 8
        jmp     $fffe        ; 9
        jmp     $fffe        ; 10
        jmp     $fffe        ; 11
        jmp     $fffe        ; 12
        jmp     $fffe        ; 13
        jmp     $fffe        ; 14
        jmp     $fffe        ; 15
        jmp     $fffe        ; 16

        DC.B    SIG_BOOT


VECTROM:    SECTION     
boot_table:      

        DC.B     0,0,0,0,0,0,0,0
VEC0:   jmp     $fffe        ; 0
VEC1:   jmp     $fffe        ; 1
VEC2:   jmp     USB_SYS_ISR     ; 2
VEC3:   jmp     USB_EP_ISR     ; 3
VEC4:   jmp     $fffe        ; 4
VEC5:   jmp     $fffe        ; 5
VEC6:   jmp     TIM_CH0_ISR   ; 6
VEC7:   jmp     TIM_CH1_ISR   ; 7
VEC8:   jmp     TIM_OVF_ISR   ; 8
VEC9:   jmp     $fffe        ; 9
VEC10:  jmp     $fffe        ; 10
VEC11:  jmp     $fffe        ; 11
VEC12:  jmp     $fffe        ; 12
VEC13:  jmp     $fffe        ; 13
VEC14:  jmp     $fffe        ; 14
VEC15:  jmp     $fffe        ; 15
VEC16:  jmp     $fffe        ; 16

        DC.B    SIG_BOOT

USRVECTROM:    SECTION     
usr_boot_table:      

; actually nothing in there, this space is populated by bootloader