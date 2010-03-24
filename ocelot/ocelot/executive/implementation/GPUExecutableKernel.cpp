/*! \file GPUExecutableKernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date October 6, 2009
	\brief implements the GPU kernel callable by the executive
*/

#include <ocelot/executive/interface/GPUExecutableKernel.h>

#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>

#include <configure.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; report(ss.str()); \
	throw hydrazine::Exception(ss.str()); }

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::GPUExecutableKernel::GPUExecutableKernel(): ptxKernel(0) {
	this->ISA = ir::Instruction::GPU;
}

executive::GPUExecutableKernel::~GPUExecutableKernel() {
	if (ptxKernel) {
		delete ptxKernel;
	}
}

/*!
	Construct a GPUExecutableKernel from an existing kernel
*/
executive::GPUExecutableKernel::GPUExecutableKernel(
	ir::Kernel& kernel, const CUfunction& function, const executive::Executive* c ): 
		ExecutableKernel(kernel, c), ptxKernel(0), cuFunction(function) {
	
	report("GPUExecutableKernel()");
	this->ISA = ir::Instruction::GPU;
	
	ptxKernel = new ir::PTXKernel( static_cast<ir::PTXKernel &>(kernel));
	_parameterMemorySize = mapParameterOffsets();
		
#if HAVE_CUDA_DRIVER_API == 1
	cuFuncGetAttribute((int*)&_registerCount, 
		CU_FUNC_ATTRIBUTE_NUM_REGS, cuFunction);
	report(" Registers - " << _registerCount);
	cuFuncGetAttribute((int*)&_constMemorySize, 
		CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES, cuFunction);
	report(" Constant Memory - " << _constMemorySize);
	cuFuncGetAttribute((int*)&_localMemorySize, 
		CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES, cuFunction);
	report(" Local Memory - " << _localMemorySize);
	cuFuncGetAttribute((int*)&_sharedMemorySize, 
		CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES, cuFunction);
	report(" Shared Memory - " << _sharedMemorySize);
#endif

	report("  constructed new GPUExecutableKernel");
}

/*!
	Launch a kernel on a 2D grid
*/
void executive::GPUExecutableKernel::launchGrid(int width, int height) {
	#if HAVE_CUDA_DRIVER_API == 1
	report("executive::GPUExecutableKernel::launchGrid(" << width 
		<< ", " << height << ")");
	CUresult result;

	result = cuLaunchGrid(cuFunction, width, height);
	if (result != CUDA_SUCCESS) {
		report("  - cuLaunchGrid() failed: " << result);
		throw hydrazine::Exception("cuLaunchGrid() failed ");
	}
	// KERRDEBUG remove this before check in
	{
		result = cuCtxSynchronize();
		if (result != CUDA_SUCCESS) {
			report ("  -cuLaunchGrid() failed on ctx synchronize(): " << result);
			throw hydrazine::Exception("cuCtxSynchronize() failed after launchGrid() was called");
		}
		report("  -cuLaunchGrid() succeeded");
	}
	#endif
}

/*!
	Sets the shape of a kernel
*/
void executive::GPUExecutableKernel::setKernelShape(int x, int y, int z) {
	#if HAVE_CUDA_DRIVER_API == 1
	CUresult result = cuFuncSetBlockShape(cuFunction, x, y, z);
	if (result != CUDA_SUCCESS) {
		report("failed to set kernel shape with result " << result);
		throw hydrazine::Exception("GPUExecutableKernel::setKernelShape() failed");
	}
	#endif
}

void executive::GPUExecutableKernel::setDevice(const Device* device,
	unsigned int limit) {
}

void executive::GPUExecutableKernel::setExternSharedMemorySize(unsigned int bytes) {
	_sharedMemorySize = bytes;
#if HAVE_CUDA_DRIVER_API == 1
	CUresult result;
	result = cuFuncSetSharedSize(cuFunction, bytes);
	if (result != CUDA_SUCCESS) {
		report("  - cuFuncSetSharedSize(" << bytes << " bytes) FAILED: " << result);
		throw hydrazine::Exception("cuFuncSetSharedSize() failed");
	}
	else {
		report("  - cuFuncSetSharedSize(" << bytes << " bytes) succeeded");
	}
#endif
}

void executive::GPUExecutableKernel::updateParameterMemory() {
	configureParameters();
}

void executive::GPUExecutableKernel::updateMemory() {
	updateGlobalMemory();
	updateConstantMemory();
}

ir::ExecutableKernel::TextureVector 
	executive::GPUExecutableKernel::textureReferences() const {
	assertM(false, "no support for getting texture references");
}

void executive::GPUExecutableKernel::updateGlobalMemory() {

}

void executive::GPUExecutableKernel::updateConstantMemory() {

}

void executive::GPUExecutableKernel::addTraceGenerator(
	trace::TraceGenerator *generator)
{
	assertM(false, "No trace generation support in GPU kernel.");
}

void executive::GPUExecutableKernel::removeTraceGenerator(
	trace::TraceGenerator *generator)
{
	assertM(false, "No trace generation support in GPU kernel.");	
}


void executive::GPUExecutableKernel::configureParameters() {
#if HAVE_CUDA_DRIVER_API == 1
	report("executive::GPUExecutableKernel::configureParameters() - size: " << _parameterMemorySize);

	char *paramBuffer = new char[_parameterMemorySize];
	getParameterBlock((unsigned char*)paramBuffer, _parameterMemorySize);

	if (cuParamSetSize(cuFunction, _parameterMemorySize) != CUDA_SUCCESS) {
		delete [] paramBuffer;
		Ocelot_Exception("GPUExecutableKernel::configureParameters() - failed to set parameter size to " 
			<< _parameterMemorySize);
	}
	if (cuParamSetv(cuFunction, 0, paramBuffer, _parameterMemorySize) != CUDA_SUCCESS) {
		delete [] paramBuffer;
		Ocelot_Exception("GPUExecutableKernel::configureParameters() - failed to set parameter data");
	}
	
#endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////

