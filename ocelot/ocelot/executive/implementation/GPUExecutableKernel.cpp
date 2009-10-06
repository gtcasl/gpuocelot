/*!
	\file GPUExecutableKernel.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\date October 6, 2009

	\brief implements the GPU kernel callable by the executive
*/

#include <ocelot/executive/interface/GPUExecutableKernel.h>

#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

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
	
	if (kernel.ISA == ir::Instruction::PTX) {
		throw hydrazine::Exception( "GPUExecutableKernel may only be constructed from PTXKernel" );
	}
	
	ptxKernel = new ir::PTXKernel( static_cast<ir::PTXKernel &>(kernel));
}

/*!
	Launch a kernel on a 2D grid
*/
void executive::GPUExecutableKernel::launchGrid(int width, int height) {
	configureParameters();
	/*
	cuLaunchGrid(cuFunc, width, height);
	*/
}

/*!
	Sets the shape of a kernel
*/
void executive::GPUExecutableKernel::setKernelShape(int x, int y, int z) {
	/*
	cuFuncSetBlockShape(cuFunc, x, y, z);
	*/
}
/*
executive::GPUKernel *executive::GPUKernel::fromKernel(ir::PTXKernel *source) {
	GPUKernel *kernel = new GPUKernel();
	
	// emit the PTX kernel to a file
	
	// load the PTX kernel file as a module
	
	// get the kernel
	
	return kernel;
}*/

void executive::GPUExecutableKernel::configureParameters() {
	std::vector< ir::Parameter >::iterator it;
	unsigned int paramSize = 0;
	for (it = parameters.begin(); it != parameters.end(); ++it) {
		it->offset = paramSize;
		paramSize += it->getSize();
	}
	/*
	cuParamSetSize(cuFunc, paramSize);
	for (it = parameters.begin(); it != parameters.end(); ++it) {
		switch (it->type) {
		case ir::Parameter::Int:
			//cuParamSeti(cuFunc, it->offset, it->val_int);
			break;
		
		case ir::Parameter::Float:
			//cuParamSetf(cuFunc, it->offset, it->val_float);
			break;
		
		case ir::Parameter::Float2:
			//cuParamSetf(cuFunc, it->offset, it->val_float2[0]);
			//cuParamSetf(cuFunc, it->offset+sizeof(float), it->val_float2[1]);
			break;
		
		case ir::Parameter::Float4:
			//cuParamSetf(cuFunc, it->offset, it->val_float2[0]);
			//cuParamSetf(cuFunc, it->offset+sizeof(float), it->val_float2[1]);
			//cuParamSetf(cuFunc, it->offset+sizeof(float)*2, it->val_float2[2]);
			//cuParamSetf(cuFunc, it->offset+sizeof(float)*3, it->val_float2[3]);
			break;
		
		case ir::Parameter::Pointer:
			//cuParamSetv(cuFunc, it->offset, it->val_pointer, it->getSize());
			break;
		
		default:
			break;
		}
	}
	*/
}
/////////////////////////////////////////////////////////////////////////////////////////////////

