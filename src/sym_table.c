#include <stdlib.h>
#include <string.h>
#include "../include/sym_table.h"

void init_table(){

    st = (Sym_Table*) malloc(sizeof(Sym_Table));

    for(int i = 0; i < HT_SIZE; i++)
      st->table[i] = NULL;

    st->count = 0;
}

Symbol* new_symbol(char* name, int type, int scope){

  Symbol* sym = (Symbol*) malloc(sizeof(Symbol));
  sym->id = name;
  sym->type = type;
  sym->scope = scope;
  sym->next = NULL;
  return sym;
}

int hash(char* s){

    int hash_val = 0;

    while(*s != '\0'){
      hash_val = (hash_val << 4) + *s;
       s++;
    }

    return hash_val;
}

Symbol* lookup(char* name){

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

Symbol* insert(char* name, int type, int scope){

  int h = hash(name);
  int index = h % HT_SIZE;
  Symbol* sym = new_symbol(name, type, scope);
  sym->next = st->table[index];
  st->table[index] = sym;
  st->count++;
  return sym;
}
