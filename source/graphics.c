#include <graphics.h>

static const color_t white = {.red = 0xFF, .green = 0xFF, .blue = 0xFF};
static const color_t black;

static fb_info_t fb_info  __attribute__((aligned(16)));
static graphics_info_t g_info = {.background=&black, .foreground=&white};

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

void drawPixel(int x, int y, const color_t * pixel) {
    uint8_t * target = fb_info.buff_addr + (y * fb_info.pitch) + (x * PIXEL_BYTES);

    *(target) = pixel->blue;
    *(target + 1) = pixel->green;
    *(target + 2) = pixel->red;
}

void drawChar(char c) {
    const uint8_t * bitmap = getCharBitmap(c);
    int x_offset = g_info.column_index * CHAR_WIDTH;
    int y_offset = g_info.row_index * CHAR_HEIGHT;

    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 8; x++) {
            if (bitmap[y] & (1 << x)) {
                drawPixel(8 - x - 1 + x_offset , y + y_offset, g_info.foreground);
            } else {
                drawPixel(8 - x - 1 + x_offset , y + y_offset, g_info.background);
            }
        }
    }

    g_info.column_index++;
    if (g_info.column_index == 10) {
        g_info.column_index = 0;
        g_info.row_index++;
    }
}
