/*!
	\file ConvergenceGenerator.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief identifies warp-synchronous blocks
*/

// C++ includes
#include <iostream>
#include <fstream>

// Boost includes
#include <boost/filesystem.hpp>

// Ocelot includes
#include <traces/interface/ConvergenceGenerator.h>
#include <traces/interface/TraceConfiguration.h>
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

//////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int trace::ConvergenceGenerator::_counter = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::ConvergenceGenerator::Counter::Counter():
	hasSync(false),
	threads(0),
	dynInstructions(0),
	warpInstructions(0)
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////


trace::ConvergenceGenerator::ConvergenceGenerator() {

}

trace::ConvergenceGenerator::~ConvergenceGenerator() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void trace::ConvergenceGenerator::initialize(const executive::ExecutableKernel &kernel) {

	const executive::EmulatedKernel & emuKernel = 
		static_cast<const executive::EmulatedKernel &>(kernel);

	//
	// initialize kernel header
	//
	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = TraceGenerator::ConvergenceTraceFormat;
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
	stream << _entry.format << "_" << trace::ConvergenceGenerator::_counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= _entry.program + "_" + name + "_" + stream.str() + ".json";
	path = boost::filesystem::system_complete( path );
	
	_entry.header = path.string();
	
	this->kernel = (& emuKernel);
	analyzeKernel(emuKernel);
}

