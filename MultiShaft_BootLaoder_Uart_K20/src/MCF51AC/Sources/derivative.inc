; include derivative specific macros
           
           .IF(SIZE==128)
            .IF(TYPE=="A")
              .INCLUDE 'MCF51AC128A.inc'
            .ELSEIF(TYPE=="C")
              .INCLUDE 'MCF51AC128C.inc'
            .ENDIF  
           .ELSEIF(SIZE==256)
            .IF(TYPE=="A")
              .INCLUDE 'MCF51AC256A.inc'
            .ELSEIF(TYPE=="B")
              .INCLUDE 'MCF51AC256B.inc'
            .ENDIF
           .ENDIF
         
; RAM/ROM definitions
