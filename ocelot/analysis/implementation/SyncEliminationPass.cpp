/*! \file SyncEliminationPass.cpp
	\date Aug 30, 2010
	\author Diogo Sampaio <dnsampaio@gmail.com>
	\brief The source file for the SyncEliminationPass class
*/

#include <ocelot/analysis/interface/SyncEliminationPass.h>
#include <ocelot/analysis/interface/DivergenceAnalysis.h>

namespace analysis {

SyncEliminationPass::SyncEliminationPass()
	: KernelPass(DataflowGraphAnalysis
	| StaticSingleAssignment | DivergenceAnalysis, "SyncElimination")
{
}

/*! \brief The SyncEliminationPass converts all non divergent
	bra instructions into bra.uni */
void SyncEliminationPass::runOnKernel(ir::Kernel& k)
{
	const analysis::DivergenceAnalysis *divAnalysis = k.div_analy();

        // Ocelot uses guards to represent the first and last basic block of
        // each kernel. These special blocks hold no instruction; hence, we
        // do not need to go through them.
	DataflowGraph::iterator block = ++k.dfg()->begin();
	DataflowGraph::iterator blockEnd = --k.dfg()->end();

	for (; block != blockEnd; block++) {
		if (!divAnalysis->isDivBlock(block)) {
			DataflowGraph::Instruction inst = *(--block->_instructions.end());
			ir::PTXInstruction *ptxInst
				= static_cast<ir::PTXInstruction*> (inst.i);
			if (ptxInst->opcode == ir::PTXInstruction::Bra) {
				ptxInst->uni = true;
			}
		}
	}
}

}
