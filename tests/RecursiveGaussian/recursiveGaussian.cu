/*
* Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
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

#include <cuda_gl_interop.h>
#include <cutil_inline.h>

#include "recursiveGaussian_kernel.cu"

#define USE_SIMPLE_FILTER 0

char *image_filename = "lena.ppm";
float sigma = 10.0f;
int order = 0;
int nthreads = 64;	// number of threads per block

unsigned int width, height;
uint* h_img = NULL;
uint* d_img = NULL;
uint* d_temp = NULL;

GLuint pbo = 0;     // OpenGL pixel buffer object
GLuint texid = 0;   // texture

unsigned int timer = 0;
int fpsCount = 0;        // FPS count for averaging
int fpsLimit = 1;        // FPS limit for sampling

//Round a / b to nearest higher integer value
int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

/*
    Transpose a 2D array (see SDK transpose example)
*/
void transpose(uint *d_src, uint *d_dest, uint width, int height)
{
    dim3 grid(iDivUp(width, BLOCK_DIM), iDivUp(height, BLOCK_DIM), 1);
    dim3 threads(BLOCK_DIM, BLOCK_DIM, 1);
    d_transpose<<< grid, threads >>>(d_dest, d_src, width, height);
    cutilCheckMsg("Kernel execution failed");
}

/*
    Perform Gaussian filter on a 2D image using CUDA

    Parameters:
    d_src  - pointer to input image in device memory
    d_dest - pointer to destination image in device memory
    d_temp - pointer to temporary storage in device memory
    width  - image width
    height - image height
    sigma  - sigma of Gaussian
    order  - filter order (0, 1 or 2)
*/

// 8-bit RGBA version
void gaussianFilterRGBA(uint *d_src, uint *d_dest, uint *d_temp, int width, int height, float sigma, int order)
{
    const float
        nsigma = sigma < 0.1f ? 0.1f : sigma,
        alpha = 1.695f / nsigma,
        ema = (float)std::exp(-alpha),
        ema2 = (float)std::exp(-2*alpha),
        b1 = -2*ema,
        b2 = ema2;

    float a0 = 0, a1 = 0, a2 = 0, a3 = 0, coefp = 0, coefn = 0;
    switch (order) {
    case 0: {
        const float k = (1-ema)*(1-ema)/(1+2*alpha*ema-ema2);
        a0 = k;
        a1 = k*(alpha-1)*ema;
        a2 = k*(alpha+1)*ema;
        a3 = -k*ema2;
    } break;

    case 1: {
        const float k = (1-ema)*(1-ema)/ema;
        a0 = k*ema;
        a1 = a3 = 0;
        a2 = -a0;
    } break;

    case 2: {
        const float
            ea = (float)std::exp(-alpha),
            k = -(ema2-1)/(2*alpha*ema),
            kn = (-2*(-1+3*ea-3*ea*ea+ea*ea*ea)/(3*ea+1+3*ea*ea+ea*ea*ea));
        a0 = kn;
        a1 = -kn*(1+k*alpha)*ema;
        a2 = kn*(1-k*alpha)*ema;
        a3 = -kn*ema2;
    } break;

    default:
        fprintf(stderr, "gaussianFilter: invalid order parameter!\n");
        return;
    }
    coefp = (a0+a1)/(1+b1+b2);
    coefn = (a2+a3)/(1+b1+b2);

    // process columns
#if USE_SIMPLE_FILTER
    d_simpleRecursive_rgba<<< iDivUp(width, nthreads), nthreads >>>(d_src, d_temp, width, height, ema);
#else
    d_recursiveGaussian_rgba<<< iDivUp(width, nthreads), nthreads >>>(d_src, d_temp, width, height, a0, a1, a2, a3, b1, b2, coefp, coefn);
#endif
    cutilCheckMsg("Kernel execution failed");

    transpose(d_temp, d_dest, width, height);
    cutilCheckMsg("transpose: Kernel execution failed");

    // process rows
#if USE_SIMPLE_FILTER
    d_simpleRecursive_rgba<<< iDivUp(height, nthreads), nthreads >>>(d_dest, d_temp, height, width, ema);
#else
    d_recursiveGaussian_rgba<<< iDivUp(height, nthreads), nthreads >>>(d_dest, d_temp, height, width, a0, a1, a2, a3, b1, b2, coefp, coefn);
#endif
    cutilCheckMsg("Kernel execution failed");

    transpose(d_temp, d_dest, height, width);
}

