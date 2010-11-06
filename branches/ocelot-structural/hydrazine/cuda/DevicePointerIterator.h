/*!
	\file DevicePointerIterator.h
	\date Tuesday March 12, 2009
	\author Gregory Diamos
	\brief Header file for the DevicePointerIterator classe
*/

#ifndef DEVICE_POINTER_ITERATOR_H_INCLUDED
#define DEVICE_POINTER_ITERATOR_H_INCLUDED

#include <hydrazine/interface/Iterator.h>
#include <hydrazine/cuda/include/cuda.h>
#include <hydrazine/cuda/CudaException.h>
#include <hydrazine/cuda/DeviceReference.h>

namespace hydrazine
{

namespace cuda
{
	
	/*!
		\brief A generic iterator class wrapper for iterators derived from
			pointers to objects in GPU memory.
			
		Container is here so that different iterator types get instantiated
		for containers using the same underlying pointer as in GCC-4.3.3

		This class presents a reference derived class that allows assignment
		to a GPU element.
	*/
	template< typename Type, typename Container >
	class DevicePointerIterator
	{
		public:
			typedef Type iterator_type;
			typedef typename hydrazine::IteratorTraits< 
				Type >::iterator_category iterator_category;
			typedef typename hydrazine::IteratorTraits< Type >::value_type 
				value_type;
			typedef typename hydrazine::IteratorTraits< Type >::difference_type 
				difference_type;
			typedef typename hydrazine::IteratorTraits< Type >::pointer pointer;

			typedef typename hydrazine::IteratorTraits< Type >::reference 
				base_reference;
			typedef DeviceReference<pointer> reference;
		
		protected:
			pointer _current;
			
		public:
			DevicePointerIterator() : _current( Type() ) 
			{
			}
			
			explicit DevicePointerIterator( const Type& it ) : _current( it ) 
			{
			}
			
			template< typename _Assignee >
			DevicePointerIterator( const DevicePointerIterator< _Assignee, 
				typename Container::type >& it ) : _current( it.base() )
			{
			}
			
			reference operator*() const
			{
				return _current;
			}
			
			DevicePointerIterator& operator++()
			{
				++_current;
				return *this;
			}
			
			DevicePointerIterator operator++( int )
			{
				return DevicePointerIterator( _current++ );
			}
			
			DevicePointerIterator& operator--()
			{
				--_current;
				return *this;
			}
			
			DevicePointerIterator operator--( int )
			{
				return DevicePointerIterator( _current-- );
			}
			
			reference operator[]( const difference_type& n ) const
			{
				return reference( _current + n );
			}
			
			DevicePointerIterator& operator+=( const difference_type& n )
			{
				_current += n;
				return *this;
			}
			
			DevicePointerIterator operator+( const difference_type& n ) const
			{
				return DevicePointerIterator( _current + n );
			}
			
			DevicePointerIterator& operator-=( const difference_type& n )
			{
				_current -= n;
				return *this;
			}
			
			DevicePointerIterator operator-( const difference_type& n ) const
			{
				return DevicePointerIterator( _current - n );
			}
			
			pointer base() const
			{
				return _current;
			}
			
	};
	
	template<typename TypeL, typename TypeR, typename Container>
	inline bool operator==(
		const DevicePointerIterator<TypeL, Container>& left,
		const DevicePointerIterator<TypeR, Container>& right)
	{ 
		return left.base() == right.base();
	}

	template<typename Pointer, typename Container>
	inline bool operator==(
		const DevicePointerIterator<Pointer, Container>& left,
		const DevicePointerIterator<Pointer, Container>& right)
	{
		return left.base() == right.base(); 
	}

	template<typename TypeL, typename TypeR, typename Container>
	inline bool operator!=(
		const DevicePointerIterator<TypeL, Container>& left,
		const DevicePointerIterator<TypeR, Container>& right)
	{
		return left.base() != right.base(); 
	}

	template<typename Pointer, typename Container>
	inline bool operator!=(
		const DevicePointerIterator<Pointer, Container>& left,
		const DevicePointerIterator<Pointer, Container>& right)
	{
		return left.base() != right.base(); 
	}

	template<typename TypeL, typename TypeR, typename Container>
	inline bool operator<(
		const DevicePointerIterator<TypeL, Container>& left,
		const DevicePointerIterator<TypeR, Container>& right)
	{
		return left.base() < right.base(); 
	}

	template<typename Pointer, typename Container>
	inline bool operator<(
		const DevicePointerIterator<Pointer, Container>& left,
		const DevicePointerIterator<Pointer, Container>& right)
	{
		return left.base() < right.base(); 
	}

	template<typename TypeL, typename TypeR, typename Container>
	inline bool operator>(
		const DevicePointerIterator<TypeL, Container>& left,
		const DevicePointerIterator<TypeR, Container>& right)
	{
		return left.base() > right.base(); 
	}

	template<typename Pointer, typename Container>
	inline bool operator>(
		const DevicePointerIterator<Pointer, Container>& left,
		const DevicePointerIterator<Pointer, Container>& right)
	{
		return left.base() > right.base(); 
	}

	template<typename TypeL, typename TypeR, typename Container>
	inline bool operator<=(
		const DevicePointerIterator<TypeL, Container>& left,
		const DevicePointerIterator<TypeR, Container>& right)
	{
		return left.base() <= right.base(); 
	}

	template<typename Pointer, typename Container>
	inline bool operator<=(
		const DevicePointerIterator<Pointer, Container>& left,
		const DevicePointerIterator<Pointer, Container>& right)
	{
		return left.base() <= right.base(); 
	}

	template<typename TypeL, typename TypeR, typename Container>
	inline bool operator>=(
		const DevicePointerIterator<TypeL, Container>& left,
		const DevicePointerIterator<TypeR, Container>& right)
	{
		return left.base() >= right.base(); 
	}

	template<typename Pointer, typename Container>
	inline bool operator>=(
		const DevicePointerIterator<Pointer, Container>& left,
		const DevicePointerIterator<Pointer, Container>& right)
	{
		return left.base() >= right.base(); 
	}

	template<typename TypeL, typename TypeR, typename Container>
	inline typename DevicePointerIterator<TypeL, Container>::difference_type
		operator-(const DevicePointerIterator<TypeL, Container>& left,
		const DevicePointerIterator<TypeR, Container>& right)
	{
		return left.base() - right.base(); 
	}

	template<typename Pointer, typename Container>
	inline typename DevicePointerIterator<Pointer, Container>::difference_type
		operator-(const DevicePointerIterator<Pointer, Container>& left,
		const DevicePointerIterator<Pointer, Container>& right)
	{
		return left.base() - right.base(); 
	}

	template<typename Pointer, typename Container>
	inline DevicePointerIterator<Pointer, Container> operator+(
		typename DevicePointerIterator<Pointer, Container>::difference_type
		n, const DevicePointerIterator<Pointer, Container>& it )
	{
		return DevicePointerIterator<Pointer, Container>( it.base() + n ); 
	}

}

}

#endif

