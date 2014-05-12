prefix		:= arm-none-eabi-

cflags-y	+= -mlittle-endian -mthumb -mcpu=cortex-m4 -Iarch/$(ARCH) -Iarch/$(ARCH)$(SUBARCH)
cflags-y	+= -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -flto

ldlibs-y	+= -Tarch/$(ARCH)$(SUBARCH)/lm4f120h5qr.ld
ldlibs-y	+= -Wl,--gc-sections

arch-y			+= arch/$(ARCH)$(SUBARCH)
arch-$(CONFIG_DEV)	+= arch/$(ARCH)$(SUBARCH)/dev/
