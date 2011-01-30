/*! \file PassManager.h
	\date Thursday September 16, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the PassManager class
*/

#ifndef PASS_MANAGER_H_INCLUDED
#define PASS_MANAGER_H_INCLUDED

// Standard Library Includes
#include <map>
#include <string>

namespace ir
{
	//! Forward Declarations
	class Module;
}

namespace analysis
{
	//! Forward Declarations
	class Pass;
	
	/*! \brief A class to orchestrate the execution of many passes */
	class PassManager
	{
	public:
		/*! \brief The constructor creates an empty pass manager associated
			with an existing Module.  
			
			The module is not owned by the PassManager.
			
			\param module The module that this manager is associated with.
		*/
		explicit PassManager(ir::Module* module);
		
	public:
		/*! \brief Adds a pass that needs to be eventually run
		
			The pass is not owned by the manager and must not be deallocated
			before it is run by the manager.
		
			\param pass The pass being added
		 */
		void addPass(Pass& pass);
		
		/*! \brief Clears all added passes */
		void clear();
		
		/*! \brief Deletes all added passes */
		void destroyPasses();
		
	public:
		/*! \brief Runs passes on a specific Kernel contained in the module.
		
			\param name The name of the kernel to run all passes on.
		*/
		void runOnKernel(const std::string& name);
		
		/*! \brief Runs passes on the entire module. */
		void runOnModule();
		
	private:
		typedef std::multimap<int, Pass*, std::greater<int>> PassMap;
		
	private:
		PassMap     _passes;
		ir::Module* _module;
	};
}

#endif

