// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Device.h>

opencl::Device::Device(executive::Device * d, 
	cl_device_type type, Platform * p):
	exeDevice(d), _type(type), _vendorId(_deviceCount++),
	_platform(p), _builtInKernels("") {
}

opencl::Device::~Device() {
}

cl_uint opencl::Device::_deviceCount = 0;

opencl::Platform * opencl::Device::platform() {
	return _platform;
}

const cl_device_type opencl::Device::type() const {
	return _type;
}

cl_int opencl::Device::getInfo(cl_device_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {

	cl_int result = CL_SUCCESS;

	union infoUnion {
		cl_device_type deviceType;
		cl_uint uint;
		size_t sizes[3];
		size_t size;
		cl_ulong ulong;
		cl_bool boolVar;
		cl_device_fp_config fpConfig;
		cl_device_mem_cache_type memCacheType;
		cl_device_local_mem_type localMemType;
		cl_device_exec_capabilities execCap;
		cl_command_queue_properties queueProp;
		const char * str;
		cl_platform_id platform;
		cl_device_id deviceId;
		cl_device_partition_property * partProp;
		cl_device_affinity_domain affinityDomain;
	};

	infoUnion info;
	const void * ptr = &info;
	size_t infoLen = 0;
	const executive::Device::Properties & prop = exeDevice->properties();

	try {
		switch(param_name) {
			case CL_DEVICE_TYPE:
				info.deviceType = _type;
				infoLen = sizeof(cl_device_type);
				break;

			case CL_DEVICE_VENDOR_ID:
				info.uint = _vendorId;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_MAX_COMPUTE_UNITS:
				info.uint = (cl_uint)prop.multiprocessorCount * 48; //fermi	
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS:
				info.uint = 3;
				infoLen = sizeof(cl_uint);
				break;
	
			case CL_DEVICE_MAX_WORK_ITEM_SIZES:
				for(int i = 0; i < 3; i++)
					info.sizes[i] = (size_t)prop.maxThreadsDim[i];
				infoLen = sizeof(size_t[3]); 
				break;

			case CL_DEVICE_MAX_WORK_GROUP_SIZE:
				for(int i = 0; i < 3; i++)
					info.sizes[i] = (size_t)prop.maxGridSize[i];
				infoLen = sizeof(size_t[3]); 
				break;

			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR:
				info.uint = 16;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT:
				info.uint = 8;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT:
				info.uint = 4;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG:
				info.uint = 2;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT:
				info.uint = 4;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE:
				info.uint = 2;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF:
				info.uint = 0; //cl_khr_fp16 extension not supported
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR:
				info.uint = 16;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT:
				info.uint = 8;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_NATIVE_VECTOR_WIDTH_INT:
				info.uint = 4;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG:
				info.uint = 2;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT:
				info.uint = 4;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE:
				info.uint = 2;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF:
				info.uint = 0; //cl_khr_fp16 extension not supported
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_MAX_CLOCK_FREQUENCY:
				info.uint = (cl_uint)prop.clockRate;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_ADDRESS_BITS:
				info.uint = 64;
				infoLen = sizeof(cl_uint);
				break;

			case CL_DEVICE_MAX_MEM_ALLOC_SIZE:
				info.uint = (cl_ulong)prop.totalMemory;
				infoLen = sizeof(cl_ulong);
				break;

			case CL_DEVICE_IMAGE_SUPPORT:
				info.boolVar = CL_TRUE;
				infoLen = sizeof(cl_bool);
				break;




			case CL_DEVICE_NAME:
				info.str = prop.name;
				ptr = info.str;
				infoLen = std::strlen(prop.name) + 1;
				break;
				
				break;
			default:
				assertM(false, "Device info unimplemented!\n");
				result = CL_UNIMPLEMENTED;
				break;
		}

		if(param_value && param_value_size < infoLen)
			throw CL_INVALID_VALUE;
		
		if(param_value != 0)
			std::memcpy(param_value, ptr, infoLen);
	
		if(param_value_size_ret !=0 )
			*param_value_size_ret = infoLen;

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	return result;

}

