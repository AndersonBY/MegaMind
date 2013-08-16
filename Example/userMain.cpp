#include "Arduino.h"

void setup(void)
{
	Serial1.begin(9600);
	pinMode(PORTA, 8, OUTPUT);
	pinMode(PORTA, 11, INPUT_PULLDOWN);
}

void loop(void)
{
	Serial1.println("Hello MegaMind!");
	Serial1.print("PA11 State:");
	Serial1.println(digitalRead(PORTA, 11));
	Serial1.print("analogRead A7(PA7):");
	Serial1.println(analogRead(A7));

	for(int i=0;i<100;i++){
		analogWrite(PORTA, 8, i);
		delay(20);
	}

	digitalWrite(PORTA, 8, LOW);
	delay(100);
	digitalWrite(PORTA, 8, HIGH);
	delay(100);
}
