# (c) 2010 The Board of Trustees of the University of Illinois.

# Shared makefile definitions
include $(PARBOIL_ROOT)/common/mk/common.mk

# To use slow (but precise) math routines
ifeq ($(slowmath), 1)
	EXTRA_CFLAGS += -fp-model precise
else
	EXTRA_CFLAGS += -ffast-math
	EXTRA_CXXFLAGS += -ffast-math
endif

EXTRA_LIBS += -lm -lstdc++

# To use the MKL library
ifeq ($(mkl), 1)
	EXTRA_LIBS += -L/opt/intel/mkl/8.0/lib/em64t \
		-lmkl -lvml -lguide -lpthread
	INCLUDES += -I/opt/intel/mkl/9.1.023/include
	EXTRA_CFLAGS += -DMKL
endif

SRCDIR_OBJS=main.o 

LINK_MODE=C

all : $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk


























