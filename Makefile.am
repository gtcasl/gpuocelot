################################################################################
#
#	\file Makefile.am
#
#	\author Gregory Diamos, Andrew Kerr
#
#	\date Wednesday September 10, 2008
#
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot
#	
################################################################################

################################################################################
## Global Parameters
AM_YFLAGS = -d
AM_LFLAGS = -o$(LEX_OUTPUT_ROOT).c --c++
GL_LIBS = -lGL -lGLU -lglut -lGLEW
BOOST_LIBS = lib/libboost_filesystem-gcc43-mt-1_37.a \
	lib/libboost_system-gcc43-mt-1_37.a \
	lib/libboost_wserialization-gcc43-mt-1_37.a \
	lib/libboost_serialization-gcc43-mt-1_37.a
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
################################################################################

################################################################################
## Programs and Libraries
BUILT_SOURCES=ptxgrammar.h
bin_PROGRAMS = CFG Module BranchTraceAnalyzer MemoryTraceAnalyzer \
	ParallelismTraceAnalyzer SharedComputationAnalyzer
sdk : $(SDK_PROGRAMS)
examples :  Sequence MatrixMultiply CapModel3 
EXTRA_PROGRAMS = AlignedTypes ConvolutionFFT2D FastWalshTransform MatrixMul \
	 QuasirandomGenerator SimpleCUFFT SmokeParticles AsyncAPI \
	 ConvolutionSeparable FluidsGL RecursiveGaussian SimpleGL \
	 SobelFilter BandwidthTest ConvolutionTexture Histogram256 MersenneTwister \
	 Reduction SimpleMultiGPU Template BicubicTexture CppIntegration \
	 Histogram64 MonteCarlo ScalarProd SimpleStreams \
	 BinomialOptions Dct8x8 ImageDenoising MonteCarloMultiGPU Scan \
	 SimpleTemplates Transpose Bitonic DeviceQuery LineOfSight Nbody \
	 ScanLargeArray SimpleTexture VolumeRender BlackScholes DwtHaar1D \
	 Mandelbrot OceanFFT SimpleTexture3D BoxFilter Dxtc MarchingCubes \
	 Particles SimpleAtomicIntrinsics Clock Eigenvalues \
	 PostProcessGL SimpleCUBLAS SimpleVoteIntrinsics SimplerFFT \
	 Sequence MatrixMultiply CapModel3 RangeDopplerGen \
	 RangeDopplerMap
check_PROGRAMS = TestLexer TestParser \
	TestEmulator TestInstructions TestKernels TestTrace \
	TestMemoryTraceGenerator \
	TestVSIPL
lib_LTLIBRARIES = libir.la libparser.la libhydrazine.la libexecutive.la \
	libtrace.la libcudart.la libvsip.la
################################################################################

################################################################################
## libir
libir_la_CXXFLAGS = -I ocelot -Wall -ansi -pedantic -Werror -std=c++0x
libir_la_SOURCES = ocelot/ir/implementation/BasicBlock.cpp \
	ocelot/ir/implementation/ControlFlowGraph.cpp \
	ocelot/ir/implementation/Edge.cpp \
	ocelot/ir/implementation/Instruction.cpp \
	ocelot/ir/implementation/Parameter.cpp \
	ocelot/ir/implementation/Global.cpp \
	ocelot/ir/implementation/PTXInstruction.cpp \
	ocelot/ir/implementation/PTXStatement.cpp \
	ocelot/ir/implementation/PTXOperand.cpp \
	ocelot/ir/implementation/Module.cpp \
	ocelot/ir/implementation/Kernel.cpp \
	ocelot/ir/implementation/PTXKernel.cpp \
	ocelot/ir/implementation/Texture.cpp \
	ocelot/ir/implementation/DominatorTree.cpp \
	ocelot/ir/implementation/PostdominatorTree.cpp
################################################################################

################################################################################
## libhydrazine
libhydrazine_la_CXXFLAGS = -I ocelot $(CUDA_CFLAGS) -Wall -ansi -pedantic \
	-Werror -std=c++0x
libhydrazine_la_SOURCES = \
	hydrazine/implementation/Exception.cpp \
	hydrazine/implementation/Package.cpp \
	hydrazine/implementation/SerializationBuffer.cpp \
	hydrazine/implementation/XmlLexer.cpp \
	hydrazine/implementation/Timer.cpp \
	hydrazine/implementation/LowLevelTimer.cpp \
	hydrazine/implementation/ArgumentParser.cpp \
	hydrazine/implementation/XmlParser.cpp \
	hydrazine/implementation/SerializableArchive.cpp \
	hydrazine/implementation/math.cpp \
	hydrazine/implementation/debug.cpp \
	hydrazine/implementation/XmlArgumentParser.cpp \
	hydrazine/implementation/XmlTree.cpp \
	hydrazine/implementation/string.cpp \
	hydrazine/cuda/Cuda.cpp \
	hydrazine/interface/Configurable.cpp \
	hydrazine/interface/Test.cpp \
	hydrazine/interface/Serializable.cpp \
	hydrazine/interface/Stringable.cpp \
	hydrazine/interface/ActiveTimer.cpp \
	hydrazine/interface/Clonable.cpp \
	hydrazine/interface/Thread.cpp \
	hydrazine/interface/Version.cpp
