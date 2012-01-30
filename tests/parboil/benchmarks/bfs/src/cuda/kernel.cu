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
*/
#ifndef _KERNEL_H_
#define _KERNEL_H_
/*
Define colors for BFS
1) the definition of White, gray and black comes from the text book "Introduction to Algorithms"
2) For path search problems, people may choose to use different colors to record the found paths.
Therefore we reserve numbers (0-16677216) for this purpose. Only nodes with colors bigger than
UP_LIMIT are free to visit 
3) We define two gray shades to differentiate between the new frontier nodes and the old frontier nodes that
 have not been marked BLACK 
*/

#define UP_LIMIT 16677216//2^24
#define WHITE 16677217
#define GRAY 16677218
#define GRAY0 16677219
#define GRAY1 16677220
#define BLACK 16677221

//Distribute computation
//tries to distribute the computation among all the SMs. However, it does not seem to help improve the
//performance.
//#define DIS_COMP

/***
The maximum size of each  w-queue (row-major order)
FIXME
This should be chosen more carefully to avoid  bank conflict.
A better implementation will be to arrange w-queues in column-major order, but the program will be less readable.
****/
#define LOCAL_MEM 400 

texture<Node> g_graph_node_ref;
texture<Edge> g_graph_edge_ref;

volatile __device__ int count = 0;
volatile __device__ int no_of_nodes_vol = 0;
volatile __device__ int stay_vol = 0;
//GPU synchronization.
//implementing the algorithm proposed in 
//S. Xiao and W. Feng, "Inter-block GPU communication via fast barrier
//synchronization," Technical Report TR-09-19, Dept. of Computer Science, VT
//NOTE the algorithm originally given in the report is inaccurate
__device__ void start_global_barrier(int fold){
	//This synchronization is missing in the report
	__syncthreads();

	if(threadIdx.x == 0){
        atomicAdd((int*)&count, 1);
		while( count < NUM_SM*fold){
		    ;
		}
    }
    __syncthreads();
    
}
//-------------------------------------------------
//This is the version for one-block situation. The propagation idea is basically the same as
//BFS_kernel.
//The major differences are:
// 1) This kernel can propagate though multiple BFS levels (while loop) using __synchThreads() between levels 
// 2) the intermediate queues are stored in shared memory (next_wf) 
//\param q1: the current frontier queue when the kernel is launched
//\param q2: the new frontier queue when the  kernel returns
//--------------------------------------------------
__global__ void
BFS_in_GPU_kernel( int * q1, int * q2, Node* g_graph_nodes, Edge* g_graph_edges, int* g_color, int * g_cost, int no_of_nodes, int * tail, int gray_shade, int k ) 
{
	__shared__ int local_q_tail[NUM_BIN];
	__shared__ int local_q[NUM_BIN][LOCAL_MEM]; 
	__shared__ int prefix_q[NUM_BIN];
	__shared__ int thread_n_q[NUM_BIN];
	
	//next/new wave front
	__shared__ int next_wf[MAX_THREADS_PER_BLOCK];
	__shared__ int  tot_sum;
	if(threadIdx.x == 0)	
		tot_sum = 0;//total number of new frontier nodes
	while(1){//propage through multiple BFS levels until the wavfront overgrows one-block limit
		if(threadIdx.x < NUM_BIN){
			local_q_tail[threadIdx.x] = 0;
			thread_n_q[threadIdx.x] = blockDim.x>>EXP;
			if((blockDim.x&MOD_OP) > threadIdx.x){
				thread_n_q[threadIdx.x]++;
			}
		}
		__syncthreads();
		int tid = blockIdx.x*MAX_THREADS_PER_BLOCK + threadIdx.x;
		if( tid<no_of_nodes)
		{
			int pid;
			if(tot_sum == 0)//this is the first BFS level of current kernel call
				pid = q1[tid];  
			else
				pid = next_wf[tid];//read the current frontier info from last level's propagation
			g_color[pid] = BLACK;
			int cur_cost = g_cost[pid];
			int q_i = threadIdx.x&MOD_OP; 
			Node cur_node = tex1Dfetch(g_graph_node_ref,pid);
			for(int i=cur_node.x; i<cur_node.y + cur_node.x; i++) {
				Edge cur_edge = tex1Dfetch(g_graph_edge_ref,i);
				int id = cur_edge.x;
				int cost = cur_edge.y;
				cost += cur_cost;
				int orig_cost = atomicMin(&g_cost[id],cost);
				if(orig_cost > cost){
					int old_color = atomicExch(&g_color[id],gray_shade);
					if(old_color != gray_shade) {
						//push to the queue
						int index = atomicAdd(&local_q_tail[q_i],1);
						local_q[q_i][index] = id;
					}
				}
			}
		}
		__syncthreads();
		if(threadIdx.x == 0){
			prefix_q[0] = 0;
			for(int i = 1; i < NUM_BIN; i++){
				prefix_q[i] = prefix_q[i-1]+local_q_tail[i-1];
			}
			tot_sum = prefix_q[NUM_BIN-1] + local_q_tail[NUM_BIN-1];
			*tail = tot_sum;
		}
		__syncthreads();

		int q_i = threadIdx.x&MOD_OP;
		int local_shift = threadIdx.x>>EXP;
		if(tot_sum == 0)//the new frontier becomes empty; BFS is over
			return;
		if(tot_sum <= MAX_THREADS_PER_BLOCK){//the new frontier is still within one-block limit;
			//stay in current kernel
			while (local_shift < local_q_tail[q_i]){
				next_wf[prefix_q[q_i]+local_shift] = local_q[q_i][local_shift];
				local_shift += thread_n_q[q_i];
			}
			__syncthreads();
			no_of_nodes = tot_sum;
			if(threadIdx.x == 0){
				if(gray_shade == GRAY0)
					gray_shade = GRAY1;
				else
					gray_shade = GRAY0;
			}
		}
		else{//the new frontier outgrows one-block limit; terminate current kernel
			while(local_shift < local_q_tail[q_i]){
				q2[prefix_q[q_i]+local_shift] = local_q[q_i][local_shift];
				local_shift += thread_n_q[q_i];
			}
			return;
		}
	}//while
	
}	
//----------------------------------------------------------------
//This BFS kernel propagates through multiple levels using global synchronization 
//The basic propagation idea is the same as "BFS_kernel"
//The major differences are:
// 1) propagate through multiple levels by using GPU global sync ("start_global_barrier")
// 2) use q1 and q2 alternately for the intermediate queues
//\param q1: the current frontier when the kernel is called
//\param q2: possibly the new frontier when the kernel returns depending on how many levels of propagation
//           has been done in current kernel; the new frontier could also be stored in q1
//\param switch_k: whether or not to adjust the "k" value on the host side
//                Normally on the host side, when "k" is even, q1 is the current frontier; when "k" is
//                odd, q2 is the current frontier; since this kernel can propagate through multiple levels,
//                the k value may need to be adjusted when this kernel returns.
//\param max_nodes_per_block: the maximum frontier node assigned to a block. It is only useful when "DIS_COMP"
//                is enabled
//\param global_kt: the total number of global synchronizations, 
//                   or the number of times to call "start_global_barrier" 
//--------------------------------------------------------------
__global__ void
BFS_kernel_multi_blk_inGPU( int *  q1, int *  q2, Node* g_graph_nodes, Edge* g_graph_edges, int* g_color, int * g_cost, int *no_of_nodes, int * tail, int gray_shade, int k,   
	 int * switch_k, int * max_nodes_per_block, int * global_kt ) 
{
	__shared__ int local_q_tail[NUM_BIN];
	__shared__ int local_q[NUM_BIN][LOCAL_MEM]; 
	__shared__ int prefix_q[NUM_BIN];
	__shared__ int thread_n_q[NUM_BIN];
	__shared__ int shift;
	__shared__ int no_of_nodes_sm;
	__shared__ int odd_time;// the odd level of propagation within current kernel
	if(threadIdx.x == 0){
		odd_time = 1;//true;
        if(blockIdx.x == 0)
            no_of_nodes_vol = *no_of_nodes;
	}
	int kt = *global_kt;// the total count of GPU global synchronization 
	while (1){//propagate through multiple levels
		if(threadIdx.x < NUM_BIN){
			local_q_tail[threadIdx.x] = 0;
			thread_n_q[threadIdx.x] = blockDim.x>>EXP;
			if((blockDim.x&MOD_OP) > threadIdx.x){
				thread_n_q[threadIdx.x]++;
			}
		}
		if(threadIdx.x == 0)
			no_of_nodes_sm =  no_of_nodes_vol; 
		__syncthreads();

		#ifdef DIS_COMP
		int tid = blockIdx.x*(*max_nodes_per_block) + threadIdx.x;
		#else
		int tid = blockIdx.x*MAX_THREADS_PER_BLOCK + threadIdx.x;
		#endif
		if( tid<no_of_nodes_sm)
		{
			int pid;
			if(odd_time == 1)
				pid = atomicOr((int*)&q1[tid], 0);  
			else
				pid = atomicOr((int*)&q2[tid], 0);
			g_color[pid] = BLACK;
			int cur_cost = atomicOr((int*)&g_cost[pid], 0);
			int q_i = threadIdx.x&MOD_OP; 
			Node cur_node = tex1Dfetch(g_graph_node_ref,pid);
			for(int i=cur_node.x; i<cur_node.y + cur_node.x; i++) {
				Edge cur_edge = tex1Dfetch(g_graph_edge_ref,i);
				int id = cur_edge.x;
				int cost = cur_edge.y;
				cost += cur_cost;
				int orig_cost = atomicMin(&g_cost[id],cost);
				if(orig_cost > cost){
					if(g_color[id] > UP_LIMIT){
						int old_color = atomicExch(&g_color[id],gray_shade);
						if(old_color != gray_shade)
							{
							//push to the queue
							int index = atomicAdd(&local_q_tail[q_i],1);
							local_q[q_i][index] = id;
						}
					}
				}
			}
		}
		__syncthreads();
		if(threadIdx.x == 0){
			prefix_q[0] = 0;
			for(int i = 1; i < NUM_BIN; i++){
				prefix_q[i] = prefix_q[i-1] + local_q_tail[i-1];
			}
			int tot_sum = prefix_q[NUM_BIN-1] + local_q_tail[NUM_BIN-1];
			shift = atomicAdd(tail,tot_sum);
		}
		__syncthreads();

		int q_i = threadIdx.x&MOD_OP;
		int local_shift = threadIdx.x>>EXP;
		while (local_shift < local_q_tail[q_i]){
			if(odd_time)
				q2[shift+prefix_q[q_i]+local_shift] = local_q[q_i][local_shift];
			else
				q1[shift+prefix_q[q_i]+local_shift] = local_q[q_i][local_shift];
			local_shift += thread_n_q[q_i];
		}
		if(threadIdx.x == 0){
			odd_time = (odd_time+1)%2;
			if(gray_shade == GRAY0)
				gray_shade = GRAY1;
			else
				gray_shade = GRAY0;
		}

		//synchronize among all the blks
		start_global_barrier(kt+1);
		if(blockIdx.x == 0 && threadIdx.x == 0){
            stay_vol = 0;
			if(*tail< NUM_SM*MAX_THREADS_PER_BLOCK && *tail > MAX_THREADS_PER_BLOCK){
                stay_vol = 1;
				no_of_nodes_vol = *tail;
			
				//this is only useful when DIS_COMP is enabled
				*max_nodes_per_block = ceil(float(*no_of_nodes)/NUM_SM);
				*tail = 0;
			}
		}
		start_global_barrier(kt+2);
		kt+= 2;
        if(stay_vol == 0)
        {
            if(blockIdx.x == 0 && threadIdx.x == 0)
            {
                *global_kt = kt;
                *switch_k = (odd_time+1)%2;
                *no_of_nodes = no_of_nodes_vol;
            }
            return;
        }
	}
}

