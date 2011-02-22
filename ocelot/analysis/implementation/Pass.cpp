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
	Pass::Pass( Type t, int a, const std::string& n )
		: type( t ), analyses( a ), name( n )
	{
	
	}
	
	Pass::~Pass()
	{
	
	}
	
	Pass::Pass( const Pass& p ) : type( p.type ), 
		analyses( p.analyses ), name( p.name )
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
	
	ImmutablePass::ImmutablePass( int a, const std::string& n) 
		: Pass( Pass::ImmutablePass, a, n )
	{
	
	}

	ImmutablePass::~ImmutablePass()
	{
	
	}
	
	ModulePass::ModulePass( int a, const std::string& n ) 
		: Pass( Pass::ModulePass, a, n )
	{
	
	}
	
	ModulePass::~ModulePass()
	{
	
	}

	KernelPass::KernelPass( int a, const std::string& n )
		: Pass( Pass::KernelPass, a, n )
	{
	
	}
	
	KernelPass::~KernelPass()
	{
	
	}
	
	//! \brief called before runOnBlock() is called 
	void KernelPass::doInitialize( ir::Module &module) {
	
	}
	
	/*! \brief Initialize the pass using a specific module */
	void KernelPass::initialize( const ir::Module& m ) {
	
	}
			
	/*! \brief Finalize the pass */
	void KernelPass::finalize( ) {
	
	}

	BasicBlockPass::BasicBlockPass( int a, const std::string& n )
		: Pass( Pass::BasicBlockPass, a, n )
	{
	
	}
	
	BasicBlockPass::~BasicBlockPass()
	{
	
	}
	
	//! \brief called before runOnBlock() is called 
	void BasicBlockPass::doInitialize( ir::Module &module) {
	
	}
	
	//! \brief called before runOnBlock() is called 
	void BasicBlockPass::doInitialize( ir::Kernel &kernel) {
	
	}

	/*! \brief Initialize the pass using a specific module */
	void BasicBlockPass::initialize( const ir::Module& m ) {
	
	}

	/*! \brief Initialize the pass using a specific kernel */
	void BasicBlockPass::initialize( const ir::Kernel& kernel ) {
	
	}	

	/*! \brief Finalize the pass on the kernel */
	void BasicBlockPass::finalizeKernel( ) {
	
	}

	/*! \brief Finalize the pass on the module */
	void BasicBlockPass::finalize( ) {
	
	}
}

#endif

