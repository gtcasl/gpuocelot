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

//
// CheckBackBuffer/FBO verification Class
//
//  This piece of code is used to to allow us verify the contents from the frame bufffer
//  of graphics samples.  We can render to the CheckBackBuffer or FBO in OpenGL, and read the
//  contents back for the purpose of comparisons
//
//  http://www.nvidia.com/dev_content/nvopenglspecs/GL_EXT_framebuffer_object.txt
//
// Authors: Mark Harris, Evan Hart, Simon Green, and Eric Young
// Email: sdkfeedback@nvidia.com
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <cutil.h>
#include "rendercheck_gl.h"

// CheckRender::Base class for CheckRender (there will be default functions all classes derived from this)
CheckRender::CheckRender(unsigned int width, unsigned int height, unsigned int bpp,
			            bool bQAReadback, bool bUseFBO, bool bUsePBO) 
{
    allocateMemory(width, height, bpp, bQAReadback, bUseFBO, bUsePBO);
}

CheckRender::~CheckRender() 
{
	// Release PBO resources
	glDeleteBuffersARB(1, &m_pboReadback);
	m_pboReadback = 0;            

    free(m_pImageData);
}

void 
CheckRender::allocateMemory( unsigned int width, unsigned int height, unsigned int bpp,
                            bool bQAReadback, bool bUseFBO, bool bUsePBO ) 
{
    m_Width         = width;
    m_Height        = height;
    m_Bpp           = bpp;
    m_bQAReadback   = bQAReadback;
    m_bUseFBO       = bUseFBO;
    m_bUsePBO       = bUsePBO;
    m_PixelFormat   = GL_BGRA;

    // Create the PBO for readbacks
    if (m_bUsePBO) {
        glGenBuffersARB(1, &m_pboReadback);
        glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, m_pboReadback);
        glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, m_Width*m_Height*m_Bpp, NULL, GL_STREAM_READ);
        glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
    }

    m_pImageData = malloc(m_Width*m_Height*m_Bpp);  // This is the image data stored in system memory
}

void 
CheckRender::savePPM(  const char *zfilename, bool bInvert, void **ppReadBuf )
{
    if (zfilename != NULL) {
        if (bInvert) {
            unsigned char *readBuf;
            unsigned char *writeBuf= (unsigned char *)malloc(m_Width * m_Height * m_Bpp);

            for (unsigned int y=0; y < m_Height; y++) {
                if (ppReadBuf) {
                    readBuf = *(unsigned char **)ppReadBuf;
                } else {
                    readBuf = (unsigned char *)m_pImageData;
                }
                memcpy(&writeBuf[m_Width*m_Bpp*y], (readBuf+ m_Width*m_Bpp*(m_Height-1-y)), m_Width*m_Bpp);
            }
            // we copy the results back to original system buffer
            if (ppReadBuf) {
                memcpy(*ppReadBuf, writeBuf, m_Width*m_Height*m_Bpp);
            } else {
                memcpy(m_pImageData, writeBuf, m_Width*m_Height*m_Bpp);
            }
            free (writeBuf);
        }
        printf("> Saving PPM: <%s>\n", zfilename);
        if (ppReadBuf) {
		    cutSavePPM4ub(zfilename, *(unsigned char **)ppReadBuf, m_Width, m_Height);
        } else {
		    cutSavePPM4ub(zfilename, (unsigned char *)m_pImageData, m_Width, m_Height);
        }
    }
}

bool 
CheckRender::PPMvsPPM( const char *src_file, const char *ref_file, const float epsilon )
{
    unsigned char *src_data, *ref_data;
    unsigned long error_count = 0;
    unsigned int width, height;

    char *ref_path = cutFindFilePath(ref_file, m_ExecPath);
    if (src_file == NULL || ref_path == NULL) {
        printf("PPMvsPPM: Aborting comparison\n");
        return false;
    }
    printf("> Comparing (a)rendered: <%s>, (b)reference: <%s>\n", src_file, ref_path);

    if (cutLoadPPM4ub(ref_path, &ref_data, &width, &height) != CUTTrue) {
        printf("PPMvsPPM: unable to load ref image file: %s\n", ref_file);
        return false;
    }

    if (cutLoadPPM4ub(src_file, &src_data, &width, &height) != CUTTrue) {
        printf("PPMvsPPM: unable to load src image file: %s\n", src_file);
        return false;
    }

    printf("PPMvsPPM: comparing images size (%d,%d) epsilon(%2.4f)\n", m_Height, m_Width, epsilon);
    if (cutCompareube( ref_data, src_data, m_Height*m_Width*4, epsilon ) == CUTFalse) {
        error_count = 1;
    }

    if (error_count == 0) { 
        printf("  PASSED!\n"); 
    } else {
        printf("  FAILED! %d errors...\n", (unsigned int)error_count);
    }
    return (error_count == 0);  // returns true if all pixels pass
}

