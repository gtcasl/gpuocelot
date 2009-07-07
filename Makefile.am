################################################################################
#	\file Makefile.am
#	\author Gregory Diamos, Andrew Kerr
#	\date Wednesday September 10, 2008
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot
################################################################################

################################################################################
## Global Parameters
AM_YFLAGS = -d
AM_LFLAGS = -o$(LEX_OUTPUT_ROOT).c --c++
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
################################################################################

################################################################################
## Programs and Libraries
BUILT_SOURCES=ptx1_4grammar.h
bin_PROGRAMS = DFG CFG Module BranchTraceAnalyzer MemoryTraceAnalyzer \
	ParallelismTraceAnalyzer SharedComputationAnalyzer
check_PROGRAMS = TestLexer TestParser \
	TestEmulator TestInstructions TestKernels TestTrace \
	TestMemoryTraceGenerator 
lib_LTLIBRARIES = libir.la libanalysis.la libparser.la libhydrazine.la \
	libexecutive.la libtrace.la libcudart.la
################################################################################

################################################################################
## libanalysis
libanalysis_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
libanalysis_la_SOURCES = ocelot/analysis/implementation/DataflowGraph.cpp \
	ocelot/analysis/implementation/SSAGraph.cpp
################################################################################

################################################################################
## libir
libir_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
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
libhydrazine_la_CXXFLAGS = $(CUDA_CFLAGS) -Wall -ansi -pedantic \
	-Werror -std=c++0x
libhydrazine_la_SOURCES = \
	hydrazine/implementation/Exception.cpp \
	hydrazine/implementation/Package.cpp \
	hydrazine/implementation/XmlLexer.cpp \
	hydrazine/implementation/Timer.cpp \
	hydrazine/implementation/LowLevelTimer.cpp \
	hydrazine/implementation/ArgumentParser.cpp \
	hydrazine/implementation/XmlParser.cpp \
	hydrazine/implementation/math.cpp \
	hydrazine/implementation/debug.cpp \
	hydrazine/implementation/XmlArgumentParser.cpp \
	hydrazine/implementation/XmlTree.cpp \
	hydrazine/implementation/string.cpp \
	hydrazine/cuda/Cuda.cpp \
	hydrazine/interface/Configurable.cpp \
	hydrazine/interface/Test.cpp \
	hydrazine/interface/Stringable.cpp \
	hydrazine/interface/ActiveTimer.cpp \
	hydrazine/interface/Clonable.cpp \
	hydrazine/interface/Thread.cpp \
	hydrazine/interface/Version.cpp
################################################################################

################################################################################
## libtrace
libtrace_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
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
libexecutive_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
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
libcudart_la_CXXFLAGS = $(CUDA_CFLAGS) -Wall -ansi -pedantic -Werror -std=c++0x
libcudart_la_SOURCES = \
	ocelot/cuda/implementation/OcelotRuntimeApi.cpp \
	ocelot/cuda/implementation/CudaRuntime.cpp
libcudart_la_LDFLAGS = -version-info 2:1:0
################################################################################

################################################################################
## ParallelismTraceAnalyzer
ParallelismTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
ParallelismTraceAnalyzer_SOURCES = \
	ocelot/trace/implementation/ParallelismTraceAnalyzer.cpp
ParallelismTraceAnalyzer_LDADD = libhydrazine.la libir.la libparser.la \
	libtrace.la
ParallelismTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## BranchTraceAnalyzer
BranchTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror \
	-std=c++0x
BranchTraceAnalyzer_SOURCES = \
	ocelot/trace/implementation/BranchTraceAnalyzer.cpp
BranchTraceAnalyzer_LDADD = libhydrazine.la libir.la libparser.la libtrace.la \
	$(LIBRT)
BranchTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## MemoryTraceAnalyzer
MemoryTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror \
	-std=c++0x
MemoryTraceAnalyzer_SOURCES = \
	ocelot/trace/implementation/MemoryTraceAnalyzer.cpp
