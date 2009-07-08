/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <parboil.h>
#include "shell.h"

typedef struct {
  float x, y, z;
} float3;

typedef struct {
  float x, y;
} float2;

typedef struct {
  unsigned int x, y;
} uint2;

#define BLOCK_SIZE 64

float3* Coors;
float2* Sprms;

int totNumBlocks;
int MaxBlocks;

Atom *ComputeAtom, *BasisAtom;
Shell* ComputeShell;

float *ReductionSum;
int totReductionElements;

uint2 *FinalReduce;

inline float H_product1D(float, float, float, float);
inline float H_dist2(float3, float3);
inline float H_ComputeI(float, float, float, float, 
			 float, float, float, float);

void CalcOnHost(int);
Atom* ReadBasisAtoms(int&, struct pb_Parameters *);
int TotalNumOfShells(char*, int, int&);
void PopulateShells(char*, int);
void PopulateHostData(int, int, int);
int NumOfIntegrals(int);
void FreeAllData();

float root1f(float X);

int main(int argc, char* argv[])
{
  struct pb_TimerSet timers;
  struct pb_Parameters *params;

  pb_InitializeTimerSet( &timers );
  params = pb_ReadParameters( &argc, argv );

  totNumBlocks = 0;
  MaxBlocks = 0;

  int numBasisAtoms;
  pb_SwitchToTimer( &timers, pb_TimerID_IO );
  BasisAtom = ReadBasisAtoms(numBasisAtoms, params);
  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
  
  int totNumAtoms;
  int totNumShells = TotalNumOfShells(params->inpFiles[0], 
                                      numBasisAtoms, totNumAtoms);
  totReductionElements = totNumShells * (totNumShells + 1) * 
    (totNumShells + 2) * (totNumShells + 3) / 24;
  ComputeAtom = (Atom*)malloc(totNumAtoms * sizeof(Atom));
  ComputeShell = (Shell*)malloc(totNumShells * sizeof(Shell));

  pb_SwitchToTimer( &timers, pb_TimerID_IO );
  PopulateShells(params->inpFiles[0], numBasisAtoms);
  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
  // all shells are ready now

  // prepare host data
  int totBasisShells = 0;
  for(int i = 0; i < numBasisAtoms; i ++) 
    for(int j = 0; j < BasisAtom[i].numShells; j ++)
      totBasisShells += BasisAtom[i].AtomShell[j].numPrimitives;

  Coors = (float3*)malloc(totNumAtoms * sizeof(float3));
  Sprms = (float2*)malloc(totBasisShells * sizeof(float2));
  PopulateHostData(totNumAtoms, totNumShells, numBasisAtoms);

  // distribute the work now
  FinalReduce = (uint2*)malloc(totReductionElements * sizeof(uint2));
  int numIntegrals = NumOfIntegrals(totNumShells);
  pb_SwitchToTimer( &timers, pb_TimerID_IO );
  printf("Total # of integrals to compute: %d\n", numIntegrals);
  printf("Total # of blocks allocated: %d\n", totNumBlocks);
  printf("Final array size: %d\n", totReductionElements);
  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );

  int output_mem   = totNumBlocks * sizeof(float);
  int reduction_mem = totReductionElements * sizeof(float);
  int final_mem = totReductionElements * sizeof(uint2);

  ReductionSum = (float*)malloc(reduction_mem);

  // doing the same on the host
  CalcOnHost(totNumShells);

  FreeAllData();
  if(params->outFile)
    {
      pb_SwitchToTimer( &timers, pb_TimerID_IO );
      FILE *file = fopen(params->outFile, "w");
      for(int i = 0; i < 20000; i ++)
        {
          fprintf(file, "%d\t%e\n", i, ReductionSum[i]);
        }
      fclose(file);
    }

  pb_SwitchToTimer( &timers, pb_TimerID_NONE );
  pb_PrintTimerSet( &timers );
  pb_FreeParameters( params );

  return 0;
}

