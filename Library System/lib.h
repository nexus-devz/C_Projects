#ifndef LIB_H
#define LIB_H

#include "book.h"
#include "user.h"
#define File_Book "books.txt"
#define FIle_Mem "user.txt"

extern int userCount; // for now
extern int bookCount; // for now
extern User *users;
extern Book *books;
// pointer def
extern int *userNum, *bookNum;
extern FILE* fmem, *fbook, *counter;
// Lend a book to a user
void lentBooks();

// Return a book from a user
void returnBook();

// Display all books lent to a user
void showUserBooks();

void load();
void loadFile();
void dynamicArrayLoad();

void loadUserArray();
void loadBooksArray();
#endif
