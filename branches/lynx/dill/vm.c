#include "config.h"
#include "dill.h"
#include "dill_internal.h"
#include "virtual.h"
#include "assert.h"
#include <stdarg.h>
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define PREG(ec, reg) ((reg < 100) ? &ec->p[reg] : &ec->r[reg-100])

static void run_emulation(dill_exec_ctx ec);

#define EMULATION_BODY \
    va_list ap;\
    int i;\
    int param_count = ec->dc->p->save_param_count;\
    ec->p = malloc(param_count * sizeof(struct reg_type));\
\
    va_start(ap, ec);\
    if ((param_count < 1) || (ec->dc->p->c_param_args[0].type != DILL_EC)) {\
	fprintf(stderr, "No emulation possible, %%EC not first argument\n");\
    }\
    ec->p[0].u.p.p = ec;\
    for (i= 1; i < param_count; i++) {\
	switch (ec->dc->p->c_param_args[i].type) {\
	case DILL_C:\
	    ec->p[i].u.c.c = va_arg(ap, int);\
	    break;\
	case DILL_UC:\
	    ec->p[i].u.uc.uc = va_arg(ap, int);\
	    break;\
	case DILL_S:\
	    ec->p[i].u.s.s = va_arg(ap, int);\
	    break;\
	case DILL_US:\
	    ec->p[i].u.us.us = va_arg(ap, int);\
	    break;\
	case DILL_I:\
	    ec->p[i].u.i.i = va_arg(ap, int);\
	    break;\
	case DILL_U:\
	    ec->p[i].u.u.u = va_arg(ap, unsigned);\
	    break;\
	case DILL_L:\
	    ec->p[i].u.l.l = va_arg(ap, long);\
	    break;\
	case DILL_UL:\
	    ec->p[i].u.ul.ul = va_arg(ap, unsigned long);\
	    break;\
	case DILL_F:\
	    ec->p[i].u.f.f = va_arg(ap, double);\
	    break;\
	case DILL_D:\
	    ec->p[i].u.d.d = va_arg(ap, double);\
	    break;\
	case DILL_P:\
	case DILL_EC:\
	    ec->p[i].u.p.p = va_arg(ap, char*);\
	    break;\
default: printf("Unknown param type %d\n",ec->dc->p->c_param_args[i].type);\
	}\
    }\
    va_end(ap);\
\
    run_emulation(ec);

int
emulate_vm_i_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.i.i);
}

char emulate_vm_c_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.u.u);
}

unsigned char emulate_vm_uc_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.uc.uc);
}

short emulate_vm_s_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.s.s);
}

unsigned short emulate_vm_us_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.us.us);
}

unsigned int emulate_vm_u_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.u.u);
}

long emulate_vm_l_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.l.l);
}

unsigned long emulate_vm_ul_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.ul.ul);
}

void *emulate_vm_p_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.p.p);
}

float emulate_vm_f_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.f.f);
}

double emulate_vm_d_func(dill_exec_ctx ec, ...)
{
    EMULATION_BODY
    return (PREG(ec, ec->ret_reg)->u.d.d);
}

void emulate_vm_v_func(dill_exec_ctx ec, ...) 
{
    EMULATION_BODY
}

extern void *
emulate_clone_code(c, new_base, available_size)
dill_stream c;
void *new_base;
int available_size;
{
    return c->p->fp;
}

static void
print_warning()
{
    fprintf(stderr, "No emulation possible, %%EC not first argument\n");
}

