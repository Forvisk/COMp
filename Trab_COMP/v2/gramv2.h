#include <stdio.h>
#include <stdlib.h>

#define T_INT 1
#define T_STR 2

#ifndef __gramv2__
#define __gramv2__

typedef struct
{
	struct AtributoInt *pInt;
	struct AtributoStr *pStr;
}greatList;

typedef struct
{
	char nomeId[21];
	struct Atributo *proximo;
} Atributo;



typedef struct
{
	
	struct *Atributo;
}ListaId

void addGreatList( ListaId *lista, int tipo);

#endif