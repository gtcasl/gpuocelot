/*! \file OcelotConfiguration.cpp
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
#include <hydrazine/interface/Version.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

////////////////////////////////////////////////////////////////////////////////

static api::OcelotConfiguration* ocelotConfiguration = 0;

const api::OcelotConfiguration & api::OcelotConfiguration::get() {
	if (!ocelotConfiguration) {
		ocelotConfiguration = new OcelotConfiguration("configure.ocelot");
	}
	return *ocelotConfiguration;
}

void api::OcelotConfiguration::destroy() {
        delete ocelotConfiguration;
        ocelotConfiguration = 0;
}

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

api::OcelotConfiguration::TraceGeneration::RaceDetector::RaceDetector():
        enabled(false),
        ignoreIrrelevantWrites(true)
{

}
api::OcelotConfiguration::TraceGeneration::Debugger::Debugger():
        enabled(false),
        kernelFilter(""),
        alwaysAttach(false)
{

}

api::OcelotConfiguration::TraceGeneration::TraceGeneration():
	memoryChecker(false)
{

}

static void initializeTrace(api::OcelotConfiguration::TraceGeneration &trace, 
	hydrazine::json::Visitor config) {
	trace.memoryChecker = config.parse<bool>("memoryChecker", true);
    
    hydrazine::json::Visitor raceConfig = config["raceDetector"];
    if (!raceConfig.is_null()) {
            trace.raceDetector.enabled = raceConfig.parse<bool>("enabled", false);
            trace.raceDetector.ignoreIrrelevantWrites = raceConfig.parse<bool>("ignoreIrrelevantWrites", true);
    }

    hydrazine::json::Visitor debugConfig = config["debugger"];
    if (!debugConfig.is_null()) {
            trace.debugger.enabled = debugConfig.parse<bool>("enabled", false);
            trace.debugger.kernelFilter = debugConfig.parse<std::string>("kernelFilter", "");
            trace.debugger.alwaysAttach = debugConfig.parse<bool>("alwaysAttach", false);
    }
}

api::OcelotConfiguration::CudaRuntimeImplementation::CudaRuntimeImplementation():
	implementation("CudaRuntime"),
	runtimeApiTrace("trace/CudaAPI.trace")
{

}

static void initializeCudaRuntimeImplementation(
	api::OcelotConfiguration::CudaRuntimeImplementation &cuda, 
	hydrazine::json::Visitor config) {

	cuda.implementation = config.parse<std::string>(
		"implementation", "CudaRuntime");
	cuda.runtimeApiTrace = config.parse<std::string>(
		"runtimeApiTrace", "trace/CudaAPI.trace");
}

api::OcelotConfiguration::Executive::Executive():
	defaultDeviceID(0),
	preferredISA(ir::Instruction::Emulated),
	optimizationLevel(translator::Translator::FullOptimization),
	required(false),
	enableLLVM(true),
	enableEmulated(true),
	enableNVIDIA(true),
	enableAMD(true),
	workerThreadLimit(-1),
	warpSize(-1)
{

}

static void initializeExecutive(api::OcelotConfiguration::Executive &executive, 
	hydrazine::json::Visitor config) {

	std::string strPrefISA = config.parse<std::string>(
		"preferredISA", "emulated");
	std::string strOptLevel = config.parse<std::string>(
		"optimizationLevel", "full");

	executive.preferredISA = (int)ir::Instruction::Emulated;
	if (strPrefISA == "emulated" || strPrefISA == "Emulated") {
		executive.preferredISA = (int)ir::Instruction::Emulated;
	}
	else if (strPrefISA == "llvm" || strPrefISA == "LLVM") {
		executive.preferredISA = (int)ir::Instruction::LLVM;
	}
	else if (strPrefISA == "nvidia" || strPrefISA == "NVIDIA") {
		executive.preferredISA = (int)ir::Instruction::SASS;
	}
	else if (strPrefISA == "amd" || strPrefISA == "AMD") {
		executive.preferredISA = (int)ir::Instruction::CAL;
	}
	else {
		report("Unknown preferredISA - using Emulated");
	}

	executive.optimizationLevel = (int)translator::Translator::NoOptimization;
	if (strOptLevel == "full") {
		executive.optimizationLevel = 
			(int)translator::Translator::FullOptimization;
	}
	else if (strOptLevel == "debug") {
		executive.optimizationLevel = 
			(int)translator::Translator::DebugOptimization;
	}
	else if (strOptLevel == "report") {
		executive.optimizationLevel = 
			(int)translator::Translator::ReportOptimization;
	}
	else if (strOptLevel == "basic") {
		executive.optimizationLevel = 
			(int)translator::Translator::BasicOptimization;
	}
	else if (strOptLevel == "aggressive") {
		executive.optimizationLevel = 
			(int)translator::Translator::AggressiveOptimization;
	}
	else if (strOptLevel == "space") {
		executive.optimizationLevel = 
			(int)translator::Translator::SpaceOptimization;
	}
	else if (strOptLevel == "instrument") {
		executive.optimizationLevel = 
			(int)translator::Translator::InstrumentOptimization;
	}
	else if (strOptLevel == "memcheck") {
		executive.optimizationLevel = 
			(int)translator::Translator::MemoryCheckOptimization;
	}
	else if (strOptLevel == "none") {
		executive.optimizationLevel = 
			(int)translator::Translator::NoOptimization;
	}
	else {
		report("Unknown optimization level - using none");
	}

	executive.defaultDeviceID = config.parse<int>("defaultDeviceID", 0);
	executive.required = config.parse<bool>("required", false);
	executive.enableLLVM = config.parse<bool>("enableLLVM", true);
	executive.enableEmulated = config.parse<bool>("enableEmulated", true);
	executive.enableNVIDIA = config.parse<bool>("enableNVIDIA", true);
	executive.enableAMD = config.parse<bool>("enableAMD", true);
	executive.workerThreadLimit = config.parse<int>("workerThreadLimit", -1);
	executive.warpSize = config.parse<int>("warpSize", -1);
	
	if (config.find("devices")) {
		hydrazine::json::Visitor devices = config["devices"];
		hydrazine::json::Array *array = 
			static_cast<hydrazine::json::Array *>(devices.value);
		
		executive.enableLLVM = false;
		executive.enableEmulated = false;
		executive.enableNVIDIA = false;
		executive.enableAMD = false;
		
		for (hydrazine::json::Array::ValueVector::iterator it = array->begin();
			it != array->end(); ++it) {
			hydrazine::json::Visitor dev(*it);
			if ((std::string)dev == "llvm") {
				executive.enableLLVM = true;
			}
			else if ((std::string)dev == "nvidia") {
				executive.enableNVIDIA = true;
			}
			else if ((std::string)dev == "amd") {
				executive.enableAMD = true;
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

api::OcelotConfiguration::OcelotConfiguration(
	const std::string &_path): path(_path) {
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
		version = main.parse<std::string>("version", 
			hydrazine::Version().toString());
		ocelot = main.parse<std::string>("ocelot", "ocelot");
	}
	catch (hydrazine::Exception exp) {
		std::cerr << "==Ocelot== WARNING: Could not parse config file '" 
			<< path << "', loading defaults.\n";
	}
	delete config;

	std::string device;
	if (executive.enableEmulated) device = "emulated";
	if (executive.enableLLVM) device = "llvm";
	if (executive.enableNVIDIA) device = "nvidia";
	if (executive.enableAMD) device = "amd";
	report("Ocelot Configuration: " << ocelot 
		<< " " << version << " " << device);
}

////////////////////////////////////////////////////////////////////////////////

