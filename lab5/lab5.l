%{
//Matthew Groover lab5
//passes tokens based on language passed to it till eof



int mydebug =0;
int linecount =1;

#include "y.tab.h"

int yylex();
%}








%%

int    {return(INT);}
void   {return(VOID);}
boolean   {return(BOOLEAN);}
begin     {return(MYBEGIN);}
end       {return(END);}
if        {return(IF);}
then      {return(THEN);}
else      {return(ELSE);}
while     {return(WHILE);}
do        {return(DO);}
return    {return(MYRETURN);}
read      {return(READ);}
write     {return(WRITE);}
"<="      {return(LE);}
"<"       {return(LT);}
">="      {return(GE);}
">"       {return(GT);}
"=="      {return(EE);}
"!="      {return(NE);}
and       {return(AND);}
or        {return(OR);}
true      {return(TRUE);}
false     {return(FALSE);}
not       {return(NOT);}

[a-zA-Z][a-zA-Z0-9]* {if (mydebug) fprintf(stderr,"Letter found\n");
                       yylval.string =strdup(yytext); return(ID);}
[0-9][0-9]*     {if (mydebug) fprintf(stderr,"Digit found\n");
                       yylval.number=atoi((const char *)yytext); return(NUM);}
[ \t]           {if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%();\[/\]/\,/]  { if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);
                       return (*yytext);}
\n              { if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext);
                       linecount++;}
%%





int yywrap(){

return(1);
}
