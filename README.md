MegaMind

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
1.Download GCC Complier

Before Using CoIDE you need to set up GCC tool chain. Please refer to the 
website:

http://www.coocox.org/CoIDE/Compiler_Settings.html

-------------------------------
2.Download CoIDE and CoX

MegaMind is developed on CoIDE, so it's recommended to use CoIDE. To Download
CoIDE and CoX, please refer to coocox website:

http://www.coocox.org

According to the coocox website it's recommended to download all component 
through CoCenter(That's also how I downloaded:)).

-------------------------------
3.Add CoX to your project

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

-------------------------------
4.Using C++ in CoIDE

To use C++ you need to do some modification.


4.1 Modify arm-gcc-link.ld file

You can find arm-gcc-link.ld in 

CooCox\CoIDE\configuration\ProgramData\ (Your project name)

One thing to be noticed is that it seems that you can only find this file when
you're openning the project you are working on in CoIDE.

After openning arm-gcc-link.ld, you should add something so it looks like this:
/* Section Definitions */
SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector .isr_vector.*))
        *(.text .text.* .gnu.linkonce.t.*)       
        *(.glue_7t) *(.glue_7)                      
        *(.rodata .rodata* .gnu.linkonce.r.*)  
       
        /* C++ Static constructors/destructors (eabi) */
       . = ALIGN(4);
       KEEP(*(.init))
      
       . = ALIGN(4);
       __preinit_array_start = .;
       KEEP (*(.preinit_array))
       __preinit_array_end = .;
      
       . = ALIGN(4);
       __init_array_start = .;
       KEEP (*(SORT(.init_array.*)))
       KEEP (*(.init_array))
       __init_array_end = .;
      
       . = ALIGN(4);
       KEEP(*(.fini))
      
       . = ALIGN(4);
       __fini_array_start = .;
       KEEP (*(.fini_array))
       KEEP (*(SORT(.fini_array.*)))
       __fini_array_end = .;
      
       /* C++ Staticconstructors/destructors (elf) */
       . = ALIGN(4);
       _ctor_start = .;
       KEEP (*crtbegin.o(.ctors))
       KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
       KEEP (*(SORT(.ctors.*)))
       KEEP (*crtend.o(.ctors))
       _ctor_end = .;
      
       . = ALIGN(4);
       KEEP (*crtbegin.o(.dtors))
       KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
       KEEP (*(SORT(.dtors.*)))
       KEEP (*crtend.o(.dtors))                       
    } > rom
   
    .ARM.extab :
    {
        *(.ARM.extab*.gnu.linkonce.armextab.*)
} > rom
…
…
    /* stack section */
    .co_stack (NOLOAD):
    {
        . = ALIGN(8);
        *(.co_stack .co_stack.*)
    } > ram
   
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > rom
    __exidx_end = .;
   
      
    . = ALIGN(4);
    _end = . ;
}

You can find arm-gcc-link.ld in https://github.com/AndersonBY/MegaMind
as an example which is tested on STM32F103RBT6.


4.2 Modify startup code

Open startup_coide.c and add the following code:

…
extern unsigned long __preinit_array_start;
extern unsigned long __preinit_array_end;
extern unsigned long __init_array_start;
extern unsigned long __init_array_end;
extern unsigned long _ctor_start;
extern unsigned long _ctor_end;
static void call_constructors(unsigned long *start,unsigned long *end) __attribute__((noinline));
static void call_constructors(unsigned long *start,unsigned long *end)
{
  unsigned long *i;
  void (*funcptr)();
  for ( i = start; i < end; i++)
  {
    funcptr=(void (*)())(*i);
    funcptr();
  }
}
…
void Default_Reset_Handler(void)
{
…
  /* Setup the microcontrollersystem. */
  SystemInit();
   
  //InitializeCoOS (in order the new/delete operators to work properly
  //prior tocalling constructors). Comment it out if you don't use CoOS!
  //CoInitOS();
 
  //Call C++global constructors
  call_constructors(&__preinit_array_start,&__preinit_array_end);
  call_constructors(&__init_array_start,&__init_array_end);
  call_constructors(&_ctor_start,&_ctor_end);
 
  /* Call the application's entry point.*/
  main();
}


4.3 Choose CLibrary in Repository

Open Repository in CoIDE and choose C Library.


4.4 Add C++ library

Open Configuration in CoIDE and in Link tab:
Press Add in Linked Libraries and type stdc++, then press OK.
Add supc++, m, c, g in the same way.


4.5 Choose "Use nano C Library"

Open Configuration in CoIDE and in Link tab:
In Options area, choose "Use nano C Library". This can reduce the size of your
program.


-------------------------------
5 Rename main.c

Rename main.c file in your project to other name like userMain.cpp.
Remember to end with .cpp


-------------------------------
6 Include "Arduino.h"
In the userMain.cpp add:"#include "Arduino.h""


-------------------------------
7 Done!
Now you can use Arduino in Arm MCU.
Add your code in userMain.cpp.


------------------------------------------------------------------------------
Difference between MegaMind and Arduino language
------------------------------------------------------------------------------

1.
In order to applied to more Arm MCU, MegaMind use two parameters to describe
pin.One is the port name, another is pin number.
Example:

In Arduino:
pinMode(8, OUTPUT);
digitalWrite(8, HIGH);

In MegaMind:
pinMode(PORTA, 8, OUTPUT);
digitalWrite(PORTA, 8 ,HIGH);

Usually there are 16 pins in one port.
PORTA,PORTB,PORTC...

One exception is analogRead(). MegaMind Still use A0,A1... as pin number.

2.
analogWrite() accept pwm value between 0~100 while in Arduino it's 0~255.


------------------------------------------------------------------------------
Use MegaMind on other Arm MCU
------------------------------------------------------------------------------

I have tested MegaMind lib on STM32F103RBT6. To Use MegaMind on different Arm 
MCU, THEORETICALLY you only need to modify variant.h and variant.cpp which 
define details of pins in different Arm MCU. Please tell me if you can across
any problems.


------------------------------------------------------------------------------
Contact Me
------------------------------------------------------------------------------
Email:andersonby@163.com
