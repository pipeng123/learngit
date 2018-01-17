#ifndef _GLOBAL_H
#define _GLOBAL_H

#define DO_NOTHING() {asm "NOP"}

#define PTE_INI PTE &= ~(PTE_PTE4_MASK |PTE_PTE6_MASK);\
                DDRE |= (DDRE_DDRE4_MASK | DDRE_DDRE6_MASK)
                 
#define PTE6H   PTE |= PTE_PTE6_MASK
#define PTE6L   PTE &= ~PTE_PTE6_MASK

#define PTE4H   PTE |= PTE_PTE4_MASK      
#define PTE4L   PTE &= ~PTE_PTE4_MASK


#endif