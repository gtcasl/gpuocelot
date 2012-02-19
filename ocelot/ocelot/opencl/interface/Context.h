/*!	
	\file Context.h
	\author Jin Wang <jin.wang@gatech.edu>
	\brief defines OpenCL runtime context interface
	\date 03 Feb 2012
*/



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

	/*! \brief OpenCL context consists of these */
	class Context : public Object{	
	
	public:
		/*! \brief type of context list */
		typedef std::list< Context * > ContextList;

	public:
		/*! \brief constructor */
		Context(Platform * platform, Device::DeviceList & devices);

		/*! \brief destructor */
		~Context();

	public:
		/*! \brief release context, decrease reference count by 1.
			if all objects related to the context are deleted. delete
			context
		*/
		void release();

		/*! \brief Get all valid devices associated with the context */
		Device::DeviceList & getValidDevices();

		/*! \brief check if this is a valid device for the context */
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
