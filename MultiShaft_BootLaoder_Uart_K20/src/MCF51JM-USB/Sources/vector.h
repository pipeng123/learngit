#ifndef _VECTOR_H
#define _VECTOR_H

#include "derivative.h"
#include "hc08sprg.h"

#define dummy_ISR NULL

typedef void (* pFun)(void);
extern asm void _startup(void);
extern unsigned long far _SP_INIT;
extern void usb_it_handler(void);


/**************** relocated interrupt vector table ****************/
/**************** The new relocated address of interrupts *********/

#define R_INITSP         (RELINTVECT + (6* INITSP      /4))
#define R_INITPC         (RELINTVECT + (6* INITPC      /4))
#define R_Vaccerr        (RELINTVECT + (6* Vaccerr     /4))
#define R_Vadderr        (RELINTVECT + (6* Vadderr     /4))
#define R_Viinstr        (RELINTVECT + (6* Viinstr     /4))         
#define R_VReserved5     (RELINTVECT + (6* VReserved5  /4))         
#define R_VReserved6     (RELINTVECT + (6* VReserved6  /4))         
#define R_VReserved7     (RELINTVECT + (6* VReserved7  /4))         
#define R_Vprviol        (RELINTVECT + (6* Vprviol     /4))         
#define R_Vtrace         (RELINTVECT + (6* Vtrace      /4))         
#define R_Vunilaop       (RELINTVECT + (6* Vunilaop    /4))         
#define R_Vunilfop       (RELINTVECT + (6* Vunilfop    /4))         
#define R_Vdbgi          (RELINTVECT + (6* Vdbgi       /4))         
#define R_VReserved13    (RELINTVECT + (6* VReserved13 /4))         
#define R_Vferror        (RELINTVECT + (6* Vferror     /4))         
#define R_VReserved15    (RELINTVECT + (6* VReserved15 /4))         
#define R_VReserved16    (RELINTVECT + (6* VReserved16 /4))         
#define R_VReserved17    (RELINTVECT + (6* VReserved17 /4))         
#define R_VReserved18    (RELINTVECT + (6* VReserved18 /4))         
#define R_VReserved19    (RELINTVECT + (6* VReserved19 /4))         
#define R_VReserved20    (RELINTVECT + (6* VReserved20 /4))         
#define R_VReserved21    (RELINTVECT + (6* VReserved21 /4))         
#define R_VReserved22    (RELINTVECT + (6* VReserved22 /4))         
#define R_VReserved23    (RELINTVECT + (6* VReserved23 /4))         
#define R_Vspuri         (RELINTVECT + (6* Vspuri      /4))         
#define R_VReserved25    (RELINTVECT + (6* VReserved25 /4))         
#define R_VReserved26    (RELINTVECT + (6* VReserved26 /4))         
#define R_VReserved27    (RELINTVECT + (6* VReserved27 /4))         
#define R_VReserved28    (RELINTVECT + (6* VReserved28 /4))         
#define R_VReserved29    (RELINTVECT + (6* VReserved29 /4))         
#define R_VReserved30    (RELINTVECT + (6* VReserved30 /4))         
#define R_VReserved31    (RELINTVECT + (6* VReserved31 /4))         
#define R_Vtrap0         (RELINTVECT + (6* Vtrap0      /4))         
#define R_Vtrap1         (RELINTVECT + (6* Vtrap1      /4))         
#define R_Vtrap2         (RELINTVECT + (6* Vtrap2      /4))         
#define R_Vtrap3         (RELINTVECT + (6* Vtrap3      /4))         
#define R_Vtrap4         (RELINTVECT + (6* Vtrap4      /4))         
#define R_Vtrap5         (RELINTVECT + (6* Vtrap5      /4))         
#define R_Vtrap6         (RELINTVECT + (6* Vtrap6      /4))         
#define R_Vtrap7         (RELINTVECT + (6* Vtrap7      /4))         
#define R_Vtrap8         (RELINTVECT + (6* Vtrap8      /4))         
#define R_Vtrap9         (RELINTVECT + (6* Vtrap9      /4))         
#define R_Vtrap10        (RELINTVECT + (6* Vtrap10     /4))         
#define R_Vtrap11        (RELINTVECT + (6* Vtrap11     /4))         
#define R_Vtrap12        (RELINTVECT + (6* Vtrap12     /4))         
#define R_Vtrap13        (RELINTVECT + (6* Vtrap13     /4))         
#define R_Vtrap14        (RELINTVECT + (6* Vtrap14     /4))         
#define R_Vtrap15        (RELINTVECT + (6* Vtrap15     /4))         
#define R_VReserved48    (RELINTVECT + (6* VReserved48 /4))         
#define R_VReserved49    (RELINTVECT + (6* VReserved49 /4))         
#define R_VReserved50    (RELINTVECT + (6* VReserved50 /4))         
#define R_VReserved51    (RELINTVECT + (6* VReserved51 /4))         
#define R_VReserved52    (RELINTVECT + (6* VReserved52 /4))         
#define R_VReserved53    (RELINTVECT + (6* VReserved53 /4))         
#define R_VReserved54    (RELINTVECT + (6* VReserved54 /4))         
#define R_VReserved55    (RELINTVECT + (6* VReserved55 /4))         
#define R_VReserved56    (RELINTVECT + (6* VReserved56 /4))              
#define R_VReserved57    (RELINTVECT + (6* VReserved57 /4))              
#define R_VReserved58    (RELINTVECT + (6* VReserved58 /4))              
#define R_VReserved59    (RELINTVECT + (6* VReserved59 /4))         
#define R_VReserved60    (RELINTVECT + (6* VReserved60 /4))         
#define R_Vunsinstr      (RELINTVECT + (6* Vunsinstr   /4))         
#define R_VReserved62    (RELINTVECT + (6* VReserved62 /4))         
#define R_VReserved63    (RELINTVECT + (6* VReserved63 /4))         
#define R_Virq           (RELINTVECT + (6* Virq        /4))         
#define R_Vlvd           (RELINTVECT + (6* Vlvd        /4))         
#define R_Vlol           (RELINTVECT + (6* Vlol        /4))         
#define R_Vspi1          (RELINTVECT + (6* Vspi1       /4))         
#define R_Vspi2          (RELINTVECT + (6* Vspi2       /4))         
#define R_Vusb           (RELINTVECT + (6* Vusb        /4))         
#define R_VReserved70    (RELINTVECT + (6* VReserved70 /4))         
#define R_Vtpm1ch0       (RELINTVECT + (6* Vtpm1ch0    /4))         
#define R_Vtpm1ch1       (RELINTVECT + (6* Vtpm1ch1    /4))         
#define R_Vtpm1ch2       (RELINTVECT + (6* Vtpm1ch2    /4))         
#define R_Vtpm1ch3       (RELINTVECT + (6* Vtpm1ch3    /4))         
#define R_Vtpm1ch4       (RELINTVECT + (6* Vtpm1ch4    /4))         
#define R_Vtpm1ch5       (RELINTVECT + (6* Vtpm1ch5    /4))         
#define R_Vtpm1ovf       (RELINTVECT + (6* Vtpm1ovf    /4))         
#define R_Vtpm2ch0       (RELINTVECT + (6* Vtpm2ch0    /4))         
#define R_Vtpm2ch1       (RELINTVECT + (6* Vtpm2ch1    /4))         
#define R_Vtpm2ovf       (RELINTVECT + (6* Vtpm2ovf    /4))         
#define R_Vsci1err       (RELINTVECT + (6* Vsci1err    /4))         
#define R_Vsci1rx        (RELINTVECT + (6* Vsci1rx     /4))         
#define R_Vsci1tx        (RELINTVECT + (6* Vsci1tx     /4))         
#define R_Vsci2err       (RELINTVECT + (6* Vsci2err    /4))         
#define R_Vsci2rx        (RELINTVECT + (6* Vsci2rx     /4))         
#define R_Vsci2tx        (RELINTVECT + (6* Vsci2tx     /4))         
#define R_Vkeyboard      (RELINTVECT + (6* Vkeyboard   /4))         
#define R_Vadc           (RELINTVECT + (6* Vadc        /4))         
#define R_Vacmpx         (RELINTVECT + (6* Vacmpx      /4))         
#define R_Viic1x         (RELINTVECT + (6* Viic1x      /4))         
#define R_Vrtc           (RELINTVECT + (6* Vrtc        /4))         
#define R_Viic2x         (RELINTVECT + (6* Viic2x      /4))         
#define R_Vcmt           (RELINTVECT + (6* Vcmt        /4))         
#define R_Vcanwu         (RELINTVECT + (6* Vcanwu      /4))         
#define R_Vcanerr        (RELINTVECT + (6* Vcanerr     /4))         
#define R_Vcanrx         (RELINTVECT + (6* Vcanrx      /4))         
#define R_Vcantx         (RELINTVECT + (6* Vcantx      /4))         
#define R_Vrnga          (RELINTVECT + (6* Vrnga       /4))         
#define R_VReserved99    (RELINTVECT + (6* VReserved99 /4))         
#define R_VReserved100   (RELINTVECT + (6* VReserved100/4))         
#define R_VReserved101   (RELINTVECT + (6* VReserved101/4))         
#define R_VReserved102   (RELINTVECT + (6* VReserved102/4))         
#define R_VReserved103   (RELINTVECT + (6* VReserved103/4))         
#define R_VL7swi         (RELINTVECT + (6* VL7swi      /4))         
#define R_VL6swi         (RELINTVECT + (6* VL6swi      /4))         
#define R_VL5swi         (RELINTVECT + (6* VL5swi      /4))         
#define R_VL4swi         (RELINTVECT + (6* VL4swi      /4))         
#define R_VL3swi         (RELINTVECT + (6* VL3swi      /4))         
#define R_VL2swi         (RELINTVECT + (6* VL2swi      /4))         
#define R_VL1swi         (RELINTVECT + (6* VL1swi      /4))         

                                                   

