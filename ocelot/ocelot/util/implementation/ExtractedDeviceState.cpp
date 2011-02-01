/*!
	\file ExtractedDeviceState.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 31 Jan 2011
	\brief Data structure describing device state with serialization and deserialization procedures
*/

#include <ocelot/util/interface/ExtractedDeviceState.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

static void emitEscapedString(std::ostream &out, std::string str) {
	
}

static void serialize(std::ostream &out, const ir::Dim3 &dim) {
	out << "[" << dim.x << ", " << dim.y << ", " << dim.z << "]";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

util::ExtractedDeviceState::MemoryAllocation::MemoryAllocation(size_t _size): base(0), size(_size) {
	base = new char[size];
}

util::ExtractedDeviceState::MemoryAllocation::~MemoryAllocation() {
	if (base) {
		delete [] base;
	}
	base = 0; size = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void util::ExtractedDeviceState::KernelLaunch::serialize(std::ostream &out) {
	out << "{ \"module\": \"" << moduleName << "\", \"kernel\": \"" << kernelName << "\",\n";
	out << "  \"gridDim\": "; serialize(gridDim); out << ",\n";
	out << "  \"blockDim\": "; serialize(blockDim); out << ",\n";
	out << "  \"parameterMemorySize\": " << parameterMemorySize << ",\n";
	out << "  \"sharedMemorySize\": " << sharedMemorySize << ",\n";
	out << "  \"parameterMemory\": ";
	out << "}";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

util::ExtractedDeviceState::Module::Module() {

}

util::ExtractedDeviceState::Module::~Module() {
	clear();
}

void util::ExtractedDeviceState::Module::clear() {
	for (GlobalVariableMap::iterator v_it = globalVariablesBefore.begin(); 
		v_it != globalVariablesBefore.end(); ++v_it ) {
		delete v_it->second;
	}
	globalVariablesBefore.clear();
	for (GlobalVariableMap::iterator v_it = globalVariablesAfter.begin(); 
		v_it != globalVariablesAfter.end(); ++v_it ) {
		delete v_it->second;
	}
	globalVariablesAfter.clear();
}

void util::ExtractedDeviceState::serialize(std::ostream &out) {
	out << "{\n";
	out << "  \"name\": \"" << name << "\",\n";
	out << "  \"ptx\": \"";
	emitEscapedString(out, ptx);
	out << "\",\n";
	
	out << "  \"globalsBefore\": {\n";
	int n = 0;
	for (GlobalVariableMap::iterator v_it = globalVariablesBefore.begin(); 
		v_it != globalVariablesBefore.end(); ++v_it ) {
		if (!n++) { out << ",\n"; }
		out << "    \"" << v_it->first << "\": ";
		v_it->second.serialize(out);
	}
	out << "},\n";
	out << "  \"globalsAfter\": {\n";
	n = 0;
	for (GlobalVariableMap::iterator v_it = globalVariablesAfter.begin(); 
		v_it != globalVariablesAfter.end(); ++v_it ) {
		
		out << "    \"" << v_it->first << "\": ";
		v_it->second.serialize(out);
	}
	out << "}\n";
	out << "}\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief constructs from an istream - input must be JSON document
util::ExtractedDeviceState::ExtractedDeviceState(std::istream &in) {
	deserialize(in);
}

util::ExtractedDeviceState::ExtractedDeviceState() {

}

util::ExtractedDeviceState::~ExtractedDeviceState() {
	clear();
}

//! \brief store data in host memory to file
void util::ExtractedDeviceState::serialize(std::ostream &out) {
	// only serialize the module containing the executed kernel
	ModuleMap::const_iterator mod_it = modules.find(kernelLaunch.moduleName);
	if (mod_it == modules.end()) {
		// all modules then, and no 'after' state
	}
	else {
		// serialize this module, before state, kernel launch, and after state
		
		out << "{\n";
		
		out << "}\n";
	}
}

//! \brief load data from JSON file to host memory
void util::ExtractedDeviceState::deserialize(std::istream &in) {

}

//! \brief clear all data structures
void util::ExtractedDeviceState::clear() {
	for (ModuleMap::iterator mod_it = modules.begin(); mod_it != modules.end(); ++mod_it) {
		mod_it->second.clear();
	}
	modules.clear();
	
	for (GlobalAllocationMap::iterator ga_it = globalAllocationsBefore.begin();
		ga_it != globalAllocationsBefore.end(); ++ga_it) {
		
		delete ga_it->second;
	}
	globalAllocationsBefore.clear();
	
	for (GlobalAllocationMap::iterator ga_it = globalAllocationsAfter.begin();
		ga_it != globalAllocationsAfter.end(); ++ga_it) {
		
		delete ga_it->second;
	}
	globalAllocationsAfter.clear();
}

