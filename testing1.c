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
    float depositAmount; // Will receive the deposit amount from user
    printf("Enter the deposit amount: ");
    scanf("%f", &depositAmount); // Get the deposit amount from user
    transaction[position] = depositAmount; // Store the deposit amount in the array at the current postion
    printf("Deposit received!");

}

void sumDeposit(float transaction[], int position)
{
    float total = 0.0; // Initialize total

    for(int i = 0; i < position; i++){ // Loop through the array up to the current position while adding each deposit to total
        total += transaction[i];
    }
    printf("Total:%.2f\n", total);
    
}

void showDepositOrdered(float transaction[], int position)
{
    for(int i = 0; i < position - 1; i ++){ // Bubble sort algorithm to sort in descending order
        for(int j = i + 1; j < position; j++){
            if (transaction[i] < transaction[j]){
                float temp = transaction[i];
                transaction[i] = transaction[j];
                transaction[j] = temp;
            }
        }

    }

    for(int i = 0; i < position; i++){ // Print the deposits in descending order
        printf("Deposits from highest to lowest: %.2f\n", transaction[i]);
    }
}

void averageDeposit(float transaction[], int position)
{
    float average = 0.0;
    for(int i = 0; i < position; i++){ // Loop through the array up to the current position while adding each deposit to average
        average += transaction[i];
    }
    average = average / position; // Calculate the average by dividing the total sum by the number of deposits;
    printf("Average: %.2f\n", average);
}

void lowestDeposit(float transaction[], int position)
{
    for(int i = 0; i < position - 1; i ++){ // Same bubble sort algorithm to sort in descending order
        for(int j = i + 1; j < position; j++){
            if (transaction[i] < transaction[j]){
                float temp = transaction[i];
                transaction[i] = transaction[j];
                transaction[j] = temp;
            }
        }

    }
    printf("Lowest deposit: %.2f\n", transaction[position - 1]); // Print the last element in the array which correspondeds to the lowest deposit

}
