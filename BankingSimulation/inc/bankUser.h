#ifndef BANKUSER_H
#define BANKUSER_H

#include <vector>
#include "bank.h"

class BankUser
{
public:

    int withdrawMoney(Bank &bankData);

    int depositMoney(Bank &bankData);

    bool findStatement(Bank &bankData, Transaction &transaction, int accountNumber);

    int getMiniBankStatement(Bank &bankData);

    int getBankStatement(Bank &bankData);

    int showBalance(Bank &bankData);
};

#endif