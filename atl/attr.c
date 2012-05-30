#include "config.h"
#include "stdio.h"
#include "atl.h"

#ifndef LINUX_KERNEL_MODULE
#  include "config.h"
#  ifdef HAVE_WINDOWS_H
#    include <windows.h>
#  else
#    include <ctype.h>
#    include <stdio.h>
#    include <stdlib.h>
#    include <string.h>
#    ifdef HAVE_MALLOC_H
#      include <malloc.h>
#    endif
#    include <unix_defs.h>
#  endif
#else
#  ifndef __KERNEL__
#    define __KERNEL__
#  endif
#  ifndef MODULE
#    define MODULE
#  endif

#  include "kernel/katl.h"
#  include "kernel/library.h"
#  include <linux/ctype.h>
#  include "kernel/kernel_defs.h"
#endif

#include "assert.h"
#ifndef LINUX_KERNEL_MODULE
#  ifdef HAVE_CERCS_ENV_H
#    include "cercs_env.h"
#  else
#    define cercs_getenv(a) ((char *)0)
#  endif
#endif

#if defined(_MSC_VER)
#define strdup _strdup
#endif

#if SIZEOF_INT == 4
typedef int int4;
#endif
#if SIZEOF_SHORT == 2
typedef short int2;
#endif

typedef struct attr_union {
    union {
	double d;
	float f;
	int i;
	long l;
	void *p;
    }u;
} attr_union;

typedef struct attr {
    atom_t attr_id;
    attr_value_type val_type;
    attr_union value;
} attr, *attr_p;

typedef struct int_attr {
    int4 attr_id;
    int4 value;
} int_attr;

typedef struct int_attr_struct {
    unsigned char byte_order;
    unsigned char int_attr_count;
    unsigned char other_attr_count;
    unsigned char junk;
    int_attr iattr[1];
} *int_attr_p;

typedef struct _attr_sublist_struct {
    attr_p attributes;
    struct int_attr_struct *iattrs;
} attr_sublist_struct;

typedef struct _attr_list_of_lists_struct {
    int sublist_count;
    attr_list *lists;
} attr_list_of_lists_struct;

/* opaque type for attr_lists */
typedef struct _attr_list_struct {
    short list_of_lists;
    short ref_count;
    union {
        attr_list_of_lists_struct lists;
        attr_sublist_struct list;
    } l;
} attr_list_struct;

static char * base64_encode ARGS((char *binStr, unsigned int len));
static int base64_decode ARGS((unsigned char *input, unsigned char *output));

atom_server global_as = NULL;
static int use_base64_string_encoding = 1;

#ifdef MODULE
char * atl_getenv(const char *);
int    atl_setenv(const char *, const char *, int);
char * atl_strdup(char *);
#define cercs_getenv(x) atl_getenv(x)
#define getenv atl_getenv
#define strdup  atl_strdup
#endif

int
get_pattr(attr_list list,int index, atom_t *name,
	  attr_value_type *val_type, attr_union *value);

extern int 
set_pattr(attr_list list, atom_t attr_id, attr_value_type val_type,
	  attr_union value);
extern int
replace_pattr(attr_list list, atom_t attr_id, attr_value_type val_type,
	      attr_union value);
extern int
add_pattr(attr_list list, atom_t attr_id, attr_value_type val_type, 
	  attr_union value);

static
void
init_global_atom_server(asp)
atom_server *asp;
{
    char *addr_str = NULL;
    char var_str[60];
    char *base64;

    if ((base64 = cercs_getenv("ATL_BASE64_STRINGS")) != NULL) {
        use_base64_string_encoding = strtol(base64, NULL, 10);
    }
    if (*asp != NULL) return;
    /*
     * for notes on my we're doing funny things with the "global" value, 
     * global_as, see the comments in gen_info.c.  This is similar.
     */
    sprintf(var_str, "ATOM_SERVER_ADDRESS_%lx", (long) getpid());
#ifndef HAVE_WINDOWS_H
    addr_str = getenv(var_str);
#else
    { 
	int ret;
	char buffer[60];
	ret = GetEnvironmentVariable(var_str, &buffer[0], sizeof(buffer));
	if (ret != 0) {
	    strcpy(var_str, &buffer[0]);
	    addr_str = &var_str[0];
	}
    }
#endif
    if (addr_str == NULL) {
	char addr_tmp[64];
#ifndef MODULE
	int value;
#endif
	*asp = init_atom_server(prefill_atom_cache);
#ifndef HAVE_WINDOWS_H
#ifdef MODULE
	sprintf(addr_tmp, "%lx", (long)*asp);
	addr_str = strdup(addr_tmp);
	atl_setenv(var_str, addr_str, 1);
#else
	sprintf(addr_tmp, "%s=%lx", var_str, (long)*asp);
	addr_str = strdup(addr_tmp);
	value = putenv(addr_str);
	if (value != 0) perror("putenv failed\n");
#endif
#else
	sprintf(addr_tmp, "%lx", (long)*asp);
	addr_str = strdup(addr_tmp);
	value = SetEnvironmentVariable(var_str, addr_str);
#endif
    } else {
        *(long*)asp = strtol((char *)addr_str, NULL, 16); 
    }
}

attr_list
attr_copy_list(attr_list orig)
{
    attr_list list = malloc(sizeof(attr_list_struct));
    memcpy(list, orig, sizeof(attr_list_struct));
    if (orig->l.list.iattrs->int_attr_count != 0) {
	int iattr_count = orig->l.list.iattrs->int_attr_count;
	list->l.list.iattrs = malloc(sizeof(struct int_attr_struct) +
				     (iattr_count -1) * sizeof(int_attr));
	memcpy(list->l.list.iattrs, orig->l.list.iattrs, 
	       sizeof(struct int_attr_struct) +
	       (iattr_count -1) * sizeof(int_attr));
    }
    if (orig->l.list.iattrs->other_attr_count != 0) {
	int i;
	attr *a, *b;
	int oattr_count = orig->l.list.iattrs->other_attr_count;
	a = list->l.list.attributes = malloc(oattr_count * sizeof(attr));
	b = orig->l.list.attributes;
	memcpy(a, b, oattr_count * sizeof(attr));
	for (i=0; i < oattr_count; i++) {
	    if (a[i].val_type == Attr_String) {
		char *s = strdup((char *) b[i].value.u.p);
		a[i].value.u.p = s;
	    }
	}
    }
    return list;
}

#ifndef WORDS_BIGENDIAN
#define WORDS_BIGENDIAN 0
#endif

/* operations on attr_lists */
static attr_list
internal_create_attr_list(int iattr_count, int oattr_count)
{
    attr_list list = malloc(sizeof(attr_list_struct));

    list->list_of_lists = 0;
    list->ref_count = 1;
    if (oattr_count == 0) {
	list->l.list.attributes = NULL;
    } else {
	list->l.list.attributes = malloc(oattr_count * sizeof(attr));
    }
    if (iattr_count == 0) {
	list->l.list.iattrs = malloc(sizeof(struct int_attr_struct));
    } else {
	list->l.list.iattrs = malloc(sizeof(struct int_attr_struct) +
				     (iattr_count -1) * sizeof(int_attr));
    }
    list->l.list.iattrs->other_attr_count = oattr_count;
    list->l.list.iattrs->int_attr_count = iattr_count;
    list->l.list.iattrs->byte_order = WORDS_BIGENDIAN;
    list->l.list.iattrs->junk = 0;
    return list;  
}

extern attr_list
create_attr_list()
{
    init_global_atom_server(&global_as);
    return internal_create_attr_list(0, 0);
}

extern attr_list
add_ref_attr_list(list)
attr_list list;
{
    if(list) {
	list->ref_count++;
    }
    return list;
}

extern int
attr_list_ref_count(list)
attr_list list;
{
    return (list->ref_count);
}

/* operations on attr_lists */
extern attr_list
attr_join_lists(list1, list2)
attr_list list1;
attr_list list2;
{
    attr_list list;

    if (list2 == NULL) {
        list1->ref_count++;
        return list1;
    }
    list = malloc(sizeof(attr_list_struct));

    init_global_atom_server(&global_as);
    list->list_of_lists = 1;
    list->ref_count = 1;
    list->l.lists.lists = (attr_list *)malloc(sizeof(attr_list) *2);
    list->l.lists.sublist_count = 2;
    list->l.lists.lists[0] = list1;
    list1->ref_count++;
    list->l.lists.lists[1] = list2;
    list2->ref_count++;
    return list;     
}

