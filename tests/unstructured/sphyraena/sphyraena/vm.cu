/* vim: set filetype=c : */
/* vim: set ts=6 : */
/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */



#include <cuda.h>

extern "C" {
#include "sphyraena.h"
}

// these are operator templates. I did this this way so that I could use the same code but
// switch the operator
#define SPHYRAENA_VM_COMPARE(x)										\
	type = max(reg[op->p3].type, reg[op->p1].type);							\
	switch(type) {												\
		case SPHYRAENA_INT :										\
			jump = (castToInt(&reg[op->p3]) x castToInt(&reg[op->p1]));			\
			break;											\
		case SPHYRAENA_FLOAT :										\
			jump = (castToFloat(&reg[op->p3]) x castToFloat(&reg[op->p1]));		\
			break;											\
		case SPHYRAENA_INT64 :										\
			jump = (castToInt64(&reg[op->p3]) x castToInt64(&reg[op->p1]));		\
			break;											\
		case SPHYRAENA_DOUBLE :										\
			jump = (castToDouble(&reg[op->p3]) x castToDouble(&reg[op->p1]));		\
			break;											\
	}														\
	if(jump)													\
		pc = op->p2;											\
	else														\
		pc++;

#define SPHYRAENA_VM_MATH(x)												\
	type = max(reg[op->p2].type, reg[op->p1].type);								\
	reg[op->p3].type = type;											\
	switch(type) {													\
		case SPHYRAENA_INT :											\
			reg[op->p3].mem.i = (castToInt(&reg[op->p2]) x castToInt(&reg[op->p1]));	\
			break;												\
		case SPHYRAENA_FLOAT :											\
			reg[op->p3].mem.f = (castToFloat(&reg[op->p2]) x castToFloat(&reg[op->p1]));	\
			break;												\
		case SPHYRAENA_INT64 :											\
			reg[op->p3].mem.li = (castToInt64(&reg[op->p2]) x castToInt64(&reg[op->p1]));	\
			break;												\
		case SPHYRAENA_DOUBLE :											\
			reg[op->p3].mem.d = (castToDouble(&reg[op->p2]) x castToDouble(&reg[op->p1]));\
			break;												\
	}															\

// these could probably be done in functions but you would have to pass a lot of arguments
// this makes it a bit simpler
#define SPHYRAENA_VM_LOGICAL_LOAD(x)					\
	switch(reg[op->x].type) {						\
		case SPHYRAENA_INT :						\
			val_##x = reg[op->x].mem.i;				\
			break;							\
		case SPHYRAENA_FLOAT :						\
			val_##x = (reg[op->x].mem.f == 0) ? 0 : 1;	\
			break;							\
		case SPHYRAENA_INT64 :						\
			val_##x = (reg[op->x].mem.li == 0) ? 0 : 1;	\
			break;							\
		case SPHYRAENA_DOUBLE :						\
			val_##x = (reg[op->x].mem.d == 0) ? 0 : 1;	\
			break;							\
	}

#define SPHYRAENA_VM_LOGICAL(x)			\
	SPHYRAENA_VM_LOGICAL_LOAD(p1)			\
	SPHYRAENA_VM_LOGICAL_LOAD(p2)			\
	reg[op->p3].type = SPHYRAENA_INT;		\
	reg[op->p3].mem.i = (val_p1 x val_p2);


__device__ void copyDataToReg(sphyraena_mem *reg, char *data, char* d, int column, int row);
__device__ int castToInt(sphyraena_mem *m);
__device__ float castToFloat(sphyraena_mem *m);
__device__ i64 castToInt64(sphyraena_mem *m);
__device__ double castToDouble(sphyraena_mem *m);

// the sql statement
__constant__ sphyraena_stmt cstmt;
// the data block meta information
__constant__ sphyraena_data_gpu cdata;

__shared__ int result_start;
__shared__ int block_start;
__shared__ int reductionblock[SPHYRAENA_THREADSPERBLOCK];
//__shared__ sphyraena_mem registerspace[SPHYRAENA_THREADSPERBLOCK * SPHYRAENA_REGISTERS];
//__device__ sphyraena_mem gregisterspace[SPHYRAENA_THREADSPERBLOCK * SPHYRAENA_REGISTERS];
//__shared__ sphyraena_mem reg_shared[SPHYRAENA_GLOBAL_REGISTERS];

