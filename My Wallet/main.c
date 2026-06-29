//just for personal use

#include<stdio.h>

int main(){
    int date, earned, spent, food;
    char cat[20];

    FILE *fptr;

    fptr = fopen("mywallet.txt", "a+");
    fseek(fptr, 0, SEEK_END);
    if(ftell(fptr)==0){
        fprintf(fptr, "Date/tEarned/tTravel/tFood/tLeft\n");
    }
    printf("Enter date (format DDMM): ");
    scanf("%d", &date);
    printf("Todays Earning: ");
    scanf("%d", &earned);
    printf("Travel Cost: ");
    scanf("%d", &spent);
    printf("Food: ");
    scanf("%d", &food);
    //Left calculation
    int lastLeft =0;
    

    return 0;
}