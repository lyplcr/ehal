# Handle objects in subdirs
# ---------------------------------------------------------------------------
# o if we encounter foo/ in $(obj-y), replace it by foo/built-in.o
#   and add the directory to the list of dirs to descend into: $(subdir-y)

subdir-y	:= $(patsubst %/,%,$(filter %/, $(obj-y)))
obj-y		:= $(patsubst %/, %/built-in.o, $(obj-y))

# Subdirectories we need to descend into
subdir-ym	:= $(sort $(subdir-y))

# if $(foo-objs) exists, foo.o is a composite object 
multi-used	:= $(sort $(foreach m,$(obj-y), $(if $(strip $($(m:.o=-objs)) $($(m:.o=-y))), $(m))))

# Build list of the parts of our composite objects, our composite
# objects depend on those (obviously)
multi-objs	:= $(foreach m, $(multi-used-y), $($(m:.o=-objs)) $($(m:.o=-y)))

# $(subdir-obj-y) is the list of objects in $(obj-y) which uses dir/ to
# tell kbuild to descend
subdir-obj-y	:= $(filter %/built-in.o, $(obj-y))

# $(obj-dirs) is a list of directories that contain object files
obj-dirs	:= $(dir $(multi-objs) $(obj-y))

# Replace multi-part objects by their individual parts, look at local dir only
real-objs-y := $(foreach m, $(filter-out $(subdir-obj-y), $(obj-y)), $(if $(strip $($(m:.o=-objs)) $($(m:.o=-y))),$($(m:.o=-objs)) $($(m:.o=-y)),$(m))) $(extra-y)

# Add subdir path

targets		:= $(addprefix $(obj)/,$(targets))
obj-y		:= $(addprefix $(obj)/,$(obj-y))
subdir-obj-y	:= $(addprefix $(obj)/,$(subdir-obj-y))
multi-used-y	:= $(addprefix $(obj)/,$(multi-used-y))
multi-objs-y	:= $(addprefix $(obj)/,$(multi-objs-y))
subdir-ym	:= $(addprefix $(obj)/,$(subdir-ym))
obj-dirs	:= $(addprefix $(obj)/,$(obj-dirs))
