/*! \file ILKernel.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The header file for the ILKernel class.
 */

#ifndef IL_KERNEL_H_INCLUDED
#define IL_KERNEL_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/ILStatement.h>

namespace translator
{
	class PTXToILTranslator;
}

namespace ir
{
	/*! \brief A class containing a complete representation of an IL kernel */
	class ILKernel : public Kernel
	{
		friend class translator::PTXToILTranslator;
		public:
			/*! \brief A vector of IL Statements */
			typedef std::deque< ILStatement > ILStatementVector;

			/*! \brief Write this kernel to a parseable string */
			void write(std::ostream& stream) const;

			/*! \brief Default constructor */
			ILKernel();
			/*! \brief Constructor from a base class */
			ILKernel(const Kernel &k);

		private:
			ILStatementVector _statements;
	};
}

#endif

