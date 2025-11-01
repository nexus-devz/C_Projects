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
        printf("user %d:\n", i+1);
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
    //updating how many users has been registered and adding with the previous number
    *BookNum+=n;
    printf("Registration has been completed.\n");
}

void searchBook(int bookNum, Book users[]){
    printf("Search by:\n1. Name\n2. id\n:");
    int c=0, n[bookNum]; //temporary array to store indx with most possible size
    scanf(" %d",&c);
    if(c==1){
        // searchByName(n, bookNum, c, users);
    }
}