__device__ sphyraena_mem reg_global[SPHYRAENA_GLOBAL_REGISTERS];
__device__ unsigned long long int count_global[SPHYRAENA_GLOBAL_REGISTERS];

__device__ unsigned int block_order;

texture<float, 1, cudaReadModeElementType> texRef;

__global__ void VmKernel(char *data, sphyraena_results *results, int start_row, int num_blocks, int rows)
{
	// used for instances where a single thread handles multiple rows, for large data sets
	int curr_row = 0;
	block_start = 0;

	// sets the global registers used for aggregates
	if(threadIdx.x < SPHYRAENA_GLOBAL_REGISTERS) {
		//reg_shared[threadIdx.x].mem.li = 0;
		if(blockIdx.x == 0) {
			reg_global[threadIdx.x].mem.li = 0;
			reg_global[threadIdx.x].type = SPHYRAENA_NULL;
		}
	}

new_row:

	int row = (blockIdx.x + num_blocks * curr_row) * blockDim.x + threadIdx.x + start_row;

	sphyraena_mem reg[SPHYRAENA_REGISTERS];
	//sphyraena_mem *reg = (sphyraena_mem*) &registerspace[threadIdx.x * SPHYRAENA_REGISTERS];
	//sphyraena_mem *reg = (sphyraena_mem*) &gregisterspace[threadIdx.x * SPHYRAENA_REGISTERS];

	// program counter for opcode program
	int pc = 0;
	// stride of results block
	int stride = 0;
	// hardcoded registers for logical operations
	int val_p1, val_p2;
	// pointer to current operation
	sphyraena_op *op;

#ifdef COLUMNROW
	char *d = data;
#else
	char *d = data + row * cdata.stride;
#endif

	// pointer to results block
	char *r = (char*) &results->r;
	// used to store the current variable type
	int type;
	int jump = 0;
	int aggfinal_num = 0;
	int i, j;

	if(row >= cdata.rows)
		return;

// there are two modes of operation: divergent and synchronized
// the divergent block allows threads to diverge based on opcodes
// divergent is normally used, then we jump to synchronized on OP_Next
divergent:
	while(pc < SPHYRAENA_MAX_OPS) {
		op = &cstmt.op[pc];

		// this is a massive switch statement of opcodes. It is in alphabetical order other than
		// OP_Column, which is called frequently enough to make see a performance distance in moving
		// it to the front. Depending on the opcodes and size of the opcode programs the total switching
		// overhead for a query could be as high as 30%. On a CPU you could avoid this overhead with a 
		// jump table accessed with the opcode, but this is not supported on current (Tesla C1060)
		// hardware, so we are stuck with the overhead, but this is a major optimization for future
		// hardware.
		// The opcodes are documented on the SQLite website
		switch(op->opcode)
		{
			case OP_Column :
				copyDataToReg(&reg[op->p3], data, d, op->p2, row);
				//fprintf(stderr, "Column reg[%i] = %i  %i\n", op->p3, ((int*)(d + data->offsets[op->p2]))[0]);
				pc++;
				break;

			case OP_Add :
				SPHYRAENA_VM_MATH(+)
				pc++;
				break;

			case OP_AddImm :
				reg[op->p1].mem.i = castToInt(&reg[op->p1]) + op->p2;
				pc++;
				break;

			case OP_AggStep :
				switch(op->p4.i) {
					case SPHYRAENA_AGG_COUNT :
						reg[op->p3].mem.i = 1;
						break;

					case SPHYRAENA_AGG_SUM :
					case SPHYRAENA_AGG_MIN :
					case SPHYRAENA_AGG_MAX :
					case SPHYRAENA_AGG_AVG :
						reg[op->p3].mem.li = reg[op->p2].mem.li;
						reg[op->p3].type = reg[op->p2].type;
						break;
				}
				pc++;
				break;

			case OP_And :
				SPHYRAENA_VM_LOGICAL(&&)
				pc++;
				break;

			case OP_BitAnd :
				reg[op->p3].mem.li = reg[op->p1].mem.li & reg[op->p2].mem.li;
				pc++;
				break;

			case OP_BitNot :
				reg[op->p2].mem.li = ~reg[op->p1].mem.li;
				pc++;
				break;

			case OP_BitOr :
				reg[op->p3].mem.li = reg[op->p1].mem.li | reg[op->p2].mem.li;
				pc++;
				break;

			case OP_Copy :
			case OP_SCopy :
				reg[op->p2].type = reg[op->p1].type;
				reg[op->p2].mem.li = reg[op->p1].mem.li;
				pc++;
				break;

			case OP_Divide :
				SPHYRAENA_VM_MATH(/)
				pc++;
				break;

			case OP_Eq :
				SPHYRAENA_VM_COMPARE(==)
				break;

			case OP_Ge :
				SPHYRAENA_VM_COMPARE(>=)
				break;

			case OP_Gt :
				SPHYRAENA_VM_COMPARE(>)
				break;

			case OP_Halt :
				goto finish;

			case OP_If :
				SPHYRAENA_VM_LOGICAL_LOAD(p1)
				if(val_p1)
					pc = op->p2;
				else
					pc++;
				break;

			case OP_IfNeg :
				if(reg[op->p1].mem.i < 0)
					pc = op->p2;
				else
					pc++;
				break;

			case OP_IfNot :
				SPHYRAENA_VM_LOGICAL_LOAD(p1)
				if(!val_p1)
					pc = op->p2;
				else
					pc++;
				break;

			case OP_IfPos :
				if(reg[op->p1].mem.i < 0)
					pc = op->p2;
				else
					pc++;
				break;
			
			case OP_IfZero :
				if(reg[op->p1].mem.i == 0)
					pc = op->p2;
				else
					pc++;
				break;

			case OP_Int64 :
				reg[op->p2].type = SPHYRAENA_INT64;
				reg[op->p2].mem.li = op->p4.li;
				pc++;
				break;

			case OP_Integer :
				reg[op->p2].type = SPHYRAENA_INT;
				reg[op->p2].mem.i = op->p1;
				pc++;
				break;

			case OP_Le :
				SPHYRAENA_VM_COMPARE(<=)
				break;

			case OP_Lt :
				SPHYRAENA_VM_COMPARE(<)
				break;

			case OP_Multiply :
				SPHYRAENA_VM_MATH(*)
				pc++;
				break;

			case OP_Ne :
				SPHYRAENA_VM_COMPARE(!=)
				break;

			case OP_Next :
				goto coordinated;

			case OP_Not :
				SPHYRAENA_VM_LOGICAL_LOAD(p1)
				reg[op->p2].type = SPHYRAENA_INT;
				reg[op->p2].mem.i = !val_p1;
				pc++;
				break;

			case OP_Null :
				reg[op->p2].mem.li = 0;
				reg[op->p2].type = SPHYRAENA_NULL;
				pc++;
				break;

			case OP_Or :
				SPHYRAENA_VM_LOGICAL(||)
				pc++;
				break;

			case OP_Real :
				reg[op->p2].type = SPHYRAENA_DOUBLE;
				reg[op->p2].mem.d = op->p4.d;
				pc++;
				break;

			case OP_Remainder :
				break;

			case OP_ResultRow :
				//fprintf(stderr, "resultrow    %i   %i\n", reg[7].mem.i, reg[8].mem.i);
				
				if(block_start != -1)
					j = atomicAdd(&block_start, 1);

				for(i = op->p1; i < op->p1 + op->p2; i++) {
					results->types[i - op->p1] = reg[i].type;
					results->offsets[i - op->p1] = stride;

					switch(reg[i].type) {
						case SPHYRAENA_INT :
							stride += sizeof(int);
							break;
						case SPHYRAENA_FLOAT :
							stride += sizeof(float);
							break;
						case SPHYRAENA_INT64 :
							stride += sizeof(i64);
							break;
						case SPHYRAENA_DOUBLE :
							stride += sizeof(double);
							break;
					}
				}

				// this is a slight abuse of syncthreads. According to the documentation
				// syncthreads should never be called in a conditional not executed uniformly
				// across a threadblock. It turns out that synchthreads still works.
				// I implemented it this way because I had to use atomic functions for the reduction,
				// since even though every thread in the threadblock executes OP_Next, syncthreads
				// does not wait for divergent threads to catch up, so a normal reduction cannot be
				// performed. In the event that the implementation changes, this code can be moved
				// to OP_Next, and a proper coordinated reduction can be performed.
				__syncthreads();

				if(j == 0 && block_start != 0) {
					result_start = atomicAdd(&results->rows, block_start);
					block_start = 0;
				}

				__syncthreads();

				// round stride up to a power of 2
				stride--;
				stride |= stride >> 1;
				stride |= stride >> 2;
				stride |= stride >> 4;
				stride |= stride >> 8;
				stride |= stride >> 16;
				stride++;
				stride *= 4;

				results->stride = stride;
				results->columns = op->p2;

				r += (result_start + j) * stride;

				for(i = op->p1; i < op->p1 + op->p2; i++) {
					switch(reg[i].type) {
						case SPHYRAENA_INT :
							((int*)r)[0] = reg[i].mem.i;
							r += sizeof(int);
							break;
						case SPHYRAENA_FLOAT :
							((float*)r)[0] = reg[i].mem.f;
							r += sizeof(float);
							break;
						case SPHYRAENA_INT64 :
							//((i64*)r)[0] = reg[i].mem.li;
							((i64*)r)[0] = reg[i].mem.li;
							r += sizeof(i64);
							break;
						case SPHYRAENA_DOUBLE :
						((double*)r)[0] = reg[i].mem.d;
							r += sizeof(double);
							break;
					}
				}

				pc++;
				break;

			case OP_Rowid :
				// TODO change to actual pkey
				copyDataToReg(&reg[op->p2], data, d, 0, row);
				pc++;
				break;

			case OP_ShiftLeft :
				reg[op->p3].type = reg[op->p2].type;
				reg[op->p3].mem.li = reg[op->p2].mem.li << op->p1;
				pc++;
				break;

			case OP_ShiftRight :
				reg[op->p3].type = reg[op->p2].type;
				reg[op->p3].mem.li = reg[op->p2].mem.li >> op->p1;
				pc++;
				break;

			case OP_Subtract :
				SPHYRAENA_VM_MATH(-);
				pc++;
				break;
			
			default :
				pc++;
				break;
		}


	}

// this is the coordinated opcode block, for when it is essential that every thread acts in
// concert, as in the global aggregate reductions, note that several other opcodes are implemented
// in this block. These are used for post-aggregate operations, such as AVG(col1) + AVG(col2).
// Since all operation is done within a single kernel launch it is necessary to use atomics for
// the aggregate reductions, and establish threadblock order for ex post operations. Because
// of the threadblock ordering, performing multiple aggregates in the same query probably wont work,
// since there is no way to synchronize threadblocks. This should be avoided. All these are reasons
// that a multiple kernel launch model would be better, but that would erase SQLite registers,
// so a good deal more work is needed to accomplish that.
coordinated:

	while(pc < SPHYRAENA_MAX_OPS) {
		op = &cstmt.op[pc];

		switch(op->opcode)
		{
			case OP_AggFinal :
				aggfinal_num++;

				switch(op->p4.i) {
					case SPHYRAENA_AGG_COUNT :
						// find the the next lowest power of 2 from the 
						// thread block size, including the current size
						i = SPHYRAENA_THREADSPERBLOCK;
						SPHYRAENA_ROUNDTOPWR2(i)
						j = i;
						i = i >> 1;
						i = 128;

						reductionblock[threadIdx.x] = reg[op->p1].mem.i;

						for( ; i > 0; i >>= 1, j >>= 1) {
							if(i >= 32)
								__syncthreads();
							if(threadIdx.x >= i && threadIdx.x < j)
								reductionblock[i - (threadIdx.x - i) - 1] += reductionblock[threadIdx.x];
						}

						//int tid = threadIdx.x;

						/*if(tid >= i)
							reductionblock[i - (tid - i) - 1] += reductionblock[tid];
						__syncthreads();

						if(i >= 512) {
							if(tid < 256)
								reductionblock[tid] += reductionblock[tid + 256];
							__syncthreads();
						}
						if(i >= 256) {
							if(tid < 128)
								reductionblock[tid] += reductionblock[tid + 128];
							__syncthreads();
						}
						if(i >= 128) {
							if(tid < 64)
								reductionblock[tid] += reductionblock[tid + 64];
							__syncthreads();
						}

						if(tid < 32) {
							if(i >= 64)
								reductionblock[tid] += reductionblock[tid + 32];
							if(i >= 32)
								reductionblock[tid] += reductionblock[tid + 16];
							if(i >= 16)
								reductionblock[tid] += reductionblock[tid +  8];
							if(i >=  8)
								reductionblock[tid] += reductionblock[tid +  4];
							if(i >=  4)
								reductionblock[tid] += reductionblock[tid +  2];
							if(i >=  2)
								reductionblock[tid] += reductionblock[tid +  1];
						}*/

						if(threadIdx.x == 0) {
							unsigned long long int ulli = atomicAdd(&reg_global[op->p1].mem.ulli, reductionblock[0]);
							reg[op->p1].mem.li = ulli + reductionblock[0];
							reg[op->p1].type = SPHYRAENA_INT;
						}
						break;

					case SPHYRAENA_AGG_SUM :
                                    i = SPHYRAENA_THREADSPERBLOCK;
                                    SPHYRAENA_ROUNDTOPWR2(i)
                                    j = i;
                                    i = i >> 1;

                                    reductionblock[threadIdx.x] = reg[op->p1].mem.i;

                                    for( ; i > 0; i >>= 1, j >>= 1) {
							if(i >= 32)
                                          	__syncthreads();
                                          if(threadIdx.x >= i && threadIdx.x < j)
                                                reductionblock[i - (threadIdx.x - i) - 1] += reductionblock[threadIdx.x];
                                    }

						if(threadIdx.x == 0) {
							unsigned long long int ulli = atomicAdd(&reg_global[op->p1].mem.ulli, reductionblock[0]);
							reg[op->p1].mem.li = ulli + reductionblock[0];
							reg[op->p1].type = SPHYRAENA_INT;
                                    }
						break;

					case SPHYRAENA_AGG_MIN :
                                    i = SPHYRAENA_THREADSPERBLOCK;
                                    SPHYRAENA_ROUNDTOPWR2(i)
                                    j = i;
                                    i = i >> 1;

                                    reductionblock[threadIdx.x] = reg[op->p1].mem.i;

                                    for( ; i > 0; i >>= 1, j >>= 1) {
							if(i >= 32)
                                          	__syncthreads();
                                          if(threadIdx.x >= i && threadIdx.x < j)
                                                SPHYRAENA_MIN(reductionblock[i - (threadIdx.x - i) - 1], reductionblock[threadIdx.x])
                                    }

                                    if(threadIdx.x == 0) {
                                          i = atomicMin(&reg_global[op->p1].mem.i, reductionblock[0]);
                                          SPHYRAENA_MIN(i, reductionblock[0]);
                                          reg[op->p1].mem.li = i;
                                          reg[op->p1].type = SPHYRAENA_INT;
                                    }
                                    break;


                              case SPHYRAENA_AGG_MAX :
                                    i = SPHYRAENA_THREADSPERBLOCK;
                                    SPHYRAENA_ROUNDTOPWR2(i)
                                    j = i;
                                    i = i >> 1;

                                    reductionblock[threadIdx.x] = reg[op->p1].mem.i;

                                    for( ; i > 0; i >>= 1, j >>= 1) {
							if(i >= 32)
                                          	__syncthreads();
                                          if(threadIdx.x >= i && threadIdx.x < j)
                                                SPHYRAENA_MAX(reductionblock[i - (threadIdx.x - i) - 1], reductionblock[threadIdx.x])
                                    }

                                    if(threadIdx.x == 0) {
                                          i = atomicMax(&reg_global[op->p1].mem.i, reductionblock[0]);
                                          SPHYRAENA_MAX(i, reductionblock[0]);
                                          reg[op->p1].mem.li = i;
                                          reg[op->p1].type = SPHYRAENA_INT;
                                    }
                                    break;

					case SPHYRAENA_AGG_AVG :
                                    i = SPHYRAENA_THREADSPERBLOCK;
                                    SPHYRAENA_ROUNDTOPWR2(i)
                                    j = i;
                                    i = i >> 1;

                                    reductionblock[threadIdx.x] = (reg[op->p1].type != SPHYRAENA_NULL) ? 1 : 0;

                                    for( ; i > 0; i >>= 1, j >>= 1) {
							if(i >= 32)
                                          	__syncthreads();
                                          if(threadIdx.x >= i && threadIdx.x < j)
								reductionblock[i - (threadIdx.x - i) - 1] += reductionblock[threadIdx.x];
                                    }

						int sum;

                                    if(threadIdx.x == 0) {
                                          sum = atomicAdd(&reg_global[0].mem.i, reductionblock[0]);
							sum += reductionblock[0];
                                    }


                                    i = SPHYRAENA_THREADSPERBLOCK;
                                    SPHYRAENA_ROUNDTOPWR2(i)
                                    j = i;
                                    i = i >> 1;

						// int overflow?
                                    reductionblock[threadIdx.x] = reg[op->p1].mem.i;

                                    for( ; i > 0; i >>= 1, j >>= 1) {
							if(i >= 32)
                                          	__syncthreads();
                                          if(threadIdx.x >= i && threadIdx.x < j)
								reductionblock[i - (threadIdx.x - i) - 1] += reductionblock[threadIdx.x];
                                    }

						double avg;

                                    if(threadIdx.x == 0) {
                                          avg = (double)atomicAdd(&reg_global[op->p1].mem.ulli, reductionblock[0]);
							avg += reductionblock[0];
							avg /= sum;
							reg[op->p1].mem.f = (float)avg;
							reg[op->p1].type = SPHYRAENA_FLOAT;
                                    }
                                    break;
				}

				pc++;
				break;
					
			case OP_Column :
				goto divergent;

			case OP_Copy :
			case OP_SCopy :
				reg[op->p2].type = reg[op->p1].type;
				reg[op->p2].mem.li = reg[op->p1].mem.li;
				pc++;
				break;

			case OP_Halt :
				goto finish;

			case OP_ResultRow :
				if(threadIdx.x == 0)
					//i = atomicInc(&block_order, gridDim.x);
					i = atomicAdd(&block_order, 1);
				else
					i = 0;

				if(i == gridDim.x - 1) {
					block_order = 0;
				
					for(i = op->p1; i < op->p1 + op->p2; i++) {
						results->types[i - op->p1] = reg[i].type;
						results->offsets[i - op->p1] = stride;

						switch(reg[i].type) {
							case SPHYRAENA_INT :
								stride += sizeof(int);
								break;
							case SPHYRAENA_FLOAT :
								stride += sizeof(float);
								break;
							case SPHYRAENA_INT64 :
								stride += sizeof(i64);
								break;
							case SPHYRAENA_DOUBLE :
								stride += sizeof(double);
								break;
						}
					}

					stride--;
					stride |= stride >> 1;
					stride |= stride >> 2;
					stride |= stride >> 4;
					stride |= stride >> 8;
					stride |= stride >> 16;
					stride++;

					results->stride = stride;
					results->columns = op->p2;
					results->rows = 1;

					for(i = op->p1; i < op->p1 + op->p2; i++) {
						switch(reg[i].type) {
							case SPHYRAENA_INT :
								((int*)r)[0] = reg[i].mem.i;
								r += sizeof(int);
								break;
							case SPHYRAENA_FLOAT :
								((float*)r)[0] = reg[i].mem.f;
								r += sizeof(float);
								break;
							case SPHYRAENA_INT64 :
								((i64*)r)[0] = reg[i].mem.li;
								r += sizeof(i64);
								break;
							case SPHYRAENA_DOUBLE :
							((double*)r)[0] = reg[i].mem.d;
								r += sizeof(double);
								break;
						}
					}

				}
				pc++;
				break;

			default :
				pc++;
				break;
		}
	}

finish:

	curr_row++;
	if(curr_row < rows)
		goto new_row;

}

