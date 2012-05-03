/*! \file   PassFactory.cpp
	\date   Wednesday May 2, 2012
	\author Gregory Diamos <gdiamos@nvidia.com>
	\brief  The source file for the PassFactory class.
	
*/

// Ocelot Includes
#include <ocelot/transforms/interface/PassFactory.h>

#include <ocelot/transforms/interface/LinearScanRegisterAllocationPass.h>
#include <ocelot/transforms/interface/RemoveBarrierPass.h>
#include <ocelot/transforms/interface/StructuralTransform.h>
#include <ocelot/transforms/interface/ConvertPredicationToSelectPass.h>
#include <ocelot/transforms/interface/SubkernelFormationPass.h>
#include <ocelot/transforms/interface/MIMDThreadSchedulingPass.h>
#include <ocelot/transforms/interface/DeadCodeEliminationPass.h>
#include <ocelot/transforms/interface/SplitBasicBlockPass.h>
#include <ocelot/transforms/interface/SyncEliminationPass.h>
#include <ocelot/transforms/interface/HoistSpecialValueDefinitionsPass.h>
#include <ocelot/transforms/interface/LoopUnrollingPass.h>
#include <ocelot/transforms/interface/SimplifyControlFlowGraphPass.h>

// Standard Library Includes
#include <stdexcept>

namespace transforms
{

Pass* PassFactory::createPass(const std::string& name)
{
	if( name == "linearscan" )
	{
		return new transforms::LinearScanRegisterAllocationPass;
	}
	else if( name == "remove-barriers" )
	{
		return new transforms::RemoveBarrierPass;
	}
	else if( name == "reverse-if-conversion" )
	{
		return new transforms::ConvertPredicationToSelectPass;
	}
	else if( name == "structural-transform" )
	{
		return new transforms::StructuralTransform;
	}
	else if( name == "subkernel-formation" )
	{
		return new transforms::SubkernelFormationPass;
	}
	else if( name == "mimd-threading" )
	{
		return new transforms::MIMDThreadSchedulingPass;
	}
	else if( name == "dead-code-elimination" )
	{
		return new transforms::DeadCodeEliminationPass;
	}
	else if( name == "split-blocks" )
	{
		return new transforms::SplitBasicBlockPass;
	}
	else if( name == "sync-elimination" )
	{
		return new transforms::SyncEliminationPass;
	}
	else if( name == "hoist-special-definitions" )
	{
		return new transforms::HoistSpecialValueDefinitionsPass;
	}
	else if( name == "simplify-cfg" )
	{
		return new transforms::SimplifyControlFlowGraphPass;
	}
	else if( name == "loop-unrolling" )
	{
		return new transforms::LoopUnrollingPass;
	}
	else
	{
		throw std::runtime_error("Invalid pass name " + name);
	}
	
	return 0;
}

}


