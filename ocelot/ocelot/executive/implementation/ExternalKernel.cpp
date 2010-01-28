/*! \file ExternalKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 28, 2010
	\brief interface for a kernel defined externally to Ocelot that is to be loaded at runtime
*/

#include <ocelot/executive/interface/ExternalKernel.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::ExternalKernel::LoadingType executive::ExternalKernel::fromString(
	const std::string &str) {

	executive::ExternalKernel::LoadingType loading = LoadingType_invalid;
	if (str == "PTX") {
		loading = PTX_Source;
	}
	else if (str == "LLVM") {
		loading = LLVM_Source;
	}
	else if (str == "Managed") {
		loading = Managed_Object;
	}
	else if (str == "Unmanaged") {
		loading = Unmanaged_Object;
	}
	return loading;
}

executive::ExternalKernel::ExternalKernel(
	LoadingType _type, const std::string & path, const executive::Executive* c):

		ir::ExecutableKernel(c),	loadingType(_type), sourcePath(path), emulatedKernel(0), llvmKernel(0), 
		objectHandle(0), managedFunction(0), unmanagedFunction(0) {

	switch (loadingType) {
	case PTX_Source:
	{
		// load a PTX module 
		
	}
		break;

	case LLVM_Source:
	{
		// load an LLVM module
	}
		break;

	case Managed_Object:
	{
		
	}
		break;

	case Unmanaged_Object:
	{
		
	}
		break;

	default:
		break;
	}
}

executive::ExternalKernel::~ExternalKernel() {

	switch (loadingType) {
		case PTX_Source:
		{
			if (emulatedKernel) {
				delete emulatedKernel;
			}
		}
			break;

		case LLVM_Source:
		{
			if (llvmKernel) {
				delete llvmKernel;
			}
		}
			break;

		case Managed_Object:		// fall through
		case Unmanaged_Object:
		{

		}
		default:
			assert(0 && "unimplemented");
			break;
	}

	emulatedKernel = 0;
	llvmKernel = 0;
	objectHandle = 0;
	unmanagedFunction = 0;
	managedFunction = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
// ExecutableKernel interface
//

/*!	\brief Determines whether kernel is executable */
bool executive::ExternalKernel::executable() {
	switch (loadingType) {
		case PTX_Source:
		{
			return emulatedKernel->executable();
		}
			break;

		case LLVM_Source:
		{
			return llvmKernel->executable();
		}
			break;

		case Managed_Object:
		{
		
		}
			break;

		case Unmanaged_Object:
		{
		
		}
			break;

		default:
			break;
	}
	return false;
}

/*!	\brief Launch a kernel on a 2D grid */
void executive::ExternalKernel::launchGrid(int width, int height) {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->launchGrid(width, height);
		}
			break;

		case LLVM_Source:
		{
			llvmKernel->launchGrid(width, height);
		}
			break;

		default:
			break;
	}
}

/*!	\brief Sets the shape of a kernel */
void executive::ExternalKernel::setKernelShape(int x, int y, int z) {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->setKernelShape(x, y, z);
		}
			break;

		case LLVM_Source:
		{
			llvmKernel->setKernelShape(x, y, z);
		}
			break;

		default:
			break;
	}
}

/*! \brief Changes the amount of external shared memory */
void executive::ExternalKernel::setExternSharedMemorySize(unsigned int bytes) {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->setExternSharedMemorySize(bytes);
		}
			break;

		case LLVM_Source:
		{
			llvmKernel->setExternSharedMemorySize(bytes);
		}
			break;

		default:
			break;
	}
}

/*! \brief Describes the device used to execute the kernel */
void executive::ExternalKernel::setDevice(const executive::Device* device, unsigned int limit) {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->setDevice(device, limit);
		}
			break;

		case LLVM_Source:
		{
			llvmKernel->setDevice(device, limit);
		}
			break;

		default:
			break;
	}
}
	
/*! \brief Indicate that the kernels parameters have been updated */
void executive::ExternalKernel::updateParameterMemory() {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->updateParameterMemory();
		}
			break;

		case LLVM_Source:
		{
			llvmKernel->updateParameterMemory();
		}
			break;

		default:
			break;
	}
}

/*! \brief Indicate that other memory has been updated */
void executive::ExternalKernel::updateMemory() {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->updateMemory();
		}
			break;

		case LLVM_Source:
		{
			llvmKernel->updateMemory();
		}
			break;

		default:
			break;
	}
}

/*! \brief Get a vector of all textures references by the kernel */
ir::ExecutableKernel::TextureVector executive::ExternalKernel::textureReferences() const {
	ir::ExecutableKernel::TextureVector textures;
	return textures;
}

/*!	Notifies all attached TraceGenerators of an event */
void executive::ExternalKernel::traceEvent(const trace::TraceEvent & event) const {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->traceEvent(event);
		}
			break;

		default:
			break;
	}
}

/*!	adds a trace generator to the EmulatedKernel */
void executive::ExternalKernel::addTraceGenerator(trace::TraceGenerator* generator) {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->addTraceGenerator(generator);
		}
			break;

		default:
			break;
	}
}

/*!	removes a trace generator from an EmulatedKernel */
void executive::ExternalKernel::removeTraceGenerator(trace::TraceGenerator* generator) {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->removeTraceGenerator(generator);
		}
			break;

		default:
			break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
// protected methods

/*! 
	\brief update global symbols to refer to global variables in the module this has been added to
		at call time
*/
void executive::ExternalKernel::mergeIntoModule() {
	switch (loadingType) {
		case PTX_Source:
		{
			emulatedKernel->module = module;
			emulatedKernel->initialize();
			emulatedKernel->initializeGlobalMemory();
		}
			break;

		case LLVM_Source:
		{

		}
			break;

		default:
			break;
	}
}

//
//
/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
