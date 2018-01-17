/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      pll.h
*
* @author    r30323
* 
* @version   1.0.1.0
* 
* @date      Apr-11-2006
* 
* @brief     Clock Generator Module setting
*
*******************************************************************************/

#ifndef _PLL_H_
#define _PLL_H_

//-------------------------------------------------------------------
// PLL Start
// Description: 
// Enable PLL module and set bus to 8MHz
//-------------------------------------------------------------------

void PllStart(void);
void PllStop(void);

#endif /* _PLL_H_ */