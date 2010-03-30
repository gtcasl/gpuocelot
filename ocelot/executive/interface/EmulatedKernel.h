/*! \file EmulatedKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 19, 2009
	\brief implements a kernel emulated on the host CPU
*/

#ifndef EXECUTIVE_EMULATEDKERNEL_H_INCLUDED
#define EXECUTIVE_EMULATEDKERNEL_H_INCLUDED

#include <list>
#include <map>

#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/ir/interface/Texture.h>

#include <ocelot/executive/interface/CTAContext.h>
#include <ocelot/executive/interface/CooperativeThreadArray.h>
#include <hydrazine/interface/Stringable.h>

namespace trace {
	class TraceGenerator;
}

namespace executive {
		
	class EmulatedKernel: public ir::ExecutableKernel {
	public:
		typedef std::vector< ir::PTXInstruction > PTXInstructionVector;
		typedef std::vector< const ir::Texture * > TextureVector;

	private:
		static void _computeOffset(const ir::PTXStatement& it, 
			unsigned int& offset, unsigned int& totalOffset);

	public:
		EmulatedKernel(ir::Kernel* kernel, const Executive* c, bool initialize=true);
		EmulatedKernel(const Executive *c);
		EmulatedKernel();
		virtual ~EmulatedKernel();
	
		/*!	\brief Determines whether kernel is executable */
		bool executable();
		
		/*!	Launch a kernel on a 2D grid */
		void launchGrid(int width, int height);
	
		/*!	Sets the shape of a kernel */
		void setKernelShape(int x, int y, int z);

		ir::Dim3 getKernelShape() const;
		
		/*! \brief Changes the amount of external shared memory */
		void setExternSharedMemorySize(unsigned int bytes);
		
		/*!	Sets device used to execute the kernel */
		void setDevice(const Device* device, unsigned int limit);

		/*! \brief Indicate that the kernels parameters have been updated */
		void updateParameterMemory();
		
		/*! \brief Indicate that other memory has been updated */
		void updateMemory();

		/*! \brief Get a vector of all textures references by the kernel */
		ir::StringSet textureReferences() const;

		/*!  \brief get a set of all identifiers used as addresses by the kernel */
		ir::StringSet addressReferences() const;

	public:
		/*!	adds a trace generator to the EmulatedKernel */
		void addTraceGenerator(trace::TraceGenerator *generator);
		
		/*!	removes a trace generator from an EmulatedKernel */
		void removeTraceGenerator(trace::TraceGenerator *generator);

		/*! \brief Initialize the kernel */
		void initialize();

		/*!	Maps identifiers to global memory allocations. */
		void initializeGlobalMemory();		

	protected:
	
		/*! Cleans up the EmulatedKernel instance*/
		void freeAll();

		/*!	On construction, allocates registers by computing live ranges */
		void registerAllocation();

		/*!	Produces a packed vector of instructions, updates each operand, 
			and changes labels to indices.
		*/
		void constructInstructionSequence();

		/*!	After emitting the instruction sequence, visit each memory move 
			operation and replace references to parameters with offsets into 
			parameter memory.
		*/
		void updateParamReferences();

		/*!	Allocate parameter memory*/	
		void initializeParameterMemory();

		/*!	Allocates arrays in shared memory and maps identifiers to 
			allocations. */
		void initializeSharedMemory();

		/*!	Allocates arrays in local memory and maps identifiers to 
			allocations. */
		void initializeLocalMemory();

		/*!	Maps identifiers to const memory allocations. */
		void initializeConstMemory();

		/*!	Maps identifiers to global shared memory allocations. */
		void initializeGlobalSharedMemory();
		
		/*!	Scans the kernel and builds the set of textures using references 
				in tex instructions */
		void initializeTextureMemory();

	public:
		/*! A map of register name to register number */
		ir::PTXKernel::RegisterMap registerMap;

		/*!	Pointer to block of memory used to store parameter data */
		char* ParameterMemory;

		/*!	Pointer to byte-addressable const memory */
		char* ConstMemory;

		/*!	Packed and allocated vector of instructions */
		PTXInstructionVector instructions;

		/*!	Packed vector of mapped textures */
		TextureVector textures;

	public:
		/*! \brief Check to see if a memory access is valid */
		bool checkMemoryAccess(const void* base, size_t size) const;
	
	public:
		/*! Copies data from global objects into const and global memory */
		void updateGlobals();	

	public:
		/*!	Print out every instruction	*/
		std::string toString() const;
		
		/*! \brief Get the file name that the kernel resides in */
		std::string fileName() const;
		
		/*! \brief Get the nearest location to an instruction at a given PC */
		std::string location( unsigned int PC ) const;
	};

}

#endif
