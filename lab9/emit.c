//Matthew Groover may,6 -may,8 2020
//this code emits mips code based on the ast tree
//that is created from and with the symbol table 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"
#include "emit.h"


static int GLABEL=0;  // global label counter
char * curfunc;
//=========================================================================================
//pre condit call 
//post condition  returns a char pointer with the label

char * genlabel()
{  char s[100];
  char *s1;
  sprintf(s,"_L%d",GLABEL++);
  s1=strdup(s);  // get heap memory for the label name
  return (s1);
}//of generate label
//=========================================================================================
//pre condition pointer to the entire ast tree and file to write to
//post condition prints out the label for the found string then recursively calls for the
//rest of the tree 
void EMITSTRINGS(ASTnode *p,FILE *fp){

  if(p==NULL) return;
  
  if((p->type == WRIT) && (p->Name != NULL)){
  
    fprintf(fp,"%s:\t .asciiz\t%s\n",p->label,p->Name); // writes .asciiz for the string

  }

  EMITSTRINGS(p->next,fp);
  EMITSTRINGS(p->s1,fp);  //recursive call cases 
  EMITSTRINGS(p->s2,fp);
  
}//of emit strings 
//========================================================================================
//pre con a node to the main tree and a file pointer 
//post con emits global variable and allowcates space for them
//then recursive calls to the rest of the tree 
void EMITGLOBALS(ASTnode *p,FILE *fp){

  if(p==NULL) return;

  if((p->type == vardec) && (p->symbol->level == 0)){

    fprintf(fp,"%s:\t .space\t%d\n",p->Name,p->symbol->mysize*WSIZE);//allocates size by size times word size

  }

  EMITGLOBALS(p->next,fp);  //recursive calls to handle other globals
  EMITGLOBALS(p->s1,fp);
  // EMITSTRINGS(p->s2); no global vardecs via s2

}//of emit globals 
//=======================================================================================
//helper function to make clean code
//pre con takes in four params
// the  file
//label if function or if/while
// a char* for the command to be run
//a char * pointer for comments 
//
//post con emits the formated string
void emit(FILE *fp, char *label, char *command, char *comment){

  if(strcmp(label,"") ==0){
    fprintf(fp,"\t\t%s\t\t%s\n", command,comment);
  }
  else
  fprintf(fp,"%s:\t\t%s\t\t%s\n",label,command,comment);

}//of emit
//======================================================================================
//pre con a pointer to a fundec and the file to write to 
//post con emits the header for a function in assembely

