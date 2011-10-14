// C standard library includes
#include <assert.h>

// C++ standard library includes
#include <sstream>
#include <fstream>
#include <algorithm>

// Ocelot includes
#include <ocelot/opencl/interface/OpenCLRuntime.h>
//#include <ocelot/opencl/interface/OpenCLDriver.h>
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
	lastError(CL_SUCCESS), parameterBlock(0), parameterBlockSize(1<<13) {
	parameterBlock = (unsigned char *)malloc(parameterBlockSize);
}

opencl::HostThreadContext::~HostThreadContext() {
	::free(parameterBlock);
}

opencl::HostThreadContext::HostThreadContext(const HostThreadContext& c): 
	selectedDevice(c.selectedDevice),
	validDevices(c.validDevices),
	launchConfigurations(c.launchConfigurations),
	lastError(c.lastError),
	parameterBlock((unsigned char *)malloc(c.parameterBlockSize)),
	parameterBlockSize(c.parameterBlockSize),
	parameterIndices(c.parameterIndices),
	parameterSizes(c.parameterSizes),
	persistentTraceGenerators(c.persistentTraceGenerators),
	nextTraceGenerators(c.nextTraceGenerators) {
	memcpy(parameterBlock, c.parameterBlock, parameterBlockSize);
}

opencl::HostThreadContext& opencl::HostThreadContext::operator=(
	const HostThreadContext& c) {
	if(&c == this) return *this;
	selectedDevice = c.selectedDevice;
	validDevices = c.validDevices;
	lastError = c.lastError;
	launchConfigurations = c.launchConfigurations;
	parameterIndices = c.parameterIndices;
	parameterSizes = c.parameterSizes;
	persistentTraceGenerators = c.persistentTraceGenerators;
	nextTraceGenerators = c.nextTraceGenerators;
	memcpy(parameterBlock, c.parameterBlock, parameterBlockSize);
	return *this;
}

opencl::HostThreadContext::HostThreadContext(HostThreadContext&& c): 
	selectedDevice(0), parameterBlock(0), parameterBlockSize(1<<13) {
	*this = std::move(c);
}

opencl::HostThreadContext& opencl::HostThreadContext::operator=(
	HostThreadContext&& c) {
	if (this == &c) return *this;
	std::swap(selectedDevice, c.selectedDevice);
	std::swap(validDevices, c.validDevices);
	std::swap(lastError, c.lastError);
	std::swap(parameterBlock, c.parameterBlock);
	std::swap(launchConfigurations, c.launchConfigurations);
	std::swap(parameterIndices, c.parameterIndices);
	std::swap(parameterSizes, c.parameterSizes);
	std::swap(persistentTraceGenerators, c.persistentTraceGenerators);
	std::swap(nextTraceGenerators, c.nextTraceGenerators);
	return *this;
}

void opencl::HostThreadContext::clearParameters() {
	parameterIndices.clear();
	parameterSizes.clear();
}

void opencl::HostThreadContext::clear() {
	validDevices.clear();
	launchConfigurations.clear();
	clearParameters();
	persistentTraceGenerators.clear();
	nextTraceGenerators.clear();
}

