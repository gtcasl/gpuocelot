# (c) 2010 The Board of Trustees of the University of Illinois.

include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk

SRCDIR_OBJS=file.o
SRCDIR_CUDAOBJS=fft.o

LINK_MODE=CUDA

all: $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk


