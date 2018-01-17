#line 1 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.c"
/*****************************************************************************
 * (c) Copyright 2011, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      flash_kinetis.c
 * @author    R20253
 * @version   1.0.18.0
 * @date      Jan-23-2014
 * @brief     Flash programming driver
 * @par       
 * @include   
 * @par       
 * @include         
 ******************************************************************************/

#line 1 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"
/******************************************************************************
* 
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved                       
*
*******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file      kinetis_params.h
*
* @author    b01119
* 
* @version   0.0.26.0
* 
* @date      Mar-11-2014
* 
* @brief     Main configuration file for IIC bootloader
*
******************************************************************************/




#line 1 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader_cfg.h"
/******************************************************************************
* 
* Copyright (c) 2012 Freescale Semiconductor;
* All Rights Reserved                       
*
*******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file      bootloader_cfg.h
*
* @author    b01119
* 
* @version   0.0.21.0
* 
* @date      Feb-14-2014
* 
* @brief     Main configuration file for SCI bootloader
*
******************************************************************************/





#line 46 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader_cfg.h"
  //#include "AN2295_TWR_K20D50_cfg.h"
  //#include "AN2295_TWR_K20D72_cfg.h"
  //#include "AN2295_TWR_K60_cfg.h"
  //#include "AN2295_TWR_K60D100_cfg.h"
#line 1 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\AN2295_TWR_K70120_cfg.h"
/**************************************************/
/** USER SETTINGS OF KINETIS MCU */
/**  Kinetis ARM Cortex-M4 model */
//K10_50MHz K11_50MHz K12_50MHz K10_72MHz K10_100MHz K10_120MHz 
//K20_50MHz K21_50MHz K22_50MHz K20_72MHz K20_100MHz K20_120MHz 
//K30_72MHz K30_100MHz 
//K40_72MHz K40_100MHz 
//K50_72MHz K51_72MHz K50_100MHz 
//K60_100MHz K60_120MHz 
//K70_120MHz

/**  Kinetis ARM Cortex-M0+ model */
//KL0_48MHz
//KL1_48MHz
//KL2_48MHz KL25_48MHz




/*  in the case of using USB VIRTUAL SERIAL LINK you must activate No break TRIM CHECKBOX in the master AN2295 PC Application  */
/*  the break impulse is replaced by using only 9 bits zero impulse  */
//  BREAK IMPULSE       |START| |0| |0| |0| |0| |0| |0| |0| |0| |0| |0| STOP|
//  ZERO IMPULSE        |START| |0| |0| |0| |0| |0| |0| |0| |0| |0| |STOP|



/** Kinetis Flash memory size */



/** Bootloader flash protection */


/** Boot timeout after POR (Power On Reset) for wait to connect Master **/
/** BOOT_WAITING_TIMEOUT * 10ms **/


/**************************************************/

    /* Actual used UART module */


    /* Actual used UART module */
    /* A range of UART baudrates is (9600 - 115200) */


    /** GPIO & UART pins initialization */



    /*  setting of multiplexer for UART alternative of pin */


    /*  setting of multiplexer for GPIO alternative of pin */




#line 83 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\AN2295_TWR_K70120_cfg.h"

/**************************************************/
/* Actual used PIN reset setting */







/**************************************************/
/** BOOTLOADER FEATURES SETTINGS */











/**************************************************/
/** CALIBRATION OF BOOTLOADER TRIM SETTINGS */

/******************************************************************************
*
*
*     Advanced detail settings for non standard settings
*
*
******************************************************************************/


/* Flash block count of this MCU */
//#define FLASH_BLOCK_CNT 1

/* Start address of interrupt vector table */ 
//#define INTERRUPT_VECTORS 0x0000

/* Start address of relocated interrutp vector table */
//#define RELOCATED_VECTORS 0x4000 

/* Flash start address */
//#define USER_FLASH_START RELOCATED_VECTORS

/* Flash end address */
//#define USER_FLASH_END 0x0003FFFF

/* Flash2 start address */
//#define USER_FLASH_START_2 0x00040000

/* Flash2 end address */
//#define USER_FLASH_END_2 0x0005FFFF

/* Size of write block */
//#define FLASH_WRITE_PAGE 128

/* Size of erase block */
//#define FLASH_ERASE_PAGE 2048

/* Maximal length of ID_STRING */
//#define ID_STRING_MAX 5

/* Description string */
//#define KINETIS_MODEL_STR "K53"
#line 51 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader_cfg.h"
  //#include "AN2295_TWR_K20_1M_cfg.h"


#line 38 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"



//  Kinetis ARM Cortex-M4 Microcontrollers models macros
#line 48 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"

#line 56 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"

















//  Kinetis ARM Cortex-M0+ Microcontrollers models macros






//  Kinetis ARM Cortex-M0+ Microcontrollers metering models macros









#line 97 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"


















//  Kinetis Flash memory sizes
#line 124 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"

/****************** Include the MCU header files and basic types **************/
#line 1 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\main.h"
/******************************************************************************
* 
* Copyright (c) 2012 Freescale Semiconductor;
* All Rights Reserved                       
*
*******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file      main.h
*
* @author    b01119
* 
* @version   0.0.7.0
* 
* @date      Dec-19-2012
* 
* @brief     Main header file for SCI bootloader
*
******************************************************************************/








#line 1 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/*
** ###################################################################
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K70P256M150SF3RM, Rev. 0, May 2011
**     Version:             rev. 1.0, 2011-08-12
**
**     Abstract:
**         This header file implements peripheral memory map for MK70F12
**         processor.
**
**     Copyright: 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2011-08-12)
**         Initial version.
**
** ###################################################################
*/

/**
 * @file MK70F12.h
 * @version 1.0.1.0
 * @date Sep-17-2012
 * @brief Peripheral memory map for MK70F12
 *
 * This header file implements peripheral memory map for MK70F12 processor.
 */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */




/* Check if another memory map has not been also included */





#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\stdint.h"
/* stdint.h standard header */
/* Copyright 2003-2010 IAR Systems AB.  */




  #pragma system_include


#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\ycheck.h"




/* A definiton for a function of what effects it has.
   NS  = no_state, i.e. it uses no internal or external state. It may write
         to errno though
   NE  = no_state, no_errno,  i.e. it uses no internal or external state,
         not even writing to errno. 
   NRx = no_read(x), i.e. it doesn't read through pointer parameter x.
   NWx = no_write(x), i.e. it doesn't write through pointer parameter x.
*/

#line 99 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\ycheck.h"









#line 11 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\stdint.h"
#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */





  #pragma system_include


#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\ycheck.h"

#line 12 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* Convenience macros */









/* Used to refer to '__aeabi' symbols in the library. */ 


                /* Versions */










/*
 * Support for some C99 or other symbols
 *
 * This setting makes available some macros, functions, etc that are
 * beneficial.
 *
 * Default is to include them.
 *
 * Disabling this in C++ mode will not compile (some C++ functions uses C99
 * functionality).
 */


  /* Default turned on when compiling C++, EC++, or C99. */
#line 59 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"





#line 70 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* Configuration */
#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"
/***************************************************
 *
 * DLib_Defaults.h is the library configuration manager.
 *
 * Copyright 2003-2010 IAR Systems AB.  
 *
 * This configuration header file performs the following tasks:
 *
 * 1. Includes the configuration header file, defined by _DLIB_CONFIG_FILE,
 *    that sets up a particular runtime environment.
 *
 * 2. Includes the product configuration header file, DLib_Product.h, that
 *    specifies default values for the product and makes sure that the
 *    configuration is valid.
 *
 * 3. Sets up default values for all remaining configuration symbols.
 *
 * This configuration header file, the one defined by _DLIB_CONFIG_FILE, and
 * DLib_Product.h configures how the runtime environment should behave. This
 * includes all system headers and the library itself, i.e. all system headers
 * includes this configuration header file, and the library has been built
 * using this configuration header file.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/





  #pragma system_include


/* Include the main configuration header file. */
#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\INC\\c\\DLib_Config_Normal.h"
/* Customer-specific DLib configuration. */
/* Copyright (C) 2003 IAR Systems.  All rights reserved. */





  #pragma system_include


/* No changes to the defaults. */

#line 40 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"
  /* _DLIB_CONFIG_FILE_STRING is the quoted variant of above */
#line 47 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"

/* Include the product specific header file. */
#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Product.h"




   #pragma system_include



/*********************************************************************
*
*       Configuration
*
*********************************************************************/

/* Wide character and multi byte character support in library.
 * This is not allowed to vary over configurations, since math-library
 * is built with wide character support.
 */


/* ARM uses the large implementation of DLib */


/* This ensures that the standard header file "string.h" includes
 * the Arm-specific file "DLib_Product_string.h". */


/* This ensures that the standard header file "fenv.h" includes
 * the Arm-specific file "DLib_Product_fenv.h". */


/* Max buffer used for swap in qsort */




/* Enable system locking  */
#line 45 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Product.h"

/* Enable AEABI support */


/* Enable rtmodel for setjump buffer size */


/* Enable parsing of hex floats */






/* Special placement for locale structures when building ropi libraries */




/* CPP-library uses software floatingpoint interface */


/* Use speedy implementation of floats (simple quad). */


/* Configure generic ELF init routines. */
#line 99 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Product.h"







#line 51 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"



/*
 * The remainder of the file sets up defaults for a number of
 * configuration symbols, each corresponds to a feature in the
 * libary.
 *
 * The value of the symbols should either be 1, if the feature should
 * be supported, or 0 if it shouldn't. (Except where otherwise
 * noted.)
 */


/*
 * Small or Large target
 *
 * This define determines whether the target is large or small. It must be 
 * setup in the DLib_Product header or in the compiler itself.
 *
 * For a small target some functionality in the library will not deliver 
 * the best available results. For instance the _accurate variants will not use
 * the extra precision packet for large arguments.
 * 
 */







/*
 * File handling
 *
 * Determines whether FILE descriptors and related functions exists or not.
 * When this feature is selected, i.e. set to 1, then FILE descriptors and
 * related functions (e.g. fprintf, fopen) exist. All files, even stdin,
 * stdout, and stderr will then be handled with a file system mechanism that
 * buffers files before accessing the lowlevel I/O interface (__open, __read,
 * __write, etc).
 *
 * If not selected, i.e. set to 0, then FILE descriptors and related functions
 * (e.g. fprintf, fopen) does not exist. All functions that normally uses
 * stderr will use stdout instead. Functions that uses stdout and stdin (like
 * printf and scanf) will access the lowlevel I/O interface directly (__open,
 * __read, __write, etc), i.e. there will not be any buffering.
 *
 * The default is not to have support for FILE descriptors.
 */





/*
 * Use static buffers for stdout
 *
 * This setting controls whether the stream stdout uses a static 80 bytes
 * buffer or uses a one byte buffer allocated in the file descriptor. This
 * setting is only applicable if the FILE descriptors are enabled above.
 *
 * Default is to use a static 80 byte buffer.
 */





/*
 * Support of locale interface
 *
 * "Locale" is the system in C that support language- and
 * contry-specific settings for a number of areas, including currency
 * symbols, date and time, and multibyte encodings.
 *
 * This setting determines whether the locale interface exist or not.
 * When this feature is selected, i.e. set to 1, the locale interface exist
 * (setlocale, etc). A number of preselected locales can be activated during
 * runtime. The preselected locales and encodings is choosen by defining any
 * number of _LOCALE_USE_xxx and _ENCODING_USE_xxx symbols. The application
 * will start with the "C" locale choosen. (Single byte encoding is always
 * supported in this mode.)
 *
 *
 * If not selected, i.e. set to 0, the locale interface (setlocale, etc) does
 * not exist. One preselected locale and one preselected encoding is then used
 * directly. That locale can not be changed during runtime. The preselected
 * locale and encoding is choosen by defining at most one of _LOCALE_USE_xxx
 * and at most one of _ENCODING_USE_xxx. The default is to use the "C" locale
 * and the single byte encoding, respectively.
 *
 * The default is not to have support for the locale interface with the "C"
 * locale and the single byte encoding.
 *
 * Supported locales
 * -----------------
 * _LOCALE_USE_C                  C standard locale (the default)
 * _LOCALE_USE_POSIX ISO-8859-1   Posix locale
 * _LOCALE_USE_CS_CZ ISO-8859-2   Czech language locale for Czech Republic
 * _LOCALE_USE_DA_DK ISO-8859-1   Danish language locale for Denmark
 * _LOCALE_USE_DA_EU ISO-8859-15  Danish language locale for Europe
 * _LOCALE_USE_DE_AT ISO-8859-1   German language locale for Austria
 * _LOCALE_USE_DE_BE ISO-8859-1   German language locale for Belgium
 * _LOCALE_USE_DE_CH ISO-8859-1   German language locale for Switzerland
 * _LOCALE_USE_DE_DE ISO-8859-1   German language locale for Germany
 * _LOCALE_USE_DE_EU ISO-8859-15  German language locale for Europe
 * _LOCALE_USE_DE_LU ISO-8859-1   German language locale for Luxemburg
 * _LOCALE_USE_EL_EU ISO-8859-7x  Greek language locale for Europe
 *                                (Euro symbol added)
 * _LOCALE_USE_EL_GR ISO-8859-7   Greek language locale for Greece
 * _LOCALE_USE_EN_AU ISO-8859-1   English language locale for Australia
 * _LOCALE_USE_EN_CA ISO-8859-1   English language locale for Canada
 * _LOCALE_USE_EN_DK ISO_8859-1   English language locale for Denmark
 * _LOCALE_USE_EN_EU ISO-8859-15  English language locale for Europe
 * _LOCALE_USE_EN_GB ISO-8859-1   English language locale for United Kingdom
 * _LOCALE_USE_EN_IE ISO-8859-1   English language locale for Ireland
 * _LOCALE_USE_EN_NZ ISO-8859-1   English language locale for New Zealand
 * _LOCALE_USE_EN_US ISO-8859-1   English language locale for USA
 * _LOCALE_USE_ES_AR ISO-8859-1   Spanish language locale for Argentina
 * _LOCALE_USE_ES_BO ISO-8859-1   Spanish language locale for Bolivia
 * _LOCALE_USE_ES_CL ISO-8859-1   Spanish language locale for Chile
 * _LOCALE_USE_ES_CO ISO-8859-1   Spanish language locale for Colombia
 * _LOCALE_USE_ES_DO ISO-8859-1   Spanish language locale for Dominican Republic
 * _LOCALE_USE_ES_EC ISO-8859-1   Spanish language locale for Equador
 * _LOCALE_USE_ES_ES ISO-8859-1   Spanish language locale for Spain
 * _LOCALE_USE_ES_EU ISO-8859-15  Spanish language locale for Europe
 * _LOCALE_USE_ES_GT ISO-8859-1   Spanish language locale for Guatemala
 * _LOCALE_USE_ES_HN ISO-8859-1   Spanish language locale for Honduras
 * _LOCALE_USE_ES_MX ISO-8859-1   Spanish language locale for Mexico
 * _LOCALE_USE_ES_PA ISO-8859-1   Spanish language locale for Panama
 * _LOCALE_USE_ES_PE ISO-8859-1   Spanish language locale for Peru
 * _LOCALE_USE_ES_PY ISO-8859-1   Spanish language locale for Paraguay
 * _LOCALE_USE_ES_SV ISO-8859-1   Spanish language locale for Salvador
 * _LOCALE_USE_ES_US ISO-8859-1   Spanish language locale for USA
 * _LOCALE_USE_ES_UY ISO-8859-1   Spanish language locale for Uruguay
 * _LOCALE_USE_ES_VE ISO-8859-1   Spanish language locale for Venezuela
 * _LOCALE_USE_ET_EE ISO-8859-1   Estonian language for Estonia
 * _LOCALE_USE_EU_ES ISO-8859-1   Basque language locale for Spain
 * _LOCALE_USE_FI_EU ISO-8859-15  Finnish language locale for Europe
 * _LOCALE_USE_FI_FI ISO-8859-1   Finnish language locale for Finland
 * _LOCALE_USE_FO_FO ISO-8859-1   Faroese language locale for Faroe Islands
 * _LOCALE_USE_FR_BE ISO-8859-1   French language locale for Belgium
 * _LOCALE_USE_FR_CA ISO-8859-1   French language locale for Canada
 * _LOCALE_USE_FR_CH ISO-8859-1   French language locale for Switzerland
 * _LOCALE_USE_FR_EU ISO-8859-15  French language locale for Europe
 * _LOCALE_USE_FR_FR ISO-8859-1   French language locale for France
 * _LOCALE_USE_FR_LU ISO-8859-1   French language locale for Luxemburg
 * _LOCALE_USE_GA_EU ISO-8859-15  Irish language locale for Europe
 * _LOCALE_USE_GA_IE ISO-8859-1   Irish language locale for Ireland
 * _LOCALE_USE_GL_ES ISO-8859-1   Galician language locale for Spain
 * _LOCALE_USE_HR_HR ISO-8859-2   Croatian language locale for Croatia
 * _LOCALE_USE_HU_HU ISO-8859-2   Hungarian language locale for Hungary
 * _LOCALE_USE_ID_ID ISO-8859-1   Indonesian language locale for Indonesia
 * _LOCALE_USE_IS_EU ISO-8859-15  Icelandic language locale for Europe
 * _LOCALE_USE_IS_IS ISO-8859-1   Icelandic language locale for Iceland
 * _LOCALE_USE_IT_EU ISO-8859-15  Italian language locale for Europe
 * _LOCALE_USE_IT_IT ISO-8859-1   Italian language locale for Italy
 * _LOCALE_USE_IW_IL ISO-8859-8   Hebrew language locale for Israel
 * _LOCALE_USE_KL_GL ISO-8859-1   Greenlandic language locale for Greenland
 * _LOCALE_USE_LT_LT   BALTIC     Lithuanian languagelocale for Lithuania
 * _LOCALE_USE_LV_LV   BALTIC     Latvian languagelocale for Latvia
 * _LOCALE_USE_NL_BE ISO-8859-1   Dutch language locale for Belgium
 * _LOCALE_USE_NL_EU ISO-8859-15  Dutch language locale for Europe
 * _LOCALE_USE_NL_NL ISO-8859-9   Dutch language locale for Netherlands
 * _LOCALE_USE_NO_EU ISO-8859-15  Norwegian language locale for Europe
 * _LOCALE_USE_NO_NO ISO-8859-1   Norwegian language locale for Norway
 * _LOCALE_USE_PL_PL ISO-8859-2   Polish language locale for Poland
 * _LOCALE_USE_PT_BR ISO-8859-1   Portugese language locale for Brazil
 * _LOCALE_USE_PT_EU ISO-8859-15  Portugese language locale for Europe
 * _LOCALE_USE_PT_PT ISO-8859-1   Portugese language locale for Portugal
 * _LOCALE_USE_RO_RO ISO-8859-2   Romanian language locale for Romania
 * _LOCALE_USE_RU_RU ISO-8859-5   Russian language locale for Russia
 * _LOCALE_USE_SL_SI ISO-8859-2   Slovenian language locale for Slovenia
 * _LOCALE_USE_SV_EU ISO-8859-15  Swedish language locale for Europe
 * _LOCALE_USE_SV_FI ISO-8859-1   Swedish language locale for Finland
 * _LOCALE_USE_SV_SE ISO-8859-1   Swedish language locale for Sweden
 * _LOCALE_USE_TR_TR ISO-8859-9   Turkish language locale for Turkey
 *
 *  Supported encodings
 *  -------------------
 * n/a                            Single byte (used if no other is defined).
 * _ENCODING_USE_UTF8             UTF8 encoding.
 */






/* We need to have the "C" locale if we have full locale support. */






/*
 * Support of multibytes in printf- and scanf-like functions
 *
 * This is the default value for _DLIB_PRINTF_MULTIBYTE and
 * _DLIB_SCANF_MULTIBYTE. See them for a description.
 *
 * Default is to not have support for multibytes in printf- and scanf-like
 * functions.
 */






/*
 * Throw handling in the EC++ library
 *
 * This setting determines what happens when the EC++ part of the library
 * fails (where a normal C++ library 'throws').
 *
 * The following alternatives exists (setting of the symbol):
 * 0                - The application does nothing, i.e. continues with the
 *                    next statement.
 * 1                - The application terminates by calling the 'abort'
 *                    function directly.
 * <anything else>  - An object of class "exception" is created.  This
 *                    object contains a string describing the problem.
 *                    This string is later emitted on "stderr" before
 *                    the application terminates by calling the 'abort'
 *                    function directly.
 *
 * Default is to do nothing.
 */






/*
 * Hexadecimal floating-point numbers in strtod
 *
 * If selected, i.e. set to 1, strtod supports C99 hexadecimal floating-point
 * numbers. This also enables hexadecimal floating-points in internal functions
 * used for converting strings and wide strings to float, double, and long
 * double.
 *
 * If not selected, i.e. set to 0, C99 hexadecimal floating-point numbers
 * aren't supported.
 *
 * Default is not to support hexadecimal floating-point numbers.
 */






/*
 * Printf configuration symbols.
 *
 * All the configuration symbols described further on controls the behaviour
 * of printf, sprintf, and the other printf variants.
 *
 * The library proves four formatters for printf: 'tiny', 'small',
 * 'large', and 'default'.  The setup in this file controls all except
 * 'tiny'.  Note that both small' and 'large' explicitly removes
 * some features.
 */

/*
 * Handle multibytes in printf
 *
 * This setting controls whether multibytes and wchar_ts are supported in
 * printf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * Long long formatting in printf
 *
 * This setting controls long long support (%lld) in printf. Set to 1 to
 * support it, otherwise set to 0.

 * Note, if long long should not be supported and 'intmax_t' is larger than
 * an ordinary 'long', then %jd and %jn will not be supported.
 *
 * Default is to support long long formatting.
 */

#line 351 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"






/*
 * Floating-point formatting in printf
 *
 * This setting controls whether printf supports floating-point formatting.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting.
 */





/*
 * Hexadecimal floating-point formatting in printf
 *
 * This setting controls whether the %a format, i.e. the output of
 * floating-point numbers in the C99 hexadecimal format. Set to 1 to support
 * it, otherwise set to 0.
 *
 * Default is to support %a in printf.
 */





/*
 * Output count formatting in printf
 *
 * This setting controls whether the output count specifier (%n) is supported
 * or not in printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support %n in printf.
 */





/*
 * Support of qualifiers in printf
 *
 * This setting controls whether qualifiers that enlarges the input value
 * [hlLjtz] is supported in printf or not. Set to 1 to support them, otherwise
 * set to 0. See also _DLIB_PRINTF_INT_TYPE_IS_INT and
 * _DLIB_PRINTF_INT_TYPE_IS_LONG.
 *
 * Default is to support [hlLjtz] qualifiers in printf.
 */





/*
 * Support of flags in printf
 *
 * This setting controls whether flags (-+ #0) is supported in printf or not.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support flags in printf.
 */





/*
 * Support widths and precisions in printf
 *
 * This setting controls whether widths and precisions are supported in printf.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support widths and precisions in printf.
 */





/*
 * Support of unsigned integer formatting in printf
 *
 * This setting controls whether unsigned integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in printf.
 */





/*
 * Support of signed integer formatting in printf
 *
 * This setting controls whether signed integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support signed integer formatting in printf.
 */





/*
 * Support of formatting anything larger than int in printf
 *
 * This setting controls if 'int' should be used internally in printf, rather
 * than the largest existing integer type. If 'int' is used, any integer or
 * pointer type formatting use 'int' as internal type even though the
 * formatted type is larger. Set to 1 to use 'int' as internal type, otherwise
 * set to 0.
 *
 * See also next configuration.
 *
 * Default is to internally use largest existing internally type.
 */





/*
 * Support of formatting anything larger than long in printf
 *
 * This setting controls if 'long' should be used internally in printf, rather
 * than the largest existing integer type. If 'long' is used, any integer or
 * pointer type formatting use 'long' as internal type even though the
 * formatted type is larger. Set to 1 to use 'long' as internal type,
 * otherwise set to 0.
 *
 * See also previous configuration.
 *
 * Default is to internally use largest existing internally type.
 */









/*
 * Emit a char a time in printf
 *
 * This setting controls internal output handling. If selected, i.e. set to 1,
 * then printf emits one character at a time, which requires less code but
 * can be slightly slower for some types of output.
 *
 * If not selected, i.e. set to 0, then printf buffers some outputs.
 *
 * Note that it is recommended to either use full file support (see
 * _DLIB_FILE_DESCRIPTOR) or -- for debug output -- use the linker
 * option "-e__write_buffered=__write" to enable buffered I/O rather
 * than deselecting this feature.
 */






/*
 * Scanf configuration symbols.
 *
 * All the configuration symbols described here controls the
 * behaviour of scanf, sscanf, and the other scanf variants.
 *
 * The library proves three formatters for scanf: 'small', 'large',
 * and 'default'.  The setup in this file controls all, however both
 * 'small' and 'large' explicitly removes some features.
 */

/*
 * Handle multibytes in scanf
 *
 * This setting controls whether multibytes and wchar_t:s are supported in
 * scanf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default.
 */





/*
 * Long long formatting in scanf
 *
 * This setting controls whether scanf supports long long support (%lld). It
 * also controls, if 'intmax_t' is larger than an ordinary 'long', i.e. how
 * the %jd and %jn specifiers behaves. Set to 1 to support them, otherwise set
 * to 0.
 *
 * Default is to support long long formatting in scanf.
 */

#line 566 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"





/*
 * Support widths in scanf
 *
 * This controls whether scanf supports widths. Set to 1 to support them,
 * otherwise set to 0.
 *
 * Default is to support widths in scanf.
 */





/*
 * Support qualifiers [hjltzL] in scanf
 *
 * This setting controls whether scanf supports qualifiers [hjltzL] or not. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support qualifiers in scanf.
 */





/*
 * Support floating-point formatting in scanf
 *
 * This setting controls whether scanf supports floating-point formatting. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting in scanf.
 */





/*
 * Support output count formatting (%n)
 *
 * This setting controls whether scanf supports output count formatting (%n).
 * Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support output count formatting in scanf.
 */





/*
 * Support scansets ([]) in scanf
 *
 * This setting controls whether scanf supports scansets ([]) or not. Set to 1
 * to support them, otherwise set to 0.
 *
 * Default is to support scansets in scanf.
 */





/*
 * Support signed integer formatting in scanf
 *
 * This setting controls whether scanf supports signed integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support signed integer formatting in scanf.
 */





/*
 * Support unsigned integer formatting in scanf
 *
 * This setting controls whether scanf supports unsigned integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in scanf.
 */





/*
 * Support assignment suppressing [*] in scanf
 *
 * This setting controls whether scanf supports assignment suppressing [*] or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support assignment suppressing in scanf.
 */





/*
 * Handle multibytes in asctime and strftime.
 *
 * This setting controls whether multibytes and wchar_ts are
 * supported.Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * True if "qsort" should be implemented using bubble sort.
 *
 * Bubble sort is less efficient than quick sort but requires less RAM
 * and ROM resources.
 */





/*
 * Set Buffert size used in qsort
 */





/*
 * The default "rand" function uses an array of 32 long:s of memory to
 * store the current state.
 *
 * The simple "rand" function uses only a single long. However, the
 * quality of the generated psuedo-random numbers are not as good as
 * the default implementation.
 */





/*
 * Wide character and multi byte character support in library.
 */





/*
 * Set attributes on the function used by the C-SPY debug interface to set a
 * breakpoint in.
 */





/*
 * Support threading in the library
 *
 * 0    No thread support
 * 1    Thread support with a, b, and d.
 * 2    Thread support with a, b, and e.
 * 3    Thread support with all thread-local storage in a dynamically allocated
 *        memory area and a, and b.
 *      a. Lock on heap accesses
 *      b. Optional lock on file accesses (see _DLIB_FILE_OP_LOCKS below)
 *      d. Use an external thread-local storage interface for all the
 *         libraries static and global variables.
 *      e. Static and global variables aren't safe for access from several
 *         threads.
 *
 * Note that if locks are used the following symbols must be defined:
 *
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *
 * They will be used to initialize the needed locks only once. TYPE is the
 * type for the static control variable, MACRO is the expression that will be
 * evaluated at each usage of a lock, and INIT is the initializer for the
 * control variable.
 *
 * Note that if thread model 3 is used the symbol _DLIB_TLS_POINTER must be
 * defined. It is a thread local pointer to a dynamic memory area that
 * contains all used TLS variables for the library. Optionally the following
 * symbols can be defined as well (default is to use the default const data
 * and data memories):
 *
 *   _DLIB_TLS_INITIALIZER_MEMORY The memory to place the initializers for the
 *                                TLS memory area
 *   _DLIB_TLS_MEMORY             The memory to use for the TLS memory area. A
 *                                pointer to this memory must be castable to a
 *                                default pointer and back.
 *   _DLIB_TLS_REQUIRE_INIT       Set to 1 to require __cstart_init_tls
 *                                when needed to initialize the TLS data
 *                                segment for the main thread.
 *   _DLIB_TLS_SEGMENT_DATA       The name of the TLS RAM data segment
 *   _DLIB_TLS_SEGMENT_INIT       The name of the used to initialize the
 *                                TLS data segment.
 *
 * See DLib_Threads.h for a description of what interfaces needs to be
 * defined for thread support.
 */





/*
 * Used by products where one runtime library can be used by applications
 * with different data models, in order to reduce the total number of
 * libraries required. Typically, this is used when the pointer types does
 * not change over the data models used, but the placement of data variables
 * or/and constant variables do.
 *
 * If defined, this symbol is typically defined to the memory attribute that
 * is used by the runtime library. The actual define must use a
 * _Pragma("type_attribute = xxx") construct. In the header files, it is used
 * on all statically linked data objects seen by the application.
 */




#line 812 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"


/*
 * Turn on support for the Target-specific ABI. The ABI is based on the
 * ARM AEABI. A target, except ARM, may deviate from it.
 */

#line 826 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"


  /* Possible AEABI deviations */
#line 836 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"

#line 844 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"
  /*
   * The "difunc" table contains information about C++ objects that
   * should be dynamically initialized, where each entry in the table
   * represents an initialization function that should be called. When
   * the symbol _DLIB_AEABI_DIFUNC_CONTAINS_OFFSETS is true, each
   * entry in the table is encoded as an offset from the entry
   * location. When false, the entries contain the actual addresses to
   * call.
   */






