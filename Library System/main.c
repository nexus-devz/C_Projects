//Library system

#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #include "user.h"
// #include "book.h"
#include "lib.h" // as lib.h has both user.h and book.h in it i dont nned to write them saperately

 int userCount = 0; // for now
 int bookCount = 0; // for now
 User user[1000];
 Book book[1000];

 //pointer init
    int *userNum = &userCount;;
    int *bookNum = &bookCount;

const char adminName[] = "admin";
const char adminPass[] = "1234";

int isLoggedIn();

int main(){
    char opt = '0';
    
    
    printf("\tWelcome to Ist Library\nPlease verify your user name and password\n\n");

    if(isLoggedIn()){
        //load and update info
        while(opt!='3'){
            printf("Main menu\n");
            printf("\t1. Users\n\t2. Books\n\t3. Quit\n");
            printf("Enter the option number of your choice: ");
        scanf(" %c", &opt);

        switch(opt){

            case '1':{
            char ch='0';
            while(ch!='3'){
                printf("Choose from below:\n");
                printf("\t1. Register Users\n\t2. Search user-profile\n\t3. Back\n");
                printf("Enter the option number of your choice: ");
            scanf(" %c", &ch);
            switch(ch){
            case '1':
                registerUser();
                break;
            case '2':{
                int n[userCount], c=0;
                searchUser(n, c); // need changes
                printf("\nChoose the user number from above to see user's profile. Type 0 to return: ");
                scanf(" %d",&c);
                if(c){
                profile(user[n[c-1]]);
                }
                break;
            }
            default:
                break;
                }
            }// braces is a good practice, but still works without braces
            break;
        }
        case '2':
            //books
            char choice='0';
            while(choice!='3'){
                printf("Choose from below:\n");
                printf("\t1. Register new books\n\t2. Search books\n\t3. Back\n");
                printf("Enter the option number of your choice: ");
            scanf(" %c", &choice);
            switch(choice){
            case '1':
                registerBook();
                break;
            
            case '2':{
                int c=0, n[bookCount]; //temporary array to store indx with most possible size
                searchBook(c, n);

                printf("\nChoose the user number from above to see Books's profile. Type 0 to return: ");
                scanf(" %d",&c);
                if(c){
                bookProfile(book[n[c-1]]);
                }
                break;
            }

            default:
                break;
                }
            }
            break;

        case '3':
            return 0;
        
        default:
            printf("Invalid input");
            break;
        }
    }
}





}


int isLoggedIn(){
    int try=3;
    char name[50], pass[50];
    while(try--){
        printf("Username: ");
        scanf(" %s", name);
        printf("Password: ");
        scanf(" %s", pass);
        if(strcmp(name,adminName) == 0 && strcmp(pass,adminPass) == 0){
            printf("Successfully logged in\n");
            return 1;
        }
        else{
            printf("invalid username or password.\nplease try again\n");
        }
    }
    printf("3 unsuccessfull attempt has been made. Try again later\n");
    return 0;
}


/* Plan
1. make a book structure \/
2. make sure to use some of books elemnnt with user such as books keeping duration. 
3. make a profile loading function
4. make sure to update dues, book kept duration etc with current date
5. use file handling for better data arrangement
*/