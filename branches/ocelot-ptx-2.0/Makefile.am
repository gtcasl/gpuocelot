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
INCLUDE = -I $(srcdir)/ocelot/cuda/include
AM_LDFLAGS = 
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
################################################################################

################################################################################
## Programs and Libraries
BUILT_SOURCES=ptxgrammar.h
bin_PROGRAMS = PTXOptimizer OcelotConfig
check_PROGRAMS = TestLexer TestParser \
	TestEmulator TestInstructions TestKernels \
	TestDataflowGraph TestLLVMInstructions \
	TestPTXToLLVMTranslator  TestGPUKernel  \
	TestCudaGlobals TestCudaMalloc TestCudaTexture2D TestCudaTextureArray \
	TestCudaSequence TestLLVMKernels TestDeviceSwitching \
	TestCalVectorScale TestPTXAssembly
EXTRA_PROGRAMS = Module PtxToLlvmTranslator DFG CFG PTXChecker \
	MemoryTraceAnalyzer InstructionTraceAnalyzer BranchTraceAnalyzer \
	ParallelismTraceAnalyzer SharedComputationAnalyzer
lib_LTLIBRARIES = libocelot.la
################################################################################

################################################################################
## libocelot
libocelot_la_CXXFLAGS = $(LLVM_CFLAGS) $(INCLUDE) -Wall -ansi -Werror -std=c++0x
libocelot_la_SOURCES = \
	ocelot/analysis/implementation/DataflowGraph.cpp \
	ocelot/analysis/implementation/SSAGraph.cpp \
	ocelot/analysis/implementation/Pass.cpp \
	ocelot/analysis/implementation/RemoveBarrierPass.cpp \
	ocelot/analysis/implementation/ConvertPredicationToSelectPass.cpp \
	ocelot/analysis/implementation/LinearScanRegisterAllocationPass.cpp \
	ocelot/api/implementation/ocelot.cpp \
	ocelot/api/implementation/OcelotRuntime.cpp \
	ocelot/api/implementation/OcelotConfiguration.cpp \
	ocelot/ir/implementation/ControlFlowGraph.cpp \
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
	ocelot/ir/implementation/LLVMStatement.cpp \
	ocelot/ir/implementation/Dim3.cpp \
	ocelot/ir/implementation/Local.cpp \
	ocelot/ir/implementation/ILInstruction.cpp \
	ocelot/ir/implementation/ILKernel.cpp \
	ocelot/ir/implementation/ILStatement.cpp \
	hydrazine/implementation/Exception.cpp \
	hydrazine/implementation/Timer.cpp \
	hydrazine/implementation/LowLevelTimer.cpp \
	hydrazine/implementation/ArgumentParser.cpp \
	hydrazine/implementation/math.cpp \
	hydrazine/implementation/debug.cpp \
	hydrazine/implementation/string.cpp \
	hydrazine/implementation/json.cpp \
	hydrazine/interface/Configurable.cpp \
	hydrazine/interface/Test.cpp \
	hydrazine/interface/Stringable.cpp \
	hydrazine/interface/ActiveTimer.cpp \
	hydrazine/interface/Clonable.cpp \
	hydrazine/interface/Thread.cpp \
	hydrazine/interface/Version.cpp \
	ocelot/trace/implementation/TraceEvent.cpp \
	ocelot/trace/implementation/TraceGenerator.cpp \
	ocelot/trace/implementation/BranchTraceGenerator.cpp \
	ocelot/trace/implementation/ParallelismTraceGenerator.cpp \
	ocelot/trace/implementation/SharedComputationGenerator.cpp \
	ocelot/trace/implementation/MemoryTraceGenerator.cpp \
	ocelot/trace/implementation/KernelEntry.cpp \
	ocelot/trace/implementation/CacheSimulator.cpp \
	ocelot/trace/implementation/InstructionTraceGenerator.cpp \
	ocelot/trace/implementation/MemoryChecker.cpp \
	ocelot/trace/implementation/MemoryRaceDetector.cpp \
	ocelot/executive/implementation/ExecutableKernel.cpp \
	ocelot/executive/implementation/Device.cpp \
	ocelot/executive/implementation/ATIGPUDevice.cpp \
	ocelot/executive/implementation/NVIDIAGPUDevice.cpp \
	ocelot/executive/implementation/EmulatorDevice.cpp \
	ocelot/executive/implementation/MulticoreCPUDevice.cpp \
	ocelot/executive/implementation/CTAContext.cpp \
	ocelot/executive/implementation/EmulatedKernel.cpp \
	ocelot/executive/implementation/NVIDIAExecutableKernel.cpp \
	ocelot/executive/implementation/RuntimeException.cpp \
	ocelot/executive/implementation/CooperativeThreadArray.cpp \
	ocelot/executive/implementation/LLVMExecutableKernel.cpp \
	ocelot/executive/implementation/LLVMContext.cpp \
	ocelot/executive/implementation/TextureOperations.cpp \
	ocelot/cuda/implementation/cuda_runtime.cpp \
	ocelot/cuda/implementation/CudaRuntime.cpp \
	ocelot/cuda/implementation/CudaDriver.cpp \
	ocelot/cuda/implementation/CudaRuntimeInterface.cpp \
	ocelot/cal/implementation/CalDriver.cpp \
	ocelot/parser/implementation/ptx.lpp \
	ocelot/parser/implementation/ptxgrammar.ypp \
	ocelot/parser/implementation/PTXParser.cpp \
	ocelot/parser/implementation/PTXLexer.cpp \
	ocelot/translator/implementation/Translator.cpp \
	ocelot/translator/implementation/PTXToLLVMTranslator.cpp \
	ocelot/translator/implementation/PTXToILTranslator.cpp
	
