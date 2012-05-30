#include "config.h"
#include "cod.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif

int
main(int argc, char **argv)
{
    int test_to_run = -1;
    if (argc > 1) {
	sscanf(argv[1], "%d", &test_to_run);
    }

    if ((test_to_run == 1) || (test_to_run == -1)) {
	/* test the basics */
	char code_string[] = "\
{\n\
	typedef struct test {\n\
	    int ti,tj;\n\
	    long tk;\n\
	    short tl;\n\
	} test_struct;\n\
\n\
    int j = 4;\n\
    long k = 10;\n\
    short l = 3;\n\
	test_struct t;\n\
    t.ti = j;\n\
    t.tj = j;\n\
    t.tk = k;\n\
    t.tl = l;\n\
    return t.tl * (t.tj + t.tk);\n\
}";

	cod_parse_context context = new_cod_parse_context();
	cod_code gen_code;
	long (*func)();
	long result;

	gen_code = cod_code_gen(code_string, context);
	func = (long(*)()) (long) gen_code->func;
	result = func();
	assert(result == 42);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }

    if ((test_to_run == 2) || (test_to_run == -1)) {
	/* test the basics */
	char code_string[] = "\
{\n\
	typedef struct test {\n\
	    void *next;\n\
	    int i;\n\
	} test_struct;\n\
\n\
    int sum = 0;\n\
    test_struct *t1;\n\
    test_struct *t2;\n\
    t1 = malloc(sizeof(test_struct));\n\
    t1.i = 1; \n\
    t1.next = (void*)malloc(sizeof(test_struct));\n\
    t2 = (test_struct *) t1.next;\n\
    t2.i = 2;\n\
    t2.next = (void*)malloc(sizeof(test_struct));\n\
    t2 = (test_struct *) t2.next;\n\
    t2.i = 3;\n\
    t2.next = (void*)malloc(sizeof(test_struct));\n\
    t2 = (test_struct *) t2.next;\n\
    t2.i = 4;\n\
    t2.next = (void*)malloc(sizeof(test_struct));\n\
    t2 = (test_struct *) t2.next;\n\
    t2.i = 5;\n\
    t2.next = (void*)malloc(sizeof(test_struct));\n\
    t2 = (test_struct *) t2.next;\n\
    t2.i = 6;\n\
    t2.next = (void*)0;\n\
    while ( t1 != (void*)0 ) {\n\
	sum = sum + t1.i;\n\
	t2 = (test_struct *)t1.next;\n\
	free(t1); t1 = t2;\n\
    }\n\
    return sum;\n\
}";

	static char extern_string[] = "int printf(string format, ...);\n\
void *malloc(int size);\n\
void free(void *pointer);\n";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {"malloc", (void*)(long)malloc},
	    {"free", (void*)(long)free},
	    {(void*)0, (void*)0}
	};
	cod_parse_context context = new_cod_parse_context();
	cod_code gen_code;
	long (*func)();
	long result;

	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);
	gen_code = cod_code_gen(code_string, context);
	if (gen_code == NULL) {
	    printf("Code generation failed for test 2\n");
	} else {
	    func = (long(*)()) (long) gen_code->func;
	    result = func();
	    assert(result == 21);
	    cod_code_free(gen_code);
	}
	cod_free_parse_context(context);
    }

    if ((test_to_run == 3) || (test_to_run == -1)) {
	/* test the array fields */
	char code_string[] = "\
{\n\
	typedef struct test {\n\
	    int size;\n\
	    int array[5];\n\
	} test_struct;\n\
\n\
    int i;\n\
    int sum = 0;\n\
    test_struct t1;\n\
    t1.size = 5;\n\
    t1.array[0] = 6;\n\
    t1.array[1] = 5;\n\
    t1.array[2] = 4;\n\
    t1.array[3] = 3;\n\
    t1.array[4] = 2;\n\
    for (i = 0; i < t1.size ; i++) {\n\
	sum = sum + t1.array[i];\n\
    }\n\
    return sum;\n\
}";

	static char extern_string[] = "int printf(string format, ...);\n\
void *malloc(int size);\n\
void free(void *pointer);\n";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {"malloc", (void*)(long)malloc},
	    {"free", (void*)(long)free},
	    {(void*)0, (void*)0}
	};
	cod_parse_context context = new_cod_parse_context();
	cod_code gen_code;
	long (*func)();
	long result;

	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);
	gen_code = cod_code_gen(code_string, context);
	if (gen_code == NULL) {
	    printf("Code generation failed for test 3\n");
	} else {
	    func = (long(*)()) (long) gen_code->func;
	    result = func();
	    assert(result == 20);
	    cod_code_free(gen_code);
	}
	cod_free_parse_context(context);
    }
    if ((test_to_run == 4) || (test_to_run == -1)) {
	/* test dynamic array fields */
	char code_string[] = "\
{\n\
	typedef struct test {\n\
	    int size;\n\
	    int array[size];\n\
	} test_struct;\n\
\n\
    int i;\n\
    int sum = 0;\n\
    test_struct t1;\n\
    t1.size = 5;\n\
    t1.array[0] = 6;\n\
    t1.array[1] = 5;\n\
    t1.array[2] = 4;\n\
    t1.array[3] = 3;\n\
    t1.array[4] = 2;\n\
    for (i = 0; i < t1.size ; i++) {\n\
	sum = sum + t1.array[i];\n\
    }\n\
    return sum;\n\
}";

	static char extern_string[] = "int printf(string format, ...);\n\
void *malloc(int size);\n\
void free(void *pointer);\n";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {"malloc", (void*)(long)malloc},
	    {"free", (void*)(long)free},
	    {(void*)0, (void*)0}
	};
	cod_parse_context context = new_cod_parse_context();
	cod_code gen_code;
	long (*func)();
	long result;

	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);
	gen_code = cod_code_gen(code_string, context);
	if (gen_code == NULL) {
	    printf("Code generation failed for test 3\n");
	} else {
	    func = (long(*)()) (long) gen_code->func;
	    result = func();
	    assert(result == 20);
	    cod_code_free(gen_code);
	}
	cod_free_parse_context(context);
    }
    if ((test_to_run == 5) || (test_to_run == -1)) {
	/* test dynamic array fields in static vars */
	char code_string[] = "\
{\n\
	typedef struct test {\n\
	    int size;\n\
	    int array[size];\n\
	} test_struct;\n\
\n\
    int i;\n\
    static int sum = 0;\n\
    static test_struct t1;\n\
    t1.size = 5;\n\
    t1.array[0] = 6;\n\
    t1.array[1] = 5;\n\
    t1.array[2] = 4;\n\
    t1.array[3] = 3;\n\
    t1.array[4] = 2;\n\
    for (i = 0; i < t1.size ; i++) {\n\
	sum = sum + t1.array[i];\n\
    }\n\
    return sum;\n\
}";

	static char extern_string[] = "int printf(string format, ...);\n";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {"malloc", (void*)(long)malloc},
	    {"free", (void*)(long)free},
	    {(void*)0, (void*)0}
	};
	cod_parse_context context = new_cod_parse_context();
	cod_code gen_code;
	long (*func)();
	long result;

	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);
	gen_code = cod_code_gen(code_string, context);
	if (gen_code == NULL) {
	    printf("Code generation failed for test 3\n");
	} else {
	    func = (long(*)()) (long) gen_code->func;
	    result = func();
	    assert(result == 20);
	    cod_code_free(gen_code);
	}
	cod_free_parse_context(context);
    }

    return 0;
}