__device__ void copyDataToReg(sphyraena_mem *reg, char *data, char* d, int column, int row)
{
	reg->type = cdata.types[column];

#ifdef COLUMNROW
	/*if(reg->type <= SPHYRAENA_FLOAT) {
		reg->mem.f = tex1Dfetch(texRef, (cdata.offsets[column] + row * sizeof(int)) / sizeof(int));
	}
	else {
		reg->mem.segment.hi = tex1Dfetch(texRef,
			(cdata.offsets[column] + row * sizeof(i64)) / sizeof(int));
		reg->mem.segment.lo = tex1Dfetch(texRef,
			(cdata.offsets[column] + row * sizeof(i64) + sizeof(int)) / sizeof(int));
	}*/

	char* p = d + cdata.offsets[column] + row * sizeof(int);

	switch(cdata.types[column]) {
		case SPHYRAENA_INT :
			reg->mem.i = ((int*)p)[0];
			break;
		case SPHYRAENA_FLOAT :
			reg->mem.f = ((float*)p)[0];
			break;
		case SPHYRAENA_INT64 :
			reg->mem.li = ((i64*)p)[0];
			break;
		case SPHYRAENA_DOUBLE :
			reg->mem.d = ((double*)p)[0];
			break;
	}
#else
	/*reg->mem.f = tex1Dfetch(texRef, (row * cdata.stride + cdata.offsets[column]) / sizeof(int));

	if(reg->type > SPHYRAENA_FLOAT)
		reg->mem.segment.lo = tex1Dfetch(texRef,
			(row * cdata.stride + cdata.offsets[column]) / sizeof(int) + sizeof(int));*/


	//printf("%i\n", reg->mem.i);
	char* p = d + cdata.offsets[column];

	switch(cdata.types[column]) {
		case SPHYRAENA_INT :
			reg->mem.i = ((int*)p)[0];
			break;
		case SPHYRAENA_FLOAT :
			reg->mem.f = ((float*)p)[0];
			break;
		case SPHYRAENA_INT64 :
			reg->mem.li = ((i64*)p)[0];
			//reg->mem.li = 0;
			//reg->mem.segment.lo = ((int*)p)[0];
			//reg->mem.segment.hi = ((int*)p)[1];
			break;
		case SPHYRAENA_DOUBLE :
			reg->mem.d = ((double*)p)[0];
			break;
	}
#endif

}

