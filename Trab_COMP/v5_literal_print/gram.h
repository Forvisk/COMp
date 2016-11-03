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

#define GETSTATIC 0xB2
#define INVOKEVIRTUAL 0xB6
#define SYSTEM_OUT "java/lang/System/out"
#define PRINT_STR "java/io/PrintStream/println(Ljava/lang/String;)V"
#define PRINT_INT "java/io/PrintStream/println(Ljava/lang/integer)V"
//#define 

#ifndef __gramv3__
#define __gramv3__

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	char nomeIdTemp[21];
	int numTemp;
	char* literal;
	
	struct Atributo* lista
} ListaAtributos, *pListaAtributos;

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	char nomeId[21];
	struct Atributo* proximo;
} Atributo, *pAtributo;

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	int label;
	int byte_code;
	int parametro_1;
	int parametro_2;
} Instrucao, *pInstrucao;

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	char* literal;
	struct listaLiteral* proximo;
} ListaLiteral, *pListaLiteral;

   /*____________________________*/
  /*			gram.c 			*/
 /*____________________________*/
/*____________________________*/

void putsListId( pListaAtributos lista);
void putsListaInstrucao();

pListaAtributos getGreatList();
pInstrucao* getListaInstrucao();
pListaLiteral getListaLiteral();

   /*____________________________*/
  /*		gramListId.c 		*/
 /*____________________________*/
/*____________________________*/

pListaAtributos createGreatList();
pAtributo createAtributo( char* nomeId);

pListaAtributos createId( char* nomeId);
pListaAtributos createNum( int num);

void addToGreatList( pListaAtributos newlista);

void addIdToList( pListaAtributos listaFinal, pListaAtributos lista);
int existeId( pListaAtributos lista, char* nomeId);
char* buscaId( char* nomeId);

   /*____________________________*/
  /*	gramListInstrucoes.c 	*/
 /*____________________________*/
/*____________________________*/

int addInstrucaoLista( int byte_code, int parametro_1, int parametro_2);

int addNumLista( int num);

   /*____________________________*/
  /*	gramListLiteral.c 		*/
 /*____________________________*/
/*____________________________*/

pListaAtributos createLit( char* literal);
char* addLiteralLista( pListaAtributos literal);

#endif
