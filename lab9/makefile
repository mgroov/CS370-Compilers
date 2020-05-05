#Matthew Groover
#2-14-20
#this is the make file for lab 7 it combines all the 
#files for lab5 in order to update 
#if we need to run after updating  


all: 
	yacc -d lab9.y 
	lex lab9.l
	gcc lex.yy.c y.tab.c ast.c symtable.c emit.c -o lab9
	
