/*! \file SubkernelFormationPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday July 27, 2010
	\brief The header file for the SubkernelFormationPass class.
*/

#ifndef SUBKERNEL_FORMATION_PASS_H_INCLUDED
#define SUBKERNEL_FORMATION_PASS_H_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/Pass.h>

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
	 */
	class SubkernelFormationPass : ModulePass
	{
	public:
		void runOnModule(ir::Module& m);

	private:
		class ExtractKernelsPass : KernelPass
		{
		public:
			typedef std::vector<ir::Kernel*> KernelVector;
			typedef std::unordered_map<std::string, 
				KernelVector> KernelVectorMap;
		
		public:
			void initialize(const ir::Module& m);
			void runOnKernel(ir::Kernel& k);
			void finalize();
			
		public:
			KernelVectorMap kernels;
		
		public:
			unsigned int expectedRegionSize;
		};
	};
}

#endif

