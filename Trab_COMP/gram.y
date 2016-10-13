%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TID TINT TSTR TATR TADD TSUB TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TTRUE TFALSE TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM

%%
Codigo : 	Prog TFIM		{printf("");}
			;
			
Prog : 		ListFunc BlocoP		{printf("");}
			| BlocoP	{printf("");}
			;
			
ListFunc : 	ListFunc Func	{printf("");}
			| Func	{printf("");}
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRDIR	{printf("");}
			| TipeReturn TID TLPAR TRPAR	{printf("");}
			;
			
DecPar :	DecPar TVIRG Par	{printf("");}
			| Par	{printf("");}
			;
			
Par :		Tipe TID
			;
			
BlocoP :	TLCH Decs ListCom TRCH	{printf("");}
			| TLCH ListCom TRCH	{printf("");}
			;
			
Decs :		Decs Dec	{printf("");}
			| Dec	{printf("");}
			;
			
Dec :		Tipe Listid TFLIN	{printf("");}
			;
			
Tipe :		TINT	{printf("");}
			| TSTR	{printf("");}
			;
			
Listid :	Listid TVIRG TID	{printf("");}
			| TID	{printf("");}
			;
			
Bloco :		TLCH ListCom TRCH	{printf("");}
			;
			
ListCom :	ListCom Com	{printf("");}
			| Com	{printf("");}
			;
			
Com :			Cse	{printf("");}
			| Cenq	{printf("");}
			| Catr	{printf("");}
			| Cread	{printf("");}
			| Cprint	{printf("");}
			| Cfunc	{printf("");}
			| Ret	{printf("");}
			;
			
Ret :			TRET ExpAr TFLIN	{printf("");}
			;
			
Cse :			TIF TLPAR ExpLog TRPAR Bloco	{printf("");}
			| TIF TLPAR ExpLog TRPAR Bloco TELSE Bloco	{printf("");}
			;
			
Cenq :			TWHILE TLPAR ExpLog TRPAR Bloco	{printf("");}
			;
			
Catr :			TID TATR ExpAr TFLIN	{printf("");}
			| TID TATR TLIT TFLIN	{printf("");}
			;
			
Cread :			TREAD TLPAR TID TRPAR TFLIN	{printf("");}
			;
			
Cprint :		TPRINT TLPAR ExpAr TRPAR TFLIN	{printf("");}
			| TPRINT TLPAR TLIT TRPAR TFLIN	{printf("");}
			;
			
Cfunc :			TID TLPAR ListPar TRPAR TFLIN	{printf("");}
			| TID TLPAR TRPAR TFLIN	{printf("");}
			;
			
ListPar :		ListPar TVIRG ExpAr	{printf("");}
			| ExpAr	{printf("");}
			;
			
ExpLog :		ExpLog TAND FLog	{printf("");}
			| ExpLog TOR FLog	{printf("");}
			| FLog	{printf("");}
			;
			
FLog :			TLPAR ExpLog TRPAR	{printf("");}
			| TNOT FLog	{printf("");}
			| ExpRela	{printf("");}
			;
			
ExpRela :		ExpAr TIGUAL ExpAr	{printf("");}
			| ExpAr TDIF ExpAr	{printf("");}
			| ExpAr TIGUALMA ExpAr	{printf("");}
			| ExpAr TIGUALME ExpAr	{printf("");}
			| ExpAr TMAIOR ExpAr	{printf("");}
			| ExpAr TMENOR ExpAr	{printf("");}
			;
ExpAr :		A
			;
A :			A TADD G
			| A TSUB G
			| G
			;
G :			G TMUL H
			| G TDIV H
			| H
			;
H :			TSUB H
			| TLPAR A TRPAR
			| TID
			| Cfunc
			| TNUM
			;

%%
#include "lex.yy.c"
int yyerror (char *str)
{
	printf("%s - antes %s\n", str, yytext);
	
} 		 
int yywrap()
{
	return 1;
}
