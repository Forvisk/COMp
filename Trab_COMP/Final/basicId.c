#include "gramF.h"


/*--------------------------------------------------------------*/

pModulo criarId( char* nomeId){
	pModulo new = ( pModulo)malloc( sizeof(Modulo));

	strncpy( new -> nomeId_temp, nomeId, 20);

	return new;
}

/*--------------------------------------------------------------*/

pModulo criarTipo( int tipo){
	pModulo new = ( pModulo)malloc( sizeof(Modulo));

	new -> tipo_temp = tipo;

	return new;
}

/*--------------------------------------------------------------*/

pVariavel criarVariavel( char* nomeId){
	pVariavel new = ( pVariavel)malloc( sizeof( Variavel));

	strncpy( new -> nomeId, nomeId, 20);
	new -> proximo = NULL;
	new -> anterior = NULL;
	new -> posVal = POS_INVAL;
	new -> tipo = T_TODEF;
	new -> validade = VALIDO;

	return new;
}

/*--------------------------------------------------------------*/

int addNewId_Variaveis( pModulo lista, pModulo novoId){
	if( lista == NULL){

		lista = ( pModulo)malloc( sizeof( Modulo));

	}
	pVariavel new = criarVariavel( novoId -> nomeId_temp);

	if( lista -> listaVariaveis == NULL){
		printf("Primeira variavel da lista temp : %s\n", new -> nomeId);
		lista -> listaVariaveis = new;
	}else {
		printf("Adicionando variavel a lista temp : %s\n", new -> nomeId);
		pVariavel aux = lista -> listaVariaveis;
		while( aux -> proximo != NULL){
			if( strncmp( aux -> nomeId, new -> nomeId, 20) == 0)
				return 0;
			aux = aux -> proximo;
		}
		aux -> proximo = new;
		new -> anterior = aux;
	}

	free( novoId);

	return 1;
}

/*--------------------------------------------------------------*/

/*int addListaVariaveis_ListaSuperior( pModulo superior, pModulo novaLista){

	printf("%p %p\n", (void*)superior, (void*)novaLista);
	if( superior == NULL){
		printf("Criando sup\n");
		superior = ( pModulo)malloc( sizeof( Modulo));
	}
	if( superior -> listaVariaveis == NULL){
		printf("Primeira entrada\n");
		superior -> listaVariaveis = novaLista -> listaVariaveis;
	} else {
		printf("Adicionando variaveis\n");
		pVariavel auxSup = superior -> listaVariaveis;
		pVariavel auxNew = novaLista -> listaVariaveis;
		
		while( auxSup -> proximo != NULL){
			auxSup = auxSup -> proximo;
			//printf("nomeId: %s\n", auxSup -> nomeId);
		}
		do{
			//printf("nomeId: %s\n", auxNew -> nomeId);
			if( existeId( superior, auxNew -> nomeId) == 0)
				return 0;
			auxNew = auxNew -> proximo;
		}while( auxNew != NULL);

		auxNew = novaLista -> listaVariaveis;
		auxSup -> proximo = auxNew;
		auxNew -> anterior = auxSup;

	}

	//free( novaLista);
	return 1;
}*/

/*--------------------------------------------------------------*/

pModulo setTipoListaVariaveis( pModulo lista, pModulo tipo){
	if( lista -> listaVariaveis == NULL){
		return lista;
	}
	pVariavel aux = lista -> listaVariaveis;

	do{
		if( aux -> tipo == T_TODEF)
			aux -> tipo = tipo -> tipo_temp;
		aux = aux -> proximo;
	}while( aux != NULL);

	free(tipo);
	return lista;
}

/*--------------------------------------------------------------*/

int addNewId_Parametros( pModulo lista, pModulo novoPar){
	if( lista == NULL){

		lista = ( pModulo)malloc( sizeof( Modulo));

	}
	pVariavel new = criarVariavel( novoPar -> nomeId_temp);

	if( lista -> listaParametros == NULL)
		lista -> listaParametros = new;
	else {
		pVariavel aux = lista -> listaParametros;
		while( aux -> proximo != NULL){
			if( strncmp( aux -> nomeId, new -> nomeId, 20) == 0)
				return 0;
			aux = aux -> proximo;
		}
		aux -> proximo = new;
		new -> anterior = aux;
	}

	free( novoPar);

	return 1;
}

/*--------------------------------------------------------------*/

pModulo setTipoListaParametros( pModulo lista, pModulo tipo){
	if( lista -> listaParametros == NULL){
		return lista;
	}
	pVariavel aux = lista -> listaParametros;

	do{
		if( aux -> tipo == T_TODEF)
			aux -> tipo = tipo -> tipo_temp;
		aux = aux -> proximo;
	}while( aux != NULL);

	free(tipo);
	return lista;
}

/*--------------------------------------------------------------*/

