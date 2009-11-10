/*!
	\file GPUExecutableKernel.cpp

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

	report("  constructed new GPUExecutableKernel");
}

/*!
	Launch a kernel on a 2D grid
*/
void executive::GPUExecutableKernel::launchGrid(int width, int height) {
	#if HAVE_CUDA_DRIVER_API == 1
	report("executive::GPUExecutableKernel::launchGrid()");
	CUresult result;

	result = cuLaunchGrid(cuFunction, width, height);
	if (result != CUDA_SUCCESS) {
		report("  - cuLaunchGrid() failed: " << result);
		throw hydrazine::Exception("cuLaunchGrid() failed ");
	}
	#endif
}

/*!
	Sets the shape of a kernel
*/
void executive::GPUExecutableKernel::setKernelShape(int x, int y, int z) {
	#if HAVE_CUDA_DRIVER_API == 1
	cuFuncSetBlockShape(cuFunction, x, y, z);
	#endif
}

void executive::GPUExecutableKernel::setDevice(const Device* device,
	unsigned int limit) {
}

void executive::GPUExecutableKernel::setSharedMemorySize(unsigned int bytes) {
#if HAVE_CUDA_DRIVER_API == 1
	CUresult result;
	if (bytes == 0) {
		bytes = 8192;
	}
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

void executive::GPUExecutableKernel::updateGlobalMemory() {

}

void executive::GPUExecutableKernel::updateConstantMemory() {

}

void executive::GPUExecutableKernel::configureParameters() {
#if HAVE_CUDA_DRIVER_API == 1
	report("executive::GPUExecutableKernel::configuraParameters()");

	std::vector< ir::Parameter >::iterator it = parameters.begin();
	unsigned int paramSize = 0;
	cudaError_enum result;
	for (; it != parameters.end(); ++it) {
		it->offset = paramSize;
		paramSize += it->getSize();
	}
	if (!paramSize) {
		return;
	}
	if ((result = cuParamSetSize(cuFunction, paramSize)) != CUDA_SUCCESS) {
		report("** failed to set parameter size (" << paramSize << " bytes) for kernel " << name << "\n - cuParamSetSize returned " << result);
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

				report("  - GPUExecutableKernel::configureParameters() - cuParamSetv(offset: " << it->offset << ", size: " << bytes << " bytes)");
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
					val_it != it->arrayValues.end(); ++val_it, offset += 8) {
					unsigned int value = (unsigned int)val_it->val_u64;
				
					report("  - GPUExecutableKernel::configureParameters() - cuParamSeti(offset: " << it->offset << ", value: 0x" << std::hex << value << std::dec << ")");
					if (cuParamSeti(cuFunction, offset, value) != CUDA_SUCCESS) {
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

