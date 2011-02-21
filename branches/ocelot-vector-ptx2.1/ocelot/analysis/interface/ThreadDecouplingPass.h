/*! 
	\file ThreadDecouplingPass.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date  21 February 2011
	\brief defines ThreadDecouplingPass which replaces uses of threadIdx.{x,y,z} with loads 
		from a .local variable
*/

#ifndef OCELOT_ANALYSIS_THREADDECOUPLINGPASS_H_INCLUDED
#define OCELOT_ANALYSIS_THREADDECOUPLINGPASS_H_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/ir/interface/Module.h>

// Standard Library Includes
#include <vector>
#include <unordered_map>

// Forward Declarations
namespace ir
{
	class PTXKernel;
}

namespace analysis
{
	/*!
		\brief replaces uses of threadIdx.{x,y,z} with loads from a .local variable
			which contains the actual mapping
	 */
	class ThreadDecouplingPass : public BasicBlockPass
	{
	public:
		typedef std::vector<ir::PTXKernel*> KernelVector;
			
	public:
		//! constructs the pass
		ThreadDecouplingPass();
		
		//! no operation
		virtual void initialize( const ir::Module& m );
		
		//! adds a local variable to each kernel storing threadIdx
		virtual void initialize( const ir::Kernel& m );
		
		//! replaces uses of threadIdx.{x,y,z} with loads from the local threadIdx variable
		virtual void runOnBlock( ir::BasicBlock& b );	
			
		/*! \brief Finalize the pass on the kernel */
		virtual void finalizeKernel( );
		
		/*! \brief Finalize the pass on the module */
		virtual void finalize( );
	
	private:
		//! \brief most recent kernel initialized
		ir::Kernel *_kernel;
		
	};
}

#endif
