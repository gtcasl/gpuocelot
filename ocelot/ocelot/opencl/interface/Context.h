#ifndef OCELOT_OPENCL_CONTEXT_H_INCLUDED
#define OCELOT_OPENCL_CONTEXT_H_INCLUDED

// C++ libs
#include <string>
#include <map>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/MemoryObject.h>
#include <ocelot/opencl/interface/CommandQueue.h>
#include <ocelot/opencl/interface/Program.h>

namespace opencl {

	class MemoryObject;
	class Program;
	class CommandQueue;

	typedef std::set< int > IndexSet;
	typedef std::set< MemoryObject * > MemoryObjectSet;
	typedef std::set< executive::Device *> DeviceSet;
	typedef std::set< CommandQueue * > QueueSet;
	typedef std::set< Program * > ProgramSet;

	/*! Host thread OpenCL context consists of these */
	class Context {	
	public:
		//! index of selected device
		executive::Device * selectedDevice;
		
		//! set of valid device indices
		DeviceSet validDevices;

		//! set of valid programs
		ProgramSet validPrograms;

		//! set of valid buffer objects
		MemoryObjectSet validMemories;

		//! set of valid command queues
		QueueSet validQueues;
	
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
