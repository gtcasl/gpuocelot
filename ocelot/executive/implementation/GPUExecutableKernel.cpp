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
	ir::Kernel& kernel, const executive::Executive* c ): 
		ExecutableKernel(kernel, c), ptxKernel(0) {
	
	this->ISA = ir::Instruction::GPU;
	report("GPUExecutableKernel()");
	
	ptxKernel = new ir::PTXKernel( static_cast<ir::PTXKernel &>(kernel));

	#if HAVE_CUDA_DRIVER_API == 1
	cuFuncGetAttribute((int*)&_registerCount, 
		CU_FUNC_ATTRIBUTE_NUM_REGS, cuFunction);
	cuFuncGetAttribute((int*)&_constMemorySize, 
		CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES, cuFunction);
	cuFuncGetAttribute((int*)&_localMemorySize, 
		CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES, cuFunction);
	cuFuncGetAttribute((int*)&_sharedMemorySize, 
		CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES, cuFunction);
	#endif

	report("  constructed new GPUExecutableKernel");
}

/*!
	Launch a kernel on a 2D grid
*/
void executive::GPUExecutableKernel::launchGrid(int width, int height) {
	#if HAVE_CUDA_DRIVER_API == 1
	report("executive::GPUExecutableKernel::launchGrid(" << width << ", " << height << ")");
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
//	bytes = 2496;// KERRDEBUG remove this before check in
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
	assertM(false, "No support for getting textures references of GPU kernels");
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
	report("executive::GPUExecutableKernel::configureParameters()");

	std::vector< ir::Parameter >::iterator it = parameters.begin();
	unsigned int paramSize = 0;
	cudaError_enum result;

	for (; it != parameters.end(); ++it) {
		if (it->getElementSize() == 8 && (paramSize % 8)) {
			paramSize += 8 - (paramSize % 8);
		}
		it->offset = paramSize;
		paramSize += it->getSize();
	}
	if (!paramSize) {
		return;
	}

	result = cuParamSetSize(cuFunction, paramSize);
	if (result != CUDA_SUCCESS) {
		report("** failed to set parameter size (" << paramSize << " bytes) for kernel " 
			<< name << "\n - cuParamSetSize returned " << result);
		throw hydrazine::Exception(std::string("Failed to set parameter size for kernel ") + name);
	}
	else {
		report("  set parameter size: " << paramSize);
	}
	for (it = parameters.begin(); it != parameters.end(); ++it) {
		report("Configuring parameter " << it->name 
			<< " " 
			<< " - type: " << it->arrayValues.size() << " x " 
			<< ir::PTXOperand::toString(it->type)
			<< " - value: " << ir::Parameter::value(*it));

		switch (it->type) {
			case ir::PTXOperand::b8:	// fall through
			case ir::PTXOperand::s8:	// fall through
			case ir::PTXOperand::s16:	// fall through
			case ir::PTXOperand::u8:	// fall through
			case ir::PTXOperand::u16:
			{
				// use setv to copy a blob
				unsigned int bytes = it->arrayValues.size() * it->getElementSize();
				char *ptr = new char[bytes];
				
				for (size_t i = 0; i < it->arrayValues.size(); i++) {
					switch (it->getElementSize()) {
						case 2:
							ptr[i*it->getElementSize()+1] = (it->arrayValues[i].val_u16 >> 8);
						case 1:
							ptr[i*it->getElementSize()] = it->arrayValues[i].val_u8;
							break;
						default:
						{
							delete [] ptr;
							report("*** Unsupported parameter size");
							throw hydrazine::Exception("unsupported parameter size");
						}
					}
				}

				report("  - GPUExecutableKernel::configureParameters() - cuParamSetv(offset: " 
					<< it->offset << ", size: " << bytes << " bytes)");
				if (cuParamSetv(cuFunction, it->offset, (void *)ptr, bytes) != CUDA_SUCCESS) {
					report("*** failed to set binary parameter - offset: " << it->offset << ", size: " << bytes);
					throw hydrazine::Exception(std::string("Failed to set parameter ") + it->name + 
						" for kernel " + name);
				}
				delete [] ptr;
				break;
			}

			case ir::PTXOperand::s32:	// fall through
			case ir::PTXOperand::u32:	// fall through
			case ir::PTXOperand::s64:	// fall through
			case ir::PTXOperand::u64:
			{
				size_t offset = it->offset;
				for (ir::Parameter::ValueVector::iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it, offset += it->getElementSize()) {
					size_t value = (size_t)val_it->val_u64;
				
					report("  - GPUExecutableKernel::configureParameters() - cuParamSeti(offset: " << it->offset 
						<< ", value: 0x" << std::hex << value << std::dec << ", size: " << it->getElementSize() << ")");
					if (cuParamSetv(cuFunction, offset, &value, it->getElementSize()) != CUDA_SUCCESS) {
						report("*** failed to set integer parameter");
						throw hydrazine::Exception(std::string("Failed to set parameter ") + it->name + 
							" for kernel " + name);
					}
				}
				break;
			}

			case ir::PTXOperand::f32:
			{
				size_t offset = it->offset;
				for (ir::Parameter::ValueVector::iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it, offset += 4) {
					float value = val_it->val_f32;
					report("  - GPUExecutableKernel::configureParameters() - cuParamSetf(offset: " << it->offset << ", value: " << value << ")");
					if (cuParamSetf(cuFunction, offset, value) != CUDA_SUCCESS) {
						report("*** failed to set floating point parameter" << std::flush);
						throw hydrazine::Exception(std::string("Failed to set parameter ") + it->name + 
							" for kernel " + name);
					}
				}
				break;
			}

			default:
			{
				throw hydrazine::Exception(std::string("Parameter type ") + 
					ir::PTXOperand::toString(it->type) + " not supported for kernel " + name);
			}
		}
	}
	#endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////

