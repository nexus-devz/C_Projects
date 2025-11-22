//book functions
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "book.h"



void registerBook(int* BookNum, Book *B){
    int n, u= *BookNum;
    printf("Enter the number of new books you want to register: ");
    scanf(" %d", &n);
    //need to comp n and u (but if i use file handling then i dont need it)
    for(int i=0; i<n; i++){
        int am = 0;
        printf("book %d:\n", i+1);
        printf("Input name: ");
        scanf(" %s", &(B+u+i)->name); // did this cz i just wanted to practice pointer
        printf("Input id: ");
        scanf(" %d", &(B+u+i)->id);
        printf("Input author: ");
        scanf(" %s", &(B+u+i)->author);
        printf("Input semester: ");
        scanf(" %d", &(B+u+i)->sem);
        printf("Input catagory: ");
        scanf(" %s", &(B+u+i)->catg);
        printf("Input amount: ");
        scanf("%d", &am);
        (B+u+i)->total+=am;
    }
    //updating how many books has been registered and adding with the previous number
    *BookNum+=n;
    printf("Registration has been completed.\n");
}

void searchBook(int bookNum, int c, int n[], Book Books[]){
    
    printf("Search by:\n1. Name\n2. Author\n3. Id\n4. Category\n:");
    

    scanf(" %d",&c);
    switch(c){
        case 1:
            searchBookByName(n, bookNum, c, Books);
            break;
        case 2:
            searchBookByAuthor(n, bookNum, c, Books);
            break;
        case 3:
            searchBookById(n, bookNum, c, Books);
            break;
        case 4:
            searchBookByCatagory(n, bookNum, c, Books);
            break;
        default:
            printf("Invalid Input\n");
            break;
    }
}

void searchBookByName(int n[], int s, int c, Book Books[]){
    //make this a search by name function**
        int isfnd =1;
        char name[50];
        while(isfnd){
        printf("\nEnter name: ");
        scanf(" %s", name);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(strstr(Books[i].name,name)){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            // while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            // {
            isfnd=0;
            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,Books[n[i]].name);
        }
        
        
            // }
        }
        else{
            printf("Book not found.\n");
        }
    }
}
void searchBookByAuthor(int n[], int s, int c, Book Books[]){
    char author[50];
        printf("\nEnter Author: ");
        scanf(" %s", author);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(strstr(Books[i].author,author)){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            {

            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,Books[n[i]].name);
        }
        printf("\nChoose the user number from above to see Books's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        bookProfile(n, c-1, Books);
        }
        
            }
        }
        else{
            printf("Book not found.\n");
        }

}
void searchBookById(int n[], int s, int c, Book Books[]){
    int id=0;
        printf("\nEnter Id: ");
        scanf(" %d", &id);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(Books[i].id==id){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            {

            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,Books[n[i]].name);
        }
        printf("\nChoose the user number from above to see Books's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        bookProfile(n, c-1, Books);
        }
        
            }
        }
        else{
            printf("Book not found.\n");
        }
}
void searchBookByCatagory(int n[], int s, int c, Book Books[]){
    char category[10];
        printf("\nEnter Author: ");
        scanf(" %s", category);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(strstr(Books[i].catg,category)){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            {

            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,Books[n[i]].name);
        }
        printf("\nChoose the user number from above to see Books's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        bookProfile(n, c-1, Books);
        }
        
            }
        }
        else{
            printf("Book not found.\n");
        }

}

void bookProfile(int n[], int c, Book Books[]){
    //need to load user account details here
    printf("\tUser Profile:\n");
    printf("Name: %s\n", Books[n[c]].name);
    printf("Id: %d\n", Books[n[c]].id);
    printf("Dept: %s\n", Books[n[c]].catg);
    printf("Semester: %d\n", Books[n[c]].sem);
    // printf("Books borrowed: %d\n", Books[n[c]].booksKept);
    // printf("Due: %d\n", Books[n[c]].due);
    printf("Status: %s\n", Books[n[c]].status);
    printf("\n\n\tChoose an option from below:\n");
    printf("1. Edit Book Profile\n0. Return to search\nEnter your choice: ");
    int ch;
    scanf(" %d", &ch);
    
    switch(ch) {
        case 0:
            return;
        case 1:
        // Add edit profile functionality
        printf("\n\n\tChoose an option from below:\n1. Name\n2. Id\n3. Author\n4. Semester\n5. Category\n6. Total Books\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
                case 1:
                printf("Input name: ");
                scanf(" %s", &Books[n[c]].name);
                    break;
                case 2:
                printf("Input id: ");
                scanf(" %d", &Books[n[c]].id);
                    break;
                case 3:
                printf("Input author: ");
                scanf(" %s", &Books[n[c]].author);
                    break;
                case 4:
                printf("Input semester: ");
                scanf(" %d", &Books[n[c]].sem);
                    break;
                case 5:
                printf("Input category: ");
                scanf(" %s", &Books[n[c]].catg);
                    break;
                case 6:
                printf("Input total books: ");
                scanf(" %d", &Books[n[c]].total);
                    break;
                case 7:
                printf("Input available books: ");
                scanf(" %d", &Books[n[c]].available);
                    break;
                case 8:
                printf("Input status: ");
                scanf(" %d", &Books[n[c]].status);
                    break;
                default:
            printf("Invalid choice!\n");
            break;
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

