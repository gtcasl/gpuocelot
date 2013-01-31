#ifndef OCELOT_LCL_RUNTIME_H_INCLUDED
#define OCELOT_LCL_RUNTIME_H_INCLUDED

//Ocelot libs
#include <ocelot/opencl/interface/lcl_runtime.h>
#include <ocelot/opencl/interface/VirtualBuffer.h>


struct _lcl_vbuf : public lcl::VirtualBuffer {
};

namespace lcl {

	class LCLRuntime {

	public:

		//! \brief singleton accessors */
		static LCLRuntime *instance;
		
		//! \brief get available implementation */
		static LCLRuntime *get();

		LCLRuntime();
		~LCLRuntime();

		virtual lcl_vbuf lclCreateVirtualBuffer(lcl_context context,
							size_t size,
							lcl_int * errcode_ret);

	};
}

#endif
