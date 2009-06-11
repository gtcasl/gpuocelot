/*!
	\file matmult.cu
	
	\author Andrew Kerr <arkerr@gatech.edu>

	\brief use whatever you have to achieve fast (~150 GFLOP/s) matrix multiply on a GPU
*/


#include <stdlib.h>
#include <math.h>
#define CEIL_DIV(a,b) (((a) == ((a)/(b)) * (b)) ?  ((a)/(b)):((a)/(b)+1) )


///////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Performs matrix multiplication
*/
__global__ void k_matMult_naive(
	float *A,
	float *B,
	float *C,
	int A_rows,
	int A_cols,
	int B_cols) {

#define BW 16

	int k;

	__shared__ float A_block[BW][BW];
	__shared__ float B_block[BW][BW];


	float *a_ptr = A + (blockIdx.y * blockDim.y + threadIdx.y) * A_cols + threadIdx.x;
	float *b_ptr = B + blockIdx.x * blockDim.x + threadIdx.x + threadIdx.y * B_cols;

	float c_v = 0;

	for (k = 0; k < A_cols; k += BW) {
		int j;

		A_block[threadIdx.y][threadIdx.x] = *a_ptr;
		__syncthreads();
		B_block[threadIdx.y][threadIdx.x] = *b_ptr;
		__syncthreads();

		for (j = 0; j < BW; j++) {
			c_v += A_block[threadIdx.y][j] * B_block[j][threadIdx.x];
		}
		__syncthreads();
		a_ptr += BW;
		b_ptr += BW * B_cols;
	}

	
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	C[row * B_cols + col] = c_v;
}

