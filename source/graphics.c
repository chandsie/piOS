#include <graphics.h>

static fb_info_t fb_info  __attribute__((aligned(16)));

void framebufferInit() {
    // Fill out non-zero properties of fb init message
    fb_info.width = 800;
    fb_info.height = 480;
    fb_info.virtual_width = 800;
    fb_info.virtual_height = 480;
    fb_info.depth = 24;

    // Send 28 MSBs of message addr and channel selection (1 on MB 0) as data
    uint32_t request = BUS_ADDR_BASE | (uint32_t)&fb_info | 0x1;
    uint32_t response;
    do {
        mailboxWrite(request);
        response = mailboxRead(1);
    } while (!(response >> 4)); // TODO(2/2/19): verify that this can actually fail and 
                                //               remove if it can't

    // Ensure we initialize to a known clean state
    clearFrame();

    pixel_t red = {.red=0xFF};
    pixel_t green = {.green=0xFF};
    pixel_t blue = {.blue=0xFF};
    pixel_t * cur_pixel = &red;

    for (uint32_t x = 0; x < fb_info.width; x++) {
        for (uint32_t y = 0; y < fb_info.height; y++) {
            if (x % 30 == 0) {
                cur_pixel = &red;
            } else if (x % 30 == 10) {
                cur_pixel = &green;
            } else if (x % 30 == 20) {
                cur_pixel = &blue;
            }

            drawPixel(x, y, cur_pixel);
        }
    }

}

void clearFrame() {
    for (uint32_t i = 0; i < fb_info.buff_size ; i++) {
        *(fb_info.buff_addr + i) = 0x00;
    }
}

void drawPixel(uint32_t x, uint32_t y, const pixel_t * pixel) {
    uint8_t * target = fb_info.buff_addr + (y * fb_info.pitch) + (x * PIXEL_BYTES);

    *(target) = pixel->blue;
    *(target + 1) = pixel->green;
    *(target + 2) = pixel->red;
}
