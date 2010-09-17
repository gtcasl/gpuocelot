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
#include <ocelot/ir/interface/PTXKernel.h>
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

		typedef std::unordered_map< std::string, PTXKernel* > KernelMap;
		
		typedef std::vector< PTXKernel* > KernelVector;

		/*! \brief Map from unique identifier to global variable */
		typedef std::unordered_map< std::string, Global > GlobalMap;
				
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

		/*!	Deletes everything associated with this particular module */
		void unload();

		/*!	Unloads module and loads PTX source file in given path */
		bool load(const std::string& path);

		/*!	Unloads module and loads PTX source file in given stream */
		bool load(std::istream& source,
			const std::string& path = "::unknown path::");

		/*!	Unloads module and loads PTX source string via a destructive copy */
		bool lazyLoad(std::string& source,
			const std::string& path = "::unknown path::");
		
		/*!	Unloads module and loads PTX source, this pointer must be valid 
			until the module is loaded */
		bool lazyLoad(const char* source,
			const std::string& path = "::unknown path::");
		
		/*! \brief Load the module if it has not already been loaded */
		void loadNow();
		
		/*! \brief Is the module loaded? */
		bool loaded() const;
		
		/*! \brief Gets a kernel instance by name. 

			\param name [mangled] name of kernel

			\return pointer to kernel instance with (name) 
				or 0 if kernel does not exist
		*/
		PTXKernel* getKernel(const std::string& name);
		
		/*! \brief Removes an existing kernel by name.
			\param name [mangled] name of kernel
		*/
		void removeKernel(const std::string& name);
		
		/*! \brief Adds a new kernel.
			\param kernel The kernel being inserted, it will be owned
				by the module.
		*/
		void insertKernel(PTXKernel* kernel);		
		
		/*! \brief Gets a texture instance by name. 

			\param name [mangled] name of texture

			\return pointer to texture instance with (name) 
				or 0 if it does not exist
		*/
		Texture* getTexture(const std::string& name);

		/*! \brief Gets a global instance by name. 

			\param name [mangled] name of global

			\return pointer to global instance with (name) 
				or 0 if it does not exist
		*/
		Global* getGlobal(const std::string& name);

		/*! \brief Gets the module path */
		const std::string& path() const;
		
		/*! \brief Gets the kernel map */
		const KernelMap& kernels() const;

		/*! \brief Gets the global map */
		const GlobalMap& globals() const;

		/*! \brief Gets the texture map */
		const TextureMap& textures() const;

		/*! \brief Gets the statement vector */
		const StatementVector& statements() const;
	
	private:
		/*! After a successful parse; constructs all kernels for PTX isa. */
		void extractPTXKernels();

	private:
		/*! \brief This is a copy of the original ptx source for lazy loading */
		std::string _ptx;

		/*! \brief This is a pointer to the original ptx source 
			for lazy loading */
		const char* _ptxPointer;
	
		/*! Set of PTX statements loaded from PTX source file. This must not 
			change after parsing, as all kernels have const_iterators into 
			this vector.
		*/
		StatementVector _statements;

		/*! Set of kernels belonging to Module.  These are PTX Kernels */
		KernelMap _kernels;	
		
		/*! Set of textures in the module */
		TextureMap _textures;

		/*! Set of global variables in the modules */
		GlobalMap _globals;

		/*! Path from which Module was loaded */
		std::string _modulePath;
		
		friend class executive::Executive;
	};

}

#endif

