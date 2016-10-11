#include <stdio.h>

extern FILE *yyin;

int main(int argc, char const *argv[])
{
	yyin = fopen( argv[ 1], "r")
	yyparse();
	fclose(yyin);
	return 0;
}