################################################################################

################################################################################
## libtrace
libtrace_la_CXXFLAGS = -I ocelot -Wall -ansi -pedantic -Werror -std=c++0x
libtrace_la_SOURCES = \
	ocelot/trace/implementation/TraceEvent.cpp \
	ocelot/trace/implementation/TraceGenerator.cpp \
	ocelot/trace/implementation/BranchTraceGenerator.cpp \
	ocelot/trace/implementation/MemoryTraceGenerator.cpp \
	ocelot/trace/implementation/ParallelismTraceGenerator.cpp \
	ocelot/trace/implementation/SharedComputationGenerator.cpp \
	ocelot/trace/implementation/KernelEntry.cpp
	
################################################################################

################################################################################
## libexecutive
libexecutive_la_CXXFLAGS = -I ocelot -Wall -ansi -pedantic -Werror -std=c++0x
libexecutive_la_SOURCES = \
	ocelot/executive/implementation/Device.cpp \
	ocelot/executive/implementation/Executive.cpp \
	ocelot/executive/implementation/CTAContext.cpp \
	ocelot/executive/implementation/EmulatedKernel.cpp \
	ocelot/executive/implementation/RuntimeException.cpp \
	ocelot/executive/implementation/CooperativeThreadArray.cpp
################################################################################

################################################################################
## libparser
libparser_la_CXXFLAGS = -I ocelot -Wall -ansi -Werror -std=c++0x
libparser_la_SOURCES = \
	ocelot/parser/implementation/ptx.lpp \
	ocelot/parser/implementation/ptxgrammar.ypp \
	ocelot/parser/implementation/ptx1_4grammar.ypp \
	ocelot/parser/implementation/PTXParser.cpp \
	ocelot/parser/implementation/PTXLexer.cpp
################################################################################

################################################################################
## libcudart
libcudart_la_CXXFLAGS = -I ocelot $(CUDA_CFLAGS) -Wall -ansi -pedantic -Werror \
	-std=c++0x
libcudart_la_SOURCES = \
	ocelot/cuda/implementation/OcelotRuntimeApi.cpp \
	ocelot/cuda/implementation/CudaRuntime.cpp
libcudart_la_LDFLAGS = -version-info 2:1:0
################################################################################

################################################################################
## libvsip.la
libvsip_la_CXXFLAGS = -I ocelot $(CUDA_CFLAGS) -std=c++0x
libvsip_la_SOURCES = \
	tests/vsipl/GPUVSIPL/vsipl-startup.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-support.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-block.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-util.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-vview_f.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-qrd.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-cmview_f.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-vview_vi.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-mview_f.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-vview_i.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-vview_bl.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-vview_mi.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-cvview_f.cpp \
	tests/vsipl/GPUVSIPL/vsipl-scalar-functions.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-mview_bl.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-boolean.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-celementwise.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-complex.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-copy.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-elementwise.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-integer.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-logical.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-vector-ternary.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-fir.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-histo.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-qrd-house.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-qrd-mgs.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-reduction.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-vector-product.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-cholesky.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-copy.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-elementwise.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-matrix-matrix-product.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-rand.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-fir.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-cfir.cpp \
	tests/vsipl/GPUVSIPL/vsipl-melwise.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-mproc.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-sigproc.cpp \
	tests/vsipl/GPUVSIPL/vsipl-sigproc.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-cuda-msigproc.cpp \
	tests/vsipl/GPUVSIPL/vsipl-msigproc.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-sigproc-conv.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-sigproc-corr1d.cu.cpp \
	tests/vsipl/GPUVSIPL/vsipl-sigproc-window.cu.cpp

################################################################################

################################################################################
## CapModel3
CapModel3_CXXFLAGS = -I ocelot $(CUDA_CFLAGS) -Wall -std=c++0x
CapModel3_CFLAGS = -I ocelot $(CUDA_CFLAGS) -Wall -std=c99
CapModel3_SOURCES = CapModel3.cu.cpp \
	tests/cuda/CapModel3/TestCapModel3.cpp \
	tests/cuda/CapModel3/SimulationParameters.cpp \
	tests/cuda/CapModel3/MultiVariateNormal.c \
	tests/cuda/CapModel3/Date.cpp \
	tests/cuda/CapModel3/CapModel3.cpp
	
CapModel3_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
CapModel3_LDFLAGS = -static

CapModel3.cu.cpp : tests/cuda/CapModel3/capModel3.cu
	$(NVCC) -I ocelot -arch sm_13 --use_fast_math --cuda -o $@ $<
################################################################################

################################################################################
## Sequence
Sequence_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x
Sequence_SOURCES = Sequence.cu.cpp
Sequence_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Sequence_LDFLAGS = -static

