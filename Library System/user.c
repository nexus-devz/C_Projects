//user functions
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "user.h"


void registerUser(int* userNum, User *U){
    int n, u= *userNum;
    printf("Enter the number of users you want to register: ");
    scanf(" %d", &n);
    //need to comp n and u (but if i use file handling then i dont need it)
    for(int i=0; i<n; i++){
        
        printf("user %d:\n", i+1);
        printf("Input name: ");
        scanf(" %s", &(U+u+i)->name); // did this cz i just wanted to practice pointer
        printf("Input id: ");
        scanf(" %d", &(U+u+i)->id);
        printf("Input department: ");
        scanf(" %s", &(U+u+i)->dept);
        printf("Input semester: ");
        scanf(" %d", &(U+u+i)->sem);
    }
    //updating how many users has been registered and adding with the previous number
    *userNum+=n;
    printf("Registration has been completed\n");
}

void searchUser(int userNum, User users[]){
    printf("Search by:\n1. Name\n2. id\n:");
    int c=0, n[userNum]; //temporary array to store indx with most possible size
    scanf(" %d",&c);
    if(c==1){
        searchByName(n, userNum, c, users);
    }
}

void searchByName(int n[],int s, int c, User users[]){
    //make this a search by name function**
        char name[50];
        printf("\nEnter name: ");
        scanf(" %s", name);
        int found=0;
        for(int i=0, a=0; i<s;i++){
            
                if(strstr(users[i].name,name)){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            {

            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,users[n[i]].name);
        }
        printf("\nChoose the user number from above to see user's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        profile(n, c-1, users);
        }
        
            }
        }
        else{
            printf("User not found.\n");
        }
}
void profile(int n[], int c, User users[]){
    //need to load user account details here
    printf("\tUser Profile:\n");
    printf("Name: %s\n", users[n[c]].name);
    printf("Id: %d\n", users[n[c]].id);
    printf("Dept: %s\n", users[n[c]].dept);
    printf("Semester: %d\n", users[n[c]].sem);
    printf("Books borrowed: %d\n", users[n[c]].booksKept);
    printf("Due: %d\n", users[n[c]].due);
    printf("Status: %s\n", users[n[c]].status);
    printf("\n\n\tChoose an option from below:\n");
    printf("1. Edit User Profile\n2. Lent Books\n3. Return Books\n0. Return to search\nEnter your choice: ");
    int ch;
    scanf(" %d", &ch);
    
    switch(ch) {
        case 0:
            return;
        case 1:
        // Add edit profile functionality
        printf("\n\n\tChoose an option from below:\n1. Name\n2. Id\n3. Department\n4. Semester\n5. Due\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
                case 1:
                printf("Input name: ");
                scanf(" %s", &users[n[c]].name);
                    break;
                case 2:
                printf("Input id: ");
                scanf(" %d", &users[n[c]].id);
                    break;
                case 3:
                printf("Input department: ");
                scanf(" %s", &users[n[c]].dept);
                    break;
                case 4:
                printf("Input semester: ");
                scanf(" %d", &users[n[c]].sem);
                    break;
                default:
            printf("Invalid choice!\n");
            break;
            }
            break;
        case 2:
            // Add lent books functionality
            //will be added after the books function is done
            break;
        case 3:
            // Add return books functionality
            //will be added after the books function is done
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

