/*! \file Texture.h 
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Sunday April 5, 2009
	
	\brief The header file for the Texture class
*/

#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/Dim3.h>

namespace ir
{
	/*! \brief A class to represent the access format of a texture */
	class Texture {		
		public:
			enum Type {
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
			unsigned int pitch() {
				return ((x + y + z + w) / 8) * size.x;
			}

			unsigned int bytes() {
				return pitch() * size.y * size.z;
			}

			unsigned int components() {
				return (x ? 1 : 0) + (y ? 1 : 0) + (z ? 1 : 0) 
					+ (w ? 1 : 0);
			}
			unsigned int dimensions() {
				return (size.x - 1 ? 1 : 0) + (size.y - 1 ? 1 : 0) 
					+ (size.z - 1 ? 1 : 0);
			}

		public:
			std::string name; //! texture name
		
			unsigned int x; //! Bits in x dim
			unsigned int y; //! Bits in y dim
			unsigned int z; //! Bits in z dim
			unsigned int w; //! Bits in w dim

			bool normalize; //! Normalize accesses
			bool normalizedFloat; //! Return a normalized float

			Type type; //! Data type
			Dim3 size; //! Texture dimensions
			
			Interpolation interpolation; //! Interpolation mode
			AddressMode addressMode[3]; //! Wrap around or clamp to bound

			void* data; //! Pointer to mapped variable
			
		public:
			Texture(const std::string& n = "", Type t = Invalid);

		public:
			std::string toString() const;

		public:
			static std::string toString(Type type);			
	};

}

#endif

