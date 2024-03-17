#ifndef ACCHOLDER_H
#define ACCHOLDER_H

#include <iostream>
#include "bankUser.h"
#include "Accounts.h"

class AccountHolder : public BankUser
{
    Accounts *bankData;
public:
    bool isLoggedIn{false};

    AccountHolder(Accounts *bank):bankData(bank){}

    bool login();

    void showOperationChoices();

    void performOperation(int operationChoice);

    int withdrawMoney();

    int depositMoney();

    bool findStatement( Transaction &transaction, int accountNumber);

    int getMiniBankStatement();

    int getBankStatement();

    int showBalance();

    bool logout();

    // ~AccountHolder(){}
};

#endif