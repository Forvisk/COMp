%{
#include "gramF.h"
#define YYSTYPE pModulo

int linha = 0;
int nlabel = 0, labelAtual = 0;
%}

%token TID TINT TSTR TVOID TADD TINC TSUB TDEC TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TATR TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM

%%
Codigo : 	Prog			
			;
			
Prog : 		ListFunc BlocoP 	{	/*
									*/
									/*printf("Prog -> ListFunc BlocoP\n");
									putsListaVariaveis($$);*/
								}
			| BlocoP 			{	/*
									*/
									/*printf("Prog -> BlocoP\n");
									putsListaVariaveis($$);*/
								}
			;
			
ListFunc : 	ListFunc Func		{	/*
									*/
								}
			| Func 				{	/*
									*/
								}
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRPAR 	{	/*
													*/
													putsListaVariaveis($4);
												}
			| TipeReturn TID TLPAR TRPAR		{	/*
													*/
												}
			;

TipeReturn :	Tipe 			{	/*
									*/
								}
			| TVOID				{	/*
									*/
								}
			;

DecPar :	DecPar TVIRG Par 	{	/*
									*/
								}
			| Par 				{	/*
									*/
								}
			;
			
Par :		Tipe TID 			{	/*
									*/
									addNewId_Parametros( $$, $2);
									$$ = setTipoListaParametros( $$, $1);
								}
			;
			
BlocoP :	TLCH Decs ListCom TRCH 		{	/*
											*/
										}	
			| TLCH ListCom TRCH 		
			;
			
Decs :		Decs Dec 			{	/*
									*/
									/*printf("Decs -> Decs Dec\n");
									printf("%p %p\n", (void*)$1, (void*)$2);*/
									/*putsListaVariaveis( $2);*/
									/*addListaVariaveis_ListaSuperior( $1, $2);*/
									/*$$ = $1;*/
									/*putsListaVariaveis( $$);*/
								}
			| Dec 				{	/*
									*/
									/*printf("Decs -> Dec\n");
									printf("%p %p\n", (void*)$$, (void*)$1);*/
									/*putsListaVariaveis( $1);*/
									/*addListaVariaveis_ListaSuperior( $$, $1);*/
									/*putsListaVariaveis( $$);*/
								}
			;
			
Dec :		Tipe Listid TFLIN 	{	/*
									*/
									$$ = setTipoListaVariaveis( $2, $1);
									/*putsListaVariaveis( $$);*/
								}
			;
			
Tipe :		TINT 				{	/*
									*/
									$$ = criarTipo( T_INT);
								}
			| TSTR 				{	/*
									*/
									$$ = criarTipo( T_STR);
								}
			;
			
Listid :	Listid TVIRG TID 	{	/*
									*/
									addNewId_Variaveis( $1, $3);
									$$ = $1;
									/*putsListaVariaveis( $$);*/
								}
			| TID 				{	/*
									*/
									addNewId_Variaveis( $$, $1);
									/*putsListaVariaveis( $$);*/
								}
			;
			
Bloco :		TLCH ListCom TRCH
			;
			
ListCom :	ListCom Com 		{	/*
									*/
								}
			| Com 				{	/*
									*/
								}
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
			
Cse :		TIF TLPAR ExpLog TRPAR M Bloco						{	/*
																	*/
																}			
			| TIF TLPAR ExpLog TRPAR M Bloco N TELSE M Bloco 	{	/*
																	*/
																}
			;

M :				{	/*
					*/
				}
			;

N :				{	/*
					*/
				}
			;
			
Cenq :		TWHILE M TLPAR ExpLog TRPAR M Bloco		{	/*
														*/
													}
			;
			
Catr :		TID TATR ExpAr TFLIN				{	/*
													*/
												}
			| TID TATR TLIT TFLIN 				{	/*
													*/
												}
			;
			
Cread :		TREAD TLPAR TID TRPAR TFLIN			{	/*
													*/
												}
			;
			
Cprint :	TPRINT Cnprint TLPAR ExpAr TRPAR TFLIN		{	/*
															*/
														}
			| TPRINT Cnprint TLPAR TLIT TRPAR TFLIN 	{	/*
															*/
														}
			;

Cnprint :			{	/*
						*/
					}
			;
			
Cfunc :		TID TLPAR ListPar TRPAR
			| TID TLPAR TRPAR
			;
			
ListPar :	ListPar TVIRG ExpAr
			| ListPar TVIRG TLIT 	{	/*
										*/
									}
			| ExpAr
			| TLIT 					{	/*
										*/
									}
			;
			
ExpLog :	ExpLog TAND M FLog		{	/*
										*/
									}

			| ExpLog TOR M FLog		{	/*
										*/
									}

			| FLog					{	/*
										*/
									}

			;
			
FLog :		TLPAR ExpLog TRPAR		{	/*
										*/
									}

			| TNOT FLog				{	/*
										*/
									}

			| ExpRela 				{	/*
										*/
									}

			;
			
ExpRela :	ExpAr TIGUAL ExpAr			{	/*
											*/
										}
			| ExpAr TDIF ExpAr			{	/*
											*/
										}
			| ExpAr TIGUALMA ExpAr		{	/*
											*/
										}
			| ExpAr TIGUALME ExpAr		{	/*
											*/
										}
			| ExpAr TMAIOR ExpAr		{	/*
											*/
										}
			| ExpAr TMENOR ExpAr		{	/*
											*/
										}
			;
			
ExpAr :		ExpAr TADD Am			{	/*
										*/
									}
			| ExpAr TSUB Am			{	/*
										*/
									}
			| Am					{	/*
										*/
									}
			;
			
Am :		Am TMUL An 				{	/*
										*/
									}
			| Am TDIV An 			{	/*
										*/
									}
			| An 					{	/*
										*/
									}
			;
			
An :		TSUB An 				{	/*
										*/
									}
			| TLPAR ExpAr TRPAR
			| TID 					{	/*
										*/
									}
			| Cfunc 				{	/*
										*/
									}
			| TNUM					{	/*
										*/
									}
			;

%%
#include "lex.yy.c"
int yyerror (char *str){
	printf("Erro em %i - %s; %s\n", linha, yytext, str);
	//setPossuiErro();
} 		 
int yywrap(){
	return 1;
}