MemoryTraceAnalyzer_LDADD = libhydrazine.la libir.la libparser.la libtrace.la \
	$(LIBRT)
MemoryTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## SharedComputationAnalyzer
SharedComputationAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror \
	-std=c++0x
SharedComputationAnalyzer_SOURCES = \
	ocelot/trace/implementation/SharedComputationAnalyzer.cpp
SharedComputationAnalyzer_LDADD = libhydrazine.la libir.la libparser.la \
	libtrace.la
SharedComputationAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## DFG
DFG_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
DFG_SOURCES = ocelot/analysis/test/DFG.cpp
DFG_LDADD = libanalysis.la libir.la libparser.la libhydrazine.la
DFG_LDFLAGS = -static
################################################################################

################################################################################
## CFG
CFG_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
CFG_SOURCES = ocelot/ir/test/CFG.cpp
CFG_LDADD = libir.la libparser.la libhydrazine.la
CFG_LDFLAGS = -static
################################################################################

################################################################################
## Module
Module_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
Module_SOURCES = ocelot/ir/test/Module.cpp
Module_LDADD = libir.la libparser.la libhydrazine.la
Module_LDFLAGS = -static
################################################################################

################################################################################
## TestLexer
TestLexer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestLexer_SOURCES = ocelot/parser/test/TestLexer.cpp
TestLexer_LDADD = libir.la libparser.la libhydrazine.la
TestLexer_LDFLAGS = -static
################################################################################

################################################################################
## TestParser
TestParser_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestParser_SOURCES = ocelot/parser/test/TestParser.cpp
TestParser_LDADD = libir.la libparser.la libhydrazine.la
TestParser_LDFLAGS = -static
################################################################################

################################################################################
## TestEmulator
TestEmulator_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestEmulator_SOURCES = ocelot/executive/test/TestEmulator.cpp
TestEmulator_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la
TestEmulator_LDFLAGS = -static
################################################################################

################################################################################
## TestKernels
TestKernels_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestKernels_SOURCES = ocelot/executive/test/TestKernels.cpp
TestKernels_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la
TestKernels_LDFLAGS = -static
################################################################################

################################################################################
## TestTrace
TestTrace_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestTrace_SOURCES = ocelot/executive/test/TestTrace.cpp
TestTrace_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la
TestTrace_LDFLAGS = -static
################################################################################

################################################################################
## TestMemoryTraceGenerator
TestMemoryTraceGenerator_CXXFLAGS = $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
TestMemoryTraceGenerator_SOURCES = \
	ocelot/trace/test/TestMemoryTraceGenerator.cpp \
	TestMemoryTraceGenerator_kernel.cu.cpp
TestMemoryTraceGenerator_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la \
	libparser.la libhydrazine.la
TestMemoryTraceGenerator_LDFLAGS = -static

TestMemoryTraceGenerator_kernel.cu.cpp: \
	ocelot/trace/test/TestMemoryTraceGenerator_kernel.cu
	$(NVCC) -arch sm_13 --cuda -o $@ $< $(SDK_CFLAGS)
################################################################################

################################################################################
## TestInstructions
TestInstructions_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestInstructions_SOURCES = ocelot/executive/test/TestInstructions.cpp
TestInstructions_LDADD = libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la
TestInstructions_LDFLAGS = -static
################################################################################


################################################################################
## Headers
nobase_include_HEADERS = 

################################################################################

################################################################################
## Regression tests
ocelotTest : regression/ocelotRegression.log

regression/ocelotRegression.log : check
	@echo
	@echo "Running Ocelot unit tests"
	@python hydrazine/python/RunRegression.py \
		-t regression/ocelotRegressionTests.txt \
		-l regression/ocelotRegression.log -v

test : ocelotTest

################################################################################

################################################################################
## Extra clean rules
CLEANFILES = ptxgrammar.h ptxgrammar.cpp ptx.cpp ptx1_4grammar.h \
	ptx1_4grammar.cpp
CLEANFILES += *.linkinfo *.cu.cpp 
################################################################################

