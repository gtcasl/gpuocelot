// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Kernel.h>

opencl::Kernel::Kernel(const std::string &n, 
	Program * p,
	const Context * c): name(n), program(p), context(c) {
	parameterBlock = NULL;
}

opencl::Kernel::~Kernel()
{
	PointerMap::iterator pointer;
	for(pointer = parameterPointers.begin(); pointer != parameterPointers.end(); pointer++) {
		delete pointer->second;
	}

	if(parameterBlock)
		delete parameterBlock;
}



