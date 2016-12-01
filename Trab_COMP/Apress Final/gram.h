#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_GREAT_LIST 0
#define T_INT 1
#define T_STR 2
#define T_VOID 3
#define T_TODEF -1

#define AND 1
#define OR 2

#define INVAL "-1"

#define IADD "iadd"//0x60 	//adicao
#define ISUB "isub"//0x64	//subtracao
#define IMUL "imul"//0x68	//multiplicacao
#define IDIV "idiv"//0x6C	//divisao

#define INEG "ineg"//0x74	//multiplicar por -1

#define ISTORE "istore"//0x36	//armazena em memoria (ISTORE PAR1)
#define ILOAD "iload"//0x15	//carrega da memoria (ILOAD PAR1)

#define BIPUSH "bipush"//0x10	//adiciona valor na pilha (BIPUSH PAR1) (6 =< PAR1 =< 127)
#define LDC "ldc"//0x12	//adiciona valor na pilha (LDC PAR1) ( 127 < PAR1)

#define ICONST_0 "iconst_0"//0x03	//adiciona 0 na pilha
#define ICONST_1 "iconst_1"//0x04	//adiciona 1 na pilha
#define ICONST_2 "iconst_2"//0x05	//adiciona 2 na pilha
#define ICONST_3 "iconst_3"//0x06 	//adiciona 3 na pilha
#define ICONST_4 "iconst_4"//0x07	//adiciona 4 na pilha
#define ICONST_5 "iconst_5"//0x08	//adiciona 5 na pilha

#define IFEQ "if_icmpeq" 	// if( E == E)
#define IFDIF "if_icmpne" 	// if( E != E)
#define IFMAEQ "if_icmpge" 	// if( E >= E)
#define IFMA "if_icmpgt"		// if( E > E)
#define IFMEEQ "if_icmple" 	// if( E <= E)
#define IFME "if_icmplt"		// if( E < E)

#define GOTO "goto"

#define GETSTATIC "getstatic"//0xB2
#define INVOKEVIRTUAL "invokevirtual"//0xB6
#define SYSTEM_OUT "java/lang/System/out"
#define PRINTSTREAM "Ljava/io/PrintStream;"
#define PRINT_STR "java/io/PrintStream/println(Ljava/lang/String;)V"
#define PRINT_INT "java/io/PrintStream/println(I)V"
//#define 

#ifndef __gramv3__
#define __gramv3__

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	char nomeId[21];
	int posVal;
	struct Atributo* proximo;
	int tipe;
} Atributo, *pAtributo;

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

typedef struct 
{
	char nomeFuncao[21];
	int posFinal;
	int tipeRetorno;
	int *parametros;
	struct Funcao *proximo;
} Funcao, *pFuncao;
 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	int linha;
	struct LinhaInst* proximo;
} LinhaInst, *pLinhaInst;

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	char nomeIdTemp[21];
	int numTemp;
	char* literal;
	int tipe_temp;

	pLinhaInst seVerdadeiro;
	pLinhaInst seFalso;

	int label;

	char byte_codeTemp[21];
	
	pAtributo lista
} ListaAtributos, *pListaAtributos;


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	int label;
	int num_par;
	char byte_code[21];
	char* parametro_1;
	char* parametro_2;
} Instrucao, *pInstrucao;

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
typedef struct
{
	char* literal;
	struct listaLiteral* proximo;
} ListaLiteral, *pListaLiteral;

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/


   /*____________________________*/
  /*			gram.c 			*/
 /*____________________________*/
/*____________________________*/


void createCabecalho(char* nomeArquivo);
void createMethodMain();
void endMethodMain();

void putsListId( pListaAtributos lista);
void putsListaInstrucao();
void putsListaLiteral();

void setPrimeiroListaLiteral( pListaLiteral primeiro);

void writeCabecalho( char* nomeArquivo, FILE *arq);
void writeMethodMain( FILE *arq);
void writeEndMethodMain( FILE *arq);
void writeListaInstrucao( FILE *arq);
int createJar( char* argc);

pListaAtributos getGreatList();
pInstrucao* getListaInstrucao();
pListaLiteral getListaLiteral();

void setPossuiErro();

   /*____________________________*/
  /*		gramListId.c 		*/
 /*____________________________*/
/*____________________________*/

pListaAtributos createGreatList();
pAtributo createAtributo( char* nomeId, int posVal, int tipe);
pListaAtributos createList();

pListaAtributos createTipe( int tipe);

pListaAtributos createId( char* nomeId);
pListaAtributos createNum( int num);

void addToGreatList( pListaAtributos newlista, int sePosVal, int tipe);

void addIdToList( pListaAtributos listaFinal, pListaAtributos lista);
int existeId( pListaAtributos lista, char* nomeId);
char* buscaId( char* nomeId);
int getPosVal( char* nomeId);
int getTipe( char* nomeId);

   /*____________________________*/
  /*	gramListInstrucoes.c 	*/
 /*____________________________*/
/*____________________________*/

int addInstrucaoLista( char byte_code[21], char* parametro_1, char* parametro_2, int label, int num_par);
int addInstrucaoListaPosVal( char byte_code[21], int posVal_1, int posVal_2, int label);
int addLdc( char* literal, int label);

int addNumLista(int num, int label);

pListaAtributos addLabel( int label);
int addIf( char byte_code[21], int label_1, int label_2, int labelAtual);
pListaAtributos createListVeF( char byte_code[21], int linha);

pListaAtributos not(pListaAtributos lista);
pListaAtributos mergeAnd( pListaAtributos listaC, pListaAtributos listaB);
pListaAtributos mergeOr( pListaAtributos listaC, pListaAtributos listaB);

int corrigirLabel( pLinhaInst linhaInstrucao, int label);

int getTamListInstrucoes();

int addPrintStr( int label);
int addPrintInt( int label);
int addGetstaticSout( int label);


   /*____________________________*/
  /*	gramListLiteral.c 		*/
 /*____________________________*/
/*____________________________*/

pListaAtributos createLit( char* literal);
char* addLiteralLista( pListaAtributos literal);

   /*____________________________*/
  /*		gramListFunc.c 		*/
 /*____________________________*/
/*____________________________*/

pListaAtributos addParametros( pListaAtributos new, pListaAtributos listParametros);

#endif