Sequence.cu.cpp : tests/cuda/Sequence/sequence.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $<
################################################################################

################################################################################
## MatrixMultiply
MatrixMultiply_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
MatrixMultiply_SOURCES = tests/cuda/matmult/mult.c matmult.cu.cpp
MatrixMultiply_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
MatrixMultiply_LDFLAGS = -static

matmult.cu.cpp: tests/cuda/matmult/matmult.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $<
################################################################################

################################################################################
## ParallelismTraceAnalyzer
ParallelismTraceAnalyzer_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror \
	-std=c++0x
ParallelismTraceAnalyzer_SOURCES = \
	source/trace/implementation/ParallelismTraceAnalyzer.cpp
ParallelismTraceAnalyzer_LDADD = libhydrazine.la libir.la libparser.la \
	libtrace.la $(LIBRT) $(BOOST_LIBS)
ParallelismTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## BranchTraceAnalyzer
BranchTraceAnalyzer_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror \
	-std=c++0x
BranchTraceAnalyzer_SOURCES = \
	source/trace/implementation/BranchTraceAnalyzer.cpp
BranchTraceAnalyzer_LDADD = libhydrazine.la libir.la libparser.la libtrace.la \
	$(LIBRT) $(BOOST_LIBS)
BranchTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## MemoryTraceAnalyzer
MemoryTraceAnalyzer_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror \
	-std=c++0x
MemoryTraceAnalyzer_SOURCES = \
	source/trace/implementation/MemoryTraceAnalyzer.cpp
MemoryTraceAnalyzer_LDADD = libhydrazine.la libir.la libparser.la libtrace.la \
	$(LIBRT) $(BOOST_LIBS)
MemoryTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## SharedComputationAnalyzer
SharedComputationAnalyzer_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror \
	-std=c++0x
SharedComputationAnalyzer_SOURCES = \
	source/trace/implementation/SharedComputationAnalyzer.cpp
SharedComputationAnalyzer_LDADD = libhydrazine.la libir.la libparser.la libtrace.la \
	$(LIBRT) $(BOOST_LIBS)
SharedComputationAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## CFG
CFG_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
CFG_SOURCES = source/ir/test/CFG.cpp
CFG_LDADD = libir.la libparser.la libhydrazine.la $(LIBRT)
CFG_LDFLAGS = -static
################################################################################

################################################################################
## Module
Module_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
Module_SOURCES = source/ir/test/Module.cpp
Module_LDADD = libir.la libparser.la libhydrazine.la $(LIBRT)
Module_LDFLAGS = -static
################################################################################

################################################################################
## TestLexer
TestLexer_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
TestLexer_SOURCES = source/parser/test/TestLexer.cpp
TestLexer_LDADD = libir.la libparser.la libhydrazine.la $(BOOST_LIBS) $(LIBRT)
TestLexer_LDFLAGS = -static
################################################################################

################################################################################
## TestParser
TestParser_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
TestParser_SOURCES = source/parser/test/TestParser.cpp
TestParser_LDADD = libir.la libparser.la libhydrazine.la $(BOOST_LIBS) $(LIBRT)
TestParser_LDFLAGS = -static
################################################################################

################################################################################
## TestEmulator
TestEmulator_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
TestEmulator_SOURCES = source/executive/test/TestEmulator.cpp
TestEmulator_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT)
TestEmulator_LDFLAGS = -static
################################################################################

################################################################################
## TestKernels
TestKernels_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
TestKernels_SOURCES = source/executive/test/TestKernels.cpp
TestKernels_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT)
TestKernels_LDFLAGS = -static
################################################################################

################################################################################
## TestTrace
TestTrace_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
TestTrace_SOURCES = source/executive/test/TestTrace.cpp
TestTrace_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT)
TestTrace_LDFLAGS = -static
################################################################################

################################################################################
## TestMemoryTraceGenerator
TestMemoryTraceGenerator_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
TestMemoryTraceGenerator_SOURCES = \
	source/trace/test/TestMemoryTraceGenerator.cpp \
	TestMemoryTraceGenerator_kernel.cu.cpp
TestMemoryTraceGenerator_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
TestMemoryTraceGenerator_LDFLAGS = -static

TestMemoryTraceGenerator_kernel.cu.cpp: \
	source/trace/test/TestMemoryTraceGenerator_kernel.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## TestInstructions
TestInstructions_CXXFLAGS = -I source -Wall -ansi -pedantic -Werror -std=c++0x
TestInstructions_SOURCES = source/executive/test/TestInstructions.cpp
TestInstructions_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT)
TestInstructions_LDFLAGS = -static
################################################################################

################################################################################
## TestVSIPL
TestVSIPL_CXXFLAGS = -I tests/vsipl/GPUVSIPL -I source $(CUDA_CFLAGS) -std=c++0x
TestVSIPL_SOURCES = tests/vsipl/TestVSIPL/Testvsip.cpp

