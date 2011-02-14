/*!
	\file Documentation.h
	\date Wednesday Jun 17, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A file solely used for Ocelot self documentation.
*/

/*!
	\mainpage Ocelot: A Binary Translation Framework for PTX

	\section instruction_section Introduction
	
		The emergence of GPGPU programming models such as CUDA and OpenCL 
		provide avenues for general purpose application developers to leverage 
		the computation capabilities of highly parallel SIMD GPU architectures. 
		PTX defines a machine model and virtual ISA for these architectures 
		that is used commercially by NVIDIA GPUs, but is also representative 
		of other SIMD machine models. Ocelot seeks to develop a set of tools 
		that enable the low level analysis of GPGPU applications as well a 
		providing a JIT compiler for generic architectures. We have completed 
		control and dataflow analysis modules for PTX as well as an emulator 
		for the PTX 1.3-1.4 virtual machine compatible with CUDA 2.1-2.2 
		applications. We are currently working on a back end binary translator 
		from PTX to various architectures.

	\section installation_section Installation
	
		\subsection requirements_section Requirements
			
			The following compiler tools are required (tested):
				- GCC (4.3.2)
				- Flex (2.5.35)
				- Bison (2.3)
				- Autoconf (2.63)
				- Automake (1.10.2)
				- Cuda toolkit (2.2)
				- Libtool (2.2.6)
				
			The following libraries are required to be installed:
				- boost_system
				- boost_filesystem
				- boost_serialization
				- GLEW
				- rt
				
			The following external library headers are required to be on 
				your search path:
				- hydrazine (http://code.google.com/p/hydrazine/)
				- boost (http://www.boost.org/)
			
			We require a compiler that supports parts of the upcoming C++0x
			standard.
			
			Ocelot is rigorously tested on Ubuntu 9.04 using GCC-4.3.2.  We 
			strive to be ANSI C++ compliant, but only the specified systems is 
			actively tested.
			
		\subsection install_instructions Instructions
		
			Follow the standard autotools flow.  
			
				- libtoolize; aclocal; autoconf; automake; ./configure; make
				
			We assume that you have cuda installed in /usr/local/cuda.  If not
			specify a different path with 
				
				- ./configure --with-cuda=YOUR_PATH
			

	\section usage_section Expected Usage
	
		Ocelot as it stands includes a full featured parser for PTX 1.3-1.4, 
		an emulator for PTX 1.3-1.4, and a complete implementation of the 
		Cuda Runtime API 2.2 as defined in 
		PATH_TO_CUDA/include/cuda_runtime_api.h .  It also includes for 
		generating the control flow graphs and dominator trees of PTX programs.
		There are several trace generator modules and a trace generator 
		interface to the emulator that supports a callback after each emulated
		event.
		
		Compiling Ocelot will generate a libtool library libcudart.la that
		is a drop in replacement for NVIDIA's libcuda.so .  Libtool allows
		us to convert the library to a static libcudart.a or a shared
		object libcudart.so .  Note that Ocelot is built from several 
		internal modules, so you will have to link against every module
		that you use rather than simply cudart.  

	\section testing_section Testing

		Ocelot has been validated against the entire CUDA 2.1 and 2.2 SDKs,
		including streams, events, asynchronous operations, multidimensional 
		memory allocation, shared host/device memory, atomic/vote/reduction 
		operations, and even OpenGL.  It has also been validated against
		GPU-VISPL and several other internal applications.
		
		Under the tests directory, there are two separate projects cuda2.1 and
		cuda2.2 that build the CUDA SDKs and link them against Ocelot.  Running
		make test in these directories will run a regression test for each SDK.
		
	\section caveats_section Caveats
	
		To use Ocelot with any pre-compiled CUDA libraries 
		(such as CUFFT or CUBLAS), the libraries must be compiled as shared
		objects and must be linked in the correct order.  The order is 
		PRECOMPILED_LIBRARIES OCELOT_LIBRARIES YOUR_PROGRAM .  This is REQUIRED
		to ensure that global constructors are called in the correct order.  It
		is an artifact of how CUDA is designed and impossible for us to change.
		
		The warp size in Ocelot is variable and can change depending on the 
		version being used.  Any code that relies on the warp size being 32
		without checking the device properties will break.
		
		The implementation of texture instructions is not the same as NVIDIA's.
		We believe that our implementation is correct as far as the instructions
		are defined, however, the results will not be bit-accurate.
		
		The implementations of floating point rounding for single precision 
		instructions is probably different from NVIDIA's.

*/