extern attr_list
attr_add_list(list1, list2)
attr_list list1;
attr_list list2;
{
    init_global_atom_server(&global_as);
    if (list1->list_of_lists == 0) {
        return attr_join_lists(list1, list2);
    }
    list1->l.lists.lists =
           (attr_list *)realloc(list1->l.lists.lists, sizeof(attr_list) *
                                (list1->l.lists.sublist_count+1));
    list1->l.lists.lists[list1->l.lists.sublist_count] = list2;
    list2->ref_count++;
    list1->l.lists.sublist_count += 1;
    return list1;   
}

/* 
 *  merges list2 into list1.  modifies list1, does not modify list2
 */
extern void
attr_merge_lists(list1, list2)
attr_list list1;
attr_list list2;
{
    attr attr_guy;
    int i;
    int c = attr_count(list2);
    /* need to make this more efficient */

    for (i = 0; i < c; i++) {
	get_pattr(list2, i, &attr_guy.attr_id, &attr_guy.val_type,
		  &attr_guy.value);
	if (attr_guy.val_type == Attr_String) {
	    char *s = strdup((char *) attr_guy.value.u.p);
	    set_string_attr(list1, attr_guy.attr_id, s);
	} else {
	    set_pattr(list1, attr_guy.attr_id, attr_guy.val_type, attr_guy.value);
	}
    }
}


extern int
add_double_attr(list, attr_id, dvalue)
attr_list list;
atom_t attr_id;
double dvalue;
{
    attr_value_type t = Attr_Float4;
    attr_union tmp;
    tmp.u.d = dvalue;
    if (sizeof(double) == 8) t = Attr_Float8;
    if (sizeof(double) == 16) t = Attr_Float16;
    return add_pattr(list, attr_id, t, tmp);
}

extern int
add_float_attr(list, attr_id, fvalue)
attr_list list;
atom_t attr_id;
double fvalue;
{
    attr_value_type t = Attr_Float4;
    attr_union tmp;
    tmp.u.f = fvalue;
    if (sizeof(float) == 8) t = Attr_Float8;
    if (sizeof(float) == 16) t = Attr_Float16;
    return add_pattr(list, attr_id, t, tmp);
}

extern int
add_long_attr(list, attr_id, lvalue)
attr_list list;
atom_t attr_id;
long lvalue;
{
    attr_value_type t = Attr_Int4;
    attr_union tmp;
    tmp.u.l = lvalue;
    if (sizeof(long) == 8) t = Attr_Int8;
    return add_pattr(list, attr_id, t, tmp);
}

extern int
add_int_attr(list, attr_id, ivalue)
attr_list list;
atom_t attr_id;
int ivalue;
{
    attr_value_type t = Attr_Int4;
    attr_union tmp;
    tmp.u.i = ivalue;
    if (sizeof(int) == 8) t = Attr_Int8;
    return add_pattr(list, attr_id, t, tmp);
}

extern int
add_string_attr(list, attr_id, ivalue)
attr_list list;
atom_t attr_id;
char *ivalue;
{
    attr_value_type t = Attr_String;
    attr_union tmp;
    tmp.u.p = ivalue;
    return add_pattr(list, attr_id, t, tmp);
}

extern int
set_double_attr(list, attr_id, dvalue)
attr_list list;
atom_t attr_id;
double dvalue;
{
    attr_value_type t = Attr_Float4;
    attr_union tmp;
    tmp.u.d = dvalue;
    if (sizeof(double) == 8) t = Attr_Float8;
    if (sizeof(double) == 16) t = Attr_Float16;
    return set_pattr(list, attr_id, t, tmp);
}

extern int
set_float_attr(list, attr_id, fvalue)
attr_list list;
atom_t attr_id;
double fvalue;
{
    attr_value_type t = Attr_Float4;
    attr_union tmp;
    tmp.u.f = fvalue;
    if (sizeof(float) == 8) t = Attr_Float8;
    if (sizeof(float) == 16) t = Attr_Float16;
    return set_pattr(list, attr_id, t, tmp);
}

extern int
set_long_attr(list, attr_id, lvalue)
attr_list list;
atom_t attr_id;
long lvalue;
{
    attr_value_type t = Attr_Int4;
    attr_union tmp;
    tmp.u.l = lvalue;
    if (sizeof(long) == 8) t = Attr_Int8;
    return set_pattr(list, attr_id, t, tmp);
}

extern int
set_int_attr(list, attr_id, ivalue)
attr_list list;
atom_t attr_id;
int ivalue;
{
    attr_value_type t = Attr_Int4;
    attr_union tmp;
    tmp.u.l = 0;
    tmp.u.i = ivalue;
    if (sizeof(int) == 8) t = Attr_Int8;
    return set_pattr(list, attr_id, t, tmp);
}

extern int
replace_double_attr(list, attr_id, dvalue)
attr_list list;
atom_t attr_id;
double dvalue;
{
    attr_value_type t = Attr_Float4;
    attr_union tmp;
    tmp.u.d = dvalue;
    if (sizeof(float) == 8) t = Attr_Float8;
    if (sizeof(float) == 16) t = Attr_Float16;
    return replace_pattr(list, attr_id, t, tmp);
}

extern int
replace_float_attr(list, attr_id, fvalue)
attr_list list;
atom_t attr_id;
double fvalue;
{
    attr_value_type t = Attr_Float4;
    attr_union tmp;
    tmp.u.f = fvalue;
    if (sizeof(float) == 8) t = Attr_Float8;
    if (sizeof(float) == 16) t = Attr_Float16;
    return replace_pattr(list, attr_id, t, tmp);
}

extern int
replace_long_attr(list, attr_id, lvalue)
attr_list list;
atom_t attr_id;
long lvalue;
{
    attr_value_type t = Attr_Int4;
    attr_union tmp;
    tmp.u.l = lvalue;
    if (sizeof(long) == 8) t = Attr_Int8;
    return replace_pattr(list, attr_id, t, tmp);
}

extern int
replace_int_attr(list, attr_id, ivalue)
attr_list list;
atom_t attr_id;
int ivalue;
{
    attr_value_type t = Attr_Int4;
    attr_union tmp;
    tmp.u.i = ivalue;
    if (sizeof(int) == 8) t = Attr_Int8;
    return replace_pattr(list, attr_id, t, tmp);
}

extern int
add_pattr(list, attr_id, val_type, value)
attr_list list;
atom_t attr_id;
attr_value_type val_type;
attr_union value;
{
    int i;
    if (val_type == Attr_Int4) {
	int count = list->l.list.iattrs->int_attr_count;
	if (count > 0) {
	    int size = sizeof(struct int_attr_struct) + 
		(count+1)* sizeof(int_attr);
	    list->l.list.iattrs = realloc(list->l.list.iattrs, size);
	}
	
	for (i = count - 1; i >= 0; i--) {
	    if (list->l.list.iattrs->iattr[i].attr_id > attr_id) {
		list->l.list.iattrs->iattr[i+1].attr_id = list->l.list.iattrs->iattr[i].attr_id;
		list->l.list.iattrs->iattr[i+1].value = list->l.list.iattrs->iattr[i].value;
	    } else {
		break;
	    }
	}
	
	list->l.list.iattrs->iattr[i+1].attr_id = attr_id;
	list->l.list.iattrs->iattr[i+1].value = (int4) (long) value.u.i;
	list->l.list.iattrs->int_attr_count++;
    } else {
	int count = list->l.list.iattrs->other_attr_count;
	if (count == 0) {
	    list->l.list.attributes = (attr_p) malloc(sizeof(attr));
	} else {	    
	    list->l.list.attributes = (attr_p) realloc(list->l.list.attributes,
						       sizeof(attr)*(count+1));
	}
	
	for (i = count - 1; i >= 0; i--) {
	    if (list->l.list.attributes[i].attr_id > attr_id) {
		list->l.list.attributes[i+1].attr_id = list->l.list.attributes[i].attr_id;
		list->l.list.attributes[i+1].val_type = list->l.list.attributes[i].val_type;
		list->l.list.attributes[i+1].value = list->l.list.attributes[i].value;
	    } else {
		break;
	    }
	}
	
	list->l.list.attributes[i+1].attr_id = attr_id;
	list->l.list.attributes[i+1].val_type = val_type;
	list->l.list.attributes[i+1].value = value;
	list->l.list.iattrs->other_attr_count++;
    }
    return 1;
}

