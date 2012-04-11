/*!	
	\file OpenCLRuntime.h
	\author Jin Wang <jin.wang@gatech.edu>
	\brief defines OpenCL runtime
	\date 28 Sep 2011
*/

#ifndef OCELOT_OPENCL_RUNTIME_H_INCLUDED
#define OCELOT_OPENCL_RUNTIME_H_INCLUDED

// C++ libs
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

// Boost libs
#include <boost/thread/thread.hpp>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Kernel.h>
#include <ocelot/opencl/interface/MemoryObject.h>
#include <ocelot/opencl/interface/CommandQueue.h>
#include <ocelot/opencl/interface/Program.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/Platform.h>
#include <ocelot/opencl/interface/Object.h>
#include <ocelot/ir/interface/ExternalFunctionSet.h>

// Hydrazine includes
#include <hydrazine/implementation/Timer.h>

// Forward Declarations

struct _cl_platform_id : public opencl::Platform {
};

struct _cl_context : public opencl::Context {
};

struct _cl_program : public opencl::Program {
};

struct _cl_command_queue : public opencl::CommandQueue {
};

struct _cl_kernel : public opencl::Kernel {
};

struct _cl_mem : public opencl::MemoryObject {
};

struct _cl_device_id : public opencl::Device {
};

struct _cl_event : public opencl::Event {
};

namespace transforms { class Pass; }

namespace opencl {

//	class RegisteredTexture
//	{
//		public:
//			RegisteredTexture(const std::string& module = "", 
//				const std::string& texture = "", bool norm = false);
//	
//		public:
//			/*! \brief The module that the texture is declared in */
//			std::string module;
//			/*! \brief The name of the texture */
//			std::string texture;
//			// Should the texture be normalized?
//			bool norm;
//	};
//	
//	class RegisteredGlobal
//	{
//		public:
//			RegisteredGlobal(const std::string& module = "", 
//				const std::string& global = "");
//	
//		public:
//			/*! \brief The module that the global is declared in */
//			std::string module;
//			/*! \brief The name of the global */
//			std::string global;
//	};
//	
//	class Dimension
//	{
//		public:
//			/*! \brief Initializing constructor */
//			Dimension(int x = 0, int y = 0, int z = 0, 
//				const openclChannelFormatDesc& f = 
//				openclCreateChannelDesc(8,0,0,0,openclChannelFormatKindNone));
//	
//			/*! \brief Get the pitch of the array */
//			size_t pitch() const;
//	
//		public:
//			/*! \brief X dimension */
//			int x;
//			/*! \brief Y dimension */
//			int y;
//			/*! \brief Z dimension */
//			int z;
//			/*! \brief Format */
//			openclChannelFormatDesc format;
//	};
//	
//	/*! \brief Set of PTX passes */
//	typedef std::set< transforms::Pass* > PassSet;


//	typedef std::map< void*, RegisteredGlobal > RegisteredGlobalMap;
//	typedef std::map< void*, RegisteredTexture > RegisteredTextureMap;
//	typedef std::map< void*, Dimension > DimensionMap;
//	typedef std::unordered_map<unsigned int, void*> GLBufferMap;

	////////////////////////////////////////////////////////////////////////////
	/*! OpenCL runtime context */
	class OpenCLRuntime: public OpenCLRuntimeInterface {


	private:
		typedef Device::DeviceList DeviceList;

		//! \brief acquires mutex and locks the runtime
		void _lock();
		//! \brief releases mutex
		void _unlock();
		//! \brief sets the last error state for the OpenCLRuntime object
		//cl_int _setLastError(cl_int result);

	private:
		//! locking object for opencl runtime
		boost::mutex _mutex;
		
		//! maps texture symbols to module-textures
		//RegisteredTextureMap _textures;

		//! maps symbol pointers onto their device names
		//RegisteredGlobalMap _globals;
		
		//! The dimensions for multi-dimensional allocations
		//DimensionMap _dimensions;
		
		//! Registered opengl buffers and mapping to graphics resources
		//GLBufferMap _buffers;
	
		//! optimization level
		translator::Translator::OptimizationLevel _optimization;
	
