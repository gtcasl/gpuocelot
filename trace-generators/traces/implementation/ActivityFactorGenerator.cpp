#include <traces/interface/ActivityFactorGenerator.h>


trace::ActivityFactorGenerator::ActivityFactorGenerator() {
	invocations = 0;
}

trace::ActivityFactorGenerator::~ActivityFactorGenerator() {

}

/*! \brief called when a traced kernel is launched to retrieve some 
		parameters from the kernel
*/
void trace::ActivityFactorGenerator::initialize(const executive::ExecutableKernel& kernel) {
	dynamicInstructions = threadInstructions = 0;
	
	kernelName = kernel.name;
	blockDim = kernel.blockDim();
	++invocations;
}

/*! \brief Called whenever an event takes place.

	Note, the const reference 'event' is only valid until event() 
	returns
*/
void trace::ActivityFactorGenerator::event(const TraceEvent & event) {
	++dynamicInstructions;
	threadInstructions += event.active.count();
}

/*! \brief Called when a kernel is finished. There will be no more 
		events for this kernel.
*/
void trace::ActivityFactorGenerator::finish() {
	
	std::ofstream file("traceActivityFactor.json", std::ios::app);
	
	double activity = 0;
	if (dynamicInstructions) {
		activity = (double)threadInstructions / (double)(dynamicInstructions * blockDim.size());
	}
	
	file << "{ \"kernel\": \"" << kernelName << "\", \"invocation\": " << invocations << ",\n"
		<< "  \"blockDim\": [" << blockDim.x << ", " << blockDim.y << ", " << blockDim.z << " ],\n"
		<< "  \"events\": " << dynamicInstructions << ",\n"
		<< "  \"threadInstructions\": " << threadInstructions << ",\n"
		<< "  \"activity\": " << activity << "\n"
		<< "},\n";
}