/****************** The aray of pointers to function *****************/


 void  (*  const RAM_vector[])()@0x1C0 = 
 {
          (pFun)&_SP_INIT,           // vector_0  INITSP
          (pFun)&_startup,           // vector_1  INITPC
          (pFun)dummy_ISR,           // vector_2  Vaccerr
          (pFun)dummy_ISR,           // vector_3  Vadderr
          (pFun)dummy_ISR,           // vector_4  Viinstr
          (pFun)dummy_ISR,           // vector_5  VReserved5
          (pFun)dummy_ISR,           // vector_6  VReserved6
          (pFun)dummy_ISR,           // vector_7  VReserved7
          (pFun)dummy_ISR,           // vector_8  Vprviol
          (pFun)dummy_ISR,           // vector_9  Vtrace
          (pFun)dummy_ISR,           // vector_10 Vunilaop
          (pFun)dummy_ISR,           // vector_11 Vunilfop
          (pFun)dummy_ISR,           // vector_12 Vdbgi
          (pFun)dummy_ISR,           // vector_13 VReserved13
          (pFun)dummy_ISR,           // vector_14 Vferror
          (pFun)dummy_ISR,           // vector_15 VReserved15
          (pFun)dummy_ISR,           // vector_16 VReserved16
          (pFun)dummy_ISR,           // vector_17 VReserved17
          (pFun)dummy_ISR,           // vector_18 VReserved18
          (pFun)dummy_ISR,           // vector_19 VReserved19
          (pFun)dummy_ISR,           // vector_20 VReserved20
          (pFun)dummy_ISR,           // vector_21 VReserved21
          (pFun)dummy_ISR,           // vector_22 VReserved22
          (pFun)dummy_ISR,           // vector_23 VReserved23
          (pFun)dummy_ISR,           // vector_24 Vspuri
          (pFun)dummy_ISR,           // vector_25 VReserved25
          (pFun)dummy_ISR,           // vector_26 VReserved26
          (pFun)dummy_ISR,           // vector_27 VReserved27 
          (pFun)dummy_ISR,           // vector_28 VReserved28
          (pFun)dummy_ISR,           // vector_29 VReserved29
          (pFun)dummy_ISR,           // vector_30 VReserved30
          (pFun)dummy_ISR,           // vector_31 VReserved31
          (pFun)dummy_ISR,           // vector_32 Vtrap0
          (pFun)dummy_ISR,           // vector_33 Vtrap1
          (pFun)dummy_ISR,           // vector_34 Vtrap2 
          (pFun)dummy_ISR,           // vector_35 Vtrap3
          (pFun)dummy_ISR,           // vector_36 Vtrap4
          (pFun)dummy_ISR,           // vector_37 Vtrap5
          (pFun)dummy_ISR,           // vector_38 Vtrap6
          (pFun)dummy_ISR,           // vector_39 Vtrap7
          (pFun)dummy_ISR,           // vector_40 Vtrap8
          (pFun)dummy_ISR,           // vector_41 Vtrap9 
          (pFun)dummy_ISR,           // vector_42 Vtrap10
          (pFun)dummy_ISR,           // vector_43 Vtrap11
          (pFun)dummy_ISR,           // vector_44 Vtrap12
          (pFun)dummy_ISR,           // vector_45 Vtrap13 
          (pFun)dummy_ISR,           // vector_46 Vtrap14
          (pFun)dummy_ISR,           // vector_47 Vtrap15
          (pFun)dummy_ISR,           // vector_48 VReserved48
          (pFun)dummy_ISR,           // vector_49 VReserved49
          (pFun)dummy_ISR,           // vector_50 VReserved50
          (pFun)dummy_ISR,           // vector_51 VReserved51
          (pFun)dummy_ISR,           // vector_52 VReserved52
          (pFun)dummy_ISR,           // vector_53 VReserved53
          (pFun)dummy_ISR,           // vector_54 VReserved54
          (pFun)dummy_ISR,           // vector_55 VReserved55
          (pFun)dummy_ISR,           // vector_56 VReserved56
          (pFun)dummy_ISR,           // vector_57 VReserved57
          (pFun)dummy_ISR,           // vector_58 VReserved58
          (pFun)dummy_ISR,           // vector_59 VReserved59
          (pFun)dummy_ISR,           // vector_60 VReserved60
          (pFun)dummy_ISR,           // vector_61 Vunsinstr
          (pFun)dummy_ISR,           // vector_62 VReserved62
          (pFun)dummy_ISR,           // vector_63 VReserved63
          (pFun)dummy_ISR,           // vector_64 Virq
          (pFun)dummy_ISR,           // vector_65 Vlvd
          (pFun)dummy_ISR,           // vector_66 Vlol
          (pFun)dummy_ISR,           // vector_67 Vspi1
          (pFun)dummy_ISR,           // vector_68 Vspi2 
          (pFun)&usb_it_handler,     // vector_69 Vusb
          (pFun)dummy_ISR,           // vector_70 VReserved70
          (pFun)dummy_ISR,           // vector_71 Vtpm1ch0
          (pFun)dummy_ISR,           // vector_72 Vtpm1ch1
          (pFun)dummy_ISR,           // vector_73 Vtpm1ch2
          (pFun)dummy_ISR,           // vector_74 Vtpm1ch3 
          (pFun)dummy_ISR,           // vector_75 Vtpm1ch4
          (pFun)dummy_ISR,           // vector_76 Vtpm1ch5
          (pFun)dummy_ISR,           // vector_77 Vtpm1ovf
          (pFun)dummy_ISR,           // vector_78 Vtpm2ch0
          (pFun)dummy_ISR,           // vector_79 Vtpm2ch1
          (pFun)dummy_ISR,           // vector_80 Vtpm2ovf
          (pFun)dummy_ISR,           // vector_81 Vsci1err
          (pFun)dummy_ISR,           // vector_82 Vsci1rx
          (pFun)dummy_ISR,           // vector_83 Vsci1tx
          (pFun)dummy_ISR,           // vector_84 Vsci2err
          (pFun)dummy_ISR,           // vector_85 Vsci2rx
          (pFun)dummy_ISR,           // vector_86 Vsci2tx
          (pFun)dummy_ISR,           // vector_87 Vkeyboard
          (pFun)dummy_ISR,           // vector_88 Vadc
          (pFun)dummy_ISR,           // vector_89 Vacmpx
          (pFun)dummy_ISR,           // vector_90 Viic1x
          (pFun)dummy_ISR,           // vector_91 Vrtc
          (pFun)dummy_ISR,           // vector_92 Viic2x
          (pFun)dummy_ISR,           // vector_93 Vcmt
          (pFun)dummy_ISR,           // vector_94 Vcanwu
          (pFun)dummy_ISR,           // vector_95 Vcanerr 
          (pFun)dummy_ISR,           // vector_96 Vcanrx
          (pFun)dummy_ISR,           // vector_97 Vcantx
          (pFun)dummy_ISR,           // vector_98 Vrnga
          (pFun)dummy_ISR,           // vector_99 VReserved99
          (pFun)dummy_ISR,           // vector_100 VReserved100
          (pFun)dummy_ISR,           // vector_101 VReserved101 
          (pFun)dummy_ISR,           // vector_102 VReserved102
          (pFun)dummy_ISR,           // vector_103 VReserved103
          (pFun)dummy_ISR,           // vector_104 VL7swi 
          (pFun)dummy_ISR,           // vector_105 VL6swi
          (pFun)dummy_ISR,           // vector_106 VL5swi
          (pFun)dummy_ISR,           // vector_107 VL4swi
          (pFun)dummy_ISR,           // vector_108 VL3swi
          (pFun)dummy_ISR,           // vector_109 VL2swi
          (pFun)dummy_ISR,           // vector_110 VL1swi


 };     

 
                                        
/**************** The original interrupt vector table ****************/
/**************** with new relocated addresses ***********************/

 int  original_vectors[]@0x00000000 =
 
 {                
              (int)&_SP_INIT,
              (int)&_startup,
              R_Vaccerr      ,     
              R_Vadderr      ,     
              R_Viinstr      ,     
              R_VReserved5   ,     
              R_VReserved6   ,     
              R_VReserved7   ,     
              R_Vprviol      ,     
              R_Vtrace       ,     
              R_Vunilaop     ,     
              R_Vunilfop     ,     
              R_Vdbgi        ,     
              R_VReserved13  ,     
              R_Vferror      ,     
              R_VReserved15  ,   
              R_VReserved16  ,   
              R_VReserved17  ,  
              R_VReserved18  ,   
              R_VReserved19  ,   
              R_VReserved20  ,   
              R_VReserved21  ,   
              R_VReserved22  ,   
              R_VReserved23  ,   
              R_Vspuri       ,   
              R_VReserved25  ,   
              R_VReserved26  ,   
              R_VReserved27  ,   
              R_VReserved28  ,   
              R_VReserved29  ,   
              R_VReserved30  ,   
              R_VReserved31  ,   
              R_Vtrap0       ,   
              R_Vtrap1       ,   
              R_Vtrap2       ,   
              R_Vtrap3       ,   
              R_Vtrap4       ,   
              R_Vtrap5       ,   
              R_Vtrap6       ,   
              R_Vtrap7       ,   
              R_Vtrap8       ,   
              R_Vtrap9       ,   
              R_Vtrap10      ,   
              R_Vtrap11      ,   
              R_Vtrap12      ,   
              R_Vtrap13      ,   
              R_Vtrap14      ,   
              R_Vtrap15      ,   
              R_VReserved48  ,   
              R_VReserved49  ,   
              R_VReserved50  ,   
              R_VReserved51  ,   
              R_VReserved52  ,   
              R_VReserved53  ,   
              R_VReserved54  ,   
              R_VReserved55  ,   
              R_VReserved56  ,   
              R_VReserved57  ,   
              R_VReserved58  ,   
              R_VReserved59  ,   
              R_VReserved60  ,   
              R_Vunsinstr    ,   
              R_VReserved62  ,   
              R_VReserved63  ,   
              R_Virq         ,   
              R_Vlvd         ,   
              R_Vlol         ,   
              R_Vspi1        ,   
              R_Vspi2        ,   
              R_Vusb         ,   
              R_VReserved70  ,   
              R_Vtpm1ch0     ,   
              R_Vtpm1ch1     ,   
              R_Vtpm1ch2     ,   
              R_Vtpm1ch3     ,   
              R_Vtpm1ch4     ,   
              R_Vtpm1ch5     ,   
              R_Vtpm1ovf     ,   
              R_Vtpm2ch0     ,   
              R_Vtpm2ch1     ,   
              R_Vtpm2ovf     ,   
              R_Vsci1err     ,   
              R_Vsci1rx      ,   
              R_Vsci1tx      ,   
              R_Vsci2err     ,   
              R_Vsci2rx      ,   
              R_Vsci2tx      ,   
              R_Vkeyboard    ,   
              R_Vadc         ,   
              R_Vacmpx       ,   
              R_Viic1x       ,   
              R_Vrtc         ,   
              R_Viic2x       ,   
              R_Vcmt         ,   
              R_Vcanwu       ,   
              R_Vcanerr      ,   
              R_Vcanrx       ,   
              R_Vcantx       ,   
              R_Vrnga        ,   
              R_VReserved99  ,   
              R_VReserved100 ,   
              R_VReserved101 ,   
              R_VReserved102 ,   
              R_VReserved103 ,   
              R_VL7swi       ,   
              R_VL6swi       ,   
              R_VL5swi       ,   
              R_VL4swi       ,   
              R_VL3swi       ,   
              R_VL2swi       ,   
              R_VL1swi       ,
                     
 };                     
                    
               
#endif