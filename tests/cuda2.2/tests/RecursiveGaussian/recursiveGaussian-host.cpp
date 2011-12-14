/*
* Copyright 1993-2008 NVIDIA Corporation.  All rights reserved.
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
    Recursive Gaussian filter
    sgreen 8/1/08

    This code sample implements a Gaussian blur using Deriche's recursive method:
    http://citeseer.ist.psu.edu/deriche93recursively.html

    This is similar to the box filter sample in the SDK, but it uses the previous
    outputs of the filter as well as the previous inputs. This is also known as an
    IIR (infinite impulse response) filter, since its response to an input impulse
    can last forever.

    The main advantage of this method is that the execution time is independent of
    the filter width.
    
    The GPU processes columns of the image in parallel. To avoid uncoalesced reads
    for the row pass we transpose the image and then transpose it back again
    afterwards.

    The implementation is based on code from the CImg library:
    http://cimg.sourceforge.net/
    Thanks to David Tschumperlé and all the CImg contributors!
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/glew.h>

#if defined (__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cuda_gl_interop.h>
#include <rendercheck_gl.h>

#define MAX(a,b) ((a > b) ? a : b)

#define USE_SIMPLE_FILTER 0

#define MAX_EPSILON_ERROR 5.0f

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
float sigma = 10.0f;
int order = 0;
int nthreads = 64;	// number of threads per block

unsigned int width, height;
unsigned int* h_img = NULL;
unsigned int* d_img = NULL;
unsigned int* d_temp = NULL;

GLuint pbo = 0;     // OpenGL pixel buffer object
GLuint texid = 0;   // texture

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

// CheckFBO/BackBuffer class objects
CheckRender       *g_CheckRender = NULL;

CUTBoolean runBenchmark = CUTFalse;

const char *sSDKsample = "CUDA Recursive Gaussian";

extern "C" 
void transpose(unsigned int *d_src, unsigned int *d_dest, unsigned int width, int height);

extern "C" 
void gaussianFilterRGBA(unsigned int *d_src, unsigned int *d_dest, unsigned int *d_temp, int width, int height, float sigma, int order, int nthreads);


void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char fps[256];
        float ifps = 1.f / (cutGetAverageTimerValue(timer) / 1000.f);
        sprintf(fps, "%s %s (sigma=%4.2f): %3.1f fps", sSDKsample,
                ((g_CheckRender && g_CheckRender->IsQAReadback()) ? "AutoTest: " : ""), sigma, ifps);  

	    glutSetWindowTitle(fps);

        g_Index++;
        sigma += 4;

		if (sigma > 22) {
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
        sprintf(fps, "%s %s (sigma=%4.2f): %3.1f fps", sSDKsample,
                ((g_CheckRender && g_CheckRender->IsQAReadback()) ? "AutoTest: " : ""), sigma, ifps);  

        glutSetWindowTitle(fps);
        fpsCount = 0; 
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
    gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order, nthreads);
    cutilSafeCall(cudaGLUnmapBufferObject(pbo));

    // load texture from pbo
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glBindTexture(GL_TEXTURE_2D, texid);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    // display results
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(0, 0);
    glTexCoord2f(1, 1); glVertex2f(1, 0);
    glTexCoord2f(1, 0); glVertex2f(1, 1);
    glTexCoord2f(0, 0); glVertex2f(0, 1);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        // readback for QA testing
        printf("> (Frame %d) Readback BackBuffer\n", frameCount);
        g_CheckRender->readback( width, height );
        g_CheckRender->savePPM(sOriginal[g_Index], true, NULL);
        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, 0.50f )) {
            g_TotalErrors++;
        }
        g_Verify = false;
    }

    glutSwapBuffers();

    cutilCheckError(cutStopTimer(timer));  

    computeFPS();
}

void idle()
{
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 27:
            exit(0);
            break;
            
        case '=':
            sigma+=0.1f;
            break;
        case '-':
            sigma-=0.1f;
            if (sigma < 0.0) sigma = 0.0f;
            break;
            
        case '+':
			sigma+=1.0f;
			break;
		case '_':
			sigma-=1.0f;
			if (sigma < 0.0) sigma = 0.0f;
			break;
        
        case '0':
            order = 0;
            break;
        case '1':
            order = 1;
            sigma = 0.5f;
            break;
        case '2':
            order = 2;
            sigma = 0.5f;
            break;

        default:
            break;
    }
    printf("sigma = %f\n", sigma);
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

void initCudaBuffers()
{
    unsigned int size = width * height * sizeof(unsigned int);

    // allocate device memory
    cutilSafeCall( cudaMalloc( (void**) &d_img, size));
    cutilSafeCall( cudaMalloc( (void**) &d_temp, size));

    cutilSafeCall( cudaMemcpy( d_img, h_img, size, cudaMemcpyHostToDevice));

    cutilCheckError( cutCreateTimer( &timer));
}

void cleanup()
{
    cutilCheckError( cutDeleteTimer( timer));
    if (!h_img) {
	    free(h_img);
	}

    cutilSafeCall(cudaFree(d_img));
    cutilSafeCall(cudaFree(d_temp));

    if (!runBenchmark) {
        if (pbo) {
            cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
            glDeleteBuffersARB(1, &pbo);
        }
        if (texid) {
            glDeleteTextures(1, &texid);
        }
    }

    if (g_CheckRender) {
        delete g_CheckRender; g_CheckRender = NULL;
    }
}


void initGLBuffers()
{
    // create pixel buffer object to store final image
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
}

void initGL(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow(sSDKsample);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    printf("Press '+' and '-' to change filter width\n");
    printf("0, 1, 2 - change filter order\n");

    glewInit();
    if (!glewIsSupported("GL_VERSION_2_0 GL_ARB_vertex_buffer_object GL_ARB_pixel_buffer_object")) {
        fprintf(stderr, "Required OpenGL extensions missing.");
        cudaThreadExit();
        exit(-1);
    }
}

void
benchmark(int iterations) 
{
    // allocate memory for result
    unsigned int *d_result;
    unsigned int size = width * height * sizeof(unsigned int);
    cutilSafeCall( cudaMalloc( (void**) &d_result, size));

    // warm-up
    gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order, nthreads);

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStartTimer( timer));

    // execute the kernel
    for(int i=0; i<iterations; i++) {
        gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order, nthreads);
    }

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStopTimer( timer));

    // check if kernel execution generated an error
    cutilCheckMsg("Kernel execution failed");

    printf("Processing time: %f (ms)\n", cutGetTimerValue( timer));
    printf("%.2f Mpixels/sec\n", (width*height*iterations / (cutGetTimerValue( timer) / 1000.0f)) / 1e6);

    cutilSafeCall(cudaFree(d_result));
}

void
runAutoTest(int argc, char **argv) 
{
    // allocate memory for result
    unsigned int *d_result;
    unsigned int size = width * height * sizeof(unsigned int);
    cutilSafeCall( cudaMalloc( (void**) &d_result, size));

    // warm-up
    gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order, nthreads);

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStartTimer( timer));
    
    while (sigma <= 22) {    
        gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order, nthreads);
        cutilSafeCall( cudaThreadSynchronize() );
        // check if kernel execution generated an error
        cutilCheckMsg("Kernel execution failed");

        cudaMemcpy(g_CheckRender->imageData(), d_result, width*height*4, cudaMemcpyDeviceToHost);
        g_CheckRender->savePPM(sOriginal[g_Index], false, NULL);
        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, 0.50f)) {
            g_TotalErrors++;
        }
        g_Index++;
        sigma += 4;
    }

    cutilCheckError( cutStopTimer( timer));

    printf("Processing time: %f (ms)\n", cutGetTimerValue( timer));
    printf("%.2f Mpixels/sec\n", (width*height*g_Index / (cutGetTimerValue( timer) / 1000.0f)) / 1e6);

    printf("Summary: %d errors!\n", g_TotalErrors);
	printf("Test %s!\n", (g_TotalErrors==0) ? "PASSED" : "FAILED");
    

    cutilSafeCall(cudaFree(d_result));
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if (!cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
	{
        g_bQAReadback = true;
        fpsLimit = frameCheckNumber;
    }
    if (argc > 1) {

        if (cutCheckCmdLineFlag(argc, (const char **)argv, "glverify")) {
            g_bOpenGLQA = true;
            fpsLimit = frameCheckNumber;
        }
    }

    printf("[%s] ", sSDKsample);
    if (g_bQAReadback) printf("(Automated Testing)\n");
    if (g_bOpenGLQA)   printf("(OpenGL Readback)\n");

    // Get the path of the filename
    char *filename;
    if (cutGetCmdLineArgumentstr(argc, (const char**) argv, "image", &filename)) {
        image_filename = filename;
    }
    // load image
    char* image_path = cutFindFilePath(image_filename, argv[0]);
    if (image_path == 0) {
        fprintf(stderr, "Error finding image file '%s'\n", image_filename);
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }

    cutilCheckError( cutLoadPPM4ub(image_path, (unsigned char **) &h_img, &width, &height));
    if (!h_img) {
        printf("Error opening file '%s'\n", image_path);
        cudaThreadExit();
        exit(-1);
    }
    printf("Loaded '%s', %d x %d pixels\n", image_path, width, height);

    cutGetCmdLineArgumenti(argc, (const char**) argv, "threads", &nthreads);
    cutGetCmdLineArgumentf(argc, (const char**) argv, "sigma", &sigma);
    runBenchmark = cutCheckCmdLineFlag(argc, (const char**) argv, "bench");

    int device;
    struct cudaDeviceProp prop;
    cudaGetDevice( &device );
    cudaGetDeviceProperties( &prop, device );
    if( !strncmp( "Tesla", prop.name, 5 ) ) {
        printf("Tesla card detected, running the test in benchmark mode (no OpenGL display)\n");
//        runBenchmark = CUTTrue;
        g_bQAReadback = true;
    }        

    // Benchmark or AutoTest mode detected, no OpenGL
    if (runBenchmark == CUTTrue || g_bQAReadback) {
        if( cutCheckCmdLineFlag( argc, (const char **)argv, "device" ) ) 
            cutilDeviceInit( argc, argv );
        else 
            cudaSetDevice( cutGetMaxGflopsDeviceId() );
    } else {

        // First initialize OpenGL context, so we can properly set the GL for CUDA.
        // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
        initGL(argc, argv);

        if( cutCheckCmdLineFlag( argc, (const char **)argv, "device" ) ) 
            cutilGLDeviceInit( argc, argv );
        else 
            cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
    }

    initCudaBuffers();

    if (g_bOpenGLQA) {
        g_CheckRender = new CheckBackBuffer(width, height, 4);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);
    }

    if (g_bQAReadback) {
        // This is the automated testing path
        g_CheckRender = new CheckBackBuffer(width, height, 4, false);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);

        runAutoTest(argc, argv); 
        cleanup();
        cudaThreadExit();
        cutilExit(argc, argv);
    }

    if (runBenchmark) {
        benchmark(100);
        cleanup();
        cudaThreadExit();
        exit(0);
    }

    initGLBuffers();
    
    atexit(cleanup);
    
    glutMainLoop();

    cudaThreadExit();
    cutilExit(argc, argv);
}
