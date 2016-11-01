
#include "gram.h"

extern FILE *yyin;

#define ARQUIVO1 "Exemlo1.c"
#define ARQUIVO2 "Exemlo2.c"
#define ARQUIVO3 "Exemlo3.c"

/*
*	Adriano Zanella Junior
*	
*/

pListaAtributos greatList;
pInstrucao listaInstrucao[200];

int posValGlobal = 1;

int main(int argc, char const *argv[])
{
	int i;
	for( i = 0; i < 200; i++){
		listaInstrucao[ i] = NULL;
	}
	greatList = createGreatList();
	yyin = fopen( argv[ 1], "r");
	if( yyin != NULL){
		yyparse();
	}else{
		printf("Arquivo nao encontrado!");
	}
	fclose(yyin);

	putsListId(greatList);
	//putsListaInstrucao();
	return 0;
}

/*________________________________________________________________________________________*/
pListaAtributos createGreatList(){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->tipo = T_GREAT_LIST;
	new->listaInt = NULL;
	new->listaStr = NULL;

	return new;
}

void addToGreatList( pListaAtributos newlista){
	//printf("\nAdicionando a greatList:\n");
	/*	Adiciona inteiros	*/
	if( newlista -> tipo == T_INT){
		/*	da lista de inteiros	*/
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
		/* da lista não definida	*/
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
	/*	adiciona strings	*/
	}else if( newlista -> tipo == T_STR){
		/*	da lista de strings	*/
		if( newlista -> listaStr == NULL){
			//printf("Lista string vazia\n");
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
		/*	da lista não definida	*/
		if( newlista -> listaNotYet != NULL){
			//printf("lista not yet\n");
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
		/*	adiciona a lista não definida	*/
	}else if( newlista -> tipo == T_TODEF){
		/* da lista não definida	*/
		if( newlista -> listaNotYet  != NULL){
			pAtributo aux = newlista -> listaNotYet;
			pAtributo auxGreat = greatList -> listaNotYet;
			pAtributo auxDel;
			do{
				if( greatList -> listaNotYet == NULL){
					if( verificaExistId( greatList, aux)){

						int posAux = posValGlobal;
						posValGlobal = aux -> posVal;
						greatList -> listaNotYet = createAtributo( aux -> nomeId);
						posValGlobal = posAux;

						auxGreat = greatList -> listaNotYet;
						//printf("\tprimeiro void da greatList: %s\n", auxGreat->nomeId);
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
						//printf("\tnovo void na greatList: %s\n", auxGreat->nomeId);
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

/*________________________________________________________________________________________*/
void putsListId( pListaAtributos lista){
	printf("\nTabela de simbolos %p:\n", (void*)lista);
	printf("\ttipo\t\tsimbolo\tposVal\tnum\n\n");
	if( lista->tipo == T_TODEF){
		//printf("\tLista void\n");
	}else if( lista->tipo == T_INT){
		//printf("\tLista int\n");
	}else if( lista->tipo == T_STR){
		//printf("\tLista string\n");
	}
	if( lista->listaInt != NULL){
		pAtributo aux = lista->listaInt;
		do{
			printf("\tinteiro\t\t%s\t%i\tnum = %i\n", aux->nomeId, aux->posVal, aux->num);
			aux = aux->proximo;
		}while( aux != NULL);
	}
	if( lista->listaStr != NULL){
		pAtributo aux = lista->listaStr;
		do{
			printf("\tstring\t\t%s\t%i\n", aux->nomeId, aux->posVal);
			aux = aux->proximo;
		}while( aux != NULL);
	}
	if( lista->listaNotYet != NULL){
		pAtributo aux = lista->listaNotYet;
		do{
			printf("\tvoid\t\t%s\t%i\n", aux->nomeId, aux->posVal);
			aux = aux->proximo;
		}while( aux != NULL);
	}
	printf("\n");
}

void putsListaInstrucao(){
	int numIntrucoes = 0;
	printf("\nLista de instruções:\n");
	while( listaInstrucao[ numIntrucoes] != NULL){
		printf("Intrucao: %p\n\tPar1 %i Par2 %i\n\tlabel: %i\n",
												 listaInstrucao[ numIntrucoes]->byte_code,
												 listaInstrucao[ numIntrucoes]->parametro_1,
												 listaInstrucao[ numIntrucoes]->parametro_2,
												 listaInstrucao[ numIntrucoes]-> label
												 );
		numIntrucoes++;
	}
}

/*________________________________________________________________________________________*/
int getPosValGlobal(){
	return posValGlobal;
}

void setPosValGlobal(int pos){
	posValGlobal = pos;
}

/*________________________________________________________________________________________*/
pListaAtributos getGreatList(){
	return greatList;
}

pInstrucao* getListaInstrucao(){
	return listaInstrucao;
}

/*________________________________________________________________________________________*/
pAtributo buscaAtributo( char* nomeId){
	pAtributo aux = NULL;
	/*	Verifica lista de inteiros da lista de atributos	*/
	if( greatList -> listaInt != NULL){
		aux = greatList -> listaInt;
		do{
			if( strncmp( aux -> nomeId, nomeId, 20) == 0){
				//printf("\tverificando se %s == %s:", aux->nomeId, nomeId);
				return aux;
			}
			aux = aux -> proximo;
		}while( aux != NULL);
	}
	/* Verifica lista de strings da lista de atributos	*/
	if( greatList -> listaStr != NULL){
		aux = greatList -> listaStr;
		do{
			if( strncmp( aux -> nomeId, nomeId, 20) == 0){
				//printf("\tverificando se %s == %s:", aux->nomeId, nomeId);
				return aux;
			}
			aux = aux -> proximo;
		}while( aux != NULL);
	}
	/*	Não foi achado nenhum atributo com este nomeId 	*/
	return NULL;
}

/*________________________________________________________________________________________*/
void testIdList(){
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


void testInstrucoes(){

}

/*________________________________________________________________________________________*/