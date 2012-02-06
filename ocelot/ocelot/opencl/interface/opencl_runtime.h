/*! 
	\file opencl_runtime.h
    \author Jin Wang <jin.wang@gatech.edu>
    \brief Definition of OpenCL Runtime API
    \date 28 Sep 2011
*/

#ifndef OPENCL_RUNTIME_H_INCLUDED
#define OPENCL_RUNTIME_H_INCLUDED

//C libs
#include <cstring>
#include <limits.h>
#include <cstdint>

//OpenCL header includes
#include <ocelot/opencl/interface/CL/opencl.h>

#ifdef __cplusplus
extern "C" {
#endif
//Ocelot defined Error code
#define CL_UNIMPLEMENTED	-15

#ifdef __cplusplus
}
#endif

#endif
