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
	int i, count = 0;
	int Delay_Value = 3000000;

	printf("This is a simple binary counter displayed on LEDs.\n");

	while(1) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, count);
		// Delay for sometime
		for (i = 0; i < Delay_Value; i++) {
			;
		}
		count++;
	}
	return 0;
}


