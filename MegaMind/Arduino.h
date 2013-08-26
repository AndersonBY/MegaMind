/*
  Copyright (c) 2013 MegaMind.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "binary.h"

#include "xhw_adc.h"
#include "xhw_rtc.h"
#include "xhw_sysctl.h"
#include "xhw_types.h"
#include "xhw_uart.h"
#include "xhw_types.h"
#include "xhw_ints.h"
#include "xhw_nvic.h"
#include "xhw_memmap.h"
#include "xhw_i2c.h"
#include "xhw_gpio.h"
#include "xhw_dma.h"
#include "xhw_timer.h"

#include "xdebug.h"
#include "xcore.h"
#include "xsysctl.h"
#include "xgpio.h"
#include "xuart.h"
#include "xadc.h"
#include "xpwm.h"
#include "xi2c.h"
#include "xdma.h"
#include "xtimer.h"

typedef unsigned char uint8_t;

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include "wiring_constants.h"
//
//#define clockCyclesPerMicrosecond() ( SystemCoreClock / 1000000L )
//#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (SystemCoreClock / 1000L) )
//#define microsecondsToClockCycles(a) ( (a) * (SystemCoreClock / 1000000L) )
//
void yield(void);
//
#include "wiring.h"
#include "wiring_digital.h"
#include "wiring_analog.h"
#include "wiring_shift.h"
//#include "WInterrupts.h"

/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
//
//#define digitalPinToPort(P)        ( g_APinDescription[P].pPort )
//#define digitalPinToBitMask(P)     ( g_APinDescription[P].ulPin )
//#define digitalPinToTimer(P)       (  )
////#define analogInPinToBit(P)        ( )
//#define portOutputRegister(port)   ( &(port->PIO_ODSR) )
//#define portInputRegister(port)    ( &(port->PIO_PDSR) )
////#define portModeRegister(P)        (  )

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5
#define PORTG 6

#define NOT_A_PORT           0
//
//typedef enum _EExt_Interrupts
//{
//  EXTERNAL_INT_0=0,
//  EXTERNAL_INT_1=1,
//  EXTERNAL_INT_2=2,
//  EXTERNAL_INT_3=3,
//  EXTERNAL_INT_4=4,
//  EXTERNAL_INT_5=5,
//  EXTERNAL_INT_6=6,
//  EXTERNAL_INT_7=7,
//  EXTERNAL_NUM_INTERRUPTS
//} EExt_Interrupts ;
//
//typedef void (*voidFuncPtr)( void ) ;

/* Define attribute */
#if defined   ( __CC_ARM   ) /* Keil uVision 4 */
    #define WEAK (__attribute__ ((weak)))
#elif defined ( __ICCARM__ ) /* IAR Ewarm 5.41+ */
    #define WEAK __weak
#elif defined (  __GNUC__  ) /* GCC CS */
    #define WEAK __attribute__ ((weak))
#endif

///* Definitions and types for pins */
//typedef enum _EAnalogChannel
//{
//  NO_ADC=-1,
//  ADC0=0,
//  ADC1,
//  ADC2,
//  ADC3,
//  ADC4,
//  ADC5,
//  ADC6,
//  ADC7,
//  ADC8,
//  ADC9,
//  ADC10,
//  ADC11,
//  ADC12,
//  ADC13,
//  ADC14,
//  ADC15,
////  DA0,
////  DA1
//} EAnalogChannel ;
//
//#define ADC_CHANNEL_NUMBER_NONE 0xffffffff
//

// Definitions for Timer Base
typedef enum _ETimerBase
{
  NOT_ON_TIMERBASE= 0xFFFFFFFF,
  TIMER1_BASE = TIM1_BASE,
  TIMER2_BASE = TIM2_BASE,
  TIMER3_BASE = TIM3_BASE,
  TIMER4_BASE = TIM4_BASE,
  TIMER5_BASE = TIM5_BASE,
  TIMER6_BASE = TIM6_BASE,
  TIMER7_BASE = TIM7_BASE,
  TIMER8_BASE = TIM8_BASE,
} ETimerBase ;

