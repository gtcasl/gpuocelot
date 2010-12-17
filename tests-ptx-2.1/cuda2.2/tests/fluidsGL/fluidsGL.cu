/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <cufft.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cuda_gl_interop.h>
//#include <rendercheck_gl.h>


#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "fluidsGL_kernels.cuh"

#define MAX_EPSILON_ERROR 1.0f

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "fluidsGL.ppm",
    NULL
};

const char *sReference[] =
{
    "ref_fluidsGL.ppm",
    NULL
};

// CUDA example code that implements the frequency space version of 
// Jos Stam's paper 'Stable Fluids' in 2D. This application uses the 
// CUDA FFT library (CUFFT) to perform velocity diffusion and to 
// force non-divergence in the velocity field at each time step. It uses 
// CUDA-OpenGL interoperability to update the particle field directly
// instead of doing a copy to system memory before drawing. Texture is
// used for automatic bilinear interpolation at the velocity advection step. 

#if 1
#define DIM    64        // Square size of solver domain
#else
#define DIM    512       // Square size of solver domani
#endif
#define DS    (DIM*DIM)  // Total domain size
#define CPADW (DIM/2+1)  // Padded width for real->complex in-place FFT
#define RPADW (2*(DIM/2+1))  // Padded width for real->complex in-place FFT
#define PDS   (DIM*CPADW) // Padded total domain size

#define DT     0.09f     // Delta T for interative solver
#define VIS    0.0025f   // Viscosity constant
#define FORCE (5.8f*DIM) // Force scale factor 
#define FR     4         // Force update radius

#define TILEX 64 // Tile width
#define TILEY 64 // Tile height
#define TIDSX 64 // Tids in X
#define TIDSY 4  // Tids in Y

void cleanup(void);       

// CUFFT plan handle
static cufftHandle planr2c;
static cufftHandle planc2r;
static cData *vxfield = NULL;
static cData *vyfield = NULL;

cData *hvfield = NULL;
cData *dvfield = NULL;
static int wWidth = max(512,DIM);
static int wHeight = max(512,DIM);

static int clicked = 0;
static int fpsCount = 0;
static int fpsLimit = 1;
unsigned int timer;

// Particle data
GLuint vbo = 0;                 // OpenGL vertex buffer object
static cData *particles = NULL; // particle positions in host memory
static int lastx = 0, lasty = 0;

// Texture pitch
size_t tPitch = 0; // Now this is compatible with gcc in 64-bit

bool				  g_bQAReadback     = false;
bool				  g_bQAAddTestForce = true;
int					  g_iFrameToCompare = 4;
int                   frame = 0;
int                   g_TotalErrors     = 0;

// CheckFBO/BackBuffer class objects
//CheckRender       *g_CheckRender = NULL;

void autoTest();


void addForces(cData *v, int dx, int dy, int spx, int spy, float fx, float fy, int r) { 

    dim3 tids(2*r+1, 2*r+1);
    
    addForces_k<<<1, tids>>>(v, dx, dy, spx, spy, fx, fy, r, tPitch);
    cutilCheckMsg("addForces_k failed.");
}

void advectVelocity(cData *v, float *vx, float *vy,
                    int dx, int pdx, int dy, float dt) { 
    
    dim3 grid((dx/TILEX)+(!(dx%TILEX)?0:1), (dy/TILEY)+(!(dy%TILEY)?0:1));

    dim3 tids(TIDSX, TIDSY);

    updateTexture(v, DIM*sizeof(cData), DIM, tPitch);
    advectVelocity_k<<<grid, tids>>>(v, vx, vy, dx, pdx, dy, dt, TILEY/TIDSY);

    cutilCheckMsg("advectVelocity_k failed.");
}

