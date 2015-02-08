ENTRY(reset_irq_handler);

MEMORY {
	flash (rx) : ORIGIN = 0x08000000, LENGTH = 256K
	sram (rwx) : ORIGIN = 0x20000000, LENGTH = 48K
}

SECTIONS {
	.text : {
		KEEP(*(.isr_vector))
		*(.text*)
		*(.rodata*)
	} > flash
	.data : {
		*(vtable)
		*(.data*)
	} > sram AT > flash
	.bss  : {
		*( .bss*)
	} > sram

	.stack : {
		_stack_top = _sdata + 48K;
	}
}

_stext = ADDR(.text);
_etext = _stext + SIZEOF(.text);

_sdata = ADDR(.data);
_edata = _sdata + SIZEOF(.data);

_sbss  = ADDR(.bss);
_ebss  = _sbss  + SIZEOF(.bss);
