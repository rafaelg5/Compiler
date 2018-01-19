all:
	flex lexer.l
	bison -vd parser.y
	gcc parser.tab.c lex.yy.c sym_table.c type_table.c intermediate_code.c `pkg-config --cflags --libs glib-2.0` -lfl -o parser

tests:
	./parser prueba_logic

clean:
	cd src; rm a.out lex.yy.c *.tab.*;
