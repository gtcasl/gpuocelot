// C standard library includes
#include <assert.h>

// C++ standard library includes
#include <sstream>
#include <fstream>
#include <algorithm>

// Ocelot includes
#include <ocelot/opencl/interface/OpenCLRuntime.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <ocelot/transforms/interface/PassManager.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

////////////////////////////////////////////////////////////////////////////////

// whether OPENCL runtime catches exceptions thrown by Ocelot
#define CATCH_RUNTIME_EXCEPTIONS 0

// whether verbose error messages are printed
#define OPENCL_VERBOSE 1

// whether debugging messages are printed
#define REPORT_BASE 0

// report all ptx modules
//#define REPORT_ALL_PTX 0

////////////////////////////////////////////////////////////////////////////////
//
// Error handling macros

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; \
	throw hydrazine::Exception(ss.str()); }

////////////////////////////////////////////////////////////////////////////////

typedef api::OcelotConfiguration config;

/*
opencl::RegisteredTexture::RegisteredTexture(const std::string& m, 
	const std::string& t, bool n) : module(m), texture(t), norm(n) {
	
}

opencl::RegisteredGlobal::RegisteredGlobal(const std::string& m, 
	const std::string& g) : module(m), global(g) {

}

opencl::Dimension::Dimension(int _x, int _y, int _z, 
	const openclChannelFormatDesc& _f) : x(_x), y(_y), z(_z), format(_f) {

}

size_t opencl::Dimension::pitch() const {
	return ((format.x + format.y + format.z + format.w) / 8) * x;
}
*/
////////////////////////////////////////////////////////////////////////////////
void opencl::OpenCLRuntime::_enumeratePlatforms(cl_uint num_entries, 
	cl_platform_id * platforms, 
	cl_uint * num_platforms) {
	report("Create platforms ");
	Platform * p = new Platform();
	
	if(platforms) {
		for(cl_uint i = 0; i < std::min((cl_uint)1, num_entries); 
			i++)
			platforms[i] = (cl_platform_id)p;
	}

	if(num_platforms)
		*num_platforms = 1;

}

opencl::Context * opencl::OpenCLRuntime::_createContext(Platform * platform,
	cl_uint deviceNum, const cl_device_id * devices) {
	report("Creating new context ");
	DeviceList deviceList;
	for (cl_uint i = 0; i < deviceNum; i++) {
		if(devices[i] == NULL  	
			|| !devices[i]->isValidObject(Object::OBJTYPE_DEVICE)) {
			throw CL_INVALID_DEVICE;
			break;             	
		}
		deviceList.push_back(devices[i]);
	}
	Context * c = new Context(platform, deviceList);
	_contexts.push_back(c);    	

	return c;
}

void opencl::OpenCLRuntime::_enumerateDevices(cl_platform_id platform,
    cl_device_type device_type, 
    cl_uint num_entries,
    cl_device_id * devices,
    cl_uint * num_devices) {
	if(!_devicesLoaded) {
		report("Creating devices.");
		if(config::get().executive.enableNVIDIA) {
			Device::createDevices(platform, Device::DEVICE_NVIDIA_GPU,
				_flags, _computeCapability);
	
		}
		if(config::get().executive.enableEmulated) {
			Device::createDevices(platform, Device::DEVICE_EMULATED,
				_flags,_computeCapability);
		}
		if(config::get().executive.enableLLVM) {
			Device::createDevices(platform, Device::DEVICE_MULTICORE_CPU,
				_flags,_computeCapability, config::get().executive.workerThreadLimit);
		}
		if(config::get().executive.enableAMD) {
			Device::createDevices(platform, Device::DEVICE_AMD_GPU,
				_flags,_computeCapability);
		}
		if(config::get().executive.enableRemote) {
			Device::createDevices(platform, Device::DEVICE_REMOTE,
				_flags,_computeCapability);
		}
		
		_devicesLoaded = true;
		
	}

	if (Device::getDevices(platform, device_type, num_entries, devices, num_devices) == 0)
		throw CL_DEVICE_NOT_FOUND;
}

