# (c) 2010 The Board of Trustees of the University of Illinois.

include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk


SRCDIR_OBJS=main.o io.o #compute_gold.o
EXTRA_LIBS=-lm -lstdc++ 
EXTRA_CFLAGS=-ffast-math -g3
EXTRA_CXXFLAGS=-ffast-math -g3
LINK_MODE=CUDA

all : $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk
