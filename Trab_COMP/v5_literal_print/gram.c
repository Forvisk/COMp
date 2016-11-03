	
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
pListaLiteral primeiroLiteral;

int posValGlobal = 1;

int main(int argc, char const *argv[])
{
	int i;
	for( i = 0; i < 200; i++){
		listaInstrucao[ i] = NULL;
	}

	primeiroLiteral = NULL;

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
	//putsListaLiteral();
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

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void putsListaInstrucao(){
	int numIntrucoes = 0;
	//char instrucao[21];
	printf("\nLista de instruções:\n");
	while( listaInstrucao[ numIntrucoes] != NULL){
		printf("Intrucao:\n\t%s", listaInstrucao[ numIntrucoes]->byte_code);

		if( strncmp( listaInstrucao[ numIntrucoes] -> parametro_1, INVAL, 2000) != 0){
			printf("\t%s", listaInstrucao[ numIntrucoes] -> parametro_1);

			if( strncmp( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL, 2000) != 0)
				printf("\t%s", listaInstrucao[ numIntrucoes] -> parametro_2);
			
		}
		printf("\n\t%i\n", listaInstrucao[ numIntrucoes] -> label);
		numIntrucoes++;
	}
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void putsListaLiteral(){
	printf("\nLista literais\n");
	pListaLiteral aux = primeiroLiteral;
	while( aux != NULL){
		printf("\t%s\n", aux -> literal);
		aux = aux -> proximo;
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

pListaLiteral getListaLiteral(){
	return primeiroLiteral;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void setPrimeiroListaLiteral( pListaLiteral primeiro){
	primeiroLiteral = primeiro;
	//printf("primeiro lit : %s\n", primeiroLiteral -> literal);
}