void diffuseProject(cData *vx, cData *vy, int dx, int dy, float dt,
                    float visc) { 
    // Forward FFT
    cufftExecR2C(planr2c, (cufftReal*)vx, (cufftComplex*)vx); 
    cufftExecR2C(planr2c, (cufftReal*)vy, (cufftComplex*)vy);

    uint3 grid = make_uint3((dx/TILEX)+(!(dx%TILEX)?0:1), 
                            (dy/TILEY)+(!(dy%TILEY)?0:1), 1);

    uint3 tids = make_uint3(TIDSX, TIDSY, 1);
    
    diffuseProject_k<<<grid, tids>>>(vx, vy, dx, dy, dt, visc, TILEY/TIDSY);
    cutilCheckMsg("diffuseProject_k failed.");

    // Inverse FFT
    cufftExecC2R(planc2r, (cufftComplex*)vx, (cufftReal*)vx); 
    cufftExecC2R(planc2r, (cufftComplex*)vy, (cufftReal*)vy);
}

void updateVelocity(cData *v, float *vx, float *vy, 
                    int dx, int pdx, int dy) { 

    dim3 grid((dx/TILEX)+(!(dx%TILEX)?0:1), (dy/TILEY)+(!(dy%TILEY)?0:1));

    dim3 tids(TIDSX, TIDSY);

    updateVelocity_k<<<grid, tids>>>(v, vx, vy, dx, pdx, dy, TILEY/TIDSY, tPitch);
    cutilCheckMsg("updateVelocity_k failed.");
}

void advectParticles(GLuint buffer, cData *v, int dx, int dy, float dt) {
    
    dim3 grid((dx/TILEX)+(!(dx%TILEX)?0:1), (dy/TILEY)+(!(dy%TILEY)?0:1));

    dim3 tids(TIDSX, TIDSY);

    cData *p;
    cudaGLMapBufferObject((void**)&p, buffer);
    cutilCheckMsg("cudaGLMapBufferObject failed");
   
    advectParticles_k<<<grid, tids>>>(p, v, dx, dy, dt, TILEY/TIDSY, tPitch);
    cutilCheckMsg("advectParticles_k failed.");
    
    cudaGLUnmapBufferObject(buffer);
    cutilCheckMsg("cudaGLUnmapBufferObject failed");
}

void display(void) {  
   cutilCheckError(cutStartTimer(timer));  
    
   // simulate fluid
   advectVelocity(dvfield, (float*)vxfield, (float*)vyfield, DIM, RPADW, DIM, DT);
   diffuseProject(vxfield, vyfield, CPADW, DIM, DT, VIS);
   updateVelocity(dvfield, (float*)vxfield, (float*)vyfield, DIM, RPADW, DIM);
   advectParticles(vbo, dvfield, DIM, DIM, DT);
   
   // render points from vertex buffer
   glClear(GL_COLOR_BUFFER_BIT);
   glColor4f(0,1,0,0.5f); glPointSize(1);
   glEnable(GL_POINT_SMOOTH);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glEnableClientState(GL_VERTEX_ARRAY);    
   glDisable(GL_DEPTH_TEST);
   glDisable(GL_CULL_FACE); 
   glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
   glVertexPointer(2, GL_FLOAT, 0, NULL);
   glDrawArrays(GL_POINTS, 0, DS);
   glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
   glDisableClientState(GL_VERTEX_ARRAY); 
   glDisableClientState(GL_TEXTURE_COORD_ARRAY); 
   glDisable(GL_TEXTURE_2D);

   // Finish timing before swap buffers to avoid refresh sync
   cutilCheckError(cutStopTimer(timer));  
   glutSwapBuffers();
    
   fpsCount++;
   if (fpsCount == fpsLimit) {
       char fps[256];
       float ifps = 1.f / (cutGetAverageTimerValue(timer) / 1000.f);
       sprintf(fps, "Cuda/GL Stable Fluids (%d x %d): %3.1f fps", DIM, DIM, ifps);  
       glutSetWindowTitle(fps);
       fpsCount = 0; 
       fpsLimit = (int)max(ifps, 1.f);
       cutilCheckError(cutResetTimer(timer));  
    }

    glutPostRedisplay();
    
    if( frame < g_iFrameToCompare )
    {
    	++frame;
    }
    else
    {
    	printf( "TEST PASSED\n" );
    	exit (0);  	
    }
}

