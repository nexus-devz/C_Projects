// user.h
#ifndef USER_H
#define USER_H
#include "book.h"
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

/* function prototypes — types User and Book come from types.h */
void registerUser();
void searchUser(int n[], int c);
void profile(User user);
void searchByName(int n[], int s, int c);

#endif