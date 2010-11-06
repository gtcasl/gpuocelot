/*!
	\file CachedVector.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Thursday May 28, 2009
	\brief The header file for the CachedVector class.
*/

#ifndef CACHED_VECTOR_H_INCLUDED
#define CACHED_VECTOR_H_INCLUDED

namespace hydrazine
{

namespace cuda
{

	/*!
		\brief A vector that maintains a cache on the host as well as a CUDA
			device.  
			
		The idea is to lazily copy pages from the device depending on how the
		host accesses the vector.  This data structure should try to predict
		which pages the host will access and prefetch them.  
		
		It should also be convertable into a device handle.  This conversion
		process should flush the host cache.
		
		All other GPU data structures should be built using this for memory
		allocation.
	*/
	template< typename T, size_t LineSize = 2097152 >
	class CachedVector
	{
		public:
			class iterator;
			class const_iterator;
			
		public:
			typedef CachedVector type;
			typedef size_t size_type;
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef value_type* pointer;
			typedef value_type& reference;
			typedef const value_type* const_pointer;
			typedef const value_type& const_reference;
			typedef std::reverse_iterator< iterator > reverse_iterator;
			typedef std::reverse_iterator< const_iterator > 
				const_reverse_iterator;
		
		private:
			class CacheLine
			{
				public:
					enum State
					{
						NotAllocated,
						OnHostClean,
						OnHostDirty,
						OnDeviceClean,
						OnDeviceDirty,
						SharedClean
					};
					
				public:
					State state;
					pointer device;
					pointer host;
					
				public:
					CacheLine() : state( NotAllocated )
					{
						
					}
					
					void hostReadStart();
					void hostWriteStart();
					void hostReadDone();
					void hostWriteDone();
					
					void gpuReadStart();
					void gpuWriteStart();
					void gpuReadDone();
					void gpuWriteDone();
			};
			
			class GpuMemoryPool
			{};
			
			class HostMemoryPool
			{};
			
		private:
			
			
		public:
			CachedVector();
			CachedVector( const CachedVector& c );
			CachedVector( size_type size );
			template< typename input_iterator >
			CachedVector( input_iterator start, input_iterator end );
			~CachedVector();
		
		public:
			CachedVector& operator=(const Vector& c);

		public:
			void assign( size_type size, const T& val );
			template< typename input_iterator >
			void assign( input_iterator start, input_iterator end );
			
			reference operator[]( size_type index );
			reference at( size_type index );
			reference back();
			reference front();
			
			const_reference operator[]( size_type index ) const;
			const_reference at( size_type index ) const;
			const_reference back() const;
			const_reference front() const;
			
			void clear();
			void reserve( size_type storage );
			void resize( size_type newSize );
			
			
			void pop_back();
			void push_back( const T& val );
			
			size_type size() const;
			size_type max_size() const;
			size_type capacity() const;
			bool empty() const;
			
			void swap( CachedVector& vec );
	
		public:
			iterator begin();
			iterator end();
			const_iterator begin() const;
			const_iterator end() const;
			
			reverse_iterator rbegin();
			reverse_iterator rend();
			const_reverse_iterator rbegin() const;
			const_reverse_iterator rend() CacheLineconst;
				
	};

}

}

#endif

