#include <gpio.h>
#include <stdint.h>
#include <kernel.h>

void GPIO16Init() {
    // Set GPIO Ping 16 to output mode
    volatile uint32_t* fsel = (volatile uint32_t*)(GPIO_BASE + 0x4);
    *fsel = (1 << 18);
}

void GPIO16On() {
    volatile uint32_t* gpio_out_clear = (volatile uint32_t*)(GPIO_BASE + 0x28);
    *gpio_out_clear = (1 << 16);
}

void GPIO16Off() {
    volatile uint32_t* gpio_out_clear = (volatile uint32_t*)(GPIO_BASE + 0x1C);
    *gpio_out_clear = (1 << 16);
}

