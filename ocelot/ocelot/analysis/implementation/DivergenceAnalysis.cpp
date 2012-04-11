/*! \file DivergenceAnalysis.h
	\date Jun 1, 2010
	\author Diogo Sampaio <dnsampaio@gmail.com>
	\brief The source file for the DivergenceAnalysis class
*/

// Ocelot Includes
#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/analysis/interface/PostdominatorTree.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

// Standard Library Includes
#include <cassert>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{

bool DivergenceAnalysis::_isOperandAnArgument( const ir::PTXOperand& operand ) {
	if (operand.addressMode != ir::PTXOperand::Address) {
		return false;
	}
	
	return _kernel->getParameter(operand.identifier) != 0;
}

bool DivergenceAnalysis::_doesOperandUseLocalMemory(
	const ir::PTXOperand& operand ) {
	
	if (operand.addressMode != ir::PTXOperand::Address) {
		return false;
	}
	
	if (_kernel->locals.count(operand.identifier) != 0) {
		return true;
	}
	
	const ir::Global* global = _kernel->module->getGlobal(operand.identifier);
	
	if (global == 0) {
		return false;
	}
	
	return global->space() == ir::PTXInstruction::Local;
}

void DivergenceAnalysis::_analyzeDataFlow()
{
	Analysis* dfg = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(dfg != 0);

	DataflowGraph &nonConstGraph = static_cast<DataflowGraph&>(*dfg);
	DataflowGraph::const_iterator block = nonConstGraph.begin();
	DataflowGraph::const_iterator endBlock = nonConstGraph.end();

	/* 1) Analyze the data flow adding divergence sources */
	for (; block != endBlock; ++block) {
		DataflowGraph::PhiInstructionVector::const_iterator
			phiInstruction = block->phis().begin();
		DataflowGraph::PhiInstructionVector::const_iterator
			endPhiInstruction = block->phis().end();
        /* Go over the phi functions and add their dependences to the
         * dependence graph. */
		for (; phiInstruction != endPhiInstruction; phiInstruction++) {
			for (DataflowGraph::RegisterVector::const_iterator
				si = phiInstruction->s.begin();
				si != phiInstruction->s.end(); ++si) {
				_divergGraph.insertEdge(si->id, phiInstruction->d.id);
			}
		}

		DataflowGraph::InstructionVector::const_iterator
			ii = block->instructions().begin();
		DataflowGraph::InstructionVector::const_iterator
			iiEnd = block->instructions().end();
		for (; ii != iiEnd; ++ii) {

			ir::PTXInstruction *ptxInstruction = NULL;
			bool atom = false;
			bool functionStackArgument = false;
			bool localMemoryOperand = false;
			bool isCall = false;

			std::set<const ir::PTXOperand*> divergenceSources;

			/* First we populate divergenceSources with all the
			 * source operands that might diverge.
			 */
			if (typeid(ir::PTXInstruction) == typeid(*(ii->i))) {
				ptxInstruction = static_cast<ir::PTXInstruction*> (ii->i);
				if (ptxInstruction->a.addressMode == ir::PTXOperand::Special) {
					if( (ptxInstruction->a.special == ir::PTXOperand::tid &&
						ptxInstruction->a.vIndex == ir::PTXOperand::ix)
						|| (ptxInstruction->a.special
						== ir::PTXOperand::laneId))
						divergenceSources.insert(&ptxInstruction->a);
				}

				if (ptxInstruction->b.addressMode == ir::PTXOperand::Special) {
					if( (ptxInstruction->c.special == ir::PTXOperand::tid &&
						ptxInstruction->c.vIndex == ir::PTXOperand::ix)
						|| (ptxInstruction->b.special
						== ir::PTXOperand::laneId))
						divergenceSources.insert(&ptxInstruction->b);
				}

				if (ptxInstruction->c.addressMode == ir::PTXOperand::Special) {
					if( (ptxInstruction->c.special == ir::PTXOperand::tid &&
						ptxInstruction->c.vIndex == ir::PTXOperand::ix)
						|| (ptxInstruction->c.special
						== ir::PTXOperand::laneId))
						divergenceSources.insert(&ptxInstruction->c);
				}

				if (ptxInstruction->opcode == ir::PTXInstruction::Atom){
					atom = true;
				}
				
				if (ptxInstruction->mayHaveAddressableOperand()) {
					if (_doesOperandUseLocalMemory(ptxInstruction->a)) {
						localMemoryOperand = true;
					}
				}
				
				if (ptxInstruction->opcode == ir::PTXInstruction::Call){
					isCall = true;
				}
			}

			/* Second, if this is a function call, we populate divergenceSources
			 * with all the source operands that might diverge in a call.
			 */
			if (_kernel->function()) {
				if (typeid(ir::PTXInstruction) == typeid(*(ii->i))) {
					ptxInstruction = static_cast<ir::PTXInstruction*> (ii->i);
				
					if (ptxInstruction->mayHaveAddressableOperand()) {
						if (_isOperandAnArgument(ptxInstruction->a)) {
							functionStackArgument = true;
							report(" operand '" << ptxInstruction->a.toString()
								<< "' is a function call argument.");
						}
					}
				}
			}
						
			/* Third, we link the source operands to the
			 * destination operands, and check if the destination
			 * can diverge. This will only happen in case the
			 * instruction is atomic. */
			DataflowGraph::RegisterPointerVector::const_iterator
				destinationReg = ii->d.begin();
			DataflowGraph::RegisterPointerVector::const_iterator
				destinationEndReg = ii->d.end();

			for (; destinationReg != destinationEndReg; destinationReg++) {
				if (divergenceSources.size() != 0) {
					std::set<const ir::PTXOperand*>::iterator
						divergenceSource = divergenceSources.begin();
					std::set<const ir::PTXOperand*>::iterator
						divergenceSourceEnd = divergenceSources.end();

					for (; divergenceSource != divergenceSourceEnd;
						divergenceSource++) {
						_divergGraph.insertEdge(*divergenceSource,
							*destinationReg->pointer);
					}
				}

				DataflowGraph::RegisterPointerVector::const_iterator
					sourceReg = ii->s.begin();
				DataflowGraph::RegisterPointerVector::const_iterator
					sourceRegEnd = ii->s.end();

				for (; sourceReg != sourceRegEnd; sourceReg++) {
					_divergGraph.insertEdge(*sourceReg->pointer,
						*destinationReg->pointer);
				}

				if(atom || functionStackArgument ||
					localMemoryOperand || isCall){
					
					report(" destination register '" << *destinationReg->pointer
						<< "' is a divergence source.");
					_divergGraph.insertNode(*destinationReg->pointer);
					_divergGraph.setAsDiv(*destinationReg->pointer);
				}
			}
		}
	}
	/* 2) Computes the divergence propagation */
	_divergGraph.computeDivergence();
}

/*! \brief  Does control flow analysis to detect new divergent variables.
 * 1) Obtain information of all possible divergent branches on the kernel
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

	Analysis* dfgAnalysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(dfgAnalysis != 0);

	DataflowGraph &dfg = static_cast<DataflowGraph&>(*dfgAnalysis);

	/* Create a list of branches that can be divergent, that is,
		they are not  bra.uni and have a predicate */
	DataflowGraph::iterator block = dfg.begin();
	DataflowGraph::iterator endBlock = dfg.end();

	/* Post-dominator tree */
	PostdominatorTree *dtree;
	dtree = (PostdominatorTree*) (getAnalysis(Type::PostDominatorTreeAnalysis));

	for (; block != endBlock; ++block) {
		ir::PTXInstruction *ptxInstruction = NULL;

		if (block->instructions().size() > 0) {
			/* Branch instructions can only be the last
			instruction of a basic block */
			DataflowGraph::Instruction lastInstruction =
			*(--block->instructions().end());

			if (typeid(ir::PTXInstruction) == typeid(*(lastInstruction.i))) {
				ptxInstruction =
					static_cast<ir::PTXInstruction*>(lastInstruction.i);

				if ((ptxInstruction->opcode == ir::PTXInstruction::Bra)
					&& (ptxInstruction->uni == false)
					&& (lastInstruction.s.size() != 0)) {
					
					assert(lastInstruction.s.size() == 1);
					DataflowGraph::iterator postDomBlock =
						dfg.getCFGtoDFGMap()[
							dtree->getPostDominator(block->block())];
					if (postDomBlock != dfg.end()) {
						BranchInfo newBranch(&(*block), &(*postDomBlock), 
							lastInstruction, _divergGraph);
						branches.insert(newBranch);
					}
				}
			}
		}
	}
	/* 2) Obtain all branch instructions that depend on a divergent predicate
	* List of branches that are divergent, so their controlflow
	influence must be tested */
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
			branch = branches.begin();
			continue;
		} else {
			_notDivergentBranches.insert(*branch);
		}
		branch++;
	}

	/*  3) For each divergent branch
	 * Test for divergence on the post-dominator block of every
	 	divergent branch instruction */
	while (worklist.size() > 0) {
		BranchInfo branchInfo = *worklist.begin();
		/* 3.1) Compute the controlflow dependency. populate is O(E) */
		branchInfo.populate();
		/* 3.2) Search the postdominator block for new divergent variables */
		DataflowGraph::PhiInstructionVector
			phis = branchInfo.postDominator()->phis();
		DataflowGraph::PhiInstructionVector::const_iterator
			phi = phis.begin();
		DataflowGraph::PhiInstructionVector::const_iterator
			endphi = phis.end();

		bool newDivergences = false;
		for (; phi != endphi; phi++) {
			DataflowGraph::RegisterVector::const_iterator
				source = phi->s.begin();
			DataflowGraph::RegisterVector::const_iterator
				endSource = phi->s.end();

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
			/* 3.3.1) Re-compute the divergence spread by the
				new divergence/dataflow graph */
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
					branch = branches.begin();
					continue;
				} else {
					_notDivergentBranches.insert(*branch);
				}
				branch++;
			}
		}
	}
	
	/* 4) mark all blocks that are post dominators of the entry point as 
	      convergent.  
	*/
	report(" Marking non-divergent blocks.");
	block = dfg.begin();
	for (; block != endBlock; ++block) {
		if(dtree->postDominates(block->block(),
			_kernel->cfg()->get_entry_block())) {

			report("  " << block->label() << " post-dominates the entry point.");
			_notDivergentBlocks.insert(block);
		}
	}
	
	/* 4.1) mark all blocks with barriers as convergent.  
	*/
	block = dfg.begin();
	for (; block != endBlock; ++block) {
		ir::PTXInstruction *ptxInstruction = NULL;

		DataflowGraph::InstructionVector::const_iterator
			ii = block->instructions().begin();
		DataflowGraph::InstructionVector::const_iterator
			iiEnd = block->instructions().end();
		for (; ii != iiEnd; ++ii) {
			if (typeid(ir::PTXInstruction) == typeid(*(ii->i))) {
				ptxInstruction = static_cast<ir::PTXInstruction*> (ii->i);
				
				if (ptxInstruction->opcode == ir::PTXInstruction::Bar) {
					report("  " << block->label() << " includes a barrier.");
					_notDivergentBlocks.insert(block);
					break;
				}
			}
		}
	}
	
	/* 4.2.1) mark all blocks with only convergent
	          predecessors/successors as convergent.  
	*/
	
	bool changed = true;
	
	while(changed) {
		changed = false;
		
		block = dfg.begin();
		for (; block != endBlock; ++block) {		
		
			if (!isEntryDiv(block)) continue;
		
			bool allPredecessorsConvergent = true;
		
			for (analysis::DataflowGraph::BlockPointerSet::iterator
				predecessor = block->predecessors().begin();
				predecessor != block->predecessors().end(); ++predecessor) {
			
				if (isDivBlock(*predecessor)) {
					allPredecessorsConvergent = false;
					break;
				}
			
				// skip self loops
				if(*predecessor == block) continue;
			
				if (isEntryDiv(*predecessor)) {
					allPredecessorsConvergent = false;
					break;
				}
			}
		
			if (allPredecessorsConvergent) {
				changed = true;
				report("  " << block->label()
					<< " has only convergent predecessors.");
			
				_notDivergentBlocks.insert(block);
			
				continue;
			}
		}
	
		/* 4.2.2) Mark blocks contained in one-sided divergent
			hammocks as convergent. */
		if (_includeConditionalConvergence) {
			block = dfg.begin();
			for (; block != endBlock; ++block) {
				if (isEntryDiv(block))  continue;
				if (!isDivBlock(block)) continue;
			
				report("  examining " << block->label()
						<< ", it is a source of divergence.");
				
				// find the ipdom
				DataflowGraph::iterator postDomBlock =
					dfg.getCFGtoDFGMap()[dtree->getPostDominator(block->block())];
			
				if (isEntryDiv(postDomBlock)) {
					changed = true;
				
					report("   " << postDomBlock->label()
						<< " post-dominates a convergent block.");
				
					_notDivergentBlocks.insert(postDomBlock);
				}
			
				unsigned int targetsOtherThanIPDOM = 0;
			
				for (analysis::DataflowGraph::BlockPointerSet::iterator
					successor = block->targets().begin();
					successor != block->targets().end(); ++successor) {
					if (*successor != postDomBlock) ++targetsOtherThanIPDOM;
				}
			
				if (block->fallthrough() != endBlock) {
					if (block->fallthrough() != postDomBlock) {
						++targetsOtherThanIPDOM;
					}
				}
			
				if (targetsOtherThanIPDOM < 2) {
					for (analysis::DataflowGraph::BlockPointerSet::iterator
						successor = block->targets().begin();
						successor != block->targets().end(); ++successor) {
						if (*successor != postDomBlock) {
							if (isEntryDiv(*successor)) {
								changed = true;
				
								report("   " << (*successor)->label()
									<< " is part of a one-sided "
									<< "divergent hammock.");
						
								_notDivergentBlocks.insert(*successor);
							}
						}
					}
			
					if (block->fallthrough() != endBlock) {
						if (block->fallthrough() != postDomBlock) {
							if (isEntryDiv(block->fallthrough())) {
								changed = true;
				
								report("   " << block->fallthrough()->label()
									<< " is part of a one-sided "
									<< "divergent hammock.");
							
								_notDivergentBlocks.insert(block->fallthrough());
							}
						}
					}
				}
				else {
					report("   " << targetsOtherThanIPDOM
						<< " divergent paths originate here, skipping.");
				}
			}
		}
	}
}

