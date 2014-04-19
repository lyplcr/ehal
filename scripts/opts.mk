-include .config

# give me a ARCH/MCU to build for.
ifeq ($(ARCH),)
$(error give me a ARCH to build for)
endif

ifeq ($(MCU),)
$(error give me a MCU to build for)
endif


# 'make V=1' for verbose (using commands)
ifeq ($(V),1)
	Q=
	S=
	print=
endif
# 'make V=2' for verbose (using words description)
ifeq ($(V),2)
	Q=
	S=
	print=pretty_
endif
# 'make' for quiet (very short description)
ifeq ($(V),)
	Q=@
	S=-s
	print=quiet_
endif

# 'make elf' to build elf.
# 'make bin' to build a binary from the elf.
# 'make clean' remove .o, .d and generated files.
