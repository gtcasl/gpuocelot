/*! \file   DefaultProgramStructure.h
	\author Gregory Diamos <gdiamos@nvidia.com>
	\date   Monday August 29, 2011
	\brief  The header file for the DefaultProgramStructure class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/analysis/interface/ProgramStructureGraph.h>

namespace analysis
{

/*! \brief Implements a naive mapping over existing basic blocks */
class DefaultProgramStructure : public ProgramStructureGraph
{
public:
	DefaultProgramStructure();

public:
	/*! \brief Build from a kernel CFG */
	void analyze(ir::IRKernel& k);

};

}


