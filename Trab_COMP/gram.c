#include <stdio.h>

extern FILE *yyin;

#define ARQUIVO1 "Exemlo1.c"
#define ARQUIVO2 "Exemlo2.c"
#define ARQUIVO3 "Exemlo3.c"

int main(int argc, char const *argv[])
{
	yyin = fopen( argv[ 1], "r");
	if( yyin != NULL){
		printf("Abrindo arquivo %s. \n", argv[1]);
		yyparse();
	}else{
		printf("Arquivo nao encontrado!");
	}
	fclose(yyin);
	return 0;
}
