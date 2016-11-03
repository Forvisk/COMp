#include "gram.h"

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createLit( char* literal){
	pListaAtributos new = ( ListaAtributos*)malloc( sizeof(ListaAtributos));
	new -> lista = NULL;
	new->literal = ( char*)malloc( sizeof(strlen(literal)+1));
	strcpy( new -> literal, literal);
	//printf("%s\n", new->literal);
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaLiteral createPrimeiroLiteral( pListaAtributos literal){
	pListaLiteral primeiro = ( ListaLiteral*)malloc( sizeof( ListaLiteral));
	primeiro -> literal = ( char*)malloc( sizeof(strlen(literal -> literal)+1));
	strcpy( primeiro -> literal, literal -> literal);
	primeiro -> proximo = NULL;
	return primeiro;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

char* addLiteralLista( pListaAtributos literal){
	pListaLiteral new = ( ListaLiteral*)malloc( sizeof( ListaLiteral));
	new -> literal = ( char*)malloc( sizeof( strlen( literal -> literal) + 1));
	strcpy( new -> literal, literal -> literal);
	new -> proximo = NULL;
	pListaLiteral aux = getListaLiteral();
	
	if( aux == NULL){
		//printf("lista vazia\n");
		setPrimeiroListaLiteral( new);
		aux = getListaLiteral();
	} else{
		while( aux -> proximo != NULL)
			aux = aux -> proximo;
		aux -> proximo = new;
		aux = aux -> proximo;
	}
	//printf("%s\n", aux -> literal);
	return aux -> literal;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
