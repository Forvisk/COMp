#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_GREAT_LIST 0
#define T_INT 1
#define T_STR 2
#define T_TODEF -1

#define IADD 0x60
#define ISUB 0x64
#define IMUL 0x68
#define IDIV 0x6C

#define ISTORE 0x36
#define ILOAD 0x15

#define BIPUSH 0x10
#define ldc 0x12

#define ICONST_0 0x03
#define ICONST_1 0x04
#define ICONST_2 0x05
#define ICONST_3 0x06
#define ICONST_4 0x07
#define ICONST_5 0x08




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
	int posVal;
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

pListaAtributos createAtributoNum( char* num);

void test();

#endif