TestVSIPL_LDADD = libvsip.la $(SDK_LIBS) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) \
	$(GL_LIBS) $(BOOST_LIBS)
	
## TestVSIPL_LDFLAGS 
##
################################################################################

################################################################################
## RangeDopplerMap

RangeDopplerGen_CXXFLAGS = -I tests/vsipl/GPUVSIPL -I source $(CUDA_CFLAGS) \
	-std=c++0x
RangeDopplerGen_SOURCES = tests/vsipl/RangeDoppler/gen_data.cpp
RangeDopplerGen_LDADD = libvsip.la $(SDK_LIBS) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) \
	$(GL_LIBS) $(BOOST_LIBS)


RangeDopplerMap_CXXFLAGS = -I tests/vsipl/GPUVSIPL -I source $(CUDA_CFLAGS) \
	-std=c++0x
RangeDopplerMap_SOURCES = tests/vsipl/RangeDoppler/vsip_rd.cpp
RangeDopplerMap_LDADD = libvsip.la $(SDK_LIBS) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) \
	$(GL_LIBS) $(BOOST_LIBS)

##
################################################################################

################################################################################
## AlignedTypes
AlignedTypes_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
AlignedTypes_SOURCES = AlignedTypes.cu.cpp
AlignedTypes_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
AlignedTypes_LDFLAGS = -static

AlignedTypes.cu.cpp: tests/cuda/AlignedTypes/alignedTypes.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## AsyncAPI
AsyncAPI_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x -D__DEVICE_EMULATION__
AsyncAPI_SOURCES = AsyncAPI.cu.cpp
AsyncAPI_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
AsyncAPI_LDFLAGS = -static

AsyncAPI.cu.cpp: tests/cuda/AsyncAPI/asyncAPI.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## BandwidthTest
BandwidthTest_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
BandwidthTest_SOURCES = BandwidthTest.cu.cpp
BandwidthTest_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BandwidthTest_LDFLAGS = -static

BandwidthTest.cu.cpp: tests/cuda/BandwidthTest/bandwidthTest.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## BicubicTexture
BicubicTexture_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
BicubicTexture_SOURCES = BicubicTexture.cu.cpp \
	tests/cuda/BlackScholes/BlackScholes_gold.cpp
BicubicTexture_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BicubicTexture_LDFLAGS = -static

BicubicTexture.cu.cpp: tests/cuda/BicubicTexture/bicubicTexture.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## BinomialOptions
BinomialOptions_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x -I tests/cuda/BinomialOptions $(SDK_CFLAGS)
BinomialOptions_SOURCES = BinomialOptions_SM13.cu.cpp \
	BinomialOptions_SM10.cu.cpp \
	tests/cuda/BinomialOptions/binomialOptions_common.h \
	tests/cuda/BinomialOptions/binomialOptions.cpp  \
	tests/cuda/BinomialOptions/binomialOptions_gold.cpp
BinomialOptions_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
BinomialOptions_LDFLAGS = -static

BinomialOptions_SM13.cu.cpp: tests/cuda/BinomialOptions/binomialOptions_SM13.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
BinomialOptions_SM10.cu.cpp: tests/cuda/BinomialOptions/binomialOptions_SM10.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS) 
################################################################################

################################################################################
## Bitonic
Bitonic_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Bitonic_SOURCES = Bitonic.cu.cpp
Bitonic_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Bitonic_LDFLAGS = -static

Bitonic.cu.cpp: tests/cuda/Bitonic/bitonic.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## BlackScholes
BlackScholes_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
BlackScholes_SOURCES = BlackScholes.cu.cpp \
	tests/cuda/BlackScholes/BlackScholes_gold.cpp
BlackScholes_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BlackScholes_LDFLAGS = -static

BlackScholes.cu.cpp: tests/cuda/BlackScholes/BlackScholes.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## BoxFilter
BoxFilter_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
BoxFilter_SOURCES = BoxFilter.cu.cpp \
	tests/cuda/BoxFilter/boxFilter_gold.cpp \
	tests/cuda/BoxFilter/boxFilter.cpp
BoxFilter_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BoxFilter_LDFLAGS = -static

BoxFilter.cu.cpp: tests/cuda/BoxFilter/boxFilter_kernel.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## Clock
Clock_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Clock_SOURCES = Clock.cu.cpp
Clock_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Clock_LDFLAGS = -static

Clock.cu.cpp: tests/cuda/Clock/clock.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## ConvolutionFFT2D
ConvolutionFFT2D_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ConvolutionFFT2D_SOURCES = ConvolutionFFT2D.cu.cpp \
	tests/cuda/ConvolutionFFT2D/convolutionFFT2D_gold.cpp
ConvolutionFFT2D_LDADD = $(SDK_LIBS) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) \
	$(GL_LIBS) $(BOOST_LIBS)

