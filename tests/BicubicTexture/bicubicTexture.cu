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

#include <cuda_gl_interop.h>
#include <cutil_inline.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#include "bicubicTexture_kernel.cuh"

#define USE_BUFFER_TEX 0

char *imageFilename = "lena_bw.pgm";

uint width = 512, height = 512;
uint imageWidth, imageHeight;
dim3 blockSize(16, 16);
dim3 gridSize(width / blockSize.x, height / blockSize.y);

enum Mode { MODE_NEAREST, MODE_BILINEAR, MODE_BICUBIC, MODE_FAST_BICUBIC };
Mode mode = MODE_FAST_BICUBIC;
bool drawCurves = false;

cudaArray *d_imageArray = 0;
GLuint pbo = 0;                 // OpenGL pixel buffer object
GLuint displayTex = 0;
GLuint bufferTex = 0;
GLuint fprog;                   // fragment program (shader)

float tx = 9.0f, ty = 10.0f;    // image translation
float scale = 1.0f / 16.0f;     // image scale
float cx, cy;                   // image centre

bool bQATest = false;

void initPixelBuffer();
void runBenchmark(int iterations);

// render image using CUDA
void render(uchar4 *output)
{
    // call CUDA kernel, writing results to PBO memory
    switch(mode) {
    case MODE_NEAREST:
        tex.filterMode = cudaFilterModePoint;
        d_render<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    case MODE_BILINEAR:
        tex.filterMode = cudaFilterModeLinear;
        d_render<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    case MODE_BICUBIC:
        tex.filterMode = cudaFilterModePoint;
        d_renderBicubic<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    case MODE_FAST_BICUBIC:
        tex.filterMode = cudaFilterModeLinear;
        d_renderFastBicubic<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    }
    cutilCheckMsg("kernel failed");
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
    // map PBO to get CUDA device pointer
    uchar4 *d_output;
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_output, pbo));
    render(d_output);
    cutilSafeCall(cudaGLUnmapBufferObject(pbo));

    // display results
    glClear(GL_COLOR_BUFFER_BIT);

#if USE_BUFFER_TEX
    // display using buffer texture
    glBindTexture(GL_TEXTURE_BUFFER_EXT, bufferTex);
    glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, fprog);
    glEnable(GL_FRAGMENT_PROGRAM_ARB);
    glProgramLocalParameterI4iNV(GL_FRAGMENT_PROGRAM_ARB, 0, width, 0, 0, 0);
#else
    // download image from PBO to OpenGL texture
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, displayTex);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexSubImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, 0, 0, width, height, GL_BGRA, GL_UNSIGNED_BYTE, 0);
    glEnable(GL_TEXTURE_RECTANGLE_ARB);
