/*! 
	\file PassThroughDevice.cpp
	\author Andrew Kerr
	\date 15 February 2011
	\brief Defines a wrapper for Ocelot executive::Devices enabling monitoring, serialization, and decoupling
*/

// Ocelot includes
#include <ocelot/cuda/interface/cuda_runtime.h>
#include <ocelot/executive/interface/PassThroughDevice.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////

// whether debugging messages are printed
#define REPORT_BASE 1

// if reporting is enabled, determines whether to print file name, line number, and function name
// for each device call
#define REPORT_DEVICE_CALLS 1

/////////////////////////////////////////////////////////////////////////////////////////////////

#if REPORT_DEVICE_CALLS
#define TRACE() report( __FILE__ << ":" << __LINE__ << " - " << __func__ << "() " )
#else
#define TRACE()
#endif

#define CHECK() assert(0 && "No device selected")

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::PassThroughDevice::PassThroughDevice(
	executive::Device *target, 
	unsigned int flags)
: _target(target) 
{
	TRACE();
}

executive::PassThroughDevice::~PassThroughDevice() {
	TRACE();
	CHECK();
	_target = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Check a memory access against all allocations */
bool executive::PassThroughDevice::checkMemoryAccess(const void* pointer, size_t size) const {
	TRACE();
	CHECK();
	return _target->checkMemoryAccess(pointer, size);
}

/*! \brief Get the allocation containing a pointer or 0 */
executive::Device::MemoryAllocation* executive::PassThroughDevice::getMemoryAllocation(
	const void* address, 
	AllocationType type) const {
	TRACE();
	CHECK();
	return _target->getMemoryAllocation(address, type);
}

/*! \brief Get the address of a global by name */
executive::Device::MemoryAllocation* executive::PassThroughDevice::getGlobalAllocation(
	const std::string& module, 
	const std::string& name) {
	TRACE();
	CHECK();
	return _target->getGlobalAllocation(module, name);
}

/*! \brief Allocate some new dynamic memory on this executive::Device */
executive::Device::MemoryAllocation* executive::PassThroughDevice::allocate(size_t size) {
	TRACE();
	CHECK();
	return _target->allocate(size);
}

/*! \brief Make this a host memory allocation */
executive::Device::MemoryAllocation* executive::PassThroughDevice::allocateHost(
	size_t size, 
	unsigned int flags) {
	TRACE();
	CHECK();
	return _target->allocateHost(size, flags);
}

/*! \brief Free an existing non-global allocation */
void executive::PassThroughDevice::free(void* pointer) {
	TRACE();
	CHECK();
	_target->free(pointer);
}

/*! \brief Get nearby allocations to a pointer */
executive::Device::MemoryAllocationVector executive::PassThroughDevice::getNearbyAllocations(
	void* pointer) const {
	TRACE();
	CHECK();
	return _target->getNearbyAllocations(pointer);
}

/*! \brief Get all allocations, host, global, and executive::Device */
executive::Device::MemoryAllocationVector executive::PassThroughDevice::getAllAllocations() const {
	TRACE();
	CHECK();
	return _target->getAllAllocations();
}

/*! \brief Get a string representation of nearby allocations */
std::string executive::PassThroughDevice::nearbyAllocationsToString(void* pointer) const {
	TRACE();
	CHECK();
	return _target->nearbyAllocationsToString(pointer);
}

/*! \brief Wipe all memory allocations, but keep modules */
void executive::PassThroughDevice::clearMemory() {
	TRACE();
	CHECK();
	_target->clearMemory();
}

/*! \brief Registers an opengl buffer with a resource */
void * executive::PassThroughDevice::glRegisterBuffer(
	unsigned int buffer, 
	unsigned int flags) {
	TRACE();
	CHECK();
	return _target->glRegisterBuffer(buffer, flags);
}

/*! \brief Registers an opengl image with a resource */
void * executive::PassThroughDevice::glRegisterImage(
	unsigned int image, 
	unsigned int target, 
	unsigned int flags) {
	TRACE();
	CHECK();
	return _target->glRegisterImage(image, target, flags);
}

/*! \brief Unregister a resource */
void executive::PassThroughDevice::unRegisterGraphicsResource(void* resource) {
	TRACE();
	CHECK();
	_target->unRegisterGraphicsResource(resource);
}

/*! \brief Map a graphics resource for use with this executive::Device */
void executive::PassThroughDevice::mapGraphicsResource(
	void** resource, 
	int count, 
	unsigned int stream) {
	TRACE();
	CHECK();
	_target->mapGraphicsResource(resource, count, stream);
}

/*! \brief Get a pointer to a mapped resource along with its size */
void * executive::PassThroughDevice::getPointerToMappedGraphicsResource(
	size_t & size, 
	void* resource) {
	TRACE();
	CHECK();
	return _target->getPointerToMappedGraphicsResource(size, resource);
}

/*! \brief Change the flags of a mapped resource */
void executive::PassThroughDevice::setGraphicsResourceFlags(
	void* resource, 
	unsigned int flags) {
	TRACE();
	CHECK();
	_target->setGraphicsResourceFlags(resource, flags);
}

/*! \brief Unmap a mapped resource */
void executive::PassThroughDevice::unmapGraphicsResource(
	void** resource, 
	int count,
	unsigned int stream) {
	TRACE();
	CHECK();
	_target->unmapGraphicsResource(resource, count, stream);
}

/*! \brief Load a module, must have a unique name */
void executive::PassThroughDevice::load(const ir::Module* module) {
	TRACE();
	CHECK();
	_target->load(module);
}

/*! \brief Unload a module by name */
void executive::PassThroughDevice::unload(const std::string& name) {
	TRACE();
	CHECK();
	_target->unload(name);
}

/*! \brief Get a translated kernel from the executive::Device */
executive::ExecutableKernel* executive::PassThroughDevice::getKernel(
	const std::string& module, 
	const std::string& kernel) {
	TRACE();
	CHECK();
	return _target->getKernel(module, kernel);
}

/*! \brief Create a new event */
unsigned int executive::PassThroughDevice::createEvent(int flags) {
	TRACE();
	CHECK();
	return _target->createEvent(flags);
}

/*! \brief Destroy an existing event */
void executive::PassThroughDevice::destroyEvent(unsigned int event) {
	TRACE();
	CHECK();
	_target->destroyEvent(event);
}

/*! \brief Query to see if an event has been recorded (yes/no) */
bool executive::PassThroughDevice::queryEvent(unsigned int event) {
	TRACE();
	CHECK();
	return _target->queryEvent(event);
}

/*! \brief Record something happening on an event */
void executive::PassThroughDevice::recordEvent(unsigned int event, unsigned int stream) {
	TRACE();
	CHECK();
	_target->recordEvent(event, stream);
}

/*! \brief Synchronize on an event */
void executive::PassThroughDevice::synchronizeEvent(unsigned int event) {
	TRACE();
	CHECK();
	_target->synchronizeEvent(event);
}

/*! \brief Get the elapsed time in ms between two recorded events */
float executive::PassThroughDevice::getEventTime(unsigned int start, unsigned int end) {
	TRACE();
	CHECK();
	return _target->getEventTime(start, end);
}

/*! \brief Create a new stream */
unsigned int executive::PassThroughDevice::createStream() {
	TRACE();
	CHECK();
	return _target->createStream();
}

/*! \brief Destroy an existing stream */
void executive::PassThroughDevice::destroyStream(unsigned int stream) {
	TRACE();
	CHECK();
	_target->destroyStream(stream);
}

/*! \brief Query the status of an existing stream (ready/not) */
bool executive::PassThroughDevice::queryStream(unsigned int stream) {
	TRACE();
	CHECK();
	return _target->queryStream(stream);
}

/*! \brief Synchronize a particular stream */
void executive::PassThroughDevice::synchronizeStream(unsigned int stream) {
	TRACE();
	CHECK();
	_target->synchronizeStream(stream);
}

/*! \brief Sets the current stream */
void executive::PassThroughDevice::setStream(unsigned int stream) {
	TRACE();
	CHECK();
	_target->setStream(stream);
}

/*! \brief Select this executive::Device as the current executive::Device. 
	Only one executive::Device is allowed to be selected at any time. */
void executive::PassThroughDevice::select() {
	TRACE();
	CHECK();
	_target->select();
}

/*! \brief is this executive::Device selected? */
bool executive::PassThroughDevice::selected() const {
	TRACE();
	CHECK();
	return _target->selected();
}

/*! \brief Deselect this executive::Device. */
void executive::PassThroughDevice::unselect() {
	TRACE();
	CHECK();
	_target->unselect();
}

/*! \brief Binds a texture to a memory allocation at a pointer */
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

/*! \brief unbinds anything bound to a particular texture */
void executive::PassThroughDevice::unbindTexture(
	const std::string& moduleName, 
	const std::string& textureName) {
	TRACE();
	CHECK();
	_target->unbindTexture(moduleName, textureName);
}

/*! \brief Get's a reference to an internal texture */
void * executive::PassThroughDevice::getTextureReference(
	const std::string& moduleName, 
	const std::string& textureName) {
	TRACE();
	CHECK();
	return _target->getTextureReference(moduleName, textureName);
}

/*! \brief helper function for launching a kernel
	\param module module name
	\param kernel kernel name
	\param grid grid dimensions
	\param block block dimensions
	\param sharedMemory shared memory size
	\param argumentBlock array of bytes for argument memory
	\param argumentBlockSize number of bytes in argument memory
	\param traceGenerators vector of trace generators to add 
		and remove from kernel
*/
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
	_target->launch(module, kernel, grid, block, sharedMemory, argumentBlock, argumentBlockSize, 
		traceGenerators);
}

/*! \brief Get the function attributes of a specific kernel */
cudaFuncAttributes executive::PassThroughDevice::getAttributes(const std::string& module, const std::string& kernel) {
	TRACE();
	CHECK();
	return _target->getAttributes(module, kernel);
}

/*! \brief Get the last error from this executive::Device */
unsigned int executive::PassThroughDevice::getLastError() {
	TRACE();
	CHECK();
	return _target->getLastError();
}

/*! \brief Wait until all asynchronous operations have completed */
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


