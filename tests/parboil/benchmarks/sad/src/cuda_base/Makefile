# (c) Copyright 2007 The Board of Trustees of the University of Illinois.

include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk

SRCDIR_CUDAOBJS=sad4.o largerBlocks.o main.o
SRCDIR_OBJS=file.o image.o

LINK_MODE=CUDA

all : $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk
