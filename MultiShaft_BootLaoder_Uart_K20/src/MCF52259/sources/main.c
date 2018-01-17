/*********************************************************************
* HEADER_START                                                       *            
*                                                                    *               
*      Name:           main.c                                        *            
*      Project:        Developper's  Bootloader Slave                *            
*      Description:    MCF52259 main bootloader file                 *            
*      Platform:       Linux/Win32                                   *            
*      Date:           Nov 1 2009                                    *            
*      Author:         B20253                                        *            
*      Company:      Freescale                                       *            
*      Security:       General Business                              *            
*                                                                    *
* ===================================================================*
* Copyright (c):       FREESCALE Inc., 2009, All rights reserved.    *            
*                                                                    *            
* ===================================================================*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY             *            
* EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE*            
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR *            
* PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL FREESCALE OR            *            
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   *            
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT       *            
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;       *            
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)           *            
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,*            
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      *            
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED*            
* OF THE POSSIBILITY OF SUCH DAMAGE.                                 *            
* ===================================================================*/

#include <stdio.h>
#include "support_common.h"
#include "uart_support.h"

#include "MCF52259.h"
#include "hc08sprg.h"
#include "startcf.h"

unsigned char quit;

unsigned char i,sdid= 0;
unsigned int* ptr_app;
unsigned int* ptr_SDID;

FILE_PTR_STR file_ptr;

/* flash protection (31 sector - 16kB (0x7A000-0x7FFFF)) */
const unsigned int MY_MCF_CFM_CFMPROT @0x401D0010 = 0x40000000; 

#define SYSTEM_CLK_KHZ   80000

 const IDENT_STR idents = 
   {
    2,                                           // number of reprogrammable memory areas
    (int *) 0x00000000,                          // flash part 1 start 
    (int *) 0x000004FF,                          // flash part 1 end
    (int *) 0x00000500,                          // flash part 2 start 
    (int *) 0x0007BFFF,                          // flash part 2 end
    (int *) 0x00000000,                          // start of new relocated vector table
    NULL,                                        // end of interrupt vector table
    FLASH_ERASE_PAGE,                            // size of erase page
    FLASH_WRITE_PAGE                             // size of write page
   };                     

/******************************************************************************************/
char getchar_flag(int channel)
{
  unsigned int j = 0;
   for(j=0; j<MAX_VALUE ;j++)
   {
     asm(nop);
   }
   return (char)MCF_UART_URB(channel);
}
/******************************************************************************************/
void putstr(char* str) 
{
    while(*str)
       uart_putchar(CHANNEL,*str++);
    uart_putchar(CHANNEL,NULL);        
}
/******************************************************************************************/
void putint(unsigned char * p) 
{
    uart_putchar(CHANNEL,(char)*p++);
    uart_putchar(CHANNEL,(char)*p++);
    uart_putchar(CHANNEL,(char)*p++);
    uart_putchar(CHANNEL,(char)*p++);
}
/*******************************************************************************************/
void putint_FF(void) 
{
    uart_putchar(CHANNEL,(char)0xFF);
    uart_putchar(CHANNEL,(char)0XFF);
    uart_putchar(CHANNEL,(char)0XFF);
    uart_putchar(CHANNEL,(char)0XFF);
}

