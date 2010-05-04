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
			case Declaration: return \
							  "il_cs_2_0\n"
							  "dcl_max_thread_per_group 256\n"
							  "dcl_raw_uav_id(0)\n"
							  "dcl_cb cb0[2]\n"
							  "dcl_literal l0, 4, 4, 4, 4\n"
							  "dcl_literal l1, 2, 2, 2, 2";
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

