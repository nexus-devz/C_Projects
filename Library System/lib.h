#ifndef LIB_H
#define LIB_H

#include "book.h"
#include "user.h"

    extern int userCount; // for now
    extern int bookCount; // for now
    extern User user[1000];
    extern Book book[1000];
    //pointer def
    extern int *userNum, *bookNum;

// Lend a book to a user
void lentBooks(User *users);

// Return a book from a user
void returnBook(User *users);

// Display all books lent to a user
void showUserBooks(User *users, Book *books);

#endif
