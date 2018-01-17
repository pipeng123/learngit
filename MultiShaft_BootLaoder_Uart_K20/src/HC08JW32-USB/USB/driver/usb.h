/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2006 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      usb.h
*
* @author    B01119
* 
* @version   1.0.3.0
* 
* @date      Oct-11-2011
* 
* @brief     USB generic defines
*
*******************************************************************************
*
* 
*
******************************************************************************/

#ifndef _USB_H_
#define _USB_H_

/******************** possible types in SETUP packet *****************************************/
#define M_COMMAND_TYPE_MASK     0x60
#define M_STANDARD_COMMAND      0x00 
#define M_CLASS_COMMAND         0x20 
#define M_VENDOR_COMMAND        0x40 
#define M_USER_COMMAND          0x60 

/******************** USB SETUP packet Standart Request Codes **************************************************/
#define RQST_GET_STATUS         0   // Returns current status of device/endpoint. No sw. attention req.
#define RQST_CLEAR_FEATURE      1   // Cleares feature (DEVICE_REMOTE_WAKEUP or ENDPIONT_HALT). No sw. attention req.
#define RQST_SET_FEATURE        3   // Sets feature. No sw. attention req. 
#define RQST_SET_ADDRESS        5   // Sets address. No sw. attention req.
#define RQST_GET_DESCRIPTOR     6   // Request is not handled automatically. User is notified by SETUP flag to prepare answear.
#define RQST_SET_DESCRIPTOR     7   // Not supported. STALL packed returned to host
#define RQST_GET_CONFIGURATION  8   // Return confihuration number in CONFIG. No sw. attention req.
#define RQST_SET_CONFIGURATION  9   // No sw. attention req.
#define RQST_GET_INTERFACE      10  // No alternative setting is supported. 
#define RQST_SET_INTERFACE      11  // No alternative setting is supported. Zero is allways returned.
#define RQST_SYNCH_FRAME        12  // Passed to user asvendor specific request.

/************************SETUP PACKET STRUCTURE*****************************************/

typedef union
{
  word w;
  struct
  {
    byte bH;
    byte bL;
  }u;
}sw;

typedef struct
{
  byte  bmRequestType;   // Characteristics of request:
                         //   D7: Data transfer direction:  0 = Host-to-device
                         //                                 1 = Device-to-host
                         //
                         //   D6...5: Type:                 0 = Standard
                         //                                 1 = Class
                         //                                 2 = Vendor
                         //                                 3 = Reserved
                         //
                         //   D4...0: Recipient:            0 = Device
                         //                                 1 = Interface
                         //                                 2 = Endpoint
                         //                                 3 = Other
                         //                                 4...31 = Reserved
   
  byte  bRequest;        // specifies the particular request
  word  wValue;          // the field vary according to the request
  word  wIndex;          // often used in requests to specify an endpoint or an interface.
  word  wLength;         // specifies the length of the data transferred during the second phase of the control transfer
} SetupPcktStrc;



/***************** DESCRIPTION TYPES **************************************************************/
#define DSC_DEVICE_TYPE           1 
#define DSC_CONFIGURATION_TYPE    2
#define DSC_STRING_TYPE           3
#define DSC_INTERFACE_TYPE        4
#define DSC_ENDPOINT_TYPE         5
#define DSC_DEVICE_QUALIFIER      6  
#define DSC_OTHER_SPEED_CONF      7
#define DSC_INTERFACE_POWER       8
#define DSC_OTG                   9
#define DSC_DEBUG                 10
#define DSC_INTERFACE_ASSOCIATION 11

/************************** USB DESCRIPTOR  STRUCTURE *********************************************
 **************************************************************************************************/
/* DEVICE Descriptor Structure */
typedef struct 
{
  byte bLength;             // length of this descriptor
  byte bDescriptorType;     // DEVICE descriptor type
  word bcdUSB;              // USB release Num. in BCD
  byte bDeviceClass;        // device Class Code
  byte bDeviceSubClass;     // device subclass code
  byte bDeviceProtocol;     // device protocol code
  byte bMaxPacketSize0;     // max. endpoint 0 buffer size -> allways 8
  word idVendor;            // vendor id. - Freescale 
  word idProduct;           // product id
  word bcdDevice;           // device release number
  byte iManufacturer;       // index of manufacturer string descriptor
  byte iProduct;            // index of product string descriptor
  byte iSerialNumber;       // index of serial number string descriptor
  byte bNumConfigurations;  // number of possible configurations
} DeviceDscStrc;

