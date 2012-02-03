// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Context.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif


opencl::Context::Context(): selectedDevice(0),
	lastError(CL_SUCCESS) {
}

opencl::Context::~Context() {
}

opencl::Context::Context(const Context& c): 
	selectedDevice(c.selectedDevice),
	validDevices(c.validDevices),
	lastError(c.lastError),
	persistentTraceGenerators(c.persistentTraceGenerators),
	nextTraceGenerators(c.nextTraceGenerators) {
}

opencl::Context& opencl::Context::operator=(
	const Context& c) {
	if(&c == this) return *this;
	selectedDevice = c.selectedDevice;
	validDevices = c.validDevices;
	lastError = c.lastError;
	persistentTraceGenerators = c.persistentTraceGenerators;
	nextTraceGenerators = c.nextTraceGenerators;
	return *this;
}

opencl::Context::Context(Context&& c): 
	selectedDevice(0) {
	*this = std::move(c);
}

opencl::Context& opencl::Context::operator=(
	Context&& c) {
	if (this == &c) return *this;
	std::swap(selectedDevice, c.selectedDevice);
	std::swap(validDevices, c.validDevices);
	std::swap(lastError, c.lastError);
	std::swap(persistentTraceGenerators, c.persistentTraceGenerators);
	std::swap(nextTraceGenerators, c.nextTraceGenerators);
	return *this;
}


void opencl::Context::clear() {
	validDevices.clear();
	persistentTraceGenerators.clear();
	nextTraceGenerators.clear();
}


