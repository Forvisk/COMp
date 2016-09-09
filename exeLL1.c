// Analisador Sintatico LL(1)
// Exercicio Compiladores LL(1) p/ Disciplina de Compiladores    
// Adriano Zanella Junior
//
// Baseado no código de Cristiano Damiani Vasconcellos

// Compilação gcc -Wall -o exell1 exeLL1.c

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

/* Nao terminais o bit mais significativo ligado indica que se trata de um nao
terminal */
#define EXPR   0x8001	// E
#define EXPRL  0x8002	// E'
#define TERMO  0x8003	// T
#define TERMOL 0x8004	// T'
#define FATOR  0x8005	// C

/* Terminais */
#define ERRO 	0x0000
#define AND     0x0100	// e
#define OR 		0X0200	// ou
#define SESOSE	0x0300	// se e somente se
#define SEENT	0x0400	// se então
#define VALLOG  0x0500 	// V ou F
#define NOT		0x0600	// negação
#define LPAR	0x0700 	// (
#define RPAR	0x0800 	// )
#define FIM		0x0900

//Mascaras
#define NTER   0x8000
#define NNTER  0x7FFF

#define TAMPILHA 100


struct Pilha {
	int topo;
	int dado[TAMPILHA];
};

/* Producoes a primeira posicao do vetor indica quantos simbolos
gramaticais a producao possui em seu lado direito */

const int PROD1[] = {2, TERMO, EXPRL};        	// E  -> TE' 	(1)
const int PROD2[] = {3, SESOSE, TERMO, EXPRL};  // E' -> <->TE'	(2)
const int PROD3[] = {3, SEENT, TERMO, EXPRL};   // E' -> ->TE'	(3)
const int PROD4[] = {0};                      	// E' -> vazio	(4)
const int PROD5[] = {2, FATOR, TERMOL};       	// T  -> CT'	(5)
const int PROD6[] = {3, AND, FATOR, TERMOL};  	// T' -> &CT'	(6)
const int PROD7[] = {3, OR, FATOR, TERMOL};  	// T' -> |CT'	(7)
const int PROD8[] = {0};                      	// T' -> vazio	(8)
const int PROD9[] = {1, VALLOG};				// C  -> c 		(9)
const int PROD10[]= {3, LPAR, EXPR, RPAR};		// C  -> (E)	(10)
const int PROD11[]= {2, NOT, FATOR};			// C  -> ~C 	(11)

// vetor utilizado para mapear um numero e uma producao.
const int *PROD[] = {NULL, PROD1, PROD2, PROD3, PROD4, PROD5, PROD6, PROD7, PROD8, PROD9, PROD10, PROD11};

// Tabela sintatica LL(1). Os numeros correspondem as producoes acima.
						//    &  | <-> ->  c  ~   (   )  #
const int STAB[5][9] = {	{ 0, 0, 0, 0, 1,  1,  1,  0, 0}, // E
							{ 0, 0, 2, 3, 0,  0,  0,  4, 4}, // E'
							{ 0, 0, 0, 0, 5,  5,  5,  0, 0}, // T
							{ 6, 7, 8, 8, 0,  0,  0,  8, 8}, // T'
							{ 0, 0, 0, 0, 9, 11, 10, 10, 0}  // C
						};

/*****************************************************************
* int lex (char *str, int *pos)                                  *
* procura o proximo token dentro de str a partir de *pos,incre-  *
* menta o valor de *pos a medida que faz alguma tranzicao de     *
* estados.                                                       *
* Retorna o inteiro que identifica o token encontrado.           *
******************************************************************/

int lex (char *str, int *pos){
	int estado = 0, i = 0;
	char c;

	while (i < 10){
		c =  str[*pos];
		//printf("loop: %c %i\n", c, *pos);

		switch(estado){
			case 0:
				switch(c){
					case ' ':
						(*pos)++;
						break;
					case 'V':
						(*pos)++;
						printf(" V\n");
						return VALLOG;
					case 'F':
						(*pos)++;
						printf(" F\n");
						return VALLOG;
					case 'v':
						(*pos)++;
						printf(" v\n");
						return VALLOG;
					case 'f':
						(*pos)++;
						printf(" f\n");
						return VALLOG;
					case '-':
						(*pos)++;
						printf(" -");
						estado = 1;
						break;
					case '<':
						(*pos)++;
						printf(" <");
						estado = 2;
						break;
					case '&':
						(*pos)++;
						printf(" &\n");
						return AND;
					case '|':
						(*pos)++;
						printf(" |\n");
						return OR;
					case '~':
						(*pos)++;
						printf(" ~\n");
						return NOT;
					case '(':
						(*pos)++;
						printf(" (\n");
						return LPAR;
					case ')':
						(*pos)++;
						printf(" )\n");
						return RPAR;
					case '\0':
						printf("FIM\n");
						return FIM;
					default:
						(*pos)++;
						printf("ERRO\n");
						return ERRO;
				}
				break;
			case 1:		// caso encontrou o traco do Se então ( -> )
				(*pos)++;
				if( c == '>'){
					printf(">\n");
					return SEENT;
				}else{
					printf("ERRO\n");
					return ERRO;
				}
				break;
			case 2:		// caso encontrou o menor que do Se somente se ( <-> )(*pos)++;
				(*pos)++;
				if( c == '-'){
					printf("-");
					estado = 3;
				}else{
					printf("ERRO\n");
					return ERRO;
				}
				break;
			case 3:		// caso encontrou o traço do  Se somente se ( <-> )(*pos)++;
				(*pos)++;
				if( c == '>'){
					printf(">\n");
					return SESOSE;
				}else{
					printf("ERRO\n");
					return ERRO;
				}
				break;
			default:
					printf("Lex:Estado indefinido");
					exit(1);
		}
	i++;
	}
}

