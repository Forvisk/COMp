/*****************************************************************
* Analisador Sintatico LL(1)                                     *
* Exercicio Compiladores LL(1) p/ Disciplina de Compiladores     *
* Adriano Zanella Junior                                 		 *
*																 *
* Baseado no código de Cristiano Damiani Vasconcellos			 *
******************************************************************/

/* Compilação gcc -Wall -o exll1 exeLL1.c */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

/* Nao terminais o bit mais significativo ligado indica que se trata de um nao
terminal */
#define EXPR   0x8001
#define EXPRL  0x8002
#define TERMO  0x8003
#define TERMOL 0x8004
#define FATOR  0x8005

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
#define NOT   0x0600	// negação
#define FIM    0x0800

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
const int PROD1[] = {2, TERMO, EXPRL};			// (1) E  -> CE'
const int PROD2[] = {3, AND, TERMO, EXPRL};		// (2) E' -> &CE'
const int PROD3[] = {3, OR, TERMO, EXPRL};		// (3) E' -> |CE'
const int PROD4[] = {3, SEENT, TERMO, EXPRL};	// (4) E' -> ->CE'
const int PROD5[] = {3, SESOSE, TERMO, EXPRL};	// (5) E' -> <->CE'
const int PROD6[] = {0};						// (6) E' -> vazio
const int PROD7[] = {2, NOT, TERMO};			// (7) C  -> ~C
const int PROD8[] = {1, VALLOG};				// (8) C  -> vl

// vetor utilizado para mapear um numero e uma producao.
//const int *PROD[] = {NULL, PROD1, PROD2, PROD3, PROD4, PROD5, PROD6, PROD7, PROD8, PROD9, PROD10};
const int *PROD[] = {NULL, PROD1, PROD2, PROD3, PROD4, PROD5, PROD6, PROD7, PROD8};

// Tabela sintatica LL(1). Os numeros correspondem as producoes acima.
/*
const int STAB[5][8] = {	{ 0, 0, 0, 0, 1, 1, 0, 0},
							{ 2, 3, 0, 0, 0, 0, 4, 4},
							{ 0, 0, 0, 0, 5, 5, 0, 0},
							{ 8, 8, 6, 7, 0, 0, 8, 8},
							{ 0, 0, 0, 0, 9,10, 0, 0}
						};
*/
const int STAB[3][7] = 	{	{ 0, 0, 0, 0, 1, 1, 0}
							{ 2, 3, 4, 5, 0, 0, 6}
							{ 0, 0, 0, 0, 7, 8, 0}
						};

/*****************************************************************
* int lex (char *str, int *pos)                                  *
* procura o proximo token dentro de str a partir de *pos,incre-  *
* menta o valor de *pos a medida que faz alguma tranzicao de     *
* estados.                                                       *
* Retorna o inteiro que identifica o token encontrado.           *
******************************************************************/

int lex (char *str, int *pos){
	int estado = 0;
	char c;

	while (1){
		c =  str[*pos];

		switch(estado){
			case 0:
				if ((c == 'V') || (c == 'F')){
					(*pos)++;
					estado = 1;
				}
				else
					switch (c){
						case ' ':
							(*pos)++;
							break;
						/*case '.':
								(*pos)++;
								estado = 2;
								break;*/
						case '&':
								(*pos)++;
								return AND;
						case '|':
								(*pos)++;
								return OR;
						case '-':
								(*pos)++;
								c = str[*pos];
								if(c == '>'){
									(*pos)++;
									return SEENT;
								}else{
									(*pos)++;
									return ERRO;
								}
						case '<':
								(*pos)++;
								c = str[*pos];
								if(c == '-'){
									(*pos)++;
									c = str[*pos];
									if(c == '>'){
										(*pos)++;
										return SESOSE;
									}else{
										(*pos)++;
										return ERRO;
									}
								}else{
									(*pos)++;
									return ERRO;
								}
						case '\0':
								return FIM;
						default:
								(*pos)++;
								return ERRO;
						}
					break;
			case 1:
				if((c == 'V') || (c == 'F')){

				}
				break;
			case 2:
				if (isdigit(c)){
					(*pos)++;
					estado = 3;
				}
				else{
					(*pos)++;
					return ERRO;
				}
				break;
			case 3:
				if (isdigit(c))
					(*pos)++;
				else{
					//Adicionar a constante na tabela de simbolos.
					return CONST;
				}
				break;
			default:
					printf("Lex:Estado indefinido");
					exit(1);

		}
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
	if (p->topo < TAMPILHA)
	{
		p->topo++;
		p->dado[p->topo] = elemento;
	}
	else
	{
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

	if (p->topo >= 0)
	{
		aux = p->dado[p->topo];
		p->topo--;
		return aux;
	}
	else
	{
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
	if (p->topo >= 0)
		return p->dado[p->topo];
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
	if ((a = lex(expr, &pos)) == ERRO)
		erro("Erro lexico", expr, pos);
	do
	{
		x = consulta(&pilha);
		if (!(x&NTER))
		{
			if (x == a)
			{
				remover (&pilha);
				if ((a = lex(expr, &pos)) == ERRO)
					erro("Erro lexico", expr, pos);
			}
			else
				erro("Erro sintatico",expr, pos);
		}
		if (x&NTER)
		{
			nProd = STAB[(x&NNTER)-1][(a>>8) - 1];
			if (nProd)
			{
				remover (&pilha);
				producao = PROD[nProd];
				for (i = producao[0]; i > 0; i--)
					insere (&pilha, producao[i]);
			}
			else
				erro ("Erro sintatico", expr, pos);
		}
	} while (x != FIM);
}

void main()
{
	char expr[100];

	printf("\nDigite uma expressao: ");
	gets(expr);
	parser(expr);
	printf("Expressao sintaticamente correta\n");
}
