/*! \file   EnforceLockStepExecutionPass.cpp
	\date   Wednesday April 18, 2012
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the  EnforceLockStepExecutionPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/EnforceLockStepExecutionPass.h>

#include <ocelot/analysis/interface/ThreadFrontierAnalysis.h>
#include <ocelot/analysis/interface/ConvergentRegionAnalysis.h>

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
	Analysis::DataflowGraphAnalysis | Analysis::ConvergentRegionAnalysis,
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
	
	// assign a mask to the program entry point
	_assignMaskToEntryPoint(k);
	
	// assign condition variables to branch edges
	_assignConditionsToEdges(k);
	
	// Delete all branches
	_deleteAllBranches(k);
	
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
	
	auto firstBlock = dfg->begin()->fallthrough();
	
	report(" assigning a mask to the program entry point "
		<< firstBlock->label());
	
	ir::PTXInstruction vote(ir::PTXInstruction::Vote);

	vote.type = ir::PTXOperand::b32;
	
	vote.vote = ir::PTXInstruction::Ballot;
	vote.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::u32, _getBlockVariable(firstBlock));
	vote.a = ir::PTXOperand(1, ir::PTXOperand::pred);
	
	dfg->insert(firstBlock, vote, 0);
	
	report("  " << vote.toString());
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
		
		if(bra == nullptr)
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
			takenMask = bra->pg.reg;
			
			ir::PTXInstruction vote(ir::PTXInstruction::Vote);

			vote.type = ir::PTXOperand::b32;
			
			vote.vote = ir::PTXInstruction::Ballot;
			vote.d = ir::PTXOperand(ir::PTXOperand::Register,
				ir::PTXOperand::u32, dfg->newRegister());
			vote.a = ir::PTXOperand(ir::PTXOperand::Register,
				ir::PTXOperand::pred, takenMask);
			
			dfg->insert(block, vote);
		
			takenMask = vote.d.reg;
		}
		
		assert(block->block()->has_branch_edge());
		auto branchEdge = block->block()->get_branch_edge();
		
		_edgeVariables.insert(std::make_pair(branchEdge, takenMask));

		report("   creating mask for branch edge " << branchEdge->head->label
			<< " -> " << branchEdge->tail->label);
		
		if(bra->pg.condition == ir::PTXOperand::PT) continue;

		ir::PTXInstruction lnot(ir::PTXInstruction::Not);

		lnot.type = ir::PTXOperand::b32;
		
		lnot.d = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::u32, dfg->newRegister());
		lnot.a = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::u32, takenMask);
		
		dfg->insert(block, lnot);
		
		ir::PTXInstruction land(ir::PTXInstruction::And);
		
		Register fallthroughMask = dfg->newRegister();
		
		land.type = ir::PTXOperand::b32;
		
		land.d = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::u32, fallthroughMask);
		land.a = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::u32, _getBlockVariable(block));
		land.b = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::u32, lnot.d.reg);
		
		dfg->insert(block, land);
		
		assert(block->block()->has_fallthrough_edge());
		auto fallthroughEdge = block->block()->get_fallthrough_edge();
		
		_edgeVariables.insert(std::make_pair(fallthroughEdge, fallthroughMask));
		
		report("   creating mask for fallthrough edge "
			<< fallthroughEdge->head->label << " -> "
			<< fallthroughEdge->tail->label);
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

void EnforceLockStepExecutionPass::_setMergePoints(ir::IRKernel& k)
{
	auto tfAnalysis = static_cast<analysis::ThreadFrontierAnalysis*>(
		getAnalysis(Analysis::ThreadFrontierAnalysis));

	report(" updating masks on region transitions");
	
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	for(auto block = dfg->begin(); block != dfg->end(); ++block)
	{
		if(block->block() == k.cfg()->get_entry_block()) continue;
		if(block->block() == k.cfg()->get_exit_block())  continue;
		
		report("  for block " << block->label());
		for(auto successor : block->successors())
		{
			if(successor->block() == k.cfg()->get_entry_block()) continue;
			if(successor->block() == k.cfg()->get_exit_block())  continue;
			
			if(tfAnalysis->isInThreadFrontier(
				block->block(), successor->block()))
			{
				report("   merging variable with " << successor->label()
					<< " before entering" );
				_mergeVariablesBeforeEntering(block, successor);
			}
			else
			{
				report("   assigning variable with " << successor->label()
					<< " before entering" );
				_assignVariableBeforeEntering(block, successor);
			}
		}
	}
}

void EnforceLockStepExecutionPass::_setBranches(ir::IRKernel& k)
{
	auto tfAnalysis = static_cast<analysis::ThreadFrontierAnalysis*>(
		getAnalysis(Analysis::ThreadFrontierAnalysis));

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
		
		BlockSet successors;
		
		for(auto successor : block->successors())
		{
			if(!visited.insert(successor->block()).second) continue;

			priorities.insert(std::make_pair(
				tfAnalysis->getPriority(successor->block()), successor));
			successors.insert(successor->block());
		}
		
		for(auto frontierBlock : frontier)
		{
			if(!visited.insert(frontierBlock).second) continue;
			
			auto dfgBlock = cfgToDFGMap[frontierBlock];
			
			priorities.insert(std::make_pair(
				tfAnalysis->getPriority(frontierBlock), dfgBlock));
		}
		
		for(auto entry = priorities.begin();
			entry != priorities.end(); ++entry)
		{
			auto successor = successors.find(entry->second->block());
			
			if(successor != successors.end())
			{
				successors.erase(successor);
			}
			
			// no branch is needed if the fallthrough is the last block to be
			// checked
			if(entry->first + 1 == tfAnalysis->getPriority(block->block()))
			{
				if(entry == --priorities.end()) continue;
			}
			
			_branchToTargetIfVariableIsSet(block, entry->second);
			
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
	
	ir::PTXInstruction lor(ir::PTXInstruction::Or);
	
	lor.type = ir::PTXOperand::b32;
	
	lor.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::u32, successorVariable);
	lor.a = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::u32, edgeVariable);
	lor.b = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::u32, successorVariable);
	
	lor.broadcast = true;
	
	dfg->insert(block, lor);
	
	_setActiveMaskIfNecessary(successor);
}

void EnforceLockStepExecutionPass::_assignVariableBeforeEntering(
	block_iterator block, block_iterator successor)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	Register edgeVariable      = _getEdgeVariable(block, successor);
	Register successorVariable = _getBlockVariable(successor);
	
	ir::PTXInstruction mov(ir::PTXInstruction::Mov);
	
	mov.type = ir::PTXOperand::b32;
	
	mov.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::b32, successorVariable);
	mov.a = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::b32, edgeVariable);
	
	mov.broadcast = true;
	
	dfg->insert(block, mov);
	
	_setActiveMaskIfNecessary(successor);
}

void EnforceLockStepExecutionPass::_branchToTargetIfVariableIsSet(
	block_iterator block, const_block_iterator target)
{
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	Register targetVariable = _getBlockVariable(target);
	
	ir::PTXInstruction setp(ir::PTXInstruction::SetP);
	
	setp.type = ir::PTXOperand::u32;	
	
	setp.d = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::pred, dfg->newRegister());
	setp.a = ir::PTXOperand(ir::PTXOperand::Register,
		ir::PTXOperand::u32, targetVariable);
	setp.b = ir::PTXOperand(0, ir::PTXOperand::u32);
	setp.comparisonOperator = ir::PTXInstruction::Ne;
	
	dfg->insert(block, setp);
	
	ir::PTXInstruction bra(ir::PTXInstruction::Bra);
	
	bra.pg = setp.d;
	bra.d  = ir::PTXOperand(target->label());
	
	dfg->insert(block, bra);
		
	report("   added check for target " << target->label());
}

void EnforceLockStepExecutionPass::_setActiveMaskIfNecessary(
	block_iterator target)
{
	if(_blocksWithEntryPointRegionTransitions.insert(target).second)
	{
		auto dfg = static_cast<analysis::DataflowGraph*>(
			getAnalysis(Analysis::DataflowGraphAnalysis));
	
		ir::PTXInstruction merge(ir::PTXInstruction::Reconverge);
	
		merge.a = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::u32, _getBlockVariable(target));
		merge.getActiveMask = false;
		
		std::stringstream stream;
		
		stream << "// active mask = " << merge.a.toString();
		
		merge.metadata = stream.str();	
		
		dfg->insert(target, merge, 0);
	}
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
		<< edge->head->label << " -> " << edge->tail->label);
	
	return edgeVariable->second;
}

}


