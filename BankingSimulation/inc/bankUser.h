#ifndef BANKUSER_H
#define BANKUSER_H

#include <vector>
#include "Accounts.h"

class BankUser
{
public:
    BankUser() {}
    // virtual ~BankUser(){}

    virtual bool login()=0;

    virtual int withdrawMoney() = 0;

    virtual int depositMoney() = 0;

    virtual bool findStatement(Transaction &transaction, int accountNumber) = 0;

    virtual int getMiniBankStatement() = 0;

    virtual int getBankStatement() = 0;

    virtual int showBalance() = 0;

    virtual bool logout() = 0;
};

#endif