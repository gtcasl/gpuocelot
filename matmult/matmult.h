/*!

*/

#ifndef MATMULT_BENCHMARK
#define MATMULT_BENCHMARK

#define MATRIX_COL_MAJOR 1

void matrix_multiply_GPU(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols);

void fill_matrix(float *A, int M, int N, float s);

#endif