################################################################################

################################################################################
## OcelotConfig
OcelotConfig_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x \
	-DOCELOT_ABS_PATH="\"${abs_builddir}\"" \
	-DOCELOT_BIN_PATH="\"${bindir}\"" \
	-DOCELOT_LIB_PATH="\"${libdir}\"" -DOCELOT_PREFIX_PATH="\"${prefix}\"" \
	-DOCELOT_INCLUDE_PATH="\"${includedir}\""
OcelotConfig_SOURCES = ocelot/util/implementation/OcelotConfig.cpp
OcelotConfig_LDADD = libocelot.la
OcelotConfig_LDFLAGS = -static
################################################################################

################################################################################
## PTXOptimizer
PTXOptimizer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
PTXOptimizer_SOURCES = ocelot/analysis/implementation/PTXOptimizer.cpp
PTXOptimizer_LDADD = libocelot.la
PTXOptimizer_LDFLAGS = -static
################################################################################

################################################################################
## DFG
DFG_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
DFG_SOURCES = ocelot/analysis/test/DFG.cpp
DFG_LDADD = libocelot.la $(LLVM_LDFLAGS)
DFG_LDFLAGS = -static
################################################################################

################################################################################
## CFG
CFG_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
CFG_SOURCES = ocelot/ir/test/CFG.cpp
CFG_LDADD = libocelot.la $(LLVM_LDFLAGS)
CFG_LDFLAGS = -static
################################################################################

################################################################################
## Module
Module_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
Module_SOURCES = ocelot/ir/test/Module.cpp
Module_LDADD = libocelot.la $(LLVM_LDFLAGS)
Module_LDFLAGS = -static
################################################################################

################################################################################
## PtxToLlvmTranslator
PtxToLlvmTranslator_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
PtxToLlvmTranslator_SOURCES = ocelot/translator/test/PtxToLlvmTranslator.cpp
PtxToLlvmTranslator_LDADD = libocelot.la $(LLVM_LDFLAGS)
PtxToLlvmTranslator_LDFLAGS = -static
################################################################################

################################################################################
## ParallelismTraceAnalyzer
ParallelismTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
ParallelismTraceAnalyzer_SOURCES = ocelot/trace/implementation/ParallelismTraceAnalyzer.cpp
ParallelismTraceAnalyzer_LDADD = libocelot.la $(LLVM_LDFLAGS)
ParallelismTraceAnalyzer_LDFLAGS = -static
################################################################################
	
################################################################################
## InstructionTraceAnalyzer
InstructionTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
InstructionTraceAnalyzer_SOURCES = ocelot/trace/implementation/InstructionTraceAnalyzer.cpp
InstructionTraceAnalyzer_LDADD = libocelot.la $(LLVM_LDFLAGS)
InstructionTraceAnalyzer_LDFLAGS = -static
################################################################################
	
