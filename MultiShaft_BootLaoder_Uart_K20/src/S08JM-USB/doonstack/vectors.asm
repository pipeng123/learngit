    XDEF bl_boot_table
    XDEF boot_table
    XDEF usr_boot_table
    
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
    XDEF VEC17
    XDEF VEC18
    XDEF VEC19
    XDEF VEC20
    XDEF VEC21
    XDEF VEC22
    XDEF VEC23
    XDEF VEC24
    XDEF VEC25
    XDEF VEC26
    XDEF VEC27
    XDEF VEC28
    XDEF VEC29
    XDEF VEC30
    XDEF VEC31
   
SIG_BOOT EQU    $FC

BLVECTROM:     SECTION   ;blank boot vector table
bl_boot_table:
   
    DC.B     SIG_BOOT       

    
VECTROM:    SECTION      ;new redirected boot vector table, address (0xDFC0-0xDFFD)
boot_table:    

    DC.B    SIG_BOOT
    VEC31:     
    VEC30:     
    VEC29:     
    VEC28:     
    VEC27:     
    VEC26:     
    VEC25:     
    VEC24:     
    VEC23:     
    VEC22:    
    VEC21:    
    VEC20:   
    VEC19:    
    VEC18:    
    VEC17:    
    VEC16:   
    VEC15:    
    VEC14:   
    VEC13:    
    VEC12:    
    VEC11:   
    VEC10:  
    VEC9:    
    VEC8:    
    VEC7:    
    VEC6:    
    VEC5:    
    VEC4:    
    VEC3:    
    VEC2:    
    VEC1:
  
 

USRVECTROM:    SECTION    ;user boot vector table 
usr_boot_table:    
