obj-$(CONFIG_DEV_CPU0)	+= cpu0.o
obj-$(CONFIG_DEV_GPIO0)	+= gpio0.o
obj-$(CONFIG_DEV_GPIO1)	+= gpio1.o
obj-$(CONFIG_DEV_GPIO2)	+= gpio2.o

$(src)/gpio0.c: $(src)/gpio0.h
$(src)/gpio1.c: $(src)/gpio1.h
$(src)/gpio2.c: $(src)/gpio2.h

# transform 0->B, 1->C, 2->D...
gpio_remap="BCD"
$(src)/gpio%.c: $(src)/gen.gpio.c $(src)/conf_gpio.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@" $(gpio_remap)
$(src)/gpio%.h: $(src)/gen.gpio.h $(src)/conf_gpio.h
	@echo "GEN:  $@"
	sh scripts/gen.dev.sh "$@" $(gpio_remap)