/*
 * Turn on usage of a pragma to tell the linker the number of elements used
 * in a setjmp jmp_buf.
 */





/*
 * If true, the product supplies a "DLib_Product_string.h" file that
 * is included from "string.h".
 */





/*
 * Determine whether the math fma routines are fast or not.
 */




/*
 * Rtti support.
 */

#line 899 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"

/*
 * Use the "pointers to short" or "pointers to long" implementation of 
 * the basic floating point routines (like Dnorm, Dtest, Dscale, and Dunscale).
 */




/*
 * Use 64-bit long long as intermediary type in Dtest, and fabs.
 * Default is to do this if long long is 64-bits.
 */




/*
 * Favor speed versus some size enlargements in floating point functions.
 */




/*
 * Include dlmalloc as an alternative heap manager in product.
 *
 * Typically, an application will use a "malloc" heap manager that is
 * relatively small but not that efficient. An application can
 * optionally use the "dlmalloc" package, which provides a more
 * effective "malloc" heap manager, if it is included in the product
 * and supported by the settings.
 *
 * See the product documentation on how to use it, and whether or not
 * it is included in the product.
 */

  /* size_t/ptrdiff_t must be a 4 bytes unsigned integer. */
#line 943 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"





/*
 * Allow the 64-bit time_t interface?
 *
 * Default is yes if long long is 64 bits.
 */

  #pragma language = save 
  #pragma language = extended





  #pragma language = restore






/*
 * Is time_t 64 or 32 bits?
 *
 * Default is 32 bits.
 */




/*
 * Do we include math functions that demands lots of constant bytes?
 * (like erf, erfc, expm1, fma, lgamma, tgamma, and *_accurate)
 *
 */




/*
 * Set this to __weak, if supported.
 *
 */
#line 997 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Defaults.h"


/*
 * Deleted options
 *
 */







#line 73 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"











                /* Floating-point */

/*
 * Whenever a floating-point type is equal to another, we try to fold those
 * two types into one. This means that if float == double then we fold float to
 * use double internally. Example sinf(float) will use _Sin(double, uint).
 *
 * _X_FNAME is a redirector for internal support routines. The X can be
 *          D (double), F (float), or L (long double). It redirects by using
 *          another prefix. Example calls to Dtest will be __iar_Dtest,
 *          __iar_FDtest, or __iarLDtest.
 * _X_FUN   is a redirector for functions visible to the customer. As above, the
 *          X can be D, F, or L. It redirects by using another suffix. Example
 *          calls to sin will be sin, sinf, or sinl.
 * _X_TYPE  The type that one type is folded to.
 * _X_PTRCAST is a redirector for a cast operation involving a pointer.
 * _X_CAST  is a redirector for a cast involving the float type.
 *
 * _FLOAT_IS_DOUBLE signals that all internal float routines aren't needed.
 * _LONG_DOUBLE_IS_DOUBLE signals that all internal long double routines
 *                        aren't needed.
 */
#line 147 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"





                /* NAMING PROPERTIES */


/* Has support for fixed point types */




/* Has support for secure functions (printf_s, scanf_s, etc) */
/* Will not compile if enabled */
#line 170 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

/* Has support for complex C types */




/* If is Embedded C++ language */






/* If is true C++ language */






/* True C++ language setup */
#line 233 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"











                /* NAMESPACE CONTROL */
#line 292 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"









#line 308 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"








#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\xencoding_limits.h"
/* xencoding_limits.h internal header file */
/* Copyright 2003-2010 IAR Systems AB.  */





  #pragma system_include


#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\ycheck.h"

#line 12 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\xencoding_limits.h"
#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */

#line 707 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 13 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\xencoding_limits.h"

                                /* Multibyte encoding length. */


#line 24 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\xencoding_limits.h"




#line 42 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\xencoding_limits.h"

                                /* Utility macro */














#line 317 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"



                /* FLOATING-POINT PROPERTIES */

                /* float properties */
#line 335 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* double properties */
#line 360 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* long double properties */
                /* (must be same as double) */




#line 382 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"


                /* INTEGER PROPERTIES */

                                /* MB_LEN_MAX */







  #pragma language=save
  #pragma language=extended
  typedef long long _Longlong;
  typedef unsigned long long _ULonglong;
  #pragma language=restore
#line 405 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"






  typedef unsigned short int _Wchart;
  typedef unsigned short int _Wintt;


#line 424 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

#line 432 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* POINTER PROPERTIES */


typedef signed int  _Ptrdifft;
typedef unsigned int     _Sizet;

/* IAR doesn't support restrict  */


                /* stdarg PROPERTIES */
#line 454 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"
  typedef _VA_LIST __Va_list;



__intrinsic __nounwind void __iar_Atexit(void (*)(void));



  typedef struct
  {       /* state of a multibyte translation */
    unsigned int _Wchar;
    unsigned int _State;
  } _Mbstatet;
#line 477 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"










typedef struct
{       /* file position */

  _Longlong _Off;    /* can be system dependent */



  _Mbstatet _Wstate;
} _Fpost;







                /* THREAD AND LOCALE CONTROL */

#line 1 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Threads.h"
/***************************************************
 *
 * DLib_Threads.h is the library threads manager.
 *
 * Copyright 2004-2010 IAR Systems AB.  
 *
 * This configuration header file sets up how the thread support in the library
 * should work.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/





  #pragma system_include


/*
 * DLib can support a multithreaded environment. The preprocessor symbol 
 * _DLIB_THREAD_SUPPORT governs the support. It can be 0 (no support), 
 * 1 (currently not supported), 2 (locks only), and 3 (simulated TLS and locks).
 */

/*
 * This header sets the following symbols that governs the rest of the
 * library:
 * ------------------------------------------
 * _DLIB_MULTI_THREAD     0 No thread support
 *                        1 Multithread support
 * _DLIB_GLOBAL_VARIABLES 0 Use external TLS interface for the libraries global
 *                          and static variables
 *                        1 Use a lock for accesses to the locale and no 
 *                          security for accesses to other global and static
 *                          variables in the library
 * _DLIB_FILE_OP_LOCKS    0 No file-atomic locks
 *                        1 File-atomic locks

 * _DLIB_COMPILER_TLS     0 No Thread-Local-Storage support in the compiler
 *                        1 Thread-Local-Storage support in the compiler
 * _DLIB_TLS_QUAL         The TLS qualifier, define only if _COMPILER_TLS == 1
 *
 * _DLIB_THREAD_MACRO_SETUP_DONE Whether to use the standard definitions of
 *                               TLS macros defined in xtls.h or the definitions
 *                               are provided here.
 *                        0 Use default macros
 *                        1 Macros defined for xtls.h
 *
 * _DLIB_THREAD_LOCK_ONCE_TYPE
 *                        type for control variable in once-initialization of 
 *                        locks
 * _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *                        expression that will be evaluated at each lock access
 *                        to determine if an initialization must be done
 * _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *                        initial value for the control variable
 *
 ****************************************************************************
 * Description
 * -----------
 *
 * If locks are to be used (_DLIB_MULTI_THREAD != 0), the following options
 * has to be used in ilink: 
 *   --redirect __iar_Locksyslock=__iar_Locksyslock_mtx
 *   --redirect __iar_Unlocksyslock=__iar_Unlocksyslock_mtx
 *   --redirect __iar_Lockfilelock=__iar_Lockfilelock_mtx
 *   --redirect __iar_Unlockfilelock=__iar_Unlockfilelock_mtx
 *   --keep     __iar_Locksyslock_mtx
 * and, if C++ is used, also:
 *   --redirect __iar_Initdynamicfilelock=__iar_Initdynamicfilelock_mtx
 *   --redirect __iar_Dstdynamicfilelock=__iar_Dstdynamicfilelock_mtx
 *   --redirect __iar_Lockdynamicfilelock=__iar_Lockdynamicfilelock_mtx
 *   --redirect __iar_Unlockdynamicfilelock=__iar_Unlockdynamicfilelock_mtx
 * Xlink uses similar options (-e and -g). The following lock interface must
 * also be implemented: 
 *   typedef void *__iar_Rmtx;                   // Lock info object
 *
 *   void __iar_system_Mtxinit(__iar_Rmtx *);    // Initialize a system lock
 *   void __iar_system_Mtxdst(__iar_Rmtx *);     // Destroy a system lock
 *   void __iar_system_Mtxlock(__iar_Rmtx *);    // Lock a system lock
 *   void __iar_system_Mtxunlock(__iar_Rmtx *);  // Unlock a system lock
 * The interface handles locks for the heap, the locale, the file system
 * structure, the initialization of statics in functions, etc. 
 *
 * The following lock interface is optional to be implemented:
 *   void __iar_file_Mtxinit(__iar_Rmtx *);    // Initialize a file lock
 *   void __iar_file_Mtxdst(__iar_Rmtx *);     // Destroy a file lock
 *   void __iar_file_Mtxlock(__iar_Rmtx *);    // Lock a file lock
 *   void __iar_file_Mtxunlock(__iar_Rmtx *);  // Unlock a file lock
 * The interface handles locks for each file stream.
 * 
 * These three once-initialization symbols must also be defined, if the 
 * default initialization later on in this file doesn't work (done in 
 * DLib_product.h):
 *
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *
 * If an external TLS interface is used, the following must
 * be defined:
 *   typedef int __iar_Tlskey_t;
 *   typedef void (*__iar_Tlsdtor_t)(void *);
 *   int __iar_Tlsalloc(__iar_Tlskey_t *, __iar_Tlsdtor_t); 
 *                                                    // Allocate a TLS element
 *   int __iar_Tlsfree(__iar_Tlskey_t);               // Free a TLS element
 *   int __iar_Tlsset(__iar_Tlskey_t, void *);        // Set a TLS element
 *   void *__iar_Tlsget(__iar_Tlskey_t);              // Get a TLS element
 *
 */

/* We don't have a compiler that supports tls declarations */



#line 157 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Threads.h"

  /* Thread support, library supports threaded variables in a user specified
     memory area, locks on heap and on FILE */

  /* See Documentation/ThreadsInternal.html for a description. */





  


#line 176 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Threads.h"





#line 187 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Threads.h"





  #pragma language=save 
  #pragma language=extended
  __intrinsic __nounwind void __iar_dlib_perthread_initialize(void  *);
  __intrinsic __nounwind void  *__iar_dlib_perthread_allocate(void);
  __intrinsic __nounwind void __iar_dlib_perthread_destroy(void);
  __intrinsic __nounwind void __iar_dlib_perthread_deallocate(void  *);









  #pragma segment = "__DLIB_PERTHREAD" 
  #pragma segment = "__DLIB_PERTHREAD_init" 


























#line 242 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Threads.h"

  /* The thread-local variable access function */
  void  *__iar_dlib_perthread_access(void  *);
  #pragma language=restore



























    /* Make sure that each destructor is inserted into _Deallocate_TLS */
  









  /* Internal function declarations. */






  





  
  typedef void *__iar_Rmtx;
  

  
  __intrinsic __nounwind void __iar_system_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxunlock(__iar_Rmtx *m);

  __intrinsic __nounwind void __iar_file_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxunlock(__iar_Rmtx *m);

  /* Function to destroy the locks. Should be called after atexit and 
     _Close_all. */
  __intrinsic __nounwind void __iar_clearlocks(void);


#line 323 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Threads.h"

  





  

#line 341 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\DLib_Threads.h"

  typedef unsigned _Once_t;



  













#line 506 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

#line 516 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* THREAD-LOCAL STORAGE */
#line 524 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"


                /* MULTITHREAD PROPERTIES */

  
  
  /* The lock interface for DLib to use. */ 
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock(unsigned int);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock(unsigned int);

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamicfilelock(__iar_Rmtx *);
  
  
#line 564 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* LOCK MACROS */
#line 572 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

#line 690 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"

                /* MISCELLANEOUS MACROS AND FUNCTIONS*/





#line 705 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\yvals.h"



/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 12 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\stdint.h"


/* Fixed size types. These are all optional. */

  typedef signed char   int8_t;
  typedef unsigned char uint8_t;



  typedef signed short int   int16_t;
  typedef unsigned short int uint16_t;



  typedef signed int   int32_t;
  typedef unsigned int uint32_t;



  #pragma language=save
  #pragma language=extended
  typedef signed long long int   int64_t;
  typedef unsigned long long int uint64_t;
  #pragma language=restore


/* Types capable of holding at least a certain number of bits.
   These are not optional for the sizes 8, 16, 32, 64. */
typedef signed char   int_least8_t;
typedef unsigned char uint_least8_t;

typedef signed short int   int_least16_t;
typedef unsigned short int uint_least16_t;

typedef signed int   int_least32_t;
typedef unsigned int uint_least32_t;

/* This isn't really optional, but make it so for now. */

  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_least64_t;
  #pragma language=restore


  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_least64_t;
  #pragma language=restore


/* The fastest type holding at least a certain number of bits.
   These are not optional for the size 8, 16, 32, 64.
   For now, the 64 bit size is optional in IAR compilers. */
typedef signed int   int_fast8_t;
typedef unsigned int uint_fast8_t;

typedef signed int   int_fast16_t;
typedef unsigned int uint_fast16_t;

typedef signed int   int_fast32_t;
typedef unsigned int uint_fast32_t;


  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_fast64_t;
  #pragma language=restore


  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_fast64_t;
  #pragma language=restore


/* The integer type capable of holding the largest number of bits. */
#pragma language=save
#pragma language=extended
typedef signed long long int   intmax_t;
typedef unsigned long long int uintmax_t;
#pragma language=restore

/* An integer type large enough to be able to hold a pointer.
   This is optional, but always supported in IAR compilers. */
typedef signed long int   intptr_t;
typedef unsigned long int uintptr_t;

/* An integer capable of holding a pointer to a specific memory type. */



typedef int __data_intptr_t; typedef unsigned int __data_uintptr_t;


/* Minimum and maximum limits. */






























































































/* Macros expanding to integer constants. */

































#line 258 "C:\\Program Files\\IAR Systems\\Embedded Workbench 7.0\\arm\\inc\\c\\stdint.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 52 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/** Memory map version 1.0 */


/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
typedef enum {
  INT_Initial_Stack_Pointer    = 0,                /**< Initial stack pointer */
  INT_Initial_Program_Counter  = 1,                /**< Initial program counter */
  INT_NMI                      = 2,                /**< Non-maskable interrupt */
  INT_Hard_Fault               = 3,                /**< Hard fault exception */
  INT_Mem_Manage_Fault         = 4,                /**< Memory Manage Fault */
  INT_Bus_Fault                = 5,                /**< Bus fault exception */
  INT_Usage_Fault              = 6,                /**< Usage fault exception */
  INT_Reserved7                = 7,                /**< Reserved interrupt 7 */
  INT_Reserved8                = 8,                /**< Reserved interrupt 8 */
  INT_Reserved9                = 9,                /**< Reserved interrupt 9 */
  INT_Reserved10               = 10,               /**< Reserved interrupt 10 */
  INT_SVCall                   = 11,               /**< A supervisor call exception */
  INT_DebugMonitor             = 12,               /**< Debug Monitor */
  INT_Reserved13               = 13,               /**< Reserved interrupt 13 */
  INT_PendableSrvReq           = 14,               /**< PendSV exception - request for system level service */
  INT_SysTick                  = 15,               /**< SysTick interrupt */
  INT_DMA0_DMA16               = 16,               /**< DMA channel 0/16 transfer complete interrupt */
  INT_DMA1_DMA17               = 17,               /**< DMA channel 1/17 transfer complete interrupt */
  INT_DMA2_DMA18               = 18,               /**< DMA channel 2/18 transfer complete interrupt */
  INT_DMA3_DMA19               = 19,               /**< DMA channel 3/19 transfer complete interrupt */
  INT_DMA4_DMA20               = 20,               /**< DMA channel 4/20 transfer complete interrupt */
  INT_DMA5_DMA21               = 21,               /**< DMA channel 5/21 transfer complete interrupt */
  INT_DMA6_DMA22               = 22,               /**< DMA channel 6/22 transfer complete interrupt */
  INT_DMA7_DMA23               = 23,               /**< DMA channel 7/23 transfer complete interrupt */
  INT_DMA8_DMA24               = 24,               /**< DMA channel 8/24 transfer complete interrupt */
  INT_DMA9_DMA25               = 25,               /**< DMA channel 9/25 transfer complete interrupt */
  INT_DMA10_DMA26              = 26,               /**< DMA channel 10/26 transfer complete interrupt */
  INT_DMA11_DMA27              = 27,               /**< DMA channel 11/27 transfer complete interrupt */
  INT_DMA12_DMA28              = 28,               /**< DMA channel 12/28 transfer complete interrupt */
  INT_DMA13_DMA29              = 29,               /**< DMA channel 13/29 transfer complete interrupt */
  INT_DMA14_DMA30              = 30,               /**< DMA channel 14/30 transfer complete interrupt */
  INT_DMA15_DMA31              = 31,               /**< DMA channel 15/31 transfer complete interrupt */
  INT_DMA_Error                = 32,               /**< DMA error interrupt */
  INT_MCM                      = 33,               /**< Normal interrupt */
  INT_FTFE                     = 34,               /**< FTFE interrupt */
  INT_Read_Collision           = 35,               /**< Read collision interrupt */
  INT_LVD_LVW                  = 36,               /**< Low Voltage Detect, Low Voltage Warning */
  INT_LLW                      = 37,               /**< Low Leakage Wakeup */
  INT_Watchdog                 = 38,               /**< WDOG interrupt */
  INT_RNG                      = 39,               /**< RNGA interrupt */
  INT_I2C0                     = 40,               /**< I2C0 interrupt */
  INT_I2C1                     = 41,               /**< I2C1 interrupt */
  INT_SPI0                     = 42,               /**< SPI0 interrupt */
  INT_SPI1                     = 43,               /**< SPI1 interrupt */
  INT_SPI2                     = 44,               /**< SPI2 interrupt */
  INT_CAN0_ORed_Message_buffer = 45,               /**< CAN0 OR'd message buffers interrupt */
  INT_CAN0_Bus_Off             = 46,               /**< CAN0 bus off interrupt */
  INT_CAN0_Error               = 47,               /**< CAN0 error interrupt */
  INT_CAN0_Tx_Warning          = 48,               /**< CAN0 Tx warning interrupt */
  INT_CAN0_Rx_Warning          = 49,               /**< CAN0 Rx warning interrupt */
  INT_CAN0_Wake_Up             = 50,               /**< CAN0 wake up interrupt */
  INT_I2S0_Tx                  = 51,               /**< I2S0 transmit interrupt */
  INT_I2S0_Rx                  = 52,               /**< I2S0 receive interrupt */
  INT_CAN1_ORed_Message_buffer = 53,               /**< CAN1 OR'd message buffers interrupt */
  INT_CAN1_Bus_Off             = 54,               /**< CAN1 bus off interrupt */
  INT_CAN1_Error               = 55,               /**< CAN1 error interrupt */
  INT_CAN1_Tx_Warning          = 56,               /**< CAN1 Tx warning interrupt */
  INT_CAN1_Rx_Warning          = 57,               /**< CAN1 Rx warning interrupt */
  INT_CAN1_Wake_Up             = 58,               /**< CAN1 wake up interrupt */
  INT_Reserved59               = 59,               /**< Reserved interrupt 59 */
  INT_UART0_LON                = 60,               /**< UART0 LON interrupt */
  INT_UART0_RX_TX              = 61,               /**< UART0 receive/transmit interrupt */
  INT_UART0_ERR                = 62,               /**< UART0 error interrupt */
  INT_UART1_RX_TX              = 63,               /**< UART1 receive/transmit interrupt */
  INT_UART1_ERR                = 64,               /**< UART1 error interrupt */
  INT_UART2_RX_TX              = 65,               /**< UART2 receive/transmit interrupt */
  INT_UART2_ERR                = 66,               /**< UART2 error interrupt */
  INT_UART3_RX_TX              = 67,               /**< UART3 receive/transmit interrupt */
  INT_UART3_ERR                = 68,               /**< UART3 error interrupt */
  INT_UART4_RX_TX              = 69,               /**< UART4 receive/transmit interrupt */
  INT_UART4_ERR                = 70,               /**< UART4 error interrupt */
  INT_UART5_RX_TX              = 71,               /**< UART5 receive/transmit interrupt */
  INT_UART5_ERR                = 72,               /**< UART5 error interrupt */
  INT_ADC0                     = 73,               /**< ADC0 interrupt */
  INT_ADC1                     = 74,               /**< ADC1 interrupt */
  INT_CMP0                     = 75,               /**< CMP0 interrupt */
  INT_CMP1                     = 76,               /**< CMP1 interrupt */
  INT_CMP2                     = 77,               /**< CMP2 interrupt */
  INT_FTM0                     = 78,               /**< FTM0 fault, overflow and channels interrupt */
  INT_FTM1                     = 79,               /**< FTM1 fault, overflow and channels interrupt */
  INT_FTM2                     = 80,               /**< FTM2 fault, overflow and channels interrupt */
  INT_CMT                      = 81,               /**< CMT interrupt */
  INT_RTC                      = 82,               /**< RTC interrupt */
  INT_RTC_Seconds              = 83,               /**< RTC seconds interrupt */
  INT_PIT0                     = 84,               /**< PIT timer channel 0 interrupt */
  INT_PIT1                     = 85,               /**< PIT timer channel 1 interrupt */
  INT_PIT2                     = 86,               /**< PIT timer channel 2 interrupt */
  INT_PIT3                     = 87,               /**< PIT timer channel 3 interrupt */
  INT_PDB0                     = 88,               /**< PDB0 interrupt */
  INT_USB0                     = 89,               /**< USB0 interrupt */
  INT_USBDCD                   = 90,               /**< USBDCD interrupt */
  INT_ENET_1588_Timer          = 91,               /**< Ethernet MAC IEEE 1588 timer interrupt */
  INT_ENET_Transmit            = 92,               /**< Ethernet MAC transmit interrupt */
  INT_ENET_Receive             = 93,               /**< Ethernet MAC receive interrupt */
  INT_ENET_Error               = 94,               /**< Ethernet MAC error and miscelaneous interrupt */
  INT_Reserved95               = 95,               /**< Reserved interrupt 95 */
  INT_SDHC                     = 96,               /**< SDHC interrupt */
  INT_DAC0                     = 97,               /**< DAC0 interrupt */
  INT_DAC1                     = 98,               /**< DAC1 interrupt */
  INT_TSI0                     = 99,               /**< TSI0 interrupt */
  INT_MCG                      = 100,              /**< MCG interrupt */
  INT_LPTimer                  = 101,              /**< LPTimer interrupt */
  INT_Reserved102              = 102,              /**< Reserved interrupt 102 */
  INT_PORTA                    = 103,              /**< Port A interrupt */
  INT_PORTB                    = 104,              /**< Port B interrupt */
  INT_PORTC                    = 105,              /**< Port C interrupt */
  INT_PORTD                    = 106,              /**< Port D interrupt */
  INT_PORTE                    = 107,              /**< Port E interrupt */
  INT_PORTF                    = 108,              /**< Port F interrupt */
  INT_DDR                      = 109,              /**< DDR interrupt */
  INT_SWI                      = 110,              /**< Software interrupt */
  INT_NFC                      = 111,              /**< NAND flash controller interrupt */
  INT_USBHS                    = 112,              /**< USB high speed OTG interrupt */
  INT_LCD                      = 113,              /**< Graphical LCD interrupt */
  INT_CMP3                     = 114,              /**< CMP3 interrupt */
  INT_Tamper                   = 115,              /**< Tamper detect interrupt */
  INT_Reserved116              = 116,              /**< Reserved interrupt 116 */
  INT_FTM3                     = 117,              /**< FTM3 fault, overflow and channels interrupt */
  INT_ADC2                     = 118,              /**< ADC2 interrupt */
  INT_ADC3                     = 119,              /**< ADC3 interrupt */
  INT_I2S1_Tx                  = 120,              /**< I2S1 transmit interrupt */
  INT_I2S1_Rx                  = 121               /**< I2S1 receive interrupt */
} IRQInterruptIndex;

/**
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Peripheral type defines
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup Peripheral_defines Peripheral type defines
 * @{
 */


/*
** Start of section using anonymous unions
*/

#line 225 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
  #pragma language=extended




/* ----------------------------------------------------------------------------
   -- ADC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_Peripheral ADC
 * @{
 */

/** ADC - Peripheral register structure */
typedef struct ADC_MemMap {
  uint32_t SC1[2];                                 /**< ADC status and control registers 1, array offset: 0x0, array step: 0x4 */
  uint32_t CFG1;                                   /**< ADC configuration register 1, offset: 0x8 */
  uint32_t CFG2;                                   /**< Configuration register 2, offset: 0xC */
  uint32_t R[2];                                   /**< ADC data result register, array offset: 0x10, array step: 0x4 */
  uint32_t CV1;                                    /**< Compare value registers, offset: 0x18 */
  uint32_t CV2;                                    /**< Compare value registers, offset: 0x1C */
  uint32_t SC2;                                    /**< Status and control register 2, offset: 0x20 */
  uint32_t SC3;                                    /**< Status and control register 3, offset: 0x24 */
  uint32_t OFS;                                    /**< ADC offset correction register, offset: 0x28 */
  uint32_t PG;                                     /**< ADC plus-side gain register, offset: 0x2C */
  uint32_t MG;                                     /**< ADC minus-side gain register, offset: 0x30 */
  uint32_t CLPD;                                   /**< ADC plus-side general calibration value register, offset: 0x34 */
  uint32_t CLPS;                                   /**< ADC plus-side general calibration value register, offset: 0x38 */
  uint32_t CLP4;                                   /**< ADC plus-side general calibration value register, offset: 0x3C */
  uint32_t CLP3;                                   /**< ADC plus-side general calibration value register, offset: 0x40 */
  uint32_t CLP2;                                   /**< ADC plus-side general calibration value register, offset: 0x44 */
  uint32_t CLP1;                                   /**< ADC plus-side general calibration value register, offset: 0x48 */
  uint32_t CLP0;                                   /**< ADC plus-side general calibration value register, offset: 0x4C */
  uint32_t PGA;                                    /**< ADC PGA register, offset: 0x50 */
  uint32_t CLMD;                                   /**< ADC minus-side general calibration value register, offset: 0x54 */
  uint32_t CLMS;                                   /**< ADC minus-side general calibration value register, offset: 0x58 */
  uint32_t CLM4;                                   /**< ADC minus-side general calibration value register, offset: 0x5C */
  uint32_t CLM3;                                   /**< ADC minus-side general calibration value register, offset: 0x60 */
  uint32_t CLM2;                                   /**< ADC minus-side general calibration value register, offset: 0x64 */
  uint32_t CLM1;                                   /**< ADC minus-side general calibration value register, offset: 0x68 */
  uint32_t CLM0;                                   /**< ADC minus-side general calibration value register, offset: 0x6C */
} volatile *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register accessors */
#line 306 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/* SC1 Bit Fields */
#line 331 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CFG1 Bit Fields */
#line 345 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CFG2 Bit Fields */
#line 355 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* R Bit Fields */



/* CV1 Bit Fields */



/* CV2 Bit Fields */



/* SC2 Bit Fields */
#line 383 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SC3 Bit Fields */
#line 395 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OFS Bit Fields */



/* PG Bit Fields */



/* MG Bit Fields */



/* CLPD Bit Fields */



/* CLPS Bit Fields */



/* CLP4 Bit Fields */



/* CLP3 Bit Fields */



/* CLP2 Bit Fields */



/* CLP1 Bit Fields */



/* CLP0 Bit Fields */



/* PGA Bit Fields */
#line 447 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CLMD Bit Fields */



/* CLMS Bit Fields */



/* CLM4 Bit Fields */



/* CLM3 Bit Fields */



/* CLM2 Bit Fields */



/* CLM1 Bit Fields */



/* CLM0 Bit Fields */




/**
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base pointer */

/** Peripheral ADC1 base pointer */

/** Peripheral ADC2 base pointer */

/** Peripheral ADC3 base pointer */


/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register instance definitions */
/* ADC0 */
#line 531 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ADC1 */
#line 560 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ADC2 */
#line 589 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ADC3 */
#line 618 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* ADC - Register array accessors */
#line 628 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ADC_Peripheral */


/* ----------------------------------------------------------------------------
   -- AIPS
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Peripheral AIPS
 * @{
 */

