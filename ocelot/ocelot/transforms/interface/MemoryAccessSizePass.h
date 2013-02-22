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
		void * _ptr; //store memory size

	private:
		//add read size instruction
		ir::PTXInstruction _readSizeInstruction(ir::PTXOperand::DataType dataType,
			ir::PTXOperand::RegisterType addReg);
	
	public:
		MemoryAccessSizePass(void * ptr);
	    virtual ~MemoryAccessSizePass() {};
		virtual void initialize( const ir::Module& m ){};
		virtual void runOnKernel( ir::IRKernel& k );
		virtual void finalize(){};
	};

}

#endif
