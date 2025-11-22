// user.h
#ifndef USER_H
#define USER_H

#include "types.h"

/* function prototypes — types User and Book come from types.h */
void registerUser(int* userNum, User *U);
void searchUser(int userNum, User users[]);
void profile(int n[], int c, User users[], Book books[], int bookNum);
void searchByName(int n[], int s, int c, User users[]);

#endif