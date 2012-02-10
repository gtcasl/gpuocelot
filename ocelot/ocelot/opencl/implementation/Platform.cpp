// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Platform.h>

opencl::Platform::Platform(): Object(OBJTYPE_PLATFORM),
	_profile("FULL_PROFILE"), _version("1.2"),
	_name("Ocelot OpenCL"), _vendor("Gatch CASL"),
	_extensions("cl_khr_gl_sharing") {
}

opencl::Platform::~Platform() {
}
	
void opencl::Platform::getInfo(cl_platform_info param_name,
	size_t param_value_size,
    void * param_value,
    size_t * param_value_size_ret) {

	const char * info;
	size_t infoLen;

	switch(param_name) {
		case CL_PLATFORM_PROFILE:
			info = _profile.c_str();
			infoLen = _profile.length() + 1;
			break;

		case CL_PLATFORM_VERSION: 
			info = _version.c_str();
			infoLen = _version.length() + 1;
			break;

		case CL_PLATFORM_NAME: 
			info = _name.c_str();
			infoLen = _name.length() + 1;
			break;

		case CL_PLATFORM_VENDOR: 
			info = _vendor.c_str();
			infoLen = _vendor.length() + 1;
			break;

		case CL_PLATFORM_EXTENSIONS:
			info = _extensions.c_str();
			infoLen = _extensions.length() + 1;
			break;
		
		default:
			throw CL_INVALID_VALUE;
			break;
	}

	if(param_value && param_value_size < infoLen)
		throw CL_INVALID_VALUE;
	
	if(param_value != 0)
		std::memcpy(param_value, info, infoLen);
	
	if(param_value_size_ret != 0)
		*param_value_size_ret = infoLen;
}

