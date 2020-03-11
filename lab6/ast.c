#include "ast.h"
#include <stdio.h>
#include <malloc.h>

ASTnode *ASTCreateNode(enum NODETYPE type)
{

  ASTnode *p;
  p= (ASTnode *)(malloc(sizeof(struct ASTNODEtype)));
  p->type = type;
  return p;

}//of create node

void ASTprint(ASTnode *p,int level)
{
  if(p==NULL){
    return;
  }//if the tree hasn't been created

  switch(p->type){
  case vardec:{
    printtabs(level);
    printf("variable declaration\n");
    printtabs(level);
    printf("type is: ");
    switch(p->datatype){
    case inttype:{
	printf("inttype\n");
	break;
    }
    case voidtype:{
	  printf("voidtype\n");
	  break;
    }
    case booltype:{
	    printf("booltype\n");
	    break;
    }
    default:break;
    }
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
    ASTprint(p->s1,level+1);;
    level =0;
    ASTprint(p->next,level);
    break;
  }
  case fundec:{
    printtabs(level);
    printf("FUNCTION declaration:\n");
    printtabs(level);
    printf("name is: %s \n",p->Name);
    printtabs(level);
    printf("return type is: ");
     switch(p->datatype){
    case inttype:{
        printf("inttype\n");
        break;
    }
    case voidtype:{
          printf("voidtype\n");
          break;
    }
    case booltype:{
            printf("booltype\n");
            break;
    }
    default:break;
    }
     printf("\n");
    ASTprint(p->s1,level+1);
    ASTprint(p->s2,level);
    break;
  }
  case params:{
    printtabs(level);
    printf("param declaration\n");
    printtabs(level);
    printf("name is %s\n",p->Name);
    printtabs(level);
    printf("type is: ");
    switch(p->datatype){
    case inttype:{
        printf("inttype\n");
        break;
    }
    case voidtype:{
          printf("voidtype\n");
          break;
    }
    case booltype:{
            printf("booltype\n");
            break;
    }
    default:
      break;
    }
    if(p->size == -1){
      printtabs(level);
      printf("it's an array \n\n");
    }
    else{
      printtabs(level);
      printf("it's an single \n\n");
    }
    ASTprint(p->next,level);
    break;
  }
  case comp:{
    printtabs(level);
    printf("BEGIN compound statment\n\n");
    printtabs(level);
    ASTprint(p->s1,level);
    ASTprint(p->s2,level);
    printtabs(level);
    printf("END of compound statement\n");
    break;
  }
  case iff:{
    printtabs(level);
    printf("IF:\n");
    printtabs(level);
    ASTprint(p->s1,level);
    ASTprint(p->s2,level);
    break;
  }
  default:
    printf("UNKNOWN type in astPrint\n");
    break;
  }//of switch case 

  
}//of print

void printtabs(int a){
  while(a>0){
    printf("\t");
    a--;
  }
}//of print tabs