void emit_function_head(ASTnode *p, FILE *fp){

  char s[100];
  emit(fp,p->Name,"","#start of Function");
  //set the global func variable
  curfunc = p->Name;

  //stack pointer movement
  sprintf(s,"subu $a0, $sp, %d",p->size*WSIZE);
  emit(fp,"",s,"#adjust the stack pointer for function setup");
  emit(fp,"","sw $sp, ($a0)","");
  emit(fp,"","sw $ra, 4($a0)","");
  emit(fp,"","move $sp, $a0","#adjust the stack pointer");
  emit(fp,"","",""); //spacing emit
}//of emit function head
//===================================================================================
//pre con a node pointer to a fundec and a file pointe r
//post con emits return lines based upon the type of function
//method to handle explicit and implicit function returns 
void emit_function_return(ASTnode *p, FILE *fp){

  if(p != NULL){
    // we need to evaluate the expr
    emit_expr(p,fp); //this leaves $a0 with the result 

  }
  //if it is null we leave nothing with a0
  
  emit(fp,"","",""); //spacing emit
  emit(fp,"","lw $ra, 4($sp)","#restore RA");
  emit(fp,"","lw $sp, ($sp)","#restore SP");
  emit(fp,"","",""); //spacing emit   

  //we have to do it diffrently if it is main
  if(strcmp(curfunc,"main")==0){

    emit(fp,"","li $v0, 10","#Leave main program");
    emit(fp,"","syscall","# leave main");
    emit(fp,"","",""); //spacing emit
    
  }//handle main
  else {

    emit(fp, "", "jr $ra", "# jump back to RA" );
    emit(fp,"","",""); //spacing emit

  }//every other case than main
  

}//of emit function return
//=================================================================================
//pre con a pointer to an expr and a fp
// post con mips code that sets $a0 to the ptrs value
void emit_expr(ASTnode *p, FILE *fp){

  char s[100];

  //Base cases cases where recursion isnt necessary
  switch(p->type){
  case mynum:{
    sprintf(s,"li $a0, %d",p->value);
    emit(fp,"",s,"# expression is a NUM");
    return;
    break;
  }//of num
  case VAR:{
    emit_identifier(p,fp);//we know a0 is the address of ident
    emit(fp,"","lw $a0, ($a0)","#fetch value for ident from memory");
    return;
    break;
  }//of identifier call
  case callme:{
    emit_call(p,fp);
    return;
    break;
  }//of call handler
  }//of switch

  //expression is an expr, deal with it recursively 

  // recursive case
  // expression is an EXPR , deal with it recursively
  //   evaluatin s1    emit_expr(p->s1)
  //   store s1 in p>symbol->offset (sw A0  %d($sp))
  //   evaluate s2    emit_expr(p-S2)
  //   move A0 to B0   move A1 A0  (copies RHS to A1)

  emit_expr(p->s1,fp);
  sprintf(s,"sw $a0, %d($sp)",p->symbol->offset*WSIZE);
  emit(fp,"",s,"#store left side of expr");
  if(p->s2 != NULL){
  emit_expr(p->s2,fp);
  emit(fp,"","move $a2, $a0","#storing right hand side");
  }//of preventing not seg fault 
  sprintf(s,"lw $a0, %d($sp)",p->symbol->offset*WSIZE);
  emit(fp,"",s,"#load back left side of expr");
  
  switch(p->operator){
  case PLUS:{
    emit(fp,"","add $a0,$a0,$a2","#add the left and right hand side");
    break;
  }//of plus
  case MINUS:{
    emit(fp,"","sub $a0,$a0,$a2","#subtract the left and right");
    break;
  }//of minus
  case LessThan:{
    emit(fp,"", "slt $a0, $a0, $a2", "#less than for left and right side");
    break;
  }//of less than
  case LessEqual:{
    emit(fp, "", "sle $a0, $a0, $a2", "#less than or equal for left and right" );
    break;
  }//less equal
  case GreatThan:{
    emit(fp, "", "sgt $a0, $a0, $a2", "#greater than for left and right");
    break;
  }//of greater than
  case GreatEqual:{
    emit(fp, "", "sge $a0, $a0, $a2", "#greater than or equal for left and right");
    break;
  }//of greater than or equal
  case Equal:{
    emit(fp, "", "seq $a0, $a0, $a2", "#equal equals for left and right hand side" );
    break;
  }//of equal
  case NotEqual:{
    emit(fp, "", "seq $a0, $a0, $a2", "# equals equals expression" );
    emit(fp, "", "sltiu $a0, $a0, 1", "# the not for the not equals" );
    break;
  }//of not equal
  case devi:{
    emit(fp, "","div $a0, $a2" , "#divide the left and right hand side" );
    emit(fp, "", "mflo $a0", "#grabs the division product from the low bit" );
    break;
  }//of divide 
  case multi:{
    emit(fp, "","mult $a0, $a2" , "#multiply the left and right" );
    emit(fp, "", "mflo $a0", "#grabs the multuplication product from the low bit" );
    break;
  }//of multiply 
  case aNd:{
    emit(fp,"","and $a0, $a2,$a0","#ands the left and the right hand side");
    break;
  }//of and
  case oR:{
    emit(fp,"","or $a0, $a2, $a0","#ors the left and the right hand side");
    break; 
  }//of or
  case nOt:{
    emit(fp, "", "sltiu $a0, $a0, 1", "# the not" );                                                                                                                                                                                            break;
  }//of not 
  }//of operator handle
}//of emit expresion

