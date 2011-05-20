#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>


// returned row
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
		printf("%s = %s\t", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

// create test_int table in database
void create_int_tables(sqlite3 *db) {
	int r;
	char *err = 0;

	r = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS test_int (id INTEGER PRIMARY KEY, uniform INTEGER, normal5 INTEGER, normal20 INTEGER, t20 INTEGER)",
		callback, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}
}

// create test table in database
void create_tables(sqlite3 *db) {
	int r;
	char *err = 0;

	r = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, uniformi INTEGER, normali5 INTEGER, normali20 INTEGER, uniformf FLOAT, normalf5 FLOAT, normalf20 FLOAT)",
		callback, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}
}

// insert rows into test with varying random distributions
void insert_data(sqlite3 *db, int rows, gsl_rng *ran) {
	char* err = 0;
	int i;
	int r;

	r = sqlite3_exec(db, "PRAGMA synchronous = 0", NULL, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}

	fprintf(stderr, "executed pragma\n");

	r = sqlite3_exec(db, "BEGIN TRANSACTION", NULL, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}

	fprintf(stderr, "started transaction\n");

	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db,
		"INSERT INTO test (id, uniformi, normali5, normali20, uniformf, normalf5, normalf20) VALUES (?,?,?,?,?,?,?)", 
		512,
		&stmt,
		0);

	for(i = 0; i < rows; i++) {
		sqlite3_bind_int(stmt, 1, i);
		sqlite3_bind_int(stmt, 2, (int)gsl_ran_flat(ran, -100, 100));
		sqlite3_bind_int(stmt, 3, (int)gsl_ran_gaussian(ran, 5));
		sqlite3_bind_int(stmt, 4, (int)gsl_ran_gaussian(ran, 20));
		sqlite3_bind_int(stmt, 5, (float)gsl_ran_flat(ran, -100, 100));
		sqlite3_bind_int(stmt, 6, (float)gsl_ran_gaussian(ran, 5));
		sqlite3_bind_int(stmt, 7, (float)gsl_ran_gaussian(ran, 20));

		int r = sqlite3_step(stmt);

		if(r != SQLITE_DONE && r != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
			sqlite3_free(err);
			return;
		}

		sqlite3_reset(stmt);
		
		if(i % 10000 == 0)
			printf("%i\n", i);
	}

	sqlite3_finalize(stmt);

	sqlite3_exec(db, "COMMIT", 0, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}
}


// insert rows into test_int with varying random distributions
void insert_int_data(sqlite3 *db, int rows, gsl_rng *ran) {
	char* err = 0;
	int i;
	int r;

	r = sqlite3_exec(db, "PRAGMA synchronous = 0", NULL, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}

	fprintf(stderr, "executed pragma\n");

	r = sqlite3_exec(db, "BEGIN TRANSACTION", NULL, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}

	fprintf(stderr, "started transaction\n");

	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db,
		"INSERT INTO test_int (id, uniform, normal5, normal20, t20) VALUES (?,?,?,?,?)", 
		512,
		&stmt,
		0);

	for(i = 0; i < rows; i++) {
		sqlite3_bind_int(stmt, 1, i);
		sqlite3_bind_int(stmt, 2, (int)gsl_ran_flat(ran, -100, 100));
		sqlite3_bind_int(stmt, 3, (int)gsl_ran_gaussian(ran, 5));
		sqlite3_bind_int(stmt, 4, (int)gsl_ran_gaussian(ran, 20));
		sqlite3_bind_int(stmt, 5, (int)gsl_ran_cauchy(ran, 20));

		int r = sqlite3_step(stmt);

		if(r != SQLITE_DONE && r != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
			sqlite3_free(err);
			return;
		}

		sqlite3_reset(stmt);
		
		if(i % 1000 == 0)
			printf("%i\n", i);
	}

	sqlite3_finalize(stmt);

	sqlite3_exec(db, "COMMIT", 0, 0, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}
}



void time_execution(sqlite3 *db, const char* cmd)
{
	printf("Starting execution of command\n%s\n", cmd);

	char* err;

	struct timeval t;
	gettimeofday(&t, NULL);
	double starttime = (double)t.tv_sec + (double)t.tv_usec / 1000000;

	int r = sqlite3_exec(db, cmd, &callback, NULL, &err);

	if(r != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}

	gettimeofday(&t, NULL);
	double endtime = (double)t.tv_sec + (double)t.tv_usec / 1000000;

	printf("================\n");
	printf(" %e seconds\n", endtime - starttime);
	printf("================\n");
}


int main(int argc, char **argv){
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	if(argc != 3) {
		fprintf(stderr, "%s <database name> <rows>\n", argv[0]);
		exit(1);
	}

	const gsl_rng_type *type;
	gsl_rng *ran;

	type = gsl_rng_ranlxd2;
	ran = gsl_rng_alloc(type);
	gsl_rng_set(ran, time(0));

	rc = sqlite3_open(argv[1], &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	create_tables(db);

	fprintf(stderr, "tables created\n");

	insert_data(db, atoi(argv[2]), ran);
	
	//time_execution(db, "SELECT SUM(uniform), SUM(normal5), SUM(normal10), SUM(normal20) FROM test_int");

	//time_execution(db, "SELECT * FROM test_int WHERE uniform > 98");

	//rc = sqlite3_exec(db, "SELECT * FROM test", callback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);
	gsl_rng_free(ran);

	return 0;
}

