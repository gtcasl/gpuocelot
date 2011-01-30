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
    FFT-based Ocean simulation
    based on original code by Yury Uralsky

    This sample demonstrates how to use CUFFT to synthesize and
    render an ocean surface in real-time.

    See Jerry Tessendorf's Siggraph course notes for more details:
    http://www.finelightvisualtechnology.com/pages/coursematerials.php    

    It also serves as an example of how to generate multiple vertex
    buffer streams from CUDA and render them using GLSL shaders.
*/

#ifdef _WIN32
#  define WINDOWS_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

// includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/glew.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cutil_gl_error.h>
#include <cuda_gl_interop.h>
#include <cufft.h>
#include <math_constants.h>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <rendercheck_gl.h>

const char *sSDKsample = "CUDA FFT Ocean Simulation";

#define MAX_EPSILON 0.10f
#define THRESHOLD   0.15f

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "oceanFFT.ppm",
    NULL
};

const char *sReference[] =
{
    "reference.ppm",
    NULL
};

bool g_bQAReadback = false;
bool g_bOpenGLQA   = false;


// check if we're running in emulation mode
int inEmulationMode()
{
#ifdef __DEVICE_EMULATION__
    return 1;
#else
    return 0;
#endif
} // inEmulationMode

////////////////////////////////////////////////////////////////////////////////
// constants
unsigned int windowW = 512, windowH = 512;
const unsigned int meshW = 256,  meshH = 256;
const int frameCompare = 4;

unsigned int fftInputW, fftInputH;
unsigned int fftInputSize;

// OpenGL vertex buffers
GLuint posVertexBuffer;
GLuint heightVertexBuffer, slopeVertexBuffer;
struct cudaGraphicsResource *cuda_posVB_resource, *cuda_heightVB_resource, *cuda_slopeVB_resource; // handles OpenGL-CUDA exchange

GLuint indexBuffer;
GLuint shaderProg;
char* vertShaderPath = 0, *fragShaderPath = 0;

float  *d_heightVB;
float2 *d_slopeVB;
float  *d_meshPosVBO;
GLuint *d_indexBuffer;

// mouse controls
int mouseOldX, mouseOldY;
int mouseButtons = 0;
float rotateX = 20.0f, rotateY = 0.0f;
float translateX = 0.0f, translateY = 0.0f, translateZ = -2.0f;

bool animate = true;
bool drawPoints = false;
bool wireFrame = false;
bool g_hasDouble = false;

// FFT data
cufftHandle fftPlan;
float2 *d_h0 = 0, *d_ht = 0;
float2 *h_h0 = 0;
float2 *d_slope = 0;

// pointers to device object
float  *g_hptr = NULL;
float2 *g_sptr = NULL;

// simulation parameters
const float g = 9.81;		        // gravitational constant
const float A = 2*.00000000775f;	// wave scale factor
const float patchSize = 100;        // patch size
float windSpeed = 10.0f;
float windDir = CUDART_PI_F/3.0f;

unsigned int timer;
float animTime = 0.0f;
float prevTime = 0.0f;
float animationRate = -0.0005f;

// Auto-Verification Code
const int frameCheckNumber = 4;
int fpsCount = 0;        // FPS count for averaging
int fpsLimit = 1;        // FPS limit for sampling
unsigned int frameCount = 0;
unsigned int g_TotalErrors = 0;
bool g_Verify = false, g_AutoQuit = false;

// CheckFBO/BackBuffer class objects
CheckRender       *g_CheckRender = NULL;

#define MAX(a,b) ((a > b) ? a : b)

////////////////////////////////////////////////////////////////////////////////
// kernels
//#include <oceanFFT_kernel.cu>

extern "C" 
void cudaGenerateSpectrumKernel(float2* d_h0, float2 *d_ht, 
                                unsigned int width, unsigned int height, 
                                float animTime, float patchSize);

extern "C"
void cudaCalculateSlopeKernel(  float* h, float2 *slopeOut, 
                                unsigned int width, unsigned int height);

