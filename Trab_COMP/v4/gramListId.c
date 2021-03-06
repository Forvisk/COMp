#include "gram.h"

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createGreatList(){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new -> lista = NULL;
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void addToGreatList( pListaAtributos newlista){
	//printf("\nAdicionando a greatList:\n");
	//putsListId( newlista);

	pListaAtributos greatList = getGreatList();

	if( newlista -> lista == NULL){
		//printf("Lista vazia\n");

	}else{
		pAtributo aux = newlista -> lista;
		pAtributo auxGreat = greatList -> lista;
		pAtributo auxDel;
		
		do{
			if( greatList -> lista == NULL){
				if( existeId( greatList, aux)){
					greatList -> lista = createAtributo( aux -> nomeId);
					auxGreat = greatList -> lista;
					auxGreat -> proximo = NULL;
					//printf("\tprimeiro simbolo da greatList: %s\n", auxGreat->nomeId);
				}
			}else{
				while( auxGreat -> proximo != NULL){
					//printf("\tGreatList : %s\n", auxGreat->nomeId);
					auxGreat = auxGreat -> proximo;
				}
				if( existeId( greatList, aux)){
					auxGreat -> proximo = createAtributo( aux -> nomeId);
					auxGreat = auxGreat -> proximo;
					//printf("\tnovo simbolo na greatList: %s\n", auxGreat->nomeId);
				}
			}

			auxDel = aux;
			aux = aux -> proximo;
			free( auxDel);
		}while( aux != NULL);
	}
		
	free(newlista);
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pAtributo createAtributo( char* nomeId){
	pAtributo new = (Atributo*)malloc(sizeof(Atributo));
	strncpy(new->nomeId, nomeId, 20);
	//printf("\n\tNovo atributo: %s\n", new->nomeId);
	new -> proximo = NULL;
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createList(){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->lista = NULL;
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createId( char *nomeId){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->lista = NULL;
	strncpy(new->nomeIdTemp, nomeId, 20);
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void addIdToList( pListaAtributos listaFinal, pListaAtributos lista){
	pAtributo new = createAtributo( lista -> nomeIdTemp);
	//printf(" %s\n", lista -> nomeIdTemp);
	if( listaFinal -> lista == NULL){
		//printf("Lista %p vazia primeiro simbolo %s\n", listaFinal, new -> nomeId);
		listaFinal -> lista = new;
	}else{
		pAtributo aux = listaFinal -> lista;
		while( aux -> proximo != NULL)
			aux = aux -> proximo;
		aux -> proximo = new;
		aux = aux -> proximo;
		//printf("Adicionando em %p o simbolo %s\n", listaFinal, aux -> nomeId);
	}
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createNum( int num){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->lista = NULL;
	new->numTemp =  num;

	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int existeId( pListaAtributos lista, char* nomeId){
	if( lista -> lista == NULL){
		return 1;
	}else{
		pAtributo aux = lista -> lista;
		do{
			//printf("Verificando se %s == %s\n", aux -> nomeId, nomeId);
			if( strncmp( aux -> nomeId, nomeId, 20) == 0)
				return 0;
			aux = aux -> proximo;
		}while( aux != NULL);
	}
	return 1;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
