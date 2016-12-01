
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

void addToGreatList( pListaAtributos newlista, int sePosVal, int tipe){
	//printf("\nAdicionando a greatList:\n");
	//putsListId( newlista);

	pListaAtributos greatList = getGreatList();


	if( newlista -> lista == NULL){
		//printf("Lista vazia\n");

	}else{
		pAtributo aux = newlista -> lista;
		pAtributo auxGreat = greatList -> lista;
		pAtributo auxDel;
		int posVal = 0;

		do{
			if( greatList -> lista == NULL){
				if( existeId( greatList, aux)){
					if(sePosVal != 1)
						posVal = -1;
					greatList -> lista = createAtributo( aux -> nomeId, posVal, tipe);
					auxGreat = greatList -> lista;
					auxGreat -> proximo = NULL;
					posVal++;
					//printf("\tprimeiro simbolo da greatList: %s %i\n", auxGreat->nomeId, auxGreat -> posVal);
				}
			}else{

				while( auxGreat -> proximo != NULL){
					//printf("\tGreatList : %s\n", auxGreat->nomeId);
					if( auxGreat -> posVal != -1){
						posVal++;
					}
					auxGreat = auxGreat -> proximo;
				}
				if( existeId( greatList, aux)){
					if(sePosVal != 1)
						posVal = -1;
					/*else
						posVal++;*/
					if( auxGreat -> posVal != -1){
						posVal = auxGreat -> posVal +1;
					}
					auxGreat -> proximo = createAtributo( aux -> nomeId, posVal, tipe);
					auxGreat = auxGreat -> proximo;
					//printf("\tnovo simbolo na greatList: %s %i\n", auxGreat->nomeId, auxGreat->posVal);
					posVal++;
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

pAtributo createAtributo( char* nomeId, int posVal, int tipe){
	pAtributo new = (Atributo*)malloc(sizeof(Atributo));
	strncpy(new->nomeId, nomeId, 20);
	//printf("\n\tNovo atributo: %s\n", new->nomeId);
	new -> proximo = NULL;
	new -> posVal = posVal;
	new -> tipe = tipe;
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createTipe( int tipe){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new -> tipe_temp = tipe;
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createList(){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->lista = NULL;
	new -> tipe_temp = T_TODEF;
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
	pAtributo new = createAtributo( lista -> nomeIdTemp, 0, lista -> tipe_temp);
	//printf(" %s\n", lista -> nomeIdTemp);
	if( listaFinal -> lista == NULL){
		//printf("Lista %p vazia primeiro simbolo %s\n", listaFinal, new -> nomeId);
		listaFinal -> lista = new;
	}else{
		pAtributo aux = listaFinal -> lista;
		while( aux -> proximo != NULL)
			aux = (pAtributo) aux -> proximo;
		aux -> proximo = new;
		aux = (pAtributo) aux -> proximo;
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
			//printf("\nVerificando se %s == %s\n", aux -> nomeId, nomeId);
			if( strncmp( aux -> nomeId, nomeId, 20) == 0){
				//printf("aqui\n");
				return 0;
			}
			//printf("aqui2\n");
			aux = aux -> proximo;
		}while( aux != NULL);
	}
	return 1;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

char* buscaId( char* nomeId){
	pListaAtributos lista = getGreatList();
	if( lista -> lista == NULL){
		return INVAL;
	}else{
		pAtributo aux = lista -> lista;
		while( aux -> proximo != NULL){
			//printf("Verificando se %s == %s\n", aux -> nomeId, nomeId);
			if( strncmp( aux -> nomeId, nomeId, 20) == 0)
				return INVAL;
			aux = aux -> proximo;
		}
		char* ret = (char*)malloc( sizeof( strlen( aux->nomeId) + 1));
		strcpy( ret, aux->nomeId);
		return ret;
	}
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int getPosVal( char* nomeId){
	pListaAtributos lista = getGreatList();
	if( lista -> lista == NULL){
		return -1;
	}else{
		pAtributo aux = lista -> lista;
		while( aux != NULL){
			//printf("Verificando se %s == %s\n", aux -> nomeId, nomeId);
			if( strncmp( aux -> nomeId, nomeId, 20) == 0){
				/*char ret[10];
				sprintf( ret, "%i\0", aux -> posVal);
				printf("%s %i\n", ret, strlen( ret));*/
				return aux -> posVal;
			}
			aux = aux -> proximo;
		}
		return -1;
	}
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int getTipe( char* nomeId){
	pListaAtributos lista = getGreatList();
	if( lista -> lista == NULL){
		return -1;
	}else{
		pAtributo aux = lista -> lista;
		while( aux != NULL){
			//printf("Verificando se %s == %s\n", aux -> nomeId, nomeId);
			if( strncmp( aux -> nomeId, nomeId, 20) == 0){
				/*char ret[10];
				sprintf( ret, "%i\0", aux -> posVal);
				printf("%s %i\n", ret, strlen( ret));*/
				/*printf("%s %i\n", nomeId, aux -> tipe);*/
				return aux -> tipe;
			}
			aux = aux -> proximo;
		}
		return -1;
	}
}

/*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/