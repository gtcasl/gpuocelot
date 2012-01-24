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
    Image box filtering example

    This sample uses CUDA to perform a simple box filter on an image
    and uses OpenGL to display the results.

    It processes rows and columns of the image in parallel.

    The box filter is implemented such that it has a constant cost,
    regardless of the filter width.

    Press '=' to increment the filter radius, '-' to decrease it

    Version 1.1 - modified to process 8-bit RGBA images
*/

// OpenGL Graphics includes
#include <GL/glew.h>
#if defined(__APPLE__) || defined(__MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

// CUDA utilities and system includes
#include <cutil_inline.h>    // includes cuda.h and cuda_runtime_api.h    // includes cuda_runtime_api.h
#include <cutil_gl_inline.h> // includes cuda_gl_interop.h// includes cuda_gl_interop.h
#include <rendercheck_gl.h>

// Shared Library Test Functions
#include <shrUtils.h>
#include <shrQATest.h>

#define MAX_EPSILON_ERROR 5.0f
#define REFRESH_DELAY	  10 //ms

#define MIN_RUNTIME_VERSION 1000
#define MIN_COMPUTE_VERSION 0x10

const static char *sSDKsample = "CUDA Iterative Box Filter"; 

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "lenaRGB_10.ppm",
    "lenaRGB_14.ppm",
    "lenaRGB_18.ppm",
    "lenaRGB_22.ppm",
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

const char *image_filename = "lenaRGB.ppm";
int iterations = 1;
int filter_radius = 10;
int nthreads = 64;

unsigned int width, height;
unsigned int * h_img = NULL;
unsigned int * d_img = NULL;
unsigned int * d_temp = NULL;

GLuint pbo;     // OpenGL pixel buffer object
struct cudaGraphicsResource *cuda_pbo_resource; // handles OpenGL-CUDA exchange
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
bool g_bOpenGLQA   = false;
bool g_bFBODisplay = false;

int *pArgc = NULL;
char **pArgv = NULL;

// CheckFBO/BackBuffer class objects
CFrameBufferObject  *g_FrameBufferObject = NULL;
CheckRender         *g_CheckRender       = NULL;

//#define GL_TEXTURE_TYPE GL_TEXTURE_RECTANGLE_ARB
#define GL_TEXTURE_TYPE GL_TEXTURE_2D

extern "C" void runAutoTest(int argc, char **argv);
extern "C" void runBenchmark(); 
extern "C" void loadImageData(int argc, char **argv);
extern "C" void computeGold(float *id, float *od, int w, int h, int n);

// These are CUDA functions to handle allocation and launching the kernels
extern "C" void initTexture(int width, int height, void *pImage);
extern "C" void freeTextures();
extern "C" double boxFilter(float *d_src, float *d_temp, float *d_dest, int width, int height,
                          int radius, int iterations, int nthreads);

extern "C" double boxFilterRGBA(unsigned int *d_src, unsigned int *d_temp, unsigned int *d_dest, 
                              int width, int height, int radius, int iterations, int nthreads);

void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "[AutoTest]: %s (radius=%d)", sSDKsample, filter_radius );
	    glutSetWindowTitle(temp);

        if (filter_radius >= 10) g_Index++;
        filter_radius += 4;

		if (filter_radius > 22) {
			shrLog("Summary: %d errors!\n\n", g_TotalErrors);
            shrQAFinishExit(*pArgc, (const char **)pArgv, (g_TotalErrors==0) ? QA_PASSED : QA_FAILED);
		}
    }
}

