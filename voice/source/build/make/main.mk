default: all


include $(PROJ_DIR)/config.mk


# SUB_DIRS =
define PROC_SUBDIRS_FUNC
    $(1).Dir.all: $(1)
    $(1).Dir.clean: $(1)
    SUB.dirs.all += $(1).Dir.all
    SUB.dirs.clean += $(1).Dir.clean
endef
$(foreach Dir,$(SUB_DIRS),$(eval $(call PROC_SUBDIRS_FUNC,$(Dir))))
all: $(SUB.dirs.all)
clean: $(SUB.dirs.clean)

%.Dir.all: %
	make -C $< all PROJ_DIR=$(PROJ_DIR)
%.Dir.clean: %
	make -C $< clean PROJ_DIR=$(PROJ_DIR)


# BINS = 
# xxx_CSRCS = 
# xxx_CXXSRCS =
# xxx_CFLAGS = 
# xxx_CXXFLAGS =
# xxx_LDFLAGS = 
# xxx_LIBS = 

define PROC_BINS_FUNC
    $(1)_OBJS  = $$($(1)_CSRCS:%.c=%.o)
    $(1)_OBJS += $$($(1)_CXXSRCS:%.cpp=%.o)
    BINS_OBJS += $$($(1)_OBJS)

    $(1)_OBJS: LOCAL_CFLAGS = $$($(1)_CFLAGS)
    $(1)_OBJS: LOCAL_CXXFLAGS = $$($(1)_CXXFLAGS)

    $(1).bin: LOCAL_OBJS = $$($(1)_OBJS)
    $(1).bin: LOCAL_LDFLAGS = $$($(1)_LDFLAGS)
    $(1).bin: $$($(1)_OBJS)

    $(1).Bin.all : $(1).bin
    $(1).Bin.clean: DELETE_FILES = $$($(1)_OBJS) $(1)
    BINS.all += $(1).Bin.all
    BINS.clean += $(1).Bin.clean
endef
$(foreach Bin,$(BINS),$(eval $(call PROC_BINS_FUNC,$(Bin))))
all: $(BINS.all)
clean: $(BINS.clean)

%.bin:
	gcc $(LDFLAGS) $(LOCAL_LDFLAGS) -o $@ 	\
		$(LOCAL_OBJS)

%.Bin.clean:
	rm -f $(DELETE_FILES)


# LIBS = 
# xxx_CSRCS = 
# xxx_CXXSRCS = 
# xxx_CFLAGS = 
# xxx_CXXFLAGS =
# xxx_LDFLAGS = 
# xxx_LIBS = 
LIB_EXT = so
define PROC_LIBS_FUNC
    $(1)_OBJS  = $$($(1)_CSRCS:%.c=%.o)
    $(1)_OBJS += $$($(1)_CXXSRCS:%.cpp=%.o)
    LIBS_OBJS += $$($(1)_OBJS)

    $(1)_OBJS: LOCAL_CFLAGS = $$($(1)_CFLAGS)
    $(1)_OBJS: LOCAL_CXXFLAGS = $$($(1)_CXXFLAGS)

    lib$(1).$(LIB_EXT): LOCAL_OBJS = $$($(1)_OBJS)
    lib$(1).$(LIB_EXT): LOCAL_LDFLAGS = $$($(1)_LDFLAGS)
    lib$(1).$(LIB_EXT): $$($(1)_OBJS)

    $(1).Lib.all : lib$(1).$(LIB_EXT)
    $(1).Lib.clean: DELETE_FILES = $$($(1)_OBJS) lib$(1).$(LIB_EXT)
    LIBS.all += $(1).Lib.all
    LIBS.clean += $(1).Lib.clean
endef
$(foreach Lib,$(LIBS),$(eval $(call PROC_LIBS_FUNC,$(Lib))))
all: $(LIBS.all)
clean: $(LIBS.clean)

lib%.$(LIB_EXT):
	gcc -fPIC -shared \
		-o $@ $(LOCAL_OBJS) 	\
		$(LDFLAGS) $(LOCAL_LDFLAGS)
%.Lib.clean:
	rm -f $(DELETE_FILES)




WORK_DIR ?= $(shell pwd)
PROJ_DIR ?= $(WORK_DIR)

%.o : %.c
	gcc $(CFLAGS) $(LOCAL_CFLAGS) -c $< -o $@
%.o : %.cpp
	gcc $(CXFLAGS) $(LOCAL_CXXFLAGS) -c $< -o $@

