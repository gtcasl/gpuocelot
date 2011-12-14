/*
* Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
*
* NOTICE TO USER:
*
* This source code is subject to NVIDIA ownership rights under U.S. and
* international Copyright laws.
*
* This software and the information contained herein is PROPRIETARY and
* CONFIDENTIAL to NVIDIA and is being provided under the terms and
* conditions of a Non-Disclosure Agreement.  Any reproduction or
* disclosure to any third party without the express written consent of
* NVIDIA is prohibited.
*
* NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
* CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
* IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
* REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
* OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
* OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
* OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE
* OR PERFORMANCE OF THIS SOURCE CODE.
*
* U.S. Government End Users.  This source code is a "commercial item" as
* that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of
* "commercial computer software" and "commercial computer software
* documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995)
* and is provided to the U.S. Government only as a commercial end item.
* Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
* 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
* source code with only those rights set forth herein.
*/

/* 
    This example demonstrates the use of CUDA/OpenGL interoperability
    to post-process an image of a 3D scene generated in OpenGL.

    The basic steps are:
    1 - render the scene to the framebuffer
    2 - copy the image to a PBO (pixel buffer object)
    3 - map this PBO so that its memory is accessible from CUDA
    4 - run CUDA to process the image, writing to memory mapped from a second PBO
    6 - copy from result PBO to a texture
    7 - display the texture

    Press space to toggle the CUDA processing on/off.
    Press 'a' to toggle animation.
    Press '+' and '-' to increment and decrement blur radius
*/

#ifdef _WIN32
#  define WINDOWS_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#pragma warning(disable:4996)
#endif

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, GL
#include <GL/glew.h>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cuda_runtime_api.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cutil_gl_error.h>
#include <cuda_gl_interop.h>

#include <rendercheck_gl.h>

bool g_bQAReadback = false;
bool g_bFBODisplay = true;

#define MAX_EPSILON 10

// FLOAT textures not quite working yet
#define USE_FLOAT		    0
#define USE_SHADER_FLOAT    0

#if USE_FLOAT
	#define TEXFMT_INTERNAL GL_RGBA
	#define TEXFMT_EXTERNAL GL_RGBA32F_ARB
    #define TEXFMT_TYPE     GL_FLOAT
#else
	#define TEXFMT_INTERNAL GL_BGRA
	#define TEXFMT_EXTERNAL GL_RGBA8
    #define TEXFMT_TYPE     GL_UNSIGNED_BYTE
#endif

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "teapot_2.ppm",
    "teapot_4.ppm",
    "teapot_8.ppm",
    "teapot_16.ppm",
    NULL
};

const char *sReference[] =
{
    "ref_2.ppm",
    "ref_4.ppm",
    "ref_8.ppm",
    "ref_16.ppm",
    NULL
};

unsigned int g_TotalErrors = 0;

// CheckFBO/BackBuffer class objects
CheckRender *g_CheckRender = NULL;

////////////////////////////////////////////////////////////////////////////////
// constants / global variables
unsigned int window_width = 64;
unsigned int window_height = 64;
unsigned int image_width = 64;
unsigned int image_height = 64;

// pbo and fbo variables
GLuint pbo_source;
GLuint pbo_dest;
GLuint fbo_source;
GLuint tex_source;

// shader ID
GLuint shader;

unsigned int size_tex_data;
unsigned int num_texels;
unsigned int num_values;

// (offscreen) render target
// fbo variables
GLuint framebuffer;
GLuint tex_screen;
GLuint depth_buffer;

float rotate[3];

bool enable_cuda = true;
bool animate = true;
int blur_radius = 8;
int g_Index = 0;

// Timer
static int fpsCount = 0;
static int fpsLimit = 1;
unsigned int timer;

////////////////////////////////////////////////////////////////////////////////
extern "C" void
launch_cudaProcess(dim3 grid, dim3 block, int sbytes, int* g_data, int* g_odata, 
					int imgw, int imgh, int tilew, 
					int radius, float threshold, float highlight);

//extern "C" void process(int pbo_in, int pbo_out, int width, int height, int radius);

