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

    int withdrawMoney(Bank &b);

    int depositMoney(Bank &b);

    int getMiniBankStatement(Bank &b);

    int getBankStatement(Bank &b);

    int showBalance(Bank &b);
};

#endif