/*! \brief Add a predicate as a predecessor of a variable */
void DivergenceAnalysis::_addPredicate(const DataflowGraph::PhiInstruction &phi,
    const DivergenceGraph::node_type &predicate)
{
	_divergGraph.insertEdge(predicate, phi.d.id);
}

/*! \brief Constructor, already making the analysis of a input kernel */
DivergenceAnalysis::DivergenceAnalysis()
: KernelAnalysis( Analysis::DivergenceAnalysis, "DivergenceAnalysis",
	Analysis::DataflowGraphAnalysis | Analysis::StaticSingleAssignment |
	Analysis::PostDominatorTreeAnalysis), _doCFGanalysis(true),
	_includeConditionalConvergence(false)
{
}

/*! \brief Analyze the control and data flow graphs searching for divergent 
 *    variables and blocks
 *
 * 1) Makes data flow analysis that detects divergent variables and blocks 
 *    based on divergent sources, such as t.id, laneId
 * 2) Makes control flow analysis that detects new divergent variables based
 *    on the dependency of variables of variables created on divergent paths
 */
void DivergenceAnalysis::analyze(ir::IRKernel &k)
{
	Analysis* dfgAnalysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(dfgAnalysis != 0);

	DataflowGraph &dfg = static_cast<DataflowGraph&>(*dfgAnalysis);

	assert(dfg.ssa());

	_divergGraph.clear();
	_divergentBranches.clear();
	_notDivergentBranches.clear();
	_notDivergentBlocks.clear();
	_kernel = &k;

	DivergenceGraph::node_set predicates;
	/* 1) Makes data flow analysis that detects divergent variables and blocks
		based on divergent sources, such as t.id, laneId */
	_analyzeDataFlow();
	/* 2) Makes control flow analysis that detects new divergent variables
		based on the dependency of variables of variables created on divergent
		paths */
	_analyzeControlFlow();
}

