/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

/*
    Image bilateral filtering example

    This sample uses CUDA to perform a simple bilateral filter on an image
    and uses OpenGL to display the results.

    Bilateral filter is an edge-preserving nonlinear smoothing filter. There 
    are three parameters distribute to the filter: gaussian delta, euclidean 
    delta and iterations.

    When the euclidean delta increases, most of the fine texture will be
    filtered away, yet all contours are as crisp as in the original image.
    If the euclidean delta approximates to ∞, the filter becomes a normal
    gaussian filter. Fine texture will blur more with larger gaussian delta.
    Multiple iterations have the effect of flattening the colors in an 
    image considerably, but without blurring edges, which produces a cartoon
    effect.

    To learn more details about this filter, please view C. Tomasi's "Bilateral
    Filtering for Gray and Color Images".

*/

#include <math.h>

// OpenGL Graphics includes
#include <GL/glew.h>
#if defined(__APPLE__) || defined(__MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

// CUDA utilities and system includes
#include <cutil_inline.h>    // includes cuda.h and cuda_runtime_api.h
#include <cutil_gl_inline.h> // includes cuda_gl_interop.h// includes cuda_gl_interop.h
#include <rendercheck_gl.h>

// Shared Library Test Functions
#include <shrUtils.h>
#include <shrQATest.h>

#define MAX_EPSILON_ERROR	5.0f
#define REFRESH_DELAY		10 //ms

const static char *sSDKsample = "CUDA Bilateral Filter"; 

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "nature_1.ppm",
    "nature_2.ppm",
    "nature_3.ppm",
    "nature_4.ppm",
    NULL
};

const char *sReference[] =
{
    "ref_1.ppm",
    "ref_2.ppm",
    "ref_3.ppm",
    "ref_4.ppm",
    NULL
};

const char *image_filename = "nature_monte.bmp";
int iterations = 1;
float gaussian_delta = 4;
float euclidean_delta = 0.1f;
int filter_radius = 5;
int nthreads = 64;

unsigned int width, height;
unsigned int * h_img = NULL;
unsigned int * h_temp = NULL;
unsigned int * d_img = NULL;

GLuint pbo;     // OpenGL pixel buffer object
struct cudaGraphicsResource *cuda_pbo_resource; // handles OpenGL-CUDA exchange
GLuint texid;   // texture
GLuint shader;

unsigned int timer = 0;
int type = 2; // by default we make it use the bilateral filtering path

// Auto-Verification Code
const int frameCheckNumber = 4;
int fpsCount = 0;        // FPS count for averaging
int fpsLimit = 1;        // FPS limit for sampling
unsigned int g_TotalErrors = 0;

// CheckFBO/BackBuffer class objects
CFrameBufferObject  *g_FrameBufferObject = NULL;
CheckRender         *g_CheckRender       = NULL;

//#define GL_TEXTURE_TYPE GL_TEXTURE_RECTANGLE_ARB
#define GL_TEXTURE_TYPE GL_TEXTURE_2D

extern "C" void loadImageData(int argc, char **argv);

// These are CUDA functions to handle allocation and launching the kernels
extern "C" void initTexture(int width, int height, void *pImage);
extern "C" void freeTextures();

extern "C" double bilateralFilterRGBA(unsigned int *d_dest,
                                      int width, int height, 
                                      float e_d, int radius, int iterations,
                                      int nthreads);
extern "C"
void copyImage(unsigned int *h_src, unsigned int *d_dest,
               int width, int height);
extern "C" void updateGaussian(float delta, int radius);
extern "C" void updateGaussianGold(float delta, int radius);
extern "C" void bilateralFilterGold(unsigned int* pSrc, unsigned int* pDest,
                                    float e_d, int w, int h, int r);
extern "C" void LoadBMPFile(uchar4 **dst, unsigned int *width, 
                            unsigned int *height, const char *name);
