#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <kernel.h>
#include <mailbox.h>

#define COLORDEPTH 24
#define PIXEL_BYTES (COLORDEPTH / 8)

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;


typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t virtual_width;
    uint32_t virtual_height;
    uint32_t pitch;
    uint32_t depth;
    uint32_t virtual_offset_x;
    uint32_t virtual_offset_y;
    uint8_t * buff_addr;
    uint32_t buff_size;
} fb_info_t;

typedef struct {
    uint32_t row_index;
    uint32_t column_index;
    const pixel_t * background;
    const pixel_t * foreground;
} graphics_info_t;

#define CHAR_HEIGHT   16
#define GLYPH_WIDTH    8
#define CHAR_TRACKING  2
#define CHAR_WIDTH     (CHAR_TRACKING + GLYPH_WIDTH)
#define LINE_HEIGHT    (CHAR_HEIGHT + 2)

void framebufferInit();
void clearFrame();
void drawPixel(int x, int y, const pixel_t * pixel);
void puts(const char * str);
void putc(char c);
const uint8_t * getCharBitmap(char c);

#endif // GRAPHICS_H
