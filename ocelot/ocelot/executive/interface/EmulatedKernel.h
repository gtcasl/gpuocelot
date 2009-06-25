/*!
	\file EmulatedKernel.h

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
		typedef std::vector< const ir::Texture* > TextureVector;

	public:
		EmulatedKernel(ir::Kernel *kernel);
		EmulatedKernel();
		virtual ~EmulatedKernel();
	
		/*!
			Launch a kernel on a 2D grid
		*/
		virtual void launchGrid(int width, int height);
	
		/*!
			Sets the shape of a kernel
		*/
		virtual void setKernelShape(int x, int y, int z);

		/*!
			adds a trace generator to the EmulatedKernel
		*/
		virtual void addTraceGenerator(trace::TraceGenerator *generator);

		/*!
			removes a trace generator from an EmulatedKernel
		*/
		virtual void removeTraceGenerator(trace::TraceGenerator *generator);

		/*!
			Gets the configured dimensions of a block
		*/
		ir::dim3 getBlockDim() const {
			return blockDim;
		}
	
	protected:

		/*!
			Cleans up the EmulatedKernel instance
		*/
		void freeAll();

		/*!
			From Kernel, analyze application and construct data structures 
				necessary for emulation
		*/
		void initialize();

		/*!
			Deletes allocated regions of global, register, shared, and 
				constant memory
		*/
		void freeRegions();

		/*!
			Configures the parameter block for the CUDA driver API
		*/
		void configureParameters();
	
		/*!
			On construction, allocates registers by computing live ranges
		*/
		void registerAllocation();

		/*!
			Produces a packed vector of instructions, updates each operand, 
			and changes labels to indices.
		*/
		void constructInstructionSequence();

		/*!
			After emitting the instruction sequence, visit each memory move 
			operation and replace references to parameters with offsets into 
			parameter memory.
		*/
		void updateParamReferences();

		/*!
			Allocate parameter memory
		*/
		void initializeParameterMemory();

		/*!
			Allocates arrays in shared memory and maps identifiers to 
			allocations.
		*/
		void initializeSharedMemory();

		/*!
			Allocates arrays in local memory and maps identifiers to 
			allocations.
		*/
		void initializeLocalMemory();

		/*!
			Maps identifiers to const memory allocations.
		*/
		void initializeConstMemory();

		/*!
			Maps identifiers to global memory allocations.
		*/
		void initializeGlobalMemory();		

		/*!
			Maps identifiers to global shared memory allocations.
		*/
		void initializeGlobalSharedMemory();
		
		/*!
			Scans the kernel and builds the set of textures using references 
				in tex instructions
		*/
		void initializeTextureMemory();

	public:

		/*!
			Dimension of grid in blocks
		*/
		ir::dim3 gridDim;

		/*!
			Dimension of block in threads
		*/
		ir::dim3 blockDim;
	
		/*!
			Number of threads in the block
		*/
		int threadCount;

		/*!
			A map of register name to register number
		*/
		std::map<std::string, ir::PTXOperand::RegisterType > RegisterMap;

		/*!
			The number of registers allocated to each thread
		*/
		int RegisterCount;

		/*!
			Pointer to block of memory used to store parameter data
		*/
		char *ParameterMemory;

		/*!
			Number of bytes in parameter region
		*/
		unsigned int ParameterMemorySize;

		/*!
			Pointer to byte-addressable const memory
		*/
		char *ConstMemory;

		/*!
			Number of bytes in constant memory
		*/
		unsigned int ConstMemorySize;

		/*!
			Number of bytes in shared memory
		*/
		unsigned int SharedMemorySize;
		
		/*!
			Local memory size
		*/
		unsigned int LocalMemorySize;
		
		/*!
			Packed and allocated vector of instructions implementing kernel
		*/
		std::vector< ir::PTXInstruction > KernelInstructions;

		/*!
			Packed vector of mapped textures
		*/
		TextureVector textures;
		
	public:

		/*!
			Notifies all attached TraceGenerators of an event
		*/
		void traceEvent( const trace::TraceEvent & event) const;

		/*!
			set of all trace generators listening to kernel
		*/
		std::list< trace::TraceGenerator * > Traces;

		/*!
			Copies data from parameter objects into parameter memory
		*/
		void updateParameterMemory();	

		/*!
			Copies data from global objects into const and global memory
		*/
		void updateGlobals();	

	public:
	
		/*!
			Print out every instruction
		*/
		std::string toString() const;
	};
	
}

#endif
