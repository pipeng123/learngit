/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      usb_cdc.h
*
* @author    r30323
* 
* @version   1.0.2.0
* 
* @date      Oct-11-2011
* 
* @brief     Communication Device Class definitions 
*
*******************************************************************************
*
* Detailed Description of the file. If not used, remove the separator above.
*
******************************************************************************/

#ifndef _USB_CDC_H
#define _USB_CDC_H


// Class-Specific Codes for Communication Devices
#define CLASS_CDC_DEVICE                  0x02
/* Communication Interface Class Code */
#define CLASS_COMM_INTF                   0x02
/* Communication Interface Class SubClass Codes */
#define SCLASS_ABST_CTRL_MODEL            0x02
/* Communication Interface Class Control Protocol Codes */
#define CLASS_V25TER                      0x01    // Common AT commands ("Hayes(TM)")



/* Data Interface Class Codes */
#define CLASS_DATA_INTF                   0x0A
/* Data Interface Class Protocol Codes */
#define CLASS_NO_PROTOCOL                 0x00    // No class specific protocol required


/* Communication Feature Selector Codes */
#define SDSC_ABSTRACT_STATE               0x01
#define SDSC_COUNTRY_SETTING              0x02

/* Functional Descriptors */
/* Type Values for the bDscType Field */
#define DSC_CS_INTERFACE                  0x24
#define DSC_CS_ENDPOINT                   0x25

// Descriptor subtype - Functional descriprors
/* bDscSubType in Functional Descriptors */
#define SDSC_FN_HEADER                    0x00
#define SDSC_FN_CALL_MGT                  0x01
#define SDSC_FN_ACM                       0x02    // ACM - Abstract Control Management
#define SDSC_FN_DLM                       0x03    // DLM - Direct Line Managment
#define SDSC_FN_TELEPHONE_RINGER          0x04
#define SDSC_FN_RPT_CAPABILITIES          0x05
#define SDSC_FN_UNION                     0x06
#define SDSC_FN_COUNTRY_SELECTION         0x07
#define SDSC_FN_TEL_OP_MODES              0x08
#define SDSC_FN_USB_TERMINAL              0x09
/* more.... see Table 25 in USB CDC Specification 1.1 */


/* CDC */
#define CDC_COMM_INTF_ID                  0x00
#define CDC_DATA_INTF_ID                  0x01

#define MAX_EP_NUMBER                     3    

/* CDC Bulk IN transfer states */
#define CDC_TX_READY                      0
#define CDC_TX_BUSY                       1
#define CDC_TX_BUSY_ZLP                   2       // ZLP: Zero Length Packet
#define CDC_TX_COMPLETING                 3


/* Functional Descriptor Structures by CDC Specification 1.1 */
/* HEADER Functional Descriptor */
typedef struct 
{
  byte bFunctionLength;         // size of this descriptor in bytes.
  byte bDescriptorType;         // CS_INTERFACE descriptor type.
  byte bDescriptorSubtype;      // header functional descriptor subtype
  word bcdCDC;                  // release number in binary-coded decimal
}CdcHeaderFnDscStrc;

/* ABSTRACT CONTROL MANAGMENT Functional Descriptor */
typedef struct 
{
  byte bFunctionLength;         // size of this functional descriptor
  byte bDescriptorType;         // CS_INTERFACE
  byte bDescriptorSubtype;      // descriptor subtype 
  byte bmCapabilities;
}CdcAcmFnDscStrc;

/* UNION Functional Descriptor */
typedef struct 
{
  byte bFunctionLength;         // size of this functional descriptor
  byte bDescriptorType;         // CS_INTERFACE
  byte bDescriptorSubtype;      // union functional descriptor SubType
  byte bMasterInterface;        // the number of master interface 
  byte bSlaveInterface0;        // interface number of first slave
}CdcUnionFnDscStrc;

/* CALL MANAGMENT Functional Descriptor */
typedef struct 
{
  byte bFunctionLength;         // size of this functional descriptor,
  byte bDescriptorType;         // CS_INTERFACE
  byte bDescriptorSubtype;      // call Management functional descriptor subtype
  byte bmCapabilities;          // D1:  0 - Device sends/receives call management information 
                                //         only over the Communication Class interface.
                                //      1 - Device can send/receive call management information over a
                                //          Data Class interface.
                                // D0:  0 - Device does not handle call management itself.
                                //      1 - Device handles call management itself.
  byte bDataInterface;          // interface number of Data Class interface optionally used for call management.
}CdcCallMngmtFnDscStrc;


/* LINE CODING Structure */
typedef struct
{
  unsigned long   dwDTERate;    // data terminal rate, in bits per second
  byte    bCharFormat;          // stop bits:
                                //    0 : 1 Stop bit
                                //    1 : 1.5 Stop bits
                                //    2 : 2 Stop bits
  
  byte    bParityType;               // parity:
                                //   0 : None
                                //   1 : Odd
                                //   2 : Even
                                //   3 : Mark
                                //   4 : Space
  byte    bDataBits;                  // data bits (5, 6, 7, 8 or 16)
} CdcLineCodingStrc;

#define LINEC_1_STOPB           0
#define LINEC_15_STOPB          1
#define LINEC_2_STOPB           2

#define LINEC_PARITY_NONE       0
#define LINEC_PARITY_ODD        1
#define LINEC_PARITY_EVEN       2
#define LINEC_PARITY_MARK       3
#define LINEC_PARITY_SPACE      4


/* Control Line State variable bitmap description */
#define CONTROL_LINE_STATE_DTR        0x0001       // 1 .. RTS active
#define CONTROL_LINE_STATE_RTS        0x0002       // 1 .. present


/* ELEMENT NOTIFICATIONS */
#define CDC_SERIAL_STATE              0x20

/* Serial State variable bitmap description  */
#define SERIAL_STATE_OVERRUN          0x40
#define SERIAL_STATE_PARITY           0x20
#define SERIAL_STATE_FRAMING          0x10
#define SERIAL_STATE_RING             0x08
#define SERIAL_STATE_BREAK            0x04
#define SERIAL_STATE_TXCARRIER        0x02  // DSR
#define SERIAL_STATE_RXCARRIER        0x01  // DCD

/* Communication Interface CLASS MESSAGES */

#define  SEND_ENCAPSULATED_COMMAND    0x00
#define  GET_ENCAPSULATED_RESPONSE    0x01
#define  SET_COMM_FEATURE             0x02
#define  GET_COMM_FEATURE             0x03
#define  CLEAR_COMM_FEATURE           0x04
#define  SET_LINE_CODING              0x20
#define  GET_LINE_CODING              0x21
#define  SET_CONTROL_LINE_STATE       0x22
#define  SEND_BREAK                   0x23

// CDC configuraion 1 descriptor definition
typedef struct                           
{
  ConfigDscStrc           configDsc;                   
  IntfcDscStrc            intfcDsc00;                 
  CdcHeaderFnDscStrc      cdcHeader_fn;   
  CdcAcmFnDscStrc         cdcAcmFn;      
  CdcUnionFnDscStrc       cdcUnionFn;    
  CdcCallMngmtFnDscStrc   cdcCallMngmtFn; 
  EpDscStrc               ep02in;           
  IntfcDscStrc            intfcDsc01;                 
  EpDscStrc               ep03out;           
  EpDscStrc               ep03in;           
}Config01_dsc_strc;

#endif _USB_CDC_H