ConvolutionFFT2D.cu.cpp: tests/cuda/ConvolutionFFT2D/convolutionFFT2D.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## ConvolutionSeparable
ConvolutionSeparable_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ConvolutionSeparable_SOURCES = ConvolutionSeparable.cu.cpp \
	tests/cuda/ConvolutionSeparable/convolutionSeparable_gold.cpp
ConvolutionSeparable_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
ConvolutionSeparable_LDFLAGS = -static

ConvolutionSeparable.cu.cpp: \
	tests/cuda/ConvolutionSeparable/convolutionSeparable.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)\
		-Itests/cuda/ConvolutionSeparable -D__DEVICE_EMULATION__
################################################################################

################################################################################
## ConvolutionTexture
ConvolutionTexture_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ConvolutionTexture_SOURCES = ConvolutionTexture.cu.cpp \
	tests/cuda/ConvolutionTexture/convolutionTexture_gold.cpp
ConvolutionTexture_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
ConvolutionTexture_LDFLAGS = -static

ConvolutionTexture.cu.cpp: \
	tests/cuda/ConvolutionTexture/convolutionTexture.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## CppIntegration
CppIntegration_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
CppIntegration_SOURCES = CppIntegration.cu.cpp \
	tests/cuda/CppIntegration/cppIntegration_gold.cpp \
	tests/cuda/CppIntegration/main.cpp
CppIntegration_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
CppIntegration_LDFLAGS = -static

CppIntegration.cu.cpp: \
	tests/cuda/CppIntegration/cppIntegration.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Dct8x8
Dct8x8_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
Dct8x8_SOURCES = Dct8x8.cu.cpp \
	tests/cuda/Dct8x8/DCT8x8_Gold.cpp \
	tests/cuda/Dct8x8/BmpUtil.cpp
Dct8x8_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Dct8x8_LDFLAGS = -static

Dct8x8.cu.cpp: \
	tests/cuda/Dct8x8/dct8x8.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## DeviceQuery
DeviceQuery_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
DeviceQuery_SOURCES = DeviceQuery.cu.cpp
DeviceQuery_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
DeviceQuery_LDFLAGS = -static

DeviceQuery.cu.cpp: tests/cuda/DeviceQuery/deviceQuery.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## DwtHaar1D
DwtHaar1D_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
DwtHaar1D_SOURCES = DwtHaar1D.cu.cpp
DwtHaar1D_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
DwtHaar1D_LDFLAGS = -static

DwtHaar1D.cu.cpp: tests/cuda/DwtHaar1D/dwtHaar1D.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Dxtc
Dxtc_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Dxtc_SOURCES = Dxtc.cu.cpp DxtcTests.cu.cpp
Dxtc_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Dxtc_LDFLAGS = -static

Dxtc.cu.cpp: tests/cuda/Dxtc/dxtc.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
DxtcTests.cu.cpp: tests/cuda/Dxtc/dxtcTests.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Eigenvalues
Eigenvalues_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Eigenvalues_SOURCES = Eigenvalues.cu.cpp \
	tests/cuda/Eigenvalues/matlab.cpp \
	tests/cuda/Eigenvalues/gerschgorin.cpp \
	Bisect_large.cu.cpp \
	Bisect_small.cu.cpp
Eigenvalues_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Eigenvalues_LDFLAGS = -static

Eigenvalues.cu.cpp: tests/cuda/Eigenvalues/main.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
Bisect_large.cu.cpp: tests/cuda/Eigenvalues/bisect_large.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
Bisect_small.cu.cpp: tests/cuda/Eigenvalues/bisect_small.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## FluidsGL
FluidsGL_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
FluidsGL_SOURCES = FluidsGL.cu.cpp
FluidsGL_LDADD = $(SDK_LIBS) $(LIBRT) $(GL_LIBS) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(BOOST_LIBS)

FluidsGL.cu.cpp: tests/cuda/FluidsGL/fluidsGL.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## FastWalshTransform
FastWalshTransform_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
FastWalshTransform_SOURCES = FastWalshTransform.cu.cpp \
	tests/cuda/FastWalshTransform/fastWalshTransform_gold.cpp
FastWalshTransform_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
FastWalshTransform_LDFLAGS = -static

FastWalshTransform.cu.cpp: tests/cuda/FastWalshTransform/fastWalshTransform.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## Histogram256
Histogram256_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
Histogram256_SOURCES = Histogram256_SM10.cu.cpp \
	Histogram256_SM11.cu.cpp \
	Histogram256_SM12.cu.cpp \
	tests/cuda/Histogram256/histogram256_gold.cpp \
	tests/cuda/Histogram256/histogram256.cpp
Histogram256_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Histogram256_LDFLAGS = -static

Histogram256_SM10.cu.cpp: tests/cuda/Histogram256/histogram256_SM10.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
Histogram256_SM11.cu.cpp: tests/cuda/Histogram256/histogram256_SM11.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
Histogram256_SM12.cu.cpp: tests/cuda/Histogram256/histogram256_SM12.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Histogram64
Histogram64_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Histogram64_SOURCES = Histogram64.cu.cpp \
	tests/cuda/Histogram64/histogram64_gold.cpp
