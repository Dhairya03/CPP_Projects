#ifndef ACCHOLDER_H
#define ACCHOLDER_H

#include <iostream>

#include "bank.h"

class AccountHolder : public Bank
{
public:
    void showOperationChoices();

    void performOperation(int operationChoice, Bank &b);

    bool logout();
};

#endif