//=========================================================================================
//pre con  a pointer to a write node and the file to wrtie to 
//post con emits the write call based on wheter it is a string or not
// and a new line 
void  emit_write(ASTnode *p,FILE *fp){

  char s[100];
  
  if(p->Name == NULL){
  emit_expr(p->s1,fp);//a0 is the value from the expr
  emit(fp,"","li $v0, 1","#print the number");
  emit(fp,"","syscall","#system call for printing the number");
  emit(fp,"","",""); //spacing emit
  emit(fp,"","li $v0, 4","#print the new line");                                                                                                                                                                                               emit(fp,"","la $a0,_NL","#the new line");                                                                                                                                                                                                    emit(fp,"","syscall","#system call for printing the string");
  }
  else{
    emit(fp,"","li $v0, 4","#print the string");
    sprintf(s,"la $a0, %s",p->label);
    emit(fp,"",s,"#the label to be printed");
    emit(fp,"","syscall","#system call for printing the string");
    emit(fp,"","",""); //spacing emit
    emit(fp,"","li $v0, 4","#print the new line");
    emit(fp,"","la $a0,_NL","#the new line");
    emit(fp,"","syscall","#system call for printing the string");
  }//string handle
  
}//of emit write
//==========================================================================================
//pre con a node to an identifier whether global or not and a fp to the file we wish to
//write to
//post con emits code to load the value into a0
void  emit_identifier(ASTnode *p,FILE *fp){

  //we need to find out if ident is a global or local
  //we need to figure out if ident is a scalar or array

  char s[100];
  
  if(p->symbol->level !=0){
    if(p->symbol->mysize ==1){
      sprintf(s,"add $a0, $sp , %d",p->symbol->offset *WSIZE);
      emit(fp,"",s,"#identifier is a local scalar");
      emit(fp,"","",""); //spacing emit
    }
    else{
      emit_expr(p->s1,fp);//storing internal offset in a0
      sprintf(s,"sll $t0, $a0 , %d", LOGWSIZE);
      emit(fp,"",s,"#array internal offset management");
      sprintf(s,"add $a0, $sp , %d",p->symbol->offset *WSIZE);
      emit(fp,"",s,"#identifier is a local array");                                                                                                                                                                                               emit(fp,"","",""); //spacing emit  
    } //of local arrays  
  }//of local idents 
  else{
    if(p->symbol->mysize != 1){
      emit_expr(p->s1,fp);
      sprintf(s,"la $t0, %s",p->Name);  // this stores the name into a register for calling
      emit(fp,"",s,"#getting array adress");
      emit(fp,"","li $t1, 4","#loading size into a temp to multiply");
      emit(fp,"","mult $a0,$t1","#multiplying internal offset by 4");
      emit(fp, "", "mflo $a0", "#grab the product" );
      emit(fp,"","add $a0, $t0,$a0","#adding internal offset ident is a global array");
      emit(fp,"","",""); //spacing emit
    }//of global arrays 
    else{
      sprintf(s,"la $a0,%s",p->Name); // calls value into a0
      emit(fp,"",s,"#identifier is a global scalar");                                                                                                                                                                                       
      emit(fp,"","",""); //spacing emit
    } //of global variables
    
  }//of global idents 

}//of emit ident
//==========================================================================================
//pre con a pointer to read node and the file pointer 
//post con a set of statments to write out the value of the ident in read 
void  emit_read(ASTnode *p,FILE *fp){

  emit_identifier(p->s1,fp);//$a0 is the adress we want to store in
  
  emit(fp,"","li $v0, 5","#reads from input a number into v0");
  emit(fp,"","syscall","#system call for reading in the number");
  emit(fp,"","sw $v0, ($a0)","#store the read into a memory location");
  emit(fp,"","",""); //we know $v0 has the value we read in
  

}//of emit read
//==========================================================================================
//pre con a pointer to a assign statment and the fp to the file
//post con the evaluated expression spilt apart evaluated then stored in a0
void emit_assign(ASTnode *p,FILE *fp){

  char s[100];
  
  emit_expr(p->s2,fp);
  sprintf(s,"sw $a0, %d($sp)",p->symbol->offset *WSIZE);
  emit(fp,"",s,"#store right hand side into node");
  emit_identifier(p->s1,fp);
  sprintf(s,"lw $t0 , %d($sp)",p->symbol->offset*WSIZE);
  emit(fp,"",s,"#store right hand side into register");
  emit(fp,"","sw $t0,($a0)","#store the right hand side in a0");
  
}//of emit assign
//==========================================================================================
//pre con a pointer to a if node and the fp
//post con the mips code to handle the if 
void emit_if(ASTnode *p,FILE *fp){

  char s[100];
  
  char *L1;   //the if and exit if labels
  char *L2;
  L1= genlabel();
  L2= genlabel();

  emit_expr(p->s1,fp); //emits and evals the conditon
  emit(fp,"","li $t0 ,0","#sets t0 to zero");
  sprintf(s,"beq $a0, $t0 %s",L1);
  emit(fp,"",s,"#check if not true");
  EMITAST(p->s2->s1,fp);//positive part 
  sprintf(s,"j %s",L2);
  emit(fp,"",s,"#jump to end");
  sprintf(s,"%s",L1);
  emit(fp,s,"","#else part");
  EMITAST(p->s2->s2,fp);
  sprintf(s,"%s",L2);
  emit(fp,s,"","#end of if statment");
  
}//of emit if
//===========================================================================================
//pre con a pointer to a while node and the fp
// post con the emited while statment
void emit_while(ASTnode *p,FILE *fp){

  char s[100];

  char *L1;
  char *L2;
  char *L3;
  L1= genlabel();
  L2= genlabel(); // i thought i needed three 
  L3= genlabel();

  sprintf(s,"%s",L1);                                                                                                                                                                                                                      
  emit(fp,s,"","#while");
  emit_expr(p->s1,fp);
  sprintf(s,"beq $a0, $0 %s",L3);
  emit(fp,"",s,"#if while condition no longer true");
  //sprintf(s,"%s",L2);
  // emit(fp,s,"","#do");
  EMITAST(p->s2,fp);
  sprintf(s,"j %s",L1);                                                                                                                                                                                                                    
  emit(fp,"",s,"#jump back to check while condition"); 
  sprintf(s,"%s",L3);
  emit(fp,s,"","#end of while");

}//of emit while
//===========================================================================================
//pre con a pointer to a call node aswell as the fp
//post con emits mips code to handle calls 
void emit_call(ASTnode *p, FILE *fp){

  //make a node for arg list on p
  char s[100];
  
  ASTnode *fun = p->s1;
  while(fun !=NULL){
    emit_expr(fun->s1,fp);
    sprintf(s,"sw $a0 , %d($sp)",fun->symbol->offset*WSIZE);
    emit(fp,"",s,"#stores arg list");
    fun = fun->next;
  }//stores vals of arg list 

  //calculate the future activation record 
  sprintf(s,"subu $t2 ,$sp, %d",p->symbol->mysize*WSIZE);
  emit(fp,"",s,"#subtracting size of function from stack pointer");

  fun=p->s1;
  ASTnode *fun2 = p->symbol->fparms;
  while(fun != NULL){
    sprintf(s,"lw $t0, %d($sp)",fun->symbol->offset*WSIZE);
    emit(fp,"",s,"#re grabbing values from temp nodes");
    sprintf(s, "sw $t0, %d($t2)", fun2->symbol->offset*WSIZE);
    emit(fp,"",s,"#putting values back into fparams adress");
    fun = fun->next;
    fun2 = fun2->next;
  }//this while loop loads then stores fparams values into where fparams actually is

  sprintf(s,"jal %s",p->Name);
  emit(fp,"",s,"#jumps and links the function call");

}//of emit call
//==========================================================================================
/*emitast(ASTNode p,FILE *fp) */
//pre con a pointer to the entire ast tree
//post con a emited mips code based on each seperate case call 
void EMITAST(ASTnode *p, FILE *fp){

  if(p==NULL)return;

  switch(p->type){
  case vardec:{
    break;
  }//of vardec
  case fundec:{
    emit_function_head(p,fp);
    EMITAST(p->s2,fp); //the block
    emit_function_return(NULL,fp);
    break;
  }//of fundec 
  case comp:{EMITAST(p->s2,fp);
    break;
  }//of compstat
  case WRIT:{
    emit_write(p,fp);
    break;
  }//of writ handle
  case RED:{
    emit_read(p,fp);
    break;
  }//of read stat
  case assign:{
    emit_assign(p,fp);
    break;
  }
  case iff:{
    emit_if(p,fp);
    break;
  }//of if handle
  case loop:{
    printf("hoi\n");
    emit_while(p,fp);
    printf("hoi\n"); 
    break;
  }//of while handle
  case exprstmt:{
    emit_expr(p->s1,fp);
    break;
  }//of callme
  case RET:{
    emit_function_return(p->s1,fp);
    break;
  }//of ret 
  default:printf("emit ast does not have this type \n");
    break;
  }//of switch
  

  EMITAST(p->next,fp);

}//of emit ast 
