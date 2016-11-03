
#include "gram.h"

extern FILE *yyin;

#define ARQUIVO1 "Exemlo1.c"
#define ARQUIVO2 "Exemlo2.c"
#define ARQUIVO3 "Exemlo3.c"

/*
*	Adriano Zanella Junior
*	
*/

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos greatList;
pInstrucao listaInstrucao[200];

int posValGlobal = 1;

int main(int argc, char const *argv[])
{
	int i;
	for( i = 0; i < 200; i++){
		listaInstrucao[ i] = NULL;
	}
	greatList = createGreatList();
	yyin = fopen( argv[ 1], "r");
	if( yyin != NULL){
		yyparse();
	}else{
		printf("Arquivo nao encontrado!");
	}
	fclose(yyin);

	putsListId(greatList);
	putsListaInstrucao();
	return 0;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void putsListId( pListaAtributos lista){
	printf("\nTabela de simbolos %p:\n", (void*)lista);
	printf("\tsimbolo\n\n");
	if( lista->lista != NULL){
		pAtributo aux = lista->lista;
		do{
			printf("\t%s\n", aux->nomeId);
			aux = aux->proximo;
		}while( aux != NULL);
	}
	printf("\n");
}

void putsListaInstrucao(){
	int numIntrucoes = 0;
	char instrucao[11];
	printf("\nLista de instruções:\n");
	while( listaInstrucao[ numIntrucoes] != NULL){

		switch (listaInstrucao[ numIntrucoes] -> byte_code){
			case IADD:
				strncpy(instrucao, "IADD", 10);
			break;

			case ISUB:
				strncpy(instrucao, "ISUB", 10);
			break;

			case IMUL:
				strncpy(instrucao, "IMUL", 10);
			break;

			case IDIV:
				strncpy(instrucao, "IDIV", 10);
			break;

			case INEG:
				strncpy(instrucao, "INEG", 10);
			break;

			case ISTORE:
				strncpy(instrucao, "ISTORE", 10);
			break;

			case ILOAD:
				strncpy(instrucao, "ILOAD", 10);
			break;

			case BIPUSH:
				strncpy(instrucao, "BIPUSH", 10);
			break;

			case LDC:
				strncpy(instrucao, "LDC", 10);
			break;

			case ICONST_0:
				strncpy(instrucao, "ICONST_0", 10);
			break;

			case ICONST_1:
				strncpy(instrucao, "ICONST_1", 10);
			break;

			case ICONST_2:
				strncpy(instrucao, "ICONST_2", 10);
			break;

			case ICONST_3:
				strncpy(instrucao, "ICONST_3", 10);
			break;

			case ICONST_4:
				strncpy(instrucao, "ICONST_4", 10);
			break;

			case ICONST_5:
				strncpy(instrucao, "ICONST_5", 10);
			break;

			case IAND:
				strncpy(instrucao, "IAND", 10);
			break;

			case IOR:
				strncpy(instrucao, "IOR", 10);
			break;

			case GETSTATIC:
				strncpy(instrucao, "GETSTATIC", 10);
			break;

			case INVOKEVIRTUAL:
				strncpy(instrucao, "INVOKEVIRTUAL", 10);
			break;



			default:
				strncpy(instrucao, "NOT YET", 10);

		}
		printf("Intrucao: %p\t%s\n\tPar1 %i Par2 %i\n\tlabel: %i\n",
												 listaInstrucao[ numIntrucoes]->byte_code,
												 instrucao,
												 listaInstrucao[ numIntrucoes]->parametro_1,
												 listaInstrucao[ numIntrucoes]->parametro_2,
												 listaInstrucao[ numIntrucoes]-> label
												 );
		numIntrucoes++;
	}
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos getGreatList(){
	return greatList;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pInstrucao* getListaInstrucao(){
	return listaInstrucao;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
