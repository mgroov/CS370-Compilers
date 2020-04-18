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
   expr,
   VAR,
   TF,
   callme,
   nOt,
   iffbody,
   ARGLIST
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
    MINUS,
    LessThan,
    LessEqual,
    GreatThan,
    GreatEqual,
    Equal,
    NotEqual,
    devi,
    multi,
    aNd,
    oR
};
typedef struct ASTNODEtype{

  enum NODETYPE type;
  struct ASTNODEtype *s1,*s2,*next; // these handle the branches of the tree
  struct SymbTab *symbol; //so we can have acess to the symbol table
  char *Name ;
  int value ;
  int size ;  
  enum DATATYPE datatype ;
  enum DATATYPE semtype;
  enum OPERATOR operator;
}ASTnode; //of AST 

void ASTprint(ASTnode *p, int level);

ASTnode *ASTCreateNode(enum NODETYPE type);

void printtabs(int level);

int checkFormalsandParams(ASTnode *f, ASTnode *a);
#endif 