extern int
add_attr(list, attr_id, val_type, val)
attr_list list;
atom_t attr_id;
attr_value_type val_type;
attr_value val;
{
    int i;
    attr_union value;
    switch(val_type) {
    case Attr_Int8:
	if (sizeof(long) == 8) {
	    value.u.l = (long) val;
	}
    case Attr_Int4:
    case Attr_Atom:
      if (sizeof(int) == 4) {
	  value.u.i = (long)val;
      }
      break;
    case Attr_Float16:
	if (sizeof(double) == 16) {
	    value.u.d = *(double*)&val;
	    break;
	}
    case Attr_Float8:
	if (sizeof(double) == 8) {
	    value.u.d = *(double*)&val;
	    break;
	} else if (sizeof(float) == 8) {
	    value.u.f = *(float*)&val;
	    break;
	}
    case Attr_Float4:
	if (sizeof(double) == 4) {
	    value.u.d = *(double*)&val;
	    break;
	} else if (sizeof(float) == 4) {
	    value.u.f = *(float*)&val;
	    break;
	}
	break;
    case Attr_String:
    case Attr_Opaque:
    case Attr_List:
	value.u.p = val;
	break;
    case Attr_Undefined:
	break;
    }
    if (val_type == Attr_Int4) {
	int count = list->l.list.iattrs->int_attr_count;
	if (count > 0) {
	    int size = sizeof(struct int_attr_struct) + 
		(count+1)* sizeof(int_attr);
	    list->l.list.iattrs = realloc(list->l.list.iattrs, size);
	}
	
	for (i = count - 1; i >= 0; i--) {
	    if (list->l.list.iattrs->iattr[i].attr_id > attr_id) {
		list->l.list.iattrs->iattr[i+1].attr_id = list->l.list.iattrs->iattr[i].attr_id;
		list->l.list.iattrs->iattr[i+1].value = list->l.list.iattrs->iattr[i].value;
	    } else {
		break;
	    }
	}
	
	list->l.list.iattrs->iattr[i+1].attr_id = attr_id;
	list->l.list.iattrs->iattr[i+1].value = (int4) (long) val;
	list->l.list.iattrs->int_attr_count++;
    } else {
	int count = list->l.list.iattrs->other_attr_count;
	if (count == 0) {
	    list->l.list.attributes = (attr_p) malloc(sizeof(attr));
	} else {	    
	    list->l.list.attributes = (attr_p) realloc(list->l.list.attributes,
						       sizeof(attr)*(count+1));
	}
	
	for (i = count - 1; i >= 0; i--) {
	    if (list->l.list.attributes[i].attr_id > attr_id) {
		list->l.list.attributes[i+1].attr_id = list->l.list.attributes[i].attr_id;
		list->l.list.attributes[i+1].val_type = list->l.list.attributes[i].val_type;
		list->l.list.attributes[i+1].value = list->l.list.attributes[i].value;
	    } else {
		break;
	    }
	}
	
	list->l.list.attributes[i+1].attr_id = attr_id;
	list->l.list.attributes[i+1].val_type = val_type;
	list->l.list.attributes[i+1].value = value;
	list->l.list.iattrs->other_attr_count++;
    }
    return 1;
}

extern int 
set_attr(list, attr_id, val_type, value)
attr_list list;
atom_t attr_id;
attr_value_type val_type;
attr_value value;
{
    if (replace_attr(list, attr_id, val_type, value) == 0) {
	return add_attr(list, attr_id, val_type, value);
    }
    return 1;
}

extern int 
set_pattr(list, attr_id, val_type, value)
attr_list list;
atom_t attr_id;
attr_value_type val_type;
attr_union value;
{
    if (replace_pattr(list, attr_id, val_type, value) == 0) {
	return add_pattr(list, attr_id, val_type, value);
    }
    return 1;
}

extern int 
set_string_attr(list, attr_id, string)
attr_list list;
atom_t attr_id;
char *string;
{
    attr_union value;
    value.u.p = string;
    if (replace_pattr(list, attr_id, Attr_String, value) == 0) {
	return add_pattr(list, attr_id, Attr_String, value);
    }
    return 1;
}

extern int
replace_attr(list, attr_id, val_type, val)
attr_list list;
atom_t attr_id;
attr_value_type val_type;
attr_value val;
{
    int index = 0;
  attr_union value;
    assert(list->list_of_lists == 0);
  switch(val_type) {
  case Attr_Int8:
      if (sizeof(long) == 8) {
	  value.u.l = (long) val;
      }
  case Attr_Int4:
  case Attr_Atom:
      if (sizeof(int) == 4) {
	  value.u.i = (long)val;
      }
      break;
  case Attr_Float16:
      if (sizeof(double) == 16) {
	  value.u.d = *(double*)&val;
	  break;
      }
  case Attr_Float8:
      if (sizeof(double) == 8) {
	  value.u.d = *(double*)&val;
	  break;
      } else if (sizeof(float) == 8) {
	  value.u.f = *(float*)&val;
	  break;
      }
  case Attr_Float4:
      if (sizeof(double) == 4) {
	  value.u.d = *(double*)&val;
	  break;
      } else if (sizeof(float) == 4) {
	  value.u.f = *(float*)&val;
	  break;
      }
      break;
  case Attr_String:
  case Attr_Opaque:
  case Attr_List:
      value.u.p = val;
      break;
  case Attr_Undefined:
      break;
  }
    if (val_type == Attr_Int4) {
	while (index < list->l.list.iattrs->int_attr_count) {
	    if (list->l.list.iattrs->iattr[index].attr_id == attr_id) {
		list->l.list.iattrs->iattr[index].value = value.u.i;
		return 1;
	    }
	    index++;
	}
    } else {
	while (index < list->l.list.iattrs->other_attr_count) {
	    if (list->l.list.attributes[index].attr_id == attr_id) {
		list->l.list.attributes[index].val_type = val_type;
		list->l.list.attributes[index].value = value;
		return 1;
	    }
	    index++;
	}
    }
    return 0;  
}

extern int
replace_pattr(list, attr_id, val_type, value)
attr_list list;
atom_t attr_id;
attr_value_type val_type;
attr_union value;
{
    int index = 0;
    assert(list->list_of_lists == 0);
    if (val_type == Attr_Int4) {
	while (index < list->l.list.iattrs->int_attr_count) {
	    if (list->l.list.iattrs->iattr[index].attr_id == attr_id) {
		list->l.list.iattrs->iattr[index].value = (int4)(long)value.u.i;
		return 1;
	    }
	    index++;
	}
    } else {
	while (index < list->l.list.iattrs->other_attr_count) {
	    if (list->l.list.attributes[index].attr_id == attr_id) {
		list->l.list.attributes[index].val_type = val_type;
		list->l.list.attributes[index].value = value;
		return 1;
	    }
	    index++;
	}
    }
    return 0;  
}

extern int
query_attr(list, attr_id, val_type_p, value_p)
attr_list list;
atom_t attr_id;
attr_value_type *val_type_p;
attr_value *value_p;
{
    if (list == NULL) return 0;
    if (list->list_of_lists) {
        int i;
        for (i=0; i< list->l.lists.sublist_count; i++) {
            if (query_attr(list->l.lists.lists[i], attr_id, val_type_p,
                           value_p)) {
                return 1;
            }
        }
        return 0;
    } else {
	int index = 0;
	while(index < list->l.list.iattrs->int_attr_count) {
	    if (list->l.list.iattrs->iattr[index].attr_id == attr_id) {
		if (val_type_p != NULL) {
		    *val_type_p = Attr_Int4;
		}
		if (value_p != NULL) {
		    if (sizeof(long) != 4){
			*((int*)value_p) = (int)(long)list->l.list.iattrs->iattr[index].value;
		    } else {
			*((int*)value_p) = list->l.list.iattrs->iattr[index].value;
		    }
		}
		return 1;
	    }
	    index++;
        }
	index = 0;
	while(index < list->l.list.iattrs->other_attr_count) {
	    if (list->l.list.attributes[index].attr_id == attr_id) {
		if (val_type_p != NULL) {
		    *val_type_p = list->l.list.attributes[index].val_type;
		}
		if (value_p != NULL) {
		    if ((sizeof(long) != 4) &&
			(list->l.list.attributes[index].val_type == Attr_Int4)){
			*((int*)value_p) = (int)(long)list->l.list.attributes[index].value.u.i;
		    } else {
			*value_p = (void*)list->l.list.attributes[index].value.u.l;
		    }
		}
		return 1;
	    }
	    index++;
        }
        return 0;
    }                 
}
extern int
query_pattr(list, attr_id, val_type_p, value_p)
attr_list list;
atom_t attr_id;
attr_value_type *val_type_p;
attr_union *value_p;
{
    if (list == NULL) return 0;
    if (list->list_of_lists) {
        int i;
        for (i=0; i< list->l.lists.sublist_count; i++) {
            if (query_pattr(list->l.lists.lists[i], attr_id, val_type_p,
                           value_p)) {
                return 1;
            }
        }
        return 0;
    } else {
	int index = 0;
	while(index < list->l.list.iattrs->int_attr_count) {
	    if (list->l.list.iattrs->iattr[index].attr_id == attr_id) {
		if (val_type_p != NULL) {
		    *val_type_p = Attr_Int4;
		}
		if (value_p != NULL) {
		    if (sizeof(long) != 4){
			value_p->u.i = (int)(long)list->l.list.iattrs->iattr[index].value;
		    } else {
			value_p->u.l = list->l.list.iattrs->iattr[index].value;
		    }
		}
		return 1;
	    }
	    index++;
        }
	index = 0;
	while(index < list->l.list.iattrs->other_attr_count) {
	    if (list->l.list.attributes[index].attr_id == attr_id) {
		if (val_type_p != NULL) {
		    *val_type_p = list->l.list.attributes[index].val_type;
		}
		if (value_p != NULL) {
		    *value_p = list->l.list.attributes[index].value;
		}
		return 1;
	    }
	    index++;
        }
        return 0;
    }
}

