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
    Volume rendering sample

    This sample loads a 3D volume from disk and displays it using
    ray marching and 3D textures.

    Note - this is intended to be an example of using 3D textures
    in CUDA, not an optimized volume renderer.

    Changes
    sgg 22/3/2010
    - updated to use texture for display instead of glDrawPixels.
    - changed to render from front-to-back rather than back-to-front.
*/

// Graphics includes
#include <GL/glew.h>
#if defined (__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Utilities and System includes
#include <shrUtils.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>

#include <vector_types.h>
#include <vector_functions.h>
#include <driver_functions.h>
#include <cuda_gl_interop.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define MAX_EPSILON_ERROR 5.00f
#define THRESHOLD         0.30f

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "volume.ppm",
    NULL
};

const char *sReference[] =
{
    "ref_volume.ppm",
    NULL
};

const char *sSDKsample = "CUDA 3D Volume Render";

char *volumeFilename = "Bucky.raw";
cudaExtent volumeSize = make_cudaExtent(32, 32, 32);
typedef unsigned char VolumeType;

//char *volumeFilename = "mrt16_angio.raw";
//cudaExtent volumeSize = make_cudaExtent(416, 512, 112);
//typedef unsigned short VolumeType;

uint width = 512, height = 512;
dim3 blockSize(16, 16);
dim3 gridSize;

float3 viewRotation;
float3 viewTranslation = make_float3(0.0, 0.0, -4.0f);
float invViewMatrix[12];

float density = 0.05f;
float brightness = 1.0f;
float transferOffset = 0.0f;
float transferScale = 1.0f;
bool linearFiltering = true;

GLuint pbo = 0;     // OpenGL pixel buffer object
GLuint tex = 0;     // OpenGL texture object
struct cudaGraphicsResource *cuda_pbo_resource; // CUDA Graphics Resource (to transfer PBO)

unsigned int timer = 0;

// Auto-Verification Code
const int frameCheckNumber = 2;
int fpsCount = 0;        // FPS count for averaging
int fpsLimit = 1;        // FPS limit for sampling
int g_Index = 0;
unsigned int frameCount = 0;
unsigned int g_TotalErrors = 0;
bool g_Verify = false;
bool g_bQAReadback = false;
bool g_bQAGLVerify = false;
bool g_bFBODisplay = false;

// CheckFBO/BackBuffer class objects
CheckRender       *g_CheckRender = NULL;

#define MAX(a,b) ((a > b) ? a : b)

extern "C" void setTextureFilterMode(bool bLinearFilter);
extern "C" void initCuda(void *h_volume, cudaExtent volumeSize);
extern "C" void freeCudaBuffers();
extern "C" void render_kernel(dim3 gridSize, dim3 blockSize, uint *d_output, uint imageW, uint imageH, 
							  float density, float brightness, float transferOffset, float transferScale);
extern "C" void copyInvViewMatrix(float *invViewMatrix, size_t sizeofMatrix);

void initPixelBuffer();

void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "AutoTest: Volume Render");
	    glutSetWindowTitle(temp);

		exit(0);
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
        sprintf(fps, "%sVolume Render: %3.1f fps", 
                ((g_CheckRender && g_CheckRender->IsQAReadback()) ? "AutoTest: " : ""), ifps);  

        glutSetWindowTitle(fps);
        fpsCount = 0; 
        if (g_CheckRender && !g_CheckRender->IsQAReadback()) fpsLimit = (int)MAX(ifps, 1.f);

        cutilCheckError(cutResetTimer(timer));  

        AutoQATest();
    }
}

// render image using CUDA
void render()
{
	copyInvViewMatrix(invViewMatrix, sizeof(float4)*3);

    // map PBO to get CUDA device pointer
    uint *d_output;
	// map PBO to get CUDA device pointer
	cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_resource, 0));
    size_t num_bytes; 
    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void **)&d_output, &num_bytes,  
						       cuda_pbo_resource));
    //printf("CUDA mapped PBO: May access %ld bytes\n", num_bytes);

    // clear image
    cutilSafeCall(cudaMemset(d_output, 0, width*height*4));

    // call CUDA kernel, writing results to PBO
    render_kernel(gridSize, blockSize, d_output, width, height, density, brightness, transferOffset, transferScale);

    cutilCheckMsg("kernel failed");

    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_pbo_resource, 0));
}

// display results using OpenGL (called by GLUT)
void display()
{
    cutilCheckError(cutStartTimer(timer));  

    // use OpenGL to build view matrix
    GLfloat modelView[16];
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();
        glRotatef(-viewRotation.x, 1.0, 0.0, 0.0);
        glRotatef(-viewRotation.y, 0.0, 1.0, 0.0);
        glTranslatef(-viewTranslation.x, -viewTranslation.y, -viewTranslation.z);
    glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
    glPopMatrix();

    invViewMatrix[0] = modelView[0]; invViewMatrix[1] = modelView[4]; invViewMatrix[2] = modelView[8]; invViewMatrix[3] = modelView[12];
    invViewMatrix[4] = modelView[1]; invViewMatrix[5] = modelView[5]; invViewMatrix[6] = modelView[9]; invViewMatrix[7] = modelView[13];
    invViewMatrix[8] = modelView[2]; invViewMatrix[9] = modelView[6]; invViewMatrix[10] = modelView[10]; invViewMatrix[11] = modelView[14];

    render();

    // display results
    glClear(GL_COLOR_BUFFER_BIT);

    // draw image from PBO
    glDisable(GL_DEPTH_TEST);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
#if 0
    // draw using glDrawPixels (slower)
    glRasterPos2i(0, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
#else
    // draw using texture

    // copy from pbo to texture
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    // draw textured quad
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2f(0, 0);
    glTexCoord2f(1, 0); glVertex2f(1, 0);
    glTexCoord2f(1, 1); glVertex2f(1, 1);
    glTexCoord2f(0, 1); glVertex2f(0, 1);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
#endif

    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        // readback for QA testing
        shrLog("\n> (Frame %d) Readback BackBuffer\n", frameCount);
        g_CheckRender->readback( width, height );
        g_CheckRender->savePPM(sOriginal[g_Index], true, NULL);
        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, THRESHOLD)) {
            g_TotalErrors++;
        }
        g_Verify = false;
    }
    glutSwapBuffers();
    glutReportErrors();

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
        case 'f':
            linearFiltering = !linearFiltering;
			setTextureFilterMode(linearFiltering);
            break;
        case '=':
            density += 0.01;
            break;
        case '-':
            density -= 0.01;
            break;
        case '+':
            density += 0.1;
            break;
        case '_':
            density -= 0.1;
            break;

        case ']':
            brightness += 0.1;
            break;
        case '[':
            brightness -= 0.1;
            break;

        case ';':
            transferOffset += 0.01;
            break;
        case '\'':
            transferOffset -= 0.01;
            break;

        case '.':
            transferScale += 0.01;
            break;
        case ',':
            transferScale -= 0.01;
            break;

        default:
            break;
    }
    shrLog("density = %.2f, brightness = %.2f, transferOffset = %.2f, transferScale = %.2f\n", density, brightness, transferOffset, transferScale);
    glutPostRedisplay();
}

int ox, oy;
int buttonState = 0;

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
        buttonState  |= 1<<button;
    else if (state == GLUT_UP)
        buttonState = 0;

    ox = x; oy = y;
    glutPostRedisplay();
}

void motion(int x, int y)
{
    float dx, dy;
    dx = x - ox;
    dy = y - oy;

    if (buttonState == 4) {
        // right = zoom
        viewTranslation.z += dy / 100.0;
    } 
    else if (buttonState == 2) {
        // middle = translate
        viewTranslation.x += dx / 100.0;
        viewTranslation.y -= dy / 100.0;
    }
    else if (buttonState == 1) {
        // left = rotate
        viewRotation.x += dy / 5.0;
        viewRotation.y += dx / 5.0;
    }

    ox = x; oy = y;
    glutPostRedisplay();
}

int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

