/*! 
	\file KernelTimer.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date June 29, 2012
	\brief measures the total kernel runtime of an application
*/

// C++ includes
#include <fstream>

// Boost includes
#include <boost/lexical_cast.hpp>

// Ocelot includes
#include <ocelot/trace/interface/KernelTimer.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/executive/interface/ExecutableKernel.h>

////////////////////////////////////////////////////////////////////////////////////////////////////

trace::KernelTimer::KernelTimer(): outputFile("traceKernelTimer.json"), kernel(0) {
	kernelTimer.clearAccumulated();
}

trace::KernelTimer::~KernelTimer() {
}

void trace::KernelTimer::initialize(const executive::ExecutableKernel& kernel) {
	this->kernel = &kernel;
	dynamicInstructions = 0;
	kernelTimer.start();
}

void trace::KernelTimer::event(const TraceEvent &) {
	++dynamicInstructions;
}

void trace::KernelTimer::finish() {
	kernelTimer.stop();
	
	size_t kernelCycles = kernelTimer.getAccumulated();
	assert(kernelCycles);
	
	std::ofstream file(outputFile.c_str(), std::ios_base::app);

	const char *appname = getenv("APPNAME");
	if (!appname) { appname = "Unknown Application"; }

	file << "{ \"application\": \"" << appname << "\", ";
	
	const char *trial = getenv("TRIALNAME");
	if (trial) {
		file << " \"trial\": \"" << trial << "\", ";
	}
	const char *execution = getenv("EXECUTION");
	if (execution) {
		file << " \"execution\": " << boost::lexical_cast<int, const char *>(execution) << ", ";
	}
	
	file
		<< "\"ISA\": \"" << ir::Instruction::toString(kernel->device->properties().ISA) << "\", "
		<< "\"device\": \"" << kernel->device->properties().name << "\", "
		<< "\"kernel\": \"" << kernel->name << "\", "
		<< "\"instructions\": " << dynamicInstructions << ", "
		<< "\"kernelRuntime\": " << kernelCycles << " }, " << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

