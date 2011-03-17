/*! 
	\file PassThroughDevice.cpp
	\author Andrew Kerr
	\date 15 February 2011
	\brief Defines a wrapper for Ocelot executive::Devices enabling monitoring,
		serialization, and decoupling
*/

// Ocelot includes
#include <ocelot/executive/interface/PassThroughDevice.h>
#include <ocelot/cuda/interface/cuda_runtime.h>
#include <ocelot/api/interface/OcelotConfiguration.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

////////////////////////////////////////////////////////////////////////////////

// whether debugging messages are printed
#define REPORT_BASE 0

// if reporting is enabled, determines whether to print file name, line number, 
// and function name for each device call
#define REPORT_DEVICE_CALLS 0

////////////////////////////////////////////////////////////////////////////////

#if REPORT_DEVICE_CALLS
#define TRACE() report( " - " << __func__ << "() " )
#else
#define TRACE()
#endif

#define CHECK() assertM(_target, "Target not set.")

////////////////////////////////////////////////////////////////////////////////

typedef api::OcelotConfiguration config;

executive::PassThroughDevice::PassThroughDevice(
	executive::Device *target, 
	unsigned int flags)
: _kernelCount(0), _target(target) 
{
	TRACE();
	_properties = _target->properties();

	report("Bound to device '" << properties().name << "'");
}

executive::PassThroughDevice::~PassThroughDevice() {
	TRACE();
	CHECK();
	delete _target;
}

////////////////////////////////////////////////////////////////////////////////

bool executive::PassThroughDevice::checkMemoryAccess(const void* pointer,
	size_t size) const {
	TRACE();
	CHECK();
	return _target->checkMemoryAccess(pointer, size);
}

executive::Device::MemoryAllocation*
	executive::PassThroughDevice::getMemoryAllocation(const void* address, 
	AllocationType type) const {
	TRACE();
	CHECK();
	return _target->getMemoryAllocation(address, type);
}

executive::Device::MemoryAllocation*
	executive::PassThroughDevice::getGlobalAllocation(const std::string& module, 
	const std::string& name) {
	TRACE();
	CHECK();
	return _target->getGlobalAllocation(module, name);
}

executive::Device::MemoryAllocation* executive::PassThroughDevice::allocate(
	size_t size) {
	TRACE();
	CHECK();
	return _target->allocate(size);
}

executive::Device::MemoryAllocation* executive::PassThroughDevice::allocateHost(
	size_t size, 
	unsigned int flags) {
	TRACE();
	CHECK();
	return _target->allocateHost(size, flags);
}

void executive::PassThroughDevice::free(void* pointer) {
	TRACE();
	CHECK();
	_target->free(pointer);
}

executive::Device::MemoryAllocationVector
	executive::PassThroughDevice::getNearbyAllocations(void* pointer) const {
	TRACE();
	CHECK();
	return _target->getNearbyAllocations(pointer);
}

executive::Device::MemoryAllocationVector
	executive::PassThroughDevice::getAllAllocations() const {
	TRACE();
	CHECK();
	return _target->getAllAllocations();
}

std::string executive::PassThroughDevice::nearbyAllocationsToString(
	void* pointer) const {
	TRACE();
	CHECK();
	return _target->nearbyAllocationsToString(pointer);
}

void executive::PassThroughDevice::clearMemory() {
	TRACE();
	CHECK();
	_target->clearMemory();
}

void * executive::PassThroughDevice::glRegisterBuffer(
	unsigned int buffer, 
	unsigned int flags) {
	TRACE();
	CHECK();
	return _target->glRegisterBuffer(buffer, flags);
}

void * executive::PassThroughDevice::glRegisterImage(
	unsigned int image, 
	unsigned int target, 
	unsigned int flags) {
	TRACE();
	CHECK();
	return _target->glRegisterImage(image, target, flags);
}

void executive::PassThroughDevice::unRegisterGraphicsResource(void* resource) {
	TRACE();
	CHECK();
	_target->unRegisterGraphicsResource(resource);
}

void executive::PassThroughDevice::mapGraphicsResource(
	void** resource, 
	int count, 
	unsigned int stream) {
	TRACE();
	CHECK();
	_target->mapGraphicsResource(resource, count, stream);
}

void * executive::PassThroughDevice::getPointerToMappedGraphicsResource(
	size_t & size, 
	void* resource) {
	TRACE();
	CHECK();
	return _target->getPointerToMappedGraphicsResource(size, resource);
}

