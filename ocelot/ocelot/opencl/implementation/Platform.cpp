/*!	
	\file Platform.cpp
	\author Jin Wang <jin.wang@gatech.edu>
	\brief defines OpenCL runtime platform
	\date 05 Feb 2012
*/

// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Platform.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

opencl::Platform * opencl::Platform::_platform = NULL;

bool opencl::Platform::_loaded = false;

void opencl::Platform::getPlatforms(cl_uint num_entries, 
	cl_platform_id * platforms, 
	cl_uint * num_platforms) {

	if(!_loaded) {
		report("Create platforms ");
		_platform = new Platform();
		_loaded = true;
	}
	
	if(platforms) {
		for(cl_uint i = 0; i < std::min((cl_uint)1, num_entries); i++)
			platforms[i] = (cl_platform_id)_platform;
	}

	if(num_platforms)
		*num_platforms = 1;

}

opencl::Platform::Platform(): Object(OBJTYPE_PLATFORM),
	_profile("FULL_PROFILE"), _version("1.2"),
	_name("Ocelot OpenCL"), _vendor("OCELOT"),
	_extensions("cl_khr_global_int32_base_atomics \
cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics \
cl_khr_local_int32_extended_atomics cl_khr_byte_addressable_store \
cl_khr_fp64 cl_khr_gl_sharing cl_khr_gl_event") {
}

opencl::Platform::~Platform() {
}
	
void opencl::Platform::release() {
	if(Object::release())
		delete this;
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