################################################################################
## BranchTraceAnalyzer
BranchTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
BranchTraceAnalyzer_SOURCES = ocelot/trace/implementation/BranchTraceAnalyzer.cpp
BranchTraceAnalyzer_LDADD = libocelot.la $(LLVM_LDFLAGS)
BranchTraceAnalyzer_LDFLAGS = -static
################################################################################
	
################################################################################
## SharedComputationAnalyzer
SharedComputationAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
SharedComputationAnalyzer_SOURCES = ocelot/trace/implementation/SharedComputationAnalyzer.cpp
SharedComputationAnalyzer_LDADD = libocelot.la $(LLVM_LDFLAGS)
SharedComputationAnalyzer_LDFLAGS = -static
################################################################################
	
################################################################################
## MemoryTraceAnalyzer
MemoryTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
MemoryTraceAnalyzer_SOURCES = ocelot/trace/implementation/MemoryTraceAnalyzer.cpp
MemoryTraceAnalyzer_LDADD = libocelot.la $(LLVM_LDFLAGS)
MemoryTraceAnalyzer_LDFLAGS = -static
################################################################################

################################################################################
## TestLexer
TestLexer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestLexer_SOURCES = ocelot/parser/test/TestLexer.cpp
TestLexer_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestLexer_LDFLAGS = -static
################################################################################

################################################################################
## TestParser
TestParser_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestParser_SOURCES = ocelot/parser/test/TestParser.cpp
TestParser_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestParser_LDFLAGS = -static
################################################################################

################################################################################
## TestEmulator
TestEmulator_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestEmulator_SOURCES = ocelot/executive/test/TestEmulator.cpp
TestEmulator_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestEmulator_LDFLAGS = -static
################################################################################

################################################################################
## TestKernels
TestKernels_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestKernels_SOURCES = ocelot/executive/test/TestKernels.cpp
TestKernels_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestKernels_LDFLAGS = -static
################################################################################

################################################################################
## TestGPUKernel
TestGPUKernel_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestGPUKernel_SOURCES = ocelot/executive/test/TestGPUKernel.cpp
TestGPUKernel_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestGPUKernel_LDFLAGS = -static
################################################################################

################################################################################
## PTXChecker
PTXChecker_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
PTXChecker_SOURCES = ocelot/executive/test/PTXChecker.cpp
PTXChecker_LDADD = libocelot.la $(LLVM_LDFLAGS) $(CUDA_LDFLAGS)
PTXChecker_LDFLAGS = -static
################################################################################

################################################################################
## TestInstructions
TestInstructions_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestInstructions_SOURCES = ocelot/executive/test/TestInstructions.cpp
TestInstructions_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestInstructions_LDFLAGS = -static
################################################################################

################################################################################
## TestDataflowGraph
TestDataflowGraph_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestDataflowGraph_SOURCES = ocelot/analysis/test/TestDataflowGraph.cpp
TestDataflowGraph_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestDataflowGraph_LDFLAGS = -static
################################################################################

################################################################################
## TestLLVMInstructions
TestLLVMInstructions_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestLLVMInstructions_SOURCES = ocelot/ir/test/TestLLVMInstructions.cpp
TestLLVMInstructions_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestLLVMInstructions_LDFLAGS = -static
################################################################################

################################################################################
## TestPTXToLLVMTranslator
TestPTXToLLVMTranslator_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestPTXToLLVMTranslator_SOURCES = \
	ocelot/translator/test/TestPTXToLLVMTranslator.cpp
TestPTXToLLVMTranslator_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestPTXToLLVMTranslator_LDFLAGS = -static
################################################################################

################################################################################
## TestLLVMKernels
TestLLVMKernels_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
TestLLVMKernels_SOURCES = \
	ocelot/executive/test/TestLLVMKernels.cpp
TestLLVMKernels_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestLLVMKernels_LDFLAGS = -static
################################################################################

################################################################################
##
##
TestCudaGlobals_CXXFLAGS = $(SDK_CFLAGS)
TestCudaGlobals_SOURCES = \
	ocelot/cuda/test/globals/global.cu.cpp
TestCudaGlobals_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCudaGlobals_LDFLAGS = -static
################################################################################

################################################################################
##
##
TestCudaMalloc_CXXFLAGS = $(SDK_CFLAGS)
TestCudaMalloc_SOURCES = \
	ocelot/cuda/test/memory/malloc.cu.cpp
TestCudaMalloc_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCudaMalloc_LDFLAGS = -static
################################################################################

