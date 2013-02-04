#ifndef LCL_RUNTIME_H_INCLUDED
#define LCL_RUNTIME_H_INCLUDED

#include <ocelot/opencl/interface/opencl_runtime.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LCL_INVALID_VIRTUAL_BUFFER -99

typedef struct _lcl_vbuf * lcl_vbuf;
typedef cl_context lcl_context;
typedef cl_command_queue lcl_command_queue;
typedef cl_event lcl_event;
typedef cl_kernel lcl_kernel;


typedef cl_int lcl_int;
typedef cl_uint lcl_uint;
typedef cl_bool lcl_bool;

extern lcl_vbuf lclCreateVirtualBuffer(lcl_context context,
							  size_t size,
							  lcl_int * errcode_ret);

extern lcl_int lclEnqueueReadVirtualBuffer(lcl_command_queue command_queue,
					lcl_vbuf virtual_buffer,
					lcl_bool blocking_write,
					size_t offset,
					size_t size,
					void * ptr,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event);

extern lcl_int lclEnqueueWriteVirtualBuffer(lcl_command_queue command_queue,
					lcl_vbuf virtual_buffer,
					lcl_bool blocking_write,
					size_t offset,
					size_t size,
					const void * ptr,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event);

extern lcl_int lclSetKernelArg(lcl_kernel kernel,
					lcl_uint arg_index,
					size_t arg_size,
					const void * arg_value);

extern lcl_int lclEnqueueNDRangeKernel(lcl_command_queue command_queue,
					lcl_kernel kernel,
					lcl_uint work_dim,
					const size_t * global_work_offset,
					const size_t * global_work_size,
					const size_t * local_work_size,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event);

extern lcl_int lclFinish(lcl_command_queue command_queue);

extern lcl_int lclReleaseVirtualBuffer(lcl_vbuf virtual_buffer);
#ifdef __cplusplus
}
#endif

#endif
