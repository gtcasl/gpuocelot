// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Program.h>

unsigned int opencl::Program::_id = 0;


opencl::Program::Program(const std::string & s, Context * c):
	Object(OBJTYPE_PROGRAM), 
	source(s), built(false), context(c) {
	std::stringstream stream;
	stream << "__clmodule_" << _id;
	name = stream.str();
	_id++;

	context->retain();
}

opencl::Program::~Program() {
	if(context->release())
		delete context;
}


