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
    This example demonstrates how to use the Cuda OpenGL bindings to
    dynamically modify a vertex buffer using a Cuda kernel.

    The steps are:
    1. Create an empty vertex buffer object (VBO)
    2. Register the VBO with Cuda
    3. Map the VBO for writing from Cuda
    4. Run Cuda kernel to modify the vertex positions
    5. Unmap the VBO
    6. Render the results using OpenGL

    Host code
*/

#ifdef _WIN32
#  define WINDOWS_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, GL
#include <GL/glew.h>

#if defined (__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// includes
#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cutil_gl_error.h>
#include <cuda_gl_interop.h>
#include <vector_types.h>
#include <rendercheck_gl.h>

#define MAX_EPSILON_ERROR 10.0f
#define THRESHOLD		  0.30f
// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "simpleGL.ppm",
    NULL
};

const char *sReference[] =
{
    "ref_simpleGL.ppm",
    NULL
};


////////////////////////////////////////////////////////////////////////////////
// constants
const unsigned int window_width = 512;
const unsigned int window_height = 512;

const unsigned int mesh_width = 256;
const unsigned int mesh_height = 256;

// vbo variables
GLuint vbo;
struct cudaGraphicsResource *cuda_vbo_resource;
void *d_vbo_buffer = NULL;

float anim = 0.0;

// mouse controls
int mouse_old_x, mouse_old_y;
int mouse_buttons = 0;
float rotate_x = 0.0, rotate_y = 0.0;
float translate_z = -3.0;

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
bool g_bGLVerify   = false;

// CheckFBO/BackBuffer class objects
CheckRender       *g_CheckRender = NULL;

#define MAX(a,b) ((a > b) ? a : b)

////////////////////////////////////////////////////////////////////////////////
// kernels
//#include <simpleGL_kernel.cu>

extern "C" 
void launch_kernel(float4* pos, unsigned int mesh_width, unsigned int mesh_height, float time);

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
CUTBoolean runTest(int argc, char** argv);
void cleanup();

// GL functionality
CUTBoolean initGL(int *argc, char** argv);
void createVBO(GLuint* vbo, struct cudaGraphicsResource **vbo_res, 
	       unsigned int vbo_res_flags);
void deleteVBO(GLuint* vbo, struct cudaGraphicsResource *vbo_res);

// rendering callbacks
void display();
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);

// Cuda functionality
void runCuda(struct cudaGraphicsResource **vbo_resource);
void runAutoTest();
void checkResultCuda(int argc, char** argv, const GLuint& vbo);

const char *SDK_name = "simpleGL (VBO)";

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	printf("[%s] starting...\n", SDK_name);
    
    if (argc > 1) {
        if (cutCheckCmdLineFlag(argc, (const char **)argv, "qatest") ||
			cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
	    {
		printf("- (automated test no-OpenGL)\n");
		g_bQAReadback = true;
		//			g_bGLVerify = true;	
		fpsLimit = frameCheckNumber;
	    } else if (cutCheckCmdLineFlag(argc, (const char **)argv, "glverify")) {
	    printf("- (automated test OpenGL rendering)\n");
	    g_bGLVerify = true;	
            fpsLimit = frameCheckNumber;
	}
    }
    printf("\n");
    
    runTest(argc, argv);
    
    cudaThreadExit();
    
    cutilExit(argc, argv);
}

void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "AutoTest: Cuda GL Interop (VBO)");
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
        sprintf(fps, "%sCuda GL Interop (VBO): %3.1f fps", 
                ((g_CheckRender && g_CheckRender->IsQAReadback()) ? "AutoTest: " : ""), ifps);  

        glutSetWindowTitle(fps);
        fpsCount = 0; 
        if (g_CheckRender && !g_CheckRender->IsQAReadback()) 
	    fpsLimit = (int)MAX(ifps, 1.f);

        cutilCheckError(cutResetTimer(timer));  

        AutoQATest();
    }
 }

////////////////////////////////////////////////////////////////////////////////
//! Initialize GL
////////////////////////////////////////////////////////////////////////////////
CUTBoolean initGL(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("Cuda GL Interop (VBO)");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(motion);

	// initialize necessary OpenGL extensions
    glewInit();
    if (! glewIsSupported("GL_VERSION_2_0 ")) {
        fprintf(stderr, "ERROR: Support for necessary OpenGL extensions missing.");
        fflush(stderr);
        return CUTFalse;
    }

    // default initialization
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDisable(GL_DEPTH_TEST);

    // viewport
    glViewport(0, 0, window_width, window_height);

    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)window_width / (GLfloat) window_height, 0.1, 10.0);

    CUT_CHECK_ERROR_GL();

    return CUTTrue;
}


