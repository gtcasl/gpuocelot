/*!	\file LLVMModuleManager.h
	\date Thursday September 23, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMModuleManager class
*/

#ifndef LLVM_MODULE_MANAGER_H_INCLUDED
#define LLVM_MODULE_MANAGER_H_INCLUDED

// Ocelot Includes
#include <ocelot/translator/interface/Translator.h>
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/interface/Thread.h>

// Standard Library Includes
#include <vector>

// Forward Declarations
namespace ir
{
	class Module;
	class PTXKernel;
}

namespace llvm
{
	class Module;
}

namespace executive
{

class LLVMContext;

/*! \brief A class that manages modules that are executed by LLVM kernels */
class LLVMModuleManager
{
public:
	typedef void (*Function)(LLVMContext*);
	typedef unsigned int FunctionId;
	typedef ExecutableKernel::TextureVector TextureVector;

public:
	/*! \brief Loads a module into the manager, kernels are now visible */
	static void loadModule(const ir::Module* m,
		translator::Translator::OptimizationLevel l, Device* device);

	/*! \brief Is a module loaded? */
	static bool isModuleLoaded(const std::string& moduleName);

	/*! \brief Gets the total number of functions in all modules */
	static unsigned int totalFunctionCount();

	/*! \brief unLoad module from the database, this invalidates all ids */
	static void unloadModule(const std::string& moduleName);

public:
	/*! \brief Associate a hydrazine thread with this manager, 
		allowing it to communicate */
	static void associate(hydrazine::Thread* thread);

	/*! \brief Get the id of the hydrazine thread */
	static hydrazine::Thread::Id id();
	
public:
	class ModuleDatabase;

	//! describes status of threads that have reached a subkernel exit point
	class ThreadDescriptor {
	public:
		enum ThreadExitType {
			Subkernel_exit = 0,
			Barrier_exit = 1,
			Kernel_exit = 2,
			Divergent_branch = 3,
			Convergent_branch = 4,
			ThreadExitType_unknown
		};
		
	public:
		char *localMemory;
		int targetSubkernelID;
		ir::Dim3 threadIdx;
		ThreadExitType type;
	};

	//! 
	class KernelAndTranslation
	{
	public:
		class MetaData
		{
		public:
			typedef std::unordered_map<ir::ControlFlowGraph::BasicBlock::Id, 
				ir::ControlFlowGraph::const_iterator> BlockIdMap;

		public:
			unsigned int sharedSize;
			unsigned int localSize;
			unsigned int parameterSize;
			unsigned int argumentSize;
			unsigned int constantSize;
			unsigned int warpSize;
			
		public:
			ThreadDescriptor *threadDescriptor;
			BlockIdMap           blocks;
			const ir::PTXKernel* kernel;
			Function             function;
			TextureVector        textures;
		};
	
	public:
		KernelAndTranslation(
			ir::PTXKernel* k = 0, 
			translator::Translator::OptimizationLevel level = translator::Translator::NoOptimization,
			const ir::PTXKernel* parent = 0, 
			FunctionId offset = 0,
			Device* device = 0,
			const ModuleDatabase* database = 0,
			int _ws=1);

	public:
		void               unload();
		MetaData*          metadata();
		const std::string& name() const;
	
	private:
		ir::PTXKernel*                            _kernel;
		llvm::Module*                             _module;
		translator::Translator::OptimizationLevel _optimizationLevel;
		MetaData*                                 _metadata;
		const ir::PTXKernel*                      _parent;
		FunctionId                                _offsetId;
		Device*                                   _device;
		const ModuleDatabase*                     _database;
		int 																			_warpSize;
	};

	typedef KernelAndTranslation::MetaData MetaData;

	class DatabaseMessage
	{
	public:
		enum Type
		{
			GetId,
			GetFunction,
			KillThread,
			Exception,
			Invalid
		};
	public:
		Type type;
	};

	class GetFunctionMessage : public DatabaseMessage
	{
	public:
		std::string moduleName;
		std::string kernelName;
		FunctionId  id;
		MetaData*   metadata;
		std::string errorMessage;
	};
	
public:
	typedef std::unordered_map<std::string, FunctionId> FunctionIdMap;
	typedef std::vector<KernelAndTranslation> KernelVector;
	
	class Module
	{
	public:
		Module(const KernelVector& kernels, FunctionId nextId);
	
	public:
		FunctionId getFunctionId(const std::string& kernelName) const;
		
		FunctionId lowId() const;
		FunctionId highId() const;
		
		bool empty() const;
		
		void shiftId(FunctionId nextId);
		
	private:
		FunctionIdMap  _ids;
	};

	typedef std::unordered_map<std::string, Module> ModuleMap;

	/*! \brief A thread safe-class for actually maintaining the modules */
	class ModuleDatabase : public hydrazine::Thread
	{
	public:
		/*! \brief Create and initialize the database */
		ModuleDatabase();
	
		/*! \brief Destroy the database */
		~ModuleDatabase();
	
		/*! \brief Load module into the database */
		void loadModule(const ir::Module* module,
			translator::Translator::OptimizationLevel l, Device* device);
	
		/*! \brief Is a module loaded? */
		bool isModuleLoaded(const std::string& moduleName);
	
		/*! \brief unLoad module from the database */
		void unloadModule(const std::string& moduleName);
		
		/*! \brief Gets the total number of functions in all modules */
		unsigned int totalFunctionCount() const;
	
	public:
		/*! \brief Get the id of a kernel by module and kernel name */
		FunctionId getFunctionId(const std::string& moduleName,
			const std::string& kernelName) const;

	private:
		/*! \brief The entry point to the thread */
		void execute();
	
	private:
		ModuleMap     _modules;
		KernelVector  _kernels;
		ir::Module    _barrierModule;
	};
	
private:
	static ModuleDatabase _database;
};

}

#endif

