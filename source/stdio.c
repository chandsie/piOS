#include <stdio.h>

static const color_t white = {.red = 0xFF, .green = 0xFF, .blue = 0xFF};
static const color_t black;

static console_info_t c_info = {.background=&black, .foreground=&white};

void putNewline() {
    c_info.x_offset = 0;
    c_info.y_offset += CHAR_HEIGHT;
    // TODO(2/9/2019): move contents up instead of clearing screen?
    // If the next character would fall off the screen edge, start again from the top
    if (c_info.y_offset + CHAR_HEIGHT >= SCREEN_HEIGHT) {
       clearFrame();
       c_info.y_offset = 0;
    }
}

void puts(const char* str) {
    while(*str) {
        putc(*str++);
    }
    putNewline();
}

void putc(char c) {
    if (c == '\n') {
        putNewline();
        return;
    }

    drawChar(c_info.x_offset, c_info.y_offset, c_info.foreground, c_info.background, c);

    c_info.x_offset += CHAR_WIDTH;

    // If the next character would fall off the screen edge, wrap to next line
    if (c_info.x_offset + CHAR_WIDTH >= SCREEN_WIDTH) {
        putNewline();
    }
}
