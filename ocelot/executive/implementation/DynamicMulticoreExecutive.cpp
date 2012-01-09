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

#define REPORT_SCHEDULE_OPERATIONS 1			// scheduling events

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::SubkernelId 
	executive::DynamicMulticoreExecutive::_getResumePoint(const executive::LLVMContext *context, 
	int tid) {
	
	const char *ptr = context->local;
	return *(executive::DynamicMulticoreExecutive::SubkernelId *)(ptr + 0);
}

void executive::DynamicMulticoreExecutive::_setResumePoint(const executive::LLVMContext *context, 
	int tid, SubkernelId subkernel) {

	char *ptr = context->local;
	*(executive::DynamicMulticoreExecutive::SubkernelId *)(ptr + 0) = subkernel;
}

executive::DynamicMulticoreExecutive::ThreadExitType 
	executive::DynamicMulticoreExecutive::_getResumeStatus(const executive::LLVMContext *context,
	int tid) {
	
	const char *ptr = context->local;
	return *(executive::DynamicMulticoreExecutive::ThreadExitType *)(ptr + 4);
}

void executive::DynamicMulticoreExecutive::_setResumeStatus(const executive::LLVMContext *context, 
	int tid, executive::DynamicMulticoreExecutive::ThreadExitType status) {

	char *ptr = context->local;
	*(executive::DynamicMulticoreExecutive::ThreadExitType *)(ptr + 4) = status;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::DynamicMulticoreExecutive(
	executive::DynamicMulticoreKernel &_kernel, size_t _sharedMemorySize
):
	kernel(&_kernel) 
{
	
	// allocate memory for Cooperative Thread array
	localMemorySize = _kernel.kernelGraph()->localMemorySize();
	localMemory = new char[localMemorySize * _kernel.blockDim().size()];
	
	sharedMemorySize = _sharedMemorySize;
	sharedMemory = new char[sharedMemorySize];
	
	parameterMemorySize = _kernel.parameterMemorySize();
	parameterMemory = new char[parameterMemorySize];
	
	contexts = new LLVMContext[kernel->blockDim().size()];
	
	report("DynamicMulticoreExecutve('" << _kernel.name << "', shared mem size: " << sharedMemorySize);
	report("  localMemorySize: " << localMemorySize);
	report("  paramMemorySize: " << parameterMemorySize);
}

executive::DynamicMulticoreExecutive::~DynamicMulticoreExecutive() {
	delete [] contexts;
	delete [] localMemory;
	delete [] sharedMemory;
	delete [] parameterMemory;
}

void executive::DynamicMulticoreExecutive::_initializeThreadContexts(const ir::Dim3 &blockId) {

	const ir::Dim3 blockDim = kernel->blockDim();
	SubkernelId startingSubkernel = kernel->kernelGraph()->getEntrySubkernel();
	
	for (int i = 0; i < blockDim.size(); i++) {
		contexts[i].tid = {i % blockDim.x, (i / blockDim.x) % blockDim.y, i / (blockDim.x * blockDim.y)};
		
		contexts[i].ntid = {blockDim.x, blockDim.y, blockDim.z};
		contexts[i].ctaid = {blockId.x, blockId.y, 0};
		contexts[i].nctaid = {kernel->gridDim().x, kernel->gridDim().y, kernel->gridDim().z};
		contexts[i].metadata = 0;
		contexts[i].local = localMemory + i * localMemorySize;
		contexts[i].shared = sharedMemory;
		contexts[i].parameter = parameterMemory;
		contexts[i].argument = parameterMemory;
		contexts[i].globallyScopedLocal = 0;
		contexts[i].externalSharedSize = 0;
		
		_setResumePoint(&contexts[i], i, startingSubkernel);
		_setResumeStatus(&contexts[i], i, analysis::KernelPartitioningPass::Thread_entry);
	}
}

void executive::DynamicMulticoreExecutive::execute(const ir::Dim3 &block) {
	report("DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y << ") kernel: '"
		<< kernel->name << "' for CTA size " << kernel->blockDim().size() << " threads");

	_initializeThreadContexts(block);

	analysis::KernelPartitioningPass::KernelGraph *kernelGraph = kernel->kernelGraph();

	DynamicTranslationCache::Translation *entryTranslation =
		DynamicExecutionManager::get().translationCache.getOrInsertTranslation(1, 
			kernelGraph->getEntrySubkernel());

	assert(entryTranslation); 
	
	int tid = 0;
	
	bool executing = true;
	int exitingThreads = 0;
	int iterations = 0;
	
	int maxIterations = 10;
	
	do {
		if (maxIterations && ++iterations >= maxIterations) {
			reportE(REPORT_SCHEDULE_OPERATIONS, " early termination (maxIterations = " << maxIterations << ")");
			break;
		}
	
	//   form warp
		LLVMContext *warp[1] = { &contexts[tid] };
	
		reportE(REPORT_SCHEDULE_OPERATIONS, "--------------");
		reportE(REPORT_SCHEDULE_OPERATIONS, "  executing thread " << tid);
			
		if (_getResumeStatus(&contexts[tid], tid) != analysis::KernelPartitioningPass::Thread_exit) {
		
		
			//   execute subkernel
			SubkernelId encodedSubkernel = _getResumePoint(&contexts[tid], tid);
			SubkernelId subkernelId = analysis::KernelPartitioningPass::ExternalEdge::getSubkernelId(encodedSubkernel);
			int warpSize = 1;
			unsigned int specialization = 0;
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "  encoded resume point: " << encodedSubkernel);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  mapped subkernel ID: " << subkernelId);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  fetching translation (warp size: " << warpSize << ")");
		
			DynamicTranslationCache::Translation *translation =
				DynamicExecutionManager::get().translationCache.getOrInsertTranslation(warpSize, 
					subkernelId, specialization);
		
			assert(translation);
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "  executing subkernel");
		
			translation->execute(warp);
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "  thread 0 exited with code "
				<< _getResumeStatus(&contexts[tid], tid) << " and resume point: " 
				<< _getResumePoint(&contexts[tid], tid));
	
			//   update contexts
			if (_getResumeStatus(&contexts[tid], tid) == analysis::KernelPartitioningPass::Thread_barrier) {
				++tid;
				executing = false;
				reportE(REPORT_SCHEDULE_OPERATIONS, " barriers not supported.");
			}
			else {
				// continue executing [for now, more sophisticated scheduler shortly]
			}
		}
		else {
			tid ++;
			++exitingThreads;
			if (exitingThreads == kernel->blockDim().size()) {
				executing = false;
			}
		}
		
		if (tid >= kernel->blockDim().size()) {
			tid = 0;
			exitingThreads = 0;
		}
	
	} while (executing);

  
	report("completed DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y  
		<< ") kernel: '" << kernel->name << "'");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::Metadata::Metadata() {

}

executive::DynamicMulticoreExecutive::Metadata::~Metadata() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////

