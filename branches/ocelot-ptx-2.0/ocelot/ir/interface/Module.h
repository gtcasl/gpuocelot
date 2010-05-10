/*! \file Module.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief declares a Module loadable from a PTX source file
*/

#ifndef IR_MODULE_H_INCLUDED
#define IR_MODULE_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

#include <ocelot/ir/interface/Texture.h>
#include <ocelot/ir/interface/Instruction.h>
#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/Global.h>

namespace executive { class Executive; }

namespace ir {

	class Module {
	public:
		/*!	\brief Map from texture variable names to objects */
		typedef std::map< std::string, Texture > TextureMap;

		/*! \brief Typedef for a vector of PTXStatements */
		typedef std::vector< PTXStatement > StatementVector;

		typedef std::map< std::string, Kernel * > KernelMap;

		/*! \brief Map from unique identifier to global variable */
		typedef std::map< std::string, Global > GlobalMap;
				
	public:

		/*! Given a path to a PTX source file, construct the Module, 
			load and parse the PTX file,
			and extract kernels into Kernel objects
		*/
		Module(const std::string& path);

		/*! Given a stream constaining a PTX file, parse the PTX file,
			and extract kernels into Kernel objects
		*/
		Module(std::istream& source, 
			const std::string& path = "::unknown path::");

		/*! Construct a Module from a name and a vector of PTXStatements */
		Module(const std::string& , const StatementVector&);

		/*!	Construct an empty module */
		Module();

		/*!	Deconstruct a module */
		~Module();
		
		/*! Write the module to an assembly file using statements */
		void write(std::ostream& stream) const;

		/*! \brief Write the module to an assembly file from the IR */
		void writeIR(std::ostream& stream) const;

		/*! \brief Creates IR data structures for PTX kernels */
		void createDataStructures();

		/*!	Deletes everything associated with this particular module */
		void unload();

		/*!	Unloads module and loads PTX source file in given path */
		bool load(std::string path);

		/*!	Unloads module and loads PTX source file in given stream */
		bool load(std::istream& source,
			const std::string& path = "::unknown path::");

		/*!
			Gets a kernel instance by name. 

			\param kernelName [mangled] name of kernel

			\return pointer to kernel instance with (name) 
				or 0 if kernel does not exist
		*/
		Kernel *getKernel(std::string kernelName);
		
	protected:
		/*! After a successful parse; constructs all kernels for PTX isa. */
		void extractPTXKernels();

	public:
		/*! Set of PTX statements loaded from PTX source file. This must not 
			change after parsing, as all kernels have const_iterators into 
			this vector.
		*/
		StatementVector statements;

		/*! Set of kernels belonging to Module.  These are PTX Kernels */
		KernelMap kernels;	
		
		/*! Set of textures in the module */
		TextureMap textures;

		/*! Set of global variables in the modules */
		GlobalMap globals;

		/*! Path from which Module was loaded */
		std::string modulePath;
		
		friend class executive::Executive;
	};

}

#endif

