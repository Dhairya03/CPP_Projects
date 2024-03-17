#ifndef IACCOUNT_HOLDER_H
#define IACCOUNT_HOLDER_H

#include <iostream>
#include "bankUser.h"
#include "bank.h"

class IAccountHolder : public BankUser
{
public:
    virtual int withdrawMoney(Bank &bankData)=0;

    virtual int depositMoney(Bank &bankData)=0;

    virtual bool findStatement(Bank &bankData, Transaction &transaction, int accountNumber)=0;

    virtual int getMiniBankStatement(Bank &bankData)=0;

    virtual int getBankStatement(Bank &bankData)=0;

    virtual int showBalance(Bank &bankData)=0;

    virtual bool logout()=0;
};

#endif