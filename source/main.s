.section .init
.globl _start
_start:
    b main

.section .text
main:

    # set up the stack
    mov sp,#0x8000

    mov r0,#16
    mov r1,#0
    bl SetGpioFunction

    loop$: 
    mov r0,#16
    mov r1,#0
    bl SetGpio

//    ldr r0,=100000
//    bl Wait
//
//    // Turn on GPIO Pin 16
//    mov r0,#16
//    mov r1,#1
//    bl SetGpio
//
//    ldr r0,=100000
//    bl Wait

    b loop$
    
