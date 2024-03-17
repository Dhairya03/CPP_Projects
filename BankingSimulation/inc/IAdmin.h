#ifndef IADMIN_H
#define IADMIN_H

#include <iostream>
#include "bankUser.h"
#include "bank.h"

class IAdmin : public BankUser
{
public:
    virtual bool login()=0;

    virtual int createAccount(Bank &bankData)=0;

    virtual int withdrawMoney(Bank &bankData)=0;

    virtual int depositMoney(Bank &bankData)=0;

    virtual bool findStatement(Bank &bankData, Transaction &transaction, int accountNumber)=0;

    virtual int getMiniBankStatement(Bank &bankData)=0;

    virtual int getBankStatement(Bank &bankData)=0;

    virtual int showBalance(Bank &bankData)=0;

    virtual void showUserList(Bank &bankData)=0;

    virtual void showParticularUser(Bank &bankData)=0;

    virtual int closeAccount(Bank &bankData)=0;

    virtual bool logout()=0;
};

#endif