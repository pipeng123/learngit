/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      usb_driver.h
*
* @author    B01119
* 
* @version   1.0.4.0
* 
* @date      Oct-11-2011
* 
* @brief     usb_driver.c module header
*
*******************************************************************************/

#ifndef _USB_DRIVER_H
#define _USB_DRIVER_H

#include <stdtypes.h>

// EP1 API functions
uchar USB_GetRxReady1(void);
uchar USB_RxChar1(void);
uchar USB_RxBuff1(uchar* adr, uchar cnt);
uchar USB_RxBuffPending1(void);

uchar USB_GetTxEmpty1(void);
uchar USB_TxChar1(uchar ch);
uchar USB_TxBuff1(uchar* adr, uchar cnt);
uchar USB_TxBuffPending1(void);
uchar USB_TxFlush1(void);

#define USB_WRSTALL_EP1(x)  (UEP1CSR_STALL=x)
#define USB_RDSTALL_EP1    UEP1CSR_STALL


extern void USB_RxReadyCB0(void);
// EP1 API functions call back
extern void USB_RxReadyCB1(uchar cnt);
extern void USB_RxReadyCBdisable1(void);
extern void USB_RxReadyCBenable1(void);

extern void USB_TxEmptyCB1(uchar cnt);
extern void USB_TxEmptyCBdisable1(void);
extern void USB_TxEmptyCBenable1(void);


// EP2 API functions
uchar USB_GetRxReady2(void);
uchar USB_RxChar2(void);
uchar USB_RxBuff2(uchar* adr, uchar cnt);
uchar USB_RxBuffPending2(void);

uchar USB_GetTxEmpty2(void);
uchar USB_TxChar2(uchar ch);
uchar USB_TxBuff2(uchar* adr, uchar cnt);
uchar USB_TxBuffPending2(void);
uchar USB_TxFlush2(void);

#define USB_WRSTALL_EP2(x)  (UEP2CSR_STALL=x)
#define USB_RDSTALL_EP2    UEP2CSR_STALL

// EP2 API functions call back
extern void USB_RxReadyCB2(uchar cnt);
extern void USB_RxReadyCBdisable2(void);
extern void USB_RxReadyCBenable2(void);

extern void USB_TxEmptyCB2(uchar cnt);
extern void USB_TxEmptyCBdisable2(void);
extern void USB_TxEmptyCBenable2(void);

// EP3 API functions direct
uchar USB_GetRxReady3(void);
uchar USB_RxChar3(void);
uchar USB_RxBuff3(uchar* adr, uchar cnt);
uchar USB_RxBuffPending3(void);

uchar USB_GetTxEmpty3(void);
uchar USB_TxChar3(uchar ch);
uchar USB_TxBuff3(uchar* adr, uchar cnt);
uchar USB_TxBuffPending3(void);
uchar USB_TxFlush3(void);

#define USB_WRSTALL_EP3(x)  (UEP3CSR_STALL=x)
#define USB_RDSTALL_EP3    UEP3CSR_STALL

// EP3 API functions call back
extern void USB_RxReadyCB3(uchar cnt);
extern void USB_RxReadyCBdisable3(void);
extern void USB_RxReadyCBenable3(void);

extern void USB_TxEmptyCB3(uchar cnt);
extern void USB_TxEmptyCBdisable3(void);
extern void USB_TxEmptyCBenable3(void);


// EP4 API functions
uchar USB_GetRxReady4(void);
uchar USB_RxChar4(void);
uchar USB_RxBuff4(uchar* adr, uchar cnt);
uchar USB_RxBuffPending4(void);

uchar USB_GetTxEmpty4(void);
uchar USB_TxChar4(uchar ch);
uchar USB_TxBuff4(uchar* adr, uchar cnt);
uchar USB_TxBuffPending4(void);
uchar USB_TxFlush4(void);

#define USB_WRSTALL_EP4(x)  (UEP4CSR_STALL=x)
#define USB_RDSTALL_EP4    UEP4CSR_STALL

// EP2 API functions call back
extern void USB_RxReadyCB4(uchar cnt);
extern void USB_RxReadyCBdisable4(void);
extern void USB_RxReadyCBenable4(void);

extern void USB_TxEmptyCB4(uchar cnt);
extern void USB_TxEmptyCBdisable4(void);
extern void USB_TxEmptyCBenable4(void);

// General Functions
void USB_Enable(void);
void USB_Disable(void);
void USB_Init(void);
void USB_Deinit(void);
uchar USB_GetStatus(void);

// EP0 API functions
#define USB_WRSTALL_EP0(x)  (USIMR_EP0_STALL=x)
#define USB_RDSTALL_EP0    USIMR_EP0_STALL

void USB_RxBuff0(uchar* adr, uchar cnt);
uchar USB_TxBuff0(/*const*/ uchar* adr, uchar cnt);

// CallBack Functions
extern void USB_ConfigChngCB(void);
extern void USB_ResumeCB(void);
extern void USB_SuspendCB(void);
extern void USB_ResetCB(void);
extern void USB_SofCB(void);

// Bit Definition for USB_Status;
#define CTRL_READ_STATE     0x10               // Control transfer Data state IN
#define CTRL_WRITE_STATE    0x20               // Control transfer Data state OUT

extern uchar ep0BufSh[8];

#endif
