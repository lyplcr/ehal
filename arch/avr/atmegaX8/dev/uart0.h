#ifndef UART0_H
#define UART0_H
#include <stdio.h>
#include <avr/io.h>

#include <core/bm.h>
#include <core/ringbuf.h>

#include <dev/cpu0.h>
#include <dev/gpio2.h>

extern volatile RingBuf uart0_rx_rb;

static inline void uart0_ctor(uint32_t freq,
		uint32_t baud, uint8_t bits, uint8_t par, uint8_t stop)
{
	// 1) setup pins.
	gpio2_ctor();
	gpio2_set_dir(  P1 | P0,
			P1 |  0); /* in, out */
	// 2) baud rate
	UBRR0 = freq / (16L * baud) - 1;
	// 3) 8n1 
	UCSR0C = (3<<UCSZ00);
	// 4) enable TX & RX & RX_IRQ.
	UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) ;
}

static inline int uart0_put(int ch)
{
	/* wait for a slot in UDR. */
	bm_loop_until_clear(UCSR0A, 1<<UDRE0);
	UDR0 = ch;
	return ch;
}

static inline int uart0_get(void)
{
	return ringbuf_get(&uart0_rx_rb);
}

#endif /* UART0_H */
