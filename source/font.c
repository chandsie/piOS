#include <font.h>

// Font Bitmaps
// Copyright 2019 Quinn McElroy - Released under same terms as software
const uint8_t char_ERR[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_SPACE[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_A[] = {0x18, 0x18, 0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0xFF, 0xC3, 0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_B[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_C[] = {0x3C, 0x7E, 0x66, 0x62, 0xC0, 0xC0, 0x80, 0x80, 0x81, 0xE7, 0x7E, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_D[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_E[] = {0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xC0, 0xC0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_F[] = {0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_G[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_H[] = {0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_I[] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_J[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_K[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_L[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_M[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_N[] = {0xC1, 0xC1, 0xC1, 0xE1, 0xE1, 0xF1, 0xD1, 0xD9, 0xCD, 0xC5, 0xC7, 0xC3, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_O[] = {0x3C, 0x7E, 0x66, 0x66, 0xC3, 0xC3, 0x81, 0x81, 0x81, 0xE7, 0x7E, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_P[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_Q[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_R[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_S[] = {0x3C, 0x7F, 0x43, 0xC1, 0xC0, 0xC0, 0xE0, 0x7E, 0x03, 0xC3, 0xF7, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_T[] = {0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_U[] = {0x42, 0x42, 0x42, 0xC3, 0xC3, 0xC3, 0x81, 0x81, 0x81, 0xC3, 0x7E, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_V[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_W[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_X[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_Y[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_Z[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_a[] = {0x18, 0x18, 0x3C, 0x3C, 0x66, 0x66, 0x66, 0x66, 0xFF, 0xC3, 0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_b[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_c[] = {0x3C, 0x7E, 0x66, 0x62, 0xC0, 0xC0, 0x80, 0x80, 0x81, 0xE7, 0x7E, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_d[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_e[] = {0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xC0, 0xC0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_f[] = {0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_g[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_h[] = {0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_i[] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_j[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_k[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_l[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_m[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_n[] = {0xC1, 0xC1, 0xC1, 0xE1, 0xE1, 0xF1, 0xD1, 0xD9, 0xCD, 0xC5, 0xC7, 0xC3, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_o[] = {0x3C, 0x7E, 0x66, 0x66, 0xC3, 0xC3, 0x81, 0x81, 0x81, 0xE7, 0x7E, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_p[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_q[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_r[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_s[] = {0x3C, 0x7F, 0x43, 0xC1, 0xC0, 0xC0, 0xE0, 0x7E, 0x03, 0xC3, 0xF7, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_t[] = {0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_u[] = {0x42, 0x42, 0x42, 0xC3, 0xC3, 0xC3, 0x81, 0x81, 0x81, 0xC3, 0x7E, 0x3C, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_v[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_w[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_x[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_y[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
const uint8_t char_z[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
// End Copyright 2019 Quinn McElroy

const uint8_t * getCharBitmap(char c) {
    switch(c) {
        case 'A':
            return char_A;
        case 'B':
            return char_B;
        case 'C':
            return char_C;
        case 'D':
            return char_D;
        case 'E':
            return char_E;
        case 'F':
            return char_F;
        case 'G':
            return char_G;
        case 'H':
            return char_H;
        case 'I':
            return char_I;
        case 'J':
            return char_J;
        case 'K':
            return char_K;
        case 'L':
            return char_L;
        case 'M':
            return char_M;
        case 'N':
            return char_N;
        case 'O':
            return char_O;
        case 'P':
            return char_P;
        case 'Q':
            return char_Q;
        case 'R':
            return char_R;
        case 'S':
            return char_S;
        case 'T':
            return char_T;
        case 'U':
            return char_U;
        case 'V':
            return char_V;
        case 'W':
            return char_W;
        case 'X':
            return char_X;
        case 'Y':
            return char_Y;
        case 'Z':
            return char_Z;
        case 'a':
            return char_a;
        case 'b':
            return char_b;
        case 'c':
            return char_c;
        case 'd':
            return char_d;
        case 'e':
            return char_e;
        case 'f':
            return char_f;
        case 'g':
            return char_g;
        case 'h':
            return char_h;
        case 'i':
            return char_i;
        case 'j':
            return char_j;
        case 'k':
            return char_k;
        case 'l':
            return char_l;
        case 'm':
            return char_m;
        case 'n':
            return char_n;
        case 'o':
            return char_o;
        case 'p':
            return char_p;
        case 'q':
            return char_q;
        case 'r':
            return char_r;
        case 's':
            return char_s;
        case 't':
            return char_t;
        case 'u':
            return char_u;
        case 'v':
            return char_v;
        case 'w':
            return char_w;
        case 'x':
            return char_x;
        case 'y':
            return char_y;
        case 'z':
            return char_z;
        case ' ':
            return char_SPACE;
        default:
            return char_ERR;
    }
}
