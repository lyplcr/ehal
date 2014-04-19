# Build .o files from .c and .s.

# Do not reorder
include scripts/include.mk
include $(src)/Makefile
include scripts/lib.mk

# create dirs for out of tree build.
_dummy := $(shell [ -d $(obj) ] || mkdir -p $(obj))
_dummy := $(foreach d,$(obj-dirs), $(shell [ -d $(d) ] || mkdir -p $(d)))

# skip empty built-in.
ifneq ($(strip $(obj-y)),)
builtin-target := $(obj)/built-in.o
endif

# The output to the upper layer is a $(builtin-target), thats what we'll build.
build: $(builtin-target)
$(builtin-target): $(obj-y)
	$($(print)ld_o_o)

$(obj)/%.o: $(src)/%.c $(obj)/%.d
	$($(print)cc_o_c)

$(obj)/%.o: $(src)/%.s
	$($(print)cc_o_s)

$(obj)/%.d: $(src)/%.c
	$($(print)cc_d_c)

# multi .o
$(multi-used): %.o: $(multi-objs-y)
	$($(print)ld_o_o)

# descend for folders
$(sort $(subdir-obj-y)): $(subdir-ym) ;
$(subdir-ym):
	$(kmake) $(build)=$@

# include and workout dependencies (in a way that a no .dep won't explode)
-include $(obj-y:.o=.d)

.PHONY: $(subdir-ym)
