#include <stdint.h>
#include "kernel.h"

/* "New" way of doing things that isn't deprecated - but maybe only valid on newer hardware
typedef enum {
    ALLOCATE_BUFFER =    0x00040001;
    BLANK_SCREEN    =    0x00040002;
    RELEASE_BUFFER  =    0x00048001;
} property_tag_t;

typedef struct {
    void * buff_addr;
    uint32_t buff_size;
} alloc_buff_resp_t;
*/

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

typedef struct {
    uint32_t reserved: 30;
    uint8_t empty: 1;
    uint8_t full: 1;
} mail_status_t;


static fb_init_t fb_init __attribute__((aligned(16)));

void mailbox0_send(uint32_t data) {
    while((*(mail_status_t*)((MAIL_BASE + 0x18))).full);

    *((uint32_t*)MAIL_BASE) = data;
}

void framebufferInit() {
    // Fill out non-zero properties of fb init message
    fb_init.width = 640;
    fb_init.height = 480;
    fb_init.virtual_width = 640;
    fb_init.virtual_height = 480;
    fb_init.depth = 24;

    // Send 28 MSBs of message addr and channel selection (1 on MB 0) as data
    uint32_t requestData = BUS_ADDR_BASE | (uint32_t)&fb_init | 0x1;
    mailbox0_send(requestData);
}

inline void GPIO16Init() {
    // Set GPIO Ping 16 to output mode
    volatile uint32_t* fsel = (volatile uint32_t*)(GPIO_BASE + 0x4);
    *fsel = (1 << 18);
}

inline void GPIO16High() {
    volatile uint32_t* gpio_out_clear = (volatile uint32_t*)(GPIO_BASE + 0x28);
    *gpio_out_clear = (1 << 16);
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags) {
    // Unused for now
    (void) r0;
    (void) r1;
    (void) atags;

    GPIO16Init();
    GPIO16High();
    framebufferInit();

    return;
}

