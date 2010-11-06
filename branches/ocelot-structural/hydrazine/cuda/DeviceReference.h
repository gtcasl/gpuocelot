/*!
	\file DeviceReference.h
	\date Thursday June 4, 2009
	\author Gregory Diamos
	\brief Header file for the DeviceReference classe
*/

#ifndef DEVICE_REFERENCE_H_INCLUDED
#define DEVICE_REFERENCE_H_INCLUDED

#include <hydrazine/interface/Iterator.h>

namespace hydrazine
{

namespace cuda
{
	
	/*!
		\brief A wrapper for a reference to an object stored in device memory.
	*/
	template< typename Type >
	class DeviceReference
	{
		public:
			typedef typename hydrazine::IteratorTraits< Type >::value_type 
				value_type;
			typedef typename hydrazine::IteratorTraits< Type >::difference_type 
				difference_type;
			typedef typename hydrazine::IteratorTraits< Type >::pointer pointer;
			typedef typename hydrazine::IteratorTraits< Type >::reference 
				base_reference;
		
		private:
			pointer _pointer;
			
		public:
			DeviceReference( const DeviceReference& r ) : 
				_pointer( r._pointer ) {}
			DeviceReference( pointer p ) : _pointer( p ) {}
			DeviceReference( ) : _pointer( 0 ) {}
			
			DeviceReference& operator=( const value_type& value )
			{
				cuda::check( cudaMemcpy( _pointer, &value, 
					sizeof( value_type ), cudaMemcpyHostToDevice ) );
				return *this;
			}
			
			DeviceReference& operator=( const DeviceReference& value )
			{
				cuda::check( cudaMemcpy( _pointer, value._pointer, 
					sizeof( value_type ), cudaMemcpyDeviceToDevice ) );
				return *this;
			}
			
			operator value_type() const
			{
				value_type temp;
				cuda::check( cudaMemcpy( &temp, _pointer, 
					sizeof( value_type ), cudaMemcpyDeviceToHost ) );
				return temp;
			}
			
			pointer base()
			{
				return _pointer;
			}
	};
	
	template< typename Left, typename Right >
	bool operator==( const DeviceReference<Left>& l, 
		const DeviceReference<Right>& r )
	{
		return typename DeviceReference<Left>::value_type(l) 
			== typename DeviceReference<Right>::value_type(r);
	}
	
	template< typename Left, typename Right >
	bool operator!=( const DeviceReference<Left>& l, 
		const DeviceReference<Right>& r )
	{
		return typename DeviceReference<Left>::value_type(l) 
			!= typename DeviceReference<Right>::value_type(r);
	}
	
	template< typename Left, typename Right >
	bool operator<( const DeviceReference<Left>& l, 
		const DeviceReference<Right>& r )
	{
		return typename DeviceReference<Left>::value_type(l) 
			< typename DeviceReference<Right>::value_type(r);
	}
	
	template< typename Left, typename Right >
	bool operator<=( const DeviceReference<Left>& l, 
		const DeviceReference<Right>& r )
	{
		return typename DeviceReference<Left>::value_type(l) 
			<= typename DeviceReference<Right>::value_type(r);
	}
	
	template< typename Left, typename Right >
	bool operator>( const DeviceReference<Left>& l, 
		const DeviceReference<Right>& r )
	{
		return typename DeviceReference<Left>::value_type(l) 
			> typename DeviceReference<Right>::value_type(r);
	}
	
	template< typename Left, typename Right >
	bool operator>=( const DeviceReference<Left>& l, 
		const DeviceReference<Right>& r )
	{
		return typename DeviceReference<Left>::value_type(l) 
			>= typename DeviceReference<Right>::value_type(r);
	}
	
	template< typename First, typename Second >
	struct UglyHack
	{
		typedef DeviceReference< std::pair< First, Second >* > type;
	};
	
	template< typename First, typename Second >
	class DeviceReference< std::pair< First, Second >* >
	{
		public:
			typedef std::pair< First, Second >* Type;
			typedef typename hydrazine::IteratorTraits< Type >::value_type 
				value_type;
			typedef typename hydrazine::IteratorTraits< Type >::difference_type 
				difference_type;
			typedef typename hydrazine::IteratorTraits< Type >::pointer pointer;
			typedef typename hydrazine::IteratorTraits< Type >::reference 
				base_reference;
			typedef DeviceReference< First* > FirstReference;
			typedef DeviceReference< Second* > SecondReference;
			
		private:
			pointer _pointer;
		
		public:
			FirstReference first;
			SecondReference second;
		
		public:
			DeviceReference( const typename UglyHack< First, 
				Second >::type& r ) : 
				_pointer( r._pointer ), first( r.first ), second( r.second ) {}
			DeviceReference( pointer p ) : _pointer( p ), first( &p->first ), 
				second( &p->second ) {}
			
			DeviceReference& operator=( const value_type& value )
			{
				cuda::check( cudaMemcpy( _pointer, &value, 
					sizeof( value_type ), cudaMemcpyHostToDevice ) );
				return *this;
			}
			
			DeviceReference& operator=( const typename UglyHack< First, 
				Second >::type& value )
			{
				cuda::check( cudaMemcpy( _pointer, value._pointer, 
					sizeof( value_type ), cudaMemcpyDeviceToDevice ) );
				return *this;
			}
			
			operator value_type() const
			{
				value_type temp;
				cuda::check( cudaMemcpy( &temp, _pointer, 
					sizeof( value_type ), cudaMemcpyDeviceToHost ) );
				return temp;
			}
			
			pointer base()
			{
				return _pointer;
			}			
			
	};
	
	template< typename First, typename Second >
	struct ConstUglyHack
	{
		typedef DeviceReference< const std::pair< First, Second >* > type;
	};	
	
	template< typename First, typename Second >
	class DeviceReference< const std::pair< First, Second >* >
	{
		public:
			typedef const std::pair< First, Second >* Type;
			typedef typename hydrazine::IteratorTraits< Type >::value_type 
				value_type;
			typedef typename hydrazine::IteratorTraits< Type >::difference_type 
				difference_type;
			typedef typename hydrazine::IteratorTraits< Type >::pointer pointer;
			typedef typename hydrazine::IteratorTraits< Type >::reference 
				base_reference;
			typedef DeviceReference< const First* > FirstReference;
			typedef DeviceReference< const Second* > SecondReference;
		
		private:
			pointer _pointer;
		
		public:
			FirstReference first;
			SecondReference second;
		
		public:
			DeviceReference( const typename ConstUglyHack< First, 
				Second >::type& r ) : _pointer( r._pointer ), first( r.first ),
				second( r.second ) {}
			DeviceReference( pointer p ) : _pointer( p ), first( &p->first ), 
				second( &p->second ) {}
			
			DeviceReference& operator=( const value_type& value )
			{
				cuda::check( cudaMemcpy( _pointer, &value, 
					sizeof( value_type ), cudaMemcpyHostToDevice ) );
				return *this;
			}
			
			DeviceReference& operator=( const typename ConstUglyHack< First, 
				Second >::type& value )
			{
				cuda::check( cudaMemcpy( _pointer, value._pointer, 
					sizeof( value_type ), cudaMemcpyDeviceToDevice ) );
				return *this;
			}
			
			operator value_type() const
			{
				value_type temp;
				cuda::check( cudaMemcpy( &temp, _pointer, 
					sizeof( value_type ), cudaMemcpyDeviceToHost ) );
				return temp;
			}
			
			pointer base()
			{
				return _pointer;
			}
						
	};
	
}

}

#endif