################################################################################
##
##
TestCudaTexture2D_CXXFLAGS = $(SDK_CFLAGS)
TestCudaTexture2D_SOURCES = ocelot/cuda/test/textures/texture2D.cu.cpp
TestCudaTexture2D_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCudaTexture2D_LDFLAGS = -static
################################################################################

################################################################################
##
##
TestCudaTextureArray_CXXFLAGS = $(SDK_CFLAGS)
TestCudaTextureArray_SOURCES = ocelot/cuda/test/textures/textureArray.cu.cpp
TestCudaTextureArray_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCudaTextureArray_LDFLAGS = -static
################################################################################

################################################################################
##
##
TestCudaSequence_CXXFLAGS = $(SDK_CFLAGS)
TestCudaSequence_SOURCES = ocelot/cuda/test/kernels/sequence.cu.cpp
TestCudaSequence_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCudaSequence_LDFLAGS = -static
################################################################################

################################################################################
## TestDeviceSwitching
TestDeviceSwitching_CXXFLAGS = $(INCLUDE) -Wall -ansi \
	-pedantic -Werror -std=c++0x
TestDeviceSwitching_SOURCES = ocelot/api/test/TestDeviceSwitching.cpp
TestDeviceSwitching_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestDeviceSwitching_LDFLAGS = -static
################################################################################

################################################################################
## TestPTXAssembly
TestPTXAssembly_CXXFLAGS = $(INCLUDE) -Wall -ansi \
	-pedantic -Werror -std=c++0x
TestPTXAssembly_SOURCES = ocelot/ir/test/TestPTXAssembly.cpp
TestPTXAssembly_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestPTXAssembly_LDFLAGS = -static
################################################################################


################################################################################
##
##
TestCalVectorScale_CXXFLAGS = $(SDK_CFLAGS)
TestCalVectorScale_SOURCES = \
	ocelot/cal/test/vectorScale.cu.cpp
