
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
	putsListaId(greatList);
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
	strncpy(new->nomeId, nomeId, 20);
	new->num = 0;
	new->proximo = NULL;
	printf("\t%s\n", new->nomeId);
	return new;
}

void addIdToList( ListaAtributos* lista){
	printf("%s\n", lista->nomeIdTemp);
	pAtributo new = createAtributo(lista->nomeIdTemp);

	if( lista->tipo == T_INT){
		if(lista->listaInt == NULL){
			lista->listaInt = new;
			printf("\tPrimeiro %s\n", new -> nomeId);
		}else{
			if(verificaExistId( lista, new)){
				pAtributo aux = lista->listaInt;
				while( aux -> proximo != NULL)
					aux = aux -> proximo;

				aux->proximo = new;
				aux = aux -> proximo;
				printf("\tnovo %s\n", aux->nomeId);
			}
		}
	}else if( lista->tipo == T_STR){
		if(lista->listaStr == NULL){
			lista->listaStr = new;
			printf("\tPrimeiro %s\n", new -> nomeId);
		}else{
			
		}
	}
	strncpy(lista->nomeIdTemp, "", 20);
	putsListaId( lista);
}


void addToGreatList( pListaAtributos newlista){
	putsListaId( newlista);

	if( newlista -> tipo == T_INT){
		if( newlista -> listaInt == NULL){
			printf( "Lista vazia\n");
		}else{
			pAtributo auxGreat;
			if(greatList -> listaInt != NULL){
				auxGreat = greatList -> listaInt;
				do{
					auxGreat = auxGreat->proximo;
				}while(auxGreat->proximo != NULL);
			}
			pAtributo aux = newlista -> listaInt;
			do{
				if(verificaExistId(greatList, aux)){
					if(auxGreat != NULL){
						auxGreat->proximo = aux;
						auxGreat = createAtributo(aux->nomeId);
						printf("Atributo %s adicionado como inteiro\n", auxGreat->nomeId);
					}else{
						greatList -> listaInt = createAtributo(aux->nomeId);
						auxGreat = greatList -> listaInt;
						printf("Primeiro atributo %s adicionado como inteiro\n", auxGreat->nomeId);
					}
				}else{
					printf("Atributo %s ja existente\n", aux->nomeId);
				}
				aux = aux->proximo;
			}while( aux->proximo != NULL);
		}
		free(newlista);
	}else if( newlista -> tipo == T_STR){
		if( newlista -> listaStr == NULL){
			printf( "Lista vazia\n");
		}else{
			pAtributo auxGreat;
			if(	greatList -> listaStr != NULL){
				auxGreat = greatList -> listaStr;
				do{
					auxGreat = auxGreat -> proximo;
				}while( auxGreat -> proximo != NULL);
			}
			pAtributo aux = newlista -> listaInt;
			do{
				if( verificaExistId(greatList, aux)){
					if( auxGreat != NULL){
						auxGreat -> proximo = aux;
						auxGreat = createAtributo( aux -> nomeId);
						printf("Atributo %s adicionado como string\n", auxGreat->nomeId);
					}else{
						greatList -> listaStr = createAtributo( aux->nomeId);
						auxGreat = greatList -> listaStr;
						printf("Primeiro atributo %s adicionado como string\n", auxGreat->nomeId);
					}
				}else{
					printf("Atributo %s ja existente\n", aux -> nomeId);
				}
				aux = aux => proximo;
			}while( aux->proximo != NULL);
		}
		free(newlista);
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

void putsListaId( pListaAtributos lista){
	printf("lista:\n");
	if( lista->listaInt != NULL){
		pAtributo aux = lista->listaInt;
		do{
			printf("\tint\t%s\n", aux->nomeId);
			if( aux->proximo != NULL)
				aux = aux->proximo;
		}while( aux->proximo != NULL);
		printf("\tint\t%s\n", aux->nomeId);
	}
	if( greatList->listaStr != NULL){
		pAtributo aux = lista->listaStr;
		do{
			printf("\tstr\t%s\n", aux->nomeId);
			aux = aux->proximo;
		}while( aux->proximo != NULL);

	}
}

void test(){
	pListaAtributos testTipo1 = createListaPeloTipo(T_INT);
	pListaAtributos testTipo2 = createListaPeloTipo(T_STR);
	pListaAtributos testListaInt1 = createList( testTipo1);

	strncpy(testListaInt1->nomeIdTemp, "a", 20);
	printf("%s\n", testListaInt1->nomeIdTemp);
	addIdToList(testListaInt1);

	strncpy(testListaInt1->nomeIdTemp, "b", 20);
	printf("%s\n", testListaInt1->nomeIdTemp);
	addIdToList(testListaInt1);

	addToGreatList(testListaInt1);
}
