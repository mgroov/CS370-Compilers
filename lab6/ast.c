#include "ast.h"
#include <stdio.h>
#include <malloc.h>

ASTnode *ASTCreateNode(enum NODETYPE type)
{

  ASTnode *p;
  p= (ASTnode *)(malloc(sizeof(struct ASTNODEtype)));
  return p;

}//of create node

void ASTprint(ASTnode *p,int level)
{
  if(p==NULL){
    return;
  }//if the tree hasn't been created

  switch(p->type){
  case vardec:
    printtabs(level);
    printf("variable declaration \n");
    printtabs(level);
    printf("name is:  %s \n ",p->Name);
    if(p->size>0){
      printtabs(level);
      printf("it is  an array of size: [ %d ]\n \n",p->size);
    }
    else{
      printtabs(level);
      printf("its size is: %d \n \n",p->size);
    }
    ASTprint(p->s1,level+1);
    break;

  default:
    printf("UNKNOWN type in astPrint\n");
  }//of switch case 

  ASTprint(p->next,level);
}//of print

void printtabs(int a){
  while(a>0){
    printf("\t");
    a--;
  }
}//of print tabs
