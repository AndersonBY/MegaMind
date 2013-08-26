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

/*----------------------------------------------------------------------------
 *                   STM32F1xx Hardware
 *----------------------------------------------------------------------------
 *                         ADC
 * |------------------------|------------------------|
 * |    ADC0                |    PA0 (ADC123)        |
 * |    ADC1                |    PA1 (ADC123)        |
 * |    ADC2                |    PA2 (ADC123)        |
 * |    ADC3                |    PA3 (ADC123)        |
 * |    ADC4                | PA4(ADC12)  PF6(ADC3)  |
 * |    ADC5                | PA5(ADC12)  PF7(ADC3)  |
 * |    ADC6                | PA6(ADC12)  PF8(ADC3)  |
 * |    ADC7                | PA7(ADC12)  PF9(ADC3)  |
 * |    ADC8                | PB0(ADC12)  PF10(ADC3) |
 * |    ADC9                |    PB1 (ADC12)         |
 * |    ADC10               |    PC0 (ADC123)        |
 * |    ADC11               |    PC1 (ADC123)        |
 * |    ADC12               |    PC2 (ADC123)        |
 * |    ADC13               |    PC3 (ADC123)        |
 * |    ADC14               |    PC4 (ADC12)         |
 * |    ADC15               |    PC5 (ADC12)         |
 * |------------------------|------------------------|
 *
 *----------------------------------------------------------------------------
 *                        TIMER
 * |------------------------|------------------------|
 * |    TIM1ETR             |    PA12 PE7            |
 * |    TIM1CH1             |    PA8  PE9            |
 * |    TIM1CH1N            |    PA7  PB13   PE8     |
 * |    TIM1CH2             |    PA9  PE11           |
 * |    TIM1CH2N            |    PB14 PB0   PE10     |
 * |    TIM1CH3             |    PA10 PE13           |
 * |    TIM1CH3N            |    PB15 PB1   PE12     |
 * |    TIM1CH4             |    PA11 PE14           |
 * |    TIM1CH4N            |                        |
 * |    TIM1BKIN            |    PB12 PA6   PE15     |
 * |    TIM8ETR             |    PA0                 |
 * |    TIM8CH1             |    PC6                 |
 * |    TIM8CH1N            |    PA7                 |
 * |    TIM8CH2             |    PC7                 |
 * |    TIM8CH2N            |    PB0                 |
 * |    TIM8CH3             |    PC8                 |
 * |    TIM8CH3N            |    PB1                 |
 * |    TIM8CH4             |    PC9                 |
 * |    TIM8CH4N            |                        |
 * |    TIM8BKIN            |    PA6                 |
 * |    TIM2ETR             |    PA0  PA15           |
 * |    TIM2CH1             |    PA0  PA15           |
 * |    TIM2CH2             |    PA1  PB3            |
 * |    TIM2CH3             |    PA2  PB10           |
 * |    TIM2CH4             |    PA3  PB11           |
 * |    TIM3ETR             |    PD2                 |
 * |    TIM3CH1             |    PA6  PB4   PC6  PF8 |
 * |    TIM3CH2             |    PA7  PB5   PC7      |
 * |    TIM3CH3             |    PB0  PC8            |
 * |    TIM3CH4             |    PB1  PC9            |
 * |    TIM4ETR             |    PE0                 |
 * |    TIM4CH1             |    PB6  PD12           |
 * |    TIM4CH2             |    PB7  PD13           |
 * |    TIM4CH3             |    PB8  PD14           |
 * |    TIM4CH4             |    PB9  PD15           |
 * |    TIM5ETR             |                        |
 * |    TIM5CH1             |    PA0                 |
 * |    TIM5CH2             |    PA1                 |
 * |    TIM5CH3             |    PA2                 |
 * |    TIM5CH4             |    PA3                 |
 * |    TIM9CH1             |    PE5  PA2            |
 * |    TIM9CH2             |    PE6  PA3            |
 * |    TIM10CH1            |    PF6                 |
 * |    TIM10CH2            |                        |
 * |    TIM11CH1            |    PF7                 |
 * |    TIM11CH2            |                        |
 * |    TIM12CH1            |    PB14                |
 * |    TIM12CH2            |    PB15                |
 * |    TIM13CH1            |    PA6                 |
 * |    TIM13CH2            |                        |
 * |    TIM14CH1            |    PA7  PF9            |
 * |    TIM14CH2            |                        |
 * |------------------------|------------------------|
 *----------------------------------------------------------------------------
 *                         SPI
 * |------------------------|------------------------|
 * |    SPI1CLK             |    PA5 PB3             |
 * |    SPI1MOSI            |    PA7,PB5             |
 * |    SPI1MISO            |    PA6,PB4             |
 * |    SPI1CS              |    PA4,PA15            |
 * |    SPI2CLK             |    PB13                |
 * |    SPI2MOSI            |    PB15                |
 * |    SPI2MISO            |    PB14                |
 * |    SPI2CS              |    PB12                |
 * |    SPI3CLK             |    PB3                 |
 * |    SPI3MOSI            |    PB5                 |
 * |    SPI3MISO            |    PB4                 |
 * |    SPI3CS              |    PA15                |
 * |------------------------|------------------------|
 *----------------------------------------------------------------------------
 *                         I2C
 * |------------------------|------------------------|
 * |    I2C1SCK             |    PB6   PB8           |
 * |    I2C1SDA             |    PB7   PB9           |
 * |    I2C1SMBA            |    PB5                 |
 * |    I2C2SCK             |    PB10                |
 * |    I2C2SDA             |    PB11                |
 * |    I2C2SMBA            |    PB12                |
 * |------------------------|------------------------|
 *----------------------------------------------------------------------------
 */


