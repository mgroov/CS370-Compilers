#Matthew Groover
#2-14-20
#this is the make file for lab 4 it combines all the 
#files for lab4 in order to update 
#if we need to run after updating  


all: 
	yacc -d lab4.y 
	lex lab4.l
	gcc lex.yy.c y.tab.c symtable.c -o lab4
	
