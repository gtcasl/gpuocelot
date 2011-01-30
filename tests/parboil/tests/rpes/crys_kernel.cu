/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#define BLOCK_SIZE 64
#define LOG_BLOCK_SIZE 6
#define GRID_SIZE 65535
#define TABLESIZE 2
#define LOG_TABLE_WIDTH 2
#define TABLE_HEIGHT (TABLESIZE >> LOG_TABLE_WIDTH)
#define W_MAX_SIZE 10

__global__ void ComputeX(uint4*, float*, int);

__device__ float product1D(float, float, float, float, float);
__device__ float dist2(float3, float3);
__device__ float dist2(float4, float4);
__device__ float3 ReducePair(float4, float4, float2, float2, float);
__device__ float ComputeI(float, float, float, float, 
			  float, float, float, float);
__device__ float Root(float X);

__device__ void GetBases(int, int, int, int&, int&, int&, int&, int&);
__device__ void GetAtoms(int, int&, int&, int&, int&);
__device__ void GetOffsets(int, int&, int&, int&, int&);
__device__ void GetNs(int, int, int, int, int, int&, int&, int&, int&);
__device__ void KahanSum(float&, float, float&, float&, float&);

texture<float4, 1, cudaReadModeElementType> texCoors;
texture<float2, 1, cudaReadModeElementType> texSprms;
texture<float , 1, cudaReadModeElementType> texWghts;

__global__ 
void ComputeX(uint4* d_Work, float* d_Output, int Offset)
{
  __shared__ float Data[BLOCK_SIZE];
  __shared__ uint4 s_Work;
  
  int blid = blockIdx.x;
  int thid = threadIdx.x;
  
  int myWorkIndex = ((Offset + blid) << LOG_BLOCK_SIZE) + thid;
  if(!thid)
    s_Work = d_Work[Offset + blid];
  __syncthreads();
  uint4 myWork = s_Work;
  
  int localthid, a1, a2, a3, a4;
  GetBases(myWork.x, myWorkIndex, myWork.w,
	   localthid, a1, a2, a3, a4);
  
  float Result = 0.0f;
  int Maxthid = __mul24(a1, __mul24(a2, __mul24(a3, a4)));
  if(localthid < Maxthid)
    {
      int n1, n2, n3, n4;
      int off1, off2, off3, off4;
      int atom1, atom2, atom3, atom4;
      
      GetAtoms(myWork.y, atom1, atom2, atom3, atom4);
      GetNs(localthid, a1, a2, a3, a4, n1, n2, n3, n4);
      GetOffsets(myWork.z, off1, off2, off3, off4);
      n1 += off1;
      n2 += off2;
      n3 += off3;
      n4 += off4;
      
      float4 Atom1 = tex1D(texCoors, (float)atom1);
      float4 Atom2 = tex1D(texCoors, (float)atom2);
      float4 Atom3 = tex1D(texCoors, (float)atom3);
      float4 Atom4 = tex1D(texCoors, (float)atom4);
      float2 Param1 = tex1D(texSprms, (float)n1);
      float2 Param2 = tex1D(texSprms, (float)n2);
      float2 Param3 = tex1D(texSprms, (float)n3);
      float2 Param4 = tex1D(texSprms, (float)n4);
      
      float R12 = dist2(Atom1, Atom2);
      float R34 = dist2(Atom3, Atom4);
      float sum12  = Param1.x + Param2.x;
      float sum34  = Param3.x + Param4.x;
      float prod12 = Param1.x * Param2.x;
      float prod34 = Param3.x * Param4.x;
      float preexp = __fdividef(prod12, sum12) * R12 + 
	__fdividef(prod34, sum34) * R34;
      float preintegral = __fdividef(Param1.y * Param2.y * Param3.y * 
				     Param4.y * __expf(- preexp), sum12 * 
				     sum34) * (1 / sqrtf(sum12 + sum34));

      if(preintegral * preintegral > 1.0e-23f)
	{
	  float3 Atomp = ReducePair(Atom1, Atom2, Param1, Param2, sum12);
	  float3 Atomq = ReducePair(Atom3, Atom4, Param3, Param4, sum34);
	  
	  float rpq2 = dist2(Atomp, Atomq);
	  float rho = __fdividef(sum12 * sum34, sum12 + sum34);
	  float weight = Root(rpq2 * rho);
	  Result = 34.98683666f * preintegral * weight;
	}
    }
  Data[thid] = Result;
  __syncthreads();

  for(unsigned int s = blockDim.x>>1; s > 0;  s = s>>1)
    {
      if (thid < s)
        Data[thid] += Data[thid+s];
      __syncthreads();
    }

  if(!thid)
    d_Output[Offset + blid] = Data[0];
}

