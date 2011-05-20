#################################################################
#  Makefile for Monte-Carlo Extreme (MCX) RNG Benchmark
#  Qianqian Fang <fangq at nmr.mgh.harvard.edu>
#  2009/04/16
#################################################################

CUDACC=nvcc
CCC=g++
SOURCE=rngspeed
BINARY=rngspeed
OUTPUT_DIR=../../bin
OPT=-DUSE_MT_RAND
CPPOPT=-I/usr/local/cuda/include -I../../src
INCLUDEDIRS=-I/usr/local/cuda/include  -I../../src
LINKOPT=-L/usr/local/cuda/lib -lcudart 

CUCCOPT=-I../../src
CPPOPT=-g -Wall

OBJSUFFIX=.o
EXESUFFIX=

FILES=rngspeed

ARCH = $(shell uname -m)
PLATFORM = $(shell uname -o)
ifeq ($(findstring Msys,$(PLATFORM)), Msys)
  CCC=nvcc
  LINKOPT=-L/c/CUDA/lib -lcudart --link
  INCLUDEDIRS +=-I/c/CUDA/include
  CPPOPT =-c  -D_CRT_SECURE_NO_DEPRECATE
  OBJSUFFIX=.obj
  EXESUFFIX=.exe
else
  ifeq ($(findstring x86_64,$(ARCH)), x86_64)
     ifeq "$(wildcard /usr/local/cuda/lib64)" "/usr/local/cuda/lib64"
        LINKOPT=-L/usr/local/cuda/lib64 -lcudart 
     endif
  endif
endif

OBJS      := $(addsuffix $(OBJSUFFIX), $(FILES))

all mt:     OPT=-DUSE_MT_RAND
logistic:   OPT=
mtw:        OPT=-DUSE_MT_RAND -DGLOBAL_WRITE
logisticw:  OPT=-DGLOBAL_WRITE
debug:      OPT=-DUSE_MT_RAND -DGLOBAL_WRITE
debuglog:   OPT=-DGLOBAL_WRITE


all mt mtw logistic logisticw: cudasdk $(OUTPUT_DIR)/$(BINARY)

$(OUTPUT_DIR)/$(BINARY): $(OBJS)
	$(CCC) $(LINKOPT) $(OBJS) -o $(OUTPUT_DIR)/$(BINARY)

%$(OBJSUFFIX): %.c
	$(CCC) $(INCLUDEDIRS) $(CPPOPT) $(OPT) -c -o $@  $<

%$(OBJSUFFIX): %.cu
	$(CUDACC) -c $(CUCCOPT) $(OPT) -o $@  $<

clean:
	-rm -f $(OBJS) $(OUTPUT_DIR)/$(BINARY)$(EXESUFFIX) $(OUTPUT_DIR)/$(BINARY)_atomic$(EXESUFFIX)
cudasdk:
	@if [ -z `which ${CUDACC}` ]; then \
	   echo "Please first install CUDA SDK or add path to nvcc to your PATH environment variable."; exit 1;\
	fi
