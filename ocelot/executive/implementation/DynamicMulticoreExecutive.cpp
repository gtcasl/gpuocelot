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

//////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_BASE 0

#define REPORT_CTA_OPERATIONS 0						// called O(n), where n is the number of CTAs launched
#define REPORT_SCHEDULE_OPERATIONS 1			// scheduling events
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

////////////////////////////////////////////////////////////////////////////////////////////////////

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

std::ostream & operator<<(std::ostream &out, const executive::LLVMContext::Dimension &dim) {
	out << "(" << dim.x << ", " << dim.y << ", " << dim.z << ")";
	return out;
}
std::ostream & operator<<(std::ostream &out, const ir::Dim3 &dim) {
	out << "(" << dim.x << ", " << dim.y << ", " << dim.z << ")";
	return out;
}

namespace llvm { class Value; class Function; }
std::string String(llvm::Value *);
std::string String(llvm::Function *);

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::DynamicMulticoreExecutive(
	const executive::DynamicMulticoreKernel &_kernel, size_t _sharedMemorySize
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
	
	DynamicExecutionManager::get().translationCache.getTranslationVector(translationVector);
	
	reportE(REPORT_CTA_OPERATIONS, "DynamicMulticoreExecutve('" << _kernel.name 
		<< "', shared mem size: " << sharedMemorySize);
	reportE(REPORT_CTA_OPERATIONS, "  localMemorySize: " << localMemorySize);
	reportE(REPORT_CTA_OPERATIONS, "  paramMemorySize: " << parameterMemorySize);
	
	reportE(REPORT_CTA_OPERATIONS, " contexts = " << (void *)contexts);
	reportE(REPORT_CTA_OPERATIONS, " localMemory = " << (void *)localMemory 
		<< " (" << localMemorySize << " bytes)");
	reportE(REPORT_CTA_OPERATIONS, " sharedMemory = " << (void *)sharedMemory 
		<< " (" << sharedMemorySize << " bytes)");
	reportE(REPORT_CTA_OPERATIONS, " parameterMemory = " << (void *)parameterMemory 
		<< " (" << parameterMemorySize << " bytes)");
}

executive::DynamicMulticoreExecutive::~DynamicMulticoreExecutive() {

	reportE(REPORT_CTA_OPERATIONS, " contexts = " << (void *)contexts);
	reportE(REPORT_CTA_OPERATIONS, " localMemory = " << (void *)localMemory);
	reportE(REPORT_CTA_OPERATIONS, " sharedMemory = " << (void *)sharedMemory);
	reportE(REPORT_CTA_OPERATIONS, " parameterMemory = " << (void *)parameterMemory);

	delete [] contexts;
	delete [] localMemory;
	delete [] sharedMemory;
	delete [] parameterMemory;
}


void executive::DynamicMulticoreExecutive::_initializeThreadContexts(const ir::Dim3 &blockId) {

	const ir::Dim3 blockDim = kernel->blockDim();
	SubkernelId startingSubkernel = analysis::KernelPartitioningPass::ExternalEdge::getEncodedEntry(
		kernel->kernelGraph()->getEntrySubkernel(), 0);
	
	std::memset(localMemory, 0, localMemorySize * blockDim.size());
	
	reportE(REPORT_CTA_OPERATIONS, "DynamicMulticoreExecutive::_initializeThreadContexts(blockId = " 
		<< blockId << ") - blockDim = " << blockDim);
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
		contexts[i].constant = kernel->constantMemory();
		
		_setResumePoint(&contexts[i], startingSubkernel);
		_setResumeStatus(&contexts[i], analysis::KernelPartitioningPass::Thread_entry);
	}
	reportE(REPORT_CTA_OPERATIONS, "  startingSubkernel >> 16 = " << (startingSubkernel >> 16));
}

const executive::DynamicMulticoreExecutive::Translation *
	executive::DynamicMulticoreExecutive::_getOrInsertTranslation(int warpsize, SubkernelId subkernel, 
	unsigned int specialization) {

	int Log2WarpSize(int warpSize);
		
	int lgwarpsize = Log2WarpSize(warpsize);
	const Translation *translation = translationVector[lgwarpsize][subkernel];
	
	if (!translation) {
		translation = DynamicExecutionManager::get().translationCache.getOrInsertTranslation(warpsize, 
			subkernel, specialization);
		translationVector[lgwarpsize][subkernel] = translation;
		assert(translation && "Failed to fetch translation from translation cache");
	}
	
	return translation;
}

void executive::DynamicMulticoreExecutive::execute(const ir::Dim3 &block) {
	reportE(REPORT_SCHEDULE_OPERATIONS, 
		"DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y << ") kernel: '"
			<< kernel->name << "' for CTA size " << kernel->blockDim().size() << " threads");

	_initializeThreadContexts(block);
	
#if REPORT_LOCAL_MEMORY && REPORT_BASE
	reportE(REPORT_CTA_OPERATIONS, "Parameter memory: ");
	_emitParameterMemory(&contexts[0]);
