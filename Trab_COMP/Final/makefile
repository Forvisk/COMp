hellomake:
	flex gram.l
	bison gram.y
	gcc -Wall -w gramMain.c basicId.c basicInstrucao.c basicFuncao.c gram.tab.c gramF.h -o gramFinal
