%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

   Shaun Cooper
    January 2015

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in

	 modified by Matthew Groover 
	 2-3-2020
	added the multiplication 
	fixed the unary minus function 
	inputs are the expression expected to be input by the user
	output is a parsed out expression and accurate end status of 
	the calculation. 
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>


int regs[26];
int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}



/*  defines the start symbol, what values come back from LEX and how the operators are associated  */
%}

%start program

%token INTEGER
%token INT
%token VARIABLE

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%	/* end specs, begin rules */
program:DECLS list
       ;
DECLS  :DEC DECLS
       |/*empty*/
       ;
DEC    :INT VARIABLE ';'
       ;
list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr
			{ fprintf(stderr,"the anwser is%d\n", $1); }
	|	VARIABLE '=' expr
			{ regs[$1] = $3; }
	;

expr	:	 '(' expr ')' /*not many modification made in .y file */
			{$$ = $2  ; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3; }
	|	expr '/' expr
			{ $$ = $1 / $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
	|	expr '*' expr /* added multiplication function */
			{ $$ = $1 * $3; } 
	|	 '-' expr	%prec UMINUS 
			{ $$ = -$2; } /* modified to handle correctly */
	|	VARIABLE
			{ $$ = regs[$1]; fprintf(stderr,"found a variable value =%d\n",$1); }
	|	INTEGER {$$=$1; fprintf(stderr,"found an integer\n");}
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