////////////////////////////////////////////////////////////////////////////////
// forward declarations
void runAutoTest(int argc, char** argv);
void runGraphicsTest(int argc, char** argv);

// GL functionality
CUTBoolean initGL(int *argc, char **argv);
void createVBO(GLuint* vbo, int size);
void deleteVBO(GLuint* vbo);
void createMeshIndexBuffer(GLuint *id, int w, int h);
void createMeshPositionVBO(GLuint *id, int w, int h);
GLuint loadGLSLProgram(const char *vertFileName, const char *fragFileName);

// rendering callbacks
void display();
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void reshape(int w, int h);
void idle();

// Cuda functionality
void runCuda();
void runCudaTest(bool bHasDouble);
void generate_h0();
void generateFftInput();

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    // check for command line arguments
    if (argc > 1) {
        if (cutCheckCmdLineFlag(argc, (const char **)argv, "qatest") ||
            cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
		{
            g_bQAReadback = true;
            animate       = false;
            fpsLimit = frameCheckNumber;
        }
        if (cutCheckCmdLineFlag(argc, (const char **)argv, "glverify")) {
            g_bOpenGLQA = true;
            animate = false;
            fpsLimit = frameCheckNumber;
        }
    }

    if (g_bQAReadback) 
    {
        // Automated testing 
        runAutoTest(argc, argv);
    } 
    else 
    {
        printf("[%s]\n\n"
               "Left mouse button          - rotate\n"
               "Middle mouse button        - pan\n"
               "Left + middle mouse button - zoom\n"
               "'w' key                    - toggle wireframe\n", sSDKsample);

        runGraphicsTest(argc, argv);
    }

    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Run test
////////////////////////////////////////////////////////////////////////////////
void runAutoTest(int argc, char** argv)
{
    printf("[%s]\n", sSDKsample);

    // Cuda init
	int dev = cutilChooseCudaDevice(argc, argv);

    cudaDeviceProp deviceProp;
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, dev));
    printf("Compute capability %d.%d\n", deviceProp.major, deviceProp.minor);
    int version = deviceProp.major*10 + deviceProp.minor;
    g_hasDouble = (version >= 13);
    if (inEmulationMode()) {
        // workaround since SM13 kernel doesn't produce correct output in emulation mode
        g_hasDouble = false;
    }

    // create FFT plan
    CUFFT_SAFE_CALL(cufftPlan2d(&fftPlan, meshW, meshH, CUFFT_C2R) );

    // allocate memory
    fftInputW = (meshW / 2)+1;
    fftInputH = meshH;
    fftInputSize = (fftInputW*fftInputH)*sizeof(float2);

    cutilSafeCall(cudaMalloc((void **)&d_h0, fftInputSize) );
    cutilSafeCall(cudaMalloc((void **)&d_ht, fftInputSize) );
    h_h0 = (float2 *) malloc(fftInputSize);
    generate_h0();
    cutilSafeCall(cudaMemcpy(d_h0, h_h0, fftInputSize, cudaMemcpyHostToDevice) );

    cutilSafeCall(cudaMalloc((void **)&d_slope, meshW*meshH*sizeof(float2)) );

    cutCreateTimer(&timer);
    cutStartTimer(timer);
    prevTime = cutGetTimerValue(timer);

    // Creating the Auto-Validation Code
    g_CheckRender = new CheckBackBuffer(windowH, windowH, 4, false);
    g_CheckRender->setPixelFormat(GL_RGBA);
    g_CheckRender->setExecPath(argv[0]);
    g_CheckRender->EnableQAReadback(true);

    runCudaTest(g_hasDouble);
    cudaThreadExit();
}

////////////////////////////////////////////////////////////////////////////////
//! Run test
////////////////////////////////////////////////////////////////////////////////
void runGraphicsTest(int argc, char** argv)
{
    printf("[%s] ", sSDKsample);
    if (g_bOpenGLQA)   printf("[OpenGL Readback Comparisons] ");
    printf("\n");

    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device") ) { 
		printf("[%s]\n", argv[0]);
		printf("   Does not explicitly support -device=n in OpenGL mode\n");
		printf("   To use -device=n, the sample must be running w/o OpenGL\n\n");
		printf(" > %s -device=n -qatest\n", argv[0]);
		printf("exiting...\n");
		exit(0);
    }

    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    if(CUTFalse == initGL( &argc, argv )) {
        cudaThreadExit();
        return;
    }

    cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );

    // create FFT plan
    CUFFT_SAFE_CALL(cufftPlan2d(&fftPlan, meshW, meshH, CUFFT_C2R) );

    // allocate memory
    fftInputW = (meshW / 2)+1;
    fftInputH = meshH;
    fftInputSize = (fftInputW*fftInputH)*sizeof(float2);

    cutilSafeCall(cudaMalloc((void **)&d_h0, fftInputSize) );
    cutilSafeCall(cudaMalloc((void **)&d_ht, fftInputSize) );
    h_h0 = (float2 *) malloc(fftInputSize);
    generate_h0();
    cutilSafeCall(cudaMemcpy(d_h0, h_h0, fftInputSize, cudaMemcpyHostToDevice) );

    cutilSafeCall(cudaMalloc((void **)&d_slope, meshW*meshH*sizeof(float2)) );

    cutCreateTimer(&timer);
    cutStartTimer(timer);
    prevTime = cutGetTimerValue(timer);

    // create vertex buffers and register with CUDA
    createVBO(&heightVertexBuffer, meshW*meshH*sizeof(float));
    // DEPRECATED: cutilSafeCall(cudaGLRegisterBufferObject(heightVertexBuffer));
	cutilSafeCall(cudaGraphicsGLRegisterBuffer(&cuda_heightVB_resource, heightVertexBuffer, cudaGraphicsMapFlagsWriteDiscard));

    createVBO(&slopeVertexBuffer, meshW*meshH*sizeof(float2));
    // DEPRECATED: cutilSafeCall(cudaGLRegisterBufferObject(slopeVertexBuffer));
	cutilSafeCall(cudaGraphicsGLRegisterBuffer(&cuda_slopeVB_resource, slopeVertexBuffer, cudaGraphicsMapFlagsWriteDiscard));

    // create vertex and index buffer for mesh
    createMeshPositionVBO(&posVertexBuffer, meshW, meshH);
    createMeshIndexBuffer(&indexBuffer, meshW, meshH);

    // Creating the Auto-Validation Code
    if (g_bOpenGLQA) {
        g_CheckRender = new CheckBackBuffer(windowH, windowH, 4);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);
    }

    runCuda();

    // register callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    // start rendering mainloop
    glutMainLoop();
    cudaThreadExit();
}

// Phillips spectrum
// Vdir - wind angle in radians
// V - wind speed
float phillips(float Kx, float Ky, float Vdir, float V, float A)
{
    float k_squared = Kx * Kx + Ky * Ky;
    float k_x = Kx / sqrtf(k_squared);
    float k_y = Ky / sqrtf(k_squared);
    float L = V * V / g;
    float w_dot_k = k_x * cosf(Vdir) + k_y * sinf(Vdir);

    if (k_squared == 0) return 0;

    return A * expf(-1.0 / (k_squared * L * L)) / (k_squared * k_squared) * w_dot_k * w_dot_k;
}

// Generate base heightfield in frequency space
void generate_h0()
{
    for (unsigned int y = 0; y<fftInputH; y++) {
        for (unsigned int x = 0; x<fftInputW; x++) {
            float kx = CUDART_PI_F * x / (float) patchSize;
            float ky = 2.0f * CUDART_PI_F * y / (float) patchSize;

            // note - these random numbers should be from a Gaussian distribution really
            float Er = 2.0f * rand() / (float) RAND_MAX - 1.0f;
            float Ei = 2.0f * rand() / (float) RAND_MAX - 1.0f;

            float P = sqrt(phillips(kx, ky, windDir, windSpeed, A));  

            float h0_re = 1.0f / sqrtf(2.0f) * Er * P;
            float h0_im = 1.0f / sqrtf(2.0f) * Ei * P;

            int i = y*fftInputW+x;
            h_h0[i].x = h0_re;
            h_h0[i].y = h0_im;
        }
    }
}