// Definitions for Timer channels
typedef enum _ETimerChannel
{
  NOT_ON_TIMERCHN=0xFFFFFFFF,
  TIMER_CH1 = xPWM_CHANNEL0,
  TIMER_CH2 = xPWM_CHANNEL1,
  TIMER_CH3 = xPWM_CHANNEL2,
  TIMER_CH4 = xPWM_CHANNEL3,
  TIMER_CH5,
  TIMER_CH6,
  TIMER_CH7
} ETimerChannel ;
//
//// Definitions for TC channels
//typedef enum _ETCChannel
//{
//  NOT_ON_TIMER=-1,
//  TC0_CHA0=0,
//  TC0_CHB0,
//  TC0_CHA1,
//  TC0_CHB1,
//  TC0_CHA2,
//  TC0_CHB2,
//  TC1_CHA3,
//  TC1_CHB3,
//  TC1_CHA4,
//  TC1_CHB4,
//  TC1_CHA5,
//  TC1_CHB5,
//  TC2_CHA6,
//  TC2_CHB6,
//  TC2_CHA7,
//  TC2_CHB7,
//  TC2_CHA8,
//  TC2_CHB8
//} ETCChannel ;
//
///**
// * Pin Attributes to be OR-ed
// */
//#define PIN_ATTR_COMBO         (1UL<<0)
//#define PIN_ATTR_ANALOG        (1UL<<1)
//#define PIN_ATTR_DIGITAL       (1UL<<2)
//#define PIN_ATTR_PWM           (1UL<<3)
//#define PIN_ATTR_TIMER         (1UL<<4)
//
/* Types used for the tables below */
typedef struct _PinDescription
{
  uint32_t		 ulPortBase ;	     //GPIOA_BASE~GPIOG_BASE
  uint32_t 		 ulPin ;		     //xGPIO_PIN_0~xGPIO_PIN_15
  uint32_t 		 ulPeripheralPortId ;//xSYSCTL_PERIPH_GPIOA~xSYSCTL_PERIPH_GPIOG
  uint32_t		 ulPinADCConfig; 	 //GPIO_PA0_ADC0
  ETimerBase	 ulTimerBase;
  ETimerChannel	 ulTimerChannel;
  uint32_t		 ulPeripheralTimerId;//SYSCTL_PERIPH_TIM1
  uint32_t		 ulTimerPinConfig;	 //GPIO_PA0_TIM2CH1(APP)
} PinDescription ;

/* Pins table to be instantiated into variant.cpp */
extern const PinDescription g_APinDescription[][16] ;

/*Analog Pin Description*/
typedef struct _AnalogPinDescription{
	uint32_t	ulPortBase ;	 //GPIOA_BASE~GPIOG_BASE
	uint32_t 	ulPin ;		 	 //xGPIO_PIN_0~xGPIO_PIN_15
	uint32_t	ulPinConfig;
}APDescription;
/*Analog Pin to GPIO Port and Pin*/
extern const APDescription g_analogPinDescription[];

#ifdef __cplusplus
} // extern "C"

#include "WCharacter.h"
#include "WString.h"
//#include "Tone.h"
#include "WMath.h"
#include "HardwareSerial.h"
#include "UARTClass.h"
#include "wiring_pulse.h"

#endif // __cplusplus

 //Include board variant
#include "variant.h"
#include "variantUART.h"

//// USB Device
//#define USB_VID            0x2341 // arduino LLC vid
//#define USB_PID_LEONARDO   0x0034
//#define USB_PID_MICRO      0x0035
//#define USB_PID_DUE        0x003E
//#include "USB/USBDesc.h"
//#include "USB/USBCore.h"
//#include "USB/USBAPI.h"

#endif // Arduino_h
