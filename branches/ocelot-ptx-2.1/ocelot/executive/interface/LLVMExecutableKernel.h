/*! \file LLVMExecutableKernel.h
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMRuntime class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_H_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_H_INCLUDED

#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/Texture.h>
#include <ocelot/executive/interface/LLVMContext.h>
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <ocelot/translator/interface/Translator.h>
#include <hydrazine/interface/Thread.h>

#include <boost/thread.hpp>

#include <stack>

namespace llvm
{
	class ExecutionEngine;
	class Module;
	class Context;
}

namespace executive
{
	/*! \brief Executes an LLVMKernel using the LLVM JIT */
	class LLVMExecutableKernel : public executive::ExecutableKernel
	{
		private:
			/*! \brief A map from a variable identifier to its allocation */
			typedef std::unordered_map< std::string, size_t > AllocationMap;
			/*! \brief A type for referring to a specific PTX thread */
			typedef unsigned int ThreadContext;
			/*! \brief A function pointer to the translated kernel */
			typedef unsigned int (*Function)( LLVMContext* );
			
			/*! \brief A class for managing global llvm state */
			class LLVMState
			{
				public:
					/*! \brief LLVM module */
					llvm::Module* module;
					/*! \brief LLVM JIT Engine */
					llvm::ExecutionEngine* jit;

				public:
					/*! \brief Build the jit */
					LLVMState();
					/*! \brief Destroy the jit */
					~LLVMState();

				public:
					/*! \brief Initialize the jit */
					void initialize();
			};
			
			/*! \brief Used as a synchronization point for atomic operations */
			class AtomicOperationCache
			{
				private:
					/*! \brief Controls access to the cache */
					boost::mutex _mutex;
				
				public:
					/*! \brief Create the mutex */
					AtomicOperationCache();
					/*! \brief Destroy the mutex */
					~AtomicOperationCache();
				
				public:
					/*! \brief Locks access to the cache */
					void lock();
					/*! \brief Unlocks the cache */
					void unlock();
			};
			
			/*! \brief A worker thread executes a subset of CTAs in a kernel */
			class Worker : public hydrazine::Thread
			{
				public:
					/*! \brief A message to the thread */
					class Message
					{
						public:
							/*! \brief A type for determining 
								what kind of message is being sent */
							enum Type
							{
								Kill,
								LaunchKernelWithBarriers,
								LaunchKernelWithoutBarriers,
								Acknowledgement,
								Invalid
							};
							
						public:
							/*! \brief The type of message to the thread */
							Type type;
							/*! \brief The LLVM code being executed */
							Function function;
							/*! \brief The context being executed */
							LLVMContext* context;
							/*! \brief The begining cta of the grid */
							unsigned int begin;
							/*! \brief The ending cta of the grid */
							unsigned int end;
							/*! \brief The step */
							unsigned int step;
							/*! \brief The resume point offset */
							unsigned int resumePointOffset;
							
						public:
							Message( Type t = Invalid, Function f = 0,
								LLVMContext* c = 0, 
								unsigned int begin = 0,
								unsigned int end = 0,
								unsigned int step = 0,
								unsigned int r = 0 );
					};
			
				private:
					/*! \brief This is the 'main' function for the worker */
					void execute();
					
					/*! \brief Launch a series of ctas with barriers */
					void launchKernelWithBarriers( Function f, LLVMContext* c, 
						unsigned int begin,
						unsigned int end,
						unsigned int step,
						unsigned int rp );

					/*! \brief Launch a series of ctas without barriers */
					void launchKernelWithoutBarriers( Function f, 
						LLVMContext* c, 
						unsigned int begin,
						unsigned int end,
						unsigned int step );
					
					/*! \brief Launch a specific cta with barriers */
					void launchCtaWithBarriers( Function f, LLVMContext* c, 
						unsigned int rp );

					/*! \brief Launch a specific cta without barriers */
					void launchCtaWithoutBarriers( Function f, LLVMContext* c );
			};
			
			/*! \brief Controls the execution of worker threads */
			class ExecutionManager
			{
				private:
					/*! \brief A vector of created threads */
					typedef std::vector< Worker > WorkerVector;
					/*! \brief A vector of LLVM contexts */
					typedef std::vector< LLVMContext > ContextVector;
					/*! \brief A vector of messages */
					typedef std::vector< Worker::Message > MessageVector;
			
				private:
					/*! \brier The currently active worker threads */
					WorkerVector _workers;
					
					/*! \brief One context for each worker */
					ContextVector _contexts;
					
					/*! \brief One message for each worker */
					MessageVector _messages;
					
					/*! \brief The max threads per CTA */
					unsigned int _maxThreadsPerCta;
			
				public:
					/*! \brief The constructor boots up the workers */
					ExecutionManager();
					/*! \brief The destructor tears down the workers */
					~ExecutionManager();
					
				public:
					/*! \brief Launches a kernel on a grid using a context */
					void launch( Function f, LLVMContext* context, 
						bool barriers, unsigned int resumePointOffset, 
						unsigned int externalSharedMemory );
					
					/*! \brief Changes the number of worker threads */
					void setThreadCount( unsigned int threads );
					
					/*! \brief Changes the max number of threads per cta */
					void setMaxThreadsPerCta( unsigned int threads );

					/*! \brief Clears all active threads */
					void clear();
					
					/*! \brief Gets the current number of threads */
					unsigned int threads() const;
			};
		
		public:
			/*! \brief A class of opaque thread visible state */
			class OpaqueState
			{
				public:
					/*! \brief A map from a basic block id to the block */
					typedef std::unordered_map< 
						ir::ControlFlowGraph::BasicBlock::Id, 
						ir::ControlFlowGraph::const_iterator > BlockIdMap;
			
				public:
					/*! \brief Texture variables */
					TextureVector textures;
					/*! \brief Clock timer */
					hydrazine::Timer timer;
					/*! \brief Debugging information for blocks */
					BlockIdMap blocks;
					/*! \brief Atomic operation cache */
					AtomicOperationCache* cache;
					/*! \brief A reference to the kernel */
					const LLVMExecutableKernel* kernel;
					
				public:
					/*! \brief Starts the timer on creation */
					OpaqueState();
			};

		private:
			/*! \brief Contains the LLVM JIT for all LLVM kernels */
			static LLVMState _state;
			/*! \brief Contains the ExecutionManager for all LLVM kernels */
			static ExecutionManager _manager;
		
		private:
			/*! \brief The memory requirements and execution context */
			LLVMContext _context;
	
		private:
			/*! \brief LLVM module */
			llvm::Module* _module;
			/*! \brief The translated function */
			Function _function;
			/*! \brief The stored ptx kernel used for translation */
			ir::PTXKernel* _ptx;
			/*! \brief Does this kernel require barrier support? */
			bool _barrierSupport;
			/*! \brief The barrier resume point variable */
			std::string _resumePoint;
			/*! \brief The resume point offset */
			unsigned int _resumePointOffset;
			/*! \brief Constant memory mapping */
			AllocationMap _constants;
			/*! \brief Opaque state */
			OpaqueState _opaque;
			/*! \brief Optimization level for this kernel */
			translator::Translator::OptimizationLevel _optimizationLevel;
			/*! \brief Cache atomics from different threads */
			AtomicOperationCache _cache;
		
		private:
			/*! \brief Determine the padding required to satisfy alignment */
			static unsigned int _pad( size_t& size, unsigned int alignment );

		public:
			/*! \brief Get a string representation of a thread id */
			static std::string threadIdString( const LLVMContext& c );
			/*! \brief Get a string representation of a thread id */
			static unsigned int threadId( const LLVMContext& c );
			/*! \brief Optimize an llvm module using standard passes */
			static void _optimizeLLVMFunction( llvm::Module* module, 
				unsigned int level, bool space );
			
		private:
			/*! \brief Run various PTX optimizer passes on the kernel */
			void _optimizePtx();
			
			/*! \brief Create the LLVM module from the code */
			void _translateKernel();
			
			/*! \brief Run various LLVM optimizer passes on the kernel */
			void _optimize();
						
			/*! \brief Allocate parameter memory */
			void _allocateParameterMemory( );

			/*! \brief Allocate shared memory */
			void _allocateSharedMemory( );
			
			/*! \brief Allocate global memory */
			void _allocateGlobalMemory( );
			
			/*! \brief Allocate local memory */
			void _allocateLocalMemory( );
			
			/*! \brief Allocate constant memory */
			void _allocateConstantMemory( );
			
			/*! \brief Allocate texture memory */
			void _allocateTextureMemory( );
			
			/*! \brief Scan the kernel and determine memory requirements */
			void _allocateMemory( );

			/*! \brief Reload global memory */
			void _updateGlobalMemory( );

			/*! \brief Reload constant memory */
			void _updateConstantMemory( );

		private:
			/*! \brief Build debugging information */
			void _buildDebuggingInformation();

		public:
			/*! \brief Creates a new instance of the runtime bound to a kernel*/
			LLVMExecutableKernel( ir::Kernel& kernel, 
				executive::Device* d = 0,
				translator::Translator::OptimizationLevel 
				l = translator::Translator::NoOptimization);
			/*! \brief Clean up the runtime */
			~LLVMExecutableKernel();

		public:
			/*! \brief Launch a kernel on a 2D grid */
			void launchGrid( int width, int height );
			/*! \brief Sets the shape of a cta in the kernel */
			void setKernelShape( int x, int y, int z );
			/*! \brief Declare an amount of external shared memory */
			void setExternSharedMemorySize( unsigned int bytes );
			/*! \brief Describes the device used to execute the kernel */
			void setWorkerThreads( unsigned int threadLimit );
			/*! \brief Reload parameter memory */
			void updateParameterMemory();
			/*! \brief Indicate that other memory has been updated */
			void updateMemory();
			/*! \brief Get a vector of all textures references by the kernel */
			TextureVector textureReferences() const;

		public:
			/*!	adds a trace generator to the EmulatedKernel */
			void addTraceGenerator(trace::TraceGenerator *generator);
			/*!	removes a trace generator from an EmulatedKernel */
			void removeTraceGenerator(trace::TraceGenerator *generator);
			
		public:
			/*! \brief Get the number of threads per cta */
			unsigned int threads() const;
			/*! \brief Get the local id of the current thread */
			unsigned int threadId() const;
			/*! \brief Determine the location of a given PTX statement 
				in the original source file */
			std::string location(unsigned int statement) const;
			/*! \brieg Get the instruction contained in a given statement */
			std::string instruction(unsigned int statement) const;

	};
}

#endif

