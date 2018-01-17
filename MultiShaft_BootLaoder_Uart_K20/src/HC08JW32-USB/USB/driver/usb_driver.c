/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      usb_driver.c
*
* @author    B01119
*
* @version   1.0.4.0
*
* @date      Oct-11-2011
*
* @brief    USB Module Driver for HC08 MCUs
*
*******************************************************************************
*
* 
*
******************************************************************************/

#include <hidef.h>       /* for EnableInterrupts macro */
#include <MC68HC908JW32.h>   /* include peripheral declarations */
#include "usb.h"      /* USB Header file */
#include "usb_periph_cfg.h"
#include "usb_driver.h"

//-------------------------------------------------------------------
// Local Variables
//-------------------------------------------------------------------
#pragma DATA_SEG SHORT _DATA_ZEROPAGE

static volatile uchar* pSrc0;
static volatile uchar* pDst0;
static volatile uchar cntSrc0;
static volatile uchar cntDst0;

static volatile uchar* pSrc1;
static volatile uchar* pDst1;
static volatile uchar cntSrc1;
static volatile uchar cntDst1;

static volatile uchar* pSrc2;
static volatile uchar* pDst2;
static volatile uchar cntSrc2;
static volatile uchar cntDst2;

static volatile uchar* pSrc3;
static volatile uchar* pDst3;
static volatile uchar cntSrc3;
static volatile uchar cntDst3;

static volatile uchar* pSrc4;
static volatile uchar* pDst4;
static volatile uchar cntSrc4;
static volatile uchar cntDst4;

volatile uchar  usbStatus;
#pragma    DATA_SEG  DEFAULT
uchar ep0BufSh[8];

//-------------------------------------------------------------------
// USB line initialization (needs to be done asap after chip reset)
//
// Description:
// - Enable D+ pullup resistor and 3.3V regulator & USB RESET
//-------------------------------------------------------------------
void USB_Init(void)
{

  // Set/reset the 3V3 voltage regulator and USB reset
#ifndef USB_3V3REGULATOR_DIS
#define USB_3V3REGULATOR_DIS 0
#endif

#ifndef USB_CHIP_RESET_DIS
#define USB_CHIP_RESET_DIS 0
#endif

#ifndef USB_PULLUP_ENA
#define USB_PULLUP_ENA 0x00
#endif

  CONFIG2 |= (USB_3V3REGULATOR_DIS | USB_CHIP_RESET_DIS);

// Enable D+ pullup
#if USB_PULLUP_ENA==0x01
  POCR2 |= POCR2_DPPULLEN_MASK;
#endif
}

//-------------------------------------------------------------------
// USB module Enable (shall be done right before interrupt enable)
//
// Description:
// - wait for D+ line to go high (out of USB reset state), if USB chip reset enabled
// - Enable 4 Data Endpoint
// - 16 byte endpoint data buffer
//-------------------------------------------------------------------
void USB_Enable(void)
{
  // If the USB reset is set as MCU reset we should avoid the
  // multiple chip resetting while long RESET signalling
  #if USB_CHIP_RESET_DIS == 0
  // Wait for RESET signal on USB D+ line (logic 0)
 
    while (!PTE_PTE2) 
    {
      USB_DO_NOTHING();
    __RESET_WATCHDOG();
    }
  #endif

  // Assign the End Points to the interfaces
  UINTFCR = UINTFCR_INI;

  // Endpoints settings
  // Clear EP0 Status Register
  UEP0CSR = 0;

  // Set EP1 - EP4 base addresses
  UEP12BPR = UEP12BPR_INI;
  UEP34BPR = UEP34BPR_INI;

  // initialise all used EP
  #if EP1_MODE
   UEP1CSR = UEP1CSR_INI;
    #if EP1_DIR & EP_DIR_IN
      cntDst1 = EP1_BUFFER_SIZE;
      cntSrc1 = 0;
      pDst1 = EP1_BASE_ADR;
    #else
      cntDst1 = 0;
      cntSrc1 = 0;
    #endif
  #endif

  #if EP2_MODE
    UEP2CSR = UEP2CSR_INI;
    #if EP2_DIR & EP_DIR_IN
      cntDst2 = EP2_BUFFER_SIZE;
      cntSrc2 = 0;
      pDst2 = EP2_BASE_ADR;
    #else
      cntDst2 = 0;
      cntSrc2 = 0;
    #endif
  #endif

  #if EP3_MODE
    UEP3CSR = UEP3CSR_INI;
    #if EP3_DIR & EP_DIR_IN
      cntDst3 = EP3_BUFFER_SIZE;
      cntSrc3 = 0;
      pDst3 = EP3_BASE_ADR;
    #else
      cntDst3 = 0;
      cntSrc3 = 0;
    #endif
  #endif

  #if EP4_MODE
    UEP4CSR = UEP4CSR_INI;
    #if EP4_DIR & EP_DIR_IN
      cntDst4 = EP4_BUFFER_SIZE;
      cntSrc4 = 0;
      pDst4 = EP4_BASE_ADR;
    #else
      cntDst4 = 0;
      cntSrc4 = 0;
    #endif
  #endif

  USBSR = 0;        // Clear Status Register

  #ifndef USB_SETUPIE_ENA
    #define USB_SETUPIE_ENA      0
  #endif
  #ifndef USB_SOFIE_ENA
    #define USB_SOFIE_ENA        0
  #endif
  #ifndef USB_CONFIGCHGIE_ENA
    #define USB_CONFIGCHGIE_ENA  0
  #endif
  #ifndef USB_USBRSTIE_ENA
    #define USB_USBRSTIE_ENA     0
  #endif
  #ifndef USB_RESUMEFIE_ENA
    #define USB_RESUMEFIE_ENA    0
  #endif
  #ifndef USB_SUSPNDIE_ENA
    #define USB_SUSPNDIE_ENA     0
  #endif

  USIMR = (USB_SUSPNDIE_ENA?USIMR_SUSPNDIE_MASK:0)|\
          (USB_RESUMEFIE_ENA?USIMR_RESUMEFIE_MASK:0)|\
          (USB_USBRSTIE_ENA?USIMR_USBRSTIE_MASK:0)|\
          (USB_CONFIGCHGIE_ENA?USIMR_CONFIG_CHGIE_MASK:0)|\
          (USB_SOFIE_ENA?USIMR_SOFIE_MASK:0)|\
          (USB_SETUPIE_ENA?USIMR_SETUPIE_MASK:0);

  USBCR = USBCR_USBCLKEN_MASK|USBCR_USBEN_MASK|USBCR_TFC0IE_MASK|\
          (EP1_MODE?USBCR_TFC1IE_MASK:0)|\
          (EP2_MODE?USBCR_TFC2IE_MASK:0)|\
          (EP3_MODE?USBCR_TFC3IE_MASK:0)|\
          (EP4_MODE?USBCR_TFC4IE_MASK:0);
}

