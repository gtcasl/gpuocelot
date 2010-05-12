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
OCELOT_LIBS = $(OCELOT_LDFLAGS) libsdk.la 
CUDA_CFLAGS = -I $(srcdir)/sdk -std=c++0x
SDK_CFLAGS = -I $(srcdir)/sdk
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS = 
check_PROGRAMS = 3DFD SortingNetwork worleyTestExternalSharedMemory \
	TestAtomics TestMemoryAccesses TestBarriers TestSpecialFunctions \
	TestInstructionThroughput TestCallLatency \
	TestThrustArbitraryTransform TestThrustBasicVector TestThrustBoundingBox \
	TestThrustBucketSort2D TestThrustConstantIterator \
	TestThrustCountingIterator TestThrustZipDot TestThrustFillCopy \
	TestThrustHistogram TestThrustMaxAbsDiff TestThrustMinMax TestThrustMode \
	TestThrustNorm TestThrustPaddedGridReduction \
	TestThrustSaxpy TestThrustSegmentedScan \
	TestThrustSort TestThrustAOSSorting TestThrustStreamCompact \
	TestThrustSum \
	TestThrustTransformIterator TestThrustWrapPointer TestThrustUnwrapPointer \
	vectorAdd
	
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
## vectorAdd
vectorAdd_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
vectorAdd_SOURCES = tests/vectorAdd/vectorAdd.cu.cpp
vectorAdd_LDADD = $(OCELOT_LIBS)
vectorAdd_LDFLAGS = -static
################################################################################

################################################################################
## TestAtomics
TestAtomics_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TestAtomics_SOURCES = tests/AtomicPerformance/atomicsImplementation.cpp \
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
## TestCallLatency
TestCallLatency_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TestCallLatency_SOURCES = tests/TestCallLatency/TestCallLatency.cpp
TestCallLatency_LDADD = $(OCELOT_LIBS)
TestCallLatency_LDFLAGS = -static
################################################################################

################################################################################
## TestSpecialFunctions
TestSpecialFunctions_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TestSpecialFunctions_SOURCES = \
	tests/TestSpecialFunctions/TestSpecialFunctions.cpp
TestSpecialFunctions_LDADD = $(OCELOT_LIBS)
TestSpecialFunctions_LDFLAGS = -static
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
## TestThrustArbitraryTransform
TestThrustArbitraryTransform_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustArbitraryTransform_SOURCES = \
	tests/thrust_arbitrary_transformation/arbitrary_transformation.cu.cpp
TestThrustArbitraryTransform_LDADD = $(OCELOT_LIBS)
TestThrustArbitraryTransform_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustBasicVector
TestThrustBasicVector_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustBasicVector_SOURCES = \
	tests/thrust_basic_vector/basic_vector.cu.cpp
TestThrustBasicVector_LDADD = $(OCELOT_LIBS)
TestThrustBasicVector_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustBoundingBox
TestThrustBoundingBox_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustBoundingBox_SOURCES = \
	tests/thrust_bounding_box/bounding_box.cu.cpp
TestThrustBoundingBox_LDADD = $(OCELOT_LIBS)
TestThrustBoundingBox_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustBucketSort2D
TestThrustBucketSort2D_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustBucketSort2D_SOURCES = \
	tests/thrust_bucket_sort2d/bucket_sort2d.cu.cpp
TestThrustBucketSort2D_LDADD = $(OCELOT_LIBS)
TestThrustBucketSort2D_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustConstantIterator
TestThrustConstantIterator_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustConstantIterator_SOURCES = \
	tests/thrust_constant_iterator/constant_iterator.cu.cpp
TestThrustConstantIterator_LDADD = $(OCELOT_LIBS)
TestThrustConstantIterator_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustCountingIterator
TestThrustCountingIterator_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustCountingIterator_SOURCES = \
	tests/thrust_counting_iterator/counting_iterator.cu.cpp
TestThrustCountingIterator_LDADD = $(OCELOT_LIBS)
TestThrustCountingIterator_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustZipDot
TestThrustZipDot_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustZipDot_SOURCES = \
	tests/thrust_dot_products_with_zip/dot_products_with_zip.cu.cpp
TestThrustZipDot_LDADD = $(OCELOT_LIBS)
TestThrustZipDot_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustFillCopy
TestThrustFillCopy_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustFillCopy_SOURCES = \
	tests/thrust_fill_copy_sequence/fill_copy_sequence.cu.cpp
