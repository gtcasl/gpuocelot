// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/transforms/interface/MemoryAccessSizePass.h>
#include <ocelot/opencl/interface/OpenCLRuntime.h>
#include <ocelot/opencl/interface/Kernel.h>
//#include <ocelot/opencl/interface/LCLRuntime.h>

#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

bool opencl::Kernel::_isBuiltOnDevice(Device * device) {
	if(_deviceInfo.find(device) != _deviceInfo.end())
		return true;

	return false;
}

size_t opencl::Kernel::_maxWorkGroupSize(Device * device) {
	size_t maxSize;
	device->getInfo(CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), &maxSize, NULL);
	return maxSize; 
}

size_t opencl::Kernel::_getArgumentsSize() {

	return _deviceInfo.begin()->second._irKernel->arguments.size();
}

std::string & opencl::Kernel::_getArgumentName(cl_uint arg_index) {
	return _deviceInfo.begin()->second._irKernel->arguments[arg_index].name;
}

opencl::Kernel::Kernel(const std::string &n, 
	Program * p, bool builtIn): Object(OBJTYPE_KERNEL),
	_name(n), _isBuiltIn(builtIn), _program(p),
	_sharedBase((void *)0),	_sharedOffset(0)/*hard-coded according to NVIDIA GPU*/ {
	_parameterBlock = NULL;
	_program->retain();
}

opencl::Kernel::~Kernel()
{
	PointerMap::iterator pointer;
	for(pointer = _parameterPointers.begin(); pointer != _parameterPointers.end(); pointer++) {
		delete pointer->second;
	}

	if(_parameterBlock)
		delete _parameterBlock;


}

void opencl::Kernel::release() {
	if(Object::release()) {
		_program->removeKernel(this);

		_program->release();
		delete this;
	}
}

bool opencl::Kernel::isValidContext(Context * context) {
	return _program->isValidContext(context);
}

opencl::Context * opencl::Kernel::getContext() {
	return _program->getContext();
}

void opencl::Kernel::addDeviceInfo(Device * device, std::string moduleName, 
	ir::Module * module, ir::Kernel * irKernel) {

	deviceInfoT devInfo = {moduleName, module, irKernel};

	_deviceInfo[device] = devInfo;
}

void opencl::Kernel::setArg(cl_uint arg_index, size_t arg_size, const void * arg_value) {

	if(arg_value != NULL) {
		_parameterSizes[arg_index] = arg_size;
		char * paramVal = new char[arg_size];
		memcpy(paramVal, arg_value, arg_size);
		_parameterPointers[arg_index] = paramVal;
	}
	else { //a null pointer for buffer object, or argument has __local qualifier
		_parameterSizes[arg_index] = sizeof(void *); //pointer size
		char * paramVal = new char[sizeof(void *)];
		*((void **)paramVal) = (void *)((size_t)_sharedBase + _sharedOffset);
		_sharedOffset += arg_size;
		report("Found shared parameter, shared offset = " << _sharedOffset);
		_parameterPointers[arg_index] = paramVal;
	}

}

