# mandatory
obj-y			+= cpu0.o

obj-$(CONFIG_DEV_GPIO0)	+= gpio0.o
obj-$(CONFIG_DEV_GPIO1)	+= gpio1.o
obj-$(CONFIG_DEV_GPIO2)	+= gpio2.o
obj-$(CONFIG_DEV_GPIO3)	+= gpio3.o
obj-$(CONFIG_DEV_GPIO4)	+= gpio4.o
obj-$(CONFIG_DEV_GPIO5)	+= gpio5.o

obj-$(CONFIG_DEV_SPI0)	+= spi0.o
obj-$(CONFIG_DEV_SPI1)	+= spi1.o
obj-$(CONFIG_DEV_SPI2)	+= spi2.o
obj-$(CONFIG_DEV_SPI3)	+= spi3.o

obj-$(CONFIG_DEV_UART0)	+= uart0.o
obj-$(CONFIG_DEV_UART1)	+= uart1.o
obj-$(CONFIG_DEV_UART2)	+= uart2.o
obj-$(CONFIG_DEV_UART3)	+= uart3.o
obj-$(CONFIG_DEV_UART4)	+= uart4.o
obj-$(CONFIG_DEV_UART5)	+= uart5.o
obj-$(CONFIG_DEV_UART6)	+= uart6.o
obj-$(CONFIG_DEV_UART7)	+= uart7.o

# GPIO ========================================================================
$(src)/gpio0.c: $(src)/gpio0.h
$(src)/gpio1.c: $(src)/gpio1.h
$(src)/gpio2.c: $(src)/gpio2.h
$(src)/gpio3.c: $(src)/gpio3.h
$(src)/gpio4.c: $(src)/gpio4.h
$(src)/gpio5.c: $(src)/gpio5.h

gpio_remap="ABCDEF"
$(src)/gpio%.c: $(src)/gen.gpio.c $(src)/conf_gpio.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@" $(gpio_remap)
$(src)/gpio%.h: $(src)/gen.gpio.h $(src)/conf_gpio.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@" $(gpio_remap)
# SPI =========================================================================
$(src)/spi0.c: $(src)/spi0.h
$(src)/spi1.c: $(src)/spi1.h
$(src)/spi2.c: $(src)/spi2.h
$(src)/spi3.c: $(src)/spi3.h

$(src)/spi%.c: $(src)/gen.spi.c $(src)/conf_spi.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@"
$(src)/spi%.h: $(src)/gen.spi.h $(src)/conf_spi.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@"
# UART ========================================================================
$(src)/uart0.c: $(src)/uart0.h
$(src)/uart1.c: $(src)/uart1.h
$(src)/uart2.c: $(src)/uart2.h
$(src)/uart3.c: $(src)/uart3.h
$(src)/uart4.c: $(src)/uart4.h
$(src)/uart5.c: $(src)/uart5.h
$(src)/uart6.c: $(src)/uart6.h
$(src)/uart7.c: $(src)/uart7.h

$(src)/uart%.c: $(src)/gen.uart.c $(src)/conf_uart.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@"
$(src)/uart%.h: $(src)/gen.uart.h $(src)/conf_uart.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@"
# =============================================================================
