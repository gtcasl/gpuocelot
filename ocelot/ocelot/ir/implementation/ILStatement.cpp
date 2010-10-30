/*! \file ILStatement.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The implementation file for the IL Statement class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ILStatement.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

namespace ir
{
	ILStatement::ILStatement(Type type) : instruction(0), type(type)
	{
	}

	ILStatement::ILStatement(const ILInstruction &i) 
		: instruction(0), type(Instruction)
	{
		instruction = static_cast<ILInstruction*>(i.clone());
	}

	std::string ILStatement::toString() const
	{
		switch(type)
		{
			case Instruction: return instruction->toString();
			case ConstantBufferDcl:
			{
				std::stringstream stream;

				stream << "dcl_cb ";
				stream << operands[0].toString();

				return stream.str();
			}
			case LiteralDcl:
			{
				std::stringstream stream;

				stream << "dcl_literal ";
				stream << operands[0].toString() << ", ";
				stream << operands[1].toString() << ", ";
				stream << operands[1].toString() << ", ";
				stream << operands[1].toString() << ", ";
				stream << operands[1].toString();

				return stream.str();
			}
			case OtherDeclarations: return \
							  "il_cs_2_0\n"
							  "dcl_max_thread_per_group 512\n"
							  "dcl_raw_uav_id(0)\n"
							  "dcl_arena_uav_id(8)\n"
							  "dcl_lds_id(1) 32768";
			default:
			{
				assertM(false, "Statement type "
						<< type
						<< " not supported");
				break;
			}
		}
	}
}

