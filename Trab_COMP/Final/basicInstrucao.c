#include "gramF.h"


pModulo criarValorNumerico( int valor){
	pModulo new = ( pModulo)malloc( sizeof(Modulo));

	new -> valor_temp = valor;

	return new;
}