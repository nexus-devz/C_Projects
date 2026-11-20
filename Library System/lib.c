// combine functions
#include <stdio.h>
#include "lib.h"
#include <stdlib.h>

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
     loadFile();
     dynamicArrayLoad();
     loadUserArray();
     loadBooksArray();

}

//fprint(fmem,"%10d|%30s|%5s|%5d|%5d|%5d|%10s",)
//71
//109

void loadFile(){
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

void dynamicArrayLoad(){
    users = malloc((userCount+100) * sizeof(struct User));
    books = malloc((bookCount+100) * sizeof(struct User));
    fmem=fopen(FIle_Mem,"r");
    fbook=fopen(File_Book,"r");
    for(int i=0; i<userCount; i++){
        
    }
}

void loadUserArray(){
    fmem = fopen("user.txt", "r");
    if (fmem == NULL) {
        perror("user.txt");
        loadUserArray();
    }
    char line[256];
     fgets(line, sizeof line, fmem);  // Skip the header
    
    for (int i = 0; i < userCount && fgets(line, sizeof line, fmem) != NULL; i++) {
        int fields = sscanf(line,
            " %8d|%20[^|]|%5[^|]|%5d|%10d|%5d|%10[^\r\n]",
            &users[i].id, users[i].name, users[i].dept,
            &users[i].sem, &users[i].booksKept, &users[i].due,
            users[i].status);

        if (fields != 7) {
            printf("Parsed %d fields; line=[%s]\n", fields, line);
            continue;
        }
    }

    fclose(fmem);
}

void loadBooksArray(){
    fbook = fopen("books.txt", "r");
    if (fbook == NULL) {
        perror("user.txt");
        loadBooksArray();
    }
    char line[256];
     fgets(line, sizeof line, fbook);  // Skip the header
    
    for (int i = 0; i < bookCount && fgets(line, sizeof line, fbook) != NULL; i++) {
        int fields = sscanf(line,
            " %8d| %30[^|]| %30[^|]| %10[^|]| %5d| %6d| %10d| %10d|%10[^\r\n]",
            &books[i].id, books[i].name, books[i].author, books[i].catg,
            &books[i].sem, &books[i].total, &books[i].booklent,
            &books[i].available, books[i].status);

        if (fields != 9) {
            printf("Parsed %d fields; line=[%s]\n", fields, line);
            continue;
        }
    }

    fclose(fbook);

}