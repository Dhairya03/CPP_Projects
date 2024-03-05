#ifndef BANK_H
#define BANK_H

#include <vector>
#include "account.h"
#include "transaction.h"

class Bank
{
public:
    std::vector<Account> accountHolderData;
    std::vector<Transaction> transactionDetails;
};

#endif