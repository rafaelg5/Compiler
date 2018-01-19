#include <stdlib.h>
#include <string.h>
#include "../include/sym_table.h"
#include "../include/type_table.h"

/**
* Inicializa los atributos de una tabla de símbolos.
* @return un apuntador a la tabla de símbolos
*/
Sym_Table* init_sym_table(){

    Sym_Table* st = (Sym_Table*) malloc(sizeof(Sym_Table));

    for(int i = 0; i < HT_SIZE; i++)
      st->table[i] = NULL;

    st->count = 0;
    st->size = 0;
    st->parent = NULL;
    st->child = NULL;
    st-> type_table = init_type_table();

    return st;
}

/**
* Crea un nuevo símbolo.
* @param name el nombre o identificador del símbolo
* @param type el tipo del símbolo
* @param dir la dirección en memoria del símbolo
* @return un apuntador al símbolo
*/
Symbol* new_symbol(char* name, int type, int dir){

  Symbol* sym = (Symbol*) malloc(sizeof(Symbol));
  sym->id = name;
  sym->type = type;
  sym->dir = dir;
  sym->params = NULL;
  sym->next = NULL;
  return sym;
}

/**
* Función hash para el diccionario.
* @param s la llave
* @return un entero entre 0 y HT_SIZE - 1
*/
int hash(char* key){

    int hash_val = 0;

    while(*key != '\0'){
      hash_val = (hash_val << 4) + *key;
       key++;
    }

    return hash_val;
}

/**
* Busca un símbolo en la tabla.
* @param st la tabla en la que se quiere buscar
* @param name el nombre o id del símbolo
* @return un apuntador al símbolo, si existe, e.o.c devuelve NULL
*/
Symbol* lookup(Sym_Table* st, char* name){

  int h = hash(name);
  int index = h % HT_SIZE;
  Symbol* sym = st->table[index];

  while(sym != NULL){

    if(strcmp(sym->id, name) == 0)
      break;
    sym = sym->next;
  }

  return sym;
}

/**
* Inserta un nuevo símbolo en la tabla.
* @param st la tabla en la que se quiere buscar
* @param name el nombre o id del símbolo
* @param type el tipo del símbolo
* @param dir la dirección en memoria del símbolo
* @return un apuntador al nuevo símbolo
*/
Symbol* insert(Sym_Table* st, char* name, int type, int dir, int dim){

  int h = hash(name);
  int index = h % HT_SIZE;
  Symbol* sym = new_symbol(name, type, dir);
  sym->next = st->table[index];
  st->table[index] = sym;
  st->count++;
  return sym;
}

/**
* Agrega la lista de parámetros/argumentos de una función
* @param sym el símbolo
* @param params la lista de parámetros
*/
void set_symbol_params(Symbol* sym, List* params){
  sym->params = params;
}