void autoTest() 
{
	for(int count=0;count<g_iFrameToCompare;count++)
	{
		// add in a little force so the automated testing is interesing.
		if(g_bQAReadback && g_bQAAddTestForce) 
		{
			int x = wWidth/(count+1); int y = wHeight/(count+1);
			float fx = (x / (float)wWidth);        
			float fy = (y / (float)wHeight);
			int nx = (int)(fx * DIM);        
			int ny = (int)(fy * DIM);   

			int ddx = 35;
			int ddy = 35;
			fx = ddx / (float)wWidth;
			fy = ddy / (float)wHeight;
			int spy = ny-FR;
			int spx = nx-FR;

            addForces(dvfield, DIM, DIM, spx, spy, FORCE * DT * fx, FORCE * DT * fy, FR);
            lastx = x; lasty = y;
			//g_bQAAddTestForce = false; // only add it once
		}
        display();
    }

	// compare to offical reference image, printing PASS or FAIL.
    /*
    printf("> (Frame %d) Readback BackBuffer\n", 100);
    g_CheckRender->readback( wWidth, wHeight, NULL );
    g_CheckRender->savePPM(sOriginal[0], true, NULL);
    if (!g_CheckRender->PPMvsPPM(sOriginal[0], sReference[0], MAX_EPSILON_ERROR)) {
        g_TotalErrors++;
    }
    */
}


void idle(void) {
    glutPostRedisplay();
}

void initParticles(cData *p, int dx, int dy) {
    int i, j;
    for (i = 0; i < dy; i++) {
        for (j = 0; j < dx; j++) {
            p[i*dx+j].x = ((j+0.5)/dx) + 
                          (rand() / (float)RAND_MAX - 0.5f) / dx;
            p[i*dx+j].y = ((i+0.5)/dy) + 
                          (rand() / (float)RAND_MAX - 0.5f) / dy;
        }
    }
}

void keyboard( unsigned char key, int x, int y) {
    switch( key) {
        case 27:
        exit (0);
        case 'r':
            memset(hvfield, 0, sizeof(cData) * DS);
            cudaMemcpy(dvfield, hvfield, sizeof(cData) * DS, 
                       cudaMemcpyHostToDevice);

            initParticles(particles, DIM, DIM);

            cudaGLUnregisterBufferObject(vbo);
            cutilCheckMsg("cudaGLUnregisterBufferObject failed");
    
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
            glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(cData) * DS, 
                            particles, GL_DYNAMIC_DRAW_ARB);
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

            cudaGLRegisterBufferObject(vbo);
            cutilCheckMsg("cudaGLRegisterBufferObject failed");
            break;
        default: break;
    }
}

void click(int button, int updown, int x, int y) {
    lastx = x; lasty = y;
    clicked = !clicked;
}

void motion (int x, int y) {
    // Convert motion coordinates to domain
    float fx = (lastx / (float)wWidth);        
    float fy = (lasty / (float)wHeight);
    int nx = (int)(fx * DIM);        
    int ny = (int)(fy * DIM);   
    
    if (clicked && nx < DIM-FR && nx > FR-1 && ny < DIM-FR && ny > FR-1) {
        int ddx = x - lastx;
        int ddy = y - lasty;
        fx = ddx / (float)wWidth;
        fy = ddy / (float)wHeight;
        int spy = ny-FR;
        int spx = nx-FR;
        addForces(dvfield, DIM, DIM, spx, spy, FORCE * DT * fx, FORCE * DT * fy, FR);
        lastx = x; lasty = y;
    } 
    glutPostRedisplay();
}

