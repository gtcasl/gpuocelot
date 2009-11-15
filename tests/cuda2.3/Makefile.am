################################################################################
#	\file Makefile.am
#	\author Gregory Diamos
#	\date Monday Auguest 3, 2009
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot's SDK 2.3 regression tests
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
OCELOT_LIBS = -lcudart -lOcelot -lOcelotExecutive -lOcelotTranslator \
	-lOcelotTrace -lOcelotIr -lOcelotAnalysis -lOcelotParser -lhydrazine \
	libsdk.la $(LLVM_LDFLAGS) $(CUDA_DRIVER_API_LIBARY)
CUFFT_LIBS = -lcufft
CUBLAS_LIBS = -lcublas
CUDA_CFLAGS = -I $(srcdir)/sdk
SDK_CFLAGS = -I $(srcdir)/sdk
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS = 
check_PROGRAMS = 3DFD SortingNetwork worleyTestExternalSharedMemory \
	TestAtomics TestMemoryAccesses TestBarriers TestInstructionThroughput
lib_LTLIBRARIES = libsdk.la
################################################################################

################################################################################
## SDK 2.2 common libraries
libsdk_la_CXXFLAGS = -I sdk $(CUDA_CFLAGS)
libsdk_la_SOURCES = sdk/stopwatch_linux.cpp \
	sdk/cmd_arg_reader.cpp \
	sdk/cutil.cpp \
	sdk/stopwatch.cpp \
	sdk/bank_checker.cpp
################################################################################

################################################################################
## 3DFD
3DFD_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
3DFD_SOURCES = tests/3DFD/3dfd.cu.cpp
3DFD_LDADD = $(OCELOT_LIBS)
3DFD_LDFLAGS = -static
################################################################################

################################################################################
## worleyTestExternalSharedMemory
worleyTestExternalSharedMemory_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
worleyTestExternalSharedMemory_SOURCES = \
	tests/worleyTestExternalSharedMemory/worleyTestExternalSharedMemory.cu.cpp
worleyTestExternalSharedMemory_LDADD = $(OCELOT_LIBS)
worleyTestExternalSharedMemory_LDFLAGS = -static
################################################################################

################################################################################
## SortingNetwork
SortingNetwork_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SortingNetwork_SOURCES = tests/sortingNetworks/bitonicSort.cu.cpp \
	tests/sortingNetworks/oddEvenMergeSort.cu.cpp \
	tests/sortingNetworks/main.cpp \
	tests/sortingNetworks/sortingNetworks_validate.cpp
SortingNetwork_LDADD = $(OCELOT_LIBS)
SortingNetwork_LDFLAGS = -static
################################################################################

################################################################################
## TestAtomics
TestAtomics_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TestAtomics_SOURCES = tests/AtomicPerformance/atomics.cu.cpp \
	tests/AtomicPerformance/atomics.cpp
TestAtomics_LDADD = $(OCELOT_LIBS)
TestAtomics_LDFLAGS = -static
################################################################################

################################################################################
## TestMemoryAccesses
TestMemoryAccesses_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TestMemoryAccesses_SOURCES = tests/memory/TestMemoryAccesses.cpp
TestMemoryAccesses_LDADD = $(OCELOT_LIBS)
TestMemoryAccesses_LDFLAGS = -static
################################################################################

################################################################################
## TestBarriers
TestBarriers_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TestBarriers_SOURCES = tests/TestBarriers/TestBarriers.cpp
TestBarriers_LDADD = $(OCELOT_LIBS)
TestBarriers_LDFLAGS = -static
################################################################################

################################################################################
## TestInstructionThroughput
TestInstructionThroughput_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TestInstructionThroughput_SOURCES = \
	tests/TestInstructionThroughput/TestInstructionThroughput.cpp
TestInstructionThroughput_LDADD = $(OCELOT_LIBS)
TestInstructionThroughput_LDFLAGS = -static
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = sdk/stopwatch_base.h \
	sdk/cutil.h \
	sdk/cutil_math.h \
	sdk/cuComplex.h \
	sdk/vector_types.h \
	sdk/driver_types.h \
	sdk/cutil_gl_inline.h \
	sdk/exception.h \
	sdk/cutil_inline_bankchecker.h \
	sdk/device_types.h \
	sdk/texture_types.h \
	sdk/cutil_inline_runtime.h \
	sdk/error_checker.h \
	sdk/cmd_arg_reader.h \
	sdk/cutil_inline_drvapi.h \
	sdk/cufft.h \
	sdk/builtin_types.h \
	sdk/cutil_gl_error.h \
	sdk/host_defines.h \
	sdk/cuda.h \
	sdk/stopwatch.h \
	sdk/cuda_runtime_api.h \
	sdk/bank_checker.h \
	sdk/stopwatch_linux.h \
	sdk/cutil_inline.h \
	tests/sortingNetworks/sortingNetworks_common.h \
	tests/3DFD/reference.h \
	tests/sortingNetworks/sortingNetworks_common.cuh
################################################################################

################################################################################
## Data
EXTRA_DIST = 

################################################################################


################################################################################
## Regression tests
regression/regression.log : check
	@echo
	@echo "Running CUDA SDK 2.3 regression test"
	@python hydrazine/python/RunRegression.py \
		-t regression/tests.txt \
		-l regression/regression.log -v

test : regression/regression.log

################################################################################


