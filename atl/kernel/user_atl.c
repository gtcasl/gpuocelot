#else
#include <linux/artemis.h>

attr_list create_attr_list()
{
  syscall_attrs_atl attrs;
  char *name = "create_attr_list";

  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.list;
}

void free_attr_list(attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "free_attr_list";

  attrs.list = list;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return;
}

void add_ref_attr_list(attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "add_ref_attr_list";

  attrs.list = list;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return;
}

attr_list attr_join_lists(attr_list list1, attr_list list2)
{
  syscall_attrs_atl attrs;
  char *name = "attr_join_lists";

  attrs.list1 = list1;
  attrs.list2 = list2;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.list;
}

attr_list attr_add_list(attr_list list1, attr_list list2)
{
  syscall_attrs_atl attrs;
  char *name = "attr_add_list";

  attrs.list1 = list1;
  attrs.list2 = list2;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.list;
}

int add_attr( 
attr_list list,
atom_t attr_id,
attr_value_type val_type,
attr_value value)
{
  syscall_attrs_atl attrs;
  char *name = "add_attr";

  attrs.list = list;
  attrs.attr_id = attr_id;
  attrs.value_type = val_type;
  attrs.value = value;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

int set_attr(
attr_list list,
atom_t attr_id,
attr_value_type val_type,
attr_value value)
{
  syscall_attrs_atl attrs;
  char *name = "set_attr";

  attrs.list = list;
  attrs.attr_id = attr_id;
  attrs.value_type = val_type;
  attrs.value = value;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

int replace_attr(
attr_list list,
atom_t attr_id, 
attr_value_type val_type,
attr_value value)
{
  syscall_attrs_atl attrs;
  char *name = "replace_attr";

  attrs.list = list;
  attrs.attr_id = attr_id;
  attrs.value_type = val_type;
  attrs.value = value;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

int query_attr(
attr_list list, 
atom_t attr_id, 
attr_value_type *val_type_p,
attr_value *value_p)
{
  syscall_attrs_atl attrs;
  char *name = "query_attr";

  attrs.list = list;
  attrs.attr_id = attr_id;
  attrs.value_type_p = val_type_p;
  attrs.value_p = value_p;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

void dump_attr_list(
attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "dump_attr_list";

  attrs.list = list;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return;
}

atom_t
attr_atom_from_string(
const char *str)
{
  syscall_attrs_atl attrs;
  char *name = "attr_atom_from_string";

  memcpy((void *)&attrs.str, (void *)str, strlen(str)+1);
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);
  attrs.str_len = strlen(attrs.str);

  KECho_syscall_atl((void *)&attrs);

  return attrs.ret_atom;
}

char *
attr_string_from_atom(
atom_t atom)
{
  syscall_attrs_atl attrs;
  char *name = "attr_string_from_atom";

  attrs.atom = atom;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.ret_str;
}

int attr_count(
attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "attr_count";

  attrs.list = list;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

attr_p get_attr(
attr_list list,
int index)
{
  syscall_attrs_atl attrs;
  char *name = "get_attr";

  attrs.list = list;
  attrs.index = index;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.ret_attr_p;
}

char *
attr_list_to_string(
attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "attr_list_to_string";

  attrs.list = list;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.ret_str;
}

attr_list
attr_list_from_string(
char *str)
{
  syscall_attrs_atl attrs;
  char *name = "attr_list_from_string";

  memcpy((void *)&attrs.str, (void *)str, strlen(str)+1);
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);
  attrs.str_len = strlen(attrs.str);

  KECho_syscall_atl((void *)&attrs);

  return attrs.list;
}

int
compare_attr_p_by_val(
attr_p a1,
attr_p a2)
{
  syscall_attrs_atl attrs;
  char *name = "compare_attr_p_by_val";

  attrs.attr_p1 = a1;
  attrs.attr_p2 = a2;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

int
compare_attr_p_xmit_attr_by_val(
attr_p ap,
xmit_attr_ref xa)
{
  syscall_attrs_atl attrs;
  char *name = "compare_attr_p_xmit_attr_by_val";

  attrs.attr_p1 = ap;
  attrs.attr_ref = xa;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

xmit_object
pack_attr_list(
attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "pack_attr_list";

  attrs.list = list;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.ret_obj;
}

void
pack_attr_list_1(
attr_list list,
xmit_object xo)
{
  syscall_attrs_atl attrs;
  char *name = "pack_attr_list_1";

  attrs.list = list;
  attrs.ret_obj = xo;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return;
}

attr_list
unpack_attr_list(
xmit_object xo)
{
  syscall_attrs_atl attrs;
  char *name = "unpack_attr_list";

  attrs.ret_obj = xo;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.list;
}

void
unpack_attr_list_1(
xmit_object xo,
attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "unpack_attr_list_1";

  attrs.list = list;
  attrs.ret_obj = xo;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return;
}

void
unpack_attr_list_2(
int xmit_attr_count,
xmit_attr *xmit_list,
attr_list list)
{
  syscall_attrs_atl attrs;
  char *name = "unpack_attr_list_2";

  attrs.xmit_attr_count = xmit_attr_count;
  attrs.xmit_list = xmit_list;
  attrs.list = list;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return;
}

int
attr_list_subset(
attr_list l1,
attr_list l2)
{
  syscall_attrs_atl attrs;
  char *name = "attr_list_subset";

  attrs.list1 = l1;
  attrs.list2 = l2;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

int
attr_list_subset_xmit_object(
xmit_object xo,
attr_list l1)
{
  syscall_attrs_atl attrs;
  char *name = "attr_list_subset_xmit_object";

  attrs.list1 = l1;
  attrs.ret_obj = xo;
  memcpy((void *)&attrs.name, (void *)name, strlen(name)+1);
  attrs.name_len = strlen(attrs.name);

  KECho_syscall_atl((void *)&attrs);

  return attrs.retval;
}

#endif
