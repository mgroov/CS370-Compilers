%{
/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015
			
		    modified by Matthew Groover
 		    2-3-20
	            added parenthesis to the token analyzer to
 		    allow for proper handling of the parenthesis in the
 		    yacc grammer. 
 		    
 		    modfied by mg 
 		    2-14-20
 		    added reserve word token return for int 
 		    added ; to char handler 
 		    
 		    modfied by mg 
 		    2-20-20 
 		    added union handler in y then modified this code to use strdup
 		    to apply it to the union handler 
 		    
 		    
*/


int mydebug=1;
#include "y.tab.h"
%}


%%
int         {return(INT);}

[a-zA-Z][a-zA-Z0-9]* {if (mydebug) fprintf(stderr,"Letter found\n"); 
                       yylval.string =strdup(yytext); return(VARIABLE);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       yylval.number=atoi((const char *)yytext); return(INTEGER);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%&|();] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                       return (*yytext);}
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       return (*yytext);}

%%

int yywrap(void)
{ return 1;}

