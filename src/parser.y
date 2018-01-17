%{
  #include <string.h>
  #include <stdio.h>
  #include "symbol.h"

  extern FILE *yyin;
  extern FILE *yyout;
  extern int yylex();
  extern int yylineno;
  extern char *yytext;
  void yyerror(char *s);

  // inherited vars
  int inh_type, inh_dim;

%}

%start program

%union {
  char car[32];
  int num;
  double flo;
  char *cad;
  char *id;
}

%token INT DOUBLE FLOAT CHAR VOID STRUCT
%token CARACTER NUMERO FLOTANTE CADENA
%token SWITCH CASE BREAK DEFAULT
%token FOR IF ELSE DO WHILE
%token FUNC RETURN PRINT
%token TRUE FALSE ID LE GE EQ NEQ AND OR

%type<car> CARACTER
%type<num> NUMERO
%type<flo> FLOTANTE
%type<cad> CADENA
%type<att> type_arr param_arr param_list sents params cases case_default ids arrays expression logical relational

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
  decs funcs
  ;

// D -> T L; D | epsilon
decs:
  type  {
	inh_type = $1.type;
	inh_dim = $1.dim;
	}
  id_list ';' decs
  | %empty
  ;

// T -> buncha types
type:
  INT  		{
		$$ = new_symbol();
		$$.type = 0;
		$$.dim = 4;
		}
  | FLOAT  	{
		$$ = nuevo_simbolo_gram();
            	$$.type = 1;
            	$$.dim = 4;
           	}
  | DOUBLE	{
            	$$ = nuevo_simbolo_gram();
            	$$.type = 2;
            	$$.dim = 8;
            	}
  | CHAR	{
            	$$ = nuevo_simbolo_gram();
            	$$.type = 3;
            	$$.dim = 1;
            	}
  | VOID	{
            	$$ = nuevo_simbolo_gram();
            	$$.type = 4;
            	$$.dim = 0;
            	}
  | STRUCT '{' decs '}'
  ;

// L -> L, id C | id C
id_list:
  id_list ',' ID type_arr
  | ID type_arr
  ;

// C -> [ numero ] C | epsilon
type_arr:
  '[' NUMERO ']' type_arr	{
				$$ = $4;
				$$.is_arr = 1;
				$$.type = $4.type;
				$$.dim = $2 * $4.dim;
				}
  | %empty			{
				$$ = new_symbol();
				$$.type = inh_type;
				$$.dim = inh_dim
				}
  ;

// F -> func T id( A ){ D S } F_1 | epsilon
funcs:
  FUNC type ID '(' params ')' '{' decs sents '}' funcs
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
  param_list	{
		$$ = $1;
		}
  ',' type	{
		inh_type = $4.type;
		inh_dim = $4.dim;
		}
  ID param_arr
  | type	{
		inh_type = $1.type;
		inh_dim = $1.dim;
		$$ = NULL;
		}
  ID param_arr
  ;

param_arr:
  '[' ']' param_arr	{
			$$ = $3;
			$$.dim = 8;
			$$.is_arr = 1;
			$$.type = $3.type;
			}
  | %empty	{
		$$ = new_symbol();
		$$.type = inh_type;
		$$.dim = inh_dim;
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
  | $empty	{}
  ;

case_def:
  DEFAULT ':' sents	{}
  | %empty	{}
  ;

expression:
  expression '*' expression	{
				$$ = new_symbol();
				}
  | expression '/' expression	{
				$$ = new_symbol();
				}
  | expression '+' expression	{
				$$ = new_symbol();
				}
  | expression '-' expression	{
				$$ = new_symbol();
				}
  | expression '%' expression	{
				$$ = new_symbol();
				}
  | ids	{
	$$ = new_symbol();
	$$.type = $1.type;
	}
  | CADENA	{}

  | NUMERO	{
		$$ = new_symbol();
		$$.type = 0;
		}
  | FLOTANTE	{
		$$ = new_symbol();
		$$.type = 1;
		}
  | CARACTER	{
		$$.type = 3;
		}
  | ID '(' params ')' {}
  ;

// H
params:
  params ',' expression	{
			$$ = new_symbol();
			}
  | expression		{
			$$ = new_symbol();
          		}
  ;

// B
logical:
  logical OR logical	{
			$$ = new_symbol();
			}
  | logical AND logical	{
			$$ = nuevo_simbolo();
			}
  | '!' logical		{
			$$ = new_symbol();
			}
  | '(' logical ')'	{
			$$ = $2;
			}
  | expression relation expression	{}
  | TRUE	{}
  | FALSE	{}
  ;

relation:
  '<'	{
	$$ = $1;
	}
  | '>'	{
	$$ = $1;
	}
  | GE	{
	$$ = $1;
	}
  | LE	{
	$$ = $1;
	}
  | NEQ	{
	$$ = $1;
	}
  | EQ	{
	$$ = $1;
	}
  ;

%%
