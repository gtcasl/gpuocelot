/*! \file PTXToILTranslator.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 19, 2010
 *  \brief The header file for the PTX to IL Translator class.
 */

#ifndef PTX_TO_IL_TRANSLATOR_H_INCLUDED
#define PTX_TO_IL_TRANSLATOR_H_INCLUDED

//C++ standard library includes
#include <string>
#include <map>

//Ocelot includes
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/ILKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>

namespace translator
{
	/*! \brief A translator from PTX to IL */
	class PTXToILTranslator
	{
		public:
			/*! \brief Translate a module from PTX to IL */
			std::string translate(const ir::Module *module);

		private:
			typedef std::map<long long unsigned int, std::string> LiteralMap;

			ir::ILKernel *_ilKernel;
			LiteralMap literals;

			void _translateInstructions();

			void _translate(ir::ControlFlowGraph::BasicBlock *block);
			void _translate(const ir::PTXInstruction &i, 
					ir::ControlFlowGraph::BasicBlock *b);
			ir::ILOperand _translate(const ir::PTXOperand &o);
			std::string _translate(const ir::PTXOperand::RegisterType &reg);
			ir::ILOperand::SpecialRegister _translate(
					const ir::PTXOperand::SpecialRegister &s);

			void _translateAdd(const ir::PTXInstruction &i);
			void _translateBra(const ir::PTXInstruction &i, 
					ir::ControlFlowGraph::BasicBlock *b);
			void _translateCvt(const ir::PTXInstruction &i);
			void _translateExit(const ir::PTXInstruction &i);
			void _translateLd(const ir::PTXInstruction &i);
			void _translateMov(const ir::PTXInstruction &i);
			void _translateMul(const ir::PTXInstruction &i);
			void _translateSetP(const ir::PTXInstruction &i);
			void _translateSt(const ir::PTXInstruction &i);

			std::string _translateLiteral(long long unsigned int l);
			std::string _translateConstantBuffer(const std::string &ident);

			void _addKernelPrefix();

			void _add(const ir::ILInstruction &i);
	};
}

#endif
