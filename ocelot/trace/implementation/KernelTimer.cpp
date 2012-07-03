/*! 
	\file KernelTimer.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date June 29, 2012
	\brief measures the total kernel runtime of an application
*/

// C++ includes
#include <fstream>

// Ocelot includes
#include <ocelot/trace/interface/KernelTimer.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/executive/interface/ExecutableKernel.h>

////////////////////////////////////////////////////////////////////////////////////////////////////

trace::KernelTimer::KernelTimer(): outputFile("applicationKernelRuntime.json"), kernel(0) {
	kernelTimer.clearAccumulated();
}

trace::KernelTimer::~KernelTimer() {
}

void trace::KernelTimer::initialize(const executive::ExecutableKernel& kernel) {
	this->kernel = &kernel;
	kernelTimer.start();
}

void trace::KernelTimer::finish() {
	kernelTimer.stop();
	
	size_t kernelCycles = kernelTimer.getAccumulated();

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
		file << " \"execution\": " << std::atoi(execution) << ", ";
	}
	file
		<< "\"device\": \"" << kernel->device->properties().name << "\","
		<< "\"kernel\": \"" << kernel->name << "\", "
		<< "\"kernelRuntime\": " << kernelCycles << " }, " << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

