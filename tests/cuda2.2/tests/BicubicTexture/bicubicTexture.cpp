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
* MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE
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
    Bicubic texture filtering sample
    sgreen 6/2008

    This sample demonstrates how to efficiently implement bicubic texture
    filtering in CUDA.

    Bicubic filtering is a higher order interpolation method that produces
    smoother results than bilinear interpolation:
    http://en.wikipedia.org/wiki/Bicubic

    It requires reading a 4 x 4 pixel neighbourhood rather than the
    2 x 2 area required by bilinear filtering.

    Current graphics hardware doesn't support bicubic filtering natively,
    but it is possible to compose a bicubic filter using just 4 bilinear
    lookups by offsetting the sample position within each texel and weighting
    the samples correctly. The only disadvantage to this method is that the
    hardware only maintains 9-bits of filtering precision within each texel.

    See "Fast Third-Order Texture Filtering", Sigg & Hadwiger, GPU Gems 2:
    http://developer.nvidia.com/object/gpu_gems_2_home.html

    v1.1 - updated to include the brute force method using 16 texture lookups.
    
    Example performance results from GeForce 8800 GTS:
    Bilinear     - 5500 MPixels/sec
    Bicubic      - 1400 MPixels/sec
    Fast Bicubic - 2100 MPixels/sec
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

#include <cuda_runtime_api.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cutil_gl_error.h>
#include <cuda_gl_interop.h>

#include <rendercheck_gl.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define USE_BUFFER_TEX 0
#define MAX(a,b) ((a < b) ? b : a)

// Auto-Verification Code
const int frameCheckNumber = 4;
int       fpsCount = 0;        // FPS count for averaging
int       fpsLimit = 4;        // FPS limit for sampling
int       g_Index  = 0;
unsigned int frameCount = 0;
unsigned int g_TotalErrors = 0;
unsigned int timer = 0;
bool g_bBenchmark  = false;
bool g_bQAReadback = false;
bool g_bOpenGLQA   = false;
bool g_Verify      = false;

// CheckFBO/BackBuffer class objects
CheckRender        *g_CheckRender       = NULL;

#define MAX_EPSILON_ERROR 5.0f

static char *sSDKsample = "CUDA BicubicTexture"; 

// Define the files that are to be save and the reference images for validation
const char *sFilterMode[] =
{
    "Nearest",
    "Bilinear",
    "Bicubic",
    "Fast Bicubic",
    NULL
};

const char *sOriginal[] =
{
    "01_nearest.ppm",
    "02_bilinear.ppm",
    "03_bicubic.ppm",
    "04_fastbicubic.ppm",
    NULL
};

const char *sReference[] =
{
    "01_nearest.ppm",
    "02_bilinear.ppm",
    "03_bicubic.ppm",
    "04_fastbicubic.ppm",
    NULL
};

char *imageFilename = "lena_bw.pgm";

uint width = 512, height = 512;
uint imageWidth, imageHeight;
dim3 blockSize(16, 16);
dim3 gridSize(width / blockSize.x, height / blockSize.y);

enum Mode { MODE_NEAREST, MODE_BILINEAR, MODE_BICUBIC, MODE_FAST_BICUBIC };
int mode = MODE_FAST_BICUBIC;

bool drawCurves = false;

GLuint pbo        = 0;          // OpenGL pixel buffer object
GLuint displayTex = 0;
GLuint bufferTex  = 0;
GLuint fprog;                   // fragment program (shader)

float tx = 9.0f, ty = 10.0f;    // image translation
float scale = 1.0f / 16.0f;     // image scale
float cx, cy;                   // image centre

void display();
void displayImage();
void initGLBuffers();
void runBenchmark(int iterations);
void cleanup();

#define GL_TEXTURE_TYPE GL_TEXTURE_RECTANGLE_ARB
//#define GL_TEXTURE_TYPE GL_TEXTURE_2D

extern "C" void initGL(int argc, char **argv);
extern "C" void loadImageData(int argc, char **argv);

extern "C" void initTexture(int imageWidth, int imageHeight, uchar *h_data);
extern "C" void freeTexture();
extern "C" void render( int width, int height, float tx, float ty, float scale, float cx, float cy, 
                        dim3 blockSize, dim3 gridSize, int mode, uchar4 *output);


// w0, w1, w2, and w3 are the four cubic B-spline basis functions
float bspline_w0(float a)
{
    return (1.0f/6.0f)*(a*(a*(-a + 3.0f) - 3.0f) + 1.0f);   // optimized
}

float bspline_w1(float a)
{
    return (1.0f/6.0f)*(a*a*(3.0f*a - 6.0f) + 4.0f);
}

float bspline_w2(float a)
{
    return (1.0f/6.0f)*(a*(a*(-3.0f*a + 3.0f) + 3.0f) + 1.0f);
}

