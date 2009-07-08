/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <parboil.h>

/*
// Place and Transition are implicitly included in the code 
// as the grid is a fixed one
typedef struct {
	float mark;
} Place;
typedef struct {
	int from1, from2;
	int to1, to2;
} Transition;

// this starts from row 0 and col 0
P(r,c)    -> T(r,c)   -> P(r,c+1)  ->
  |            |            |
 \/           \/           \/
T(r+1,c-1)-> P(r+1,c) -> T(r+1,c)  ->
  |            |            |
 \/           \/           \/
P(r+2,c)  -> T(r+2,c) -> P(r+2,c+1)->
  |            |            |
 \/           \/           \/
T(r+3,c-1)-> P(r+3,c) -> T(r+3,c)->
  |            |            |
 \/           \/           \/

*/

int N, s, t, N2, NSQUARE2;
char *places;
float *vars;
int *maxs;
float mean_vars;
float var_vars;
float mean_maxs;
float var_maxs;

#define place_mark(r, c)  places[(r)*N+(c)]

/* Period parameters */  
#define MERS_N 624
#define MERS_M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
#define MERS_MAX   0xffffffffUL

static unsigned long mt[MERS_N]; /* the array for the state vector  */
static int mti=MERS_N+1; /* mti==MERS_N+1 means mt[MERS_N] is not initialized */

