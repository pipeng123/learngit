;*********************************************************************
; HEADER_START
;
;        $File Name: slfprg-s08gw.asm$
;      Project:        Developper's HC08 Bootloader Slave
;      Description:    S08GW main bootloader file
;      Platform:       HCS08
;      $Version: 1.0.0.0$
;      $Date: May-24-2012$ 
;      $Last Modified By: B20253$
;      Company:        Freescale Semiconductor
;      Security:       General Business
;
; =================================================================== 
; Copyright (c):      Freescale Semiconductor, 2012, All rights reserved.
;
; =================================================================== 
; THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY
; EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
; PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL FREESCALE OR
; ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
; NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
; STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
; ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
; OF THE POSSIBILITY OF SUCH DAMAGE.
; ===================================================================
;
; HEADER_END

; labels SCI, SIZE and IRQOPTION defined externally:
; SIZE = 32, 64 depending what memory size of GW family is required
; 
; IRQOPTION *NOT* defined >> regular version 
; IRQOPTION defined >> regular version using IRQ option (bootloading won't start if IRQ high)
;
; label HISPEED => if defined 9600, 19200, 38400

;**************************************************/
;** USER SETTINGS OF S08 MCU 

;** Kinetis Flash memory size (32KB, 64KB)
SIZE	EQU		64

;** Actual used UART module (SCI0, SCI1, SCI2, SCI3)
SCI		EQU		0

;** A range of UART baudrates is (9600, 19200, 38400) 
SPEED	EQU		9600

