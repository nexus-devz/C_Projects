//book.h
#ifndef BOOK_H
#define BOOK_H

typedef struct {
    char name[50], author[50], status[10], catg[10];
    int id, total, booklent, available, sem;
} Book;

void registerBook(int* BookNum, Book *B);
void searchBook(int BookNum, Book Books[]);
void profile(int n[], int c, Book Books[]);
void searchByName(int n[], int s, int c, Book Books[]);
void searchByAuthor(int n[], int s, int c, Book Books[]);
void searchByid(int n[], int s, int c, Book Books[]);
void searchBycatagory(int n[], int s, int c, Book Books[]);


#endif