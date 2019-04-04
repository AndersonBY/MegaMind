------------------------------------------------------------------------------
MegaMind Lib
------------------------------------------------------------------------------                

The lastest version can be found here:

https://github.com/AndersonBY/MegaMind

------------------------------------------------------------------------------
General Information
------------------------------------------------------------------------------

MegaMind Lib is a library based on CoX. You can use MegaMind to write Arduino
program on Arm MCU that CoX supports.

More details about CoX can be found here:

http://www.coocox.org

------------------------------------------------------------------------------
How to use MegaMind lib
------------------------------------------------------------------------------
#### 1.Download GCC Complier

Before Using CoIDE you need to set up GCC tool chain. Please refer to the 
website:

http://www.coocox.org/CoIDE/Compiler_Settings.html


#### 2.Download CoIDE and CoX

MegaMind is developed on CoIDE, so it's recommended to use CoIDE. To Download
CoIDE and CoX, please refer to coocox website:

http://www.coocox.org

According to the coocox website it's recommended to download all component 
through CoCenter(That's also how I downloaded:)).


#### 3.Add CoX to your project

Follow the instructions on the website you should be able to add CoX to your 
project. Remember to choose PERIPHERAL.COX in Repository and choose the 
following componets:

xStartup
xLowLayer
xCORE
xSysCtl
xGPIO
xUART
xPWM
xADC

The Componets above didn't include SPI and I2C which havn't been develop in 
MegaMind Lib.


#### 4.Add MegaMind Lib to your project

Copy MegaMind folder to your project. Add it in CoIDE.


#### 5.Using C++ in CoIDE

Please refer to Use_C++_in_CoIDE.md file.


#### 6.Rename main.c

Rename main.c file in your project to other name like userMain.cpp.
Remember to end with .cpp


#### 7.Include "Arduino.h"
In the userMain.cpp add:"#include "Arduino.h""


#### 8.Done!
Now you can use Arduino in Arm MCU.
Add your code in userMain.cpp.


------------------------------------------------------------------------------
Difference between MegaMind and Arduino language
------------------------------------------------------------------------------

#### 1.
In order to applied to more Arm MCU, MegaMind use two parameters to describe
pin.One is the port name, another is pin number.
Example:

#####In Arduino:
######pinMode(8, OUTPUT);
######digitalWrite(8, HIGH);

#####In MegaMind:
######pinMode(PORTA, 8, OUTPUT);
######digitalWrite(PORTA, 8 ,HIGH);

Usually there are 16 pins in one port:0~15.

Port name: PORTA,PORTB,PORTC...

One exception is analogRead(). MegaMind Still use A0,A1... as pin number.

####2.
analogWrite() accept pwm value between 0~100 while in Arduino it's 0~255.


------------------------------------------------------------------------------
Use MegaMind on other Arm MCU
------------------------------------------------------------------------------

I have tested MegaMind lib on STM32F103RBT6. To Use MegaMind on different Arm 
MCU, THEORETICALLY you only need to modify 
* variant.h
* variant.cpp 
* variantUART.h  

which define details of pins in different Arm MCU. Please tell me if you can across
any problems.


------------------------------------------------------------------------------
Contact Me
------------------------------------------------------------------------------
Email:andersonby@163.com
