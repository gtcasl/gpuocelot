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
	std::string Texture::toString(Type type) {
		std::string typeStr;
		switch (type) {
			case Signed:
				typeStr = ".s32";
				break;
			case Float:
				typeStr = ".f32";
				break;
			case Unsigned:
			default:
				typeStr = ".u32";
				break;
		}
		return typeStr;
	}

	Texture::Texture(const std::string& n, Type t) : name(n), normalize(false), 
		type(t), size( Dim3(0, 0, 0) ), data( 0 ) {
		
	}
	
	std::string Texture::toString() const {
		return ".tex " + toString(type) + " " + name + ";";
	}

}

#endif

