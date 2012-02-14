// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Kernel.h>

bool opencl::Kernel::_isBuiltOnDevice(Device * device) {
	if(_deviceInfo.find(device) != _deviceInfo.end())
		return true;

	return false;
}


opencl::Kernel::Kernel(const std::string &n, 
	Program * p): Object(OBJTYPE_KERNEL),
	_name(n), _program(p) {
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

	_program->removeKernel(this);

	_program->release();

}

void opencl::Kernel::release() {
	if(Object::release())
		delete this;
}

bool opencl::Kernel::isValidContext(Context * context) {
	return _program->isValidContext(context);
}


void opencl::Kernel::addDeviceInfo(Device * device, std::string moduleName, 
	ir::Module * module, ir::Kernel * irKernel) {

	_deviceInfo[device] = (deviceInfoT){moduleName, module, irKernel};
}

void opencl::Kernel::setArg(cl_uint arg_index, size_t arg_size, const void * arg_value) {

	_parameterSizes[arg_index] = arg_size;
	char * paramVal = new char[arg_size];
	memcpy(paramVal, arg_value, arg_size);
	_parameterPointers[arg_index] = paramVal;

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
		
			if(argSize != sizeof(void *))
				throw CL_INVALID_KERNEL_ARGS;

			MemoryObject * mem = *(MemoryObject **)pointer;
			if(!mem->isAllocatedOnDevice(device))
				throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

			void * addr = mem->getPtrOnDevice(device);
			memcpy(_parameterBlock + offset, &addr, argSize);
		}
		else { //non-memory argument
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
//		traceGens = ctx.persistentTraceGenerators;
//		traceGens.insert(traceGens.end(),
//			ctx.nextTraceGenerators.begin(), 
//			ctx.nextTraceGenerators.end());
//
//		_inExecute = true;

		device->launch(_deviceInfo[device]._moduleName, _name, convert(_workGroupNum), 
			convert(_localWorkSize), /*launch.sharedMemory*/0, 
			_parameterBlock, _parameterBlockSize, traceGens, NULL/*&_externals*/);
//		_inExecute = false;
		report(" launch completed successfully");	
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