//---------------------------------------------------------------------------------------
// USB line deinitialization
//---------------------------------------------------------------------------------------
void USB_Deinit(void)
{
  // Disable D+ pullup
  POCR2 &= ~POCR2_DPPULLEN_MASK;
}

//---------------------------------------------------------------------------------------
// USB module Disable
//---------------------------------------------------------------------------------------
void USB_Disable(void)
{
  // Disable USB Module
  USBCR = 0;
}

//---------------------------------------------------------------------------------------
// uchar USB_TxBuff0(uchar* adr, uchar cnt)
//---------------------------------------------------------------------------------------
uchar USB_TxBuff0(uchar* adr, uchar cnt)
{
  pDst0 = EP0_BASE_ADR;
  cntDst0 = EP0_BUFFER_SIZE;

  pSrc0 = adr;
  cntSrc0 = cnt;

  while(cntDst0 && cntSrc0)
  {
    cntDst0--;
    cntSrc0--;
    *pDst0++ = *pSrc0++;
  }

  if(cntDst0 == 0)
    usbStatus |= CTRL_READ_STATE;

  // Set DVALID_IN flag and data length, others bits leave unchanged
  UEP0CSR = (EP0_BUFFER_SIZE - cntDst0)<<4 | (UEP0CSR_DVALID_IN_MASK | UEP0CSR_TFRC_IN_MASK | UEP0CSR_TFRC_OUT_MASK | UEP0CSR_DVALID_OUT_MASK);
  return(cntSrc0);
}

//---------------------------------------------------------------------------------------
// void USB_RxBuff0(uchar* adr, uchar cnt)
//---------------------------------------------------------------------------------------
void USB_RxBuff0(uchar* adr, uchar cnt)
{
  pDst0 = adr;
  cntDst0 = cnt;
  usbStatus |= CTRL_WRITE_STATE;
}

//---------------------------------------------------------------------------------------
// uchar USB_RxBuff1(uchar* adr, uchar cnt) - used for OUT bulk/interrupt packet
// NON BLOCKING function. Set user buffer address and number of bytes to be
// received. If there are any available data these will be copied intermidiately.
// The rest of the user buffer is filled during interrupt service routine.
// Function returns number of pending bytes in user buffer.
//---------------------------------------------------------------------------------------
uchar USB_RxBuff1(uchar* adr, uchar cnt)
{
  // Set address where to copy received data
  pDst1 = adr;
  // How many bytes to be copied
  cntDst1 = cnt;

  // If there are any data available, copy them intermidiately
  while(cntSrc1 && cntDst1)
  {
    cntSrc1--;
    cntDst1--;
    *pDst1++ = *pSrc1++;
  }

  // If all the received bytes are copied to the user buffer, enable to receive next OUT packet
  if(cntSrc1 == 0)
     UEP1CSR &= ~UEP1CSR_DVALID_MASK;

  // Return number of pending data in user buffer
  return(cntDst1);
}

//---------------------------------------------------------------------------------------
// uchar USB_RxChar1(void)
// BLOCKING function - wait till RxBuffPending and there are any received data in EP buffer
// then read one byte from EP buffer and return it.
//---------------------------------------------------------------------------------------
uchar USB_RxChar1(void)
{
  uchar retVal;
  // Wait until user buffer pending
  while(cntDst1)
    USB_DO_NOTHING();

  // Wait while data in EP buffer available
  while(!(cntSrc1))
    USB_DO_NOTHING();

  retVal = *pSrc1++;

  // If no more data in EP buffer, enable another packet receive
  if(!(--cntSrc1))
     UEP1CSR &= ~UEP1CSR_DVALID_MASK;

  // Return received data
  return(retVal);
}

