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

// Utilities and system includes
#include <shrUtils.h>
#include <cutil_inline.h>
#include <cutil_math.h>
#include <float.h> // for FLT_MAX

#include "CudaMath.h"
#include "dds.h"
#include "permutations.h"

// Definitions
#define INPUT_IMAGE "lena_std.ppm"
#define REFERENCE_IMAGE "lena_ref.dds"

#if __DEVICE_EMULATION__
#define ERROR_THRESHOLD 0.1f
#else
#define ERROR_THRESHOLD 0.02f
#endif

#define NUM_THREADS 64        // Number of threads per block.

#if __DEVICE_EMULATION__
#define __debugsync() __syncthreads()
#else
#define __debugsync()
#endif

template <class T> 
__device__ inline void swap(T & a, T & b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

//__constant__ float3 kColorMetric = { 0.2126f, 0.7152f, 0.0722f };
__constant__ float3 kColorMetric = { 1.0f, 1.0f, 1.0f };

////////////////////////////////////////////////////////////////////////////////
// Sort colors
////////////////////////////////////////////////////////////////////////////////
__device__ void sortColors(const float * values, int * ranks)
{
#if __DEVICE_EMULATION__
    if (threadIdx.x == 0)
    {
        for (int tid = 0; tid < 16; tid++)
        {
            int rank = 0;
            for (int i = 0; i < 16; i++)
            {
                rank += (values[i] < values[tid]);
            }
            
            ranks[tid] = rank;
        }

        // Resolve elements with the same index.
        for (int i = 0; i < 15; i++)
        {
            for (int tid = 0; tid < 16; tid++)
            {
                if (tid > i && ranks[tid] == ranks[i]) ++ranks[tid];
            }
        }
    }
#else
    const int tid = threadIdx.x;

    int rank = 0;

    #pragma unroll
    for (int i = 0; i < 16; i++)
    {
        rank += (values[i] < values[tid]);
    }
    
    ranks[tid] = rank;

    // Resolve elements with the same index.
    #pragma unroll
    for (int i = 0; i < 15; i++)
    {
        if (tid > i && ranks[tid] == ranks[i]) ++ranks[tid];
    }
#endif
}

////////////////////////////////////////////////////////////////////////////////
// Load color block to shared mem
////////////////////////////////////////////////////////////////////////////////
__device__ void loadColorBlock(const uint * image, float3 colors[16], float3 sums[16], int xrefs[16], int blockOffset)
{
    const int bid = blockIdx.x + blockOffset;
    const int idx = threadIdx.x;

    __shared__ float dps[16];

    float3 tmp;

    if (idx < 16)
    {
        // Read color and copy to shared mem.
        uint c = image[(bid) * 16 + idx];
    
        colors[idx].x = ((c >> 0) & 0xFF) * (1.0f / 255.0f);
        colors[idx].y = ((c >> 8) & 0xFF) * (1.0f / 255.0f);
        colors[idx].z = ((c >> 16) & 0xFF) * (1.0f / 255.0f);
        
        // No need to synchronize, 16 < warp size.
#if __DEVICE_EMULATION__
        } __debugsync(); if (idx < 16) {
#endif

        // Sort colors along the best fit line.
        colorSums(colors, sums);
        float3 axis = bestFitLine(colors, sums[0]);
        
        dps[idx] = dot(colors[idx], axis);
        
#if __DEVICE_EMULATION__
        } __debugsync(); if (idx < 16) {
#endif
        
        sortColors(dps, xrefs);
        
        tmp = colors[idx];

#if __DEVICE_EMULATION__
        } __debugsync(); if (idx < 16) {
#endif

        colors[xrefs[idx]] = tmp;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Round color to RGB565 and expand
////////////////////////////////////////////////////////////////////////////////
inline __device__ float3 roundAndExpand(float3 v, ushort * w)
{
    v.x = rintf(__saturatef(v.x) * 31.0f);
    v.y = rintf(__saturatef(v.y) * 63.0f);
    v.z = rintf(__saturatef(v.z) * 31.0f);

    *w = ((ushort)v.x << 11) | ((ushort)v.y << 5) | (ushort)v.z;
    v.x *= 0.03227752766457f; // approximate integer bit expansion.
    v.y *= 0.01583151765563f;
    v.z *= 0.03227752766457f;
    return v;
}


__constant__ float alphaTable4[4] = { 9.0f, 0.0f, 6.0f, 3.0f };
__constant__ float alphaTable3[4] = { 4.0f, 0.0f, 2.0f, 2.0f };
__constant__ const int prods4[4] = { 0x090000,0x000900,0x040102,0x010402 };
__constant__ const int prods3[4] = { 0x040000,0x000400,0x040101,0x010401 };

#define USE_TABLES 1

////////////////////////////////////////////////////////////////////////////////
// Evaluate permutations
////////////////////////////////////////////////////////////////////////////////
static __device__ float evalPermutation4(const float3 * colors, uint permutation, ushort * start, ushort * end, float3 color_sum)
{
    // Compute endpoints using least squares.
#if USE_TABLES
    float3 alphax_sum = make_float3(0.0f, 0.0f, 0.0f);

    int akku = 0;

    // Compute alpha & beta for this permutation.
    for (int i = 0; i < 16; i++)
    {
        const uint bits = permutation >> (2*i);

        alphax_sum += alphaTable4[bits & 3] * colors[i];
        akku += prods4[bits & 3];
    }

    float alpha2_sum = float(akku >> 16);
    float beta2_sum = float((akku >> 8) & 0xff);
    float alphabeta_sum = float((akku >> 0) & 0xff);
    float3 betax_sum = (9.0f * color_sum) - alphax_sum;
#else
    float alpha2_sum = 0.0f;
    float beta2_sum = 0.0f;
    float alphabeta_sum = 0.0f;
    float3 alphax_sum = make_float3(0.0f, 0.0f, 0.0f);

    // Compute alpha & beta for this permutation.
    for (int i = 0; i < 16; i++)
    {
        const uint bits = permutation >> (2*i);

        float beta = (bits & 1);
        if (bits & 2) beta = (1 + beta) * (1.0f / 3.0f);
        float alpha = 1.0f - beta;

        alpha2_sum += alpha * alpha;
        beta2_sum += beta * beta;
        alphabeta_sum += alpha * beta;
        alphax_sum += alpha * colors[i];
    }

    float3 betax_sum = color_sum - alphax_sum;
#endif

    // alpha2, beta2, alphabeta and factor could be precomputed for each permutation, but it's faster to recompute them.
    const float factor = 1.0f / (alpha2_sum * beta2_sum - alphabeta_sum * alphabeta_sum);

    float3 a = (alphax_sum * beta2_sum - betax_sum * alphabeta_sum) * factor;
    float3 b = (betax_sum * alpha2_sum - alphax_sum * alphabeta_sum) * factor;
    
    // Round a, b to the closest 5-6-5 color and expand...
    a = roundAndExpand(a, start);
    b = roundAndExpand(b, end);

    // compute the error
    float3 e = a * a * alpha2_sum + b * b * beta2_sum + 2.0f * (a * b * alphabeta_sum - a * alphax_sum - b * betax_sum);

    return (0.111111111111f) * dot(e, kColorMetric);
}

static __device__ float evalPermutation3(const float3 * colors, uint permutation, ushort * start, ushort * end, float3 color_sum)
{
    // Compute endpoints using least squares.
#if USE_TABLES
    float3 alphax_sum = make_float3(0.0f, 0.0f, 0.0f);

    int akku = 0;

    // Compute alpha & beta for this permutation.
    for (int i = 0; i < 16; i++)
    {
        const uint bits = permutation >> (2*i);

        alphax_sum += alphaTable3[bits & 3] * colors[i];
        akku += prods3[bits & 3];
    }

    float alpha2_sum = float(akku >> 16);
    float beta2_sum = float((akku >> 8) & 0xff);
    float alphabeta_sum = float((akku >> 0) & 0xff);
    float3 betax_sum = (4.0f * color_sum) - alphax_sum;
#else
    float alpha2_sum = 0.0f;
    float beta2_sum = 0.0f;
    float alphabeta_sum = 0.0f;
    float3 alphax_sum = make_float3(0.0f, 0.0f, 0.0f);

    // Compute alpha & beta for this permutation.
    for (int i = 0; i < 16; i++)
    {
        const uint bits = permutation >> (2*i);

        float beta = (bits & 1);
        if (bits & 2) beta = 0.5f;
        float alpha = 1.0f - beta;
    
        alpha2_sum += alpha * alpha;
        beta2_sum += beta * beta;
        alphabeta_sum += alpha * beta;
        alphax_sum += alpha * colors[i];
    }

    float3 betax_sum = color_sum - alphax_sum;
#endif

    const float factor = 1.0f / (alpha2_sum * beta2_sum - alphabeta_sum * alphabeta_sum);

    float3 a = (alphax_sum * beta2_sum - betax_sum * alphabeta_sum) * factor;
    float3 b = (betax_sum * alpha2_sum - alphax_sum * alphabeta_sum) * factor;
    
    // Round a, b to the closest 5-6-5 color and expand...
    a = roundAndExpand(a, start);
    b = roundAndExpand(b, end);

    // compute the error
    float3 e = a * a * alpha2_sum + b * b * beta2_sum + 2.0f * (a * b * alphabeta_sum - a * alphax_sum - b * betax_sum);

    return (0.25f) * dot(e, kColorMetric);
}

__device__ void evalAllPermutations(const float3 * colors, const uint * permutations, ushort & bestStart, ushort & bestEnd, uint & bestPermutation, float * errors, float3 color_sum)
{
    const int idx = threadIdx.x;
    
    float bestError = FLT_MAX;
    
    __shared__ uint s_permutations[160];

    for(int i = 0; i < 16; i++)
    {
        int pidx = idx + NUM_THREADS * i;
        if (pidx >= 992) break;
        
        ushort start, end;
        uint permutation = permutations[pidx];
        if (pidx < 160) s_permutations[pidx] = permutation;
                
        float error = evalPermutation4(colors, permutation, &start, &end, color_sum);
        
        if (error < bestError)
        {
            bestError = error;
            bestPermutation = permutation;
            bestStart = start;
            bestEnd = end;
        }
    }

    if (bestStart < bestEnd)
    {
        swap(bestEnd, bestStart);
        bestPermutation ^= 0x55555555;    // Flip indices.
    }

    for(int i = 0; i < 3; i++)
    {
        int pidx = idx + NUM_THREADS * i;
        if (pidx >= 160) break;
        
        ushort start, end;
        uint permutation = s_permutations[pidx];
        float error = evalPermutation3(colors, permutation, &start, &end, color_sum);
        
        if (error < bestError)
        {
            bestError = error;
            bestPermutation = permutation;
            bestStart = start;
            bestEnd = end;
            
            if (bestStart > bestEnd)
            {
                swap(bestEnd, bestStart);
                bestPermutation ^= (~bestPermutation >> 1) & 0x55555555;    // Flip indices.
            }
        }
    }

    errors[idx] = bestError;
}

////////////////////////////////////////////////////////////////////////////////
// Find index with minimum error
////////////////////////////////////////////////////////////////////////////////
__device__ int findMinError(float * errors)
{
    const int idx = threadIdx.x;

    __shared__ int indices[NUM_THREADS];
    indices[idx] = idx;

#if __DEVICE_EMULATION__
    for(int d = NUM_THREADS/2; d > 0; d >>= 1)
    {
        __syncthreads();
        
        if (idx < d)
        {
            float err0 = errors[idx];
            float err1 = errors[idx + d];
            
            if (err1 < err0) {
                errors[idx] = err1;
                indices[idx] = indices[idx + d];
            }
        }
    }

#else
    for(int d = NUM_THREADS/2; d > 32; d >>= 1)
    {
        __syncthreads();
        
        if (idx < d)
        {
            float err0 = errors[idx];
            float err1 = errors[idx + d];
            
            if (err1 < err0) {
                errors[idx] = err1;
                indices[idx] = indices[idx + d];
            }
        }
    }

    __syncthreads();

    // unroll last 6 iterations
    if (idx < 32)
    {
        if (errors[idx + 32] < errors[idx]) {
            errors[idx] = errors[idx + 32];
            indices[idx] = indices[idx + 32];
        }
        if (errors[idx + 16] < errors[idx]) {
            errors[idx] = errors[idx + 16];
            indices[idx] = indices[idx + 16];
        }
        if (errors[idx + 8] < errors[idx]) {
            errors[idx] = errors[idx + 8];
            indices[idx] = indices[idx + 8];
        }
        if (errors[idx + 4] < errors[idx]) {
            errors[idx] = errors[idx + 4];
            indices[idx] = indices[idx + 4];
        }
        if (errors[idx + 2] < errors[idx]) {
            errors[idx] = errors[idx + 2];
            indices[idx] = indices[idx + 2];
        }
        if (errors[idx + 1] < errors[idx]) {
            errors[idx] = errors[idx + 1];
            indices[idx] = indices[idx + 1];
        }
    }
#endif

    __syncthreads();

    return indices[0];
}

////////////////////////////////////////////////////////////////////////////////
// Save DXT block
////////////////////////////////////////////////////////////////////////////////
__device__ void saveBlockDXT1(ushort start, ushort end, uint permutation, int xrefs[16], uint2 * result, int blockOffset)
{
    const int bid = blockIdx.x + blockOffset;

    if (start == end)
    {
        permutation = 0;
    }
    
    // Reorder permutation.
    uint indices = 0;
    for(int i = 0; i < 16; i++)
    {
        int ref = xrefs[i];
        indices |= ((permutation >> (2 * ref)) & 3) << (2 * i);
    }
    
    // Write endpoints.
    result[bid].x = (end << 16) | start;
    
    // Write palette indices.
    result[bid].y = indices;
}

////////////////////////////////////////////////////////////////////////////////
// Compress color block
////////////////////////////////////////////////////////////////////////////////
__global__ void compress(const uint * permutations, const uint * image, uint2 * result, int blockOffset)
{
    const int idx = threadIdx.x;
    
    __shared__ float3 colors[16];
    __shared__ float3 sums[16];
    __shared__ int xrefs[16];
    
    loadColorBlock(image, colors, sums, xrefs, blockOffset);

    __syncthreads();

    ushort bestStart, bestEnd;
    uint bestPermutation;

    __shared__ float errors[NUM_THREADS];

    evalAllPermutations(colors, permutations, bestStart, bestEnd, bestPermutation, errors, sums[0]);

    // Use a parallel reduction to find minimum error.
    const int minIdx = findMinError(errors);
    
    __syncthreads();
    
    // Only write the result of the winner thread.
    if (idx == minIdx)
    {
        saveBlockDXT1(bestStart, bestEnd, bestPermutation, xrefs, result, blockOffset);
    }
}

// Helper structs and functions to validate the output of the compressor.
// We cannot simply do a bitwise compare, because different compilers produce different
// results for different targets due to floating point arithmetic.

union Color32 {
    struct {
        unsigned char b, g, r, a;
    };
    unsigned int u;
};

union Color16 {
    struct {
        unsigned short b : 5;
        unsigned short g : 6;
        unsigned short r : 5;
    };
    unsigned short u;
};

struct BlockDXT1
{
    Color16 col0;
    Color16 col1;
    union {
        unsigned char row[4];
        unsigned int indices;
    };
    
    void decompress(Color32 colors[16]) const;
};

void BlockDXT1::decompress(Color32 * colors) const
{
    Color32 palette[4];
    
    // Does bit expansion before interpolation.
    palette[0].b = (col0.b << 3) | (col0.b >> 2);
    palette[0].g = (col0.g << 2) | (col0.g >> 4);
    palette[0].r = (col0.r << 3) | (col0.r >> 2);
    palette[0].a = 0xFF;
    
    palette[1].r = (col1.r << 3) | (col1.r >> 2);
    palette[1].g = (col1.g << 2) | (col1.g >> 4);
    palette[1].b = (col1.b << 3) | (col1.b >> 2);
    palette[1].a = 0xFF;
    
    if( col0.u > col1.u ) {
        // Four-color block: derive the other two colors.
        palette[2].r = (2 * palette[0].r + palette[1].r) / 3;
        palette[2].g = (2 * palette[0].g + palette[1].g) / 3;
        palette[2].b = (2 * palette[0].b + palette[1].b) / 3;
        palette[2].a = 0xFF;
        
        palette[3].r = (2 * palette[1].r + palette[0].r) / 3;
        palette[3].g = (2 * palette[1].g + palette[0].g) / 3;
        palette[3].b = (2 * palette[1].b + palette[0].b) / 3;
        palette[3].a = 0xFF;
    }
    else {
        // Three-color block: derive the other color.
        palette[2].r = (palette[0].r + palette[1].r) / 2;
        palette[2].g = (palette[0].g + palette[1].g) / 2;
        palette[2].b = (palette[0].b + palette[1].b) / 2;
        palette[2].a = 0xFF;

        palette[3].r = 0x00;
        palette[3].g = 0x00;
        palette[3].b = 0x00;
        palette[3].a = 0x00;
    }

    for (int i = 0; i < 16; i++)
    {
        colors[i] = palette[(indices >> (2*i)) & 0x3];
    }
}

static int compareColors(const Color32 * b0, const Color32 * b1)
{
    int sum = 0;
    for (int i = 0; i < 16; i++)
    {
        int r = (b0[i].r - b1[i].r);
        int g = (b0[i].g - b1[i].g);
        int b = (b0[i].b - b1[i].b);
        sum += r*r + g*g + b*b;
    }
    return sum;
}

static int compareBlock(const BlockDXT1 * b0, const BlockDXT1 * b1)
{
    Color32 colors0[16];
    Color32 colors1[16];

    if (memcmp(b0, b1, sizeof(BlockDXT1)) == 0)
    {
        return 0;
    }
    else
    {
        b0->decompress(colors0);
        b1->decompress(colors1);
    
        return compareColors(colors0, colors1);
    }
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) 
{
    shrSetLogFileName ("dxtc.txt");
    shrLog("%s Starting...\n\n", argv[0]); 
    
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    // Load input image.
    unsigned char* data = NULL;
    uint W, H;

    char* image_path = shrFindFilePath(INPUT_IMAGE, argv[0]);
    if (image_path == 0) 
    {
        shrLog("Error, unable to find source image\n");
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }

    if (!shrLoadPPM4ub(image_path, &data, &W, &H)) 
    {
        shrLog("Error, unable to open source image\n");
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }

    uint w, h;
#if __DEVICE_EMULATION__
    // Reduce the image size so that it doesn't take so long on emulation.
    w = W;
    h = H;
#else
    w = W;
    h = H;
#endif
    shrLog("Loaded '%s', %d x %d pixels\n\n", image_path, w, h);

    // Allocate input image.
    const uint memSize = w * h * 4;
    cutilCondition( 0 != memSize );
    uint* block_image = (uint*)malloc(memSize);

    // Convert linear image to block linear. 
    for(uint by = 0; by < h/4; by++) {
        for(uint bx = 0; bx < w/4; bx++) {
            for (int i = 0; i < 16; i++) {
                const int x = i & 3;
                const int y = i / 4;
                block_image[(by * w/4 + bx) * 16 + i] = 
                    ((uint *)data)[(by * 4 + y) * 4 * (W/4) + bx * 4 + x];
            }
        }
    }

    // copy into global mem
    uint * d_data = NULL;
    cutilSafeCall( cudaMalloc((void**) &d_data, memSize) );

    // Result
    uint* d_result = NULL;
    const uint compressedSize = (w / 4) * (h / 4) * 8;
    cutilSafeCall(cudaMalloc((void**)&d_result, compressedSize) );
    uint* h_result = (uint *)malloc(compressedSize);

    // Compute permutations.
    uint permutations[1024];
    computePermutations(permutations);

    // Copy permutations host to devie.
    uint * d_permutations = NULL;    
    cutilSafeCall(cudaMalloc((void**) &d_permutations, 1024 * sizeof(uint)) );
    cutilSafeCall(cudaMemcpy(d_permutations, permutations, 1024 * sizeof(uint), 
                   cudaMemcpyHostToDevice) );

    // create a timer
    uint timer;
    cutilCheckError(cutCreateTimer(&timer));
    
    // Copy image from host to device
    cutilSafeCall(cudaMemcpy(d_data, block_image, memSize, cudaMemcpyHostToDevice) );

    // Determine launch configuration and run timed computation numIterations times
	uint blocks = ((w + 3) / 4) * ((h + 3) / 4); // rounds up by 1 block in each dim if %4 != 0

	int devID;
	cudaDeviceProp deviceProp;

	// get number of SMs on this GPU
	cutilSafeCall(cudaGetDevice(&devID));
	cutilSafeCall(cudaGetDeviceProperties(&deviceProp, devID));

	// Restrict the numbers of blocks to launch on low end GPUs to avoid kernel timeout
	int blocksPerLaunch = min(blocks, 768 * deviceProp.multiProcessorCount);

    shrLog("Running DXT Compression on %u x %u image...\n", w, h);
    shrLog("\n%u Blocks, %u Threads per Block, %u Threads in Grid...\n\n", 
           blocks, NUM_THREADS, blocks * NUM_THREADS);
    int numIterations = 1;
    for (int i = -1; i < numIterations; ++i) {
        if( i == 0 ) { 
            cutilSafeCall(cudaThreadSynchronize()); 
            cutilCheckError(cutStartTimer(timer));   
        }
		
		for( int j=0; j<blocks; j+=blocksPerLaunch ) {
			compress<<<min(blocksPerLaunch, blocks-j), NUM_THREADS>>>(d_permutations, d_data, (uint2 *)d_result, j);
		}
    }
    cutilCheckMsg("compress");

    // sync to host, stop timer, record perf
    cutilSafeCall(cudaThreadSynchronize());
    cutilCheckError(cutStopTimer(timer));
    double dAvgTime = 1.0e-3 * cutGetTimerValue(timer)/(double)numIterations;
    shrLogEx(LOGBOTH | MASTER, 0, "dxtc, Throughput = %.4f MPixels/s, Time = %.5f s, Size = %u Pixels, NumDevsUsed = %i, Workgroup = %d\n", 
           (1.0e-6 * (double)(W * H)/ dAvgTime), dAvgTime, (W * H), 1, NUM_THREADS); 

    // copy result data from device to host
    cutilSafeCall(cudaMemcpy(h_result, d_result, compressedSize, cudaMemcpyDeviceToHost));

    // Write out result data to DDS file
    char output_filename[1024];
    strcpy(output_filename, image_path);
    strcpy(output_filename + strlen(image_path) - 3, "dds");
    FILE* fp = fopen(output_filename, "wb");
    if (fp == 0) {
        shrLog("Error, unable to open output image\n");
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }
    DDSHeader header;
    header.fourcc = FOURCC_DDS;
    header.size = 124;
    header.flags  = (DDSD_WIDTH|DDSD_HEIGHT|DDSD_CAPS|DDSD_PIXELFORMAT|DDSD_LINEARSIZE);
    header.height = h;
    header.width = w;
    header.pitch = compressedSize;
    header.depth = 0;
    header.mipmapcount = 0;
    memset(header.reserved, 0, sizeof(header.reserved));
    header.pf.size = 32;
    header.pf.flags = DDPF_FOURCC;
    header.pf.fourcc = FOURCC_DXT1;
    header.pf.bitcount = 0;
    header.pf.rmask = 0;
    header.pf.gmask = 0;
    header.pf.bmask = 0;
    header.pf.amask = 0;
    header.caps.caps1 = DDSCAPS_TEXTURE;
    header.caps.caps2 = 0;
    header.caps.caps3 = 0;
    header.caps.caps4 = 0;
    header.notused = 0;
    fwrite(&header, sizeof(DDSHeader), 1, fp);
    fwrite(h_result, compressedSize, 1, fp);
    fclose(fp);

    // Make sure the generated image is correct.
    const char* reference_image_path = shrFindFilePath(REFERENCE_IMAGE, argv[0]);
    if (reference_image_path == 0) {
        shrLog("Error, unable to find reference image\n");
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }
    fp = fopen(reference_image_path, "rb");
    if (fp == 0) {
        shrLog("Error, unable to open reference image\n");
        cudaThreadExit();
        exit(EXIT_FAILURE);
    }
    fseek(fp, sizeof(DDSHeader), SEEK_SET);
    uint referenceSize = (W / 4) * (H / 4) * 8;
    uint* reference = (uint *)malloc(referenceSize);
    fread(reference, referenceSize, 1, fp);
    fclose(fp);

    shrLog("\nChecking accuracy...\n");
    float rms = 0;
    for (uint y = 0; y < h; y += 4)
    {
        for (uint x = 0; x < w; x += 4)
        {
            uint referenceBlockIdx = ((y/4) * (W/4) + (x/4));
            uint resultBlockIdx = ((y/4) * (w/4) + (x/4));

            int cmp = compareBlock(((BlockDXT1 *)h_result) + resultBlockIdx, ((BlockDXT1 *)reference) + referenceBlockIdx);
            if (cmp != 0.0f) {
                shrLog("Deviation at (%d, %d):\t%f rms\n", x/4, y/4, float(cmp)/16/3);
            }
            rms += cmp;
        }
    }
    rms /= w * h * 3;
    shrLog("RMS(reference, result) = %f\n\n", rms);
    shrLog("%s\n\n", (rms <= ERROR_THRESHOLD) ? "PASSED" : "FAILED");

    // Free allocated resources and exit
    cutilSafeCall(cudaFree(d_permutations));
    cutilSafeCall(cudaFree(d_data));
    cutilSafeCall(cudaFree(d_result));
    shrFree(image_path);
    free(data);
    free(block_image);
    free(h_result);
    free(reference);
    cutilCheckError(cutDeleteTimer(timer));
    cudaThreadExit();
    shrEXIT(argc, (const char**)argv);
}
