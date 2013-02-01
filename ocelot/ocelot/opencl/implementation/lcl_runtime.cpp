#include <stdio.h>
#include <ocelot/opencl/interface/lcl_runtime.h>
#include <ocelot/opencl/interface/LCLRuntime.h>

lcl_vbuf lclCreateVirtualBuffer(lcl_context context,
			size_t size,
			lcl_int *errcode_ret) {

	return lcl::LCLRuntime::get()->lclCreateVirtualBuffer(context, size, errcode_ret);
}

lcl_int lclEnqueueReadVirtualBuffer(lcl_command_queue command_queue,
					lcl_vbuf virtual_buffer,
					lcl_bool blocking_write,
					size_t offset,
					size_t size,
					void * ptr,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event) {
	return lcl::LCLRuntime::get()->lclEnqueueReadVirtualBuffer(command_queue, virtual_buffer,
					blocking_write, offset, size, ptr, num_events_in_wait_list,
					event_wait_list, event);
}

lcl_int lclEnqueueWriteVirtualBuffer(lcl_command_queue command_queue,
					lcl_vbuf virtual_buffer,
					lcl_bool blocking_write,
					size_t offset,
					size_t size,
					const void * ptr,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event) {
	return lcl::LCLRuntime::get()->lclEnqueueWriteVirtualBuffer(command_queue, virtual_buffer,
					blocking_write, offset, size, ptr, num_events_in_wait_list,
					event_wait_list, event);
}

lcl_int lclSetKernelArg(lcl_kernel kernel,
					lcl_uint arg_index,
					size_t arg_size,
					const void * arg_value) {
	return lcl::LCLRuntime::get()->lclSetKernelArg(kernel, arg_index, arg_size, arg_value);
}

lcl_int lclEnqueueNDRangeKernel(lcl_command_queue command_queue,
					lcl_kernel kernel,
					lcl_uint work_dim,
					const size_t * global_work_offset,
					const size_t * global_work_size,
					const size_t * local_work_size,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event) {
	return lcl::LCLRuntime::get()->lclEnqueueNDRangeKernel(command_queue, 
					kernel, work_dim,
					global_work_offset,
					global_work_size,
					local_work_size,
					num_events_in_wait_list,
					event_wait_list,
					event);
}

