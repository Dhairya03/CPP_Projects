#ifndef ACCHOLDER_H
#define ACCHOLDER_H

#include <iostream>
#include "bankUser.h"
#include "bank.h"

class AccountHolder : public BankUser
{
public:
    void showOperationChoices();

    void performOperation(int operationChoice, Bank &bankData);

    bool logout();
};

#endif