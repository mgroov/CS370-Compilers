//Matthew Groover may 4 -2020 - may 8, 2020


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef EMIT_H
#define EMIT_H

#include "ast.h"
#include "symtable.h"
#define WSIZE 4  //word size
#define LOGWSIZE 2 // number of shifts till word size



char * genlabel();   //function prototypes 

void EMITSTRINGS(ASTnode *P,FILE *fp);
void EMITGLOBALS(ASTnode *P,FILE *fp);
void EMITAST(ASTnode *p, FILE *fp);
void emit_expr(ASTnode *p, FILE *fp);
void emit_identifier(ASTnode *p, FILE *fp);
void emit_if(ASTnode *p, FILE *fp);
void emit_assign(ASTnode *p, FILE *fp);
void emit_call(ASTnode *p, FILE *fp);
#endif 
