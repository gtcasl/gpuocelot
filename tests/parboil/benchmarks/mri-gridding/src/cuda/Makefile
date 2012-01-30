# (c) 2007 The Board of Trustees of the University of Illinois.

include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk

SRCDIR_OBJS=CPU_kernels.o
EXTRA_CUDACFLAGS= -arch sm_13
SRCDIR_CUDAOBJS=main.o CUDA_interface.o scanLargeArray.o sort.o
EXTRA_LIBS=

LINK_MODE=CUDA

CUDALDFLAGS=$(LDFLAGS) -Xcompiler "-m64" -L$(CUDAHOME)/lib64 -L$(PARBOIL_ROOT)/common/src $(EXTRA_CUDAFLAGS)

all: $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk

