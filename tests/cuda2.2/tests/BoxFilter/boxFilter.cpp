/*
* Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
*
* NOTICE TO USER:
*
* This source code is subject to NVIDIA ownership rights under U.S. and
* international Copyright laws.
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
    Image box filtering example

    This sample uses CUDA to perform a simple box filter on an image
    and uses OpenGL to display the results.

    It processes rows and columns of the image in parallel.

    The box filter is implemented such that it has a constant cost,
    regardless of the filter width.

    Press '=' to increment the filter radius, '-' to decrease it

    Version 1.1 - modified to process 8-bit RGBA images
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/glew.h>

#if defined(__APPLE__) || defined(__MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cuda_runtime_api.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cuda_gl_interop.h>
#include <rendercheck_gl.h>

#define MAX_EPSILON_ERROR 5.0f

static char *sSDKsample = "CUDA Iterative Box Filter"; 

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "lena_10.ppm",
    "lena_14.ppm",
    "lena_18.ppm",
    "lena_22.ppm",
    NULL
};

const char *sReference[] =
{
    "ref_10.ppm",
    "ref_14.ppm",
    "ref_18.ppm",
    "ref_22.ppm",
    NULL
};

char *image_filename = "lena.ppm";
int iterations = 1;
int filter_radius = 10;
int nthreads = 32; //64;

unsigned int width, height;
unsigned int * h_img = NULL;
unsigned int * d_img = NULL;
unsigned int * d_temp = NULL;
//cudaArray* d_array, *d_tempArray;

GLuint pbo;     // OpenGL pixel buffer object
GLuint texid;   // texture
GLuint shader;

unsigned int timer = 0;

// Auto-Verification Code
const int frameCheckNumber = 4;
int fpsCount = 0;        // FPS count for averaging
int fpsLimit = 1;        // FPS limit for sampling
int g_Index = 0;
unsigned int frameCount = 0;
unsigned int g_TotalErrors = 0;
bool g_Verify = false;
bool g_bQAReadback = false;
bool g_bOpenGLQA   = false;
bool g_bFBODisplay = false;

// CheckFBO/BackBuffer class objects
CFrameBufferObject  *g_FrameBufferObject = NULL;
CheckRender         *g_CheckRender       = NULL;

//#define GL_TEXTURE_TYPE GL_TEXTURE_RECTANGLE_ARB
#define GL_TEXTURE_TYPE GL_TEXTURE_2D

#define MAX(a,b) ((a > b) ? a : b)


extern "C" void runAutoTest(int argc, char **argv);
extern "C" void loadImageData(int argc, char **argv);

extern "C" void computeGold(float *id, float *od, int w, int h, int n);

// These are CUDA functions to handle allocation and launching the kernels
extern "C" void initTexture(int width, int height, void *pImage);
extern "C" void freeTextures();

extern "C" void boxFilter(float *d_src, float *d_temp, float *d_dest, int width, int height,
                          int radius, int iterations, int nthreads);

extern "C" void boxFilterRGBA(unsigned int *d_src, unsigned int *d_temp, unsigned int *d_dest, 
                              int width, int height, int radius, int iterations, int nthreads);

void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "AutoTest: %s (radius=%d)", sSDKsample, filter_radius );
	    glutSetWindowTitle(temp);

        if (filter_radius >= 10) g_Index++;
        filter_radius += 4;

		if (filter_radius > 22) {
			printf("Summary: %d errors!\n", g_TotalErrors);
			printf("Test %s!\n", (g_TotalErrors==0) ? "PASSED" : "FAILED");
			exit(0);
		}
    }
}

void computeFPS()
{
    frameCount++;
    fpsCount++;
    if (fpsCount == fpsLimit-1) {
        g_Verify = true;
    }
    if (fpsCount == fpsLimit) {
        char fps[256];
        float ifps = 1.f / (cutGetAverageTimerValue(timer) / 1000.f);
        sprintf(fps, "%sCUDA Box Filter (radius=%d): %3.1f fps", 
                ((g_CheckRender && g_CheckRender->IsQAReadback()) ? "AutoTest: " : ""), filter_radius, ifps);  

        glutSetWindowTitle(fps);
        fpsCount = 0; 
        if (g_CheckRender && !g_CheckRender->IsQAReadback()) fpsLimit = (int)MAX(ifps, 1.f);

        cutilCheckError(cutResetTimer(timer));  

        AutoQATest();
    }
}

// display results using OpenGL
void display()
{
    cutilCheckError(cutStartTimer(timer));  

    // execute filter, writing results to pbo
    unsigned int *d_result;
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_result, pbo));
    boxFilterRGBA(d_img, d_temp, d_result, width, height, filter_radius, iterations, nthreads);
    cutilSafeCall(cudaGLUnmapBufferObject(pbo));

	if (g_bFBODisplay) {
		g_FrameBufferObject->bindRenderPath();
	}

    // Common display code path
	{
        glClear(GL_COLOR_BUFFER_BIT);

        // load texture from pbo
        glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
        glBindTexture(GL_TEXTURE_2D, texid);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

        // fragment program is required to display floating point texture
        glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, shader);
        glEnable(GL_FRAGMENT_PROGRAM_ARB);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_QUADS);
        if (GL_TEXTURE_TYPE == GL_TEXTURE_2D) {
            glTexCoord2f(0, 1);          glVertex2f(0, 0);
            glTexCoord2f(1, 1);          glVertex2f(1, 0);
            glTexCoord2f(1, 0);          glVertex2f(1, 1);
            glTexCoord2f(0, 0);          glVertex2f(0, 1);
        } else {
            glTexCoord2f(0    , height); glVertex2f(0, 0);
            glTexCoord2f(width, height); glVertex2f(1, 0);
            glTexCoord2f(width, 0     ); glVertex2f(1, 1);
            glTexCoord2f(0    , 0     ); glVertex2f(0, 1);
        }
        glEnd();
        glBindTexture(GL_TEXTURE_TYPE, 0);
        glDisable(GL_FRAGMENT_PROGRAM_ARB);
    }

	if (g_bFBODisplay) {
		g_FrameBufferObject->unbindRenderPath();

	}

    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        // readback for QA testing
 		if (g_bFBODisplay) {
            printf("> (Frame %d) Readback FBO\n", frameCount);
			g_CheckRender->readback( width, height, g_FrameBufferObject->getFbo() );
        } else {
            printf("> (Frame %d) Readback BackBuffer\n", frameCount);
            g_CheckRender->readback( width, height );
        }
        g_CheckRender->savePPM(sOriginal[g_Index], true, NULL);
        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, 0.15f)) {
            g_TotalErrors++;
        }
        g_Verify = false;
    }

	glutSwapBuffers();
    glutReportErrors();

    cutilCheckError(cutStopTimer(timer));  

    computeFPS();
}

void keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch(key) {
        case 27:
            exit(0);
            break;
        case '=':
        case '+':
            filter_radius++;
            break;
        case '-':
            if (filter_radius > 1) filter_radius--;
            break;
        case ']':
            iterations++;
            break;
        case '[':
            if (iterations>1) iterations--;
            break;
        default:
            break;
    }
    printf("radius = %d, iterations = %d\n", filter_radius, iterations);
    glutPostRedisplay();
}

void idle()
{
    glutPostRedisplay();
}

void reshape(int x, int y)
{
    glViewport(0, 0, x, y);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0); 
}

void initCuda()
{
    // allocate device memory
    cutilSafeCall( cudaMalloc( (void**) &d_img,  (width * height * sizeof(unsigned int)) ));
    cutilSafeCall( cudaMalloc( (void**) &d_temp, (width * height * sizeof(unsigned int)) ));

    // Refer to boxFilter_kernel.cu for implementation
    initTexture(width, height, h_img); 

    cutilCheckError( cutCreateTimer( &timer));
}

void cleanup()
{
    cutilCheckError( cutDeleteTimer( timer));
//    free(h_img);

    cutilSafeCall(cudaFree(d_img));
    cutilSafeCall(cudaFree(d_temp));

    // Refer to boxFilter_kernel.cu for implementation
    freeTextures();

	cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
	glDeleteBuffersARB(1, &pbo);
    glDeleteTextures(1, &texid);
    glDeleteProgramsARB(1, &shader);

    if (g_CheckRender) {
        delete g_CheckRender; g_CheckRender = NULL;
    }
    if (g_FrameBufferObject) {
        delete g_FrameBufferObject; g_FrameBufferObject = NULL;
    }
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

void initOpenGL()
{
    // create pixel buffer object
    glGenBuffersARB(1, &pbo);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
	glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, width*height*sizeof(GLubyte)*4, h_img, GL_STREAM_DRAW_ARB);

	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
	cutilSafeCall(cudaGLRegisterBufferObject(pbo));

    // create texture for display
    glGenTextures(1, &texid);
    glBindTexture(GL_TEXTURE_2D, texid);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    // load shader program
    shader = compileASMShader(GL_FRAGMENT_PROGRAM_ARB, shader_code);

	if (g_FrameBufferObject) {
		delete g_FrameBufferObject; g_FrameBufferObject = NULL;
	}
	if (g_bFBODisplay) {
		g_FrameBufferObject = new CFrameBufferObject(width, height, 32, true, GL_TEXTURE_2D);
	}
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runTest( int argc, char** argv) 
{
    // warm-up
    boxFilterRGBA(d_img, d_temp, d_temp, width, height, filter_radius, iterations, nthreads);

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStartTimer( timer));

    // execute the kernel
    boxFilterRGBA(d_img, d_temp, d_img, width, height, filter_radius, iterations, nthreads);

    // check if kernel execution generated an error
    cutilCheckMsg("Error: boxFilterRGBA Kernel execution failed!");

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStopTimer( timer));

    printf("Processing time: %f (ms)\n", cutGetTimerValue( timer));
	printf("%.2f Mpixels/sec\n", (width*height / (cutGetTimerValue( timer) / 1000.0f)) / 1e6);

    // allocate mem for the result on host side
    unsigned int size = width * height * sizeof(float);
    float* h_odata = (float*) malloc(size);
    // copy result from device to host
    cutilSafeCall( cudaMemcpy( h_odata, d_img, size, cudaMemcpyDeviceToHost) );

    cutilCheckError( cutSavePGMf( "data/output.pgm", h_odata, width, height));

    // compute reference solution
    float *h_odata_ref = (float*) malloc(size);
    cutilCheckError( cutStartTimer( timer));
//    computeGold(h_img, h_odata_ref, width, height, filter_radius);
    cutilCheckError( cutStopTimer( timer));
    printf("CPU Processing time: %f (ms)\n", cutGetTimerValue( timer));

    // check result
    if( cutCheckCmdLineFlag( argc, (const char**) argv, "regression")) 
    {
        // write file for regression test
        cutilCheckError( cutSavePGMf( "data/regression.pgm", h_odata, width, height));
        printf("Wrote 'regression.pgm'\n");
    }
    else 
    {
        // custom output handling when no regression test running
        // in this case check if the result is equivalent to the expected soluion
        CUTBoolean res = cutComparefe( h_odata, h_odata_ref, width*height, MAX_EPSILON_ERROR );
        printf( "Test %s\n", (1 == res) ? "PASSED" : "FAILED");
    }

    free(h_odata);
    free(h_odata_ref);
}

void initGL( int argc, char **argv )
{
    // initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("CUDA Box Filter");
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glewInit();
	if (g_bFBODisplay) {
        if (!glewIsSupported( "GL_VERSION_2_0 GL_ARB_fragment_program GL_EXT_framebuffer_object" )) {
            fprintf(stderr, "Error: failed to get minimal extensions for demo\n");
            fprintf(stderr, "This sample requires:\n");
            fprintf(stderr, "  OpenGL version 2.0\n");
            fprintf(stderr, "  GL_ARB_fragment_program\n");
            fprintf(stderr, "  GL_EXT_framebuffer_object\n");
            exit(-1);
        }
	} else {
		if (!glewIsSupported( "GL_VERSION_1_5 GL_ARB_vertex_buffer_object GL_ARB_pixel_buffer_object" )) {
			fprintf(stderr, "Error: failed to get minimal extensions for demo\n");
			fprintf(stderr, "This sample requires:\n");
			fprintf(stderr, "  OpenGL version 1.5\n");
			fprintf(stderr, "  GL_ARB_vertex_buffer_object\n");
			fprintf(stderr, "  GL_ARB_pixel_buffer_object\n");
			exit(-1);
		}
	}
}

void runAutoTest(int argc, char **argv)
{
    printf("[%s] (automated testing w/ readback)\n", sSDKsample);

    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
        cutilDeviceInit(argc, argv);
    } else {
        cudaSetDevice( cutGetMaxGflopsDeviceId() );
    }

    loadImageData(argc, argv);

    initCuda();

    g_CheckRender       = new CheckBackBuffer(width, height, 4, false);
    g_CheckRender->setExecPath(argv[0]);

    unsigned int *d_result;
    cutilSafeCall( cudaMalloc( (void **)&d_result, width*height*sizeof(unsigned int)) );

    while (filter_radius <= 22) 
    {
        printf("AutoTest: %s (radius=%d)", sSDKsample, filter_radius );
        boxFilterRGBA(d_img, d_temp, d_result, width, height, filter_radius, iterations, nthreads);

        // check if kernel execution generated an error
        cutilCheckMsg("Error: boxFilterRGBA Kernel execution failed!");
        cutilSafeCall( cudaThreadSynchronize() );

        cudaMemcpy(g_CheckRender->imageData(), d_result, width*height*sizeof(unsigned int), cudaMemcpyDeviceToHost);

        g_CheckRender->savePPM(sOriginal[g_Index], false, NULL);

        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, 0.15f)) {
            g_TotalErrors++;
        }
        g_Index++;
        filter_radius += 4;
    }

    cutilSafeCall( cudaFree( d_result ) );
    delete g_CheckRender;

    if (!g_TotalErrors) 
        printf("TEST PASSED!\n");
    else 
        printf("TEST FAILED!\n");
}


void loadImageData(int argc, char **argv)
{
    // load image (needed so we can get the width and height before we create the window
    char* image_path = cutFindFilePath(image_filename, argv[0]);
    if (image_path == 0) {
        fprintf(stderr, "Error finding image file '%s'\n", image_filename);
        exit(EXIT_FAILURE);
    }

    cutilCheckError( cutLoadPPM4ub(image_path, (unsigned char **) &h_img, &width, &height));
    if (!h_img) {
        printf("Error opening file '%s'\n", image_path);
        exit(-1);
    }
    printf("Loaded '%s', %d x %d pixels\n", image_path, width, height);
}



////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    cutGetCmdLineArgumenti( argc, (const char**) argv, "threads", &nthreads );
    cutGetCmdLineArgumenti( argc, (const char**) argv, "radius", &filter_radius);

    if (!cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
	{
        g_bQAReadback = true;
        fpsLimit = frameCheckNumber;
    }
    if (cutCheckCmdLineFlag(argc, (const char **)argv, "glverify"))
	{
        g_bOpenGLQA = true;
        fpsLimit = frameCheckNumber;
    }
    if (cutCheckCmdLineFlag(argc, (const char **)argv, "fbo")) {
        g_bFBODisplay = true;
    }

    if (g_bQAReadback) {
        runAutoTest(argc, argv);
        cutilExit(argc, argv);
        exit(0);
    } else {
        printf("[%s] ", sSDKsample);
        if (g_bFBODisplay) printf("[FBO Display] ");
        if (g_bOpenGLQA)   printf("[OpenGL Readback Comparisons] ");
        printf("\n");

        loadImageData(argc, argv);

        // First initialize OpenGL context, so we can properly set the GL for CUDA.
        // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
        initGL( argc, argv );

        if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
	        cutilGLDeviceInit(argc, argv);
        else {
            cudaGLSetGLDevice (cutGetMaxGflopsDeviceId() );
        }
        initCuda();
        initOpenGL();

        if (g_bOpenGLQA) {
            if (g_bFBODisplay) {
                g_CheckRender = new CheckFBO(width, height, 4, g_FrameBufferObject);
            } else {
                g_CheckRender = new CheckBackBuffer(width, height, 4);
            }
            g_CheckRender->setPixelFormat(GL_RGBA);
            g_CheckRender->setExecPath(argv[0]);
            g_CheckRender->EnableQAReadback(true);
        }
    }

    printf("Press '+' and '-' to change filter width\n"
           "Press ']' and '[' to change number of iterations\n");
    fflush(stdout);

    atexit(cleanup);

//    runTest( argc, argv);
    glutMainLoop();

    cudaThreadExit();

    cutilExit(argc, argv);
}
