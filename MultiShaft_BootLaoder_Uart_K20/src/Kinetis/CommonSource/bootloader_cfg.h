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

#ifndef BOOTLOADER_CFG_H
#define BOOTLOADER_CFG_H


#if defined(KINETIS_L)
 // #include "AN2295_FRDM_KL25Z_cfg.h"
  #include "AN2295_TWR_KL25_cfg.h"
#elif defined(KINETIS_M)
  //#include "AN2295_VAL_KM34_cfg.h"
  #include "AN2295_TWR_KM34_cfg.h"

#else
  //#include "AN2295_TWR_K20D50_cfg.h"
  //#include "AN2295_TWR_K20D72_cfg.h"
  //#include "AN2295_TWR_K60_cfg.h"
  //#include "AN2295_TWR_K60D100_cfg.h"
  #include "AN2295_TWR_K70120_cfg.h"
  //#include "AN2295_TWR_K20_1M_cfg.h"
#endif

#endif //BOOTLOADER_CFG_H
