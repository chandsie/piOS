#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <font.h>
#include <mailbox.h>

#define COLORDEPTH 24
#define PIXEL_BYTES (COLORDEPTH / 8)

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} color_t;


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

void framebufferInit();
void clearFrame();
void drawPixel(int x, int y, const color_t * color);
void drawChar(uint32_t x, uint32_t y, const color_t * foreground, const color_t * background, char c);

#endif // GRAPHICS_H
