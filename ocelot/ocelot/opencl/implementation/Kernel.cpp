// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Kernel.h>

opencl::Kernel::Kernel(const std::string &n, 
	Program * p,
	Context * c): Object(OBJTYPE_KERNEL),
	name(n), program(p), context(c) {
	parameterBlock = NULL;
	program->retain();
	context->retain();
}

opencl::Kernel::~Kernel()
{
	PointerMap::iterator pointer;
	for(pointer = parameterPointers.begin(); pointer != parameterPointers.end(); pointer++) {
		delete pointer->second;
	}

	if(parameterBlock)
		delete parameterBlock;

	if(program->release())
		delete program;

	if(context->release())
		delete context;
}



