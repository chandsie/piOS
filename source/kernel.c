#include <stdint.h>
#include <kernel.h>
#include <gpio.h>

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


fb_init_t fb_init __attribute__((aligned(16)));

void mailbox0_send(uint32_t data) {
    // Wait for mailbox to be not full
    while((*(volatile mail_status_t*)((MAIL_BASE + 0x18))).full);

    *((volatile uint32_t*)(MAIL_BASE + 0x20)) = data;
    GPIO16On();
}

uint32_t mailbox0_receive() {
    // Wait for mailbox to be not empty
    while((*(volatile mail_status_t*)((MAIL_BASE + 0x18))).empty);

    uint32_t ret = *((volatile uint32_t*)MAIL_BASE);
    GPIO16Off();

    return ret;
}

void framebufferInit() {
    // Fill out non-zero properties of fb init message
    fb_init.width = 640;
    fb_init.height = 480;
    fb_init.virtual_width = 640;
    fb_init.virtual_height = 480;
    fb_init.depth = 24;

    // Send 28 MSBs of message addr and channel selection (1 on MB 0) as data
    uint32_t request = BUS_ADDR_BASE | (uint32_t)&fb_init | 0x1;
    uint32_t response;
    do {
        mailbox0_send(request);
        response = mailbox0_receive();
    } while (!(response >> 4) && (response & 0x1));
    GPIO16On();

    for (uint32_t i = 0; i < fb_init.buff_size ; i++) {
        *((uint8_t *)(fb_init.buff_addr + i)) = 0x00;
    }
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags) {
    // Unused for now
    (void) r0;
    (void) r1;
    (void) atags;

    GPIO16Init();
    GPIO16Off();
    framebufferInit();

    return;
}

