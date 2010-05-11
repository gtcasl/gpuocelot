/*! \file PTXToILTranslator.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 19, 2010
 *  \brief The implementation file for the PTX to IL Translator class.
 */

// Ocelot includes
#include <ocelot/translator/interface/PTXToILTranslator.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace translator
{
	std::string PTXToILTranslator::translate(const ir::Module *module)
	{
		/*
		for (ir::Module::StatementVector::const_iterator
				stmt = module->statements.begin() ;
				stmt != module->statements.end() ; stmt++) {
			if (stmt->directive == ir::PTXStatement::Instr)
				_translate(stmt->instruction);
		}
		*/

		// Use a fixed ILKernel for now (no PTX-to-IL translation yet)
		std::string ILKernel = 
			"il_cs_2_0\n"
			"dcl_max_thread_per_group 256\n"
			"dcl_raw_uav_id(0)\n"
			"dcl_cb cb0[1]\n"
			"dcl_cb cb1[2]\n"							//.param .u64 A
														//.param .u64 B
			"dcl_literal l0, 4, 4, 4, 4\n"
			"dcl_literal l1, 2, 2, 2, 2\n"
			"mov r0, vAbsTidFlat.x\n"					//cvt.s32.u16	%r1, %tid.x;
			"mov r1, r0\n"								//cvt.u64.s32 	%rd1, %r1;
			"imul r2, r1, l0\n"							//mul.lo.u64 	%rd2, %rd1, 4;
			"mov r3, cb1[0]\n"							//ld.param.u64 	%rd3, [A];
			"iadd r4, r3, r2\n"							//add.u64 	    %rd4, %rd3, %rd2;
			"uav_raw_load_id(0) r5, r4\n"				//ld.global.s32	%r2, [%rd4+0];
			"imul r6, r5, l1\n"							//mul.lo.s32 	%r3, %r2, 2;
			"mov r7, cb1[1]\n"							//ld.param.u64 	%rd5, [B];
			"iadd r8, r7, r2\n"							//add.u64    	%rd6, %rd5, %rd2;
			"uav_raw_store_id(0) mem.xyzw, r8, r6\n"	//st.global.s32	[%rd6+0], %r3;
			"end\n";									//exit;

		return ILKernel;
	}

	void PTXToILTranslator::_translate(const ir::PTXInstruction &i)
	{
		report("Translating: " << i.toString());
		switch(i.opcode) 
		{
			case ir::PTXInstruction::Cvt: _translateCvt(i); break;
			default:
			{
				assertM(false, "Opcode "
						<< ir::PTXInstruction::toString(i.opcode)
						<< " not supported");
				break;
			}
		}
	}

	void PTXToILTranslator::_translateCvt(const ir::PTXInstruction &i)
	{
		ir::ILMov mov;

		_add(mov);
	}

	void PTXToILTranslator::_add(const ir::ILInstruction &i)
	{
		report("Added instruction '" << i.toString() << "'");
		_ilKernel->_statements.push_back(ir::ILStatement(i));
	}
}