void
setup_VM_proc(dill_stream c)
{
    if ((c->p->c_param_count < 1) || (c->p->c_param_args[0].type != DILL_EC)) {
	fprintf(stderr, "No emulation possible, %%EC not first argument\n");
	c->p->fp = (void*)print_warning;
	return;
    }
    c->p->fp = NULL;
    c->j->clone_code = emulate_clone_code;
    switch (c->p->ret_type) {
    case DILL_C:
	c->p->fp = (void*)emulate_vm_c_func;
	break;
    case DILL_UC:
	c->p->fp = (void*)emulate_vm_uc_func;
	break;
    case DILL_S:
	c->p->fp = (void*)emulate_vm_s_func;
	break;
    case DILL_US:
	c->p->fp = (void*)emulate_vm_us_func;
	break;
    case DILL_I:
	c->p->fp = (void*)emulate_vm_i_func;
	break;
    case DILL_U:
	c->p->fp = (void*)emulate_vm_u_func;
	break;
    case DILL_L:
	c->p->fp = (void*)emulate_vm_l_func;
	break;
    case DILL_UL:
	c->p->fp = (void*)emulate_vm_ul_func;
	break;
    case DILL_P:
	c->p->fp = (void*)emulate_vm_p_func;
	break;
    case DILL_F:
	c->p->fp = (void*)emulate_vm_f_func;
	break;
    case DILL_D:
	c->p->fp = (void*)emulate_vm_d_func;
	break;
    case DILL_V:
	c->p->fp = (void*)emulate_vm_v_func;
	break;
    }
}

