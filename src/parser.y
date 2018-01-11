%{

  #include <stdio.h>
  //#include "semantic.tab.h"
  extern FILE *yyin;
  extern int yylex();
  void yyerror(char *s);

%}

%union {
    char sval[32];
    int nval;
    double dval;
    int line;
}

%token <sval> ID STRING CHARACTER
%token <nval> NUM TRUE FALSE
%token <dval> DECIMAL
%token INT DOUBLE FLOAT CHAR
%token VOID STRUCT
%token IF WHILE DO FOR SWITCH RETURN BREAK CASE DEFAULT
%token FUNC PRINT

%left '='
%left OR
%left AND
%left EQ NE
%left GTE LTE
%left '+' '-'
%left '*' '/' '%'
%nonassoc '!'
%nonassoc '(' ')'
%left IFX
%left ELSE
