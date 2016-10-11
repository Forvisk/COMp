delim[ \t \n]
ws {delim}+
digito [0-9]
num {digito}+

%%
{ws}	{}
"+"	{return TADD;}
"-" {return TSUB;}
"*" {return TMUL;}
"/" {return TDIV;}
"(" {return TLPAR;}
")" {return TRPAR;}
{num} {return TNUM;}
