/*!
	\file DynamicMulticoreExecutive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 20, 2011
	\brief executes a kernel over one or more CTAs
*/

// C++ includes
#include <iomanip>

// Ocelot includes
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

#define REPORT_SCHEDULE_OPERATIONS 0			// scheduling events
#define REPORT_LOCAL_MEMORY 0							// display contents of local memory

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::SubkernelId 
	executive::DynamicMulticoreExecutive::_getResumePoint(const executive::LLVMContext *context) {
	
	const char *ptr = context->local;
	return *(executive::DynamicMulticoreExecutive::SubkernelId *)(ptr + 0);
}

void executive::DynamicMulticoreExecutive::_setResumePoint(const executive::LLVMContext *context, 
	SubkernelId subkernel) {

	char *ptr = context->local;
	*(executive::DynamicMulticoreExecutive::SubkernelId *)(ptr + 0) = subkernel;
}

executive::DynamicMulticoreExecutive::ThreadExitType 
	executive::DynamicMulticoreExecutive::_getResumeStatus(const executive::LLVMContext *context) {
	
	const char *ptr = context->local;
	return *(executive::DynamicMulticoreExecutive::ThreadExitType *)(ptr + 4);
}

void executive::DynamicMulticoreExecutive::_setResumeStatus(const executive::LLVMContext *context, 
	executive::DynamicMulticoreExecutive::ThreadExitType status) {

	char *ptr = context->local;
	*(executive::DynamicMulticoreExecutive::ThreadExitType *)(ptr + 4) = status;
}


void executive::DynamicMulticoreExecutive::_emitThreadLocalMemory(const LLVMContext *context) {
	for (size_t offset = 0; offset < localMemorySize; offset += 4) {
		std::cout << "[offset: " << std::setw(3) << std::setfill(' ') << offset << "]: 0x" 
			<< std::hex << std::setw(8) << std::setfill('0')
			<< *(unsigned int *)(&context->local[offset]) << std::dec;
			
		switch (offset) {
		case 0:
			std::cout << "  [resume point]";
			break;
		case 4:
			std::cout << "  [resume status]";
			break;
		case 8:
			std::cout << "  [spill area]";
			break;
		default:
			break;
		}
		std::cout << "\n";
	}
}

void executive::DynamicMulticoreExecutive::_emitParameterMemory(const LLVMContext *context) {
	for (size_t offset = 0; offset < parameterMemorySize; offset += 4) {
		std::cout << "[offset: " << std::setw(3) << std::setfill(' ') << offset << "]: 0x" 
			<< std::hex << std::setw(8) << std::setfill('0')
			<< *(unsigned int *)(&parameterMemory[offset]) << std::dec;
		std::cout << "\n";
	}
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
	
	parameterMemorySize = _kernel.argumentMemorySize();
	parameterMemory = new char[parameterMemorySize];
	
	_kernel.getArgumentBlock((unsigned char *)parameterMemory, parameterMemorySize);
	
	contexts = new LLVMContext[kernel->blockDim().size()];
	
	report("DynamicMulticoreExecutve('" << _kernel.name << "', shared mem size: " << sharedMemorySize);
	report("  localMemorySize: " << localMemorySize);
	report("  paramMemorySize: " << parameterMemorySize);
	
	report(" contexts = " << (void *)contexts);
	report(" localMemory = " << (void *)localMemory);
	report(" sharedMemory = " << (void *)sharedMemory);
	report(" parameterMemory = " << (void *)parameterMemory);
}

executive::DynamicMulticoreExecutive::~DynamicMulticoreExecutive() {

	report(" contexts = " << (void *)contexts);
	report(" localMemory = " << (void *)localMemory);
	report(" sharedMemory = " << (void *)sharedMemory);
	report(" parameterMemory = " << (void *)parameterMemory);

	delete [] contexts;
	delete [] localMemory;
	delete [] sharedMemory;
	delete [] parameterMemory;
}

static std::ostream & operator<<(std::ostream &out, const executive::LLVMContext::Dimension &dim) {
	out << "(" << dim.x << ", " << dim.y << ", " << dim.z << ")";
	return out;
}
static std::ostream & operator<<(std::ostream &out, const ir::Dim3 &dim) {
	out << "(" << dim.x << ", " << dim.y << ", " << dim.z << ")";
	return out;
}

