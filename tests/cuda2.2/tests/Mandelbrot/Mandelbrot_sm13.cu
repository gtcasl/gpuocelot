#include <stdio.h>
#include "cutil_inline.h"
#include "Mandelbrot_kernel.h"
#include "Mandelbrot_kernel.cu"

// The Mandelbrot CUDA GPU thread function

/*
    Version using software scheduling of thread blocks.
    
    The idea here is to launch of fixed number of worker blocks to fill the
    machine, and have each block loop over the available work until it is all done.
    
    We use a counter in global memory to keep track of which blocks have been
    completed. The counter is incremented atomically by each worker block.
    
    This method can achieve higher performance when blocks take a wide range of
    different times to complete.
*/

__device__ unsigned int blockCounter;   // global counter, initialized to zero before kernel launch

template<class T>
__global__ void Mandelbrot0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, 
								 const T xJP, const T yJP, const T scale, const uchar4 colors, const int frame, 
								 const int animationFrame, const int gridWidth, const int numBlocks, const bool isJ)
{
    __shared__ unsigned int blockIndex;
    __shared__ unsigned int blockX, blockY;
    
     if ((threadIdx.x==0) && (threadIdx.y==0)) {
        // get block to process
        blockIndex = atomicAdd(&blockCounter, 1);
        blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
        blockY = blockIndex / gridWidth;
    }
    __syncthreads();

   // loop until all blocks completed
    while(blockIndex < numBlocks) {
 
        // process this block
        const int ix = blockDim.x * blockX + threadIdx.x;
        const int iy = blockDim.y * blockY + threadIdx.y;

        if ((ix < imageW) && (iy < imageH)) {
		    // Calculate the location
		    const T xPos = (T)ix * scale + xOff;
		    const T yPos = (T)iy * scale + yOff;
    		
            // Calculate the Mandelbrot index for the current location
            int m = CalcMandelbrot<T>(xPos, yPos, xJP, yJP, crunch, isJ);
//            int m = blockIdx.x;         // uncomment to see scheduling order
            m = m > 0 ? crunch - m : 0;
    			
            // Convert the Mandelbrot index into a color
            uchar4 color;
            if (m) {
			    m += animationFrame;
			    color.x = m * colors.x;
			    color.y = m * colors.y;
			    color.z = m * colors.z;
		    } else {
			    color.x = 0;
			    color.y = 0;
			    color.z = 0;
		    }
    		
            // Output the pixel
 		    int pixel = imageW * iy + ix;
            if (frame == 0) {
			    color.w = 0;
			    dst[pixel] = color;
            } else {
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (dst[pixel].x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (dst[pixel].y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (dst[pixel].z * frame + color.z + frame2) / frame1;
            }
        }
        
		__syncthreads();
		if ((threadIdx.x==0) && (threadIdx.y==0)) {
		    // get block to process
		    blockIndex = atomicAdd(&blockCounter, 1);
		    blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
		    blockY = blockIndex / gridWidth;
		}
		__syncthreads();


    }
    
} // Mandelbrot0


// The Mandelbrot CUDA GPU thread function (double single version)
__global__ void MandelbrotDS0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff0, const float xOff1, 
								   const float yOff0, const float yOff1, const float xJP, const float yJP, const float scale, 
								   const uchar4 colors, const int frame, const int animationFrame, const int gridWidth, 
								   const int numBlocks, const bool isJ)
{
    __shared__ unsigned int blockIndex;
    __shared__ unsigned int blockX, blockY;

    if ((threadIdx.x==0) && (threadIdx.y==0)) {
        // get block to process
        blockIndex = atomicAdd(&blockCounter, 1);
        blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
        blockY = blockIndex / gridWidth;
    }
    __syncthreads();
    
    // loop until all blocks completed
    while(blockIndex < numBlocks) {

        // process this block
        const int ix = blockDim.x * blockX + threadIdx.x;
        const int iy = blockDim.y * blockY + threadIdx.y;

        if ((ix < imageW) && (iy < imageH)) {
		    // Calculate the location
		    float xPos0 = (float)ix * scale;
		    float xPos1 = 0.0f;
		    float yPos0 = (float)iy * scale;
		    float yPos1 = 0.0f;
		    dsadd(xPos0, xPos1, xPos0, xPos1, xOff0, xOff1);
		    dsadd(yPos0, yPos1, yPos0, yPos1, yOff0, yOff1);

            // Calculate the Mandelbrot index for the current location
            int m = CalcMandelbrotDS(xPos0, xPos1, yPos0, yPos1, xJP, yJP, crunch, isJ);
            m = m > 0 ? crunch - m : 0;
    			
            // Convert the Mandelbrot index into a color
            uchar4 color;
            if (m) {
			    m += animationFrame;
			    color.x = m * colors.x;
			    color.y = m * colors.y;
			    color.z = m * colors.z;
		    } else {
			    color.x = 0;
			    color.y = 0;
			    color.z = 0;
		    }
    		
            // Output the pixel
 		    int pixel = imageW * iy + ix;
            if (frame == 0) {
			    color.w = 0;
			    dst[pixel] = color;
            } else {
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (dst[pixel].x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (dst[pixel].y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (dst[pixel].z * frame + color.z + frame2) / frame1;
            }
        }
		__syncthreads();
		if ((threadIdx.x==0) && (threadIdx.y==0)) {
		    // get block to process
		    blockIndex = atomicAdd(&blockCounter, 1);
		    blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
		    blockY = blockIndex / gridWidth;
		}
		__syncthreads();
        
    }
} // MandelbrotDS0

// The Mandelbrot secondary AA pass CUDA GPU thread function
template<class T>
__global__ void Mandelbrot1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, 
								 const T xJP, const T yJP, const T scale, const uchar4 colors, const int frame, 
								 const int animationFrame, const int gridWidth, const int numBlocks, const bool isJ)
{
    __shared__ unsigned int blockIndex;
    __shared__ unsigned int blockX, blockY;

    if ((threadIdx.x==0) && (threadIdx.y==0)) {
        // get block to process
        blockIndex = atomicAdd(&blockCounter, 1);
        blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
        blockY = blockIndex / gridWidth;
    }

    __syncthreads();    

    // loop until all blocks completed
    while(blockIndex < numBlocks) {

       // process this block
        const int ix = blockDim.x * blockX + threadIdx.x;
        const int iy = blockDim.y * blockY + threadIdx.y;

        if ((ix < imageW) && (iy < imageH)) {
		    // Get the current pixel color
 		    int pixel = imageW * iy + ix;
		    uchar4 pixelColor = dst[pixel];
		    int count = 0;
    		
		    // Search for pixels out of tolerance surrounding the current pixel
		    if (ix > 0)
			    count += CheckColors(pixelColor, dst[pixel - 1]);
		    if (ix + 1 < imageW)
			    count += CheckColors(pixelColor, dst[pixel + 1]);
		    if (iy > 0)
			    count += CheckColors(pixelColor, dst[pixel - imageW]);
		    if (iy + 1 < imageH)
			    count += CheckColors(pixelColor, dst[pixel + imageW]);
		    if (count) {
			    // Calculate the location
			    const T xPos = (T)ix * scale + xOff;
			    const T yPos = (T)iy * scale + yOff;
    			      
			    // Calculate the Mandelbrot index for the current location
			    int m = CalcMandelbrot(xPos, yPos, xJP, yJP, crunch, isJ);
			    m = m > 0 ? crunch - m : 0;
    	        
			    // Convert the Mandelbrot index into a color
			    uchar4 color;
			    if (m) {
				    m += animationFrame;
				    color.x = m * colors.x;
				    color.y = m * colors.y;
				    color.z = m * colors.z;
			    } else {
				    color.x = 0;
				    color.y = 0;
				    color.z = 0;
			    }
    			
			    // Output the pixel
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (pixelColor.x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (pixelColor.y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (pixelColor.z * frame + color.z + frame2) / frame1;
		    }
        }
        __syncthreads();
        
          if ((threadIdx.x==0) && (threadIdx.y==0)) {
        // get block to process
		    blockIndex = atomicAdd(&blockCounter, 1);
		    blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
		    blockY = blockIndex / gridWidth;
		}

		__syncthreads();
    }
    
} // Mandelbrot1

// The Mandelbrot secondary AA pass CUDA GPU thread function (double single version)
__global__ void MandelbrotDS1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, 
								   const float xOff0, const float xOff1, const float yOff0, const float yOff1, 
								   const float xJP, const float yJP, const float scale, const uchar4 colors, 
								   const int frame, const int animationFrame, const int gridWidth, const int numBlocks, const bool isJ)
{
    __shared__ unsigned int blockIndex;
    __shared__ unsigned int blockX, blockY;
    
    
      if ((threadIdx.x==0) && (threadIdx.y==0)) {
    // get block to process
	    blockIndex = atomicAdd(&blockCounter, 1);
	    blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
	    blockY = blockIndex / gridWidth;
	}

	__syncthreads();
    
    // loop until all blocks completed
    while(blockIndex < numBlocks) {

        if (blockIndex >= numBlocks) break;  // finish

        // process this block
        const int ix = blockDim.x * blockX + threadIdx.x;
        const int iy = blockDim.y * blockY + threadIdx.y;

        if ((ix < imageW) && (iy < imageH)) {
		    // Get the current pixel color
 		    int pixel = imageW * iy + ix;
		    uchar4 pixelColor = dst[pixel];
		    int count = 0;
    		
		    // Search for pixels out of tolerance surrounding the current pixel
		    if (ix > 0)
			    count += CheckColors(pixelColor, dst[pixel - 1]);
		    if (ix + 1 < imageW)
			    count += CheckColors(pixelColor, dst[pixel + 1]);
		    if (iy > 0)
			    count += CheckColors(pixelColor, dst[pixel - imageW]);
		    if (iy + 1 < imageH)
			    count += CheckColors(pixelColor, dst[pixel + imageW]);
		    if (count) {
			    // Calculate the location
			    float xPos0 = (float)ix * scale;
			    float xPos1 = 0.0f;
			    float yPos0 = (float)iy * scale;
			    float yPos1 = 0.0f;
			    dsadd(xPos0, xPos1, xPos0, xPos1, xOff0, xOff1);
			    dsadd(yPos0, yPos1, yPos0, yPos1, yOff0, yOff1);
    			      
			    // Calculate the Mandelbrot index for the current location
			    int m = CalcMandelbrotDS(xPos0, xPos1, yPos0, yPos1, xJP, yJP, crunch, isJ);
			    m = m > 0 ? crunch - m : 0;
    	        
			    // Convert the Mandelbrot index into a color
			    uchar4 color;
			    if (m) {
				    m += animationFrame;
				    color.x = m * colors.x;
				    color.y = m * colors.y;
				    color.z = m * colors.z;
			    } else {
				    color.x = 0;
				    color.y = 0;
				    color.z = 0;
			    }
    			
			    // Output the pixel
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (pixelColor.x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (pixelColor.y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (pixelColor.z * frame + color.z + frame2) / frame1;
		    }
        }
    	
        __syncthreads();
        
          if ((threadIdx.x==0) && (threadIdx.y==0)) {
        // get block to process
		    blockIndex = atomicAdd(&blockCounter, 1);
		    blockX = blockIndex % gridWidth;            // note: this is slow, but only called once per block here
		    blockY = blockIndex / gridWidth;
		}

		__syncthreads();
    }
    
} // MandelbrotDS1

// The host CPU Mandebrot thread spawner
void RunMandelbrot0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, 
						 const double xjp, const double yjp, const double scale, const uchar4 colors, const int frame, 
						 const int animationFrame, const int mode, const int numSMs, const bool isJ)
{
    dim3 threads(BLOCKDIM_X, BLOCKDIM_Y);
    dim3 grid(iDivUp(imageW, BLOCKDIM_X), iDivUp(imageH, BLOCKDIM_Y));

    // zero block counter
    unsigned int hBlockCounter = 0;
    cutilSafeCall( cudaMemcpyToSymbol(blockCounter, &hBlockCounter, sizeof(unsigned int), 0, cudaMemcpyHostToDevice ) );

    int numWorkerBlocks = numSMs;

	switch(mode) {
    default:
    case 0:
	    Mandelbrot0_sm13<float><<<numWorkerBlocks, threads>>>(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, 
			(float)xjp, (float)yjp, (float)scale, colors, frame, animationFrame, grid.x, grid.x*grid.y, isJ);
        break;
    case 1:
		float x0, x1, y0, y1;
		dsdeq(x0, x1, xOff);
		dsdeq(y0, y1, yOff);
		MandelbrotDS0_sm13<<<numWorkerBlocks, threads>>>(dst, imageW, imageH, crunch, x0, x1, y0, y1, 
			xjp, yjp, (float)scale, colors, frame, animationFrame, grid.x, grid.x*grid.y, isJ);
        break;
    case 2:
		Mandelbrot0_sm13<double><<<numWorkerBlocks, threads>>>(dst, imageW, imageH, crunch, xOff, yOff, 
			xjp, yjp, scale, colors, frame, animationFrame, grid.x, grid.x*grid.y, isJ);
        break;
    }
    cutilCheckMsg("Mandelbrot0_sm13 kernel execution failed.\n");
} // RunMandelbrot0

// The host CPU Mandebrot thread spawner
void RunMandelbrot1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, 
						 const double xjp, const double yjp, const double scale, const uchar4 colors, const int frame, 
						 const int animationFrame, const int mode, const int numSMs, const bool isJ)
{
    dim3 threads(BLOCKDIM_X, BLOCKDIM_Y);
    dim3 grid(iDivUp(imageW, BLOCKDIM_X), iDivUp(imageH, BLOCKDIM_Y));

    // zero block counter
    unsigned int hBlockCounter = 0;
    cutilSafeCall( cudaMemcpyToSymbol(blockCounter, &hBlockCounter, sizeof(unsigned int), 0, cudaMemcpyHostToDevice ) );

    int numWorkerBlocks = numSMs;

	switch(mode) {
    default:
    case 0:
		Mandelbrot1_sm13<float><<<numWorkerBlocks, threads>>>(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, 
			(float)xjp, (float)yjp, (float)scale, colors, frame, animationFrame, grid.x, grid.x*grid.y, isJ);
        break;
    case 1:
		float x0, x1, y0, y1;
		dsdeq(x0, x1, xOff);
		dsdeq(y0, y1, yOff);
		MandelbrotDS1_sm13<<<numWorkerBlocks, threads>>>(dst, imageW, imageH, crunch, x0, x1, y0, y1, 
			xjp, yjp, (float)scale, colors, frame, animationFrame, grid.x, grid.x*grid.y, isJ);
        break;
    case 2:
		Mandelbrot1_sm13<double><<<numWorkerBlocks, threads>>>(dst, imageW, imageH, crunch, xOff, yOff, 
			xjp, yjp, scale, colors, frame, animationFrame, grid.x, grid.x*grid.y, isJ);
        break;
	}

    cutilCheckMsg("Mandelbrot1_sm13 kernel execution failed.\n");
} // RunMandelbrot1


// check if we're running in emulation mode
int inEmulationMode()
{
#if 1
    return 1;
#else
    return 0;
#endif
} // inEmulationMode
