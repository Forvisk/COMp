%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TID TINT TSTR TVOID TADD TSUB TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TATR TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM

%%
Codigo : 	Prog		{printf("Programa\n");}
			;
			
Prog : 		ListFunc BlocoP {printf("Funcoes e bloco P\n");}
			| BlocoP
			;
			
ListFunc : 	ListFunc Func	
			| Func
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRPAR {printf("Funcao(par)\n");}
			| TipeReturn TID TLPAR TRPAR {printf("Funcao()\n");}
			;

TipeReturn :	Tipe {printf(" retono ");}
			| TVOID {printf("retorno void\n");}
			;

DecPar :	DecPar TVIRG Par
			| Par
			;
			
Par :		Tipe TID
			;
			
BlocoP :	TLCH Decs ListCom TRCH {printf("Bloco P com dec\n");}
			| TLCH ListCom TRCH {printf("Bloco P\n");}
			;
			
Decs :		Decs Dec
			| Dec
			;
			
Dec :		Tipe Listid TFLIN	{printf("; Declaracao\n");}
			;
			
Tipe :		TINT	{printf("Inteiro");}
			| TSTR	{printf("Sttring");}
			;
			
Listid :	Listid TVIRG TID {printf(" ID ");}
			| TID {printf(" ID ");}
			;
			
Bloco :		TLCH ListCom TRCH {printf("Bloco\n");}
			;
			
ListCom :	ListCom Com	{printf("ListCom\n");}
			| Com	{printf("Comando\n");}
			;
			
Com :		Cse
			| Cenq
			| Catr
			| Cread
			| Cprint
			| Cfunc
			| Ret
			;
			
Ret :		TRET ExpAr TFLIN	{printf("retorna\n");}
			| TRET TLIT TFLIN	{printf("retorna string\n");}
			;
			
Cse :		TIF TLPAR ExpLog TRPAR Bloco	{printf("se\n");}
			| TIF TLPAR ExpLog TRPAR Bloco TELSE Bloco	{printf("se senao\n");}
			;
			
Cenq :		TWHILE TLPAR ExpLog TRPAR Bloco	{printf("While\n");}
			;
			
Catr :		TID TATR ExpAr TFLIN	{printf("Atribui In\nt");}
			| TID TATR TLIT TFLIN	{printf("Atribui String\n");}
			;
			
Cread :		TREAD TLPAR TID TRPAR TFLIN	{printf("Read\n");}
			;
			
Cprint :	TPRINT TLPAR ExpAr TRPAR TFLIN	{printf("Print Int\n");}
			| TPRINT TLPAR TLIT TRPAR TFLIN	{printf("Print String\n");}
			;
			
Cfunc :		TID TLPAR ListPar TRPAR TFLIN	{printf("Chamada funcao com parametros\n");}
			| TID TLPAR TRPAR TFLIN	{printf("Chamada funcao com parametros\n");}
			;
			
ListPar :	ListPar TVIRG ExpAr
			| ListPar TVITG TLIT
			| ExpAr
			|TLIT
			;
			
ExpLog :	ExpLog TAND FLog	{printf("Log AND Log\n");}
			| ExpLog TOR FLog	{printf("Log OR Log\n");}
			| FLog	{printf("Log\n");}
			;
			
FLog :		TLPAR ExpLog TRPAR	{printf("( Log )\n");}
			| TNOT FLog	{printf(" NOT Log\n");}
			| ExpRela	{printf("Relacional\n");}
			;
			
ExpRela :	ExpAr TIGUAL ExpAr	{printf("Ex == Ex\n");}
			| ExpAr TDIF ExpAr	{printf("Ex != Ex\n");}
			| ExpAr TIGUALMA ExpAr	{printf("Ex >= Ex\n");}
			| ExpAr TIGUALME ExpAr	{printf("Ex <= Ex\n");}
			| ExpAr TMAIOR ExpAr	{printf("Ex > Ex\n");}
			| ExpAr TMENOR ExpAr	{printf("Ex < Ex\n");}
			;
			
ExpAr :		ExpAr TADD Am	{printf("Soma\n");}
			| ExpAr TSUB Am	{printf("Subtracao\n");}
			| Am
			;
			
Am :		Am TMUL An	{printf("Multiplicacao\n");}
			| Am TDIV An	{printf("Divisao\n");}
			| An
			;
			
An :		TSUB An	{printf("Negativo\n");}
			| TLPAR ExpAr TRPAR	{printf("( algo )\n");}
			| TID	{printf("variavel\n");}
			| Cfunc	{printf("chamado de funcao\n");}
			| TNUM	{printf("numero\n");}
			;

%%
#include "lex.yy.c"
int yyerror (char *str)
{
	printf("Erro; %s\n", str);
	
} 		 
int yywrap()
{
	return 1;
}