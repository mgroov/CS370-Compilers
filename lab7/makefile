#Matthew Groover
#2-14-20
#this is the make file for lab 7 it combines all the 
#files for lab5 in order to update 
#if we need to run after updating  


all: 
	yacc -d lab7.y 
	lex lab7.l
	gcc lex.yy.c y.tab.c ast.c symtable.c -o lab7
	