/*****************************************************************
* void erro (char *erro, char *expr, int pos)                    *
* imprime a mensagem apontado por erro, a expressao apontada por *
* expr, e uma indicacao de que o erro ocorreu na posicao pos de  *
* expr. Encerra a execucao do programa.                          *
******************************************************************/

void erro (char *erro, char *expr, int pos) {
	int i;
	printf("%s", erro);
	printf("\n%s\n", expr);
	for (i = 0; i < pos-1; i++)
		putchar(' ');
	putchar('^');
	printf("\n");
	exit(1);
}

/*****************************************************************
* void inicializa(struct Pilha *p)                               *
* inicializa o topo da pilha em -1, valor que indica que a pilha *
* esta vazia.                                                    *
******************************************************************/

void inicializa(struct Pilha *p) {
	p->topo = -1;
}

/*****************************************************************
* void insere (struct Pilha *p, int elemento                     *
* Insere o valor de elemento no topo da pilha apontada por p.    *
******************************************************************/

void insere (struct Pilha *p, int elemento) {
	if (p->topo < TAMPILHA) {
		p->topo++;
		p->dado[p->topo] = elemento;
		printf("Insere 0x%04x\n", elemento);
	}else{
		printf("estouro de pilha");
		exit (1);
	}
}

/*****************************************************************
* int remover (struct Pilha *p)                                  *
* Remove e retorna o valor armazenado no topo da pilha apontada  *
* por p                                                          *
******************************************************************/

int remover (struct Pilha *p) {
	int aux;

	if (p->topo >= 0) {
		printf("Remove 0x%04x\n", p->dado[p->topo]);
		aux = p->dado[p->topo];
		p->topo--;
		return aux;
	}else{
		printf("Pilha vazia");
		exit(1);
	}
	return 0;
}

/*****************************************************************
* int consulta (struct Pilha *p)                                 *
* Retorna o valor armazenado no topo da pilha apontada por p     *
******************************************************************/


int consulta (struct Pilha *p) {
	if (p->topo >= 0) {
		printf("topo: 0x%04x\n", p->dado[p->topo]);
		return p->dado[p->topo];
	}
	printf("Pilha vazia");
	exit(1);
}

/*****************************************************************
* void parser (char *expr)                                       *
* Verifica se a string apontada por expr esta sintaticamente     *
* correta.                                                       *
* Variaveis Globais Consultadas: STAB e PROD                     *
******************************************************************/


void parser(char *expr) {
	struct Pilha pilha;
	int x, a, nProd, i, *producao;
	int pos = 0;

	inicializa(&pilha);
	insere(&pilha, FIM);
	insere(&pilha, EXPR);
	if((a = lex(expr, &pos)) == ERRO){
		printf("Erro 1\n");
		erro("Erro lexico", expr, pos);
	}
	printf("topo 0x%04x\n", consulta(&pilha));
	do{
		x = consulta(&pilha);
		printf("0x%04x\t0x%04x\t0x%04x\n", x, x&NTER, !x&NTER);
		if(!(x&NTER)){
			if (x == a){
				remover (&pilha);
				if ((a = lex(expr, &pos)) == ERRO){
					printf("Erro 2\n");
					erro("Erro lexico", expr, pos);
				}else{
					printf("ok\n");
				}
			}else{
				printf("Erro 3 0x%04x != 0x%04x\n", x, a);
				erro("Erro sintatico",expr, pos);
			}
		}
		if (x&NTER){
			nProd = STAB[(x&NNTER)-1][(a>>8) - 1];
			printf("0x%04x 0x%04x\n", a, x);
			printf("  %04i   %04i -> 0x%04x\n", x&NNTER, (a>>8)-1, nProd);
			printf("0x%04x 0x%04x -> 0x%04x\n", x&NNTER, (a>>8)-1, nProd);
			if (nProd){
				remover (&pilha);
				producao = PROD[nProd];
				for (i = producao[0]; i > 0; i--)
					insere (&pilha, producao[i]);
			}else{
				printf("Erro 4\n");
				erro ("Erro sintatico", expr, pos);
			}
		}
	}while (x != FIM);
}

int main() {
	char expr[150];

	printf("\nDigite uma expressao: ");
	scanf("%[^\n]s", expr);
	parser(expr);
	printf("Expressao sintaticamente correta\n");
	return 0;
}
