include scripts/include.mk
include $(src)/Makefile
include scripts/lib.mk

clean: $(subdir-ym)
	$(RM) $(obj)/built-in.o
	$(RM) $(obj-y) $(obj-y:.o=.d) $(subdir-obj-y)

# descend 
$(sort $(subdir-obj-y)): $(subdir-ym) ;
$(subdir-ym):
	$(kmake) $(clean)=$@

.PHONY: $(subdir-ym)
