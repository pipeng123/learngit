/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      pll.c
*
* @author    r30323
* 
* @version   1.0.3.0
* 
* @date      Oct-11-2011
* 
* @brief     Brief description of the file
*
*******************************************************************************
*
* Detailed Description of the file. If not used, remove the separator above.
*
******************************************************************************/
#include "map.h"
#include "global.h"
#include "pll.h"

void PllStart(void)
{
  PCTL = 0;  // disable PLL 
  PMS = PMSINIT;    // PMSINIT externally defined 6 for 4MHz, 4 for ZSTAR
  PMRS = 0x60;
  PMDS = PMDS_RDS0_MASK;
  PBWC = PBWC_AUTO_MASK;
  PCTL = PCTL_PRE0_MASK | PCTL_VPR1_MASK;
  PCTL |= PCTL_PLLON_MASK;
  
  // wait untill phase loop is locked
  while (!(PBWC & PBWC_LOCK_MASK))
    DO_NOTHING();

  PCTL |= PCTL_BCS_MASK;    
}

void PllStop(void)
{
  PCTL &= ~PCTL_BCS_MASK;                     // Stop PLL
  PCTL = 0;
}