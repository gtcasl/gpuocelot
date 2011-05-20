/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#include "sphyraena.h"

// generates an opcode program using SQLite and translates it to Sphyraena's format
// Even though the prepare operation works uing a SELECT, Sphyraena does not actually
// store information on the GPU-memory database, thus it must have exactly the same number
// and type of columns as the SQLite table
int sphyraena_select(sphyraena *s, const char* sql_stmt, int streaming)
{
        sqlite3_stmt *stmt;

        // get length of null terminated sql_stmt
        int i;
        for(i = 0; sql_stmt[i] != '\0'; i++);

        // prepare our sqlite3_stmt object
        sqlite3_prepare_v2(s->db, sql_stmt, i, &stmt, NULL);

	// pointers for accessing the stmt details
	// sqlite3_stmt's are internally represented as Vdbe's
	Vdbe *vdbe = (Vdbe*) stmt;
	VdbeOp *o = vdbe->aOp;

#ifdef SPHY_DEBUG
	for(i = 0; i < vdbe->nOp; i++)
		printf("%i:  %s\t\t%i\t%i\t%i\n", i, sqlite3OpcodeName(o[i].opcode),
			o[i].p1, o[i].p2, o[i].p3);
#endif

	// find the first OP_Next
	for(i = 0; i < vdbe->nOp && o[i].opcode != OP_Next; i++);

	// set start to the destination of OP_Next when it jumps back
	// to start the next row
	int start = o[i].p2;

	// stencil for going over the sphyraena_op's
	sphyraena_op *op;

	// set sphyraena_stmt variables
	s->stmt_cpu->nOp = vdbe->nOp;
	s->stmt_cpu->start = start;

	char *agg_name;

	// copy over program operations and transform from sqlite3 
	// format to sphyraena format
	for(i = 0; i < vdbe->nOp; i++) {
		op = &(s->stmt_cpu->op[i]);
		op->opcode = o[i].opcode;
		op->p1 = o[i].p1;
		op->p2 = o[i].p2;
		op->p3 = o[i].p3;
		op->p5 = o[i].p5;

		switch(op->opcode) {
			case OP_Int64 :
				// p4 normally stores a pointer to an int64, 
				// dereference for the gpu
				op->p4.li = o[i].p4.pI64[0];
				break;

			case OP_Real :
				// p4 normally stores a pointer to a double, 
				// dereference for the gpu
				op->p4.d = o[i].p4.pReal[0];
				break;

				// SQLite stores the type of aggregate as a string,
				// translate it to an int
			case OP_AggStep :
			case OP_AggFinal :
				agg_name = o[i].p4.pFunc->zName;

				if(strcmp(agg_name, SPHYRAENA_AGG_STR_COUNT) == 0) {
					op->p4.i = SPHYRAENA_AGG_COUNT;
				}
				else if(strcmp(agg_name, SPHYRAENA_AGG_STR_MAX) == 0) {
					op->p4.i = SPHYRAENA_AGG_MAX;
				}
				else if(strcmp(agg_name, SPHYRAENA_AGG_STR_MIN) == 0) {
					op->p4.i = SPHYRAENA_AGG_MIN;
				}
				else if(strcmp(agg_name, SPHYRAENA_AGG_STR_SUM) == 0) {
					op->p4.i = SPHYRAENA_AGG_SUM;
				}
				else if(strcmp(agg_name, SPHYRAENA_AGG_STR_AVG) == 0) {
					op->p4.i = SPHYRAENA_AGG_AVG;
				}
				break;
		}
	}

	sqlite3_finalize(stmt);

	if(streaming)
		sphyraena_vm_streaming(s);
	else
		sphyraena_vm(s);

	return SPHYRAENA_SUCCESS;
}
