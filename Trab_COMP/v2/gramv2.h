#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_GREAT_LIST 0
#define T_INT 1
#define T_STR 2
#define T_TODEF -1

#ifndef __gramv2__
#define __gramv2__

typedef struct
{
	char nomeIdTemp[21];
	int numTemp;

	int tipo;
	struct Atributo* listaInt;
	struct Atributo* listaStr;
} ListaAtributos, *pListaAtributos;

typedef struct
{
	char nomeId[21];
	int num;
	struct Atributo* proximo;
} Atributo, *pAtributo;

/*
typedef struct Atributo
{
	int tipo;
	char nomeId[21];
	lista *listaId;
	int num;
};
*/

pListaAtributos createGreatList();
void addToGreatList( pListaAtributos newlista);


pListaAtributos createListaPeloTipo(int tipo);
pListaAtributos createList(pListaAtributos tipo);


pAtributo createAtributo( char* nomeId);


void setTipo( pListaAtributos lista, int tipo);


void addIdToList( pListaAtributos lista);

int verificaExistId( pListaAtributos lista, pAtributo id);

void putsListaId(pListaAtributos lista);

void test();

#endif
