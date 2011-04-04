/*! \file IntraThreadCoalescingPass.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date March 24, 2010
 *  \brief The header file for the IntraThreadCoalescingPass class.
 */

#ifndef ANALYSIS_INTRATHREADCOALESCINGPASS_H_INCLUDED
#define ANALYSIS_INTRATHREADCOALESCINGPASS_H_INCLUDED

#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>

namespace analysis
{
	class IntraThreadCoalescingPass : public KernelPass
	{
		public:
			void initialize(const ir::Module& m);
			void runOnKernel(ir::Kernel& k);
			void finalize();

		private:
			void _runOnBlock(DataflowGraph::iterator block);

			ir::PTXKernel* _kernel;
	};
}

#endif