#endif

    // draw textured quad
    glDisable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
    glTexCoord2f(0, height);        glVertex2f(0, 0);
    glTexCoord2f(width, height);    glVertex2f(1, 0);
    glTexCoord2f(width, 0);         glVertex2f(1, 1);
    glTexCoord2f(0, 0);             glVertex2f(0, 1);
    glEnd();
    glDisable(GL_TEXTURE_RECTANGLE_ARB);
    glDisable(GL_FRAGMENT_PROGRAM_ARB);

    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    if (drawCurves) {
        // draw spline curves
        glPushMatrix();
        glScalef(0.25, 0.25, 1.0);

        glTranslatef(0.0, 2.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        plotCurve(w3);

        glTranslatef(1.0, 0.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        plotCurve(w2);

        glTranslatef(1.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        plotCurve(w1);

        glTranslatef(1.0, 0.0, 0.0);
        glColor3f(1.0, 0.0, 1.0);
        plotCurve(w0);

        glPopMatrix();
        glColor3f(1.0, 1.0, 1.0);
    }

    glutSwapBuffers();
    glutReportErrors();
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
            runBenchmark(1);
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
    cutilSafeCall(cudaFreeArray(d_imageArray));
	cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
	glDeleteBuffersARB(1, &pbo);
#if USE_BUFFER_TEX
    glDeleteTextures(1, &bufferTex);
#else
    glDeleteTextures(1, &displayTex);
#endif
    glDeleteProgramsARB(1, &fprog);
    printf("Test PASSED!\n");
}

int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
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
	glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, width*height*sizeof(uchar4), 0, GL_STREAM_DRAW_ARB);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

	cutilSafeCall(cudaGLRegisterBufferObject(pbo));

#if USE_BUFFER_TEX
    // create buffer texture, attach to pbo
    if (bufferTex) {
        glDeleteTextures(1, &bufferTex);
    }
    glGenTextures(1, &bufferTex);
    glBindTexture(GL_TEXTURE_BUFFER_EXT, bufferTex);
    glTexBufferEXT(GL_TEXTURE_BUFFER_EXT, GL_RGBA8, pbo);
    glBindTexture(GL_TEXTURE_BUFFER_EXT, 0);
#else
    // create texture for display
    if (displayTex) {
        glDeleteTextures(1, &displayTex);
    }
    glGenTextures(1, &displayTex);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, displayTex);
    glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, 0);
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
        render(d_output);
    }

    cudaThreadSynchronize();
    cutilCheckError(cutStopTimer(timer));  
    float time = cutGetTimerValue(timer) / (float) iterations;

    cutilSafeCall(cudaGLUnmapBufferObject(pbo));

    printf("time: %0.3f ms, %f Mpixels/sec\n", time, (width*height / (time * 0.001f)) / 1e6);    
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

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
		cutilDeviceInit(argc, argv);
	else
		cudaSetDevice( cutGetMaxGflopsDeviceId() );

    // parse arguments
    char *filename;
    bool benchmark = true;

    if (argc > 1) {
        if (cutGetCmdLineArgumentstr( argc, (const char**) argv, "file", &filename)) {
            imageFilename = filename;
        }
        benchmark = cutCheckCmdLineFlag(argc, (const char**) argv, "benchmark") != 0;
        if (cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) {
            benchmark = true;
        }
    }

    if (cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest")) {
        benchmark = false;
    }

    // load image from disk
    uchar* h_data = NULL;
    char* imagePath = cutFindFilePath(imageFilename, argv[0]);
    if (imagePath == 0)
        exit(EXIT_FAILURE);
    cutilCheckError(cutLoadPGMub(imagePath, &h_data, &imageWidth, &imageHeight));

    printf("Loaded '%s', %d x %d pixels\n", imageFilename, imageWidth, imageHeight);

    cx = imageWidth * 0.5f;
    cy = imageHeight * 0.5f;

    // allocate array and copy image data
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsigned);
    cutilSafeCall( cudaMallocArray(&d_imageArray, &channelDesc, imageWidth, imageHeight) ); 
    uint size = imageWidth * imageHeight * sizeof(uchar);
    cutilSafeCall( cudaMemcpyToArray(d_imageArray, 0, 0, h_data, size, cudaMemcpyHostToDevice) );
    cutFree(h_data);

    // set texture parameters
    tex.addressMode[0] = cudaAddressModeClamp;
    tex.addressMode[1] = cudaAddressModeClamp;
    tex.filterMode = cudaFilterModeLinear;
    tex.normalized = false;    // access with integer texture coordinates

    // Bind the array to the texture
    cutilSafeCall( cudaBindTextureToArray(tex, d_imageArray, channelDesc) );

    printf(
        "Press '=' and '-' to zoom\n"
        "Press number keys to change filtering mode:\n"
        "1 - nearest filtering\n"
        "2 - bilinear filtering\n"
        "3 - bicubic filtering\n"
        "4 - fast bicubic filtering\n"
        );


    // initialize GLUT callback functions
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("CUDA bicubic texture filtering");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    initMenus();

    atexit(cleanup);

    glewInit();
    if (!glewIsSupported("GL_VERSION_2_0 "
                         "GL_ARB_pixel_buffer_object "
                         "GL_EXT_texture_buffer_object "
                         "GL_NV_gpu_program4 "
                         )) {
        fprintf(stderr, "Required OpenGL extensions missing.");
        exit(-1);
    }
    initPixelBuffer();
    fprog = compileASMShader(GL_FRAGMENT_PROGRAM_ARB, shaderCode);
    if (!fprog) exit(0);

    if (benchmark) {
        runBenchmark(1);
//        cudaThreadExit();
        exit(0);
    }

    glutMainLoop();

    cudaThreadExit();
    return 0;
}
