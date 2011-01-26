/*! \file RemoteDevice.h
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\date 26 Jan 2011
	\brief class defining a remote Ocelot device 
*/

// OpenGL includes
#include <GL/glew.h>

// Linux includes
#include <sys/sysinfo.h>

// Standard library includes
#include <cstring>

// ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/executive/interface/RemoteDevice.h>
#include <ocelot/cuda/interface/cuda_runtime.h>

// hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/interface/Casts.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

// Macros
#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str());}
	
/////////////////////////////////////////////////////////////////////////////////////////////////

// Turn on report messages
#define REPORT_BASE 0

// Memory Alignment (must be a power of 2) 
// (cuda currently requires 256-byte alignment)
#define ALIGNMENT 256

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Sets the device properties, bind this to the cuda id */
executive::RemoteDevice::RemoteDevice(std::string host, int port, unsigned int flags): _socket(_io_service) {

}

/*! \brief Clears all state */
executive::RemoteDevice::~RemoteDevice() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::Device::MemoryAllocation* executive::RemoteDevice::getMemoryAllocation(const void* address, 
	AllocationType type) const {

	assert(0 && "unimplemented");
	return 0;
}

/*! \brief Get the address of a global by stream */
executive::Device::MemoryAllocation* executive::RemoteDevice::getGlobalAllocation(
	const std::string& module, const std::string& name) {

	assert(0 && "unimplemented");
	return 0;
}

/*! \brief Allocate some new dynamic memory on this device */
executive::Device::MemoryAllocation* executive::RemoteDevice::allocate(size_t size) {

	assert(0 && "unimplemented");
	return 0;
}

/*! \brief Make this a host memory allocation */
executive::Device::MemoryAllocation* executive::RemoteDevice::allocateHost(size_t size, 
	unsigned int flags) {

	assert(0 && "unimplemented");
	return 0;
}

/*! \brief Free an existing non-global allocation */
void executive::RemoteDevice::free(void* pointer) {

	assert(0 && "unimplemented");
}

/*! \brief Get nearby allocations to a pointer */
executive::Device::MemoryAllocationVector executive::RemoteDevice::getNearbyAllocations(void* pointer) const {
	executive::Device::MemoryAllocationVector allocations;
	
	assert(0 && "unimplemented");
	return allocations;
}

