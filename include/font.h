#ifndef FONT_H
#define FONT_H

#include <stdint.h>

#define CHAR_HEIGHT   16
#define GLYPH_WIDTH    8
#define CHAR_TRACKING  2
#define CHAR_WIDTH     (CHAR_TRACKING + GLYPH_WIDTH)
#define LINE_HEIGHT    (CHAR_HEIGHT + 2)

const uint8_t * getCharBitmap(char c);

#endif // FONT_H
