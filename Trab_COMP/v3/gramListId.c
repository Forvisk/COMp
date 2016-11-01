#include "gram.h"

/*________________________________________________________________________________________*/
pListaAtributos createListTipo(int tipo){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = tipo;
	new->listaInt = NULL;
	new->listaStr = NULL;
	new->listaNotYet = NULL;

	return new;
}

pListaAtributos createList(pListaAtributos tipo){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = tipo->tipo;
	new->listaInt = NULL;
	new->listaStr = NULL;
	new->listaNotYet = NULL;
	
	free(tipo);
	return new;
}

/*________________________________________________________________________________________*/
pListaAtributos createAtributoList( char *nomeId){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = T_TODEF;
	new->listaInt = NULL;
	new->listaStr = NULL;
	new->listaNotYet = NULL;

	strncpy(new->nomeIdTemp, nomeId, 20);
	new->numTemp = 0;

	return new;
}

pListaAtributos createAtributoNum( int num){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = T_TODEF;
	new->listaInt = NULL;
	new->listaStr = NULL;
	new->listaNotYet = NULL;

	strncpy(new->nomeIdTemp, "", 20);
	new->numTemp = num;
	return new;
}

pAtributo createAtributo( char* nomeId){
	pAtributo new = (Atributo*)malloc(sizeof(Atributo));
	strncpy(new->nomeId, nomeId, 20);
	new->num = 0;
	new->proximo = NULL;
	int pos = getPosValGlobal();
	new->posVal = pos++;
	setPosValGlobal(pos);
	//printf("\nCriando Atributo\n\tNovo atributo: %s\n", new->nomeId);
	return new;
}

/*________________________________________________________________________________________*/
void addIdToList( pListaAtributos lista, pListaAtributos nomeId){
	int posAux = getPosValGlobal();
	pAtributo new = createAtributo(nomeId->nomeIdTemp);
	//printf("\nAdicionando a lista %p\n", (void*)lista);
	if( lista->tipo == T_INT){
		if(lista->listaInt == NULL){
			lista->listaInt = new;
			//printf("\tprimeiro inteiro %s\n", new -> nomeId);
		}else{
			if(verificaExistId( lista, new)){
				pAtributo aux = lista->listaInt;
				while( aux -> proximo != NULL)
					aux = aux -> proximo;

				aux->proximo = new;
				aux = aux -> proximo;
				//printf("\tnovo inteiro %s\n", aux->nomeId);
			}else{
				setPosValGlobal( posAux);
			}
		}
	}else if( lista->tipo == T_STR){
		if(lista->listaStr == NULL){
			lista->listaStr = new;
			//printf("\tprimeira string %s\n", new -> nomeId);
		}else{
			if(verificaExistId( lista, new)){
				pAtributo aux = lista->listaStr;
				while( aux -> proximo != NULL)
					aux = aux -> proximo;

				aux->proximo = new;
				aux = aux -> proximo;
				//printf("\tnova string %s\n", aux->nomeId);
			}else{
				setPosValGlobal( posAux);
			}
		}
	}else{
		//printf("\tLista sem tipo\n");
		if(lista->listaNotYet == NULL){
			lista->listaNotYet = new;
			//printf("\tprimeira not yet %s\n", new -> nomeId);
		}else{
			if(verificaExistId( lista, new)){

				pAtributo aux = lista->listaNotYet;
				while( aux -> proximo != NULL)
					aux = aux -> proximo;

				aux->proximo = new;
				aux = aux -> proximo;
				//printf("\tnova not yet %s\n", aux->nomeId);
			}else{
				setPosValGlobal( posAux);
			}
		}
	}
}

int verificaExistId( pListaAtributos lista, pAtributo id){
	pAtributo aux;
	if( lista->listaInt != NULL){
		//printf("Verificando inteiro\n");
		aux = lista->listaInt;
		do{
			//printf("\tverificando se %s == %s\n", aux->nomeId, id->nomeId);
			if( strncmp( aux->nomeId, id->nomeId, 20) == 0){
				//printf("\t%s ja existente\n", id->nomeId);
				return 0;
			}
			//printf("\tOK\n");
			aux = aux->proximo;
		}while(aux != NULL);
	}
	if( lista->listaStr != NULL){
		aux = lista->listaStr;
		do{
			//printf("\tverificando se %s == %s:", aux->nomeId, id->nomeId);
			if( strncmp( aux->nomeId, id->nomeId, 20) == 0){
				//printf("\t%s ja existente\n", id->nomeId);
				return 0;
			}
			//printf("\tOK\n");
			aux = aux->proximo;
		}while(aux != NULL);
	}
	//printf("\tverificação OK\n");
	return 1;
}

/*________________________________________________________________________________________*/
void setTipo( ListaAtributos* lista, int tipo){
	lista->tipo = tipo;
}

void addNumToAtributo( int num, char* nomeId){
	pAtributo atributo = buscaAtributo( nomeId);
	atributo -> num = num;
}

int getPosValId( char* nomeId){
	pAtributo atributo = buscaAtributo( nomeId);
	if( atributo != NULL){
		return atributo -> posVal;
	}else{
		printf("Atributo não existe\n");
		return INVAL;
	}
}