// declaration, forward
void runTest(int argc, char** argv);
void cleanup();

// GL functionality
bool initCUDA( int argc, char **argv );
bool initGL(int argc, char** argv);
void createPBO(GLuint* pbo);
void deletePBO(GLuint* pbo);
void createFBO(GLuint* fbo, GLuint* tex, unsigned int size_x, unsigned int size_y);
void deleteFBO(GLuint* fbo);

void createTexture(GLuint* tex_name, unsigned int size_x, unsigned int size_y);
void deleteTexture(GLuint* tex);
void createDepthBuffer(GLuint* depth, unsigned int size_x, unsigned int size_y);
void deleteDepthBuffer(GLuint* depth);
void createFramebuffer(GLuint* fbo, GLuint color, GLuint depth);
void deleteFramebuffer(GLuint* fbo);

// rendering callbacks
void display();
void idle();
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);
void mainMenu(int i);
void runTest(int argc, char** argv);


////////////////////////////////////////////////////////////////////////////////
//! Run the Cuda part of the computation
////////////////////////////////////////////////////////////////////////////////
void process(int pbo_in, int pbo_out, int width, int height, int radius) 
{
    int *in_data;
    int* out_data;

    // map buffer objects to get CUDA device pointers
    cutilSafeCall(cudaGLMapBufferObject( (void**)&in_data, pbo_in));
    cutilSafeCall(cudaGLMapBufferObject( (void**)&out_data, pbo_out));

    // calculate grid size
    dim3 block(16, 16, 1);
    dim3 grid(width / block.x, height / block.y, 1);
    int sbytes = (block.x+(2*radius))*(block.y+(2*radius))*sizeof(int);

    // execute CUDA kernel
    launch_cudaProcess(grid, block, sbytes, 
                       in_data, out_data, width, height, 
                       block.x+(2*radius), radius, 0.8f, 4.0f);

    cutilSafeCall(cudaGLUnmapBufferObject( pbo_in));
    cutilSafeCall(cudaGLUnmapBufferObject( pbo_out));
}

////////////////////////////////////////////////////////////////////////////////
//! Create PBO
////////////////////////////////////////////////////////////////////////////////
void
createPBO(GLuint* pbo)
{
    // set up vertex data parameter
    num_texels = image_width * image_height;
    num_values = num_texels * 4;
    size_tex_data = sizeof(GLubyte) * num_values;
    void *data = malloc(size_tex_data);

    // create buffer object
    glGenBuffers(1, pbo);
    glBindBuffer(GL_ARRAY_BUFFER, *pbo);
    glBufferData(GL_ARRAY_BUFFER, size_tex_data, data, GL_DYNAMIC_DRAW);
    free(data);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // register this buffer object with CUDA
    cutilSafeCall(cudaGLRegisterBufferObject(*pbo));

    CUT_CHECK_ERROR_GL();
}

////////////////////////////////////////////////////////////////////////////////
//! Delete PBO
////////////////////////////////////////////////////////////////////////////////
void
deletePBO(GLuint* pbo)
{
    // unregister this buffer object with CUDA
    cutilSafeCall(cudaGLUnregisterBufferObject(*pbo));

    glBindBuffer(GL_ARRAY_BUFFER, *pbo);
    glDeleteBuffers(1, pbo);
    CUT_CHECK_ERROR_GL();

    *pbo = 0;
}

// render a simple 3D scene
void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(rotate[0], 1.0, 0.0, 0.0);
    glRotatef(rotate[1], 0.0, 1.0, 0.0);
    glRotatef(rotate[2], 0.0, 0.0, 1.0);

    glViewport(0, 0, 512, 512);

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    glutSolidTeapot(1.0);

    CUT_CHECK_ERROR_GL();
}

