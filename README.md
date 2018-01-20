# Compiler
Compilador con flex, bison y glib que produce codigo intermedio
Escrito en el lenguaje c

Requisitos:
	Glib

Como ejecutarlo:
	Entrar a la carpeta src:
		> cd src

	Se ejecuta con los siguientes comandos:
		> make
		> ./parser [ARCHIVO]

	Se provee con un archivo de prueba, este se puede ejecutar con:
		> make tests
		o
		> ./parser prueba

	Ademas se puede lanzar solamente el analizador sintactico
		> make check-syntax



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
	[4] Reporta el tipo de error, la línea y token con el que ocurrio el error sintactico
	[4] En el archivo yacc se hace una clara división entre el análisis sintáttico y semántico
	[3] El programa en yacc compila, pero manda mensajes de advertencia, aunque se ejecuta de forma correcta
	[4] El gestor de tipos valida los tipos, hace conversion de tipos para operar con ellos.
	[4] Se valida revisa que las variables no sean duplicadas, y sean declaradas antes de usarse.
	[3] Reporta el tipo de error, y la linea con la que ocurrio el error.
	[4] Se maneja una estructura dinamica para el manejo de la tabla de simbolos y funciona correctamente.
	[4] Se hace uso de una estructura en memoria dinamica y funciona.
	[4] Se genera codigo intermedio de todas las partes de la gramatica donde se puede generar codigo. El codigo intermedio se produce en el archivo "Codigo_Intermedio.i"
	[0] No se genera codigo objeto.