void computeFPS()
{
    frameCount++;
    if (fpsCount++ == fpsLimit-1) {
        g_Verify = true;
    }
    if (fpsCount == fpsLimit) {
        char fps[256];
        float ifps = 1.0f / (cutGetAverageTimerValue(timer) / 1000.0f);
        sprintf(fps, "%sCUDA Box Filter (radius=%d): %3.1f fps", 
                ((g_CheckRender && g_CheckRender->IsQAReadback()) ? "[AutoTest]: " : ""), filter_radius, ifps);  

        glutSetWindowTitle(fps);
        fpsCount = 0; 
        if (g_CheckRender && !g_CheckRender->IsQAReadback()) fpsLimit = (int)MAX(ifps, 1.0f);

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
    //DEPRECATED: cutilSafeCall( cudaGLMapBufferObject((void**)&d_result, pbo) );
    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_resource, 0));
    size_t num_bytes; 
    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void **)&d_result, &num_bytes,  
						       cuda_pbo_resource));
    boxFilterRGBA(d_img, d_temp, d_result, width, height, filter_radius, iterations, nthreads);
    // DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(pbo));
    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_pbo_resource, 0));

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
            glTexCoord2f(0.0f, 0.0f);          
            glVertex2f(0.0f, 0.0f);
            glTexCoord2f(1.0f, 0.0f);          
            glVertex2f(1.0f, 0.0f);
            glTexCoord2f(1.0f, 1.0f);          
            glVertex2f(1.0f, 1.0f);
            glTexCoord2f(0.0f, 1.0f);          
            glVertex2f(0.0f, 1.0f);
        } else {
            glTexCoord2f(0.0f, 0.0f); 
            glVertex2f(0.0f, 0.0f);
            glTexCoord2f((float)width, 0.0f); 
            glVertex2f(1.0f, 0.0f);
            glTexCoord2f((float)width, (float)height); 
            glVertex2f(1.0f, 1.0f);
            glTexCoord2f(0.0f, (float)height); glVertex2f(0.0f, 1.0f);
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
            shrLog("> (Frame %d) Readback FBO\n", frameCount);
			g_CheckRender->readback( width, height, g_FrameBufferObject->getFbo() );
        } else {
            shrLog("> (Frame %d) Readback BackBuffer\n", frameCount);
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
            if (filter_radius < (int)width-1 && 
                filter_radius < (int)height-1) 
            {
                filter_radius++;
            }
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
    shrLog("radius = %d, iterations = %d\n", filter_radius, iterations);
}

void timerEvent(int value)
{
    glutPostRedisplay();
	glutTimerFunc(REFRESH_DELAY, timerEvent, 0);
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
    if(h_img)cutFree(h_img);
    cutilSafeCall(cudaFree(d_img));
    cutilSafeCall(cudaFree(d_temp));

    // Refer to boxFilter_kernel.cu for implementation
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
        shrLog("Program error at position: %d\n%s\n", (int)error_pos, error_string);
        return 0;
    }
    return program_id;
}

// This is where we create the OpenGL PBOs, FBOs, and texture resources
void initGLResources()
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
	if (g_bFBODisplay) {
		g_FrameBufferObject = new CFrameBufferObject(width, height, 32, true, GL_TEXTURE_2D);
	}
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple benchmark test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runBenchmark( int argc, char **argv ) 
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
    boxFilterRGBA(d_img, d_temp, d_temp, width, height, filter_radius, iterations, nthreads);
    cutilSafeCall( cutilDeviceSynchronize() );

	// Start round-trip timer and process iCycles loops on the GPU
    iterations = 1;     // standard 1-pass filtering
    const int iCycles = 150;
    double dProcessingTime = 0.0;
    shrLog("\nRunning BoxFilterGPU for %d cycles...\n\n", iCycles);
	shrDeltaT(2);
    for (int i = 0; i < iCycles; i++)
    {
        dProcessingTime += boxFilterRGBA(d_img, d_temp, d_img, width, height, filter_radius, iterations, nthreads);
    }

    // check if kernel execution generated an error and sync host
    cutilCheckMsg("Error: boxFilterRGBA Kernel execution FAILED");
    cutilSafeCall(cutilDeviceSynchronize());

    // Get average computation time
    dProcessingTime /= (double)iCycles;

    // log testname, throughput, timing and config info to sample and master logs
    shrLogEx(LOGBOTH | MASTER, 0, "boxFilter-texture, Throughput = %.4f M RGBA Pixels/s, Time = %.5f s, Size = %u RGBA Pixels, NumDevsUsed = %u, Workgroup = %u\n", 
                                  (1.0e-6 * width * height)/dProcessingTime, dProcessingTime, 
                                  (width * height), 1, nthreads); 
    shrLog("\n");
}

