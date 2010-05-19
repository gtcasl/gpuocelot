/*! \file Pass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday September 15, 2009
	\brief The source file for the Pass class.
*/

#ifndef PASS_CPP_INCLUDED
#define PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/Pass.h>
#include <hydrazine/implementation/debug.h>

namespace analysis
{
	Pass::Pass( Type t ) : type( t )
	{
	
	}
	
	Pass::~Pass()
	{
	
	}
	
	Pass::Pass( const Pass& p ) : type( p.type )
	{
	
	}
	
	Pass& Pass::operator=( const Pass& p )
	{
		assertM( p.type == type, "Cannot copy passes of different types." );
		return *this;
	}
	
	std::string Pass::toString() const
	{
		return name;
	}
	
	ImmutablePass::ImmutablePass() : Pass( Pass::ImmutablePass )
	{
	
	}

	ImmutablePass::~ImmutablePass()
	{
	
	}
	
	ModulePass::ModulePass() : Pass( Pass::ModulePass )
	{
	
	}
	
	ModulePass::~ModulePass()
	{
	
	}

	KernelPass::KernelPass() : Pass( Pass::KernelPass )
	{
	
	}
	
	KernelPass::~KernelPass()
	{
	
	}

	BasicBlockPass::BasicBlockPass() : Pass( Pass::BasicBlockPass )
	{
	
	}
	
	BasicBlockPass::~BasicBlockPass()
	{
	
	}

}

#endif

