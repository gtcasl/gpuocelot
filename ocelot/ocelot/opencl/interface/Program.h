#ifndef OCELOT_OPENCL_PROGRAM_H_INCLUDED
#define OCELOT_OPENCL_PROGRAM_H_INCLUDED

// C++ libs
#include <string>
#include <set>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Kernel.h>
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Context.h>

namespace opencl {

	class Kernel;

	typedef std::list< Kernel * > KernelList;

	//! programs created in OpenCL runtime	
	class Program {

	private:
		//! program id
		static unsigned int _id;

	public:
		Program(const std::string & source, Context * context);

	public:
		std::string name;
	
		//! ptx modules associated with device id	
		std::map <Device *, std::string> ptxModule;

		//! ptx code associated with device id
		std::map <Device *, std::string> ptxCode;
		
		//! source code of program
		std::string source;

		//! kernels
		KernelList kernels;

		//! get build status
		bool built;

		//! associated context
		Context * context;

	};

}

#endif 
