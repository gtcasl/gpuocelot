################################################################################
#	\file Makefile.am
#	\author Gregory Diamos
#	\date Thursday July 29, 2010
# 	\brief Automake input file describing the programs and sources needed to
#			build the Ocelot
################################################################################

################################################################################
## Global Parameters
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
################################################################################

################################################################################
## Programs and Libraries
BUILT_SOURCES =
bin_PROGRAMS = 
check_PROGRAMS = 
EXTRA_PROGRAMS = MemoryTraceAnalyzer InstructionTraceAnalyzer \
	BranchTraceAnalyzer ParallelismTraceAnalyzer SharedComputationAnalyzer \
	X86TraceGenerator
lib_LTLIBRARIES = libocelotTrace.la
################################################################################

################################################################################
## libocelotTrace
libocelotTrace_la_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
libocelotTrace_la_SOURCES = \
	traces/implementation/BranchTraceGenerator.cpp \
	traces/implementation/ParallelismTraceGenerator.cpp \
	traces/implementation/SharedComputationGenerator.cpp \
	traces/implementation/MemoryTraceGenerator.cpp \
	traces/implementation/CacheSimulator.cpp \
	traces/implementation/InstructionTraceGenerator.cpp \
	traces/implementation/WarpSynchronousGenerator.cpp \
	traces/implementation/PerformanceBoundGenerator.cpp \
	traces/implementation/ConvergenceGenerator.cpp \
	traces/implementation/TraceConfiguration.cpp \
	traces/implementation/LoadBalanceGenerator.cpp \
	traces/implementation/KernelEntry.cpp \
	traces/implementation/ControlFlowVisualizer.cpp \
	traces/implementation/BasicBlockCountGenerator.cpp \
	traces/implementation/X86TraceGenerator.cpp
	
################################################################################


################################################################################
## X86TraceGenerator
X86TraceGenerator_CXXFLGAS = -Wall -ansi -pedantic -Werror -std=x++0x -I ../ocelot/install/include
X86TraceGenerator_SOURCES = \
  traces/implementation/X86TraceGenerator.cpp
X86TraceGenerator_LDADD = libocelotTrace.la
X86TraceGenerator_LDFLGAS = -static $(OCELOT_LDFLAGS)
################################################################################

################################################################################
## ParallelismTraceAnalyzer
ParallelismTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
ParallelismTraceAnalyzer_SOURCES = \
	traces/implementation/ParallelismTraceAnalyzer.cpp
ParallelismTraceAnalyzer_LDADD = libocelotTrace.la
ParallelismTraceAnalyzer_LDFLAGS = -static $(OCELOT_LDFLAGS)
################################################################################
	
################################################################################
## InstructionTraceAnalyzer
InstructionTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
InstructionTraceAnalyzer_SOURCES = \
	traces/implementation/InstructionTraceAnalyzer.cpp
InstructionTraceAnalyzer_LDADD = libocelotTrace.la
InstructionTraceAnalyzer_LDFLAGS = -static $(OCELOT_LDFLAGS)
################################################################################
	
################################################################################
## BranchTraceAnalyzer
BranchTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
BranchTraceAnalyzer_SOURCES = traces/implementation/BranchTraceAnalyzer.cpp
BranchTraceAnalyzer_LDADD = libocelotTrace.la
BranchTraceAnalyzer_LDFLAGS = -static $(OCELOT_LDFLAGS)
################################################################################
	
################################################################################
## SharedComputationAnalyzer
SharedComputationAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
SharedComputationAnalyzer_SOURCES = \
	traces/implementation/SharedComputationAnalyzer.cpp
SharedComputationAnalyzer_LDADD = libocelotTrace.la
SharedComputationAnalyzer_LDFLAGS = -static $(OCELOT_LDFLAGS)
################################################################################
	
################################################################################
## MemoryTraceAnalyzer
MemoryTraceAnalyzer_CXXFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x
MemoryTraceAnalyzer_SOURCES = \
	traces/implementation/MemoryTraceAnalyzer.cpp
MemoryTraceAnalyzer_LDADD = libocelotTrace.la
MemoryTraceAnalyzer_LDFLAGS = -static $(OCELOT_LDFLAGS)
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = traces/interface/MemoryTraceGenerator.h \
	traces/interface/BranchTraceAnalyzer.h \
	traces/interface/SharedComputationGenerator.h \
	traces/interface/ParallelismTraceGenerator.h \
	traces/interface/MemoryTraceAnalyzer.h \
	traces/interface/SharedComputationAnalyzer.h \
	traces/interface/BranchTraceGenerator.h \
	traces/interface/ParallelismTraceAnalyzer.h \
	traces/interface/KernelEntry.h \
	traces/interface/CacheSimulator.h \
	traces/interface/InstructionTraceGenerator.h \
	traces/interface/MachineAttributesGenerator.h \
	traces/interface/InstructionTraceAnalyzer.h \
	traces/interface/KernelDimensionsGenerator.h \
	traces/interface/WatchTraceGenerator.h \
	traces/interface/PerformanceBoundGenerator.h \
	traces/interface/LoadBalanceGenerator.h \
	traces/interface/ConvergenceGenerator.h \
	traces/interface/ControlFlowVisualizer.h \
	traces/interface/BasicBlockCountGenerator.h \
	traces/interface/X86TraceGenerator.h \
	traces/interface/X86TraceGeneratorCommon.h

################################################################################

################################################################################
## Extra clean rules
CLEANFILES = 
################################################################################

