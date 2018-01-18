#ifndef ATTRIBS_H
#define ATTRIBS_H
#include "intermediate_code.h"

typedef struct _sentences{
	int first;
	label lnext;
} sentences;

typedef struct _expression{
	char var[10];
	int type; 
	int first;
} expression;

typedef struct _condition{
	label ltrue;
	label lfalse;
	int first;
} condition;

#endif