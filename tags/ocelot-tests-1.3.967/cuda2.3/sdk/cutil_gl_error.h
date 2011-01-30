/*
* Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
*
* NVIDIA Corporation and its licensors retain all intellectual property and 
* proprietary rights in and to this software and related documentation and 
* any modifications thereto.  Any use, reproduction, disclosure, or distribution 
* of this software and related documentation without an express license 
* agreement from NVIDIA Corporation is strictly prohibited.
* 
*/

#ifndef CUTIL_GL_ERROR
#define CUTIL_GL_ERROR

/* CUda UTility Library */

// includes, system
#ifdef _WIN32
#  define WINDOWS_LEAN_AND_MEAN
#  include <windows.h>
#  include <stdlib.h>
#  undef min
#  undef max
#endif

// includes, graphics
#if defined (__APPLE__) || defined(MACOSX)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

////////////////////////////////////////////////////////////////////////////
//! Check for OpenGL error
//! @return CUTTrue if no GL error has been encountered, otherwise 0
//! @param file  __FILE__ macro
//! @param line  __LINE__ macro
//! @note The GL error is listed on stderr
//! @note This function should be used via the CHECK_ERROR_GL() macro
////////////////////////////////////////////////////////////////////////////
CUTBoolean CUTIL_API
cutCheckErrorGL( const char* file, const int line) 
{
	CUTBoolean ret_val = CUTTrue;

	// check for error
	GLenum gl_error = glGetError();
	if (gl_error != GL_NO_ERROR) 
	{
		fprintf(stderr, "GL Error in file '%s' in line %d :\n", file, line);
		fprintf(stderr, "%s\n", gluErrorString(gl_error));
		ret_val = CUTFalse;
	}
	return ret_val;
}

#ifdef _DEBUG

#define CUT_CHECK_ERROR_GL()                                               \
	if( CUTFalse == cutCheckErrorGL( __FILE__, __LINE__)) {                  \
	exit(EXIT_FAILURE);                                                  \
	}
#else

#define CUT_CHECK_ERROR_GL()                                               \

#endif // _DEBUG

#endif // CUTIL_GL_ERROR
