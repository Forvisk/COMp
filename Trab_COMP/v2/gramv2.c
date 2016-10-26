
#include "gramv2.h"

extern FILE *yyin;

#define ARQUIVO1 "Exemlo1.c"
#define ARQUIVO2 "Exemlo2.c"
#define ARQUIVO3 "Exemlo3.c"

/*
*	Adriano Zanella Junior
*	
*/

ListaAtributos* greatList = createGreatList();

int main(int argc, char const *argv[])
{
	yyin = fopen( argv[ 1], "r");
	if( yyin != NULL){
		yyparse();
	}else{
		printf("Arquivo nao encontrado!");
	}
	fclose(yyin);
	return 0;
}

ListaAtributos* createGreatList(){
	ListaAtributos* new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new.tipo = T_GREAT_LIST;
	new.listaInt = NULL;
	new.listaSTR = NULL;

	return new;
}

ListaAtributos* createListaPeloTipo(int tipo){
	ListaAtributos* new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new.tipo = tipo;
	new.listaInt = NULL;
	new.listaSTR = NULL;

	return new;
}

ListaAtributos* createList(ListaAtributos* tipo){
	ListaAtributos* new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new.tipo = tipo.tipo;
	new.listaInt = NULL;
	new.listaSTR = NULL;
	
	free(tipo);
	return new;
}

void setTipo( ListaAtributos* lista, int tipo){
	lista.tipo = tipo;
}

Atributo* createAtributo( char* nomeId){
	Atributo* new = (Atributo*)malloc(sizrof(Atributo));
	strncpy(nomeId, new.nomeId, 20);
	new.proximo = NULL;
	
	return new;
}

void addIdToList( ListaAtributos* lista, Atributo* id){
	if( lista.tipo == T_INT){
		if(lista.listaInt == NULL){
			lista.listaInt = id;
		}else{
			if(verificaExistId( lista, id)){
				Atributo* aux = lista.listaInt;
				while(aux.proximo != NULL)
					aux = aux.proximo;
				aux.proximo = id;
			}
		}
	}else if( lista.tipo == T_STR){
		if(lista.listaStr == NULL){
			lista.listaStr = id;
		}else{
			if(verificaExistId( lista, id)){
				Atributo* aux = lista.listaStr;
				while( aux.proximo != NULL)
					aux = aux.proximo;
				aux.proximo = id;
			}
		}
	}
}


//void addToGreatList( ListaAtributos* grandelista, ListaAtributos* newlista);


int verificaExistId( ListaAtributos* lista, Atributo* id){
	Atributo* aux;
	if( lista.listaInt != NULL){
		aux = lista.listaInt;
		do{
			if( aux.nomeId == id.nomeId)
				return 0
			if(aux.proximo != NULL)
				aux = aux.proximo;
		}while(aux.proximo != NULL);
	}
	if( lista.listaStr != NULL){
		aux = lista.listaStr;
		do{
			if( aux.nomeId == id.nomeId)
				return 0
			if(aux.proximo != NULL)
				aux = aux.proximo;
		}while(aux.proximo != NULL);
	}
	return 1;
}
