/*!
	\file DynamicCompilationOverhead.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date August 16, 2011
	\brief accumulates time spent in each of Ocelot's dynamic JIT compilation components
*/

#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/trace/interface/DynamicCompilationOverhead.h>

#include <iostream>
#include <fstream>

namespace trace {

DynamicCompilationOverhead::DynamicCompilationOverhead(): 
	ptxParseOcelot(0), instrumentPtx(0), ptxEmitOcelot(0), ptxRegister(0), kernelExecute(0) {

}

DynamicCompilationOverhead::~DynamicCompilationOverhead() {
	if (api::OcelotConfiguration::get().trace.dynamicCompilation.enabled) {
		struct {
			const char *name;
			double *ptr;
		} members[] = {
			{ "ptxParseOcelot", &ptxParseOcelot },
			{ "instrumentPtx", &instrumentPtx },
			{ "ptxEmitOcelot", &ptxEmitOcelot },
			{ "ptxCudaLoad", &ptxCudaLoad },
			{ "ptxRegister", &ptxRegister },
			{ "kernelExecute", & kernelExecute},
			{ 0, 0 }
		};
		
		std::cout << "DynamicCompilationOverhead: {\n";
		for (int i = 0; members[i].ptr; ++i) {
			std::cout << "  \"" << members[i].name << "\": " << *(members[i].ptr) << ",\n";
		}
		std::cout << "}\n";
	}
}

//! starts a timer
void DynamicCompilationOverhead::start() {
	timer.start();
}

//! stops the timer and adds time to a selected accumulator
void DynamicCompilationOverhead::stop(double DynamicCompilationOverhead::* accumulator) {
	timer.stop();
	this->*accumulator += timer.seconds();
}

// global counter
DynamicCompilationOverhead DynamicCompilationOverhead::instance;

}
