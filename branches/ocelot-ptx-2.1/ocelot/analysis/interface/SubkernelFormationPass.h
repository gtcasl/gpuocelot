/*! \file SubkernelFormationPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday July 27, 2010
	\brief The header file for the SubkernelFormationPass class.
*/

#ifndef SUBKERNEL_FORMATION_PASS_H_INCLUDED
#define SUBKERNEL_FORMATION_PASS_H_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/Pass.h>

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
	/*! \brief Split all kernels in a module into sub-kernels.  The sub-kernels
		should be called as functions from the main kernel.  The assumption
		is that all threads will execute a sub-kernel, hit a barrier, and
		enter the next sub-kernel.
		
		This pass may optionally insert an explicit scheduler kernel that is
		responsible for doing fine-grained scheduling of the next function
		to execute and control transition between functions.  This is necessary
		to support intelligent scheduling on architectures without runtime 
		support (mainly GPUs).
	 */
	class SubkernelFormationPass : public ModulePass
	{
	public:
		typedef std::vector<ir::PTXKernel*> KernelVector;
			
	public:
		SubkernelFormationPass(unsigned int expectedRegionSize = 5);
		void runOnModule(ir::Module& m);

	public:
		class ExtractKernelsPass : public KernelPass
		{
		public:
			typedef std::unordered_map<std::string, 
				KernelVector> KernelVectorMap;
				
		public:
			ExtractKernelsPass(unsigned int expectedRegionSize = 5);
			void initialize(const ir::Module& m);
			void runOnKernel(ir::Kernel& k);
			void finalize();
			
		public:
			KernelVectorMap kernels;
		
		private:
			unsigned int _expectedRegionSize;
		};
		
	private:
		unsigned int _expectedRegionSize;
	};
}

#endif

