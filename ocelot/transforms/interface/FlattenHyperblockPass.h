/*! \file   FlattenHyperblockPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday October 8, 2011
	\brief  The header file for the FlattenHyperblockPass class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/transforms/interface/Pass.h>

namespace transforms
{

/*! \brief Merge all basic blocks in a hyperblock together using predication */
class FlattenHyperblockPass : public KernelPass
{
public:
	FlattenHyperblockPass();

public:
	/*! \brief Initialize the pass using a specific module */
	void initialize(const ir::Module& m);
	/*! \brief Run the pass on a specific kernel in the module */
	void runOnKernel(ir::IRKernel& k);
	/*! \brief Finalize the pass */
	void finalize();

};

}


	
