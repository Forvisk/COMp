delim[\t ]
ws {delim}+
digito [0-9]
caractere [A-Za-z]
num {digito}+
id {caractere}+
literal \".*\"
/*"*/

%%
{ws}	{}
"if"	    { return TIF;}
"else"	  	{ return TELSE;}
"while"   	{ return TWHILE;}
"int"     	{ return TINT;}
"String"  	{ return TSTR;}
"void"    	{ return TVOID;}
"read"    	{ return TREAD;}
"print"   	{ return TPRINT;}
"return"  	{ return TRET;}
"<="      	{ return TIGUALME;}
">="      	{ return TIGUALMA;}
"!="      	{ return TDIF;}
"<"       	{ return TMENOR;}
">"       	{ return TMAIOR;}
"=="      	{ return TIGUAL;}
"&&"      	{ return TAND;}
"||"      	{ return TOR;}
"!"       	{ return TNOT;}
"="       	{ return TATR;}
"++"		{ return TINC;}
"--"		{ return TDEC;}
"+"			{ return TADD;}
"-"       	{ return TSUB;}
"*"       	{ return TMUL;}
"/"       	{ return TDIV;}
"("       	{ return TLPAR;}
")"       	{ return TRPAR;}
"{"       	{ return TLCH;}
"}"       	{ return TRCH;}
","       	{ return TVIRG;}
";"       	{ return TFLIN;}
{literal} 	{ yylval = createLit( yytext); return TLIT;}
{num}     	{ yylval = createNum( atoi(yytext)); return TNUM;}
{id}      	{ yylval = createId( yytext); return TID;}
"\n"	  	{ linha++; /*printf("%i", linha);*/}
