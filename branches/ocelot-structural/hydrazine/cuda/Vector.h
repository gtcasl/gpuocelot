/*!
	\file Vector.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Thursday May 7, 2009
	\brief The header file for the Vector class
*/

#ifndef CUDA_VECTOR_H_INCLUDED
#define CUDA_VECTOR_H_INCLUDED

#include <hydrazine/implementation/macros.h>
#include <hydrazine/cuda/DevicePointerIterator.h>
#include <cassert>
#include <algorithm>

#define PAGE_SIZE 32768
#define PAGE_ALIGN(x) ( (x) + ( (x) % PageSize ) )
#define MEM_RATIO .2

namespace hydrazine
{

namespace cuda
{

	/*!
		\brief An STL-like vector stored in GPU memory
	*/
	template< typename T, unsigned int PageSize = PAGE_SIZE >
	class Vector
	{
	
		private:
	
			T* _begin;
			T* _end;
			T* _storage;
		
		public:
	
			typedef size_t size_type;
			typedef T value_type;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef ptrdiff_t difference_type;
			typedef Vector< T > vector_type;
			typedef vector_type type;
			
			typedef hydrazine::cuda::DevicePointerIterator< pointer, 
				vector_type > iterator;
			typedef hydrazine::cuda::DevicePointerIterator< const_pointer, 
				vector_type > const_iterator;
			typedef typename hydrazine::cuda::DevicePointerIterator< pointer, 
				vector_type >::reference reference;
				
		private:
		
			static size_type _pageAlign( size_type size )
			{
				return CEIL_DIV( PAGE_ALIGN( size * sizeof( T ) ), 
					sizeof( T ) );
			}
			
		public:
	
			Vector()
			{
				_begin = 0;
				_end = 0;
				_storage = 0;
			}
		
			Vector( const Vector& c )
			{
		
				size_type size = c.size();
				size_type storage = _pageAlign( size );
			
				cuda::check( cudaMalloc( (void**) &_begin, 
					sizeof(T) * storage ) );
				cuda::check( cudaMemcpy( _begin, c._begin, sizeof(T) * size, 
					cudaMemcpyDeviceToDevice ) );
				
				_end = _begin + size;
				_storage = _begin + storage;
		
			}
		
			Vector( size_type size )
			{
				size_type storage = _pageAlign( size );
			
				cuda::check( cudaMalloc( (void**) &_begin, 
					sizeof(T) * storage ) );
				
				_end = _begin + size;
				_storage = _begin + storage;
			}
		
			template< typename input_iterator >
			Vector( input_iterator start, input_iterator end )
			{
				size_type size = end - start;
				size_type storage = _pageAlign( size );
			
				cuda::check( cudaMalloc( (void**) &_begin, 
					sizeof(T) * storage ) );
				
				_end = _begin + size;
				_storage = _begin + storage;
			
				T* temp;
			
				cuda::check( cudaMallocHost( (void**) &temp, 
					sizeof(T) * size ) );
		
				T* temp_it = temp;
		
				for( input_iterator it = start; it != end; ++it, ++temp_it )
				{
					*temp_it = *it;
				}
			
				cuda::check( cudaMemcpy( _begin, temp, sizeof(T) * size, 
					cudaMemcpyHostToDevice ) );
		
				cuda::check( cudaFreeHost( temp ) );
			}

			~Vector()
			{
				if( _begin != 0 )
				{
					cuda::check( cudaFree( _begin ) );
				}
			}
		
		public:
	
			reference operator[]( size_type index ) const
			{
				assert( index < size() );
				return reference( _begin + index );
			}
		
			Vector& operator=(const Vector& c)
			{
				assert( &c != this );
			
				resize( c.size() );

				T* pointer;

				cuda::check( cudaMalloc( (void**) &pointer, 
					sizeof(T) * size() ) );
				cuda::check( cudaMemcpy( _begin, c._begin, sizeof(T) * size(), 
					cudaMemcpyDeviceToDevice ) );
				
				return *this;
			}
	
			bool operator==( const Vector& c2 )
			{
				return size() == c2.size();
			}

			bool operator!=( const Vector& c2 )
			{
				return size() != c2.size();
			}

			bool operator<( const Vector& c2 )
			{
				return size() < c2.size();
			}

			bool operator>( const Vector& c2 )
			{
				return size() > c2.size();
			}

			bool operator<=( const Vector& c2 )
			{
				return size() <= c2.size();
			}

			bool operator>=( const Vector& c2 )
			{
				return size() >= c2.size();
			}

		public:
	
