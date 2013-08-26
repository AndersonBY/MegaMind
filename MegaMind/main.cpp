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

#define ARDUINO_MAIN
#include "Arduino.h"

/*
 * \brief Main entry point of Arduino application
 */

void analogInit(void)
{
	//
	// Reset ADC
	//
//	xSysCtlPeripheralReset(xSYSCTL_PERIPH_ADC1);

	//
	// Set ADC clock source
	//
	xSysCtlPeripheralClockSourceSet(xSYSCTL_ADC0_MAIN, 4);
 	//
	// Enable Peripheral ADC
	//
	xSysCtlPeripheralEnable(xSYSCTL_PERIPH_ADC1);
}

void init(void)
{
	xSysCtlClockSet(72000000, xSYSCTL_OSC_MAIN | xSYSCTL_XTAL_8MHZ);
	xSysTickPeriodSet(72);
	xSysTickIntEnable();
	xSysTickEnable();

	xSysCtlDelay(10000);

	analogInit();
}

int main( void )
{
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif

	setup();

	for (;;)
	{
		loop();

		//No need to use serialEvent function
//		if (serialEventRun) serialEventRun();
	}

	return 0;
}
