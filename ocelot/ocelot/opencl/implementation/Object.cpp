// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Object.h>

#undef REPORT_BASE
#define REPORT_BASE 0

std::list<opencl::Object *> opencl::Object::_objList = std::list< Object * >();

opencl::Object::Object(objT type):
	_objType(type), _references(1) {

	report("Creating object " << this);
	_objList.push_back(this);

}

opencl::Object::~Object() {
	report("Delete object " << this);
	std::list< Object * >::iterator it = 
		std::find(_objList.begin(), _objList.end(), this);

	assert(it != _objList.end());

	_objList.erase(it);

}

bool opencl::Object::isValidObject(objT type) {
	std::list< Object * >::iterator it = 
		std::find(_objList.begin(), _objList.end(), this);

	if(it == _objList.end())
		return false;

	return (this->_objType == type);
}

void opencl::Object::retain() {
	_references++;
	report("Object " << this << " retain, reference count " << _references);
}

bool opencl::Object::release() {
	_references--;
	report("Object " << this << " release, reference count " << _references);
	return (_references == 0);
}