static void
internal_dump_attr_list ARGS((attr_list list, int indent));

static void
dump_attr_sublist(list, indent)
attr_list list;
int indent;
{
    int i;
    init_global_atom_server(&global_as);
    if (list == NULL) {
        printf("[NULL]\n");
        return;
    }
    for (i = 0; i < list->l.list.iattrs->int_attr_count; i++) {
	int attr_id = list->l.list.iattrs->iattr[i].attr_id;
	char c[15];
        char *attr_name = string_from_atom(global_as, attr_id), *print_name;
        int j;
	memcpy(&c[0], &attr_id, 4);
	c[4] = 0;
	print_name = attr_name;
        if (attr_name == NULL)
            print_name = "<null attr name>";
        for (j = 0; j < indent; j++) {
            printf("    ");
        }
	if ((attr_id == ATL_CHAR_CONS('C','P','I','P')) || 
	    (attr_id == ATL_CHAR_CONS('C','I','P','A'))) {
	    /* builts we want to format differently */
	    unsigned int ip = list->l.list.iattrs->iattr[i].value;
	    printf("    { %s ('%c%c%c%c'), Attr_Int4, %d.%d.%d.%d }\n", print_name,
		   c[0], c[1], c[2], c[3],
		   ((ip & 0xff000000) >> 24), ((ip & 0x00ff0000) >> 16), 
		   ((ip & 0x0000ff00) >> 8), (ip & 0x000000ff));
	} else {
	    char *print_id = &c[0];
	    if ((!isprint((int)c[0])) || (!isprint((int)c[1])) || (!isprint((int)c[2])) || 
		(!isprint((int)c[3]))) {
		sprintf(print_id, "0x%x", attr_id);
	    }
	    printf("    { %s ('%s'), Attr_Int4, %ld }\n", print_name,
		   print_id, (long) list->l.list.iattrs->iattr[i].value);
	}
	if (attr_name) free(attr_name);
    }
	
    for (i = 0; i < list->l.list.iattrs->other_attr_count; i++) {
	int attr_id = list->l.list.attributes[i].attr_id;
	char c[15];
	char *attr_name = string_from_atom(global_as, attr_id);
        char *print_name;
        int j;
	char *print_id = &c[0];
	print_name = attr_name;
	memcpy(&c[0], &attr_id, 4);
	c[4] = 0;
	if (!isprint((int)c[0]) || !isprint((int)c[1]) || !isprint((int)c[2]) || !isprint((int)c[3])) {
	    sprintf(print_id, "0x%x", attr_id);
	}
        if (attr_name == NULL)
            print_name = "<null attr name>";
        for (j = 0; j < indent; j++) {
            printf("    ");
        }
        switch (list->l.list.attributes[i].val_type) {
        case Attr_Undefined:
            printf("    { %s ('%s'), Undefined, Undefined }\n", 
		   print_name, print_id);
            break;
        case Attr_Int4:
	    assert(0);
            break;
        case Attr_Int8:
            printf("    { %s ('%s'), Attr_Int8, %ld }\n", print_name,
		   print_id,
                   (long) list->l.list.attributes[i].value.u.l);
            break;
        case Attr_Float16:
            printf("    { %s ('%s'), Attr_Float8, %g }\n", print_name,
		   print_id,
                   list->l.list.attributes[i].value.u.d);
            break;
        case Attr_Float8:
            printf("    { %s ('%s'), Attr_Float8, %g }\n", print_name,
		   print_id,
                   list->l.list.attributes[i].value.u.d);
            break;
        case Attr_Float4:
            printf("    { %s ('%s'), Attr_Float8, %g }\n", print_name,
		   print_id,
                   list->l.list.attributes[i].value.u.d);
            break;
        case Attr_String:
            if (((char*)list->l.list.attributes[i].value.u.p) != NULL) {
                printf("    { %s ('%s'), Attr_String, %s }\n", 
		       print_name, print_id,
                       (char *) list->l.list.attributes[i].value.u.p);
            } else {
                printf("    { %s ('%s'), Attr_String, NULL }\n", 
		       print_name, print_id);
            }
            break;          
        case Attr_Opaque:
            if (((char*)list->l.list.attributes[i].value.u.p) != NULL) {
                int j;
                attr_opaque_p o =
                    (attr_opaque_p) list->l.list.attributes[i].value.u.p;
                printf("    { %s ('%s'), Attr_Opaque, \"", 
		       print_name, print_id);
                for (j=0; j< o->length; j++) {
                    printf("%c", ((char*)o->buffer)[j]);
                }
                printf("\"\n            <");
                for (j=0; j< o->length; j++) {
                    printf(" %02x", ((unsigned char*)o->buffer)[j]);
                }
                printf(">}\n");
            } else {
                printf("    { %s ('%s'), Attr_Opaque, NULL }\n", 
		       print_name, print_id);
            }
            break;
        case Attr_Atom: {
	    int atom_val = (atom_t)(long)list->l.list.attributes[i].value.u.i;
	    char *cv = (char*)&atom_val;
	    char *atom_str, *print_str;
            print_str = atom_str = string_from_atom(global_as, atom_val);
	    if (atom_str == NULL)
		print_str = "<null attr name>";
            printf("    { %s ('%s'), Attr_Atom, %s ('%c%c%c%c') }\n", 
		   print_name, print_id,
                   (char *) print_str, cv[0], cv[1], cv[2], cv[3]);
	    if (atom_str) free(atom_str);
            break;
	}
        case Attr_List:
            printf("    { %s ('%s'), Attr_List, ->\n", print_name,
		   print_id);
            internal_dump_attr_list((attr_list) list->l.list.attributes[i].value.u.p,
                                    indent+1);
            for (j = 0; j< indent; j++) {
                printf("    ");
            }
            printf(" }\n");
            break;
        }
        if (attr_name) free(attr_name);
    }
}

extern void
dump_attr_list(list)           
attr_list list;
{

    init_global_atom_server(&global_as);
    printf("Attribute list %p, ref_count = %d\n", list, list->ref_count);
    internal_dump_attr_list(list, 0);
}

/*
 * Return 1 when attr_id find was successful, else returns 0
 * The attr_id is placed in item
 */
extern int
get_attr_id(attr_list list, int item_no, atom_t *item)
{

    init_global_atom_server(&global_as);

    if (item_no < 0) return 0;

    if (list == NULL) return 0;

    if (!list->list_of_lists) {
        int int_attr_count = list->l.list.iattrs->int_attr_count;
        int other_attr_count = list->l.list.iattrs->int_attr_count;
        int total_attr_count = int_attr_count + other_attr_count;

        if (item_no >= total_attr_count) return 0;

        if (item_no < int_attr_count) {
            *item = list->l.list.iattrs->iattr[item_no].attr_id;
	    return 1;
        } else {
            item_no -= int_attr_count;
            *item = list->l.list.attributes[item_no].attr_id;
	    return 1;
        }
    } else {
        int i;
        for (i=0; i<list->l.lists.sublist_count; i++) {
            attr_list atl = list->l.lists.lists[i];
            int int_attr_count = atl->l.list.iattrs->int_attr_count;
            int other_attr_count = atl->l.list.iattrs->int_attr_count;
            int total_attr_count = int_attr_count + other_attr_count;

            if (item_no > total_attr_count) {
                item_no -= total_attr_count;
	    } else {
                if (item_no < int_attr_count) {
                    *item = atl->l.list.iattrs->iattr[item_no].attr_id;
		    return 1;
                } else {
                    item_no -= int_attr_count;
                    *item = atl->l.list.attributes[item_no].attr_id;
		    return 1;
                }
            }
        }
    }
    return 0;
}

