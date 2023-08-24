#ifndef MONTYCONTEXT_H
#define MONTYCONTEXT_H

#include <stdio.h>

typedef struct
{
	char *getl_info;
	stack_t *stack_head;
	size_t n_lines;
	FILE *fp_struct;
} MontyContext;

#endif
