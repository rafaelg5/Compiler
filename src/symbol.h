#ifndef SYMBOL
#define SYMBOL

#include <stdlib.h>
#include "../include/intermediate_code.h"

typedef struct intermediate_symbol {
	int type, dim;
	int is_arr;
	int first;
	label lnext;
	label ltrue;
	label lfalse;
	label lbreaks;
	char id[60];
} symbol;

symbol *new_inter_symbol()
{
	symbol *s = (symbol*) malloc (sizeof(symbol));
	s->first = -1;
	s->lnext = create_label();
	s->ltrue = create_label();
	s->lfalse = create_label();
	s->lbreaks = create_label();
	
	return s;
}

#endif