/** AIPS - Peripheral register structure */
typedef struct AIPS_MemMap {
  uint32_t MPRA;                                   /**< Master Privilege Register A, offset: 0x0 */
  uint8_t RESERVED_0[28];
  uint32_t PACRA;                                  /**< Peripheral Access Control Register, offset: 0x20 */
  uint32_t PACRB;                                  /**< Peripheral Access Control Register, offset: 0x24 */
  uint32_t PACRC;                                  /**< Peripheral Access Control Register, offset: 0x28 */
  uint32_t PACRD;                                  /**< Peripheral Access Control Register, offset: 0x2C */
  uint8_t RESERVED_1[16];
  uint32_t PACRE;                                  /**< Peripheral Access Control Register, offset: 0x40 */
  uint32_t PACRF;                                  /**< Peripheral Access Control Register, offset: 0x44 */
  uint32_t PACRG;                                  /**< Peripheral Access Control Register, offset: 0x48 */
  uint32_t PACRH;                                  /**< Peripheral Access Control Register, offset: 0x4C */
  uint32_t PACRI;                                  /**< Peripheral Access Control Register, offset: 0x50 */
  uint32_t PACRJ;                                  /**< Peripheral Access Control Register, offset: 0x54 */
  uint32_t PACRK;                                  /**< Peripheral Access Control Register, offset: 0x58 */
  uint32_t PACRL;                                  /**< Peripheral Access Control Register, offset: 0x5C */
  uint32_t PACRM;                                  /**< Peripheral Access Control Register, offset: 0x60 */
  uint32_t PACRN;                                  /**< Peripheral Access Control Register, offset: 0x64 */
  uint32_t PACRO;                                  /**< Peripheral Access Control Register, offset: 0x68 */
  uint32_t PACRP;                                  /**< Peripheral Access Control Register, offset: 0x6C */
} volatile *AIPS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- AIPS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Register_Accessor_Macros AIPS - Register accessor macros
 * @{
 */


/* AIPS - Register accessors */
#line 699 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group AIPS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- AIPS Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Register_Masks AIPS Register Masks
 * @{
 */

/* MPRA Bit Fields */
#line 763 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRA Bit Fields */
#line 812 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRB Bit Fields */
#line 861 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRC Bit Fields */
#line 910 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRD Bit Fields */
#line 959 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRE Bit Fields */
#line 1008 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRF Bit Fields */
#line 1057 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRG Bit Fields */
#line 1106 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRH Bit Fields */
#line 1155 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRI Bit Fields */
#line 1204 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRJ Bit Fields */
#line 1253 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRK Bit Fields */
#line 1302 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRL Bit Fields */
#line 1351 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRM Bit Fields */
#line 1400 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRN Bit Fields */
#line 1449 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRO Bit Fields */
#line 1498 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PACRP Bit Fields */
#line 1547 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group AIPS_Register_Masks */


/* AIPS - Peripheral instance base addresses */
/** Peripheral AIPS0 base pointer */

/** Peripheral AIPS1 base pointer */


/* ----------------------------------------------------------------------------
   -- AIPS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Register_Accessor_Macros AIPS - Register accessor macros
 * @{
 */


/* AIPS - Register instance definitions */
/* AIPS0 */
#line 1588 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* AIPS1 */
#line 1606 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group AIPS_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group AIPS_Peripheral */


/* ----------------------------------------------------------------------------
   -- AXBS
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Peripheral AXBS
 * @{
 */

/** AXBS - Peripheral register structure */
typedef struct AXBS_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    uint32_t PRS;                                    /**< Priority Registers Slave, array offset: 0x0, array step: 0x100 */
    uint8_t RESERVED_0[12];
    uint32_t CRS;                                    /**< Control Register, array offset: 0x10, array step: 0x100 */
    uint8_t RESERVED_1[236];
  } SLAVE[6];
  uint8_t RESERVED_0[512];
  uint32_t MGPCR0;                                 /**< Master General Purpose Control Register, offset: 0x800 */
  uint8_t RESERVED_1[252];
  uint32_t MGPCR1;                                 /**< Master General Purpose Control Register, offset: 0x900 */
  uint8_t RESERVED_2[252];
  uint32_t MGPCR2;                                 /**< Master General Purpose Control Register, offset: 0xA00 */
  uint8_t RESERVED_3[252];
  uint32_t MGPCR3;                                 /**< Master General Purpose Control Register, offset: 0xB00 */
  uint8_t RESERVED_4[252];
  uint32_t MGPCR4;                                 /**< Master General Purpose Control Register, offset: 0xC00 */
  uint8_t RESERVED_5[252];
  uint32_t MGPCR5;                                 /**< Master General Purpose Control Register, offset: 0xD00 */
  uint8_t RESERVED_6[252];
  uint32_t MGPCR6;                                 /**< Master General Purpose Control Register, offset: 0xE00 */
  uint8_t RESERVED_7[252];
  uint32_t MGPCR7;                                 /**< Master General Purpose Control Register, offset: 0xF00 */
} volatile *AXBS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- AXBS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Register_Accessor_Macros AXBS - Register accessor macros
 * @{
 */


/* AXBS - Register accessors */
#line 1673 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group AXBS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Register_Masks AXBS Register Masks
 * @{
 */

/* PRS Bit Fields */
#line 1713 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CRS Bit Fields */
#line 1727 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MGPCR0 Bit Fields */



/* MGPCR1 Bit Fields */



/* MGPCR2 Bit Fields */



/* MGPCR3 Bit Fields */



/* MGPCR4 Bit Fields */



/* MGPCR5 Bit Fields */



/* MGPCR6 Bit Fields */



/* MGPCR7 Bit Fields */




/**
 * @}
 */ /* end of group AXBS_Register_Masks */


/* AXBS - Peripheral instance base addresses */
/** Peripheral AXBS base pointer */


/* ----------------------------------------------------------------------------
   -- AXBS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Register_Accessor_Macros AXBS - Register accessor macros
 * @{
 */


/* AXBS - Register instance definitions */
/* AXBS */
#line 1801 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* AXBS - Register array accessors */



/**
 * @}
 */ /* end of group AXBS_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group AXBS_Peripheral */


/* ----------------------------------------------------------------------------
   -- CAN
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Peripheral CAN
 * @{
 */

/** CAN - Peripheral register structure */
typedef struct CAN_MemMap {
  uint32_t MCR;                                    /**< Module Configuration Register, offset: 0x0 */
  uint32_t CTRL1;                                  /**< Control 1 Register, offset: 0x4 */
  uint32_t TIMER;                                  /**< Free Running Timer, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t RXMGMASK;                               /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  uint32_t RX14MASK;                               /**< Rx 14 Mask Register, offset: 0x14 */
  uint32_t RX15MASK;                               /**< Rx 15 Mask Register, offset: 0x18 */
  uint32_t ECR;                                    /**< Error Counter, offset: 0x1C */
  uint32_t ESR1;                                   /**< Error and Status 1 Register, offset: 0x20 */
  uint32_t IMASK2;                                 /**< Interrupt Masks 2 Register, offset: 0x24 */
  uint32_t IMASK1;                                 /**< Interrupt Masks 1 Register, offset: 0x28 */
  uint32_t IFLAG2;                                 /**< Interrupt Flags 2 Register, offset: 0x2C */
  uint32_t IFLAG1;                                 /**< Interrupt Flags 1 Register, offset: 0x30 */
  uint32_t CTRL2;                                  /**< Control 2 Register, offset: 0x34 */
  uint32_t ESR2;                                   /**< Error and Status 2 Register, offset: 0x38 */
  uint8_t RESERVED_1[8];
  uint32_t CRCR;                                   /**< CRC Register, offset: 0x44 */
  uint32_t RXFGMASK;                               /**< Rx FIFO Global Mask Register, offset: 0x48 */
  uint32_t RXFIR;                                  /**< Rx FIFO Information Register, offset: 0x4C */
  uint8_t RESERVED_2[48];
  struct {                                         /* offset: 0x80, array step: 0x10 */
    uint32_t CS;                                     /**< Message Buffer 0 CS Register..Message Buffer 15 CS Register, array offset: 0x80, array step: 0x10 */
    uint32_t ID;                                     /**< Message Buffer 0 ID Register..Message Buffer 15 ID Register, array offset: 0x84, array step: 0x10 */
    uint32_t WORD0;                                  /**< Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register, array offset: 0x88, array step: 0x10 */
    uint32_t WORD1;                                  /**< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x8C, array step: 0x10 */
  } MB[16];
  uint8_t RESERVED_3[1792];
  uint32_t RXIMR[16];                              /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
} volatile *CAN_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register accessors */
#line 1890 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/* MCR Bit Fields */
#line 1946 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CTRL1 Bit Fields */
#line 1984 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TIMER Bit Fields */



/* RXMGMASK Bit Fields */



/* RX14MASK Bit Fields */



/* RX15MASK Bit Fields */



/* ECR Bit Fields */
#line 2007 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ESR1 Bit Fields */
#line 2045 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IMASK2 Bit Fields */



/* IMASK1 Bit Fields */



/* IFLAG2 Bit Fields */



/* IFLAG1 Bit Fields */
#line 2070 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CTRL2 Bit Fields */
#line 2085 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ESR2 Bit Fields */
#line 2093 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CRCR Bit Fields */
#line 2100 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RXFGMASK Bit Fields */



/* RXFIR Bit Fields */



/* CS Bit Fields */
#line 2124 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ID Bit Fields */
#line 2134 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WORD0 Bit Fields */
#line 2147 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WORD1 Bit Fields */
#line 2160 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RXIMR Bit Fields */




/**
 * @}
 */ /* end of group CAN_Register_Masks */


/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base pointer */

/** Peripheral CAN1 base pointer */


/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register instance definitions */
/* CAN0 */
#line 2285 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CAN1 */
#line 2383 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* CAN - Register array accessors */
#line 2395 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CAN_Peripheral */


/* ----------------------------------------------------------------------------
   -- CAU
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAU_Peripheral CAU
 * @{
 */

/** CAU - Peripheral register structure */
typedef struct CAU_MemMap {
  uint32_t DIRECT[16];                             /**< Direct access register 0..Direct access register 15, array offset: 0x0, array step: 0x4 */
  uint8_t RESERVED_0[2048];
  uint32_t LDR_CASR;                               /**< Status register  - Load Register command, offset: 0x840 */
  uint32_t LDR_CAA;                                /**< Accumulator register - Load Register command, offset: 0x844 */
  uint32_t LDR_CA[9];                              /**< General Purpose Register 0 - Load Register command..General Purpose Register 8 - Load Register command, array offset: 0x848, array step: 0x4 */
  uint8_t RESERVED_1[20];
  uint32_t STR_CASR;                               /**< Status register  - Store Register command, offset: 0x880 */
  uint32_t STR_CAA;                                /**< Accumulator register - Store Register command, offset: 0x884 */
  uint32_t STR_CA[9];                              /**< General Purpose Register 0 - Store Register command..General Purpose Register 8 - Store Register command, array offset: 0x888, array step: 0x4 */
  uint8_t RESERVED_2[20];
  uint32_t ADR_CASR;                               /**< Status register  - Add Register command, offset: 0x8C0 */
  uint32_t ADR_CAA;                                /**< Accumulator register - Add to register command, offset: 0x8C4 */
  uint32_t ADR_CA[9];                              /**< General Purpose Register 0 - Add to register command..General Purpose Register 8 - Add to register command, array offset: 0x8C8, array step: 0x4 */
  uint8_t RESERVED_3[20];
  uint32_t RADR_CASR;                              /**< Status register  - Reverse and Add to Register command, offset: 0x900 */
  uint32_t RADR_CAA;                               /**< Accumulator register - Reverse and Add to Register command, offset: 0x904 */
  uint32_t RADR_CA[9];                             /**< General Purpose Register 0 - Reverse and Add to Register command..General Purpose Register 8 - Reverse and Add to Register command, array offset: 0x908, array step: 0x4 */
  uint8_t RESERVED_4[84];
  uint32_t XOR_CASR;                               /**< Status register  - Exclusive Or command, offset: 0x980 */
  uint32_t XOR_CAA;                                /**< Accumulator register - Exclusive Or command, offset: 0x984 */
  uint32_t XOR_CA[9];                              /**< General Purpose Register 0 - Exclusive Or command..General Purpose Register 8 - Exclusive Or command, array offset: 0x988, array step: 0x4 */
  uint8_t RESERVED_5[20];
  uint32_t ROTL_CASR;                              /**< Status register  - Rotate Left command, offset: 0x9C0 */
  uint32_t ROTL_CAA;                               /**< Accumulator register - Rotate Left command, offset: 0x9C4 */
  uint32_t ROTL_CA[9];                             /**< General Purpose Register 0 - Rotate Left command..General Purpose Register 8 - Rotate Left command, array offset: 0x9C8, array step: 0x4 */
  uint8_t RESERVED_6[276];
  uint32_t AESC_CASR;                              /**< Status register  - AES Column Operation command, offset: 0xB00 */
  uint32_t AESC_CAA;                               /**< Accumulator register - AES Column Operation command, offset: 0xB04 */
  uint32_t AESC_CA[9];                             /**< General Purpose Register 0 - AES Column Operation command..General Purpose Register 8 - AES Column Operation command, array offset: 0xB08, array step: 0x4 */
  uint8_t RESERVED_7[20];
  uint32_t AESIC_CASR;                             /**< Status register  - AES Inverse Column Operation command, offset: 0xB40 */
  uint32_t AESIC_CAA;                              /**< Accumulator register - AES Inverse Column Operation command, offset: 0xB44 */
  uint32_t AESIC_CA[9];                            /**< General Purpose Register 0 - AES Inverse Column Operation command..General Purpose Register 8 - AES Inverse Column Operation command, array offset: 0xB48, array step: 0x4 */
} volatile *CAU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CAU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAU_Register_Accessor_Macros CAU - Register accessor macros
 * @{
 */


/* CAU - Register accessors */
#line 2488 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CAU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CAU Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAU_Register_Masks CAU Register Masks
 * @{
 */

/* LDR_CASR Bit Fields */
#line 2511 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* STR_CASR Bit Fields */
#line 2519 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ADR_CASR Bit Fields */
#line 2527 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RADR_CASR Bit Fields */
#line 2535 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* XOR_CASR Bit Fields */
#line 2543 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ROTL_CASR Bit Fields */
#line 2551 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* AESC_CASR Bit Fields */
#line 2559 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* AESIC_CASR Bit Fields */
#line 2567 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CAU_Register_Masks */


/* CAU - Peripheral instance base addresses */
/** Peripheral CAU base pointer */


/* ----------------------------------------------------------------------------
   -- CAU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAU_Register_Accessor_Macros CAU - Register accessor macros
 * @{
 */


/* CAU - Register instance definitions */
/* CAU */
#line 2693 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* CAU - Register array accessors */
#line 2704 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CAU_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CAU_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMP
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Peripheral CMP
 * @{
 */

/** CMP - Peripheral register structure */
typedef struct CMP_MemMap {
  uint8_t CR0;                                     /**< CMP Control Register 0, offset: 0x0 */
  uint8_t CR1;                                     /**< CMP Control Register 1, offset: 0x1 */
  uint8_t FPR;                                     /**< CMP Filter Period Register, offset: 0x2 */
  uint8_t SCR;                                     /**< CMP Status and Control Register, offset: 0x3 */
  uint8_t DACCR;                                   /**< DAC Control Register, offset: 0x4 */
  uint8_t MUXCR;                                   /**< MUX Control Register, offset: 0x5 */
} volatile *CMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register accessors */
#line 2751 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/* CR0 Bit Fields */
#line 2773 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR1 Bit Fields */
#line 2788 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FPR Bit Fields */



/* SCR Bit Fields */
#line 2805 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DACCR Bit Fields */
#line 2813 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MUXCR Bit Fields */
#line 2820 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base pointer */

/** Peripheral CMP1 base pointer */

/** Peripheral CMP2 base pointer */

/** Peripheral CMP3 base pointer */


/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register instance definitions */
/* CMP0 */
#line 2854 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMP1 */
#line 2861 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMP2 */
#line 2868 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMP3 */
#line 2875 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CMP_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Peripheral CMT
 * @{
 */

/** CMT - Peripheral register structure */
typedef struct CMT_MemMap {
  uint8_t CGH1;                                    /**< CMT Carrier Generator High Data Register 1, offset: 0x0 */
  uint8_t CGL1;                                    /**< CMT Carrier Generator Low Data Register 1, offset: 0x1 */
  uint8_t CGH2;                                    /**< CMT Carrier Generator High Data Register 2, offset: 0x2 */
  uint8_t CGL2;                                    /**< CMT Carrier Generator Low Data Register 2, offset: 0x3 */
  uint8_t OC;                                      /**< CMT Output Control Register, offset: 0x4 */
  uint8_t MSC;                                     /**< CMT Modulator Status and Control Register, offset: 0x5 */
  uint8_t CMD1;                                    /**< CMT Modulator Data Register Mark High, offset: 0x6 */
  uint8_t CMD2;                                    /**< CMT Modulator Data Register Mark Low, offset: 0x7 */
  uint8_t CMD3;                                    /**< CMT Modulator Data Register Space High, offset: 0x8 */
  uint8_t CMD4;                                    /**< CMT Modulator Data Register Space Low, offset: 0x9 */
  uint8_t PPS;                                     /**< CMT Primary Prescaler Register, offset: 0xA */
  uint8_t DMA;                                     /**< CMT Direct Memory Access, offset: 0xB */
} volatile *CMT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros
 * @{
 */


/* CMT - Register accessors */
#line 2934 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CMT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Register_Masks CMT Register Masks
 * @{
 */

/* CGH1 Bit Fields */



/* CGL1 Bit Fields */



/* CGH2 Bit Fields */



/* CGL2 Bit Fields */



/* OC Bit Fields */
#line 2972 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MSC Bit Fields */
#line 2988 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMD1 Bit Fields */



/* CMD2 Bit Fields */



/* CMD3 Bit Fields */



/* CMD4 Bit Fields */



/* PPS Bit Fields */



/* DMA Bit Fields */



/**
 * @}
 */ /* end of group CMT_Register_Masks */


/* CMT - Peripheral instance base addresses */
/** Peripheral CMT base pointer */


/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros
 * @{
 */


/* CMT - Register instance definitions */
/* CMT */
#line 3045 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CMT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CMT_Peripheral */


/* ----------------------------------------------------------------------------
   -- CRC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Peripheral CRC
 * @{
 */

/** CRC - Peripheral register structure */
typedef struct CRC_MemMap {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      uint16_t CRCL;                                   /**< CRC_CRCL register., offset: 0x0 */
      uint16_t CRCH;                                   /**< CRC_CRCH register., offset: 0x2 */
    } ACCESS16BIT;
    uint32_t CRC;                                    /**< CRC Data Register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      uint8_t CRCLL;                                   /**< CRC_CRCLL register., offset: 0x0 */
      uint8_t CRCLU;                                   /**< CRC_CRCLU register., offset: 0x1 */
      uint8_t CRCHL;                                   /**< CRC_CRCHL register., offset: 0x2 */
      uint8_t CRCHU;                                   /**< CRC_CRCHU register., offset: 0x3 */
    } ACCESS8BIT;
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint16_t GPOLYL;                                 /**< CRC_GPOLYL register., offset: 0x4 */
      uint16_t GPOLYH;                                 /**< CRC_GPOLYH register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    uint32_t GPOLY;                                  /**< CRC Polynomial Register, offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint8_t GPOLYLL;                                 /**< CRC_GPOLYLL register., offset: 0x4 */
      uint8_t GPOLYLU;                                 /**< CRC_GPOLYLU register., offset: 0x5 */
      uint8_t GPOLYHL;                                 /**< CRC_GPOLYHL register., offset: 0x6 */
      uint8_t GPOLYHU;                                 /**< CRC_GPOLYHU register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
  };
  union {                                          /* offset: 0x8 */
    uint32_t CTRL;                                   /**< CRC Control Register, offset: 0x8 */
    struct {                                         /* offset: 0x8 */
      uint8_t RESERVED_0[3];
      uint8_t CTRLHU;                                  /**< CRC_CTRLHU register., offset: 0xB */
    } CTRL_ACCESS8BIT;
  };
} volatile *CRC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register accessors */
#line 3129 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/* CRCL Bit Fields */



/* CRCH Bit Fields */



/* CRC Bit Fields */
#line 3165 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CRCLL Bit Fields */



/* CRCLU Bit Fields */



/* CRCHL Bit Fields */



/* CRCHU Bit Fields */



/* GPOLYL Bit Fields */



/* GPOLYH Bit Fields */



/* GPOLY Bit Fields */
#line 3196 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* GPOLYLL Bit Fields */



/* GPOLYLU Bit Fields */



/* GPOLYHL Bit Fields */



/* GPOLYHU Bit Fields */



/* CTRL Bit Fields */
#line 3225 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CTRLHU Bit Fields */
#line 3238 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base pointer */


/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register instance definitions */
/* CRC */
#line 3276 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CRC_Peripheral */


/* ----------------------------------------------------------------------------
   -- CoreDebug
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Peripheral CoreDebug
 * @{
 */

/** CoreDebug - Peripheral register structure */
typedef struct CoreDebug_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t base_DHCSR_Read;                        /**< Debug Halting Control and Status Register, offset: 0x0 */
    uint32_t base_DHCSR_Write;                       /**< Debug Halting Control and Status Register, offset: 0x0 */
  };
  uint32_t base_DCRSR;                             /**< Debug Core Register Selector Register, offset: 0x4 */
  uint32_t base_DCRDR;                             /**< Debug Core Register Data Register, offset: 0x8 */
  uint32_t base_DEMCR;                             /**< Debug Exception and Monitor Control Register, offset: 0xC */
} volatile *CoreDebug_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CoreDebug - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Register_Accessor_Macros CoreDebug - Register accessor macros
 * @{
 */


/* CoreDebug - Register accessors */






/**
 * @}
 */ /* end of group CoreDebug_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CoreDebug Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Register_Masks CoreDebug Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group CoreDebug_Register_Masks */


/* CoreDebug - Peripheral instance base addresses */
/** Peripheral CoreDebug base pointer */


/* ----------------------------------------------------------------------------
   -- CoreDebug - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Register_Accessor_Macros CoreDebug - Register accessor macros
 * @{
 */


/* CoreDebug - Register instance definitions */
/* CoreDebug */






/**
 * @}
 */ /* end of group CoreDebug_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CoreDebug_Peripheral */


/* ----------------------------------------------------------------------------
   -- DAC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Peripheral DAC
 * @{
 */

/** DAC - Peripheral register structure */
typedef struct DAC_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    uint8_t DATL;                                    /**< DAC Data Low Register, array offset: 0x0, array step: 0x2 */
    uint8_t DATH;                                    /**< DAC Data High Register, array offset: 0x1, array step: 0x2 */
  } DAT[16];
  uint8_t SR;                                      /**< DAC Status Register, offset: 0x20 */
  uint8_t C0;                                      /**< DAC Control Register, offset: 0x21 */
  uint8_t C1;                                      /**< DAC Control Register 1, offset: 0x22 */
  uint8_t C2;                                      /**< DAC Control Register 2, offset: 0x23 */
} volatile *DAC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register accessors */
#line 3414 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/* DATL Bit Fields */



/* DATH Bit Fields */



/* SR Bit Fields */
#line 3444 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C0 Bit Fields */
#line 3461 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C1 Bit Fields */
#line 3472 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C2 Bit Fields */
#line 3479 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base pointer */

/** Peripheral DAC1 base pointer */


/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register instance definitions */
/* DAC0 */
#line 3539 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DAC1 */
#line 3576 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* DAC - Register array accessors */





/**
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DAC_Peripheral */


/* ----------------------------------------------------------------------------
   -- DDR
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DDR_Peripheral DDR
 * @{
 */

/** DDR - Peripheral register structure */
typedef struct DDR_MemMap {
  uint32_t CR00;                                   /**< DDR Control Register 0, offset: 0x0 */
  uint32_t CR01;                                   /**< DDR Control Register 1, offset: 0x4 */
  uint32_t CR02;                                   /**< DDR Control Register 2, offset: 0x8 */
  uint32_t CR03;                                   /**< DDR Control Register 3, offset: 0xC */
  uint32_t CR04;                                   /**< DDR Control Register 4, offset: 0x10 */
  uint32_t CR05;                                   /**< DDR Control Register 5, offset: 0x14 */
  uint32_t CR06;                                   /**< DDR Control Register 6, offset: 0x18 */
  uint32_t CR07;                                   /**< DDR Control Register 7, offset: 0x1C */
  uint32_t CR08;                                   /**< DDR Control Register 8, offset: 0x20 */
  uint32_t CR09;                                   /**< DDR Control Register 9, offset: 0x24 */
  uint32_t CR10;                                   /**< DDR Control Register 10, offset: 0x28 */
  uint32_t CR11;                                   /**< DDR Control Register 11, offset: 0x2C */
  uint32_t CR12;                                   /**< DDR Control Register 12, offset: 0x30 */
  uint32_t CR13;                                   /**< DDR Control Register 13, offset: 0x34 */
  uint32_t CR14;                                   /**< DDR Control Register 14, offset: 0x38 */
  uint32_t CR15;                                   /**< DDR Control Register 15, offset: 0x3C */
  uint32_t CR16;                                   /**< DDR Control Register 16, offset: 0x40 */
  uint32_t CR17;                                   /**< DDR Control Register 17, offset: 0x44 */
  uint32_t CR18;                                   /**< DDR Control Register 18, offset: 0x48 */
  uint32_t CR19;                                   /**< DDR Control Register 19, offset: 0x4C */
  uint32_t CR20;                                   /**< DDR Control Register 20, offset: 0x50 */
  uint32_t CR21;                                   /**< DDR Control Register 21, offset: 0x54 */
  uint32_t CR22;                                   /**< DDR Control Register 22, offset: 0x58 */
  uint32_t CR23;                                   /**< DDR Control Register 23, offset: 0x5C */
  uint32_t CR24;                                   /**< DDR Control Register 24, offset: 0x60 */
  uint32_t CR25;                                   /**< DDR Control Register 25, offset: 0x64 */
  uint32_t CR26;                                   /**< DDR Control Register 26, offset: 0x68 */
  uint32_t CR27;                                   /**< DDR Control Register 27, offset: 0x6C */
  uint32_t CR28;                                   /**< DDR Control Register 28, offset: 0x70 */
  uint32_t CR29;                                   /**< DDR Control Register 29, offset: 0x74 */
  uint32_t CR30;                                   /**< DDR Control Register 30, offset: 0x78 */
  uint32_t CR31;                                   /**< DDR Control Register 31, offset: 0x7C */
  uint32_t CR32;                                   /**< DDR Control Register 32, offset: 0x80 */
  uint32_t CR33;                                   /**< DDR Control Register 33, offset: 0x84 */
  uint32_t CR34;                                   /**< DDR Control Register 34, offset: 0x88 */
  uint32_t CR35;                                   /**< DDR Control Register 35, offset: 0x8C */
  uint32_t CR36;                                   /**< DDR Control Register 36, offset: 0x90 */
  uint32_t CR37;                                   /**< DDR Control Register 37, offset: 0x94 */
  uint32_t CR38;                                   /**< DDR Control Register 38, offset: 0x98 */
  uint32_t CR39;                                   /**< DDR Control Register 39, offset: 0x9C */
  uint32_t CR40;                                   /**< DDR Control Register 40, offset: 0xA0 */
  uint32_t CR41;                                   /**< DDR Control Register 41, offset: 0xA4 */
  uint32_t CR42;                                   /**< DDR Control Register 42, offset: 0xA8 */
  uint32_t CR43;                                   /**< DDR Control Register 43, offset: 0xAC */
  uint32_t CR44;                                   /**< DDR Control Register 44, offset: 0xB0 */
  uint32_t CR45;                                   /**< DDR Control Register 45, offset: 0xB4 */
  uint32_t CR46;                                   /**< DDR Control Register 46, offset: 0xB8 */
  uint32_t CR47;                                   /**< DDR Control Register 47, offset: 0xBC */
  uint32_t CR48;                                   /**< DDR Control Register 48, offset: 0xC0 */
  uint32_t CR49;                                   /**< DDR Control Register 49, offset: 0xC4 */
  uint32_t CR50;                                   /**< DDR Control Register 50, offset: 0xC8 */
  uint32_t CR51;                                   /**< DDR Control Register 51, offset: 0xCC */
  uint32_t CR52;                                   /**< DDR Control Register 52, offset: 0xD0 */
  uint32_t CR53;                                   /**< DDR Control Register 53, offset: 0xD4 */
  uint32_t CR54;                                   /**< DDR Control Register 54, offset: 0xD8 */
  uint32_t CR55;                                   /**< DDR Control Register 55, offset: 0xDC */
  uint32_t CR56;                                   /**< DDR Control Register 56, offset: 0xE0 */
  uint32_t CR57;                                   /**< DDR Control Register 57, offset: 0xE4 */
  uint32_t CR58;                                   /**< DDR Control Register 58, offset: 0xE8 */
  uint32_t CR59;                                   /**< DDR Control Register 59, offset: 0xEC */
  uint32_t CR60;                                   /**< DDR Control Register 60, offset: 0xF0 */
  uint32_t CR61;                                   /**< DDR Control Register 61, offset: 0xF4 */
  uint32_t CR62;                                   /**< DDR Control Register 62, offset: 0xF8 */
  uint32_t CR63;                                   /**< DDR Control Register 63, offset: 0xFC */
  uint8_t RESERVED_0[128];
  uint32_t RCR;                                    /**< RCR Control Register, offset: 0x180 */
} volatile *DDR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DDR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DDR_Register_Accessor_Macros DDR - Register accessor macros
 * @{
 */


/* DDR - Register accessors */
#line 3748 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DDR_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DDR Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DDR_Register_Masks DDR Register Masks
 * @{
 */

/* CR00 Bit Fields */
#line 3772 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR01 Bit Fields */
#line 3782 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR02 Bit Fields */
#line 3789 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR03 Bit Fields */
#line 3802 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR04 Bit Fields */
#line 3815 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR05 Bit Fields */
#line 3828 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR06 Bit Fields */
#line 3837 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR07 Bit Fields */
#line 3848 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR08 Bit Fields */
#line 3860 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR09 Bit Fields */
#line 3869 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR10 Bit Fields */
#line 3879 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR11 Bit Fields */
#line 3888 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR12 Bit Fields */
#line 3895 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR13 Bit Fields */





/* CR14 Bit Fields */
#line 3908 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR15 Bit Fields */
#line 3916 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR16 Bit Fields */
#line 3925 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR17 Bit Fields */
#line 3932 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR18 Bit Fields */
#line 3939 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR19 Bit Fields */
#line 3946 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR20 Bit Fields */
#line 3958 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR21 Bit Fields */
#line 3965 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR22 Bit Fields */
#line 3972 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR23 Bit Fields */
#line 3979 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR25 Bit Fields */
#line 3991 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR26 Bit Fields */
#line 4002 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR27 Bit Fields */
#line 4011 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR28 Bit Fields */
#line 4020 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR29 Bit Fields */
#line 4030 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR30 Bit Fields */
#line 4039 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR31 Bit Fields */



/* CR32 Bit Fields */



/* CR33 Bit Fields */
#line 4057 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR34 Bit Fields */




/* CR35 Bit Fields */
#line 4069 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR36 Bit Fields */
#line 4076 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR37 Bit Fields */
#line 4089 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR38 Bit Fields */
#line 4099 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR39 Bit Fields */
#line 4109 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR40 Bit Fields */
#line 4116 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR41 Bit Fields */
#line 4126 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR42 Bit Fields */
#line 4133 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR43 Bit Fields */
#line 4143 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR44 Bit Fields */
#line 4154 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR45 Bit Fields */
#line 4167 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR46 Bit Fields */
#line 4177 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR47 Bit Fields */
#line 4190 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR48 Bit Fields */
#line 4200 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR49 Bit Fields */
#line 4210 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR50 Bit Fields */





/* CR51 Bit Fields */
#line 4226 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR52 Bit Fields */
#line 4239 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR53 Bit Fields */
#line 4248 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR54 Bit Fields */
#line 4255 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR55 Bit Fields */
#line 4262 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR56 Bit Fields */
#line 4272 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR57 Bit Fields */
#line 4284 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR58 Bit Fields */
#line 4291 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR59 Bit Fields */
#line 4298 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR60 Bit Fields */
#line 4305 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR61 Bit Fields */
#line 4312 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR62 Bit Fields */
#line 4319 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR63 Bit Fields */
#line 4326 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RCR Bit Fields */



/**
 * @}
 */ /* end of group DDR_Register_Masks */


/* DDR - Peripheral instance base addresses */
/** Peripheral DDR base pointer */


/* ----------------------------------------------------------------------------
   -- DDR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DDR_Register_Accessor_Macros DDR - Register accessor macros
 * @{
 */


/* DDR - Register instance definitions */
/* DDR */
#line 4416 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DDR_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DDR_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMA
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Peripheral DMA
 * @{
 */

/** DMA - Peripheral register structure */
typedef struct DMA_MemMap {
  uint32_t CR;                                     /**< Control Register, offset: 0x0 */
  uint32_t ES;                                     /**< Error Status Register, offset: 0x4 */
  uint8_t RESERVED_0[4];
  uint32_t ERQ;                                    /**< Enable Request Register, offset: 0xC */
  uint8_t RESERVED_1[4];
  uint32_t EEI;                                    /**< Enable Error Interrupt Register, offset: 0x14 */
  uint8_t CEEI;                                    /**< Clear Enable Error Interrupt Register, offset: 0x18 */
  uint8_t SEEI;                                    /**< Set Enable Error Interrupt Register, offset: 0x19 */
  uint8_t CERQ;                                    /**< Clear Enable Request Register, offset: 0x1A */
  uint8_t SERQ;                                    /**< Set Enable Request Register, offset: 0x1B */
  uint8_t CDNE;                                    /**< Clear DONE Status Bit Register, offset: 0x1C */
  uint8_t SSRT;                                    /**< Set START Bit Register, offset: 0x1D */
  uint8_t CERR;                                    /**< Clear Error Register, offset: 0x1E */
  uint8_t CINT;                                    /**< Clear Interrupt Request Register, offset: 0x1F */
  uint8_t RESERVED_2[4];
  uint32_t INT;                                    /**< Interrupt Request Register, offset: 0x24 */
  uint8_t RESERVED_3[4];
  uint32_t ERR;                                    /**< Error Register, offset: 0x2C */
  uint8_t RESERVED_4[4];
  uint32_t HRS;                                    /**< Hardware Request Status Register, offset: 0x34 */
  uint8_t RESERVED_5[200];
  uint8_t DCHPRI3;                                 /**< Channel n Priority Register, offset: 0x100 */
  uint8_t DCHPRI2;                                 /**< Channel n Priority Register, offset: 0x101 */
  uint8_t DCHPRI1;                                 /**< Channel n Priority Register, offset: 0x102 */
  uint8_t DCHPRI0;                                 /**< Channel n Priority Register, offset: 0x103 */
  uint8_t DCHPRI7;                                 /**< Channel n Priority Register, offset: 0x104 */
  uint8_t DCHPRI6;                                 /**< Channel n Priority Register, offset: 0x105 */
  uint8_t DCHPRI5;                                 /**< Channel n Priority Register, offset: 0x106 */
  uint8_t DCHPRI4;                                 /**< Channel n Priority Register, offset: 0x107 */
  uint8_t DCHPRI11;                                /**< Channel n Priority Register, offset: 0x108 */
  uint8_t DCHPRI10;                                /**< Channel n Priority Register, offset: 0x109 */
  uint8_t DCHPRI9;                                 /**< Channel n Priority Register, offset: 0x10A */
  uint8_t DCHPRI8;                                 /**< Channel n Priority Register, offset: 0x10B */
  uint8_t DCHPRI15;                                /**< Channel n Priority Register, offset: 0x10C */
  uint8_t DCHPRI14;                                /**< Channel n Priority Register, offset: 0x10D */
  uint8_t DCHPRI13;                                /**< Channel n Priority Register, offset: 0x10E */
  uint8_t DCHPRI12;                                /**< Channel n Priority Register, offset: 0x10F */
  uint8_t DCHPRI19;                                /**< Channel n Priority Register, offset: 0x110 */
  uint8_t DCHPRI18;                                /**< Channel n Priority Register, offset: 0x111 */
  uint8_t DCHPRI17;                                /**< Channel n Priority Register, offset: 0x112 */
  uint8_t DCHPRI16;                                /**< Channel n Priority Register, offset: 0x113 */
  uint8_t DCHPRI23;                                /**< Channel n Priority Register, offset: 0x114 */
  uint8_t DCHPRI22;                                /**< Channel n Priority Register, offset: 0x115 */
  uint8_t DCHPRI21;                                /**< Channel n Priority Register, offset: 0x116 */
  uint8_t DCHPRI20;                                /**< Channel n Priority Register, offset: 0x117 */
  uint8_t DCHPRI27;                                /**< Channel n Priority Register, offset: 0x118 */
  uint8_t DCHPRI26;                                /**< Channel n Priority Register, offset: 0x119 */
  uint8_t DCHPRI25;                                /**< Channel n Priority Register, offset: 0x11A */
  uint8_t DCHPRI24;                                /**< Channel n Priority Register, offset: 0x11B */
  uint8_t DCHPRI31;                                /**< Channel n Priority Register, offset: 0x11C */
  uint8_t DCHPRI30;                                /**< Channel n Priority Register, offset: 0x11D */
  uint8_t DCHPRI29;                                /**< Channel n Priority Register, offset: 0x11E */
  uint8_t DCHPRI28;                                /**< Channel n Priority Register, offset: 0x11F */
  uint8_t RESERVED_6[3808];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    uint32_t SADDR;                                  /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    uint16_t SOFF;                                   /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    uint16_t ATTR;                                   /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLNO;                            /**< TCD Minor Byte Count (Minor Loop Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFNO;                         /**< TCD Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFYES;                        /**< TCD Signed Minor Loop Offset (Minor Loop and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    uint32_t SLAST;                                  /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    uint32_t DADDR;                                  /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    uint16_t DOFF;                                   /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKNO;                          /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKYES;                         /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    uint32_t DLAST_SGA;                              /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    uint16_t CSR;                                    /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKNO;                          /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKYES;                         /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[32];
} volatile *DMA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register accessors */
#line 4590 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/* CR Bit Fields */
#line 4630 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ES Bit Fields */
#line 4658 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ERQ Bit Fields */
#line 4723 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EEI Bit Fields */
#line 4788 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CEEI Bit Fields */
#line 4796 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SEEI Bit Fields */
#line 4804 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CERQ Bit Fields */
#line 4812 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SERQ Bit Fields */
#line 4820 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CDNE Bit Fields */
#line 4828 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SSRT Bit Fields */
#line 4836 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CERR Bit Fields */
#line 4844 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CINT Bit Fields */
#line 4852 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* INT Bit Fields */
#line 4917 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ERR Bit Fields */
#line 4982 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HRS Bit Fields */
#line 5047 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI3 Bit Fields */
#line 5058 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI2 Bit Fields */
#line 5069 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI1 Bit Fields */
#line 5080 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI0 Bit Fields */
#line 5091 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI7 Bit Fields */
#line 5102 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI6 Bit Fields */
#line 5113 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI5 Bit Fields */
#line 5124 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI4 Bit Fields */
#line 5135 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI11 Bit Fields */
#line 5146 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI10 Bit Fields */
#line 5157 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI9 Bit Fields */
#line 5168 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI8 Bit Fields */
#line 5179 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI15 Bit Fields */
#line 5190 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI14 Bit Fields */
#line 5201 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI13 Bit Fields */
#line 5212 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI12 Bit Fields */
#line 5223 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI19 Bit Fields */
#line 5234 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI18 Bit Fields */
#line 5245 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI17 Bit Fields */
#line 5256 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI16 Bit Fields */
#line 5267 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI23 Bit Fields */
#line 5278 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI22 Bit Fields */
#line 5289 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI21 Bit Fields */
#line 5300 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI20 Bit Fields */
#line 5311 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI27 Bit Fields */
#line 5322 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI26 Bit Fields */
#line 5333 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI25 Bit Fields */
#line 5344 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI24 Bit Fields */
#line 5355 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI31 Bit Fields */
#line 5366 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI30 Bit Fields */
#line 5377 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI29 Bit Fields */
#line 5388 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCHPRI28 Bit Fields */
#line 5399 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SADDR Bit Fields */



/* SOFF Bit Fields */



/* ATTR Bit Fields */
#line 5420 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* NBYTES_MLNO Bit Fields */



/* NBYTES_MLOFFNO Bit Fields */
#line 5432 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* NBYTES_MLOFFYES Bit Fields */
#line 5443 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SLAST Bit Fields */



/* DADDR Bit Fields */



/* DOFF Bit Fields */



/* CITER_ELINKNO Bit Fields */





/* CITER_ELINKYES Bit Fields */
#line 5470 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DLAST_SGA Bit Fields */



/* CSR Bit Fields */
#line 5497 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* BITER_ELINKNO Bit Fields */





/* BITER_ELINKYES Bit Fields */
#line 5512 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA base pointer */


/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register instance definitions */
/* DMA */
#line 6061 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* DMA - Register array accessors */
#line 6078 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DMA_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMAMUX
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Peripheral DMAMUX
 * @{
 */

/** DMAMUX - Peripheral register structure */
typedef struct DMAMUX_MemMap {
  uint8_t CHCFG[16];                               /**< Channel Configuration Register, array offset: 0x0, array step: 0x1 */
} volatile *DMAMUX_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register accessors */


/**
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/* CHCFG Bit Fields */
#line 6138 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX0 base pointer */

/** Peripheral DMAMUX1 base pointer */


/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register instance definitions */
/* DMAMUX0 */
#line 6178 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DMAMUX1 */
#line 6195 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* DMAMUX - Register array accessors */



/**
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DMAMUX_Peripheral */


/* ----------------------------------------------------------------------------
   -- DRY
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DRY_Peripheral DRY
 * @{
 */

/** DRY - Peripheral register structure */
typedef struct DRY_MemMap {
  uint8_t RESERVED_0[4];
  uint32_t SKVR;                                   /**< DryIce Secure Key Valid Register, offset: 0x4 */
  uint32_t SKWLR;                                  /**< DryIce Secure Key Write Lock Register, offset: 0x8 */
  uint32_t SKRLR;                                  /**< DryIce Secure Key Read Lock Register, offset: 0xC */
  uint32_t CR;                                     /**< DryIce Control Register, offset: 0x10 */
  uint32_t SR;                                     /**< DryIce Status Register, offset: 0x14 */
  uint32_t LR;                                     /**< DryIce Lock Register, offset: 0x18 */
  uint32_t IER;                                    /**< DryIce Interrupt Enable Register, offset: 0x1C */
  uint32_t TSR;                                    /**< DryIce Tamper Seconds Register, offset: 0x20 */
  uint32_t TER;                                    /**< DryIce Tamper Enable Register, offset: 0x24 */
  uint32_t PDR;                                    /**< DryIce Pin Direction Register, offset: 0x28 */
  uint32_t PPR;                                    /**< DryIce Pin Polarity Register, offset: 0x2C */
  uint32_t ATR[2];                                 /**< DryIce Active Tamper Register, array offset: 0x30, array step: 0x4 */
  uint8_t RESERVED_1[8];
  uint32_t PGFR[8];                                /**< DryIce Pin Glitch Filter Register, array offset: 0x40, array step: 0x4 */
  uint8_t RESERVED_2[1952];
  uint32_t WAC;                                    /**< DryIce Write Access Control Register, offset: 0x800 */
  uint32_t RAC;                                    /**< DryIce Read Access Control Register, offset: 0x804 */
  uint8_t RESERVED_3[2040];
  uint32_t SKR[8];                                 /**< Secure Key Register, array offset: 0x1000, array step: 0x4 */
  uint8_t RESERVED_4[2016];
  uint32_t SWAC;                                   /**< Secure Write Access Control, offset: 0x1800 */
  uint32_t SRAC;                                   /**< Secure Read Access Control, offset: 0x1804 */
} volatile *DRY_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DRY - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DRY_Register_Accessor_Macros DRY - Register accessor macros
 * @{
 */


/* DRY - Register accessors */
#line 6275 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DRY_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DRY Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DRY_Register_Masks DRY Register Masks
 * @{
 */

/* SKVR Bit Fields */



/* SKWLR Bit Fields */



/* SKRLR Bit Fields */



/* CR Bit Fields */
#line 6322 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SR Bit Fields */
#line 6346 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LR Bit Fields */
#line 6377 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IER Bit Fields */
#line 6399 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TSR Bit Fields */



/* TER Bit Fields */
#line 6423 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PDR Bit Fields */
#line 6430 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PPR Bit Fields */
#line 6437 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ATR Bit Fields */
#line 6444 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PGFR Bit Fields */
#line 6457 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WAC Bit Fields */
#line 6486 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RAC Bit Fields */
#line 6515 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SKR Bit Fields */



/* SWAC Bit Fields */



/* SRAC Bit Fields */




/**
 * @}
 */ /* end of group DRY_Register_Masks */


/* DRY - Peripheral instance base addresses */
/** Peripheral DRY base pointer */


/* ----------------------------------------------------------------------------
   -- DRY - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DRY_Register_Accessor_Macros DRY - Register accessor macros
 * @{
 */


/* DRY - Register instance definitions */
/* DRY */
#line 6582 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* DRY - Register array accessors */




/**
 * @}
 */ /* end of group DRY_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DRY_Peripheral */


/* ----------------------------------------------------------------------------
   -- DWT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Peripheral DWT
 * @{
 */

/** DWT - Peripheral register structure */
typedef struct DWT_MemMap {
  uint32_t CTRL;                                   /**< Control Register, offset: 0x0 */
  uint32_t CYCCNT;                                 /**< Cycle Count Register, offset: 0x4 */
  uint32_t CPICNT;                                 /**< CPI Count Register, offset: 0x8 */
  uint32_t EXCCNT;                                 /**< Exception Overhead Count Register, offset: 0xC */
  uint32_t SLEEPCNT;                               /**< Sleep Count Register, offset: 0x10 */
  uint32_t LSUCNT;                                 /**< LSU Count Register, offset: 0x14 */
  uint32_t FOLDCNT;                                /**< Folded-instruction Count Register, offset: 0x18 */
  uint32_t PCSR;                                   /**< Program Counter Sample Register, offset: 0x1C */
  struct {                                         /* offset: 0x20, array step: 0x10 */
    uint32_t COMP;                                   /**< Comparator Register 0..Comparator Register 3, array offset: 0x20, array step: 0x10 */
    uint32_t MASK;                                   /**< Mask Register 0..Mask Register 3, array offset: 0x24, array step: 0x10 */
    uint32_t FUNCTION;                               /**< Function Register 0..Function Register 3, array offset: 0x28, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } COMPARATOR[4];
  uint8_t RESERVED_0[3952];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *DWT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DWT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Register_Accessor_Macros DWT - Register accessor macros
 * @{
 */


/* DWT - Register accessors */
#line 6672 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group DWT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DWT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Register_Masks DWT Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group DWT_Register_Masks */


/* DWT - Peripheral instance base addresses */
/** Peripheral DWT base pointer */


/* ----------------------------------------------------------------------------
   -- DWT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Register_Accessor_Macros DWT - Register accessor macros
 * @{
 */


/* DWT - Register instance definitions */
/* DWT */
#line 6741 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* DWT - Register array accessors */




/**
 * @}
 */ /* end of group DWT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DWT_Peripheral */


/* ----------------------------------------------------------------------------
   -- ENET
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ENET_Peripheral ENET
 * @{
 */

/** ENET - Peripheral register structure */
typedef struct ENET_MemMap {
  uint8_t RESERVED_0[4];
  uint32_t EIR;                                    /**< Interrupt Event Register, offset: 0x4 */
  uint32_t EIMR;                                   /**< Interrupt Mask Register, offset: 0x8 */
  uint8_t RESERVED_1[4];
  uint32_t RDAR;                                   /**< Receive Descriptor Active Register, offset: 0x10 */
  uint32_t TDAR;                                   /**< Transmit Descriptor Active Register, offset: 0x14 */
  uint8_t RESERVED_2[12];
  uint32_t ECR;                                    /**< Ethernet Control Register, offset: 0x24 */
  uint8_t RESERVED_3[24];
  uint32_t MMFR;                                   /**< MII Management Frame Register, offset: 0x40 */
  uint32_t MSCR;                                   /**< MII Speed Control Register, offset: 0x44 */
  uint8_t RESERVED_4[28];
  uint32_t MIBC;                                   /**< MIB Control Register, offset: 0x64 */
  uint8_t RESERVED_5[28];
  uint32_t RCR;                                    /**< Receive Control Register, offset: 0x84 */
  uint8_t RESERVED_6[60];
  uint32_t TCR;                                    /**< Transmit Control Register, offset: 0xC4 */
  uint8_t RESERVED_7[28];
  uint32_t PALR;                                   /**< Physical Address Lower Register, offset: 0xE4 */
  uint32_t PAUR;                                   /**< Physical Address Upper Register, offset: 0xE8 */
  uint32_t OPD;                                    /**< Opcode/Pause Duration Register, offset: 0xEC */
  uint8_t RESERVED_8[40];
  uint32_t IAUR;                                   /**< Descriptor Individual Upper Address Register, offset: 0x118 */
  uint32_t IALR;                                   /**< Descriptor Individual Lower Address Register, offset: 0x11C */
  uint32_t GAUR;                                   /**< Descriptor Group Upper Address Register, offset: 0x120 */
  uint32_t GALR;                                   /**< Descriptor Group Lower Address Register, offset: 0x124 */
  uint8_t RESERVED_9[28];
  uint32_t TFWR;                                   /**< Transmit FIFO Watermark Register, offset: 0x144 */
  uint8_t RESERVED_10[56];
  uint32_t RDSR;                                   /**< Receive Descriptor Ring Start Register, offset: 0x180 */
  uint32_t TDSR;                                   /**< Transmit Buffer Descriptor Ring Start Register, offset: 0x184 */
  uint32_t MRBR;                                   /**< Maximum Receive Buffer Size Register, offset: 0x188 */
  uint8_t RESERVED_11[4];
  uint32_t RSFL;                                   /**< Receive FIFO Section Full Threshold, offset: 0x190 */
  uint32_t RSEM;                                   /**< Receive FIFO Section Empty Threshold, offset: 0x194 */
  uint32_t RAEM;                                   /**< Receive FIFO Almost Empty Threshold, offset: 0x198 */
  uint32_t RAFL;                                   /**< Receive FIFO Almost Full Threshold, offset: 0x19C */
  uint32_t TSEM;                                   /**< Transmit FIFO Section Empty Threshold, offset: 0x1A0 */
  uint32_t TAEM;                                   /**< Transmit FIFO Almost Empty Threshold, offset: 0x1A4 */
  uint32_t TAFL;                                   /**< Transmit FIFO Almost Full Threshold, offset: 0x1A8 */
  uint32_t TIPG;                                   /**< Transmit Inter-Packet Gap, offset: 0x1AC */
  uint32_t FTRL;                                   /**< Frame Truncation Length, offset: 0x1B0 */
  uint8_t RESERVED_12[12];
  uint32_t TACC;                                   /**< Transmit Accelerator Function Configuration, offset: 0x1C0 */
  uint32_t RACC;                                   /**< Receive Accelerator Function Configuration, offset: 0x1C4 */
  uint8_t RESERVED_13[56];
  uint32_t RMON_T_DROP;                            /**< Count of frames not counted correctly (RMON_T_DROP). NOTE: Counter not implemented (read 0 always) as not applicable., offset: 0x200 */
  uint32_t RMON_T_PACKETS;                         /**< RMON Tx packet count (RMON_T_PACKETS), offset: 0x204 */
  uint32_t RMON_T_BC_PKT;                          /**< RMON Tx Broadcast Packets (RMON_T_BC_PKT), offset: 0x208 */
  uint32_t RMON_T_MC_PKT;                          /**< RMON Tx Multicast Packets (RMON_T_MC_PKT), offset: 0x20C */
  uint32_t RMON_T_CRC_ALIGN;                       /**< RMON Tx Packets w CRC/Align error (RMON_T_CRC_ALIGN), offset: 0x210 */
  uint32_t RMON_T_UNDERSIZE;                       /**< RMON Tx Packets < 64 bytes, good CRC (RMON_T_UNDERSIZE), offset: 0x214 */
  uint32_t RMON_T_OVERSIZE;                        /**< RMON Tx Packets > MAX_FL bytes, good CRC (RMON_T_OVERSIZE), offset: 0x218 */
  uint32_t RMON_T_FRAG;                            /**< RMON Tx Packets < 64 bytes, bad CRC (RMON_T_FRAG), offset: 0x21C */
  uint32_t RMON_T_JAB;                             /**< RMON Tx Packets > MAX_FL bytes, bad CRC (RMON_T_JAB), offset: 0x220 */
  uint32_t RMON_T_COL;                             /**< RMON Tx collision count (RMON_T_COL), offset: 0x224 */
  uint32_t RMON_T_P64;                             /**< RMON Tx 64 byte packets (RMON_T_P64), offset: 0x228 */
  uint32_t RMON_T_P65TO127;                        /**< RMON Tx 65 to 127 byte packets (RMON_T_P65TO127), offset: 0x22C */
  uint32_t RMON_T_P128TO255;                       /**< RMON Tx 128 to 255 byte packets (RMON_T_P128TO255), offset: 0x230 */
  uint32_t RMON_T_P256TO511;                       /**< RMON Tx 256 to 511 byte packets (RMON_T_P256TO511), offset: 0x234 */
  uint32_t RMON_T_P512TO1023;                      /**< RMON Tx 512 to 1023 byte packets (RMON_T_P512TO1023), offset: 0x238 */
  uint32_t RMON_T_P1024TO2047;                     /**< RMON Tx 1024 to 2047 byte packets (RMON_T_P1024TO2047), offset: 0x23C */
  uint32_t RMON_T_P_GTE2048;                       /**< RMON Tx packets w > 2048 bytes (RMON_T_P_GTE2048), offset: 0x240 */
  uint32_t RMON_T_OCTETS;                          /**< RMON Tx Octets (RMON_T_OCTETS), offset: 0x244 */
  uint32_t IEEE_T_DROP;                            /**< Count of frames not counted correctly (IEEE_T_DROP). NOTE: Counter not implemented (read 0 always) as not applicable., offset: 0x248 */
  uint32_t IEEE_T_FRAME_OK;                        /**< Frames Transmitted OK (IEEE_T_FRAME_OK), offset: 0x24C */
  uint32_t IEEE_T_1COL;                            /**< Frames Transmitted with Single Collision (IEEE_T_1COL), offset: 0x250 */
  uint32_t IEEE_T_MCOL;                            /**< Frames Transmitted with Multiple Collisions (IEEE_T_MCOL), offset: 0x254 */
  uint32_t IEEE_T_DEF;                             /**< Frames Transmitted after Deferral Delay (IEEE_T_DEF), offset: 0x258 */
  uint32_t IEEE_T_LCOL;                            /**< Frames Transmitted with Late Collision (IEEE_T_LCOL), offset: 0x25C */
  uint32_t IEEE_T_EXCOL;                           /**< Frames Transmitted with Excessive Collisions (IEEE_T_EXCOL), offset: 0x260 */
  uint32_t IEEE_T_MACERR;                          /**< Frames Transmitted with Tx FIFO Underrun (IEEE_T_MACERR), offset: 0x264 */
  uint32_t IEEE_T_CSERR;                           /**< Frames Transmitted with Carrier Sense Error (IEEE_T_CSERR), offset: 0x268 */
  uint32_t IEEE_T_SQE;                             /**< Frames Transmitted with SQE Error (IEEE_T_SQE). NOTE: Counter not implemented (read 0 always) as no SQE information is available., offset: 0x26C */
  uint32_t IEEE_T_FDXFC;                           /**< Flow Control Pause frames transmitted (IEEE_T_FDXFC), offset: 0x270 */
  uint32_t IEEE_T_OCTETS_OK;                       /**< Octet count for Frames Transmitted w/o Error (IEEE_T_OCTETS_OK). NOTE: Counts total octets (includes header and FCS fields)., offset: 0x274 */
  uint8_t RESERVED_14[12];
  uint32_t RMON_R_PACKETS;                         /**< RMON Rx packet count (RMON_R_PACKETS), offset: 0x284 */
  uint32_t RMON_R_BC_PKT;                          /**< RMON Rx Broadcast Packets (RMON_R_BC_PKT), offset: 0x288 */
  uint32_t RMON_R_MC_PKT;                          /**< RMON Rx Multicast Packets (RMON_R_MC_PKT), offset: 0x28C */
  uint32_t RMON_R_CRC_ALIGN;                       /**< RMON Rx Packets w CRC/Align error (RMON_R_CRC_ALIGN), offset: 0x290 */
  uint32_t RMON_R_UNDERSIZE;                       /**< RMON Rx Packets < 64 bytes, good CRC (RMON_R_UNDERSIZE), offset: 0x294 */
  uint32_t RMON_R_OVERSIZE;                        /**< RMON Rx Packets > MAX_FL bytes, good CRC (RMON_R_OVERSIZE), offset: 0x298 */
  uint32_t RMON_R_FRAG;                            /**< RMON Rx Packets < 64 bytes, bad CRC (RMON_R_FRAG), offset: 0x29C */
  uint32_t RMON_R_JAB;                             /**< RMON Rx Packets > MAX_FL bytes, bad CRC (RMON_R_JAB), offset: 0x2A0 */
  uint32_t RMON_R_RESVD_0;                         /**< Reserved (RMON_R_RESVD_0), offset: 0x2A4 */
  uint32_t RMON_R_P64;                             /**< RMON Rx 64 byte packets (RMON_R_P64), offset: 0x2A8 */
  uint32_t RMON_R_P65TO127;                        /**< RMON Rx 65 to 127 byte packets (RMON_R_P65TO127), offset: 0x2AC */
  uint32_t RMON_R_P128TO255;                       /**< RMON Rx 128 to 255 byte packets (RMON_R_P128TO255), offset: 0x2B0 */
  uint32_t RMON_R_P256TO511;                       /**< RMON Rx 256 to 511 byte packets (RMON_R_P256TO511), offset: 0x2B4 */
  uint32_t RMON_R_P512TO1023;                      /**< RMON Rx 512 to 1023 byte packets (RMON_R_P512TO1023), offset: 0x2B8 */
  uint32_t RMON_R_P1024TO2047;                     /**< RMON Rx 1024 to 2047 byte packets (RMON_R_P1024TO2047), offset: 0x2BC */
  uint32_t RMON_R_P_GTE2048;                       /**< RMON Rx packets w > 2048 bytes (RMON_R_P_GTE2048), offset: 0x2C0 */
  uint32_t RMON_R_OCTETS;                          /**< RMON Rx Octets (RMON_R_OCTETS), offset: 0x2C4 */
  uint32_t RMON_R_DROP;                            /**< Count of frames not counted correctly (IEEE_R_DROP). NOTE: Counter increments if a frame with valid/missing SFD character is detected and has been dropped. None of the other counters increments if this counter increments., offset: 0x2C8 */
  uint32_t RMON_R_FRAME_OK;                        /**< Frames Received OK (IEEE_R_FRAME_OK), offset: 0x2CC */
  uint32_t IEEE_R_CRC;                             /**< Frames Received with CRC Error (IEEE_R_CRC), offset: 0x2D0 */
  uint32_t IEEE_R_ALIGN;                           /**< Frames Received with Alignment Error (IEEE_R_ALIGN), offset: 0x2D4 */
  uint32_t IEEE_R_MACERR;                          /**< Receive Fifo Overflow count (IEEE_R_MACERR), offset: 0x2D8 */
  uint32_t IEEE_R_FDXFC;                           /**< Flow Control Pause frames received (IEEE_R_FDXFC), offset: 0x2DC */
  uint32_t IEEE_R_OCTETS_OK;                       /**< Octet count for Frames Rcvd w/o Error (IEEE_R_OCTETS_OK). Counts total octets (includes header and FCS fields)., offset: 0x2E0 */
  uint8_t RESERVED_15[284];
  uint32_t ATCR;                                   /**< Timer Control Register, offset: 0x400 */
  uint32_t ATVR;                                   /**< Timer Value Register, offset: 0x404 */
  uint32_t ATOFF;                                  /**< Timer Offset Register, offset: 0x408 */
  uint32_t ATPER;                                  /**< Timer Period Register, offset: 0x40C */
  uint32_t ATCOR;                                  /**< Timer Correction Register, offset: 0x410 */
  uint32_t ATINC;                                  /**< Time-Stamping Clock Period Register, offset: 0x414 */
  uint32_t ATSTMP;                                 /**< Timestamp of Last Transmitted Frame, offset: 0x418 */
  uint8_t RESERVED_16[488];
  uint32_t TGSR;                                   /**< Timer Global Status Register, offset: 0x604 */
  struct {                                         /* offset: 0x608, array step: 0x8 */
    uint32_t TCSR;                                   /**< Timer Control Status Register, array offset: 0x608, array step: 0x8 */
    uint32_t TCCR;                                   /**< Timer Compare Capture Register, array offset: 0x60C, array step: 0x8 */
  } CHANNEL[4];
} volatile *ENET_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ENET - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ENET_Register_Accessor_Macros ENET - Register accessor macros
 * @{
 */


/* ENET - Register accessors */
#line 6992 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ENET_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ENET Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ENET_Register_Masks ENET Register Masks
 * @{
 */

/* EIR Bit Fields */
#line 7040 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EIMR Bit Fields */
#line 7073 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RDAR Bit Fields */


/* TDAR Bit Fields */


/* ECR Bit Fields */
#line 7096 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MMFR Bit Fields */
#line 7115 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MSCR Bit Fields */
#line 7124 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MIBC Bit Fields */
#line 7131 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RCR Bit Fields */
#line 7163 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCR Bit Fields */
#line 7179 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PALR Bit Fields */



/* PAUR Bit Fields */
#line 7190 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OPD Bit Fields */
#line 7197 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IAUR Bit Fields */



/* IALR Bit Fields */



/* GAUR Bit Fields */



/* GALR Bit Fields */



/* TFWR Bit Fields */





/* RDSR Bit Fields */



/* TDSR Bit Fields */



/* MRBR Bit Fields */



/* RSFL Bit Fields */



/* RSEM Bit Fields */



/* RAEM Bit Fields */



/* RAFL Bit Fields */



/* TSEM Bit Fields */



/* TAEM Bit Fields */



/* TAFL Bit Fields */



/* TIPG Bit Fields */



/* FTRL Bit Fields */



/* TACC Bit Fields */
#line 7274 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RACC Bit Fields */
#line 7285 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ATCR Bit Fields */
#line 7302 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ATVR Bit Fields */



/* ATOFF Bit Fields */



/* ATPER Bit Fields */



/* ATCOR Bit Fields */



/* ATINC Bit Fields */
#line 7325 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ATSTMP Bit Fields */



/* TGSR Bit Fields */
#line 7338 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCSR Bit Fields */
#line 7348 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCCR Bit Fields */




/**
 * @}
 */ /* end of group ENET_Register_Masks */


/* ENET - Peripheral instance base addresses */
/** Peripheral ENET base pointer */


/* ----------------------------------------------------------------------------
   -- ENET - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ENET_Register_Accessor_Macros ENET - Register accessor macros
 * @{
 */


/* ENET - Register instance definitions */
/* ENET */
#line 7476 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* ENET - Register array accessors */



/**
 * @}
 */ /* end of group ENET_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ENET_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Peripheral ETB
 * @{
 */

/** ETB - Peripheral register structure */
typedef struct ETB_MemMap {
  uint8_t RESERVED_0[4];
  uint32_t RDP;                                    /**< RAM Depth Register, offset: 0x4 */
  uint8_t RESERVED_1[4];
  uint32_t STS;                                    /**< Status Register, offset: 0xC */
  uint32_t RRD;                                    /**< RAM Read Data Register, offset: 0x10 */
  uint32_t RRP;                                    /**< RAM Read Pointer Register, offset: 0x14 */
  uint32_t RWP;                                    /**< RAM Write Pointer Register, offset: 0x18 */
  uint32_t TRG;                                    /**< Trigger Counter Register, offset: 0x1C */
  uint32_t CTL;                                    /**< Control Register, offset: 0x20 */
  uint32_t RWD;                                    /**< RAM Write Data Register, offset: 0x24 */
  uint8_t RESERVED_2[728];
  uint32_t FFSR;                                   /**< Formatter and Flush Status Register, offset: 0x300 */
  uint32_t FFCR;                                   /**< Formatter and Flush Control Register, offset: 0x304 */
  uint8_t RESERVED_3[3032];
  uint32_t ITMISCOP0;                              /**< Integration Register, ITMISCOP0, offset: 0xEE0 */
  uint32_t ITTRFLINACK;                            /**< Integration Register, ITTRFLINACK, offset: 0xEE4 */
  uint32_t ITTRFLIN;                               /**< Integration Register, ITTRFLIN, offset: 0xEE8 */
  uint32_t ITATBDATA0;                             /**< Integration Register, ITATBDATA0, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Register, ITATBCTR2, offset: 0xEF0 */
  uint32_t ITATBCTR1;                              /**< Integration Register, ITATBCTR1, offset: 0xEF4 */
  uint32_t ITATBCTR0;                              /**< Integration Register, ITATBCTR0, offset: 0xEF8 */
  uint8_t RESERVED_4[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_6[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_7[12];
  uint32_t DEVID;                                  /**< Device ID Register, offset: 0xFC8 */
  uint32_t DEVTYPE;                                /**< Device Type Identifier Register, offset: 0xFCC */
  uint32_t PIDR4;                                  /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Register_Accessor_Macros ETB - Register accessor macros
 * @{
 */


/* ETB - Register accessors */
#line 7597 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ETB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Register_Masks ETB Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ETB_Register_Masks */


/* ETB - Peripheral instance base addresses */
/** Peripheral ETB base pointer */


/* ----------------------------------------------------------------------------
   -- ETB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Register_Accessor_Macros ETB - Register accessor macros
 * @{
 */


/* ETB - Register instance definitions */
/* ETB */
#line 7671 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ETB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ETB_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETF
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Peripheral ETF
 * @{
 */

/** ETF - Peripheral register structure */
typedef struct ETF_MemMap {
  uint32_t FCR;                                    /**< Funnel Control Register, offset: 0x0 */
  uint32_t PCR;                                    /**< Priority Control Register, offset: 0x4 */
  uint8_t RESERVED_0[3812];
  uint32_t ITATBDATA0;                             /**< Integration Register, ITATBDATA0, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Register, ITATBCTR2, offset: 0xEF0 */
  uint32_t ITATBCTR1;                              /**< Integration Register, ITATBCTR1, offset: 0xEF4 */
  uint32_t ITATBCTR0;                              /**< Integration Register, ITATBCTR0, offset: 0xEF8 */
  uint8_t RESERVED_1[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_2[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_3[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_4[12];
  uint32_t DEVID;                                  /**< Device ID Register, offset: 0xFC8 */
  uint32_t DEVTYPE;                                /**< Device Type Identifier Register, offset: 0xFCC */
  uint32_t PIDR4;                                  /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Register_Accessor_Macros ETF - Register accessor macros
 * @{
 */


/* ETF - Register accessors */
#line 7763 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ETF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETF Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Register_Masks ETF Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ETF_Register_Masks */


/* ETF - Peripheral instance base addresses */
/** Peripheral ETF base pointer */


/* ----------------------------------------------------------------------------
   -- ETF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Register_Accessor_Macros ETF - Register accessor macros
 * @{
 */


/* ETF - Register instance definitions */
/* ETF */
#line 7826 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ETF_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ETF_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Peripheral ETM
 * @{
 */

/** ETM - Peripheral register structure */
typedef struct ETM_MemMap {
  uint32_t CR;                                     /**< Main Control Register, offset: 0x0 */
  uint32_t CCR;                                    /**< Configuration Code Register, offset: 0x4 */
  uint32_t TRIGGER;                                /**< Trigger Event Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t SR;                                     /**< ETM Status Register, offset: 0x10 */
  uint32_t SCR;                                    /**< System Configuration Register, offset: 0x14 */
  uint8_t RESERVED_1[8];
  uint32_t EEVR;                                   /**< Trace Enable Event Register, offset: 0x20 */
  uint32_t TECR1;                                  /**< Trace Enable Control 1 Register, offset: 0x24 */
  uint32_t FFLR;                                   /**< FIFOFULL Level Register, offset: 0x28 */
  uint8_t RESERVED_2[276];
  uint32_t CNTRLDVR1;                              /**< Free-running counter reload value, offset: 0x140 */
  uint8_t RESERVED_3[156];
  uint32_t SYNCFR;                                 /**< Synchronization Frequency Register, offset: 0x1E0 */
  uint32_t IDR;                                    /**< ID Register, offset: 0x1E4 */
  uint32_t CCER;                                   /**< Configuration Code Extension Register, offset: 0x1E8 */
  uint8_t RESERVED_4[4];
  uint32_t TESSEICR;                               /**< TraceEnable Start/Stop EmbeddedICE Control Register, offset: 0x1F0 */
  uint8_t RESERVED_5[4];
  uint32_t TSEVR;                                  /**< Timestamp Event Register, offset: 0x1F8 */
  uint8_t RESERVED_6[4];
  uint32_t TRACEIDR;                               /**< CoreSight Trace ID Register, offset: 0x200 */
  uint8_t RESERVED_7[4];
  uint32_t IDR2;                                   /**< ETM ID Register 2, offset: 0x208 */
  uint8_t RESERVED_8[264];
  uint32_t PDSR;                                   /**< Device Power-Down Status Register, offset: 0x314 */
  uint8_t RESERVED_9[3016];
  uint32_t ITMISCIN;                               /**< Integration Test Miscelaneous Inputs Register, offset: 0xEE0 */
  uint8_t RESERVED_10[4];
  uint32_t ITTRIGOUT;                              /**< Integration Test Trigger Out Register, offset: 0xEE8 */
  uint8_t RESERVED_11[4];
  uint32_t ITATBCTR2;                              /**< ETM Integration Test ATB Control 2 Register, offset: 0xEF0 */
  uint8_t RESERVED_12[4];
  uint32_t ITATBCTR0;                              /**< ETM Integration Test ATB Control 0 Register, offset: 0xEF8 */
  uint8_t RESERVED_13[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_14[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_15[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_16[16];
  uint32_t DEVTYPE;                                /**< CoreSight Device Type Register, offset: 0xFCC */
  uint32_t PIDR4;                                  /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Register_Accessor_Macros ETM - Register accessor macros
 * @{
 */


/* ETM - Register accessors */
#line 7958 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ETM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Register_Masks ETM Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ETM_Register_Masks */


/* ETM - Peripheral instance base addresses */
/** Peripheral ETM base pointer */


/* ----------------------------------------------------------------------------
   -- ETM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Register_Accessor_Macros ETM - Register accessor macros
 * @{
 */


/* ETM - Register instance definitions */
/* ETM */
#line 8035 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ETM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ETM_Peripheral */


/* ----------------------------------------------------------------------------
   -- EWM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Peripheral EWM
 * @{
 */

/** EWM - Peripheral register structure */
typedef struct EWM_MemMap {
  uint8_t CTRL;                                    /**< Control Register, offset: 0x0 */
  uint8_t SERV;                                    /**< Service Register, offset: 0x1 */
  uint8_t CMPL;                                    /**< Compare Low Register, offset: 0x2 */
  uint8_t CMPH;                                    /**< Compare High Register, offset: 0x3 */
} volatile *EWM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros
 * @{
 */


/* EWM - Register accessors */





/**
 * @}
 */ /* end of group EWM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/* CTRL Bit Fields */
#line 8100 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SERV Bit Fields */



/* CMPL Bit Fields */



/* CMPH Bit Fields */




/**
 * @}
 */ /* end of group EWM_Register_Masks */


/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base pointer */


/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros
 * @{
 */


/* EWM - Register instance definitions */
/* EWM */





/**
 * @}
 */ /* end of group EWM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group EWM_Peripheral */


/* ----------------------------------------------------------------------------
   -- FB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_Peripheral FB
 * @{
 */

/** FB - Peripheral register structure */
typedef struct FB_MemMap {
  struct {                                         /* offset: 0x0, array step: 0xC */
    uint32_t CSAR;                                   /**< Chip select address register, array offset: 0x0, array step: 0xC */
    uint32_t CSMR;                                   /**< Chip select mask register, array offset: 0x4, array step: 0xC */
    uint32_t CSCR;                                   /**< Chip select control register, array offset: 0x8, array step: 0xC */
  } CS[6];
  uint8_t RESERVED_0[24];
  uint32_t CSPMCR;                                 /**< Chip select port multiplexing control register, offset: 0x60 */
} volatile *FB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_Register_Accessor_Macros FB - Register accessor macros
 * @{
 */


/* FB - Register accessors */





/**
 * @}
 */ /* end of group FB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_Register_Masks FB Register Masks
 * @{
 */

/* CSAR Bit Fields */



/* CSMR Bit Fields */
#line 8211 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CSCR Bit Fields */
#line 8244 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CSPMCR Bit Fields */
#line 8260 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FB_Register_Masks */


/* FB - Peripheral instance base addresses */
/** Peripheral FB base pointer */


/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_Register_Accessor_Macros FB - Register accessor macros
 * @{
 */


/* FB - Register instance definitions */
/* FB */
#line 8301 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* FB - Register array accessors */




/**
 * @}
 */ /* end of group FB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FB_Peripheral */


/* ----------------------------------------------------------------------------
   -- FMC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Peripheral FMC
 * @{
 */

/** FMC - Peripheral register structure */
typedef struct FMC_MemMap {
  uint32_t PFAPR;                                  /**< Flash Access Protection Register, offset: 0x0 */
  uint32_t PFB01CR;                                /**< Flash Bank 0-1 Control Register, offset: 0x4 */
  uint32_t PFB23CR;                                /**< Flash Bank 2-3 Control Register, offset: 0x8 */
  uint8_t RESERVED_0[244];
  uint32_t TAGVD[4][4];                            /**< Cache Tag Storage, array offset: 0x100, array step: index*0x10, index2*0x4 */
  uint8_t RESERVED_1[192];
  struct {                                         /* offset: 0x200, array step: index*0x40, index2*0x10 */
    uint32_t DATA_UM;                                /**< Cache Data Storage (uppermost word), array offset: 0x200, array step: index*0x40, index2*0x10 */
    uint32_t DATA_MU;                                /**< Cache Data Storage (mid-upper word), array offset: 0x204, array step: index*0x40, index2*0x10 */
    uint32_t DATA_ML;                                /**< Cache Data Storage (mid-lower word), array offset: 0x208, array step: index*0x40, index2*0x10 */
    uint32_t DATA_LM;                                /**< Cache Data Storage (lowermost word), array offset: 0x20C, array step: index*0x40, index2*0x10 */
  } SET[4][4];
} volatile *FMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros
 * @{
 */


/* FMC - Register accessors */
#line 8361 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/* PFAPR Bit Fields */
#line 8417 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PFB01CR Bit Fields */
#line 8445 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PFB23CR Bit Fields */
#line 8462 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TAGVD Bit Fields */





/* DATA_UM Bit Fields */



/* DATA_MU Bit Fields */



/* DATA_ML Bit Fields */



/* DATA_LM Bit Fields */




/**
 * @}
 */ /* end of group FMC_Register_Masks */


/* FMC - Peripheral instance base addresses */
/** Peripheral FMC base pointer */


/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros
 * @{
 */


/* FMC - Register instance definitions */
/* FMC */
#line 8589 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* FMC - Register array accessors */






/**
 * @}
 */ /* end of group FMC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- FPB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Peripheral FPB
 * @{
 */

/** FPB - Peripheral register structure */
typedef struct FPB_MemMap {
  uint32_t CTRL;                                   /**< FlashPatch Control Register, offset: 0x0 */
  uint32_t REMAP;                                  /**< FlashPatch Remap Register, offset: 0x4 */
  uint32_t COMP[8];                                /**< FlashPatch Comparator Register 0..FlashPatch Comparator Register 7, array offset: 0x8, array step: 0x4 */
  uint8_t RESERVED_0[4008];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *FPB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FPB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Register_Accessor_Macros FPB - Register accessor macros
 * @{
 */


/* FPB - Register accessors */
#line 8662 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FPB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FPB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Register_Masks FPB Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group FPB_Register_Masks */


/* FPB - Peripheral instance base addresses */
/** Peripheral FPB base pointer */


/* ----------------------------------------------------------------------------
   -- FPB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Register_Accessor_Macros FPB - Register accessor macros
 * @{
 */


/* FPB - Register instance definitions */
/* FPB */
#line 8721 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* FPB - Register array accessors */


/**
 * @}
 */ /* end of group FPB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FPB_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTFE
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFE_Peripheral FTFE
 * @{
 */

/** FTFE - Peripheral register structure */
typedef struct FTFE_MemMap {
  uint8_t FSTAT;                                   /**< Flash Status Register, offset: 0x0 */
  uint8_t FCNFG;                                   /**< Flash Configuration Register, offset: 0x1 */
  uint8_t FSEC;                                    /**< Flash Security Register, offset: 0x2 */
  uint8_t FOPT;                                    /**< Flash Option Register, offset: 0x3 */
  uint8_t FCCOB3;                                  /**< Flash Common Command Object Registers, offset: 0x4 */
  uint8_t FCCOB2;                                  /**< Flash Common Command Object Registers, offset: 0x5 */
  uint8_t FCCOB1;                                  /**< Flash Common Command Object Registers, offset: 0x6 */
  uint8_t FCCOB0;                                  /**< Flash Common Command Object Registers, offset: 0x7 */
  uint8_t FCCOB7;                                  /**< Flash Common Command Object Registers, offset: 0x8 */
  uint8_t FCCOB6;                                  /**< Flash Common Command Object Registers, offset: 0x9 */
  uint8_t FCCOB5;                                  /**< Flash Common Command Object Registers, offset: 0xA */
  uint8_t FCCOB4;                                  /**< Flash Common Command Object Registers, offset: 0xB */
  uint8_t FCCOBB;                                  /**< Flash Common Command Object Registers, offset: 0xC */
  uint8_t FCCOBA;                                  /**< Flash Common Command Object Registers, offset: 0xD */
  uint8_t FCCOB9;                                  /**< Flash Common Command Object Registers, offset: 0xE */
  uint8_t FCCOB8;                                  /**< Flash Common Command Object Registers, offset: 0xF */
  uint8_t FPROT3;                                  /**< Program Flash Protection Registers, offset: 0x10 */
  uint8_t FPROT2;                                  /**< Program Flash Protection Registers, offset: 0x11 */
  uint8_t FPROT1;                                  /**< Program Flash Protection Registers, offset: 0x12 */
  uint8_t FPROT0;                                  /**< Program Flash Protection Registers, offset: 0x13 */
  uint8_t RESERVED_0[2];
  uint8_t FEPROT;                                  /**< EEPROM Protection Register, offset: 0x16 */
  uint8_t FDPROT;                                  /**< Data Flash Protection Register, offset: 0x17 */
} volatile *FTFE_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTFE - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFE_Register_Accessor_Macros FTFE - Register accessor macros
 * @{
 */


/* FTFE - Register accessors */
#line 8804 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FTFE_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTFE Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFE_Register_Masks FTFE Register Masks
 * @{
 */

/* FSTAT Bit Fields */
#line 8830 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FCNFG Bit Fields */
#line 8847 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FSEC Bit Fields */
#line 8860 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FOPT Bit Fields */



/* FCCOB3 Bit Fields */



/* FCCOB2 Bit Fields */



/* FCCOB1 Bit Fields */



/* FCCOB0 Bit Fields */



/* FCCOB7 Bit Fields */



/* FCCOB6 Bit Fields */



/* FCCOB5 Bit Fields */



/* FCCOB4 Bit Fields */



/* FCCOBB Bit Fields */



/* FCCOBA Bit Fields */



/* FCCOB9 Bit Fields */



/* FCCOB8 Bit Fields */



/* FPROT3 Bit Fields */



/* FPROT2 Bit Fields */



/* FPROT1 Bit Fields */



/* FPROT0 Bit Fields */



/* FEPROT Bit Fields */



/* FDPROT Bit Fields */




/**
 * @}
 */ /* end of group FTFE_Register_Masks */


/* FTFE - Peripheral instance base addresses */
/** Peripheral FTFE base pointer */


/* ----------------------------------------------------------------------------
   -- FTFE - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFE_Register_Accessor_Macros FTFE - Register accessor macros
 * @{
 */


/* FTFE - Register instance definitions */
/* FTFE */
#line 8980 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FTFE_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FTFE_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Peripheral FTM
 * @{
 */

/** FTM - Peripheral register structure */
typedef struct FTM_MemMap {
  uint32_t SC;                                     /**< Status and Control, offset: 0x0 */
  uint32_t CNT;                                    /**< Counter, offset: 0x4 */
  uint32_t MOD;                                    /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    uint32_t CnSC;                                   /**< Channel (n) Status and Control, array offset: 0xC, array step: 0x8 */
    uint32_t CnV;                                    /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[8];
  uint32_t CNTIN;                                  /**< Counter Initial Value, offset: 0x4C */
  uint32_t STATUS;                                 /**< Capture and Compare Status, offset: 0x50 */
  uint32_t MODE;                                   /**< Features Mode Selection, offset: 0x54 */
  uint32_t SYNC;                                   /**< Synchronization, offset: 0x58 */
  uint32_t OUTINIT;                                /**< Initial State for Channels Output, offset: 0x5C */
  uint32_t OUTMASK;                                /**< Output Mask, offset: 0x60 */
  uint32_t COMBINE;                                /**< Function for Linked Channels, offset: 0x64 */
  uint32_t DEADTIME;                               /**< Deadtime Insertion Control, offset: 0x68 */
  uint32_t EXTTRIG;                                /**< FTM External Trigger, offset: 0x6C */
  uint32_t POL;                                    /**< Channels Polarity, offset: 0x70 */
  uint32_t FMS;                                    /**< Fault Mode Status, offset: 0x74 */
  uint32_t FILTER;                                 /**< Input Capture Filter Control, offset: 0x78 */
  uint32_t FLTCTRL;                                /**< Fault Control, offset: 0x7C */
  uint32_t QDCTRL;                                 /**< Quadrature Decoder Control and Status, offset: 0x80 */
  uint32_t CONF;                                   /**< Configuration, offset: 0x84 */
  uint32_t FLTPOL;                                 /**< FTM Fault Input Polarity, offset: 0x88 */
  uint32_t SYNCONF;                                /**< Synchronization Configuration, offset: 0x8C */
  uint32_t INVCTRL;                                /**< FTM Inverting Control, offset: 0x90 */
  uint32_t SWOCTRL;                                /**< FTM Software Output Control, offset: 0x94 */
  uint32_t PWMLOAD;                                /**< FTM PWM Load, offset: 0x98 */
} volatile *FTM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register accessors */
#line 9067 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/* SC Bit Fields */
#line 9095 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNT Bit Fields */



/* MOD Bit Fields */



/* CnSC Bit Fields */
#line 9118 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CnV Bit Fields */



/* CNTIN Bit Fields */



/* STATUS Bit Fields */
#line 9143 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MODE Bit Fields */
#line 9159 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SYNC Bit Fields */
#line 9176 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OUTINIT Bit Fields */
#line 9193 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OUTMASK Bit Fields */
#line 9210 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* COMBINE Bit Fields */
#line 9267 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DEADTIME Bit Fields */
#line 9274 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EXTTRIG Bit Fields */
#line 9291 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* POL Bit Fields */
#line 9308 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FMS Bit Fields */
#line 9323 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FILTER Bit Fields */
#line 9336 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FLTCTRL Bit Fields */
#line 9356 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* QDCTRL Bit Fields */
#line 9373 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CONF Bit Fields */
#line 9384 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FLTPOL Bit Fields */
#line 9393 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SYNCONF Bit Fields */
#line 9424 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* INVCTRL Bit Fields */
#line 9433 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SWOCTRL Bit Fields */
#line 9466 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PWMLOAD Bit Fields */
#line 9485 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FTM_Register_Masks */


/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base pointer */

/** Peripheral FTM1 base pointer */

/** Peripheral FTM2 base pointer */

/** Peripheral FTM3 base pointer */


/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register instance definitions */
/* FTM0 */
#line 9552 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FTM1 */
#line 9580 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FTM2 */
#line 9608 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FTM3 */
#line 9648 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* FTM - Register array accessors */
#line 9658 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FTM_Peripheral */


/* ----------------------------------------------------------------------------
   -- GPIO
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Peripheral GPIO
 * @{
 */

/** GPIO - Peripheral register structure */
typedef struct GPIO_MemMap {
  uint32_t PDOR;                                   /**< Port Data Output Register, offset: 0x0 */
  uint32_t PSOR;                                   /**< Port Set Output Register, offset: 0x4 */
  uint32_t PCOR;                                   /**< Port Clear Output Register, offset: 0x8 */
  uint32_t PTOR;                                   /**< Port Toggle Output Register, offset: 0xC */
  uint32_t PDIR;                                   /**< Port Data Input Register, offset: 0x10 */
  uint32_t PDDR;                                   /**< Port Data Direction Register, offset: 0x14 */
} volatile *GPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register accessors */
#line 9705 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */



/* PSOR Bit Fields */



/* PCOR Bit Fields */



/* PTOR Bit Fields */



/* PDIR Bit Fields */



/* PDDR Bit Fields */




/**
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral PTA base pointer */

/** Peripheral PTB base pointer */

/** Peripheral PTC base pointer */

/** Peripheral PTD base pointer */

/** Peripheral PTE base pointer */

/** Peripheral PTF base pointer */


/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register instance definitions */
/* PTA */
#line 9782 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PTB */
#line 9789 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PTC */
#line 9796 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PTD */
#line 9803 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PTE */
#line 9810 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PTF */
#line 9817 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group GPIO_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2C
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Peripheral I2C
 * @{
 */

/** I2C - Peripheral register structure */
typedef struct I2C_MemMap {
  uint8_t A1;                                      /**< I2C Address Register 1, offset: 0x0 */
  uint8_t F;                                       /**< I2C Frequency Divider register, offset: 0x1 */
  uint8_t C1;                                      /**< I2C Control Register 1, offset: 0x2 */
  uint8_t S;                                       /**< I2C Status Register, offset: 0x3 */
  uint8_t D;                                       /**< I2C Data I/O register, offset: 0x4 */
  uint8_t C2;                                      /**< I2C Control Register 2, offset: 0x5 */
  uint8_t FLT;                                     /**< I2C Programmable Input Glitch Filter register, offset: 0x6 */
  uint8_t RA;                                      /**< I2C Range Address register, offset: 0x7 */
  uint8_t SMB;                                     /**< I2C SMBus Control and Status register, offset: 0x8 */
  uint8_t A2;                                      /**< I2C Address Register 2, offset: 0x9 */
  uint8_t SLTH;                                    /**< I2C SCL Low Timeout Register High, offset: 0xA */
  uint8_t SLTL;                                    /**< I2C SCL Low Timeout Register Low, offset: 0xB */
} volatile *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register accessors */
#line 9876 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/* A1 Bit Fields */



/* F Bit Fields */
#line 9902 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C1 Bit Fields */
#line 9919 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* S Bit Fields */
#line 9936 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* D Bit Fields */



/* C2 Bit Fields */
#line 9954 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FLT Bit Fields */



/* RA Bit Fields */



/* SMB Bit Fields */
#line 9979 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* A2 Bit Fields */



/* SLTH Bit Fields */



/* SLTL Bit Fields */




/**
 * @}
 */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base pointer */

/** Peripheral I2C1 base pointer */


/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register instance definitions */
/* I2C0 */
#line 10027 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* I2C1 */
#line 10040 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group I2C_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2S
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Peripheral I2S
 * @{
 */

/** I2S - Peripheral register structure */
typedef struct I2S_MemMap {
  uint32_t TCSR;                                   /**< SAI Transmit Control Register, offset: 0x0 */
  uint32_t TCR1;                                   /**< SAI Transmit Configuration 1 Register, offset: 0x4 */
  uint32_t TCR2;                                   /**< SAI Transmit Configuration 2 Register, offset: 0x8 */
  uint32_t TCR3;                                   /**< SAI Transmit Configuration 3 Register, offset: 0xC */
  uint32_t TCR4;                                   /**< SAI Transmit Configuration 4 Register, offset: 0x10 */
  uint32_t TCR5;                                   /**< SAI Transmit Configuration 5 Register, offset: 0x14 */
  uint8_t RESERVED_0[8];
  uint32_t TDR[2];                                 /**< SAI Transmit Data Register, array offset: 0x20, array step: 0x4 */
  uint8_t RESERVED_1[24];
  uint32_t TFR[2];                                 /**< SAI Transmit FIFO Register, array offset: 0x40, array step: 0x4 */
  uint8_t RESERVED_2[24];
  uint32_t TMR;                                    /**< SAI Transmit Mask Register, offset: 0x60 */
  uint8_t RESERVED_3[28];
  uint32_t RCSR;                                   /**< SAI Receive Control Register, offset: 0x80 */
  uint32_t RCR1;                                   /**< SAI Receive Configuration 1 Register, offset: 0x84 */
  uint32_t RCR2;                                   /**< SAI Receive Configuration 2 Register, offset: 0x88 */
  uint32_t RCR3;                                   /**< SAI Receive Configuration 3 Register, offset: 0x8C */
  uint32_t RCR4;                                   /**< SAI Receive Configuration 4 Register, offset: 0x90 */
  uint32_t RCR5;                                   /**< SAI Receive Configuration 5 Register, offset: 0x94 */
  uint8_t RESERVED_4[8];
  uint32_t RDR[2];                                 /**< SAI Receive Data Register, array offset: 0xA0, array step: 0x4 */
  uint8_t RESERVED_5[24];
  uint32_t RFR[2];                                 /**< SAI Receive FIFO Register, array offset: 0xC0, array step: 0x4 */
  uint8_t RESERVED_6[24];
  uint32_t RMR;                                    /**< SAI Receive Mask Register, offset: 0xE0 */
  uint8_t RESERVED_7[28];
  uint32_t MCR;                                    /**< SAI MCLK Control Register, offset: 0x100 */
  uint32_t MDR;                                    /**< MCLK Divide Register, offset: 0x104 */
} volatile *I2S_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros
 * @{
 */


/* I2S - Register accessors */
#line 10123 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group I2S_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Register_Masks I2S Register Masks
 * @{
 */

/* TCSR Bit Fields */
#line 10175 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCR1 Bit Fields */



/* TCR2 Bit Fields */
#line 10197 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCR3 Bit Fields */
#line 10204 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCR4 Bit Fields */
#line 10219 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCR5 Bit Fields */
#line 10229 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TDR Bit Fields */



/* TFR Bit Fields */
#line 10240 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TMR Bit Fields */



/* RCSR Bit Fields */
#line 10281 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RCR1 Bit Fields */



/* RCR2 Bit Fields */
#line 10303 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RCR3 Bit Fields */
#line 10310 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RCR4 Bit Fields */
#line 10325 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RCR5 Bit Fields */
#line 10335 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RDR Bit Fields */



/* RFR Bit Fields */
#line 10346 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RMR Bit Fields */



/* MCR Bit Fields */
#line 10358 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MDR Bit Fields */
#line 10365 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base pointer */

/** Peripheral I2S1 base pointer */


/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros
 * @{
 */


/* I2S - Register instance definitions */
/* I2S0 */
#line 10413 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* I2S1 */
#line 10438 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* I2S - Register array accessors */
#line 10448 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group I2S_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group I2S_Peripheral */


/* ----------------------------------------------------------------------------
   -- ITM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Peripheral ITM
 * @{
 */

/** ITM - Peripheral register structure */
typedef struct ITM_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t STIM_READ[32];                          /**< Stimulus Port Register 0 (for reading)..Stimulus Port Register 31 (for reading), array offset: 0x0, array step: 0x4 */
    uint32_t STIM_WRITE[32];                         /**< Stimulus Port Register 0 (for writing)..Stimulus Port Register 31 (for writing), array offset: 0x0, array step: 0x4 */
  };
  uint8_t RESERVED_0[3456];
  uint32_t TER;                                    /**< Trace Enable Register, offset: 0xE00 */
  uint8_t RESERVED_1[60];
  uint32_t TPR;                                    /**< Trace Privilege Register, offset: 0xE40 */
  uint8_t RESERVED_2[60];
  uint32_t TCR;                                    /**< Trace Control Register, offset: 0xE80 */
  uint8_t RESERVED_3[300];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint8_t RESERVED_4[24];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *ITM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ITM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Register_Accessor_Macros ITM - Register accessor macros
 * @{
 */


/* ITM - Register accessors */
#line 10528 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group ITM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ITM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Register_Masks ITM Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ITM_Register_Masks */


/* ITM - Peripheral instance base addresses */
/** Peripheral ITM base pointer */


/* ----------------------------------------------------------------------------
   -- ITM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Register_Accessor_Macros ITM - Register accessor macros
 * @{
 */


/* ITM - Register instance definitions */
/* ITM */
#line 10646 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* ITM - Register array accessors */



/**
 * @}
 */ /* end of group ITM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ITM_Peripheral */


/* ----------------------------------------------------------------------------
   -- LCDC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LCDC_Peripheral LCDC
 * @{
 */

/** LCDC - Peripheral register structure */
typedef struct LCDC_MemMap {
  uint32_t LSSAR;                                  /**< LCDC screen start address register, offset: 0x0 */
  uint32_t LSR;                                    /**< LCDC size register, offset: 0x4 */
  uint32_t LVPWR;                                  /**< LCDC virtual page width register, offset: 0x8 */
  uint32_t LCPR;                                   /**< LCDC cursor position register, offset: 0xC */
  uint32_t LCWHB;                                  /**< LCDC cursor width, height, and blink register, offset: 0x10 */
  uint32_t LCCMR;                                  /**< LCDC color cursor mapping register, offset: 0x14 */
  uint32_t LPCR;                                   /**< LCDC panel configuration register, offset: 0x18 */
  uint32_t LHCR;                                   /**< LCDC horizontal configuration register, offset: 0x1C */
  uint32_t LVCR;                                   /**< LCDC vertical configuration register, offset: 0x20 */
  uint32_t LPOR;                                   /**< LCDC panning offset register, offset: 0x24 */
  uint8_t RESERVED_0[4];
  uint32_t LPCCR;                                  /**< LCDC PWM contrast control register, offset: 0x2C */
  uint32_t LDCR;                                   /**< LCDC DMA control register, offset: 0x30 */
  uint32_t LRMCR;                                  /**< LCDC refresh mode control register, offset: 0x34 */
  uint32_t LICR;                                   /**< LCDC interrupt configuration register, offset: 0x38 */
  uint32_t LIER;                                   /**< LCDC interrupt enable register, offset: 0x3C */
  uint32_t LISR;                                   /**< LCDC interrupt status register, offset: 0x40 */
  uint8_t RESERVED_1[12];
  uint32_t LGWSAR;                                 /**< LCDC graphic window start address register, offset: 0x50 */
  uint32_t LGWSR;                                  /**< LCDC graphic window size register, offset: 0x54 */
  uint32_t LGWVPWR;                                /**< LCDC graphic window virtual page width register, offset: 0x58 */
  uint32_t LGWPOR;                                 /**< LCDC graphic window panning offset register, offset: 0x5C */
  uint32_t LGWPR;                                  /**< LCDC graphic window position register, offset: 0x60 */
  uint32_t LGWCR;                                  /**< LCDC graphic window control register, offset: 0x64 */
  uint32_t LGWDCR;                                 /**< LCDC graphic window DMA control register, offset: 0x68 */
  uint8_t RESERVED_2[20];
  uint32_t LAUSCR;                                 /**< LCDC AUS mode control register, offset: 0x80 */
  uint32_t LAUSCCR;                                /**< LCDC AUS mode cursor control register, offset: 0x84 */
} volatile *LCDC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LCDC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LCDC_Register_Accessor_Macros LCDC - Register accessor macros
 * @{
 */


/* LCDC - Register accessors */
#line 10738 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LCDC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LCDC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LCDC_Register_Masks LCDC Register Masks
 * @{
 */

/* LSSAR Bit Fields */



/* LSR Bit Fields */
#line 10766 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LVPWR Bit Fields */



/* LCPR Bit Fields */
#line 10782 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LCWHB Bit Fields */
#line 10794 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LCCMR Bit Fields */
#line 10804 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LPCR Bit Fields */
#line 10843 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LHCR Bit Fields */
#line 10853 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LVCR Bit Fields */
#line 10863 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LPOR Bit Fields */



/* LPCCR Bit Fields */
#line 10878 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LDCR Bit Fields */
#line 10887 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LRMCR Bit Fields */


/* LICR Bit Fields */
#line 10897 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LIER Bit Fields */
#line 10914 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LISR Bit Fields */
#line 10931 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LGWSAR Bit Fields */



/* LGWSR Bit Fields */
#line 10942 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LGWVPWR Bit Fields */



/* LGWPOR Bit Fields */



/* LGWPR Bit Fields */
#line 10957 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LGWCR Bit Fields */
#line 10976 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LGWDCR Bit Fields */
#line 10985 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LAUSCR Bit Fields */
#line 10997 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LAUSCCR Bit Fields */
#line 11007 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LCDC_Register_Masks */


/* LCDC - Peripheral instance base addresses */
/** Peripheral LCDC base pointer */


/* ----------------------------------------------------------------------------
   -- LCDC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LCDC_Register_Accessor_Macros LCDC - Register accessor macros
 * @{
 */


/* LCDC - Register instance definitions */
/* LCDC */
#line 11054 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LCDC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group LCDC_Peripheral */


/* ----------------------------------------------------------------------------
   -- LLWU
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Peripheral LLWU
 * @{
 */

/** LLWU - Peripheral register structure */
typedef struct LLWU_MemMap {
  uint8_t PE1;                                     /**< LLWU Pin Enable 1 Register, offset: 0x0 */
  uint8_t PE2;                                     /**< LLWU Pin Enable 2 Register, offset: 0x1 */
  uint8_t PE3;                                     /**< LLWU Pin Enable 3 Register, offset: 0x2 */
  uint8_t PE4;                                     /**< LLWU Pin Enable 4 Register, offset: 0x3 */
  uint8_t ME;                                      /**< LLWU Module Enable Register, offset: 0x4 */
  uint8_t F1;                                      /**< LLWU Flag 1 Register, offset: 0x5 */
  uint8_t F2;                                      /**< LLWU Flag 2 Register, offset: 0x6 */
  uint8_t F3;                                      /**< LLWU Flag 3 Register, offset: 0x7 */
  uint8_t FILT1;                                   /**< LLWU Pin Filter 1 Register, offset: 0x8 */
  uint8_t FILT2;                                   /**< LLWU Pin Filter 2 Register, offset: 0x9 */
  uint8_t RST;                                     /**< LLWU Reset Enable Register, offset: 0xA */
} volatile *LLWU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register accessors */
#line 11111 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

/* PE1 Bit Fields */
#line 11139 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PE2 Bit Fields */
#line 11152 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PE3 Bit Fields */
#line 11165 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PE4 Bit Fields */
#line 11178 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ME Bit Fields */
#line 11195 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* F1 Bit Fields */
#line 11212 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* F2 Bit Fields */
#line 11229 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* F3 Bit Fields */
#line 11246 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FILT1 Bit Fields */
#line 11255 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FILT2 Bit Fields */
#line 11264 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RST Bit Fields */





/**
 * @}
 */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base pointer */


/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register instance definitions */
/* LLWU */
#line 11302 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group LLWU_Peripheral */


/* ----------------------------------------------------------------------------
   -- LMEM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LMEM_Peripheral LMEM
 * @{
 */

/** LMEM - Peripheral register structure */
typedef struct LMEM_MemMap {
  uint32_t PCCCR;                                  /**< Cache control register, offset: 0x0 */
  uint32_t PCCLCR;                                 /**< Cache line control register, offset: 0x4 */
  uint32_t PCCSAR;                                 /**< Cache search address register, offset: 0x8 */
  uint32_t PCCCVR;                                 /**< Cache read/write value register, offset: 0xC */
  uint8_t RESERVED_0[16];
  uint32_t PCCRMR;                                 /**< Cache regions mode register, offset: 0x20 */
  uint8_t RESERVED_1[2012];
  uint32_t PSCCR;                                  /**< Cache control register, offset: 0x800 */
  uint32_t PSCLCR;                                 /**< Cache line control register, offset: 0x804 */
  uint32_t PSCSAR;                                 /**< Cache search address register, offset: 0x808 */
  uint32_t PSCCVR;                                 /**< Cache read/write value register, offset: 0x80C */
  uint8_t RESERVED_2[16];
  uint32_t PSCRMR;                                 /**< Cache regions mode register, offset: 0x820 */
} volatile *LMEM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LMEM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LMEM_Register_Accessor_Macros LMEM - Register accessor macros
 * @{
 */


/* LMEM - Register accessors */
#line 11360 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LMEM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LMEM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LMEM_Register_Masks LMEM Register Masks
 * @{
 */

/* PCCCR Bit Fields */
#line 11390 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PCCLCR Bit Fields */
#line 11413 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PCCSAR Bit Fields */





/* PCCCVR Bit Fields */



/* PCCRMR Bit Fields */
#line 11472 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PSCCR Bit Fields */
#line 11487 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PSCLCR Bit Fields */
#line 11510 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PSCSAR Bit Fields */





/* PSCCVR Bit Fields */



/* PSCRMR Bit Fields */
#line 11569 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LMEM_Register_Masks */


/* LMEM - Peripheral instance base addresses */
/** Peripheral LMEM base pointer */


/* ----------------------------------------------------------------------------
   -- LMEM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LMEM_Register_Accessor_Macros LMEM - Register accessor macros
 * @{
 */


/* LMEM - Register instance definitions */
/* LMEM */
#line 11601 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group LMEM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group LMEM_Peripheral */


/* ----------------------------------------------------------------------------
   -- LPTMR
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR_Peripheral LPTMR
 * @{
 */

/** LPTMR - Peripheral register structure */
typedef struct LPTMR_MemMap {
  uint32_t CSR;                                    /**< Low Power Timer Control Status Register, offset: 0x0 */
  uint32_t PSR;                                    /**< Low Power Timer Prescale Register, offset: 0x4 */
  uint32_t CMR;                                    /**< Low Power Timer Compare Register, offset: 0x8 */
  uint32_t CNR;                                    /**< Low Power Timer Counter Register, offset: 0xC */
} volatile *LPTMR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register accessors */





/**
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/* CSR Bit Fields */
#line 11675 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PSR Bit Fields */
#line 11684 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMR Bit Fields */



/* CNR Bit Fields */




/**
 * @}
 */ /* end of group LPTMR_Register_Masks */


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base pointer */


/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register instance definitions */
/* LPTMR0 */





/**
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group LPTMR_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCG
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Peripheral MCG
 * @{
 */

/** MCG - Peripheral register structure */
typedef struct MCG_MemMap {
  uint8_t C1;                                      /**< MCG Control 1 Register, offset: 0x0 */
  uint8_t C2;                                      /**< MCG Control 2 Register, offset: 0x1 */
  uint8_t C3;                                      /**< MCG Control 3 Register, offset: 0x2 */
  uint8_t C4;                                      /**< MCG Control 4 Register, offset: 0x3 */
  uint8_t C5;                                      /**< MCG Control 5 Register, offset: 0x4 */
  uint8_t C6;                                      /**< MCG Control 6 Register, offset: 0x5 */
  uint8_t S;                                       /**< MCG Status Register, offset: 0x6 */
  uint8_t RESERVED_0[1];
  uint8_t SC;                                      /**< MCG Status and Control Register, offset: 0x8 */
  uint8_t RESERVED_1[1];
  uint8_t ATCVH;                                   /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  uint8_t ATCVL;                                   /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
  uint8_t C7;                                      /**< MCG Control 7 Register, offset: 0xC */
  uint8_t C8;                                      /**< MCG Control 8 Register, offset: 0xD */
  uint8_t C9;                                      /**< MCG Control 9 Register, offset: 0xE */
  uint8_t C10;                                     /**< MCG Control 10 Register, offset: 0xF */
  uint8_t C11;                                     /**< MCG Control 11 Register, offset: 0x10 */
  uint8_t C12;                                     /**< MCG Control 12 Register, offset: 0x11 */
  uint8_t S2;                                      /**< MCG Status 2 Register, offset: 0x12 */
} volatile *MCG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register accessors */
#line 11789 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/* C1 Bit Fields */
#line 11817 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C2 Bit Fields */
#line 11831 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C3 Bit Fields */



/* C4 Bit Fields */
#line 11846 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C5 Bit Fields */
#line 11856 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C6 Bit Fields */
#line 11866 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* S Bit Fields */
#line 11882 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SC Bit Fields */
#line 11896 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ATCVH Bit Fields */



/* ATCVL Bit Fields */



/* C7 Bit Fields */


/* C8 Bit Fields */
#line 11914 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C10 Bit Fields */
#line 11924 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C11 Bit Fields */
#line 11936 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C12 Bit Fields */
#line 11944 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* S2 Bit Fields */
#line 11955 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base pointer */


/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register instance definitions */
/* MCG */
#line 11994 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group MCG_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Peripheral MCM
 * @{
 */

/** MCM - Peripheral register structure */
typedef struct MCM_MemMap {
  uint8_t RESERVED_0[8];
  uint16_t PLASC;                                  /**< Crossbar switch (AXBS) slave configuration, offset: 0x8 */
  uint16_t PLAMC;                                  /**< Crossbar switch (AXBS) master configuration, offset: 0xA */
  uint32_t CR;                                     /**< Control register, offset: 0xC */
  uint32_t ISR;                                    /**< Interrupt status and control register, offset: 0x10 */
  uint32_t ETBCC;                                  /**< ETB counter control register, offset: 0x14 */
  uint32_t ETBRL;                                  /**< ETB reload register, offset: 0x18 */
  uint32_t ETBCNT;                                 /**< ETB counter value register, offset: 0x1C */
  uint32_t FADR;                                   /**< Fault address register, offset: 0x20 */
  uint32_t FATR;                                   /**< Fault attributes register, offset: 0x24 */
  uint32_t FDR;                                    /**< Fault data register, offset: 0x28 */
  uint8_t RESERVED_1[4];
  uint32_t PID;                                    /**< Process ID register, offset: 0x30 */
} volatile *MCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register accessors */
#line 12053 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/* PLASC Bit Fields */



/* PLAMC Bit Fields */



/* CR Bit Fields */
#line 12090 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ISR Bit Fields */
#line 12125 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ETBCC Bit Fields */
#line 12137 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ETBRL Bit Fields */



/* ETBCNT Bit Fields */



/* FADR Bit Fields */



/* FATR Bit Fields */
#line 12164 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FDR Bit Fields */



/* PID Bit Fields */




/**
 * @}
 */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base pointer */


/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register instance definitions */
/* MCM */
#line 12205 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group MCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- MPU
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Peripheral MPU
 * @{
 */

/** MPU - Peripheral register structure */
typedef struct MPU_MemMap {
  uint32_t CESR;                                   /**< Control/Error Status Register, offset: 0x0 */
  uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    uint32_t EAR;                                    /**< Error Address Register, Slave Port n, array offset: 0x10, array step: 0x8 */
    uint32_t EDR;                                    /**< Error Detail Register, Slave Port n, array offset: 0x14, array step: 0x8 */
  } SP[5];
  uint8_t RESERVED_1[968];
  uint32_t WORD[12][4];                            /**< Region Descriptor n, Word 0..Region Descriptor n, Word 3, array offset: 0x400, array step: index*0x10, index2*0x4 */
  uint8_t RESERVED_2[832];
  uint32_t RGDAAC[12];                             /**< Region Descriptor Alternate Access Control n, array offset: 0x800, array step: 0x4 */
} volatile *MPU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MPU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Register_Accessor_Macros MPU - Register accessor macros
 * @{
 */


/* MPU - Register accessors */






/**
 * @}
 */ /* end of group MPU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MPU Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Register_Masks MPU Register Masks
 * @{
 */

/* CESR Bit Fields */
#line 12285 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EAR Bit Fields */



/* EDR Bit Fields */
#line 12304 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WORD Bit Fields */
#line 12367 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RGDAAC Bit Fields */
#line 12416 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group MPU_Register_Masks */


/* MPU - Peripheral instance base addresses */
/** Peripheral MPU base pointer */


/* ----------------------------------------------------------------------------
   -- MPU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Register_Accessor_Macros MPU - Register accessor macros
 * @{
 */


/* MPU - Register instance definitions */
/* MPU */
#line 12509 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* MPU - Register array accessors */





/**
 * @}
 */ /* end of group MPU_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group MPU_Peripheral */


/* ----------------------------------------------------------------------------
   -- NFC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NFC_Peripheral NFC
 * @{
 */

/** NFC - Peripheral register structure */
typedef struct NFC_MemMap {
  uint8_t RESERVED_0[16128];
  uint32_t CMD1;                                   /**< Flash command 1, offset: 0x3F00 */
  uint32_t CMD2;                                   /**< Flash command 2, offset: 0x3F04 */
  uint32_t CAR;                                    /**< Column address, offset: 0x3F08 */
  uint32_t RAR;                                    /**< Row address, offset: 0x3F0C */
  uint32_t RPT;                                    /**< Flash command repeat, offset: 0x3F10 */
  uint32_t RAI;                                    /**< Row address increment, offset: 0x3F14 */
  uint32_t SR1;                                    /**< Flash status 1, offset: 0x3F18 */
  uint32_t SR2;                                    /**< Flash status 2, offset: 0x3F1C */
  uint32_t DMA1;                                   /**< DMA channel 1 address, offset: 0x3F20 */
  uint32_t DMACFG;                                 /**< DMA configuration, offset: 0x3F24 */
  uint32_t SWAP;                                   /**< Cach swap, offset: 0x3F28 */
  uint32_t SECSZ;                                  /**< Sector size, offset: 0x3F2C */
  uint32_t CFG;                                    /**< Flash configuration, offset: 0x3F30 */
  uint32_t DMA2;                                   /**< DMA channel 2 address, offset: 0x3F34 */
  uint32_t ISR;                                    /**< Interrupt status, offset: 0x3F38 */
} volatile *NFC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NFC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NFC_Register_Accessor_Macros NFC - Register accessor macros
 * @{
 */


/* NFC - Register accessors */
#line 12581 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group NFC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NFC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NFC_Register_Masks NFC Register Masks
 * @{
 */

/* CMD1 Bit Fields */
#line 12603 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMD2 Bit Fields */
#line 12615 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CAR Bit Fields */
#line 12622 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RAR Bit Fields */
#line 12640 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RPT Bit Fields */



/* RAI Bit Fields */
#line 12654 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SR1 Bit Fields */
#line 12667 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SR2 Bit Fields */
#line 12674 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DMA1 Bit Fields */



/* DMACFG Bit Fields */
#line 12692 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SWAP Bit Fields */
#line 12699 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SECSZ Bit Fields */



/* CFG Bit Fields */
#line 12735 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DMA2 Bit Fields */



/* ISR Bit Fields */
#line 12777 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group NFC_Register_Masks */


/* NFC - Peripheral instance base addresses */
/** Peripheral NFC base pointer */


/* ----------------------------------------------------------------------------
   -- NFC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NFC_Register_Accessor_Macros NFC - Register accessor macros
 * @{
 */


/* NFC - Register instance definitions */
/* NFC */
#line 12814 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group NFC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group NFC_Peripheral */


/* ----------------------------------------------------------------------------
   -- NV
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Peripheral NV
 * @{
 */

/** NV - Peripheral register structure */
typedef struct NV_MemMap {
  uint8_t BACKKEY3;                                /**< Backdoor Comparison Key 3., offset: 0x0 */
  uint8_t BACKKEY2;                                /**< Backdoor Comparison Key 2., offset: 0x1 */
  uint8_t BACKKEY1;                                /**< Backdoor Comparison Key 1., offset: 0x2 */
  uint8_t BACKKEY0;                                /**< Backdoor Comparison Key 0., offset: 0x3 */
  uint8_t BACKKEY7;                                /**< Backdoor Comparison Key 7., offset: 0x4 */
  uint8_t BACKKEY6;                                /**< Backdoor Comparison Key 6., offset: 0x5 */
  uint8_t BACKKEY5;                                /**< Backdoor Comparison Key 5., offset: 0x6 */
  uint8_t BACKKEY4;                                /**< Backdoor Comparison Key 4., offset: 0x7 */
  uint8_t FPROT3;                                  /**< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  uint8_t FPROT2;                                  /**< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  uint8_t FPROT1;                                  /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  uint8_t FPROT0;                                  /**< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  uint8_t FSEC;                                    /**< Non-volatile Flash Security Register, offset: 0xC */
  uint8_t FOPT;                                    /**< Non-volatile Flash Option Register, offset: 0xD */
  uint8_t FEPROT;                                  /**< Non-volatile EERAM Protection Register, offset: 0xE */
  uint8_t FDPROT;                                  /**< Non-volatile D-Flash Protection Register, offset: 0xF */
} volatile *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register accessors */
#line 12881 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/* BACKKEY3 Bit Fields */



/* BACKKEY2 Bit Fields */



/* BACKKEY1 Bit Fields */



/* BACKKEY0 Bit Fields */



/* BACKKEY7 Bit Fields */



/* BACKKEY6 Bit Fields */



/* BACKKEY5 Bit Fields */



/* BACKKEY4 Bit Fields */



/* FPROT3 Bit Fields */



/* FPROT2 Bit Fields */



/* FPROT1 Bit Fields */



/* FPROT0 Bit Fields */



/* FSEC Bit Fields */
#line 12957 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FOPT Bit Fields */




/* FEPROT Bit Fields */



/* FDPROT Bit Fields */




/**
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTFE_FlashConfig base pointer */


/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register instance definitions */
/* FTFE_FlashConfig */
#line 13008 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group NV_Peripheral */


/* ----------------------------------------------------------------------------
   -- NVIC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Peripheral NVIC
 * @{
 */

/** NVIC - Peripheral register structure */
typedef struct NVIC_MemMap {
  uint32_t ISER[4];                                /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
  uint8_t RESERVED_0[112];
  uint32_t ICER[4];                                /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
  uint8_t RESERVED_1[112];
  uint32_t ISPR[4];                                /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
  uint8_t RESERVED_2[112];
  uint32_t ICPR[4];                                /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
  uint8_t RESERVED_3[112];
  uint32_t IABR[4];                                /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[240];
  uint8_t IP[106];                                 /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
  uint8_t RESERVED_5[2710];
  uint32_t STIR[1];                                /**< Software Trigger Interrupt Register, array offset: 0xE00, array step: 0x4 */
} volatile *NVIC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros
 * @{
 */


/* NVIC - Register accessors */
#line 13063 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group NVIC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NVIC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Register_Masks NVIC Register Masks
 * @{
 */

/* ISER Bit Fields */



/* ICER Bit Fields */



/* ISPR Bit Fields */



/* ICPR Bit Fields */



/* IABR Bit Fields */



/* IP Bit Fields */
#line 13417 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* STIR Bit Fields */




/**
 * @}
 */ /* end of group NVIC_Register_Masks */


/* NVIC - Peripheral instance base addresses */
/** Peripheral NVIC base pointer */


/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros
 * @{
 */


/* NVIC - Register instance definitions */
/* NVIC */
#line 13570 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* NVIC - Register array accessors */
#line 13579 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group NVIC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group NVIC_Peripheral */


/* ----------------------------------------------------------------------------
   -- OSC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Peripheral OSC
 * @{
 */

/** OSC - Peripheral register structure */
typedef struct OSC_MemMap {
  uint8_t CR;                                      /**< OSC Control Register, offset: 0x0 */
} volatile *OSC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register accessors */


/**
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/* CR Bit Fields */
#line 13644 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/** Peripheral OSC0 base pointer */

/** Peripheral OSC1 base pointer */


/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register instance definitions */
/* OSC0 */

/* OSC1 */


/**
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group OSC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PDB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Peripheral PDB
 * @{
 */

/** PDB - Peripheral register structure */
typedef struct PDB_MemMap {
  uint32_t SC;                                     /**< Status and Control Register, offset: 0x0 */
  uint32_t MOD;                                    /**< Modulus Register, offset: 0x4 */
  uint32_t CNT;                                    /**< Counter Register, offset: 0x8 */
  uint32_t IDLY;                                   /**< Interrupt Delay Register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x28 */
    uint32_t C1;                                     /**< Channel n Control Register 1, array offset: 0x10, array step: 0x28 */
    uint32_t S;                                      /**< Channel n Status Register, array offset: 0x14, array step: 0x28 */
    uint32_t DLY[2];                                 /**< Channel n Delay 0 Register..Channel n Delay 1 Register, array offset: 0x18, array step: index*0x28, index2*0x4 */
    uint8_t RESERVED_0[24];
  } CH[4];
  uint8_t RESERVED_0[160];
  struct {                                         /* offset: 0x150, array step: 0x8 */
    uint32_t INTC;                                   /**< DAC Interval Trigger n Control Register, array offset: 0x150, array step: 0x8 */
    uint32_t INT;                                    /**< DAC Interval n Register, array offset: 0x154, array step: 0x8 */
  } DAC[2];
  uint8_t RESERVED_1[48];
  uint32_t POEN;                                   /**< Pulse-Out n Enable Register, offset: 0x190 */
  uint32_t PODLY[4];                               /**< Pulse-Out n Delay Register, array offset: 0x194, array step: 0x4 */
} volatile *PDB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros
 * @{
 */


/* PDB - Register accessors */
#line 13735 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group PDB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Register_Masks PDB Register Masks
 * @{
 */

/* SC Bit Fields */
#line 13779 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MOD Bit Fields */



/* CNT Bit Fields */



/* IDLY Bit Fields */



/* C1 Bit Fields */
#line 13801 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* S Bit Fields */
#line 13808 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DLY Bit Fields */



/* INTC Bit Fields */




/* INT Bit Fields */



/* POEN Bit Fields */



/* PODLY Bit Fields */
#line 13832 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group PDB_Register_Masks */


/* PDB - Peripheral instance base addresses */
/** Peripheral PDB0 base pointer */


/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros
 * @{
 */


/* PDB - Register instance definitions */
/* PDB0 */
#line 13883 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* PDB - Register array accessors */
#line 13891 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group PDB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group PDB_Peripheral */


/* ----------------------------------------------------------------------------
   -- PIT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PIT_Peripheral PIT
 * @{
 */

/** PIT - Peripheral register structure */
typedef struct PIT_MemMap {
  uint32_t MCR;                                    /**< PIT Module Control Register, offset: 0x0 */
  uint8_t RESERVED_0[252];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    uint32_t LDVAL;                                  /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    uint32_t CVAL;                                   /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    uint32_t TCTRL;                                  /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    uint32_t TFLG;                                   /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[4];
} volatile *PIT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register accessors */






/**
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/* MCR Bit Fields */




/* LDVAL Bit Fields */



/* CVAL Bit Fields */



/* TCTRL Bit Fields */




/* TFLG Bit Fields */



/**
 * @}
 */ /* end of group PIT_Register_Masks */


/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base pointer */


/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register instance definitions */
/* PIT */
#line 14014 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* PIT - Register array accessors */





/**
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group PIT_Peripheral */


/* ----------------------------------------------------------------------------
   -- PMC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Peripheral PMC
 * @{
 */

/** PMC - Peripheral register structure */
typedef struct PMC_MemMap {
  uint8_t LVDSC1;                                  /**< Low Voltage Detect Status and Control 1 Register, offset: 0x0 */
  uint8_t LVDSC2;                                  /**< Low Voltage Detect Status and Control 2 Register, offset: 0x1 */
  uint8_t REGSC;                                   /**< Regulator Status and Control Register, offset: 0x2 */
} volatile *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register accessors */




/**
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/* LVDSC1 Bit Fields */
#line 14088 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LVDSC2 Bit Fields */
#line 14098 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* REGSC Bit Fields */
#line 14107 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base pointer */


/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register instance definitions */
/* PMC */




/**
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group PMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PORT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Peripheral PORT
 * @{
 */

/** PORT - Peripheral register structure */
typedef struct PORT_MemMap {
  uint32_t PCR[32];                                /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  uint32_t GPCLR;                                  /**< Global Pin Control Low Register, offset: 0x80 */
  uint32_t GPCHR;                                  /**< Global Pin Control High Register, offset: 0x84 */
  uint8_t RESERVED_0[24];
  uint32_t ISFR;                                   /**< Interrupt Status Flag Register, offset: 0xA0 */
  uint8_t RESERVED_1[28];
  uint32_t DFER;                                   /**< Digital Filter Enable Register, offset: 0xC0 */
  uint32_t DFCR;                                   /**< Digital Filter Clock Register, offset: 0xC4 */
  uint32_t DFWR;                                   /**< Digital Filter Width Register, offset: 0xC8 */
} volatile *PORT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register accessors */
#line 14183 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PCR Bit Fields */
#line 14221 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* GPCLR Bit Fields */
#line 14228 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* GPCHR Bit Fields */
#line 14235 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ISFR Bit Fields */



/* DFER Bit Fields */



/* DFCR Bit Fields */


/* DFWR Bit Fields */




/**
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base pointer */

/** Peripheral PORTB base pointer */

/** Peripheral PORTC base pointer */

/** Peripheral PORTD base pointer */

/** Peripheral PORTE base pointer */

/** Peripheral PORTF base pointer */


/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register instance definitions */
/* PORTA */
#line 14320 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PORTB */
#line 14359 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PORTC */
#line 14398 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PORTD */
#line 14437 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PORTE */
#line 14476 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PORTF */
#line 14515 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* PORT - Register array accessors */
#line 14523 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group PORT_Peripheral */


/* ----------------------------------------------------------------------------
   -- RCM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Peripheral RCM
 * @{
 */

/** RCM - Peripheral register structure */
typedef struct RCM_MemMap {
  uint8_t SRS0;                                    /**< System Reset Status Register 0, offset: 0x0 */
  uint8_t SRS1;                                    /**< System Reset Status Register 1, offset: 0x1 */
  uint8_t RESERVED_0[2];
  uint8_t RPFC;                                    /**< Reset Pin Filter Control Register, offset: 0x4 */
  uint8_t RPFW;                                    /**< Reset Pin Filter Width Register, offset: 0x5 */
  uint8_t RESERVED_1[1];
  uint8_t MR;                                      /**< Mode Register, offset: 0x7 */
} volatile *RCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register accessors */






/**
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/* SRS0 Bit Fields */
#line 14598 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SRS1 Bit Fields */
#line 14613 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RPFC Bit Fields */





/* RPFW Bit Fields */



/* MR Bit Fields */



/**
 * @}
 */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base pointer */


/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register instance definitions */
/* RCM */






/**
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- RFSYS
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Peripheral RFSYS
 * @{
 */

/** RFSYS - Peripheral register structure */
typedef struct RFSYS_MemMap {
  uint32_t REG[8];                                 /**< Register file register, array offset: 0x0, array step: 0x4 */
} volatile *RFSYS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RFSYS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Register_Accessor_Macros RFSYS - Register accessor macros
 * @{
 */


/* RFSYS - Register accessors */


/**
 * @}
 */ /* end of group RFSYS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RFSYS Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Register_Masks RFSYS Register Masks
 * @{
 */

/* REG Bit Fields */
#line 14718 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group RFSYS_Register_Masks */


/* RFSYS - Peripheral instance base addresses */
/** Peripheral RFSYS base pointer */


/* ----------------------------------------------------------------------------
   -- RFSYS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Register_Accessor_Macros RFSYS - Register accessor macros
 * @{
 */


/* RFSYS - Register instance definitions */
/* RFSYS */
#line 14748 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* RFSYS - Register array accessors */


/**
 * @}
 */ /* end of group RFSYS_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RFSYS_Peripheral */


/* ----------------------------------------------------------------------------
   -- RFVBAT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFVBAT_Peripheral RFVBAT
 * @{
 */

/** RFVBAT - Peripheral register structure */
typedef struct RFVBAT_MemMap {
  uint32_t REG[8];                                 /**< VBAT register file register, array offset: 0x0, array step: 0x4 */
} volatile *RFVBAT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RFVBAT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFVBAT_Register_Accessor_Macros RFVBAT - Register accessor macros
 * @{
 */


/* RFVBAT - Register accessors */


/**
 * @}
 */ /* end of group RFVBAT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RFVBAT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFVBAT_Register_Masks RFVBAT Register Masks
 * @{
 */

/* REG Bit Fields */
#line 14816 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group RFVBAT_Register_Masks */


/* RFVBAT - Peripheral instance base addresses */
/** Peripheral RFVBAT base pointer */


/* ----------------------------------------------------------------------------
   -- RFVBAT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFVBAT_Register_Accessor_Macros RFVBAT - Register accessor macros
 * @{
 */


/* RFVBAT - Register instance definitions */
/* RFVBAT */
#line 14846 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* RFVBAT - Register array accessors */


/**
 * @}
 */ /* end of group RFVBAT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RFVBAT_Peripheral */


/* ----------------------------------------------------------------------------
   -- RNG
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RNG_Peripheral RNG
 * @{
 */

/** RNG - Peripheral register structure */
typedef struct RNG_MemMap {
  uint32_t CR;                                     /**< RNGA Control Register, offset: 0x0 */
  uint32_t SR;                                     /**< RNGA Status Register, offset: 0x4 */
  uint32_t ER;                                     /**< RNGA Entropy Register, offset: 0x8 */
  uint32_t OR;                                     /**< RNGA Output Register, offset: 0xC */
} volatile *RNG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RNG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RNG_Register_Accessor_Macros RNG - Register accessor macros
 * @{
 */


/* RNG - Register accessors */





/**
 * @}
 */ /* end of group RNG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RNG Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RNG_Register_Masks RNG Register Masks
 * @{
 */

/* CR Bit Fields */
#line 14918 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SR Bit Fields */
#line 14935 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ER Bit Fields */



/* OR Bit Fields */




/**
 * @}
 */ /* end of group RNG_Register_Masks */


/* RNG - Peripheral instance base addresses */
/** Peripheral RNG base pointer */


/* ----------------------------------------------------------------------------
   -- RNG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RNG_Register_Accessor_Macros RNG - Register accessor macros
 * @{
 */


/* RNG - Register instance definitions */
/* RNG */





/**
 * @}
 */ /* end of group RNG_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RNG_Peripheral */


/* ----------------------------------------------------------------------------
   -- RTC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Peripheral RTC
 * @{
 */

/** RTC - Peripheral register structure */
typedef struct RTC_MemMap {
  uint32_t TSR;                                    /**< RTC Time Seconds Register, offset: 0x0 */
  uint32_t TPR;                                    /**< RTC Time Prescaler Register, offset: 0x4 */
  uint32_t TAR;                                    /**< RTC Time Alarm Register, offset: 0x8 */
  uint32_t TCR;                                    /**< RTC Time Compensation Register, offset: 0xC */
  uint32_t CR;                                     /**< RTC Control Register, offset: 0x10 */
  uint32_t SR;                                     /**< RTC Status Register, offset: 0x14 */
  uint32_t LR;                                     /**< RTC Lock Register, offset: 0x18 */
  uint32_t IER;                                    /**< RTC Interrupt Enable Register, offset: 0x1C */
  uint32_t TTSR;                                   /**< RTC Tamper Time Seconds Register, offset: 0x20 */
  uint32_t MER;                                    /**< RTC Monotonic Enable Register, offset: 0x24 */
  uint32_t MCLR;                                   /**< RTC Monotonic Counter Low Register, offset: 0x28 */
  uint32_t MCHR;                                   /**< RTC Monotonic Counter High Register, offset: 0x2C */
  uint32_t TER;                                    /**< RTC Tamper Enable Register, offset: 0x30 */
  uint32_t TDR;                                    /**< RTC Tamper Detect Register, offset: 0x34 */
  uint32_t TTR;                                    /**< RTC Tamper Trim Register, offset: 0x38 */
  uint32_t TIR;                                    /**< RTC Tamper Interrupt Register, offset: 0x3C */
  uint8_t RESERVED_0[1984];
  uint32_t WAR;                                    /**< RTC Write Access Register, offset: 0x800 */
  uint32_t RAR;                                    /**< RTC Read Access Register, offset: 0x804 */
} volatile *RTC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register accessors */
#line 15041 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/* TSR Bit Fields */



/* TPR Bit Fields */



/* TAR Bit Fields */



/* TCR Bit Fields */
#line 15081 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CR Bit Fields */
#line 15102 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SR Bit Fields */
#line 15113 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* LR Bit Fields */
#line 15138 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IER Bit Fields */
#line 15149 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TTSR Bit Fields */



/* MER Bit Fields */


/* MCLR Bit Fields */



/* MCHR Bit Fields */



/* TER Bit Fields */
#line 15177 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TDR Bit Fields */
#line 15190 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TTR Bit Fields */
#line 15200 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TIR Bit Fields */
#line 15213 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WAR Bit Fields */
#line 15246 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RAR Bit Fields */
#line 15279 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base pointer */


/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register instance definitions */
/* RTC */
#line 15319 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RTC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SCB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Peripheral SCB
 * @{
 */

/** SCB - Peripheral register structure */
typedef struct SCB_MemMap {
  uint8_t RESERVED_0[8];
  uint32_t ACTLR;                                  /**< Auxiliary Control Register,, offset: 0x8 */
  uint8_t RESERVED_1[3316];
  uint32_t CPUID;                                  /**< CPUID Base Register, offset: 0xD00 */
  uint32_t ICSR;                                   /**< Interrupt Control and State Register, offset: 0xD04 */
  uint32_t VTOR;                                   /**< Vector Table Offset Register, offset: 0xD08 */
  uint32_t AIRCR;                                  /**< Application Interrupt and Reset Control Register, offset: 0xD0C */
  uint32_t SCR;                                    /**< System Control Register, offset: 0xD10 */
  uint32_t CCR;                                    /**< Configuration and Control Register, offset: 0xD14 */
  uint32_t SHPR1;                                  /**< System Handler Priority Register 1, offset: 0xD18 */
  uint32_t SHPR2;                                  /**< System Handler Priority Register 2, offset: 0xD1C */
  uint32_t SHPR3;                                  /**< System Handler Priority Register 3, offset: 0xD20 */
  uint32_t SHCSR;                                  /**< System Handler Control and State Register, offset: 0xD24 */
  uint32_t CFSR;                                   /**< Configurable Fault Status Registers, offset: 0xD28 */
  uint32_t HFSR;                                   /**< HardFault Status register, offset: 0xD2C */
  uint32_t DFSR;                                   /**< Debug Fault Status Register, offset: 0xD30 */
  uint32_t MMFAR;                                  /**< MemManage Address Register, offset: 0xD34 */
  uint32_t BFAR;                                   /**< BusFault Address Register, offset: 0xD38 */
  uint32_t AFSR;                                   /**< Auxiliary Fault Status Register, offset: 0xD3C */
} volatile *SCB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros
 * @{
 */


/* SCB - Register accessors */
#line 15390 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SCB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SCB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Register_Masks SCB Register Masks
 * @{
 */

/* ACTLR Bit Fields */
#line 15412 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CPUID Bit Fields */
#line 15425 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ICSR Bit Fields */
#line 15448 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* VTOR Bit Fields */



/* AIRCR Bit Fields */
#line 15467 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCR Bit Fields */
#line 15474 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CCR Bit Fields */
#line 15487 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SHPR1 Bit Fields */
#line 15497 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SHPR2 Bit Fields */



/* SHPR3 Bit Fields */
#line 15508 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SHCSR Bit Fields */
#line 15537 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CFSR Bit Fields */
#line 15576 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HFSR Bit Fields */
#line 15583 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DFSR Bit Fields */
#line 15594 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MMFAR Bit Fields */



/* BFAR Bit Fields */



/* AFSR Bit Fields */




/**
 * @}
 */ /* end of group SCB_Register_Masks */


/* SCB - Peripheral instance base addresses */
/** Peripheral SystemControl base pointer */


/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros
 * @{
 */


/* SCB - Register instance definitions */
/* SystemControl */
#line 15645 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SCB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SCB_Peripheral */


/* ----------------------------------------------------------------------------
   -- SDHC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Peripheral SDHC
 * @{
 */

/** SDHC - Peripheral register structure */
typedef struct SDHC_MemMap {
  uint32_t DSADDR;                                 /**< DMA System Address Register, offset: 0x0 */
  uint32_t BLKATTR;                                /**< Block Attributes Register, offset: 0x4 */
  uint32_t CMDARG;                                 /**< Command Argument Register, offset: 0x8 */
  uint32_t XFERTYP;                                /**< Transfer Type Register, offset: 0xC */
  uint32_t CMDRSP[4];                              /**< Command Response 0..Command Response 3, array offset: 0x10, array step: 0x4 */
  uint32_t DATPORT;                                /**< Buffer Data Port Register, offset: 0x20 */
  uint32_t PRSSTAT;                                /**< Present State Register, offset: 0x24 */
  uint32_t PROCTL;                                 /**< Protocol Control Register, offset: 0x28 */
  uint32_t SYSCTL;                                 /**< System Control Register, offset: 0x2C */
  uint32_t IRQSTAT;                                /**< Interrupt Status Register, offset: 0x30 */
  uint32_t IRQSTATEN;                              /**< Interrupt Status Enable Register, offset: 0x34 */
  uint32_t IRQSIGEN;                               /**< Interrupt Signal Enable Register, offset: 0x38 */
  uint32_t AC12ERR;                                /**< Auto CMD12 Error Status Register, offset: 0x3C */
  uint32_t HTCAPBLT;                               /**< Host Controller Capabilities, offset: 0x40 */
  uint32_t WML;                                    /**< Watermark Level Register, offset: 0x44 */
  uint8_t RESERVED_0[8];
  uint32_t FEVT;                                   /**< Force Event Register, offset: 0x50 */
  uint32_t ADMAES;                                 /**< ADMA Error Status Register, offset: 0x54 */
  uint32_t ADSADDR;                                /**< ADMA System Address Register, offset: 0x58 */
  uint8_t RESERVED_1[100];
  uint32_t VENDOR;                                 /**< Vendor Specific Register, offset: 0xC0 */
  uint32_t MMCBOOT;                                /**< MMC Boot Register, offset: 0xC4 */
  uint8_t RESERVED_2[52];
  uint32_t HOSTVER;                                /**< Host Controller Version, offset: 0xFC */
} volatile *SDHC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SDHC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Register_Accessor_Macros SDHC - Register accessor macros
 * @{
 */


/* SDHC - Register accessors */
#line 15725 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SDHC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SDHC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Register_Masks SDHC Register Masks
 * @{
 */

/* DSADDR Bit Fields */



/* BLKATTR Bit Fields */
#line 15751 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMDARG Bit Fields */



/* XFERTYP Bit Fields */
#line 15781 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CMDRSP Bit Fields */
#line 15794 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DATPORT Bit Fields */



/* PRSSTAT Bit Fields */
#line 15830 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PROCTL Bit Fields */
#line 15862 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SYSCTL Bit Fields */
#line 15888 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IRQSTAT Bit Fields */
#line 15925 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IRQSTATEN Bit Fields */
#line 15962 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IRQSIGEN Bit Fields */
#line 15999 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* AC12ERR Bit Fields */
#line 16012 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HTCAPBLT Bit Fields */
#line 16030 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WML Bit Fields */
#line 16040 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FEVT Bit Fields */
#line 16073 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ADMAES Bit Fields */
#line 16081 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ADSADDR Bit Fields */



/* VENDOR Bit Fields */
#line 16093 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MMCBOOT Bit Fields */
#line 16108 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HOSTVER Bit Fields */
#line 16115 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SDHC_Register_Masks */


/* SDHC - Peripheral instance base addresses */
/** Peripheral SDHC base pointer */


/* ----------------------------------------------------------------------------
   -- SDHC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Register_Accessor_Macros SDHC - Register accessor macros
 * @{
 */


/* SDHC - Register instance definitions */
/* SDHC */
#line 16161 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* SDHC - Register array accessors */


/**
 * @}
 */ /* end of group SDHC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SDHC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SIM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Peripheral SIM
 * @{
 */

/** SIM - Peripheral register structure */
typedef struct SIM_MemMap {
  uint32_t SOPT1;                                  /**< System Options Register 1, offset: 0x0 */
  uint32_t SOPT1CFG;                               /**< SOPT1 Configuration Register, offset: 0x4 */
  uint8_t RESERVED_0[4092];
  uint32_t SOPT2;                                  /**< System Options Register 2, offset: 0x1004 */
  uint8_t RESERVED_1[4];
  uint32_t SOPT4;                                  /**< System Options Register 4, offset: 0x100C */
  uint32_t SOPT5;                                  /**< System Options Register 5, offset: 0x1010 */
  uint32_t SOPT6;                                  /**< System Options Register 6, offset: 0x1014 */
  uint32_t SOPT7;                                  /**< System Options Register 7, offset: 0x1018 */
  uint8_t RESERVED_2[8];
  uint32_t SDID;                                   /**< System Device Identification Register, offset: 0x1024 */
  uint32_t SCGC1;                                  /**< System Clock Gating Control Register 1, offset: 0x1028 */
  uint32_t SCGC2;                                  /**< System Clock Gating Control Register 2, offset: 0x102C */
  uint32_t SCGC3;                                  /**< System Clock Gating Control Register 3, offset: 0x1030 */
  uint32_t SCGC4;                                  /**< System Clock Gating Control Register 4, offset: 0x1034 */
  uint32_t SCGC5;                                  /**< System Clock Gating Control Register 5, offset: 0x1038 */
  uint32_t SCGC6;                                  /**< System Clock Gating Control Register 6, offset: 0x103C */
  uint32_t SCGC7;                                  /**< System Clock Gating Control Register 7, offset: 0x1040 */
  uint32_t CLKDIV1;                                /**< System Clock Divider Register 1, offset: 0x1044 */
  uint32_t CLKDIV2;                                /**< System Clock Divider Register 2, offset: 0x1048 */
  uint32_t FCFG1;                                  /**< Flash Configuration Register 1, offset: 0x104C */
  uint32_t FCFG2;                                  /**< Flash Configuration Register 2, offset: 0x1050 */
  uint32_t UIDH;                                   /**< Unique Identification Register High, offset: 0x1054 */
  uint32_t UIDMH;                                  /**< Unique Identification Register Mid-High, offset: 0x1058 */
  uint32_t UIDML;                                  /**< Unique Identification Register Mid Low, offset: 0x105C */
  uint32_t UIDL;                                   /**< Unique Identification Register Low, offset: 0x1060 */
  uint32_t CLKDIV3;                                /**< System Clock Divider Register 3, offset: 0x1064 */
  uint32_t CLKDIV4;                                /**< System Clock Divider Register 4, offset: 0x1068 */
  uint32_t MCR;                                    /**< Misc Control Register, offset: 0x106C */
} volatile *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register accessors */
#line 16254 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/* SOPT1 Bit Fields */
#line 16278 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SOPT1CFG Bit Fields */
#line 16285 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SOPT2 Bit Fields */
#line 16327 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SOPT4 Bit Fields */
#line 16364 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SOPT5 Bit Fields */
#line 16377 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SOPT6 Bit Fields */
#line 16390 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SOPT7 Bit Fields */
#line 16419 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SDID Bit Fields */
#line 16429 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCGC1 Bit Fields */




/* SCGC2 Bit Fields */
#line 16441 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCGC3 Bit Fields */
#line 16466 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCGC4 Bit Fields */
#line 16501 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCGC5 Bit Fields */
#line 16532 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCGC6 Bit Fields */
#line 16567 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCGC7 Bit Fields */
#line 16576 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CLKDIV1 Bit Fields */
#line 16589 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CLKDIV2 Bit Fields */
#line 16600 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FCFG1 Bit Fields */
#line 16612 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FCFG2 Bit Fields */
#line 16623 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* UIDH Bit Fields */



/* UIDMH Bit Fields */



/* UIDML Bit Fields */



/* UIDL Bit Fields */



/* CLKDIV3 Bit Fields */
#line 16646 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CLKDIV4 Bit Fields */
#line 16658 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* MCR Bit Fields */
#line 16675 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base pointer */


/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register instance definitions */
/* SIM */
#line 16723 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SIM_Peripheral */


/* ----------------------------------------------------------------------------
   -- SMC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Peripheral SMC
 * @{
 */

/** SMC - Peripheral register structure */
typedef struct SMC_MemMap {
  uint8_t PMPROT;                                  /**< Power Mode Protection Register, offset: 0x0 */
  uint8_t PMCTRL;                                  /**< Power Mode Control Register, offset: 0x1 */
  uint8_t VLLSCTRL;                                /**< VLLS Control Register, offset: 0x2 */
  uint8_t PMSTAT;                                  /**< Power Mode Status Register, offset: 0x3 */
} volatile *SMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register accessors */





/**
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* PMPROT Bit Fields */
#line 16788 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PMCTRL Bit Fields */
#line 16799 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* VLLSCTRL Bit Fields */



/* PMSTAT Bit Fields */




/**
 * @}
 */ /* end of group SMC_Register_Masks */


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base pointer */


/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register instance definitions */
/* SMC */





/**
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SPI
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Peripheral SPI
 * @{
 */

/** SPI - Peripheral register structure */
typedef struct SPI_MemMap {
  uint32_t MCR;                                    /**< DSPI Module Configuration Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  uint32_t TCR;                                    /**< DSPI Transfer Count Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    uint32_t CTAR[2];                                /**< DSPI Clock and Transfer Attributes Register (In Master Mode), array offset: 0xC, array step: 0x4 */
    uint32_t CTAR_SLAVE[1];                          /**< DSPI Clock and Transfer Attributes Register (In Slave Mode), array offset: 0xC, array step: 0x4 */
  };
  uint8_t RESERVED_1[24];
  uint32_t SR;                                     /**< DSPI Status Register, offset: 0x2C */
  uint32_t RSER;                                   /**< DSPI DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                          /* offset: 0x34 */
    uint32_t PUSHR;                                  /**< DSPI PUSH TX FIFO Register In Master Mode, offset: 0x34 */
    uint32_t PUSHR_SLAVE;                            /**< DSPI PUSH TX FIFO Register In Slave Mode, offset: 0x34 */
  };
  uint32_t POPR;                                   /**< DSPI POP RX FIFO Register, offset: 0x38 */
  uint32_t TXFR0;                                  /**< DSPI Transmit FIFO Registers, offset: 0x3C */
  uint32_t TXFR1;                                  /**< DSPI Transmit FIFO Registers, offset: 0x40 */
  uint32_t TXFR2;                                  /**< DSPI Transmit FIFO Registers, offset: 0x44 */
  uint32_t TXFR3;                                  /**< DSPI Transmit FIFO Registers, offset: 0x48 */
  uint8_t RESERVED_2[48];
  uint32_t RXFR0;                                  /**< DSPI Receive FIFO Registers, offset: 0x7C */
  uint32_t RXFR1;                                  /**< DSPI Receive FIFO Registers, offset: 0x80 */
  uint32_t RXFR2;                                  /**< DSPI Receive FIFO Registers, offset: 0x84 */
  uint32_t RXFR3;                                  /**< DSPI Receive FIFO Registers, offset: 0x88 */
} volatile *SPI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register accessors */
#line 16909 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/* MCR Bit Fields */
#line 16960 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TCR Bit Fields */



/* CTAR Bit Fields */
#line 17000 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CTAR_SLAVE Bit Fields */
#line 17008 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SR Bit Fields */
#line 17035 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RSER Bit Fields */
#line 17052 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PUSHR Bit Fields */
#line 17068 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PUSHR_SLAVE Bit Fields */



/* POPR Bit Fields */



/* TXFR0 Bit Fields */
#line 17083 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TXFR1 Bit Fields */
#line 17090 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TXFR2 Bit Fields */
#line 17097 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TXFR3 Bit Fields */
#line 17104 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RXFR0 Bit Fields */



/* RXFR1 Bit Fields */



/* RXFR2 Bit Fields */



/* RXFR3 Bit Fields */




/**
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base pointer */

/** Peripheral SPI1 base pointer */

/** Peripheral SPI2 base pointer */


/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register instance definitions */
/* SPI0 */
#line 17164 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SPI1 */
#line 17183 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SPI2 */
#line 17202 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* SPI - Register array accessors */
#line 17210 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SPI_Peripheral */


/* ----------------------------------------------------------------------------
   -- SysTick
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Peripheral SysTick
 * @{
 */

/** SysTick - Peripheral register structure */
typedef struct SysTick_MemMap {
  uint32_t CSR;                                    /**< SysTick Control and Status Register, offset: 0x0 */
  uint32_t RVR;                                    /**< SysTick Reload Value Register, offset: 0x4 */
  uint32_t CVR;                                    /**< SysTick Current Value Register, offset: 0x8 */
  uint32_t CALIB;                                  /**< SysTick Calibration Value Register, offset: 0xC */
} volatile *SysTick_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register accessors */





/**
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SysTick Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Register_Masks SysTick Register Masks
 * @{
 */

/* CSR Bit Fields */
#line 17277 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RVR Bit Fields */



/* CVR Bit Fields */



/* CALIB Bit Fields */
#line 17293 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group SysTick_Register_Masks */


/* SysTick - Peripheral instance base addresses */
/** Peripheral SysTick base pointer */


/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register instance definitions */
/* SysTick */





/**
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SysTick_Peripheral */


/* ----------------------------------------------------------------------------
   -- TPIU
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Peripheral TPIU
 * @{
 */

/** TPIU - Peripheral register structure */
typedef struct TPIU_MemMap {
  uint32_t SSPSR;                                  /**< Supported Parallel Port Size Register, offset: 0x0 */
  uint32_t CSPSR;                                  /**< Current Parallel Port Size Register, offset: 0x4 */
  uint8_t RESERVED_0[8];
  uint32_t ACPR;                                   /**< Asynchronous Clock Prescaler Register, offset: 0x10 */
  uint8_t RESERVED_1[220];
  uint32_t SPPR;                                   /**< Selected Pin Protocol Register, offset: 0xF0 */
  uint8_t RESERVED_2[524];
  uint32_t FFSR;                                   /**< Formatter and Flush Status Register, offset: 0x300 */
  uint32_t FFCR;                                   /**< Formatter and Flush Control Register, offset: 0x304 */
  uint32_t FSCR;                                   /**< Formatter Synchronization Counter Register, offset: 0x308 */
  uint8_t RESERVED_3[3036];
  uint32_t TRIGGER;                                /**< Trigger Register, offset: 0xEE8 */
  uint32_t FIFODATA0;                              /**< FIFODATA0 Register, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Test ATB Control 2 Register, offset: 0xEF0 */
  uint8_t RESERVED_4[4];
  uint32_t ITATBCTR0;                              /**< Integration Test ATB Control 0 Register, offset: 0xEF8 */
  uint32_t FIFODATA1;                              /**< FIFODATA1 Register, offset: 0xEFC */
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_6[32];
  uint32_t DEVID;                                  /**< TPIU_DEVID Register, offset: 0xFC8 */
  uint8_t RESERVED_7[4];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID4;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *TPIU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TPIU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Register_Accessor_Macros TPIU - Register accessor macros
 * @{
 */


/* TPIU - Register accessors */
#line 17418 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group TPIU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TPIU Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Register_Masks TPIU Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group TPIU_Register_Masks */


/* TPIU - Peripheral instance base addresses */
/** Peripheral TPIU base pointer */


/* ----------------------------------------------------------------------------
   -- TPIU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Register_Accessor_Macros TPIU - Register accessor macros
 * @{
 */


/* TPIU - Register instance definitions */
/* TPIU */
#line 17483 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group TPIU_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group TPIU_Peripheral */


/* ----------------------------------------------------------------------------
   -- TSI
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Peripheral TSI
 * @{
 */

/** TSI - Peripheral register structure */
typedef struct TSI_MemMap {
  uint32_t GENCS;                                  /**< General Control and Status Register, offset: 0x0 */
  uint32_t SCANC;                                  /**< SCAN Control Register, offset: 0x4 */
  uint32_t PEN;                                    /**< Pin Enable Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t WUCNTR;                                 /**< Wake-Up Channel Counter Register, offset: 0x10 */
  uint8_t RESERVED_1[236];
  uint32_t CNTR1;                                  /**< Counter Register, offset: 0x100 */
  uint32_t CNTR3;                                  /**< Counter Register, offset: 0x104 */
  uint32_t CNTR5;                                  /**< Counter Register, offset: 0x108 */
  uint32_t CNTR7;                                  /**< Counter Register, offset: 0x10C */
  uint32_t CNTR9;                                  /**< Counter Register, offset: 0x110 */
  uint32_t CNTR11;                                 /**< Counter Register, offset: 0x114 */
  uint32_t CNTR13;                                 /**< Counter Register, offset: 0x118 */
  uint32_t CNTR15;                                 /**< Counter Register, offset: 0x11C */
  uint32_t THRESHOLD;                              /**< Low Power Channel Threshold Register, offset: 0x120 */
} volatile *TSI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros
 * @{
 */


/* TSI - Register accessors */
#line 17546 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group TSI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Register_Masks TSI Register Masks
 * @{
 */

/* GENCS Bit Fields */
#line 17597 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SCANC Bit Fields */
#line 17613 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PEN Bit Fields */
#line 17649 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WUCNTR Bit Fields */



/* CNTR1 Bit Fields */
#line 17660 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNTR3 Bit Fields */
#line 17667 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNTR5 Bit Fields */
#line 17674 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNTR7 Bit Fields */
#line 17681 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNTR9 Bit Fields */
#line 17688 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNTR11 Bit Fields */
#line 17695 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNTR13 Bit Fields */
#line 17702 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CNTR15 Bit Fields */
#line 17709 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* THRESHOLD Bit Fields */
#line 17716 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group TSI_Register_Masks */


/* TSI - Peripheral instance base addresses */
/** Peripheral TSI0 base pointer */


/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros
 * @{
 */


/* TSI - Register instance definitions */
/* TSI0 */
#line 17751 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group TSI_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group TSI_Peripheral */


/* ----------------------------------------------------------------------------
   -- UART
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Peripheral UART
 * @{
 */

/** UART - Peripheral register structure */
typedef struct UART_MemMap {
  uint8_t BDH;                                     /**< UART Baud Rate Registers:High, offset: 0x0 */
  uint8_t BDL;                                     /**< UART Baud Rate Registers: Low, offset: 0x1 */
  uint8_t C1;                                      /**< UART Control Register 1, offset: 0x2 */
  uint8_t C2;                                      /**< UART Control Register 2, offset: 0x3 */
  uint8_t S1;                                      /**< UART Status Register 1, offset: 0x4 */
  uint8_t S2;                                      /**< UART Status Register 2, offset: 0x5 */
  uint8_t C3;                                      /**< UART Control Register 3, offset: 0x6 */
  uint8_t D;                                       /**< UART Data Register, offset: 0x7 */
  uint8_t MA1;                                     /**< UART Match Address Registers 1, offset: 0x8 */
  uint8_t MA2;                                     /**< UART Match Address Registers 2, offset: 0x9 */
  uint8_t C4;                                      /**< UART Control Register 4, offset: 0xA */
  uint8_t C5;                                      /**< UART Control Register 5, offset: 0xB */
  uint8_t ED;                                      /**< UART Extended Data Register, offset: 0xC */
  uint8_t MODEM;                                   /**< UART Modem Register, offset: 0xD */
  uint8_t IR;                                      /**< UART Infrared Register, offset: 0xE */
  uint8_t RESERVED_0[1];
  uint8_t PFIFO;                                   /**< UART FIFO Parameters, offset: 0x10 */
  uint8_t CFIFO;                                   /**< UART FIFO Control Register, offset: 0x11 */
  uint8_t SFIFO;                                   /**< UART FIFO Status Register, offset: 0x12 */
  uint8_t TWFIFO;                                  /**< UART FIFO Transmit Watermark, offset: 0x13 */
  uint8_t TCFIFO;                                  /**< UART FIFO Transmit Count, offset: 0x14 */
  uint8_t RWFIFO;                                  /**< UART FIFO Receive Watermark, offset: 0x15 */
  uint8_t RCFIFO;                                  /**< UART FIFO Receive Count, offset: 0x16 */
  uint8_t RESERVED_1[1];
  uint8_t C7816;                                   /**< UART 7816 Control Register, offset: 0x18 */
  uint8_t IE7816;                                  /**< UART 7816 Interrupt Enable Register, offset: 0x19 */
  uint8_t IS7816;                                  /**< UART 7816 Interrupt Status Register, offset: 0x1A */
  union {                                          /* offset: 0x1B */
    uint8_t WP7816_T_TYPE0;                          /**< UART 7816 Wait Parameter Register, offset: 0x1B */
    uint8_t WP7816_T_TYPE1;                          /**< UART 7816 Wait Parameter Register, offset: 0x1B */
  };
  uint8_t WN7816;                                  /**< UART 7816 Wait N Register, offset: 0x1C */
  uint8_t WF7816;                                  /**< UART 7816 Wait FD Register, offset: 0x1D */
  uint8_t ET7816;                                  /**< UART 7816 Error Threshold Register, offset: 0x1E */
  uint8_t TL7816;                                  /**< UART 7816 Transmit Length Register, offset: 0x1F */
  uint8_t RESERVED_2[1];
  uint8_t C6;                                      /**< UART CEA709.1-B Control Register 6, offset: 0x21 */
  uint8_t PCTH;                                    /**< UART CEA709.1-B Packet Cycle Time Counter High, offset: 0x22 */
  uint8_t PCTL;                                    /**< UART CEA709.1-B Packet Cycle Time Counter Low, offset: 0x23 */
  uint8_t B1T;                                     /**< UART CEA709.1-B Beta1 Timer, offset: 0x24 */
  uint8_t SDTH;                                    /**< UART CEA709.1-B Secondary Delay Timer High, offset: 0x25 */
  uint8_t SDTL;                                    /**< UART CEA709.1-B Secondary Delay Timer Low, offset: 0x26 */
  uint8_t PRE;                                     /**< UART CEA709.1-B Preamble, offset: 0x27 */
  uint8_t TPL;                                     /**< UART CEA709.1-B Transmit Packet Length, offset: 0x28 */
  uint8_t IE;                                      /**< UART CEA709.1-B Interrupt Enable Register, offset: 0x29 */
  uint8_t WB;                                      /**< UART CEA709.1-B WBASE, offset: 0x2A */
  uint8_t S3;                                      /**< UART CEA709.1-B Status Register, offset: 0x2B */
  uint8_t S4;                                      /**< UART CEA709.1-B Status Register, offset: 0x2C */
  uint8_t RPL;                                     /**< UART CEA709.1-B Received Packet Length, offset: 0x2D */
  uint8_t RPREL;                                   /**< UART CEA709.1-B Received Preamble Length, offset: 0x2E */
  uint8_t CPW;                                     /**< UART CEA709.1-B Collision Pulse Width, offset: 0x2F */
  uint8_t RIDT;                                    /**< UART CEA709.1-B Receive Indeterminate Time, offset: 0x30 */
  uint8_t TIDT;                                    /**< UART CEA709.1-B Transmit Indeterminate Time, offset: 0x31 */
} volatile *UART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register accessors */
#line 17887 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/* BDH Bit Fields */
#line 17910 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* BDL Bit Fields */



/* C1 Bit Fields */
#line 17931 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C2 Bit Fields */
#line 17948 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* S1 Bit Fields */
#line 17965 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* S2 Bit Fields */
#line 17982 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C3 Bit Fields */
#line 17999 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* D Bit Fields */



/* MA1 Bit Fields */



/* MA2 Bit Fields */



/* C4 Bit Fields */
#line 18021 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* C5 Bit Fields */




/* ED Bit Fields */




/* MODEM Bit Fields */
#line 18040 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IR Bit Fields */





/* PFIFO Bit Fields */
#line 18057 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CFIFO Bit Fields */
#line 18066 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SFIFO Bit Fields */
#line 18075 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TWFIFO Bit Fields */



/* TCFIFO Bit Fields */



/* RWFIFO Bit Fields */



/* RCFIFO Bit Fields */



/* C7816 Bit Fields */
#line 18102 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IE7816 Bit Fields */
#line 18117 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* IS7816 Bit Fields */
#line 18132 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WP7816_T_TYPE0 Bit Fields */



/* WP7816_T_TYPE1 Bit Fields */
#line 18143 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WN7816 Bit Fields */



/* WF7816 Bit Fields */



/* ET7816 Bit Fields */
#line 18158 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TL7816 Bit Fields */



/* C6 Bit Fields */
#line 18171 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PCTH Bit Fields */



/* PCTL Bit Fields */



/* B1T Bit Fields */



/* SDTH Bit Fields */



/* SDTL Bit Fields */



/* PRE Bit Fields */



/* TPL Bit Fields */



/* IE Bit Fields */
#line 18214 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* WB Bit Fields */



/* S3 Bit Fields */
#line 18235 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* S4 Bit Fields */
#line 18245 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* RPL Bit Fields */



/* RPREL Bit Fields */



/* CPW Bit Fields */



/* RIDT Bit Fields */



/* TIDT Bit Fields */




/**
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base pointer */

/** Peripheral UART1 base pointer */

/** Peripheral UART2 base pointer */

/** Peripheral UART3 base pointer */

/** Peripheral UART4 base pointer */

/** Peripheral UART5 base pointer */


/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register instance definitions */
/* UART0 */
#line 18345 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* UART1 */
#line 18368 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* UART2 */
#line 18391 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* UART3 */
#line 18414 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* UART4 */
#line 18437 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* UART5 */
#line 18460 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group UART_Peripheral */


/* ----------------------------------------------------------------------------
   -- USB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Peripheral USB
 * @{
 */

/** USB - Peripheral register structure */
typedef struct USB_MemMap {
  uint8_t PERID;                                   /**< Peripheral ID Register, offset: 0x0 */
  uint8_t RESERVED_0[3];
  uint8_t IDCOMP;                                  /**< Peripheral ID Complement Register, offset: 0x4 */
  uint8_t RESERVED_1[3];
  uint8_t REV;                                     /**< Peripheral Revision Register, offset: 0x8 */
  uint8_t RESERVED_2[3];
  uint8_t ADDINFO;                                 /**< Peripheral Additional Info Register, offset: 0xC */
  uint8_t RESERVED_3[3];
  uint8_t OTGISTAT;                                /**< OTG Interrupt Status Register, offset: 0x10 */
  uint8_t RESERVED_4[3];
  uint8_t OTGICR;                                  /**< OTG Interrupt Control Register, offset: 0x14 */
  uint8_t RESERVED_5[3];
  uint8_t OTGSTAT;                                 /**< OTG Status Register, offset: 0x18 */
  uint8_t RESERVED_6[3];
  uint8_t OTGCTL;                                  /**< OTG Control Register, offset: 0x1C */
  uint8_t RESERVED_7[99];
  uint8_t ISTAT;                                   /**< Interrupt Status Register, offset: 0x80 */
  uint8_t RESERVED_8[3];
  uint8_t INTEN;                                   /**< Interrupt Enable Register, offset: 0x84 */
  uint8_t RESERVED_9[3];
  uint8_t ERRSTAT;                                 /**< Error Interrupt Status Register, offset: 0x88 */
  uint8_t RESERVED_10[3];
  uint8_t ERREN;                                   /**< Error Interrupt Enable Register, offset: 0x8C */
  uint8_t RESERVED_11[3];
  uint8_t STAT;                                    /**< Status Register, offset: 0x90 */
  uint8_t RESERVED_12[3];
  uint8_t CTL;                                     /**< Control Register, offset: 0x94 */
  uint8_t RESERVED_13[3];
  uint8_t ADDR;                                    /**< Address Register, offset: 0x98 */
  uint8_t RESERVED_14[3];
  uint8_t BDTPAGE1;                                /**< BDT Page Register 1, offset: 0x9C */
  uint8_t RESERVED_15[3];
  uint8_t FRMNUML;                                 /**< Frame Number Register Low, offset: 0xA0 */
  uint8_t RESERVED_16[3];
  uint8_t FRMNUMH;                                 /**< Frame Number Register High, offset: 0xA4 */
  uint8_t RESERVED_17[3];
  uint8_t TOKEN;                                   /**< Token Register, offset: 0xA8 */
  uint8_t RESERVED_18[3];
  uint8_t SOFTHLD;                                 /**< SOF Threshold Register, offset: 0xAC */
  uint8_t RESERVED_19[3];
  uint8_t BDTPAGE2;                                /**< BDT Page Register 2, offset: 0xB0 */
  uint8_t RESERVED_20[3];
  uint8_t BDTPAGE3;                                /**< BDT Page Register 3, offset: 0xB4 */
  uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    uint8_t ENDPT;                                   /**< Endpoint Control Register, array offset: 0xC0, array step: 0x4 */
    uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  uint8_t USBCTRL;                                 /**< USB Control Register, offset: 0x100 */
  uint8_t RESERVED_22[3];
  uint8_t OBSERVE;                                 /**< USB OTG Observe Register, offset: 0x104 */
  uint8_t RESERVED_23[3];
  uint8_t CONTROL;                                 /**< USB OTG Control Register, offset: 0x108 */
  uint8_t RESERVED_24[3];
  uint8_t USBTRC0;                                 /**< USB Transceiver Control Register 0, offset: 0x10C */
  uint8_t RESERVED_25[7];
  uint8_t USBFRMADJUST;                            /**< Frame Adjust Register, offset: 0x114 */
} volatile *USB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register accessors */
#line 18580 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/* PERID Bit Fields */



/* IDCOMP Bit Fields */



/* REV Bit Fields */



/* ADDINFO Bit Fields */





/* OTGISTAT Bit Fields */
#line 18626 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OTGICR Bit Fields */
#line 18639 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OTGSTAT Bit Fields */
#line 18652 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OTGCTL Bit Fields */
#line 18661 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ISTAT Bit Fields */
#line 18678 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* INTEN Bit Fields */
#line 18695 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ERRSTAT Bit Fields */
#line 18710 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ERREN Bit Fields */
#line 18725 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* STAT Bit Fields */
#line 18733 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CTL Bit Fields */
#line 18750 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ADDR Bit Fields */





/* BDTPAGE1 Bit Fields */



/* FRMNUML Bit Fields */



/* FRMNUMH Bit Fields */



/* TOKEN Bit Fields */
#line 18775 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* SOFTHLD Bit Fields */



/* BDTPAGE2 Bit Fields */



/* BDTPAGE3 Bit Fields */



/* ENDPT Bit Fields */
#line 18802 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* USBCTRL Bit Fields */




/* OBSERVE Bit Fields */
#line 18814 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CONTROL Bit Fields */


/* USBTRC0 Bit Fields */
#line 18826 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* USBFRMADJUST Bit Fields */




/**
 * @}
 */ /* end of group USB_Register_Masks */


/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base pointer */


/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register instance definitions */
/* USB0 */
#line 18895 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* USB - Register array accessors */


/**
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group USB_Peripheral */


/* ----------------------------------------------------------------------------
   -- USBDCD
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Peripheral USBDCD
 * @{
 */

/** USBDCD - Peripheral register structure */
typedef struct USBDCD_MemMap {
  uint32_t CONTROL;                                /**< Control Register, offset: 0x0 */
  uint32_t CLOCK;                                  /**< Clock Register, offset: 0x4 */
  uint32_t STATUS;                                 /**< Status Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t TIMER0;                                 /**< TIMER0 Register, offset: 0x10 */
  uint32_t TIMER1;                                 /**< , offset: 0x14 */
  uint32_t TIMER2;                                 /**< , offset: 0x18 */
} volatile *USBDCD_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros
 * @{
 */


/* USBDCD - Register accessors */
#line 18946 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group USBDCD_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USBDCD Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Register_Masks USBDCD Register Masks
 * @{
 */

/* CONTROL Bit Fields */
#line 18972 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* CLOCK Bit Fields */





/* STATUS Bit Fields */
#line 18991 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TIMER0 Bit Fields */
#line 18998 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TIMER1 Bit Fields */
#line 19005 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TIMER2 Bit Fields */
#line 19012 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group USBDCD_Register_Masks */


/* USBDCD - Peripheral instance base addresses */
/** Peripheral USBDCD base pointer */


/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros
 * @{
 */


/* USBDCD - Register instance definitions */
/* USBDCD */
#line 19040 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group USBDCD_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group USBDCD_Peripheral */


/* ----------------------------------------------------------------------------
   -- USBHS
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBHS_Peripheral USBHS
 * @{
 */

/** USBHS - Peripheral register structure */
typedef struct USBHS_MemMap {
  uint32_t ID;                                     /**< Identification Register, offset: 0x0 */
  uint32_t HWGENERAL;                              /**< General Hardware Parameters Register, offset: 0x4 */
  uint32_t HWHOST;                                 /**< Host Hardware Parameters Register, offset: 0x8 */
  uint32_t HWDEVICE;                               /**< Device Hardware Parameters Register, offset: 0xC */
  uint32_t HWTXBUF;                                /**< Transmit Buffer Hardware Parameters Register, offset: 0x10 */
  uint32_t HWRXBUF;                                /**< Receive Buffer Hardware Parameters Register, offset: 0x14 */
  uint8_t RESERVED_0[104];
  uint32_t GPTIMER0LD;                             /**< General Purpose Timer n Load Register, offset: 0x80 */
  uint32_t GPTIMER0CTL;                            /**< General Purpose Timer n Control Register, offset: 0x84 */
  uint32_t GPTIMER1LD;                             /**< General Purpose Timer n Load Register, offset: 0x88 */
  uint32_t GPTIMER1CTL;                            /**< General Purpose Timer n Control Register, offset: 0x8C */
  uint8_t RESERVED_1[112];
  uint16_t HCIVERSION;                             /**< Host Controller Interface Version Register, offset: 0x100 */
  uint8_t RESERVED_2[1];
  uint8_t CAPLENGTH;                               /**< Capability Registers Length Register, offset: 0x103 */
  uint32_t HCSPARAMS;                              /**< Host Controller Structural Parameters Register, offset: 0x104 */
  uint32_t HCCPARAMS;                              /**< Host Controller Capability Parameters Register, offset: 0x108 */
  uint8_t RESERVED_3[22];
  uint16_t DCIVERSION;                             /**< Device Controller Interface Version, offset: 0x122 */
  uint32_t DCCPARAMS;                              /**< Device Controller Capability Parameters, offset: 0x124 */
  uint8_t RESERVED_4[24];
  uint32_t USBCMD;                                 /**< USB Command Register, offset: 0x140 */
  uint32_t USBSTS;                                 /**< USB Status Register, offset: 0x144 */
  uint32_t USBINTR;                                /**< USB Interrupt Enable Register, offset: 0x148 */
  uint32_t FRINDEX;                                /**< Frame Index Register, offset: 0x14C */
  uint8_t RESERVED_5[4];
  union {                                          /* offset: 0x154 */
    uint32_t DEVICEADDR;                             /**< Device Address Register, offset: 0x154 */
    uint32_t PERIODICLISTBASE;                       /**< Periodic Frame List Base Address Register, offset: 0x154 */
  };
  union {                                          /* offset: 0x158 */
    uint32_t ASYNCLISTADDR;                          /**< Current Asynchronous List Address Register, offset: 0x158 */
    uint32_t EPLISTADDR;                             /**< Endpoint List Address Register, offset: 0x158 */
  };
  uint32_t TTCTRL;                                 /**< Host TT Asynchronous Buffer Control, offset: 0x15C */
  uint32_t BURSTSIZE;                              /**< Master Interface Data Burst Size Register, offset: 0x160 */
  uint32_t TXFILLTUNING;                           /**< Transmit FIFO Tuning Control Register, offset: 0x164 */
  uint8_t RESERVED_6[8];
  uint32_t ULPI_VIEWPORT;                          /**< ULPI Register Access, offset: 0x170 */
  uint8_t RESERVED_7[12];
  uint32_t CONFIGFLAG;                             /**< Configure Flag Register, offset: 0x180 */
  uint32_t PORTSC1;                                /**< Port Status and Control Registers, offset: 0x184 */
  uint8_t RESERVED_8[28];
  uint32_t OTGSC;                                  /**< On-the-Go Status and Control Register, offset: 0x1A4 */
  uint32_t USBMODE;                                /**< USB Mode Register, offset: 0x1A8 */
  uint32_t EPSETUPSR;                              /**< Endpoint Setup Status Register, offset: 0x1AC */
  uint32_t EPPRIME;                                /**< Endpoint Initialization Register, offset: 0x1B0 */
  uint32_t EPFLUSH;                                /**< Endpoint Flush Register, offset: 0x1B4 */
  uint32_t EPSR;                                   /**< Endpoint Status Register, offset: 0x1B8 */
  uint32_t EPCOMPLETE;                             /**< Endpoint Complete Register, offset: 0x1BC */
  uint32_t EPCR0;                                  /**< Endpoint Control Register 0, offset: 0x1C0 */
  uint32_t EPCR[3];                                /**< Endpoint Control Register n, array offset: 0x1C4, array step: 0x4 */
} volatile *USBHS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USBHS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBHS_Register_Accessor_Macros USBHS - Register accessor macros
 * @{
 */


/* USBHS - Register accessors */
#line 19166 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group USBHS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USBHS Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBHS_Register_Masks USBHS Register Masks
 * @{
 */

/* ID Bit Fields */
#line 19191 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HWGENERAL Bit Fields */
#line 19201 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HWHOST Bit Fields */
#line 19213 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HWDEVICE Bit Fields */





/* HWTXBUF Bit Fields */
#line 19231 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HWRXBUF Bit Fields */
#line 19238 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* GPTIMER0LD Bit Fields */



/* GPTIMER0CTL Bit Fields */
#line 19252 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* GPTIMER1LD Bit Fields */



/* GPTIMER1CTL Bit Fields */
#line 19266 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HCIVERSION Bit Fields */



/* CAPLENGTH Bit Fields */



/* HCSPARAMS Bit Fields */
#line 19294 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* HCCPARAMS Bit Fields */
#line 19307 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DCIVERSION Bit Fields */



/* DCCPARAMS Bit Fields */
#line 19319 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* USBCMD Bit Fields */
#line 19347 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* USBSTS Bit Fields */
#line 19386 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* USBINTR Bit Fields */
#line 19417 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* FRINDEX Bit Fields */
#line 19424 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* DEVICEADDR Bit Fields */



/* PERIODICLISTBASE Bit Fields */



/* ASYNCLISTADDR Bit Fields */



/* EPLISTADDR Bit Fields */



/* TTCTRL Bit Fields */





/* BURSTSIZE Bit Fields */
#line 19453 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* TXFILLTUNING Bit Fields */
#line 19463 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* ULPI_VIEWPORT Bit Fields */
#line 19484 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* PORTSC1 Bit Fields */
#line 19534 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* OTGSC Bit Fields */
#line 19587 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* USBMODE Bit Fields */
#line 19597 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EPSETUPSR Bit Fields */



/* EPPRIME Bit Fields */
#line 19608 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EPFLUSH Bit Fields */
#line 19615 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EPSR Bit Fields */
#line 19622 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EPCOMPLETE Bit Fields */
#line 19629 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EPCR0 Bit Fields */
#line 19644 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* EPCR Bit Fields */
#line 19671 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group USBHS_Register_Masks */


/* USBHS - Peripheral instance base addresses */
/** Peripheral USBHS base pointer */


/* ----------------------------------------------------------------------------
   -- USBHS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBHS_Register_Accessor_Macros USBHS - Register accessor macros
 * @{
 */


/* USBHS - Register instance definitions */
/* USBHS */
#line 19734 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* USBHS - Register array accessors */


/**
 * @}
 */ /* end of group USBHS_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group USBHS_Peripheral */


/* ----------------------------------------------------------------------------
   -- VREF
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Peripheral VREF
 * @{
 */

/** VREF - Peripheral register structure */
typedef struct VREF_MemMap {
  uint8_t TRM;                                     /**< VREF Trim Register, offset: 0x0 */
  uint8_t SC;                                      /**< VREF Status and Control Register, offset: 0x1 */
} volatile *VREF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros
 * @{
 */


/* VREF - Register accessors */



/**
 * @}
 */ /* end of group VREF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Register_Masks VREF Register Masks
 * @{
 */

/* TRM Bit Fields */



/* SC Bit Fields */
#line 19805 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group VREF_Register_Masks */


/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base pointer */


/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros
 * @{
 */


/* VREF - Register instance definitions */
/* VREF */



/**
 * @}
 */ /* end of group VREF_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group VREF_Peripheral */


/* ----------------------------------------------------------------------------
   -- WDOG
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Peripheral WDOG
 * @{
 */

/** WDOG - Peripheral register structure */
typedef struct WDOG_MemMap {
  uint16_t STCTRLH;                                /**< Watchdog Status and Control Register High, offset: 0x0 */
  uint16_t STCTRLL;                                /**< Watchdog Status and Control Register Low, offset: 0x2 */
  uint16_t TOVALH;                                 /**< Watchdog Time-out Value Register High, offset: 0x4 */
  uint16_t TOVALL;                                 /**< Watchdog Time-out Value Register Low, offset: 0x6 */
  uint16_t WINH;                                   /**< Watchdog Window Register High, offset: 0x8 */
  uint16_t WINL;                                   /**< Watchdog Window Register Low, offset: 0xA */
  uint16_t REFRESH;                                /**< Watchdog Refresh Register, offset: 0xC */
  uint16_t UNLOCK;                                 /**< Watchdog Unlock Register, offset: 0xE */
  uint16_t TMROUTH;                                /**< Watchdog Timer Output Register High, offset: 0x10 */
  uint16_t TMROUTL;                                /**< Watchdog Timer Output Register Low, offset: 0x12 */
  uint16_t RSTCNT;                                 /**< Watchdog Reset Count Register, offset: 0x14 */
  uint16_t PRESC;                                  /**< Watchdog Prescaler Register, offset: 0x16 */
} volatile *WDOG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register accessors */
#line 19888 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/* STCTRLH Bit Fields */
#line 19931 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"
/* STCTRLL Bit Fields */


/* TOVALH Bit Fields */



/* TOVALL Bit Fields */



/* WINH Bit Fields */



/* WINL Bit Fields */



/* REFRESH Bit Fields */



/* UNLOCK Bit Fields */



/* TMROUTH Bit Fields */



/* TMROUTL Bit Fields */



/* RSTCNT Bit Fields */



/* PRESC Bit Fields */




/**
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base pointer */


/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register instance definitions */
/* WDOG */
#line 20008 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/**
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group WDOG_Peripheral */


/*
** End of section using anonymous unions
*/






  #pragma language=default




/**
 * @}
 */ /* end of group Peripheral_defines */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup Backward_Compatibility_Symbols Backward Compatibility
 * @{
 */

/* No backward compatibility issues. */

/**
 * @}
 */ /* end of group Backward_Compatibility_Symbols */


#line 20062 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\headers\\MK70F12.h"

/* MK70F12.h, eof. */
#line 89 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\main.h"
#line 102 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\main.h"

// typedef definitions
typedef unsigned char Byte;
typedef unsigned long LWord;
typedef unsigned short Word;

#line 127 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"
/******************************************************************************/

//  Kinetis flash memory macros









#line 148 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"










//  Kinetis memory sizes











//  size of one protection section depends on flash size in Bytes (protected block = flash size / 32)


//  size of bootloader in kilobytes 



//  Generation of value for FPROT register (protection of bootloader)






#line 213 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"






    /** Flash block count of this MCU */







  



  



  



  



  
#line 253 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"



//  default values of GPIO Alternatives of the port  (Alternative to UART)
#line 265 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"






















//  PIN alternative definition





//  PIN alternative definition















//  init macro for multiplexer setting - alternative UART

//  init macro for multiplexer setting - alternative GPIO



//  Trim auto calibration 
//  Trim register


//      As calibration impulse can be used break impulse with 10 bits or zero impulse with 9bit. Reason is impossibility of using break impulse on the USB VIRTUAL SERIAL LINK   









//      initialization for boot pin enable (MUX - GPIO alternative & PE - pull-up enable)      





typedef union _FlashConfig_t
{
  unsigned int Data[4];
  struct {
    unsigned int BackDoorKey[2];
    unsigned int Protection;
    unsigned int Config;
  };
} FlashConfig_t;


/******************************************************************************/
//
//       Compiler differencies
//
//      __CWCC__                - CodeWarrior
//      __GNUC__                - GNU
//      __IAR_SYSTEMS_ICC__     - IAR
//      __ARMCC_VERSION         - KEIL
//
/******************************************************************************/

#line 369 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"


// Register redefinition


  // Bus clock frequency






#line 388 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"
  
#line 398 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"



#line 414 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"





                                                                        
                                    

                                    
#line 475 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\IAR_6_4\\..\\CommonSource\\bootloader\\kinetis_params.h"



#line 17 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.c"
#line 1 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.h"
/*****************************************************************************
 * (c) Copyright 2011, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      flash_kinetis.h
 * @author    R20253
 * @version   1.0.8.0
 * @date      Dec-13-2012
 * @brief     Flash programming driver header file
 * @par       
 * @include   
 * @par       
 * @include         
 ******************************************************************************/



//  Flash hardware algorithm operation commands 
















//  FCOOB register structure
typedef union 
{
  Byte all[12];
  struct
  {
    Byte fccob3;
    Byte fccob2;
    Byte fccob1;
    Byte fccob0;
    Byte fccob7;
    Byte fccob6;
    Byte fccob5;
    Byte fccob4;
    Byte fccobB;
    Byte fccobA;
    Byte fccob9;
    Byte fccob8;
  }regs;
  
  struct
  {
    LWord fccob3210;
    LWord fccob7654;
    LWord fccobBA98;
  }regsLong;
}FCC0B_STR;

//  API FUNCTION FOR KINETIS FLASH DRIVER
void  FLASH_Initialization(void);
LWord FLASH_EraseSector(LWord destination);
LWord FLASH_ProgramLongWord(LWord destination, LWord data);
LWord FLASH_ProgramPhrase(LWord destination, LWord * data64b);
LWord FLASH_ProgramSectionByLongs(LWord destination, LWord* pSource, LWord size);
LWord FLASH_ProgramSectionByPhrases(LWord destination, LWord* pSource, LWord size);
LWord FLASH_MassErase(void);






#line 18 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.c"


  #pragma section = "codeRam"
  #pragma location = "codeRam"
  Byte buffer[128];

  #pragma section = "default"
  #pragma location = "default"
#line 32 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.c"

  
FCC0B_STR CommandObj;



//  internal driver function
extern LWord FLASH_FlashCommandSequenceStart(Byte index);

/********************************************************
* Init Function 
*
********************************************************/
void FLASH_Initialization(void)
{
  LWord i;
  volatile Byte* ptr_FlashCommandSequenceStart = ((Byte*)FLASH_FlashCommandSequenceStart - 1);
  
  //  initialize pointer to ram function 
  //  copy function from ROM to RAM
  for(i=0;i<128;i++)
    buffer[i] =	*ptr_FlashCommandSequenceStart++;
  
  //  inititalization of flash clock module 
   ((((SIM_MemMapPtr)0x40047000u))->CLKDIV1) |= (((uint32_t)(((uint32_t)(1))<<16))&0xF0000u);; // done in main function
}


/********************************************************
* Function for Programming of one Long Word 
*
********************************************************/
LWord FLASH_ProgramLongWord(LWord destination, LWord data32b)
{
  /* preparing passing parameter to program the flash block */
#line 73 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.c"
  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = 0x06;
  CommandObj.regsLong.fccob7654 = data32b; 


  return ((LWord (*)(Byte))&buffer[1])(8);
}

/********************************************************
* Function for Programming of one Long Word 
*
********************************************************/
LWord FLASH_ProgramPhrase(LWord destination, LWord * data64b)
{
  /* preparing passing parameter to program the flash block */
  
#line 96 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.c"
  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = 0x07;
  CommandObj.regsLong.fccob7654 = data64b[0];
  CommandObj.regsLong.fccobBA98 = data64b[1];
  
  return ((LWord (*)(Byte))&buffer[1])(12);
}

/********************************************************
* Function for Programming of section by simple longs
*
********************************************************/
LWord FLASH_ProgramSectionByLongs(LWord destination, LWord* pSource, LWord size)
{ 
  while(size--)
  {
    if(FLASH_ProgramLongWord(destination, *pSource++) != 0)
      return 1;
    destination += 4;
  }
  return 0;
}

/********************************************************
* Function for Programming of one section (maximum is 2048 Bytes) 
*
********************************************************/
LWord FLASH_ProgramSectionByPhrases(LWord destination, LWord* pSource, LWord size)
{
  LWord my_size;
  
  // check the size of memory 
  if(size >= 64 - 2)
    return 1;
  
  if(destination & 0x00000003)
    return 1;
  
  // it's neccessary alligment on start of buffer?
  if(destination & 0x00000004)
  {
    LWord tmp_buff[2];
    tmp_buff[0] = 0xFFFFFFFF;    
    tmp_buff[1] = *(pSource++);
    
    //  call flash phrase
    if(FLASH_ProgramPhrase((destination & 0xFFFFFFF8), tmp_buff))
      return 1;
    
    destination += 4;    
  }
  
  my_size = size & 0xFFFFFFFE;
 
  if(my_size)
  {
    //  flash all phrases
    while(my_size)
    {
      //  call flash phrase
      if(FLASH_ProgramPhrase(destination, pSource))
        return 1;
    
      pSource += 2;
      destination += 8;
      my_size -= 2;      
    }
  }
  
  // it's neccessary alligment on end of buffer?
  if(size & 0x00000001)
  {
    LWord tmp_buff[2];
    tmp_buff[0] = *pSource;    
    tmp_buff[1] = 0xFFFFFFFF;
    
    //  call flash phrase
    if(FLASH_ProgramPhrase(destination, tmp_buff))
      return 1;           
  }
  return 0;
}

/********************************************************
* Function for erasing of flash memory sector (0x800)
*
********************************************************/
LWord FLASH_EraseSector(LWord destination)
{  
#line 192 "F:\\Git\\MultiShaft_BootLaoder_Uart_K20\\src\\Kinetis\\CommonSource\\flash\\flash_kinetis.c"
  
  CommandObj.regsLong.fccob3210 = destination;
  CommandObj.regs.fccob0 = 0x09;
  
  return ((LWord (*)(Byte))&buffer[1])(4);
}