void computeFPS()
{
    fpsCount++;

    if (fpsCount == fpsLimit) {
        char fps[256];
        float ifps = 1.0f / (cutGetAverageTimerValue(timer) / 1000.0f);
        sprintf(fps, "CUDA Bilateral Filter: %3.f fps (euclidean_delta=%.2f, gaussian_delta=%.2f, iterations=%.2f)", 
                ifps, (double)euclidean_delta, (double)gaussian_delta, (double)iterations);

        glutSetWindowTitle(fps);
        fpsCount = 0; 
        fpsLimit = (int)MAX(ifps, 1.0f);

        cutilCheckError(cutResetTimer(timer));  
    }
}

void runSelect(unsigned int * d_result)
{
    switch(type)
    {
    case 1:
        copyImage(h_img, d_result, width, height);
        break;
    case 2:
        bilateralFilterRGBA(d_result, width, height, euclidean_delta, filter_radius, iterations, nthreads);
        //bilateralFilterGold(h_img, h_temp, euclidean_delta, width, height, filter_radius);
        //copyImage(h_temp, d_result, width, height);
        break;
    default:
        break;
    }
}

// display results using OpenGL
void display()
{
    cutilCheckError(cutStartTimer(timer));  

    // execute filter, writing results to pbo
    unsigned int *d_result;
    //DEPRECATED: cutilSafeCall( cudaGLMapBufferObject((void**)&d_result, pbo) );
    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_resource, 0));
    size_t num_bytes; 
    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void **)&d_result, &num_bytes,  
						       cuda_pbo_resource));
    
    runSelect(d_result);
    // DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(pbo));
    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_pbo_resource, 0));

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
        {
            glTexCoord2f(0, 0);          
            glVertex2f(0, 0);
            glTexCoord2f(1, 0);          
            glVertex2f(1, 0);
            glTexCoord2f(1, 1);          
            glVertex2f(1, 1);
            glTexCoord2f(0, 1);          
            glVertex2f(0, 1);
        }
        glEnd();
        glBindTexture(GL_TEXTURE_TYPE, 0);
        glDisable(GL_FRAGMENT_PROGRAM_ARB);
    }

	glutSwapBuffers();
    glutReportErrors();

    cutilCheckError(cutStopTimer(timer));  

    computeFPS();
}

/*
    right arrow to increase the gaussian delta 
    left arrow to decrease the gaussian delta
    up arrow to increase the euclidean delta
    down arrow to decrease the euclidean delta
*/
void specialKey(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_RIGHT:
        euclidean_delta *= 1.5;
        break;
    case GLUT_KEY_LEFT:
        euclidean_delta /= 1.5;
        break;
    case GLUT_KEY_DOWN:
        if(gaussian_delta > 0.1)
            gaussian_delta /= 2;
        //updateGaussianGold(gaussian_delta, filter_radius);
        updateGaussian(gaussian_delta, filter_radius);
        break;
    case GLUT_KEY_UP:
        gaussian_delta *= 2;
        //updateGaussianGold(gaussian_delta, filter_radius);
        updateGaussian(gaussian_delta, filter_radius);
        break;
    default:
        break;
    }
	printf("gaussian delta = %.2f, euclidean delta = %.2f, iterations = %d\n", 
		gaussian_delta, euclidean_delta, iterations);
}

void keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch(key) {
        case 27:
            exit(0);
            break;

        case '1':
            type = 1;
            printf("No Filtering\n");
            break;
        case '2':
            type = 2;
            printf("Bilateral Filtering\n");
            break;
        case '3':
            type = 3;
            break;
        case '=':
        case '+': 
            iterations++;
            break;
        case '-':
            iterations--;
            if(iterations < 1)
                iterations = 1;
            break;
        default:
            break;
    }
    printf("gaussian delta = %.2f, euclidean delta = %.2f, iterations = %d\n", 
        gaussian_delta, euclidean_delta, iterations);
}

void timerEvent(int value)
{
    glutPostRedisplay();
	glutTimerFunc(REFRESH_DELAY, timerEvent,0);
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

    //initialize gaussian mask
    //updateGaussianGold(gaussian_delta, filter_radius);
    updateGaussian(gaussian_delta, filter_radius);

    initTexture(width, height, h_img); 
    cutilCheckError( cutCreateTimer( &timer));
}

