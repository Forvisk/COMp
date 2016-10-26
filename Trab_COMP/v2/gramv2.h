#include <stdio.h>
#include <stdlib.h>

#define T_GREAT_LIST 0
#define T_INT 1
#define T_STR 2
#define T_TODEF -1

#ifndef __gramv2__
#define __gramv2__

typedef struct
{
	int tipo;
	struct Atributo *listaInt;
	struct Atributo *listaStr;
} ListaAtributos;

typedef struct
{
	char nomeId[21];
	struct Atributo *proximo;
} Atributo;

ListaAtributos* createGreatList();

ListaAtributos* createListaPeloTipo(int tipo);
ListaAtributos* createList(ListaAtributos* tipo);

Atributo* createAtributo();

void setTipo( ListaAtributos* lista, int tipo);

void addIdToList( ListaAtributos* lista, Atributo* id);

void addToGreatList( ListaAtributos* grandelista, ListaAtributos* newlista);

int verificaExistId( ListaAtributos* lista, Atributo* id);

#endif
