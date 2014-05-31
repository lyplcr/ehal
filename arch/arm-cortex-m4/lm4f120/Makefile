prefix	:= arm-none-eabi-

cflags-y        += -mlittle-endian -mthumb -mcpu=cortex-m4 -I$(archdir)
cflags-y        += -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -flto

ldlibs-y        += -T$(archdir)lm4f120h5qr.ld
ldlibs-y        += -Wl,--gc-sections

arch-y          += $(archdir)lib/
arch-y          += $(archdir)dev/