void FreeAllData()
{
  free ((void*)FinalReduce);
  
  free ((void*)ComputeAtom);
  free ((void*)BasisAtom);
  free ((void*)ComputeShell);
}

Atom* ReadBasisAtoms(int& numBasisAtoms, struct pb_Parameters *params)
{
  FILE* basis = fopen(params->inpFiles[1], "r");
  if(!basis)
    {
      printf("Unable to open file %s\n", params->inpFiles[1]);
      exit(0);
    }
  int numAtoms = 0, numShells = 0;
  fscanf(basis, "%*s %*s %d", &numAtoms);
  fscanf(basis, "%*s %*s %d", &numShells);
  printf("\n>>>>>>> STARTED BASIS SET OUTPUT <<<<<<<\n");
  printf("\n# OF KNOWN ATOMS:  %d\n", numAtoms);
  printf("# OF KNOWN SHELLS: %d\n\n", numShells);
  numBasisAtoms = numAtoms;
  
  Atom* BasisAtom = (Atom*)malloc(numAtoms * sizeof(Atom));
  
  for(int atom = 0; atom < numAtoms; atom ++)
    {
      char type[4];
      char buff[4];
      fscanf(basis, "%*s %s", type);
      fscanf(basis, "%*s %d", &numShells);
      BasisAtom[atom].numShells = numShells;
      strcpy(BasisAtom[atom].Type, type);
      printf("\nAtom %s (%d shells)\n", BasisAtom[atom].Type, 
	     BasisAtom[atom].numShells);
      
      for(int shell = 0; shell < numShells; shell ++)
	{
	  int numPrimitives = 0;
	  fscanf(basis, "%*s %*d %*s %d", &numPrimitives);
	  BasisAtom[atom].AtomShell[shell].numPrimitives = numPrimitives;
	  sprintf(buff, "%d", shell + 1);
	  strcpy(BasisAtom[atom].AtomShell[shell].Type    , type);
	  strcpy(BasisAtom[atom].AtomShell[shell].Type + 1, buff);
	  printf("\tShell %s: %d primitives\n", 
		 BasisAtom[atom].AtomShell[shell].Type,
		 BasisAtom[atom].AtomShell[shell].numPrimitives);
	  for(int prim = 0; prim < numPrimitives; prim ++)
	    {
	      fscanf(basis, "%*s %*s %*s %f %f", 
		     &BasisAtom[atom].AtomShell[shell].Alpha[prim], 
		     &BasisAtom[atom].AtomShell[shell].Coeff[prim]);
	      printf("\t\tprimitive %d: %10.2f    %5.2f\n", prim + 1, 
		     BasisAtom[atom].AtomShell[shell].Alpha[prim], 
		     BasisAtom[atom].AtomShell[shell].Coeff[prim]);
	    }
	  printf("\n");
	}
    }
  printf(">>>>>>>> DONE BASIS SET OUTPUT <<<<<<<<\n\n\n");
  fclose(basis);
  return BasisAtom;
}

int TotalNumOfShells(char* fname, int numBasisAtoms, int& totNumAtoms)
{
  FILE* inp = fopen(fname, "r");
  if(!inp)
    {
      printf("Unable to open %s\n", fname);
      exit(0);
    }
  int numShells = 0;
  fscanf(inp, "%*s %d", &totNumAtoms);
  
  for(int atom = 0; atom < totNumAtoms; atom ++)
    {
      char type[8];
      fscanf(inp, "%s %*s %*s %*s", type);
      
      int notfound = 1;
      for(int batom = 0; batom < numBasisAtoms; batom ++)
	{
	  if(!strcmp(BasisAtom[batom].Type, type))
	    {
	      numShells += BasisAtom[batom].numShells;
	      notfound = 0;
	      break;
	    }
	}
      if(notfound)
	{
	  printf("Unable to find atom \'%s\' in the basis set\n", type);
	  exit(0);
	}
    }

  fclose(inp);
  return numShells;
}