//! acquires mutex and locks the runtime
void opencl::OpenCLRuntime::_lock() {
	_mutex.lock();
}

//! releases mutex
void opencl::OpenCLRuntime::_unlock() {
	_mutex.unlock();
}

/*
opencl::Context& opencl::OpenCLRuntime::_bind() {
	_enumerateDevices();

	Context& thread = _createContext();

	if (_devices.empty()) return thread;
	
	_selectedDevice = thread.selectedDevice;
	executive::Device& device = _getDevice();

	assert(!device.selected());
	device.select();
	
	return thread;
}

void opencl::OpenCLRuntime::_unbind() {
	executive::Device& device = _getDevice();
	assert(_createContext().selectedDevice == _selectedDevice);
	
	_selectedDevice = NULL;
	assert(device.selected());
	device.unselect();
}

void opencl::OpenCLRuntime::_acquire() {
	_lock();
	_bind();
	if (_devices.empty()) _unlock();
}

void opencl::OpenCLRuntime::_release() {
	_unbind();
	_unlock();
}
*/

/*
executive::Device& opencl::OpenCLRuntime::_getDevice() {
	return *((executive::Device *)_selectedDevice);
}
*/

/*
std::string opencl::OpenCLRuntime::_formatError( const std::string& message ) {
	std::string result = "==Ocelot== ";
	for(std::string::const_iterator mi = message.begin(); 
		mi != message.end(); ++mi) {
		result.push_back(*mi);
		if(*mi == '\n') {
			result.append("==Ocelot== ");
		}
	}
	return result;
}*/

#if 0
void opencl::OpenCLRuntime::_registerModule(ModuleMap::iterator module, Device * device) {
	if(module->second.loaded()) return;
	module->second.loadNow();	
/*	for(RegisteredTextureMap::iterator texture = _textures.begin(); 
		texture != _textures.end(); ++texture) {
		if(texture->second.module != module->first) continue;
		ir::Texture* tex = module->second.getTexture(texture->second.texture);
		assert(tex != 0);
		tex->normalizedFloat = texture->second.norm;
	}
	
	transforms::PassManager manager(&module->second);
	
	for(PassSet::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		manager.addPass(**pass);
	}
	
	manager.runOnModule();*/
	device->load(&module->second);
	device->setOptimizationLevel(_optimization);
}

void opencl::OpenCLRuntime::_registerModule(const std::string& name, Device * device) {
	ModuleMap::iterator module = _modules.find(name);
	if(module != _modules.end()) {
		_registerModule(module, device);
	}
}

void opencl::OpenCLRuntime::_registerAllModules(Device * device) {
	for(ModuleMap::iterator module = _modules.begin(); 
		module != _modules.end(); ++module) {
		_registerModule(module, device);
	}
}
#endif

////////////////////////////////////////////////////////////////////////////////

opencl::OpenCLRuntime::OpenCLRuntime() : /*_inExecute(false),*/
	_devicesLoaded(false), 
	/*_selectedDevice(NULL), _nextSymbol(1),*/ _computeCapability(2), _flags(0), 
	_optimization((translator::Translator::OptimizationLevel)
		config::get().executive.optimizationLevel) {
}

opencl::OpenCLRuntime::~OpenCLRuntime() {
	//
	// free things that need freeing
	//
	// devices
//	for (DeviceList::iterator device = _devices.begin(); 
//		device != _devices.end(); ++device) {
//		delete *device;
//	}
//	
//	// mutex
//
//	// contexts
//	for(ContextList::iterator context = _contexts.begin();
//		context != _contexts.end(); ++context) {
//		delete *context;
//	}
//	
//	// textures
//	
//	// programs
//	for (ProgramList::iterator program = _programs.begin();
//		program != _programs.end(); ++program) {
//		delete *program;
//	}
//
//	// kernels
//	for (KernelList::iterator kernel = _kernels.begin();
//		kernel != _kernels.end(); ++kernel) {
//		delete *kernel;
//	}
//
//	// memory objects
//	for (MemoryObjectList::iterator memory = _memories.begin();
//		memory != _memories.end(); ++memory) {
//		delete *memory;
//	}
//
//	// command queues
//	for (CommandQueueList::iterator queue = _queues.begin();
//		queue != _queues.end(); ++queue) {
//		delete *queue;
//	}
	
	// fat binaries
	
	// config
	config::destroy();
	
	// globals
}