/*! \brief Tests if a block ends with a divergent branch
	instruction (isDivBranchInstr) */
bool DivergenceAnalysis::isDivBlock(
	const DataflowGraph::const_iterator &block) const
{
	if (block->instructions().size() == 0) {
		return false;
	}
	return isDivBranch(--block->instructions().end());
}

/*! \brief Tests if a block ends with a divergent branch
	instruction (isDivBranchInstr) */
bool DivergenceAnalysis::isDivBlock(const DataflowGraph::iterator &block) const
{
	if (block->instructions().size() == 0) {
		return false;
	}
	return isDivBranch(--block->instructions().end());
}

/*!\brief Tests if all threads enter the block in a convergent state */
bool DivergenceAnalysis::isEntryDiv(
	const DataflowGraph::iterator &block ) const {
	return _notDivergentBlocks.count(block) == 0;
}
		

/*! \brief Tests if the a instruction is a branch instruction
	instruction and is possible a divergent instruction (isDivInstruction) */
bool DivergenceAnalysis::isDivBranch(
	const DataflowGraph::InstructionVector::const_iterator &instruction) const
{
	return (isDivInstruction(*instruction) && isPossibleDivBranch(instruction));
}

/*!\brief Tests if a instruction is a branch instruction
	with possibility of divergence */
