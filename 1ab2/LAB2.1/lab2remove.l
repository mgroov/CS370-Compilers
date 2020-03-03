%{        
	 /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015
            
            modified by Matthew Groover
            1-31-20
            added a linecount variablle and a new line handler
            added the linecount variable to the print statement
            fixed misformated vraces arround c-code and lack of retunr type on main
 
         */
        int comment = 0;
        int debug=1;  /* prints out debug statements if desired */
        int linecount =1;
%}
%%
"/*"	{
	if (comment && debug) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n",linecount);
	comment = 1;
	}

"*/"	{
          if (!comment) printf("%s",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}
"\n"    { linecount+=1;
          printf("\n");
          }
.       { if (!comment) printf("%s",yytext);}

%%


int yywrap(void)
{ return 1;
}

int main()
{
  yylex();
  
}

