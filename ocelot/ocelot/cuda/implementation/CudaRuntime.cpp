/*!

	\file CudaRuntime.cpp
	
	\date Wednesday March 25, 2009
	\author Gregory Diamos
	
	\brief The source file for the CudaRuntime class.	

*/

#ifndef CUDA_RUNTIME_CPP_INCLUDED
#define CUDA_RUNTIME_CPP_INCLUDED

#include <ocelot/cuda/interface/CudaRuntime.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/XmlParser.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <cassert>
#include <cstring>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_ALL_PTX 0
#define CATCH_RUNTIME_EXCEPTIONS 1

namespace cuda
{

	CudaRuntime::ThreadContext::ThreadContext() :
		nextStream(1), nextEvent(1), lastError(cudaSuccess)
	{
	
	}

	unsigned int CudaRuntime::Array::bytes() const
	{
		
		return length * width * height * CudaRuntime::bytes( channel );
		
	}

	CudaRuntime::ArchitectureMap::iterator CudaRuntime::_getTranslatedKernel( 
		SymbolMap::iterator kernel )
	{	
		FatBinaryMap::iterator binary = _binaries.find( kernel->second.handle );
		assert( binary != _binaries.end() );
		
		KernelMap::iterator architectures = binary->second.kernels.find( 
			kernel->second.kernel );
		
		if( architectures == binary->second.kernels.end() )
		{
	
			ArchitectureMap map;
		
			architectures = binary->second.kernels.insert( 
				std::make_pair( kernel->second.kernel, 
				map ) ).first;
		
		}

		ArchitectureMap::iterator translatedKernel = 
			architectures->second.find( context.getSelectedISA() );
		
		// possilbly translate kernels
		if( translatedKernel == architectures->second.end() )
		{
		
			ir::Kernel* generated = context.getKernel( 
				context.getSelectedISA(), binary->second.binary.ident, 
				kernel->second.kernel );
				
			if( generated != 0 )
			{
									
				translatedKernel = architectures->second.insert( 
					std::make_pair( context.getSelectedISA(), 
					generated ) ).first;
			
			}
			
			if( translatedKernel == architectures->second.end() )
			{
			
				std::stringstream stream;
				stream << "From Fat Binary \"" << binary->second.binary.ident 
					<< "\" failed to translate kernel \"" 
					<< kernel->second.kernel << "\"";
					
				throw hydrazine::Exception( formatError(stream.str()), 5 );			
			}
		
		}
		
		report( "Obtained translated kernel." );
		return translatedKernel;
	}

	cudaDeviceProp CudaRuntime::convert( const executive::Device& device )
	{
	
		cudaDeviceProp properties;
		
		hydrazine::strlcpy( properties.name, device.name.c_str(), 256 );
		properties.totalGlobalMem = device.totalMemory;
		properties.sharedMemPerBlock = device.sharedMemPerBlock;
		properties.regsPerBlock = device.regsPerBlock;
		properties.warpSize = device.SIMDWidth;
		properties.memPitch = device.memPitch;
		properties.maxThreadsPerBlock = device.maxThreadsPerBlock;
		properties.maxThreadsDim[0] = device.maxThreadsDim[0];
		properties.maxThreadsDim[1] = device.maxThreadsDim[1];
		properties.maxThreadsDim[2] = device.maxThreadsDim[2];
		properties.maxGridSize[0] = device.maxGridSize[0];
		properties.maxGridSize[1] = device.maxGridSize[1];
		properties.maxGridSize[2] = device.maxGridSize[2];
		properties.clockRate = device.clockRate;
		properties.totalConstMem = device.totalConstantMemory;
		properties.major = 1;
		properties.minor = 3;
		properties.textureAlignment = device.textureAlign;
		properties.deviceOverlap = device.memcpyOverlap;
		properties.multiProcessorCount = device.multiprocessorCount;
		properties.kernelExecTimeoutEnabled = false;
		properties.computeMode = cudaComputeModeDefault;
		properties.integrated = true;
		properties.canMapHostMemory = true;
		memset(properties.__cudaReserved, 0, sizeof(properties.__cudaReserved));
		
		return properties;
	
	}
	
	ir::Texture CudaRuntime::convert( const cudaChannelFormatDesc& desc)
	{
		ir::Texture texture;
		
		texture.x = desc.x;
		texture.y = desc.y;
		texture.z = desc.z;
		texture.w = desc.w;
		
		switch( desc.f )
		{
			case cudaChannelFormatKindUnsigned: 
				texture.type = ir::Texture::Unsigned;
				break;
			case cudaChannelFormatKindSigned: 
				texture.type = ir::Texture::Signed;
				break;
			case cudaChannelFormatKindFloat: 
				texture.type = ir::Texture::Float;
				break;
			default:
				break;
		}
		
		return texture;
	
	}
	
	cudaChannelFormatDesc CudaRuntime::convert( const ir::Texture& texture)
	{
		cudaChannelFormatDesc desc = { texture.x, texture.y, texture.z, 
			texture.w };
		
		switch( texture.type )
		{
			case ir::Texture::Unsigned: 
				desc.f = cudaChannelFormatKindUnsigned;
				break;
			case ir::Texture::Signed: 
				desc.f = cudaChannelFormatKindSigned;
				break;
			case ir::Texture::Float: 
				desc.f = cudaChannelFormatKindFloat;
				break;
			default:
				break;
		}
		
		return desc;
	
	}

	ir::Texture::AddressMode CudaRuntime::convert(cudaTextureAddressMode m)
	{
		switch( m )
		{
			case cudaAddressModeWrap: return ir::Texture::Wrap;
			case cudaAddressModeClamp: return ir::Texture::Clamp;
		}
		return ir::Texture::Wrap;
	}

	ir::Texture::Interpolation CudaRuntime::convert(cudaTextureFilterMode m)
	{
		switch( m )
		{
			case cudaFilterModePoint: return ir::Texture::Nearest;
			case cudaFilterModeLinear: return ir::Texture::Linear;
		}
		return ir::Texture::Linear;
	}
	
