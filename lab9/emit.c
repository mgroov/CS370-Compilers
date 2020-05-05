#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"
#include "emit.h"


static int GLABEL=0;  // global label counter

char * genlabel()
{  char s[100];
  char *s1;
  sprintf(s,"_L%d",GLABEL++);
  s1=strdup(s);  // get heap memory for the label name
  return (s1);
}//of generate label

//ptrto whole treee given
//prints the labels at the beginning of the program
void EMITSTRINGS(ASTnode *p,FILE *fp){

  if(p==NULL) return;
  
  if((p->type == WRIT) && (p->Name != NULL)){
  
    fprintf(fp,"%s:\t .asciiz\t%s\n\n",p->label,p->Name);

  }

  EMITSTRINGS(p->next,fp);
  EMITSTRINGS(p->s1,fp);
  EMITSTRINGS(p->s2,fp);
  
}//of emit strings 

//ptrto whole treee given
//prints the global variables 
void EMITGLOBALS(ASTnode *p,FILE *fp){

  if(p==NULL) return;

  if((p->type == vardec) && (p->symbol->level == 0)){

    fprintf(fp,"%s:\t .space\t%d\n\n",p->Name,p->symbol->mysize*WSIZE);

  }

  EMITGLOBALS(p->next,fp);
  EMITGLOBALS(p->s1,fp);
  // EMITSTRINGS(p->s2); no global vardecs via s2

}//of emit globals 
