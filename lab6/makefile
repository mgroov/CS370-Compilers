#Matthew Groover
#2-14-20
#this is the make file for lab 5 it combines all the 
#files for lab5 in order to update 
#if we need to run after updating  


all: 
	yacc -d lab6.y 
	lex lab6.l
	gcc lex.yy.c y.tab.c ast.c -o lab5
	
