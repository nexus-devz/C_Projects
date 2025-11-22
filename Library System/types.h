#ifndef TYPES_H
#define TYPES_H

typedef struct User {
    char name[50];
    char pass[50];
    char status[10];
    char dept[10];
    int id;
    int booksKept;
    int due;
    int sem;
} User;

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

#endif