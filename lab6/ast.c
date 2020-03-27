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
     if(p->s1 == NULL){
       printf("(void) no params given\n \n");
     }
     else{
       ASTprint(p->s1,level+1);
     }
     printtabs(level);
    ASTprint(p->s2,level);
    ASTprint(p->next,level);
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
    ASTprint(p->s1,level+1);
    ASTprint(p->s2,level);
    printtabs(level);
    printf("END of compound statement\n\n");
    ASTprint(p->next,level);
    break;
  }
  case WRIT:{
    printtabs(level);
    printf("write Found \n");
    ASTprint(p->s1,level);
    printtabs(level);
    ASTprint(p->next,level);
    break;
  }
  case mynum:{
    printtabs(level);
    printf("Number found: \n");
    printtabs(level);
    printf("%d\n\n",p->value);
    break;
  }
  case expr:{
    printtabs(level);
    printf("expression found \n");
    printtabs(level);
    printf("operator is ");
    switch(p->operator){
    case PLUS:{
      printf("plus \n\n");
      break;
    }
    case MINUS:{
      printf("minus \n\n");
      break;
    }
    case LessThan:{printf("less than\n\n"); break;}
    case LessEqual:{printf("less than or equal\n\n");break;}
    case GreatThan:{printf("Greater than\n\n");break;}
    case GreatEqual:{printf("Greater than or equal\n\n");break;}
    case Equal:{printf("equal\n\n");break;}
    case NotEqual:{printf("not equal \n\n");break;}
    case multi:{printf("multiply \n\n");break;}
    case devi:{printf("divide \n\n");break;}
    case aNd:{printf("and\n\n");break;}
    case oR:{printf("or\n\n");break;}
    default:break;
    }
    ASTprint(p->s1,level);
    ASTprint(p->s2,level);
    ASTprint(p->next,level);
    break;
  }
  case VAR:{
    if(p==NULL){
      break;
    }
    printtabs(level);
    printf("variable found\n");
    printtabs(level);
    printf("name is: %s \n\n",p->Name);
    if(p->s1 != NULL){
      printtabs(level);
      printf("it is an array refrence at [\n\n");
      ASTprint(p->s1,level);
      printtabs(level);
      printf("] end of array refrence \n");
    }
    ASTprint(p->next,level);
    break;
  }
  case TF:{
    printtabs(level);
    printf("found a boolean\n");
	   if(p->value){
	     printtabs(level);
	     printf("it is truth\n\n");
	   }
	   else{
            printtabs(level);
            printf("it is false\n\n");
	   }
	   break;
	   }//of tf
  case assign:{
    printtabs(level);
    printf("assignment statement \n\n");  printtabs(level); printf("left side:\n");
    ASTprint(p->s1,level);
    printtabs(level);
    printf("right side: \n");
    ASTprint(p->s2,level+1);
    ASTprint(p->next,level);
    break;
  }
  case iff:{
    printtabs(level);
    printf("IF statement found \n\n");
    ASTprint(p->s1,level+1);
    printtabs(level);
    printf("THEN do \n\n");
    ASTprint(p->s2,level+1);
    ASTprint(p->next,level);
    break;
  }
  case exprstmt:{
    printtabs(level);
    printf("expression stat found\n");
    ASTprint(p->s1,level);
    ASTprint(p->next,level);
    break;
  }
  case loop:{
    printtabs(level);
    printf("WHILE statment found \n\n");
    ASTprint(p->s1,level+1);
    printtabs(level);
    printf("DO \n\n");
    ASTprint(p->s2,level+1);
    ASTprint(p->next,level);
    break;
  }
  case RED:{
    printtabs(level);
    printf("read statment found \n");
    printtabs(level);
    printf("target is: \n");
    ASTprint(p->s1,level+1);
    ASTprint(p->next,level);
    break;
  }
  case RET:{
    printtabs(level);
    printf("return statment found \n");
    printtabs(level);
    printf("returning: \n");
    ASTprint(p->s1,level+1);
    ASTprint(p->next,level);
    break;
  }
  case callme:{
    printtabs(level);
    printf("call to function: %s \n",p->Name);
    printtabs(level);
    printf("with the args \n\n");
    printtabs(level);
    if(p->s1==NULL){printf("void \n");}
    ASTprint(p->s1,level+1);
    ASTprint(p->next,level);
    break;
  }
  case nOt:{
    printtabs(level);
    printf(" Not funtion found \n");
    printtabs(level);
    printf("target is: \n");
    ASTprint(p->s1,level+1);
    ASTprint(p->next,level);
    break;
  }
  default:{
    printf("UNKNOWN type in astPrint\n");
    break;
    }
 
  }//of switch case 

  
}//of print

void printtabs(int a){
  while(a>0){
    printf("\t");
    a--;
  }
}//of print tabs
