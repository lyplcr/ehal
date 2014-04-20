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

       ld_o_o = $(LD) -r -o $@ $(obj-y)
 quiet_ld_o_o = $(ld_o_o)
pretty_ld_o_o = @echo "'$@' subtree is done."; $(ld_o_o)
$(builtin-target): $(obj-y)
	$($(print)ld_o_o)

       cc_o_c = $(CC) $(CFLAGS) -c $< -o $@
 quiet_cc_o_c = @echo "CC:   $@"; $(cc_o_c)
pretty_cc_o_c = @echo "rebuilding '$@' because of '$<'"; $(cc_o_c)
$(obj)/%.o: $(src)/%.c $(obj)/%.d
	$($(print)cc_o_c)

       cc_o_s = $(CC) $(CFLAGS) -c $< -o $@
 quiet_cc_o_s = @echo "AS:   $@"; $(cc_o_s)
pretty_cc_o_s = @echo "rebuilding '$@' because of '$<'"; $(cc_o_s)
$(obj)/%.o: $(src)/%.s
	$($(print)cc_o_s)

       cc_d_c = $(CC) $(CFLAGS) -MM -MT $(@:.d=.o) $< > $@
 quiet_cc_d_c = $(cc_d_c)
pretty_cc_d_c = @echo "rebuilding '$@' because of '$<'"; $(cc_d_c)
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
