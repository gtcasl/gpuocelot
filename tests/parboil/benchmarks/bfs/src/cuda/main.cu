/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/*
  Implementing Breadth first search on CUDA using algorithm given in DAC'10
  paper "An Effective GPU Implementation of Breadth-First Search"

  Copyright (c) 2010 University of Illinois at Urbana-Champaign. 
  All rights reserved.

  Permission to use, copy, modify and distribute this software and its documentation for 
  educational purpose is hereby granted without fee, provided that the above copyright 
  notice and this permission notice appear in all copies of this software and that you do 
  not sell the software.

  THE SOFTWARE IS PROVIDED "AS IS" AND WITHOUT WARRANTY OF ANY KIND,EXPRESS, IMPLIED OR 
  OTHERWISE.

  Author: Lijiuan Luo (lluo3@uiuc.edu)
  Revised for Parboil 2 Benchmark Suite by: Geng Daniel Liu (gengliu2@illinois.edu)
*/

#ifdef _GLIBCXX_USE_INT128
#undef _GLIBCXX_USE_INT128
#endif 

#ifdef _GLIBCXX_ATOMIC_BUILTINS
#undef _GLIBCXX_ATOMIC_BUILTINS
#endif


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <parboil.h>
#include <deque>
#include <iostream>

#define MAX_THREADS_PER_BLOCK 512
#define NUM_SM 15 //the number of Streaming Multiprocessors; 15 for Fermi architecture 30 for G280 at the moment of this document
#define NUM_BIN 8 //the number of duplicated frontiers used in BFS_kernel_multi_blk_inGPU
#define EXP 3 // EXP = log(NUM_BIN), assuming NUM_BIN is still power of 2 in the future architecture
	//using EXP and shifting can speed up division operation 
#define MOD_OP 7 // This variable is also related with NUM_BIN; may change in the future architecture;
	//using MOD_OP and "bitwise and" can speed up mod operation
#define INF 2147483647//2^31-1
int no_of_nodes; //the number of nodes in the graph
int edge_list_size;//the number of edges in the graph
FILE *fp;

typedef int2 Node;
typedef int2 Edge;

#include "kernel.cu"
//Somehow "cudaMemset" does not work. So I use cudaMemcpy of constant variables for initialization
const int h_top = 1;
const int zero = 0;

