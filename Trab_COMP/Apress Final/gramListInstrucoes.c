#include "gram.h"

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addInstrucaoLista( char byte_code[21], char* parametro_1, char* parametro_2, int label, int num_par){
	int numIntrucoes = 0;
	//printf("%s\t%s\t%s\n", byte_code, parametro_1, parametro_2);
	//printf("%i\t%i\t%i\n", strlen(byte_code), strlen(parametro_1), strlen(parametro_2));
	pInstrucao* listaInstrucao = getListaInstrucao();
	while( (listaInstrucao[ numIntrucoes] != NULL) && ( numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instruções cheia\n");
		return 0;
	}
	//printf("%s %s %s", byte_code, parametro_1, parametro_2);

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, byte_code);
	//printf("%s", listaInstrucao[ numIntrucoes] -> byte_code);

	if( num_par > 0){
		listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( strlen( parametro_1) + 1));
		strncpy(listaInstrucao[ numIntrucoes] -> parametro_1, parametro_1, strlen( parametro_1));
		listaInstrucao[ numIntrucoes] -> parametro_1[ strlen(parametro_1) + 1] = '\0';
		//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_1, strlen(listaInstrucao[ numIntrucoes] -> parametro_1));

		if( num_par > 1){
			listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( strlen( parametro_2) + 1));
			strncpy(listaInstrucao[ numIntrucoes] -> parametro_2, parametro_2, strlen( parametro_2));
			listaInstrucao[ numIntrucoes] -> parametro_2[ strlen(parametro_2) + 1] = '\0';
			//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_2, strlen(listaInstrucao[ numIntrucoes] -> parametro_2));
		}
	}

	listaInstrucao[ numIntrucoes] -> label = label;
	listaInstrucao[ numIntrucoes] -> num_par = num_par;
	//printf("\n");
	return 1;
}

int addLdc( char* literal, int label){
	int numIntrucoes = 0;
	//printf("literal que chegou : %s\n", literal);
	pInstrucao* listaInstrucao = getListaInstrucao();
	while( (listaInstrucao[ numIntrucoes] != NULL) && ( numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instruções cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, LDC);

	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( strlen( literal) + 1));
	strncpy(listaInstrucao[ numIntrucoes] -> parametro_1, literal, strlen( literal));
	listaInstrucao[ numIntrucoes] -> parametro_1[ strlen(literal)] = '\0';
/*
	printf("%s", listaInstrucao[ numIntrucoes] -> byte_code);
	printf("\t%s == %s / %i == %i", listaInstrucao[ numIntrucoes] -> parametro_1, literal, strlen(listaInstrucao[ numIntrucoes] -> parametro_1), strlen(literal));
*/
	listaInstrucao[ numIntrucoes] -> label = label;
	listaInstrucao[ numIntrucoes] -> num_par = 1;
	//printf("\n");
}


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addInstrucaoListaPosVal( char byte_code[21], int posVal_1, int posVal_2, int label){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	//printf("%s %i %i %i\n", byte_code, posVal_1, posVal_2, label);
	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( 4));
	listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 4));

	strcpy( listaInstrucao[numIntrucoes] -> byte_code, byte_code);
	if( posVal_1 != -1){
		listaInstrucao[ numIntrucoes] -> num_par = 1;
		sprintf( listaInstrucao[ numIntrucoes] -> parametro_1, "%i", posVal_1);
		if( posVal_2 != -1){
			listaInstrucao[ numIntrucoes] -> num_par = 2;
			sprintf( listaInstrucao[ numIntrucoes] -> parametro_2, "%i", posVal_2);
		}else{
			strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);
		}
	}
	else{
		listaInstrucao[ numIntrucoes] -> num_par = 0;
		strcpy( listaInstrucao[ numIntrucoes] -> parametro_1, INVAL);
		strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);
	}

	//printf("%s", listaInstrucao[ numIntrucoes] -> byte_code);
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_1, strlen(listaInstrucao[ numIntrucoes] -> parametro_1));
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_2, strlen(listaInstrucao[ numIntrucoes] -> parametro_2));
	listaInstrucao[ numIntrucoes] -> label = label;
	//printf("\n");
	return 1;
}
 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addPrintStr( int label){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, INVOKEVIRTUAL);

	listaInstrucao[ numIntrucoes] -> parametro_1 = (char*)malloc( strlen(PRINT_STR) + 1);
	strncpy( listaInstrucao[ numIntrucoes] -> parametro_1, PRINT_STR, strlen(PRINT_STR));

	/*listaInstrucao[ numIntrucoes] -> parametro_2 = (char*)malloc( 4);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_2 ,INVAL);*/

	listaInstrucao[ numIntrucoes] -> label = label;
	listaInstrucao[ numIntrucoes] -> num_par = 1;

	return 1;

}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addPrintInt( int label){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, INVOKEVIRTUAL);

	listaInstrucao[ numIntrucoes] -> parametro_1 = (char*)malloc( strlen(PRINT_INT) + 1);
	strncpy( listaInstrucao[ numIntrucoes] -> parametro_1, PRINT_INT, strlen(PRINT_INT));

	/*listaInstrucao[ numIntrucoes] -> parametro_2 = (char*)malloc( 4);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_2 ,INVAL);*/

	listaInstrucao[ numIntrucoes] -> label = label;
	listaInstrucao[ numIntrucoes] -> num_par = 1;

	return 1;
}
 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addGetstaticSout( int label){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, GETSTATIC);

	listaInstrucao[ numIntrucoes] -> parametro_1 = (char*)malloc( strlen(SYSTEM_OUT) + 1);
	strncpy( listaInstrucao[ numIntrucoes] -> parametro_1, SYSTEM_OUT, strlen(SYSTEM_OUT));

	listaInstrucao[ numIntrucoes] -> parametro_2 = (char*)malloc( PRINTSTREAM);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_2 ,PRINTSTREAM);

	listaInstrucao[ numIntrucoes] -> label = label;
	listaInstrucao[ numIntrucoes] -> num_par = 2;

	return 1;
}
 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
