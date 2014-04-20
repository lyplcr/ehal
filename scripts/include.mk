include scripts/opts.mk
include arch/$(ARCH)/Makefile

# Do not
# o  use make builtins rules (to make it faster)
# o  print "Entering directory ..."; (to make it less obnoxious)
MAKEFLAGS += -rR --no-print-directory

# gnu toolchain cmds with prefix added (such as: arm-none-eabi-).
CC      := $(prefix)gcc
LD      := $(prefix)ld
NM      := $(prefix)nm
OBJCOPY := $(prefix)objcopy
OBJDUMP := $(prefix)objdump
SIZE    := $(prefix)size
RM      := @rm -f

# call make but quietly
kmake := @$(MAKE) $(S)

# commands (full log):
cc_o_c = $(CC) $(CFLAGS) -c $< -o $@
cc_d_c = $(CC) $(CFLAGS) -MM -MT $(@:.d=.o) $< > $@
cc_o_s = $(CC) $(CFLAGS) -c $< -o $@
cc_elf = $(CC) $(CFLAGS) -o $@ $(target-objs) $(LDLIBS)
ld_o_o = $(LD) -r -o $@ $(obj-y)
cp_bin = $(OBJCOPY) -O binary $< $@
cp_hex = $(OBJCOPY) -O ihex $< $@

# very short log (default).
quiet_cc_o_c = @echo "CC:   $@"; $(cc_o_c)
quiet_cc_d_c =                   $(cc_d_c)
quiet_cc_o_s = @echo "AS:   $@"; $(cc_o_s)
quiet_cc_elf = @echo "LD:   $@"; $(cc_elf)
quiet_ld_o_o =                   $(ld_o_o)
quiet_cp_bin = @echo "COPY: $@"; $(cp_bin)
quiet_cp_hex = @echo "COPY: $@"; $(cp_hex)

# describe in words what is getting done.
pretty_cc_o_c = @echo "rebuilding '$@' because of '$<'"; $(cc_o_c)
pretty_cc_d_c = @echo "rebuilding '$@' because of '$<'"; $(cc_d_c)
pretty_cc_o_s = @echo "rebuilding '$@' because of '$<'"; $(cc_o_s)
pretty_cc_elf = @echo "'$@' all done!"; $(cc_elf)
pretty_ld_o_o = @echo "'$@' subtree is done."; $(ld_o_o)
pretty_cp_bin = @echo "'$@' because you asked for a .bin"; $(cp_bin)
pretty_cp_hex = @echo "'$@' because you asked for a .hex"; $(cp_hex)


build=-f scripts/build.mk build obj
clean=-f scripts/clean.mk clean obj

# grab the src/ tree out of the obj/ tree so we can generate the build in a
# diferent tree
src := $(patsubst $(O)%, %, $(obj))

# warning level.
warning_1	:=
warning_2	:= $(warning_1)
warning_3	:= $(warning_2) -Wall -pedantic


# for local obj flags.
CFLAGS += -Os -fomit-frame-pointer $(cflags-y) -I. $(warning_$(W))
LDLIBS += $(ldlibs-y)
