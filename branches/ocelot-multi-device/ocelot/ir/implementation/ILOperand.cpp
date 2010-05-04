/*! \file ILOperand.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 29, 2010
 *  \brief The implementation file for the IL Operand class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ILOperand.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace ir
{
	std::string ILOperand::toString() const
	{
		switch (addressMode)
		{
			case Register: return identifier;
			case Literal: return identifier;
			case ConstantBuffer: return identifier;
			case Special: return toString(special);
			default:
			{
				assertM(false, "Address Mode "
						<< addressMode 
						<< " not supported");
				break;
			}
		}
	}

	std::string ILOperand::toString(SpecialRegister sr) const
	{
		switch (sr)
		{
			case vAbsTidFlatX: return "vAbsTidFlat.x"; break;
			default: break;
		}
		
		return "SpecialRegister_invalid";
	}
}