//Round a / b to nearest higher integer value
int iDivUp(int a, int b)
{
    return (a + (b - 1)) / b;
}

////////////////////////////////////////////////////////////////////////////////
//! Run the Cuda kernels
////////////////////////////////////////////////////////////////////////////////
void runCuda()
{
	size_t num_bytes; 

	// generate wave spectrum in frequency domain
    cudaGenerateSpectrumKernel(d_h0, d_ht, fftInputW, fftInputH, animTime, patchSize);

    // execute inverse FFT to convert to spatial domain
    // DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&g_hptr, heightVertexBuffer));
    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_heightVB_resource, 0));
	// DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&g_hptr, heightVertexBuffer));
	cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void**)&g_hptr, &num_bytes, cuda_heightVB_resource));

	cufftSafeCall( cufftExecC2R(fftPlan, (cufftComplex *) d_ht, g_hptr) );

    // calculate slope for shading
    // DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&g_sptr, slopeVertexBuffer));
    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_slopeVB_resource, 0));
	// DEPRECATED: cutilSafeCall(cudaGraphicsMapBufferObject((void**)&g_sptr, slopeVertexBuffer));
	cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void**)&g_sptr, &num_bytes, cuda_slopeVB_resource));

    cudaCalculateSlopeKernel(g_hptr, g_sptr, meshW, meshH);

    // DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(slopeVertexBuffer));
    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_slopeVB_resource, 0));
	// DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(heightVertexBuffer));
    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_heightVB_resource, 0));
}

const char *sSpatialDomain[] =
{
    "ref_spatialDomain.bin",
    "ref_spatialDomain_sm13.bin",
    NULL
};

const char *sSlopeShading[] =
{
    "ref_slopeShading.bin",
    "ref_slopeShading_sm13.bin",
    NULL
};

void runCudaTest(bool bHasDouble)
{
    cutilSafeCall( cudaMalloc((void **)&g_hptr, meshW*meshH*sizeof(float)) );
    cutilSafeCall( cudaMalloc((void **)&g_sptr, meshW*meshH*sizeof(float2)) );

    // generate wave spectrum in frequency domain
    cudaGenerateSpectrumKernel(d_h0, d_ht, fftInputW, fftInputH, animTime, patchSize);

    // execute inverse FFT to convert to spatial domain
    cufftSafeCall( cufftExecC2R(fftPlan, (cufftComplex *) d_ht, g_hptr) );

    if (g_CheckRender) {
        float *hptr = (float *)malloc(meshW*meshH*sizeof(float));
        cudaMemcpy((void *)hptr, (void *)g_hptr, meshW*meshH*sizeof(float), cudaMemcpyDeviceToHost);
        g_CheckRender->dumpBin((void *)hptr, meshW*meshH*sizeof(float), "spatialDomain.bin");
        if(!g_CheckRender->compareBin2BinFloat("spatialDomain.bin", sSpatialDomain[bHasDouble], meshW*meshH*sizeof(float), MAX_EPSILON, THRESHOLD))
            g_TotalErrors++;
        free(hptr);
    }

    // calculate slope for shading
    cudaCalculateSlopeKernel(g_hptr, g_sptr, meshW, meshH);

    if (g_CheckRender) {
        float2 *sptr = (float2 *)malloc(meshW*meshH*sizeof(float2));
        cudaMemcpy((void *)sptr, (void *)g_sptr, meshW*meshH*sizeof(float2), cudaMemcpyDeviceToHost);
        g_CheckRender->dumpBin(sptr, meshW*meshH*sizeof(float2), "slopeShading.bin");
        if (!g_CheckRender->compareBin2BinFloat("slopeShading.bin", sSlopeShading[bHasDouble], meshW*meshH*sizeof(float2), MAX_EPSILON, THRESHOLD))
            g_TotalErrors++;
        free(sptr);
    }

    printf("%s\n", (g_TotalErrors==0) ? "PASSED" : "FAILED");

    cutilSafeCall( cudaFree(g_hptr) );
    cutilSafeCall( cudaFree(g_sptr) );
}


