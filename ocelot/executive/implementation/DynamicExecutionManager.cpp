/*!
	\file DynamicExecutionManager.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 21, 2011
	\brief singleton instance of dynamic execution manager for multicore CPU backend
*/

// C++ and other libraries
#include <pthread.h>
#include <fstream>
#include <chrono>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/executive/interface/DynamicMulticoreDevice.h>
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

#define REPORT_BASE 0

////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_SUBKERNEL_COVERAGE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

// This flag choose two modes: create worker threads once which last the duration of the program, or
// create them for every kernel then let them exit. It appears that barriers are slower than thread
// creation on this machine.
#define SPAWN_THREADS_ONCE 0

void * executionManagerLightweightThread(void *args) {
	
	const WorkerThreadArgs *arguments = static_cast<const WorkerThreadArgs *>(args);
	
	int gridDimy = arguments->kernel->gridDim().y;
	int gridDimx = arguments->kernel->gridDim().x;
	
	if (arguments->threadId < gridDimx * gridDimy) {
		// start executing	
		executive::DynamicMulticoreExecutive executive(*arguments->kernel, arguments->sharedMemorySize);
		for (int blockId = arguments->threadId; blockId < gridDimx * gridDimy; blockId += arguments->pitch) {
			executive.execute(ir::Dim3(blockId % gridDimx, blockId / gridDimx, 0));
		}
	}
	
	return 0;
}

