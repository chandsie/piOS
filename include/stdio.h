#ifndef STDIO_H
#define STDIO_H

#include <graphics.h>

typedef struct {
    uint32_t row_index;
    uint32_t column_index;
    const color_t * background;
    const color_t * foreground;
} console_info_t;

void puts(const char* str);
void putc(char c);

#endif // STDIO_H