void PopulateShells(char* fname, int numBasisAtoms)
{
  FILE* inp = fopen(fname, "r");
  if(!inp)
    {
      printf("Unable to open %s\n", fname);
      exit(0);
    }
  int numAtoms = 0, currentShell = 0;
  fscanf(inp, "%*s %d", &numAtoms);
  
  for(int atom = 0; atom < numAtoms; atom ++)
    {
      fscanf(inp, "%s %f %f %f", &ComputeAtom[atom].Type, 
	     &ComputeAtom[atom].X,
	     &ComputeAtom[atom].Y, &ComputeAtom[atom].Z);
      
      int currentInList = 0;
      for(int batom = 0; batom < numBasisAtoms; batom ++)
	{
	  if(!strcmp(BasisAtom[batom].Type, ComputeAtom[atom].Type))
	    {
	      for(int shell = 0; shell < BasisAtom[batom].numShells; 
		  shell ++)
		{
		  ComputeShell[currentShell] = 
		    BasisAtom[batom].AtomShell[shell];
		  ComputeShell[currentShell].myAtom = atom;
		  
		  //	this part populates inList
		  for(int prim = 0; prim < 
			BasisAtom[batom].AtomShell[shell].numPrimitives; 
		      prim ++)
		    ComputeShell[currentShell].inList[prim] = 
		      currentInList ++;

		  currentShell ++;
		}
	      break;
	    }
	  //	this part populates inList
	  else
	    {
	      for(int shell = 0; shell < BasisAtom[batom].numShells; 
		  shell ++)
		currentInList += 
		  BasisAtom[batom].AtomShell[shell].numPrimitives;
	    }
	}
    }
  fclose(inp);
}

void PopulateHostData(int totNumAtoms, int totNumShells, int numBasisAtoms)
{
  for(int atom = 0; atom < totNumAtoms; atom ++)
    {
      Coors[atom].x = ComputeAtom[atom].X;
      Coors[atom].y = ComputeAtom[atom].Y;
      Coors[atom].z = ComputeAtom[atom].Z;
    }

  int currentPos = 0;
  for(int batom = 0; batom < numBasisAtoms; batom ++)
    {
      for(int shell = 0; shell < BasisAtom[batom].numShells; shell ++)
	{
	  for(int prim = 0; prim < 
		BasisAtom[batom].AtomShell[shell].numPrimitives; 
	      prim ++)
	    {
	      Sprms[currentPos].x = 
		BasisAtom[batom].AtomShell[shell].Alpha[prim];
	      Sprms[currentPos].y = 
		BasisAtom[batom].AtomShell[shell].Coeff[prim];
	      currentPos ++;
	    }
	}
    }
}

int NumOfIntegrals(int totNumShells)
{
  int numIntegrals = 0;
  int firstRedElement = 0;
  int redElement = 0;
  for(int shell1 = 0; shell1 < totNumShells; shell1 ++)
    for(int shell2 = shell1; shell2 < totNumShells; shell2 ++)
      for(int shell3 = shell2; shell3 < totNumShells; shell3 ++)
	for(int shell4 = shell3; shell4 < totNumShells; shell4 ++)
	  {
	    int integrals = ComputeShell[shell1].numPrimitives * 
	      ComputeShell[shell2].numPrimitives * 
	      ComputeShell[shell3].numPrimitives * 
	      ComputeShell[shell4].numPrimitives;
	    numIntegrals += integrals;
	    
	    int blocks = (int)ceil(1.0 * integrals / BLOCK_SIZE);
	    totNumBlocks += blocks;
	    if(blocks > MaxBlocks)
	      MaxBlocks = blocks;
	    FinalReduce[redElement].x = firstRedElement;
	    FinalReduce[redElement].y = blocks;
	    firstRedElement += blocks;
	    redElement ++;
	  }
  return numIntegrals;
}

