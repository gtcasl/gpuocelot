/*!
	\file BasicBlockCountGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 6, 2010
	\brief counts the number of times each basic block is encountered by a thread
*/

// C++ includes
#include <iostream>
#include <fstream>

// Boost includes
#include <boost/filesystem.hpp>

// Ocelot includes
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <traces/interface/TraceConfiguration.h>
#include <traces/interface/BasicBlockCountGenerator.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>
#include <hydrazine/interface/string.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Counter for creating unique file names. */
unsigned int trace::BasicBlockCountGenerator::_counter = 0;

trace::BasicBlockCountGenerator::BasicBlockCountGenerator() {

}

trace::BasicBlockCountGenerator::~BasicBlockCountGenerator() {

}

/*! \brief called when a traced kernel is launched to retrieve some parameters from the kernel
*/
void trace::BasicBlockCountGenerator::initialize(const executive::ExecutableKernel& kernel) {
	
	const executive::EmulatedKernel &emuKernel = static_cast<const executive::EmulatedKernel &>(kernel);
	emulatedKernel = &emuKernel;
	
	
	//
	// initialize kernel header
	//
	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = TraceGenerator::BasicBlockCountFormat;
	_entry.path = "";
	_entry.header = "";
	_entry.program = "";
	_entry.gridDim = kernel.gridDim();
	_entry.blockDim = kernel.blockDim();
	
	std::string name = kernel.name;
	
	if( name.size() > 20 ) {
		name.resize( 20 );
	}

	std::stringstream stream;
	stream << _entry.format << "_" << trace::BasicBlockCountGenerator::_counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= _entry.program + "_" + name + "_" + stream.str() + "_bbcount.json";
	path = boost::filesystem::system_complete( path );
	
	_entry.header = path.string();
	
	
	size_t totalThreads = kernel.blockDim().size() * kernel.gridDim().size();
	basicBlockCounter.clear();
	for (executive::EmulatedKernel::BlockRangeMap::const_iterator
		bb_it = emuKernel.blockPCRange.begin();
		bb_it != emuKernel.blockPCRange.end(); ++bb_it) {
		
		ThreadCounter emptyCounters(totalThreads, 0);
		basicBlockCounter[bb_it->first] = emptyCounters;
	}
}

/*! \brief Called whenever an event takes place.

	Note, the const reference 'event' is only valid until event() 
	returns
*/
void trace::BasicBlockCountGenerator::event(const trace::TraceEvent & event) {
	ir::Dim3 gridDim = emulatedKernel->gridDim();
	size_t blockId = event.blockId.x + event.blockId.y * gridDim.x + event.blockId.z * gridDim.x * gridDim.y;
	
	size_t globalTid = emulatedKernel->blockDim().size() * blockId;
	std::string blockLabel = emulatedKernel->getInstructionBlock(event.PC);
	
	executive::EmulatedKernel::BlockRangeMap::const_iterator r_it = emulatedKernel->blockPCRange.find(blockLabel);
	
	if ((size_t)r_it->second.first == event.PC) {
		ThreadCounter &counter = basicBlockCounter[blockLabel];
		for (size_t tid = 0; tid < event.active.size(); tid++) {
			if (event.active[tid]) {
				++counter[globalTid + tid];
			}
		}
	}
}

/*! \brief called when an event is committed
*/
void trace::BasicBlockCountGenerator::postEvent(const trace::TraceEvent & event) {

}

/*! \brief Called when a kernel is finished. There will be no more events for this kernel.
*/
void trace::BasicBlockCountGenerator::finish() {
	_entry.updateDatabase(database);

	std::ofstream file(_entry.header.c_str());
	
	ir::Dim3 gridDim = emulatedKernel->gridDim();
	ir::Dim3 blockDim = emulatedKernel->blockDim();
	file 
		<< "{"
		<< " \"kernel\": \"" << emulatedKernel->name << "\",\n"
		<< " \"invocation\": " << _counter << ",\n"
		<< " \"gridDim\": [" << gridDim.x << ", " << gridDim.y << ", " << gridDim.z << "],\n"
		<< " \"blockDim\": [" << blockDim.x << ", " << blockDim.y << ", " << blockDim.z << "],\n"
		<< " \"counters\": {\n";
	
	for (BasicBlockCounter::const_iterator bb_it = basicBlockCounter.begin(); 
		bb_it != basicBlockCounter.end(); ++bb_it) {
	
		file << "   \"" << bb_it->first << "\": [";
		size_t tid = 0;
		for (ThreadCounter::const_iterator t_it = bb_it->second.begin(); 
			t_it != bb_it->second.end(); ++t_it, ++tid) {
			file << (tid ? "," : "") << *t_it;
		}
		file << "],\n";
	}
	
	file 
		<< " }\n"
		<< "}\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

