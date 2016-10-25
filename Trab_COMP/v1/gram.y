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
			
Ret :		TRET ExpAr TFLIN	{printf("retorna exp\n");}
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
			|TLIT
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
	printf("Erro %s; %s\n", yytext, str);
	
} 		 
int yywrap()
{
	return 1;
}
