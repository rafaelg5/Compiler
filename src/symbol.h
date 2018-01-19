#ifndef SYMBOL
#define SYMBOL

#include <stdlib.h>

typedef struct intermediate_symbol {
	int type, dim;
	int is_arr;
	char id[32];
} symbol;

symbol *new_inter_symbol()
{
	symbol *s = (symbol*) malloc (sizeof(symbol));
	
	return s;
}

#endif