////////////////////////////////////////////////////////////////////////////////
#if 0
void opencl::OpenCLRuntime::addTraceGenerator( trace::TraceGenerator& gen,
	bool persistent ) {
	_lock();
	Context& thread = _createContext();
	if (persistent) {
		thread.persistentTraceGenerators.push_back(&gen);
	}
	else {
		thread.nextTraceGenerators.push_back(&gen);
	}
	_unlock();
}

void opencl::OpenCLRuntime::clearTraceGenerators() {
	_lock();
	Context& thread = _createContext();
	thread.persistentTraceGenerators.clear();
	thread.nextTraceGenerators.clear();
	_unlock();
}

void opencl::OpenCLRuntime::addPTXPass(transforms::Pass &pass) {
	_lock();
	_passes.insert(&pass);
	_unlock();
}

void opencl::OpenCLRuntime::removePTXPass(transforms::Pass &pass) {
	_lock();

	assert(_passes.count(&pass) != 0);
	_passes.erase(&pass);

	_unlock();
}

void opencl::OpenCLRuntime::clearPTXPasses() {
	_lock();
	_passes.clear();
	_unlock();
}

void opencl::OpenCLRuntime::limitWorkerThreads(unsigned int limit) {
	_lock();
	Device::limitWorkerThreadForAll(limit);
	_unlock();
}

void opencl::OpenCLRuntime::registerPTXModule(std::istream& ptx, 
	const std::string& name) {
	
#if 0
	_lock();
	report("Loading module (ptx) - " << name);
	assert(_modules.count(name) == 0);
	
	ModuleMap::iterator module = _modules.insert(
		std::make_pair(name, ir::Module())).first;
	
	std::string temp;
	
	ptx.seekg(0, std::ios::end);
	size_t size = ptx.tellg();
	ptx.seekg(0, std::ios::beg);
	
	temp.resize(size);
	ptx.read((char*)temp.data(), size);
	
	try {
		module->second.lazyLoad(temp, name);
	}
	catch(...) {
		_unlock();
		_modules.erase(module);
		throw;
	}
		
	_unlock();
#endif
}


void opencl::OpenCLRuntime::registerTexture(const void* texref,
	const std::string& moduleName,
	const std::string& textureName, bool normalize) {
	_lock();
	
	report("registerTexture('" << textureName << ", norm: " << normalize );

	_textures[(void*)texref] = RegisteredTexture(moduleName,
		textureName, normalize);
	
	_unlock();
}


void opencl::OpenCLRuntime::clearErrors() {
#if 0
	_lock();
	_unlock();
#endif
}

void opencl::OpenCLRuntime::reset() {
#if 0
	_lock();
	report("Resetting opencl runtime.");
	//_dimensions.clear();
	
	for(ContextList::iterator context = _contexts.begin(); 
		context != _contexts.end(); ++context)
	{
		report(" Delete context - ");
		delete *context;
	}

	for(DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device)
	{
		report(" Clearing memory on device - " << (*device)->properties().name);
		(*device)->clearMemory();
	}
	
	for(ModuleMap::iterator module = _modules.begin(); module != _modules.end();
		module != _modules.end())
	{
		bool found = false;
		report(" Unloading module - " << module->first);
		/*for(FatBinaryVector::iterator bin = _fatBinaries.begin(); 
			bin != _fatBinaries.end(); ++bin)
		{
			if(bin->name() == module->first)
			{
				found = true;
				break;
			}
		}*/
		
		if(!found)
		{
			for(DeviceVector::iterator device = _devices.begin(); 
				device != _devices.end(); ++device)
			{
				(*device)->select();
				(*device)->unload(module->first);
				(*device)->unselect();
			}
			
			_modules.erase(module++);
		}
		else
		{
			++module;
		}
	}
	_unlock();
#endif
}

