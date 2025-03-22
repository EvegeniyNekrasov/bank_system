#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "file_io.h"

#define LINE_SIZE 1024

int loadAccounts(tAccount accounts[], int maxAccounts) {
    FILE *fp = fopen("accounts.csv", "r");
    if (fp == NULL) {
        return 0;
    }

    char line[LINE_SIZE];
    int count = 0;

    if (fgets(line, LINE_SIZE, fp) == NULL) {
        fclose(fp);
        return 0;
    }

    while (fgets(line, LINE_SIZE, fp) != NULL && count < maxAccounts) {
        char *token = strtok(line, ",");
        if (token == NULL) continue;
        accounts[count].accountNumber = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;

        token[strcspn(token, "\"\n")] = '\0';
        strncpy(accounts[count].name, token, sizeof(accounts[count].name));
        accounts[count].name[sizeof(accounts[count].name)-1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        accounts[count].balance = atof(token);

        count++;
    }
    fclose(fp);
    return count;
}

void saveAllAccounts(const tAccount accounts[], int numAccounts) {
    FILE *fp = fopen("accounts.csv", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(fp, "AccountNumber,Name,Balance\n");
    for (int i = 0; i < numAccounts; i++) {
        fprintf(fp, "%d,\"%s\",%.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    fclose(fp);
}
