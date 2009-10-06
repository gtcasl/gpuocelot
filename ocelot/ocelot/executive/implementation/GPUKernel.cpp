/*!
	\file GPUKernel.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 19, 2009

	\brief implements the GPU kernel callable by the executive
*/

#include <ocelot/executive/interface/GPUKernel.h>

executive::GPUKernel::GPUKernel() {
	this->ISA = ir::Instruction::GPU;
}

executive::GPUKernel::~GPUKernel() {
	
}

/*!
	Construct a GPU Kernel from an existing kernel
*/
executive::GPUKernel::GPUKernel( ir::Kernel& kernel, const executive::Executive* c ): 
	ExecutableKernel(kernel, c) {

}

/*!
	Launch a kernel on a 2D grid
*/
void executive::GPUKernel::launchGrid(int width, int height) {
	configureParameters();
	/*
	cuLaunchGrid(cuFunc, width, height);
	*/
}

/*!
	Sets the shape of a kernel
*/
void executive::GPUKernel::setKernelShape(int x, int y, int z) {
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

void executive::GPUKernel::configureParameters() {
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
