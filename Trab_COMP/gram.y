
%token TID TINT TSTR TATR TADD TSUB TMUL TDIV TIGUAL TIGUALMA TIGUALME TMAIOR TMENOR TDIF TNOT TAND TOR TTRUE TFALSE TNUM TLIT TIF TELSE TWHILE TREAD TPRINT TRPAR TLPAR TVIRG TLCH TRCH TRET TFLIN TFIM

%%
Codigo : 	Prog TFIM
			;
Prog : 		ListFunc BlocoP
			| BlocoP
			;
ListFunc : 	ListFunc Func
			| Func
			;
Func : 		TipeReturn TID TLPAR DecPar TRDIR
			| TipeReturn TID TLPAR TRPAR
			;
DecPar :	DecPar TVIRG Par
			| Par
			;
Par :		Tipe TID
			;
BlocoP :	TLCH Decs ListCom TRCH
			| TLCH ListCom TRCH
			;
Decs :		Decs Dec
			| Dec
			;
Dec :		Tipe Listid TFLIN
			;
Tipe :		TINT
			| TSTR
			;
Listid :	Listid TVIRG TID
			| TID
			;
Bloco :		TLCH ListCom TRCH
			;
ListCom :	ListCom Com
			| Com
			;
Com :		Cse
			| Cenq
			| Catr
			| Cread
			| Cprint
			| Cfunc
			| Ret
			;
Ret :		TRET ExpAr TFLIN
			;
Cse :		TIF TLPAR ExpLog TRPAR Bloco
			| TIF TLPAR ExpLog TRPAR Bloco TELSE Bloco
			;
Cenq :		TWHILE TLPAR ExpLog TRPAR Bloco
			;
Catr :		TID TATR ExpAr TFLIN
			| TID TATR TLIT TFLIN
			;
Cread :		TREAD TLPAR TID TRPAR TFLIN
			;
Cprint :	TPRINT TLPAR ExpAr TRPAR TFLIN
			| TPRINT TLPAR TLIT TRPAR TFLIN
			;
Cfunc :		TID TLPAR ListPar TRPAR TFLIN
			| TID TLPAR TRPAR TFLIN
			;
ListPar :	ListPar TVIRG ExpAr
			| ExpAr
			;
ExpLog :	TLPAR ExpLog TRPAR TAND TLPAR E TRPAR
			| TLPAR ExpLog TRPAR TOR TLPAR E TRPAR
			| E
			;
E :			ExpAr TIGUAL ExpAr
			| ExpAr TDIF ExpAr
			| ExpAr TIGUALMA ExpAr
			| ExpAr TIGUALME ExpAr
			| ExpAr TMAIOR ExpAr
			| ExpAr TMENOR ExpAr
			| TLPAR ExpLog TFPAR
			| TNOT ExpLog
			| TTRUE
			| TFALSE
			;
ExpAr :		A
			;
A :			A TADD G
			| A TSUB G
			| G
			;
G :			G TMUL H
			| G TDIV H
			| H
			;
H :			TSUB H
			| TLPAR A TRPAR
			| TID
			| Cfunc
			| TNUM