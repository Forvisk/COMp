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

#define POS_INVAL -1
#define POS_VAL 1
#define INVAL "-1"

#define VALIDO 1
#define INVALIDO 0

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
#define IFMA "if_cmpgt"		// if( E > E)
#define IFMEEQ "if_cmple" 	// if( E <= E)
#define IFME "if_cmplt"		// if( E < E)

#define GOTO "goto"

#define GETSTATIC "getstatic"//0xB2
#define INVOKEVIRTUAL "invokevirtual"//0xB6
#define SYSTEM_OUT "java/lang/System/out"
#define PRINT_STR "java/io/PrintStream/println(Ljava/lang/String;)V"
#define PRINT_INT "java/io/PrintStream/println(I)V"
//#define 

#ifndef __gramv3__
#define __gramv3__

typedef struct
{
	int codFuncao;
	char nomeId[21];
	int posVal;
	int tipo;
	int validade;
	struct Variavel* proximo;
	struct Variavel* anterior;
} Variavel, *pVariavel;

typedef struct
{
	int linha;
	struct linhaIntrucao *proximo;
	struct linhaIntrucao *anterior;
} linhaIntrucao, *pLinhaIntrucao;

typedef struct
{
	char nomeFuncao[21];
	pVariavel listaParametros;
	pVariavel listaVariaveis;

	pLinhaIntrucao seVerdadeiro;
	pLinhaIntrucao seFalso;

	char nomeId_temp[21];
	char byteCode_temp[21];
	char* literal_temp;
	int valor_temp;
	int tipo_temp;
	int label;
} Modulo, *pModulo;

typedef struct
{
	int codFuncao;
	int label;
	char byteCode[21];
	char* parametro1;
	char* parametro2;
} Intrucao, *pInstrucao;

typedef struct
{
	int codFuncao;
	char idFuncao[21];
	int linhaIncio;
	int linhaFinal;
	int tipoRetorno;
	int qntParametros;
	int* lista_tipoParametros;
} Funcao, *pFuncao;

/*_-_gramMain.c_-_*/

void setErro();

/*_-_basicId.c_-_*/

pModulo criarId( char* nomeId);

pModulo criarTipo( int tipo);

pVariavel criarVariavel( char* nomeId);

int addNewId_Variaveis( pModulo lista, pModulo novoId);
int addNewId_Parametros( pModulo lista, pModulo novoPar);

void putsListaVariaveis( pModulo lista);

pModulo setTipoListaVariaveis( pModulo lista, pModulo tipo);
pModulo setTipoListaParametros( pModulo lista, pModulo tipo);

int existeId( pModulo lista, char* nomeId);

#endif