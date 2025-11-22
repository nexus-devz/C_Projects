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

void registerBook(int* BookNum, Book *B);
void searchBook(int BookNum, int c, int n[], Book Books[]);
void book(int n[], int c, Book Books[]);
void searchBookByName(int n[], int s, int c, Book Books[]);
void searchBookByAuthor(int n[], int s, int c, Book Books[]);
void searchBookById(int n[], int s, int c, Book Books[]);
void searchBookByCatagory(int n[], int s, int c, Book Books[]);
void bookProfile(int n[], int c, Book Books[]);


#endif