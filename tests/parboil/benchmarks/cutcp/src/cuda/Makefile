# (c) 2010 The Board of Trustees of the University of Illinois.

include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk

SRCDIR_OBJS=main.o readatom.o output.o excl.o cutcpu.o cutoff6overlap.o
EXTRA_LIBS=-lm

LINK_MODE=CUDA

all : $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk
