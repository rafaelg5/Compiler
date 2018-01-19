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
  {
  init();
  }
  decs
  funcs
  {
  print_code();
  }
  ;

// D -> T L; D | epsilon
decs:
  type  {
	inh_type = $1->type;
	inh_dim = $1->dim;
	}
  id_list ';' decs
  | %empty
  ;

// T -> buncha types
type:
  INT  		{
		$$ = new_inter_symbol();
		$$->type = 0;
		$$->dim = 4;
		}
  | FLOAT  	{
		$$ = new_inter_symbol();
            	$$->type = 1;
            	$$->dim = 4;
           	}
  | DOUBLE	{
            	$$ = new_inter_symbol();
            	$$->type = 2;
            	$$->dim = 8;
            	}
  | CHAR	{
            	$$ = new_inter_symbol();
            	$$->type = 3;
            	$$->dim = 1;
            	}
  | VOID	{
            	$$ = new_inter_symbol();
            	$$->type = 4;
            	$$->dim = 0;
            	}
  | STRUCT	{
		// Create a new table and link it to the current one
  		Sym_Table *new_table; 
		new_table = init_sym_table();
		new_table->parent = table;
		table->child = new_table;
		table = new_table;
		}
  '{' decs '}'	{
		Sym_Table *prev = table;
		table = table->parent;
		
		$$ = new_inter_symbol();
		$$->type = 5;
		$$->dim = prev->size;
		}
  ;

// L -> L, id C | id C
id_list:
  id_list
  ','
  ID type_arr	{
		if(lookup(table, $3) == NULL)
		{
			insert(table, $3, $4->type, address, $4->dim);
			address += $4->dim;
		} else {
			error("ID defined twice.", yylineno);
		}
		}
  | ID type_arr	{
		if(lookup(table, $1) == NULL)
		{
			insert(table, $1, $2->type, address, $2->dim);
			address += $2->dim;
		} else {
			error("ID defined twice.", yylineno);
		}
		}
  ;

// C -> [ numero ] C | epsilon
type_arr:
  '[' NUMERO ']' type_arr	{
				$$ = $4;
				$$->is_arr = 1;
				$$->type = $4->type;
				$$->dim = $2 * $4->dim;
				}
  | %empty			{
				$$ = new_inter_symbol();
				$$->type = inh_type;
				$$->dim = inh_dim;
				}
  ;

// F -> func T id( A ){ D S } F_1 | epsilon
funcs:
  FUNC type ID 
  {
    insert_code("label","","", $3);
  }
  '(' params ')' '{' decs sents '}' 
  {
    char *tmp, *lab;
    tmp = (char*) malloc(strlen($3)+4);
    sprintf(tmp, "%s%s", "end", $3);
    insert_code("label","","", tmp);
  }
  funcs
  | %empty
  ;

params:
  param_list	{
		$$ = $1;
		}
  | %empty	{
		$$ = NULL;
		}
  ;

param_list:
  param_list	
  ',' type	{
		inh_type = $3->type;
		inh_dim = $3->dim;
		}
  ID param_arr	{
		$$ = $1;

		if(lookup(table, $5) == NULL)                              
                {                                                          
			$$ = g_list_append($$, $6->type);
                        insert(table, $5, $6->type, address, $6->dim);                   
                        address += $6->dim;                                     
                } else {                                                   
                        error("ID defined twice.", yylineno);              
                } 
		}
  | type	{
		inh_type = $1->type;
		inh_dim = $1->dim;
		}
  ID param_arr	{
		$$ = NULL;

		if(lookup(table, $3) == NULL)                              
                {                                                          
			$$ = g_list_append($$, $4->type);
                        insert(table, $3, $4->type, address, $4->dim);                   
                        address += $4->dim;                                     
                } else {                                                   
                        error("ID defined twice.", yylineno);              
                }
		}
  ;

param_arr:
  '[' ']' param_arr	{
			$$ = new_inter_symbol();
			$$->dim = 8;
			$$->is_arr = 1;
			$$->type = $3->type;
			}
  | %empty	{
		$$ = new_inter_symbol();
		$$->type = inh_type;
		$$->dim = inh_dim;
		}
  ;

sents:
  sents sents	{}
  | FOR '(' sents ';' logical ';' sents ')' sents	{}
  | DO sents WHILE '(' logical ')' ';'	{}
  | WHILE '(' logical ')' sents	{}
  | IF '(' logical ')' sents %prec IFX	{}
  | IF '(' logical ')' sents ELSE sents	{}
  | SWITCH '(' expression ')' '{' cases case_def '}'	{}
  | BREAK ';'	{}
  | PRINT expression ';'	{}
  | RETURN expression ';'	{}
  | RETURN ';'	{}
  | '{' sents '}'	{
			$$ = $2;
			}
  | ids '=' expression ';'	{
    $$ = new_inter_symbol();

    char *tmp = strdup("=");
    insert_code(tmp, $3->id, "", $1->id);
    free(tmp);
  }
  ;

