ENTRY(_start)

SECTIONS {
    . = 0x8000;

	.text : {
        KEEP(*(.init))
		*(.text)
	}
    . = ALIGN(4096);

    __data_start = .;
	.data : {
		*(.data)
	}
    . = ALIGN(4096);
    __data_end = .;

    __bss_start = .;
	.bss : {
        bss = .;
		*(.bss)
	}
    . = ALIGN(4096);
    __bss_end = .;

/*    /DISCARD/ : {
//        *(.*)
//    }
*/
}
