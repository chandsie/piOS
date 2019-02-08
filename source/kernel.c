#include <kernel.h>

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags) {
    // Unused for now
    (void) r0;
    (void) r1;
    (void) atags;

    GPIO16Init();
    GPIO16On();
    framebufferInit();
    puts("Welcome to piOS!");

    return;
}