#endif
	
	report(" executing block: " << block.x << ", " << block.y);
	
	_executeDefault(block);
	//_executeIterateSubkernelBarriers(block);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void executive::DynamicMulticoreExecutive::_executeDefault(const ir::Dim3 &block) {
	int tid = 0;
	
	int blockDimSize = kernel->blockDim().size();
	bool executing = true;
	int exitingThreads = 0;
	int iterations = 0;
	
	int maxIterations = 0;
	
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
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "  encoded resume point: 0x" << std::hex << encodedSubkernel << std::dec);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  subkernel: " << subkernelId);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  entry: 0x" << std::hex << entryId << std::dec);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  mapped subkernel ID: " << subkernelId);
			reportE(REPORT_SCHEDULE_OPERATIONS, "  fetching translation (warp size: " << warpSize << ")");
			
			const Translation *translation = _getOrInsertTranslation(warpSize, subkernelId, specialization);
	
			_setResumeStatus(&contexts[tid], analysis::KernelPartitioningPass::Thread_exit);
			contexts[tid].metadata = (char *)translation->metadata;
			static_cast<executive::MetaData*>(translation->metadata)->sharedSize = sharedMemorySize;
				
			reportE(REPORT_SCHEDULE_OPERATIONS, "  executing subkernel ");
			
			translation->execute(warp);
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "exited");
			
			reportE(REPORT_SCHEDULE_OPERATIONS, "  thread 0 exited with code "
				<< analysis::KernelPartitioningPass::toString(_getResumeStatus(&contexts[tid])) 
				<< " and resume point: 0x" << std::hex << _getResumePoint(&contexts[tid]) << std::dec);
	
			//   update contexts
			if (_getResumeStatus(&contexts[tid]) == analysis::KernelPartitioningPass::Thread_barrier) {
				++tid;
				reportE(REPORT_SCHEDULE_OPERATIONS, "   advancing to next thread: " << tid);
			}
			else {
				reportE(REPORT_SCHEDULE_OPERATIONS, "   executing same thread: " << tid);
			}
		}
		else {
			reportE(REPORT_SCHEDULE_OPERATIONS, "   thread " << tid << " exiting");
			tid ++;
			++exitingThreads;
			if (exitingThreads >= blockDimSize) {
				executing = false;
				reportE(REPORT_SCHEDULE_OPERATIONS, "   CTA exiting");
			}
		}
		
		if (tid >= blockDimSize) {
			tid = 0;
		}
	
	} while (executing);

	report("completed DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y 
		<< ") kernel: '" << kernel->name << "'");
}


void executive::DynamicMulticoreExecutive::_executeIterateSubkernelBarriers(const ir::Dim3 &block) {
	
	bool executing = true;
	int blockDimSize = kernel->blockDim().size();
	
	do {
		int exitedThreads = 0;
		int barrierThreads = 0;
		
		do {
		
			for (int tid = 0; tid < blockDimSize; ) {
				ThreadExitType status = _getResumeStatus(&contexts[tid]);
				if (status != analysis::KernelPartitioningPass::Thread_exit &&
					status != analysis::KernelPartitioningPass::Thread_barrier) {
			
					int warpsize = 1;
					
					SubkernelId warpEntryId = _getResumePoint(&contexts[tid]);
					for (int w = 1; tid + w < blockDimSize; ++w) {
						if (_getResumePoint(&contexts[tid + w]) == warpEntryId &&
							_getResumeStatus(&contexts[tid + w]) == status) {
							++warpsize;
						}
						else {
							break;
						}
					}
			
					reportE(REPORT_SCHEDULE_OPERATIONS, "warp: tid " << tid << " of size " << warpsize 
						<< " threads [subkernel " << std::hex << "0x" << warpEntryId << std::dec << "]");

					_executeWarp(&contexts[tid], warpsize);
				
					for (int i = 0; i < warpsize; i++) {
						if (_getResumeStatus(&contexts[tid + i]) == analysis::KernelPartitioningPass::Thread_barrier) {
							++barrierThreads;
						}
					}
				
					tid += warpsize;
				}
				else {
					++tid;
				}
			}
			
		} while (barrierThreads && barrierThreads < blockDimSize);
		
		for (int tid = 0; tid < blockDimSize; tid++) {
			ThreadExitType status = _getResumeStatus(&contexts[tid]);
			if (status == analysis::KernelPartitioningPass::Thread_exit) {
				++exitedThreads;
			}
			else if (status == analysis::KernelPartitioningPass::Thread_barrier) {
				_setResumeStatus(&contexts[tid], analysis::KernelPartitioningPass::Thread_entry);
			}
		}
		if (exitedThreads >= blockDimSize) {
			executing = false;
		}
	} while (executing);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void executive::DynamicMulticoreExecutive::_executeWarp(LLVMContext *_contexts, size_t threads) {

	//   execute subkernel
	SubkernelId encodedSubkernel = _getResumePoint(&_contexts[0]);
	SubkernelId subkernelId = analysis::KernelPartitioningPass::ExternalEdge::getSubkernelId(encodedSubkernel);
	int warpSize = 1;
	unsigned int specialization = 0;
	
	const Translation *translation = _getOrInsertTranslation(warpSize, subkernelId, specialization);

	static_cast<executive::MetaData*>(translation->metadata)->sharedSize = sharedMemorySize;
	
	for (size_t t = 0; t < threads; t++) {
		LLVMContext *warp[1] = { &_contexts[t] };
		warp[0]->metadata = (char *)translation->metadata;
		_setResumeStatus(warp[0], analysis::KernelPartitioningPass::Thread_exit);
		
		translation->execute(warp);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

