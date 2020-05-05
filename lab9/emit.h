//Matthew Groover march 4 -2020


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef EMIT_H
#define EMIT_H

#include "ast.h"
#include "symtable.h"
#define WSIZE 4  //word size
#define LOGWSIZE 2 // number of shifts till word size



char * genlabel();

void EMITSTRINGS(ASTnode *P,FILE *fp);
void EMITGLOBALS(ASTnode *P,FILE *fp);
#endif 
