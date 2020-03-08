%{
/* lab6
Matthew Groover
3-6-20
this handles passing tokens and values to yacc as it sees them
everytime a new line occurs the linecount variable is incremented
*/


int mydebug =0;
int linecount =1;

#include "y.tab.h"

int yylex();
%}








%%

int	{return(INT);}
void	{return(VOID);}
boolean	{return(BOOLEAN);}
begin	{return(MYBEGIN);}
end	{return(END);}           /*this handles all the reserved word tokens for the yacc */
if	{return(IF);}
then	{return(THEN);}
else	{return(ELSE);}
while	{return(WHILE);}
do	{return(DO);}
return	{return(MYRETURN);}
read	{return(READ);}
write	{return(WRITE);}       
and	{return(AND);}
or	{return(OR);}
true	{return(TRUE);}
false	{return(FALSE);}
not	{return(NOT);}
"<="	{return(LE);}    /* relationship opps opperate diffrently because they aren't read in as one */
"<"	{return(LT);}
">="	{return(GE);}
">"	{return(GT);}
"=="	{return(EE);}
"!="	{return(NE);}

[a-zA-Z][a-zA-Z0-9]* {if (mydebug) fprintf(stderr,"Letter found\n");        /* this handles the id passing */
                       yylval.string =strdup(yytext); return(ID);}
[0-9][0-9]*     {if (mydebug) fprintf(stderr,"Digit found\n");
                       yylval.number=atoi((const char *)yytext); return(NUM);}      /*this handles numerical passing */
[ \t]           {if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%();\[/\]/\,/]  { if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);  /*this handles all small token handles */
                       return (*yytext);}
\n              { if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext);         /*this handles the linecount */
                       linecount++;}
%%





int yywrap(){

return(1);
}
