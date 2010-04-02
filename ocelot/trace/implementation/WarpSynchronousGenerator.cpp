/*!
	\file WarpSynchronousGenerator.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 1 April 2010
	\brief detects suitability for kernels to execute in warp-synchronized regions
*/

// C++ includes
#include <iostream>

// Ocelot includes
#include <ocelot/trace/interface/WarpSynchronousGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

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
			synchronous += 1; //= (size_t)active;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::InstructionCounter::InstructionCounter()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WarpSynchronousGenerator::LSInstructionCounter::LSInstructionCounter()
{

}

void trace::WarpSynchronousGenerator::LSInstructionCounter::event(int warpSize, 
	const trace::TraceEvent &event) {

	ir::PTXU64 mask = (4 * warpSize - 1);
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

			bool aligned = false;
			if (event.memory_size == 4 && !(event.memory_addresses[tid] & mask)) {
				// 32-bit access, potentially aligned
				aligned = true;
				for (int i = 1; i < warpSize; i++) {
					if (event.active[tid+i] && 
						event.memory_addresses[tid + i] != 4 + event.memory_addresses[tid + i - 1]) {
						aligned = false;
						break;
					}
				}
			}
			if (aligned) {
				// w00t
				++synchronous;
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

	out << " loadStore: { events: " << counter.counterLoadStore.events 
		<< ", synchronous: " << counter.counterLoadStore.synchronous << " },\n";

/*
	out << " arithmetic: { events: " << counter.counterVectorizable.events
		<< ", synchronous: " << counter.counterVectorizable.synchronous << " },\n";
*/

	out << " arithmetic: [\n";

	trace::WarpSynchronousGenerator::WarpInstructionCounter::const_iterator warp_it = counter.counterVectorizable.begin();
	for (; warp_it != counter.counterVectorizable.end(); ++warp_it) {

		trace::WarpSynchronousGenerator::DataInstructionCounter::const_iterator inst_it = warp_it->second.begin();
		for (; inst_it != warp_it->second.end(); ++inst_it) {
			if (inst_it->second.events) {
				out << "   \"" << ir::PTXInstruction::toString(warp_it->first) << "." << 
					ir::PTXOperand::toString(inst_it->first) << "\": {\n";
				out << "     events: " << inst_it->second.events << ", synchronous: " << inst_it->second.synchronous;
				out << " },\n";
			}
		}
	}

	out << " ],\n";
	out << " branches: [";

	std::map< int, trace::WarpSynchronousGenerator::BranchCounter >::const_iterator bra_it;
	bra_it = counter.counterBranches.begin();
	for (; bra_it != counter.counterBranches.end(); ++bra_it) {
		out << "  { pc: " << bra_it->first << ", events: " << bra_it->second.events 
			<< ", synchronous: " << bra_it->second.synchronous << " },\n";
	}
	out << "]\n";
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

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

	kernelName = kernel.name;

	// identify all branches and create counters for them
	std::vector< int > branchPCs;
	if (kernel.ISA == ir::Instruction::Emulated) {
		const executive::EmulatedKernel & emuKernel = 
			static_cast<const executive::EmulatedKernel &>(kernel);
		kernelBlockDim = emuKernel.getKernelShape();

		executive::EmulatedKernel::PTXInstructionVector::const_iterator inst_it;

		int pc = 0;		
		for (inst_it = emuKernel.instructions.begin(); inst_it != emuKernel.instructions.end(); 
			++inst_it, ++pc) {
			const ir::PTXInstruction &inst = *inst_it;

			// complete per-instruction analysis 
			switch (inst.opcode) {
				case ir::PTXInstruction::Bra:
					branchPCs.push_back(pc);
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
		for (std::vector<int>::const_iterator bra_it = branchPCs.begin(); 
			bra_it != branchPCs.end(); ++bra_it) {

			BranchCounter braCounter;
			syncCounter.counterBranches[*bra_it] = braCounter;
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
	// serialize results
	std::cout << kernelName << ": {";

	std::cout << " threads: " << kernelBlockDim.x * kernelBlockDim.y * kernelBlockDim.z << ",\n";
	std::cout << " counters: [\n";
	for (std::map< int, SynchronousInstructionCounter >::iterator counter_it = warpCounters.begin();
		counter_it != warpCounters.end(); ++counter_it) {
		std::cout << "{ warpSize: " << counter_it->first << ",\n";
		write(std::cout, counter_it->second);
		std::cout << "},\n";
	}
	std::cout << "]\n}\n\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