float bspline_w3(float a)
{
    return (1.0f/6.0f)*(a*a*a);
}


void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "AutoTest: %s <%s>", sSDKsample, sFilterMode[mode] );
	    glutSetWindowTitle(temp);

        mode++;

	if (mode > MODE_FAST_BICUBIC) {
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
        sprintf(fps, "%s %s <%s>: %3.1f fps", "", sSDKsample, sFilterMode[mode], ifps);  

        glutSetWindowTitle(fps);
        fpsCount = 0; 

        cutilCheckError(cutResetTimer(timer));  

        AutoQATest();
    }
}

void plotCurve(float (*func)(float))
{
    const int steps = 100;
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<steps; i++) {
        float x = i / (float) (steps-1);
        glVertex2f(x, func(x));
    }
    glEnd();
}

// display results using OpenGL (called by GLUT)
void display()
{
    cutilCheckError(cutStartTimer(timer));  

    // map PBO to get CUDA device pointer
    uchar4 *d_output;
    cutilSafeCall( cudaGLMapBufferObject((void**)&d_output, pbo) );
    render( imageWidth, imageHeight, tx, ty, scale, cx, cy, 
            blockSize, gridSize, mode, d_output );
    cutilSafeCall( cudaGLUnmapBufferObject(pbo) );

	// Common diplay path
	{
		// display results
		glClear(GL_COLOR_BUFFER_BIT);

#if USE_BUFFER_TEX
		// display using buffer texture
		glBindTexture(GL_TEXTURE_BUFFER_ARB, bufferTex);
		glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, fprog);
		glEnable(GL_FRAGMENT_PROGRAM_ARB);
		glProgramLocalParameterI4iNV(GL_FRAGMENT_PROGRAM_ARB, 0, width, 0, 0, 0);
#else
		// download image from PBO to OpenGL texture
		glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
		glBindTexture  (GL_TEXTURE_TYPE, displayTex);
		glPixelStorei  (GL_UNPACK_ALIGNMENT, 1);
		glTexSubImage2D(GL_TEXTURE_TYPE,
						0, 0, 0, width, height, GL_BGRA, GL_UNSIGNED_BYTE, 0);
		glEnable(GL_TEXTURE_TYPE);
#endif

		// draw textured quad
		glDisable(GL_DEPTH_TEST);
		glBegin(GL_QUADS);
		glTexCoord2f(0    , height);  glVertex2f(0, 0);
		glTexCoord2f(width, height);  glVertex2f(1, 0);
		glTexCoord2f(width, 0     );  glVertex2f(1, 1);
		glTexCoord2f(0    , 0     );  glVertex2f(0, 1);
		glEnd();
		glDisable(GL_TEXTURE_TYPE);
		glDisable(GL_FRAGMENT_PROGRAM_ARB);

		glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

		if (drawCurves) {
			// draw spline curves
			glPushMatrix();
			glScalef(0.25, 0.25, 1.0);

			glTranslatef(0.0, 2.0, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			plotCurve(bspline_w3);

			glTranslatef(1.0, 0.0, 0.0);
			glColor3f(0.0, 1.0, 0.0);
			plotCurve(bspline_w2);

			glTranslatef(1.0, 0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			plotCurve(bspline_w1);

			glTranslatef(1.0, 0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			plotCurve(bspline_w0);

			glPopMatrix();
			glColor3f(1.0, 1.0, 1.0);
		}
	}

    glutSwapBuffers();
    glutReportErrors();

    cutilCheckError(cutStopTimer(timer));  

    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        // readback for QA testing
        printf("> (Frame %d) Readback\n", frameCount);
		g_CheckRender->readback( width, height, pbo );
        g_CheckRender->savePPM(sOriginal[mode], true, NULL);
        if (!g_CheckRender->PPMvsPPM(sOriginal[mode], sReference[mode], MAX_EPSILON_ERROR, 0.15f)) {
            g_TotalErrors++;
        }
        g_Verify = false;
    }

    computeFPS();
}

// GLUT callback functions
void idle()
{
    glutPostRedisplay();
}

void keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch(key) {
        case 27:
            cleanup();
            exit(0);
            break;
        case '1':
            mode = MODE_NEAREST;
            break;
        case '2':
            mode = MODE_BILINEAR;
            break;
        case '3':
            mode = MODE_BICUBIC;
            break;
        case '4':
            mode = MODE_FAST_BICUBIC;
            break;
        case '=':
        case '+':
            scale *= 0.5f;
            break;
        case '-':
            scale *= 2.0f;
            break;
        case 'r':
            scale = 1.0f;
            tx = ty = 0.0f;
            break;
        case 'd':
            printf("%f, %f, %f\n", tx, ty, scale);
        case 'b':
            runBenchmark(500);
            break;
        case 'c':
            drawCurves ^= 1;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int ox, oy;
int buttonState = 0;

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
        buttonState |= 1<<button;
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

    if (buttonState & 1) {
        // left = translate
        tx -= dx*scale;
        ty -= dy*scale;
    }
    else if (buttonState & 2) {
        // middle = zoom
        scale -= dy / 1000.0;
    }

    ox = x; oy = y;
    glutPostRedisplay();
}

void reshape(int x, int y)
{
    width = x; height = y;

    initGLBuffers();

    glViewport(0, 0, x, y);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0); 
}