static void
internal_dump_attr_list (list, indent)
attr_list list;
int indent;
{
    int i = 0;
    for (i = 0; i< indent; i++) {
        printf("    ");
    }
    if (list == NULL) {
        printf("[NULL]\n");
        return;
    }
    printf("[\n");
    if (!list->list_of_lists) {
        dump_attr_sublist(list, indent);
    } else {
        int i;
        for (i=0; i<list->l.lists.sublist_count; i++) {
            dump_attr_sublist(list->l.lists.lists[i], indent);
        }
    }
    for (i=0; i< indent; i++) {
        printf("    ");
    }
    printf("]\n");
}                   

static char*
strdqcat(str, size_p, str2)
char *str;
int *size_p;
char *str2;
{
    int str2_len = strlen(str2);
    str = realloc(str, *size_p + str2_len + 1);
    strcpy(str + *size_p, str2);
    (*size_p) += str2_len;
    return str;
}

static char*
strdcat(str, size_p, str2)
char *str;
int *size_p;
char *str2;
{
    return strdqcat(str, size_p, str2);
}

static const char xchars [] = "0123456789abcdef";

#define nibble2hex(val) (xchars[val & 0x0f])

static
unsigned char
hex2byte (char c)
{
    if (isdigit ((int)c))
	return (unsigned char) (c - '0');
    else if (islower ((int)c))
	return (unsigned char) (10 + c - 'a');
    else
	return (unsigned char) (10 + c - 'A');
}

#define roundup4(a) ((a + 3) & ~3)

static char *
add_list_to_string(str, size_p, list)
char *str;
int *size_p;
attr_list list;
{
    int i;
    init_global_atom_server(&global_as);
    
    for (i = 0; i < list->l.list.iattrs->int_attr_count; i++) {
        char str_tmp[128];
        char *atom_string;
        memset(str_tmp, 0, sizeof(str_tmp));
#ifdef SHARED_ATTR_NUMS
        sprintf(str_tmp, "{%d", tmp.attr_id);
#else
	
	atom_string =string_from_atom(global_as, 
				      list->l.list.iattrs->iattr[i].attr_id);
	if (atom_string == NULL) {
	    static int warned = 0;
	    if (warned == 0) {
		printf("Attribute has no name.  Set one with set_attr_string_and_atom();\n");
		printf("See http://www.cc.gatech.edu/systems/projects/CM/attributes.html\n");
		warned++;
	    }
	    atom_string = strdup("NO-NAME");
	}
	sprintf(str_tmp, "{%s", atom_string);
        free(atom_string);
#endif
        str = strdcat(str, size_p, str_tmp);
	sprintf(str_tmp, ",4,%d},", (int) (long)list->l.list.iattrs->iattr[i].value);
	str = strdcat(str, size_p, str_tmp);
    }
	
    for (i = 0; i < list->l.list.iattrs->other_attr_count; i++) {
        attr_p tmp;
        char str_tmp[128];
        char *atom_string;
	tmp = &list->l.list.attributes[i];

        memset(str_tmp, 0, sizeof(str_tmp));
        if (tmp->val_type == Attr_List) continue;
#ifdef SHARED_ATTR_NUMS
        sprintf(str_tmp, "{%d", tmp->attr_id);
#else
	atom_string = string_from_atom(global_as, tmp->attr_id);
	if (atom_string == NULL) {
	    static int warned = 0;
	    if (warned == 0) {
		printf("Attribute has no name.  Set one with set_attr_string_and_atom();\n");
		printf("See http://www.cc.gatech.edu/systems/projects/CM/attributes.html\n");
		warned++;
	    }
	    atom_string = strdup("NO-NAME");
	}
        sprintf(str_tmp, "{%s", atom_string);
        free(atom_string);
#endif
        str = strdcat(str, size_p, str_tmp);
        switch(tmp->val_type) {
        case Attr_Undefined:
            str = strdcat(str, size_p, ",U,");
            break;
        case Attr_Int4:
	    assert(0);
            break;
        case Attr_Int8:
            sprintf(str_tmp, ",8,%ld", (long) tmp->value.u.l);
            str = strdcat(str, size_p, str_tmp);
            break;
        case Attr_String:
            {
                char tmp_str[24];
                sprintf(tmp_str, ",S%d,", (int)strlen(tmp->value.u.p));
                str = strdcat(str, size_p, tmp_str);
                str = strdcat(str, size_p, (char*)tmp->value.u.p);
            }
            break;
        case Attr_Opaque: {
            attr_opaque_p o = (attr_opaque_p) tmp->value.u.p;
           if (o == NULL) {
                str = strdcat(str, size_p, ",O0,");
            } else {
                char tmp3[3];
                int i;
                sprintf(str_tmp, ",O%d,", o->length);
                str = strdcat(str, size_p, str_tmp);
                tmp3[2] = 0;
                for (i=0; i<o->length; i++) {
                    tmp3[0] = nibble2hex(((char*)o->buffer)[i] >> 4);
                    tmp3[1] = nibble2hex(((char*)o->buffer)[i]);
                    str = strdcat(str, size_p, tmp3);
                }
            }
            break;
        }
        case Attr_Atom:
            sprintf(str_tmp, ",A,%d", (int) (long)tmp->value.u.i);
            str = strdcat(str, size_p, str_tmp);
            break;
        case Attr_List:
        default:
            assert(0);
        }
        str = strdqcat(str, size_p, "},");
    }
    return str;
}                 

static int
add_list_from_string(str, list)
const char *str;
attr_list list;
{
    while (1) {
	char *first_comma = strchr(str, ',');
	char *value = first_comma ? strchr(first_comma+1, ',') : NULL;
	char *end = NULL;
	int attr_id, length;
	attr_value_type val_type = Attr_Undefined;
	attr_value val = 0;
	long long_value;

	if (*str == 0) return 1;   /* success */
	if (value == NULL) return 0;
#ifdef SHARED_ATTR_NUMS
	if (sscanf(str, "{%d,", &attr_id) != 1) return 0;
#else
	
	{ 
	    int len = first_comma - str - 1;
	    char * atom_name = malloc(len + 1);
	    strncpy(atom_name, (str+1), len);
	    atom_name[len] = 0;
	    attr_id = attr_atom_from_string(atom_name);
	    free(atom_name);
	}
#endif
	switch(*(first_comma+1)) {
	case 'U':
	    val_type = Attr_Undefined;
	    end = value + 2;
	    break;
	case '4':
	    val_type = Attr_Int4;
            val = (attr_value) (long) atoi(value+1);
            end = strchr(value+1, ',') + 1;
 	    if (end == (char*)1) end = value + strlen(value);
	    break;
	case '8':
	    val_type = Attr_Int8;
            long_value = atoi(value+1);
	    val = (attr_value)long_value;
	    end = strchr(value+1, ',') + 1;
	    if (end == (char*)1) end = value + strlen(value);
	    break;
	case 'A':
	    val_type = Attr_Atom;
	    val = (attr_value)(long)atoi(value+1);
	    end = strchr(value+1, ',') + 1;
	    if (end == (char*)1) end = value + strlen(value);
	    break;
	case 'S':
	    val_type = Attr_String;
	    length = atoi(first_comma+2);
	    end = value+1+length;
	    val = malloc(length+1);
	    strncpy(val, value+1, length);
	    ((char*)val)[length] = 0; /* terminate string */
	    end += 2;
	    break;
	case 'O': {
	    int len;
	    len = atoi(first_comma+2);
	    while (*value != ',') value++; /* skip to start of buffer */
	    value++;
	    val_type = Attr_Opaque;
	    if (len == 0) {
		val = (attr_value) NULL;
	    } else {
		attr_opaque_p o = malloc(sizeof(attr_opaque));
		int i;
		val = (attr_value)o;
		o->length = len;
		o->buffer = malloc(len);
		for (i=0 ; i < len; i++) {
		    unsigned char	byte;
		    byte = (unsigned char) (hex2byte (value[0]) << 4);
		    byte |= hex2byte (value [1]);
		    ((char*)o->buffer)[i] = byte;
		    value += 2;
		}
	    }
	    end = value + 2;
	    break;
	}    
	default:
	    assert(0);
	}
	add_attr(list, attr_id, val_type, val);
	str = end;
    }
}

