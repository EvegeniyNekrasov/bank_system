#ifndef ACCOUNT_H

#define ACCOUNT_H
#define MAX_NAME 50

typedef struct {
    int accountNumber;
    char name[MAX_NAME];
    double balance;
} tAccount;

void createAccount(tAccount accounts[], int *numAccounts);
void deposit(tAccount accounts[], int numAccounts);
void withdraw(tAccount accounts[], int numAccounts);
void displayAccounts(const tAccount accounts[], int numAccounts);

#endif