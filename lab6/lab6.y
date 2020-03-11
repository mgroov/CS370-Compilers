%{

/*  Matthew Groover 
    3-2-20 - 3-4-20
 *  this y file defines the algol-c language for 
    our ast and later use for the whole compiler [21~
*/


	/* begin specs */
#include "ast.h"
#include <stdio.h>
#include <ctype.h>

 
  extern int linecount;  /*imports the linecount from lex */
  ASTnode *worldpointer;
  
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
struct ASTNODEtype *node; 
enum DATATYPE dtype;
enum NODETYPE type;
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

%type <node> varlist fundec vardec params expression  dec decl param paramlist compstat localdec expressstat statement statlist simpleexp
%type <node> addexp relop 

%type <dtype> typespec
%%/*end of specs start of rules */

program: decl { worldpointer = $1; }
       ;
decl:dec   {$$ = $1;}
    |dec decl {
                $$=$1;
                $1->next = $2;
               
              }
    ;
dec:vardec  {$$ = $1;}
   |fundec  { $$ = $1;}
   ;
vardec:typespec varlist';' {$$ =$2;
                            ASTnode *p;
                             p = $$;
			     while(p!=NULL){
                               p->datatype =  $1;
			       p=p->s1;
			     }
                           }                         /*vardec , varlist handle all variable declaration */
                           ;
varlist:ID {
            $$ = ASTCreateNode(vardec);
            $$->Name = $1;
           }
       |ID '['NUM']' { // fprintf(stderr,"there is a num it is %d \n",$3);
                     
                     $$=ASTCreateNode(vardec);
		     $$->Name = $1;
		     $$->size = $3;
	}
        |ID ',' varlist {
			 $$=ASTCreateNode(vardec);
			 $$->Name = $1;
			  $$->s1 = $3;

	 }              
  
       |ID '['NUM']'','varlist {fprintf(stderr,"there is a num it is %d \n",$3);

                        
                         $$=ASTCreateNode(vardec);
			 $$->Name = $1;
			 $$->size = $3;
			 $$->s1 = $6;

	}
       ;
typespec:INT {$$=inttype;}
        |VOID {$$ = voidtype;}
        |BOOLEAN {$$ = booltype;}
        ;
fundec:typespec ID '('params')' compstat{
          $$ = ASTCreateNode(fundec);
          $$->Name = $2;
          $$->s1 = $4;
          $$->s2 = $6;
          $$->datatype = $1;
   
      }           /*handles function declaration with or without parameters */
      ;
params:VOID {$$=NULL;}
       |paramlist {$$=$1;}
      ;
paramlist:param { $$ = $1;}
         |param ',' paramlist { $$=$1; $1->next = $3;}
         ;
param:typespec ID   {$$ = ASTCreateNode(params);
                      $$->Name = $2;
		       $$->size =0;
		       $$->datatype = $1;
                    }
      |typespec ID '['']' { $$ = ASTCreateNode(params);
                      $$->Name = $2;
                      $$->size = -1;
		      $$->datatype = $1;
     } /*param list , param handle a large ammount and what type of params work in the function declarations */
     ;
compstat:MYBEGIN localdec statlist END {
  $$ = ASTCreateNode(comp);
         $$->s1 = $2;
         $$->s2 = $3;
        } /*states how functions should be implemented */
        ;
localdec:/*empty*/ {$$ = NULL;}
|vardec localdec { $1->next=$2;$$=$1;}
	;
statlist:/*empty*/   {$$ = NULL;}  
|statement statlist  {$1->next = $2; $$=$1;}
	;
statement:expressstat {$$ = $1;}
         |compstat  {$$ = NULL;}
         |selectionstat {$$ = NULL;}
         |iterstat {$$ = NULL;}
         |assignstat {$$ = NULL;}
         |returstat {$$ = NULL;}
         |readstat {$$ = NULL;}
         |writestat {$$ = NULL;}
         ;
expressstat:expression';' {
       $$ =  ASTCreateNode(exprstmt);
       $$->s1 = $1;
            }
            |';' {$$ = NULL;}
            ;
selectionstat:IF expression THEN statement 
             |IF expression THEN statement ELSE statement
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
expression:simpleexp {$$ = $1;}    
          ;
var:ID
   |ID '['expression']'
   ;
simpleexp:addexp {$$ =$1;}    
     |simpleexp relop addexp{
       $$ = ASTCreateNode(express);
       $$->s1=$1;
       $$->s2=$3;
     }
         ;
relop:LE {$$ = NULL;}
     |LT {$$ = NULL;}
     |GT {$$ = NULL;}       /* handles relation ship operators such as <= */
     |GE {$$ = NULL;}
     |EE {$$ = NULL;}
     |NE {$$ = NULL;}
     ;
addexp:term        {$$ = NULL;}
|addexp addop term {$$ = NULL;}
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
  ASTprint(worldpointer,0);//prints tree 
}//of main