void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "AutoTest: CUDA FFT Ocean Simulation");

        glutSetWindowTitle(temp);

	if (g_AutoQuit) {
		printf("Summary: %d errors!\n", g_TotalErrors);
		printf("%s\n", (g_TotalErrors==0) ? "PASSED" : "FAILED");
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
        fpsCount = 0; 
        g_AutoQuit = true;
        AutoQATest();
    }
}

////////////////////////////////////////////////////////////////////////////////
//! Display callback
////////////////////////////////////////////////////////////////////////////////
void display()
{
    // run CUDA kernel to generate vertex positions
    if (animate) {
        runCuda();
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translateX, translateY, translateZ);
    glRotatef(rotateX, 1.0, 0.0, 0.0);
    glRotatef(rotateY, 0.0, 1.0, 0.0);

    // render from the vbo
    glBindBuffer(GL_ARRAY_BUFFER, posVertexBuffer);
    glVertexPointer(4, GL_FLOAT, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, heightVertexBuffer);
    glClientActiveTexture(GL_TEXTURE0);
    glTexCoordPointer(1, GL_FLOAT, 0, 0);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, slopeVertexBuffer);
    glClientActiveTexture(GL_TEXTURE1);
    glTexCoordPointer(2, GL_FLOAT, 0, 0);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glUseProgram(shaderProg);
    
    // Set default uniform variables parameters for the vertex shader
    GLuint uniHeightScale, uniChopiness, uniSize;

    uniHeightScale = glGetUniformLocation(shaderProg, "heightScale");
    glUniform1f(uniHeightScale, 0.5f);

    uniChopiness   = glGetUniformLocation(shaderProg, "chopiness");
    glUniform1f(uniChopiness, 1.0f);

    uniSize        = glGetUniformLocation(shaderProg, "size");
    glUniform2f(uniSize, meshW, meshH);

    // Set default uniform variables parameters for the pixel shader
    GLuint uniDeepColor, uniShallowColor, uniSkyColor, uniLightDir;

    uniDeepColor = glGetUniformLocation(shaderProg, "deepColor");
    glUniform4f(uniDeepColor, 0.0f, 0.0f, 0.1f, 1.0f);

    uniShallowColor = glGetUniformLocation(shaderProg, "shallowColor");
    glUniform4f(uniShallowColor, 0.1f, 0.4f, 0.3f, 1.0f);

    uniSkyColor = glGetUniformLocation(shaderProg, "skyColor");
    glUniform4f(uniSkyColor, 0.5f, 0.5f, 0.5f, 1.0f);

    uniLightDir = glGetUniformLocation(shaderProg, "lightDir");
    glUniform3f(uniLightDir, 0.0f, 1.0f, 0.0f);
    // end of uniform settings

    glColor3f(1.0, 1.0, 1.0);
    if (drawPoints) {
        glDrawArrays(GL_POINTS, 0, meshW * meshH);
    } else {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

        glPolygonMode(GL_FRONT_AND_BACK, wireFrame ? GL_LINE : GL_FILL);
            glDrawElements(GL_TRIANGLE_STRIP, ((meshW*2)+2)*(meshH-1), GL_UNSIGNED_INT, 0);        
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glClientActiveTexture(GL_TEXTURE0);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glClientActiveTexture(GL_TEXTURE1);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glUseProgram(0);

    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        printf("> (Frame %d) Readback BackBuffer\n", frameCount);
        g_CheckRender->readback( windowW, windowH );
        g_CheckRender->savePPM ( sOriginal[0], true, NULL);
        if (!g_CheckRender->PPMvsPPM( sOriginal[0], sReference[0], MAX_EPSILON, THRESHOLD)) {
            g_TotalErrors++;   
        }
        g_Verify = false;
    }
    glutSwapBuffers();

    computeFPS();
}

