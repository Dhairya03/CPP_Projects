#ifndef BANK_H
#define BANK_H

#include <vector>
// #include "IBank.h"
#include "account.h"
#include "transaction.h"

class Bank
{
public:
    std::vector<Account> accountHolderData;
    std::vector<Transaction> transactionDetails;

};

#endif