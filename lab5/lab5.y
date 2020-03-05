%{

/*  Matthew Groover 
    3-2-20 - 3-4-20
 *  this y file defines the algol-c language for 
    our ast and later use for the whole compiler [21~
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>

 
  extern int linecount;  /*imports the linecount from lex */
  
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d \n", s,linecount);
}

 

int yylex();
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */
%}

%start program

%union{

int number;
char *string;

}

%token <string> ID
%token <number> NUM
%token INT
%token VOID
%token BOOLEAN
%token MYBEGIN
%token END             /*these are all the tokens lex passes to the yacc file */
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token MYRETURN
%token READ
%token WRITE
%token LE
%token LT
%token GE
%token GT
%token EE
%token NE
%token AND
%token OR
%token TRUE
%token FALSE
%token NOT

%%/*end of specs start of rules */

program: decl
       ;
decl:dec
    |dec decl
    ;
dec:vardec
   |fundec
   ;
vardec:typespec varlist';'                         /*vardec , varlist handle all variable declaration */
      ;
varlist:ID
       |ID '['NUM']' {fprintf(stderr,"there is a num it is %d \n",$3);}
       |ID ',' varlist 
       |ID '['NUM']'','varlist {fprintf(stderr,"there is a num it is %d \n",$3);}
       ;
typespec:INT
        |VOID
        |BOOLEAN
        ;
fundec:typespec ID '('params')' compstat       /*handles function declaration with or without parameters */
      ;
params:VOID
      |paramlist
      ;
paramlist:param
         |param ',' paramlist
         ;
param:typespec ID
|typespec ID '['']'                    /*param list , param handle a large ammount and what type of params work in the function declarations */
     ;
compstat:MYBEGIN localdec statlist END  /*states how functions should be implemented */
        ;
localdec:/*empty*/
        |vardec localdec
	;
statlist:/*empty*/
        |statement statlist 
	;
statement:expressstat
         |compstat
         |selectionstat
         |iterstat
         |assignstat
         |returstat
         |readstat
         |writestat
         ;
expressstat:expression';'
            |';'
            ;
selectionstat:IF expression THEN statement
             |IF expression THEN statement  ELSE statement
             ;
iterstat:WHILE expression DO statement 
        ;
returstat:MYRETURN ';'                                       /* all simple expression are right recursive in order to handle math properly */
         |MYRETURN expression ';'
         ;
readstat:READ var ';'
        ;
writestat:WRITE expression ';'               
         ;
assignstat: var '=' simpleexp ';'          
          ;
expression:simpleexp
          ;
var:ID
   |ID '['expression']'
   ;
simpleexp:addexp
         |simpleexp relop addexp 
         ;
relop:LE
     |LT
     |GT        /* handles relation ship operators such as <= */
     |GE
     |EE
     |NE
     ;
addexp:term
      |addexp addop term
      ;
addop:'+'
     |'-'
     ;
term:factor
    |term mulop factor
    ;
mulop:'*'
     |'/'
     |AND
     |OR
     ;
factor:'('expression')'
      |NUM  {fprintf(stderr,"there is a num it is %d \n",$1);}  /* this detetmines how the expression statment works  */
      |var
      |call
      |TRUE
      |FALSE
      |NOT factor
      ;
call:ID '('args')'
    ;
args:/*empty*/
    |arglist 
    ;
arglist:expression
       |expression ',' arglist 
       ;
%%	/* end of rules, start of program */

int main()
{ yyparse();
}
