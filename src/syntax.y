%{
  #include <string.h>
  #include <stdio.h>
  #include <glib.h>
  #include "symbol.h"
  #include "sym_list.h"
  #include "../include/sym_table.h"

  extern FILE *yyin;
  extern FILE *yyout;
  extern int yylex();
  extern int yylineno;
  extern char *yytext;
  void yyerror(char *s);

  // inherited vars
  int inh_type, inh_dim;

  // Memory address for new vars
  int address = 0;

  // Temporal variables
  int temp = 0;

  // Symbol table
  Sym_Table *table; 

  // Aux functions
  void init();
  void error(char *msg, int line);

  symbol *operacion(symbol *arg1, symbol *arg2, char *op);
  char *get_temporal();

  char *aux_id;
%}

%start program

%union {
  char* cad;
  int num;
  double flo;
  struct intermediate_symbol *att;
  struct _GList* list;
  char *id;
}

%token INT DOUBLE FLOAT CHAR VOID STRUCT
%token CARACTER NUMERO FLOTANTE CADENA
%token SWITCH CASE BREAK DEFAULT
%token FOR IF ELSE DO WHILE
%token FUNC RETURN PRINT
%token TRUE_P FALSE_P ID LE GE EQ NEQ AND OR

%type<num> NUMERO
%type<flo> FLOTANTE
%type<cad> CADENA ID CARACTER relation
%type<att> type type_arr param_arr sents cases case_def ids arrays expression logical id_list arguments
%type<list> params param_list

%left OR
%left AND
%nonassoc EQ NEQ
%nonassoc '>' '<' GE LE
%left '+' '-'
%nonassoc '%'
%left '*' '/'
%nonassoc IFX
%nonassoc ELSE

%%

// P -> D F
program:
  decs funcs {}
  ;

// D -> T L; D | epsilon
decs:
  type  id_list ';' decs {}
  | %empty
  ;

// T -> buncha types
type:
  INT  		{}
  | FLOAT  	{}
  | DOUBLE	{}
  | CHAR	{}
  | VOID	{}
  | STRUCT '{' decs '}'	{}
  ;

// L -> L, id C | id C
id_list:
  id_list ',' ID type_arr	{}
  | ID type_arr	{}
  ;

// C -> [ numero ] C | epsilon
type_arr:
  '[' NUMERO ']' type_arr	{}
  | %empty			{}
  ;

// F -> func T id( A ){ D S } F_1 | epsilon
funcs:
  FUNC type ID '(' params ')' '{' decs sents '}' funcs {}
  | %empty
  ;

params:
  param_list	{}
  | %empty	{}
  ;

param_list:
  param_list	',' type	ID param_arr	{}
  | type ID param_arr	{}
  ;

param_arr:
  '[' ']' param_arr	{}
  | %empty	{}
  ;

sents:
  sents sents	{}
  | FOR '(' sents ';' logical ';' sents ')' '{' sents	'}' {}
  | DO '{' sents '}' WHILE '(' logical ')' ';' {}
  | WHILE '(' logical ')' '{' sents	'}' {}
  | IF '(' logical ')' sents %prec IFX	{}
  | IF '(' logical ')' sents ELSE sents	{}
  | SWITCH '(' expression ')' '{' cases case_def '}'	{}
  | BREAK ';'	{}
  | PRINT expression ';'	{}
  | RETURN expression ';'	{}
  | RETURN ';'	{}
  | '{' sents '}'	{}
  | ids '=' expression ';'	{}
  ;

ids:
  ID	{}
  | arrays	{}
  | ID '.' ID {}
  ;

arrays:
  ID '[' expression ']'	{}
  | arrays '[' expression ']'	{}
  ;

cases:
  CASE ':' NUMERO sents cases {}
  | %empty	{}
  ;

case_def:
  DEFAULT ':' sents	{}
  | %empty	{}
  ;

expression:
  expression '*' expression	{}
  | expression '/' expression	{}
  | expression '+' expression	{}
  | expression '-' expression	{}
  | expression '%' expression	{}
  | ids	{}
  | CADENA	{}
  | NUMERO	{}
  | FLOTANTE	{}
  | CARACTER	{}
  | ID '(' arguments ')' {}
  ;

// H
arguments:
  arguments ',' expression	{}
  | expression			{}
  ;

// B
logical:
  logical OR logical	{}
  | logical AND logical	{}
  | '!' logical		{}
  | '(' logical ')'	{}
  | expression relation expression	{}
  | TRUE_P	{}
  | FALSE_P	{}
  ;

relation:
  EQ	{}
  | NEQ	{}
  | GE	{}
  | '>'	{}
  | LE	{}
  | '<'	{}
  ;

%%

void yyerror(char *s)
{
	fprintf(stderr, "Error: '%s'. Con el token '%s' en linea %d\n", s, yytext, yylineno);
  exit(1);
}

void error(char *msg, int line)
{
	fprintf(stderr, "Error, line %d: %s\n", line, msg);
}



int main(int argc, char** argv){
    if(argc>1){
        yyin = fopen(argv[1], "r");
        if(!yyin) return 1;
        yyparse();
        fclose(yyin);
    }
}
