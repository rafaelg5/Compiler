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
%type<att> type type_arr param_arr sents cases case_def ids arrays expression logical id_list arguments data
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
    // Create a new table and link it to the current one
      Sym_Table *new_table; 
      new_table = init_sym_table();
      new_table->parent = table;
      table->child = new_table;
      table = new_table;

    // Codigo intermedio
    insert_code("label","","", $3);
  }
  '(' params ')' '{' decs sents '}' 
  {
    // Table
    Sym_Table *prev = table;
    table = table->parent;

    char *tmp, *lab;
    tmp = (char*) malloc(strlen($3)+4);
    sprintf(tmp, "%s%s", "end", $3);

    int line = insert_code("label","","", tmp);
    backpatch($10->lnext, line);
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
  sents sents	
  {
    $$ = new_inter_symbol();

    backpatch($1->lnext, $2->first);

    $$->first = $1->first;
    $$->lnext = $2->lnext;
    $$->lbreaks = merge($1->lbreaks, $2->lbreaks);
  }
  | FOR '(' sents ';' logical ';' sents {

    int line = insert_code("goto", "", "", "");
    $7->lnext = insert_in_label($7->lnext, line);

    } ')' '{' sents	'}'
    {
      $$ = new_inter_symbol();

      char tmp[10];
      sprintf(tmp, "%d", $7->first);
      int line = insert_code("goto", "", "", tmp);

      $$->first = $3->first;

      backpatch($3->lnext, $5->first);

      backpatch($5->ltrue, $11->first);
      backpatch($11->lnext, $7->first);
      backpatch($7->lnext, $5->first);

      label temp = merge($3->lbreaks, $7->lbreaks);
      temp = merge($11->lbreaks, temp);

      $$->lnext = merge($5->lfalse, temp);
    }
  | DO '{' sents '}' WHILE '(' logical ')' ';'
  {
    $$ = new_inter_symbol();

    $$->first = $3->first;

    backpatch($3->lnext, $7->first);
    backpatch($7->ltrue, $3->first);

    $$->lnext = merge($7->lfalse, $7->lbreaks);
  }
  | WHILE '(' logical ')' '{' sents	'}'
  {
    $$ = new_inter_symbol();

    $$->first = $3->first;
    backpatch($3->ltrue, $6->first);
    backpatch($6->lnext, $3->first);

    $$->lnext = merge($3->lfalse, $6->lbreaks);

    char tmp[10];
    sprintf(tmp, "%d", $3->first);
    int line = insert_code("goto", "", "", tmp);
  }
  | IF '(' logical ')' sents %prec IFX	
  {
    $$ = new_inter_symbol();
    backpatch($3->ltrue, $5->first);

    $$->first = $3->first;
    $$->lnext = merge($3->lfalse, $5->lnext);
    $$->lbreaks = $5->lbreaks;
  }
  | IF '(' logical ')' sents ELSE sents	
  {
    $$ = new_inter_symbol();

    $$->first = $3->first;

    backpatch($3->ltrue, $5->first);
    backpatch($3->lfalse, $7->first);

    $$->lnext = merge($5->lnext, $7->lnext);
    $$->lbreaks = merge($5->lbreaks, $7->lbreaks);
  }
  | SWITCH '(' expression {
    aux_id = strdup($3->id);
  }')' '{' cases case_def '}'	
  {
    free(aux_id);
    $$ = new_inter_symbol();

    if($3->first != -1)
      $$->first = $3->first;
    else if($7->first != -1)
      $$->first = $7->first;
    else if($8->first != -1)
      $$->first = $8->first;
    else{
      int line = insert_code("nop", "", "", "");
      $$->first = line;
    }

    if($8->first != -1){
      backpatch($7->lnext, $8->first);
    }
    
    label temp = merge($7->lbreaks, $8->lbreaks);
    $$->lnext = merge(temp, $8->lnext);
  }
  | BREAK ';'	
  {
    $$ = new_inter_symbol();
    int line = insert_code("goto","","","");

    $$->first = line;
    $$->lbreaks = insert_in_label($$->lbreaks, line);
  }
  | PRINT expression ';'	
  {
    $$ = new_inter_symbol();

    int line = insert_code("print", $2->id, "", "");

    if($2->first == -1)
      $$->first = line;
    else
      $$->first = $2->first;
  }
  | RETURN expression ';'	
  {
    $$ = new_inter_symbol();

    int line = insert_code("return", $2->id, "", "");

    if($2->first == -1)
      $$->first = line;
    else
      $$->first = $2->first;
  }
  | RETURN ';'	
  {
    $$ = new_inter_symbol();
    int line = insert_code("return", "", "", "");
    $$->first = line;
  }
  | '{' sents '}'	{
			$$ = $2;
			}
  | ids '=' expression ';'	{
    $$ = new_inter_symbol();

    char *tmp = strdup("=");
    int line = insert_code(tmp, $3->id, "", $1->id);
    free(tmp);

    if($3->first == -1)
      $$->first = line;
    else
      $$->first = $3->first;
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
  CASE ':' NUMERO data {
    char tmp[20];
    sprintf(tmp, "%d", $3);
    strcpy(CODE.code[$4->ltrue.code_lines[$4->ltrue.size-1]].arg2, tmp);
  }
   sents cases {
    backpatch($4->ltrue, $6->first);

    $$ = new_inter_symbol(); 

    $$->first = $4->ltrue.code_lines[$4->ltrue.size-1];
    $$->lnext = merge($6->lnext, $4->lfalse);

    if($7->first != -1){
      backpatch($$->lnext, $7->first);
      $$->lnext = $7->lnext;
    }

    $$->lbreaks = merge($6->lbreaks, $7->lbreaks);


  }
  | %empty	{ $$ = new_inter_symbol();}
  ;

data:
  %empty {
    $$ = new_inter_symbol(); 
    char temp[10];
    sprintf(temp, "%d", 0);

    int line_true = insert_code("if==", aux_id, temp, "");
    int line_false = insert_code("goto","","","");

    $$->ltrue = insert_in_label($$->ltrue, line_true);
    $$->lfalse = insert_in_label($$->lfalse, line_false);
  }
  ;

case_def:
  DEFAULT ':' sents	
  {
    $$ = $3;
    
  }
  | %empty	{$$ = new_inter_symbol();}
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

    int line = insert_code("call", $1, "", tmp);
    strcpy($$->id, tmp);
    free(tmp);

    if($3->first == -1)
      $$->first = line;
    else
      $$->first = $3->first;
  }
  ;

// H
arguments:
  arguments ',' expression	{
				$$ = new_inter_symbol();
        int line = insert_code("push", $3->id, "", "");

        if($1->first != -1)
          $$->first = $1->first;
        else if($3->first != -1)
          $$->first = $3->first;
        else
          $$->first = line;
				}
  | expression			{
				$$ = new_inter_symbol();
        int line = insert_code("push", $1->id, "", "");
        
        if($1->first == -1)
          $$->first = line;
        else
          $$->first = $1->first;

      }
  ;

// B
logical:
  logical OR logical	{
      $$ = new_inter_symbol();
      backpatch($1->lfalse, $3->first);

      // first, ltrue, lfalse
      $$->first = $1->first;
      $$->ltrue = merge($1->ltrue, $3->ltrue);
      $$->lfalse = $3->lfalse;

			}
  | logical AND logical	{
			$$ = new_inter_symbol();
      backpatch($1->ltrue, $3->first);

      // first, ltrue, lfalse
      $$->first = $1->first;
      $$->ltrue = $3->ltrue;
      $$->lfalse = merge($1->lfalse, $3->lfalse);
			}
  | '!' logical		{
			$$ = new_inter_symbol();
      
      // first, ltrue, lfalse
      $$->first = $2->first;
      $$->ltrue = $2->lfalse;
      $$->lfalse = $2->ltrue;
      
			}
  | '(' logical ')'	{
			$$ = $2;
			}
  | expression relation expression	{
    $$ = new_inter_symbol();

    char *operacion = strdup("if1234");
    sprintf(operacion, "if%s", $2);

    int line_true = insert_code(operacion, $1->id, $3->id, "");
    int line_false = insert_code("goto", "", "", "");

    // first, ltrue, lfalse
    if($1->first == -1){
      if($3->first == -1){
        $$->first = line_true;
      } else {
        $$->first = $3->first;
      }
    } else{
      $$->first = $1->first;
    }
    
    $$->ltrue = insert_in_label($$->ltrue, line_true);
    $$->lfalse = insert_in_label($$->lfalse, line_false);

  }
  | TRUE_P	{
    $$ = new_inter_symbol();
    int line = insert_code("goto", "", "", "");

    // first, ltrue, lfalse
    $$->first = line;
    $$->ltrue = insert_in_label($$->ltrue, line);

  }
  | FALSE_P	{
    $$ = new_inter_symbol();
    int line = insert_code("goto", "", "", "");

    // first, ltrue, lfalse
    $$->first = line;
    $$->lfalse = insert_in_label($$->lfalse, line);
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
	fprintf(stderr, "Error: '%s'. Con el token '%s' en linea %d\n", s, yytext, yylineno);
  exit(1);
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

  // Codigo intermedio
  int line = insert_code(op, arg1->id, arg2->id, tmp);

  // Valores para compartir
  strcpy(res->id, tmp);

  if(arg1->first != -1)
    res->first = arg1->first;
  else if(arg2->first != -1)
    res->first = arg2->first;
  else 
    res->first = line;

  // Limpiar memoria
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
