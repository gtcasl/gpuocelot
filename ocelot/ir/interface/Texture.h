/*!
	\file Texture.h 
	
	\author Gregory DIamos <gregory.diamos@gatech.edu>
	\date Sunday April 5, 2009
	
	\brief The header file for the Texture class
*/

#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/Dim3.h>

namespace ir
{
	/*!
		\brief A class to represent the access format of a texture
	*/
	class Texture
	{		

		public:
			enum Type
			{
				Unsigned,
				Signed,
				Float,
				Invalid
			};
			
			enum Interpolation
			{
				Nearest,
				Linear
			};
			
			enum AddressMode
			{
				Wrap,
				Clamp
			};

		public:
			unsigned int x; //! Bits in x dim
			unsigned int y; //! Bits in y dim
			unsigned int z; //! Bits in z dim
			unsigned int w; //! Bits in w dim
			bool normalize; //! Normalize accesses
			bool normalizedFloat; //! Return a normalized float
			Type type; //! Data type
			Dim3 size; //! Texture dimensions
			void* data; //! Pointer to mapped variable
			
			Interpolation interpolation; //! Interpolation mode
			AddressMode addressMode[3]; //! Wrap around or clamp to boundary
			
		public:
			Texture();

		public:
		
			static std::string toString(Type type);			
	};
}

#endif

