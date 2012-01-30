# (c) 2007 The Board of Trustees of the University of Illinois.

include $(PARBOIL_ROOT)/common/mk/common.mk
include $(PARBOIL_ROOT)/common/mk/cuda.mk

SRCDIR_CUDAOBJS=main.o histo_final.o histo_intermediates.o histo_main.o histo_prescan.o util.o

EXTRA_CUDACFLAGS=-arch sm_20

LINK_MODE=CUDA

all: $(BIN)

include $(PARBOIL_ROOT)/common/mk/rules.mk
include $(PARBOIL_ROOT)/common/mk/cuda_rules.mk
