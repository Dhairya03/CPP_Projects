#ifndef BANK_H
#define BANK_H

#include <vector>
#include "account.h"
#include "transaction.h"

class Bank
{
protected:
    std::vector<Account> accountHolderData;
    std::vector<Transaction> transactionDetails;

public:
    bool adminLogin(int id, int pwd);

    int withdrawMoney();

    int depositMoney();

    int getMiniBankStatement();

    int getBankStatement();

    int showBalance();
};

#endif