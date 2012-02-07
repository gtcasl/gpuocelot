// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Object.h>

std::list<opencl::Object *> opencl::Object::_objList = std::list< Object * >();

opencl::Object::Object(objT type):
	_objType(type), _references(1) {

	_objList.push_back(this);

}

opencl::Object::~Object() {
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
}

bool opencl::Object::release() {
	return (--_references == 0);
}