/*****************************************************************************
This is the  most general version of BFS kernel, i.e. no assumption about #block in the grid  
\param q1: the array to hold the current frontier
\param q2: the array to hold the new frontier
\param g_graph_nodes: the nodes in the input graph
\param g_graph_edges: the edges i nthe input graph
\param g_color: the colors of nodes
\param g_cost: the costs of nodes
\param no_of_nodes: the number of nodes in the current frontier
\param tail: pointer to the location of the tail of the new frontier. *tail is the size of the new frontier 
\param gray_shade: the shade of the gray in current BFS propagation. See GRAY0, GRAY1 macro definitions for more details
\param k: the level of current propagation in the BFS tree. k= 0 for the first propagation.
***********************************************************************/
__global__ void
BFS_kernel( int * q1, int * q2, Node* g_graph_nodes, Edge* g_graph_edges, int* g_color, int * g_cost, int no_of_nodes, int * tail, int gray_shade, int k ) 
{
	__shared__ int local_q_tail[NUM_BIN];//the tails of each local warp-level queue
	__shared__ int local_q[NUM_BIN][LOCAL_MEM];//the local warp-level queues 
	__shared__ int prefix_q[NUM_BIN];//the number of elementss in the w-queues ahead of
					//current w-queue, a.k.a prefix sum
	__shared__ int thread_n_q[NUM_BIN];//#thread which writes into the current w-queue
	__shared__ int shift;

	if(threadIdx.x < NUM_BIN){
		local_q_tail[threadIdx.x] = 0;//initialize the tail of w-queue
		thread_n_q[threadIdx.x] = blockDim.x>>EXP;//#thread/NUM_BIN
		if((blockDim.x&MOD_OP) > threadIdx.x){//#thread%NUM_BIN > threadIdx.x
			thread_n_q[threadIdx.x]++;
		}
	}
	__syncthreads();

	//first, propagate and add the new frontier elements into w-queues
	int tid = blockIdx.x*MAX_THREADS_PER_BLOCK + threadIdx.x;
	if( tid<no_of_nodes)
	{
		int pid = q1[tid]; //the current frontier node, or the parent node of the new frontier nodes 
		g_color[pid] = BLACK;
		int cur_cost = g_cost[pid];
		int q_i = threadIdx.x&MOD_OP; //the id of the queue which new frontier nodes will be pushed
				//into
		Node cur_node = tex1Dfetch(g_graph_node_ref,pid);
		for(int i=cur_node.x; i<cur_node.y + cur_node.x; i++)//visit each neighbor of the
				//current frontier node.
			{
			Edge cur_edge = tex1Dfetch(g_graph_edge_ref,i);
			int id = cur_edge.x;
			int cost = cur_edge.y;
			cost += cur_cost;
			int orig_cost = atomicMin(&g_cost[id],cost);
			if(orig_cost > cost){//the node should be visited
				if(g_color[id] > UP_LIMIT){
					int old_color = atomicExch(&g_color[id],gray_shade);
					//this guarantees that only one thread will push this node
					//into a queue
					if(old_color != gray_shade) {

						//atomic operation guarantees the correctness
						//even if multiple warps are executing simultaneously
						int index = atomicAdd(&local_q_tail[q_i],1);
						local_q[q_i][index] = id;
					}
				}
			}
		}
	}
	__syncthreads();

	if(threadIdx.x == 0){
		//now calculate the prefix sum
		prefix_q[0] = 0;
		for(int i = 1; i < NUM_BIN; i++){
			//the prefix sum of one queue is equal to the prefix sum of its predecessor queue
			//plus the number of elements in the predecessor queue
			prefix_q[i] = prefix_q[i-1]+local_q_tail[i-1];
		}
		//the total number of elements in the block-level queue is the prefix sum of the last w-queue
		//plus the number of elements in the last w-queue
		int tot_sum = prefix_q[NUM_BIN-1] + local_q_tail[NUM_BIN-1];

		//the offset or "shift" of the block-level queue within the grid-level queue
		//is determined by atomic operation
		shift = atomicAdd(tail,tot_sum);
	}
	__syncthreads();

	//now copy the elements from w-queues into grid-level queues.
	//Note that we have bypassed the copy to/from block-level queues for efficiency reason

	int q_i = threadIdx.x&MOD_OP;//w-queue index
	int local_shift = threadIdx.x>>EXP;//shift within a w-queue

	//loop unrolling was originally used for better performance, but removed for better readability
	while(local_shift < local_q_tail[q_i]){
		q2[shift+prefix_q[q_i]+local_shift] = local_q[q_i][local_shift];
		local_shift+= thread_n_q[q_i];//multiple threads are copying elements at the same time,
			//so we shift by multiple elements for next iteration  
	}
	//FIXME, the above implementation has bad coalescing. Better implementation should make
	//consecutive threads write into consecutive locations
}
#endif 
