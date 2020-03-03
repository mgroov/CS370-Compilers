#Matthew Groover
#2-3-20
#this make file ensures that every time its run the 
#lex file and yacc file then compiles them into an object
#1) yacc makes y.tab.h , y.tab.c and .lab2docalc.y.swp
#2) lex makes lex.yy.c
#3) you wouldn't becuase it's included then compiled in the y file 
# therefore it would mess with the y compile  
all:
	yacc -d lab2docalc.y
	lex lab2docalc.l
	gcc y.tab.c -o lab2docalc