		//! external functions
	//	ir::ExternalFunctionSet _externals;
		
		//! PTX passes
	//	PassSet _passes;
	
	public:
		OpenCLRuntime();
		~OpenCLRuntime();

	public:
		/*virtual void openclRegisterTexture(
			void **fatCubinHandle,
			const struct textureReference *hostVar,
			const void **deviceAddress,
			const char *deviceName,
			int dim,
			int norm,
			int ext
		);*/

	public:

//		virtual void addTraceGenerator( trace::TraceGenerator& gen, 
//			bool persistent = false );
//		virtual void clearTraceGenerators();

//		virtual void addPTXPass(transforms::Pass &pass);
//		virtual void removePTXPass(transforms::Pass &pass);
//		virtual void clearPTXPasses();
//		virtual void limitWorkerThreads( unsigned int limit = 1024 );
//		virtual void registerPTXModule(std::istream& stream, 
//			const std::string& name);
//		virtual void registerTexture(const void* texref,
//			const std::string& moduleName,
//			const std::string& textureName, bool normalize);
//		virtual void clearErrors();
//		virtual void reset();
//		virtual ocelot::PointerMap contextSwitch( 
//			unsigned int destinationDevice, unsigned int sourceDevice);
//		virtual void unregisterModule(const std::string& name);
//		virtual void launch(const std::string& moduleName, 
//			const std::string& kernelName);
//		virtual void setOptimizationLevel(
//			translator::Translator::OptimizationLevel l);
//		virtual void registerExternalFunction(const std::string& name,
//			void* function);
//		virtual void removeExternalFunction(const std::string& name);


	public:

		//Platform APIs
		virtual cl_int clGetPlatformIDs(cl_uint num_entries, 
					cl_platform_id * platforms, 
					cl_uint * num_platforms);
		virtual cl_int clGetPlatformInfo(cl_platform_id platform, 
                  cl_platform_info param_name,
                  size_t param_value_size, 
                  void * param_value,
                  size_t * param_value_size_ret);

		//Device APIs
		virtual cl_int clGetDeviceIDs(cl_platform_id platform,
					cl_device_type device_type,
					cl_uint num_entries,
					cl_device_id * devices,
					cl_uint * num_devices);
		virtual cl_int clGetDeviceInfo(cl_device_id device,
					cl_device_info param_name,
				    size_t param_value_size,
					void * param_value,
				    size_t * param_value_size_ret);
		virtual cl_int clCreateSubDevices(cl_device_id in_device,
					const cl_device_partition_property * properties,
					cl_uint num_devices,
					cl_device_id * out_devices,
					cl_uint * num_devices_ret);

		//Context APIs
		virtual cl_context clCreateContext(const cl_context_properties * properties,
					cl_uint num_devices,
					const cl_device_id * devices,
					void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
					void * user_data,
					cl_int * errcode_ret);
		virtual cl_context clCreateContextFromType(const cl_context_properties * properties,
					cl_device_type                device_type,
					void (CL_CALLBACK *     pfn_notify)(const char *, const void *, size_t, void *),
					void *                        user_data,
					cl_int *                      errcode_ret);
		virtual cl_int clRetainContext(cl_context context);
		virtual cl_int clReleaseContext(cl_context context);
		virtual cl_int clGetContextInfo(cl_context         context,
					cl_context_info    param_name,
					size_t             param_value_size,
					void *             param_value,
					size_t *           param_value_size_ret);

		//Command queue APIs
		virtual cl_command_queue clCreateCommandQueue(cl_context context, 
				    cl_device_id device, 
				    cl_command_queue_properties properties,
				    cl_int * errcode_ret);
//		virtual cl_int clRetainCommandQueue(cl_command_queue command_queue);
		virtual cl_int clReleaseCommandQueue(cl_command_queue command_queue);
//		virtual cl_int clGetCommandQueueInfo(cl_command_queue      command_queue,
//					cl_command_queue_info param_name,
//					size_t                param_value_size,
//					void *                param_value,
//					size_t *              param_value_size_ret);

