#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_GREAT_LIST 0
#define T_INT 1
#define T_STR 2
#define T_TODEF -1

#define INVAL -1

#define IADD 0x60 	//adicao
#define ISUB 0x64	//subtracao
#define IMUL 0x68	//multiplicacao
#define IDIV 0x6C	//divisao

#define INEG 0x74	//multiplicar por -1

#define ISTORE 0x36	//armazena em memoria (ISTORE PAR1)
#define ILOAD 0x15	//carrega da memoria (ILOAD PAR1)

#define BIPUSH 0x10	//adiciona valor na pilha (BIPUSH PAR1) (6 =< PAR1 =< 127)
#define LDC 0x12	//adiciona valor na pilha (LDC PAR1) ( 127 < PAR1)

#define ICONST_0 0x03	//adiciona 0 na pilha
#define ICONST_1 0x04	//adiciona 1 na pilha
#define ICONST_2 0x05	//adiciona 2 na pilha
#define ICONST_3 0x06 	//adiciona 3 na pilha
#define ICONST_4 0x07	//adiciona 4 na pilha
#define ICONST_5 0x08	//adiciona 5 na pilha

#define IAND	0x7E	//and
#define IOR 	0x80 	//or

//#define 




#ifndef __gramv3__
#define __gramv3__

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

/*	gram.c 	*/
pListaAtributos createGreatList();
void addToGreatList( pListaAtributos newlista);

void putsListId( pListaAtributos lista);
void putsListaInstrucao();

int getPosValGlobal();
void setPosValGlobal(int pos);

pListaAtributos getGreatList();
pInstrucao* getListaInstrucao();

pAtributo buscaAtributo( char* nomeId);

void testIdList();
void testInstrucoes();


/*	gramListid.c 	*/
pListaAtributos createListTipo(int tipo);
pListaAtributos createList( pListaAtributos tipo);

pListaAtributos createAtributoList( char *nomeId);
pListaAtributos createAtributoNum( int num);
pAtributo createAtributo( char* nomeId);


void addIdToList( pListaAtributos lista, pListaAtributos nomeId);
int verificaExistId( pListaAtributos lista, pAtributo id);

void setTipo( pListaAtributos lista, int tipo);
void addNumToAtributo( int num, char* nomeId);
int getPosValId( char* nomeId);


/*	gramListInstrucoes.c 	*/
int addInstrucaoLista( int byte_code, int parametro_1, int parametro_2);

int addNumLista( int num);

#endif
