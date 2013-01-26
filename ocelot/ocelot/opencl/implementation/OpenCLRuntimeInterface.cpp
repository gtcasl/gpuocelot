/*!	
	\file OpenCLRuntimeInterface.cpp
	\author Jin Wang <jin.wang@gatech.edu>
	\brief defines OpenCL runtime abstract interface
	\date 28 Sep 2011
*/

// C std lib includes
#include <assert.h>

// C++ std lib includes

// Ocelot includes
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/OpenCLRuntime.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>
#include <ocelot/opencl/interface/Object.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0


////////////////////////////////////////////////////////////////////////////////

opencl::OpenCLRuntimeInterface * opencl::OpenCLRuntimeInterface::instance = 0;

static void destroyInstance() {
	if (opencl::OpenCLRuntimeInterface::instance) {
		delete opencl::OpenCLRuntimeInterface::instance;
		opencl::OpenCLRuntimeInterface::instance = 0;
	}
}

////////////////////////////////////////////////////////////////////////////////

opencl::OpenCLRuntimeInterface * opencl::OpenCLRuntimeInterface::get() {
	if (!opencl::OpenCLRuntimeInterface::instance) {
		if (api::OcelotConfiguration::get().opencl.implementation
			== "OpenCLRuntime") {
			opencl::OpenCLRuntimeInterface::instance = new OpenCLRuntime;

			opencl::OpenCLRuntimeInterface::instance->ocelotRuntime.configure(
				api::OcelotConfiguration::get());
			std::atexit(destroyInstance);

		}
		else {
			assertM(false,"no OpenCL runtime implementation "
				"matches what is requested");
		}
	}
	return opencl::OpenCLRuntimeInterface::instance;
}

opencl::OpenCLRuntimeInterface::OpenCLRuntimeInterface() {

}

opencl::OpenCLRuntimeInterface::~OpenCLRuntimeInterface() {

}

////////////////////////////////////////////////////////////////////////////////