void CheckRender::bindReadback() {
    if (!m_bQAReadback) {
        printf("CheckRender::bindReadback() uninitialized!\n");
        return;
    }
    if (m_bUsePBO) {
		glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, m_pboReadback);	// Bind the PBO
    }
}

void CheckRender::unbindReadback() {
    if (!m_bQAReadback) {
        printf("CheckRender::unbindReadback() uninitialized!\n");
        return;
    }
    if (m_bUsePBO) {
		glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, 0);	// Release the bind on the PBO
    }
}


// CheckBackBuffer::Class for rendering and verifying results from the CheckBackBuffer
CheckBackBuffer::CheckBackBuffer(unsigned int width, unsigned int height, unsigned int bpp) : 
			CheckRender(width, height, bpp, false, false, false)
{
}

CheckBackBuffer::~CheckBackBuffer()
{
}

bool CheckBackBuffer::checkStatus(const char *zfile, int line, bool silent)
{
    GLenum nErrorCode = glGetError();

    if (nErrorCode != GL_NO_ERROR)
    {
        if (!silent)
           printf("Assertion failed(%s,%d): %s\n", zfile, line, gluErrorString(nErrorCode));
    }
    return true;
}

//////////////////////////////////////////////////////////////////////
//  readback
//
//////////////////////////////////////////////////////////////////////
bool CheckBackBuffer::readback( GLuint width, GLuint height, void **ppReadBackBuf )
{
    bool ret = false;

    if (m_bUsePBO) {
        // binds the PBO for readback
        bindReadback();

        // Now initiate the readback to PBO
	    glReadPixels(0, 0, width, height, getPixelFormat(),      GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
        ret = checkStatus(__FILE__, __LINE__, true);
        if (!ret) printf("CheckBackBuffer::glReadPixels() checkStatus = %d\n", ret);

	    // map - unmap simulates readback without the copy
	    void *ioMem = glMapBufferARB(GL_PIXEL_PACK_BUFFER_ARB, GL_READ_ONLY_ARB);
        if (ppReadBackBuf == NULL) {
            memcpy(m_pImageData,    ioMem, width*height*m_Bpp);
        } else {
    	    memcpy(*ppReadBackBuf,  ioMem, width*height*m_Bpp);
        }
	    glUnmapBufferARB(GL_PIXEL_PACK_BUFFER_ARB);

        // release the PBO
        unbindReadback();
    } else {
        // reading direct from the backbuffer
        glReadBuffer(GL_FRONT);
        glReadPixels(0, 0, width, height, getPixelFormat(), GL_UNSIGNED_BYTE, m_pImageData);
    }

    return ret; 
}
// End of class for rendering to CheckBackBuffer


// Class for verify and rendering to FBO
CheckFBO::CheckFBO(unsigned int width, unsigned int height, unsigned int bpp) :
			CheckRender(width, height, bpp, false, true, true)
{
	initialize(width, height, m_fboConfig, m_fboData);
};

CheckFBO::CheckFBO(unsigned int width, unsigned int height, unsigned int bpp, fboData &data, fboConfig &config) :
			CheckRender(width, height, bpp, false, true, true),
			m_fboData(data), 
			m_fboConfig(config)
{
	initialize(width, height, m_fboConfig, m_fboData);
}

CheckFBO::~CheckFBO() 
{
	freeResources();
};


//////////////////////////////////////////////////////////////////////
//  initialize
//
//   helper function to setup the FBO
//////////////////////////////////////////////////////////////////////
bool CheckFBO::initialize(unsigned int width, unsigned int height, fboConfig & rConfigFBO, fboData & rActiveFBO)
{
    //Framebuffer config options
    vector<bufferConfig> colorConfigs;
    vector<bufferConfig> depthConfigs;
    bufferConfig temp;

    //add default color configs
    temp.name = "RGBA8";
    temp.bits = 8;
    temp.format = GL_RGBA8;
    colorConfigs.push_back( temp);

    //add default depth configs
    temp.name = "D24";
    temp.bits = 24;
    temp.format = GL_DEPTH_COMPONENT24;
    depthConfigs.push_back( temp );

    // If the FBO can be created, add it to the list of available configs, and make a menu entry
    string root = colorConfigs[0].name + " " + depthConfigs[0].name;

    rConfigFBO.colorFormat	= colorConfigs[0].format;
    rConfigFBO.depthFormat	= depthConfigs[0].format;
    rConfigFBO.redbits		= colorConfigs[0].bits;
    rConfigFBO.depthBits	= depthConfigs[0].bits;

    //single sample
    rConfigFBO.name				= root;
    rConfigFBO.coverageSamples	= 0;
    rConfigFBO.depthSamples		= 0;

    create( width, height, rConfigFBO, rActiveFBO );

    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    // load fragment programs
    const char* strTextureProgram2D = 
        "!!ARBfp1.0\n"
        "TEX result.color, fragment.texcoord[0], texture[0], 2D;\n"
        "END\n";

    m_textureProgram = nv::CompileASMShader( GL_FRAGMENT_PROGRAM_ARB, strTextureProgram2D );

    const char* strOverlayProgram = 
        "!!ARBfp1.0\n"
        "TEMP t;\n"
        "TEX t, fragment.texcoord[0], texture[0], 2D;\n"
        "MOV result.color, t;\n"
        "END\n";
    
    m_overlayProgram = nv::CompileASMShader( GL_FRAGMENT_PROGRAM_ARB, strOverlayProgram );

	return 0;
}

//////////////////////////////////////////////////////////////////////
//  checkStatus of FBO
//
//   Check the framebuffer status to ensure it is a supported
//    config.
//////////////////////////////////////////////////////////////////////
bool CheckFBO::checkStatus(const char *zfile, int line, bool silent)
{
    GLenum status;
    status = (GLenum) glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
	if (status != GL_FRAMEBUFFER_COMPLETE_EXT) {
		printf("<%s : %d> - ", zfile, line);
	}

	switch(status) {
        case GL_FRAMEBUFFER_COMPLETE_EXT:
            break;
        case GL_FRAMEBUFFER_UNSUPPORTED_EXT:
			if (!silent) printf("Unsupported framebuffer format\n");
            return false;
        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT:
            if (!silent) printf("Framebuffer incomplete, missing attachment\n");
            return false;
        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT:
            if (!silent) printf("Framebuffer incomplete, duplicate attachment\n");
            return false;
        case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT:
            if (!silent) printf("Framebuffer incomplete, attached images must have same dimensions\n");
            return false;
        case GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT:
            if (!silent) printf("Framebuffer incomplete, attached images must have same format\n");
            return false;
        case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT:
            if (!silent) printf("Framebuffer incomplete, missing draw buffer\n");
            return false;
        case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT:
            if (!silent) printf("Framebuffer incomplete, missing read buffer\n");
            return false;
        default:
            assert(0);
            return false;
    }
    return true;
}

//////////////////////////////////////////////////////////////////////
//  freeResources
//
//   Free all allocated FBO based resources on the given config, if the created FBO
//////////////////////////////////////////////////////////////////////
void CheckFBO::freeResources() 
{
	if (m_fboData.fb)           glDeleteFramebuffersEXT( 1, &m_fboData.fb);
    if (m_fboData.resolveFB)    glDeleteFramebuffersEXT( 1, &m_fboData.resolveFB);
    if (m_fboData.colorRB)      glDeleteRenderbuffersEXT( 1, &m_fboData.colorRB);
    if (m_fboData.depthRB)      glDeleteRenderbuffersEXT( 1, &m_fboData.depthRB);
    if (m_fboData.tex)          glDeleteTextures( 1, &m_fboData.tex);
    if (m_fboData.depthTex)     glDeleteTextures( 1, &m_fboData.depthTex);

	glDeleteProgramsARB(1, &m_textureProgram);
	glDeleteProgramsARB(1, &m_overlayProgram);
}

//////////////////////////////////////////////////////////////////////
//  readback 
//
//   Code to handle reading back of the FBO data
//
//////////////////////////////////////////////////////////////////////
bool CheckFBO::readback( GLuint width, GLuint height, void **ppReadBackBuf )
{
    bool ret = false;

    if (!m_bQAReadback || !m_bUseFBO) {
        printf("CheckFBO::readback() uninitialized!\n");
        return false;
    }

    // Reading back from FBO using glReadPixels
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_fboData.fb);
    ret = checkStatus(__FILE__, __LINE__, true);
    if (!ret) printf("CheckFBO::readback::glBindFramebufferEXT() checkStatus = %d\n", ret);

    glReadBuffer(static_cast<GLenum>(GL_COLOR_ATTACHMENT0_EXT));
    ret &= checkStatus(__FILE__, __LINE__, true);
    if (!ret) printf("CheckFBO::readback::glReadBuffer() checkStatus = %d\n", ret);

    if (ppReadBackBuf == NULL) {
        glReadPixels(0, 0, width, height, getPixelFormat(), GL_UNSIGNED_BYTE, m_pImageData);
    } else {
        glReadPixels(0, 0, width, height, getPixelFormat(), GL_UNSIGNED_BYTE, *ppReadBackBuf);
    }
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    return ret;
}


