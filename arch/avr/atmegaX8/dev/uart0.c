#include <dev/uart0.h>

/* This does not require a lock for (1 producer & 1 consumer) */

uint8_t uart0_rx_b[1<<4];
volatile RingBuf uart0_rx_rb = RINGBUF_INIT(uart0_rx_b, sizeof(uart0_rx_b));

__attribute__((weak))
void uart0_rx_irq(uint8_t ch)
{
	ringbuf_put(ch, &uart0_rx_rb);
}

ISR(USART_RX_vect) {
	uint8_t ch = UDR0;
	uart0_rx_irq(ch);
}
