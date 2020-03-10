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
   params
   /*insert others here */
 };//OF Node type 
enum DATATYPE
  {
    inttype,
    voidtype,
    booltype
  };
typedef struct ASTNODEtype{

  enum NODETYPE type;
  struct ASTNODEtype *s1,*s2,*next; // these handle the branches of the tree
  char *Name;
  int value;
  int size;  
  enum DATATYPE datatype;  
}ASTnode; //of AST 

void ASTprint(ASTnode *p, int level);

ASTnode *ASTCreateNode(enum NODETYPE type);

void printtabs(int level);

#endif 
