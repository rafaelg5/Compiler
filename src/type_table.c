#include <stdlib.h>
#include <string.h>
#include "../include/type_table.h"

/**
* Agrega un elemento a una lista.
* @param l la lista
* @param element el elemento a agregar
*/
void add_element_to_list(List* l, void* element){
  l->next = element;
  l->next->element = NULL;
}

/**
* Crea un nuevo tipo
* @param base el entero que representa al tipo_base
* @param dim la dimensión del tipo
*/
Type* new_type(int base, int dim){
  Type* type = (Type*) malloc(sizeof(Type));
  type->base_type = base;
  type->dim = dim;
  return type;
}

/**
* Inicializa los atributos de una tabla de tipos
* @return un apuntador a la tabla de tipos
*/
Type_Table* init_type_table(){

    Type_Table* tt = (Type_Table*) malloc(sizeof(Type_Table));
    tt->types = (List*) malloc(sizeof(List));
    tt->count = 5;

    add_element_to_list(tt->types, new_type(INT_T, 4));
    add_element_to_list(tt->types, new_type(FLOAT_T, 4));
    add_element_to_list(tt->types, new_type(DOUBLE_T, 8));
    add_element_to_list(tt->types, new_type(CHAR_T, 1));
    add_element_to_list(tt->types, new_type(VOID_T, 0));

    return tt;
}