void cleanup()
{
    freeTexture();
    cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
    glDeleteBuffersARB(1, &pbo);

#if USE_BUFFER_TEX
    glDeleteTextures(1, &bufferTex);
    glDeleteProgramsARB(1, &fprog);
#else
    glDeleteTextures(1, &displayTex);
#endif

    if (g_CheckRender) {
        delete g_CheckRender; g_CheckRender = NULL;
    }
}

int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

void initGLBuffers()
{
    if (pbo) {
        // delete old buffer
        cutilSafeCall(cudaGLUnregisterBufferObject(pbo));
        glDeleteBuffersARB(1, &pbo);
    }

    // create pixel buffer object for display
    glGenBuffersARB(1, &pbo);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, width*height*sizeof(uchar4), 0, GL_STREAM_DRAW_ARB);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    cutilSafeCall(cudaGLRegisterBufferObject(pbo));

#if USE_BUFFER_TEX
    // create buffer texture, attach to pbo
    if (bufferTex) {
        glDeleteTextures(1, &bufferTex);
    }
    glGenTextures(1, &bufferTex);
    glBindTexture(GL_TEXTURE_BUFFER_ARB, bufferTex);
    glTexBufferEXT(GL_TEXTURE_BUFFER_ARB, GL_RGBA8, pbo);
    glBindTexture(GL_TEXTURE_BUFFER_ARB, 0);
#else
    // create texture for display
    if (displayTex) {
        glDeleteTextures(1, &displayTex);
    }
    glGenTextures(1, &displayTex);
    glBindTexture  (GL_TEXTURE_TYPE, displayTex);
    glTexImage2D   (GL_TEXTURE_TYPE, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_TYPE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_TYPE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture  (GL_TEXTURE_TYPE, 0);
#endif

    // calculate new grid size
    gridSize = dim3(iDivUp(width, blockSize.x), iDivUp(height, blockSize.y));
}

void mainMenu(int i)
{
    keyboard(i, 0, 0);
}

void initMenus()
{
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Nearest filtering [1]", '1');
    glutAddMenuEntry("Bilinear filtering [2]", '2');
    glutAddMenuEntry("Bicubic filtering [3]", '3');
    glutAddMenuEntry("Fast Bicubic filtering [4]", '4');
    glutAddMenuEntry("Zoom in [=]", '=');
    glutAddMenuEntry("Zoom out [-]", '-');
    glutAddMenuEntry("Benchmark [b]", 'b');
    glutAddMenuEntry("Quit [esc]", 27);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void runBenchmark(int iterations)
{
    unsigned int timer;
    cutilCheckError(cutCreateTimer(&timer));

    uchar4 *d_output;
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_output, pbo));

    cutilCheckError(cutStartTimer(timer));  
    for (int i = 0; i < iterations; ++i)
    {
        render( imageWidth, imageHeight, tx, ty, scale, cx, cy, 
                blockSize, gridSize, mode, d_output);
    }

    cudaThreadSynchronize();
    cutilCheckError(cutStopTimer(timer));  
    float time = cutGetTimerValue(timer) / (float) iterations;

    cutilSafeCall(cudaGLUnmapBufferObject(pbo));

    printf("time: %0.3f ms, %f Mpixels/sec\n", time, (width*height / (time * 0.001f)) / 1e6);    
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

    g_CheckRender       = new CheckBackBuffer(imageWidth, imageHeight, 4, false);
    g_CheckRender->setExecPath(argv[0]);

    uchar4 *d_output;
    cutilSafeCall( cudaMalloc( (void **)&d_output, imageWidth*imageHeight*4 ) );

    for (int mode=0; mode < 4; mode++) {
        printf("AutoTest: %s <%s>\n", sSDKsample, sFilterMode[mode] );
        render( imageWidth, imageHeight, tx, ty, scale, cx, cy, 
                blockSize, gridSize, mode, d_output);
        // check if kernel execution generated an error
        cutilCheckMsg("Error: render (bicubicTexture) Kernel execution failed!");
        cutilSafeCall( cudaThreadSynchronize() );

        cudaMemcpy(g_CheckRender->imageData(), d_output, imageWidth*imageHeight*4, cudaMemcpyDeviceToHost);

        g_CheckRender->savePPM(sOriginal[mode], false, NULL);

        if (!g_CheckRender->PPMvsPPM(sOriginal[mode], sReference[mode], MAX_EPSILON_ERROR, 0.15f)) {
            g_TotalErrors++;
        }
    }

    cutilSafeCall( cudaFree( d_output ) );
    delete g_CheckRender;

    if (!g_TotalErrors) 
        printf("TEST PASSED!\n");
    else 
        printf("TEST FAILED!\n");
}