void CalcOnHost(int totNumShells)
{
  int numElements = 0;
  for(int shell1 = 0; shell1 < totNumShells; shell1 ++)
    {
      for(int shell2 = shell1; shell2 < totNumShells; shell2 ++)
	{
	  for(int shell3 = shell2; shell3 < totNumShells; shell3 ++)
	    {
	      for(int shell4 = shell3; shell4 < totNumShells; shell4 ++)
		{
		  ReductionSum[numElements] = 0.0;
		  for(int prim1 = 0; prim1 < 
			ComputeShell[shell1].numPrimitives; prim1 ++)
		    {
		      for(int prim2 = 0; prim2 < 
			    ComputeShell[shell2].numPrimitives; prim2 ++)
			{
			  for(int prim3 = 0; prim3 < 
				ComputeShell[shell3].numPrimitives; prim3 ++)
			    {
			      for(int prim4 = 0; prim4 < 
				  ComputeShell[shell4].numPrimitives; prim4 ++)
				{
				  int atom1 = ComputeShell[shell1].myAtom;
				  int atom2 = ComputeShell[shell2].myAtom;
				  int atom3 = ComputeShell[shell3].myAtom;
				  int atom4 = ComputeShell[shell4].myAtom;
				  
				  int alpha1 = 
				    ComputeShell[shell1].inList[prim1];
				  int alpha2 = 
				    ComputeShell[shell2].inList[prim2];
				  int alpha3 = 
				    ComputeShell[shell3].inList[prim3];
				  int alpha4 = 
				    ComputeShell[shell4].inList[prim4];
				  
				  float Alpha1 = Sprms[alpha1].x;
				  float Alpha2 = Sprms[alpha2].x;
				  float Alpha3 = Sprms[alpha3].x;
				  float Alpha4 = Sprms[alpha4].x;
				  float Coeff1 = Sprms[alpha1].y;
				  float Coeff2 = Sprms[alpha2].y;
				  float Coeff3 = Sprms[alpha3].y;
				  float Coeff4 = Sprms[alpha4].y;
				  
				  float3 Atom1, Atom2, Atom3, Atom4, 
				    Atomp, Atomq;

				  Atom1.x = (float)Coors[atom1].x;
				  Atom1.y = (float)Coors[atom1].y;
				  Atom1.z = (float)Coors[atom1].z;
				  Atom2.x = (float)Coors[atom2].x;
				  Atom2.y = (float)Coors[atom2].y;
				  Atom2.z = (float)Coors[atom2].z;
				  Atom3.x = (float)Coors[atom3].x;
				  Atom3.y = (float)Coors[atom3].y;
				  Atom3.z = (float)Coors[atom3].z;
				  Atom4.x = (float)Coors[atom4].x;
				  Atom4.y = (float)Coors[atom4].y;
				  Atom4.z = (float)Coors[atom4].z;
				  
				  float A = Alpha1 + Alpha2;
				  float B = Alpha3 + Alpha4;
				  
				  float rho = A * B / (A + B);

				  Atomp.x = H_product1D(Alpha1, Atom1.x, 
							Alpha2, Atom2.x);
				  Atomp.y = H_product1D(Alpha1, Atom1.y, 
							Alpha2, Atom2.y);
				  Atomp.z = H_product1D(Alpha1, Atom1.z, 
							Alpha2, Atom2.z);
				  Atomq.x = H_product1D(Alpha3, Atom3.x, 
							Alpha4, Atom4.x);
				  Atomq.y = H_product1D(Alpha3, Atom3.y, 
							Alpha4, Atom4.y);
				  Atomq.z = H_product1D(Alpha3, Atom3.z, 
							Alpha4, Atom4.z);

				  float rpq2 = H_dist2(Atomp, Atomq);
				  float X = rpq2 * rho;
				  
				  float weight;
				  weight = root1f(X);
				  
				  float I1 = H_ComputeI(Atom1.x, Atom2.x, 
							 Atom3.x, Atom4.x,
							 Alpha1, Alpha2, 
							 Alpha3, Alpha4);
				  
				  float I2 = H_ComputeI(Atom1.y, Atom2.y, 
							 Atom3.y, Atom4.y,
							 Alpha1, Alpha2, 
							 Alpha3, Alpha4);
				  
				  float I3 = H_ComputeI(Atom1.z, Atom2.z, 
							 Atom3.z, Atom4.z,
							 Alpha1, Alpha2, 
							 Alpha3, Alpha4);
				  
				  ReductionSum[numElements] += 
				    sqrt(1.273239545f * rho) * I1*I2*I3*
				    weight * Coeff1 * Coeff2 * Coeff3 * 
				    Coeff4;
				}
			    }
			}
		    }
		  numElements ++;
		}
	    }
	}
    }
}