	std::string CudaRuntime::formatError( const std::string& message )
	{
		std::string result = "==Ocelot== ";
		for(std::string::const_iterator mi = message.begin(); 
			mi != message.end(); ++mi)
		{
			result.push_back(*mi);
			if(*mi == '\n')
			{
				result.append("==Ocelot== ");
			}
		}
		return result;
	}

	unsigned int CudaRuntime::bytes( const cudaChannelFormatDesc& desc )
	{
		unsigned int dimensions = 0;
		
		if(desc.x > 0)
		{
			++dimensions;
		}
		if(desc.y > 0)
		{
			++dimensions;
		}
		if(desc.z > 0)
		{
			++dimensions;
		}
		if(desc.w > 0)
		{
			++dimensions;
		}
		
		switch( desc.f )
		{
			case cudaChannelFormatKindSigned: 
				return dimensions * sizeof(int);
			case cudaChannelFormatKindUnsigned: 
				return dimensions * sizeof(unsigned int);
			case cudaChannelFormatKindFloat: 
				return dimensions * sizeof(float);
			case cudaChannelFormatKindNone: 
				return dimensions * sizeof(long long unsigned int);
		}
		
		return 0;
	}

	CudaRuntime::CudaRuntime()
	{
	
		pthread_mutex_init( &_mutex, 0 );
		_handle = 0;
		
		try 
		{
			hydrazine::XmlParser parser("default.config");
			hydrazine::XmlTree tree = parser.tree();
		
			hydrazine::XmlTree::iterator position = tree.begin();
			position.descend("cuda");
			position.descend("CudaRuntime");
			configure(position.map());
		}
		catch ( const hydrazine::Exception& e )
		{
			report("Could not find Ocelot config file.");
			report("Hit parser exception " + e.message );
			Configuration blank;
			configure(blank);
		}
		
		report("Ocelot Runtime Initialized.");
	
	}

	CudaRuntime::~CudaRuntime()
	{
	
		pthread_mutex_destroy( &_mutex );

		for( MemoryMap::iterator fi = _memory.begin(); 
			fi != _memory.end(); ++fi )
		{
	
			std::cerr << "==Ocelot== Pinned Memory Leak Detected\n";
			std::cerr << "==Ocelot==  " << fi->second.size 
				<< " bytes at " << (int*)fi->first << " never freed.\n"; 
			delete[] fi->first;
	
		}
		
		for( ArrayMap::iterator array = _arrays.begin(); 
			array != _arrays.end();	++array )
		{	
			std::cerr << "==Ocelot== Array Memory Leak Detected\n";
			std::cerr << "==Ocelot==  " << array->second.bytes() 
				<<" bytes at " << array->second.array << " never freed.\n"; 
			context.free( array->second.array );
		}
		
		for( OpenGLBufferMap::iterator buffer = _openGLBuffers.begin(); 
			buffer != _openGLBuffers.end(); ++buffer )
		{
		
			std::cerr << "==Ocelot== Open GL Buffer Error.\n";
			std::cerr << "==Ocelot==  Never unregistered buffer " 
				<< buffer->first << "\n";
				
			if( buffer->second != 0 )
			{
			
				std::cerr << "==Ocelot==  still mapped to " 
					<< buffer->second << "\n";		
		
			}
			
		}
		
		report("Ocelot Runtime Destroyed.");
	
	}
	
	void CudaRuntime::lock()
	{
	
		pthread_mutex_lock( &_mutex );
	
	}
	
	void CudaRuntime::unlock()
	{
	
		pthread_mutex_unlock( &_mutex );
	
	}
	
	void CudaRuntime::setContext()
	{
	
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );		
		assert( !context.devices.empty() );
		
		if( thread == _threads.end() )
		{
		
			ThreadContext threadContext;
			threadContext.guid = context.devices[0].guid;
			threadContext.ctaDimensions.x = 1;
			threadContext.ctaDimensions.y = 1;
			threadContext.ctaDimensions.z = 1;
			threadContext.kernelDimensions.x = 1;
			threadContext.kernelDimensions.y = 1;
			threadContext.kernelDimensions.z = 1;
			threadContext.shared = 0;
			threadContext.flags = 0;
			thread = _threads.insert( std::make_pair( id, 
				threadContext ) ).first;
		
		}
		
