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

/* 
    Marching cubes

    This sample extracts a geometric isosurface from a volume dataset using
    the marching cubes algorithm. It uses the scan (prefix sum) function from
    the CUDPP library to perform stream compaction. Similar techniques can
    be used for other problems that require a variable-sized output per
    thread.

    For more information on marching cubes see:
    http://local.wasp.uwa.edu.au/~pbourke/geometry/polygonise/
    http://en.wikipedia.org/wiki/Marching_cubes

    Volume data courtesy:
    http://www9.informatik.uni-erlangen.de/External/vollib/

    For more information on CUDPP ("CUDA Data Parallel Primitives Library"):
    http://www.gpgpu.org/developer/cudpp

    The algorithm consists of several stages:

    1. Execute "classifyVoxel" kernel
    This evaluates the volume at the corners of each voxel and computes the
    number of vertices each voxel will generate.
    It is executed using one thread per voxel.
    It writes two arrays - voxelOccupied and voxelVertices to global memory.
    voxelOccupied is a flag indicating if the voxel is non-empty.

    2. Scan "voxelOccupied" array (using CUDPP cudppScan())
    Read back the total number of occupied voxels from GPU to CPU.
    This is the sum of the last value of the exclusive scan and the last
    input value.

    3. Execute "compactVoxels" kernel
    This compacts the voxelOccupied array to get rid of empty voxels.
    This allows us to run the complex "generateTriangles" kernel on only
    the occupied voxels.

    4. Scan voxelVertices array
    This gives the start address for the vertex data for each voxel.
    We read back the total number of vertices generated from GPU to CPU.

    Note that by using a custom scan function we could combine the above two
    scan operations above into a single operation.

    5. Execute "generateTriangles" kernel
    This runs only on the occupied voxels.
    It looks up the field values again and generates the triangle data,
    using the results of the scan to write the output to the correct addresses.
    The marching cubes look-up tables are stored in 1D textures.

    6. Render geometry
    Using number of vertices from readback.
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
#include <cutil_inline.h>
#include <cuda_runtime_api.h>
#include <cuda_gl_interop.h>
#include <vector_types.h>
#include <vector_functions.h>

#include "defines.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

extern "C" void
launch_classifyVoxel( dim3 grid, dim3 threads, uint* voxelVerts, uint *voxelOccupied, uchar *volume,
					  uint3 gridSize, uint3 gridSizeShift, uint3 gridSizeMask, uint numVoxels,
					  float3 voxelSize, float isoValue);

extern "C" void 
launch_compactVoxels(dim3 grid, dim3 threads, uint *compactedVoxelArray, uint *voxelOccupied, 
					uint *voxelOccupiedScan, uint numVoxels);

extern "C" void
launch_generateTriangles(dim3 grid, dim3 threads,
						float4 *pos, float4 *norm, uint *compactedVoxelArray, uint *numVertsScanned,
						uint3 gridSize, uint3 gridSizeShift, uint3 gridSizeMask,
						float3 voxelSize, float isoValue, uint activeVoxels, uint maxVerts);

extern "C" void
launch_generateTriangles2(dim3 grid, dim3 threads,
						float4 *pos, float4 *norm, uint *compactedVoxelArray, uint *numVertsScanned, uchar *volume,
						uint3 gridSize, uint3 gridSizeShift, uint3 gridSizeMask,
						float3 voxelSize, float isoValue, uint activeVoxels, uint maxVerts);

extern "C"
void allocateTextures(	uint **d_edgeTable, uint **d_triTable,  uint **d_numVertsTable );

extern "C"
void bindVolumeTexture(uchar *d_volume);

#include "cudpp/cudpp.h"

// constants
const unsigned int window_width = 512;
const unsigned int window_height = 512;

char *volumeFilename = "Bucky.raw";

uint3 gridSizeLog2 = make_uint3(5, 5, 5);
uint3 gridSizeShift;
uint3 gridSize;
uint3 gridSizeMask;

float3 voxelSize;
uint numVoxels    = 0;
uint maxVerts     = 0;
uint activeVoxels = 0;
uint totalVerts   = 0;

float isoValue		= 0.2f;
float dIsoValue		= 0.005f;

CUDPPHandle scanplan;

// device data
GLuint posVbo, normalVbo;

uchar *d_volume = 0;
uint *d_voxelVerts = 0;
uint *d_voxelVertsScan = 0;
uint *d_voxelOccupied = 0;
uint *d_voxelOccupiedScan = 0;
uint *d_compactedVoxelArray;

// tables
uint* d_numVertsTable = 0;
uint* d_edgeTable = 0;
uint* d_triTable = 0;

// mouse controls
int mouse_old_x, mouse_old_y;
int mouse_buttons = 0;
float3 rotate = make_float3(0.0, 0.0, 0.0);
float3 translate= make_float3(0.0, 0.0, -3.0);

// toggles
bool wireframe = false;
bool animate = false;
bool lighting = true;
bool render = true;
bool compute = true;

// forward declarations
void runTest(int argc, char** argv);

CUTBoolean initGL();
void createVBO(GLuint* vbo, unsigned int size);
void deleteVBO(GLuint* vbo);

void display();
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void idle();
void reshape(int w, int h);

void computeIsosurface();
void dumpBuffer(uint *d_buffer, int nelements);
void mainMenu(int i);

////////////////////////////////////////////////////////////////////////////////
// Load raw data from disk
////////////////////////////////////////////////////////////////////////////////
uchar *loadRawFile(char *filename, int size)
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
main(int argc, char** argv)
{
    runTest(argc, argv);

    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
// initialize marching cubes
////////////////////////////////////////////////////////////////////////////////
void
initMC(int argc, char** argv)
{
    // parse command line arguments
    int n;
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "grid", &n)) {
        gridSizeLog2.x = gridSizeLog2.y = gridSizeLog2.z = n;
    }
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "gridx", &n)) {
        gridSizeLog2.x = n;
    }
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "gridy", &n)) {
        gridSizeLog2.y = n;
    }
    if (cutGetCmdLineArgumenti( argc, (const char**) argv, "gridz", &n)) {
        gridSizeLog2.z = n;
    }

    char *filename;
    if (cutGetCmdLineArgumentstr( argc, (const char**) argv, "file", &filename)) {
        volumeFilename = filename;
    }

    gridSize = make_uint3(1<<gridSizeLog2.x, 1<<gridSizeLog2.y, 1<<gridSizeLog2.z);
    gridSizeMask = make_uint3(gridSize.x-1, gridSize.y-1, gridSize.z-1);
    gridSizeShift = make_uint3(0, gridSizeLog2.x, gridSizeLog2.x+gridSizeLog2.y);

    numVoxels = gridSize.x*gridSize.y*gridSize.z;
    voxelSize = make_float3(2.0f / gridSize.x, 2.0f / gridSize.y, 2.0f / gridSize.z);
    maxVerts = gridSize.x*gridSize.y*100;

    printf("grid: %d x %d x %d = %d voxels\n", gridSize.x, gridSize.y, gridSize.z, numVoxels);
    printf("max verts = %d\n", maxVerts);

#if SAMPLE_VOLUME
    // load volume data
    char* path = cutFindFilePath(volumeFilename, argv[0]);
    if (path == 0) {
        fprintf(stderr, "Error finding file '%s'\n", volumeFilename);
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }

    int size = gridSize.x*gridSize.y*gridSize.z*sizeof(uchar);
    uchar *volume = loadRawFile(path, size);
    cutilSafeCall(cudaMalloc((void**) &d_volume, size));
    cutilSafeCall(cudaMemcpy(d_volume, volume, size, cudaMemcpyHostToDevice) );
    free(volume);

	bindVolumeTexture(d_volume);
#endif

    // create VBOs
    createVBO(&posVbo, maxVerts*sizeof(float)*4);
    cutilSafeCall(cudaGLRegisterBufferObject(posVbo));

    createVBO(&normalVbo, maxVerts*sizeof(float)*4);
    cutilSafeCall(cudaGLRegisterBufferObject(normalVbo));

    // allocate textures
	allocateTextures(	&d_edgeTable, &d_triTable, &d_numVertsTable );

    // allocate device memory
    unsigned int memSize = sizeof(uint) * numVoxels;
    cutilSafeCall(cudaMalloc((void**) &d_voxelVerts, memSize));
    cutilSafeCall(cudaMalloc((void**) &d_voxelVertsScan, memSize));
    cutilSafeCall(cudaMalloc((void**) &d_voxelOccupied, memSize));
    cutilSafeCall(cudaMalloc((void**) &d_voxelOccupiedScan, memSize));
    cutilSafeCall(cudaMalloc((void**) &d_compactedVoxelArray, memSize));

    // initialize CUDPP scan
    CUDPPConfiguration config;
    config.algorithm = CUDPP_SCAN;
    config.datatype = CUDPP_UINT;
    config.op = CUDPP_ADD;
    config.options = CUDPP_OPTION_FORWARD | CUDPP_OPTION_EXCLUSIVE;
    cudppPlan(&scanplan, config, numVoxels, 1, 0);
}

void cleanup()
{
    deleteVBO(&posVbo);
    deleteVBO(&normalVbo);

    if (d_volume)
        cutilSafeCall(cudaFree(d_volume));
    cutilSafeCall(cudaFree(d_edgeTable));
    cutilSafeCall(cudaFree(d_triTable));
    cutilSafeCall(cudaFree(d_numVertsTable));

    cutilSafeCall(cudaFree(d_voxelVerts));
    cutilSafeCall(cudaFree(d_voxelVertsScan));
    cutilSafeCall(cudaFree(d_voxelOccupied));
    cutilSafeCall(cudaFree(d_voxelOccupiedScan));
    cutilSafeCall(cudaFree(d_compactedVoxelArray));

    cudppDestroyPlan(scanplan);
}

void initMenus()
{
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Toggle animation [ ]", ' ');
    glutAddMenuEntry("Increment isovalue [+]", '+');
    glutAddMenuEntry("Decrement isovalue [-]", '-');
    glutAddMenuEntry("Toggle computation [c]", 'c');
    glutAddMenuEntry("Toggle rendering [r]", 'r');
    glutAddMenuEntry("Toggle lighting [l]", 'l');
    glutAddMenuEntry("Toggle wireframe [w]", 'w');
    glutAddMenuEntry("Quit (esc)", '\033');
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void
runTest(int argc, char** argv)
{
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    // Create GL context
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("Cuda Marching Cubes");

    // initialize GL
    if(CUTFalse == initGL()) {
        return;
    }

    // register callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    initMenus();

    initMC(argc, argv);

    // start rendering mainloop
    glutMainLoop();

    cudaThreadExit();
}

void dumpBuffer(uint *d_buffer, int nelements)
{
    uint bytes = nelements*sizeof(uint);
    uint *h_buffer = (uint *) malloc(bytes);
    cutilSafeCall(cudaMemcpy(h_buffer, d_buffer, bytes, cudaMemcpyDeviceToHost) );
    for(int i=0; i<nelements; i++) {
        printf("%d: %u\n", i, h_buffer[i]);
    }
    printf("\n");
    free(h_buffer);
}

#define DEBUG_BUFFERS 0

////////////////////////////////////////////////////////////////////////////////
//! Run the Cuda part of the computation
////////////////////////////////////////////////////////////////////////////////
void
computeIsosurface()
{
    int threads = 128;
    dim3 grid(numVoxels / threads, 1, 1);
    // get around maximum grid size of 65535 in each dimension
    if (grid.x > 65535) {
        grid.y = grid.x / 32768;
        grid.x = 32768;
    }

    // calculate number of vertices need per voxel
    launch_classifyVoxel(grid, threads, 
						d_voxelVerts, d_voxelOccupied, d_volume, 
						gridSize, gridSizeShift, gridSizeMask, 
						numVoxels, voxelSize, isoValue);
#if DEBUG_BUFFERS
    printf("voxelVerts:\n");
    dumpBuffer(d_voxelVerts, numVoxels);
#endif

#if SKIP_EMPTY_VOXELS

    // scan voxel occupied array
    cudppScan(scanplan, d_voxelOccupiedScan, d_voxelOccupied, numVoxels);
#if DEBUG_BUFFERS
    printf("voxelOccupiedScan:\n");
    dumpBuffer(d_voxelOccupiedScan, numVoxels);
#endif

    // read back values to calculate total number of non-empty voxels
    // since we are using an exclusive scan, the total is the last value of
    // the scan result plus the last value in the input array
    {
        uint lastElement, lastScanElement;
        cutilSafeCall(cudaMemcpy((void *) &lastElement, 
                       (void *) (d_voxelOccupied + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        cutilSafeCall(cudaMemcpy((void *) &lastScanElement, 
                       (void *) (d_voxelOccupiedScan + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        activeVoxels = lastElement + lastScanElement;
    }

    if (activeVoxels==0) {
        // return if there are no full voxels
        totalVerts = 0;
        return;
    }

    // compact voxel index array
    launch_compactVoxels(grid, threads, d_compactedVoxelArray, d_voxelOccupied, d_voxelOccupiedScan, numVoxels);
    cutilCheckMsg("compactVoxels failed");

#endif // SKIP_EMPTY_VOXELS

    // scan voxel vertex count array
    cudppScan(scanplan, d_voxelVertsScan, d_voxelVerts, numVoxels);
#if DEBUG_BUFFERS
    printf("voxelVertsScan:\n");
    dumpBuffer(d_voxelVertsScan, numVoxels);
#endif

    // readback total number of vertices
    {
        uint lastElement, lastScanElement;
        cutilSafeCall(cudaMemcpy((void *) &lastElement, 
                       (void *) (d_voxelVerts + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        cutilSafeCall(cudaMemcpy((void *) &lastScanElement, 
                       (void *) (d_voxelVertsScan + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        totalVerts = lastElement + lastScanElement;
    }

    // generate triangles, writing to vertex buffers
    float4 *d_pos = 0, *d_normal = 0;
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_pos, posVbo));
    cutilSafeCall(cudaGLMapBufferObject((void**)&d_normal, normalVbo));

#if SKIP_EMPTY_VOXELS
    dim3 grid2((int) ceil(activeVoxels / (float) NTHREADS), 1, 1);
#else
    dim3 grid2((int) ceil(numVoxels / (float) NTHREADS), 1, 1);
#endif
    while(grid2.x > 65535) {
        grid2.x/=2;
        grid2.y*=2;
    }
#if SAMPLE_VOLUME
    launch_generateTriangles2(grid2, NTHREADS, d_pos, d_normal, 
                                            d_compactedVoxelArray, 
                                            d_voxelVertsScan, d_volume, 
                                            gridSize, gridSizeShift, gridSizeMask, 
                                            voxelSize, isoValue, activeVoxels, 
                                            maxVerts);
#else
    launch_generateTriangles(grid2, NTHREADS, d_pos, d_normal, 
                                           d_compactedVoxelArray, 
                                           d_voxelVertsScan, 
                                           gridSize, gridSizeShift, gridSizeMask, 
                                           voxelSize, isoValue, activeVoxels, 
                                           maxVerts);
#endif

    cutilSafeCall(cudaGLUnmapBufferObject(normalVbo));
    cutilSafeCall(cudaGLUnmapBufferObject(posVbo));
}

////////////////////////////////////////////////////////////////////////////////
//! Initialize OpenGL
////////////////////////////////////////////////////////////////////////////////
CUTBoolean
initGL()
{
    // initialize necessary OpenGL extensions
    glewInit();
    if (! glewIsSupported("GL_VERSION_2_0 " 
		                  )) {
        fprintf(stderr, "ERROR: Support for necessary OpenGL extensions missing.");
        fflush(stderr);
        return CUTFalse;
    }

    // default initialization
    glClearColor(0.1, 0.2, 0.3, 1.0);
    glEnable(GL_DEPTH_TEST);

    // good old-fashioned fixed function lighting
    float black[] = { 0.0, 0.0, 0.0, 1.0 };
    float white[] = { 1.0, 1.0, 1.0, 1.0 };
    float ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    float diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
    float lightPos[] = { 0.0, 0.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);

    glLightfv(GL_LIGHT0, GL_AMBIENT, white);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    
    glutReportErrors();

    return CUTTrue;
}

////////////////////////////////////////////////////////////////////////////////
//! Create VBO
////////////////////////////////////////////////////////////////////////////////
void
createVBO(GLuint* vbo, unsigned int size)
{
    // create buffer object
    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);

    // initialize buffer object
    glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutReportErrors();
}

////////////////////////////////////////////////////////////////////////////////
//! Delete VBO
////////////////////////////////////////////////////////////////////////////////
void
deleteVBO(GLuint* vbo)
{
    glBindBuffer(1, *vbo);
    glDeleteBuffers(1, vbo);
    cutilSafeCall(cudaGLUnregisterBufferObject(*vbo));

    *vbo = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Render isosurface geometry from the vertex buffers
////////////////////////////////////////////////////////////////////////////////
void renderIsosurface()
{
    glBindBuffer(GL_ARRAY_BUFFER, posVbo);
    glVertexPointer(4, GL_FLOAT, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, normalVbo);
    glNormalPointer(GL_FLOAT, sizeof(float)*4, 0);
    glEnableClientState(GL_NORMAL_ARRAY);

    glColor3f(1.0, 0.0, 0.0);
    glDrawArrays(GL_TRIANGLES, 0, totalVerts);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

////////////////////////////////////////////////////////////////////////////////
//! Display callback
////////////////////////////////////////////////////////////////////////////////
void
display()
{
    // run CUDA kernel to generate geometry
    if (compute) {
        computeIsosurface();
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translate.x, translate.y, translate.z);
    glRotatef(rotate.x, 1.0, 0.0, 0.0);
    glRotatef(rotate.y, 0.0, 1.0, 0.0);

    glPolygonMode(GL_FRONT_AND_BACK, wireframe? GL_LINE : GL_FILL);
    if (lighting) {
        glEnable(GL_LIGHTING);
    }

    // render
    if (render) {
        glPushMatrix();
        glRotatef(180.0, 0.0, 1.0, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        renderIsosurface();
        glPopMatrix();
    }

    glDisable(GL_LIGHTING);

    glutSwapBuffers();
}

////////////////////////////////////////////////////////////////////////////////
//! Keyboard events handler
////////////////////////////////////////////////////////////////////////////////
void
keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch(key) {
    case(27) :
        cleanup();
        cudaThreadExit();
        exit(0);
    case '=':
        isoValue += 0.01;
        break;
    case '-':
        isoValue -= 0.01;
        break;
    case '+':
        isoValue += 0.1;
        break;
    case '_':
        isoValue -= 0.1;
        break;
    case 'w':
        wireframe = !wireframe;
        break;
    case ' ':
        animate = !animate;
        break;
    case 'l':
        lighting = !lighting;
        break;
    case 'r':
        render = !render;
        break;
    case 'c':
        compute = !compute;
        break;
    }

    printf("isoValue = %f\n", isoValue);
    printf("voxels = %d\n", activeVoxels);
    printf("verts = %d\n", totalVerts);
    printf("occupancy: %d / %d = %.2f%%\n", 
           activeVoxels, numVoxels, activeVoxels*100.0f / (float) numVoxels);

    if (!compute) {
        computeIsosurface();        
    }

    glutPostRedisplay();
}

////////////////////////////////////////////////////////////////////////////////
//! Mouse event handlers
////////////////////////////////////////////////////////////////////////////////
void
mouse(int button, int state, int x, int y)
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
    float dx = x - mouse_old_x;
    float dy = y - mouse_old_y;

    if (mouse_buttons==1) {
        rotate.x += dy * 0.2;
        rotate.y += dx * 0.2;
    } else if (mouse_buttons==2) {
        translate.x += dx * 0.01;
        translate.y -= dy * 0.01;
    } else if (mouse_buttons==3) {
        translate.z += dy * 0.01;
    }

    mouse_old_x = x;
    mouse_old_y = y;
    glutPostRedisplay();
}

void idle()
{
    if (animate) {
        isoValue += dIsoValue;
        if (isoValue < 0.1f || isoValue > 0.9f)
            dIsoValue *= -1.0f;
    }
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float) w / (float) h, 0.1, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);
}

void mainMenu(int i)
{
    keyboard((unsigned char) i, 0, 0);
}
