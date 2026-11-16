// books functions
#include <stdio.h>
#include <string.h>
#include "lib.h"
/// onk kaj baki

void registerBook() {
    int n, u = *bookNum;
    printf("Enter the number of new books you want to register: ");
    scanf(" %d", &n);
    // need to comp n and u (but if i use file handling then i dont need it)
    for (int i = 0; i < n; i++) {
        int am = 0;
        printf("books %d:\n", i + 1);
        printf("Input name: ");
        scanf(" %s", books[u + i].name); // did this cz i just wanted to practice pointer
        printf("Input id: ");
        scanf(" %d", &(books + u + i)->id);
        printf("Input author: ");
        scanf(" %s", (books + u + i)->author); // i dont need address bcz using both pinter and array name which is pointer
        printf("Input semester: ");
        scanf(" %d", &(books + u + i)->sem); // need address for as it directes to an integer
        printf("Input catagory: ");
        scanf(" %s", &(books + u + i)->catg);
        printf("Input amount: ");
        scanf("%d", &am);
        (books + u + i)->total += am;
    }
    // updating how many books has been registered and adding with the previous number
    *bookNum += n;
    printf("Registration has been completed.\n");
}

void searchBook(int c, int n[]) {

    printf("Search by:\n1. Name\n2. Author\n3. Id\n4. Category\n:");

    scanf(" %d", &c);
    switch (c) {
    case 1:
        searchBookByName(n, *bookNum, c);
        break;
    case 2:
        searchBookByAuthor(n, *bookNum, c);
        break;
    case 3:
        searchBookById(n, *bookNum, c);
        break;
    case 4:
        searchBookByCatagory(n, *bookNum, c);
        break;
    default:
        printf("Invalid Input\n");
        break;
    }
}

void searchBookByName(int n[], int s) {
    // make this a search by name function**
    int isfnd = 1;
    char name[50];

    for (int t = 3; isfnd && t > 0; t--) {
        printf("\nEnter name: ");
        scanf(" %s", name);
        int found = 0;
        for (int i = 0, a = 0; i < s; i++) {

            if (strstr(books[i].name, name)) {
                n[a++] = i;
                found++;
            }
        }
        if (found) {
            // while (c) // this c can only be zero after the while funtion executes, it can be done with do-while
            // {
            isfnd = 0;
            printf("\n\tSearch Result:\n\n");
            for (int i = 0; i < found; i++) {
                printf("%d. %s\n", i + 1, books[n[i]].name);
            }

            // }
        } else {
            printf("books not found.\n");
        }
    }
}
void searchBookByAuthor(int n[], int s) {
    char author[50];
    printf("\nEnter Author: ");
    scanf(" %s", author);
    int found = 0;
    for (int i = 0, a = 0; i < s; i++) {

        if (strstr(books[i].author, author)) {
            n[a++] = i;
            found++;
        }
    }
    if (found) {

        printf("\n\tSearch Result:\n\n");
        for (int i = 0; i < found; i++) {
            printf("%d. %s\n", i + 1, books[n[i]].name);
        }
    } else {
        printf("books not found.\n");
    }
}
void searchBookById(int n[], int s, int c) {
    int id = 0;
    printf("\nEnter Id: ");
    scanf(" %d", &id);
    int found = 0;
    for (int i = 0, a = 0; i < s; i++) {

        if (books[i].id == id) {
            n[a++] = i;
            found++;
        }
    }
    if (found) {
       

            printf("\n\tSearch Result:\n\n");
            for (int i = 0; i < found; i++) {
                printf("%d. %s\n", i + 1, books[n[i]].name);
            }
            
    } else {
        printf("books not found.\n");
    }
}
void searchBookByCatagory(int n[], int s) {
    char category[10];
    printf("\nEnter Author: ");
    scanf(" %s", category);
    int found = 0;
    for (int i = 0, a = 0; i < s; i++) {

        if (strstr(books[i].catg, category)) {
            n[a++] = i;
            found++;
        }
    }
    if (found) {
        

            printf("\n\tSearch Result:\n\n");
            for (int i = 0; i < found; i++) {
                printf("%d. %s\n", i + 1, books[n[i]].name);
            }
        
    } else {
        printf("books not found.\n");
    }
}

void bookProfile(Book books) {
    // need to load user account details here
    printf("\tUser Profile:\n");
    printf("Name: %s\n", books.name);
    printf("Id: %d\n", books.id);
    printf("Dept: %s\n", books.catg);
    printf("Semester: %d\n", books.sem);
    // printf("books borrowed: %d\n", books.booksKept);
    // printf("Due: %d\n", books.due);
    printf("Status: %s\n", books.status);
    printf("Total Books: %d\n", books.total);
    printf("\n\n\tChoose an option from below:\n");
    printf("1. Edit books Profile\n0. Return to search\nEnter your choice: ");
    int ch;
    scanf(" %d", &ch);

    switch (ch) {
    case 0:
        return;
    case 1:
        // Add edit profile functionality
        printf("\n\n\tChoose an option from below:\n1. Name\n2. Id\n3. Author\n4. Semester\n5. Category\n6. Total books\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Input name: ");
            scanf(" %s", &books.name);
            break;
        case 2:
            printf("Input id: ");
            scanf(" %d", &books.id);
            break;
        case 3:
            printf("Input author: ");
            scanf(" %s", &books.author);
            break;
        case 4:
            printf("Input semester: ");
            scanf(" %d", &books.sem);
            break;
        case 5:
            printf("Input category: ");
            scanf(" %s", &books.catg);
            break;
        case 6:
            printf("Input total books: ");
            scanf(" %d", &books.total);
            break;
        case 7:
            printf("Input available books: ");
            scanf(" %d", &books.available);
            break;
        case 8:
            printf("Input status: ");
            scanf(" %d", &books.status);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
}
