
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
	printf("\nCriando Atributo\n\tNovo atributo: %s\n", new->nomeId);
	return new;
}

void addIdToList( ListaAtributos* lista){
	pAtributo new = createAtributo(lista->nomeIdTemp);
	printf("\nAdicionando a lista %p\n", (void*)lista);
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
			}
		}
	}else if( lista->tipo == T_STR){
		if(lista->listaStr == NULL){
			lista->listaStr = new;
			printf("\tprimeira string %s\n", new -> nomeId);
		}else{
			if(verificaExistId( lista, new)){
				pAtributo aux = lista->listaStr;
				while( aux -> proximo != NULL)
					aux = aux -> proximo;

				aux->proximo = new;
				aux = aux -> proximo;
				printf("\tnova string %s\n", aux->nomeId);
			}
		}
	}
	strncpy(lista->nomeIdTemp, "", 20);
}


void addToGreatList( pListaAtributos newlista){
	putsListaId( newlista);
	printf("\nAdicionando a greatList:\n");
	if( newlista -> tipo == T_INT){
		if( newlista -> listaInt == NULL){
			printf("Lista vazia\n");
		}else{
			pAtributo aux = newlista -> listaInt, auxGreat = greatList -> listaInt;
			
			do{
				if( greatList -> listaInt == NULL){
					if( verificaExistId( greatList, aux)){
						greatList -> listaInt = createAtributo( aux -> nomeId);
						auxGreat = greatList -> listaInt;
						printf("\tprimeiro inteiro da greatList: %s\n", auxGreat->nomeId);
					}
				}else{
					while( auxGreat -> proximo != NULL){
						printf("\t\tGreatList : %s\n", auxGreat->nomeId);
						auxGreat = auxGreat -> proximo;
					}
					if( verificaExistId( greatList, aux)){
						auxGreat -> proximo = createAtributo( aux -> nomeId);
						auxGreat = auxGreat -> proximo;
						printf("\tnovo inteiro na greatList: %s\n", auxGreat->nomeId);
					}
				}

				aux = aux -> proximo;
			}while( aux != NULL);


		}
	}else if( newlista -> tipo == T_STR){
		if( newlista -> listaStr == NULL){
			printf("Lista vazia\n");
		}else{
			pAtributo aux = newlista -> listaStr, auxGreat = greatList -> listaStr;
			
			do{
				if( greatList -> listaStr == NULL){
					if( verificaExistId( greatList, aux)){
						greatList -> listaStr = createAtributo( aux -> nomeId);
						auxGreat = greatList -> listaInt;
						printf("\tprimeiro inteiro da greatList: %s\n", auxGreat->nomeId);
					}
				}else{
					while( auxGreat -> proximo != NULL){
						printf("\t\tGreatList : %s\n", auxGreat->nomeId);
						auxGreat = auxGreat -> proximo;
					}
					if( verificaExistId( greatList, aux)){
						auxGreat -> proximo = createAtributo( aux -> nomeId);
						auxGreat = auxGreat -> proximo;
						printf("\tnovo inteiro na greatList: %s\n", auxGreat->nomeId);
					}
				}

				aux = aux -> proximo;
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
		printf("Verivicando inteiro\n");
		aux = lista->listaInt;
		do{
			printf("\tverificando se %s == %s\n", aux->nomeId, id->nomeId);
			if( strncmp( aux->nomeId, id->nomeId, 20) == 0){
				printf("\t%s ja existente\n", id->nomeId);
				return 0;
			}
			if(aux->proximo != NULL)
				aux = aux->proximo;
		}while(aux->proximo != NULL);
	}
	if( lista->listaStr != NULL){
		aux = lista->listaStr;
		do{
			printf("\tverificando se %s == %s:", aux->nomeId, id->nomeId);
			if( strncmp( aux->nomeId, id->nomeId, 20) == 0){
				printf("\t%s ja existente\n", id->nomeId);
				return 0;
			}
			printf("\tOK\n");
			aux = aux->proximo;
		}while(aux != NULL);
	}
	printf("\tverificação OK\n");
	return 1;
}


void putsListaId( pListaAtributos lista){
	printf("Lista %p:\n", (void*)lista);
	if( lista->listaInt != NULL){
		pAtributo aux = lista->listaInt;
		do{
			printf("\tinteiro\t%s\n", aux->nomeId);
			aux = aux->proximo;
		}while( aux != NULL);
	}else{
		printf("iista sem inteiros\n");
	}
	if( lista->listaStr != NULL){
		pAtributo aux = lista->listaStr;
		do{
			printf("\tstring\t%s\n", aux->nomeId);
			aux = aux->proximo;
		}while( aux != NULL);
	}else{
		printf("lista sem Strings\n");
	}
}

void test(){
	pListaAtributos testTipo1 = createListaPeloTipo(T_INT);
	pListaAtributos testTipo2 = createListaPeloTipo(T_STR);

	pListaAtributos testListaInt1 = createList( testTipo1);
	
	strncpy(testListaInt1->nomeIdTemp, "a", 20);
	addIdToList(testListaInt1);
	putsListaId(testListaInt1);

	strncpy(testListaInt1->nomeIdTemp, "b", 20);
	addIdToList(testListaInt1);
	putsListaId(testListaInt1);

	strncpy(testListaInt1->nomeIdTemp, "c", 20);
	addIdToList(testListaInt1);
	putsListaId(testListaInt1);

	strncpy(testListaInt1->nomeIdTemp, "a", 20);
	addIdToList(testListaInt1);
	putsListaId(testListaInt1);

	strncpy(testListaInt1->nomeIdTemp, "b", 20);
	addIdToList(testListaInt1);
	putsListaId(testListaInt1);

	addToGreatList(testListaInt1);

	
	pListaAtributos testListaStr1 = createList( testTipo2);

	strncpy(testListaStr1->nomeIdTemp, "chambinha", 20);
	addIdToList(testListaStr1);
	putsListaId(testListaStr1);

	strncpy(testListaStr1->nomeIdTemp, "Aioi", 20);
	addIdToList(testListaStr1);
	putsListaId(testListaStr1);

	strncpy(testListaStr1->nomeIdTemp, "Poi", 20);
	addIdToList(testListaStr1);
	putsListaId(testListaStr1);

	strncpy(testListaStr1->nomeIdTemp, "Wahaha", 20);
	addIdToList(testListaStr1);
	putsListaId(testListaStr1);

	strncpy(testListaStr1->nomeIdTemp, "ok", 20);
	addIdToList(testListaStr1);
	putsListaId(testListaStr1);

	strncpy(testListaStr1->nomeIdTemp, "c", 20);
	addIdToList(testListaStr1);
	putsListaId(testListaStr1);

	strncpy(testListaStr1->nomeIdTemp, "a", 20);
	addIdToList(testListaStr1);
	putsListaId(testListaStr1);

	addToGreatList( testListaStr1);
	
}
