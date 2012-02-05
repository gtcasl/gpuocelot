#ifndef OCELOT_OPENCL_KERNEL_H_INCLUDED
#define OCELOT_OPENCL_KERNEL_H_INCLUDED

// C++ libs
#include <string>
#include <map>
#include <set>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Program.h>
#include <ocelot/opencl/interface/Context.h>

namespace opencl {

	class Program;
 
	typedef std::map< unsigned int, size_t > SizeMap;
   	typedef std::map<unsigned int, char * > PointerMap;
	typedef std::map< unsigned int, unsigned int > OffsetMap;

   
    //! references a kernel registered to OpenCL runtime
	class Kernel {

	public:
		Kernel(const std::string& name, Program * program, Context * context);
		~Kernel();

	public:
		//! name of kernel
		const std::string name;

		//! associated program
		Program * program;

		//! associated context
		Context * context;
	
		//! Sizes for individual parameter
		SizeMap parameterSizes;
		
		//! Sizes for individual parameters
		PointerMap parameterPointers;

		//! parameter memory
		char *parameterBlock;
		
		//! size of parameter memory
		size_t parameterBlockSize;

		//! offset of parameters
		OffsetMap parameterOffsets;	

		//! number of dimensions for work-items
		cl_uint workDim;
		
		//! global ID offset for work-items
		size_t globalWorkOffset[3];

		//! global dimensions of work-items
		size_t globalWorkSize[3];

		//! local dimensions of work-items in work-group
		size_t localWorkSize[3];

		//! number of work groups
		size_t workGroupNum[3];
			
	};
	

}

#endif