void opencl::Kernel::mapParametersOnDevice(Device * device) {

	if(_parameterSizes.size() == 0)
		throw CL_INVALID_KERNEL_ARGS;

	assert(_parameterSizes.size() == _parameterPointers.size());

	if(!_isBuiltOnDevice(device))
		throw CL_INVALID_PROGRAM_EXECUTABLE;	
		
	if(_deviceInfo[device]._irKernel->arguments.size() != _parameterSizes.size())
		throw CL_INVALID_KERNEL_ARGS;

	//Get aligned parameter sizes	
	_parameterBlockSize = 0;
	_parameterOffsets.clear();
	ir::Kernel *k = _deviceInfo[device]._irKernel;

	unsigned int argId = 0;
	for (ir::Kernel::ParameterVector::const_iterator parameter = k->arguments.begin(); 
		parameter != k->arguments.end(); ++parameter, ++argId) {
		_parameterOffsets[argId] = _parameterBlockSize;
		unsigned int misalignment = _parameterBlockSize % parameter->getAlignment();
		unsigned int alignmentOffset = misalignment == 0 
			? 0 : parameter->getAlignment() - misalignment;
		_parameterBlockSize += alignmentOffset;
		_parameterBlockSize += parameter->getSize();
	}

	if(_parameterBlock)
	{
		delete[] _parameterBlock;
		_parameterBlock = NULL;
	}
	
	_parameterBlock = new char[_parameterBlockSize];
	memset(_parameterBlock, 0, _parameterBlockSize);

	//Copy parameters to aligned offset
	assert(_parameterSizes.size() == _parameterPointers.size());
	assert(_parameterSizes.size() == _parameterOffsets.size());
	argId = 0;
	for(SizeMap::iterator size = _parameterSizes.begin();
		size != _parameterSizes.end(); size++, argId++) {
		assert(size->first == argId);
		assert(_parameterPointers.find(argId) != _parameterPointers.end());
		assert(_parameterOffsets.find(argId) != _parameterOffsets.end());
		
		unsigned int offset = _parameterOffsets[argId];
		size_t oriSize = size->second;
		size_t argSize = k->arguments[argId].getSize();
		void * pointer = _parameterPointers[argId];

		//check if it is a memory address argument
		if(oriSize == sizeof(cl_mem) &&  
			(*(MemoryObject **)pointer)->isValidObject(Object::OBJTYPE_MEMORY)) {//pointer is memory object

			report("Memory object arg size = " << argSize);
		
			if(argSize != sizeof(void *))
				throw CL_INVALID_KERNEL_ARGS;

			MemoryObject * mem = *(MemoryObject **)pointer;
			if(!mem->isAllocatedOnDevice(device))
				throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

			void * addr = mem->getPtrOnDevice(device);
			memcpy(_parameterBlock + offset, &addr, argSize);
		}
		else { //non-memory argument
			report("Non-Memory object arg size = " << argSize << ", value = " << *(size_t *)pointer);
			if(oriSize != argSize)
				throw CL_INVALID_KERNEL_ARGS;

			memcpy(_parameterBlock + offset, pointer, argSize);
		}

	}
}

void opencl::Kernel::setConfiguration(cl_uint work_dim, const size_t * global_work_offset,
		const size_t * global_work_size, const size_t * local_work_size) {

	if(work_dim < 1 || work_dim > 3)
			throw CL_INVALID_WORK_DIMENSION;

	if(global_work_size == NULL)
		throw CL_INVALID_GLOBAL_WORK_SIZE;

	for(cl_uint dim = 0; dim < work_dim; dim++) {
		if (global_work_size[dim] == 0)
			throw CL_INVALID_GLOBAL_WORK_SIZE;
	}

	if(global_work_offset != NULL) {
		assertM(false, "non-null global work offset unsupported");
		throw CL_UNIMPLEMENTED;
	}

	if(local_work_size) {
		for(cl_uint dim = 0; dim < work_dim; dim++) {
		if(local_work_size[dim] == 0)
			throw CL_INVALID_WORK_ITEM_SIZE;

		if (global_work_size[dim] / local_work_size[dim] * local_work_size[dim] != global_work_size[dim])
			throw CL_INVALID_WORK_GROUP_SIZE;
		}
	}


	for(cl_uint dim = 0; dim < 3; dim++) {
		if(dim < work_dim) {
			_globalWorkSize[dim] = global_work_size[dim];
			if(local_work_size)
				_localWorkSize[dim] = local_work_size[dim];
			else
				_localWorkSize[dim] = global_work_size[dim];
		}
		else {
			_globalWorkSize[dim] = 1;
			_localWorkSize[dim] = 1;
		}

		_workGroupNum[dim] = _globalWorkSize[dim] / _localWorkSize[dim];
	}
}

static ir::Dim3 convert(const size_t d[3]) {
	return std::move(ir::Dim3(d[0], d[1], d[2]));
}

//static size_t threadCount(const size_t workGroupNum[3], const size_t localWorkSize[3]) {
//	return workGroupNum[0] * workGroupNum[1] * workGroupNum[2] * localWorkSize[0] 
//	* localWorkSize[1] * localWorkSize[2];
//}

