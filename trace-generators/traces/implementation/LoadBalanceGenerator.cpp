

// C++ includes
#include <iostream>
#include <fstream>

// Boost includes
#include <boost/filesystem.hpp>

// Ocelot includes
#include <traces/interface/WarpSynchronousGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <traces/interface/LoadBalanceGenerator.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_KERNEL_INSTRUCTIONS 0

//////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int trace::LoadBalanceGenerator::_counter = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::LoadBalanceGenerator::LoadBalanceGenerator() {

}

trace::LoadBalanceGenerator::~LoadBalanceGenerator() {

}

/*! \brief called when a traced kernel is launched to retrieve some 
		parameters from the kernel
*/
void trace::LoadBalanceGenerator::initialize(const executive::ExecutableKernel& kernel) {
	_ctas.clear();
	_kernelName = kernel.name;
	_counter ++;
}

/*! \brief Called whenever an event takes place.

	Note, the const reference 'event' is only valid until event() 
	returns
*/
void trace::LoadBalanceGenerator::event(const TraceEvent & event) {
	if (!_ctas.size()) {
		CtaCounter ctaC;
		ctaC.ctaId = event.blockId;
		_ctas.push_back(ctaC);
	}
	if (_ctas.back().ctaId != event.blockId) {
		CtaCounter ctaC;
		ctaC.ctaId = event.blockId;
		_ctas.push_back(ctaC);
	}
	if (!_ctas.back().threads.size()) {
		_ctas.back().threads.resize(event.active.size());
	}
	bool isMem = false;
	if (event.instruction->opcode == ir::PTXInstruction::Ld ||
		event.instruction->opcode == ir::PTXInstruction::St) {
		if (event.instruction->addressSpace == ir::PTXInstruction::Global) {
			isMem = true;
		}
	}
	for (size_t tid = 0; tid < event.active.size(); tid++) {
		if (event.active[tid]) {
			ThreadCounter &thread = _ctas.back().threads[tid];
			thread.dynInstr ++;
			if (isMem) {
				thread.memoryDemand += event.memory_size;
			}
		}
	}
}

/*! \brief called when an event is committed
*/
void trace::LoadBalanceGenerator::postEvent(const TraceEvent & event) {

}

/*! \brief Called when a kernel is finished. There will be no more 
		events for this kernel.
*/
void trace::LoadBalanceGenerator::finish() {
	std::stringstream ss;
	boost::filesystem::path path( database );
	path = path.parent_path();
	path = boost::filesystem::system_complete( path );
	ss << path.string() << "/" << _kernelName << "." << _counter << ".trace";
	
	std::string filename = ss.str();
	std::ofstream file(filename.c_str());
	
	file << "{ kernel: \"" << _kernelName << "\", ctas: [\n";
	for (CtaCounterVector::iterator cta_it = _ctas.begin(); cta_it != _ctas.end(); ++cta_it) {
		size_t instructions = 0, memoryDemand = 0;
		file << "  { cta: [" << cta_it->ctaId.x << ", " << cta_it->ctaId.y << ", " << cta_it->ctaId.z << "], \n";
		file << "    threads: [";
		int n = 0;
		for (ThreadCounterVector::iterator t_it = cta_it->threads.begin(); t_it != cta_it->threads.end(); ++t_it) {
			instructions += t_it->dynInstr;
			memoryDemand += t_it->memoryDemand;
			file << (n++ ? ",":"") << " [" << t_it->dynInstr << ", " << t_it->memoryDemand << "]";
		}
		file << "],\n";
		file << "  dynInstr: " << instructions << ",\n";
		file << "  memoryDemand: " << memoryDemand << "\n";
		file << "},\n";
	}
	file << "  { cta: [ -1, -1, -1 ], threads: [ [0, 0] ] }\n";
	file << "] }\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