unsigned int opencl::HostThreadContext::mapParameters(const ir::Kernel* kernel) {
	unsigned int dst = 0;

	if (kernel->arguments.size() == parameterIndices.size()) {
		IndexVector::iterator offset = parameterIndices.begin();
		SizeVector::iterator size = parameterSizes.begin();
		unsigned char* temp = (unsigned char*)malloc(parameterBlockSize);
		for (ir::Kernel::ParameterVector::const_iterator 
			parameter = kernel->arguments.begin(); 
			parameter != kernel->arguments.end();
			++parameter, ++offset, ++size) {
			unsigned int misalignment = dst % parameter->getAlignment();
			unsigned int alignmentOffset = misalignment == 0 
				? 0 : parameter->getAlignment() - misalignment;
			dst += alignmentOffset;
		
			memset(temp + dst, 0, parameter->getSize());
			memcpy(temp + dst, parameterBlock + *offset, *size);
			report( "Mapping parameter at offset " << *offset << " of size " 
				<< *size << " to offset " << dst << " of size " 
				<< parameter->getSize() << "\n   data = " 
				<< hydrazine::dataToString(temp + dst, parameter->getSize()));
			dst += parameter->getSize();
		}
		free(parameterBlock);
		parameterBlock = temp;
		clearParameters();
	}
	else if (parameterIndices.size() == 1
		&& parameterIndices[0] == 0 && parameterSizes[0]) {
		
		parameterBlockSize = parameterSizes[0];
		
		unsigned char *temp = (unsigned char *)malloc(parameterBlockSize);
		memcpy(temp, parameterBlock, parameterBlockSize);
		free(parameterBlock);
		parameterBlock = temp;
		
		report("parameter block formatted by client: offset "
			<< parameterIndices[0] << ", " 
			<< parameterSizes[0] << " bytes");
		clearParameters();

		dst = parameterBlockSize;
	}
	else {
		report("Parameter ERROR: offset " << parameterIndices[0] << ", "
			<< parameterSizes[0] << " bytes. Expected parameter sizes of "
			<< parameterBlockSize);
		assert((kernel->arguments.size() == parameterIndices.size()) && 
			"unaccepted argument formatting");
	}

	return dst;
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
/*
void opencl::OpenCLRuntime::_memcpy(void* dst, const void* src, size_t count, 
	enum openclMemcpyKind kind) {
	
	switch(kind) {
		case openclMemcpyHostToHost: {
			report("  _memcpy(" << (void *)dst << ", " << src
				<< ", " << count << " bytes) h-to-h");
			memcpy(dst, src, count);
		}
		break;
		case openclMemcpyDeviceToHost: {
			report("  _memcpy(" << (void *)dst << ", " << src
				<< ", " << count << " bytes) d-to-h");
			if (!_getDevice().checkMemoryAccess(src, count)) {
				_release();
				_memoryError(src, count, "openclMemcpy");
			}
			
			executive::Device::MemoryAllocation* allocation = 
				_getDevice().getMemoryAllocation(src);
			size_t offset = (char*)src - (char*)allocation->pointer();
			allocation->copy(dst, offset, count);
		}
		break;
		case openclMemcpyDeviceToDevice: {
			report("  _memcpy(" << (void *)dst << ", "
				<< src << ", " << count << " bytes) d-to-d");
			if (!_getDevice().checkMemoryAccess(src, count)) {
				_release();
				_memoryError(src, count, "openclMemcpy");
			}
			if (!_getDevice().checkMemoryAccess(dst, count)) {
				_release();
				_memoryError(dst, count, "openclMemcpy");
			}
				
			executive::Device::MemoryAllocation* fromAllocation = 
				_getDevice().getMemoryAllocation(src);
			executive::Device::MemoryAllocation* toAllocation =
				_getDevice().getMemoryAllocation(dst);
			size_t fromOffset = (char*)src 
				- (char*)fromAllocation->pointer();
			size_t toOffset = (char*)dst - (char*)toAllocation->pointer();
			fromAllocation->copy(toAllocation, toOffset, fromOffset, count);
		}
		break;
		case openclMemcpyHostToDevice: {
			report("  _memcpy(" << (void *)dst << ", "
				<< src << ", " << count << " bytes) h-to-d");
			if (!_getDevice().checkMemoryAccess(dst, count)) {
				_release();
				_memoryError(dst, count, "openclMemcpy");
			}
			
			executive::Device::MemoryAllocation* allocation = 
				_getDevice().getMemoryAllocation(dst);
			size_t offset = (char*)dst - (char*)allocation->pointer();
			allocation->copy(offset, src, count);
		}
		break;
	}
}
*/
void opencl::OpenCLRuntime::_memoryError(const void* address, size_t count, 
	const std::string& function) {
	std::stringstream stream;
	stream << "In function - " << function << " - invalid memory access at " 
		<< address << "(" << count << " bytes)"; 
	throw hydrazine::Exception(stream.str());
}

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
	
	// textures
	
	// kernels
	
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

static ir::Dim3 convert(const cl_uint dim, const size_t * d) {
	assertM(dim <= 3, "dim > 3");
	return std::move(ir::Dim3((dim >= 1 ? d[0] : 1), (dim >= 2 ? d[1] : 1), (dim >= 3 ? d[2] : 1)));
}

cl_int opencl::OpenCLRuntime::_launchKernel(const std::string& moduleName, 
	const std::string& kernelName )
{
	_lock();

	_enumerateDevices();
	if (_devices.empty()) {
		_unlock();
		return _setLastError(CL_INVALID_CONTEXT);
	}
	
	ModuleMap::iterator module = _modules.find(moduleName);
	assert(module != _modules.end());

//	try {
//		_registerModule(module, _devices);
//	}
//	catch(...) {
//		_unlock();
//		throw;
//	}

	ir::Kernel* k = module->second.getKernel(kernelName);
	assert(k != 0);

	_bind();

	HostThreadContext& thread = _getCurrentThread();
	cl_int result = CL_SUCCESS;
	
	assert(thread.launchConfigurations.size());
	
	KernelLaunchConfiguration launch(thread.launchConfigurations.back());
	thread.launchConfigurations.pop_back();
	
	unsigned int paramSize = thread.mapParameters(k);
	
	report("kernel launch (" << kernelName 
		<< ") on thread " << boost::this_thread::get_id());
	
	try {
		trace::TraceGeneratorVector traceGens;

		traceGens = thread.persistentTraceGenerators;
		traceGens.insert(traceGens.end(),
			thread.nextTraceGenerators.begin(), 
			thread.nextTraceGenerators.end());

		_inExecute = true;
		_getDevice().launch(moduleName, kernelName, convert(launch.workDim, launch.globalWorkSize), 
			convert(launch.workDim, launch.localWorkSize), /*launch.sharedMemory*/0, 
			thread.parameterBlock, paramSize, traceGens, NULL/*&_externals*/);
		_inExecute = false;
		report(" launch completed successfully");	
	}
	catch( const executive::RuntimeException& e ) {
		std::cerr << "==Ocelot== PTX Emulator failed to run kernel \"" 
			<< kernelName 
			<< "\" with exception: \n";
		std::cerr << _formatError( e.toString() ) 
			<< "\n" << std::flush;
		thread.lastError = CL_INVALID_KERNEL;
		_inExecute = false;
		_release();
		throw;
	}
	catch( const std::exception& e ) {
		std::cerr << "==Ocelot== " << _getDevice().properties().name
			<< " failed to run kernel \""
			<< kernelName
			<< "\" with exception: \n";
		std::cerr << _formatError( e.what() )
			<< "\n" << std::flush;
		thread.lastError = CL_INVALID_KERNEL;
		_inExecute = false;
		_release();
		throw;
	}
	catch(...) {
		thread.lastError = CL_INVALID_KERNEL;
		_inExecute = false;
		_release();
		throw;
	}
	_release();
	
	return result;
}

void opencl::OpenCLRuntime::launch(const std::string& moduleName,
	const std::string& kernelName) {
	_launchKernel(moduleName, kernelName);
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
	if((num_entries == 0 && platforms != NULL) || (num_platforms == NULL && platforms == NULL))
		result = CL_INVALID_VALUE;
	else {
		//Assume only 1 platform, platform_id = 0
		if(platforms)
			*platforms = 0;
		if(num_platforms)
			*num_platforms = 1;
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
	if(platform) //Temorarily assume platform=0
		result = CL_INVALID_PLATFORM;
	else if(device_type < CL_DEVICE_TYPE_CPU || device_type > CL_DEVICE_TYPE_ALL)
		result = CL_INVALID_DEVICE_TYPE;
	else if((num_entries == 0 && devices != NULL) || (num_devices == NULL && devices == NULL))
		result = CL_INVALID_VALUE;
	else { 
		_enumerateDevices();
		if(num_devices != 0)
			*num_devices = _devices.size();
		if(devices != 0) {
			for(cl_uint i = 0; i < std::min(_devices.size(), (size_t)num_entries); i++)
				devices[i] = i;
		}
		if (_devices.empty()) {
			result = CL_DEVICE_NOT_FOUND;
		}
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
	_lock();
	*errcode_ret = CL_SUCCESS;
	cl_context context = NULL;

	//Assume ocelot platform is always availbe, but platform_id in properties should be zero
	if(properties && properties[0] && (properties[0] != CL_CONTEXT_PLATFORM 
		|| properties[2] != 0 /*properties terminates with 0*/ ))
		*errcode_ret = CL_INVALID_PROPERTY;
	else if(properties[1] != 0 /*platform_id should be zero*/)
		*errcode_ret = CL_INVALID_PLATFORM;
	else if(devices == 0 || num_devices == 0
		|| (pfn_notify == 0 && user_data != 0))
		*errcode_ret = CL_INVALID_VALUE;
	else if(pfn_notify) {
		assertM(false, "call_back function unsupported\n");
		*errcode_ret = CL_UNIMPLEMENTED;
	}
	else {
		HostThreadContext &thread = _getCurrentThread();
		for (cl_uint i = 0; i < num_devices; i++) {
			if(devices[i] == -1 || devices[i] >= (int)_devices.size()) {
				*errcode_ret = CL_INVALID_DEVICE;
				break;
			}
			thread.validDevices.insert(devices[i]);
		}
		if(*errcode_ret == CL_SUCCESS)
			context = (cl_context) &thread;
	}
	_setLastError(*errcode_ret);
	_unlock();
	return context;
}

cl_command_queue opencl::OpenCLRuntime::clCreateCommandQueue(cl_context context, 
	cl_device_id device, 
	cl_command_queue_properties properties,
	cl_int * errcode_ret) {
	
	cl_command_queue queue = -1;
	
	_lock();
	*errcode_ret = CL_SUCCESS;

	HostThreadContext &thread = _getCurrentThread();
	if(context != (void *)&thread)
		*errcode_ret = CL_INVALID_CONTEXT;
	else if(thread.validDevices.find(device) == thread.validDevices.end())//Not found
		*errcode_ret = CL_INVALID_DEVICE;
	else if(properties > (CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE |
					CL_QUEUE_PROFILING_ENABLE))
		*errcode_ret = CL_INVALID_VALUE;
	else if((properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE) 
		||(properties & CL_QUEUE_PROFILING_ENABLE)) {
		assertM(false, "unimplemented queue properties");
		*errcode_ret = CL_INVALID_QUEUE_PROPERTIES;
	}
	else {
		executive::Device &d = *(_devices[device]);
		d.select();
		try {
			queue = d.createStream();
		}
		catch (...) {
			*errcode_ret = CL_OUT_OF_RESOURCES;
		}
		d.unselect();
	}
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
	*errcode_ret = CL_SUCCESS;
	HostThreadContext &thread = _getCurrentThread();
	if(context != (void *)&thread)
		*errcode_ret = CL_INVALID_CONTEXT;
	else if(count == 0 || strings == 0)
		*errcode_ret = CL_INVALID_VALUE;
	else {
		cl_uint i;
		for(i = 0; i < count; i++) {
			if(strings[i] == 0) {
				*errcode_ret = CL_INVALID_VALUE;
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
	return result;
}

cl_kernel opencl::OpenCLRuntime::clCreateKernel(cl_program program,
	const char * kernel_name,
	cl_int * errcode_ret) {
	
	cl_kernel kernel = -1;
	_lock();
	*errcode_ret = CL_SUCCESS;

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

	}
	catch(cl_int exception) {
		*errcode_ret = exception;
	}
	catch(...) {
		*errcode_ret = CL_OUT_OF_HOST_MEMORY;
	}

	_unlock();
	return kernel;
}

cl_mem opencl::OpenCLRuntime::clCreateBuffer(cl_context context,
	cl_mem_flags flags,
	size_t size,
	void * host_ptr,
	cl_int * errcode_ret) {

	_lock();
	*errcode_ret = CL_SUCCESS;
	cl_mem buffer = -1;

	_unlock();
	return buffer;
}
