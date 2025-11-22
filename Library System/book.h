//book.h
#ifndef BOOK_H
#define BOOK_H

#include "types.h"

void registerBook(int* BookNum, Book *B);
void searchBook(int BookNum, int c, int n[], Book Books[]);
void book(int n[], int c, Book Books[]);
void searchBookByName(int n[], int s, int c, Book Books[]);
void searchBookByAuthor(int n[], int s, int c, Book Books[]);
void searchBookById(int n[], int s, int c, Book Books[]);
void searchBookByCatagory(int n[], int s, int c, Book Books[]);
void bookProfile(int n[], int c, Book Books[]);
void lentBooks(int bookNum, Book books[], User *users);

#endif