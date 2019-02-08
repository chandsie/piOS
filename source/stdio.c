#include <stdio.h>

static const color_t white = {.red = 0xFF, .green = 0xFF, .blue = 0xFF};
static const color_t black;

static console_info_t c_info = {.background=&black, .foreground=&white};

void puts(const char* str) {
    while(*str) {
        putc(*str++);
    }
}

void putc(char c) {
    int x_offset = c_info.column_index * CHAR_WIDTH;
    int y_offset = c_info.row_index * CHAR_HEIGHT;

    drawChar(x_offset, y_offset, c_info.foreground, c_info.background, c);

    c_info.column_index++;
    if (c_info.column_index == 10) {
        c_info.column_index = 0;
        c_info.row_index++;
    }
}
