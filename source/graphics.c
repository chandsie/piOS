#include <graphics.h>

void framebufferInit() {
    // Fill out non-zero properties of fb init message
    fb_init.width = 640;
    fb_init.height = 480;
    fb_init.virtual_width = 640;
    fb_init.virtual_height = 480;
    fb_init.depth = 24;

    // Send 28 MSBs of message addr and channel selection (1 on MB 0) as data
    uint32_t request = BUS_ADDR_BASE | (uint32_t)&fb_init | 0x1;
    uint32_t response;
    do {
        mailboxWrite(request);
        response = mailboxRead(1);
    } while (!(response >> 4));

    for (uint32_t i = 0; i < fb_init.buff_size ; i++) {
        *((uint8_t *)(fb_init.buff_addr) + i) = 0xFF;
    }
}
