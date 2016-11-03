#include "gram.h"

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addInstrucaoLista( char byte_code[21], char* parametro_1, char* parametro_2){
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

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));
	listaInstrucao[ numIntrucoes] -> parametro_1 = ( char*)malloc( sizeof( strlen( parametro_1) + 1));
	listaInstrucao[ numIntrucoes] -> parametro_2 = ( char*)malloc( sizeof( strlen( parametro_2) + 1));

	strcpy( listaInstrucao[ numIntrucoes] -> byte_code, byte_code);
	strncpy(listaInstrucao[ numIntrucoes] -> parametro_1, parametro_1, strlen( parametro_1));
	strncpy(listaInstrucao[ numIntrucoes] -> parametro_2, parametro_2, strlen( parametro_2));

	//printf("%s", listaInstrucao[ numIntrucoes] -> byte_code);
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_1, strlen(listaInstrucao[ numIntrucoes] -> parametro_1));
	//printf("\t%s %i", listaInstrucao[ numIntrucoes] -> parametro_2, strlen(listaInstrucao[ numIntrucoes] -> parametro_2));
	listaInstrucao[ numIntrucoes] -> label = 0;
	//printf("\n");
	return 1;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addNumLista(int num){
	char str[20];
	switch (num){
		case 0:
			if( addInstrucaoLista(ICONST_0, INVAL, INVAL) == 1)
				return 1;
			else
				return 0;

		break;

		case 1:
			if( addInstrucaoLista(ICONST_1, INVAL, INVAL) == 1)
				return 1;
			else
				return 0;
		break;

		case 2:
			if( addInstrucaoLista(ICONST_2, INVAL, INVAL) == 1)
				return 1;
			else
				return 0;
		break;

		case 3:
			if( addInstrucaoLista(ICONST_3, INVAL, INVAL) == 1)
				return 1;
			else
				return 0;
		break;

		case 4:
			if( addInstrucaoLista(ICONST_4, INVAL, INVAL) == 1)
				return 1;
			else
				return 0;
		break;

		case 5:
			if( addInstrucaoLista(ICONST_5, INVAL, INVAL) == 1)
				return 1;
			else
				return 0;
		break;

		default:
			sprintf(str, "%d", num);
			if( num > 127){
				if( addInstrucaoLista(LDC, str, INVAL) == 1)
					return 1;
				else
					return 0;
			}else if( num > 5){
				if( addInstrucaoLista(BIPUSH, str, INVAL) == 1)
					return 1;
				else
					return 0;
			}

	}
	return 0;
}

 /*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/
