.section ".init"

.global _start

/**
 * Subroutine _start - Set up stack and bss, and enter kernel
 * Inputs:   r0 -> 0x0
 *           r1 -> 0x0C42 ?? according to wiki.osdev
 *           r2 -> 0x0100 ATAGS location
 * Outputs:  None
 **/
_start:
    // Set stack to top of text section
    mov sp, #0x8000

    /* Clear out bss */
    // Get bss bounds
    ldr r4, =__bss_start
    ldr r5, =__bss_end
    // Initialize registers to zero
    mov r6, #0
    mov r7, #0
    mov r8, #0
    mov r9, #0
    b 2f

1:
    // Store zeroed registers to r4-r4+4, and set r4+=4
    stmia r4!, {r6-r9}

2:
    // If r4 < r5, jump back to 1
    cmp r4, r5
    blo 1b

    // Jump to kernel main
    bl kernel_main

    // Halt if kernel returns
halt:
    wfe
    b halt