/*! \brief Get all allocations, host, global, and device */
executive::Device::MemoryAllocationVector executive::RemoteDevice::getAllAllocations() const {
	executive::Device::MemoryAllocationVector allocations;
	
	assert(0 && "unimplemented");
	return allocations;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Wipe all memory allocations, but keep modules */
void executive::RemoteDevice::clearMemory() {

	assert(0 && "unimplemented");
}

/*! \brief Load a module, must have a unique name */
void executive::RemoteDevice::load(const ir::Module* module) {

	assert(0 && "unimplemented");
}

/*! \brief Unload a module by name */
void executive::RemoteDevice::unload(const std::string& name) {

	assert(0 && "unimplemented");
}

/*! \brief Get a translated kernel from the device */
executive::ExecutableKernel* executive::RemoteDevice::getKernel(const std::string& module, 
	const std::string& kernel) {

	assert(0 && "unimplemented");
	return 0;
}


/*! \brief Create a new event */
unsigned int executive::RemoteDevice::createEvent(int flags) {

	assert(0 && "unimplemented");
	return 0;
}

/*! \brief Destroy an existing event */
void executive::RemoteDevice::destroyEvent(unsigned int event) {

	assert(0 && "unimplemented");
}

/*! \brief Query to see if an event has been recorded (yes/no) */
bool executive::RemoteDevice::queryEvent(unsigned int event) const {

	assert(0 && "unimplemented");
	return false;
}

/*! \brief Record something happening on an event */
void executive::RemoteDevice::recordEvent(unsigned int event, unsigned int stream) {

	assert(0 && "unimplemented");
}

/*! \brief Synchronize on an event */
void executive::RemoteDevice::synchronizeEvent(unsigned int event) {

	assert(0 && "unimplemented");
}

/*! \brief Get the elapsed time in ms between two recorded events */
float executive::RemoteDevice::getEventTime(unsigned int start, unsigned int end) const {

	assert(0 && "unimplemented");
	return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Create a new stream */
unsigned int executive::RemoteDevice::createStream() {

	assert(0 && "unimplemented");
	return false;
}

/*! \brief Destroy an existing stream */
void executive::RemoteDevice::destroyStream(unsigned int stream) {

	assert(0 && "unimplemented");
}

/*! \brief Query the status of an existing stream (ready/not) */
bool executive::RemoteDevice::queryStream(unsigned int stream) const {

	assert(0 && "unimplemented");
	return false;
}

/*! \brief Synchronize a particular stream */
void executive::RemoteDevice::synchronizeStream(unsigned int stream) {

	assert(0 && "unimplemented");
}

/*! \brief Sets the current stream */
void executive::RemoteDevice::setStream(unsigned int stream) {

	assert(0 && "unimplemented");
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Select this device as the current device. 
	Only one device is allowed to be selected at any time. */
void executive::RemoteDevice::select() {

	assert(0 && "unimplemented");
}

/*! \brief is this device selected? */
bool executive::RemoteDevice::selected() const {

	assert(0 && "unimplemented");
	return false;
}

/*! \brief Deselect this device. */
void executive::RemoteDevice::unselect() {

	assert(0 && "unimplemented");
}


/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Binds a texture to a memory allocation at a pointer */
void executive::RemoteDevice::bindTexture(void* pointer,
	const std::string& moduleName, const std::string& textureName, 
	const textureReference& ref, const cudaChannelFormatDesc& desc, 
	const ir::Dim3& size) {

	assert(0 && "unimplemented");
}

/*! \brief unbinds anything bound to a particular texture */
void executive::RemoteDevice::unbindTexture(const std::string& moduleName, 
	const std::string& textureName) {

	assert(0 && "unimplemented");
}

/*! \brief Get's a reference to an internal texture */
void* executive::RemoteDevice::getTextureReference(const std::string& moduleName, 
	const std::string& textureName) {

	assert(0 && "unimplemented");
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief helper function for launching a kernel
	\param module module name
	\param kernel kernel name
	\param grid grid dimensions
	\param block block dimensions
	\param sharedMemory shared memory size
	\param argumentBlock array of bytes for parameter memory
	\param argumentBlockSize number of bytes in parameter memory
	\param traceGenerators vector of trace generators to add 
		and remove from kernel
*/
void executive::RemoteDevice::launch(const std::string& module, 
	const std::string& kernel, const ir::Dim3& grid, 
	const ir::Dim3& block, size_t sharedMemory, 
	const void* argumentBlock, size_t argumentBlockSize, 
	const trace::TraceGeneratorVector & traceGenerators) {

	assert(0 && "unimplemented");
}


/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Get the function attributes of a specific kernel */
cudaFuncAttributes executive::RemoteDevice::getAttributes(const std::string& module, 
	const std::string& kernel) {
	
	cudaFuncAttributes attr;
	assert(0 && "unimplemented");
	return attr;
}

/*! \brief Get the last error from this device */
unsigned int executive::RemoteDevice::getLastError() const {

	assert(0 && "unimplemented");
	return 0;
}

/*! \brief Wait until all asynchronous operations have completed */
void executive::RemoteDevice::synchronize() {
	assert(0 && "unimplemented");
}

/*! \brief Limit the worker threads used by this device */
void executive::RemoteDevice::limitWorkerThreads(unsigned int threads) {
	assert(0 && "unimplemented");
}
			
/*! \brief Set the optimization level for kernels in this device */
void executive::RemoteDevice::setOptimizationLevel(
	translator::Translator::OptimizationLevel level) {

	assert(0 && "unimplemented");
}

/////////////////////////////////////////////////////////////////////////////////////////////////