Histogram64_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Histogram64_LDFLAGS = -static

Histogram64.cu.cpp: tests/cuda/Histogram64/histogram64.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## ImageDenoising
ImageDenoising_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
ImageDenoising_SOURCES = ImageDenoising.cu.cpp \
	tests/cuda/ImageDenoising/bmploader.cpp \
	tests/cuda/ImageDenoising/imageDenoisingGL.cpp
ImageDenoising_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
ImageDenoising_LDFLAGS = -static

ImageDenoising.cu.cpp: tests/cuda/ImageDenoising/imageDenoising.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Mandelbrot
Mandelbrot_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Mandelbrot_SOURCES = Mandelbrot_sm10.cu.cpp Mandelbrot_sm13.cu.cpp \
	tests/cuda/Mandelbrot/Mandelbrot.cpp \
	tests/cuda/Mandelbrot/Mandelbrot_gold.cpp
Mandelbrot_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Mandelbrot_LDFLAGS = -static

Mandelbrot_sm10.cu.cpp: tests/cuda/Mandelbrot/Mandelbrot_sm10.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS)
Mandelbrot_sm13.cu.cpp: tests/cuda/Mandelbrot/Mandelbrot_sm13.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## MatrixMul
MatrixMul_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
MatrixMul_SOURCES = MatrixMul.cu.cpp \
	tests/cuda/MatrixMul/matrixMul_gold.cpp
MatrixMul_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
MatrixMul_LDFLAGS = -static

MatrixMul.cu.cpp: tests/cuda/MatrixMul/matrixMul.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## MersenneTwister
MersenneTwister_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
MersenneTwister_SOURCES = MersenneTwister.cu.cpp \
	tests/cuda/MersenneTwister/MersenneTwister_gold.cpp \
	tests/cuda/MersenneTwister/genmtrand.c 
MersenneTwister_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
MersenneTwister_LDFLAGS = -static

MersenneTwister.cu.cpp: tests/cuda/MersenneTwister/MersenneTwister.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## MonteCarlo
MonteCarlo_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
MonteCarlo_SOURCES = MonteCarlo_SM13.cu.cpp MonteCarlo_SM10.cu.cpp \
	tests/cuda/MonteCarlo/MonteCarlo_gold.cpp \
	tests/cuda/MonteCarlo/MonteCarlo.cpp
MonteCarlo_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
MonteCarlo_LDFLAGS = -static

MonteCarlo_SM13.cu.cpp: tests/cuda/MonteCarlo/MonteCarlo_SM13.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
MonteCarlo_SM10.cu.cpp: tests/cuda/MonteCarlo/MonteCarlo_SM10.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## MonteCarloMultiGPU
MonteCarloMultiGPU_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
MonteCarloMultiGPU_SOURCES = MonteCarloMultiGPU_SM13.cu.cpp \
	MonteCarloMultiGPU_SM10.cu.cpp \
	tests/cuda/MonteCarlo/MonteCarlo_gold.cpp \
	tests/cuda/MonteCarlo/MonteCarlo.cpp
MonteCarloMultiGPU_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
MonteCarloMultiGPU_LDFLAGS = -static

MonteCarloMultiGPU_SM13.cu.cpp: tests/cuda/MonteCarloMultiGPU/MonteCarlo_SM13.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
MonteCarloMultiGPU_SM10.cu.cpp: tests/cuda/MonteCarloMultiGPU/MonteCarlo_SM10.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Nbody
Nbody_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Nbody_SOURCES = Nbodysystemcuda.cu.cpp tests/cuda/Nbody/nbody.cpp \
	tests/cuda/Nbody/bodysystemcpu.cpp \
	tests/cuda/Nbody/bodysystemcuda.cpp \
	tests/cuda/Nbody/nbody_gold.cpp \
	tests/cuda/Nbody/render_particles.cpp
Nbody_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Nbody_LDFLAGS = -static

Nbodysystemcuda.cu.cpp : tests/cuda/Nbody/bodysystemcuda.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## OceanFFT
OceanFFT_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
OceanFFT_SOURCES = OceanFFT_kernel.cu.cpp \
	tests/cuda/OceanFFT/oceanFFT.cpp
OceanFFT_LDADD = $(SDK_LIBS) $(LIBRT) $(GL_LIBS) $(CUFFT_LIBS) \
	libcudart.la libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la\
	$(BOOST_LIBS)

OceanFFT_kernel.cu.cpp : tests/cuda/OceanFFT/oceanFFT_kernel.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Particles
Particles_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Particles_SOURCES = ParticleSystem.cu.cpp \
	tests/cuda/Particles/particles.cpp \
	tests/cuda/Particles/particleSystem.cpp \
	tests/cuda/Particles/render_particles.cpp \
	tests/cuda/Particles/shaders.cpp
Particles_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Particles_LDFLAGS = -static

