#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "file_io.h"

void createAccount(tAccount accounts[], int *numAccounts) {
    int newAccountNumber;
    printf("Enter an account number: ");
    if (scanf("%d", &newAccountNumber) != 1) {
        printf("Invalid input.\n");
        return;
    }

    for (int i = 0; i < *numAccounts; i++) {
        if (accounts[i].accountNumber == newAccountNumber) {
            printf("An account with this number already exists.\n");
            return;
        }
    }

    accounts[*numAccounts].accountNumber = newAccountNumber;
    printf("Enter account holder name: ");
    scanf(" %[^\n]", accounts[*numAccounts].name);
    accounts[*numAccounts].balance = 0.0;
    (*numAccounts)++;

    saveAllAccounts(accounts, *numAccounts);
    printf("Account created successfully.\n");
}

void deposit(tAccount accounts[], int numAccounts) {
    int accNum;
    double amount;
    printf("Enter account number to deposit into: ");
    if (scanf("%d", &accNum) != 1) {
        printf("Invalid input.\n");
        return;
    }
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            if (scanf("%lf", &amount) != 1 || amount < 0) {
                printf("Invalid amount.\n");
                return;
            }
            accounts[i].balance += amount;
            saveAllAccounts(accounts, numAccounts);
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(tAccount accounts[], int numAccounts) {
    int accNum;
    double amount;
    printf("Enter account number to withdraw from: ");
    if (scanf("%d", &accNum) != 1) {
        printf("Invalid input.\n");
        return;
    }
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            if (scanf("%lf", &amount) != 1 || amount < 0) {
                printf("Invalid amount.\n");
                return;
            }
            if (amount > accounts[i].balance) {
                printf("Insufficient funds.\n");
            } else {
                accounts[i].balance -= amount;
                saveAllAccounts(accounts, numAccounts);
                printf("Withdraw successful. New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccounts(const tAccount accounts[], int numAccounts) {
    printf("\n--------- List of Accounts ------------\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("-------------------\n");
    }
}
