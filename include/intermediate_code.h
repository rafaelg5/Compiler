#ifndef INTERMEDIATE_CODE_H
#define INTERMEDIATE_CODE_H

typedef struct _quad {
	char op[10];
	char arg1[20];
	char arg2[20];
	char dest[20];
} quad;

typedef struct _intermediate_code{
	quad code[10000];
	int size;
} intermediate_code;

typedef struct _label{
	int code_lines[100];
	int size;
} label;

intermediate_code CODE;

void init_code();
int insert_code(char *op, char *arg1, char *arg2, char *dest);

label create_label();
label insert_in_label(label l, int x);
label merge(label l1, label l2);
void backpatch(label l, int inst);

void print_code();
void print_label(label l);
#endif