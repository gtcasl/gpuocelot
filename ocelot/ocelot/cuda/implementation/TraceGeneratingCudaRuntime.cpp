/*! \file TraceGeneratingCudaRuntime.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Saturday September 5, 2009
	\brief The header file for the TraceGeneratingCudaRuntime class.
*/

#ifndef TRACE_GENERATING_CUDA_RUNTIME_CPP_INCLUDED
#define TRACE_GENERATING_CUDA_RUNTIME_CPP_INCLUDED

#include <ocelot/cuda/interface/TraceGeneratingCudaRuntime.h>

#include <hydrazine/implementation/XmlParser.h>
#include <hydrazine/implementation/Exception.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace cuda
{
	TraceGeneratingCudaRuntime::TraceGeneratingCudaRuntime()
	{
		Configuration config;
	
		try
		{
			report( "Loading config file config.ocelot" );
			hydrazine::XmlParser parser( "config.ocelot" );
			hydrazine::XmlTree tree = parser.tree();
			hydrazine::XmlTree::iterator fi = tree.begin();
		
			fi.descend("ocelot");
			fi.descend("CudaRuntime");
			fi.descend("TraceGeneratingCudaRuntime");
		
			config = fi.map();
		}
		catch( const hydrazine::Exception& e )
		{
			report( "Failed to load config file" );
		}
	
		configure( config );
		_timer.start();
	}
	
	TraceGeneratingCudaRuntime::~TraceGeneratingCudaRuntime()
	{
	
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMalloc3D( 
		cudaPitchedPtr* pitchedDevPtr, cudaExtent extent )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMalloc3D( pitchedDevPtr, extent );
		_timer.stop();
		
		_trace << "cudaMalloc3D";
		_trace << " pointer = " << pitchedDevPtr;
		_trace << " width = " << extent.width;
		_trace << " height = " << extent.height;
		_trace << " depth = " << extent.depth;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";
		
		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMalloc3DArray( 
		cudaArray** arrayPtr, const cudaChannelFormatDesc* desc, 
		cudaExtent extent )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMalloc3DArray( 
			arrayPtr, desc, extent );
		_timer.stop();
		
		_trace << "cudaMalloc3DArray";
		_trace << " pointer = " << arrayPtr;
		_trace << " x = " << desc->x;
		_trace << " y = " << desc->y;
		_trace << " z = " << desc->z;
		_trace << " format = " << desc->f;
		_trace << " width = " << extent.width;
		_trace << " height = " << extent.height;
		_trace << " depth = " << extent.depth;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";
				
		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemset3D( 
		cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemset3D( pitchedDevPtr, 
			value, extent );
		_timer.stop();
		
		_trace << "cudaMemset3D";
		_trace << " pointer = " << pitchedDevPtr.ptr;
		_trace << " pitch = " << pitchedDevPtr.pitch;
		_trace << " xsize = " << pitchedDevPtr.xsize;
		_trace << " ysize = " << pitchedDevPtr.ysize;
		_trace << " value = " << value;
		_trace << " width = " << extent.width;
		_trace << " height = " << extent.height;
		_trace << " depth = " << extent.depth;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";
				
		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy3D( 
		const cudaMemcpy3DParms* p )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy3D( p );
		_timer.stop();
		
		_trace << "cudaMemcpy3D";
		_trace << " sourcePointer = " << p->srcArray;
		_trace << " sourceX = " << p->srcPos.x;
		_trace << " sourceY = " << p->srcPos.y;
		_trace << " sourceZ = " << p->srcPos.z;
		_trace << " sourcePitchedPtr = " << p->srcPtr.ptr;
		_trace << " sourcePitch = " << p->srcPtr.pitch;
		_trace << " sourceXsize = " << p->srcPtr.xsize;
		_trace << " sourceYsize = " << p->srcPtr.ysize;

		_trace << " destinationPointer = " << p->dstArray;
		_trace << " destinationX = " << p->dstPos.x;
		_trace << " destinationY = " << p->dstPos.y;
		_trace << " destinationZ = " << p->dstPos.z;
		_trace << " destinationPitchedPtr = " << p->dstPtr.ptr;
		_trace << " destinationPitch = " << p->dstPtr.pitch;
		_trace << " destinationXsize = " << p->dstPtr.xsize;
		_trace << " destinationYsize = " << p->dstPtr.ysize;
		
		_trace << " width = " << p->extent.width;
		_trace << " height = " << p->extent.height;
		_trace << " depth = " << p->extent.depth;
		_trace << " kind = " << p->kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";
		
		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy3DAsync( 
		const cudaMemcpy3DParms* p, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy3DAsync( p, stream );
		_timer.stop();

		_trace << "cudaMemcpy3DAsync";
		_trace << " sourcePointer = " << p->srcArray;
		_trace << " sourceX = " << p->srcPos.x;
		_trace << " sourceY = " << p->srcPos.y;
		_trace << " sourceZ = " << p->srcPos.z;
		_trace << " sourcePitchedPtr = " << p->srcPtr.ptr;
		_trace << " sourcePitch = " << p->srcPtr.pitch;
		_trace << " sourceXsize = " << p->srcPtr.xsize;
		_trace << " sourceYsize = " << p->srcPtr.ysize;

		_trace << " destinationPointer = " << p->dstArray;
		_trace << " destinationX = " << p->dstPos.x;
		_trace << " destinationY = " << p->dstPos.y;
		_trace << " destinationZ = " << p->dstPos.z;
		_trace << " destinationPitchedPtr = " << p->dstPtr.ptr;
		_trace << " destinationPitch = " << p->dstPtr.pitch;
		_trace << " destinationXsize = " << p->dstPtr.xsize;
		_trace << " destinationYsize = " << p->dstPtr.ysize;
		
		_trace << " width = " << p->extent.width;
		_trace << " height = " << p->extent.height;
		_trace << " depth = " << p->extent.depth;
		_trace << " kind = " << p->kind;
		_trace << " time = " << _timer.seconds();
		_trace << " stream = " << stream;
		_trace << "\n";
		
		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaMalloc( 
		void** devPtr, size_t size )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMalloc( devPtr, size );
		_timer.stop();

		_trace << "cudaMalloc";
		_trace << " pointer = " << *devPtr;
		_trace << " size = " << size;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";
		
		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMallocHost( 
		void** ptr, size_t size )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMallocHost( ptr, size );
		_timer.stop();

		_trace << "cudaMallocHost";
		_trace << " pointer = " << *ptr;
		_trace << " size = " << size;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";
		
		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMallocPitch( void** devPtr, 
		size_t* pitch, size_t width, size_t height )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMallocPitch( devPtr, 
			pitch, width, height );
		_timer.stop();

		_trace << "cudaMallocPitch";
		_trace << " pointer = " << *devPtr;
		_trace << " pitch = " << *pitch;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMallocArray( cudaArray** array, 
		const cudaChannelFormatDesc* desc, size_t width, size_t height )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMallocArray( array, 
			desc, width, height );
		_timer.stop();

		_trace << "cudaMallocArray";
		_trace << " pointer = " << *array;
		_trace << " x = " << desc->x;
		_trace << " y = " << desc->y;
		_trace << " z = " << desc->z;
		_trace << " format = " << desc->f;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaFree( void* devPtr )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaFree( devPtr );
		_timer.stop();

		_trace << "cudaFree";
		_trace << " pointer = " << devPtr;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaFreeHost( void* ptr )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaFreeHost( ptr );
		_timer.stop();

		_trace << "cudaFreeHost";
		_trace << " pointer = " << ptr;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaFreeArray( cudaArray* array )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaFreeArray( array );
		_timer.stop();

		_trace << "cudaFreeArray";
		_trace << " pointer = " << array;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaHostAlloc( 
		void** pHost, size_t bytes, unsigned int flags )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaHostAlloc( pHost, bytes, flags );
		_timer.stop();

		_trace << "cudaHostAlloc";
		_trace << " pointer = " << *pHost;
		_trace << " bytes = " << bytes;
		_trace << " flags = " << flags;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaHostGetDevicePointer( 
		void** pDevice, void* pHost, unsigned int flags )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaHostGetDevicePointer( pDevice, pHost, flags );
		_timer.stop();

		_trace << "cudaHostGetDevicePointer";
		_trace << " pointer = " << *pDevice;
		_trace << " hostPointer = " << pHost;
		_trace << " flags = " << flags;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy( 
		void* dst, const void* src, size_t count, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy( dst, src, count, kind );
		_timer.stop();

		_trace << "cudaMemcpy";
		_trace << " destination = " << dst;
		_trace << " source = " << src;
		_trace << " size = " << count;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyToArray( cudaArray* dst, 
		size_t wOffset, size_t hOffset, const void* src, 
		size_t count, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyToArray( dst, wOffset, hOffset, 
			src, count, kind );
		_timer.stop();

		_trace << "cudaMemcpyToArray";
		_trace << " destination = " << dst;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " source = " << src;
		_trace << " size = " << count;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyFromArray( void* dst, 
		const cudaArray* src, size_t wOffset, size_t hOffset, 
		size_t count, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyFromArray( dst, src, wOffset, 
			hOffset, count, kind );
		_timer.stop();

		_trace << "cudaMemcpyFromArray";
		_trace << " destination = " << dst;
		_trace << " source = " << src;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " size = " << count;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyArrayToArray( 
		cudaArray* dst, size_t wOffsetDst, size_t hOffsetDst, 
		const cudaArray* src, size_t wOffsetSrc, 
		size_t hOffsetSrc, size_t count, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyArrayToArray( dst, wOffsetDst, 
			hOffsetDst, src, wOffsetSrc, hOffsetSrc, count, kind );
		_timer.stop();

		_trace << "cudaMemcpyArrayToArray";
		_trace << " destination = " << dst;
		_trace << " wOffsetDst = " << wOffsetDst;
		_trace << " hOffsetDst = " << hOffsetDst;
		_trace << " source = " << src;
		_trace << " wOffsetSrc = " << wOffsetSrc;
		_trace << " hOffsetSrc = " << hOffsetSrc;
		_trace << " size = " << count;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy2D( void* dst, 
		size_t dpitch, const void* src, size_t spitch, size_t width, 
		size_t height, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy2D( dst, dpitch, src, spitch, 
			width, height, kind );
		_timer.stop();

		_trace << "cudaMemcpy2D";
		_trace << " destination = " << dst;
		_trace << " dpitch = " << dpitch;
		_trace << " source = " << src;
		_trace << " spitch = " << spitch;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy2DToArray( cudaArray* dst, 
		size_t wOffset, size_t hOffset, const void* src, 
		size_t spitch, size_t width, size_t height, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy2DToArray( dst, wOffset, 
			hOffset, src, spitch, width, height, kind );
		_timer.stop();

		_trace << "cudaMemcpy2DToArray";
		_trace << " destination = " << dst;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " source = " << src;
		_trace << " spitch = " << spitch;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy2DFromArray( void* dst, 
		size_t dpitch, const cudaArray* src, size_t wOffset, 
		size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy2DFromArray( dst, dpitch, 
			src, wOffset, hOffset, width, height, kind );
		_timer.stop();

		_trace << "cudaMemcpy2DFromArray";
		_trace << " destination = " << dst;
		_trace << " dpitch = " << dpitch;
		_trace << " source = " << src;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy2DArrayToArray( 
		cudaArray* dst, size_t wOffsetDst, size_t hOffsetDst, 
		const cudaArray* src, size_t wOffsetSrc, size_t hOffsetSrc, 
		size_t width, size_t height, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy2DArrayToArray( dst, 
			wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, width, 
			height, kind );
		_timer.stop();

		_trace << "cudaMemcpy2DArrayToArray";
		_trace << " destination = " << dst;
		_trace << " wOffsetDst = " << wOffsetDst;
		_trace << " hOffsetDst = " << hOffsetDst;
		_trace << " source = " << src;
		_trace << " wOffsetSrc = " << wOffsetSrc;
		_trace << " hOffsetSrc = " << hOffsetSrc;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyToSymbol( 
		const char* symbol, const void* src, size_t count, size_t offset, 
		cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyToSymbol( symbol, src, count, 
			offset, kind );
		_timer.stop();

		_trace << "cudaMemcpyToSymbol";
		_trace << " symbol = " <<(void*) symbol;
		_trace << " source = " << src;
		_trace << " bytes = " << count;
		_trace << " offset = " << offset;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyFromSymbol( void* dst, 
		const char* symbol, size_t count, size_t offset, cudaMemcpyKind kind )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyFromSymbol( dst, symbol, 
			count, offset, kind );
		_timer.stop();

		_trace << "cudaMemcpyFromSymbol";
		_trace << " destination = " << dst;
		_trace << " symbol = " << (void*) symbol;
		_trace << " bytes = " << count;
		_trace << " offset = " << offset;
		_trace << " kind = " << kind;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyAsync( void* dst, 
		const void* src, size_t count, cudaMemcpyKind kind, 
		cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyAsync( dst, src, count, 
			kind, stream );
		_timer.stop();

		_trace << "cudaMemcpyAsync";
		_trace << " destination = " << dst;
		_trace << " source = " << src;
		_trace << " bytes = " << count;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyToArrayAsync( 
		cudaArray* dst, size_t wOffset, size_t hOffset, const void* src, 
		size_t count, cudaMemcpyKind kind, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyToArrayAsync( dst, wOffset, 
			hOffset, src, count, kind, stream );
		_timer.stop();

		_trace << "cudaMemcpyToArrayAsync";
		_trace << " destination = " << dst;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " source = " << src;
		_trace << " bytes = " << count;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyFromArrayAsync( void* dst, 
		const cudaArray* src, size_t wOffset, size_t hOffset, 
		size_t count, cudaMemcpyKind kind, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyFromArrayAsync( dst, src, 
			wOffset, hOffset, count, kind, stream );
		_timer.stop();

		_trace << "cudaMemcpyFromArrayAsync";
		_trace << " destination = " << dst;
		_trace << " source = " << src;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " bytes = " << count;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy2DAsync( void* dst, 
		size_t dpitch, const void* src, size_t spitch, size_t width, 
		size_t height, cudaMemcpyKind kind, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy2DAsync( dst, dpitch, src, 
			spitch, width, height, kind, stream );
		_timer.stop();

		_trace << "cudaMemcpy2DAsync";
		_trace << " destination = " << dst;
		_trace << " dpitch = " << dpitch;
		_trace << " source = " << src;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy2DToArrayAsync( 
		cudaArray* dst, size_t wOffset, size_t hOffset, const void* src, 
		size_t spitch, size_t width, size_t height, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy2DToArrayAsync( dst, wOffset, hOffset, 
			src, spitch, width, height, kind, stream );
		_timer.stop();

		_trace << "cudaMemcpy2DToArrayAsync";
		_trace << " destination = " << dst;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " source = " << src;
		_trace << " spitch = " << spitch;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpy2DFromArrayAsync( 
		void* dst, size_t dpitch, const cudaArray* src, size_t wOffset, 
		size_t hOffset, size_t width, size_t height, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpy2DFromArrayAsync( dst, dpitch, 
			src, wOffset, hOffset, width, height, kind, stream );
		_timer.stop();

		_trace << "cudaMemcpy2DFromArrayAsync";
		_trace << " destination = " << dst;
		_trace << " dpitch = " << dpitch;
		_trace << " source = " << src;
		_trace << " wOffset = " << wOffset;
		_trace << " hOffset = " << hOffset;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyToSymbolAsync( 
		const char* symbol, const void* src, size_t count, size_t offset, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyToSymbolAsync( symbol, src, 
			count, offset, kind, stream );
		_timer.stop();

		_trace << "cudaMemcpyToSymbolAsync";
		_trace << " symbol = " <<(void*) symbol;
		_trace << " source = " << src;
		_trace << " bytes = " << count;
		_trace << " offset = " << offset;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemcpyFromSymbolAsync( 
		void* dst, const char* symbol, size_t count, size_t offset, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemcpyFromSymbolAsync( dst, symbol, 
			count, offset, kind, stream );
		_timer.stop();

		_trace << "cudaMemcpyFromSymbolAsync";
		_trace << " destination = " << dst;
		_trace << " symbol = " <<(void*) symbol;
		_trace << " bytes = " << count;
		_trace << " offset = " << offset;
		_trace << " kind = " << kind;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaMemset( void* devPtr, int value, 
		size_t count )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemset( devPtr, value, count );
		_timer.stop();

		_trace << "cudaMemset";
		_trace << " devPtr = " << devPtr;
		_trace << " value = " << value;
		_trace << " bytes = " << count;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaMemset2D( 
		void* devPtr, size_t pitch, int value, size_t width, size_t height )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaMemset2D( devPtr, pitch, value, 
			width, height );
		_timer.stop();

		_trace << "cudaMemset2D";
		_trace << " devPtr = " << devPtr;
		_trace << " pitch = " << pitch;
		_trace << " value = " << value;
		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaGetSymbolAddress( void** devPtr, 
		const char* symbol )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetSymbolAddress( devPtr, symbol );
		_timer.stop();

		_trace << "cudaGetSymbolAddress";
		_trace << " pointer = " << *devPtr;
		_trace << " symbol = " <<(void*) symbol;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGetSymbolSize( size_t* size, 
		const char* symbol )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetSymbolSize( size, symbol );
		_timer.stop();

		_trace << "cudaGetSymbolSize";
		_trace << " size = " << *size;
		_trace << " symbol = " <<(void*) symbol;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaGetDeviceCount( int* count )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetDeviceCount( count );
		_timer.stop();

		_trace << "cudaGetDeviceCount";
		_trace << " devices = " << *count;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGetDeviceProperties( 
		cudaDeviceProp* prop, int device )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetDeviceProperties( prop, device );
		_timer.stop();

		_trace << "cudaGetDeviceProperties";
		_trace << " pointer = " << prop;
		_trace << " device = " << device;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaChooseDevice( int* device, 
		const cudaDeviceProp* prop )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaChooseDevice( device, prop );
		_timer.stop();

		_trace << "cudaChooseDevice";
		_trace << " device = " << *device;
		_trace << " pointer = " << prop;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaSetDevice( int device )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaSetDevice( device );
		_timer.stop();

		_trace << "cudaSetDevice";
		_trace << " device = " << device;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGetDevice( int* device )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetDevice( device );
		_timer.stop();

		_trace << "cudaGetDevice";
		_trace << " device = " << *device;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaSetValidDevices( 
		int* device_arr, int len )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaSetValidDevices( device_arr, len );
		_timer.stop();

		_trace << "cudaSetValidDevices";
		for( int i = 0; i < len; ++i )
		{
			_trace << " element" << i << " = " << device_arr[ i ];
		}
		_trace << " length = " << len;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaSetDeviceFlags( int flags )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaSetDeviceFlags( flags );
		_timer.stop();

		_trace << "cudaSetDeviceFlags";
		_trace << " flags = " << flags;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaBindTexture( size_t* offset, 
		const textureReference* texref, const void* devPtr, 
		const cudaChannelFormatDesc* desc, size_t size )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaBindTexture( offset, texref, 
			devPtr, desc, size );
		_timer.stop();

		_trace << "cudaBindTexture";
		_trace << " offset = ";
		
		if( offset != 0 )
		{
			_trace << *offset;
		}
		else
		{
			_trace << 0;
		}
		
		_trace << " normalized = " << texref->normalized;
		_trace << " filterMode = " << texref->filterMode;
		_trace << " addressMode0 = " << texref->addressMode[ 0 ];
		_trace << " addressMode1 = " << texref->addressMode[ 1 ];
		_trace << " addressMode2 = " << texref->addressMode[ 2 ];
		_trace << " texrefX = " << texref->channelDesc.x;
		_trace << " texrefY = " << texref->channelDesc.y;
		_trace << " texrefZ = " << texref->channelDesc.z;
		_trace << " texrefFormat = " << texref->channelDesc.f;
		
		_trace << " pointer = " << devPtr;

		_trace << " x = " << desc->x;
		_trace << " y = " << desc->y;
		_trace << " z = " << desc->z;
		_trace << " format = " << desc->f;

		_trace << " size = " << size;
		
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaBindTexture2D( size_t* offset, 
		const textureReference* texref, const void* devPtr, 
		const cudaChannelFormatDesc* desc, size_t width, 
		size_t height, size_t pitch )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaBindTexture2D( offset, texref, devPtr, 
			desc, width, height, pitch );
		_timer.stop();

		_trace << "cudaBindTexture2D";
		_trace << " offset = " << *offset;
		
		_trace << " normalized = " << texref->normalized;
		_trace << " filterMode = " << texref->filterMode;
		_trace << " addressMode0 = " << texref->addressMode[ 0 ];
		_trace << " addressMode1 = " << texref->addressMode[ 1 ];
		_trace << " addressMode2 = " << texref->addressMode[ 2 ];
		_trace << " texrefX = " << texref->channelDesc.x;
		_trace << " texrefY = " << texref->channelDesc.y;
		_trace << " texrefZ = " << texref->channelDesc.z;
		_trace << " texrefFormat = " << texref->channelDesc.f;
		
		_trace << " pointer = " << devPtr;

		_trace << " x = " << desc->x;
		_trace << " y = " << desc->y;
		_trace << " z = " << desc->z;
		_trace << " format = " << desc->f;

		_trace << " width = " << width;
		_trace << " height = " << height;
		_trace << " pitch = " << pitch;

		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaBindTextureToArray( 
		const textureReference* texref, const cudaArray* array, 
		const cudaChannelFormatDesc* desc )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaBindTextureToArray( texref, 
			array, desc );
		_timer.stop();

		_trace << "cudaBindTextureToArray";

		_trace << " normalized = " << texref->normalized;
		_trace << " filterMode = " << texref->filterMode;
		_trace << " addressMode0 = " << texref->addressMode[ 0 ];
		_trace << " addressMode1 = " << texref->addressMode[ 1 ];
		_trace << " addressMode2 = " << texref->addressMode[ 2 ];
		_trace << " texrefX = " << texref->channelDesc.x;
		_trace << " texrefY = " << texref->channelDesc.y;
		_trace << " texrefZ = " << texref->channelDesc.z;
		_trace << " texrefFormat = " << texref->channelDesc.f;
		
		_trace << " array = " << array;

		_trace << " x = " << desc->x;
		_trace << " y = " << desc->y;
		_trace << " z = " << desc->z;
		_trace << " format = " << desc->f;

		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaUnbindTexture( 
		const textureReference* texref )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaUnbindTexture( texref );
		_timer.stop();

		_trace << "cudaUnbindTexture";
		_trace << " normalized = " << texref->normalized;
		_trace << " filterMode = " << texref->filterMode;
		_trace << " addressMode0 = " << texref->addressMode[ 0 ];
		_trace << " addressMode1 = " << texref->addressMode[ 1 ];
		_trace << " addressMode2 = " << texref->addressMode[ 2 ];
		_trace << " texrefX = " << texref->channelDesc.x;
		_trace << " texrefY = " << texref->channelDesc.y;
		_trace << " texrefZ = " << texref->channelDesc.z;
		_trace << " texrefFormat = " << texref->channelDesc.f;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGetTextureAlignmentOffset( 
		size_t* offset, const textureReference* texref )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetTextureAlignmentOffset( 
			offset, texref );
		_timer.stop();

		_trace << "cudaGetTextureAlignmentOffset";
		_trace << " offset = " << *offset;
		_trace << " normalized = " << texref->normalized;
		_trace << " filterMode = " << texref->filterMode;
		_trace << " addressMode0 = " << texref->addressMode[ 0 ];
		_trace << " addressMode1 = " << texref->addressMode[ 1 ];
		_trace << " addressMode2 = " << texref->addressMode[ 2 ];
		_trace << " texrefX = " << texref->channelDesc.x;
		_trace << " texrefY = " << texref->channelDesc.y;
		_trace << " texrefZ = " << texref->channelDesc.z;
		_trace << " texrefFormat = " << texref->channelDesc.f;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGetTextureReference( 
		const textureReference** texref, const char* symbol )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetTextureReference( texref, symbol );
		_timer.stop();

		_trace << "cudaGetTextureReference";
		_trace << " normalized = " << (*texref)->normalized;
		_trace << " filterMode = " << (*texref)->filterMode;
		_trace << " addressMode0 = " << (*texref)->addressMode[ 0 ];
		_trace << " addressMode1 = " << (*texref)->addressMode[ 1 ];
		_trace << " addressMode2 = " << (*texref)->addressMode[ 2 ];
		_trace << " texrefX = " << (*texref)->channelDesc.x;
		_trace << " texrefY = " << (*texref)->channelDesc.y;
		_trace << " texrefZ = " << (*texref)->channelDesc.z;
		_trace << " texrefFormat = " << (*texref)->channelDesc.f;
		_trace << " symbol = " <<(void*) symbol;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaGetChannelDesc( 
		cudaChannelFormatDesc* desc, const cudaArray* array )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetChannelDesc( desc, array );
		_timer.stop();

		_trace << "cudaGetChannelDesc";

		_trace << " x = " << desc->x;
		_trace << " y = " << desc->y;
		_trace << " z = " << desc->z;
		_trace << " format = " << desc->f;

		_trace << " pointer = " << array;

		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaChannelFormatDesc TraceGeneratingCudaRuntime::cudaCreateChannelDesc( 
		int x, int y, int z, int w, cudaChannelFormatKind f )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaChannelFormatDesc desc = _runtime.cudaCreateChannelDesc( x, 
			y, z, w, f );
		_timer.stop();

		_trace << "cudaCreateChannelDesc";

		_trace << " x = " << x;
		_trace << " y = " << y;
		_trace << " z = " << z;
		_trace << " w = " << w;
		_trace << " format = " << f;

		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return desc;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaGetLastError( void )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGetLastError();
		_timer.stop();

		_trace << "cudaGetLastError";
		_trace << " error = " << status;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	const char* TraceGeneratingCudaRuntime::cudaGetErrorString( 
		cudaError_t error )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		const char* string = _runtime.cudaGetErrorString( error );
		_timer.stop();

		_trace << "cudaGetErrorString";
		_trace << " string = \"" << string << "\"";
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return string;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaConfigureCall( dim3 gridDim, 
		dim3 blockDim, size_t sharedMem, cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaConfigureCall( gridDim, 
			blockDim, sharedMem, stream );
		_timer.stop();

		_trace << "cudaConfigureCall";
		_trace << " gridX = " << gridDim.x;
		_trace << " gridY = " << gridDim.y;
		_trace << " gridZ = " << gridDim.z;

		_trace << " blockX = " << blockDim.x;
		_trace << " blockY = " << blockDim.y;
		_trace << " blockZ = " << blockDim.z;

		_trace << " sharedMem = " << sharedMem;
		_trace << " stream = " << stream;

		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaSetupArgument( const void* arg, 
		size_t size, size_t offset )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaSetupArgument( arg, size, offset );
		_timer.stop();

		_trace << "cudaSetupArgument";
		_trace << " size = " << size;
		for( unsigned int i = 0; i < size; ++i )
		{
			_trace << " arg" << i << " = " << (int)((char*)arg)[i];
		}
		_trace << " offset = " << offset;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaLaunch( const char* entry )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaLaunch( entry );
		_timer.stop();

		_trace << "cudaLaunch";
		_trace << " entry = " << (void*) entry;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaFuncGetAttributes( 
		cudaFuncAttributes* attr, const char* func )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaFuncGetAttributes( attr, func );
		_timer.stop();

		_trace << "cudaFuncGetAttributes";
		_trace << " sharedBytes = " << attr->sharedSizeBytes;
		_trace << " constBytes = " << attr->constSizeBytes;
		_trace << " localBytes = " << attr->localSizeBytes;
		_trace << " maxThreadsPerBlock = " << attr->maxThreadsPerBlock;
		_trace << " numRegs = " << attr->numRegs;
		_trace << " function = " << (void*)func;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaStreamCreate( 
		cudaStream_t* pStream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaStreamCreate( pStream );
		_timer.stop();

		_trace << "cudaStreamCreate";
		_trace << " stream = " << *pStream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaStreamDestroy( 
		cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaStreamDestroy( stream );
		_timer.stop();

		_trace << "cudaStreamDestroy";
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaStreamSynchronize( 
		cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaStreamSynchronize( stream );
		_timer.stop();

		_trace << "cudaStreamSynchronize";
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaStreamQuery( 
		cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaStreamQuery( stream );
		_timer.stop();

		_trace << "cudaStreamQuery";
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaEventCreate( 
		cudaEvent_t* event )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaEventCreate( event );
		_timer.stop();

		_trace << "cudaEventCreate";
		_trace << " event = " << *event;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaEventCreateWithFlags( 
		cudaEvent_t* event, int flags )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaEventCreateWithFlags( event, flags );
		_timer.stop();

		_trace << "cudaEventCreateWithFlags";
		_trace << " event = " << *event;
		_trace << " flags = " << flags;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaEventRecord( cudaEvent_t event, 
		cudaStream_t stream )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaEventRecord( event, stream );
		_timer.stop();

		_trace << "cudaEventRecord";
		_trace << " event = " << event;
		_trace << " stream = " << stream;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaEventQuery( cudaEvent_t event )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaEventQuery( event );
		_timer.stop();

		_trace << "cudaEventQuery";
		_trace << " event = " << event;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaEventSynchronize( 
		cudaEvent_t event )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaEventSynchronize( event );
		_timer.stop();

		_trace << "cudaEventSynchronize";
		_trace << " event = " << event;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaEventDestroy( 
		cudaEvent_t event )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaEventDestroy( event );
		_timer.stop();

		_trace << "cudaEventDestroy";
		_trace << " event = " << event;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaEventElapsedTime( float* ms, 
		cudaEvent_t start, cudaEvent_t end )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaEventElapsedTime( ms, start, end );
		_timer.stop();

		_trace << "cudaEventElapsedTime";
		_trace << " ms = " << *ms;
		_trace << " start = " << start;
		_trace << " end = " << end;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaSetDoubleForDevice( double* d )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaSetDoubleForDevice( d );
		_timer.stop();

		_trace << "cudaSetDoubleForDevice";
		_trace << " d = " << *d;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaSetDoubleForHost( double* d )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaSetDoubleForHost( d );
		_timer.stop();

		_trace << "cudaSetDoubleForHost";
		_trace << " d = " << *d;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaThreadExit( void )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaThreadExit();
		_timer.stop();

		_trace << "cudaThreadExit";
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaThreadSynchronize( void )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaThreadSynchronize();
		_timer.stop();

		_trace << "cudaThreadSynchronize";
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	

	cudaError_t TraceGeneratingCudaRuntime::cudaDriverGetVersion( 
		int* driverVersion )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaDriverGetVersion( driverVersion );
		_timer.stop();

		_trace << "cudaDriverGetVersion";
		_trace << " version = " << *driverVersion;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaRuntimeGetVersion( 
		int* runtimeVersion )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaRuntimeGetVersion( runtimeVersion );
		_timer.stop();

		_trace << "cudaRuntimeGetVersion";
		_trace << " runtimeVersion = " << *runtimeVersion;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGLSetGLDevice( int device )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGLSetGLDevice( device );
		_timer.stop();

		_trace << "cudaGLSetGLDevice";
		_trace << " device = " << device;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGLRegisterBufferObject( 
		GLuint bufObj )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGLRegisterBufferObject( bufObj );
		_timer.stop();

		_trace << "cudaGLRegisterBufferObject";
		_trace << " buffer = " << bufObj;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGLMapBufferObject( 
		void** devPtr, GLuint bufObj )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGLMapBufferObject( devPtr, bufObj );
		_timer.stop();

		_trace << "cudaGLMapBufferObject";
		_trace << " pointer = " << *devPtr;
		_trace << " buffer = " << bufObj;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGLUnmapBufferObject( 
		GLuint bufObj )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGLUnmapBufferObject( bufObj );
		_timer.stop();

		_trace << "cudaGLUnmapBufferObject";
		_trace << " buffer = " << bufObj;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	cudaError_t TraceGeneratingCudaRuntime::cudaGLUnregisterBufferObject( 
		GLuint bufObj )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		cudaError_t status = _runtime.cudaGLUnregisterBufferObject( bufObj );
		_timer.stop();

		_trace << "cudaGLUnregisterBufferObject";
		_trace << " buffer = " << bufObj;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	void TraceGeneratingCudaRuntime::cudaTextureFetch( const void* tex, 
		void* index, int integer, void* val )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaTextureFetch( tex, index, integer, val );
		_timer.stop();

		_trace << "cudaTextureFetch";
		_trace << " tex = " << tex;
		_trace << " indexPointer = " << index;
		_trace << " integer = " << integer;
		_trace << " valuePointer = " << val;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();
	}
	

	void** TraceGeneratingCudaRuntime::cudaRegisterFatBinary( void* fatCubin )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		void** handle = _runtime.cudaRegisterFatBinary( fatCubin );
		_timer.stop();

		_trace << "cudaRegisterFatBinary";
		_trace << " handle = " << handle;
		_trace << " pointer = " << fatCubin;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return handle;
	}
	
	void TraceGeneratingCudaRuntime::cudaUnregisterFatBinary( 
		void** fatCubinHandle )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaUnregisterFatBinary( fatCubinHandle );
		_timer.stop();

		_trace << "cudaUnregisterFatBinary";
		_trace << " handle = " << fatCubinHandle;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";
		_timer.start();

	}
	
	void TraceGeneratingCudaRuntime::cudaRegisterVar( void** fatCubinHandle, 
		char* hostVar, char* deviceAddress, const char* deviceName, int ext, 
		int size, int constant, int global )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaRegisterVar( fatCubinHandle, hostVar, deviceAddress, 
			deviceName, ext, size, constant, global );
		_timer.stop();

		_trace << "cudaRegisterVar";
		_trace << " handle = " << fatCubinHandle;
		_trace << " hostVar = " << (void*)hostVar;
		_trace << " deviceAddress = " << deviceAddress;
		_trace << " deviceName = " << deviceName;
		_trace << " ext = " << ext;
		_trace << " size = " << size;
		_trace << " constant = " << constant;
		_trace << " global = " << global;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();
	}
	
	void TraceGeneratingCudaRuntime::cudaRegisterTexture( void** fatCubinHandle, 
		const struct textureReference* hostVar, const void** deviceAddress, 
		const char* deviceName, int dim, int norm, int ext )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaRegisterTexture( fatCubinHandle, hostVar, 
			deviceAddress, deviceName, dim, norm, ext );
		_timer.stop();

		_trace << "cudaRegisterTexture";
		_trace << " handle = " << fatCubinHandle;
		_trace << " normalized = " << hostVar->normalized;
		_trace << " filterMode = " << hostVar->filterMode;
		_trace << " addressMode0 = " << hostVar->addressMode[ 0 ];
		_trace << " addressMode1 = " << hostVar->addressMode[ 1 ];
		_trace << " addressMode2 = " << hostVar->addressMode[ 2 ];
		_trace << " texrefX = " << hostVar->channelDesc.x;
		_trace << " texrefY = " << hostVar->channelDesc.y;
		_trace << " texrefZ = " << hostVar->channelDesc.z;
		_trace << " texrefFormat = " << hostVar->channelDesc.f;
		_trace << " deviceAddress = " << deviceAddress;
		_trace << " deviceName = " << deviceName;
		_trace << " dim = " << dim;
		_trace << " norm = " << norm;
		_trace << " ext = " << ext;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();
	}
	
	void TraceGeneratingCudaRuntime::cudaRegisterShared( 
		void** fatCubinHandle, void** devicePtr )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaRegisterShared( fatCubinHandle, devicePtr );
		_timer.stop();

		_trace << "cudaRegisterShared";
		_trace << " handle = " << fatCubinHandle;
		_trace << " pointer = " << *devicePtr;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();
	}
	
	void TraceGeneratingCudaRuntime::cudaRegisterSharedVar( 
		void** fatCubinHandle, void** devicePtr, size_t size, size_t alignment, 
		int storage )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaRegisterSharedVar( fatCubinHandle, devicePtr, 
			size, alignment, storage );
		_timer.stop();

		_trace << "cudaRegisterSharedVar";
		_trace << " handle = " << fatCubinHandle;
		_trace << " pointer = " << *devicePtr;
		_trace << " size = " << size;
		_trace << " alignment = " << alignment;
		_trace << " storage = " << storage;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();
	}
	
	void TraceGeneratingCudaRuntime::cudaRegisterFunction( 
		void** fatCubinHandle, const char* hostFun, char* deviceFun, 
		const char* deviceName, int thread_limit, uint3* tid, uint3* bid, 
		dim3* bDim, dim3* gDim, int* wSize )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaRegisterFunction( fatCubinHandle, 
			hostFun, deviceFun, deviceName, thread_limit, tid, bid, bDim, 
			gDim, wSize );
		_timer.stop();

		_trace << "cudaRegisterFunction";
		_trace << " handle = " << fatCubinHandle;
		_trace << " hostFunction = " << (void*) hostFun;
		_trace << " deviceFunction = " << deviceFun;
		_trace << " deviceName = " << deviceName;
		_trace << " threadLimit = " << thread_limit;
		_trace << " tid = " << tid;
		if( tid != 0 )
		{
			_trace << " tidX = " << tid->x;
			_trace << " tidY = " << tid->y;
			_trace << " tidZ = " << tid->z;
		}
		_trace << " tid = " << bid;
		if( bid != 0 )
		{
			_trace << " bidX = " << bid->x;
			_trace << " bidY = " << bid->y;
			_trace << " bidZ = " << bid->z;
		}
		_trace << " tid = " << bDim;
		if( bDim != 0 )
		{
			_trace << " bDimX = " << bDim->x;
			_trace << " bDimY = " << bDim->y;
			_trace << " bDimZ = " << bDim->z;
		}
		_trace << " tid = " << gDim;
		if( gDim != 0 )
		{
			_trace << " gDimX = " << gDim->x;
			_trace << " gDimY = " << gDim->y;
			_trace << " gDimZ = " << gDim->z;
		}
		_trace << " wSize = " << wSize;
		if( wSize != 0 )
		{
			_trace << " wSize = " << *wSize;
		}
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();
	}
	
	void TraceGeneratingCudaRuntime::cudaMutexOperation( int lock )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		_runtime.cudaMutexOperation( lock );
		_timer.stop();

		_trace << "cudaMutexOperation";
		_trace << " lock = " << lock;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();
	}
	
	int TraceGeneratingCudaRuntime::cudaSynchronizeThreads( 
		void** one, void* two )
	{
		_timer.stop();
		_trace << "slack time = " << _timer.seconds() << "\n";
		
		_timer.start();
		int status = _runtime.cudaSynchronizeThreads( one, two );
		_timer.stop();

		_trace << "cudaSynchronizeThreads";
		_trace << " one = " << *one;
		_trace << " two = " << two;
		_trace << " time = " << _timer.seconds();
		_trace << "\n";

		_timer.start();

		return status;
	}
	
	void TraceGeneratingCudaRuntime::addTraceGenerator( 
		trace::TraceGenerator& gen, bool persistent, bool safe )
	{
		_runtime.addTraceGenerator( gen, persistent, safe );	
	}
	
	void TraceGeneratingCudaRuntime::clearTraceGenerators( bool safe )
	{
		_runtime.clearTraceGenerators( safe );
	}

	void TraceGeneratingCudaRuntime::configure( const Configuration& c )
	{
		std::string tracefile;
		parse( "CudaRuntimeApiTraceFile", tracefile, 
			"traces/CudaApi.trace", c );
		_trace.open( tracefile.c_str() );
	}
	
	void TraceGeneratingCudaRuntime::limitWorkerThreads( unsigned int limit )
	{
		_runtime.limitWorkerThreads( limit );
	}
	
	void TraceGeneratingCudaRuntime::registerPTXModule( std::istream& stream, 
		const std::string& name )
	{
		_runtime.registerPTXModule( stream, name );
	}
		
	const char* TraceGeneratingCudaRuntime::getKernelPointer(
		const std::string& name, const std::string& module )
	{
		return _runtime.getKernelPointer( name, module );
	}

	void** TraceGeneratingCudaRuntime::getFatBinaryHandle( 
		const std::string& name )
	{
		return _runtime.getFatBinaryHandle( name );
	}

	void TraceGeneratingCudaRuntime::clearErrors( )
	{
		return _runtime.clearErrors( );
	}
}

#endif

