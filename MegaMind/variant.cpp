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

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
extern const PinDescription g_APinDescription[][16]=
{
	{//GPIO PORTA
    {GPIOA_BASE, xGPIO_PIN_0,  xSYSCTL_PERIPH_GPIOA, GPIO_PA0_ADC0,  TIMER2_BASE,      TIMER_CH1,       SYSCTL_PERIPH_TIM2, GPIO_PA0_TIM2CH1(APP) },//Pin 0
	{GPIOA_BASE, xGPIO_PIN_1,  xSYSCTL_PERIPH_GPIOA, GPIO_PA1_ADC1,  TIMER2_BASE,      TIMER_CH2,       SYSCTL_PERIPH_TIM2, GPIO_PA1_TIM2CH2(APP) },//Pin 1
	{GPIOA_BASE, xGPIO_PIN_2,  xSYSCTL_PERIPH_GPIOA, GPIO_PA2_ADC2,  TIMER2_BASE,      TIMER_CH3,       SYSCTL_PERIPH_TIM2, GPIO_PA2_TIM2CH3(APP) },//Pin 2
	{GPIOA_BASE, xGPIO_PIN_3,  xSYSCTL_PERIPH_GPIOA, GPIO_PA3_ADC3,  TIMER2_BASE,      TIMER_CH4,       SYSCTL_PERIPH_TIM2, GPIO_PA3_TIM2CH4(APP) },//Pin 3
	{GPIOA_BASE, xGPIO_PIN_4,  xSYSCTL_PERIPH_GPIOA, GPIO_PA4_ADC4,  NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 4
	{GPIOA_BASE, xGPIO_PIN_5,  xSYSCTL_PERIPH_GPIOA, GPIO_PA5_ADC5,  NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 5
	{GPIOA_BASE, xGPIO_PIN_6,  xSYSCTL_PERIPH_GPIOA, GPIO_PA6_ADC6,  TIMER3_BASE,      TIMER_CH1,       SYSCTL_PERIPH_TIM3, GPIO_PA6_TIM3CH1(APP) },//Pin 6
	{GPIOA_BASE, xGPIO_PIN_7,  xSYSCTL_PERIPH_GPIOA, GPIO_PA7_ADC7,  TIMER3_BASE,      TIMER_CH2,       SYSCTL_PERIPH_TIM3, GPIO_PA7_TIM3CH2(APP) },//Pin 7
	{GPIOA_BASE, xGPIO_PIN_8,  xSYSCTL_PERIPH_GPIOA, NO_ADC,         TIMER1_BASE,      TIMER_CH1,       SYSCTL_PERIPH_TIM1, GPIO_PA8_TIM1CH1(APP) },//Pin 8
	{GPIOA_BASE, xGPIO_PIN_9,  xSYSCTL_PERIPH_GPIOA, NO_ADC,         TIMER1_BASE,      TIMER_CH2,       SYSCTL_PERIPH_TIM1, GPIO_PA9_TIM1CH2(APP) },//Pin 9
	{GPIOA_BASE, xGPIO_PIN_10, xSYSCTL_PERIPH_GPIOA, NO_ADC,         TIMER1_BASE,      TIMER_CH3,       SYSCTL_PERIPH_TIM1, GPIO_PA10_TIM1CH3(APP)},//Pin 10
	{GPIOA_BASE, xGPIO_PIN_11, xSYSCTL_PERIPH_GPIOA, NO_ADC,         TIMER1_BASE,      TIMER_CH4,       SYSCTL_PERIPH_TIM1, GPIO_PA11_TIM1CH4(APP)},//Pin 11
	{GPIOA_BASE, xGPIO_PIN_12, xSYSCTL_PERIPH_GPIOA, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 12
	{GPIOA_BASE, xGPIO_PIN_13, xSYSCTL_PERIPH_GPIOA, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 13
	{GPIOA_BASE, xGPIO_PIN_14, xSYSCTL_PERIPH_GPIOA, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 14
	{GPIOA_BASE, xGPIO_PIN_15, xSYSCTL_PERIPH_GPIOA, NO_ADC,         TIMER2_BASE,      TIMER_CH1,       SYSCTL_PERIPH_TIM2, GPIO_PA15_TIM2CH1(APP)} //Pin 15
	},
	{//GPIO PORTB
	{GPIOB_BASE, xGPIO_PIN_0,  xSYSCTL_PERIPH_GPIOB, GPIO_PB0_ADC8,  TIMER3_BASE,      TIMER_CH3,       SYSCTL_PERIPH_TIM3, GPIO_PB0_TIM3CH3(APP) },//Pin 0
	{GPIOB_BASE, xGPIO_PIN_1,  xSYSCTL_PERIPH_GPIOB, GPIO_PB1_ADC9,  TIMER3_BASE,      TIMER_CH4,       SYSCTL_PERIPH_TIM3, GPIO_PB1_TIM3CH4(APP) },//Pin 1
	{GPIOB_BASE, xGPIO_PIN_2,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 2
	{GPIOB_BASE, xGPIO_PIN_3,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER2_BASE,      TIMER_CH2,       SYSCTL_PERIPH_TIM2, GPIO_PB3_TIM2CH2(APP) },//Pin 3
	{GPIOB_BASE, xGPIO_PIN_4,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER3_BASE,      TIMER_CH1,       SYSCTL_PERIPH_TIM3, GPIO_PB4_TIM3CH1(APP) },//Pin 4
	{GPIOB_BASE, xGPIO_PIN_5,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER3_BASE,      TIMER_CH2,       SYSCTL_PERIPH_TIM3, GPIO_PB5_TIM3CH2(APP) },//Pin 5
	{GPIOB_BASE, xGPIO_PIN_6,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER4_BASE,      TIMER_CH1,       SYSCTL_PERIPH_TIM4, GPIO_PB6_TIM4CH1(APP) },//Pin 6
	{GPIOB_BASE, xGPIO_PIN_7,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER4_BASE,      TIMER_CH2,       SYSCTL_PERIPH_TIM4, GPIO_PB7_TIM4CH2(APP) },//Pin 7
	{GPIOB_BASE, xGPIO_PIN_8,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER4_BASE,      TIMER_CH3,       SYSCTL_PERIPH_TIM4, GPIO_PB8_TIM4CH3(APP) },//Pin 8
	{GPIOB_BASE, xGPIO_PIN_9,  xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER4_BASE,      TIMER_CH4,       SYSCTL_PERIPH_TIM4, GPIO_PB9_TIM4CH4(APP) },//Pin 9
	{GPIOB_BASE, xGPIO_PIN_10, xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER2_BASE,      TIMER_CH3,       SYSCTL_PERIPH_TIM2, GPIO_PB10_TIM2CH3(APP)},//Pin 10
	{GPIOB_BASE, xGPIO_PIN_11, xSYSCTL_PERIPH_GPIOB, NO_ADC,         TIMER2_BASE,      TIMER_CH4,       SYSCTL_PERIPH_TIM2, GPIO_PB11_TIM2CH4(APP)},//Pin 11
	{GPIOB_BASE, xGPIO_PIN_12, xSYSCTL_PERIPH_GPIOB, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 12
	{GPIOB_BASE, xGPIO_PIN_13, xSYSCTL_PERIPH_GPIOB, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 13
	{GPIOB_BASE, xGPIO_PIN_14, xSYSCTL_PERIPH_GPIOB, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 14
	{GPIOB_BASE, xGPIO_PIN_15, xSYSCTL_PERIPH_GPIOB, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          } //Pin 15
	},
	{//GPIO PORTC
	{GPIOC_BASE, xGPIO_PIN_0,  xSYSCTL_PERIPH_GPIOC, GPIO_PC0_ADC10, NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 0
	{GPIOC_BASE, xGPIO_PIN_1,  xSYSCTL_PERIPH_GPIOC, GPIO_PC1_ADC11, NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 1
	{GPIOC_BASE, xGPIO_PIN_2,  xSYSCTL_PERIPH_GPIOC, GPIO_PC2_ADC12, NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 2
	{GPIOC_BASE, xGPIO_PIN_3,  xSYSCTL_PERIPH_GPIOC, GPIO_PC3_ADC13, NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 3
	{GPIOC_BASE, xGPIO_PIN_4,  xSYSCTL_PERIPH_GPIOC, GPIO_PC4_ADC14, NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 4
	{GPIOC_BASE, xGPIO_PIN_5,  xSYSCTL_PERIPH_GPIOC, GPIO_PC5_ADC15, NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 5
	{GPIOC_BASE, xGPIO_PIN_6,  xSYSCTL_PERIPH_GPIOC, NO_ADC,         TIMER3_BASE,      TIMER_CH1,       SYSCTL_PERIPH_TIM3, GPIO_PC6_TIM3CH1(APP) },//Pin 6
	{GPIOC_BASE, xGPIO_PIN_7,  xSYSCTL_PERIPH_GPIOC, NO_ADC,         TIMER3_BASE,      TIMER_CH2,       SYSCTL_PERIPH_TIM3, GPIO_PC7_TIM3CH2(APP) },//Pin 7
	{GPIOC_BASE, xGPIO_PIN_8,  xSYSCTL_PERIPH_GPIOC, NO_ADC,         TIMER3_BASE,      TIMER_CH3,       SYSCTL_PERIPH_TIM3, GPIO_PC8_TIM3CH3(APP) },//Pin 8
	{GPIOC_BASE, xGPIO_PIN_9,  xSYSCTL_PERIPH_GPIOC, NO_ADC,         TIMER3_BASE,      TIMER_CH4,       SYSCTL_PERIPH_TIM3, GPIO_PC9_TIM3CH4(APP) },//Pin 9
	{GPIOC_BASE, xGPIO_PIN_10, xSYSCTL_PERIPH_GPIOC, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 10
	{GPIOC_BASE, xGPIO_PIN_11, xSYSCTL_PERIPH_GPIOC, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 11
	{GPIOC_BASE, xGPIO_PIN_12, xSYSCTL_PERIPH_GPIOC, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 12
	{GPIOC_BASE, xGPIO_PIN_13, xSYSCTL_PERIPH_GPIOC, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 13
	{GPIOC_BASE, xGPIO_PIN_14, xSYSCTL_PERIPH_GPIOC, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          },//Pin 14
	{GPIOC_BASE, xGPIO_PIN_15, xSYSCTL_PERIPH_GPIOC, NO_ADC,         NOT_ON_TIMERBASE, NOT_ON_TIMERCHN, NOT_ON_TIMER      , NOT_ON_TIMER          } //Pin 15
	}
} ;

extern const APDescription g_analogPinDescription[] = {
	{GPIOA_BASE, xGPIO_PIN_0, GPIO_PA0_ADC0}, //A0
	{GPIOA_BASE, xGPIO_PIN_1, GPIO_PA1_ADC1}, //A1
	{GPIOA_BASE, xGPIO_PIN_2, GPIO_PA2_ADC2}, //A2
	{GPIOA_BASE, xGPIO_PIN_3, GPIO_PA3_ADC3}, //A3
	{GPIOA_BASE, xGPIO_PIN_4, GPIO_PA4_ADC4}, //A4
	{GPIOA_BASE, xGPIO_PIN_5, GPIO_PA5_ADC5}, //A5
	{GPIOA_BASE, xGPIO_PIN_6, GPIO_PA6_ADC6}, //A6
	{GPIOA_BASE, xGPIO_PIN_7, GPIO_PA7_ADC7}, //A7
	{GPIOB_BASE, xGPIO_PIN_0, GPIO_PB0_ADC8}, //A8
	{GPIOB_BASE, xGPIO_PIN_1, GPIO_PB1_ADC9}, //A9
	{GPIOC_BASE, xGPIO_PIN_0, GPIO_PC0_ADC10}, //A10
	{GPIOC_BASE, xGPIO_PIN_1, GPIO_PC1_ADC11}, //A11
	{GPIOC_BASE, xGPIO_PIN_2, GPIO_PC2_ADC12}, //A12
	{GPIOC_BASE, xGPIO_PIN_3, GPIO_PC3_ADC13}, //A13
	{GPIOC_BASE, xGPIO_PIN_4, GPIO_PC4_ADC14}, //A14
	{GPIOC_BASE, xGPIO_PIN_5, GPIO_PC5_ADC15}  //A15
};

extern const UARTPinDescription g_uartPinDescription[] = {
	{USART1_BASE, xSYSCTL_PERIPH_GPIOA, xSYSCTL_PERIPH_UART1, xINT_UART1, GPIOA_BASE, GPIO_PIN_9,  GPIO_PA9_UART1TX,  GPIO_PIN_10, GPIO_PA10_UART1RX},
	{USART2_BASE, xSYSCTL_PERIPH_GPIOA, xSYSCTL_PERIPH_UART2, xINT_UART2, GPIOA_BASE, GPIO_PIN_2,  GPIO_PA2_UART2TX,  GPIO_PIN_3,  GPIO_PA3_UART2RX },
	{USART3_BASE, xSYSCTL_PERIPH_GPIOB, xSYSCTL_PERIPH_UART3, xINT_UART3, GPIOB_BASE, GPIO_PIN_10, GPIO_PB10_UART3TX, GPIO_PIN_11, GPIO_PB11_UART3RX}
};

#ifdef __cplusplus
}
#endif
//
//
// ----------------------------------------------------------------------------
/*
 * UART objects
 */

#ifdef _SERIAL1
UARTClass Serial1(1);
// IT handlers
unsigned long
uart1IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData)
{
//	while(Serial1.uartInt()==0);
	Serial1.uartInt();
	return 0;
}
#endif

#ifdef _SERIAL2
UARTClass Serial2(2);
// IT handlers
unsigned long
uart2IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData)
{
//	while(Serial2.uartInt()==0);
	Serial2.uartInt();
	return 0;
}
#endif

#ifdef _SERIAL3
UARTClass Serial3(3);
// IT handlers
unsigned long
uart3IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData)
{
//	while(Serial3.uartInt()==0);
	Serial3.uartInt();
	return 0;
}
#endif

#ifdef _SERIAL4
UARTClass Serial4(4);
// IT handlers
unsigned long
uart4IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData)
{
//	while(Serial4.uartInt()==0);
	Serial4.uartInt();
	return 0;
}
#endif

#ifdef _SERIAL5
UARTClass Serial5(5);
// IT handlers
unsigned long
uart5IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData)
{
//	while(Serial5.uartInt()==0);
	Serial5.uartInt();
	return 0;
}
#endif
// ----------------------------------------------------------------------------
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//void __libc_init_array(void);
//
//void init( void )
//{
//  SystemInit();
//
//  // Set Systick to 1ms interval, common to all SAM3 variants
//  if (SysTick_Config(SystemCoreClock / 1000))
//  {
//    // Capture error
//    while (true);
//  }
//
//  // Disable watchdog
//  WDT_Disable(WDT);
//
//  // Initialize C library
//  __libc_init_array();
//
//  // Disable pull-up on every pin
//  for (int i = 0; i < PINS_COUNT; i++)
//	  digitalWrite(i, LOW);
//
//  // Enable parallel access on PIO output data registers
//  PIOA->PIO_OWER = 0xFFFFFFFF;
//  PIOB->PIO_OWER = 0xFFFFFFFF;
//  PIOC->PIO_OWER = 0xFFFFFFFF;
//  PIOD->PIO_OWER = 0xFFFFFFFF;
//
//  // Initialize Serial port U(S)ART pins
//  PIO_Configure(
//    g_APinDescription[PINS_UART].pPort,
//    g_APinDescription[PINS_UART].ulPinType,
//    g_APinDescription[PINS_UART].ulPin,
//    g_APinDescription[PINS_UART].ulPinConfiguration);
//  digitalWrite(0, HIGH); // Enable pullup for RX0
//  PIO_Configure(
//    g_APinDescription[PINS_USART0].pPort,
//    g_APinDescription[PINS_USART0].ulPinType,
//    g_APinDescription[PINS_USART0].ulPin,
//    g_APinDescription[PINS_USART0].ulPinConfiguration);
//  PIO_Configure(
//    g_APinDescription[PINS_USART1].pPort,
//    g_APinDescription[PINS_USART1].ulPinType,
//    g_APinDescription[PINS_USART1].ulPin,
//    g_APinDescription[PINS_USART1].ulPinConfiguration);
//  PIO_Configure(
//    g_APinDescription[PINS_USART3].pPort,
//    g_APinDescription[PINS_USART3].ulPinType,
//    g_APinDescription[PINS_USART3].ulPin,
//    g_APinDescription[PINS_USART3].ulPinConfiguration);
//
//  // Initialize USB pins
//  PIO_Configure(
//    g_APinDescription[PINS_USB].pPort,
//    g_APinDescription[PINS_USB].ulPinType,
//    g_APinDescription[PINS_USB].ulPin,
//    g_APinDescription[PINS_USB].ulPinConfiguration);
//
//  // Initialize Analog Controller
//  pmc_enable_periph_clk(ID_ADC);
//  adc_init(ADC, SystemCoreClock, ADC_FREQ_MAX, ADC_STARTUP_FAST);
//  adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);
//  adc_configure_trigger(ADC, ADC_TRIG_SW, 0); // Disable hardware trigger.
//  adc_disable_interrupt(ADC, 0xFFFFFFFF); // Disable all ADC interrupts.
//  adc_disable_all_channel(ADC);
//
//  // Initialize analogOutput module
//  analogOutputInit();
//}
//
//#ifdef __cplusplus
//}
//#endif
//
