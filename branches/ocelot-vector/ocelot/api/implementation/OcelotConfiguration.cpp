/*!
	\file OcelotConfiguration.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief configuration class for GPU Ocelot
*/

// C stdlib includes
#include <assert.h>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>

#include <ocelot/ir/interface/Instruction.h>
#include <ocelot/translator/interface/Translator.h>

// Hydrazine includes
#include <hydrazine/implementation/json.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

//////////////////////////////////////////////////////////////////////////////////////////////////

static api::OcelotConfiguration * ocelotConfiguration = 0;

const api::OcelotConfiguration & api::OcelotConfiguration::get() {
	if (!ocelotConfiguration) {
		ocelotConfiguration = new OcelotConfiguration("configure.ocelot");
	}
	return *ocelotConfiguration;
}

const api::OcelotConfiguration::Executive & api::OcelotConfiguration::getExecutive() {
	return get().executive;
}

const api::OcelotConfiguration::CudaRuntimeImplementation & api::OcelotConfiguration::getCuda() {
	return get().cuda;
}

const api::OcelotConfiguration::TraceGeneration & api::OcelotConfiguration::getTrace() {
	return get().trace;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

api::OcelotConfiguration::Checkpoint::Checkpoint():
	enabled(false), path("."), prefix("check"), suffix(".binary"), verify(false)
{
	
}

static void initializeCheckpoint(api::OcelotConfiguration::Checkpoint &check,
	hydrazine::json::Visitor config) {

	check.enabled = config.parse<bool>("enabled", false);
	check.path = config.parse<std::string>("path", "trace/");
	check.prefix = config.parse<std::string>("prefix", "check");
	check.suffix = config.parse<std::string>("suffix", ".binary");
	check.verify = config.parse<bool>("verify", false);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

api::OcelotConfiguration::TraceGeneration::WarpSynchronous::WarpSynchronous():
	enabled(false),
	emitHotPaths(false)
{

}

api::OcelotConfiguration::TraceGeneration::TraceGeneration():
	enabled(false),
	database("trace/database.trace"),
	inPlaceTraces(false),
	memory(false),
	branch(false),
	sharedComputation(false),
	parallelism(false),
	instruction(false),
	cacheSimulator(false),
	memoryChecker(false),
	raceDetector(false)
{

}

static void initializeTrace(api::OcelotConfiguration::TraceGeneration &trace, 
	hydrazine::json::Visitor config) {

	trace.enabled = config.parse<bool>("enabled", true);
	trace.database = config.parse<std::string>("database", "trace/database.trace");

	// enable/disable flags
	trace.inPlaceTraces = config.parse<bool>("inPlaceTraces", false);
	trace.memory = config.parse<bool>("memory", false);
	trace.branch = config.parse<bool>("branch", false);
	trace.sharedComputation = config.parse<bool>("sharedComputation", false);
	trace.instruction = config.parse<bool>("instruction", false);
	trace.parallelism = config.parse<bool>("parallelism", false);
	trace.cacheSimulator = config.parse<bool>("cacheSimulator", false);
	trace.memoryChecker = config.parse<bool>("memoryChecker", true);
	trace.raceDetector = config.parse<bool>("raceDetector", true);

	// more detailed configuration for this trace generator
	hydrazine::json::Visitor warpSyncConfig = config["warpSynchronous"];
	trace.warpSynchronous.enabled = warpSyncConfig.parse<bool>("enabled", false);
	trace.warpSynchronous.emitHotPaths = warpSyncConfig.parse<bool>("emitHotPaths", false);
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
	preferredISA(ir::Instruction::Emulated),
	optimizationLevel(translator::Translator::FullOptimization),
	required(false),
	enableLLVM(true),
	enableEmulated(true),
	enableGPU(true),
	workerThreadLimit(4)
{

}

static void initializeExecutive(api::OcelotConfiguration::Executive &executive, 
	hydrazine::json::Visitor config) {

	std::string strPrefISA = config.parse<std::string>("preferredISA", "emulated");
	std::string strOptLevel = config.parse<std::string>("optimizationLevel", "full");

	executive.preferredISA = (int)ir::Instruction::Emulated;
	if (strPrefISA == "emulated" || strPrefISA == "Emulated") {
		executive.preferredISA = (int)ir::Instruction::Emulated;
	}
	else if (strPrefISA == "llvm" || strPrefISA == "LLVM") {
		executive.preferredISA = (int)ir::Instruction::LLVM;
	}
	else if (strPrefISA == "gpu" || strPrefISA == "GPU") {
		executive.preferredISA = (int)ir::Instruction::GPU;
	}
	else {
		report("Unknown preferredISA - using Emulated");
	}

	executive.optimizationLevel = (int)translator::Translator::NoOptimization;
	if (strOptLevel == "full") {
		executive.optimizationLevel = (int)translator::Translator::FullOptimization;
	}
	else if (strOptLevel == "debug") {
		executive.optimizationLevel = (int)translator::Translator::DebugOptimization;
	}
	else if (strOptLevel == "report") {
		executive.optimizationLevel = (int)translator::Translator::ReportOptimization;
	}
	else if (strOptLevel == "basic") {
		executive.optimizationLevel = (int)translator::Translator::BasicOptimization;
	}
	else if (strOptLevel == "aggressive") {
		executive.optimizationLevel = (int)translator::Translator::AggressiveOptimization;
	}
	else if (strOptLevel == "space") {
		executive.optimizationLevel = (int)translator::Translator::SpaceOptimization;
	}
	else if (strOptLevel == "instrument") {
		executive.optimizationLevel = (int)translator::Translator::InstrumentOptimization;
	}
	else if (strOptLevel == "memcheck") {
		executive.optimizationLevel = (int)translator::Translator::MemoryCheckOptimization;
	}
	else if (strOptLevel == "none") {
		executive.optimizationLevel = (int)translator::Translator::NoOptimization;
	}
	else {
		report("Unknown optimization level - using none");
	}

	executive.defaultDeviceID = config.parse<int>("defaultDeviceID", 0);
	executive.required = config.parse<bool>("required", false);
	executive.enableLLVM = config.parse<bool>("enableLLVM", true);
	executive.enableEmulated = config.parse<bool>("enableEmulated", true);
	executive.enableGPU = config.parse<bool>("enableGPU", true);
	executive.workerThreadLimit = config.parse<int>("workerThreadLimit", 4);
	
	if (config.find("devices")) {
		hydrazine::json::Visitor devices = config["devices"];
		hydrazine::json::Array *array = static_cast<hydrazine::json::Array *>(devices.value);
		
		executive.enableLLVM = executive.enableEmulated = executive.enableGPU = false;
		
		for (hydrazine::json::Array::ValueVector::iterator it = array->begin(); it != array->end(); 
			++it) {
			hydrazine::json::Visitor dev(*it);
			if ((std::string)dev == "llvm") {
				executive.enableLLVM = true;
			}
			else if ((std::string)dev == "gpu") {
				executive.enableGPU = true;
			}
			else if ((std::string)dev == "emulated") {
				executive.enableEmulated = true;
			}
		}
	}
}

api::OcelotConfiguration::OcelotConfiguration() {

}

api::OcelotConfiguration::OcelotConfiguration(std::istream &stream) {
	initialize(stream);
}

api::OcelotConfiguration::OcelotConfiguration(const std::string &_path): path(_path) {
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
			initializeTrace(trace, main["trace"]);
		}
		if (main.find("cuda")) {
			initializeCudaRuntimeImplementation(cuda, main["cuda"]);
		}
		if (main.find("executive")) {
			initializeExecutive(executive, main["executive"]);
		}
		if (main.find("checkpoint")) {
			initializeCheckpoint(checkpoint, main["checkpoint"]);
		}
		version = main.parse<std::string>("version", "1.0.65");
		ocelot = main.parse<std::string>("ocelot", "ocelot-refactored");
	}
	catch (hydrazine::Exception exp) {
		report("api::OcelotConfiguration::initialize() exception: " << exp.what());
	}
	if (config) {
		delete config;
	}

	std::string device;
	if (executive.enableEmulated) device = "emulated";
	if (executive.enableLLVM) device = "llvm";
	if (executive.enableGPU) device = "gpu";
	report("Ocelot Configuration: " << ocelot << " " << version << " " << device);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

