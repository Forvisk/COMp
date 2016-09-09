/*****************************************************************
* Analisador Sintatico LL(1)                                     *
* Exercicio Compiladores LL(1) p/ Disciplina de Compiladores     *
* Adriano Zanella Junior                                 		 *
*																 *
* Baseado no código de Cristiano Damiani Vasconcellos			 *
******************************************************************/

/* Compilação gcc -Wall -o exell1 exeLL1.c */

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
/*
#define ERRO 	0x0000
#define AD     0x0100
#define SUB 	0X0200
#define MUL    0x0300
#define DIV		0x0400
#define CONST  0x0500
#define APAR   0x0600
#define FPAR   0x0700
#define FIM    0x0800
*/
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
/*
const int PROD1[] = {2, TERMO, EXPRL};        // E  -> TE'
const int PROD2[] = {3, AD, TERMO, EXPRL};    // E' -> +TE'
const int PROD3[] = {3, SUB, TERMO, EXPRL};   // E' -> -TE'
const int PROD4[] = {0};                      // E' -> vazio
const int PROD5[] = {2, FATOR, TERMOL};       // T  -> FT'
const int PROD6[] = {3, MUL, FATOR, TERMOL};  // T' -> *FT'
const int PROD7[] = {3, DIV, FATOR, TERMOL};  // T' -> /FT'
const int PROD8[] = {0};                      // T' -> vazio
const int PROD9[] = {1, CONST};               // F  -> const
const int PROD10[]= {3, APAR, EXPR, FPAR};    // F  -> (E)
*/

const int PROD1[] = {2, TERMO, EXPRL};        // E  -> TE' 		(1)
const int PROD2[] = {3, SEENT, TERMO, EXPRL};    // E' -> ->TE'	(2)
const int PROD3[] = {3, SESOSE, TERMO, EXPRL};   // E' -> <->TE'	(3)
const int PROD4[] = {0};                      // E' -> vazio	(4)
const int PROD5[] = {2, FATOR, TERMOL};       // T  -> CT'		(5)
const int PROD6[] = {3, AND, FATOR, TERMOL};  // T' -> &CT'		(6)
const int PROD7[] = {3, OR, FATOR, TERMOL};  // T' -> |CT'		(7)
const int PROD8[] = {0};                      // T' -> vazio	(8)
const int PROD9[] = {2, NOT, FATOR};          // C  -> ~C 	(9)
const int PROD10[]= {3, LPAR, EXPR, RPAR};	// C  -> (E)		(10)
const int PROD11[]= {1, VALLOG};			// C  -> c (11)

// vetor utilizado para mapear um numero e uma producao.
//const int *PROD[] = {NULL, PROD1, PROD2, PROD3, PROD4, PROD5, PROD6, PROD7, PROD8, PROD9, PROD10};
const int *PROD[] = {NULL, PROD1, PROD2, PROD3, PROD4, PROD5, PROD6, PROD7, PROD8, PROD9, PROD10, PROD11};

