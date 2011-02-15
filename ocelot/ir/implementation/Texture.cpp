/*!
	\file Texture.cpp
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Sunday April 5, 2009
	
	\brief The source file for the Texture class
*/

#ifndef TEXTURE_CPP_INCLUDED
#define TEXTURE_CPP_INCLUDED

#include <ocelot/ir/interface/Texture.h>

namespace ir
{
	Texture::Texture(const std::string& n, SurfaceType _surfType) : name(n), surfaceType(_surfType),
		normalize(false),  type(Invalid), size( Dim3(0, 0, 0) ), data( 0 ) {
		
	}
	
	std::string Texture::toString(SurfaceType type) {
		switch (type) {
		case Texref: return ".texref";
		case Surfref: return ".surfref";
		case Samplerref: return ".samplerref";
		default: break;
		}
		return ".texref";
	}
	
	
	std::string Texture::toString(Interpolation type) {
		switch (type) {
		case Nearest: return "Nearest";
		case Linear: return "Linear";
		default: break;
		}
		return "Interpolation_unknown";
	}
	
	std::string Texture::toString(AddressMode type) {
		switch (type) {
		case Wrap: return "Wrap";
		case Clamp: return "Clamp";
		case Mirror: return "Mirror";
		case Clamp_ogl: return "Clamp_ogl";
		case Clamp_edge: return "Clamp_edge";
		case Clamp_border: return "Clamp_border";
		case AddressMode_Invalid: return "AddressMode_Invalid";
		default: break;
		}
		return "AddressMode_unknown";
	}
	
	std::string Texture::toString(Type type) {
		switch (type) {
		case Unsigned: return "Unsigned";
		case Signed: return "Signed";
		case Float: return "Float";
		case Invalid: return "Invalid";
		default: break;
		}
		return "Type_unknown";
	}

	std::string Texture::toString() const {
		return ".global " + toString(surfaceType) + " " + name + ";";
	}

	ir::PTXOperand::DataType Texture::convertFromChannelDataType(Texture::ChannelDataType channelData) {
		switch (channelData) {
		case CL_SNORM_INT8:
				break;
		case CL_SNORM_INT16:
				break;
		case CL_UNORM_INT8:
				break;
		case CL_UNORM_INT16:
				break;
		case CL_UNORM_SHORT_565:
				break;
		case CL_UNORM_SHORT_555:
				break;
		case CL_UNORM_INT_101010:
				break;
		case CL_SIGNED_INT8:
				return ir::PTXOperand::s8;
		case CL_SIGNED_INT16:
				return ir::PTXOperand::s16;
		case CL_SIGNED_INT32:
				return ir::PTXOperand::s32;
		case CL_UNSIGNED_INT8:
				return ir::PTXOperand::u8;
		case CL_UNSIGNED_INT16:
				return ir::PTXOperand::u16;
		case CL_UNSIGNED_INT32:
				return ir::PTXOperand::u32;
		case CL_HALF_FLOAT:
				return ir::PTXOperand::f16;
		case CL_FLOAT:
				return ir::PTXOperand::f32;
				break;
		default:
			break;
		}
		return ir::PTXOperand::u64;
	}
	
	Texture::ChannelDataType Texture::convertFromPTXDataType(PTXOperand::DataType ptxData) {
		switch (ptxData) {
		case PTXOperand::s8:
			return CL_SIGNED_INT8;
		case PTXOperand::s16:
			return CL_SIGNED_INT16;
		case PTXOperand::s32:
			return CL_SIGNED_INT32;
		case PTXOperand::b8:	// fall through
		case PTXOperand::u8:
			return CL_UNSIGNED_INT8;
		case PTXOperand::b16:	// fall through
		case PTXOperand::u16:
			return CL_UNSIGNED_INT16;
		case PTXOperand::b32: // fall through
		case PTXOperand::u32:
			return CL_UNSIGNED_INT32;
		case PTXOperand::f16:
			return CL_HALF_FLOAT;
		case PTXOperand::f32:
			return CL_FLOAT;
		default:
			break;
		}
		return ir::Texture::ChannelDataType_Invalid;
	}
}

#endif

