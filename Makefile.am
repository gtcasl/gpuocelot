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
	TestPTXToLLVMTranslator TestCudaGlobals TestCudaMalloc TestCudaTexture2D \
	TestCudaTextureArray TestCudaTexture3D \
	TestCudaSequence TestLLVMKernels TestDeviceSwitching \
	TestCalVectorScale TestPTXAssembly TestGenericMemory \
	TestFunctionCall TestIndirectFunctionCall TestIndirectFunctionCallOcelot \
	KernelTestHarness
EXTRA_PROGRAMS = Module PtxToIlTranslator DFG CFG PTXChecker \
	OcelotServer TestOcelotServer DB
lib_LTLIBRARIES = libocelot.la libKernelExtractor.la

################################################################################
## libocelot
libocelot_la_CXXFLAGS = $(LLVM_CFLAGS) $(INCLUDE) -Wall -ansi -Werror \
	-std=c++0x
libocelot_la_SOURCES = \
	ocelot/parser/implementation/ptx.lpp \
	ocelot/parser/implementation/ptxgrammar.ypp \
	ocelot/parser/implementation/PTXParser.cpp \
	ocelot/parser/implementation/PTXLexer.cpp \
	ocelot/analysis/implementation/DataflowGraph.cpp \
	ocelot/analysis/implementation/SSAGraph.cpp \
	ocelot/analysis/implementation/Pass.cpp \
	ocelot/analysis/implementation/PassManager.cpp \
	ocelot/analysis/implementation/RemoveBarrierPass.cpp \
	ocelot/analysis/implementation/AssignFallThroughEdge.cpp \
	ocelot/analysis/implementation/StructuralTransform.cpp \
	ocelot/analysis/implementation/StructuralAnalysis.cpp \
	ocelot/analysis/implementation/ConvertPredicationToSelectPass.cpp \
	ocelot/analysis/implementation/LinearScanRegisterAllocationPass.cpp \
	ocelot/analysis/implementation/SubkernelFormationPass.cpp \
	ocelot/analysis/implementation/MIMDThreadSchedulingPass.cpp \
	ocelot/analysis/implementation/ClockCycleCountPass.cpp \
	ocelot/analysis/implementation/BasicBlockInstrumentationPass.cpp \
    ocelot/analysis/implementation/BasicBlockExecutionCountPass.cpp \
    ocelot/analysis/implementation/DynamicInstructionCountPass.cpp \
    ocelot/analysis/implementation/PTXInstrumentor.cpp \
    ocelot/analysis/implementation/ClockCycleCountInstrumentor.cpp \
    ocelot/analysis/implementation/BasicBlockInstrumentor.cpp \
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
	ocelot/ir/implementation/ILOperand.cpp \
	ocelot/ir/implementation/ControlTree.cpp \
	hydrazine/implementation/Exception.cpp \
	hydrazine/implementation/Timer.cpp \
	hydrazine/implementation/LowLevelTimer.cpp \
	hydrazine/implementation/ArgumentParser.cpp \
	hydrazine/implementation/math.cpp \
	hydrazine/implementation/debug.cpp \
	hydrazine/implementation/string.cpp \
	hydrazine/implementation/json.cpp \
	hydrazine/implementation/SystemCompatibility.cpp \
	hydrazine/interface/Configurable.cpp \
	hydrazine/interface/Test.cpp \
	hydrazine/interface/Stringable.cpp \
	hydrazine/interface/Clonable.cpp \
	hydrazine/interface/Thread.cpp \
	hydrazine/interface/Version.cpp \
	ocelot/trace/implementation/TraceEvent.cpp \
	ocelot/trace/implementation/TraceGenerator.cpp \
	ocelot/trace/implementation/MemoryChecker.cpp \
	ocelot/trace/implementation/MemoryRaceDetector.cpp \
	ocelot/trace/implementation/InteractiveDebugger.cpp \
	ocelot/executive/implementation/ExecutableKernel.cpp \
	ocelot/executive/implementation/Device.cpp \
	ocelot/executive/implementation/ATIGPUDevice.cpp \
	ocelot/executive/implementation/NVIDIAGPUDevice.cpp \
	ocelot/executive/implementation/EmulatorDevice.cpp \
	ocelot/executive/implementation/MulticoreCPUDevice.cpp \
	ocelot/executive/implementation/PassThroughDevice.cpp \
	ocelot/executive/implementation/CTAContext.cpp \
	ocelot/executive/implementation/EmulatorCallStack.cpp \
	ocelot/executive/implementation/EmulatedKernel.cpp \
	ocelot/executive/implementation/NVIDIAExecutableKernel.cpp \
	ocelot/executive/implementation/ATIExecutableKernel.cpp \
	ocelot/executive/implementation/RuntimeException.cpp \
	ocelot/executive/implementation/ReconvergenceMechanism.cpp \
	ocelot/executive/implementation/CooperativeThreadArray.cpp \
	ocelot/executive/implementation/LLVMExecutableKernel.cpp \
	ocelot/executive/implementation/LLVMModuleManager.cpp \
	ocelot/executive/implementation/LLVMExecutionManager.cpp \
	ocelot/executive/implementation/LLVMState.cpp \
	ocelot/executive/implementation/LLVMWorkerThread.cpp \
	ocelot/executive/implementation/LLVMCooperativeThreadArray.cpp \
	ocelot/executive/implementation/LLVMFunctionCallStack.cpp \
	ocelot/executive/implementation/LLVMContext.cpp \
	ocelot/executive/implementation/TextureOperations.cpp \
	ocelot/executive/implementation/RemoteDevice.cpp \
	ocelot/cuda/implementation/CudaDriverApi.cpp \
	ocelot/cuda/implementation/CudaDriver.cpp \
	ocelot/cuda/implementation/CudaDriverInterface.cpp \
	ocelot/cuda/implementation/CudaDriverFrontend.cpp \
	ocelot/cuda/implementation/CudaRuntimeInterface.cpp \
	ocelot/cuda/implementation/CudaRuntime.cpp \
	ocelot/cuda/implementation/cuda_runtime.cpp \
	ocelot/cuda/implementation/FatBinaryContext.cpp \
	ocelot/cal/implementation/CalDriver.cpp \
	ocelot/translator/implementation/Translator.cpp \
	ocelot/translator/implementation/PTXToLLVMTranslator.cpp \
	ocelot/translator/implementation/PTXToILTranslator.cpp \
	ocelot/util/implementation/RemoteDeviceMessage.cpp \
	ocelot/graphs/implementation/DirectionalGraph.cpp \
	ocelot/graphs/implementation/DivergenceDrawer.cpp \
	ocelot/graphs/implementation/DivergenceGraph.cpp \
	ocelot/analysis/implementation/DivergenceAnalysis.cpp \
	ocelot/analysis/implementation/BranchInfo.cpp \
	ocelot/analysis/implementation/SyncEliminationPass.cpp \
	ocelot/analysis/test/DB.cpp
	
	
