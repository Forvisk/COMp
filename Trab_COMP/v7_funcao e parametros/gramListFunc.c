#include "gram.h"

/*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

pListaAtributos addParametros( pListaAtributos new, pListaAtributos listParametros){
	//pListaAtributos new = ( ListaAtributos*)malloc( sizeof(ListaAtributos));

	if( listParametros == NULL){

	} else {
		pAtributo aux = listParametros -> lista;
		pAtributo auxGreat = new -> lista;
		pAtributo auxDel;

		do{
			if( new -> lista == NULL){
				if( existeId( new, aux)){

					new -> lista = createAtributo( aux -> nomeId, -1, aux -> tipe);
					auxGreat = new -> lista;
					auxGreat -> proximo = NULL;
				}
			}else{

				while( auxGreat -> proximo != NULL){
					auxGreat = auxGreat -> proximo;
				}
				if( existeId( new, aux)){
					auxGreat -> proximo = createAtributo( aux -> nomeId, -1, aux -> tipe);
					auxGreat = auxGreat -> proximo;
				}
			}

			auxDel = aux;
			aux = aux -> proximo;
			//free( auxDel);
		}while( aux != NULL);
	}
	//free( listParametros);
	return new;
}

/*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int addInicioFuncao( char* nome_func, int tipe_retorno, pListaAtributos parametros){
	return 1;
}

/*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/

int createLocal( pListaAtributos variaveis, pListaAtributos parametros){
	return 1;
}

/*_________________________________________________________________________________________*/
/*_________________________________________________________________________________________*/