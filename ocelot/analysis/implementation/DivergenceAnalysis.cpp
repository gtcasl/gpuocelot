/*! \file DivergenceAnalysis.h
	\date Jun 1, 2010
	\author Diogo Sampaio <dnsampaio@gmail.com>
	\brief The source file for the DivergenceAnalysis class
*/

#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/ir/interface/PostdominatorTree.h>
#include <assert.h>

namespace analysis
{

void DivergenceAnalysis::_analyzeDataFlow()
{
	DataflowGraph &nonConstGraph = *_kernel->dfg();
	DataflowGraph::const_iterator block = nonConstGraph.begin();
	DataflowGraph::const_iterator endBlock = nonConstGraph.end();

	/* 1) Analyze the data flow adding divergence sources */
	for (; block != endBlock; ++block) {
		DataflowGraph::PhiInstructionVector::const_iterator phiInstruction = block->phis().begin();
		DataflowGraph::PhiInstructionVector::const_iterator endPhiInstruction = block->phis().end();
                /* Go over the phi functions and add their dependences to the
                 * dependence graph. */
		for (; phiInstruction != endPhiInstruction; phiInstruction++) {
			for (DataflowGraph::RegisterVector::const_iterator si = phiInstruction->s.begin(); si != phiInstruction->s.end(); ++si) {
				_divergGraph.insertEdge(si->id, phiInstruction->d.id);
				si->type;
			}
		}

		DataflowGraph::InstructionVector::const_iterator ii = block->instructions().begin();
		DataflowGraph::InstructionVector::const_iterator iiEnd = block->instructions().end();
		for (; ii != iiEnd; ++ii) {

			ir::PTXInstruction *ptxInstruction = NULL;
			bool atom = false;

			set<const ir::PTXOperand*> divergenceSources;

			/* First we populate divergenceSources with all the
			 * source operands that might diverge. */
			if (typeid(ir::PTXInstruction) == typeid(*(ii->i))) {
				ptxInstruction = static_cast<ir::PTXInstruction*> (ii->i);

				if (ptxInstruction->a.addressMode == ir::PTXOperand::Special) {
					if( (ptxInstruction->a.special == ir::PTXOperand::tid)
						|| (ptxInstruction->a.special == ir::PTXOperand::laneId))
						divergenceSources.insert(&ptxInstruction->a);
				}

				if (ptxInstruction->b.addressMode == ir::PTXOperand::Special) {
					if( (ptxInstruction->b.special == ir::PTXOperand::tid)
						|| (ptxInstruction->b.special == ir::PTXOperand::laneId))
						divergenceSources.insert(&ptxInstruction->b);
				}

				if (ptxInstruction->c.addressMode == ir::PTXOperand::Special) {
					if( (ptxInstruction->c.special == ir::PTXOperand::tid)
						|| (ptxInstruction->c.special == ir::PTXOperand::laneId))
						divergenceSources.insert(&ptxInstruction->c);
				}

				if(ptxInstruction->opcode == ir::PTXInstruction::Opcode::Atom){
					atom = true;
				}
			}

			/* Second, we link the source operands to the
			 * destination operands, and check if the destination
			 * can diverge. This will only happen in case the
			 * instruction is atomic. */
			DataflowGraph::RegisterPointerVector::const_iterator destinyReg = ii->d.begin();
			DataflowGraph::RegisterPointerVector::const_iterator destinyEndReg = ii->d.end();

			for (; destinyReg != destinyEndReg; destinyReg++) {
				if (divergenceSources.size() != 0) {
					set<const ir::PTXOperand*>::iterator divergenceSource = divergenceSources.begin();
					set<const ir::PTXOperand*>::iterator divergenceSourceEnd = divergenceSources.end();

					for (; divergenceSource != divergenceSourceEnd; divergenceSource++) {
						_divergGraph.insertEdge(*divergenceSource, *destinyReg->pointer);
					}
				}

				DataflowGraph::RegisterPointerVector::const_iterator sourceReg = ii->s.begin();
				DataflowGraph::RegisterPointerVector::const_iterator sourceRegEnd = ii->s.end();

				for (; sourceReg != sourceRegEnd; sourceReg++) {
					_divergGraph.insertEdge(*sourceReg->pointer, *destinyReg->pointer);
				}

				/*NOT-TO DO: see if you can make this test local. Not more than this
				 * If there is no instruction with more than one destiny register, it's possible */
				if(atom){
					_divergGraph.setAsDiv(*destinyReg->pointer);
				}
			}
		}
	}
	/* 2) Computes the divergence propagation */
	_divergGraph.computeDivergence();
}

/*! \brief  Does control flow analysis to detect new divergent variables.
 * 1) Obtain information of all possible divergent branch instructions on the kernel
 * 2) Obtain all branch instructions that depend on a divergent predicate
 * 3) For each divergent branch
 * 3.1) Compute the controlflow dependency
 * 3.2) Search the postdominator block for new divergent variables
 * 3.3) If new divergent variables were found
 * 3.3.1) Re-compute the divergence spread by the new divergence/dataflow graph
 * 3.3.2) Search for new divergent branch instructions
 */
void DivergenceAnalysis::_analyzeControlFlow()
{
	/* Set of possible diverging branches */
	std::set<BranchInfo> branches;

	/* Create a list of branches that can be divergent, that is, they are not  bra.uni and have a predicate */
	DataflowGraph::const_iterator block = _kernel->dfg()->begin();
	DataflowGraph::const_iterator endBlock = _kernel->dfg()->end();

	/* Post-dominator tree */
	ir::PostdominatorTree dtree(_kernel->cfg());

	for (; block != endBlock; ++block) {
		ir::PTXInstruction *ptxInstruction = NULL;

		if (block->instructions().size() > 0) {
			/* Branch instructions can only be the last instruction of a basic block */
			DataflowGraph::Instruction lastInstruction = *(--block->instructions().end());

			if (typeid(ir::PTXInstruction) == typeid(*(lastInstruction.i))) {
				ptxInstruction = static_cast<ir::PTXInstruction*> (lastInstruction.i);

				if ((ptxInstruction->opcode == ir::PTXInstruction::Opcode::Bra) && (ptxInstruction->uni == false)
					&& (lastInstruction.s.size() != 0)) {
					ir::ControlFlowGraph::iterator CFGBlock = _kernel->cfg()->begin();
					ir::ControlFlowGraph::iterator CFGEndBlock = _kernel->cfg()->end();

					// Locate the same block of the DFG on the CFG. The block sequence on the DFC not necessarily are on the same position.
					for (; CFGBlock != CFGEndBlock; CFGBlock++) {
						if (CFGBlock->label == block->label()) {
							break;
						}
					}
					assert(CFGBlock != CFGEndBlock);
					assert(lastInstruction.s.size() == 1);
					unsigned int id = dtree.getPostDominator(CFGBlock)->id;
					DataflowGraph::const_iterator postDomBlock = _kernel->dfg()->begin();
					DataflowGraph::const_iterator endPostDomBlock = _kernel->dfg()->end();
					// Locate the same block of the DFG on the CFG. The block sequence on the DFC not necessarily are on the same position.
					for (; postDomBlock != endPostDomBlock; ++postDomBlock) {
						if (postDomBlock->id() == id) {
							break;
						}
					}
					if (postDomBlock != endPostDomBlock) {
						BranchInfo newBranch(&(*block), &(*postDomBlock), lastInstruction, _divergGraph);
						branches.insert(newBranch);
					}
				}
			}
		}
	}
	/* 2) Obtain all branch instructions that depend on a divergent predicate
	 * List of branches that are divergent, so their controlflow influence must be tested */
	std::set<BranchInfo> worklist;

	/* Populate the divergent branches set */
	std::set<BranchInfo>::iterator branch = branches.begin();
	std::set<BranchInfo>::iterator endBranch = branches.end();

	while (branch != endBranch) {
		if (isDivInstruction(branch->instruction()) ){
			std::set<BranchInfo>::iterator divBranch = branch--;
			worklist.insert(*divBranch);
			_divergentBranches.insert(*divBranch);
			branches.erase(divBranch);
			endBranch = branches.end();
		} else {
			_notDivergentBranches.insert(*branch);
		}
		branch++;
	}

	/*  3) For each divergent branch
	 * Test for divergence on the post-dominator block of every divergent branch instruction */
	while (worklist.size() > 0) {
		BranchInfo branchInfo = *worklist.begin();
		/* 3.1) Compute the controlflow dependency. populate is O(E) */
		branchInfo.populate();
		/* 3.2) Search the postdominator block for new divergent variables */
		DataflowGraph::PhiInstructionVector phis = branchInfo.postDominator()->phis();
		DataflowGraph::PhiInstructionVector::const_iterator phi = phis.begin();
		DataflowGraph::PhiInstructionVector::const_iterator endphi = phis.end();

		bool newDivergences = false;
		for (; phi != endphi; phi++) {
			DataflowGraph::RegisterVector::const_iterator source = phi->s.begin();
			DataflowGraph::RegisterVector::const_iterator endSource = phi->s.end();

			for (; source != endSource; source++) {
				if (branchInfo.isTainted(source->id)) {
					_addPredicate(*phi, branchInfo.predicate());
					newDivergences = true;
				}
			}
		}
		worklist.erase(branchInfo);
		/* 3.3) If new divergent variables were found*/
		if (newDivergences) {
			/* 3.3.1) Re-compute the divergence spread by the new divergence/dataflow graph */
			_divergGraph.computeDivergence();
			branch = branches.begin();
			/* 3.3.2) Search for new divergent branch instructions */
			while (branch != endBranch) {
				if (isDivInstruction(branch->instruction()) ){
					std::set<BranchInfo>::iterator divBranch = branch--;
					worklist.insert(*divBranch);
					_divergentBranches.insert(*divBranch);
					branches.erase(divBranch);
					endBranch = branches.end();
				} else {
					_notDivergentBranches.insert(*branch);
				}
				branch++;
			}
		}
	}
}

/*! \brief Add a predicate as a predecessor of a variable */
void DivergenceAnalysis::_addPredicate(const DataflowGraph::PhiInstruction &phi,
    const graph_utils::DivergenceGraph::node_type &predicate)
{
	_divergGraph.insertEdge(predicate, phi.d.id);
}

/*! \brief Constructor, already making the analysis of a input kernel */
DivergenceAnalysis::DivergenceAnalysis() : KernelPass( DataflowGraphAnalysis | StaticSingleAssignment, "DivergenceAnalysis" )
{
	_doCFGanalysis = true;
	_kernel = NULL;
}

/*! \brief Analyze the control and data flow graphs searching for divergent 
 *    variables and blocks
 *
 * 1) Makes data flow analysis that detects divergent variables and blocks 
 *    based on divergent sources, such as t.id, laneId
 * 2) Makes control flow analysis that detects new divergent variables based
 *    on the dependency of variables of variables created on divergent paths
 */
void DivergenceAnalysis::runOnKernel(ir::IRKernel &k)
{

	if (typeid(ir::PTXKernel) == typeid(k)) {
		_kernel = (ir::PTXKernel*) &k;
	}

	if (_kernel == NULL) {
		return;
	}

	if(!_kernel->dfg()->ssa())
		_kernel->dfg()->toSsa();

	_divergGraph.clear();
	_divergentBranches.clear();
	_notDivergentBranches.clear();

	graph_utils::DivergenceGraph::node_set predicates;
	/* 1) Makes data flow analysis that detects divergent variables and blocks
		based on divergent sources, such as t.id, laneId */
	_analyzeDataFlow();
	/* 2) Makes control flow analysis that detects new divergent variables
		based on the dependency of variables of variables created on divergent
		paths */
	if(_doCFGanalysis){
		_analyzeControlFlow();
	}
}

/*! \brief Tests if a block ends with a divergent branch instruction (isDivBranchInstr) */
bool DivergenceAnalysis::isDivBlock(DataflowGraph::const_iterator &block) const
{
	if (block->instructions().size() == 0) {
		return false;
	}
	return isDivBranch(--block->instructions().end());
}

/*! \brief Tests if a block ends with a divergent branch instruction (isDivBranchInstr) */
bool DivergenceAnalysis::isDivBlock(DataflowGraph::iterator &block) const
{
	if (block->instructions().size() == 0) {
		return false;
	}
	return isDivBranch(--block->instructions().end());
}

/*! \brief Tests if the a instruction is a branch instruction instruction and is possible a divergent instruction (isDivInstruction) */
bool DivergenceAnalysis::isDivBranch(const DataflowGraph::InstructionVector::const_iterator &instruction) const
{
	return (isDivInstruction(*instruction) && isPossibleDivBranch(instruction));
}

/*!\brief Tests if a instruction is a branch instruction with possibility of divergence */
bool DivergenceAnalysis::isPossibleDivBranch(const DataflowGraph::InstructionVector::const_iterator &instruction) const
{
	if(typeid(ir::PTXInstruction) == typeid(*(instruction->i))) {
		const ir::PTXInstruction &ptxI = *(static_cast<ir::PTXInstruction *> (instruction->i));
		return ((ptxI.opcode == ir::PTXInstruction::Bra) && (!ptxI.uni));
	}
	return false;
}

/*! \brief Tests if any of the registers of a instruction is possible divergent */
bool DivergenceAnalysis::isDivInstruction(const DataflowGraph::Instruction &instruction) const
{
	bool isDivergent = false;
	DataflowGraph::RegisterPointerVector::const_iterator reg = instruction.d.begin();
	DataflowGraph::RegisterPointerVector::const_iterator endReg = instruction.d.end();

	for (; (!isDivergent) && (reg != endReg); reg++) {
		isDivergent |= _divergGraph.isDivNode(*reg->pointer);
	}

	if (isDivergent) {
		return true;
	}

	reg = instruction.s.begin();
	endReg = instruction.s.end();

	for (; (!isDivergent) && (reg != endReg); reg++) {
		isDivergent |= _divergGraph.isDivNode(*reg->pointer);
	}

	return isDivergent;
}

DivergenceAnalysis::branch_set &DivergenceAnalysis::getDivergentBranches()
{
	return _divergentBranches;
}

DivergenceAnalysis::branch_set &DivergenceAnalysis::getNonDivergentBranches()
{
	return _notDivergentBranches;
}

const graph_utils::DivergenceGraph&
	DivergenceAnalysis::getDivergenceGraph() const
{
	return _divergGraph;
}

const DataflowGraph* DivergenceAnalysis::getDFG() const
{
	return _kernel->dfg();
}

void DivergenceAnalysis::setControlFlowAnalysis(bool doControlFlowAnalysis)
{
	_doCFGanalysis = doControlFlowAnalysis;
}

}

namespace std 
{
bool operator<(const analysis::BranchInfo x, const analysis::BranchInfo y)
{
	return x.block()->id() < y.block()->id();
}

bool operator<=(const analysis::BranchInfo x, const analysis::BranchInfo y)
{
	return x.block()->id() <= y.block()->id();
}

bool operator>(const analysis::BranchInfo x, const analysis::BranchInfo y)
{
	return x.block()->id() > y.block()->id();
}

bool operator>=(const analysis::BranchInfo x, const analysis::BranchInfo y)
{
	return x.block()->id() >= y.block()->id();
}
}
