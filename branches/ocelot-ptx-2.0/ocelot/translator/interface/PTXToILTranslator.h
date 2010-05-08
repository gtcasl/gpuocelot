/*! \file PTXToILTranslator.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 19, 2010
 *  \brief The header file for the PTX to IL Translator class.
 */

#ifndef PTX_TO_IL_TRANSLATOR_H_INCLUDED
#define PTX_TO_IL_TRANSLATOR_H_INCLUDED

//C++ standard library includes
#include <string>

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

		private:
			ir::ILKernel *_ilKernel;

			void _translate(const ir::PTXInstruction &i);
			void _translateCvt(const ir::PTXInstruction &i);

			void _add(const ir::ILInstruction &i);
	};
}

#endif