void executive::PassThroughDevice::setGraphicsResourceFlags(
	void* resource, 
	unsigned int flags) {
	TRACE();
	CHECK();
	_target->setGraphicsResourceFlags(resource, flags);
}

void executive::PassThroughDevice::unmapGraphicsResource(
	void** resource, 
	int count,
	unsigned int stream) {
	TRACE();
	CHECK();
	_target->unmapGraphicsResource(resource, count, stream);
}

void executive::PassThroughDevice::load(const ir::Module* module) {
	TRACE();
	CHECK();
	
	util::ExtractedDeviceState::ModuleMap::iterator eModule =
		_state.modules.insert(std::make_pair(module->path(),
		util::ExtractedDeviceState::Module())).first;
	
	eModule->second.name = module->path();
	std::stringstream stream;
	module->writeIR(stream);
	eModule->second.ptx = stream.str();

	for (ir::Module::TextureMap::const_iterator
		texture = module->textures().begin();
		texture != module->textures().end(); ++texture) {
		eModule->second.textures.insert(
			std::make_pair(texture->first, &texture->second));
	}
	
	// TODO add global allocations
	
	_target->load(module);
}

void executive::PassThroughDevice::unload(const std::string& name) {
	TRACE();
	CHECK();
	
	util::ExtractedDeviceState::ModuleMap::iterator eModule =
		_state.modules.find(name);
	if (eModule != _state.modules.end()) {
		_state.modules.erase(eModule);
	}
	
	_target->unload(name);
}

executive::ExecutableKernel* executive::PassThroughDevice::getKernel(
	const std::string& module, 
	const std::string& kernel) {
	TRACE();
	CHECK();
	return _target->getKernel(module, kernel);
}

unsigned int executive::PassThroughDevice::createEvent(int flags) {
	TRACE();
	CHECK();
	return _target->createEvent(flags);
}

void executive::PassThroughDevice::destroyEvent(unsigned int event) {
	TRACE();
	CHECK();
	_target->destroyEvent(event);
}

bool executive::PassThroughDevice::queryEvent(unsigned int event) {
	TRACE();
	CHECK();
	return _target->queryEvent(event);
}

void executive::PassThroughDevice::recordEvent(unsigned int event,
	unsigned int stream) {
	TRACE();
	CHECK();
	_target->recordEvent(event, stream);
}

void executive::PassThroughDevice::synchronizeEvent(unsigned int event) {
	TRACE();
	CHECK();
	_target->synchronizeEvent(event);
}

float executive::PassThroughDevice::getEventTime(
	unsigned int start, unsigned int end) {
	TRACE();
	CHECK();
	return _target->getEventTime(start, end);
}

unsigned int executive::PassThroughDevice::createStream() {
	TRACE();
	CHECK();
	return _target->createStream();
}

void executive::PassThroughDevice::destroyStream(unsigned int stream) {
	TRACE();
	CHECK();
	_target->destroyStream(stream);
}

bool executive::PassThroughDevice::queryStream(unsigned int stream) {
	TRACE();
	CHECK();
	return _target->queryStream(stream);
}

void executive::PassThroughDevice::synchronizeStream(unsigned int stream) {
	TRACE();
	CHECK();
	_target->synchronizeStream(stream);
}

void executive::PassThroughDevice::setStream(unsigned int stream) {
	TRACE();
	CHECK();
	_target->setStream(stream);
}

void executive::PassThroughDevice::select() {
	TRACE();
	CHECK();
	_target->select();
}

bool executive::PassThroughDevice::selected() const {
	TRACE();
	CHECK();
	return _target->selected();
}

void executive::PassThroughDevice::unselect() {
	TRACE();
	CHECK();
	_target->unselect();
}

void executive::PassThroughDevice::bindTexture(
	void* pointer, 
	const std::string& moduleName, 
	const std::string& textureName,
	const textureReference& ref, 
	const cudaChannelFormatDesc& desc, 
	const ir::Dim3& size) {
	TRACE();
	CHECK();
	_target->bindTexture(pointer, moduleName, textureName, ref, desc, size);
}

void executive::PassThroughDevice::unbindTexture(
	const std::string& moduleName, 
	const std::string& textureName) {
	TRACE();
	CHECK();
	_target->unbindTexture(moduleName, textureName);
}

