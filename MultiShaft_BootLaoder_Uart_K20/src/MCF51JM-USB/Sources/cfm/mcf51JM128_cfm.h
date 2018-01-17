/*
 * File:    mcf51jm128_cfm.h
 * Purpose: Register and bit definitions
 */

#ifndef __MCF51JM128_CFM_H__
#define __MCF51JM128_CFM_H__

#include "derivative.h"

/*********************************************************************
*
* ColdFire Flash Module 
*********************************************************************/

/* Register read/write macros */




#define MCF_CFM_CFMMCR              (*(vuint16*)(&__IPSBAR[0x1D0000]))
#define MCF_CFM_CFMSEC              (*(vuint32*)(&__IPSBAR[0x1D0008]))
#define MCF_CFM_CFMSACC             (*(vuint32*)(&__IPSBAR[0x1D0014]))
#define MCF_CFM_CFMDACC             (*(vuint32*)(&__IPSBAR[0x1D0018]))   

#define MCF_CFM_CFMCLKD             FCDIV
#define MCF_CFM_CFMUSTAT            FSTAT
#define MCF_CFM_CFMCMD              FCMD    

/* Bit definitions and macros for CFMCLKD */


#define MCF_CFM_CFMCLKD_DIV(x)      (((x)&0x3F))
#define MCF_CFM_CFMCLKD_PRDIV8      (0x40)
#define MCF_CFM_CFMCLKD_DIVLD       (0x80)
                                           
/* Bit definitions and macros for CFMUSTAT */

#define MCF_CFM_CFMUSTAT_BLANK      (0x04)
#define MCF_CFM_CFMUSTAT_ACCERR     (0x10)
#define MCF_CFM_CFMUSTAT_PVIOL      (0x20)
#define MCF_CFM_CFMUSTAT_CCIF       (0x40)
#define MCF_CFM_CFMUSTAT_CBEIF      (0x80)

/* Bit definitions and macros for FCMD register */      

#define MCF_CFM_CFMCMD_CMD(x)       (((x)&0x7F))    
#define MCF_CFM_CFMCMD_RDARY1       (0x05)
#define MCF_CFM_CFMCMD_PGM          (0x20)
#define MCF_CFM_CFMCMD_PGM_BURST    (0x25)
     

/* Bit definitions and macros for FCMD register */       

#define ERASE_VERIFY                (0x05)
#define PROGRAM                     (0x20)
#define BURST_PROGRAM               (0x25)
#define SECTOR_ERASE                (0x40)
#define MASS_ERASE                  (0x41)


/********************************************************************/

#endif /* __MCF51JM128_CFM_H__ */
