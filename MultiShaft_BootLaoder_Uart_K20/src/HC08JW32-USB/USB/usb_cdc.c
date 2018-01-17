/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
* (c) Copyright 2001-2004 Motorola, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file      usb_cdc.c
*
* @author    r30323
* 
* @version   1.0.4.0
* 
* @date      Oct-11-2011
* 
* @brief     Here we define Communication Class USB Device descriptors (CDC)
*
*******************************************************************************
*
* 
*
******************************************************************************/
#include "map.h"
#include "usb.h"
#include "usb_periph_cfg.h"
#include "usb_cdc.h"

#include "usb_driver.h"

#pragma CONST_SEG MyConstant
const DeviceDscStrc device01 =
{
  sizeof(DeviceDscStrc),      // length of this descriptor
  DSC_DEVICE_TYPE,               // DEVICE descriptor type
  CHNG_ENDIAN(0x0200),         // USB release Num. in BCD
  CLASS_CDC_DEVICE,               // device Class Code
  0x00,                                 // device subclass code
  0x00,                                 // device protocol code
  EP0_BUFFER_SIZE,               // max. endpoint 0 buffer size -> allways 8
  CHNG_ENDIAN(0x15A2),      // vendor id. - Freescale 
  CHNG_ENDIAN(0x0010),      // product id - AN2295 Bootloader
  CHNG_ENDIAN(0x0000),         // device release number
  0x00,                                 // index of manufacturer string descriptor
  0x01,                                 // index of product string descriptor
  0x02,                                 // index of serial number string descriptor
  0x01                                 // number of possible configurations
};

// Configuration 1
const Config01_dsc_strc config01 =
{
  // CONFIGURATION descriptor
  sizeof(ConfigDscStrc),
  DSC_CONFIGURATION_TYPE,
  CHNG_ENDIAN(sizeof(Config01_dsc_strc)),
  0x02, // number or interfaces
  0x01, // config value
  0x00, // $ descriptor
  0x80,
  0x32,

  // INTERFACE 00 descriptor
  sizeof(IntfcDscStrc),
  DSC_INTERFACE_TYPE,
  0,      // interface number
  0,
  1,    // number of endpoints
  CLASS_COMM_INTF,
  SCLASS_ABST_CTRL_MODEL,
  CLASS_NO_PROTOCOL,
  0,
    
  // HEADER FUNCTION CDC Class Specific descriptor
  sizeof(CdcHeaderFnDscStrc),
  DSC_CS_INTERFACE,
  SDSC_FN_HEADER,
  CHNG_ENDIAN(0x0110),
  
  // ABSTRACT CONTROL MODEL CDC Class Specific descriptor
  sizeof(CdcAcmFnDscStrc),
  DSC_CS_INTERFACE,
  SDSC_FN_ACM,
  0x02,
  
  // UNION CDC Class Specific descriptor
  sizeof(CdcUnionFnDscStrc),
  DSC_CS_INTERFACE,
  SDSC_FN_UNION,
  CDC_COMM_INTF_ID,
  CDC_DATA_INTF_ID,
  
  // CALL MANAGMENT FUNCTION CDC Class Specific descriptor
  sizeof(CdcCallMngmtFnDscStrc),
  DSC_CS_INTERFACE,
  SDSC_FN_CALL_MGT,
  0x00,
  CDC_DATA_INTF_ID,
  
  // ENDPOINT 01 IN descriptor interrupt
  sizeof(EpDscStrc),
  DSC_ENDPOINT_TYPE,
  EP01_IN_ADR,
  (EP1_MODE>>6),
  CHNG_ENDIAN(EP1_BUFFER_SIZE),                   
  0x02,
  
  // INTERFACE 02 descriptor
  sizeof(IntfcDscStrc),
  DSC_INTERFACE_TYPE,
  1,
  0,
  2,
  CLASS_DATA_INTF,
  0,
  CLASS_NO_PROTOCOL,
  0,
  
  // ENDPOINT 02 OUT descriptor
  sizeof(EpDscStrc),
  DSC_ENDPOINT_TYPE,
  EP02_OUT_ADR,
  (EP2_MODE>>6),
  CHNG_ENDIAN(EP2_BUFFER_SIZE),
  0x00,
  
  // ENDPOINT 03 IN descriptor
  sizeof(EpDscStrc),
  DSC_ENDPOINT_TYPE,
  EP03_IN_ADR,
  (EP3_MODE>>6),
  CHNG_ENDIAN(EP3_BUFFER_SIZE),
  0x00,
};

