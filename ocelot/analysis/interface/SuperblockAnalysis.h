/*! \file   SuperblockAnalysis.h
	\author Gregory Diamos <gdiamos@nvidia.com>
	\date   Friday August 12, 2011
	\brief  The header file for the superblock analysis class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/analysis/interface/ProgramStructureGraph.h>

namespace analysis
{

/*! \brief Implements superblock analysis as described in [1].

	Core Idea: Form single-entry, multiple-exit, blocks that are simple
		to optimize and schedule.
	
	[1] - Richard E. Hank,  Scott A. Mahlke,  Roger A. Bringmann, 
		John C. Gyllenhaal,  Wen-mei W. Hwu. Superblock formation using static
		program analysis.
*/
class SuperblockAnalysis : public ProgramStructureGraph
{
public:
	SuperblockAnalysis(unsigned int blockSize = 50);

public:
	/*! \brief Build from a kernel CFG */
	void analyze( ir::IRKernel& kernel );

private:
	ir::ControlFlowGraph* _cfg;
	unsigned int          _blockSize;
};

}