//! \brief visits each basic block and initializes a counter for each block
void trace::ConvergenceGenerator::analyzeKernel(const executive::EmulatedKernel &kernel) {
	ir::ControlFlowGraph *cfg = const_cast<ir::ControlFlowGraph *>(kernel.cfg());
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->executable_sequence();
	ir::ControlFlowGraph::BlockPointerVector::iterator bb_it;
	for (bb_it = blocks.begin(); bb_it != blocks.end(); ++bb_it) {
		Counter counter;
		counter.threads = _entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z;
		ir::ControlFlowGraph::BasicBlock::InstructionList::const_iterator inst_it =
			(*bb_it)->instructions.begin();
		for (; inst_it != (*bb_it)->instructions.end(); ++inst_it) {
			const ir::Instruction *inst = (*inst_it);
			if (inst && inst->ISA == ir::Instruction::PTX && 
				static_cast<const ir::PTXInstruction *>(inst)->opcode == ir::PTXInstruction::Bar) {
				counter.hasSync = true;
				break;
			}
		}
		counterMap[(*bb_it)->label()] = counter;
	}
	
	Counter counter;
	counter.threads = _entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z;
	counterMap["entry"] = counter;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream &out, const trace::ConvergenceGenerator::Counter &counter) {

	size_t ideal = (counter.warpInstructions * counter.threads);
	double activity = (ideal ? (double)counter.dynInstructions / (double)ideal : 0.0);
	out << " | dynamic instructions: " << counter.dynInstructions
		<< " | warp instructions: " << counter.warpInstructions 
		<< " | activity: " << activity;
		
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

class ConvergenceFormatter : public ir::ControlFlowGraph::BasicBlock::DotFormatter {
public:	
	ConvergenceFormatter(trace::ConvergenceGenerator * gen): generator(gen) {
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
		out << "\"{ ENTRY: " << hydrazine::toGraphVizParsableLabel(generator->kernel->name);
		
		if (generator->counterMap.find(block->label()) != generator->counterMap.end()) {
		
			const trace::ConvergenceGenerator::Counter & 
				counter = generator->counterMap[block->label()];
				
			size_t ideal = (counter.warpInstructions * counter.threads);
			double activity = (ideal ? (double)counter.dynInstructions / (double)ideal : 0.0);
			out << " | blocks: " << generator->_entry.gridDim.x * generator->_entry.gridDim.y * generator->_entry.gridDim.z;
			out << " | threads: " << counter.threads;
			out << " | aggregate dynamic instructions: " << counter.dynInstructions
				<< " | aggregate warp instructions: " << counter.warpInstructions 
				<< " | average activity: " << activity;
		}
		
		out << "}\"]";
		return out.str();	
	}
	
	/*!
		\brief prints string representation of 
	*/
	virtual std::string toString(const ir::ControlFlowGraph::BasicBlock *block) {
		std::stringstream out;

		bool convergent = false;
		bool sync = false;
		out << "[shape=record,";

		out << "label=";
		out << "\"{" << hydrazine::toGraphVizParsableLabel(block->label());
		
		if (generator->counterMap.find(block->label()) != generator->counterMap.end()) {
		
			const trace::ConvergenceGenerator::Counter & 
				counter = generator->counterMap[block->label()];
				
			if (blocksToPC.find(block->label()) != blocksToPC.end()) {
				out << " | near " << generator->kernel->location(blocksToPC[block->label()]);
			}	
			
			out << counter;
			
			if (counter.dynInstructions == counter.warpInstructions * counter.threads) {
				convergent = true;
				out << " | *** convergent *** ";
			}
			if (counter.hasSync) {
				sync = true;
				out << " | *** bar.sync *** ";
			}
		}
		
		out << "}\"";
		
		if (convergent && !sync) {
			out << ",style=\"filled\",fillcolor=\"#ff0000\"";
		}
		else if (sync && !convergent) {
			out << ",style=\"filled\",fillcolor=\"#0000ff\"";
		}
		else if (convergent && sync) {
			out << ",style=\"filled\",fillcolor=\"#ff00ff\"";
		}
		
		out << "]";

		return out.str();
	}
	
public:

	std::map< std::string, int > blocksToPC;
	
	trace::ConvergenceGenerator *generator;

};

//! \brief writes a DOT-format CFG to an output stream
void trace::ConvergenceGenerator::writeCFG() {

	ConvergenceFormatter formatter(this);
	
	std::stringstream ss;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path = boost::filesystem::system_complete( path );
	ss << path.string() << "/" << _entry.program << "_" << _entry.name << "." 
		<< _counter << ".convergence.dot";
	
	std::string filename = ss.str();
	
	ir::ControlFlowGraph *controlFlowGraph = const_cast<ir::ControlFlowGraph*>(kernel->cfg());
	std::ofstream cfgFile(filename.c_str());
	cfgFile << "/*\n";
	cfgFile << "     kernel: " << kernel->name << "\n";
	cfgFile << "*/\n";

	controlFlowGraph->write(cfgFile, formatter);
	cfgFile.close();	
	
	if (TraceConfiguration::Singleton.convergence.render) {
		std::stringstream ss;		
		ss << "dot -Tpdf -o " << path.string() << "/" << _entry.program << "_" << _entry.name << "." << _counter 
			<< ".convergence.pdf " << filename;
		if (system(ss.str().c_str()) != 0) {
			report("system(" << ss.str() << ") failed");
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief aggregates statistics and emits kernel results
void trace::ConvergenceGenerator::finish() {

	// aggregate entry statistics
	for (OperationCounterMap::const_iterator op_it = counterMap.begin();
		op_it != counterMap.end(); ++op_it) {
		
		if (op_it->first != "entry" && op_it->first != "exit") {
			counterMap["entry"] += op_it->second;
		}
	}
	
	boost::filesystem::path path( database );
	path = path.parent_path();
	path = boost::filesystem::system_complete( path );
		
	std::fstream resultFile(
		TraceConfiguration::Singleton.convergence.logfile.c_str(), 
		std::ios_base::out | std::ios_base::app);

	write(resultFile);
	
	if (TraceConfiguration::Singleton.convergence.dot) {
		writeCFG();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void trace::ConvergenceGenerator::event(const trace::TraceEvent &event) {
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
		
	op->second.dynInstructions += event.active.count();
	op->second.warpInstructions ++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void trace::ConvergenceGenerator::write(std::fstream &out) {
	// invocation #, kernel, blocks, threads, block-label, dyn-instructions, warp instructions, activity, convergent (0, 1), sync (0, 1)
	const char *delimiter = ",";
	
	size_t blockCount = _entry.gridDim.x * _entry.gridDim.y;
	size_t threadCount = _entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z;
	
	OperationCounterMap::const_iterator op = counterMap.begin();
	for (; op != counterMap.end(); ++op) {

	size_t ideal = (op->second.warpInstructions * op->second.threads);
	double activity = (ideal ? (double)op->second.dynInstructions / (double)ideal : 0.0);
		out 
			<< _counter << delimiter
			<< kernel->name << delimiter 
			<< blockCount << delimiter 
			<< threadCount << delimiter
			<< op->first << delimiter
			<< op->second.dynInstructions << delimiter
			<< op->second.warpInstructions << delimiter
			<< activity << delimiter
			<< (op->second.warpInstructions * threadCount == op->second.dynInstructions ? 1 : 0)
			<< (op->second.hasSync ? 1 : 0)
			<< std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