void * executive::PassThroughDevice::getTextureReference(
	const std::string& moduleName, 
	const std::string& textureName) {
	TRACE();
	CHECK();
	return _target->getTextureReference(moduleName, textureName);
}

void executive::PassThroughDevice::launch(
	const std::string& module, 
	const std::string& kernel, 
	const ir::Dim3& grid, 
	const ir::Dim3& block, 
	size_t sharedMemory, 
	const void* argumentBlock, 
	size_t argumentBlockSize, 
	const trace::TraceGeneratorVector & traceGenerators) {
	TRACE();
	CHECK();
	
	_recordStatePreExecution();
	_recordKernelLaunch(module, kernel, grid, block, sharedMemory,
		argumentBlock, argumentBlockSize);
	_target->launch(module, kernel, grid, block, sharedMemory, argumentBlock,
		argumentBlockSize, traceGenerators);
	_recordStatePostExecution();
	
}

cudaFuncAttributes executive::PassThroughDevice::getAttributes(
	const std::string& module, const std::string& kernel) {
	TRACE();
	CHECK();
	return _target->getAttributes(module, kernel);
}

unsigned int executive::PassThroughDevice::getLastError() {
	TRACE();
	CHECK();
	return _target->getLastError();
}

void executive::PassThroughDevice::synchronize() {
	TRACE();
	CHECK();
	_target->synchronize();
}

void executive::PassThroughDevice::limitWorkerThreads(unsigned int threads) {
	TRACE();
	CHECK();
	_target->limitWorkerThreads(threads);
}

void executive::PassThroughDevice::setOptimizationLevel(
	translator::Translator::OptimizationLevel level) {
	TRACE();
	CHECK();
	_target->setOptimizationLevel(level);
}

void  executive::PassThroughDevice::_recordStatePreExecution() {

	// clear previous
	_state.globalAllocations.clear();
	_state.postLaunchGlobalAllocations.clear();

	// save allocations
	Device::MemoryAllocationVector allocations = getAllAllocations();

	for (Device::MemoryAllocationVector::const_iterator
		allocation = allocations.begin();
		allocation != allocations.end(); ++allocation) {
		if (!(*allocation)->global()) {
			util::ExtractedDeviceState::GlobalAllocationMap::iterator memory
				= _state.globalAllocations.insert(std::make_pair(
				(*allocation)->pointer(),
				new util::ExtractedDeviceState::MemoryAllocation(
					(*allocation)->pointer(), (*allocation)->size()))).first;
			
			(*allocation)->copy(memory->second->data.data(),
				0, (*allocation)->size());
		}
	}
}

void  executive::PassThroughDevice::_recordKernelLaunch(
	const std::string& module, 
	const std::string& kernel, 
	const ir::Dim3& grid, 
	const ir::Dim3& block, 
	size_t sharedMemory, 
	const void* argumentBlock, 
	size_t argumentBlockSize) {
	
	_state.launch.moduleName = module;
	_state.launch.kernelName = kernel;
	_state.launch.blockDim = block;
	_state.launch.gridDim = grid;
	_state.launch.sharedMemorySize = sharedMemory;;
	_state.launch.parameterMemory.assign((const char*)argumentBlock,
		(const char*)argumentBlock + argumentBlockSize);
}

void  executive::PassThroughDevice::_recordStatePostExecution() {
	// save allocations
	Device::MemoryAllocationVector allocations = getAllAllocations();

	for (Device::MemoryAllocationVector::const_iterator
		allocation = allocations.begin();
		allocation != allocations.end(); ++allocation) {
		if (!(*allocation)->global()) {
			util::ExtractedDeviceState::GlobalAllocationMap::iterator memory
				= _state.postLaunchGlobalAllocations.insert(std::make_pair(
				(*allocation)->pointer(),
				new util::ExtractedDeviceState::MemoryAllocation(
					(*allocation)->pointer(), (*allocation)->size()))).first;
			
			(*allocation)->copy(memory->second->data.data(),
				0, (*allocation)->size());
		}
	}
	
	std::stringstream stream;
	stream << config::get().checkpoint.path
		<< config::get().checkpoint.prefix << _kernelCount++
		<< config::get().checkpoint.suffix;
	std::ofstream file(stream.str());
	if(!file.is_open())
	{
		throw hydrazine::Exception("Failed to open checkpoint file '"
			+ stream.str() + "' for writing.");
	}
	
	_state.serialize(file);
}

