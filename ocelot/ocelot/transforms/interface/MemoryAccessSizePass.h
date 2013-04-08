#ifndef MEMORY_ACCESS_SIZE_H_
#define MEMORY_ACCESS_SIZE_H_

#include "ocelot/ir/interface/IRKernel.h"
#include "ocelot/ir/interface/PTXKernel.h"
#include "ocelot/ir/interface/PTXOperand.h"
#include "ocelot/transforms/interface/Pass.h"
namespace transforms {
	/*! \brief This pass prints the instructions in the Dataflow Graph */
	class MemoryAccessSizePass: public KernelPass {

	private:
		std::list<void *> _readPtrs; //memory read size storing pointer
		std::list<void *> _writePtrs; //memory write size storing pointer

	private:
		//add read size instruction
		ir::PTXInstruction _readSizeInstruction(ir::PTXOperand::DataType dataType,
			ir::PTXOperand::RegisterType addReg);
	
	public:
		MemoryAccessSizePass(std::list<void * > &readPtrs, std::list<void *> &writePtrs);
	    virtual ~MemoryAccessSizePass() {};
		virtual void initialize( const ir::Module& m ){};
		virtual void runOnKernel( ir::IRKernel& k );
		virtual void finalize(){};
	};

}

#endif