//---------------------------------------------------------------------------------------
// uchar USB_RxBuffPending1(void)
// returns number of bytes pending to be received to user buffer
//---------------------------------------------------------------------------------------
uchar USB_RxBuffPending1(void)
{
  return(cntDst1);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetRxReady1(void)
// return number of available data bytes in EP buffer
//---------------------------------------------------------------------------------------
uchar USB_GetRxReady1(void)
{
  return(cntSrc1);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetTxEmpty1(void)
// returns number of available bytes in EP buffer (to be write)
//---------------------------------------------------------------------------------------
uchar USB_GetTxEmpty1(void)
{
  if(UEP1CSR_DVALID)   // if transmit is pending
    return(0);         // return zero
  else
    return(cntDst1);   // else return free space in transmit buffer
}

//---------------------------------------------------------------------------------------
// uchar USB_TxChar1(uchar ch)  - used for IN bulk/interrupt packet
// BLOCKING function - waits till user Tx buffer is pending and
// EP buffer has free place. Then write character to EP buffer. When EP buffer
// is full, flushes this packet.
// Function returns number of available bytes in EP buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxChar1(uchar ch)
{
  uchar retVal;
  // wait pending buffer
  while(cntSrc1)
    USB_DO_NOTHING();

  // wait while EP buffer not sent
  while(UEP1CSR_DVALID)
    USB_DO_NOTHING();

  // write character to buffer
  *pDst1++ = ch;

  cntDst1--;
  retVal = cntDst1;
  // if EP buffer is full, flush it
  if(retVal == 0)
  {
    UEP1DSR = EP1_BUFFER_SIZE;
    UEP1CSR |= UEP1CSR_DVALID_MASK;
  }
  return(retVal);
}
#pragma MESSAGE DEFAULT C1853
//---------------------------------------------------------------------------------------
// uchar USB_TxBuff1(uchar* adr, uchar cnt) user for IN interrupt/bulk packet
// NON BLOCKING function - function copy data from user buffer to EP
// buffer. If user buffer is larger then EP buffer the rest of data is send in interrupt
// service routine. Function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxBuff1(uchar* adr, uchar cnt)
{
   uchar retVal;
   // set address of buffer where the data to be send are placed
   pSrc1 = adr;
   // set number of bytes to send
   cntSrc1 = cnt;

   // copy data from user buffer to EP buffer
   while(cntSrc1 && cntDst1)
   {
    cntSrc1--;
    cntDst1--;
    *pDst1++ = *pSrc1++;
   }

   retVal = cntSrc1;
   // flush it
   UEP1DSR = EP1_BUFFER_SIZE - cntDst1;
   UEP1CSR |= UEP1CSR_DVALID_MASK;

   // return number of bytes pending in user buffer
   return(retVal);
}
#pragma MESSAGE DEFAULT C1853
//---------------------------------------------------------------------------------------
// uchar USB_TxBuffPending1(void)
// function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
uchar USB_TxBuffPending1(void)
{
  return(cntSrc1);
}
//---------------------------------------------------------------------------------------
// uchar USB_TxFlush1(void)
// if there is at least one byte to be send in EP buffer, flush buffer
// Function returns number of send bytes
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxFlush1(void)
{
  UEP1DSR = EP1_BUFFER_SIZE - cntDst1;
  UEP1CSR |= UEP1CSR_DVALID_MASK;
  return(UEP1DSR);
}
#pragma MESSAGE DEFAULT C1853
//---------------------------------------------------------------------------------------
// uchar USB_RxBuff2(uchar* adr, uchar cnt) - used for OUT bulk/interrupt packet
// NON BLOCKING function. Set user buffer address and number of bytes to be
// received. If there are any available data these will be copied intermidiately.
// The rest of the user buffer is filled during interrupt service routine.
// Function returns number of pending bytes in user buffer.
//---------------------------------------------------------------------------------------
uchar USB_RxBuff2(uchar* adr, uchar cnt)
{
  // set address where to copy received data
  pDst2 = adr;
  // how many bytes to be copied
  cntDst2 = cnt;

  // if there are any data available, copy them intermidiately
  while(cntSrc2 && cntDst2)
  {
    cntSrc2--;
    cntDst2--;
    *pDst2++ = *pSrc2++;
  }

  // if all received bytes are copied to user buffe, enable to receive next OUT packet
  if(cntSrc2 == 0)
     UEP2CSR &= ~UEP2CSR_DVALID_MASK;

  // return number of pending data in user buffer
  return(cntDst2);
}

//---------------------------------------------------------------------------------------
// uchar USB_RxChar2(void)
// BLOCKING function - wait till RxBuffPending and there are any received data in EP buffer
// then read one byte from EP buffer and return it.
//---------------------------------------------------------------------------------------
uchar USB_RxChar2(void)
{
  uchar retVal;
  // wait until buffer pending
  while(cntDst2)
    USB_DO_NOTHING();

  // wait while data in EP buffer aviable
  while(!(cntSrc2))
    USB_DO_NOTHING();

  retVal = *pSrc2++;
  // if no more data in EP buffer, enalble another packet receive
  if(!(--cntSrc2))
     UEP2CSR &= ~UEP2CSR_DVALID_MASK;

  // return data
  return(retVal);
}
//---------------------------------------------------------------------------------------
// uchar USB_RxBuffPending2(void)
// returns number of bytes pending to be received to user buffer
//---------------------------------------------------------------------------------------
uchar USB_RxBuffPending2(void)
{
  return(cntDst2);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetRxReady2(void)
// return number of available data bytes in EP buffer
//---------------------------------------------------------------------------------------
uchar USB_GetRxReady2(void)
{
  return(cntSrc2);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetTxEmpty2(void)
// returns number of available bytes in EP buffer (to be write)
//---------------------------------------------------------------------------------------
uchar USB_GetTxEmpty2(void)
{
  if(UEP2CSR_DVALID)   // if transmit is pending
   return(0);         // return zero
  else
   return(cntDst2);   // else return free space in transmit buffer
}

//---------------------------------------------------------------------------------------
// uchar USB_TxChar2(uchar ch)  - used for IN bulk/interrupt packet
// BLOCKING function - waits till user Tx buffer is pending and
// EP buffer has free place. Then write character to EP buffer. When EP buffer
// is full, flushes this packet.
// Function returns number of available bytes in EP buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxChar2(uchar ch)
{
  uchar retVal;
  // wait pending buffer
  while(cntSrc2)
    USB_DO_NOTHING();

  // wait while EP3 buffer not sent
  while(UEP2CSR_DVALID)
    USB_DO_NOTHING();

  // write character to buffer
  *pDst2++ = ch;

  cntDst2--;
  retVal = cntDst2;
  // if EP buffer is full, flush it
  if(retVal == 0)
  {
    UEP2DSR = EP2_BUFFER_SIZE;
    UEP2CSR |= UEP2CSR_DVALID_MASK;
  }
  return(retVal);
}
#pragma MESSAGE DEFAULT C1853
//---------------------------------------------------------------------------------------
// uchar USB_TxBuff1(uchar* adr, uchar cnt) user for IN interrupt/bulk packet
// NON BLOCKING function - function copy data from user buffer to EP
// buffer. If user buffer is larger then EP buffer the rest of data is send in interrupt
// service routine. Function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxBuff2(uchar* adr, uchar cnt)
{
   uchar retVal;

   // set address of buffer where the data to be send are placed
   pSrc2 = adr;
   // set number of bytes to send
   cntSrc2 = cnt;

   // copy data from user buffer to EP buffer
   while(cntSrc2 && cntDst2)
   {
    cntSrc2--;
    cntDst2--;
    *pDst2++ = *pSrc2++;
   }
   retVal = cntSrc2;

   // flush it
   UEP2DSR = EP2_BUFFER_SIZE - cntDst2;
   UEP2CSR |= UEP2CSR_DVALID_MASK;

   // return number of bytes pending in user buffer
   return(retVal);
}
#pragma MESSAGE DEFAULT C1853
//---------------------------------------------------------------------------------------
// uchar USB_TxBuffPending2(void)
// function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
uchar USB_TxBuffPending2(void)
{
  return(cntSrc2);
}

//---------------------------------------------------------------------------------------
// uchar USB_TxFlush2(void)
// if there is at least one byte to be send in EP buffer, flush buffer
// Function returns number of send bytes
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxFlush2(void)
{
  UEP2DSR = EP2_BUFFER_SIZE - cntDst2;
  UEP2CSR |= UEP2CSR_DVALID_MASK;
  return(UEP2DSR);
}
#pragma MESSAGE DEFAULT C1853

//---------------------------------------------------------------------------------------
// uchar USB_RxBuff3(uchar* adr, uchar cnt) - used for OUT bulk/interrupt packet
// NON BLOCKING function. Set user buffer address and number of bytes to be
// received. If there are any available data these will be copied intermidiately.
// The rest of the user buffer is filled during interrupt service routine.
// Function returns number of pending bytes in user buffer.
//---------------------------------------------------------------------------------------
uchar USB_RxBuff3(uchar* adr, uchar cnt)
{
  // set address where to copy received data
  pDst3 = adr;
  // how many bytes to be copied
  cntDst3 = cnt;

  // if there are any data available, copy them intermediately
  while(cntSrc3 && cntDst3)
  {
    cntSrc3--;
    cntDst3--;
    *pDst3++ = *pSrc3++;
  }

  // if all received bytes are copied to user buffe, enable to receive next OUT packet
  if(cntSrc3 == 0)
     UEP3CSR &= ~UEP3CSR_DVALID_MASK;

  // return number of pending data in user buffer
  return(cntDst3);
}

//---------------------------------------------------------------------------------------
// uchar USB_RxChar3(void)
// BLOCKING function - wait till RxBuffPending and there are any received data in EP buffer
// then read one byte from EP buffer and return it.
//---------------------------------------------------------------------------------------
uchar USB_RxChar3(void)
{
  uchar retVal;
  // wait until buffer pending
  while(cntDst3)
    USB_DO_NOTHING();

  // wait while data in EP buffer aviable
  while(!(cntSrc3))
    USB_DO_NOTHING();

  retVal = *pSrc3++;
  // if no more data in EP buffer, enalble another packet receive
  if(!(--cntSrc3))
     UEP3CSR &= ~UEP3CSR_DVALID_MASK;

  // return data
  return(retVal);
}

//---------------------------------------------------------------------------------------
// uchar USB_RxBuffPending3(void)
// returns number of bytes pending to be received to user buffer
//---------------------------------------------------------------------------------------
uchar USB_RxBuffPending3(void)
{
  return(cntDst3);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetRxReady3(void)
// return number of available data bytes in EP buffer
//---------------------------------------------------------------------------------------
uchar USB_GetRxReady3(void)
{
  return(cntSrc3);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetTxEmpty3(void)
// returns number of available bytes in EP buffer (to be write)
//---------------------------------------------------------------------------------------
uchar USB_GetTxEmpty3(void)
{
  if(UEP3CSR_DVALID)   // if transmit is pending
    return(0);         // return zero
  else
    return(cntDst3);   // else return free space in transmit buffer
}


#ifndef WIN_USBSER_SYS_HACK

#if ((EP3_DIR == EP_DIR_IN) && (EP3_MODE == EP_MODE_BULK))
#warning "Aren't you trying to compile code for Windows usbser.sys driver?"
#warning "XP2 version of this driver doesn't work correctly with an IN packet"
#warning "that is as long as IN packet size (ie. full packet)."
#warning "Disabling to default value = full packet may be sent"
#warning "To use usbser.sys (XP2 version) correctly,"
#warning "add #define WIN_USBSER_SYS_HACK 1 into usb_periph.cfg.h!"
#endif

#define WIN_USBSER_SYS_HACK 0

#endif

//---------------------------------------------------------------------------------------
// uchar USB_TxChar3(uchar ch)  - used for IN bulk/interrupt packet
// BLOCKING function - waits till user Tx buffer is pending and
// EP buffer has free place. Then write character to EP buffer. When EP buffer
// is full, flushes this packet.
// Function returns number of available bytes in EP buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxChar3(uchar ch)
{
  uchar retVal;
  // wait pending buffer
  while(cntSrc3)
    USB_DO_NOTHING();

  // wait while EP3 buffer not sent
  while(UEP3CSR_DVALID)
    USB_DO_NOTHING();

  // write character to buffer
  *pDst3++ = ch;

  cntDst3--;
  retVal = cntDst3;

  // if EP buffer is full, flush it
  if(retVal <= WIN_USBSER_SYS_HACK)          // WARNING! only usbser.sys (XP version)
  {                          // doesn't handle full-length buffer sent
    UEP3DSR = EP3_BUFFER_SIZE - retVal;           // without zero flush afterwards
    UEP3CSR |= UEP3CSR_DVALID_MASK;
  }
  return(retVal);
}
#pragma MESSAGE DEFAULT C1853

//---------------------------------------------------------------------------------------
// uchar USB_TxBuff1(uchar* adr, uchar cnt) user for IN interrupt/bulk packet
// NON BLOCKING function - function copy data from user buffer to EP
// buffer. If user buffer is larger then EP buffer the rest of data is send in interrupt
// service routine. Function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxBuff3(uchar* adr, uchar cnt)
{
   uchar retVal;

   // set address of buffer where the data to be send are placed
   pSrc3 = adr;
   // set number of bytes to send
   cntSrc3 = cnt;

   // copy data from user buffer to EP buffer
   while(cntSrc3 && (cntDst3 > WIN_USBSER_SYS_HACK))   /* WinXP usbser.sys hack, need to send 1B less, see TxChar */
   {
    cntSrc3--;
    cntDst3--;
    *pDst3++ = *pSrc3++;
   }

   retVal = cntSrc3;
   // flush it
     UEP3DSR = EP3_BUFFER_SIZE - cntDst3;
     UEP3CSR |= UEP3CSR_DVALID_MASK;
   // return number of bytes pending in user buffer
   return(retVal);
}
#pragma MESSAGE DEFAULT C1853

//---------------------------------------------------------------------------------------
// uchar USB_TxBuffPending3(void)
// function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
uchar USB_TxBuffPending3(void)
{
  return(cntSrc3);
}

//---------------------------------------------------------------------------------------
// uchar USB_TxFlush3(void)
// if there is at least one byte to be send in EP buffer, flush buffer
// Function returns number of send bytes
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxFlush3(void)
{
  UEP3DSR = EP3_BUFFER_SIZE - cntDst3;
  UEP3CSR |= UEP3CSR_DVALID_MASK;
  return(UEP3DSR);
}
#pragma MESSAGE DEFAULT C1853

//---------------------------------------------------------------------------------------
// uchar USB_RxBuff4(uchar* adr, uchar cnt) - used for OUT bulk/interrupt packet
// NON BLOCKING function. Set user buffer address and number of bytes to be
// received. If there are any available data these will be copied intermidiately.
// The rest of the user buffer is filled during interrupt service routine.
// Function returns number of pending bytes in user buffer.
//---------------------------------------------------------------------------------------
uchar USB_RxBuff4(uchar* adr, uchar cnt)
{
  // set address where to copy received data
  pDst4 = adr;
  // how many bytes to be copied
  cntDst4 = cnt;

  // if there are any data available, copy them intermidiately
  while(cntSrc4 && cntDst4)
  {
    cntSrc4--;
    cntDst4--;
    *pDst4++ = *pSrc4++;
  }

  // if all received bytes are copied to user buffe, enable to receive next OUT packet
  if(cntSrc4 == 0)
     UEP4CSR &= ~UEP4CSR_DVALID_MASK;

  // return number of pending data in user buffer
  return(cntDst4);
}

//---------------------------------------------------------------------------------------
// uchar USB_RxChar4(void)
// BLOCKING function - wait till RxBuffPending and there are any received data in EP buffer
// then read one byte from EP buffer and return it.
//---------------------------------------------------------------------------------------
uchar USB_RxChar4(void)
{
  uchar retVal;
  // wait until buffer pending
  while(cntDst4)
    USB_DO_NOTHING();

  // wait while data in EP buffer aviable
  while(!(cntSrc4))
    USB_DO_NOTHING();

  retVal = *pSrc4++;
  // if no more data in EP buffer, enalble another packet receive
  if(!(--cntSrc4))
     UEP4CSR &= ~UEP4CSR_DVALID_MASK;

  // return data
  return(retVal);
}

//---------------------------------------------------------------------------------------
// uchar USB_RxBuffPending4(void)
// returns number of bytes pending to be received to user buffer
//---------------------------------------------------------------------------------------
uchar USB_RxBuffPending4(void)
{
  return(cntDst4);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetRxReady4(void)
// return number of available data bytes in EP buffer
//---------------------------------------------------------------------------------------
uchar USB_GetRxReady4(void)
{
  return(cntSrc4);
}

//---------------------------------------------------------------------------------------
// uchar USB_GetTxEmpty4(void)
// returns number of available bytes in EP buffer (to be write)
//---------------------------------------------------------------------------------------
uchar USB_GetTxEmpty4(void)
{
  if(UEP4CSR_DVALID)   // if transmit is pending
    return(0);         // return zero
  else
    return(cntDst4);   // else return free space in transmit buffer
}

//---------------------------------------------------------------------------------------
// uchar USB_TxChar4(uchar ch)  - used for IN bulk/interrupt packet
// BLOCKING function - waits till user Tx buffer is pending and
// EP buffer has free place. Then write character to EP buffer. When EP buffer
// is full, flushes this packet.
// Function returns number of available bytes in EP buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxChar4(uchar ch)
{
  uchar retVal;
  // wait pending buffer
  while(cntSrc4)
    USB_DO_NOTHING();

  // wait while EP buffer not sent
  while(UEP4CSR_DVALID)
    USB_DO_NOTHING();

  // write character to buffer
  *pDst4++ = ch;

  cntDst4--;
  retVal = cntDst4;
  // if EP buffer is full, flush it
  if(retVal == 0)
  {
    UEP4DSR = EP4_BUFFER_SIZE;
    UEP4CSR |= UEP4CSR_DVALID_MASK;
  }
  return(cntDst4);
}
#pragma MESSAGE DEFAULT C1853
//---------------------------------------------------------------------------------------
// uchar USB_TxBuff1(uchar* adr, uchar cnt) user for IN interrupt/bulk packet
// NON BLOCKING function - function copy data from user buffer to EP
// buffer. If user buffer is larger then EP buffer the rest of data is send in interrupt
// service routine. Function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxBuff4(uchar* adr, uchar cnt)
{
   uchar retVal;
   // set address of buffer where the data to be send are placed
   pSrc4 = adr;
   // set number of bytes to send
   cntSrc4 = cnt;

   // copy data from user buffer to EP buffer
   while(cntSrc4 && cntDst4)
   {
    cntSrc4--;
    cntDst4--;
    *pDst4++ = *pSrc4++;
   }

   retVal = cntSrc4;
   // flush it
   UEP4DSR = EP4_BUFFER_SIZE - cntDst4;
   UEP4CSR |= UEP4CSR_DVALID_MASK;

   // return number of bytes pending in user buffer
   return(retVal);
}
#pragma MESSAGE DEFAULT C1853
//---------------------------------------------------------------------------------------
// uchar USB_TxBuffPending4(void)
// function returns number of bytes pending in user buffer
//---------------------------------------------------------------------------------------
uchar USB_TxBuffPending4(void)
{
  return(cntSrc4);
}

//---------------------------------------------------------------------------------------
// uchar USB_TxFlush4(void)
// if there is at least one byte to be send in EP buffer, flush buffer
// Function returns number of send bytes
//---------------------------------------------------------------------------------------
#pragma MESSAGE DISABLE C1853
uchar USB_TxFlush4(void)
{
  UEP4DSR = EP4_BUFFER_SIZE - cntDst4;
  UEP4CSR |= UEP4CSR_DVALID_MASK;
  return(UEP4DSR);
}
#pragma MESSAGE DEFAULT C1853

//---------------------------------------------------------------------------------------
// USB_GetStatus
//---------------------------------------------------------------------------------------
uchar USB_GetStatus(void)
{
  return(usbStatus);
}

//---------------------------------------------------------------------------------------
// Decode USB commands
// Called when SETUP request received
//---------------------------------------------------------------------------------------
void USB_StandardRequest(void)
{
  word temp;
  uchar idxTmp;

  extern byte* ptrToConfigDsc;
  extern byte* ptrToDeviceDsc;
  extern byte* STRING_DSC_TAB[STRING_DSC_TAB_LEN];

  // Clear pending Data Control State
  // Standart reguest GET DESCRIPTOR
  if (((SetupPcktStrc *)ep0BufSh)->bRequest == RQST_GET_DESCRIPTOR)
  {
    switch ((byte)((SetupPcktStrc *)ep0BufSh)->wValue)
    {
       // Get CONFIGURATION Descriptor request
      case (DSC_CONFIGURATION_TYPE):
        // number of requested data
        temp = CHNG_ENDIAN(((SetupPcktStrc *)ep0BufSh)->wLength);
        if (temp > 0xFF) temp = 0xFF;


        if ((byte)temp > *(ptrToConfigDsc + 2))
          temp = *(ptrToConfigDsc + 2);

        (void) USB_TxBuff0(ptrToConfigDsc, (byte)temp);
        break;

      // Get DEVICE Descriptor
      case (DSC_DEVICE_TYPE):

        temp = CHNG_ENDIAN(((SetupPcktStrc *)ep0BufSh)->wLength);
        if (temp > 0xFF) temp = 0xFF;

        if (temp > *ptrToDeviceDsc)
          temp = *ptrToDeviceDsc;

        // Upload Data to EP buffer
        (void) USB_TxBuff0(ptrToDeviceDsc, (byte)temp);
        break;

      // Get STRING Descriptor
      case (DSC_STRING_TYPE):

        // load STRING descriptor index number
        idxTmp = H_BYTE(((SetupPcktStrc *)ep0BufSh)->wValue);

        if (idxTmp <= STRING_DSC_TAB_LEN)
        {  // load requested number of bytes
          temp = CHNG_ENDIAN(((SetupPcktStrc *)ep0BufSh)->wLength);
          if (temp > 0xFF) temp = 0xFF;

          // if string descriptor length is shorter than requested num of bytes, trim it
          if (temp > * STRING_DSC_TAB[idxTmp])
            temp = * STRING_DSC_TAB[idxTmp];

          (void) USB_TxBuff0(STRING_DSC_TAB[idxTmp], (byte)temp);
        }

        // Illegal String descriptor Index
        else
          USB_WRSTALL_EP0(1);
      break;

      // Illegal descriptor type
      default:
      {
          #ifdef  USB_GET_DESCRIPTOR_CB
          extern void USB_GET_DESCRIPTOR_CB(void);
          USB_GET_DESCRIPTOR_CB();
          #else
          USB_WRSTALL_EP0(1);
          #endif
      }
      break;
    } // end switch
  }
  else   USB_WRSTALL_EP0(1);
}

//-------------------------------------------------------------------
// USB Interrupt Service Routines
//-------------------------------------------------------------------


interrupt void USB_EP_ISR(void)
{
/* ENDPOINT 0 - dedicated to control transfer */
  if(UEP0CSR & UEP0CSR_TFRC_IN_MASK)    // EP0 IN packet odeslan, naplnim zbytek?
  {
    UEP0CSR &= ~UEP0CSR_TFRC_IN_MASK;

    if(usbStatus & CTRL_READ_STATE)
    {
      pDst0 = EP0_BASE_ADR;
      cntDst0 = EP0_BUFFER_SIZE;

      while(cntDst0 && cntSrc0)
      {
        *pDst0++ = *pSrc0++;
        cntDst0--;
        cntSrc0--;
      }

      if(cntDst0 > 0)
        usbStatus &= ~CTRL_READ_STATE;

      // set DVALID_IN flag and data length, others bits leave unchanged
      UEP0CSR = (EP0_BUFFER_SIZE - cntDst0)<<4 | (UEP0CSR_DVALID_IN_MASK | UEP0CSR_TFRC_IN_MASK | UEP0CSR_TFRC_OUT_MASK | UEP0CSR_DVALID_OUT_MASK);
    }
  }

  if(UEP0CSR & UEP0CSR_TFRC_OUT_MASK)   //EP0 OUT packet prijat
  {
    if(usbStatus & CTRL_WRITE_STATE)
    {
      pSrc0 = EP0_BASE_ADR;
      cntSrc0 = EP0_BUFFER_SIZE;

      while(cntDst0 && cntSrc0)
      {
        *pDst0++ = *pSrc0++;
        cntDst0--;
        cntSrc0--;
      }

      if(cntSrc0 > 0)
       {
         // end of data state in OUT packet -> we must send IN packet with zero data length
        UEP0CSR = (UEP0CSR_DVALID_IN_MASK | UEP0CSR_TFRC_IN_MASK | UEP0CSR_TFRC_OUT_MASK | UEP0CSR_DVALID_OUT_MASK);
        usbStatus &= ~CTRL_WRITE_STATE;
       }
       #ifndef USB_CALLBACK_EP0
        #define USB_CALLBACK_EP0 0
      #endif
      
       #if USB_CALLBACK_EP0 == 1
         USB_RxReadyCB0();
       #endif
    }

    UEP0CSR &= ~(UEP0CSR_TFRC_OUT_MASK | UEP0CSR_DVALID_OUT_MASK); // Clear TFRC0 and DVALID_OUT flag
  }

  // ENDPOINT 1
  // endpoint is enabled
  #ifndef USB_CALLBACK_EP1
    #define USB_CALLBACK_EP1 0
  #endif
  #if EP1_MODE
    if(UEP1CSR & UEP1CSR_TFRC_MASK)
    {
      // EP in IN mode
      #if EP1_DIR & EP_DIR_IN
         pDst1 = EP1_BASE_ADR;
         cntDst1 = EP1_BUFFER_SIZE;

         #if USB_CALLBACK_EP1 == 0
           while(cntDst1 && cntSrc1)
           {
             cntDst1--;
             cntSrc1--;
             *pDst1++ = *pSrc1++;
           }

           if((uchar)(EP1_BUFFER_SIZE - cntDst1) > 0)
           {
              UEP1DSR = EP1_BUFFER_SIZE - cntDst1;
              UEP1CSR |= UEP1CSR_DVALID_MASK;
           }
        #else
          USB_TxEmptyCB1(EP1_BUFFER_SIZE);
        #endif

      // EP in OUT mode
      #else
        pSrc1 = EP1_BASE_ADR;
        cntSrc1 = UEP1DSR;

        #if USB_CALLBACK_EP1 == 0
          while(cntSrc1 && cntDst1)
          {
            cntSrc1--;
            cntDst1--;
            *pDst1++ = *pSrc1++;
          }
          if(cntSrc1 == 0)
            UEP1CSR &= ~UEP1CSR_DVALID_MASK;
        #else
          USB_RxReadyCB1(UEP1DSR);
        #endif
      #endif
      UEP1CSR &= ~UEP1CSR_TFRC_MASK;
    }
  #endif

  // ENDPOINT 2
  // endpoint is enabled
  #ifndef USB_CALLBACK_EP2
    #define USB_CALLBACK_EP2 0
  #endif
  #if EP2_MODE
    if(UEP2CSR & UEP2CSR_TFRC_MASK)
    {
      // EP in IN mode
      #if EP2_DIR & EP_DIR_IN
         pDst2 = EP2_BASE_ADR;
         cntDst2 = EP2_BUFFER_SIZE;

         #if USB_CALLBACK_EP2 == 0
           while(cntDst2 && cntSrc2)
           {
             cntDst2--;
             cntSrc2--;
             *pDst2++ = *pSrc2++;
           }

           if((uchar)(EP2_BUFFER_SIZE - cntDst2) > 0)
           {
              UEP2DSR = EP2_BUFFER_SIZE - cntDst2;
              UEP2CSR |= UEP2CSR_DVALID_MASK;
           }
         #else
           USB_TxEmptyCB2(EP2_BUFFER_SIZE);
         #endif

      // EP in OUT mode
      #else
        pSrc2 = EP2_BASE_ADR;
        cntSrc2 = UEP2DSR;

        #if USB_CALLBACK_EP2 == 0
          while(cntSrc2 && cntDst2)
          {
            cntSrc2--;
            cntDst2--;
            *pDst2++ = *pSrc2++;
          }
          if(cntSrc2 == 0)
            UEP2CSR &= ~UEP2CSR_DVALID_MASK;

        #else
          USB_RxReadyCB2(UEP2DSR);
        #endif

      #endif
      UEP2CSR &= ~UEP2CSR_TFRC_MASK;
    }
  #endif

  /* ENDPOINT 3 */
  // endpoint is enabled
#ifndef USB_CALLBACK_EP3
  #define   USB_CALLBACK_EP3 0
#endif
  #if EP3_MODE
    if(UEP3CSR & UEP3CSR_TFRC_MASK)
    {
      // EP in IN mode
      #if EP3_DIR & EP_DIR_IN
         pDst3 = EP3_BASE_ADR;
         cntDst3 = EP3_BUFFER_SIZE;

        #if USB_CALLBACK_EP3 == 0
           while(cntDst3 && cntSrc3)
           {
             cntDst3--;
             cntSrc3--;
             *pDst3++ = *pSrc3++;
           }

           if((uchar)(EP3_BUFFER_SIZE - cntDst3) > 0)
           {
              UEP3DSR = EP3_BUFFER_SIZE - cntDst3;
              UEP3CSR |= UEP3CSR_DVALID_MASK;
           }
         #else
           USB_TxEmptyCB3(EP3_BUFFER_SIZE);
         #endif

      // EP in OUT mode
      #else
        pSrc3 = EP3_BASE_ADR;
        cntSrc3 = UEP3DSR;

        #if USB_CALLBACK_EP3 == 0
          while(cntSrc3 && cntDst3)
          {
            cntSrc3--;
            cntDst3--;
            *pDst3++ = *pSrc3++;
          }
          if(cntSrc3 == 0)
            UEP3CSR &= ~UEP3CSR_DVALID_MASK;
        #else
          USB_RxReadyCB3(UEP3DSR);
        #endif
      #endif
      UEP3CSR &= ~UEP3CSR_TFRC_MASK;
    }
  #endif


  // ENDPOINT 4
  // endpoint is enabled
  #ifndef USB_CALLBACK_EP4
    #define USB_CALLBACK_EP4 0
  #endif
  #if EP4_MODE
    if(UEP4CSR & UEP4CSR_TFRC_MASK)
    {
      // EP in IN mode
      #if EP4_DIR & EP_DIR_IN
         pDst4 = EP4_BASE_ADR;
         cntDst4 = EP4_BUFFER_SIZE;

         #if  USB_CALLBACK_EP4 == 0
           while(cntDst4 && cntSrc4)
           {
             cntDst4--;
             cntSrc4--;
             *pDst4++ = *pSrc4++;
           }

           if((uchar)(EP4_BUFFER_SIZE - cntDst4) > 0)
           {
              UEP4DSR = EP4_BUFFER_SIZE - cntDst4;
              UEP4CSR |= UEP4CSR_DVALID_MASK;
           }
        #else
          USB_TxEmptyCB4(EP4_BUFFER_SIZE);
        #endif

      // EP in OUT mode
      #else
        pSrc4 = EP4_BASE_ADR;
        cntSrc4 = UEP4DSR;

        #if  USB_CALLBACK_EP4 == 0
          while(cntSrc4 && cntDst4)
          {
            cntSrc4--;
            cntDst4--;
            *pDst4++ = *pSrc4++;
          }
          if(cntSrc4 == 0)
            UEP4CSR &= ~UEP4CSR_DVALID_MASK;
        #else
          USB_RxReadyCB4(UEP4DSR);
        #endif

      #endif
      UEP4CSR &= ~UEP4CSR_TFRC_MASK;
    }
  #endif
}

//-------------------------------------------------------------------
// USB Interrupt Service Routines
//-------------------------------------------------------------------

interrupt void USB_SYS_ISR(void)
{

  // setup packet interrupt?
  #if USB_SETUPIE_ENA != 0
    if(USBSR & USBSR_SETUP_MASK)
    {
      // Copy ep0 data into shadow data buffer
      ep0BufSh[0] =  *(EP0_BASE_ADR + 0);
      ep0BufSh[1] =  *(EP0_BASE_ADR + 1);
      ep0BufSh[2] =  *(EP0_BASE_ADR + 2);
      ep0BufSh[3] =  *(EP0_BASE_ADR + 3);
      ep0BufSh[4] =  *(EP0_BASE_ADR + 4);
      ep0BufSh[5] =  *(EP0_BASE_ADR + 5);
      ep0BufSh[6] =  *(EP0_BASE_ADR + 6);
      ep0BufSh[7] =  *(EP0_BASE_ADR + 7);
      
        
      // GET_DESCRIPTOR, SYNC_FRAME, class/vendor specific request    
      UEP0CSR &= ~(UEP0CSR_TFRC_OUT_MASK | UEP0CSR_DVALID_OUT_MASK); // Clear TFRC_0UT bit
      USBSR &= ~USBSR_SETUP_MASK;                                     // Clear SETUP flag

      usbStatus &= ~(CTRL_READ_STATE | CTRL_WRITE_STATE);
      // standard requests
      if ((((SetupPcktStrc *)ep0BufSh)->bmRequestType & M_COMMAND_TYPE_MASK) == M_STANDARD_COMMAND)
      {
        USB_StandardRequest();
      }

      // class specific requests
      else if ((((SetupPcktStrc *)ep0BufSh)->bmRequestType & M_COMMAND_TYPE_MASK) == M_CLASS_COMMAND)
      {
        #ifdef USB_CLASS_REQUEST_CB
          extern void USB_CLASS_REQUEST_CB(void);
          USB_CLASS_REQUEST_CB();
        #else
          USB_WRSTALL_EP0(1);
        #endif
      }

      // vendor specific requests
      else if ((((SetupPcktStrc *)ep0BufSh)->bmRequestType & M_COMMAND_TYPE_MASK) == M_VENDOR_COMMAND)
      {
        #ifdef USB_VENDOR_REQUEST_CB
          extern void USB_VENDOR_REQUEST_CB(void);
          USB_VENDOR_REQUEST_CB();
        #else
        USB_WRSTALL_EP0(1);
        #endif
      }

      // all other illegal requests
      else
      {
        USB_WRSTALL_EP0(1);
      }
    }
  #endif

  // Start of frame interrupt
  #if USB_SOFIE_ENA != 0
    if(USBSR & USBSR_SOF_MASK)
    {
      USBSR &= ~USBSR_SOF_MASK;       // Clear SOF flag
      USB_SofCB();
    }
  #endif

  // Config change interrupt
  #if USB_CONFIGCHGIE_ENA != 0
    if(USBSR & USBSR_CONFIG_CHG_MASK)
    {
      USBSR &= ~USBSR_CONFIG_CHG_MASK;            // Clear CONFIGCHG flag
      USB_ConfigChngCB();
    }
  #endif

  // Reset flag  - divne!!! Jak to ma byt?
  #if USB_USBRSTIE_ENA != 0
    if (USBSR & USBSR_USBRST_MASK)
    {
      USBSR &= ~USBSR_USBRST_MASK;              // Clear USB Reset flag
      // clear all unlatched STALL
      USIMR_EP0_STALL = 0;
      #if EP1_MODE
        UEP1CSR_STALL = 0;
      #endif
       #if EP2_MODE
         UEP2CSR_STALL = 0;
      #endif
      #if EP3_MODE
        UEP3CSR_STALL = 0;      
      #endif
      #if EP4_MODE
       UEP4CSR_STALL = 0;
      #endif
      USB_ResetCB();    // Custom RESET Handling
    }
  #endif

  // Resume flag - budim procesor ze spanku
  #if USB_RESUMEFIE_ENA != 0
    if (USBSR & USBSR_RESUMEF_MASK)
    {
      USBSR &= ~USBSR_RESUMEF_MASK;    // Clear USB RESUME flag
      USB_ResumeCB();                 // User setting for USB resume
      USBCR |= USBCR_USBCLKEN_MASK;    // Enable USB clk
    }
  #endif

  // Suspend flag
  #if USB_SUSPNDIE_ENA != 0
    if (USBSR & USBSR_SUSPND_MASK)
    {
      USBSR &= ~USBSR_SUSPND_MASK;              // Clear USB Suspend
      USBCR &= ~USBCR_USBCLKEN_MASK;            // Stop USB module clock
      USB_SuspendCB();
    }
 #endif
}
