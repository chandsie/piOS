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

#define MAIL_STATUS (volatile mail_status_t *)(MAIL_BASE + 0x38)
// ^ The constant *should* be 0x38 for the send but the working kernel uses 0x18.. idk wtf
#define MAIL_READ_STATUS (volatile mail_status_t *)(MAIL_BASE + 0x18)
#define MAIL_WRITE  (volatile uint32_t *)(MAIL_BASE + 0x20)
#define MAIL_READ   (volatile uint32_t *)(MAIL_BASE + 0x00)

void mailbox0_send(uint32_t data) {
    // Wait for mailbox to be not full
    mail_status_t status;
    do {
        status = *MAIL_STATUS; 
    } while (status.full);

    *MAIL_WRITE = data;
}

uint32_t mailbox0_receive(int channel) {
    uint32_t ret;
    int msg_channel;
    mail_status_t status;
    // Wait for mailbox to contain a message for the specified channel
    do {
        // Wait for mailbox to be not empty
        do {
            status = *MAIL_READ_STATUS;
        } while (status.empty);

        ret = *MAIL_READ;
        msg_channel = ret & 0xF;
    } while(msg_channel != channel);

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
    uint32_t request = BUS_ADDR_BASE | ((uint32_t)(&fb_init)) | 0x1;
    uint32_t response;

    do {
        mailbox0_send(request);
        response = mailbox0_receive(1);
    } while (!response);
    if (fb_init.buff_addr) {
        GPIO16On();
    }

    for (uint32_t i = 0; i < fb_init.buff_size ; i++) {
        *((uint8_t *)(fb_init.buff_addr + i)) = 0xFF;
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

