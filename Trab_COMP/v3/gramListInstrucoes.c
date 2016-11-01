#include "gram.h"

/*________________________________________________________________________________________*/
int addInstrucaoLista( int byte_code, int parametro_1, int parametro_2){
	int numIntrucoes = 0;
	pInstrucao* listaInstrucao = getListaInstrucao();
	while( (listaInstrucao[ numIntrucoes] != NULL) && ( numIntrucoes < 200)){
		numIntrucoes++;
	}

	if( numIntrucoes == 200){
		printf("\nLista de instruções cheia\n");
		return 0;
	}

	listaInstrucao[ numIntrucoes] = (Instrucao*)malloc(sizeof(Instrucao));

	listaInstrucao[ numIntrucoes] -> byte_code = byte_code;
	if( parametro_1 != INVAL){
		listaInstrucao[ numIntrucoes] -> parametro_1 = parametro_1;
		if( parametro_2 != INVAL){
			listaInstrucao[ numIntrucoes] -> parametro_2 = parametro_2;
		}else{
			listaInstrucao[ numIntrucoes] -> parametro_2 = -1;
		}
	}else{
		listaInstrucao[ numIntrucoes] -> parametro_1 = -1;
		listaInstrucao[ numIntrucoes] -> parametro_2 = -1;
	}
	listaInstrucao[ numIntrucoes] -> label = 0;
	return 1;
}

/*________________________________________________________________________________________*/
int addNumLista(int num){
	switch (num){
		case 0:
			if( addInstrucaoLista(ICONST_0, INVAL, INVAL))
				return 1;
			else
				return 0;

		break;

		case 1:
			if( addInstrucaoLista(ICONST_1, INVAL, INVAL))
				return 1;
			else
				return 0;
		break;

		case 2:
			if( addInstrucaoLista(ICONST_2, INVAL, INVAL))
				return 1;
			else
				return 0;
		break;

		case 3:
			if( addInstrucaoLista(ICONST_3, INVAL, INVAL))
				return 1;
			else
				return 0;
		break;

		case 4:
			if( addInstrucaoLista(ICONST_4, INVAL, INVAL))
				return 1;
			else
				return 0;
		break;

		case 5:
			if( addInstrucaoLista(ICONST_5, INVAL, INVAL))
				return 1;
			else
				return 0;
		break;

		default:
			if( num > 127){
				if( addInstrucaoLista(LDC, num, INVAL))
					return 1;
				else
					return 0;
			}else if( num > 5){
				if( addInstrucaoLista(BIPUSH, num, INVAL))
					return 1;
				else
					return 0;
			}

	}
	return 0;
}

/*________________________________________________________________________________________*/