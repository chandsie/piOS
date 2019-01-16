.section .init
.globl _start
_start:
    b main

.section .text
main:
    ldr r0,=0x20200000
    # Enable 16th GPIO pin
    mov r1,#1
    lsl r1,#18
    str r1,[r0,#4]

    mov r1,#1
    lsl r1,#16

    loop$:
    # Turn off pin 16
    str r1,[r0,#40]

    # Wait a little
    mov r2,#0x3F0000
    wait1$:
    sub r2,#1
    cmp r2,#0
    bne wait1$

    # Turn on pin 16
    str r1,[r0,#28]

    # Wait a little
    mov r2,#0x3F0000
    wait2$:
    sub r2,#1
    cmp r2,#0
    bne wait2$

    b loop$

