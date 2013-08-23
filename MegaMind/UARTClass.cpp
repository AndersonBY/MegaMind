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

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
#include "UARTClass.h"

// Constructors ////////////////////////////////////////////////////////////////

UARTClass::UARTClass(unsigned char uart_num)
{
	_uart_num = uart_num;
//	_uart_base = g_uartPinDescription[_uart_num].uartBase;
}

// Public Methods //////////////////////////////////////////////////////////////

void UARTClass::begin(unsigned long dwBaudRate)
{
	switch(_uart_num){
#ifdef _SERIAL
	case 0:
		xSysCtlPeripheralEnable(PERIPHERAL_PORT_UART);
		xSysCtlPeripheralEnable(SYSCTL_PERIPH_AFIO);

		xSPinTypeUART(PERIPHERAL_UART_TX, PIN_UART_TX);
		xSPinTypeUART(PERIPHERAL_UART_TX, PIN_UART_TX);

		xSysCtlPeripheralReset(PERIPHERAL_UART_UART);
		xSysCtlPeripheralEnable(PERIPHERAL_UART_UART);

		_uart_base = UART_BASE;
		xUARTConfigSet(_uart_base, dwBaudRate,
				(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

		xUARTIntEnable(_uart_base, UART_INT_RXNE);
		xUARTIntCallbackInit (_uart_base, uartIntFunction);

		xUARTEnable(_uart_base, (UART_BLOCK_UART | UART_BLOCK_TX | UART_BLOCK_RX));
		xIntEnable (INTERRUPT_UART);
		break;
#endif
#ifdef _SERIAL1
	case 1:
		break;
#endif
#ifdef _SERIAL2
	case 2:
		break;
#endif
#ifdef _SERIAL3
	case 3:
		break;
#endif
#ifdef _SERIAL4
	case 4:
		break;
#endif
	}
#if 0
	xSysCtlPeripheralEnable(g_uartPinDescription[_uart_num].ulPeripheralPortId);
	xSysCtlPeripheralEnable(SYSCTL_PERIPH_AFIO);

	//TODO:GPIOPinConfigure function might be different from other ARM
	//TODO:Write GPIOPinConfigure fuction for different ARM
	//GPIO Pin Config TX
	GPIOPinConfigure(
			g_uartPinDescription[_uart_num].ulPortBase,
			g_uartPinDescription[_uart_num].ulPinTX,
			g_uartPinDescription[_uart_num].ulPinConfigTX);

	//GPIO Pin Config RX
	GPIOPinConfigure(
			g_uartPinDescription[_uart_num].ulPortBase,
			g_uartPinDescription[_uart_num].ulPinRX,
			g_uartPinDescription[_uart_num].ulPinConfigRX);

	xSysCtlPeripheralReset(g_uartPinDescription[_uart_num].ulPeripheralUartId);
	xSysCtlPeripheralEnable(g_uartPinDescription[_uart_num].ulPeripheralUartId);

	xUARTConfigSet(_uart_base, dwBaudRate, (UART_CONFIG_WLEN_8 |
	                                     UART_CONFIG_STOP_ONE |
	                                     UART_CONFIG_PAR_NONE));

	xUARTIntEnable(_uart_base, UART_INT_RXNE);

	switch(_uart_num){
#ifdef _SERIAL
	case 0:
		xUARTIntCallbackInit (_uart_base, uart1IntFunction);
		break;
#endif
#ifdef _SERIAL1
	case 1:
		xUARTIntCallbackInit (_uart_base, uart2IntFunction);
		break;
#endif
#ifdef _SERIAL2
	case 2:
		xUARTIntCallbackInit (_uart_base, uart3IntFunction);
		break;
#endif
#ifdef _SERIAL3
	case 3:
		xUARTIntCallbackInit (_uart_base, uart4IntFunction);
		break;
#endif
#ifdef _SERIAL4
	case 4:
		xUARTIntCallbackInit (_uart_base, uart5IntFunction);
		break;
#endif
	}
	xUARTEnable(_uart_base, (UART_BLOCK_UART | UART_BLOCK_TX | UART_BLOCK_RX));
	xIntEnable (g_uartPinDescription[_uart_num].ulInterruptId);
#endif
}

void UARTClass::end( void )
{
  // clear any received data
  _rx_buffer._iHead = _rx_buffer._iTail ;

  // Wait for any outstanding data to be sent
  flush();
}

int UARTClass::available( void )
{
	return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer._iHead - _rx_buffer._iTail) % SERIAL_BUFFER_SIZE;
}

int UARTClass::peek( void )
{
  if ( _rx_buffer._iHead == _rx_buffer._iTail )
    return -1 ;

  return _rx_buffer._aucBuffer[_rx_buffer._iTail] ;
}

int UARTClass::read( void )
{
  // if the head isn't ahead of the tail, we don't have any characters
  if ( _rx_buffer._iHead == _rx_buffer._iTail )
    return -1 ;

  unsigned char uc = _rx_buffer._aucBuffer[_rx_buffer._iTail] ;
  _rx_buffer._iTail = (unsigned int)(_rx_buffer._iTail + 1) % SERIAL_BUFFER_SIZE ;
  return uc ;
}

void UARTClass::flush( void )
{
  // Wait for transmission to complete
//  while ((_pUart->UART_SR & UART_SR_TXRDY) != UART_SR_TXRDY)
//    ;
}

//clear() is used to clear the rx buffer
void UARTClass::clear(void)
{
	// clear any received data
	_rx_buffer._iHead = _rx_buffer._iTail ;
}

size_t UARTClass::write(unsigned char uc_data )
{
//  // Check if the transmitter is ready
//  while ((_pUart->UART_SR & UART_SR_TXRDY) != UART_SR_TXRDY)
//    ;

  // Send character and return status
	xUARTCharPut(_uart_base, uc_data);
	return 1;
}

//size_t UARTClass::write(const uint8_t *buffer, size_t size)
//{
//	xUARTCharPut(_uart_base, '4');
//  size_t n = 0;
//  while (size--) {
//    n += write(*buffer++);
//  }
//  return n;
//}

unsigned char UARTClass::uartInt(void)
{

	//ATTENTION:进入中断函数后无法使用xUARTCharGet或者xUARTCharGetNonBlocking
	//因为进入中断函数后USART_SR_RXNE标志位（receive data not empty）仍为0,
	//但此时USART_DR标志位(Data Register)已经有数据进来了
	//所以在串口中断函数中只能直接使用xHWREG( _uart_base + USART_DR)来获取数据

	//TODO:Should not directly write register here. Use other function.
	long c = xHWREG(_uart_base + USART_DR);

	if (c!=-1){
		_rx_buffer.store_char(c);
		return 1;
	}
	return 0;

}

