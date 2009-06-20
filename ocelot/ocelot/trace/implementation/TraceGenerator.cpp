/*!
	\file TraceGenerator.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief implements the base TraceGenerator class
*/

#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

trace::TraceGenerator::TraceGenerator() {

}

trace::TraceGenerator::~TraceGenerator() {

}

/*!
	called when a traced kernel is launched to retrieve some parameters from the kernel
*/
void trace::TraceGenerator::initialize(
	const executive::EmulatedKernel *kernel) {
	// if we cared, we could get the kernel's launch configuration:
	//
	// kernel->gridDim
	// kernel->blockDim
	// kernel->threadCount
	// kernel->RegisterCount
	// kernel->ParameterMemorySize
	// kernel->ConstMemorySize
	// kernel->SharedMemorySize
	// kernel->KernelInstructions
	report( "Initializing trace generator for kernel " << kernel->name );
}

/*!
	called whenever an event takes place
*/
void trace::TraceGenerator::event(const TraceEvent & event) {
	// do something meaningful with the trace
	report( "Default Trace: " << event.toString() );
}

