#include "Arduino.h"
#include "Wire.h"

//This Example Show how to use I2C to read ADXL345 3-axis XYZ data

#define I2C_SLAVE_ADDR  0x53

#define Register_ID 0
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37

void setup(void){
	Serial1.begin(9600);

	Wire.begin();

	//Enable ADXL345 Measure Function
	Wire.beginTransmission(I2C_SLAVE_ADDR);
	Wire.write(Register_2D);
	Wire.write(0x08);
	Wire.endTransmission();

	delay(500);
}

void loop(void)
{
	//Read Accelerometer XYZ data in continue mode
	Wire.beginTransmission(I2C_SLAVE_ADDR);
	Wire.write(Register_X0);
	Wire.endTransmission();

	Wire.requestFrom(I2C_SLAVE_ADDR, 6);
	Serial1.print("available:");
	Serial1.println(Wire.available());

	for(int i=0;i<6;i++){
		uint8_t recByte = Wire.read();
		Serial1.print(recByte);
		Serial1.print("\t");
	}
	Serial1.println();
}