inline float H_product1D(float alpha_a, float coor_a, 
			  float alpha_b, float coor_b)
{
  float inv = 1 / (alpha_a + alpha_b);
  return (alpha_a * coor_a + alpha_b * coor_b) * inv;
}

inline float H_dist2(float3 Atom1, float3 Atom2)
{
  float dx = Atom1.x - Atom2.x;
  float dy = Atom1.y - Atom2.y;
  float dz = Atom1.z - Atom2.z;
  return dx * dx + dy * dy + dz * dz;
}

inline float H_ComputeI(float coor1, float coor2, 
			 float coor3, float coor4,
			 float alpha1, float alpha2, 
			 float alpha3, float alpha4)
{
  float A = alpha1 + alpha2;
  float B = alpha3 + alpha4;
  float dx1 = coor2 - coor1;
  float dx2 = coor4 - coor3;
  float inv_sqrt = 1.0 / sqrt(A * B);
  inv_sqrt *= 3.141592654;
  
  float preexp = -1.0 * alpha1 * alpha2 * dx1 * dx1 / A - 
    alpha3 * alpha4 * dx2 * dx2 / B;
  
  return inv_sqrt * exp(preexp);
}

float root1f(float X)
{
  float PIE4;
  float WW1 = 0.0f;
  float F1,E,Y,inv;
  
  PIE4 = 7.85398163397448E-01f;
  
  if (X < 3.0e-7f)
    {
      WW1 = 1.0f - 0.333333333f * X;
    } 
    else if (X < 1.0f) 
    {
      F1 = ((((((((-8.36313918003957E-08f*X+1.21222603512827E-06 )*X-
                   1.15662609053481E-05f )*X+9.25197374512647E-05f )*X-
		   6.40994113129432E-04f )*X+3.78787044215009E-03f )*X-
		   1.85185172458485E-02f )*X+7.14285713298222E-02f )*X-
		   1.99999999997023E-01f )*X+3.33333333333318E-01f;
      WW1 = (X+X)*F1 + expf(-X);
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
      WW1 = (X+X)*F1+expf(-X);
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
      WW1 = (X+X)*F1+expf(-X);
    } 
    else if (X < 10.0f) 
    {
      E = expf(-X);
      inv = 1 / X;
      WW1 = (((((( 4.6897511375022E-01f*inv-6.9955602298985E-01f)*inv +
			5.3689283271887E-01f)*inv-3.2883030418398E-01f)*inv +
			2.4645596956002E-01f)*inv-4.9984072848436E-01f)*inv -
			3.1501078774085E-06f)*E + sqrtf(PIE4*inv);
    } 
    else if (X < 15.0f) 
    {
      E = expf(-X);
      inv = 1 / X;
      WW1 = (((-1.8784686463512E-01f*inv+2.2991849164985E-01f)*inv -
			4.9893752514047E-01f)*inv-2.1916512131607E-05f)*E \
			+ sqrtf(PIE4*inv);
      F1 = (WW1-E)*inv*0.5f;
    } 
    else if (X < 33.0f) 
    {
      E = expf(-X);
      inv = 1 / X;
      WW1 = (( 1.9623264149430E-01f*inv-4.9695241464490E-01f)*inv -
			6.0156581186481E-05f)*E + sqrtf(PIE4*inv);
    } 
    else 
    {
      inv = 1 / X;
      WW1 = sqrtf(PIE4*inv);
    }
    
    return WW1;
}
