#ifndef LCL_RUNTIME_H_INCLUDED
#define LCL_RUNTIME_H_INCLUDED

#include <ocelot/opencl/interface/opencl_runtime.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _lcl_vbuf * lcl_vbuf;
typedef cl_context lcl_context;
typedef cl_int lcl_int;

extern lcl_vbuf lclCreateVirtualBuffer(lcl_context context,
							  size_t size,
							  lcl_int * errcode_ret);

#ifdef __cplusplus
}
#endif

#endif
