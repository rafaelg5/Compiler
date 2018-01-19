



all:
	cd src; echo Usando Flex con lexer.l; flex lexer.l; echo Usando bison con parser.y; bison parser.y; bison -d parser.y; echo Compilando con gcc; gcc -g parser.tab.c type_table.c sym_table.c intermediate_code.c lex.yy.c;

tests:
	src/a.out src/prueba

clean:
	cd src; rm a.out lex.yy.c *.tab.*;