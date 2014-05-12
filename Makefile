include scripts/include.mk

# ouput names
elf := $(O)$(MCU).elf
bin := $(elf:%.elf=%.bin)
hex := $(elf:%.elf=%.hex)

# build rules to call directly
all:       build-elf build-bin build-hex size
build:     $(elf) $(hex) $(bin)
build-elf: $(elf)
build-bin: $(bin)
build-hex: $(hex)

# dirs we look for code
src-$(CONFIG_SRC)		:= src/
src-$(CONFIG_TEST)		:= test/
core-$(CONFIG_CORE)		:= core/
drivers-$(CONFIG_DRIVERS)	:= drivers/

## build section. ##############################################################
target-dirs	:= $(patsubst %/,%,$(arch-y) $(core-y) $(src-y) $(drivers-y))
target-objs	:= $(patsubst %,$(O)%/built-in.o,$(target-dirs))

       cc_elf = $(CC) $(CFLAGS) -o $@ $(target-objs) $(LDLIBS)
 quiet_cc_elf = @echo "LD:   $@"; $(cc_elf)
pretty_cc_elf = @echo "'$@' all done!"; $(cc_elf)
$(elf): $(target-dirs)
	$($(print)cc_elf)

       cp_bin = $(OBJCOPY) -O binary $< $@
 quiet_cp_bin = @echo "COPY: $@"; $(cp_bin)
pretty_cp_bin = @echo "'$@' because you asked for a .bin"; $(cp_bin)
$(bin): $(elf)
	$($(print)cp_bin)

       cp_hex = $(OBJCOPY) -O ihex $< $@
 quiet_cp_hex = @echo "COPY: $@"; $(cp_hex)
pretty_cp_hex = @echo "'$@' because you asked for a .hex"; $(cp_hex)
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

## config. #####################################################################
config:
	@echo "generating default .config file."
	@cp arch/$(ARCH)$(SUBARCH)/config .config

.PHONY: build bin clean $(target-dirs)
