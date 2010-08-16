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
			case Immediate:
			{
				std::stringstream stream;
				switch (type)
				{
					case I32: stream << imm_int; break;
					case F32: stream << imm_float; break;
					default: assertM(false, "Invalid data type");
				}
				return stream.str();	
			}
			case Literal: return identifier;
			case ConstantBuffer: return identifier;
			case Special: return toString(special);
			default:
			{
				assertM(false, "Address Mode " << addressMode 
						<< " not supported");
				break;
			}
		}
	}

	std::string ILOperand::toString(SpecialRegister sr) const
	{
		switch (sr)
		{
			case vTidInGrpX:     return "vTidInGrp.x";    break;
			case vTidInGrpY:     return "vTidInGrp.y";    break;
			case vTidInGrpZ:     return "vTidInGrp.z";    break;
			case vNTidInGrpX:    return "cb0[0].x";       break;
			case vNTidInGrpY:    return "cb0[0].y";       break;
			case vNTidInGrpZ:    return "cb0[0].z";       break;
			case vThreadGrpIdX:  return "vThreadGrpId.x"; break;
			case vThreadGrpIdY:  return "vThreadGrpId.y"; break;
			case vThreadGrpIdZ:  return "vThreadGrpId.z"; break;
			case vNThreadGrpIdX: return "cb0[1].x";       break;
			case vNThreadGrpIdY: return "cb0[1].y";       break;
			case vNThreadGrpIdZ: return "cb0[1].z";       break;
			default: break;
		}
		
		return "SpecialRegister_invalid";
	}
}
