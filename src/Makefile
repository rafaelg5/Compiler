all:
	flex lexer.l
	bison -vd parser.y
	gcc parser.tab.c lex.yy.c sym_table.c type_table.c intermediate_code.c `pkg-config --cflags --libs glib-2.0` -lfl -o parser

tests:
	./parser prueba

clean:
	rm parser lex.yy.c *.tab.*;
