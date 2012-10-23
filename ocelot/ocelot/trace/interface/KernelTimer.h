/*! 
	\file KernelTimer.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date June 29, 2012
	\brief measures the total kernel runtime of an application
*/

#ifndef TRACE_KERNELTIMER_H_INCLUDED
#define TRACE_KERNELTIMER_H_INCLUDED

// Ocelot includes
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/trace/interface/EventTimer.h>

namespace trace {

	//! stores the total kernel runtime
	class KernelTimer: public trace::TraceGenerator {
	public:
		KernelTimer();
		virtual ~KernelTimer();
		
		virtual void initialize(const executive::ExecutableKernel& kernel);
		virtual void event(const TraceEvent &);
		virtual void finish();
		
		std::string outputFile;
		
	protected:
		const executive::ExecutableKernel *kernel;
		executive::EventTimer kernelTimer;
		size_t dynamicInstructions;
	};
}

#endif

