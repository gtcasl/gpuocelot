/*! \file   HyperblockAnalysis.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday October 8, 2011
	\brief  The header file for the HyperblockAnalysis class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/analysis/interface/ProgramStructureGraph.h>

namespace analysis
{

class HyperblockAnalysis : public ProgramStructureGraph
{
public:
	HyperblockAnalysis(unsigned int blockSize = 100);

public:
	/*! \brief Build from a kernel CFG */
	void analyze(ir::IRKernel& kernel);

private:
	ir::ControlFlowGraph* _cfg;
	unsigned int          _blockSize;
};

}

