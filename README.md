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

GESTOR DE TIPOS				¿El gestor de tipos valida?
DECLARACION DE VARIABLES	¿Se revisa que las variables no se dupliquen al declaradas, se valida que antes de usarlas estas se hayan declarado?
ERRORES SEMANTICOS			¿Reporta el tipo de error, la línea y token con el que ocurrio el error semantico?
TABLAS DE SIMBOLOS Y PILA	¿Se maneja una estructura dinámica para el manejo de la tabla de símbolos y funciona correctamente?
TABLAS DE TIPOS 			¿Se hace uso de una estructura en memoria dinámica y funciona?

	
	[4] Se genera código intermedio de todas las partes de la gramática donde se puede generar código
				El codigo intermedio se produce en el archivo "Codigo_Intermedio.i"

CODIGO OBJETO				¿Se genera del código intermedio, el código objeto usando algun algoritmo de generación optimo?


