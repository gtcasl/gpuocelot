#ifndef OCELOT_OPENCL_PROGRAM_H_INCLUDED
#define OCELOT_OPENCL_PROGRAM_H_INCLUDED

// C++ libs

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>

namespace opencl {

	typedef std::set< int > IndexSet;

	//! programs created in OpenCL runtime	
	class Program {
	private:
		//! program id
		static unsigned int _id;

	public:
		Program(const std::string & source, const void * context);

	public:
		std::string name;
	
		//! ptx modules associated with device id	
		std::map <int, std::string> ptxModule;

		//! ptx code associated with device id
		std::map <int, std::string> ptxCode;
		
		//! source code of program
		std::string source;

		//! kernels
		IndexSet kernels;

		//! get build status
		bool built;

		//! associated context
		const void * context;

	};

} 

#endif 