__global__ 
void DoReduction(float* d_ReductionSum, float* d_Output, 
			    uint2* d_FinalReduce, int block_size, int Offset)
{
  int firstElement;
  int offset;
  __shared__ float Result[BLOCK_SIZE];
  
  int blid = blockIdx.x;
  int thid = threadIdx.x;
  
  uint2 myWork = d_FinalReduce[blid + Offset];
  firstElement = myWork.x;
  offset = myWork.y;
  
  if(thid < offset)
    Result[thid] = d_Output[firstElement + thid];
  else
    Result[thid] = 0.0f;
  __syncthreads();

  for(unsigned int s = blockDim.x>>1; s > 0;  s = s>>1)
    {
      if (thid < s)
        Result[thid] += Result[thid+s];
      __syncthreads();
    }

  if(!thid)
    d_ReductionSum[blid + Offset] = Result[0];
}

__device__ 
float product1D(float alpha_a, float coor_a, float alpha_b, 
			   float coor_b, float sum_ab)
{
  return __fdividef(alpha_a * coor_a + alpha_b * coor_b, sum_ab);
}

__device__ 
float dist2(float3 Atom1, float3 Atom2)
{
  float dx = Atom1.x - Atom2.x;
  float dy = Atom1.y - Atom2.y;
  float dz = Atom1.z - Atom2.z;
  return dx * dx + dy * dy + dz * dz;
}

__device__ 
float dist2(float4 Atom1, float4 Atom2)
{
  float dx = Atom1.x - Atom2.x;
  float dy = Atom1.y - Atom2.y;
  float dz = Atom1.z - Atom2.z;
  return dx * dx + dy * dy + dz * dz;
}

__device__ 
float3 ReducePair(float4 Atom1, float4 Atom2, float2 Param1, 
		  float2 Param2, float sum_12)
{
  float3 Atomp;
  Atomp.x = product1D(Param1.x, Atom1.x, Param2.x, Atom2.x, sum_12);
  Atomp.y = product1D(Param1.x, Atom1.y, Param2.x, Atom2.y, sum_12);
  Atomp.z = product1D(Param1.x, Atom1.z, Param2.x, Atom2.z, sum_12);
  
  return Atomp;
}

