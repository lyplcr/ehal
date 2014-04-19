include scripts/include.mk

# ouput names
elf := $(O)$(MCU).elf
bin := $(elf:%.elf=%.bin)
hex := $(elf:%.elf=%.hex)

# build rules to call directly
all:       build
build:     $(elf) $(hex) $(bin)
build-elf: $(elf)
build-bin: $(bin)
build-hex: $(bin)

# dirs we look for code
src-$(CONFIG_SRC)		:= src/
#arch-$(CONFIG_ARCH)		:=
drivers-$(CONFIG_DRIVERS)	:= drivers/

## build section. ##############################################################
target-dirs	:= $(patsubst %/,%,$(src-y) $(arch-y) $(drivers-y))
target-objs	:= $(patsubst %,$(O)%/built-in.o,$(target-dirs))

$(elf): $(target-dirs)
	$($(print)cc_elf)
$(bin): $(elf)
	$($(print)cp_bin)
$(hex): $(elf)
	$($(print)cp_hex)
size:   $(elf)
	$(SIZE) $<

# descend.
$(target-dirs):
	$(kmake) $(build)=$(O)$@

## clean section. ##############################################################
clean-dirs := $(addprefix _clean_,$(target-dirs))
clean-objs := $(addprefix _clean_,$(target-objs))

clean: $(clean-dirs)
	$(RM) $(elf) $(bin) $(hex) $(patsubst _clean_%,%,$(clean-objs))

# descend.
$(clean-dirs):
	$(kmake) $(clean)=$(patsubst _clean_%,$(O)%,$@)

help:
	@echo "make <target> <opt>"
	@echo ""
	@echo "targets:"
	@echo "* all"
	@echo "* build"
	@echo "* size"
	@echo "* build-elf"
	@echo "* build-hex"
	@echo "* build-bin"
	@echo "* clean"
	@echo "* help"
	@echo ""
	@echo "opts:"
	@echo "* ARCH=<arch>"
	@echo "* MCU=<mcu>"
	@echo ""
	@echo "archs:"
	@echo $(shell ls arch)

.PHONY: build bin clean $(target-dirs)
