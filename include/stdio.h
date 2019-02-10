#ifndef STDIO_H
#define STDIO_H

#include <graphics.h>

typedef struct {
    uint32_t x_offset;
    uint32_t y_offset;
    const color_t * background;
    const color_t * foreground;
} console_info_t;

void puts(const char* str);
void putc(char c);

#endif // STDIO_H
