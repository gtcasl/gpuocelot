#include "config.h"
#ifndef LINUX_KERNEL_MODULE
#include "stdio.h"
#endif
#ifdef LINUX_KERNEL_MODULE
#ifndef MODULE
#define MODULE
#endif
#ifndef __KERNEL__
#define __KERNEL__
#endif
#include <linux/kernel.h>
#include <linux/module.h>
#endif
#ifndef LINUX_KERNEL_MODULE
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#endif
#include "cod.h"
#include "cod_internal.h"
#include "structs.h"
#include "assert.h"
#ifndef LINUX_KERNEL_MODULE
#include <ctype.h>
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <string.h>
#else
#include <linux/ctype.h>
#include <linux/string.h>
#include <linux/mm.h>
#endif
#ifndef LINUX_KERNEL_MODULE
#ifdef HAVE_ATL_H
#include "atl.h"
#endif
#ifdef HAVE_CERCS_ENV_H
#include "cercs_env.h"
#endif
#endif


#ifndef LINUX_KERNEL_MODULE
#ifdef HAVE_ATL_H
static int
attr_set(attr_list l, char *name)
{
    atom_t atom = attr_atom_from_string(name);
    attr_value_type junk;
    attr_value junk2;
    if (atom == 0 ) return 0;
    
    return query_attr(l, atom, &junk, &junk2);
}

static void
std_set_int_attr(attr_list l, char *name, int value)
{
    atom_t atom = attr_atom_from_string(name);
    if (atom == 0 ) return;

    set_int_attr(l, atom, value);
}

static void
std_set_long_attr(attr_list l, char *name, long value)
{
    atom_t atom = attr_atom_from_string(name);
    if (atom == 0 ) return;

    set_long_attr(l, atom, value);
}

static void
std_set_double_attr(attr_list l, char *name, double value)
{
    atom_t atom = attr_atom_from_string(name);
    if (atom == 0 ) return;

    set_double_attr(l, atom, value);
}

static void
std_set_float_attr(attr_list l, char *name, float value)
{
    atom_t atom = attr_atom_from_string(name);
    if (atom == 0 ) return;

    set_float_attr(l, atom, value);
}

static void
std_set_string_attr(attr_list l, char *name, char *value)
{
    atom_t atom = attr_atom_from_string(name);
    if (atom == 0 ) return;

    set_string_attr(l, atom, value);
}

static int
attr_ivalue(attr_list l, char *name)
{
    atom_t atom = attr_atom_from_string(name);
    int i = 0;
    if (atom == 0 ) return 0;
    
    get_int_attr(l, atom, &i);
    return i;
}

static long
attr_lvalue(attr_list l, char *name)
{
    atom_t atom = attr_atom_from_string(name);
    long lo = 0;
    if (atom == 0 ) return 0;
    
    get_long_attr(l, atom, &lo);
    return lo;
}

static double
attr_dvalue(attr_list l, char *name)
{
    atom_t atom = attr_atom_from_string(name);
    double d;
    if (atom == 0 ) return 0;
    
    get_double_attr(l, atom, &d);
    return d;
}

static float
attr_fvalue(attr_list l, char *name)
{
    atom_t atom = attr_atom_from_string(name);
    float f;
    if (atom == 0 ) return 0;
    
    get_float_attr(l, atom, &f);
    return f;
}

static char *
attr_svalue(attr_list l, char *name)
{
    atom_t atom = attr_atom_from_string(name);
    char *s;
    if (atom == 0 ) return 0;
    
    get_string_attr(l, atom, &s);
    return strdup(s);
}
#endif

