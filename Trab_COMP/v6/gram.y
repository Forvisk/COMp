%{
#include "gram.h"
#define YYSTYPE pListaAtributos

int linha = 0;
int nlabel = 0, labelAtual = 0;
%}

%token TID TINT TSTR TVOID TADD TSUB TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TATR TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM

%%
Codigo : 	Prog
			;
			
Prog : 		ListFunc BlocoP
			| BlocoP
			;
			
ListFunc : 	ListFunc Func	{	addToGreatList( $2, 0);
							}
			| Func 			{	addToGreatList( $1, 0);
							}
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRPAR 	{	$$ = createList();
													addIdToList( $$, $2);
													addToGreatList($4, 0);
												}
			| TipeReturn TID TLPAR TRPAR		{	$$ = createList();
													addIdToList( $$, $2);
												}
			;

TipeReturn :	Tipe
			| TVOID
			;

DecPar :	DecPar TVIRG Par 	{	addIdToList( $1, $3);
								}
			| Par 				{	addIdToList( $$, $1);
								}
			;
			
Par :		Tipe TID 	{	addIdToList( $$, $2);
						}
			;
			
BlocoP :	TLCH Decs ListCom TRCH
			| TLCH ListCom TRCH
			;
			
Decs :		Decs Dec 	{	addToGreatList( $2, 1);
						}
			| Dec 		{	addToGreatList( $1, 1);
						}
			;
			
Dec :		Tipe Listid TFLIN 	{$$ = $2;}
			;
			
Tipe :		TINT 
			| TSTR 
			;
			
Listid :	Listid TVIRG TID 	{	addIdToList($1, $3);
								}
			| TID 				{	addIdToList($$, $1);
								}
			;
			
Bloco :		TLCH ListCom TRCH
			;
			
ListCom :	ListCom Com
			| Com
			;
			
Com :		Cse
			| Cenq
			| Catr
			| Cread
			| Cprint
			| Cfunc
			| Ret
			;
			
Ret :		TRET ExpAr TFLIN
			| TRET TLIT TFLIN
			;
			
Cse :		TIF TLPAR ExpLog TRPAR M Bloco Fm
			| TIF TLPAR ExpLog TRPAR M Bloco TELSE M Bloco Fm
			;

M :			{	nlabel++;
				labelAtual = nlabel;
				addLabel( labelAtual);/*teste*/
				printf("%i %i\n", nlabel, labelAtual);
			}
			;

Fm :		{	nlabel++;
				labelAtual = nlabel;
				addLabel( labelAtual);/*teste*/
				labelAtual = 0;
				printf("%i %i\n", nlabel, labelAtual);
			}
			;
			
Cenq :		TWHILE TLPAR ExpLog TRPAR Bloco
			;
			
Catr :		TID TATR ExpAr TFLIN		{	addInstrucaoListaPosVal( ISTORE, getPosVal( $1 -> nomeIdTemp), -1, labelAtual);
										}
			| TID TATR TLIT TFLIN
			;
			
Cread :		TREAD TLPAR TID TRPAR TFLIN
			;
			
Cprint :	TPRINT Cnprint TLPAR ExpAr TRPAR TFLIN		{	addInstrucaoLista( INVOKEVIRTUAL, PRINT_INT, INVAL, labelAtual);
														}
			| TPRINT Cnprint TLPAR TLIT TRPAR TFLIN 	{ 	addInstrucaoLista( LDC, addLiteralLista( $4), INVAL, labelAtual);
															addInstrucaoLista( INVOKEVIRTUAL, PRINT_STR, INVAL, labelAtual);

														}
			;

Cnprint :		{ 	addInstrucaoLista( GETSTATIC, SYSTEM_OUT, INVAL, labelAtual);
				}
			;
			
Cfunc :		TID TLPAR ListPar TRPAR TFLIN
			| TID TLPAR TRPAR TFLIN
			;
			
ListPar :	ListPar TVIRG ExpAr
			| ListPar TVIRG TLIT 	{	addLiteralLista($3);
									}
			| ExpAr
			| TLIT 					{	addLiteralLista($1);
									}
			;
			
ExpLog :	ExpLog TAND M FLog		{/* configura o labelAtual*/}
			| ExpLog TOR M FLog		{}
			| FLog					{}
			;
			
FLog :		TLPAR ExpLog TRPAR
			| TNOT FLog
			| ExpRela 				{/*adiciona a lista de operacoes*/}
			;
			
ExpRela :	ExpAr TIGUAL ExpAr			{/*Adicionar o tipo de comparacao*/
										}
			| ExpAr TDIF ExpAr			{}
			| ExpAr TIGUALMA ExpAr		{}
			| ExpAr TIGUALME ExpAr		{}
			| ExpAr TMAIOR ExpAr		{}
			| ExpAr TMENOR ExpAr		{}
			;
			
ExpAr :		ExpAr TADD Am		{	addInstrucaoLista( IADD, INVAL, INVAL, labelAtual);
								}
			| ExpAr TSUB Am		{	addInstrucaoLista( ISUB, INVAL, INVAL, labelAtual);
								}
			| Am				{	$$ = $1;
								}
			;
			
Am :		Am TMUL An 				{	addInstrucaoLista( IMUL, INVAL, INVAL, labelAtual);
									}
			| Am TDIV An 			{	addInstrucaoLista( IDIV, INVAL, INVAL, labelAtual);
									}
			| An 					{	$$ = $1;
									}
			;
			
An :		TSUB An 				{	addInstrucaoLista( INEG, INVAL, INVAL, labelAtual);
									}
			| TLPAR ExpAr TRPAR
			| TID 					{ 	/*printf("\nlinha: %i _ ", linha);
										printf("Existe id: %i, %s\n", existeId(getGreatList(), getPosVal($1->nomeIdTemp), $1 -> nomeIdTemp);*/
										addInstrucaoListaPosVal( ILOAD, getPosVal($1->nomeIdTemp), -1, labelAtual);
									}
			| Cfunc
			| TNUM					{	addNumLista( $1 -> numTemp, labelAtual);
									}
			;

%%
#include "lex.yy.c"
int yyerror (char *str){
	printf("Erro em %i - %s; %s\n", linha, yytext, str);
	
} 		 
int yywrap(){
	return 1;
}
