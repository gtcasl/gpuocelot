/*! \file   ConvertPredicationToControlFlowPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday December 3, 2011
	\brief  The header file for the ConvertPredicationToControlFlowPass class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/transforms/interface/Pass.h>

namespace transforms
{

/*! \brief Convert chains of predicated instructions into hammocks */
class ConvertPredicationToControlFlowPass : public KernelPass
{
public:
	ConvertPredicationToControlFlowPass();

public:
	/*! \brief Initialize the pass using a specific module */
	void initialize(const ir::Module& m);
	/*! \brief Run the pass on a specific kernel in the module */
	void runOnKernel(ir::IRKernel& k);
	/*! \brief Finalize the pass */
	void finalize();

};

}


