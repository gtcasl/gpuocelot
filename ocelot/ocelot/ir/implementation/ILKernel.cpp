/*! \file ILKernel.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The implementation file for the ILKernel class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ILKernel.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

// C++ includes
#include <iostream>

namespace ir
{
	ILKernel::ILKernel()
	{
		ISA = Instruction::CAL;
	}

	void ILKernel::write(std::ostream& stream) const
	{
		for(ILStatementVector::const_iterator
				statement = _statements.begin();
				statement != _statements.end(); statement++)
		{
			stream << statement->toString() << std::endl;
		}
	}
}


