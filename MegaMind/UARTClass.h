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

#ifndef _UART_CLASS_
#define _UART_CLASS_

#include "HardwareSerial.h"
#include "RingBuffer.h"

#include "variantUART.h"

#include "xhw_types.h"
#include "xhw_ints.h"
#include "xhw_nvic.h"
#include "xhw_memmap.h"
#include "xhw_uart.h"
#include "xdebug.h"
#include "xcore.h"
#include "xsysctl.h"
#include "xgpio.h"
#include "xuart.h"

extern unsigned long
uartIntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData);

extern unsigned long
uart1IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData);

extern unsigned long
uart2IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData);

extern unsigned long
uart3IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData);

extern unsigned long
uart4IntFunction(void *pvCBData, unsigned long ulEvent,
        unsigned long ulMsgParam,void *pvMsgData);

class UARTClass : public HardwareSerial
{
  protected:
    RingBuffer _rx_buffer ;
    unsigned long _uart_base;
    unsigned char _uart_num;

  public:
    UARTClass(unsigned char uart_num) ;

    void begin( unsigned long dwBaudRate ) ;
    void end( void ) ;
    int available( void ) ;
    int peek( void ) ;
    int read( void ) ;
    void flush( void ) ;
    void clear( void ) ;
    size_t write( uint8_t c ) ;
//    size_t write( const uint8_t *buffer, size_t size);

    unsigned char uartInt(void);

    //Currently not usable
#if 0
#if defined __GNUC__ /* GCC CS3 */
    using Print::write ; // pull in write(str) and write(buf, size) from Print
#elif defined __ICCARM__ /* IAR Ewarm 5.41+ */
//    virtual void write( const char *str ) ;
//    virtual void write( const uint8_t *buffer, size_t size ) ;
#endif

    operator bool() { return true; }; // UART always active
#endif
};

#endif // _UART_CLASS_
