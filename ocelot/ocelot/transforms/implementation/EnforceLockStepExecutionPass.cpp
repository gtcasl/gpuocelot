/*! \file   EnforceLockStepExecutionPass.cpp
	\date   Wednesday April 18, 2012
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the  EnforceLockStepExecutionPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/EnforceLockStepExecutionPass.h>

#include <ocelot/analysis/interface/ThreadFrontierAnalysis.h>
#include <ocelot/analysis/interface/ConvergentRegionAnalysis.h>
#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/analysis/interface/DominatorTree.h>

#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace transforms
{

EnforceLockStepExecutionPass::EnforceLockStepExecutionPass()
: KernelPass(Analysis::ThreadFrontierAnalysis |
	Analysis::DataflowGraphAnalysis | Analysis::ConvergentRegionAnalysis |
	Analysis::DominatorTreeAnalysis | Analysis::DivergenceAnalysis,
	"EnforceLockStepExecutionPass")
{

}

void EnforceLockStepExecutionPass::initialize(const ir::Module& m)
{

}

void EnforceLockStepExecutionPass::runOnKernel(ir::IRKernel& k)
{
	report("Running Enforce-Lock-Step-Execution-Pass on kernel '"
		<< k.name << "'");
	
	// Predicate all instructions with their region variable
	_predicateInstructions(k);
	
	// assign a mask to the program entry point
	_assignMaskToEntryPoint(k);
	
	// assign condition variables to branch edges
	_assignConditionsToEdges(k);
	
	// Delete all branches
	_deleteAllBranches(k);
	
	// Initialize masks
	_initializeMasks(k);
	
	// Set merge points
	_setMergePoints(k);

	// Set branches to transfer control flow
	_setBranches(k);
	
	// Free data structures
	_reset();
}

void EnforceLockStepExecutionPass::finalize()
{
	
}

EnforceLockStepExecutionPass::StringVector
	EnforceLockStepExecutionPass::getDependentPasses() const
{
	return StringVector(1, "SimplifyControlFlowGraphPass");	
}

static ir::PTXInstruction* getBranch(ir::ControlFlowGraph::iterator block)
{
	for(auto i = block->instructions.rbegin();
		i != block->instructions.rend(); ++i)
	{
		auto ptx = static_cast<ir::PTXInstruction*>(*i);
		
		if(ptx->opcode == ir::PTXInstruction::Bra) return ptx;
	}
	
	return 0;
}

static ir::PTXInstruction* getComparison(ir::ControlFlowGraph::iterator block,
	ir::PTXInstruction* branch)
{
	for(auto i = block->instructions.rbegin();
		i != block->instructions.rend(); ++i)
	{
		auto ptx = static_cast<ir::PTXInstruction*>(*i);
		
		if(ptx->opcode != ir::PTXInstruction::SetP) continue;
		
		if((ptx->d.isRegister() && ptx->d.reg == branch->pg.reg) ||
			(ptx->pq.isRegister() && ptx->pq.reg == branch->pg.reg))
		{
			return ptx;
		}
	}
	
	return 0;
}

static ir::Instruction::RegisterType getTakenPredicate(
	analysis::DataflowGraph::iterator block, ir::PTXInstruction* branch)
{
	assert(branch->pg.condition != ir::PTXOperand::PT);
	assert(branch->pg.condition != ir::PTXOperand::nPT);
	
	bool fallthroughIsD = branch->pg.condition == ir::PTXOperand::Pred;
	
	ir::PTXInstruction* comparison = getComparison(block->block(), branch);
	
	if(fallthroughIsD)
	{
		return comparison->d.reg;
	}
	else
	{
		return comparison->pq.reg;
	}
}

static ir::Instruction::RegisterType getFallthroughPredicate(
	analysis::DataflowGraph::iterator block, ir::PTXInstruction* branch)
{
	assert(branch->pg.condition != ir::PTXOperand::PT);
	assert(branch->pg.condition != ir::PTXOperand::nPT);
	
	bool fallthroughIsD = branch->pg.condition == ir::PTXOperand::InvPred;
	
	ir::PTXInstruction* comparison = getComparison(block->block(), branch);
	
	if(fallthroughIsD)
	{
		return comparison->d.reg;
	}
	else
	{
		return comparison->pq.reg;
	}
}

static bool blockHasExitPoint(ir::IRKernel& k,
	ir::ControlFlowGraph::iterator block)
{
	for(auto successor = block->successors.begin();
		successor != block->successors.end(); ++successor)
	{
		if(k.cfg()->get_exit_block() == *successor) return true;
	}
	
	return false;
}

void EnforceLockStepExecutionPass::_assignMaskToEntryPoint(ir::IRKernel& k)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	auto div = static_cast<analysis::DivergenceAnalysis*>(
		getAnalysis(Analysis::DivergenceAnalysis));
	
	auto firstBlock = dfg->begin()->fallthrough();
	
	// skip convergent blocks
	if(!div->isEntryDiv(firstBlock))
	{
		report(" not assigned a mask to the program entry point "
			<< firstBlock->label() << " because it is convergent.");
		return;
	}
	
	report(" assigning a mask to the program entry point "
		<< firstBlock->label());
	
	// TODO: load this from the stack for device functions
	
	ir::PTXInstruction move(ir::PTXInstruction::Mov);

	move.type = ir::PTXOperand::pred;
	
	move.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, _getBlockVariable(firstBlock));
	move.a = ir::PTXOperand(1, ir::PTXOperand::pred);
	
	dfg->insert(firstBlock, move, 0);
	
	report("  " << move.toString());
}

void EnforceLockStepExecutionPass::_predicateInstructions(ir::IRKernel& k)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
			getAnalysis(Analysis::DataflowGraphAnalysis));
	auto div = static_cast<analysis::DivergenceAnalysis*>(
		getAnalysis(Analysis::DivergenceAnalysis));
	
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		if(block->block() == k.cfg()->get_entry_block()) continue;
		if(block->block() == k.cfg()->get_exit_block())  continue;
	
		Register blockVariable = _getBlockVariable(block);
	
		auto branch = getBranch(block->block());
		
		ir::PTXInstruction* comparison = 0;
		
		if(branch != 0)
		{
			if(branch->pg.condition != ir::PTXOperand::PT &&
				branch->pg.condition != ir::PTXOperand::nPT)
			{
				report("   finding comparison for branch: "
					<< branch->toString());
				
				comparison = getComparison(block->block(), branch);
				
				if(comparison == 0)
				{
					_addComparison(block, branch);
					
					comparison = getComparison(block->block(), branch);
				
					assert(comparison != 0);
				}
				else
				{
					comparison = _canonicalizeComparison(block, comparison);
				}
			}
		}
		
		// skip convergent blocks
		if(!div->isEntryDiv(block)) continue;
	
		report("  predicating instructions in block '"
			<< block->label() << "'");
		
		for(auto instruction = block->block()->instructions.begin();
			instruction != block->block()->instructions.end(); ++instruction)
		{
			auto ptx = static_cast<ir::PTXInstruction*>(*instruction);
			
			if(ptx == branch)     continue;
			if(ptx == comparison) continue;
			
			// TODO: handle instructions that have already been predicated
			assert(ptx->pg.condition == ir::PTXOperand::PT);
			
			ptx->pg.condition = ir::PTXOperand::Pred;
			ptx->pg.reg       = blockVariable;
		}
	}
}

void EnforceLockStepExecutionPass::_assignConditionsToEdges(ir::IRKernel& k)
{
	report(" generating masks for each edge");
	
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		// skip blocks with exit instructions
		if(blockHasExitPoint(k, block->block())) continue;
		
		ir::PTXInstruction* bra = getBranch(block->block());
		
		if(bra == 0)
		{
			assert(!block->block()->has_branch_edge());
			
			if(block->block()->has_fallthrough_edge())
			{
				_edgeVariables.insert(std::make_pair(
					block->block()->get_fallthrough_edge(),
					_getBlockVariable(block)));
			}
			
			continue;
		}
		
		report("  in block " << block->label());

		Register takenMask = 0;
		
		if(bra->pg.condition == ir::PTXOperand::PT)
		{
			takenMask = _getBlockVariable(block);
		}
		else
		{
			takenMask = getTakenPredicate(block, bra);
		}
		
		assert(block->block()->has_branch_edge());
		auto branchEdge = block->block()->get_branch_edge();
		
		_edgeVariables.insert(std::make_pair(branchEdge, takenMask));
		
		report("   creating mask for branch edge " << branchEdge->head->label()
			<< " -> " << branchEdge->tail->label());
		
		if(bra->pg.condition == ir::PTXOperand::PT) continue;

		Register fallthroughMask = getFallthroughPredicate(block, bra);
		
		assert(block->block()->has_fallthrough_edge());
		auto fallthroughEdge = block->block()->get_fallthrough_edge();
		
		_edgeVariables.insert(std::make_pair(
			fallthroughEdge, fallthroughMask));
	
		report("   creating mask for fallthrough edge "
			<< fallthroughEdge->head->label() << " -> "
			<< fallthroughEdge->tail->label());
	}
}

void EnforceLockStepExecutionPass::_deleteAllBranches(ir::IRKernel& k)
{
	report(" deleting all branches");
	
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		for(auto instruction = block->instructions().begin();
			instruction != block->instructions().end(); )
		{
			auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);
			
			if(ptx->opcode == ir::PTXInstruction::Bra)
			{
				report("  " << ptx->toString());
	
				instruction = dfg->erase(block, instruction);
			}
			else
			{
				++instruction;
			}
		}
	}
}

void EnforceLockStepExecutionPass::_initializeMasks(ir::IRKernel& k)
{
	typedef analysis::ThreadFrontierAnalysis::Priority Priority;
	typedef std::map<Priority, block_iterator,
		std::greater<Priority>> PriorityMap;
	typedef std::vector<block_iterator> BlockVector;
	typedef std::unordered_multimap<block_iterator, BlockVector> ReverseTFMap;

	// The immediate dominator of (the region and all blocks with the region in
	//  their TFs) initializes the mask for each block
	
	auto tfAnalysis = static_cast<analysis::ThreadFrontierAnalysis*>(
		getAnalysis(Analysis::ThreadFrontierAnalysis));
	
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));

	auto domTree = static_cast<analysis::DominatorTree*>(
		getAnalysis(Analysis::DominatorTreeAnalysis));

	auto cfgToDfgMap = dfg->getCFGtoDFGMap();

	report(" initializing masks");

	BlockMap     initializers;
	PriorityMap  priorities;
	ReverseTFMap frontiers;

	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		if(block->block() == k.cfg()->get_entry_block()) continue;
		if(block->block() == k.cfg()->get_exit_block())  continue;
		
		priorities.insert(std::make_pair(
			tfAnalysis->getPriority(block->block()), block));
		
		auto frontier = tfAnalysis->getThreadFrontier(block->block());
		
		for(auto frontierBlock = frontier.begin();
			frontierBlock != frontier.end(); ++frontierBlock)
		{
			auto dfgFrontierBlock = cfgToDfgMap.find(*frontierBlock);
			assert(dfgFrontierBlock != cfgToDfgMap.end());
		
			auto frontierList = frontiers.find(dfgFrontierBlock->second);
			if(frontierList == frontiers.end())
			{
				frontierList = frontiers.insert(std::make_pair(
					dfgFrontierBlock->second, BlockVector()));
			}
			
			frontierList->second.push_back(block);
		}
	}

	auto div = static_cast<analysis::DivergenceAnalysis*>(
		getAnalysis(Analysis::DivergenceAnalysis));
	
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		if(block->block() == k.cfg()->get_entry_block()) continue;
		if(block->block() == k.cfg()->get_exit_block())  continue;
		
		// skip convergent blocks
		if(!div->isEntryDiv(block)) continue;
		
		auto immediateDominator = domTree->getDominator(block->block());
		auto nearest = block->block();
	
		report("  computing TF dominator for block " << block->label()
			<< " with actual dominator " << immediateDominator->label());
		
		// get the common dominator of this block and all blocks with this
		//  block in their thread frontier
		auto frontier = frontiers.find(block);
		if(frontier != frontiers.end())
		{
			for(auto predecessor = frontier->second.begin();
				predecessor != frontier->second.end(); ++predecessor)
			{
				auto commonDominator = domTree->getCommonDominator(
					nearest, (*predecessor)->block());
				
				if(commonDominator != immediateDominator)
				{
					immediateDominator = commonDominator;
					nearest = (*predecessor)->block();
				}
				
				report("   in TF of " << (*predecessor)->label()
					<< ", common dominator is " << immediateDominator->label());
			}
		}
		
		report("   block " << block->label() << " is TF dominated by "
			<< immediateDominator->label() << ", zeroing mask");
		
		auto dfgDominator = cfgToDfgMap.find(immediateDominator);
		assert(dfgDominator != cfgToDfgMap.end());
		
		initializers.insert(std::make_pair(block, dfgDominator->second));
		
		if(immediateDominator == k.cfg()->get_entry_block()) continue;
	
		_zeroVariableBeforeExiting(dfgDominator->second, block);
	}

	report(" resetting masks on back edges");
	
	// if there is a back-edge with a range containing a block,
	// reset the variables for all blocks whose immediate dominator has a
	// priority less than the target of the back-edge
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		if(block->block() == k.cfg()->get_entry_block()) continue;
		if(block->block() == k.cfg()->get_exit_block())  continue;
		
		// skip convergent blocks
		if(!div->isEntryDiv(block)) continue;
		
		Priority blockPriority = tfAnalysis->getPriority(block->block());

		for(auto successor = block->successors().begin();
			successor != block->successors().end(); ++successor)
		{
			if((*successor)->block() == k.cfg()->get_entry_block()) continue;
			if((*successor)->block() == k.cfg()->get_exit_block())  continue;
			
			Priority successorPriority =
				tfAnalysis->getPriority((*successor)->block());
			
			// skip edges that go forward
			if(successorPriority < blockPriority) continue;
			
			auto begin = priorities.lower_bound(successorPriority);
			auto end   = priorities.upper_bound(blockPriority);
			
			report("  examing priority range (" << successorPriority
				<< ", " << blockPriority << ")");
			
			for(auto blockInRange = begin; blockInRange != end; ++blockInRange)
			{
				auto initializer = initializers.find(blockInRange->second);
				assert(initializer != initializers.end());
				
				auto initializerPriority = tfAnalysis->getPriority(
					initializer->second->block());
				
				// skip blocks that will be handled by their dominator	
				if(initializerPriority <= successorPriority &&
					(successorPriority != blockPriority)) continue;
				
				report("   block " << block->label() << " may trigger "
					<< blockInRange->second->label() << " (priority "
					<< blockInRange->first << "), zeroing mask");
		
				_zeroVariableBeforeExiting(block, blockInRange->second);
			}
		}
	}
}

void EnforceLockStepExecutionPass::_setMergePoints(ir::IRKernel& k)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	auto div = static_cast<analysis::DivergenceAnalysis*>(
		getAnalysis(Analysis::DivergenceAnalysis));
		
	report(" updating masks on region transitions");
	
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		if(block->block() == k.cfg()->get_entry_block()) continue;
		if(block->block() == k.cfg()->get_exit_block())  continue;
		
		report("  for block " << block->label());
		for(auto successor = block->successors().begin();
			successor != block->successors().end(); ++successor)
		{
			if((*successor)->block() == k.cfg()->get_entry_block()) continue;
			if((*successor)->block() == k.cfg()->get_exit_block())  continue;
			
			// if the predecessor was convergent, just set the successor
			if(!div->isEntryDiv(block))
			{
				report("   entering " << (*successor)->label()
					<< " directly" );
				_setVariableForSuccessor(block, (*successor));
			}
			else
			{
				report("   merging variable with " << (*successor)->label()
					<< " before entering" );
				_mergeVariablesBeforeEntering(block, (*successor));
			}
		}
	}
}

void EnforceLockStepExecutionPass::_setBranches(ir::IRKernel& k)
{
	auto tfAnalysis = static_cast<analysis::ThreadFrontierAnalysis*>(
		getAnalysis(Analysis::ThreadFrontierAnalysis));
	auto div = static_cast<analysis::DivergenceAnalysis*>(
		getAnalysis(Analysis::DivergenceAnalysis));
	
	typedef std::multimap<analysis::ThreadFrontierAnalysis::Priority,
		const_block_iterator,
		std::greater<analysis::ThreadFrontierAnalysis::Priority>> PriorityMap;
	typedef std::unordered_set<ir::ControlFlowGraph::const_iterator> BlockSet;

	report(" creating branches to regions that may have active threads.");
	
	PriorityMap priorities;
	BlockSet    visited;

	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	auto cfgToDFGMap = dfg->getCFGtoDFGMap();
	
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		if(block->block() == k.cfg()->get_entry_block()) continue;
		if(block->block() == k.cfg()->get_exit_block())  continue;
		if(blockHasExitPoint(k, block->block()))         continue;
		
		report("  for block - " << block->label());
		analysis::ThreadFrontierAnalysis::BlockVector frontier =
			tfAnalysis->getThreadFrontier(block->block());
		
		// Optimization:
		//  elide checks from convergent blocks to targets other than successors
		//
		//  check if all go to the furthest successor with bra.uni, otherwise,
		//  fallthrough
		if(!div->isEntryDiv(block))
		{
			assert(block->successors().size() <= 2);

			if(block->targets().empty()) continue;
			if(!block->hasFallthrough()) continue;

			auto target = block->targets().begin();

			if(tfAnalysis->getPriority(block->fallthrough()->block()) >
				tfAnalysis->getPriority((*target)->block()))
			{
				_conditionalBranchToTarget(block, *target);
				continue;
			}
		}
		
		BlockSet successors;
		
		for(auto successor = block->successors().begin();
			successor != block->successors().end(); ++successor)
		{
			if(!visited.insert((*successor)->block()).second) continue;

			priorities.insert(std::make_pair(
				tfAnalysis->getPriority((*successor)->block()), *successor));
			successors.insert((*successor)->block());
		}
		
		for(auto frontierBlock = frontier.begin();
			frontierBlock != frontier.end(); ++frontierBlock)
		{
			if(!visited.insert(*frontierBlock).second) continue;
			
			auto dfgBlock = cfgToDFGMap[*frontierBlock];
			
			priorities.insert(std::make_pair(
				tfAnalysis->getPriority(*frontierBlock), dfgBlock));
		}
		
		for(auto entry = priorities.begin();
			entry != priorities.end(); ++entry)
		{
			auto successor = successors.find(entry->second->block());
			
			if(successor != successors.end())
			{
				successors.erase(successor);
			}
			
			// Optimization:
			// no branch is needed if the fallthrough is the last block to be
			// checked
			if(entry->first + 1 == tfAnalysis->getPriority(block->block()))
			{
				if(entry == --priorities.end()) continue;
				
				if(successors.empty())
				{
					break;
				}
			}
			
			if(successor != successors.end() && successors.empty())
			{
				_uniformBranchToTarget(block, entry->second);
			}
			else
			{
				_branchToTargetIfVariableIsSet(block, entry->second);
			}
			
			if(successors.empty())
			{
				break;
			}
		}
		
		priorities.clear();
		visited.clear();
	}
}

void EnforceLockStepExecutionPass::_mergeVariablesBeforeEntering(
	block_iterator block, block_iterator successor)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	Register edgeVariable      = _getEdgeVariable(block, successor);
	Register successorVariable = _getBlockVariable(successor);
	
	ir::PTXInstruction lxor(ir::PTXInstruction::Xor);
	
	lxor.type = ir::PTXOperand::pred;
	
	lxor.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, successorVariable);
	lxor.a = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, edgeVariable);
	lxor.b = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, successorVariable);
	
	dfg->insert(block, lxor);
}

void EnforceLockStepExecutionPass::_setVariableForSuccessor(
	block_iterator block, block_iterator successor)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	Register edgeVariable      = _getEdgeVariable(block, successor);
	Register successorVariable = _getBlockVariable(successor);
	
	ir::PTXInstruction move(ir::PTXInstruction::Mov);
	
	move.type = ir::PTXOperand::pred;
	
	move.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, successorVariable);
	move.a = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, edgeVariable);
	
	dfg->insert(block, move);
}

void EnforceLockStepExecutionPass::_zeroVariableBeforeExiting(
	block_iterator block, block_iterator successor)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	Register successorVariable = _getBlockVariable(successor);
	
	ir::PTXInstruction mov(ir::PTXInstruction::Mov);
	
	mov.type = ir::PTXOperand::pred;
	
	mov.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, successorVariable);
	mov.a = ir::PTXOperand(0, ir::PTXOperand::pred);
	
	dfg->insert(block, mov);
}

void EnforceLockStepExecutionPass::_uniformBranchToTarget(block_iterator block,
	const_block_iterator target)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	ir::PTXInstruction bra(ir::PTXInstruction::Bra);
	
	bra.pg.addressMode = ir::PTXOperand::Register;
	bra.pg.condition   = ir::PTXOperand::PT;
	
	bra.d = ir::PTXOperand(target->label());
	bra.uni = true;
	
	dfg->insert(block, bra);
		
	report("   added branch to target " << target->label());
}

void EnforceLockStepExecutionPass::_conditionalBranchToTarget(
	block_iterator block, const_block_iterator target)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	ir::PTXInstruction bra(ir::PTXInstruction::Bra);
	
	Register targetVariable = _getBlockVariable(target);
	
	bra.pg = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, targetVariable);
	
	bra.d = ir::PTXOperand(target->label());
	bra.uni = true;
	
	dfg->insert(block, bra);
		
	report("   added conditional branch to target " << target->label());
}

void EnforceLockStepExecutionPass::_branchToTargetIfVariableIsSet(
	block_iterator block, const_block_iterator target)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));

	Register targetVariable = _getBlockVariable(target);
	
	ir::PTXInstruction vote(ir::PTXInstruction::Vote);
	
	vote.vote = ir::PTXInstruction::Any;	
	vote.type = ir::PTXOperand::pred;
	
	vote.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, dfg->newRegister());
	vote.a = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, targetVariable);
	
	dfg->insert(block, vote);
	
	ir::PTXInstruction bra(ir::PTXInstruction::Bra);
	
	bra.pg  = vote.d;
	bra.d   = ir::PTXOperand(target->label());
	bra.uni = true;
	
	dfg->insert(block, bra);
	
	report("   added check for target " << target->label());
}

ir::PTXInstruction* EnforceLockStepExecutionPass::_canonicalizeComparison(
	block_iterator block, ir::PTXInstruction* comparison)
{
	auto div = static_cast<analysis::DivergenceAnalysis*>(
		getAnalysis(Analysis::DivergenceAnalysis));
	
	assert(comparison->opcode == ir::PTXInstruction::SetP);

	report("   canonicalizing comparison '" << comparison->toString() << "'");

	comparison = _moveToEnd(block, comparison);

	// AND with the block variable if it is not convergent
	if(div->isEntryDiv(block))
	{
		comparison->c = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::pred, _getBlockVariable(block));
	
		comparison->booleanOperator = ir::PTXInstruction::BoolAnd;
	}

	// D must be a predicate destination
	assert(comparison->d.isRegister() &&
		comparison->d.type == ir::PTXOperand::pred);
	
	// PQ is the inverse of D
	if(comparison->pq.addressMode == ir::PTXOperand::Invalid)
	{
		auto dfg = static_cast<analysis::DataflowGraph*>(
			getAnalysis(Analysis::DataflowGraphAnalysis));
		
		comparison->pq = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::pred, dfg->newRegister());
	}
	
	// PQ must be a predicate destination
	assert(comparison->pq.isRegister() &&
		comparison->pq.type == ir::PTXOperand::pred);
	
	report("    to '" << comparison->toString() << "'");
	
	return comparison;
}


ir::PTXInstruction* EnforceLockStepExecutionPass::_moveToEnd(
	block_iterator block, ir::PTXInstruction* original)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	for(auto instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction)
	{
		auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);
		
		if(ptx == original)
		{
			auto newInstruction = dfg->insert(block, *original);
			dfg->erase(block, instruction);
			return static_cast<ir::PTXInstruction*>(newInstruction->i);
		}
	}
	
	assertM(false, "Instruction not found.")
	
	return 0;
}

void EnforceLockStepExecutionPass::_addComparison(block_iterator block,
	ir::PTXInstruction* branch)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	// convert predicate to register
	ir::PTXInstruction selp(ir::PTXInstruction::SelP);
	
	selp.type = ir::PTXOperand::b32;
	
	selp.c = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, branch->pg.reg);
	selp.a = ir::PTXOperand(1);
	selp.b = ir::PTXOperand(0);
	
	selp.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::b32, dfg->newRegister());
	
	dfg->insert(block, selp);

	// SETP instruction
	ir::PTXInstruction comparison(ir::PTXInstruction::SetP);
	
	comparison.comparisonOperator = ir::PTXInstruction::Eq;
	comparison.type = ir::PTXOperand::b32;
	
	comparison.a = ir::PTXOperand(1, ir::PTXOperand::b32);
	comparison.b = selp.d;

	// C must be a predicate destination
	assert(branch->pg.isRegister() &&
		branch->pg.type == ir::PTXOperand::pred);
	
	// AND with the block variable
	comparison.c = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, _getBlockVariable(block));
	comparison.booleanOperator = ir::PTXInstruction::BoolAnd;
	
	comparison.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, dfg->newRegister());
	comparison.pq = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, dfg->newRegister());

	branch->pg.reg = comparison.d.reg;

	dfg->insert(block, comparison);
}

void EnforceLockStepExecutionPass::_reset()
{
	_edgeVariables.clear();
	_blockToRegionRegisters.clear();
	_blocksWithEntryPointRegionTransitions.clear();
}

bool EnforceLockStepExecutionPass::_variablesMismatch(block_iterator left,
	block_iterator right)
{
	return _getBlockVariable(left) != _getBlockVariable(right);
}

EnforceLockStepExecutionPass::Register
	EnforceLockStepExecutionPass::_getBlockVariable(const_block_iterator block)
{
	auto regions = static_cast<analysis::ConvergentRegionAnalysis*>(
		getAnalysis(Analysis::ConvergentRegionAnalysis));
	
	Region region = regions->getRegion(block->block());
	
	auto mapping = _blockToRegionRegisters.find(region);
	
	if(mapping == _blockToRegionRegisters.end())
	{
		auto dfg = static_cast<analysis::DataflowGraph*>(
			getAnalysis(Analysis::DataflowGraphAnalysis));
		
		mapping = _blockToRegionRegisters.insert(
			std::make_pair(region, dfg->newRegister())).first;
	}
	
	return mapping->second;
}


EnforceLockStepExecutionPass::Register
	EnforceLockStepExecutionPass::_getEdgeVariable(
	block_iterator head, block_iterator tail)
{
	auto edge = head->block()->get_edge(tail->block());

	auto edgeVariable = _edgeVariables.find(edge);
	
	assertM(edgeVariable != _edgeVariables.end(), "No edge "
		<< edge->head->label() << " -> " << edge->tail->label());
	
	return edgeVariable->second;
}

}


