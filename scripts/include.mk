include scripts/opts.mk

archdir := arch/$(ARCH)/
include $(archdir)Makefile

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
CFLAGS += -Os -g -std=gnu99 $(cflags-y) -I. $(warning_$(W))
LDLIBS += $(ldlibs-y)
