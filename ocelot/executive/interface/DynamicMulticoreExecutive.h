/*!
	\file DynamicMulticoreExecutive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 20, 2011
	\brief executes a kernel over one or more CTAs
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICMULTICOREEXECUTIVE_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICMULTICOREEXECUTIVE_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>

namespace executive {

	class DynamicMulticoreExecutive {
	public:
	
	public:
		DynamicMulticoreExecutive(executive::DynamicMulticoreKernel &kernel, size_t sharedMemory);
		~DynamicMulticoreExecutive();
		
		void execute(ir::Dim3 block);
	
	protected:
		
		char *localMemory;
		size_t localMemorySize;
		
		char *sharedMemory;
		size_t sharedMemorySize;
		
		char *parameterMemory;
		size_t parameterMemorySize;
	};

}

#endif