extern
char *
attr_list_to_string(attrs)
attr_list attrs;
{
    int size = 0;
    if (attrs == NULL) return NULL;
    if (use_base64_string_encoding) {
	char * result;
	void *encoded;
	int len;
	AttrBuffer tmp = create_AttrBuffer();

	encoded = encode_attr_for_xmit(attrs, tmp, &len);
	result = base64_encode(encoded, len);
	free_AttrBuffer(tmp);
	return result;
    } else {
	return(add_list_to_string(malloc(1), &size, attrs));
    }
}

extern
attr_list
attr_list_from_string(str)
const char * str;
{
    if (str == NULL) return NULL;
    if ((*str == ' ') || (*str == '\t') || (*str == '{')) {
	attr_list ret_val = create_attr_list();
	if (add_list_from_string(str, ret_val) != 1) {
	    free_attr_list(ret_val);
	    return NULL;
	} 
	return ret_val;
    } else {
	attr_list ret_val;
	unsigned char *output = (unsigned char *)strdup(str);
	base64_decode((unsigned char *)str, output);
	ret_val = decode_attr_from_xmit(output);
	free(output);
	return ret_val;
    }
}

extern
 atom_t
attr_atom_from_string(str)
const char *str;
{
    init_global_atom_server(&global_as);
    return atom_from_string(global_as, (char*)str);
}

extern
char *
attr_string_from_atom(atom)
atom_t atom;
{
    init_global_atom_server(&global_as);
    return string_from_atom(global_as, atom);
}

extern
int 
attr_count(list)
attr_list list;
{
    if (list == NULL) return 0;
    if (!list->list_of_lists) {
        return list->l.list.iattrs->int_attr_count +
	    list->l.list.iattrs->other_attr_count;
    } else {
        int count = 0;
        int i;
        for (i=0; i<list->l.lists.sublist_count; i++) {
            count += attr_count(list->l.lists.lists[i]);
        }
        return count;
    }           
}


int
get_int_attr(attr_list l, atom_t attr_id, int *valp)
{
    attr_value_type t;
    attr_union v;
    int ret = query_pattr(l, attr_id, &t, &v);
    if (ret == 0) return 0;
    switch(t) {
    case Attr_Int4:
	if (sizeof(int) == 4) *valp = v.u.i;
	*valp = v.u.i;
	break;
    case Attr_Int8:
	if (sizeof(long) == 8) *valp = v.u.l;
	*valp = v.u.i;
	break;
    case Attr_Float16:
	if (sizeof(double) == 16) *valp = (int)v.u.d;
	if (sizeof(float) == 16) *valp = (int)v.u.f;
	break;
    case Attr_Float8:
	if (sizeof(double) == 8) *valp = (int)v.u.d;
	if (sizeof(float) == 8) *valp = (int)v.u.f;
	break;
    case Attr_Float4:
	if (sizeof(double) == 4) *valp = (int)v.u.d;
	if (sizeof(float) == 4) *valp = (int)v.u.f;
	break;
    default:
	return 0;
    }
    return 1;
}

int
get_long_attr(attr_list l, atom_t attr_id, long *valp)
{
    attr_value_type t;
    attr_union v;
    int ret = query_pattr(l, attr_id, &t, &v);
    if (ret == 0) return 0;
    switch(t) {
    case Attr_Int4:
	if (sizeof(int) == 4) *valp = v.u.i;
	*valp = v.u.i;
	break;
    case Attr_Int8:
	if (sizeof(long) == 8) *valp = v.u.l;
	*valp = v.u.i;
	break;
    case Attr_Float16:
	if (sizeof(double) == 16) *valp = (long)v.u.d;
	if (sizeof(float) == 16) *valp = (long)v.u.f;
	break;
    case Attr_Float8:
	if (sizeof(double) == 8) *valp = (long)v.u.d;
	if (sizeof(float) == 8) *valp = (long)v.u.f;
	break;
    case Attr_Float4:
	if (sizeof(double) == 4) *valp = (long)v.u.d;
	if (sizeof(float) == 4) *valp = (long)v.u.f;
	break;
    default:
	return 0;
    }
    return 1;
}

int
get_double_attr(attr_list l, atom_t attr_id, double *valp)
{
    attr_value_type t;
    attr_union v;
    int ret = query_pattr(l, attr_id, &t, &v);
    if (ret == 0) return 0;
    switch(t) {
    case Attr_Int4:
	if (sizeof(int) == 4) *valp = v.u.i;
	*valp = v.u.i;
	break;
    case Attr_Int8:
	if (sizeof(long) == 8) *valp = v.u.l;
	*valp = v.u.i;
	break;
    case Attr_Float16:
	if (sizeof(double) == 16) *valp = v.u.d;
	if (sizeof(float) == 16) *valp = v.u.f;
	break;
    case Attr_Float8:
	if (sizeof(double) == 8) *valp = v.u.d;
	if (sizeof(float) == 8) *valp = v.u.f;
	break;
    case Attr_Float4:
	if (sizeof(double) == 4) *valp = v.u.d;
	if (sizeof(float) == 4) *valp = v.u.f;
	break;
    default:
	return 0;
    }
    return 1;
}

int
get_float_attr(attr_list l, atom_t attr_id, float *valp)
{
    attr_value_type t;
    attr_union v;
    int ret = query_pattr(l, attr_id, &t, &v);
    if (ret == 0) return 0;
    switch(t) {
    case Attr_Int4:
	if (sizeof(int) == 4) *valp = (float)v.u.i;
	*valp = (float)v.u.i;
	break;
    case Attr_Int8:
	if (sizeof(long) == 8) *valp = (float)v.u.l;
	*valp = (float)v.u.i;
	break;
    case Attr_Float16:
	if (sizeof(double) == 16) *valp = (float)v.u.d;
	if (sizeof(float) == 16) *valp = v.u.f;
	break;
    case Attr_Float8:
	if (sizeof(double) == 8) *valp = (float)v.u.d;
	if (sizeof(float) == 8) *valp = v.u.f;
	break;
    case Attr_Float4:
	if (sizeof(double) == 4) *valp = (float)v.u.d;
	if (sizeof(float) == 4) *valp = v.u.f;
	break;
    default:
	return 0;
    }
    return 1;
}

int
get_string_attr(attr_list l, atom_t attr_id, char **valp)
{
    attr_value_type t;
    attr_union v;
    int ret = query_pattr(l, attr_id, &t, &v);
    if (ret == 0) return 0;
    switch(t) {
    case Attr_String:
	*valp = v.u.p;
	break;
    default:
	return 0;
    }
    return 1;
}

int
get_attr(attr_list list,int index, atom_t *name,
	  attr_value_type *val_type, attr_value *value)
{
    if (!list->list_of_lists) {
	if (index < list->l.list.iattrs->int_attr_count) {
	    *name = list->l.list.iattrs->iattr[index].attr_id;
	    *val_type = Attr_Int4;
	    *value = (attr_value) (long) list->l.list.iattrs->iattr[index].value;
	    return 1;
	}
	index -= list->l.list.iattrs->int_attr_count;
	if (index < list->l.list.iattrs->other_attr_count) {
	    *name = list->l.list.attributes[index].attr_id;
	    *val_type = list->l.list.attributes[index].val_type;
	    *value = (void*)list->l.list.attributes[index].value.u.l;
	    return 1;
	}
	return 0;
    } else {
        int i;
        for (i=0; i<list->l.lists.sublist_count; i++) {
            int count = attr_count(list->l.lists.lists[i]);
            if (index < count) {
                return get_attr(list->l.lists.lists[i], index, name, 
				val_type, value);
            } else {
                index -= count;
            }
        }
        return 0;
    }   
}

int
get_pattr(attr_list list,int index, atom_t *name,
	  attr_value_type *val_type, attr_union *value)
{
    if (!list->list_of_lists) {
	if (index < list->l.list.iattrs->int_attr_count) {
	    *name = list->l.list.iattrs->iattr[index].attr_id;
	    *val_type = Attr_Int4;
	    value->u.i = list->l.list.iattrs->iattr[index].value;
	    return 1;
	}
	index -= list->l.list.iattrs->int_attr_count;
	if (index < list->l.list.iattrs->other_attr_count) {
	    *name = list->l.list.attributes[index].attr_id;
	    *val_type = list->l.list.attributes[index].val_type;
	    *value = list->l.list.attributes[index].value;
	    return 1;
	}
	return 0;
    } else {
        int i;
        for (i=0; i<list->l.lists.sublist_count; i++) {
            int count = attr_count(list->l.lists.lists[i]);
            if (index < count) {
                return get_pattr(list->l.lists.lists[i], index, name, 
				val_type, value);
            } else {
                index -= count;
            }
        }
        return 0;
    }   
}

