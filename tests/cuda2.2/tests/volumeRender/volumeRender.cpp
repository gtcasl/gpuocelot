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
    Volume rendering sample

    This sample loads a 3D volume from disk and displays it using
    ray marching and 3D textures.
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

#include <vector_types.h>
#include <vector_functions.h>
#include <driver_functions.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cuda_gl_interop.h>
#include <rendercheck_gl.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define MAX_EPSILON_ERROR 5.0f

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

char *volumeFilename = "Bucky.raw";
cudaExtent volumeSize = make_cudaExtent(32, 32, 32);

uint width = 512, height = 512;
dim3 blockSize(16, 16);
dim3 gridSize(width / blockSize.x, height / blockSize.y);

float3 viewRotation;
float3 viewTranslation = make_float3(0.0, 0.0, -4.0f);
float invViewMatrix[12];

float density = 0.05f;
float brightness = 1.0f;
float transferOffset = 0.0f;
float transferScale = 1.0f;
bool linearFiltering = true;

GLuint pbo = 0;     // OpenGL pixel buffer object

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
bool g_bFBODisplay = false;

// CheckFBO/BackBuffer class objects
CheckRender       *g_CheckRender = NULL;

#define MAX(a,b) ((a > b) ? a : b)

extern "C" void setTextureFilterMode(bool bLinearFilter);
extern "C" void initCuda(uchar *h_volume, cudaExtent volumeSize);
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
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_output, pbo));

    cutilSafeCall(cudaMemset(d_output, 0, width*height*4));

    // call CUDA kernel, writing results to PBO
    render_kernel(gridSize, blockSize, d_output, width, height, density, brightness, transferOffset, transferScale);

    cutilCheckMsg("kernel failed");

    cutilSafeCall(cudaGLUnmapBufferObject(pbo));
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
    glRasterPos2i(0, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);


    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        // readback for QA testing
        printf("> (Frame %d) Readback BackBuffer\n", frameCount);
        g_CheckRender->readback( width, height );
        g_CheckRender->savePPM(sOriginal[g_Index], true, NULL);
        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, 0.20f)) {
            g_TotalErrors++;
        }
        else
        {
        	printf("TEST PASSED\n");
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
    printf("density = %.2f, brightness = %.2f, transferOffset = %.2f, transferScale = %.2f\n", density, brightness, transferOffset, transferScale);
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

    if (buttonState == 3) {
        // left+middle = zoom
        viewTranslation.z += dy / 100.0;
    } 
    else if (buttonState & 2) {
        // middle = translate
        viewTranslation.x += dx / 100.0;
        viewTranslation.y -= dy / 100.0;
    }
    else if (buttonState & 1) {
        // left = rotate
        viewRotation.x += dy / 5.0;
        viewRotation.y += dx / 5.0;
    }

    ox = x; oy = y;
    glutPostRedisplay();
}

void reshape(int x, int y)
{
    width = x; height = y;
    initPixelBuffer();

    glViewport(0, 0, x, y);

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

	cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
	glDeleteBuffersARB(1, &pbo);

    if (g_CheckRender) {
        delete g_CheckRender; g_CheckRender = NULL;
    }
}

int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

void initGL(int argc, char **argv)
{
    // initialize GLUT callback functions
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("CUDA volume rendering");

    glewInit();
    if (!glewIsSupported("GL_VERSION_2_0 GL_ARB_pixel_buffer_object")) {
        fprintf(stderr, "Required OpenGL extensions missing.");
        exit(-1);
    }
}

void initPixelBuffer()
{
    if (pbo) {
        // delete old buffer
        cutilSafeCall(cudaGLUnregisterBufferObject(pbo));
        glDeleteBuffersARB(1, &pbo);
    }

    // create pixel buffer object for display
    glGenBuffersARB(1, &pbo);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
	glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, width*height*sizeof(GLubyte)*4, 0, GL_STREAM_DRAW_ARB);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

	cutilSafeCall(cudaGLRegisterBufferObject(pbo));

    // calculate new grid size
    gridSize = dim3(iDivUp(width, blockSize.x), iDivUp(height, blockSize.y));
}

// Load raw data from disk
uchar *loadRawFile(char *filename, size_t size)
{
	FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return 0;
    }

	uchar *data = (uchar *) malloc(size);
	size_t read = fread(data, 1, size, fp);
	fclose(fp);

    printf("Read '%s', %d bytes\n", filename, read);

    return data;
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    if (!cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
	{
        g_bQAReadback = true;
        fpsLimit = frameCheckNumber;
    }

    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    initGL( argc, argv );

	// use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilGLDeviceInit(argc, argv);
    else
        cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );

    int device;
    struct cudaDeviceProp prop;
    cudaGetDevice( &device );
    cudaGetDeviceProperties( &prop, device );
    if( !strncmp( "Tesla", prop.name, 5 ) ){
        printf("This sample needs a card capable of OpenGL and display.\n");
        printf("Please choose a different device with the -device=x argument.\n");
        cutilExit(argc, argv);
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
    char* path = cutFindFilePath(volumeFilename, argv[0]);
    if (path == 0) {
        fprintf(stderr, "Error finding file '%s'\n", volumeFilename);
        exit(EXIT_FAILURE);
    }

    size_t size = volumeSize.width*volumeSize.height*volumeSize.depth;
    uchar *h_volume = loadRawFile(path, size);
    initCuda(h_volume, volumeSize);
    cutilCheckError( cutCreateTimer( &timer));
    free(h_volume);

    printf("Press '=' and '-' to change density\n"
           "      ']' and '[' to change brightness\n"
           "      ';' and ''' to modify transfer function offset\n"
           "      '.' and ',' to modify transfer function scale\n");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    initPixelBuffer();

    if (g_bQAReadback) {
        g_CheckRender = new CheckBackBuffer(width, height, 4);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);
    }

    atexit(cleanup);

    glutMainLoop();

    cudaThreadExit();
    return 0;
}
