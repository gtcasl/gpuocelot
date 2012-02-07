// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Context.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif


opencl::Context::Context(Platform * p, DeviceList & devices): 
	Object(OBJTYPE_CONTEXT), platform(p) {

	for(DeviceList::iterator d = devices.begin();
		d != devices.end(); d++) {
		this->validDevices.push_back(*d);
		(*d)->retain();
	}

	platform->retain();
}

opencl::Context::~Context() {
	for(std::list< Device * >::iterator d = validDevices.begin();
		d != validDevices.end(); d++) {
		if((*d)->release())
			delete (*d);
	}

	if(platform->release())
		delete platform;
}

