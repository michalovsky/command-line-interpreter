#include "usart.h"

void USART_UnitTest(void)
{
  size_t i;
  uint32_t checksum;
	char c;

	// initialize the usart
	USART_Init();

	while (1) {
		// reset variables
		i = 0;
		checksum = 0;

		// wait for 10kB of data
		while (i < 10*1024) {
			if (USART_GetChar(&c)) {
				// if character has been received, calculate the sum
				checksum += c;
				i++;
			} else {
				// delay - this delay introduces the 'tricky' part in the test
				// do not modify it!
				volatile int j;
        for (j=0; j < 10000; j++) {
					;
				}
			}
		}
		// after receiving 10kB of data, send out the checksum
		USART_WriteData(&checksum, 4);
	}
}
