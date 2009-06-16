/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */

#ifndef _RENDERCHECK_GL_H_
#define _RENDERCHECK_GL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <map>
#include <string>

#include <GL/glew.h>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <nvShaderUtils.h>

using std::vector;
using std::map;
using std::string;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))


class CheckRender
{
public:
    CheckRender() {}
	CheckRender(unsigned int width, unsigned int height, unsigned int bpp,
    			bool bQAReadback, bool bUseFBO, bool bUsePBO);

	virtual ~CheckRender();

    virtual void allocateMemory( unsigned int width, unsigned int height, unsigned int bpp,
	    	                    bool bQAReadback, bool bUseFBO, bool bUsePBO );

    virtual void setExecPath(char *path) {
        strcpy(m_ExecPath, path);
    }
    virtual void EnableQAReadback(bool bStatus) { m_bQAReadback = bStatus; }
    virtual bool IsQAReadback() { return m_bQAReadback; }
    virtual bool IsFBO()        { return m_bUseFBO; }
    virtual bool IsPBO()        { return m_bUsePBO; }

    // Interface to this class functions
    virtual void setPixelFormat(GLenum format) { m_PixelFormat = format; }
    virtual int  getPixelFormat() { return m_PixelFormat; }
    virtual bool checkStatus(const char *zfile, int line, bool silent) = 0;
    virtual void freeResources() = 0;
    virtual bool readback(GLuint width, GLuint height, void **ppReadBackBuf ) = 0;

    virtual void savePPM(  const char *zfilename, bool bInvert, void **ppReadBuf );
    virtual bool PPMvsPPM( const char *src_file, const char *ref_file, const float epsilon = 0.0f );

	virtual void bindFragmentProgram()  = 0;
	virtual void bindRenderPath()       = 0;
	virtual void unbindRenderPath()     = 0;

	virtual void bindTexture()          = 0;
	virtual void unbindTexture()        = 0;

	virtual void bindReadback();
    virtual void unbindReadback();

protected:
    unsigned int m_Width, m_Height, m_Bpp;
    void        *m_pImageData;  // This is the image data stored in system memory
    bool         m_bQAReadback, m_bUseFBO, m_bUsePBO;
    GLuint       m_pboReadback;
    GLenum       m_PixelFormat;
    char         m_ExecPath[256];
};


class CheckBackBuffer : public CheckRender
{
public:
	CheckBackBuffer(unsigned int width, unsigned int height, unsigned int bpp);
	virtual ~CheckBackBuffer();

	virtual bool checkStatus(const char *zfile, int line, bool silent);
    virtual void freeResources() {};
    bool readback( GLuint width, GLuint height, void **ppReadBackBuf );

private:
	virtual void bindFragmentProgram() {}; 
	virtual void bindRenderPath() {};
	virtual void unbindRenderPath() {};

	// bind to the FBO to Texture
	virtual void bindTexture() {}; 

	// release this bind
	virtual void unbindTexture() {}; 
};


// structure defining the properties of a single buffer
struct bufferConfig {
    string name;
    GLenum format;
    int bits;
};

// structures defining properties of an FBO
struct fboConfig {
    string name;
    GLenum colorFormat;
    GLenum depthFormat;
    int redbits;
    int depthBits;
    int depthSamples;
    int coverageSamples;
};

struct fboData {
    GLuint tex; //color texture
    GLuint depthTex; //depth texture
    GLuint fb; // render framebuffer
    GLuint resolveFB; //multisample resolve target
    GLuint colorRB; //color render buffer
    GLuint depthRB; // depth render buffer
};


// CheckFBO - render and verify contents of the FBO
class CheckFBO: public CheckRender
{
public:
	CheckFBO(unsigned int width, unsigned int height, unsigned int bpp);
	CheckFBO(unsigned int width, unsigned int height, unsigned int bpp, fboData &data, fboConfig &config);

	virtual ~CheckFBO();

	virtual bool checkStatus(const char *zfile, int line, bool silent);
	virtual void freeResources();
	virtual bool readback( GLuint width, GLuint height, void **ppReadBackBuf );

	bool initialize(unsigned width, unsigned height, fboConfig & rConfigFBO, fboData & rActiveFBO);
	bool create( GLuint width, GLuint height, fboConfig &config, fboData &data );
	bool createMSAA( GLuint width, GLuint height, fboConfig *p_config, fboData *p_data );
	bool createCSAA( GLuint width, GLuint height, fboConfig *p_config, fboData *p_data );

	// bind the fragment program we'll just render the quad as
	virtual void bindFragmentProgram()
	{
        if (!m_bQAReadback || !m_bUseFBO) {
            printf("CheckFBO::bindFragmentProgram() uninitialized!\n");
            return;
        }
		glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, m_textureProgram);
		glEnable(GL_FRAGMENT_PROGRAM_ARB);
	}

	// bind to the FrameBuffer Object
	virtual void bindRenderPath()
	{
        if (!m_bQAReadback || !m_bUseFBO) {
            printf("CheckFBO::bindReaderPath() uninitialized!\n");
            return;
        }
		glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, m_fboData.fb );
	}

	// release current FrameBuffer Object
	virtual void unbindRenderPath()
	{
        if (!m_bQAReadback || !m_bUseFBO) {
            printf("CheckFBO::unbindReaderPath() uninitialized!\n");
            return;
        }
		glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, 0 );
	}

	// bind to the FBO to Texture
	virtual void bindTexture()
	{
        if (!m_bQAReadback || !m_bUseFBO) {
            printf("CheckFBO::v() uninitialized!\n");
            return;
        }
		glBindTexture( GL_TEXTURE_2D, m_fboData.tex );
	}

	// release this bind
	virtual void unbindTexture()
	{
        if (!m_bQAReadback || !m_bUseFBO) {
            printf("CheckFBO::unbindTexture() uninitialized!\n");
            return;
        }
		glBindTexture( GL_TEXTURE_2D, 0 );
	}


private:
	fboData		m_fboData;
	fboConfig	m_fboConfig;

	GLuint		m_textureProgram;
	GLuint		m_overlayProgram;
};

#endif // _RENDERCHECK_GL_H_

