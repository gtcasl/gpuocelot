/*! \file   GlobalValueNumberingPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Tuesday July 10, 2012
	\brief  The header file for the GlobalValueNumberingPass class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/transforms/interface/Pass.h>

namespace transforms
{

/*! \brief Perform global value numbering on a PTX kernel */
class GlobalValueNumberingPass : public KernelPass
{
public:
	/*! \brief Create the pass, create dependencies */
	GlobalValueNumberingPass();

public:
	/*! \brief Initialize the pass using a specific module */
	void initialize(const ir::Module& m);
	/*! \brief Run the pass on a specific kernel in the module */
	void runOnKernel(ir::IRKernel& k);		
	/*! \brief Finalize the pass */
	void finalize();


};

}

