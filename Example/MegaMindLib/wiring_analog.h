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

#ifndef _WIRING_ANALOG_
#define _WIRING_ANALOG_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _eAnalogReference
{
  AR_DEFAULT,
} eAnalogReference ;

extern void analogReference( eAnalogReference ulMode ) ;

void pwmInit(uint32_t ulBase, uint32_t ulChannel);

extern void analogWrite( uint32_t ulPort, uint32_t ulPin, uint32_t ulValue ) ;

/*
 * \brief Reads the value from the specified analog pin.
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: ADCn         |should be: PXn          |
//! |                    |n indicate the pin      |XX indicate the GPIO    |
//! |                    |number such as          |PORT,Such as            |
//! |                    |0 1 2 3 ....            |A B C D E ...           |
//! |                    |                        |n indicate the pin      |
//! |                    |                        |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |      STM32F1xx     |    ADC0                |    PA0 (ADC123)        |
//! |                    |    ADC1                |    PA1 (ADC123)        |
//! |                    |    ADC2                |    PA2 (ADC123)        |
//! |                    |    ADC3                |    PA3 (ADC123)        |
//! |                    |    ADC4                | PA4(ADC12)  PF6(ADC3)  |
//! |                    |    ADC5                | PA5(ADC12)  PF7(ADC3)  |
//! |                    |    ADC6                | PA6(ADC12)  PF8(ADC3)  |
//! |                    |    ADC7                | PA7(ADC12)  PF9(ADC3)  |
//! |                    |    ADC8                | PB0(ADC12)  PF10(ADC3) |
//! |                    |    ADC9                |    PB1 (ADC12)         |
//! |                    |    ADC10               |    PC0 (ADC123)        |
//! |                    |    ADC11               |    PC1 (ADC123)        |
//! |                    |    ADC12               |    PC2 (ADC123)        |
//! |                    |    ADC13               |    PC3 (ADC123)        |
//! |                    |    ADC14               |    PC4 (ADC12)         |
//! |                    |    ADC15               |    PC5 (ADC12)         |
//! |--------------------|------------------------|------------------------|
 *
 * \param ulPin
 *
 * \return Read value from selected pin, if no error.
 */
extern uint32_t analogRead( uint32_t ulPin ) ;

/*
 * \brief Set the resolution of analogRead return values. Default is 10 bits (range from 0 to 1023).
 *
 * \param res
 */
//extern void analogReadResolution(int res);

/*
 * \brief Set the resolution of analogWrite parameters. Default is 8 bits (range from 0 to 255).
 *
 * \param res
 */
//extern void analogWriteResolution(int res);

//extern void analogOutputInit( void ) ;

#ifdef __cplusplus
}
#endif

#endif /* _WIRING_ANALOG_ */