void
free_attr_list(list)
attr_list list;
{
    if (list == NULL) return;
    list->ref_count--;
    if (list->ref_count > 0) return;
    if (list->list_of_lists) {
        int i;
        for (i=0; i<list->l.lists.sublist_count; i++) {
            free_attr_list(list->l.lists.lists[i]);
        }
        free(list->l.lists.lists);
        free(list);
    } else {
        int i;
        for (i=0; i< list->l.list.iattrs->other_attr_count; i++) {
            switch (list->l.list.attributes[i].val_type) {
            case Attr_Undefined:
            case Attr_Int4:
            case Attr_Int8:
	    case Attr_Float16:
	    case Attr_Float8:
	    case Attr_Float4:
                break;
            case Attr_Atom:
                break;
            case Attr_String:
                free((char *)list->l.list.attributes[i].value.u.p);
                break;
            case Attr_Opaque: {
                attr_opaque_p o =
                    (attr_opaque_p) list->l.list.attributes[i].value.u.p;
                if (o) {
                    free(o->buffer);
                    free(o);
                }
                break;
            }
            case Attr_List:
                free_attr_list((attr_list)list->l.list.attributes[i].value.u.p);
                break;                  
            default:
                assert(0);
            }
        }
        if (list->l.list.attributes != NULL) {
            free(list->l.list.attributes);
        }
	if (list->l.list.iattrs != NULL) {
	    free(list->l.list.iattrs);
	    list->l.list.iattrs = NULL;
	}
        free(list);
    }      
}

#define ATTR_INT4_8_EQ(ap1,ap2) ((ap1)->value.u.l == (ap2)->value.u.l)
#define ATTR_ATOM_EQ(ap1,ap2) ((ap1)->value.u.i == (ap2)->value.u.i)
#define ATTR_STRING_EQ(ap1,ap2) \
  (strcmp ((char*)(ap1)->value.u.p, "*") == 0 \
  || strcmp ((char*)(ap2)->value.u.p, "*") == 0 \
  || strcmp ((char*)(ap1)->value.u.p, (char*)(ap2)->value.u.p) == 0)

extern
int
compare_attr_p_by_val (attr_p a1, attr_p a2)
{
  int eq = 0;
  
  if (a1 == a2)
    return 1;

  if (a1->val_type == a2->val_type)
    {
      if (a1->val_type == Attr_Int4 ||
	  a1->val_type == Attr_Int8)
	{
	  eq = ATTR_INT4_8_EQ(a1,a2);
	}
      else if (a1->val_type == Attr_String)
	{
	  eq = ATTR_STRING_EQ(a1,a2);
	}
      else if (a1->val_type == Attr_Atom)
	{
	  eq = ATTR_ATOM_EQ(a1,a2);
	}
      else if (a1->val_type == Attr_List)
	{
	  eq = attr_list_subset ((attr_list)a1->value.u.p,
				 (attr_list)a2->value.u.p);
	}
      else
	{
	  eq = 1;
	}

    }
  
  return eq;
}

extern
int
attr_list_subset (attr_list l1, attr_list l2)
{
  /*
   *  This function returns true if l1 is a subset of l2.  I
   *  define this as:  for each element of l1, there is an element
   *  of l2 with the same attribute name, attribute type, and attribute
   *  value.
   */
  int i, j, keep_going = 1;
  int l1_count;
  int l2_count;
  attr l1_tmp, l2_tmp;

  l1_count = attr_count (l1);
  l2_count = attr_count (l2);
  
  if (l2_count < l1_count) return 0;

  for (i = 0; i < l1_count && keep_going; i++)
    {
      int found = 0;
      get_pattr (l1, i, &l1_tmp.attr_id, &l1_tmp.val_type, &l1_tmp.value);

      for (j = 0; !found && j < l2_count; j++)
	{
	    get_pattr (l2, j, &l2_tmp.attr_id, &l2_tmp.val_type,
		      &l2_tmp.value);
	  
	  found = compare_attr_p_by_val (&l1_tmp, &l2_tmp);
	}

      keep_going = found;
    }

  return keep_going;
}
	
extern
void
set_string_and_atom(atom_server as, char *str, atom_t atom);

typedef struct Attr_tmp_buffer {
    void *tmp_buffer;
    int tmp_buffer_size;
    int tmp_buffer_in_use_size;
} Attr_tmp_buffer;

AttrBuffer
create_AttrBuffer()
{
    AttrBuffer buf = malloc(sizeof(Attr_tmp_buffer));
    buf->tmp_buffer = NULL;
    buf->tmp_buffer_size = 0;
    buf->tmp_buffer_in_use_size = 0;
    return buf;
}

void
free_AttrBuffer(buf)
AttrBuffer buf;
{
    if (buf->tmp_buffer)
	free(buf->tmp_buffer);
    free(buf);
}

#define TMP_BUFFER_INIT_SIZE 128

#define Max(i,j) ((i<j) ? j : i)

static
void *
add_to_tmp_buffer(buf, size)
AttrBuffer buf;
unsigned int size;
{
    int old_size = buf->tmp_buffer_in_use_size;
    size += old_size;

    if (buf->tmp_buffer_size == 0) {
	int tmp_size = Max(size, TMP_BUFFER_INIT_SIZE);
	buf->tmp_buffer = malloc(tmp_size * sizeof(char));
	if(buf->tmp_buffer) memset(buf->tmp_buffer, 0, tmp_size * sizeof(char));
    }
    if (size > buf->tmp_buffer_size) {
	buf->tmp_buffer = realloc(buf->tmp_buffer, size);
	memset (((char*)buf->tmp_buffer) + buf->tmp_buffer_size, 0, size - buf->tmp_buffer_size);
	buf->tmp_buffer_size = size;
    }
    if (!buf->tmp_buffer) {
	buf->tmp_buffer_size = 0;
    } else {
	buf->tmp_buffer_in_use_size = size;
    }

    return old_size + (char*)buf->tmp_buffer;
}

static void
recursive_encode(attr_list l, AttrBuffer b, attr_value_type t)
{
    if (l->list_of_lists == 0) {
	switch (t) {
	case Attr_Int4: {
	    /* marshalling only int4 attributes in this pass */
	    int attr_count = l->l.list.iattrs->int_attr_count;
	    void *buffer_end;
	    if (attr_count == 0) return;
	    buffer_end = add_to_tmp_buffer(b, (unsigned)(attr_count * 
					   sizeof(int_attr)));
	    memcpy(buffer_end, &l->l.list.iattrs->iattr[0], 
		   attr_count * sizeof(int_attr));
	    ((int_attr_p) b->tmp_buffer)->int_attr_count += attr_count;
	    break;
	  }
	default: {
	    /* no bulk stuff here... marshal one by one */
	    int i;
	    for (i=0; i<l->l.list.iattrs->other_attr_count; i++) {
		attr_p attr = &l->l.list.attributes[i];
		void *buffer_end = add_to_tmp_buffer(b, 8);
		memcpy(buffer_end, attr, 8);
		switch (attr->val_type) {
		case Attr_Int4:
		case Attr_Undefined:
		case Attr_Float16:
		case Attr_Float4:
		    assert(0);
		    break;
		case Attr_Atom:
		    buffer_end = add_to_tmp_buffer(b, 4);
		    *((int*)buffer_end) = (int) (long)attr->value.u.i;
		    break;
		case Attr_Int8:
		    buffer_end = add_to_tmp_buffer(b, 8);
		    memcpy(buffer_end, &attr->value.u.l, 8);
		    break;
		case Attr_Float8:
		    buffer_end = add_to_tmp_buffer(b, 8);
		    memcpy(buffer_end, &attr->value, 8);
		    break;
		case Attr_Opaque:
		case Attr_String: {
		    void *value;
		    int len;
		    int pad_len;
		    if (attr->val_type == Attr_String) {
			value = (char*) attr->value.u.p;
			len = (int)strlen((char*)value) + 1;
		    } else {
			value = ((attr_opaque_p)attr->value.u.p)->buffer;
			len = ((attr_opaque_p)attr->value.u.p)->length;
		    }
		    pad_len = roundup4(len+2) - 2;
		    buffer_end = add_to_tmp_buffer(b, 2 + pad_len);
		    *((int2*)buffer_end) = (int2) len;
		    memcpy((char*)buffer_end + 2, value, len);
		    break;
		  }
		case Attr_List:
		    assert(0);
		    break;
		}
		((int_attr_p) b->tmp_buffer)->other_attr_count ++;
	    }
	  }
	}
    } else {
        int i;
        for (i=0; i<l->l.lists.sublist_count; i++) {
	    recursive_encode(l, b, t);
	}
    }
}

	
extern void *
encode_attr_for_xmit(attr_list l, AttrBuffer b, int *length)
{
    if (l->list_of_lists == 0) {
	if (l->l.list.iattrs->other_attr_count == 0) {
	    /* fast case, a single list with no non-integer attributes */
	    /* just return a pointer to the data block */
	    *length = sizeof(struct int_attr_struct) + 
		(l->l.list.iattrs->int_attr_count - 1) * sizeof(int_attr);
	    return l->l.list.iattrs;
	}
    }
    add_to_tmp_buffer(b, (unsigned)sizeof(struct int_attr_struct));
    ((int_attr_p) b->tmp_buffer)->byte_order = WORDS_BIGENDIAN;
    ((int_attr_p) b->tmp_buffer)->int_attr_count = 0;
    ((int_attr_p) b->tmp_buffer)->other_attr_count = 0;
    ((int_attr_p) b->tmp_buffer)->junk = 0;
    /* not the simple case */
    b->tmp_buffer_in_use_size = 4;
    /* first the int Attributes */
    recursive_encode(l, b, Attr_Int4);
    /* then the remaining Attributes */
    recursive_encode(l, b, Attr_Undefined);
    *length = b->tmp_buffer_in_use_size;
    add_to_tmp_buffer(b, 4);  /* pad at the end */
    return b->tmp_buffer;
}

  
static void
byte_swap(char *buf, int len)
{
    switch(len) {
    case 8: {
	int4 tmp;
	tmp = ((int4*) buf)[0];
	((int4*)buf)[0] = ((int4*) buf)[1];
	((int4*) buf)[1] = tmp;
	byte_swap(buf + 4, 4);
	/* falling through */
    }
    case 4: {
	int2 tmp;
	tmp = ((int2*) buf)[0];
	((int2*)buf)[0] = ((int2*) buf)[1];
	((int2*) buf)[1] = tmp;
	byte_swap(buf + 2, 2);
	/* falling through */
    }
    case 2: {
	char tmp;
	tmp = buf[0];
	buf[0] = buf[1];
	buf[1] = tmp;
	break;
    }
    default:
	assert(0);
    }
}

