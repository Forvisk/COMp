
#include "gramv2.h"

extern FILE *yyin;

#define ARQUIVO1 "Exemlo1.c"
#define ARQUIVO2 "Exemlo2.c"
#define ARQUIVO3 "Exemlo3.c"

/*
*	Adriano Zanella Junior
*	
*/

pListaAtributos greatList;
Instrucao listaInstrucao[200];

int posValGlobal = 1;

int main(int argc, char const *argv[])
{
	greatList = createGreatList();
	yyin = fopen( argv[ 1], "r");
	if( yyin != NULL){
		yyparse();
	}else{
		printf("Arquivo nao encontrado!");
	}
	fclose(yyin);

	//test();
	putsListId(greatList);
	return 0;
}

pListaAtributos createGreatList(){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = T_GREAT_LIST;
	new->listaInt = NULL;
	new->listaStr = NULL;

	return new;
}

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

void setTipo( ListaAtributos* lista, int tipo){
	lista->tipo = tipo;
}

pListaAtributos createAtributoList( char *nomeId){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = T_TODEF;
	new->listaInt = NULL;
	new->listaStr = NULL;
	new->listaNotYet = NULL;
	strncpy(new->nomeIdTemp, nomeId, 20);

	return new;
}

pAtributo createAtributo( char* nomeId){
	pAtributo new = (Atributo*)malloc(sizeof(Atributo));
	strncpy(new->nomeId, nomeId, 20);
	new->num = 0;
	new->proximo = NULL;
	new->posVal = posValGlobal;
	posValGlobal++;
	//printf("\nCriando Atributo\n\tNovo atributo: %s\n", new->nomeId);
	return new;
}

void addIdToList( pListaAtributos lista, pListaAtributos nomeId){
	int posAux = posValGlobal;
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
				posValGlobal = posAux;
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
				posValGlobal = posAux;
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
				posValGlobal = posAux;
			}
		}
	}
}


void addToGreatList( pListaAtributos newlista){
	//printf("\nAdicionando a greatList:\n");
	if( newlista -> tipo == T_INT){
		if( newlista -> listaInt == NULL){
			//printf("Lista vazia\n");
		}else{
			pAtributo aux = newlista -> listaInt;
			pAtributo auxGreat = greatList -> listaInt;
			pAtributo auxDel;
			
			do{
				if( greatList -> listaInt == NULL){
					if( verificaExistId( greatList, aux)){
						greatList -> listaInt = createAtributo( aux -> nomeId);
						auxGreat = greatList -> listaInt;
						//printf("\tprimeiro inteiro da greatList: %s\n", auxGreat->nomeId);
					}
				}else{
					while( auxGreat -> proximo != NULL){
						//printf("\t\tGreatList : %s\n", auxGreat->nomeId);
						auxGreat = auxGreat -> proximo;
					}
					if( verificaExistId( greatList, aux)){
						auxGreat -> proximo = createAtributo( aux -> nomeId);
						auxGreat = auxGreat -> proximo;
						//printf("\tnovo inteiro na greatList: %s\n", auxGreat->nomeId);
					}
				}
				auxDel = aux;
				aux = aux -> proximo;
				free( auxDel);
			}while( aux != NULL);
		}

		if( newlista -> listaNotYet != NULL){
			pAtributo aux = newlista -> listaNotYet;
			pAtributo auxGreat = greatList -> listaInt;
			pAtributo auxDel;
			
			do{
				if( greatList -> listaInt == NULL){
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						greatList -> listaInt = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = greatList -> listaInt;
						//printf("\tprimeiro inteiro notyet da greatList: %s\n", auxGreat->nomeId);
					}
				}else{
					while( auxGreat -> proximo != NULL){
						//printf("\t\tGreatList : %s\n", auxGreat->nomeId);
						auxGreat = auxGreat -> proximo;
					}
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						auxGreat -> proximo = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = auxGreat -> proximo;
						//printf("\tnovo inteiro notyet na greatList: %s\n", auxGreat->nomeId);
					}
				}
				auxDel = aux;
				aux = aux -> proximo;
				free( auxDel);

			}while( aux != NULL);
			newlista -> listaNotYet = NULL;
		}

	}else if( newlista -> tipo == T_STR){
		if( newlista -> listaStr == NULL){
			//printf("Lista Not Yet vazia\n");
		}else{
			pAtributo aux = newlista -> listaStr;
			pAtributo auxGreat = greatList -> listaStr;
			pAtributo auxDel;
			do{
				if( greatList -> listaStr == NULL){
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						greatList -> listaStr = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = greatList -> listaStr;
						//printf("\tprimeiro string da greatList: %s\n", auxGreat->nomeId);
					}
				}else{
					while( auxGreat -> proximo != NULL){
						//printf("\t\tGreatList : %s\n", auxGreat->nomeId);
						auxGreat = auxGreat -> proximo;
					}
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						auxGreat -> proximo = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = auxGreat -> proximo;
						//printf("\tnovo string na greatList: %s\n", auxGreat->nomeId);
					}
				}
				auxDel = aux;
				aux = aux -> proximo;
				free( auxDel);
			}while( aux != NULL);
		}

		if( newlista -> listaNotYet != NULL){
			pAtributo aux = newlista -> listaNotYet;
			pAtributo auxGreat = greatList -> listaStr;
			pAtributo auxDel;
			
			do{
				if( greatList -> listaStr == NULL){
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						greatList -> listaStr = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = greatList -> listaStr;
						//printf("\tprimeiro string notyet da greatList: %s\n", auxGreat->nomeId);
					}
				}else{
					while( auxGreat -> proximo != NULL){
						//printf("\t\tGreatList : %s\n", auxGreat->nomeId);
						auxGreat = auxGreat -> proximo;
					}
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						auxGreat -> proximo = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = auxGreat -> proximo;
						//printf("\tnovo string notyet na greatList: %s\n", auxGreat->nomeId);
					}
				}
				auxDel = aux;
				aux = aux -> proximo;
				free( auxDel);
			}while( aux != NULL);
			newlista -> listaNotYet = NULL;
		}
	}else if( newlista -> tipo == T_TODEF){
		if( newlista -> listaNotYet  != NULL){
			pAtributo aux = newlista -> listaNotYet;
			pAtributo auxGreat = greatList -> listaNotYet;
			pAtributo auxDel;
			do{
				if( greatList -> listaStr == NULL){
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						greatList -> listaStr = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = greatList -> listaNotYet;
						//printf("\tprimeiro string da greatList: %s\n", auxGreat->nomeId);
					}
				}else{
					while( auxGreat -> proximo != NULL){
						//printf("\t\tGreatList : %s\n", auxGreat->nomeId);
						auxGreat = auxGreat -> proximo;
					}
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						auxGreat -> proximo = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = auxGreat -> proximo;
						//printf("\tnovo string na greatList: %s\n", auxGreat->nomeId);
					}
				}
				auxDel = aux;
				aux = aux -> proximo;
				free( auxDel);
			}while( aux != NULL);
		}
	}else{
		printf("Erro na lista a ser inserida\n");
	}
	free(newlista);
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


