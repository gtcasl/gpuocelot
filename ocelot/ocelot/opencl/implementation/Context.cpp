// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Context.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif


opencl::Context::Context(Platform * p, Device::DeviceList & devices): 
	Object(OBJTYPE_CONTEXT), _platform(p) {

	for(Device::DeviceList::iterator d = devices.begin();
		d != devices.end(); d++) {
		this->_validDevices.push_back(*d);
		(*d)->retain();
	}

	_platform->retain();
}

opencl::Context::~Context() {
	for(Device::DeviceList::iterator d = _validDevices.begin();
		d != _validDevices.end(); d++) {
		if((*d)->release())
			delete (*d);
	}

	if(_platform->release())
		delete _platform;
}

opencl::Device::DeviceList & opencl::Context::getValidDevices() {
	return _validDevices;
}

bool opencl::Context::isValidDevice(Device * device) {

	if(find(_validDevices.begin(), _validDevices.end(), device) 
		== _validDevices.end())
		return false;
	
	return true;
}

