
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

int main(int argc, char const *argv[])
{
	greatList = createGreatList();
	/*yyin = fopen( argv[ 1], "r");
	if( yyin != NULL){
		yyparse();
	}else{
		printf("Arquivo nao encontrado!");
	}
	fclose(yyin);*/

	test();
	printf("Sucesso\n");
	return 0;
}

pListaAtributos createGreatList(){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = T_GREAT_LIST;
	new->listaInt = NULL;
	new->listaStr = NULL;

	return new;
}

pListaAtributos createListaPeloTipo(int tipo){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = tipo;
	new->listaInt = NULL;
	new->listaStr = NULL;

	return new;
}

pListaAtributos createList(pListaAtributos tipo){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = tipo->tipo;
	new->listaInt = NULL;
	new->listaStr = NULL;
	
	free(tipo);
	return new;
}

void setTipo( ListaAtributos* lista, int tipo){
	lista->tipo = tipo;
}

pAtributo createAtributo( char* nomeId){
	pAtributo new = (Atributo*)malloc(sizeof(Atributo));
	strncpy(nomeId, new->nomeId, 20);
	new->proximo = NULL;
	
	return new;
}

void addIdToList( ListaAtributos* lista, Atributo* id){
	if( lista->tipo == T_INT){
		if(lista->listaInt == NULL){
			lista->listaInt = id;
		}else{
			if(verificaExistId( lista, id)){
				pAtributo aux = lista->listaInt;
				while(aux->proximo != NULL)
					aux = aux->proximo;
				aux->proximo = id;
			}
		}
	}else if( lista->tipo == T_STR){
		if(lista->listaStr == NULL){
			lista->listaStr = id;
		}else{
			if(verificaExistId( lista, id)){
				pAtributo aux = lista->listaStr;
				while( aux->proximo != NULL)
					aux = aux->proximo;
				aux->proximo = id;
			}
		}
	}
}


void addToGreatList( pListaAtributos newlista){
	if( newlista -> tipo == T_INT){
		if( newlista -> listaInt == NULL){
			printf( "Lista vazia\n");
		}else{
			pAtributo aux = newlista -> listaInt;
			do{
				if( aux != NULL){
					if( verificaExistId( greatList, aux)){
						printf("Atributo %s adicionado como inteiro\n", aux->nomeId);
						if( greatList->listaInt == NULL){
							printf("Primeio inteiro\n");
							greatList->listaInt = aux;
						}else{
							pAtributo auxGreat = greatList->listaInt;
							if( auxGreat -> proximo != NULL){
								do{
									auxGreat = auxGreat -> proximo;
								}while( auxGreat -> proximo != NULL);
								auxGreat->proximo = aux;
							}
						}
					}else{
						printf("Atributo %s ja existente\n", aux->nomeId);
					}
				}
			}while( aux->proximo != NULL);
		}
	}else if( newlista -> tipo == T_STR){
		if( newlista -> listaStr == NULL){
			printf( "Lista vazia\n");
		}else{
			pAtributo aux = newlista -> listaInt;
			do{
				if( aux != NULL){
					if( verificaExistId( greatList, aux)){
						printf("Atributo %s adicionado como string\n", aux->nomeId);
						if( greatList->listaStr == NULL){
							printf("Primeio inteiro\n");
							greatList->listaStr = aux;
						}else{
							pAtributo auxGreat = greatList->listaInt;
							if( auxGreat -> proximo != NULL){
								do{
									auxGreat = auxGreat -> proximo;
								}while( auxGreat -> proximo != NULL);
								auxGreat->proximo = aux;
							}
						}
					}else{
						printf("Atributo %s ja existente\n", aux->nomeId);
					}
				}
			}while( aux->proximo != NULL);
		}
	}else{
		printf("Erro na lista a ser inserida\n");
	}
}

int verificaExistId( pListaAtributos lista, pAtributo id){
	pAtributo aux;
	if( lista->listaInt != NULL){
		aux = lista->listaInt;
		do{
			if( aux->nomeId == id->nomeId)
				return 0;
			if(aux->proximo != NULL)
				aux = aux->proximo;
		}while(aux->proximo != NULL);
	}
	if( lista->listaStr != NULL){
		aux = lista->listaStr;
		do{
			if( aux->nomeId == id->nomeId)
				return 0;
			if(aux->proximo != NULL)
				aux = aux->proximo;
		}while(aux->proximo != NULL);
	}
	return 1;
}

void test(){
	pListaAtributos testTipo1 = createListaPeloTipo(T_INT);
	pListaAtributos testTipo2 = createListaPeloTipo(T_STR);
	pListaAtributos testListaInt1 = createList( testTipo1);
}
