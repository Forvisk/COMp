delim[ \t \n]
ws {delim}+
digito [0-9]
num {digito}+
literal \".*\"


%%
{ws}	{}
"+"	{return TADD;}
"-" {return TSUB;}
"*" {return TMUL;}
"/" {return TDIV;}
"(" {return TLPAR;}
")" {return TRPAR;}

{literal} {return TLIT;}
{num} {return TNUM;}

