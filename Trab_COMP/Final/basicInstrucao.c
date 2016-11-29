#include "gramF.h"


pModulo criarValorNumerico( int valor){
	pModulo new = ( pModulo)malloc( sizeof(Modulo));

	new -> valor_temp = valor;

	return new;
}

pModulo criarLiteral( char* literal){
	pModulo new = ( pModulo)malloc( sizeof(Modulo));

	new -> literal_temp = ( char*)malloc( sizeof( strlen( literal) + 1));
	strcpy( new -> literal_temp, literal);

	return new;
}