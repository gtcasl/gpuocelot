/*!
	\file CudaRuntimeContext.cpp
	\author Andrew Kerr <arkerr@gatech.edu>

	\brief defines objects used by CUDA front ends to maintain context information - note: is NOT
		specific to Ocelot's CUDA Runtime API implementation
	
	\date Sept 16 2010
	\location somewhere over Western Europe
*/

// C standard library includes
#include <assert.h>

// C++ standard library includes
#include <sstream>
#include <algorithm>

// Ocelot includes
#include <ocelot/cuda/interface/CudaRuntime.h>
#include <ocelot/cuda/interface/CudaDriver.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/executive/interface/RuntimeException.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

// GL includes
#include <GL/glew.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////

// whether CUDA runtime catches exceptions thrown by Ocelot
#define CATCH_RUNTIME_EXCEPTIONS 0

// whether verbose error messages are printed
#define CUDA_VERBOSE 1

// whether debugging messages are printed
#define REPORT_BASE 0

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Error handling macros

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

//////////////////////////////////////////////////////////////////////////////////////////////////

typedef api::OcelotConfiguration config;

const char *cuda::FatBinaryContext::name() const {
	if (!cubin_ptr) return "";
	__cudaFatCudaBinary *binary = (__cudaFatCudaBinary *)cubin_ptr;
	return binary->ident;
}	

const char *cuda::FatBinaryContext::ptx() const {
	if (!cubin_ptr) return "";
	__cudaFatCudaBinary *binary = (__cudaFatCudaBinary *)cubin_ptr;
	return binary->ptx->ptx;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cuda::HostThreadContext::HostThreadContext(): selectedDevice(0), 
	parameterBlock(0), parameterBlockSize(1<<13) {
	parameterBlock = (unsigned char *)malloc(parameterBlockSize);
}

cuda::HostThreadContext::~HostThreadContext() {
	::free(parameterBlock);
}

cuda::HostThreadContext::HostThreadContext(const HostThreadContext& c): 
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

cuda::HostThreadContext& cuda::HostThreadContext::operator=(const HostThreadContext& c) {
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

cuda::HostThreadContext::HostThreadContext(HostThreadContext&& c): 
	selectedDevice(0), parameterBlock(0), parameterBlockSize(1<<13) {
	*this = std::move(c);
}

cuda::HostThreadContext& cuda::HostThreadContext::operator=(HostThreadContext&& c) {
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

void cuda::HostThreadContext::clearParameters() {
	parameterIndices.clear();
	parameterSizes.clear();
}

void cuda::HostThreadContext::clear() {
	validDevices.clear();
	launchConfigurations.clear();
	clearParameters();
	persistentTraceGenerators.clear();
	nextTraceGenerators.clear();
}

void cuda::HostThreadContext::mapParameters(const ir::Kernel* kernel) {
	
	assert(kernel->arguments.size() == parameterIndices.size());
	IndexVector::iterator offset = parameterIndices.begin();
	SizeVector::iterator size = parameterSizes.begin();
	unsigned int dst = 0;
	unsigned char* temp = (unsigned char*)malloc(parameterBlockSize);
	for (ir::Kernel::ParameterVector::const_iterator 
		parameter = kernel->arguments.begin(); 
		parameter != kernel->arguments.end(); ++parameter, ++offset, ++size) {
		unsigned int misalignment = dst % parameter->getAlignment();
		unsigned int alignmentOffset = misalignment == 0 
			? 0 : parameter->getAlignment() - misalignment;
		dst += alignmentOffset;
		
		memset(temp + dst, 0, parameter->getSize());
		memcpy(temp + dst, parameterBlock + *offset, *size);
		report( "Mapping parameter at offset " << *offset << " of size " 
			<< *size << " to offset " << dst << " of size " 
			<< parameter->getSize() << " data = " 
			<< hydrazine::dataToString(temp + dst, parameter->getSize()));
		dst += parameter->getSize();
	}
	free(parameterBlock);
	parameterBlock = temp;
	clearParameters();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cuda::RegisteredKernel::RegisteredKernel(size_t h, const std::string& m, 
	const std::string& k) : handle(h), module(m), kernel(k) {
}

cuda::RegisteredTexture::RegisteredTexture(const std::string& m, 
	const std::string& t, bool n) : module(m), texture(t), norm(n) {
	
}

cuda::RegisteredGlobal::RegisteredGlobal(const std::string& m, 
	const std::string& g) : module(m), global(g) {

}

cuda::Dimension::Dimension(int _x, int _y, int _z, 
	const cudaChannelFormatDesc& _f) : x(_x), y(_y), z(_z), format(_f) {

}

size_t cuda::Dimension::pitch() const {
	return ((format.x + format.y + format.z + format.w) / 8) * x;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