int addNumLista(int num, int label){
	char str[20];
	switch (num){
		case 0:
			if( addInstrucaoLista(ICONST_0, INVAL, INVAL, label, 0) == 1)
				return 1;
			else
				return 0;

		break;

		case 1:
			if( addInstrucaoLista(ICONST_1, INVAL, INVAL, label, 0) == 1)
				return 1;
			else
				return 0;
		break;

		case 2:
			if( addInstrucaoLista(ICONST_2, INVAL, INVAL, label, 0) == 1)
				return 1;
			else
				return 0;
		break;

		case 3:
			if( addInstrucaoLista(ICONST_3, INVAL, INVAL, label, 0) == 1)
				return 1;
			else
				return 0;
		break;

		case 4:
			if( addInstrucaoLista(ICONST_4, INVAL, INVAL, label, 0) == 1)
				return 1;
			else
				return 0;
		break;

		case 5:
			if( addInstrucaoLista(ICONST_5, INVAL, INVAL, label, 0) == 1)
				return 1;
			else
				return 0;
		break;

		default:
			sprintf(str, "%d", num);
			if( num > 127){
				if( addInstrucaoLista(LDC, str, INVAL, label, 1) == 1)
					return 1;
				else
					return 0;
			}else if( num > 5){
				if( addInstrucaoLista(BIPUSH, str, INVAL, label, 1) == 1)
					return 1;
				else
					return 0;
			}

	}
	return 0;
}


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos addLabel( int label){
	int numIntrucoes = 0;

	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->lista = NULL;
	new -> label = label;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	//listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( 3));
	//listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 3));

	sprintf( listaInstrucao[ numIntrucoes] -> byte_code, "l%i:", label);

	//strcpy( listaInstrucao[ numIntrucoes] -> parametro_1, INVAL);
	//strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);

	//printf("%s", listaInstrucao[ numIntrucoes] -> byte_code);
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_1, strlen(listaInstrucao[ numIntrucoes] -> parametro_1));
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_2, strlen(listaInstrucao[ numIntrucoes] -> parametro_2));
	listaInstrucao[ numIntrucoes] -> label = 0;
	listaInstrucao[ numIntrucoes] -> num_par = 0;
	//printf("\n");

	//printf("%s label %i\n", listaInstrucao[ numIntrucoes] -> byte_code, new -> label);
	return new;
}


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/


