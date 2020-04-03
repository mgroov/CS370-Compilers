%{

/*  Matthew Groover 
    3-2-20 - 3-27-20
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
 enum DATATYPE dtype;      /*global types to handle operators and nodes */
enum NODETYPE type;
 enum OPERATOR optype;
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

%type <node> varlist fundec vardec params expression  dec decl param paramlist compstat localdec expressstat statement statlist simpleexp   /*allows for us to pass node refrences up to the worldpointer*/
%type <node> addexp selectionstat iterstat assignstat returstat readstat writestat var term factor call args arglist

%type <optype> addop relop mulop /*tells us what operator is being used */

%type <dtype> typespec /*tells what type of declaration / variable */
%%/*end of specs start of rules */

program: decl { worldpointer = $1; } /*feeds first node that points to the rest */
       ;
decl:dec   {$$ = $1;}   /*feeds to the world */
    |dec decl {
                $$=$1;
                $1->next = $2;  /*assigns the next dec to its pointer next */
               
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
	  $$=ASTCreateNode(vardec);  /*these handle all variable declarations varlist recusively points at itself hence the null handle */
			 $$->Name = $1;
			  $$->s1 = $3;

	 }              
  
       |ID '['NUM']'','varlist {

                        
                         $$=ASTCreateNode(vardec);
			 $$->Name = $1;
			 $$->size = $3;
			 $$->s1 = $6;

	}
       ;
typespec:INT {$$=inttype;}
|VOID {$$ = voidtype;}   /* this assigns type to a vardec or list based on what is present */
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
        |vardec localdec {  /*handle local variable declaration within a compound statment */
	  $1->next=$2;$$=$1;
	  
          }
	;
statlist:/*empty*/   {$$ = NULL;}  
|statement statlist  {  
  if($1==NULL){
    $$=$2;             /*statlist recursively handles itself so we check against null to prevent seg faults*/
  }
  $1->next = $2; $$=$1; 
  }
	;
statement:expressstat {$$ = $1;}  /* these point to all forms of expression */
         |compstat  {$$ = $1;}
         |selectionstat {$$ = $1;}
         |iterstat {$$ = $1;}
         |assignstat {$$ = $1;}
         |returstat {$$ = $1;}
         |readstat {$$ = $1;}
         |writestat {$$ = $1;}
         ;
expressstat:expression';' {
  $$= ASTCreateNode(exprstmt);
  $$->s1 = $1;
            }
            |';' {$$ = NULL;}
            ;
selectionstat:IF expression THEN statement {
              $$=ASTCreateNode(iff);
	      $$->s2 = ASTCreateNode(iffbody);  /* we create a node for the statment then body of the if */
              $$->s1 = $2;
	      $$->s2->s1 = $4;
	      $$->s2->s2 = NULL;
              }
              |IF expression THEN statement ELSE statement{
	       $$=ASTCreateNode(iff);
	       $$->s2 = ASTCreateNode(iffbody); /*the s2 of the body if is only initialized if we have an else */
               $$->s1 = $2;
               $$->s2->s1 = $4;
	       $$->s2->s2 = $6;
              }
             ;
iterstat:WHILE expression DO statement{
  $$ = ASTCreateNode(loop);    /*handles the while do statments */
	   $$->s1 = $2;
	   $$->s2 = $4;
         }
        ;
returstat:MYRETURN ';' {$$ =ASTCreateNode(RET);
   $$->s1 = NULL;
         }                                      /* all simple expression are right recursive in order to handle math properly */
         |MYRETURN expression ';' {
           $$ = ASTCreateNode(RET);
           $$->s1 = $2;
         }
         ;
readstat:READ var ';'{
         $$ = ASTCreateNode(RED); /*handles the read */
         $$->s1 = $2;
	 }
        ;
writestat:WRITE expression ';'{
  $$ = ASTCreateNode(WRIT); /*handles write statments */
	  $$->s1 = $2;
          }
         ;
assignstat: var '=' simpleexp ';'{
          $$ = ASTCreateNode(assign); /*assignment statement handle */
          $$->s1 = $1;
	  $$->s2 = $3;
          }
          ;



expression:simpleexp {$$ = $1;}     
          ;


var:ID {$$=ASTCreateNode(VAR); /*this is a leaf it often should not have anyone other nodes */
         $$->Name = $1;
	 $$->s1 = NULL;
     }
   |ID '['expression']' {$$=ASTCreateNode(VAR);
         $$->Name = $1; 
         $$->s1 = $3;  
    } 
   ;




simpleexp:addexp {$$ =$1;}    
     |simpleexp relop addexp{
       $$ = ASTCreateNode(expr);
       $$->s1 = $1;
       $$->s2 = $3;             /* this handles most of our addition and subtraction cases*/
       $$->operator = $2;
     }
     ;


relop:LE {$$ = LessEqual;}
     |LT {$$ = LessThan;}
     |GT {$$ = GreatThan;}       /* handles relation ship operators such as <= */
     |GE {$$ = GreatEqual;}
     |EE {$$ = Equal;}
     |NE {$$ = NotEqual;}
     ;


addexp:term        {$$ = $1;}
|addexp addop term {
  $$ = ASTCreateNode(expr);
  $$->s1 = $1;
  $$->s2 = $3;
  $$->operator = $2;
 }
;


addop:'+' { $$ = PLUS;}
     |'-' { $$ = MINUS;}
     ;

term:factor {$$ = $1;}
    |term mulop factor {
      $$ =ASTCreateNode(expr);
      $$->operator = $2;
      $$->s1 = $1;
      $$->s2 = $3;
     }
    ;

mulop:'*' {$$= multi;}
     |'/' {$$ = devi;}
     |AND {$$ = aNd;}
     |OR  {$$ = oR;}
     ;

factor:'('expression')' {$$ =$2;}
       |NUM  { $$ = ASTCreateNode(mynum);
               $$->value = $1;
             }  /* this detetmines how the expression statment works  */
      |var   {$$ = $1;}
      |call  {$$ =$1;}
      |TRUE  {$$ =ASTCreateNode(TF);
              $$->value = 1;
       }
      |FALSE {$$ =ASTCreateNode(TF);
              $$->value =0;
       }
|NOT factor {$$ = ASTCreateNode(nOt);
   $$->s1 = $2;
      }
      ;

call:ID '('args')'{
    $$=ASTCreateNode(callme);
    $$->Name = $1;
    $$->s1 = $3;
    }
    ;

args:/*empty*/ {$$ = NULL;}
    |arglist {$$ = $1;}
    ;

arglist:expression {$$=$1;}
       |expression ',' arglist {
         $1->s1 = $3;
	 $$ = $1;
       }
       ;

%%	/* end of rules, start of program */

int main()
{ yyparse();
  ASTprint(worldpointer,0);//prints tree 
}//of main
