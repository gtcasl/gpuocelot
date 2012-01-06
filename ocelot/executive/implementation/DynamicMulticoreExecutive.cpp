/*!
	\file DynamicMulticoreExecutive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 20, 2011
	\brief executes a kernel over one or more CTAs
*/

#include <ocelot/executive/interface/DynamicTranslationCache.h>
#include <ocelot/executive/interface/DynamicExecutionManager.h>
#include <ocelot/executive/interface/DynamicMulticoreExecutive.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::DynamicMulticoreExecutive(
	executive::DynamicMulticoreKernel &_kernel, size_t _sharedMemorySize
):
	kernel(&_kernel) 
{
	
	// allocate memory for Cooperative Thread array
	localMemorySize = _kernel.localMemorySize();
	localMemory = new char[localMemorySize];
	
	sharedMemorySize = _sharedMemorySize;
	sharedMemory = new char[sharedMemorySize];
	
	parameterMemorySize = _kernel.parameterMemorySize();
	parameterMemory = new char[parameterMemorySize];
	
	report("DynamicMulticoreExecutve('" << _kernel.name << "', shared mem size: " << sharedMemorySize);
	report("  localMemorySize: " << localMemorySize);
	report("  paramMemorySize: " << parameterMemorySize);
}

executive::DynamicMulticoreExecutive::~DynamicMulticoreExecutive() {
	delete [] localMemory;
	delete [] sharedMemory;
	delete [] parameterMemory;
}

void executive::DynamicMulticoreExecutive::execute(ir::Dim3 block) {
	report("DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y << ")");

	analysis::KernelPartitioningPass::KernelGraph *kernelGraph = kernel->kernelGraph();

	DynamicTranslationCache::Translation *entryTranslation =
		DynamicExecutionManager::get().translationCache.getOrInsertTranslation(1, 
			kernelGraph->getEntrySubkernel());
	
	assert(entryTranslation);
	
	// initialize thread contexts
	//
	// while threads not done {
	//   form largest warp possible
	//   execute subkernel
	//   update contexts
	// }
	//
  // exit
}

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::Metadata::Metadata() {

}

executive::DynamicMulticoreExecutive::Metadata::~Metadata() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////

