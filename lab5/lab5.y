%{

/*  Matthew Groover 
    3-2-20 - 3-4-20
 *  this y file defines the algol-c language for 
    our ast and later use for the whole compiler [21~
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>

 
extern int linecount;
  
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
%token END
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
vardec:typespec varlist';'
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
fundec:typespec ID '('params')' compstat
      ;
params:VOID
      |paramlist
      ;
paramlist:param
         |param ',' paramlist
         ;
param:typespec ID
     |typespec ID '['']'
     ;
compstat:MYBEGIN localdec statlist END
        ;
localdec:/*empty*/
        |vardec
	;
statlist:/*empty*/
        |statement
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
             |IF expression THEN ELSE statement
             ;
iterstat:WHILE expression DO statement 
        ;
returstat:MYRETURN ';'
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
         |addexp relop  
         ;
relop:LE
     |LT
     |GT
     |GE
     |EE
     |NE
     ;
addexp:term
      |addop term
      ;
addop:'+'
     |'-'
     ;
term:factor
    |mulop factor
    ;
mulop:'*'
     |'/'
     |AND
     |OR
     ;
factor:'('expression')'
      |NUM  {fprintf(stderr,"there is a num it is %d \n",$1);}
      |var
      |call
      |TRUE
      |FALSE
      |NOT factor
      ;
call:ID '('args')'
    ;
args:arglist
    |/*empty*/ 
    ;
arglist:expression
       |expression ',' arglist
       ;
%%	/* end of rules, start of program */

int main()
{ yyparse();
}
