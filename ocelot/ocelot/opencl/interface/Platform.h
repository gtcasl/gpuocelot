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

	public:

		//get available platforms
		static void getPlatforms(cl_uint num_entries,
			cl_platform_id * platforms,
			cl_uint * num_platforms);

		void release();

		//Get info
		void getInfo(cl_platform_info param_name,
			size_t param_value_size,
			void * param_value,
			size_t * param_value_size_ret);


	private:		
		//available platform
		static Platform * _platform;

		//platform loaded flag
		static bool _loaded;	

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
