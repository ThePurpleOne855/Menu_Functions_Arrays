#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


void newDeposit(float transaction[], int position);
void sumDeposit(float transaction[], int position);
void showDepositOrdered(float transaction[], int position);
void averageDeposit(float transaction[], int position);
void lowestDeposit(float transaction[], int position);

int main(){
    int position = 0;
    float bankTransactions[MAX_SIZE];
    float depositAmount;
    int on = 1;
    char choice;

    while(on == 1){
        int size = sizeof(bankTransactions) / sizeof(bankTransactions[0]); // Calculate or recalculate the size of the bankTransacitons array


        printf("*** BANKING MAIN MENU ***\n\n");
        printf("[G]et a new deposit\n");
        printf("[S]Sum of all deposits\n");
        printf("[D]eposits will be displayed from highest to lowest deposit\n");
        printf("[A]verage of all deposits\n");
        printf("[L]owest deposit will be displayed\n");
        printf("[Q]uit the program\n");
        
        scanf("%c", &choice);

        switch(choice){
            case 'G':
            case 'g':
                newDeposit(bankTransactions, position);
                position++;
                break;
            case 'S':
            case 's':
                sumDeposit(bankTransactions, position);
                break;

            case 'D':
            case 'd':
                showDepositOrdered(bankTransactions, position);
                break;
            case 'A':
            case 'a':
                averageDeposit(bankTransactions, position);
                break;
            case 'L':
            case 'l':
                lowestDeposit(bankTransactions, position);
                break;

            case 'Q':
            case 'q':
                on = 0;
                printf("Exiting the program...\n");
                break;
        }
    }
}

void newDeposit(float transaction[], int position)
{
    float depositAmount;
    printf("Enter the deposit amount: ");
    scanf("%f", &depositAmount);
    transaction[position] = depositAmount;
    printf("Deposit received!");

}

void sumDeposit(float transaction[], int position)
{
    float total = 0.0;

    for(int i = 0; i < position; i++){
        total += transaction[i];
    }
    printf("Total:%.2f\n", total);
    
}

void showDepositOrdered(float transaction[], int position)
{
    for(int i = 0; i < position - 1; i ++){
        for(int j = i + 1; j < position; j++){
            if (transaction[i] < transaction[j]){
                float temp = transaction[i];
                transaction[i] = transaction[j];
                transaction[j] = temp;
            }
        }

    }

    for(int i = 0; i < position; i++){
        printf("Deposits from highest to lowest: %.2f\n", transaction[i]);
    }
}

void averageDeposit(float transaction[], int position)
{
    float average = 0.0;
    for(int i = 0; i < position; i++){
        average += transaction[i];
    }
    average = average / position;
    printf("Average: %.2f\n", average);
}

void lowestDeposit(float transaction[], int position)
{
    for(int i = 0; i < position - 1; i ++){
        for(int j = i + 1; j < position; j++){
            if (transaction[i] < transaction[j]){
                float temp = transaction[i];
                transaction[i] = transaction[j];
                transaction[j] = temp;
            }
        }

    }
    printf("Lowest deposit: %.2f\n", transaction[position - 1]);

}
