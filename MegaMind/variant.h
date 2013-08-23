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

#ifndef _VARIANT_ARDUINO_DUE_X_
#define _VARIANT_ARDUINO_DUE_X_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "Arduino.h"
#ifdef __cplusplus
#include "UARTClass.h"
//#include "USARTClass.h"
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
//
///*----------------------------------------------------------------------------
// *        Pins
// *----------------------------------------------------------------------------*/
//sum of ports:
//STM32F10xC&R:PORTA~PORTC
#define PORT_COUNT 3
//
// Number of pins defined in PinDescription array
#define PINS_COUNT           (79u)
//
// LEDs
//#define PIN_LED_13           (13u)
//#define PIN_LED_RXL          (72u)
//#define PIN_LED_TXL          (73u)
//#define PIN_LED              PIN_LED_13
//#define PIN_LED2             PIN_LED_RXL
//#define PIN_LED3             PIN_LED_TXL

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2
//
//#define SPI_INTERFACE        SPI0
//#define SPI_INTERFACE_ID     ID_SPI0
//#define SPI_CHANNELS_NUM 4
//#define PIN_SPI_SS0          (77u)
//#define PIN_SPI_SS1          (87u)
//#define PIN_SPI_SS2          (86u)
//#define PIN_SPI_SS3          (78u)
//#define PIN_SPI_MOSI         (75u)
//#define PIN_SPI_MISO         (74u)
//#define PIN_SPI_SCK          (76u)
//#define BOARD_SPI_SS0        (10u)
//#define BOARD_SPI_SS1        (4u)
//#define BOARD_SPI_SS2        (52u)
//#define BOARD_SPI_SS3        PIN_SPI_SS3
//#define BOARD_SPI_DEFAULT_SS BOARD_SPI_SS2
//
/*#define BOARD_PIN_TO_SPI_PIN(x) \
	(x==BOARD_SPI_SS0 ? PIN_SPI_SS0 : \
	(x==BOARD_SPI_SS1 ? PIN_SPI_SS1 : \
	(x==BOARD_SPI_SS2 ? PIN_SPI_SS2 : PIN_SPI_SS3 )))
#define BOARD_PIN_TO_SPI_CHANNEL(x) \
	(x==BOARD_SPI_SS0 ? 0 : \
	(x==BOARD_SPI_SS1 ? 1 : \
	(x==BOARD_SPI_SS2 ? 2 : 3)))*/
//
//static const uint8_t SS   = BOARD_SPI_SS0;
//static const uint8_t SS1  = BOARD_SPI_SS1;
//static const uint8_t SS2  = BOARD_SPI_SS2;
//static const uint8_t SS3  = BOARD_SPI_SS3;
//static const uint8_t MOSI = PIN_SPI_MOSI;
//static const uint8_t MISO = PIN_SPI_MISO;
//static const uint8_t SCK  = PIN_SPI_SCK;

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
 * UART/USART Interfaces
 */
#define UART_INTERFACES_COUNT 		3
// Serial1
#define _SERIAL1
//#define PIN_UART1_CK		        PA8
//#define PIN_UART1_TX		        PA9
//#define PIN_UART1_RX		        PA10
//#define PIN_UART1_CTS		        PA11
//#define PIN_UART1_RTS		        PA12
//#define PERIPHERAL_UART1_CK		    UART1CK
//#define PERIPHERAL_UART1_TX		    UART1TX
//#define PERIPHERAL_UART1_RX		    UART1RX
//#define PERIPHERAL_UART1_CTS		UART1CTS
//#define PERIPHERAL_UART1_RTS		UART1RTS
//#define PERIPHERAL_PORT_UART1		xSYSCTL_PERIPH_GPIOA
//#define PERIPHERAL_UART_UART1		xSYSCTL_PERIPH_UART1
//#define INTERRUPT_UART1				xINT_UART1
//#define PORT_BASE_UART1				xGPIO_PORTA_BASE
//#define UART1_BASE					USART1_BASE
// Serial2
#define _SERIAL2
//#define PIN_UART2_CK		        PA4
//#define PIN_UART2_TX		        PA2
//#define PIN_UART2_RX		        PA3
//#define PIN_UART2_CTS		        PA0
//#define PIN_UART2_RTS		        PA1
//#define PERIPHERAL_UART2_CK		    UART2CK
//#define PERIPHERAL_UART2_TX		    UART2TX
//#define PERIPHERAL_UART2_RX		    UART2RX
//#define PERIPHERAL_UART2_CTS		UART2CTS
//#define PERIPHERAL_UART2_RTS		UART2RTS
//#define PERIPHERAL_PORT_UART2		xSYSCTL_PERIPH_GPIOA
//#define PERIPHERAL_UART_UART2		xSYSCTL_PERIPH_UART2
//#define INTERRUPT_UART2				xINT_UART2
//#define PORT_BASE_UART2				xGPIO_PORTA_BASE
//#define UART2_BASE					USART2_BASE
// Serial3
#define _SERIAL3
//#define PIN_UART3_CK		        PB12
//#define PIN_UART3_TX		        PB10
//#define PIN_UART3_RX		        PB11
//#define PIN_UART3_CTS		        PB13
//#define PIN_UART3_RTS		        PB14
//#define PERIPHERAL_UART3_CK		    UART3CK
//#define PERIPHERAL_UART3_TX		    UART3TX
//#define PERIPHERAL_UART3_RX		    UART3RX
//#define PERIPHERAL_UART3_CTS		UART3CTS
//#define PERIPHERAL_UART3_RTS		UART3RTS
//#define PERIPHERAL_PORT_UART3		xSYSCTL_PERIPH_GPIOB
//#define PERIPHERAL_UART_UART3		xSYSCTL_PERIPH_UART3
//#define INTERRUPT_UART3				xINT_UART3
//#define PORT_BASE_UART3				xGPIO_PORTB_BASE
//#define UART3_BASE					USART3_BASE
///*
// * USB Interfaces
// */
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
//
///*
// * DACC
// */
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
//
///*
// * TC
// */
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

extern UARTClass Serial1;
extern UARTClass Serial2;
extern UARTClass Serial3;

#endif

#endif /* _VARIANT_ARDUINO_DUE_X_ */

