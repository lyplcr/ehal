#ifndef CPU_H
#define CPU_H
#include <stdint.h>

#define CPU_BOOT_POWER_UP 0
#define CPU_BOOT_SOFT     1
#define CPU_BOOT_WDT      2
#define CPU_BOOT_HARD     3

struct cpu_interface {
	/** @brief Initializes the CPU/System
	 *
	 * initializes clocks, PLL, enable global IRQs
	 *
	 * @note Must be initialized before any other of the system. */
	void    (*ctor)        (void);

	/** @brief Terminates the module causing the CPU to halt. */
	void    (*dtor)        (void);

	/** @brief Halt the CPU execution recoverable only by reset. */
	void    (*halt)        (void);

	/** @brief Enter a critical section.
	 *
	 * This disables the interrupts globally so that only a single threads
	 * of execution can ocour. This call has a recursive semantic so that
	 * two calls to enter_ and one call to leave_ will still leave you in a
	 * critical section. Only by matching the number of calls of enter_ and
	 * leave_ that your system is back to normal operation.
	 *
	 * @note recursive up to 255 calls. (implement with uint8_t. */
	void    (*enter_critical)(void);

	/** @brief Leave a critical section. @ref enter_critical.
	 *
	 * This is the matching function of enter_critical. To leave more
	 * critical sections than to enter is considered a BUG. Doing so will
	 * cause undefined behaviour. The implementation is advised to assert
	 * and halt in its ocurrence in debug builds and handle it in any
	 * fasion during release builds (-DNDEBUG). */
	void    (*leave_critical)(void);

	/** @brief Get the Running frequency of the CPU.
	 *
	 * This function returns the expected running frequency based on the
	 * crystall, PLL, or internal oscilator. It does not correct for
	 * imprecise clock sources. */
	uint32_t(*freq)        (void);

	/** @brief Causes a reset on the CPU.
	 *
	 * This may not put peripherals in their default state. */
	void    (*reset)       (void);

	/** @brief Wait at least ms (micro seconds).
	 *
	 * Convenient for driver implementations that require small delays.
	 * This function waits at least the amount specified and does not
	 * correct for interruption latencies. */
	void    (*busywait_us) (uint16_t us); /**< at least this. */

	/** @brief Retrieve the cause of boot. */
	uint8_t (*boot_cause)  (void);
};

#endif /* CPU_H */
