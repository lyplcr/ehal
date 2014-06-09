#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#define UART_115200_8N1 155200, 8, 'n', 1

/* WIP: Still missing the definition for an assync interface. */
struct uart_interface {
	int  (*ctor)(uint32_t freq, uint8_t bits, uint8_t par, uint8_t stop);
	void (*dtor)(void);

	int  (*getc)(void);
	int  (*putc)(void);
};

#endif /* UART_INTERFACE_H */
