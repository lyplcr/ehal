obj-$(CONFIG_DEV_CPU0)	+= cpu0.o
obj-$(CONFIG_DEV_GPIO0)	+= gpio0.o
obj-$(CONFIG_DEV_GPIO1)	+= gpio1.o
obj-$(CONFIG_DEV_GPIO2)	+= gpio2.o
obj-$(CONFIG_DEV_GPIO3)	+= gpio3.o
obj-$(CONFIG_DEV_GPIO4)	+= gpio4.o
obj-$(CONFIG_DEV_GPIO5)	+= gpio5.o
obj-$(CONFIG_DEV_UART0)	+= uart0.o

$(src)/gpio%.c $(src)/gpio%.h: $(src)/template_gpio.c $(src)/template_gpio.h $(src)/conf_gpio.h
	@echo "GEN: $(src)/gpio[0-5].[ch]"
	sh $(src)/gen_gpio.sh "$(src)/"
