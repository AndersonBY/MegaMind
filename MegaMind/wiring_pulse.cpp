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

#include "Arduino.h"
#include "wiring_private.h"

extern volatile long sysTickCount;

/* Measures the length (in microseconds) of a pulse on the pin; state is HIGH
 * or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
 * to 3 minutes in length, but must be called at least a few dozen microseconds
 * before the start of the pulse. */
extern uint32_t pulseIn( uint32_t ulPort, uint32_t ulPin, uint32_t state, uint32_t timeout )
{
	// cache the port and bit of the pin in order to speed up the
	// pulse width measuring loop and achieve finer resolution.  calling
	// digitalRead() instead yields much coarser resolution.
	uint32_t portBase = g_APinDescription[ulPort][ulPin].ulPortBase;
	uint32_t pinNum = 0x0001<<ulPin;
	uint32_t width = 0; // keep initialization out of time critical area
	uint32_t start = sysTickCount;

	// wait for any previous pulse to end
	while (bitRead(xGPIOPinRead(portBase,pinNum),ulPin) == state)
		if ((sysTickCount - start) >= timeout)
			return 0;

	// wait for the pulse to start
	while (bitRead(xGPIOPinRead(portBase,pinNum),ulPin) != state)
		if ((sysTickCount - start) >= timeout)
			return 0;
	
	uint32_t pulseStart = sysTickCount;

	// wait for the pulse to stop
	while (bitRead(xGPIOPinRead(portBase,pinNum),ulPin) == state){
		if ((sysTickCount - start)>= timeout)
			return 0;
		width = sysTickCount - pulseStart;
	}

	return width;
}