void executive::DynamicMulticoreExecutive::_initializeThreadContexts(const ir::Dim3 &blockId) {

	const ir::Dim3 blockDim = kernel->blockDim();
	SubkernelId startingSubkernel = analysis::KernelPartitioningPass::ExternalEdge::getEncodedEntry(
		kernel->kernelGraph()->getEntrySubkernel(), 0);
	
	std::memset(localMemory, 0, localMemorySize * blockDim.size());
	
	report("DynamicMulticoreExecutive::_initializeThreadContexts(blockId = " << blockId << ") - blockDim = " << blockDim);
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
		
		_setResumePoint(&contexts[i], startingSubkernel);
		_setResumeStatus(&contexts[i], analysis::KernelPartitioningPass::Thread_entry);
		
		report("  created thread id " << contexts[i].tid);
	}
	report("  startingSubkernel >> 16 = " << (startingSubkernel >> 16));
}

void executive::DynamicMulticoreExecutive::execute(const ir::Dim3 &block) {
	report("DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y << ") kernel: '"
		<< kernel->name << "' for CTA size " << kernel->blockDim().size() << " threads");

	_initializeThreadContexts(block);
	
	int tid = 0;
	
	bool executing = true;
	int exitingThreads = 0;
	int iterations = 0;
	
	int maxIterations = 0;
	
#if REPORT_LOCAL_MEMORY && REPORT_BASE
	reportE(REPORT_SCHEDULE_OPERATIONS, "Parameter memory: ");
	_emitParameterMemory(&contexts[0]);
#endif
	
	do {
		if (maxIterations && ++iterations >= maxIterations) {
			reportE(REPORT_SCHEDULE_OPERATIONS, " early termination (maxIterations = " 
				<< maxIterations << ")");
				assert(0 && "Early termination");
			break;
		}
	
		LLVMContext *warp[1] = { &contexts[tid] };
			
		reportE(REPORT_SCHEDULE_OPERATIONS, "--------------");
		reportE(REPORT_SCHEDULE_OPERATIONS, "  executing thread " << tid);
			
		if (_getResumeStatus(&contexts[tid]) != analysis::KernelPartitioningPass::Thread_exit) {
		
			//   execute subkernel
			SubkernelId encodedSubkernel = _getResumePoint(&contexts[tid]);
			SubkernelId subkernelId = analysis::KernelPartitioningPass::ExternalEdge::getSubkernelId(encodedSubkernel);
			SubkernelId entryId = analysis::KernelPartitioningPass::ExternalEdge::getEntryId(encodedSubkernel);
			int warpSize = 1;
			unsigned int specialization = 0;
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "  encoded resume point: " << encodedSubkernel);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  subkernel: " << subkernelId);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  entry: " << entryId);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  mapped subkernel ID: " << subkernelId);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  fetching translation (warp size: " << warpSize << ")");
		
			DynamicTranslationCache::Translation *translation =
				DynamicExecutionManager::get().translationCache.getOrInsertTranslation(warpSize, 
					subkernelId, specialization);
		
			assert(translation);
	
			_setResumeStatus(&contexts[tid], analysis::KernelPartitioningPass::Thread_exit);
			contexts[tid].metadata = (char *)translation->metadata;
				
			reportE(REPORT_SCHEDULE_OPERATIONS, "  executing subkernel " << translation->name());
			
			translation->execute(warp);
			
#if REPORT_LOCAL_MEMORY  && REPORT_BASE
			reportE(REPORT_SCHEDULE_OPERATIONS, "Local memory: ");
			_emitThreadLocalMemory(warp[0]);
#endif
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "  thread 0 exited with code "
				<< _getResumeStatus(&contexts[tid]) << " and resume point: " 
				<< _getResumePoint(&contexts[tid]));
	
			//   update contexts
			if (_getResumeStatus(&contexts[tid]) == analysis::KernelPartitioningPass::Thread_barrier) {
				++tid;
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
		}
	
	} while (executing);

	report("completed DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y  
		<< ") kernel: '" << kernel->name << "'");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

