#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

// tipos base
#define INT_T 0
#define FLOAT_T 1
#define DOUBLE_T 2
#define CHAR_T 3
#define VOID_T 4

/*
* Estructura para listas genéricas.
* element un elemento de la listas
* next el siguiente elemento
*/
typedef struct list{
  void* element;
  struct list* next;
} List;

/*
* Estructura para la tabla de tipos.
* types es una lista con los tipos de la tabla
* count el número de elementos de la tabla.
*/
typedef struct type_table{
  List* types;
  int count;
} Type_Table;

/*
* Estructura para representar un tipo.
* base_type un entero asociado a un tipo
* dim la dimensión
*/
typedef struct type{
  int base_type;
  int dim;
} Type;

void add_element_to_list(List*, void*);
Type* new_type(int, int);
Type_Table* init_type_table();

#endif