################################################################################

################################################################################
## OcelotConfig
OcelotConfig_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x \
	-DOCELOT_ABS_PATH="\"${abs_builddir}\"" \
	-DOCELOT_BIN_PATH="\"${bindir}\"" \
	-DOCELOT_LIB_PATH="\"${libdir}\"" -DOCELOT_PREFIX_PATH="\"${prefix}\"" \
	-DOCELOT_INCLUDE_PATH="\"${includedir}\""
OcelotConfig_SOURCES = ocelot/util/implementation/OcelotConfig.cpp
OcelotConfig_LDADD = libocelot.la $(LLVM_LDFLAGS) 
OcelotConfig_LDFLAGS = -static
################################################################################

################################################################################
## OcelotServer
OcelotServer_CXXFLAGS = $(INCLUDE) -std=c++0x
OcelotServer_SOURCES = ocelot/util/implementation/OcelotServer.cpp \
	ocelot/util/implementation/OcelotServerConnection.cpp
OcelotServer_LDADD = libocelot.la $(LLVM_LDFLAGS)
OcelotServer_LDFLAGS = -static
################################################################################
################################################################################
## TestOcelotServer
TestOcelotServer_CXXFLAGS = $(INCLUDE) -std=c++0x
TestOcelotServer_SOURCES = ocelot/util/test/TestOcelotServer.cpp
TestOcelotServer_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestOcelotServer_LDFLAGS = -static
################################################################################

################################################################################
## PTXOptimizer
PTXOptimizer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
PTXOptimizer_SOURCES = ocelot/analysis/implementation/PTXOptimizer.cpp
PTXOptimizer_LDADD = libocelot.la $(LLVM_LDFLAGS)
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
## DB
DB_CXXFLAGS = -Wall -pedantic -std=c++0x
DB_SOURCES = ocelot/analysis/test/DB.cpp
DB_LDADD = libocelot.la $(LLVM_LDFLAGS)
DB_LDFLAGS = -static
################################################################################

################################################################################
## Module
Module_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
Module_SOURCES = ocelot/ir/test/Module.cpp
Module_LDADD = libocelot.la $(LLVM_LDFLAGS)
Module_LDFLAGS = -static
################################################################################

