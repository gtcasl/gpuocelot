/*!
	\file PTXKernel.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 15, 2009

	\brief definition for PTXKernel class
*/

#ifndef IR_PTXKERNEL_H_INCLUDED
#define IR_PTXKERNEL_H_INCLUDED

#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/Kernel.h>

namespace ir {

	class PTXKernel: public Kernel {
	public:
		PTXKernel();
		virtual ~PTXKernel();

	};

}

#endif

