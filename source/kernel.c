#include <stdint.h>
#include "kernel.h"
inline void GPIO16Init() {
    // Set GPIO Ping 16 to output mode
    volatile uint32_t* fsel = (volatile uint32_t*)(GPIO_BASE + 0x4);
    *fsel = (1 << 18);
}

inline void GPIO16High() {
    volatile uint32_t* gpio_out_clear = (volatile uint32_t*)(GPIO_BASE + 0x28);
    *gpio_out_clear = (1 << 16);
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags) {
    // Unused for now
    (void) r0;
    (void) r1;
    (void) atags;

    GPIO16Init();
    GPIO16High();

    return;
}
