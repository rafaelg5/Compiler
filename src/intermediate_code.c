#include "../include/intermediate_code.h"
#include <string.h>
#include <stdio.h>

void init_code(){
	CODE.size = 0;
}

int insert_code(char *op, char *arg1, char *arg2, char *dest){
	quad q;
	strcpy(q.op, op);
	strcpy(q.arg1, arg1);
	strcpy(q.arg2, arg2);
	strcpy(q.dest, dest);

	CODE.code[CODE.size++] = q;
	return CODE.size-1;
}

label create_label(){
	label l;
	l.size = 0;
	return l;
}
label insert_in_label(label l1, int x){
	label l = l1;
	l.code_lines[l.size++] = x;
	return l;
}
label merge(label l1, label l2){
	label l = l1;
	for(int i = 0; i<l2.size; i++){
		l.code_lines[l.size++] = l2.code_lines[i];
	}
	return l;
}
void backpatch(label l, int inst){
	for(int i = 0; i < l.size ; i++){
		sprintf(CODE.code[l.code_lines[i]].dest, "%d", inst);
	}
}

void print_code(){
	FILE *fp;
	fp = fopen("Codigo_Intermedio.i", "w");// "w" means that we are going to write on this file

	fprintf(fp,"************ CODIGO INTERMEDIO **************\n");
    fprintf(fp,"%5s%10s%10s%10s%10s\n","inst","op","arg1","arg2","dest");
    for(int i=0; i <CODE.size ;i++){
        fprintf(fp, "%5d%10s%10s%10s%10s\n",i, CODE.code[i].op, CODE.code[i].arg1, CODE.code[i].arg2, CODE.code[i].dest);
    }
}

void print_label(label x){
	printf("Label size = %d; label = ", x.size);
	for(int i = 0; i<x.size; i++){
		printf("%d, ", x.code_lines[i]);
	}
	printf("\n");
}