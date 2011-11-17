/*!
	\file DynamicMulticoreKernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 11, 2011
	\brief implements a dynamic multicore kernel
*/

// Ocelot includes
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreKernel::DynamicMulticoreKernel(executive::Device* d) {

}

executive::DynamicMulticoreKernel::DynamicMulticoreKernel(const ir::IRKernel& _kernel,
	executive::Device* _device) {

	report("DynamicMulticoreKernel(kernel, device)");
	
	const ir::PTXKernel &ptxKernel = static_cast<ir::PTXKernel &>(_kernel);
	
}

executive::DynamicMulticoreKernel::~DynamicMulticoreKernel() {

}

/*!	\brief Launch a kernel on a 2D grid */
void executive::DynamicMulticoreKernel::launchGrid(int width, int height, int depth) {

}

/*!
	\brief compute argument offsets for argument data
	\return number of bytes required for argument memory
*/
size_t executive::DynamicMulticoreKernel::mapArgumentOffsets() {

	return 0;
}

/*!
	\brief given a block of argument memory, sets the values of 
		each argument
	\param argument pointer to argument memory
	\param argumentSize number of bytes to write to argument memory
*/
void executive::DynamicMulticoreKernel::setArgumentBlock(const unsigned char *argument, 
	size_t argumentSize) {

}

/*!
	\brief gets the values of each argument as a block of binary data
	\param argument pointer to argument memory
	\param maxSize maximum number of bytes to write to argument memory
	\return actual number of bytes required by argument memory
*/
size_t executive::DynamicMulticoreKernel::getArgumentBlock(unsigned char *argument,
	size_t maxSize) const {

	return 0;
}

/*!	\brief Sets the shape of a kernel */
void executive::DynamicMulticoreKernel::setKernelShape(int x, int y, int z) {

}

/*! \brief Changes the amount of external shared memory */
void executive::DynamicMulticoreKernel::setExternSharedMemorySize(unsigned int) {

}

/*! \brief Sets the max number of pthreads this kernel can use */
void executive::DynamicMulticoreKernel::setWorkerThreads(unsigned int workerThreadLimit) {

}
	
/*! \brief Indicate that the kernels arguments have been updated */
void executive::DynamicMulticoreKernel::updateArgumentMemory() {

}

/*! \brief Indicate that other memory has been updated */
void executive::DynamicMulticoreKernel::updateMemory() {

}

/*! sets an external function table for the emulated kernel */
void executive::DynamicMulticoreKernel::setExternalFunctionSet(
	const ir::ExternalFunctionSet& s) {

}

/*! clear the external function table for the emulated kernel */
void executive::DynamicMulticoreKernel::clearExternalFunctionSet() {

}

/*! \brief Get a vector of all textures references by the kernel */
executive::ExecutableKernel::TextureVector executive::DynamicMulticoreKernel::textureReferences() const {
	return TextureVector();
}

