/*!
	\file PerformanceBoundGenerator.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief computes operations, flops, and effective memory bandwidth per basic block
*/

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
#include <traces/interface/PerformanceBoundGenerator.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>
#include <hydrazine/interface/string.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1
#define REPORT_KERNEL_INSTRUCTIONS 0

//////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int trace::PerformanceBoundGenerator::_counter = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::PerformanceBoundGenerator::Counter::Counter():
	memoryDemand(0),
	warpInstructions(0),
	branchInstructions(0),
	noopInstructions(0),
	instructions(0),
	flops(0),
	sharedBytes(0),
	bankConflicts(0),
	stackDepth(0),
	stackVisitNodes(0),
	stackVisitEnd(0),
	stackVisitMiddle(0),
	stackInsert(0),
	stackMerge(0),
	conservativeBranches(0)
{

}

struct thousands: std::numpunct<char> { 
   char do_thousands_sep() const { return ','; } 
   std::string do_grouping() const { return "\3"; }
};

	
/*!
\brief place commas between every three digits
*/
static std::string formatInteger(size_t n) {
	std::stringstream ss;
	ss.imbue(std::locale(std::locale(), new thousands));
	ss << n;
	return ss.str();
}

std::ostream & operator <<(std::ostream &out, 
	const trace::PerformanceBoundGenerator::Counter &counter) {

	out << " | memory demand: " << formatInteger(counter.memoryDemand) << " bytes ";
	if (counter.sharedBytes) {
		out << " | shared mem demand: " << formatInteger(counter.sharedBytes) << " bytes ";
		out << " | shared conflicts: " << formatInteger(counter.bankConflicts) << " ";
	}
	out << " | warp instr: " << formatInteger(counter.warpInstructions) << " ";
	out << " | dynamic instr: " << formatInteger(counter.instructions) << " ";
	out << " | FLOPs: " << formatInteger(counter.flops) << " ";
	if (counter.memoryDemand) {
		out << " | FLOPs per word: " << (double)counter.flops / (double)(counter.memoryDemand) * 4.0 << " ";
		out << " | OPs per byte: " << (double)counter.instructions / (double)(counter.memoryDemand) << " ";
	}
	if (counter.stackDepth) {
		out << " | avg stack depth: " << (double)counter.stackDepth / (double)counter.warpInstructions << " ";
	}
	if (counter.stackVisitNodes && counter.branchInstructions) {
		out << " | avg stack iterations: " << (double)counter.stackVisitNodes / (double)counter.branchInstructions << " ";
	}
	if (counter.stackVisitEnd) {
		out << " | stack visit end: " << counter.stackVisitEnd << " ";
		out << " | stack visit middle: " << counter.stackVisitMiddle << " ";
		out << " | stack inserts: " << counter.stackInsert << " ";
		out << " | stack merges: " << counter.stackMerge << " ";
	}
	if (counter.conservativeBranches) {
		out << " | " << counter.conservativeBranches << " ";
	}
	if (counter.noopInstructions) {
		out << " | " << counter.noopInstructions << " ";
	}

	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////


trace::PerformanceBoundGenerator::PerformanceBoundGenerator() {

}

trace::PerformanceBoundGenerator::~PerformanceBoundGenerator() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void trace::PerformanceBoundGenerator::initialize(const executive::ExecutableKernel &kernel) {

	const executive::EmulatedKernel & emuKernel = 
		static_cast<const executive::EmulatedKernel &>(kernel);

	//
	// initialize kernel header
	//
	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = TraceGenerator::PerformanceBoundTraceFormat;
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
	stream << _entry.format << "_" << trace::PerformanceBoundGenerator::_counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= _entry.program + "_" + name + "_" + stream.str() + ".json";
	path = boost::filesystem::system_complete( path );
	
	_entry.header = path.string();
	
	this->kernel = (& emuKernel);
	analyzeKernel(emuKernel);
}

//! \brief visits each basic block and initializes a counter for each block
void trace::PerformanceBoundGenerator::analyzeKernel(const executive::EmulatedKernel &kernel) {
	ir::ControlFlowGraph *cfg = const_cast<ir::ControlFlowGraph *>(kernel.cfg());
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->executable_sequence();
	ir::ControlFlowGraph::BlockPointerVector::iterator bb_it;
	for (bb_it = blocks.begin(); bb_it != blocks.end(); ++bb_it) {
		Counter counter;
		counterMap[(*bb_it)->label()] = counter;
	}
	
	Counter counter;
	counterMap["entry"] = counter;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

class Formatter: public ir::ControlFlowGraph::BasicBlock::DotFormatter {
public:
	std::map< std::string, int > blocksToPC;
public:

	static std::string colorToString(
		unsigned int r, unsigned int g, unsigned int b, unsigned int a=0) {
		std::stringstream ss;

		ss << "#";
		ss << std::setfill('0') << std::setw(2) << std::hex << (r & 0x0ff);
		ss << std::setfill('0') << std::setw(2) << std::hex << (g & 0x0ff);
		ss << std::setfill('0') << std::setw(2) << std::hex << (b & 0x0ff);
	//	ss << std::setfill('0') << std::setw(2) << std::hex << (a & 0x0ff);
	
		return ss.str();
	}

	Formatter(trace::PerformanceBoundGenerator * gen): generator(gen), maxEvents(1) {
		for (std::map< int, std::string >::const_iterator bl_it = generator->kernel->basicBlockPC.begin();
			bl_it != generator->kernel->basicBlockPC.end(); ++bl_it) {
			
			blocksToPC[bl_it->second] = bl_it->first;
		}
	}
	
	/*!
	
	*/
	virtual std::string entryLabel(const ir::ControlFlowGraph::BasicBlock *block) {
		std::stringstream out;
		out << "[shape=record,style=\"bold,filled\",fillcolor=\"#4444cc\",";
		out << "label=";
		out << "\"{ KERNEL: " << hydrazine::toGraphVizParsableLabel(generator->kernel->name);
		
		if (generator->counterMap.find(block->label()) != generator->counterMap.end()) {
		
			const trace::PerformanceBoundGenerator::Counter & 
				counter = generator->counterMap[block->label()];
			
			/*
			if (blocksToPC.find(block->label) != blocksToPC.end()) {
				out << " | near " << generator->kernel->location(blocksToPC[block->label]);
			}

			out << " | memory demand: " << counter.memoryDemand << " bytes ";
			out << " | dynamic instr: " << counter.instructions << " ";
			out << " | FLOPs: " << counter.flops << " ";
			if (counter.memoryDemand) {
			out << " | FLOPs per word: " << (double)counter.flops / (double)(counter.memoryDemand) * 4.0 << " ";
			out << " | OPs per byte: " << (double)counter.instructions / (double)(counter.memoryDemand) << " ";
			}
			*/
			out << counter;
		}
		
		out << "}\"]";
		return out.str();	
	}
	
	/*!
		\brief prints string representation of a block
	*/
	virtual std::string toString(const ir::ControlFlowGraph::BasicBlock *block) {
		std::stringstream out;

		float t = 1.0f;
		
		if (generator->counterMap.find(block->label()) != generator->counterMap.end()) {
		
			const trace::PerformanceBoundGenerator::Counter & 
				counter = generator->counterMap[block->label()];
				
			t = 0.0f;
			// log-scale color intensity based on number of times block has been reached by a warp
			if (counter.instructions) {
				t = log((float)(counter.instructions)) / (float)log((float)(maxEvents) + 1.0f);
			}
			unsigned int r = (unsigned int)(t * 255.0);
			unsigned int g = (unsigned int)(t * 64.0), b = (unsigned int)(t * 64.0);

			out << "[";
			out << "fillcolor=\"" << Formatter::colorToString(r,g,b) << "\",style=filled,";
			out << "shape=record,label=\"{";
	
			out << hydrazine::toGraphVizParsableLabel(block->label());
		
			if (blocksToPC.find(block->label()) != blocksToPC.end()) {
				std::string loc = generator->kernel->location(blocksToPC[block->label()]);
				if (loc != ":0:0") {
					out << " | near " << generator->kernel->location(blocksToPC[block->label()]);
				}
			}	
			out << counter;
		}
		else {
			out << "[shape=record,";
			out << "label=";
			out << "\"{" << hydrazine::toGraphVizParsableLabel(block->label());
		}
		
		out << "}\"";
		
		if (t < 0.5) {
			out << ",fontcolor=\"#aaaaaa\"";
		}
		out << "]";

		return out.str();
	}
	
public:

	trace::PerformanceBoundGenerator *generator;
	
	/*!
		\brief maximum number of operations performed by some block
	*/
	size_t maxEvents;
};

//! \brief aggregates statistics and emits kernel results
void trace::PerformanceBoundGenerator::finish() {

	// aggregate entry statistics
	for (OperationCounterMap::const_iterator op_it = counterMap.begin();
		op_it != counterMap.end(); ++op_it) {
		
		if (op_it->first != "entry" && op_it->first != "exit") {
			counterMap["entry"] += op_it->second;
		}
	}

	Formatter formatter(this);
	
	std::stringstream ss;
	
	for (OperationCounterMap::const_iterator opit = counterMap.begin(); opit != counterMap.end(); ++opit) {
		if (opit->second.instructions > formatter.maxEvents) {
			formatter.maxEvents = opit->second.instructions;
		}
	}
	
	if (outputFormat == Output_append_csv) {
	
		//
		// append kernel aggregate results
		//
		boost::filesystem::path path(database);
		path = path.parent_path();
		path = boost::filesystem::system_complete(path);
		ss << path.string() << "/performance-bound-results.txt";
		std::ofstream resultsFile(ss.str().c_str(), std::ios_base::app);
	
		const char *app = getenv("APPLICATION");
		const char *reconverge = getenv("RECONVERGE");
		
		app = (app ? app: "unknown-app");
		reconverge = (reconverge ? reconverge : "unknown-reconverge");
	
		// appliction, reconvergence method, kernel name, counter, warp instructions, dynamic scalar instructions, 
		resultsFile 
			<< app << ", " 
			<< reconverge
			<< _entry.name << ", " 
			<< _counter << ", "
			<< counterMap["entry"].warpInstructions << ", " 
			<< counterMap["entry"].instructions << ", "
			<< counterMap["entry"].stackVisitEnd << ", "
			<< counterMap["entry"].stackVisitMiddle << ", "
			<< counterMap["entry"].stackInsert << ", "
			<< counterMap["entry"].stackMerge << ", "
			<< (double)counterMap["entry"].stackDepth / (double)counterMap["entry"].warpInstructions << ", "
			<< counterMap["entry"].branchInstructions << ", "
			<< counterMap["entry"].stackVisitNodes << ", "
			<< counterMap["entry"].conservativeBranches << ", "
			<< counterMap["entry"].noopInstructions;
		
		resultsFile	<< std::endl;

	}
	else if (outputFormat == Output_dot) {
	
		boost::filesystem::path path( database );
		path = path.parent_path();
		path = boost::filesystem::system_complete( path );
		ss << path.string() << "/" << _entry.program << "_" << _entry.name << "_" 
			<< _counter << "_perf.dot";
	
		std::string filename = ss.str();
	
		ir::ControlFlowGraph *controlFlowGraph = const_cast<ir::ControlFlowGraph*>(kernel->cfg());
		std::ofstream cfgFile(filename.c_str());
		cfgFile << "/*\n";
		cfgFile << "     kernel: " << " kernel-name " << "\n";
		cfgFile << "*/\n";

		controlFlowGraph->write(cfgFile, formatter);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void trace::PerformanceBoundGenerator::event(const trace::TraceEvent &event) {
	std::string bbLabel = kernel->getInstructionBlock(event.PC);
	if (bbLabel == "") { 
		report("event.PC = " << event.PC << " does not correspond to a BB");
		return;  // PC doesn't correspond to a basic block
	}
	
	OperationCounterMap::iterator op = counterMap.find(bbLabel);
	if (op == counterMap.end()) { 
		report(" counter not found ");
		return;  // counter not found
	}
	
	/*
	report(bbLabel << " - " << event.instruction->toString() << " - " 
		<< event.active.count() << " active threads");
	*/
	
	if (event.instruction->opcode != ir::PTXInstruction::Reconverge) {
		op->second.warpInstructions ++;
		op->second.stackDepth += event.contextStackSize;
		op->second.instructions += event.active.count();
	}
	else if (!event.active.count()) {
		op->second.noopInstructions ++;
	}
	
	
	if (event.instruction->opcode == ir::PTXInstruction::Bra) {
		op->second.branchInstructions ++;
		op->second.stackVisitEnd += event.reconvergence.stackVisitEnd;
		op->second.stackVisitMiddle += event.reconvergence.stackVisitMiddle;
		op->second.stackInsert += event.reconvergence.stackInsert;
		op->second.stackMerge += event.reconvergence.stackMerge;
		op->second.stackVisitNodes += event.reconvergence.stackVisitNodes;
		op->second.conservativeBranches += (event.reconvergence.conservativeBranch ? 1 : 0);
	}
	
	if (isFlop(*event.instruction)) {
		op->second.flops += event.active.count();
	}
	
	if (isGlobalMemoryOp(*event.instruction)) {
		//op->second.memoryDemand += computeMemoryDemand(event, protocol);
	}
	
	//int conflicts = 0;
	//op->second.sharedBytes += computeSharedDemand(event, &conflicts);
	//op->second.bankConflicts += conflicts;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief computes bytes loaded or stored to shared memory and number of conflicts
size_t trace::PerformanceBoundGenerator::computeSharedDemand(const trace::TraceEvent &event, 
	int * conflicts) {
	typedef std::map< size_t, size_t > SharedBankCounter;
	size_t bytes = 0;
	*conflicts = 0;
		
	if ((event.instruction->opcode == ir::PTXInstruction::Ld || 
		event.instruction->opcode == ir::PTXInstruction::St) &&
		event.instruction->addressSpace == ir::PTXInstruction::Shared) {
	
		size_t end = 0xffffffff;
		std::vector< size_t > addresses;
		for (int n = 0, tid = 0; tid < (int)event.active.size(); ++tid) {
			if (event.active[tid]) {
				addresses.push_back(event.memory_addresses[n++]);
			}
			else {
				addresses.push_back(end);
			}
		}
		
		for (int tid = 0; tid < (int)event.active.size(); tid += 16) {		
			SharedBankCounter bankAddresses;
			for (int t = 0; t < 16; t++) {
				size_t addr = addresses[tid + t];
				if (addr != end) {
					size_t base = (addr & 0x3c);
					SharedBankCounter::iterator bank = bankAddresses.find(base);
					if (bank == bankAddresses.end()) {
						bankAddresses[base] = addr;
					}
					else {
						if (bank->second != addr) {
							++ *conflicts;
						}
					}
					
					bytes += event.memory_size;
				}
			}
		}
	}

	return bytes;
}

//! \brief computes the number of bytes of effective demand from an event given a coalescing protocol
size_t trace::PerformanceBoundGenerator::computeMemoryDemand(const trace::TraceEvent &event, 
	CoalescingProtocol protocol) {
	
	size_t bytes = 0;
	
	// special handling of texture (assume coalesced reads)
	if (event.instruction->opcode == ir::PTXInstruction::Tex) {
		size_t elsize = 1;
		switch (event.instruction->d.type) {
			case ir::PTXOperand::s8:
			case ir::PTXOperand::u8:
			case ir::PTXOperand::b8:
				elsize = 1;
				break;
	
			case ir::PTXOperand::s16:
			case ir::PTXOperand::u16:
			case ir::PTXOperand::f16:
			case ir::PTXOperand::b16:
				elsize = 2;
				break;
	
			case ir::PTXOperand::s32:
			case ir::PTXOperand::u32:
			case ir::PTXOperand::b32:
			case ir::PTXOperand::f32:
				elsize = 4;
				break;
	
			case ir::PTXOperand::s64:
			case ir::PTXOperand::u64:
			case ir::PTXOperand::f64:
			case ir::PTXOperand::b64:
				elsize = 8;
				break;
				
			default:
				elsize = 0;
				break;
		}
		size_t vsize = (size_t)event.instruction->d.vec;
		
		bytes = (size_t)event.active.count() * elsize * vsize;
		return bytes;
	}
	
	switch (protocol) {
	case Protocol_sm_10:	// fall through
	case Protocol_sm_11:
	{
		size_t tid = 0;
		TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();
		size_t transactionSize = (event.memory_size == 16 ? 256 : (event.memory_size == 8 ? 128 : 64));

		std::vector< size_t > addresses;
		addresses.reserve(event.active.size());
		for (int n = 0; tid < event.active.size(); ++tid) {
			if (event.active[tid]) {
				addresses.push_back(event.memory_addresses[n]);
				++n;
			}
			else {
				addresses.push_back(0);
			}
		}
		
		// iterate over each half-warp
		std::map< size_t, size_t > transactions;
		for (tid = 0; tid < event.active.size(); tid += 16) {

			for (size_t t = 0; t < 16; t++) {
				size_t & address = addresses[t + tid];
				size_t base = (address & (~0x0f));
				if (address) {
					if (event.memory_size * t + base == address) {
						transactions[base] = transactionSize;
					}
					else {
						transactions[address] = transactionSize;
					}
				}
			}
			
			// add up the size of each transaction
			for (std::map<size_t, size_t>::const_iterator tr_it = transactions.begin();
				tr_it != transactions.end(); ++tr_it) {
				bytes += tr_it->second;
			}
			transactions.clear();
		}
		
	}
		break;
		
	case Protocol_sm_12:	// fall through
	case Protocol_sm_13:	// fall through
	case Protocol_sm_20:
	{
		size_t tid = 0;
		TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();

		std::vector< size_t > addresses;
		addresses.reserve(event.active.size());
		for (int n = 0; tid < event.active.size(); ++tid) {
			if (event.active[tid]) {
				addresses.push_back(event.memory_addresses[n]);
				++n;
			}
			else {
				addresses.push_back(0);
			}
		}
		
		// iterate over each half-warp
		std::map< size_t, size_t > transactions;
		for (tid = 0; tid < event.active.size(); tid += 16) {
			for (size_t t = 0; t < 16; t++) {
				size_t & address = addresses[t + tid];
				size_t base = (address & (~0x0f));
				if (address) {
					transactions[base] = (event.memory_size >= 2 ? 64 : 32);
				}
			}
			// add up the size of each transaction
			for (std::map<size_t, size_t>::const_iterator tr_it = transactions.begin();
				tr_it != transactions.end(); ++tr_it) {
				bytes += tr_it->second;
			}
			transactions.clear();
		}
	}
		break;
	
	// only count the actual number of distinct loads or stores	
	case Protocol_ideal:
	{
		std::map< size_t, size_t > transactions;
		for (TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();
			addr_it != event.memory_addresses.end(); ++addr_it) {
			transactions[*addr_it] = event.memory_size;
		}
		// add up the size of each transaction
		for (std::map<size_t, size_t>::const_iterator tr_it = transactions.begin();
			tr_it != transactions.end(); ++tr_it) {
			bytes += tr_it->second;
		}
	}
		break;
		
	default:
		break;
	}
	
	return bytes;
}

typedef struct {
	ir::PTXInstruction::Opcode opcode;
	int flops;
} OpcodeWeight;

//! \brief determines if instruction is a significant floating-point operation
int trace::PerformanceBoundGenerator::isFlop(const ir::PTXInstruction &instr) {
	
	OpcodeWeight flopOpcodes[] = {
		{ir::PTXInstruction::Add, 1},
		{ir::PTXInstruction::AddC, 1},
		{ir::PTXInstruction::Mad, 2},
		
		{ir::PTXInstruction::Cos, 1},
		{ir::PTXInstruction::Div, 1},
		{ir::PTXInstruction::Ex2, 1},

		{ir::PTXInstruction::Fma, 2},
		{ir::PTXInstruction::Lg2, 1},
		{ir::PTXInstruction::Mad, 2},
		{ir::PTXInstruction::Mul, 1},
		{ir::PTXInstruction::Rcp, 1},
		{ir::PTXInstruction::Rsqrt, 1},
		{ir::PTXInstruction::Sin, 1},
		{ir::PTXInstruction::Sqrt, 1},
		{ir::PTXInstruction::Sub, 1},
		{ir::PTXInstruction::SubC, 1},
		
		{ir::PTXInstruction::Nop, 0}
	};
	
	int flops = 0;
	
	if (instr.d.type == ir::PTXOperand::f32 ||
		instr.d.type == ir::PTXOperand::f64) {
		
		for (int n = 0; 
			flopOpcodes[n].opcode != ir::PTXInstruction::Nop && flopOpcodes[n].flops;
			++n) {
			if (flopOpcodes[n].opcode == instr.opcode) {
				flops = flopOpcodes[n].flops * (int)instr.vec;
				break;
			}
		}
	}

	return flops;
}

bool trace::PerformanceBoundGenerator::isGlobalMemoryOp(const ir::PTXInstruction &instr) {
	if (((instr.opcode == ir::PTXInstruction::Ld || instr.opcode == ir::PTXInstruction::St) && 
			instr.addressSpace == ir::PTXInstruction::Global)
		 || instr.opcode == ir::PTXInstruction::Tex) {
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

