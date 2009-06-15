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
    3D texture sample

    This sample loads a 3D volume from disk and displays slices through it
    using 3D texture lookups.
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

#include "simpleTexture3D_kernel.cu"

const char *volumeFilename = "Bucky.raw";
const cudaExtent volumeSize = make_cudaExtent(32, 32, 32);

const uint width = 512, height = 512;
const dim3 blockSize(16, 16, 1);
const dim3 gridSize(width / blockSize.x, height / blockSize.y);

float w = 0.5;  // texture coordinate in z

cudaArray *d_volumeArray = 0;
GLuint pbo;     // OpenGL pixel buffer object

bool linearFiltering = true;
bool animate = true;
unsigned int count = 0;
unsigned int limit = 2;
bool runTest = false;

// render image using CUDA
void render()
{
    // map PBO to get CUDA device pointer
    uint *d_output;
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_output, pbo));

    // call CUDA kernel, writing results to PBO
    d_render<<<gridSize, blockSize>>>(d_output, width, height, w);
    cutilCheckMsg("kernel failed");

    cutilSafeCall(cudaGLUnmapBufferObject(pbo));
}

// display results using OpenGL (called by GLUT)
void display()
{
    render();

    // display results
    glClear(GL_COLOR_BUFFER_BIT);

    // draw image from PBO
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(0, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
    glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    glutSwapBuffers();
    glutReportErrors();
    
    ++count;
    if(count >= limit)
    {
    	count = 0;
    	if(runTest)
    	{
    		exit(0);
    	}
    }
    
}

void idle()
{
    if (animate) {
        w += 0.01f;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 27:
            exit(0);
            break;
        case '=':
        case '+':
            w += 0.01;
            break;
        case '-':
            w -= 0.01;
            break;
        case 'f':
            linearFiltering = !linearFiltering;
            tex.filterMode = linearFiltering ? cudaFilterModeLinear : cudaFilterModePoint;
            break;
        case ' ':
            animate = !animate;
            break;
        default:
            break;
    }
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

void initCuda(const uchar *h_volume, cudaExtent volumeSize)
{
    // create 3D array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<uchar>();
    cutilSafeCall( cudaMalloc3DArray(&d_volumeArray, &channelDesc, volumeSize) );

    // copy data to 3D array
    cudaMemcpy3DParms copyParams = {0};
    copyParams.srcPtr   = make_cudaPitchedPtr((void*)h_volume, volumeSize.width*sizeof(uchar), volumeSize.width, volumeSize.height);
    copyParams.dstArray = d_volumeArray;
    copyParams.extent   = volumeSize;
    copyParams.kind     = cudaMemcpyHostToDevice;
    cutilSafeCall( cudaMemcpy3D(&copyParams) );

    // set texture parameters
    tex.normalized = true;                      // access with normalized texture coordinates
    tex.filterMode = cudaFilterModeLinear;      // linear interpolation
    tex.addressMode[0] = cudaAddressModeWrap;   // wrap texture coordinates
    tex.addressMode[1] = cudaAddressModeWrap;
    tex.addressMode[2] = cudaAddressModeWrap;

    // bind array to 3D texture
    cutilSafeCall(cudaBindTextureToArray(tex, d_volumeArray, channelDesc));
}

void cleanup()
{
	cutilSafeCall(cudaGLUnregisterBufferObject(pbo));    
	glDeleteBuffersARB(1, &pbo);
}

void initOpenGL()
{
    // create pixel buffer object
    glGenBuffersARB(1, &pbo);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, pbo);
	glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, width*height*sizeof(GLubyte)*4, 0, GL_STREAM_DRAW_ARB);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

	cutilSafeCall(cudaGLRegisterBufferObject(pbo));
	printf("Test PASSED\n");
}

// Load raw data from disk
uchar *loadRawFile(const char *filename, size_t size)
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
	// use command-line specified CUDA device, otherwise use device with highest Gflops/s
	if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
	{
		cutilDeviceInit(argc, argv);
	}
	else
	{
		cudaSetDevice( cutGetMaxGflopsDeviceId() );
	}

	runTest = !cutCheckCmdLineFlag(argc, (const char**)argv, "noqatest");

    // load volume data
    const char* path = cutFindFilePath(volumeFilename, argv[0]);
    if (path == 0) {
        fprintf(stderr, "Error finding file '%s'\n", volumeFilename);
        exit(EXIT_FAILURE);
    }

    size_t size = volumeSize.width*volumeSize.height*volumeSize.depth;
    uchar *h_volume = loadRawFile(path, size);
    initCuda(h_volume, volumeSize);
    free(h_volume);

    printf("Press space to toggle animation\n"
           "Press '+' and '-' to change displayed slice\n");

    // initialize GLUT callback functions
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("CUDA 3D texture");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glewInit();
    if (!glewIsSupported("GL_VERSION_2_0 GL_ARB_pixel_buffer_object")) {
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
