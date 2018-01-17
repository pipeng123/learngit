/*
 * File:    mcf5xxx.s
 * Purpose: Lowest level routines for all ColdFire processors.
 *
 * Notes:  
 *
 */

  
    .global asm_set_ipl
    .global _asm_set_ipl
    .global _mcf5xxx_byterev
      
    .text


  
/********************************************************************/
/*
 * This routines changes the IPL to the value passed into the routine.
 * It also returns the old IPL value back.
 * Calling convention from C:
 *   old_ipl = asm_set_ipl(new_ipl);
 * For the Diab Data C compiler, it passes return value thru D0.
 * Note that only the least significant three bits of the passed
 * value are used.
 */

asm_set_ipl:
_asm_set_ipl:
    link    A6,#-12
    movem.l D6-D7,(SP)
    
    move.w  SR,D7       /* current sr    */

    move.l  D7,D6       /* prepare return value  */
    andi.l  #0x0700,D6  /* mask out IPL  */
    lsr.l   #8,D6       /* IPL   */

    
    andi.l  #0x07,D0        /* least significant three bits  */
    lsl.l   #8,D0           /* move over to make mask    */

    andi.l  #0x0000F8FF,D7  /* zero out current IPL  */
    or.l    D0,D7           /* place new IPL in sr   */
    move.w  D7,SR
    
    move.w  d6,d0
    movem.l (SP),D6-D7
    lea     8(SP),SP
    unlk    A6
    rts


_mcf5xxx_byterev:
    .short   0x02c0      /* byterev.l, D0   */
    rts  
  

/********************************************************************/
    .end
