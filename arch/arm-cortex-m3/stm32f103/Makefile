prefix	:= arm-none-eabi-

cflags-y        += -mlittle-endian -mthumb -mcpu=cortex-m3 -I$(archdir)
cflags-y        += -mfloat-abi=soft -ffunction-sections -fdata-sections -flto
cflags-y	+= -DSTM32F10X_HD

ldlibs-y        += -T$(archdir)$(mcu).ld
ldlibs-y        += -Wl,--gc-sections

arch-y          += $(archdir)lib/
arch-y          += $(archdir)dev/
