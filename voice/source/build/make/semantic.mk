
PROJ_DIR := $(shell pwd)

MAKE_TOOL_DIR = $(PROJ_DIR)/build/make

# include toolchain...
include $(MAKE_TOOL_DIR)/linux.x86.platform.mk

LIBS := semantic

# Static Lib
STATIC_LIBS  := $(addprefix lib,$(addsuffix .a,$(LIBS)))
# Dynamic Lib
DYNAMIC_LIBS := $(addprefix lib,$(addsuffix .so,$(LIBS)))

#LIB_CXXSRCS     = $(wildcard semantic/*.cc)
#LIB_HDRS     = $(PROJ_DIR) $(PROJ_DIR)/semantic
LIB_CSRCS     = $(wildcard semantic.2/*.c)
LIB_HDRS     = $(PROJ_DIR) $(PROJ_DIR)/semantic.2
LIB_CFLAGS   = 
LIB_CXXFLAGS = 
LIB_LDFLAGS  = 
LIB_LIBS     =

LIB_OBJS     = $(LIB_CXXSRCS:%.cc=%.o) $(LIB_CSRCS:%.c=%.o)
LIB_LDLIBS   = $(addprefix -l ,$(LIB_LIBS))

CXXFLAGS += -std=gnu++0x $(LIB_CXXFLAGS) $(addprefix -I,$(LIB_HDRS))
CFLAGS   += $(LIB_CFLAGS) $(addprefix -I,$(LIB_HDRS))

$(STATIC_LIBS) : $(LIB_OBJS)
	$(AR) $@ $(LIB_OBJS)

$(DYNAMIC_LIBS) : $(LIB_OBJS)
	$(LD) $(LIB_LDFLAGS) -o $@  \
	    $(LIB_OBJS) $(LIB_LDLIBS)
$(LIBS) : $(STATIC_LIBS) $(DYNAMIC_LIBS)

BINS := debug

BIN_CSRCS     = main.c
BIN_HDRS     = 
BIN_CFLAGS   = 
BIN_CXXFLAGS = 
BIN_LDFLAGS  = 
BIN_LIBS     =

BIN_OBJS     = $(BIN_CSRCS:%.c=%.o)
BIN_LDLIBS   = $(addprefix -l ,$(BIN_LIBS))

CXXFLAGS += $(BIN_CXXFLAGS) $(addprefix -I,$(BIN_HDRS))
CFLAGS   += $(BIN_CFLAGS) $(addprefix -I,$(BIN_HDRS))

$(BINS) : $(BIN_OBJS) $(LIBS)
	$(LD) $(BIN_LDFLAGS) -o $@   \
	    $(BIN_OBJS) $(BIN_LDLIBS)



%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(LIBS) $(BINS)
clean:
	rm -f $(LIB_OBJS) $(BIN_OBJS) $(STATIC_LIBS) $(DYNAMIC_LIBS) $(BINS)