################################################################################
## PtxToIlTranslator
PtxToIlTranslator_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
PtxToIlTranslator_SOURCES = ocelot/translator/test/PtxToIlTranslator.cpp
PtxToIlTranslator_LDADD = libocelot.la $(LLVM_LDFLAGS)
PtxToIlTranslator_LDFLAGS = -static
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
TestCudaTexture3D_CXXFLAGS = $(SDK_CFLAGS)
TestCudaTexture3D_SOURCES = ocelot/cuda/test/textures/texture3D.cu.cpp
TestCudaTexture3D_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCudaTexture3D_LDFLAGS = -static
################################################################################

################################################################################
##
##
TestCudaSequence_CXXFLAGS = $(SDK_CFLAGS)
TestCudaSequence_SOURCES = ocelot/cuda/test/kernels/sequence.cu.cpp
TestCudaSequence_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestCudaSequence_LDFLAGS = -static
################################################################################

#################################################################################
###
###
#TestSequenceDriverAPI_CXXFLAGS = $(SDK_CFLAGS)
#TestSequenceDriverAPI_SOURCES = ocelot/cuda/test/driver/sequence.cpp
#TestSequenceDriverAPI_LDADD = libocelot.la $(LLVM_LDFLAGS)
#TestSequenceDriverAPI_LDFLAGS = -static
#################################################################################

################################################################################
##
##
TestGenericMemory_CXXFLAGS = $(SDK_CFLAGS) -Wall -ansi \
	-pedantic -Werror -std=c++0x
TestGenericMemory_SOURCES = ocelot/cuda/test/memory/generic.cpp
TestGenericMemory_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestGenericMemory_LDFLAGS = -static
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
## TestFunctionCall
TestFunctionCall_CXXFLAGS = $(INCLUDE) -std=c++0x
TestFunctionCall_SOURCES = ocelot/cuda/test/functions/simpleFunc.cu.cpp
TestFunctionCall_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestFunctionCall_LDFLAGS = -static
################################################################################

################################################################################
## TestIndirectFunctionCall
TestIndirectFunctionCall_CXXFLAGS = $(INCLUDE) -std=c++0x
TestIndirectFunctionCall_SOURCES = ocelot/cuda/test/functions/indirectCall.cu.cpp
TestIndirectFunctionCall_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestIndirectFunctionCall_LDFLAGS = -static
################################################################################
################################################################################
## TestIndirectFunctionCall
TestIndirectFunctionCallOcelot_CXXFLAGS = $(INCLUDE) -std=c++0x
TestIndirectFunctionCallOcelot_SOURCES = ocelot/cuda/test/functions/indirectCallOcelot.cpp
TestIndirectFunctionCallOcelot_LDADD = libocelot.la $(LLVM_LDFLAGS)
TestIndirectFunctionCallOcelot_LDFLAGS = -static
################################################################################

################################################################################

libKernelExtractor_la_CXXFLAGS = -Wall -ansi -Werror -std=c++0x
#libKernelExtractor_la_HEADERS = ocelot/util/interface/KernelExtractor.h
libKernelExtractor_la_LDFLAGS = -module
libKernelExtractor_la_SOURCES = ocelot/util/implementation/KernelExtractor.cpp \
	ocelot/util/implementation/ExtractedDeviceState.cpp \
	ocelot/cuda/implementation/FatBinaryContext.cpp \
	ocelot/cuda/implementation/CudaDriverApi.cpp \
	ocelot/cuda/implementation/CudaDriverInterface.cpp \
	ocelot/cuda/implementation/CudaDriver.cpp \
	ocelot/ir/implementation/Texture.cpp \
	ocelot/ir/implementation/PTXOperand.cpp \
	ocelot/ir/implementation/Dim3.cpp \
	hydrazine/implementation/Exception.cpp \
	hydrazine/implementation/Timer.cpp \
	hydrazine/implementation/LowLevelTimer.cpp \
	hydrazine/implementation/ArgumentParser.cpp \
	hydrazine/implementation/math.cpp \
	hydrazine/implementation/debug.cpp \
	hydrazine/implementation/string.cpp \
	hydrazine/implementation/json.cpp \
	hydrazine/implementation/SystemCompatibility.cpp \
	hydrazine/interface/Configurable.cpp \
	hydrazine/interface/Test.cpp \
	hydrazine/interface/Stringable.cpp \
	hydrazine/interface/Clonable.cpp \
	hydrazine/interface/Thread.cpp \
	hydrazine/interface/Version.cpp

################################################################################
## KernelTestHarness
KernelTestHarness_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
KernelTestHarness_SOURCES = ocelot/util/implementation/KernelTestHarness.cpp \
	ocelot/util/implementation/ExtractedDeviceState.cpp
