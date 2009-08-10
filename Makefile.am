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
INCLUDE = -I ocelot/cuda/include
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
################################################################################

################################################################################
## Programs and Libraries
BUILT_SOURCES=ptx1_4grammar.h
bin_PROGRAMS = DFG CFG Module BranchTraceAnalyzer MemoryTraceAnalyzer \
	ParallelismTraceAnalyzer SharedComputationAnalyzer PtxToLlvmTranslator
check_PROGRAMS = TestLexer TestParser \
	TestEmulator TestInstructions TestKernels TestTrace \
	TestMemoryTraceGenerator TestDataflowGraph TestLLVMInstructions
lib_LTLIBRARIES = libOcelotIr.la libOcelotAnalysis.la libOcelotParser.la \
	libhydrazine.la libOcelotExecutive.la libOcelotTrace.la libcudart.la \
	libOcelot.la libOcelotTranslator.la
################################################################################

################################################################################
## libOcelotAnalysis
libOcelotAnalysis_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
libOcelotAnalysis_la_SOURCES = \
	ocelot/analysis/implementation/DataflowGraph.cpp \
	ocelot/analysis/implementation/SSAGraph.cpp
################################################################################

################################################################################
## libOcelot
libOcelot_la_CXXFLAGS = $(INCLUDE) -Wall -ansi -pedantic -Werror -std=c++0x
libOcelot_la_SOURCES = ocelot/api/implementation/ocelot.cpp
################################################################################

################################################################################
## libOcelotIr
libOcelotIr_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
libOcelotIr_la_SOURCES = ocelot/ir/implementation/BasicBlock.cpp \
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
	ocelot/ir/implementation/PostdominatorTree.cpp \
	ocelot/ir/implementation/LLVMInstruction.cpp \
	ocelot/ir/implementation/LLVMKernel.cpp \
	ocelot/ir/implementation/LLVMStatement.cpp
################################################################################

################################################################################
## libhydrazine
libhydrazine_la_CXXFLAGS = $(INCLUDE) -Wall -ansi -pedantic -Werror -std=c++0x
libhydrazine_la_SOURCES = \
	hydrazine/implementation/Exception.cpp \
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
## libOcelotTrace
libOcelotTrace_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
libOcelotTrace_la_SOURCES = \
	ocelot/trace/implementation/TraceEvent.cpp \
	ocelot/trace/implementation/TraceGenerator.cpp \
	ocelot/trace/implementation/BranchTraceGenerator.cpp \
	ocelot/trace/implementation/MemoryTraceGenerator.cpp \
	ocelot/trace/implementation/ParallelismTraceGenerator.cpp \
	ocelot/trace/implementation/SharedComputationGenerator.cpp \
	ocelot/trace/implementation/KernelEntry.cpp \
	ocelot/trace/implementation/BranchEvent.cpp	
################################################################################

################################################################################
## libOcelotExecutive
libOcelotExecutive_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
libOcelotExecutive_la_SOURCES = \
	ocelot/executive/implementation/Device.cpp \
	ocelot/executive/implementation/Executive.cpp \
	ocelot/executive/implementation/CTAContext.cpp \
	ocelot/executive/implementation/EmulatedKernel.cpp \
	ocelot/executive/implementation/RuntimeException.cpp \
	ocelot/executive/implementation/CooperativeThreadArray.cpp
################################################################################

################################################################################
## libOcelotParser
libOcelotParser_la_CXXFLAGS = -I ocelot -Wall -ansi -Werror -std=c++0x
libOcelotParser_la_SOURCES = \
	ocelot/parser/implementation/ptx.lpp \
	ocelot/parser/implementation/ptxgrammar.ypp \
	ocelot/parser/implementation/ptx1_4grammar.ypp \
	ocelot/parser/implementation/PTXParser.cpp \
	ocelot/parser/implementation/PTXLexer.cpp
################################################################################

################################################################################
## libcudart
libcudart_la_CXXFLAGS = $(INCLUDE) -Wall -ansi -pedantic -Werror -std=c++0x
libcudart_la_SOURCES = \
	ocelot/cuda/implementation/OcelotRuntimeApi.cpp \
	ocelot/cuda/implementation/CudaRuntime.cpp
libcudart_la_LDFLAGS = -version-info 2:3:0
################################################################################

################################################################################
## libOcelotTranslator
libOcelotTranslator_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
libOcelotTranslator_la_SOURCES = \
	ocelot/translator/implementation/Translator.cpp \
	ocelot/translator/implementation/PTXToLLVMTranslator.cpp
################################################################################

################################################################################
## ParallelismTraceAnalyzer
ParallelismTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
ParallelismTraceAnalyzer_SOURCES = \
	ocelot/trace/implementation/ParallelismTraceAnalyzer.cpp
ParallelismTraceAnalyzer_LDADD =libOcelotIr.la \
	libOcelotParser.la libOcelotTrace.la libhydrazine.la 
ParallelismTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## BranchTraceAnalyzer
BranchTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror \
	-std=c++0x