ParticleSystem.cu.cpp : tests/cuda/Particles/particleSystem.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## PostProcessGL
PostProcessGL_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
PostProcessGL_SOURCES = PostProcessGL.cu.cpp tests/cuda/PostProcessGL/main.cpp
PostProcessGL_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
PostProcessGL_LDFLAGS = -static

PostProcessGL.cu.cpp : tests/cuda/PostProcessGL/postProcessGL.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## QuasirandomGenerator
QuasirandomGenerator_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
QuasirandomGenerator_SOURCES = QuasirandomGenerator_SM13.cu.cpp \
	QuasirandomGenerator_SM10.cu.cpp \
	tests/cuda/QuasirandomGenerator/quasirandomGenerator_gold.cpp \
	tests/cuda/QuasirandomGenerator/quasirandomGenerator.cpp
QuasirandomGenerator_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
QuasirandomGenerator_LDFLAGS = -static

QuasirandomGenerator_SM13.cu.cpp: \
	tests/cuda/QuasirandomGenerator/quasirandomGenerator_SM13.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
QuasirandomGenerator_SM10.cu.cpp: \
	tests/cuda/QuasirandomGenerator/quasirandomGenerator_SM10.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## RecursiveGaussian
RecursiveGaussian_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
RecursiveGaussian_SOURCES = RecursiveGaussian.cu.cpp
RecursiveGaussian_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
RecursiveGaussian_LDFLAGS = -static

RecursiveGaussian.cu.cpp : tests/cuda/RecursiveGaussian/recursiveGaussian.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Reduction
Reduction_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Reduction_SOURCES = Reduction_kernel_SM13.cu.cpp Reduction_kernel_SM10.cu.cpp \
	Reduction.cu.cpp
Reduction_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Reduction_LDFLAGS = -static

Reduction_kernel_SM13.cu.cpp: tests/cuda/Reduction/reduction_kernel_sm13.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
Reduction_kernel_SM10.cu.cpp: tests/cuda/Reduction/reduction_kernel_sm10.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
Reduction.cu.cpp: tests/cuda/Reduction/reduction.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## ScalarProd
ScalarProd_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ScalarProd_SOURCES = ScalarProd.cu.cpp \
	tests/cuda/ScalarProd/scalarProd_gold.cpp
ScalarProd_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
ScalarProd_LDFLAGS = -static

ScalarProd.cu.cpp: tests/cuda/ScalarProd/scalarProd.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Scan
Scan_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Scan_SOURCES = Scan.cu.cpp \
	tests/cuda/Scan/scan_gold.cpp
Scan_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Scan_LDFLAGS = -static

Scan.cu.cpp: tests/cuda/Scan/scan.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## ScanLargeArray
ScanLargeArray_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ScanLargeArray_SOURCES = ScanLargeArray.cu.cpp \
	tests/cuda/ScanLargeArray/scan_gold.cpp
ScanLargeArray_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
ScanLargeArray_LDFLAGS = -static

ScanLargeArray.cu.cpp: tests/cuda/ScanLargeArray/scanLargeArray.cu
	$(NVCC) -arch sm_10 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## SimpleAtomicIntrinsics
SimpleAtomicIntrinsics_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
SimpleAtomicIntrinsics_SOURCES = SimpleAtomicIntrinsics.cu.cpp \
	tests/cuda/SimpleAtomicIntrinsics/simpleAtomicIntrinsics_gold.cpp
SimpleAtomicIntrinsics_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
SimpleAtomicIntrinsics_LDFLAGS = -static

SimpleAtomicIntrinsics.cu.cpp: \
	tests/cuda/SimpleAtomicIntrinsics/simpleAtomicIntrinsics.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleCUBLAS
SimpleCUBLAS_CFLAGS = -I source $(CUDA_CFLAGS) -Wall
SimpleCUBLAS_SOURCES = tests/cuda/SimpleCUBLAS/simpleCUBLAS.c
SimpleCUBLAS_LDADD = $(SDK_LIBS) $(CUBLAS_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(BOOST_LIBS) \
	$(GL_LIBS)
################################################################################

################################################################################
## SimpleCUFFT
SimpleCUFFT_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
SimpleCUFFT_SOURCES = SimpleCUFFT.cu.cpp
SimpleCUFFT_LDADD = $(SDK_LIBS) $(GL_LIBS) $(CUFFT_LIBS) $(LIBRT) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la \
	$(BOOST_LIBS)

SimpleCUFFT.cu.cpp: tests/cuda/SimpleCUFFT/simpleCUFFT.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleCUFFT
SimplerFFT_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
SimplerFFT_SOURCES = SimplerFFT.cu.cpp
SimplerFFT_LDADD = $(SDK_LIBS) $(LIBRT) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(GL_LIBS) \
	$(BOOST_LIBS)

SimplerFFT.cu.cpp: tests/cuda/SimpleCUFFT/simplerFFT.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleGL
SimpleGL_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
SimpleGL_SOURCES = SimpleGL_kernel.cu.cpp tests/cuda/SimpleGL/simpleGL.cpp
SimpleGL_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleGL_LDFLAGS = -static

SimpleGL_kernel.cu.cpp : tests/cuda/SimpleGL/simpleGL_kernel.cu
	$(NVCC) -arch sm_10 --use_fast_math --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleMultiGPU
SimpleMultiGPU_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleMultiGPU_SOURCES = SimpleMultiGPU.cu.cpp \
	tests/cuda/SimpleMultiGPU/simpleMultiGPU.cpp
SimpleMultiGPU_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleMultiGPU_LDFLAGS = -static

SimpleMultiGPU.cu.cpp: tests/cuda/SimpleMultiGPU/simpleMultiGPU_kernel.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleStreams
SimpleStreams_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
SimpleStreams_SOURCES = SimpleStreams.cu.cpp
SimpleStreams_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleStreams_LDFLAGS = -static

SimpleStreams.cu.cpp: tests/cuda/SimpleStreams/simpleStreams.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS) -D__DEVICE_EMULATION__
################################################################################

