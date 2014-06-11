#include <dev/uart0.h>

/* This does not require a lock for (1 producer & 1 consumer) */
CBUF(uart0_rxq, 4);

ISR(USART_RX_vect) {
	uint8_t ch = UDR0;
	cbuf_put(&uart0_rxq, ch);
	/* job_schedule() to handle a terminal emulator, xmodem, etc... */
}
