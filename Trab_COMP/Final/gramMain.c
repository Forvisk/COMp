#include "gramF.h"

extern FILE *yyin;

int erro = 0;

int main( int argc, char const *argv[]){
	int i; 

	yyin = fopen( argv[ 1], "r");
	if( yyin != NULL){
		i = 1;
		yyparse();
		fclose(yyin);
	}else{
		i = 0;
		printf("Arquivo nao encontrado!");
	}

	return 0;
}

void setErro(){
	erro = 1;
}