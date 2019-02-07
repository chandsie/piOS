#ifndef FONT_H
#define FONT_H

#include <stdint.h>

#define GLYPH_HEIGHT   (16)
#define GLYPH_WIDTH    (8)
#define CHAR_TRACKING  (2)
#define CHAR_SPACING   (2)
#define CHAR_WIDTH     (GLYPH_WIDTH + CHAR_TRACKING)
#define CHAR_HEIGHT    (GLYPH_HEIGHT + CHAR_SPACING)

const uint8_t * getCharBitmap(char c);

#endif // FONT_H
