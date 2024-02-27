#ifndef BANK_H
#define BANK_H

#include <vector>
#include "accountHolder.h"
#include "transaction.h"

class Bank
{
protected:
    std::vector<AccountHolder> accountHolderData;
    std::vector<Transaction> transactionDetails;
    // Admin adminData;

public:
    int withdrawMoney();

    int depositMoney();

    int getMiniBankStatement();

    int getBankStatement();

    int showBalance();
};

#endif