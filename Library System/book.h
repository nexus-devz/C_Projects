//book.h
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
void searchBook(int c, int n[]);
void searchBookByName(int n[], int s, int c);
void searchBookByAuthor(int n[], int s, int c);
void searchBookById(int n[], int s, int c);
void searchBookByCatagory(int n[], int s, int c);
void bookProfile(Book books);


#endif