void matrix_multiply_naive(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
	dim3 grid(A_rows / 16, B_cols / 16);
	dim3 block(16, 16);
	k_matMult_naive<<< grid, block >>>(A, B, C, A_rows, A_cols, B_cols);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

__global__ void k_matMult_unroll(
  float *A,
  float *B,
  float *C,
  int A_rows,
  int A_cols,
  int B_cols) {

#define BW 16

  int k;

  __shared__ float A_block[BW][BW];
  __shared__ float B_block[BW][BW*2];


  float *a_ptr = A + (blockIdx.y * blockDim.y + threadIdx.y) * A_cols + threadIdx.x;
  float *b_ptr = B + 2 * blockIdx.x * blockDim.x + threadIdx.x + threadIdx.y * B_cols;

  float c_v0 = 0;
	float c_v1 = 0;

  for (k = 0; k < A_cols; k += BW) {

    A_block[threadIdx.y][threadIdx.x] = *a_ptr;
    __syncthreads();
    B_block[threadIdx.y][threadIdx.x] = b_ptr[0];
		B_block[threadIdx.y][threadIdx.x+blockDim.x] = b_ptr[blockDim.x];
    __syncthreads();

		int X = threadIdx.x;
		int Y = threadIdx.y;

    float a00 = A_block[Y][0];
    float a01 = A_block[Y][1];
    float a02 = A_block[Y][2];
    float a03 = A_block[Y][3];
    float a04 = A_block[Y][4];
    float a05 = A_block[Y][5];
    float a06 = A_block[Y][6];
    float a07 = A_block[Y][7];
    float a08 = A_block[Y][8];
    float a09 = A_block[Y][9];
    float a10 = A_block[Y][10];
    float a11 = A_block[Y][11];
    float a12 = A_block[Y][12];
    float a13 = A_block[Y][13];
    float a14 = A_block[Y][14];
    float a15 = A_block[Y][15];

		c_v0 += a00 * B_block[0][X];
		c_v0 += a01 * B_block[1][X];
		c_v0 += a02 * B_block[2][X];
		c_v0 += a03 * B_block[3][X];
		c_v0 += a04 * B_block[4][X];
		c_v0 += a05 * B_block[5][X];
		c_v0 += a06 * B_block[6][X];
		c_v0 += a07 * B_block[7][X];
		c_v0 += a08 * B_block[8][X];
		c_v0 += a09 * B_block[9][X];
		c_v0 += a10 * B_block[10][X];
		c_v0 += a11 * B_block[11][X];
		c_v0 += a12 * B_block[12][X];
		c_v0 += a13 * B_block[13][X];
		c_v0 += a14 * B_block[14][X];
		c_v0 += a15 * B_block[15][X];

		X = threadIdx.x + BW;

    c_v1 += a00 * B_block[0][X];
		c_v1 += a01 * B_block[1][X];
    c_v1 += a02 * B_block[2][X];
		c_v1 += a03 * B_block[3][X];
    c_v1 += a04 * B_block[4][X];
		c_v1 += a05 * B_block[5][X];
    c_v1 += a06 * B_block[6][X];
		c_v1 += a07 * B_block[7][X];
    c_v1 += a08 * B_block[8][X];
		c_v1 += a09 * B_block[9][X];
    c_v1 += a10 * B_block[10][X];
		c_v1 += a11 * B_block[11][X];
    c_v1 += a12 * B_block[12][X];
		c_v1 += a13 * B_block[13][X];
    c_v1 += a14 * B_block[14][X];
		c_v1 += a15 * B_block[15][X];

    __syncthreads();
    a_ptr += BW;
    b_ptr += BW * B_cols;
  }

  int col = blockIdx.x * 2 * blockDim.x + threadIdx.x;
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  C[row * B_cols + col] = c_v0;
	C[row * B_cols + col + blockDim.x] = c_v1;
}

void matrix_multiply_unroll(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
  dim3 grid(B_cols / 32, A_rows / 16);
  dim3 block(16, 16);
  k_matMult_unroll<<< grid, block >>>(A, B, C, A_rows, A_cols, B_cols);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Macros used by k_matMul_unroll2

#define INNER_PROD(cc) { \
		cc += a00 * B_block[0][X];	\
		cc += a01 * B_block[1][X];	\
		cc += a02 * B_block[2][X];	\
		cc += a03 * B_block[3][X];	\
		cc += a04 * B_block[4][X];	\
		cc += a05 * B_block[5][X];	\
		cc += a06 * B_block[6][X];	\
		cc += a07 * B_block[7][X];	\
		cc += a08 * B_block[8][X];	\
		cc += a09 * B_block[9][X];	\
		cc += a10 * B_block[10][X];	\
		cc += a11 * B_block[11][X];	\
		cc += a12 * B_block[12][X];	\
		cc += a13 * B_block[13][X];	\
		cc += a14 * B_block[14][X];	\
		cc += a15 * B_block[15][X];	\
	}

#define LOAD_A_REGS() {		\
		a00 = A_block[Y][0];	\
    a01 = A_block[Y][1];	\
    a02 = A_block[Y][2];	\
    a03 = A_block[Y][3];	\
    a04 = A_block[Y][4];	\
    a05 = A_block[Y][5];	\
    a06 = A_block[Y][6];	\
    a07 = A_block[Y][7];	\
    a08 = A_block[Y][8];	\
    a09 = A_block[Y][9];	\
    a10 = A_block[Y][10];	\
    a11 = A_block[Y][11];	\
    a12 = A_block[Y][12];	\
    a13 = A_block[Y][13];	\
    a14 = A_block[Y][14];	\
    a15 = A_block[Y][15];	\
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
	Assumes A, B, and C are unit-stride and row-major. A_rows, A_cols, B_cols are all divisible by 64
*/
__global__ void k_matMult_unroll2(
  float *A,
  float *B,
  float *C,
  int A_rows,
  int A_cols,
  int B_cols) {

#define BW 16

  int k;

  __shared__ float A_block[BW*4][BW];
  __shared__ float B_block[BW][BW*4];

	int col = blockIdx.x * blockDim.x * 4 + threadIdx.x;
  int row = 4 * blockIdx.y * blockDim.y + threadIdx.y;
	C += row * B_cols + col;

  float *a_ptr = A + row * A_cols + threadIdx.x;
  float *b_ptr = B + col + threadIdx.y * B_cols;

  float c_v00 = 0;
	float c_v01 = 0;
	float c_v02 = 0;
	float c_v03 = 0;
  float c_v10 = 0;
	float c_v11 = 0;
	float c_v12 = 0;
	float c_v13 = 0;
	
  float c_v20 = 0;
	float c_v21 = 0;
	float c_v22 = 0;
	float c_v23 = 0;
  float c_v30 = 0;
	float c_v31 = 0;
	float c_v32 = 0;
	float c_v33 = 0;


  for (k = 0; k < A_cols; k += BW) {

    A_block[threadIdx.y][threadIdx.x] = a_ptr[0];
		A_block[threadIdx.y + BW][threadIdx.x] = a_ptr[BW*A_cols];
    __syncthreads();
    B_block[threadIdx.y][threadIdx.x] = b_ptr[0];
		B_block[threadIdx.y][threadIdx.x+blockDim.x] = b_ptr[blockDim.x];
		B_block[threadIdx.y][threadIdx.x+blockDim.x*2] = b_ptr[blockDim.x*2];
		B_block[threadIdx.y][threadIdx.x+blockDim.x*3] = b_ptr[blockDim.x*3];
		A_block[threadIdx.y + BW*2][threadIdx.x] = a_ptr[BW*A_cols*2];
		A_block[threadIdx.y + BW*3][threadIdx.x] = a_ptr[BW*A_cols*3];
		__syncthreads();

		int X, Y;		float a00, a01, a02, a03, a04, a05, a06, a07;
		float a08, a09, a10, a11, a12, a13, a14, a15;

		Y = threadIdx.y;
		LOAD_A_REGS();
		X = threadIdx.x;
		INNER_PROD(c_v00);

		X += BW;
		INNER_PROD(c_v01);
		
		X += BW;
		INNER_PROD(c_v02);

		X += BW;
		INNER_PROD(c_v03);
		
		__syncthreads();
		
		Y += BW;
		LOAD_A_REGS();

		X = threadIdx.x;
		INNER_PROD(c_v10);

		X += BW;
		INNER_PROD(c_v11);
		
		X += BW;
		INNER_PROD(c_v12);

		X += BW;
		INNER_PROD(c_v13);

		__syncthreads();
		
		Y += BW;
		LOAD_A_REGS();
		
		X = threadIdx.x;
		INNER_PROD(c_v20);

		X += BW;
		INNER_PROD(c_v21);
		
		X += BW;
		INNER_PROD(c_v22);

		X += BW;
		INNER_PROD(c_v23);

		__syncthreads();
		
		Y += BW;
		LOAD_A_REGS();
		
		X = threadIdx.x;
		INNER_PROD(c_v30);

		X += BW;
		INNER_PROD(c_v31);
		
		X += BW;
		INNER_PROD(c_v32);

		X += BW;
		INNER_PROD(c_v33);

    a_ptr += BW;
    b_ptr += BW * B_cols;
  }

  C[0] = c_v00;
	C[blockDim.x] = c_v01;
  C[blockDim.x*2] = c_v02;
	C[blockDim.x*3] = c_v03;
	
	C += B_cols * BW;
  C[0] = c_v10;
	C[blockDim.x] = c_v11;
  C[blockDim.x*2] = c_v12;
	C[blockDim.x*3] = c_v13;
	
	C += B_cols * BW;
  C[0] = c_v20;
	C[blockDim.x] = c_v21;
  C[blockDim.x*2] = c_v22;
	C[blockDim.x*3] = c_v23;
	
	C += B_cols * BW;
  C[0] = c_v30;
	C[blockDim.x] = c_v31;
  C[blockDim.x*2] = c_v32;
	C[blockDim.x*3] = c_v33;
}

void matrix_multiply_unroll2(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
  dim3 grid(B_cols / 64, A_rows / 64);
  dim3 block(16, 16);
  k_matMult_unroll2<<< grid, block >>>(A, B, C, A_rows, A_cols, B_cols);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//
//	SGEMM routines
//
__device__ void saxpy( float a, float *b, float *c )
{
	c[0] += a*b[0];
	c[1] += a*b[1];
	c[2] += a*b[2];
	c[3] += a*b[3];
	c[4] += a*b[4];
	c[5] += a*b[5];
	c[6] += a*b[6];
	c[7] += a*b[7];
	c[8] += a*b[8];
	c[9] += a*b[9];
	c[10] += a*b[10];
	c[11] += a*b[11];
	c[12] += a*b[12];
	c[13] += a*b[13];
	c[14] += a*b[14];
	c[15] += a*b[15];
}
__global__ void sgemmNN( const float *A, int lda, const float *B,
	int ldb, float* C, int ldc, int k, float alpha, float beta )
{
	const int inx = threadIdx.x;
	const int iny = threadIdx.y;
	const int ibx = blockIdx.x * 64;
	const int iby = blockIdx.y * 16;
	const int id = inx + iny*16;
	
	A += ibx + id;
	B += inx + __mul24( iby + iny, ldb );
	C += ibx + id  + __mul24( iby, ldc );
	
	const float *Blast = B + k;
	
	float c[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
	do
	{
		float a[4] = { A[0*lda], A[1*lda], A[2*lda], A[3*lda] };

		__shared__ float bs[16][17];
		bs[inx][iny]    = B[0*ldb];
		bs[inx][iny+4]  = B[4*ldb];
		bs[inx][iny+8]  = B[8*ldb];
		bs[inx][iny+12] = B[12*ldb];
		__syncthreads();

		A += 4*lda;
		saxpy( a[0], &bs[0][0], c );		a[0] = A[0*lda];
		saxpy( a[1], &bs[1][0], c );		a[1] = A[1*lda];
		saxpy( a[2], &bs[2][0], c );		a[2] = A[2*lda];
		saxpy( a[3], &bs[3][0], c );		a[3] = A[3*lda];	

		A += 4*lda;
		saxpy( a[0], &bs[4][0], c );		a[0] = A[0*lda];
		saxpy( a[1], &bs[5][0], c );		a[1] = A[1*lda];
		saxpy( a[2], &bs[6][0], c );		a[2] = A[2*lda];
		saxpy( a[3], &bs[7][0], c );		a[3] = A[3*lda];
		
		A += 4*lda;
		saxpy( a[0], &bs[8][0], c );		a[0] = A[0*lda];
		saxpy( a[1], &bs[9][0], c );		a[1] = A[1*lda];
		saxpy( a[2], &bs[10][0], c );		a[2] = A[2*lda];
		saxpy( a[3], &bs[11][0], c );		a[3] = A[3*lda];
		
		A += 4*lda;
		saxpy( a[0], &bs[12][0], c );
		saxpy( a[1], &bs[13][0], c );
		saxpy( a[2], &bs[14][0], c );
		saxpy( a[3], &bs[15][0], c );
		
		B += 16;
		__syncthreads();
	} while( B < Blast );
	
	for( int i = 0; i < 16; i++, C += ldc )
		C[0] = alpha*c[i] + beta*C[0]; 
}	

void matrix_multiply_volvok(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
	dim3 grid(CEIL_DIV(A_rows, 64), CEIL_DIV(B_cols, 16));
	dim3 block(16, 4);
	
	sgemmNN<<< grid, block >>>(A, A_rows, B,
		A_cols, C, A_rows, A_cols, 1, 0 );
	//k_matMult_volvok<<< grid, block >>>(A, B, C, A_rows, A_cols, B_cols);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void matrix_multiply_GPU(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
	//matrix_multiply_unroll2(A, B, C, A_rows, A_cols, B_cols);
	matrix_multiply_volvok(A, B, C, A_rows, A_cols, B_cols);
	//matrix_multiply_naive(A, B, C, A_rows, A_cols, B_cols);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

__global__ void k_fill_matrix(float *A, int M, int N, float s) {
	int row = blockDim.y * blockIdx.y + threadIdx.y;
	int col = blockDim.x * blockIdx.x + threadIdx.x;
	if (row < M && col < N) {
		A[row * N + col] = s;
	}
}

extern "C" void fill_matrix(float *A, int M, int N, float s) {
	dim3 grid(CEIL_DIV(N, 16), CEIL_DIV(M, 16) );
	dim3 block(16, 16);
	k_fill_matrix<<< grid, block >>>(A, M, N, s);
}



