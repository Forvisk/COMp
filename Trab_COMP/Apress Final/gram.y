%{
#include "gram.h"
#define YYSTYPE pListaAtributos

int linha = 0;
int nlabel = 0, labelAtual = 0;
%}

%token TID TINT TSTR TVOID TADD TINC TSUB TDEC TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TATR TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM TMAISIGUAL

%%
Codigo : 	Prog			
			;
			
Prog : 		ListFunc BlocoP 	
			| BlocoP 			
			;
			
ListFunc : 	ListFunc Func	{	
								addToGreatList( $2, 0, $2 -> tipe_temp);
							}
			| Func 			{	
								addToGreatList( $1, 0, $1 -> tipe_temp);
							}
			;
			
Func : 		TipeReturn TID TLPAR DecPar TRPAR 	{	
													addIdToList( $4, $2);
													addToGreatList($4, 0, T_TODEF);
												}
			| TipeReturn TID TLPAR TRPAR		{	
													addIdToList( $4, $2);
													addToGreatList($4, 0, T_TODEF);
												}
			;

TipeReturn :	Tipe 			{	$$ = $1;
								}
			| TVOID				{	$$ = createTipe( T_VOID);
								}
			;

DecPar :	DecPar TVIRG Par 	{	/*addIdToList( $1, $3);*/
								}
			| Par 				{	/*addIdToList( $$, $1);*/
								}
			;
			
Par :		Tipe TID 	{	addIdToList( $2, $2);
							addToGreatList($2, 1, $1 -> tipe_temp);
						}
			;
			
BlocoP :	TLCH Decs ListCom TRCH 		
			| TLCH ListCom TRCH 		
			;
			
Decs :		Decs Dec 	{	
								/*printf("Decs -> Decs Dec %p %p\n", (void*)$$, (void*)$2);*/
							addToGreatList( $2, 1, $2 -> tipe_temp);
						}
			| Dec 		{	
								/*printf("Decs -> Dec %p %p\n", (void*)$$, (void*)$1);*/
							addToGreatList( $1, 1, $1 -> tipe_temp);
						}
			;
			
Dec :		Tipe Listid TFLIN 	{	
									$2 -> tipe_temp = $1 -> tipe_temp;
									$$ = $2;
									free($1);
								}
			;
			
Tipe :		TINT 				{
									$$ = createTipe( T_INT);
								}
			| TSTR 				{
									$$ = createTipe( T_STR);
								}
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

			| Caddatr
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

Caddatr :	TID Inc TMAISIGUAL ExpAr TFLIN	{	if( existeId( getGreatList(), $1) == 1){
													setPossuiErro();
												}
												corrigirPosVal( $2 -> seVerdadeiro, getPosVal($1->nomeIdTemp));
												addInstrucaoLista( IADD, INVAL, INVAL, labelAtual, 0);
												addInstrucaoListaPosVal( ISTORE, getPosVal( $1 -> nomeIdTemp), -1, labelAtual);
											}
			;

Inc :	{	
			int linha = getTamListInstrucoes();
			$$ = createListVeF( ILOAD, linha);
			addInstrucaoListaPosVal( ILOAD, 0, -1, labelAtual);
		}
		;
			
Catr :		TID TATR ExpAr TFLIN		{	
											addInstrucaoListaPosVal( ISTORE, getPosVal( $1 -> nomeIdTemp), -1, labelAtual);
										}
			| TID TATR TLIT TFLIN 		{
											addLdc( addLiteralLista( $3), labelAtual);
											addInstrucaoListaPosVal( ISTORE, getPosVal( $1 -> nomeIdTemp), -1, labelAtual);
										}
			;
			
Cread :		TREAD TLPAR TID TRPAR TFLIN					{	
															int tipe = getTipe( $3->nomeIdTemp);
															if( tipe == T_INT){
																/*printf(" ler inteiro %s\n", $3->nomeIdTemp);*/
																addNumLista( 3, labelAtual);
															} else if( tipe == T_STR){
																/*printf(" ler string %s\n", $3->nomeIdTemp);*/
																addLdc( "\"Aqui temos sorvete\"", labelAtual);
															} else {
																printf("\nErro %s %i\n", $3->nomeIdTemp, tipe);
																setPossuiErro();
															}
															if( existeId( getGreatList(), $3) == 1){
																setPossuiErro();
															}
															addInstrucaoListaPosVal( ISTORE, getPosVal($3->nomeIdTemp), -1, labelAtual);
														}
			;
			
Cprint :	TPRINT Cnprint TLPAR ExpAr TRPAR TFLIN		{	/*addInstrucaoLista( INVOKEVIRTUAL, PRINT_INT, INVAL, labelAtual);*/
															if( $4 -> tipe_temp == T_INT)
																addPrintInt( labelAtual);
															else if( $4 -> tipe_temp == T_STR)
																addPrintStr(labelAtual);
															else{
																setPossuiErro();
																printf("\nTipo incompativel para escrita\n");
															}
														}
			| TPRINT Cnprint TLPAR TLIT TRPAR TFLIN 	{ 	/*addInstrucaoLista( LDC, addLiteralLista( $4), INVAL, labelAtual);*/
															/*addInstrucaoLista( INVOKEVIRTUAL, PRINT_STR, INVAL, labelAtual);*/
															/*printf("\nliteral : %s\n", $4 -> literal);*/
															addLdc( addLiteralLista( $4), labelAtual);
															addPrintStr( labelAtual);

														}
			;

Cnprint :		{ 	addGetstaticSout( labelAtual);
				}
			;
			
Cfunc :		TID TLPAR ListPar TRPAR
			| TID TLPAR TRPAR
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
			
ExpAr :		ExpAr TADD Am		{	addInstrucaoLista( IADD, INVAL, INVAL, labelAtual, 0);
								}
			| ExpAr TSUB Am		{	addInstrucaoLista( ISUB, INVAL, INVAL, labelAtual, 0);
								}
			| Am				{	$$ = $1;
								}
			;
			
Am :		Am TMUL An 				{	
										addInstrucaoLista( IMUL, INVAL, INVAL, labelAtual, 0);
									}
			| Am TDIV An 			{	
										addInstrucaoLista( IDIV, INVAL, INVAL, labelAtual, 0);
									}
			| An 					{	
										$$ = $1;
									}
			;
			
An :		TSUB An 				{	
										addInstrucaoLista( INEG, INVAL, INVAL, labelAtual, 0);
									}
			| TLPAR ExpAr TRPAR
			| TID 					{ 	
										if( existeId( getGreatList(), $1 -> nomeIdTemp) == 1){
											setPossuiErro();
											printf("ID %s não existe\n", $1 -> nomeIdTemp);
										}
										addInstrucaoListaPosVal( ILOAD, getPosVal($1->nomeIdTemp), -1, labelAtual);
										$$ -> tipe_temp = getTipe( $1 -> nomeIdTemp);
										/*printf("\n%i\n", $$ ->tipe_temp);*/
										free($1);
									}
			| Cfunc 				{
										if( existeId( getGreatList(), $1) == 0){
											printf("\nFuncao nao implemetada\n");
										}
									}
			| TNUM					{	
										addNumLista( $1 -> numTemp, labelAtual);
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
