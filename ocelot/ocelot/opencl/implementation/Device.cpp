// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Device.h>

opencl::Device::DeviceList opencl::Device::_deviceList = opencl::Device::DeviceList();

bool opencl::Device::_loaded = false;

cl_uint opencl::Device::_deviceCount = 0;

const bool opencl::Device::_hasPlatform(cl_platform_id platform) const {
	return ((Platform *)platform == _platform);
}

const bool opencl::Device::_isType(const cl_device_type type) const {
	return (type == CL_DEVICE_TYPE_ALL || type==_type);
}

opencl::Device::Device(executive::Device * d, 
	cl_device_type type, Platform * p):
	Object(OBJTYPE_DEVICE),
	_exeDevice(d), _type(type), _vendorId(_deviceCount++),
	_platform(p), _builtInKernels("") {

	_platform->retain();
}

opencl::Device::~Device() {

	if(_platform->release())
		delete _platform;

	delete _exeDevice;

	DeviceList::iterator it = std::find(_deviceList.begin(), _deviceList.end(), this);
	assert(it != _deviceList.end());

	_deviceList.erase(it);

}

void opencl::Device::createDevices(Platform * platform, deviceT device, 
	unsigned int flags, int computeCapability, int workerThreadLimit ) {

	executive::DeviceVector d;
	cl_device_type type= CL_DEVICE_TYPE_DEFAULT;

	switch(device) {
		case DEVICE_NVIDIA_GPU:
			d = executive::Device::createDevices(ir::Instruction::SASS, flags,
				computeCapability);
			type = CL_DEVICE_TYPE_GPU;
			report(" - Added " << d.size() << " nvidia gpu devices." );
			break;

		case DEVICE_EMULATED:
			d = executive::Device::createDevices(ir::Instruction::Emulated, flags,
				computeCapability);
			type = CL_DEVICE_TYPE_GPU;
			report(" - Added " << d.size() << " emulator devices." );
			break;

		case DEVICE_MULTICORE_CPU:
			d = executive::Device::createDevices(ir::Instruction::LLVM, flags,
				computeCapability);
			type = CL_DEVICE_TYPE_CPU;
			report(" - Added " << d.size() << " llvm-cpu devices." );

			if (workerThreadLimit > 0) {
				for (executive::DeviceVector::iterator d_it = d.begin();
					d_it != d.end(); ++d_it) {
					(*d_it)->limitWorkerThreads(workerThreadLimit);
				}
			}
			break;

		case DEVICE_AMD_GPU:
			d =	executive::Device::createDevices(ir::Instruction::CAL, flags,
					computeCapability);
			type = CL_DEVICE_TYPE_GPU;
			report(" - Added " << d.size() << " amd gpu devices." );
			break;

		case DEVICE_REMOTE:
			d =
				executive::Device::createDevices(ir::Instruction::Remote, flags,
					computeCapability);
			type = CL_DEVICE_TYPE_GPU;
			report(" - Added " << d.size() << " remote devices." );
			break;
	}
	
	for(size_t i = 0; i < d.size(); i++)
		_deviceList.push_back(new Device(d[i], type, platform));
}

cl_uint opencl::Device::getDevices(cl_platform_id platform, cl_device_type type, cl_uint num_entries,
	cl_device_id * devices, cl_uint * num_devices) {
	cl_uint j = 0;
	if(devices != 0) {
		for(DeviceList::iterator d = _deviceList.begin(); d != _deviceList.end(); d++) {
			if((*d)->_isType(type) && (*d)->_hasPlatform(platform)) {
				if(j < num_entries)
					devices[j] = (cl_device_id)(*d);
				j++;
			}
		}
	}
	
	if(num_devices != 0)
		*num_devices = j;

	return j;
}

void opencl::Device::limitWorkerThreadForAll(unsigned int limit) {
	for (DeviceList::iterator device = _deviceList.begin(); 
		device != _deviceList.end(); ++device) {
		(*device)->_exeDevice->limitWorkerThreads(limit);
	}
} 

void opencl::Device::unregisterModuleForAll(const std::string & name) {
	for (DeviceList::iterator device = _deviceList.begin(); 
		device != _deviceList.end(); ++device) {
		(*device)->_exeDevice->select();
		(*device)->_exeDevice->unload(name);
		(*device)->_exeDevice->unselect();
	}
}

void opencl::Device::setOptimizationLevelForAll(translator::Translator::OptimizationLevel l) {
	for (DeviceList::iterator device = _deviceList.begin(); 
		device != _deviceList.end(); ++device) {
		(*device)->_exeDevice->select();
		(*device)->_exeDevice->setOptimizationLevel(l);
		(*device)->_exeDevice->unselect();
	}
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
	const executive::Device::Properties & prop = _exeDevice->properties();

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

const char * opencl::Device::name() {
	return _exeDevice->properties().name;
} 

void opencl::Device::select() {
	_exeDevice->select();
}

void opencl::Device::unselect() {
	_exeDevice->unselect();
}

void opencl::Device::load(const ir::Module * module) {
	_exeDevice->load(module);
}

void opencl::Device::unload(const std::string & name) {
	_exeDevice->unload(name);
}

void opencl::Device::launch(const std::string& module,
                const std::string& kernel, const ir::Dim3& grid,
                const ir::Dim3& block, size_t sharedMemory,
                const void* argumentBlock, size_t argumentBlockSize,
                const trace::TraceGeneratorVector& traceGenerators,
                const ir::ExternalFunctionSet* externals) {

	_exeDevice->launch(module, kernel, grid, block, sharedMemory,
					argumentBlock, argumentBlockSize, traceGenerators,
					externals);
}

void opencl::Device::setOptimizationLevel(translator::Translator::OptimizationLevel level) {
	_exeDevice->setOptimizationLevel(level);

}

void * opencl::Device::allocate(size_t size) {
	return _exeDevice->allocate(size)->pointer();
}

bool opencl::Device::read(const void * src, void * host, size_t offset, size_t size) {
	if(!_exeDevice->checkMemoryAccess((char *)src + offset, size))
		return false;

	_exeDevice->getMemoryAllocation(src)->copy(host, offset, size);
	return true;
}

bool opencl::Device::write(void * dest, const void * host, size_t offset, size_t size) {	
	if(!_exeDevice->checkMemoryAccess((char *)dest + offset, size))
		return false;

	_exeDevice->getMemoryAllocation(dest)->copy(offset, host, size);
	return true;
}