		//Memory Object APIs
		virtual cl_mem clCreateBuffer(cl_context context,
					cl_mem_flags flags,
					size_t size,
					void * host_ptr,
					cl_int * errcode_ret);
//		virtual cl_mem clCreateSubBuffer(cl_mem buffer,
//					cl_mem_flags             flags ,
//					cl_buffer_create_type    buffer_create_type,
//					const void *             buffer_create_info,
//					cl_int *                 errcode_ret);
//		virtual cl_mem clCreateImage(cl_context context,
//					cl_mem_flags            flags,
//					const cl_image_format * image_format,
//					const cl_image_desc *   image_desc,
//					void *                  host_ptr,
//					cl_int *                errcode_ret);
//		virtual cl_int clRetainMemObject(cl_mem memobj);
		virtual cl_int clReleaseMemObject(cl_mem memobj);
//		virtual cl_int clGetSupportedImageFormats(cl_context context,
//					cl_mem_flags         flags,
//					cl_mem_object_type   image_type,
//					cl_uint              num_entries,
//					cl_image_format *    image_formats,
//					cl_uint *            num_image_formats);
//		virtual cl_int clGetMemObjectInfo(cl_mem           memobj,
//                   cl_mem_info      param_name, 
//                   size_t           param_value_size,
//                   void *           param_value,
//                   size_t *         param_value_size_ret);
//		virtual cl_int clGetImageInfo(cl_mem           image,
//               cl_image_info    param_name, 
//               size_t           param_value_size,
//               void *           param_value,
//               size_t *         param_value_size_ret);
//		virtual cl_int clSetMemObjectDestructorCallback(  cl_mem memobj, 
//                                    void (CL_CALLBACK * pfn_notify)( cl_mem memobj, void* user_data), 
//                                    void * user_data);

		//Sampler APIs
//		virtual cl_sampler clCreateSampler(cl_context context,
//					cl_bool             normalized_coords,    
//					cl_addressing_mode  addressing_mode,    
//					cl_filter_mode      filter_mode,
//					cl_int *            errcode_ret);
//		virtual cl_int clRetainSampler(cl_sampler sampler); 
//		virtual cl_int clReleaseSampler(cl_sampler sampler);
//		virtual cl_int clGetSamplerInfo(cl_sampler sampler,
//					cl_sampler_info    param_name,
//					size_t             param_value_size,
//					void *             param_value,
//					size_t *           param_value_size_ret); 
		
		//Program APIs
		virtual cl_program clCreateProgramWithSource(cl_context context,
					cl_uint count,
					const char ** strings,
					const size_t * lengths,
					cl_int * errcode_ret);
//		virtual cl_program clCreateProgramWithBinary(cl_context context,
//					cl_uint                        num_devices,
//					const cl_device_id *           device_list,
//					const size_t *                 lengths,
//					const unsigned char **         binaries,
//					cl_int *                       binary_status,
//					cl_int *                       errcode_ret);
//		virtual cl_program clCreateProgramWithBuiltInKernels(cl_context context,
//					cl_uint               num_devices,
//					const cl_device_id *  device_list,
//					const char *          kernel_names,
//					cl_int *              errcode_ret);
//		virtual cl_int clRetainProgram(cl_program program);
		virtual cl_int clReleaseProgram(cl_program program);
		virtual cl_int clBuildProgram(cl_program program,
					cl_uint num_devices,
					const cl_device_id * device_list,
					const char * options, 
					void (CL_CALLBACK * pfn_notify)(cl_program, void *),
					void * user_data);
//		virtual cl_int clCompileProgram(cl_program program,
//					cl_uint              num_devices,
//					const cl_device_id * device_list,
//					const char *         options,
//					cl_uint              num_input_headers,
//					const cl_program *   input_headers,
//					const char **        header_include_names,
//					void (CL_CALLBACK *  pfn_notify)(cl_program program, void * user_data),
//					void *               user_data);
//		virtual cl_program clLinkProgram(cl_context           context,
//					cl_uint              num_devices,
//					const cl_device_id * device_list,
//					const char *         options,
//					cl_uint              num_input_programs,
//					const cl_program *   input_programs,
//					void (CL_CALLBACK *  pfn_notify)(cl_program program, void * user_data),
//					void *               user_data,
//					cl_int *             errcode_ret);
//		virtual cl_int clUnloadPlatformCompiler(cl_platform_id platform);
		virtual cl_int clGetProgramInfo(cl_program program,
					cl_program_info param_name,
					size_t param_value_size,
					void * param_value,
					size_t * param_value_size_ret);
//		virtual cl_int clGetProgramBuildInfo(cl_program            program,
//					cl_device_id          device,
//					cl_program_build_info param_name,
//					size_t                param_value_size,
//					void *                param_value,
//					size_t *              param_value_size_ret);
		
