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
	Pass::Pass( Type t, bool s, const std::string& n )
		: type( t ), ssa( s ), name( n )
	{
	
	}
	
	Pass::~Pass()
	{
	
	}
	
	Pass::Pass( const Pass& p ) : type( p.type ), ssa( p.ssa ), name( p.name )
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
	
	ImmutablePass::ImmutablePass( bool s, const std::string& n) 
		: Pass( Pass::ImmutablePass, s, n )
	{
	
	}

	ImmutablePass::~ImmutablePass()
	{
	
	}
	
	ModulePass::ModulePass( bool s, const std::string& n ) 
		: Pass( Pass::ModulePass, s, n )
	{
	
	}
	
	ModulePass::~ModulePass()
	{
	
	}

	KernelPass::KernelPass( bool s, const std::string& n )
		: Pass( Pass::KernelPass, s, n )
	{
	
	}
	
	KernelPass::~KernelPass()
	{
	
	}

	BasicBlockPass::BasicBlockPass( bool s, const std::string& n )
		: Pass( Pass::BasicBlockPass, s, n )
	{
	
	}
	
	BasicBlockPass::~BasicBlockPass()
	{
	
	}

}

#endif

