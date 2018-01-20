# Compiler
Compiler

Tipos de comentarios:
	// de linea
	/* multilinea */

Cambios a la gramatica para evitar ambiguedad
S -> while( B ) { S1 } 
	| do { S1 } while( B ); 
	| for( S1; B; S2){ S3 }


Que puede hacer:
	[4] Reconoce el 100% de los tokens
	[4] Reconoce mas de un tipo comentarios haciendo uso de estados léxicos en lex
	[4] Hace reconocimiento de errores léxicos, reportando el número de línea donde ocurrió el error
	[4] El programa en lex compila, y tiene una estructura bien definida
	[4] Reconoce el 100% de la gramática
	[4] Reporta el tipo de error, la línea y token con el que ocurrio el error
	[4] En el archivo yacc se hace una clara división entre el análisis sintáttico y semántico