TestThrustFillCopy_LDADD = $(OCELOT_LIBS)
TestThrustFillCopy_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustHistogram
TestThrustHistogram_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustHistogram_SOURCES = \
	tests/thrust_histogram/histogram.cu.cpp
TestThrustHistogram_LDADD = $(OCELOT_LIBS)
TestThrustHistogram_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustMaxAbsDiff
TestThrustMaxAbsDiff_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustMaxAbsDiff_SOURCES = \
	tests/thrust_max_abs_diff/max_abs_diff.cu.cpp
TestThrustMaxAbsDiff_LDADD = $(OCELOT_LIBS)
TestThrustMaxAbsDiff_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustMinMax
TestThrustMinMax_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustMinMax_SOURCES = \
	tests/thrust_minmax/minmax.cu.cpp
TestThrustMinMax_LDADD = $(OCELOT_LIBS)
TestThrustMinMax_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustMode
TestThrustMode_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustMode_SOURCES = \
	tests/thrust_mode/mode.cu.cpp
TestThrustMode_LDADD = $(OCELOT_LIBS)
TestThrustMode_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustNorm
TestThrustNorm_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustNorm_SOURCES = \
	tests/thrust_norm/norm.cu.cpp
TestThrustNorm_LDADD = $(OCELOT_LIBS)
TestThrustNorm_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustPaddedGridReduction
TestThrustPaddedGridReduction_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustPaddedGridReduction_SOURCES = \
	tests/thrust_padded_grid_reduction/padded_grid_reduction.cu.cpp
TestThrustPaddedGridReduction_LDADD = $(OCELOT_LIBS)
TestThrustPaddedGridReduction_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustSaxpy
TestThrustSaxpy_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustSaxpy_SOURCES = \
	tests/thrust_saxpy/saxpy.cu.cpp
TestThrustSaxpy_LDADD = $(OCELOT_LIBS)
TestThrustSaxpy_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustSegmentedScan
TestThrustSegmentedScan_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustSegmentedScan_SOURCES = \
	tests/thrust_segmented_scan/segmented_scan.cu.cpp
TestThrustSegmentedScan_LDADD = $(OCELOT_LIBS)
TestThrustSegmentedScan_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustSort
TestThrustSort_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustSort_SOURCES = \
	tests/thrust_sort/sort.cu.cpp
TestThrustSort_LDADD = $(OCELOT_LIBS)
TestThrustSort_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustAOSSorting
TestThrustAOSSorting_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustAOSSorting_SOURCES = \
	tests/thrust_sorting_aos_vs_soa/sorting_aos_vs_soa.cu.cpp
TestThrustAOSSorting_LDADD = $(OCELOT_LIBS)
TestThrustAOSSorting_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustStreamCompact
TestThrustStreamCompact_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustStreamCompact_SOURCES = \
	tests/thrust_stream_compaction/stream_compaction.cu.cpp
TestThrustStreamCompact_LDADD = $(OCELOT_LIBS)
TestThrustStreamCompact_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustSum
TestThrustSum_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustSum_SOURCES = \
	tests/thrust_sum/sum.cu.cpp
TestThrustSum_LDADD = $(OCELOT_LIBS)
TestThrustSum_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustTransformIterator
TestThrustTransformIterator_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustTransformIterator_SOURCES = \
	tests/thrust_transform_iterator/transform_iterator.cu.cpp
TestThrustTransformIterator_LDADD = $(OCELOT_LIBS)
TestThrustTransformIterator_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustWrapPointer
TestThrustWrapPointer_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustWrapPointer_SOURCES = \
	tests/thrust_wrap_pointer/wrap_pointer.cu.cpp
TestThrustWrapPointer_LDADD = $(OCELOT_LIBS)
TestThrustWrapPointer_LDFLAGS = -static
################################################################################

################################################################################
## TestThrustUnwrapPointer
TestThrustUnwrapPointer_CXXFLAGS = $(CUDA_CFLAGS)
TestThrustUnwrapPointer_SOURCES = \
	tests/thrust_unwrap_pointer/unwrap_pointer.cu.cpp
TestThrustUnwrapPointer_LDADD = $(OCELOT_LIBS)
TestThrustUnwrapPointer_LDFLAGS = -static
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


