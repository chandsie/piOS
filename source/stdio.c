#include <stdio.h>

void puts(const char* str) {
    while(*str) {
        putc(*str++);
    }
}

void putc(char c) {
    drawChar(c);
}
