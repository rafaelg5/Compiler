#ifndef SYM_TABLE_H
#define SYM_TABLE_H

#include "type_table.h"

/*
* Estructura para representar un símbolo.
* id es el identificador del símbolo.
* type es el tipo del símbolo.
* dir es la dirección en memoria del símbolo.
* params son los parámetros en caso de que el símbolo sea una función
* next es el siguiente símbolo en la lista, para evitar colisiones en el
* diccionario.
*/
typedef struct symbol {
  char* id;
  int type;
  int dir;
  List* params;
  struct symbol* next;
} Symbol;

// Tamaño del diccionario
#define HT_SIZE 1024

/*
* Estructura para la tabla de símbolos.
* table es un arreglo de símbolos que representa el diccionario (hash table) con
* los pares key = id del símbolo y valor = símbolo.
* parent es la tabla padre, ya que al crear un struct o una función se define
* un nuevo alcance para las variables.
* count es el número de símbolos en la tabla.
*/
typedef struct sym_table {
  Symbol* table[HT_SIZE];
  struct sym_table* parent;
  int count;
  Type_Table* type_table;
} Sym_Table;

Sym_Table* init_sym_table();
Symbol* new_symbol(char*, int, int);
int hash();
Symbol* lookup(Sym_Table*, char*);
Symbol* insert(Sym_Table*, char*, int, int);
void set_symbol_params(Symbol*, List*);

#endif
