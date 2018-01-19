#ifndef SYMBOL
#define SYMBOL

#include <sys/queue.h>

struct sym_node {
	int type, dim;
	char id[32];
	LIST_ENTRY(sym_node) pointers;
};

typedef struct sym_list {
	LIST_HEAD(symbol_list, sym_node) list;
} sym_list;

#endif
