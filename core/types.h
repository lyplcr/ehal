#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>
#define HWPTR(x) ((volatile uint32_t *)x)
#define HWREG(x) (*HWPTR(x))

#endif /* TYPES_H */