BranchTraceAnalyzer_SOURCES = \
	ocelot/trace/implementation/BranchTraceAnalyzer.cpp
BranchTraceAnalyzer_LDADD = libOcelotIr.la libOcelotParser.la \
	libOcelotTrace.la libhydrazine.la
BranchTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## MemoryTraceAnalyzer
MemoryTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
MemoryTraceAnalyzer_SOURCES = \
	ocelot/trace/implementation/MemoryTraceAnalyzer.cpp
MemoryTraceAnalyzer_LDADD = libOcelotIr.la libOcelotParser.la \
	libOcelotTrace.la libhydrazine.la 
MemoryTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## SharedComputationAnalyzer
SharedComputationAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror \
	-std=c++0x
SharedComputationAnalyzer_SOURCES = \
	ocelot/trace/implementation/SharedComputationAnalyzer.cpp
SharedComputationAnalyzer_LDADD = libOcelotIr.la \
	libOcelotParser.la libOcelotTrace.la libhydrazine.la
SharedComputationAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## DFG
DFG_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
DFG_SOURCES = ocelot/analysis/test/DFG.cpp
DFG_LDADD = libOcelotAnalysis.la libOcelotIr.la libOcelotParser.la \
	libhydrazine.la
DFG_LDFLAGS = -static
################################################################################

################################################################################
## CFG
CFG_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
CFG_SOURCES = ocelot/ir/test/CFG.cpp
CFG_LDADD = libOcelotIr.la libOcelotParser.la libhydrazine.la
CFG_LDFLAGS = -static
################################################################################

################################################################################
## Module
Module_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
Module_SOURCES = ocelot/ir/test/Module.cpp
Module_LDADD = libOcelotIr.la libOcelotParser.la libhydrazine.la
Module_LDFLAGS = -static
################################################################################

################################################################################
## PtxToLlvmTranslator
PtxToLlvmTranslator_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
PtxToLlvmTranslator_SOURCES = ocelot/translator/test/PtxToLlvmTranslator.cpp
PtxToLlvmTranslator_LDADD = libOcelotTranslator.la libOcelotAnalysis.la \
	libOcelotIr.la libOcelotParser.la libhydrazine.la
PtxToLlvmTranslator_LDFLAGS = -static
################################################################################

################################################################################
## TestLexer
TestLexer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestLexer_SOURCES = ocelot/parser/test/TestLexer.cpp
TestLexer_LDADD = libOcelotIr.la libOcelotParser.la libhydrazine.la
TestLexer_LDFLAGS = -static
################################################################################

################################################################################
## TestParser
TestParser_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestParser_SOURCES = ocelot/parser/test/TestParser.cpp
TestParser_LDADD = libOcelotIr.la libOcelotParser.la libhydrazine.la
TestParser_LDFLAGS = -static
################################################################################

################################################################################
## TestEmulator
TestEmulator_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestEmulator_SOURCES = ocelot/executive/test/TestEmulator.cpp
TestEmulator_LDADD = libcudart.la libOcelotExecutive.la libOcelotTrace.la \
	libOcelotIr.la libOcelotParser.la libhydrazine.la
TestEmulator_LDFLAGS = -static
################################################################################

################################################################################
## TestKernels
TestKernels_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestKernels_SOURCES = ocelot/executive/test/TestKernels.cpp
TestKernels_LDADD = libcudart.la libOcelotExecutive.la libOcelotTrace.la \
	libOcelotIr.la libOcelotParser.la libhydrazine.la
TestKernels_LDFLAGS = -static
################################################################################

################################################################################
## TestTrace
TestTrace_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestTrace_SOURCES = ocelot/executive/test/TestTrace.cpp
TestTrace_LDADD = libcudart.la libOcelotExecutive.la libOcelotTrace.la \
	libOcelotIr.la libOcelotParser.la libhydrazine.la
TestTrace_LDFLAGS = -static
################################################################################

################################################################################
## TestMemoryTraceGenerator
TestMemoryTraceGenerator_CXXFLAGS = -Wall -std=c++0x
TestMemoryTraceGenerator_SOURCES = \
	ocelot/trace/test/TestMemoryTraceGenerator.cpp \
	ocelot/trace/test/TestMemoryTraceGenerator_kernel.cu.cpp
TestMemoryTraceGenerator_LDADD = libcudart.la libOcelotExecutive.la \
	libOcelotTrace.la libOcelotIr.la libOcelotParser.la libhydrazine.la
TestMemoryTraceGenerator_LDFLAGS = -static
################################################################################

################################################################################
## TestInstructions
TestInstructions_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestInstructions_SOURCES = ocelot/executive/test/TestInstructions.cpp
TestInstructions_LDADD = libcudart.la libOcelotExecutive.la \
	libOcelotTrace.la libOcelotIr.la libOcelotParser.la libhydrazine.la
TestInstructions_LDFLAGS = -static
################################################################################

################################################################################
## TestDataflowGraph
TestDataflowGraph_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestDataflowGraph_SOURCES = ocelot/analysis/test/TestDataflowGraph.cpp
TestDataflowGraph_LDADD = libOcelotAnalysis.la libOcelotIr.la \
	libOcelotParser.la libhydrazine.la