void idle()
{
    float time = cutGetTimerValue(timer);
    if (animate) {
        animTime += (time - prevTime) * animationRate;
    }
    glutPostRedisplay();
    prevTime = time;
}

void cleanup()
{
    // DEPRECATED: cutilSafeCall(cudaGLUnregisterBufferObject(heightVertexBuffer));
    cutilSafeCall(cudaGraphicsUnregisterResource(cuda_heightVB_resource));
    // DEPRECATED: cutilSafeCall(cudaGLUnregisterBufferObject(slopeVertexBuffer));
    cutilSafeCall(cudaGraphicsUnregisterResource(cuda_slopeVB_resource));

	deleteVBO(&posVertexBuffer);
    deleteVBO(&heightVertexBuffer);
    deleteVBO(&slopeVertexBuffer);

    cutilSafeCall( cudaFree(d_h0) );
    cutilSafeCall( cudaFree(d_slope) );
    free(h_h0);
    cufftDestroy(fftPlan);
}

////////////////////////////////////////////////////////////////////////////////
//! Keyboard events handler
////////////////////////////////////////////////////////////////////////////////
void keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch(key) {
    case(27) :
        cleanup();
        exit(0);
    case 'w':
        wireFrame = !wireFrame;
        break;
    case 'p':
        drawPoints = !drawPoints;
        break;
    case ' ':
        animate = !animate;
        break;
    }
    glutPostRedisplay();
}

////////////////////////////////////////////////////////////////////////////////
//! Mouse event handlers
////////////////////////////////////////////////////////////////////////////////
void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) {
        mouseButtons |= 1<<button;
    } else if (state == GLUT_UP) {
        mouseButtons = 0;
    }

    mouseOldX = x;
    mouseOldY = y;
    glutPostRedisplay();
}

void motion(int x, int y)
{
    float dx, dy;
    dx = x - mouseOldX;
    dy = y - mouseOldY;

    if (mouseButtons == 1) {
        rotateX += dy * 0.2f;
        rotateY += dx * 0.2f;
    } else if (mouseButtons == 2) {
        translateX += dx * 0.01f;
        translateY -= dy * 0.01f;        
    } else if (mouseButtons == 3) {
        translateZ += dy * 0.01f;
    }

    mouseOldX = x;
    mouseOldY = y;
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double) w / (double) h, 0.1, 10.0);

    windowW = w;
    windowH = h;
}

////////////////////////////////////////////////////////////////////////////////
//! Initialize GL
////////////////////////////////////////////////////////////////////////////////
CUTBoolean initGL(int *argc, char **argv)
{
    // Create GL context
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(windowW, windowH);
    glutCreateWindow("CUDA FFT Ocean Simulation");

    vertShaderPath = cutFindFilePath("ocean.vert", argv[0]);
    fragShaderPath = cutFindFilePath("ocean.frag", argv[0]);
    if (vertShaderPath == 0 || fragShaderPath == 0) {
        fprintf(stderr, "Error finding shader files!\n");
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }

    // initialize necessary OpenGL extensions
    glewInit();
    if (! glewIsSupported("GL_VERSION_2_0 " 
        )) {
        fprintf(stderr, "ERROR: Support for necessary OpenGL extensions missing.");
        fflush(stderr);
        return CUTFalse;
    }

    if (!glewIsSupported( "GL_VERSION_1_5 GL_ARB_vertex_buffer_object GL_ARB_pixel_buffer_object" )) {
	    fprintf(stderr, "Error: failed to get minimal extensions for demo\n");
	    fprintf(stderr, "This sample requires:\n");
	    fprintf(stderr, "  OpenGL version 1.5\n");
	    fprintf(stderr, "  GL_ARB_vertex_buffer_object\n");
	    fprintf(stderr, "  GL_ARB_pixel_buffer_object\n");
            cleanup();
	    exit(-1);
    }

    // default initialization
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    // load shader
    shaderProg = loadGLSLProgram(vertShaderPath, fragShaderPath);

    CUT_CHECK_ERROR_GL();
    return CUTTrue;
}

