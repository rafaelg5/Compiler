#ifndef SYMBOL
#define SYMBOL

#include <stdlib.h>

typedef struct symbol {
	int type, dim;
	int is_arr;
	char[32] id;
} symbol;

symbol *new_symbol()
{
	symbol *s = (symbol*) malloc (sizeof(symbol));
	
	return s;
}

#endif
