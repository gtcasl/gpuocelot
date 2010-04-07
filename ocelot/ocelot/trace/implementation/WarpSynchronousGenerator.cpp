/*!
	\file WarpSynchronousGenerator.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 1 April 2010
	\brief detects suitability for kernels to execute in warp-synchronized regions
*/

// C++ includes
#include <iostream>
#include <fstream>

// Boost includes
#include <boost/filesystem.hpp>

// Ocelot includes
#include <ocelot/trace/interface/WarpSynchronousGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_KERNEL_INSTRUCTIONS 0

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::WarpCounter::WarpCounter() :
	synchronous(0), events(0)
{
}

void trace::WarpSynchronousGenerator::WarpCounter::event(int warpSize, 
	const trace::TraceEvent &event) {

	int warps = (event.active.size() + warpSize - 1) / warpSize;
	for (int warp = 0; warp < warps; warp++) {
		int tid = warp * warpSize;
		int active = 0;
		for (int i = 0; i < warpSize; i++) {
			if (event.active[tid + i]) {
				++active;
			}
		}

		if (active) {
			++events;
			synchronous += (active == warpSize ? 1 : 0); //= (size_t)active;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::InstructionCounter::InstructionCounter()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::LSInstructionCounter::LSInstructionCounter():
	wordsLoaded(0), wordsStored(0)
{

}

void trace::WarpSynchronousGenerator::LSInstructionCounter::event(int warpSize, 
	const trace::TraceEvent &event) {

	if (event.instruction->addressSpace != ir::PTXInstruction::Global) {
		return;
	}

	ir::PTXU64 mask = (~(4 * warpSize - 1));
	size_t *wordsAccessed = (event.instruction->opcode == ir::PTXInstruction::St ?
		&wordsStored : &wordsLoaded);
	
	std::map< ir::PTXU64, int > addresses;
	int warps = (event.active.size() + warpSize - 1) / warpSize;
	for (int warp = 0; warp < warps; warp++) {
		int tid = warp * warpSize;
		int active = 0;
		for (int i = 0; i < warpSize; i++) {
			if (event.active[tid + i]) {
				++active;
				++*wordsAccessed;
			}
		}

		if (active) {
			addresses.clear();
			bool aligned = false;
			if (event.memory_size == 4) {
				aligned = true;
				for (int i = 0; i < warpSize; i++) {
					if (event.active[tid+i]) {
						addresses[event.memory_addresses[tid + i] & mask] = (tid + i);
					}
				}
				if (addresses.size() == 1) {
					++synchronous;
				}
			}
			++events;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::BranchCounter::BranchCounter()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::TargetCounter::TargetCounter()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::SynchronousInstructionCounter::SynchronousInstructionCounter() {
	// initialize the warp instruction counters

	// add, sub, mul, div, mad
	// f32, s32, u32

	InstructionCounter empty;

	counterVectorizable[ir::PTXInstruction::Add][ir::PTXOperand::f32] = empty;
	counterVectorizable[ir::PTXInstruction::Add][ir::PTXOperand::s32] = empty;
	counterVectorizable[ir::PTXInstruction::Add][ir::PTXOperand::u32] = empty;

	counterVectorizable[ir::PTXInstruction::Sub][ir::PTXOperand::f32] = empty;
	counterVectorizable[ir::PTXInstruction::Sub][ir::PTXOperand::s32] = empty;
	counterVectorizable[ir::PTXInstruction::Sub][ir::PTXOperand::u32] = empty;

	counterVectorizable[ir::PTXInstruction::Mul][ir::PTXOperand::f32] = empty;
	counterVectorizable[ir::PTXInstruction::Mul][ir::PTXOperand::s32] = empty;
	counterVectorizable[ir::PTXInstruction::Mul][ir::PTXOperand::u32] = empty;

	counterVectorizable[ir::PTXInstruction::Mad][ir::PTXOperand::f32] = empty;
	counterVectorizable[ir::PTXInstruction::Mad][ir::PTXOperand::s32] = empty;
	counterVectorizable[ir::PTXInstruction::Mad][ir::PTXOperand::u32] = empty;

	counterVectorizable[ir::PTXInstruction::Div][ir::PTXOperand::f32] = empty;
	counterVectorizable[ir::PTXInstruction::Div][ir::PTXOperand::s32] = empty;
	counterVectorizable[ir::PTXInstruction::Div][ir::PTXOperand::u32] = empty;
}

void trace::WarpSynchronousGenerator::SynchronousInstructionCounter::event(
	int warpSize, const trace::TraceEvent &event) {

	// count specific control flow targets
	std::map< int, TargetCounter >::iterator target_it = counterTargets.find(event.PC);
	if (target_it != counterTargets.end()) {
		target_it->second.event(warpSize, event);
	}

	// handle each specific opcode its own way
	switch (event.instruction->opcode) {
	case ir::PTXInstruction::Bra:
		// handle branches specially
		counterBranches[event.PC].event(warpSize, event);
		break;

	case ir::PTXInstruction::Ld:
	case ir::PTXInstruction::St:
		// handle loads and stores specially
		counterLoadStore.event(warpSize, event);
		break;

	default:
		// record inst
	{
		WarpInstructionCounter::iterator w_it = counterVectorizable.find(event.instruction->opcode);
		if (w_it != counterVectorizable.end()) {
			DataInstructionCounter::iterator inst_counter = w_it->second.find(event.instruction->type);
			if (inst_counter != w_it->second.end()) {
				inst_counter->second.event(warpSize, event);
			}
		}
	}
		break;
	}
}

static void write(std::ostream &out, 
	const trace::WarpSynchronousGenerator::SynchronousInstructionCounter &counter) {

	out << "\t\t\"loadStore\": { \"events\": " << counter.counterLoadStore.events 
		<< ", \"synchronous\": " << counter.counterLoadStore.synchronous
		<< ", \"accessed\": " << (counter.counterLoadStore.wordsLoaded + counter.counterLoadStore.wordsStored)
		<< " },\n";

	out << "\t\t\"arithmetic\": {\n";

	int someEvents = 0;
	trace::WarpSynchronousGenerator::WarpInstructionCounter::const_iterator warp_it = counter.counterVectorizable.begin();
	for (; warp_it != counter.counterVectorizable.end(); ++warp_it) {
		trace::WarpSynchronousGenerator::DataInstructionCounter::const_iterator inst_it = warp_it->second.begin();
		for (; inst_it != warp_it->second.end(); ++inst_it) {
			if (inst_it->second.events) {
				if (someEvents++) {
					out << ",\n";
				}
				out << "\t\t\t\"" << ir::PTXInstruction::toString(warp_it->first) << "." << 
					ir::PTXOperand::toString(inst_it->first) << "\": { ";
				out << " \"events\": " << inst_it->second.events << ", \"synchronous\": " << inst_it->second.synchronous;
				out << " }";
			}
		}
	}
	out << "\n";

	out << "\t\t},\n";
	out << "\t\t\"branches\": [\n";

	std::map< int, trace::WarpSynchronousGenerator::BranchCounter >::const_iterator bra_it;
	bra_it = counter.counterBranches.begin();
	for (; bra_it != counter.counterBranches.end();) {
		out << "\t\t\t{ \"pc\": " << bra_it->first << ", \"events\": " << bra_it->second.events 
			<< ", \"synchronous\": " << bra_it->second.synchronous
			<< ", \"target\": " << bra_it->second.target;
		++bra_it;
		out << " }" << (bra_it != counter.counterBranches.end() ? "," :"") << "\n";
	}
	out << "\t\t],\n";

	out << "\t\t\"targets\": [\n";
	std::map< int, trace::WarpSynchronousGenerator::TargetCounter >::const_iterator targ_it;
	targ_it = counter.counterTargets.begin();
	for (; targ_it != counter.counterTargets.end();) {
		out << "\t\t\t{ \"pc\": " << targ_it->first << ", \"events\": " << targ_it->second.events 
			<< ", \"synchronous\": " << targ_it->second.synchronous;
		++targ_it;
		out << " }" << (targ_it != counter.counterTargets.end() ? "," :"") << "\n";
	}
	out << "\t\t]\n";
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int trace::WarpSynchronousGenerator::_counter = 0;

trace::WarpSynchronousGenerator::WarpSynchronousGenerator() {

	// warp sizes
//	int sizes[] = {2, 4, 8, 16, 32, 0};
	int sizes[] = {4, 0};
	for (int i = 0; sizes[i]; i++) {
		warpSizes.push_back(sizes[i]);
	}
}

trace::WarpSynchronousGenerator::~WarpSynchronousGenerator() {

}

/*!	\brief Initializes the trace generator when a new kernel is 
		about to be launched.
	\param kernel The kernel used to initialize the generator
*/
void trace::WarpSynchronousGenerator::initialize(const ir::ExecutableKernel& kernel) {

	//
	// initialize kernel header
	//
	_entry.name = kernel.name;
	_entry.module = kernel.module->modulePath;
	_entry.format = TraceGenerator::WarpSynchronousTraceFormat;
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
	stream << _entry.format << "_" << trace::WarpSynchronousGenerator::_counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= _entry.program + "_" + name + "_" + stream.str() + ".json";
	path = boost::filesystem::system_complete( path );
	
	_entry.header = path.string();

	//
	// identify all branches and create counters for them
	//
	std::map< int, int > branchPCs;
	std::map< int, std::vector<int> > targetPCs; // map's a target PC to list of branches jumping to it
	if (kernel.ISA == ir::Instruction::Emulated) {
		const executive::EmulatedKernel & emuKernel = 
			static_cast<const executive::EmulatedKernel &>(kernel);

		targetPCs[0].push_back(-1);	// first instruction gets a push

		executive::EmulatedKernel::PTXInstructionVector::const_iterator inst_it;

		int pc = 0;		
		for (inst_it = emuKernel.instructions.begin(); inst_it != emuKernel.instructions.end(); 
			++inst_it, ++pc) {
			const ir::PTXInstruction &inst = *inst_it;

			// complete per-instruction analysis 
			switch (inst.opcode) {
				case ir::PTXInstruction::Bra:
					branchPCs[pc] = inst.branchTargetInstruction;
					targetPCs[inst.branchTargetInstruction].push_back(pc);
					targetPCs[pc+1].push_back(pc);
					break;

				default:
					break;
			}
		}
	}

	// for each warp size, initialize counters and create branch records
	warpCounters.clear();
	for (std::vector<int>::const_iterator ws_it = warpSizes.begin(); ws_it != warpSizes.end();
		++ws_it) {
		SynchronousInstructionCounter syncCounter;
		for (std::map<int,int>::const_iterator bra_it = branchPCs.begin(); 
			bra_it != branchPCs.end(); ++bra_it) {

			BranchCounter braCounter;
			braCounter.target = bra_it->second;
			syncCounter.counterBranches[bra_it->first] = braCounter;
		}
		for (std::map<int, std::vector<int> >::const_iterator targ_it = targetPCs.begin();
			targ_it != targetPCs.end(); ++targ_it) {
			TargetCounter targCounter;

			syncCounter.counterTargets[targ_it->first] = targCounter;
		}
		warpCounters[*ws_it] = syncCounter;
	}
}

/*!
	\brief Called whenever an event takes place.

	\param even The TraceEvent that just occurred
	Note, the const reference 'event' is only valid until event() 
	returns
*/
void trace::WarpSynchronousGenerator::event( const trace::TraceEvent& event ) {
	for (std::map< int, SynchronousInstructionCounter >::iterator counter_it = warpCounters.begin();
		counter_it != warpCounters.end(); ++counter_it) {
		counter_it->second.event(counter_it->first, event);
	}
}

/*!	\brief Finalize the trace and dump the results to disk.
	
	Add a databse entry for the trace as well.
*/
void trace::WarpSynchronousGenerator::finish() {

	// update database
	_entry.updateDatabase(database);

	std::ofstream traceLog(_entry.header.c_str());

	//
	// serialize results
	//
	traceLog << "{\n";
	traceLog << "\t\"kernel\": \"" << _entry.name << "\",\n";
	traceLog << "\t\"module\": \"" << _entry.module << "\",\n";
	traceLog << "\t\"threads\": " << _entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z << ",\n";
	traceLog << "\t\"gridDim\": [" << _entry.gridDim.x << ", " << _entry.gridDim.y << ", " << _entry.gridDim.z << "],\n";
	traceLog << "\t\"blockDim\": [" << _entry.blockDim.x << ", " << _entry.blockDim.y << ", " << _entry.blockDim.z << "],\n";
	traceLog << "\t\"counters\":\n[\n";
	for (std::map< int, SynchronousInstructionCounter >::iterator counter_it = warpCounters.begin();
		counter_it != warpCounters.end(); ) {
		traceLog << "\t{\n\t\"warpSize\": " << counter_it->first << ",\n";
		write(traceLog, counter_it->second);
		++counter_it;
		traceLog << "\t}" << (counter_it != warpCounters.end() ? "," : "") << "\n";
	}
	traceLog << "]\n}\n\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
