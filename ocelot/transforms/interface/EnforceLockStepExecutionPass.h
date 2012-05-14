/*! \file   EnforceLockStepExecutionPass.h
	\date   Wednesday April 18, 2012
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The header file for the  EnforceLockStepExecutionPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/Pass.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/Instruction.h>

#include <ocelot/analysis/interface/DataflowGraph.h>

// Standard Library Includes
#include <unordered_map>
#include <unordered_set>

namespace transforms
{

/*! \brief Insert instructions to modify the active mask to enforce lock-step
           execution down a divergent subgraph */
class EnforceLockStepExecutionPass : public ::transforms::KernelPass
{
public:
	/*! \brief The default constructor sets the type */
	EnforceLockStepExecutionPass();
	
public:
	/*! \brief Initialize the pass using a specific module */
	void initialize(const ir::Module& m);
	/*! \brief Run the pass on a specific kernel in the module */
	void runOnKernel(ir::IRKernel& k);
	/*! \brief Finalize the pass */
	void finalize();

public:
	virtual StringVector getDependentPasses() const;

private:
	typedef ir::Instruction::RegisterType Register;
	typedef unsigned int Region;
	typedef analysis::DataflowGraph::iterator block_iterator;
	typedef analysis::DataflowGraph::const_iterator const_block_iterator;
	typedef std::unordered_map<ir::ControlFlowGraph::edge_iterator,
		Register> EdgeMap;
	typedef std::unordered_map<Region, Register> RegionMap;
	typedef std::unordered_set<const_block_iterator> BlockSet;

private:
	// Algorithm stages
	void _assignMaskToEntryPoint(ir::IRKernel& k);
	void _assignConditionsToEdges(ir::IRKernel& k);
	void _deleteAllBranches(ir::IRKernel& k);
	void _setMergePoints(ir::IRKernel& k);
	void _setBranches(ir::IRKernel& k);

private:
	// Helper functions
	void _mergeVariablesBeforeEntering(block_iterator block,
		block_iterator successor);
	void _assignVariableBeforeEntering(block_iterator block,
		block_iterator successor);
	void _setVariableForSuccessor(block_iterator block,
		block_iterator successor);
	void _branchToTargetIfVariableIsSet(block_iterator block,
		const_block_iterator target);
	void _setActiveMaskIfNecessary(block_iterator target);

	void _reset();

	bool _variablesMismatch(block_iterator left, block_iterator right);
	Register _getBlockVariable(const_block_iterator block);
	Register _getEdgeVariable(block_iterator head, block_iterator tail);

private:
	EdgeMap   _edgeVariables;
	RegionMap _blockToRegionRegisters;
	BlockSet  _blocksWithEntryPointRegionTransitions;

};

}