void *executionManagerWorkerThread(void *args) {

	volatile WorkerThreadArgs *arguments = static_cast< WorkerThreadArgs *>(args);
	
	do {
	
		// wait for launch signal
		pthread_barrier_wait(arguments->launchBarrier);
	
		if (arguments->kernel) {
			int gridDimy = arguments->kernel->gridDim().y;
			int gridDimx = arguments->kernel->gridDim().x;
	
			if (arguments->threadId < gridDimx * gridDimy) {
				// start executing	
				executive::DynamicMulticoreExecutive executive(*arguments->kernel, arguments->sharedMemorySize);
				for (int blockId = arguments->threadId; blockId < gridDimx * gridDimy; blockId += arguments->pitch) {
					executive.execute(ir::Dim3(blockId % gridDimx, blockId / gridDimx, 0));
				}
			}
		
			pthread_barrier_wait(arguments->finishBarrier);
		}
	} while (arguments->kernel);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicExecutionManager executive::DynamicExecutionManager::instance;

executive::DynamicExecutionManager & executive::DynamicExecutionManager::get() {
	return instance;
}

executive::DynamicExecutionManager::DynamicExecutionManager(): translationCache(this) {
	report("DynamicExecutionManager()");
#if SPAWN_THREADS_ONCE
	int workerThreads = api::OcelotConfiguration::get().executive.workerThreadLimit;
	
	// spawn worker threads
	pthread_barrier_init(&_launchBarrier, 0, workerThreads + 1);
	pthread_barrier_init(&_finishBarrier, 0, workerThreads + 1);
	
	for (int i = 0; i < workerThreads; i++) {
		arguments[i].launchBarrier = &_launchBarrier;
		arguments[i].finishBarrier = &_finishBarrier;
		pthread_create(&threads[i], 0, executionManagerWorkerThread, &arguments[i]);
	}
#endif
}

executive::DynamicExecutionManager::~DynamicExecutionManager() {
	report("~DynamicExecutionManager()");

#if SPAWN_THREADS_ONCE
	int workerThreads = api::OcelotConfiguration::get().executive.workerThreadLimit;
	for (int i = 0; i < workerThreads; i++) {
		arguments[i].kernel = 0;
	}
	pthread_barrier_wait(&_launchBarrier);
	for (int i = 0; i < workerThreads; i++) {
		void *valuePtr = 0;
		pthread_join(threads[i], &valuePtr);
	}
#endif
}


void executive::DynamicExecutionManager::launch(executive::DynamicMulticoreKernel &kernel, 
	size_t sharedMemorySize) {
	
	report("DynamicExecutionManager::launch() - dynamic sharedMemorySize = " << sharedMemorySize);

	translationCache.loadModule(kernel.module, static_cast<executive::DynamicMulticoreDevice*>(kernel.device));
	
	// make the kernel graph available to the dynamic translation cache if need be
	translationCache.registerKernel(&kernel);
	sharedMemorySize += kernel.totalSharedMemorySize();
	
	int workerThreads = api::OcelotConfiguration::get().executive.workerThreadLimit;

	report(" launching grid " << kernel.gridDim().x << " x " << kernel.gridDim().y 
		<< " on " << workerThreads << " threads");
	
	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::milliseconds milliseconds;

	Clock::time_point t0 = Clock::now();
		
	if (workerThreads == 1) {
	
		// start executing in main thread
		report("  sharedMemorySize() = " << kernel.sharedMemorySize());
		report("  externSharedMemorySize() = " << kernel.externSharedMemorySize());
		report("  totalSharedMemorySize() = " << kernel.totalSharedMemorySize());
	
		DynamicMulticoreExecutive executive(kernel, sharedMemorySize);
	
		for (int blockIdy = 0; blockIdy < kernel.gridDim().y; blockIdy++) {
			for (int blockIdx = 0; blockIdx < kernel.gridDim().x; blockIdx++) {
				report("Executing block " << blockIdx << ", " << blockIdy);
			
				executive.execute(ir::Dim3(blockIdx, blockIdy, 1));
			}
		}
	}
	else {
		//
		// spawn worker threads and execute subset of partitions in these
		//
		assert(workerThreads <= MaxThreadCount && "Too many worker threads");
		
		for (int i = 0; i < workerThreads; i++) {
			arguments[i].sharedMemorySize = sharedMemorySize;
			arguments[i].kernel = &kernel;
			arguments[i].pitch = workerThreads;
			arguments[i].threadId = i;
#if !SPAWN_THREADS_ONCE
			pthread_create(&threads[i], 0, executionManagerLightweightThread, &arguments[i]);
#endif
		}
#if SPAWN_THREADS_ONCE
		pthread_barrier_wait(&_launchBarrier);
		pthread_barrier_wait(&_finishBarrier);
#else
		for (int i = 0; i < workerThreads; i++) {
			void *valuePtr = 0;
			pthread_join(threads[i], &valuePtr);
		}
#endif
	}
	Clock::time_point t1 = Clock::now();
	
	if (REPORT_SUBKERNEL_COVERAGE) {
		milliseconds ms = std::chrono::duration_cast<milliseconds>(t1 - t0);
		_reportSubkernelCoverage(kernel, ms.count());
	}
}

// emma was here. :-)

////////////////////////////////////////////////////////////////////////////////////////////////////

static std::ostream & operator<<(std::ostream &out, const ir::Dim3 &dim) {
	out << dim.x << ", " << dim.y << ", " << dim.z;
	return out;
}

void executive::DynamicExecutionManager::_reportSubkernelCoverage(
	executive::DynamicMulticoreKernel &kernel, double runtime) {
	
	typedef DynamicTranslationCache::SubkernelId SubkernelId;
	
	// visit all the subkernels, and record which ones have translations in the code cache
	std::unordered_map< SubkernelId, std::set<int> > translations;
	translationCache.getCachedSubkernels(translations, kernel.module->path(), kernel.name);
	
	DynamicMulticoreKernel::SubkernelIdRange subkernelIdRange = kernel.getSubkernelIdRange();
	
	// assumes warp sizes that are powers of 2 from 1 to warpSize implied by config
	std::ofstream file("subkernelCoverage.json", std::ios_base::app);
	const char *app = getenv("APPNAME");
	if (!app) {
		app = "Unknown Application";
	}
	file << "{ \n   \"application\": \"" << app << "\", \"kernel\": \"" << kernel.name 
		<< "\", \"launch\": " << kernel.getLaunchCount() << ",\n   \"range\": [" << subkernelIdRange.first 
		<< ", " << subkernelIdRange.second << "]" << ", \"runtime\": " << runtime
		<< ", \"gridDim\": [" << kernel.gridDim() << "], \"blockDim\": [" << kernel.blockDim() << "]"
		<< ",\n   \"workerThreads\": " << api::OcelotConfiguration::get().executive.workerThreadLimit 
		<< ", \"maxWarpSize\": " << api::OcelotConfiguration::get().executive.warpSize
		<< ", \"partitioning\": \"" << analysis::KernelPartitioningPass::toString(
			(analysis::KernelPartitioningPass::PartitioningHeuristic)
				api::OcelotConfiguration::get().executive.partitioningHeuristic ) << "\""
		<< ",\n   \"coverage\": {\n";
	
	size_t skCounter = 0;
	for (SubkernelId start = subkernelIdRange.first; start <= subkernelIdRange.second; ++start) {
		auto sk_it = translations.find(start);
		file << (skCounter++ ? "," : "") << "  \"" << sk_it->first << "\": [";
		if (sk_it != translations.end()) {
			int wsIdx = 0;
			for (auto ws_it = sk_it->second.begin(); ws_it != sk_it->second.end(); ++ws_it) {
				file << (wsIdx++ ? ", " : "") << *ws_it;
			}
		}
		file << "]";
	}
	
	file << "\n  }\n},\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

