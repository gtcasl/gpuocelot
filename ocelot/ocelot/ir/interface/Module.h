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
#include <ocelot/cuda/include/cuda.h>

namespace executive { class Executive; }

namespace ir {

	class Module {
	public:
		/*!	\brief Map from texture variable names to objects */
		typedef std::map< std::string, Texture > TextureMap;

		/*! \brief set of names */
		typedef std::set< std::string > NameSet;
	
		/*! \brief Typedef for a vector of PTXStatements */
		typedef std::vector< PTXStatement > StatementVector;

		typedef std::map< std::string, Kernel * > KernelMap;

		typedef std::map< Instruction::Architecture, KernelMap > KernelArchitectureMap;

		/*! \brief Map from unique identifier to global variable */
		typedef std::map< std::string, Global > GlobalMap;
		
		enum CUModuleState {
			Unloaded,
			Loaded,
			Dirty,
			Invalid
		};
		
	public:

		/*! Given a path to a PTX source file, construct the Module, 
			load and parse the PTX file,
			and extract kernels into Kernel objects
		*/
		Module(std::string path);

		/*! Given a stream constaining a PTX file, parse the PTX file,
			and extract kernels into Kernel objects
		*/
		Module(std::istream& source);

		/*! Construct a Module from a name and a vector of PTXStatements */
		Module(std::string, const StatementVector &);

		/*!	Construct an empty module */
		Module();

		/*!	Deconstruct a module */
		~Module();
		
		/*! Write the module to an assembly file using statements */
		void write( std::ostream& stream ) const;

		/*! \brief Write the module to an assembly file from the IR */
		void writeIR( std::ostream& stream ) const;

		/*!	Deletes everything associated with this particular module */
		void unload();

		/*!	Unloads module and loads PTX source file in given path */
		bool load(std::string path);

		/*!	Unloads module and loads PTX source file in given stream */
		bool load(std::istream& source, std::string path = "::unknown path::");

		/*!
			Gets a kernel instance by ISA and name. Returned kernel 
			is guaranteed to have ISA requested.

			\param isa instruction set architecture of desired kernel
			\param kernelName [mangled] name of kernel

			\return pointer to kernel instance with (isa, name) 
				or 0 if kernel does not exist
		*/
		Kernel *getKernel(Instruction::Architecture isa, 
			std::string kernelName);

		Module::KernelMap::iterator begin(Instruction::Architecture isa) {
			return kernels[isa].begin();
		}

		Module::KernelMap::iterator end(Instruction::Architecture isa) {
			return kernels[isa].end();
		}
		
	protected:
		/*! After a successful parse; constructs all kernels for PTX isa. */
		void extractPTXKernels();

	public:
		/*!
			Set of PTX statements loaded from PTX source file. This must not 
			change after parsing, as all kernels have const_iterators into 
			this vector.
		*/
		StatementVector statements;

		/*! Set of kernels belonging to Module */
		KernelArchitectureMap kernels;	
		
		/*! Set of textures in the module */
		TextureMap textures;

		/*! Set of all texture names in the module */
		NameSet textureNames;

		/*! Set of global variables in the modules */
		GlobalMap globals;

		/*! Set of all global names in the module */
		NameSet globalNames;
		
		/*! Path from which Module was loaded */
		std::string modulePath;
	
		/*! CUDA Module owning this kernel, others, and globals - 
			this value is shared among other GPUExecutableKernels of this module
		*/
		CUmodule cuModule;

		/*! state of cuModule */
		CUModuleState cuModuleState;
		
		friend class executive::Executive;
	};

}

#endif