void runGPU(int argc, char** argv);
////////////////////////////////////////////////////////////////////////////////
// Main Program
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char** argv) 
{
    //printf(" device 1 \n");
	no_of_nodes=0;
	edge_list_size=0;
    cudaSetDevice(0);
	runGPU(argc,argv);

}
bool  BFS_GPU( Node * d_graph_nodes,Edge * d_graph_edges,
	int * d_color, int * d_cost, int * d_q1, int * d_q2, int * tail, int source, int & global_kt){
	int num_of_blocks; 
	int num_of_threads_per_block;
    

	(cudaMemcpy(tail,&h_top,sizeof(int),cudaMemcpyHostToDevice));
	(cudaMemcpy(&d_cost[source],&zero,sizeof(int),cudaMemcpyHostToDevice));

	( cudaMemcpy( &d_q1[0], &source, sizeof(int), cudaMemcpyHostToDevice) );
	int num_t;//number of threads
	int k=0;//BFS level index

	//whether or not to adjust "k", see comment on "BFS_kernel_multi_blk_inGPU" for more details 
	int * switch_kd;
	( cudaMalloc( (void**) &switch_kd, sizeof(int)));
	int * num_td;//number of threads
	( cudaMalloc( (void**) &num_td, sizeof(int)));

	//whether to stay within a kernel, used in "BFS_kernel_multi_blk_inGPU"
	bool *stay;
	( cudaMalloc( (void**) &stay, sizeof(bool)));
	int switch_k;

	//max number of frontier nodes assigned to a block
	int * max_nodes_per_block_d;
	( cudaMalloc( (void**) &max_nodes_per_block_d, sizeof(int)));
	#ifdef DIS_COMP
	int max_nodes_per_block;
	#endif
    int *global_kt_d;
	( cudaMalloc( (void**) &global_kt_d, sizeof(int)));
	(cudaMemcpy(global_kt_d,&global_kt, sizeof(int),cudaMemcpyHostToDevice));
	
	do
	{
		( cudaMemcpy( &num_t, tail, sizeof(int), cudaMemcpyDeviceToHost) );
		(cudaMemcpy(tail,&zero,sizeof(int),cudaMemcpyHostToDevice));

		if(num_t == 0){//frontier is empty
			(cudaFree(stay));
			(cudaFree(switch_kd));
			(cudaFree(num_td));
			(cudaMemcpy(&global_kt,global_kt_d, sizeof(int),cudaMemcpyDeviceToHost));
			return false;
		}

		num_of_blocks = 1;
		num_of_threads_per_block = num_t;
		if(num_of_threads_per_block <NUM_BIN)
			num_of_threads_per_block = NUM_BIN;
		if(num_t>MAX_THREADS_PER_BLOCK)
		{
			num_of_blocks = (int)ceil(num_t/(double)MAX_THREADS_PER_BLOCK); 
			num_of_threads_per_block = MAX_THREADS_PER_BLOCK;
		}
		if(num_of_blocks == 1)//will call "BFS_in_GPU_kernel" 
			num_of_threads_per_block = MAX_THREADS_PER_BLOCK; 
		if(num_of_blocks >1 && num_of_blocks <= NUM_SM)// will call "BFS_kernel_multi_blk_inGPU"
			num_of_blocks = NUM_SM;

		//assume "num_of_blocks" can not be very large
	        dim3  grid( num_of_blocks, 1, 1);
		dim3  threads( num_of_threads_per_block, 1, 1);

		if(k%2 == 0){
			if(num_of_blocks == 1){
				BFS_in_GPU_kernel<<< grid, threads >>>(d_q1,d_q2, d_graph_nodes, 
				 d_graph_edges, d_color, d_cost,num_t , tail,GRAY0,k );
			}
			else if(num_of_blocks <= NUM_SM){
				#ifdef DIS_COMP
				max_nodes_per_block = ceil(float(num_t)/NUM_SM);
				(cudaMemcpy(max_nodes_per_block_d,
					&max_nodes_per_block,sizeof(int), cudaMemcpyHostToDevice));
				#endif
				(cudaMemcpy(num_td,&num_t,sizeof(int),
					cudaMemcpyHostToDevice));
				BFS_kernel_multi_blk_inGPU
				<<< grid, threads >>>(d_q1,d_q2, d_graph_nodes, 
				 d_graph_edges, d_color, d_cost, num_td, tail,GRAY0,k,
				switch_kd, max_nodes_per_block_d, global_kt_d);
				(cudaMemcpy(&switch_k,switch_kd, sizeof(int),
				cudaMemcpyDeviceToHost));
				if(!switch_k){
					k--;
				}
			}
			else{
				BFS_kernel<<< grid, threads >>>(d_q1,d_q2, d_graph_nodes, 
				 d_graph_edges, d_color, d_cost, num_t, tail,GRAY0,k);
			}
		}
		else{
			if(num_of_blocks == 1){
				BFS_in_GPU_kernel<<< grid, threads >>>(d_q2,d_q1, d_graph_nodes, 
				 d_graph_edges, d_color, d_cost, num_t, tail,GRAY1,k);
			}
			else if(num_of_blocks <= NUM_SM){
				#ifdef DIS_COMP
				max_nodes_per_block = ceil(float(num_t)/NUM_SM);
				(cudaMemcpy(max_nodes_per_block_d,
					&max_nodes_per_block,sizeof(int), cudaMemcpyHostToDevice));
				#endif
				(cudaMemcpy(num_td,&num_t,sizeof(int),
					cudaMemcpyHostToDevice));
				BFS_kernel_multi_blk_inGPU
				<<< grid, threads >>>(d_q2,d_q1, d_graph_nodes, 
				 d_graph_edges, d_color, d_cost, num_td, tail,GRAY1,k,
				 switch_kd, max_nodes_per_block_d, global_kt_d);
				(cudaMemcpy(&switch_k,switch_kd, sizeof(int),
				cudaMemcpyDeviceToHost));
				if(!switch_k){
					k--;
				}
			}
			else{
				BFS_kernel<<< grid, threads >>>(d_q2,d_q1, d_graph_nodes, 
				 d_graph_edges, d_color, d_cost, num_t, tail, GRAY1,k);
			}
		}
			
		// check if kernel execution generated any error
		//CUT_CHECK_ERROR("Kernel execution failed");
		
		k++;
	}
	while(1);
}
///////////////////////////////
//FUNCTION:only run GPU version 
////////////////////////////////////////////
void runGPU( int argc, char** argv) 
{

    struct pb_Parameters *params;
    struct pb_TimerSet timers;

    pb_InitializeTimerSet(&timers);
    params = pb_ReadParameters(&argc, argv);
    if ((params->inpFiles[0] == NULL) || (params->inpFiles[1] != NULL))
    {
        fprintf(stderr, "Expecting one input filename\n");
        exit(-1);
    }

    pb_SwitchToTimer(&timers, pb_TimerID_IO);
	//printf("Reading File\n");
	//Read in Graph from a file
	fp = fopen(params->inpFiles[0],"r");
	if(!fp)
	{
		printf("Error Reading graph file\n");
		return;
	}
	int source;

	fscanf(fp,"%d",&no_of_nodes);
	// allocate host memory
	Node* h_graph_nodes = (Node*) malloc(sizeof(Node)*no_of_nodes);
	int *color = (int*) malloc(sizeof(int)*no_of_nodes);
	int start, edgeno;   
	// initalize the memory
	for( unsigned int i = 0; i < no_of_nodes; i++) 
	{
		fscanf(fp,"%d %d",&start,&edgeno);
		h_graph_nodes[i].x = start;
		h_graph_nodes[i].y = edgeno;
		color[i]=WHITE;
	}
	//read the source node from the file
	fscanf(fp,"%d",&source);
	fscanf(fp,"%d",&edge_list_size);
	int id,cost;
	Edge* h_graph_edges = (Edge*) malloc(sizeof(Edge)*edge_list_size);
	for(int i=0; i < edge_list_size ; i++)
	{
		fscanf(fp,"%d",&id);
		fscanf(fp,"%d",&cost);
		h_graph_edges[i].x = id;
		h_graph_edges[i].y = cost;
	}
	if(fp)
		fclose(fp);    

//	printf("Read File\n");

	// allocate mem for the result on host side
	int* h_cost = (int*) malloc( sizeof(int)*no_of_nodes);
	for(int i = 0; i < no_of_nodes; i++){
		h_cost[i] = INF;
	}
	h_cost[source] = 0;

    pb_SwitchToTimer(&timers, pb_TimerID_COPY);

	int * temp = NULL;
	( cudaMalloc( (void**) &temp, sizeof(int)*no_of_nodes) );
	( cudaFree( temp) );
//	unsigned int copy_timer = 0;
//	cutilCheckError(cutCreateTimer(&copy_timer));
//	cutilCheckError(cutStartTimer(copy_timer));

	//Copy the Node list to device memory
	Node* d_graph_nodes;
	( cudaMalloc( (void**) &d_graph_nodes, sizeof(Node)*no_of_nodes) );
	( cudaMemcpy( d_graph_nodes, h_graph_nodes, sizeof(Node)*no_of_nodes, cudaMemcpyHostToDevice) );
	//Copy the Edge List to device Memory
	Edge* d_graph_edges;
	( cudaMalloc( (void**) &d_graph_edges, sizeof(Edge)*edge_list_size) );
	( cudaMemcpy( d_graph_edges, h_graph_edges, sizeof(Edge)*edge_list_size, cudaMemcpyHostToDevice) );


	int* d_color;
	( cudaMalloc( (void**) &d_color, sizeof(int)*no_of_nodes) );
	int* d_cost;
	( cudaMalloc( (void**) &d_cost, sizeof(int)*no_of_nodes));
	int * d_q1;
	int * d_q2;
	( cudaMalloc( (void**) &d_q1, sizeof(int)*no_of_nodes));
	( cudaMalloc( (void**) &d_q2, sizeof(int)*no_of_nodes));
	int * tail;
	( cudaMalloc( (void**) &tail, sizeof(int)));
	int *front_cost_d;
	( cudaMalloc( (void**) &front_cost_d, sizeof(int)));
	( cudaMemcpy( d_color, color, sizeof(int)*no_of_nodes, cudaMemcpyHostToDevice) );
	( cudaMemcpy( d_cost, h_cost, sizeof(int)*no_of_nodes, cudaMemcpyHostToDevice) );
	
//	printf("Copied Everything to GPU memory\n");


	//bind the texture memory with global memory
	(cudaBindTexture(0,g_graph_node_ref,d_graph_nodes, sizeof(Node)*no_of_nodes));
	(cudaBindTexture(0,g_graph_edge_ref,d_graph_edges,sizeof(Edge)*edge_list_size));

	int cur_count = 0;
	
    printf("Starting GPU kernel\n");
	(cudaThreadSynchronize());
    pb_SwitchToTimer(&timers, pb_TimerID_GPU);
	BFS_GPU( d_graph_nodes,d_graph_edges,
		d_color, d_cost, d_q1, d_q2,  tail, source, cur_count);
	(cudaThreadSynchronize());
    pb_SwitchToTimer(&timers, pb_TimerID_COPY);
    printf("GPU kernel done\n");


	// copy result from device to host
	( cudaMemcpy( h_cost, d_cost, sizeof(int)*no_of_nodes, cudaMemcpyDeviceToHost) );
	( cudaMemcpy( color, d_color, sizeof(int)*no_of_nodes, cudaMemcpyDeviceToHost) );
	( cudaUnbindTexture(g_graph_node_ref) );
	( cudaUnbindTexture(g_graph_edge_ref) );

	(cudaFree(d_graph_nodes));
	(cudaFree(d_graph_edges));
	(cudaFree(d_color));
	(cudaFree(d_cost));
	(cudaFree(tail));
	(cudaFree(front_cost_d));
	//Store the result into a file
    pb_SwitchToTimer(&timers, pb_TimerID_IO);
	FILE *fp = fopen(params->outFile,"w");
    fprintf(fp, "%d\n", no_of_nodes);
	for(int i=0;i<no_of_nodes;i++)
		fprintf(fp,"%d %d\n",i,h_cost[i]);
	fclose(fp);
	//printf("Result stored in %s\n", params->outFile);

	// cleanup memory
	free( h_graph_nodes);
	free( h_graph_edges);
	free( color);
	free( h_cost);
    pb_SwitchToTimer(&timers, pb_TimerID_NONE);
    pb_PrintTimerSet(&timers);
    pb_FreeParameters(params);
}
