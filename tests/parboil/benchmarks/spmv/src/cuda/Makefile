# (c) 2007 The Board of Trustees of the University of Illinois.

# Shared makefile definitions
include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk

# To use slow (but precise) math routines
ifeq ($(slowmath), 1)
	EXTRA_CFLAGS += -fp-model precise
else
	EXTRA_CFLAGS += -ffast-math
	EXTRA_CXXFLAGS += -ffast-math
	EXTRA_CUDACFLAGS += --use_fast_math
endif

EXTRA_LIBS += -lm -lstdc++

# To use the MKL library
ifeq ($(mkl), 1)
	EXTRA_LIBS += -L/opt/intel/mkl/9.1.023/lib/32 \
		-lmkl -lvml -lguide -lpthread
	INCLUDES += -I/opt/intel/mkl/9.1.023/include
	EXTRA_CFLAGS += -DMKL
endif

SRCDIR_OBJS=main.o file.o gpu_info.o

LINK_MODE=CUDA

all : $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk
