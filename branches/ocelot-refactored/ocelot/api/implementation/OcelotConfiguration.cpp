/*!
	\file OcelotConfiguration.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief configuration class for GPU Ocelot
*/

// C stdlib includes
#include <assert.h>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>

// Hydrazine includes
#include <hydrazine/implementation/json.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

//////////////////////////////////////////////////////////////////////////////////////////////////

api::OcelotConfiguration::TraceGeneration::TraceGeneration():
	enabled(false),
	database("trace/database.trace"),
	inPlaceTraces(false),
	memory(false),
	branch(false),
	sharedComputation(false),
	parallelism(false),
	instruction(false),
	cacheSimulator(false)
{

}

static void initializeTrace(api::OcelotConfiguration::TraceGeneration &trace, 
	hydrazine::json::Visitor config) {

	trace.enabled = config.parse<bool>("enabled", false);
	trace.database = config.parse<std::string>("database", "trace/database.trace");
	trace.inPlaceTraces = config.parse<bool>("inPlaceTraces", false);
	trace.memory = config.parse<bool>("memory", false);
	trace.branch = config.parse<bool>("branch", false);
	trace.sharedComputation = config.parse<bool>("sharedComputation", false);
	trace.instruction = config.parse<bool>("instruction", false);
	trace.cacheSimulator = config.parse<bool>("cacheSimulator", false);
}

api::OcelotConfiguration::CudaRuntimeImplementation::CudaRuntimeImplementation():
	implementation("CudaRuntime"),
	runtimeApiTrace("trace/CudaAPI.trace")
{

}

static void initializeCudaRuntimeImplementation(
	api::OcelotConfiguration::CudaRuntimeImplementation &cuda, 
	hydrazine::json::Visitor config) {

	cuda.implementation = config.parse<std::string>("implementation", "CudaRuntime");
	cuda.runtimeApiTrace = config.parse<std::string>("runtimeApiTrace", "trace/CudaAPI.trace");
}

api::OcelotConfiguration::Executive::Executive():
	defaultDeviceID(0),
	preferredISA("Emulated"),
	required(false),
	enableLLVM(true),
	enableEmulated(true),
	enableGPU(true),
	workerThreadLimit(4)
{

}

static void initializeExecutive(api::OcelotConfiguration::Executive &executive, 
	hydrazine::json::Visitor config) {

	executive.defaultDeviceID = config.parse<int>("defaultDeviceID", 0);
	executive.preferredISA = config.parse<std::string>("preferredISA", "Emulated");
	executive.required = config.parse<bool>("required", false);
	executive.enableLLVM = config.parse<bool>("enableLLVM", true);
	executive.enableEmulated = config.parse<bool>("enableEmulated", true);
	executive.enableGPU = config.parse<bool>("enableGPU", true);
	executive.workerThreadLimit = config.parse<int>("workerThreadLimit", 4);
}

api::OcelotConfiguration::OcelotConfiguration() {

}

api::OcelotConfiguration::OcelotConfiguration(std::istream &stream) {
	initialize(stream);
}

api::OcelotConfiguration::OcelotConfiguration(const std::string &path) {
	std::ifstream file(path.c_str());
	initialize(file);
}

void api::OcelotConfiguration::initialize(std::istream &stream) {
	hydrazine::json::Parser parser;
	hydrazine::json::Object *config = 0;
	try {
		config = parser.parse_object(stream);

		hydrazine::json::Visitor main(config);
		if (main.find("trace")) {
			initializeTrace(trace, main);
		}
		if (main.find("cuda")) {
			initializeCudaRuntimeImplementation(cuda, main);
		}
		if (main.find("executive")) {
			initializeExecutive(executive, main);
		}
	}
	catch (hydrazine::Exception exp) {
		report("api::OcelotConfiguration::initialize() exception: " << exp.message);
	}
	if (config) {
		delete config;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

