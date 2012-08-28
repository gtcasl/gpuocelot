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
#include <ocelot/opencl/interface/Device.h>
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
		Context(const cl_context_properties * properties,
			cl_uint num_devices,
			const cl_device_id * devices,
			void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
			void * user_data);

		Context(const cl_context_properties * properties,
			cl_device_type                device_type,
			void (CL_CALLBACK *     pfn_notify)(const char *, const void *, size_t, void *),
			void *                        user_data);

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



		/*! \brief get info of context */
		void getInfo(cl_context_info    param_name,
					size_t             param_value_size,
					void *             param_value,
					size_t *           param_value_size_ret);

	private:
		/* \breif create context, check input properties and platform */
		void _createContext(const cl_context_properties * properties);


	private:
		//! platform
		Platform * _platform;
	
		//! set of valid device indices
		Device::DeviceList _validDevices;

		//! properties
		cl_context_properties * _properties;	

	};

}

#endif
