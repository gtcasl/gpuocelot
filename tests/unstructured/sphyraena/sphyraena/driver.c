/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


// This is a driver for running Sphyraena and SQLite, example uses can be seen
// in the provided Makefile. The arguments are: 
// -m   Load data into SQLite memory
// -p   Use pinned memory
// -d <file>   The database file


#include "sphyraena.h"

// set data and result blocks to 128MB 
#define DATA_SIZE (SPHYRAENA_MB * 128)
#define RESULTS_SIZE (SPHYRAENA_MB * 128)

void printhelp(char **argv);


int main(int argc, char **argv)
{
	sqlite3 *db;
	sphyraena sphy;
	int i, r;
	int dbarg = -1;
	int loadmemory = 0;
	int pinned_memory = 0;

	for(i = 1; i < argc; i++) {
		if(argv[i][0] == '-')
			switch(argv[i][1]) {
				case 'd' :
					dbarg = i + 1;
					printf("Using database %s\n", argv[i+1]);
					break;
				case 'm' :
					loadmemory = 1;
					printf("Loading database into memory\n");
					break;
				case 'p' :
					pinned_memory = 1;
					printf("Using pinned memory\n");
					break;
				default :
					printhelp(argv);
			}
	}

	if(dbarg == -1) {
		printhelp(argv);
		exit(1);
	}

	if(loadmemory) {
		sqlite3_open(":memory:", &db);
		char sql[256];
		sprintf(sql, "ATTACH DATABASE '%s' AS loadfrom", argv[dbarg]);

		r = sqlite3_exec(db, sql, NULL, NULL, NULL);

		sqlite3_exec(db, "CREATE TABLE 'test' AS SELECT * FROM loadfrom.test", NULL, NULL, NULL);
		sqlite3_exec(db, "DETACH loadfrom", NULL, NULL, NULL);
	}
	else {
		r = sqlite3_open(argv[dbarg], &db);
	}

	if(r) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                exit(1);
	}

	sphyraena_init(&sphy, db, DATA_SIZE, RESULTS_SIZE, pinned_memory);


#ifndef RUNTEST
	sphyraena_timer_start();
	sphyraena_prepare_data(&sphy, "SELECT * FROM test");
	const char* sql = "SELECT id, uniformi FROM test WHERE uniformi < 90";
	char* err;

	sphyraena_timer_start();
	r = sqlite3_exec(db, sql, NULL, NULL, &err);
	double native = sphyraena_timer_end("native execution");

	if(err != NULL) {
		fprintf(stderr, "exec error: %s\n", err);
		exit(1);
	}

	sphyraena_timer_start();
	sphyraena_transfer_data(&sphy);
	sphyraena_select(&sphy, sql, 0);
	double vm = sphyraena_timer_end("vm execution");

	sphyraena_timer_start();
	sphyraena_transfer_results(&sphy);
	double results = sphyraena_timer_end("transfer results");

	printf("stream\n");
	printf("speedup:		%fx\n", native / vm);
	printf("speedup with results:	%fx\n", native / (vm + results)); 

	sphyraena_print_results(&sphy, 40);
#else
	sphyraena_test_queries(&sphy);
	/*  this code tests speedup as a function of stream width
 	sphyraena_test_sizes(&sphy, 0, 1);
	sphy.stream_width = 2;
	sphyraena_test_sizes(&sphy, 1, 0);
	sphy.stream_width = 4;
	sphyraena_test_sizes(&sphy, 1, 0);
	sphy.stream_width = 8;
	sphyraena_test_sizes(&sphy, 1, 0);*/
#endif

	sphyraena_cleanup(&sphy);
	sqlite3_close(db);

	return 0;
}

void printhelp(char** argv)
{
	printf("%s [options] -d <database file>\n", argv[0]);
	printf("  -m	Explicitly load database into memory for sqlite queries\n");
	printf("  -p	Use pinned memory for the data and results blocks\n");
	printf("  -d	Use this database file\n");
}

