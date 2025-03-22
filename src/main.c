#include <stdio.h>
#include <stdlib.h>
#include "account.h"

#define MAX_ACCOUNTS 100

int main(void) {
    tAccount accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    do {
        printf("\n==== Simple Bank System ===== \n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display all accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                displayAccounts(accounts, numAccounts);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again\n");
        }

    } while(choice != 5);
    
    return 0;
}