static char extern_string[] = "\n\
	int attr_set(attr_list l, string name);\n\
	void set_long_attr(attr_list l, string name, long value);\n\
	void set_float_attr(attr_list l, string name, double value);\n\
	void set_double_attr(attr_list l, string name, double value);\n\
	void set_int_attr(attr_list l, string name, int value);\n\
	void set_string_attr(attr_list l, string name, string value);\n\
	int attr_ivalue(attr_list l, string name);\n\
	long attr_lvalue(attr_list l, string name);\n\
	double attr_dvalue(attr_list l, string name);\n\
	double attr_fvalue(attr_list l, string name);\n\
	char* attr_svalue(attr_list l, string name);\n\
        void chr_get_time( chr_time *time);\n\
        void chr_timer_diff( chr_time *diff_time, chr_time *src1, chr_time *src2);\n\
	int chr_timer_eq_zero( chr_time *time);\n\
	void chr_timer_sum( chr_time *sum_time, chr_time *src1, chr_time *src2);\n\
	void chr_timer_start (chr_time *timer);\n\
	void chr_timer_stop (chr_time *timer);\n\
	double chr_time_to_nanosecs (chr_time *time);\n\
	double chr_time_to_microsecs (chr_time *time);\n\
	double chr_time_to_millisecs (chr_time *time);\n\
	double chr_time_to_secs (chr_time *time);\n\
	double chr_approx_resolution();\n";

static cod_extern_entry externs[] = 
{
#ifdef HAVE_ATL_H
    {"attr_set", (void*)(long)attr_set},
    {"set_int_attr", (void*)(long)std_set_int_attr},
    {"set_long_attr", (void*)(long)std_set_long_attr},
    {"set_double_attr", (void*)(long)std_set_double_attr},
    {"set_float_attr", (void*)(long)std_set_float_attr},
    {"set_string_attr", (void*)(long)std_set_string_attr},
    {"attr_ivalue", (void*)(long)attr_ivalue},
    {"attr_lvalue", (void*)(long)attr_lvalue},
    {"attr_dvalue", (void*)(long)attr_dvalue},
    {"attr_fvalue", (void*)(long)attr_fvalue},
    {"attr_svalue", (void*)(long)attr_svalue},
#endif
#ifdef HAVE_CERCS_ENV_H
    {"chr_get_time", (void*)(long)chr_get_time},
    {"chr_timer_diff", (void*)(long)chr_timer_diff},
    {"chr_timer_eq_zero", (void*)(long)chr_timer_eq_zero},
    {"chr_timer_sum", (void*)(long)chr_timer_sum},
    {"chr_timer_start", (void*)(long)chr_timer_start},
    {"chr_timer_stop", (void*)(long)chr_timer_stop},
    {"chr_time_to_nanosecs", (void*)(long)chr_time_to_nanosecs},
    {"chr_time_to_microsecs", (void*)(long)chr_time_to_microsecs},
    {"chr_time_to_millisecs", (void*)(long)chr_time_to_millisecs},
    {"chr_time_to_secs", (void*)(long)chr_time_to_secs},
    {"chr_approx_resolution", (void*)(long)chr_approx_resolution},
#endif
    {(void*)0, (void*)0}
};

#ifdef HAVE_CERCS_ENV_H
FMField chr_time_list[] = {
    {"d1", "double", sizeof(double), FMOffset(chr_time*, d1)}, 
    {"d2", "double", sizeof(double), FMOffset(chr_time*, d2)}, 
    {"d3", "double", sizeof(double), FMOffset(chr_time*, d3)}, 
    {NULL, NULL, 0, 0}};
#endif

extern void
cod_add_standard_elements(cod_parse_context context)
{
#ifdef HAVE_ATL_H
    sm_ref attr_node = cod_new_reference_type_decl();
    attr_node->node.reference_type_decl.name = strdup("attr_list");
    cod_add_decl_to_parse_context("attr_list", attr_node, context);
    cod_add_decl_to_scope("attr_list", attr_node, context);
    cod_add_defined_type("attr_list", context);
#endif
#ifdef HAVE_CERCS_ENV_H
    cod_add_struct_type("chr_time", chr_time_list, context);
#endif
    cod_add_defined_type("cod_type_spec", context);
    cod_add_defined_type("cod_exec_context", context);
    cod_add_defined_type("cod_closure_context", context);
    cod_semanticize_added_decls(context);
    
#if defined(HAVE_ATL_H) && defined(HAVE_CERCS_ENV_H)
    cod_assoc_externs(context, externs);
    cod_parse_for_context(extern_string, context);
    cod_swap_decls_to_standard(context);
#endif
}

#else /* LINUX_KERNEL_MODULE */

extern void
cod_add_standard_elements(cod_parse_context context)
{
}
#endif /* LINUX_KERNEL_MODULE */