__device__ int castToInt(sphyraena_mem *m)
{
	switch(m->type) {
		case SPHYRAENA_INT :
			return m->mem.i;
		case SPHYRAENA_FLOAT :
			return (int)m->mem.f;
		case SPHYRAENA_INT64 :
			return (int)m->mem.li;
		case SPHYRAENA_DOUBLE :
			return (int)m->mem.d;
	}
	return 0;
}

__device__ float castToFloat(sphyraena_mem *m)
{
	switch(m->type) {
		case SPHYRAENA_FLOAT :
			return m->mem.f;
		case SPHYRAENA_INT :
			return (float)m->mem.i;
		case SPHYRAENA_INT64 :
			return (float)m->mem.li;
		case SPHYRAENA_DOUBLE :
			return (float)m->mem.d;
	}
	return 0;
}

__device__ i64 castToInt64(sphyraena_mem *m)
{
	switch(m->type) {
		case SPHYRAENA_INT64 :
			return m->mem.li;
		case SPHYRAENA_INT :
			return (i64)m->mem.i;
		case SPHYRAENA_FLOAT :
			return (i64)m->mem.f;
		case SPHYRAENA_DOUBLE :
			return (i64)m->mem.d;
	}
	return 0;
}

__device__ double castToDouble(sphyraena_mem *m)
{
	switch(m->type) {
		case SPHYRAENA_DOUBLE :
			return m->mem.d;
		case SPHYRAENA_INT :
			return (double)m->mem.i;
		case SPHYRAENA_FLOAT :
			return (double)m->mem.f;
		case SPHYRAENA_INT64 :
			return (double)m->mem.li;
	}
	return 0;
}