################################################################################
## SimpleTemplates
SimpleTemplates_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleTemplates_SOURCES = SimpleTemplates.cu.cpp
SimpleTemplates_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleTemplates_LDFLAGS = -static

SimpleTemplates.cu.cpp: tests/cuda/SimpleTemplates/simpleTemplates.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleTexture
SimpleTexture_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
SimpleTexture_SOURCES = SimpleTexture.cu.cpp
SimpleTexture_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleTexture_LDFLAGS = -static

SimpleTexture.cu.cpp: tests/cuda/SimpleTexture/simpleTexture.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleTexture3D
SimpleTexture3D_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleTexture3D_SOURCES = SimpleTexture3D.cu.cpp
SimpleTexture3D_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleTexture3D_LDFLAGS = -static

SimpleTexture3D.cu.cpp: tests/cuda/SimpleTexture3D/simpleTexture3D.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SimpleVoteIntrinsics
SimpleVoteIntrinsics_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleVoteIntrinsics_SOURCES = SimpleVoteIntrinsics.cu.cpp
SimpleVoteIntrinsics_LDADD = $(SDK_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) \
	$(GL_LIBS) $(BOOST_LIBS)
	
SimpleVoteIntrinsics_LDFLAGS = -static

SimpleVoteIntrinsics.cu.cpp: \
	tests/cuda/SimpleVoteIntrinsics/simpleVoteIntrinsics.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## SobelFilter
SobelFilter_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SobelFilter_SOURCES = SobelFilter.cu.cpp \
	tests/cuda/SobelFilter/SobelFilter.cpp
SobelFilter_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SobelFilter_LDFLAGS = -static

SobelFilter.cu.cpp: tests/cuda/SobelFilter/SobelFilter_kernels.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Template
Template_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
Template_SOURCES = Template.cu.cpp \
	tests/cuda/Template/template_gold.cpp
Template_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Template_LDFLAGS = -static

Template.cu.cpp: tests/cuda/Template/Template.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Transpose
Transpose_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
Transpose_SOURCES = Transpose.cu.cpp \
	tests/cuda/Transpose/transpose_gold.cpp
Transpose_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Transpose_LDFLAGS = -static

Transpose.cu.cpp: tests/cuda/Transpose/transpose.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## VolumeRender
VolumeRender_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
VolumeRender_SOURCES = VolumeRender.cu.cpp
VolumeRender_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
VolumeRender_LDFLAGS = -static

VolumeRender.cu.cpp: tests/cuda/VolumeRender/volumeRender.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = 

################################################################################

################################################################################
## Regression tests
sdkTest : tests/regression/sdkRegression.log
ocelotTest : tests/regression/ocelotRegression.log
binTest : tests/regression/binRegression.log

tests/regression/ocelotRegression.log : check
	@echo
	@echo "Running Ocelot unit tests"
	@python hydrazine/python/RunRegression.py \
		-t tests/regression/ocelotRegressionTests.txt \
		-l tests/regression/ocelotRegression.log -v

tests/regression/sdkRegression.log : sdk
	@echo
	@echo "Running CUDA SDK regression test"
	@python hydrazine/python/RunRegression.py \
		-t tests/regression/sdkRegressionTests.txt \
		-l tests/regression/sdkRegression.log -v

tests/regression/binRegression.log : examples
	@echo
	@echo "Running Ocelot applications test"
	@python hydrazine/python/RunRegression.py \
		-t tests/regression/binRegressionTests.txt \
		-l tests/regression/binRegression.log -v

test : sdkTest ocelotTest binTest

################################################################################

################################################################################
## Extra clean rules
CLEANFILES = ptxgrammar.h ptxgrammar.cpp ptx.cpp ptx1_4grammar.h \
	ptx1_4grammar.cpp
CLEANFILES += $(SDK_PROGRAMS) Sequence MatrixMultiply CapModel3 \
	RangeDopplerMap RangeDopplerGen SimplerFFT
CLEANFILES += *.linkinfo *.cu.cpp 
################################################################################

