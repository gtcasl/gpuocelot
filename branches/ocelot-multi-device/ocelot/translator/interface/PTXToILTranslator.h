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

namespace translator
{
	/*! \brief A translator from PTX to IL */
	class PTXToILTranslator
	{
		public:
			/*! \brief Translate a module from PTX to IL */
			std::string translate(const ir::Module *module);

			/*! \brief Default constructor */
			PTXToILTranslator();

		private:
			typedef std::map<std::string, std::string> RegisterMap;
			typedef std::map<long long unsigned int, std::string> LiteralMap;
			typedef std::map<std::string, unsigned int> ConstBufMap;

			ir::ILKernel *_ilKernel;
			RegisterMap registerMap;
			LiteralMap literalMap;
			ConstBufMap constbufMap;

			unsigned int literals;
			unsigned int registers;

			void _addKernelPrefix();

			void _translate(const ir::PTXInstruction &i);
			ir::ILOperand _translate(const ir::PTXOperand &o);
			ir::ILOperand::SpecialRegister _translate(
					const ir::PTXOperand::SpecialRegister &s);

			void _translateAdd(const ir::PTXInstruction &i);
			void _translateCvt(const ir::PTXInstruction &i);
			void _translateExit(const ir::PTXInstruction &i);
			void _translateLd(const ir::PTXInstruction &i);
			void _translateMul(const ir::PTXInstruction &i);
			void _translateSt(const ir::PTXInstruction &i);

			std::string _translateRegister(const std::string &ident);
			std::string _translateLiteral(long long unsigned int l);
			std::string _translateConstantBuffer(const std::string &ident);
			void _add(const ir::ILInstruction &i);
	};
}

#endif
