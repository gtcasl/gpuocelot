#ifndef OCELOT_OPENCL_PLATFORM_H_INCLUDED
#define OCELOT_OPENCL_PLATFORM_H_INCLUDED

// C++ libs

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Object.h>

namespace opencl {

	class Platform : public Object{
	public:
		Platform();
		~Platform();

		//Get info
		void getInfo(cl_platform_info param_name,
			size_t param_value_size,
			void * param_value,
			size_t * param_value_size_ret);


	private:		
		//OpenCL profile
		const std::string _profile;

		//Platform version
		const std::string _version;

		//Platform name
		const std::string _name;

		//Platform vendor
		const std::string _vendor;

		//Extension supported
		const std::string _extensions;
	};	
}

#endif
