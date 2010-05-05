/*! \file ILStatement.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The header file for the IL Statement class.
 */

#ifndef IL_STATEMENT_H_INCLUDED
#define IL_STATEMENT_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/ILInstruction.h>

namespace ir
{
	class ILStatement
	{
		public:
			/*! \brief Construct a statement from an instruction */
			explicit ILStatement(const ILInstruction &i);
	};
}

#endif


