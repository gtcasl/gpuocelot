#ifndef OCELOT_OPENCL_PROGRAM_H_INCLUDED
#define OCELOT_OPENCL_PROGRAM_H_INCLUDED

// C++ libs
#include <string>
#include <set>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/opencl/interface/Kernel.h>
#include <ocelot/opencl/interface/Context.h>

namespace opencl {

	class Kernel;

	typedef std::set< Kernel * > KernelSet;

	//! programs created in OpenCL runtime	
	class Program {
	private:
		//! program id
		static unsigned int _id;

	public:
		Program(const std::string & source, const Context * context);

	public:
		std::string name;
	
		//! ptx modules associated with device id	
		std::map <executive::Device *, std::string> ptxModule;

		//! ptx code associated with device id
		std::map <executive::Device *, std::string> ptxCode;
		
		//! source code of program
		std::string source;

		//! kernels
		KernelSet kernels;

		//! get build status
		bool built;

		//! associated context
		const Context * context;

	};

}

#endif 
