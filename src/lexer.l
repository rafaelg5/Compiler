%{
#include <stdlib.h>
//#include "parser.tab.h"

extern void yyerror(char*);

int commentDepth = 0;
%}

%x comment

%option noyywrap
%option yylineno

id [a-zA-Z_][a-zA-Z0-9_]*
integer [0-9]+
blank [ \t\n]
operator [-+\*\/%=!<>]
misc [.;:,{}\[\]()]

%%

<comment>
{
\n  { ++yylineno; }
"*/"  { commentDepth--; if(commentDepth == 0) BEGIN(INITIAL); }
"/*"  { commentDepth++; }
<<EOF>> { yyerror("Comentario sin cerrar"); }
[^*/\n]*  { } // ignorar todo lo que no sea '*' o '/'
. { } // Ignorar cualquier otro caracter
}

int { return INT; }

double  { return DOUBLE; }

float { return FLOAT; }

char  { return CHAR; }

void  { return VOID; }

struct  { return STRUCT; }

if  { return IF; }

else  { return ELSE; }

while { return WHILE; }

do  { return DO; }

for { return FOR; }

switch  { return SWITCH; }

return  { return RETURN; }

break { return BREAK; }

case  { return CASE; }

default { return DEFAULT; }

true  { return TRUE; }

false { return FALSE; }

func  { return FUNC; }

print { return PRINT; }

{misc}  { return *yytext; }

{operator}  { return *yytext; }

"||"  { return OR; }

"&&"  { return AND; }

">="  { return GE; }

"<="  { return LE; }

"!="  { return NEQ; }

"=="  { return EQ; }

\"[^\"\n\0<<EOF>>]*\" {
                        yytext[strlen(yytext)-1]='\0';
                        yylval.cad = strdup(yytext+1);
                        return CADENA;
                      }

\'\\.\' {
          yylval.car = strdup(yytext);
          return CARACTER;
        }

{integer} {
            yylval.num = atoi(yytext);
            return NUMERO;
          }

({integer}[.])?{integer}  {
                            yylval.flo = atof(yytext);
                            return FLOTANTE;
                          }

{blank} {}

{id}  {
        strcpy(yylval.id, yytext);
        return ID;
      }

. { printf("ERROR: %s en la línea %d\n", yytext, yylineno); }

%%
