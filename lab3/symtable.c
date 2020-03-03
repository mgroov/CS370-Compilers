//Matthew Groover 
//2-7-19
//this code was pulled from the canvas link the only changes I made was to formatt and comment
//these set of functions serve to add modify delete and search for items in a symbol table 
//Insert uses malloc to allocate then add a symbol to the table 
//display uses pointer and print statements to display the whole table
//search uses pointers to search the table then returns o or 1  
//modify uses pointers and search to modify a specified value or values of a member of the table
//delete removes a symbol by removing all refrences to a symbol in the table 


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
    void main()
    {
        int op,y;
        char la[10];
        do
        {
            printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
            printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
            printf("\n\tEnter your option : ");
            scanf("%d",&op);
            switch(op)
            {
                case 1:
                    Insert();
                    break;
                case 2:
                    Display();
                    break;
                case 3:
                    Delete();
                    break;
                case 4:
                    printf("\n\tEnter the label to be searched : ");  // this passes the user input to the search function in order to search the symbol table
                    scanf("%s",la);
                    y=Search(la);
                    printf("\n\tSearch Result:");
                    if(y==1)
                        printf("\n\tThe label is present in the symbol table\n");
                    else
                        printf("\n\tThe label is not present in the symbol table\n");
                    break;
                case 5:
                    Modify();
                    break;
                case 6:
                    exit(0);
            }//of switch case 
        }while(op<6); //end of do while 
        
    }  /* end of main */
    
//====================================================================================================================================================================
// this function uses the search function to first check wheter or not the symbol exists in the table
// it then uses the malloc function to reserve a space for the insert 
// after it verifies the place to insert the label it then inserts said label in order 

    void Insert()
    {
        int n;
        char l[10];
        printf("\n\tEnter the label : ");
        scanf("%s",l);
        n=Search(l);
        if(n==1)
            printf("\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted");
        else
        {
            struct SymbTab *p;
            p=malloc(sizeof(struct SymbTab));
            strcpy(p->label,l);
            printf("\n\tEnter the symbol : ");
            scanf("%s",p->symbol);
            printf("\n\tEnter the address : ");
            scanf("%d",&p->addr);
            p->next=NULL;
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
        printf("\n\tLabel inserted\n");
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
        printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");
        for(i=0;i<size;i++)
        {
            printf("\t%s\t\t%s\t\t%d\n",p->label,p->symbol,p->addr);
            p=p->next;
        }//of for loop 
    }//of DISPLAY
//=============================================================================================================    
   //this function uses pointers to search the table to match the passed label
   // it returns zero if false and 1 if true 
    int Search(char lab[])
    {
        int i,flag=0;
        struct SymbTab *p;
        p=first;
        for(i=0;i<size;i++)
        {
            if(strcmp(p->label,lab)==0)
                flag=1;
            p=p->next;
        }//of for loop 
        return flag;
    }//of search
//===========================================================================================================    
   //this function uses pointers first to check the existance of the label then 
   // uses pointers to modify the desired attributes then prints out the label and 
  // information that was modified 
    void Modify()
    {
        char l[10],nl[10];
        int add,choice,i,s;
        struct SymbTab *p;
        p=first;
        printf("\n\tWhat do you want to modify?\n");
        printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
        printf("\tEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n\tEnter the old label : ");
                scanf("%s",l);
                s=Search(l);
                if(s==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",nl);
                    for(i=0;i<size;i++)
                    {
                        if(strcmp(p->label,l)==0)
                            strcpy(p->label,nl);
                        p=p->next;
                    }//of for 
                    printf("\n\tAfter Modification:\n");
                    Display();
                }//of else 
                break;
            case 2:
                printf("\n\tEnter the label where the address is to be modified : ");
                scanf("%s",l);
                s=Search(l);
                if(s==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);
                    for(i=0;i<size;i++)
                    {
                        if(strcmp(p->label,l)==0)
                            p->addr=add;
                        p=p->next;
                    }//of for 
                    printf("\n\tAfter Modification:\n");
                    Display();
                }//of else 
                break;
            case 3:
                printf("\n\tEnter the old label : ");
                scanf("%s",l);
                s=Search(l);
                if(s==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",nl);
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);
                    for(i=0;i<size;i++)
                    {
                        if(strcmp(p->label,l)==0)
                        {
                            strcpy(p->label,nl);
                            p->addr=add;
                        }//of if  
                        p=p->next;
                    }//of for 
                    printf("\n\tAfter Modification:\n");
                    Display();
                }//of else 
                break;
        }//of switch
    }//of Modify
//================================================================================================================================================
    //this function uses the search function to first see if a label exists
    //if the label exists it then removes the pointers to the label so that the 
   // entry can no longer be accessed
    void Delete()
    {
        int a;
        char l[10];
        struct SymbTab *p,*q;
        p=first;
        printf("\n\tEnter the label to be deleted : ");
        scanf("%s",l);
        a=Search(l);
        if(a==0)
            printf("\n\tLabel not found\n");
        else
        {
            if(strcmp(first->label,l)==0)
                first=first->next;
            else if(strcmp(last->label,l)==0)
            {
                q=p->next;
                while(strcmp(q->label,l)!=0)
                {
                    p=p->next;
                    q=q->next;
                }//of while 
                p->next=NULL;
                last=p;
            }//of else if 
            else
            {
                q=p->next;
                while(strcmp(q->label,l)!=0)
                {
                    p=p->next;
                    q=q->next;
                }//of while 
                p->next=q->next;
            }//of else 
            size--;
            printf("\n\tAfter Deletion:\n");
            Display();
        }//of largest else 
    }//of delete
//=======================================================================================================================    
    
