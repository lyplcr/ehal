#ifndef UART0_H
#define UART0_H
#include <stdio.h>
#include <avr/io.h>
#include <dev/cpu0.h>
#include <dev/gpio2.h>
#include <core/cbuf.h>

extern struct cbuf uart0_rxq;

static inline int uart0_ctor(uint32_t baud, uint8_t bits, uint8_t par, uint8_t stop)
{
	// 1) setup pins.
	gpio2_ctor();
	gpio2_set_dir(P1|P0, P1); /* P1 - in, P0 - out */
	// 2) baud rate
	UBRR0 = cpu0_freq() / (16L * baud) - 1;
	// 3) 8n1 
	UCSR0C = (3<<UCSZ00);
	// 4) enable TX & RX & RX_IRQ.
	UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) ;
	return 0;
}

static inline void uart0_putchar(int ch)
{
	/* wait for a slot in UDR. */
	while (!(UCSR0A & (1<<UDRE0)))
		;
	UDR0 = (uint8_t)ch;
}

static inline int uart0_getchar(void)
{
	if (cbuf_isempty(&uart0_rxq))
		return EOF;
	return (uint8_t)cbuf_get(&uart0_rxq);
}

#endif /* UART0_H */