void opencl::Kernel::launchOnDevice(Device * device)
{

	if(!_isBuiltOnDevice(device))
		throw CL_INVALID_PROGRAM_EXECUTABLE;

	report("kernel launch (" << _name 
		<< ") on device " << device);
	
//	try {
	
//		Context &ctx = *((Context *) kernel.context);
		trace::TraceGeneratorVector traceGens;
//
		OpenCLRuntime * runtime = dynamic_cast<OpenCLRuntime *>(OpenCLRuntimeInterface::get());

		traceGens = runtime->persistentTraceGenerators;
		traceGens.insert(traceGens.end(),
			runtime->nextTraceGenerators.begin(), 
			runtime->nextTraceGenerators.end());
		runtime->nextTraceGenerators.clear();

//		_inExecute = true;

//		lcl::LCLRuntime * lcl = lcl::LCLRuntime::get();
//		void *ptr = NULL;
//		if(lcl->isInEvaluation()) {
//			ptr = device->allocate(sizeof(uint32_t));
//			std::cout << "$$$$$$$$$$$$$$$$ temp allocate ptr = " << ptr << std::endl;
//			uint32_t init = 0;
//			device->write(ptr, &init, 0, sizeof(uint32_t)); 
//	
//			ir::Module * module = _deviceInfo[device]._module;
//			transforms::MemoryAccessSizePass memAccessSizePass(ptr);
//			transforms::PassManager manager(module);
//			manager.addPass(memAccessSizePass);
//			manager.runOnModule();
//		}

		device->launch(_deviceInfo[device]._moduleName, _name, convert(_workGroupNum), 
			convert(_localWorkSize), _sharedOffset, 
			_parameterBlock, _parameterBlockSize, traceGens, &(runtime->externals));
//		_inExecute = false;
		report(" launch completed successfully");	

//		if(lcl->isInEvaluation()) {
//			uint64_t readSize;
//			device->read(ptr, &readSize, 0, sizeof(uint32_t));
//			std::cout << "##############Read out " << readSize << std::endl;
//			lcl->increaseAccessSize(readSize * threadCount(_workGroupNum, _localWorkSize), lcl::LCLRuntime::DEVICE_READ);
//		}
//	}
//	catch( const executive::RuntimeException& e ) {
//		std::cerr << "==Ocelot== PTX Emulator failed to run kernel \"" 
//			<< kernelName 
//			<< "\" with exception: \n";
//		std::cerr << _formatError( e.toString() ) 
//			<< "\n" << std::flush;
//		_inExecute = false;
//		throw;
//	}
//	catch( const std::exception& e ) {
//		std::cerr << "==Ocelot== " << device->name()
//			<< " failed to run kernel \""
//			<< kernelName
//			<< "\" with exception: \n";
//		std::cerr << _formatError( e.what() )
//			<< "\n" << std::flush;
//		throw;
//	}
//	catch(...) {
//		throw;
//	}
}

void opencl::Kernel::getInfo(cl_kernel_info param_name,
		size_t param_value_size,
		void * param_value,
		size_t * param_value_size_ret) {

	size_t infoLen = 0;
	cl_uint info;
	const void * ptr = &info;

	switch(param_name) {
		case CL_KERNEL_FUNCTION_NAME:
			infoLen = _name.length() + 1;
			ptr = _name.c_str();	
			break;

		case CL_KERNEL_NUM_ARGS:
			infoLen = sizeof(cl_uint);
			info = (cl_uint)_getArgumentsSize();
			break;

		case CL_KERNEL_REFERENCE_COUNT:
			infoLen = sizeof(cl_uint);
			info = (cl_uint)_references;
			break;

		case CL_KERNEL_CONTEXT:
			infoLen = sizeof(cl_context);
			ptr = getContext();
			break;

		case CL_KERNEL_PROGRAM:
			infoLen = sizeof(cl_program);
			ptr = _program;
			break;

		case CL_KERNEL_ATTRIBUTES:
			assertM(false, "CL_KERNEL_ATTRIBUTES unimplemented\n");
			throw CL_UNIMPLEMENTED;

			break;
		default:
			throw CL_INVALID_VALUE;
	}

	if(param_value && param_value_size < infoLen)
		throw CL_INVALID_VALUE;
	
	if(param_value != 0)
		std::memcpy(param_value, ptr, infoLen);

	if(param_value_size_ret !=0 )
		*param_value_size_ret = infoLen;

}