__device__ 
float Root(float X)
{
  float rPIE4;
  float WW1 = 0.0f;
  float F1,E,Y,inv;
  
  rPIE4 = 1.273239545f;
  if (X < 3.0e-7f)
    {
      WW1 = 1.0f - 0.333333333f * X;
    } 
  else if (X < 1.0f) 
    {
      F1 = ((((((((-8.36313918003957E-08f*X+1.21222603512827E-06f )*X-
		  1.15662609053481E-05f )*X+9.25197374512647E-05f )*X-
		6.40994113129432E-04f )*X+3.78787044215009E-03f )*X-
	      1.85185172458485E-02f )*X+7.14285713298222E-02f )*X-
	    1.99999999997023E-01f )*X+3.33333333333318E-01f;
      WW1 = (X+X)*F1 + __expf(-X);
    } 
  else if (X < 3.0f) 
    {
      Y = X-2.0f;
      F1 = ((((((((((-1.61702782425558E-10f*Y+1.96215250865776E-09f )*Y-
		    2.14234468198419E-08f )*Y+2.17216556336318E-07f )*Y-
		  1.98850171329371E-06f )*Y+1.62429321438911E-05f )*Y-
		1.16740298039895E-04f )*Y+7.24888732052332E-04f )*Y-
	      3.79490003707156E-03f )*Y+1.61723488664661E-02f )*Y-
	    5.29428148329736E-02f )*Y+1.15702180856167E-01f;
      WW1 = (X+X)*F1+__expf(-X);
    } 
  else if (X < 5.0f)
    {
      Y = X-4.0f;
      F1 = ((((((((((-2.62453564772299E-11f*Y+3.24031041623823E-10f )*Y-
		    3.614965656163E-09f)*Y+3.760256799971E-08f)*Y-
		  3.553558319675E-07f)*Y+3.022556449731E-06f)*Y-
		2.290098979647E-05f)*Y+1.526537461148E-04f)*Y-
	      8.81947375894379E-04f)*Y+4.33207949514611E-03f )*Y-
	    1.75257821619926E-02f )*Y+5.28406320615584E-02f;
      WW1 = (X+X)*F1+__expf(-X);
    } 
  else if (X < 10.0f) 
    {
      E = __expf(-X);
      inv = 1 / X;
      WW1 = (((((( 4.6897511375022E-01f*inv-6.9955602298985E-01f)*inv +
		 5.3689283271887E-01f)*inv-3.2883030418398E-01f)*inv +
	       2.4645596956002E-01f)*inv-4.9984072848436E-01f)*inv -
	     3.1501078774085E-06f)*E + 1 / sqrtf(rPIE4 * X);
    } 
  else if (X < 15.0f) 
    {
      E = __expf(-X);
      inv = 1 / X;
      WW1 = (((-1.8784686463512E-01f*inv+2.2991849164985E-01f)*inv -
	      4.9893752514047E-01f)*inv-2.1916512131607E-05f)*E \
	+ 1 / sqrtf(rPIE4 * X);
    } 
  else if (X < 33.0f) 
    {
      E = __expf(-X);
      inv = 1 / X;
      WW1 = (( 1.9623264149430E-01f*inv-4.9695241464490E-01f)*inv -
	     6.0156581186481E-05f)*E + 1 / sqrtf(rPIE4 * X);
    } 
  else 
    {
      WW1 = 1 / sqrtf(rPIE4 * X);
    }
  return WW1;
}

__device__ 
void GetBases(int Work, int thid, int Shift, int& localthid, 
	      int& a1, int& a2, int& a3, int& a4)
{
  a1         = (Work & (unsigned int)61440)   >> 12;
  a2         = (Work & (unsigned int)3840 )   >> 8;
  a3         = (Work & (unsigned int)240  )   >> 4;
  a4         = (Work & (unsigned int)15   );
  localthid = thid - (Shift << LOG_BLOCK_SIZE);
}

__device__ 
void GetNs(int localthid, int a1, int a2, int a3, int a4, 
	   int& n1, int& n2, int& n3, int& n4)
{
  int prod = __mul24(a2, __mul24(a3, a4));
  int res = localthid;
  n1 = __fdividef(res, prod);
  res -= __mul24(n1, prod);

  prod = __mul24(a3, a4);
  n2 = __fdividef(res, prod);
  res -= __mul24(n2, prod);

  prod = a4;
  n3 = __fdividef(res, prod);
  res -= __mul24(n3, prod);

  n4 = res;
}

__device__ 
void GetAtoms(int Work, int& atom1, int& atom2, int& atom3, int& atom4)
{
  atom1 = (Work & (unsigned int)4278190080) >> 24;
  atom2 = (Work & (unsigned int)16711680)   >> 16;
  atom3 = (Work & (unsigned int)65280)      >> 8;
  atom4 = (Work & (unsigned int)255);
}

__device__ 
void GetOffsets(int Work, int& off1, int& off2, int& off3, int& off4)
{
  off1 = (Work & (unsigned int)4278190080) >> 24;
  off2 = (Work & (unsigned int)16711680)   >> 16;
  off3 = (Work & (unsigned int)65280)      >> 8;
  off4 = (Work & (unsigned int)255);
}
