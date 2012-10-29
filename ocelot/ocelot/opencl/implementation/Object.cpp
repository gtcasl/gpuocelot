// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/OpenCLRuntime.h>
#include <ocelot/opencl/interface/Object.h>
#include <sstream>

#undef REPORT_BASE
#define REPORT_BASE 0

opencl::Object::Object(objT type):
	_objType(type), _references(1) {

	OpenCLRuntime * runtime = dynamic_cast<OpenCLRuntime *>(OpenCLRuntimeInterface::get());
	size_t objSize = runtime->addRuntimeObject(this);
	report("Creating object " << this->toString() << ", object list size = " << objSize);

}

opencl::Object::~Object() {
	OpenCLRuntime * runtime = dynamic_cast<OpenCLRuntime *>(OpenCLRuntimeInterface::get());
	size_t objSize = runtime->removeRuntimeObject(this);

	report("Delete object " << this->toString() << ", object list size = " << objSize);

}

bool opencl::Object::isValidObject(objT type) {

	OpenCLRuntime * runtime = dynamic_cast<OpenCLRuntime *>(OpenCLRuntimeInterface::get());
	
	if(runtime->isRuntimeObjectValid(this))
		return (this->_objType == type);
	else
		return false;
}

void opencl::Object::retain() {
	_references++;
	report("Object " << this->toString() << " retain, reference count " << _references);
}

bool opencl::Object::release() {
	_references--;
	report("Object " << this->toString() << " release, reference count " << _references);
	return (_references == 0);
}

std::string opencl::Object::toString() {
	std::stringstream ss;
	switch(_objType) {
		case OBJTYPE_PLATFORM:
			ss << "Platform Object ";
			break;
		case OBJTYPE_DEVICE:
			ss << "Device Object ";
			break;
		case OBJTYPE_CONTEXT:
			ss << "Context Object ";
			break;
		case OBJTYPE_PROGRAM:
			ss << "Program Object ";
			break;
		case OBJTYPE_KERNEL:
			ss << "Kernel Object ";
			break;
		case OBJTYPE_MEMORY:
			ss << "Memory Object ";
			break;
		case OBJTYPE_COMMANDQUEUE:
			ss << "CommandQueue Object ";
			break;
		case OBJTYPE_EVENT:
			ss << "Event Object ";
			break;

		default:
			ss << "Unknown Object ";
			break;
	}
	ss << this;
	return ss.str();
}