void cleanup()
{
    cutilCheckError( cutDeleteTimer( timer));
    if(h_img)free(h_img);
    cutilSafeCall(cudaFree(d_img));

    delete[] h_temp;

    freeTextures();

    //DEPRECATED: cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
    cudaGraphicsUnregisterResource(cuda_pbo_resource);

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
        printf("Program error at position: %d\n%s\n", (int)error_pos, error_string);
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
    // DEPRECATED: cutilSafeCall(cudaGLRegisterBufferObject(pbo));
    cutilSafeCall(cudaGraphicsGLRegisterBuffer(&cuda_pbo_resource, pbo, 
					       cudaGraphicsMapFlagsWriteDiscard));
    
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
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple benchmark test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runBenchmark( int argc, char ** argv ) 
{
    int devID = 0;
    shrLog("[runBenchmark]: [%s]\n", sSDKsample);

    devID = cutilChooseCudaDevice(argc, argv);

    loadImageData(argc, argv);
    initCuda();

    g_CheckRender       = new CheckBackBuffer(width, height, 4, false);
    g_CheckRender->setExecPath(argv[0]);

    unsigned int *d_result;
    cutilSafeCall( cudaMalloc( (void **)&d_result, width*height*sizeof(unsigned int)) );

    // warm-up
    bilateralFilterRGBA(d_img, width, height, euclidean_delta, filter_radius, iterations, nthreads);
    cutilSafeCall( cutilDeviceSynchronize() );

	// Start round-trip timer and process iCycles loops on the GPU
    iterations = 1;     // standard 1-pass filtering
    const int iCycles = 150;
    double dProcessingTime = 0.0;
    shrLog("\nRunning BilateralFilterGPU for %d cycles...\n\n", iCycles);
	shrDeltaT(2);
    for (int i = 0; i < iCycles; i++)
    {
        dProcessingTime += bilateralFilterRGBA(d_img, width, height, euclidean_delta, filter_radius, iterations, nthreads);
    }

    // check if kernel execution generated an error and sync host
    cutilCheckMsg("Error: bilateralFilterRGBA Kernel execution FAILED");
    cutilSafeCall(cutilDeviceSynchronize());

    // Get average computation time
    dProcessingTime /= (double)iCycles;

    // log testname, throughput, timing and config info to sample and master logs
    shrLogEx(LOGBOTH | MASTER, 0, "bilateralFilter-texture, Throughput = %.4f M RGBA Pixels/s, Time = %.5f s, Size = %u RGBA Pixels, NumDevsUsed = %u, Workgroup = %u\n", 
                                  (1.0e-6 * width * height)/dProcessingTime, dProcessingTime, 
                                  (width * height), 1, nthreads); 
    shrLog("\n");
}

void initGL( int argc, char **argv )
{
    // initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);

    glutCreateWindow("CUDA Bilateral Filter");
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutReshapeFunc(reshape);
    //glutIdleFunc(idle);
	glutTimerFunc(REFRESH_DELAY, timerEvent, 0);

    glewInit();
	if (!glewIsSupported( "GL_VERSION_1_5 GL_ARB_vertex_buffer_object GL_ARB_pixel_buffer_object" ))
    {
		printf("Error: failed to get minimal extensions for demo\n");
		printf("This sample requires:\n");
		printf("  OpenGL version 1.5\n");
		printf("  GL_ARB_vertex_buffer_object\n");
		printf("  GL_ARB_pixel_buffer_object\n");
		exit(-1);
	}
}

void runAutoTest(int argc, char **argv)
{
    int devID = 0;
    shrLog("[runAutoTest]: [%s] (automated testing w/ readback)\n", sSDKsample);

    devID = cutilChooseCudaDevice(argc, argv);

    loadImageData(argc, argv);

    initCuda();

    g_CheckRender       = new CheckBackBuffer(width, height, 4, false);
    g_CheckRender->setExecPath(argv[0]);

    unsigned int *d_result;
    cutilSafeCall( cudaMalloc( (void **)&d_result, width*height*sizeof(unsigned int)) );

    for(int i = 0; i < 4; i++)
    {
        shrLog("[AutoTest]: %s (radius=%d)", sSDKsample, filter_radius );
        bilateralFilterRGBA(d_result, width, height, euclidean_delta, filter_radius, iterations, nthreads);

        // check if kernel execution generated an error
        cutilCheckMsg("Error: bilateralFilterRGBA Kernel execution FAILED");
        cutilSafeCall( cutilDeviceSynchronize() );
        cudaMemcpy(g_CheckRender->imageData(), d_result, width*height*sizeof(unsigned int), cudaMemcpyDeviceToHost);

        g_CheckRender->savePPM(sOriginal[i], false, NULL);

        if (!g_CheckRender->PPMvsPPM(sOriginal[i], sReference[i], MAX_EPSILON_ERROR, 0.15f)) {
            g_TotalErrors++;
        }
        gaussian_delta += 1.0f;
        euclidean_delta *= 1.25f;

		updateGaussian(gaussian_delta, filter_radius);
    }

    cutilSafeCall( cudaFree( d_result ) );
    delete g_CheckRender;
}

void loadImageData(int argc, char **argv)
{
    // load image (needed so we can get the width and height before we create the window
    char* image_path = NULL;
    if (argc >= 1) image_path = shrFindFilePath(image_filename, argv[0]);
    if (image_path == NULL) {
        shrLog("Error finding image file '%s'\n", image_filename);
        exit(EXIT_FAILURE);
    }

    LoadBMPFile((uchar4 **)&h_img, &width, &height, image_path);
    //cutilCheckError(cutLoadPPM4ub(image_path, (unsigned char **) &h_img, &width, &height));
    h_temp = new unsigned int[width * height];
    if (!h_img) {
        shrLog("Error opening file '%s'\n", image_path);
        exit(-1);
    }
    shrLog("Loaded '%s', %d x %d pixels\n\n", image_path, width, height);
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char** argv) 
{
    shrQAStart(argc, argv);

    // start logs
    shrSetLogFileName ("bilateralFilter.txt");
    shrLog("%s Starting...\n\n", argv[0]); 

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    cutGetCmdLineArgumenti( argc, (const char**) argv, "threads", &nthreads );
    cutGetCmdLineArgumenti( argc, (const char**) argv, "radius", &filter_radius);

	// load image to process
    loadImageData(argc, argv);

    if (cutCheckCmdLineFlag(argc, (const char **)argv, "qatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
    {
		// Running CUDA kernel (bilateralFilter) without visualization (QA Testing/Verification)
        runAutoTest(argc, argv);
	    shrQAFinishExit(argc, (const char **)argv, (g_TotalErrors == 0 ? QA_PASSED : QA_FAILED));
	} 
	else if (cutCheckCmdLineFlag(argc, (const char **)argv, "benchmark")) 
	{
		// Running CUDA kernel (bilateralFilter) in Benchmarking Mode
        runBenchmark(argc, argv);
	    shrQAFinishExit(argc, (const char **)argv, (g_TotalErrors == 0 ? QA_PASSED : QA_FAILED));
	} 
	else 
	{	
		// Running CUDA kernel (bilateralFilter) in CUDA + OpenGL Visualization Mode
        if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
             printf("[%s]\n", argv[0]);
             printf("   Does not explicitly support -device=n in OpenGL mode\n");
             printf("   To use -device=n, the sample must be running w/o OpenGL\n\n");
             printf(" > %s -device=n -qatest\n", argv[0]);
             printf("exiting...\n");
             exit(0);
        }

        // First initialize OpenGL context, so we can properly set the GL for CUDA.
        // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
        initGL( argc, argv );

        if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
            cutilGLDeviceInit(argc, argv);
        } else {
            cudaGLSetGLDevice (cutGetMaxGflopsDeviceId() );
        }
        initCuda();
        initOpenGL();
    }

    atexit(cleanup);

    printf("Running Standard Demonstration with GLUT loop...\n\n");
    printf("Press '+' and '-' to change number of iterations\n"
        "Press LEFT and RIGHT change euclidean delta\n"
        "Press UP and DOWN to change gaussian delta\n"
        "Press '1' to show original image\n"
        "Press '2' to show result\n\n");

    glutMainLoop();

    cutilDeviceReset();
	shrQAFinishExit(argc, (const char **)argv, (g_TotalErrors == 0 ? QA_PASSED : QA_FAILED));
}
