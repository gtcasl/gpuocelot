/*! \file   ControlDependenceAnalysis.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Friday June 29, 2013
	\file   The header file for the ControlDependenceAnalysis class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/analysis/interface/Analysis.h>
#include <ocelot/analysis/interface/PTXInstructionDependenceGraph.h>

// Standard Library Includes
#include <unordered_map>

// Forward Declarations
namespace ir { class PTXInstruction; }

namespace analysis
{

/*! \brief Discover control dependences in the program */
class ControlDependenceAnalysis
: public KernelAnalysis, public PTXInstructionDependenceGraph
{
public:
	typedef ir::PTXInstruction   PTXInstruction;

public:
	ControlDependenceAnalysis();

public:
	void analyze(ir::IRKernel& kernel);
};

}


