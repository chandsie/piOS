ENTRY(_start)

SECTIONS {
    . = 0x8000;

	.text : {
        KEEP(*(.init))
		*(.text)
	}

	.data : {
		*(.data)
	}

    __bss_start = .;
	.bss : {
        bss = .;
		*(.bss)
	}
    __bss_end = .;
}
