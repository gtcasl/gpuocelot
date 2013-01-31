#include <stdio.h>
#include <ocelot/opencl/interface/lcl_runtime.h>
#include <ocelot/opencl/interface/LCLRuntime.h>

lcl_vbuf lclCreateVirtualBuffer(cl_context context,
			size_t size,
			cl_int *errcode_ret) {

	return lcl::LCLRuntime::get()->lclCreateVirtualBuffer(context, size, errcode_ret);
}
