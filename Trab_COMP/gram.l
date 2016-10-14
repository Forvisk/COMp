delim[\t \n]
ws {delim}+
digito [0-9]
caractere [A-Za-z]
num {digito}+
id {caractere}+
literal \".*\"


%%
{ws}	{}
"if"	{return TIF;}
"else"	{return TELSE;}
"while" {return TWHILE;}
"int" {return TINT;}
"String" {return TSTR;}
"void" {return TVOID;}
"read" {return TREAD;}
"print" {return TPRINT;}
"return" {return TRET;}
"<=" {return TIGUALME;}
">=" {return TIGUALMA;}
"!=" {return TDIF;}
"<" {return TMENOR;}
">" {return TMAIOR;}
"==" {return TIGUAL;}
"&&" {return TAND;}
"||" {return TOR;}
"!" {return TNOT;}
"=" {return TATR;}
"+"	{return TADD;}
"-" {return TSUB;}
"*" {return TMUL;}
"/" {return TDIV;}
"(" {return TLPAR;}
")" {return TRPAR;}
"{" {return TLCH;}
"}" {return TRCH;}
"," {return TVIRG;}
";" {return TFLIN;}
{literal} {return TLIT;}
{num} {return TNUM;}
{id} {return TID;}
