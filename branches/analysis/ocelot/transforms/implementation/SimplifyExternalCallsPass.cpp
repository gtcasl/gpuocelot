/*! \file   SimplifyExternalCallsPass.cpp
	\date   Saturday April 9, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the SimplifyExternalCallsPass class.
*/

// Ocelot Includes
#include <ocelot/analysis/interface/SimplifyExternalCallsPass.h>
#include <ocelot/ir/interface/ExternalFunctionSet.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{

static void simplifyCall(ir::PTXKernel& kernel,
	ir::ControlFlowGraph::iterator block, ir::PTXInstruction& call)
{
	typedef std::unordered_set<std::string> StringSet;
	typedef std::unordered_map<std::string,
		ir::PTXOperand::RegisterType> RegisterMap;
	typedef std::vector<ir::BasicBlock::InstructionList::iterator>
		InstructionVector;

	// Get the names of parameters
	StringSet parameterNames;
	
	report("  return arguments:");
	
	for(ir::PTXOperand::Array::const_iterator parameter = call.d.array.begin();
		parameter != call.d.array.end(); ++parameter)
	{
		if(parameter->addressMode == ir::PTXOperand::BitBucket) continue;
		report("   " << parameter->identifier);
		parameterNames.insert(parameter->identifier);
	}

	report("  input arguments:");
	for(ir::PTXOperand::Array::const_iterator parameter = call.b.array.begin();
		parameter != call.b.array.end(); ++parameter)
	{
		if(parameter->addressMode == ir::PTXOperand::BitBucket) continue;
		report("   " << parameter->identifier);
		parameterNames.insert(parameter->identifier);
	}
	
	// Find the registers that are mapped to these parameters
	RegisterMap nameToRegister;
	InstructionVector killList;
	
	for(ir::BasicBlock::InstructionList::iterator
		instruction = block->instructions.begin();
		instruction != block->instructions.end(); ++instruction)
	{
		ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(
			**instruction);
	
		if(ptx.opcode == ir::PTXInstruction::St)
		{
			if(ptx.addressSpace == ir::PTXInstruction::Param)
			{
				if(ptx.d.addressMode == ir::PTXOperand::Address)
				{
					if(parameterNames.count(ptx.d.identifier) != 0)
					{
						assert(ptx.a.addressMode == ir::PTXOperand::Register);
						assert(nameToRegister.count(ptx.d.identifier) == 0);
						nameToRegister.insert(std::make_pair(ptx.d.identifier,
							ptx.a.reg));
						killList.push_back(instruction);
					}
				}
			}
		}
		else if(ptx.opcode == ir::PTXInstruction::Ld)
		{
			if(ptx.addressSpace == ir::PTXInstruction::Param)
			{
				if(ptx.a.addressMode == ir::PTXOperand::Address)
				{
					if(parameterNames.count(ptx.a.identifier) != 0)
					{
						assert(ptx.d.addressMode == ir::PTXOperand::Register);
						assert(nameToRegister.count(ptx.a.identifier) == 0);
						nameToRegister.insert(std::make_pair(ptx.a.identifier,
							ptx.d.reg));
						killList.push_back(instruction);
					}
				}
			}
		}
	}
	
	// Modify the call to replace parameter operands with register operands
	for(ir::PTXOperand::Array::iterator parameter = call.d.array.begin();
		parameter != call.d.array.end(); ++parameter)
	{
		if(parameter->addressMode == ir::PTXOperand::BitBucket) continue;
		RegisterMap::iterator mapping = nameToRegister.find(
			parameter->identifier);
		assert(mapping != nameToRegister.end());
		
		parameter->addressMode = ir::PTXOperand::Register;
		parameter->reg         = mapping->second;

		parameter->identifier.clear();
	}

	for(ir::PTXOperand::Array::iterator parameter = call.b.array.begin();
		parameter != call.b.array.end(); ++parameter)
	{
		if(parameter->addressMode == ir::PTXOperand::BitBucket) continue;
		RegisterMap::iterator mapping = nameToRegister.find(
			parameter->identifier);
		assert(mapping != nameToRegister.end());
		
		parameter->addressMode = ir::PTXOperand::Register;
		parameter->reg         = mapping->second;

		parameter->identifier.clear();
	}
	
	report("  new call is '" << call.toString() << "'");
	
	// Remove the parameter instructions
	report("  removing ld/st param instructions:");
	for(InstructionVector::const_iterator killed = killList.begin();
		killed != killList.end(); ++killed)
	{
		report("   removing " << (**killed)->toString());
		block->instructions.erase(*killed);
	}
	
	// Remove the parameters from the kernels
	report("  removing parameters:");
	for(StringSet::const_iterator parameterName = parameterNames.begin();
		parameterName != parameterNames.end(); ++parameterName)
	{
		report("   " << *parameterName);
		ir::Kernel::ParameterMap::iterator
			parameter = kernel.parameters.find(*parameterName);
		assert(parameter != kernel.parameters.end());
		kernel.parameters.erase(parameter);
	}
}

SimplifyExternalCallsPass::SimplifyExternalCallsPass(
	const ir::ExternalFunctionSet& e) 
: KernelPass(NoAnalysis, "SimplifyExternalCallsPass"), _externals(&e)
{

}

void SimplifyExternalCallsPass::initialize(const ir::Module& m)
{

}

void SimplifyExternalCallsPass::runOnKernel(ir::IRKernel& k)
{
	ir::PTXKernel& kernel = static_cast<ir::PTXKernel&>(k);

	report("Running SimplifyExternalCallsPass on kernel '" + k.name + "'");

	for(ir::ControlFlowGraph::iterator block = k.cfg()->begin();
		block != k.cfg()->end(); ++block)
	{
		for(ir::BasicBlock::InstructionList::iterator
			instruction = block->instructions.begin();
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(
				**instruction);
		
			if(ptx.opcode == ir::PTXInstruction::Call)
			{
				if(k.module->kernels().count(ptx.a.identifier) == 0)
				{
					if(_externals->find(ptx.a.identifier) != 0)
					{
						report(" For " << ptx.toString());
						simplifyCall(kernel, block, ptx);
					}
				}
			}
		}
	}
}

void SimplifyExternalCallsPass::finalize()
{

}

}

