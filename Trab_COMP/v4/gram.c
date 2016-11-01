
#include "gram.h"

extern FILE *yyin;

#define ARQUIVO1 "Exemlo1.c"
#define ARQUIVO2 "Exemlo2.c"
#define ARQUIVO3 "Exemlo3.c"

/*
*	Adriano Zanella Junior
*	
*/

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

/*________________________________________________________________________________________*/
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
	printf("\nLista de instruções:\n");
	while( listaInstrucao[ numIntrucoes] != NULL){
		printf("Intrucao: %p\n\tPar1 %i Par2 %i\n\tlabel: %i\n",
												 listaInstrucao[ numIntrucoes]->byte_code,
												 listaInstrucao[ numIntrucoes]->parametro_1,
												 listaInstrucao[ numIntrucoes]->parametro_2,
												 listaInstrucao[ numIntrucoes]-> label
												 );
		numIntrucoes++;
	}
}

/*________________________________________________________________________________________*/
pListaAtributos getGreatList(){
	return greatList;
}

pInstrucao* getListaInstrucao(){
	return listaInstrucao;
}