/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


/** 
 * Sphyraena compiler options
 *
 * SPHY_DEBUG
 * Global debugging option, prints info during execution
 *
 * USE_INT64
 * Uses 64 bit integers instead of 32 bit integers for gpu executions
 *
 * USE_DOUBLES
 * Uses doubles instead of floats for gpu executions
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#include "sqlite3.h"
#include "sqliteInt.h"
#include "vdbe.h"
#include "vdbeInt.h"
#include "opcodes.h"

#include "cuda_runtime_api.h"
#include "driver_types.h"

#define SPHYRAENA_SUCCESS		0
#define SPHYRAENA_ERR_MEM		1
#define SPHYRAENA_ERR_STMT		2
#define SPHYRAENA_ERR_CUDAMEMCPY	3
#define SPHYRAENA_ERR_CUDAMALLOC	4
#define SPHYRAENA_ERR_DEVICE		5
#define SPHYRAENA_ERR_CUDAFREE	6
#define SPHYRAENA_ERR_CUDAFREEHOST	7
#define SPHYRAENA_ERR_KERNEL		8
#define SPHYRAENA_ERR_TYPE		9
#define SPHYRAENA_ERR_TEXTURE		10

#define SPHYRAENA_AGG_COUNT		0
#define SPHYRAENA_AGG_MIN		1
#define SPHYRAENA_AGG_MAX		2
#define SPHYRAENA_AGG_SUM		3
#define SPHYRAENA_AGG_AVG		4

#define SPHYRAENA_AGG_STR_COUNT	"count"
#define SPHYRAENA_AGG_STR_MIN		"min"
#define SPHYRAENA_AGG_STR_MAX		"max"
#define SPHYRAENA_AGG_STR_SUM		"sum"
#define SPHYRAENA_AGG_STR_AVG		"avg"

#define SPHYRAENA_MAX_OPS		64
#define SPHYRAENA_MAX_COLUMNS		16
#define SPHYRAENA_REGISTERS		32
#define SPHYRAENA_GLOBAL_REGISTERS	8
#define SPHYRAENA_THREADSPERBLOCK	192
#define SPHYRAENA_STREAMWIDTH		2

#define SPHYRAENA_INT			0
#define SPHYRAENA_INT64			1
#define SPHYRAENA_FLOAT			2
#define SPHYRAENA_DOUBLE		3
#define SPHYRAENA_ULLI			4
#define SPHYRAENA_NULL			5

#define SPHYRAENA_KB			1024
#define SPHYRAENA_MB			1048576
#define SPHYRAENA_GB			1073741824


// ############################################################################
// Struct definitions


struct sphyraena_op {
	u8 opcode;
	int p1;
	int p2;
	int p3;
	union {
		int i;
		i64 li;
		float f;
		double d;
	} p4;
	u8 p5;
} __attribute__((aligned (32))); // gcc and nvcc align this struct differently
typedef struct sphyraena_op sphyraena_op;

struct sphyraena_stmt {
	int start;	// TODO remove if not needed
	int nOp;
	sphyraena_op op[SPHYRAENA_MAX_OPS];
};
typedef struct sphyraena_stmt sphyraena_stmt;


#define SPHYRAENA_DATA_PADDING (128 - (((3 + 2 * SPHYRAENA_MAX_COLUMNS) * sizeof(int)) % 128))
struct sphyraena_data {
	int rows;
	int columns;
	int stride;
	int types[SPHYRAENA_MAX_COLUMNS];
	int offsets[SPHYRAENA_MAX_COLUMNS];
	//char pad[SPHYRAENA_DATA_PADDING];
	char d[];
};
typedef struct sphyraena_data sphyraena_data;


struct sphyraena_data_gpu {
	int rows;
	int columns;
	int stride;
	int types[SPHYRAENA_MAX_COLUMNS];
	int offsets[SPHYRAENA_MAX_COLUMNS];
};
typedef struct sphyraena_data_gpu sphyraena_data_gpu;


struct sphyraena_results {
	int rows;
	int columns;
	int stride;
	int types[SPHYRAENA_MAX_COLUMNS];
	int offsets[SPHYRAENA_MAX_COLUMNS];
	char r[];
};
typedef struct sphyraena_results sphyraena_results;


struct sphyraena_mem {
	union {
		int i;
		i64 li;
		unsigned long long int ulli;
		float f;
		double d;
		struct {
			int hi;
			int lo;
		} segment;
	} mem;
	int type;
};// __attribute__((aligned (16))); // gcc and nvcc align this struct differently
typedef struct sphyraena_mem sphyraena_mem;


struct sphyraena {
	sqlite3 *db;				// pointer to sqlite 3 database
	sphyraena_data *data_cpu;		// pointer to data block on cpu
	char *data_gpu;				// pointer to data block on gpu
	sphyraena_results *results_cpu;	// pointer to results block on cpu
	sphyraena_results *results_gpu;	// pointer to results block on gpu
	sphyraena_stmt *stmt_cpu;		// pointer to instruction block on cpu
	size_t data_size;				// size of data block
	size_t results_size;			// size of results block
	int threads_per_block;			// set to max
	int pinned_memory;
	int stream_width;
};
typedef struct sphyraena sphyraena;



// ############################################################################
// Function Declarations


int sphyraena_init(
	sphyraena *s,		// pointer to state struct we will initialize
	sqlite3 *db,		// pointer to sqlite 3 database
	size_t data_size, 	// size of data block allocated on both
					//   the cpu and gpu
	size_t results_size,	// size of results block allocated on both
					//   the cpu and gpu
	int pinned_memory);

int sphyraena_cleanup(sphyraena *s);

int sphyraena_prepare_data(sphyraena *s, const char* sql_stmt);

int sphyraena_transfer_data(sphyraena *s);

int sphyraena_transfer_results(sphyraena *s);

int sphyraena_select(sphyraena *s, const char* sql_stmt, int streaming);

int sphyraena_vm(sphyraena *s);

int sphyraena_vm_streaming(sphyraena *s);

int sphyraena_test_queries(sphyraena *s);

int sphyraena_test_sizes(sphyraena *s, int streaming, int include_transfer);

int sphyraena_test_case(
	sphyraena *s,
	const char *sql,
	double *time_native,
	double *time_gpu,
	double *time_transfer,
	int *rows,
	int streaming,
	int include_transfer);



// ############################################################################
// Debug helpers


struct timeval sphyraena_starttime;
struct timeval sphyraena_endtime;

void sphyraena_timer_start();
double sphyraena_timer_stop();
double sphyraena_timer_end(const char* label);
void sphyraena_print_results(sphyraena *s, int n);
cudaError_t sphyraena_print_error();

#ifdef SPHY_DEBUG

const char *sqlite3OpcodeName(int i);

#endif // ifdef DEBUG



// ############################################################################
// Macros

#define SPHYRAENA_ROUNDTOPWR2(x)	\
x--;						\
x |= x >> 1;				\
x |= x >> 2;				\
x |= x >> 4;				\
x |= x >> 8;				\
x |= x >> 16;				\
x++;

#define SPHYRAENA_MIN(a, b) a = ((a <= b) ? a : b);

#define SPHYRAENA_MAX(a, b) a = ((a >= b) ? a : b);