// copy image and process using CUDA
void processImage()
{
    // read data into source pbo. note: use BGRA format for optimal performance
    glBindBuffer(GL_PIXEL_PACK_BUFFER_ARB, pbo_source);
    glReadPixels(0, 0, image_width, image_height, GL_BGRA, GL_UNSIGNED_BYTE, NULL); 

    // run the Cuda kernel
    process(pbo_source, pbo_dest, image_width, image_height, blur_radius);

    // download texture from destination PBO
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, pbo_dest);
    glBindTexture(GL_TEXTURE_2D, tex_screen);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 
                    image_width, image_height, 
                    GL_BGRA, GL_UNSIGNED_BYTE, NULL);

    glBindBuffer(GL_PIXEL_PACK_BUFFER_ARB, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    CUT_CHECK_ERROR_GL();
}

// display image to the screen as textured quad
void displayImage()
{
    // render a screen sized quad
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, window_width, window_height);

#if USE_FLOAT_SHADER
    // fragment program is required to display floating point texture
    glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, shader);
    glEnable(GL_FRAGMENT_PROGRAM_ARB);
    glDisable(GL_DEPTH_TEST);
#endif

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.5);
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    CUT_CHECK_ERROR_GL();
}

void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "AutoTest: CUDA OpenGL post-processing");

        glutSetWindowTitle(temp);

		if (blur_radius >= 2) g_Index++;
		blur_radius *= 2;

		if (blur_radius > 16) {
			printf("Summary: %d errors!\n", g_TotalErrors);
			printf("Test %s!\n", (g_TotalErrors==0) ? "PASSED" : "FAILED");
			cudaThreadExit();
			exit(0);
		}
    }
}


////////////////////////////////////////////////////////////////////////////////
//! Display callback
////////////////////////////////////////////////////////////////////////////////
void
display()
{
    cutStartTimer(timer);

    if (enable_cuda) {
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, framebuffer);
        renderScene();
        processImage();
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
        displayImage();
    } else {
        renderScene();
    }

	cutStopTimer(timer);
    glutSwapBuffers();

    if (g_CheckRender && g_CheckRender->IsQAReadback() ) {
		if (enable_cuda) {
	        g_CheckRender->readback( window_width, window_height, framebuffer );
		} else {
			g_CheckRender->readback( window_width, window_height );
		}
        g_CheckRender->savePPM ( sOriginal[g_Index], true, NULL);
        if (!g_CheckRender->PPMvsPPM( sOriginal[g_Index], sReference[g_Index], MAX_EPSILON, 0.30f )) {
            g_TotalErrors++;   
        }
	}

	AutoQATest();

   fpsCount++;
   if (fpsCount == fpsLimit) {
       char fps[256];
       float ifps = 1.f / (cutGetAverageTimerValue(timer) / 1000.f);
       sprintf(fps, "CUDA GL Post Processing(%d x %d): %3.1f fps", window_width, window_height, ifps);  
       printf("CUDA GL Post Processing(%d x %d): %3.1f fps\n",window_width, window_height, ifps);
       glutSetWindowTitle(fps);
       fpsCount = 0; 
       fpsLimit = (int)((ifps > 1.f) ? ifps : 1.f);
       cutResetTimer(timer);  
    }

}

void idle()
{
    if (animate) {
        rotate[0] += 0.2;
        rotate[1] += 0.6;
        rotate[2] += 1.0;
    }
    glutPostRedisplay();
}

////////////////////////////////////////////////////////////////////////////////
//! Keyboard events handler
////////////////////////////////////////////////////////////////////////////////
void
keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch(key) {
    case(27) :
		cleanup();
        cudaThreadExit();
        exit(0);
    case ' ':
        enable_cuda ^= 1;
        break;
    case 'a':
        animate ^= 1;
        break;
    case '=':
    case '+':
        if (blur_radius < 16) blur_radius++;
        printf("radius = %d\n", blur_radius);
        break;
    case '-':
        if (blur_radius > 1) blur_radius--;
        printf("radius = %d\n", blur_radius);
        break;
    }
}

void reshape(int w, int h)
{
    window_width = w;
    window_height = h;
}

void mainMenu(int i)
{
    keyboard((unsigned char) i, 0, 0);
}


