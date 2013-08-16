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

#include "wiring.h"
#include "Arduino.h"

volatile long sysTickCount = 0;

#ifdef __cplusplus
extern "C" {
#endif

// When SysTick is thrown, this code is performed
void SysTickIntHandler( void )
{
	sysTickCount++;
}

//ms
uint32_t millis( void )
{
// todo: ensure no interrupts
	return sysTickCount/1000;
}

//us
uint32_t micros( void )
{
    return sysTickCount;
}

void delay( uint32_t ms )
{
    uint32_t end = millis() + ms;
    while (millis() < end){}
}

void delayMicroseconds( uint32_t us )
{
    uint32_t start = micros();
    while ((micros() - start) < us){}
}

#if defined ( __ICCARM__ ) /* IAR Ewarm 5.41+ */
extern signed int putchar( signed int c ) ;
/**
 * \brief
 *
 * \param c  Character to output.
 *
 * \return The character that was output.
 */
extern WEAK signed int putchar( signed int c )
{
    return c ;
}
#endif /* __ICCARM__ */

#ifdef __cplusplus
}
#endif
