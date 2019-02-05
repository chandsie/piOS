#ifndef MAILBOX_H
#define MAILBOX_H

#include <stdint.h>
#include <kernel.h>

// Mailbox 0 is only used for VC -> ARM communication
#define MAIL_0_STATUS ((volatile mail_status_t *)(MAIL_BASE + 0x18))
#define MAIL_0_DATA ((volatile uint32_t *)(MAIL_BASE + 0x00))

// Mailbox 1 is only used for ARM -> VC communication
#define MAIL_1_STATUS ((volatile mail_status_t *)(MAIL_BASE + 0x38))
#define MAIL_1_DATA ((volatile uint32_t *)(MAIL_BASE + 0x20))

typedef struct {
    uint32_t reserved: 30;
    uint8_t empty: 1;
    uint8_t full: 1;
} mail_status_t;

uint32_t mailboxRead(uint8_t channel);
void mailboxWrite(uint32_t msg);

#endif // MAILBOX_H
