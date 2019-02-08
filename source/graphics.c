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
}

void clearFrame() {
    for (uint32_t i = 0; i < fb_info.buff_size ; i++) {
        *(fb_info.buff_addr + i) = 0x00;
    }
}

void drawPixel(int x, int y, const color_t * color) {
    uint8_t * target = fb_info.buff_addr + (y * fb_info.pitch) + (x * PIXEL_BYTES);

    *(target) = color->blue;
    *(target + 1) = color->green;
    *(target + 2) = color->red;
}

void drawChar(
        uint32_t x,
        uint32_t y,
        const color_t * foreground,
        const color_t * background,
        char c) {
    const uint8_t * bitmap = getCharBitmap(c);

    for (int col_index = 0; col_index < 16; col_index++) {
        for (int row_index = 0; row_index < 8; row_index++) {
            if (bitmap[col_index] & (1 << row_index)) {
                drawPixel(8 - row_index - 1 + x, col_index + y, foreground);
            } else {
                drawPixel(8 - row_index - 1 + x, col_index + y, background);
            }
        }
    }
}