//////////////////////////////////////////////////////////////////////
//  create
//
//   Creates a FBO based on the given config, if the created FBO
// fails to validate, or the bits do not match the prescribed size,
// this it returns false. If the number of samples or coverage
// samples exceed the requested number, then the number of samples
// in the config is changed to match the number recieved.
//
//////////////////////////////////////////////////////////////////////
bool CheckFBO::create( GLuint width, GLuint height, fboConfig &config, fboData &data) 
{
    bool multisample = config.depthSamples > 0;
    bool csaa = config.coverageSamples > config.depthSamples;
    bool ret = true;
    GLint query;

    if (!m_bQAReadback || !m_bUseFBO) {
        printf("CheckFBO::create() uninitialized!\n");
        return false;
    }

    glGenFramebuffersEXT(1, &data.fb);
    glGenTextures(1, &data.tex);

    // init texture
    glBindTexture( GL_TEXTURE_2D, data.tex);
    glTexImage2D ( GL_TEXTURE_2D, 0, config.colorFormat, 
					width, height, 0, GL_RGBA, GL_FLOAT, NULL);

    glGenerateMipmapEXT( GL_TEXTURE_2D);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //
    // Handle multisample FBO's first
    //
    if (multisample) {
        if (csaa) {
			ret &= createCSAA(width, height, &config, &data);
        }
        else {
			ret &= createMSAA(width, height, &config, &data);
        }
       
        // attach the depth buffer
        glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, data.depthRB);
        ret &= checkStatus(__FILE__, __LINE__, true);
    } 
    else // case if not multisampled
	{ 
        glGenTextures( 1, &data.depthTex);
        data.depthRB = 0;
        data.colorRB = 0;
        data.resolveFB = 0;

        //non-multisample, so bind things directly to the FBO
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, data.fb); 
        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, data.tex, 0);

        glBindTexture(	GL_TEXTURE_2D, data.depthTex );
        glTexImage2D(	GL_TEXTURE_2D, 0, config.depthFormat, 
						width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameterf( GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);

        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, data.depthTex, 0);

        ret &= checkStatus(__FILE__, __LINE__, true);
    }
    
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, data.fb);
    glGetIntegerv( GL_RED_BITS, &query);
    if ( query != config.redbits) {
        ret = false;
    }

    glGetIntegerv( GL_DEPTH_BITS, &query);
    if ( query != config.depthBits) {
        ret = false;
    }

    if (multisample) {
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, data.resolveFB);
        glGetIntegerv( GL_RED_BITS, &query);
        if ( query != config.redbits) {
            ret = false;
        }
    }
    
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    return ret;
}

