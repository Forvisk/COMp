%{
#include <stdio.h>
#include <stdlib.h>
#include "gramv2.h"
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
			
ListFunc : 	ListFunc Func	
			| Func
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRPAR
			| TipeReturn TID TLPAR TRPAR
			;

TipeReturn :	Tipe
			| TVOID
			;

DecPar :	DecPar TVIRG Par
			| Par
			;
			
Par :		Tipe TID
			;
			
BlocoP :	TLCH Decs ListCom TRCH
			| TLCH ListCom TRCH
			;
			
Decs :		Decs Dec	{addToGreatList( $2);	printf("\tadiciona lista a grande lista\n");}
			| Dec	{addToGreatList( $1);	printf("\tadiciona lista a grande lista\n");}
			;
			
Dec :		Tipe Listid TFLIN		{$2 = createList( $1); printf("\tcriando lista de atributos\n");}
			;
			
Tipe :		TINT		{$$ = createListaPeloTipo(T_INT); printf("\tcriando lista pelo tipo inteiro\n");}
			| TSTR	{$$ = createListaPeloTipo(T_STR); printf("\tcriando lista pelo tipo string\n");}
			;
			
Listid :	Listid TVIRG TID	{	printf("\t\tadicionando um id a lista\n");}
			| TID		{	printf("\t\tadicionando um id a lista\n");}
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
			
Catr :		TID TATR ExpAr TFLIN
			| TID TATR TLIT TFLIN
			;
			
Cread :		TREAD TLPAR TID TRPAR TFLIN
			;
			
Cprint :	TPRINT TLPAR ExpAr TRPAR TFLIN
			| TPRINT TLPAR TLIT TRPAR TFLIN
			;
			
Cfunc :		TID TLPAR ListPar TRPAR TFLIN
			| TID TLPAR TRPAR TFLIN
			;
			
ListPar :	ListPar TVIRG ExpAr
			| ListPar TVIRG TLIT
			| ExpAr
			| TLIT
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
			
ExpAr :		ExpAr TADD Am
			| ExpAr TSUB Am
			| Am
			;
			
Am :		Am TMUL An
			| Am TDIV An
			| An
			;
			
An :		TSUB An
			| TLPAR ExpAr TRPAR
			| TID
			| Cfunc
			| TNUM
			;

%%
#include "lex.yy.c"
int yyerror (char *str){
	printf("Erro em %i - %s; %s\n", linha, yytext, str);
	
} 		 
int yywrap(){
	return 1;
}
