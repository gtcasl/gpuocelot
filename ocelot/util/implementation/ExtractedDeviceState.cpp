/*!
	\file ExtractedDeviceState.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 31 Jan 2011
	\brief Data structure describing device state with serialization and deserialization procedures
*/

// C++ includes
#include <iomanip>

// Ocelot includes
#include <ocelot/util/interface/ExtractedDeviceState.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

static void emitEscapedString(std::ostream &out, const std::string &str) {
	for (std::string::const_iterator c_it = str.begin(); c_it != str.end(); ++c_it) {
		if (*c_it == '"') {
			out << "\\\"";
		}
		else {
			out << *c_it;
		}
	}
}

static void serialize(std::ostream &out, const ir::Dim3 &dim) {
	out << "[" << dim.x << ", " << dim.y << ", " << dim.z << "]";
}

static void serializeBinary(std::ostream &out, const size_t size, const char *bytes) {
	const size_t wordSize = 4;
	out << "{ \"bytes\": " << std::setbase(10) << size << ", \"image\": [\n" << std::setbase(16);

	for (size_t n = 0; n < size; n += wordSize) {
		unsigned int word = 0;
		for (size_t j = 0; j < wordSize; j++) {
			if (j+n < size) {
				word |= ((unsigned int)bytes[j+n] << (8*j));		
			}
		}
		if (!(n % 16)) {
			out << "\n";
		}
		out << ((n) ? ", " : "") << "0x" << word;
	}
	out << std::setbase(10) << "] }";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

util::ExtractedDeviceState::MemoryAllocation::MemoryAllocation(size_t _size): base(0), size(_size) {
	base = new char[size];
}
util::ExtractedDeviceState::MemoryAllocation::MemoryAllocation(): base(0), size(0) {

}

util::ExtractedDeviceState::MemoryAllocation::~MemoryAllocation() {
	if (base) {
		delete [] base;
	}
	base = 0; size = 0;
}

void util::ExtractedDeviceState::MemoryAllocation::serialize(std::ostream &out) const {
	out << "{\"base\": " << std::setbase(16) << (const void *)base << ",\n";
	out << "\"data\": ";
	::serializeBinary(out, size, (const char *)base);
	out << "}";	
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void util::ExtractedDeviceState::KernelLaunch::serialize(std::ostream &out) const {
	out << "{ \"module\": \"" << moduleName << "\", \"kernel\": \"" << kernelName << "\",\n";
	out << "  \"gridDim\": "; ::serialize(out, gridDim); out << ",\n";
	out << "  \"blockDim\": "; ::serialize(out, blockDim); out << ",\n";
	out << "  \"parameterMemorySize\": " << parameterMemorySize << ",\n";
	out << "  \"sharedMemorySize\": " << sharedMemorySize << ",\n";
	out << "  \"parameterMemory\": ";
	serializeBinary(out, parameterMemorySize, parameterMemory);
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

void util::ExtractedDeviceState::Module::serialize(std::ostream &out) const {
	out << "{\n";
	out << "  \"name\": \"" << name << "\",\n";
	out << "  \"ptx\": \"";
	emitEscapedString(out, ptx);
	out << "\",\n";
	
	out << "  \"globalsBefore\": {\n";
	int n = 0;
	for (GlobalVariableMap::const_iterator v_it = globalVariablesBefore.begin(); 
		v_it != globalVariablesBefore.end(); ++v_it ) {
		if (!n++) { out << ",\n"; }
		out << "    \"" << v_it->first << "\": ";
		v_it->second->serialize(out);
	}
	out << "},\n";
	out << "  \"globalsAfter\": {\n";
	n = 0;
	for (GlobalVariableMap::const_iterator v_it = globalVariablesAfter.begin(); 
		v_it != globalVariablesAfter.end(); ++v_it ) {
		
		out << "    \"" << v_it->first << "\": ";
		v_it->second->serialize(out);
	}
	out << "}\n";
	out << "}\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void util::ExtractedDeviceState::Application::serialize(std::ostream &out) const {
	out << "{\n\"name\": \"";
	emitEscapedString(out, cudaDevice);
	out << "\",\n\"cudaDevice\":\""; 
	emitEscapedString(out, cudaDevice);
	out << "\"}";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief constructs from an istream - input must be JSON document
util::ExtractedDeviceState::ExtractedDeviceState(std::istream &in) {
	deserialize(in);
}

util::ExtractedDeviceState::ExtractedDeviceState() {

}

util::ExtractedDeviceState::~ExtractedDeviceState() {
	
}

//! \brief store data in host memory to file
void util::ExtractedDeviceState::serialize(std::ostream &out) const {
	// only serialize the module containing the executed kernel
	ModuleMap::const_iterator mod_it = modules.find(launch.moduleName);

		// serialize this module, before state, kernel launch, and after state
		size_t n = 0;
		
		out << "{\n";
		out << "\"application\":";
		
		application.serialize(out);
		
		out << ", \"allocationsBefore\": [";
		n = 0;
		for (GlobalAllocationMap::const_iterator alloc_it = globalAllocationsBefore.begin(); 
			alloc_it != globalAllocationsBefore.end(); ++alloc_it) {
		
			out << (n++ ? ",":"");
			alloc_it->second->serialize(out);
		}
		
		out << "],\n \"allocationsAfter\": [";
		n = 0;
		for (GlobalAllocationMap::const_iterator alloc_it = globalAllocationsBefore.begin(); 
			alloc_it != globalAllocationsBefore.end(); ++alloc_it) {
		
			out << (n++ ? ",":"");
			alloc_it->second->serialize(out);
		}		
		out << "],\n \"kernelLaunch\": ";
		
		out << "\"modules\": [";
		n = 0;
		for (ModuleMap::const_iterator mod_it = modules.begin(); 
			mod_it != modules.end(); ++mod_it) {
			
			out << (n++ ? ",":"");
			mod_it->second.serialize(out);
		}
		out << "]\n";
		out << "}\n";
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

