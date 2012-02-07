/*! \file   AnalyzePTXPass.h
	\author Gregory Diamos <gdiamos@nvidia.com>
	\date   Monday February 6, 2012
	\brief  The header file for the AnalyzePTXPass
	
*/

#pragma once

// Ocelot Includes
#include <ocelot/transforms/interface/Pass.h>

// Forward Declarations
namespace ir { class PTXKernel; }

namespace transforms
{

/*! \brief An immutable pass that generates information from a PTX kernel */
class AnalyzePTXPass : public ImmutableKernelPass
{
public:
	AnalyzePTXPass();

public:
	void initialize(const ir::Module& m);
	void runOnKernel(const ir::IRKernel& k);
	void finalize();

private:
	void _analyzeILP(const ir::PTXKernel& ptx);
	void _analyzeRegisterAlignment(const ir::PTXKernel& kernel);
};

}