/*int addListaParametros_ListaSuperior( pModulo superior, pModulo novaLista){
	
	printf("%p %p\n", (void*)superior, (void*)novaLista);
	if( superior == NULL){
		printf("Criando sup\n");
		superior = ( pModulo)malloc( sizeof( Modulo));
	}
	if( novaLista -> listaParametros == NULL)
		return 1;
	if( superior -> listaParametros == NULL){
		pVariavel auxNew = novaLista -> listaParametros;
		do{
			//printf("nomeId: %s\n", auxNew -> nomeId);
			if( existeId( superior, auxNew -> nomeId) == 0)
				return 0;
			auxNew = auxNew -> proximo;
		}while( auxNew != NULL);
		printf("Primeira entrada\n");
		superior -> listaParametros = novaLista -> listaParametros;
	} else {
		printf("Adicionando variaveis\n");
		pVariavel auxSup = superior -> listaParametros;
		pVariavel auxNew = novaLista -> listaParametros;
		
		while( auxSup -> proximo != NULL){
			auxSup = auxSup -> proximo;
			//printf("nomeId: %s\n", auxSup -> nomeId);
		}
		do{
			//printf("nomeId: %s\n", auxNew -> nomeId);
			if( existeId( superior, auxNew -> nomeId) == 0)
				return 0;
			auxNew = auxNew -> proximo;
		}while( auxNew != NULL);

		auxNew = novaLista -> listaParametros;
		auxSup -> proximo = auxNew;
		auxNew -> anterior = auxSup;

	}

	//free( novaLista);
	return 1;
}*/

/*--------------------------------------------------------------*/

int existeId( pModulo lista, char* nomeId){

	if( lista -> listaVariaveis != NULL){
		pVariavel aux = lista -> listaVariaveis;
		do{
			if( strncpy( aux -> nomeId, nomeId, 20) == 0)
				return 0;
			aux = aux -> proximo;
		}while(aux != NULL);
	}

	if( lista -> listaParametros != NULL){
		pVariavel aux = lista -> listaParametros;
		do{
			if( strncpy( aux -> nomeId, nomeId, 20) == 0)
				return 0;
			aux = aux -> proximo;
		}while(aux != NULL);
	}

	return 1;
}

/*--------------------------------------------------------------*/

void putsListaVariaveis( pModulo lista){
	if( lista == NULL){
		printf("Lista inexistente\n");
	} else {
		if( lista -> listaVariaveis == NULL){
			printf("lista de variaveis vazia\n");
		}else{
			printf("\nTabela de simbolos %p:\n", (void*)lista);
			printf("Variavel\n");
			printf("\tsimbolo\tposVal\n\n");
			pVariavel aux = lista -> listaVariaveis;
			do{
				printf("\t%s\t%i", aux->nomeId, aux->posVal);
				if( aux-> tipo == T_INT){
					printf("\tint\n");
				} else if( aux -> tipo == T_STR){
					printf("\tstring\n");
				} else if( aux -> tipo == T_VOID){
					printf("\tvoid\n");
				} else {
					printf("\tno tipe\n");
				}
				aux = aux -> proximo;
			}while( aux != NULL);
		}

		if( lista -> listaParametros == NULL){
			printf("lista de parametros vazia\n");
		}else{
			//printf("\nTabela de simbolos %p:\n", (void*)lista);
			printf("Parametro\n");
			printf("\tsimbolo\tposVal\n\n");
			pVariavel aux = lista -> listaParametros;
			do{
				printf("\t%s\t%i", aux->nomeId, aux->posVal);
				if( aux-> tipo == T_INT){
					printf("\tint\n");
				} else if( aux -> tipo == T_STR){
					printf("\tstring\n");
				} else if( aux -> tipo == T_VOID){
					printf("\tvoid\n");
				} else {
					printf("\tno tipe\n");
				}
				aux = aux -> proximo;
			}while( aux != NULL);
		}
		printf("\n");
	}
}

/*-----------------------------------------------*/

int addToListaSimbolos( pModulo novaLista){
	printf("Iniciando incersão na lista principal\n");
	//putsListaVariaveis( novaLista);
	pModulo listaSimbolos = getListaSimbolos();
		

	if( novaLista -> listaVariaveis != NULL){

		if( listaSimbolos -> listaVariaveis == NULL){
			printf("Lista de variaveis vazia\n");

			pVariavel auxNew = novaLista -> listaVariaveis;
			do{
				//printf("nomeId: %s\n", auxNew -> nomeId);
				if( existeId( listaSimbolos, auxNew -> nomeId) == 0)
					return 0;
				auxNew = auxNew -> proximo;
			}while( auxNew != NULL);
			listaSimbolos -> listaVariaveis = novaLista -> listaVariaveis;
		} else {

			pVariavel auxNew = novaLista -> listaVariaveis;
			do{
				//printf("nomeId: %s\n", auxNew -> nomeId);
				if( existeId( listaSimbolos, auxNew -> nomeId) == 0)
					return 0;
				auxNew = auxNew -> proximo;
			}while( auxNew != NULL);

			pVariavel auxSup = listaSimbolos -> listaVariaveis;
			while( auxSup -> proximo != NULL){
				printf("nomeId: %s\n", auxSup -> nomeId);
				auxSup = auxSup -> proximo;
			}
			auxSup -> proximo = novaLista -> listaVariaveis;
			auxNew = novaLista -> listaVariaveis;
			auxNew -> anterior = auxSup;
		}
	}

	if( novaLista -> listaParametros != NULL){

	}


	return 1;
}
