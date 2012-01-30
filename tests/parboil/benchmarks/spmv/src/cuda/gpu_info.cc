/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#include <endian.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <inttypes.h>

void compute_active_thread(unsigned int *thread,
					unsigned int *grid,
					int task,
					int pad,
					int major,
					int minor,
					int warp_size,
					int sm)
{
	int max_thread;
	int max_warp;
	int max_block=8;
	if(major==1)
	{
		if(minor>=2)
		{
			max_thread=1024;
			max_warp=32;
		}
		else
		{
			max_thread=768;
			max_warp=24;
		}
	}
	else if(major==2)
	{
		max_thread=1536;
		max_warp=48;
	}
	else
	{
		//newer GPU  //keep using 2.0
		max_thread=1536;
		max_warp=48;
	}
	
	int _grid;
	int _thread;
	int threads_per_sm=0;
	if(task*pad>sm*max_thread)
	{
		_grid=sm*max_block;
		_thread=max_thread/max_block;
	}
	else
	{
		_thread=pad;
		_grid=task;
	}
	thread[0]=_thread;
	grid[0]=_grid;
	
}
