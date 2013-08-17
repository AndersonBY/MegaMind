To use C++ you need to do some modification.

------------------------------------------------------------------------------
1 Modify arm-gcc-link.ld file
------------------------------------------------------------------------------

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


------------------------------------------------------------------------------
2 Modify startup code
------------------------------------------------------------------------------

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


------------------------------------------------------------------------------
3 Choose CLibrary in Repository
------------------------------------------------------------------------------

Open Repository in CoIDE and choose C Library.


------------------------------------------------------------------------------
4 Add C++ library
------------------------------------------------------------------------------

Open Configuration in CoIDE and in Link tab:
Press Add in Linked Libraries and type stdc++, then press OK.
Add supc++, m, c, g in the same way.


------------------------------------------------------------------------------
5 Choose "Use nano C Library"
------------------------------------------------------------------------------

Open Configuration in CoIDE and in Link tab:
In Options area, choose "Use nano C Library". This can reduce the size of your
program.