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
   params,
   comp,
   iff,
   exprstmt,
   express,
   assign,
   RET,
   loop,
   RED,
   WRIT,
   mynum,
   expr
   /*insert others here */
 };//OF Node type 
enum DATATYPE
  {
    inttype,
    voidtype,
    booltype
  };
enum OPERATOR
  {
    PLUS,
    MINUS
};
typedef struct ASTNODEtype{

  enum NODETYPE type;
  struct ASTNODEtype *s1,*s2,*next; // these handle the branches of the tree
  char *Name ;
  int value ;
  int size ;  
  enum DATATYPE datatype ;
  enum OPERATOR operator;
}ASTnode; //of AST 

void ASTprint(ASTnode *p, int level);

ASTnode *ASTCreateNode(enum NODETYPE type);

void printtabs(int level);

#endif 
