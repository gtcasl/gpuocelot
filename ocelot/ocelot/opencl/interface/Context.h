#ifndef OCELOT_OPENCL_CONTEXT_H_INCLUDED
#define OCELOT_OPENCL_CONTEXT_H_INCLUDED

// C++ libs
#include <string>
#include <map>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/MemoryObject.h>

namespace opencl {

	typedef std::set< int > IndexSet;
	typedef std::set< MemoryObject * > MemoryObjectSet;

	/*! Host thread OpenCL context consists of these */
	class Context {	
	public:
		//! index of selected device
		executive::Device * selectedDevice;
		
		//! set of valid device indices
		IndexSet validDevices;

		//! set of valid programs
		IndexSet validPrograms;

		//! set of valid buffer objects
		MemoryObjectSet validMemories;

		//! set of valid command queues
		IndexSet validQueues;
	
		//! last result returned by a OpenCL call
		cl_int lastError;
		
		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector persistentTraceGenerators;

		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector nextTraceGenerators;
			
	public:
		Context();
		~Context();

		Context(const Context& c);	
		Context& operator=(const Context& c);

		Context(Context&& c);	
		Context& operator=(Context&& c);

		void clear();
	};

}

#endif
