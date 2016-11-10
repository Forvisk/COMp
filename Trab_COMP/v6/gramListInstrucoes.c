#include "gram.h"

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addInstrucaoLista( char byte_code[21], char* parametro_1, char* parametro_2, int label){
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
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( strlen( parametro_1) + 1));
	listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( strlen( parametro_2) + 1));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, byte_code);
	strncpy(listaInstrucao[ numIntrucoes] -> parametro_1, parametro_1, strlen( parametro_1));
	strncpy(listaInstrucao[ numIntrucoes] -> parametro_2, parametro_2, strlen( parametro_2));

	//printf("%s", listaInstrucao[ numIntrucoes] -> byte_code);
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_1, strlen(listaInstrucao[ numIntrucoes] -> parametro_1));
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_2, strlen(listaInstrucao[ numIntrucoes] -> parametro_2));
	listaInstrucao[ numIntrucoes] -> label = label;
	//printf("\n");
	return 1;
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
		sprintf( listaInstrucao[ numIntrucoes] -> parametro_1, "%i", posVal_1);
		if( posVal_2 != -1)
			sprintf( listaInstrucao[ numIntrucoes] -> parametro_2, "%i", posVal_2);
		else
			strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);
	}
	else{
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

int addNumLista(int num, int label){
	char str[20];
	switch (num){
		case 0:
			if( addInstrucaoLista(ICONST_0, INVAL, INVAL, label) == 1)
				return 1;
			else
				return 0;

		break;

		case 1:
			if( addInstrucaoLista(ICONST_1, INVAL, INVAL, label) == 1)
				return 1;
			else
				return 0;
		break;

		case 2:
			if( addInstrucaoLista(ICONST_2, INVAL, INVAL, label) == 1)
				return 1;
			else
				return 0;
		break;

		case 3:
			if( addInstrucaoLista(ICONST_3, INVAL, INVAL, label) == 1)
				return 1;
			else
				return 0;
		break;

		case 4:
			if( addInstrucaoLista(ICONST_4, INVAL, INVAL, label) == 1)
				return 1;
			else
				return 0;
		break;

		case 5:
			if( addInstrucaoLista(ICONST_5, INVAL, INVAL, label) == 1)
				return 1;
			else
				return 0;
		break;

		default:
			sprintf(str, "%d", num);
			if( num > 127){
				if( addInstrucaoLista(LDC, str, INVAL, label) == 1)
					return 1;
				else
					return 0;
			}else if( num > 5){
				if( addInstrucaoLista(BIPUSH, str, INVAL, label) == 1)
					return 1;
				else
					return 0;
			}

	}
	return 0;
}


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addLabel( int label){
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
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( 3));
	listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 3));

	sprintf( listaInstrucao[ numIntrucoes] -> byte_code, "l%i", label);

	strcpy( listaInstrucao[ numIntrucoes] -> parametro_1, INVAL);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);

	//printf("%s", listaInstrucao[ numIntrucoes] -> byte_code);
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_1, strlen(listaInstrucao[ numIntrucoes] -> parametro_1));
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_2, strlen(listaInstrucao[ numIntrucoes] -> parametro_2));
	listaInstrucao[ numIntrucoes] -> label = 0;
	//printf("\n");
	return 1;
}


 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/


int addIf( char byte_code[21], int label_1, int label_2){
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
	listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, byte_code);
	sprintf( listaInstrucao[ numIntrucoes] -> parametro_1, "l%i", label_1);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);

	numIntrucoes++;
	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( 5));
	listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, GOTO);
	sprintf( listaInstrucao[ numIntrucoes] -> parametro_1, "l%i", label_2);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);

	return 1;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int getTamListInstrucoes(){
	int numIntrucoes = 0;

	pInstrucao* listaInstrucao = getListaInstrucao();

	while( (listaInstrucao[numIntrucoes] != NULL) && (numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instrucoes cheia\n");
		return -1;
	}

	return numIntrucoes;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos createListVeF( char byte_code[21], int linhaV, int linhaF){
	pListaAtributos new = (ListaAtributos*)malloc(sizeof(ListaAtributos));
	new->lista = NULL;
	new-> listV = linhaV;
	new-> listF = linhaF;
	strcpy( new -> byte_codeTemp, byte_code);

	return new;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addCompListInstrucoes( pListaAtributos lista){
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
	listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, lista -> byte_codeTemp);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_1, INVAL);
	strcpy( listaInstrucao[ numIntrucoes] -> parametro_2, INVAL);

	listaInstrucao[ numIntrucoes] -> label = 0;
}
