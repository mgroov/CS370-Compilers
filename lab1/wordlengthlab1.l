%{  
   /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
        
       modified by  MAtthew Groover  
       1-24-2020
       added a new counting variable called count and a lex derective to modify the count , and a print statement in order to count the numbers in the input. 
   */
	int lgths[100];
        int count=0;
%}
	
%%
[a-zA-Z]+	{lgths[yyleng]++;}
[0-9]+          {count++;}
.	|
\n	;
%%
	
int yywrap()
{
	int i;
	printf("Length  No.words    \n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
	printf("Ammount of Numbers in the file: %4d\n",count); 
	return(1);

	
}

int main()
{  yylex();

}