// Tabela sintatica LL(1). Os numeros correspondem as producoes acima.
/*
const int STAB[5][8] = {	{ 0, 0, 0, 0, 1, 1, 0, 0},
				{ 2, 3, 0, 0, 0, 0, 4, 4},
				{ 0, 0, 0, 0, 5, 5, 0, 0},
				{ 8, 8, 6, 7, 0, 0, 8, 8},
				{ 0, 0, 0, 0, 9,10, 0, 0}
			};
*/						//   -> <-> &  |  ~  c  (  )  #
const int STAB[5][9] = {	{ 0, 0, 0, 0, 1, 1, 1, 0, 0}, // E
							{ 2, 3, 0, 0, 0, 0, 0, 4, 4}, // E'
							{ 0, 0, 0, 0, 5, 5, 5, 0, 0}, // T
							{ 0, 0, 6, 7, 0, 0, 0, 8, 8}, // T'
							{ 0, 0, 0, 0, 9, 11, 10, 0, 0}  // C
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
		printf("loop: %c %i\n", c, *pos);

		switch(estado){
			case 0:
				switch (c){
					case 'V':
						(*pos)++;
						printf(" V\n");
						return VALLOG;
					case 'F':
						(*pos)++;
						printf(" F\n");
						return VALLOG;
					case ' ':
						(*pos)++;
						printf("Espaço\n");
						break;
					case '&':
						(*pos)++;
						printf("AND\n");
						return AND;
					case '|':
						(*pos)++;
						printf("OR\n");
						return OR;
					case '-':
						(*pos)++;
						printf(" -");
						estado = 2;
					case '<':
						(*pos)++;
						printf(" <");
						estado = 3;
					case '\0':
						return FIM;
					default:
						(*pos)++;
						return ERRO;
				}
				break;
			case 1:
				printf("estado == 1\n");
				printf("%i\n", *pos);
				if((c == 'V') || (c == 'F')){
					return ERRO;
				}else{
					return VALLOG;
				}
				break;
			case 2: // caso encontrou o traco do Se então ( -> )
				if (c == '>'){
					(*pos)++;
					printf(">\n");
					return SEENT;
				}else{
					(*pos)++;
					printf("erro >\n");
					return ERRO;
				}
				break;
			case 3: // caso encontrou o menor que do Se somente se ( <-> )
				if (c == '-'){
					(*pos)++;
					printf("-");
					estado = 4;
				}
				else{
					(*pos)++;
					printf("erro -\n");
					return ERRO;
				}
				break;
			case 4: // caso encontrou o traço do  Se somente se ( <-> )
				if (c == '>'){
					(*pos)++;
					printf(">\n");
					return SESOSE;
				}else{
					(*pos)++;
					printf("erro >\n");
					return ERRO;
				}
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

void erro (char *erro, char *expr, int pos)
{
	int i;
	printf("%s", erro);
	printf("\n%s\n", expr);
	for (i = 0; i < pos-1; i++)
		putchar(' ');
	putchar('^');
	exit(1);
}

/*****************************************************************
* void inicializa(struct Pilha *p)                               *
* inicializa o topo da pilha em -1, valor que indica que a pilha *
* esta vazia.                                                    *
******************************************************************/

void inicializa(struct Pilha *p)
{
	p->topo = -1;
}

/*****************************************************************
* void insere (struct Pilha *p, int elemento                     *
* Insere o valor de elemento no topo da pilha apontada por p.    *
******************************************************************/

void insere (struct Pilha *p, int elemento)
{
	if (p->topo < TAMPILHA){
		p->topo++;
		p->dado[p->topo] = elemento;
		printf("Insere 0x%04x\n\n", elemento);
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

int remover (struct Pilha *p)
{
	int aux;

	if (p->topo >= 0){
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


int consulta (struct Pilha *p)
{
	if (p->topo >= 0){
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


void parser(char *expr)
{
	struct Pilha pilha;
	int x, a, nProd, i, *producao;
	int pos = 0;

	inicializa(&pilha);
	insere(&pilha, FIM);
	insere(&pilha, EXPR);
	if((a = lex(expr, &pos)) == ERRO)
		erro("Erro lexico", expr, pos);
	printf("topo 0x%04x\n", consulta(&pilha));
	do{
		x = consulta(&pilha);
		if(!(x&NTER)){
			if (x == a){
				remover (&pilha);
				if ((a = lex(expr, &pos)) == ERRO)
					erro("Erro lexico", expr, pos);
			}else
				erro("Erro sintatico",expr, pos);
		}
		if (x&NTER){
			nProd = STAB[(x&NNTER)-1][(a>>8) - 1];
			if (nProd){
				remover (&pilha);
				producao = PROD[nProd];
				for (i = producao[0]; i > 0; i--)
					insere (&pilha, producao[i]);
			}else
				erro ("Erro sintatico", expr, pos);
		}
	}while (x != FIM);
}

int main()
{
	char expr[150];

	printf("\nDigite uma expressao: ");
	scanf("%[^\n]s", expr);
	parser(expr);
	printf("Expressao sintaticamente correta\n");
	return 0;
}
