/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#include "sphyraena.h"

int sphyraena_prepare_data(sphyraena *s, const char* sql_stmt)
{
	sqlite3_stmt *stmt;
	sphyraena_data *data = s->data_cpu;

	// get length of null terminated sql_stmt
	int i;
	for(i = 0; sql_stmt[i] != '\0'; i++);

	// prepare our sqlite3_stmt object
	sqlite3_prepare_v2(s->db, sql_stmt, i, &stmt, NULL);

#ifdef SPHY_DEBUG
	sphyraena_timer_start();
#endif
	
	// step once to examine the results to determine data stride
	int r = sqlite3_step(stmt);

	// if a row isn't returned when we step return error
	if(r != SQLITE_ROW)
		return SPHYRAENA_ERR_STMT;

	// get and set number of columns in table
	int columns = sqlite3_column_count(stmt);
	data->columns = columns;

	// offset tracks the offset of each column in bytes from the beginning
	// of the row, since not every column is 4 bytes
	int offset = 0;
	sqlite3_value *val;

	// go through the first row of results to get all of our data
	// types so we know column offsets, don't save column data yet
	//
	// for each column get it from the sqlite info
	for(i = 0; i < columns; i++) {
		val = sqlite3_column_value(stmt, i);

		// if column type is integer
		if(val->type == SQLITE_INTEGER) {
#ifdef USE_INT64
			// SQLite does not differentiate between 32 and 64 bit
			// ints in the types data column, this controls whether
			// or not we want to cast all of the int values to
			// int32 or int64

			// set the type in the sphyraena_data struct
			data->types[i] = SPHYRAENA_INT64;
			// set column offset
			data->offsets[i] = offset;
			// increment offset
			offset += sizeof(i64);
#else
			data->types[i] = SPHYRAENA_INT;
			data->offsets[i] = offset;
			offset += sizeof(int);
#endif
		}
		else if(val->type == SQLITE_FLOAT) {
#ifdef USE_DOUBLES
			// see USE_INT64
			data->types[i] = SPHYRAENA_DOUBLE;
			data->offsets[i] = offset;
			offset += sizeof(double);
#else
			data->types[i] = SPHYRAENA_FLOAT;
			data->offsets[i] = offset;
			offset += sizeof(float);
#endif
		}
		else {
			fprintf(stderr,
				"Error: the data type for column %i is not supported\n",
				i);
			return SPHYRAENA_ERR_TYPE;
		}
	}

	// set row stride to the current offset
	int stride = offset;

	// round stride to next power of 2
/*	stride--;
	stride |= stride >> 1;
	stride |= stride >> 2;
	stride |= stride >> 4;
	stride |= stride >> 8;
	stride |= stride >> 16;
	stride++;*/

	s->data_cpu->stride = stride;
	int rows = 0;
	int last_row = floor((float)s->data_size / (float)stride);
	char *d = (char*)&s->data_cpu->d;
	void *p;

	do {
		for(i = 0; i < columns; i++) {
			p = d + rows * stride + data->offsets[i];

			switch(data->types[i]) {

				case SPHYRAENA_INT :
					((int*)p)[0] = sqlite3_column_int(stmt, i);
					break;

				case SPHYRAENA_INT64 :
					((i64*)p)[0] = sqlite3_column_int64(stmt, i);
					break;

				case SPHYRAENA_FLOAT :
					((float*)p)[0] = (float)sqlite3_column_double(stmt, i);
					break;

				case SPHYRAENA_DOUBLE :
					((double*)p)[0] = sqlite3_column_double(stmt, i);
					break;

				default:
					fprintf(stderr,
						"Error: the data type for column %i is not supported\n",
						i);
					return SPHYRAENA_ERR_TYPE;
			}
		}

		rows++;

		if(rows >= last_row) {
			fprintf(stderr, "Warning: selected data too large for gpu data block\n");
			break;
		}
	} while(sqlite3_step(stmt) == SQLITE_ROW);

#ifdef COLUMNROW
	// the current format is row-column data format, this block performs a
	// translation to column-row format, which takes longer, but may make
	// query execution faster because of coalescing
	char *temp = (char*)malloc(s->data_size);
	int offsets[columns];
	int j;

	for(i = 0; i < rows; i++) {
		for(j = 0; j < columns; j++) {
			switch(data->types[j]) {

				case SPHYRAENA_INT :
					((int*)(temp + data->offsets[j] * rows))[i] =
						((int*)(d + i * stride + data->offsets[j]))[0];
					break;

				case SPHYRAENA_INT64 :
					((i64*)(temp + data->offsets[j] * rows))[i] =
						((i64*)(d + i * stride + data->offsets[j]))[0];
					break;

				case SPHYRAENA_FLOAT :
					((float*)(d + data->offsets[j] * rows))[i] =
						((float*)(d + i * stride + data->offsets[j]))[0];
					break;

				case SPHYRAENA_DOUBLE :
					((double*)(temp + data->offsets[j] * rows))[i] =
						((double*)(d + i * stride + data->offsets[j]))[0];
					break;
			}
		}
	}

	for(i = 0; i < columns; i++)
		data->offsets[i] *= rows;

	memcpy(d, temp, s->data_size);
	free(temp);
#endif

	data->rows = rows;


#ifdef SPHY_DEBUG
	sphyraena_timer_end("SQLite select");
#endif

	// clean up sqlite stmt
	sqlite3_finalize(stmt);

	return SPHYRAENA_SUCCESS;
}