ids:
  ID	{
    $$ = new_inter_symbol();

    //Para el codigo intermedio
    strcpy($$->id, $1);
  }
  | arrays	{
    $$ = $1;
  }
  | ID '.' ID {
    $$ = new_inter_symbol();

    //Para el codigo intermedio
    sprintf($$->id, "%s.%s", $1, $3);
  }
  ;

arrays:
  ID '[' expression ']'	{
    $$ = new_inter_symbol();

    //Para el codigo intermedio
    sprintf($$->id, "%s[%s]", $1, $3->id);
  }
  | arrays '[' expression ']'	{
    $$ = new_inter_symbol();

    //Para el codigo intermedio
    sprintf($$->id, "%s[%s]", $1->id, $3->id);
  }
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
  expression '*' expression	{
  				// Generar codigo intermedio
          char *tmp = strdup("*");
          $$ = operacion($1, $3, tmp);
          free(tmp);
				}
  | expression '/' expression	{
  				// Generar codigo intermedio
          char *tmp = strdup("/");
          $$ = operacion($1, $3, tmp);
          free(tmp);
				}
  | expression '+' expression	{
          // Generar codigo intermedio
          char *tmp = strdup("+");
          $$ = operacion($1, $3, tmp);
          free(tmp);
				}
  | expression '-' expression	{
  				// Generar codigo intermedio
          char *tmp = strdup("-");
          $$ = operacion($1, $3, tmp);
          free(tmp);
				}
  | expression '%' expression	{
  				// Generar codigo intermedio
          char *tmp = strdup("%");
          $$ = operacion($1, $3, tmp);
          free(tmp);
				}
  | ids	{
	 $$ = new_inter_symbol();
	 $$->type = $1->type;

   //Para el codigo intermedio
    sprintf($$->id, "%s", $1->id);
	}
  | CADENA	{
    $$ = new_inter_symbol();

    //Para el codigo intermedio
    sprintf($$->id, "\"%s\"", $1);
  }

  | NUMERO	{
		$$ = new_inter_symbol();
		$$->type = 0;

    // Para el codigo intermedio
    sprintf($$->id, "%d", $1);
		}
  | FLOTANTE	{
		$$ = new_inter_symbol();
		$$->type = 1;

    // Para el codigo intermedio
    sprintf($$->id, "%f", $1);
		}
  | CARACTER	{
    $$ = new_inter_symbol();
		$$->type = 3;

    //Para el codigo intermedio
    sprintf($$->id, "'%c'", $1);
		}
  | ID '(' arguments ')' {
    // Para el codigo intermedio 
    // falta hacer el llamado a la funcion aqui
    $$ = new_inter_symbol();

    // Temp
    char *tmp = get_temporal();
    insert_code("call", $1, "", tmp);

    strcpy($$->id, tmp);
    
    free(tmp);
  }
  ;

// H
arguments:
  arguments ',' expression	{
				$$ = new_inter_symbol();
        insert_code("push", $3->id, "", "");
				}
  | expression			{
				$$ = new_inter_symbol();
        insert_code("push", $1->id, "", "");
          			}
  ;

// B
logical:
  logical OR logical	{
			$$ = operacion($1, $3, "||");
			}
  | logical AND logical	{
			$$ = operacion($1, $3, "&&");
			}
  | '!' logical		{
			$$ = new_inter_symbol();
      char *tmp = get_temporal();
      insert_code("!", $2->id, "", tmp);
      strcpy($$->id, tmp);
      free(tmp);
			}
  | '(' logical ')'	{
			$$ = $2;
			}
  | expression relation expression	{
    $$ = operacion($1, $3, $2);

  }
  | TRUE_P	{
    $$ = new_inter_symbol();
    strcpy($$->id, "true");
  }
  | FALSE_P	{
    $$ = new_inter_symbol();
    strcpy($$->id, "false");
  }
  ;

relation:
  EQ	{
	strdup("==");
	}
  | NEQ	{
	$$ = strdup("!=");
	}
  | GE	{
	$$ = strdup(">=");
	}
  | '>'	{
	$$ = strdup(">");
	}
  | LE	{
	$$ = strdup("<=");
	}
  | '<'	{
	$$ = strdup("<");
	}
  ;

%%

void yyerror(char *s)
{
	fprintf(stderr, "%s en linea %d\n", s, yylineno);
}

void error(char *msg, int line)
{
	fprintf(stderr, "Error, line %d: %s\n", line, msg);
}

void init()
{
	table = init_sym_table();
  init_code();
}

symbol *operacion(symbol *arg1, symbol *arg2, char *op){
  symbol *res = new_inter_symbol();

  char *tmp = get_temporal();

  insert_code(op, arg1->id, arg2->id, tmp);

  strcpy(res->id, tmp);

  free(tmp);

  return res;
}

char *get_temporal(){
  temp++;
  char tmp[7];
  sprintf(tmp, "%c%d", 't', temp);

  return strdup(tmp);
}


int main(int argc, char** argv){
    if(argc>1){
        yyin = fopen(argv[1], "r");
        if(!yyin) return 1;
        yyparse();
        fclose(yyin);
    }
}