KernelTestHarness_includedir = .
KernelTestHarness_include_HEADERS = ocelot/util/interface/KernelTestHarness.h \
	ocelot/util/interface/ExtractedDeviceState.h
KernelTestHarness_LDADD = libocelot.la $(LLVM_LDFLAGS)
KernelTestHarness_LDFLAGS = -static
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
	ocelot/executive/interface/PassThroughDevice.h \
	ocelot/executive/interface/CTAContext.h \
	ocelot/executive/interface/ExternalKernel.h \
	ocelot/executive/interface/NVIDIAExecutableKernel.h \
	ocelot/executive/interface/ATIExecutableKernel.h \
	ocelot/executive/interface/LLVMContext.h \
	ocelot/executive/interface/LLVMExecutableKernel.h \
	ocelot/executive/interface/TextureOperations.h \
	ocelot/executive/interface/ExecutableKernel.h \
	ocelot/executive/interface/LLVMModuleManager.h \
	ocelot/executive/interface/LLVMExecutionManager.h \
	ocelot/executive/interface/LLVMState.h \
	ocelot/executive/interface/LLVMWorkerThread.h \
	ocelot/executive/interface/LLVMCooperativeThreadArray.h \
	ocelot/executive/interface/LLVMFunctionCallStack.h \
	ocelot/executive/interface/EmulatorCallStack.h \
	ocelot/executive/interface/RemoteDevice.h \
	ocelot/executive/interface/ReconvergenceMechanism.h \
	ocelot/executive/test/TestEmulator.h \
	ocelot/executive/test/sequence.ptx \
	ocelot/executive/test/kernels.ptx \
	ocelot/executive/test/TestLLVMKernels.h \
	ocelot/cuda/interface/CudaRuntime.h \
	ocelot/cuda/interface/CudaDriver.h \
	ocelot/cuda/interface/cuda_runtime.h \
	ocelot/cuda/interface/CudaRuntimeInterface.h \
	ocelot/cuda/interface/TraceGeneratingCudaRuntime.h \
	ocelot/cuda/interface/cuda.h \
	ocelot/cuda/interface/CudaDriverFrontend.h \
	ocelot/cuda/interface/CudaDriverInterface.h \
	ocelot/cuda/interface/CudaRuntimeContext.h \
	ocelot/trace/interface/TraceEvent.h \
	ocelot/trace/interface/TraceGenerator.h \
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
	ocelot/analysis/interface/SubkernelFormationPass.h \
    ocelot/analysis/interface/ClockCycleCountPass.h \
    ocelot/analysis/interface/BasicBlockExecutionCountPass.h \
	ocelot/analysis/interface/DynamicInstructionCountPass.h \
	ocelot/analysis/interface/PTXOptimizer.h \
	ocelot/analysis/interface/RemoveBarrierPass.h \
	ocelot/analysis/interface/AssignFallThroughEdge.h \
	ocelot/analysis/interface/StructuralAnalysis.h \
	ocelot/analysis/interface/StructuralTransform.h \
	ocelot/analysis/interface/PassManager.h \
    ocelot/analysis/interface/PTXInstrumentor.h \
    ocelot/analysis/interface/ClockCycleCountInstrumentor.h \
    ocelot/analysis/interface/BasicBlockInstrumentor.h \
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
	ocelot/ir/interface/ControlTree.h \
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
	ocelot/translator/test/TestPTXToLLVMTranslator.h \
	ocelot/translator/test/PtxToIlTranslator.h \
	ocelot/util/interface/OcelotConfig.h \
	ocelot/util/interface/RemoteDeviceMessage.h \
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
	hydrazine/interface/Clonable.h \
	hydrazine/interface/Thread.h \
	hydrazine/interface/Thread.hpp \
	hydrazine/interface/SystemCompatibility.h \
	hydrazine/interface/Version.h \
	hydrazine/python/RunRegression.py \
	regression/ocelotRegressionTests.txt\
	ocelot/graphs/interface/DirectionalGraph.h \
	ocelot/graphs/interface/DivergenceDrawer.h \
	ocelot/graphs/interface/DivergenceGraph.h \
	ocelot/analysis/interface/DivergenceAnalysis.h \
	ocelot/analysis/interface/BranchInfo.h \
	ocelot/analysis/interface/SyncEliminationPass.h

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

query:
	@echo $(LLVM_LDFLAGS)

################################################################################

################################################################################
## Extra clean rules
CLEANFILES = ptxgrammar.h ptxgrammar.cpp ptx.cpp
CLEANFILES += *.linkinfo *.cu.cpp 
################################################################################

