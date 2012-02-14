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
		typedef std::list< Context * > ContextList;

	public:
		Context(Platform * platform, Device::DeviceList & devices);
		~Context();

	public:
		void release();

		//! Get all valid devices
		Device::DeviceList & getValidDevices();

		//! check if valid device
		bool isValidDevice(Device * device);

	private:
		//! platform
		Platform * _platform;
	
		//! set of valid device indices
		Device::DeviceList _validDevices;

		//! set of trace generators to be inserted into emulated kernels
		//trace::TraceGeneratorVector persistentTraceGenerators;

		//! set of trace generators to be inserted into emulated kernels
		//trace::TraceGeneratorVector nextTraceGenerators;
			

	};

}

#endif
