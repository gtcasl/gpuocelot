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
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <traces/interface/ControlFlowVisualizer.h>

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

unsigned int trace::ControlFlowVisualizer::_counter = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////

class ControlFlowVisualizerFormatter:
	public ir::ControlFlowGraph::BasicBlock::DotFormatter {
public:

	ControlFlowVisualizerFormatter(trace::ControlFlowVisualizer * gen,
		bool _all): generator(gen), allInstructions(_all) {

	}
	
	/*!
	
	*/
	virtual std::string entryLabel(const ir::ControlFlowGraph::BasicBlock *block) {
		std::stringstream out;
		out << "[shape=record,style=\"bold,filled\",fillcolor=\"#4444cc\",";
		out << "label=";
		out << "\"{ KERNEL: " << hydrazine::toGraphVizParsableLabel(generator->kernel->name);
				
		out << "}\"]";
		return out.str();	
	}
	
	/*!
		\brief prints string representation of a block
	*/
	virtual std::string toString(const ir::ControlFlowGraph::BasicBlock *block) {
		std::stringstream out;

		out << "[";
		out << "style=filled,";
		out << "shape=record,label=\"{";

		std::pair<int,int> blockRange = generator->kernel->getBlockRange(block->label());
		
		out << hydrazine::toGraphVizParsableLabel(block->label());
		out << " | PCs: [" << blockRange.first << " ,  " << blockRange.second << "] ";
		for (int i = blockRange.first; i <= blockRange.second; i++) {
			const ir::PTXInstruction & instr = generator->kernel->instructions.at(i);
			if (instr.opcode == ir::PTXInstruction::Bra) {
				out << " | " << hydrazine::toGraphVizParsableLabel(instr.toString()) << "\\l";
				if (!instr.uni) {
					out << " | ipdom PC: " << instr.reconvergeInstruction << " , block " 
						<< generator->kernel->getInstructionBlock(instr.reconvergeInstruction) << " ";
				}
			}
			else if (instr.opcode == ir::PTXInstruction::Reconverge) {
				out << " | reconverge\\l";
			}
			else if (allInstructions) {
				out << " | " << hydrazine::toGraphVizParsableLabel(instr.toString()) << "\\l";
			}
		}
		
		out << "}\"";
		out << "]";
		
		return out.str();
	}
	
public:

	trace::ControlFlowVisualizer *generator;
	
	bool allInstructions;
};

//////////////////////////////////////////////////////////////////////////////////////////////////


trace::ControlFlowVisualizer::ControlFlowVisualizer(): allInstructions(false) {

}

trace::ControlFlowVisualizer::~ControlFlowVisualizer() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void trace::ControlFlowVisualizer::initialize(const executive::ExecutableKernel &kernel) {

	const executive::EmulatedKernel & emuKernel = 
		static_cast<const executive::EmulatedKernel &>(kernel);

	report("initialize('" << kernel.name << "')");

	//
	// initialize kernel header
	//
	{
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
		stream << _entry.format << "_" << trace::ControlFlowVisualizer::_counter++;

		boost::filesystem::path path( database );
		path = path.parent_path();
		path /= _entry.program + "_" + name + "_" + stream.str() + ".json";
		path = boost::filesystem::system_complete( path );
	
		_entry.header = path.string();
	}
	
	this->kernel = (& emuKernel);
	
	{
		ControlFlowVisualizerFormatter formatter(this, allInstructions);
	
		std::stringstream ss;
	
		boost::filesystem::path path( database );
		path = path.parent_path();
		path = boost::filesystem::system_complete( path );
		ss << path.string() << "/" << _entry.program << "_" << _entry.name << "_" 
			<< _counter << "_cfg.dot";

		std::string filename = ss.str();
		
		report("  writing to '" << filename << "'");

		ir::ControlFlowGraph *controlFlowGraph = const_cast<ir::ControlFlowGraph*>(this->kernel->cfg());
		std::ofstream cfgFile(filename.c_str());
		cfgFile << "/*\n";
		cfgFile << "     kernel: " << " kernel-name " << "\n";
		cfgFile << "*/\n";

		controlFlowGraph->write(cfgFile, formatter);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief aggregates statistics and emits kernel results
void trace::ControlFlowVisualizer::finish() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void trace::ControlFlowVisualizer::event(const trace::TraceEvent &event) {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

