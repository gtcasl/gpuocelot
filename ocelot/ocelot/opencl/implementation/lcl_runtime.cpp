#include <stdio.h>
#include <ocelot/opencl/interface/lcl_runtime.h>
#include <ocelot/opencl/interface/LCLRuntime.h>

lcl_vbuf lclCreateVirtualBuffer(lcl_context context,
			size_t size,
			lcl_int *errcode_ret) {

	return lcl::LCLRuntime::get()->lclCreateVirtualBuffer(context, size, errcode_ret);
}

lcl_int lclWriteVirtualBuffer(lcl_command_queue command_queue,
					lcl_vbuf virtual_buffer,
					lcl_bool blocking_write,
					size_t offset,
					size_t cb,
					const void * ptr,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event) {
	return lcl::LCLRuntime::get()->lclWriteVirtualBuffer(command_queue, virtual_buffer,
					blocking_write, offset, cb, ptr, num_events_in_wait_list,
					event_wait_list, event);
}

