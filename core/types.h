#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>
#define HWPTR(x) ((volatile uint32_t * const)(x))
#define HWREG(x) (*HWPTR(x))

#define HWPTR16(x) ((volatile uint16_t * const)(x))
#define HWREG16(x) (*HWPTR16(x))

#define HWPTR8(x) ((volatile uint8_t * const)(x))
#define HWREG8(x) (*HWPTR8(x))

#endif /* TYPES_H */
