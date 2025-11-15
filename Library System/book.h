//book.h
#ifndef BOOK_H
#define BOOK_H

typedef struct {
    char name[50], author[50], status[10], catg[10];
    int id, total, booklent, available, sem;
} Book;

void registerBook(int* BookNum, Book *B);
void searchBook(int BookNum, Book Books[]);
void book(int n[], int c, Book Books[]);
void searchBookByName(int n[], int s, int c, Book Books[]);
void searchBookByAuthor(int n[], int s, int c, Book Books[]);
void searchBookById(int n[], int s, int c, Book Books[]);
void searchBookByCatagory(int n[], int s, int c, Book Books[]);
void bookProfile(int n[], int c, Book Books[]);


#endif