TestDataflowGraph_LDFLAGS = -static
################################################################################

################################################################################
## TestLLVMInstructions
TestLLVMInstructions_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestLLVMInstructions_SOURCES = ocelot/ir/test/TestLLVMInstructions.cpp
TestLLVMInstructions_LDADD = libOcelotIr.la libhydrazine.la
TestLLVMInstructions_LDFLAGS = -static
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = ocelot/api/interface/ocelot.h \
	ocelot/executive/interface/Executive.h \
	ocelot/executive/interface/CooperativeThreadArray.h \
	ocelot/executive/interface/EmulatedKernel.h \
	ocelot/executive/interface/RuntimeException.h \
	ocelot/executive/interface/GPUKernel.h \
	ocelot/executive/interface/Device.h \
	ocelot/executive/interface/CTAContext.h \
	ocelot/executive/test/TestEmulator.h \
	ocelot/executive/test/TestGPUKernel.h \
	ocelot/executive/test/sequence.ptx \
	ocelot/executive/test/kernels.ptx \
	ocelot/cuda/interface/CudaRuntime.h \
	ocelot/trace/interface/MemoryTraceGenerator.h \
	ocelot/trace/interface/TraceEvent.h \
	ocelot/trace/interface/BranchEvent.h \
	ocelot/trace/interface/BranchTraceAnalyzer.h \
	ocelot/trace/interface/TraceGenerator.h \
	ocelot/trace/interface/SharedComputationGenerator.h \
	ocelot/trace/interface/ParallelismTraceGenerator.h \
	ocelot/trace/interface/MemoryTraceAnalyzer.h \
	ocelot/trace/interface/SharedComputationAnalyzer.h \
	ocelot/trace/interface/BranchTraceGenerator.h \
	ocelot/trace/interface/ParallelismTraceAnalyzer.h \
	ocelot/trace/interface/KernelEntry.h \
	ocelot/parser/interface/PTXLexer.h \
	ocelot/parser/interface/Parser.h \
	ocelot/parser/interface/PTXParser.h \
	ocelot/parser/test/TestLexer.h \
	ocelot/parser/test/TestParser.h \
	ocelot/analysis/interface/DataflowGraph.h \
	ocelot/analysis/interface/SSAGraph.h \
	ocelot/analysis/test/TestDataflowGraph.h \
	ocelot/ir/interface/Kernel.h \
	ocelot/ir/interface/Module.h \
	ocelot/ir/interface/ControlFlowGraph.h \
	ocelot/ir/interface/PostdominatorTree.h \
	ocelot/ir/interface/Parameter.h \
	ocelot/ir/interface/PTXKernel.h \
	ocelot/ir/interface/ExecutableKernel.h \
	ocelot/ir/interface/PTXStatement.h \
	ocelot/ir/interface/PTXInstruction.h \
	ocelot/ir/interface/Instruction.h \
	ocelot/ir/interface/DominatorTree.h \
	ocelot/ir/interface/Documentation.h \
	ocelot/ir/interface/Edge.h \
	ocelot/ir/interface/PTXOperand.h \
	ocelot/ir/interface/BasicBlock.h \
	ocelot/ir/interface/Global.h \
	ocelot/ir/interface/Texture.h \
	ocelot/ir/test/TestLLVMInstructions.h \
	hydrazine/implementation/Exception.h \
	hydrazine/implementation/XmlLexer.h \
	hydrazine/implementation/Timer.h \
	hydrazine/implementation/LowLevelTimer.h \
	hydrazine/implementation/ArgumentParser.h \
	hydrazine/implementation/XmlParser.h \
	hydrazine/implementation/math.h \
	hydrazine/implementation/debug.h \
	hydrazine/implementation/XmlArgumentParser.h \
	hydrazine/implementation/XmlTree.h \
	hydrazine/implementation/string.h \
	hydrazine/implementation/macros.h \
	hydrazine/cuda/Cuda.h \
	hydrazine/interface/Configurable.h \
	hydrazine/interface/Test.h \
	hydrazine/interface/Stringable.h \
	hydrazine/interface/ActiveTimer.h \
	hydrazine/interface/Clonable.h \
	hydrazine/interface/Thread.h \
	hydrazine/interface/Thread.hpp \
	hydrazine/interface/Version.h \
	hydrazine/python/RunRegression.py \
	ocelot/cuda/include/builtin_types.h \
	ocelot/cuda/include/__cudaFatFormat.h \
	ocelot/cuda/include/cuda_runtime_api.h \
	ocelot/cuda/include/device_types.h \
	ocelot/cuda/include/driver_types.h \
	ocelot/cuda/include/host_defines.h \
	ocelot/cuda/include/texture_types.h \
	ocelot/cuda/include/vector_types.h \
	regression/ocelotRegressionTests.txt	

################################################################################

################################################################################
## EXTRA
EXTRA_DIST = regression/ocelotRegressionTests.txt \
	hydrazine/python/RunRegression.py
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