// fragment program for reading from buffer texture
static const char *shaderCode = 
"!!NVfp4.0\n"
"INT PARAM width = program.local[0];\n"
"INT TEMP index;\n"
"FLR.S index, fragment.texcoord;\n"
"MAD.S index.x, index.y, width, index.x;\n" // compute 1D index from 2D coords
"TXF result.color, index.x, texture[0], BUFFER;\n"
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

void runCUDASample(int argc, char **argv)
{
    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    initGL( argc, argv );

    printf("%s ", sSDKsample);
    if (g_bOpenGLQA) {
        printf("[OpenGL Readback Comparisons] ");
        printf("\n");
        mode = MODE_NEAREST;
    }

    if (g_bOpenGLQA) {
        g_CheckRender = new CheckBackBuffer(width, height, 4);
	    g_CheckRender->setPixelFormat(GL_RGBA8);
	    g_CheckRender->setExecPath(argv[0]);
	    g_CheckRender->EnableQAReadback(true);
    }

    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );

    // Create the timer (for fps measurement)
    cutilCheckError( cutCreateTimer( &timer));

    // load image from disk
    loadImageData(argc, argv);

    printf(
        "Press '=' and '-' to zoom\n"
        "Press number keys to change filtering mode:\n"
        "1 - nearest filtering\n"
        "2 - bilinear filtering\n"
        "3 - bicubic filtering\n"
        "4 - fast bicubic filtering\n"
        );

    initGLBuffers();

#if USE_BUFFER_TEX
    fprog = compileASMShader(GL_FRAGMENT_PROGRAM_ARB, shaderCode);
    if (!fprog) exit(0);
#endif
}

void initGL( int argc, char **argv )
{
    // initialize GLUT callback functions
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("CUDA bicubic texture filtering");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    initMenus();

    glewInit();
    if (!glewIsSupported("GL_VERSION_2_0 "
                         "GL_ARB_pixel_buffer_object "
                         )) 
    {
        fprintf(stderr, "Required OpenGL extensions are missing.");
        exit(-1);
    }
#if USE_BUFFER_TEX
    if (!glewIsSupported("GL_ARB_texture_buffer_object")) {
       fprintf(stderr, "OpenGL extension: GL_ARB_texture_buffer_object missing.\n");
       exit(-1);
    }
    if (!glewIsSupported("GL_EXT_gpu_program4")) {
       fprintf(stderr, "OpenGL extension: GL_EXT_gpu_program4 missing.\n");
       exit(-1);
    }
#endif
}

void loadImageData(int argc, char **argv)
{
    // load image from disk
    uchar* h_data = NULL;
    char* imagePath = cutFindFilePath(imageFilename, argv[0]);
    if (imagePath == 0)
        exit(EXIT_FAILURE);

    cutilCheckError(cutLoadPGMub(imagePath, &h_data, &imageWidth, &imageHeight));

    printf("Loaded '%s', %d x %d pixels\n", imageFilename, imageWidth, imageHeight);

    cx = imageWidth * 0.5f;
    cy = imageHeight * 0.5f;

    // initialize texture
    initTexture(imageWidth, imageHeight, h_data);
}


////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    // parse arguments
    char *filename;
 	if (cutGetCmdLineArgumentstr( argc, (const char**) argv, "file", &filename)) {
        imageFilename = filename;
    }
    g_bBenchmark = (cutCheckCmdLineFlag(argc, (const char**) argv, "benchmark") != 0);

    if (!cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest") ||
        cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
    {
        g_bQAReadback = true;
        fpsLimit = frameCheckNumber;
    }
    if (cutCheckCmdLineFlag(argc, (const char **)argv, "glverify"))
    {
        g_bOpenGLQA = true;
    }


    // Running CUDA kernels without OpenGL visualization
    if (g_bQAReadback) {
        runAutoTest(argc, argv);
        cutilExit(argc, argv);
        exit(0);
    }

    // Running test as as a benchmark
    if (g_bBenchmark) {
        runBenchmark(500);
        printf("Benchmark complete\n");
        printf("Test PASSED\n");
        cutilCheckError( cutDeleteTimer( timer) );

        cutilExit(argc, argv);
        exit(0);
    }

    // This is the normal test with OpenGL visualization
    runCUDASample(argc, argv);
    glutMainLoop();
    cutilCheckError( cutDeleteTimer( timer) );
    cudaThreadExit();
    cutilExit(argc, argv);

    return 0;
}