int addIf( char byte_code[21], int label_1, int label_2, int labelAtual){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( 5));
	/*listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 5));*/

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, byte_code);
	sprintf( listaInstrucao[ numIntrucoes] -> parametro_1, "l%i", label_1);
	/*strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);*/

	listaInstrucao[ numIntrucoes] -> label = labelAtual;
	listaInstrucao[ numIntrucoes] -> num_par = 1;

	//printf("%s com label %i\n", listaInstrucao[ numIntrucoes] -> byte_code, labelAtual	);

	numIntrucoes++;
	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( 5));
	//listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, GOTO);
	sprintf( listaInstrucao[ numIntrucoes] -> parametro_1, "l%i", label_2);
	//strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);

	listaInstrucao[ numIntrucoes] -> label = labelAtual;
	listaInstrucao[ numIntrucoes] -> num_par = 1;

	//printf("%s com label %i\n", listaInstrucao[ numIntrucoes] -> byte_code, listaInstrucao[ numIntrucoes] -> label);

	return 1;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int getTamListInstrucoes(){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		//printf("%i %s\n", numIntrucoes, listaInstrucao[ numIntrucoes] -> byte_code);
		numIntrucoes++;
	}
	//printf(" num = %i\n", numIntrucoes);
	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return -1;
	}

	//printf(" num = %i\n", numIntrucoes);
	return numIntrucoes;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createListVeF( char byte_code[21], int linha){
	//printf("%s linha %i\n", byte_code, linha);
	pLinhaInst aux, aux1;

	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->lista = NULL;
	new -> seVerdadeiro = (LinhaInst*)malloc(sizeof(LinhaInst));
	aux = new -> seVerdadeiro;
	aux -> proximo = NULL;
	aux -> linha = linha;
	aux1 = aux;

	new -> seFalso = (LinhaInst*)malloc(sizeof(LinhaInst));
	aux = new -> seFalso;
	aux -> proximo = NULL;
	aux-> linha = linha + 1;

	strcpy( new -> byte_codeTemp, byte_code);

	//printf("%s %i %i\n", new -> byte_codeTemp, aux1 -> linha, aux -> linha);
	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos not(pListaAtributos lista){
	pLinhaInst aux = lista -> seFalso;
	lista -> seFalso = lista -> seVerdadeiro;
	lista -> seVerdadeiro = aux;
	return lista;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/


int addGoto( int label){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( 5));
	//listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, GOTO);
	sprintf( listaInstrucao[ numIntrucoes] -> parametro_1, "l%i", label);
	//strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);

	listaInstrucao[ numIntrucoes] -> label = label;
	listaInstrucao[ numIntrucoes] -> num_par = 1;

	return 1;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos mergeAnd( pListaAtributos listaC, pListaAtributos listaB){
	pLinhaInst auxF, auxV, auxDel;

	auxV = listaB -> seVerdadeiro;
	while( auxF -> proximo != NULL){
		auxDel = auxV;
		auxV -> proximo;
		free(auxDel);
	}
	free(auxV);

	listaB -> seVerdadeiro = listaC -> seVerdadeiro;

	auxF = listaB -> seFalso;
	while( auxF -> proximo != NULL){
		auxF = auxF -> proximo;
	}
	auxF -> proximo = listaC -> seFalso;

	free( listaC);
	return listaB;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos mergeOr( pListaAtributos listaC, pListaAtributos listaB){
	pLinhaInst auxV, auxF, auxDel;

	auxF = listaB -> seFalso;
	while( auxF -> proximo != NULL){
		auxDel = auxF;
		auxF -> proximo;
		free(auxDel);
	}
	free(auxF);

	listaB -> seFalso = listaC -> seFalso;

	auxV = listaB -> seVerdadeiro;
	while( auxV -> proximo != NULL){
		auxV = auxV -> proximo;
	}
	auxV -> proximo = listaC -> seVerdadeiro;

	free( listaC);
	return listaB;
}
 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int corrigirLabel( pLinhaInst linhaInstrucao, int label){
	pInstrucao* listaInstrucao = getListaInstrucao();
	//printf("corrigiu %i label %i\n");
	if( linhaInstrucao != NULL){
		pLinhaInst aux = linhaInstrucao;

		do{
			//printf("linha %i\n", aux->linha);
			if( listaInstrucao[ aux -> linha] != NULL){
				sprintf( listaInstrucao[ aux -> linha] -> parametro_1, "l%i", label);
				//printf("corrigiu %i label %i\n", linhaInstrucao -> linha, label);
			}else
				return 0;
			aux = aux -> proximo;
		}while(aux != NULL);
	}
	else
		return 0;
	return 1;
}

int corrigirPosVal( pLinhaInst linhaInstrucao, int posVal){
	pInstrucao* listaInstrucao = getListaInstrucao();

	if( linhaInstrucao != NULL){
		pLinhaInst aux = linhaInstrucao;

		do{
			//printf("linha %i\n", aux->linha);
			if( listaInstrucao[ aux -> linha] != NULL){
				sprintf( listaInstrucao[ aux -> linha] -> parametro_1, "%i", posVal);
				//printf("corrigiu %i label %i\n", linhaInstrucao -> linha, label);
			}else
				return 0;
			aux = aux -> proximo;
		}while(aux != NULL);
	}
	else
		return 0;
	return 1;
}