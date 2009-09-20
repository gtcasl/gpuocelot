/*! \file RemoveBarrierPass.h
	\date Tuesday September 15, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the RemoveBarrierPass class
*/

#ifndef REMOVE_BARRIER_PASS_H_INCLUDED
#define REMOVE_BARRIER_PASS_H_INCLUDED

#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace ir
{
	class PTXKernel;
}

namespace analysis
{

	/*! \brief A class for a pass that removes all barriers from a PTX kernel
	
		This implementation leaves the barriers in as place holders, but
		splits the basic block containing them into two.  The first block
		contains all of the code before the barrier, spill instructions to
		a stack in local memory, the barrier, and a branch to the program exit.
		A local variable is allocated on the stack to indicate the program
		entry point.
		
		The program entry point is augmented to include a conditinal branch to
		the second block of each split barrier depending on the program entry 
		point variable.  The second block is augmented with code to load the 
		live variables from the local memory stack.	
	*/
	class RemoveBarrierPass : public KernelPass
	{
		private:
			ir::PTXKernel* _kernel;
			unsigned int _reentryPoint;
			unsigned int _spillBytes;
			bool _barriers;
			
		private:
			DataflowGraph::RegisterId _tempRegister( );
			void _addSpillCode( DataflowGraph::iterator block, 
				const DataflowGraph::Block::RegisterSet& alive );
			void _addRestoreCode( DataflowGraph::iterator block, 
				const DataflowGraph::Block::RegisterSet& alive );
			void _addEntryPoint( DataflowGraph::iterator block );
			void _removeBarrier( DataflowGraph::iterator block, 
				unsigned int instruction );
			void _addLocalVariables();
			void _runOnBlock( DataflowGraph::iterator block );
		
		public:
			RemoveBarrierPass();
			
		public:
			void initialize( const ir::Module& m );
			void runOnKernel( ir::Kernel& k );		
			void finalize( );

		public:
			/*! \brief Does this kernel contain at least one barrier */
			bool barriers() const;
			/*! \brrief What is the name of the barrier resume point */
			std::string resume() const;

	};
}

#endif

