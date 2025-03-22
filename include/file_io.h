#ifndef FILE_IO_H
#define FILE_IO_H

#include "account.h"

int loadAccounts(tAccount accounts[], int maxAccounts);
void saveAllAccounts(const tAccount accounts[], int numAccounts);

#endif