/* CONFIGURATION  Descriptor Structure */
typedef struct 
{
  byte bLength;             // length of this descriptor
  byte bDescriptorType;     // CONFIGURATION descriptor type
  word wTotalLength;        // length of configuration descriptor in bytes (including interface, endpoint)
  byte bNumInterfaces;      // number of interfaces - at least one
  byte bConfigurationValue; // value to use as an argument to the SetConfiguration() req. to select this configuration    
  byte iConfiguration;      // index of string descriptor describing this configuration
  byte bmAttributes;        // bmAttributes - 0x?0   bit 7-reserve (one)
                            //   bit 6-self powered
                            //   bit 5-remote wakeup
                            //   bit 4-0-reserved
  byte bMaxPower;           // max. power consumption in this configuration when the device is operational. In 2mA units.
}ConfigDscStrc;

/* INTERFACE Association Descriptor Structure */
typedef struct 
{
  byte bLength;             // length of this descriptor
  byte bDescriptorType;     // INTERFACE ASSOCIATION descriptor type 
  byte bFirstInterface;     // number of first interface to be associated
  byte bInterfaceCount;     // number of assciated interfaces
  byte bFunctionClass;      // class code
  byte bFunctionSubClass;   // subclass code
  byte bFunctionProtocol;   // protocol code (assigned by the USB).
  byte iFunction;           // Index of string descriptor describing this interface
} IntfcAssocDscStrc;


/* INTERFACE Descriptor Structure */
typedef struct 
{
  byte bLength;             // length of this descriptor
  byte bDescriptorType;     // INTERFACE descriptor type 
  byte bInterfaceNumber;    // number of this interface.
  byte bAlternateSetting;   // value used to select this alternate setting for the interface identified in the prior field - not allowed
  byte bNumEndpoints;       // number of endpoints used by this interface
  byte bInterfaceClass;     // class code
  byte bInterfaceSubClass;  // subclass code
  byte bInterfaceProtocol;  // protocol code (assigned by the USB).
  byte iInterface;          // Index of string descriptor describing this interface
} IntfcDscStrc;

/* ENDPOINT Descriptor Structure */
typedef struct 
{
  byte bLength;             // length of this descriptor
  byte bDescriptorType;     // ENDPOINT descriptor type
  byte bEndpointAddress;    // bit 3..0 endpoint number
                            // bit 6..4 Reserved reset to zero
                            // bit 7     0-OUT, 1-IN               
  byte bmAttributes;        // bits 1..0: Transfer Type   00 = Control
                            //                            01 = Isochronous
                            //                            10 = Bulk
                            //                            11 = Interrupt
                            // not an isochronous endpoint, bits 5..2 are reserved and must be set to zero. 
                            // if isochronous, they are defined as follows: 
                            // bits 3..2: Synchronization Type:  00 = No Synchronization
                            //                                   01 = Asynchronous
                            //                                   10 = Adaptive
                            //                                   11 = Synchronous
                            // bits 5..4: Usage Type: 00 = Data endpoint
                            //                        01 = Feedback endpoint
                            //                        10 = Implicit feedback Data endpoint
                            //                        11 = Reserved
  word wMaxPacketSize;      // maximum packet size this endpoint is capable of sending or receiving
  byte bInterval;           // interval for polling endpoint for data transfers.
} EpDscStrc;

/* STRING Descriptor structure */
typedef struct 
{
  byte bLength;             // length of this descriptor
  byte bDescriptorType;     // ENDPOINT descriptor type
  byte bString;             // N bytes of string
} StringDscStrc;
/* Note that string descriptor structure has variable length of bString */


// Bit Definition for USB_Status;
#define SUSPEND_STATE     0x01               // USB suspend detected
#define RESUME_STATE      0x02               // USB resume detected
#define RESET_STATE       0x04               // USB RESET detected
#define CONFIG_STAGE      0x08               // USB CONFIG Stage


/* Endpoint Address Definitions by USB2.0 */
#define EP01_OUT_ADR      0x01
#define EP01_IN_ADR       0x81
#define EP02_OUT_ADR      0x02
#define EP02_IN_ADR       0x82
#define EP03_OUT_ADR      0x03
#define EP03_IN_ADR       0x83
#define EP04_OUT_ADR      0x04
#define EP04_IN_ADR       0x84


// byte manipulating macros
#define CHNG_ENDIAN(w)    ((((w)&0xFF00)>>8)|(((w)&0x00FF)<<8))
#define CHNG_ENDIANL(w)   ((((w)&0xFF000000)>>24)|(((w)&0x00FF0000)>>8)|(((w)&0x0000FF00)<<8)|(((w)&0x000000FF)<<24))
#define H_BYTE(w)         (byte)(((w)&0xFF00)>>8)

#define IDENT_CONFIG_DSC(x)  byte* const ptrToConfigDsc = (byte*)&x
#define IDENT_DEVICE_DSC(x)  byte* const ptrToDeviceDsc = (byte*)&x

#endif  _USB_H_ 
