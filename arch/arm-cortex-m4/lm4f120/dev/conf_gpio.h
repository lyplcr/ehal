#ifndef GPIO_BASE_H
#define GPIO_BASE_H

#define GPIO0_NVIC_ENTRY 0
#define GPIO1_NVIC_ENTRY 1
#define GPIO2_NVIC_ENTRY 2
#define GPIO3_NVIC_ENTRY 3
#define GPIO4_NVIC_ENTRY 4
#define GPIO5_NVIC_ENTRY 30

typedef uint8_t gpio_mask;

#define gpio_pctl_mask(pin)   ((0x0F)  << ((pin)<<2))
#define gpio_pctl_entry(pin, value) ((value) << ((pin)<<2))

#endif /* GPIO_BASE_H */
