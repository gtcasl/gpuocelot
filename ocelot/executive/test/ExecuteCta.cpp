/*!
	\file ExecuteCta.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date May 8, 2012
	\brief stand-alone tool for compiling and executing externally defined functions as a CTA
*/

#include <cmath>
#include <sstream>
#include <ocelot/executive/interface/DynamicMulticoreExecutive.h>
#include <ocelot/executive/interface/DynamicTranslationCache.h>

////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void _subkernel_convergence_1_opt3_ws4(executive::LLVMContext *);
extern "C" void _subkernel_convergence_1_opt3_ws8(executive::LLVMContext *);

////////////////////////////////////////////////////////////////////////////////////////////////////

typedef executive::DynamicTranslationCache::ExecutableFunction ExecutableFunction;

struct TranslatedFunction {
	TranslatedFunction(ExecutableFunction _func, int ws): function(_func), warpSize(ws) { }
	bool valid() const { return function != 0; }
	
	ExecutableFunction function;
	int warpSize;
};

class Binaries {
public:

	static TranslatedFunction get(const std::string &base, int warpsize) {
		std::stringstream ss;
		ss << base << "_ws" << warpsize;
		return TranslatedFunction(get(ss.str()), warpsize);
	}

	static ExecutableFunction get(const std::string &str) {
		if (str == "_subkernel_convergence_1_opt3_ws4") {
			return _subkernel_convergence_1_opt3_ws4;
		}
		if (str == "_subkernel_convergence_1_opt3_ws8") {
			std::cout << "warp size of 8" << std::endl;
			return _subkernel_convergence_1_opt3_ws8;
		}
		std::cerr << "failed to return function" << std::endl;
		return 0;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class CTA {
public:
	
public:
	CTA(const ir::Dim3 &_gridDim, const ir::Dim3 &_blockDim, const ir::Dim3 &_blockId, 
		size_t localSize, size_t sharedSize, size_t paramSize
	): gridDim(_gridDim), blockDim(_blockDim), blockId(_blockId), localMemory(0), 
		localMemorySize(localSize), sharedMemory(0), sharedMemorySize(sharedSize),
		parameterMemory(0), parameterMemorySize(paramSize)
	{
	
		totalThreads = blockDim.size();
		contexts = new executive::LLVMContext[totalThreads];
		localMemory = new char[localMemorySize * totalThreads];
		sharedMemory = new char[sharedMemorySize];
		parameterMemory = new char [parameterMemorySize];
		
		metadata = new executive::DynamicMulticoreExecutive::Metadata;
		initializeContexts();
	};
	
	~CTA() {
		delete metadata;
		delete [] parameterMemory;
		delete [] sharedMemory;
		delete [] localMemory;
		delete [] contexts;
	}
	
	void setParam(size_t offset, size_t size, const void *value) {
		std::memcpy(parameterMemory + offset, value, size);
	}
	
	void setParam(size_t offset, int value) {
		setParam(offset, sizeof(int), (void *)&value);
	}
	
	void setParam(size_t offset, void *value) {
		setParam(offset, sizeof(void *), (void *)&value);
	}
	
	void setParam(size_t offset, float value) {
		setParam(offset, sizeof(float), (void *)&value);
	}
	
	void execute(ExecutableFunction function, int warpSize) {
		executeWarp(metadata, contexts, totalThreads, warpSize, function);
	}
	
	void execute(TranslatedFunction function) {
		execute(function.function, function.warpSize);
	}
	
protected:

	void setResumeStatus(const executive::LLVMContext *context, 
		executive::DynamicMulticoreExecutive::ThreadExitType status) {

		char *ptr = context->local;
		*(executive::DynamicMulticoreExecutive::ThreadExitType *)(ptr + 4) = status;
	}
	
	void initializeContexts() {
		for (int tid = 0; tid < totalThreads; tid++) {
			contexts[tid].tid.x = tid;
			contexts[tid].tid.y = 0;
			contexts[tid].tid.z = 0;
			contexts[tid].ntid.x = blockDim.x;
			contexts[tid].ntid.y = blockDim.y;
			contexts[tid].ntid.z = blockDim.z;
			contexts[tid].ctaid.x = blockId.x;
			contexts[tid].ctaid.y = blockId.y;
			contexts[tid].ctaid.z = blockId.z;
			contexts[tid].nctaid.x = gridDim.x;
			contexts[tid].nctaid.y = gridDim.y;
			contexts[tid].nctaid.z = gridDim.z;
			contexts[tid].local = &localMemory[localMemorySize * tid];
			contexts[tid].shared = sharedMemory;
			contexts[tid].parameter = parameterMemory;
			contexts[tid].argument = parameterMemory;
			contexts[tid].globallyScopedLocal = 0;
			contexts[tid].metadata = (char *)metadata;
		}
	}

	void executeWarp(executive::MetaData *metadata, executive::LLVMContext *contexts, 
		size_t threads, int warpSize, 
		ExecutableFunction function) {

		//   execute subkernel
		for (size_t startThread = 0; startThread < threads; ) {
	
			if (metadata) {
				metadata->sharedSize = sharedMemorySize;
			}
		
			executive::LLVMContext *warp = &contexts[startThread];

			for (int t = 0; t < warpSize; t++) {
				warp[t].metadata = (char *)metadata;
				setResumeStatus(&warp[t], analysis::KernelPartitioningPass::Thread_exit);
			}
		
			function(warp);
			startThread += warpSize;
		}
	}
	
protected:

	ir::Dim3 gridDim;
	ir::Dim3 blockDim;
	ir::Dim3 blockId;

	char *localMemory;
	size_t localMemorySize;
	
	char *sharedMemory;
	size_t sharedMemorySize;
	
	char *parameterMemory;
	size_t parameterMemorySize;
	
	executive::LLVMContext *contexts;
	int totalThreads;
	
	executive::DynamicMulticoreExecutive::Metadata *metadata;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

#undef report
#define report(x) { std::cout << x << std::endl; }

/*!

*/
bool executeTestConvergence() {
	const int N = 8;
	
	ir::Dim3 grid(1,1,1);
	ir::Dim3 block(N,1,1);
	ir::Dim3 blockId(0,0,0);
	
	size_t localSize = 8;
	size_t sharedSize = 0;
	size_t paramSize = sizeof(float*);
	
	float *A_host;
	size_t bytes = N * sizeof(float);
	
	A_host = (float *)malloc(bytes);
	
	for (int i = 0; i < N; i++) {
		A_host[i] = (float)(i+1);
	}
		
	CTA cta(grid, block, blockId, localSize, sharedSize, paramSize);
	
	cta.setParam(0, (void *)A_host);
	
	TranslatedFunction function = Binaries::get("_subkernel_convergence_1_opt3", 8);
	
	if (function.valid()) {
		cta.execute(function);
	}
	
	int errors = 0;
	for (int i = 0; (errors < 5) && i < N; i++) {
		float expected = 2.0f * i + 1.0f;
		float got = A_host[i];
		if (fabs(expected - got) > 0.001f) {
			++errors;
			printf("error [%d] - expected: %f, got %f\n", i, expected, got);
		}
	}
	
	printf("Pass/Fail : %s\n", (errors ? "Fail":"Pass"));
	
	delete A_host;
	
	return (errors ? false : true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	executeTestConvergence();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

