%{
#include "gram.h"
#define YYSTYPE pListaAtributos

int linha = 0;
%}

%token TID TINT TSTR TVOID TADD TSUB TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TATR TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM

%%
Codigo : 	Prog
			;
			
Prog : 		ListFunc BlocoP
			| BlocoP
			;
			
ListFunc : 	ListFunc Func	{	addToGreatList( $2);
							}
			| Func 			{	addToGreatList( $1);
							}
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRPAR 	{	$$ = createList();
													addIdToList( $$, $2);
													addToGreatList($4);
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
			
Decs :		Decs Dec 	{	addToGreatList( $2);
						}
			| Dec 		{	addToGreatList( $1);
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
			
Cse :		TIF TLPAR ExpLog TRPAR Bloco
			| TIF TLPAR ExpLog TRPAR Bloco TELSE Bloco
			;
			
Cenq :		TWHILE TLPAR ExpLog TRPAR Bloco
			;
			
Catr :		TID TATR ExpAr TFLIN		{	addInstrucaoLista( ISTORE, buscaId($1 -> nomeIdTemp), INVAL);
										}
			| TID TATR TLIT TFLIN
			;
			
Cread :		TREAD TLPAR TID TRPAR TFLIN
			;
			
Cprint :	TPRINT Cnprint TLPAR ExpAr TRPAR TFLIN		{	addInstrucaoLista( INVOKEVIRTUAL, PRINT_INT, INVAL);
														}
			| TPRINT Cnprint TLPAR TLIT TRPAR TFLIN 	{ 	addInstrucaoLista( LDC, addLiteralLista( $4), INVAL);
															addInstrucaoLista( INVOKEVIRTUAL, PRINT_STR, INVAL);
														}
			;

Cnprint :		{ 	addInstrucaoLista( GETSTATIC, SYSTEM_OUT, INVAL);
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
			
ExpLog :	ExpLog TAND FLog
			| ExpLog TOR FLog
			| FLog
			;
			
FLog :		TLPAR ExpLog TRPAR
			| TNOT FLog
			| ExpRela
			;
			
ExpRela :	ExpAr TIGUAL ExpAr
			| ExpAr TDIF ExpAr
			| ExpAr TIGUALMA ExpAr
			| ExpAr TIGUALME ExpAr
			| ExpAr TMAIOR ExpAr
			| ExpAr TMENOR ExpAr
			;
			
ExpAr :		ExpAr TADD Am		{	addInstrucaoLista( IADD, INVAL, INVAL);
								}
			| ExpAr TSUB Am		{	addInstrucaoLista( ISUB, INVAL, INVAL);
								}
			| Am				{	$$ = $1;
								}
			;
			
Am :		Am TMUL An 				{	addInstrucaoLista( IMUL, INVAL, INVAL);
									}
			| Am TDIV An 			{	addInstrucaoLista( IDIV, INVAL, INVAL);
									}
			| An 					{	$$ = $1;
									}
			;
			
An :		TSUB An 				{	addInstrucaoLista( INEG, INVAL, INVAL);
									}
			| TLPAR ExpAr TRPAR
			| TID 					{ 	/*char* aux = buscaId( $1 -> nomeIdTemp);valor temporario*/
										addInstrucaoLista( ILOAD, buscaId( $1 -> nomeIdTemp), INVAL);
									}
			| Cfunc
			| TNUM					{	addNumLista( $1 -> numTemp);
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