void initGL( int *argc, char **argv )
{
    // initialize GLUT
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(768, 768);
    glutCreateWindow("CUDA Box Filter");
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
	glutTimerFunc(REFRESH_DELAY, timerEvent, 0);

    glewInit();
    if (g_bFBODisplay) {
        if (!glewIsSupported( "GL_VERSION_2_0 GL_ARB_fragment_program GL_EXT_framebuffer_object" )) {
            shrLog("Error: failed to get minimal extensions for demo\n");
            shrLog("This sample requires:\n");
            shrLog("  OpenGL version 2.0\n");
            shrLog("  GL_ARB_fragment_program\n");
            shrLog("  GL_EXT_framebuffer_object\n");
            exit(-1);
        }
    } else {
        if (!glewIsSupported( "GL_VERSION_1_5 GL_ARB_vertex_buffer_object GL_ARB_pixel_buffer_object" )) {
            shrLog("Error: failed to get minimal extensions for demo\n");
            shrLog("This sample requires:\n");
            shrLog("  OpenGL version 1.5\n");
            shrLog("  GL_ARB_vertex_buffer_object\n");
            shrLog("  GL_ARB_pixel_buffer_object\n");
            exit(-1);
        }
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

    while (filter_radius <= 22) 
    {
        shrLog("[AutoTest]: %s (radius=%d)", sSDKsample, filter_radius );
        boxFilterRGBA(d_img, d_temp, d_result, width, height, filter_radius, iterations, nthreads);

        // check if kernel execution generated an error
        cutilCheckMsg("Error: boxFilterRGBA Kernel execution FAILED");
        cutilSafeCall( cutilDeviceSynchronize() );

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
}

void loadImageData(int argc, char **argv)
{
    // load image (needed so we can get the width and height before we create the window
    char* image_path = NULL;
    if (argc >= 1) image_path = shrFindFilePath(image_filename, argv[0]);
    if (image_path == 0) {
        shrLog("Error finding image file '%s'\n", image_filename);
        exit(EXIT_FAILURE);
    }

    cutilCheckError(cutLoadPPM4ub(image_path, (unsigned char **) &h_img, &width, &height));
    if (!h_img) {
        shrLog("Error opening file '%s'\n", image_path);
        exit(-1);
    }
    shrLog("Loaded '%s', %d x %d pixels\n\n", image_path, width, height);
}

bool checkCUDAProfile(int dev, int min_runtime, int min_compute)
{
    int runtimeVersion = 0;     

    cudaDeviceProp deviceProp;
    cudaGetDeviceProperties(&deviceProp, dev);

    fprintf(stderr,"\nDevice %d: \"%s\"\n", dev, deviceProp.name);
    cudaRuntimeGetVersion(&runtimeVersion);
    fprintf(stderr,"  CUDA Runtime Version     :\t%d.%d\n", runtimeVersion/1000, (runtimeVersion%100)/10);
    fprintf(stderr,"  CUDA Compute Capability  :\t%d.%d\n", deviceProp.major, deviceProp.minor);

    if( runtimeVersion >= min_runtime && ((deviceProp.major<<4) + deviceProp.minor) >= min_compute ) {
        return true;
    } else {
        return false;
    }
}

int findCapableDevice(int argc, char **argv)
{
    int dev;
    int bestDev = -1;

    int deviceCount = 0;
    cudaError_t error_id = cudaGetDeviceCount(&deviceCount);
    if (error_id != cudaSuccess) {
        fprintf(stderr, "cudaGetDeviceCount returned %d\n-> %s\n", (int)error_id, cudaGetErrorString(error_id) );
        shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
    }

    if(deviceCount==0)
        fprintf(stderr,"There are no CUDA capabile devices.\n");
    else
        fprintf(stderr,"Found %d CUDA Capable device(s) supporting CUDA\n", deviceCount);

    for (dev = 0; dev < deviceCount; ++dev) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, dev);

        if( checkCUDAProfile( dev, MIN_RUNTIME_VERSION, MIN_COMPUTE_VERSION ) ) {
            fprintf(stderr,"\nFound CUDA Capable Device %d: \"%s\"\n", dev, deviceProp.name );
            if( bestDev == -1 ) { 
                bestDev = dev;
                fprintf(stderr, "Setting active device to %d\n", bestDev );
            }
        }
    }

    if( bestDev == -1 ) {
        fprintf(stderr, "\nNo configuration with available capabilities was found.  Test has been waived.\n");
        fprintf(stderr, "The SDK sample minimum requirements:\n");
        fprintf(stderr, "\tCUDA Compute Capability >= %d.%d is required\n", MIN_COMPUTE_VERSION/16, MIN_COMPUTE_VERSION%16);
        fprintf(stderr, "\tCUDA Runtime Version    >= %d.%d is required\n", MIN_RUNTIME_VERSION/1000, (MIN_RUNTIME_VERSION%100)/10);
        shrQAFinishExit(argc, (const char **)argv, QA_PASSED);
    }
    return bestDev;
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
	pArgc = &argc;
	pArgv = argv;

	shrQAStart(argc, argv);
    // start logs
    shrSetLogFileName ("boxFilter.txt");
    shrLog("%s Starting...\n\n", argv[0]); 

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if (argc > 1) {
        cutGetCmdLineArgumenti( argc, (const char**) argv, "threads", &nthreads );
        cutGetCmdLineArgumenti( argc, (const char**) argv, "radius", &filter_radius);

        if (cutCheckCmdLineFlag(argc, (const char **)argv, "glverify"))
		{
            g_bOpenGLQA = true;
            fpsLimit = frameCheckNumber;
        }
        if (cutCheckCmdLineFlag(argc, (const char **)argv, "fbo")) {
            g_bFBODisplay = true;
        }
    }

    // load image to process
    loadImageData(argc, argv);

    if (cutCheckCmdLineFlag(argc, (const char **)argv, "qatest") ||
	    cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
    {
		// Running CUDA kernel (boxFilter) without visualization (QA Testing/Verification)
        runAutoTest(argc, argv);
        shrQAFinishExit(argc, (const char **)argv, (g_TotalErrors == 0 ? QA_PASSED : QA_FAILED));
    }
	else if (cutCheckCmdLineFlag(argc, (const char **)argv, "benchmark")) 
	{	
		// Running CUDA kernels (boxfilter) in Benchmarking mode
        runBenchmark(argc, argv);
        shrQAFinishExit(argc, (const char **)argv, (g_TotalErrors == 0 ? QA_PASSED : QA_FAILED));
	}
	else 
	{	
		// Running CUDA kernels (boxFilter) with OpenGL visualization
        if (g_bFBODisplay) shrLog("[FBO Display] ");
        if (g_bOpenGLQA)   shrLog("[OpenGL Readback Comparisons] ");
        shrLog("\n");

        if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
             printf("   This SDK does not explicitly support -device=n when running with OpenGL.\n");
             printf("   When specifying -device=n (n=0,1,2,....) the sample must not use OpenGL.\n");
			 printf("   See details below to run without OpenGL:\n\n");
             printf(" > %s -device=n -qatest\n\n", argv[0]);
             printf("exiting...\n");
			 shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
        }

        // First initialize OpenGL context, so we can properly set the GL for CUDA.
        // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
        initGL( &argc, argv );
		int dev = findCapableDevice(argc, argv);
		if( dev != -1 ) {
			cudaGLSetGLDevice( dev );
		} else {
            cutilDeviceReset();
			shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
		}

		// Now we can create a CUDA context and bind it to the OpenGL context
        initCuda();
        initGLResources();

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

	// sets the callback function so it will call cleanup upon exit
    atexit(cleanup);

    shrLog("Running Standard Demonstration with GLUT loop...\n\n");
    shrLog("Press '+' and '-' to change filter width\n"
           "Press ']' and '[' to change number of iterations\n\n");

	// Main OpenGL loop that will run visualization for every vsync
    glutMainLoop();

    cutilDeviceReset();
    shrQAFinishExit(argc, (const char **)argv, (g_TotalErrors == 0 ? QA_PASSED : QA_FAILED));
}