ocelot::PointerMap opencl::OpenCLRuntime::contextSwitch(unsigned int destinationId, 
	unsigned int sourceId) {
#if 0
	report("Context switching from " << sourceId << " to " << destinationId);
	
	if(!_devicesLoaded) return ocelot::PointerMap();
	
	ocelot::PointerMap mappings;

	_lock();
	
	if(sourceId >= _devices.size())
	{
		_unlock();
		Ocelot_Exception("Invalid source device - " << sourceId);
	}
	
	if(destinationId >= _devices.size())
	{
		_unlock();
		Ocelot_Exception("Invalid destination device - " << destinationId);
	}
	
	executive::Device& source = *_devices[sourceId];
	executive::Device& destination = *_devices[destinationId];
	
	_unlock();
	
	source.select();
	executive::Device::MemoryAllocationVector sourceAllocations = 
		source.getAllAllocations();
	source.unselect();
		
	for(executive::Device::MemoryAllocationVector::iterator 
		allocation = sourceAllocations.begin();
		allocation != sourceAllocations.end(); ++allocation)
	{
		size_t size = (*allocation)->size();
		void* pointer = (*allocation)->pointer();
		
		if(!(*allocation)->global())
		{
			char* temp = new char[size];
			source.select();
			(*allocation)->copy(temp, 0, size);
			source.free(pointer);
			source.unselect();

			destination.select();
			executive::Device::MemoryAllocation* dest = destination.allocate(
				size);
			dest->copy(0, temp, size);
			destination.unselect();
			
			report(" Mapping device allocation at " << pointer 
				<< " to " << dest->pointer());
			mappings.insert(std::make_pair(pointer,	dest->pointer()));
			delete[] temp;
		}
		else if((*allocation)->host())
		{
			destination.select();
			executive::Device::MemoryAllocation* dest = 
				destination.allocateHost(size, (*allocation)->flags());
			dest->copy(0, pointer, size);
			destination.unselect();

			mappings.insert(std::make_pair(pointer, dest->pointer()));
			
			source.select();
			source.free(pointer);
			source.unselect();
		}
	}

	for(ModuleMap::iterator module = _modules.begin(); 
		module != _modules.end(); ++module)
	{
		if( !module->second.loaded() ) continue;
		for(ir::Module::GlobalMap::const_iterator 
			global = module->second.globals().begin();
			global != module->second.globals().end(); ++global)
		{
			source.select();
			executive::Device::MemoryAllocation* sourceGlobal = 
				source.getGlobalAllocation(module->first, global->first);
			assert(sourceGlobal != 0);
			source.unselect();

			destination.select();
			executive::Device::MemoryAllocation* destinationGlobal = 
				destination.getGlobalAllocation(module->first, global->first);
			assert(destinationGlobal != 0);
			destination.unselect();
			
			char* temp = new char[sourceGlobal->size()];
			source.select();
			sourceGlobal->copy(temp, 0, sourceGlobal->size());
			source.unselect();

			destination.select();
			destinationGlobal->copy(0, temp, destinationGlobal->size());
			destination.unselect();
			delete[] temp;
		}
	}
		
	_unlock();
	
	return mappings;
#endif
	return ocelot::PointerMap();
}

void opencl::OpenCLRuntime::unregisterModule(const std::string& name) {
#if 0
	_lock();
	ModuleMap::iterator module = _modules.find(name);
	if (module == _modules.end()) {
		_unlock();
		Ocelot_Exception("Module - " << name << " - is not registered.");
	}
	
	Device::unregisterModuleForAll(name);	
	
	_modules.erase(module);
	
	_unlock();
#endif
}



