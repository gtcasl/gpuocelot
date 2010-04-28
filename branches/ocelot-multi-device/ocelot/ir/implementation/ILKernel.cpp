/*! \file ILKernel.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The implementation file for the ILKernel class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ILKernel.h>

namespace ir
{
	ILKernel::ILKernel()
	{
		ISA = Instruction::CAL;
	}
}