		/* Kernel APIs */
		virtual cl_kernel clCreateKernel(cl_program program,
					const char * kernel_name,
					cl_int * errcode_ret);
//		virtual cl_int clCreateKernelsInProgram(cl_program program,
//					cl_uint        num_kernels,
//					cl_kernel *    kernels,
//					cl_uint *      num_kernels_ret);
//		virtual cl_int clRetainKernel(cl_kernel  kernel);
		virtual cl_int clReleaseKernel(cl_kernel kernel);
		virtual cl_int clSetKernelArg(cl_kernel kernel,
					cl_uint arg_index,
					size_t arg_size,
					const void * arg_value);
//		virtual cl_int clGetKernelInfo(cl_kernel kernel,
//					cl_kernel_info  param_name,
//					size_t          param_value_size,
//					void *          param_value,
//					size_t *        param_value_size_ret);
//		virtual cl_int clGetKernelArgInfo(cl_kernel kernel,
//					cl_uint         arg_index,
//					cl_kernel_arg_info  param_name,
//					size_t          param_value_size,
//					void *          param_value,
//					size_t *        param_value_size_ret);
//		virtual cl_int clGetKernelWorkGroupInfo(cl_kernel kernel,
//					cl_device_id               device,
//					cl_kernel_work_group_info  param_name,
//					size_t                     param_value_size,
//					void *                     param_value,
//					size_t *                   param_value_size_ret);

		/* Event Object APIs */
//		virtual cl_int clWaitForEvents(cl_uint num_events,
//					const cl_event *    event_list);
//		virtual cl_int clGetEventInfo(cl_event event,
//					cl_event_info    param_name,
//					size_t           param_value_size,
//					void *           param_value,
//					size_t *         param_value_size_ret); 
//		virtual cl_event clCreateUserEvent(cl_context context,
//                  cl_int *      errcode_ret); 
//		virtual cl_int clRetainEvent(cl_event event);
		virtual cl_int clReleaseEvent(cl_event event);
//		virtual cl_int clSetUserEventStatus(cl_event   event,
//                     cl_int     execution_status);
//		virtual cl_int clSetEventCallback( cl_event    event,
//                    cl_int      command_exec_callback_type,
//                    void (CL_CALLBACK * pfn_notify)(cl_event, cl_int, void *),
//                    void *      user_data);

		/* Profiling APIs */
//		virtual cl_int clGetEventProfilingInfo(cl_event event,
//					cl_profiling_info   param_name,
//					size_t              param_value_size,
//					void *              param_value,
//					size_t *            param_value_size_ret);

		/* Flush and Finish APIs */
		virtual cl_int clFlush(cl_command_queue command_queue);
		virtual cl_int clFinish(cl_command_queue command_queue);

