#include <mailbox.h>

uint32_t mailboxRead(uint8_t channel) {
    uint32_t msg;

    do {
        // Spin-wait until mailbox0 is not empty
        while(MAIL_0_STATUS->empty);

        msg = *MAIL_0_DATA;
    } while((msg & 0xF) != channel);

    return msg;
}


void mailboxWrite(uint32_t msg) {
    // Spin-wait until mailbox1 is not full
    while(MAIL_1_STATUS->full);

    *MAIL_1_DATA = msg;
}