// STRING Descriptors index 0
const struct 
{
  byte bLength;
  byte bDescriptorType;
  word string[1];
}StringDscStrc00 = 
{
  sizeof(StringDscStrc00),
  DSC_STRING_TYPE,
  CHNG_ENDIAN(0x0409),
};

// STRING Descriptors index 2
const struct 
{
  byte bLength;
  byte bDescriptorType;
  byte string[34];
}StringDscStrc01 = 
{
  sizeof(StringDscStrc01),
  DSC_STRING_TYPE,
  'A',0,'N',0,'2',0,'2',0,'9',0,'5',0,' ',0,
  'B',0,'o',0,'o',0,'t',0,'l',0,'o',0,'a',0,'d',0,'e',0,'r',0
};

const struct 
{
  byte bLength;
  byte bDescriptorType;
  byte string[28];
}StringDscStrc02 = 
{
  sizeof(StringDscStrc02),
  DSC_STRING_TYPE,
  '0',0,'0',0,'2',0,'4',0,'0',0,'0',0,'0',0,'0',0,'0',0,'0',0,'0',0,'0',0,'0',0,'1',0
};

const byte* const stringDscTab[STRING_DSC_TAB_LEN] = 
{
  (byte*)&StringDscStrc00,
  (byte*)&StringDscStrc01,
  (byte*)&StringDscStrc02,
};

// Create pointers to config01 and device01 variables in flash
// These variables are used in USB_driver to locate config01 and
// device01 variables 
IDENT_CONFIG_DSC(config01);
IDENT_DEVICE_DSC(device01);

#pragma CONST_SEG DEFAULT


// from here variables are located in RAM

CdcLineCodingStrc cdcLineCoding = 
{
  CHNG_ENDIANL(115200),
  LINEC_1_STOPB,
  LINEC_PARITY_NONE,
  8,
};

// control signal RTS / DTR
word cdcControlLineState = 0;
// serial state DSR / DCD
word cdcSerialState = 0; 


// CDC-class specific requests
void USB_ClassRequestCB(void)
{
  word temp;
  
   switch (((SetupPcktStrc *)EP0_BASE_ADR)->bRequest) 
   {
      case(SEND_ENCAPSULATED_COMMAND):
            USB_WRSTALL_EP0(1);
         break;
         
      case(GET_ENCAPSULATED_RESPONSE):
             USB_WRSTALL_EP0(1);
         break;
         
      case(SET_COMM_FEATURE):
             USB_WRSTALL_EP0(1);
         break;
      
      case(GET_COMM_FEATURE):
            USB_WRSTALL_EP0(1);
         break;
      
      case(CLEAR_COMM_FEATURE):
             USB_WRSTALL_EP0(1);
         break;
      
      case(SET_LINE_CODING):    // OUT packet      
        temp = CHNG_ENDIAN(((SetupPcktStrc *)EP0_BASE_ADR)->wLength);
        if(temp > 0xFF) temp = 0xFF;
         USB_RxBuff0((byte*)&cdcLineCoding,(byte)temp);
      break; 
      
      case(GET_LINE_CODING):    // IN packet

         temp = CHNG_ENDIAN(((SetupPcktStrc *)EP0_BASE_ADR)->wLength);
        if(temp > 0xFF) temp = 0xFF;
         
      (void) USB_TxBuff0((byte*)&cdcLineCoding, (byte)temp);
         break; 

      case(SET_CONTROL_LINE_STATE):      //OUT 
        cdcControlLineState = CHNG_ENDIAN(((SetupPcktStrc *)EP0_BASE_ADR)->wValue);
      
        // this command has zero data length
         (void) USB_TxBuff0(NULL, 0);
         break; 
         
      case(SEND_BREAK):
          USB_WRSTALL_EP0(1);
         break; 

      default:
          USB_WRSTALL_EP0(1);
         break;   
   }
}

