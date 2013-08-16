OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
/* Internal Memory Map*/
MEMORY
{
	rom (rx)  : ORIGIN = 0x08000000, LENGTH = 0x00020000
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00005000
}

_eram = 0x20000000 + 0x00005000;
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
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > rom
    
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > rom
    __exidx_end = .;
    
    . = ALIGN(4); 
    _etext = .;
    _sidata = .; 
    		
    .data : AT (_etext) 
    { 
        _sdata = .; 
        *(.data .data.*) 
        . = ALIGN(4); 
        _edata = . ;
    } > ram

    /* .bss section which is used for uninitialized data */ 
    .bss (NOLOAD) : 
    { 
        _sbss = . ; 
        *(.bss .bss.*) 
        *(COMMON) 
        . = ALIGN(4); 
        _ebss = . ; 
    } > ram
    
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