////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void createFBO(GLuint* fbo, GLuint* tex, unsigned int size_x, unsigned int size_y)
{
	GLuint depth_rb;

	// get IDs for frame buffer, render buffer
	// and associated texture
	glGenFramebuffersEXT(1, fbo);
	glGenRenderbuffersEXT(1, &depth_rb);
	glGenTextures(1, tex);

	// bind created frame buffer
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, *fbo);

	// initialize texture used as render target
	glBindTexture(GL_TEXTURE_2D, *tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F_ARB, size_x, size_y, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexImage2D(GL_TEXTURE_2D, 0, TEXFMT_EXTERNAL, size_x, size_y, 0, TEXFMT_INTERNAL, TEXFMT_TYPE, NULL);

	// attach texture to frame buffer object
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, *tex, 0);

	// initialize depth render buffer
	glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depth_rb);
	glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, size_x, size_y);

	// attach depth buffer
	glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depth_rb);

	// check if created frame buffer is valid
	GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
	if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
	{
		fprintf(stderr, "Failed to create FBO!\n");
		exit(-1);
	}

	// unbind created frame buffer object
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
}

////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void deleteFBO(GLuint* fbo)
{
	GLuint objid;

	// bind frame buffer
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, *fbo);

	// delete depth attachment
	glGetFramebufferAttachmentParameterivEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT, (GLint*) &objid);
	glDeleteRenderbuffersEXT(1, (const GLuint*) &objid);

	// delete color attachment
	glGetFramebufferAttachmentParameterivEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT, (GLint*) &objid);
	glDeleteTextures(1, (const GLuint*) &objid);

	// delete frame buffer
	glDeleteFramebuffersEXT(1, fbo);
	*fbo = 0;

	CUT_CHECK_ERROR_GL();

	// bind default frame buffer
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
}

////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void
createTexture(GLuint* tex_name, unsigned int size_x, unsigned int size_y)
{
    // create a texture
    glGenTextures(1, tex_name);
    glBindTexture(GL_TEXTURE_2D, *tex_name);

    // set basic parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // buffer data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size_x, size_y, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    CUT_CHECK_ERROR_GL();
}

////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void
deleteTexture(GLuint* tex)
{
    glDeleteTextures(1, tex);
    CUT_CHECK_ERROR_GL();

    *tex = 0;
}

////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void
createDepthBuffer(GLuint* depth, unsigned int size_x, unsigned int size_y)
{
    // create a renderbuffer
    glGenRenderbuffersEXT(1, depth);
    glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, *depth);

    // allocate storage
    glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, size_x, size_y);

    // clean up
    glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);

    CUT_CHECK_ERROR_GL();
}

////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void
deleteDepthBuffer(GLuint* depth)
{
    glDeleteRenderbuffersEXT(1, depth);
    CUT_CHECK_ERROR_GL();

    *depth = 0;
}

////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void
createFramebuffer(GLuint* fbo, GLuint color, GLuint depth)
{
    // create and bind a framebuffer
    glGenFramebuffersEXT(1, fbo);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, *fbo);

    // attach images
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, color, 0);
    glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depth);

    // clean up
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    CUT_CHECK_ERROR_GL();
}

////////////////////////////////////////////////////////////////////////////////
//! 
////////////////////////////////////////////////////////////////////////////////
void
deleteFramebuffer( GLuint* fbo)
{
    glDeleteFramebuffersEXT(1, fbo);
    CUT_CHECK_ERROR_GL();

    *fbo = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main(int argc, char** argv)
{
    runTest(argc, argv);

    cutilExit(argc, argv);

    return EXIT_SUCCESS;
}

void cleanup()
{
	// unregister this buffer object with CUDA
//    cutilSafeCall(cudaGLUnregisterBufferObject(pbo_source));
//    cutilSafeCall(cudaGLUnregisterBufferObject(pbo_dest));

	cutilCheckError( cutDeleteTimer( timer));

	deletePBO(&pbo_source);
	deletePBO(&pbo_dest);

//	deleteFBO(&fbo_source);

	deleteTexture(&tex_screen);
    deleteDepthBuffer(&depth_buffer);
    deleteFramebuffer(&framebuffer);
}

// shader for displaying floating-point texture
static const char *shader_code = 
"!!ARBfp1.0\n"
"TEX result.color, fragment.texcoord, texture[0], 2D; \n"
"END";

GLuint compileASMShader(GLenum program_type, const char *code)
{
    GLuint program_id;
    glGenProgramsARB(1, &program_id);
    glBindProgramARB(program_type, program_id);
    glProgramStringARB(program_type, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei) strlen(code), (GLubyte *) code);

    GLint error_pos;
    glGetIntegerv(GL_PROGRAM_ERROR_POSITION_ARB, &error_pos);
    if (error_pos != -1) {
        const GLubyte *error_string;
        error_string = glGetString(GL_PROGRAM_ERROR_STRING_ARB);
        fprintf(stderr, "Program error at position: %d\n%s\n", (int)error_pos, error_string);
        return 0;
    }
    return program_id;
}

