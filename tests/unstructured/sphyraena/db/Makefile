GSL_VER = 1.9

gendb: gendb.c
	gcc -O2 -Wall -Wextra gendb.c -I../sqlite -I../gsl -c -o gendb.o
	gcc gendb.o ../sqlite/sqlite3.o -ldl -lpthread -lgsl -lgslcblas -L../gsl/.libs -L../gsl/cblas/.libs -o gendb
	