bool DivergenceAnalysis::isPossibleDivBranch(
	const DataflowGraph::InstructionVector::const_iterator &instruction) const
{
	if(typeid(ir::PTXInstruction) == typeid(*(instruction->i))) {
		const ir::PTXInstruction &ptxI =
			*(static_cast<ir::PTXInstruction *> (instruction->i));
		return ((ptxI.opcode == ir::PTXInstruction::Bra) && (!ptxI.uni));
	}
	return false;
}

/*! \brief Tests if any of the registers of a instruction
	is possible divergent */
bool DivergenceAnalysis::isDivInstruction(
	const DataflowGraph::Instruction &instruction) const
{
	bool isDivergent = false;
	DataflowGraph::RegisterPointerVector::const_iterator
		reg = instruction.d.begin();
	DataflowGraph::RegisterPointerVector::const_iterator
		endReg = instruction.d.end();

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

const DivergenceGraph& DivergenceAnalysis::getDivergenceGraph() const
{
	return _divergGraph;
}

const DataflowGraph* DivergenceAnalysis::getDFG() const
{
	const Analysis* dfgAnalysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(dfgAnalysis != 0);

	return static_cast<const DataflowGraph*>(dfgAnalysis);
}

void DivergenceAnalysis::setControlFlowAnalysis(bool doControlFlowAnalysis)
{
	_doCFGanalysis = doControlFlowAnalysis;
}

void DivergenceAnalysis::setConditionalConvergence(bool doIt)
{
	_includeConditionalConvergence = doIt;
}

}