#ifndef _VARIANT_
#define _VARIANT_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "Arduino.h"
#ifdef __cplusplus
#include "UARTClass.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#define STM32F1xx

#define STM32RBT6

/** Name of the board */
#define VARIANT_NAME		"STM32RBT6"

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		8000000

/** Master clock frequency */
#define VARIANT_MCK			72000000

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
//sum of ports:
//STM32F10xC&R:PORTA~PORTC
#define PORT_COUNT 3

//currently not usable
#if 0
// Number of pins defined in PinDescription array
#define PINS_COUNT           (79u)

// LEDs
#define PIN_LED_13           (13u)
#define PIN_LED_RXL          (72u)
#define PIN_LED_TXL          (73u)
#define PIN_LED              PIN_LED_13
#define PIN_LED2             PIN_LED_RXL
#define PIN_LED3             PIN_LED_TXL

#endif

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2
/*
#define SPI_INTERFACE        SPI0
#define SPI_INTERFACE_ID     ID_SPI0
#define SPI_CHANNELS_NUM 4
#define PIN_SPI_SS0          (77u)
#define PIN_SPI_SS1          (87u)
#define PIN_SPI_SS2          (86u)
#define PIN_SPI_SS3          (78u)
#define PIN_SPI_MOSI         (75u)
#define PIN_SPI_MISO         (74u)
#define PIN_SPI_SCK          (76u)
#define BOARD_SPI_SS0        (10u)
#define BOARD_SPI_SS1        (4u)
#define BOARD_SPI_SS2        (52u)
#define BOARD_SPI_SS3        PIN_SPI_SS3
#define BOARD_SPI_DEFAULT_SS BOARD_SPI_SS2

#define BOARD_PIN_TO_SPI_PIN(x) \
	(x==BOARD_SPI_SS0 ? PIN_SPI_SS0 : \
	(x==BOARD_SPI_SS1 ? PIN_SPI_SS1 : \
	(x==BOARD_SPI_SS2 ? PIN_SPI_SS2 : PIN_SPI_SS3 )))
#define BOARD_PIN_TO_SPI_CHANNEL(x) \
	(x==BOARD_SPI_SS0 ? 0 : \
	(x==BOARD_SPI_SS1 ? 1 : \
	(x==BOARD_SPI_SS2 ? 2 : 3)))

static const uint8_t SS   = BOARD_SPI_SS0;
static const uint8_t SS1  = BOARD_SPI_SS1;
static const uint8_t SS2  = BOARD_SPI_SS2;
static const uint8_t SS3  = BOARD_SPI_SS3;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;*/

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 	2

