#include "gram.h"

pListaAtributos createLit( char* literal){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new -> lista = NULL;
	new->literal = (char*)malloc( sizeof(strlen(literal)+1));
	strcpy( new -> literal, literal);
	//printf("%s\n", new->literal);
	return new;
}