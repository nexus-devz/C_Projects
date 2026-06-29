#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char date[20];
    int earned, spent, food;
    int prevLeft = 0, wallet;

    // Open file in append+read mode
    fp = fopen("records.txt", "a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Check if file has previous data
    int lastLeft = 0;
    {
        FILE *readfp = fopen("records.txt", "r");
        if (readfp != NULL) {  /* NULL check */
            char line[200];
            while (fgets(line, sizeof(line), readfp)) {
                /* skip header */
                if (strncmp(line, "Date", 4) == 0) continue;

                /* split by tabs or spaces (robust for existing files) */
                char *cols[8];
                int i = 0;
                char *tok = strtok(line, "\t ");
                while (tok != NULL && i < 8) {
                    cols[i++] = tok;
                    tok = strtok(NULL, "\t ");
                }

                /* expect at least 7 columns; Wallet is column index 6 */
                if (i >= 7) {
                    lastLeft = atoi(cols[6]);
                }
            }
            fclose(readfp);
        }
    }

    // Take user input
    printf("Enter date: ");
    scanf("%19s", date);  /* limit input */
    printf("Enter earned: ");
    scanf("%d", &earned);
    printf("Enter spent: ");
    scanf("%d", &spent);
    printf("Enter food: ");
    scanf("%d", &food);

    
    // If file is empty, write header first
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0) {
        fprintf(fp, "%-10s %8s %8s %8s %10s %10s %8s\n",
            "Date", "Earned", "Travel", "Food", "Saved/Lost", "Expected", "Wallet");
            printf("Enter Initial Wallet ammount: ");
            scanf("%d", &lastLeft);
        }
        
        // Calculate
        wallet = (lastLeft + earned) - (spent + food);
        int saved, expected;
        saved = earned + 70 - (spent + food);
        expected = lastLeft + earned - 70;

    // Append new record with fixed-width fields so columns align visually
    fprintf(fp, "%-10s %8d %8d %8d %10d %10d %8d\n",
            date, earned, spent, food, saved, expected, wallet);

    fclose(fp);

    printf("Record added successfully! Money Left = %d\n", wallet);

    return 0;
}