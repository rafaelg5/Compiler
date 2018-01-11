%{
#include <stdlib.h>

extern void yyerror(char*);

int commentDepth = 0;
%}

%x comment

%option noyywrap
%option yylineno

id [a-zA-Z_][a-zA-Z0-9_]*
integer [0-9]+
blank [ \t\n]
operator [+-*/%=!<>]
misc [.;:,{}[]()]

%%

<comment> {
            \n  { ++yylineno; }
            "*/"  { commentDepth--; if(commentDepth == 0) BEGIN(INITIAL); }
            "/*"  { commentDepth++; }
            <<EOF>> { yyerror("Comentario sin cerrar"); }
            [^*/\n]*  { } // ignorar todo lo que no sea '*' o '/'
            . { } // Ignorar cualquier otro caracter
          }

int { yylval.line = yylineno; return INT; }

double  { yylval.line = yylineno; return DOUBLE; }

float { yylval.line = yylineno; return FLOAT; }

char  { yylval.line = yylineno; return CHAR; }

void  { yylval.line = yylineno; return VOID; }

struct  { yylval.line = yylineno; return STRUCT; }

if  { yylval.line = yylineno; return IF; }

else  { yylval.line = yylineno; return ELSE; }

while { yylval.line = yylineno; return WHILE; }

do  { yylval.line = yylineno; return DO; }

for { yylval.line = yylineno; return FOR; }

switch  { yylval.line = yylineno; return SWITCH; }

return  { yylval.line = yylineno; return RETURN; }

break { yylval.line = yylineno; return BREAK; }

case  { yylval.line = yylineno; return CASE; }

default { yylval.line = yylineno; return DEFAULT; }

true  { yylval.line = yylineno; yylval.nval = 1; return TRUE; }

false { yylval.line = yylineno; yylval.nval = 0; return FALSE; }

func  { yylval.line = yylineno; return FUNC; }

print { yylval.line = yylineno; return PRINT; }

{misc}  { yylval.line = yylineno; return *yytext; }

{operator}  { yylval.line = yylineno; return *yytext; }

"||"  { yylval.line = yylineno; return OR; }

"&&"  { yylval.line = yylineno; return AND; }

">="  { yylval.line = yylineno; return GTE; }

"<="  { yylval.line = yylineno; return LTE; }

"!="  { yylval.line = yylineno; return NE; }

"=="  { yylval.line = yylineno; return EQ; }

\"[^\"\n\0<<EOF>>]*\" {
                        yylval.line = yylineno;
                        yytext[strlen(yytext)-1]='\0';
                        yylval.sval = strdup(yytext+1);
                        return STRING;
                      }

\'\\.\' {
          yylval.line = yylineno;
          yylval.sval = strdup(yytext);
          return CHARACTER;
        }

{integer} {
            yylval.line = yylineno;
            yylval.nval = atoi(yytext);
            return NUM;
          }

({integer}[.])?{integer}  {
                            yylval.line = yylineno;
                            yylval.nval = atoi(yytext);
                            return DECIMAL;
                          }

{blank} {}

{id}  {
        yylval.line = yylineno;
        strcpy(yylval.sval, yytext);
        return ID;
      }

. { printf("ERROR: %s en la línea %d\n", yytext, yylineno); }

%%
