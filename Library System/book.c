//book functions
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "lib.h"



void registerBook(){
    int n, u= *bookNum;
    printf("Enter the number of new books you want to register: ");
    scanf(" %d", &n);
    //need to comp n and u (but if i use file handling then i dont need it)
    for(int i=0; i<n; i++){
        int am = 0;
        printf("book %d:\n", i+1);
        printf("Input name: ");
        scanf(" %s", &(book+u+i)->name); // did this cz i just wanted to practice pointer
        printf("Input id: ");
        scanf(" %d", &(book+u+i)->id);
        printf("Input author: ");
        scanf(" %s", &(book+u+i)->author);
        printf("Input semester: ");
        scanf(" %d", &(book+u+i)->sem);
        printf("Input catagory: ");
        scanf(" %s", &(book+u+i)->catg);
        printf("Input amount: ");
        scanf("%d", &am);
        (book+u+i)->total+=am;
    }
    //updating how many books has been registered and adding with the previous number
    *bookNum+=n;
    printf("Registration has been completed.\n");
}

void searchBook(int c, int n[]){
    
    printf("Search by:\n1. Name\n2. Author\n3. Id\n4. Category\n:");
    

    scanf(" %d",&c);
    switch(c){
        case 1:
            searchBookByName(n, *bookNum, c);
            break;
        case 2:
            searchBookByAuthor(n, *bookNum, c);
            break;
        case 3:
            searchBookById(n, *bookNum, c);
            break;
        case 4:
            searchBookByCatagory(n, *bookNum, c);
            break;
        default:
            printf("Invalid Input\n");
            break;
    }
}

void searchBookByName(int n[], int s, int c){
    //make this a search by name function**
        int isfnd =1;
        char name[50];
        while(isfnd){
        printf("\nEnter name: ");
        scanf(" %s", name);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(strstr(book[i].name,name)){
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
            printf("%d. %s\n",i+1,book[n[i]].name);
        }
        
        
            // }
        }
        else{
            printf("Book not found.\n");
        }
    }
}
void searchBookByAuthor(int n[], int s, int c){
    char author[50];
        printf("\nEnter Author: ");
        scanf(" %s", author);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(strstr(book[i].author,author)){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            {

            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,book[n[i]].name);
        }
        printf("\nChoose the user number from above to see book's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        bookProfile(book[n[c-1]]);
        }
        
            }
        }
        else{
            printf("Book not found.\n");
        }

}
void searchBookById(int n[], int s, int c){
    int id=0;
        printf("\nEnter Id: ");
        scanf(" %d", &id);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(book[i].id==id){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            {

            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,book[n[i]].name);
        }
        printf("\nChoose the user number from above to see book's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        bookProfile(book[n[c-1]]);
        }
        
            }
        }
        else{
            printf("Book not found.\n");
        }
}
void searchBookByCatagory(int n[], int s, int c){
    char category[10];
        printf("\nEnter Author: ");
        scanf(" %s", category);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(strstr(book[i].catg,category)){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            {

            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,book[n[i]].name);
        }
        printf("\nChoose the user number from above to see book's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        bookProfile(book[n[c-1]]);
        }
        
            }
        }
        else{
            printf("Book not found.\n");
        }

}

void bookProfile(Book books){
    //need to load user account details here
    printf("\tUser Profile:\n");
    printf("Name: %s\n", books.name);
    printf("Id: %d\n", books.id);
    printf("Dept: %s\n", books.catg);
    printf("Semester: %d\n", books.sem);
    // printf("book borrowed: %d\n", books.booksKept);
    // printf("Due: %d\n", books.due);
    printf("Status: %s\n", books.status);
    printf("\n\n\tChoose an option from below:\n");
    printf("1. Edit Book Profile\n0. Return to search\nEnter your choice: ");
    int ch;
    scanf(" %d", &ch);
    
    switch(ch) {
        case 0:
            return;
        case 1:
        // Add edit profile functionality
        printf("\n\n\tChoose an option from below:\n1. Name\n2. Id\n3. Author\n4. Semester\n5. Category\n6. Total book\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
                case 1:
                printf("Input name: ");
                scanf(" %s", &books.name);
                    break;
                case 2:
                printf("Input id: ");
                scanf(" %d", &books.id);
                    break;
                case 3:
                printf("Input author: ");
                scanf(" %s", &books.author);
                    break;
                case 4:
                printf("Input semester: ");
                scanf(" %d", &books.sem);
                    break;
                case 5:
                printf("Input category: ");
                scanf(" %s", &books.catg);
                    break;
                case 6:
                printf("Input total books: ");
                scanf(" %d", &books.total);
                    break;
                case 7:
                printf("Input available books: ");
                scanf(" %d", &books.available);
                    break;
                case 8:
                printf("Input status: ");
                scanf(" %d", &books.status);
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

