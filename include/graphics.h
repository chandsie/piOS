#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <kernel.h>
#include <mailbox.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t virtual_width;
    uint32_t virtual_height;
    uint32_t pitch;
    uint32_t depth;
    uint32_t virtual_offset_x;
    uint32_t virtual_offset_y;
    void * buff_addr;
    uint32_t buff_size;
} fb_init_t;

void framebufferInit();

fb_init_t fb_init __attribute__((aligned(16)));

#endif // GRAPHICS_H
