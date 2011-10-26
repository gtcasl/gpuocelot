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

////////////////////////////////////////////////////////////////////////////////

opencl::HostThreadContext::HostThreadContext(): selectedDevice(0),
	lastError(CL_SUCCESS) {
}

opencl::HostThreadContext::~HostThreadContext() {
}

opencl::HostThreadContext::HostThreadContext(const HostThreadContext& c): 
	selectedDevice(c.selectedDevice),
	validDevices(c.validDevices),
	lastError(c.lastError),
	persistentTraceGenerators(c.persistentTraceGenerators),
	nextTraceGenerators(c.nextTraceGenerators) {
}

opencl::HostThreadContext& opencl::HostThreadContext::operator=(
	const HostThreadContext& c) {
	if(&c == this) return *this;
	selectedDevice = c.selectedDevice;
	validDevices = c.validDevices;
	lastError = c.lastError;
	persistentTraceGenerators = c.persistentTraceGenerators;
	nextTraceGenerators = c.nextTraceGenerators;
	return *this;
}

opencl::HostThreadContext::HostThreadContext(HostThreadContext&& c): 
	selectedDevice(0) {
	*this = std::move(c);
}

opencl::HostThreadContext& opencl::HostThreadContext::operator=(
	HostThreadContext&& c) {
	if (this == &c) return *this;
	std::swap(selectedDevice, c.selectedDevice);
	std::swap(validDevices, c.validDevices);
	std::swap(lastError, c.lastError);
	std::swap(persistentTraceGenerators, c.persistentTraceGenerators);
	std::swap(nextTraceGenerators, c.nextTraceGenerators);
	return *this;
}


void opencl::HostThreadContext::clear() {
	validDevices.clear();
	persistentTraceGenerators.clear();
	nextTraceGenerators.clear();
}



////////////////////////////////////////////////////////////////////////////////
unsigned int opencl::Program::_id = 0;


opencl::Program::Program(const std::string & s, const void * c): 
		source(s), built(false), context(c) {
	std::stringstream stream;
	stream << "__clmodule_" << _id;
	name = stream.str();
	_id++;
}

////////////////////////////////////////////////////////////////////////////////
opencl::RegisteredKernel::RegisteredKernel(const std::string &k, const int p,
const void * c): kernel(k), program(p), context(c) {
	parameterBlock = NULL;
}

opencl::RegisteredKernel::~RegisteredKernel()
{
	PointerMap::iterator pointer;
	for(pointer = parameterPointers.begin(); pointer != parameterPointers.end(); pointer++) {
		delete pointer->second;
	}

	if(parameterBlock)
		delete parameterBlock;
}


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

