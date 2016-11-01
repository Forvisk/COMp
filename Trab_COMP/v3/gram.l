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
"else"	  { return TELSE;}
"while"   { return TWHILE;}
"int"     { /*printf("criando inteiros\n");*/ yylval = createListTipo(T_INT);return TINT;}
"String"  { /*printf("criando string\n");*/ yylval = createListTipo(T_STR); return TSTR;}
"void"    { yylval = createListTipo(T_TODEF); return TVOID;}
"read"    { return TREAD;}
"print"   { return TPRINT;}
"return"  { return TRET;}
"<="      { return TIGUALME;}
">="      { return TIGUALMA;}
"!="      { return TDIF;}
"<"       { return TMENOR;}
">"       { return TMAIOR;}
"=="      { return TIGUAL;}
"&&"      { return TAND;}
"||"      { return TOR;}
"!"       { return TNOT;}
"="       { return TATR;}
"+"	      { return TADD;}
"-"       { return TSUB;}
"*"       { return TMUL;}
"/"       { return TDIV;}
"("       { return TLPAR;}
")"       { return TRPAR;}
"{"       { return TLCH;}
"}"       { return TRCH;}
","       { return TVIRG;}
";"       { return TFLIN;}
{literal} { return TLIT;}
{num}     { /*printf("Criando num %s : %i\n", yytext, linha);*/ yylval = createAtributoNum( atoi(yytext)); return TNUM;}
{id}      { /*printf("Criando id %s : %i\n", yytext, linha);*/ yylval = createAtributoList( yytext); return TID;}
"\n"	  { linha++;}