		/* Enqueue APIs */
		virtual cl_int clEnqueueReadBuffer(cl_command_queue command_queue,
					cl_mem buffer,
					cl_bool blocking_read,
					size_t offset,
					size_t cb, 
					void * ptr,
					cl_uint num_events_in_wait_list,
					const cl_event * event_wait_list,
					cl_event * event);
//		virtual cl_int clEnqueueReadBufferRect(cl_command_queue    command_queue,
//					cl_mem              buffer,
//					cl_bool             blocking_read,
//					const size_t *      buffer_origin,
//					const size_t *      host_origin, 
//					const size_t *      region,
//					size_t              buffer_row_pitch,
//					size_t              buffer_slice_pitch,
//					size_t              host_row_pitch,
//					size_t              host_slice_pitch,                        
//					void *              ptr,
//					cl_uint             num_events_in_wait_list,
//					const cl_event *    event_wait_list,
//					cl_event *          event);
		virtual cl_int clEnqueueWriteBuffer(cl_command_queue command_queue,
					cl_mem buffer,
					cl_bool blocking_write,
					size_t offset,
					size_t cb, 
					const void * ptr,
					cl_uint num_events_in_wait_list,
					const cl_event * event_wait_list,
					cl_event * event);
//		virtual cl_int clEnqueueWriteBufferRect(cl_command_queue    command_queue,
//					cl_mem              buffer,
//					cl_bool             blocking_write,
//					const size_t *      buffer_origin,
//					const size_t *      host_origin, 
//					const size_t *      region,
//					size_t              buffer_row_pitch,
//					size_t              buffer_slice_pitch,
//					size_t              host_row_pitch,
//					size_t              host_slice_pitch,                        
//					const void *        ptr,
//					cl_uint             num_events_in_wait_list,
//					const cl_event *    event_wait_list,
//					cl_event *          event);
//		virtual cl_int clEnqueueFillBuffer(cl_command_queue   command_queue,
//					cl_mem             buffer,
//					const void *       pattern,
//					size_t             pattern_size,
//					size_t             offset,
//					size_t             size,
//					cl_uint            num_events_in_wait_list,
//					const cl_event *   event_wait_list,
//					cl_event *         event);
//		virtual cl_int clEnqueueCopyBuffer(cl_command_queue    command_queue, 
//					cl_mem              src_buffer,
//					cl_mem              dst_buffer, 
//					size_t              src_offset,
//					size_t              dst_offset,
//					size_t              cb, 
//					cl_uint             num_events_in_wait_list,
//					const cl_event *    event_wait_list,
//					cl_event *          event);
//		virtual cl_int clEnqueueCopyBufferRect(cl_command_queue     command_queue, 
//					cl_mem               src_buffer,
//					cl_mem               dst_buffer, 
//					const size_t *       src_origin,
//					const size_t *       dst_origin,
//					const size_t *       region, 
//					size_t               src_row_pitch,
//					size_t               src_slice_pitch,
//					size_t               dst_row_pitch,
//					size_t               dst_slice_pitch,
//					cl_uint              num_events_in_wait_list,
//					const cl_event *     event_wait_list,
//					cl_event *           event);
//		virtual cl_int clEnqueueReadImage(cl_command_queue      command_queue,
//					cl_mem                image,
//					cl_bool               blocking_read, 
//					const size_t *        origin[3],
//					const size_t *        region[3],
//					size_t                row_pitch,
//					size_t                slice_pitch, 
//					void *                ptr,
//					cl_uint               num_events_in_wait_list,
//					const cl_event *      event_wait_list,
//					cl_event *            event);
//		virtual cl_int clEnqueueWriteImage(cl_command_queue     command_queue,
//					cl_mem               image,
//					cl_bool              blocking_write, 
//					const size_t *       origin[3],
//					const size_t *       region[3],
//					size_t               input_row_pitch,
//					size_t               input_slice_pitch, 
//					const void *         ptr,
//					cl_uint              num_events_in_wait_list,
//					const cl_event *     event_wait_list,
//					cl_event *           event);
//		virtual cl_int clEnqueueFillImage(cl_command_queue    command_queue,
//					cl_mem              image, 
//					const void *        fill_color, 
//					const size_t *      origin[3], 
//					const size_t *      region[3], 
//					cl_uint             num_events_in_wait_list, 
//					const cl_event *    event_wait_list, 
//					cl_event *          event);
//		virtual cl_int clEnqueueCopyImage(cl_command_queue      command_queue,
//					cl_mem                src_image,
//					cl_mem                dst_image, 
//					const size_t *        src_origin[3],
//					const size_t *        dst_origin[3],
//					const size_t *        region[3], 
//					cl_uint               num_events_in_wait_list,
//					const cl_event *      event_wait_list,
//					cl_event *            event);
//		virtual cl_int clEnqueueCopyImageToBuffer(cl_command_queue  command_queue,
//					cl_mem            src_image,
//					cl_mem            dst_buffer, 
//					const size_t *    src_origin[3],
//					const size_t *    region[3], 
//					size_t            dst_offset,
//					cl_uint           num_events_in_wait_list,
//					const cl_event *  event_wait_list,
//					cl_event *        event);
//		virtual cl_int clEnqueueCopyBufferToImage(cl_command_queue  command_queue,
//					cl_mem            src_buffer,
//					cl_mem            dst_image, 
//					size_t            src_offset,
//					const size_t *    dst_origin[3],
//					const size_t *    region[3], 
//					cl_uint           num_events_in_wait_list,
//					const cl_event *  event_wait_list,
//					cl_event *        event);
//		virtual void * clEnqueueMapBuffer(cl_command_queue  command_queue,
//					cl_mem            buffer,
//					cl_bool           blocking_map, 
//					cl_map_flags      map_flags,
//					size_t            offset,
//					size_t            cb,
//					cl_uint           num_events_in_wait_list,
//					const cl_event *  event_wait_list,
//					cl_event *        event,
//					cl_int *          errcode_ret);
//		virtual void * clEnqueueMapImage(cl_command_queue   command_queue,
//					cl_mem             image, 
//					cl_bool            blocking_map, 
//					cl_map_flags       map_flags, 
//					const size_t *     origin[3],
//					const size_t *     region[3],
//					size_t *           image_row_pitch,
//					size_t *           image_slice_pitch,
//					cl_uint            num_events_in_wait_list,
//					const cl_event *   event_wait_list,
//					cl_event *         event,
//					cl_int *           errcode_ret);
//		virtual cl_int clEnqueueUnmapMemObject(cl_command_queue  command_queue,
//					cl_mem            memobj,
//					void *            mapped_ptr,
//					cl_uint           num_events_in_wait_list,
//					const cl_event *   event_wait_list,
//					cl_event *         event);
//		virtual cl_int clEnqueueMigrateMemObjects(cl_command_queue        command_queue,
//					cl_uint                 num_mem_objects,
//					const cl_mem *          mem_objects,
//					cl_mem_migration_flags  flags,
//					cl_uint                 num_events_in_wait_list,
//					const cl_event *        event_wait_list,
//					cl_event *              event);
		virtual cl_int clEnqueueNDRangeKernel(cl_command_queue command_queue,
					cl_kernel        kernel,
					cl_uint          work_dim,
					const size_t *   global_work_offset,
					const size_t *   global_work_size,
					const size_t *   local_work_size,
					cl_uint          num_events_in_wait_list,
					const cl_event * event_wait_list,
					cl_event *       event);
//		virtual cl_int clEnqueueTask(cl_command_queue   command_queue,
//					cl_kernel          kernel,
//					cl_uint            num_events_in_wait_list,
//					const cl_event *   event_wait_list,
//					cl_event *         event);
//		virtual cl_int clEnqueueNativeKernel(cl_command_queue   command_queue,
//					void (*user_func)(void *), 
//					void *             args,
//					size_t             cb_args, 
//					cl_uint            num_mem_objects,
//					const cl_mem *     mem_list,
//					const void **      args_mem_loc,
//					cl_uint            num_events_in_wait_list,
//					const cl_event *   event_wait_list,
//					cl_event *         event);
//		virtual cl_int clEnqueueMarkerWithWaitList(cl_command_queue  command_queue,
//					cl_uint            num_events_in_wait_list,
//					const cl_event *   event_wait_list,
//					cl_event *         event);
//		virtual cl_int clEnqueueBarrierWithWaitList(cl_command_queue  command_queue,
//					cl_uint            num_events_in_wait_list,
//					const cl_event *   event_wait_list,
//					cl_event *         event);
//		virtual cl_int clSetPrintfCallback(cl_context           context,
//					void (CL_CALLBACK *  pfn_notify)(cl_context  program, 
//										cl_uint printf_data_len, 
//										char *  printf_data_ptr, 
//										void *  user_data),
//					void *               user_data);


	};

}


#endif

