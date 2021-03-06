%{
#include "gram.h"
#define YYSTYPE pListaAtributos

int linha = 0;
int nlabel = 0, labelAtual = 0;
%}

%token TID TINT TSTR TVOID TADD TINC TSUB TDEC TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TATR TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM

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
			
Cse :		TIF TLPAR ExpLog TRPAR M Bloco						{	
																	corrigirLabel( $3 -> seVerdadeiro, $5 -> label);
																	

																	nlabel++;
																	/*printf("n_labl %i\n", nlabel);*/
																	labelAtual = nlabel;
																	addLabel( labelAtual);

																	corrigirLabel( $3 -> seFalso, labelAtual);
																	free($3);
																	free($5);
																}			
			| TIF TLPAR ExpLog TRPAR M Bloco N TELSE M Bloco 	{	
																	corrigirLabel( $3 -> seVerdadeiro, $5 -> label);
																	corrigirLabel( $3 -> seFalso, $9 -> label);	

																	nlabel++;
																	/*printf("n_labl %i\n", nlabel);*/
																	labelAtual = nlabel;
																	addLabel( labelAtual);

																	corrigirLabel( $7 -> seVerdadeiro, labelAtual);

																	free($3);
																	free($5);
																	free($7);
																	free($9);
																}
			;

M :			{	nlabel++;
				/*printf("n_labl %i\n", nlabel);*/
				labelAtual = nlabel;
				$$ = addLabel( labelAtual);
			}
			;

N :			{	
				int linha = getTamListInstrucoes(); 
				addGoto( labelAtual);
				/*printf("%i ifelse GOTO", linha);*/
				$$ = createListVeF( GOTO, linha);
				$$ -> label = labelAtual;
			}
			;
			
Cenq :		TWHILE M TLPAR ExpLog TRPAR M Bloco		{   
														corrigirLabel( $4 -> seVerdadeiro, $6 -> label);
														addGoto($2 -> label);

														nlabel++;
														/*printf("n_labl %i\n", nlabel);*/
														labelAtual = nlabel;
														addLabel( labelAtual);

														corrigirLabel( $4 -> seFalso, labelAtual);

														free($2);
														free($4);
														free($6);
													}
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
			
ExpLog :	ExpLog TAND M FLog		{	
										corrigirLabel( $1 -> seVerdadeiro, $3 -> label);
										$$ = mergeAnd( $4, $1);
									}
			| ExpLog TOR M FLog		{	
										corrigirLabel( $1 -> seFalso, $3 -> label);
										$$ = mergeOr( $4, $1);
									}
			| FLog					{	
										$$ = $1;
									}
			;
			
FLog :		TLPAR ExpLog TRPAR		{	
										$$ = $2;
									}
			| TNOT FLog				{	$$ = not( $2);
									}
			| ExpRela 				{	
										$$ = $1;
									}
			;
			
ExpRela :	ExpAr TIGUAL ExpAr			{	int linha = getTamListInstrucoes();
											$$ = createListVeF( IFEQ, linha);
											addIf( IFEQ, -1, -1, labelAtual);
										}
			| ExpAr TDIF ExpAr			{	int linha = getTamListInstrucoes();
											$$ = createListVeF( IFDIF, linha);
											addIf( IFDIF, -1, -1, labelAtual);
										}
			| ExpAr TIGUALMA ExpAr		{	int linha = getTamListInstrucoes();
											$$ = createListVeF( IFMAEQ, linha);
											addIf( IFMAEQ, -1, -1, labelAtual);
										}
			| ExpAr TIGUALME ExpAr		{	int linha = getTamListInstrucoes();
											$$ = createListVeF( IFMEEQ, linha);
											addIf( IFMEEQ, -1, -1, labelAtual);
										}
			| ExpAr TMAIOR ExpAr		{	int linha = getTamListInstrucoes();
											$$ = createListVeF( IFMA, linha);
											addIf( IFMA, -1, -1, labelAtual);
										}
			| ExpAr TMENOR ExpAr		{	int linha = getTamListInstrucoes();
											$$ = createListVeF( IFME, linha);
											addIf( IFME, -1, -1, labelAtual);
										}
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
			| TID 					{ 	
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
	setPossuiErro();
} 		 
int yywrap(){
	return 1;
}