void reshape(int w, int h)
{
    width = w; height = h;
    initPixelBuffer();

    // calculate new grid size
    gridSize = dim3(iDivUp(width, blockSize.x), iDivUp(height, blockSize.y));

    glViewport(0, 0, w, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
}

void cleanup()
{
    cutilCheckError( cutDeleteTimer( timer));

	freeCudaBuffers();

    if (pbo) {
	    cutilSafeCall(cudaGraphicsUnregisterResource(cuda_pbo_resource));
        glDeleteBuffersARB(1, &pbo);
        glDeleteTextures(1, &tex);
    }

    if (g_CheckRender) {
        delete g_CheckRender; g_CheckRender = NULL;
    }
}

void initGL(int *argc, char **argv)
{
    // initialize GLUT callback functions
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("CUDA volume rendering");

    glewInit();
    if (!glewIsSupported("GL_VERSION_2_0 GL_ARB_pixel_buffer_object")) {
        shrLog("Required OpenGL extensions missing.");
        exit(-1);
    }
}

void initPixelBuffer()
{
    if (pbo) {
		// unregister this buffer object from CUDA C
		cutilSafeCall(cudaGraphicsUnregisterResource(cuda_pbo_resource));

		// delete old buffer
        glDeleteBuffersARB(1, &pbo);
        glDeleteTextures(1, &tex);
    }

    // create pixel buffer object for display
    glGenBuffersARB(1, &pbo);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
	glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, width*height*sizeof(GLubyte)*4, 0, GL_STREAM_DRAW_ARB);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    // register this buffer object with CUDA
	cutilSafeCall(cudaGraphicsGLRegisterBuffer(&cuda_pbo_resource, pbo, cudaGraphicsMapFlagsWriteDiscard));	

    // create texture for display
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// Load raw data from disk
void *loadRawFile(char *filename, size_t size)
{
	FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return 0;
    }

	void *data = malloc(size);
	size_t read = fread(data, 1, size, fp);
	fclose(fp);

    shrLog("Read '%s', %d bytes\n", filename, read);

    return data;
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    //start logs
    shrSetLogFileName ("volumeRender.txt");
    shrLog("%s Starting...\n\n", argv[0]); 

    if (cutCheckCmdLineFlag(argc, (const char **)argv, "qatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
	{
        g_bQAReadback = true;
        fpsLimit = frameCheckNumber;
    }

    if (cutCheckCmdLineFlag(argc, (const char **)argv, "glverify")) 
	{
        g_bQAGLVerify = true;
        fpsLimit = frameCheckNumber;
    }

    if (g_bQAReadback) {
	    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
        if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
            cutilDeviceInit(argc, argv);
        } else {
            cudaSetDevice( cutGetMaxGflopsDeviceId() );
        }

    } else {
        // First initialize OpenGL context, so we can properly set the GL for CUDA.
        // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
        initGL( &argc, argv );

	    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
        if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
            cutilGLDeviceInit(argc, argv);
        } else {
            cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
        }
/*
        int device;
        struct cudaDeviceProp prop;
        cudaGetDevice( &device );
        cudaGetDeviceProperties( &prop, device );
        if( !strncmp( "Tesla", prop.name, 5 ) ) {
            shrLog("This sample needs a card capable of OpenGL and display.\n");
            shrLog("Please choose a different device with the -device=x argument.\n");
            cutilExit(argc, argv);
        }
*/
	}

    // parse arguments
    char *filename;
    if (cutGetCmdLineArgumentstr( argc, (const char**) argv, "file", &filename)) {
        volumeFilename = filename;
    }
    int n;
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "size", &n)) {
        volumeSize.width = volumeSize.height = volumeSize.depth = n;
    }
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "xsize", &n)) {
        volumeSize.width = n;
    }
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "ysize", &n)) {
        volumeSize.height = n;
    }
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "zsize", &n)) {
         volumeSize.depth = n;
    }

    // load volume data
    char* path = shrFindFilePath(volumeFilename, argv[0]);
    if (path == 0) {
        shrLog("Error finding file '%s'\n", volumeFilename);
        exit(EXIT_FAILURE);
    }

    size_t size = volumeSize.width*volumeSize.height*volumeSize.depth*sizeof(VolumeType);
    void *h_volume = loadRawFile(path, size);
    
    initCuda(h_volume, volumeSize);
    free(h_volume);

    cutilCheckError( cutCreateTimer( &timer));

    shrLog("Press '=' and '-' to change density\n"
           "      ']' and '[' to change brightness\n"
           "      ';' and ''' to modify transfer function offset\n"
           "      '.' and ',' to modify transfer function scale\n\n");

    // calculate new grid size
    gridSize = dim3(iDivUp(width, blockSize.x), iDivUp(height, blockSize.y));

    if (g_bQAReadback) {
        g_CheckRender = new CheckBackBuffer(width, height, 4, false);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);

        uint *d_output;
        cutilSafeCall(cudaMalloc((void**)&d_output, width*height*sizeof(uint)));
        cutilSafeCall(cudaMemset(d_output, 0, width*height*sizeof(uint)));

        float modelView[16] = 
        {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 4.0f, 1.0f
        };

        invViewMatrix[0] = modelView[0]; invViewMatrix[1] = modelView[4]; invViewMatrix[2] = modelView[8]; invViewMatrix[3] = modelView[12];
        invViewMatrix[4] = modelView[1]; invViewMatrix[5] = modelView[5]; invViewMatrix[6] = modelView[9]; invViewMatrix[7] = modelView[13];
        invViewMatrix[8] = modelView[2]; invViewMatrix[9] = modelView[6]; invViewMatrix[10] = modelView[10]; invViewMatrix[11] = modelView[14];

        // call CUDA kernel, writing results to PBO
	    copyInvViewMatrix(invViewMatrix, sizeof(float4)*3);
        
        // Start timer 0 and process n loops on the GPU 
        int nIter = 10;
        for (int i = -1; i < nIter; i++)
        {
            if( i == 0 ) {
                cudaThreadSynchronize();
                cutStartTimer(timer); 
            }
            
            render_kernel(gridSize, blockSize, d_output, width, height, density, brightness, transferOffset, transferScale);
        }
        cudaThreadSynchronize();
        cutStopTimer(timer);
        // Get elapsed time and throughput, then log to sample and master logs
        double dAvgTime = cutGetTimerValue(timer)/(nIter * 1000.0);
        shrLogEx(LOGBOTH | MASTER, 0, "volumeRender, Throughput = %.4f MTexels/s, Time = %.5f s, Size = %u Texels, NumDevsUsed = %u, Workgroup = %u\n", 
               (1.0e-6 * width * height)/dAvgTime, dAvgTime, (width * height), 1, blockSize.x * blockSize.y); 
        

        cutilCheckMsg("Error: render_kernel() execution FAILED");
        cutilSafeCall( cudaThreadSynchronize() );

        cutilSafeCall( cudaMemcpy(g_CheckRender->imageData(), d_output, width*height*4, cudaMemcpyDeviceToHost) );
        g_CheckRender->savePPM(sOriginal[g_Index], true, NULL);

        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, THRESHOLD)) {
            shrLog("\nFAILED\n\n");
        } else {
            shrLog("\nPASSED\n\n");
        }

        cudaFree(d_output);
    	freeCudaBuffers();

        if (g_CheckRender) {
            delete g_CheckRender; g_CheckRender = NULL;
        }

    } else {
        // This is the normal rendering path for VolumeRender
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutMouseFunc(mouse);
        glutMotionFunc(motion);
        glutReshapeFunc(reshape);
        glutIdleFunc(idle);

        initPixelBuffer();

        if (g_bQAGLVerify) {
            g_CheckRender = new CheckBackBuffer(width, height, 4);
            g_CheckRender->setPixelFormat(GL_RGBA);
            g_CheckRender->setExecPath(argv[0]);
            g_CheckRender->EnableQAReadback(true);
        }
        atexit(cleanup);

        glutMainLoop();
    }

    cudaThreadExit();
    shrEXIT(argc, (const char**)argv);
}
