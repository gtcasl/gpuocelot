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
			enum SurfaceType {
				Texref,
				Surfref,
				Samplerref,
				SurfaceType_Invalid
			};
		
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
				Clamp,
				Mirror,
				Clamp_ogl,
				Clamp_edge,
				Clamp_border,
				AddressMode_Invalid
			};
			
			enum ChannelDataType {
				SNORM_INT8 = 0x10D0,
				SNORM_INT16 = 0x10D1,
				UNORM_INT8 = 0x10D2,
				UNORM_INT16 = 0x10D3,
				UNORM_SHORT_565 = 0x10D4,
				UNORM_SHORT_555 = 0x105,
				UNORM_INT_101010 = 0x10D6,
				SIGNED_INT8 = 0x10D7,
				SIGNED_INT16 = 0x10D8,
				SIGNED_INT32 = 0x10D9,
				UNSIGNED_INT8 = 0x10DA,
				UNSIGNED_INT16 = 0x10DB,
				UNSIGNED_INT32 = 0x10DC,
				HALF_FLOAT = 0x10DD,
				FLOAT = 0x10DE,
				ChannelDataType_Invalid
			};
			
			enum ChannelOrder {
				R = 0x10B0,
				A = 0x10B1,
				RG = 0x10B2,
				RA = 0x10B3,
				RGB = 0x10B4,
				RGBA = 0x10B5,
				BGRA = 0x10B6,
				ARGB = 0x10B7,
				ITENSITY = 0x10B8,
				LUMINANCE = 0x10B9,
				ChannelOrder_Invalid
			};
			
		public:
		
			static std::string toString(SurfaceType type);
			static std::string toString(Interpolation type);
			static std::string toString(AddressMode type);
			static std::string toString(Type type);
			
			static Type typeFromString(const std::string&);
			static AddressMode modeFromString(const std::string&);
			static Interpolation interpolationFromString(const std::string&);
			
			static ir::PTXOperand::DataType
				convertFromChannelDataType(ChannelDataType);
			static ChannelDataType
				convertFromPTXDataType(ir::PTXOperand::DataType);

		public:
			unsigned int pitch() const {
				return ((x + y + z + w) / 8) * size.x;
			}

			unsigned int bytes() const {
				return pitch() * size.y * size.z;
			}

			unsigned int components() const {
				return (x ? 1 : 0) + (y ? 1 : 0) + (z ? 1 : 0) 
					+ (w ? 1 : 0);
			}
			unsigned int dimensions() const {
				return (size.x - 1 ? 1 : 0) + (size.y - 1 ? 1 : 0) 
					+ (size.z - 1 ? 1 : 0);
			}

		public:
			std::string name; //! texture name
			
			SurfaceType surfaceType;	//! indicates type of surface this is
		
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
			Texture(const std::string& n = "", SurfaceType surfType = Texref,
				Type type = Float);

		public:
			std::string toString() const;
	};

}

#endif

