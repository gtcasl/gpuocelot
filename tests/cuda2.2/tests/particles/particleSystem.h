/*
 * Copyright 1993-2006 NVIDIA Corporation.  All rights reserved.
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

#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

#define DEBUG_GRID 0
#define DO_TIMING 0

#include "particles_kernel.cuh"
#include "vector_functions.h"

// Particle system class
class ParticleSystem
{
public:
    ParticleSystem(uint numParticles, uint3 gridSize);
    ~ParticleSystem();

    enum ParticleConfig
    {
	    CONFIG_RANDOM,
	    CONFIG_GRID,
	    _NUM_CONFIGS
    };

    enum ParticleArray
    {
        POSITION,
        VELOCITY,
    };

    void update(float deltaTime);
    void reset(ParticleConfig config);

    float* getArray(ParticleArray array);
    void   setArray(ParticleArray array, const float* data, int start, int count);

    int    getNumParticles() const { return m_numParticles; }

    unsigned int getCurrentReadBuffer() const { return m_posVbo[m_currentPosRead]; }
    unsigned int getColorBuffer() const { return m_colorVBO; }

    void dumpGrid();
    void dumpParticles(uint start, uint count);

    void setIterations(int i) { m_solverIterations = i; }

    void setDamping(float x) { m_params.globalDamping = x; }
    void setGravity(float x) { m_params.gravity = make_float3(0.0f, x, 0.0f); }

    void setCollideSpring(float x) { m_params.spring = x; }
    void setCollideDamping(float x) { m_params.damping = x; }
    void setCollideShear(float x) { m_params.shear = x; }
    void setCollideAttraction(float x) { m_params.attraction = x; }

    void setColliderPos(float4 x) { m_params.colliderPos = x; }

    float getParticleRadius() { return m_params.particleRadius; }
    float4 getColliderPos() { return m_params.colliderPos; }
    float getColliderRadius() { return m_params.colliderRadius; }
    uint3 getGridSize() { return m_params.gridSize; }
    float3 getWorldOrigin() { return m_params.worldOrigin; }
    float3 getCellSize() { return m_params.cellSize; }

    void addSphere(int index, float *pos, float *vel, int r, float spacing);

protected: // methods
    ParticleSystem() {}
    uint createVBO(uint size);

    void _initialize(int numParticles);
    void _finalize();

    void initGrid(uint *size, float spacing, float jitter, uint numParticles);

protected: // data
    bool m_bInitialized;
    uint m_numParticles;

    // CPU data
    float* m_hPos;              // particle positions
    float* m_hVel;              // particle velocities

    uint*  m_hGridCounters;
    uint*  m_hGridCells;

    uint*  m_hParticleHash;
    uint*  m_hCellStart;

    // GPU data
    float* m_dPos[2];
    float* m_dVel[2];

    float* m_dSortedPos;
    float* m_dSortedVel;

    // uniform grid data
    uint*  m_dGridCounters;     // counts number of entries per grid cell
    uint*  m_dGridCells;        // contains indices of up to "m_maxParticlesPerCell" particles per cell

    // grid data for sorting method
    uint*  m_dParticleHash[2];  // (hash, index) pairs for each particle
    uint*  m_dCellStart;        // index of start of each cell in sorted list

    uint m_posVbo[2];           // vertex buffer object for particle positions
    uint m_colorVBO;            // vertex buffer object for colors

    uint m_currentPosRead, m_currentVelRead;
    uint m_currentPosWrite, m_currentVelWrite;

    // params
    SimParams m_params;
    uint3 m_gridSize;
    uint m_numGridCells;
    uint m_maxParticlesPerCell;

    uint m_timer;

    uint m_solverIterations;
};

#endif // __PARTICLESYSTEM_H__