// display results using OpenGL
void display()
{
    cutilCheckError(cutStartTimer(timer));  

    // execute filter, writing results to pbo
    uint *d_result;
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_result, pbo));
    gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order);
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
    glVertex2f(0, 0); glTexCoord2f(0, 0);
    glVertex2f(0, 1); glTexCoord2f(1, 0);
    glVertex2f(1, 1); glTexCoord2f(1, 1);
    glVertex2f(1, 0); glTexCoord2f(0, 1);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();

    cutilCheckError(cutStopTimer(timer));  

    fpsCount++;
    if (fpsCount == fpsLimit) {
        char fps[256];
        float ifps = 1.f / (cutGetAverageTimerValue(timer) / 1000.f);
        sprintf(fps, "CUDA Recursive Gaussian filter: %3.1f fps", ifps);
        glutSetWindowTitle(fps);
        fpsCount = 0; 
        fpsLimit = (int)max(ifps, 1.f);
        cutilCheckError(cutResetTimer(timer));  
    }
}

void idle()
{
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 27:
//            cudaThreadExit();
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

void initCuda()
{
    unsigned int size = width * height * sizeof(uint);

    // allocate device memory
    cutilSafeCall( cudaMalloc( (void**) &d_img, size));
    cutilSafeCall( cudaMalloc( (void**) &d_temp, size));

    cutilSafeCall( cudaMemcpy( d_img, h_img, size, cudaMemcpyHostToDevice));

    cutilCheckError( cutCreateTimer( &timer));
}

void cleanup()
{
    cutilCheckError( cutDeleteTimer( timer));
    free(h_img);

    cutilSafeCall(cudaFree(d_img));
    cutilSafeCall(cudaFree(d_temp));

    if (pbo) {
        cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
        glDeleteBuffersARB(1, &pbo);
    }
    if (texid) {
        glDeleteTextures(1, &texid);
    }
}

void initOpenGL()
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

void
benchmark(int iterations) 
{
    // allocate memory for result
    uint *d_result;
    unsigned int size = width * height * sizeof(uint);
    cutilSafeCall( cudaMalloc( (void**) &d_result, size));

    // warm-up
    gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order);

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStartTimer( timer));

    // execute the kernel
    for(int i=0; i<iterations; i++) {
        gaussianFilterRGBA(d_img, d_result, d_temp, width, height, sigma, order);
    }

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStopTimer( timer));

    // check if kernel execution generated an error
    cutilCheckMsg("Kernel execution failed");

    printf("Processing time: %f (ms)\n", cutGetTimerValue( timer));
    printf("%.2f Mpixels/sec\n", (width*height*iterations / (cutGetTimerValue( timer) / 1000.0f)) / 1e6);
    printf("Test PASSED\n");

    cutilSafeCall(cudaFree(d_result));
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{

    if( cutCheckCmdLineFlag( argc, (const char **)argv, "device" ) ) 
        cutilDeviceInit( argc, argv );
    else 
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    int device;
    struct cudaDeviceProp prop;
    cudaGetDevice( &device );
    cudaGetDeviceProperties( &prop, device );
    if( !strncmp( "Tesla", prop.name, 5 ) ){
        printf("This sample needs a card capable of OpenGL and display.\n");
        printf("Please choose a different device with the -device=x argument.\n");
        cudaThreadExit();
        cutilExit(argc, argv);
    }        

    char *filename;
    if (cutGetCmdLineArgumentstr(argc, (const char**) argv, "image", &filename)) {
        image_filename = filename;
    }
    cutGetCmdLineArgumenti(argc, (const char**) argv, "threads", &nthreads);
    cutGetCmdLineArgumentf(argc, (const char**) argv, "sigma", &sigma);
    bool runBenchmark = !cutCheckCmdLineFlag(argc, (const char**) argv, "nobench");

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

    initCuda();

    if (runBenchmark) {
        benchmark(1);
        cleanup();
//        cudaThreadExit();
        exit(0);
    }

    // initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("CUDA Recursive Gaussian filter");
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
    initOpenGL();

    atexit(cleanup);

    glutMainLoop();

    cudaThreadExit();
    return 0;
}
