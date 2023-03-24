/*
 * my_binary_leds.c
 *
 *  Created on: March 2023
 *      Author: Morteza
 */

#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"

int main()
{
	int i, tens, ones, count = 0;
	int Delay_Value = 300000;
	int segments[] = {
			0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111};

	printf("Setting UPI numbers\n");
	// Set Left most 7-Seg to UPI, 92
	IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT_4_BASE, ~segments[9]);
	IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT_3_BASE, ~segments[2]);


	while(1) {
		// calcualte digits
		ones = count % 10;
		tens = count / 10;


		// set 7-Segs to digits
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT_2_BASE, ~segments[tens]);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT_1_BASE, ~segments[ones]);

		// Set LEDs to binary number
		IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, count);

		// Delay for sometime
		for (i = 0; i < Delay_Value; i++) {
			;
		}

		// increment
		if (count >= 99){
			count = 0;
		} else {
			count++;
		}

	}
	return 0;
}