// Performs the kernel call
// You'll see that I have commented out some texture code, I tested this but
// found negligible performance improvement, probably because the global
// memory access is a very small part of program execution since the SQLite registers
// are stored in local (global) memory. If that wasn't the case, texture memory
// may make a difference.
extern "C"
int sphyraena_vm(sphyraena *s)
{
	cudaError_t r;
	cudaMemcpyToSymbol((char*)&cstmt, s->stmt_cpu,
		sizeof(sphyraena_stmt), 0, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol((char*)&cdata, s->data_cpu,
		sizeof(sphyraena_data_gpu), 0, cudaMemcpyHostToDevice);
	cudaMemset(s->results_gpu, 0, sizeof(int));
	int zero = 0;
	cudaMemcpyToSymbol((char*)&block_order, &zero, sizeof(int),
		0, cudaMemcpyHostToDevice);

	/*const struct textureReference *texRefPtr;
	r = cudaGetTextureReference(&texRefPtr, "texRef");

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_TEXTURE;
	}

	cudaChannelFormatDesc channelDesc =
		cudaCreateChannelDesc<float>();

	r = cudaBindTexture(0, texRefPtr, (char*)s->data_gpu,
		&channelDesc, s->data_size);

	//texRef.filterMode = cudaFilterModeLinear;

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_TEXTURE;
	}*/

	int blocks = (s->data_cpu->rows + s->threads_per_block - 1) / s->threads_per_block;
	int thread_rows = 1;

	if(blocks >= 65536) {
		thread_rows = (int) ceilf((float)blocks / (float)65536);
		blocks = (int) ceilf((float)blocks / (float)thread_rows);
	}

	VmKernel<<<blocks, s->threads_per_block>>>((char*)s->data_gpu, s->results_gpu, 0, blocks, thread_rows);

	if((r = cudaGetLastError()) != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_KERNEL;
	}

	r = cudaThreadSynchronize();

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_KERNEL;
	}

	return SPHYRAENA_SUCCESS;
}


