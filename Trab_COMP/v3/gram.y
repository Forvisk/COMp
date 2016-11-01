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
			
ListFunc : 	ListFunc Func	{ /*printf("t1 Adicionando na greatList");*//*putsListId($2);*/ addToGreatList( $2);}
			| Func 			{ /*printf("t2 Adicionando na greatList");*//*putsListId($1);*/ addToGreatList( $1);}
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRPAR 	{setTipo( $$, $1 -> tipo); addIdToList( $$, $2);}
			| TipeReturn TID TLPAR TRPAR		{setTipo( $$, $1 -> tipo); addIdToList( $$, $2);}
			;

TipeReturn :	Tipe
			| TVOID
			;

DecPar :	DecPar TVIRG Par 	{ /*printf("t2 Adicionando na greatList");*//*putsListId($3);*/ addToGreatList( $3);}
			| Par 				{ /*printf("t2 Adicionando na greatList");*//*putsListId($1);*/ addToGreatList( $1);}
			;
			
Par :		Tipe TID 	{setTipo( $$, $1 -> tipo); addIdToList( $$, $2);}
			;
			
BlocoP :	TLCH Decs ListCom TRCH
			| TLCH ListCom TRCH
			;
			
Decs :		Decs Dec 	{ /*printf("t1 Adicionando na greatList");*/ addToGreatList( $2);}
			| Dec 		{ /*printf("t2 Adicionando na greatList");*/ addToGreatList( $1);}
			;
			
Dec :		Tipe Listid TFLIN 	{/* printf("criando lista tipo %i\n", $1->tipo);*/ setTipo($2, $1->tipo);/* putsListId($2);*/ $$ = $2;}
			;
			
Tipe :		TINT 		{ /*printf("Inteiro\n");*/}
			| TSTR 		{ /*printf("String\n");*/}
			;
			
Listid :	Listid TVIRG TID 	{ addIdToList($1, $3); /*printf("t1 Adicionando id na lista\n");*/}
			| TID 				{ addIdToList($$, $1); /*printf("t2 Adicionando id na lista\n");*/}
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
			
Catr :		TID TATR ExpAr TFLIN		{	/*printf("\natribuindo algo a %s", $1 -> nomeIdTemp );*/
										 	int posVal = getPosValId($1 -> nomeIdTemp);
										 	if( posVal != INVAL){ 
										 		addInstrucaoLista( ISTORE, posVal, INVAL);
										 		addNumToAtributo($3 -> numTemp,  $1 -> nomeIdTemp);
											}
										}
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
			
ExpAr :		ExpAr TADD Am		{/*printf("\nadiciona IADD");*/ addInstrucaoLista( IADD, INVAL, INVAL);}
			| ExpAr TSUB Am		{/*printf("\nadiciona ISUB");*/ addInstrucaoLista( ISUB, INVAL, INVAL);}
			| Am				{/*printf("\nExpAr -> Am");*/ $$ = $1;}
			;
			
Am :		Am TMUL An 			{/*printf("\nadiciona IMUL");*/ addInstrucaoLista( IMUL, INVAL, INVAL);}
			| Am TDIV An 		{/*printf("\nadiciona IDIV");*/ addInstrucaoLista( IDIV, INVAL, INVAL);}
			| An 				{/*printf("\nAm -> An");*/ $$ = $1;}
			;
			
An :		TSUB An 			{/*printf("\nadiciona INEG");*/ addInstrucaoLista( INEG, INVAL, INVAL);}
			| TLPAR ExpAr TRPAR
			| TID 					{/*printf("\nID %s", $1 -> nomeIdTemp);*/ int aux = getPosValId($1 -> nomeIdTemp); if( aux != INVAL) addInstrucaoLista( ILOAD, aux, INVAL);}
			| Cfunc
			| TNUM					{/*printf("\nNUM %i", $1 -> numTemp);*/ addNumLista( $1 -> numTemp);}
			;

%%
#include "lex.yy.c"
int yyerror (char *str){
	printf("Erro em %i - %s; %s\n", linha, yytext, str);
	
} 		 
int yywrap(){
	return 1;
}
