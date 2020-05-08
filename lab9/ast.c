//Matthew Groover
//this files creates
//amd maages the symbtable
//based semantic actions
//aswekk as prints the ast print

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


//function to check formal and actual params
int checkFormalsandParams(ASTnode *f, ASTnode *a){

  if(f==NULL && a==NULL){
    return 1;
  }
  if(f==NULL || a==NULL){                                                                                                                                                                                                                        return 0;                                                                                                                                                                                                                                  }
  if(f->semtype != a->semtype){
    return 0;
  }
  return checkFormalsandParams(f->next,a->next);
}


void ASTprint(ASTnode *p,int level)
{
  if(p==NULL){
    return;
  }//if the tree hasn't been created

  switch(p->type){
  case vardec:{
    printtabs(level);
    printf("variable dec ");
    switch(p->datatype){
    case inttype:{
      printf("int ");       /* handles all variable declarations even local declarations */
	break;
    }
    case voidtype:{
	  printf("void ");
	  break;
    }
    case booltype:{
	    printf("boolean ");
	    break;
    }
    default:break;
    }
    printf(" %s  ",p->Name);
    if(p->size>0){
     printtabs(level);
     printf("[ %d ]\n \n",p->size);
    }
    else{
      printtabs(level);
      printf("\n\n");
    }
    ASTprint(p->s1,level+1);
    level =0;
    ASTprint(p->next,level);
    break;
  }
  case fundec:{
    printtabs(level);
    printf("FUNCTION declaration: ");
    printf(" %s \n",p->Name);
    printtabs(level);
    printf("return type is: ");
     switch(p->datatype){
    case inttype:{
        printf("int \n");
        break;
    }
    case voidtype:{
          printf("void \n");
          break;                            /*handles the function declarations */
    }
    case booltype:{
            printf("boolean \n");
            break;
    }
    default:break;
    }
     if(p->s1 == NULL){
       printf("(void) no params given\n \n");
     }
     else{
       ASTprint(p->s1,level+1);
     }
     ASTprint(p->s2,level+1);
     ASTprint(p->next,level);
    break;
  }
  case params:{
    printtabs(level);
    printf("parameter(s) \n");
    printtabs(level);
    switch(p->datatype){
    case inttype:{
        printf("int ");
        break;
    }
    case voidtype:{
          printf("void ");
          break;
    }                                       /* acts simmmilair to variable dec but specifically for the more limitied info param */
    case booltype:{
            printf("boolean ");
            break;
    }
    default:
      break;
    }
    printf(" %s \n",p->Name);
    if(p->size == -1){
      printtabs(level);
      printf("[]");
    }
    printf("\n");
    ASTprint(p->next,level);
    break;
  }
  case comp:{
    printtabs(level);
    printf("BEGIN \n\n");
    ASTprint(p->s1,level+1);
    ASTprint(p->s2,level+1);       /* handles compound statments also known as begin and end */
    printtabs(level);
    printf("END \n\n");
    ASTprint(p->next,level);
    break;
  }
  case WRIT:{
    printtabs(level);
    printf("write \n");
    if(p->s1 != NULL){
    ASTprint(p->s1,level+1);
/* handles the write nodes */
    }
    else{
      printf("%s %s \n",p->label,p->Name);

    }/* if a string is passed */
    ASTprint(p->next,level);
    break;
  }
  case mynum:{
    printtabs(level);
    printf("%d\n\n",p->value); /* handles number printing*/
    break;
  }
  case expr:{
    printtabs(level);
    printf("expression: "); /*handles expressions with any operator type other than not */
    switch(p->operator){
    case PLUS:{
      printf("+ \n\n");
      break;
    }
    case MINUS:{
      printf("- \n\n");
      break;
    }
    case LessThan:{printf(" < \n\n"); break;}
    case LessEqual:{printf("<= \n\n");break;}
    case GreatThan:{printf("> \n\n");break;}
    case GreatEqual:{printf(">= \n\n");break;}
    case Equal:{printf("== \n\n");break;}
    case NotEqual:{printf("not=  \n\n");break;}
    case multi:{printf(" * \n\n");break;}
    case devi:{printf("divide \n\n");break;}
    case aNd:{printf("and \n\n");break;}
    case oR:{printf("or \n\n");break;}
    default:break;
    }
    ASTprint(p->s1,level+1);
    ASTprint(p->s2,level+1);
    ASTprint(p->next,level);
    break;
  }
  case VAR:{
    if(p==NULL){
      break;
    }
    printtabs(level);
    printf("variable  ");
    printf(" %s \n\n",p->Name);
    if(p->s1 != NULL){                           /*handles when variables appear in a non declatory manner */
      printtabs(level);
      printf("array refrence at [\n\n");
      ASTprint(p->s1,level+1);
      printtabs(level);
      printf("] end of array refrence \n");
    }
    ASTprint(p->next,level);
    break;
  }
  case TF:{                                      /*handles boolean values */
    printtabs(level);
    printf("boolean: ");                  
	   if(p->value){
 
	     printf("it is truth\n\n");
	   }
	   else{
            
            printf("it is false\n\n");
	   }
	   break;
	   }//of tf
  case assign:{
    printtabs(level);
    printf("assignment statement \n\n");  printtabs(level); printf("left side:\n");
    ASTprint(p->s1,level+1);                 /*handles assignment statments */
    printtabs(level);
    printf("right side: \n");
    ASTprint(p->s2,level+1);
    ASTprint(p->next,level);
    break;
  }
  case iff:{
    printtabs(level);
    printf("IF: \n\n");
    ASTprint(p->s1,level+1);
    printtabs(level);
    printf("THEN do: \n\n");
    ASTprint(p->s2->s1,level+1);
    if(p->s2->s2 != NULL){                   /*handles if statments*/
      printtabs(level);
      printf("ELSE do this: \n");
      ASTprint(p->s2->s2,level+1);   /*if s2 of if body is initialized it will print the else statment aswell */
    }
    ASTprint(p->next,level);
    break;
  }
  case exprstmt:{
    printtabs(level);
    printf("expression stat found\n");
    ASTprint(p->s1,level+1);
    ASTprint(p->next,level);
    break;
  }
  case loop:{
    printtabs(level);
    printf("WHILE statment found \n\n");
    ASTprint(p->s1,level+1);
    printtabs(level);                            /*handles while looops */
    printf("DO \n\n");
    ASTprint(p->s2,level+1);
    ASTprint(p->next,level);
    break;
  }
  case RED:{
    printtabs(level);     /*handles read staments */
    printf("read: \n");
    ASTprint(p->s1,level+1);
    ASTprint(p->next,level);
    break;
  }
  case RET:{
    printtabs(level);
    printf("return: ");   /*handles Ret */
    if(p->s1 == NULL){
      printf("void \n");
    }
    else{
      printf("\n");
    ASTprint(p->s1,level+1);
    }
    ASTprint(p->next,level);
    break;
  }
  case callme:{
    printtabs(level);
    printf("call to: %s \n",p->Name); /*handles calls to a function */
    printtabs(level);
    printf("with the args \n\n");
    if(p->s1==NULL){printf("void \n");}
    ASTprint(p->s1,level+1);
    ASTprint(p->next,level);
    break;
  }
  case nOt:{
    printtabs(level);
    printf(" Not of: \n ");
    ASTprint(p->s1,level+1); /*creates the node to handle not */
    ASTprint(p->next,level); 
    break;
  }
  case ARGLIST:{
    printtabs(level);
    printf("Args list\n");
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