// performs the kernel call with streaming blocks, using s->stream_width to determine
// the number of streaming blocks
extern "C"
int sphyraena_vm_streaming(sphyraena *s)
{
	if(s->data_cpu->rows < 1000)
		return sphyraena_vm(s);

	cudaError_t r;
	cudaMemcpyToSymbol((char*)&cstmt, s->stmt_cpu,
		sizeof(sphyraena_stmt), 0, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol((char*)&cdata, s->data_cpu,
		sizeof(sphyraena_data_gpu), 0, cudaMemcpyHostToDevice);
	cudaMemset(s->results_gpu, 0, sizeof(int));
	int zero = 0;
	cudaMemcpyToSymbol((char*)&block_order, &zero, sizeof(int),
		0, cudaMemcpyHostToDevice);

	int rows_per_stream = (s->data_cpu->rows + s->stream_width - 1) / s->stream_width;

	int blocks = (rows_per_stream + s->threads_per_block - 1) / s->threads_per_block;
	int block_size = s->data_cpu->stride * rows_per_stream;

	int thread_rows = 0;

	if(blocks >= 65536) {
		thread_rows = (int) ceilf((float)blocks / (float)65536);
		blocks = (int) ceilf((float)blocks / (float)thread_rows);
	}

	//printf("reg size   %i        block_size  %i\n", s->data_cpu->rows * s->data_cpu->stride, block_size);

	//printf("rps %i     blocks %i   block_size %i\n", rows_per_stream, blocks, block_size);

	cudaStream_t stream[s->stream_width];
	for(int i = 0; i < s->stream_width; i++)
		cudaStreamCreate(&stream[i]);

	for(int i = 0; i < s->stream_width; i++)
		cudaMemcpyAsync(s->data_gpu + block_size * i, s->data_cpu->d + block_size * i,
			block_size, cudaMemcpyHostToDevice, stream[i]);

	for(int i = 0; i < s->stream_width; i++) {
		VmKernel<<<blocks, s->threads_per_block, 0, stream[i]>>>
			((char*)s->data_gpu, s->results_gpu, i * blocks * s->threads_per_block, blocks, thread_rows);
	}

	for(int i = 0; i < s->stream_width; i++)
		cudaStreamDestroy(stream[i]);

	if((r = cudaGetLastError()) != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_KERNEL;
	}

	r = cudaThreadSynchronize();

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_KERNEL;
	}

	return SPHYRAENA_SUCCESS;
}


