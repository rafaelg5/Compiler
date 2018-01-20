%{
#include <stdlib.h>
#include "parser.tab.h"

extern void yyerror(char*);

int commentDepth = 0;
%}

%x comment
%x linecomment

%option noyywrap
%option yylineno

id [a-zA-Z_][a-zA-Z0-9_]*
integer [0-9]+
blank [ \f\r\t\v]
operator [-+\*\/%=!<>]
misc [.;:,{}\[\]()]

%%

\n  ++yylineno;
{blank}+  ;

"/*" BEGIN(comment);
"//" BEGIN(linecomment);

<comment>[^*\n]*        {}
<comment>"*"+[^*/\n]*   {}
<comment>\n             ++yylineno;
<comment>"*"+"/"        BEGIN(INITIAL);
<comment><<EOF>>        yyerror("Comentario sin cerrar");

<linecomment>\n         {++yylineno; BEGIN(INITIAL);}
<linecomment>.   {}


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

true  { return TRUE_P; }

false { return FALSE_P; }

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

                        yylval.cad = (char*)malloc(strlen(yytext));
                        yylval.cad = strdup(yytext+1);
                        return CADENA;
                      }

\'\\.\' {
          yylval.cad = (char*)malloc(strlen(yytext));
          yylval.cad = strdup(yytext);
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

{id}  {
        yylval.id = (char*)malloc(strlen(yytext));
        strcpy(yylval.id, yytext);
        return ID;
      }

. { printf("ERROR LEXICO: %s en la línea %d\n", yytext, yylineno); }

%%
