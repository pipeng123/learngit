/*
 * File:   mcf5xxx_vectors.asm
 * Purpose:   ColdFire vector table
 */

.global VECTOR_TABLE
.global _VECTOR_TABLE

.extern __SP_INIT
.extern _asm_startmeup
   
.text
   
/*
 * Exception Vector Table
 */
VECTOR_TABLE:
_VECTOR_TABLE:

INITSP:        .long   __SP_INIT                /* Initial SP         */
INITPC:        .long   _asm_startmeup           /* Initial PC         */


.end