void initGLBuffers()
{
    // create pbo
    createPBO(&pbo_source);
    createPBO(&pbo_dest);

	// create fbo
//	createFBO(&fbo_source, &tex_source, image_width, image_height);

    // create texture for blitting onto the screen
    createTexture(&tex_screen, image_width, image_height);

    // create a depth buffer for offscreen rendering
    createDepthBuffer(&depth_buffer, image_width, image_height);

    // create a framebuffer for offscreen rendering
    createFramebuffer(&framebuffer, tex_screen, depth_buffer);

	// load shader program
    shader = compileASMShader(GL_FRAGMENT_PROGRAM_ARB, shader_code);
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runTest(int argc, char** argv)
{
    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    if( false == initGL(argc, argv)) {
        return;
    }

	// Now initialize CUDA context (GL context has been created already)
	initCUDA(argc, argv);

	if( !cutCheckCmdLineFlag(argc, (const char**)argv, "noqatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))
	{
        g_bQAReadback = true;
        animate = false;

		blur_radius = 2;
	}

    cutCreateTimer(&timer);
    cutResetTimer(timer);  

    // register callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    // create menu
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Toggle CUDA processing [ ]", ' ');
    glutAddMenuEntry("Toggle animation [a]", 'a');
    glutAddMenuEntry("Increment blur radius [=]", '=');
    glutAddMenuEntry("Decrement blur radius [-]", '-');
    glutAddMenuEntry("Quit (esc)", '\033');
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	initGLBuffers();

//	atexit(cleanup);

    // Creating the Auto-Validation Code
    if (g_bQAReadback) {
		if (g_bFBODisplay) {
			g_CheckRender = new CheckFBO(window_width, window_height, 4);
		} else {
			g_CheckRender = new CheckBackBuffer(window_width, window_height, 4);
		}
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);
    }

    // start rendering mainloop
    glutMainLoop();

    cudaThreadExit();
}

////////////////////////////////////////////////////////////////////////////////
//! Initialize CUDA context
////////////////////////////////////////////////////////////////////////////////
bool
initCUDA( int argc, char **argv )
{
    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
	    cutilGLDeviceInit(argc, argv);
    else {
        cudaGLSetGLDevice (cutGetMaxGflopsDeviceId() );
    }
	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Initialize GL
////////////////////////////////////////////////////////////////////////////////
bool
initGL(int argc, char **argv )
{
    // Create GL context
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("CUDA OpenGL post-processing");

    // initialize necessary OpenGL extensions
    glewInit();
    if (! glewIsSupported(
        "GL_VERSION_2_0 " 
        "GL_ARB_pixel_buffer_object "
        "GL_EXT_framebuffer_object "
		)) {
        fprintf(stderr, "ERROR: Support for necessary OpenGL extensions missing.");
        fflush(stderr);
        return CUTFalse;
    }

    // default initialization
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glDisable(GL_DEPTH_TEST);

    // viewport
    glViewport(0, 0, window_width, window_height);

    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)window_width / (GLfloat) window_height, 0.1, 10.0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_LIGHT0);
    float red[] = { 1.0, 0.1, 0.1, 1.0 };
    float white[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 60.0);

    CUT_CHECK_ERROR_GL();

    return CUTTrue;
}