////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
CUTBoolean runTest(int argc, char** argv)
{
    // Create the CUTIL timer
    cutilCheckError( cutCreateTimer( &timer));
    
    if (g_bQAReadback) {
		// use command-line specified CUDA device, otherwise use device with highest Gflops/s
		if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
			cutilDeviceInit(argc, argv);
		} else {
			cudaSetDevice( cutGetMaxGflopsDeviceId() );
		}
		
		// create VBO
		createVBO(NULL, NULL, 0);
    } else {
		// First initialize OpenGL context, so we can properly set the GL for CUDA.
		// This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
		if (CUTFalse == initGL(&argc, argv)) {
			return CUTFalse;
		}
		// use command-line specified CUDA device, otherwise use device with highest Gflops/s
		if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
			cutilGLDeviceInit(argc, argv);
		} else {
			cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
		}
		
		// register callbacks
		glutDisplayFunc(display);
		glutKeyboardFunc(keyboard);
		glutMouseFunc(mouse);
		glutMotionFunc(motion);
		
		// create VBO
		createVBO(&vbo, &cuda_vbo_resource, cudaGraphicsMapFlagsWriteDiscard);
    }
    
    if (g_bQAReadback) {
        g_CheckRender = new CheckBackBuffer(window_width, window_height, 4, false);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);

	runAutoTest();
    } else {
	if (g_bGLVerify) {
	    g_CheckRender = new CheckBackBuffer(window_width, window_height, 4);
	    g_CheckRender->setPixelFormat(GL_RGBA);
	    g_CheckRender->setExecPath(argv[0]);
	    g_CheckRender->EnableQAReadback(true);
	}
	
	// run the cuda part
	runCuda(&cuda_vbo_resource);
    }

    // check result of Cuda step
    checkResultCuda(argc, argv, vbo);

    if (!g_bQAReadback) {
	atexit(cleanup);
	
	// start rendering mainloop
	glutMainLoop();
    }

    cudaThreadExit();

	return CUTTrue;
}

////////////////////////////////////////////////////////////////////////////////
//! Run the Cuda part of the computation
////////////////////////////////////////////////////////////////////////////////
void runCuda(struct cudaGraphicsResource **vbo_resource)
{
    // map OpenGL buffer object for writing from CUDA
    float4 *dptr;
    // DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&dptr, vbo));
    cutilSafeCall(cudaGraphicsMapResources(1, vbo_resource, 0));
    size_t num_bytes; 
    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void **)&dptr, &num_bytes,  
						       *vbo_resource));
    //printf("CUDA mapped VBO: May access %ld bytes\n", num_bytes);

    // execute the kernel
    //    dim3 block(8, 8, 1);
    //    dim3 grid(mesh_width / block.x, mesh_height / block.y, 1);
    //    kernel<<< grid, block>>>(dptr, mesh_width, mesh_height, anim);

    launch_kernel(dptr, mesh_width, mesh_height, anim);

    // unmap buffer object
    // DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(vbo));
    cutilSafeCall(cudaGraphicsUnmapResources(1, vbo_resource, 0));
}

////////////////////////////////////////////////////////////////////////////////
//! Run the Cuda part of the computation
////////////////////////////////////////////////////////////////////////////////
void runAutoTest()
{
    // execute the kernel
    launch_kernel((float4 *)d_vbo_buffer, mesh_width, mesh_height, anim);

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckMsg("launch_kernel failed");

    cutilSafeCall( cudaMemcpy( g_CheckRender->imageData(), d_vbo_buffer, mesh_width*mesh_height*sizeof(float), cudaMemcpyDeviceToHost) );
    g_CheckRender->dumpBin((void *)g_CheckRender->imageData(), mesh_width*mesh_height*sizeof(float), "simpleGL.bin");
    if (!g_CheckRender->compareBin2BinFloat("simpleGL.bin", "ref_simpleGL.bin", mesh_width*mesh_height*sizeof(float), MAX_EPSILON_ERROR, THRESHOLD))
       g_TotalErrors++;

    printf("%s\n", (g_TotalErrors > 0) ? "FAILED" : "PASSED");
}

////////////////////////////////////////////////////////////////////////////////
//! Create VBO
////////////////////////////////////////////////////////////////////////////////
void createVBO(GLuint* vbo, struct cudaGraphicsResource **vbo_res, 
	       unsigned int vbo_res_flags)
{
    if (vbo) {
	// create buffer object
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	
	// initialize buffer object
	unsigned int size = mesh_width * mesh_height * 4 * sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	// register this buffer object with CUDA
	// DEPRECATED: cutilSafeCall(cudaGLRegisterBufferObject(*vbo));
	cutilSafeCall(cudaGraphicsGLRegisterBuffer(vbo_res, *vbo, vbo_res_flags));
	
	CUT_CHECK_ERROR_GL();
    } else {
	cutilSafeCall( cudaMalloc( (void **)&d_vbo_buffer, mesh_width*mesh_height*4*sizeof(float) ) );
    }
}

