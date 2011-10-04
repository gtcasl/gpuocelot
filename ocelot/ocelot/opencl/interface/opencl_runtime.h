/*! 
	\file opencl_runtime.h
    \author Jin Wang <jin.wang@gatech.edu>
    \brief Definition of OpenCL Runtime API
    \date 28 Sep 2011
*/

#ifndef OPENCL_RUNTIME_H_INCLUDED
#define OPENCL_RUNTIME_H_INCLUDED

// C includes
#include <cstring>
#include <limits.h>
#include <cstdint>

//Ocelot includes
#include <ocelot/opencl/interface/CL/opencl.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
struct _cl_platform_id {
	//To be defined
};

struct _cl_device_id {
	//To be defined
};

struct _cl_context {
	//To be defined
};

struct _cl_command_queue {
	//To be defined
};

struct _cl_mem {
	//To be defined
};

struct _cl_program {
	//To be defined
};

struct _cl_kernel {
	//To be defined
};

struct _cl_event {
	//To be defined
};

struct _cl_sampler {
	//To be defined
};

//Ocelot defined Error code
#define CL_UNIMPLEMENTED	-15

#ifdef __cplusplus
}
#endif

#endif
