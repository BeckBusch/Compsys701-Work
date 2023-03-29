#include <stdio.h>
#include "system.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_timestamp.h" 
#include "sys/alt_irq.h"
#include <unistd.h>    // to use usleep function

volatile int edge_capture = 0;

static void handle_buttons_interrupts(void* context) {
    //set up interrupt output holder
    volatile int* edge_capture_ptr = (volatile int*)context;
    // capture interrupt
    *edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE);
    // reset interrupts output
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE, 0);
    // delay ISR completion
    IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE);
}

static void init_buttons_interrupt() {
    // set up interrupt flag output
    void* edge_capture_ptr = (void*)&edge_capture;
    // mask out key 1 and 0
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTON_PIO_BASE, 0b1100);// KEY2 and KEY3
    // reset interrupts
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE, 0);
    // register interrupt handler
    alt_ic_isr_register(BUTTON_PIO_IRQ_INTERRUPT_CONTROLLER_ID, BUTTON_PIO_IRQ, handle_buttons_interrupts, edge_capture_ptr, 0x0);
}

int main() {
    init_buttons_interrupt();

    int i, tens, ones, count = 0;
    int counting = 1;
    int segments[] = {
            0b00111111, // 0
            0b00000110, // 1
            0b01011011, // 2
            0b01001111, // 3
            0b01100110, // 4
            0b01101101, // 5
            0b01111101, // 6
            0b00000111, // 7
            0b01111111, // 8
            0b01101111, // 9
            0b01110111, // A
            0b01111111, // B
            0b00111001, // C
            0b00111111, // D
            0b01111001, // E
            0b01110001}; // F

    while (1) {
        // read switch input and generate input number
        int switches = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_0_7_BASE);
        switches = switches & 0b00001111;
        switches = switches | 0b11110000;

        // check interrupts and make required changes
        if (edge_capture != 0) {
            if (edge_capture == 0x4) {
                count = switches;
                printf("Initial value is: %d\n", switches);
            }
            if (edge_capture == 0x8) {
                counting = !counting;
            }
            edge_capture = 0;
        }

        // format count number for display
        ones = count % 16;
        tens = (count / 16) % 16;

        // display on leds, 7-seg, and console
        IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT_2_BASE, ~segments[tens]);
        IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT_1_BASE, ~segments[ones]);
        IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, count);

        // wait
        usleep(100000);

        // increment counter
        if (count >= 0xFF) {
            count = 0;
        } else if (counting) {
            count++;
        }

    }
    return 0;
}

