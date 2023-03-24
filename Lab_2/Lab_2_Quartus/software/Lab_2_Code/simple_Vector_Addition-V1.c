// COMPSYS 701 - (March 2022)
 
#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "sys/alt_timestamp.h"

int main()
{
	// Add two vectors A and B
	unsigned char A[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
				 		   0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
				 		   0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
				 		   0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};

	unsigned char B[32] = {0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
				 		   0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
				 		   0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
				 		   0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F};

	unsigned char C[32];

	unsigned int timestamp_start_time, timestamp_end_time;
	unsigned int timestamp_overhead_time, T1, T2;
	int count = 0;
	
	printf("Performance measurement using high-resolution timer for a simple example for vector addition ... \n");
	printf("\nDisplay 11001100 on LEDs\n"); 
	count = 0xCC;
	IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, count);
		
	if (alt_timestamp_start() < 0) {
	    printf ("No timestamp device is available.\n");
	}
	else
	{
		// Vector Addition 
	    printf("\n*** Vector Addition C[i] = A[i] + B[i] *** \n");
		// Sample the timestamp timer (for start time) 
		timestamp_start_time = alt_timestamp();
		// Vector addition using SIMD_ADD custom instruction 
		for (int i=0; i<32; i=i+4)
		{
			// use the SIMD_ADD custom instruction
			C[i] = ALT_CI_SIMD_ADD_0(A[i], B[i]);
		}

		// Sample the timestamp timer (for end time)
	    timestamp_end_time = alt_timestamp();

		// Measure the time overhead to read the timestamp timer by subsequently
		// calling alt_timestamp() back to back.
		T1 = alt_timestamp();
		T2 = alt_timestamp();
		timestamp_overhead_time = T2 - T1;
		
		printf("\n*** Vector Addition Completed ***\n");
		for (int i=0; i<32; i++) {
			printf(" C[%d] = %d, ", i, C[i]);
		}
		printf("\n\n");
		
		// Print-out the Timestamp interval timer peripheral measurements.
		printf("timestamp_start_time = %u ticks\n",
					           (unsigned int) (timestamp_start_time));
		printf("timestamp_end_time = %u ticks\n\n",
							           (unsigned int) (timestamp_end_time));
		printf("timestamp measurement = %u ticks\n",
			           (unsigned int) (timestamp_end_time - timestamp_start_time));
		printf("timestamp measurement overhead = %u ticks\n",
			           (unsigned int) (timestamp_overhead_time));
		printf("Actual time  = %u ticks\n",
			           (unsigned int) ((timestamp_end_time - timestamp_start_time) -
			           timestamp_overhead_time));
		printf("Timestamp timer frequency = %u\n",
			           (unsigned int)alt_timestamp_freq());
	}
	
	printf("\nThis program was completed.\n");

	return 0;
}
