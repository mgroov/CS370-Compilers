#matthew groover 
#1-22-20 
#This makefile runs two commands on the same file 
#first it updates lex.yy.c by compiling the new 
#wordlengthlab1 then compiles both into a single executable
 
wordlength:wordlengthlab1.l lex.yy.c 
	lex wordlengthlab1.l
	gcc -o wordlength lex.yy.c

