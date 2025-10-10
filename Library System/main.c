//Library system

#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char adminName[] = "admin";
const char adminPass[] = "1234";
typedef struct {
    char name[50], pass[50], status[10], dept[10];
    int id, booksKept, due, sem;
}User;

int isLoggedIn();
void registerUser(int* userNum, User *U);
void searchUser();

int main(){
    char opt ;
    int userCount = 0; // for now
    int bookCount = 0; // for now
    User user[1000];
    
    printf("\tWelcome to Ist Library\nPlease verify your user name and password\n\n");

    if(isLoggedIn()){
        while(opt!='3'){
            printf("Main menu\n");
            printf("\t1. Users\n\t2. Books\n\t3. Quit\n");
            printf("Enter the option number of your choice: ");
        scanf(" %c", &opt);

        switch(opt){

            case '1':
            char ch;
            while(ch!='3'){
                printf("Choose from below:\n");
                printf("\t1. Register Users\n\t2. Search user-profile\n\t3. Back\n");
                printf("Enter the option number of your choice: ");
            scanf(" %c", &ch);
            switch(ch){
            case '1':
                registerUser(&userCount, user);
                break;
            case '2':
                searchUser();
                break;
            default:
                break;
                }
            }
                break;

        case '2':
            //books
            break;
        default:
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
        scanf("%s", name);
        printf("Password: ");
        scanf("%s", pass);
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

void registerUser(int* userNum, User *U){
    int n, u= *userNum;
    printf("Enter the number of users you want to register: ");
    scanf("%d", &n);
    //need to comp n and u
    for(int i=0; i<n; i++){
        
        printf("user %d:\n", i+1);
        printf("Input name: ");
        scanf("%s", (U+u+i)->name);
        printf("Input id: ");
        scanf("%d", (U+u+i)->id);
        printf("Input department: ");
        scanf("%s", (U+u+i)->dept);
        printf("Input semester: ");
        scanf("%d", (U+u+i)->sem);
    }
    printf("Registration has been completed\n");
}

void searchUser(){

}