TestCalVectorScale_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCalVectorScale_LDFLAGS = -static
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = ocelot/api/interface/ocelot.h \
	ocelot/api/interface/OcelotConfiguration.h \
	ocelot/api/interface/OcelotRuntime.h \
	ocelot/api/test/TestDeviceSwitching.h \
	ocelot/executive/interface/CooperativeThreadArray.h \
	ocelot/executive/interface/EmulatedKernel.h \
	ocelot/executive/interface/RuntimeException.h \
	ocelot/executive/interface/Device.h \
	ocelot/executive/interface/ATIGPUDevice.h \
	ocelot/executive/interface/NVIDIAGPUDevice.h \
	ocelot/executive/interface/EmulatorDevice.h \
	ocelot/executive/interface/MulticoreCPUDevice.h \
	ocelot/executive/interface/CTAContext.h \
	ocelot/executive/interface/ExternalKernel.h \
	ocelot/executive/interface/NVIDIAExecutableKernel.h \
	ocelot/executive/interface/LLVMContext.h \
	ocelot/executive/interface/LLVMExecutableKernel.h \
	ocelot/executive/interface/TextureOperations.h \
	ocelot/executive/interface/ExecutableKernel.h \
	ocelot/executive/test/TestEmulator.h \
	ocelot/executive/test/sequence.ptx \
	ocelot/executive/test/kernels.ptx \
	ocelot/executive/test/TestGPUKernel.h \
	ocelot/executive/test/TestLLVMKernels.h \
	ocelot/cuda/interface/CudaRuntime.h \
	ocelot/cuda/interface/CudaDriver.h \
	ocelot/cuda/interface/cuda_runtime.h \
	ocelot/cuda/interface/CudaRuntimeInterface.h \
	ocelot/cuda/interface/TraceGeneratingCudaRuntime.h \
	ocelot/cuda/interface/cuda.h \
	ocelot/trace/interface/MemoryTraceGenerator.h \
	ocelot/trace/interface/TraceEvent.h \
	ocelot/trace/interface/BranchTraceAnalyzer.h \
	ocelot/trace/interface/TraceGenerator.h \
	ocelot/trace/interface/SharedComputationGenerator.h \
	ocelot/trace/interface/ParallelismTraceGenerator.h \
	ocelot/trace/interface/MemoryTraceAnalyzer.h \
	ocelot/trace/interface/SharedComputationAnalyzer.h \
	ocelot/trace/interface/BranchTraceGenerator.h \
	ocelot/trace/interface/ParallelismTraceAnalyzer.h \
	ocelot/trace/interface/KernelEntry.h \
	ocelot/trace/interface/CacheSimulator.h \
	ocelot/trace/interface/InstructionTraceGenerator.h \
	ocelot/trace/interface/MachineAttributesGenerator.h \
	ocelot/trace/interface/InstructionTraceAnalyzer.h \
	ocelot/trace/interface/KernelDimensionsGenerator.h \
	ocelot/trace/interface/WatchTraceGenerator.h \
	ocelot/trace/interface/MemoryRaceDetector.h \
	ocelot/trace/interface/MemoryChecker.h \
	ocelot/parser/interface/PTXLexer.h \
	ocelot/parser/interface/Parser.h \
	ocelot/parser/interface/PTXParser.h \
	ocelot/parser/test/TestLexer.h \
	ocelot/parser/test/TestParser.h \
	ocelot/analysis/interface/DataflowGraph.h \
	ocelot/analysis/interface/Pass.h \
	ocelot/analysis/interface/SSAGraph.h \
	ocelot/analysis/interface/ConvertPredicationToSelectPass.h \
	ocelot/analysis/interface/LinearScanRegisterAllocationPass.h \
	ocelot/analysis/interface/PTXOptimizer.h \
	ocelot/analysis/interface/RemoveBarrierPass.h \
	ocelot/analysis/test/TestDataflowGraph.h \
	ocelot/ir/interface/Kernel.h \
	ocelot/ir/interface/Module.h \
	ocelot/ir/interface/ControlFlowGraph.h \
	ocelot/ir/interface/PostdominatorTree.h \
	ocelot/ir/interface/Parameter.h \
	ocelot/ir/interface/PTXKernel.h \
	ocelot/ir/interface/Dim3.h \
	ocelot/ir/interface/LLVMInstruction.h \
	ocelot/ir/interface/LLVMKernel.h \
	ocelot/ir/interface/LLVMStatement.h \
	ocelot/ir/interface/Local.h	\
	ocelot/ir/interface/PTXStatement.h \
	ocelot/ir/interface/PTXInstruction.h \
	ocelot/ir/interface/Instruction.h \
	ocelot/ir/interface/DominatorTree.h \
	ocelot/ir/interface/Documentation.h \
	ocelot/ir/interface/PTXOperand.h \
	ocelot/ir/interface/Global.h \
	ocelot/ir/interface/Texture.h \
	ocelot/ir/test/TestLLVMInstructions.h \
	ocelot/ir/test/SamplePTX.h \
	ocelot/ir/test/TestPTXAssembly.h \
	ocelot/ir/interface/ILInstruction.h \
	ocelot/ir/interface/ILStatement.h \
	ocelot/ir/interface/ILKernel.h \
	ocelot/cal/interface/CalDriver.h \
	ocelot/cal/include/calcl.h \
	ocelot/cal/include/cal.h \
	ocelot/translator/interface/PTXToILTranslator.h \
	ocelot/translator/interface/PTXToLLVMTranslator.h \
	ocelot/translator/interface/Translator.h \
	ocelot/translator/test/PtxToLlvmTranslator.h \
	ocelot/translator/test/TestPTXToLLVMTranslator.h \
	ocelot/util/interface/OcelotConfig.h \
	hydrazine/implementation/Exception.h \
	hydrazine/implementation/Timer.h \
	hydrazine/implementation/LowLevelTimer.h \
	hydrazine/implementation/ArgumentParser.h \
	hydrazine/implementation/math.h \
	hydrazine/implementation/debug.h \
	hydrazine/implementation/string.h \
	hydrazine/implementation/macros.h \
	hydrazine/implementation/json.h \
	hydrazine/interface/Casts.h \
	hydrazine/interface/Configurable.h \
	hydrazine/interface/Test.h \
	hydrazine/interface/Stringable.h \
	hydrazine/interface/ActiveTimer.h \
	hydrazine/interface/Clonable.h \
	hydrazine/interface/Thread.h \
	hydrazine/interface/Thread.hpp \
	hydrazine/interface/Version.h \
	hydrazine/python/RunRegression.py \
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
CLEANFILES = ptxgrammar.h ptxgrammar.cpp ptx.cpp
CLEANFILES += *.linkinfo *.cu.cpp 
################################################################################

