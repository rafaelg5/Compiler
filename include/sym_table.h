#ifndef SYM_TABLE_H
#define SYM_TABLE_H

typedef struct symbol {
  char* id;
  int type;
  int scope;
  struct symbol* next; // Next symbol in bucket
} Symbol;

#ifndef HT_SIZE
  #define HT_SIZE 1024
#endif

typedef struct sym_table {
  Symbol* table[HT_SIZE];
  int count;
} Sym_Table;

// Declaración de la tabla de símbolos
Sym_Table* st;

Symbol* new_symbol(char*, int, int);
int hash();
Symbol* lookup(char*);
Symbol* insert(char*, int, int);

#endif
