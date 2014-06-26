obj-$(CONFIG_DEV_CPU0)	+= cpu0.o
obj-$(CONFIG_DEV_GPIO0)	+= gpio0.o
obj-$(CONFIG_DEV_GPIO1)	+= gpio1.o
obj-$(CONFIG_DEV_GPIO2)	+= gpio2.o
obj-$(CONFIG_DEV_GPIO3)	+= gpio3.o
obj-$(CONFIG_DEV_GPIO4)	+= gpio4.o
obj-$(CONFIG_DEV_GPIO5)	+= gpio5.o
obj-$(CONFIG_DEV_UART0)	+= uart0.o
obj-$(CONFIG_DEV_SPI0)	+= spi0.o
obj-$(CONFIG_DEV_SPI1)	+= spi1.o
obj-$(CONFIG_DEV_SPI2)	+= spi2.o
obj-$(CONFIG_DEV_SPI3)	+= spi3.o

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
# =============================================================================
