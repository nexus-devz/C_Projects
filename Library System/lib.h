#ifndef LIB_H
#define LIB_H

#include "book.h"
#include "user.h"

// Lend a book to a user
void lentBooks(int bookNum, Book books[], User *users);;

// Return a book from a user
void returnBook(int bookNum, Book books[], User *users);

// Display all books lent to a user
void showUserBooks(User *users, int userCount, Book *books, int bookCount);

#endif
