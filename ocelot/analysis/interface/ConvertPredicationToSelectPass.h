/*! \file ConvertPredicationToSelectPass.h
	\date Friday September 25, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the ConvertPredicationToSelectPass class
*/

#ifndef CONVERT_PREDICATION_TO_SELECT_PASS_H_INCLUDED
#define CONVERT_PREDICATION_TO_SELECT_PASS_H_INCLUDED

#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace ir
{
	class PTXKernel;
}

namespace analysis
{

	/*! \brief A class for a pass that converts all predicate instructions
		to conditional select 
	
		This is necessary for converting predicated code into static single
		assignment form without creating phi nodes at all predicated 
		instructions
	*/
	class ConvertPredicationToSelectPass : public KernelPass
	{
		private:
			ir::PTXKernel* _kernel;
			
		private:
			DataflowGraph::RegisterId _tempRegister( );
			void _replacePredicate( DataflowGraph::iterator block, 
				unsigned int instruction );
			void _runOnBlock( DataflowGraph::iterator block );
		
		public:
			ConvertPredicationToSelectPass();
			
		public:
			void initialize( const ir::Module& m );
			void runOnKernel( ir::Kernel& k );		
			void finalize( );

	};
}

#endif

