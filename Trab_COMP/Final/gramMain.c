#include "gramF.h"

extern FILE *yyin;

int erro = 0;
pModulo listaSimbolos;
pInstrucao listaInstrucao[200];

int main( int argc, char const *argv[]){
	int i; 
	listaSimbolos = criarListaSimbolos();
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
		printf("\nLista de Simbolos\n");
		putsListaVariaveis( listaSimbolos);
	}
	return 0;
}

void setErro(){
	erro = 1;
}

pModulo criarListaSimbolos(){
	pModulo new;
	printf("Criando lista simbolos\n");
	new = ( pModulo)malloc( sizeof( Modulo));
	new -> listaParametros = NULL;
	new -> listaVariaveis = NULL;

	return new;
}

pModulo getListaSimbolos(){
	return listaSimbolos;
}