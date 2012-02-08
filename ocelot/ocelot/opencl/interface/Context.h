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
#include <ocelot/opencl/interface/Platform.h>
#include <ocelot/opencl/interface/Object.h>

namespace opencl {

	class MemoryObject;
	class Program;
	class CommandQueue;

	/*! Host thread OpenCL context consists of these */
	class Context : public Object{	
	
		public:

		typedef std::list< MemoryObject * > MemoryObjectList;
		typedef Device::DeviceList DeviceList;
		typedef std::list< CommandQueue * > QueueList;
		typedef std::list< Program * > ProgramList;


		//! platform
		Platform * platform;
	
		//! set of valid device indices
		DeviceList validDevices;

		//! set of valid programs
		ProgramList validPrograms;

		//! set of valid buffer objects
		MemoryObjectList validMemories;

		//! set of valid command queues
		QueueList validQueues;
	
		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector persistentTraceGenerators;

		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector nextTraceGenerators;
			
	public:
		Context(Platform * platform, DeviceList & devices);
		~Context();

	};

}

#endif