#include "vm_include.c"
#ifdef BUILD_EMULATOR
#include <avcall.h>
#endif
static void run_emulation(dill_exec_ctx ec)
{
    dill_stream c = ec->dc;
    void *insns = c->p->code_base;
    virtual_insn *ip = &((virtual_insn *)insns)[0];

    while (1) {
	struct reg_type *pused[3];
	struct reg_type *pdest;
	int loc;
	int insn_code;
	insn_code = ip->insn_code;
	loc = ((char*)ip - (char*)insns);
	if (c->dill_debug) {
	    printf("   v    loc(%d)  ", loc);
	    virtual_print_insn(c, NULL, ip);
	    printf("\n");
	}
	switch(ip->class_code) {
	case iclass_arith3: {
	    /* arith 3 operand integer insns */
	    int r0 = ip->opnds.a3.src1;
	    int r1 = ip->opnds.a3.src2;
	    int d = ip->opnds.a3.dest;
	    pused[0] = PREG(ec, r0);
	    pused[1] = PREG(ec, r1);
	    pdest = PREG(ec, d);
	    emulate_arith3(insn_code, pdest, pused[0], pused[1]);
	    break;
	}
	case iclass_arith2: {
	    /* arith 2 operand integer insns */
	    int r0 = ip->opnds.a2.src;
	    int d = ip->opnds.a2.dest;
	    pused[0] = PREG(ec, r0);
	    pdest = PREG(ec, d);
	    emulate_arith2(insn_code, pdest, pused[0]);
	    break;
	}
	case iclass_arith3i:{
	    /* arith 3 immediate operand integer insns */
	    int r0 = ip->opnds.a3i.src;
	    int d = ip->opnds.a3i.dest;
	    pused[0] = PREG(ec, r0);
	    pdest = PREG(ec, d);
	    emulate_arith3i(insn_code, pdest, pused[0], ip->opnds.a3i.u.imm);
	    break;
	}
	case iclass_ret:
	    ec->ret_reg = ip->opnds.a1.src;
	    return;
	    break;
	case iclass_convert: {
	    int r0 = ip->opnds.a2.src;
	    int d = ip->opnds.a2.dest;
	    pused[0] = PREG(ec, r0);
	    pdest = PREG(ec, d);
	    emulate_convert(ip->insn_code & 0xff, pdest, pused[0]);
	    break;
	}
	case iclass_loadstore: {
	    /* load store immediate operand integer insns */
	    pdest = PREG(ec, ip->opnds.a3.dest);
	    pused[0] = PREG(ec, ip->opnds.a3.src1);
	    pused[1] = PREG(ec, ip->opnds.a3.src2);
	    if ((ip->insn_code >> 4) == 0) {
		emulate_loadi(ip->insn_code & 0xf,
			      pdest, pused[0],
			      pused[1]->u.l.l);
	    } else {
		/* a store, dest is the source of the store */
		emulate_storei(ip->insn_code & 0xf,
			       pdest, pused[0],
			       pused[1]->u.l.l);
	    }
	    break;
	}
	case iclass_lea: {
	    int offset = ip->opnds.a3i.u.imm;
	    pused[0] = PREG(ec, ip->opnds.a3i.src);
	    pdest = PREG(ec, ip->opnds.a3i.dest);
	    pdest->u.p.p = ((char*)pused[0]->u.p.p) + offset;
	    break;
	}
	case iclass_loadstorei:
	    /* load store immediate operand integer insns */
	    pdest = PREG(ec, ip->opnds.a3i.dest);
	    pused[0] = PREG(ec, ip->opnds.a3i.src);
	    if ((ip->insn_code >> 4) == 0) {
		emulate_loadi(ip->insn_code & 0xf,
			       pdest, pused[0],
			       ip->opnds.a3i.u.imm);
	    } else {
		/* a store, dest is the source of the store */
		emulate_storei(ip->insn_code & 0xf,
			       pdest, pused[0],
			       ip->opnds.a3i.u.imm);
	    }
	    break;
	case iclass_set: {
	    pdest = PREG(ec, ip->opnds.a3i.dest);
	    pdest->u.l.l = ip->opnds.a3i.u.imm;
	    break;
	}
	case iclass_setf: {
	    pdest = PREG(ec, ip->opnds.sf.dest);
	    if ((ip->insn_code & 0xf) == DILL_F) {
		pdest->u.f.f = (float) ip->opnds.sf.imm;
	    } else {
		pdest->u.d.d = ip->opnds.sf.imm;
	    }
	    break;
	}
	case iclass_mov: {
	    pdest = PREG(ec, ip->opnds.a2.dest);
	    pused[0] = PREG(ec, ip->opnds.a2.src);

	    pdest->u = pused[0]->u;
	    break;
	}
	case iclass_reti:
	    /* return immediate integer insns */
	    /* arbitrarily destroy reg 100 and return it */
	    ec->ret_reg = 100;
	    PREG(ec, ec->ret_reg)->u.i.i = ip->opnds.a3i.u.imm;
	    return;
	case iclass_branch:
	{
	    /* branch */
	    int br_op = ip->insn_code;
	    int r0 = ip->opnds.br.src1;
	    int r1 = ip->opnds.br.src2;
	    pused[0] = PREG(ec, r0);
	    pused[1] = PREG(ec, r1);
	    if (emulate_branch(br_op, pused[0], pused[1])) {
		ip = (void*)(((char *)(&((virtual_insn *)insns)[-1])) + c->p->branch_table.label_locs[ip->opnds.br.label]);
	    }
	}
	break;
	case iclass_branchi:
	{
	    /* branch immediate */
	    int br_op = ip->insn_code;
	    int r0 = ip->opnds.bri.src;
	    pused[0] = PREG(ec, r0);
	    if (emulate_branchi(br_op, pused[0], ip->opnds.bri.imm_l)) {
		ip = (void*)(((char *)(&((virtual_insn *)insns)[-1])) + c->p->branch_table.label_locs[ip->opnds.bri.label]);
	    }
	}
	break;
	case iclass_jump_to_label:
	    ip = (void*)(((char *)(&((virtual_insn *)insns)[-1])) + c->p->branch_table.label_locs[ip->opnds.br.label]);
	    break;
	break;
	case iclass_jump_to_reg:
	    printf("Unimpl13\n");
	    /*	    dill_jp(c, pused[0]);*/
	    break;
	case iclass_jump_to_imm:
	    printf("Unimpl14\n");
	    dill_jpi(c, ip->opnds.bri.imm_a);
		break;
	case iclass_special:
	    printf("Unimpl15\n");
	    dill_special(c, ip->opnds.spec.type, ip->opnds.spec.param);
	    break;
	case iclass_call:
	{
#ifdef BUILD_EMULATOR
	    int i;
	    void* imm = ip->opnds.bri.imm_a;
	    int ret_reg = ip->opnds.bri.src;
	    int reg = ip->insn_code & 0x10;
	    int typ = ip->insn_code & 0xf;
	    void *func;
	    av_alist alist;
	    pused[0] = PREG(ec, ret_reg);
	    if (reg != 0) {
		func = PREG(ec, (long)imm)->u.p.p;
	    } else {
		func = (void*)imm;
	    }
	    switch(typ) {
	    case DILL_C:
		av_start_char(alist, func, &pused[0]->u.c.c);
		break;
	    case DILL_UC:
		av_start_uchar(alist, func, &pused[0]->u.uc.uc);
		break;
	    case DILL_S:
		av_start_short(alist, func, &pused[0]->u.s.s);
		break;
	    case DILL_US:
		av_start_ushort(alist, func, &pused[0]->u.us.us);
		break;
	    case DILL_I:
		av_start_int(alist, func, &pused[0]->u.i.i);
		break;
	    case DILL_U:
		av_start_uint(alist, func, &pused[0]->u.u.u);
		break;
	    case DILL_L:
		av_start_long(alist, func, &pused[0]->u.l.l);
		break;
	    case DILL_UL:
		av_start_ulong(alist, func, &pused[0]->u.ul.ul);
		break;
	    case DILL_P:
		av_start_ptr(alist, func, void*, &pused[0]->u.p.p);
		break;
	    case DILL_F:
		av_start_float(alist, func, &pused[0]->u.f.f);
		break;
	    case DILL_D:
		av_start_double(alist, func, &pused[0]->u.d.d);
		break;
	    case DILL_V:
		av_start_void(alist, func);
		break;
	    }
	    for (i=0; i < ec->out_param_count; i++) {
		switch(ec->out_params[i].typ) {
		case DILL_C:
		    av_char(alist, ec->out_params[i].val.u.c.c);
		    break;
		case DILL_UC:
		    av_uchar(alist, ec->out_params[i].val.u.uc.uc);
		    break;
		case DILL_S:
		    av_short(alist, ec->out_params[i].val.u.s.s);
		    break;
		case DILL_US:
		    av_ushort(alist, ec->out_params[i].val.u.us.us);
		    break;
		case DILL_I:
		    av_int(alist, ec->out_params[i].val.u.i.i);
		    break;
		case DILL_U:
		    av_uint(alist, ec->out_params[i].val.u.u.u);
		    break;
		case DILL_L:
		    av_long(alist, ec->out_params[i].val.u.l.l);
		    break;
		case DILL_UL:
		    av_ulong(alist, ec->out_params[i].val.u.ul.ul);
		    break;
		case DILL_P:
		    av_ptr(alist, void*, ec->out_params[i].val.u.p.p);
		    break;
		case DILL_F:
		    av_float(alist, ec->out_params[i].val.u.f.f);
		    break;
		case DILL_D:
		    av_double(alist, ec->out_params[i].val.u.d.d);
		    break;
		case DILL_V:
		    break;
		}
	    }
	    av_call(alist);
#endif
	}
	    break;

	case iclass_push:
	{
	    int typ = ip->insn_code & 0xf;
	    int r0 = ip->opnds.a1.src;
	    if (ip->opnds.a1.src == 0xffff) {
		ec->out_param_count = 0;
		ec->out_params = malloc(sizeof(ec->out_params[0]));
	    } else {
		ec->out_params = realloc(ec->out_params, sizeof(ec->out_params[0]) * (ec->out_param_count + 1));
		ec->out_params[ec->out_param_count].typ = typ;
		ec->out_params[ec->out_param_count].val = *PREG(ec, r0);
		ec->out_param_count++;
	    }
	}
	break;
	case iclass_pushi:
	    ec->out_params = realloc(ec->out_params, sizeof(ec->out_params[0]) * (ec->out_param_count + 1));
	    ec->out_params[ec->out_param_count].typ = DILL_L;
	    ec->out_params[ec->out_param_count].val.u.l.l = ip->opnds.a3i.u.imm;
	    ec->out_param_count++;
	    break;
	case iclass_pushf:
	    ec->out_params = realloc(ec->out_params, sizeof(ec->out_params[0]) * (ec->out_param_count + 1));
	    ec->out_params[ec->out_param_count].typ = DILL_D;
	    ec->out_params[ec->out_param_count].val.u.l.l = ip->opnds.a3i.u.imm;
	    ec->out_param_count++;
	    break;
	case iclass_nop:
	    break;
	}
	ip++;
    }
}