void putsListId( pListaAtributos lista){
	printf("\nLista %p:\n", (void*)lista);
	if( lista->tipo == T_TODEF){
		printf("\tLista sem tipo\n");
	}
	if( lista->listaInt != NULL){
		pAtributo aux = lista->listaInt;
		do{
			printf("\tinteiro\t%s\t%i\n", aux->nomeId, aux->posVal);
			aux = aux->proximo;
		}while( aux != NULL);
	}
	if( lista->listaStr != NULL){
		pAtributo aux = lista->listaStr;
		do{
			printf("\tstring\t%s\t%i\n", aux->nomeId, aux->posVal);
			aux = aux->proximo;
		}while( aux != NULL);
	}
	if( lista->listaNotYet != NULL){
		pAtributo aux = lista->listaNotYet;
		do{
			printf("\tnot yet\t%s\t%i\n", aux->nomeId, aux->posVal);
			aux = aux->proximo;
		}while( aux != NULL);
	}
}

void test(){
	pListaAtributos testTipoInt = createListTipo(T_INT);
	pListaAtributos testTipoStr = createListTipo(T_STR);

	pListaAtributos testListaInt1 = createList( testTipoInt);
	
	pListaAtributos atr =  createAtributoList( "a");
	addIdToList(testListaInt1, atr);
	//putsListId(testListaInt1);

	atr = createAtributoList( "b");
	addIdToList(testListaInt1, atr);
	//putsListId(testListaInt1);

	atr = createAtributoList( "a");
	addIdToList(testListaInt1, atr);
	//putsListId(testListaInt1);

	atr = createAtributoList( "c");
	addIdToList(testListaInt1, atr);
	//putsListId(testListaInt1);

	atr = createAtributoList( "b");
	addIdToList(testListaInt1, atr);
	//putsListId(testListaInt1);

	addToGreatList(testListaInt1);

	
	pListaAtributos testListaStr1 = createList( testTipoStr);

	atr = createAtributoList( "st1");
	addIdToList(testListaStr1, atr);
	//putsListId(testListaStr1);

	atr = createAtributoList( "bk1");
	addIdToList(testListaStr1, atr);
	//putsListId(testListaStr1);

	atr = createAtributoList( "b");
	addIdToList(testListaStr1, atr);
	//putsListId(testListaStr1);

	atr = createAtributoList( "ok");
	addIdToList(testListaStr1, atr);
	//putsListId(testListaStr1);

	atr = createAtributoList( "bk1");
	addIdToList(testListaStr1, atr);
	//putsListId(testListaStr1);

	atr = createAtributoList( "a");
	addIdToList(testListaStr1, atr);
	//putsListId(testListaStr1);

	atr = createAtributoList( "Wahaha");
	addIdToList(testListaStr1, atr);
	//putsListId(testListaStr1);/

	addToGreatList( testListaStr1);
	
}
