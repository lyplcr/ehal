#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H
#include <stdbool.h>
#include <stdint.h>

struct uart_conf {
	uint32_t baud;
	bool par, stop;
	uint8_t bits;
};

/** Universal Assynchronous Transmiter Receiver.
 *
 * putchar to write bytes.
 * getchar to read bytes.
 */
typedef struct {
	/** Initialize the uart and its pins for use.
	 * @param baud - baud rate for the comunication.
	 * @param bits - bits of content (usually 8)
	 * @param par  - parity 'o':odd, 'e':even, 'n':none.
	 * @param stop - 1 or 2 stop bits.
	 *
	 * An example for 115200 8N1:
	 * @code
	 *	uart0_ctor(115200, 8, 'n', 1);
	 * @endcode */
	int  (*ctor)(	uint32_t freq,
			uint32_t baud,
			uint8_t bits,
			uint8_t par,
			uint8_t stop);

	/** Terminates the uart and set the GPIOs to their original value. */
	void (*dtor)(void);

	/* buffered non blocking API.
	 *
	 * @return EOF on failure.
	 *
	 * TX empty queue will schedule a job for user computation.
	 * @note Implement me with cbuf.h */
	int (*putchar)(int ch);

	/** Non blocking getchar.
	 *
	 * Gets a byte from the uart buffer.
	 * bytes in RX queue will schedule a job for user computation.
	 *
	 * @return EOF on failure.
	 *
	 * @note Implement me with cbuf.h */
	int (*getchar)(void);
} IUart;

/** Each uart (uart0, uart1, ...) IRQ is defined as a weak symbol with the below
 * interfaces. Both functions can be "overloaded" and will run in IRQ context,
 * So the Non-block very fast execution rules apply to them. */
void uart_tx_irq(volatile uint8_t *ch);

#define UART_RX_OK     0
#define UART_RX_EPAR   1
#define UART_RX_EFRAME 2
void uart_rx_irq(uint8_t ch, uint8_t err);

#endif /* UART_INTERFACE_H */