		if( !context.select( thread->second.guid ) )
		{
		
			throw hydrazine::Exception( 
				formatError( "Failed to select ocelot device." ), 
				thread->second.guid );
		
		}
	
	}
	
	void CudaRuntime::destroyContext()
	{
	
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		_threads.erase( thread );
	
	}
	
	cudaError_t CudaRuntime::lastError() const
	{
	
		pthread_t id = pthread_self();
		
		ThreadMap::const_iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		return thread->second.lastError;
	
	}

	void CudaRuntime::setDevice( int device )
	{
	
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		assert( (unsigned int)device < context.devices.size() );

		report( "Setting device from " << context.getSelected() << " to " 
			<< device );

		bool pass = context.select( context.devices[ device ].guid );

		if( !pass )
		{
		
			throw hydrazine::Exception( 
				formatError( "Tried to set to invalid device." ), 
				cudaErrorInvalidDevice );
		
		}
		
		thread->second.guid = context.devices[ device ].guid;
			
	}
	
	void CudaRuntime::setFlags( int flags )
	{
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		thread->second.flags = flags;		
	}
	
	int CudaRuntime::bestDevice( const cudaDeviceProp *prop ) const
	{
		typedef std::deque< int > ValidVector;
		ValidVector valid;
		
		pthread_t id = pthread_self();
		
		ThreadMap::const_iterator thread = _threads.find( id );
		assert( thread != _threads.end() );

		int result = 0;

		for( executive::Executive::DeviceVector::const_iterator 
			device = context.devices.begin(); 
			device != context.devices.end(); ++device )
		{
			if( device->major >= prop->major && device->minor >= prop->minor )
			{
				valid.push_back( device - context.devices.begin() );
			}
		}
		
		for( ValidVector::iterator next = valid.begin(); 
			next != valid.end(); ++next )
		{
			if( context.devices[result].totalMemory < prop->totalGlobalMem )
			{
				if( context.devices[*next].totalMemory < prop->totalGlobalMem )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( (unsigned int) context.devices[result].sharedMemPerBlock 
				< prop->sharedMemPerBlock )
			{
				if( (unsigned int) context.devices[*next].sharedMemPerBlock 
					< prop->sharedMemPerBlock )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( context.devices[result].regsPerBlock 
				< prop->regsPerBlock )
			{
				if( context.devices[*next].regsPerBlock < prop->regsPerBlock )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( context.devices[result].SIMDWidth 
				< prop->warpSize )
			{
				if( context.devices[*next].SIMDWidth < prop->warpSize )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( context.devices[result].maxThreadsPerBlock 
				< prop->maxThreadsPerBlock )
			{
				if( context.devices[*next].maxThreadsPerBlock 
					< prop->maxThreadsPerBlock )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( (unsigned int) context.devices[result].totalConstantMemory 
				< prop->totalConstMem )
			{
				if( (unsigned int) context.devices[*next].totalConstantMemory 
					< prop->totalConstMem )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( context.devices[result].multiprocessorCount 
				< prop->multiProcessorCount )
			{
				if( context.devices[*next].multiprocessorCount 
					< prop->multiProcessorCount )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( context.devices[result].clockRate 
				< prop->clockRate )
			{
				if( context.devices[*next].clockRate < prop->clockRate )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}
			if( context.devices[result].memcpyOverlap 
				< prop->deviceOverlap )
			{
				if( context.devices[*next].memcpyOverlap < prop->deviceOverlap )
				{
					continue;
				}
				else
				{
					result = *next;
					continue;
				}
			}		
		}

		return result;
					
	}

	unsigned int CudaRuntime::registerFatBinary( const FatBinary& binary )
	{
	
		report( "Registering fat binary " << binary.ident << " to handle " 
			<< _handle );
	
		StringMap::iterator name = _binaryNames.find( binary.ident );
		FatBinaryMap::iterator bi;
		
		if( name != _binaryNames.end() )
		{
		
			bi = _binaries.find( name->second );
			assert( bi != _binaries.end() );
			
			pthread_t id = pthread_self();
			
			if( bi->second.threads.count( id ) != 0 )
			{
			
				throw hydrazine::Exception( 
					formatError( "Fat Binary \"" + name->first + 
					"\" already registered." ), 2 );
			
			}
		
		}
		else
		{
		
			// register all of the PTX files
			report( "Loading PTX programs from \"" << binary.ident );
			if( binary.ptx->ptx != 0 ) 
			{
			
				std::stringstream ptx( binary.ptx->ptx );
				reportE( REPORT_ALL_PTX, ptx.str() );
		
				context.loadModule( binary.ident, true, &ptx );
				
			}
			else
			{
				throw hydrazine::Exception( formatError( "Fat Binary \"" 
					+ std::string(binary.ident) + 
					"\" contains no PTX." ), 3 );
			}
			
			_binaryNames.insert( std::make_pair( binary.ident, _handle ) );
			
			FatBinaryContext binaryContext;
			binaryContext.binary = binary;
		
			bi = _binaries.insert( std::make_pair( _handle++, 
				binaryContext ) ).first;
		
		}
		
		bi->second.threads.insert( pthread_self() );
		
		return bi->first;
	
	}

	void CudaRuntime::unregisterFatBinary( unsigned int handle )
	{
	
		FatBinaryMap::iterator binary = _binaries.find( handle );
		
		if( binary == _binaries.end() )
		{
		
			std::stringstream stream;
			stream << handle;
			throw hydrazine::Exception(
				formatError( "Invalid fat binary handle\"" + stream.str() 
				+ "\""), 3 );
		
		}

		ThreadSet::iterator thread = 
			binary->second.threads.find( pthread_self() );
		
		if( thread == binary->second.threads.end() )
		{
		
			std::stringstream stream;
			stream << "Thread " << pthread_self() 
				<< " never registered fat binary \"" 
				<< binary->second.binary.ident << "\"";
			throw hydrazine::Exception( formatError( stream.str() ), 4 );
		
		}
		
		for( GlobalMap::iterator global = binary->second.globals.begin(); 
			global != binary->second.globals.end(); ++global )
		{
		
			context.freeGlobal( global->first, binary->second.binary.ident );
		
		}
		
		binary->second.threads.erase( thread );
		
		if( binary->second.threads.empty() )
		{
		
			StringMap::iterator 
				name = _binaryNames.find( binary->second.binary.ident );
			assert( name != _binaryNames.end() );

			// unregister all of the PTX files
			context.unloadModule( binary->second.binary.ident );
			
			_binaryNames.erase( name );
			_binaries.erase( binary );
	
		}
	
	}
	
	void CudaRuntime::configureCall( dim3 kernel, dim3 cta, 
		unsigned int memory )
	{
	
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		report( "Configuring next cuda launch." );
		report( " Kernel" );
		report( "  x " << kernel.x );
		report( "  y " << kernel.y );
		report( "  z " << kernel.z );
		report( " CTA" );
		report( "  x " << cta.x );
		report( "  y " << cta.y );
		report( "  z " << cta.z );
		report( " Shared Memory " << memory );

		if( kernel.x > (unsigned int) context.devices[ 
			context.getSelected() ].maxGridSize[0] )
		{
			std::stringstream stream;
			stream << "Kernel x dimension " << kernel.x 
				<< " is greater than max " 
				<< context.devices[ 
				context.getSelected() ].maxGridSize[0] << ".";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidConfiguration );
		}

		if( kernel.y > (unsigned int) context.devices[ 
			context.getSelected() ].maxGridSize[1] )
		{
			std::stringstream stream;
			stream << "Kernel y dimension " << kernel.y 
				<< " is greater than max " 
				<< context.devices[ 
				context.getSelected() ].maxGridSize[1] << ".";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidConfiguration );
		}

		if( kernel.z > (unsigned int) context.devices[ 
			context.getSelected() ].maxGridSize[2] )
		{
			std::stringstream stream;
			stream << "Kernel z dimension " << kernel.z 
				<< " is greater than max " 
				<< context.devices[ 
				context.getSelected() ].maxGridSize[2] << ".";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidConfiguration );
		}

		if( cta.x > (unsigned int) context.devices[ 
			context.getSelected() ].maxThreadsDim[0] )
		{
			std::stringstream stream;
			stream << "CTA x dimension " << cta.x 
				<< " is greater than max " 
				<< context.devices[ 
				context.getSelected() ].maxThreadsDim[0] << ".";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidConfiguration );
		}

		if( cta.y > (unsigned int) context.devices[ 
			context.getSelected() ].maxThreadsDim[1] )
		{
			std::stringstream stream;
			stream << "CTA y dimension " << cta.y 
				<< " is greater than max " 
				<< context.devices[ 
				context.getSelected() ].maxThreadsDim[1] << ".";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidConfiguration );
		}

		if( cta.z > (unsigned int) context.devices[ 
			context.getSelected() ].maxThreadsDim[2] )
		{
			std::stringstream stream;
			stream << "CTA z dimension " << cta.z 
				<< " is greater than max " 
				<< context.devices[ 
				context.getSelected() ].maxThreadsDim[2] << ".";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidConfiguration );
		}

		if( cta.z * cta.y * cta.x > (unsigned int) context.devices[ 
			context.getSelected() ].maxThreadsPerBlock )
		{
			std::stringstream stream;
			stream << "Total CTA size " << ( cta.z * cta.y * cta.x ) 
				<< " is greater than max " 
				<< context.devices[ 
				context.getSelected() ].maxThreadsPerBlock << ".";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidConfiguration );
		}
		
		thread->second.kernelDimensions = kernel;
		thread->second.ctaDimensions = cta;
		thread->second.shared = memory;		
	
	}
	
	void CudaRuntime::setupArgument( const void *arg, unsigned int size, 
		unsigned int offset )
	{
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		report( "Adding argument of size " << size << " at offset " 
			<< offset << " for next cuda launch." );

		ThreadContext::ParameterMap::iterator parameter = 
			thread->second.parameters.lower_bound(offset);

		while( parameter != thread->second.parameters.begin() )
		{
			ThreadContext::ParameterMap::iterator previous = parameter;
			--previous;
		
			if( previous->first + previous->second.size() > offset )
			{			
				report( " Removed parameter at offset " << previous->first );
				thread->second.parameters.erase( previous );
				parameter = thread->second.parameters.lower_bound( offset );
				previous = parameter;
				--previous;
			}
			else
			{
				break;
			}
		}
			
		if( parameter != thread->second.parameters.end() )
		{
			ThreadContext::ParameterMap::iterator next = parameter;
			++next;
			
			while( next != thread->second.parameters.end() )
			{
				if( next->first <= offset + size )
				{
					report( " Removed parameter at offset " << next->first );
					thread->second.parameters.erase( next );
					parameter = thread->second.parameters.lower_bound( offset );

					if( parameter == thread->second.parameters.end() )
					{
						break;
					}

					next = parameter;
					++next;
				}
				else
				{
					break;
				}
			}
		}		
		
		thread->second.parameters.insert( std::make_pair( offset, 
			ThreadContext::Parameter( (char*)arg, ((char*)arg) + size ) ) );
	
	}

	void CudaRuntime::getAttributes( cudaFuncAttributes* attributes, 
		const char* symbol )
	{
		SymbolMap::iterator kernel = _symbols.find( symbol );
		if( kernel == _symbols.end() )
		{
			throw hydrazine::Exception( 
				formatError( "Could not find kernel function name." ), 
				cudaErrorInvalidDeviceFunction );
		}
		
		ArchitectureMap::iterator translatedKernel = _getTranslatedKernel( 
			kernel );
		
		// set up launch parameters and launch
		switch( context.getSelectedISA() )
		{
		
			case ir::Instruction::Emulated:
			{
				executive::EmulatedKernel* emulated = static_cast< 
					executive::EmulatedKernel* >( translatedKernel->second );
				attributes->constSizeBytes = emulated->ConstMemorySize;
				attributes->localSizeBytes = emulated->LocalMemorySize;
				attributes->maxThreadsPerBlock = context.devices[ 
					context.getSelected() ].maxThreadsPerBlock;
				attributes->numRegs = emulated->RegisterCount;
				attributes->sharedSizeBytes = emulated->SharedMemorySize;
				
				break;
			}

			default:
			{
				std::stringstream stream;
				stream << "Kernel type " << context.getSelectedISA() 
					<< " not supported.";
				throw hydrazine::Exception( formatError( stream.str() ), 6 );
			}
		
		}
		
	}

	void CudaRuntime::registerFunction( const char* symbol, 
		const std::string& name, unsigned int handle )
	{
	
		HandleAndKernel kernel;
		kernel.kernel = name;
		kernel.handle = handle;

		report( "Registering symbol " << (void*) symbol << " to function " 
			<< name << " in module " << handle);
			
		if(_symbols.count(symbol) != 0)
		{
			throw hydrazine::Exception( 
				formatError( "Registered symbol " + name + " twice." ) );		
		}
		
		_symbols.insert( std::make_pair( symbol, kernel ) );
		
	}

	void CudaRuntime::launch( const char* symbol )
	{
	
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );

		if(thread->second.lastError == cudaErrorLaunchFailure)
		{
			thread->second.lastError = cudaErrorPriorLaunchFailure;		
		}
		
		if(thread->second.lastError == cudaErrorPriorLaunchFailure)
		{
			return;		
		}

		SymbolMap::iterator kernel = _symbols.find( symbol );
		assert( kernel != _symbols.end() );
	
		ArchitectureMap::iterator translatedKernel 
			= _getTranslatedKernel( kernel );
		
		// set up launch parameters and launch
		switch( context.getSelectedISA() )
		{
		
			case ir::Instruction::Emulated:
			{
			
				executive::EmulatedKernel* emulated = static_cast< 
					executive::EmulatedKernel* >( translatedKernel->second );

				report( "Setting up parameters for emulated kernel \"" 
					<< emulated->name << "\"." );
				
				if( emulated->ConstMemorySize 
					> ( unsigned int ) context.devices[ 
					context.getSelected() ].totalConstantMemory )
				{
					#if CUDA_VERBOSE == 1
					std::cerr << "==Ocelot== Out of const memory for kernel \"" 
						<< emulated->name 
						<< "\" : \n==Ocelot==\tpreallocated ";
					std::cerr << emulated->ConstMemorySize 
						<< " is greater than available " 
						<< context.devices[ 
						context.getSelected() ].totalConstantMemory 
						<< " for device " << context.devices[ 
						context.getSelected() ].name << "\n" << std::flush;
					#endif
					thread->second.lastError = cudaErrorLaunchFailure;
					break;
				}
				
				unsigned int staticSharedSize = emulated->SharedMemorySize;
				unsigned int dynamicSharedSize = std::max( staticSharedSize, 
					thread->second.shared );
				
				if( _preallocateAllSharedMemory )
				{
					dynamicSharedSize = std::max( dynamicSharedSize, 
						(unsigned int) context.devices[ 
						context.getSelected() ].sharedMemPerBlock );
					report(" Setting shared memory size to " 
						<< dynamicSharedSize );
				}
				
				if( dynamicSharedSize > ( unsigned int ) context.devices[ 
					context.getSelected() ].sharedMemPerBlock )
				{
					#if CUDA_VERBOSE == 1
					std::cerr << "==Ocelot== Out of shared memory for kernel \""
						<< emulated->name 
						<< "\" : \n==Ocelot==\tpreallocated ";
					std::cerr << emulated->SharedMemorySize << " + requested " 
						<< thread->second.shared 
						<< " is greater than available " 
						<< context.devices[ 
						context.getSelected() ].sharedMemPerBlock 
						<< " for device " << context.devices[ 
						context.getSelected() ].name << "\n" << std::flush;
					#endif
					thread->second.lastError = cudaErrorLaunchFailure;
					break;
				}
				
				emulated->SharedMemorySize = dynamicSharedSize;
				
				ir::Kernel::ParameterVector::iterator 
					ki = emulated->parameters.begin();
				ThreadContext::ParameterMap::iterator 
					pi = thread->second.parameters.begin();
				
				for( ; ki != emulated->parameters.end() 
					&& pi != thread->second.parameters.end(); ++ki, ++pi )
				{
					if( ki->getSize() < pi->second.size() )
					{
						std::stringstream stream;
						stream << "For parameter " << ki->name << " PTX size " 
							<< ki->getSize() 
							<< " is less than specified size " 
							<< pi->second.size();
						throw hydrazine::Exception( formatError( 
							stream.str() ) );
					}
					
					if( ki->arrayValues.size() == 1 )
					{
						ir::Parameter::ValueVector::iterator 
						vi = ki->arrayValues.begin();
					
						unsigned int copySize = std::min( pi->second.size(), 
							ki->getElementSize() );
						unsigned int remainder = ki->getElementSize() 
							- copySize;
						memcpy( &vi->val_b8, &pi->second[0], copySize );
						memset( &vi->val_b8 + copySize, 0, remainder );
					}
					else
					{
						unsigned int size = 0;
					
						for( ir::Parameter::ValueVector::iterator 
							vi = ki->arrayValues.begin();
							vi != ki->arrayValues.end(); ++vi )
						{
							memcpy( &vi->val_b8, &pi->second[0] + size, 
								ki->getElementSize() );
							size += ki->getElementSize();
						}
					}
					
					report( " Set up parameter " << ki->name << " size " 
						<< ki->getSize() << " value " 
						<< ir::Parameter::value( *ki ) );				
				}
				
				if( ki != emulated->parameters.end() )
				{
					std::stringstream stream;
					stream << "Parameters : ";
					
					for( ; ki != emulated->parameters.end(); ++ki )
					{
						stream << ki->name << " ";
					}
					
					stream << "not set up for kernel " << emulated->name <<".";
					throw hydrazine::Exception( formatError( stream.str() ) );		
				}

				if( pi != thread->second.parameters.end() )
				{
					std::stringstream stream;
					stream << "Extra parameters added at offsets : ";
					
					for( ; pi != thread->second.parameters.end(); ++pi )
					{
						stream << pi->first << " ";
					}
					
					stream << "for kernel " << emulated->name <<".";
					throw hydrazine::Exception( formatError( stream.str() ) );		
				}

				#if CUDA_GENERATE_TRACE == 1
					CUDA_TRACE_GENERATOR generator;
					generator.database = _traceGeneratorDatabase;
					emulated->addTraceGenerator( &generator );
				#endif
				
				emulated->updateParameterMemory();
				emulated->updateGlobals();
				
				try
				{
					emulated->setKernelShape( thread->second.ctaDimensions.x, 
						thread->second.ctaDimensions.y, 
						thread->second.ctaDimensions.z );
					assert( thread->second.kernelDimensions.z == 1 );

					report( "Launching emulated kernel \"" 
						<< emulated->name << "\"." );

					emulated->launchGrid( thread->second.kernelDimensions.x, 
						thread->second.kernelDimensions.y );
					thread->second.lastError = cudaSuccess;
					
				}
				#if CATCH_RUNTIME_EXCEPTIONS == 1
				catch( const executive::RuntimeException& e )
				{
					#if CUDA_VERBOSE == 1
					std::cerr << "==Ocelot== Emulator failed to run kernel \"" 
						<< emulated->name 
						<< "\" with exception: \n";
					std::cerr << formatError( e.toString() ) 
						<< "\n" << std::flush;
					#endif
					thread->second.lastError = cudaErrorLaunchFailure;
					emulated->SharedMemorySize = staticSharedSize;
					thread->second.parameters.clear();
				}
				#else
				catch( int nothing )
				{
				
				}
				#endif
				
				emulated->SharedMemorySize = staticSharedSize;
				thread->second.parameters.clear();
				
				#if CUDA_GENERATE_TRACE == 1
					emulated->removeTraceGenerator( &generator );
				#endif
				
				break;
			
			}

			default:
			{
			
				std::stringstream stream;
				stream << "Kernel type " << context.getSelectedISA() 
					<< " not supported.";
				throw hydrazine::Exception( formatError( stream.str() ), 6 );
			
			}
		
		}
	
	}
	
	void* CudaRuntime::allocate( unsigned int size, bool portable, bool mapped )
	{
	
		Memory memory;
		
		if( mapped )
		{
			memory.base = ( char* ) context.malloc( size );
			report( " Allocating " << size 
				<< " bytes of device mapped host memory at " 
				<< (void*) memory.base );
		}
		else
		{
			memory.base = new char[ size ];
			report( " Allocating " << size 
				<< " bytes of host memory at " 
				<< (void*) memory.base );
		}
		
		memory.mapped = mapped;
		memory.portable = portable;
		memory.owner = pthread_self();
		memory.size = size;
	
		_memory.insert( std::make_pair( memory.base, memory ) );
		
		return memory.base;
	
	}
	
	void* CudaRuntime::lookupMappedMemory( void* pointer )
	{
		MemoryMap::iterator block = _memory.find( ( char* ) pointer );

		if( block == _memory.end() )
		{
			std::stringstream stream;
			stream << "Invalid lookup, address " << pointer 
				<< " not allocated in host pinned memory.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
	
		if( !block->second.mapped )
		{
			std::stringstream stream;
			stream << "Invalid lookup, address " << pointer 
				<< " is not mapped from host to device memory.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		return block->second.base;	
	}

	void CudaRuntime::free( void* pointer )
	{
	
		MemoryMap::iterator block = _memory.find( ( char* ) pointer );

		if( block == _memory.end() )
		{
			std::stringstream stream;
			stream << "Invalid free, address " << pointer 
				<< " not allocated in host pinned memory.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		if( block->second.owner != pthread_self() && !block->second.portable )
		{
			std::stringstream stream;
			stream << "Invalid free, address " << pointer 
				<< " allocated by another thread and not delcared portable.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		if( block->second.mapped )
		{
			context.free( pointer );
		}
		else
		{
			delete[] block->second.base;
		}
		
		_memory.erase( block );
	
	}
	
	cudaArray* CudaRuntime::allocateArray( const cudaChannelFormatDesc& desc,
		unsigned int width, unsigned int height, unsigned int length )
	{
	
		Array array = { (cudaArray*) context.malloc( length * width * height * 
			bytes( desc ) ), width, height, length, desc };
	
		_arrays.insert( std::make_pair( array.array, array ) );
	
		return array.array;
	
	}

	unsigned int CudaRuntime::offset( const cudaArray* pointer, 
		unsigned int width, unsigned int height, unsigned int length ) const
	{
	
		ArrayMap::const_iterator array = _arrays.find( 
			const_cast< cudaArray* >( pointer ) );

		if( array == _arrays.end() )
		{			
			std::stringstream stream;
			stream << "Invalid operation, " << pointer
				<< " is not a device array.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		if( height >= array->second.height )
		{		
			std::stringstream stream;
			stream << "For array " << pointer 
				<< " height index " << height 
				<< " is beyong limit " << array->second.height;
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		if( width >= array->second.width )
		{
			std::stringstream stream;
			stream << "For array " << pointer 
				<< " width index " << width 
				<< " is beyong limit " << array->second.width;
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		if( length >= array->second.length )
		{
			std::stringstream stream;
			stream << "For array " << pointer 
				<< " length index " << length 
				<< " is beyong limit " << array->second.length;
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		unsigned int wFactor = 1;
		unsigned int hFactor = array->second.width;
		unsigned int lFactor = array->second.height * hFactor;
		unsigned int index = wFactor * width + hFactor * height 
			+ lFactor * length;
		
		return bytes( array->second.channel ) * index;
		
	}

	const cudaChannelFormatDesc& CudaRuntime::getChannel( 
		const cudaArray* pointer ) const
	{
		
		ArrayMap::const_iterator array = _arrays.find( 
			const_cast< cudaArray* >( pointer ) );
		
		if( array == _arrays.end() )
		{			
			std::stringstream stream;
			stream << "Invalid operation, " << pointer
				<< " is not a device array.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
		}
		
		return array->second.channel;
	
	}
	
	const textureReference* CudaRuntime::getTexture( 
		const std::string& name ) const
	{
	
		for( FatBinaryMap::const_iterator binary = _binaries.begin();
			binary != _binaries.end(); ++binary )
		{
			GlobalMap::const_iterator texture = 
				binary->second.globals.find( name );
		
			if( texture != binary->second.globals.end() )
			{
				return (const textureReference*) texture->second;
			}
		}
		
		throw hydrazine::Exception( formatError( "Invalid texture " + name ), 
					cudaErrorInvalidTexture );
	}
	
	void CudaRuntime::rebind( const textureReference *texref, 
		const void *devPtr, const cudaChannelFormatDesc *desc, 
		size_t size )
	{
	
		TextureMap::iterator texture = _textures.find( texref );
		
		if( texture == _textures.end() )
		{
			std::stringstream stream;
			stream << "Invalid bind texture to array, " << texref 
				<< " is not a registered texture.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidTexture );
		}
	
		try
		{
			ir::Texture tex = convert(texref->channelDesc);
			tex.normalize = texref->normalized;
			tex.interpolation = convert(texref->filterMode);
			tex.addressMode[0] = convert(texref->addressMode[0]);
			tex.addressMode[1] = convert(texref->addressMode[1]);
			tex.addressMode[2] = convert(texref->addressMode[2]);
			context.rebind( texture->second.module, texture->second.name, 
				(void*)devPtr, size, 1, 1, tex );
			texture->second.bound = true;
		}
		catch( hydrazine::Exception& e )
		{
			if( e.code == 1 )
			{
				std::stringstream stream;
				stream << " " << texref;
				e.message += stream.str();
				e.code = cudaErrorInvalidTexture;
			}
			else if( e.code == 2 )
			{
				std::stringstream stream;
				stream << " " << devPtr;
				e.message += stream.str();
				e.code = cudaErrorInvalidDevicePointer;		
			}
		
			throw e;
		}
		
	}
	
	void CudaRuntime::rebind( const textureReference *texref, 
		const cudaArray* pointer, const cudaChannelFormatDesc *desc )
	{
	
		ArrayMap::iterator array = _arrays.find( 
			const_cast< cudaArray* >( pointer ) );

		if( array == _arrays.end() )
		{	
			std::stringstream stream;
			stream << "Invalid bind texture to array, " << pointer 
				<< " is not a device array.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidDevicePointer );
		}
		
		TextureMap::iterator texture = _textures.find( texref );
		
		if( texture == _textures.end() )
		{
			std::stringstream stream;
			stream << "Invalid bind texture to array, " << texref 
				<< " is not a registered texture.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidTexture );
		}
		
		try
		{
			ir::Texture tex = convert(texref->channelDesc);
			tex.normalize = texref->normalized;
			tex.interpolation = convert(texref->filterMode);
			tex.addressMode[0] = convert(texref->addressMode[0]);
			tex.addressMode[1] = convert(texref->addressMode[1]);
			tex.addressMode[2] = convert(texref->addressMode[2]);

			context.rebind( texture->second.module, texture->second.name, 
				(void*)pointer, array->second.width, array->second.height, 
				array->second.length, tex );
			texture->second.bound = true;
		}
		catch( hydrazine::Exception& e )
		{
			if( e.code == 1 )
			{
				std::stringstream stream;
				stream << " " << texref;
				e.message += formatError( stream.str() );
				e.code = cudaErrorInvalidTexture;
			}
			else if( e.code == 2 )
			{
				std::stringstream stream;
				stream << " " << pointer;
				e.message += formatError( stream.str() );
				e.code = cudaErrorInvalidDevicePointer;			
			}
		
			throw e;
		}
	
	}
	
	void CudaRuntime::unbind( const textureReference *texref )
	{
	
		TextureMap::iterator texture = _textures.find( texref );
		
		if( texture == _textures.end() )
		{
			std::stringstream stream;
			stream << "Invalid bind texture to array, " << texref 
				<< " is not a registered texture.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidTexture );
		}
		
		texture->second.bound = false;
				
	}
	
	void* CudaRuntime::getSymbol(const std::string& name)
	{

		for( FatBinaryMap::const_iterator binary = _binaries.begin();
			binary != _binaries.end(); ++binary )
		{
			GlobalMap::const_iterator global = 
				binary->second.globals.find( name );
		
			if( global != binary->second.globals.end() )
			{
				return global->second;
			}
		}
		
		throw hydrazine::Exception( formatError( "Invalid Symbol " + name ), 
			cudaErrorInvalidSymbol );			
	}

	void CudaRuntime::freeArray( cudaArray * pointer )
	{

		if(pointer == 0)
		{
			return;
		}

		ArrayMap::iterator array = _arrays.find( pointer );

		if( array == _arrays.end() )
		{
					
			std::stringstream stream;
			stream << "Invalid free, " << pointer 
				<< " is not a device array.";
			throw hydrazine::Exception( formatError( stream.str() ), 
				cudaErrorInvalidValue );
	
		}
		
		context.free( array->second.array );
		
		_arrays.erase( array );	
	
	}
	
	void CudaRuntime::registerGlobal( void* pointer, unsigned int size, 
		const std::string& name, ir::PTXInstruction::AddressSpace space, 
		unsigned int handle )
	{
	
		report( "Registering " << ir::PTXInstruction::toString(space) 
			<< " variable " << name << " to " << pointer << " with " << size 
			<< " bytes" );
	
		FatBinaryMap::iterator binary = _binaries.find( handle );
		assert( binary != _binaries.end() );
	
		GlobalMap::iterator global = binary->second.globals.find( name );
		if( global != binary->second.globals.end() )
		{
		
			if( global->second != pointer )
			{
			
				throw hydrazine::Exception( 
					formatError( "Two globals regstered with the same name " 
					+ name ) );
			
			}
		
		}
		else
		{
		
			assert( space != ir::PTXInstruction::Texture );

			binary->second.globals.insert( std::make_pair( name, 
				(char*)pointer ) );
			context.registerGlobal( pointer, size, name, space, 
				binary->second.binary.ident );
		
		}
		
	}

	void CudaRuntime::registerTexture( const textureReference* hostVar, 
		unsigned int size, const std::string& name, unsigned int handle, 
		bool normalize )
	{

		report( "Registering texture variable " << name << " to " 
			<< hostVar << " with " << size << " dimensions," 
			<< ((normalize) ? " normalized float" : " element") );

		FatBinaryMap::iterator binary = _binaries.find( handle );
		assert( binary != _binaries.end() );
	
		GlobalMap::iterator global = binary->second.globals.find( name );
		if( global != binary->second.globals.end() )
		{
			if( global->second != (void*) hostVar )
			{
				throw hydrazine::Exception( 
					formatError( "Two globals regstered with the same name " 
					+ name ) );
			}
		}
		else
		{
			assert( _textures.count( hostVar ) == 0 );
			Texture t;
			t.name = name;
			t.bound = false;
			t.module = binary->second.binary.ident;
			_textures.insert( std::make_pair( hostVar, t ) );	

			binary->second.globals.insert( std::make_pair( name, 
				(char*)hostVar ) );
				
			ir::Texture texture = convert(hostVar->channelDesc);
			texture.normalizedFloat = normalize;
			texture.interpolation = convert(hostVar->filterMode);
			texture.addressMode[0] = convert(hostVar->addressMode[0]);
			texture.addressMode[1] = convert(hostVar->addressMode[1]);
			texture.addressMode[2] = convert(hostVar->addressMode[2]);
				
			context.registerTexture( texture, name, 
				binary->second.binary.ident );
		}
	
	}
	
	bool CudaRuntime::isGlobal( const void* pointer ) const
	{
		for( FatBinaryMap::const_iterator binary = _binaries.begin();
			binary != _binaries.end(); ++binary )
		{			
			for( GlobalMap::const_iterator 
				global = binary->second.globals.begin(); 
				global != binary->second.globals.end(); ++global )
			{
				if( (char*)pointer == global->second )
				{
					return true;
				}						
			}			
		}		
		return false;			
	}
	
	cudaStream_t CudaRuntime::createStream()
	{
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		assert( thread->second.streams.count( 
			thread->second.nextStream ) == 0 );

		Stream stream;
		stream.handle = thread->second.nextStream;
		
		thread->second.streams.insert( 
			std::make_pair( thread->second.nextStream++, stream ) );
			
		return stream.handle;
	}

	void CudaRuntime::destroyStream( cudaStream_t handle )
	{
	
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		StreamMap::iterator stream = thread->second.streams.find( handle );
		
		if( stream == thread->second.streams.end() ) 
		{
			throw hydrazine::Exception( formatError( "Invalid stream handle." ), 
			handle );
		}
		
		thread->second.streams.erase( stream );
				
	}

	bool CudaRuntime::streamValid( cudaStream_t handle ) const
	{
		pthread_t id = pthread_self();

		if( handle == 0 )
		{
			return true;
		}
		
		ThreadMap::const_iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		return ( thread->second.streams.count( handle ) != 0 ); 
	}

	cudaEvent_t CudaRuntime::createEvent()
	{
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		assert( thread->second.events.count( 
			thread->second.nextEvent ) == 0 );

		Event event;
		event.handle = thread->second.nextEvent;
		
		thread->second.events.insert( 
			std::make_pair( thread->second.nextEvent++, event ) );
			
		return event.handle;
	}

	void CudaRuntime::destroyEvent( cudaEvent_t handle )
	{
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		assert( thread->second.events.count( 
			thread->second.nextEvent ) == 0 );

		EventMap::iterator event = thread->second.events.find( handle );
		
		if( event == thread->second.events.end() ) 
		{
			throw hydrazine::Exception( formatError( "Invalid event handle." ), 
				handle );
		}
		
		thread->second.events.erase( event );
	}

	bool CudaRuntime::eventValid( cudaEvent_t handle ) const
	{
		pthread_t id = pthread_self();
		
		ThreadMap::const_iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		return ( thread->second.events.count( handle ) != 0 ); 
	}

	void CudaRuntime::eventRecord( cudaEvent_t handle, cudaStream_t stream )
	{
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		EventMap::iterator event = thread->second.events.find( handle );
		
		if( event == thread->second.events.end() ) 
		{
			throw hydrazine::Exception( formatError( "Invalid event handle." ),
				handle );
		}
		
		event->second.timer.stop();
	}
	
	double CudaRuntime::eventTime( cudaEvent_t _start, cudaEvent_t _end )
	{
		pthread_t id = pthread_self();
		
		ThreadMap::iterator thread = _threads.find( id );
		assert( thread != _threads.end() );
		
		EventMap::iterator start = thread->second.events.find( _start );
		
		if( start == thread->second.events.end() ) 
		{
			throw hydrazine::Exception( formatError( "Invalid event handle."), 
				_start );
		}
		
		EventMap::iterator end = thread->second.events.find( _end );
		
		if( end == thread->second.events.end() ) 
		{
			throw hydrazine::Exception( formatError( "Invalid event handle."), 
				_end );
		}
		
		return ( end->second.timer.absolute() - 
			start->second.timer.absolute() ) * 1000;
	
	}
	
	void CudaRuntime::registerOpenGLBuffer( GLuint buffer )
	{
		OpenGLBufferMap::iterator mapping = _openGLBuffers.find( buffer );
		if( mapping == _openGLBuffers.end() )
		{
			_openGLBuffers.insert( std::make_pair( buffer, (void*)0 ) );
		}
	}

	void CudaRuntime::unregisterOpenGLBuffer( GLuint buffer )
	{
		OpenGLBufferMap::iterator mapping = _openGLBuffers.find( buffer );
		if( mapping != _openGLBuffers.end() )
		{
			_openGLBuffers.erase( mapping );
		}
	}

	CudaRuntime::OpenGLBuffer CudaRuntime::mapOpenGLBuffer( GLuint buffer )
	{
		OpenGLBufferMap::iterator mapping = _openGLBuffers.find( buffer );
		if( mapping == _openGLBuffers.end() )
		{
			throw hydrazine::Exception( 
				formatError( "Buffer is not registered." ), 
				cudaErrorMapBufferObjectFailed );		
		}
	
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		mapping->second = glMapBuffer( GL_ARRAY_BUFFER, GL_READ_WRITE );
		int bytes = 0;
		glGetBufferParameteriv( GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bytes );
		context.registerExternal(mapping->second, bytes);
		
		GLenum error = glGetError();
		if( error != GL_NO_ERROR )
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			throw hydrazine::Exception(formatError( "Opengl call failed." ), 
				cudaErrorMapBufferObjectFailed );
		}
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		report("Buffer " << buffer << ", size " << bytes 
			<< ", mapped to address " << mapping->second);
		return mapping->second;
	}

	void CudaRuntime::unmapOpenGLBuffer( GLuint buffer )
	{
		OpenGLBufferMap::iterator mapping = _openGLBuffers.find( buffer );
		if( mapping == _openGLBuffers.end() )
		{
			throw hydrazine::Exception( 
				formatError( "Buffer is not registered." ), 
				cudaErrorInvalidDevicePointer );		
		}

		context.free(mapping->second);
		
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		if( !glUnmapBuffer( GL_ARRAY_BUFFER ) )
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			throw hydrazine::Exception( formatError( "Opengl call failed." ), 
				cudaErrorMapBufferObjectFailed );
		}
		
		mapping->second = (void*)0;
	}
	
	void CudaRuntime::configure( const Configuration& c )
	{
		parse("PreallocateAllSharedMemory", 
			_preallocateAllSharedMemory, false, c);
		parse("TraceGeneratorDatabase", _traceGeneratorDatabase, 
			"traces/database.db", c);
	}

}

#endif

