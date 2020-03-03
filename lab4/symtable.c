//Matthew Groover 
//2-7-19
//this code was pulled from the canvas link the only changes I made was to formatt and comment
//these set of functions serve to add modify delete and search for items in a symbol table 
//Insert uses malloc to allocate then add a symbol to the table 
//display uses pointer and print statements to display the whole table
//search uses pointers to search the table then returns o or 1  
//modify uses pointers and search to modify a specified value or values of a member of the table
//delete removes a symbol by removing all refrences to a symbol in the table 
/*
 * modified by mg 
 *	2-21-20 - 2-23-20
 *  changed all of the main function to work with parameters
 *  commented out main function and removed main parts of the delete 
 *  function.
 *  added fetch_adress to return the adress of a matching symbol to 
 *  the y code. with the precondition that the symbol must exist  
 * 
 *  
*/

#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"
int size=0;



    struct SymbTab *first,*last; // global pointers
//=================================================================================================================================================================
//this function loops while user input is less than 6 
//based on the choice of the user this function calls the function required     
  
//   void main()
//     {
//         printf("search returns %d\n",Search("my first"));
//         Insert("my first",0);
//         Insert("my second",1);
//         Insert("my third",2);
//         printf("search returns %d\n",Search("my first"));
//         Display();
//     }  /* end of main */
    
//====================================================================================================================================================================
// this function uses the search function to first check wheter or not the symbol exists in the table
// it then uses the malloc function to reserve a space for the insert 
// after it verifies the place to insert the label it then inserts said label in order 

    void Insert(char *sym,int offset)
    {
        int n;

        n=Search(sym);
        
        if(n==1)
            printf("\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted");
        else
        {
            struct SymbTab *p;
            p=malloc(sizeof(struct SymbTab));
            p->symbol = strdup(sym);
            p->next=NULL;
            p->addr=offset;
            if(size==0)
            {
                first=p;
                last=p;
            }//of if
            else
            {
                last->next=p;
                last=p;
            }//of else 
            size++;
        }//of else where N!=1
       
       
    }//of Insert
//=============================================================================================================
    // this function uses pointers to itterate through 
    // and print all the members and information in the
    // symbol table
    void Display()
    {
        int i;
        struct SymbTab *p;
        p=first;
        printf("\t\tSYMBOL\t\tADDRESS\n");
        for(i=0;i<size;i++)
        {
            printf("\t\t%s\t\t%d\n",p->symbol,p->addr);
            p=p->next;
        }//of for loop 
    }//of DISPLAY
//=============================================================================================================    
   //this function uses pointers to search the table to match the passed label
   // it returns zero if false and 1 if true 
    int Search(char *sym)
    {
        int i,flag=0;
        struct SymbTab *p;
        p=first;
        for(i=0;i<size;i++)
        {
            if(strcmp(p->symbol,sym)==0)
                flag=1;
            p=p->next;
        }//of for loop 
        return flag;
    }//of search
//===========================================================================================================    
    //@precondition you must know that the symbol is in the table before you call my function
    //this function uses pointers to find a return the adress of the symbol 
    int fetch_adress(char *symbol){
       struct SymbTab *cursor = first ;
        while(first != NULL)
        {
            if(strcmp(cursor->symbol,symbol)==0){
             
                return(cursor->addr);
            
            }//of if it is the symbol
            cursor = cursor->next;
        }//of while    
        printf("you have failed the symbol does not exist \n");
    }//of getch adress 

//===========================================================================================================
    //this function uses the search function to first see if a label exists
    //if the label exists it then removes the pointers to the label so that the 
   // entry can no longer be accessed
    void Delete()
    {
        // to be fixed later
    }//of delete
//=======================================================================================================================    
    
