// combine functions
#include <stdio.h>
#include "lib.h"

void lentBooks() {
    User selUser = *users;
    int n[*bookNum], found = 0;
    // need a loop
    printf("Search for the book\n");
    searchBook(n);
    printf("\nChoose the book to be lent. Type 0 to return: ");
    scanf(" %d", &found);
    if (!found) {
        return;
    }
    printf("How many book to be lent: ");
    int cnt = 0;
    scanf("%d", &cnt);
    selUser.booksKept += cnt;
    books[n[found - 1]].booklent += cnt;
    books[n[found - 1]].available = books[n[found - 1]].total - books[n[found - 1]].booklent;
    *users = selUser;
    printf("Book has been lent for 15 days.\n");
}

void load(){
     fmem = fopen("user.txt", "a+");
     fbook = fopen("books.txt", "a+");
     counter = fopen("counter.txt","a+");
    

     if (fmem == NULL || fbook == NULL || counter==NULL) {
        printf("The file is not opened.");
    }
    else{
        printf("File opened successfully\n");
    }
    //set position to the end
    
    fseek(fmem, 0, SEEK_END);
    fseek(fbook, 0, SEEK_END);
    fseek(counter,0,SEEK_END);
    //check file if empty or not
    if(ftell(fmem)==0){
        fprintf(fmem,"%8s|%20s|%5s|%5s|%10s|%5s|%10s\n","Id","Name","Dept","Sem","Borrowed","Due","Status");

    }
    if(ftell(fbook)==0){
        fprintf(fbook,"%8s|%20s|%20s|%10s|%5s|%6s|%10s|%10s|%10s\n","Id","Name","Author","Catagory","Sem","total","Borrowed","Available","Status");

    }
    if(ftell(counter)==0){
         fprintf(counter,"%10s|%10s\n%10d%10d","User Count","Book Count",0,0);
    }
    else{
        fseek(counter, -20,SEEK_END );
        
    fscanf(counter,"%10d%10d",userNum,bookNum);
    }


    printf("Loading successfull\nTotal User:%d\nTotal Books:%d\n",*userNum,*bookNum);
    //
    fclose(fmem);
    fclose(fbook);
    fclose(counter);

}

//fprint(fmem,"%10d|%30s|%5s|%5d|%5d|%5d|%10s",)
//71
//109