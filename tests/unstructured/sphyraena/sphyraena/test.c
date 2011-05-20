/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#include "sphyraena.h"
#include "test.h"

static int test_callback(void *rows, int argc, char **argv, char **azColName);

int sphyraena_test_queries(sphyraena *s)
{
	int i, r, rows;
	double time_native, time_gpu, time_transfer;
	double speedup, sum_speedup = 0;
	double tspeedup, sum_tspeedup = 0;

	r = sphyraena_prepare_data(s, "SELECT * FROM test");

	if(r != SPHYRAENA_SUCCESS) {
		fprintf(stderr, "Test failed to prepare data\n");
		return r;
	}

	r = sphyraena_transfer_data(s);

	if(r != SPHYRAENA_SUCCESS) {
		fprintf(stderr, "Test failed to transfer data\n");
		return r;
	}

	printf("\nspeedup (x)\ttspeedup (x)\tcpu (s)   \tgpu (s)   \ttrans (s) \trows\n");

	for(i = 0; i < sphyraena_num_tests; i++) {
		r = sphyraena_test_case(s, sphyraena_test_cases[i],
			&time_native, &time_gpu, &time_transfer, &rows, 0, 0);

		if(r != SPHYRAENA_SUCCESS)
			return 1;

		speedup = time_native / time_gpu;
		sum_speedup += speedup;

		tspeedup = time_native / (time_gpu + time_transfer);
		sum_tspeedup += tspeedup;

		printf("%f\t%f\t%f\t%f\t%f\t%i\n",
			speedup, tspeedup, time_native, time_gpu, time_transfer, rows);
	}

	printf("mean speedup: %f\n", sum_speedup / sphyraena_num_tests);
	printf("mean tspeedup: %f\n", sum_tspeedup / sphyraena_num_tests);

	return SPHYRAENA_SUCCESS;
}




int sphyraena_test_sizes(sphyraena *s, int streaming, int include_transfer)
{
        int i, r, rows, tests = 0;
        double time_native, time_gpu, time_transfer;
        double speedup, sum_speedup = 0;
        double tspeedup, sum_tspeedup = 0;

        printf("\nrows\tspeedup (x)\ttspeedup (x)\tcpu (s)   \tgpu (s)   \ttrans (s) \trows returned\n");

	char query[256];

        for(i = 1; i <= 15000001; i += 100000) {
		sprintf(query, "CREATE TABLE testsize AS SELECT * FROM test WHERE id < %i", i);
		sqlite3_exec(s->db, query, NULL, NULL, NULL);
		r = sphyraena_prepare_data(s, "SELECT * FROM testsize");

		if(r != SPHYRAENA_SUCCESS) {
			fprintf(stderr, "Test failed to prepare data\n");
			return r;
		}

		if(streaming == 0 && include_transfer == 0) {
			r = sphyraena_transfer_data(s);

			if(r != SPHYRAENA_SUCCESS) {
				fprintf(stderr, "Test failed to transfer data\n");
				return r;
			}
		}

                r = sphyraena_test_case(s, "SELECT uniformi, normali20 FROM testsize WHERE uniformi < 50",
                        &time_native, &time_gpu, &time_transfer, &rows, streaming, include_transfer);

                if(r != SPHYRAENA_SUCCESS)
                        return 1;

                speedup = time_native / time_gpu;
                sum_speedup += speedup;

                tspeedup = time_native / (time_gpu + time_transfer);
                sum_tspeedup += tspeedup;

                printf("%i\t%f\t%f\t%f\t%f\t%f\t%i\n",
                        i, speedup, tspeedup, time_native, time_gpu, time_transfer, rows);

		sqlite3_exec(s->db, "DROP TABLE testsize", NULL, NULL, NULL);

		tests++;
        }

        printf("mean speedup: %f\n", sum_speedup / tests);
        printf("mean tspeedup: %f\n", sum_tspeedup / tests);

        return SPHYRAENA_SUCCESS;
}

int sphyraena_test_breakeven(sphyraena *s)
{
        int i, r, rows, tests = 0;
        double time_native, time_gpu, time_transfer;
        double speedup, sum_speedup = 0;
        double tspeedup, sum_tspeedup = 0;

        printf("\nrows\tspeedup (x)\ttspeedup (x)\tcpu (s)   \tgpu (s)   \ttrans (s) \trows returned\n");

        char query[256];

        for(i = 1; i <= 800; i += 10) {
                sprintf(query, "CREATE TABLE testsize AS SELECT * FROM test WHERE id < %i", i);
                sqlite3_exec(s->db, query, NULL, NULL, NULL);
                r = sphyraena_prepare_data(s, "SELECT * FROM testsize");

                if(r != SPHYRAENA_SUCCESS) {
                        fprintf(stderr, "Test failed to prepare data\n");
                        return r;
                }

                r = sphyraena_transfer_data(s);

                if(r != SPHYRAENA_SUCCESS) {
                        fprintf(stderr, "Test failed to transfer data\n");
                        return r;
                }

                r = sphyraena_test_case(s, "SELECT uniformi, normali20 FROM testsize WHERE uniformi < 50",
                        &time_native, &time_gpu, &time_transfer, &rows, 0, 0);

                if(r != SPHYRAENA_SUCCESS)
                        return 1;

                speedup = time_native / time_gpu;
                sum_speedup += speedup;

                tspeedup = time_native / (time_gpu + time_transfer);
                sum_tspeedup += tspeedup;

                printf("%i\t%f\t%f\t%f\t%f\t%f\t%i\n",
                        i, speedup, tspeedup, time_native, time_gpu, time_transfer, rows);

                sqlite3_exec(s->db, "DROP TABLE testsize", NULL, NULL, NULL);

                tests++;
        }

        printf("mean speedup: %f\n", sum_speedup / tests);
        printf("mean tspeedup: %f\n", sum_tspeedup / tests);

        return SPHYRAENA_SUCCESS;
}



int sphyraena_test_case(sphyraena *s, const char *sql,
	double *time_native, double *time_gpu, double *time_transfer, int *rows_, int streaming, int include_transfer)
{
	int rows = 0;
	char *err;
	int r;

	sphyraena_timer_start();
	r = sqlite3_exec(s->db, sql, &test_callback, &rows, &err);
	time_native[0] = sphyraena_timer_stop();

	if(r != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n%s\n", err, sql);
                sqlite3_free(err);
		return 1;
        }

	sphyraena_timer_start();
	if(include_transfer == 1)
		sphyraena_transfer_data(s);
	r = sphyraena_select(s, sql, streaming);
	time_gpu[0] = sphyraena_timer_stop();

	if(r != SPHYRAENA_SUCCESS) {
		fprintf(stderr, "Sphyraena error: case failed\n%s\n", sql);
		return 1;
	}

	sphyraena_timer_start();
	sphyraena_transfer_results(s);
	time_transfer[0] = sphyraena_timer_stop();

	if(rows != s->results_cpu->rows) {
		fprintf(stderr, "Incorrect result: %i cpu rows %i gpu rows\n%s\n",
			rows, s->results_cpu->rows, sql);
		return 1;
	}

	rows_[0] = rows;

	return SPHYRAENA_SUCCESS;
}

static int test_callback(void *rows,
	int argc __attribute__((unused)),
	char **argv __attribute__((unused)),
	char **azColName __attribute__((unused)))
{
	((int*)rows)[0]++;
	return 0;
}