////////////////////////////////////////////////////////////////////////////////
//! Delete VBO
////////////////////////////////////////////////////////////////////////////////
void deleteVBO(GLuint* vbo, struct cudaGraphicsResource *vbo_res)
{
    if (vbo) {
	// unregister this buffer object with CUDA
	//DEPRECATED: cutilSafeCall(cudaGLUnregisterBufferObject(*pbo));
	cudaGraphicsUnregisterResource(vbo_res);
	
	glBindBuffer(1, *vbo);
	glDeleteBuffers(1, vbo);
	
	*vbo = 0;
    } else {
	cudaFree(d_vbo_buffer);
	d_vbo_buffer = NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////
//! Display callback
////////////////////////////////////////////////////////////////////////////////
void display()
{
    cutilCheckError(cutStartTimer(timer));  

    // run CUDA kernel to generate vertex positions
    runCuda(&cuda_vbo_resource);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, translate_z);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    // render from the vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexPointer(4, GL_FLOAT, 0, 0);

    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1.0, 0.0, 0.0);
    glDrawArrays(GL_POINTS, 0, mesh_width * mesh_height);
    glDisableClientState(GL_VERTEX_ARRAY);

    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        // readback for QA testing
        printf("> (Frame %d) Readback BackBuffer\n", frameCount);
        g_CheckRender->readback( window_width, window_height );
        g_CheckRender->savePPM(sOriginal[g_Index], true, NULL);
        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Index], sReference[g_Index], MAX_EPSILON_ERROR, 0.15f)) {
            g_TotalErrors++;
        }
        g_Verify = false;
    }

    glutSwapBuffers();
    glutPostRedisplay();

    anim += 0.01;

    cutilCheckError(cutStopTimer(timer));  
    computeFPS();
}

void cleanup()
{
    cutilCheckError( cutDeleteTimer( timer));

    deleteVBO(&vbo, cuda_vbo_resource);

    if (g_CheckRender) {
        delete g_CheckRender; g_CheckRender = NULL;
    }
}


////////////////////////////////////////////////////////////////////////////////
//! Keyboard events handler
////////////////////////////////////////////////////////////////////////////////
void keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch(key) {
    case(27) :
        exit(0);
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////
//! Mouse event handlers
////////////////////////////////////////////////////////////////////////////////
void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) {
        mouse_buttons |= 1<<button;
    } else if (state == GLUT_UP) {
        mouse_buttons = 0;
    }

    mouse_old_x = x;
    mouse_old_y = y;
    glutPostRedisplay();
}

void motion(int x, int y)
{
    float dx, dy;
    dx = x - mouse_old_x;
    dy = y - mouse_old_y;

    if (mouse_buttons & 1) {
        rotate_x += dy * 0.2;
        rotate_y += dx * 0.2;
    } else if (mouse_buttons & 4) {
        translate_z += dy * 0.01;
    }

    mouse_old_x = x;
    mouse_old_y = y;
}

////////////////////////////////////////////////////////////////////////////////
//! Check if the result is correct or write data to file for external
//! regression testing
////////////////////////////////////////////////////////////////////////////////
void checkResultCuda(int argc, char** argv, const GLuint& vbo)
{
    if (!d_vbo_buffer) {
	//DEPRECATED: cutilSafeCall(cudaGLUnregisterBufferObject(vbo));
	cudaGraphicsUnregisterResource(cuda_vbo_resource);
	
	// map buffer object
	glBindBuffer(GL_ARRAY_BUFFER_ARB, vbo );
	float* data = (float*) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
	
	// check result
	if(cutCheckCmdLineFlag(argc, (const char**) argv, "regression")) {
	    // write file for regression test
	    cutilCheckError(cutWriteFilef("./data/regression.dat",
					  data, mesh_width * mesh_height * 3, 0.0));
	}
	
	// unmap GL buffer object
	if(! glUnmapBuffer(GL_ARRAY_BUFFER)) {
	    fprintf(stderr, "Unmap buffer failed.\n");
	    fflush(stderr);
	}
	
	//DEPRECATED: cutilSafeCall(cudaGLRegisterBufferObject(vbo));
	cutilSafeCall(cudaGraphicsGLRegisterBuffer(&cuda_vbo_resource, vbo, 
						   cudaGraphicsMapFlagsWriteDiscard));
	
	CUT_CHECK_ERROR_GL();
    }
}