bool CheckFBO::createCSAA( GLuint width, GLuint height, fboConfig *p_config, fboData *p_data )
{
    GLint query;
    bool ret = false;

    if (!m_bQAReadback || !m_bUseFBO) {
        printf("CheckFBO::createCSAA() uninitialized!\n");
        return false;
    }

    // Step #1
    {
        glGenRenderbuffersEXT( 1, &p_data->depthRB);
        glGenRenderbuffersEXT( 1, &p_data->colorRB);
        glGenFramebuffersEXT( 1, &p_data->resolveFB);
        p_data->depthTex = 0; //no resolve of depth buffer for now
        
        //multisample, so we need to resolve from the FBO, bind the texture to the resolve FBO
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, p_data->resolveFB); 

        glFramebufferTexture2DEXT(	GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, 
									GL_TEXTURE_2D, p_data->tex, 0);

        ret &= checkStatus(__FILE__, __LINE__, true);

        //now handle the rendering FBO
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, p_data->fb);

        // initialize color renderbuffer
        glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, p_data->colorRB);
    }

	// Step #2
	{
		glRenderbufferStorageMultisampleCoverageNV( GL_RENDERBUFFER_EXT, 
													p_config->coverageSamples, 
													p_config->depthSamples, 
													p_config->colorFormat,
													width, height);

		glGetRenderbufferParameterivEXT( GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_COVERAGE_SAMPLES_NV, &query);

		if ( query < p_config->coverageSamples) {
		   ret = false;
		}
		else if ( query > p_config->coverageSamples) {
			// report back the actual number
			p_config->coverageSamples = query;
		}

		glGetRenderbufferParameterivEXT( GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_COLOR_SAMPLES_NV, &query);

		if ( query < p_config->depthSamples) {
		   ret = false;
		}
		else if ( query > p_config->depthSamples) {
			// report back the actual number
			p_config->depthSamples = query;
		}
	}

	// Step #3
	{
        // attach the multisampled color buffer
        glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_RENDERBUFFER_EXT, p_data->colorRB);

        ret &= checkStatus(__FILE__, __LINE__, true);

        // bind the multisampled depth buffer
        glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, p_data->depthRB);
	}

	// Step #4 create the multisampled depth buffer (with coverage sampling)
	{
        // create a coverage sampled MSAA depth buffer
        glRenderbufferStorageMultisampleCoverageNV( GL_RENDERBUFFER_EXT, 
													p_config->coverageSamples, 
													p_config->depthSamples, 
													p_config->depthFormat,
                                                    width, height);

        // check the number of coverage samples
        glGetRenderbufferParameterivEXT( GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_COVERAGE_SAMPLES_NV, &query);

        if ( query < p_config->coverageSamples) {
            ret = false;
        }
        else if ( query > p_config->coverageSamples) {
            // set the coverage samples value to return the actual value
            p_config->coverageSamples = query;
        } 

        // cehck the number of stored color samples (same as depth samples)
        glGetRenderbufferParameterivEXT( GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_COLOR_SAMPLES_NV, &query);

        if ( query < p_config->depthSamples) {
            ret = false;
        }
        else if ( query > p_config->depthSamples) {
            // set the depth samples value to return the actual value
            p_config->depthSamples = query;
        }
	}
	return ret;
}

