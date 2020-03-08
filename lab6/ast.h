//
//
//
//
//
//

#ifndef AST
#define AST

enum NODETYPE
 {
   vardec,
   fundec,
   /*insert others here */
 };//OF Node type 

typedef struct ASTNODEtype{

  enum NODETYPE type;
  struct ASTNODEtype *s1,*s2,*next; // these handle the branches of the tree
  char *Name;
  int value;
  int size;  
  
}ASTnode; //of AST 

void ASTprint(ASTnode *p, int level);

ASTnode *ASTCreateNode(enum NODETYPE type);

void printtabs(int level);

#endif 