cl_int opencl::OpenCLRuntimeInterface::clGetPlatformIDs(cl_uint num_entries, 
	cl_platform_id * platforms, 
	cl_uint * num_platforms) {
	assertM(false , "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetPlatformInfo(cl_platform_id platform, 
                  cl_platform_info param_name,
                  size_t param_value_size, 
                  void * param_value,
                  size_t * param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetDeviceIDs(cl_platform_id platform, 
	cl_device_type device_type, 
	cl_uint num_entries,
	cl_device_id * devices,
	cl_uint * num_devices) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}
			
cl_int opencl::OpenCLRuntimeInterface::clGetDeviceInfo(cl_device_id device,
	cl_device_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clCreateSubDevices(cl_device_id in_device,
					const cl_device_partition_property * properties,
					cl_uint num_devices,
					cl_device_id * out_devices,
					cl_uint * num_devices_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_context opencl::OpenCLRuntimeInterface::clCreateContext(const cl_context_properties * properties,
	cl_uint num_devices,
	const cl_device_id * devices,
	void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
	void * user_data,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_context opencl::OpenCLRuntimeInterface::clCreateContextFromType(const cl_context_properties * properties,
					cl_device_type                device_type,
					void (CL_CALLBACK *     pfn_notify)(const char *, const void *, size_t, void *),
					void *                        user_data,
					cl_int *                      errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clRetainContext(cl_context context) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clReleaseContext(cl_context context) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetContextInfo(cl_context         context,
                 cl_context_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_command_queue opencl::OpenCLRuntimeInterface::clCreateCommandQueue(cl_context context, 
	cl_device_id device, 
	cl_command_queue_properties properties,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clRetainCommandQueue(cl_command_queue command_queue) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clReleaseCommandQueue(cl_command_queue command_queue) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetCommandQueueInfo(cl_command_queue      command_queue,
					cl_command_queue_info param_name,
					size_t                param_value_size,
					void *                param_value,
					size_t *              param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_mem opencl::OpenCLRuntimeInterface::clCreateBuffer(cl_context context,
	cl_mem_flags flags,
	size_t size,
	void * host_ptr,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_mem opencl::OpenCLRuntimeInterface::clCreateSubBuffer(cl_mem buffer,
					cl_mem_flags             flags ,
					cl_buffer_create_type    buffer_create_type,
					const void *             buffer_create_info,
					cl_int *                 errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_mem opencl::OpenCLRuntimeInterface::clCreateImage(cl_context context,
					cl_mem_flags            flags,
					const cl_image_format * image_format,
					const cl_image_desc *   image_desc,
					void *                  host_ptr,
					cl_int *                errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clRetainMemObject(cl_mem memobj) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clReleaseMemObject(cl_mem memobj) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetSupportedImageFormats(cl_context context,
					cl_mem_flags         flags,
					cl_mem_object_type   image_type,
					cl_uint              num_entries,
					cl_image_format *    image_formats,
					cl_uint *            num_image_formats) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetMemObjectInfo(cl_mem           memobj,
                   cl_mem_info      param_name, 
                   size_t           param_value_size,
                   void *           param_value,
                   size_t *         param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetImageInfo(cl_mem           image,
               cl_image_info    param_name, 
               size_t           param_value_size,
               void *           param_value,
               size_t *         param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clSetMemObjectDestructorCallback(  cl_mem memobj, 
                                    void (CL_CALLBACK * pfn_notify)( cl_mem memobj, void* user_data), 
                                    void * user_data) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_sampler opencl::OpenCLRuntimeInterface::clCreateSampler(cl_context context,
					cl_bool             normalized_coords,    
					cl_addressing_mode  addressing_mode,    
					cl_filter_mode      filter_mode,
					cl_int *            errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clRetainSampler(cl_sampler sampler) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clReleaseSampler(cl_sampler sampler) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetSamplerInfo(cl_sampler sampler,
					cl_sampler_info    param_name,
					size_t             param_value_size,
					void *             param_value,
					size_t *           param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_program opencl::OpenCLRuntimeInterface::clCreateProgramWithSource(cl_context context,
	cl_uint count,
	const char ** strings,
	const size_t * lengths,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_program opencl::OpenCLRuntimeInterface::clCreateProgramWithBinary(cl_context context,
					cl_uint                        num_devices,
					const cl_device_id *           device_list,
					const size_t *                 lengths,
					const unsigned char **         binaries,
					cl_int *                       binary_status,
					cl_int *                       errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_program opencl::OpenCLRuntimeInterface::clCreateProgramWithBuiltInKernels(cl_context context,
					cl_uint               num_devices,
					const cl_device_id *  device_list,
					const char *          kernel_names,
					cl_int *              errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clRetainProgram(cl_program program) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clReleaseProgram(cl_program program) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clBuildProgram(cl_program program,
	cl_uint num_devices,
	const cl_device_id * device_list,
	const char * options, 
	void (CL_CALLBACK * pfn_notify)(cl_program, void *),
	void * user_data) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clCompileProgram(cl_program program,
					cl_uint              num_devices,
					const cl_device_id * device_list,
					const char *         options,
					cl_uint              num_input_headers,
					const cl_program *   input_headers,
					const char **        header_include_names,
					void (CL_CALLBACK *  pfn_notify)(cl_program program, void * user_data),
					void *               user_data) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_program opencl::OpenCLRuntimeInterface::clLinkProgram(cl_context           context,
					cl_uint              num_devices,
					const cl_device_id * device_list,
					const char *         options,
					cl_uint              num_input_programs,
					const cl_program *   input_programs,
					void (CL_CALLBACK *  pfn_notify)(cl_program program, void * user_data),
					void *               user_data,
					cl_int *             errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clUnloadPlatformCompiler(cl_platform_id platform) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetProgramInfo(cl_program program,
	cl_program_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetProgramBuildInfo(cl_program            program,
					cl_device_id          device,
					cl_program_build_info param_name,
					size_t                param_value_size,
					void *                param_value,
					size_t *              param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_kernel opencl::OpenCLRuntimeInterface::clCreateKernel(cl_program program,
	const char * kernel_name,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clCreateKernelsInProgram(cl_program program,
					cl_uint        num_kernels,
					cl_kernel *    kernels,
					cl_uint *      num_kernels_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clRetainKernel(cl_kernel  kernel) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clReleaseKernel(cl_kernel kernel) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clSetKernelArg(cl_kernel kernel,
					cl_uint arg_index,
					size_t arg_size,
					const void * arg_value) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetKernelInfo(cl_kernel kernel,
					cl_kernel_info  param_name,
					size_t          param_value_size,
					void *          param_value,
					size_t *        param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetKernelArgInfo(cl_kernel kernel,
					cl_uint         arg_index,
					cl_kernel_arg_info  param_name,
					size_t          param_value_size,
					void *          param_value,
					size_t *        param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetKernelWorkGroupInfo(cl_kernel kernel,
					cl_device_id               device,
					cl_kernel_work_group_info  param_name,
					size_t                     param_value_size,
					void *                     param_value,
					size_t *                   param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clWaitForEvents(cl_uint num_events,
					const cl_event *    event_list) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetEventInfo(cl_event event,
					cl_event_info    param_name,
					size_t           param_value_size,
					void *           param_value,
					size_t *         param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_event opencl::OpenCLRuntimeInterface::clCreateUserEvent(cl_context context,
                  cl_int *      errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clRetainEvent(cl_event event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clReleaseEvent(cl_event event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clSetUserEventStatus(cl_event   event,
                     cl_int     execution_status) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clSetEventCallback( cl_event    event,
                    cl_int      command_exec_callback_type,
                    void (CL_CALLBACK * pfn_notify)(cl_event, cl_int, void *),
                    void *      user_data) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetEventProfilingInfo(cl_event event,
					cl_profiling_info   param_name,
					size_t              param_value_size,
					void *              param_value,
					size_t *            param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clFlush(cl_command_queue command_queue) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clFinish(cl_command_queue command_queue) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueReadBuffer(cl_command_queue command_queue,
	cl_mem buffer,
	cl_bool blocking_read,
	size_t offset,
	size_t cb, 
	void * ptr,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueReadBufferRect(cl_command_queue    command_queue,
					cl_mem              buffer,
					cl_bool             blocking_read,
					const size_t *      buffer_origin,
					const size_t *      host_origin, 
					const size_t *      region,
					size_t              buffer_row_pitch,
					size_t              buffer_slice_pitch,
					size_t              host_row_pitch,
					size_t              host_slice_pitch,                        
					void *              ptr,
					cl_uint             num_events_in_wait_list,
					const cl_event *    event_wait_list,
					cl_event *          event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueWriteBuffer(cl_command_queue command_queue,
	cl_mem buffer,
	cl_bool blocking_write,
	size_t offset,
	size_t cb, 
	const void * ptr,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueWriteBufferRect(cl_command_queue    command_queue,
					cl_mem              buffer,
					cl_bool             blocking_write,
					const size_t *      buffer_origin,
					const size_t *      host_origin, 
					const size_t *      region,
					size_t              buffer_row_pitch,
					size_t              buffer_slice_pitch,
					size_t              host_row_pitch,
					size_t              host_slice_pitch,                        
					const void *        ptr,
					cl_uint             num_events_in_wait_list,
					const cl_event *    event_wait_list,
					cl_event *          event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueFillBuffer(cl_command_queue   command_queue,
					cl_mem             buffer,
					const void *       pattern,
					size_t             pattern_size,
					size_t             offset,
					size_t             size,
					cl_uint            num_events_in_wait_list,
					const cl_event *   event_wait_list,
					cl_event *         event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueCopyBuffer(cl_command_queue    command_queue, 
					cl_mem              src_buffer,
					cl_mem              dst_buffer, 
					size_t              src_offset,
					size_t              dst_offset,
					size_t              cb, 
					cl_uint             num_events_in_wait_list,
					const cl_event *    event_wait_list,
					cl_event *          event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueCopyBufferRect(cl_command_queue     command_queue, 
					cl_mem               src_buffer,
					cl_mem               dst_buffer, 
					const size_t *       src_origin,
					const size_t *       dst_origin,
					const size_t *       region, 
					size_t               src_row_pitch,
					size_t               src_slice_pitch,
					size_t               dst_row_pitch,
					size_t               dst_slice_pitch,
					cl_uint              num_events_in_wait_list,
					const cl_event *     event_wait_list,
					cl_event *           event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueReadImage(cl_command_queue      command_queue,
					cl_mem                image,
					cl_bool               blocking_read, 
					const size_t *        origin,
					const size_t *        region,
					size_t                row_pitch,
					size_t                slice_pitch, 
					void *                ptr,
					cl_uint               num_events_in_wait_list,
					const cl_event *      event_wait_list,
					cl_event *            event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueWriteImage(cl_command_queue     command_queue,
					cl_mem               image,
					cl_bool              blocking_write, 
					const size_t *       origin,
					const size_t *       region,
					size_t               input_row_pitch,
					size_t               input_slice_pitch, 
					const void *         ptr,
					cl_uint              num_events_in_wait_list,
					const cl_event *     event_wait_list,
					cl_event *           event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueFillImage(cl_command_queue    command_queue,
					cl_mem              image, 
					const void *        fill_color, 
					const size_t *      origin, 
					const size_t *      region, 
					cl_uint             num_events_in_wait_list, 
					const cl_event *    event_wait_list, 
					cl_event *          event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueCopyImage(cl_command_queue      command_queue,
					cl_mem                src_image,
					cl_mem                dst_image, 
					const size_t *        src_origin,
					const size_t *        dst_origin,
					const size_t *        region, 
					cl_uint               num_events_in_wait_list,
					const cl_event *      event_wait_list,
					cl_event *            event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueCopyImageToBuffer(cl_command_queue  command_queue,
					cl_mem            src_image,
					cl_mem            dst_buffer, 
					const size_t *    src_origin,
					const size_t *    region, 
					size_t            dst_offset,
					cl_uint           num_events_in_wait_list,
					const cl_event *  event_wait_list,
					cl_event *        event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueCopyBufferToImage(cl_command_queue  command_queue,
					cl_mem            src_buffer,
					cl_mem            dst_image, 
					size_t            src_offset,
					const size_t *    dst_origin,
					const size_t *    region, 
					cl_uint           num_events_in_wait_list,
					const cl_event *  event_wait_list,
					cl_event *        event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

void * opencl::OpenCLRuntimeInterface::clEnqueueMapBuffer(cl_command_queue  command_queue,
					cl_mem            buffer,
					cl_bool           blocking_map, 
					cl_map_flags      map_flags,
					size_t            offset,
					size_t            cb,
					cl_uint           num_events_in_wait_list,
					const cl_event *  event_wait_list,
					cl_event *        event,
					cl_int *          errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

void * opencl::OpenCLRuntimeInterface::clEnqueueMapImage(cl_command_queue   command_queue,
					cl_mem             image, 
					cl_bool            blocking_map, 
					cl_map_flags       map_flags, 
					const size_t *     origin,
					const size_t *     region,
					size_t *           image_row_pitch,
					size_t *           image_slice_pitch,
					cl_uint            num_events_in_wait_list,
					const cl_event *   event_wait_list,
					cl_event *         event,
					cl_int *           errcode_ret) {
	assertM(false, "unimplemented");
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueUnmapMemObject(cl_command_queue  command_queue,
					cl_mem            memobj,
					void *            mapped_ptr,
					cl_uint           num_events_in_wait_list,
					const cl_event *   event_wait_list,
					cl_event *         event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueMigrateMemObjects(cl_command_queue        command_queue,
					cl_uint                 num_mem_objects,
					const cl_mem *          mem_objects,
					cl_mem_migration_flags  flags,
					cl_uint                 num_events_in_wait_list,
					const cl_event *        event_wait_list,
					cl_event *              event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueNDRangeKernel(cl_command_queue command_queue,
	cl_kernel kernel,
	cl_uint work_dim,
	const size_t * global_work_offset,
	const size_t * global_work_size,
	const size_t * local_work_size,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event){
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueTask(cl_command_queue   command_queue,
					cl_kernel          kernel,
					cl_uint            num_events_in_wait_list,
					const cl_event *   event_wait_list,
					cl_event *         event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueNativeKernel(cl_command_queue   command_queue,
					void (*user_func)(void *), 
					void *             args,
					size_t             cb_args, 
					cl_uint            num_mem_objects,
					const cl_mem *     mem_list,
					const void **      args_mem_loc,
					cl_uint            num_events_in_wait_list,
					const cl_event *   event_wait_list,
					cl_event *         event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueMarkerWithWaitList(cl_command_queue  command_queue,
					cl_uint            num_events_in_wait_list,
					const cl_event *   event_wait_list,
					cl_event *         event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clEnqueueBarrierWithWaitList(cl_command_queue  command_queue,
					cl_uint            num_events_in_wait_list,
					const cl_event *   event_wait_list,
					cl_event *         event) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clSetPrintfCallback(cl_context           context,
					void (CL_CALLBACK *  pfn_notify)(cl_context  program, 
										cl_uint printf_data_len, 
										char *  printf_data_ptr, 
										void *  user_data),
					void *               user_data) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

void opencl::OpenCLRuntimeInterface::addTraceGenerator( trace::TraceGenerator& gen, 
	bool persistent ) {
	assert(0 && "unimplemented");
}
			
void opencl::OpenCLRuntimeInterface::clearTraceGenerators() {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::addPTXPass(transforms::Pass &pass) {
	assert(0 && "unimplemented");
}
void opencl::OpenCLRuntimeInterface::removePTXPass(transforms::Pass &pass) {
	assert(0 && "unimplemented");
}
void opencl::OpenCLRuntimeInterface::clearPTXPasses() {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::limitWorkerThreads( unsigned int limit ) {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::registerPTXModule(std::istream& stream, 
	const std::string& name) {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::registerTexture(
	const void* texref,
	const std::string& moduleName,
	const std::string& textureName, bool normalize){
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::clearErrors() {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::reset() {
	assert(0 && "unimplemented");
}

ocelot::PointerMap opencl::OpenCLRuntimeInterface::contextSwitch( 
	unsigned int destinationDevice, unsigned int sourceDevice ) {
	assert(0 && "unimplemented");
	return ocelot::PointerMap();
}

void opencl::OpenCLRuntimeInterface::unregisterModule( const std::string& name ) {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::launch(const std::string& moduleName, const 
	std::string& kernelName) {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::setOptimizationLevel(
	translator::Translator::OptimizationLevel l) {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::registerExternalFunction(
	const std::string& name, void* function) {
	assert(0 && "unimplemented");
}

void opencl::OpenCLRuntimeInterface::removeExternalFunction(
	const std::string& name) {
	assert(0 && "unimplemented");
}

bool opencl::OpenCLRuntimeInterface::isExternalFunction(
	const std::string& name) {
	assert(0 && "unimplemented");

	return false;
}

void opencl::OpenCLRuntimeInterface::getDeviceProperties(
	executive::DeviceProperties &, int deviceIndex) {
	assert(0 && "unimplemented");
}

////////////////////////////////////////////////////////////////////////////////