void opencl::Kernel::getArgInfo(cl_uint arg_index, 
		cl_kernel_info param_name,
		size_t param_value_size,
		void * param_value,
		size_t * param_value_size_ret) {

	size_t argSizes = _getArgumentsSize();
	if(arg_index >= (cl_uint) argSizes)
		throw CL_INVALID_ARG_INDEX;

	union infoUnion {
		cl_kernel_arg_address_qualifier cl_kernel_arg_address_qualifier_var;
		cl_kernel_arg_access_qualifier cl_kernel_arg_access_qualifier_var;
		cl_kernel_arg_type_qualifier cl_kernel_type_qualifier_var;
	};

#ifndef ASSIGN_INFO
#define ASSIGN_INFO(field, value) \
do { \
	info.field##_var = value; \
	infoLen = sizeof(field); \
} while(0)
#endif

#ifndef ASSIGN_STRING
#define ASSIGN_STRING(value) \
do { \
	str = value; \
	ptr = str.c_str(); \
	infoLen = str.length() + 1; \
}while(0)
#endif


	size_t infoLen = 0;
	infoUnion info;
	const void * ptr = &info;
	std::string str;

	switch(param_name) {
		case CL_KERNEL_ARG_ADDRESS_QUALIFIER:
			assertM(false, "Unimplemented argument address qualifier\n");
			break;

		case CL_KERNEL_ARG_ACCESS_QUALIFIER:
			assertM(false, "Unimplemented argument access qualifier\n");
			break;

		case CL_KERNEL_ARG_TYPE_NAME:
			assertM(false, "Unimplemented argument type name\n");
			break;

		case CL_KERNEL_ARG_TYPE_QUALIFIER:
			assertM(false, "Unimplemented argument type qualifier\n");
			break;

		case CL_KERNEL_ARG_NAME:
			ASSIGN_STRING(_getArgumentName(arg_index));
			break;

		default:
			throw CL_INVALID_VALUE;
	}

	if(param_value && param_value_size < infoLen)
		throw CL_INVALID_VALUE;
	
	if(param_value != 0)
		std::memcpy(param_value, ptr, infoLen);

	if(param_value_size_ret !=0 )
		*param_value_size_ret = infoLen;

}

void opencl::Kernel::getWorkGroupInfo(cl_device_id device,
		cl_kernel_work_group_info  param_name,
		size_t param_value_size,
		void * param_value,
		size_t * param_value_size_ret) {

	Device * d;

	if(device) {
		if(!_isBuiltOnDevice((Device *) device))
			throw CL_INVALID_VALUE;
	
		d = (Device *)device;
	}
	else {
		if(_deviceInfo.size() > 1)
			throw CL_INVALID_VALUE;
			
		d = (*_deviceInfo.begin()).first;
	}

	
	union infoUnion {
		size_t size_t_var;
		size_t sizes[3];
		cl_ulong cl_ulong_var;
	};

	infoUnion info;
	const void * ptr = &info;
	size_t infoLen = 0;
	executive::ExecutableKernel * kernel = (executive::ExecutableKernel *)_deviceInfo[d]._irKernel;
#ifndef ASSIGN_INFO
#define ASSIGN_INFO(field, value) \
do { \
	info.field##_var = value; \
	infoLen = sizeof(field); \
} while(0)
#endif

	switch(param_name) {
		case CL_KERNEL_GLOBAL_WORK_SIZE:
			if(!d->isType(CL_DEVICE_TYPE_CUSTOM) || !_isBuiltIn)
				throw CL_INVALID_VALUE;
			else {
				assertM(false, "No built-in kernel or custom device supported");
				throw CL_UNIMPLEMENTED;
				//currently no built-in kernel and custom device, leave blank
			} 
			break;

		case CL_KERNEL_WORK_GROUP_SIZE:
			ASSIGN_INFO(size_t, _maxWorkGroupSize(d));
			break;

		case CL_KERNEL_COMPILE_WORK_GROUP_SIZE:
			std::memset(info.sizes, 0, 3*sizeof(size_t));
			ptr = info.sizes;
			infoLen = 3 * sizeof(size_t);
			break;

		case CL_KERNEL_LOCAL_MEM_SIZE:
			ASSIGN_INFO(cl_ulong, (cl_ulong)(kernel->totalSharedMemorySize()));
			break;

		case CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE:
			ASSIGN_INFO(size_t, 32);
			break;

		case CL_KERNEL_PRIVATE_MEM_SIZE:
			ASSIGN_INFO(cl_ulong, (cl_ulong)(kernel->localMemorySize()));
			break;

		default:
			throw CL_INVALID_VALUE;
			break;
	

	}

	if(param_value && param_value_size < infoLen)
		throw CL_INVALID_VALUE;
	
	if(param_value != 0)
		std::memcpy(param_value, ptr, infoLen);

	if(param_value_size_ret !=0 )
		*param_value_size_ret = infoLen;


}

