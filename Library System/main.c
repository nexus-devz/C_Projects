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
void profile(int n[], int c, User users[]);
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
        scanf("  %c", &opt);

        switch(opt){

            case '1':
            char ch;
            while(ch!='3'){
                printf("Choose from below:\n");
                printf("\t1. Register Users\n\t2. Search user-profile\n\t3. Back\n");
                printf("Enter the option number of your choice: ");
            scanf("  %c", &ch);
            switch(ch){
            case '1':
                registerUser(&userCount, user);
                break;
            case '2':
                searchUser(&userCount,user);
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

void registerUser(int* userNum, User *U){
    int n, u= *userNum;
    printf("Enter the number of users you want to register: ");
    scanf(" %d", &n);
    //need to comp n and u
    for(int i=0; i<n; i++){
        
        printf("user %d:\n", i+1);
        printf("Input name: ");
        scanf(" %s", &(U+u+i)->name);
        printf("Input id: ");
        scanf(" %d", &(U+u+i)->id);
        printf("Input department: ");
        scanf(" %s", &(U+u+i)->dept);
        printf("Input semester: ");
        scanf(" %d", &(U+u+i)->sem);
    }
    *userNum+=n;
    printf("Registration has been completed\n");
}

void searchUser(int* userNum, User users[]){
    printf("Search by:\n1. Name\n2. id\n:");
    int c, n[*userNum]; //temporary array to store indx with most possible size
    scanf(" %d",&c);
    if(c==1){
        char name[50];
        printf("\nEnter name: ");
        scanf(" %s", name);
        int found=0;
        for(int i=0, a=0; i<*userNum;i++){
            
                if(strstr(users[i].name,name)){
                    n[a++]=i;
                    found++;
            }
        }
        if(found){
            printf("\n\tSearch Result:\n\n");
        for(int i=0; i<found; i++){
            printf("%d. %s\n",i+1,users[n[i]].name);
        }
        printf("\nChoose the user number from above to see user's profile. Type 0 to return: ");
        scanf(" %d",&c);
        if(c){
        profile(n, c, users);
        }
        

        }
        else{
            printf("User not found.\n");
        }
    }
}

void profile(int n[], int c, User users[]){
    //need to load user account details here
    printf("\tUser Profile:\n");
    printf("Name: %s\n", users[n[c-1]].name);
    printf("Id: %d\n", users[n[c-1]].id);
    printf("Dept: %s\n", users[n[c-1]].dept);
    printf("Semester: %d\n", users[n[c-1]].sem);
    printf("Books borrowed: %d\n", users[n[c-1]].booksKept);
    printf("Due: %d\n", users[n[c-1]].due);
    printf("Status: %s\n", users[n[c-1]].status);
    printf("\n\n\tChoose an option from below:\n");
    printf("1. Edit User Profile\n2. Lent Books\n3. Return Books\n4. Return to menu\nEnter your choice: ");
    scanf(" %d", &c);
    
    switch(c) {
        case 1:
            // Add edit profile functionality
            break;
        case 2:
            // Add lent books functionality
            break;
        case 3:
            // Add return books functionality
            break;
        case 4:
            return;
        default:
            printf("Invalid choice!\n");
            break;
    }
}



/* Plan
1. make a book structure
2. make sure to use some of books elemnnt with user such as books keeping duration.
3. make a profile loading function
4. make sure to update dues, book kept duration etc with current date
5. use file handling for better data arrangement
*/