			void assign( size_type size, const T& val )
			{
			
				resize( size );
			
				T* temp;
			
				cuda::check( cudaMallocHost( (void**) &temp, 
					sizeof(T) * size ) );
		
				T* temp_it = temp;
		
				for( unsigned int i = 0; i < size; ++i )
				{
					*temp_it = val;
				}
			
				cuda::check( cudaMemcpy( _begin, temp, sizeof(T) * size, 
					cudaMemcpyHostToDevice ) );
		
				cuda::check( cudaFreeHost( temp ) );
		
			}
		
			template< typename input_iterator >
			void assign( input_iterator start, input_iterator end )
			{
				size_type size = end - start;
			
				resize( size );

				T* temp;
			
				cuda::check( cudaMallocHost( (void**) &temp, sizeof(T) * size ) );
		
				T* temp_it = temp;
		
				for( input_iterator it = start; it != end; ++it, ++temp_it )
				{
					*temp_it = *it;
				}
			
				cuda::check( cudaMemcpy( _begin, temp, sizeof(T) * size, 
					cudaMemcpyHostToDevice ) );
		
				cuda::check( cudaFreeHost( temp ) );		
			}
		
			const T& at( size_type index ) const
			{
				return (*this)[index];		
			}
		
			const T& back() const
			{
				return at( size() - 1 );
			}
		
			size_type capacity() const
			{
				return _storage - _begin;
			}
		
			void clear()
			{
				if( _storage != _begin )
				{
					cuda::check( cudaFree( _begin ) );
					_storage = 0;
					_begin = 0;
					_end = 0;
				}
			}
		
			bool empty() const
			{
				return _begin == _end;
			}
		
			const T& front() const
			{
				return at(0);
			}
		
			size_type max_size() const
			{
				cudaDeviceProp properties;
				int device;
				cuda::check( cudaGetDevice( &device ) );
				cuda::check( cudaGetDeviceProperties( &properties, device ) );
				return ( properties.totalGlobalMem * MEM_RATIO ) / sizeof(T);
			}
		
			void pop_back()
			{
				assert(!empty());
				--_end;
			}
		
			void push_back( const T& val )
			{
				if( size() < capacity() )
				{
					resize( size() + 1 );
				}

				cuda::check( cudaMemcpy( _end - 1, &val, sizeof(T), 
					cudaMemcpyHostToDevice ) );
			}

			void reserve( size_type storage )
			{
				if( capacity() < storage )
				{
					storage = _pageAlign( storage );
					T* _new;
					cuda::check( cudaMalloc( (void**) &_new, 
						sizeof( T ) * storage ) );
					size_type old = size();
					cuda::check( cudaMemcpy( _new, _begin, 
						old * sizeof( T ), cudaMemcpyDeviceToDevice ) );
					clear();
					_begin = _new;
					_end = _begin + old;
					_storage = _begin + storage;
				}
			}
			
			void resize( size_type newSize )
			{
				size_type storage = _pageAlign( newSize );
				if( storage != capacity() )
				{
					T* _new;
					cuda::check( cudaMalloc( (void**) &_new, 
						sizeof( T ) * storage ) );
					size_type old = MIN( size(), newSize );
					cuda::check( cudaMemcpy( _new, _begin, 
						old * sizeof( T ), cudaMemcpyDeviceToDevice ) );
					clear();
					_begin = _new;
					_end = _begin + newSize;
					_storage = _begin + storage;					
				}
			}
			
			size_type size() const
			{
				return _end - _begin;
			}
			
			void swap( Vector& vec )
			{
				std::swap( _begin, vec._begin );
				std::swap( _end, vec._end );
				std::swap( _storage, vec._storage );
			}
			
		public:
		
			void read( void* dest, size_type bytes )
			{
				assert( bytes <= sizeof( T ) * size() );
				cuda::check( cudaMemcpy( dest, _begin, bytes, 
					cudaMemcpyDeviceToHost ) );
			}
			
			void write( const void* src, size_type bytes )
			{
				if( bytes > sizeof( T ) * size() )
				{
					resize( CEIL_DIV( bytes, sizeof( T ) ) );
				}
				cuda::check( cudaMemcpy( _begin, src, bytes, 
					cudaMemcpyHostToDevice ) );
			}
	
		public:
		
			iterator begin()
			{
				return iterator( _begin );
			}
			
			iterator end()
			{
				return iterator( _end );
			}
			
			const_iterator begin() const
			{
				return const_iterator( _begin );
			}
			
			const_iterator end() const
			{
				return const_iterator( _end );
			}
		
	};

}

}

#undef PAGE_SIZE
#undef PAGE_ALIGN
#undef MEM_RATIO

#endif

