/*!	\file LLVMModuleManager.h
	\date Thursday September 23, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMModuleManager class
*/

#ifndef LLVM_MODULE_MANAGER_H_INCLUDED
#define LLVM_MODULE_MANAGER_H_INCLUDED

// Hydrazine Includes
#include <hydrazine/interface/Thread.h>

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

public:
	/*! \brief Loads a module into the manager, kernels are now visible */
	static void loadModule(const ir::Module* m);

	/*! \brief Is a module loaded? */
	static bool isModuleLoaded(const std::string& moduleName);

	/*! \brief Gets the corresponding id of a kernel in a specific module */
	static FunctionId getFunctionId(const std::string& moduleName,
		const std::string& kernelName);

	/*! \brief Gets a completely translated function from the manager */
	static Function getFunction(const FunctionId& id);

	/*! \brief Gets the total number of functions in all modules */
	static unsigned int totalFunctionCount();

	/*! \brief unLoad module from the database */
	static void unloadModule(const std::string& moduleName);

public:
	class KernelAndTranslation
	{
	public:
		KernelAndTranslation(ir::PTXKernel* k = 0, Function f = 0);
	
	public:
		ir::PTXKernel* kernel;
		Function       function;
		llvm::Module*  module;
	};
		
private:
	typedef std::unordered_map<std::string, 
		KernelAndTranslation> PTXKernelMap;
	
	class Module
	{
	public:
		Module(const ir::Module* m);
				
	public:
		ir::PTXKernel* getKernel(const std::string& kernelName);
		Function getFunction(const std::string& kernelName);
		void unload();
		unsigned int kernelCount() const;
		
	private:
		PTXKernelMap  _kernels;
	};

	typedef std::map<std::string, Module> ModuleMap;

	/*! \brief A thread safe-class for actually maintaining the modules */
	class ModuleDatabase : public hydrazine::Thread
	{
	public:
		/*! \brief Create and initialize the database */
		ModuleDatabase();
	
		/*! \brief Destroy the database */
		~ModuleDatabase();
	
		/*! \brief Load module into the database */
		void loadModule(const ir::Module* module);
	
		/*! \brief Is a module loaded? */
		bool isModuleLoaded(const std::string& moduleName);
	
		/*! \brief unLoad module from the database */
		void unloadModule(const std::string& moduleName);
		
		/*! \brief Get the id of a translated function from the database */
		FunctionId getFunctionId(const std::string& moduleName,
			const std::string& functionName);
	
		/*! \brief Gets the total number of functions in all modules */
		unsigned int totalFunctionCount() const;

		/*! \brief Get the translated function from the database */
		Function getFunction(const FunctionId& id);

	private:
		/*! \brief The entry point to the thread */
		void execute();
	
	private:
		ModuleMap                     _modules;
		unsigned int                  _kernelCount;
	};
	
	static ModuleDatabase _database;
};

}

#endif