/* 
   The following two functions implement the Mersenne Twister random 
   number generator.  The copyright notice/disclaimer, etc are related
   to this code.

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.                          

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote 
        products derived from this software without specific prior written 
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
/* initializes mt[MERS_N] with a seed */
void init_genrand(unsigned long s)
{
    mt[0]= s;
    for (mti=1; mti<MERS_N; mti++) {
        mt[mti] = 
	    (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti); 
        /* for >32 bit machines */
        mt[mti] &= 0xffffffffUL;
    }
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void)
{
    unsigned long y;
    static unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= MERS_N) { /* generate N words at one time */
        int kk;

        for (kk=0;kk<MERS_N-MERS_M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+MERS_M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<MERS_N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(MERS_M-MERS_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[MERS_N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[MERS_N-1] = mt[MERS_M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }
  
    y = mt[mti++];

    /* Tempering */
    /*
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);*/

    return y;
}

void run_trajectory(int max_steps) 
{
  int i;
  int rand_val;
  int t_r, t_c, input_place_up_r, input_place_up_c, 
    input_place_left_r, input_place_left_c;
  int output_place_down_r, output_place_down_c, 
    output_place_right_r, output_place_right_c;
  
  i = 0;

  while (i<max_steps) 
    {
      rand_val = (int)(((float)genrand_int32())/MERS_MAX*NSQUARE2);
      t_r = rand_val/N;
      t_c = rand_val%N;
      input_place_up_r = (t_r-1+N2)%N2;
      input_place_up_c = (t_r&1)? (t_c+1)%N: t_c;
      input_place_left_r = t_r;
      input_place_left_c = t_c;
      // the two input places should be enabled for one transition
      if ( (place_mark(input_place_up_r, input_place_up_c)>=1) &&
	   (place_mark(input_place_left_r, input_place_left_c)>=1))
	{
	  output_place_down_r = (t_r+1)%N2;
	  output_place_down_c = input_place_up_c;
	  output_place_right_r = t_r;
	  output_place_right_c = (t_c+1)%N;
	  place_mark(input_place_up_r, input_place_up_c) = 
	    place_mark(input_place_up_r, input_place_up_c)-1;
	  place_mark(input_place_left_r, input_place_left_c) = 
	    place_mark(input_place_left_r, input_place_left_c)-1;
	  place_mark(output_place_down_r, output_place_down_c) = 
	    place_mark(output_place_down_r, output_place_down_c)+1;
	  place_mark(output_place_right_r, output_place_right_c) = 
	    place_mark(output_place_right_r, output_place_right_c)+1;
	  i = i+1;
	}
    }
}

void compute_reward_stat(int trajectory_num) 
{
  float sum = 0;
  int i;
  int max = 0;
  // unrolling -- we know N is even and so we can unroll upto 8
  for (i=0; i<NSQUARE2; i+=8) 
    {
      sum += ((float)places[i])*places[i];
      if (max<places[i])
	max = places[i];
      sum += ((float)places[i+1])*places[i+1];
      if (max<places[i+1])
	max = places[i+1];
      sum += ((float)places[i+2])*places[i+2];
      if (max<places[i+2])
	max = places[i+2];
      sum += ((float)places[i+3])*places[i+3];
      if (max<places[i+3])
	max = places[i+3];
      sum += ((float)places[i+4])*places[i+4];
      if (max<places[i+4])
	max = places[i+4];
      sum += ((float)places[i+5])*places[i+5];
      if (max<places[i+5])
	max = places[i+5];
      sum += ((float)places[i+6])*places[i+6];
      if (max<places[i+6])
	max = places[i+6];
      sum += ((float)places[i+7])*places[i+7];
      if (max<places[i+7])
	max = places[i+7];
    }
  vars[trajectory_num] = sum/NSQUARE2-1; // D(X)=E(X^2)-E(X)^2, E(X)=1
  maxs[trajectory_num] = max;
}

void compute_statistics() 
{
  float sum = 0;
  float sum_vars = 0;
  float sum_max = 0;
  float sum_max_vars = 0;
  int i;

  for (i=0; i<t; i++) 
    {
      sum += vars[i];
      sum_vars += vars[i]*vars[i];
      sum_max += maxs[i];
      sum_max_vars += maxs[i]*maxs[i];
    }
  mean_vars = sum/t;
  var_vars = sum_vars/t - mean_vars*mean_vars;
  mean_maxs = sum_max/t;
  var_maxs= sum_max_vars/t - mean_maxs*mean_maxs;
}

int main(int argc, char* argv[]) 
{
  struct pb_TimerSet timers;
  struct pb_Parameters *params;
  int i;
  FILE *out;
  
  pb_InitializeTimerSet( &timers );
  params = pb_ReadParameters( &argc, argv );

  if (argc<4) 
    {
      printf("Usage: petri n s t\n"
	     "n: the place-transition grid is 2nX2n\n"
	     "s: the maximum steps in a trajectory\n"
	     "t: number of trajectories\n");
      return -1;
    }

  pb_SwitchToTimer( &timers, pb_TimerID_IO );
  N = atoi(argv[1]);
  if (N<1)
    return -1;
  s = atoi(argv[2]);
  if (s<1)
    return -1;
  t = atoi(argv[3]);
  if (t<1)
    return -1;

  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
  
  init_genrand(391581);
  N2 = N+N;
  NSQUARE2 = N*N2;
  places = (char*)malloc(NSQUARE2*sizeof(char));
  if (places==NULL) 
    {
      printf("Error in allocating memory\n");
      return -1;
    }
  vars = (float*)malloc(t*sizeof(float));
  if (vars==NULL) 
    {
      printf("Error in allocating memory\n");
      return -1;
    }
  maxs = (int*)malloc(t*sizeof(int));
  if (maxs==NULL) 
    {
      printf("Error in allocating memory\n");
      return -1;
    }

  for (i=0; i<t; i=i+1) 
    {
      //initialize_grid(N);
      memset(places, 1, NSQUARE2*sizeof(char));
      run_trajectory(s);
      compute_reward_stat(i);
    }
  compute_statistics();
  
  free(places);
  free(vars);
  free(maxs);
  
  pb_SwitchToTimer( &timers, pb_TimerID_IO );

  if(params->outFile)
    {
      out = fopen( params->outFile, "w" );
      fprintf(out, "%f %f %f %f\n", mean_vars, var_vars, mean_maxs, var_maxs);
      printf("petri N=%d s=%d t=%d\n"
  	     "mean_vars: %f   var_vars: %f\n"
	     "mean_maxs: %f   var_maxs: %f\n", N, s, t, mean_vars, var_vars,
	     mean_maxs, var_maxs);
      fclose( out );
    }
  else
    {
      printf("petri N=%d s=%d t=%d\n"
  	     "mean_vars: %f   var_vars: %f\n"
	     "mean_maxs: %f   var_maxs: %f\n", N, s, t, mean_vars, var_vars,
	     mean_maxs, var_maxs);
    }

  pb_SwitchToTimer( &timers, pb_TimerID_NONE );
  pb_PrintTimerSet( &timers );
  pb_FreeParameters( params );
  return 0;
}

