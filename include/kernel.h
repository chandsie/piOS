#ifndef KERNEL_H
#define KERNEL_H

enum {
    IO_BASE       = 0x20000000,
    GPIO_BASE     = (IO_BASE + 0x00200000),
    MAIL_BASE     = (IO_BASE + 0xB880),

    BUS_ADDR_BASE = 0x40000000,
};

#endif // KERNEL_H
