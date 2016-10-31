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
	struct Atributo* listaNotYet;
} ListaAtributos, *pListaAtributos;


typedef struct
{
	char nomeId[21];
	int num;
	struct Atributo* proximo;
} Atributo, *pAtributo;


typedef struct
{
	int label;
	int byte_code;
	int parametro_1;
	int parametro_2;
} Instrucao, *pInstrucao;

pListaAtributos createGreatList();
void addToGreatList( pListaAtributos newlista);


pListaAtributos createListTipo(int tipo);
pListaAtributos createList( pListaAtributos tipo);
pListaAtributos createAtributoList( char *nomeId);
pAtributo createAtributo( char* nomeId);
void setTipo( pListaAtributos lista, int tipo);
void addIdToList( pListaAtributos lista, pListaAtributos nomeId);
int verificaExistId( pListaAtributos lista, pAtributo id);
void putsListId( pListaAtributos lista);



void test();

#endif
