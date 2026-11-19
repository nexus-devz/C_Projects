// user functions
#include <stdio.h>
#include <string.h>
#include "lib.h" // provides functions/types used here; lib.h includes user.h (but consider including user.h directly if this file depends on User)

void registerUser() {
    int n, u = *userNum;
    fmem = fopen(FIle_Mem,"a+");
    counter = fopen("counter.txt", "a+");
    fseek(fmem,0,SEEK_END);
    fseek(counter,0,SEEK_END);
    printf("Enter the number of user you want to register: ");
    scanf(" %d", &n);
    // need to comp n and u (but if i use file handling then i dont need it)
    for (int i = 0; i < n; i++) {

        printf("user %d:\n", i + 1);
        printf("Input name: ");
        scanf(" %s", (users + u + i)->name); // did this cz i just wanted to practice pointer
        printf("Input id: ");
        scanf(" %d", &(users + u + i)->id);
        printf("Input department: ");
        scanf(" %s", (users + u + i)->dept);
        printf("Input semester: ");
        scanf(" %d", &(users + u + i)->sem);
        users[u+i].due = users[u+i].booksKept = 0;
        strcpy(users[u+i].status, "New"); // array cant be assigned after declaration
        // input all to user file
        fprintf(fmem,"%8d|%20s|%5s|%5d|%10d|%5d|%10s\n",users[u+i].id,users[u+i].name,users[u+i].dept,users[u+i].sem,users[u+i].booksKept,users[u+i].due,users[u+i].status);
    }
    // updating how many user has been registered and adding with the previous number
    *userNum += n;
    fprintf(counter,"\n%10d%10d",userCount,bookCount);
    printf("Registration has been completed\n");
    fclose(fmem);
    fclose(counter);
}

void searchUser(int n[], int c) {
    printf("Search by:\n1. Name\n2. id\n:");
    // int c=0, n[*userNum]; //temporary array to store indx with most possible size
    scanf(" %d", &c);
    if (c == 1) {
        searchByName(n, *userNum);
    }
}

void searchByName(int n[], int s) {
    // make this a search by name function**
    char name[50];
    printf("\nEnter name: ");
    scanf(" %s", name);
    int found = 0;
    for (int i = 0, a = 0; i < s; i++) {

        if (strstr(users[i].name, name)) {
            n[a++] = i;
            found++;
        }
    }
    if (found) {
        // while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
        // {

        printf("\n\tSearch Result:\n\n");
        for (int i = 0; i < found; i++) {
            printf("%d. %s\n", i + 1, users[n[i]].name);
        }

        // }
    } else {
        printf("User not found.\n");
    }
}

void profile(User users) {
    // need to load user account details here
    printf("\tUser Profile:\n");
    printf("Name: %s\n", users.name);
    printf("Id: %d\n", users.id);
    printf("Dept: %s\n", users.dept);
    printf("Semester: %d\n", users.sem);
    printf("Books borrowed: %d\n", users.booksKept);
    printf("Due: %d\n", users.due);
    printf("Status: %s\n", users.status);
    printf("\n\n\tChoose an option from below:\n");
    printf("1. Edit User Profile\n2. Lent Books\n3. Return Books\n0. Return to search\nEnter your choice: ");
    int ch;
    scanf(" %d", &ch);

    switch (ch) {
    case 0:
        return;
    case 1:
        // Add edit profile functionality
        printf("\n\n\tChoose an option from below:\n1. Name\n2. Id\n3. Department\n4. Semester\n5. Due\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Input name: ");
            scanf(" %s", &users.name);
            break;
        case 2:
            printf("Input id: ");
            scanf(" %d", &users.id);
            break;
        case 3:
            printf("Input department: ");
            scanf(" %s", &users.dept);
            break;
        case 4:
            printf("Input semester: ");
            scanf(" %d", &users.sem);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
        break;
    case 2:
        // Add lent books functionality
        lentBooks();
        break;
    case 3:
        // Add return books functionality
        // returnBook();
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
}

// search and profile function need to be separate so i can use them again