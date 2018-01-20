
all:
	flex lexer.l
	bison -vd parser.y
	gcc parser.tab.c lex.yy.c sym_table.c type_table.c intermediate_code.c `pkg-config --cflags --libs glib-2.0` -lfl -o parser

syntax:
	flex lexer.l
	bison -vd syntax.y
	gcc syntax.tab.c lex.yy.c sym_table.c type_table.c intermediate_code.c `pkg-config --cflags --libs glib-2.0` -lfl -o syntax

check-syntax: syntax
	./syntax prueba

tests:
	$(info Generando archivo Codigo_Intermedio.i)
	./parser prueba

clean:
	rm parser syntax lex.yy.c *.tab.* parser.output;