extern attr_list
decode_attr_from_xmit(void * buf)
{
    int_attr_p header = (int_attr_p) buf;
    int iattr_size = sizeof(struct int_attr_struct) + 
	(header->int_attr_count -1) * sizeof(int_attr);
    attr_list l = internal_create_attr_list(header->int_attr_count,
					    header->other_attr_count);
    /* byte swap if the encoders byte order is not equal to ours */
    int bswap = header->byte_order != WORDS_BIGENDIAN;
    char *optr = (char*)buf + iattr_size;
    int i;
    
    memcpy(l->l.list.iattrs, buf, iattr_size);
    l->l.list.iattrs->byte_order = WORDS_BIGENDIAN; /* overwrite original */
    if (bswap) {
	for (i=0; i < header->int_attr_count; i++) {
	    byte_swap((char*)&l->l.list.iattrs->iattr[i].attr_id, 4);
	    byte_swap((char*)&l->l.list.iattrs->iattr[i].value, 4);
	}
    }
    for (i=0; i< header->other_attr_count; i++) {
	memcpy(&l->l.list.attributes[i], optr, 8);
	if (bswap) {
	    byte_swap((char*)&l->l.list.attributes[i].attr_id, 4);
	    byte_swap((char*)&l->l.list.attributes[i].val_type, 4);
	}
	optr += 8;
	switch(l->l.list.attributes[i].val_type) {
	case Attr_Int4:
	case Attr_Undefined:
	case Attr_Float16:
	case Attr_Float4:
	    assert(0);
	    break;
	case Attr_Int8:
	    memcpy(&l->l.list.attributes[i].value, optr, 8);
	    if (bswap) byte_swap((char*)&l->l.list.attributes[i].value, 8);
	    optr += 8;
	    break;
	case Attr_Float8:
	    memcpy(&l->l.list.attributes[i].value, optr, 8);
	    if (bswap) byte_swap((char*)&l->l.list.attributes[i].value, 8);
	    optr += 8;
	    break;
	case Attr_Atom:
	    memcpy(&l->l.list.attributes[i].value, optr, 4);
	    if (bswap) byte_swap((char*)&l->l.list.attributes[i].value, 4);
	    optr += 4;
	    break;
	case Attr_Opaque:
	case Attr_String: {
	    int2 len = *(int2*)optr;
	    int pad_len;
	    if (bswap) byte_swap((char*)&len, 2);
	    pad_len = roundup4(len + 2) - 2;
	    optr += 2;
	    if (l->l.list.attributes[i].val_type == Attr_String) {
		char *value = malloc(len);
		memcpy(value, optr, len);
		l->l.list.attributes[i].value.u.p = (attr_value) value;
	    } else {
		attr_opaque_p op = malloc(sizeof(attr_opaque));
		op->length = len;
		op->buffer = malloc(len);
		memcpy(op->buffer, optr, len);
		l->l.list.attributes[i].value.u.p = (attr_value) op;
	    }
	    optr += pad_len;
	    break;
	  }
	case Attr_List:
	    assert(0);
	    break;
	}
    }
    return l;
}


static const char num_to_char[] =
   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char signed char_to_num[256] = {
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,62, -1,-1,-1,63,
    52,53,54,55, 56,57,58,59, 60,61,-1,-1, -1,-1,-1,-1,
    -1, 0, 1, 2,  3, 4, 5, 6,  7, 8, 9,10, 11,12,13,14,
    15,16,17,18, 19,20,21,22, 23,24,25,-1, -1,-1,-1,-1,
    -1,26,27,28, 29,30,31,32, 33,34,35,36, 37,38,39,40,
    41,42,43,44, 45,46,47,48, 49,50,51,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
};

/*
 * Decode base64 data to 'output'.  Decode in-place if 'output' is NULL.
 * Return the length of the decoded data, or -1 if there was an error.
 */
static int 
base64_decode(input, output)
unsigned char *input;
unsigned char *output;
{
    int len = 0;
    int c1, c2, c3, c4;

    if (output == NULL) output = input;
    while (*input) {
	c1 = *input++;
	if (char_to_num[c1] == -1) return -1;
	c2 = *input++;
	if (char_to_num[c2] == -1) return -1;
	c3 = *input++;
	if (c3 != '=' && char_to_num[c3] == -1) return -1; 
	c4 = *input++;
	if (c4 != '=' && char_to_num[c4] == -1) return -1;
	*output++ = (char_to_num[c1] << 2) | (char_to_num[c2] >> 4);
	++len;
	if (c3 == '=') break;
	*output++ = ((char_to_num[c2] << 4) & 0xf0) | (char_to_num[c3] >> 2);
	++len;
	if (c4 == '=') break;
	*output++ = ((char_to_num[c3] << 6) & 0xc0) | char_to_num[c4];
	++len;
    }

    return len;
}
	
/*
 * Do base64 encoding of binary buffer, returning a malloc'd string
 */
static char *
base64_encode(buffer, len)
char *buffer;
unsigned int len;
{
    char * buf;
    int buflen = 0;
    int c1, c2, c3;
    int maxlen = len*4/3 + 4;
#ifdef OVERKILL
    maxlen = len*2 + 2;
#endif

    buf = malloc(maxlen * sizeof(char));
    if(buf == NULL) {
	return NULL;
    } else {
	memset(buf, 0, maxlen * sizeof(char));
    }

    while (len) {
	
	c1 = (unsigned char)*buffer++;
	buf[buflen++] = num_to_char[c1>>2];

	if (--len == 0) c2 = 0;
	else c2 = (unsigned char)*buffer++;
	buf[buflen++] = num_to_char[((c1 & 0x3)<< 4) | ((c2 & 0xf0) >> 4)];

	if (len == 0) {
	    buf[buflen++] = '=';
	    buf[buflen++] = '=';
	    break;
	}

	if (--len == 0) c3 = 0;
	else c3 = (unsigned char)*buffer++;

	buf[buflen++] = num_to_char[((c2 & 0xf) << 2) | ((c3 & 0xc0) >>6)];
	if (len == 0) {
	    buf[buflen++] = '=';

	    break;
	}

	--len;
	buf[buflen++] = num_to_char[c3 & 0x3f];

    }

    buf[buflen]=0;

    return buf;
}

int atl_base64_decode(input, output)
unsigned char *input;
unsigned char *output;
{
    return base64_decode(input, output);
}

char *
atl_base64_encode(buffer, len)
char *buffer;
unsigned int len;
{
    return base64_encode(buffer, len);
}
