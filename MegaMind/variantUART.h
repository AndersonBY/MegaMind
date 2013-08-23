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


#ifndef _VARIANTUART_
#define _VARIANTUART_


/*
 * UART/USART Interfaces
 */
#define UART_INTERFACES_COUNT 		3
// Serial
#define _SERIAL
#define PIN_UART_CK		            PA8
#define PIN_UART_TX		            PA9
#define PIN_UART_RX		            PA10
#define PIN_UART_CTS		        PA11
#define PIN_UART_RTS		        PA12
#define PERIPHERAL_UART_CK		    UART1CK
#define PERIPHERAL_UART_TX		    UART1TX
#define PERIPHERAL_UART_RX		    UART1RX
#define PERIPHERAL_UART_CTS		    UART1CTS
#define PERIPHERAL_UART_RTS		    UART1RTS
#define PERIPHERAL_PORT_UART		xSYSCTL_PERIPH_GPIOA
#define PERIPHERAL_UART_UART		xSYSCTL_PERIPH_UART1
#define INTERRUPT_UART				xINT_UART1
#define PORT_BASE_UART				xGPIO_PORTA_BASE
#define UART_BASE					USART1_BASE
// Serial1
#define _SERIAL1
#define PIN_UART1_CK		        PA4
#define PIN_UART1_TX		        PA2
#define PIN_UART1_RX		        PA3
#define PIN_UART1_CTS		        PA0
#define PIN_UART1_RTS		        PA1
#define PERIPHERAL_UART1_CK		    UART2CK
#define PERIPHERAL_UART1_TX		    UART2TX
#define PERIPHERAL_UART1_RX		    UART2RX
#define PERIPHERAL_UART1_CTS		UART2CTS
#define PERIPHERAL_UART1_RTS		UART2RTS
#define PERIPHERAL_PORT_UART1		xSYSCTL_PERIPH_GPIOA
#define PERIPHERAL_UART_UART1		xSYSCTL_PERIPH_UART2
#define INTERRUPT_UART1				xINT_UART2
#define PORT_BASE_UART1				xGPIO_PORTA_BASE
#define UART1_BASE					USART2_BASE
// Serial2
#define _SERIAL2
#define PIN_UART2_CK		        PB12
#define PIN_UART2_TX		        PB10
#define PIN_UART2_RX		        PB11
#define PIN_UART2_CTS		        PB13
#define PIN_UART2_RTS		        PB14
#define PERIPHERAL_UART2_CK		    UART3CK
#define PERIPHERAL_UART2_TX		    UART3TX
#define PERIPHERAL_UART2_RX		    UART3RX
#define PERIPHERAL_UART2_CTS		UART3CTS
#define PERIPHERAL_UART2_RTS		UART3RTS
#define PERIPHERAL_PORT_UART2		xSYSCTL_PERIPH_GPIOB
#define PERIPHERAL_UART_UART2		xSYSCTL_PERIPH_UART3
#define INTERRUPT_UART2				xINT_UART3
#define PORT_BASE_UART2				xGPIO_PORTB_BASE
#define UART2_BASE					USART3_BASE

#endif//_VARIANT_UART_