void reshape(int x, int y) {
    wWidth = x; wHeight = y;
    glViewport(0, 0, x, y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 1, 0, 0, 1); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void cleanup(void) {
    cudaGLUnregisterBufferObject(vbo);
    cutilCheckMsg("cudaGLUnregisterBufferObject failed");

    unbindTexture();
    deleteTexture();

    // Free all host and device resources
    free(hvfield); free(particles); 
    cudaFree(dvfield); 
    cudaFree(vxfield); cudaFree(vyfield);
    cufftDestroy(planr2c);
    cufftDestroy(planc2r);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
    glDeleteBuffersARB(1, &vbo);
    
    cutilCheckError(cutDeleteTimer(timer));  
}

int initGL(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(wWidth, wHeight);
    glutCreateWindow("Compute Stable Fluids");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(click);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glewInit();
    if (! glewIsSupported(
        "GL_ARB_vertex_buffer_object"
		)) {
        fprintf( stderr, "ERROR: Support for necessary OpenGL extensions missing.");
        fflush( stderr);
        return CUTFalse;
    }
    return CUTTrue;
}


int main(int argc, char** argv) 
{
    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    if (CUTFalse == initGL(argc, argv)) {
        return CUTFalse;
    }

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilGLDeviceInit(argc, argv);
    else {
        cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
    }

	// automatied build testing harness
    if (cutCheckCmdLineFlag(argc, (const char **)argv, "qatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))
    {
        g_bQAReadback = true;
    }

    // Allocate and initialize host data
    GLint bsize;

    cutilCheckError(cutCreateTimer(&timer));
    cutilCheckError(cutResetTimer(timer));  
    
    hvfield = (cData*)malloc(sizeof(cData) * DS);
    memset(hvfield, 0, sizeof(cData) * DS);
  
    // Allocate and initialize device data
    cudaMallocPitch((void**)&dvfield, &tPitch, sizeof(cData)*DIM, DIM);
    
    cudaMemcpy(dvfield, hvfield, sizeof(cData) * DS, 
               cudaMemcpyHostToDevice); 
    // Temporary complex velocity field data     
    cudaMalloc((void**)&vxfield, sizeof(cData) * PDS);
    cudaMalloc((void**)&vyfield, sizeof(cData) * PDS);
    
    setupTexture(DIM, DIM);
    bindTexture();
    
    // Create particle array
    particles = (cData*)malloc(sizeof(cData) * DS);
    memset(particles, 0, sizeof(cData) * DS);   
    
    initParticles(particles, DIM, DIM); 

    // Create CUFFT transform plan configuration
    cufftPlan2d(&planr2c, DIM, DIM, CUFFT_R2C);
    cufftPlan2d(&planc2r, DIM, DIM, CUFFT_C2R);
#if 0    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(wWidth, wHeight);
    glutCreateWindow("Compute Stable Fluids");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(click);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glewInit();
    if (! glewIsSupported(
        "GL_ARB_vertex_buffer_object"
		)) {
        fprintf( stderr, "ERROR: Support for necessary OpenGL extensions missing.");
        fflush( stderr);
        return CUTFalse;
    }
#endif
    glGenBuffersARB(1, &vbo);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(cData) * DS, 
                    particles, GL_DYNAMIC_DRAW_ARB);

    glGetBufferParameterivARB(GL_ARRAY_BUFFER_ARB, GL_BUFFER_SIZE_ARB, &bsize); 
    if (bsize != (sizeof(cData) * DS))
        goto EXTERR;
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

    cudaGLRegisterBufferObject(vbo);
    cutilCheckMsg("cudaGLRegisterBufferObject failed");

    if (g_bQAReadback)
    {
/*      g_CheckRender = new CheckBackBuffer(wWidth, wHeight, 4);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);

        autoTest();
*/
    } else {
        atexit(cleanup); 
        glutMainLoop();
    }

    cudaThreadExit();
    return 0;

EXTERR:
    printf("Failed to initialize GL extensions.\n");

    cudaThreadExit();
    return 1;
}