/*******************************************************************************************/
void main(void)
{
      #if(CHANNEL == 0) /* SCI CHANNEL 0*/
            MCF_GPIO_PUAPAR |= MCF_GPIO_PUAPAR_UTXD0_UTXD0 | MCF_GPIO_PUAPAR_URXD0_URXD0;
   #elif(CHANNEL == 1) /* SCI CHANNEL 1*/
      MCF_GPIO_PUBPAR |= MCF_GPIO_PUBPAR_UTXD1_UTXD1 | MCF_GPIO_PUBPAR_URXD1_URXD1;
   #elif(CHANNEL == 2) /* SCI CHANNEL 2*/
        MCF_GPIO_PUCPAR |= MCF_GPIO_PUCPAR_UTXD2_UTXD2 | MCF_GPIO_PUCPAR_URXD2_URXD2;
   #endif 
     
     MCF_CFM_CFMCLKD |= 0x4F;                     // Set the correct flash clock

     uart_init(CHANNEL, SYSTEM_CLK_KHZ, BAUDRATE);       // SCI initialization
     uart_putchar(CHANNEL, (char)FCACK);
   
      if(getchar_flag(CHANNEL) == (char)FCACK)
       {
      uart_putchar(CHANNEL, (char)FCACK);
       }
      else
        {
      asm (move.l RESET_APP,a0);     
      asm (move.l (a0),a7);
      asm (move.l RESET_APP+4,a0);    
      asm (jmp (a0));
        }

      quit = 0;

       while(!quit) 
         {
               switch(uart_getchar(CHANNEL)) { 
            
            case READ:
                     file_ptr.addr.b.byte03 = uart_getchar(CHANNEL);    // addr hi
                             file_ptr.addr.b.byte02 = uart_getchar(CHANNEL);    
                              file_ptr.addr.b.byte01 = uart_getchar(CHANNEL);    
                              file_ptr.addr.b.byte00 = uart_getchar(CHANNEL);    // addr lo
                             file_ptr.datasize      = uart_getchar(CHANNEL);     // length
                  
                      if(file_ptr.addr.i == NULL)
                             {
                                putint((unsigned char*)RESET_APP);
                                putint((unsigned char*)(RESET_APP+4));
                                file_ptr.addr.w   += 8;
                                file_ptr.datasize -= 8;
                             }
                     while (file_ptr.datasize)
                             {
                              if(file_ptr.addr.i == (unsigned int*)RESET_APP)
                                {
                                   putint_FF();
                                   putint_FF();
                                   file_ptr.addr.w   += 8;
                                   file_ptr.datasize -= 8;
                                }
                                 uart_putchar(CHANNEL, (char)*file_ptr.addr.w);
                                 file_ptr.addr.w++;
                                 file_ptr.datasize--;  
                              }

                   break;
            
            case ERASE:
                     file_ptr.addr.b.byte03 = uart_getchar(CHANNEL);    
                             file_ptr.addr.b.byte02 = uart_getchar(CHANNEL);    
                              file_ptr.addr.b.byte01 = uart_getchar(CHANNEL);    
                              file_ptr.addr.b.byte00 = uart_getchar(CHANNEL);    

                  DisableInterrupts;
                  Page_erase (file_ptr.addr.w);
                  EnableInterrupts;
                  uart_putchar(CHANNEL, (char)FCACK);
                   break;
                   
            case WRITE:
                  file_ptr.addr.b.byte03 = uart_getchar(CHANNEL);    
                             file_ptr.addr.b.byte02 = uart_getchar(CHANNEL);    
                              file_ptr.addr.b.byte01 = uart_getchar(CHANNEL);    
                              file_ptr.addr.b.byte00 = uart_getchar(CHANNEL);    
                             file_ptr.datasize      = uart_getchar(CHANNEL);
                                
                                  for (i=0; i <file_ptr.datasize; i++)
                                file_ptr.data.data8[i] = uart_getchar(CHANNEL);
                            
                             if(file_ptr.addr.i == NULL)
                             {                                          
                                 ptr_app =(unsigned int*)RESET_APP;
                                 DisableInterrupts;
                                 Burst_Prog(ptr_app, file_ptr.data.data32, 2);  // copy SP & PC to RESET_APP
                                 EnableInterrupts;
                                 file_ptr.data.data32[0] = (unsigned int)&__SP_AFTER_RESET;
                                 file_ptr.data.data32[1] = (unsigned int)&_startup;  
                             }
                         
                             if (file_ptr.datasize & 0x3) // length non long word aligned
                             {
                                 file_ptr.datasize &= 0xFFFFFFFC;
                                 file_ptr.datasize += 4;
                             }
                  Burst_Prog(file_ptr.addr.w,file_ptr.data.data32, file_ptr.datasize / 4);
                  uart_putchar(CHANNEL, (char)FCACK);
               break;
               
            case IDENT:
                  uart_putchar(CHANNEL, (char)PROTOCOL_VERSION);
                   ptr_SDID = (unsigned int*)MCF_CCM_CIR_REG;
                     uart_putchar(CHANNEL, NULL);
                  sdid = (unsigned char)(((*ptr_SDID)>>6));
                  uart_putchar(CHANNEL, (char)sdid);
                  i = 0;
                             while(i < sizeof(idents))
                             {
                               uart_putchar(CHANNEL,idents.str[i++]);
                             }  
                         putstr("MCF52259 $Version: 1.0.6.0$"); 
                  uart_putchar(CHANNEL, (char)FCACK);
               break;
            
            case QUIT:
               quit = 1;
               break;
               }
           }
      asm (jmp main);
      }
