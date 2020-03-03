//Mstthew Groover 
//2-7-20
//this file serves to provide a outline for the functions used in symtable.c


#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#ifndef SYMBTAB
#define SYMBTAB
void Insert();
void Display();
void Delete();
int Search(char *sym);void Modify();
int fetch_adress(char *symbol);
struct SymbTab{
    char *symbol;
    int addr;
    struct SymbTab *next;
    
};//of SymbTab

#endif //of SymbTab
