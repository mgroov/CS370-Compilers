%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 NUM registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either ID or NUM.
   The return type via yylval is NUM 

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
	
	modified by mg 
	2-14-20
	added program decls and dec declarations
	changes starting label from list to program
	
	
	modified by mg 
	2-21-20 - 2-23-20
	added handle for ID insert,declaration,manipulation
	on both the left and right hand side of the equation 
	added rules to call to modified symtab structure.
	added a union handler to specify type of ID being passed through.
	
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define max_size 2
int regs[max_size];
int base, debugsw;
int offset;
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


int yylex();
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */
%}

%start program

%union{

int number;
char *string;

}

%token <number> NUM
%token INT
%token <string>ID
%type <number> expr
%token MYBEGIN
%token DO
%token MYRETURN
%token END
%token IF
%token THEN
%token WHILE
%token READ
%token ELSE

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
DEC    :INT ID ';' '\n' {if(Search($2)){fprintf(stderr,"ID already declared\n");exit(1);}else{if(offset<max_size){Insert($2,offset++);} else {fprintf(stderr,"too many ID declarations\n"); exit(1);} }}
       ;
list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
		{ yyerrok; }
	;

stat	:	expr
			{ fprintf(stderr,"the anwser is %d\n", $1); }
	|	ID '=' expr
			{ if(Search($1)){regs[fetch_adress($1)]=$3;fprintf(stderr,"the ID %s\n is now %d\n\n",$1,$3);}else{fprintf(stderr,"the ID %s doesn't exists \n", $1); exit(1); } }
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
	|	ID
	{ if(Search($1)){$$=regs[fetch_adress($1)];}else{fprintf(stderr,"ID does not exist \n"); exit(1);} } 
	|	NUM {$$=$1; fprintf(stderr,"found an NUM\n");}
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
