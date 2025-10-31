// user.h
#ifndef USER_H
#define USER_H

typedef struct {
    char name[50], pass[50], status[10], dept[10];
    int id, booksKept, due, sem;
} User;


void registerUser(int* userNum, User *U);
void searchUser(int userNum, User users[]);
void profile(int n[], int c, User users[]);
void searchByName(int n[], int s, int c, User users[]);

#endif