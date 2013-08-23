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

#ifdef __cplusplus
extern "C" {
#endif

static int _readResolution = 12;
static int _writeResolution = 8;

//_pwmInitPortPins[0]: whether PORTA Pin has initialized or not.Tag by bit.
//_pwmInitPortPins[1]: PORTB...
static uint32_t _pwmInitPortPins[PORT_COUNT] = {0};

void analogReadResolution(int res) {
	_readResolution = res;
}

void analogWriteResolution(int res) {
	_writeResolution = res;
}

static inline uint32_t mapResolution(uint32_t value, uint32_t from, uint32_t to) {
	if (from == to)
		return value;
	if (from > to)
		return value >> (from-to);
	else
		return value << (to-from);
}

eAnalogReference analog_reference = AR_DEFAULT;

void analogReference(eAnalogReference ulMode)
{
	analog_reference = ulMode;
}

uint32_t analogRead(uint32_t ulPin)
{
	unsigned long ulData[1];

	//
	// configure GPIO pin as ADC function
	//
	GPIOPinConfigure(
			g_analogPinDescription[ulPin].ulPortBase,
			g_analogPinDescription[ulPin].ulPin,
			g_analogPinDescription[ulPin].ulPinConfig);

	//
	// ADC convert once, Software tirgger.
	//
	xADCConfigure(xADC1_BASE, ADC_OP_SINGLE, ADC_TRIGGER_PROCESSOR);

	//
	// Enable the channel
	//
	xADCStepConfigure(xADC1_BASE, 0, xADC_CTL_CH0+ulPin);//xADC_CTL_CH1

	//
	// Enable the adc
	//
	xADCEnable(xADC1_BASE);

	xADCProcessorTrigger(xADC1_BASE);

	xADCDataGet(xADC1_BASE, ulData);

	return ulData[0];
}
//
//static void TC_SetCMR_ChannelA(Tc *tc, uint32_t chan, uint32_t v)
//{
//	tc->TC_CHANNEL[chan].TC_CMR = (tc->TC_CHANNEL[chan].TC_CMR & 0xFFF0FFFF) | v;
//}
//
//static void TC_SetCMR_ChannelB(Tc *tc, uint32_t chan, uint32_t v)
//{
//	tc->TC_CHANNEL[chan].TC_CMR = (tc->TC_CHANNEL[chan].TC_CMR & 0xF0FFFFFF) | v;
//}
//
//static uint8_t PWMEnabled = 0;
//static uint8_t pinEnabled[PINS_COUNT];
//static uint8_t TCChanEnabled[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
//
//void analogOutputInit(void) {
//	uint8_t i;
//	for (i=0; i<PINS_COUNT; i++)
//		pinEnabled[i] = 0;
//}
//
// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.

void pwmInit(uint32_t ulBase, uint32_t ulChannel){
	//
	// Configure PWM
	//
	//	xPWMInitConfigure(xPWMA_BASE, xPWM_CHANNEL0, xPWM_OUTPUT_INVERTER_DIS|xPWM_DEAD_ZONE_DIS);
	xPWMInitConfigure(ulBase, ulChannel, xPWM_OUTPUT_INVERTER_DIS|xPWM_DEAD_ZONE_DIS);

	//
	// Set PWM Frequency(1000Hz)
	//
	//	xPWMFrequencyConfig(xPWMA_BASE, xPWM_CHANNEL0, xPWM_FREQ_CONFIG(1,0x48,0x3E8));
	xPWMFrequencyConfig(ulBase, ulChannel, xPWM_FREQ_CONFIG(1,0x48,0x3E8));

	//
	// Set pwm Duty to 50
	//
	//xPWMDutySet(xPWMA_BASE, xPWM_CHANNEL0, 95);
	xPWMDutySet(ulBase, ulChannel, 50);

	//
	// Enable PWM Output
	//
	//xPWMOutputEnable(xPWMA_BASE, xPWM_CHANNEL0);
	xPWMOutputEnable(ulBase, ulChannel);

	//
	// Start PWM
	//
	//xPWMStart(xPWMA_BASE, xPWM_CHANNEL0);
	xPWMStart(ulBase, ulChannel);
}

void analogWrite( uint32_t ulPort, uint32_t ulPin, uint32_t ulValue ) {

	if(bitRead(_pwmInitPortPins[ulPort],ulPin)==0){
		bitSet(_pwmInitPortPins[ulPort],ulPin);
		xSysCtlPeripheralEnable(g_APinDescription[ulPort][ulPin].ulPeripheralPortId);
		xSysCtlPeripheralEnable(SYSCTL_PERIPH_AFIO);
		xSysCtlPeripheralEnable(g_APinDescription[ulPort][ulPin].ulPeripheralTimerId);
		GPIOPinConfigure(
				g_APinDescription[ulPort][ulPin].ulPortBase,
				g_APinDescription[ulPort][ulPin].ulPin,
				g_APinDescription[ulPort][ulPin].ulTimerPinConfig);
		pwmInit(g_APinDescription[ulPort][ulPin].ulTimerBase,
				g_APinDescription[ulPort][ulPin].ulTimerChannel);
	}
	xPWMDutySet(g_APinDescription[ulPort][ulPin].ulTimerBase,
				g_APinDescription[ulPort][ulPin].ulTimerChannel,
				ulValue);

//
//	// Defaults to digital write
//	pinMode(ulPin, OUTPUT);
//	ulValue = mapResolution(ulValue, _writeResolution, 8);
//	if (ulValue < 128)
//		digitalWrite(ulPin, LOW);
//	else
//		digitalWrite(ulPin, HIGH);
}

#ifdef __cplusplus
}
#endif
