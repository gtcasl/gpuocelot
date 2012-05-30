#include "ecl.h"
#include <stdlib>
#ifdef HAVE_MALLOC_H
#include "malloc.h"
#endif
#include "assert.h"
#include <stdio.h>
#include <string.h>

typedef struct _multi_array_rec {
    long	ifield;
    double	double_array[2][2][2][2];
    int		(*int_array)[2];
    int		(*int_array2)[4];
    int		(*int_array3)[4][4];
} multi_array_rec, *multi_array_rec_ptr;

IOField multi_array_flds[] = {
    {"ifield", "integer", sizeof(int), IOOffset(multi_array_rec_ptr, ifield)},
    {"double_array", "float[2][2][2][2]", sizeof(double),
     IOOffset(multi_array_rec_ptr, double_array)},
    {"int_array", "integer[ifield][2]", sizeof(int),
     IOOffset(multi_array_rec_ptr, int_array)},
    {"int_array2", "integer[2][ifield]", sizeof(int),
     IOOffset(multi_array_rec_ptr, int_array2)},
    {"int_array3", "integer[ifield][ifield][ifield]", sizeof(int),
    IOOffset(multi_array_rec_ptr, int_array3)},
    {(char *) 0, (char *) 0, 0, 0}
};


typedef struct _complex_rec {
    double r;
    double i;
} complex, *complex_ptr;

typedef struct _nested_rec {
    complex item;
} nested, *nested_ptr;

static IOField nested_field_list[] =
{
    {"item", "complex", sizeof(complex), IOOffset(nested_ptr, item)},
    {NULL, NULL, 0, 0}
};

static IOField complex_field_list[] =
{
    {"r", "double", sizeof(double), IOOffset(complex_ptr, r)},
    {"i", "double", sizeof(double), IOOffset(complex_ptr, i)},
    {NULL, NULL, 0, 0}
};

typedef struct _simple_rec {
    int integer_field;
    short short_field;
    long long_field;
    nested nested_field;
    double double_field;
    char char_field;
    int scan_sum;
} simple_rec, *simple_rec_ptr;

static IOField simple_field_list[] =
{
    {"integer_field", "integer",
     sizeof(int), IOOffset(simple_rec_ptr, integer_field)},
    {"short_field", "integer",
     sizeof(short), IOOffset(simple_rec_ptr, short_field)},
    {"long_field", "integer",
     sizeof(long), IOOffset(simple_rec_ptr, long_field)},
    {"nested_field", "nested",
     sizeof(nested), IOOffset(simple_rec_ptr, nested_field)},
    {"double_field", "float",
     sizeof(double), IOOffset(simple_rec_ptr, double_field)},
    {"char_field", "char",
     sizeof(char), IOOffset(simple_rec_ptr, char_field)},
    {"scan_sum", "integer",
     sizeof(int), IOOffset(simple_rec_ptr, scan_sum)},
    {NULL, NULL, 0, 0}
};

int
submit(ecl_exec_context ec, int port, void *data, void *type_info)
{
    IOFormatList formats = (IOFormatList) type_info;
    printf("In submit, ec is %lx, port is %d, data is %lx, tpye_info is %lx\n",
	   ec, port, data, type_info);
    while (formats[0].format_name != NULL) {
	IOFieldList tmp = formats[0].field_list;
	printf("Format \"%s\" - \n", formats[0].format_name);
	while(tmp[0].field_name != NULL) {
	    printf("{%s, %s, %d, %d},\n", tmp[0].field_name,
		   tmp[0].field_type, tmp[0].field_size, tmp[0].field_offset);
	    tmp++;
	}
	formats++;
    }
}

int
main() 
{
    static char extern_string[] = "int printf(string format, ...);\n\
	int submit(ecl_exec_context ec, int port, void *d, ecl_type_spec dt);";
    static ecl_extern_entry externs[] =
	{
	    {"printf", (void*)(long)printf},
	    {"submit", (void*)(long)submit},
	    {(void*)0, (void*)0}
	};
    static char code[] = "{\n\
    submit(1, input);\n\
     }";

/*

*/
    int i, j, k, l;
    ecl_code gen_code;
    ecl_exec_context ec;
    void (*func)(ecl_exec_context, void*);

    multi_array_rec multi_array;
   
    ecl_parse_context context = new_ecl_parse_context();

    multi_array.ifield = 4;
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 2; j++) {
	    for (k = 0; k < 2; k++) {
		for (l = 0; l < 2; l++) {
		    multi_array.double_array[i][j][k][l] = 
			1000*i + 100*j + 10*k +l;
		}
	    }
	}
    }
    multi_array.int_array = malloc(2*4*sizeof(int));
    for (i = 0; i < 4; i++) {
	for (j = 0; j < 2; j++) {
	    multi_array.int_array[i][j] = 1000*i + 100*j;
	}
    }
    multi_array.int_array2 = malloc(4*2*sizeof(int));
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 4; j++) {
	    printf("element [%d][%d] is at addr %lx\n", i, j, &multi_array.int_array2[i][j]);
	    multi_array.int_array2[i][j] = 1000*i + 100*j;
	}
    }
    multi_array.int_array3 = malloc(4*4*4*sizeof(int));
    for (i = 0; i < 4; i++) {
	for (j = 0; j < 4; j++) {
	    for (k = 0; k < 4; k++) {
		multi_array.int_array3[i][j][k] = 1000*i + 100*j + 10*k;
	    }
	}
    }


    ecl_assoc_externs(context, externs);
    ecl_parse_for_context(extern_string, context);

    ecl_add_struct_type("multi_array", multi_array_flds, context);
    ecl_add_struct_type("nested", nested_field_list, context);
    ecl_add_struct_type("complex", complex_field_list, context);
    ecl_add_struct_type("simple", simple_field_list, context);
    ecl_subroutine_declaration("int proc(ecl_exec_context ec, simple *input)", context);
   
    gen_code = ecl_code_gen(code, context);
    func = (void (*)(ecl_exec_context, void*))(long)gen_code->func;

    ecl_dump(gen_code);
    ec = ecl_create_exec_context(gen_code);
    printf("Main ec is %lx\n", (long) ec);
    func(ec, &multi_array);
    ecl_exec_context_free(ec);
    ecl_code_free(gen_code);
    ecl_free_parse_context(context);
/*    if ((data.num_points != 1) || (data.image_data[0].num_points != 1)) 
      return 1;*/
    return 0;
}
