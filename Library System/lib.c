//combine functions
#include<stdio.h>
#include "lib.h"

void lentBooks(int bookNum, Book books[], User *users){
    User selUser = *users;
    int n[bookNum], found=0;
    // need a loop
    printf("Search for the book\n");
    searchBook(bookNum, found, n, books);
    printf("\nChoose the book to be lent. Type 0 to return: ");
    scanf(" %d",&found);
    printf("How many book to be lent: ");
    int cnt=0;
    scanf("%d", &cnt);
    selUser.booksKept += cnt;
    books[n[found-1]].booklent += cnt;
    books[n[found-1]].available = books[n[found-1]].total - books[n[found-1]].booklent;
    *users = selUser;
    printf("Book has been lent for 15 days.\n");
}