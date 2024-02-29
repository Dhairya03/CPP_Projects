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

    bool adminLogin(int id, int pwd);

    int withdrawMoney(Bank &b);

    int depositMoney(Bank &b);

    int getMiniBankStatement(Bank &b);

    int getBankStatement(Bank &b);

    int showBalance(Bank &b);
};

#endif