#define WIRE_BASE				I2C1_BASE
#define WIRE_PORT_BASE			xGPIO_PORTB_BASE
#define PIN_WIRE_SCL         	PB6
#define PIN_WIRE_SDA         	PB7
#define PERIPHERAL_WIRE_SCL		I2C1SCK
#define PERIPHERAL_WIRE_SDA		I2C1SDA
//#define WIRE_INTERFACE       TWI1
//#define WIRE_INTERFACE_ID    ID_TWI1
//#define WIRE_ISR_HANDLER     TWI1_Handler

#define WIRE1_BASE				I2C2_BASE
#define WIRE1_PORT_BASE			xGPIO_PORTB_BASE
#define PIN_WIRE1_SCL         	PB10
#define PIN_WIRE1_SDA         	PB11
#define PERIPHERAL_WIRE1_SCL	I2C2SCK
#define PERIPHERAL_WIRE1_SDA	I2C2SDA
//#define WIRE1_INTERFACE      TWI0
//#define WIRE1_INTERFACE_ID   ID_TWI0
//#define WIRE1_ISR_HANDLER    TWI0_Handler

/*
 * USB Interfaces
 */
//#define PINS_USB             (85u)
//
/*
 * Analog pins
 */                                    // |------------------------|
static const uint8_t A0  = 0;          // |    PA0 (ADC123)        |
static const uint8_t A1  = 1;          // |    PA1 (ADC123)        |
static const uint8_t A2  = 2;          // |    PA2 (ADC123)        |
static const uint8_t A3  = 3;          // |    PA3 (ADC123)        |
static const uint8_t A4  = 4;          // | PA4(ADC12)  PF6(ADC3)  |
static const uint8_t A5  = 5;          // | PA5(ADC12)  PF7(ADC3)  |
static const uint8_t A6  = 6;          // | PA6(ADC12)  PF8(ADC3)  |
static const uint8_t A7  = 7;          // | PA7(ADC12)  PF9(ADC3)  |
static const uint8_t A8  = 8;          // | PB0(ADC12)  PF10(ADC3) |
static const uint8_t A9  = 9;          // |    PB1 (ADC12)         |
static const uint8_t A10 = 10;         // |    PC0 (ADC123)        |
static const uint8_t A11 = 11;         // |    PC1 (ADC123)        |
static const uint8_t A12 = 12;         // |    PC2 (ADC123)        |
static const uint8_t A13 = 13;         // |    PC3 (ADC123)        |
static const uint8_t A14 = 14;         // |    PC4 (ADC12)         |
static const uint8_t A15 = 15;         // |    PC5 (ADC12)         |
#define ADC_RESOLUTION	   12          // |------------------------|
#define NO_ADC			   0xFFFFFFFF

/*
 * DACC
 */
//#define DACC_INTERFACE		DACC
//#define DACC_INTERFACE_ID	ID_DACC
//#define DACC_RESOLUTION		12
//#define DACC_ISR_HANDLER    DACC_Handler
//#define DACC_ISR_ID         DACC_IRQn
//
/*
 * PWM
 */
#define PWM_INTERFACE		PWM
#define PWM_INTERFACE_ID	ID_PWM
#define PWM_FREQUENCY		1000
#define PWM_MAX_DUTY_CYCLE	255
#define PWM_MIN_DUTY_CYCLE	0
#define PWM_RESOLUTION		8
#define NOT_ON_TIMER		0xFFFFFFFF

/*
 * TC
 */
//#define TC_INTERFACE        TC0
//#define TC_INTERFACE_ID     ID_TC0
//#define TC_FREQUENCY        1000
//#define TC_MAX_DUTY_CYCLE   255
//#define TC_MIN_DUTY_CYCLE   0
//#define TC_RESOLUTION		8

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

extern UARTClass Serial;
extern UARTClass Serial1;
extern UARTClass Serial2;

#endif

#endif /* _VARIANT_ */

