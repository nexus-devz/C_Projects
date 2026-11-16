// book.h
#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
    char name[50];
    char author[50];
    char status[10];
    char catg[10];
    int id;
    int total;
    int booklent;
    int available;
    int sem;
} Book;

void registerBook();
void searchBook(int n[]);
void searchBookByName(int n[]);
void searchBookByAuthor(int n[]);
void searchBookById(int n[]);
void searchBookByCatagory(int n[]);
void bookProfile(Book books);

#endif