void opencl::OpenCLRuntime::setOptimizationLevel(
	translator::Translator::OptimizationLevel l) {
	_lock();

	_optimization = l;

	Device::setOptimizationLevelForAll(l);	

	_unlock();
}
#endif
/*
void opencl::OpenCLRuntime::registerExternalFunction(const std::string& name,
	void* function) {
	
	_lock();

	report("Adding external function '" << name << "'");
	_externals.add(name, function);

	_unlock();
}

void opencl::OpenCLRuntime::removeExternalFunction(const std::string& name) {
	_lock();

	report("Removing external function '" << name << "'");

	_externals.remove(name);

	_unlock();	
}
*/
////////////////////////////////////////////////////////////////////////////////

cl_int opencl::OpenCLRuntime::clGetPlatformIDs(cl_uint num_entries, 
	cl_platform_id * platforms, 
	cl_uint * num_platforms) {
	cl_int result = CL_SUCCESS;
	_lock();

	try {
		if((num_entries == 0 && platforms != NULL) || (num_platforms == NULL && platforms == NULL))
			throw CL_INVALID_VALUE;
		
		_enumeratePlatforms(num_entries, platforms, num_platforms);

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
    return result;
}

cl_int opencl::OpenCLRuntime::clGetPlatformInfo(cl_platform_id platform, 
	cl_platform_info param_name,
	size_t param_value_size, 
	void * param_value,
	size_t * param_value_size_ret) {
	cl_int result = CL_SUCCESS;
	_lock();

	try {
		if(!platform->isValidObject(Object::OBJTYPE_PLATFORM))
			throw CL_INVALID_PLATFORM;

		if(!param_value && !param_value_size_ret)
			throw CL_INVALID_VALUE;
		
		platform->getInfo(param_name,
			param_value_size,
			param_value,
			param_value_size_ret);

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
	return result;
}
	

cl_int opencl::OpenCLRuntime::clGetDeviceIDs(cl_platform_id platform, 
    cl_device_type device_type, 
    cl_uint num_entries,
    cl_device_id * devices,
    cl_uint * num_devices) {
	
	cl_int result = CL_SUCCESS;

	_lock();

	try {
		if(!platform->isValidObject(Object::OBJTYPE_PLATFORM))
			throw CL_INVALID_PLATFORM;
	
		if(device_type < CL_DEVICE_TYPE_CPU || device_type > CL_DEVICE_TYPE_ALL)
			throw CL_INVALID_DEVICE_TYPE;
		
		if((num_entries == 0 && devices != NULL) || (num_devices == NULL && devices == NULL))
			throw CL_INVALID_VALUE;
 
		_enumerateDevices(platform, device_type, num_entries, devices, num_devices);
			
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
    return result;
}

cl_int opencl::OpenCLRuntime::clGetDeviceInfo(cl_device_id device,
	cl_device_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {
	cl_int result = CL_SUCCESS;
	_lock();
	
	try {

		if(!device->isValidObject(Object::OBJTYPE_DEVICE))
			throw CL_INVALID_DEVICE;

		if(!param_value && !param_value_size_ret)
			throw CL_INVALID_VALUE;

		device->getInfo(param_name, param_value_size, param_value,
			param_value_size_ret);

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}	

	_unlock();
	return result;
}

cl_context opencl::OpenCLRuntime::clCreateContext(const cl_context_properties * properties,
	cl_uint num_devices,
	const cl_device_id * devices,
	void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
	void * user_data,
	cl_int * errcode_ret) {
	
	_lock();
	cl_int err = CL_SUCCESS;

	Context * ctx = NULL;

	try {
		if(properties && properties[0] && (properties[0] != CL_CONTEXT_PLATFORM 
			|| properties[2] != 0 /*properties terminates with 0*/ ))
			throw CL_INVALID_PROPERTY;
		
		if(!((Platform *)properties[1])->isValidObject(Object::OBJTYPE_PLATFORM))
			throw CL_INVALID_PLATFORM;

		if(devices == 0 || num_devices == 0
			|| (pfn_notify == 0 && user_data != 0))
			throw CL_INVALID_VALUE;
		if(pfn_notify) {
			assertM(false, "call_back function unsupported\n");
			throw CL_UNIMPLEMENTED;
		}
		
		ctx = _createContext((Platform *)properties[1], num_devices, devices);
	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();

	if(errcode_ret)
		*errcode_ret = err;
	return (cl_context)(ctx);
}

cl_command_queue opencl::OpenCLRuntime::clCreateCommandQueue(cl_context context, 
	cl_device_id device, 
	cl_command_queue_properties properties,
	cl_int * errcode_ret) {
	
	CommandQueue * queue = NULL;
	
	_lock();
	cl_int err = CL_SUCCESS;

	try {
		if(std::find(_contexts.begin(), _contexts.end(), context) == _contexts.end())
			throw CL_INVALID_CONTEXT;
		
		if(std::find(context->validDevices.begin(), context->validDevices.end(), device) 
			== context->validDevices.end())//Not found
			throw CL_INVALID_DEVICE;
	
		if(properties > (CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE |
						CL_QUEUE_PROFILING_ENABLE))
			throw CL_INVALID_VALUE;
		
		if((properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE) 
			||(properties & CL_QUEUE_PROFILING_ENABLE)) {
			assertM(false, "unimplemented queue properties");
			throw CL_UNIMPLEMENTED;
		}

		try {
			queue = new CommandQueue(context, device, properties);
			_queues.push_back(queue);
		}
		catch(...) {
			throw CL_OUT_OF_HOST_MEMORY;
		}
		context->validQueues.push_back(queue);
		
	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}
	if(errcode_ret)
		*errcode_ret = err;
	_unlock();
	return (cl_command_queue)queue;
}

cl_program opencl::OpenCLRuntime::clCreateProgramWithSource(cl_context context,
	cl_uint count,
	const char ** strings,
	const size_t * lengths,
	cl_int * errcode_ret) {
	
	_lock();
	cl_int err = CL_SUCCESS;
	Program * program = NULL;

	try {
		if(!context->isValidObject(Object::OBJTYPE_CONTEXT))
			throw CL_INVALID_CONTEXT;
		
		if(count == 0 || strings == 0)
			throw CL_INVALID_VALUE;
		
		program = new Program(context, count, strings, lengths, Program::PROGRAM_SOURCE);

	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}

	if(errcode_ret)
		*errcode_ret = err;
	_unlock();

	return (cl_program)program;
}

cl_int opencl::OpenCLRuntime::clBuildProgram(cl_program program,
	cl_uint num_devices,
	const cl_device_id * device_list,
	const char * options, 
	void (CL_CALLBACK * pfn_notify)(cl_program, void *),
	void * user_data) {
	cl_int result = CL_SUCCESS;
	_lock();
	try {
		
		if(!program->isValidObject(Object::OBJTYPE_PROGRAM))//Not program object
			throw CL_INVALID_PROGRAM;

		if((num_devices == 0 && device_list) || (num_devices && device_list == NULL))
			throw CL_INVALID_VALUE;

		if(pfn_notify == NULL && user_data)
			throw CL_INVALID_VALUE;

		if(options || pfn_notify || user_data) {
			assertM(false, "unsupported options, pfn_nofify or user_data arguments");
			throw CL_UNIMPLEMENTED;
		}

		if(!program->setupDevices(num_devices, device_list))
			throw CL_INVALID_DEVICE;

		program->build(options, pfn_notify, user_data);
								
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_BUILD_PROGRAM_FAILURE;
	}
	
	_unlock();
	return result;
}

cl_int opencl::OpenCLRuntime::clGetProgramInfo(cl_program program,
	cl_program_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {
	cl_int result = CL_SUCCESS;
	_lock();
	
	try {
		
		if(!program->isValidObject(Object::OBJTYPE_PROGRAM))
			throw CL_INVALID_PROGRAM;

		program->getInfo(param_name, param_value_size, param_value, param_value_size_ret);

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();
	return result;
}

cl_kernel opencl::OpenCLRuntime::clCreateKernel(cl_program program,
	const char * kernel_name,
	cl_int * errcode_ret) {
	
	cl_int err = CL_SUCCESS;	

	Kernel * kernel = NULL;

	_lock();

	try{

		if(!program->isValidObject(Object::OBJTYPE_PROGRAM))//Not found
			throw CL_INVALID_PROGRAM;

		kernel = program->createKernel(kernel_name);
	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}

	if(errcode_ret)
		*errcode_ret = err;
	_unlock();
	return (cl_kernel)kernel;
}

cl_mem opencl::OpenCLRuntime::clCreateBuffer(cl_context context,
	cl_mem_flags flags,
	size_t size,
	void * host_ptr,
	cl_int * errcode_ret) {

	BufferObject * buffer = NULL;
	_lock();
	cl_int err = CL_SUCCESS;

	try {
		if(find(_contexts.begin(), _contexts.end(), context) == _contexts.end())
			throw CL_INVALID_CONTEXT;

		if((flags & CL_MEM_READ_ONLY) 
			&& ((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_WRITE_ONLY)))
			throw CL_INVALID_VALUE;
		if((flags & CL_MEM_WRITE_ONLY) 
			&& ((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_READ_ONLY)))
			throw CL_INVALID_VALUE;

		if((flags & CL_MEM_ALLOC_HOST_PTR) && (flags & CL_MEM_COPY_HOST_PTR))
			throw CL_INVALID_VALUE;
		
		if(size == 0)
			throw CL_INVALID_BUFFER_SIZE;

		if((!host_ptr && ((flags & CL_MEM_USE_HOST_PTR) || (flags & CL_MEM_COPY_HOST_PTR)))
			|| (host_ptr && !(flags & CL_MEM_USE_HOST_PTR) && !(flags & CL_MEM_COPY_HOST_PTR)))
			throw CL_INVALID_HOST_PTR;

		if(host_ptr) {
			assertM(false, "unsuported host_ptr");
			throw CL_UNIMPLEMENTED;
		}

		std::map< Device *, void * > allocations;
		for(DeviceList::iterator device = context->validDevices.begin();
			device != context->validDevices.end(); device++) {
			try {
				void * allocation =  (*device)->allocate(size);
				if(allocation == NULL) throw;
				allocations.insert(std::make_pair(*device, allocation));
				report("clCreateBuffer() return address = " <<  allocation << ", size = " << size);
			}
			catch(...) {
				throw CL_OUT_OF_RESOURCES;
			}

		}

		try {
			buffer = new BufferObject(allocations, context, flags, size);
			_memories.push_back(buffer);
		}
		catch(...) {
			throw CL_OUT_OF_HOST_MEMORY;
		}
		context->validMemories.push_back(buffer);

	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}

	if(errcode_ret)
		*errcode_ret = err;
	_unlock();
	return (cl_mem)buffer;
}

cl_int opencl::OpenCLRuntime::clEnqueueReadBuffer(cl_command_queue command_queue,
	cl_mem buffer,
	cl_bool blocking_read,
	size_t offset,
	size_t cb, 
	void * ptr,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) {
	cl_int result = CL_SUCCESS;
	_lock();

	try {
		
		if(std::find(_queues.begin(), _queues.end(), command_queue) == _queues.end())
			throw CL_INVALID_COMMAND_QUEUE;

		if(std::find(_memories.begin(), _memories.end(), buffer) == _memories.end())
			throw CL_INVALID_MEM_OBJECT;

		if(buffer->type() != CL_MEM_OBJECT_BUFFER)
			throw CL_INVALID_MEM_OBJECT;

		if(command_queue->context() != buffer->context())
			throw CL_INVALID_CONTEXT;

		if(offset >= buffer->size() || cb + offset > buffer->size())
			throw CL_INVALID_VALUE;
		
		if(ptr == NULL)
			throw CL_INVALID_VALUE;

		if(event_wait_list == NULL && num_events_in_wait_list > 0)
			throw CL_INVALID_EVENT_WAIT_LIST;

		if(event_wait_list && num_events_in_wait_list == 0)
			throw CL_INVALID_EVENT_WAIT_LIST;

		if(event_wait_list) {
			assertM(false, "non-null event wait list is no supported!");
			throw CL_UNIMPLEMENTED;
		}

		if(event) {
			assertM(false, "non-null event is not supported!");
			throw CL_UNIMPLEMENTED;
		}

		if(blocking_read == false) {
			assertM(false, "unblocking read is not supported!");
			throw CL_UNIMPLEMENTED;
		}

		std::map<Device *, void *> & allocations = buffer->allocations;
		Device * device = command_queue->device();
		if(allocations.find(device) == allocations.end() || allocations.find(device)->second == NULL)
			throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

		void * allocation = allocations.find(device)->second;
		if(!device->read(allocation, ptr, offset, cb))
			throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
	return result;
}

cl_int opencl::OpenCLRuntime::clEnqueueWriteBuffer(cl_command_queue command_queue,
	cl_mem buffer,
	cl_bool blocking_write,
	size_t offset,
	size_t cb, 
	const void * ptr,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) {
	cl_int result = CL_SUCCESS;
	_lock();

	try {

		if(std::find(_queues.begin(), _queues.end(), command_queue) == _queues.end())
			throw CL_INVALID_COMMAND_QUEUE;

		if(std::find(_memories.begin(), _memories.end(), buffer) == _memories.end())
			throw CL_INVALID_MEM_OBJECT;

		if(command_queue->context() != buffer->context())
			throw CL_INVALID_CONTEXT;

		if(offset >= buffer->size() || cb + offset > buffer->size())
			throw CL_INVALID_VALUE;
		
		if(ptr == NULL)
			throw CL_INVALID_VALUE;

		if(event_wait_list == NULL && num_events_in_wait_list > 0)
			throw CL_INVALID_EVENT_WAIT_LIST;

		if(event_wait_list && num_events_in_wait_list == 0)
			throw CL_INVALID_EVENT_WAIT_LIST;

		if(event_wait_list) {
			assertM(false, "non-null event wait list is no supported!");
			throw CL_UNIMPLEMENTED;
		}

		if(event) {
			assertM(false, "non-null event is not supported!");
			throw CL_UNIMPLEMENTED;
		}

		if(blocking_write == false) {
			assertM(false, "unblocking write is not supported!");
			throw CL_UNIMPLEMENTED;
		}

		std::map<Device *, void *> & allocations = buffer->allocations;
		Device * device = command_queue->device();
		if(allocations.find(device) == allocations.end() || allocations.find(device)->second == NULL)
			throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

		void * allocation = allocations.find(device)->second;

		if(!device->write(allocation, ptr, offset, cb))
			throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
	return result;
}

cl_int opencl::OpenCLRuntime::clSetKernelArg(cl_kernel kernel,
	cl_uint arg_index,
	size_t arg_size,
	const void * arg_value) {
	cl_int result = CL_SUCCESS;

	_lock();

	try {
		if(!kernel->isValidObject(Object::OBJTYPE_KERNEL))
			throw CL_INVALID_KERNEL;

		kernel->setArg(arg_index, arg_size, arg_value);	
		
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();
	return result;
}

cl_int opencl::OpenCLRuntime::clEnqueueNDRangeKernel(cl_command_queue command_queue,
	cl_kernel kernel,
	cl_uint work_dim,
	const size_t * global_work_offset,
	const size_t * global_work_size,
	const size_t * local_work_size,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) {
	cl_int result = CL_SUCCESS;

	_lock();

	try {
		if(std::find(_queues.begin(), _queues.end(), command_queue) == _queues.end())
			throw CL_INVALID_COMMAND_QUEUE;

		if(!kernel->isValidObject(Object::OBJTYPE_KERNEL))
			throw CL_INVALID_KERNEL;

		if(!kernel->isValidContext(command_queue->context()))
			throw CL_INVALID_CONTEXT;

		if((event_wait_list == NULL && num_events_in_wait_list > 0) || (event_wait_list && num_events_in_wait_list == 0))
			throw CL_INVALID_EVENT_WAIT_LIST;
	
		kernel->mapParametersOnDevice(command_queue->device());
		
		kernel->setConfiguration(work_dim, global_work_offset, global_work_size, local_work_size);	

		kernel->launchOnDevice(command_queue->device());
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();
	return result;
}