////////////////////////////////////////////////////////////////////////////////
//! Create VBO
////////////////////////////////////////////////////////////////////////////////
void createVBO(GLuint* vbo, int size)
{
    // create buffer object
    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    CUT_CHECK_ERROR_GL();
}

////////////////////////////////////////////////////////////////////////////////
//! Delete VBO
////////////////////////////////////////////////////////////////////////////////
void deleteVBO(GLuint* vbo)
{
    glDeleteBuffers(1, vbo);
    *vbo = 0;
}

// create index buffer for rendering quad mesh
void createMeshIndexBuffer(GLuint *id, int w, int h)
{
    int size = ((w*2)+2)*(h-1)*sizeof(GLuint);

    // create index buffer
    glGenBuffersARB(1, id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *id);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER, size, 0, GL_STATIC_DRAW);

    // fill with indices for rendering mesh as triangle strips
    GLuint *indices = (GLuint *) glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
    if (!indices) {
        return;
    }

    for(int y=0; y<h-1; y++) {
        for(int x=0; x<w; x++) {
            *indices++ = y*w+x;
            *indices++ = (y+1)*w+x;
        }
        // start new strip with degenerate triangle
        *indices++ = (y+1)*w+(w-1);
        *indices++ = (y+1)*w;
    }

    glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// create fixed vertex buffer to store mesh vertices
void createMeshPositionVBO(GLuint *id, int w, int h)
{
    createVBO(id, w*h*4*sizeof(float));

    glBindBuffer(GL_ARRAY_BUFFER, *id);
    float *pos = (float *) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    if (!pos) {
        return;
    }
    
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            float u = x / (float) (w-1);
            float v = y / (float) (h-1);
            *pos++ = u*2.0f-1.0f;
            *pos++ = 0.0f;
            *pos++ = v*2.0f-1.0f;
            *pos++ = 1.0f;
        }
    }

    glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Attach shader to a program
int attachShader(GLuint prg, GLenum type, const char *name)
{
    GLuint shader;
    FILE * fp;
    int size, compiled;
    char * src;

    fp = fopen(name, "rb");
    if (!fp) return 0;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    src = (char*)malloc(size);

    fseek(fp, 0, SEEK_SET);
    fread(src, sizeof(char), size, fp);
    fclose(fp);

    shader = glCreateShader(type);
    glShaderSource(shader, 1, (const char**)&src, (const GLint*)&size);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, (GLint*)&compiled);
    if (!compiled) {
        char log[2048];
        int len;

        glGetShaderInfoLog(shader, 2048, (GLsizei*)&len, log);
        printf("Info log: %s\n", log);
        glDeleteShader(shader);
        return 0;
    }
    free(src);
        
    glAttachShader(prg, shader);
    glDeleteShader(shader);

    return 1;
}

// Create shader program from vertex shader and fragment shader files
GLuint loadGLSLProgram(const char *vertFileName, const char *fragFileName)
{
    GLint linked;
    GLuint program;

    program = glCreateProgram();
    if (!attachShader(program, GL_VERTEX_SHADER, vertFileName)) {
        glDeleteProgram(program);
        fprintf(stderr, "Couldn't attach vertex shader from file %s\n", vertFileName);
        return 0;
    }

    if (!attachShader(program, GL_FRAGMENT_SHADER, fragFileName)) {
        glDeleteProgram(program);
        fprintf(stderr, "Couldn't attach fragment shader from file %s\n", fragFileName);
        return 0;
    }

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked) {
        glDeleteProgram(program);
        char temp[256];
        glGetProgramInfoLog(program, 256, 0, temp);
        fprintf(stderr, "Failed to link program: %s\n", temp);
        return 0;
    }

    return program;
}
