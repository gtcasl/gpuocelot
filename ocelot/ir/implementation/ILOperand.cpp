/*! \file ILOperand.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 29, 2010
 *  \brief The implementation file for the IL Operand class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ILOperand.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

// Boost includes
#include <boost/lexical_cast.hpp>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace ir
{
	ILOperand::ILOperand()
		:
			swizzle_x(CompSel_Invalid),
			swizzle_y(CompSel_Invalid),
			swizzle_z(CompSel_Invalid),
			swizzle_w(CompSel_Invalid),
			negate_x(false),
			negate_y(false),
			negate_z(false),
			negate_w(false)
	{
	}

	std::string ILOperand::toString(ComponentSelect c) const
	{
		switch (c)
		{
			case CompSel_0:       return "0";
			case CompSel_1:       return "1";
			case CompSel_X:       return "x";
			case CompSel_Y:       return "y";
			case CompSel_Z:       return "z";
			case CompSel_W:       return "w";
			case CompSel_NoWrite: return "_";
			case CompSel_Invalid: return "";
			default: assertM(false, "Invalid component select " << c);
		}
	}

	std::string ILOperand::toStringRegister() const
	{
		std::string r(identifier);

		if (swizzle_x != CompSel_Invalid || swizzle_y != CompSel_Invalid ||
				swizzle_z != CompSel_Invalid || swizzle_w != CompSel_Invalid)
		{
			r += ".";
			r += toString(swizzle_x);
			r += toString(swizzle_y);
			r += toString(swizzle_z);
			r += toString(swizzle_w);
		}

		if (negate_x || negate_y || negate_z || negate_w)
		{
			r+= "_neg(";
			r+= negate_x ? "x" : "";
			r+= negate_y ? "y" : "";
			r+= negate_z ? "z" : "";
			r+= negate_w ? "w" : "";
			r+= ")";
		}

		return r;
	}

	std::string ILOperand::toString(RegType rt)
	{
		switch (rt)
		{
			case RegType_Temp: return "r"; break;
			default: assertM(false, "Invalid register type " << rt);
		}
	}

	std::string ILOperand::Dst_Mod::toString(ModDstComponent dc)
	{
		switch (dc)
		{
			case ModComp_NoWrite: return "_";
			case ModComp_0:       return "0";
			case ModComp_1:       return "1";
			default: assertM(false, "Invalid dest component select " << dc);
		}
	}

	std::string ILOperand::Dst_Mod::toString() const
	{
		return "." + 
			(component_x == ModComp_Write ? "x" : toString(component_x)) + 
			(component_y == ModComp_Write ? "y" : toString(component_y)) + 
			(component_z == ModComp_Write ? "z" : toString(component_z)) + 
			(component_w == ModComp_Write ? "w" : toString(component_w));
	}

	std::string ILOperand::Src_Mod::toString(ComponentSelect c)
	{
		switch (c)
		{
			case CompSel_X: return "x";
			case CompSel_Y: return "y";
			case CompSel_Z: return "z";
			case CompSel_W: return "w";
			case CompSel_0: return "0";
			case CompSel_1: return "1";
			default: assertM(false, "Invalid component select " << c);
		}
	}

	std::string ILOperand::Src_Mod::swizzleString() const
	{
		return toString(swizzle_x) + toString(swizzle_y) + toString(swizzle_z) +
			toString(swizzle_w);
	}

	std::string ILOperand::Src_Mod::negateString() const
	{
		return (negate_x || negate_y || negate_z || negate_w ? 
				std::string("_neg(") + 
				(negate_x ? "x" : "") +
				(negate_y ? "y" : "") +
				(negate_z ? "z" : "") +
				(negate_w ? "w" : "") +
				")" : "");
	}

	std::string ILOperand::Src_Mod::toString() const
	{
		return "." + swizzleString() + negateString();
	}

	std::string ILOperand::dstString() const
	{
		return toString(rtype) + boost::lexical_cast<std::string>(num) +
			(modifier_present ? dst_mod.toString() : "");
	}

	std::string ILOperand::srcString() const
	{
		return toString(rtype) + boost::lexical_cast<std::string>(num) +
			(modifier_present ? src_mod.toString() : "");
	}

	std::string ILOperand::toString() const
	{
		switch (addressMode)
		{
			case Register: return toStringRegister();
			case Immediate:
			{
				std::stringstream stream;
				switch (type)
				{
					case I32: stream << imm_int; break;
					case F32: 
					{
						union
						{
							float f;
							int i;
						} convert;
						
						convert.f = imm_float;
						stream << "0x" << std::hex << convert.i; 
						break;
					}
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

	ILOperand ILOperand::x() const
	{
		ILOperand o(*this);
		o.swizzle_x = CompSel_X;

		return o;
	}

	ILOperand ILOperand::y() const
	{
		ILOperand o(*this);
		o.swizzle_y = CompSel_Y;

		return o;
	}

	ILOperand ILOperand::z() const
	{
		ILOperand o(*this);
		o.swizzle_z = CompSel_Z;

		return o;
	}

	ILOperand ILOperand::w() const
	{
		ILOperand o(*this);
		o.swizzle_w = CompSel_W;

		return o;
	}

	ILOperand ILOperand::xy() const
	{
		ILOperand o(*this);
		o.swizzle_x = CompSel_X;
		o.swizzle_y = CompSel_Y;

		return o;
	}

	ILOperand ILOperand::xxxx() const
	{
		ILOperand o(*this);
		o.swizzle_x = CompSel_X;
		o.swizzle_y = CompSel_X;
		o.swizzle_z = CompSel_X;
		o.swizzle_w = CompSel_X;

		return o;
	}

	ILOperand ILOperand::x___() const
	{
		ILOperand o(*this);
		o.swizzle_x = CompSel_X;
		o.swizzle_y = CompSel_NoWrite;
		o.swizzle_z = CompSel_NoWrite;
		o.swizzle_w = CompSel_NoWrite;

		return o;
	}

	ILOperand ILOperand::_y__() const
	{
		ILOperand o(*this);
		o.swizzle_x = CompSel_NoWrite;
		o.swizzle_y = CompSel_Y;
		o.swizzle_z = CompSel_NoWrite;
		o.swizzle_w = CompSel_NoWrite;

		return o;
	}

	ILOperand ILOperand::__z_() const
	{
		ILOperand o(*this);
		o.swizzle_x = CompSel_NoWrite;
		o.swizzle_y = CompSel_NoWrite;
		o.swizzle_z = CompSel_Z;
		o.swizzle_w = CompSel_NoWrite;

		return o;
	}

	ILOperand ILOperand::___w() const
	{
		ILOperand o(*this);
		o.swizzle_x = CompSel_NoWrite;
		o.swizzle_y = CompSel_NoWrite;
		o.swizzle_z = CompSel_NoWrite;
		o.swizzle_w = CompSel_W;

		return o;
	}

	ILOperand ILOperand::neg() const
	{
		ILOperand o(*this);
		o.negate_x = true;
		o.negate_y = true;
		o.negate_z = true;
		o.negate_w = true;

		return o;
	}
}
