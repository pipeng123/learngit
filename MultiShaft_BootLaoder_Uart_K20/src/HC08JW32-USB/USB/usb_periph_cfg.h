/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      usb_periph_cfg.h
*
* @author    r30323
*
* @version   1.0.2.0
*
* @date      Oct-11-2011
*
* @brief     EP setting
*
*******************************************************************************
* Here we ought to set Endpoint1 - Endpoint3 parameters
*
*
******************************************************************************/
#ifndef _USB_PERIPH_CFG_H
#define _USB_PERIPH_CFG_H


#define EP0_BUFFER_SIZE        0x08

/******************** ENDPOINT MODE TYPES **********************************/
/****************** do not modify this section *****************************/
#define EP_MODE_DISABLE        0x00            //Control Transfer
#define EP_MODE_ISO            0x40            //Isochronous Transfer - NOT supported
#define EP_MODE_BULK           0x80            //Bulk Transfer
#define EP_MODE_INT            0xC0            //Interrupt Transfer

/* Modify HERE  */
#define EP1_MODE               EP_MODE_INT
#define EP2_MODE               EP_MODE_BULK
#define EP3_MODE               EP_MODE_BULK
#define EP4_MODE               EP_MODE_DISABLE


/******************** ENDPOINT DIRECTION TYPES ******************************/
/****************** do not modify this section *****************************/
#define EP_DIR_IN              0x10
#define EP_DIR_OUT             0x00

/* Modify HERE  */
#define EP1_DIR                EP_DIR_IN
#define EP2_DIR                EP_DIR_OUT
#define EP3_DIR                EP_DIR_IN
#define EP4_DIR                EP_DIR_OUT


/******************** ENDPOINT BUFFER LENGTH TYPES **************************/
/****************** do not modify this section *****************************/
#define    EP_BUFFER_SIZE_0    0xFF
#define    EP_BUFFER_SIZE_8    0x00
#define    EP_BUFFER_SIZE_16   0x04
#define    EP_BUFFER_SIZE_32   0x08
#define    EP_BUFFER_SIZE_64   0x0C

/* Modify HERE */
#define EP1_BUF_SIZE_BITMAP    EP_BUFFER_SIZE_16
#define EP2_BUF_SIZE_BITMAP    EP_BUFFER_SIZE_16
#define EP3_BUF_SIZE_BITMAP    EP_BUFFER_SIZE_16
#define EP4_BUF_SIZE_BITMAP    EP_BUFFER_SIZE_0

/* do NOT modify */
#define _EP1_BUFFER_SIZE_MOD   (1<<(EP1_BUF_SIZE_BITMAP>>2))
#define _EP2_BUFFER_SIZE_MOD   (1<<(EP2_BUF_SIZE_BITMAP>>2))
#define _EP3_BUFFER_SIZE_MOD   (1<<(EP3_BUF_SIZE_BITMAP>>2))
#define _EP4_BUFFER_SIZE_MOD   (1<<(EP4_BUF_SIZE_BITMAP>>2))

/** use this defines in your descriptor or code - do not modify this section! **/
#define EP1_BUFFER_SIZE        (_EP1_BUFFER_SIZE_MOD<<3)
#define EP2_BUFFER_SIZE        (_EP2_BUFFER_SIZE_MOD<<3)
#define EP3_BUFFER_SIZE        (_EP3_BUFFER_SIZE_MOD<<3)
#define EP4_BUFFER_SIZE        (_EP4_BUFFER_SIZE_MOD<<3)


/******************** ENDPOINT INTERFACE TYPED ******************************/
/****************** do not modify this section *****************************/
#define EP_INTERFACE_0         0
#define EP_INTERFACE_1         1

/* Modify HERE  */
/* here you should assign all endpoints to their interfaces */
#define EP1_INTFCE  EP_INTERFACE_0
#define EP2_INTFCE  EP_INTERFACE_1
#define EP3_INTFCE  EP_INTERFACE_1
#define EP4_INTFCE  EP_INTERFACE_0

/* do NOT modify */
/****** used in USB initialise routine *******/
#define UINTFCR_INI ((EP4_INTFCE << 6)|(EP3_INTFCE << 4)|(EP2_INTFCE << 2)|EP1_INTFCE)


/************* create REGISTERS INI vlaues for USB periphery *****************/
#define UEP1CSR_INI (EP1_BUF_SIZE_BITMAP | EP1_DIR | EP1_MODE)
#define UEP2CSR_INI (EP2_BUF_SIZE_BITMAP | EP2_DIR | EP2_MODE)
#define UEP3CSR_INI (EP3_BUF_SIZE_BITMAP | EP3_DIR | EP3_MODE)
#define UEP4CSR_INI (EP4_BUF_SIZE_BITMAP | EP4_DIR | EP4_MODE)

/*********** BUFFER ADDRESS base pointer are calculated from SIZES************/
/***************** we assume that EP1 base address is 0x1000******************/

#define UEP12BPR_INI ((_EP1_BUFFER_SIZE_MOD<< 4)| 0)
#define UEP34BPR_INI (((_EP1_BUFFER_SIZE_MOD+_EP2_BUFFER_SIZE_MOD+_EP3_BUFFER_SIZE_MOD)<<4)|(_EP1_BUFFER_SIZE_MOD+_EP2_BUFFER_SIZE_MOD))


#define EP0_BASE_ADR  (byte*)0x0040
#define EP1_BASE_ADR  (byte*)(((UEP12BPR_INI&0x07)<<3)|0x1000)
#define EP2_BASE_ADR  (byte*)(((UEP12BPR_INI&0x70)>>1)|0x1000)
#define EP3_BASE_ADR  (byte*)(((UEP34BPR_INI&0x07)<<3)|0x1000)
#define EP4_BASE_ADR  (byte*)(((UEP34BPR_INI&0x70)>>1)|0x1000)

/* CONFIG2 REGISTER setting - to enable 3V3 regulator and chip reset comment out the defines*/
//#define USB_3V3REGULATOR_DIS  CONFIG2_VREG33D_MASK
#define USB_CHIP_RESET_DIS   CONFIG2_URSTD_MASK
#define USB_PULLUP_ENA       0x01

/* Settings of the USB periphery interrupts. If interrupt will not be used just comment out the defines */
#define USB_SETUPIE_ENA      1
#define STRING_DSC_TAB_LEN   4
#define STRING_DSC_TAB       stringDscTab

#define USB_CLASS_REQUEST_CB USB_ClassRequestCB

// see. usb_driver.c 
#define WIN_USBSER_SYS_HACK 1
#define USB_DO_NOTHING() {asm "NOP"}

#endif  _USB_PERIPH_CFG_H
