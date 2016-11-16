	
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
		i = 1;
		yyparse();
		fclose(yyin);
	}else{
		i = 0;
		printf("Arquivo nao encontrado!");
	}


	if( i == 1){
		putsListId(greatList);
		//putsListaLiteral();

		createCabecalho( argv[ 1]);
		createMethodMain();

		putsListaInstrucao();

		endMethodMain();
		
		//createJar( argv[ 1]);
	}
	/*
		char test = getPos
	*/
	printf("\n");
	return 0;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void createCabecalho(char* nomeArquivo){
	printf(".class public %s\n", nomeArquivo);
	printf(".super java/lang/Object\n\n");
	printf(".method public <init>()V\n");
	printf("  aload_0\n\n");
	printf("  invokevirtual java/lang/Object/<init>()V\n");
	printf("  return\n");
	printf(".end method\n\n");
	/*printf(".limit stack 10\n");

	int numVariaveisLocais = 0;
	pAtributo aux;
	if( greatList -> lista != NULL){
		pAtributo aux = greatList -> lista;
		do{
			//printf("\t%s\t%i\n", aux->nomeId, aux->posVal);
			if( aux -> posVal != -1)
				numVariaveisLocais++;
			aux = aux->proximo;
		}while( aux != NULL);
	}
	printf(".limit local %i\n", numVariaveisLocais);
	printf("\n");*/
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void writeCabecalho(char* nomeArquivo, FILE *arq){
	fprintf( arq, ".class public %s\n", nomeArquivo);
	fprintf( arq, ".super java/lang/Object\n\n");
	fprintf( arq, ".method public <init>()V\n");
	fprintf( arq, "  aload_0\n\n");
	fprintf( arq, "  invokevirtual java/lang/Object/<init>()V\n");
	fprintf( arq, "  return\n");
	fprintf( arq, ".end method\n\n");
	/*printf(".limit stack 10\n");

	int numVariaveisLocais = 0;
	pAtributo aux;
	if( greatList -> lista != NULL){
		pAtributo aux = greatList -> lista;
		do{
			//printf("\t%s\t%i\n", aux->nomeId, aux->posVal);
			if( aux -> posVal != -1)
				numVariaveisLocais++;
			aux = aux->proximo;
		}while( aux != NULL);
	}
	printf(".limit local %i\n", numVariaveisLocais);
	printf("\n");*/
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void createMethodMain(){
	printf(".method public static main([Ljava/lang/String;)V\n");
	printf(".limit stack 10\n");

	int numVariaveisLocais = 0;
	pAtributo aux;
	if( greatList -> lista != NULL){
		pAtributo aux = greatList -> lista;
		do{
			//printf("\t%s\t%i\n", aux->nomeId, aux->posVal);
			if( aux -> posVal != -1)
				numVariaveisLocais++;
			aux = aux->proximo;
		}while( aux != NULL);
	}
	printf(".limit local %i\n", numVariaveisLocais);
}


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void writeMethodMain( FILE *arq){
	fprintf( arq, ".method public static main([Ljava/lang/String;)V\n");
	fprintf( arq, ".limit stack 10\n");

	int numVariaveisLocais = 0;
	pAtributo aux;
	if( greatList -> lista != NULL){
		pAtributo aux = greatList -> lista;
		do{
			//printf("\t%s\t%i\n", aux->nomeId, aux->posVal);
			if( aux -> posVal != -1)
				numVariaveisLocais++;
			aux = aux->proximo;
		}while( aux != NULL);
	}
	fprintf( arq, ".limit local %i\n", numVariaveisLocais);
}


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void endMethodMain(){
	printf("\n  .return\n.end method");
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void writeEndMethodMain( FILE *arq){
	fprintf( arq, "\n  .return\n.end method");
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void putsListId( pListaAtributos lista){
	printf("\nTabela de simbolos %p:\n", (void*)lista);
	printf("\tsimbolo\tposVal\n\n");
	if( lista->lista != NULL){
		pAtributo aux = lista->lista;
		do{
			printf("\t%s\t%i\n", aux->nomeId, aux->posVal);
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
	//printf("\nLista de instruções:\n");
	while( listaInstrucao[ numIntrucoes] != NULL){
		printf("\n%i", numIntrucoes);
		if( listaInstrucao[ numIntrucoes] -> label != 0)
			printf("  ");
		printf("  %s", listaInstrucao[ numIntrucoes]->byte_code);

		if( strncmp( listaInstrucao[ numIntrucoes] -> parametro_1, INVAL, 2000) != 0){
			printf(" %s", listaInstrucao[ numIntrucoes] -> parametro_1);

			if( strncmp( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL, 2000) != 0)
				printf(" %s", listaInstrucao[ numIntrucoes] -> parametro_2);
			
		}
		//printf("\n\t%i", listaInstrucao[ numIntrucoes] -> label);
		numIntrucoes++;
	}
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

void writeListaInstrucao( FILE *arq){
	int numIntrucoes = 0;
	//char instrucao[21];
	//printf("\nLista de instruções:\n");
	while( listaInstrucao[ numIntrucoes] != NULL){
		if( listaInstrucao[ numIntrucoes] -> label != 0)
			fprintf( arq, "\t");
		fprintf( arq, "\n  %s", listaInstrucao[ numIntrucoes]->byte_code);
		if( strncmp( listaInstrucao[ numIntrucoes] -> parametro_1, INVAL, 2000) != 0){
			fprintf( arq, " %s", listaInstrucao[ numIntrucoes] -> parametro_1);

			if( strncmp( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL, 2000) != 0)
				fprintf( arq, " %s", listaInstrucao[ numIntrucoes] -> parametro_2);
			
		}
		//printf("\n\t%i", listaInstrucao[ numIntrucoes] -> label);
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
	printf("\n");
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

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int createJar( char* argc){
	FILE *newArquivo;
	char nomeNew[strlen(argc) + 3];
	int i = 0;
	while( argc[ i] != '.' && argc[ i] != '\0' && i < strlen(argc)){
		nomeNew[ i] = argc[ i];
		i++;
	}
	nomeNew[ i++] = '.';
	nomeNew[ i++] = 'j';
	nomeNew[ i++] = '\0';
	printf("\n%s\n", nomeNew);

	newArquivo = fopen( nomeNew, "w");
	if( newArquivo == NULL){
		printf("Erro ao criar o novo arquivo\nEncerrando...\n");
		return 0;
	}
	writeCabecalho( nomeNew, newArquivo);
	writeMethodMain( newArquivo);
	writeListaInstrucao( newArquivo);
	writeEndMethodMain( newArquivo);

	fclose(newArquivo);

	return 1;
}