bool CheckFBO::createMSAA( GLuint width, GLuint height, fboConfig *p_config, fboData *p_data )
{
	GLint query;
	bool ret = false;

    if (!m_bQAReadback || !m_bUseFBO) {
        printf("CheckFBO::createMSAA() uninitialized!\n");
        return false;
    }

	// Step #1
	{
        glGenRenderbuffersEXT( 1, &p_data->depthRB   );
        glGenRenderbuffersEXT( 1, &p_data->colorRB   );
        glGenFramebuffersEXT ( 1, &p_data->resolveFB );
        p_data->depthTex = 0; //no resolve of depth buffer for now
        
        //multisample, so we need to resolve from the FBO, bind the texture to the resolve FBO
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, p_data->resolveFB); 

        glFramebufferTexture2DEXT(	GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, 
									GL_TEXTURE_2D, p_data->tex, 0);
        ret &= checkStatus(__FILE__, __LINE__, true);

        //now handle the rendering FBO
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, p_data->fb);

        // initialize color renderbuffer
        glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, p_data->colorRB);
	}

	// Step #2
	{
		// create a regular MSAA color buffer
		glRenderbufferStorageMultisampleEXT( GL_RENDERBUFFER_EXT, 
											p_config->depthSamples, 
											p_config->colorFormat, 
											width, height);
		// check the number of samples
		glGetRenderbufferParameterivEXT( GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_SAMPLES_EXT, &query);

		if ( query < p_config->depthSamples) {
			ret = false;
		}
		else if ( query > p_config->depthSamples) {
			p_config->depthSamples = query;
		}
	}

	// Step #3
	{
        // attach the multisampled color buffer
        glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_RENDERBUFFER_EXT, p_data->colorRB);
        ret &= checkStatus(__FILE__, __LINE__, true);

        // bind the multisampled depth buffer
        glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, p_data->depthRB);
	}

	// Step #4 - create the multisampled depth buffer (without coverage sampling)
	{
        // create a regular (not coverage sampled) MSAA depth buffer
        glRenderbufferStorageMultisampleEXT(	GL_RENDERBUFFER_EXT, 
												p_config->depthSamples, 
												p_config->depthFormat, 
												width, height);

        // check the number of depth samples
        glGetRenderbufferParameterivEXT( GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_SAMPLES_EXT, &query);

        if ( query < p_config->depthSamples) {
            ret = false;
        }
        else if ( query < p_config->depthSamples) {
            p_config->depthSamples = query;
        }
	}

	return ret;
}

