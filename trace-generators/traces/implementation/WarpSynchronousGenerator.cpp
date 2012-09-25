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
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <traces/interface/TraceConfiguration.h>
#include <traces/interface/WarpSynchronousGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>
#include <hydrazine/interface/string.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_KERNEL_INSTRUCTIONS 0

//! if 1, warp size is set to the number of threads in the CTA
#define UNIFORM_CONTROL_FLOW_ONLY 1

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
void trace::WarpSynchronousGenerator::initialize(const executive::ExecutableKernel& kernel) {

	const executive::EmulatedKernel & emuKernel = 
		static_cast<const executive::EmulatedKernel &>(kernel);

	//
	// initialize kernel header
	//
	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = TraceGenerator::WarpSynchronousTraceFormat;
	_entry.path = "";
	_entry.header = "";
	_entry.program = "";
	_entry.gridDim = kernel.gridDim();
	_entry.blockDim = kernel.blockDim();
		std::string name = kernel.name;

	// only look for complete uniformity
#if UNIFORM_CONTROL_FLOW_ONLY	
	warpSizes.clear();
	warpSizes.push_back(_entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z);
#endif
	
		
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

	// obtain control flow graph
	controlFlowGraph = emuKernel.cfg();
	branchTargetsToBlock = emuKernel.branchTargetsToBlock;
	for (std::map< int, std::string >::const_iterator it = branchTargetsToBlock.begin(); 
		it != branchTargetsToBlock.end(); ++it) {
		blockToBranchTarget[it->second] = it->first;
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

	report("WarpSynchronousGenerator::finish()");

	// always update database and emit results as JSON
	outputSynchronousStatistics();

	if (TraceConfiguration::Singleton.warpSynchronous.emitHotPaths) {
		// emit DOT files
		for (std::vector<int>::const_iterator ws_it = warpSizes.begin();
			ws_it != warpSizes.end(); ++ws_it) {
			int warpSize = *ws_it;
			report("  outputting hot paths - ws: " << warpSize);
			outputHotPaths(warpSize);
		}
	}
}

void trace::WarpSynchronousGenerator::outputSynchronousStatistics() {

	// update database
	_entry.updateDatabase(database);

	std::ofstream traceLog(_entry.header.c_str());

	//
	// serialize results
	//
	traceLog << "{\n";
	traceLog << "\t\"kernel\": \"" << _entry.name << "\",\n";
	traceLog << "\t\"module\": \"" << _entry.module << "\",\n";
	traceLog << "\t\"threads\": " 
		<< _entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z << ",\n";
	traceLog << "\t\"gridDim\": [" << _entry.gridDim.x << ", " << _entry.gridDim.y << ", " 
		<< _entry.gridDim.z << "],\n";
	traceLog << "\t\"blockDim\": [" << _entry.blockDim.x << ", " << _entry.blockDim.y << ", " 
		<< _entry.blockDim.z << "],\n";
	traceLog << "\t\"counters\":\n[\n";
	for (std::map< int, SynchronousInstructionCounter >::iterator 
		counter_it = warpCounters.begin();
		counter_it != warpCounters.end(); ) {
		traceLog << "\t{\n\t\"warpSize\": " << counter_it->first << ",\n";
		write(traceLog, counter_it->second);
		++counter_it;
		traceLog << "\t}" << (counter_it != warpCounters.end() ? "," : "") << "\n";
	}
	traceLog << "]\n}\n\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*
			class DotFormatter : public ir::ControlFlowGraph::BasicBlock::DotFormatter {
			public:
	
				const WarpSynchronousGenerator *traceGenerator;

				static std::string colorToString(unsigned int color);
			public:
				std::string toString(const ir::ControlFlowGraph::BasicBlock *block);
				std::string toString(const ir::ControlFlowGraph::Edge *edge);
			};
// trace::WarpSynchronousGenerator::DotFormatter::
*/

std::string trace::WarpSynchronousGenerator::DotFormatter::colorToString(unsigned int color) {

	unsigned short a = ((color >> 24) & 0x0ff);
	unsigned short r = ((color >> 16) & 0x0ff);
	unsigned short g = ((color >> 8) & 0x0ff);
	unsigned short b = ((color) & 0x0ff);
	
	return colorToString(r, g, b, a);
}

std::string trace::WarpSynchronousGenerator::DotFormatter::colorToString(
	unsigned int r, unsigned int g, unsigned int b, unsigned int a) {
	std::stringstream ss;

	ss << "#";
	ss << std::setfill('0') << std::setw(2) << std::hex << (r & 0x0ff);
	ss << std::setfill('0') << std::setw(2) << std::hex << (g & 0x0ff);
	ss << std::setfill('0') << std::setw(2) << std::hex << (b & 0x0ff);
//	ss << std::setfill('0') << std::setw(2) << std::hex << (a & 0x0ff);
	
	return ss.str();
}

std::string trace::WarpSynchronousGenerator::DotFormatter::toString(
	const ir::ControlFlowGraph::BasicBlock *block) {
	std::stringstream ss;

	std::string label = block->label();
	if (blockCounter.find(label) == blockCounter.end()) {
		ss << "[shape=record,label=\"" << 
			hydrazine::toGraphVizParsableLabel(block->label()) << "\"] // no block counter";
		return ss.str();
	}

	size_t events = blockCounter[block->label()].events, 
		synchronous = blockCounter[block->label()].synchronous;
	float t = 0.0f;
	double activity = (events ? (double)synchronous / (double)events : 0);

	/*
	// log-scale color intensity based on number of times block has been reached by a warp
	if (events) {
		t = log((float)(events)) / (float)log((float)(maxEvents));
	}
	unsigned int r = (unsigned int)(t * 255.0);
	unsigned int g = 0, b = 0;
	*/
	if (events) {
		t = (float)activity;
		if (t < 0.95) { t = 0.0f; }
	}
	unsigned int r = (unsigned int)(t * 255.0);
	unsigned int g = 0, b = 0;
	
	ss << "[";
	ss << "fillcolor=\"" << colorToString(r,g,b) << "\",style=filled,";
	ss << "shape=record,label=\"{" << hydrazine::toGraphVizParsableLabel(block->label()) 
		<< " | events: " << events << " | synchronous: " << synchronous << " | activity: " 
		<< activity << "}\"";
	if (t < 0.5) {
		ss << ",fontcolor=\"#aaaaaa\"";
	}
	ss << "]";
	return ss.str();
}

std::string trace::WarpSynchronousGenerator::DotFormatter::toString(
	const ir::ControlFlowGraph::BasicBlock::Edge *edge) {
	std::stringstream out;

	if (edge->type == ir::ControlFlowGraph::BasicBlock::Edge::Dummy) {
		out << "[style=dotted]";
	}
	else {
		// color it blue if the edge is entirely uniform or not
		if (counterEdges.find(edge) != counterEdges.end()) {
			if (counterEdges[edge].synchronous == counterEdges[edge].events) {
				out << "[color=blue,style=bold]";
			}
		}
	}

	return out.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief emits DOT files for each kernel with blocks colored by hot path for a given warp size
*/
void trace::WarpSynchronousGenerator::outputHotPaths(int warpSize) {
	const SynchronousInstructionCounter & counter = warpCounters[warpSize];

	DotFormatter formatter;
	formatter.warpSize = warpSize;
	formatter.traceGenerator = this;

	std::map< int, TargetCounter >::const_iterator target_it;
	
	formatter.maxEvents = 0;
	for (target_it = counter.counterTargets.begin(); target_it != counter.counterTargets.end(); 
		++target_it) {
		//blockColors[branchTargetsToBlock[target_it->first]] = 0;
		if (formatter.maxEvents < target_it->second.events) {
			formatter.maxEvents = target_it->second.events;
		}
		if ( (!formatter.minEvents && target_it->second.events) || (target_it->second.events && 
			target_it->second.events < formatter.minEvents)) {
			formatter.minEvents = target_it->second.events;
		}
	}
	if (formatter.maxEvents) {
		for (target_it = counter.counterTargets.begin(); target_it != counter.counterTargets.end(); 
			++target_it) {
			//blockColors[branchTargetsToBlock[target_it->first]] = color;
			formatter.blockCounter[ branchTargetsToBlock[target_it->first] ] = target_it->second;
		}
	}

	std::stringstream ss;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path = boost::filesystem::system_complete( path );
	ss << path.string() << "/" << _entry.program << "_" << _entry.name << "_" 
		<< _counter << "_ws" << warpSize << "_hotpath.dot";
	
	std::string filename = ss.str();

	report(" outputHotPaths(ws: " << warpSize << ", filename = " << filename << ")");

	std::ofstream cfgFile(filename.c_str());
	cfgFile << "/*\n";
	cfgFile << "     kernel: " << " kernel-name " << "\n";
	cfgFile << "  warp size: " << warpSize << "\n";
	cfgFile << "*/\n";

	controlFlowGraph->write(cfgFile, formatter);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

