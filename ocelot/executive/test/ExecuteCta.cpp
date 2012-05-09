/*!
	\file ExecuteCta.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date May 8, 2012
	\brief stand-alone tool for compiling and executing externally defined functions as a CTA
*/

#include <cmath>
#include <ocelot/executive/interface/DynamicMulticoreExecutive.h>
#include <ocelot/executive/interface/DynamicTranslationCache.h>

////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////

class CTA {
public:
	CTA(const ir::Dim3 &_gridDim, const ir::Dim3 &_blockDim, const ir::Dim3 &_blockId, 
		size_t localSize, size_t sharedSize, size_t paramSize
	): gridDim(_gridDim), blockDim(_blockDim), blockId(_blockId), localMemory(0), 
		localMemorySize(localSize), sharedMemory(0), sharedMemorySize(sharedSize),
		parameterMemory(0), parameterMemorySize(paramSize)
	{
	
		int totalThreads = blockDim.size();
		contexts = new executive::LLVMContext[totalThreads];
		localMemory = new char[localMemorySize * totalThreads];
		sharedMemory = new char[sharedMemorySize];
		parameterMemory = new char [parameterMemorySize];
	};
	
	~CTA() {
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
	
	/*!
	
	*/
	void loadFunction(const std::string &object, const std::string &name) {
	
	}
	
	void execute() {
		
	}
	
protected:

	void setResumeStatus(const executive::LLVMContext *context, 
		executive::DynamicMulticoreExecutive::ThreadExitType status) {

		char *ptr = context->local;
		*(executive::DynamicMulticoreExecutive::ThreadExitType *)(ptr + 4) = status;
	}

	void executeWarp(executive::MetaData *metadata, executive::LLVMContext *contexts, 
		size_t threads, int warpSize, 
		executive::DynamicTranslationCache::ExecutableFunction function) {

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
};

////////////////////////////////////////////////////////////////////////////////////////////////////

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
	
	CTA cta(grid, block, blockId, localSize, sharedSize, paramSize);
	
	float *A_host;
	size_t bytes = N * sizeof(float);
	
	A_host = (float *)malloc(bytes);
	
	for (int i = 0; i < N; i++) {
		A_host[i] = (float)(i+1);
	}
	
	cta.setParam(0, (void *)A_host);
	cta.execute();
	
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
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