void opencl::OpenCLRuntime::_enumerateDevices() {
	if(_devicesLoaded) return;
	report("Creating devices.");
	if(config::get().executive.enableNVIDIA) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::SASS, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " nvidia gpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableEmulated) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::Emulated, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " emulator devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableLLVM) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::LLVM, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " llvm-cpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
		
		if (config::get().executive.workerThreadLimit > 0) {
			for (executive::DeviceVector::iterator d_it = d.begin();
				d_it != d.end(); ++d_it) {
				(*d_it)->limitWorkerThreads(
					config::get().executive.workerThreadLimit);
			}
		}
	}
	if(config::get().executive.enableAMD) {
		executive::DeviceVector d =
			executive::Device::createDevices(ir::Instruction::CAL, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " amd gpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableRemote) {
		executive::DeviceVector d =
			executive::Device::createDevices(ir::Instruction::Remote, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " remote devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	
	_devicesLoaded = true;
	
	if(_devices.empty())
	{
		std::cerr << "==Ocelot== WARNING - No CUDA devices found or all " 
			<< "devices disabled!\n";
		std::cerr << "==Ocelot==  Consider enabling the emulator in " 
			<< "configure.ocelot.\n";
	}

	
}

//! acquires mutex and locks the runtime
void opencl::OpenCLRuntime::_lock() {
	_mutex.lock();
}

//! releases mutex
void opencl::OpenCLRuntime::_unlock() {
	_mutex.unlock();
}

//! sets the last error state for the OpenCLRuntime object
cl_int opencl::OpenCLRuntime::_setLastError(cl_int result) {
	HostThreadContext& thread = _getCurrentThread();
	thread.lastError = result;
	return result;
}

opencl::HostThreadContext& opencl::OpenCLRuntime::_bind() {
	_enumerateDevices();

	HostThreadContext& thread = _getCurrentThread();

	if (_devices.empty()) return thread;
	
	_selectedDevice = thread.selectedDevice;
	executive::Device& device = _getDevice();

	assert(!device.selected());
	device.select();
	
	return thread;
}

void opencl::OpenCLRuntime::_unbind() {
	executive::Device& device = _getDevice();
	assert(_getCurrentThread().selectedDevice == _selectedDevice);
	
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

executive::Device& opencl::OpenCLRuntime::_getDevice() {
	return *((executive::Device *)_selectedDevice);
}

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
}

opencl::HostThreadContext& opencl::OpenCLRuntime::_getCurrentThread() {
	HostThreadContextMap::iterator t = _threads.find(
		boost::this_thread::get_id());
	if (t == _threads.end()) {
		report("Creating new context for thread "
			<< boost::this_thread::get_id());
		t = _threads.insert(std::make_pair(boost::this_thread::get_id(), 
			new HostThreadContext())).first;
	}
	return *(t->second);
}


void opencl::OpenCLRuntime::_registerModule(ModuleMap::iterator module, int device) {
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
	executive::Device & d =*(_devices[device]);
	d.select();
	d.load(&module->second);
	d.setOptimizationLevel(_optimization);
	d.unselect();
}

void opencl::OpenCLRuntime::_registerModule(const std::string& name, int device) {
	ModuleMap::iterator module = _modules.find(name);
	if(module != _modules.end()) {
		_registerModule(module, device);
	}
}

void opencl::OpenCLRuntime::_registerAllModules(int device) {
	for(ModuleMap::iterator module = _modules.begin(); 
		module != _modules.end(); ++module) {
		_registerModule(module, device);
	}
}

void opencl::OpenCLRuntime::_mapKernelParameters(RegisteredKernel & kernel, int device) {

	const Program & prog = *(_programs[kernel.program]);
	assert(prog.ptxModule.find(device) != prog.ptxModule.end());

	const std::string & moduleName = prog.ptxModule.find(device)->second;
	assert(_modules.find(moduleName) != _modules.end());

	const std::string & kernelName = kernel.kernel;
	const ir::Kernel * k = _modules.find(moduleName)->second.getKernel(kernelName);

	if(k->arguments.size() != kernel.parameterSizes.size())
		throw CL_INVALID_KERNEL_ARGS;

	//Get aligned parameter sizes	
	kernel.parameterBlockSize = 0;
	kernel.parameterOffsets.clear();
	unsigned int argId = 0;
	for (ir::Kernel::ParameterVector::const_iterator parameter = k->arguments.begin(); 
		parameter != k->arguments.end(); ++parameter, ++argId) {
		kernel.parameterOffsets[argId] = kernel.parameterBlockSize;
		unsigned int misalignment = (kernel.parameterBlockSize) % parameter->getAlignment();
		unsigned int alignmentOffset = misalignment == 0 
			? 0 : parameter->getAlignment() - misalignment;
		kernel.parameterBlockSize += alignmentOffset;
		kernel.parameterBlockSize += parameter->getSize();
	}

	if(kernel.parameterBlock)
	{
		delete[] kernel.parameterBlock;
		kernel.parameterBlock = NULL;
	}
	try {
		kernel.parameterBlock = new char[kernel.parameterBlockSize];
		assert(kernel.parameterBlock);
		memset(kernel.parameterBlock, 0, kernel.parameterBlockSize);
	}
	catch(...) {
		throw CL_OUT_OF_HOST_MEMORY;
	}

	//Copy parameters to aligned offset
	assert(kernel.parameterSizes.size() == kernel.parameterPointers.size());
	assert(kernel.parameterSizes.size() == kernel.parameterOffsets.size());
	argId = 0;
	for(SizeMap::iterator size = kernel.parameterSizes.begin();
		size != kernel.parameterSizes.end(); size++, argId++) {
		assert(size->first == argId);
		assert(kernel.parameterPointers.find(argId) != kernel.parameterPointers.end());
		assert(kernel.parameterOffsets.find(argId) != kernel.parameterOffsets.end());
		
		unsigned int offset = kernel.parameterOffsets[argId];
		size_t oriSize = size->second;
		size_t argSize = k->arguments[argId].getSize();
		void * pointer = kernel.parameterPointers[argId];

		//check if it is a memory address argument
		if(oriSize == sizeof(cl_mem) &&  
			_memories.find((MemoryObject *)(*(cl_mem *)pointer)) != _memories.end()) {//pointer is memory object
		
			if(argSize != sizeof(void *))
				throw CL_INVALID_KERNEL_ARGS;

			MemoryObject & mem = *((MemoryObject *)(*(cl_mem *)pointer));
			if(mem.allocations.find(device) == mem.allocations.end())
				throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

			void * addr = mem.allocations[device]->pointer();
			memcpy(kernel.parameterBlock + offset, &addr, argSize);
		}
		else { //non-memory argument
			if(oriSize != argSize)
				throw CL_INVALID_KERNEL_ARGS;

			memcpy(kernel.parameterBlock + offset, pointer, argSize);
		}

	}
}
////////////////////////////////////////////////////////////////////////////////

opencl::OpenCLRuntime::OpenCLRuntime() : _inExecute(false), _deviceCount(0),
	_devicesLoaded(false), 
	_selectedDevice(NULL), _nextSymbol(1), _computeCapability(2), _flags(0), 
	_optimization((translator::Translator::OptimizationLevel)
		config::get().executive.optimizationLevel) {

	// get device count
	if(config::get().executive.enableNVIDIA) {
		_deviceCount += executive::Device::deviceCount(
			ir::Instruction::SASS, _computeCapability);
	}
	if(config::get().executive.enableEmulated) {
		_deviceCount += executive::Device::deviceCount(
			ir::Instruction::Emulated, _computeCapability);
	}
	if(config::get().executive.enableLLVM) {
		_deviceCount += executive::Device::deviceCount(
			ir::Instruction::LLVM, _computeCapability);
	}
	if(config::get().executive.enableAMD) {
		_deviceCount += executive::Device::deviceCount(
			ir::Instruction::CAL, _computeCapability);
	}
	if(config::get().executive.enableRemote) {
		_deviceCount += executive::Device::deviceCount(
			ir::Instruction::Remote, _computeCapability);
	}
}

opencl::OpenCLRuntime::~OpenCLRuntime() {
	//
	// free things that need freeing
	//
	// devices
	for (DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device) {
		delete *device;
	}
	
	// mutex

	// thread contexts
	for(HostThreadContextMap::iterator thread = _threads.begin();
		thread != _threads.end(); ++thread) {
		delete thread->second;
	}
	
	// textures
	
	// programs
	for (ProgramVector::iterator program = _programs.begin();
		program != _programs.end(); ++program) {
		delete *program;
	}

	// kernels
	for (RegisteredKernelVector::iterator kernel = _kernels.begin();
		kernel != _kernels.end(); ++kernel) {
		delete *kernel;
	}

	// memory objects
	for (MemoryObjectSet::iterator memory = _memories.begin();
		memory != _memories.end(); ++memory) {
		delete *memory;
	}

	// command queues
	for (CommandQueueVector::iterator queue = _queues.begin();
		queue != _queues.end(); ++queue) {
		delete *queue;
	}
	
	// fat binaries
	
	// config
	config::destroy();
	
	// globals
}



////////////////////////////////////////////////////////////////////////////////
/*
void opencl::OpenCLRuntime::addTraceGenerator( trace::TraceGenerator& gen,
	bool persistent ) {
	_lock();
	HostThreadContext& thread = _getCurrentThread();
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
	HostThreadContext& thread = _getCurrentThread();
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
*/
void opencl::OpenCLRuntime::limitWorkerThreads(unsigned int limit) {
	_acquire();
	for (DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device) {
		(*device)->limitWorkerThreads(limit);
	}
	_release();
}

void opencl::OpenCLRuntime::registerPTXModule(std::istream& ptx, 
	const std::string& name) {
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
}

/*
void opencl::OpenCLRuntime::registerTexture(const void* texref,
	const std::string& moduleName,
	const std::string& textureName, bool normalize) {
	_lock();
	
	report("registerTexture('" << textureName << ", norm: " << normalize );

	_textures[(void*)texref] = RegisteredTexture(moduleName,
		textureName, normalize);
	
	_unlock();
}
*/
void opencl::OpenCLRuntime::clearErrors() {
	_lock();
	HostThreadContext& thread = _getCurrentThread();
	thread.lastError = CL_SUCCESS;
	_unlock();
}

void opencl::OpenCLRuntime::reset() {
	_lock();
	report("Resetting opencl runtime.");
	HostThreadContext& thread = _getCurrentThread();
	thread.clear();
	//_dimensions.clear();
	
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
}

ocelot::PointerMap opencl::OpenCLRuntime::contextSwitch(unsigned int destinationId, 
	unsigned int sourceId) {
	report("Context switching from " << sourceId << " to " << destinationId);
	
	if(!_devicesLoaded) return ocelot::PointerMap();
	
	ocelot::PointerMap mappings;

	_acquire();
	
	if(sourceId >= _devices.size())
	{
		_release();
		Ocelot_Exception("Invalid source device - " << sourceId);
	}
	
	if(destinationId >= _devices.size())
	{
		_release();
		Ocelot_Exception("Invalid destination device - " << destinationId);
	}
	
	executive::Device& source = *_devices[sourceId];
	executive::Device& destination = *_devices[destinationId];
	
	_unbind();
	
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
}

void opencl::OpenCLRuntime::unregisterModule(const std::string& name) {
	_lock();
	ModuleMap::iterator module = _modules.find(name);
	if (module == _modules.end()) {
		_unlock();
		Ocelot_Exception("Module - " << name << " - is not registered.");
	}
	
	for (DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device) {
		(*device)->select();
		(*device)->unload(name);
		(*device)->unselect();
	}
	
	_modules.erase(module);
	
	_unlock();
}

static ir::Dim3 convert(const size_t d[3]) {
	return std::move(ir::Dim3(d[0], d[1], d[2]));
}

void opencl::OpenCLRuntime::_launchKernel(RegisteredKernel &kernel, cl_device_id device)
{
	const std::string & kernelName = kernel.kernel;
	assert(_programs[kernel.program]->built);
	assert(_programs[kernel.program]->ptxModule.find(device) != _programs[kernel.program]->ptxModule.end());
	const std::string & moduleName = _programs[kernel.program]->ptxModule[device];

	report("kernel launch (" << kernelName 
		<< ") on thread " << boost::this_thread::get_id());
	
	try {
		HostThreadContext &thread = _getCurrentThread();
		trace::TraceGeneratorVector traceGens;

		traceGens = thread.persistentTraceGenerators;
		traceGens.insert(traceGens.end(),
			thread.nextTraceGenerators.begin(), 
			thread.nextTraceGenerators.end());

		_inExecute = true;

		executive::Device & d = *(_devices[device]);
		d.launch(moduleName, kernelName, convert(kernel.workGroupNum), 
			convert(kernel.localWorkSize), /*launch.sharedMemory*/0, 
			kernel.parameterBlock, kernel.parameterBlockSize, traceGens, NULL/*&_externals*/);
		_inExecute = false;
		report(" launch completed successfully");	
	}
	catch( const executive::RuntimeException& e ) {
		std::cerr << "==Ocelot== PTX Emulator failed to run kernel \"" 
			<< kernelName 
			<< "\" with exception: \n";
		std::cerr << _formatError( e.toString() ) 
			<< "\n" << std::flush;
		_inExecute = false;
		throw;
	}
	catch( const std::exception& e ) {
		std::cerr << "==Ocelot== " << _getDevice().properties().name
			<< " failed to run kernel \""
			<< kernelName
			<< "\" with exception: \n";
		std::cerr << _formatError( e.what() )
			<< "\n" << std::flush;
		throw;
	}
	catch(...) {
		throw;
	}
}


void opencl::OpenCLRuntime::setOptimizationLevel(
	translator::Translator::OptimizationLevel l) {
	_lock();

	_optimization = l;
	for (DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device) {
		(*device)->select();
		(*device)->setOptimizationLevel(l);
		(*device)->unselect();
	}

	_unlock();
}
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

		//Assume only 1 platform, platform_id = 0
		if(platforms)
			*platforms = 0;

		if(num_platforms)
			*num_platforms = 1;
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
    return _setLastError(result);
}

cl_int opencl::OpenCLRuntime::clGetPlatformInfo(cl_platform_id platform, 
	cl_platform_info param_name,
	size_t param_value_size, 
	void * param_value,
	size_t * param_value_size_ret) {
	cl_int result = CL_SUCCESS;
	_lock();
	if(platform)
		result = CL_INVALID_PLATFORM;
	else if(!param_value && !param_value_size_ret)
		result = CL_INVALID_VALUE;
	else {
		switch(param_name) {
			case CL_PLATFORM_NAME: {
				char ocelotPlatform[] = "Ocelot";						
				if(param_value && param_value_size < strlen(ocelotPlatform))
					result = CL_INVALID_VALUE;
				else {
					if(param_value != 0)
						strcpy((char *)param_value, ocelotPlatform);
					if(param_value_size_ret != 0)
						*param_value_size_ret = strlen(ocelotPlatform);
				}
				break;
			}
			case CL_PLATFORM_VERSION: {
				char ocelotVersion[] = "2.1";
				if(param_value && param_value_size < strlen(ocelotVersion))
					result = CL_INVALID_VALUE;
				else {
					if(param_value != 0)
						strcpy((char *)param_value, ocelotVersion);
					if(param_value_size_ret != 0)
						*param_value_size_ret = strlen(ocelotVersion);
				}
				break;
			}
			default:
				assertM(false, "Platform info unimplemented!\n");
				result = CL_UNIMPLEMENTED;
				break;
		}
	}
	_unlock();
	return _setLastError(result);
}
	

cl_int opencl::OpenCLRuntime::clGetDeviceIDs(cl_platform_id platform, 
    cl_device_type device_type, 
    cl_uint num_entries,
    cl_device_id * devices,
    cl_uint * num_devices) {
	
	cl_int result = CL_SUCCESS;

	_lock();

	try {
		if(platform) //Temorarily assume platform=0
			throw CL_INVALID_PLATFORM;
		
		if(device_type < CL_DEVICE_TYPE_CPU || device_type > CL_DEVICE_TYPE_ALL)
			throw CL_INVALID_DEVICE_TYPE;
		
		if((num_entries == 0 && devices != NULL) || (num_devices == NULL && devices == NULL))
			throw CL_INVALID_VALUE;
 
		_enumerateDevices();
		if (_devices.empty())
			throw CL_DEVICE_NOT_FOUND;
		
		if(num_devices != 0)
			*num_devices = _devices.size();
	
		if(devices != 0) {
			for(cl_uint i = 0; i < std::min(_devices.size(), (size_t)num_entries); i++)
				devices[i] = i;
		}
	
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
    return _setLastError(result);
}

cl_int opencl::OpenCLRuntime::clGetDeviceInfo(cl_device_id device,
	cl_device_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {
	cl_int result = CL_SUCCESS;
	_lock();
	if(device == -1 || device >= (int)_devices.size())
		result = CL_INVALID_DEVICE;
	else if(!param_value && !param_value_size_ret)
		result = CL_INVALID_VALUE;
	else {
		const executive::Device::Properties & prop = (_devices[device])->properties();
		switch(param_name) {
			case CL_DEVICE_NAME:
				if(param_value && param_value_size < strlen(prop.name))
					result = CL_INVALID_VALUE;
				else {
					if(param_value != 0)
						strcpy((char *)param_value, prop.name);
					if(param_value_size_ret !=0 )
						*param_value_size_ret = strlen(prop.name);
				}
				break;
			default:
				assertM(false, "Device info unimplemented!\n");
				result = CL_UNIMPLEMENTED;
				break;
		}
	}

	_unlock();
	return _setLastError(result);
}

cl_context opencl::OpenCLRuntime::clCreateContext(const cl_context_properties * properties,
	cl_uint num_devices,
	const cl_device_id * devices,
	void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
	void * user_data,
	cl_int * errcode_ret) {
	
	cl_context context = NULL;
	_lock();
	cl_int err = CL_SUCCESS;

	//Assume ocelot platform is always availbe, but platform_id in properties should be zero
	if(properties && properties[0] && (properties[0] != CL_CONTEXT_PLATFORM 
		|| properties[2] != 0 /*properties terminates with 0*/ ))
		err = CL_INVALID_PROPERTY;
	else if(properties[1] != 0 /*platform_id should be zero*/)
		err = CL_INVALID_PLATFORM;
	else if(devices == 0 || num_devices == 0
		|| (pfn_notify == 0 && user_data != 0))
		err = CL_INVALID_VALUE;
	else if(pfn_notify) {
		assertM(false, "call_back function unsupported\n");
		err = CL_UNIMPLEMENTED;
	}
	else {
		HostThreadContext &thread = _getCurrentThread();
		for (cl_uint i = 0; i < num_devices; i++) {
			if(devices[i] == -1 || devices[i] >= (int)_devices.size()) {
				err = CL_INVALID_DEVICE;
				break;
			}
			thread.validDevices.insert(devices[i]);
		}
		if(err == CL_SUCCESS)
			context = (cl_context) &thread;
	}
	_setLastError(err);
	if(errcode_ret)
		*errcode_ret = err;
	_unlock();
	return context;
}

cl_command_queue opencl::OpenCLRuntime::clCreateCommandQueue(cl_context context, 
	cl_device_id device, 
	cl_command_queue_properties properties,
	cl_int * errcode_ret) {
	
	cl_command_queue queue = -1;
	
	_lock();
	cl_int err = CL_SUCCESS;

	try {
		HostThreadContext &thread = _getCurrentThread();
		if(context != (void *)&thread)
			throw CL_INVALID_CONTEXT;
		
		if(thread.validDevices.find(device) == thread.validDevices.end())//Not found
			throw CL_INVALID_DEVICE;
	
		if(properties > (CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE |
						CL_QUEUE_PROFILING_ENABLE))
			throw CL_INVALID_VALUE;
		
		if((properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE) 
			||(properties & CL_QUEUE_PROFILING_ENABLE)) {
			assertM(false, "unimplemented queue properties");
			throw CL_UNIMPLEMENTED;
		}

		executive::Device &d = *(_devices[device]);
		d.select();
		unsigned int stream;
		try {
			stream = d.createStream();
		}
		catch(...) {
			d.unselect();
			throw CL_OUT_OF_RESOURCES;
		}
		d.unselect();

		try {
			_queues.push_back(new CommandQueue(context, device, properties, stream));
		}
		catch(...) {
			throw CL_OUT_OF_HOST_MEMORY;
		}
		queue = _queues.size()-1;
		thread.validQueues.insert(queue);
		
	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}
	_setLastError(err);
	if(errcode_ret)
		*errcode_ret = err;
	_unlock();
	return queue;
}

cl_program opencl::OpenCLRuntime::clCreateProgramWithSource(cl_context context,
	cl_uint count,
	const char ** strings,
	const size_t * lengths,
	cl_int * errcode_ret) {
	
	cl_program program = -1;
	
	_lock();
	cl_int err = CL_SUCCESS;
	HostThreadContext &thread = _getCurrentThread();
	if(context != (void *)&thread)
		err = CL_INVALID_CONTEXT;
	else if(count == 0 || strings == 0)
		err = CL_INVALID_VALUE;
	else {
		cl_uint i;
		for(i = 0; i < count; i++) {
			if(strings[i] == 0) {
				err = CL_INVALID_VALUE;
				break;
			}
		}
		if(i == count) {//valid string 
			std::stringstream stream;
			for(i = 0; i < count; i++)
				stream << strings[i];
			_programs.push_back(new Program(stream.str(), context));
			program = _programs.size()-1;
			thread.validPrograms.insert(program);
		}
	}

	_setLastError(err);
	if(errcode_ret)
		*errcode_ret = err;
	_unlock();

	return program;
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
		HostThreadContext &thread = _getCurrentThread();
		
		if(thread.validPrograms.find(program) == thread.validPrograms.end())//Not found
			throw CL_INVALID_PROGRAM;

		if((num_devices == 0 && device_list) || (num_devices && device_list == NULL))
			throw CL_INVALID_VALUE;

		if(pfn_notify == NULL && user_data)
			throw CL_INVALID_VALUE;

		for(cl_uint i = 0; i < num_devices; i++) {
			if(thread.validDevices.find(device_list[i]) == thread.validDevices.end()) {//Not found
				throw CL_INVALID_DEVICE;
				break;
			}
		}

		if(options || pfn_notify || user_data) {
			assertM(false, "unsupported options, pfn_nofify or user_data arguments");
			throw CL_UNIMPLEMENTED;
		}

		Program &prog = *(_programs[program]);
		//For source building, since we don't have opencl frontend, load buildout.ptx instead
		if(!prog.ptxModule.empty() && !prog.built) {
			assertM(false, "unsupported binary. note that clCreateProgramWithBinaries is currently unsupported!");
			throw CL_UNIMPLEMENTED;
		}

		if(!prog.built) {
			//Not built is loaded
			std::ifstream ptx("buildout.ptx", std::ifstream::in); //Temorarily load ptx file as built binary
			if(ptx.fail()) {
				assertM(false, "buildout.ptx not found, run opencl program with libOpenCL first!");
				throw CL_BUILD_PROGRAM_FAILURE;
			}
				
			std::string temp;
		
			ptx.seekg(0, std::ios::end);
			size_t size = ptx.tellg();
			ptx.seekg(0, std::ios::beg);
			
			if(!size) {
				assertM(false, "buildout.ptx is empty!");
				throw CL_BUILD_PROGRAM_FAILURE;
			}
	
			temp.resize(size);
			ptx.read((char*)temp.data(), size);
	
			// Register ptx with device
			IndexSet devices;
			if(num_devices) {
				for(cl_uint i = 0; i < num_devices; i++)
					devices.insert((device_list[i]));
			}
			else
				devices = thread.validDevices;
	
			try{
				for(IndexSet::iterator d = devices.begin(); d != devices.end(); d++) {
					std::stringstream moduleName;
					moduleName << prog.name << "_" << *d;
					report("Loading module (ptx) - " << moduleName.str());
	
					std::string name = moduleName.str();
					assert(_modules.count(name) == 0);
			
					ModuleMap::iterator module = _modules.insert(
						std::make_pair(name, ir::Module())).first;
				
					module->second.lazyLoad(temp, name);
			
					_registerModule(module, *d);
	
					assert(prog.ptxModule.count(*d) == 0);
					prog.ptxModule.insert(std::make_pair(*d, name));
		
					assert(prog.ptxCode.count(*d) == 0);
					prog.ptxCode.insert(std::make_pair(*d, temp));
				}
	
				assert(prog.ptxModule.size() == prog.ptxCode.size());
				prog.built = true;
			}
			catch(...) {
				throw CL_BUILD_PROGRAM_FAILURE;
			}
		}
								
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_BUILD_PROGRAM_FAILURE;
	}
	
	_unlock();
	return _setLastError(result);
}

cl_int opencl::OpenCLRuntime::clGetProgramInfo(cl_program program,
	cl_program_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {
	cl_int result = CL_SUCCESS;
	_lock();
	
	try {
		
		if(param_name < CL_PROGRAM_REFERENCE_COUNT || param_name > CL_PROGRAM_BINARIES)
			throw CL_INVALID_VALUE;
		
		HostThreadContext &thread = _getCurrentThread();
	
		if(thread.validPrograms.find(program) == thread.validPrograms.end())//Not found
			throw CL_INVALID_PROGRAM;

		Program &prog = *_programs[program];

		switch(param_name) {
			case CL_PROGRAM_BINARY_SIZES: {
				if(param_value_size < thread.validDevices.size() * sizeof(size_t))
					throw CL_INVALID_VALUE;

				if(param_value)	{
					IndexSet::iterator device;
					unsigned int i = 0;
					//get ptx code size for every valid device
					for(device = thread.validDevices.begin(); 
							device != thread.validDevices.end(); device++) {
						//if ptx code for a specific device does not exist, return 0
						std::map <int, std::string>::iterator ptx;
						if((ptx = prog.ptxCode.find(*device)) != prog.ptxCode.end())
							((size_t *)param_value)[i] = ptx->second.size();
						else
							((size_t *)param_value)[i] = 0;
						i++;
					}
				}

				if(param_value_size_ret)
					*param_value_size_ret = thread.validDevices.size() * sizeof(size_t);
	
				break;
			}
			case CL_PROGRAM_BINARIES: {
				if(param_value_size < thread.validDevices.size() * sizeof(char *))
					throw CL_INVALID_VALUE;

				if(param_value)	{
					IndexSet::iterator device;
					unsigned int i = 0;
					//get ptx code size for every valid device
					for(device = thread.validDevices.begin(); 
							device != thread.validDevices.end(); device++) {
							
						//if ptx code for a specific device does not exist, don't copy
						std::map <int, std::string>::iterator ptx;
						if((ptx = prog.ptxCode.find(*device)) != prog.ptxCode.end())
							std::memcpy(((char **)param_value)[i], ptx->second.data(), ptx->second.size());
						i++;
					}
				}

				if(param_value_size_ret)
					*param_value_size_ret = thread.validDevices.size() * sizeof(size_t);
	
				break;
			}
				
				break;
			default:
				assertM(false, "unsupported program info");
				throw CL_UNIMPLEMENTED;
				break;
		}
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();
	return _setLastError(result);
}

cl_kernel opencl::OpenCLRuntime::clCreateKernel(cl_program program,
	const char * kernel_name,
	cl_int * errcode_ret) {
	
	cl_kernel kernel = -1;
	cl_int err = CL_SUCCESS;	

	_lock();

	try{
		HostThreadContext & thread = _getCurrentThread();
		if(thread.validPrograms.find(program) == thread.validPrograms.end())
			throw CL_INVALID_PROGRAM;

		Program &prog = *_programs[program];
		if(!prog.built)
			throw CL_INVALID_PROGRAM_EXECUTABLE;

		if(!kernel_name)
			throw CL_INVALID_VALUE;

		std::map < int, std::string >::iterator module;
		std::string kernelName(kernel_name);
		
		for(module = prog.ptxModule.begin(); module != prog.ptxModule.end(); module++) {
			ModuleMap::iterator m = _modules.find(module->second);
			assert(m != _modules.end());
			if(m->second.getKernel(kernelName)==0) {//kernel not found
				throw CL_INVALID_KERNEL_NAME;
				break;
			}
	
		}

		report("Registered kernel - " << kernelName
			<< " in program '" << prog.name << "'");
		try {
			_kernels.push_back(new RegisteredKernel(kernelName, program, prog.context));
		}
		catch(...) {
			throw CL_OUT_OF_HOST_MEMORY;
		}
		kernel = _kernels.size() - 1;
		prog.kernels.insert(kernel);

	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}

	_setLastError(err);
	if(errcode_ret)
		*errcode_ret = err;
	_unlock();
	return kernel;
}

cl_mem opencl::OpenCLRuntime::clCreateBuffer(cl_context context,
	cl_mem_flags flags,
	size_t size,
	void * host_ptr,
	cl_int * errcode_ret) {

	cl_mem buffer = NULL;
	_lock();
	cl_int err = CL_SUCCESS;

	try {
		HostThreadContext & thread = _getCurrentThread();
		if(context != (void *)&thread)
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

		std::map< int, executive::Device::MemoryAllocation * > allocations;
		for(IndexSet::iterator it = thread.validDevices.begin();
			it != thread.validDevices.end(); it++) {
			executive::Device &device = *(_devices[*it]);
			device.select();
			try {
				executive::Device::MemoryAllocation * allocation =  device.allocate(size);
				if(allocation == NULL) throw;
				allocations.insert(std::make_pair(*it, allocation));
				report("clCreateBuffer() return address = " <<  allocation->pointer() << ", size = " << size);
			}
			catch(...) {
				device.unselect();
				throw CL_OUT_OF_RESOURCES;
			}

			device.unselect();
		}

		BufferObject * bf;
		try {
			bf = new BufferObject(allocations, context, flags, size);
			_memories.insert(bf);
		}
		catch(...) {
			throw CL_OUT_OF_HOST_MEMORY;
		}
		thread.validMemories.insert(bf);
		buffer = (void *)bf;

	}
	catch(cl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}

	_setLastError(err);
	if(errcode_ret)
		*errcode_ret = err;
	_unlock();
	return buffer;
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
		HostThreadContext & thread = _getCurrentThread();
		if(thread.validQueues.find(command_queue) == thread.validQueues.end())
			throw CL_INVALID_COMMAND_QUEUE;

		MemoryObject * bf = (MemoryObject *) buffer;
		if(_queues[command_queue]->context() != (void *)&thread || bf->context() != (void *)&thread)
			throw CL_INVALID_CONTEXT;

		if(thread.validMemories.find(bf) == thread.validMemories.end() || bf->type() != CL_MEM_OBJECT_BUFFER)
			throw CL_INVALID_MEM_OBJECT;

		if(offset >= bf->size() || cb + offset > bf->size())
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

		std::map<int, executive::Device::MemoryAllocation *> & allocations = bf->allocations;
		cl_device_id device = _queues[command_queue]->device();
		if(allocations.find(device) == allocations.end() || allocations.find(device)->second == NULL)
			throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

		executive::Device & d = *(_devices[device]);
		executive::Device::MemoryAllocation * allocation = allocations.find(device)->second;
		assert(d.checkMemoryAccess((char *)allocation->pointer() + offset, cb));
		allocation->copy(ptr, offset, cb);

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
	return _setLastError(result);
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
		HostThreadContext & thread = _getCurrentThread();
		if(thread.validQueues.find(command_queue) == thread.validQueues.end())
			throw CL_INVALID_COMMAND_QUEUE;

		MemoryObject * bf = (MemoryObject *)buffer;
		if(_queues[command_queue]->context() != (void *)&thread || bf->context() != (void *)&thread)
			throw CL_INVALID_CONTEXT;

		if(thread.validMemories.find(bf) == thread.validMemories.end() || bf->type() != CL_MEM_OBJECT_BUFFER)
			throw CL_INVALID_MEM_OBJECT;

		if(offset >= bf->size() || cb + offset > bf->size())
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

		std::map<int, executive::Device::MemoryAllocation *> & allocations = bf->allocations;
		cl_device_id device = _queues[command_queue]->device();
		if(allocations.find(device) == allocations.end() || allocations.find(device)->second == NULL)
			throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

		executive::Device & d = *(_devices[device]);
		executive::Device::MemoryAllocation * allocation = allocations.find(device)->second;
		assert(d.checkMemoryAccess((char *)allocation->pointer() + offset, cb));
		
		allocation->copy(offset, ptr, cb);

	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}
	_unlock();
	return _setLastError(result);
}

cl_int opencl::OpenCLRuntime::clSetKernelArg(cl_kernel kernel,
	cl_uint arg_index,
	size_t arg_size,
	const void * arg_value) {
	cl_int result = CL_SUCCESS;

	_lock();

	try {
		if(kernel < 0 || kernel >= (cl_kernel)_kernels.size())
			throw CL_INVALID_KERNEL;

		RegisteredKernel & k = *(_kernels[kernel]);
		HostThreadContext & thread = _getCurrentThread();
		if(k.context != (void *) &thread)
			throw CL_INVALID_KERNEL;

		k.parameterSizes[arg_index] = arg_size;
		char * paramVal = new char[arg_size];
		memcpy(paramVal, arg_value, arg_size);
		k.parameterPointers[arg_index] = paramVal;
		
		
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();
	return _setLastError(result);
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
		HostThreadContext &thread = _getCurrentThread();
		if(thread.validQueues.find(command_queue) == thread.validQueues.end())
			throw CL_INVALID_COMMAND_QUEUE;

		if(kernel < 0 || kernel >= (cl_kernel)_kernels.size())
			throw CL_INVALID_KERNEL;

		CommandQueue & q = *(_queues[command_queue]);
		RegisteredKernel & k = *(_kernels[kernel]);
		if(q.context() != k.context)
			throw CL_INVALID_CONTEXT;
		
		if(k.parameterSizes.size() == 0)
			throw CL_INVALID_KERNEL_ARGS;

		assert(k.parameterSizes.size() == k.parameterPointers.size());
		
		_mapKernelParameters(k, q.device());

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

		if((event_wait_list == NULL && num_events_in_wait_list > 0) || (event_wait_list && num_events_in_wait_list == 0))
			throw CL_INVALID_EVENT_WAIT_LIST;


		for(cl_uint dim = 0; dim < 3; dim++) {
			if(dim < work_dim) {
				k.globalWorkSize[dim] = global_work_size[dim];
				if(local_work_size)
					k.localWorkSize[dim] = local_work_size[dim];
				else
					k.localWorkSize[dim] = global_work_size[dim];
			}
			else {
				k.globalWorkSize[dim] = 1;
				k.localWorkSize[dim] = 1;
			}

			k.workGroupNum[dim] = k.globalWorkSize[dim] / k.localWorkSize[dim];
		}

		try {
			_launchKernel(k, q.device());
		}
		catch(...) {
			throw CL_OUT_OF_RESOURCES;
		}
	}
	catch(cl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();
	return _setLastError(result);
}
