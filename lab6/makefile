#Matthew Groover
#3-6-20
#this is the make file for lab 6 it combines all the 
#files for lab6 in order to update 
#if we need to run after updating  


all: 
	yacc -d lab6.y 
	lex lab6.l
	gcc lex.yy.c y.tab.c ast.c -o lab6
	
