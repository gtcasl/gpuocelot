/*	\file   HoistParameterLoadsPass.cpp
	\date   December 14, 2012
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the HoistParameterLoadsPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/HoistParameterLoadsPass.h>

#include <ocelot/analysis/interface/DominatorTree.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/LoopAnalysis.h>
#include <ocelot/analysis/interface/SimpleAliasAnalysis.h>

#include <ocelot/ir/interface/IRKernel.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{

HoistParameterLoadsPass::HoistParameterLoadsPass()
: KernelPass(Analysis::DominatorTreeAnalysis | Analysis::DataflowGraphAnalysis |
	Analysis::LoopAnalysis | Analysis::SimpleAliasAnalysis,
	"HoistParameterLoadsPass")
{
	
}

void HoistParameterLoadsPass::runOnKernel(ir::IRKernel& k)
{
	typedef std::pair<ir::ControlFlowGraph::iterator, ir::PTXInstruction*> Load;
	typedef std::vector<Load> LoadVector;

	auto aliasAnalysis = static_cast<analysis::SimpleAliasAnalysis*>(
		getAnalysis(Analysis::SimpleAliasAnalysis));
	
	LoadVector candidateLoads;
	
	report("Hoisting loads in kernel '" << k.name << "'");

	report(" Identifying candidate loads");
	
	for(auto block = k.cfg()->begin(); block != k.cfg()->end(); ++block)
	{
		for(auto instruction : block->instructions)
		{
			auto ptx = static_cast<ir::PTXInstruction*>(instruction);
		
			if(ptx->isLoad() && aliasAnalysis->cannotAliasAnyStore(instruction))
			{
				report("  " << ptx->toString());
				candidateLoads.push_back(std::make_pair(block, ptx));
			}
		}
	}
	
	report(" Attempting to hoist loads");
	for(auto load : candidateLoads)
	{
		_tryHoistingLoad(load.first, load.second);
	}
	
	invalidateAnalysis(analysis::Analysis::DataflowGraphAnalysis);
	invalidateAnalysis(analysis::Analysis::SimpleAliasAnalysis  );
}

static void insertBeforeTerminator(ir::ControlFlowGraph::iterator block,
	ir::PTXInstruction* instruction)
{
	bool hasTerminator = false;
	
	if(!block->instructions.empty())
	{
		ir::PTXInstruction* possibleTerminator =
			static_cast<ir::PTXInstruction*>(block->instructions.back());
	
		hasTerminator = possibleTerminator->isBranch();
	}
	
	ir::ControlFlowGraph::instruction_iterator position =
		block->instructions.end();

	if(hasTerminator) --position;
	
	block->instructions.insert(position, instruction);
}

void HoistParameterLoadsPass::_tryHoistingLoad(
	ir::ControlFlowGraph::iterator block, ir::PTXInstruction* ptx)
{
	report("  " << ptx->toString());
	
	auto newBlock = _getTopLevelDominatingBlock(block);
	
	if(newBlock == block) return;
	
	report("   hoisting to " << newBlock->label());
	
	auto dfg = static_cast<analysis::DataflowGraph*>(
		getAnalysis(Analysis::DataflowGraphAnalysis));
	
	auto load = new ir::PTXInstruction(ir::PTXInstruction::Ld);
	
	load->addressSpace   = ptx->addressSpace;
	load->type           = ptx->type;
	load->volatility     = ptx->volatility;
	load->cacheOperation = ptx->cacheOperation;
	
	load->d = ir::PTXOperand(ir::PTXOperand(ir::PTXOperand::Register,
		ptx->d.type, dfg->newRegister()));
	load->a = ptx->a;
	
	insertBeforeTerminator(newBlock, load);
	
	ptx->opcode = ir::PTXInstruction::Mov;
	ptx->a = load->d;
}

ir::ControlFlowGraph::iterator 
	HoistParameterLoadsPass::_getTopLevelDominatingBlock(
		ir::ControlFlowGraph::iterator block)
{
	auto loopAnalysis = static_cast<analysis::LoopAnalysis*>(
		getAnalysis(Analysis::LoopAnalysis));
	auto dominatorTree = static_cast<analysis::DominatorTree*>(
		getAnalysis(Analysis::DominatorTreeAnalysis));
		
	while(block != block->cfg->get_entry_block())
	{
		block = dominatorTree->getDominator(block);
		
		if(!loopAnalysis->isContainedInLoop(block)) break;
	}
	
	return block;
	
}

}

