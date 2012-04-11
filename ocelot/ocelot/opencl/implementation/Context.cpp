// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/OpenCLRuntime.h>
#include <ocelot/opencl/interface/Context.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

opencl::Context::Context(const cl_context_properties * properties,
	cl_uint num_devices,
	const cl_device_id * devices,
	void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
	void * user_data):
	Object(OBJTYPE_CONTEXT) {

	report("Creating new context ");

	if(properties[0] != CL_CONTEXT_PLATFORM 
		|| properties[2] != 0 /*properties terminates with 0*/ )
		throw CL_INVALID_PROPERTY;
	
	if(!((Platform *)properties[1])->isValidObject(Object::OBJTYPE_PLATFORM))
			throw CL_INVALID_PLATFORM;
	_platform = (Platform *)properties[1];

	for (cl_uint i = 0; i < num_devices; i++) {
		if(devices[i] == NULL  	
			|| !devices[i]->isValidObject(Object::OBJTYPE_DEVICE)) {
			throw CL_INVALID_DEVICE;
			break;             	
		}
		_validDevices.push_back(devices[i]);
		devices[i]->retain();
	}

	_properties = new cl_context_properties[3];
	memcpy(_properties, properties, 3*sizeof(cl_context_properties));

	_platform->retain();
}

opencl::Context::Context(const cl_context_properties * properties,
	cl_device_type                device_type,
	void (CL_CALLBACK *     pfn_notify)(const char *, const void *, size_t, void *),
	void *                        user_data) : Object(OBJTYPE_CONTEXT) {

	report("Creating new context ");

	if(properties[0] != CL_CONTEXT_PLATFORM 
		|| properties[2] != 0 /*properties terminates with 0*/ )
		throw CL_INVALID_PROPERTY;
	
	if(!((Platform *)properties[1])->isValidObject(Object::OBJTYPE_PLATFORM))
			throw CL_INVALID_PLATFORM;
	_platform = (Platform *)properties[1];

	_properties = new cl_context_properties[3];
	memcpy(_properties, properties, 3*sizeof(cl_context_properties));

	cl_uint deviceNum;
	Device::getDevices((cl_platform_id)_platform, device_type, 0, NULL, &deviceNum);
	cl_device_id * devices = new cl_device_id[deviceNum];
	Device::getDevices((cl_platform_id)_platform, device_type, deviceNum, devices, NULL);	
	
	for (cl_uint i = 0; i < deviceNum; i++) {
		_validDevices.push_back(devices[i]);
		devices[i]->retain();
	}
	delete[] devices;

	_platform->retain();

}


opencl::Context::~Context() {
	for(Device::DeviceList::iterator d = _validDevices.begin();
		d != _validDevices.end(); d++) {
		(*d)->release();
	}

	_platform->release();

	delete[] _properties;
}

void opencl::Context::release() {
	if(Object::release())
		delete this;
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

void opencl::Context::getInfo(cl_context_info    param_name,
					size_t             param_value_size,
					void *             param_value,
					size_t *           param_value_size_ret) {

	size_t infoLen = 0;
	cl_uint info;
	void * ptr = &info;
	bool needsFree = false;

	switch(param_name) {
		case CL_CONTEXT_REFERENCE_COUNT:
			infoLen = sizeof(cl_uint);
			info = _references;	
			break;

		case CL_CONTEXT_NUM_DEVICES:
			infoLen = sizeof(cl_uint);
			info = _validDevices.size();
			break;

		case CL_CONTEXT_DEVICES: {
			infoLen = _validDevices.size() * sizeof(cl_device_id);
			cl_device_id * devices = new cl_device_id[_validDevices.size()];
			cl_uint i = 0;
			for(Device::DeviceList::iterator d = _validDevices.begin();
				d != _validDevices.end(); d++)
				devices[i++] = (cl_device_id)(*d); 
			ptr = (void *) devices;
			needsFree = true;
			break;
		}

		case CL_CONTEXT_PROPERTIES:
			infoLen = 3 * sizeof(cl_context_properties);
			ptr = _properties;
			break;
	}

	if(param_value && param_value_size < infoLen)
		throw CL_INVALID_VALUE;
	
	if(param_value != 0)
		std::memcpy(param_value, ptr, infoLen);

	if(param_value_size_ret !=0 )
		*param_value_size_ret = infoLen;

	if(needsFree)
		delete[] (const unsigned char *)ptr;
}
